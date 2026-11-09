
===== PptpCoRequest @ 1c0001010 =====

int PptpCoRequest(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int unaff_EBX;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  if ((param_2 != 0) && (*(int *)(param_2 + 0x30) != 0x43505450)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EBX;
    }
    if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) {
      return unaff_EBX;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return unaff_EBX;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
    return unaff_EBX;
  }
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar2 = PptpMpSetInformation
                        (param_3 + 0x34,param_2,*(int *)(param_3 + 0x20),
                         *(undefined4 **)(param_3 + 0x28),*(uint *)(param_3 + 0x30),
                         (undefined4 *)(param_3 + 0x34),(undefined4 *)(param_3 + 0x38));
      goto LAB_1c000108b;
    }
    if (iVar1 != 2) {
      iVar2 = -0x3fffff45;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return unaff_EBX;
      }
      if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                 &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar1);
      }
      goto LAB_1c000108b;
    }
  }
  uVar3 = PptpMpQueryInformation
                    (param_1,param_2,*(uint *)(param_3 + 0x20),*(void **)(param_3 + 0x28),
                     *(uint *)(param_3 + 0x30),(uint *)(param_3 + 0x34),(uint *)(param_3 + 0x38));
  iVar2 = (int)uVar3;
LAB_1c000108b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
             &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar2);
  }
  return unaff_EBX;
}



===== PptpMpQueryInformation @ 1c00011e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PptpMpQueryInformation
          (longlong param_1,longlong param_2,uint param_3,void *param_4,uint param_5,uint *param_6,
          uint *param_7)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  int *_Src;
  undefined1 auStack_138 [32];
  int local_118 [2];
  longlong local_110;
  longlong local_108;
  int local_f8 [4];
  ulonglong local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_138;
  _Src = local_118;
  local_68 = 0;
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  uVar2 = 4;
  local_118[0] = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  uVar3 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_110 = param_2;
  local_108 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  if (param_3 == 0x20106) {
    local_e8 = (ulonglong)DAT_1c000c404;
    _Src = local_f8;
    uVar2 = 0x98;
    uStack_a0 = (ulonglong)(uint)(DAT_1c000c3fc + _DAT_1c000c3f8);
    local_f8[0] = 0x980180;
    local_f8[1] = 0x420;
  }
  else if (param_3 == 0x4010182) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
    }
    if (local_110 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0010015;
      }
      if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) {
        return 0xc0010015;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return 0xc0010015;
      }
      uVar1 = 0x1f;
LAB_1c0001848:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
              &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
      return 0xc0010015;
    }
    _Src = (int *)(local_110 + 0xf0);
    uVar2 = 0x20;
  }
  else {
    if (0x4010280 < param_3) {
      if (param_3 == 0x4010282) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
        if (local_110 == 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc0010015;
          }
          if (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) {
            return 0xc0010015;
          }
          if (WPP_GLOBAL_Control[0x29] == '\0') {
            return 0xc0010015;
          }
          uVar1 = 0x22;
          goto LAB_1c0001848;
        }
        *(undefined4 *)((longlong)param_4 + 0x38) = *(undefined4 *)(local_110 + 0x268);
        *(undefined4 *)((longlong)param_4 + 0x3c) = *(undefined4 *)(local_110 + 0xb8);
        *(undefined4 *)((longlong)param_4 + 0x40) = *(undefined4 *)(local_110 + 0x26c);
        *(undefined4 *)((longlong)param_4 + 0x44) = *(undefined4 *)(local_110 + 0x270);
        *(undefined4 *)((longlong)param_4 + 0x48) = *(undefined4 *)(local_110 + 0x294);
        *(undefined4 *)((longlong)param_4 + 0x4c) = *(undefined4 *)(local_110 + 0x298);
        *(undefined4 *)((longlong)param_4 + 0x50) = *(undefined4 *)(local_110 + 0xbc);
        *(undefined4 *)((longlong)param_4 + 0x54) = *(undefined4 *)(local_110 + 0x29c);
        *(undefined4 *)((longlong)param_4 + 0x58) = *(undefined4 *)(local_110 + 0x2a0);
        *(undefined4 *)((longlong)param_4 + 0x5c) = *(undefined4 *)(local_110 + 0x2a4);
        *(undefined4 *)((longlong)param_4 + 0x60) = *(undefined4 *)(local_110 + 0x2a8);
        *(undefined4 *)((longlong)param_4 + 100) = *(undefined4 *)(local_110 + 0x2ac);
      }
      else {
        if (param_3 == 0xfd010100) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                    &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
          }
          _Src = (int *)&PnpCaps;
          uVar2 = 0x10;
          goto LAB_1c00012b9;
        }
        if (param_3 == 0xfd010101) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar1 = 0x24;
LAB_1c000166c:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
                    &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
          }
        }
        else if (param_3 == 0xfd010102) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar1 = 0x25;
            goto LAB_1c000166c;
          }
        }
        else {
          if (param_3 != 0xfd010106) goto LAB_1c0001622;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar1 = 0x26;
            goto LAB_1c000166c;
          }
        }
      }
      uVar2 = 0;
      goto LAB_1c00012d4;
    }
    if (param_3 == 0x4010280) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
      }
LAB_1c00015b2:
      uVar3 = 0xc00000bb;
      uVar2 = 0;
      goto LAB_1c00012d4;
    }
    if (param_3 < 0x20103) {
      if (param_3 == 0x20102) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
        local_118[0] = DAT_1c000c430;
      }
      else if (param_3 == 0x1010c) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
        local_118[0] = -1;
        uVar2 = 3;
      }
      else if (param_3 == 0x10111) {
        local_118[0] = 0x5c8;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
      }
      else {
        if (param_3 != 0x20101) goto LAB_1c0001622;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
        local_118[0] = DAT_1c000c3f0 - _DAT_1c000c3f8;
      }
    }
    else if (param_3 == 0x4010105) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
      }
      local_118[0] = 8;
    }
    else {
      if (param_3 != 0x4010180) {
LAB_1c0001622:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                   &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,param_3);
          uVar2 = 0;
          uVar3 = 0xc00000bb;
          goto LAB_1c00012d4;
        }
        goto LAB_1c00015b2;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
      }
      uVar2 = 0x10;
      _Src = (int *)(local_108 + 0x4c);
    }
  }
LAB_1c00012b9:
  if (param_5 < uVar2) {
    *param_7 = uVar2;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,param_5);
    }
    return 0xc0010014;
  }
  memcpy(param_4,_Src,(ulonglong)uVar2);
LAB_1c00012d4:
  *param_6 = uVar2;
  *param_7 = uVar2;
  return uVar3;
}



===== PptpMpSetInformation @ 1c00018b0 =====

int PptpMpSetInformation
              (undefined8 param_1,longlong param_2,int param_3,undefined4 *param_4,uint param_5,
              undefined4 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == -0x2fefefa) {
LAB_1c0001a28:
    iVar2 = 0;
  }
  else {
    if (param_3 == 0x4010181) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
      }
      if (param_5 < 0x20) {
        iVar2 = -0x3ffeffec;
        uVar1 = 0;
      }
      else {
        if ((param_2 == 0) || (*(int *)(param_2 + 0x30) != 0x43505450)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0' &&
              (WPP_GLOBAL_Control[0x29] != '\0')))) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                    &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
          }
          return -0x3ffeffeb;
        }
        iVar2 = CallSetLinkInfo(param_2,param_4);
        uVar1 = 0x20;
      }
      *param_6 = uVar1;
      *param_7 = 0x20;
      return iVar2;
    }
    if (param_3 == 0x4010281) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        iVar2 = -0x3fffff45;
        goto LAB_1c0001a2c;
      }
    }
    else {
      if (param_3 == -0x2fefeff) goto LAB_1c0001a28;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                 &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,param_3);
      }
    }
    iVar2 = -0x3fffff45;
  }
LAB_1c0001a2c:
  *param_7 = 0;
  *param_6 = 0;
  return iVar2;
}



===== DereferenceRefCount @ 1c0001a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DereferenceRefCount(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(param_1 + 2))();
  }
  return;
}



===== PptpCmOidRequest @ 1c0001a90 =====

ulonglong PptpCmOidRequest(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  int iVar1;
  ulonglong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  if ((param_2 != 0) && (*(int *)(param_2 + 0x30) != 0x43505450)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    return 0xc0010015;
  }
  iVar1 = *(int *)(param_4 + 4);
  if (iVar1 == 0) {
    uVar2 = PptpQueryCmInformation
                      (param_4 + 0x34,param_2,*(int *)(param_4 + 0x20),
                       *(undefined4 **)(param_4 + 0x28),*(uint *)(param_4 + 0x30),
                       (uint *)(param_4 + 0x34),(uint *)(param_4 + 0x38));
    uVar2 = uVar2 & 0xffffffff;
  }
  else if (iVar1 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,*(undefined4 *)(param_4 + 0x20));
    }
    uVar2 = 0xc00000bb;
  }
  else {
    uVar2 = 0xc00000bb;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar1);
    }
  }
  return uVar2;
}



===== PptpQueryCmInformation @ 1c0001c00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
PptpQueryCmInformation
          (undefined8 param_1,longlong param_2,int param_3,undefined4 *param_4,uint param_5,
          uint *param_6,uint *param_7)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined8 *_Src;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_348 [32];
  undefined4 local_328 [2];
  longlong local_320;
  undefined4 local_318;
  undefined4 uStack_314;
  undefined4 local_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined4 local_2e8 [2];
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2c4;
  int local_2c0;
  int local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_26c;
  undefined4 local_1d4;
  undefined2 local_1bc [66];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_d8;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_348;
  local_318 = 0;
  uStack_314 = 0;
  local_310 = 0;
  local_320 = param_2;
  memset(local_2e8,0,0x1b0);
  memset(&local_138,0,0xf0);
  _Src = (undefined8 *)local_328;
  uVar7 = 0;
  local_2f8 = 0;
  local_328[0] = 0;
  uVar4 = 0;
  local_308 = 0;
  uStack_300 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_3);
  }
  if (param_3 == -0x1ffefff) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uStack_314 = 1;
    local_310 = 0;
    _Src = (undefined8 *)&local_318;
    local_318 = 0x30000;
    uVar7 = 0xc;
LAB_1c0001cf3:
    if (param_5 < uVar7) {
      uVar4 = 0xc0010014;
      goto LAB_1c0001d1a;
    }
    if (uVar7 != 0) {
LAB_1c0001d05:
      memcpy(param_4,_Src,(ulonglong)uVar7);
    }
  }
  else if (param_3 == -0x1ffeffe) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    if (0x1af < param_5) {
      local_2e0 = param_4[2];
      local_2e8[0] = *param_4;
      psVar3 = (short *)&u_PPTP;
      local_2dc = 0x1a8;
      local_2d8 = 0x1a8;
      iVar1 = 0;
      do {
        iVar6 = iVar1;
        psVar3 = psVar3 + 1;
        iVar1 = iVar6 + 1;
      } while (*psVar3 != 0);
      uVar7 = iVar6 + 2;
      uVar8 = (ulonglong)uVar7;
      if (0x40 < uVar7) {
        uVar8 = 0x40;
      }
      local_2c4 = local_2e8[0];
      memcpy(local_1bc,&u_PPTP,uVar8 * 2);
      local_1bc[uVar8] = 0;
      local_2c0 = (int)uVar8 * 2;
      local_2b8 = 3;
      local_2bc = (int)local_1bc - (int)&local_2e0;
      local_2b0 = 1;
      _Src = (undefined8 *)local_2e8;
      local_2ac = 8;
      uVar7 = 0x1b0;
      local_2a8 = 10000000;
      local_2a4 = 0x102;
      local_26c = 1;
      local_1d4 = 0x10;
      goto LAB_1c0001d05;
    }
    uVar4 = 0xc0010015;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar5 = 0x6b;
LAB_1c0001f66:
      uVar4 = 0xc0010015;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
  }
  else {
    if (param_3 != -0x1ffeffd) {
      if (param_3 == -0x1ffeff9) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                  &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
        }
        if (local_320 == 0) {
          uVar4 = 0xc0010015;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar5 = 0x6f;
            goto LAB_1c0001f66;
          }
          goto LAB_1c0001d13;
        }
        _Src = &local_308;
        uVar2 = 1;
        if (*(char *)(local_320 + 0xc0) != '\0') {
          uVar2 = 4;
        }
        local_308 = CONCAT44(1,uVar2);
        uVar7 = 0x18;
        uStack_300 = 0;
        local_2f8 = 0;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
                   &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_3);
        }
        uVar4 = 0xc00000bb;
      }
      goto LAB_1c0001cf3;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    if (0xef < param_5) {
      local_138 = *param_4;
      _Src = (undefined8 *)&local_138;
      local_134 = param_4[1];
      uVar7 = 0xf0;
      local_12c = 0xe4;
      local_128 = 0xe4;
      local_124 = 0xe4;
      local_d8 = 0x4000;
      local_120 = local_138;
      goto LAB_1c0001d05;
    }
    uVar4 = 0xc0010015;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar5 = 0x6d;
      goto LAB_1c0001f66;
    }
  }
LAB_1c0001d13:
  *param_6 = uVar7;
LAB_1c0001d1a:
  *param_7 = uVar7;
  return uVar4;
}



===== CompareSockAddress @ 1c00020e0 =====

ulonglong CompareSockAddress(short *param_1,short *param_2)

{
  short sVar1;
  longlong lVar2;
  ulonglong uVar3;
  bool bVar4;
  
  sVar1 = *param_1;
  if (sVar1 == *param_2) {
    if (sVar1 == 2) {
      lVar2 = RtlCompareMemory(param_1 + 2,param_2 + 2,4);
      bVar4 = lVar2 == 4;
    }
    else {
      lVar2 = RtlCompareMemory(param_1 + 4,param_2 + 4,0x10);
      bVar4 = lVar2 == 0x10;
    }
    uVar3 = (ulonglong)bVar4;
  }
  else {
    uVar3 = (ulonglong)(byte)((ushort)sVar1 >> 8) << 8;
  }
  return uVar3;
}



===== MiniportCheckAdapterState @ 1c0002160 =====

undefined8 MiniportCheckAdapterState(longlong param_1)

{
  if (*(int *)(param_1 + 0xd0) == 1) {
    return 0xc023002a;
  }
  if (*(int *)(param_1 + 0xd0) == 2) {
    return 0;
  }
  return 0xc0000001;
}



===== PptpCmCloseAf @ 1c0002190 =====

undefined8 PptpCmCloseAf(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0xa0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar2 + -1);
  }
  if (iVar2 + -1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    NdisCmCloseAddressFamilyComplete(0,*(undefined8 *)(param_1 + 0x98));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    LOCK();
    *(undefined8 *)(param_1 + 0x98) = 0;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(param_1 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      NdisSetEvent(param_1 + 0xa8);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  return 0x103;
}



===== DereferenceAf @ 1c0002360 =====

void DereferenceAf(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xa0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar2 + -1);
  }
  if (iVar2 + -1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    NdisCmCloseAddressFamilyComplete(0,*(undefined8 *)(param_1 + 0x98));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    LOCK();
    *(undefined8 *)(param_1 + 0x98) = 0;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(param_1 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      NdisSetEvent(param_1 + 0xa8);
    }
  }
  return;
}



===== MiniportRestart @ 1c00024a0 =====

undefined8 MiniportRestart(longlong param_1)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  *(code **)(param_1 + 200) = DoDerefMiniportAdapterBlockWork;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  LOCK();
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
  UNLOCK();
  *(undefined4 *)(param_1 + 0xd0) = 2;
  KeReleaseSpinLock(param_1 + 8,*(undefined1 *)(param_1 + 0x10));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  return 0;
}



===== PptpCmOpenAf @ 1c0002590 =====

undefined8 PptpCmOpenAf(longlong param_1,int *param_2,longlong param_3,longlong *param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  bool bVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  if (((*param_2 == 0x801) && (param_2[1] == 6)) && (param_2[2] == 0x1e)) {
    LOCK();
    bVar4 = *(longlong *)(param_1 + 0x98) == 0;
    if (bVar4) {
      *(longlong *)(param_1 + 0x98) = param_3;
    }
    UNLOCK();
    if (bVar4) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        NdisResetEvent(param_1 + 0xa8);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xa0);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar2 + 1);
      }
      *param_4 = param_1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      uVar3 = 0;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      uVar3 = 0xc0000001;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uVar3 = 0xc0010004;
  }
  return uVar3;
}



===== StrLenW @ 1c0002730 =====

int StrLenW(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != (short *)0x0) {
    sVar1 = *param_1;
    while (sVar1 != 0) {
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      sVar1 = *param_1;
    }
  }
  return iVar2;
}



===== DoDerefMiniportAdapterBlockWork @ 1c0002760 =====

void DoDerefMiniportAdapterBlockWork(longlong param_1)

{
  undefined1 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + -0xb8);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined1 *)(param_1 + -0xb0) = uVar1;
  KeReleaseSpinLock(param_1 + -0xb8,uVar1);
  NdisMPauseComplete(*(undefined8 *)(param_1 + -0xc0));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  return;
}



===== MiniportPause @ 1c0002840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MiniportPause(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined4 *)(param_1 + 0xd0) = 3;
  *(undefined1 *)(param_1 + 0x10) = uVar3;
  KeReleaseSpinLock(param_1 + 8,uVar3);
  piVar1 = (int *)(param_1 + 0xc0);
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 200))();
  }
  return 0x103;
}



===== ReferenceAf @ 1c00028c0 =====

void ReferenceAf(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xa0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar2 + 1);
  }
  return;
}



===== ReferenceAdapter @ 1c0002920 =====

void ReferenceAdapter(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    NdisResetEvent(param_1 + 0xa8);
  }
  return;
}



===== ScheduleWorkItem @ 1c0002960 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
ScheduleWorkItem(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = MyMemAlloc(0x30,0x49575450);
  if (lVar1 == 0) {
    _DAT_1c000c480 = _DAT_1c000c480 + 1;
    uVar2 = 0xc0000001;
  }
  else {
    *(undefined8 *)(lVar1 + 0x18) = param_2;
    *(undefined8 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x28) = param_4;
    *(undefined8 *)(lVar1 + 0x10) = param_1;
    ExInterlockedInsertTailList(&WorkItemList,lVar1,&GlobalThreadLock);
    KeSetEvent(&EventPassiveThread,0,0);
    uVar2 = 0;
  }
  return uVar2;
}



===== MyMemAlloc @ 1c0002a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong MyMemAlloc(undefined4 param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar2 = (ulonglong)param_2;
  local_10 = 0x10;
  local_18 = 1;
  lVar1 = ExAllocatePool3(0x40,param_1,uVar2,&local_18,1);
  if (lVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar2,param_1,(char)param_2);
    }
    _DAT_1c000c484 = _DAT_1c000c484 + 1;
    lVar1 = 0;
  }
  return lVar1;
}



===== DereferenceAdapter @ 1c0002ab0 =====

void DereferenceAdapter(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    NdisSetEvent(param_1 + 0xa8);
  }
  return;
}



===== InitCallLayer @ 1c0002af0 =====

void InitCallLayer(void)

{
  uint uVar1;
  
  if ((PptpClientSide != '\0') || (PptpBaseCallId != 0)) {
    PptpMaxCallId = PptpWanEndpoints + PptpBaseCallId;
    PptpCallIdMaskSet = 0;
    return;
  }
  uVar1 = 1;
  if (1 < PptpWanEndpoints) {
    do {
      uVar1 = uVar1 * 2;
    } while (uVar1 < PptpWanEndpoints);
  }
  PptpCallIdMaskSet = 1;
  PptpCallIdMask = uVar1 - 1;
  PptpMaxCallId = 0x10000;
  return;
}



===== _guard_check_icall @ 1c0002b60 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 1c0002b80 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CallAlloc @ 1c0002b90 =====

undefined4 * CallAlloc(undefined8 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined8 local_28;
  code *pcStack_20;
  undefined4 *local_18;
  
  local_18 = (undefined4 *)0x0;
  local_28 = 0;
  pcStack_20 = (code *)0x0;
  puVar2 = (undefined4 *)MyMemAlloc(0x2b8,0x43505450);
  if (puVar2 == (undefined4 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    }
    return (undefined4 *)0x0;
  }
  puVar2[0x6a] = 0;
  *(undefined2 *)((longlong)puVar2 + 0xc2) = 0;
  puVar2[0xc] = 0x43505450;
  *(undefined8 **)(puVar2 + 0xe) = param_1;
  *(undefined1 *)(puVar2 + 0x92) = 0;
  KeInitializeSpinLock(puVar2 + 0x18);
  KeInitializeSpinLock(puVar2 + 0x22);
  KeInitializeSpinLock(puVar2 + 0x2a);
  lVar3 = NdisAllocateNetBufferList(*(undefined8 *)(*(longlong *)(puVar2 + 0xe) + 0x80),0,0);
  *(longlong *)(puVar2 + 0x78) = lVar3;
  if (lVar3 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_1c0002e96;
    uVar4 = 0xb;
  }
  else {
    lVar3 = NdisAllocateIoWorkItem(*param_1);
    *(longlong *)(puVar2 + 0x96) = lVar3;
    if (lVar3 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_1c0002e96;
      uVar4 = 0xc;
    }
    else {
      lVar3 = NdisAllocateIoWorkItem(*param_1);
      *(longlong *)(puVar2 + 0x98) = lVar3;
      if (lVar3 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0')
           ) goto LAB_1c0002e96;
        uVar4 = 0xd;
      }
      else {
        *(undefined8 *)(puVar2 + 0x20) = 0;
        *(undefined8 *)(puVar2 + 0x1e) = 0;
        *(undefined8 *)(puVar2 + 0x28) = 0;
        *(undefined8 *)(puVar2 + 0x26) = 0;
        pcStack_20 = CallpCloseTimeout;
        local_28 = 0x544d545000180197;
        local_18 = puVar2;
        iVar1 = NdisAllocateTimerObject(*param_1,&local_28,puVar2 + 0x68);
        if (iVar1 == 0) {
          pcStack_20 = CallpAckTimeout;
          iVar1 = NdisAllocateTimerObject(*param_1,&local_28,puVar2 + 0x70);
          if (iVar1 == 0) {
            pcStack_20 = CallpDialTimeout;
            iVar1 = NdisAllocateTimerObject(*param_1,&local_28,puVar2 + 0x80);
            if (iVar1 == 0) {
              *puVar2 = 0;
              *(code **)(puVar2 + 2) = CallpFinalDerefEx;
              puVar2[8] = 0;
              *(code **)(puVar2 + 10) = CallpVcFinalDerefEx;
              puVar2[0x1c] = 1;
              return puVar2;
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c0002e96;
            uVar4 = 0x10;
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c0002e96;
            uVar4 = 0xf;
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c0002e96;
          uVar4 = 0xe;
        }
      }
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
LAB_1c0002e96:
  CallFree((longlong)puVar2);
  return (undefined4 *)0x0;
}



===== CallCleanup @ 1c0002ee0 =====

void CallCleanup(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  undefined3 uVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined7 uVar11;
  undefined8 uVar10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_2 = 0;
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
  }
  piVar1 = param_1 + 0x18;
  pbVar2 = (byte *)(param_1 + 0x1a);
  bVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *pbVar2 = bVar6;
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  uVar9 = param_1[0x6a];
  uVar11 = (undefined7)((ulonglong)param_2 >> 8);
  if ((uVar9 == 0) || ((param_1[0x6b] & 0x80000U) != 0)) {
    uVar10 = CONCAT71(uVar11,*pbVar2);
    KeReleaseSpinLock(piVar1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_dDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,param_3,param_1[0x32],
                 (char)param_1[0x6a],(char)param_1[0x6b]);
    }
    goto LAB_1c00035d9;
  }
  if ((uVar9 & 0x60000) == 0) {
    if ((uVar9 >> 0xc & 1) != 0) {
      iVar3 = param_1[0x94];
      param_1[0x6a] = uVar9 & 0xffffefff;
      KeReleaseSpinLock(piVar1,CONCAT71(uVar11,*pbVar2));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,param_3,param_1[0x32],(char)iVar3)
        ;
      }
      NdisCmMakeCallComplete
                (iVar3,*(undefined8 *)(param_1 + 0x38),0,0,*(undefined8 *)(param_1 + 0x3a));
      bVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
      param_1[0x3a] = 0;
      param_1[0x3b] = 0;
      *pbVar2 = bVar6;
    }
    if (((uint)param_1[0x6a] >> 8 & 1) == 0) {
      if ((param_1[0x6a] & 8U) != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
        }
        param_1[0x6a] = param_1[0x6a] & 0xfffffff7U | 0x40;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                   &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
        }
        KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
        CallFlushTxNBLQueue((longlong)param_1);
        CallFlushRxNBLQueue((longlong)param_1);
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        *(undefined1 *)(param_1 + 0x1a) = uVar7;
        if ((param_1[0x6a] & 0x10U) == 0 && ((uint)param_1[0x6b] >> 0xb & 1) == 0) {
          param_1[0x6b] = param_1[0x6b] | 0x800;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
          }
          KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
          NdisCmDispatchIncomingCloseCall(0,*(undefined8 *)(param_1 + 0x38),0,0);
          uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
          param_1[0x6b] = param_1[0x6b] & 0xfffff7ff;
          *(undefined1 *)(param_1 + 0x1a) = uVar7;
        }
        else {
          param_1[0x6a] = param_1[0x6a] & 0xffffffbf;
        }
        DereferenceRefCount(param_1);
      }
      if ((param_1[0x6a] & 0x10010U) == 0x10010) {
        param_1[0x6b] = param_1[0x6b] | 0x80000;
        param_1[0x6a] = param_1[0x6a] & 0xfffeffff;
        KeReleaseSpinLock(param_1 + 0x18,CONCAT71(0x100,(char)param_1[0x1a]));
        DereferenceRefCount(param_1 + 8);
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        param_1[0x6b] = param_1[0x6b] & 0xfff7ffff;
        *(undefined1 *)(param_1 + 0x1a) = uVar7;
      }
      uVar4 = param_1[0x6b];
      uVar9 = param_1[0x6a];
      uVar5 = (undefined3)(uVar9 >> 8);
      if ((uVar9 & 0x40) == 0 && (uVar4 >> 0xb & 1) == 0) {
        if ((uVar9 & 4) == 0) {
          if ((uVar9 >> 0xf & 1) != 0) {
            uVar9 = CONCAT31(uVar5,(char)param_1[0x1a]);
            if ((uVar4 & 0x200) != 0) goto LAB_1c000357c;
            param_1[0x6b] = uVar4 | 0x200;
            KeReleaseSpinLock(param_1 + 0x18,uVar9);
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                       &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
            }
            NdisCmCloseCallComplete(0,*(undefined8 *)(param_1 + 0x38),0);
            uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
            uVar9 = param_1[0x6a] & 0xffff7fff;
            *(undefined1 *)(param_1 + 0x1a) = uVar7;
            param_1[0x6a] = uVar9;
          }
          if ((char)param_1[0x30] != '\0') {
            if ((uVar9 >> 8 & 1) == 0) {
              if (*(longlong *)(param_1 + 0x3a) != 0) {
                PptpCmFreeCallParams(*(longlong *)(param_1 + 0x3a));
                param_1[0x3a] = 0;
                param_1[0x3b] = 0;
              }
              if (((byte)param_1[0x6a] & 0x42) == 2) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                           &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
                }
                param_1[0x6a] = param_1[0x6a] & 0xfffffffd;
                KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                           &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
                }
                NdisMCmDeleteVc(*(undefined8 *)(param_1 + 0x38));
                uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
                param_1[0x38] = 0;
                param_1[0x39] = 0;
                *(undefined1 *)(param_1 + 0x1a) = uVar7;
                CallDetachFromAdapter((longlong)param_1);
                KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                           &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
                }
                CtlDisconnectCall((longlong)param_1);
                CallpCancelCallTimers(param_1);
                DereferenceRefCount(param_1);
                uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
                *(undefined1 *)(param_1 + 0x1a) = uVar7;
              }
            }
            else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                       &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
            }
          }
          uVar9 = (uint)*(byte *)(param_1 + 0x1a);
          goto LAB_1c000357c;
        }
        KeReleaseSpinLock(param_1 + 0x18,CONCAT31(uVar5,(char)param_1[0x1a]));
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c00035d9;
        uVar8 = 0x1c;
      }
      else {
        KeReleaseSpinLock(param_1 + 0x18,CONCAT31(uVar5,(char)param_1[0x1a]));
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c00035d9;
        uVar8 = 0x1b;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
      goto LAB_1c00035d9;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    uVar9 = (uint)*pbVar2;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    uVar9 = (uint)*(byte *)(param_1 + 0x1a);
  }
LAB_1c000357c:
  KeReleaseSpinLock(param_1 + 0x18,uVar9);
LAB_1c00035d9:
  DereferenceRefCount(param_1);
  return;
}



===== CallDetachFromAdapter @ 1c0003608 =====

void CallDetachFromAdapter(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 200));
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x38) + 8);
  *(undefined1 *)(*(longlong *)(param_1 + 0x38) + 0x10) = uVar2;
  *(undefined8 *)
   (*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x20) + *(longlong *)(param_1 + 200) * 8) = 0;
  lVar1 = *(longlong *)(param_1 + 0x38);
  KeReleaseSpinLock(lVar1 + 8,CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x10)))
  ;
  *(undefined1 *)(param_1 + 0xc1) = 0;
  return;
}



===== CallFindAndLock @ 1c00036a8 =====

int * CallFindAndLock(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int *piVar3;
  void *_Dst;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  uint local_res18 [4];
  
  piVar3 = (int *)0x0;
  bVar1 = false;
  local_res18[0] = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
  *(undefined1 *)(param_1 + 2) = uVar2;
  do {
    if (PptpClientSide == '\0') {
      iVar8 = 0;
      iVar4 = 0;
LAB_1c0003730:
      local_res18[0] = 0;
      SystemPrng(local_res18);
      uVar9 = (ulonglong)local_res18[0] % (ulonglong)PptpWanEndpoints;
      if ((*(longlong *)(param_1[4] + uVar9 * 8) != 0) ||
         (piVar3 = CallAlloc(param_1), piVar3 == (int *)0x0)) break;
      *(int **)(param_1[4] + uVar9 * 8) = piVar3;
      *(ulonglong *)(piVar3 + 0x32) = uVar9;
LAB_1c00037ff:
      CallSetFullCallId((longlong)piVar3);
      goto LAB_1c0003807;
    }
    iVar8 = 1;
    uVar9 = 0xffffffff;
LAB_1c000378b:
    if (piVar3 != (int *)0x0) {
LAB_1c0003807:
      LOCK();
      *piVar3 = *piVar3 + 1;
      UNLOCK();
LAB_1c000380f:
      KeReleaseSpinLock(param_1 + 1,*(undefined1 *)(param_1 + 2));
      if (piVar3 != (int *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                   &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,piVar3[0x32]);
        }
        uVar2 = KeAcquireSpinLockRaiseToDpc(piVar3 + 0x18);
        *(undefined1 *)(piVar3 + 0x1a) = uVar2;
        piVar3[0x1c] = 2;
      }
      return piVar3;
    }
LAB_1c0003793:
    if (iVar8 < 2) {
      lVar5 = (longlong)(int)uVar9;
      uVar7 = uVar9;
LAB_1c00037a2:
      if (iVar8 == 0) {
        lVar5 = lVar5 + -1;
        uVar6 = (int)uVar7 - 1;
        if (lVar5 < 0) goto LAB_1c00037b9;
      }
      else {
        uVar6 = (int)uVar7 + 1;
        lVar5 = lVar5 + 1;
        if ((int)PptpWanEndpoints <= (int)uVar6) goto LAB_1c00037b9;
      }
      uVar7 = (ulonglong)uVar6;
      if ((*(longlong *)(param_1[4] + lVar5 * 8) == 0) &&
         (piVar3 = CallAlloc(param_1), piVar3 != (int *)0x0)) {
        *(int **)(param_1[4] + lVar5 * 8) = piVar3;
        *(ulonglong *)(piVar3 + 0x32) = uVar7;
        goto LAB_1c00037ff;
      }
      goto LAB_1c00037a2;
    }
    if (((bVar1) || (0x3ff6 < PptpWanEndpoints)) ||
       (_Dst = (void *)MyMemAlloc(PptpWanEndpoints * 8 + 0x50,0x63505450), _Dst == (void *)0x0))
    goto LAB_1c000380f;
    memcpy(_Dst,(void *)param_1[4],(ulonglong)PptpWanEndpoints << 3);
    ExFreePoolWithTag(param_1[4],0);
    PptpWanEndpoints = PptpWanEndpoints + 10;
    param_1[4] = _Dst;
    *(uint *)(param_1 + 9) = PptpWanEndpoints;
    InitCallLayer();
    bVar1 = true;
  } while( true );
  iVar4 = iVar4 + 1;
  if ((int)PptpWanEndpoints / 2 <= iVar4) goto LAB_1c000378b;
  goto LAB_1c0003730;
LAB_1c00037b9:
  iVar8 = iVar8 + 1;
  if (piVar3 != (int *)0x0) goto LAB_1c0003807;
  goto LAB_1c0003793;
}



===== CallFree @ 1c0003938 =====

void CallFree(longlong param_1)

{
  if (param_1 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 200));
    }
    *(undefined4 *)(param_1 + 0x30) = 0x45455246;
    if (*(longlong *)(param_1 + 0x1e0) != 0) {
      NdisFreeNetBufferList();
    }
    if (*(longlong *)(param_1 + 600) != 0) {
      NdisFreeIoWorkItem();
    }
    if (*(longlong *)(param_1 + 0x260) != 0) {
      NdisFreeIoWorkItem();
    }
    if (*(longlong *)(param_1 + 0x1a0) != 0) {
      NdisFreeTimerObject();
    }
    if (*(longlong *)(param_1 + 0x1c0) != 0) {
      NdisFreeTimerObject();
    }
    if (*(longlong *)(param_1 + 0x200) != 0) {
      NdisFreeTimerObject();
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== CallSetFullCallId @ 1c0003a3c =====

void CallSetFullCallId(longlong param_1)

{
  longlong lVar1;
  uint local_res10 [6];
  
  if (PptpCallIdMaskSet == '\0') {
    lVar1 = (ulonglong)PptpBaseCallId + *(longlong *)(param_1 + 200);
  }
  else {
    local_res10[0] = 0;
    SystemPrng(local_res10,4);
    lVar1 = (ulonglong)(~PptpCallIdMask & local_res10[0] & 0xffff) + *(longlong *)(param_1 + 200);
  }
  *(longlong *)(param_1 + 0xd0) = lVar1;
  return;
}



===== CallSetState @ 1c0003aa8 =====

void CallSetState(longlong param_1,uint param_2,undefined8 param_3,char param_4)

{
  undefined1 uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  uint uVar5;
  
  if (param_4 == '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x68) = uVar1;
  }
  uVar5 = *(uint *)(param_1 + 0x70);
  if ((((param_2 != uVar5) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    puVar4 = WPP_GLOBAL_Control;
    pcVar2 = szCallState(param_2);
    pcVar3 = szCallState(uVar5);
    WPP_SF_dss(*(undefined8 *)(puVar4 + 0x18),puVar4,pcVar2,*(undefined4 *)(param_1 + 200),pcVar3,
               pcVar2);
  }
  *(uint *)(param_1 + 0x70) = param_2;
  if (param_4 == '\0') {
    KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
  }
  return;
}



===== CallpCancelCallTimers @ 1c0003b74 =====

void CallpCancelCallTimers(int *param_1)

{
  char cVar1;
  
  cVar1 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x80));
  if (cVar1 != '\0') {
    DereferenceRefCount(param_1);
  }
  cVar1 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x68));
  if (cVar1 != '\0') {
    DereferenceRefCount(param_1);
  }
  cVar1 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x70));
  if (cVar1 != '\0') {
    DereferenceRefCount(param_1);
  }
  return;
}



===== CallpFinalDerefEx @ 1c0003bf0 =====

void CallpFinalDerefEx(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 200));
  }
  CallFree(param_1);
  return;
}



===== CallpVcFinalDerefEx @ 1c0003c90 =====

void CallpVcFinalDerefEx(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 0xa8));
  }
  lVar1 = param_1 + 0x40;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x48) = uVar2;
  if (*(int *)(param_1 + 0x50) == 0xb) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 0xa8));
    }
    if (((*(uint *)(param_1 + 0x188) & 4) != 0) && ((*(uint *)(param_1 + 0x18c) & 0x400) == 0)) {
      *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) | 0x400;
      KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x48));
      iVar3 = NdisMCmDeactivateVc(*(undefined8 *)(param_1 + 0xc0));
      if (iVar3 == 0x103) {
        return;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
                 &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,*(undefined4 *)(param_1 + 0xa8));
      }
      PptpCmDeactivateVcComplete(iVar3,(int *)(param_1 + -0x20),param_3);
      return;
    }
    uVar2 = *(undefined1 *)(param_1 + 0x48);
  }
  KeReleaseSpinLock(lVar1,uVar2);
  return;
}



===== GetStringFromSockAddr @ 1c0003e28 =====

undefined8 GetStringFromSockAddr(short *param_1,undefined8 param_2)

{
  if (*param_1 == 2) {
    RtlIpv4AddressToStringA(param_1 + 2);
  }
  else {
    RtlIpv6AddressToStringA(param_1 + 4);
  }
  return param_2;
}



===== StringCbCopyA @ 1c0003e6c =====

HRESULT __stdcall StringCbCopyA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (0x7ffffffe < cbDest - 1) {
    if (cbDest != 0) {
      *pszDest = '\0';
    }
    return -0x7ff8ffa9;
  }
  lVar3 = 0x7ffffffe - cbDest;
  lVar2 = (longlong)pszSrc - (longlong)pszDest;
  do {
    if ((lVar3 + cbDest == 0) || (pszDest[lVar2] == '\0')) break;
    *pszDest = pszDest[lVar2];
    pszDest = pszDest + 1;
    cbDest = cbDest - 1;
  } while (cbDest != 0);
  pcVar1 = pszDest + -1;
  if (cbDest != 0) {
    pcVar1 = pszDest;
  }
  *pcVar1 = '\0';
  return ~-(uint)(cbDest != 0) & 0x8007007a;
}



===== WPP_SF_ @ 1c0003ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1c0003efc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDDDDDDDDDDDDDDD @ 1c0003f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDDDDDDDDDD
               (undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,undefined1 param_16,
               undefined1 param_17,undefined1 param_18,undefined1 param_19)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,&param_10,4,&param_11,4,&param_12,4,&param_13,4,&param_14,4,&param_15,4,
             &param_16,4,&param_17,4,&param_18,4,&param_19,4,0);
  return;
}



===== WPP_SF_dDD @ 1c0004064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,0x14,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dd @ 1c00040c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_ddd @ 1c0004120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,0x70,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dddd @ 1c0004184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,0x27,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dss @ 1c00041f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dss(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               char *param_5,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  lVar1 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_5[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,0x5d,local_res20,4,
             param_5,lVar3,param_6,lVar2,0);
  return;
}



===== WPP_SF_q @ 1c00042c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qd @ 1c0004304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qdD @ 1c0004358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqD @ 1c00043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_s @ 1c0004428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,0);
  return;
}



===== WPP_SF_sd @ 1c000448c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WPP_SF_sdd @ 1c000450c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,0x4d,param_4,lVar2,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_sq @ 1c00045a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sq(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,8,0);
  return;
}



===== WPP_SF_sqdd @ 1c0004618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_sqdq @ 1c00046bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqdq(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,param_4,lVar2,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_ss @ 1c0004764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ss(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_4[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,param_4,lVar3,
             param_5,lVar2,0);
  return;
}



===== szCallState @ 1c0004808 =====

char * szCallState(uint param_1)

{
  if (param_1 < 0xc) {
    return (&PTR_s_INVALID_1c000a060)[(int)param_1];
  }
  return "UNKNOWN";
}



===== CtlFree @ 1c0004830 =====

void CtlFree(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  
  if ((param_1 != (longlong *)0x0) && ((int)param_1[4] == 0x54505450)) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1[5] + 8);
    *(undefined1 *)(param_1[5] + 0x10) = uVar4;
    *(undefined4 *)(param_1 + 4) = 0x45455246;
    lVar1 = *param_1;
    if ((*(longlong **)(lVar1 + 8) != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    lVar1 = param_1[5];
    KeReleaseSpinLock(lVar1 + 8,
                      CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x10)));
    if (param_1[0x48] != 0) {
      NdisFreeTimerObject();
    }
    if (param_1[0x4a] != 0) {
      NdisFreeTimerObject();
    }
    if (param_1[0x4b] != 0) {
      NdisFreeTimerObject();
    }
    DAT_1c000c4a8 = KeAcquireSpinLockRaiseToDpc(&gCallbackLock);
    lVar1 = param_1[0x11];
    if (lVar1 == 0) {
      KeReleaseSpinLock(&gCallbackLock,DAT_1c000c4a8);
    }
    else {
      param_1[0x11] = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
      }
      WskCloseSocketContextAndFreeSocketEx(lVar1,'\x01',0x1c000c4a0);
    }
    DereferenceAdapter(param_1[5]);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== CtlLogWskLibActivity @ 1c00049c0 =====

void CtlLogWskLibActivity(char *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
             &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1);
  }
  return;
}



===== CtlpStopTimeout @ 1c0004a10 =====

void CtlpStopTimeout(undefined8 param_1,longlong param_2)

{
  CtlpDeathTimeout(param_2);
  KeSetEvent(param_2 + 0x278,0,0);
  return;
}



===== CtlpWaitTimeout @ 1c0004a50 =====

void CtlpWaitTimeout(undefined8 param_1,longlong param_2)

{
  CtlpDeathTimeout(param_2);
  KeSetEvent(param_2 + 0x260,0,0);
  return;
}



===== WPP_SF_ds @ 1c0004a88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ds(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x3f,local_res20,4,
             param_5,lVar2,0);
  return;
}



===== WPP_SF_qdddddd @ 1c0004b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x2e,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_qq @ 1c0004bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qss @ 1c0004c04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qss(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               char *param_5,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_res20;
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  lVar1 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_5[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x62,&local_res20,8,
             param_5,lVar3,param_6,lVar2,0);
  return;
}



===== WPP_SF_sD @ 1c0004cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x5a,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WPP_SF_sdDdd @ 1c0004d54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sdDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x40,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_sqD @ 1c0004e14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x4b,param_4,lVar2,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_sqd @ 1c0004eac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_2,param_4,lVar2,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_sqddd @ 1c0004f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x2b,param_4,lVar2,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_sqdddd @ 1c0005000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqdddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x33,param_4,lVar2,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_sqq @ 1c00050d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0x4d,param_4,lVar2,
             &param_5,8,&param_6,8,0);
  return;
}



===== szCtlState @ 1c000516c =====

char * szCtlState(uint param_1)

{
  if (param_1 < 8) {
    return (&PTR_s_INVALID_1c000a0d0)[(int)param_1];
  }
  return "UNKNOWN";
}



===== NsiCliCleanupProviderContext @ 1c0005190 =====

void NsiCliCleanupProviderContext(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WPP_SF_dD @ 1c00051b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_902952016dc03c1032783b1d6d4fca4a_Traceguids,0xb,local_res20,4,
             &param_5,4,0);
  return;
}



===== MiniportHaltEx @ 1c0005210 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MiniportHaltEx(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  _gPptpNumMpHalts = _gPptpNumMpHalts + 1;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x48) != 0) {
    do {
      piVar2 = *(int **)(*(longlong *)(param_1 + 0x20) + uVar6 * 8);
      if ((piVar2 != (int *)0x0) && (piVar2[0xc] == 0x43505450)) {
        piVar1 = piVar2 + 0x18;
        uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
        *(undefined1 *)(piVar2 + 0x1a) = uVar3;
        if (piVar2[0x1c] - 3U < 8) {
          uVar4 = 0;
          CallSetState((longlong)piVar2,0xb,param_3,'\x01');
          uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),(char)piVar2[0x1a]);
          KeReleaseSpinLock(piVar1);
          CallCleanup(piVar2,uVar4,param_3);
        }
        else {
          KeReleaseSpinLock(piVar1,CONCAT31((int3)(piVar2[0x1c] - 3U >> 8),uVar3));
        }
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(param_1 + 0x48));
  }
  PptpAuthenticateIncomingCalls = 0;
  if (g_AcceptClientList != 0) {
    ExFreePoolWithTag(g_AcceptClientList,0);
    g_AcceptClientList = 0;
  }
  _g_ulAcceptClientAddresses = 0;
  if (g_TrustedClientList != 0) {
    ExFreePoolWithTag(g_TrustedClientList,0);
    g_TrustedClientList = 0;
  }
  _g_ulTrustedClientAddresses = 0;
  if (*(longlong *)(param_1 + 0x40) != 0) {
    WskCloseSocketContextAndFreeSocket(*(longlong *)(param_1 + 0x40));
    *(undefined8 *)(param_1 + 0x40) = 0;
    Pptpv4Initialized = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    WskCloseSocketContextAndFreeSocket(*(longlong *)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  DereferenceAdapter(param_1);
  NdisWaitEvent(param_1 + 0xa8,0);
  *(undefined4 *)(param_1 + 0xd0) = 0;
  AdapterFree(param_1);
  pgAdapter = 0;
  DeinitThreading();
  return;
}



===== MiniportSetOptions @ 1c0005390 =====

int MiniportSetOptions(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  code *local_b0;
  code *local_a8;
  undefined4 local_98;
  undefined4 local_94;
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
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  code *local_10;
  
  local_d4 = 0;
  local_d8 = 0x380191;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_94 = 0;
  local_b0 = PptpCoSendNetBufferLists;
  local_a8 = PptpCoRequest;
  iVar1 = NdisSetOptionalHandlers(param_1,&local_d8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return iVar1;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return iVar1;
    }
    uVar2 = 0xc;
  }
  else {
    local_98 = 0x9001a5;
    local_90 = PptpCmCreateVc;
    local_88 = PptpCmDeleteVc;
    local_80 = PptpCmOpenAf;
    local_78 = PptpCmCloseAf;
    local_70 = PptpCmRegisterSap;
    local_68 = PptpCmDeregisterSap;
    local_60 = PptpCmMakeCall;
    local_58 = PptpCmCloseCall;
    local_50 = PptpCmIncomingCallComplete;
    local_38 = PptpCmActivateVcComplete;
    local_30 = PptpCmDeactivateVcComplete;
    local_28 = PptpCmModifyCallQoS;
    local_20 = PptpCmOidRequest;
    local_18 = _guard_check_icall;
    local_10 = _guard_check_icall;
    local_48 = PptpCmDropParty;
    local_40 = PptpCmDropParty;
    iVar1 = NdisSetOptionalHandlers(param_1,&local_98);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0) {
      return iVar1;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return iVar1;
    }
    uVar2 = 0xd;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar1);
  return iVar1;
}



===== WPP_SF_Dd @ 1c0005564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== AdapterFree @ 1c00055b4 =====

void AdapterFree(longlong param_1)

{
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
      *(undefined8 *)(param_1 + 0x20) = 0;
    }
    if (*(longlong *)(param_1 + 0x60) != 0) {
      NdisFreeNetBufferListPool();
    }
    if (*(longlong *)(param_1 + 0x70) != 0) {
      NdisFreeNetBufferListPool();
    }
    if (*(longlong *)(param_1 + 0x80) != 0) {
      NdisFreeNetBufferListPool();
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== WppClassicProviderCallback @ 1c0005640 =====

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



===== DereferenceSap @ 1c0005674 =====

void DereferenceSap(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + -1;
  iVar1 = *(int *)(param_1 + 0xa4);
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  KeReleaseSpinLock(param_1 + 8,uVar2);
  if (iVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    ScheduleWorkItem(PptpCmDeregSapPassive,param_1,0,0);
  }
  return;
}



===== PptpCmDropParty @ 1c0005720 =====

undefined8 PptpCmDropParty(void)

{
  return 0;
}



===== PptpCmCloseCall @ 1c0005730 =====

int PptpCmCloseCall(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = 0x103;
  bVar3 = false;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0;
    param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  piVar1 = param_1 + 0x18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_1 + 0x1a) = uVar4;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0;
    param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  uVar2 = param_1[0x6a];
  param_1[0x6a] = uVar2 | 0x8010;
  if ((uVar2 & 0x40) == 0) {
    if ((uVar2 & 8) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_2 = 0;
        param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      iVar5 = 0;
      param_1[0x6a] = param_1[0x6a] & 0xffff7fff;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_2 = 0;
        param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      param_1[0x6a] = param_1[0x6a] | 0x20;
      bVar3 = true;
      LOCK();
      param_1[8] = param_1[8] + 1;
      UNLOCK();
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_2 = 0;
      param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1[0x32]);
    }
    param_1[0x6a] = param_1[0x6a] & 0xffffffbf;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_2 = 0;
      param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
  }
  uVar6 = CONCAT71((int7)((ulonglong)param_2 >> 8),(char)param_1[0x1a]);
  KeReleaseSpinLock(piVar1);
  if (bVar3) {
    iVar5 = CallpSendCallClearReq(param_1,uVar6,param_3);
    if (iVar5 == 0x103) goto LAB_1c0005965;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
    param_1[0x6a] = param_1[0x6a] & 0xffffffdf;
    *(undefined1 *)(param_1 + 0x1a) = uVar4;
    KeReleaseSpinLock(piVar1,uVar4);
    DereferenceRefCount(param_1 + 8);
    iVar5 = 0x103;
  }
  uVar6 = 0xb;
  CallSetState((longlong)param_1,0xb,param_3,'\0');
  CallCleanup(param_1,uVar6,param_3);
LAB_1c0005965:
  DereferenceRefCount(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar5);
  }
  return iVar5;
}



===== PptpCmCreateVc @ 1c00059c0 =====

undefined8 PptpCmCreateVc(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar2 = param_2;
  puVar3 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = 0x24;
    puVar3 = (undefined8 *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  piVar1 = CallFindAndLock(param_1,uVar2,(uint)puVar3);
  if (piVar1 == (int *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      *(undefined1 *)((longlong)piVar1 + 0xc2) = 1;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                   &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,piVar1);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                   &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,piVar1);
        }
      }
    }
    *(undefined8 *)(piVar1 + 0x38) = param_2;
    piVar1[0x3c] = 0;
    piVar1[0x3d] = 0;
    piVar1[0x3e] = 0;
    piVar1[0x3f] = 0;
    piVar1[0x40] = 0;
    piVar1[0x41] = 0;
    piVar1[0x42] = 0;
    piVar1[0x43] = 0;
    piVar1[0x3c] = *(int *)((longlong)param_1 + 0x4c);
    piVar1[0x3d] = *(int *)((longlong)param_1 + 0x4c);
    piVar1[0x3e] = *(int *)((longlong)param_1 + 0x54);
    piVar1[0x3f] = *(int *)((longlong)param_1 + 0x54);
    piVar1[0x42] = *(int *)(param_1 + 0xb);
    piVar1[0x43] = *(int *)(param_1 + 0xb);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    piVar1[0x6a] = piVar1[0x6a] | 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    DereferenceRefCount(piVar1);
    KeReleaseSpinLock(piVar1 + 0x18,(char)piVar1[0x1a]);
    *param_3 = piVar1;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,piVar1);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== PptpCmDeleteVc @ 1c0005c20 =====

undefined8 PptpCmDeleteVc(int *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  bool bVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  uVar1 = param_1[0x6a];
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  *(undefined1 *)(param_1 + 0x1a) = uVar2;
  param_1[0x6a] = uVar1 & 0xfffffffe;
  bVar3 = (uVar1 >> 0xe & 1) != 0;
  if (bVar3) {
    param_1[0x6a] = uVar1 & 0xffffbffe;
  }
  CallDetachFromAdapter((longlong)param_1);
  KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
  if (bVar3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1[0x32]);
    }
    CtlDisconnectCall((longlong)param_1);
  }
  CallpCancelCallTimers(param_1);
  DereferenceRefCount(param_1);
  return 0;
}



===== PptpCmDeregSapPassive @ 1c0005d40 =====

void PptpCmDeregSapPassive(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1 + 8);
  uVar2 = *(undefined8 *)(lVar1 + 0x88);
  *(undefined8 *)(lVar1 + 0x88) = 0;
  lVar3 = *(longlong *)(lVar1 + 0x38);
  *(undefined1 *)(lVar1 + 0x10) = uVar4;
  lVar5 = 0;
  if (lVar3 != 0) {
    *(undefined8 *)(lVar1 + 0x38) = 0;
    lVar5 = lVar3;
  }
  KeReleaseSpinLock(lVar1 + 8,CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar4));
  if (lVar3 != 0) {
    WskCloseSocketContextAndFreeSocket(lVar5);
  }
  DereferenceAdapter(lVar1);
  DereferenceAf(lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  NdisCmDeregisterSapComplete(0,uVar2);
  return;
}



===== PptpCmDeregisterSap @ 1c0005e30 =====

int PptpCmDeregisterSap(longlong param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = 0x103;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  if (*(longlong *)(param_1 + 0x88) == 0) {
    iVar2 = -0x3fffffff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
  }
  KeReleaseSpinLock(param_1 + 8,*(undefined1 *)(param_1 + 0x10));
  if (iVar2 == 0x103) {
    DereferenceSap(param_1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar2);
  }
  return iVar2;
}



===== PptpCmMakeCall @ 1c0005f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PptpCmMakeCall(int *param_1,uint *param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  int iVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  wchar_t *pwVar13;
  uint uVar14;
  undefined *puVar15;
  short **ppsVar16;
  undefined1 auStackY_138 [32];
  int local_80 [2];
  short *local_78;
  undefined *local_70;
  longlong local_68;
  uint *local_60;
  undefined8 local_58;
  short *local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_138;
  local_60 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  if ((param_1 == (int *)0x0) || (param_1[0xc] != 0x43505450)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    return -0x3ffeffeb;
  }
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  uVar14 = param_1[0x1c];
  *(undefined1 *)(param_1 + 0x1a) = uVar7;
  bVar6 = true;
  if (uVar14 != 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar8 = 0x30;
      goto LAB_1c0006038;
    }
    goto LAB_1c0006044;
  }
  local_58 = *(undefined8 *)(param_1 + 0xe);
  local_78 = (short *)0x0;
  local_80[0] = 0;
  local_50 = (short *)0x0;
  uStack_48 = 0;
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  uVar14 = *param_2;
  if ((uVar14 & 0x19) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,uVar14);
    }
    iVar9 = -0x3fffff45;
    bVar6 = true;
    goto LAB_1c0006511;
  }
  if (((uVar14 & 2) == 0) && (local_68 = *(longlong *)(param_2 + 4), local_68 != 0)) {
    uVar14 = *(uint *)(local_68 + 0x14);
    if (uVar14 < 0x30) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar8 = 0x32;
LAB_1c0006038:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,uVar14);
      }
      goto LAB_1c0006044;
    }
    uVar2 = *(ushort *)(local_68 + 0x38);
    puVar15 = (undefined *)(ulonglong)uVar2;
    if (uVar2 < 0xb4) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar14 = (uint)uVar2;
        uVar8 = 0x33;
        goto LAB_1c0006038;
      }
      goto LAB_1c0006044;
    }
    lVar12 = *(longlong *)(local_68 + 0x40) + 0x38 + local_68;
    if ((*(uint *)(lVar12 + 0x10) & 0xfffffeef) != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      goto LAB_1c0006044;
    }
    if (*(int *)(lVar12 + 0x68) == 0x18) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar15 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      lVar12 = (ulonglong)*(uint *)(lVar12 + 0x6c) + lVar12;
      *(longlong *)(param_1 + 0x6e) = lVar12;
      uVar3 = *(undefined4 *)(lVar12 + 0xc);
      uVar4 = *(undefined4 *)(lVar12 + 0x10);
      uVar5 = *(undefined4 *)(lVar12 + 0x14);
      *(undefined4 *)((longlong)param_1 + 0x18d) = *(undefined4 *)(lVar12 + 8);
      *(undefined4 *)((longlong)param_1 + 0x191) = uVar3;
      *(undefined4 *)((longlong)param_1 + 0x195) = uVar4;
      *(undefined4 *)((longlong)param_1 + 0x199) = uVar5;
      *(undefined1 *)((longlong)param_1 + 0x19d) = 0;
      lVar12 = -1;
      do {
        lVar10 = lVar12 + 1;
        lVar1 = lVar12 + 0x18e;
        lVar12 = lVar10;
      } while (*(char *)(lVar1 + (longlong)param_1) != '\0');
      if (lVar10 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar15 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                  &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
        }
      }
      else {
        local_70 = WPP_GLOBAL_Control;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar15 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
            WPP_SF_DDDDDDDDDDDDDDDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                       &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,
                       (uint)*(byte *)((longlong)param_1 + 0x18d),
                       *(undefined1 *)((longlong)param_1 + 0x18e),
                       *(undefined1 *)((longlong)param_1 + 399),(char)param_1[100],
                       *(undefined1 *)((longlong)param_1 + 0x191),
                       *(undefined1 *)((longlong)param_1 + 0x192),
                       *(undefined1 *)((longlong)param_1 + 0x193),(char)param_1[0x65],
                       *(undefined1 *)((longlong)param_1 + 0x195),
                       *(undefined1 *)((longlong)param_1 + 0x196),
                       *(undefined1 *)((longlong)param_1 + 0x197),(char)param_1[0x66],
                       *(undefined1 *)((longlong)param_1 + 0x199),
                       *(undefined1 *)((longlong)param_1 + 0x19a),
                       *(undefined1 *)((longlong)param_1 + 0x19b),(char)param_1[0x67]);
          }
          local_70 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar15 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
            WPP_SF_DDDDDDDDDDDDDDDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                       &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,
                       (uint)*(byte *)(param_1 + 100),*(undefined1 *)((longlong)param_1 + 399),
                       *(undefined1 *)((longlong)param_1 + 0x18e),
                       *(undefined1 *)((longlong)param_1 + 0x18d),
                       *(undefined1 *)((longlong)param_1 + 0x192),
                       *(undefined1 *)((longlong)param_1 + 0x191),(char)param_1[0x65],
                       *(undefined1 *)((longlong)param_1 + 0x193),
                       *(undefined1 *)((longlong)param_1 + 0x195),
                       *(undefined1 *)((longlong)param_1 + 0x196),
                       *(undefined1 *)((longlong)param_1 + 0x197),(char)param_1[0x66],
                       *(undefined1 *)((longlong)param_1 + 0x199),
                       *(undefined1 *)((longlong)param_1 + 0x19a),
                       *(undefined1 *)((longlong)param_1 + 0x19b),(char)param_1[0x67]);
          }
        }
      }
    }
    uVar2 = *(ushort *)(local_68 + 0x28);
    if (uVar2 < 0x83) {
      pwVar13 = (wchar_t *)(*(longlong *)(local_68 + 0x30) + local_68 + 0x28);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar2,puVar15,pwVar13);
      }
      ppsVar16 = &local_50;
      iVar9 = RtlIpv6StringToAddressW(pwVar13,&local_78);
      if ((iVar9 < 0) || (*local_78 != 0)) {
        ppsVar16 = &local_78;
        iVar9 = RtlIpv4StringToAddressW(pwVar13,1,ppsVar16,local_80);
        if ((-1 < iVar9) && (*local_78 == 0)) {
          param_1[0x47] = local_80[0];
          uVar8 = 2;
          goto LAB_1c000668b;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c0006548;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
        goto LAB_1c0006511;
        uVar8 = 0x3b;
LAB_1c00066cc:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      else {
        uVar8 = 0x17;
        *(short **)(param_1 + 0x48) = local_50;
        *(undefined8 *)(param_1 + 0x4a) = uStack_48;
LAB_1c000668b:
        *(undefined2 *)(param_1 + 0x46) = uVar8;
        if (*(longlong *)(param_1 + 0x3a) == 0) {
          *(uint **)(param_1 + 0x3a) = local_60;
          *(undefined1 *)(param_1 + 0x30) = 0;
          CallSetState((longlong)param_1,3,ppsVar16,'\x01');
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                    &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
          }
          param_1[0x6a] = param_1[0x6a] | 0x1000;
          bVar6 = false;
          param_1[0x94] = -0x3fffffff;
          KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
          LOCK();
          *param_1 = *param_1 + 1;
          UNLOCK();
          uVar11 = ScheduleWorkItem(PptpCmMakeCallCallback,local_58,param_1,0);
          iVar9 = (int)uVar11;
          if (iVar9 == 0) {
            iVar9 = 0x103;
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                      &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
            }
            uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
            param_1[0x6a] = param_1[0x6a] & 0xffffefff;
            *(undefined1 *)(param_1 + 0x1a) = uVar7;
            KeReleaseSpinLock(param_1 + 0x18,uVar7);
            DereferenceRefCount(param_1);
          }
        }
        else {
          iVar9 = 0x10007;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c0006548;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar8 = 0x3c;
            goto LAB_1c00066cc;
          }
        }
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,(uint)uVar2);
      }
      iVar9 = -0x3ffeffeb;
    }
  }
  else {
LAB_1c0006044:
    iVar9 = -0x3ffeffeb;
    bVar6 = true;
  }
LAB_1c0006511:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar9);
  }
  if (!bVar6) {
    return iVar9;
  }
LAB_1c0006548:
  KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
  return iVar9;
}



===== PptpCmRegSapPassive @ 1c0006890 =====

void PptpCmRegSapPassive(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  iVar5 = 0;
  if (g_fPagesLocked == '\0') {
    MmLockPagableDataSection(PptpCmActivateVcComplete);
    g_fPagesLocked = '\x01';
  }
  uVar4 = PptpInitialize(lVar1);
  if (((((int)uVar4 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      (param_2 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
      (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    param_2 = 0x1a;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  iVar3 = CtlListen(lVar1,param_2);
  if (iVar3 == 0) {
LAB_1c0006955:
    if (-1 < (int)uVar4) goto LAB_1c0006988;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    if (-1 < iVar3) goto LAB_1c0006955;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  iVar5 = -0x3fffffff;
LAB_1c0006988:
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 8);
  uVar4 = *(undefined8 *)(lVar1 + 0x88);
  *(undefined1 *)(lVar1 + 0x10) = uVar2;
  if (iVar5 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    *(undefined4 *)(lVar1 + 0xa4) = 1;
    ReferenceAdapter(lVar1);
    ReferenceAf(lVar1);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    *(undefined8 *)(lVar1 + 0x88) = 0;
  }
  KeReleaseSpinLock(lVar1 + 8,*(undefined1 *)(lVar1 + 0x10));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar5);
  }
  NdisCmRegisterSapComplete(iVar5,uVar4,lVar1);
  return;
}



===== PptpCmRegisterSap @ 1c0006a90 =====

ulonglong PptpCmRegisterSap(longlong param_1,int *param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  bVar3 = false;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  *param_4 = param_1;
  lVar1 = param_1 + 8;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x10) = uVar4;
  if (*(longlong *)(param_1 + 0x88) == 0) {
    bVar2 = false;
    if ((*param_2 == 0x8000) && (0xb < (uint)param_2[1])) {
      *(int *)(param_1 + 0x90) = param_2[2];
      iVar5 = 0;
      if (param_2[3] != -1) {
        iVar5 = param_2[3];
      }
      *(int *)(param_1 + 0x94) = iVar5;
      *(undefined8 *)(param_1 + 0x88) = param_3;
    }
    else {
      bVar3 = true;
    }
  }
  else {
    bVar2 = true;
  }
  KeReleaseSpinLock(lVar1,uVar4);
  if (bVar2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uVar6 = 0xc0010021;
  }
  else if (bVar3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    uVar6 = 0xc0010015;
  }
  else {
    uVar7 = ScheduleWorkItem(PptpCmRegSapPassive,param_1,0,0);
    uVar6 = uVar7 & 0xffffffff;
    if ((int)uVar7 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      uVar6 = 0x103;
    }
    else {
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined1 *)(param_1 + 0x10) = uVar4;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      *(undefined8 *)(param_1 + 0x88) = 0;
      KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x10));
    }
  }
  return uVar6;
}



===== ReferenceSap @ 1c0006cc0 =====

bool ReferenceSap(longlong param_1)

{
  undefined1 uVar1;
  bool bVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  bVar2 = *(longlong *)(param_1 + 0x88) != 0;
  if (bVar2) {
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
  }
  KeReleaseSpinLock(param_1 + 8,uVar1);
  return bVar2;
}



===== WPP_SF_S @ 1c0006d28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,0x3a,param_4,lVar1,0);
  return;
}



===== WPP_SF_sddd @ 1c0006da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,0x57,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== MainPassiveLevelThread @ 1c0006e50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MainPassiveLevelThread(void)

{
  int iVar1;
  longlong lVar2;
  undefined *local_18;
  undefined *local_10;
  
  local_18 = &EventPassiveThread;
  local_10 = &EventKillThread;
  while (iVar1 = KeWaitForMultipleObjects(2,&local_18,1,0,0,0,0,0), iVar1 == 0) {
    while (lVar2 = ExInterlockedRemoveHeadList(&WorkItemList,&GlobalThreadLock), lVar2 != 0) {
      (**(code **)(lVar2 + 0x10))(lVar2);
      ExFreePoolWithTag(lVar2,0);
    }
  }
  while (lVar2 = ExInterlockedRemoveHeadList(&WorkItemList,&GlobalThreadLock), lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  hPassiveThread = 0;
  PsTerminateSystemThread(0);
  return;
}



===== INET_ADDR_EQUAL @ 1c0006f3c =====

ulonglong INET_ADDR_EQUAL(short param_1,longlong *param_2,longlong *param_3)

{
  if (param_1 != 0x17) {
    return (ulonglong)CONCAT31((int3)((ulonglong)*param_3 >> 8),(int)*param_2 == (int)*param_3);
  }
  if ((param_2[1] == param_3[1]) && (*param_2 == *param_3)) {
    return CONCAT71((int7)((ulonglong)*param_3 >> 8),1);
  }
  return 0;
}



===== NsiCliAddHostRoute @ 1c0006f6c =====

void NsiCliAddHostRoute(undefined4 param_1,NET_IFINDEX *param_2)

{
  CHAR local_res8 [32];
  
  local_res8._0_4_ = param_1;
  NsiCliAddHostRouteHelper(2,(CHAR (*) [8])local_res8,' ',param_2);
  return;
}



===== NsiCliAddHostRouteHelper @ 1c0006f98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "enum_6678": Some values do not have unique names */

void NsiCliAddHostRouteHelper(ushort param_1,CHAR (*param_2) [8],UINT8 param_3,NET_IFINDEX *param_4)

{
  NTSTATUS NVar1;
  undefined1 auStackY_128 [32];
  SOCKADDR_INET local_e8;
  SOCKADDR_INET local_c8;
  _MIB_IPFORWARD_ROW2 local_a8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(&local_a8,0,0x68);
  local_e8._16_1_ = '\0';
  local_e8._17_1_ = '\0';
  local_e8._18_1_ = '\0';
  local_e8._19_1_ = '\0';
  local_e8._20_1_ = '\0';
  local_e8._21_1_ = '\0';
  local_e8._22_1_ = '\0';
  local_e8._23_1_ = '\0';
  local_e8.Ipv6.field4_0x18 = (_union_6653)0;
  local_c8._16_8_ = 0;
  local_c8.Ipv6.field4_0x18 = (_union_6653)0;
  local_e8.Ipv4.sin_zero[0] = '\0';
  local_e8.Ipv4.sin_zero[1] = '\0';
  local_e8.Ipv4.sin_zero[2] = '\0';
  local_e8.Ipv4.sin_zero[3] = '\0';
  local_e8.Ipv4.sin_zero[4] = '\0';
  local_e8.Ipv4.sin_zero[5] = '\0';
  local_e8.Ipv4.sin_zero[6] = '\0';
  local_e8.Ipv4.sin_zero[7] = '\0';
  local_e8._2_6_ = 0;
  local_e8.Ipv4.sin_family = param_1;
  local_c8._0_8_ = 0;
  local_c8.Ipv4.sin_zero[0] = '\0';
  local_c8.Ipv4.sin_zero[1] = '\0';
  local_c8.Ipv4.sin_zero[2] = '\0';
  local_c8.Ipv4.sin_zero[3] = '\0';
  local_c8.Ipv4.sin_zero[4] = '\0';
  local_c8.Ipv4.sin_zero[5] = '\0';
  local_c8.Ipv4.sin_zero[6] = '\0';
  local_c8.Ipv4.sin_zero[7] = '\0';
  if (param_1 == 0x17) {
    local_e8.Ipv4.sin_zero = *param_2;
    local_e8._16_8_ = param_2[1];
  }
  else {
    local_e8.Ipv4.sin_port = 0;
    local_e8.Ipv4.sin_addr.S_un = (IN_ADDR)(IN_ADDR)*(undefined4 *)*param_2;
  }
  NVar1 = GetBestRoute2((NET_LUID *)0x0,0,(SOCKADDR_INET *)0x0,&local_e8,0,&local_a8,&local_c8);
  if (-1 < NVar1) {
    if (local_a8.DestinationPrefix.Prefix.Ipv4.sin_family == 0x17) {
      local_a8.DestinationPrefix.Prefix.Ipv4.sin_zero._0_4_ = *(undefined4 *)*param_2;
      local_a8.DestinationPrefix.Prefix.Ipv4.sin_zero._4_4_ = *(undefined4 *)(*param_2 + 4);
      local_a8.DestinationPrefix.Prefix._16_4_ = *(undefined4 *)param_2[1];
      local_a8.DestinationPrefix.Prefix._20_4_ = *(undefined4 *)(param_2[1] + 4);
    }
    else {
      local_a8.DestinationPrefix.Prefix.Ipv4.sin_addr.S_un = *(IN_ADDR *)*param_2;
    }
    local_a8.ValidLifetime = 0xffffffff;
    local_a8.PreferredLifetime = 0xffffffff;
    local_a8.Metric = 1;
    local_a8.Protocol = MIB_IPPROTO_NETMGMT;
    local_a8.Publish = '\0';
    local_a8.Immortal = '\x01';
    if (param_4 != (NET_IFINDEX *)0x0) {
      *param_4 = local_a8.InterfaceIndex;
    }
    local_a8.DestinationPrefix.PrefixLength = param_3;
    InternalCreateOrRefIpForwardEntry2(1,&local_a8);
  }
  return;
}



===== NsiCliAddHostV6Route @ 1c00070b4 =====

void NsiCliAddHostV6Route(CHAR (*param_1) [8],NET_IFINDEX *param_2)

{
  NsiCliAddHostRouteHelper(0x17,param_1,0x80,param_2);
  return;
}



===== NsiCliAttachProvider @ 1c00070e0 =====

int NsiCliAttachProvider(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,0x18,NsiCliTag);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar2 + 0x10) = param_1;
    iVar1 = NmrClientAttachProvider(param_1,lVar2,&NsiCliDispatch,lVar2,lVar2 + 8);
    if (iVar1 < 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  return iVar1;
}



===== NsiCliDeleteHostRoute @ 1c000716c =====

void NsiCliDeleteHostRoute(undefined4 param_1)

{
  undefined4 local_res8 [8];
  
  local_res8[0] = param_1;
  NsiCliDeleteHostRouteHelper(2,(longlong *)local_res8);
  return;
}



===== NsiCliDeleteHostRouteHelper @ 1c0007190 =====

/* WARNING: Enum "enum_6678": Some values do not have unique names */

NTSTATUS NsiCliDeleteHostRouteHelper(ADDRESS_FAMILY param_1,longlong *param_2)

{
  uint uVar1;
  NTSTATUS NVar2;
  ulonglong uVar3;
  longlong lVar4;
  PMIB_IPFORWARD_TABLE2 Memory;
  uint uVar5;
  MIB_IPFORWARD_ROW2 *Row;
  PMIB_IPFORWARD_TABLE2 local_res18 [2];
  
  local_res18[0] = (PMIB_IPFORWARD_TABLE2)0x0;
  NVar2 = GetIpForwardTable2(param_1,local_res18);
  Memory = local_res18[0];
  if (-1 < NVar2) {
    uVar1 = local_res18[0]->NumEntries;
    uVar3 = 0;
    while (uVar5 = (uint)uVar3, uVar5 < uVar1) {
      Row = Memory->Table + uVar3;
      if (Row->Protocol == MIB_IPPROTO_NETMGMT) {
        lVar4 = 8;
        if ((Row->DestinationPrefix).Prefix.Ipv4.sin_family != 0x17) {
          lVar4 = 4;
        }
        uVar3 = INET_ADDR_EQUAL(param_1,(longlong *)
                                        ((Row->DestinationPrefix).Prefix.Ipv6.sin6_addr.u.Byte +
                                        lVar4 + -8),param_2);
        if ((char)uVar3 != '\0') {
          if (Row != (MIB_IPFORWARD_ROW2 *)0x0) {
            NVar2 = DeleteIpForwardEntry2(Row);
            Memory = local_res18[0];
            goto LAB_1c0007232;
          }
          break;
        }
      }
      uVar3 = (ulonglong)(uVar5 + 1);
    }
    NVar2 = -0x3ffffddb;
  }
LAB_1c0007232:
  if (Memory != (PMIB_IPFORWARD_TABLE2)0x0) {
    FreeMibTable(Memory);
  }
  return NVar2;
}



===== NsiCliDeleteHostV6Route @ 1c0007260 =====

void NsiCliDeleteHostV6Route(longlong *param_1)

{
  NsiCliDeleteHostRouteHelper(0x17,param_1);
  return;
}



===== NsiCliDeregisterClient @ 1c0007280 =====

void NsiCliDeregisterClient(void)

{
  int iVar1;
  bool bVar2;
  
  if (NsiCliHandle != 0) {
    NmrDeregisterClient();
    NmrWaitForClientDeregisterComplete(NsiCliHandle);
    LOCK();
    iVar1 = NsiCliDriverRefCount + -1;
    UNLOCK();
    bVar2 = NsiCliDriverRefCount == 1;
    NsiCliDriverRefCount = iVar1;
    if (bVar2) {
      KeSetEvent(&NsiCliDriverUnloadEvent,0,0);
    }
    NsiCliHandle = 0;
    KeWaitForSingleObject(&NsiCliDriverUnloadEvent,0,0,0,0);
  }
  return;
}



===== NsiCliGetInterfaceSpeed @ 1c000730c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NsiCliGetInterfaceSpeed(NET_IFINDEX param_1,undefined4 *param_2)

{
  NTSTATUS NVar1;
  undefined1 auStack_588 [32];
  _MIB_IF_ROW2 local_568;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_588;
  memset(&local_568,0,0x548);
  *param_2 = 0;
  local_568.InterfaceIndex = param_1;
  NVar1 = GetIfEntry2(&local_568);
  if (-1 < NVar1) {
    *param_2 = (undefined4)local_568.TransmitLinkSpeed;
  }
  return;
}



===== NsiCliGetLinkSpeedFromInterfaceIpAddress @ 1c0007390 =====

NTSTATUS NsiCliGetLinkSpeedFromInterfaceIpAddress(ULONG param_1,undefined4 *param_2)

{
  NTSTATUS NVar1;
  ulonglong uVar2;
  PMIB_UNICASTIPADDRESS_TABLE local_res10;
  
  *param_2 = 0;
  local_res10 = (PMIB_UNICASTIPADDRESS_TABLE)0x0;
  NVar1 = GetUnicastIpAddressTable(2,&local_res10);
  if (-1 < NVar1) {
    NVar1 = -0x3ffffddb;
    for (uVar2 = 0; (uint)uVar2 < local_res10->NumEntries; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
      if (local_res10->Table[uVar2].Address.Ipv6.sin6_flowinfo == param_1) {
        NVar1 = NsiCliGetInterfaceSpeed(local_res10->Table[uVar2].InterfaceIndex,param_2);
        break;
      }
    }
  }
  if (local_res10 != (PMIB_UNICASTIPADDRESS_TABLE)0x0) {
    FreeMibTable(local_res10);
  }
  return NVar1;
}



===== WskCreateAndIntializeSockContext @ 1c0007430 =====

void WskCreateAndIntializeSockContext(void)

{
  undefined4 *puVar1;
  
  if (g_fWSKPagesLocked == '\0') {
    MmLockPagableDataSection(WskCreateSocket);
    g_fWSKPagesLocked = '\x01';
  }
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x240,0x57535450);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x434b5357;
    *(code **)(puVar1 + 0xc) = WskLibDummyLogger;
    *(code **)(puVar1 + 0x82) = FreeSockHandle;
    puVar1[0x80] = 1;
  }
  return;
}



===== GetWskClientContext @ 1c00074b0 =====

undefined8 GetWskClientContext(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (g_bWskAttachComplete != '\0') {
    uVar1 = g_pWskState;
  }
  return uVar1;
}



===== WskClientEvent @ 1c00074d0 =====

undefined8 WskClientEvent(void)

{
  return 0xc0000002;
}



===== WskNotifyAttachProvider @ 1c00074e0 =====

int WskNotifyAttachProvider(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(longlong *)(param_3 + 0x20) == 0) ||
     (0x100 < *(ushort *)(*(longlong *)(param_3 + 0x20) + 2))) {
    iVar1 = -0x3ffffd47;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x18,0x77534152);
    g_pWskState = lVar2;
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(lVar2 + 0x10) = param_1;
      iVar1 = NmrClientAttachProvider(param_1,lVar2,&DAT_1c000a000,lVar2,lVar2 + 8);
      if (-1 < iVar1) {
        g_bWskAttachComplete = 1;
        return iVar1;
      }
    }
  }
  if (g_pWskState != 0) {
    ExFreePoolWithTag(g_pWskState,0);
    g_pWskState = 0;
  }
  return iVar1;
}



===== WskNotifyDetachProvider @ 1c00075a0 =====

undefined8 WskNotifyDetachProvider(void)

{
  g_pWskState = 0;
  g_bWskAttachComplete = 0;
  return 0;
}



===== WskStopClientModule @ 1c00075bc =====

void WskStopClientModule(void)

{
  if (WskClientHandle != 0) {
    NmrDeregisterClient();
    NmrWaitForClientDeregisterComplete(WskClientHandle);
    WskClientHandle = 0;
  }
  return;
}



===== __GSHandlerCheck @ 1c0007608 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000762c =====

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



===== __cpu_features_init @ 1c00076a0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000770a) */
/* WARNING: Removing unreachable block (ram,0x0001c00076b9) */
/* WARNING: Removing unreachable block (ram,0x0001c00076aa) */

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



===== __security_check_cookie @ 1c0007770 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00077b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00077e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00077e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007810 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0007880 =====

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



===== memset @ 1c0007b80 =====

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



===== __memset_repmovs @ 1c0007cc0 =====

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



===== __memset_query @ 1c0007d40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0007dc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0007f00 =====

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



===== __memset_spec_plain @ 1c0007f80 =====

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



===== CallConnectToCtl @ 1c0010008 =====

undefined1 CallConnectToCtl(longlong param_1,longlong param_2,char param_3)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar8 = 0;
  if (param_3 == '\0') {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x68) = uVar2;
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x38) + 8);
  puVar6 = auStack_28;
  *(undefined1 *)(*(longlong *)(param_1 + 0x38) + 0x10) = uVar2;
  puVar7 = auStack_28;
  if (*(longlong *)(param_1 + 0x50) == 0) {
    lVar4 = param_2 + 0x38;
    *(longlong *)(param_1 + 0x50) = param_2;
    plVar5 = *(longlong **)(param_2 + 0x40);
    plVar3 = (longlong *)(param_1 + 0x10);
    if (*plVar5 != lVar4) {
      lVar4 = 3;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar1)();
      puVar6 = auStack_20;
    }
    *plVar3 = lVar4;
    uVar8 = 1;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 8) = plVar3;
    LOCK();
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    UNLOCK();
    puVar7 = puVar6;
  }
  lVar4 = *(longlong *)(param_1 + 0x38);
  uVar2 = *(undefined1 *)(lVar4 + 0x10);
  *(undefined8 *)(puVar7 + -8) = 0x1c00100ac;
  KeReleaseSpinLock(lVar4 + 8,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar2));
  if (param_3 == '\0') {
    uVar2 = *(undefined1 *)(param_1 + 0x68);
    *(undefined8 *)(puVar7 + -8) = 0x1c00100c4;
    KeReleaseSpinLock(param_1 + 0x60,uVar2);
  }
  return uVar8;
}



===== CallDisconnectFromCtl @ 1c00100f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CallDisconnectFromCtl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  undefined1 uVar8;
  
  bVar7 = false;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
  *(undefined1 *)(param_1 + 0x68) = uVar8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x38) + 8);
  *(undefined1 *)(*(longlong *)(param_1 + 0x38) + 0x10) = uVar8;
  if (((param_2 != 0) && (*(int *)(param_2 + 0x20) == 0x54505450)) &&
     (*(longlong *)(param_1 + 0x50) == param_2)) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    plVar1 = (longlong *)(param_1 + 0x10);
    lVar4 = *plVar1;
    if ((*(longlong **)(lVar4 + 8) != plVar1) ||
       (plVar5 = *(longlong **)(param_1 + 0x18), (longlong *)*plVar5 != plVar1)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar5 = lVar4;
    bVar7 = true;
    *(longlong **)(lVar4 + 8) = plVar5;
  }
  lVar4 = *(longlong *)(param_1 + 0x38);
  KeReleaseSpinLock(lVar4 + 8,CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(lVar4 + 0x10)))
  ;
  KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
  if (bVar7) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    }
    LOCK();
    piVar2 = (int *)(param_2 + 0x10);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (**(code **)(param_2 + 0x18))(param_2);
    }
  }
  return;
}



===== CallEventCallClearRequest @ 1c0010248 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CallEventCallClearRequest(int *param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  ushort *puVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined1 auStackY_b8 [32];
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  iVar1 = 0;
  puVar5 = (undefined *)0x41;
  memset(local_78,0,0x41);
  puVar2 = (ushort *)CtlAllocPacket(*(longlong *)(param_1 + 0x14),0xd);
  if (puVar2 != (ushort *)0x0) {
    puVar2[6] = *(ushort *)(param_1 + 0x50) >> 8 | *(ushort *)(param_1 + 0x50) << 8;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      iVar1 = param_1[0x50];
      pcVar3 = (char *)GetStringFromSockAddr((short *)(param_3 + 0x170),local_78);
      puVar5 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                  &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar3,(char)param_1,
                  (char)param_1[0x32],(char)iVar1);
    }
    iVar1 = CtlSend(param_3,puVar2,puVar5);
  }
  uVar4 = 0xb;
  CallSetState((longlong)param_1,0xb,puVar5,'\0');
  CallCleanup(param_1,uVar4,puVar5);
  return iVar1;
}



===== CallEventCallDisconnectNotify @ 1c0010364 =====

undefined8 CallEventCallDisconnectNotify(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  if ((param_1 != (int *)0x0) && (param_1[0xc] == 0x43505450)) {
    piVar1 = param_1 + 0x18;
    uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
    *(undefined1 *)(param_1 + 0x1a) = uVar3;
    if (param_1[0x1c] == 5) {
      KeReleaseSpinLock(piVar1,uVar3);
    }
    else {
      uVar2 = param_1[0x6a];
      uVar4 = 0;
      param_1[0x6a] = uVar2 & 0xffffffdf;
      CallSetState((longlong)param_1,0xb,param_3,'\x01');
      uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),(char)param_1[0x1a]);
      KeReleaseSpinLock(piVar1);
      CallCleanup(param_1,uVar4,param_3);
      if ((uVar2 & 0x20) != 0) {
        DereferenceRefCount(param_1 + 8);
      }
    }
  }
  return 0;
}



===== CallEventCallInConnect @ 1c001041c =====

undefined8 CallEventCallInConnect(int *param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  
  piVar1 = param_1 + 0x18;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_1 + 0x1a) = uVar3;
  if ((((*(longlong *)(param_1 + 0x3a) == 0) || ((param_1[0x6a] & 0x20000U) != 0)) ||
      (*(ushort *)(param_1 + 0x50) !=
       (ushort)(*(ushort *)(param_2 + 0xc) >> 8 | *(ushort *)(param_2 + 0xc) << 8))) ||
     (param_1[0x1c] != 6)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(ushort *)(param_1 + 0x4f),
                  (ulonglong)*(ushort *)(param_1 + 0x50),param_1[0x32],
                  (char)*(ushort *)(param_1 + 0x50),(char)*(ushort *)(param_1 + 0x4f),
                  (char)param_1[0x1c]);
    }
    KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x10);
    param_1[0x6c] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    CallSetState((longlong)param_1,9,param_3,'\x01');
    param_1[0x6a] = param_1[0x6a] | 0x20000;
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
    iVar4 = NdisMCmActivateVc(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x3a));
    if (iVar4 != 0x103) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      PptpCmActivateVcComplete(iVar4,param_1,*(undefined **)(param_1 + 0x3a));
    }
  }
  return 0;
}



===== CallEventCallInRequest @ 1c00105a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CallEventCallInRequest(undefined8 *param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  int *piVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  char *pcVar10;
  ushort *puVar11;
  STRSAFE_LPCSTR pszSrc;
  undefined *puVar12;
  undefined1 auStackY_c8 [32];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar8 = 0;
  puVar12 = (undefined *)0x41;
  memset(local_88,0,0x41);
  uVar5 = *(ushort *)(param_3 + 0xc) >> 8 | *(ushort *)(param_3 + 0xc) << 8;
  uVar9 = (ulonglong)uVar5;
  piVar7 = (int *)FindExistingCallInCtl(param_2,(uint)uVar5);
  if ((piVar7 == (int *)0x0) || (piVar7[0xc] != 0x43505450)) {
    piVar7 = CallFindAndLock(param_1,uVar9,(uint)puVar12);
    if (piVar7 == (int *)0x0) {
      puVar11 = (ushort *)CtlAllocPacket(param_2,10);
      if (puVar11 != (ushort *)0x0) {
        puVar11[7] = *(ushort *)(param_3 + 0xc);
        puVar11[8] = 0x402;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar10 = (char *)GetStringFromSockAddr((short *)(param_2 + 0x170),local_88);
          puVar12 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                    &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar10,(char)param_2);
        }
        uVar6 = CtlSend(param_2,puVar11,puVar12);
        uVar8 = (ulonglong)uVar6;
      }
    }
    else {
      *(undefined1 *)(piVar7 + 0x30) = 1;
      piVar2 = piVar7 + 0x46;
      *(ushort *)(piVar7 + 0x4f) = *(ushort *)(param_3 + 0xc) >> 8 | *(ushort *)(param_3 + 0xc) << 8
      ;
      uVar3 = *(undefined8 *)(param_2 + 0x178);
      *(undefined8 *)piVar2 = *(undefined8 *)(param_2 + 0x170);
      *(undefined8 *)(piVar7 + 0x48) = uVar3;
      *(undefined8 *)(piVar7 + 0x4a) = *(undefined8 *)(param_2 + 0x180);
      piVar7[0x4c] = *(int *)(param_2 + 0x188);
      *(undefined2 *)((longlong)piVar7 + 0x11a) = 0x2f00;
      *(ushort *)(piVar7 + 0x36) = *(ushort *)(param_3 + 0xe) >> 8 | *(ushort *)(param_3 + 0xe) << 8
      ;
      CallConnectToCtl((longlong)piVar7,param_2,'\x01');
      pszSrc = (STRSAFE_LPCSTR)(param_3 + 0x5c);
      *(undefined1 *)(param_3 + 0x9b) = 0;
      StringCbCopyA((STRSAFE_LPSTR)(piVar7 + 0x53),0x41,pszSrc);
      LOCK();
      *piVar7 = *piVar7 + 1;
      UNLOCK();
      DereferenceRefCount(piVar7);
      CallSetState((longlong)piVar7,5,pszSrc,'\x01');
      piVar1 = piVar7 + 0x18;
      piVar7[0x6a] = piVar7[0x6a] | 0x100;
      piVar7[0x1d] = 1;
      KeReleaseSpinLock(piVar1,(char)piVar7[0x1a]);
      uVar9 = ScheduleWorkItem(CallpNewIncomingConnection,piVar7,0,0);
      uVar8 = uVar9 & 0xffffffff;
      if ((int)uVar9 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar12 = WPP_GLOBAL_Control;
          pcVar10 = (char *)GetStringFromSockAddr((short *)piVar2,local_88);
          WPP_SF_sqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar9 + 0x38,puVar12,pcVar10
                      ,(char)piVar7,(char)piVar7[0x32],(char)param_2);
        }
      }
      else {
        _DAT_1c000c480 = _DAT_1c000c480 + 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          pcVar10 = (char *)GetStringFromSockAddr((short *)piVar2,local_88);
          WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                    &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar10,(char)piVar7);
        }
        uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
        piVar7[0x6a] = piVar7[0x6a] & 0xfffffeff;
        *(undefined1 *)(piVar7 + 0x1a) = uVar4;
        CallDetachFromAdapter((longlong)piVar7);
        KeReleaseSpinLock(piVar1,(char)piVar7[0x1a]);
        CallDisconnectFromCtl((longlong)piVar7,param_2);
        DereferenceRefCount(piVar7);
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,(uint)uVar5);
    }
    DereferenceRefCount(piVar7);
    uVar8 = 0;
  }
  return uVar8;
}



===== CallEventCallOutReply @ 1c001090c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CallEventCallOutReply(int *param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined1 auStackY_b8 [32];
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  iVar4 = 0;
  puVar7 = (undefined *)0x41;
  memset(local_78,0,0x41);
  piVar1 = param_1 + 0x18;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_1 + 0x1a) = uVar3;
  if (((*(char *)(param_2 + 0x10) == '\x01') && (param_1[0x1c] == 8)) &&
     (*(ushort *)(param_1 + 0x50) ==
      (ushort)(*(ushort *)(param_2 + 0xe) >> 8 | *(ushort *)(param_2 + 0xe) << 8))) {
    *(ushort *)(param_1 + 0x4f) = *(ushort *)(param_2 + 0xc) >> 8 | *(ushort *)(param_2 + 0xc) << 8;
    iVar2 = *(int *)(*(longlong *)(param_1 + 0x14) + 0x290);
    param_1[0x94] = 0;
    param_1[0x6c] = iVar2;
    CallSetState((longlong)param_1,9,puVar7,'\x01');
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      iVar2 = param_1[0x4f];
      pcVar5 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x46),local_78);
      puVar7 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                  &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar5,(char)param_1,
                  (char)param_1[0x32],(char)iVar2);
    }
  }
  else {
    iVar4 = -0x3fffffff;
    param_1[0x94] = -0x3fffffff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,puVar7,param_1,(char)param_1[0x32],
                 (char)param_1[0x1c]);
    }
  }
  KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
  if (iVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      pcVar5 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x46),local_78);
      puVar7 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar5);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
    param_1[0x6a] = param_1[0x6a] | 0x20000;
    *(undefined1 *)(param_1 + 0x1a) = uVar3;
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
    iVar4 = NdisMCmActivateVc(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x3a));
    if (iVar4 != 0x103) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        pcVar5 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x46),local_78);
        WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,puVar7,pcVar5,(char)iVar4);
      }
      PptpCmActivateVcComplete(iVar4,param_1,*(undefined **)(param_1 + 0x3a));
    }
  }
  else {
    uVar6 = 0xb;
    CallSetState((longlong)param_1,0xb,puVar7,'\0');
    CallCleanup(param_1,uVar6,puVar7);
  }
  return iVar4;
}



===== CallEventCallOutRequest @ 1c0010bd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CallEventCallOutRequest(undefined8 *param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  ushort uVar7;
  uint uVar8;
  int *piVar9;
  ulonglong uVar10;
  longlong lVar12;
  longlong lVar11;
  ulonglong uVar13;
  char *pcVar14;
  ushort *puVar15;
  undefined *puVar16;
  undefined8 uVar17;
  undefined1 auStackY_158 [32];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  uVar10 = 0;
  puVar16 = (undefined *)0x41;
  memset(local_98,0,0x41);
  uVar7 = *(ushort *)(param_3 + 0xc) >> 8 | *(ushort *)(param_3 + 0xc) << 8;
  uVar13 = (ulonglong)uVar7;
  piVar9 = (int *)FindExistingCallInCtl(param_2,(uint)uVar7);
  if ((piVar9 == (int *)0x0) || (piVar9[0xc] != 0x43505450)) {
    piVar9 = CallFindAndLock(param_1,uVar13,(uint)puVar16);
    if (piVar9 == (int *)0x0) {
      puVar15 = (ushort *)CtlAllocPacket(param_2,8);
      if (puVar15 != (ushort *)0x0) {
        puVar15[7] = *(ushort *)(param_3 + 0xc);
        puVar15[8] = 0x402;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar14 = (char *)GetStringFromSockAddr((short *)(param_2 + 0x170),local_98);
          puVar16 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                    &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar14,(char)param_2);
        }
        uVar8 = CtlSend(param_2,puVar15,puVar16);
        uVar10 = (ulonglong)uVar8;
      }
    }
    else {
      *(undefined1 *)(piVar9 + 0x30) = 1;
      *(ushort *)(piVar9 + 0x4f) = *(ushort *)(param_3 + 0xc) >> 8 | *(ushort *)(param_3 + 0xc) << 8
      ;
      iVar3 = *(int *)(param_2 + 0x174);
      iVar4 = *(int *)(param_2 + 0x178);
      iVar5 = *(int *)(param_2 + 0x17c);
      piVar9[0x46] = *(int *)(param_2 + 0x170);
      piVar9[0x47] = iVar3;
      piVar9[0x48] = iVar4;
      piVar9[0x49] = iVar5;
      *(undefined8 *)(piVar9 + 0x4a) = *(undefined8 *)(param_2 + 0x180);
      piVar9[0x4c] = *(int *)(param_2 + 0x188);
      *(undefined2 *)((longlong)piVar9 + 0x11a) = 0x2f00;
      *(ushort *)(piVar9 + 0x36) = *(ushort *)(param_3 + 0xe) >> 8 | *(ushort *)(param_3 + 0xe) << 8
      ;
      if (*(short *)(param_2 + 0x170) == 2) {
        RtlIpv4AddressToStringA(param_2 + 0x174);
      }
      else {
        RtlIpv6AddressToStringA(param_2 + 0x178,piVar9 + 0x53);
      }
      uVar17 = *(undefined8 *)(param_3 + 0x70);
      *(undefined8 *)((longlong)piVar9 + 0x18d) = *(undefined8 *)(param_3 + 0x68);
      *(undefined8 *)((longlong)piVar9 + 0x195) = uVar17;
      *(undefined1 *)((longlong)piVar9 + 0x19d) = 0;
      lVar12 = -1;
      do {
        lVar11 = lVar12 + 1;
        lVar2 = lVar12 + 0x18e;
        lVar12 = lVar11;
      } while (*(char *)(lVar2 + (longlong)piVar9) != '\0');
      if (lVar11 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar16 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                  &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
        }
      }
      else if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar16 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_DDDDDDDDDDDDDDDD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                     &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,
                     (uint)*(byte *)((longlong)piVar9 + 0x18d),
                     *(undefined1 *)((longlong)piVar9 + 0x18e),
                     *(undefined1 *)((longlong)piVar9 + 399),(char)piVar9[100],
                     *(undefined1 *)((longlong)piVar9 + 0x191),
                     *(undefined1 *)((longlong)piVar9 + 0x192),
                     *(undefined1 *)((longlong)piVar9 + 0x193),(char)piVar9[0x65],
                     *(undefined1 *)((longlong)piVar9 + 0x195),
                     *(undefined1 *)((longlong)piVar9 + 0x196),
                     *(undefined1 *)((longlong)piVar9 + 0x197),(char)piVar9[0x66],
                     *(undefined1 *)((longlong)piVar9 + 0x199),
                     *(undefined1 *)((longlong)piVar9 + 0x19a),
                     *(undefined1 *)((longlong)piVar9 + 0x19b),(char)piVar9[0x67]);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar16 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_DDDDDDDDDDDDDDDD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                     &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,(uint)*(byte *)(piVar9 + 100),
                     *(undefined1 *)((longlong)piVar9 + 399),
                     *(undefined1 *)((longlong)piVar9 + 0x18e),
                     *(undefined1 *)((longlong)piVar9 + 0x18d),
                     *(undefined1 *)((longlong)piVar9 + 0x192),
                     *(undefined1 *)((longlong)piVar9 + 0x191),(char)piVar9[0x65],
                     *(undefined1 *)((longlong)piVar9 + 0x193),
                     *(undefined1 *)((longlong)piVar9 + 0x195),
                     *(undefined1 *)((longlong)piVar9 + 0x196),
                     *(undefined1 *)((longlong)piVar9 + 0x197),(char)piVar9[0x66],
                     *(undefined1 *)((longlong)piVar9 + 0x199),
                     *(undefined1 *)((longlong)piVar9 + 0x19a),
                     *(undefined1 *)((longlong)piVar9 + 0x19b),(char)piVar9[0x67]);
        }
      }
      uVar17 = CONCAT71((int7)((ulonglong)puVar16 >> 8),1);
      CallConnectToCtl((longlong)piVar9,param_2,'\x01');
      LOCK();
      *piVar9 = *piVar9 + 1;
      UNLOCK();
      DereferenceRefCount(piVar9);
      CallSetState((longlong)piVar9,4,uVar17,'\x01');
      piVar1 = piVar9 + 0x18;
      piVar9[0x6a] = piVar9[0x6a] | 0x100;
      piVar9[0x1d] = 2;
      KeReleaseSpinLock(piVar1,(char)piVar9[0x1a]);
      uVar17 = 0;
      uVar13 = ScheduleWorkItem(CallpNewIncomingConnection,piVar9,0,0);
      uVar10 = uVar13 & 0xffffffff;
      if ((int)uVar13 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar14 = (char *)GetStringFromSockAddr((short *)(piVar9 + 0x46),local_98);
          WPP_SF_sqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,uVar17,pcVar14,(char)piVar9,
                      (char)piVar9[0x32],(char)param_2);
        }
      }
      else {
        _DAT_1c000c480 = _DAT_1c000c480 + 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          pcVar14 = (char *)GetStringFromSockAddr((short *)(piVar9 + 0x46),local_98);
          WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                    &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar14,(char)piVar9);
        }
        uVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
        piVar9[0x6a] = piVar9[0x6a] & 0xfffffeff;
        *(undefined1 *)(piVar9 + 0x1a) = uVar6;
        CallDetachFromAdapter((longlong)piVar9);
        KeReleaseSpinLock(piVar1,(char)piVar9[0x1a]);
        CallDisconnectFromCtl((longlong)piVar9,param_2);
        DereferenceRefCount(piVar9);
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,(uint)uVar7);
    }
    DereferenceRefCount(piVar9);
    uVar10 = 0;
  }
  return uVar10;
}



===== CallEventConnectFailure @ 1c001128c =====

undefined8 CallEventConnectFailure(int *param_1,int param_2,undefined *param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x1a) = uVar1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,param_3,param_1[0x32],(char)param_2);
  }
  param_1[0x94] = param_2;
  KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
  uVar2 = 0xb;
  CallSetState((longlong)param_1,0xb,param_3,'\0');
  CallCleanup(param_1,uVar2,param_3);
  return 0;
}



===== CallEventOutboundTunnelEstablished @ 1c0011338 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CallEventOutboundTunnelEstablished(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  ushort *puVar5;
  longlong lVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  longlong lVar12;
  undefined *puVar13;
  int *piVar14;
  bool bVar15;
  undefined1 auStackY_158 [32];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_158;
  puVar13 = (undefined *)0x41;
  memset(local_88,0,0x41);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    iVar3 = param_1[0x30];
    pcVar4 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x46),local_88);
    WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,puVar13,pcVar4,(char)iVar3);
  }
  piVar14 = param_1 + 0x18;
  uVar1 = KeAcquireSpinLockRaiseToDpc(piVar14);
  *(undefined1 *)(param_1 + 0x1a) = uVar1;
  if (((char)param_1[0x30] != '\0') || (param_1[0x1c] != 7)) {
    KeReleaseSpinLock(piVar14,uVar1);
    return 0;
  }
  puVar5 = (ushort *)CtlAllocPacket(*(longlong *)(param_1 + 0x14),7);
  if (puVar5 == (ushort *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
       ) {
      puVar13 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    uVar10 = 0;
    CallSetState((longlong)param_1,0xb,puVar13,'\x01');
    uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),(char)param_1[0x1a]);
    KeReleaseSpinLock(piVar14);
    CallCleanup(param_1,uVar10,puVar13);
    return -0x3fffff66;
  }
  CallSetState((longlong)param_1,8,puVar13,'\x01');
  param_1[0x1d] = 2;
  cVar2 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x80));
  LOCK();
  UNLOCK();
  sVar7 = (short)g_CallSerialNumber + 1;
  bVar15 = PptpClientSide == '\0';
  g_CallSerialNumber = g_CallSerialNumber + 1;
  *(short *)(param_1 + 0x36) = sVar7;
  if (bVar15) {
    uVar9 = *(ushort *)(param_1 + 0x34);
  }
  else {
    uVar8 = sVar7 * 0x4000 + (short)param_1[0x32];
    uVar9 = uVar8 + 0x4000;
    if (*(ushort *)(param_1 + 0x50) != uVar8) {
      uVar9 = uVar8;
    }
  }
  *(ushort *)(param_1 + 0x50) = uVar9;
  puVar5[6] = uVar9 >> 8 | uVar9 << 8;
  puVar5[7] = *(ushort *)(param_1 + 0x36) >> 8 | *(ushort *)(param_1 + 0x36) << 8;
  lVar12 = -1;
  puVar5[0x10] = 0x4000;
  puVar5[0x11] = 0;
  puVar5[0xc] = 0;
  puVar5[0xd] = 0x300;
  piVar14 = param_1 + 0x53;
  puVar5[0xe] = 0;
  puVar5[0xf] = 0x300;
  lVar6 = -1;
  puVar5[8] = 0;
  puVar5[9] = 0x2c01;
  puVar5[10] = 0xf505;
  puVar5[0xb] = 0xe1;
  do {
    lVar6 = lVar6 + 1;
  } while (*(STRSAFE_LPCSTR)((longlong)piVar14 + lVar6) != '\0');
  puVar5[0x12] = (ushort)lVar6 >> 8 | (ushort)lVar6 << 8;
  StringCbCopyA((STRSAFE_LPSTR)(puVar5 + 0x14),0x40,(STRSAFE_LPCSTR)piVar14);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    piVar14 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,
             (char *)(*(longlong *)(param_1 + 0x14) + 0x1d8));
  }
  do {
    lVar6 = lVar12;
    lVar12 = lVar6 + 1;
  } while (*(char *)(lVar6 + 0x18e + (longlong)param_1) != '\0');
  if (lVar6 + 1 == 0x10) {
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x14) + 0x1d8) + -0x666f736f7263694d;
    if (lVar12 == 0) {
      lVar12 = (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x14) + 0x1e0) -
               (ulonglong)((int)lVar6 + 0x65U & 0xffff);
    }
    if (lVar12 == 0) {
      uVar10 = *(undefined8 *)((longlong)param_1 + 0x195);
      *(undefined8 *)(puVar5 + 0x34) = *(undefined8 *)((longlong)param_1 + 0x18d);
      *(undefined8 *)(puVar5 + 0x38) = uVar10;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          piVar14 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_DDDDDDDDDDDDDDDD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                     &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,(uint)*(byte *)(param_1 + 100)
                     ,*(undefined1 *)((longlong)param_1 + 399),
                     *(undefined1 *)((longlong)param_1 + 0x18e),
                     *(undefined1 *)((longlong)param_1 + 0x18d),
                     *(undefined1 *)((longlong)param_1 + 0x192),
                     *(undefined1 *)((longlong)param_1 + 0x191),(char)param_1[0x65],
                     *(undefined1 *)((longlong)param_1 + 0x193),
                     *(undefined1 *)((longlong)param_1 + 0x195),
                     *(undefined1 *)((longlong)param_1 + 0x196),
                     *(undefined1 *)((longlong)param_1 + 0x197),(char)param_1[0x66],
                     *(undefined1 *)((longlong)param_1 + 0x199),
                     *(undefined1 *)((longlong)param_1 + 0x19a),
                     *(undefined1 *)((longlong)param_1 + 0x19b),(char)param_1[0x67]);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          piVar14 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
          WPP_SF_DDDDDDDDDDDDDDDD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                     &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,
                     (uint)*(byte *)((longlong)param_1 + 0x18d),
                     *(undefined1 *)((longlong)param_1 + 0x18e),
                     *(undefined1 *)((longlong)param_1 + 399),(char)param_1[100],
                     *(undefined1 *)((longlong)param_1 + 0x191),
                     *(undefined1 *)((longlong)param_1 + 0x192),
                     *(undefined1 *)((longlong)param_1 + 0x193),(char)param_1[0x65],
                     *(undefined1 *)((longlong)param_1 + 0x195),
                     *(undefined1 *)((longlong)param_1 + 0x196),
                     *(undefined1 *)((longlong)param_1 + 0x197),(char)param_1[0x66],
                     *(undefined1 *)((longlong)param_1 + 0x199),
                     *(undefined1 *)((longlong)param_1 + 0x19a),
                     *(undefined1 *)((longlong)param_1 + 0x19b),(char)param_1[0x67]);
        }
      }
      goto LAB_1c00118c7;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    piVar14 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
LAB_1c00118c7:
  KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    iVar3 = param_1[0x50];
    puVar11 = local_88;
    pcVar4 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x46),puVar11);
    WPP_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar11,piVar14,pcVar4,(char)param_1[0x32]
               ,(char)iVar3);
  }
  iVar3 = CtlSend(*(longlong *)(param_1 + 0x14),puVar5,piVar14);
  if ((iVar3 != 0x103) && (iVar3 != 0)) {
    uVar10 = 0xb;
    CallSetState((longlong)param_1,0xb,piVar14,'\0');
    CallCleanup(param_1,uVar10,(undefined *)piVar14);
  }
  if (cVar2 != '\0') {
    DereferenceRefCount(param_1);
  }
  return iVar3;
}



===== CallFlushRxNBLQueue @ 1c00119cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CallFlushRxNBLQueue(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  lVar1 = param_1 + 0xa8;
  while( true ) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0xb0) = uVar4;
    puVar3 = *(undefined8 **)(param_1 + 0x98);
    if (puVar3 == (undefined8 *)0x0) break;
    *(undefined8 *)(param_1 + 0x98) = *puVar3;
    *puVar3 = 0;
    if (*(longlong *)(param_1 + 0x98) == 0) {
      *(undefined8 *)(param_1 + 0xa0) = 0;
    }
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0xb0));
    lVar2 = *(longlong *)((ulonglong)*(ushort *)(puVar3[2] + 10) + 0x20 + puVar3[2]);
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
    *(undefined1 *)(param_1 + 0x68) = uVar4;
    KeReleaseSpinLock(param_1 + 0x60,uVar4);
    LOCK();
    _DAT_1c000c40c = _DAT_1c000c40c + 1;
    UNLOCK();
    LOCK();
    *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + 1;
    UNLOCK();
    DereferenceRefCount((int *)(param_1 + 0x20));
    ReceiveDataComplete(lVar2,(longlong)puVar3);
  }
  KeReleaseSpinLock(lVar1,uVar4);
  return;
}



===== CallFlushTxNBLQueue @ 1c0011b10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CallFlushTxNBLQueue(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  bool bVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  lVar2 = param_1 + 0x88;
LAB_1c0011c42:
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
  *(undefined1 *)(param_1 + 0x90) = uVar5;
  puVar4 = *(undefined8 **)(param_1 + 0x78);
  if (puVar4 == (undefined8 *)0x0) {
    KeReleaseSpinLock(lVar2,uVar5);
    return;
  }
  *(undefined8 *)(param_1 + 0x78) = *puVar4;
  *puVar4 = 0;
  if (*(longlong *)(param_1 + 0x78) == 0) {
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  KeReleaseSpinLock(lVar2,*(undefined1 *)(param_1 + 0x90));
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
  *(undefined1 *)(param_1 + 0x68) = uVar5;
  *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) - *(int *)(puVar4 + 0xc);
  bVar6 = puVar4 == *(undefined8 **)(param_1 + 0x1e0);
  if (bVar6) {
    *(undefined1 *)(param_1 + 0x1d0) = 0;
  }
  KeReleaseSpinLock(param_1 + 0x60,uVar5);
  if (!bVar6) goto code_r0x0001c0011be5;
  goto LAB_1c0011c39;
code_r0x0001c0011be5:
  LOCK();
  piVar1 = (int *)(puVar4 + 0xe);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    *(undefined4 *)((longlong)puVar4 + 0x8c) = 0xc0000001;
    LOCK();
    _DAT_1c000c408 = _DAT_1c000c408 + *(int *)(puVar4 + 0xc);
    UNLOCK();
    LOCK();
    *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + *(int *)(puVar4 + 0xc);
    UNLOCK();
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0xe0),puVar4,0);
    DereferenceRefCount((int *)(*(longlong *)(param_1 + 0x38) + 0xc0));
LAB_1c0011c39:
    DereferenceRefCount((int *)(param_1 + 0x20));
  }
  goto LAB_1c0011c42;
}



===== CallSetLinkInfo @ 1c0011c98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CallSetLinkInfo(longlong param_1,undefined4 *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int iVar7;
  ushort *puVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined1 auStack_88 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  puVar10 = (undefined *)0x41;
  memset(local_68,0,0x41);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    puVar10 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
  *(undefined1 *)(param_1 + 0x68) = uVar6;
  if (*(int *)(param_1 + 0x70) == 9) {
    uVar3 = param_2[1];
    uVar4 = param_2[2];
    uVar5 = param_2[3];
    *(undefined4 *)(param_1 + 0xf0) = *param_2;
    *(undefined4 *)(param_1 + 0xf4) = uVar3;
    *(undefined4 *)(param_1 + 0xf8) = uVar4;
    *(undefined4 *)(param_1 + 0xfc) = uVar5;
    uVar3 = param_2[5];
    uVar4 = param_2[6];
    uVar5 = param_2[7];
    lVar2 = *(longlong *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x100) = param_2[4];
    *(undefined4 *)(param_1 + 0x104) = uVar3;
    *(undefined4 *)(param_1 + 0x108) = uVar4;
    *(undefined4 *)(param_1 + 0x10c) = uVar5;
    KeReleaseSpinLock(param_1 + 0x60,uVar6);
    puVar8 = (ushort *)CtlAllocPacket(lVar2,0xf);
    if (puVar8 == (ushort *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      iVar7 = -0x3fffff66;
    }
    else {
      puVar8[6] = *(ushort *)(param_1 + 0x13c) >> 8 | *(ushort *)(param_1 + 0x13c) << 8;
      uVar1 = *(uint *)(param_1 + 0x108);
      *(uint *)(puVar8 + 8) =
           uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = *(uint *)(param_1 + 0x10c);
      *(uint *)(puVar8 + 10) =
           uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar9 = (char *)GetStringFromSockAddr((short *)(lVar2 + 0x170),local_68);
        puVar10 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                 &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar9);
      }
      iVar7 = CtlSend(lVar2,puVar8,puVar10);
    }
  }
  else {
    iVar7 = -0x3fffffff;
    KeReleaseSpinLock();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    }
  }
  return iVar7;
}



===== CallpAckTimeout @ 1c0011ea0 =====

void CallpAckTimeout(undefined8 param_1,int *param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,(char)param_2[0x32]);
  }
  uVar2 = CallQueueTransmitNBLs(param_2,*(undefined8 **)(param_2 + 0x78));
  if ((int)uVar2 != 0x103) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x18);
    *(undefined1 *)(param_2 + 0x74) = 0;
    *(undefined1 *)(param_2 + 0x1a) = uVar1;
    KeReleaseSpinLock(param_2 + 0x18,uVar1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,(char)param_2[0x32]);
    }
  }
  DereferenceRefCount(param_2);
  return;
}



===== CallpCloseTimeout @ 1c0011f90 =====

void CallpCloseTimeout(undefined8 param_1,int *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined *puVar5;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x18);
  uVar1 = param_2[0x6a];
  *(undefined1 *)(param_2 + 0x1a) = uVar2;
  uVar4 = uVar1 & 0xffffffdf;
  puVar5 = (undefined *)(ulonglong)uVar4;
  param_2[0x6a] = uVar4;
  KeReleaseSpinLock(param_2 + 0x18,uVar2);
  uVar3 = 0xb;
  CallSetState((longlong)param_2,0xb,puVar5,'\0');
  CallCleanup(param_2,uVar3,puVar5);
  if ((uVar1 & 0x20) != 0) {
    DereferenceRefCount(param_2 + 8);
  }
  DereferenceRefCount(param_2);
  return;
}



===== CallpDialTimeout @ 1c0012020 =====

void CallpDialTimeout(undefined8 param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_2,(char)param_2[0x32]);
  }
  piVar1 = param_2 + 0x18;
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_2 + 0x1a) = uVar2;
  if (param_2[0x1c] == 7) {
    uVar3 = 0;
    CallSetState((longlong)param_2,0xb,param_3,'\x01');
    uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),(char)param_2[0x1a]);
    KeReleaseSpinLock(piVar1);
    CallCleanup(param_2,uVar3,param_3);
  }
  else {
    KeReleaseSpinLock(piVar1,uVar2);
  }
  DereferenceRefCount(param_2);
  return;
}



===== CallpNewIncomingConnection @ 1c00120f0 =====

void CallpNewIncomingConnection(longlong param_1,undefined8 param_2,int *param_3)

{
  longlong *plVar1;
  int *piVar2;
  int *piVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 uVar6;
  bool bVar7;
  int iVar8;
  int *piVar9;
  undefined2 uVar10;
  undefined8 uVar11;
  longlong lVar12;
  
  piVar3 = *(int **)(param_1 + 0x18);
  iVar8 = -0x3fffffff;
  bVar5 = true;
  plVar4 = *(longlong **)(piVar3 + 0xe);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  if ((((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (*(undefined1 *)((longlong)piVar3 + 0xc2) = 1,
     (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,piVar3);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,piVar3);
    }
  }
  plVar1 = plVar4 + 1;
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
  *(undefined1 *)(plVar4 + 2) = uVar6;
  if ((plVar4[0x13] == 0) || (*plVar4 == 0)) {
    KeReleaseSpinLock(plVar1,uVar6);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0 || (WPP_GLOBAL_Control[0x29] == '\0'))))
    goto LAB_1c001248e;
    uVar10 = 0x2c;
  }
  else {
    KeReleaseSpinLock(plVar1,uVar6);
    piVar2 = piVar3 + 0x18;
    uVar6 = KeAcquireSpinLockRaiseToDpc(piVar2);
    *(undefined1 *)(piVar3 + 0x1a) = uVar6;
    if (1 < piVar3[0x1c] - 4U) {
      KeReleaseSpinLock(piVar2,uVar6);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                  &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,piVar3,1);
      }
      goto LAB_1c001248e;
    }
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
    piVar3[0x6a] = piVar3[0x6a] | 0x40000;
    KeReleaseSpinLock(piVar2,(char)piVar3[0x1a]);
    param_3 = piVar3;
    iVar8 = NdisMCmCreateVc(*plVar4,plVar4[0x13],piVar3,piVar3 + 0x38);
    if (iVar8 != 0) {
      uVar6 = KeAcquireSpinLockRaiseToDpc();
      piVar3[0x6a] = piVar3[0x6a] & 0xfffbffff;
      *(undefined1 *)(piVar3 + 0x1a) = uVar6;
      KeReleaseSpinLock(piVar2,uVar6);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                  &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,piVar3,(char)iVar8);
      }
      DereferenceRefCount(piVar3);
      goto LAB_1c001248e;
    }
    uVar6 = KeAcquireSpinLockRaiseToDpc(piVar2);
    *(undefined1 *)(piVar3 + 0x1a) = uVar6;
    piVar3[0x6a] = piVar3[0x6a] & 0xfffbffffU | 0x102;
    KeReleaseSpinLock(piVar2,uVar6);
    piVar9 = (int *)PptpCmBuildCallParams((longlong)piVar3);
    if (piVar9 != (int *)0x0) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar2);
      *(undefined1 *)(piVar3 + 0x1a) = uVar6;
      *(int **)(piVar3 + 0x3a) = piVar9;
      LOCK();
      *piVar3 = *piVar3 + 1;
      UNLOCK();
      KeReleaseSpinLock(piVar2,(char)piVar3[0x1a]);
      bVar7 = ReferenceSap(*(longlong *)(piVar3 + 0xe));
      if (bVar7) {
        param_3 = piVar9;
        iVar8 = NdisCmDispatchIncomingCall
                          (*(undefined8 *)(*(longlong *)(piVar3 + 0xe) + 0x88),
                           *(undefined8 *)(piVar3 + 0x38));
        bVar5 = false;
        if (iVar8 != 0x103) {
          PptpCmIncomingCallComplete(iVar8,piVar3,(undefined *)piVar9);
          param_3 = piVar9;
        }
        DereferenceSap(*(longlong *)(piVar3 + 0xe));
      }
      else {
        iVar8 = -0x3ffeffe0;
        DereferenceRefCount(piVar3);
      }
      goto LAB_1c001248e;
    }
    iVar8 = -0x3fffffff;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_1c001248e;
    uVar10 = 0x2f;
  }
  iVar8 = -0x3fffffff;
  param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
          &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
LAB_1c001248e:
  uVar6 = KeAcquireSpinLockRaiseToDpc(piVar3 + 0x18);
  *(undefined1 *)(piVar3 + 0x1a) = uVar6;
  if (bVar5) {
    piVar3[0x6a] = piVar3[0x6a] & 0xfffffeff;
  }
  if (iVar8 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      param_3 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar8);
    }
    uVar11 = 0;
    CallSetState((longlong)piVar3,0xb,param_3,'\x01');
    if (piVar3[0x6a] == 0) {
      CallDetachFromAdapter((longlong)piVar3);
      KeReleaseSpinLock(piVar3 + 0x18,(char)piVar3[0x1a]);
      lVar12 = *(longlong *)(piVar3 + 0x14);
      CallDisconnectFromCtl((longlong)piVar3,lVar12);
    }
    else {
      lVar12 = CONCAT71((int7)((ulonglong)uVar11 >> 8),(char)piVar3[0x1a]);
      KeReleaseSpinLock(piVar3 + 0x18);
    }
    CallCleanup(piVar3,lVar12,(undefined *)param_3);
  }
  else {
    KeReleaseSpinLock(piVar3 + 0x18,uVar6);
  }
  DereferenceRefCount(piVar3);
  return;
}



===== CallpSendCallClearReq @ 1c0012588 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CallpSendCallClearReq(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  ushort *puVar5;
  char *pcVar6;
  undefined1 auStackY_c8 [32];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  iVar4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  piVar1 = param_1 + 0x18;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  lVar2 = *(longlong *)(param_1 + 0x14);
  *(undefined1 *)(param_1 + 0x1a) = uVar3;
  if (lVar2 == 0) {
    _DAT_1c000c460 = _DAT_1c000c460 + 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    iVar4 = -0x3fffffff;
    goto LAB_1c00127c6;
  }
  if (param_1[0x1c] != 9) goto LAB_1c00127c6;
  puVar5 = (ushort *)CtlAllocPacket(lVar2,0xc);
  if (puVar5 == (ushort *)0x0) {
    _DAT_1c000c464 = _DAT_1c000c464 + 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    iVar4 = -0x3fffff66;
    goto LAB_1c00127c6;
  }
  CallSetState((longlong)param_1,10,param_3,'\x01');
  puVar5[6] = *(ushort *)(param_1 + 0x50) >> 8 | *(ushort *)(param_1 + 0x50) << 8;
  KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    iVar4 = param_1[0x50];
    pcVar6 = (char *)GetStringFromSockAddr((short *)(lVar2 + 0x170),local_88);
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,pcVar6,(char)param_1,
                (char)param_1[0x32],(char)iVar4);
  }
  iVar4 = CtlSend(lVar2,puVar5,param_3);
  if (iVar4 == 0) {
    iVar4 = 0x103;
LAB_1c0012791:
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    NdisSetTimerObject(*(undefined8 *)(param_1 + 0x68),0xffffffffff676980,0,0);
  }
  else {
    _DAT_1c000c468 = _DAT_1c000c468 + 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1[0x32]);
    }
    if (iVar4 == 0x103) goto LAB_1c0012791;
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_1 + 0x1a) = uVar3;
LAB_1c00127c6:
  KeReleaseSpinLock(piVar1,(char)param_1[0x1a]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar4);
  }
  return iVar4;
}



===== CallpSendCompleteDeferred @ 1c0012840 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CallpSendCompleteDeferred(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_1,lVar1,(char)uVar2,
               (char)*(undefined4 *)(param_1 + 0x28));
  }
  NdisMCoSendNetBufferListsComplete(*(undefined8 *)(lVar1 + 0xe0),uVar2,0);
  LOCK();
  _DAT_1c000c3f4 = _DAT_1c000c3f4 + 1;
  UNLOCK();
  LOCK();
  *(int *)(lVar1 + 0x298) = *(int *)(lVar1 + 0x298) + 1;
  UNLOCK();
  DereferenceRefCount((int *)(*(longlong *)(lVar1 + 0x38) + 0xc0));
  DereferenceRefCount((int *)(lVar1 + 0x20));
  return;
}



===== FindExistingCallInCtl @ 1c00128e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FindExistingCallInCtl(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong local_38 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  if (*(int *)(param_1 + 0x30) == 5) {
    bVar3 = 0;
    plVar6 = (longlong *)0x0;
    local_24 = 0;
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
    local_38[1] = 0;
    local_38[0] = 0;
    local_28 = 0x4d554e45;
    while( true ) {
      plVar4 = EnumListEntry((longlong *)(param_1 + 0x38),local_38,*(longlong *)(param_1 + 0x28) + 8
                             ,0);
      if (plVar4 == (longlong *)0x0) break;
      plVar6 = plVar4 + -2;
      if ((plVar6 != (longlong *)0x0) && ((int)plVar4[4] == 0x43505450)) {
        if ((plVar4[8] == param_1) && (*(ushort *)((longlong)plVar4 + 300) == param_2)) {
          bVar3 = 1;
          break;
        }
        DereferenceRefCount((int *)plVar6);
      }
    }
    EnumComplete(local_38,*(longlong *)(param_1 + 0x28) + 8);
    LOCK();
    piVar1 = (int *)(param_1 + 0x10);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
    uVar5 = -(ulonglong)bVar3 & (ulonglong)plVar6;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



===== CtlAlloc @ 1c00129c8 =====

longlong * CtlAlloc(undefined8 *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  undefined2 uVar4;
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  longlong *local_18;
  
  plVar3 = (longlong *)MyMemAlloc(0x298,0x54505450);
  if (plVar3 == (longlong *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
    return (longlong *)0x0;
  }
  ReferenceAdapter((longlong)param_1);
  *(undefined4 *)(plVar3 + 4) = 0x54505450;
  plVar3[0x47] = (longlong)&DAT_1c000c0e0;
  plVar3[5] = (longlong)param_1;
  ExInitializeRundownProtection(plVar3 + 0xb);
  KeInitializeSpinLock(plVar3 + 0xc);
  plVar1 = plVar3 + 7;
  plVar3[8] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = plVar3 + 0xf;
  plVar3[0x10] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar3[1] = (longlong)plVar3;
  *plVar3 = (longlong)plVar3;
  local_20 = CtlpEchoTimeout;
  local_28 = 0x180197;
  local_24 = 0x544d5450;
  local_18 = plVar3;
  iVar2 = NdisAllocateTimerObject(*param_1,&local_28,plVar3 + 0x48);
  if (iVar2 == 0) {
    local_20 = CtlpWaitTimeout;
    iVar2 = NdisAllocateTimerObject(*param_1,&local_28,plVar3 + 0x4a);
    if (iVar2 == 0) {
      local_20 = CtlpStopTimeout;
      iVar2 = NdisAllocateTimerObject(*param_1,&local_28,plVar3 + 0x4b);
      if (iVar2 == 0) {
        KeInitializeEvent(plVar3 + 0x4c,0,1);
        KeInitializeEvent(plVar3 + 0x4f,0,1);
        *(undefined4 *)(plVar3 + 2) = 1;
        plVar3[3] = (longlong)CtlFree;
        ExInterlockedInsertTailList(param_1 + 5,plVar3,param_1 + 1);
        return plVar3;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_1c0012bac;
      uVar4 = 0xd;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_1c0012bac;
      uVar4 = 0xc;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_1c0012bac;
    uVar4 = 0xb;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
LAB_1c0012bac:
  CtlFree(plVar3);
  return (longlong *)0x0;
}



===== CtlAllocPacket @ 1c0012c28 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * CtlAllocPacket(longlong param_1,int param_2)

{
  undefined1 uVar1;
  longlong *plVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == 0x54505450)) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x68) = uVar1;
    plVar2 = CtlpAllocPacketLocked(param_1,param_2);
    KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
    if (plVar2 != (longlong *)0x0) {
      return plVar2;
    }
  }
  _DAT_1c000c478 = _DAT_1c000c478 + 1;
  return (longlong *)0x0;
}



===== CtlCleanup @ 1c0012cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlCleanup(longlong param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  if (param_2 == '\0') {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x68) = uVar3;
  }
  if (*(char *)(param_1 + 0x70) == '\0') {
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
    *(undefined1 *)(param_1 + 0x70) = 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
    uVar4 = ScheduleWorkItem(CtlpCleanup,param_1,0,0);
    if ((int)uVar4 != 0) {
      *(undefined1 *)(param_1 + 0x70) = 0;
      LOCK();
      piVar1 = (int *)(param_1 + 0x10);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x18))(param_1);
      }
    }
  }
  if (param_2 == '\0') {
    KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
  }
  return;
}



===== CtlConnectCall @ 1c0012db4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CtlConnectCall(undefined8 *param_1,int *param_2,short *param_3,char *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined1 uVar5;
  char cVar6;
  undefined1 uVar7;
  char *pcVar8;
  longlong *plVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined1 *puVar13;
  undefined8 uVar14;
  undefined *puVar15;
  undefined1 auStackY_148 [32];
  int local_114;
  short local_110 [8];
  char **local_100;
  longlong local_f8 [2];
  undefined4 local_e8;
  undefined4 local_e4;
  char *local_e0;
  undefined8 uStack_d8;
  char *local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined1 local_a8 [80];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  bVar4 = false;
  local_114 = 0;
  local_e4 = 0;
  cVar6 = '\0';
  uVar7 = SUB81(param_2,0);
  local_e0 = param_4;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    pcVar8 = (char *)GetStringFromSockAddr(param_3,local_a8);
    WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar8,uVar7);
  }
  local_f8[1] = 0;
  local_f8[0] = 0;
  local_e8 = 0x4d554e45;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
  *(undefined1 *)(param_1 + 2) = uVar5;
  plVar11 = (longlong *)0x0;
  do {
    uVar14 = 0;
    plVar9 = EnumListEntry(param_1 + 5,local_f8,0,1);
    if (plVar9 == (longlong *)0x0) break;
    if (((int)plVar9[6] - 2U < 4) &&
       (uVar10 = CompareSockAddress(param_3,(short *)(plVar9 + 0x2e)), (char)uVar10 != '\0')) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,uVar14,plVar9,uVar7);
      }
      LOCK();
      *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
      UNLOCK();
      KeReleaseSpinLock(param_1 + 1,*(undefined1 *)(param_1 + 2));
      uVar14 = 0;
      cVar6 = CallConnectToCtl((longlong)param_2,(longlong)plVar9,'\0');
      *local_e0 = cVar6;
      if (cVar6 == '\0') {
        LOCK();
        plVar11 = plVar9 + 2;
        lVar12 = *plVar11;
        *(int *)plVar11 = (int)*plVar11 + -1;
        UNLOCK();
        if ((int)lVar12 == 1) {
          (*(code *)plVar9[3])(plVar9);
        }
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
      *(undefined1 *)(param_1 + 2) = uVar5;
      if ((cVar6 != '\0') && ((int)plVar9[6] == 5)) {
        bVar4 = true;
      }
    }
    LOCK();
    plVar11 = plVar9 + 2;
    lVar12 = *plVar11;
    *(int *)plVar11 = (int)*plVar11 + -1;
    UNLOCK();
    if ((int)lVar12 == 1) {
      (*(code *)plVar9[3])(plVar9);
    }
    plVar11 = plVar9;
  } while (cVar6 == '\0');
  EnumComplete(local_f8,0);
  KeReleaseSpinLock(param_1 + 1,*(undefined1 *)(param_1 + 2));
  if (cVar6 == '\0') {
    plVar11 = CtlAlloc(param_1);
    if (plVar11 == (longlong *)0x0) {
      local_114 = -0x3fffff66;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,uVar14,plVar11,uVar7);
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
      *(undefined1 *)(param_1 + 2) = uVar7;
      CtlSetState((longlong)plVar11,2,uVar14,'\x01');
      *(char *)(plVar11 + 9) = (char)param_2[0x30];
      KeReleaseSpinLock(param_1 + 1,*(undefined1 *)(param_1 + 2));
      puVar15 = (undefined *)0x0;
      cVar6 = CallConnectToCtl((longlong)param_2,(longlong)plVar11,'\0');
      *local_e0 = cVar6;
      if (cVar6 == '\0') {
        local_114 = -0x3fffffff;
      }
      else {
        local_110[0] = 1;
        local_110[1] = 0;
        local_c0 = 0;
        puVar15 = (undefined *)0x2;
        local_b8 = 0;
        local_110[4] = 2;
        local_110[5] = 0;
        local_110[6] = 0;
        local_110[7] = 0;
        local_110[2] = 6;
        local_110[3] = 0;
        local_e0 = (char *)0x0;
        uStack_d8 = 0;
        local_100 = &local_d0;
        if (*param_3 == 2) {
          local_100 = &local_e0;
        }
        local_d0 = (char *)0x0;
        uStack_c8 = 0;
        *(short *)local_100 = *param_3;
        param_3[1] = PptpControlPort >> 8 | PptpControlPort << 8;
        lVar12 = WskCreateAndIntializeSockContext();
        if (lVar12 == 0) {
          local_114 = -0x3fffff66;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            puVar15 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                     &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0xc000009a);
          }
        }
        else {
          *(longlong **)(lVar12 + 8) = plVar11;
          *(code **)(lVar12 + 0x18) = CtlDisconnectCallback;
          *(undefined1 *)(lVar12 + 0x38) = 1;
          *(code **)(lVar12 + 0x10) = CtlReceiveCallback;
          *(code **)(lVar12 + 0x40) = CtlpSendMessageComplete;
          puVar15 = (undefined *)0x0;
          *(code **)(lVar12 + 0x28) = CtlConnectCompleteCallback;
          *(undefined8 **)(lVar12 + 0x48) = param_1 + 0xc;
          *(code **)(lVar12 + 0x30) = CtlLogWskLibActivity;
          uVar10 = WskCreateSocket(local_110,param_3,0,lVar12,0);
          local_114 = (int)uVar10;
          if (local_114 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              puVar15 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                       &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,local_114);
            }
            WskDestroySockContext(lVar12);
          }
          else {
            uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11 + 0xc);
            plVar11[0x11] = lVar12;
            *(undefined1 *)(plVar11 + 0xd) = uVar7;
            uVar1 = *(undefined4 *)(param_3 + 2);
            uVar2 = *(undefined4 *)(param_3 + 4);
            uVar3 = *(undefined4 *)(param_3 + 6);
            if (*param_3 == 2) {
              *(undefined4 *)(plVar11 + 0x2e) = *(undefined4 *)param_3;
              *(undefined4 *)((longlong)plVar11 + 0x174) = uVar1;
              *(undefined4 *)(plVar11 + 0x2f) = uVar2;
              *(undefined4 *)((longlong)plVar11 + 0x17c) = uVar3;
            }
            else {
              *(undefined4 *)(plVar11 + 0x2e) = *(undefined4 *)param_3;
              *(undefined4 *)((longlong)plVar11 + 0x174) = uVar1;
              *(undefined4 *)(plVar11 + 0x2f) = uVar2;
              *(undefined4 *)((longlong)plVar11 + 0x17c) = uVar3;
              plVar11[0x30] = *(longlong *)(param_3 + 8);
              *(undefined4 *)(plVar11 + 0x31) = *(undefined4 *)(param_3 + 0xc);
            }
            LOCK();
            *(int *)(plVar11 + 2) = (int)plVar11[2] + 1;
            UNLOCK();
            KeReleaseSpinLock(plVar11 + 0xc,(char)plVar11[0xd]);
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,puVar15,plVar11,
                        (char)plVar11[0x11]);
            }
            if (local_114 == 0) {
              return 0;
            }
            if (local_114 == 0x103) {
              return 0x103;
            }
          }
        }
      }
      if (((int)plVar11[4] == 0x54505450) && (cVar6 == '\0')) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))
           ) {
          puVar13 = local_a8;
          pcVar8 = (char *)GetStringFromSockAddr((short *)(plVar11 + 0x2e),puVar13);
          WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar13,puVar15,pcVar8,
                    (char)local_114);
        }
        CtlSetState((longlong)plVar11,7,puVar15,'\0');
        CtlCleanup((longlong)plVar11,'\0');
      }
    }
  }
  else {
    if (bVar4) {
      CallEventOutboundTunnelEstablished(param_2);
    }
    if (plVar11 != (longlong *)0x0) {
      LOCK();
      plVar9 = plVar11 + 2;
      lVar12 = *plVar9;
      *(int *)plVar9 = (int)*plVar9 + -1;
      UNLOCK();
      if ((int)lVar12 == 1) {
        (*(code *)plVar11[3])(plVar11);
      }
    }
  }
  return local_114;
}



===== CtlConnectCompleteCallback @ 1c00133a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CtlConnectCompleteCallback(longlong param_1,undefined8 param_2,int param_3)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined *puVar11;
  undefined1 auStackY_b8 [32];
  longlong local_80 [2];
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) != 0x54505450)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return -0x3fffffff;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return -0x3fffffff;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
             &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1);
    return -0x3fffffff;
  }
  uVar4 = *(uint *)(param_1 + 0x30);
  puVar11 = (undefined *)(ulonglong)uVar4;
  if (uVar4 == 2) {
    if (param_3 == 0) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x88) = param_2;
      *(undefined1 *)(param_1 + 0x68) = uVar5;
      KeReleaseSpinLock(param_1 + 0x60,uVar5);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar7 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_68);
          WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                    &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar7,(char)param_1);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                  &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
        }
      }
      LOCK();
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      UNLOCK();
      uVar6 = GetLocalAddress(*(longlong *)(param_1 + 0x88),param_1 + 0x218);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,uVar6);
      }
      iVar10 = 0;
      goto LAB_1c0013630;
    }
    local_6c = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      puVar9 = local_68;
      pcVar7 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),puVar9);
      WPP_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar9,puVar11,pcVar7,(char)param_1,
                 (char)param_3);
    }
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
    local_80[1] = 0;
    local_80[0] = 0;
    local_70 = 0x4d554e45;
    while( true ) {
      puVar11 = (undefined *)(*(longlong *)(param_1 + 0x28) + 8);
      plVar8 = EnumListEntry((longlong *)(param_1 + 0x38),local_80,(longlong)puVar11,0);
      if (plVar8 == (longlong *)0x0) break;
      plVar1 = plVar8 + -2;
      if ((plVar1 != (longlong *)0x0) && ((int)plVar8[4] == 0x43505450)) {
        CallEventConnectFailure((int *)plVar1,param_3,puVar11);
        DereferenceRefCount((int *)plVar1);
      }
    }
    EnumComplete(local_80,*(longlong *)(param_1 + 0x28) + 8);
    LOCK();
    piVar2 = (int *)(param_1 + 0x10);
    iVar10 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar10 == 1) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      puVar11 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1,(char)uVar4);
    }
    CtlSetState(param_1,7,puVar11,'\0');
    CtlCleanup(param_1,'\0');
  }
  iVar10 = -0x3fffffff;
LAB_1c0013630:
  LOCK();
  piVar2 = (int *)(param_1 + 0x10);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  if (-1 < iVar10) {
    ScheduleWorkItem(ScheduleAddHostRoute,param_1,0,0);
  }
  return iVar10;
}



===== CtlConnectQueryCallback @ 1c00136e0 =====

undefined8
CtlConnectQueryCallback(undefined8 *param_1,short *param_2,undefined *param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined *puVar7;
  
  uVar6 = 0;
  puVar7 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar7 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  plVar5 = CtlAlloc(param_1);
  if (plVar5 == (longlong *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
    *(undefined1 *)(param_1 + 2) = uVar4;
    CtlSetState((longlong)plVar5,3,puVar7,'\x01');
    *(undefined1 *)(plVar5 + 9) = 1;
    KeReleaseSpinLock(param_1 + 1,*(undefined1 *)(param_1 + 2));
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar5 + 0xc);
    *(undefined1 *)(plVar5 + 0xd) = uVar4;
    plVar5[0x11] = (longlong)param_3;
    uVar1 = *(undefined4 *)(param_2 + 2);
    uVar2 = *(undefined4 *)(param_2 + 4);
    uVar3 = *(undefined4 *)(param_2 + 6);
    if (*param_2 == 2) {
      *(undefined4 *)(plVar5 + 0x2e) = *(undefined4 *)param_2;
      *(undefined4 *)((longlong)plVar5 + 0x174) = uVar1;
      *(undefined4 *)(plVar5 + 0x2f) = uVar2;
      *(undefined4 *)((longlong)plVar5 + 0x17c) = uVar3;
    }
    else {
      *(undefined4 *)(plVar5 + 0x2e) = *(undefined4 *)param_2;
      *(undefined4 *)((longlong)plVar5 + 0x174) = uVar1;
      *(undefined4 *)(plVar5 + 0x2f) = uVar2;
      *(undefined4 *)((longlong)plVar5 + 0x17c) = uVar3;
      plVar5[0x30] = *(longlong *)(param_2 + 8);
      *(undefined4 *)(plVar5 + 0x31) = *(undefined4 *)(param_2 + 0xc);
    }
    KeResetEvent(plVar5 + 0x4c);
    NdisSetTimerObject(plVar5[0x4a],0xffffffffee1e5d00,0,0);
    if (PptpEchoTimeout != 0) {
      NdisSetTimerObject(plVar5[0x48],(ulonglong)(uint)(PptpEchoTimeout * 1000) * -10000,
                         (ulonglong)(uint)(PptpEchoTimeout * 1000),0);
      *(undefined1 *)((longlong)plVar5 + 0x24c) = 1;
    }
    KeReleaseSpinLock(plVar5 + 0xc,(char)plVar5[0xd]);
    *param_4 = plVar5;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,
               *(undefined4 *)((longlong)plVar5 + 0x21c));
    }
  }
  return uVar6;
}



===== CtlDisconnectCall @ 1c00138bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CtlDisconnectCall(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  undefined1 uVar8;
  ushort *puVar9;
  char *pcVar10;
  undefined8 uVar11;
  undefined *puVar12;
  undefined1 auStack_b8 [48];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar4 = *(longlong *)(param_1 + 0x38);
  uVar11 = 0;
  bVar7 = false;
  puVar12 = (undefined *)0x41;
  memset(local_88,0,0x41);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar12 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  lVar1 = param_1 + 0x60;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x68) = uVar8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x38) + 8);
  *(undefined1 *)(*(longlong *)(param_1 + 0x38) + 0x10) = uVar8;
  lVar5 = *(longlong *)(param_1 + 0x50);
  if ((lVar5 == 0) || (*(int *)(lVar5 + 0x20) != 0x54505450)) {
    lVar4 = *(longlong *)(param_1 + 0x38);
    KeReleaseSpinLock(lVar4 + 8,
                      CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(lVar4 + 0x10)));
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x68));
    uVar11 = 0;
  }
  else {
    LOCK();
    *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
    UNLOCK();
    lVar6 = *(longlong *)(param_1 + 0x38);
    KeReleaseSpinLock(lVar6 + 8,
                      CONCAT71((int7)((ulonglong)lVar6 >> 8),*(undefined1 *)(lVar6 + 0x10)));
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x68));
    CallDisconnectFromCtl(param_1,lVar5);
    lVar1 = lVar4 + 8;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(lVar4 + 0x10) = uVar8;
    if (*(longlong **)(lVar5 + 0x38) == (longlong *)(lVar5 + 0x38)) {
      if (*(int *)(lVar5 + 0x30) == 5) {
        if (*(char *)(lVar5 + 0x48) == '\0') {
          CtlSetState(lVar5,6,puVar12,'\x01');
          bVar7 = true;
        }
        else {
          KeResetEvent(lVar5 + 0x278);
          puVar12 = (undefined *)0x0;
          NdisSetTimerObject(*(undefined8 *)(lVar5 + 600),0xffffffffee1e5d00);
        }
      }
      else {
        CtlSetState(lVar5,7,puVar12,'\x01');
        KeReleaseSpinLock(lVar1);
        CtlCleanup(lVar5,'\0');
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
        *(undefined1 *)(lVar4 + 0x10) = uVar8;
      }
    }
    KeReleaseSpinLock(lVar1);
    if (bVar7) {
      puVar9 = (ushort *)CtlAllocPacket(lVar5,3);
      if (puVar9 == (ushort *)0x0) {
        uVar11 = 0xc000009a;
        CtlSetState(lVar5,7,puVar12,'\0');
        CtlCleanup(lVar5,'\0');
      }
      else {
        *(undefined1 *)(puVar9 + 6) = 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar10 = (char *)GetStringFromSockAddr((short *)(lVar5 + 0x170),local_88);
          puVar12 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
          WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                   &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar10);
        }
        CtlSend(lVar5,puVar9,puVar12);
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x60);
        *(undefined1 *)(lVar5 + 0x68) = uVar8;
        KeResetEvent(lVar5 + 0x278);
        NdisSetTimerObject(*(undefined8 *)(lVar5 + 600),0xffffffffee1e5d00,0,0);
        KeReleaseSpinLock(lVar5 + 0x60);
      }
    }
    LOCK();
    piVar2 = (int *)(lVar5 + 0x10);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (**(code **)(lVar5 + 0x18))(lVar5);
    }
  }
  return uVar11;
}



===== CtlDisconnectCallback @ 1c0013c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CtlDisconnectCallback(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 auStackY_a8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar6 = 0;
  uVar7 = 0x41;
  memset(local_68,0,0x41);
  DAT_1c000c4a8 = KeAcquireSpinLockRaiseToDpc(&gCallbackLock);
  lVar2 = *param_1;
  if ((lVar2 == 0) || (*(int *)(lVar2 + 0x20) != 0x54505450)) {
    iVar6 = -0x3ffffff3;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x60);
    *(undefined1 *)(lVar2 + 0x68) = uVar3;
    if (*(char *)(lVar2 + 0x70) == '\0') {
      LOCK();
      *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + 1;
      UNLOCK();
    }
    else {
      iVar6 = -0x3ffffff3;
    }
    KeReleaseSpinLock(lVar2 + 0x60,*(undefined1 *)(lVar2 + 0x68));
    if (iVar6 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar5 = local_68;
        pcVar4 = (char *)GetStringFromSockAddr((short *)(lVar2 + 0x170),puVar5);
        WPP_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar5,uVar7,pcVar4,(char)lVar2,
                   (char)*(undefined8 *)(lVar2 + 0x88));
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(pgAdapter + 8);
      *(undefined1 *)(pgAdapter + 0x10) = uVar3;
      if (*(int *)(lVar2 + 0x30) == 7) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,uVar7,lVar2,
                    (char)*(undefined8 *)(lVar2 + 0x88));
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,uVar7,lVar2,
                    (char)*(undefined8 *)(lVar2 + 0x88));
        }
        CtlSetState(lVar2,7,uVar7,'\x01');
      }
      KeReleaseSpinLock(pgAdapter + 8,*(undefined1 *)(pgAdapter + 0x10));
      KeReleaseSpinLock(&gCallbackLock);
      CtlCleanup(lVar2,'\0');
      LOCK();
      piVar1 = (int *)(lVar2 + 0x10);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar6 == 1) {
        (**(code **)(lVar2 + 0x18))(lVar2);
      }
      return 0;
    }
  }
  KeReleaseSpinLock(&gCallbackLock,DAT_1c000c4a8);
  return iVar6;
}



===== CtlFreePacket @ 1c0013e5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlFreePacket(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  
  plVar1 = (longlong *)(param_2 + -0x18);
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
  *(undefined1 *)(param_1 + 0x68) = uVar7;
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_2 + -0x10), (longlong *)*plVar5 != plVar1)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  if ((*(int *)(param_1 + 0x30) == 7) &&
     (*(longlong **)(param_1 + 0x78) == (longlong *)(param_1 + 0x78))) {
    CtlCleanup(param_1,'\x01');
  }
  KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
  NsiCliCleanupProviderContext(plVar1);
  LOCK();
  piVar2 = (int *)(param_1 + 0x10);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return;
}



===== CtlListen @ 1c0013f0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CtlListen(longlong param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStack_88 [32];
  short local_68 [8];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    param_2 = 0x5d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  if (*(longlong *)(param_1 + 0x38) == 0) {
    uVar1 = PptpControlPort >> 8 | PptpControlPort << 8;
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    local_50 = CONCAT62(CONCAT42(local_50._4_4_,uVar1),2);
    local_58 = &local_50;
    local_68[0] = 1;
    local_68[1] = 0;
    local_68[4] = 1;
    local_68[5] = 0;
    local_68[6] = 0;
    local_68[7] = 0;
    local_68[2] = 6;
    local_68[3] = 0;
    lVar3 = WskCreateAndIntializeSockContext();
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff66;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0xc000009a);
      }
    }
    else {
      *(longlong *)(lVar3 + 8) = param_1;
      *(code **)(lVar3 + 0x20) = CtlConnectQueryCallback;
      *(code **)(lVar3 + 0x18) = CtlDisconnectCallback;
      *(code **)(lVar3 + 0x10) = CtlReceiveCallback;
      *(code **)(lVar3 + 0x40) = CtlpSendMessageComplete;
      *(longlong *)(lVar3 + 0x48) = param_1 + 0x60;
      *(code **)(lVar3 + 0x30) = CtlLogWskLibActivity;
      uVar4 = WskCreateServerSocket(local_68,param_2,lVar3);
      iVar2 = (int)uVar4;
      if (iVar2 < 0) {
        WskDestroySockContext(lVar3);
      }
      else {
        *(longlong *)(param_1 + 0x38) = lVar3;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
             &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,iVar2);
  }
  return iVar2;
}



===== CtlReceiveCallback @ 1c0014100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CtlReceiveCallback(longlong *param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  char cVar6;
  ushort *puVar7;
  int iVar8;
  
  iVar8 = 0;
  DAT_1c000c4a8 = KeAcquireSpinLockRaiseToDpc();
  lVar4 = *param_1;
  if (lVar4 == 0) {
    iVar8 = -0x3ffffff3;
    ReceiveDataComplete(0,param_3);
  }
  else {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x60);
    plVar2 = (longlong *)(lVar4 + 0x88);
    *(undefined1 *)(lVar4 + 0x68) = uVar5;
    if (*(char *)(lVar4 + 0x70) != '\0') {
      iVar8 = -0x3ffffff3;
      ReceiveDataComplete(*plVar2,param_3);
    }
    KeReleaseSpinLock(lVar4 + 0x60,*(undefined1 *)(lVar4 + 0x68));
    if (iVar8 == 0) {
      cVar6 = ExAcquireRundownProtection(lVar4 + 0x58);
      if (cVar6 == '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                   &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,lVar4);
        }
        ReceiveDataComplete(*plVar2,param_3);
        KeReleaseSpinLock(&gCallbackLock,DAT_1c000c4a8);
      }
      else {
        LOCK();
        *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
        UNLOCK();
        ExReleaseRundownProtection(lVar4 + 0x58);
        KeReleaseSpinLock(&gCallbackLock,DAT_1c000c4a8);
        uVar3 = *(uint *)(*(longlong *)(param_3 + 8) + 0x18);
        puVar7 = (ushort *)NdisGetDataBuffer(*(longlong *)(param_3 + 8),uVar3,0,1,0);
        if (puVar7 != (ushort *)0x0) {
          CtlpEngine(lVar4,puVar7,uVar3);
        }
        ReceiveDataComplete(*plVar2,param_3);
        LOCK();
        piVar1 = (int *)(lVar4 + 0x10);
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (**(code **)(lVar4 + 0x18))(lVar4);
        }
      }
      return 0;
    }
  }
  KeReleaseSpinLock(&gCallbackLock,DAT_1c000c4a8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  return iVar8;
}



===== CtlSend @ 1c0014304 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CtlSend(longlong param_1,ushort *param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = WskSend(*(longlong *)(param_1 + 0x88),param_2,param_3,(longlong)param_2,
                  (uint)(ushort)(*param_2 >> 8 | *param_2 << 8));
  iVar2 = 0;
  if (iVar1 != 0x103) {
    iVar2 = iVar1;
  }
  if (iVar2 != 0) {
    _DAT_1c000c47c = _DAT_1c000c47c + 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,iVar2);
    }
  }
  return iVar2;
}



===== CtlSetState @ 1c0014384 =====

undefined4 CtlSetState(longlong param_1,uint param_2,undefined8 param_3,char param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = WPP_GLOBAL_Control;
    pcVar4 = szCtlState(param_2);
    pcVar5 = szCtlState(*(uint *)(param_1 + 0x30));
    WPP_SF_qss(*(undefined8 *)(puVar6 + 0x18),pcVar4,puVar6,param_1,pcVar5,pcVar4);
  }
  if (param_4 == '\0') {
    uVar3 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x28) + 8);
    *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x10) = uVar3;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  *(uint *)(param_1 + 0x30) = param_2;
  if (param_4 == '\0') {
    lVar2 = *(longlong *)(param_1 + 0x28);
    KeReleaseSpinLock(lVar2 + 8,
                      CONCAT71((int7)((ulonglong)lVar2 >> 8),*(undefined1 *)(lVar2 + 0x10)));
  }
  return uVar1;
}



===== CtlpAllocPacketLocked @ 1c001444c =====

longlong * CtlpAllocPacketLocked(longlong param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined2 uVar6;
  longlong *plVar7;
  
  if (*(int *)(param_1 + 0x30) == 7) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1);
    }
  }
  else {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x238) + (longlong)param_2 * 4);
    uVar1 = uVar2 + 0x18;
    if (uVar1 < uVar2) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return (longlong *)0x0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return (longlong *)0x0;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return (longlong *)0x0;
      }
      uVar6 = 0x10;
    }
    else {
      plVar4 = (longlong *)MyMemAlloc(uVar1,0x50545450);
      if (plVar4 != (longlong *)0x0) {
        *(uint *)(plVar4 + 2) = uVar1;
        lVar5 = param_1 + 0x78;
        *(ushort *)(plVar4 + 3) = (ushort)uVar2 >> 8 | (ushort)uVar2 << 8;
        *(ushort *)(plVar4 + 4) = (ushort)param_2 >> 8 | (ushort)param_2 << 8;
        *(undefined2 *)((longlong)plVar4 + 0x1a) = 0x100;
        *(undefined4 *)((longlong)plVar4 + 0x1c) = 0x4d3c2b1a;
        plVar7 = *(longlong **)(param_1 + 0x80);
        if (*plVar7 != lVar5) {
          lVar5 = 3;
          pcVar3 = (code *)swi(0x29);
          plVar4 = (longlong *)(*pcVar3)();
        }
        *plVar4 = lVar5;
        plVar4[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar4;
        *(longlong **)(lVar5 + 8) = plVar4;
        LOCK();
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        UNLOCK();
        return plVar4 + 3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return (longlong *)0x0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return (longlong *)0x0;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return (longlong *)0x0;
      }
      uVar6 = 0x11;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  return (longlong *)0x0;
}



===== CtlpCleanup @ 1c00145b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlpCleanup(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  int *piVar4;
  int iVar5;
  longlong lVar6;
  bool bVar7;
  undefined1 uVar8;
  char cVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined *puVar12;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  lVar6 = *(longlong *)(param_1 + 0x18);
  bVar7 = false;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  lVar1 = lVar6 + 0x60;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  plVar2 = (longlong *)(lVar6 + 0x38);
  *(undefined1 *)(lVar6 + 0x68) = uVar8;
  if ((longlong *)*plVar2 == plVar2) {
LAB_1c001473a:
    if (*(longlong **)(lVar6 + 0x78) == (longlong *)(lVar6 + 0x78)) {
      if (*(char *)(lVar6 + 0x24d) == '\0') {
        *(undefined1 *)(lVar6 + 0x24d) = 1;
        KeReleaseSpinLock(lVar1,uVar8);
        NdisCancelTimerObject(*(undefined8 *)(lVar6 + 0x240));
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
        *(undefined1 *)(lVar6 + 0x68) = uVar8;
      }
      if (*(int *)(lVar6 + 0x10) == 2) {
        KeReleaseSpinLock(lVar1,uVar8);
        cVar9 = NdisCancelTimerObject(*(undefined8 *)(lVar6 + 0x250));
        if (cVar9 == '\x01') {
          KeSetEvent(lVar6 + 0x260,0,0);
        }
        cVar9 = NdisCancelTimerObject(*(undefined8 *)(lVar6 + 600));
        if (cVar9 == '\x01') {
          KeSetEvent(lVar6 + 0x278,0,0);
        }
        local_48 = lVar6 + 0x260;
        local_40 = lVar6 + 0x278;
        KeWaitForMultipleObjects(2,&local_48,0,0,0,0,0,0);
        bVar7 = true;
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x60);
        *(undefined1 *)(lVar6 + 0x68) = uVar8;
        goto LAB_1c00147cd;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,*(int *)(lVar6 + 0x10));
      }
    }
  }
  else {
    local_24 = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
    LOCK();
    *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
    UNLOCK();
    KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar6 + 0x68));
    local_30 = 0;
    puVar12 = (undefined *)(*(longlong *)(lVar6 + 0x28) + 8);
    local_38 = 0;
    local_28 = 0x4d554e45;
    plVar10 = EnumListEntry(plVar2,&local_38,(longlong)puVar12,0);
    while (plVar10 != (longlong *)0x0) {
      plVar3 = plVar10 + -2;
      if ((plVar3 != (longlong *)0x0) && ((int)plVar10[4] == 0x43505450)) {
        uVar11 = 0xb;
        CallSetState((longlong)plVar3,0xb,puVar12,'\0');
        CallCleanup((int *)plVar3,uVar11,puVar12);
        DereferenceRefCount((int *)plVar3);
      }
      puVar12 = (undefined *)(*(longlong *)(lVar6 + 0x28) + 8);
      plVar10 = EnumListEntry(plVar2,&local_38,(longlong)puVar12,0);
    }
    EnumComplete(&local_38,*(longlong *)(lVar6 + 0x28) + 8);
    LOCK();
    piVar4 = (int *)(lVar6 + 0x10);
    iVar5 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (**(code **)(lVar6 + 0x18))(lVar6);
    }
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(lVar6 + 0x68) = uVar8;
    if ((longlong *)*plVar2 == plVar2) goto LAB_1c001473a;
  }
  *(undefined1 *)(lVar6 + 0x70) = 0;
LAB_1c00147cd:
  KeReleaseSpinLock(lVar6 + 0x60,*(undefined1 *)(lVar6 + 0x68));
  LOCK();
  piVar4 = (int *)(lVar6 + 0x10);
  iVar5 = *piVar4;
  *piVar4 = *piVar4 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    (**(code **)(lVar6 + 0x18))(lVar6);
  }
  if (bVar7) {
    if (*(char *)(lVar6 + 0x48) == '\0') {
      DeleteHostRoute((short *)(lVar6 + 0x170));
    }
    ExWaitForRundownProtectionRelease(lVar6 + 0x58);
    ExRundownCompleted(lVar6 + 0x58);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,lVar6);
    }
    LOCK();
    piVar4 = (int *)(lVar6 + 0x10);
    iVar5 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (**(code **)(lVar6 + 0x18))(lVar6);
    }
  }
  return;
}



===== CtlpDeathTimeout @ 1c0014974 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CtlpDeathTimeout(longlong param_1)

{
  char *pcVar1;
  undefined *puVar2;
  undefined1 auStack_88 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = (undefined *)0x41;
  memset(local_68,0,0x41);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    pcVar1 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_68);
    puVar2 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
             &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar1);
  }
  CtlSetState(param_1,7,puVar2,'\0');
  if (*(longlong *)(param_1 + 0x88) == 0) {
    CtlCleanup(param_1,'\0');
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1);
    }
    WskConnDisconnectEvent(*(longlong *)(param_1 + 0x88));
  }
  return;
}



===== CtlpEchoTimeout @ 1c0014a80 =====

void CtlpEchoTimeout(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  undefined1 uVar2;
  ushort *puVar3;
  int iVar4;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x60);
  *(undefined1 *)(param_2 + 0x68) = uVar2;
  if (*(int *)(param_2 + 0x30) == 7) {
    KeReleaseSpinLock(param_2 + 0x60,uVar2);
  }
  else {
    cVar1 = *(char *)(param_2 + 0x24c);
    iVar4 = *(int *)(param_2 + 0x248) + 1;
    *(int *)(param_2 + 0x248) = iVar4;
    *(undefined1 *)(param_2 + 0x24c) = 1;
    KeReleaseSpinLock();
    if (cVar1 != '\0') {
      puVar3 = (ushort *)CtlAllocPacket(param_2,5);
      if (puVar3 != (ushort *)0x0) {
        *(int *)(puVar3 + 6) = iVar4;
        CtlSend(param_2,puVar3,param_3);
      }
    }
  }
  return;
}



===== CtlpEngine @ 1c0014b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlpEngine(longlong param_1,ushort *param_2,uint param_3)

{
  longlong *plVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  undefined1 uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  undefined4 uVar15;
  char *pcVar16;
  ushort *puVar17;
  ushort *puVar18;
  longlong *plVar19;
  int *piVar20;
  longlong *plVar21;
  undefined2 uVar22;
  longlong lVar23;
  ulonglong uVar24;
  undefined1 *puVar25;
  ulonglong uVar26;
  uint uVar27;
  undefined8 uVar28;
  undefined *puVar29;
  int *piVar30;
  undefined1 auStackY_148 [32];
  longlong local_e8 [2];
  undefined8 local_d8;
  longlong local_d0 [7];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  bVar7 = false;
  memset(local_98,0,0x41);
  do {
    uVar28 = 2;
    if (param_3 == 0) {
      return;
    }
    uVar14 = *(uint *)(param_1 + 0x16c);
    if (uVar14 == 0) {
      if (param_3 < 0xc) {
        memcpy((ushort *)(param_1 + 0x90),param_2,(ulonglong)param_3);
        *(uint *)(param_1 + 0x16c) = param_3;
        return;
      }
      uVar24 = 0;
      puVar18 = param_2;
    }
    else {
      uVar24 = (ulonglong)uVar14;
      do {
        if (0xb < uVar14) break;
        uVar12 = *param_2;
        param_2 = (ushort *)((longlong)param_2 + 1);
        *(char *)((ulonglong)uVar14 + 0x90 + param_1) = (char)uVar12;
        uVar14 = *(int *)(param_1 + 0x16c) + 1;
        *(uint *)(param_1 + 0x16c) = uVar14;
        uVar24 = (ulonglong)uVar14;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
      if (uVar14 < 0xc) {
        return;
      }
      puVar18 = (ushort *)(param_1 + 0x90);
    }
    uVar12 = *puVar18;
    uVar10 = uVar12 >> 8 | uVar12 << 8;
    uVar26 = (ulonglong)uVar10;
    uVar13 = puVar18[4];
    uVar11 = uVar13 >> 8 | uVar13 << 8;
    uVar14 = (uint)uVar10;
    if ((((0xdc < uVar10) || (*(int *)(puVar18 + 2) != 0x4d3c2b1a)) || (puVar18[1] != 0x100)) ||
       ((0xe < uVar11 - 1 ||
        ((uint)uVar10 != *(uint *)(*(longlong *)(param_1 + 0x238) + (ulonglong)uVar11 * 4))))) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
        uVar10 = puVar18[1];
        puVar25 = local_98;
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),puVar25);
        WPP_SF_sdDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar25,uVar28,pcVar16,
                     (char)(uVar12 >> 8),(char)*(undefined4 *)(puVar18 + 2),(char)uVar10,
                     (char)(uVar13 >> 8));
      }
      break;
    }
    iVar3 = (int)uVar24;
    if (iVar3 + param_3 < uVar14) {
      memcpy((void *)(uVar24 + 0x90 + param_1),param_2,(ulonglong)param_3);
      *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + param_3;
      return;
    }
    if (iVar3 == 0) {
      puVar18 = param_2;
    }
    else {
      uVar14 = uVar14 - iVar3;
      uVar26 = (ulonglong)uVar14;
      memcpy((void *)(uVar24 + 0x90 + param_1),param_2,(ulonglong)uVar14);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      puVar18 = (ushort *)(param_1 + 0x90);
    }
    param_3 = param_3 - uVar14;
    puVar29 = (undefined *)0x2;
    param_2 = (ushort *)((longlong)param_2 + uVar26);
    uVar12 = puVar18[4] >> 8 | puVar18[4] << 8;
    uVar9 = (undefined1)param_1;
    if (uVar12 < 9) {
      if (uVar12 == 8) {
        uVar12 = puVar18[7];
        uVar13 = uVar12 >> 8 | uVar12 << 8;
        uVar27 = (uint)uVar13;
        uVar14 = uVar27;
        if (PptpClientSide != '\0') {
          uVar14 = uVar13 & 0x3fff;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar13 = puVar18[6];
          WPP_SF_qdddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                         (ulonglong)(ushort)(uVar13 >> 8 | uVar13 << 8),
                         (ulonglong)*(byte *)((longlong)puVar18 + 0x11),param_1,
                         (char)*(undefined4 *)(param_1 + 0x30),(char)uVar14,(char)(uVar12 >> 8),
                         (char)(uVar13 >> 8),(char)puVar18[8],*(byte *)((longlong)puVar18 + 0x11));
        }
        if (*(int *)(param_1 + 0x30) == 5) {
          piVar20 = CallGetCall(*(longlong *)(param_1 + 0x28),(ulonglong)uVar14);
          if ((piVar20 != (int *)0x0) && (piVar20[0xc] == 0x43505450)) {
            piVar30 = piVar20 + 0x18;
            uVar9 = KeAcquireSpinLockRaiseToDpc(piVar30);
            *(undefined1 *)(piVar20 + 0x1a) = uVar9;
            if ((*(longlong *)(piVar20 + 0x14) == param_1) &&
               ((piVar20[0x1d] == 2 && (piVar20[0x1c] != 0xb)))) {
              KeReleaseSpinLock(piVar30,uVar9);
              CallEventCallOutReply(piVar20,(longlong)puVar18);
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 &&
                  (WPP_GLOBAL_Control[0x29] != '\0')))) {
                uVar22 = 0x2f;
LAB_1c00155b2:
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar22,
                         &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,uVar27);
              }
LAB_1c00155c5:
              KeReleaseSpinLock(piVar30,(char)piVar20[0x1a]);
            }
LAB_1c00155d7:
            DereferenceRefCount(piVar20);
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
                (WPP_GLOBAL_Control[0x29] != '\0')) {
          uVar22 = 0x30;
LAB_1c001535d:
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar22,
                  &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
        }
      }
      else if (uVar12 == 1) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,puVar29,pcVar16,uVar9,
                     (char)*(undefined4 *)(param_1 + 0x30));
        }
        if (*(int *)(param_1 + 0x30) == 3) {
          *(uint *)(param_1 + 0x18c) = (uint)(ushort)(puVar18[6] >> 8 | puVar18[6] << 8);
          uVar14 = *(uint *)(puVar18 + 8);
          *(uint *)(param_1 + 400) =
               uVar14 >> 0x18 | (uVar14 & 0xff0000) >> 8 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
          uVar14 = *(uint *)(puVar18 + 10);
          *(uint *)(param_1 + 0x194) =
               uVar14 >> 0x18 | (uVar14 & 0xff0000) >> 8 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
          uVar28 = *(undefined8 *)(puVar18 + 0x12);
          *(undefined8 *)(param_1 + 0x198) = *(undefined8 *)(puVar18 + 0xe);
          *(undefined8 *)(param_1 + 0x1a0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x1a);
          *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(puVar18 + 0x16);
          *(undefined8 *)(param_1 + 0x1b0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x22);
          *(undefined8 *)(param_1 + 0x1b8) = *(undefined8 *)(puVar18 + 0x1e);
          *(undefined8 *)(param_1 + 0x1c0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x2a);
          *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(puVar18 + 0x26);
          *(undefined8 *)(param_1 + 0x1d0) = uVar28;
          *(undefined1 *)(param_1 + 0x1d7) = 0;
          uVar28 = *(undefined8 *)(puVar18 + 0x32);
          *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)(puVar18 + 0x2e);
          *(undefined8 *)(param_1 + 0x1e0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x3a);
          *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)(puVar18 + 0x36);
          *(undefined8 *)(param_1 + 0x1f0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x42);
          *(undefined8 *)(param_1 + 0x1f8) = *(undefined8 *)(puVar18 + 0x3e);
          *(undefined8 *)(param_1 + 0x200) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x4a);
          *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(puVar18 + 0x46);
          *(undefined8 *)(param_1 + 0x210) = uVar28;
          *(undefined1 *)(param_1 + 0x217) = 0;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
          }
          LOCK();
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          UNLOCK();
          uVar15 = GetLocalAddress(*(longlong *)(param_1 + 0x88),param_1 + 0x218);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                     &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,uVar15);
          }
        }
        else if (*(int *)(param_1 + 0x30) == 7) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar22 = 0x29;
            goto LAB_1c001535d;
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                    &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
          }
          bVar7 = true;
        }
      }
      else if (uVar12 == 2) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar2 = *(undefined1 *)((longlong)puVar18 + 0xf);
          uVar12 = puVar18[7];
          puVar25 = local_98;
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),puVar25);
          WPP_SF_sqddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar25,puVar29,pcVar16,uVar9,
                       (char)*(undefined4 *)(param_1 + 0x30),(char)uVar12,uVar2);
        }
        if (*(int *)(param_1 + 0x30) == 4) {
          local_e8[0] = 0;
          local_e8[1] = 0;
          local_d8 = 0;
          cVar8 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x250));
          if (cVar8 != '\0') {
            puVar29 = (undefined *)0x0;
            KeSetEvent(param_1 + 0x260,0);
          }
          uVar27 = (uint)(ushort)(puVar18[6] >> 8 | puVar18[6] << 8);
          *(uint *)(param_1 + 0x18c) = uVar27;
          uVar14 = *(uint *)(puVar18 + 8);
          *(uint *)(param_1 + 400) =
               uVar14 >> 0x18 | (uVar14 & 0xff0000) >> 8 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
          uVar14 = *(uint *)(puVar18 + 10);
          *(uint *)(param_1 + 0x194) =
               uVar14 >> 0x18 | (uVar14 & 0xff0000) >> 8 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
          uVar28 = *(undefined8 *)(puVar18 + 0x12);
          *(undefined8 *)(param_1 + 0x198) = *(undefined8 *)(puVar18 + 0xe);
          *(undefined8 *)(param_1 + 0x1a0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x1a);
          *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(puVar18 + 0x16);
          *(undefined8 *)(param_1 + 0x1b0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x22);
          *(undefined8 *)(param_1 + 0x1b8) = *(undefined8 *)(puVar18 + 0x1e);
          *(undefined8 *)(param_1 + 0x1c0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x2a);
          *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(puVar18 + 0x26);
          *(undefined8 *)(param_1 + 0x1d0) = uVar28;
          *(undefined1 *)(param_1 + 0x1d7) = 0;
          uVar28 = *(undefined8 *)(puVar18 + 0x32);
          *(undefined8 *)(param_1 + 0x1d8) = *(undefined8 *)(puVar18 + 0x2e);
          *(undefined8 *)(param_1 + 0x1e0) = uVar28;
          uVar28 = *(undefined8 *)(puVar18 + 0x3a);
          *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)(puVar18 + 0x36);
          *(undefined8 *)(param_1 + 0x1f0) = uVar28;
          uVar15 = *(undefined4 *)(puVar18 + 0x40);
          uVar4 = *(undefined4 *)(puVar18 + 0x42);
          uVar5 = *(undefined4 *)(puVar18 + 0x44);
          *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(puVar18 + 0x3e);
          *(undefined4 *)(param_1 + 0x1fc) = uVar15;
          *(undefined4 *)(param_1 + 0x200) = uVar4;
          *(undefined4 *)(param_1 + 0x204) = uVar5;
          uVar28 = *(undefined8 *)(puVar18 + 0x4a);
          *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(puVar18 + 0x46);
          *(undefined8 *)(param_1 + 0x210) = uVar28;
          *(undefined1 *)(param_1 + 0x217) = 0;
          if (((uVar27 == 0x100) && ((char)puVar18[7] == '\x01')) &&
             (*(char *)((longlong)puVar18 + 0xf) == '\0')) {
            CtlSetState(param_1,5,puVar29,'\0');
            LOCK();
            *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
            UNLOCK();
            local_e8[1] = 0;
            local_e8[0] = 0;
            local_d8 = CONCAT44(local_d8._4_4_,0x4d554e45);
            while (plVar19 = EnumListEntry((longlong *)(param_1 + 0x38),local_e8,
                                           *(longlong *)(param_1 + 0x28) + 8,0),
                  plVar19 != (longlong *)0x0) {
              plVar21 = plVar19 + -2;
              if ((plVar21 != (longlong *)0x0) && ((int)plVar19[4] == 0x43505450)) {
                CallEventOutboundTunnelEstablished((int *)plVar21);
                DereferenceRefCount((int *)plVar21);
              }
            }
            plVar19 = local_e8;
LAB_1c0015254:
            EnumComplete(plVar19,*(longlong *)(param_1 + 0x28) + 8);
            LOCK();
            piVar20 = (int *)(param_1 + 0x10);
            iVar3 = *piVar20;
            *piVar20 = *piVar20 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              (**(code **)(param_1 + 0x18))(param_1);
            }
          }
          else {
            bVar7 = true;
          }
        }
      }
      else if (uVar12 == 3) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,puVar29,pcVar16,uVar9,
                     (char)*(undefined4 *)(param_1 + 0x30));
        }
        iVar3 = *(int *)(param_1 + 0x30);
        if ((iVar3 != 4) && (iVar3 != 5)) {
          if (iVar3 != 6) goto LAB_1c0014dc7;
          cVar8 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 600));
          if (cVar8 != '\0') {
            puVar29 = (undefined *)0x0;
            KeSetEvent(param_1 + 0x278,0);
          }
        }
        puVar18 = (ushort *)CtlAllocPacket(param_1,4);
        if (puVar18 != (ushort *)0x0) {
          *(undefined1 *)(puVar18 + 6) = 1;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
            puVar29 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
            WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                     &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16);
          }
          CtlSend(param_1,puVar18,puVar29);
        }
LAB_1c0014f4a:
        CtlSetState(param_1,7,puVar29,'\0');
        CtlCleanup(param_1,'\0');
      }
      else if (uVar12 == 4) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,puVar29,pcVar16,uVar9,
                     (char)*(undefined4 *)(param_1 + 0x30));
        }
        if (*(int *)(param_1 + 0x30) == 6) {
          cVar8 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 600));
          if (cVar8 != '\0') {
            puVar29 = (undefined *)0x0;
            KeSetEvent(param_1 + 0x278,0);
          }
          goto LAB_1c0014f4a;
        }
      }
      else if (uVar12 == 5) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          puVar29 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
          WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                   &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16);
        }
        *(undefined1 *)(param_1 + 0x24c) = 0;
        if ((*(int *)(param_1 + 0x18c) == 0x100) &&
           (puVar17 = (ushort *)CtlAllocPacket(param_1,6), puVar17 != (ushort *)0x0)) {
          *(undefined4 *)(puVar17 + 6) = *(undefined4 *)(puVar18 + 6);
          *(undefined1 *)(puVar17 + 8) = 1;
          CtlSend(param_1,puVar17,puVar29);
        }
      }
      else if (uVar12 == 6) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          uVar22 = 0x3d;
          goto LAB_1c0014e07;
        }
      }
      else {
        if (uVar12 != 7) goto LAB_1c001564e;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar12 = puVar18[6];
          pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
          WPP_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                      &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16,uVar9,
                      (char)*(undefined4 *)(param_1 + 0x30),(char)(uVar12 >> 8));
        }
        if (*(int *)(param_1 + 0x30) == 5) {
          cVar8 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 600));
          if (cVar8 != '\0') {
            KeSetEvent(param_1 + 0x278,0,0);
          }
          CallEventCallOutRequest(*(undefined8 **)(param_1 + 0x28),param_1,(longlong)puVar18);
        }
      }
    }
    else if (uVar12 == 9) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,puVar29,pcVar16,uVar9,
                   (char)*(undefined4 *)(param_1 + 0x30));
      }
      if (*(int *)(param_1 + 0x30) == 5) {
        cVar8 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 600));
        if (cVar8 != '\0') {
          KeSetEvent(param_1 + 0x278,0,0);
        }
        CallEventCallInRequest(*(undefined8 **)(param_1 + 0x28),param_1,(longlong)puVar18);
      }
    }
    else if (uVar12 == 10) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,puVar29,pcVar16,uVar9,
                   (char)*(undefined4 *)(param_1 + 0x30));
      }
    }
    else if (uVar12 == 0xb) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        WPP_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,puVar29,pcVar16,uVar9,
                   (char)*(undefined4 *)(param_1 + 0x30));
      }
      if (*(int *)(param_1 + 0x30) == 5) {
        uVar27 = (uint)(ushort)(puVar18[6] >> 8 | puVar18[6] << 8);
        uVar14 = uVar27;
        if (PptpClientSide != '\0') {
          uVar14 = uVar27 & 0x3fff;
        }
        piVar20 = CallGetCall(*(longlong *)(param_1 + 0x28),(ulonglong)uVar14);
        if ((piVar20 != (int *)0x0) && (piVar20[0xc] == 0x43505450)) {
          piVar30 = piVar20 + 0x18;
          uVar9 = KeAcquireSpinLockRaiseToDpc(piVar30);
          *(undefined1 *)(piVar20 + 0x1a) = uVar9;
          if ((*(longlong *)(piVar20 + 0x14) != param_1) ||
             ((piVar20[0x1d] != 1 || (piVar20[0x1c] == 0xb)))) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 &&
                (WPP_GLOBAL_Control[0x29] != '\0')))) {
              uVar22 = 0x3c;
              goto LAB_1c00155b2;
            }
            goto LAB_1c00155c5;
          }
          KeReleaseSpinLock(piVar30,uVar9);
          CallEventCallInConnect(piVar20,(longlong)puVar18,puVar29);
          goto LAB_1c00155d7;
        }
      }
    }
    else if (uVar12 == 0xc) {
      uVar12 = puVar18[6];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        WPP_SF_sqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                    &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16,uVar9,
                    (char)*(undefined4 *)(param_1 + 0x30),(char)(uVar12 >> 8));
      }
      if (*(int *)(param_1 + 0x30) == 5) {
        LOCK();
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        UNLOCK();
        local_d0[4] = 0;
        local_d0[3] = 0;
        local_d0[5] = 0x4d554e45;
        do {
          uVar9 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x28) + 8);
          *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x10) = uVar9;
          plVar19 = EnumListEntry((longlong *)(param_1 + 0x38),local_d0 + 3,0,0);
          if (((plVar19 != (longlong *)0x0) && (plVar21 = plVar19 + -2, plVar21 != (longlong *)0x0))
             && ((int)plVar19[4] == 0x43505450)) {
            if ((plVar19[8] == param_1) &&
               (*(ushort *)((longlong)plVar19 + 300) == (ushort)(uVar12 >> 8 | uVar12 << 8))) {
              uVar24 = (ulonglong)
                       CONCAT11((char)(*(ushort *)((longlong)plVar19 + 300) >> 8),
                                *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x10));
              if ((int)plVar19[0xc] == 0xb) {
                KeReleaseSpinLock();
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                           &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,(int)plVar19[0x17]);
                }
              }
              else {
                KeReleaseSpinLock(*(longlong *)(param_1 + 0x28) + 8);
                CallEventCallClearRequest((int *)plVar21,uVar24,param_1);
              }
              DereferenceRefCount((int *)plVar21);
              break;
            }
            DereferenceRefCount((int *)plVar21);
          }
          lVar23 = *(longlong *)(param_1 + 0x28);
          KeReleaseSpinLock(lVar23 + 8,
                            CONCAT71((int7)((ulonglong)lVar23 >> 8),*(undefined1 *)(lVar23 + 0x10)))
          ;
        } while (plVar19 != (longlong *)0x0);
        plVar19 = local_d0 + 3;
        goto LAB_1c0015254;
      }
    }
    else if (uVar12 == 0xd) {
      uVar12 = puVar18[6];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar2 = *(undefined1 *)((longlong)puVar18 + 0xf);
        uVar13 = puVar18[7];
        puVar25 = local_98;
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),puVar25);
        WPP_SF_sqdddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar25,puVar29,pcVar16,uVar9,
                      (char)*(undefined4 *)(param_1 + 0x30),(char)(uVar12 >> 8),(char)uVar13,uVar2);
      }
      if (*(int *)(param_1 + 0x30) == 5) {
        plVar19 = (longlong *)0x0;
        bVar6 = false;
        LOCK();
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        UNLOCK();
        local_d0[1] = 0;
        local_d0[0] = 0;
        local_d0[2] = 0x4d554e45;
        while( true ) {
          puVar29 = (undefined *)(*(longlong *)(param_1 + 0x28) + 8);
          plVar21 = EnumListEntry((longlong *)(param_1 + 0x38),local_d0,(longlong)puVar29,0);
          if (plVar21 == (longlong *)0x0) break;
          plVar19 = plVar21 + -2;
          if ((plVar19 != (longlong *)0x0) && ((int)plVar21[4] == 0x43505450)) {
            plVar1 = plVar21 + 10;
            uVar9 = KeAcquireSpinLockRaiseToDpc(plVar1);
            *(undefined1 *)(plVar21 + 0xb) = uVar9;
            if ((plVar21[8] == param_1) &&
               (*(ushort *)((longlong)plVar21 + 300) == (ushort)(uVar12 >> 8 | uVar12 << 8))) {
              if (((int)plVar21[0xc] == 0xb) || ((*(uint *)(plVar21 + 0x33) & 0x100) != 0)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                  puVar29 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                           &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,(int)plVar21[0x17]);
                }
                KeReleaseSpinLock(plVar1,(char)plVar21[0xb]);
                DereferenceRefCount((int *)plVar19);
              }
              else {
                bVar6 = true;
                KeReleaseSpinLock(plVar1,CONCAT11((char)(*(ushort *)((longlong)plVar21 + 300) >> 8),
                                                  uVar9));
              }
              break;
            }
            KeReleaseSpinLock(plVar1,uVar9);
            DereferenceRefCount((int *)plVar19);
          }
        }
        lVar23 = *(longlong *)(param_1 + 0x28) + 8;
        EnumComplete(local_d0,lVar23);
        if (bVar6) {
          CallEventCallDisconnectNotify((int *)plVar19,lVar23,puVar29);
          DereferenceRefCount((int *)plVar19);
        }
        LOCK();
        piVar20 = (int *)(param_1 + 0x10);
        iVar3 = *piVar20;
        *piVar20 = *piVar20 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(param_1 + 0x18))(param_1);
        }
      }
    }
    else if (uVar12 == 0xe) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        uVar22 = 0x3e;
LAB_1c0014e07:
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar22,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16);
      }
    }
    else if (uVar12 == 0xf) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_98);
        WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                  &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar16,uVar9);
      }
    }
    else {
LAB_1c001564e:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        puVar25 = local_98;
        pcVar16 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),puVar25);
        WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar25,puVar29,
                  (uint)(ushort)(puVar18[4] >> 8 | puVar18[4] << 8),pcVar16);
      }
    }
LAB_1c0014dc7:
  } while (!bVar7);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  return;
}



===== CtlpQueryAddrInfoCallback @ 1c0015df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlpQueryAddrInfoCallback(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  longlong lStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
  }
  LOCK();
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  cVar3 = KeGetCurrentIrql();
  if (cVar3 == '\0') {
    local_28 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_18 = 0;
    uStack_10 = 0;
    lStack_20 = param_1;
    CtlpScheduleGetLinkSpeed((longlong)&local_38);
  }
  else {
    uVar4 = ScheduleWorkItem(CtlpScheduleGetLinkSpeed,param_1,0,0);
    if ((int)uVar4 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_1);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0x10);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x18))(param_1);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  return;
}



===== CtlpScheduleGetLinkSpeed @ 1c0015f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlpScheduleGetLinkSpeed(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  NTSTATUS NVar5;
  undefined4 local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x18);
  local_res8[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  NVar5 = NsiCliGetLinkSpeedFromInterfaceIpAddress(*(ULONG *)(lVar3 + 0x21c),local_res8);
  uVar4 = local_res8[0];
  if (NVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,local_res8[0]);
    }
    *(undefined4 *)(lVar3 + 0x290) = uVar4;
  }
  if (*(int *)(lVar3 + 0x30) == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,lVar3);
    }
    SendControlStartRequest(lVar3);
  }
  else if (*(int *)(lVar3 + 0x30) == 3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,lVar3);
    }
    SendControlStartReply(lVar3);
  }
  LOCK();
  piVar1 = (int *)(lVar3 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(lVar3 + 0x18))(lVar3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  return;
}



===== CtlpSendMessageComplete @ 1c0016110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CtlpSendMessageComplete
               (longlong param_1,undefined8 param_2,undefined *param_3,undefined8 param_4,
               longlong param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  UNLOCK();
  CtlFreePacket(param_1,param_5);
  if (param_6 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      param_3 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,param_6);
    }
    CtlSetState(param_1,7,param_3,'\0');
    CtlCleanup(param_1,'\0');
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  return;
}



===== PptpInitialize @ 1c00161a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PptpInitialize(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStackY_88 [32];
  short local_58 [8];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58[1] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_40 = 0;
  uStack_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
            &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
  }
  lVar1 = param_1 + 8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  if (*(longlong *)(param_1 + 0x40) == 0) {
    KeReleaseSpinLock(lVar1);
    if (*(longlong *)(param_1 + 0x40) == 0) {
      local_58[2] = 0x2f;
      local_58[3] = 0;
      local_58[0] = 3;
      local_48 = &local_40;
      local_58[4] = 4;
      local_58[5] = 0;
      local_40 = CONCAT44(local_40._4_4_,2);
      lVar3 = WskCreateAndIntializeSockContext();
      if (lVar3 == 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                   &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0);
        }
      }
      else {
        *(undefined8 *)(lVar3 + 0x18) = 0;
        *(code **)(lVar3 + 0x10) = CallReceiveDatagramCallback;
        *(longlong *)(lVar3 + 8) = param_1;
        *(code **)(lVar3 + 0x40) = CallpSendComplete;
        *(longlong *)(lVar3 + 0x48) = param_1 + 0x70;
        *(code **)(lVar3 + 0x30) = CtlLogWskLibActivity;
        uVar4 = WskCreateSocket(local_58,0,4,lVar3,0x20);
        if ((int)uVar4 == 0) {
          uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
          *(longlong *)(param_1 + 0x40) = lVar3;
          *(undefined1 *)(param_1 + 0x10) = uVar2;
          KeReleaseSpinLock(lVar1,uVar2);
          uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
          Pptpv4Initialized = 1;
          *(undefined1 *)(param_1 + 0x10) = uVar2;
          KeReleaseSpinLock(lVar1,uVar2);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                     &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0);
          }
          WskDestroySockContext(lVar3);
        }
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,0);
    }
  }
  else {
    KeReleaseSpinLock();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids);
    }
  }
  return 0;
}



===== ScheduleAddHostRoute @ 1c0016450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ScheduleAddHostRoute(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  short *psVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_38 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  psVar3 = (short *)&local_28;
  if (*(short *)(lVar1 + 0x170) == 2) {
    local_28 = *(undefined8 *)(lVar1 + 0x170);
    uStack_20 = *(undefined8 *)(lVar1 + 0x178);
  }
  else {
    local_38 = *(undefined8 *)(lVar1 + 0x180);
    local_30 = *(undefined4 *)(lVar1 + 0x188);
    psVar3 = (short *)&local_48;
    local_48 = *(undefined8 *)(lVar1 + 0x170);
    uStack_40 = *(undefined8 *)(lVar1 + 0x178);
  }
  uVar2 = AddHostRoute(psVar3,(undefined4 *)(lVar1 + 0x294));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,(int)uVar2);
  }
  return;
}



===== SendControlStartReply @ 1c0016530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendControlStartReply(longlong param_1)

{
  char cVar1;
  ushort *puVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 auStack_98 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  puVar4 = (undefined *)0x41;
  memset(local_68,0,0x41);
  puVar2 = (ushort *)CtlAllocPacket(param_1,2);
  if (puVar2 != (ushort *)0x0) {
    cVar1 = NdisCancelTimerObject(*(undefined8 *)(param_1 + 0x250));
    if (cVar1 != '\0') {
      puVar4 = (undefined *)0x0;
      KeSetEvent(param_1 + 0x260,0);
    }
    puVar2[8] = 0;
    puVar2[9] = 0x200;
    puVar2[10] = 0;
    puVar2[0xb] = 0x300;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[6] = 1;
    *(undefined8 *)(puVar2 + 0x2e) = 0x666f736f7263694d;
    puVar2[0x32] = 0x74;
    if (*(int *)(param_1 + 0x18c) == 0x100) {
      *(undefined1 *)(puVar2 + 7) = 1;
      CtlSetState(param_1,5,puVar4,'\0');
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        puVar4 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,*(int *)(param_1 + 0x18c));
      }
      *(undefined1 *)(puVar2 + 7) = 5;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar3 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_68);
      puVar4 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
      WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar3,(char)param_1);
    }
    CtlSend(param_1,puVar2,puVar4);
  }
  return;
}



===== SendControlStartRequest @ 1c00166c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendControlStartRequest(longlong param_1)

{
  undefined1 uVar1;
  ushort *puVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined1 auStack_a8 [32];
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar4 = 0x41;
  memset(local_78,0,0x41);
  puVar2 = (ushort *)CtlAllocPacket(param_1,1);
  CtlSetState(param_1,4,uVar4,'\0');
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x60);
  *(undefined1 *)(param_1 + 0x68) = uVar1;
  KeResetEvent(param_1 + 0x260);
  puVar5 = (undefined *)0x0;
  NdisSetTimerObject(*(undefined8 *)(param_1 + 0x250),0xffffffffee1e5d00,0,0);
  if (PptpEchoTimeout != 0) {
    puVar5 = (undefined *)(ulonglong)(uint)(PptpEchoTimeout * 1000);
    NdisSetTimerObject(*(undefined8 *)(param_1 + 0x240),(longlong)puVar5 * -10000,puVar5,0);
    *(undefined1 *)(param_1 + 0x24c) = 1;
  }
  KeReleaseSpinLock(param_1 + 0x60,*(undefined1 *)(param_1 + 0x68));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar3 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_78);
    puVar5 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
    WPP_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar3,(char)param_1);
  }
  if (puVar2 != (ushort *)0x0) {
    puVar2[6] = 1;
    puVar2[8] = 0;
    puVar2[9] = 0x100;
    puVar2[10] = 0;
    puVar2[0xb] = 0x100;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    *(undefined8 *)(puVar2 + 0x2e) = 0x666f736f7263694d;
    puVar2[0x32] = 0x74;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar3 = (char *)GetStringFromSockAddr((short *)(param_1 + 0x170),local_78);
      puVar5 = &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids;
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_1e2700892da1326f6a3adbe81277873a_Traceguids,pcVar3);
    }
    CtlSend(param_1,puVar2,puVar5);
  }
  return;
}



===== StringToIpAddressW @ 1c00168c4 =====

ushort * StringToIpAddressW(ushort *param_1,undefined4 *param_2,undefined1 *param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = *param_1;
  uVar6 = (uint)PptpControlPort;
  *param_3 = 0;
  uVar5 = 0;
  puVar4 = param_1;
  while( true ) {
    if (uVar2 == 0) {
      return param_1;
    }
    if ((ushort)(uVar2 - 0x30) < 10) break;
    puVar4 = puVar4 + 1;
    uVar2 = *puVar4;
  }
  uVar3 = 0;
  do {
    if ((3 < uVar3) || (uVar2 = *puVar4, uVar2 == 0)) {
      uVar2 = 0x3a;
      if (*puVar4 == 0x3a) {
        while ((uVar2 != 0 && ((ushort)(uVar2 - 0x30) < 10))) {
          uVar6 = (uint)uVar2 + (uVar6 * 5 + -0x18) * 2;
          if (0xffff < uVar6) {
            return param_1;
          }
          puVar4 = puVar4 + 1;
          uVar2 = *puVar4;
        }
      }
      if ((uVar5 - 1 < 0xfffffffe) && ((uVar5 & 0xf0000000) != 0xe0000000)) {
        *param_2 = 1;
        param_2[1] = 0x2000e;
        *(ushort *)(param_2 + 2) = (ushort)uVar6 >> 8 | (ushort)uVar6 << 8;
        *(uint *)((longlong)param_2 + 10) =
             uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
        *param_3 = 1;
      }
      return puVar4;
    }
    uVar1 = 0;
    while ((uVar2 != 0 && ((ushort)(uVar2 - 0x30) < 10))) {
      uVar1 = (uint)uVar2 + (uVar1 * 5 + -0x18) * 2;
      if (0xff < uVar1) {
        return param_1;
      }
      puVar4 = puVar4 + 1;
      uVar2 = *puVar4;
    }
    if (uVar3 < 3) {
      if (uVar2 != 0x2e) {
        return param_1;
      }
      puVar4 = puVar4 + 1;
      if (9 < (ushort)(*puVar4 - 0x30)) {
        return param_1;
      }
    }
    uVar5 = uVar5 * 0x100 + uVar1;
    uVar3 = uVar3 + 1;
  } while( true );
}



===== EnumComplete @ 1c0016a20 =====

void EnumComplete(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  
  if (*param_1 != 0) {
    if (param_2 != 0) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_2);
      *(undefined1 *)(param_2 + 8) = uVar4;
    }
    lVar1 = *param_1;
    if ((*(longlong **)(lVar1 + 8) != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    param_1[1] = 0;
    *param_1 = 0;
    if (param_2 != 0) {
      KeReleaseSpinLock(param_2,*(undefined1 *)(param_2 + 8));
    }
  }
  return;
}



===== EnumListEntry @ 1c0016aa0 =====

longlong * EnumListEntry(longlong *param_1,longlong *param_2,longlong param_3,int param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar4 = (longlong *)0x0;
  if (param_3 != 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_3);
    *(undefined1 *)(param_3 + 8) = uVar3;
  }
  do {
    plVar5 = (longlong *)*param_2;
    if (plVar5 == (longlong *)0x0) {
      plVar5 = (longlong *)*param_1;
      if (plVar5 != param_1) goto LAB_1c0016b1d;
    }
    else {
      if (plVar5 == param_1) {
        if (((longlong *)plVar5[1] != param_2) ||
           (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 != param_2)) goto LAB_1c0016c03;
        *plVar4 = (longlong)plVar5;
        plVar5[1] = (longlong)plVar4;
        param_2[1] = 0;
        *param_2 = 0;
        goto LAB_1c0016bcb;
      }
      if (((longlong *)plVar5[1] != param_2) ||
         (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 != param_2)) goto LAB_1c0016c03;
      *plVar4 = (longlong)plVar5;
      plVar5[1] = (longlong)plVar4;
LAB_1c0016b1d:
      lVar1 = *plVar5;
      if (*(longlong **)(lVar1 + 8) != plVar5) {
LAB_1c0016c03:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        plVar4 = (longlong *)(*pcVar2)();
        return plVar4;
      }
      *param_2 = lVar1;
      param_2[1] = (longlong)plVar5;
      *(longlong **)(lVar1 + 8) = param_2;
      *plVar5 = (longlong)param_2;
      plVar4 = plVar5;
    }
    if (plVar4 == (longlong *)0x0) goto LAB_1c0016bcd;
  } while ((int)plVar4[2] == 0x4d554e45);
  if (param_4 == 0) {
    plVar5 = plVar4 + -2;
    if (((plVar5 == (longlong *)0x0) || ((int)plVar4[4] != 0x43505450)) || ((int)*plVar5 == 0)) {
LAB_1c0016bcb:
      plVar4 = (longlong *)0x0;
    }
    else {
      LOCK();
      *(int *)plVar5 = (int)*plVar5 + 1;
      UNLOCK();
    }
  }
  else if (param_4 == 1) {
    LOCK();
    *(int *)(plVar4 + 2) = (int)plVar4[2] + 1;
    UNLOCK();
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_15f8f3c69fe539a078b1580830f46cde_Traceguids);
  }
LAB_1c0016bcd:
  if (param_3 != 0) {
    KeReleaseSpinLock(param_3,*(undefined1 *)(param_3 + 8));
  }
  return plVar4;
}



===== MiniportUnload @ 1c0016c10 =====

void MiniportUnload(void)

{
  if (gMiniportDriverHandle != 0) {
    NdisMDeregisterMiniportDriver();
    gMiniportDriverHandle = 0;
  }
  NsiCliDeregisterClient();
  WskStopClientModule();
  if (gDriverObject != 0) {
    WppCleanupKm();
  }
  return;
}



===== PptpCmActivateVcComplete @ 1c0016c60 =====

void PptpCmActivateVcComplete(int param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1);
  }
  if (param_1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1);
    }
    uVar6 = 0xb;
    CallSetState((longlong)param_2,0xb,param_3,'\0');
    CallCleanup(param_2,uVar6,param_3);
  }
  else {
    piVar1 = param_2 + 0x18;
    piVar2 = param_2 + 0x1a;
    uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
    puVar3 = (uint *)(param_2 + 0x6a);
    *(undefined1 *)piVar2 = uVar5;
    *puVar3 = *puVar3 & 0xffffefff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    LOCK();
    *param_2 = *param_2 + 1;
    UNLOCK();
    LOCK();
    param_2[8] = param_2[8] + 1;
    UNLOCK();
    *puVar3 = *puVar3 | 0x10004;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    puVar4 = *(uint **)(param_2 + 0x3a);
    if ((char)param_2[0x30] == '\0') {
      *puVar4 = *puVar4 | 2;
      uVar7 = (uint)param_2[0x6c] >> 3;
      KeReleaseSpinLock(piVar1,(char)*piVar2);
      *(uint *)(*(longlong *)(puVar4 + 2) + 0x20) = uVar7;
      *(uint *)(*(longlong *)(puVar4 + 2) + 0x28) = uVar7;
      **(uint **)(puVar4 + 2) = uVar7;
      *(uint *)(*(longlong *)(puVar4 + 2) + 8) = uVar7;
      *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x18) = 0x5b8;
      *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x38) = 0x5b8;
      **(undefined4 **)(param_2 + 0x6e) = 0x53415252;
      *(undefined4 *)(*(longlong *)(param_2 + 0x6e) + 4) =
           *(undefined4 *)(*(longlong *)(param_2 + 0x14) + 0x294);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1);
      }
      NdisCmMakeCallComplete(0,*(undefined8 *)(param_2 + 0x38),0,0,*(undefined8 *)(param_2 + 0x3a));
      uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
      param_2[0x3a] = 0;
      param_2[0x3b] = 0;
      *puVar3 = *puVar3 | 8;
      *(undefined1 *)piVar2 = uVar5;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      LOCK();
      *param_2 = *param_2 + 1;
      UNLOCK();
      KeReleaseSpinLock(piVar1,(char)*piVar2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_2);
      }
    }
    else {
      PptpCmFreeCallParams((longlong)puVar4);
      param_2[0x3a] = 0;
      param_2[0x3b] = 0;
      KeReleaseSpinLock(piVar1,(char)*piVar2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      NdisCmDispatchCallConnected(*(undefined8 *)(param_2 + 0x38));
    }
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x18);
  param_2[0x6a] = param_2[0x6a] & 0xfffdffff;
  *(undefined1 *)(param_2 + 0x1a) = uVar5;
  KeReleaseSpinLock(param_2 + 0x18,uVar5);
  DereferenceRefCount(param_2);
  return;
}



===== PptpCmBuildCallParams @ 1c0016fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong PptpCmBuildCallParams(longlong param_1)

{
  undefined4 *puVar1;
  short *psVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  longlong lVar9;
  short *psVar10;
  longlong lVar11;
  uint uVar12;
  undefined1 auStack_a8 [32];
  char local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar3 = *(longlong *)(param_1 + 0x50);
  lVar11 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  lVar9 = ExAllocatePool2(0x40,0x328,0x70435450);
  if (lVar9 == 0) {
    lVar9 = lVar11;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
  }
  else {
    *(uint **)(lVar9 + 8) = (uint *)(lVar9 + 0x18);
    *(longlong *)(lVar9 + 0x10) = lVar9 + 0x68;
    puVar1 = (undefined4 *)(lVar9 + 0xa8);
    uVar12 = *(uint *)(*(longlong *)(param_1 + 0x50) + 0x290);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
               &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,uVar12);
    }
    uVar12 = uVar12 >> 3;
    *(uint *)(lVar9 + 0x18) = uVar12;
    *(undefined4 *)(lVar9 + 0x30) = 0x5b8;
    *(undefined4 *)(lVar9 + 0x50) = 0x5b8;
    *(uint *)(lVar9 + 0x20) = uVar12;
    *(uint *)(lVar9 + 0x38) = uVar12;
    *(uint *)(lVar9 + 0x40) = uVar12;
    *(ulonglong *)(lVar9 + 0x98) = (ulonglong)(((int)puVar1 - ((int)lVar9 + 0x80)) - 0x10);
    *(undefined4 *)(lVar9 + 0x90) = 0x2800280;
    *(undefined4 *)(lVar9 + 0x70) = 0x5b8;
    *(undefined4 *)(lVar9 + 0x7c) = 0x2a0;
    *puVar1 = 0x280;
    *(uint *)(lVar9 + 0xac) = (uint)*(ushort *)(lVar9 + 0x90);
    *(uint *)(lVar9 + 0xb0) = (uint)*(ushort *)(lVar9 + 0x90);
    *(undefined4 *)(lVar9 + 0xb8) = *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x90);
    *(undefined4 *)(lVar9 + 0xbc) = *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x94);
    *(undefined4 *)(lVar9 + 0x1c8) = 0x18;
    *(undefined4 *)(lVar9 + 0x1cc) = 0x158;
    uVar7 = *(undefined8 *)(param_1 + 0x195);
    *(undefined8 *)(lVar9 + 0x208) = *(undefined8 *)(param_1 + 0x18d);
    *(undefined8 *)(lVar9 + 0x210) = uVar7;
    *(undefined4 *)(lVar9 + 0xc0) = 8;
    uVar12 = *(int *)(lVar9 + 0x1c8) + *(int *)(lVar9 + 0x1cc) + 7 & 0xfffffff8;
    *(uint *)(lVar9 + 0x11c) = uVar12;
    psVar2 = (short *)((ulonglong)uVar12 + (longlong)puVar1);
    memset(local_88,0,0x41);
    if (*(short *)(param_1 + 0x118) == 2) {
      RtlIpv4AddressToStringA(param_1 + 0x11c);
    }
    else {
      RtlIpv6AddressToStringA(param_1 + 0x120);
    }
    psVar10 = StrDupAsciiToUnicode(local_88);
    if (psVar10 != (short *)0x0) {
      uVar7 = *(undefined8 *)(psVar10 + 4);
      *(undefined8 *)psVar2 = *(undefined8 *)psVar10;
      *(undefined8 *)(psVar2 + 4) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0xc);
      *(undefined8 *)(psVar2 + 8) = *(undefined8 *)(psVar10 + 8);
      *(undefined8 *)(psVar2 + 0xc) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x14);
      *(undefined8 *)(psVar2 + 0x10) = *(undefined8 *)(psVar10 + 0x10);
      *(undefined8 *)(psVar2 + 0x14) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x1c);
      *(undefined8 *)(psVar2 + 0x18) = *(undefined8 *)(psVar10 + 0x18);
      *(undefined8 *)(psVar2 + 0x1c) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x24);
      *(undefined8 *)(psVar2 + 0x20) = *(undefined8 *)(psVar10 + 0x20);
      *(undefined8 *)(psVar2 + 0x24) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x2c);
      *(undefined8 *)(psVar2 + 0x28) = *(undefined8 *)(psVar10 + 0x28);
      *(undefined8 *)(psVar2 + 0x2c) = uVar7;
      uVar4 = *(undefined4 *)(psVar10 + 0x32);
      uVar5 = *(undefined4 *)(psVar10 + 0x34);
      uVar6 = *(undefined4 *)(psVar10 + 0x36);
      *(undefined4 *)(psVar2 + 0x30) = *(undefined4 *)(psVar10 + 0x30);
      *(undefined4 *)(psVar2 + 0x32) = uVar4;
      *(undefined4 *)(psVar2 + 0x34) = uVar5;
      *(undefined4 *)(psVar2 + 0x36) = uVar6;
      uVar4 = *(undefined4 *)(psVar10 + 0x3a);
      uVar5 = *(undefined4 *)(psVar10 + 0x3c);
      uVar6 = *(undefined4 *)(psVar10 + 0x3e);
      *(undefined4 *)(psVar2 + 0x38) = *(undefined4 *)(psVar10 + 0x38);
      *(undefined4 *)(psVar2 + 0x3a) = uVar4;
      *(undefined4 *)(psVar2 + 0x3c) = uVar5;
      *(undefined4 *)(psVar2 + 0x3e) = uVar6;
      *(undefined8 *)(psVar2 + 0x40) = *(undefined8 *)(psVar10 + 0x40);
      ExFreePoolWithTag(psVar10 + -8);
    }
    iVar8 = StrLenW(psVar2);
    *(undefined4 *)(lVar9 + 0x114) = 8;
    *(int *)(lVar9 + 0x118) = iVar8 * 2 + 2;
    uVar12 = *(int *)(lVar9 + 0x11c) + 0x8fU & 0xfffffff8;
    *(uint *)(lVar9 + 0x130) = uVar12;
    psVar2 = (short *)((ulonglong)uVar12 + (longlong)puVar1);
    memset(local_88,0,0x41);
    if (*(short *)(lVar3 + 0x218) == 2) {
      RtlIpv4AddressToStringA(lVar3 + 0x21c);
    }
    else {
      RtlIpv6AddressToStringA(lVar3 + 0x220,local_88);
    }
    psVar10 = StrDupAsciiToUnicode(local_88);
    if (psVar10 != (short *)0x0) {
      uVar7 = *(undefined8 *)(psVar10 + 4);
      *(undefined8 *)psVar2 = *(undefined8 *)psVar10;
      *(undefined8 *)(psVar2 + 4) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0xc);
      *(undefined8 *)(psVar2 + 8) = *(undefined8 *)(psVar10 + 8);
      *(undefined8 *)(psVar2 + 0xc) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x14);
      *(undefined8 *)(psVar2 + 0x10) = *(undefined8 *)(psVar10 + 0x10);
      *(undefined8 *)(psVar2 + 0x14) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x1c);
      *(undefined8 *)(psVar2 + 0x18) = *(undefined8 *)(psVar10 + 0x18);
      *(undefined8 *)(psVar2 + 0x1c) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x24);
      *(undefined8 *)(psVar2 + 0x20) = *(undefined8 *)(psVar10 + 0x20);
      *(undefined8 *)(psVar2 + 0x24) = uVar7;
      uVar7 = *(undefined8 *)(psVar10 + 0x2c);
      *(undefined8 *)(psVar2 + 0x28) = *(undefined8 *)(psVar10 + 0x28);
      *(undefined8 *)(psVar2 + 0x2c) = uVar7;
      uVar4 = *(undefined4 *)(psVar10 + 0x32);
      uVar5 = *(undefined4 *)(psVar10 + 0x34);
      uVar6 = *(undefined4 *)(psVar10 + 0x36);
      *(undefined4 *)(psVar2 + 0x30) = *(undefined4 *)(psVar10 + 0x30);
      *(undefined4 *)(psVar2 + 0x32) = uVar4;
      *(undefined4 *)(psVar2 + 0x34) = uVar5;
      *(undefined4 *)(psVar2 + 0x36) = uVar6;
      uVar4 = *(undefined4 *)(psVar10 + 0x3a);
      uVar5 = *(undefined4 *)(psVar10 + 0x3c);
      uVar6 = *(undefined4 *)(psVar10 + 0x3e);
      *(undefined4 *)(psVar2 + 0x38) = *(undefined4 *)(psVar10 + 0x38);
      *(undefined4 *)(psVar2 + 0x3a) = uVar4;
      *(undefined4 *)(psVar2 + 0x3c) = uVar5;
      *(undefined4 *)(psVar2 + 0x3e) = uVar6;
      *(undefined8 *)(psVar2 + 0x40) = *(undefined8 *)(psVar10 + 0x40);
      ExFreePoolWithTag(psVar10 + -8,0);
    }
    iVar8 = StrLenW(psVar2);
    *(undefined4 *)(lVar9 + 0x128) = 8;
    *(int *)(lVar9 + 300) = iVar8 * 2 + 2;
  }
  return lVar9;
}



===== PptpCmDeactivateVcComplete @ 1c00173c0 =====

void PptpCmDeactivateVcComplete(undefined4 param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  int *piVar5;
  undefined8 uVar6;
  
  piVar5 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    piVar5 = (int *)0x0;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1);
  }
  piVar1 = param_2 + 0x18;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  uVar4 = param_2[0x6a];
  uVar6 = CONCAT71((int7)((ulonglong)piVar5 >> 8),uVar3);
  *(undefined1 *)(param_2 + 0x1a) = uVar3;
  if ((uVar4 >> 0xf & 1) != 0) {
    uVar2 = param_2[0x6b];
    param_3 = (undefined *)(ulonglong)uVar2;
    if ((uVar2 & 0x200) == 0) {
      param_2[0x6b] = uVar2 | 0x200;
      KeReleaseSpinLock(piVar1,uVar6);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                 &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_2[0x32]);
      }
      uVar6 = *(undefined8 *)(param_2 + 0x38);
      param_3 = (undefined *)0x0;
      NdisCmCloseCallComplete(0,uVar6);
      uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
      uVar4 = param_2[0x6a] & 0xffff7fff;
      *(undefined1 *)(param_2 + 0x1a) = uVar3;
    }
  }
  uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),uVar3);
  param_2[0x6a] = uVar4 & 0xfffffffb;
  KeReleaseSpinLock(piVar1);
  CallCleanup(param_2,uVar6,param_3);
  DereferenceRefCount(param_2);
  return;
}



===== PptpCmFreeCallParams @ 1c001750c =====

void PptpCmFreeCallParams(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== PptpCmIncomingCallComplete @ 1c0017530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PptpCmIncomingCallComplete(int param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  ushort *puVar6;
  char *pcVar7;
  short sVar8;
  short sVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  bool bVar14;
  undefined1 auStackY_c8 [32];
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  iVar5 = -0x3fffffff;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  if ((param_2 == (int *)0x0) || (param_2[0xc] != 0x43505450)) {
    _DAT_1c000c444 = _DAT_1c000c444 + 1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    return;
  }
  piVar1 = param_2 + 0x18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_2 + 0x1a) = uVar4;
  if (param_1 == 0) {
    param_2[0x6a] = param_2[0x6a] | 8;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
    LOCK();
    *param_2 = *param_2 + 1;
    UNLOCK();
    param_1 = param_2[0x1c];
    if (param_1 == 0xb) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      goto LAB_1c0017ac8;
    }
    lVar2 = *(longlong *)(param_2 + 0x14);
    if (lVar2 != 0) {
      if (param_1 == 4) {
        puVar6 = (ushort *)CtlAllocPacket(lVar2,8);
        LOCK();
        UNLOCK();
        uVar11 = g_CallSerialNumber + 1;
        bVar14 = PptpClientSide == '\0';
        g_CallSerialNumber = g_CallSerialNumber + 1;
        *(short *)(param_2 + 0x36) = (short)uVar11;
        if (bVar14) {
          sVar8 = (short)param_2[0x34];
        }
        else {
          param_3 = (undefined *)0x4000;
          sVar9 = (short)((uVar11 & 0xffff) * 0x4000) + (short)param_2[0x32];
          sVar8 = sVar9 + 0x4000;
          if ((short)param_2[0x50] != sVar9) {
            sVar8 = sVar9;
          }
        }
        *(short *)(param_2 + 0x50) = sVar8;
        if (puVar6 != (ushort *)0x0) {
          CallSetState((longlong)param_2,9,param_3,'\x01');
          iVar5 = *(int *)(lVar2 + 0x290);
          param_2[0x6a] = param_2[0x6a] | 0x20000;
          param_2[0x6c] = iVar5;
          LOCK();
          *param_2 = *param_2 + 1;
          UNLOCK();
          KeReleaseSpinLock(piVar1,(char)param_2[0x1a]);
          puVar6[7] = *(ushort *)(param_2 + 0x4f) >> 8 | *(ushort *)(param_2 + 0x4f) << 8;
          puVar6[6] = *(ushort *)(param_2 + 0x50) >> 8 | *(ushort *)(param_2 + 0x50) << 8;
          *(undefined1 *)(puVar6 + 8) = 1;
          puVar6[0xc] = 0x40;
          *(int *)(puVar6 + 10) = param_2[0x6c];
          puVar6[0xd] = 0;
          puVar6[0xe] = 0;
          puVar6[0xf] = 0;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            iVar5 = param_2[0x4f];
            iVar3 = param_2[0x50];
            puVar12 = local_88;
            pcVar7 = (char *)GetStringFromSockAddr((short *)(param_2 + 0x46),puVar12);
            WPP_SF_sddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar12,param_3,pcVar7,
                        (char)param_2[0x32],(char)iVar3,(char)iVar5);
          }
          iVar5 = CtlSend(lVar2,puVar6,param_3);
          if (iVar5 == 0) {
            iVar5 = NdisMCmActivateVc(*(undefined8 *)(param_2 + 0x38),
                                      *(undefined8 *)(param_2 + 0x3a));
            if (iVar5 != 0x103) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                        &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
              }
              param_3 = *(undefined **)(param_2 + 0x3a);
              PptpCmActivateVcComplete(iVar5,param_2,param_3);
            }
          }
          else {
            uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
            param_2[0x6a] = param_2[0x6a] & 0xfffdffff;
            *(undefined1 *)(param_2 + 0x1a) = uVar4;
            _DAT_1c000c450 = _DAT_1c000c450 + 1;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                       &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_2[0x32]);
            }
            KeReleaseSpinLock(piVar1,(char)param_2[0x1a]);
            DereferenceRefCount(param_2);
          }
LAB_1c0017a86:
          uVar4 = KeAcquireSpinLockRaiseToDpc(piVar1);
          *(undefined1 *)(param_2 + 0x1a) = uVar4;
          goto LAB_1c0017ac8;
        }
        _DAT_1c000c44c = _DAT_1c000c44c + 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          uVar10 = 0x56;
LAB_1c0017761:
          param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                   &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_2[0x32]);
        }
      }
      else {
        if (param_1 != 5) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
             (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c0017ac8;
          uVar10 = 0x5c;
          goto LAB_1c0017ab8;
        }
        puVar6 = (ushort *)CtlAllocPacket(lVar2,10);
        LOCK();
        UNLOCK();
        uVar11 = g_CallSerialNumber + 1;
        bVar14 = PptpClientSide == '\0';
        g_CallSerialNumber = g_CallSerialNumber + 1;
        *(short *)(param_2 + 0x36) = (short)uVar11;
        if (bVar14) {
          sVar8 = (short)param_2[0x34];
        }
        else {
          param_3 = (undefined *)0x4000;
          sVar9 = (short)((uVar11 & 0xffff) * 0x4000) + (short)param_2[0x32];
          sVar8 = sVar9 + 0x4000;
          if ((short)param_2[0x50] != sVar9) {
            sVar8 = sVar9;
          }
        }
        *(short *)(param_2 + 0x50) = sVar8;
        if (puVar6 != (ushort *)0x0) {
          CallSetState((longlong)param_2,6,param_3,'\x01');
          KeReleaseSpinLock(piVar1,(char)param_2[0x1a]);
          puVar6[7] = *(ushort *)(param_2 + 0x4f) >> 8 | *(ushort *)(param_2 + 0x4f) << 8;
          puVar6[6] = *(ushort *)(param_2 + 0x50) >> 8 | *(ushort *)(param_2 + 0x50) << 8;
          *(undefined1 *)(puVar6 + 8) = 1;
          puVar6[9] = 0x40;
          puVar6[10] = 0;
          iVar5 = CtlSend(lVar2,puVar6,param_3);
          if ((((iVar5 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                     &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_2[0x32]);
          }
          goto LAB_1c0017a86;
        }
        _DAT_1c000c44c = _DAT_1c000c44c + 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          uVar10 = 0x5a;
          goto LAB_1c0017761;
        }
      }
      iVar5 = -0x3fffff66;
      goto LAB_1c0017ac8;
    }
    _DAT_1c000c448 = _DAT_1c000c448 + 1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_1c0017ac8;
    param_1 = param_2[0x32];
    uVar10 = 0x55;
  }
  else {
    _DAT_1c000c43c = _DAT_1c000c43c + 1;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_1c0017ac8;
    uVar10 = 0x52;
  }
LAB_1c0017ab8:
  param_3 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,param_1);
LAB_1c0017ac8:
  param_2[0x6a] = param_2[0x6a] & 0xfffffeff;
  if (iVar5 == 0) {
    KeReleaseSpinLock(piVar1,(char)param_2[0x1a]);
  }
  else {
    uVar13 = 0;
    CallSetState((longlong)param_2,0xb,param_3,'\x01');
    uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),(char)param_2[0x1a]);
    KeReleaseSpinLock(piVar1);
    CallCleanup(param_2,uVar13,param_3);
  }
  DereferenceRefCount(param_2);
  return;
}



===== PptpCmMakeCallCallback @ 1c0017b90 =====

void PptpCmMakeCallCallback(longlong param_1,undefined8 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined *puVar8;
  char local_res8 [8];
  
  piVar2 = *(int **)(param_1 + 0x20);
  iVar6 = 0;
  puVar3 = *(undefined8 **)(param_1 + 0x18);
  local_res8[0] = '\0';
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  if (g_fPagesLocked == '\0') {
    MmLockPagableDataSection(PptpCmActivateVcComplete);
    g_fPagesLocked = '\x01';
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(puVar3 + 1);
  cVar4 = Pptpv4Initialized;
  *(undefined1 *)(puVar3 + 2) = uVar5;
  KeReleaseSpinLock(puVar3 + 1,uVar5);
  if (cVar4 == '\0') {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
    }
    uVar7 = PptpInitialize((longlong)puVar3);
    if ((int)uVar7 == 0) goto LAB_1c0017cdd;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c0017ec8;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
              &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
    }
  }
  else {
LAB_1c0017cdd:
    if ((piVar2 == (int *)0x0) || (piVar2[0xc] != 0x43505450)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
      }
      iVar6 = -0x3ffeffeb;
    }
    else {
      piVar1 = piVar2 + 0x18;
      uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
      *(undefined1 *)(piVar2 + 0x1a) = uVar5;
      if (piVar2[0x1c] == 3) {
        CallSetState((longlong)piVar2,7,param_3,'\x01');
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        NdisSetTimerObject(*(undefined8 *)(piVar2 + 0x80),0xffffffffdc3cba00,0,0);
        KeReleaseSpinLock(piVar1,(char)piVar2[0x1a]);
        param_3 = piVar2 + 0x46;
        iVar6 = CtlConnectCall(puVar3,piVar2,(short *)param_3,local_res8);
        uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
        *(undefined1 *)(piVar2 + 0x1a) = uVar5;
        if (local_res8[0] != '\0') {
          param_3 = (int *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar5);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar8 = &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                    &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
            param_3 = (int *)CONCAT71((int7)((ulonglong)puVar8 >> 8),(char)piVar2[0x1a]);
          }
          piVar2[0x6a] = piVar2[0x6a] | 0x4000;
          uVar5 = SUB81(param_3,0);
        }
        *(undefined2 *)((longlong)piVar2 + 0x11a) = 0x2f00;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                   &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,piVar2[0x1c]);
        }
        uVar5 = (undefined1)piVar2[0x1a];
        iVar6 = -0x3ffeffeb;
      }
      KeReleaseSpinLock(piVar1,uVar5);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (int *)&WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids,iVar6);
  }
  if ((iVar6 != 0) && (iVar6 != 0x103)) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(piVar2 + 0x18);
    piVar2[0x94] = iVar6;
    uVar7 = 0;
    *(undefined1 *)(piVar2 + 0x1a) = uVar5;
    CallSetState((longlong)piVar2,0xb,param_3,'\x01');
    uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),(char)piVar2[0x1a]);
    KeReleaseSpinLock(piVar2 + 0x18);
    CallCleanup(piVar2,uVar7,(undefined *)param_3);
  }
LAB_1c0017ec8:
  DereferenceRefCount(piVar2);
  return;
}



===== PptpCmModifyCallQoS @ 1c0017ef0 =====

undefined8 PptpCmModifyCallQoS(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
            &WPP_f450b4e5050132c4a75abfc0bd41f06e_Traceguids);
  }
  return 0;
}



===== StrDupAsciiToUnicode @ 1c0017f38 =====

short * StrDupAsciiToUnicode(char *param_1)

{
  char cVar1;
  short *psVar2;
  undefined4 *puVar3;
  short *psVar4;
  longlong lVar5;
  undefined8 local_18;
  undefined8 local_10;
  
  psVar2 = (short *)0x0;
  if (*param_1 != '\0') {
    local_10 = 0x10;
    local_18 = 1;
    puVar3 = (undefined4 *)ExAllocatePool3(0x40,0x94,0x49705450,&local_18,1);
    if (puVar3 == (undefined4 *)0x0) {
      psVar2 = (short *)0x0;
    }
    else {
      *puVar3 = 0x84;
      puVar3[1] = 0xc0bbc0de;
      psVar2 = (short *)(puVar3 + 4);
      if (psVar2 != (short *)0x0) {
        lVar5 = 0x41;
        psVar4 = psVar2;
        do {
          cVar1 = *param_1;
          param_1 = param_1 + 1;
          *psVar4 = (short)cVar1;
          psVar4 = psVar4 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        *(undefined2 *)((longlong)puVar3 + 0x92) = 0;
      }
    }
  }
  return psVar2;
}



===== CallReceiveDatagramCallback @ 1c0017fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CallReceiveDatagramCallback(longlong *param_1,longlong param_2,longlong *param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  longlong lVar6;
  undefined1 uVar7;
  int iVar8;
  char *pcVar9;
  undefined8 uVar10;
  longlong lVar11;
  char *pcVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  ulonglong uVar16;
  ushort uVar17;
  int iVar18;
  ulonglong uVar19;
  uint uVar20;
  undefined1 auStackY_138 [32];
  uint local_100;
  uint local_fc;
  char *local_f8;
  char *local_f0;
  undefined1 local_e8 [80];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  piVar14 = (int *)0x0;
  lVar11 = *param_1;
  psVar5 = *(short **)(param_2 + 8);
  lVar6 = *(longlong *)(lVar11 + 0x40);
  sVar3 = *psVar5;
  local_100 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  if (sVar3 == 2) {
    LOCK();
    _DAT_1c000c400 = _DAT_1c000c400 + 1;
    UNLOCK();
    uVar10 = 0;
    uVar4 = *(uint *)(param_3[1] + 0x18);
    local_fc = uVar4;
    pcVar9 = (char *)NdisGetDataBuffer(param_3[1],(ulonglong)uVar4,0,1);
    local_f0 = pcVar9;
    if (pcVar9 == (char *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      iVar8 = -0x3ffffde5;
      LOCK();
      _DAT_1c000c410 = _DAT_1c000c410 + 1;
      UNLOCK();
      goto LAB_1c001824a;
    }
    uVar10 = ProcessIpv4AddressFromPacket(pcVar9,uVar4,uVar10,&local_100);
    iVar8 = (int)uVar10;
    if ((iVar8 < 0) || (uVar16 = (ulonglong)local_100, (ulonglong)uVar4 < uVar16 + 0xc)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))
         )) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      LOCK();
      _DAT_1c000c410 = _DAT_1c000c410 + 1;
      UNLOCK();
      goto LAB_1c0018240;
    }
    bVar1 = pcVar9[uVar16];
    local_f8 = pcVar9 + uVar16;
    bVar2 = local_f8[1];
    iVar13 = ((uint)((longlong)(char)bVar2 >> 0x3f) & 4) + ((bVar1 & 0x10 | 0x20) >> 2);
    iVar18 = (uVar4 - iVar13) - local_100;
    uVar20 = iVar13 + local_100;
    piVar15 = piVar14;
    if (((((uVar4 < uVar20) ||
          (iVar18 < (int)(uint)(ushort)(*(ushort *)(local_f8 + 4) >> 8 |
                                       *(ushort *)(local_f8 + 4) << 8))) || ((bVar1 & 0x6f) != 0x20)
         ) || (((char)bVar1 < '\0' || ((bVar2 & 7) != 1)))) ||
       (((bVar2 & 0x78) != 0 || (*(short *)(local_f8 + 2) != 0xb88)))) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      iVar8 = -0x3fffffff;
      LOCK();
      _DAT_1c000c414 = _DAT_1c000c414 + 1;
      UNLOCK();
      if (uVar4 < uVar20) {
        LOCK();
        _DAT_1c000c418 = _DAT_1c000c418 + 1;
        UNLOCK();
      }
      else if (iVar18 < (int)(uint)(ushort)(*(ushort *)(local_f8 + 4) >> 8 |
                                           *(ushort *)(local_f8 + 4) << 8)) {
        LOCK();
        _DAT_1c000c41c = _DAT_1c000c41c + 1;
        UNLOCK();
      }
    }
    else {
      uVar17 = *(ushort *)(local_f8 + 6) >> 8 | *(ushort *)(local_f8 + 6) << 8;
      if (PptpClientSide == '\0') {
        uVar19 = (ulonglong)uVar17;
      }
      else {
        uVar19 = (ulonglong)(uVar17 & 0x3fff);
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar11 + 8);
      *(undefined1 *)(lVar11 + 0x10) = uVar7;
      if ((uVar19 < PptpBaseCallId) || (PptpMaxCallId <= uVar19)) {
LAB_1c0018198:
        KeReleaseSpinLock(lVar11 + 8,*(undefined1 *)(lVar11 + 0x10));
        piVar15 = piVar14;
      }
      else {
        if (PptpCallIdMaskSet == '\0') {
          piVar15 = *(int **)(*(longlong *)(lVar11 + 0x20) + (uVar19 - PptpBaseCallId) * 8);
          if (piVar15 != (int *)0x0) goto LAB_1c0018281;
          goto LAB_1c0018198;
        }
        if ((((ulonglong)PptpWanEndpoints <= (PptpCallIdMask & uVar19)) ||
            (piVar15 = *(int **)(*(longlong *)(lVar11 + 0x20) + (PptpCallIdMask & uVar19) * 8),
            piVar15 == (int *)0x0)) || (*(ulonglong *)(piVar15 + 0x34) != uVar19))
        goto LAB_1c0018198;
LAB_1c0018281:
        if (piVar15[0xc] != 0x43505450) goto LAB_1c0018198;
        LOCK();
        *piVar15 = *piVar15 + 1;
        UNLOCK();
        KeReleaseSpinLock(lVar11 + 8,*(undefined1 *)(lVar11 + 0x10));
        if (piVar15[0xc] == 0x43505450) {
          LOCK();
          piVar15[0x9a] = piVar15[0x9a] + 1;
          UNLOCK();
          piVar14 = piVar15;
          if (PptpValidateAddress == 0) goto LAB_1c00182ca;
          if (*psVar5 == (short)piVar15[0x46]) {
            if (*psVar5 == 2) {
              uVar16 = 4;
              lVar11 = RtlCompareMemory(psVar5 + 2,piVar15 + 0x47);
              if (lVar11 != 4) goto LAB_1c00184e5;
            }
            else {
              uVar16 = 0x10;
              lVar11 = RtlCompareMemory(psVar5 + 4,piVar15 + 0x48);
              if (lVar11 != 0x10) goto LAB_1c00184e5;
            }
LAB_1c00182ca:
            lVar11 = param_3[2];
            uVar16 = (ulonglong)*(ushort *)(lVar11 + 10);
            *(char **)(uVar16 + 0x10 + lVar11) = local_f0;
            *(char **)(uVar16 + 0x18 + lVar11) = local_f8;
            *(uint *)(uVar16 + 0x28 + lVar11) = local_fc;
            *(longlong *)(uVar16 + 0x20 + lVar11) = lVar6;
            uVar10 = CallQueueReceiveNBL(piVar15,param_3);
            if ((int)uVar10 == 0) goto LAB_1c0018312;
          }
          else {
LAB_1c00184e5:
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              pcVar9 = (char *)GetStringFromSockAddr((short *)(piVar15 + 0x46),local_e8);
              pcVar12 = (char *)GetStringFromSockAddr(psVar5,local_98);
              WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,uVar16,pcVar12,pcVar9);
            }
            iVar8 = -0x3fffffff;
            LOCK();
            _DAT_1c000c424 = _DAT_1c000c424 + 1;
            UNLOCK();
            LOCK();
            piVar15[0xa4] = piVar15[0xa4] + 1;
            UNLOCK();
            if ((((*(char *)((longlong)piVar15 + 0xc2) != '\0') &&
                 ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              pcVar9 = (char *)GetStringFromSockAddr((short *)(piVar15 + 0x46),local_e8);
              pcVar12 = (char *)GetStringFromSockAddr(psVar5,local_98);
              WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,uVar16,pcVar12,pcVar9);
            }
          }
          goto LAB_1c001824a;
        }
      }
      iVar8 = -0x3fffffff;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      LOCK();
      _DAT_1c000c420 = _DAT_1c000c420 + 1;
      UNLOCK();
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    }
LAB_1c0018240:
    iVar8 = -0x3fffffff;
LAB_1c001824a:
    piVar15 = piVar14;
  }
  ReceiveDataComplete(lVar6,(longlong)param_3);
LAB_1c0018312:
  if (iVar8 != 0) {
    if (piVar15 != (int *)0x0) {
      LOCK();
      piVar15[0x9c] = piVar15[0x9c] + 1;
      UNLOCK();
    }
    LOCK();
    DAT_1c000c404 = DAT_1c000c404 + 1;
    UNLOCK();
  }
  if ((piVar15 != (int *)0x0) && (piVar15[0xc] == 0x43505450)) {
    LOCK();
    iVar13 = *piVar15;
    *piVar15 = *piVar15 + -1;
    UNLOCK();
    if (iVar13 == 1) {
      (**(code **)(piVar15 + 2))(piVar15);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar8);
  }
  return iVar8;
}



===== CallQueueReceiveNBL @ 1c00186e0 =====

undefined8 CallQueueReceiveNBL(int *param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  
  pbVar3 = *(byte **)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x18 + param_2[2]);
  if ((*pbVar3 & 0x10) == 0) {
    LOCK();
    param_1[0x9c] = param_1[0x9c] + 1;
    UNLOCK();
    LOCK();
    param_1[0xa0] = param_1[0xa0] + 1;
    UNLOCK();
    LOCK();
    DAT_1c000c404 = DAT_1c000c404 + 1;
    UNLOCK();
    return 0xc0000001;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x1a) = uVar6;
  if ((ushort)(*(ushort *)(pbVar3 + 6) >> 8 | *(ushort *)(pbVar3 + 6) << 8) ==
      *(ushort *)(param_1 + 0x50)) {
    if (param_1[0x1c] == 9) {
      if ((*(longlong *)(param_1 + 0x14) != 0) &&
         (*(int *)(*(longlong *)(param_1 + 0x14) + 0x30) != 7)) {
        LOCK();
        param_1[8] = param_1[8] + 1;
        UNLOCK();
        param_1[0x2e] = param_1[0x2e] + 1;
        KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
        uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2a);
        plVar4 = *(longlong **)(param_1 + 0x26);
        *(undefined1 *)(param_1 + 0x2c) = uVar6;
        if (plVar4 == (longlong *)0x0) {
          *(longlong **)(param_1 + 0x26) = param_2;
        }
        else {
          uVar1 = *(uint *)(pbVar3 + 8);
          plVar5 = plVar4;
          plVar9 = (longlong *)0x0;
          while (plVar8 = plVar5, plVar8 != (longlong *)0x0) {
            uVar2 = *(uint *)(*(longlong *)
                               ((ulonglong)*(ushort *)(plVar8[2] + 10) + 0x18 + plVar8[2]) + 8);
            if (0 < (int)((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                          uVar2 << 0x18) -
                         (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                         uVar1 << 0x18))) {
              if (plVar9 == (longlong *)0x0) {
                *param_2 = (longlong)plVar4;
                *(longlong **)(param_1 + 0x26) = param_2;
              }
              else {
                *param_2 = *plVar9;
                *plVar9 = (longlong)param_2;
              }
              goto LAB_1c00187b8;
            }
            plVar9 = plVar8;
            plVar5 = (longlong *)*plVar8;
          }
          **(undefined8 **)(param_1 + 0x28) = param_2;
        }
        *(longlong **)(param_1 + 0x28) = param_2;
LAB_1c00187b8:
        if ((char)param_1[0x92] == '\0') {
          *(undefined1 *)(param_1 + 0x92) = 1;
          LOCK();
          *param_1 = *param_1 + 1;
          UNLOCK();
          NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0x98),CallProcessRxNBLs,param_1);
        }
        KeReleaseSpinLock(param_1 + 0x2a,(char)param_1[0x2c]);
        return 0;
      }
      goto LAB_1c001881f;
    }
  }
  else {
LAB_1c001881f:
    if (param_1[0x1c] == 9) {
      KeReleaseSpinLock(param_1 + 0x18,uVar6);
      lVar7 = 0x288;
      goto LAB_1c001883a;
    }
  }
  KeReleaseSpinLock(param_1 + 0x18);
  lVar7 = 0x284;
LAB_1c001883a:
  LOCK();
  *(int *)(lVar7 + (longlong)param_1) = *(int *)(lVar7 + (longlong)param_1) + 1;
  UNLOCK();
  LOCK();
  param_1[0x9c] = param_1[0x9c] + 1;
  UNLOCK();
  LOCK();
  DAT_1c000c404 = DAT_1c000c404 + 1;
  UNLOCK();
  return 0xc0000001;
}



===== CallProcessNBLs @ 1c0018900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CallProcessNBLs(int *param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int local_res18;
  int local_res20;
  
  local_res20 = 0;
  uVar7 = 0;
  uVar8 = 0;
  iVar6 = 0x32;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = (undefined8 *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
  *(undefined1 *)(param_1 + 0x24) = uVar4;
  do {
    iVar6 = iVar6 + -1;
    puVar3 = *(undefined8 **)(param_1 + 0x1e);
    if (puVar3 == (undefined8 *)0x0) break;
    *(undefined8 *)(param_1 + 0x1e) = *puVar3;
    *puVar3 = 0;
    local_res18 = 0;
    if (*(longlong *)(param_1 + 0x1e) == 0) {
      param_1[0x20] = 0;
      param_1[0x21] = 0;
    }
    KeReleaseSpinLock(param_1 + 0x22,(char)param_1[0x24]);
    *(undefined4 *)((longlong)puVar3 + 0x8c) = 0;
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x1a) = uVar4;
    bVar10 = puVar3 == *(undefined8 **)(param_1 + 0x78);
    if (bVar10) {
      param_1[0x72] = param_1[0x72] + 1;
      LOCK();
      param_1[0xaa] = param_1[0xaa] + 1;
      UNLOCK();
    }
    KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
    for (puVar5 = (undefined8 *)puVar3[1]; puVar5 != (undefined8 *)0x0;
        puVar5 = (undefined8 *)*puVar5) {
      local_res18 = local_res18 + 1;
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      param_1[0x2f] = param_1[0x2f] + -1;
      uVar9 = 0;
      iVar2 = param_1[0x44];
      *(undefined1 *)(param_1 + 0x1a) = uVar4;
      if (param_1[0x52] != iVar2) {
        uVar9 = 2;
        param_1[0x52] = iVar2;
        uVar7 = iVar2 - 1;
      }
      KeReleaseSpinLock(param_1 + 0x18,uVar4);
      if (bVar10) {
        if (uVar9 != 0) goto LAB_1c0018a7c;
        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        param_1[0x72] = param_1[0x72] + 1;
        *(undefined1 *)(param_1 + 0x1a) = uVar4;
        *(undefined1 *)(param_1 + 0x74) = 0;
        KeReleaseSpinLock(param_1 + 0x18,uVar4);
        LOCK();
        param_1[0xab] = param_1[0xab] + 1;
        UNLOCK();
        DereferenceRefCount(param_1 + 8);
      }
      else {
        uVar8 = param_1[0x51];
        uVar9 = uVar9 | 1;
        param_1[0x51] = uVar8 + 1;
LAB_1c0018a7c:
        param_3 = puVar5;
        local_res20 = CallTransmitNB(param_1,(longlong)puVar3,(longlong)puVar5,uVar9,uVar8,uVar7,
                                     bVar10);
        if (local_res20 != 0x103) {
          local_res18 = *(int *)(puVar3 + 0xc) - local_res18;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,param_3,param_1,
                       (char)param_1[0x32],(char)local_res20);
          }
          if (bVar10) {
            uVar4 = KeAcquireSpinLockRaiseToDpc();
            *(undefined1 *)(param_1 + 0x74) = 0;
            *(undefined1 *)(param_1 + 0x1a) = uVar4;
            KeReleaseSpinLock(param_1 + 0x18,uVar4);
            LOCK();
            param_1[0xab] = param_1[0xab] + 1;
            UNLOCK();
            goto LAB_1c0018d9a;
          }
          *(undefined4 *)((longlong)puVar3 + 0x8c) = 0xc0000001;
          LOCK();
          param_1[0xa7] = param_1[0xa7] + local_res18;
          UNLOCK();
          LOCK();
          DAT_1c000c3fc = DAT_1c000c3fc + local_res18;
          UNLOCK();
          uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
          param_1[0x2f] = param_1[0x2f] - local_res18;
          *(undefined1 *)(param_1 + 0x1a) = uVar4;
          KeReleaseSpinLock(param_1 + 0x18,uVar4);
          goto LAB_1c0018aca;
        }
      }
    }
    if (!bVar10) {
LAB_1c0018aca:
      LOCK();
      piVar1 = (int *)(puVar3 + 0xe);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,param_3,param_1,
                     (char)param_1[0x32],(char)local_res20);
        }
        param_3 = (undefined8 *)0x0;
        NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x38),puVar3);
        DereferenceRefCount((int *)(*(longlong *)(param_1 + 0xe) + 0xc0));
LAB_1c0018d9a:
        DereferenceRefCount(param_1 + 8);
      }
    }
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
    *(undefined1 *)(param_1 + 0x24) = uVar4;
  } while (iVar6 != 0);
  if (*(longlong *)(param_1 + 0x1e) == 0) {
    *(undefined1 *)((longlong)param_1 + 0xc3) = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,param_3,param_1,(char)param_1[0x32]
                 ,(char)param_1[0x2f]);
    }
    KeReleaseSpinLock(param_1 + 0x22,(char)param_1[0x24]);
    LOCK();
    iVar6 = *param_1;
    *param_1 = *param_1 + -1;
    UNLOCK();
    if (iVar6 == 1) {
      (**(code **)(param_1 + 2))(param_1);
    }
  }
  else {
    NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0x96),CallProcessNBLs,param_1);
    KeReleaseSpinLock(param_1 + 0x22,(char)param_1[0x24]);
  }
  return;
}



===== CallTransmitNB @ 1c0018df0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CallTransmitNB(int *param_1,longlong param_2,longlong param_3,uint param_4,uint param_5,
                  uint param_6,char param_7)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined1 auStackY_c8 [32];
  undefined7 in_stack_ffffffffffffff61;
  undefined2 local_80 [20];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  iVar4 = -0x3fffffff;
  iVar7 = -0x3fffffff;
  iVar1 = *(int *)(&GreSize + (ulonglong)(param_4 & 3) * 4);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x1a) = uVar3;
  if (param_1[0x1c] != 9) {
    KeReleaseSpinLock(param_1 + 0x18,uVar3);
    LOCK();
    param_1[0xa9] = param_1[0xa9] + 1;
    UNLOCK();
    goto LAB_1c0018fc4;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xe) + 0x40);
  KeReleaseSpinLock();
  if ((short)param_1[0x46] == 2) {
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        uVar6 = 0x69;
        goto LAB_1c00190f6;
      }
    }
    else {
      iVar1 = iVar1 + 0x14;
      iVar7 = *(int *)(param_3 + 0x18);
      iVar4 = NdisRetreatNetBufferDataStart(param_3,iVar1,0,0);
      if (iVar4 == 0) {
        *(int *)(param_3 + 0x88) = iVar1;
        *(longlong *)(param_3 + 0x80) = param_2;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                   &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar7);
        }
        puVar5 = (undefined2 *)NdisGetDataBuffer(param_3,iVar1,0,1);
        uVar8 = (ulonglong)param_4;
        uVar3 = 1;
        if (puVar5 == (undefined2 *)0x0) {
          PptpBuildIpGreHdrs(local_80,(longlong)param_1,param_4,param_5,param_6,'\x01',iVar7);
          uVar8 = (ulonglong)*(uint *)(param_3 + 0x10);
          RtlCopyBufferToMdl(local_80,*(undefined8 *)(param_3 + 8),uVar8,iVar1);
        }
        else {
          PptpBuildIpGreHdrs(puVar5,(longlong)param_1,param_4,param_5,param_6,'\x01',iVar7);
        }
        if (param_7 == '\0') {
          LOCK();
          *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + 1;
          UNLOCK();
        }
        else {
          LOCK();
          *param_1 = *param_1 + 1;
          UNLOCK();
        }
        LOCK();
        param_1[0xa5] = param_1[0xa5] + 1;
        UNLOCK();
        LOCK();
        DAT_1c000c3f0 = DAT_1c000c3f0 + 1;
        UNLOCK();
        WskSendDatagram(lVar2,(longlong)(param_1 + 0x46),uVar8,param_3,(longlong)param_1,
                        CONCAT71(in_stack_ffffffffffffff61,uVar3),param_3);
        iVar7 = 0x103;
        goto LAB_1c0018fc4;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                 &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar4);
      }
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
          (WPP_GLOBAL_Control[0x29] != '\0')) {
    uVar6 = 0x68;
LAB_1c00190f6:
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    LOCK();
    param_1[0xa9] = param_1[0xa9] + 1;
    UNLOCK();
    iVar7 = -0x3fffffff;
    goto LAB_1c0018fc4;
  }
  LOCK();
  param_1[0xa9] = param_1[0xa9] + 1;
  UNLOCK();
  iVar7 = iVar4;
LAB_1c0018fc4:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar7);
  }
  return iVar7;
}



===== PptpBuildIpGreHdrs @ 1c00191d0 =====

int PptpBuildIpGreHdrs(undefined2 *param_1,longlong param_2,uint param_3,uint param_4,uint param_5,
                      char param_6,int param_7)

{
  int iVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined2 *puVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])
       ) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
              &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_7);
    }
  }
  iVar1 = *(int *)(&GreSize + (ulonglong)(param_3 & 3) * 4);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar1 + param_7);
  }
  puVar4 = (undefined2 *)0x0;
  if (param_6 != '\0') {
    uVar7 = 0x14;
    iVar6 = iVar1 + param_7 + 0x14;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,iVar6);
    }
    *param_1 = 0x45;
    *(undefined4 *)(param_1 + 2) = 0;
    *(undefined4 *)(param_1 + 4) = 0x2f80;
    uVar5 = (ushort)iVar6;
    param_1[1] = uVar5 >> 8 | uVar5 << 8;
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(*(longlong *)(param_2 + 0x50) + 0x21c);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x11c);
    puVar4 = param_1;
  }
  puVar2 = (undefined8 *)((ulonglong)uVar7 + (longlong)puVar4);
  *puVar2 = 0xb880120;
  puVar3 = (uint *)(puVar2 + 1);
  if ((param_3 & 1) != 0) {
    *(undefined1 *)puVar2 = 0x30;
    *puVar3 = param_4 >> 0x18 | (param_4 & 0xff0000) >> 8 | (param_4 & 0xff00) << 8 |
              param_4 << 0x18;
    puVar3 = (uint *)((longlong)puVar2 + 0xc);
  }
  *(ushort *)((longlong)puVar2 + 4) = (ushort)param_7 >> 8 | (ushort)param_7 << 8;
  *(ushort *)((longlong)puVar2 + 6) =
       *(ushort *)(param_2 + 0x13c) >> 8 | *(ushort *)(param_2 + 0x13c) << 8;
  if ((param_3 & 2) != 0) {
    *(byte *)((longlong)puVar2 + 1) = *(byte *)((longlong)puVar2 + 1) | 0x80;
    *puVar3 = param_5 >> 0x18 | (param_5 & 0xff0000) >> 8 | (param_5 & 0xff00) << 8 |
              param_5 << 0x18;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,uVar7 + iVar1);
  }
  return uVar7 + iVar1;
}



===== CallProcessRxNBLs @ 1c0019460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CallProcessRxNBLs(int *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  byte *pbVar7;
  bool bVar8;
  undefined1 uVar9;
  byte bVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  lVar12 = 0x32;
  uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2a);
  *(undefined1 *)(param_1 + 0x2c) = uVar9;
  do {
    puVar5 = *(undefined8 **)(param_1 + 0x26);
    lVar12 = lVar12 + -1;
    if (puVar5 == (undefined8 *)0x0) break;
    *(undefined8 *)(param_1 + 0x26) = *puVar5;
    *puVar5 = 0;
    if (*(longlong *)(param_1 + 0x26) == 0) {
      param_1[0x28] = 0;
      param_1[0x29] = 0;
    }
    KeReleaseSpinLock(param_1 + 0x2a,(char)param_1[0x2c]);
    lVar11 = (ulonglong)*(ushort *)(puVar5[2] + 10) + puVar5[2];
    lVar6 = *(longlong *)(lVar11 + 0x20);
    bVar10 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    param_1[0x2e] = param_1[0x2e] + -1;
    param_3 = (undefined *)(ulonglong)bVar10;
    *(byte *)(param_1 + 0x1a) = bVar10;
    if (param_1[0x1c] == 9) {
      pbVar7 = *(byte **)(lVar11 + 0x18);
      if ((ushort)(*(ushort *)(pbVar7 + 6) >> 8 | *(ushort *)(pbVar7 + 6) << 8) ==
          *(ushort *)(param_1 + 0x50)) {
        bVar8 = false;
        if ((*pbVar7 & 0x10) != 0) {
          uVar4 = *(uint *)(pbVar7 + 8);
          param_1[0x44] =
               (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18) + 1
          ;
          if (((param_1[0x2f] == 0) && ((char)param_1[0x74] == '\0')) &&
             (*(short *)(*(longlong *)(lVar11 + 0x18) + 4) != 0)) {
            *(undefined1 *)(param_1 + 0x74) = 1;
            bVar8 = true;
          }
        }
        KeReleaseSpinLock(param_1 + 0x18,param_3);
        if (PptpEchoAlways == '\0') {
          *(undefined1 *)(*(longlong *)(param_1 + 0x14) + 0x24c) = 0;
        }
        if (bVar8) {
          LOCK();
          *param_1 = *param_1 + 1;
          UNLOCK();
          param_3 = (undefined *)0x0;
          NdisSetTimerObject(*(undefined8 *)(param_1 + 0x70),0xfffffffffff0bdc0,0,0);
        }
        uVar3 = *(ushort *)(*(byte **)(lVar11 + 0x18) + 4);
        if ((uVar3 >> 8 != 0 || (uVar3 & 0xff) != 0) && ((**(byte **)(lVar11 + 0x18) & 0x10) != 0))
        {
          local_res8 = (undefined8 *)0x0;
          CallIndicateReceived(param_1,(longlong)puVar5,param_3);
        }
      }
      else {
        KeReleaseSpinLock(param_1 + 0x18,param_3);
        LOCK();
        param_1[0x9c] = param_1[0x9c] + 1;
        UNLOCK();
        LOCK();
        param_1[0xa3] = param_1[0xa3] + 1;
        UNLOCK();
        LOCK();
        DAT_1c000c404 = DAT_1c000c404 + 1;
        UNLOCK();
        local_res8 = puVar5;
      }
    }
    else {
      KeReleaseSpinLock(param_1 + 0x18,param_3);
      lVar12 = 100;
      LOCK();
      param_1[0x9c] = param_1[0x9c] + 1;
      UNLOCK();
      LOCK();
      param_1[0x9f] = param_1[0x9f] + 1;
      UNLOCK();
      LOCK();
      DAT_1c000c404 = DAT_1c000c404 + 1;
      UNLOCK();
      local_res8 = puVar5;
    }
    piVar1 = param_1 + 8;
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_1 + 10))();
    }
    ReceiveDataComplete(lVar6,(longlong)local_res8);
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2a);
    *(undefined1 *)(param_1 + 0x2c) = uVar9;
  } while (lVar12 != 0);
  if (*(longlong *)(param_1 + 0x26) == 0) {
    *(undefined1 *)(param_1 + 0x92) = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,param_3,param_1,(char)param_1[0x32]
                 ,(char)param_1[0x2e]);
    }
    KeReleaseSpinLock(param_1 + 0x2a,(char)param_1[0x2c]);
    LOCK();
    iVar2 = *param_1;
    *param_1 = *param_1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_1 + 2))(param_1);
      return;
    }
  }
  else {
    NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0x98),CallProcessRxNBLs,param_1);
    KeReleaseSpinLock(param_1 + 0x2a,(char)param_1[0x2c]);
  }
  return;
}



===== CallIndicateReceived @ 1c0019820 =====

void CallIndicateReceived(int *param_1,longlong param_2,undefined *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  byte *pbVar6;
  char cVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  int iVar12;
  longlong lVar13;
  
  lVar13 = (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x10) + 10) +
           *(longlong *)(param_2 + 0x10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
             &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1);
  }
  lVar5 = *(longlong *)(param_1 + 0xe);
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar5 + 8);
  *(undefined1 *)(lVar5 + 0x10) = uVar8;
  lVar10 = *(longlong *)(param_1 + 0xe);
  uVar9 = MiniportCheckAdapterState(lVar10);
  if ((int)uVar9 == 0) {
    LOCK();
    *(int *)(lVar10 + 0xc0) = *(int *)(lVar10 + 0xc0) + 1;
    UNLOCK();
    uVar11 = (ulonglong)*(byte *)(lVar5 + 0x10);
    KeReleaseSpinLock(lVar5 + 8);
    pbVar6 = *(byte **)(lVar13 + 0x18);
    bVar1 = *pbVar6;
    bVar2 = pbVar6[1];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar3 = *(uint *)(pbVar6 + 8);
      param_3 = &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      uVar11 = 0x6f;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18);
    }
    iVar12 = 0x20;
    if ((bVar1 & 0x10) == 0) {
      iVar12 = 0x1c;
    }
    iVar12 = iVar12 + ((uint)((longlong)(char)bVar2 >> 0x3f) & 4);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = *(undefined4 *)(lVar13 + 0x28);
      cVar7 = (char)iVar12;
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,param_3,uVar4,cVar7,
                 (char)uVar4 - cVar7);
    }
    NdisAdvanceNetBufferListDataStart(param_2,iVar12,0,0);
    *(undefined4 *)(param_2 + 0x8c) = 0;
    uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x1a) = uVar8;
    if (((param_1[0x6a] & 4U) == 0) || ((param_1[0x6b] & 0x400U) != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
                 &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1);
      }
      KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
      NdisFreeNetBufferList(param_2);
      DereferenceRefCount((int *)(*(longlong *)(param_1 + 0xe) + 0xc0));
    }
    else {
      LOCK();
      *param_1 = *param_1 + 1;
      UNLOCK();
      *(int **)(param_2 + 0x60) = param_1;
      LOCK();
      param_1[8] = param_1[8] + 1;
      UNLOCK();
      *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_1 + 0x38);
      KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids);
      }
      NdisMCoIndicateReceiveNetBufferLists(*(undefined8 *)(param_1 + 0x38),param_2,1);
      LOCK();
      DAT_1c000c430 = DAT_1c000c430 + 1;
      UNLOCK();
      LOCK();
      param_1[0x9b] = param_1[0x9b] + 1;
      UNLOCK();
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_1);
    }
    KeReleaseSpinLock(lVar5 + 8,*(undefined1 *)(lVar5 + 0x10));
    NdisFreeNetBufferList(param_2);
  }
  return;
}



===== CallpSendComplete @ 1c0019b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CallpSendComplete(undefined8 param_1,longlong param_2,int *param_3,undefined8 param_4,
                      undefined8 param_5,int param_6)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  int *piVar6;
  longlong lVar7;
  
  bVar3 = false;
  piVar6 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,param_3,param_3,(char)param_2,
               (char)param_6);
  }
  lVar2 = *(longlong *)(param_2 + 0x80);
  if (param_6 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      piVar6 = (int *)&WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
               &WPP_922920b7a74b3f0a61082735ce41b87f_Traceguids,param_6);
    }
    *(undefined4 *)(lVar2 + 0x8c) = 0xc0000001;
    LOCK();
    _DAT_1c000c3f8 = _DAT_1c000c3f8 + 1;
    UNLOCK();
    LOCK();
    param_3[0xa8] = param_3[0xa8] + 1;
    UNLOCK();
  }
  if (lVar2 == *(longlong *)(param_3 + 0x78)) {
    NdisAdvanceNetBufferDataStart(param_2,*(undefined4 *)(param_2 + 0x88),0,0);
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x18);
    param_3[0x73] = param_3[0x73] + 1;
    *(undefined1 *)(param_3 + 0x1a) = uVar4;
    *(undefined1 *)(param_3 + 0x74) = 0;
    KeReleaseSpinLock(param_3 + 0x18,uVar4);
    LOCK();
    _DAT_1c000c3f4 = _DAT_1c000c3f4 + 1;
    UNLOCK();
    LOCK();
    param_3[0xab] = param_3[0xab] + 1;
    UNLOCK();
    LOCK();
    param_3[0xa6] = param_3[0xa6] + 1;
    UNLOCK();
    DereferenceRefCount(param_3);
    DereferenceRefCount(param_3 + 8);
    return;
  }
  lVar7 = CONCAT71((int7)((ulonglong)piVar6 >> 8),1);
  NdisAdvanceNetBufferDataStart();
  LOCK();
  _DAT_1c000c3f4 = _DAT_1c000c3f4 + 1;
  UNLOCK();
  LOCK();
  param_3[0xa6] = param_3[0xa6] + 1;
  UNLOCK();
  LOCK();
  piVar6 = (int *)(lVar2 + 0x70);
  iVar1 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar1 != 1) {
    return;
  }
  LOCK();
  piVar6 = param_3 + 0x7e;
  iVar1 = *piVar6;
  *piVar6 = *piVar6 + 1;
  UNLOCK();
  if ((iVar1 + 1 < 5) ||
     (lVar7 = lVar2, uVar5 = ScheduleWorkItem(CallpSendCompleteDeferred,param_3,lVar2,param_6),
     (int)uVar5 != 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,lVar7,param_3,(char)lVar2,
                 (char)param_6);
    }
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_3 + 0x38),lVar2,0);
    lVar2 = *(longlong *)(param_3 + 0xe);
    bVar3 = true;
    piVar6 = (int *)(lVar2 + 0xc0);
    LOCK();
    iVar1 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      (**(code **)(lVar2 + 200))();
      LOCK();
      param_3[0x7e] = param_3[0x7e] + -1;
      UNLOCK();
      goto LAB_1c0019c92;
    }
  }
  LOCK();
  param_3[0x7e] = param_3[0x7e] + -1;
  UNLOCK();
  if (!bVar3) {
    return;
  }
LAB_1c0019c92:
  piVar6 = param_3 + 8;
  LOCK();
  iVar1 = *piVar6;
  *piVar6 = *piVar6 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(param_3 + 10))();
  }
  return;
}



===== CallQueueTransmitNBLs @ 1c0019e00 =====

undefined8 CallQueueTransmitNBLs(int *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  int iVar6;
  
  if ((param_1 == (int *)0x0) || (param_1[0xc] != 0x43505450)) {
    uVar5 = 0xc0000001;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x1a) = uVar4;
    if (param_1[0x1c] == 9) {
      KeReleaseSpinLock();
      puVar3 = param_2;
      puVar1 = (undefined8 *)0x0;
      while (puVar2 = puVar3, puVar2 != (undefined8 *)0x0) {
        iVar6 = 0;
        for (puVar1 = (undefined8 *)puVar2[1]; puVar1 != (undefined8 *)0x0;
            puVar1 = (undefined8 *)*puVar1) {
          iVar6 = iVar6 + 1;
        }
        *(int *)(puVar2 + 0xc) = iVar6;
        *(undefined4 *)(puVar2 + 0xe) = 0;
        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
        param_1[0x2f] = param_1[0x2f] + iVar6;
        *(undefined1 *)(param_1 + 0x1a) = uVar4;
        LOCK();
        param_1[8] = param_1[8] + 1;
        UNLOCK();
        if (puVar2 != *(undefined8 **)(param_1 + 0x78)) {
          LOCK();
          *(int *)(puVar2 + 0xe) = *(int *)(puVar2 + 0xe) + 1;
          UNLOCK();
          LOCK();
          *(int *)(*(longlong *)(param_1 + 0xe) + 0xc0) =
               *(int *)(*(longlong *)(param_1 + 0xe) + 0xc0) + 1;
          UNLOCK();
        }
        KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
        puVar1 = puVar2;
        puVar3 = (undefined8 *)*puVar2;
      }
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
      *(undefined1 *)(param_1 + 0x24) = uVar4;
      if (*(longlong *)(param_1 + 0x1e) == 0) {
        *(undefined8 **)(param_1 + 0x1e) = param_2;
      }
      else {
        **(undefined8 **)(param_1 + 0x20) = param_2;
      }
      *(undefined8 **)(param_1 + 0x20) = puVar1;
      if (*(char *)((longlong)param_1 + 0xc3) == '\0') {
        *(undefined1 *)((longlong)param_1 + 0xc3) = 1;
        LOCK();
        *param_1 = *param_1 + 1;
        UNLOCK();
        NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0x96),CallProcessNBLs,param_1);
      }
      KeReleaseSpinLock(param_1 + 0x22,(char)param_1[0x24]);
      uVar5 = 0x103;
    }
    else {
      KeReleaseSpinLock(param_1 + 0x18,uVar4);
      uVar5 = 0xc0000001;
    }
  }
  return uVar5;
}



===== MiniportReturnNetBufferLists @ 1c0019fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MiniportReturnNetBufferLists(longlong param_1,longlong *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  longlong *plVar5;
  
  if (param_2 != (longlong *)0x0) {
    piVar2 = (int *)(param_1 + 0xc0);
    do {
      piVar4 = (int *)param_2[0xc];
      plVar5 = (longlong *)*param_2;
      piVar1 = piVar4 + 8;
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(piVar4 + 10))();
      }
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(piVar4 + 2))(piVar4);
      }
      NdisFreeNetBufferList(param_2);
      LOCK();
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(param_1 + 200))(piVar2);
      }
      LOCK();
      _DAT_1c000c434 = _DAT_1c000c434 + 1;
      UNLOCK();
      param_2 = plVar5;
    } while (plVar5 != (longlong *)0x0);
  }
  return;
}



===== PptpCoSendNetBufferLists @ 1c001a070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PptpCoSendNetBufferLists(int *param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  lVar1 = *(longlong *)(param_1 + 0xe);
  bVar4 = false;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 8);
  *(undefined1 *)(lVar1 + 0x10) = uVar6;
  uVar7 = MiniportCheckAdapterState(lVar1);
  iVar9 = (int)uVar7;
  if (iVar9 == 0) {
    LOCK();
    *(int *)(lVar1 + 0xc0) = *(int *)(lVar1 + 0xc0) + 1;
    UNLOCK();
    bVar4 = true;
    KeReleaseSpinLock(lVar1 + 8);
    if (param_1[0xc] == 0x43505450) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
      *(undefined1 *)(param_1 + 0x1a) = uVar6;
      if (param_1[0x1c] == 9) {
        KeReleaseSpinLock();
        puVar3 = param_2;
        puVar2 = (undefined8 *)0x0;
        while (puVar5 = puVar3, puVar5 != (undefined8 *)0x0) {
          iVar9 = 0;
          for (puVar2 = (undefined8 *)puVar5[1]; puVar2 != (undefined8 *)0x0;
              puVar2 = (undefined8 *)*puVar2) {
            iVar9 = iVar9 + 1;
          }
          *(int *)(puVar5 + 0xc) = iVar9;
          *(undefined4 *)(puVar5 + 0xe) = 0;
          uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
          param_1[0x2f] = param_1[0x2f] + iVar9;
          *(undefined1 *)(param_1 + 0x1a) = uVar6;
          LOCK();
          param_1[8] = param_1[8] + 1;
          UNLOCK();
          if (puVar5 != *(undefined8 **)(param_1 + 0x78)) {
            LOCK();
            *(int *)(puVar5 + 0xe) = *(int *)(puVar5 + 0xe) + 1;
            UNLOCK();
            LOCK();
            *(int *)(*(longlong *)(param_1 + 0xe) + 0xc0) =
                 *(int *)(*(longlong *)(param_1 + 0xe) + 0xc0) + 1;
            UNLOCK();
          }
          KeReleaseSpinLock(param_1 + 0x18,(char)param_1[0x1a]);
          puVar2 = puVar5;
          puVar3 = (undefined8 *)*puVar5;
        }
        uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
        *(undefined1 *)(param_1 + 0x24) = uVar6;
        if (*(longlong *)(param_1 + 0x1e) == 0) {
          *(undefined8 **)(param_1 + 0x1e) = param_2;
        }
        else {
          **(undefined8 **)(param_1 + 0x20) = param_2;
        }
        *(undefined8 **)(param_1 + 0x20) = puVar2;
        if (*(char *)((longlong)param_1 + 0xc3) == '\0') {
          *(undefined1 *)((longlong)param_1 + 0xc3) = 1;
          LOCK();
          *param_1 = *param_1 + 1;
          UNLOCK();
          NdisQueueIoWorkItem(*(undefined8 *)(param_1 + 0x96),CallProcessNBLs,param_1);
        }
        KeReleaseSpinLock(param_1 + 0x22,(char)param_1[0x24]);
        goto LAB_1c001a239;
      }
      KeReleaseSpinLock(param_1 + 0x18);
    }
    iVar9 = -0x3fffffff;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,0xc0000001);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar9);
    }
    KeReleaseSpinLock(lVar1 + 8);
  }
  puVar2 = param_2;
  if (iVar9 != 0x103) {
    for (; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
      puVar3 = (undefined8 *)puVar2[1];
      iVar8 = 0;
      *(int *)((longlong)puVar2 + 0x8c) = iVar9;
      for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3) {
        iVar8 = iVar8 + 1;
      }
      LOCK();
      param_1[0xa9] = param_1[0xa9] + iVar8;
      UNLOCK();
      LOCK();
      _DAT_1c000c428 = _DAT_1c000c428 + iVar8;
      UNLOCK();
    }
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x38),param_2,0);
  }
  if (!bVar4) {
    return;
  }
LAB_1c001a239:
  piVar10 = (int *)(lVar1 + 0xc0);
  LOCK();
  iVar9 = *piVar10;
  *piVar10 = *piVar10 + -1;
  UNLOCK();
  if (iVar9 == 1) {
    (**(code **)(lVar1 + 200))(piVar10);
  }
  return;
}



===== CallGetCall @ 1c001a390 =====

int * CallGetCall(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  int *piVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  if ((PptpBaseCallId <= param_2) && (param_2 < PptpMaxCallId)) {
    if (PptpCallIdMaskSet == '\0') {
      piVar2 = *(int **)(*(longlong *)(param_1 + 0x20) + (param_2 - PptpBaseCallId) * 8);
      if (piVar2 != (int *)0x0) goto LAB_1c001a454;
    }
    else if ((((PptpCallIdMask & param_2) < (ulonglong)PptpWanEndpoints) &&
             (piVar2 = *(int **)(*(longlong *)(param_1 + 0x20) + (PptpCallIdMask & param_2) * 8),
             piVar2 != (int *)0x0)) && (*(ulonglong *)(piVar2 + 0x34) == param_2)) {
LAB_1c001a454:
      if (piVar2[0xc] == 0x43505450) {
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        goto LAB_1c001a3ca;
      }
    }
  }
  piVar2 = (int *)0x0;
LAB_1c001a3ca:
  KeReleaseSpinLock(param_1 + 8,*(undefined1 *)(param_1 + 0x10));
  return piVar2;
}



===== AdapterAlloc @ 1c001b010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * AdapterAlloc(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined1 auStack_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  uStack_20 = 0;
  puVar3 = (undefined8 *)MyMemAlloc(0xd8,0x61505450);
  if (puVar3 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  *puVar3 = param_1;
  KeInitializeSpinLock(puVar3 + 1);
  uVar2 = PptpMaxTransmit;
  uVar5 = (ulonglong)PptpWanEndpoints;
  *(uint *)(puVar3 + 9) = PptpWanEndpoints;
  *(undefined4 *)(puVar3 + 10) = uVar2;
  *(undefined4 *)((longlong)puVar3 + 0x4c) = 0x578;
  *(undefined8 *)((longlong)puVar3 + 0x54) = 0x700;
  if (uVar5 * 8 < 0x100000000) {
    lVar4 = MyMemAlloc((int)(uVar5 * 8),0x63505450);
    puVar3[4] = lVar4;
    if (lVar4 != 0) {
      uVar7 = 0;
      if (*(int *)(puVar3 + 9) != 0) {
        do {
          uVar5 = (ulonglong)uVar7;
          uVar7 = uVar7 + 1;
          *(undefined8 *)(puVar3[4] + uVar5 * 8) = 0;
        } while (uVar7 < *(uint *)(puVar3 + 9));
      }
      puVar1 = puVar3 + 5;
      puVar3[6] = puVar1;
      *puVar1 = puVar1;
      local_28 = CONCAT44(local_28._4_4_,0x100180);
      local_28._0_6_ = CONCAT15(1,(undefined5)local_28);
      *(undefined2 *)((longlong)puVar3 + 0x6c) = 0;
      local_28 = (ulonglong)(uint6)local_28;
      *(undefined4 *)(puVar3 + 0xd) = 0xdc;
      uStack_20 = 0xdc48505450;
      lVar4 = NdisAllocateNetBufferListPool(param_1,&local_28);
      puVar3[0xc] = lVar4;
      if (lVar4 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) ||
           (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c001b25a;
        uVar6 = 10;
      }
      else {
        *(undefined2 *)((longlong)puVar3 + 0x7c) = 0x20;
        local_28 = CONCAT26(0x20,(uint6)local_28);
        *(undefined4 *)(puVar3 + 0xf) = 0x698;
        uStack_20 = 0x69870505450;
        lVar4 = NdisAllocateNetBufferListPool(param_1,&local_28);
        puVar3[0xe] = lVar4;
        if (lVar4 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) ||
             (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c001b25a;
          uVar6 = 0xb;
        }
        else {
          local_28 = local_28 & 0xffffffffffff;
          uStack_20 = 0x2470415450;
          lVar4 = NdisAllocateNetBufferListPool(param_1,&local_28);
          puVar3[0x10] = lVar4;
          if (lVar4 != 0) {
            *(undefined4 *)(puVar3 + 0x1a) = 0;
            return puVar3;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) ||
             (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c001b25a;
          uVar6 = 0xc;
        }
      }
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                &WPP_15f8f3c69fe539a078b1580830f46cde_Traceguids,0xc000009a,0x9a);
    }
  }
LAB_1c001b25a:
  AdapterFree((longlong)puVar3);
  return (undefined8 *)0x0;
}



===== MpReadConfig @ 1c001b2a0 =====

int MpReadConfig(undefined8 param_1)

{
  int iVar1;
  longlong local_res8 [4];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_res8[0] = 0;
  local_18 = 0;
  local_28 = 0x1801a9;
  local_20 = param_1;
  iVar1 = NdisOpenConfigurationEx(&local_28,local_res8);
  if (iVar1 == 0) {
    OsReadConfig(local_res8[0]);
  }
  if (local_res8[0] != 0) {
    NdisCloseConfiguration();
  }
  return iVar1;
}



===== InitThreading @ 1c001b310 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitThreading(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = 0;
  local_34 = 0;
  local_1c = 0;
  if (ThreadingInitialized == '\0') {
    _DAT_1c000c348 = &WorkItemList;
    _WorkItemList = &WorkItemList;
    KeInitializeSpinLock(&GlobalThreadLock);
    KeInitializeEvent(&EventPassiveThread,1,0);
    KeInitializeEvent(&EventKillThread,1,0);
    local_38 = 0x30;
    local_30 = 0;
    local_20 = 0x200;
    local_28 = 0;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = PsCreateSystemThread(&hPassiveThread,0,&local_38,0,0,MainPassiveLevelThread,0);
    if (iVar1 == 0) {
      ThreadingInitialized = '\x01';
      uVar2 = 0;
    }
    else {
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== WppCleanupKm @ 1c001b400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
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



===== WppInitKm @ 1c001b480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
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



===== WppTraceCallback @ 1c001b510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar1 = *(uint **)(param_5 + 8);
          if (((*puVar1 == param_4[6]) && (puVar1[1] == param_4[7])) &&
             ((puVar1[2] == param_4[8] && (puVar1[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != 2;
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
  }
  else {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar3 + 2 + uVar11;
      }
      if (param_3 < uVar12) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
               (ulonglong)*puVar3);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar1 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== DeinitThreading @ 1c001b798 =====

void DeinitThreading(void)

{
  ThreadingInitialized = 0;
  WaitForThreadToDieAndCloseIt();
  return;
}



===== OsReadConfig @ 1c001b7b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void OsReadConfig(undefined8 param_1)

{
  int local_res10 [2];
  int local_res18 [2];
  longlong local_res20;
  longlong local_a8 [2];
  wchar_t *local_98;
  longlong local_90;
  wchar_t *local_88;
  longlong local_80;
  wchar_t *local_78;
  longlong local_70;
  wchar_t *local_68;
  longlong local_60;
  wchar_t *local_58;
  longlong local_50;
  wchar_t *local_48;
  
  local_50 = 0x1a0018;
  local_res18[0] = 0;
  local_48 = L"TapiLineName";
  local_a8[0] = 0;
  local_78 = L"ClientIpAddresses";
  local_80 = 0x240022;
  local_88 = L"ClientIpMasks";
  local_90 = 0x1c001a;
  local_58 = L"TrustedIpAddresses";
  local_60 = 0x260024;
  local_68 = L"TrustedIpMasks";
  local_70 = 0x1e001c;
  local_98 = L"TcpPortNumber";
  local_res20 = 0;
  local_res10[0] = 0;
  local_a8[1] = 0x1c001a;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpControlPort = *(undefined2 *)(local_res20 + 8);
  }
  local_res20 = 0;
  local_98 = L"BaseCallId";
  local_res10[0] = 0;
  local_a8[1] = 0x160014;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpBaseCallId = *(int *)(local_res20 + 8);
  }
  local_res20 = 0;
  local_98 = L"MaxTransmit";
  local_res10[0] = 0;
  local_a8[1] = 0x180016;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpMaxTransmit = *(uint *)(local_res20 + 8);
  }
  local_res20 = 0;
  local_98 = L"InactivityIdleSeconds";
  local_res10[0] = 0;
  local_a8[1] = 0x2c002a;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpEchoTimeout = *(undefined4 *)(local_res20 + 8);
  }
  local_res20 = 0;
  local_98 = L"AlwaysEcho";
  local_res10[0] = 0;
  local_a8[1] = 0x160014;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpEchoAlways = *(int *)(local_res20 + 8) != 0;
  }
  local_res20 = 0;
  local_98 = L"AuthenticateIncomingCalls";
  local_res10[0] = 0;
  local_a8[1] = 0x340032;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpAuthenticateIncomingCalls = *(int *)(local_res20 + 8) != 0;
  }
  local_res20 = 0;
  local_98 = L"PptpTraceMask";
  local_res10[0] = 0;
  local_a8[1] = 0x1c001a;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  local_res20 = 0;
  local_98 = L"ValidateAddress";
  local_res10[0] = 0;
  local_a8[1] = 0x20001e;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpValidateAddress = *(undefined4 *)(local_res20 + 8);
  }
  local_res20 = 0;
  local_98 = L"MaxTunnelsPerIpAddress";
  local_res10[0] = 0;
  local_a8[1] = 0x2e002c;
  NdisReadConfiguration(local_res10,&local_res20,param_1,local_a8 + 1,0);
  if (local_res10[0] == 0) {
    PptpMaxTunnelsPerIpAddress = *(uint *)(local_res20 + 8);
  }
  PptpWanEndpoints = 1;
  if (1 < PptpMaxTunnelsPerIpAddress) {
    PptpMaxTunnelsPerIpAddress = 0xffffffff;
  }
  if (0x10000 < PptpBaseCallId + 1U) {
    PptpBaseCallId = 0xffff;
  }
  PptpClientSide = 0;
  if (PptpMaxTransmit == 0) {
    PptpMaxTransmit = 1;
  }
  if (0x400 < PptpMaxTransmit) {
    PptpMaxTransmit = 0x400;
  }
  if (PptpAuthenticateIncomingCalls != '\0') {
    _g_ulAcceptClientAddresses =
         ReadClientAddressAndMaskList(param_1,local_a8 + 5,local_a8 + 3,&g_AcceptClientList);
  }
  _g_ulTrustedClientAddresses =
       ReadClientAddressAndMaskList(param_1,local_a8 + 9,local_a8 + 7,&g_TrustedClientList);
  NdisReadConfiguration(local_res18,local_a8,param_1,local_a8 + 0xb,2);
  if (local_res18[0] == 0) {
    RtlUnicodeStringToAnsiString(&TapiLineName,local_a8[0] + 8,0);
    PTR_TapiLineNameBuffer_1c000c090[(ulonglong)DAT_1c000c08a - 1] = 0;
  }
  return;
}



===== ReadClientAddressAndMaskList @ 1c001bbec =====

uint ReadClientAddressAndMaskList
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  char local_68 [4];
  int local_64;
  longlong local_60 [2];
  undefined4 uStack_4e;
  undefined8 uStack_50;
  
  uVar6 = 0;
  local_64 = -0x3fffffff;
  *param_4 = 0;
  local_60[0] = 0;
  uVar8 = 0;
  NdisReadConfiguration(&local_64,local_60,param_1,param_2,3);
  if (local_64 == 0) {
    local_68[0] = '\0';
    uVar9 = 0;
    local_60[1] = 0;
    uStack_50 = 0;
    bVar11 = false;
    lVar3 = *(longlong *)(local_60[0] + 0x10);
    if (*(ushort *)(local_60[0] + 8) >> 1 != 1) {
      uVar5 = 0;
      lVar4 = local_60[0];
      do {
        puVar1 = (ushort *)(lVar3 + uVar5 * 2);
        uVar2 = *puVar1;
        if (bVar11) {
          bVar11 = uVar2 != 0;
        }
        else if (uVar2 != 0) {
          bVar11 = true;
          StringToIpAddressW(puVar1,(undefined4 *)(local_60 + 1),local_68);
          lVar4 = local_60[0];
          if (local_68[0] != '\0') {
            uVar8 = uVar8 + 1;
          }
        }
        uVar9 = uVar9 + 1;
        uVar5 = (ulonglong)uVar9;
      } while (uVar5 < (ulonglong)(*(ushort *)(lVar4 + 8) >> 1) - 1);
    }
    if (uVar8 != 0) {
      lVar4 = MyMemAlloc(uVar8 * 8,0x4c505450);
      if (lVar4 == 0) {
        uVar8 = 0;
      }
      else {
        uVar9 = 0;
        bVar11 = false;
        if (*(ushort *)(local_60[0] + 8) >> 1 != 1) {
          do {
            if (uVar8 <= uVar9) break;
            puVar1 = (ushort *)(lVar3 + uVar6 * 2);
            uVar2 = *puVar1;
            if (bVar11) {
              bVar11 = uVar2 != 0;
            }
            else if (uVar2 != 0) {
              bVar11 = true;
              StringToIpAddressW(puVar1,(undefined4 *)(local_60 + 1),local_68);
              if (local_68[0] != '\0') {
                uVar5 = (ulonglong)uVar9;
                *(undefined4 *)(lVar4 + 4 + uVar5 * 8) = 0xffffffff;
                uVar9 = uVar9 + 1;
                *(undefined4 *)(lVar4 + uVar5 * 8) = uStack_4e;
              }
            }
            uVar6 = (ulonglong)((int)uVar6 + 1);
          } while (uVar6 < (ulonglong)(*(ushort *)(local_60[0] + 8) >> 1) - 1);
        }
        NdisReadConfiguration(&local_64,local_60,param_1,param_3,3);
        if (local_64 == 0) {
          uVar10 = 0;
          uVar9 = 0;
          bVar11 = false;
          lVar3 = *(longlong *)(local_60[0] + 0x10);
          lVar7 = local_60[0];
          if (*(ushort *)(local_60[0] + 8) >> 1 != 1) {
            do {
              if (uVar8 <= uVar10) break;
              puVar1 = (ushort *)(lVar3 + (ulonglong)uVar9 * 2);
              uVar2 = *puVar1;
              if (bVar11) {
                bVar11 = uVar2 != 0;
              }
              else if (uVar2 != 0) {
                bVar11 = true;
                StringToIpAddressW(puVar1,(undefined4 *)(local_60 + 1),local_68);
                if (local_68[0] != '\0') {
                  uVar6 = (ulonglong)uVar10;
                  uVar10 = uVar10 + 1;
                  *(undefined4 *)(lVar4 + 4 + uVar6 * 8) = uStack_4e;
                }
                lVar7 = local_60[0];
              }
              uVar9 = uVar9 + 1;
            } while ((ulonglong)uVar9 < (ulonglong)(*(ushort *)(lVar7 + 8) >> 1) - 1);
          }
        }
        *param_4 = lVar4;
      }
    }
  }
  return uVar8;
}



===== WaitForThreadToDieAndCloseIt @ 1c001be34 =====

void WaitForThreadToDieAndCloseIt(void)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res10 [3];
  
  lVar1 = hPassiveThread;
  local_res10[0] = 0;
  if (hPassiveThread != 0) {
    iVar2 = ObReferenceObjectByHandle(hPassiveThread,0,0,0,local_res10,0);
    if (iVar2 == 0) {
      KeSetEvent(&EventKillThread,0,0);
      KeWaitForSingleObject(local_res10[0],0,0,0,0);
      ObfDereferenceObject(local_res10[0]);
    }
    ZwClose(lVar1);
  }
  return;
}



===== WskStartClientModule @ 1c001bee0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WskStartClientModule(void)

{
  int iVar1;
  
  _DAT_1c000c1c0 = _WskPptpGuid;
  uRam00000001c000c1c4 = uRam00000001c000c13c;
  uRam00000001c000c1c8 = uRam00000001c000c140;
  uRam00000001c000c1cc = uRam00000001c000c144;
  iVar1 = NmrRegisterClient(&WskClientNotify,0,&WskClientHandle);
  if (-1 < iVar1) {
    KeInitializeSpinLock(&RouteListLock);
    DAT_1c000c308 = &RouteList;
    RouteList = &RouteList;
  }
  return iVar1;
}



===== MiniportInitializeEx @ 1c001bf50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MiniportInitializeEx(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined1 auStack_1e8 [32];
  undefined8 local_1b8;
  undefined8 *puStack_1b0;
  undefined8 local_1a8;
  ulonglong uStack_1a0;
  undefined4 local_198 [2];
  undefined8 local_190;
  undefined4 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_148;
  undefined4 local_144;
  undefined2 local_13c;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined2 local_e4;
  undefined1 local_e2;
  undefined8 local_e0;
  undefined4 *local_d0;
  undefined4 local_c8;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_78 = 0;
  local_70 = 0;
  puVar3 = (undefined8 *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  memset(local_198,0,0xe0);
  local_68 = 0x20106;
  local_1b8 = 0;
  puStack_1b0 = (undefined8 *)0x0;
  local_64 = 0x1010c;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_60 = 0x20102;
  local_5c = 0x20101;
  local_58 = 0x4010105;
  local_54 = 0x4010180;
  local_50 = 0x4010182;
  local_4c = 0x4010181;
  local_48 = 0xfe001001;
  local_44 = 0xfe001002;
  local_40 = 0xfe001003;
  local_3c = 0xfe001007;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
  }
  iVar1 = MpReadConfig(param_1);
  if (iVar1 == 0) {
    uVar2 = InitThreading();
    iVar1 = (int)uVar2;
    if (iVar1 == 0) {
      InitCallLayer();
      puVar3 = AdapterAlloc(param_1);
      pgAdapter = puVar3;
      if (puVar3 == (undefined8 *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
        }
        iVar1 = -0x3fffff66;
        goto LAB_1c001c374;
      }
      NdisInitializeEvent(puVar3 + 0x15);
      ReferenceAdapter((longlong)puVar3);
      *(undefined4 *)(puVar3 + 0x18) = 0;
      puVar3[0x19] = DoDerefMiniportAdapterBlockWork;
      local_1b8 = CONCAT44(local_1b8._4_4_,0x20029e);
      local_1a8 = 0x20;
      uStack_1a0 = uStack_1a0 & 0xffffffff00000000;
      puStack_1b0 = puVar3;
      iVar1 = NdisMSetMiniportAttributes(param_1,&local_1b8);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) ||
           (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c001c374;
        uVar4 = 0x11;
      }
      else {
        local_c0 = &local_a8;
        local_198[0] = 0xe0029f;
        local_190 = 0xc;
        local_e4 = 0x83;
        local_d0 = &local_68;
        local_188 = 0x5b8;
        local_180 = 0xffffffffffffffff;
        local_170 = 0xffffffffffffffff;
        local_178 = 0xffffffffffffffff;
        local_168 = 0xffffffffffffffff;
        local_160 = 0;
        local_158 = 0x5fc;
        local_a8 = CONCAT44(local_a8._4_4_,0x3c0280);
        uStack_80 = 0;
        local_78 = local_78 & 0xffffffff00000000;
        local_148 = 5;
        local_144 = 1;
        local_13c = 0;
        local_f8 = 0;
        local_f0 = 3;
        local_e8 = 1;
        local_e2 = 0;
        local_e0 = 0xc;
        local_c8 = 0x30;
        iVar1 = NdisMSetMiniportAttributes(param_1);
        if (-1 < iVar1) {
          memset(&gCounters,0,0xe0);
          local_b8 = 0x801;
          local_b4 = 6;
          local_b0 = 0x1e;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                    &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
          }
          iVar1 = NdisMCmRegisterAddressFamilyEx(param_1,&local_b8);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                     &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar1);
          }
          *(undefined4 *)(puVar3 + 0x1a) = 1;
          goto LAB_1c001c370;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) == 0)) ||
           (WPP_GLOBAL_Control[0x29] == '\0')) goto LAB_1c001c374;
        uVar4 = 0x12;
      }
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar1,(char)iVar1);
      goto LAB_1c001c374;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
       ) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_e4377d1fa7d13161870a643b98787472_Traceguids);
    }
  }
LAB_1c001c370:
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1c001c374:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_e4377d1fa7d13161870a643b98787472_Traceguids,iVar1);
  }
  if (puVar3 != (undefined8 *)0x0) {
    DereferenceAdapter((longlong)puVar3);
  }
  ThreadingInitialized = 0;
  WaitForThreadToDieAndCloseIt();
  return iVar1;
}



===== WppLoadTracingSupport @ 1c001c400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== AddHostRoute @ 1c001d008 =====

ulonglong AddHostRoute(short *param_1,undefined4 *param_2)

{
  short sVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  longlong *plVar9;
  ulonglong uVar10;
  
  uVar10 = 0;
  DAT_1c000c2f8 = KeAcquireSpinLockRaiseToDpc(&RouteListLock);
  plVar9 = FindRouteIntheList(param_1);
  if (plVar9 != (longlong *)0x0) {
    LOCK();
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    UNLOCK();
    KeReleaseSpinLock(&RouteListLock,DAT_1c000c2f8);
LAB_1c001d06e:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)((longlong)plVar9 + 0x34);
    }
    return uVar10;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x40,0x38,0x726e6177);
  if (plVar9 == (longlong *)0x0) {
    KeReleaseSpinLock(&RouteListLock,DAT_1c000c2f8);
    return 0xc000009a;
  }
  sVar1 = *param_1;
  uVar5 = *(undefined4 *)(param_1 + 2);
  uVar6 = *(undefined4 *)(param_1 + 4);
  uVar7 = *(undefined4 *)(param_1 + 6);
  if (sVar1 != 2) {
    *(undefined4 *)((longlong)plVar9 + 0x14) = *(undefined4 *)param_1;
    *(undefined4 *)(plVar9 + 3) = uVar5;
    *(undefined4 *)((longlong)plVar9 + 0x1c) = uVar6;
    *(undefined4 *)(plVar9 + 4) = uVar7;
    *(undefined8 *)((longlong)plVar9 + 0x24) = *(undefined8 *)(param_1 + 8);
    *(undefined4 *)((longlong)plVar9 + 0x2c) = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    *(undefined4 *)((longlong)plVar9 + 0x14) = *(undefined4 *)param_1;
    *(undefined4 *)(plVar9 + 3) = uVar5;
    *(undefined4 *)((longlong)plVar9 + 0x1c) = uVar6;
    *(undefined4 *)(plVar9 + 4) = uVar7;
  }
  LOCK();
  *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
  UNLOCK();
  if ((undefined8 *)*DAT_1c000c308 == &RouteList) {
    *plVar9 = (longlong)&RouteList;
    plVar9[1] = (longlong)DAT_1c000c308;
    *DAT_1c000c308 = (longlong)plVar9;
    DAT_1c000c308 = plVar9;
    if (sVar1 != 2) {
      uVar8 = NsiCliAddHostV6Route
                        ((CHAR (*) [8])((longlong)plVar9 + 0x1c),
                         (NET_IFINDEX *)((longlong)plVar9 + 0x34));
    }
    else {
      uVar8 = NsiCliAddHostRoute((int)plVar9[3],(NET_IFINDEX *)((longlong)plVar9 + 0x34));
    }
    uVar10 = (ulonglong)uVar8;
    KeReleaseSpinLock(&RouteListLock,DAT_1c000c2f8);
    if (-1 < (int)uVar8) goto LAB_1c001d06e;
    DAT_1c000c2f8 = KeAcquireSpinLockRaiseToDpc(&RouteListLock);
    lVar2 = *plVar9;
    if ((*(longlong **)(lVar2 + 8) == plVar9) &&
       (plVar3 = (longlong *)plVar9[1], (longlong *)*plVar3 == plVar9)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      KeReleaseSpinLock(&RouteListLock,DAT_1c000c2f8);
      ExFreePoolWithTag(plVar9,0);
      return uVar10;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar10 = (*pcVar4)();
  return uVar10;
}



===== DeleteHostRoute @ 1c001d1cc =====

ulonglong DeleteHostRoute(short *param_1)

{
  short sVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  
  sVar1 = *param_1;
  uVar7 = 0;
  DAT_1c000c2f8 = KeAcquireSpinLockRaiseToDpc(&RouteListLock);
  plVar6 = FindRouteIntheList(param_1);
  KeReleaseSpinLock(&RouteListLock,DAT_1c000c2f8);
  if (plVar6 != (longlong *)0x0) {
    LOCK();
    plVar2 = plVar6 + 2;
    lVar4 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar4 == 1) {
      if (sVar1 == 2) {
        uVar5 = NsiCliDeleteHostRoute((int)plVar6[3]);
      }
      else {
        uVar5 = NsiCliDeleteHostV6Route((longlong *)((longlong)plVar6 + 0x1c));
      }
      uVar7 = (ulonglong)uVar5;
      DAT_1c000c2f8 = KeAcquireSpinLockRaiseToDpc(&RouteListLock);
      lVar4 = *plVar6;
      if ((*(longlong **)(lVar4 + 8) != plVar6) ||
         (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 != plVar6)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar7 = (*pcVar3)();
        return uVar7;
      }
      *plVar2 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar2;
      KeReleaseSpinLock(&RouteListLock,CONCAT71((int7)((ulonglong)lVar4 >> 8),DAT_1c000c2f8));
      ExFreePoolWithTag(plVar6,0);
    }
  }
  return uVar7;
}



===== FindRouteIntheList @ 1c001d2d0 =====

undefined8 * FindRouteIntheList(short *param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = RouteList;
  while( true ) {
    if ((undefined8 **)puVar2 == &RouteList) {
      return (undefined8 *)0x0;
    }
    uVar1 = CompareSockAddress(param_1,(short *)((longlong)puVar2 + 0x14));
    if ((char)uVar1 != '\0') break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== FreeSockContextCommon @ 1c001d31c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeSockContextCommon(longlong param_1)

{
  undefined1 uVar1;
  
  (**(code **)(param_1 + 0x30))("FreeSockContextCommon..Freeing the Socket Context");
  if ((*(uint *)(param_1 + 0x188) & 0x800) != 0) {
    (**(code **)(param_1 + 0x30))("FreeSockContextCommon..Freeing Socket Lists and locks");
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c8);
    *(undefined1 *)(param_1 + 0x1d0) = uVar1;
    ExDeleteNPagedLookasideList(param_1 + 0x80);
    ExDeleteNPagedLookasideList(param_1 + 0x100);
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    KeReleaseSpinLock(param_1 + 0x1c8,*(undefined1 *)(param_1 + 0x1d0));
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== FreeSockHandle @ 1c001d3e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeSockHandle(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x180) == 0) {
    FreeSockContextCommon(param_1);
  }
  else if (((*(uint *)(param_1 + 0x188) & 0x10) == 0) || ((*(uint *)(param_1 + 0x188) & 2) != 0)) {
    WskCloseSocketAndFreeSocketContext(param_1);
  }
  else {
    (**(code **)(param_1 + 0x30))("FreeSockHandle..Issuing Disconnect for Connected Sockets");
    WskDisconnectSocket(param_1);
  }
  return;
}



===== GetLocalAddress @ 1c001d43c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GetLocalAddress(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  plVar1 = *(longlong **)(param_1 + 0x180);
  lVar4 = IoAllocateIrp(1,0);
  if (lVar4 != 0) {
    puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x6c6e6177);
    if (puVar5 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
      UNLOCK();
      puVar5[1] = param_1;
      *puVar5 = CtlpQueryAddrInfoCallback;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = WskGetLocalAddrIrpCompletion;
      *(undefined8 **)(lVar2 + -8) = puVar5;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      uVar3 = (**(code **)(*plVar1 + 0x20))(plVar1,param_2,lVar4);
      return uVar3;
    }
    IoFreeIrp(lVar4);
  }
  CtlpQueryAddrInfoCallback(*(longlong *)(param_1 + 8));
  return 0xc000009a;
}



===== WskAcceptCompletion @ 1c001d530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskAcceptCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x30);
  if (-1 < iVar4) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x1c8);
    *(uint *)(param_3 + 0x188) = *(uint *)(param_3 + 0x188) | 0x20;
    *(undefined1 *)(param_3 + 0x1d0) = uVar3;
    KeReleaseSpinLock(param_3 + 0x1c8,uVar3);
    iVar4 = (**(code **)(param_3 + 0x20))();
  }
  LOCK();
  piVar1 = (int *)(param_3 + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x208))(param_3);
  }
  if (iVar4 < 0) {
    WskCloseSocketContextAndFreeSocketEx(param_3,'\0',0);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskBindCompletion @ 1c001d600 =====

undefined8 WskBindCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,2);
  return 0xc0000016;
}



===== WskCloseSocketAndFreeSocketContext @ 1c001d62c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskCloseSocketAndFreeSocketContext(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_1 + 0x180) != 0) {
    lVar2 = IoAllocateIrp(1,0);
    if (lVar2 != 0) {
      lVar1 = **(longlong **)(param_1 + 0x180);
      lVar2 = *(longlong *)(lVar2 + 0xb8);
      *(code **)(lVar2 + -0x10) = WskCloseSocketIrpCompletion;
      *(longlong *)(lVar2 + -8) = param_1;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      (**(code **)(lVar1 + 8))(*(undefined8 *)(param_1 + 0x180));
    }
  }
  return;
}



===== WskCloseSocketContext @ 1c001d698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseSocketContext(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  
  (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Enter");
  lVar1 = param_1 + 0x1c8;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar5 = *(uint *)(param_1 + 0x188);
  *(undefined1 *)(param_1 + 0x1d0) = uVar8;
  if ((uVar5 & 0x40) == 0) {
    *(uint *)(param_1 + 0x188) = uVar5 & 0xffffffdf | 0x40;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)((uVar5 & 0xffffffdf) >> 8),uVar8));
    if (*(longlong *)(param_1 + 0x180) != 0) {
      if (((byte)*(uint *)(param_1 + 0x188) & 0x12) == 0x12) {
        (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Close on Stream Server Socket");
        WskCloseStreamServerSocketContext(param_1);
      }
      else if ((*(uint *)(param_1 + 0x188) & 4) != 0) {
        (**(code **)(param_1 + 0x30))("WskCloseSocketContext..Close on Stream Socket");
        uVar8 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x1f8) + 0x1c8);
        *(undefined1 *)(*(longlong *)(param_1 + 0x1f8) + 0x1d0) = uVar8;
        plVar3 = (longlong *)(param_1 + 0x1a8);
        lVar1 = *plVar3;
        if ((*(longlong **)(lVar1 + 8) != plVar3) ||
           (plVar6 = *(longlong **)(param_1 + 0x1b0), (longlong *)*plVar6 != plVar3)) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          pcVar7 = (code *)swi(3);
          uVar9 = (*pcVar7)();
          return uVar9;
        }
        *plVar6 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar6;
        lVar1 = *(longlong *)(param_1 + 0x1f8);
        KeReleaseSpinLock(lVar1 + 0x1c8,
                          CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x1d0)));
      }
      LOCK();
      piVar2 = (int *)(param_1 + 0x200);
      iVar4 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        (**(code **)(param_1 + 0x208))(param_1);
      }
    }
  }
  else {
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar5 >> 8),uVar8));
  }
  return 0;
}



===== WskCloseSocketContextAndFreeSocket @ 1c001d7f8 =====

void WskCloseSocketContextAndFreeSocket(longlong param_1)

{
  WskCloseSocketContextAndFreeSocketEx(param_1,'\0',0);
  return;
}



===== WskCloseSocketContextAndFreeSocketEx @ 1c001d814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskCloseSocketContextAndFreeSocketEx(longlong param_1,char param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  
  (**(code **)(param_1 + 0x30))("WskCloseSocketContextAndFreeSocketEx..Enter");
  uVar3 = WskCloseSocketContext(param_1);
  if (param_2 != '\0') {
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if (param_3 != 0) {
    KeReleaseSpinLock(param_3,*(undefined1 *)(param_3 + 8));
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x208))(param_1);
  }
  return uVar3 & 0xffffffff;
}



===== WskCloseSocketIrpCompletion @ 1c001d8b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseSocketIrpCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  IoFreeIrp(param_2);
  *(undefined8 *)(param_3 + 0x180) = 0;
  (**(code **)(param_3 + 0x30))("WskCloseSocket Done");
  (**(code **)(param_3 + 0x30))("Freeing Sock Context");
  FreeSockContextCommon(param_3);
  return 0xc0000016;
}



===== WskCloseStreamServerSocketContext @ 1c001d90c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskCloseStreamServerSocketContext(longlong param_1)

{
  undefined8 ****ppppuVar1;
  undefined8 ****ppppuVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 ****ppppuVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 ***pppuVar8;
  undefined1 uVar9;
  undefined8 ****ppppuVar10;
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  (**(code **)(param_1 + 0x30))("WskCloseStreamServerSocketContext..Enter");
  local_10 = &local_18;
  local_18 = &local_18;
  uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c8);
  *(undefined1 *)(param_1 + 0x1d0) = uVar9;
  puVar7 = *(undefined8 **)(param_1 + 0x1a8);
  while (puVar7 != (undefined8 *)(param_1 + 0x1a8)) {
    puVar4 = (undefined8 *)*puVar7;
    ppppuVar1 = (undefined8 ****)(puVar7 + 2);
    puVar7[3] = ppppuVar1;
    *ppppuVar1 = ppppuVar1;
    if ((undefined8 *****)local_18[1] != &local_18) goto LAB_1c001da76;
    *ppppuVar1 = local_18;
    puVar7[3] = &local_18;
    local_18[1] = ppppuVar1;
    LOCK();
    *(int *)(puVar7 + 0xb) = *(int *)(puVar7 + 0xb) + 1;
    UNLOCK();
    puVar7 = puVar4;
    local_18 = ppppuVar1;
  }
  KeReleaseSpinLock(param_1 + 0x1c8,
                    CONCAT71((int7)((ulonglong)puVar7 >> 8),*(undefined1 *)(param_1 + 0x1d0)));
  while( true ) {
    ppppuVar1 = local_18;
    if ((undefined8 *****)local_18 == &local_18) {
      return 0;
    }
    if (((undefined8 *****)local_18[1] != &local_18) ||
       (ppppuVar5 = (undefined8 ****)*local_18, (undefined8 ****)ppppuVar5[1] != local_18)) break;
    ppppuVar5[1] = &local_18;
    ppppuVar10 = local_18 + -0x37;
    ppppuVar2 = local_18 + 2;
    local_18 = ppppuVar5;
    uVar9 = KeAcquireSpinLockRaiseToDpc(ppppuVar2);
    pppuVar8 = ppppuVar1[-6];
    *(undefined1 *)(ppppuVar1 + 3) = uVar9;
    KeReleaseSpinLock(ppppuVar2,uVar9);
    if ((((ulonglong)pppuVar8 & 0x40) == 0) && (ppppuVar1[-0x34] != (undefined8 ***)0x0)) {
      (*(code *)ppppuVar1[-0x34])(ppppuVar1 + -0x36);
    }
    LOCK();
    ppppuVar5 = ppppuVar1 + 9;
    iVar3 = *(int *)ppppuVar5;
    *(int *)ppppuVar5 = *(int *)ppppuVar5 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (*(code *)ppppuVar1[10])(ppppuVar10);
    }
  }
LAB_1c001da76:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  return 0;
}



===== WskConnAcceptEvent @ 1c001daa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WskConnAcceptEvent(longlong param_1,undefined8 param_2,undefined8 param_3,short *param_4,
                      undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar9;
  undefined8 uVar8;
  undefined *local_28;
  undefined8 uStack_20;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  local_28 = (undefined *)0x0;
  uStack_20 = 0;
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x240,0x616e6177);
  if (puVar6 == (undefined4 *)0x0) {
    iVar5 = -0x3fffff30;
    goto LAB_1c001dd4e;
  }
  if ((*(uint *)(param_1 + 0x188) & 0x20) == 0) {
LAB_1c001db12:
    iVar5 = -0x3fffff30;
  }
  else {
    *puVar6 = 0x434b5357;
    puVar1 = puVar6 + 0x6a;
    *(undefined8 *)(puVar6 + 4) = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(puVar6 + 0x10) = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(puVar6 + 8) = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(puVar6 + 0x12) = *(undefined8 *)(param_1 + 0x48);
    *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(param_1 + 0x30);
    *(undefined4 **)(puVar6 + 0x6c) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    LOCK();
    *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
    UNLOCK();
    ExInterlockedInsertTailList(param_1 + 0x1a8,puVar1,param_1 + 0x1c8);
    *(code **)(puVar6 + 0x82) = FreeSockHandle;
    *(undefined8 **)(puVar6 + 0x60) = param_5;
    puVar6[0x62] = 0x14;
    *(longlong *)(puVar6 + 0x7e) = param_1;
    puVar6[0x80] = 1;
    NdisGetVersion();
    uVar8 = CONCAT44(uVar9,0x72774152);
    ExInitializeNPagedLookasideList(puVar6 + 0x20,0,0,0x200,0x30,uVar8,10);
    uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
    NdisGetVersion();
    ExInitializeNPagedLookasideList(puVar6 + 0x40,0,0,0x200,0x40,CONCAT44(uVar9,0x73774152),10);
    KeInitializeSpinLock(puVar6 + 0x72);
    puVar6[0x62] = puVar6[0x62] | 0x800;
    uVar9 = *(undefined4 *)(param_4 + 2);
    uVar3 = *(undefined4 *)(param_4 + 4);
    uVar4 = *(undefined4 *)(param_4 + 6);
    if (*param_4 == 2) {
      puVar6[0x76] = *(undefined4 *)param_4;
      puVar6[0x77] = uVar9;
      puVar6[0x78] = uVar3;
      puVar6[0x79] = uVar4;
    }
    else {
      puVar6[0x76] = *(undefined4 *)param_4;
      puVar6[0x77] = uVar9;
      puVar6[0x78] = uVar3;
      puVar6[0x79] = uVar4;
      *(undefined8 *)(puVar6 + 0x7a) = *(undefined8 *)(param_4 + 8);
      puVar6[0x7c] = *(undefined4 *)(param_4 + 0xc);
    }
    *param_6 = puVar6;
    *param_7 = &g_WskClientConnDispatch;
    lVar7 = IoAllocateIrp(1,0);
    if (lVar7 == 0) goto LAB_1c001db12;
    LOCK();
    puVar6[0x80] = puVar6[0x80] + 1;
    UNLOCK();
    LOCK();
    puVar6[0x80] = puVar6[0x80] + 1;
    UNLOCK();
    lVar2 = *(longlong *)(lVar7 + 0xb8);
    *(code **)(lVar2 + -0x10) = WskAcceptCompletion;
    *(undefined4 **)(lVar2 + -8) = puVar6;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    local_28 = &NPI_WSK_INTERFACE_ID;
    uStack_20 = CONCAT44(uStack_20._4_4_,0xc0);
    iVar5 = (**(code **)*param_5)(param_5,0,0x4002,0xffff,0x10,&local_28,0,0,0,lVar7);
    if (-1 < iVar5) {
      return iVar5;
    }
  }
  ExFreePoolWithTag(puVar6,0);
LAB_1c001dd4e:
  *param_7 = 0;
  *param_6 = 0;
  return iVar5;
}



===== WskConnDisconnectEvent @ 1c001dd80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskConnDisconnectEvent(longlong param_1)

{
  uint uVar1;
  undefined1 uVar2;
  
  (**(code **)(param_1 + 0x30))("WskConnDisconnectEvent..Enter");
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c8);
  uVar1 = *(uint *)(param_1 + 0x188);
  *(undefined1 *)(param_1 + 0x1d0) = uVar2;
  if ((uVar1 & 0x140) == 0) {
    *(uint *)(param_1 + 0x188) = uVar1 & 0xffffffdf | 0x100;
    KeReleaseSpinLock();
    if (((byte)*(undefined4 *)(param_1 + 0x188) & 0x12) == 0x12) {
      (**(code **)(param_1 + 0x30))("WskConnDisconnectEvent..Server Sock..");
      WskCloseSocketContextAndFreeSocketEx(param_1,'\0',0);
    }
    else if (*(longlong *)(param_1 + 0x18) != 0) {
      (**(code **)(param_1 + 0x30))
                ("WskConnDisconnectEvent..Non-Server Sock..Calling DisconnectHandler");
      (**(code **)(param_1 + 0x18))(param_1 + 8);
    }
  }
  else {
    KeReleaseSpinLock(param_1 + 0x1c8,CONCAT31((int3)(uVar1 >> 8),uVar2));
  }
  return 0;
}



===== WskConnReceiveEvent @ 1c001de60 =====

void WskConnReceiveEvent(longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                        longlong *param_5)

{
  ReceiveData(param_1,param_2,1,param_3,param_5);
  return;
}



===== WskConnSendBacklogEvent @ 1c001de90 =====

undefined8 WskConnSendBacklogEvent(void)

{
  return 0;
}



===== WskConnectControlCompletion @ 1c001dea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskConnectControlCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
  uVar3 = *(undefined4 *)(param_2 + 0x30);
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x1c8);
  *(uint *)(param_3 + 0x188) = *(uint *)(param_3 + 0x188) | 0x20;
  *(undefined1 *)(param_3 + 0x1d0) = uVar4;
  KeReleaseSpinLock(param_3 + 0x1c8,uVar4);
  if (*(code **)(param_3 + 0x28) != (code *)0x0) {
    (**(code **)(param_3 + 0x28))(*(undefined8 *)(param_3 + 8),param_3,uVar3);
  }
  LOCK();
  piVar1 = (int *)(param_3 + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x208))(param_3);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskControlSocket @ 1c001df58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskControlSocket(undefined8 *param_1,undefined8 param_2,undefined4 param_3,
                          undefined4 param_4,undefined8 param_5,undefined8 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong in_stack_00000050;
  undefined8 in_stack_00000058;
  
  KeResetEvent(in_stack_00000058);
  IoReuseIrp(in_stack_00000050,0xc0000001);
  lVar1 = *(longlong *)(in_stack_00000050 + 0xb8);
  *(code **)(lVar1 + -0x10) = WskBindCompletion;
  *(undefined8 *)(lVar1 + -8) = in_stack_00000058;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar2 = (**(code **)*param_1)(param_1,0,param_3,param_4,param_5,param_6,0,0,0,in_stack_00000050);
  if (-1 < (int)uVar2) {
    KeWaitForSingleObject(in_stack_00000058,0,0,0,0);
    uVar2 = (ulonglong)*(uint *)(in_stack_00000050 + 0x30);
  }
  return uVar2;
}



===== WskCreateServerSocket @ 1c001e054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskCreateServerSocket(short *param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  short *psVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined **ppuVar12;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar14;
  undefined8 uVar13;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  uVar9 = 0;
  psVar8 = param_1;
  lVar11 = param_3;
  puVar6 = (undefined8 *)GetWskClientContext();
  if (puVar6 == (undefined8 *)0x0) {
    uVar10 = 0xc00002b9;
  }
  else if ((ushort)(*psVar8 - 1U) < 3) {
    *(uint *)(lVar11 + 0x188) = *(uint *)(lVar11 + 0x188) | 2;
    if (*param_1 == 1) {
      uVar9 = 0x10;
      param_1[4] = 1;
      param_1[5] = 0;
      *(uint *)(lVar11 + 0x188) = *(uint *)(lVar11 + 0x188) | 0x10;
      ppuVar12 = &g_WskListenDispatch;
    }
    else {
      param_1[4] = 4;
      param_1[5] = 0;
      ppuVar12 = &g_WskClientDgramDispatch;
      uVar4 = *(uint *)(lVar11 + 0x188);
      *(uint *)(lVar11 + 0x188) = uVar4 | 8;
      if (*param_1 == 3) {
        *(uint *)(lVar11 + 0x188) = uVar4 | 0x408;
      }
    }
    LOCK();
    *(int *)(lVar11 + 0x200) = *(int *)(lVar11 + 0x200) + 1;
    UNLOCK();
    NdisGetVersion();
    uVar13 = CONCAT44(uVar14,0x72774152);
    ExInitializeNPagedLookasideList(param_3 + 0x80,0,0,0x200,0x30,uVar13,10);
    uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
    NdisGetVersion();
    ExInitializeNPagedLookasideList(param_3 + 0x100,0,0,0x200,0x40,CONCAT44(uVar14,0x73774152),10);
    lVar11 = param_3 + 0x1c8;
    KeInitializeSpinLock(lVar11);
    lVar1 = param_3 + 0x1a8;
    *(longlong *)(param_3 + 0x1b0) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(uint *)(param_3 + 0x188) = *(uint *)(param_3 + 0x188) | 0x800;
    uVar7 = WskOpenSocket(puVar6,param_1,ppuVar12,param_3,uVar9,(undefined8 *)(param_3 + 0x180));
    uVar10 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) {
      LOCK();
      piVar2 = (int *)(param_3 + 0x200);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(param_3 + 0x208))(param_3);
      }
    }
    else {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar11);
      *(uint *)(param_3 + 0x188) = *(uint *)(param_3 + 0x188) | 0x20;
      *(undefined1 *)(param_3 + 0x1d0) = uVar5;
      KeReleaseSpinLock(lVar11,uVar5);
    }
  }
  else {
    uVar10 = 0xc000000d;
  }
  return uVar10;
}



===== WskCreateSocket @ 1c001e250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskCreateSocket(short *param_1,undefined8 param_2,uint param_3,longlong param_4,
                         uint param_5)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  short *psVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar12;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  psVar8 = param_1;
  lVar10 = param_4;
  puVar6 = (undefined8 *)GetWskClientContext();
  if (puVar6 == (undefined8 *)0x0) {
    uVar9 = 0xc00002b9;
  }
  else if ((ushort)(*psVar8 - 1U) < 3) {
    *(uint *)(lVar10 + 0x188) = *(uint *)(lVar10 + 0x188) | 1;
    LOCK();
    *(int *)(lVar10 + 0x200) = *(int *)(lVar10 + 0x200) + 1;
    UNLOCK();
    NdisGetVersion();
    uVar11 = CONCAT44(uVar12,0x72774152);
    ExInitializeNPagedLookasideList
              (param_4 + 0x80,0,0,0x200,(ulonglong)param_5 + 0x37 & 0xfffffffffffffff8,uVar11,10);
    uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
    NdisGetVersion();
    uVar11 = 0x200;
    ExInitializeNPagedLookasideList(param_4 + 0x100,0,0,0x200,0x40,CONCAT44(uVar12,0x73774152),10);
    lVar10 = param_4 + 0x1c8;
    KeInitializeSpinLock(lVar10);
    lVar1 = param_4 + 0x1a8;
    *(longlong *)(param_4 + 0x1b0) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x800;
    if (*param_1 == 1) {
      uVar7 = WskOpenConnectedSocket(puVar6,*(undefined8 *)(param_1 + 8),param_2,uVar11,param_4);
      uVar9 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x10;
        return uVar9;
      }
      LOCK();
      piVar2 = (int *)(param_4 + 0x200);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    else {
      uVar7 = WskOpenSocket(puVar6,param_1,&g_WskClientDgramDispatch,param_4,param_3 | 8,
                            (undefined8 *)(param_4 + 0x180));
      uVar9 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar7) {
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar10);
        *(uint *)(param_4 + 0x188) = *(uint *)(param_4 + 0x188) | 0x20;
        *(undefined1 *)(param_4 + 0x1d0) = uVar5;
        KeReleaseSpinLock(lVar10,uVar5);
        uVar4 = *(uint *)(param_4 + 0x188);
        *(uint *)(param_4 + 0x188) = uVar4 | 8;
        if (*param_1 == 3) {
          *(uint *)(param_4 + 0x188) = uVar4 | 0x408;
          return uVar9;
        }
        return uVar9;
      }
      LOCK();
      piVar2 = (int *)(param_4 + 0x200);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar3 == 1) {
      (**(code **)(param_4 + 0x208))(param_4);
    }
  }
  else {
    uVar9 = 0xc000000d;
  }
  return uVar9;
}



===== WskDestroySockContext @ 1c001e480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskDestroySockContext(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_1 + 0x208))();
  }
  return;
}



===== WskDisconnectSocket @ 1c001e4ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskDisconnectSocket(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  
  (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Enter");
  if (*(longlong *)(param_1 + 0x180) != 0) {
    lVar5 = IoAllocateIrp(1,0);
    if (lVar5 != 0) {
      lVar3 = **(longlong **)(param_1 + 0x180);
      *(code **)(param_1 + 0x218) = WskSocketDisconnectDone;
      *(undefined4 *)(param_1 + 0x210) = 1;
      LOCK();
      *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 1;
      UNLOCK();
      lVar4 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar4 + -0x10) = WskSocketDisconnectCompletion;
      *(longlong *)(lVar4 + -8) = param_1;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      bVar6 = (*(uint *)(param_1 + 0x188) & 0x1000) != 0;
      if (bVar6) {
        (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Issuing ABORTIVE Disconnect");
        *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) & 0xffffefff;
      }
      (**(code **)(lVar3 + 0x40))(*(undefined8 *)(param_1 + 0x180),0,bVar6,lVar5);
      (**(code **)(param_1 + 0x30))("WskDisconnectSocket..Issuing reref for DISC Initial");
      LOCK();
      piVar1 = (int *)(param_1 + 0x210);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(param_1 + 0x218))(param_1);
      }
    }
  }
  return;
}



===== WskGetLocalAddrIrpCompletion @ 1c001e5d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskGetLocalAddrIrpCompletion(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  int iVar2;
  
  (*(code *)*param_3)(*(undefined8 *)(param_3[1] + 8));
  LOCK();
  piVar1 = (int *)(param_3[1] + 0x200);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3[1] + 0x208))();
  }
  ExFreePoolWithTag(param_3,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskLibDummyLogger @ 1c001e650 =====

void WskLibDummyLogger(void)

{
  return;
}



===== WskOpenConnectedSocket @ 1c001e65c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskOpenConnectedSocket
                    (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    longlong param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  KeInitializeEvent(param_5 + 400,0,0);
  lVar3 = IoAllocateIrp(1,0);
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    LOCK();
    *(int *)(param_5 + 0x200) = *(int *)(param_5 + 0x200) + 1;
    UNLOCK();
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar1 + -0x10) = WskOpenConnectedSocketCompletion;
    *(longlong *)(lVar1 + -8) = param_5;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar4 = (**(code **)(param_1[1] + 0x10))
                      (*param_1,1,6,param_2,param_3,0,param_5,&g_WskClientConnDispatch,0,0,0,lVar3);
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      if (*(char *)(param_5 + 0x38) == '\0') {
        uVar4 = KeWaitForSingleObject(param_5 + 400,0,0,0,0);
      }
      else {
        uVar4 = uVar4 & 0xffffffff;
        if (iVar2 == 0x103) {
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}



===== WskOpenConnectedSocketCompletion @ 1c001e790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskOpenConnectedSocketCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  longlong lVar6;
  undefined *local_18;
  undefined8 uStack_10;
  
  bVar5 = true;
  local_18 = (undefined *)0x0;
  uStack_10 = 0;
  if (-1 < *(int *)(param_2 + 0x30)) {
    puVar3 = *(undefined8 **)(param_2 + 0x38);
    *(undefined8 **)(param_3 + 0x180) = puVar3;
    lVar6 = IoAllocateIrp(1,0);
    if (lVar6 != 0) {
      local_18 = &NPI_WSK_INTERFACE_ID;
      uStack_10 = CONCAT44(uStack_10._4_4_,0xc0);
      lVar4 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar4 + -0x10) = WskConnectControlCompletion;
      *(longlong *)(lVar4 + -8) = param_3;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      (**(code **)*puVar3)(puVar3,0,0x4002,0xffff,0x10,&local_18,0,0,0,lVar6);
      bVar5 = false;
      goto LAB_1c001e801;
    }
  }
  if (*(code **)(param_3 + 0x28) != (code *)0x0) {
    (**(code **)(param_3 + 0x28))(*(undefined8 *)(param_3 + 8),param_3);
  }
LAB_1c001e801:
  KeSetEvent(param_3 + 400,2);
  if (bVar5) {
    LOCK();
    piVar1 = (int *)(param_3 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_3 + 0x208))(param_3);
    }
    LOCK();
    piVar1 = (int *)(param_3 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_3 + 0x208))(param_3);
    }
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskOpenSocket @ 1c001e90c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WskOpenSocket(undefined8 *param_1,undefined2 *param_2,undefined8 param_3,
                       undefined8 param_4,uint param_5,undefined8 *param_6)

{
  short sVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 local_res10 [2];
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar11;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&local_48,0,0);
  sVar1 = **(short **)(param_2 + 8);
  lVar6 = IoAllocateIrp(1,0);
  if (lVar6 == 0) {
    return 0xc000009a;
  }
  lVar8 = *(longlong *)(lVar6 + 0xb8);
  *(code **)(lVar8 + -0x10) = WskBindCompletion;
  *(undefined8 **)(lVar8 + -8) = &local_48;
  *(undefined1 *)(lVar8 + -0x45) = 0xe0;
  uVar5 = (**(code **)(param_1[1] + 8))
                    (*param_1,**(undefined2 **)(param_2 + 8),*param_2,*(undefined4 *)(param_2 + 2),
                     CONCAT44(uVar11,*(undefined4 *)(param_2 + 4)),param_4,param_3,0,0,0,lVar6);
  uVar10 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_1c001eca7;
  uVar9 = 0;
  KeWaitForSingleObject(&local_48,0,0,0,0);
  uVar10 = (ulonglong)*(uint *)(lVar6 + 0x30);
  if ((int)*(uint *)(lVar6 + 0x30) < 0) goto LAB_1c001eca7;
  plVar2 = *(longlong **)(lVar6 + 0x38);
  if ((param_5 & 2) == 0) {
LAB_1c001ea73:
    KeResetEvent(&local_48);
    IoReuseIrp(lVar6,0xc0000001);
    lVar8 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar8 + -0x10) = WskBindCompletion;
    *(undefined8 **)(lVar8 + -8) = &local_48;
    *(undefined1 *)(lVar8 + -0x45) = 0xe0;
    uVar5 = (**(code **)(*plVar2 + 0x10))(plVar2,*(undefined8 *)(param_2 + 8),0);
    uVar10 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      uVar9 = 0;
      KeWaitForSingleObject(&local_48,0,0,0,0);
      uVar10 = (ulonglong)*(uint *)(lVar6 + 0x30);
      if (-1 < (int)*(uint *)(lVar6 + 0x30)) {
        if ((param_5 & 1) != 0) {
          local_res10[0] = 1;
          uVar7 = WskControlSocket(plVar2,uVar9,0x13,-(uint)(sVar1 != 2) & 0x29,4,local_res10);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c001ec5d;
        }
        if ((param_5 & 8) != 0) {
          local_4c = 0;
          local_58 = &NPI_WSK_INTERFACE_ID;
          local_50 = 0x100;
          uVar7 = WskControlSocket(plVar2,uVar9,0x4002,0xffff,0x10,&local_58);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c001ec5d;
        }
        if ((param_5 & 0x10) != 0) {
          local_4c = 0;
          local_58 = &NPI_WSK_INTERFACE_ID;
          local_50 = 0x200;
          uVar7 = WskControlSocket(plVar2,uVar9,0x4002,0xffff,0x10,&local_58);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c001ec5d;
        }
        if ((param_5 & 4) != 0) {
          local_res10[0] = 1;
          uVar7 = WskControlSocket(plVar2,uVar9,2,-(uint)(sVar1 != 2) & 0x29,4,local_res10);
          uVar10 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) goto LAB_1c001ec5d;
        }
        *param_6 = plVar2;
        goto LAB_1c001eca7;
      }
    }
  }
  else {
    local_res10[0] = 1;
    uVar7 = WskControlSocket(plVar2,uVar9,4,0xffff,4,local_res10);
    uVar10 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar7) goto LAB_1c001ea73;
  }
LAB_1c001ec5d:
  if ((plVar2 != (longlong *)0x0) && (lVar8 = IoAllocateIrp(1,0), lVar8 != 0)) {
    lVar3 = *(longlong *)(lVar8 + 0xb8);
    lVar4 = *plVar2;
    *(undefined8 *)(lVar3 + -8) = 0;
    *(code **)(lVar3 + -0x10) = WskSocketIrpCompletion;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    (**(code **)(lVar4 + 8))(plVar2,lVar8);
  }
LAB_1c001eca7:
  IoFreeIrp(lVar6);
  return uVar10;
}



===== WskSend @ 1c001ecdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WskSend(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,uint param_5)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_2c = 0;
  plVar5 = (longlong *)0x0;
  if (*(longlong *)(param_1 + 0x40) == 0) {
    return 0xc000000d;
  }
  if ((*(uint *)(param_1 + 0x188) & 0x20) != 0) {
    plVar1 = *(longlong **)(param_1 + 0x180);
    lVar4 = IoAllocateIrp(1,0);
    if (lVar4 != 0) {
      plVar5 = (longlong *)ExAllocateFromNPagedLookasideList(param_1 + 0x100);
      if ((plVar5 != (longlong *)0x0) &&
         (local_38 = IoAllocateMdl(param_4,param_5,0,0,0), local_38 != 0)) {
        MmBuildMdlForNonPagedPool(local_38);
        plVar5[1] = 0;
        plVar5[2] = 0;
        *(undefined4 *)(plVar5 + 3) = 0;
        plVar5[5] = 0;
        *(undefined4 *)(plVar5 + 6) = 0;
        *plVar5 = param_1;
        plVar5[4] = param_4;
        plVar5[7] = local_38;
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(code **)(lVar2 + -0x10) = WskSendCompletion;
        *(longlong **)(lVar2 + -8) = plVar5;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        local_28 = (ulonglong)param_5;
        local_30 = 0;
        LOCK();
        *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
        UNLOCK();
        uVar3 = (**(code **)(*plVar1 + 0x30))(plVar1,&local_38,0,lVar4);
        return uVar3;
      }
      IoFreeIrp(lVar4);
    }
  }
  (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 8),0,0,0,param_4,0xc000009a);
  if (plVar5 != (longlong *)0x0) {
    ExFreeToNPagedLookasideList(param_1 + 0x100,plVar5);
  }
  return 0xc000009a;
}



===== WskSocketDisconnectCompletion @ 1c001ee80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskSocketDisconnectCompletion(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  
  IoFreeIrp(param_2);
  (**(code **)(param_3 + 0x30))("WskSocketDisconnectCompletion..Deref for DISC Pending");
  LOCK();
  piVar1 = (int *)(param_3 + 0x210);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    (**(code **)(param_3 + 0x218))(param_3);
  }
  return 0xc0000016;
}



===== WskSocketDisconnectDone @ 1c001eee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WskSocketDisconnectDone(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x188) & 4) != 0) {
    (**(code **)(param_1 + 0x30))("In WskSocketDisconnectDone..removing ref on serversock");
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x1f8) + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(*(longlong *)(param_1 + 0x1f8) + 0x208))();
    }
  }
  WskCloseSocketAndFreeSocketContext(param_1);
  return;
}



===== WskSocketIrpCompletion @ 1c001ef50 =====

undefined8 WskSocketIrpCompletion(undefined8 param_1,undefined8 param_2)

{
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WskReceiveDataGramFromEvent @ 1c001ef80 =====

void WskReceiveDataGramFromEvent(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  ReceiveData(param_1,param_2,2,param_3,(longlong *)0x0);
  return;
}



===== ReceiveData @ 1c001efb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ReceiveData(longlong param_1,undefined8 param_2,int param_3,undefined8 *param_4,longlong *param_5)

{
  short sVar1;
  short *psVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong *plVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 auStack_c8 [32];
  ulonglong local_a8;
  ulonglong *local_a0;
  int local_98;
  ulonglong local_90;
  longlong local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  local_58 = 0;
  lVar10 = 0;
  local_80 = param_5;
  local_88 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x188) & 0x20) == 0) {
      return 0;
    }
    if (param_4 == (undefined8 *)0x0) {
      return 0;
    }
    local_98 = param_3;
    for (; param_4 != (undefined8 *)0x0; param_4 = (undefined8 *)*param_4) {
      if (((param_3 == 2) && (param_4[4] != 0)) && (*(int *)(param_4[4] + 0xc) != 0x13)) {
        return 0;
      }
      if (((ulonglong)param_4[3] <= (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 8)) ||
         (param_3 == 1)) {
        plVar7 = (longlong *)ExAllocateFromNPagedLookasideList(param_1 + 0x80);
        if (plVar7 == (longlong *)0x0) {
          return 0;
        }
        *plVar7 = param_1;
        if (param_3 == 2) {
          psVar2 = (short *)param_4[6];
          lVar10 = param_4[4];
          plVar7[1] = (longlong)psVar2;
          sVar1 = *psVar2;
          if (sVar1 == 0x17) {
            if (((lVar10 != 0) && (*(int *)(lVar10 + 0xc) == 0x13)) &&
               ((undefined8 *)(lVar10 + 0x10) != (undefined8 *)0x0)) {
              uStack_60 = *(undefined8 *)(lVar10 + 0x10);
              local_58 = *(undefined8 *)(lVar10 + 0x18);
              local_68 = CONCAT62(local_68._2_6_,0x17);
              plVar7[3] = (longlong)&local_68;
              uVar6 = *(undefined4 *)(lVar10 + 0x20);
              goto LAB_1c001f2ac;
            }
          }
          else if ((((sVar1 == 2) && (lVar10 != 0)) && (*(int *)(lVar10 + 0xc) == 0x13)) &&
                  ((undefined4 *)(lVar10 + 0x10) != (undefined4 *)0x0)) {
            local_78 = CONCAT44(*(undefined4 *)(lVar10 + 0x10),(undefined4)local_78);
            local_78 = CONCAT62(local_78._2_6_,2);
            plVar7[3] = (longlong)&local_78;
            uVar6 = *(undefined4 *)(lVar10 + 0x14);
LAB_1c001f2ac:
            *(undefined4 *)(plVar7 + 2) = uVar6;
          }
        }
        iVar9 = *(int *)(param_4 + 2);
        for (uVar8 = *(uint *)(param_4 + 3); uVar8 != 0; uVar8 = uVar8 - uVar4) {
          puVar3 = *(undefined8 **)(param_1 + 0x48);
          uVar4 = uVar8;
          if (*(uint *)(puVar3 + 1) <= uVar8) {
            uVar4 = *(uint *)(puVar3 + 1);
          }
          uVar11 = (ulonglong)uVar4;
          lVar10 = NdisAllocateNetBufferList(*puVar3,*(undefined2 *)((longlong)puVar3 + 0xc),0);
          if (lVar10 == 0) goto LAB_1c001f21b;
          local_a8 = 0;
          iVar5 = NdisRetreatNetBufferListDataStart(lVar10,uVar11,0,0);
          if (iVar5 < 0) {
LAB_1c001f20c:
            NdisFreeNetBufferList(lVar10);
LAB_1c001f21b:
            ExFreeToNPagedLookasideList(param_1 + 0x80,plVar7);
            return 0;
          }
          local_a0 = &local_90;
          local_90 = 0;
          local_a8 = uVar11;
          RtlCopyMdlToMdl(param_4[1],iVar9,*(undefined8 *)(*(longlong *)(lVar10 + 8) + 8));
          if (local_90 != uVar11) goto LAB_1c001f20c;
          iVar9 = iVar9 + uVar4;
          plVar7[4] = lVar10;
          LOCK();
          *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
          UNLOCK();
          (**(code **)(param_1 + 0x10))(param_1 + 8,plVar7);
        }
        lVar10 = local_88 + param_4[3];
        local_88 = lVar10;
        ExFreeToNPagedLookasideList(param_1 + 0x80,plVar7);
        param_3 = local_98;
      }
    }
    param_5 = local_80;
  }
  if (param_5 != (longlong *)0x0) {
    *param_5 = lVar10;
  }
  return 0;
}



===== WskSendDatagram @ 1c001f2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WskSendDatagram(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
               longlong param_5,undefined8 param_6,longlong param_7)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined4 unaff_ESI;
  undefined4 uVar7;
  undefined8 in_stack_ffffffffffffff88;
  uint uVar8;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar9;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  uVar8 = (uint)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_3c = 0;
  lVar5 = 0;
  lVar2 = *(longlong *)(param_7 + 8);
  uVar1 = *(uint *)(param_7 + 0x18);
  uVar7 = *(undefined4 *)(param_7 + 0x10);
  if (*(longlong *)(param_1 + 0x40) == 0) {
    return unaff_ESI;
  }
  if ((*(uint *)(param_1 + 0x188) & 0x20) != 0) {
    plVar3 = *(longlong **)(param_1 + 0x180);
    if (param_2 == 0) {
      uVar7 = 0xc000000d;
      goto LAB_1c001f445;
    }
    lVar5 = IoAllocateIrp(1,0);
    if ((lVar5 != 0) &&
       (plVar6 = (longlong *)ExAllocateFromNPagedLookasideList(param_1 + 0x100),
       plVar6 != (longlong *)0x0)) {
      *(undefined4 *)((longlong)plVar6 + 0x1c) = 0;
      *(undefined8 *)((longlong)plVar6 + 0x34) = 0;
      *(undefined4 *)((longlong)plVar6 + 0x3c) = 0;
      *plVar6 = param_1;
      plVar6[4] = lVar2;
      plVar6[1] = param_4;
      plVar6[2] = param_5;
      *(undefined4 *)(plVar6 + 3) = 0;
      plVar6[5] = 0;
      *(undefined4 *)(plVar6 + 6) = 0;
      LOCK();
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + 1;
      UNLOCK();
      lVar4 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar4 + -0x10) = WskSendCompletion;
      *(longlong **)(lVar4 + -8) = plVar6;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      local_48 = lVar2;
      local_40 = uVar7;
      local_38 = (ulonglong)uVar1;
      (**(code **)(*plVar3 + 0x18))(plVar3,&local_48,0,param_2,(ulonglong)uVar8 << 0x20,0,lVar5);
      return unaff_ESI;
    }
  }
  uVar7 = 0xc000009a;
LAB_1c001f445:
  (**(code **)(param_1 + 0x40))
            (*(undefined8 *)(param_1 + 8),param_4,param_5,0,lVar2,CONCAT44(uVar9,uVar7));
  if (lVar5 != 0) {
    IoFreeIrp(lVar5);
  }
  return unaff_ESI;
}



===== WskSendCompletion @ 1c001f490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 WskSendCompletion(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  if (param_3 != (longlong *)0x0) {
    (**(code **)(*param_3 + 0x40))
              (*(undefined8 *)(*param_3 + 8),param_3[1],param_3[2],(int)param_3[3],param_3[4],
               *(undefined4 *)(param_2 + 0x30));
    if (param_3[7] != 0) {
      IoFreeMdl();
    }
    if (param_3[5] != 0) {
      ExFreePoolWithTag(param_3[5],0);
      param_3[5] = 0;
    }
    lVar3 = *param_3;
    ExFreeToNPagedLookasideList(lVar3 + 0x100,param_3);
    LOCK();
    piVar1 = (int *)(lVar3 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(lVar3 + 0x208))(lVar3);
    }
  }
  if (param_2 != 0) {
    IoFreeIrp(param_2);
  }
  return 0xc0000016;
}



===== ReceiveDataComplete @ 1c001f580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ReceiveDataComplete(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != 0) {
    NdisFreeNetBufferList(param_2);
  }
  if (param_1 != 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x200);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)(param_1 + 0x208))(param_1);
    }
  }
  return;
}



===== ProcessIpv4AddressFromPacket @ 1c001f5e0 =====

undefined8
ProcessIpv4AddressFromPacket(char *param_1,uint param_2,undefined8 param_3,undefined4 *param_4)

{
  *param_4 = 0;
  if (((param_2 < 8) || (*param_1 != 'E')) || (param_1[9] != '/')) {
    return 0xc000000d;
  }
  *param_4 = 0x14;
  return 0;
}



===== entry @ 1c0020010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0020044 =====

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



===== DriverEntry @ 1c0020078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_48;
  code *local_40;
  code *local_38;
  
  memset(&local_b8,0,0x98);
  NsiCliTag = 0x6e505450;
  KeInitializeEvent(&NsiCliDriverUnloadEvent,0,0);
  _DAT_1c000c1a8 = _NsiPptpGuid;
  uRam00000001c000c1ac = uRam00000001c000c14c;
  uRam00000001c000c1b0 = uRam00000001c000c150;
  uRam00000001c000c1b4 = uRam00000001c000c154;
  uVar2 = NmrRegisterClient(&NsiCliNotify,0,&NsiCliHandle);
  if ((int)uVar2 == 0) {
    LOCK();
    NsiCliDriverRefCount = NsiCliDriverRefCount + 1;
    UNLOCK();
    uVar1 = WskStartClientModule();
    if (uVar1 == 0) {
      KeInitializeSpinLock(&gCallbackLock);
      local_b8 = 0x98028a;
      local_a8 = MiniportSetOptions;
      local_b4 = 0x11e06;
      local_a0 = MiniportInitializeEx;
      local_98 = MiniportHaltEx;
      local_90 = MiniportUnload;
      local_88 = MiniportPause;
      local_80 = MiniportRestart;
      local_70 = _guard_check_icall;
      local_68 = MiniportReturnNetBufferLists;
      local_60 = _guard_check_icall;
      local_48 = _guard_check_icall;
      local_40 = _guard_check_icall;
      local_38 = _guard_check_icall;
      uVar1 = NdisMRegisterMiniportDriver(param_1,param_2,0,&local_b8,&gMiniportDriverHandle);
      if (uVar1 == 0) {
        DAT_1c000c4c8 = &WPP_ThisDir_CTLGUID_CtlGuid;
        _WPP_MAIN_CB = 0;
        DAT_1c000c4d0 = 0;
        _DAT_1c000c4e0 = 0;
        _DAT_1c000c4e8 = 1;
        gDriverObject = param_1;
        WppLoadTracingSupport();
        _DAT_1c000c4e0 = 0;
        WppInitKm();
        return 0;
      }
      MiniportUnload();
    }
    else {
      NsiCliDeregisterClient();
    }
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}


