
===== FtpAnalyzerParseIp4Endpoint @ 140001010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FtpAnalyzerParseIp4Endpoint(longlong param_1,longlong param_2,char *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStackY_b8 [32];
  int local_68;
  undefined1 local_64;
  undefined1 local_50;
  undefined1 local_4e;
  char local_4c;
  byte local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined1 auStack_18 [4];
  ushort local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar6 = 0;
  do {
    uVar5 = (uint)uVar6;
    pcVar4 = param_3;
    if (5 < uVar5) {
      iVar1 = FtpAnalyzerAddSecondaryFilter
                        (param_1,param_2,'\x04',uVar6,local_14 >> 8 | local_14 << 8);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids,iVar1);
        }
LAB_140001277:
        uVar2 = 1;
      }
      else {
        uVar2 = 2;
      }
      return uVar2;
    }
    for (; (byte)(*pcVar4 - 0x30U) < 10; pcVar4 = pcVar4 + 1) {
    }
    if (pcVar4 <= param_3) {
      memset(&local_68,0,0x50);
      uVar2 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_68);
      local_30 = *(undefined4 *)(param_1 + 0x38);
      local_38 = *(undefined8 *)(param_1 + 0x30);
      if (((local_4c == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        pcVar4 = "no digits";
LAB_1400011ed:
        WPP_SF_DHDHDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,uVar2,local_68,
                      local_50,local_64,local_4e,local_40 & 1,pcVar4);
      }
      goto LAB_140001277;
    }
    if (3 < (longlong)pcVar4 - (longlong)param_3) {
LAB_140001127:
      memset(&local_68,0,0x50);
      uVar2 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_68);
      local_30 = *(undefined4 *)(param_1 + 0x38);
      local_38 = *(undefined8 *)(param_1 + 0x30);
      if (((local_4c == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        pcVar4 = "bad digits";
        goto LAB_1400011ed;
      }
      goto LAB_140001277;
    }
    uVar3 = 0;
    for (; param_3 < pcVar4; param_3 = param_3 + 1) {
      if (9 < (byte)(*param_3 - 0x30U)) goto LAB_140001127;
      uVar3 = (int)*param_3 + (uVar3 * 5 + -0x18) * 2;
    }
    if (0xff < uVar3) goto LAB_140001127;
    auStack_18[uVar6] = (char)uVar3;
    if (uVar5 < 5) {
      if (*pcVar4 != ',') {
        memset(&local_68,0,0x50);
        uVar2 = 0;
        MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_68);
        local_30 = *(undefined4 *)(param_1 + 0x38);
        local_38 = *(undefined8 *)(param_1 + 0x30);
        if (((local_4c == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          pcVar4 = "no comma";
          goto LAB_1400011ed;
        }
        goto LAB_140001277;
      }
      pcVar4 = pcVar4 + 1;
    }
    uVar6 = (ulonglong)(uVar5 + 1);
    param_3 = pcVar4;
  } while( true );
}



===== FtpAnalyzerParseExtendedEndpoint @ 1400012b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FtpAnalyzerParseExtendedEndpoint(longlong param_1,longlong param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  undefined8 uVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  byte *pbVar9;
  undefined1 auStackY_f8 [32];
  ushort local_a8 [4];
  byte *local_a0;
  int local_98;
  undefined1 local_94;
  undefined1 local_80;
  undefined1 local_7e;
  char local_7c;
  byte local_70;
  undefined8 local_68;
  undefined4 local_60;
  uint local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  bVar1 = *param_3;
  local_a8[0] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  if (((((byte)(bVar1 - 0x30) < 10) || ((byte)(bVar1 + 0x9f) < 6)) || ((byte)(bVar1 + 0xbf) < 6)) ||
     ((bVar1 < 0x3b && ((0x400400000002400U >> ((longlong)(char)bVar1 & 0x3fU) & 1) != 0)))) {
    memset(&local_98,0,0x50);
    uVar3 = 0;
    MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
    local_60 = *(undefined4 *)(param_1 + 0x38);
    local_68 = *(undefined8 *)(param_1 + 0x30);
    if (local_7c != '\x04') {
      return 1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 1;
    }
    pcVar4 = "delimiter invalid character";
    goto LAB_1400017fa;
  }
  if (param_4 == 0) {
    iVar6 = (int)(char)param_3[1];
    iVar7 = iVar6 + -0x30;
    if (param_3[2] != bVar1) {
      memset(&local_98,0,0x50);
      uVar3 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
      local_60 = *(undefined4 *)(param_1 + 0x38);
      local_68 = *(undefined8 *)(param_1 + 0x30);
      if (local_7c != '\x04') {
        return 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 1;
      }
      pcVar4 = "bad delimiter after address family";
      goto LAB_1400017fa;
    }
    local_a0 = param_3 + 3;
    bVar2 = param_3[3];
    pbVar5 = local_a0;
    while ((bVar2 != bVar1 && (bVar2 != 0xd))) {
      pbVar9 = pbVar5 + 1;
      pbVar5 = pbVar5 + 1;
      bVar2 = *pbVar9;
    }
    if (iVar6 == 0x31) {
      uVar3 = IP4StringToAddress((char *)local_a0,0,&local_a0,local_48);
      iVar6 = (int)uVar3;
LAB_1400013f6:
      if (iVar6 == 0) {
        if (local_a0 != pbVar5) {
          memset(&local_98,0,0x50);
          uVar3 = 0;
          MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
          local_60 = *(undefined4 *)(param_1 + 0x38);
          local_68 = *(undefined8 *)(param_1 + 0x30);
          if (local_7c != '\x04') {
            return 1;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
            return 1;
          }
          pcVar4 = "bad address terminator";
          goto LAB_1400017fa;
        }
        if (*pbVar5 != bVar1) {
          memset(&local_98,0,0x50);
          uVar3 = 0;
          MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
          local_60 = *(undefined4 *)(param_1 + 0x38);
          local_68 = *(undefined8 *)(param_1 + 0x30);
          if (local_7c != '\x04') {
            return 1;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
            return 1;
          }
          pcVar4 = "bad delimiter after address";
          goto LAB_1400017fa;
        }
        pbVar5 = pbVar5 + 1;
        pbVar9 = pbVar5;
        goto LAB_1400015cb;
      }
    }
    else if (iVar6 == 0x32) {
      uVar3 = IP6StringToAddress((char *)local_a0,&local_a0,(longlong)local_48);
      iVar6 = (int)uVar3;
      goto LAB_1400013f6;
    }
    memset(&local_98,0,0x50);
    uVar3 = 0;
    MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
    local_60 = *(undefined4 *)(param_1 + 0x38);
    local_68 = *(undefined8 *)(param_1 + 0x30);
    if (local_7c != '\x04') {
      return 1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 1;
    }
    pcVar4 = "bad address";
  }
  else {
    iVar7 = ((*(byte *)(param_1 + 8) & 2) != 0) + 1;
    if ((param_3[1] != bVar1) && (param_3[2] != bVar1)) {
      memset(&local_98,0,0x50);
      uVar3 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
      local_60 = *(undefined4 *)(param_1 + 0x38);
      local_68 = *(undefined8 *)(param_1 + 0x30);
      if (local_7c != '\x04') {
        return 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 1;
      }
      pcVar4 = "bad empty fields";
      goto LAB_1400017fa;
    }
    pbVar5 = param_3 + 3;
    pbVar9 = pbVar5;
LAB_1400015cb:
    for (; (byte)(*pbVar5 - 0x30) < 10; pbVar5 = pbVar5 + 1) {
    }
    if (pbVar9 < pbVar5) {
      if (*pbVar5 == bVar1) {
        uVar3 = ParseDec16bit((char *)pbVar9,(char *)pbVar5,local_a8);
        if ((int)uVar3 != 0) {
          cVar8 = '\x06';
          if (iVar7 != 2) {
            cVar8 = '\x04';
          }
          iVar7 = FtpAnalyzerAddSecondaryFilter(param_1,param_2,cVar8,pbVar9,local_a8[0]);
          if (-1 < iVar7) {
            return 2;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return 1;
          }
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids,iVar7);
          return 1;
        }
        memset(&local_98,0,0x50);
        uVar3 = 0;
        MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
        local_60 = *(undefined4 *)(param_1 + 0x38);
        local_68 = *(undefined8 *)(param_1 + 0x30);
        if (local_7c != '\x04') {
          return 1;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 1;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return 1;
        }
        pcVar4 = "bad port";
      }
      else {
        memset(&local_98,0,0x50);
        uVar3 = 0;
        MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
        local_60 = *(undefined4 *)(param_1 + 0x38);
        local_68 = *(undefined8 *)(param_1 + 0x30);
        if (local_7c != '\x04') {
          return 1;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 1;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return 1;
        }
        pcVar4 = "bad delimiter after port";
      }
    }
    else {
      memset(&local_98,0,0x50);
      uVar3 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_98);
      local_60 = *(undefined4 *)(param_1 + 0x38);
      local_68 = *(undefined8 *)(param_1 + 0x30);
      if (local_7c != '\x04') {
        return 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 1;
      }
      pcVar4 = "no port";
    }
  }
LAB_1400017fa:
  WPP_SF_DHDHDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar4,uVar3,local_98,local_80,local_94,
                local_7e,local_70 & 1,pcVar4);
  return 1;
}



===== CreateFilter @ 140001860 =====

undefined4 CreateFilter(uint param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 *_Dst;
  uint uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = param_3;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
      puVar3 = (undefined8 *)&WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids;
      param_2 = 0x13;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,puVar3,param_1);
    }
  }
  if (param_1 < 0x186a1) {
    uVar1 = param_1 + 0x20;
    if (uVar1 < 0x21) {
      return 0x80000005;
    }
    _Dst = (undefined4 *)ExAllocatePool2(0x40,uVar1,0x52544c46);
    if (_Dst != (undefined4 *)0x0) {
      memset(_Dst,0,(ulonglong)uVar1);
      *_Dst = 1;
      *(undefined1 *)(_Dst + 1) = 1;
      *param_3 = _Dst;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
      }
      return 0;
    }
    uVar2 = 0xc0000017;
  }
  else {
    uVar2 = 0xc000000d;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400019bb;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,0xc000000d);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,uVar2);
  }
LAB_1400019bb:
  *param_3 = 0;
  return uVar2;
}



===== FtpAnalyzerAddSecondaryFilter @ 1400019e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FtpAnalyzerAddSecondaryFilter
              (longlong param_1,longlong param_2,char param_3,undefined8 param_4,ushort param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_128 [32];
  undefined8 local_d8;
  undefined4 local_d0;
  int local_c8;
  undefined1 local_c4;
  undefined1 local_b0;
  undefined1 local_ae;
  char local_ac;
  byte local_a0;
  undefined8 local_98;
  undefined4 local_90;
  longlong local_78 [3];
  char local_5c;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(local_78,0,0x50);
  local_d8 = 0;
  local_d0 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids);
  }
  uVar3 = 0;
  MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,(int *)local_78);
  local_40 = *(undefined4 *)(param_1 + 0x38);
  local_48 = *(undefined8 *)(param_1 + 0x30);
  if (local_5c == param_3) {
    if (param_5 < 0x400) {
      memset(&local_c8,0,0x50);
      uVar3 = 0;
      MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_c8);
      local_90 = *(undefined4 *)(param_1 + 0x38);
      local_98 = *(undefined8 *)(param_1 + 0x30);
      if (((local_ac == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_DHDHDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"endpoint port reserved",uVar3,
                      local_c8,local_b0,local_c4,local_ae,local_a0 & 1,"endpoint port reserved");
      }
      iVar1 = -0x3ffffff3;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) goto LAB_140001c67;
      uVar2 = 0xd;
      iVar1 = -0x3ffffff3;
    }
    else {
      local_d8 = CONCAT71(local_d8._1_7_,6);
      local_d8._0_4_ = CONCAT13(8,(undefined3)local_d8);
      local_d8 = CONCAT26(param_5,CONCAT24(param_5,CONCAT22((short)((uint)(undefined4)local_d8 >>
                                                                   0x10),
                                                            CONCAT11(~*(byte *)(param_2 + 0xe),6))))
                 & 0xffffffffffff01ff;
      iVar1 = AddSecondaryIpFilter(local_78,uVar3,(undefined1 *)&local_d8);
      if (-1 < iVar1) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar1;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
          return iVar1;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids);
        return iVar1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) goto LAB_140001c67;
      uVar2 = 0xe;
    }
  }
  else {
    memset(&local_c8,0,0x50);
    uVar3 = 0;
    MpsGetFwpAuthData(*(short **)(param_2 + 0x18),0,0,&local_c8);
    local_90 = *(undefined4 *)(param_1 + 0x38);
    local_98 = *(undefined8 *)(param_1 + 0x30);
    if (((local_ac == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_DHDHDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"IP4/IP6 mismatch",uVar3,local_c8,
                    local_b0,local_c4,local_ae,local_a0 & 1,"IP4/IP6 mismatch");
    }
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) goto LAB_140001c67;
    uVar2 = 0xc;
    iVar1 = -0x3ffffff3;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids,iVar1);
LAB_140001c67:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids,iVar1);
  }
  return iVar1;
}



===== AddSecondaryIpFilter @ 140001cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AddSecondaryIpFilter(longlong *param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  byte bVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  int *piVar6;
  ushort uVar7;
  int iVar8;
  undefined *puVar9;
  undefined2 uVar10;
  int *_Dst;
  undefined1 auStackY_b8 [32];
  int *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_48 = (int *)0x0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  iVar8 = 0x80;
  if (*(char *)((longlong)param_1 + 0x1c) != '\x06') {
    iVar8 = 0x40;
  }
  iVar8 = CreateFilter(iVar8 + (int)param_1[7],param_2,&local_48);
  piVar6 = local_48;
  if (iVar8 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140002064;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar10 = 0x10;
LAB_140002026:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_22c82edf472934362cca16c116ec1405_Traceguids,iVar8);
    }
  }
  else {
    *(undefined1 *)((longlong)local_48 + 5) = 2;
    _Dst = local_48 + 0x18;
    *(undefined2 *)((longlong)local_48 + 0x22) = 6;
    if (*(char *)((longlong)param_1 + 0x1c) == '\x06') {
      *(int **)(local_48 + 0x10) = _Dst;
      *(undefined2 *)((longlong)local_48 + 0x22) = 0x4006;
      *(int **)(local_48 + 0xe) = local_48 + 0x20;
      _Dst = local_48 + 0x28;
      uVar5 = ((undefined8 *)param_1[1])[1];
      *(undefined8 *)(local_48 + 0x1c) = *(undefined8 *)param_1[1];
      *(undefined8 *)(local_48 + 0x1e) = uVar5;
      puVar3 = *(undefined8 **)(local_48 + 0x10);
      *puVar3 = puVar3[2];
      puVar3[1] = puVar3[3];
      lVar4 = *(longlong *)(local_48 + 0xe);
      uVar5 = ((undefined8 *)*param_1)[1];
      *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)*param_1;
      *(undefined8 *)(lVar4 + 0x18) = uVar5;
      puVar3 = *(undefined8 **)(local_48 + 0xe);
      *puVar3 = puVar3[2];
      puVar3[1] = puVar3[3];
    }
    else {
      iVar8 = *(int *)((longlong)param_1 + 4);
      local_48[0x11] = iVar8;
      local_48[0x10] = iVar8;
      lVar4 = *param_1;
      local_48[0xf] = (int)lVar4;
      local_48[0xe] = (int)lVar4;
    }
    *(int **)(local_48 + 0x14) = _Dst;
    local_48[0x16] = (int)param_1[7];
    memmove(_Dst,(void *)param_1[6],(ulonglong)*(uint *)(param_1 + 7));
    bVar2 = param_3[3];
    if ((bVar2 & 8) != 0) {
      if (param_3[1] == '\0') {
        piVar6[0x13] = *(int *)(param_3 + 4);
        uVar7 = *(ushort *)((longlong)piVar6 + 0x22) | 8;
      }
      else {
        piVar6[0x12] = *(int *)(param_3 + 4);
        uVar7 = *(ushort *)((longlong)piVar6 + 0x22) | 0x10;
      }
      *(ushort *)((longlong)piVar6 + 0x22) = uVar7;
    }
    if ((bVar2 & 0x10) != 0) {
      if (param_3[1] == '\x01') {
        piVar6[0x13] = *(int *)(param_3 + 8);
        uVar7 = *(ushort *)((longlong)piVar6 + 0x22) | 8;
      }
      else {
        piVar6[0x12] = *(int *)(param_3 + 8);
        uVar7 = *(ushort *)((longlong)piVar6 + 0x22) | 0x10;
      }
      *(ushort *)((longlong)piVar6 + 0x22) = uVar7;
    }
    *(ushort *)((longlong)piVar6 + 0x22) = *(ushort *)((longlong)piVar6 + 0x22) | 1;
    *(undefined1 *)(piVar6 + 0xc) = *param_3;
    piVar6[9] = 1;
    uVar7 = *(ushort *)((longlong)piVar6 + 0x22);
    *(longlong *)(piVar6 + 10) = _DAT_fffff78000000014 + 150000000;
    if ((uVar7 >> 0xe & 1) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_DdDddDdddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                          (ulonglong)*(byte *)(piVar6 + 0xc),(uint)uVar7,*(byte *)(piVar6 + 0xc),
                          (char)((uint)piVar6[0x10] >> 0x18),(char)piVar6[0x13],
                          (char)*(undefined2 *)((longlong)piVar6 + 0x4e),
                          (char)((uint)piVar6[0xe] >> 0x18),(char)piVar6[0x12],
                          (char)*(undefined2 *)((longlong)piVar6 + 0x4a),(char)piVar6[0x16],
                          *(wchar_t **)(piVar6 + 0x14));
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_Dd_IPV6_dd_IPV6_dddS
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 (ulonglong)*(ushort *)((longlong)piVar6 + 0x4a),(uint)uVar7,(char)piVar6[0xc],
                 *(undefined8 *)(piVar6 + 0x10),(char)piVar6[0x13],
                 (char)*(undefined2 *)((longlong)piVar6 + 0x4e),*(undefined8 *)(piVar6 + 0xe),
                 (char)piVar6[0x12],(char)*(ushort *)((longlong)piVar6 + 0x4a),(char)piVar6[0x16],
                 *(wchar_t **)(piVar6 + 0x14));
    }
    puVar9 = &DAT_1400157a8;
    KeAcquireInStackQueuedSpinLock(&DAT_1400157a8,&local_40);
    iVar8 = AddFilterToList(puVar9,(longlong)local_48);
    KeReleaseInStackQueuedSpinLock(&local_40);
    if (-1 < iVar8) {
      return iVar8;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140002064;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar10 = 0x13;
      goto LAB_140002026;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_22c82edf472934362cca16c116ec1405_Traceguids,iVar8);
  }
LAB_140002064:
  piVar6 = local_48;
  if (local_48 != (int *)0x0) {
    LOCK();
    iVar1 = *local_48;
    *local_48 = *local_48 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      if ((*(byte *)(local_48 + 1) < 2) &&
         ((code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(local_48 + 1) * 8) !=
          (code *)0x0)) {
        (*(code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(local_48 + 1) * 8))
                  (local_48);
      }
      ExFreePoolWithTag(piVar6,0);
    }
  }
  return iVar8;
}



===== MpsQueryUserCallout @ 1400020f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MpsQueryUserCallout(short *param_1,undefined8 param_2,undefined8 param_3)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 *in_stack_00000038;
  undefined1 auStackY_138 [32];
  undefined4 local_e8;
  undefined2 local_e4;
  undefined2 uStack_e2;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 local_cc;
  undefined4 *local_c8;
  undefined8 local_b8;
  undefined8 local_b0;
  ushort local_a0;
  ushort local_9e;
  char local_9c;
  byte local_9b;
  wchar_t *local_88;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  memset(&local_b8,0,0x50);
  MpsGetFwpAuthData(param_1,param_2,param_3,(int *)&local_b8);
  if (local_9c == '\x04') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dDdDdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_9e,
                    (ulonglong)
                    (local_b8._4_4_ >> 0x18 | (local_b8._4_4_ & 0xff0000) >> 8 |
                     (local_b8._4_4_ & 0xff00) << 8 | local_b8._4_4_ << 0x18),(uint)local_9b,
                    (char)(local_b8._4_4_ >> 0x18),(char)local_9e,
                    (char)((uint)(int)local_b8 >> 0x18),(char)local_a0,local_88);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_d_IPV6_d_IPV6_dS
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_a0,(ulonglong)local_9e,
               (uint)local_9b,local_b0,(char)local_9e,CONCAT44(local_b8._4_4_,(int)local_b8),
               (char)local_a0,local_88);
  }
  local_d4 = 0;
  uStack_d0 = 0;
  uStack_e2 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  local_e4 = 0x401;
  local_e8 = 0;
  local_cc = 0;
  uVar3 = SendDfwNotification(&local_b8,(longlong)&local_e8);
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    AuditOneArgError(iVar2,0x13a8);
  }
  pwVar4 = wcsstr(local_88,L"sihost");
  if ((((pwVar4 != (wchar_t *)0x0) && (m_QueryUserDumpCountSihost < 2)) ||
      ((pwVar4 = wcsstr(local_88,L"filecoauth"), pwVar4 != (wchar_t *)0x0 &&
       (m_QueryUserDumpCountOtherExe < 2)))) && (-1 < iVar2)) {
    local_cc = 0;
    local_e8 = 1;
    local_e4 = 0x28;
    uStack_e2 = 0;
    local_68 = 1;
    local_60 = 1;
    local_c8 = &local_68;
    local_64 = 0x30;
    uStack_d0 = 0x10;
    uStack_e0 = 0;
    uStack_dc = 0;
    uStack_d8 = 0;
    local_d4 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    DbgkWerCaptureLiveKernelDump2(L"mpsdrv.sys",0x400001ee,local_88,0);
    pwVar4 = wcsstr(local_88,L"sihost");
    if (pwVar4 == (wchar_t *)0x0) {
      m_QueryUserDumpCountOtherExe = m_QueryUserDumpCountOtherExe + 1;
    }
    else {
      m_QueryUserDumpCountSihost = m_QueryUserDumpCountSihost + 1;
    }
  }
  sVar1 = *param_1;
  if ((sVar1 == 0x32) ||
     ((((sVar1 != 0x2a && (sVar1 != 0x24)) && (sVar1 != 0x26)) && (sVar1 != 0x28)))) {
    *in_stack_00000038 = 0x1001;
  }
  else {
    *in_stack_00000038 = 0x2006;
  }
  return uVar3 & 0xffffffff;
}



===== MpsLoggingCallout @ 1400023d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
MpsLoggingCallout(short *param_1,longlong param_2,longlong param_3,undefined8 param_4,
                 longlong param_5,undefined8 param_6,undefined4 *param_7)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  char cVar8;
  undefined1 auStack_188 [32];
  ulonglong local_168;
  uint local_158;
  undefined4 uStack_154;
  undefined8 uStack_150;
  uint local_148;
  int local_138;
  undefined4 uStack_134;
  undefined4 *local_130;
  ushort local_120;
  ushort local_11e;
  char local_11c;
  char local_11b;
  longlong local_118;
  uint local_110;
  undefined8 local_f0;
  undefined2 local_e8 [2];
  undefined1 local_e4;
  ulonglong local_e0;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  int local_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  ushort local_90;
  ushort local_8e;
  char local_8c;
  uint local_88;
  uint local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined8 local_70;
  int local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_188;
  memset(&local_138,0,0x50);
  local_158 = 0;
  uStack_154 = 0;
  uStack_150 = 0;
  bVar1 = *(byte *)(param_5 + 0x30);
  MpsGetFwpAuthData(param_1,param_2,param_3,&local_138);
  cVar8 = local_11b;
  sVar2 = *param_1;
  if (sVar2 == 0x36) {
switchD_1400028e2_caseD_34:
    if ((bVar1 & 2) == 0) goto switchD_1400028e2_caseD_1e;
    memset(local_e8,0,0x98);
    local_bc = 0x20000;
    local_88 = local_110 & 1 | local_88 & 0xfffffffe;
    local_e4 = 0;
    local_e8[0] = 0x98;
    local_b8 = 0x636f6e6e;
    local_b4 = 0x98;
    local_d0 = 0x45740edba66c1d93;
    uStack_c8 = 0x502cbf1c3305e882;
    local_84 = local_158;
    uStack_80 = uStack_154;
    uStack_7c = (undefined4)uStack_150;
    uStack_78 = uStack_150._4_4_;
    if (local_118 != 0) {
      local_58 = *(undefined8 *)(local_118 + 0x40);
    }
    if (local_11c == '\x06') {
      piVar4 = (int *)CONCAT44(uStack_134,local_138);
      local_88 = local_88 | 2;
      if (piVar4 != (int *)0x0) {
        local_b0 = *piVar4;
        iStack_ac = piVar4[1];
        iStack_a8 = piVar4[2];
        iStack_a4 = piVar4[3];
      }
      if (local_130 != (undefined4 *)0x0) {
        local_a0 = *local_130;
        uStack_9c = local_130[1];
        uStack_98 = local_130[2];
        uStack_94 = local_130[3];
      }
    }
    else {
      local_b0 = local_138;
      local_a0 = uStack_134;
    }
    local_8c = local_11b;
    if ((local_11b == '\x01') || (local_11b == ':')) {
      local_8e = local_120 & 0xff;
      local_11e = local_120 >> 8;
    }
    else {
      local_8e = local_120;
    }
    local_60 = local_f0;
    local_64 = 0;
    local_74 = 2;
    LOCK();
    UNLOCK();
    local_68 = g_LogSequence + 1;
    local_70 = _DAT_fffff78000000014;
    local_90 = local_11e;
    if (ETWLOG_CONTROL_DATA == 0) {
      iVar5 = -0x3ffffff8;
      g_LogSequence = g_LogSequence + 1;
    }
    else {
      local_e0 = 0xffff;
      if ((short)ETWLOG_CONTROL_DATA != -1) {
        local_e0 = ETWLOG_CONTROL_DATA & 0xffff;
      }
      g_LogSequence = g_LogSequence + 1;
      iVar5 = IoWMIWriteEvent(local_e8);
      if (-1 < iVar5) goto switchD_1400028e2_caseD_1e;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto switchD_1400028e2_caseD_1e;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_686923aaf3633c52165a5977ed8a535a_Traceguids,iVar5);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto switchD_1400028e2_caseD_1e;
    uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  }
  else {
    if (sVar2 != 0x1f) {
      switch(sVar2) {
      case 0x1d:
      case 0x21:
      case 0x23:
      case 0x2d:
      case 0x2f:
      case 0x31:
      case 0x33:
        break;
      default:
        goto switchD_1400028e2_caseD_1e;
      case 0x34:
        goto switchD_1400028e2_caseD_34;
      }
    }
    if ((bVar1 & 1) == 0) goto switchD_1400028e2_caseD_1e;
    local_148 = (uint)(local_11c == '\x06');
    iVar5 = 0;
    if (*(int *)(param_2 + 0x28) != 0) {
      if (*(int *)(param_2 + 0x2c) == 0) {
LAB_140002612:
        local_168 = 0;
        iVar6 = NdisRetreatNetBufferListDataStart(param_3,*(undefined4 *)(param_2 + 0x28),0,0);
        if (iVar6 == 0) {
          iVar5 = iVar5 + *(int *)(param_2 + 0x28);
          local_168 = local_168 & 0xffffffff00000000;
          if (local_148 == 0) {
            lVar7 = NdisGetDataBuffer();
            if (lVar7 != 0) {
              local_158 = (uint)(ushort)(*(ushort *)(lVar7 + 2) >> 8 | *(ushort *)(lVar7 + 2) << 8);
            }
          }
          else {
            lVar7 = NdisGetDataBuffer(*(undefined8 *)(param_3 + 8),0x28,0,1);
            if (lVar7 != 0) {
              local_158 = (uint)(ushort)(*(ushort *)(lVar7 + 4) >> 8 | *(ushort *)(lVar7 + 4) << 8)
                          + *(int *)(param_2 + 0x28);
            }
          }
        }
        if (iVar5 != 0) {
          NdisAdvanceNetBufferListDataStart(param_3,iVar5,0,0);
        }
      }
      else {
        local_168 = 0;
        iVar5 = NdisRetreatNetBufferListDataStart(param_3,*(int *)(param_2 + 0x2c),0,0);
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_2 + 0x2c);
          if (cVar8 == '\x06') {
            local_168 = local_168 & 0xffffffff00000000;
            lVar7 = NdisGetDataBuffer(*(undefined8 *)(param_3 + 8),0x14,0,1);
            if (lVar7 != 0) {
              uStack_154 = *(undefined4 *)(lVar7 + 4);
              uStack_150 = CONCAT44(CONCAT22(CONCAT11(uStack_150._7_1_,*(undefined1 *)(lVar7 + 0xd))
                                             ,*(undefined2 *)(lVar7 + 0xe)),
                                    *(undefined4 *)(lVar7 + 8));
            }
          }
          goto LAB_140002612;
        }
      }
      cVar8 = local_11b;
    }
    memset(local_e8,0,0x98);
    local_88 = local_110 & 1 | local_88 & 0xfffffffe;
    local_bc = 0x20000;
    local_e4 = 0;
    local_e8[0] = 0x98;
    local_b8 = 0x636f6e6e;
    local_b4 = 0x98;
    local_d0 = 0x45740edba66c1d93;
    uStack_c8 = 0x502cbf1c3305e882;
    local_84 = local_158;
    uStack_80 = uStack_154;
    uStack_7c = (undefined4)uStack_150;
    uStack_78 = uStack_150._4_4_;
    if (local_118 != 0) {
      local_58 = *(undefined8 *)(local_118 + 0x40);
    }
    if (local_11c == '\x06') {
      piVar4 = (int *)CONCAT44(uStack_134,local_138);
      local_88 = local_88 | 2;
      if (piVar4 != (int *)0x0) {
        local_b0 = *piVar4;
        iStack_ac = piVar4[1];
        iStack_a8 = piVar4[2];
        iStack_a4 = piVar4[3];
      }
      if (local_130 != (undefined4 *)0x0) {
        local_a0 = *local_130;
        uStack_9c = local_130[1];
        uStack_98 = local_130[2];
        uStack_94 = local_130[3];
      }
    }
    else {
      local_b0 = local_138;
      local_a0 = uStack_134;
    }
    if ((cVar8 == '\x01') || (cVar8 == ':')) {
      local_8e = local_120 & 0xff;
      local_11e = local_120 >> 8;
    }
    else {
      local_8e = local_120;
    }
    local_60 = local_f0;
    local_64 = 0;
    local_74 = 1;
    LOCK();
    UNLOCK();
    local_68 = g_LogSequence + 1;
    local_70 = _DAT_fffff78000000014;
    local_90 = local_11e;
    local_8c = cVar8;
    if (ETWLOG_CONTROL_DATA == 0) {
      iVar5 = -0x3ffffff8;
      g_LogSequence = g_LogSequence + 1;
    }
    else {
      local_e0 = 0xffff;
      if ((short)ETWLOG_CONTROL_DATA != -1) {
        local_e0 = ETWLOG_CONTROL_DATA & 0xffff;
      }
      g_LogSequence = g_LogSequence + 1;
      iVar5 = IoWMIWriteEvent(local_e8);
      if (-1 < iVar5) goto switchD_1400028e2_caseD_1e;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto switchD_1400028e2_caseD_1e;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_686923aaf3633c52165a5977ed8a535a_Traceguids,iVar5);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto switchD_1400028e2_caseD_1e;
    uVar3 = *(uint *)(WPP_GLOBAL_Control + 0x2c);
  }
  if ((uVar3 & 1) != 0) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_686923aaf3633c52165a5977ed8a535a_Traceguids,iVar5);
  }
switchD_1400028e2_caseD_1e:
  *param_7 = 0x2006;
  return 0;
}



===== MpsSecondaryConnectionsCallout @ 1400029c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MpsSecondaryConnectionsCallout(short *param_1,undefined8 param_2,undefined *param_3)

{
  char cVar1;
  undefined7 extraout_var;
  undefined4 uVar2;
  undefined4 *in_stack_00000038;
  undefined1 auStack_88 [32];
  uint local_68 [20];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_68[8] = 0;
  local_68[9] = 0;
  local_68[10] = 0;
  local_68[0xb] = 0;
  local_68[0xc] = 0;
  local_68[0xd] = 0;
  local_68[0xe] = 0;
  local_68[0xf] = 0;
  local_68[0x10] = 0;
  local_68[0x11] = 0;
  local_68[0x12] = 0;
  local_68[0x13] = 0;
  MpsGetFwpAuthData(param_1,param_2,param_3,(int *)local_68);
  cVar1 = EvaluateSecondaryIpFilterList(local_68,param_2,param_3);
  uVar2 = 0x1002;
  if ((int)CONCAT71(extraout_var,cVar1) != 2) {
    uVar2 = 0x2006;
  }
  *in_stack_00000038 = uVar2;
  return 0;
}



===== EvaluateSecondaryIpFilterList @ 140002a50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char EvaluateSecondaryIpFilterList(uint *param_1,undefined8 param_2,undefined *param_3)

{
  ushort uVar1;
  int *piVar2;
  ulonglong uVar3;
  byte bVar4;
  int iVar5;
  undefined7 extraout_var;
  int *piVar6;
  int iVar7;
  ulonglong uVar8;
  char cVar9;
  undefined1 auStackY_c8 [32];
  uint local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_38 = 0;
  cVar9 = '\b';
  local_48 = 0;
  uStack_40 = 0;
  if (*(int *)(DAT_1400157a0 + 0x10) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
    }
  }
  else {
    if ((byte)param_1[7] == 4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        param_3 = (undefined *)(ulonglong)*(ushort *)((longlong)param_1 + 0x1a);
        WPP_SF_ddDdDddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                        (ulonglong)*(byte *)((longlong)param_1 + 0x1d),param_3,4,
                        *(byte *)((longlong)param_1 + 0x1d),(char)(param_1[1] >> 0x18),
                        (char)*(ushort *)((longlong)param_1 + 0x1a),(char)(*param_1 >> 0x18),
                        (char)param_1[6],(char)param_1[0xe],*(wchar_t **)(param_1 + 0xc));
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      param_3 = (undefined *)(ulonglong)*(ushort *)((longlong)param_1 + 0x1a);
      WPP_SF_dd_IPV6_d_IPV6_ddS
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(ushort)param_1[6],param_3,
                 (uint)(byte)param_1[7],*(undefined1 *)((longlong)param_1 + 0x1d),
                 *(undefined8 *)(param_1 + 2),(char)*(ushort *)((longlong)param_1 + 0x1a),
                 *(undefined8 *)param_1,(char)param_1[6],(char)param_1[0xe],
                 *(wchar_t **)(param_1 + 0xc));
    }
    uVar3 = _DAT_fffff78000000014;
    KeAcquireInStackQueuedSpinLock(&DAT_1400157a8,&local_48);
    uVar8 = 0;
    local_58 = 0;
    if (*(int *)(DAT_1400157a0 + 0x10) != 0) {
      do {
        piVar2 = *(int **)(*(longlong *)(DAT_1400157a0 + 8) + uVar8 * 8);
        if ((*(ulonglong *)(piVar2 + 10) < uVar3) || (piVar2[9] < 1)) {
LAB_140002b90:
          uVar1 = *(ushort *)((longlong)piVar2 + 0x22);
          if ((uVar1 & 0x4000) == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              param_3 = (undefined *)(ulonglong)*(ushort *)(piVar2 + 0x12);
              WPP_SF_DdDddDddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                               (ulonglong)*(ushort *)((longlong)piVar2 + 0x4a),param_3,(uint)uVar1,
                               (char)piVar2[0xc],(char)piVar2[0x10],(char)piVar2[0x13],
                               (char)*(undefined2 *)((longlong)piVar2 + 0x4e),(char)piVar2[0xe],
                               (char)*(ushort *)(piVar2 + 0x12),
                               (char)*(ushort *)((longlong)piVar2 + 0x4a),
                               *(wchar_t **)(piVar2 + 0x14));
LAB_140002fcc:
              uVar8 = (ulonglong)local_58;
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            param_3 = (undefined *)(ulonglong)*(ushort *)(piVar2 + 0x12);
            WPP_SF_Dd_IPV6_dd_IPV6_ddS
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                       (ulonglong)*(ushort *)((longlong)piVar2 + 0x4a),param_3,(uint)uVar1,
                       (char)piVar2[0xc],*(undefined8 *)(piVar2 + 0x10),(char)piVar2[0x13],
                       (char)*(undefined2 *)((longlong)piVar2 + 0x4e),*(undefined8 *)(piVar2 + 0xe),
                       (char)*(ushort *)(piVar2 + 0x12),(char)*(ushort *)((longlong)piVar2 + 0x4a),
                       *(wchar_t **)(piVar2 + 0x14));
            goto LAB_140002fcc;
          }
          LOCK();
          iVar5 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar5 == 1) {
            DeleteFilter((longlong)piVar2);
          }
          *(undefined8 *)(*(longlong *)(DAT_1400157a0 + 8) + uVar8 * 8) =
               *(undefined8 *)
                (*(longlong *)(DAT_1400157a0 + 8) +
                (ulonglong)(*(int *)(DAT_1400157a0 + 0x10) - 1) * 8);
          *(int *)(DAT_1400157a0 + 0x10) = *(int *)(DAT_1400157a0 + 0x10) + -1;
          iVar7 = (int)uVar8 + -1;
        }
        else {
          uVar1 = *(ushort *)((longlong)piVar2 + 0x22);
          if ((uVar1 & 0x4000) == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              param_3 = (undefined *)(ulonglong)*(byte *)(piVar2 + 0xc);
              WPP_SF_DdDddDdddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,param_3,(uint)uVar1,
                                *(byte *)(piVar2 + 0xc),(char)((uint)piVar2[0x10] >> 0x18),
                                (char)piVar2[0x13],(char)*(undefined2 *)((longlong)piVar2 + 0x4e),
                                (char)((uint)piVar2[0xe] >> 0x18),(char)piVar2[0x12],
                                (char)*(undefined2 *)((longlong)piVar2 + 0x4a),(char)piVar2[0x16],
                                *(wchar_t **)(piVar2 + 0x14));
LAB_140002ead:
              uVar8 = (ulonglong)local_58;
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            param_3 = (undefined *)(ulonglong)*(ushort *)((longlong)piVar2 + 0x4a);
            WPP_SF_Dd_IPV6_dd_IPV6_dddS
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,param_3,(uint)uVar1,
                       (char)piVar2[0xc],*(undefined8 *)(piVar2 + 0x10),(char)piVar2[0x13],
                       (char)*(undefined2 *)((longlong)piVar2 + 0x4e),*(undefined8 *)(piVar2 + 0xe),
                       (char)piVar2[0x12],(char)*(ushort *)((longlong)piVar2 + 0x4a),
                       (char)piVar2[0x16],*(wchar_t **)(piVar2 + 0x14));
            goto LAB_140002ead;
          }
          iVar7 = (int)uVar8;
          piVar6 = piVar2;
          bVar4 = MatchIpFilter(param_1,(longlong)piVar2);
          iVar5 = (int)CONCAT71(extraout_var,bVar4);
          if (iVar5 == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              param_3 = &WPP_22c82edf472934362cca16c116ec1405_Traceguids;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                      &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
            }
            if ((param_1[10] & 2) == 0) {
              piVar6 = piVar2 + 9;
              *piVar6 = *piVar6 + -1;
              if (*piVar6 < 0) goto LAB_140002b90;
            }
            cVar9 = *(char *)((longlong)piVar2 + 5);
            if (cVar9 != '\b') break;
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),piVar6,param_3,iVar5);
          }
        }
        local_58 = iVar7 + 1;
        uVar8 = (ulonglong)local_58;
      } while (local_58 < *(uint *)(DAT_1400157a0 + 0x10));
    }
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  return cVar9;
}



===== MpsGetFwpAuthData @ 140002fe0 =====

void MpsGetFwpAuthData(short *param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  short sVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  int *piVar13;
  int *piVar14;
  ulonglong uVar15;
  
  piVar13 = *(int **)(param_1 + 4);
  uVar15 = 0;
  iVar10 = 0;
  param_4[0] = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  param_4[10] = 0;
  param_4[0xb] = 0;
  param_4[0xc] = 0;
  param_4[0xd] = 0;
  param_4[0xe] = 0;
  param_4[0xf] = 0;
  param_4[0x10] = 0;
  param_4[0x11] = 0;
  param_4[0x12] = 0;
  param_4[0x13] = 0;
  *(undefined8 *)(param_4 + 8) = param_2;
  sVar1 = *param_1;
  if (sVar1 == 0x30) {
LAB_14000310e:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    *(undefined1 *)(param_4 + 7) = 4;
    if (piVar13[0x44] == 0) {
      if (piVar13[0x58] != 0) goto LAB_1400032b7;
LAB_140003135:
      uVar7 = 0;
    }
    else {
      if (piVar13[0x58] == 0) goto LAB_140003135;
LAB_1400032b7:
      uVar7 = **(undefined8 **)(piVar13 + 0x5a);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    iVar10 = 0;
    if (piVar13[0x18] != 0) {
      iVar10 = piVar13[0x1a];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    param_4[1] = iVar10;
    if (piVar13[0x14] == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = (char)piVar13[0x16];
    }
    *(char *)((longlong)param_4 + 0x1d) = cVar2;
    goto joined_r0x0001400031b1;
  }
  if (sVar1 == 0x2d) {
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_2c:
    *(undefined1 *)(param_4 + 7) = 4;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    if (piVar13[0x48] == 0) {
      if (piVar13[0x5c] != 0) goto LAB_1400032cf;
LAB_14000305c:
      uVar7 = 0;
    }
    else {
      if (piVar13[0x5c] == 0) goto LAB_14000305c;
LAB_1400032cf:
      uVar7 = **(undefined8 **)(piVar13 + 0x5e);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    iVar10 = 0;
    if (piVar13[0x18] != 0) {
      iVar10 = piVar13[0x1a];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    param_4[1] = iVar10;
    if (piVar13[0x14] != 0) goto LAB_1400032f8;
    cVar2 = '\0';
    goto LAB_1400030ce;
  }
  switch(sVar1) {
  case 1:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
  case 0:
    *(undefined1 *)(param_4 + 7) = 4;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    iVar6 = 0;
    if (piVar13[4] != 0) {
      iVar6 = piVar13[6];
    }
    *param_4 = iVar6;
    if (*piVar13 != 0) {
      iVar10 = piVar13[2];
    }
LAB_1400039f0:
    param_4[1] = iVar10;
    break;
  case 3:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
  case 2:
    *(undefined1 *)(param_4 + 7) = 6;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    uVar7 = 0;
    if (piVar13[4] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 6);
    }
    *(undefined8 *)param_4 = uVar7;
    if (*piVar13 != 0) {
      uVar15 = *(ulonglong *)(piVar13 + 2);
    }
LAB_140003a28:
    *(ulonglong *)(param_4 + 2) = uVar15;
    break;
  case 4:
    goto switchD_1400031f9_caseD_4;
  case 5:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
    goto switchD_1400031f9_caseD_4;
  case 6:
    goto switchD_1400031f9_caseD_6;
  case 7:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
    goto switchD_1400031f9_caseD_6;
  case 8:
    goto switchD_1400031f9_caseD_8;
  case 9:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_8:
    *(undefined1 *)(param_4 + 7) = 4;
    iVar6 = 0;
    if (*piVar13 != 0) {
      iVar6 = piVar13[2];
    }
    *param_4 = iVar6;
    if (piVar13[4] != 0) {
      iVar10 = piVar13[6];
    }
    param_4[1] = iVar10;
    return;
  default:
    break;
  case 0xc:
    goto switchD_1400031f9_caseD_c;
  case 0xd:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
    goto switchD_1400031f9_caseD_c;
  case 0xe:
    goto switchD_1400031f9_caseD_e;
  case 0xf:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_e:
    *(undefined1 *)(param_4 + 7) = 6;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[4] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 6);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (*piVar13 == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = *(byte *)(piVar13 + 2);
    }
    *(byte *)((longlong)param_4 + 0x1d) = bVar4;
    uVar9 = (uint)bVar4;
    if (uVar9 != 1) {
      if ((uVar9 == 6) || (iVar10 = uVar9 - 0x11, iVar10 == 0)) {
        uVar5 = 0;
        if (piVar13[0x14] != 0) {
          uVar5 = (undefined2)piVar13[0x16];
        }
        *(undefined2 *)(param_4 + 6) = uVar5;
        iVar10 = piVar13[0x10];
        goto joined_r0x0001400030f6;
      }
      goto LAB_140003ca1;
    }
    goto LAB_140003b19;
  case 0x10:
    goto switchD_1400031f9_caseD_10;
  case 0x11:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_10:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    iVar10 = 0;
    *(undefined1 *)(param_4 + 7) = 4;
    if (piVar13[0xc] != 0) {
      iVar10 = piVar13[0xe];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (piVar13[4] != 0) {
      iVar10 = piVar13[6];
    }
    param_4[1] = iVar10;
    if (*piVar13 == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = *(byte *)(piVar13 + 2);
    }
    *(byte *)((longlong)param_4 + 0x1d) = bVar4;
    uVar9 = (uint)bVar4;
    if (uVar9 != 1) {
      if ((uVar9 == 6) || (iVar10 = uVar9 - 0x11, iVar10 == 0)) {
        uVar5 = 0;
        if (piVar13[0x14] != 0) {
          uVar5 = (undefined2)piVar13[0x16];
        }
        *(undefined2 *)(param_4 + 6) = uVar5;
        iVar10 = piVar13[0x10];
        goto joined_r0x0001400030f6;
      }
      goto LAB_140003ca1;
    }
    goto LAB_140003b19;
  case 0x12:
    goto switchD_1400031f9_caseD_12;
  case 0x13:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_12:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    uVar7 = 0;
    *(undefined1 *)(param_4 + 7) = 6;
    if (piVar13[0xc] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 0xe);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[4] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 6);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (*piVar13 == 0) {
      bVar4 = 0;
    }
    else {
      bVar4 = *(byte *)(piVar13 + 2);
    }
    *(byte *)((longlong)param_4 + 0x1d) = bVar4;
    uVar9 = (uint)bVar4;
    if (uVar9 != 1) {
      if ((uVar9 == 6) || (iVar10 = uVar9 - 0x11, iVar10 == 0)) {
        uVar5 = 0;
        if (piVar13[0x14] != 0) {
          uVar5 = (undefined2)piVar13[0x16];
        }
        *(undefined2 *)(param_4 + 6) = uVar5;
        iVar10 = piVar13[0x10];
        goto joined_r0x0001400030f6;
      }
      goto LAB_140003ca1;
    }
    goto LAB_140003b19;
  case 0x14:
    goto switchD_1400031f9_caseD_14;
  case 0x15:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_14:
    *(undefined2 *)(param_4 + 7) = 0x604;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (*piVar13 != 0) {
      iVar10 = piVar13[2];
    }
    param_4[1] = iVar10;
    if (piVar13[0x10] == 0) {
      uVar5 = 0;
    }
    else {
LAB_1400038d6:
      uVar5 = (undefined2)piVar13[0x12];
    }
LAB_1400038db:
    *(undefined2 *)(param_4 + 6) = uVar5;
    if (piVar13[0xc] != 0) {
      *(short *)((longlong)param_4 + 0x1a) = (short)piVar13[0xe];
      return;
    }
    goto LAB_1400030fd;
  case 0x16:
    goto switchD_1400031f9_caseD_16;
  case 0x17:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_16:
    *(undefined2 *)(param_4 + 7) = 0x606;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (*piVar13 != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 2);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    uVar5 = 0;
    if (piVar13[0x10] != 0) goto LAB_1400038d6;
    goto LAB_1400038db;
  case 0x18:
    goto switchD_1400031f9_caseD_18;
  case 0x19:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_18:
    *(undefined1 *)(param_4 + 7) = 4;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (piVar13[4] != 0) {
      iVar10 = piVar13[6];
    }
    param_4[1] = iVar10;
    if (*piVar13 == 0) {
      return;
    }
    iVar10 = piVar13[2];
    *(char *)((longlong)param_4 + 0x1d) = (char)iVar10;
    if ((char)iVar10 != '\x11') {
      return;
    }
    uVar5 = 0;
    if (piVar13[0x14] != 0) {
      uVar5 = (undefined2)piVar13[0x16];
    }
    *(undefined2 *)(param_4 + 6) = uVar5;
    iVar10 = piVar13[0x10];
    goto joined_r0x0001400030f6;
  case 0x1a:
    goto switchD_1400031f9_caseD_1a;
  case 0x1b:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_1a:
    *(undefined1 *)(param_4 + 7) = 6;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[4] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 6);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (*piVar13 == 0) {
      return;
    }
    iVar10 = piVar13[2];
    *(char *)((longlong)param_4 + 0x1d) = (char)iVar10;
    if ((char)iVar10 != '\x11') {
      return;
    }
    uVar5 = 0;
    if (piVar13[0x14] != 0) {
      uVar5 = (undefined2)piVar13[0x16];
    }
    *(undefined2 *)(param_4 + 6) = uVar5;
    iVar10 = piVar13[0x10];
    goto joined_r0x0001400030f6;
  case 0x1c:
    goto switchD_1400031f9_caseD_1c;
  case 0x1d:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_1c:
    *(undefined2 *)(param_4 + 7) = 0x104;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    if (piVar13[0x38] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0x3a);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    iVar6 = 0;
    if (piVar13[8] != 0) {
      iVar6 = piVar13[10];
    }
    *param_4 = iVar6;
    if (piVar13[4] != 0) {
      iVar10 = piVar13[6];
    }
    param_4[1] = iVar10;
LAB_140003d2e:
    if (piVar13[0x20] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (undefined1)piVar13[0x22];
    }
    *(undefined1 *)((longlong)param_4 + 0x19) = uVar3;
    if (piVar13[0x24] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (undefined1)piVar13[0x26];
    }
    *(undefined1 *)(param_4 + 6) = uVar3;
    return;
  case 0x1e:
    goto switchD_1400031f9_caseD_1e;
  case 0x1f:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_1e:
    *(undefined2 *)(param_4 + 7) = 0x3a06;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    if (piVar13[0x38] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0x3a);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)param_4 = uVar7;
    if (piVar13[4] != 0) {
      uVar15 = *(ulonglong *)(piVar13 + 6);
    }
    *(ulonglong *)(param_4 + 2) = uVar15;
    goto LAB_140003d2e;
  case 0x20:
    goto switchD_1400031f9_caseD_20;
  case 0x21:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_20:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    *(undefined2 *)(param_4 + 7) = 0x104;
    if (piVar13[0xc] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0xe);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    iVar6 = 0;
    if (piVar13[4] != 0) {
      iVar6 = piVar13[6];
    }
    *param_4 = iVar6;
    if (*piVar13 != 0) {
      iVar10 = piVar13[2];
    }
    param_4[1] = iVar10;
    if (piVar13[0x10] == 0) {
      uVar3 = 0;
    }
    else {
LAB_140003e0b:
      uVar3 = (undefined1)piVar13[0x12];
    }
LAB_140003e14:
    *(undefined1 *)((longlong)param_4 + 0x19) = uVar3;
    if (piVar13[0x14] == 0) {
      uVar3 = 0;
      goto LAB_140003b3f;
    }
    goto LAB_140003b36;
  case 0x22:
    goto switchD_1400031f9_caseD_22;
  case 0x23:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_22:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    *(undefined2 *)(param_4 + 7) = 0x3a06;
    if (piVar13[0xc] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0xe);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    uVar7 = 0;
    if (piVar13[4] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 6);
    }
    *(undefined8 *)param_4 = uVar7;
    if (*piVar13 != 0) {
      uVar15 = *(ulonglong *)(piVar13 + 2);
    }
    *(ulonglong *)(param_4 + 2) = uVar15;
    if (piVar13[0x10] != 0) goto LAB_140003e0b;
    uVar3 = 0;
    goto LAB_140003e14;
  case 0x24:
    goto switchD_1400031f9_caseD_24;
  case 0x25:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_24:
    uVar11 = *(ushort *)(param_4 + 10);
    *(undefined1 *)(param_4 + 7) = 4;
    *(ushort *)(param_4 + 10) = uVar11 & 0xfffe | 2;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    param_4[1] = iVar10;
    if (piVar13[0x14] == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = (char)piVar13[0x16];
    }
    *(char *)((longlong)param_4 + 0x1d) = cVar2;
    if (piVar13[0x30] == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = (ushort)((uint)piVar13[0x32] >> 1) & 1;
    }
    *(ushort *)(param_4 + 10) = uVar12 << 4 | uVar11 & 0xffee | 2;
LAB_1400032a1:
    if ((cVar2 != '\x06') && (cVar2 != '\x11')) {
      return;
    }
LAB_1400030f2:
    iVar10 = piVar13[0x10];
    goto joined_r0x0001400030f6;
  case 0x26:
    goto switchD_1400031f9_caseD_26;
  case 0x27:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_26:
    uVar11 = *(ushort *)(param_4 + 10);
    *(undefined1 *)(param_4 + 7) = 6;
    *(ushort *)(param_4 + 10) = uVar11 & 0xfffe | 2;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (piVar13[0x14] == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = (char)piVar13[0x16];
    }
    *(char *)((longlong)param_4 + 0x1d) = cVar2;
    if (piVar13[0x30] == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = (ushort)((uint)piVar13[0x32] >> 1) & 1;
    }
    *(ushort *)(param_4 + 10) = uVar11 & 0xffee | 2 | uVar12 << 4;
    goto LAB_1400032a1;
  case 0x28:
    goto switchD_1400031f9_caseD_28;
  case 0x29:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_28:
    uVar11 = *(ushort *)(param_4 + 10);
    *(undefined2 *)(param_4 + 7) = 0x604;
    *(ushort *)(param_4 + 10) = uVar11 & 0xfffe | 2;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    param_4[1] = iVar10;
    if (piVar13[0x10] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (undefined2)piVar13[0x12];
    }
    *(undefined2 *)((longlong)param_4 + 0x1a) = uVar5;
    if (piVar13[0x28] != 0) {
      uVar15 = (ulonglong)((uint)piVar13[0x2a] >> 1 & 1);
    }
    *(ushort *)(param_4 + 10) = (short)uVar15 << 4 | uVar11 & 0xffee | 2;
    return;
  case 0x2a:
    goto switchD_1400031f9_caseD_2a;
  case 0x2b:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_2a:
    *(undefined2 *)(param_4 + 7) = 0x606;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe | 2;
    piVar14 = param_4;
    MpspSetAppID(piVar13,(longlong)param_4);
    iVar10 = (int)uVar15;
    if (piVar13[4] == iVar10) {
      uVar8 = uVar15;
    }
    else {
      uVar8 = *(ulonglong *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(ulonglong *)(piVar14 + 0x10) = uVar8;
    uVar8 = uVar15;
    if (piVar13[8] != iVar10) {
      uVar8 = *(ulonglong *)(piVar13 + 10);
    }
    *(ulonglong *)(piVar14 + 2) = uVar8;
    if (piVar13[0x10] != iVar10) {
      uVar15 = (ulonglong)*(ushort *)(piVar13 + 0x12);
    }
    *(short *)((longlong)piVar14 + 0x1a) = (short)uVar15;
    MpspSetDynEdge(piVar13 + 0x28,(longlong)param_4);
    return;
  case 0x2c:
    goto switchD_1400031f9_caseD_2c;
  case 0x2e:
    goto switchD_1400031f9_caseD_2e;
  case 0x2f:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_2e:
    *(undefined1 *)(param_4 + 7) = 6;
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
    if (piVar13[0x48] == 0) {
      if (piVar13[0x5c] != 0) goto LAB_140003525;
LAB_140003485:
      uVar7 = 0;
    }
    else {
      if (piVar13[0x5c] == 0) goto LAB_140003485;
LAB_140003525:
      uVar7 = **(undefined8 **)(piVar13 + 0x5e);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    uVar7 = 0;
    if (piVar13[0x18] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 0x1a);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (piVar13[0x14] == 0) {
      cVar2 = '\0';
    }
    else {
LAB_1400032f8:
      cVar2 = (char)piVar13[0x16];
    }
LAB_1400030ce:
    *(char *)((longlong)param_4 + 0x1d) = cVar2;
joined_r0x0001400031b1:
    if (cVar2 != '\x11') {
      if (cVar2 == '\x01') {
LAB_1400031ce:
        if (piVar13[0x10] == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = (undefined1)piVar13[0x12];
        }
        *(undefined1 *)((longlong)param_4 + 0x19) = uVar3;
        if (piVar13[0x1c] == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = (undefined1)piVar13[0x1e];
        }
        *(undefined1 *)(param_4 + 6) = uVar3;
        return;
      }
      if (cVar2 != '\x06') {
        if (cVar2 != ':') {
          return;
        }
        goto LAB_1400031ce;
      }
    }
    if (piVar13[0x1c] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (undefined2)piVar13[0x1e];
    }
    *(undefined2 *)(param_4 + 6) = uVar5;
    goto LAB_1400030f2;
  case 0x31:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
    goto LAB_14000310e;
  case 0x32:
    goto switchD_1400031f9_caseD_32;
  case 0x33:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_32:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
    *(undefined1 *)(param_4 + 7) = 6;
    if (piVar13[0x44] == 0) {
      if (piVar13[0x58] != 0) goto LAB_1400034fc;
LAB_14000332f:
      uVar7 = 0;
    }
    else {
      if (piVar13[0x58] == 0) goto LAB_14000332f;
LAB_1400034fc:
      uVar7 = **(undefined8 **)(piVar13 + 0x5a);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    uVar7 = 0;
    if (piVar13[0x18] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 0x1a);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (piVar13[0x14] != 0) goto LAB_1400032f8;
    cVar2 = '\0';
    goto LAB_1400030ce;
  case 0x34:
    goto switchD_1400031f9_caseD_34;
  case 0x35:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_34:
    uVar11 = *(ushort *)(param_4 + 10) | 1;
    if (*(int *)(*(longlong *)(param_1 + 4) + 200) != 0) {
      uVar11 = *(ushort *)(param_4 + 10) & 0xfffe;
    }
    *(ushort *)(param_4 + 10) = uVar11;
    *(undefined1 *)(param_4 + 7) = 4;
    if (piVar13[0x2c] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0x2e);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    iVar10 = 0;
    if (piVar13[0x18] != 0) {
      iVar10 = piVar13[0x1a];
    }
    *param_4 = iVar10;
    iVar10 = 0;
    if (piVar13[8] != 0) {
      iVar10 = piVar13[10];
    }
    param_4[1] = iVar10;
    if (piVar13[0x14] != 0) goto LAB_1400032f8;
    cVar2 = '\0';
    goto LAB_1400030ce;
  case 0x36:
    goto switchD_1400031f9_caseD_36;
  case 0x37:
    *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 8;
switchD_1400031f9_caseD_36:
    uVar11 = *(ushort *)(param_4 + 10) | 1;
    if (*(int *)(*(longlong *)(param_1 + 4) + 200) != 0) {
      uVar11 = *(ushort *)(param_4 + 10) & 0xfffe;
    }
    *(ushort *)(param_4 + 10) = uVar11;
    *(undefined1 *)(param_4 + 7) = 6;
    if (piVar13[0x2c] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = **(undefined8 **)(piVar13 + 0x2e);
    }
    *(undefined8 *)(param_4 + 0x12) = uVar7;
    if (*piVar13 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 2) + 8);
    }
    *(undefined8 *)(param_4 + 0xc) = uVar7;
    if (*piVar13 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = **(int **)(piVar13 + 2);
    }
    param_4[0xe] = iVar10;
    if (piVar13[4] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(*(longlong *)(piVar13 + 6) + 8);
    }
    *(undefined8 *)(param_4 + 0x10) = uVar7;
    uVar7 = 0;
    if (piVar13[0x18] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 0x1a);
    }
    *(undefined8 *)param_4 = uVar7;
    uVar7 = 0;
    if (piVar13[8] != 0) {
      uVar7 = *(undefined8 *)(piVar13 + 10);
    }
    *(undefined8 *)(param_4 + 2) = uVar7;
    if (piVar13[0x14] != 0) goto LAB_1400032f8;
    cVar2 = '\0';
    goto LAB_1400030ce;
  }
  return;
switchD_1400031f9_caseD_6:
  *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
  uVar7 = 0;
  *(undefined1 *)(param_4 + 7) = 6;
  if (piVar13[8] != 0) {
    uVar7 = *(undefined8 *)(piVar13 + 10);
  }
  *(undefined8 *)param_4 = uVar7;
  if (*piVar13 != 0) {
    *(undefined8 *)(param_4 + 2) = *(undefined8 *)(piVar13 + 2);
    return;
  }
  goto LAB_140003a28;
switchD_1400031f9_caseD_4:
  *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) | 1;
  iVar6 = 0;
  *(undefined1 *)(param_4 + 7) = 4;
  if (piVar13[8] != 0) {
    iVar6 = piVar13[10];
  }
  *param_4 = iVar6;
  if (*piVar13 != 0) {
    param_4[1] = piVar13[2];
    return;
  }
  goto LAB_1400039f0;
switchD_1400031f9_caseD_c:
  *(undefined1 *)(param_4 + 7) = 4;
  *(ushort *)(param_4 + 10) = *(ushort *)(param_4 + 10) & 0xfffe;
  iVar10 = 0;
  if (piVar13[8] != 0) {
    iVar10 = piVar13[10];
  }
  *param_4 = iVar10;
  iVar10 = 0;
  if (piVar13[4] != 0) {
    iVar10 = piVar13[6];
  }
  param_4[1] = iVar10;
  if (*piVar13 == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = *(byte *)(piVar13 + 2);
  }
  *(byte *)((longlong)param_4 + 0x1d) = bVar4;
  uVar9 = (uint)bVar4;
  if (uVar9 != 1) {
    if ((uVar9 == 6) || (iVar10 = uVar9 - 0x11, iVar10 == 0)) {
      uVar5 = 0;
      if (piVar13[0x14] != 0) {
        uVar5 = (undefined2)piVar13[0x16];
      }
      *(undefined2 *)(param_4 + 6) = uVar5;
      iVar10 = piVar13[0x10];
joined_r0x0001400030f6:
      if (iVar10 != 0) {
        uVar15 = (ulonglong)*(ushort *)(piVar13 + 0x12);
      }
LAB_1400030fd:
      *(short *)((longlong)param_4 + 0x1a) = (short)uVar15;
      return;
    }
LAB_140003ca1:
    if (iVar10 != 0x29) {
      return;
    }
  }
LAB_140003b19:
  if (piVar13[0x10] == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (undefined1)piVar13[0x12];
  }
  *(undefined1 *)((longlong)param_4 + 0x19) = uVar3;
  if (piVar13[0x14] == 0) {
    uVar3 = 0;
  }
  else {
LAB_140003b36:
    uVar3 = (undefined1)piVar13[0x16];
  }
LAB_140003b3f:
  *(undefined1 *)(param_4 + 6) = uVar3;
  return;
}



===== SendDfwNotification @ 140004010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SendDfwNotification(longlong *param_1,longlong param_2)

{
  ushort uVar1;
  short sVar2;
  uint *puVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined4 *puVar6;
  short *psVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  short *psVar13;
  undefined2 uVar14;
  longlong lVar15;
  uint uVar16;
  bool bVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0xfd8,0x44555144);
  if (puVar6 == (undefined4 *)0x0) {
    uVar16 = 0xc0000017;
LAB_140004363:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,uVar16);
    }
    if (puVar6 == (undefined4 *)0x0) goto LAB_1400043a4;
  }
  else {
    memset(puVar6 + 1,0,0xfd4);
    uVar16 = 0;
    *puVar6 = 0;
    uVar18 = *(undefined4 *)(param_2 + 0xc);
    uVar19 = *(undefined4 *)(param_2 + 0x10);
    uVar20 = *(undefined4 *)(param_2 + 0x14);
    uVar21 = *(undefined4 *)(param_2 + 0x18);
    puVar6[0x12] = 0;
    puVar6[2] = uVar18;
    puVar6[3] = uVar19;
    puVar6[4] = uVar20;
    puVar6[5] = uVar21;
    uVar1 = *(ushort *)(param_1 + 5);
    puVar6[0x12] = uVar1 & 1;
    uVar10 = 0;
    if (*(char *)((longlong)param_1 + 0x1c) == '\x06') {
      uVar10 = 2;
    }
    uVar10 = uVar10 | uVar1 & 1;
    puVar6[0x12] = uVar10;
    uVar10 = (uint)*(byte *)(param_2 + 5) << 9 | uVar10;
    puVar6[0x12] = uVar10;
    if (*(char *)((longlong)param_1 + 0x1c) == '\x06') {
      puVar4 = (undefined4 *)*param_1;
      if (puVar4 == (undefined4 *)0x0) {
        uVar18 = 0;
        uVar19 = 0;
        uVar20 = 0;
        uVar21 = 0;
      }
      else {
        uVar18 = *puVar4;
        uVar19 = puVar4[1];
        uVar20 = puVar4[2];
        uVar21 = puVar4[3];
      }
      puVar6[8] = uVar18;
      puVar6[9] = uVar19;
      puVar6[10] = uVar20;
      puVar6[0xb] = uVar21;
      puVar4 = (undefined4 *)param_1[1];
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined8 *)(puVar6 + 0xc) = 0;
        *(undefined8 *)(puVar6 + 0xe) = 0;
        uVar10 = puVar6[0x12];
      }
      else {
        uVar18 = puVar4[1];
        uVar19 = puVar4[2];
        uVar20 = puVar4[3];
        puVar6[0xc] = *puVar4;
        puVar6[0xd] = uVar18;
        puVar6[0xe] = uVar19;
        puVar6[0xf] = uVar20;
      }
    }
    else {
      puVar6[8] = (int)*param_1;
      puVar6[0xc] = *(undefined4 *)((longlong)param_1 + 4);
    }
    *(short *)(puVar6 + 0x10) = (short)param_1[3];
    iVar11 = 0;
    *(undefined2 *)((longlong)puVar6 + 0x42) = *(undefined2 *)((longlong)param_1 + 0x1a);
    *(undefined1 *)(puVar6 + 0x11) = *(undefined1 *)((longlong)param_1 + 0x1d);
    puVar6[0x12] = ((uint)*(ushort *)(param_1 + 5) << 4 ^ uVar10) & 0x100 ^ uVar10 | 4;
    puVar3 = (uint *)param_1[4];
    if ((*puVar3 & 8) == 0) {
LAB_1400042bd:
      if ((*puVar3 & 0x10) != 0) {
        iVar11 = iVar11 + 1;
        *(undefined8 *)(puVar6 + 0x14) = *(undefined8 *)(puVar3 + 0xe);
      }
      if ((*puVar3 & 0x20) != 0) {
        iVar11 = iVar11 + 1;
        *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(puVar3 + 0x10);
      }
      if ((iVar11 != 3) &&
         (uVar16 = 0xc000000d, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar14 = 0x17;
          uVar16 = 0xc000000d;
          goto LAB_14000430f;
        }
        goto LAB_14000431f;
      }
    }
    else {
      psVar13 = *(short **)(*(longlong *)(puVar3 + 0xc) + 8);
      if (psVar13 != (short *)0x0) {
        lVar15 = 0x400;
        lVar12 = 0x400;
        psVar7 = psVar13;
        do {
          if (*psVar7 == 0) break;
          psVar7 = psVar7 + 1;
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
        if (lVar12 != 0) {
          puVar6[0x19] = 0x400 - (int)lVar12;
          psVar7 = (short *)(puVar6 + 0x1a);
          lVar12 = (longlong)psVar13 - (longlong)psVar7;
          do {
            if ((lVar15 == -0x7ffffbfe) ||
               (sVar2 = *(short *)((longlong)psVar7 + lVar12), sVar2 == 0)) break;
            *psVar7 = sVar2;
            psVar7 = psVar7 + 1;
            lVar15 = lVar15 + -1;
          } while (lVar15 != 0);
          bVar17 = lVar15 != 0;
          psVar13 = psVar7 + -1;
          if (bVar17) {
            psVar13 = psVar7;
          }
          uVar16 = 0x80000005;
          if (bVar17) {
            uVar16 = 0;
          }
          *psVar13 = 0;
          if (bVar17) {
            iVar11 = 1;
            goto LAB_1400042bd;
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
              uVar14 = 0x16;
              goto LAB_14000430f;
            }
            goto LAB_14000431f;
          }
          goto LAB_1400041b4;
        }
      }
      uVar16 = 0xc000000d;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar14 = 0x15;
LAB_14000430f:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                   &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,uVar16);
        }
LAB_14000431f:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,uVar16);
        }
      }
    }
LAB_1400041b4:
    if ((int)uVar16 < 0) {
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar14 = 0x15;
          goto LAB_14000443b;
        }
        goto LAB_140004363;
      }
    }
    else {
      local_28 = 0;
      uStack_20 = 0;
      local_18 = 0;
      puVar8 = (undefined8 *)ExAllocateFromNPagedLookasideList(&WorkItemLookasideList);
      if (puVar8 != (undefined8 *)0x0) {
        puVar8[3] = puVar6;
        puVar8[2] = CompleteDfwNotification;
        KeAcquireInStackQueuedSpinLock(&WorkerThreadLock,&local_28);
        if ((undefined8 *)*DAT_140015988 == &WorkItemList) {
          *puVar8 = &WorkItemList;
          puVar8[1] = DAT_140015988;
          *DAT_140015988 = puVar8;
          DAT_140015988 = puVar8;
          KeReleaseInStackQueuedSpinLock(&local_28);
          KeSetEvent(&WorkerThreadWakeupEvent,0,0);
          return 0;
        }
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        uVar9 = (*pcVar5)();
        return uVar9;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids,0xc0000017);
      }
      uVar16 = 0xc0000017;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          uVar14 = 0x16;
          uVar16 = 0xc0000017;
LAB_14000443b:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                   &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,uVar16);
        }
        goto LAB_140004363;
      }
    }
  }
  ExFreePoolWithTag(puVar6,0);
LAB_1400043a4:
  return (ulonglong)uVar16;
}



===== MpspSetDynEdge @ 1400044b0 =====

void MpspSetDynEdge(int *param_1,longlong param_2)

{
  ushort uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (ushort)((uint)param_1[2] >> 1) & 1;
  }
  *(ushort *)(param_2 + 0x28) = *(ushort *)(param_2 + 0x28) & 0xffef | uVar1 << 4;
  return;
}



===== MpspSetAppID @ 1400044f0 =====

void MpspSetAppID(int *param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 2) + 8);
  }
  *(undefined8 *)(param_2 + 0x30) = uVar1;
  if (*param_1 == 0) {
    *(undefined4 *)(param_2 + 0x38) = 0;
    return;
  }
  *(undefined4 *)(param_2 + 0x38) = **(undefined4 **)(param_1 + 2);
  return;
}



===== MatchIpFilter @ 140004530 =====

byte MatchIpFilter(uint *param_1,longlong param_2)

{
  ushort uVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_2 + 0x22);
  if ((char)param_1[7] != (char)((uVar1 & 0x4000 | 0x8000) >> 0xd)) {
    return 1;
  }
  if ((uVar1 & 0x3f) != 0) {
    if (((uVar1 & 1) != 0) && (*(char *)((longlong)param_1 + 0x1d) != *(char *)(param_2 + 0x30))) {
      return 2;
    }
    if (((uVar1 & 8) != 0) &&
       ((*(ushort *)((longlong)param_1 + 0x1a) < *(ushort *)(param_2 + 0x4c) ||
        (*(ushort *)(param_2 + 0x4e) < *(ushort *)((longlong)param_1 + 0x1a))))) {
      return 3;
    }
    if (((uVar1 & 0x10) != 0) &&
       (((ushort)param_1[6] < *(ushort *)(param_2 + 0x48) ||
        (*(ushort *)(param_2 + 0x4a) < (ushort)param_1[6])))) {
      return 4;
    }
    if ((uVar1 & 0x4000) == 0) {
      if (((uVar1 & 2) != 0) &&
         ((param_1[1] < *(uint *)(param_2 + 0x40) || (*(uint *)(param_2 + 0x44) < param_1[1])))) {
        return 5;
      }
      if ((uVar1 & 4) != 0) {
        if (*param_1 < *(uint *)(param_2 + 0x38)) {
          return 6;
        }
        if (*(uint *)(param_2 + 0x3c) < *param_1) {
          return 6;
        }
      }
    }
    else {
      if (((uVar1 & 2) != 0) && (pvVar2 = *(void **)(param_1 + 2), pvVar2 != (void *)0x0)) {
        pvVar3 = *(void **)(param_2 + 0x40);
        iVar4 = memcmp(pvVar2,pvVar3,0x10);
        if (iVar4 < 0) {
          return 5;
        }
        iVar4 = memcmp(pvVar2,(void *)((longlong)pvVar3 + 0x10),0x10);
        if (0 < iVar4) {
          return 5;
        }
      }
      if (((uVar1 & 4) != 0) && (pvVar2 = *(void **)param_1, pvVar2 != (void *)0x0)) {
        pvVar3 = *(void **)(param_2 + 0x38);
        iVar4 = memcmp(pvVar2,pvVar3,0x10);
        if ((iVar4 < 0) ||
           (iVar4 = memcmp(pvVar2,(void *)((longlong)pvVar3 + 0x10),0x10), 0 < iVar4)) {
          return 6;
        }
      }
    }
    if (*(void **)(param_2 + 0x50) != (void *)0x0) {
      if (*(uint *)(param_2 + 0x58) == param_1[0xe]) {
        iVar4 = memcmp(*(void **)(param_1 + 0xc),*(void **)(param_2 + 0x50),(ulonglong)param_1[0xe])
        ;
        return -(iVar4 != 0) & 7;
      }
      return 7;
    }
  }
  return 0;
}



===== DeleteFilter @ 1400046f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeleteFilter(longlong param_1)

{
  if ((*(byte *)(param_1 + 4) < 2) &&
     ((code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(param_1 + 4) * 8) != (code *)0x0
     )) {
    (*(code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(param_1 + 4) * 8))(param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== CompleteDfwNotification @ 140004740 =====

int CompleteDfwNotification(void *param_1)

{
  int iVar1;
  
  iVar1 = MpsUpcall(param_1);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,iVar1);
    }
    AuditOneArgError(iVar1,0x13a8);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,iVar1);
    }
  }
  ExFreePoolWithTag(param_1,0);
  return iVar1;
}



===== MpsUpcall @ 140004800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MpsUpcall(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  undefined1 auStackY_4b8 [8];
  undefined1 auStackY_4b0 [24];
  int local_488 [2];
  undefined8 local_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined2 local_446;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_4b8;
  local_470 = 0;
  iVar5 = 0;
  local_480 = 0;
  uStack_478 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
  }
  puVar12 = auStackY_4b8;
  puVar11 = auStackY_4b8;
  KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_480);
  lVar1 = _DAT_fffff78000000320;
  plVar9 = DAT_1400157b0;
  plVar3 = DAT_140015780;
  if ((longlong **)DAT_140015780 == &DAT_140015780) {
    if (((longlong **)DAT_1400157b0 == &DAT_1400157b0) ||
       ((DAT_140015684 < 0x101 &&
        (uVar7 = KeQueryTimeIncrement(),
        (uint)(((lVar1 - plVar9[0x1fe]) * (ulonglong)uVar7) / 10000000) < 0x79)))) {
LAB_140004af6:
      plVar9 = (longlong *)ExAllocateFromNPagedLookasideList(&DAT_140015840);
      if (plVar9 == (longlong *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                   &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc0000017);
        }
        KeReleaseInStackQueuedSpinLock(&local_480);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                   &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc0000017);
        }
        iVar5 = -0x3fffffe9;
        goto LAB_140004a21;
      }
      DAT_140015790 = DAT_140015790 + 1;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      }
      lVar2 = *plVar9;
      if ((*(longlong **)(lVar2 + 8) != plVar9) ||
         (plVar3 = (longlong *)plVar9[1], (longlong *)*plVar3 != plVar9)) goto LAB_140004c9e;
      DAT_140015684 = DAT_140015684 + -1;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      if (plVar9 == (longlong *)0x0) goto LAB_140004af6;
    }
    plVar9[0x1fe] = lVar1;
    memmove(plVar9 + 2,param_1,0xfd8);
    plVar9[0x1fd] = (longlong)UpcallIrpCompleteReadyNotification;
    if ((longlong **)*DAT_1400157b8 != &DAT_1400157b0) goto LAB_140004c9e;
    DAT_140015684 = DAT_140015684 + 1;
    *plVar9 = (longlong)&DAT_1400157b0;
    plVar9[1] = (longlong)DAT_1400157b8;
    *DAT_1400157b8 = (longlong)plVar9;
    DAT_1400157b8 = plVar9;
    KeReleaseInStackQueuedSpinLock(&local_480);
LAB_140004a08:
    puVar11 = auStackY_4b8;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140004a21;
    puVar10 = WPP_GLOBAL_Control;
    puVar11 = auStackY_4b8;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) goto LAB_140004a21;
  }
  else {
    lVar1 = *DAT_140015780;
    if ((*(longlong **)(lVar1 + 8) == DAT_140015780) &&
       (plVar9 = (longlong *)DAT_140015780[1], (longlong *)*plVar9 == DAT_140015780)) {
      *plVar9 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar9;
      KeReleaseInStackQueuedSpinLock(&local_480);
      uVar8 = UpcallIrpCompleteReadyNotification((ulonglong)*(uint *)(plVar3 + 3),(longlong)param_1)
      ;
      iVar5 = (int)uVar8;
      if (iVar5 == 0) {
        uVar13 = 0xfd8;
        memmove((void *)plVar3[4],param_1,0xfd8);
        *(undefined4 *)(plVar3[4] + 4) = 0;
        lVar1 = plVar3[2];
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,uVar13,lVar1,
                    *(undefined8 *)(lVar1 + 0x70));
        }
        if (*(char *)(lVar1 + 0x44) == '\0') {
          LOCK();
          *(undefined8 *)(lVar1 + 0x68) = 0;
          UNLOCK();
        }
        *(undefined4 *)(lVar1 + 0x30) = 0;
        *(undefined8 *)(lVar1 + 0x38) = 0xfd8;
        IofCompleteRequest(lVar1,0);
        ExFreeToNPagedLookasideList(&DAT_1400157c0,plVar3);
        goto LAB_140004a08;
      }
      local_488[0] = iVar5;
      memset(&local_458,0,0x418);
      local_468 = 0;
      uStack_460 = 0;
      RtlInitUnicodeString(&local_468,L"Security");
      local_454 = 0x13ad;
      local_458 = 1;
      local_446 = 0x10;
      iVar6 = SeSetAuditParameter(&local_458,3,1,local_488);
      if (-1 < iVar6) {
        local_450 = 1;
        SeReportSecurityEventWithSubCategory(0,&local_468,0,&local_458);
      }
      KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_480);
      if ((longlong **)DAT_140015780[1] == &DAT_140015780) {
        *plVar3 = (longlong)DAT_140015780;
        plVar3[1] = (longlong)&DAT_140015780;
        DAT_140015780[1] = (longlong)plVar3;
        DAT_140015780 = plVar3;
        KeReleaseInStackQueuedSpinLock(&local_480);
        iVar5 = 0;
        puVar11 = auStackY_4b8;
        goto LAB_140004a21;
      }
    }
LAB_140004c9e:
    puVar10 = (undefined *)0x3;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar12 = auStackY_4b0;
  }
  uVar13 = *(undefined8 *)(puVar10 + 0x18);
  *(undefined8 *)(puVar12 + -8) = 0x140004cba;
  WPP_SF_(uVar13,0x1b,&WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
  puVar11 = puVar12;
LAB_140004a21:
  *(undefined8 *)(puVar11 + -8) = 0x140004a39;
  return iVar5;
}



===== UpcallIrpCompleteReadyNotification @ 140004cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UpcallIrpCompleteReadyNotification(ulonglong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  ulonglong local_60 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  local_60[0] = param_1 & 0xffffffff;
  local_70 = 0;
  local_68 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_50 = 0x30;
  local_38 = 0x200;
  local_48 = 0;
  local_40 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_60[1] = 0;
  uVar1 = ZwOpenProcess(&local_78,0x40,&local_50,local_60);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140004f7f;
    uVar3 = 0xe;
  }
  else {
    local_60[0] = *(ulonglong *)(param_2 + 0x18);
    local_50 = CONCAT44(local_50._4_4_,0x30);
    local_48 = 0;
    local_38 = CONCAT44(local_38._4_4_,0x200);
    local_30 = 0;
    uStack_28 = 0;
    local_40 = 0;
    local_60[1] = 0;
    uVar1 = ZwOpenProcess(&local_80,0x1440,&local_50,local_60);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140004f7f;
      uVar3 = 0xf;
    }
    else {
      uVar1 = ZwOpenProcessTokenEx(local_80,0xb,0x200,&local_88);
      uVar4 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140004f7f;
        uVar3 = 0x10;
      }
      else {
        *(longlong *)(param_2 + 0x50) = local_88;
        uVar2 = CalculateAccessFlags(param_2);
        uVar4 = uVar2 & 0xffffffff;
        if ((int)uVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140004f7f;
          uVar3 = 0x11;
        }
        else {
          local_98 = 0;
          local_a0 = 0;
          local_a8 = 0xb;
          uVar1 = ZwDuplicateObject(0xffffffffffffffff,local_88,local_78,&local_70);
          uVar4 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            ZwClose(local_88);
            local_98 = 0;
            local_a0 = 0;
            local_a8 = 0x101400;
            local_88 = 0;
            uVar1 = ZwDuplicateObject(0xffffffffffffffff,local_80,local_78,&local_68);
            ZwClose(local_80);
            local_80 = 0;
            ZwClose(local_78);
            *(longlong *)(param_2 + 0x50) = local_70;
            *(longlong *)(param_2 + 0x58) = local_68;
            return (ulonglong)uVar1;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140004f7f;
          uVar3 = 0x12;
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,(int)uVar4);
LAB_140004f7f:
  if (local_80 != 0) {
    ZwClose();
  }
  if (local_88 != 0) {
    ZwClose();
  }
  if (local_78 != 0) {
    ZwClose();
  }
  if (local_68 != 0) {
    ZwClose();
  }
  if (local_70 != 0) {
    ZwClose();
  }
  return uVar4;
}



===== CalculateAccessFlags @ 140005000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CalculateAccessFlags(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  longlong *local_b0;
  undefined8 local_a8;
  undefined1 local_a0;
  undefined4 *local_98;
  undefined4 *local_90;
  longlong local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined4 local_6c;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_44 = 2;
  local_6c = 0;
  local_58 = &local_48;
  local_64 = 0;
  local_b0 = &local_88;
  local_5c = 0;
  local_b8 = 2;
  local_80 = 0x30;
  local_38 = 0;
  uStack_30 = 0;
  local_68 = 0x200;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0xc;
  local_7c = 0;
  uStack_74 = 0;
  local_88 = 0;
  uVar2 = ZwDuplicateToken(*(undefined8 *)(param_1 + 0x50),0xe,&local_80,0);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400053bd;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar4 = 10;
      goto LAB_14000537f;
    }
  }
  else {
    uVar2 = ZwSetInformationThread(0xfffffffffffffffe,5,&local_88,8);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400053bd;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar4 = 0xb;
        goto LAB_14000537f;
      }
    }
    else {
      SeCaptureSubjectContext(&local_38);
      SeLockSubjectContext(&local_38);
      local_4c = 0;
      local_50 = 0;
      local_a8 = IoGetFileObjectGenericMapping();
      local_90 = &local_50;
      local_98 = &local_4c;
      local_a0 = 1;
      local_b0 = (longlong *)0x0;
      local_b8 = 0;
      bVar1 = SeAccessCheck(&DAT_140012640,&local_38,1);
      local_50 = 0;
      local_4c = 0;
      *(uint *)(param_1 + 0x48) =
           ((uint)bVar1 << 5 ^ *(uint *)(param_1 + 0x48)) & 0x20 ^ *(uint *)(param_1 + 0x48);
      local_a8 = IoGetFileObjectGenericMapping();
      local_90 = &local_4c;
      local_98 = &local_50;
      local_a0 = 1;
      local_b0 = (longlong *)0x0;
      local_b8 = 0;
      bVar1 = SeAccessCheck(&DAT_1400126e0,&local_38,1);
      local_50 = 0;
      local_4c = 0;
      *(uint *)(param_1 + 0x48) =
           ((uint)bVar1 * 8 ^ *(uint *)(param_1 + 0x48)) & 8 ^ *(uint *)(param_1 + 0x48);
      local_a8 = IoGetFileObjectGenericMapping();
      local_90 = &local_4c;
      local_98 = &local_50;
      local_a0 = 1;
      local_b0 = (longlong *)0x0;
      local_b8 = 0;
      bVar1 = SeAccessCheck(&DAT_1400125f0,&local_38,1);
      local_50 = 0;
      local_4c = 0;
      *(uint *)(param_1 + 0x48) =
           ((uint)bVar1 << 4 ^ *(uint *)(param_1 + 0x48)) & 0x10 ^ *(uint *)(param_1 + 0x48);
      local_a8 = IoGetFileObjectGenericMapping();
      local_90 = &local_4c;
      local_98 = &local_50;
      local_a0 = 1;
      local_b0 = (longlong *)0x0;
      local_b8 = 0;
      bVar1 = SeAccessCheck(&DAT_140012690,&local_38,1);
      *(uint *)(param_1 + 0x48) =
           ((uint)bVar1 << 6 ^ *(uint *)(param_1 + 0x48)) & 0x40 ^ *(uint *)(param_1 + 0x48);
      SeUnlockSubjectContext(&local_38);
      SeReleaseSubjectContext(&local_38);
      ZwClose(local_88);
      local_88 = 0;
      uVar3 = ZwSetInformationThread(0xfffffffffffffffe,5,&local_88,8);
      uVar5 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        return uVar3;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400053bd;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar4 = 0xc;
LAB_14000537f:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                 &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,(int)uVar5);
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_ef90aa87ce5a3e38f31cc52f0401c761_Traceguids,(int)uVar5);
  }
LAB_1400053bd:
  if (local_88 != 0) {
    ZwClose();
  }
  return uVar5;
}



===== MpsDispatchDevCtl @ 1400053e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int MpsDispatchDevCtl(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  pbVar1 = *(byte **)(param_2 + 0xb8);
  uVar3 = *(uint *)(pbVar1 + 0x18) >> 0x10;
  if (uVar3 - 32000 < 5) {
    if (*(uint *)(pbVar1 + 0x18) == 0x7d008004) {
      iVar2 = MpsIoctlUpcall(32000,param_2,pbVar1);
LAB_140005442:
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return iVar2;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar2);
      return iVar2;
    }
    lVar4 = 0;
    while ((int)lVar4 == 0) {
      if (uVar3 == *(uint *)(&g_MpsModulesList + lVar4 * 0x128)) {
        if ((code *)(&DAT_140015ac0)[lVar4 * 0x25 + (ulonglong)*pbVar1] != (code *)0x0) {
          iVar2 = (*(code *)(&DAT_140015ac0)[lVar4 * 0x25 + (ulonglong)*pbVar1])(param_1,param_2);
          goto LAB_140005442;
        }
        break;
      }
      lVar4 = 1;
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,0xc0000010);
  }
  return -0x3ffffff0;
}



===== MpsIoctlUpcall @ 140005560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsIoctlUpcall(undefined8 param_1,longlong param_2,undefined *param_3)

{
  byte *pbVar1;
  void *_Dst;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  longlong *plVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  int unaff_R15D;
  undefined1 auStackY_4b8 [8];
  undefined1 auStackY_4b0 [24];
  int local_488 [2];
  undefined8 local_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined2 local_446;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_4b8;
  local_480 = 0;
  uStack_478 = 0;
  local_470 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,param_2,
              *(undefined8 *)(param_2 + 0x70));
  }
  puVar10 = auStackY_4b8;
  uVar11 = 0xfd8;
  _Dst = *(void **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0xfd8) {
    unaff_R15D = -0x3ffffff3;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        param_3 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc000000d);
      }
      goto LAB_14000595f;
    }
  }
  else {
    KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_480);
    while (plVar8 = DAT_1400157b0, (longlong **)DAT_1400157b0 != &DAT_1400157b0) {
      lVar2 = *DAT_1400157b0;
      if ((*(longlong **)(lVar2 + 8) != DAT_1400157b0) ||
         (plVar3 = (longlong *)DAT_1400157b0[1], (longlong *)*plVar3 != DAT_1400157b0))
      goto LAB_140005a4a;
      DAT_140015684 = DAT_140015684 + -1;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      KeReleaseInStackQueuedSpinLock(&local_480);
      pcVar4 = (code *)plVar8[0x1fd];
      if (pcVar4 == (code *)0x0) {
        unaff_R15D = 0;
LAB_1400057dc:
        uVar12 = 0xfd8;
        memmove(_Dst,plVar8 + 2,0xfd8);
        *(int *)((longlong)_Dst + 4) = DAT_140015790;
        DAT_140015790 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,uVar12,param_2,
                    *(undefined8 *)(param_2 + 0x70));
        }
        if (*(char *)(param_2 + 0x44) == '\0') {
          LOCK();
          *(undefined8 *)(param_2 + 0x68) = 0;
          UNLOCK();
        }
        *(int *)(param_2 + 0x30) = unaff_R15D;
        if (unaff_R15D != 0) {
          uVar11 = 0;
        }
        *(undefined8 *)(param_2 + 0x38) = uVar11;
        IofCompleteRequest(param_2,0);
        KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_480);
        ExFreeToNPagedLookasideList(&DAT_140015840,plVar8);
        goto LAB_140005866;
      }
      uVar6 = PsGetCurrentProcessId();
      unaff_R15D = (*pcVar4)(uVar6);
      if (unaff_R15D == 0) goto LAB_1400057dc;
      local_488[0] = unaff_R15D;
      memset(&local_458,0,0x418);
      local_468 = 0;
      uStack_460 = 0;
      RtlInitUnicodeString(&local_468,L"Security");
      local_454 = 0x13ad;
      local_446 = 0x10;
      local_458 = 1;
      param_3 = (undefined *)0x1;
      iVar7 = SeSetAuditParameter(&local_458,3,1,local_488);
      if (-1 < iVar7) {
        local_450 = 1;
        param_3 = (undefined *)0x0;
        SeReportSecurityEventWithSubCategory(0,&local_468,0,&local_458);
      }
      KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_480);
      ExFreeToNPagedLookasideList(&DAT_140015840);
      DAT_140015790 = DAT_140015790 + -1;
    }
    plVar8 = (longlong *)ExAllocateFromNPagedLookasideList(&DAT_1400157c0);
    if (plVar8 != (longlong *)0x0) {
      plVar8[2] = param_2;
      plVar8[4] = (longlong)_Dst;
      uVar6 = PsGetCurrentProcessId();
      *(undefined4 *)(plVar8 + 3) = uVar6;
      if ((longlong **)DAT_140015780[1] == &DAT_140015780) {
        *plVar8 = (longlong)DAT_140015780;
        unaff_R15D = 0x103;
        plVar8[1] = (longlong)&DAT_140015780;
        DAT_140015780[1] = (longlong)plVar8;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        DAT_140015780 = plVar8;
        *pbVar1 = *pbVar1 | 1;
        LOCK();
        *(code **)(param_2 + 0x68) = CancelUpcallIrp;
        UNLOCK();
LAB_140005866:
        KeReleaseInStackQueuedSpinLock(&local_480);
        puVar10 = auStackY_4b8;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140005891;
        puVar9 = WPP_GLOBAL_Control;
        puVar10 = auStackY_4b8;
        puVar5 = auStackY_4b8;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) goto LAB_140005891;
      }
      else {
LAB_140005a4a:
        puVar9 = (undefined *)0x3;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar5 = auStackY_4b0;
      }
      puVar10 = puVar5;
      uVar11 = *(undefined8 *)(puVar9 + 0x18);
      *(undefined8 *)(puVar10 + -8) = 0x140005a66;
      WPP_SF_(uVar11,0x16,&WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      goto LAB_140005891;
    }
    unaff_R15D = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      param_3 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc0000017);
    }
    KeReleaseInStackQueuedSpinLock(&local_480);
LAB_14000595f:
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        param_3 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,unaff_R15D);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_2,
                  *(undefined8 *)(param_2 + 0x70));
      }
    }
  }
  if (*(char *)(param_2 + 0x44) == '\0') {
    LOCK();
    *(undefined8 *)(param_2 + 0x68) = 0;
    UNLOCK();
  }
  *(int *)(param_2 + 0x30) = unaff_R15D;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
LAB_140005891:
  *(undefined8 *)(puVar10 + -8) = 0x1400058c1;
  return unaff_R15D;
}



===== CancelUpcallIrp @ 140005a80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CancelUpcallIrp(undefined8 param_1,longlong param_2,undefined *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  KeAcquireInStackQueuedSpinLock(&DAT_140015798,&local_28);
  puVar6 = auStack_48;
  puVar1 = DAT_140015780;
  do {
    puVar5 = puVar1;
    if ((undefined8 **)puVar5 == &DAT_140015780) goto LAB_140005bad;
    puVar1 = (undefined8 *)*puVar5;
  } while (puVar5[2] != param_2);
  if (((undefined8 *)puVar1[1] == puVar5) &&
     (puVar2 = (undefined8 *)puVar5[1], (undefined8 *)*puVar2 == puVar5)) {
    *puVar2 = puVar1;
    puVar1[1] = puVar2;
    KeReleaseInStackQueuedSpinLock(&local_28);
    ExFreeToNPagedLookasideList(&DAT_1400157c0,puVar5);
    CompleteUpcallIrp(param_2,-0x3ffffee0,param_3);
    puVar6 = auStack_48;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar6 = auStack_48, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      puVar6 = auStack_48;
    }
  }
  else {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar6 = auStack_40;
LAB_140005bad:
    *(undefined8 *)(puVar6 + -8) = 0x140005bb9;
    KeReleaseInStackQueuedSpinLock(puVar6 + 0x20);
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar6 + -8) = 0x140005bec;
        WPP_SF_D(uVar3,0x10,&WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc0000225);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar6 + -8) = 0x140005c1a;
        WPP_SF_D(uVar3,0x12,&WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,0xc0000225);
      }
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x140005c2c;
  return;
}



===== CompleteUpcallIrp @ 140005c40 =====

void CompleteUpcallIrp(longlong param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,param_1,
              *(undefined8 *)(param_1 + 0x70));
  }
  if (*(char *)(param_1 + 0x44) == '\0') {
    LOCK();
    *(undefined8 *)(param_1 + 0x68) = 0;
    UNLOCK();
  }
  *(int *)(param_1 + 0x30) = param_2;
  uVar1 = 0xfd8;
  if (param_2 != 0) {
    uVar1 = 0;
  }
  *(undefined8 *)(param_1 + 0x38) = uVar1;
  IofCompleteRequest(param_1,0);
  return;
}



===== MpsWorkerThread @ 140005cd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MpsWorkerThread(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  undefined1 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined *local_20;
  undefined *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  local_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_50 = 0;
  local_20 = &WorkerThreadWakeupEvent;
  local_58 = 0;
  local_18 = &WorkerThreadKillEvent;
  iVar4 = KeWaitForMultipleObjects(2,&local_20,1,0);
  while (iVar4 == 0) {
    while( true ) {
      KeAcquireInStackQueuedSpinLock(&WorkerThreadLock,&local_38);
      puVar5 = WorkItemList;
      if ((undefined8 **)WorkItemList == &WorkItemList) break;
      *DAT_140015988 = 0;
      DAT_140015988 = &WorkItemList;
      WorkItemList = &WorkItemList;
      KeReleaseInStackQueuedSpinLock(&local_38);
      while (puVar5 != (undefined8 *)0x0) {
        (*(code *)puVar5[2])(puVar5[3]);
        puVar1 = (undefined8 *)*puVar5;
        ExFreeToNPagedLookasideList(&WorkItemLookasideList,puVar5);
        puVar5 = puVar1;
      }
    }
    KeReleaseInStackQueuedSpinLock();
    local_40 = 0;
    local_48 = 0;
    local_50 = 0;
    local_58 = 0;
    iVar4 = KeWaitForMultipleObjects(2,&local_20,1);
  }
  KeAcquireInStackQueuedSpinLock(&WorkerThreadLock,&local_38);
  puVar5 = WorkItemList;
  if ((undefined8 **)WorkItemList != &WorkItemList) {
    do {
      puVar1 = (undefined8 *)*puVar5;
      if (((undefined8 *)puVar1[1] != puVar5) ||
         (puVar2 = (undefined8 *)puVar5[1], (undefined8 *)*puVar2 != puVar5)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      ExFreeToNPagedLookasideList(&WorkItemLookasideList);
      puVar5 = puVar1;
    } while ((undefined8 **)puVar1 != &WorkItemList);
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  PsTerminateSystemThread(0);
  return;
}



===== MpsIoLayerDispatchIrp @ 140005ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 MpsIoLayerDispatchIrp(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000010;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  if (((g_fMpsIoLayerInited == '\0') || (0x1b < **(byte **)(param_2 + 0xb8))) ||
     (pcVar1 = *(code **)(*(longlong *)(param_1 + 0x40) + (ulonglong)**(byte **)(param_2 + 0xb8) * 8
                         ), pcVar1 == (code *)0x0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar2 = (*pcVar1)(param_1,param_2);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,uVar2);
  }
  return uVar2;
}



===== FtpAnalyzerFlowAction @ 140005fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FtpAnalyzerFlowAction(undefined8 param_1,longlong param_2,ulonglong *param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_e8 [32];
  int local_98 [7];
  char local_7c;
  undefined4 local_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar8 = 2;
  pbVar5 = (byte *)*param_3;
  pbVar1 = pbVar5 + (ushort)param_3[1];
  if ((((ulonglong)(ushort)param_3[1] < 2) || (pbVar1[-2] != 0xd)) || (pbVar1[-1] != 10)) {
    *(undefined1 *)((longlong)param_3 + 0xc) = 0x80;
  }
  else {
    do {
      pbVar4 = pbVar5;
LAB_140006080:
      for (; pbVar4 < pbVar1 + -2; pbVar4 = pbVar4 + 1) {
        if (pbVar4[2] == 0x20) goto LAB_14000609c;
        if (pbVar4[2] != 9) break;
      }
      if ((*pbVar4 != 0xd) || (pbVar4[1] != 10)) {
LAB_14000609c:
        pbVar4 = pbVar4 + 1;
        goto LAB_140006080;
      }
      if (((*(byte *)((longlong)param_3 + 0xe) ^ *(byte *)(param_2 + 8)) & 1) == 0) {
        if (5 < (longlong)pbVar1 - (longlong)pbVar5) {
          if ((((*pbVar5 | 0x20) == 0x70) && ((pbVar5[1] | 0x20) == 0x6f)) &&
             (((pbVar5[2] | 0x20) == 0x72 && (((pbVar5[3] | 0x20) == 0x74 && (pbVar5[4] == 0x20)))))
             ) {
            uVar8 = FtpAnalyzerParseIp4Endpoint(param_2,(longlong)param_3,(char *)(pbVar5 + 5));
            uVar8 = uVar8 & 0xffffffff;
          }
          else if (((*pbVar5 | 0x20) == 0x65) &&
                  (((((pbVar5[1] | 0x20) == 0x70 && ((pbVar5[2] | 0x20) == 0x72)) &&
                    ((pbVar5[3] | 0x20) == 0x74)) && (pbVar5[4] == 0x20)))) {
            uVar8 = FtpAnalyzerParseExtendedEndpoint(param_2,(longlong)param_3,pbVar5 + 5,0);
            uVar8 = uVar8 & 0xffffffff;
          }
        }
      }
      else if ((4 < (longlong)pbVar1 - (longlong)pbVar5) &&
              ((*(int *)pbVar5 == 0x20373232 || (*(int *)pbVar5 == 0x20393232)))) {
        pbVar6 = pbVar5 + 4;
        do {
          if (pbVar4 <= pbVar6) goto LAB_140006143;
          bVar2 = *pbVar6;
          pbVar6 = pbVar6 + 1;
        } while (bVar2 != 0x28);
        if (pbVar5[2] == 0x39) {
          uVar8 = FtpAnalyzerParseExtendedEndpoint(param_2,(longlong)param_3,pbVar6,1);
        }
        else {
          uVar8 = FtpAnalyzerParseIp4Endpoint(param_2,(longlong)param_3,(char *)pbVar6);
        }
        uVar8 = uVar8 & 0xffffffff;
LAB_140006143:
        if (pbVar6 == pbVar4) {
          memset(local_98,0,0x50);
          uVar7 = 0;
          uVar3 = 0;
          MpsGetFwpAuthData((short *)param_3[3],0,0,local_98);
          local_60 = *(undefined4 *)(param_2 + 0x38);
          local_68 = *(undefined8 *)(param_2 + 0x30);
          if (((local_7c == '\x04') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_DHDHDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,uVar7,local_98[0],
                          (char)(undefined2)local_98[6],(char)local_98[1],(char)local_98[6]._2_2_,
                          (byte)local_70 & 1,"22x response malformed");
          }
          uVar8 = 1;
        }
      }
      pbVar5 = pbVar4 + 2;
    } while ((pbVar5 < pbVar1) && ((int)uVar8 == 2));
    *(char *)((longlong)param_3 + 0xc) = (char)uVar8;
  }
  return 0;
}



===== MpsCopyFromNetBuffer @ 1400062d0 =====

void MpsCopyFromNetBuffer(void *param_1,longlong param_2,uint param_3)

{
  void *_Src;
  size_t _Size;
  
  _Size = (size_t)param_3;
  if (**(longlong **)(param_2 + 8) == 0) {
    _Src = (void *)MpsGetNetBufferData(param_2);
    memmove(param_1,_Src,_Size);
    return;
  }
  NdisGetDataBuffer(param_2,_Size,param_1,1,0);
  return;
}



===== MpsStreamFlowAnalysisCallout @ 140006330 =====

int MpsStreamFlowAnalysisCallout
              (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
              undefined8 param_5,longlong param_6,undefined4 *param_7)

{
  longlong lVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  longlong *plVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  ulonglong _Size;
  void *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  bVar4 = false;
  local_48 = (void *)0x0;
  local_38 = 0;
  lVar3 = *(longlong *)(*(longlong *)((byte *)*param_3 + 0x38) + 8);
  bVar5 = ~*(byte *)*param_3 & 1;
  uVar7 = *(uint *)(lVar3 + 0x18);
  uStack_40 = (ulonglong)bVar5 << 0x30;
  if (uVar7 == 0) {
    *param_7 = 0x2006;
    return 0;
  }
  uVar10 = (ulonglong)bVar5;
  uStack_30 = param_1;
  if (*(longlong *)(param_6 + 0x18 + uVar10 * 8) == 0) {
    if (0xffff < uVar7) {
      iVar6 = -0x3fffff3c;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar11 = 0x12;
        goto LAB_14000655f;
      }
      goto LAB_140006488;
    }
    uStack_40 = CONCAT62(uStack_40._2_6_,(short)uVar7);
    if (**(longlong **)(lVar3 + 8) == 0) {
      local_48 = (void *)MpsGetNetBufferData(lVar3);
LAB_1400063c1:
      iVar6 = DfwAnalyzeIpFlowData(param_6,(longlong *)&local_48);
      if (iVar6 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar11 = 0x13;
          goto LAB_14000656f;
        }
        goto LAB_140006488;
      }
      if (uStack_40._4_1_ != -0x80) {
        if (uStack_40._4_1_ == '\x02') {
          *param_7 = 0x1002;
        }
        else if (uStack_40._4_1_ == '\x01') {
          *param_7 = 0x1001;
          *(undefined4 *)(param_3 + 4) = 2;
        }
        else {
          *param_7 = 0x2006;
        }
        goto joined_r0x0001400063fb;
      }
      if (bVar4) {
        uVar10 = (ulonglong)(uStack_40._6_1_ & 1);
        *(ushort *)(param_6 + 0x28 + uVar10 * 2) = uStack_40._2_2_;
        *(ushort *)(param_6 + 0x2c + uVar10 * 2) = (short)uStack_40 - uStack_40._2_2_;
        *(void **)(param_6 + 0x18 + uVar10 * 8) = local_48;
LAB_14000673c:
        *param_7 = 0x1002;
        return iVar6;
      }
      _Size = (ulonglong)uStack_40._2_2_;
      pvVar8 = (void *)ExAllocatePool2(0x40,_Size,0x46776644);
      uVar10 = (ulonglong)(uStack_40._6_1_ & 1);
      *(void **)(param_6 + 0x18 + uVar10 * 8) = pvVar8;
      lVar3 = param_6 + uVar10 * 2;
      lVar1 = param_6 + uVar10 * 2;
      if (pvVar8 != (void *)0x0) {
        memmove(pvVar8,(void *)(((uStack_40 & 0xffff) - _Size) + (longlong)local_48),_Size);
        *(ushort *)(lVar3 + 0x28) = uStack_40._2_2_;
        *(undefined2 *)(lVar1 + 0x2c) = 0;
        goto LAB_14000673c;
      }
      *(undefined2 *)(lVar3 + 0x28) = 0;
      *(undefined2 *)(lVar1 + 0x2c) = 0;
      plVar9 = *(longlong **)(param_6 + 0x10);
      if (plVar9 != (longlong *)0x0) {
        do {
          *(undefined2 *)((longlong)plVar9 + uVar10 * 2 + 8) = 0;
          plVar9 = (longlong *)*plVar9;
        } while (plVar9 != (longlong *)0x0);
      }
    }
    else {
      local_48 = (void *)ExAllocatePool2(0x40,uVar7 & 0xffff,0x46776644);
      if (local_48 != (void *)0x0) {
        bVar4 = true;
        MpsCopyFromNetBuffer(local_48,lVar3,uVar7 & 0xffff);
        goto LAB_1400063c1;
      }
    }
LAB_14000647c:
    iVar6 = -0x3fffffe9;
  }
  else {
    uVar2 = *(ushort *)(param_6 + 0x28 + uVar10 * 2);
    if (uVar7 + uVar2 < (uint)uVar2) {
      iVar6 = -0x3fffff3c;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar11 = 0x10;
LAB_14000655f:
        iVar6 = -0x3fffff3c;
LAB_14000656f:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                 &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar6);
      }
    }
    else {
      if (uVar7 + uVar2 < 0x10000) {
        uVar7 = uVar7 + uVar2;
        uStack_40 = CONCAT62(CONCAT42(uStack_40._4_4_,uVar2),(short)uVar7);
        pvVar8 = (void *)ExAllocatePool2(0x40,uVar7 & 0xffff,0x46776644);
        local_48 = pvVar8;
        if (pvVar8 == (void *)0x0) goto LAB_14000647c;
        bVar4 = true;
        memmove(pvVar8,(void *)((ulonglong)*(ushort *)(param_6 + 0x2c + uVar10 * 2) +
                               *(longlong *)(param_6 + 0x18 + uVar10 * 8)),(ulonglong)uVar2);
        MpsCopyFromNetBuffer
                  ((void *)((longlong)pvVar8 + (ulonglong)uVar2),lVar3,
                   (uVar7 & 0xffff) - (uint)uVar2);
        ExFreePoolWithTag(*(undefined8 *)(param_6 + 0x18 + uVar10 * 8),0);
        *(undefined8 *)(param_6 + 0x18 + uVar10 * 8) = 0;
        goto LAB_1400063c1;
      }
      iVar6 = -0x3fffff3c;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar11 = 0x11;
        goto LAB_14000655f;
      }
    }
  }
LAB_140006488:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar6);
  }
  *param_7 = 0x1001;
  *(undefined4 *)(param_3 + 4) = 2;
joined_r0x0001400063fb:
  if (bVar4) {
    ExFreePoolWithTag(local_48,0);
  }
  return iVar6;
}



===== DfwAnalyzeIpFlowData @ 140006770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DfwAnalyzeIpFlowData(longlong param_1,longlong *param_2)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined1 auStack_78 [32];
  longlong local_58;
  ushort local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined1 local_4a;
  undefined1 local_49;
  undefined7 uStack_48;
  undefined1 local_41;
  longlong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_4c = 0;
  local_49 = 0;
  uStack_48 = 0;
  local_41 = 0;
  piVar1 = (int *)(param_1 + (ulonglong)(*(byte *)((longlong)param_2 + 0xe) & 1) * 4);
  *piVar1 = *piVar1 + ((uint)*(ushort *)(param_2 + 1) - (uint)*(ushort *)((longlong)param_2 + 10));
  local_4a = *(undefined1 *)((longlong)param_2 + 0xe);
  uVar2 = *(ushort *)((longlong)param_2 + 10);
  local_40 = param_2[3];
  *(undefined1 *)((longlong)param_2 + 0xc) = 2;
  *(undefined2 *)((longlong)param_2 + 10) = 0;
  puVar7 = *(undefined8 **)(param_1 + 0x10);
  while( true ) {
    if (puVar7 == (undefined8 *)0x0) {
      return 0;
    }
    uVar5 = (ulonglong)(*(byte *)((longlong)param_2 + 0xe) & 1);
    uVar6 = (uint)uVar2 - (uint)*(ushort *)((longlong)puVar7 + uVar5 * 2 + 8);
    local_58 = (ulonglong)uVar6 + *param_2;
    local_50 = (short)param_2[1] - (short)uVar6;
    local_4e = *(undefined2 *)((longlong)puVar7 + uVar5 * 2 + 8);
    *(undefined2 *)((longlong)puVar7 + uVar5 * 2 + 8) = 0;
    iVar4 = (**(code **)(*(longlong *)
                          (&DAT_1400158c0 + (ulonglong)*(byte *)((longlong)puVar7 + 0xc) * 8) + 0x10
                        ))(puVar7 + 2,param_1,&local_58);
    if (iVar4 < 0) break;
    if ((char)local_4c != '\x02') {
      if (((char)local_4c == '\x01') || ((char)local_4c == '\x11')) {
        *(undefined1 *)((longlong)param_2 + 0xd) = local_4c._1_1_;
        param_2[2] = CONCAT17(local_41,uStack_48);
        *(char *)((longlong)param_2 + 0xc) = (char)local_4c;
        return 0;
      }
      if ((char)local_4c != -0x80) {
        *(undefined1 *)((longlong)param_2 + 0xc) = 1;
        return 0;
      }
      *(undefined1 *)((longlong)param_2 + 0xc) = 0x80;
      uVar3 = *(ushort *)((longlong)param_2 + 10);
      if (*(ushort *)((longlong)param_2 + 10) <= local_50) {
        uVar3 = local_50;
      }
      *(ushort *)((longlong)param_2 + 10) = uVar3;
      *(ushort *)((longlong)puVar7 + (ulonglong)(*(byte *)((longlong)param_2 + 0xe) & 1) * 2 + 8) =
           local_50;
    }
    puVar7 = (undefined8 *)*puVar7;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar4);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar4);
    }
  }
  *(undefined1 *)((longlong)param_2 + 0xc) = 1;
  return iVar4;
}



===== MpsGetNetBufferData @ 140006960 =====

ulonglong MpsGetNetBufferData(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((*(byte *)(lVar1 + 10) & 1) == 0) {
    uVar4 = (ulonglong)*(uint *)(lVar1 + 0x2c) + *(longlong *)(lVar1 + 0x20);
    uVar3 = *(uint *)(param_1 + 0x10) + uVar4;
    uVar2 = 0;
    if (uVar4 <= uVar3) {
      uVar2 = uVar3;
    }
  }
  else {
    uVar2 = (ulonglong)*(uint *)(param_1 + 0x10) + *(ulonglong *)(lVar1 + 0x18);
    if (uVar2 < *(ulonglong *)(lVar1 + 0x18)) {
      return 0;
    }
  }
  return uVar2;
}



===== MpsDummyFilterNotify @ 1400069a0 =====

undefined8 MpsDummyFilterNotify(void)

{
  return 0;
}



===== DfwDispatchCreate @ 1400069b0 =====

int DfwDispatchCreate(void)

{
  int iVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  iVar1 = MpsInitializeFwp();
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  return iVar1;
}



===== MpsDeinitializeFwp @ 140006a90 =====

int MpsDeinitializeFwp(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids;
    param_2 = 0x24;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  MpsUnregisterCallouts();
  iVar1 = MpsStopTroubleshooting(1,param_2,param_3);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
    }
    DAT_1400156a4 = iVar1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  return iVar1;
}



===== MpsInitializeFwp @ 140006b80 =====

int MpsInitializeFwp(void)

{
  int iVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  if (((DAT_1400156a4 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
  }
  iVar1 = MpsRegisterCallouts();
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  return iVar1;
}



===== MpsRegisterCallouts @ 140006c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsRegisterCallouts(void)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  iVar3 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = (code *)0x0;
  local_40 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  uVar6 = 0;
  local_68 = 0xc3dbed20;
  uStack_64 = 0x4bf30bb6;
  uStack_60 = 0x73968d82;
  uStack_5c = 0x1e2e;
  do {
    if (4 < uVar6) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
      }
      return iVar3;
    }
    uVar4 = (ulonglong)uVar6;
    uVar5 = 0;
    uStack_5c._0_3_ = CONCAT12((char)uVar6,(undefined2)uStack_5c);
    local_48 = MpsDummyFilterNotify;
    local_58 = CONCAT44(local_58._4_4_,*(undefined4 *)(&DAT_140012010 + uVar4 * 0x24));
    local_50 = *(undefined8 *)((longlong)&PTR_MpsQueryUserCallout_140012000 + uVar4 * 0x24);
    local_40 = *(undefined8 *)(&DAT_140012008 + uVar4 * 0x24);
    while( true ) {
      lVar1 = *(longlong *)((longlong)&PTR_PTR_140012014 + uVar4 * 0x24);
      lVar2 = *(longlong *)(lVar1 + (ulonglong)uVar5 * 0xc);
      if (lVar2 == 0) break;
      uStack_5c = CONCAT13(*(undefined1 *)(lVar2 + 8),(undefined3)uStack_5c);
      iVar3 = FwpsCalloutRegisterWithoutDevice0(&local_68,lVar1 + (ulonglong)uVar5 * 0xc + 8);
      if (iVar3 < 0) {
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                     &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar3);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                     &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar3);
          }
        }
        MpsUnregisterCallouts();
        return iVar3;
      }
      uVar5 = uVar5 + 1;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== MpsUnregisterCallouts @ 140006e50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MpsUnregisterCallouts(void)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  uVar4 = 0;
  ppuVar5 = &PTR_PTR_140012014;
  local_28 = 0xc3dbed20;
  uStack_24 = 0x4bf30bb6;
  uStack_20 = 0x73968d82;
  uStack_1c = 0x1e2e;
  do {
    plVar1 = (longlong *)*ppuVar5;
    uVar3 = 0;
    uStack_1c._0_3_ = CONCAT12((char)uVar4,(undefined2)uStack_1c);
    if (*plVar1 != 0) {
      lVar2 = 0;
      do {
        uStack_1c = CONCAT13(*(undefined1 *)(*(longlong *)((longlong)plVar1 + lVar2) + 8),
                             (undefined3)uStack_1c);
        FwpsCalloutUnregisterByKey0(&local_28);
        plVar1 = (longlong *)*ppuVar5;
        uVar3 = (ulonglong)((int)uVar3 + 1);
        lVar2 = uVar3 * 0xc;
      } while (*(longlong *)((longlong)plVar1 + lVar2) != 0);
    }
    uVar4 = uVar4 + 1;
    ppuVar5 = (undefined **)((longlong)ppuVar5 + 0x24);
  } while (uVar4 < 5);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  return;
}



===== MpsDispatchClose @ 140006f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int MpsDispatchClose(undefined8 param_1,longlong param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  if (DAT_140015ad0 != (code *)0x0) {
    iVar2 = (*DAT_140015ad0)(param_1,param_2);
    if (iVar2 < 0) {
      bVar1 = true;
      iVar2 = 0;
    }
  }
  if (bVar1) {
    *(undefined8 *)(g_DriverObject + 0x68) = 0;
  }
  *(int *)(param_2 + 0x30) = iVar2;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar2);
  }
  return iVar2;
}



===== __FlushUpcall @ 140007070 =====

void __FlushUpcall(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
  }
  while (plVar7 = DAT_140015780, puVar6 = DAT_1400157b0,
        (longlong **)DAT_140015780 != &DAT_140015780) {
    lVar1 = *DAT_140015780;
    if ((*(longlong **)(lVar1 + 8) != DAT_140015780) ||
       (plVar2 = (longlong *)DAT_140015780[1], (longlong *)*plVar2 != DAT_140015780))
    goto LAB_1400071cd;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseInStackQueuedSpinLock(param_1);
    CompleteUpcallIrp(plVar7[2],-0x3ffffee0,param_3);
    ExFreeToNPagedLookasideList(&DAT_1400157c0,plVar7);
    KeAcquireInStackQueuedSpinLock(&DAT_140015798,param_1);
  }
  while( true ) {
    if ((undefined8 **)puVar6 == &DAT_1400157b0) {
      DAT_140015790 = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      }
      return;
    }
    puVar3 = (undefined8 *)*puVar6;
    if (((undefined8 *)puVar3[1] != puVar6) ||
       (puVar4 = (undefined8 *)puVar6[1], (undefined8 *)*puVar4 != puVar6)) break;
    DAT_140015684 = DAT_140015684 + -1;
    *puVar4 = puVar3;
    puVar3[1] = puVar4;
    ExFreeToNPagedLookasideList(&DAT_140015840);
    puVar6 = puVar3;
  }
LAB_1400071cd:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== ETWLogKMSystemControl @ 1400071e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ETWLogKMSystemControl(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined **ppuVar12;
  undefined1 auStack_68 [32];
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  ulonglong local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar8 = 0;
  uVar7 = 0;
  uVar9 = *(uint *)(lVar2 + 0x18);
  puVar3 = *(undefined8 **)(lVar2 + 0x20);
  if (param_1 == *(longlong *)(lVar2 + 8)) {
    cVar1 = *(char *)(lVar2 + 1);
    if (cVar1 == '\v') {
      if (uVar9 < 0x38) {
        uVar7 = 0xc0000023;
        if (3 < uVar9) {
          *(undefined4 *)puVar3 = 0x38;
          uVar8 = 4;
        }
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        uVar8 = 0x38;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        uVar5 = *(undefined8 *)PTR_NseKmInfoProviderGuid_140015148;
        uVar6 = *(undefined8 *)(PTR_NseKmInfoProviderGuid_140015148 + 8);
        *(undefined4 *)(puVar3 + 5) = 0x81000;
        puVar3[3] = uVar5;
        puVar3[4] = uVar6;
        *(undefined4 *)puVar3 = 0x38;
        *(undefined4 *)(puVar3 + 2) = 1;
      }
    }
    else {
      switch(cVar1) {
      default:
        uVar7 = 0xc0000010;
        break;
      case '\x04':
      case '\x05':
        if (uVar9 < 0x30) {
          uVar7 = 0xc000000d;
        }
        else {
          uVar10 = 0;
          ppuVar12 = &PTR_NseKmInfoProviderGuid_140015148;
          do {
            lVar11 = *(longlong *)*ppuVar12 - **(longlong **)(lVar2 + 0x10);
            if (lVar11 == 0) {
              lVar11 = *(longlong *)((longlong)*ppuVar12 + 8) - (*(longlong **)(lVar2 + 0x10))[1];
            }
            if (lVar11 == 0) {
              if (cVar1 == '\x05') {
                (&ETWLOG_CONTROL_DATA)[uVar10 * 2] = 0;
              }
              else {
                uVar4 = puVar3[1];
                (&ETWLOG_CONTROL_DATA)[uVar10 * 2] = uVar4;
                local_48 = 0x30;
                local_46 = 0;
                local_42 = 0;
                local_38 = 0;
                local_20 = 0;
                local_1c = 0x20000;
                local_30 = 0x68fdd900;
                uStack_2c = 0x11d14a3e;
                uStack_28 = 0xf484;
                uStack_24 = 0xe36404f8;
                if (uVar4 != 0) {
                  local_40 = 0xffff;
                  if ((short)uVar4 != -1) {
                    local_40 = uVar4 & 0xffff;
                  }
                  IoWMIWriteEvent(&local_48);
                }
              }
              uVar7 = 0;
              goto switchD_140007252_caseD_6;
            }
            uVar9 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar9;
            ppuVar12 = ppuVar12 + 2;
          } while (uVar9 == 0);
          uVar7 = 0xc0000295;
        }
        break;
      case '\x06':
      case '\a':
        break;
      }
    }
switchD_140007252_caseD_6:
    *(undefined4 *)(param_2 + 0x30) = uVar7;
    *(undefined8 *)(param_2 + 0x38) = uVar8;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar7 = *(undefined4 *)(param_2 + 0x30);
  }
  return uVar7;
}



===== MpsInitIoLayer @ 1400073c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MpsInitIoLayer(void)

{
  undefined8 *_Dst;
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined1 local_a0;
  longlong *local_98;
  longlong local_88 [5];
  wchar_t local_60 [12];
  undefined8 local_48;
  wchar_t awStack_40 [20];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  builtin_wcsncpy(awStack_40 + 0xc,L"evice",6);
  builtin_wcsncpy(local_60,L"\\Device\\MPS",0xc);
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  g_fMpsSymbolicLinkCreated = '\0';
  local_48._0_2_ = L'\\';
  local_48._2_2_ = L'D';
  local_48._4_2_ = L'o';
  local_48._6_2_ = L's';
  builtin_wcsncpy(awStack_40,L"Devices\\MpsD",0xc);
  local_88[3] = 0;
  local_88[4] = 0;
  RtlInitUnicodeString(local_88 + 1,local_60);
  local_98 = local_88;
  local_a0 = 1;
  local_a8 = 0x100;
  iVar1 = IoCreateDevice(g_DriverObject,0xe8,local_88 + 1,32000);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000764d;
    uVar2 = 10;
  }
  else {
    iVar1 = MpsSetDeviceSecurity(local_88[0]);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000764d;
      uVar2 = 0xb;
    }
    else {
      *(uint *)(local_88[0] + 0x30) = *(uint *)(local_88[0] + 0x30) | 4;
      _Dst = *(undefined8 **)(local_88[0] + 0x40);
      memset(_Dst,0,0xe8);
      *_Dst = MpsDispatchCreate;
      _Dst[2] = MpsDispatchClose;
      _Dst[0x12] = MpsDispatchCleanup;
      _Dst[0xe] = MpsDispatchDevCtl;
      DAT_140015a68 = &WPP_ThisDir_CTLGUID_MpsDrvTrace;
      _WPP_MAIN_CB = 0;
      DAT_140015a70 = 0;
      _DAT_140015a80 = 0;
      _DAT_140015a88 = 1;
      WppLoadTracingSupport();
      _DAT_140015a80 = 0;
      WppInitKm();
      g_fWPPInited = '\x01';
      RtlInitUnicodeString(local_88 + 3,&local_48);
      *(code **)(g_DriverObject + 0x128) = ETWLogKMSystemControl;
      iVar1 = IoWMIRegistrationControl(local_88[0],1);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000764d;
        uVar2 = 0xc;
      }
      else {
        g_fETWInited = '\x01';
        iVar1 = IoCreateSymbolicLink(local_88 + 3,local_88 + 1);
        if (-1 < iVar1) {
          g_pMpsDeviceObject = local_88[0];
          g_fMpsSymbolicLinkCreated = 1;
          g_fMpsIoLayerInited = 1;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            g_fMpsIoLayerInited = 1;
            g_fMpsSymbolicLinkCreated = 1;
            return iVar1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
            g_fMpsIoLayerInited = 1;
            g_fMpsSymbolicLinkCreated = 1;
            return iVar1;
          }
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
          return iVar1;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000764d;
        uVar2 = 0xd;
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar1);
LAB_14000764d:
  if (g_fMpsSymbolicLinkCreated != '\0') {
    IoDeleteSymbolicLink(local_88 + 3);
    g_fMpsSymbolicLinkCreated = '\0';
  }
  if (g_fETWInited != '\0') {
    IoWMIRegistrationControl(local_88[0],2);
    g_fETWInited = '\0';
  }
  if (g_fWPPInited != '\0') {
    WppCleanupKm();
    g_fWPPInited = '\0';
  }
  if (local_88[0] != 0) {
    IoDeleteDevice();
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar1);
  }
  return iVar1;
}



===== MpsSetDeviceSecurity @ 140007760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsSetDeviceSecurity(undefined8 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 auStack_138 [32];
  undefined4 local_118 [7];
  undefined2 local_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined1 local_c8 [80];
  undefined1 local_78 [96];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_118[6] = 0;
  local_fc = 0x500;
  local_d8 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  memset(local_c8,0,0x44);
  memset(local_78,0,0x54);
  local_118[0] = 0x50;
  local_118[1] = 0xb81041f1;
  local_118[2] = 0x574dfc36;
  local_118[3] = 0x700baea8;
  local_118[4] = 0x42042125;
  local_118[5] = 0x31114f84;
  iVar2 = RtlInitializeSid(local_c8,local_118 + 6,6);
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar2;
    }
    uVar4 = 0x1d;
  }
  else {
    uVar5 = 0;
    puVar6 = local_118;
    do {
      puVar3 = (undefined4 *)RtlSubAuthoritySid(local_c8,uVar5);
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar5 = uVar5 + 1;
      *puVar3 = uVar1;
    } while (uVar5 < 6);
    iVar2 = RtlLengthRequiredSid(6);
    iVar2 = RtlCreateAcl(local_78,iVar2 + 0x10,2);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar2;
      }
      uVar4 = 0x1e;
    }
    else {
      iVar2 = RtlAddAccessAllowedAce(local_78,2,0x10000000,local_c8);
      if (iVar2 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return iVar2;
        }
        uVar4 = 0x1f;
      }
      else {
        iVar2 = RtlCreateSecurityDescriptor(&local_f8,1);
        if (iVar2 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar2;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return iVar2;
          }
          uVar4 = 0x20;
        }
        else {
          iVar2 = RtlSetDaclSecurityDescriptor(&local_f8,1,local_78,0);
          if (iVar2 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar2;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
              return iVar2;
            }
            uVar4 = 0x21;
          }
          else {
            iVar2 = ObSetSecurityObjectByPointer(param_1,4,&local_f8);
            if (-1 < iVar2) {
              return iVar2;
            }
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar2;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
              return iVar2;
            }
            uVar4 = 0x22;
          }
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar2);
  return iVar2;
}



===== DfwInitializeIpFiltering @ 140007a50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DfwInitializeIpFiltering(void)

{
  int iVar1;
  ulonglong uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  }
  _DAT_1400157a8 = 0;
  KeInitializeSpinLock(&DAT_1400157a8);
  uVar2 = CreateFilterList();
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_22c82edf472934362cca16c116ec1405_Traceguids,iVar1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_22c82edf472934362cca16c116ec1405_Traceguids,iVar1);
      }
    }
    DfwDeinitializeIpFiltering();
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  }
  return uVar2 & 0xffffffff;
}



===== MpsInitializeWorkerThread @ 140007b50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MpsInitializeWorkerThread(void)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar2;
  ulonglong in_stack_ffffffffffffffe8;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids);
  }
  if (WorkerThreadInitialized != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids);
    }
    return -0x3fffffff;
  }
  ExInitializeNPagedLookasideList
            (&WorkItemLookasideList,0,0,0x200,0x20,CONCAT44(uVar2,0x524b5257),
             in_stack_ffffffffffffffe8 & 0xffffffffffff0000);
  _WorkerThreadLock = 0;
  DAT_140015988 = &WorkItemList;
  WorkItemList = &WorkItemList;
  KeInitializeSpinLock(&WorkerThreadLock);
  KeInitializeEvent(&WorkerThreadWakeupEvent,1,0);
  KeInitializeEvent(&WorkerThreadKillEvent,1,0);
  iVar1 = PsCreateSystemThread(&PassiveThread,0,0,0,0,MpsWorkerThread,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids,iVar1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids,iVar1);
      }
    }
  }
  else {
    WorkerThreadInitialized = '\x01';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids);
    }
  }
  return iVar1;
}



===== DriverEntry @ 140007d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  
  wil_InitializeFeatureStaging();
  EtwRegister(&MS_MPS_DRV_Provider,0,0);
  if (g_Provider != 0) {
    EtwWrite(g_Provider,&MPS_DRV_Start_Begin,0,0,0);
  }
  g_DriverObject = param_1;
  *(code **)(param_1 + 0x68) = DriverUnload;
  *(code **)(param_1 + 0x70) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x78) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x80) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x88) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x90) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x98) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xa0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xa8) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xb0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xb8) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xc0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 200) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xd0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xd8) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xe0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xe8) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xf0) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0xf8) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x100) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x108) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x110) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x118) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x120) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x128) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x130) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x138) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x140) = MpsIoLayerDispatchIrp;
  *(code **)(param_1 + 0x148) = MpsIoLayerDispatchIrp;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids);
  }
  puVar4 = (undefined *)0x128;
  memset(&g_MpsModulesList,0,0x128);
  NseQueryExportTable((undefined4 *)&g_MpsModulesList);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    puVar4 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids,0);
  }
  iVar1 = MpsInitIoLayer();
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140008171;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar2 = 0xc;
      goto LAB_140008136;
    }
  }
  else {
    DAT_140015634 = DAT_140015634 + 1;
    iVar1 = MpsInitializeWorkerThread();
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140008171;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar2 = 0xd;
LAB_140008136:
        puVar4 = &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
                 &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids,iVar1);
      }
    }
    else {
      DAT_140015634 = DAT_140015634 + 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      }
      ExInitializeNPagedLookasideList(&DAT_1400157c0,0,0,0x200,0x28,0x6d6b7570,0);
      puVar4 = (undefined *)0x0;
      ExInitializeNPagedLookasideList(&DAT_140015840,0,0,0x200,0xff8,0x51755532,0);
      DAT_140015684 = 0;
      _DAT_140015788 = &DAT_140015780;
      DAT_140015780 = &DAT_140015780;
      DAT_1400157b8 = &DAT_1400157b0;
      DAT_1400157b0 = &DAT_1400157b0;
      DAT_140015790 = 0;
      _DAT_140015798 = 0;
      KeInitializeSpinLock(&DAT_140015798);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        puVar4 = &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids);
      }
      DAT_140015634 = DAT_140015634 + 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        puVar4 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids);
      }
      iVar1 = (*DAT_140015aa8)();
      if (-1 < iVar1) {
        DAT_140015ab0 = 1;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids);
        }
        DAT_140015634 = DAT_140015634 + 2;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids);
        }
        AuditSuccessEvent(0x13a9);
        if (g_Provider != 0) {
          EtwWrite(g_Provider,&MPS_DRV_Start_End,0,0,0);
        }
        return iVar1;
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          puVar4 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids,iVar1);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          puVar4 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids,iVar1);
        }
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140008171;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar2 = 0xf;
        goto LAB_140008136;
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar4 = &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids,iVar1);
  }
LAB_140008171:
  uVar3 = 0x13ab;
  AuditOneArgError(iVar1,0x13ab);
  DriverUnload(param_1,uVar3,puVar4);
  return iVar1;
}



===== MpsFlowEstablishedCallout @ 140008250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsFlowEstablishedCallout(short *param_1,uint *param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined **ppuVar5;
  undefined4 *in_stack_00000038;
  undefined1 auStack_b8 [32];
  longlong local_98 [2];
  int local_88 [7];
  char local_6c;
  char local_6b;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  memset(local_88,0,0x50);
  local_98[0] = 0;
  uVar3 = 0;
  MpsGetFwpAuthData(param_1,param_2,param_3,local_88);
  if ((*param_2 & 2) != 0) {
    uVar3 = *(undefined8 *)(param_2 + 8);
  }
  iVar1 = DfwCreateIpFlow((longlong)local_88,local_98);
  lVar4 = local_98[0];
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400083ff;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
    }
    lVar4 = local_98[0];
  }
  else {
    if (local_98[0] == 0) {
LAB_14000840e:
      *in_stack_00000038 = 0x2006;
      return iVar1;
    }
    *(undefined8 *)(local_98[0] + 0x18) = 0;
    *(undefined8 *)(local_98[0] + 0x20) = 0;
    if (local_6b == '\x06') {
      ppuVar5 = &PTR_PTR_140015478;
      if (local_6c == '\x06') {
        ppuVar5 = &PTR_PTR_140015484;
      }
      iVar1 = FwpsFlowAssociateContext0
                        (uVar3,*(undefined2 *)(*ppuVar5 + 8),*(undefined4 *)(ppuVar5 + 1),
                         local_98[0]);
      if (-1 < iVar1) goto LAB_14000840e;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400083ff;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar2 = 0xe;
        goto LAB_1400083c4;
      }
    }
    else {
      iVar1 = -0x3fffff3c;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400083ff;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        uVar2 = 0xd;
        iVar1 = -0x3fffff3c;
LAB_1400083c4:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
                 &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar1);
  }
LAB_1400083ff:
  if (lVar4 != 0) {
    DfwDeleteIpFlow(lVar4);
  }
  return iVar1;
}



===== DfwCreateIpFlow @ 140008440 =====

int DfwCreateIpFlow(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  void *_Dst;
  void *_Dst_00;
  byte bVar5;
  byte bVar6;
  longlong *plVar7;
  int local_48 [2];
  longlong local_40;
  
  *param_2 = 0;
  plVar7 = (longlong *)0x0;
  local_40 = 0;
  local_48[0] = 0;
  if ((*(byte *)(param_1 + 0x28) & 5) == 4) {
    return 0;
  }
  iVar4 = DfwHandleFlowCreation(param_1,&local_40,local_48);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar4);
    }
    DfwDeleteAnalyzers((longlong *)0x0);
  }
  else {
    if (local_40 != 0) {
      plVar7 = (longlong *)(local_40 + -0x10);
    }
    _Dst = (void *)ExAllocateFromNPagedLookasideList(&DAT_140015900);
    if (_Dst == (void *)0x0) {
      iVar4 = -0x3fffffe9;
      DfwDeleteAnalyzers(plVar7);
    }
    else {
      LOCK();
      g_nIpFlows._0_4_ = (int)g_nIpFlows + 1;
      UNLOCK();
      memset(_Dst,0,0x40);
      if (local_48[0] != 0) {
        uVar2 = *(uint *)(param_1 + 0x38);
        _Dst_00 = (void *)ExAllocatePool2(0x40,uVar2,0x4970466c);
        if (_Dst_00 == (void *)0x0) {
          *(undefined8 *)((longlong)_Dst + 0x30) = 0;
          DfwDeleteAnalyzers(plVar7);
          ExFreeToNPagedLookasideList(&DAT_140015900,_Dst);
          LOCK();
          g_nIpFlows._0_4_ = (int)g_nIpFlows + -1;
          UNLOCK();
          return -0x3fffffe9;
        }
        memset(_Dst_00,0,(ulonglong)uVar2);
        *(void **)((longlong)_Dst + 0x30) = _Dst_00;
        uVar2 = *(uint *)(param_1 + 0x38);
        *(uint *)((longlong)_Dst + 0x38) = uVar2;
        memmove(_Dst_00,*(void **)(param_1 + 0x30),(ulonglong)uVar2);
      }
      bVar5 = (*(byte *)((longlong)_Dst + 8) ^ *(byte *)(param_1 + 0x28)) & 1 ^
              *(byte *)((longlong)_Dst + 8);
      *(byte *)((longlong)_Dst + 8) = bVar5;
      bVar3 = 0;
      if (*(char *)(param_1 + 0x1c) == '\x06') {
        bVar3 = 2;
      }
      *(byte *)((longlong)_Dst + 8) = bVar3 | bVar5 & 0xfd;
      cVar1 = *(char *)(param_1 + 0x1d);
      *(longlong **)((longlong)_Dst + 0x10) = plVar7;
      bVar6 = 0;
      if (cVar1 == '\x06') {
        bVar6 = 4;
      }
      *(byte *)((longlong)_Dst + 8) = bVar6 | bVar3 | bVar5 & 0xf9;
      *param_2 = _Dst;
    }
  }
  return iVar4;
}



===== DfwDeleteIpFlow @ 140008630 =====

void DfwDeleteIpFlow(longlong param_1)

{
  DfwDeleteAnalyzers(*(longlong **)(param_1 + 0x10));
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
  }
  ExFreeToNPagedLookasideList(&DAT_140015900,param_1);
  LOCK();
  g_nIpFlows._0_4_ = (int)g_nIpFlows + -1;
  UNLOCK();
  return;
}



===== DfwDeleteAnalyzers @ 140008690 =====

void DfwDeleteAnalyzers(longlong *param_1)

{
  longlong *plVar1;
  
  if (param_1 != (longlong *)0x0) {
    do {
      plVar1 = (longlong *)*param_1;
      DfwDeleteAnalyzer((longlong)param_1);
      param_1 = plVar1;
    } while (plVar1 != (longlong *)0x0);
  }
  return;
}



===== AuditOneArgError @ 1400086c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AuditOneArgError(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_488 [32];
  undefined4 local_468;
  undefined4 local_458 [2];
  undefined8 local_450;
  undefined8 uStack_448;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined2 local_426;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_488;
  local_458[0] = param_1;
  memset(&local_438,0,0x418);
  local_450 = 0;
  uStack_448 = 0;
  RtlInitUnicodeString(&local_450,L"Security");
  local_438 = 1;
  local_426 = 0x10;
  local_434 = param_2;
  iVar1 = SeSetAuditParameter(&local_438,3,1,local_458);
  if (-1 < iVar1) {
    local_430 = 1;
    local_468 = 0x68;
    SeReportSecurityEventWithSubCategory(0,&local_450,0,&local_438);
  }
  return;
}



===== ParseDec16bit @ 1400087a0 =====

undefined8 ParseDec16bit(char *param_1,char *param_2,undefined2 *param_3)

{
  uint uVar1;
  
  if ((longlong)param_2 - (longlong)param_1 < 6) {
    uVar1 = 0;
    for (; param_1 < param_2; param_1 = param_1 + 1) {
      if (9 < (byte)(*param_1 - 0x30U)) {
        return 0;
      }
      uVar1 = (int)*param_1 + (uVar1 * 5 + -0x18) * 2;
    }
    if (uVar1 < 0x10000) {
      *param_3 = (short)uVar1;
      return 1;
    }
  }
  return 0;
}



===== MpsStopTroubleshooting @ 1400087f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsStopTroubleshooting(int param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined **ppuVar4;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_2 = 0x37;
    param_3 = &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  lVar1 = DAT_140015698;
  if (param_1 != 0) {
    LOCK();
    DAT_1400156a0 = DAT_1400156a0 + 1;
    UNLOCK();
  }
  LOCK();
  DAT_140015698 = 0;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,lVar1);
  }
  if (lVar1 != 0) {
    ppuVar4 = &PTR_PTR_1400151f0;
    lVar3 = 0x36;
    local_28 = 0x4bf30bb6c3dbed20;
    uStack_20 = 0x51e2e73968d82;
    do {
      uStack_20 = CONCAT17((*ppuVar4)[8],(undefined7)uStack_20);
      FwpsCalloutUnregisterByKey0(&local_28);
      ppuVar4 = (undefined **)((longlong)ppuVar4 + 0xc);
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    iVar2 = FwpmEngineClose0(lVar1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,param_3,iVar2,lVar1);
    }
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                 &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar2);
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar2;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
               &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar2);
      return iVar2;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  return iVar2;
}



===== AuditSuccessEvent @ 1400089c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AuditSuccessEvent(undefined4 param_1)

{
  undefined1 auStack_478 [32];
  undefined4 local_458;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined2 local_426;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_478;
  memset(&local_438,0,0x418);
  local_448 = 0;
  uStack_440 = 0;
  RtlInitUnicodeString(&local_448,L"Security");
  local_426 = 8;
  local_438 = 1;
  local_430 = 0;
  local_458 = 0x68;
  local_434 = param_1;
  SeReportSecurityEventWithSubCategory(0,&local_448,0,&local_438);
  return;
}



===== CreateFilterList @ 140008a70 =====

undefined8 CreateFilterList(void)

{
  undefined8 *puVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x18,0x52544c46);
  if (puVar1 == (undefined8 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,0xc0000017);
    }
    DAT_1400157a0 = (undefined8 *)0x0;
    return 0xc0000017;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined4 *)puVar1 = 1;
  *(undefined2 *)((longlong)puVar1 + 4) = 1;
  *(undefined1 *)((longlong)puVar1 + 6) = 2;
  DAT_1400157a0 = puVar1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  return 0;
}



===== _guard_check_icall @ 140008b70 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 140008b90 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DriverUnload @ 140008ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DriverUnload(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  wchar_t local_48 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  bVar1 = false;
  if (g_Provider != 0) {
    local_88 = (undefined8 *)0x0;
    param_3 = (undefined *)0x0;
    EtwWrite(g_Provider,&MPS_DRV_Stop_Begin);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids);
  }
  if (DAT_140015634 != 1) {
    if (DAT_140015634 != 2) {
      if (DAT_140015634 != 3) {
        if (DAT_140015634 != 4) {
          if (DAT_140015634 != 5) goto LAB_140008fa4;
          DAT_140015634 = 4;
          bVar1 = true;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          param_3 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids);
        }
        if (DAT_140015ab0 != '\0') {
          (*DAT_140015ab8)();
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          param_3 = &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_4bad4e63b4fe3418060d6a1f6e2481b6_Traceguids,0);
        }
        DAT_140015634 = DAT_140015634 + -1;
      }
      puVar4 = &local_78;
      local_78 = 0;
      uStack_70 = 0;
      local_68 = 0;
      KeAcquireInStackQueuedSpinLock(&DAT_140015798);
      __FlushUpcall(&local_78,puVar4,param_3);
      ExDeleteNPagedLookasideList(&DAT_1400157c0);
      ExDeleteNPagedLookasideList(&DAT_140015840);
      KeReleaseInStackQueuedSpinLock(&local_78);
      DAT_140015634 = DAT_140015634 + -1;
    }
    local_60 = 0;
    uStack_58 = 0;
    local_50 = 0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_1d99a0b5c5fd3d8165a304d829914fd4_Traceguids);
    }
    KeAcquireInStackQueuedSpinLock(&WorkerThreadLock,&local_60);
    if ((WorkerThreadInitialized == '\0') || (PassiveThread == 0)) {
      KeReleaseInStackQueuedSpinLock(&local_60);
    }
    else {
      WorkerThreadInitialized = '\0';
      KeReleaseInStackQueuedSpinLock(&local_60);
      local_88 = &local_78;
      local_80 = 0;
      local_78 = 0;
      iVar3 = ObReferenceObjectByHandle(PassiveThread,0,0,0);
      uVar2 = local_78;
      if (iVar3 == 0) {
        KeSetEvent(&WorkerThreadKillEvent,0,0);
        local_88 = (undefined8 *)0x0;
        KeWaitForSingleObject(uVar2,0,0,0);
        ObfDereferenceObject(uVar2);
      }
      ZwClose(PassiveThread);
      ExDeleteNPagedLookasideList(&WorkItemLookasideList);
    }
    DAT_140015634 = DAT_140015634 + -1;
  }
  builtin_wcsncpy(local_48 + 0x10,L"evice",6);
  builtin_wcsncpy(local_48,L"\\DosDevices\\MpsD",0x10);
  local_78 = 0;
  uStack_70 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  if (g_fMpsIoLayerInited != '\0') {
    RtlInitUnicodeString(&local_78,local_48);
    if (g_fMpsSymbolicLinkCreated != '\0') {
      IoDeleteSymbolicLink(&local_78);
      g_fMpsSymbolicLinkCreated = '\0';
    }
    if (g_fETWInited != '\0') {
      IoWMIRegistrationControl(g_pMpsDeviceObject,2);
      g_fETWInited = '\0';
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
    }
    if (g_fWPPInited != '\0') {
      WppCleanupKm();
      g_fWPPInited = '\0';
    }
  }
  DAT_140015634 = DAT_140015634 + -1;
LAB_140008fa4:
  if (g_pMpsDeviceObject != 0) {
    IoDeleteDevice();
    g_pMpsDeviceObject = 0;
  }
  if (bVar1) {
    AuditSuccessEvent(0x13aa);
  }
  if (g_Provider != 0) {
    local_88 = (undefined8 *)0x0;
    EtwWrite(g_Provider,&MPS_DRV_Stop_End,0,0);
    if (g_Provider != 0) {
      EtwUnregister();
      g_Provider = 0;
    }
  }
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_841d6cf1870f31f17b4997fb53d83523_Traceguids);
  }
  return;
}



===== WPP_SF_ @ 1400090c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1400090ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_38 = local_18;
  local_30 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140009150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordFeatureUsageReporting(undefined4 param_1)

{
  int iVar1;
  int *in_stack_00000028;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  ulonglong local_10;
  
  iVar1 = g_wil_details_featureUsageCached;
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if (*in_stack_00000028 != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar1 == 0) && (g_wil_details_featureUsageProvider != 0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (in_stack_00000028[1] != 0) {
    local_14 = (undefined2)in_stack_00000028[2];
    local_12 = (undefined2)in_stack_00000028[1];
    local_18 = param_1;
    RtlRecordFeatureUsage(&local_18,1);
  }
  return;
}



===== MpsDispatchCleanup @ 1400091f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsDispatchCleanup(undefined8 param_1,longlong param_2,undefined *param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  iVar2 = 0;
  bVar1 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_710c9ff648423249c486ff7465b97698_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  puVar3 = &local_38;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_140015798);
  __FlushUpcall(&local_38,puVar3,param_3);
  KeReleaseInStackQueuedSpinLock(&local_38);
  if (DAT_140015b50 != (code *)0x0) {
    iVar2 = (*DAT_140015b50)(param_1,param_2);
    if (iVar2 < 0) {
      bVar1 = true;
      iVar2 = 0;
    }
  }
  if (bVar1) {
    *(undefined8 *)(g_DriverObject + 0x68) = 0;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,iVar2);
  }
  return iVar2;
}



===== MpsDispatchCreate @ 140009330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 MpsDispatchCreate(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_710c9ff648423249c486ff7465b97698_Traceguids);
  }
  if (*(short *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x58) == 0) {
    if (DAT_140015ac0 != (code *)0x0) {
      uVar1 = (*DAT_140015ac0)(param_1,param_2);
    }
  }
  else {
    uVar1 = 0xc0000010;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_710c9ff648423249c486ff7465b97698_Traceguids,uVar1);
  }
  return uVar1;
}



===== MpsTracingEnableCallback @ 140009418 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MpsTracingEnableCallback
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  
  lVar1 = *param_1 + -0x4235d0b2d5e09122;
  if (lVar1 == 0) {
    lVar1 = param_1[1] + -0x6910afaa9fc8c1ad;
  }
  if ((lVar1 == 0) && (DAT_140015bc0 != (code *)0x0)) {
    (*DAT_140015bc0)(param_4);
  }
  return;
}



===== WppClassicProviderCallback @ 140009460 =====

void WppClassicProviderCallback
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  if ((byte)param_2 < 2) {
    uVar1 = 0;
    if ((byte)param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined4 *)(param_4 + 0x2c) = uVar2;
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
    MpsTracingEnableCallback(*(longlong **)(param_4 + 8),param_2,param_3,uVar2);
  }
  return;
}



===== WPP_SF_qq @ 1400094ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5)

{
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = &local_28;
  local_40 = 8;
  local_58 = &local_20;
  local_50 = 8;
  local_28 = param_5;
  local_20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_b61648fa526c3f7d2d3300ec4549db60_Traceguids,param_2);
  return;
}



===== DfwCleanup @ 140009530 =====

void DfwCleanup(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids;
    param_2 = 0x12;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  LOCK();
  DAT_14001568c = 1;
  UNLOCK();
  MpsStopTroubleshooting(1,param_2,param_3);
  if (DAT_140015688 != 1) {
    if (DAT_140015688 != 2) {
      if (DAT_140015688 != 3) goto LAB_1400095af;
      DAT_140015688 = 2;
    }
    DfwDeinitializeIpFlowManager();
    DAT_140015688 = DAT_140015688 + -1;
  }
  DfwDeinitializeFilterModule();
  DAT_140015688 = DAT_140015688 + -1;
LAB_1400095af:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  return;
}



===== DfwDispatchClose @ 1400095f0 =====

int DfwDispatchClose(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_3 = &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids;
    param_2 = 0xe;
    WPP_SF_(puVar2,0xe,&WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  iVar1 = MpsDeinitializeFwp(puVar2,param_2,param_3);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  return iVar1;
}



===== DfwInitialize @ 1400096d0 =====

int DfwInitialize(void)

{
  int iVar1;
  undefined *puVar2;
  ulonglong uVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
  }
  uVar3 = 0;
  puVar4 = (undefined *)0x48;
  memset(&DriverStatistics,0,0x48);
  iVar1 = DfwInitializeFilterModule();
  if (iVar1 < 0) {
    puVar2 = WPP_GLOBAL_Control;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400097ab;
    uVar3 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c);
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar3 = 0x15;
LAB_140009778:
      puVar4 = &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar3,
               &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
    }
  }
  else {
    DAT_140015688 = DAT_140015688 + 1;
    iVar1 = DfwInitializeIpFlowManager();
    if (-1 < iVar1) {
      DAT_140015688 = DAT_140015688 + 2;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return iVar1;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids);
      return iVar1;
    }
    puVar2 = WPP_GLOBAL_Control;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400097ab;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      uVar3 = 0x16;
      goto LAB_140009778;
    }
  }
  puVar2 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    uVar3 = 0x19;
    puVar4 = &WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids;
    WPP_SF_D(puVar2,0x19,&WPP_9eb39b4f92bf315ab2c570c063c33ffc_Traceguids,iVar1);
  }
LAB_1400097ab:
  DfwCleanup(puVar2,uVar3,puVar4);
  return iVar1;
}



===== NseQueryExportTable @ 14000981c =====

void NseQueryExportTable(undefined4 *param_1)

{
  *param_1 = 0x7d02;
  *(code **)(param_1 + 2) = DfwInitialize;
  *(code **)(param_1 + 6) = DfwCleanup;
  memset(param_1 + 8,0,0xe0);
  *(code **)(param_1 + 8) = DfwDispatchCreate;
  *(code **)(param_1 + 0xc) = DfwDispatchClose;
  *(code **)(param_1 + 0x48) = MpsStartTraceNotify;
  return;
}



===== MpsFlowAnalysisFlowDelete @ 140009890 =====

void MpsFlowAnalysisFlowDelete(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  if (*(longlong *)(param_3 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 0x18),0);
  }
  if (*(longlong *)(param_3 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 0x20),0);
  }
  DfwDeleteIpFlow(param_3);
  return;
}



===== MpsStartTraceNotify @ 1400098e0 =====

int MpsStartTraceNotify(uint param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    param_3 = &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids;
    param_2 = 0x3d;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  if ((param_1 & 0x1e0) == 0) {
    MpsStopTroubleshooting(0,param_2,param_3);
    iVar2 = DAT_1400156a0;
    LOCK();
    DAT_1400156a0 = 0;
    UNLOCK();
  }
  else {
    LOCK();
    iVar1 = DAT_1400156a0 + 1;
    UNLOCK();
    iVar2 = DAT_1400156a0 + 1;
    DAT_1400156a0 = iVar1;
    if (iVar2 == 1) {
      iVar2 = MpsStartTroubleshooting();
    }
  }
  return iVar2;
}



===== MpsStartTroubleshooting @ 140009958 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MpsStartTroubleshooting(void)

{
  longlong *plVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined1 auStackY_1b8 [32];
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  code *pcStack_170;
  code *local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  wchar_t *local_148;
  wchar_t *local_140;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_f8 [2];
  wchar_t *local_e8;
  wchar_t *local_e0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_78;
  undefined8 local_74;
  undefined8 uStack_6c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1b8;
  memset(&local_158,0,0x58);
  local_188 = 0;
  uStack_180 = 0;
  local_178 = 0;
  pcStack_170 = (code *)0x0;
  local_168 = (code *)0x0;
  uStack_160 = 0;
  memset(local_f8,0,200);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  }
  if (DAT_140015698 == 0) {
    puVar8 = (undefined8 *)0x0;
    puVar6 = (undefined8 *)0xa;
    iVar5 = FwpmEngineOpen0(0,10,0,&DAT_1400123f0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      puVar6 = (undefined8 *)0x31;
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,puVar8,iVar5,DAT_140015698);
    }
    if (iVar5 < 0) {
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          puVar6 = (undefined8 *)0x32;
LAB_140009bfc:
          puVar8 = (undefined8 *)&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)puVar6,
                   &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar5);
        }
LAB_140009c0b:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar6 = (undefined8 *)0x36;
          puVar8 = (undefined8 *)&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,iVar5);
        }
      }
LAB_140009c32:
      MpsStopTroubleshooting(0,puVar6,(undefined *)puVar8);
    }
    else {
      local_148 = L"Windows Firewall: troubleshooting callout";
      local_140 = L"";
      pcStack_170 = MpsTroubleshootingCallout;
      local_158 = 0x4bf30bb6c3dbed20;
      local_168 = MpsDummyFilterNotify;
      uStack_150 = 0x51e2e73968d82;
      uVar7 = 0;
      while( true ) {
        uVar3 = uStack_150;
        if (0x35 < (uint)uVar7) break;
        plVar1 = *(longlong **)((longlong)&PTR_PTR_1400151f0 + uVar7 * 0xc);
        puVar8 = &local_158;
        puVar6 = (undefined8 *)*plVar1;
        local_118 = *puVar6;
        uStack_110 = puVar6[1];
        uStack_150 = CONCAT17((char)plVar1[1],(undefined7)uStack_150);
        uVar4 = uStack_150;
        uStack_150._0_4_ = (undefined4)uVar3;
        uStack_150._4_4_ = SUB84(uVar4,4);
        puVar6 = &local_188;
        local_188 = local_158;
        uStack_180 = CONCAT44(uStack_150._4_4_,(undefined4)uStack_150);
        uStack_150 = uVar4;
        iVar5 = FwpiCalloutRegisterAndAddWithoutDevice0(DAT_140015698);
        if (iVar5 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140009c32;
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) goto LAB_140009c0b;
          puVar6 = (undefined8 *)0x33;
          goto LAB_140009bfc;
        }
        uVar7 = (ulonglong)((uint)uVar7 + 1);
      }
      local_e0 = L"";
      local_e8 = L"Windows Firewall: troubleshooting filter";
      local_74 = 0x4bf30bb6c3dbed20;
      uStack_6c = 0x51e2e73968d82;
      local_a8 = 0x41a5e6a9877519e1;
      uStack_a0 = 0x604a8e114f8cb481;
      local_78 = 0x6004;
      for (uVar7 = 0; (uint)uVar7 < 0x36; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
        plVar1 = *(longlong **)((longlong)&PTR_PTR_1400151f0 + uVar7 * 0xc);
        puVar8 = (undefined8 *)0x0;
        puVar2 = (undefined4 *)*plVar1;
        local_b8 = *puVar2;
        uStack_b4 = puVar2[1];
        uStack_b0 = puVar2[2];
        uStack_ac = puVar2[3];
        puVar6 = local_f8;
        uStack_6c = CONCAT17((char)plVar1[1],(undefined7)uStack_6c);
        iVar5 = FwpmFilterAdd0(DAT_140015698,puVar6,0,0);
        if (iVar5 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140009c32;
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) goto LAB_140009c0b;
          puVar6 = (undefined8 *)0x34;
          goto LAB_140009bfc;
        }
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
      }
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



===== MpsTroubleshootingCallout @ 140009ca0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MpsTroubleshootingCallout(ushort *param_1,longlong param_2,ulonglong param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  char **ppcVar8;
  int iVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  int *in_stack_00000038;
  undefined1 auStackY_288 [32];
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar16;
  undefined1 uVar15;
  uint local_158;
  undefined4 uStack_154;
  undefined8 local_150;
  ushort local_140;
  ushort local_13e;
  char local_13c;
  char local_13b;
  uint local_130;
  wchar_t *local_128;
  undefined8 *local_118;
  char *local_108 [4];
  char *local_e8;
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *local_c8;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  char *local_a8;
  char *local_a0;
  char *local_98;
  char *local_90;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  memset(&local_158,0,0x50);
  local_108[0] = (char *)0x0;
  uVar12 = 0;
  iVar9 = 4;
  memset(local_108 + 1,0,0xb0);
  MpsGetFwpAuthData((short *)param_1,param_2,param_3,(int *)&local_158);
  pwVar11 = L"Unknown App";
  if (local_128 != (wchar_t *)0x0) {
    pwVar11 = local_128;
  }
  if (local_118 != (undefined8 *)0x0) {
    param_3 = 0;
    uVar1 = *(uint *)*local_118;
    uVar5 = 0;
    if (uVar1 != 0) {
      if (uVar1 < 0x17) {
        uVar5 = uVar1;
        if (uVar1 == 0) goto LAB_140009d7b;
      }
      else {
        uVar5 = 0x17;
      }
      puVar6 = *(undefined8 **)((uint *)*local_118 + 2);
      ppcVar8 = local_108;
      uVar10 = (ulonglong)uVar5;
      param_3 = (ulonglong)uVar5;
      do {
        pcVar3 = (char *)*puVar6;
        puVar6 = puVar6 + 2;
        *ppcVar8 = pcVar3;
        ppcVar8 = ppcVar8 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
LAB_140009d7b:
    uVar1 = *(uint *)local_118[1];
    if (uVar1 != 0) {
      if (0x17 - uVar5 <= uVar1) {
        uVar1 = 0x17 - uVar5;
      }
      if ((uint)param_3 < uVar1) {
        ppcVar8 = local_108 + param_3;
        puVar6 = (undefined8 *)(param_3 * 0x10 + *(longlong *)((uint *)local_118[1] + 2));
        uVar10 = (ulonglong)(uVar1 - (uint)param_3);
        do {
          pcVar3 = (char *)*puVar6;
          puVar6 = puVar6 + 2;
          *ppcVar8 = pcVar3;
          ppcVar8 = ppcVar8 + 1;
          uVar10 = uVar10 - 1;
          param_3 = 0;
        } while (uVar10 != 0);
      }
    }
  }
  if (local_13b == '\x01') {
LAB_140009df3:
    local_13e = local_140 >> 8;
    local_140 = local_140 & 0xff;
  }
  else if ((local_13b != '\x06') && (local_13b != '\x11')) {
    if (local_13b == ':') goto LAB_140009df3;
    local_140 = 0;
    local_13e = 0;
  }
  uVar15 = (undefined1)local_140;
  uVar16 = (undefined1)local_13e;
  uVar13 = (undefined1)((uint)uStack_154 >> 0x18);
  uVar14 = (undefined1)(local_158 >> 0x18);
  bVar4 = (byte)local_130;
  if ((local_130 & 8) == 0) {
    iVar9 = *in_stack_00000038;
    uVar12 = (undefined1)*(undefined8 *)(in_stack_00000038 + 4);
    if (iVar9 == 7) goto LAB_140009e50;
    if (iVar9 != 0x1001) {
      if (iVar9 != 0x1002) goto LAB_140009e50;
      goto LAB_14000a105;
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x10);
    if ((iVar2 == 0) || (iVar2 == 1)) {
      iVar9 = 3;
    }
    else if (iVar2 == 2) {
      uVar12 = (undefined1)*(undefined8 *)(param_2 + 0x18);
      iVar9 = 2;
    }
    if (iVar9 == 0) {
LAB_140009e50:
      if (local_13c == '\x04') {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_13e,
                     (ulonglong)
                     (local_158 >> 0x18 | (local_158 & 0xff0000) >> 8 | (local_158 & 0xff00) << 8 |
                     local_158 << 0x18),(uint)*param_1,bVar4 & 1,pwVar11,local_108[0],local_108[1],
                     local_108[2],local_108[3],local_e8,local_e0,local_d8,local_d0,local_c8,local_c0
                     ,local_b8,local_b0,local_a8,local_a0,local_98,local_90,local_88,local_80,
                     local_78,local_70,local_68,local_60,local_58,local_13b,uVar13,uVar14,uVar16,
                     uVar15);
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,param_3,
                   (uint)*param_1,bVar4 & 1,pwVar11,local_108[0],local_108[1],local_108[2],
                   local_108[3],local_e8,local_e0,local_d8,local_d0,local_c8,local_c0,local_b8,
                   local_b0,local_a8,local_a0,local_98,local_90,local_88,local_80,local_78,local_70,
                   local_68,local_60,local_58,local_13b,local_150,CONCAT44(uStack_154,local_158),
                   uVar16,uVar15);
      }
      return 0;
    }
    if (iVar9 == 1) {
LAB_14000a105:
      if (local_13c != '\x04') {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
          return 0;
        }
        uVar7 = 0x2d;
        goto LAB_14000a31c;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
        return 0;
      }
      uVar7 = 0x2c;
      goto LAB_14000a194;
    }
    if (iVar9 != 2) {
      if (iVar9 == 3) {
        if (local_13c != '\x04') {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
            uVar12 = (undefined1)*(uint *)(param_2 + 0x14);
            WPP_SF_LLLLLSL_IPV6__IPV6_dd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_13e,
                       (ulonglong)*(uint *)(param_2 + 0x14),(uint)*param_1,
                       (char)*(undefined4 *)(param_2 + 0x10),uVar12,uVar12,bVar4 & 1,pwVar11,
                       local_13b,local_150,CONCAT44(uStack_154,local_158),uVar16,uVar15);
            return 0;
          }
          return 0;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
          uVar12 = (undefined1)*(undefined4 *)(param_2 + 0x14);
          WPP_SF_LLLLLSLDDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_140,
                             (ulonglong)local_13e,(uint)*param_1,
                             (char)*(undefined4 *)(param_2 + 0x10),uVar12,uVar12,bVar4 & 1,pwVar11,
                             local_13b,uVar13,uVar14,uVar16,uVar15);
          return 0;
        }
        return 0;
      }
      if (iVar9 != 4) {
        return 0;
      }
      goto LAB_140009e50;
    }
  }
  if (local_13c != '\x04') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar7 = 0x2b;
LAB_14000a31c:
    WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,WPP_GLOBAL_Control,(uint)*param_1,
               uVar12,bVar4 & 1,pwVar11,local_108[0],local_108[1],local_108[2],local_108[3],local_e8
               ,local_e0,local_d8,local_d0,local_c8,local_c0,local_b8,local_b0,local_a8,local_a0,
               local_98,local_90,local_88,local_80,local_78,local_70,local_68,local_60,local_58,
               local_13b,local_150,CONCAT44(uStack_154,local_158),uVar16,uVar15);
    return 0;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
    return 0;
  }
  uVar7 = 0x2a;
LAB_14000a194:
  WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,(ulonglong)local_13e,(uint)*param_1,
             uVar12,bVar4 & 1,pwVar11,local_108[0],local_108[1],local_108[2],local_108[3],local_e8,
             local_e0,local_d8,local_d0,local_c8,local_c0,local_b8,local_b0,local_a8,local_a0,
             local_98,local_90,local_88,local_80,local_78,local_70,local_68,local_60,local_58,
             local_13b,uVar13,uVar14,uVar16,uVar15);
  return 0;
}



===== WPP_SF_LLLLLSLDDdd @ 14000a620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LLLLLSLDDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       wchar_t *param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
                       undefined1 param_13,undefined1 param_14)

{
  longlong lVar1;
  undefined1 auStack_f8 [32];
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  longlong local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_f8;
  if (param_9 == (wchar_t *)0x0) {
    local_80 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != L'\0');
    local_80 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = &param_14;
  local_88 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_88 = L"NULL";
  }
  local_30 = 4;
  local_48 = &param_13;
  local_40 = 4;
  local_58 = &param_12;
  local_50 = 4;
  local_68 = &param_11;
  local_60 = 4;
  local_78 = &param_10;
  local_70 = 4;
  local_98 = &param_8;
  local_90 = 4;
  local_a8 = &param_7;
  local_a0 = 4;
  local_b8 = &param_6;
  local_b0 = 4;
  local_c8 = &param_5;
  local_c0 = 4;
  local_d8 = local_18;
  local_d0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,0x28);
  return;
}



===== WPP_SF_LLLLLSL_IPV6__IPV6_dd @ 14000a77c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LLLLLSL_IPV6__IPV6_dd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               wchar_t *param_9,undefined1 param_10,undefined8 param_11,undefined8 param_12,
               undefined1 param_13,undefined1 param_14)

{
  longlong lVar1;
  undefined1 auStack_f8 [32];
  undefined4 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  longlong local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_f8;
  if (param_9 == (wchar_t *)0x0) {
    local_80 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != L'\0');
    local_80 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = &param_14;
  local_88 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_88 = L"NULL";
  }
  local_30 = 4;
  local_48 = &param_13;
  local_40 = 4;
  local_50 = 0x10;
  local_58 = param_12;
  local_60 = 0x10;
  local_68 = param_11;
  local_78 = &param_10;
  local_70 = 4;
  local_98 = &param_8;
  local_90 = 4;
  local_a8 = &param_7;
  local_a0 = 4;
  local_b8 = &param_6;
  local_b0 = 4;
  local_c8 = &param_5;
  local_c0 = 4;
  local_d8 = local_18;
  local_d0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,0x29);
  return;
}



===== WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd @ 14000a914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,wchar_t *param_6,char *param_7,char *param_8,char *param_9,
               char *param_10,char *param_11,char *param_12,char *param_13,char *param_14,
               char *param_15,char *param_16,char *param_17,char *param_18,char *param_19,
               char *param_20,char *param_21,char *param_22,char *param_23,char *param_24,
               char *param_25,char *param_26,char *param_27,char *param_28,char *param_29,
               undefined1 param_30,undefined1 param_31,undefined1 param_32,undefined1 param_33,
               undefined1 param_34)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  ulonglong uVar13;
  char *pcVar14;
  ulonglong uVar15;
  char *pcVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStack_388 [32];
  undefined4 *local_368;
  undefined8 local_360;
  undefined1 *local_358;
  undefined8 local_350;
  wchar_t *local_348;
  longlong local_340;
  char *local_338;
  ulonglong local_330;
  char *local_328;
  ulonglong local_320;
  char *local_318;
  ulonglong local_310;
  char *local_308;
  ulonglong local_300;
  char *local_2f8;
  ulonglong local_2f0;
  char *local_2e8;
  ulonglong local_2e0;
  char *local_2d8;
  ulonglong local_2d0;
  char *local_2c8;
  ulonglong local_2c0;
  char *local_2b8;
  ulonglong local_2b0;
  char *local_2a8;
  ulonglong local_2a0;
  char *local_298;
  ulonglong local_290;
  char *local_288;
  ulonglong local_280;
  char *local_278;
  ulonglong local_270;
  char *local_268;
  ulonglong local_260;
  char *local_258;
  ulonglong local_250;
  char *local_248;
  ulonglong local_240;
  char *local_238;
  ulonglong local_230;
  char *local_228;
  ulonglong local_220;
  char *local_218;
  ulonglong local_210;
  char *local_208;
  ulonglong local_200;
  char *local_1f8;
  ulonglong local_1f0;
  char *local_1e8;
  ulonglong local_1e0;
  char *local_1d8;
  ulonglong local_1d0;
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined1 *local_188;
  undefined8 local_180;
  undefined8 local_178;
  code *local_168;
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  ulonglong local_128;
  char *local_120;
  char *local_118;
  char *local_110;
  char *local_108;
  char *local_100;
  char *local_f8;
  char *local_f0;
  char *local_e8;
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *local_c8;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  wchar_t *local_a8;
  char *local_a0;
  longlong local_98;
  char *local_90;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  undefined4 local_50 [2];
  ulonglong local_48;
  
  pcVar4 = param_23;
  pcVar8 = param_22;
  pcVar6 = param_21;
  pcVar14 = param_20;
  pcVar16 = param_19;
  pcVar10 = param_18;
  pcVar12 = param_17;
  local_48 = __security_cookie ^ (ulonglong)auStack_388;
  local_a8 = param_6;
  local_b0 = param_7;
  local_b8 = param_8;
  local_c0 = param_9;
  local_c8 = param_10;
  local_d0 = param_11;
  local_f8 = param_12;
  local_d8 = param_13;
  local_e0 = param_14;
  local_e8 = param_15;
  local_f0 = param_16;
  local_120 = param_24;
  local_100 = param_25;
  local_108 = param_26;
  local_110 = param_27;
  local_13c = 5;
  local_118 = param_28;
  local_a0 = param_29;
  local_58 = param_1;
  local_50[0] = param_4;
  if (param_29 == (char *)0x0) {
    local_160 = 5;
  }
  else {
    local_160 = RtlLengthSid(param_29);
  }
  if (local_a0 == (char *)0x0) {
    local_a0 = "NULL";
  }
  if (local_118 == (char *)0x0) {
    local_15c = 5;
  }
  else {
    local_15c = RtlLengthSid();
  }
  if (local_118 == (char *)0x0) {
    local_118 = "NULL";
  }
  if (local_110 == (char *)0x0) {
    local_158 = 5;
  }
  else {
    local_158 = RtlLengthSid();
  }
  if (local_110 == (char *)0x0) {
    local_110 = "NULL";
  }
  if (local_108 == (char *)0x0) {
    local_154 = 5;
  }
  else {
    local_154 = RtlLengthSid();
  }
  if (local_108 == (char *)0x0) {
    local_108 = "NULL";
  }
  if (local_100 == (char *)0x0) {
    local_150 = 5;
  }
  else {
    local_150 = RtlLengthSid();
  }
  if (local_100 == (char *)0x0) {
    local_100 = "NULL";
  }
  if (local_120 == (char *)0x0) {
    local_128 = CONCAT44(local_128._4_4_,5);
  }
  else {
    uVar1 = RtlLengthSid();
    local_128 = CONCAT44(local_128._4_4_,uVar1);
  }
  if (local_120 == (char *)0x0) {
    local_120 = "NULL";
  }
  if (pcVar4 == (char *)0x0) {
    local_168 = (code *)CONCAT44(local_168._4_4_,5);
    pcVar4 = "NULL";
  }
  else {
    uVar1 = RtlLengthSid(pcVar4);
    local_168 = (code *)CONCAT44(local_168._4_4_,uVar1);
  }
  local_90 = pcVar4;
  if (pcVar8 == (char *)0x0) {
    uVar5 = 5;
    pcVar8 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar8);
    uVar5 = (ulonglong)uVar2;
  }
  local_88 = pcVar8;
  if (pcVar6 == (char *)0x0) {
    uVar9 = 5;
    pcVar6 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar6);
    uVar9 = (ulonglong)uVar2;
  }
  local_80 = pcVar6;
  if (pcVar14 == (char *)0x0) {
    uVar7 = 5;
    pcVar14 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar14);
    uVar7 = (ulonglong)uVar2;
  }
  local_78 = pcVar14;
  if (pcVar16 == (char *)0x0) {
    uVar15 = 5;
    pcVar16 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar16);
    uVar15 = (ulonglong)uVar2;
  }
  local_70 = pcVar16;
  if (pcVar10 == (char *)0x0) {
    uVar17 = 5;
    pcVar10 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar10);
    uVar17 = (ulonglong)uVar2;
  }
  local_68 = pcVar10;
  if (pcVar12 == (char *)0x0) {
    uVar11 = 5;
    pcVar12 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar12);
    uVar11 = (ulonglong)uVar2;
  }
  local_60 = pcVar12;
  if (local_f0 == (char *)0x0) {
    uVar13 = 5;
  }
  else {
    uVar2 = RtlLengthSid();
    uVar13 = (ulonglong)uVar2;
  }
  if (local_f0 == (char *)0x0) {
    local_f0 = "NULL";
  }
  if (local_e8 == (char *)0x0) {
    local_148 = 5;
  }
  else {
    local_148 = RtlLengthSid();
  }
  if (local_e8 == (char *)0x0) {
    local_e8 = "NULL";
  }
  if (local_e0 == (char *)0x0) {
    local_144 = 5;
  }
  else {
    local_144 = RtlLengthSid();
  }
  if (local_e0 == (char *)0x0) {
    local_e0 = "NULL";
  }
  if (local_d8 == (char *)0x0) {
    local_140 = 5;
  }
  else {
    local_140 = RtlLengthSid();
  }
  if (local_d8 == (char *)0x0) {
    local_d8 = "NULL";
  }
  if (local_f8 == (char *)0x0) {
    local_14c = 5;
  }
  else {
    local_14c = RtlLengthSid();
  }
  if (local_f8 == (char *)0x0) {
    local_f8 = "NULL";
  }
  if (local_d0 == (char *)0x0) {
    local_138 = 5;
  }
  else {
    local_138 = RtlLengthSid();
  }
  if (local_d0 == (char *)0x0) {
    local_d0 = "NULL";
  }
  if (local_c8 == (char *)0x0) {
    local_134 = 5;
  }
  else {
    local_134 = RtlLengthSid();
  }
  if (local_c8 == (char *)0x0) {
    local_c8 = "NULL";
  }
  if (local_c0 == (char *)0x0) {
    local_130 = 5;
  }
  else {
    local_130 = RtlLengthSid();
  }
  local_12c = 5;
  if (local_c0 == (char *)0x0) {
    local_c0 = "NULL";
  }
  if (local_b8 != (char *)0x0) {
    local_12c = RtlLengthSid();
  }
  if (local_b8 == (char *)0x0) {
    local_b8 = "NULL";
  }
  bVar18 = local_b0 == (char *)0x0;
  if (!bVar18) {
    local_13c = RtlLengthSid(local_b0);
    bVar18 = local_b0 == (char *)0x0;
  }
  if (bVar18) {
    local_b0 = "NULL";
  }
  if (local_a8 == (wchar_t *)0x0) {
    local_98 = 10;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_a8[lVar3] != L'\0');
    local_98 = lVar3 * 2 + 2;
  }
  local_230 = (ulonglong)local_168 & 0xffffffff;
  local_220 = local_128 & 0xffffffff;
  local_1d0 = (ulonglong)local_160;
  local_1e0 = (ulonglong)local_15c;
  local_1f0 = (ulonglong)local_158;
  local_200 = (ulonglong)local_154;
  local_210 = (ulonglong)local_150;
  local_348 = local_a8;
  if (local_a8 == (wchar_t *)0x0) {
    local_348 = L"NULL";
  }
  local_178 = 0;
  local_180 = 4;
  local_168 = pfnWppTraceMessage;
  local_188 = &param_34;
  local_198 = &param_33;
  local_190 = 4;
  local_1a8 = &param_32;
  local_1a0 = 4;
  local_1b8 = &param_31;
  local_1b0 = 4;
  local_1c8 = &param_30;
  local_1c0 = 4;
  local_1d8 = local_a0;
  local_1e8 = local_118;
  local_2b0 = (ulonglong)local_148;
  local_1f8 = local_110;
  local_208 = local_108;
  local_218 = local_100;
  local_228 = local_120;
  local_238 = local_90;
  local_248 = local_88;
  local_258 = local_80;
  local_268 = local_78;
  local_278 = local_70;
  local_288 = local_68;
  local_298 = local_60;
  local_2a8 = local_f0;
  local_2c0 = (ulonglong)local_144;
  local_2b8 = local_e8;
  local_2d0 = (ulonglong)local_140;
  local_2c8 = local_e0;
  local_2e0 = (ulonglong)local_14c;
  local_2d8 = local_d8;
  local_2f0 = (ulonglong)local_138;
  local_2e8 = local_f8;
  local_300 = (ulonglong)local_134;
  local_2f8 = local_d0;
  local_310 = (ulonglong)local_130;
  local_308 = local_c8;
  local_320 = (ulonglong)local_12c;
  local_318 = local_c0;
  local_328 = local_b8;
  local_330 = (ulonglong)local_13c;
  local_340 = local_98;
  local_358 = &param_5;
  local_350 = 4;
  local_368 = local_50;
  local_360 = 4;
  local_338 = local_b0;
  local_2a0 = uVar13;
  local_290 = uVar11;
  local_280 = uVar17;
  local_270 = uVar15;
  local_260 = uVar7;
  local_250 = uVar9;
  local_240 = uVar5;
  local_128 = uVar13;
  local_a8 = local_348;
  (*pfnWppTraceMessage)(local_58,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,0x2e);
  return;
}



===== WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd @ 14000b2c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,wchar_t *param_6,char *param_7,char *param_8,char *param_9,
               char *param_10,char *param_11,char *param_12,char *param_13,char *param_14,
               char *param_15,char *param_16,char *param_17,char *param_18,char *param_19,
               char *param_20,char *param_21,char *param_22,char *param_23,char *param_24,
               char *param_25,char *param_26,char *param_27,char *param_28,char *param_29,
               undefined1 param_30,undefined8 param_31,undefined8 param_32,undefined1 param_33,
               undefined1 param_34)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  ulonglong uVar13;
  char *pcVar14;
  ulonglong uVar15;
  char *pcVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStack_398 [32];
  undefined4 *local_378;
  undefined8 local_370;
  undefined1 *local_368;
  undefined8 local_360;
  wchar_t *local_358;
  longlong local_350;
  char *local_348;
  ulonglong local_340;
  char *local_338;
  ulonglong local_330;
  char *local_328;
  ulonglong local_320;
  char *local_318;
  ulonglong local_310;
  char *local_308;
  ulonglong local_300;
  char *local_2f8;
  ulonglong local_2f0;
  char *local_2e8;
  ulonglong local_2e0;
  char *local_2d8;
  ulonglong local_2d0;
  char *local_2c8;
  ulonglong local_2c0;
  char *local_2b8;
  ulonglong local_2b0;
  char *local_2a8;
  ulonglong local_2a0;
  char *local_298;
  ulonglong local_290;
  char *local_288;
  ulonglong local_280;
  char *local_278;
  ulonglong local_270;
  char *local_268;
  ulonglong local_260;
  char *local_258;
  ulonglong local_250;
  char *local_248;
  ulonglong local_240;
  char *local_238;
  ulonglong local_230;
  char *local_228;
  ulonglong local_220;
  char *local_218;
  ulonglong local_210;
  char *local_208;
  ulonglong local_200;
  char *local_1f8;
  ulonglong local_1f0;
  char *local_1e8;
  ulonglong local_1e0;
  undefined1 *local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined8 local_188;
  code *local_178;
  uint local_170;
  uint local_16c;
  uint local_168;
  uint local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  ulonglong local_138;
  wchar_t *local_130;
  char *local_128;
  char *local_120;
  char *local_118;
  char *local_110;
  char *local_108;
  char *local_100;
  char *local_f8;
  char *local_f0;
  char *local_e8;
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *local_c8;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  longlong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  char *local_90;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  undefined4 local_50 [2];
  ulonglong local_48;
  
  pcVar4 = param_23;
  pcVar8 = param_22;
  pcVar6 = param_21;
  pcVar14 = param_20;
  pcVar16 = param_19;
  pcVar10 = param_18;
  pcVar12 = param_17;
  local_48 = __security_cookie ^ (ulonglong)auStack_398;
  local_130 = param_6;
  local_b8 = param_7;
  local_c0 = param_8;
  local_c8 = param_9;
  local_d0 = param_10;
  local_d8 = param_11;
  local_e0 = param_12;
  local_e8 = param_13;
  local_f0 = param_14;
  local_f8 = param_15;
  local_100 = param_16;
  local_108 = param_24;
  local_110 = param_25;
  local_118 = param_26;
  local_120 = param_27;
  local_98 = param_31;
  local_a0 = param_32;
  local_14c = 5;
  local_128 = param_28;
  local_b0 = param_29;
  local_58 = param_1;
  local_50[0] = param_4;
  if (param_29 == (char *)0x0) {
    local_170 = 5;
  }
  else {
    local_170 = RtlLengthSid(param_29);
  }
  if (local_b0 == (char *)0x0) {
    local_b0 = "NULL";
  }
  if (local_128 == (char *)0x0) {
    local_16c = 5;
  }
  else {
    local_16c = RtlLengthSid();
  }
  if (local_128 == (char *)0x0) {
    local_128 = "NULL";
  }
  if (local_120 == (char *)0x0) {
    local_168 = 5;
  }
  else {
    local_168 = RtlLengthSid();
  }
  if (local_120 == (char *)0x0) {
    local_120 = "NULL";
  }
  if (local_118 == (char *)0x0) {
    local_164 = 5;
  }
  else {
    local_164 = RtlLengthSid();
  }
  if (local_118 == (char *)0x0) {
    local_118 = "NULL";
  }
  if (local_110 == (char *)0x0) {
    local_160 = 5;
  }
  else {
    local_160 = RtlLengthSid();
  }
  if (local_110 == (char *)0x0) {
    local_110 = "NULL";
  }
  if (local_108 == (char *)0x0) {
    local_138 = CONCAT44(local_138._4_4_,5);
  }
  else {
    uVar1 = RtlLengthSid();
    local_138 = CONCAT44(local_138._4_4_,uVar1);
  }
  if (local_108 == (char *)0x0) {
    local_108 = "NULL";
  }
  if (pcVar4 == (char *)0x0) {
    local_178 = (code *)CONCAT44(local_178._4_4_,5);
    pcVar4 = "NULL";
  }
  else {
    uVar1 = RtlLengthSid(pcVar4);
    local_178 = (code *)CONCAT44(local_178._4_4_,uVar1);
  }
  local_90 = pcVar4;
  if (pcVar8 == (char *)0x0) {
    uVar5 = 5;
    pcVar8 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar8);
    uVar5 = (ulonglong)uVar2;
  }
  local_88 = pcVar8;
  if (pcVar6 == (char *)0x0) {
    uVar9 = 5;
    pcVar6 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar6);
    uVar9 = (ulonglong)uVar2;
  }
  local_80 = pcVar6;
  if (pcVar14 == (char *)0x0) {
    uVar7 = 5;
    pcVar14 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar14);
    uVar7 = (ulonglong)uVar2;
  }
  local_78 = pcVar14;
  if (pcVar16 == (char *)0x0) {
    uVar15 = 5;
    pcVar16 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar16);
    uVar15 = (ulonglong)uVar2;
  }
  local_70 = pcVar16;
  if (pcVar10 == (char *)0x0) {
    uVar17 = 5;
    pcVar10 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar10);
    uVar17 = (ulonglong)uVar2;
  }
  local_68 = pcVar10;
  if (pcVar12 == (char *)0x0) {
    uVar11 = 5;
    pcVar12 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar12);
    uVar11 = (ulonglong)uVar2;
  }
  local_60 = pcVar12;
  if (local_100 == (char *)0x0) {
    uVar13 = 5;
  }
  else {
    uVar2 = RtlLengthSid();
    uVar13 = (ulonglong)uVar2;
  }
  if (local_100 == (char *)0x0) {
    local_100 = "NULL";
  }
  if (local_f8 == (char *)0x0) {
    local_158 = 5;
  }
  else {
    local_158 = RtlLengthSid();
  }
  if (local_f8 == (char *)0x0) {
    local_f8 = "NULL";
  }
  if (local_f0 == (char *)0x0) {
    local_154 = 5;
  }
  else {
    local_154 = RtlLengthSid();
  }
  if (local_f0 == (char *)0x0) {
    local_f0 = "NULL";
  }
  if (local_e8 == (char *)0x0) {
    local_150 = 5;
  }
  else {
    local_150 = RtlLengthSid();
  }
  if (local_e8 == (char *)0x0) {
    local_e8 = "NULL";
  }
  if (local_e0 == (char *)0x0) {
    local_15c = 5;
  }
  else {
    local_15c = RtlLengthSid();
  }
  if (local_e0 == (char *)0x0) {
    local_e0 = "NULL";
  }
  if (local_d8 == (char *)0x0) {
    local_148 = 5;
  }
  else {
    local_148 = RtlLengthSid();
  }
  if (local_d8 == (char *)0x0) {
    local_d8 = "NULL";
  }
  if (local_d0 == (char *)0x0) {
    local_144 = 5;
  }
  else {
    local_144 = RtlLengthSid();
  }
  if (local_d0 == (char *)0x0) {
    local_d0 = "NULL";
  }
  if (local_c8 == (char *)0x0) {
    local_140 = 5;
  }
  else {
    local_140 = RtlLengthSid();
  }
  local_13c = 5;
  if (local_c8 == (char *)0x0) {
    local_c8 = "NULL";
  }
  if (local_c0 != (char *)0x0) {
    local_13c = RtlLengthSid();
  }
  if (local_c0 == (char *)0x0) {
    local_c0 = "NULL";
  }
  bVar18 = local_b8 == (char *)0x0;
  if (!bVar18) {
    local_14c = RtlLengthSid(local_b8);
    bVar18 = local_b8 == (char *)0x0;
  }
  if (bVar18) {
    local_b8 = "NULL";
  }
  if (local_130 == (wchar_t *)0x0) {
    local_a8 = 10;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_130[lVar3] != L'\0');
    local_a8 = lVar3 * 2 + 2;
  }
  local_240 = (ulonglong)local_178 & 0xffffffff;
  local_230 = local_138 & 0xffffffff;
  local_1e0 = (ulonglong)local_170;
  local_1f0 = (ulonglong)local_16c;
  local_200 = (ulonglong)local_168;
  local_210 = (ulonglong)local_164;
  local_220 = (ulonglong)local_160;
  local_358 = local_130;
  if (local_130 == (wchar_t *)0x0) {
    local_358 = L"NULL";
  }
  local_188 = 0;
  local_190 = 4;
  local_178 = pfnWppTraceMessage;
  local_198 = &param_34;
  local_1a8 = &param_33;
  local_1a0 = 4;
  local_1b0 = 0x10;
  local_1b8 = local_a0;
  local_1c0 = 0x10;
  local_1c8 = local_98;
  local_1d8 = &param_30;
  local_1d0 = 4;
  local_1e8 = local_b0;
  local_1f8 = local_128;
  local_2c0 = (ulonglong)local_158;
  local_208 = local_120;
  local_218 = local_118;
  local_228 = local_110;
  local_238 = local_108;
  local_248 = local_90;
  local_258 = local_88;
  local_268 = local_80;
  local_278 = local_78;
  local_288 = local_70;
  local_298 = local_68;
  local_2a8 = local_60;
  local_2b8 = local_100;
  local_2d0 = (ulonglong)local_154;
  local_2c8 = local_f8;
  local_2e0 = (ulonglong)local_150;
  local_2d8 = local_f0;
  local_2f0 = (ulonglong)local_15c;
  local_2e8 = local_e8;
  local_300 = (ulonglong)local_148;
  local_2f8 = local_e0;
  local_310 = (ulonglong)local_144;
  local_308 = local_d8;
  local_320 = (ulonglong)local_140;
  local_318 = local_d0;
  local_330 = (ulonglong)local_13c;
  local_328 = local_c8;
  local_338 = local_c0;
  local_340 = (ulonglong)local_14c;
  local_350 = local_a8;
  local_368 = &param_5;
  local_360 = 4;
  local_378 = local_50;
  local_370 = 4;
  local_348 = local_b8;
  local_2b0 = uVar13;
  local_2a0 = uVar11;
  local_290 = uVar17;
  local_280 = uVar15;
  local_270 = uVar7;
  local_260 = uVar9;
  local_250 = uVar5;
  local_138 = uVar13;
  local_130 = local_358;
  (*pfnWppTraceMessage)(local_58,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,0x2f);
  return;
}



===== WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd @ 14000bc98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_LDDdd
               (undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,wchar_t *param_7,char *param_8,char *param_9,
               char *param_10,char *param_11,char *param_12,char *param_13,char *param_14,
               char *param_15,char *param_16,char *param_17,char *param_18,char *param_19,
               char *param_20,char *param_21,char *param_22,char *param_23,char *param_24,
               char *param_25,char *param_26,char *param_27,char *param_28,char *param_29,
               char *param_30,undefined1 param_31,undefined1 param_32,undefined1 param_33,
               undefined1 param_34,undefined1 param_35)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  ulonglong uVar13;
  char *pcVar14;
  ulonglong uVar15;
  char *pcVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStack_398 [32];
  undefined4 *local_378;
  undefined8 local_370;
  undefined1 *local_368;
  undefined8 local_360;
  undefined1 *local_358;
  undefined8 local_350;
  wchar_t *local_348;
  longlong local_340;
  char *local_338;
  ulonglong local_330;
  char *local_328;
  ulonglong local_320;
  char *local_318;
  ulonglong local_310;
  char *local_308;
  ulonglong local_300;
  char *local_2f8;
  ulonglong local_2f0;
  char *local_2e8;
  ulonglong local_2e0;
  char *local_2d8;
  ulonglong local_2d0;
  char *local_2c8;
  ulonglong local_2c0;
  char *local_2b8;
  ulonglong local_2b0;
  char *local_2a8;
  ulonglong local_2a0;
  char *local_298;
  ulonglong local_290;
  char *local_288;
  ulonglong local_280;
  char *local_278;
  ulonglong local_270;
  char *local_268;
  ulonglong local_260;
  char *local_258;
  ulonglong local_250;
  char *local_248;
  ulonglong local_240;
  char *local_238;
  ulonglong local_230;
  char *local_228;
  ulonglong local_220;
  char *local_218;
  ulonglong local_210;
  char *local_208;
  ulonglong local_200;
  char *local_1f8;
  ulonglong local_1f0;
  char *local_1e8;
  ulonglong local_1e0;
  char *local_1d8;
  ulonglong local_1d0;
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined1 *local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined2 local_168;
  code *local_160;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  ulonglong local_120;
  char *local_118;
  char *local_110;
  char *local_108;
  char *local_100;
  char *local_f8;
  char *local_f0;
  char *local_e8;
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *local_c8;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  char *local_a8;
  wchar_t *local_a0;
  char *local_98;
  longlong local_90;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  undefined8 local_50;
  undefined4 local_48 [2];
  ulonglong local_40;
  
  pcVar4 = param_24;
  pcVar8 = param_23;
  pcVar6 = param_22;
  pcVar14 = param_21;
  pcVar16 = param_20;
  pcVar10 = param_19;
  pcVar12 = param_18;
  local_40 = __security_cookie ^ (ulonglong)auStack_398;
  local_a0 = param_7;
  local_a8 = param_8;
  local_b0 = param_9;
  local_b8 = param_10;
  local_c0 = param_11;
  local_c8 = param_12;
  local_f0 = param_13;
  local_d0 = param_14;
  local_d8 = param_15;
  local_e0 = param_16;
  local_e8 = param_17;
  local_118 = param_25;
  local_f8 = param_26;
  local_100 = param_27;
  local_108 = param_28;
  local_144 = 5;
  local_110 = param_29;
  local_98 = param_30;
  local_168 = param_2;
  local_50 = param_1;
  local_48[0] = param_4;
  if (param_30 == (char *)0x0) {
    local_158 = 5;
  }
  else {
    local_158 = RtlLengthSid(param_30);
  }
  if (local_98 == (char *)0x0) {
    local_98 = "NULL";
  }
  if (local_110 == (char *)0x0) {
    local_154 = 5;
  }
  else {
    local_154 = RtlLengthSid();
  }
  if (local_110 == (char *)0x0) {
    local_110 = "NULL";
  }
  if (local_108 == (char *)0x0) {
    local_150 = 5;
  }
  else {
    local_150 = RtlLengthSid();
  }
  if (local_108 == (char *)0x0) {
    local_108 = "NULL";
  }
  if (local_100 == (char *)0x0) {
    local_14c = 5;
  }
  else {
    local_14c = RtlLengthSid();
  }
  if (local_100 == (char *)0x0) {
    local_100 = "NULL";
  }
  if (local_f8 == (char *)0x0) {
    local_148 = 5;
  }
  else {
    local_148 = RtlLengthSid();
  }
  if (local_f8 == (char *)0x0) {
    local_f8 = "NULL";
  }
  if (local_118 == (char *)0x0) {
    local_120 = CONCAT44(local_120._4_4_,5);
  }
  else {
    uVar1 = RtlLengthSid();
    local_120 = CONCAT44(local_120._4_4_,uVar1);
  }
  if (local_118 == (char *)0x0) {
    local_118 = "NULL";
  }
  if (pcVar4 == (char *)0x0) {
    local_160 = (code *)CONCAT44(local_160._4_4_,5);
    pcVar4 = "NULL";
  }
  else {
    uVar1 = RtlLengthSid(pcVar4);
    local_160 = (code *)CONCAT44(local_160._4_4_,uVar1);
  }
  local_88 = pcVar4;
  if (pcVar8 == (char *)0x0) {
    uVar5 = 5;
    pcVar8 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar8);
    uVar5 = (ulonglong)uVar2;
  }
  local_80 = pcVar8;
  if (pcVar6 == (char *)0x0) {
    uVar9 = 5;
    pcVar6 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar6);
    uVar9 = (ulonglong)uVar2;
  }
  local_78 = pcVar6;
  if (pcVar14 == (char *)0x0) {
    uVar7 = 5;
    pcVar14 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar14);
    uVar7 = (ulonglong)uVar2;
  }
  local_70 = pcVar14;
  if (pcVar16 == (char *)0x0) {
    uVar15 = 5;
    pcVar16 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar16);
    uVar15 = (ulonglong)uVar2;
  }
  local_68 = pcVar16;
  if (pcVar10 == (char *)0x0) {
    uVar17 = 5;
    pcVar10 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar10);
    uVar17 = (ulonglong)uVar2;
  }
  local_60 = pcVar10;
  if (pcVar12 == (char *)0x0) {
    uVar11 = 5;
    pcVar12 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar12);
    uVar11 = (ulonglong)uVar2;
  }
  local_58 = pcVar12;
  if (local_e8 == (char *)0x0) {
    uVar13 = 5;
  }
  else {
    uVar2 = RtlLengthSid();
    uVar13 = (ulonglong)uVar2;
  }
  if (local_e8 == (char *)0x0) {
    local_e8 = "NULL";
  }
  if (local_e0 == (char *)0x0) {
    local_140 = 5;
  }
  else {
    local_140 = RtlLengthSid();
  }
  if (local_e0 == (char *)0x0) {
    local_e0 = "NULL";
  }
  if (local_d8 == (char *)0x0) {
    local_13c = 5;
  }
  else {
    local_13c = RtlLengthSid();
  }
  if (local_d8 == (char *)0x0) {
    local_d8 = "NULL";
  }
  if (local_d0 == (char *)0x0) {
    local_138 = 5;
  }
  else {
    local_138 = RtlLengthSid();
  }
  if (local_d0 == (char *)0x0) {
    local_d0 = "NULL";
  }
  if (local_f0 == (char *)0x0) {
    local_134 = 5;
  }
  else {
    local_134 = RtlLengthSid();
  }
  if (local_f0 == (char *)0x0) {
    local_f0 = "NULL";
  }
  if (local_c8 == (char *)0x0) {
    local_130 = 5;
  }
  else {
    local_130 = RtlLengthSid();
  }
  if (local_c8 == (char *)0x0) {
    local_c8 = "NULL";
  }
  if (local_c0 == (char *)0x0) {
    local_12c = 5;
  }
  else {
    local_12c = RtlLengthSid();
  }
  if (local_c0 == (char *)0x0) {
    local_c0 = "NULL";
  }
  if (local_b8 == (char *)0x0) {
    local_128 = 5;
  }
  else {
    local_128 = RtlLengthSid();
  }
  local_124 = 5;
  if (local_b8 == (char *)0x0) {
    local_b8 = "NULL";
  }
  if (local_b0 != (char *)0x0) {
    local_124 = RtlLengthSid();
  }
  if (local_b0 == (char *)0x0) {
    local_b0 = "NULL";
  }
  bVar18 = local_a8 == (char *)0x0;
  if (!bVar18) {
    local_144 = RtlLengthSid(local_a8);
    bVar18 = local_a8 == (char *)0x0;
  }
  if (bVar18) {
    local_a8 = "NULL";
  }
  if (local_a0 == (wchar_t *)0x0) {
    local_90 = 10;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_a0[lVar3] != L'\0');
    local_90 = lVar3 * 2 + 2;
  }
  local_230 = (ulonglong)local_160 & 0xffffffff;
  local_220 = local_120 & 0xffffffff;
  local_1d0 = (ulonglong)local_158;
  local_1e0 = (ulonglong)local_154;
  local_1f0 = (ulonglong)local_150;
  local_200 = (ulonglong)local_14c;
  local_210 = (ulonglong)local_148;
  local_348 = local_a0;
  if (local_a0 == (wchar_t *)0x0) {
    local_348 = L"NULL";
  }
  local_178 = 0;
  local_180 = 4;
  local_160 = pfnWppTraceMessage;
  local_188 = &param_35;
  local_198 = &param_34;
  local_190 = 4;
  local_1a8 = &param_33;
  local_1a0 = 4;
  local_1b8 = &param_32;
  local_1b0 = 4;
  local_1c8 = &param_31;
  local_1c0 = 4;
  local_1d8 = local_98;
  local_1e8 = local_110;
  local_2b0 = (ulonglong)local_140;
  local_1f8 = local_108;
  local_208 = local_100;
  local_218 = local_f8;
  local_228 = local_118;
  local_238 = local_88;
  local_248 = local_80;
  local_258 = local_78;
  local_268 = local_70;
  local_278 = local_68;
  local_288 = local_60;
  local_298 = local_58;
  local_2a8 = local_e8;
  local_2c0 = (ulonglong)local_13c;
  local_2b8 = local_e0;
  local_2c8 = local_d8;
  local_2d0 = (ulonglong)local_138;
  local_2e0 = (ulonglong)local_134;
  local_2d8 = local_d0;
  local_2f0 = (ulonglong)local_130;
  local_2e8 = local_f0;
  local_300 = (ulonglong)local_12c;
  local_2f8 = local_c8;
  local_310 = (ulonglong)local_128;
  local_308 = local_c0;
  local_320 = (ulonglong)local_124;
  local_318 = local_b8;
  local_330 = (ulonglong)local_144;
  local_328 = local_b0;
  local_340 = local_90;
  local_358 = &param_6;
  local_350 = 4;
  local_368 = &param_5;
  local_360 = 8;
  local_370 = 4;
  local_378 = local_48;
  local_338 = local_a8;
  local_2a0 = uVar13;
  local_290 = uVar11;
  local_280 = uVar17;
  local_270 = uVar15;
  local_260 = uVar7;
  local_250 = uVar9;
  local_240 = uVar5;
  local_120 = uVar13;
  local_a0 = local_348;
  (*pfnWppTraceMessage)(local_50,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,local_168);
  return;
}



===== WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd @ 14000c674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_LiLS_sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid__sid_L_IPV6__IPV6_dd
               (undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,wchar_t *param_7,char *param_8,char *param_9,
               char *param_10,char *param_11,char *param_12,char *param_13,char *param_14,
               char *param_15,char *param_16,char *param_17,char *param_18,char *param_19,
               char *param_20,char *param_21,char *param_22,char *param_23,char *param_24,
               char *param_25,char *param_26,char *param_27,char *param_28,char *param_29,
               char *param_30,undefined1 param_31,undefined8 param_32,undefined8 param_33,
               undefined1 param_34,undefined1 param_35)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  ulonglong uVar13;
  char *pcVar14;
  ulonglong uVar15;
  char *pcVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStack_3a8 [32];
  undefined4 *local_388;
  undefined8 local_380;
  undefined1 *local_378;
  undefined8 local_370;
  undefined1 *local_368;
  undefined8 local_360;
  wchar_t *local_358;
  longlong local_350;
  char *local_348;
  ulonglong local_340;
  char *local_338;
  ulonglong local_330;
  char *local_328;
  ulonglong local_320;
  char *local_318;
  ulonglong local_310;
  char *local_308;
  ulonglong local_300;
  char *local_2f8;
  ulonglong local_2f0;
  char *local_2e8;
  ulonglong local_2e0;
  char *local_2d8;
  ulonglong local_2d0;
  char *local_2c8;
  ulonglong local_2c0;
  char *local_2b8;
  ulonglong local_2b0;
  char *local_2a8;
  ulonglong local_2a0;
  char *local_298;
  ulonglong local_290;
  char *local_288;
  ulonglong local_280;
  char *local_278;
  ulonglong local_270;
  char *local_268;
  ulonglong local_260;
  char *local_258;
  ulonglong local_250;
  char *local_248;
  ulonglong local_240;
  char *local_238;
  ulonglong local_230;
  char *local_228;
  ulonglong local_220;
  char *local_218;
  ulonglong local_210;
  char *local_208;
  ulonglong local_200;
  char *local_1f8;
  ulonglong local_1f0;
  char *local_1e8;
  ulonglong local_1e0;
  undefined1 *local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined2 local_178;
  code *local_170;
  uint local_168;
  uint local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  ulonglong local_130;
  wchar_t *local_128;
  char *local_120;
  char *local_118;
  char *local_110;
  char *local_108;
  char *local_100;
  char *local_f8;
  char *local_f0;
  char *local_e8;
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *local_c8;
  char *local_c0;
  char *local_b8;
  char *local_b0;
  char *local_a8;
  longlong local_a0;
  undefined8 local_98;
  undefined8 local_90;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  undefined8 local_50;
  undefined4 local_48 [2];
  ulonglong local_40;
  
  pcVar4 = param_24;
  pcVar8 = param_23;
  pcVar6 = param_22;
  pcVar14 = param_21;
  pcVar16 = param_20;
  pcVar10 = param_19;
  pcVar12 = param_18;
  local_40 = __security_cookie ^ (ulonglong)auStack_3a8;
  local_128 = param_7;
  local_b0 = param_8;
  local_b8 = param_9;
  local_c0 = param_10;
  local_c8 = param_11;
  local_d0 = param_12;
  local_d8 = param_13;
  local_e0 = param_14;
  local_e8 = param_15;
  local_f0 = param_16;
  local_f8 = param_17;
  local_100 = param_25;
  local_108 = param_26;
  local_110 = param_27;
  local_118 = param_28;
  local_90 = param_32;
  local_98 = param_33;
  local_154 = 5;
  local_120 = param_29;
  local_a8 = param_30;
  local_178 = param_2;
  local_50 = param_1;
  local_48[0] = param_4;
  if (param_30 == (char *)0x0) {
    local_168 = 5;
  }
  else {
    local_168 = RtlLengthSid(param_30);
  }
  if (local_a8 == (char *)0x0) {
    local_a8 = "NULL";
  }
  if (local_120 == (char *)0x0) {
    local_164 = 5;
  }
  else {
    local_164 = RtlLengthSid();
  }
  if (local_120 == (char *)0x0) {
    local_120 = "NULL";
  }
  if (local_118 == (char *)0x0) {
    local_160 = 5;
  }
  else {
    local_160 = RtlLengthSid();
  }
  if (local_118 == (char *)0x0) {
    local_118 = "NULL";
  }
  if (local_110 == (char *)0x0) {
    local_15c = 5;
  }
  else {
    local_15c = RtlLengthSid();
  }
  if (local_110 == (char *)0x0) {
    local_110 = "NULL";
  }
  if (local_108 == (char *)0x0) {
    local_158 = 5;
  }
  else {
    local_158 = RtlLengthSid();
  }
  if (local_108 == (char *)0x0) {
    local_108 = "NULL";
  }
  if (local_100 == (char *)0x0) {
    local_130 = CONCAT44(local_130._4_4_,5);
  }
  else {
    uVar1 = RtlLengthSid();
    local_130 = CONCAT44(local_130._4_4_,uVar1);
  }
  if (local_100 == (char *)0x0) {
    local_100 = "NULL";
  }
  if (pcVar4 == (char *)0x0) {
    local_170 = (code *)CONCAT44(local_170._4_4_,5);
    pcVar4 = "NULL";
  }
  else {
    uVar1 = RtlLengthSid(pcVar4);
    local_170 = (code *)CONCAT44(local_170._4_4_,uVar1);
  }
  local_88 = pcVar4;
  if (pcVar8 == (char *)0x0) {
    uVar5 = 5;
    pcVar8 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar8);
    uVar5 = (ulonglong)uVar2;
  }
  local_80 = pcVar8;
  if (pcVar6 == (char *)0x0) {
    uVar9 = 5;
    pcVar6 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar6);
    uVar9 = (ulonglong)uVar2;
  }
  local_78 = pcVar6;
  if (pcVar14 == (char *)0x0) {
    uVar7 = 5;
    pcVar14 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar14);
    uVar7 = (ulonglong)uVar2;
  }
  local_70 = pcVar14;
  if (pcVar16 == (char *)0x0) {
    uVar15 = 5;
    pcVar16 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar16);
    uVar15 = (ulonglong)uVar2;
  }
  local_68 = pcVar16;
  if (pcVar10 == (char *)0x0) {
    uVar17 = 5;
    pcVar10 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar10);
    uVar17 = (ulonglong)uVar2;
  }
  local_60 = pcVar10;
  if (pcVar12 == (char *)0x0) {
    uVar11 = 5;
    pcVar12 = "NULL";
  }
  else {
    uVar2 = RtlLengthSid(pcVar12);
    uVar11 = (ulonglong)uVar2;
  }
  local_58 = pcVar12;
  if (local_f8 == (char *)0x0) {
    uVar13 = 5;
  }
  else {
    uVar2 = RtlLengthSid();
    uVar13 = (ulonglong)uVar2;
  }
  if (local_f8 == (char *)0x0) {
    local_f8 = "NULL";
  }
  if (local_f0 == (char *)0x0) {
    local_150 = 5;
  }
  else {
    local_150 = RtlLengthSid();
  }
  if (local_f0 == (char *)0x0) {
    local_f0 = "NULL";
  }
  if (local_e8 == (char *)0x0) {
    local_14c = 5;
  }
  else {
    local_14c = RtlLengthSid();
  }
  if (local_e8 == (char *)0x0) {
    local_e8 = "NULL";
  }
  if (local_e0 == (char *)0x0) {
    local_148 = 5;
  }
  else {
    local_148 = RtlLengthSid();
  }
  if (local_e0 == (char *)0x0) {
    local_e0 = "NULL";
  }
  if (local_d8 == (char *)0x0) {
    local_144 = 5;
  }
  else {
    local_144 = RtlLengthSid();
  }
  if (local_d8 == (char *)0x0) {
    local_d8 = "NULL";
  }
  if (local_d0 == (char *)0x0) {
    local_140 = 5;
  }
  else {
    local_140 = RtlLengthSid();
  }
  if (local_d0 == (char *)0x0) {
    local_d0 = "NULL";
  }
  if (local_c8 == (char *)0x0) {
    local_13c = 5;
  }
  else {
    local_13c = RtlLengthSid();
  }
  if (local_c8 == (char *)0x0) {
    local_c8 = "NULL";
  }
  if (local_c0 == (char *)0x0) {
    local_138 = 5;
  }
  else {
    local_138 = RtlLengthSid();
  }
  local_134 = 5;
  if (local_c0 == (char *)0x0) {
    local_c0 = "NULL";
  }
  if (local_b8 != (char *)0x0) {
    local_134 = RtlLengthSid();
  }
  if (local_b8 == (char *)0x0) {
    local_b8 = "NULL";
  }
  bVar18 = local_b0 == (char *)0x0;
  if (!bVar18) {
    local_154 = RtlLengthSid(local_b0);
    bVar18 = local_b0 == (char *)0x0;
  }
  if (bVar18) {
    local_b0 = "NULL";
  }
  if (local_128 == (wchar_t *)0x0) {
    local_a0 = 10;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_128[lVar3] != L'\0');
    local_a0 = lVar3 * 2 + 2;
  }
  local_240 = (ulonglong)local_170 & 0xffffffff;
  local_230 = local_130 & 0xffffffff;
  local_1e0 = (ulonglong)local_168;
  local_1f0 = (ulonglong)local_164;
  local_200 = (ulonglong)local_160;
  local_210 = (ulonglong)local_15c;
  local_220 = (ulonglong)local_158;
  local_358 = local_128;
  if (local_128 == (wchar_t *)0x0) {
    local_358 = L"NULL";
  }
  local_188 = 0;
  local_190 = 4;
  local_170 = pfnWppTraceMessage;
  local_198 = &param_35;
  local_1a8 = &param_34;
  local_1a0 = 4;
  local_1b0 = 0x10;
  local_1b8 = local_98;
  local_1c0 = 0x10;
  local_1c8 = local_90;
  local_1d8 = &param_31;
  local_1d0 = 4;
  local_1e8 = local_a8;
  local_1f8 = local_120;
  local_2c0 = (ulonglong)local_150;
  local_208 = local_118;
  local_218 = local_110;
  local_228 = local_108;
  local_238 = local_100;
  local_248 = local_88;
  local_258 = local_80;
  local_268 = local_78;
  local_278 = local_70;
  local_288 = local_68;
  local_298 = local_60;
  local_2a8 = local_58;
  local_2b8 = local_f8;
  local_2d0 = (ulonglong)local_14c;
  local_2c8 = local_f0;
  local_2d8 = local_e8;
  local_2e0 = (ulonglong)local_148;
  local_2f0 = (ulonglong)local_144;
  local_2e8 = local_e0;
  local_300 = (ulonglong)local_140;
  local_2f8 = local_d8;
  local_310 = (ulonglong)local_13c;
  local_308 = local_d0;
  local_320 = (ulonglong)local_138;
  local_318 = local_c8;
  local_330 = (ulonglong)local_134;
  local_328 = local_c0;
  local_340 = (ulonglong)local_154;
  local_338 = local_b8;
  local_350 = local_a0;
  local_368 = &param_6;
  local_360 = 4;
  local_378 = &param_5;
  local_370 = 8;
  local_380 = 4;
  local_388 = local_48;
  local_348 = local_b0;
  local_2b0 = uVar13;
  local_2a0 = uVar11;
  local_290 = uVar17;
  local_280 = uVar15;
  local_270 = uVar7;
  local_260 = uVar9;
  local_250 = uVar5;
  local_130 = uVar13;
  local_128 = local_358;
  (*pfnWppTraceMessage)(local_50,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,local_178);
  return;
}



===== WPP_SF_dDdDdS @ 14000d06c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_dDdDdS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  wchar_t *param_9)

{
  longlong lVar1;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_9 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_8;
  local_40 = 4;
  local_58 = &param_7;
  local_50 = 4;
  local_68 = &param_6;
  local_60 = 4;
  local_78 = &param_5;
  local_70 = 4;
  local_88 = local_18;
  local_80 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  return;
}



===== WPP_SF_dL @ 14000d17c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_dL(undefined8 param_1)

{
  undefined1 auStack_78 [32];
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = local_28;
  local_28[0] = DAT_140015794;
  local_20[0] = DAT_1400156a4;
  local_40 = 4;
  local_58 = local_20;
  local_50 = 4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  return;
}



===== WPP_SF_d_IPV6_d_IPV6_dS @ 14000d200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_d_IPV6_d_IPV6_dS
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,undefined1 param_6,undefined8 param_7,undefined1 param_8,
               wchar_t *param_9)

{
  longlong lVar1;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_9 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_9[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_8;
  local_40 = 4;
  local_68 = &param_6;
  local_50 = 0x10;
  local_58 = param_7;
  local_60 = 4;
  local_88 = local_18;
  local_70 = 0x10;
  local_78 = param_5;
  local_80 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,0xb);
  return;
}



===== WPP_SF_dq @ 14000d314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5)

{
  undefined1 auStack_78 [32];
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_28;
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = &local_28;
  local_40 = 8;
  local_58 = local_20;
  local_50 = 4;
  local_28 = param_5;
  local_20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids,param_2);
  return;
}



===== WPP_SF_q @ 14000d394 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStack_58 [32];
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_38 = &local_18;
  local_30 = 8;
  local_18 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_dc4d882d08f635b6520935bdd4e6f511_Traceguids);
  return;
}



===== DfwDeinitializeIpFlowManager @ 14000d3fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DfwDeinitializeIpFlowManager(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids);
  }
  ExDeleteNPagedLookasideList(&DAT_140015900);
  if (*(int *)(DAT_1400158c8 + 0xc0) != 0) {
    if (*(code **)(DAT_1400158c8 + 0x20) != (code *)0x0) {
      (**(code **)(DAT_1400158c8 + 0x20))();
    }
    if (*(int *)(DAT_1400158c8 + 0x30) != 0) {
      ExDeleteNPagedLookasideList(DAT_1400158c8 + 0x40);
    }
    *(undefined4 *)(DAT_1400158c8 + 0xc0) = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids);
  }
  return;
}



===== DfwDeleteAnalyzer @ 14000d4c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DfwDeleteAnalyzer(longlong param_1)

{
  if (*(code **)(*(longlong *)(&DAT_1400158c0 + (ulonglong)*(byte *)(param_1 + 0xc) * 8) + 8) !=
      (code *)0x0) {
    (**(code **)(*(longlong *)(&DAT_1400158c0 + (ulonglong)*(byte *)(param_1 + 0xc) * 8) + 8))
              (param_1 + 0x10);
  }
  ExFreeToNPagedLookasideList
            (*(longlong *)(&DAT_1400158c0 + (ulonglong)*(byte *)(param_1 + 0xc) * 8) + 0x40,param_1)
  ;
  return;
}



===== DfwHandleFlowCreation @ 14000d520 =====

int DfwHandleFlowCreation(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  if ((*(byte *)(param_1 + 0x28) & 1) == 0) {
    sVar1 = *(short *)(param_1 + 0x1a);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x18);
  }
  if ((*(char *)(param_1 + 0x1d) == '\x06') && (sVar1 == 0x15)) {
    iVar2 = NseCreateAnalyzer(1,param_1,param_2);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar2);
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar2;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar2);
      return iVar2;
    }
    uVar3 = *(undefined4 *)(DAT_1400158c8 + 0x28);
  }
  else {
    *param_2 = 0;
  }
  *param_3 = uVar3;
  return iVar2;
}



===== DfwInitializeIpFlowManager @ 14000d5f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DfwInitializeIpFlowManager(void)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  
  iVar2 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids);
  }
  ExInitializeNPagedLookasideList(&DAT_140015900,0,0,0x200,0x40,0x4970466c,0);
  _DAT_1400158c0 = 0;
  DAT_1400158c8 = &FtpAnalyzerOps;
  uVar4 = 1;
  while( true ) {
    if (1 < uVar4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids);
      }
      return iVar2;
    }
    uVar3 = (ulonglong)uVar4;
    if ((*(code **)(*(longlong *)(&DAT_1400158c0 + uVar3 * 8) + 0x18) != (code *)0x0) &&
       (iVar2 = (**(code **)(*(longlong *)(&DAT_1400158c0 + uVar3 * 8) + 0x18))(), iVar2 < 0))
    break;
    lVar1 = *(longlong *)(&DAT_1400158c0 + uVar3 * 8);
    if (*(int *)(lVar1 + 0x30) != 0) {
      ExInitializeNPagedLookasideList
                (lVar1 + 0x40,0,0,0x200,*(int *)(lVar1 + 0x2c) + 0x10,*(int *)(lVar1 + 0x30),0);
    }
    uVar4 = uVar4 + 1;
    *(undefined4 *)(*(longlong *)(&DAT_1400158c0 + uVar3 * 8) + 0xc0) = 1;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar2);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar2);
    }
  }
  DfwDeinitializeIpFlowManager();
  return iVar2;
}



===== NseCreateAnalyzer @ 14000d7b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NseCreateAnalyzer(byte param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  iVar1 = 0;
  puVar2 = (undefined8 *)
           ExAllocateFromNPagedLookasideList
                     (*(longlong *)(&DAT_1400158c0 + (ulonglong)param_1 * 8) + 0x40);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    *(byte *)((longlong)puVar2 + 0xc) = param_1;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    if (((code *)**(undefined8 **)(&DAT_1400158c0 + (ulonglong)param_1 * 8) == (code *)0x0) ||
       (iVar1 = (*(code *)**(undefined8 **)(&DAT_1400158c0 + (ulonglong)param_1 * 8))
                          (puVar2 + 2,param_2), -1 < iVar1)) {
      *param_3 = puVar2 + 2;
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar1);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_5ed0b75bde943dbe5d41d11565eb28d6_Traceguids,iVar1);
  }
  return iVar1;
}



===== AddFilterToList @ 14000d8bc =====

undefined4 AddFilterToList(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  lVar1 = DAT_1400157a0;
  uVar11 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  if ((Feature_3980100923__private_featureState & 0x10) == 0) {
    uVar4 = Feature_3980100923__private_IsEnabledDeviceUsageNoInline();
    uVar7 = (uint)uVar4;
  }
  else {
    uVar7 = Feature_3980100923__private_featureState & 1;
  }
  uVar10 = *(uint *)(lVar1 + 0x14);
  uVar8 = *(uint *)(lVar1 + 0x10) + 1;
  if (uVar7 == 0) {
    if (uVar10 < uVar8) {
      if (uVar10 == 0) {
        iVar2 = 8;
      }
      else {
        iVar2 = uVar10 * 2;
      }
      *(int *)(lVar1 + 0x14) = iVar2;
      pvVar6 = (void *)ExAllocatePool2(0x40,iVar2 << 3,0x52544c46);
      if (pvVar6 == (void *)0x0) {
LAB_14000da0c:
        uVar3 = 0xc0000017;
        goto LAB_14000da11;
      }
      if (*(void **)(lVar1 + 8) != (void *)0x0) {
        memmove(pvVar6,*(void **)(lVar1 + 8),(ulonglong)*(uint *)(lVar1 + 0x10) << 3);
        ExFreePoolWithTag(*(undefined8 *)(lVar1 + 8),0);
      }
      *(void **)(lVar1 + 8) = pvVar6;
    }
LAB_14000da72:
    uVar7 = *(uint *)(lVar1 + 0x10);
    uVar4 = (ulonglong)uVar7;
    if (uVar7 != 0) {
LAB_14000da83:
      uVar10 = (uint)uVar11;
      if (*(uint *)(*(longlong *)(*(longlong *)(lVar1 + 8) + uVar11 * 8) + 8) <=
          *(uint *)(param_2 + 8)) goto code_r0x00014000da8f;
      if (uVar10 < uVar7) {
        lVar12 = uVar4 * 8;
        do {
          uVar7 = (int)uVar4 - 1;
          uVar4 = (ulonglong)uVar7;
          *(undefined8 *)(lVar12 + *(longlong *)(lVar1 + 8)) =
               *(undefined8 *)(*(longlong *)(lVar1 + 8) + uVar4 * 8);
          lVar12 = lVar12 + -8;
        } while (uVar10 < uVar7);
      }
      *(longlong *)(*(longlong *)(lVar1 + 8) + uVar11 * 8) = param_2;
      goto LAB_14000da9e;
    }
LAB_14000da96:
    *(longlong *)(*(longlong *)(lVar1 + 8) + uVar4 * 8) = param_2;
LAB_14000da9e:
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
    }
    uVar3 = 0;
  }
  else {
    if (uVar8 <= uVar10) goto LAB_14000da72;
    if (uVar10 == 0) {
      uVar4 = 8;
LAB_14000d95f:
      uVar5 = (uVar4 & 0xffffffff) * 8;
      if ((uVar5 < 0x100000000) &&
         (uVar9 = (ulonglong)*(uint *)(lVar1 + 0x10) * 8, uVar9 < 0x100000000)) {
        pvVar6 = (void *)ExAllocatePool2(0x40,uVar5 & 0xffffffff,0x52544c46);
        if (pvVar6 == (void *)0x0) goto LAB_14000da0c;
        if (*(void **)(lVar1 + 8) != (void *)0x0) {
          memmove(pvVar6,*(void **)(lVar1 + 8),uVar9 & 0xffffffff);
          ExFreePoolWithTag(*(undefined8 *)(lVar1 + 8),0);
        }
        *(void **)(lVar1 + 8) = pvVar6;
        *(int *)(lVar1 + 0x14) = (int)uVar4;
        goto LAB_14000da72;
      }
    }
    else {
      uVar4 = (ulonglong)uVar10 * 2;
      if (uVar4 < 0x100000000) goto LAB_14000d95f;
    }
    uVar3 = 0xc0000095;
LAB_14000da11:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,uVar3);
    }
  }
  return uVar3;
code_r0x00014000da8f:
  uVar11 = (ulonglong)(uVar10 + 1);
  if (uVar7 <= uVar10 + 1) goto LAB_14000da96;
  goto LAB_14000da83;
}



===== ClearFilterList @ 14000db24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ClearFilterList(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar5 = 0;
    plVar1 = (longlong *)(param_1 + 8);
    if (*(int *)(param_1 + 0x10) != 0) {
      do {
        piVar3 = *(int **)(*plVar1 + uVar5 * 8);
        if (piVar3 != (int *)0x0) {
          LOCK();
          iVar2 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            if ((*(byte *)(piVar3 + 1) < 2) &&
               ((code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(piVar3 + 1) * 8) !=
                (code *)0x0)) {
              (*(code *)**(undefined8 **)(&g_FilterOps + (ulonglong)*(byte *)(piVar3 + 1) * 8))
                        (piVar3);
            }
            ExFreePoolWithTag(piVar3,0);
          }
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *(uint *)(param_1 + 0x10));
    }
    ExFreePoolWithTag(*plVar1,0);
    *plVar1 = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



===== DfwDeinitializeFilterModule @ 14000dbd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DfwDeinitializeFilterModule(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  if (*(int *)(DAT_1400159e8 + 0x18) != 0) {
    if (*(code **)(DAT_1400159e8 + 0x10) != (code *)0x0) {
      (**(code **)(DAT_1400159e8 + 0x10))();
    }
    *(undefined4 *)(DAT_1400159e8 + 0x18) = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  return;
}



===== DfwInitializeFilterModule @ 14000dc68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DfwInitializeFilterModule(void)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  
  iVar1 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  }
  _g_FilterOps = 0;
  DAT_1400159e8 = &IpFilterOps;
  uVar3 = 1;
  while( true ) {
    if (1 < uVar3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
      }
      return iVar1;
    }
    uVar2 = (ulonglong)uVar3;
    if ((*(code **)(*(longlong *)(&g_FilterOps + uVar2 * 8) + 8) != (code *)0x0) &&
       (iVar1 = (**(code **)(*(longlong *)(&g_FilterOps + uVar2 * 8) + 8))(), iVar1 < 0)) break;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(*(longlong *)(&g_FilterOps + uVar2 * 8) + 0x18) = 1;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,iVar1);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids,iVar1);
    }
  }
  DfwDeinitializeFilterModule();
  return iVar1;
}



===== Feature_3980100923__private_IsEnabledDeviceUsageNoInline @ 14000ddb0 =====

ulonglong Feature_3980100923__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  char *local_res8;
  
  local_res8 = (char *)(ulonglong)Feature_3980100923__private_featureState;
  if ((Feature_3980100923__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3980100923__private_IsEnabledFallback(local_res8,3);
    return uVar1;
  }
  return (ulonglong)(Feature_3980100923__private_featureState & 1);
}



===== Feature_3980100923__private_IsEnabledFallback @ 14000ddf0 =====

void Feature_3980100923__private_IsEnabledFallback(char *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_SF_dd @ 14000de08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_78 [32];
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_48 = local_28;
  local_28[0] = 1;
  local_40 = 4;
  local_58 = local_20;
  local_50 = 4;
  local_20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_cc5a224290e93e3ba3a4ab9483a53adc_Traceguids);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000de90 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  switch(param_3) {
  case 0:
  case 4:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar5 = uVar2 >> 5 & 0x1ff;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 4;
          if (param_3 != 0) {
            uVar5 = 0;
          }
          uVar4 = uVar2 & 0xffffc01f | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 4) {
          uVar5 = 0x4000;
        }
        uVar4 = uVar5 | uVar4 & 0xffffbfff;
      }
      uVar3 = uVar4 >> 5 & 0x1ff;
      uVar5 = uVar3 + 1;
      if ((0x1ff < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 5 ^ uVar4) & 0x3fe0 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 1:
  case 5:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar5 = uVar2 >> 0xf & 0x7f;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 5;
          if (param_3 != 1) {
            uVar5 = 1;
          }
          uVar4 = uVar2 & 0xffc07fff | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 5) {
          uVar5 = 0x400000;
        }
        uVar4 = uVar5 | uVar4 & 0xffbfffff;
      }
      uVar3 = uVar4 >> 0xf & 0x7f;
      uVar5 = uVar3 + 1;
      if ((0x7f < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 0xf ^ uVar4) & 0x3f8000 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 2:
  case 3:
  case 6:
  case 7:
    uVar4 = 0;
    if (param_3 == 2) {
      uVar4 = 2;
    }
    else if (param_3 == 3) {
      uVar4 = 8;
    }
    else if (param_3 == 6) {
      uVar4 = 4;
    }
    else if (param_3 == 7) {
      uVar4 = 0x10;
    }
    uVar2 = *param_2;
    do {
      uVar3 = uVar2;
      uVar2 = uVar4 | uVar3;
      param_1[4] = (uint)(uVar2 == uVar3);
      uVar5 = uVar2 | 1;
      if (uVar2 == uVar3) {
        uVar5 = uVar2;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar5;
        uVar2 = uVar3;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar5 & 1) == 0) || (uVar4 = 1, (uVar3 & 1) != 0)) {
      uVar4 = 0;
    }
    *param_1 = uVar4;
    break;
  default:
    uVar4 = param_3 - 0x140;
    if ((int)uVar4 < 0x40) {
      uVar2 = param_2[1];
      do {
        if (((uVar2 & 0x10) == 0) || (uVar5 = 1, (uVar2 >> 5 & 0x3f) != uVar4)) {
          uVar5 = 0;
        }
        param_1[4] = uVar5;
        LOCK();
        uVar5 = param_2[1];
        bVar6 = uVar2 == uVar5;
        if (bVar6) {
          param_2[1] = (uVar4 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
        }
        else {
          uVar2 = uVar5;
        }
        UNLOCK();
      } while (!bVar6);
      if (param_1[4] != 0) {
        return param_1;
      }
    }
    param_1[2] = param_3;
    param_1[1] = 1;
    param_1[3] = param_4;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000e170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_FeatureReporting_ReportUsageToService(char *param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_68 [32];
  uint *local_48;
  undefined8 local_40;
  undefined1 local_38;
  undefined8 local_30;
  uint local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar3 = (uint)param_2 & 1;
  if (param_3 < 7) {
    param_1 = IMAGE_DOS_HEADER_140000000.e_magic +
              (&switchD_14000e1aa::switchdataD_1400131d0)[(int)param_3];
    switch(param_3) {
    case 0:
      goto switchD_14000e1aa_caseD_0;
    case 1:
      uVar4 = (uVar3 ^ 1) << 2;
      break;
    case 2:
      uVar4 = (uVar3 ^ 1) * 4 + 1;
      break;
    case 3:
      uVar4 = (uVar3 ^ 1) * 4 + 2;
      break;
    case 4:
      uVar4 = (uVar3 ^ 1) * 4 + 3;
      break;
    case 5:
      uVar4 = (uVar3 ^ 1) * 2 + 8;
      break;
    case 6:
      uVar4 = (uVar3 ^ 1) * 2 + 9;
    }
  }
  else {
    if ((byte)((char)param_3 + 0x9cU) < 0x32) {
      param_1 = (char *)0x96;
      iVar2 = 100;
      if ((param_2 & 1) == 0) {
        iVar2 = 0x96;
      }
      uVar4 = (uint)(byte)((char)param_3 + 0x9c) + iVar2;
      goto LAB_14000e232;
    }
switchD_14000e1aa_caseD_0:
    uVar4 = 0xff;
  }
LAB_14000e232:
  local_18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar4);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    local_48 = local_18;
    local_30 = 1;
    local_38 = 0;
    local_40 = 0;
    (*g_wil_details_pfnFeatureLoggingHook)(0x3bd10a5,&Feature_3980100923_logged_traits,0,uVar3);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000e2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_78 [32];
  uint *local_58;
  uint local_48 [6];
  undefined8 local_30;
  uint local_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_48,&Feature_3980100923__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_28 = *puVar2;
  uStack_24 = puVar2[1];
  uStack_20 = puVar2[2];
  uStack_1c = puVar2[3];
  local_18 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_58 = &local_28;
    (*g_wil_details_recordFeatureUsage)(0x3bd10a5,param_3,1,&Feature_3980100923__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_30._0_6_ = CONCAT24((short)param_3,0x3bd10a5);
    uVar1 = (uint6)local_30;
    local_30 = (ulonglong)(uint6)local_30;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_30 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_30);
  }
  return (int)local_18 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000e390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  int local_res8 [2];
  undefined8 local_res10;
  
  local_res8[0] = 0;
  iVar1 = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if ((*(char *)(param_3 + 0x1c) == '\0') && (iVar1 == 0)) {
    local_res8[0] = 0;
  }
  while( true ) {
    uVar3 = (uint)param_2;
    local_res10 = CONCAT44(local_res10._4_4_,uVar3);
    uVar6 = (uint)uVar2;
    uVar5 = uVar3;
    if ((local_res8[0] != 0) && ((param_2 & 2) == 0)) {
      uVar4 = uVar3 & 0xfffff63e | uVar6 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar6 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    LOCK();
    uVar4 = *param_1;
    bVar7 = uVar3 == uVar4;
    if (bVar7) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = uVar4;
    }
    UNLOCK();
    if (bVar7) break;
    param_2 = (ulonglong)uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar6 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000e4a0 =====

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
  if ((Feature_3980100923__private_featureState & 2) != 0) {
    uVar1 = Feature_3980100923__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3980100923__private_featureState;
      if (bVar3) {
        Feature_3980100923__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3980100923__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14000e500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  longlong *plVar11;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_30;
  undefined4 local_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  cVar1 = *(char *)(param_1 + 0x1c);
  local_20 = 0;
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_30 = 0;
  local_28 = 0;
  bVar4 = false;
  local_48 = 0;
  uStack_40 = 0;
  iVar5 = RtlQueryFeatureConfiguration(uVar2,1 < (byte)(cVar1 - 2U),&local_20,&local_30);
  if (iVar5 == 0) {
    bVar4 = true;
    uVar9 = local_30._4_4_ >> 7 & 1;
    uVar6 = local_30._4_4_ >> 6 & 1;
    uVar10 = local_30._4_4_ >> 4 & 3;
LAB_14000e593:
    uVar9 = uVar9 << 10;
    uVar7 = 0x800;
    if (uVar6 != 0) goto LAB_14000e5a6;
  }
  else {
    uVar9 = 0;
    uVar6 = 0;
    uVar10 = (uint)local_48;
    if (iVar5 != 0x117) goto LAB_14000e593;
    bVar4 = true;
    uVar9 = (local_30._4_4_ >> 7 & 1) << 10;
  }
  uVar7 = 0;
LAB_14000e5a6:
  uVar9 = uVar9 | uVar7;
  if ((!bVar4) || (uVar9 = (uVar10 & 3) << 7 | uVar9, (uVar10 & 3) == 0)) {
    uVar9 = uVar9 | -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar6 = 0;
    if (uVar10 == 2) {
      uVar6 = 0x40;
    }
    uVar9 = uVar9 | uVar6;
  }
  uVar10 = uVar9 >> 6 & 1 ^ uVar9;
  local_30 = (ulonglong)uVar10;
  if (((uVar9 & 0x40) != 0) &&
     (plVar11 = *(longlong **)(param_1 + 0x20), plVar11 != (longlong *)0x0)) {
    local_30 = (ulonglong)uVar10;
    do {
      puVar3 = (undefined8 *)*plVar11;
      if (puVar3 == (undefined8 *)0x0) {
        return local_30;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar9 = *(uint *)*puVar3;
        local_20 = (ulonglong)uVar9;
        if ((uVar9 & 2) == 0) {
          uVar8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_20,(longlong)puVar3);
          uVar9 = (uint)uVar8;
        }
        uVar6 = uVar10 & 0xfffffffe;
        uVar10 = (uint)((uVar9 & uVar10 & 1) != 0);
      }
      else {
        if (((uVar10 & 1) == 0) || (uVar6 = 1, *(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar6 = 0;
        }
        uVar10 = uVar10 & 0xfffffffe;
      }
      uVar10 = uVar10 | uVar6;
      plVar11 = plVar11 + 1;
      local_30 = CONCAT44(local_30._4_4_,uVar10);
    } while ((uVar10 & 1) != 0);
  }
  return local_30;
}



===== wil_details_IsEnabledFallback @ 14000e6d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint wil_details_IsEnabledFallback(char *param_1,uint param_2)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 auStack_38 [32];
  char *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = (char *)((ulonglong)param_1 & 0xffffffff);
  if (((ulonglong)param_1 & 2) == 0) {
    pcVar3 = (char *)&Feature_3980100923__private_featureState;
    pcVar2 = (char *)wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                               (&Feature_3980100923__private_featureState,(ulonglong)param_1,
                                0x140014690);
    param_1 = pcVar3;
    pcVar4 = (char *)((ulonglong)pcVar2 & 0xffffffff);
    pcVar3 = pcVar2;
  }
  else {
    pcVar4 = param_1;
    pcVar2 = local_18;
    pcVar3 = param_1;
  }
  uVar1 = (uint)pcVar2;
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,(ulonglong)pcVar2,param_2);
    if ((param_2 == 3) || (uVar1 = (uint)pcVar4, param_2 == 4)) {
      uVar1 = (uint)pcVar3;
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)pcVar2,param_2);
    }
  }
  return uVar1 & 1;
}



===== wil_details_MapReportingKind @ 14000e7a0 =====

int wil_details_MapReportingKind(undefined4 param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  switch(param_1) {
  case 0:
    goto switchD_14000e7ba_caseD_0;
  case 1:
    iVar1 = 0;
    if (param_2 == 0) {
      iVar1 = 4;
    }
    return iVar1;
  case 2:
    iVar1 = 1;
    if (param_2 == 0) {
      iVar1 = 5;
    }
    return iVar1;
  case 3:
    iVar1 = 2;
    if (param_2 == 0) {
      iVar1 = 6;
    }
    return iVar1;
  case 4:
    iVar1 = 3;
    if (param_2 == 0) {
      iVar1 = 7;
    }
    return iVar1;
  case 5:
    iVar1 = 8;
    if (param_2 == 0) {
      iVar1 = 10;
    }
    return iVar1;
  case 6:
    iVar1 = 9;
    if (param_2 == 0) {
      iVar1 = 0xb;
    }
    return iVar1;
  default:
    bVar2 = (char)param_1 + 0x9c;
    if (bVar2 < 0x32) {
      iVar1 = 100;
      if (param_2 == 0) {
        iVar1 = 0x96;
      }
      return iVar1 + (uint)bVar2;
    }
switchD_14000e7ba_caseD_0:
    return 0xff;
  }
}



===== DfwDeinitializeIpFiltering @ 14000e850 =====

void DfwDeinitializeIpFiltering(void)

{
  int iVar1;
  int *piVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  }
  piVar2 = DAT_1400157a0;
  if (DAT_1400157a0 != (int *)0x0) {
    LOCK();
    iVar1 = *DAT_1400157a0;
    *DAT_1400157a0 = *DAT_1400157a0 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      ClearFilterList((longlong)piVar2);
      ExFreePoolWithTag(piVar2,0);
    }
    DAT_1400157a0 = (int *)0x0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  }
  return;
}



===== WPP_SF_DdDddDddS @ 14000e8fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_DdDddDddS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                     undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                     undefined1 param_9,undefined1 param_10,undefined1 param_11,wchar_t *param_12)

{
  longlong lVar1;
  undefined1 auStack_d8 [32];
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_12 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_12[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_12;
  if (param_12 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_11;
  local_40 = 4;
  local_58 = &param_10;
  local_50 = 4;
  local_68 = &param_9;
  local_60 = 4;
  local_78 = &param_8;
  local_70 = 4;
  local_88 = &param_7;
  local_80 = 4;
  local_98 = &param_6;
  local_90 = 4;
  local_a8 = &param_5;
  local_a0 = 4;
  local_b8 = local_18;
  local_b0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  return;
}



===== WPP_SF_DdDddDdddS @ 14000ea54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_DdDddDdddS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                      undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                      undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12
                      ,wchar_t *param_13)

{
  longlong lVar1;
  undefined1 auStack_e8 [32];
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_e8;
  if (param_13 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_13[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_13;
  if (param_13 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_12;
  local_40 = 4;
  local_58 = &param_11;
  local_50 = 4;
  local_68 = &param_10;
  local_60 = 4;
  local_78 = &param_9;
  local_70 = 4;
  local_88 = &param_8;
  local_80 = 4;
  local_98 = &param_7;
  local_90 = 4;
  local_a8 = &param_6;
  local_a0 = 4;
  local_b8 = &param_5;
  local_b0 = 4;
  local_c8 = local_18;
  local_c0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids,param_2);
  return;
}



===== WPP_SF_Dd_IPV6_dd_IPV6_ddS @ 14000ebc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_Dd_IPV6_dd_IPV6_ddS
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined8 param_9,undefined1 param_10,undefined1 param_11,wchar_t *param_12)

{
  longlong lVar1;
  undefined1 auStack_d8 [32];
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_12 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_12[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_12;
  if (param_12 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_11;
  local_40 = 4;
  local_58 = &param_10;
  local_50 = 4;
  local_78 = &param_8;
  local_60 = 0x10;
  local_68 = param_9;
  local_70 = 4;
  local_88 = &param_7;
  local_80 = 4;
  local_a8 = &param_5;
  local_90 = 0x10;
  local_98 = param_6;
  local_a0 = 4;
  local_b8 = local_18;
  local_b0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids,0x1c);
  return;
}



===== WPP_SF_Dd_IPV6_dd_IPV6_dddS @ 14000ed20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_Dd_IPV6_dd_IPV6_dddS
               (undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined8 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               wchar_t *param_13)

{
  longlong lVar1;
  undefined1 auStack_e8 [32];
  undefined4 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_e8;
  if (param_13 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_13[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_13;
  if (param_13 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_12;
  local_40 = 4;
  local_50 = 4;
  local_58 = &param_11;
  local_68 = &param_10;
  local_60 = 4;
  local_88 = &param_8;
  local_70 = 0x10;
  local_78 = param_9;
  local_80 = 4;
  local_98 = &param_7;
  local_90 = 4;
  local_b8 = &param_5;
  local_a0 = 0x10;
  local_a8 = param_6;
  local_b0 = 4;
  local_c8 = local_18;
  local_c0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids,param_2);
  return;
}



===== WPP_SF_L @ 14000ee94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_38 = local_18;
  local_30 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  return;
}



===== WPP_SF_ddDdDddS @ 14000eefc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_ddDdDddS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,wchar_t *param_11)

{
  longlong lVar1;
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  if (param_11 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_11[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_11;
  if (param_11 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_10;
  local_40 = 4;
  local_58 = &param_9;
  local_50 = 4;
  local_68 = &param_8;
  local_60 = 4;
  local_78 = &param_7;
  local_70 = 4;
  local_88 = &param_6;
  local_80 = 4;
  local_98 = &param_5;
  local_90 = 4;
  local_a8 = local_18;
  local_a0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids);
  return;
}



===== WPP_SF_dd_IPV6_d_IPV6_ddS @ 14000f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_dd_IPV6_d_IPV6_ddS
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,wchar_t *param_11)

{
  longlong lVar1;
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_c8;
  if (param_11 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_11[lVar1] != L'\0');
    local_30 = lVar1 * 2 + 2;
  }
  local_28 = 0;
  local_38 = param_11;
  if (param_11 == (wchar_t *)0x0) {
    local_38 = L"NULL";
  }
  local_48 = &param_10;
  local_40 = 4;
  local_58 = &param_9;
  local_50 = 4;
  local_78 = &param_7;
  local_60 = 0x10;
  local_68 = param_8;
  local_70 = 4;
  local_98 = &param_5;
  local_80 = 0x10;
  local_88 = param_6;
  local_90 = 4;
  local_a8 = local_18;
  local_a0 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_22c82edf472934362cca16c116ec1405_Traceguids,0x17);
  return;
}



===== WPP_SF_DHDHDs @ 14000f180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_DHDHDs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  char *param_9)

{
  longlong lVar1;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  char *local_38;
  longlong local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_9 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar1 = -1;
    do {
      local_30 = lVar1;
      lVar1 = local_30 + 1;
    } while (param_9[lVar1] != '\0');
    local_30 = local_30 + 2;
  }
  local_38 = param_9;
  if (param_9 == (char *)0x0) {
    local_38 = "NULL";
  }
  local_28 = 0;
  local_48 = &param_8;
  local_40 = 4;
  local_58 = &param_7;
  local_50 = 2;
  local_68 = &param_6;
  local_60 = 4;
  local_78 = &param_5;
  local_70 = 2;
  local_88 = local_18;
  local_80 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_9ab7dfc9dac33bd7fa60a550e3895a14_Traceguids);
  return;
}



===== HexDigitValue @ 14000f28c =====

int HexDigitValue(char param_1)

{
  if ((byte)(param_1 - 0x30U) < 10) {
    return param_1 + -0x30;
  }
  if ((byte)(param_1 + 0x9fU) < 6) {
    return param_1 + -0x57;
  }
  if ((byte)(param_1 + 0xbfU) < 6) {
    return param_1 + -0x37;
  }
  return 0;
}



===== IP4StringToAddress @ 14000f2c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 IP4StringToAddress(char *param_1,undefined8 param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint local_28 [8];
  
  puVar4 = local_28;
  while( true ) {
    bVar3 = false;
    iVar6 = 10;
    pcVar5 = param_1;
    if (*param_1 == '0') {
      pcVar5 = param_1 + 1;
      if ((byte)(*pcVar5 - 0x30U) < 10) goto LAB_14000f37c;
      if ((*pcVar5 + 0xa8U & 0xdf) == 0) {
        iVar6 = 0x10;
        pcVar5 = param_1 + 2;
      }
      else {
        bVar3 = true;
      }
    }
    uVar7 = 0;
    if (iVar6 != 10) goto LAB_14000f37c;
    while( true ) {
      cVar2 = *pcVar5;
      if (cVar2 == '\0') goto LAB_14000f39d;
      if ((9 < (byte)(cVar2 - 0x30U)) || (0x39 < cVar2)) break;
      uVar1 = (int)cVar2 + uVar7 * 10 + -0x30;
      if (uVar1 < uVar7) goto LAB_14000f37c;
      pcVar5 = pcVar5 + 1;
      bVar3 = true;
      uVar7 = uVar1;
    }
    if (cVar2 != '.') break;
    if (local_28 + 3 <= puVar4) goto LAB_14000f37c;
    *puVar4 = uVar7;
    param_1 = pcVar5 + 1;
    puVar4 = puVar4 + 1;
    pcVar5 = param_1;
    if (!bVar3) {
LAB_14000f37c:
      *param_3 = pcVar5;
      return 0xc000000d;
    }
  }
LAB_14000f39d:
  if ((((bVar3) && (*puVar4 = uVar7, (int)((longlong)puVar4 + (4 - (longlong)local_28) >> 2) == 4))
      && (local_28[0] < 0x100)) &&
     (((local_28[1] < 0x100 && (local_28[2] < 0x100)) && (local_28[3] < 0x100)))) {
    *param_3 = pcVar5;
    *param_4 = ((local_28[1] & 0xff | local_28[0] << 8) << 8 | local_28[2] & 0xff) << 8 |
               local_28[3] & 0xff;
    return 0;
  }
  goto LAB_14000f37c;
}



===== IP6StringToAddress @ 14000f404 =====

undefined8 IP6StringToAddress(char *param_1,undefined8 *param_2,longlong param_3)

{
  void *_Src;
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint local_res8 [2];
  uint local_res20;
  uint local_48 [4];
  
  uVar7 = 0;
  local_res8[0] = local_res8[0] & 0xffffff00;
  pcVar9 = (char *)0x0;
  local_res20 = 0;
  uVar3 = 0;
  uVar4 = 0;
  uVar2 = 0;
  uVar8 = 0;
  uVar5 = 0;
  while( true ) {
    cVar1 = *param_1;
    if (cVar1 == '\0') break;
    if (uVar7 == 0) {
      if (cVar1 == ':') {
        if (uVar4 != 0) goto LAB_14000f515;
        if ((uVar3 != 0) || (param_1[1] != ':')) break;
        uVar3 = 2;
        local_res20 = (int)uVar5 + 1;
        uVar6 = (ulonglong)local_res20;
        uVar8 = 1;
        *(undefined2 *)(param_3 + uVar5 * 2) = 0;
LAB_14000f55f:
        uVar7 = 2;
        param_1 = param_1 + 1;
        uVar5 = uVar6;
LAB_14000f562:
        if (pcVar9 != (char *)0x0) {
          local_48[0] = 0;
          if (uVar4 == 0) {
            if (4 < uVar2) {
              return 0xc000000d;
            }
            ParseHex32bit(pcVar9,pcVar9 + uVar2,(int *)local_48);
            *(ushort *)(param_3 + (ulonglong)local_res20 * 2) =
                 (ushort)local_48[0] >> 8 | (ushort)local_48[0] << 8;
            local_res20 = local_res20 + 1;
            uVar5 = (ulonglong)local_res20;
          }
          else {
            if (3 < uVar2) {
              return 0xc000000d;
            }
            ParseDec32bit(pcVar9,pcVar9 + uVar2,(int *)local_48);
            if (0xff < local_48[0]) {
              return 0xc000000d;
            }
            uVar5 = (ulonglong)local_res20;
            *(char *)((ulonglong)(local_res20 * 2 + -1 + uVar4) + param_3) = (char)local_48[0];
          }
        }
      }
      else {
LAB_14000f5ee:
        if ((byte)(cVar1 - 0x30U) < 10) {
          local_res8[0] = local_res8[0] & 0xffffff00;
          uVar7 = 1;
          pcVar9 = param_1;
          uVar2 = uVar7;
        }
        else {
          if (((9 < (byte)(cVar1 - 0x30U)) && (5 < (byte)(cVar1 + 0x9fU))) &&
             (5 < (byte)(cVar1 + 0xbfU))) break;
          if (uVar4 != 0) goto LAB_14000f515;
          uVar7 = 1;
          pcVar9 = param_1;
          uVar2 = uVar7;
LAB_14000f62c:
          local_res8[0] = CONCAT31(local_res8[0]._1_3_,1);
        }
      }
    }
    else if (uVar7 == 1) {
      if (9 < (byte)(cVar1 - 0x30U)) {
        if ((((byte)(cVar1 - 0x30U) < 10) || ((byte)(cVar1 + 0x9fU) < 6)) ||
           ((byte)(cVar1 + 0xbfU) < 6)) {
          uVar2 = uVar2 + 1;
          if (uVar4 != 0) goto LAB_14000f515;
          goto LAB_14000f62c;
        }
        if (cVar1 == ':') {
          if (uVar4 == 0) {
            if (uVar3 < 7) {
              if (param_1[1] != ':') {
                uVar3 = uVar3 + 1;
LAB_14000f4e0:
                uVar7 = 0;
                goto LAB_14000f562;
              }
              if ((uVar8 == 0) && (uVar3 < 6)) {
                uVar8 = uVar3 + 1;
                uVar3 = uVar3 + 2;
                uVar6 = uVar5;
                goto LAB_14000f55f;
              }
            }
            break;
          }
        }
        else {
          if ((cVar1 != '.') || ((char)local_res8[0] != '\0')) break;
          if (uVar4 < 3) {
            if (uVar3 < 7) {
              uVar4 = uVar4 + 1;
              goto LAB_14000f4e0;
            }
            break;
          }
        }
LAB_14000f515:
        *param_2 = param_1;
        goto LAB_14000f643;
      }
      uVar2 = uVar2 + 1;
    }
    else {
      if (uVar7 == 2) goto LAB_14000f5ee;
      if (uVar7 != 1) {
        goto LAB_14000f562;
      }
    }
    param_1 = param_1 + 1;
  }
  *param_2 = param_1;
  if (uVar4 != 0) {
LAB_14000f643:
    if (uVar4 != 3) {
      return 0xc000000d;
    }
    uVar3 = uVar3 + 1;
  }
  if ((uVar8 != 0) || (uVar3 == 7)) {
    if (uVar7 == 1) {
      local_res8[0] = 0;
      if (uVar4 == 0) {
        if (uVar2 < 5) {
          ParseHex32bit(pcVar9,pcVar9 + uVar2,(int *)local_res8);
          *(ushort *)(param_3 + (ulonglong)local_res20 * 2) =
               (ushort)local_res8[0] >> 8 | (ushort)local_res8[0] << 8;
LAB_14000f6d9:
          if (uVar8 != 0) {
            _Src = (void *)(param_3 + (ulonglong)uVar8 * 2);
            memmove((void *)(param_3 + (ulonglong)((uVar8 - uVar3) + 8) * 2),_Src,
                    (ulonglong)(uVar3 - uVar8) * 2);
            memset(_Src,0,(ulonglong)(8 - uVar3) * 2);
          }
          return 0;
        }
      }
      else if ((uVar2 < 4) &&
              (ParseDec32bit(pcVar9,pcVar9 + uVar2,(int *)local_res8), local_res8[0] < 0x100)) {
        *(char *)((ulonglong)(uVar4 + local_res20 * 2) + param_3) = (char)local_res8[0];
        goto LAB_14000f6d9;
      }
    }
    else if (uVar7 == 2) {
      *(undefined2 *)(param_3 + uVar5 * 2) = 0;
      goto LAB_14000f6d9;
    }
  }
  return 0xc000000d;
}



===== ParseDec32bit @ 14000f73c =====

undefined8 ParseDec32bit(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (int)param_2 - (int)param_1;
  if (uVar2 < 10) {
LAB_14000f74f:
    iVar3 = 0;
    while( true ) {
      if (param_2 <= param_1) {
        *param_3 = iVar3;
        return 1;
      }
      cVar1 = *param_1;
      if (9 < (byte)(cVar1 - 0x30U)) break;
      param_1 = param_1 + 1;
      iVar3 = (int)cVar1 + (iVar3 * 5 + -0x18) * 2;
    }
    return 0;
  }
  if (uVar2 == 10) {
    if (*param_1 < '4') goto LAB_14000f74f;
  }
  else if (10 < uVar2) {
    return 0;
  }
  if (*param_1 < '5') {
    uVar2 = 0;
    while (param_1 = param_1 + 1, param_1 < param_2) {
      if (9 < (byte)(*param_1 - 0x30U)) {
        return 0;
      }
      uVar2 = (int)*param_1 + (uVar2 * 5 + -0x18) * 2;
    }
    if (uVar2 < 0x1194d800) {
      *param_3 = *param_3 + uVar2 + 4000000000;
      return 1;
    }
  }
  return 0;
}



===== ParseHex32bit @ 14000f7c4 =====

undefined8 ParseHex32bit(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  
  if ((longlong)param_2 - (longlong)param_1 < 9) {
    iVar4 = 0;
    for (; param_1 < param_2; param_1 = param_1 + 1) {
      cVar1 = *param_1;
      if (((9 < (byte)(cVar1 - 0x30U)) && (5 < (byte)(cVar1 + 0x9fU))) &&
         (5 < (byte)(cVar1 + 0xbfU))) goto LAB_14000f812;
      iVar2 = HexDigitValue(cVar1);
      iVar4 = iVar4 * 0x10 + iVar2;
    }
    *param_3 = iVar4;
    uVar3 = 1;
  }
  else {
LAB_14000f812:
    uVar3 = 0;
  }
  return uVar3;
}



===== __GSHandlerCheck @ 14000f828 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000f84c =====

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



===== __cpu_features_init @ 14000f8c0 =====

/* WARNING: Removing unreachable block (ram,0x00014000f92a) */
/* WARNING: Removing unreachable block (ram,0x00014000f8d9) */
/* WARNING: Removing unreachable block (ram,0x00014000f8ca) */

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



===== __security_check_cookie @ 14000f990 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000f9d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000fa00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000fa00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000fa30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14000fa60 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000faa3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000fb14;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000fb10:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000fb14;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000fb0c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000fb10;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000fb0c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_14000fb14:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_14000faa3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 14000fb80 =====

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



===== memset @ 14000fe80 =====

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



===== __memset_repmovs @ 14000ffc0 =====

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



===== __memset_query @ 140010040 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400100c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140010200 =====

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



===== __memset_spec_plain @ 140010280 =====

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



===== WppLoadTracingSupport @ 140018010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WppLoadTracingSupport(void)

{
  undefined1 auStack_58 [48];
  uint local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = 0;
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_20,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_20);
  RtlInitUnicodeString(&local_20,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_20);
  RtlInitUnicodeString(&local_20,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_20);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_28,0,0,0);
  }
  if (5 < local_28[0]) {
    RtlInitUnicodeString(&local_20,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_20);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_20,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_20);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppInitKm @ 140018180 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140018220 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  bool bVar3;
  
  ppuVar2 = &wil_details_featureDescriptors_a;
  while (*ppuVar2 == (undefined *)0x0) {
    ppuVar2 = ppuVar2 + 1;
    if (&UNK_1400146c7 < ppuVar2) {
      wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates();
      return;
    }
  }
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar3 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar3 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar3 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    if (&UNK_1400146c7 < ppuVar2) break;
    while (*ppuVar2 == (undefined *)0x0) {
      ppuVar2 = ppuVar2 + 1;
      if (&UNK_1400146c7 < ppuVar2) {
        wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates();
        return;
      }
    }
  }
  wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates();
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140018300 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  uVar3 = uVar6;
  if ((uVar6 >> 9 & 1) != 0) {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      while (puVar2 = (undefined8 *)*plVar5, puVar2 != (undefined8 *)0x0) {
        if ((*(char *)((longlong)puVar2 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar2 + 0x1d) == '\0')) {
          uVar3 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                            ((uint *)*puVar2,(longlong)puVar2);
          if ((uVar3 & 1) == 0) goto LAB_14001838f;
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        else {
          if (*(char *)((longlong)puVar2 + 0x1f) == '\0') {
LAB_14001838f:
            uVar4 = 0;
            break;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
      }
    }
    do {
      uVar3 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar3 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar3 & 0xfffffdff | uVar4;
      LOCK();
      uVar1 = *param_1;
      bVar7 = uVar6 == uVar1;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates @ 1400183e0 =====

void wil_details_EvaluateFeatureDependencies_UpdateFeatureEffectiveStates(void)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined **ppuVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  bool bVar10;
  
  ppuVar6 = &wil_details_featureDescriptors_a;
  while (*ppuVar6 == (undefined *)0x0) {
    ppuVar6 = ppuVar6 + 1;
    if (&UNK_1400146c7 < ppuVar6) {
      return;
    }
  }
  do {
    if (ppuVar6 == (undefined **)0x0) {
      return;
    }
    puVar1 = (uint *)*ppuVar6;
    uVar5 = *puVar1;
    uVar9 = (ulonglong)uVar5;
    if ((uVar5 >> 9 & 1) != 0) {
      uVar5 = uVar5 >> 6 & 1;
      if ((uVar5 != 0) && (plVar7 = (longlong *)ppuVar6[4], plVar7 != (longlong *)0x0)) {
        while (puVar2 = (undefined8 *)*plVar7, puVar2 != (undefined8 *)0x0) {
          if ((*(char *)((longlong)puVar2 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar2 + 0x1d) == '\0')) {
            uVar5 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                              ((uint *)*puVar2,(longlong)puVar2);
            if ((uVar5 & 1) == 0) {
LAB_140018494:
              uVar5 = 0;
              break;
            }
            uVar5 = 1;
            plVar7 = plVar7 + 1;
          }
          else {
            if (*(char *)((longlong)puVar2 + 0x1f) == '\0') goto LAB_140018494;
            uVar5 = 1;
            plVar7 = plVar7 + 1;
          }
        }
      }
      uVar4 = uVar9 & 0xffffffff;
      do {
        uVar8 = (uint)uVar9;
        if ((uVar8 & 1) == uVar5) {
          uVar4 = uVar9 & 0xffffffff;
        }
        uVar3 = uVar8 & 0xffffffce;
        if ((uVar8 & 1) == uVar5) {
          uVar3 = uVar8 & 0xfffffffe;
        }
        LOCK();
        uVar8 = *puVar1;
        bVar10 = (uint)uVar4 == uVar8;
        if (bVar10) {
          *puVar1 = uVar3 & 0xfffffdff | uVar5;
        }
        else {
          uVar4 = (ulonglong)uVar8;
        }
        UNLOCK();
        uVar9 = uVar4;
      } while (!bVar10);
    }
    ppuVar6 = ppuVar6 + 7;
    if (&UNK_1400146c7 < ppuVar6) {
      return;
    }
    while (*ppuVar6 == (undefined *)0x0) {
      ppuVar6 = ppuVar6 + 1;
      if (&UNK_1400146c7 < ppuVar6) {
        return;
      }
    }
  } while( true );
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140018520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  longlong lVar10;
  bool bVar11;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  short local_64 [2];
  undefined4 local_60 [10];
  ulonglong local_38;
  
  iVar4 = g_wil_details_featureUsageCached;
  if (param_1 != 1) {
    return;
  }
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  LOCK();
  g_wil_details_featureUsageCached = 0;
  UNLOCK();
  if (iVar4 == 0) {
    g_wil_details_featureUsageCached = 0;
    return;
  }
  ppuVar8 = &wil_details_featureDescriptors_a;
  while (*ppuVar8 == (undefined *)0x0) {
    ppuVar8 = ppuVar8 + 1;
    if (&wil_details_featureDescriptors_z <= ppuVar8) {
      g_wil_details_featureUsageCached = 0;
      return;
    }
  }
  if (ppuVar8 == (undefined **)0x0) {
    g_wil_details_featureUsageCached = 0;
    return;
  }
  do {
    if ((*(uint *)ppuVar8[1] & 1) != 0) {
      puVar3 = (uint *)ppuVar8[1];
      uVar2 = *(undefined4 *)(ppuVar8 + 3);
      uVar5 = *puVar3;
      do {
        LOCK();
        uVar7 = *puVar3;
        bVar11 = uVar5 == uVar7;
        if (bVar11) {
          *puVar3 = uVar5 & 0xffc0401e;
        }
        else {
          uVar5 = uVar7;
        }
        UNLOCK();
      } while (!bVar11);
      uVar6 = uVar5 >> 1 & 0xf;
      uVar7 = 0;
      if (uVar6 != 0) {
        uVar7 = puVar3[1];
        do {
          LOCK();
          uVar1 = puVar3[1];
          bVar11 = uVar7 == uVar1;
          if (bVar11) {
            puVar3[1] = uVar7 | uVar6;
          }
          else {
            uVar7 = uVar1;
          }
          UNLOCK();
        } while (!bVar11);
        uVar7 = uVar6 & ~uVar7;
      }
      puVar9 = &local_68;
      if ((uVar7 & 1) != 0) {
        puVar9 = local_60;
        local_64[0] = 2;
        local_64[1] = 1;
        local_68 = uVar2;
      }
      if ((uVar7 & 2) != 0) {
        *puVar9 = uVar2;
        puVar9[1] = 0x10006;
        puVar9 = puVar9 + 2;
      }
      if ((uVar7 & 4) != 0) {
        *puVar9 = uVar2;
        puVar9[1] = 0x10003;
        puVar9 = puVar9 + 2;
      }
      if (7 < uVar7) {
        *puVar9 = uVar2;
        puVar9[1] = 0x10007;
        puVar9 = puVar9 + 2;
      }
      if ((uVar5 >> 5 & 0x1ff) != 0) {
        *puVar9 = uVar2;
        *(ushort *)((longlong)puVar9 + 6) = (ushort)(uVar5 >> 5) & 0x1ff;
        *(ushort *)(puVar9 + 1) = ((ushort)(uVar5 >> 0xe) & 1) << 2;
        puVar9 = puVar9 + 2;
      }
      if ((uVar5 >> 0xf & 0x7f) != 0) {
        *puVar9 = uVar2;
        *(ushort *)((longlong)puVar9 + 6) = (ushort)(uVar5 >> 0xf) & 0x7f;
        *(ushort *)(puVar9 + 1) = ((ushort)(uVar5 >> 0x16) & 1) * 4 + 1;
        puVar9 = puVar9 + 2;
      }
      lVar10 = (longlong)puVar9 - (longlong)&local_68 >> 3;
      if (0 < lVar10) {
        RtlRecordFeatureUsage(&local_68,lVar10);
      }
    }
    ppuVar8 = ppuVar8 + 7;
    if (&UNK_1400146c7 < ppuVar8) {
      return;
    }
    while (*ppuVar8 == (undefined *)0x0) {
      ppuVar8 = ppuVar8 + 1;
      if (&UNK_1400146c7 < ppuVar8) {
        return;
      }
    }
  } while (ppuVar8 != (undefined **)0x0);
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140018770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar3 != (undefined *)0x0) {
      if (ppuVar3 != (undefined **)0x0) goto LAB_1400187c4;
      break;
    }
    ppuVar3 = ppuVar3 + 1;
  } while (ppuVar3 < &wil_details_featureDescriptors_z);
LAB_14001889e:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400187c4:
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_18 = 0;
    local_28 = 0;
    local_20 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_18,&local_28);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001885a:
      uVar2 = 0x206;
    }
    else if (iVar1 == 0) {
      uVar2 = ((local_28._4_4_ & 0x40) << 2 | local_28._4_4_ & 0xb0) << 3 | 0x206;
    }
    else {
      if (iVar1 != 0x117) goto LAB_14001885a;
      uVar2 = (local_28._4_4_ & 0x80) << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  if (&UNK_1400146c7 < ppuVar3) goto LAB_14001889e;
  while (*ppuVar3 == (undefined *)0x0) {
    ppuVar3 = ppuVar3 + 1;
    if (&UNK_1400146c7 < ppuVar3) goto LAB_14001889e;
  }
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001889e;
  goto LAB_1400187c4;
}



===== WppCleanupKm @ 1400188c4 =====

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



===== WppTraceCallback @ 140018950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,ulonglong param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  uVar5 = 0;
  *param_6 = 0;
  uVar10 = (uint)param_3;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_50 = 0;
      local_4c = 0;
      if (param_5 != 0) {
        if (uVar10 < 0x30) {
          return 0xc000000d;
        }
        uVar7 = (ulonglong)param_4[6];
        do {
          puVar9 = *(uint **)(param_5 + 8);
          if (((*puVar9 == param_4[6]) && (puVar9[1] == param_4[7])) &&
             ((puVar9[2] == param_4[8] && (puVar9[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
          }
          else {
            bVar13 = WPPTraceSuite == 2;
            uVar1 = *(undefined8 *)(param_4 + 2);
            *(undefined8 *)(param_5 + 0x18) = uVar1;
            local_58 = uVar1;
            if (bVar13) {
              local_68 = param_4;
              iVar4 = (*pfnWppQueryTraceInformation)(3,&local_50,4,&local_4c);
              if (iVar4 == 0) {
                *(undefined1 *)(param_5 + 0x29) = (undefined1)local_50;
              }
              uVar7 = param_5 + 0x2c;
              param_3 = 4;
              local_68 = param_4;
              uVar5 = (*pfnWppQueryTraceInformation)(2,uVar7,4,&local_4c);
            }
            else {
              local_58._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
              *(undefined4 *)(param_5 + 0x2c) = local_58._4_4_;
              local_58._2_1_ = (undefined1)((ulonglong)uVar1 >> 0x10);
              *(undefined1 *)(param_5 + 0x29) = local_58._2_1_;
            }
          }
          MpsTracingEnableCallback
                    (*(longlong **)(param_5 + 8),uVar7,param_3,*(undefined4 *)(param_5 + 0x2c));
          return uVar5;
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
      puVar2 = *(ushort **)(param_5 + 0x20);
      uVar8 = 0;
      lVar6 = param_5;
      do {
        lVar6 = *(longlong *)(lVar6 + 0x10);
        uVar8 = uVar8 + 1;
      } while (lVar6 != 0);
      if (0x3f < uVar8) {
        return 0xc000000d;
      }
      uVar11 = uVar8 * 0x20 + 0x18;
      if (puVar2 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar2 + 2 + uVar11;
      }
      if (uVar10 < uVar12) {
        if (uVar10 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,param_3 & 0xffffffff);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar8;
      if (puVar2 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar2;
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar2 + 4),
                (ulonglong)*puVar2);
      }
      if (uVar8 != 0) {
        uVar7 = (ulonglong)uVar8;
        puVar9 = param_4 + 10;
        do {
          uVar1 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar1;
          *(undefined8 *)(puVar9 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar7 = uVar7 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar7 != 0);
      }
      *param_6 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== entry @ 140019010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140019044 =====

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



===== wil_InitializeFeatureStaging @ 140019080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_18 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar3 = &wil_details_featureDescriptors_a;
    do {
      if (*ppuVar3 != (undefined *)0x0) {
        if (ppuVar3 != (undefined **)0x0) goto LAB_1400190f6;
        break;
      }
      ppuVar3 = ppuVar3 + 1;
    } while (ppuVar3 < &wil_details_featureDescriptors_z);
LAB_14001915a:
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
LAB_1400190f6:
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_18,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_14001915a;
  }
  ppuVar3 = ppuVar3 + 7;
  if (&UNK_1400146c7 < ppuVar3) goto LAB_14001915a;
  while (*ppuVar3 == (undefined *)0x0) {
    ppuVar3 = ppuVar3 + 1;
    if (&UNK_1400146c7 < ppuVar3) goto LAB_14001915a;
  }
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001915a;
  goto LAB_1400190f6;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400191c0 =====

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
  uint uStack_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &wil_details_featureDescriptors_a;
  while (*ppuVar4 == (undefined *)0x0) {
    ppuVar4 = ppuVar4 + 1;
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
  }
  if (ppuVar4 == (undefined **)0x0) {
    return;
  }
  do {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,
                         &stack0xffffffffffffffe0);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          if (&UNK_1400146c7 < ppuVar4) {
            return;
          }
          while (*ppuVar4 == (undefined *)0x0) {
            ppuVar4 = ppuVar4 + 1;
            if (&UNK_1400146c7 < ppuVar4) {
              return;
            }
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1400192c8;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((uStack_1c & 0x40) << 2 | uStack_1c & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1400192c8;
        local_28 = (ulonglong)((uStack_1c & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1400192c8:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    if (&UNK_1400146c7 < ppuVar4) {
      return;
    }
    while (*ppuVar4 == (undefined *)0x0) {
      ppuVar4 = ppuVar4 + 1;
      if (&UNK_1400146c7 < ppuVar4) {
        return;
      }
    }
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
  } while( true );
}


