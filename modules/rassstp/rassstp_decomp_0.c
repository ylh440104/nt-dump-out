
===== SmpCoRequest @ 140001010 =====

ulonglong SmpCoRequest(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      uVar2 = SetInformation(param_3 + 0x34,param_2,
                             (undefined *)(ulonglong)*(uint *)(param_3 + 0x20),
                             *(undefined8 **)(param_3 + 0x28),*(uint *)(param_3 + 0x30),
                             (undefined4 *)(param_3 + 0x34),(undefined4 *)(param_3 + 0x38));
      return CONCAT44(extraout_var,uVar2);
    }
    if (iVar1 != 2) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                       &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,param_2 + 0x1e4,(char)iVar1)
        ;
      }
      return 0xc00000bb;
    }
  }
  uVar3 = QueryInformation(param_1,param_2,*(uint *)(param_3 + 0x20),*(void **)(param_3 + 0x28),
                           *(uint *)(param_3 + 0x30),(uint *)(param_3 + 0x34),
                           (uint *)(param_3 + 0x38));
  return uVar3;
}



===== QueryInformation @ 1400010e0 =====

undefined8
QueryInformation(longlong param_1,longlong param_2,uint param_3,void *param_4,uint param_5,
                uint *param_6,uint *param_7)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 *_Src;
  undefined4 local_res18 [2];
  
  uVar3 = 0;
  _Src = local_res18;
  local_res18[0] = 0;
  uVar2 = 4;
  if (param_3 < 0x4010181) {
    if (param_3 == 0x4010180) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
      _Src = (undefined4 *)(param_1 + 0x20);
      uVar2 = 0x10;
    }
    else if (param_3 == 0x1010c) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
      local_res18[0] = 0xffffffff;
      uVar2 = 3;
    }
    else if (param_3 == 0x10111) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
      local_res18[0] = 0xffb;
    }
    else {
      if (param_3 != 0x4010105) goto LAB_14000113f;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
      local_res18[0] = 0xd;
    }
LAB_140001146:
    if (param_5 < uVar2) {
      uVar3 = 0xc0010014;
      goto LAB_14000115f;
    }
    if (uVar2 != 0) {
      memmove(param_4,_Src,(ulonglong)uVar2);
    }
  }
  else {
    if (param_3 == 0x4010182) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
      if (param_2 == 0) {
        return 0xc0010015;
      }
      _Src = (undefined4 *)(param_2 + 0x1238);
      uVar2 = 0x20;
      goto LAB_140001146;
    }
    if (param_3 == 0xfd010102) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar1 = 0x2a;
LAB_140001356:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
                &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
      }
    }
    else {
      if (param_3 != 0xfd010100) {
LAB_14000113f:
        uVar3 = 0xc00000bb;
        uVar2 = 0;
        goto LAB_140001146;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar1 = 0x29;
        goto LAB_140001356;
      }
    }
    uVar2 = 0;
  }
  *param_6 = uVar2;
LAB_14000115f:
  *param_7 = uVar2;
  return uVar3;
}



===== SetInformation @ 1400013e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
SetInformation(undefined8 param_1,longlong param_2,undefined *param_3,undefined8 *param_4,
              uint param_5,undefined4 *param_6,undefined4 *param_7)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  int iVar6;
  UCHAR *pUVar7;
  undefined1 auStackY_88 [32];
  undefined4 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  undefined8 local_58;
  undefined8 uStack_50;
  UCHAR local_48 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  puVar5 = (undefined8 *)0x0;
  uVar3 = 0;
  uVar4 = 0;
  iVar6 = (int)param_3;
  if (iVar6 == 0x4010181) {
    uVar2 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
    if (((((int)uVar2 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                    &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,param_2 + 0x1e4);
    }
    if (param_5 < 0x20) {
      uVar4 = 0xc0010014;
    }
    else {
      if (param_2 == 0) {
        return 0xc0010015;
      }
      uVar2 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                      &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,param_2 + 0x1e4);
      }
      uVar1 = param_4[1];
      uVar3 = 0x20;
      *(undefined8 *)(param_2 + 0x1238) = *param_4;
      *(undefined8 *)(param_2 + 0x1240) = uVar1;
      uVar1 = param_4[3];
      *(undefined8 *)(param_2 + 0x1248) = param_4[2];
      *(undefined8 *)(param_2 + 0x1250) = uVar1;
      uVar4 = 0;
    }
    *param_6 = uVar3;
    *param_7 = 0x20;
  }
  else {
    if (iVar6 != 0x4010281) {
      *param_7 = 0;
      *param_6 = 0;
      uVar4 = 0;
      if (iVar6 != -0x2fefeff) {
        uVar4 = 0xc00000bb;
      }
      return uVar4;
    }
    local_58 = 0;
    uStack_50 = 0;
    pUVar7 = (UCHAR *)0x0;
    local_48[0] = '\0';
    local_48[1] = '\0';
    local_48[2] = '\0';
    local_48[3] = '\0';
    local_48[4] = '\0';
    local_48[5] = '\0';
    local_48[6] = '\0';
    local_48[7] = '\0';
    local_48[8] = '\0';
    local_48[9] = '\0';
    local_48[10] = '\0';
    local_48[0xb] = '\0';
    local_48[0xc] = '\0';
    local_48[0xd] = '\0';
    local_48[0xe] = '\0';
    local_48[0xf] = '\0';
    uVar2 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar2 != 0) && (param_2 == 0)) {
      return 0xc0010015;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                    &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,param_2 + 0x1e4);
    }
    if (*(int *)((longlong)param_4 + 0x44) == 2) {
      GenerateMsChapV2MasterSessionKey
                ((longlong)param_4,&local_58,param_3,local_48,
                 CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
                 *(char *)(param_2 + 0x1f9));
      uVar3 = 0x10;
      puVar5 = &local_58;
      pUVar7 = local_48;
    }
    else if (*(int *)((longlong)param_4 + 0x44) == 3) {
      uVar3 = *(undefined4 *)((longlong)param_4 + 0x74);
      puVar5 = param_4 + 0xf;
      pUVar7 = (UCHAR *)(param_4 + 0x3d);
    }
    else {
      uVar3 = 0;
    }
    if (*(char *)(param_2 + 0x1fa) == '\0') {
      (**(code **)(SstpGlobals + 0x230))(param_2,puVar5,uVar3,pUVar7);
    }
  }
  return uVar4;
}



===== DelineateSSTPFrame @ 140001640 =====

undefined8
DelineateSSTPFrame(uint *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                  char *param_5,uint param_6)

{
  uint uVar1;
  ulonglong uVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  
LAB_140001667:
  do {
    while( true ) {
      if (param_6 == 0) {
        return 0;
      }
      uVar1 = param_1[1];
      if (uVar1 != 0) break;
      if (*param_1 != 4) {
        return 0xc0000184;
      }
      if (param_6 < 4) {
        param_1[1] = 1;
        memmove(param_1 + 3,param_5,(ulonglong)param_6);
        *param_1 = *param_1 - param_6;
        param_1[2] = param_6;
        param_6 = 0;
        *(undefined1 *)(param_1 + 4) = 1;
      }
      else {
        bVar4 = param_5[1] & 1;
        uVar5 = (ushort)(*(ushort *)(param_5 + 2) >> 8 | *(ushort *)(param_5 + 2) << 8) & 0xfff;
        uVar2 = SstpValidateSstpHeader(param_5,bVar4);
        if ((char)uVar2 == '\0') {
          return 0xc0000184;
        }
        if (param_6 < uVar5) {
          if (bVar4 == 0) {
            *(undefined1 *)((longlong)param_1 + 0x11) = 1;
            DelinProcessSstpDataFrame(param_5 + 4,param_6 - 4,(longlong)param_5,param_2,'\x01','\0')
            ;
            param_1[1] = 2;
          }
          else {
            param_1[1] = 3;
            memmove((void *)((longlong)param_1 + 0x12),param_5,(ulonglong)param_6);
            param_1[2] = param_6;
          }
          *param_1 = uVar5 - param_6;
          param_6 = 0;
        }
        else if (bVar4 == 0) {
          DelinProcessSstpDataFrame(param_5 + 4,uVar5 - 4,(longlong)param_5,param_2,'\0','\0');
          param_5 = param_5 + uVar5;
          param_6 = param_6 - uVar5;
        }
        else {
          DelinProcessSstpControlFrame(param_5,(short)uVar5,param_2);
LAB_140001770:
          param_5 = param_5 + uVar5;
          param_6 = param_6 - uVar5;
        }
      }
    }
    if (uVar1 != 1) {
      if (uVar1 == 2) {
        uVar1 = *param_1;
        puVar6 = (uint *)0x0;
        cVar3 = *(char *)((longlong)param_1 + 0x11);
        uVar5 = uVar1;
        if (param_6 < uVar1) {
          uVar5 = param_6;
        }
        if ((cVar3 == '\0') && (uVar1 != uVar5)) {
          *(undefined1 *)((longlong)param_1 + 0x11) = 1;
          cVar3 = '\x01';
        }
        if ((char)param_1[4] != '\0') {
          puVar6 = param_1 + 3;
          *(undefined1 *)(param_1 + 4) = 0;
        }
        *param_1 = uVar1 - uVar5;
        DelinProcessSstpDataFrame(param_5,uVar5,(longlong)puVar6,param_2,cVar3,uVar1 - uVar5 == 0);
        if (*param_1 == 0) {
          param_1[0] = 4;
          param_1[1] = 0;
          *(undefined2 *)(param_1 + 4) = 0;
          param_1[2] = 0;
        }
        goto LAB_140001770;
      }
      if (uVar1 == 3) {
        uVar1 = *param_1;
        uVar5 = uVar1;
        if (param_6 < uVar1) {
          uVar5 = param_6;
        }
        *param_1 = uVar1 - uVar5;
        memmove((void *)((ulonglong)param_1[2] + 0x12 + (longlong)param_1),param_5,(ulonglong)uVar5)
        ;
        uVar1 = param_1[2];
        param_6 = param_6 - uVar5;
        param_5 = param_5 + uVar5;
        param_1[2] = uVar1 + uVar5;
        if (*param_1 == 0) {
          DelinProcessSstpControlFrame((longlong)param_1 + 0x12,(short)(uVar1 + uVar5),param_2);
          param_1[0] = 4;
          param_1[1] = 0;
          *(undefined2 *)(param_1 + 4) = 0;
          param_1[2] = 0;
        }
      }
      goto LAB_140001667;
    }
    uVar1 = *param_1;
    uVar5 = uVar1;
    if (param_6 < uVar1) {
      uVar5 = param_6;
    }
    *param_1 = uVar1 - uVar5;
    memmove((void *)((ulonglong)param_1[2] + 0xc + (longlong)param_1),param_5,(ulonglong)uVar5);
    param_1[2] = param_1[2] + uVar5;
    param_6 = param_6 - uVar5;
    param_5 = param_5 + uVar5;
    if (*param_1 == 0) {
      bVar4 = *(byte *)((longlong)param_1 + 0xd) & 1;
      uVar2 = SstpValidateSstpHeader((char *)(param_1 + 3),bVar4);
      if ((char)uVar2 == '\0') {
        return 0xc0000184;
      }
      *param_1 = ((ushort)(*(ushort *)((longlong)param_1 + 0xe) >> 8 |
                          *(ushort *)((longlong)param_1 + 0xe) << 8) & 0xfff) - 4;
      if (bVar4 == 0) {
        *(undefined1 *)(param_1 + 4) = 1;
        param_1[1] = 2;
      }
      else {
        *(uint *)((longlong)param_1 + 0x12) = param_1[3];
        param_1[2] = 4;
        param_1[1] = 3;
      }
    }
  } while( true );
}



===== DereferenceRefCount @ 140001930 =====

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



===== TpiDispatchDeviceControl @ 140001960 =====

int TpiDispatchDeviceControl(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined *_Size;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  _Size = (undefined *)0x0;
  if (*(longlong *)(lVar2 + 0x30) == *(longlong *)(SstpGlobals + 0x10)) {
    uVar1 = *(uint *)(lVar2 + 0x18);
    if (((uVar1 & 3) == 0) || ((uVar1 & 3) == 2)) {
      _Size = (undefined *)(ulonglong)*(uint *)(lVar2 + 8);
    }
    if (uVar1 == 0x12803c) {
      iVar3 = ProcessQueueForSendNotification(param_2);
    }
    else if (uVar1 == 0x128018) {
      iVar3 = ProcessMakeCallCompleteRequest(param_2);
    }
    else if (uVar1 == 0x12801c) {
      iVar3 = ProcessDisconnectCallRequest(param_2);
    }
    else if (uVar1 == 0x128028) {
      iVar3 = ProcessIncomingCallRequest(param_2,lVar2,_Size);
    }
    else {
      if (uVar1 != 0x12802c) {
        if (uVar1 == 0x128038) {
          memset(*(void **)(param_2 + 0x18),0,(size_t)_Size);
          IoCsqInsertIrp(SstpGlobals + 0x40,param_2,0);
          return 0x103;
        }
        goto LAB_140001988;
      }
      iVar3 = ProcessIncomingCallConnectedRequest(param_2);
    }
    if (iVar3 == 0x103) {
      return 0x103;
    }
  }
  else {
LAB_140001988:
    iVar3 = -0x3fffff45;
  }
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== ScmCmRequest @ 140001a60 =====

undefined8 ScmCmRequest(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (*(int *)(param_4 + 4) == 0) {
    uVar1 = QueryCmInformation(param_2,*(int *)(param_4 + 0x20),*(undefined4 **)(param_4 + 0x28),
                               *(uint *)(param_4 + 0x30),(uint *)(param_4 + 0x34),
                               (uint *)(param_4 + 0x38));
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== QueryCmInformation @ 140001ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
QueryCmInformation(longlong param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5,
                  uint *param_6)

{
  undefined8 *_Src;
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_338 [32];
  undefined4 local_318 [2];
  longlong local_310;
  undefined4 local_308;
  undefined4 uStack_304;
  undefined4 local_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 local_2d8;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_25c;
  undefined4 local_1c4;
  undefined8 local_1ac;
  undefined2 local_1a4;
  undefined8 local_128;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_c8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_338;
  local_308 = 0;
  uStack_304 = 0;
  local_300 = 0;
  local_310 = param_1;
  memset(&local_2d8,0,0x1b0);
  memset(&local_128,0,0xf0);
  uVar1 = 0;
  _Src = (undefined8 *)local_318;
  local_318[0] = 0;
  uVar2 = 0;
  local_2f8 = 0;
  if (param_2 == -0x1ffeffe) {
    if (0x1af < param_4) {
      local_2d8._0_4_ = *param_3;
      _Src = &local_2d8;
      local_2d0 = param_3[2];
      local_1a4 = 0;
      uVar1 = 0x1b0;
      local_1ac = 0x50005400530053;
      local_2cc = 0x1a8;
      local_2c8 = 0x1a8;
      local_2b0 = 10;
      local_2ac = 0x124;
      local_2a8 = 3;
      local_2a0 = 1;
      local_29c = 8;
      local_298 = 100000000;
      local_294 = 0x102;
      local_25c = 1;
      local_1c4 = 0x10;
      local_2b4 = (undefined4)local_2d8;
      goto LAB_140001ce4;
    }
LAB_140001b8e:
    uVar2 = 0xc0010015;
  }
  else if (param_2 == -0x1ffeffd) {
    if (param_4 < 0xf0) goto LAB_140001b8e;
    local_128._0_4_ = *param_3;
    _Src = &local_128;
    local_128._4_4_ = param_3[1];
    uVar1 = 0xf0;
    local_11c = 0xe4;
    local_c8 = *(undefined4 *)(SstpGlobals + 0xc0);
    local_118 = 0xe4;
    local_114 = 0xe4;
    local_110 = (undefined4)local_128;
LAB_140001ce4:
    local_2e8 = 0;
    uStack_2f0 = 0;
    memmove(param_3,_Src,(ulonglong)uVar1);
  }
  else {
    if (param_2 == -0x1ffefff) {
      uStack_304 = 1;
      local_300 = 0;
      _Src = (undefined8 *)&local_308;
      local_308 = 0x30000;
      uVar1 = 0xc;
    }
    else if (param_2 == -0x1ffeff9) {
      if (local_310 == 0) goto LAB_140001b8e;
      _Src = &local_2f8;
      local_2f8 = 0x100000001;
      uVar1 = 0x18;
    }
    else {
      uVar2 = 0xc00000bb;
    }
    if (param_4 < uVar1) {
      uVar2 = 0xc0010014;
      goto LAB_140001cf5;
    }
    if (uVar1 != 0) goto LAB_140001ce4;
  }
  *param_5 = uVar1;
LAB_140001cf5:
  *param_6 = uVar1;
  return uVar2;
}



===== SmpPause @ 140001d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SmpPause(int *param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
  param_1[4] = 3;
  KeReleaseSpinLock(param_1 + 0xe,uVar2);
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(param_1 + 2))(param_1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  return 0x103;
}



===== DoDerefMiniportAdapterBlockWork @ 140001e10 =====

void DoDerefMiniportAdapterBlockWork(longlong param_1)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x10) = 1;
  KeReleaseSpinLock(param_1 + 0x38,uVar1);
  NdisMPauseComplete(*(undefined8 *)(param_1 + 0x18));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  return;
}



===== SmpRestart @ 140001ee0 =====

undefined8 SmpRestart(int *param_1)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
  *param_1 = 0;
  *(code **)(param_1 + 2) = DoDerefMiniportAdapterBlockWork;
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  param_1[4] = 2;
  KeReleaseSpinLock(param_1 + 0xe,uVar1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  return 0;
}



===== ScmCmCloseAf @ 140001fb0 =====

undefined8 ScmCmCloseAf(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  *(undefined8 *)(SstpGlobals + 0x30) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return 0;
}



===== SstpTimerPeriodicDpc @ 140002040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SstpTimerPeriodicDpc(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  char local_res10 [8];
  undefined1 local_37 [7];
  code *local_30;
  
  lVar9 = 0;
  lVar8 = (param_2 & 0xffffffff) * 0x3d8 + DAT_14000b248;
  lVar1 = lVar8 + 0x98;
  RtlUpdateCurrentTimerWheelTick
            (lVar1,(_DAT_fffff78000000008 / 10000) / (ulonglong)DAT_14000b250 & 0xffffffff);
  KeAcquireSpinLockAtDpcLevel(lVar8 + 0x3d0);
  lVar2 = lVar8 + 0x80;
  KeAcquireSpinLockAtDpcLevel(lVar2);
  lVar6 = RtlGetNextExpiredTimerWheelEntry(lVar1);
  if (lVar6 == 0) {
    KeReleaseSpinLockFromDpcLevel(lVar2);
    KeReleaseSpinLockFromDpcLevel(lVar8 + 0x3d0);
    return;
  }
  do {
    bVar5 = false;
    local_res10[0] = '\0';
    local_37[0] = 0;
    KeAcquireSpinLockAtDpcLevel(lVar6 + -8);
    KeReleaseSpinLockFromDpcLevel(lVar2);
    if ((*(int *)(lVar6 + 0x14) == 0) || (0 < *(int *)(lVar6 + 0x14) - *(int *)(lVar6 + 0x10))) {
      KeReleaseSpinLockFromDpcLevel(lVar6 + -8);
    }
    else {
      local_30 = *(code **)(lVar6 + -0x18);
      lVar4 = *(longlong *)(lVar6 + -0x10);
      if (lVar9 == 0) {
        LOCK();
        *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 0x20) + 1;
        UNLOCK();
        lVar9 = lVar4;
      }
      bVar5 = true;
      *(undefined4 *)(lVar6 + 0x14) = 0;
      *(undefined1 *)(lVar6 + -0x1f) = 0;
      KeReleaseSpinLockFromDpcLevel(lVar6 + -8);
      if (local_30 != (code *)0x0) {
        (*local_30)(lVar4,local_res10);
      }
    }
    if (local_res10[0] == '\0') {
      KeAcquireSpinLockAtDpcLevel(lVar2);
      KeAcquireSpinLockAtDpcLevel(lVar6 + -8);
      RtlReturnTimerWheelEntry(lVar1);
      if (bVar5) {
        if (((*(char *)(lVar6 + -0x20) == '\0') || (*(char *)(lVar6 + -0x1f) != '\0')) &&
           (uVar3 = *(uint *)(lVar6 + -0x1c), uVar3 != 0)) {
          uVar7 = RtlStartTimerWheelEntryTimer
                            (lVar6,(ulonglong)uVar3 % (ulonglong)DAT_14000b250,
                             uVar3 / DAT_14000b250 + *(int *)(lVar8 + 0x9c));
          if ((char)uVar7 != '\0') {
            RtlIndicateTimerWheelEntryTimerStart(lVar1,lVar6);
          }
        }
        else {
          RtlCleanupTimerWheelEntry(lVar1,lVar6,local_37);
        }
      }
      KeReleaseSpinLockFromDpcLevel(lVar6 + -8);
      KeReleaseSpinLockFromDpcLevel(lVar2);
    }
    KeAcquireSpinLockAtDpcLevel(lVar2);
    lVar6 = RtlGetNextExpiredTimerWheelEntry(lVar1);
  } while (lVar6 != 0);
  KeReleaseSpinLockFromDpcLevel(lVar2);
  KeReleaseSpinLockFromDpcLevel(lVar8 + 0x3d0);
  if (lVar9 != 0) {
    DereferenceRefCount((int *)(lVar9 + 0x20));
  }
  return;
}



===== ScmCmOpenAf @ 140002310 =====

undefined8 ScmCmOpenAf(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  *(undefined8 *)(SstpGlobals + 0x30) = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return 0;
}



===== InitiateSstpContextCleanup @ 1400023a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InitiateSstpContextCleanup(int *param_1,int param_2,undefined *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  int *piVar8;
  undefined *puVar9;
  bool bVar10;
  
  bVar3 = (byte)param_3;
  puVar9 = param_3;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82) {
      puVar9 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,puVar9,param_1 + 0x79,
                      (char)param_2,(char)param_1[0x496]);
    }
  }
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  uVar5 = param_1[0x496];
  if (uVar5 == 0) {
    KeReleaseSpinLock(param_1 + 8,(ulonglong)param_3 & 0xff);
    goto LAB_140002bae;
  }
  if ((char)param_1[0x497] == '\0') {
    *(undefined1 *)(param_1 + 0x497) = 1;
  }
  if ((uVar5 & 0x40) != 0) {
    uVar5 = uVar5 & 0xffffffbf;
    param_1[0x496] = uVar5;
    if (param_2 != 1) {
      param_1[0x496] = uVar5 | 0x800;
      KeReleaseSpinLock(param_1 + 8,(ulonglong)param_3 & 0xff);
      puVar9 = (undefined *)0x0;
      NdisCmDispatchIncomingCloseCall(0,*(undefined8 *)(param_1 + 10),0,0);
      bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
      param_1[0x496] = param_1[0x496] & 0xfffff7ff;
      uVar5 = param_1[0x496];
    }
  }
  if ((uVar5 >> 0xb & 1) == 0) {
    if ((uVar5 & 4) == 0) {
LAB_1400025ad:
      if (((char)param_1[0x4a1] == '\0') && ((uVar5 >> 9 & 1) != 0)) goto LAB_140002b95;
    }
    else {
      uVar5 = uVar5 & 0xfffffffb | 0x200;
      param_1[0x496] = uVar5;
      if ((char)param_1[0x4a1] == '\0') {
        KeReleaseSpinLock(param_1 + 8,bVar3);
        puVar9 = (undefined *)0x0;
        iVar6 = (**(code **)(SstpGlobals + 0x218))(param_1,param_2 != 1,0,param_2 == 1);
        if (iVar6 == 0x103) goto LAB_140002bae;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar9 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
        }
        bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
        param_1[0x496] = param_1[0x496] & 0xfffffdff;
        uVar5 = param_1[0x496];
        goto LAB_1400025ad;
      }
    }
    if (param_1[0xc] == 0) {
      if ((uVar5 & 0x10) != 0) {
        *(undefined1 *)((longlong)param_1 + 0x1fb) = 0;
        param_1[0x496] = uVar5 & 0xffffffef | 0x400;
        KeReleaseSpinLock(param_1 + 8,bVar3);
        iVar6 = NdisMCmDeactivateVc(*(undefined8 *)(param_1 + 10));
        if (iVar6 != 0x103) {
          ScmCmDeactivateVcComplete((char)iVar6,(longlong)param_1);
        }
        goto LAB_140002bae;
      }
      if (((uVar5 >> 10 & 1) == 0) && ((uVar5 & 8) == 0)) {
        if ((uVar5 & 2) != 0) {
          param_1[0x496] = uVar5 & 0xfffffffd;
          KeReleaseSpinLock(param_1 + 8,bVar3);
          (**(code **)(SstpGlobals + 0x218))(param_1,1,0,param_2 == 1);
          goto LAB_140002bae;
        }
        if ((uVar5 >> 0x12 & 1) != 0) {
          param_1[0x496] = uVar5 & 0xfffbffff;
          bVar10 = (uVar5 >> 0x13 & 1) != 0;
          if (bVar10) {
            param_1[0x496] = uVar5 & 0xfff3ffff;
          }
          KeReleaseSpinLock(param_1 + 8,bVar3);
          (**(code **)(SstpGlobals + 0x218))(param_1,1,0,bVar10);
          DereferenceRefCount(param_1);
          goto LAB_140002bae;
        }
        if ((uVar5 & 0x20) != 0) {
          lVar1 = *(longlong *)(param_1 + 0x12);
          param_1[0x12] = 0;
          param_1[0x13] = 0;
          param_1[0x496] = uVar5 & 0xffffffdf;
          if ((lVar1 != 0) && (uVar7 = RemoveCancelRoutineSafe(lVar1), (char)uVar7 != '\0')) {
            *(char *)(*(longlong *)(lVar1 + 0x18) + 4) = (char)param_1[0x7f];
            *(undefined4 *)(lVar1 + 0x30) = 0;
            *(undefined8 *)(lVar1 + 0x38) = 8;
            KeReleaseSpinLock(param_1 + 8,bVar3);
            IofCompleteRequest(lVar1,0);
            DereferenceRefCount(param_1);
            bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
          }
        }
        uVar5 = param_1[0x496];
        if ((uVar5 >> 8 & 1) == 0) {
          if ((uVar5 >> 0xd & 1) != 0) {
            if ((*(char *)(SstpGlobals + 0x238) != '\0') && ((uVar5 >> 0xc & 1) == 0))
            goto LAB_140002b95;
            uVar5 = uVar5 & 0xffffdfff;
            param_1[0x496] = uVar5;
          }
          if ((uVar5 >> 0xe & 1) != 0) {
            uVar5 = uVar5 & 0xffffbfff;
            param_1[0x496] = uVar5;
            if ((char)param_1[0x4a1] == '\0') {
              KeReleaseSpinLock(param_1 + 8,bVar3);
              puVar9 = (undefined *)0x0;
              NdisCmMakeCallComplete
                        (param_1[0x498],*(undefined8 *)(param_1 + 10),0,0,
                         *(undefined8 *)(param_1 + 0x48c));
              bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
              uVar5 = param_1[0x496];
            }
            param_1[0x48c] = 0;
            param_1[0x48d] = 0;
          }
          if ((uVar5 >> 0x10 & 1) == 0) {
            KeAcquireSpinLockAtDpcLevel(SstpGlobals + 0x1f0);
            HfSuspendHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),param_1[0x1c]);
            KeReleaseSpinLockFromDpcLevel(SstpGlobals + 0x1f0);
            if (((uint)param_1[0x496] >> 0xc & 1) != 0) {
              param_1[0x496] = param_1[0x496] & 0xffffefff;
              KeReleaseSpinLock(param_1 + 8,bVar3);
              puVar9 = (undefined *)0x0;
              NdisCmCloseCallComplete(0,*(undefined8 *)(param_1 + 10));
              bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
              if (((uint)param_1[0x496] >> 0x14 & 1) != 0) {
                param_1[0x496] = param_1[0x496] & 0xffefffff;
                KeReleaseSpinLock(param_1 + 8,bVar3);
                DereferenceRefCount(param_1);
                bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
              }
              uVar7 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
              if (((int)uVar7 != 0) && (((uint)param_1[0x496] >> 0x15 & 1) != 0)) {
                param_1[0x496] = param_1[0x496] & 0xffdfffff;
                KeReleaseSpinLock(param_1 + 8,bVar3);
                DereferenceRefCount(param_1);
                bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
              }
            }
            uVar5 = param_1[0x496];
            if ((uVar5 >> 0xf & 1) == 0) {
              if ((uVar5 & 1) != 0) {
                param_1[0x496] = uVar5 & 0xfffffffe | 0x8000;
                KeReleaseSpinLock(param_1 + 8,bVar3);
                uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
                puVar2 = *(undefined8 **)(param_1 + 0x18);
                while (puVar2 != (undefined8 *)0x0) {
                  *(undefined8 *)(param_1 + 0x18) = *puVar2;
                  if (*(char *)(puVar2 + 1) == '\0') {
                    *(undefined4 *)((longlong)puVar2 + 0x2c) = 0xc0000001;
                    KeReleaseSpinLock(param_1 + 8,uVar4);
                    puVar9 = (undefined *)0x0;
                    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 10),puVar2 + -0xc);
                    lVar1 = SstpGlobals;
                    piVar8 = (int *)(SstpGlobals + 0x90);
                    LOCK();
                    iVar6 = *piVar8;
                    *piVar8 = *piVar8 + -1;
                    UNLOCK();
                    if (iVar6 == 1) {
                      (**(code **)(lVar1 + 0x98))();
                    }
                    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
                  }
                  else {
                    (**(code **)(SstpGlobals + 0x220))();
                  }
                  puVar2 = *(undefined8 **)(param_1 + 0x18);
                }
                KeReleaseSpinLock(param_1 + 8,uVar4);
                bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
                param_1[0x496] = param_1[0x496] & 0xffff7fff;
                if (*(longlong *)(param_1 + 0x48c) != 0) {
                  ExFreePoolWithTag(*(longlong *)(param_1 + 0x48c),0x6d704353);
                }
                param_1[0x48c] = 0;
                param_1[0x48d] = 0;
                if (((*(char *)((longlong)param_1 + 0x229) != '\0') && (param_1[0x86] != 0)) &&
                   (*(longlong *)(param_1 + 0x80) != 0)) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    puVar9 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                             &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1[0x86]);
                  }
                  KeReleaseSpinLock(param_1 + 8,bVar3);
                  NdisFreeNetBufferList(*(undefined8 *)(param_1 + 0x80));
                  bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
                  param_1[0x80] = 0;
                  param_1[0x81] = 0;
                  param_1[0x82] = 0;
                  param_1[0x83] = 0;
                }
                if (*(char *)((longlong)param_1 + 0x1f9) != '\0') {
                  uVar7 = (ulonglong)bVar3;
                  KeReleaseSpinLock(param_1 + 8);
                  NdisMCmDeleteVc(*(undefined8 *)(param_1 + 10));
                  ScmCmDeleteVc(param_1,uVar7,puVar9);
                  bVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
                }
              }
              if (param_1[0x496] == 0x200) {
                param_1[0x496] = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_140002b95:
  KeReleaseSpinLock(param_1 + 8,bVar3);
LAB_140002bae:
  LOCK();
  iVar6 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar6 == 1) {
    (**(code **)(param_1 + 2))(param_1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== _guard_check_icall @ 140002c20 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 140002c40 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140002c4d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140002c4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== InitializeIrpQueue @ 140002c60 =====

void InitializeIrpQueue(longlong param_1)

{
  longlong lVar1;
  
  KeInitializeSpinLock();
  IoCsqInitialize(param_1 + 8,CsqInsertIrp,CsqRemoveIrp,CsqPeekNextIrp,CsqAcquireLock,CsqReleaseLock
                  ,CsqCompleteCanceledIrp);
  lVar1 = param_1 + 0x48;
  *(longlong *)(param_1 + 0x50) = lVar1;
  *(longlong *)lVar1 = lVar1;
  return;
}



===== WPP_SF_ @ 140002cd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140002d04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140002d50 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140002d84 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000a817 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140002dac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002f00 =====

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



===== CngRsa32Compat_SHAFinal @ 140002f84 =====

void CngRsa32Compat_SHAFinal(undefined8 *param_1,PUCHAR param_2)

{
  BCRYPT_HASH_HANDLE hHash;
  code *pcVar1;
  NTSTATUS NVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  if (param_2 != (PUCHAR)0x0) {
    NVar2 = BCryptFinishHash((BCRYPT_HASH_HANDLE)*param_1,param_2,0x14,0);
    puVar3 = auStack_28;
    if (NVar2 < 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(7);
      puVar3 = auStack_20;
    }
  }
  hHash = (BCRYPT_HASH_HANDLE)*param_1;
  *(undefined8 *)(puVar3 + -8) = 0x140002fbd;
  BCryptDestroyHash(hHash);
  *param_1 = 0;
  return;
}



===== CngRsa32Compat_SHAInit @ 140002fd4 =====

void CngRsa32Compat_SHAInit(BCRYPT_HASH_HANDLE *param_1)

{
  code *pcVar1;
  NTSTATUS NVar2;
  
  NVar2 = BCryptCreateHash((BCRYPT_ALG_HANDLE)0x31,param_1,(PUCHAR)0x0,0,(PUCHAR)0x0,0,0);
  if (NVar2 < 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
  }
  return;
}



===== CngRsa32Compat_SHAUpdate @ 140003018 =====

void CngRsa32Compat_SHAUpdate(undefined8 *param_1,PUCHAR param_2,ULONG param_3)

{
  code *pcVar1;
  NTSTATUS NVar2;
  
  NVar2 = BCryptHashData((BCRYPT_HASH_HANDLE)*param_1,param_2,param_3,0);
  if (NVar2 < 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
  }
  return;
}



===== Feature_3759042875__private_IsEnabledDeviceUsageNoInline @ 140003048 =====

ulonglong Feature_3759042875__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3759042875__private_featureState;
  if ((Feature_3759042875__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3759042875__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3759042875__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3759042875__private_IsEnabledFallback @ 140003080 =====

void Feature_3759042875__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== SmpSetOptions @ 1400030a0 =====

int SmpSetOptions(undefined8 param_1)

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
  undefined8 local_48;
  undefined8 uStack_40;
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
  local_b0 = SmpCoSendNetBufferListChain;
  local_a8 = SmpCoRequest;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = NdisSetOptionalHandlers(0,&local_d8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return iVar1;
    }
    uVar2 = 0xc;
  }
  else {
    local_98 = 0x9001a5;
    local_90 = ScmCmCreateVc;
    local_88 = ScmCmDeleteVc;
    local_80 = ScmCmOpenAf;
    local_78 = ScmCmCloseAf;
    local_70 = ScmCmRegisterSap;
    local_68 = ScmCmDeregisterSap;
    local_60 = ScmCmMakeCall;
    local_58 = ScmCmCloseCall;
    local_50 = ScmCmIncomingCallComplete;
    local_38 = ScmCmActivateVcComplete;
    local_30 = ScmCmDeactivateVcComplete;
    local_28 = ScmCmModifyCallQoS;
    local_20 = ScmCmRequest;
    local_18 = _guard_check_icall;
    local_10 = _guard_check_icall;
    iVar1 = NdisSetOptionalHandlers(param_1,&local_98);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return iVar1;
    }
    uVar2 = 0xd;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,iVar1);
  return iVar1;
}



===== WPP_SF_Dd @ 140003260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF__guid_ @ 1400032b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,0);
  return;
}



===== WPP_SF__guid_d @ 1400032f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,&param_5,4,0);
  return;
}



===== WPP_SF_dd @ 140003340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,0x23,local_res20,4,
             &param_5,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140003398 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140003470 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140003554 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_1400036ac:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000369f:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400036ac;
      if (uVar5 == 5) goto LAB_14000369f;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1400036d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140003758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140003848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003958 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 1400039bc =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 140003b1c =====

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



===== wil_details_MapReportingKind @ 140003bb0 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== BuildCallParams_Old @ 140003c50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong BuildCallParams_Old(longlong param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  wchar_t *pwVar6;
  uint uVar7;
  wchar_t *pwVar8;
  short *psVar9;
  size_t sVar10;
  longlong lVar11;
  short *psVar12;
  undefined1 auStack_f8 [32];
  size_t local_d8 [2];
  wchar_t local_c8 [72];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  lVar11 = 0;
  psVar9 = (short *)((ulonglong)*(uint *)(param_1 + 4) + param_1);
  psVar12 = (short *)((ulonglong)*(uint *)(param_1 + 8) + param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  lVar4 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x74) + 0x358,0x6d704353);
  if (lVar4 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    lVar4 = lVar11;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
  }
  else {
    puVar5 = (uint *)(lVar4 + 0xa8);
    *(undefined4 *)(lVar4 + 0x18) = 12500000;
    *(undefined4 *)(lVar4 + 0x20) = 12500000;
    *(undefined4 *)(lVar4 + 0x30) = 0xfff;
    *(undefined4 *)(lVar4 + 0x38) = 12500000;
    *(undefined4 *)(lVar4 + 0x40) = 12500000;
    *(undefined4 *)(lVar4 + 0x50) = 0xfff;
    *(undefined4 **)(lVar4 + 8) = (undefined4 *)(lVar4 + 0x18);
    *(longlong *)(lVar4 + 0x10) = lVar4 + 0x68;
    *(undefined2 *)(lVar4 + 0x90) = 0x2b0;
    if (*(uint *)(param_1 + 0x74) < 0x10000) {
      uVar2 = *(short *)(param_1 + 0x74) + 0x2b0;
      if (0x2af < uVar2) {
        *(ushort *)(lVar4 + 0x90) = uVar2;
        *(ushort *)(lVar4 + 0x92) = uVar2;
        *(ulonglong *)(lVar4 + 0x98) = (ulonglong)(((int)puVar5 - ((int)lVar4 + 0x80)) - 0x10);
        *(undefined4 *)(lVar4 + 0x70) = 0xfff;
        *(uint *)(lVar4 + 0x7c) = *(ushort *)(lVar4 + 0x90) + 0x20;
        *puVar5 = (uint)*(ushort *)(lVar4 + 0x90);
        *(uint *)(lVar4 + 0xac) = (uint)*(ushort *)(lVar4 + 0x90);
        *(uint *)(lVar4 + 0xb0) = (uint)*(ushort *)(lVar4 + 0x90);
        *(undefined4 *)(lVar4 + 0xb8) = *(undefined4 *)(SstpGlobals + 0x1d0);
        *(undefined4 *)(lVar4 + 0xbc) = *(undefined4 *)(SstpGlobals + 0x1d4);
        iVar3 = *(int *)(param_1 + 0x74);
        *(undefined4 *)(lVar4 + 0x1cc) = 0x158;
        *(int *)(lVar4 + 0x1c8) = iVar3 + 0x44;
        *(undefined4 *)(lVar4 + 0x224) = 0x10;
        *(undefined4 *)(lVar4 + 0x220) = 0x34;
        uVar1 = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(lVar4 + 0x234) = *(undefined8 *)(param_1 + 0x60);
        *(undefined8 *)(lVar4 + 0x23c) = uVar1;
        if (*(int *)(param_1 + 0x74) != 0) {
          *(undefined4 *)(lVar4 + 0x228) = 0x44;
          *(undefined4 *)(lVar4 + 0x22c) = *(undefined4 *)(param_1 + 0x74);
          memmove((void *)(lVar4 + 0x244),(void *)((ulonglong)*(uint *)(param_1 + 0x70) + param_1),
                  (ulonglong)*(uint *)(param_1 + 0x74));
        }
        *(undefined4 *)(lVar4 + 0x114) = 8;
        uVar7 = *(int *)(lVar4 + 0x1c8) + *(int *)(lVar4 + 0x1cc) + 7 & 0xfffffff8;
        *(uint *)(lVar4 + 0x11c) = uVar7;
        pwVar8 = (wchar_t *)((ulonglong)uVar7 + (longlong)puVar5);
        memset(local_c8,0,0x82);
        local_d8[0] = 0;
        pwVar6 = local_c8;
        if (*psVar9 == 2) {
          RtlIpv4AddressToStringW(psVar9 + 2);
        }
        else {
          RtlIpv6AddressToStringW(psVar9 + 4);
        }
        StringCchLengthW(local_c8,(size_t)pwVar6,local_d8);
        sVar10 = local_d8[0] * 2 + 2;
        memmove(pwVar8,local_c8,sVar10);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,sVar10,pwVar8);
        }
        iVar3 = StrLenW(pwVar8);
        uVar7 = *(int *)(lVar4 + 0x11c) + 0x8fU & 0xfffffff8;
        *(undefined4 *)(lVar4 + 0x128) = 8;
        *(uint *)(lVar4 + 0x130) = uVar7;
        *(int *)(lVar4 + 0x118) = iVar3 * 2 + 2;
        pwVar8 = (wchar_t *)((ulonglong)uVar7 + (longlong)puVar5);
        memset(local_c8,0,0x82);
        local_d8[0] = 0;
        pwVar6 = local_c8;
        if (*psVar12 == 2) {
          RtlIpv4AddressToStringW(psVar12 + 2);
        }
        else {
          RtlIpv6AddressToStringW(psVar12 + 4);
        }
        StringCchLengthW(local_c8,(size_t)pwVar6,local_d8);
        sVar10 = local_d8[0] * 2 + 2;
        memmove(pwVar8,local_c8,sVar10);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,sVar10,pwVar8);
        }
        iVar3 = StrLenW(pwVar8);
        *(undefined4 *)(lVar4 + 0xc0) = 8;
        *(int *)(lVar4 + 300) = iVar3 * 2 + 2;
        goto LAB_140004026;
      }
      *(undefined2 *)(lVar4 + 0x90) = 0xffff;
    }
    ExFreePoolWithTag(lVar4 + 0x200,0x6d704353);
  }
LAB_140004026:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return lVar4;
}



===== Feature_2616427835__private_IsEnabledDeviceUsageNoInline @ 14000408c =====

ulonglong Feature_2616427835__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2616427835__private_featureState;
  if ((Feature_2616427835__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2616427835__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2616427835__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2616427835__private_IsEnabledFallback @ 1400040c4 =====

void Feature_2616427835__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2616427835__private_descriptor);
  return;
}



===== FreeCallParams @ 1400040e0 =====

void FreeCallParams(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0x6d704353);
  }
  return;
}



===== StringCchLengthW @ 140004108 =====

HRESULT __stdcall StringCchLengthW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  uint uVar1;
  longlong lVar2;
  
  if (psz == (STRSAFE_PCNZWCH)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    lVar2 = 0x41;
    do {
      if (*psz == L'\0') break;
      psz = psz + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    uVar1 = ~-(uint)(lVar2 != 0) & 0x80070057;
    if (pcchLength != (size_t *)0x0) {
      if (lVar2 == 0) {
        *pcchLength = 0;
      }
      else {
        *pcchLength = 0x41 - lVar2;
      }
    }
    if (lVar2 != 0) {
      return uVar1;
    }
  }
  if (pcchLength != (size_t *)0x0) {
    *pcchLength = 0;
  }
  return uVar1;
}



===== TpiDispatchCleanup @ 140004170 =====

undefined8 TpiDispatchCleanup(undefined8 param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong *plVar11;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  lVar3 = *(longlong *)(SstpGlobals + 0x18);
  if ((lVar2 != *(longlong *)(SstpGlobals + 0x10)) && (lVar2 != lVar3)) goto LAB_14000441d;
  if (lVar2 == lVar3) {
    *(undefined8 *)(SstpGlobals + 0x18) = 0;
  }
  else {
    *(undefined8 *)(SstpGlobals + 0x10) = 0;
    uVar8 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1b8);
    iVar1 = *(int *)(SstpGlobals + 0x1c0);
    *(undefined4 *)(SstpGlobals + 0x1c0) = 0;
    *(undefined1 *)(SstpGlobals + 0x238) = 0;
    KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar8);
    if (iVar1 == 1) {
      param_3 = (undefined *)0x0;
      NdisCmRegisterSapComplete(0xc0010002,*(undefined8 *)(SstpGlobals + 0x1c8),0);
LAB_140004270:
      *(undefined8 *)(SstpGlobals + 0x1c8) = 0;
    }
    else if (iVar1 == 2) {
      NdisCmDeregisterSapComplete(0,*(undefined8 *)(SstpGlobals + 0x1c8));
      goto LAB_140004270;
    }
    DeregisterTPIFromFsm();
    lVar5 = SstpGlobals;
    while( true ) {
      lVar9 = IoCsqRemoveNextIrp(lVar5 + 0x40,0);
      if (lVar9 == 0) break;
      *(undefined4 *)(lVar9 + 0x30) = 0xc0000120;
      IofCompleteRequest(lVar9);
    }
  }
  uVar8 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
  plVar11 = *(longlong **)(SstpGlobals + 0x1e0);
  if (plVar11 != (longlong *)(SstpGlobals + 0x1e0)) {
    do {
      plVar4 = (longlong *)*plVar11;
      KeAcquireSpinLockAtDpcLevel(plVar11 + 2);
      if ((lVar2 == lVar3) && (*(char *)((longlong)plVar11 + 0x1274) == '\0')) {
        KeReleaseSpinLockFromDpcLevel(plVar11 + 2);
      }
      else {
        lVar5 = *plVar11;
        if ((*(longlong **)(lVar5 + 8) != plVar11) ||
           (plVar6 = (longlong *)plVar11[1], (longlong *)*plVar6 != plVar11)) {
          pcVar7 = (code *)swi(0x29);
          (*pcVar7)(3);
          pcVar7 = (code *)swi(3);
          uVar10 = (*pcVar7)();
          return uVar10;
        }
        *plVar6 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar6;
        plVar11[1] = (longlong)plVar11;
        *plVar11 = (longlong)plVar11;
        KeReleaseSpinLockFromDpcLevel(SstpGlobals + 0x1d8);
        if ((*(char *)((longlong)plVar11 + 0x1274) != '\0') &&
           (*(char *)((longlong)plVar11 + 0x124c) != '\0')) {
          *(uint *)(plVar11 + 0x249) = *(uint *)(plVar11 + 0x249) & 0xfffffdff;
        }
        param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar8);
        InitiateSstpContextCleanup((int *)(plVar11 + -2),4,param_3);
        uVar8 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
      }
      plVar11 = plVar4;
    } while (plVar4 != (longlong *)(SstpGlobals + 0x1e0));
  }
  if ((*(longlong *)(SstpGlobals + 0x10) == 0) && (*(longlong *)(SstpGlobals + 0x18) == 0)) {
    NdisFreeNetBufferListPool(*(undefined8 *)(SstpGlobals + 0x240));
    *(undefined8 *)(SstpGlobals + 0x240) = 0;
  }
  KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar8);
LAB_14000441d:
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== TpiDispatchCreate @ 140004470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS TpiDispatchCreate(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 uVar4;
  char cVar5;
  NTSTATUS NVar6;
  undefined8 uVar7;
  undefined1 auStack_88 [32];
  char local_68 [8];
  undefined8 local_60;
  undefined8 uStack_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 0;
  uStack_28 = 0;
  NVar6 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  if (param_1 == *(longlong *)(SstpGlobals + 8)) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    local_68[0] = '\0';
    cVar5 = IsValidToken(*(longlong *)(*(longlong *)(lVar1 + 8) + 8),local_68);
    cVar3 = local_68[0];
    if (cVar5 != '\0') {
      uVar7 = *(undefined8 *)(lVar1 + 0x30);
      if (local_68[0] == '\0') {
        *(undefined8 *)(SstpGlobals + 0x18) = uVar7;
      }
      else {
        uVar2 = (ulonglong)uStack_58 >> 8;
        *(undefined8 *)(SstpGlobals + 0x10) = uVar7;
        uStack_58 = CONCAT71((uint7)uVar2 & 0xffffff,3);
        local_60 = *(undefined8 *)(SstpGlobals + 0x200);
        local_48 = TpiFsmDisconnectComplete;
        local_50 = TpiFsmNewCallComplete;
        local_40 = TpiFsmSendControlFrame;
        local_38 = TpiFsmCryptoBindingComplete;
        uVar7 = IoGetCurrentProcess();
        *(undefined8 *)(SstpGlobals + 0x1b0) = uVar7;
        NVar6 = RegisterTPIWithFsm((undefined4 *)&local_50,(undefined4 *)&local_60,
                                   *(undefined8 *)(SstpGlobals + 8),
                                   (undefined8 *)(SstpGlobals + 0x208));
        if ((((NVar6 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                   &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,NVar6);
        }
      }
      uVar7 = local_30;
      if (*(longlong *)(SstpGlobals + 0x240) == 0) {
        local_30 = CONCAT44(local_30._4_4_,0x100180);
        uVar4 = local_30;
        local_30._6_2_ = SUB82(uVar7,6);
        local_30._0_6_ = CONCAT15(1,(int5)uVar4);
        uStack_28 = 0xfff73646e53;
        uVar7 = NdisAllocateNetBufferListPool(*(undefined8 *)(SstpGlobals + 0xa8),&local_30);
        *(undefined8 *)(SstpGlobals + 0x240) = uVar7;
        if (*(longlong *)(SstpGlobals + 0x240) == 0) {
          if (cVar3 != '\0') {
            DeregisterTPIFromFsm();
          }
          NVar6 = -0x3fffff66;
        }
      }
      if ((cVar3 != '\0') && (*(longlong *)(SstpGlobals + 0x240) != 0)) {
        *(undefined1 *)(SstpGlobals + 0x238) = 1;
      }
    }
  }
  else {
    NVar6 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(NTSTATUS *)(param_2 + 0x30) = NVar6;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return NVar6;
}



===== TpiDispatchIrpStub @ 140004710 =====

undefined8 TpiDispatchIrpStub(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== WPP_SF_DDDDDDDDDDD @ 140004744 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9,undefined1 param_10,undefined1 param_11,
                       undefined1 param_12,undefined1 param_13,undefined1 param_14)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
             &param_12,4,&param_13,4,&param_14,4,0);
  return;
}



===== WPP_SF_S @ 14000481c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

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
            (param_1,0x2b,&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF__guid_dD @ 140004890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_2,param_4,0x10,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF__guid_dd @ 1400048f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,0x10,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF__guid_l @ 140004954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_l(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,0x44,param_4,0x10,
             &param_5,4,0);
  return;
}



===== WPP_SF_ddd @ 1400049a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 0x78;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,0x27,local_res20,4,
             &param_5,4,local_18,4,0);
  return;
}



===== WPP_SF_q @ 140004a14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== CleanupSstpContext @ 140004a60 =====

void CleanupSstpContext(int *param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    if (*param_1 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_1);
      }
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
      return;
    }
    if (param_1[0x4a4] != 0) {
      HfSuspendHandle32(*(undefined8 *)(SstpGlobals + 0x1f8));
      HfFreeHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),param_1 + 0x4a4);
    }
    KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
  }
  if ((*(longlong *)(param_1 + 0x4a2) != 0) &&
     (lVar3 = NdisAllocateIoWorkItem(*(undefined8 *)(SstpGlobals + 0xa8)), lVar3 != 0)) {
    NdisQueueIoWorkItem(lVar3,DPChannelDestroyPassive,*(undefined8 *)(param_1 + 0x4a2));
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0x78744353);
  return;
}



===== Feature_1144678712__private_IsEnabledDeviceUsageNoInline @ 140004c08 =====

ulonglong Feature_1144678712__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1144678712__private_featureState;
  if ((Feature_1144678712__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1144678712__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1144678712__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1144678712__private_IsEnabledFallback @ 140004c40 =====

void Feature_1144678712__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1144678712__private_descriptor);
  return;
}



===== ScmCmCloseCall @ 140004c60 =====

undefined8 ScmCmCloseCall(int *param_1,undefined8 param_2,int **param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  int **ppiVar9;
  int *local_res8;
  
  ppiVar9 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    ppiVar9 = (int **)&WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  uVar6 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar6 == 0) || (param_3 == (int **)0x0)) || (param_4 < 4)) {
LAB_140004e48:
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
    param_1[0x496] = param_1[0x496] | 0x1000;
    uVar6 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
    if ((((int)uVar6 != 0) && (param_3 != (int **)0x0)) && (3 < param_4)) {
      param_1[0x496] = param_1[0x496] | 0x200000;
    }
    InitiateSstpContextCleanup
              (param_1,(-(uint)((param_1[0x496] & 0x800U) != 0) & 3) + 1,
               (undefined *)CONCAT71((int7)((ulonglong)ppiVar9 >> 8),uVar4));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar7 = 0x103;
  }
  else {
    uVar2 = *(undefined4 *)param_3;
    local_res8 = (int *)0x0;
    uVar4 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    ppiVar9 = &local_res8;
    iVar5 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),uVar2,ppiVar9);
    if (((iVar5 < 0) || (param_1 == (int *)0x0)) || (local_res8 != param_1 + 0x79)) {
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar4);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                  &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
          uVar8 = 0x2d;
LAB_140004e35:
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                  &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
        }
      }
    }
    else {
      do {
        iVar5 = *param_1;
        if (iVar5 == 0) {
          bVar3 = false;
          goto LAB_140004d5d;
        }
        LOCK();
        iVar1 = *param_1;
        if (iVar5 == iVar1) {
          *param_1 = iVar5 + 1;
        }
        UNLOCK();
      } while (iVar5 != iVar1);
      bVar3 = true;
LAB_140004d5d:
      KeReleaseSpinLock(SstpGlobals + 0x1f0);
      if (bVar3) goto LAB_140004e48;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                  &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
          uVar8 = 0x2b;
          goto LAB_140004e35;
        }
      }
    }
    uVar7 = 0;
  }
  return uVar7;
}



===== ScmCmCreateVc @ 140004ef0 =====

int ScmCmCreateVc(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  piVar5 = (int *)ExAllocatePool2(0x40,0x1298,0x78744353);
  if (piVar5 == (int *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    puVar9 = auStack_38;
    iVar4 = -0x3fffff66;
  }
  else {
    *piVar5 = 0;
    *(code **)(piVar5 + 2) = CleanupSstpContext;
    KeInitializeSpinLock(piVar5 + 8);
    *(undefined8 *)(piVar5 + 10) = param_2;
    piVar5[0xe] = 0;
    piVar5[0xf] = 0;
    piVar5[0x12] = 0;
    piVar5[0x13] = 0;
    piVar5[0x14] = 0;
    piVar5[0x15] = 0;
    piVar5[0x1d] = 0;
    piVar5[0x496] = 0;
    *(undefined2 *)((longlong)piVar5 + 0x1fa) = 0;
    *(undefined1 *)(piVar5 + 0x7f) = 0;
    piVar5[0x498] = -0x3ffffee0;
    piVar5[0x49e] = 0;
    piVar5[0x49f] = 0;
    *(undefined1 *)(piVar5 + 0x4a1) = 0;
    piVar5[0x4a2] = 0;
    piVar5[0x4a3] = 0;
    uVar6 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 != 0) {
      piVar5[0x4a4] = 0;
    }
    memset(piVar5 + 0x87,0,0x1010);
    piVar5[0x86] = 4;
    piVar5[0x87] = 0;
    uVar3 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    iVar4 = HfAllocateHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),piVar5,piVar5 + 0x1c);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,iVar4);
      }
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
      ExFreePoolWithTag(piVar5,0x78744353);
      puVar9 = auStack_38;
    }
    else {
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
      uVar3 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
      puVar9 = auStack_38;
      plVar8 = (longlong *)(piVar5 + 4);
      *(longlong **)(piVar5 + 6) = plVar8;
      *plVar8 = (longlong)plVar8;
      lVar7 = SstpGlobals + 0x1e0;
      plVar10 = *(longlong **)(SstpGlobals + 0x1e8);
      if (*plVar10 != lVar7) {
        lVar7 = 3;
        pcVar2 = (code *)swi(0x29);
        uVar3 = (*pcVar2)();
        puVar9 = auStack_30;
      }
      *plVar8 = lVar7;
      plVar8[1] = (longlong)plVar10;
      *plVar10 = (longlong)plVar8;
      *(longlong **)(lVar7 + 8) = plVar8;
      *(undefined8 *)(puVar9 + -8) = 0x140005166;
      KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar3);
      LOCK();
      *piVar5 = *piVar5 + 1;
      UNLOCK();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar9 + -8) = 0x14000519b;
        WPP_SF_q(uVar1,0xf,&WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,piVar5);
      }
      *param_3 = piVar5;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x1400051c7;
    WPP_SF_(uVar1,0x10,&WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return iVar4;
}



===== ScmCmDeleteVc @ 1400051f0 =====

undefined8 ScmCmDeleteVc(int *param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81) {
      param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      param_2 = 0x11;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1 + 0x79,
                     (char)param_1);
    }
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
  KeAcquireSpinLockAtDpcLevel(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 4);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_1 + 6), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)();
    return uVar6;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseSpinLockFromDpcLevel(param_1 + 8);
  KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar5);
  uVar5 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
  HfFreeHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),param_1 + 0x1c);
  KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar5);
  DereferenceRefCount(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return 0;
}



===== ScmCmDeregisterSap @ 1400053a0 =====

undefined8 ScmCmDeregisterSap(void)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar3 = 0x103;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1b8);
  if (*(int *)(SstpGlobals + 0x1c0) == 0) {
    uVar3 = 0;
  }
  else {
    lVar2 = IoCsqRemoveNextIrp(SstpGlobals + 0x40,0);
    if (lVar2 != 0) {
      *(undefined4 *)(SstpGlobals + 0x1c0) = 2;
      **(undefined4 **)(lVar2 + 0x18) = 2;
      *(undefined4 *)(lVar2 + 0x30) = 0;
      *(undefined8 *)(lVar2 + 0x38) = 0x2010;
      KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
      IofCompleteRequest(lVar2,0);
      goto LAB_1400054e1;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
LAB_1400054e1:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return uVar3;
}



===== ScmCmMakeCall @ 140005530 =====

undefined4 ScmCmMakeCall(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  
  lVar6 = 0;
  puVar10 = (undefined4 *)0x0;
  uVar8 = 0x103;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  uVar2 = *param_2;
  if ((uVar2 & 0x19) != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,uVar2);
    }
    uVar8 = 0xc00000bb;
    goto LAB_140005a92;
  }
  if (((((uVar2 & 2) != 0) || (lVar9 = *(longlong *)(param_2 + 4), lVar9 == 0)) ||
      (*(uint *)(lVar9 + 0x14) < 0x30)) ||
     ((*(ushort *)(lVar9 + 0x38) < 0xb4 ||
      (lVar9 = *(longlong *)(lVar9 + 0x40) + 0x18 + lVar9,
      (*(uint *)(lVar9 + 0x30) & 0xfffffeef) != 0)))) {
    uVar8 = 0xc0010015;
    goto LAB_140005a92;
  }
  lVar1 = param_1 + 0x20;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(longlong *)(param_1 + 0x1230) != 0) {
    uVar8 = 0x10007;
    KeReleaseSpinLock(lVar1,uVar3);
    goto LAB_140005a92;
  }
  *(uint **)(param_1 + 0x1230) = param_2;
  if (((*(uint *)(lVar9 + 0x88) < 0x2001) &&
      ((uVar4 = Feature_1144678712__private_IsEnabledDeviceUsageNoInline(), (int)uVar4 == 0 ||
       (0x33 < *(uint *)(lVar9 + 0x88))))) &&
     ((*(uint *)((ulonglong)*(uint *)(lVar9 + 0x8c) + 0x50 + lVar9) & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x1284) = 1;
  }
  *(uint *)(param_1 + 0x1258) = *(uint *)(param_1 + 0x1258) | 0x41;
  KeReleaseSpinLock(lVar1,uVar3);
  if (*(uint *)(lVar9 + 0x88) < 0x2001) {
    lVar5 = NdisAllocateIoWorkItem(*(undefined8 *)(SstpGlobals + 0xa8));
    if (lVar5 != 0) {
      if (*(char *)(param_1 + 0x1284) == '\0') {
        lVar6 = IoCsqRemoveNextIrp(SstpGlobals + 0x40,0);
        if (lVar6 == 0) {
          uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
          *(undefined8 *)(param_1 + 0x1230) = 0;
          KeReleaseSpinLock(lVar1,uVar3);
          NdisFreeIoWorkItem(lVar5);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar7 = 0x25;
            goto LAB_140005711;
          }
          goto LAB_140005728;
        }
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      uVar2 = *(uint *)(param_1 + 0x1258);
      *(uint *)(param_1 + 0x1258) = uVar2 | 0x4000;
      if (*(char *)(param_1 + 0x1284) == '\0') {
        *(uint *)(param_1 + 0x1258) = uVar2 | 0x6000;
        KeReleaseSpinLock(param_1 + 0x20);
        puVar10 = *(undefined4 **)(lVar6 + 0x18);
        memset(puVar10 + 1,0,0x200c);
        *puVar10 = 4;
        puVar10[1] = *(undefined4 *)(param_1 + 0x70);
      }
      *(ulonglong *)(param_1 + 0x1278) = (ulonglong)*(uint *)(lVar9 + 0x8c) + 0x20 + lVar9;
      if (*(char *)(param_1 + 0x1284) == '\0') {
        memmove(puVar10 + 4,(void *)((ulonglong)*(uint *)(lVar9 + 0x8c) + 0x20 + lVar9),
                (ulonglong)*(uint *)(lVar9 + 0x88));
        puVar10[3] = *(undefined4 *)(lVar9 + 0x88);
        *(undefined4 *)(lVar6 + 0x30) = 0;
        *(undefined8 *)(lVar6 + 0x38) = 0x2010;
        NdisQueueIoWorkItem(lVar5,ScmCmCompleteIrpPassive,lVar6);
        goto LAB_140005a92;
      }
      uVar4 = Feature_1144678712__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
LAB_14000591c:
        lVar6 = *(longlong *)(param_1 + 0x1278);
        memmove((void *)(param_1 + 0x1e4),(void *)((ulonglong)*(uint *)(lVar6 + 0x20) + lVar6),
                (ulonglong)*(uint *)(lVar6 + 0x24));
        KeReleaseSpinLock(param_1 + 0x20,uVar3);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                        &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,(void *)(param_1 + 0x1e4));
        }
        uVar8 = 0;
        NdisQueueIoWorkItem(lVar5,ScmCmCompleteIrpPassive,0);
      }
      else {
        lVar6 = *(longlong *)(param_1 + 0x1278);
        uVar2 = *(uint *)(lVar6 + 0x24);
        if (uVar2 < 0x11) {
          if ((*(uint *)(lVar6 + 0x20) <= *(uint *)(lVar9 + 0x88)) &&
             (uVar2 <= *(uint *)(lVar9 + 0x88) - *(uint *)(lVar6 + 0x20))) goto LAB_14000591c;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar6,(ulonglong)uVar2,
                      *(undefined4 *)(param_1 + 0x70),(char)uVar2,
                      (char)*(undefined4 *)(lVar6 + 0x20),(char)*(undefined4 *)(lVar9 + 0x88));
        }
        *(uint *)(param_1 + 0x1258) = *(uint *)(param_1 + 0x1258) & 0xffffbfbe;
        *(undefined8 *)(param_1 + 0x1230) = 0;
        *(undefined8 *)(param_1 + 0x1278) = 0;
        *(undefined1 *)(param_1 + 0x1284) = 0;
        KeReleaseSpinLock(param_1 + 0x20,uVar3);
        NdisFreeIoWorkItem(lVar5);
        uVar8 = 0xc0010015;
      }
      goto LAB_140005a92;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined8 *)(param_1 + 0x1230) = 0;
    KeReleaseSpinLock(lVar1,uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined8 *)(param_1 + 0x1230) = 0;
    KeReleaseSpinLock(lVar1,uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar7 = 0x23;
LAB_140005711:
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                    &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_1 + 0x1e4);
    }
  }
LAB_140005728:
  uVar8 = 0xc000009a;
LAB_140005a92:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return uVar8;
}



===== ScmCmRegisterSap @ 140005af0 =====

undefined8 ScmCmRegisterSap(undefined8 param_1,int *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = 0x103;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1b8);
  if (*(int *)(SstpGlobals + 0x1c0) == 3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar5 = 0xc0010021;
  }
  else if ((*param_2 == 0x8000) && (0xb < (uint)param_2[1])) {
    *(int *)(SstpGlobals + 0x1d0) = param_2[2];
    iVar4 = param_2[3];
    if (iVar4 == -1) {
      iVar4 = 0;
    }
    *(int *)(SstpGlobals + 0x1d4) = iVar4;
    lVar2 = NdisAllocateIoWorkItem(*(undefined8 *)(SstpGlobals + 0xa8));
    if (lVar2 != 0) {
      lVar3 = IoCsqRemoveNextIrp(SstpGlobals + 0x40,0);
      if (lVar3 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
        }
        uVar5 = 0xc000009a;
        KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
        NdisFreeIoWorkItem(lVar2);
      }
      else {
        *(undefined4 *)(SstpGlobals + 0x1c0) = 1;
        **(undefined4 **)(lVar3 + 0x18) = 0;
        *(undefined4 *)(lVar3 + 0x30) = 0;
        *(undefined8 *)(lVar3 + 0x38) = 0x2010;
        *(undefined8 *)(SstpGlobals + 0x1c8) = param_3;
        KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
        NdisQueueIoWorkItem(lVar2,ScmCmCompleteIrpPassive,lVar3);
      }
      goto LAB_140005d70;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar5 = 0xc000009a;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar5 = 0xc0010015;
  }
  KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
LAB_140005d70:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return uVar5;
}



===== WPP_SF_DDDD @ 140005dc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,0x26,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF__guid_q @ 140005e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,0x12,param_4,0x10,
             &param_5,8,0);
  return;
}



===== IsValidToken @ 140005e88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 IsValidToken(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined4 local_70;
  undefined4 local_6c;
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
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_70 = 0x601;
  uVar7 = 0;
  local_78 = (uint *)0x0;
  *param_2 = 0;
  local_6c = 0x5000000;
  local_68 = 0x50;
  local_64 = 0xccc8a67e;
  local_60 = 0x2fa7ae2a;
  local_5c = 0xe1fbebc1;
  local_58 = 0xc06be3ba;
  local_54 = 0xaf2bd0da;
  local_50 = 0x601;
  local_4c = 0x5000000;
  local_48 = 0x50;
  local_44 = 0xf8ee4d1a;
  local_40 = 0x1231c877;
  local_3c = 0x8682c501;
  local_38 = 0xa1c73fcb;
  local_34 = 0xd3bf5936;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids);
  }
  SeLockSubjectContext(param_1 + 0x20);
  lVar3 = *(longlong *)(param_1 + 0x20);
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x30);
  }
  else if (*(int *)(param_1 + 0x28) < 2) goto LAB_140006065;
  iVar2 = SeQueryInformationToken(lVar3,2,&local_78);
  if (iVar2 == 0) {
    puVar4 = local_78;
    for (uVar5 = 0; uVar5 < *puVar4; uVar5 = uVar5 + 1) {
      uVar6 = (ulonglong)uVar5;
      if (((byte)puVar4[uVar6 * 4 + 4] & 0xc) == 0xc) {
        cVar1 = RtlEqualSid(&local_70,*(undefined8 *)(puVar4 + uVar6 * 4 + 2));
        if (cVar1 == '\0') {
          cVar1 = RtlEqualSid(&local_50,*(undefined8 *)(local_78 + uVar6 * 4 + 2));
          if (cVar1 == '\0') {
            puVar4 = local_78;
            goto LAB_14000603c;
          }
        }
        else {
          *param_2 = 1;
        }
        uVar7 = 1;
        puVar4 = local_78;
        break;
      }
LAB_14000603c:
    }
    if (puVar4 != (uint *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids,iVar2);
  }
LAB_140006065:
  SeUnlockSubjectContext(param_1 + 0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids);
  }
  return uVar7;
}



===== SetupSstpAclOnDevice @ 1400060d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SetupSstpAclOnDevice(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined1 local_d0;
  undefined8 *local_c8;
  undefined8 local_b8;
  ulonglong local_b0 [5];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
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
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_88 = 0x580002;
  local_84 = 2;
  local_80 = 0x280000;
  local_b0[4] = 0;
  local_7c = 0x10000000;
  local_78 = 0x601;
  local_74 = 0x5000000;
  local_70 = 0x50;
  local_6c = 0xccc8a67e;
  local_68 = 0x2fa7ae2a;
  local_64 = 0xe1fbebc1;
  local_60 = 0xc06be3ba;
  local_5c = 0xaf2bd0da;
  local_58 = 0x280000;
  local_54 = 0x10000000;
  local_50 = 0x601;
  local_4c = 0x5000000;
  local_48 = 0x50;
  local_44 = 0xf8ee4d1a;
  local_40 = 0x1231c877;
  local_3c = 0x8682c501;
  local_38 = 0xa1c73fcb;
  local_34 = 0xd3bf5936;
  local_b0[0] = 0;
  local_b0[1] = 0;
  local_b8 = 0;
  local_b0[2] = 0;
  local_b0[3] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids);
  }
  iVar2 = RtlCreateSecurityDescriptor(local_b0,1);
  if (iVar2 == 0) {
    iVar2 = RtlSetDaclSecurityDescriptor(local_b0,1,&local_88,0);
    if (iVar2 == 0) {
      cVar1 = RtlValidSecurityDescriptor(local_b0);
      if (cVar1 == '\0') {
        iVar2 = -0x3fffff87;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffff87;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
        goto LAB_14000639a;
        uVar4 = 0xd;
        iVar2 = -0x3fffff87;
      }
      else {
        local_b0[0] = local_b0[0] | 0x10000000;
        local_c8 = &local_b8;
        local_d0 = 0;
        local_d8 = 0;
        iVar2 = ObOpenObjectByPointer(param_1,0x200,0,0x40000);
        if (iVar2 == 0) {
          iVar2 = ZwSetSecurityObject(local_b8,4,local_b0);
          if ((((iVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids,iVar2);
          }
          ZwClose(local_b8);
          goto LAB_14000639a;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
        goto LAB_14000639a;
        uVar4 = 0xe;
      }
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_14000639a;
      uVar4 = 0xc;
    }
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_14000639a;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 0xb;
  }
  WPP_SF_D(uVar3,uVar4,&WPP_b18e4254e1cd3db166f3c49730626150_Traceguids,iVar2);
LAB_14000639a:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_b18e4254e1cd3db166f3c49730626150_Traceguids);
  }
  return iVar2;
}



===== CsqAcquireLock @ 140006400 =====

void CsqAcquireLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + -8);
  *param_2 = uVar1;
  return;
}



===== CsqCompleteCanceledIrp @ 140006430 =====

void CsqCompleteCanceledIrp(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== CsqInsertIrp @ 140006460 =====

void CsqInsertIrp(longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_2 + 0xa8);
  lVar3 = param_1 + 0x40;
  *(longlong **)(param_2 + 0xb0) = plVar4;
  *plVar4 = (longlong)plVar4;
  plVar2 = *(longlong **)(param_1 + 0x48);
  if (*plVar2 != lVar3) {
    lVar3 = 3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *plVar4 = lVar3;
  plVar4[1] = (longlong)plVar2;
  *plVar2 = (longlong)plVar4;
  *(longlong **)(lVar3 + 8) = plVar4;
  return;
}



===== CsqPeekNextIrp @ 1400064a0 =====

longlong CsqPeekNextIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(param_1 + 0x40);
  if (param_2 != 0) {
    plVar2 = (longlong *)(param_2 + 0xa8);
  }
  lVar1 = (longlong)((longlong *)*plVar2 + -0x15);
  if ((longlong *)*plVar2 == (longlong *)(param_1 + 0x40)) {
    lVar1 = 0;
  }
  return lVar1;
}



===== CsqReleaseLock @ 1400064e0 =====

void CsqReleaseLock(longlong param_1)

{
  KeReleaseSpinLock(param_1 + -8);
  return;
}



===== CsqRemoveIrp @ 140006500 =====

void CsqRemoveIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_2 + 0xa8);
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) == plVar4) &&
     (plVar2 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar2 == plVar4)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== StrLenW @ 140006530 =====

int StrLenW(short *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (short *)0x0) {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



===== DeregisterTPIFromFsm @ 140006550 =====

void DeregisterTPIFromFsm(void)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  NTSTATUS NVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  puVar4 = SstpFsmGlobalInfo;
  puVar1 = SstpFsmGlobalInfo + 0x18;
  *SstpFsmGlobalInfo = 0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(puVar1);
  puVar4[0x40] = 0;
  if (*(int *)(puVar4 + 0x20) == 0) {
    KeReleaseSpinLock();
  }
  else {
    KeReleaseSpinLock(puVar1,uVar5);
    KeWaitForSingleObject(puVar4 + 0x28,0,0,0,0);
  }
  while( true ) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(SstpFsmGlobalInfo + 0x48);
    puVar2 = (undefined8 *)(SstpFsmGlobalInfo + 0x50);
    puVar3 = (undefined8 *)*puVar2;
    if (puVar3 == puVar2) break;
    LOCK();
    *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + 1;
    UNLOCK();
    KeAcquireSpinLockAtDpcLevel(puVar3 + 2);
    KeReleaseSpinLockFromDpcLevel(SstpFsmGlobalInfo + 0x48);
    MoveToCallDisconnectedState((longlong)puVar3,0,(undefined1 *)0x0);
    KeLowerIrql(uVar5);
    DereferenceRefCount((int *)(puVar3 + 4));
  }
  KeReleaseSpinLock(SstpFsmGlobalInfo + 0x48,CONCAT71((int7)((ulonglong)puVar2 >> 8),uVar5));
  ExDeleteNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
  if (*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x108) != (BCRYPT_ALG_HANDLE)0x0) {
    NVar6 = BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x108),0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
               &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar6);
    }
  }
  if (*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x100) != (BCRYPT_ALG_HANDLE)0x0) {
    NVar6 = BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x100),0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x91,
               &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar6);
    }
  }
  if (SstpFsmGlobalInfo[0xc] != '\0') {
    FipsDeInit((undefined8 *)(SstpFsmGlobalInfo + 0x110));
  }
  IoFreeWorkItem(*(undefined8 *)(SstpFsmGlobalInfo + 0x1a8));
  ExFreePoolWithTag(SstpFsmGlobalInfo,0x69676653);
  SstpFsmGlobalInfo = (undefined1 *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x92,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== WPP_SF__guid_L @ 1400067ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_2,param_4,0x10,
             &param_5,4,0);
  return;
}



===== WPP_SF__guid_Lq @ 14000683c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_Lq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,0x5d,param_4,0x10,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_l @ 1400068a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_l(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,0x67,local_res20,4,0);
  return;
}



===== ModifyTimerGlobalStateToStopping @ 1400068ec =====

undefined4 ModifyTimerGlobalStateToStopping(void)

{
  undefined4 uVar1;
  bool bVar2;
  
  LOCK();
  bVar2 = SstpTimerCurrentState == 3;
  if (bVar2) {
    SstpTimerCurrentState = 2;
  }
  UNLOCK();
  uVar1 = 0;
  if (!bVar2) {
    uVar1 = 0x40000000;
  }
  return uVar1;
}



===== RtlStartTimerWheelEntryTimer @ 140006910 =====

undefined8 RtlStartTimerWheelEntryTimer(longlong param_1,undefined8 param_2,uint param_3)

{
  ulonglong uVar1;
  undefined7 uVar2;
  
  uVar1 = 1;
  if (param_3 != 0) {
    uVar1 = (ulonglong)param_3;
  }
  *(int *)(param_1 + 0x14) = (int)uVar1;
  uVar2 = (undefined7)(uVar1 >> 8);
  if (*(int *)(param_1 + 0x10) == 0) {
    return CONCAT71(uVar2,1);
  }
  return CONCAT71(uVar2,(int)uVar1 - *(int *)(param_1 + 0x10) < 0);
}



===== SstpTimerDelete @ 140006938 =====

void SstpTimerDelete(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 local_res10 [8];
  
  lVar1 = param_1[2];
  uVar5 = 0;
  local_res10[0] = 0;
  if (param_2 == '\0') {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x3d0);
  }
  KeAcquireSpinLockAtDpcLevel(lVar1 + 0x80);
  KeAcquireSpinLockAtDpcLevel(param_1 + 6);
  if (param_2 != '\0') {
    RtlReturnTimerWheelEntry(lVar1 + 0x98,param_1 + 7);
  }
  RtlCleanupTimerWheelEntry(lVar1 + 0x98,param_1 + 7,local_res10);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) != param_1) ||
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 != param_1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseSpinLockFromDpcLevel(param_1 + 6);
  KeReleaseSpinLockFromDpcLevel(lVar1 + 0x80);
  if (param_2 == '\0') {
    KeReleaseSpinLock(lVar1 + 0x3d0,uVar5);
  }
  return;
}



===== SstpTimerDisable @ 140006a5c =====

void SstpTimerDisable(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined1 local_res10 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_res10[0] = 0;
  lVar1 = lVar2 + 0x80;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  RtlCleanupTimerWheelEntry(lVar2 + 0x98,param_1 + 0x38,local_res10);
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x30);
  KeReleaseSpinLock(lVar1,uVar3);
  return;
}



===== SstpTimerInitialize @ 140006b24 =====

undefined8
SstpTimerInitialize(longlong *param_1,longlong param_2,longlong param_3,undefined8 param_4,
                   int param_5)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  memset(param_1,0,0x50);
  plVar1 = param_1 + 6;
  param_1[4] = param_2;
  param_1[5] = param_3;
  *(undefined1 *)(param_1 + 3) = 1;
  *(int *)((longlong)param_1 + 0x1c) = param_5 * 1000;
  param_1[1] = (longlong)param_1;
  *param_1 = (longlong)param_1;
  KeInitializeSpinLock(plVar1);
  LOCK();
  UNLOCK();
  lVar9 = ((ulonglong)(SstpTimerGlobals + 1) % (ulonglong)DAT_14000b244) * 0x3d8 + DAT_14000b248;
  SstpTimerGlobals = SstpTimerGlobals + 1;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar9 + 0x80);
  puVar10 = auStack_38;
  lVar7 = lVar9 + 0x88;
  plVar8 = *(longlong **)(lVar9 + 0x90);
  if (*plVar8 != lVar7) {
    lVar7 = 3;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar10 = auStack_30;
  }
  *param_1 = lVar7;
  param_1[1] = (longlong)plVar8;
  *plVar8 = (longlong)param_1;
  *(longlong **)(lVar7 + 8) = param_1;
  *(undefined8 *)(puVar10 + -8) = 0x140006bf5;
  KeAcquireSpinLockAtDpcLevel(plVar1);
  plVar8 = param_1 + 7;
  *(undefined8 *)(puVar10 + -8) = 0x140006c18;
  RtlInitializeTimerWheelEntry(lVar9 + 0x98,plVar8,0,0);
  uVar2 = *(uint *)((longlong)param_1 + 0x1c);
  if (uVar2 != 0) {
    iVar3 = *(int *)(lVar9 + 0x9c);
    *(undefined8 *)(puVar10 + -8) = 0x140006c3d;
    uVar6 = RtlStartTimerWheelEntryTimer
                      ((longlong)plVar8,(ulonglong)uVar2 % (ulonglong)DAT_14000b250,
                       uVar2 / DAT_14000b250 + iVar3);
    if ((char)uVar6 != '\0') {
      *(undefined8 *)(puVar10 + -8) = 0x140006c4e;
      RtlIndicateTimerWheelEntryTimerStart(lVar9 + 0x98,plVar8);
    }
  }
  param_1[2] = lVar9;
  *(undefined8 *)(puVar10 + -8) = 0x140006c61;
  KeReleaseSpinLockFromDpcLevel(plVar1);
  *(undefined8 *)(puVar10 + -8) = 0x140006c73;
  KeReleaseSpinLock(lVar9 + 0x80,uVar5);
  return 0;
}



===== SstpTimerInitializePerProcTimers @ 140006ca0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SstpTimerInitializePerProcTimers(void)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_res8 [2];
  longlong lVar7;
  
  local_res8[0] = 0;
  iVar2 = 0;
  LOCK();
  if (SstpTimerCurrentState == 0) {
    SstpTimerCurrentState = 1;
  }
  else {
    iVar2 = SstpTimerCurrentState;
  }
  UNLOCK();
  if ((DAT_14000b248 == 0) && (iVar2 == 0)) {
    DAT_14000b248 = 0;
    _DAT_14000b250 = 500;
    _SstpTimerGlobals = 0;
    uVar1 = KeQueryActiveProcessorCountEx(0xffff);
    _SstpTimerGlobals = CONCAT44(uVar1,SstpTimerGlobals);
    lVar3 = ExAllocatePool2(0x40,(ulonglong)uVar1 * 0x3d8,0x63747053);
    DAT_14000b248 = lVar3;
    if (lVar3 == 0) {
      uVar6 = 0xc000009a;
      LOCK();
      SstpTimerCurrentState = 0;
      UNLOCK();
    }
    else {
      uVar1 = DAT_14000b250 * 10000;
      uVar5 = 0;
      while( true ) {
        uVar6 = 0;
        if (DAT_14000b244 <= uVar5) break;
        iVar2 = KeGetProcessorNumberFromIndex(uVar5,local_res8);
        if (iVar2 != 0) {
          do {
            uVar5 = uVar5 - 1;
            KeCancelTimer(lVar3 + 0x40 + (ulonglong)uVar5 * 0x3d8);
            RtlCleanupTimerWheel(lVar3 + 0x98 + (ulonglong)uVar5 * 0x3d8);
          } while( true );
        }
        lVar4 = (ulonglong)uVar5 * 0x3d8 + lVar3;
        KeInitializeDpc(lVar4,SstpTimerPeriodicDpc);
        KeSetTargetProcessorDpcEx(lVar4,local_res8);
        KeInitializeTimerEx(lVar4 + 0x40,0);
        lVar7 = lVar4;
        KeSetCoalescableTimer(lVar4 + 0x40,-(ulonglong)uVar1,_DAT_14000b250 & 0xffffffff,0x32,lVar4)
        ;
        uVar6 = (undefined4)((ulonglong)lVar7 >> 0x20);
        KeInitializeSpinLock(lVar4 + 0x80);
        KeInitializeSpinLock(lVar4 + 0x3d0);
        lVar7 = lVar4 + 0x88;
        *(longlong *)(lVar4 + 0x90) = lVar7;
        *(longlong *)lVar7 = lVar7;
        RtlInitializeTimerWheel
                  (lVar4 + 0x98,0x20,1,1,
                   CONCAT44(uVar6,(int)((_DAT_fffff78000000008 / 10000) /
                                       (_DAT_14000b250 & 0xffffffff))));
        uVar5 = uVar5 + 1;
      }
      LOCK();
      SstpTimerCurrentState = 3;
      UNLOCK();
    }
  }
  else {
    uVar6 = 0xc0000476;
    if (iVar2 == 3) {
      uVar6 = 0x40000000;
    }
  }
  return uVar6;
}



===== SstpTimerReschedule @ 140006f1c =====

void SstpTimerReschedule(longlong param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
                        int param_5,char param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  undefined1 local_res20 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_res20[0] = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x80);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x30);
  *(undefined1 *)(param_1 + 0x18) = param_4;
  *(undefined8 *)(param_1 + 0x20) = param_2;
  lVar1 = param_1 + 0x38;
  *(undefined8 *)(param_1 + 0x28) = param_3;
  *(int *)(param_1 + 0x1c) = param_5 * 1000;
  *(undefined1 *)(param_1 + 0x19) = 1;
  if (param_6 == '\0') {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    RtlCleanupTimerWheelEntry(lVar2 + 0x98,lVar1,local_res20);
  }
  uVar4 = RtlStartTimerWheelEntryTimer
                    (lVar1,(ulonglong)*(uint *)(param_1 + 0x1c) % (ulonglong)DAT_14000b250,
                     *(uint *)(param_1 + 0x1c) / DAT_14000b250 + *(int *)(lVar2 + 0x9c));
  if ((char)uVar4 != '\0') {
    RtlIndicateTimerWheelEntryTimerStart(lVar2 + 0x98,lVar1);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x30);
  KeReleaseSpinLock(lVar2 + 0x80,uVar3);
  return;
}



===== SstpTimerShutdownPerProcTimers @ 140007038 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SstpTimerShutdownPerProcTimers(void)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  uVar4 = 0;
  uVar3 = 0;
  if (DAT_14000b244 != 0) {
    do {
      plVar2 = (longlong *)((ulonglong)uVar3 * 0x3d8 + DAT_14000b248 + 0x88);
      if ((longlong *)*plVar2 != plVar2) break;
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_14000b244);
  }
  if (uVar3 == DAT_14000b244) {
    uVar5 = 0;
    if (DAT_14000b244 != 0) {
      do {
        KeCancelTimer(uVar5 * 0x3d8 + DAT_14000b248 + 0x40);
        uVar3 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar3;
      } while (uVar3 < DAT_14000b244);
    }
    KeFlushQueuedDpcs();
    lVar1 = DAT_14000b248;
    uVar5 = 0;
    DAT_14000b248 = 0;
    if (DAT_14000b244 != 0) {
      do {
        RtlCleanupTimerWheel(uVar5 * 0x3d8 + 0x98 + lVar1);
        uVar3 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar3;
      } while (uVar3 < DAT_14000b244);
    }
    _DAT_14000b250 = 0;
    _SstpTimerGlobals = 0;
    DAT_14000b248 = 0;
    ExFreePool(lVar1);
    SstpTimerCurrentState = 0;
  }
  else {
    uVar4 = 0xc0000184;
    SstpTimerCurrentState = 3;
  }
  LOCK();
  UNLOCK();
  return uVar4;
}



===== SstpTimerShutdownPerProcTimersAsync @ 140007160 =====

void SstpTimerShutdownPerProcTimersAsync(void)

{
  SstpTimerShutdownPerProcTimers();
  return;
}



===== __GSHandlerCheck @ 140007178 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000719c =====

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



===== __chkstk @ 140007202 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140007202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 140007220 =====

/* WARNING: Removing unreachable block (ram,0x00014000728a) */
/* WARNING: Removing unreachable block (ram,0x000140007239) */
/* WARNING: Removing unreachable block (ram,0x00014000722a) */

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



===== __security_check_cookie @ 1400072f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007330 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007360 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007390 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140007400 =====

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



===== memset @ 140007700 =====

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



===== __memset_repmovs @ 140007840 =====

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



===== __memset_query @ 1400078c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007940 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007a80 =====

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



===== __memset_spec_plain @ 140007b00 =====

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



===== DriverEntry @ 14000f008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined2 uVar4;
  code **ppcVar5;
  undefined1 auStack_268 [32];
  longlong *local_248;
  longlong local_238;
  undefined8 local_230;
  undefined8 *puStack_228;
  undefined8 *local_220;
  code **ppcStack_218;
  ulonglong local_210;
  undefined *puStack_208;
  undefined8 *local_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  code *local_1a8;
  code *local_1a0;
  code *local_190;
  code *local_188;
  code *local_180;
  undefined8 local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  code *local_118 [14];
  code *local_a8;
  code *local_88;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  local_138 = 0;
  uStack_130 = 0;
  local_200 = (undefined8 *)0x0;
  local_128 = 0x11cee3254d36e972;
  uStack_120 = 0x1803e12b0008c1bf;
  local_230 = 0;
  puStack_228 = (undefined8 *)0x0;
  local_220 = (undefined8 *)0x0;
  ppcStack_218 = (code **)0x0;
  local_210 = 0;
  puStack_208 = (undefined *)0x0;
  memset(local_118,0,0xd8);
  local_238 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  memset(&local_1d8,0,0x98);
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&local_138,L"Microsoft\\Tracing\\SSTP");
  _WPP_MAIN_CB = 0;
  DAT_14000b268 = &WPP_ThisDir_CTLGUID_CtlGuid;
  DAT_14000b270 = 0;
  _DAT_14000b280 = 0;
  _DAT_14000b288 = 1;
  WppLoadTracingSupport();
  _DAT_14000b280 = 0;
  WppInitKm();
  SstpGlobals = (longlong *)ExAllocatePool2(0x40,0x248,0x69674453);
  if (SstpGlobals == (longlong *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_ae2ab746655932081d7fcb84729586d3_Traceguids);
    }
    iVar1 = -0x3fffff66;
    goto LAB_14000f532;
  }
  *SstpGlobals = param_1;
  SstpGlobals[2] = 0;
  SstpGlobals[3] = 0;
  KeInitializeSpinLock(SstpGlobals + 0x37);
  *(undefined4 *)(SstpGlobals + 0x38) = 0;
  KeInitializeSpinLock(SstpGlobals + 0x3b);
  plVar2 = SstpGlobals + 0x3c;
  SstpGlobals[0x3d] = (longlong)plVar2;
  *plVar2 = (longlong)plVar2;
  KeInitializeSpinLock(SstpGlobals + 0x3e);
  iVar1 = HfCreateFactory(0,SstpGlobals + 0x3f);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_14000f532;
    uVar4 = 0xb;
  }
  else {
    InitializeIrpQueue((longlong)(SstpGlobals + 7));
    local_1d8 = 0x98028a;
    local_1c8 = SmpSetOptions;
    local_1d4 = 0x11e06;
    local_1b8 = SmpHaltEx;
    local_170 = 0;
    local_1c0 = SmpInitializeEx;
    local_1b0 = SmpUnload;
    local_1a8 = SmpPause;
    local_1a0 = SmpRestart;
    local_190 = _guard_check_icall;
    local_188 = SmpReturnNetBufferListChain;
    local_180 = _guard_check_icall;
    local_168 = _guard_check_icall;
    local_160 = _guard_check_icall;
    local_158 = _guard_check_icall;
    local_248 = SstpGlobals + 5;
    iVar1 = NdisMRegisterMiniportDriver(param_1,param_2,&SstpGlobals,&local_1d8);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_1f8,L"\\Device\\SstpDrv");
      RtlInitUnicodeString(&local_1e8,L"\\DosDevices\\SstpDrv");
      local_210 = local_210 & 0xffffffff00000000;
      puStack_208 = &SDDL_LS_ALL;
      local_200 = &local_128;
      local_230 = CONCAT44(local_230._4_4_,0x380185);
      puStack_228 = &local_1f8;
      ppcStack_218 = local_118;
      local_220 = &local_1e8;
      ppcVar5 = local_118;
      for (lVar3 = 0x1b; lVar3 != 0; lVar3 = lVar3 + -1) {
        *ppcVar5 = TpiDispatchIrpStub;
        ppcVar5 = ppcVar5 + 1;
      }
      local_118[0] = TpiDispatchCreate;
      local_88 = TpiDispatchCleanup;
      local_a8 = TpiDispatchDeviceControl;
      iVar1 = NdisRegisterDeviceEx(SstpGlobals[5],&local_230,&local_238,SstpGlobals + 4);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_ae2ab746655932081d7fcb84729586d3_Traceguids,iVar1);
        }
      }
      else {
        iVar1 = SetupSstpAclOnDevice(local_238);
        if (-1 < iVar1) {
          SstpGlobals[1] = local_238;
          *(undefined4 *)(SstpGlobals + 0x1a) = 0xe0;
          SstpGlobals[0x24] = (longlong)TpiDispatchFastIoDeviceControl;
          *(longlong **)(param_1 + 0x50) = SstpGlobals + 0x1a;
          *(undefined1 *)((longlong)SstpGlobals + 0x239) = 0;
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return iVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
            return iVar1;
          }
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_ae2ab746655932081d7fcb84729586d3_Traceguids);
          return iVar1;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_ae2ab746655932081d7fcb84729586d3_Traceguids,iVar1);
        }
        NdisDeregisterDeviceEx(SstpGlobals[4]);
      }
      HfDestroyFactory(SstpGlobals + 0x3f);
      NdisMDeregisterMiniportDriver(SstpGlobals[5]);
      SstpGlobals[5] = 0;
      goto LAB_14000f532;
    }
    HfDestroyFactory(SstpGlobals + 0x3f);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_14000f532;
    uVar4 = 0xc;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_ae2ab746655932081d7fcb84729586d3_Traceguids,iVar1);
LAB_14000f532:
  if (SstpGlobals != (longlong *)0x0) {
    ExFreePoolWithTag(SstpGlobals,0x69674453);
    SstpGlobals = (longlong *)0x0;
  }
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return iVar1;
}



===== SmpUnload @ 14000f620 =====

void SmpUnload(void)

{
  if (*(longlong *)(SstpGlobals + 0x20) != 0) {
    NdisDeregisterDeviceEx();
    *(undefined8 *)(SstpGlobals + 8) = 0;
    *(undefined8 *)(SstpGlobals + 0x20) = 0;
  }
  if (*(longlong *)(SstpGlobals + 0x28) != 0) {
    NdisMDeregisterMiniportDriver();
    *(undefined8 *)(SstpGlobals + 0x28) = 0;
  }
  HfDestroyFactory(SstpGlobals + 0x1f8);
  ExFreePoolWithTag(SstpGlobals,0x69674453);
  SstpGlobals = 0;
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return;
}



===== WppCleanupKm @ 14000f6d0 =====

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



===== WppInitKm @ 14000f750 =====

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



===== WppTraceCallback @ 14000f7e0 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_UninitializeFeatureStaging @ 14000fa68 =====

void wil_UninitializeFeatureStaging(void)

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000fac0 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_14000fb1d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000fb1d;
    }
  }
  uVar1 = 0x206;
LAB_14000fb1d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000fb28 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000fbe0 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000fc18 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000fc9a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000fc9a;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_14000fc9a:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000fcf0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000fd50 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000fd6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== ReadRegistrySettings @ 14000fe20 =====

void ReadRegistrySettings
               (undefined8 param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int local_res8 [2];
  longlong local_58;
  longlong local_50 [2];
  wchar_t *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  
  local_50[0] = 0;
  local_58 = 0;
  local_34 = 0;
  local_28 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  local_38 = 0x1801a9;
  local_30 = param_1;
  local_res8[0] = NdisOpenConfigurationEx(&local_38,local_50);
  if (local_res8[0] < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,local_res8[0]);
    }
    *param_3 = local_res8[0];
  }
  else {
    *param_2 = 30000;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,30000);
    }
    local_40 = L"HelloDurationPerTick";
    local_50[1] = 0x2a0028;
    NdisReadConfiguration(local_res8,&local_58,local_50[0],local_50 + 1,0);
    if (local_res8[0] == 0) {
      iVar1 = *(int *)(local_58 + 8);
      *param_4 = iVar1;
      if (iVar1 == 0) {
        local_res8[0] = -0x3ffeffeb;
      }
    }
    else {
      *param_4 = 10;
      local_res8[0] = 0;
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,local_res8[0]);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,*param_4);
      }
    }
    local_40 = L"HelloTicks";
    local_50[1] = 0x160014;
    NdisReadConfiguration(local_res8,&local_58,local_50[0],local_50 + 1,0);
    if (local_res8[0] == 0) {
      iVar1 = *(int *)(local_58 + 8);
      *param_5 = iVar1;
      if (iVar1 == 0) {
        local_res8[0] = -0x3ffeffeb;
      }
    }
    else {
      *param_5 = 6;
      local_res8[0] = 0;
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,local_res8[0]);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,*param_5);
      }
    }
  }
  if (local_50[0] != 0) {
    NdisCloseConfiguration();
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  return;
}



===== SmpHaltEx @ 140010130 =====

void SmpHaltEx(void)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  *(undefined8 *)(SstpGlobals + 0xa8) = 0;
  *(undefined4 *)(SstpGlobals + 0xa0) = 0;
  return;
}



===== SmpInitializeEx @ 1400101a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmpInitializeEx(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined1 auStackY_1e8 [32];
  int local_1b8 [2];
  undefined8 local_1b0;
  longlong lStack_1a8;
  undefined8 local_1a0;
  ulonglong uStack_198;
  undefined4 local_188 [2];
  undefined8 local_180;
  undefined4 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_138;
  undefined4 local_134;
  undefined2 local_12c;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined2 local_d4;
  undefined1 local_d2;
  undefined4 local_cc;
  undefined4 *local_c0;
  undefined4 local_b8;
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_1b8[0] = 0;
  local_1b0 = 0;
  lStack_1a8 = 0;
  local_1a0 = 0;
  uStack_198 = 0;
  memset(local_188,0,0xe0);
  local_a8 = 0x801;
  local_a4 = 6;
  local_98 = 0;
  uStack_90 = 0;
  local_68 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_a0 = 0x1e;
  local_58 = 0x4010105;
  local_54 = 0x4010180;
  local_50 = 0x4010182;
  local_4c = 0x4010181;
  local_48 = 0xfe001001;
  local_44 = 0xfe001002;
  local_40 = 0xfe001003;
  local_3c = 0xfe001007;
  local_38 = 0xfd010100;
  local_34 = 0xfd010101;
  local_30 = 0xfd010102;
  local_2c = 0x1010c;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  *(undefined4 *)(SstpGlobals + 0xc0) = 1000;
  *(undefined4 *)(SstpGlobals + 0xbc) = 0;
  *(undefined4 *)(SstpGlobals + 0xb8) = 0x700;
  *(undefined4 *)(SstpGlobals + 0xb0) = 0xffb;
  *(undefined4 *)(SstpGlobals + 0xb4) = 0x20;
  KeInitializeSpinLock(SstpGlobals + 200);
  KeInitializeSpinLock(SstpGlobals + 0x1b8);
  piVar3 = local_1b8;
  *(undefined4 *)(SstpGlobals + 0x1c0) = 0;
  *(undefined8 *)(SstpGlobals + 0x1c8) = 0;
  *(undefined8 *)(SstpGlobals + 0xa8) = param_1;
  ReadRegistrySettings
            (param_1,(undefined4 *)(SstpGlobals + 0xc0),piVar3,(int *)(SstpGlobals + 0x204),
             (int *)(SstpGlobals + 0x200));
  iVar1 = local_1b8[0];
  if (local_1b8[0] < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return local_1b8[0];
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
    }
    goto LAB_14001059e;
  }
  lStack_1a8 = SstpGlobals + 0x90;
  local_1b0 = CONCAT44(local_1b0._4_4_,0x20029e);
  local_1a0 = 0x20;
  uStack_198 = uStack_198 & 0xffffffff00000000;
  iVar1 = NdisMSetMiniportAttributes(param_1,&local_1b0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_14001059e;
    uVar2 = 0x19;
  }
  else {
    local_188[0] = 0xe0029f;
    local_170 = 0xffffffffffffffff;
    local_160 = 0xffffffffffffffff;
    local_168 = 0xffffffffffffffff;
    local_158 = 0xffffffffffffffff;
    local_b0 = &local_98;
    local_d4 = 0x83;
    local_c0 = &local_58;
    local_178 = 0xffb;
    local_148 = 0xffb;
    local_180 = 0xc;
    local_150 = 0;
    local_98 = CONCAT44(local_98._4_4_,0x3c0280);
    uStack_70 = 0;
    local_68 = local_68 & 0xffffffff00000000;
    local_138 = 5;
    local_134 = 1;
    local_12c = 0;
    local_e8 = 0;
    local_e0 = 3;
    local_d8 = 1;
    local_d2 = 0;
    local_cc = 0;
    local_b8 = 0x30;
    iVar1 = NdisMSetMiniportAttributes(param_1,local_188);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_14001059e;
      uVar2 = 0x1a;
    }
    else {
      iVar1 = NdisMCmRegisterAddressFamilyEx(param_1,&local_a8);
      if (-1 < iVar1) {
        *(undefined4 *)(SstpGlobals + 0xa0) = 1;
        goto LAB_14001059e;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_14001059e;
      uVar2 = 0x1b;
    }
  }
  WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,piVar3,iVar1,(char)iVar1);
LAB_14001059e:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids);
  }
  return iVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140010604 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== ScmCmCompleteIrpPassive @ 1400106d0 =====

void ScmCmCompleteIrpPassive(longlong param_1,undefined8 param_2)

{
  NdisFreeIoWorkItem(param_2);
  if (*(char *)(SstpGlobals + 0x239) == '\0') {
    MmLockPagableDataSection(SmpReturnNetBufferListChain);
    *(undefined1 *)(SstpGlobals + 0x239) = 1;
  }
  if (param_1 != 0) {
    IofCompleteRequest(param_1,0);
  }
  return;
}



===== FipsDeInit @ 14001073c =====

void FipsDeInit(undefined8 *param_1)

{
  ObfDereferenceObject(*param_1);
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



===== FipsInit @ 14001076c =====

int FipsInit(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = param_1 + 1;
  *param_1 = 0;
  *plVar1 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_48,L"\\Device\\KsecDD");
  iVar2 = IoGetDeviceObjectPointer(&local_48,0x1f01ff,param_1,plVar1);
  if (-1 < iVar2) {
    KeInitializeEvent(&local_28,1);
    lVar3 = IoBuildDeviceIoControlRequest
                      (0x390024,*plVar1,0,0,param_1 + 2,0x80,0,&local_28,&local_38);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = IofCallDriver(*plVar1,lVar3);
      if (iVar2 == 0x103) {
        iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
        if (iVar2 == 0) {
          iVar2 = (int)local_38;
        }
      }
      if (-1 < iVar2) {
        return iVar2;
      }
    }
  }
  if (*param_1 != 0) {
    ObfDereferenceObject();
    *param_1 = 0;
    *plVar1 = 0;
  }
  return iVar2;
}



===== RegisterTPIWithFsm @ 1400108d0 =====

NTSTATUS RegisterTPIWithFsm(undefined4 *param_1,undefined4 *param_2,undefined8 param_3,
                           undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  NTSTATUS NVar10;
  NTSTATUS NVar11;
  undefined1 *puVar12;
  longlong lVar13;
  undefined2 uVar14;
  
  NVar10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  puVar12 = (undefined1 *)ExAllocatePool2(0x40,0x1c0,0x69676653);
  SstpFsmGlobalInfo = puVar12;
  if (puVar12 == (undefined1 *)0x0) {
    NVar10 = -0x3fffff66;
    goto LAB_140010cdc;
  }
  LOCK();
  UNLOCK();
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  uVar5 = param_1[4];
  uVar6 = param_1[5];
  uVar7 = param_1[6];
  uVar8 = param_1[7];
  *(undefined8 *)(puVar12 + 0x1a0) = param_3;
  *(undefined4 *)(puVar12 + 0x60) = uVar1;
  *(undefined4 *)(puVar12 + 100) = uVar2;
  *(undefined4 *)(puVar12 + 0x68) = uVar3;
  *(undefined4 *)(puVar12 + 0x6c) = uVar4;
  *(undefined4 *)(puVar12 + 0x70) = uVar5;
  *(undefined4 *)(puVar12 + 0x74) = uVar6;
  *(undefined4 *)(puVar12 + 0x78) = uVar7;
  *(undefined4 *)(puVar12 + 0x7c) = uVar8;
  lVar13 = IoAllocateWorkItem(param_3);
  puVar12 = SstpFsmGlobalInfo;
  *(longlong *)(SstpFsmGlobalInfo + 0x1a8) = lVar13;
  if (lVar13 == 0) {
    NVar10 = -0x3fffff66;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,
               &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,0xc000009a);
    }
  }
  else {
    KeInitializeSpinLock(puVar12 + 0x18);
    *(undefined4 *)(puVar12 + 0x20) = 0;
    puVar12[0x40] = 1;
    KeInitializeEvent(puVar12 + 0x28,0,1);
    puVar12 = SstpFsmGlobalInfo;
    uVar1 = *param_2;
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    param_4[3] = FsmTpiControlFrameSendComplete;
    param_4[2] = FsmTpiDisconnectCall;
    *param_4 = FsmTpiNewCall;
    param_4[1] = FsmTpiProcessControlFrame;
    param_4[4] = FsmTpiSetDataReceivedStatus;
    param_4[5] = FsmTpiSetCryptoBindingKeys;
    *(undefined4 *)(puVar12 + 4) = uVar1;
    *(undefined4 *)(puVar12 + 8) = uVar2;
    *(undefined4 *)(puVar12 + 0xc) = uVar3;
    *(undefined4 *)(puVar12 + 0x10) = uVar4;
    if ((*(byte *)(param_2 + 2) & 1) == 0) {
LAB_140010ad7:
      if ((*(byte *)(param_2 + 2) & 2) == 0) {
LAB_140010b3d:
        if (*(char *)(param_2 + 2) != '\0') {
          NVar10 = FipsInit((longlong *)(SstpFsmGlobalInfo + 0x110));
          if (NVar10 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
                       &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar10);
            }
            if (*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x108) != (BCRYPT_ALG_HANDLE)0x0) {
              NVar11 = BCryptCloseAlgorithmProvider
                                 (*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x108),0);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar14 = 0x8c;
                goto LAB_140010bd3;
              }
            }
            goto LAB_140010bdf;
          }
        }
        puVar12 = SstpFsmGlobalInfo;
        NdisGetVersion();
        ExInitializeNPagedLookasideList(puVar12 + 0x80,0,0,0x200,0x1018,0x666c6353,0);
        KeInitializeSpinLock(SstpFsmGlobalInfo + 0x48);
        puVar9 = SstpFsmGlobalInfo;
        puVar12 = SstpFsmGlobalInfo + 0x50;
        *(undefined1 **)(SstpFsmGlobalInfo + 0x58) = puVar12;
        *(undefined1 **)puVar12 = puVar12;
        *puVar9 = 1;
        goto LAB_140010cdc;
      }
      NVar10 = BCryptOpenAlgorithmProvider
                         ((BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x108),L"SHA256",(LPCWSTR)0x0,8)
      ;
      if (-1 < NVar10) goto LAB_140010b3d;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar14 = 0x8a;
        NVar11 = NVar10;
LAB_140010bd3:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                 &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar11);
      }
LAB_140010bdf:
      if (*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x100) != (BCRYPT_ALG_HANDLE)0x0) {
        NVar11 = BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(SstpFsmGlobalInfo + 0x100),0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar14 = 0x8d;
          goto LAB_140010c1e;
        }
      }
    }
    else {
      NVar10 = BCryptOpenAlgorithmProvider
                         ((BCRYPT_ALG_HANDLE *)(puVar12 + 0x100),L"SHA1",(LPCWSTR)0x0,8);
      if (-1 < NVar10) goto LAB_140010ad7;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar14 = 0x89;
        NVar11 = NVar10;
LAB_140010c1e:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                 &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar11);
      }
    }
    IoFreeWorkItem(*(undefined8 *)(SstpFsmGlobalInfo + 0x1a8));
  }
  ExFreePoolWithTag(SstpFsmGlobalInfo,0x69676653);
  SstpFsmGlobalInfo = (undefined1 *)0x0;
LAB_140010cdc:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8e,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return NVar10;
}



===== WppLoadTracingSupport @ 140010d30 =====

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



===== DelinProcessSstpControlFrame @ 140011010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DelinProcessSstpControlFrame(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (**(code **)(SstpGlobals + 0x210))(param_3,param_1,param_2);
  return;
}



===== GenerateMsChapV2MasterSessionKey @ 140011040 =====

void GenerateMsChapV2MasterSessionKey
               (longlong param_1,undefined8 param_2,undefined8 param_3,PUCHAR param_4,
               undefined8 param_5,char param_6)

{
  PUCHAR pUVar1;
  undefined8 in_stack_ffffffffffffffe0;
  
  pUVar1 = param_4;
  GenerateShaHashForMsChapV2Key
            ((PUCHAR)(param_1 + 0x10),param_2,(PUCHAR)(param_1 + 0x28),param_4,(PUCHAR)param_2,
             in_stack_ffffffffffffffe0,param_6,'\x01');
  GenerateShaHashForMsChapV2Key
            ((PUCHAR)(param_1 + 0x180),param_2,(PUCHAR)(param_1 + 0x198),pUVar1,param_4,
             in_stack_ffffffffffffffe0,param_6,'\0');
  return;
}



===== GenerateShaHashForMsChapV2Key @ 1400110ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GenerateShaHashForMsChapV2Key
               (PUCHAR param_1,undefined8 param_2,PUCHAR param_3,undefined8 param_4,PUCHAR param_5,
               undefined8 param_6,char param_7,char param_8)

{
  char *pcVar1;
  char *pcVar2;
  longlong lVar3;
  undefined1 auStack_b8 [32];
  BCRYPT_HASH_HANDLE local_98;
  UCHAR local_90 [80];
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_90[0] = '\0';
  local_90[1] = '\0';
  local_90[2] = '\0';
  local_90[3] = '\0';
  local_90[4] = '\0';
  local_90[5] = '\0';
  local_90[6] = '\0';
  local_90[7] = '\0';
  local_90[8] = '\0';
  local_90[9] = '\0';
  local_90[10] = '\0';
  local_90[0xb] = '\0';
  local_90[0xc] = '\0';
  local_90[0xd] = '\0';
  local_90[0xe] = '\0';
  local_90[0xf] = '\0';
  local_90[0x10] = '\0';
  local_90[0x11] = '\0';
  local_90[0x12] = '\0';
  local_90[0x13] = '\0';
  local_90[0x14] = '\0';
  local_90[0x15] = '\0';
  local_90[0x16] = '\0';
  local_90[0x17] = '\0';
  local_90[0x18] = '\0';
  local_90[0x19] = '\0';
  local_90[0x1a] = '\0';
  local_90[0x1b] = '\0';
  local_90[0x1c] = '\0';
  local_90[0x1d] = '\0';
  local_90[0x1e] = '\0';
  local_90[0x1f] = '\0';
  local_90[0x20] = '\0';
  local_90[0x21] = '\0';
  local_90[0x22] = '\0';
  local_90[0x23] = '\0';
  local_90[0x24] = '\0';
  local_90[0x25] = '\0';
  local_90[0x26] = '\0';
  local_90[0x27] = '\0';
  local_98 = (BCRYPT_HASH_HANDLE)0x0;
  local_90[0x28] = 0xf2;
  local_90[0x29] = 0xf2;
  local_90[0x2a] = 0xf2;
  local_90[0x2b] = 0xf2;
  local_90[0x2c] = 0xf2;
  local_90[0x2d] = 0xf2;
  local_90[0x2e] = 0xf2;
  local_90[0x2f] = 0xf2;
  local_90[0x30] = 0xf2;
  local_90[0x31] = 0xf2;
  local_90[0x32] = 0xf2;
  local_90[0x33] = 0xf2;
  local_90[0x34] = 0xf2;
  local_90[0x35] = 0xf2;
  local_90[0x36] = 0xf2;
  local_90[0x37] = 0xf2;
  local_90[0x38] = 0xf2;
  local_90[0x39] = 0xf2;
  local_90[0x3a] = 0xf2;
  local_90[0x3b] = 0xf2;
  local_90[0x3c] = 0xf2;
  local_90[0x3d] = 0xf2;
  local_90[0x3e] = 0xf2;
  local_90[0x3f] = 0xf2;
  local_90[0x40] = 0xf2;
  local_90[0x41] = 0xf2;
  local_90[0x42] = 0xf2;
  local_90[0x43] = 0xf2;
  local_90[0x44] = 0xf2;
  local_90[0x45] = 0xf2;
  local_90[0x46] = 0xf2;
  local_90[0x47] = 0xf2;
  local_90[0x48] = 0xf2;
  local_90[0x49] = 0xf2;
  local_90[0x4a] = 0xf2;
  local_90[0x4b] = 0xf2;
  local_90[0x4c] = 0xf2;
  local_90[0x4d] = 0xf2;
  local_90[0x4e] = 0xf2;
  local_90[0x4f] = 0xf2;
  CngRsa32Compat_SHAInit(&local_98);
  CngRsa32Compat_SHAUpdate(&local_98,param_1,0x10);
  CngRsa32Compat_SHAUpdate(&local_98,param_3,0x18);
  CngRsa32Compat_SHAUpdate(&local_98,(PUCHAR)"This is the MPPE Master Key",0x1b);
  CngRsa32Compat_SHAFinal(&local_98,(PUCHAR)&local_40);
  pcVar1 = "On the client side, this is the send key; on the server side, it is the receive key.";
  pcVar2 = "On the client side, this is the receive key; on the server side, it is the send key.";
  *(undefined8 *)param_5 = local_40;
  *(undefined8 *)(param_5 + 8) = uStack_38;
  if (param_8 == '\0') {
    if (param_7 == '\0') {
      pcVar1 = 
      "On the client side, this is the receive key; on the server side, it is the send key.";
    }
    pcVar2 = pcVar1;
  }
  else if (param_7 == '\0') {
    pcVar2 = "On the client side, this is the send key; on the server side, it is the receive key.";
  }
  CngRsa32Compat_SHAInit(&local_98);
  CngRsa32Compat_SHAUpdate(&local_98,param_5,0x10);
  CngRsa32Compat_SHAUpdate(&local_98,local_90,0x28);
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (pcVar2[lVar3] != '\0');
  CngRsa32Compat_SHAUpdate(&local_98,(PUCHAR)pcVar2,(ULONG)lVar3);
  CngRsa32Compat_SHAUpdate(&local_98,local_90 + 0x28,0x28);
  CngRsa32Compat_SHAFinal(&local_98,(PUCHAR)&local_40);
  *(undefined8 *)param_5 = local_40;
  *(undefined8 *)(param_5 + 8) = uStack_38;
  return;
}



===== BuildCallParams @ 140011254 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong BuildCallParams(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  wchar_t *pwVar6;
  uint uVar7;
  wchar_t *pwVar8;
  short *psVar9;
  size_t sVar10;
  longlong lVar11;
  short *psVar12;
  undefined1 auStack_f8 [32];
  size_t local_d8 [2];
  wchar_t local_c8 [72];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  lVar11 = 0;
  psVar9 = (short *)((ulonglong)*(uint *)(param_1 + 4) + param_1);
  psVar12 = (short *)((ulonglong)*(uint *)(param_1 + 8) + param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  lVar4 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x74) + 0x358,0x6d704353);
  if (lVar4 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    lVar4 = lVar11;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
  }
  else {
    puVar5 = (uint *)(lVar4 + 0xa8);
    *(undefined4 *)(lVar4 + 0x18) = 12500000;
    *(undefined4 *)(lVar4 + 0x20) = 12500000;
    *(undefined4 *)(lVar4 + 0x30) = 0xfff;
    *(undefined4 *)(lVar4 + 0x38) = 12500000;
    *(undefined4 *)(lVar4 + 0x40) = 12500000;
    *(undefined4 *)(lVar4 + 0x50) = 0xfff;
    *(undefined4 **)(lVar4 + 8) = (undefined4 *)(lVar4 + 0x18);
    *(longlong *)(lVar4 + 0x10) = lVar4 + 0x68;
    *(undefined4 *)(lVar4 + 0x80) = param_2;
    *(undefined2 *)(lVar4 + 0x90) = 0x2b0;
    if (*(uint *)(param_1 + 0x74) < 0x10000) {
      uVar2 = *(short *)(param_1 + 0x74) + 0x2b0;
      if (0x2af < uVar2) {
        *(ushort *)(lVar4 + 0x90) = uVar2;
        *(ushort *)(lVar4 + 0x92) = uVar2;
        *(ulonglong *)(lVar4 + 0x98) =
             (ulonglong)(((int)puVar5 - (int)(undefined4 *)(lVar4 + 0x80)) - 0x10);
        *(undefined4 *)(lVar4 + 0x70) = 0xfff;
        *(uint *)(lVar4 + 0x7c) = *(ushort *)(lVar4 + 0x90) + 0x20;
        *puVar5 = (uint)*(ushort *)(lVar4 + 0x90);
        *(uint *)(lVar4 + 0xac) = (uint)*(ushort *)(lVar4 + 0x90);
        *(uint *)(lVar4 + 0xb0) = (uint)*(ushort *)(lVar4 + 0x90);
        *(undefined4 *)(lVar4 + 0xb8) = *(undefined4 *)(SstpGlobals + 0x1d0);
        *(undefined4 *)(lVar4 + 0xbc) = *(undefined4 *)(SstpGlobals + 0x1d4);
        iVar3 = *(int *)(param_1 + 0x74);
        *(undefined4 *)(lVar4 + 0x1cc) = 0x158;
        *(int *)(lVar4 + 0x1c8) = iVar3 + 0x44;
        *(undefined4 *)(lVar4 + 0x224) = 0x10;
        *(undefined4 *)(lVar4 + 0x220) = 0x34;
        uVar1 = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(lVar4 + 0x234) = *(undefined8 *)(param_1 + 0x60);
        *(undefined8 *)(lVar4 + 0x23c) = uVar1;
        if (*(int *)(param_1 + 0x74) != 0) {
          *(undefined4 *)(lVar4 + 0x228) = 0x44;
          *(undefined4 *)(lVar4 + 0x22c) = *(undefined4 *)(param_1 + 0x74);
          memmove((void *)(lVar4 + 0x244),(void *)((ulonglong)*(uint *)(param_1 + 0x70) + param_1),
                  (ulonglong)*(uint *)(param_1 + 0x74));
        }
        *(undefined4 *)(lVar4 + 0x114) = 8;
        uVar7 = *(int *)(lVar4 + 0x1cc) + *(int *)(lVar4 + 0x1c8) + 7 & 0xfffffff8;
        *(uint *)(lVar4 + 0x11c) = uVar7;
        pwVar8 = (wchar_t *)((ulonglong)uVar7 + (longlong)puVar5);
        memset(local_c8,0,0x82);
        pwVar6 = local_c8;
        local_d8[0] = 0;
        if (*psVar9 == 2) {
          RtlIpv4AddressToStringW(psVar9 + 2);
        }
        else {
          RtlIpv6AddressToStringW(psVar9 + 4);
        }
        StringCchLengthW(local_c8,(size_t)pwVar6,local_d8);
        sVar10 = local_d8[0] * 2 + 2;
        memmove(pwVar8,local_c8,sVar10);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,sVar10,pwVar8);
        }
        iVar3 = StrLenW(pwVar8);
        uVar7 = *(int *)(lVar4 + 0x11c) + 0x8fU & 0xfffffff8;
        *(undefined4 *)(lVar4 + 0x128) = 8;
        *(uint *)(lVar4 + 0x130) = uVar7;
        *(int *)(lVar4 + 0x118) = iVar3 * 2 + 2;
        pwVar8 = (wchar_t *)((ulonglong)uVar7 + (longlong)puVar5);
        memset(local_c8,0,0x82);
        pwVar6 = local_c8;
        local_d8[0] = 0;
        if (*psVar12 == 2) {
          RtlIpv4AddressToStringW(psVar12 + 2);
        }
        else {
          RtlIpv6AddressToStringW(psVar12 + 4);
        }
        StringCchLengthW(local_c8,(size_t)pwVar6,local_d8);
        sVar10 = local_d8[0] * 2 + 2;
        memmove(pwVar8,local_c8,sVar10);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,sVar10,pwVar8);
        }
        iVar3 = StrLenW(pwVar8);
        *(undefined4 *)(lVar4 + 0xc0) = 8;
        *(int *)(lVar4 + 300) = iVar3 * 2 + 2;
        goto LAB_140011634;
      }
      *(undefined2 *)(lVar4 + 0x90) = 0xffff;
    }
    ExFreePoolWithTag(lVar4 + 0x200,0x6d704353);
  }
LAB_140011634:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return lVar4;
}



===== DPChannelDestroyPassive @ 1400116a0 =====

void DPChannelDestroyPassive(undefined8 param_1,undefined8 param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  NdisFreeIoWorkItem(param_2);
  DPChannelDestroy0(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== DisconnectIrpCancelRoutine @ 140011750 =====

void DisconnectIrpCancelRoutine(undefined8 param_1,longlong param_2,undefined *param_3)

{
  int *piVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    param_3 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  piVar1 = *(int **)(param_2 + 0x78);
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 8);
  piVar1[0x12] = 0;
  piVar1[0x13] = 0;
  piVar1[0x496] = piVar1[0x496] & 0xffffffdf;
  if ((char)piVar1[0x497] == '\0') {
    InitiateSstpContextCleanup
              (piVar1,2,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar2));
  }
  else {
    KeReleaseSpinLock(piVar1 + 8,uVar2);
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  DereferenceRefCount(piVar1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== DispatchIncomingCallCancelIrp @ 140011870 =====

void DispatchIncomingCallCancelIrp(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  piVar1 = *(int **)(param_2 + 0x78);
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 8);
  piVar1[0xe] = 0;
  piVar1[0xf] = 0;
  KeReleaseSpinLock(piVar1 + 8,uVar2);
  DereferenceRefCount(piVar1);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== DispatchIncomingCallConnectedCancelIrp @ 140011960 =====

void DispatchIncomingCallConnectedCancelIrp(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  piVar1 = *(int **)(param_2 + 0x78);
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 8);
  piVar1[0x10] = 0;
  piVar1[0x11] = 0;
  KeReleaseSpinLock(piVar1 + 8,uVar2);
  DereferenceRefCount(piVar1);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  return;
}



===== ProcessDisconnectCallRequest @ 1400119e4 =====

int ProcessDisconnectCallRequest(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  int *local_res10;
  
  local_res10 = (int *)0x0;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  if (*(int *)(lVar2 + 0x10) == 8) {
    uVar1 = **(undefined4 **)(param_1 + 0x18);
    uVar3 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    iVar4 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),uVar1,&local_res10);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
      }
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
    }
    else {
      *(int **)(param_1 + 0x78) = local_res10;
      LOCK();
      *local_res10 = *local_res10 + 1;
      UNLOCK();
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
      uVar3 = KeAcquireSpinLockRaiseToDpc(local_res10 + 8);
      if (((char)local_res10[0x497] == '\0') && (local_res10[0x496] != 0)) {
        *(longlong *)(local_res10 + 0x12) = param_1;
        local_res10[0x496] = local_res10[0x496] | 0x20;
        uVar5 = SetCancelRoutineSafe(param_1,DisconnectIrpCancelRoutine);
        if ((char)uVar5 != '\0') {
          iVar4 = 0x103;
          KeReleaseSpinLock(local_res10 + 8,uVar3);
          goto LAB_140011c6c;
        }
        local_res10[0x12] = 0;
        local_res10[0x13] = 0;
        KeReleaseSpinLock(local_res10 + 8);
        DereferenceRefCount(local_res10);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res10 + 0x79);
        }
        if (iVar4 == 0x103) goto LAB_140011c6c;
        goto LAB_140011c64;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res10 + 0x79);
      }
      KeReleaseSpinLock(local_res10 + 8,uVar3);
      DereferenceRefCount(local_res10);
    }
    iVar4 = -0x3ffffddb;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
    iVar4 = -0x3ffffff3;
  }
LAB_140011c64:
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x30) = iVar4;
LAB_140011c6c:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return iVar4;
}



===== ProcessIncomingCallConnectedRequest @ 140011cb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ProcessIncomingCallConnectedRequest(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  int **ppiVar6;
  undefined *puVar7;
  bool bVar8;
  int *local_res8;
  
  local_res8 = (int *)0x0;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  bVar8 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  if (*(int *)(lVar2 + 0x10) == 4) {
    uVar1 = **(undefined4 **)(param_1 + 0x18);
    uVar3 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    ppiVar6 = &local_res8;
    iVar4 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),uVar1,ppiVar6);
    if (iVar4 < 0) {
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
      }
      iVar4 = -0x3ffffddb;
    }
    else {
      *(int **)(param_1 + 0x78) = local_res8;
      uVar5 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
      bVar8 = (int)uVar5 != 0;
      if (bVar8) {
        LOCK();
        *local_res8 = *local_res8 + 1;
        UNLOCK();
      }
      LOCK();
      *local_res8 = *local_res8 + 1;
      UNLOCK();
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar3);
      uVar3 = KeAcquireSpinLockRaiseToDpc(local_res8 + 8);
      *(longlong *)(local_res8 + 0x10) = param_1;
      KeReleaseSpinLock(local_res8 + 8,uVar3);
      uVar5 = SetCancelRoutineSafe(param_1,DispatchIncomingCallConnectedCancelIrp);
      if ((char)uVar5 == '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          ppiVar6 = (int **)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res8 + 0x79);
        }
        uVar3 = KeAcquireSpinLockRaiseToDpc(local_res8 + 8);
        local_res8[0x10] = 0;
        local_res8[0x11] = 0;
        InitiateSstpContextCleanup
                  (local_res8,4,(undefined *)CONCAT71((int7)((ulonglong)ppiVar6 >> 8),uVar3));
        DereferenceRefCount(local_res8);
      }
      else {
        uVar3 = KeAcquireSpinLockRaiseToDpc(local_res8 + 8);
        local_res8[0x496] = local_res8[0x496] | 2;
        KeReleaseSpinLock(local_res8 + 8,uVar3);
        puVar7 = (undefined *)0x0;
        iVar4 = (**(code **)(SstpGlobals + 0x208))
                          (local_res8,0,1,
                           CONCAT71((int7)((ulonglong)((longlong)local_res8 + 0x129) >> 8),
                                    (char)local_res8[0x4a]),(longlong)local_res8 + 0x129,
                           (longlong)local_res8 + 0x13d,local_res8 + 0x79);
        if (iVar4 < 0) {
          uVar3 = KeAcquireSpinLockRaiseToDpc(local_res8 + 8);
          local_res8[0x496] = local_res8[0x496] & 0xfffffffd;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            puVar7 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
            WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                           &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res8 + 0x79,
                           (char)iVar4);
          }
          InitiateSstpContextCleanup
                    (local_res8,4,(undefined *)CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar3));
          LOCK();
          *(undefined8 *)(param_1 + 0x68) = 0;
          UNLOCK();
          *(undefined8 *)(param_1 + 0x38) = 0;
          *(int *)(param_1 + 0x30) = iVar4;
          IofCompleteRequest(param_1,0);
          iVar4 = 0x103;
          goto LAB_140011ef0;
        }
      }
      if (iVar4 == 0x103) goto LAB_140011ef0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
    iVar4 = -0x3ffffff3;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(int *)(param_1 + 0x30) = iVar4;
LAB_140011ef0:
  uVar5 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 != 0) && (bVar8)) {
    DereferenceRefCount(local_res8);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return iVar4;
}



===== ProcessIncomingCallRequest @ 140012070 =====

int ProcessIncomingCallRequest(longlong param_1,undefined8 param_2,undefined *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined1 uVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined2 uVar14;
  uint uVar15;
  uint *puVar16;
  code *pcVar17;
  uint *puVar18;
  uint *puVar19;
  undefined *puVar20;
  uint local_res8 [2];
  uint *local_res10;
  ulonglong *local_res18;
  ulonglong *local_res20;
  
  local_res10 = (uint *)0x0;
  local_res8[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    param_3 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  uVar15 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if ((uVar3 < 0x78) || (uVar15 < 0x78)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))) {
      WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar15,param_3,uVar3,
                 (char)uVar15);
    }
  }
  else {
    puVar4 = *(uint **)(param_1 + 0x18);
    if (((ulonglong)uVar3 - 0x10 < (ulonglong)puVar4[1]) ||
       ((ulonglong)uVar3 - 0x10 < (ulonglong)puVar4[2])) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        uVar14 = 0x28;
LAB_1400125e5:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
      }
    }
    else {
      uVar15 = puVar4[0x1d] + puVar4[0x1c];
      if ((puVar4[0x1c] <= uVar15) && (uVar15 <= uVar3)) {
        iVar9 = ScmCmCreateVc(0,0,&local_res10);
        puVar7 = local_res10;
        if (iVar9 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar9;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                     &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,iVar9);
          }
          goto LAB_140012642;
        }
        *(undefined1 *)((longlong)local_res10 + 0x1f9) = 1;
        local_res18 = (ulonglong *)(local_res10 + 0x49a);
        *local_res18 = *(ulonglong *)(puVar4 + 4);
        local_res20 = (ulonglong *)(local_res10 + 0x49c);
        *local_res20 = *(ulonglong *)(puVar4 + 6);
        uVar10 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
        puVar18 = puVar7;
        if ((int)uVar10 == 0) {
LAB_140012279:
          uVar6 = *(undefined8 *)(puVar4 + 0xc);
          puVar16 = puVar7 + 0x79;
          *(undefined8 *)((longlong)puVar7 + 0x129) = *(undefined8 *)(puVar4 + 10);
          *(undefined8 *)((longlong)puVar7 + 0x131) = uVar6;
          *(uint *)((longlong)puVar7 + 0x139) = puVar4[0xe];
          uVar6 = *(undefined8 *)(puVar4 + 0x11);
          *(undefined8 *)((longlong)puVar7 + 0x13d) = *(undefined8 *)(puVar4 + 0xf);
          *(undefined8 *)((longlong)puVar7 + 0x145) = uVar6;
          uVar6 = *(undefined8 *)(puVar4 + 0x15);
          *(undefined8 *)((longlong)puVar7 + 0x14d) = *(undefined8 *)(puVar4 + 0x13);
          *(undefined8 *)((longlong)puVar7 + 0x155) = uVar6;
          uVar3 = puVar4[0x19];
          uVar15 = puVar4[0x1a];
          uVar5 = puVar4[0x1b];
          *puVar16 = puVar4[0x18];
          puVar7[0x7a] = uVar3;
          puVar7[0x7b] = uVar15;
          puVar7[0x7c] = uVar5;
          *(char *)(puVar7 + 0x4a) = (char)puVar4[0x17];
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                          &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,puVar16);
          }
          puVar1 = puVar7 + 10;
          uVar10 = *(ulonglong *)(SstpGlobals + 0x30);
          puVar19 = puVar7;
          iVar9 = NdisMCmCreateVc(*(undefined8 *)(SstpGlobals + 0xa8),uVar10,puVar7,puVar1);
          if (iVar9 == 0) {
            uVar11 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar11 == 0) {
              puVar12 = (undefined *)BuildCallParams_Old((longlong)puVar4);
            }
            else {
              uVar10 = (ulonglong)local_res8[0];
              puVar12 = (undefined *)BuildCallParams((longlong)puVar4,local_res8[0]);
            }
            puVar18 = local_res10;
            if (puVar12 == (undefined *)0x0) {
              iVar9 = -0x3fffff66;
              puVar18 = puVar7;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                uVar10 = 0x2e;
                puVar19 = (uint *)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
                WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,puVar16);
              }
            }
            else {
              puVar2 = puVar7 + 0x48c;
              *(undefined **)puVar2 = puVar12;
              *(uint **)(param_1 + 0x78) = puVar7;
              puVar7[0x1d] = *puVar4;
              LOCK();
              *puVar7 = *puVar7 + 1;
              UNLOCK();
              puVar4 = local_res10 + 8;
              uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4);
              *(longlong *)(puVar18 + 0xe) = param_1;
              KeReleaseSpinLock(puVar4,uVar8);
              pcVar17 = DispatchIncomingCallCancelIrp;
              uVar10 = SetCancelRoutineSafe(param_1,DispatchIncomingCallCancelIrp);
              if ((char)uVar10 != '\0') {
                uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4);
                puVar18[0x496] = puVar18[0x496] | 0x101;
                KeReleaseSpinLock(puVar4,uVar8);
                uVar13 = (undefined4)(*local_res18 >> 3);
                **(undefined4 **)(puVar12 + 8) = uVar13;
                *(undefined4 *)(*(longlong *)(puVar12 + 8) + 8) = uVar13;
                *(undefined4 *)(*(longlong *)(puVar12 + 8) + 0x18) = 0xfff;
                uVar13 = (undefined4)(*local_res20 >> 3);
                *(undefined4 *)(*(longlong *)(puVar12 + 8) + 0x20) = uVar13;
                *(undefined4 *)(*(longlong *)(puVar12 + 8) + 0x28) = uVar13;
                *(undefined4 *)(*(longlong *)(puVar12 + 8) + 0x38) = 0xfff;
                puVar20 = puVar12;
                iVar9 = NdisCmDispatchIncomingCall
                                  (*(undefined8 *)(SstpGlobals + 0x1c8),*(undefined8 *)puVar1);
                if (iVar9 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (WPP_GLOBAL_Control[0x29] != '\0')) {
                    WPP_SF__guid_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,puVar20,puVar16,
                                    (char)iVar9,(char)iVar9);
                  }
                  ScmCmIncomingCallComplete(iVar9,(int *)puVar18,puVar12);
                }
                iVar9 = 0x103;
                goto LAB_140012642;
              }
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                puVar19 = (uint *)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
                pcVar17 = (code *)0x0;
                WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,puVar16);
              }
              *(undefined8 *)(param_1 + 0x38) = 0;
              iVar9 = -0x3ffffee0;
              *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
              uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4);
              puVar18[0xe] = 0;
              puVar18[0xf] = 0;
              uVar10 = CONCAT71((int7)((ulonglong)pcVar17 >> 8),uVar8);
              KeReleaseSpinLock(puVar4);
              DereferenceRefCount((int *)puVar18);
              FreeCallParams((longlong)puVar12);
              puVar2[0] = 0;
              puVar2[1] = 0;
            }
            NdisMCmDeleteVc(*(undefined8 *)puVar1);
          }
          else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                  (WPP_GLOBAL_Control[0x29] != '\0')) {
            puVar19 = (uint *)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
            uVar10 = 0x2d;
            WPP_SF__guid_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,puVar16,(char)iVar9,
                            (char)iVar9);
          }
        }
        else {
          uVar8 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
          puVar16 = puVar7 + 0x79;
          puVar19 = local_res8;
          iVar9 = HfAllocateHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),puVar16);
          uVar10 = CONCAT71((int7)((ulonglong)puVar16 >> 8),uVar8);
          KeReleaseSpinLock(SstpGlobals + 0x1f0);
          if (-1 < iVar9) {
            puVar7[0x4a4] = local_res8[0];
            goto LAB_140012279;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            puVar19 = (uint *)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
            uVar10 = 0x2b;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                     &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,iVar9);
          }
        }
        ScmCmDeleteVc((int *)puVar18,uVar10,(undefined *)puVar19);
        goto LAB_140012642;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        uVar14 = 0x29;
        goto LAB_1400125e5;
      }
    }
  }
  iVar9 = -0x3ffffff3;
LAB_140012642:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return iVar9;
}



===== ProcessMakeCallCompleteRequest @ 140012690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ProcessMakeCallCompleteRequest(longlong param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  int iVar7;
  ulonglong uVar8;
  int **ppiVar9;
  undefined *puVar10;
  int *local_res18;
  
  local_res18 = (int *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x10) == 0x68) {
    puVar1 = *(undefined4 **)(param_1 + 0x18);
    uVar6 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
    ppiVar9 = &local_res18;
    iVar7 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),*puVar1,ppiVar9);
    if (iVar7 == 0) {
      LOCK();
      *local_res18 = *local_res18 + 1;
      UNLOCK();
      KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar6);
      uVar6 = KeAcquireSpinLockRaiseToDpc(local_res18 + 8);
      local_res18[0x496] = local_res18[0x496] & 0xffffdfff;
      local_res18[0x1d] = puVar1[1];
      if ((char)local_res18[0x497] == '\0') {
        *(int **)(param_1 + 0x78) = local_res18;
        *(longlong *)(local_res18 + 0x10) = param_1;
        *(undefined8 *)(local_res18 + 0x49a) = *(undefined8 *)(puVar1 + 2);
        *(undefined8 *)(local_res18 + 0x49c) = *(undefined8 *)(puVar1 + 4);
        local_res18[0x4a0] = puVar1[7];
        local_res18[0x496] = local_res18[0x496] | 2;
        uVar5 = *(undefined8 *)(puVar1 + 10);
        *(undefined8 *)((longlong)local_res18 + 0x129) = *(undefined8 *)(puVar1 + 8);
        *(undefined8 *)((longlong)local_res18 + 0x131) = uVar5;
        *(undefined4 *)((longlong)local_res18 + 0x139) = puVar1[0xc];
        uVar5 = *(undefined8 *)(puVar1 + 0xf);
        *(undefined8 *)((longlong)local_res18 + 0x13d) = *(undefined8 *)(puVar1 + 0xd);
        *(undefined8 *)((longlong)local_res18 + 0x145) = uVar5;
        uVar5 = *(undefined8 *)(puVar1 + 0x13);
        *(undefined8 *)((longlong)local_res18 + 0x14d) = *(undefined8 *)(puVar1 + 0x11);
        *(undefined8 *)((longlong)local_res18 + 0x155) = uVar5;
        iVar2 = puVar1[0x17];
        iVar3 = puVar1[0x18];
        iVar4 = puVar1[0x19];
        local_res18[0x79] = puVar1[0x16];
        local_res18[0x7a] = iVar2;
        local_res18[0x7b] = iVar3;
        local_res18[0x7c] = iVar4;
        *(undefined1 *)(local_res18 + 0x4a) = *(undefined1 *)(puVar1 + 0x15);
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            ppiVar9 = (int **)(ulonglong)*(byte *)((longlong)puVar1 + 0x66);
            WPP_SF_DDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,ppiVar9,puVar1[0x16],
                               (char)*(undefined2 *)(puVar1 + 0x17),
                               (char)*(undefined2 *)((longlong)puVar1 + 0x5e),
                               *(undefined1 *)(puVar1 + 0x18),
                               *(undefined1 *)((longlong)puVar1 + 0x61),
                               *(undefined1 *)((longlong)puVar1 + 0x62),
                               *(undefined1 *)((longlong)puVar1 + 99),*(undefined1 *)(puVar1 + 0x19)
                               ,*(undefined1 *)((longlong)puVar1 + 0x65),
                               *(byte *)((longlong)puVar1 + 0x66),
                               *(undefined1 *)((longlong)puVar1 + 0x67));
          }
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppiVar9 = (int **)(ulonglong)*(byte *)((longlong)local_res18 + 0x1f2);
              WPP_SF_DDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,ppiVar9,
                                 local_res18[0x79],(char)local_res18[0x7a],
                                 (char)*(undefined2 *)((longlong)local_res18 + 0x1ea),
                                 (char)local_res18[0x7b],
                                 *(undefined1 *)((longlong)local_res18 + 0x1ed),
                                 *(undefined1 *)((longlong)local_res18 + 0x1ee),
                                 *(undefined1 *)((longlong)local_res18 + 0x1ef),
                                 (char)local_res18[0x7c],
                                 *(undefined1 *)((longlong)local_res18 + 0x1f1),
                                 *(byte *)((longlong)local_res18 + 0x1f2),
                                 *(undefined1 *)((longlong)local_res18 + 499));
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              ppiVar9 = (int **)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res18 + 0x79);
            }
          }
        }
        KeReleaseSpinLock(local_res18 + 8,uVar6);
        uVar8 = SetCancelRoutineSafe(param_1,DispatchIncomingCallConnectedCancelIrp);
        if ((char)uVar8 == '\0') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            ppiVar9 = (int **)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                    &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
          }
          uVar6 = KeAcquireSpinLockRaiseToDpc(local_res18 + 8);
          local_res18[0x10] = 0;
          local_res18[0x11] = 0;
          local_res18[0x498] = -0x3ffffee0;
          InitiateSstpContextCleanup
                    (local_res18,4,(undefined *)CONCAT71((int7)((ulonglong)ppiVar9 >> 8),uVar6));
          DereferenceRefCount(local_res18);
        }
        else {
          puVar10 = (undefined *)0x0;
          iVar7 = (**(code **)(SstpGlobals + 0x208))
                            (local_res18,CONCAT71((int7)((ulonglong)(local_res18 + 0x79) >> 8),1),1,
                             CONCAT71((int7)((ulonglong)((longlong)local_res18 + 0x129) >> 8),
                                      (char)local_res18[0x4a]),(longlong)local_res18 + 0x129,
                             (longlong)local_res18 + 0x13d,local_res18 + 0x79);
          if (iVar7 < 0) {
            uVar6 = KeAcquireSpinLockRaiseToDpc(local_res18 + 8);
            local_res18[0x498] = iVar7;
            local_res18[0x496] = local_res18[0x496] & 0xfffffffd;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              puVar10 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
              WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                             &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res18 + 0x79,
                             (char)iVar7);
            }
            InitiateSstpContextCleanup
                      (local_res18,4,(undefined *)CONCAT71((int7)((ulonglong)puVar10 >> 8),uVar6));
            LOCK();
            *(undefined8 *)(param_1 + 0x68) = 0;
            UNLOCK();
            *(undefined8 *)(param_1 + 0x38) = 0;
            *(int *)(param_1 + 0x30) = iVar7;
            IofCompleteRequest(param_1,0);
            iVar7 = 0x103;
          }
        }
      }
      else {
        InitiateSstpContextCleanup
                  (local_res18,4,(undefined *)CONCAT71((int7)((ulonglong)ppiVar9 >> 8),uVar6));
        DereferenceRefCount(local_res18);
        iVar7 = -0x3fffffff;
      }
    }
    else {
      KeReleaseSpinLock(SstpGlobals + 0x1f0);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar7;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                 &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,iVar7);
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
    iVar7 = -0x3ffffff3;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return iVar7;
}



===== SendNotificationCancelIrp @ 140012c90 =====

void SendNotificationCancelIrp(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  piVar1 = *(int **)(param_2 + 0x78);
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 8);
  piVar1[0x14] = 0;
  piVar1[0x15] = 0;
  KeReleaseSpinLock(piVar1 + 8,uVar2);
  DereferenceRefCount(piVar1);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== TpiFsmCryptoBindingComplete @ 140012d80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TpiFsmCryptoBindingComplete(int *param_1)

{
  undefined1 uVar1;
  undefined1 auStack_a8 [32];
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined4 local_74;
  undefined1 *local_58;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)((longlong)param_1 + 0x1fa) = 1;
  KeReleaseSpinLock(param_1 + 8);
  memset(local_88,0,0x70);
  local_88[0] = 0x700198;
  local_80 = *(undefined8 *)(SstpGlobals + 0xa8);
  local_74 = 0x40010012;
  local_50 = 1;
  local_58 = (undefined1 *)((longlong)param_1 + 0x1fa);
  uVar1 = KfRaiseIrql(2);
  NdisMCoIndicateStatusEx
            (*(undefined8 *)(SstpGlobals + 0xa8),*(undefined8 *)(param_1 + 10),local_88);
  KeLowerIrql(uVar1);
  DereferenceRefCount(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== TpiFsmDisconnectComplete @ 140012f00 =====

void TpiFsmDisconnectComplete(int *param_1,char param_2,undefined *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar2 = SUB81(param_3,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    param_3 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  uVar1 = param_1[0x496];
  *(undefined1 *)(param_1 + 0x7f) = uVar2;
  param_1[0x496] = uVar1 & 0xfffffdff;
  if (param_2 == '\0') {
    iVar4 = 4;
  }
  else {
    iVar4 = 3;
    param_1[0x496] = uVar1 & 0xfffffdfb;
  }
  InitiateSstpContextCleanup
            (param_1,iVar4,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar3));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== TpiFsmIndicateLinkParamChange @ 140012fe8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TpiFsmIndicateLinkParamChange
               (undefined8 param_1,undefined4 param_2,ulonglong param_3,ulonglong param_4)

{
  undefined1 auStack_e8 [32];
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined4 local_b4;
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_e8;
  memset(local_c8,0,0x70);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  local_48 = 0xfff;
  local_4c = 0x20;
  local_c8[0] = 0x700198;
  local_54 = (undefined4)(param_3 >> 3);
  local_50 = (undefined4)(param_4 >> 3);
  local_c0 = *(undefined8 *)(SstpGlobals + 0xa8);
  local_98 = &local_58;
  local_b4 = 0x40010025;
  local_90 = 0x14;
  local_58 = param_2;
  NdisMCoIndicateStatusEx(*(undefined8 *)(SstpGlobals + 0xa8),param_1,local_c8);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== TpiFsmNewCallComplete @ 140013120 =====

void TpiFsmNewCallComplete(int *param_1,int param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  
  if (param_2 == 0) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
    uVar3 = param_1[0x496];
    param_1[0x496] = uVar3 & 0xfffffffd | 4;
    if ((char)param_1[0x497] == '\0') {
      param_1[0x496] = uVar3 & 0xfffffffd | 0xc;
      KeReleaseSpinLock(param_1 + 8,uVar5);
      iVar6 = NdisMCmActivateVc(*(undefined8 *)(param_1 + 10),*(undefined8 *)(param_1 + 0x48c));
      if (iVar6 == 0x103) {
        return;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                       &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79,(char)iVar6);
      }
      ScmCmActivateVcComplete(iVar6,param_1,*(undefined **)(param_1 + 0x48c));
      return;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      param_3 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                     &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79,(char)param_2);
    }
    piVar1 = param_1 + 8;
    uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
    lVar4 = *(longlong *)(param_1 + 0x10);
    param_1[0x496] = param_1[0x496] & 0xfffffffd;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x498] = param_2;
    *(undefined1 *)((longlong)param_1 + 0x1fb) = 1;
    KeReleaseSpinLock(piVar1,uVar5);
    if (lVar4 != 0) {
      LOCK();
      lVar2 = *(longlong *)(lVar4 + 0x68);
      *(longlong *)(lVar4 + 0x68) = 0;
      UNLOCK();
      if (lVar2 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          param_3 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
        }
      }
      else {
        *(undefined8 *)(lVar4 + 0x38) = 0;
        *(int *)(lVar4 + 0x30) = param_2;
        IofCompleteRequest(lVar4,2);
        DereferenceRefCount(param_1);
      }
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
  }
  InitiateSstpContextCleanup(param_1,4,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar5))
  ;
  return;
}



===== TpiFsmSendControlFrame @ 140013330 =====

undefined8 TpiFsmSendControlFrame(int *param_1,undefined8 *param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  QueuePacketForSend(param_1,param_2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x82) == 0x82)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return 0x103;
}



===== ScmCmActivateVcComplete @ 1400133d0 =====

void ScmCmActivateVcComplete(int param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  piVar1 = param_2 + 8;
  uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
  param_2[0x496] = param_2[0x496] & 0xfffffff7;
  if (param_1 == 0) {
    LOCK();
    *param_2 = *param_2 + 1;
    UNLOCK();
    param_2[0x496] = param_2[0x496] | 0x100010;
    *(undefined1 *)((longlong)param_2 + 0x1fb) = 1;
  }
  lVar3 = *(longlong *)(param_2 + 0x10);
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  if ((lVar3 == 0) && ((char)param_2[0x4a1] == '\0')) {
    param_1 = -0x3ffffee0;
  }
  KeReleaseSpinLock(piVar1,uVar5);
  if (lVar3 != 0) {
    LOCK();
    lVar2 = *(longlong *)(lVar3 + 0x68);
    *(longlong *)(lVar3 + 0x68) = 0;
    UNLOCK();
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                      &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_2 + 0x79);
      }
      param_1 = -0x3ffffee0;
    }
    else {
      *(undefined8 *)(lVar3 + 0x38) = 0;
      *(int *)(lVar3 + 0x30) = param_1;
      IofCompleteRequest(lVar3,2);
      DereferenceRefCount(param_2);
    }
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
  if ((param_1 < 0) || ((char)param_2[0x497] != '\0')) {
    if (param_1 == 0) {
      param_1 = -0x3ffffee0;
    }
    param_2[0x498] = param_1;
    InitiateSstpContextCleanup
              (param_2,4,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar5));
  }
  else {
    puVar4 = *(uint **)(param_2 + 0x48c);
    if (*(char *)((longlong)param_2 + 0x1f9) == '\0') {
      param_2[0x496] = param_2[0x496] & 0xffffbfff;
      KeReleaseSpinLock(piVar1,uVar5);
      if ((char)param_2[0x4a1] == '\0') {
        *puVar4 = *puVar4 | 2;
        uVar6 = (undefined4)(*(ulonglong *)(param_2 + 0x49a) >> 3);
        **(undefined4 **)(puVar4 + 2) = uVar6;
        *(undefined4 *)(*(longlong *)(puVar4 + 2) + 8) = uVar6;
        *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x18) = 0xfff;
        uVar6 = (undefined4)(*(ulonglong *)(param_2 + 0x49c) >> 3);
        *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x20) = uVar6;
        *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x28) = uVar6;
        *(undefined4 *)(*(longlong *)(puVar4 + 2) + 0x38) = 0xfff;
      }
      else {
        uVar6 = (undefined4)(*(ulonglong *)(param_2 + 0x49c) >> 3);
      }
      *(int *)(*(longlong *)(param_2 + 0x49e) + 4) = param_2[0x4a0];
      **(undefined4 **)(param_2 + 0x49e) = 0x53415252;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF__guid_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                        &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_2 + 0x79,
                        (char)param_2[0x4a0],(char)uVar6);
      }
      if ((char)param_2[0x4a1] == '\0') {
        NdisCmMakeCallComplete(0,*(undefined8 *)(param_2 + 10),0,0,puVar4);
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(piVar1);
    }
    else {
      FreeCallParams((longlong)puVar4);
    }
    param_2[0x48c] = 0;
    param_2[0x48d] = 0;
    KeReleaseSpinLock(piVar1,uVar5);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return;
}



===== ScmCmDeactivateVcComplete @ 1400136e0 =====

void ScmCmDeactivateVcComplete(undefined1 param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined *in_R8;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81) {
      in_R8 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      in_R8 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                     &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_2 + 0x1e4,param_1);
    }
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x20);
  *(uint *)(param_2 + 0x1258) = *(uint *)(param_2 + 0x1258) & 0xfffffbff;
  InitiateSstpContextCleanup
            ((int *)param_2,4,(undefined *)CONCAT71((int7)((ulonglong)in_R8 >> 8),uVar1));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return;
}



===== ScmCmIncomingCallComplete @ 1400137d0 =====

void ScmCmIncomingCallComplete(int param_1,int *param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  int *_Dst;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  int iVar9;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81) {
      param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                     &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids,param_2 + 0x79,(char)param_1);
    }
  }
  piVar1 = param_2 + 8;
  KeAcquireSpinLockRaiseToDpc(piVar1);
  param_2[0x496] = param_2[0x496] & 0xfffffeff;
  uVar3 = *(ulonglong *)(param_2 + 0xe);
  iVar9 = -0x3ffffdbf;
  if ((char)param_2[0x497] == '\0') {
    iVar9 = param_1;
  }
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  uVar8 = 0;
  if (uVar3 != 0) {
    LOCK();
    lVar2 = *(longlong *)(uVar3 + 0x68);
    *(longlong *)(uVar3 + 0x68) = 0;
    UNLOCK();
    uVar8 = uVar3 & -(ulonglong)(lVar2 != 0);
  }
  KeReleaseSpinLock(piVar1);
  if ((iVar9 != 0) || (uVar8 == 0)) {
    if (((uVar8 == 0) &&
        (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)))) && (WPP_GLOBAL_Control[0x29] != '\0'))
    {
      param_3 = &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    uVar7 = KeAcquireSpinLockRaiseToDpc(piVar1);
    InitiateSstpContextCleanup
              (param_2,4,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar7));
    if (uVar8 == 0) goto LAB_1400139a5;
  }
  _Dst = *(int **)(uVar8 + 0x18);
  memset(_Dst,0,0x78);
  _Dst[8] = iVar9;
  *_Dst = param_2[0x1d];
  _Dst[9] = param_2[0x1c];
  iVar4 = param_2[0x7a];
  iVar5 = param_2[0x7b];
  iVar6 = param_2[0x7c];
  _Dst[0x18] = param_2[0x79];
  _Dst[0x19] = iVar4;
  _Dst[0x1a] = iVar5;
  _Dst[0x1b] = iVar6;
  if (iVar9 == 0) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(piVar1);
    param_2[0x496] = param_2[0x496] | 0x40;
    KeReleaseSpinLock(piVar1,uVar7);
    NdisCmDispatchCallConnected(*(undefined8 *)(param_2 + 10));
  }
  *(undefined4 *)(uVar8 + 0x30) = 0;
  *(undefined8 *)(uVar8 + 0x38) = 0x78;
  DereferenceRefCount(param_2);
  IofCompleteRequest(uVar8,2);
LAB_1400139a5:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
  }
  return;
}



===== ScmCmModifyCallQoS @ 140013a00 =====

undefined8 ScmCmModifyCallQoS(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
              &WPP_0e2338ba18cf327e8b8ecf2e7c52d0c3_Traceguids);
    }
  }
  return 0;
}



===== AbortState1Timeout @ 140013a80 =====

void AbortState1Timeout(longlong param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    puVar1 = (undefined1 *)0x0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x18) - 5U & 0xfffffff7) == 0) {
    MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar1 >> 8),1),param_2);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== AbortState2Timeout @ 140013b70 =====

void AbortState2Timeout(longlong param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    puVar1 = (undefined1 *)0x0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x18) - 6U & 0xfffffff7) == 0) {
    MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar1 >> 8),1),param_2);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== CleanupFsmContext @ 140013c60 =====

void CleanupFsmContext(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  
  bVar5 = true;
  plVar1 = (longlong *)(param_1 + -0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(SstpFsmGlobalInfo + 0x48);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 == plVar1) {
    bVar5 = false;
  }
  else {
    if (((longlong *)plVar2[1] != plVar1) ||
       (plVar3 = *(longlong **)(param_1 + -0x18), (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = (longlong)plVar2;
    plVar2[1] = (longlong)plVar3;
    *(longlong **)(param_1 + -0x18) = plVar1;
    *plVar1 = (longlong)plVar1;
  }
  if (*(longlong **)(SstpFsmGlobalInfo + 0x50) == (longlong *)(SstpFsmGlobalInfo + 0x50)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    iVar7 = ModifyTimerGlobalStateToStopping();
    if (iVar7 == 0x40000000) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
      }
    }
    else {
      IoQueueWorkItem(*(undefined8 *)(SstpFsmGlobalInfo + 0x1a8),SstpTimerShutdownPerProcTimersAsync
                      ,1);
      if (((iVar7 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,iVar7);
      }
    }
  }
  KeReleaseSpinLock(SstpFsmGlobalInfo + 0x48,uVar6);
  if (bVar5) {
    DereferenceRefCount((int *)(param_1 + -0x98));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== ComputeCompoundMac @ 140013e4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS ComputeCompoundMac(longlong param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,
                           ushort *param_5)

{
  char cVar1;
  NTSTATUS NVar2;
  undefined2 uVar3;
  undefined8 *_Src;
  uint uVar4;
  uint uVar5;
  undefined1 auStackY_128 [32];
  ushort local_f8 [2];
  undefined4 local_f4;
  undefined8 local_f0;
  ushort *local_e8;
  PUCHAR local_e0;
  PUCHAR local_d8;
  char local_d0 [44];
  undefined2 local_a4;
  UCHAR local_a0 [16];
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  UCHAR local_60 [32];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e8 = param_5;
  builtin_strncpy(local_d0,"SSTP inner metho",0x10);
  NVar2 = 0;
  local_f4 = 0x4d432064;
  local_f0 = 0x6576697265642064;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60[0] = '\0';
  local_60[1] = '\0';
  local_60[2] = '\0';
  local_60[3] = '\0';
  local_60[4] = '\0';
  local_60[5] = '\0';
  local_60[6] = '\0';
  local_60[7] = '\0';
  local_60[8] = '\0';
  local_60[9] = '\0';
  local_60[10] = '\0';
  local_60[0xb] = '\0';
  local_60[0xc] = '\0';
  local_60[0xd] = '\0';
  local_60[0xe] = '\0';
  local_60[0xf] = '\0';
  local_a4 = 0x4b;
  local_60[0x10] = '\0';
  local_60[0x11] = '\0';
  local_60[0x12] = '\0';
  local_60[0x13] = '\0';
  local_60[0x14] = '\0';
  local_60[0x15] = '\0';
  local_60[0x16] = '\0';
  local_60[0x17] = '\0';
  local_60[0x18] = '\0';
  local_60[0x19] = '\0';
  local_60[0x1a] = '\0';
  local_60[0x1b] = '\0';
  local_60[0x1c] = '\0';
  local_60[0x1d] = '\0';
  local_60[0x1e] = '\0';
  local_60[0x1f] = '\0';
  local_a0[0] = '\0';
  local_a0[1] = '\0';
  local_a0[2] = '\0';
  local_a0[3] = '\0';
  local_a0[4] = '\0';
  local_a0[5] = '\0';
  local_a0[6] = '\0';
  local_a0[7] = '\0';
  local_a0[8] = '\0';
  local_a0[9] = '\0';
  local_a0[10] = '\0';
  local_a0[0xb] = '\0';
  local_a0[0xc] = '\0';
  local_a0[0xd] = '\0';
  local_a0[0xe] = '\0';
  local_a0[0xf] = '\0';
  local_90 = 0;
  uStack_88 = 0;
  local_e0 = param_4;
  local_d8 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  cVar1 = *(char *)(param_1 + 0x146);
  if (cVar1 == '\0') {
    uVar4 = *(uint *)(param_1 + 300);
    uVar5 = *(uint *)(param_1 + 0x108);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x108);
    uVar5 = *(uint *)(param_1 + 300);
  }
  _Src = (undefined8 *)(param_1 + 0x10c + (-(ulonglong)(cVar1 != '\0') & 0xffffffffffffffd9));
  if (uVar4 < 0x20) {
    memmove(&local_80,_Src,(ulonglong)uVar4);
    if (0x20 - uVar4 <= uVar5) {
      uVar5 = 0x20 - uVar4;
    }
    memmove(local_60 + ((ulonglong)uVar4 - 0x20),
            (void *)(param_1 + 0xe5 + (ulonglong)(-(uint)(cVar1 != '\0') & 0x27)),(ulonglong)uVar5);
  }
  else {
    local_80 = *_Src;
    uStack_78 = _Src[1];
    local_70 = _Src[2];
    uStack_68 = _Src[3];
  }
  if (*(char *)(param_1 + 0xb0) == '\x01') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
    uStack_88._0_5_ = CONCAT14((undefined1)local_a4,local_f4);
    local_f8[0] = 0x14;
    uStack_88._0_7_ = CONCAT25(0x14,(undefined5)uStack_88);
    local_90 = local_f0;
    local_a0[0] = local_d0[0];
    local_a0[1] = local_d0[1];
    local_a0[2] = local_d0[2];
    local_a0[3] = local_d0[3];
    local_a0[4] = local_d0[4];
    local_a0[5] = local_d0[5];
    local_a0[6] = local_d0[6];
    local_a0[7] = local_d0[7];
    local_a0[8] = local_d0[8];
    local_a0[9] = local_d0[9];
    local_a0[10] = local_d0[10];
    local_a0[0xb] = local_d0[0xb];
    local_a0[0xc] = local_d0[0xc];
    local_a0[0xd] = local_d0[0xd];
    local_a0[0xe] = local_d0[0xe];
    local_a0[0xf] = local_d0[0xf];
    uStack_88 = CONCAT17(1,(undefined7)uStack_88);
    NVar2 = GenerateHmacSha1Hash((PUCHAR)&local_80,0x20,local_a0,0x20,local_60,local_f8);
    if (NVar2 == 0) {
      NVar2 = GenerateHmacSha1Hash(local_60,(uint)local_f8[0],local_d8,param_3,local_e0,local_e8);
      if (NVar2 == 0) goto LAB_140014228;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return NVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_140014228;
      uVar3 = 0x3a;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return NVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_140014228;
      uVar3 = 0x39;
    }
  }
  else {
    if (*(char *)(param_1 + 0xb0) != '\x02') goto LAB_140014228;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
    uStack_88._0_5_ = CONCAT14((undefined1)local_a4,local_f4);
    local_f8[0] = 0x20;
    uStack_88._0_7_ = CONCAT25(0x20,(undefined5)uStack_88);
    local_a0[0] = local_d0[0];
    local_a0[1] = local_d0[1];
    local_a0[2] = local_d0[2];
    local_a0[3] = local_d0[3];
    local_a0[4] = local_d0[4];
    local_a0[5] = local_d0[5];
    local_a0[6] = local_d0[6];
    local_a0[7] = local_d0[7];
    local_a0[8] = local_d0[8];
    local_a0[9] = local_d0[9];
    local_a0[10] = local_d0[10];
    local_a0[0xb] = local_d0[0xb];
    local_a0[0xc] = local_d0[0xc];
    local_a0[0xd] = local_d0[0xd];
    local_a0[0xe] = local_d0[0xe];
    local_a0[0xf] = local_d0[0xf];
    uStack_88 = CONCAT17(1,(undefined7)uStack_88);
    local_90 = local_f0;
    NVar2 = GenerateHmacSha256Hash((PUCHAR)&local_80,0x20,local_a0,0x20,local_60,local_f8);
    if (NVar2 == 0) {
      NVar2 = GenerateHmacSha256Hash(local_60,(uint)local_f8[0],local_d8,param_3,local_e0,local_e8);
      if (NVar2 == 0) goto LAB_140014228;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return NVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_140014228;
      uVar3 = 0x3d;
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return NVar2;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || (WPP_GLOBAL_Control[0x29] == '\0'))
      goto LAB_140014228;
      uVar3 = 0x3c;
    }
  }
  WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
                 &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c,(char)NVar2);
LAB_140014228:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return NVar2;
}



===== ConnectAckReceivedTimeout @ 140014290 =====

void ConnectAckReceivedTimeout(longlong param_1,undefined1 *param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if (*(int *)(param_1 + 0x18) == 3) {
    MoveToAbortState1(param_1,2,8,'\x01',param_2);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== ConnectPendingStateTimeout @ 140014380 =====

void ConnectPendingStateTimeout(longlong param_1,undefined1 *param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if (*(int *)(param_1 + 0x18) == 0xb) {
    MoveToAbortState1(param_1,2,8,'\x01',param_2);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== ConnectRequestPendingStateTimeout @ 140014470 =====

void ConnectRequestPendingStateTimeout(longlong param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    puVar1 = (undefined1 *)0x0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if (*(int *)(param_1 + 0x18) == 10) {
    MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar1 >> 8),1),param_2);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== ConnectRequestSentTimeout @ 140014560 =====

void ConnectRequestSentTimeout(longlong param_1,undefined1 *param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if (*(int *)(param_1 + 0x18) == 2) {
    MoveToAbortState1(param_1,2,8,'\x01',param_2);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== DisconnectState1Timeout @ 140014650 =====

void DisconnectState1Timeout(longlong param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    puVar1 = (undefined1 *)0x0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x18) - 7U & 0xfffffff7) == 0) {
    MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar1 >> 8),1),param_2);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== DisconnectState2Timeout @ 140014740 =====

void DisconnectState2Timeout(longlong param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    puVar1 = (undefined1 *)0x0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x18) - 8U & 0xfffffff7) == 0) {
    MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar1 >> 8),1),param_2);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== DummyTimeoutHandler @ 140014830 =====

void DummyTimeoutHandler(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
  }
  return;
}



===== FsmTpiControlFrameSendComplete @ 1400148b0 =====

void FsmTpiControlFrameSendComplete(undefined8 param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  ExFreeToNPagedLookasideList(SstpFsmGlobalInfo + 0x80,param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== FsmTpiDisconnectCall @ 140014950 =====

undefined8 FsmTpiDisconnectCall(int *param_1,char param_2,undefined8 param_3,char param_4)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  uVar4 = 0x103;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  piVar1 = param_1 + 8;
  KeAcquireSpinLockRaiseToDpc(piVar1);
  LOCK();
  bVar5 = param_1[0x7d] == 1;
  if (bVar5) {
    param_1[0x7d] = 1;
  }
  UNLOCK();
  if (bVar5) {
    KeReleaseSpinLock(piVar1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x79);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
    *(bool *)((longlong)param_1 + 0x1b9) = param_4 == '\0';
    if (param_2 == '\0') {
      MoveToDisconnectState1((longlong)(param_1 + 0x1e));
    }
    else {
      if ((param_1[0x24] - 1U & 0xfffffff7) != 0) {
        MoveToCallDisconnectedState((longlong)(param_1 + 0x1e),0,(undefined1 *)0x0);
        KeLowerIrql(uVar3);
        goto LAB_140014b08;
      }
      uVar4 = 0;
    }
    KeReleaseSpinLock(param_1 + 0x22,uVar3);
  }
  else {
    uVar2 = param_1[0x496];
    param_1[0x496] = uVar2 | 0x20000;
    if (param_4 != '\0') {
      param_1[0x496] = uVar2 | 0xa0000;
    }
    KeReleaseSpinLock(piVar1);
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x103;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
               &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,0x103);
    }
  }
LAB_140014b08:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return uVar4;
}



===== FsmTpiNewCall @ 140014b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FsmTpiNewCall(int *param_1,undefined8 param_2,int param_3,byte param_4,undefined4 *param_5,
                 undefined4 *param_6,int *param_7)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  int iVar10;
  undefined8 uVar11;
  int *piVar12;
  char cVar13;
  undefined7 uVar15;
  ulonglong uVar14;
  byte bVar16;
  
  cVar13 = (char)param_2;
  piVar1 = param_1 + 0x1e;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    param_2 = 0;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  if ((SstpFsmGlobalInfo == (char *)0x0) || (*SstpFsmGlobalInfo == '\0')) {
    iVar10 = -0x3ffffe7c;
    goto LAB_140014f1c;
  }
  bVar16 = param_4 & SstpFsmGlobalInfo[0xc];
  if ((((bVar16 & 1) != 0) && (param_5 == (undefined4 *)0x0)) ||
     (((bVar16 & 2) != 0 && (param_6 == (undefined4 *)0x0)))) {
    iVar10 = -0x3ffffff3;
    goto LAB_140014f1c;
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(SstpFsmGlobalInfo + 0x48);
  if (*(char **)(SstpFsmGlobalInfo + 0x50) == SstpFsmGlobalInfo + 0x50) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_2 = 0;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    iVar10 = SstpTimerInitializePerProcTimers();
    if (iVar10 == 0x40000000) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_2 = 0;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
      }
      goto LAB_140014caf;
    }
    if (-1 < iVar10) goto LAB_140014caf;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
               &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,iVar10);
    }
    piVar12 = (int *)(SstpFsmGlobalInfo + 0x48);
LAB_140014e1b:
    KeReleaseSpinLock(piVar12,uVar9);
  }
  else {
LAB_140014caf:
    uVar15 = (undefined7)((ulonglong)param_2 >> 8);
    InitializeFsmContext(param_1,cVar13,param_3,bVar16);
    uVar14 = CONCAT71(uVar15,uVar9);
    KeReleaseSpinLock(SstpFsmGlobalInfo + 0x48,uVar14);
    if (param_5 != (undefined4 *)0x0) {
      uVar4 = param_5[1];
      uVar5 = param_5[2];
      uVar6 = param_5[3];
      *(undefined4 *)((longlong)param_1 + 0x129) = *param_5;
      *(undefined4 *)((longlong)param_1 + 0x12d) = uVar4;
      *(undefined4 *)((longlong)param_1 + 0x131) = uVar5;
      *(undefined4 *)((longlong)param_1 + 0x135) = uVar6;
      *(undefined4 *)((longlong)param_1 + 0x139) = param_5[4];
    }
    if (param_6 != (undefined4 *)0x0) {
      uVar4 = param_6[1];
      uVar5 = param_6[2];
      uVar6 = param_6[3];
      *(undefined4 *)((longlong)param_1 + 0x13d) = *param_6;
      *(undefined4 *)((longlong)param_1 + 0x141) = uVar4;
      *(undefined4 *)((longlong)param_1 + 0x145) = uVar5;
      *(undefined4 *)((longlong)param_1 + 0x149) = uVar6;
      uVar11 = *(undefined8 *)(param_6 + 6);
      *(undefined8 *)((longlong)param_1 + 0x14d) = *(undefined8 *)(param_6 + 4);
      *(undefined8 *)((longlong)param_1 + 0x155) = uVar11;
    }
    if (param_7 != (int *)0x0) {
      iVar10 = param_7[1];
      iVar7 = param_7[2];
      iVar8 = param_7[3];
      param_1[0x79] = *param_7;
      param_1[0x7a] = iVar10;
      param_1[0x7b] = iVar7;
      param_1[0x7c] = iVar8;
    }
    param_1[0x60] = 0;
    param_1[0x69] = 0;
    *(undefined1 *)((longlong)param_1 + 0x1bd) = 1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar14 = 0;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x79);
    }
    piVar2 = param_1 + 0x26;
    LOCK();
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    piVar12 = param_1 + 8;
    uVar9 = KeAcquireSpinLockRaiseToDpc(piVar12);
    if ((char)param_1[0x497] != '\0') {
      uVar3 = param_1[0x496];
      uVar14 = (ulonglong)uVar3;
      if ((uVar3 >> 0x11 & 1) != 0) {
        iVar10 = -0x3fffffff;
        param_1[0x496] = uVar3 & 0xfffdffff | 0x40000;
        goto LAB_140014e1b;
      }
    }
    uVar15 = (undefined7)(uVar14 >> 8);
    KeReleaseSpinLock(piVar12);
    if (cVar13 == '\0') {
      if ((char)param_1[0x4a] != '\0') {
        iVar10 = (**(code **)(SstpFsmGlobalInfo + 0x160))(param_1 + 0x42);
        if (iVar10 == 0) {
          LOCK();
          *piVar2 = *piVar2 + 1;
          UNLOCK();
          uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
          MoveToCallDisconnectedState((longlong)piVar1,0,(undefined1 *)0x0);
          KeLowerIrql(uVar9);
          DereferenceRefCount(piVar2);
          iVar10 = -0x3fffffff;
          goto LAB_140014f1c;
        }
      }
      iVar10 = 0x103;
    }
    else {
      LOCK();
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x22);
      uVar11 = MoveToConnectRequestSentState((longlong)piVar1);
      iVar10 = (int)uVar11;
      if (iVar10 < 0) {
        MoveToCallDisconnectedState((longlong)piVar1,0,(undefined1 *)0x0);
        KeLowerIrql(uVar9);
      }
      else {
        iVar10 = 0x103;
        KeReleaseSpinLock(param_1 + 0x22,CONCAT71(uVar15,uVar9));
      }
      DereferenceRefCount(piVar2);
    }
  }
LAB_140014f1c:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return iVar10;
}



===== FsmTpiProcessControlFrame @ 140014f80 =====

void FsmTpiProcessControlFrame(longlong param_1,char *param_2,ushort param_3,longlong param_4)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_4 = param_1 + 0x1e4;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_4);
    }
  }
  ReceiveCtrlMessage(param_1 + 0x78,param_2,param_3,param_4);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== FsmTpiSetCryptoBindingKeys @ 140015070 =====

int FsmTpiSetCryptoBindingKeys
              (longlong param_1,void *param_2,uint param_3,void *param_4,uint param_5)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  uint uVar9;
  bool bVar10;
  
  lVar1 = param_1 + 0x78;
  iVar6 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  uVar7 = Feature_3759042875__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    LOCK();
    bVar10 = *(int *)(param_1 + 500) == 1;
    if (bVar10) {
      *(int *)(param_1 + 500) = 1;
    }
    UNLOCK();
    if (!bVar10) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                      &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x1e4);
      }
      iVar6 = -0x3ffffe7c;
      goto LAB_14001546b;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                  &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x1e4);
  }
  if (*(char *)(param_1 + 0x128) == '\0') {
    iVar6 = -0x3fffff45;
    goto LAB_14001546b;
  }
  piVar2 = (int *)(param_1 + 0x98);
  LOCK();
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  lVar3 = param_1 + 0x88;
  cVar4 = KeAcquireSpinLockRaiseToDpc(lVar3);
  uVar5 = 0x20;
  if (param_3 < 0x21) {
    uVar5 = param_3;
  }
  *(uint *)(param_1 + 0x180) = uVar5;
  uVar9 = 0x20;
  if (param_5 < 0x21) {
    uVar9 = param_5;
  }
  *(uint *)(param_1 + 0x1a4) = uVar9;
  *(undefined8 *)(param_1 + 0x15d) = 0;
  *(undefined8 *)(param_1 + 0x165) = 0;
  *(undefined8 *)(param_1 + 0x16d) = 0;
  *(undefined8 *)(param_1 + 0x175) = 0;
  *(undefined8 *)(param_1 + 0x184) = 0;
  *(undefined8 *)(param_1 + 0x18c) = 0;
  *(undefined8 *)(param_1 + 0x194) = 0;
  *(undefined8 *)(param_1 + 0x19c) = 0;
  if ((param_2 != (void *)0x0) && (uVar5 != 0)) {
    memmove((undefined8 *)(param_1 + 0x15d),param_2,(ulonglong)uVar5);
  }
  if ((param_4 != (void *)0x0) && (uVar9 != 0)) {
    memmove((void *)(param_1 + 0x184),param_4,(ulonglong)uVar9);
  }
  uVar5 = *(uint *)(param_1 + 0x90);
  if (*(char *)(param_1 + 0x1be) == '\0') {
    if (uVar5 == 0xb) {
      if (*(char *)(param_1 + 0x1bc) == '\0') {
        *(undefined1 *)(param_1 + 0x1bb) = 1;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
                        &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x1e4);
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
                  &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
        }
        if (cVar4 != '\0') {
          iVar6 = WTSScheduleSafeWorkItem
                            (SstpFsmGlobalInfo + 0x18,ProcessCryptoBindingPassive,lVar1);
          if (iVar6 == 0) goto LAB_140015459;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar8 = 0x7f;
            goto LAB_140015427;
          }
          goto LAB_140015442;
        }
        ProcessCryptoBinding(lVar1,0);
      }
    }
    else {
      iVar6 = -0x3fffff45;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar8 = 0x7c;
        goto LAB_140015326;
      }
    }
LAB_1400153d4:
    KeReleaseSpinLock(lVar3,cVar4);
  }
  else {
    if (uVar5 != 3) {
      iVar6 = -0x3fffff45;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        uVar8 = 0x7a;
LAB_140015326:
        iVar6 = -0x3fffff45;
        WPP_SF__guid_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,(ulonglong)uVar5,
                       param_1 + 0x1e4,(char)uVar5);
      }
      goto LAB_1400153d4;
    }
    if (cVar4 == '\0') {
      MoveToCallConnectedState(lVar1,0);
      goto LAB_1400153d4;
    }
    iVar6 = WTSScheduleSafeWorkItem(SstpFsmGlobalInfo + 0x18,MoveToCallConnectedPassive,lVar1);
    if (iVar6 == 0) {
LAB_140015459:
      KeReleaseSpinLock(lVar3,cVar4);
      goto LAB_14001546b;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar8 = 0x7b;
LAB_140015427:
      WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                     &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x1e4,(char)iVar6);
    }
LAB_140015442:
    MoveToCallDisconnectedState(lVar1,0,(undefined1 *)0x0);
  }
  DereferenceRefCount(piVar2);
LAB_14001546b:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return iVar6;
}



===== GenerateHmacSha1Hash @ 1400154c0 =====

NTSTATUS GenerateHmacSha1Hash
                   (PUCHAR param_1,ULONG param_2,PUCHAR param_3,ULONG param_4,PUCHAR param_5,
                   ushort *param_6)

{
  NTSTATUS NVar1;
  
  if (*(BCRYPT_HANDLE *)(SstpFsmGlobalInfo + 0x100) == (BCRYPT_HANDLE)0x0) {
    NVar1 = -0x3ffffff3;
  }
  else {
    NVar1 = GenerateHmacShaHash(*(BCRYPT_HANDLE *)(SstpFsmGlobalInfo + 0x100),param_1,param_2,
                                param_3,param_4,param_5,param_6);
  }
  return NVar1;
}



===== GenerateHmacSha256Hash @ 140015514 =====

NTSTATUS GenerateHmacSha256Hash
                   (PUCHAR param_1,ULONG param_2,PUCHAR param_3,ULONG param_4,PUCHAR param_5,
                   ushort *param_6)

{
  NTSTATUS NVar1;
  
  if (*(BCRYPT_HANDLE *)(SstpFsmGlobalInfo + 0x108) == (BCRYPT_HANDLE)0x0) {
    NVar1 = -0x3ffffff3;
  }
  else {
    NVar1 = GenerateHmacShaHash(*(BCRYPT_HANDLE *)(SstpFsmGlobalInfo + 0x108),param_1,param_2,
                                param_3,param_4,param_5,param_6);
  }
  return NVar1;
}



===== GenerateHmacShaHash @ 140015568 =====

NTSTATUS GenerateHmacShaHash(BCRYPT_HANDLE param_1,PUCHAR param_2,ULONG param_3,PUCHAR param_4,
                            ULONG param_5,PUCHAR param_6,ushort *param_7)

{
  ushort uVar1;
  NTSTATUS NVar2;
  PUCHAR pbHashObject;
  undefined8 uVar3;
  undefined2 uVar4;
  ULONG local_48 [2];
  uint local_40 [2];
  BCRYPT_HASH_HANDLE local_38 [2];
  
  local_48[0] = 0;
  local_40[0] = 0;
  local_48[1] = 0;
  local_38[0] = (BCRYPT_HASH_HANDLE)0x0;
  NVar2 = BCryptGetProperty(param_1,L"ObjectLength",(PUCHAR)local_48,4,local_48 + 1,0);
  if (NVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_140015608;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 10;
  }
  else {
    NVar2 = BCryptGetProperty(param_1,L"HashDigestLength",(PUCHAR)local_40,4,local_48 + 1,0);
    if (-1 < NVar2) {
      uVar1 = *param_7;
      *param_7 = (ushort)local_40[0];
      if (uVar1 < local_40[0]) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffdd;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return -0x3fffffdd;
        }
        if (WPP_GLOBAL_Control[0x29] == '\0') {
          return -0x3fffffdd;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
        return -0x3fffffdd;
      }
      pbHashObject = (PUCHAR)ExAllocatePool2(0x40,local_48[0],0x6f686653);
      if (pbHashObject == (PUCHAR)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,local_48[0]);
        }
        return -0x3fffff66;
      }
      NVar2 = BCryptCreateHash(param_1,local_38,pbHashObject,local_48[0],param_2,param_3,0);
      if (NVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar2);
        }
        goto LAB_140015864;
      }
      NVar2 = BCryptHashData(local_38[0],param_4,param_5,0);
      if (NVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          uVar4 = 0xf;
LAB_140015841:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar2);
        }
      }
      else {
        NVar2 = BCryptFinishHash(local_38[0],param_6,(uint)*param_7,0);
        if (((NVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))
           ) {
          uVar4 = 0x10;
          goto LAB_140015841;
        }
      }
      BCryptDestroyHash(local_38[0]);
LAB_140015864:
      ExFreePoolWithTag(pbHashObject,0x6f686653);
      return NVar2;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || (WPP_GLOBAL_Control[0x29] == '\0'))
    goto LAB_140015608;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 0xb;
  }
  WPP_SF_D(uVar3,uVar4,&WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,NVar2);
LAB_140015608:
  *param_7 = 0;
  return NVar2;
}



===== GetAcceptedMessageTypesForCurrentState @ 1400158a0 =====

void GetAcceptedMessageTypesForCurrentState(int param_1,undefined8 *param_2,undefined1 *param_3)

{
  int iVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  *param_3 = 0;
  *param_2 = 0;
  *(undefined2 *)(param_2 + 1) = 0;
  if (param_1 < 10) {
    if ((param_1 == 9) || (param_1 == 1)) {
LAB_140015940:
      *param_3 = 1;
      goto LAB_140015963;
    }
    if (param_1 == 2) {
      *(undefined2 *)((longlong)param_2 + 2) = 0x101;
    }
    else {
      iVar1 = param_1 + -3;
      if (iVar1 != 0) goto LAB_140015926;
    }
  }
  else if (param_1 == 10) {
    *(undefined1 *)((longlong)param_2 + 1) = 1;
  }
  else {
    iVar1 = param_1 + -0xb;
    if (iVar1 == 0) {
      *(undefined2 *)((longlong)param_2 + 4) = 0x101;
      *(undefined1 *)((longlong)param_2 + 6) = 1;
      goto LAB_140015963;
    }
LAB_140015926:
    if (iVar1 != 1) {
      if (((iVar1 != 2) && (iVar1 != 3)) && (iVar1 == 4)) {
        *(undefined1 *)((longlong)param_2 + 7) = 1;
        goto LAB_140015963;
      }
      goto LAB_140015940;
    }
    *(undefined2 *)(param_2 + 1) = 0x101;
  }
  *(undefined2 *)((longlong)param_2 + 5) = 0x101;
LAB_140015963:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== HelloIntervalTickExpired @ 1400159b0 =====

void HelloIntervalTickExpired(longlong param_1,undefined1 *param_2,undefined *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  
  bVar1 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    param_3 = &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  if ((*(int *)(param_1 + 0x18) - 4U & 0xfffffff7) == 0) {
    if (*(char *)(param_1 + 0x140) == '\0') {
      uVar2 = *(int *)(param_1 + 0x138) + 1;
      *(uint *)(param_1 + 0x138) = uVar2;
      if (*(uint *)(param_1 + 0x130) <= uVar2) {
        uVar2 = *(int *)(param_1 + 0x13c) + 1;
        *(uint *)(param_1 + 0x13c) = uVar2;
        if (uVar2 < 2) {
          bVar1 = true;
          *(undefined4 *)(param_1 + 0x138) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x13c) = 0;
          MoveToAbortState2(param_1,'\0',param_3,8,'\x01',param_2);
        }
      }
    }
    else {
      *(undefined8 *)(param_1 + 0x138) = 0;
    }
    *(undefined1 *)(param_1 + 0x140) = 0;
    if (bVar1) {
      puVar3 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
      if (puVar3 == (undefined8 *)0x0) {
        *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x130);
      }
      else {
        *(undefined4 *)(puVar3 + 2) = 0x1100008;
        *(undefined4 *)((longlong)puVar3 + 0x16) = 0x800;
        *(ushort *)((longlong)puVar3 + 0x14) =
             *(ushort *)(puVar3 + 2) >> 8 | *(ushort *)(puVar3 + 2) << 8;
        SendControlFrame(param_1,puVar3);
      }
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== InitializeFsmContext @ 140015b64 =====

ulonglong InitializeFsmContext(int *param_1,char param_2,int param_3,undefined1 param_4)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  plVar1 = (longlong *)(param_1 + 0x1e);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  param_1[0x7d] = 0;
  *(longlong **)(param_1 + 0x20) = plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeSpinLock(param_1 + 0x22);
  puVar10 = auStack_48;
  param_1[0x26] = 0;
  *(code **)(param_1 + 0x28) = CleanupFsmContext;
  LOCK();
  param_1[0x26] = param_1[0x26] + 1;
  UNLOCK();
  lVar7 = SstpFsmGlobalInfo + 0x50;
  plVar9 = *(longlong **)(SstpFsmGlobalInfo + 0x58);
  if (*plVar9 != lVar7) {
    plVar9 = (longlong *)0x3;
    pcVar6 = (code *)swi(0x29);
    lVar7 = (*pcVar6)();
    puVar10 = auStack_40;
  }
  *plVar1 = lVar7;
  *(longlong **)(param_1 + 0x20) = plVar9;
  *plVar9 = (longlong)plVar1;
  *(longlong **)(lVar7 + 8) = plVar1;
  LOCK();
  param_1[0x26] = param_1[0x26] + 1;
  UNLOCK();
  param_1[0x6c] = 0;
  lVar7 = SstpFsmGlobalInfo;
  *(undefined1 *)(param_1 + 0x6e) = 0;
  param_1[0x6a] = *(int *)(lVar7 + 4);
  iVar3 = *(int *)(lVar7 + 8);
  param_1[0x6d] = 0;
  param_1[0x6b] = iVar3;
  *(char *)((longlong)param_1 + 0x1be) = param_2;
  *(int **)(param_1 + 0x40) = param_1;
  param_1[0x3e] = param_3;
  *(undefined2 *)(param_1 + 0x6f) = 0;
  *(undefined2 *)((longlong)param_1 + 0x1b9) = 0;
  *(undefined1 *)(param_1 + 0x4a) = param_4;
  *(undefined1 *)((longlong)param_1 + 0x1bb) = 0;
  uVar2 = (-(uint)(param_2 != '\0') & 0xfffffff7) + 10;
  param_1[0x24] = uVar2;
  puVar4 = (&PTR_DummyTimeoutHandler_14000b008)[(ulonglong)uVar2 * 2];
  *(undefined4 *)(puVar10 + 0x20) = *(undefined4 *)(&TimeoutInfo + (ulonglong)uVar2 * 0x10);
  *(undefined8 *)(puVar10 + -8) = 0x140015cb3;
  SstpTimerInitialize((longlong *)(param_1 + 0x2a),(longlong)puVar4,(longlong)plVar1,&TimeoutInfo,
                      *(int *)(puVar10 + 0x20));
  LOCK();
  uVar2 = param_1[0x7d];
  param_1[0x7d] = 1;
  uVar8 = (ulonglong)uVar2;
  UNLOCK();
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (uVar8 = (ulonglong)(*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x84),
     (char)(*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == -0x7c)) {
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar10 + -8) = 0x140015cee;
    uVar8 = WPP_SF_(uVar5,0x17,&WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return uVar8;
}



===== IsValidCryptoBinding @ 140015d10 =====

undefined1 IsValidCryptoBinding(longlong param_1,PUCHAR param_2,undefined1 param_3)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  NTSTATUS NVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  short sVar8;
  ushort local_res8 [4];
  ushort local_res20 [4];
  PUCHAR local_38 [2];
  
  cVar1 = *(char *)(param_1 + 0xb0);
  local_38[0] = (PUCHAR)0x0;
  local_res8[0] = 0;
  local_res20[0] = 0;
  uVar2 = *(ushort *)(param_1 + 0x168);
  sVar8 = 0x14;
  if (cVar1 != '\x01') {
    sVar8 = 0x20;
  }
  lVar5 = 0xb1;
  if (cVar1 != '\x01') {
    lVar5 = 0xc5;
  }
  bVar3 = GenerateSstpCallConnected
                    ((undefined2 *)param_2,param_2,local_res20,cVar1,(undefined4 *)(lVar5 + param_1)
                     ,sVar8,(undefined8 *)(param_1 + 0x90),(longlong *)local_38,local_res8);
  if (bVar3) {
    if (local_res8[0] == uVar2) {
      lVar5 = param_1 + 0x10;
      KeReleaseSpinLock(lVar5,param_3);
      NVar4 = ComputeCompoundMac(param_1,param_2,(uint)local_res20[0],local_38[0],local_res8);
      if (NVar4 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                        &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
        }
        KeAcquireSpinLockRaiseToDpc(lVar5);
        return 0;
      }
      KeAcquireSpinLockRaiseToDpc(lVar5);
      if (local_res8[0] == uVar2) {
        uVar6 = RtlCompareMemory(local_38[0],param_1 + 0x147,(ulonglong)uVar2);
        if (uVar6 == uVar2) {
          return 1;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return 0;
        }
        if (WPP_GLOBAL_Control[0x29] == '\0') {
          return 0;
        }
        uVar7 = 0x59;
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return 0;
        }
        if (WPP_GLOBAL_Control[0x29] == '\0') {
          return 0;
        }
        uVar7 = 0x58;
      }
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return 0;
      }
      uVar7 = 0x56;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return 0;
    }
    uVar7 = 0x55;
  }
  WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
  return 0;
}



===== MoveToAbortState1 @ 140015f78 =====

void MoveToAbortState1(longlong param_1,undefined1 param_2,uint param_3,char param_4,
                      undefined1 *param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  ushort uVar4;
  int iVar5;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  if (*(char *)(param_1 + 0x146) == '\0') {
    uVar1 = *(int *)(param_1 + 0x18) - 0xd;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x18) - 5;
  }
  if (3 < uVar1) {
    uVar1 = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 0xd;
    *(uint *)(param_1 + 0x18) = uVar1;
    iVar5 = *(int *)(&TimeoutInfo + (ulonglong)uVar1 * 0x10);
    puVar3 = (&PTR_DummyTimeoutHandler_14000b008)[(ulonglong)uVar1 * 2];
    SstpTimerReschedule(param_1 + 0x30,puVar3,param_1,1,iVar5,param_4);
    uVar4 = (ushort)iVar5;
    puVar2 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
    if (puVar2 == (undefined8 *)0x0) {
      MoveToCallDisconnectedState(param_1,CONCAT71((int7)((ulonglong)puVar3 >> 8),param_4),param_5);
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
    }
    else {
      GenerateSstpMessageWithStatus
                (5,param_2,param_3,(undefined2 *)((longlong)puVar2 + 0x12),uVar4,
                 (ushort *)(puVar2 + 2));
      SendControlFrame(param_1,puVar2);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToAbortState2 @ 140016118 =====

void MoveToAbortState2(longlong param_1,char param_2,undefined8 param_3,uint param_4,char param_5,
                      undefined1 *param_6)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  ushort uVar4;
  int iVar5;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  if (*(char *)(param_1 + 0x146) == '\0') {
    uVar1 = *(int *)(param_1 + 0x18) - 0xe;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x18) - 6;
  }
  if (2 < uVar1) {
    uVar1 = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 0xe;
    *(uint *)(param_1 + 0x18) = uVar1;
    iVar5 = *(int *)(&TimeoutInfo + (ulonglong)uVar1 * 0x10);
    puVar3 = (&PTR_DummyTimeoutHandler_14000b008)[(ulonglong)uVar1 * 2];
    SstpTimerReschedule(param_1 + 0x30,puVar3,param_1,1,iVar5,param_5);
    uVar4 = (ushort)iVar5;
    if (param_2 != '\0') {
      puVar2 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
      if (puVar2 == (undefined8 *)0x0) {
        MoveToCallDisconnectedState
                  (param_1,CONCAT71((int7)((ulonglong)puVar3 >> 8),param_5),param_6);
        KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
      }
      else {
        GenerateSstpMessageWithStatus
                  (5,2,param_4,(undefined2 *)((longlong)puVar2 + 0x12),uVar4,(ushort *)(puVar2 + 2))
        ;
        SendControlFrame(param_1,puVar2);
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToCallConnectPendingState @ 1400162c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MoveToCallConnectPendingState(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      param_2 = 0x52;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_2 = 0x53;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  puVar1 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
  if (puVar1 == (undefined8 *)0x0) {
    MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
  }
  else {
    GenerateSstpConnectionAck
              ((undefined1 *)((longlong)puVar1 + 0x12),param_2,(ushort *)(puVar1 + 2),
               *(byte *)(param_1 + 0xb0),(undefined8 *)(param_1 + 0x90));
    SendControlFrame(param_1,puVar1);
    *(undefined4 *)(param_1 + 0x18) = 0xb;
    SstpTimerReschedule(param_1 + 0x30,PTR_ConnectPendingStateTimeout_14000b0b8,param_1,1,
                        DAT_14000b0b0,'\0');
    if (*(char *)(param_1 + 0xb0) == '\0') goto LAB_140016410;
    *(undefined1 *)(param_1 + 0x145) = 0;
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
    (**(code **)(SstpFsmGlobalInfo + 0x60))(*(undefined8 *)(param_1 + 0x88),0);
  }
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
LAB_140016410:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToCallConnectedPassive @ 140016460 =====

void MoveToCallConnectedPassive(longlong param_1)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                  &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  if (uVar1 == 3) {
    MoveToCallConnectedState(param_1,uVar2);
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
  {
    WPP_SF__guid_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,(ulonglong)uVar1,param_1 + 0x16c,
                   (char)uVar1);
  }
  KeReleaseSpinLock(param_1 + 0x10,uVar2);
  DereferenceRefCount((int *)(param_1 + 0x20));
  return;
}



===== MoveToCallConnectedState @ 14001654c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MoveToCallConnectedState(longlong param_1,undefined1 param_2)

{
  char cVar1;
  NTSTATUS NVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ushort local_res8 [4];
  PUCHAR local_res18;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(uint *)(param_1 + 0x18) = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 0xc;
  if ((*(int *)(param_1 + 0x130) != 0) && (*(int *)(param_1 + 0x134) != 0)) {
    *(undefined4 *)(param_1 + 0x138) = 0;
    SstpTimerReschedule(param_1 + 0x30,HelloIntervalTickExpired,param_1,0,*(int *)(param_1 + 0x134),
                        '\0');
  }
  if (*(char *)(param_1 + 0x146) != '\0') {
    puVar3 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
    if (puVar3 == (undefined8 *)0x0) {
      MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
      goto LAB_14001684f;
    }
    cVar1 = *(char *)(param_1 + 0xb0);
    uVar5 = 0x14;
    local_res18 = (PUCHAR)0x0;
    local_res8[0] = 0;
    if (cVar1 != '\x01') {
      uVar5 = 0x20;
    }
    lVar4 = 0xb1;
    if (cVar1 != '\x01') {
      lVar4 = 0xc5;
    }
    GenerateSstpCallConnected
              ((undefined2 *)((longlong)puVar3 + 0x12),uVar5,(ushort *)(puVar3 + 2),cVar1,
               (undefined4 *)(lVar4 + param_1),(short)uVar5,(undefined8 *)(param_1 + 0x90),
               (longlong *)&local_res18,local_res8);
    if (*(char *)(param_1 + 0xb0) != '\0') {
      lVar4 = param_1 + 0x10;
      KeReleaseSpinLock(lVar4,param_2);
      NVar2 = ComputeCompoundMac(param_1,(PUCHAR)((longlong)puVar3 + 0x12),
                                 (uint)*(ushort *)(puVar3 + 2),local_res18,local_res8);
      if (NVar2 == 0) {
        KeAcquireSpinLockRaiseToDpc(lVar4);
      }
      else {
        ExFreeToNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
        KeAcquireSpinLockRaiseToDpc(lVar4);
        MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
        KeAcquireSpinLockAtDpcLevel(lVar4);
      }
    }
    if ((*(int *)(param_1 + 0x18) - 4U & 0xfffffff7) != 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                      &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
      }
      goto LAB_14001684f;
    }
    SendControlFrame(param_1,puVar3);
  }
  if (*(char *)(param_1 + 0xb0) == '\0') {
    *(undefined1 *)(param_1 + 0x145) = 0;
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
    (**(code **)(SstpFsmGlobalInfo + 0x60))(*(undefined8 *)(param_1 + 0x88),0);
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  }
  (**(code **)(SstpFsmGlobalInfo + 0x78))(*(undefined8 *)(param_1 + 0x88));
LAB_14001684f:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToCallDisconnectedState @ 14001689c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MoveToCallDisconnectedState(longlong param_1,undefined8 param_2,undefined1 *param_3)

{
  char cVar1;
  undefined7 uVar2;
  int *piVar3;
  
  cVar1 = (char)param_2;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      param_2 = 0;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_2 = 0;
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  if ((*(int *)(param_1 + 0x18) - 1U & 0xfffffff7) == 0) {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  }
  else {
    uVar2 = (undefined7)((ulonglong)param_2 >> 8);
    *(uint *)(param_1 + 0x18) = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 9;
    SstpTimerDisable(param_1 + 0x30,cVar1);
    if (*(char *)(param_1 + 0x145) == '\0') {
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
      (**(code **)(SstpFsmGlobalInfo + 0x68))
                (*(undefined8 *)(param_1 + 0x88),CONCAT71(uVar2,*(undefined1 *)(param_1 + 0x141)),
                 *(undefined1 *)(param_1 + 0x142));
    }
    else {
      KeReleaseSpinLockFromDpcLevel();
      (**(code **)(SstpFsmGlobalInfo + 0x60))(*(undefined8 *)(param_1 + 0x88),0xc0000241);
    }
    SstpTimerDelete((longlong *)(param_1 + 0x30),cVar1);
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 1;
    }
    piVar3 = (int *)(param_1 + 0x20);
    DereferenceRefCount(piVar3);
    DereferenceRefCount(piVar3);
    DereferenceRefCount(piVar3);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToConnectAckReceivedState @ 140016a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MoveToConnectAckReceivedState(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                  &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
  }
  *(undefined4 *)(param_1 + 0x18) = 3;
  SstpTimerReschedule(param_1 + 0x30,PTR_ConnectAckReceivedTimeout_14000b038,param_1,1,DAT_14000b030
                      ,'\0');
  *(undefined1 *)(param_1 + 0x145) = 0;
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x10);
  (**(code **)(SstpFsmGlobalInfo + 0x60))(*(undefined8 *)(param_1 + 0x88),0);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  return;
}



===== MoveToConnectRequestSentState @ 140016b18 =====

undefined8 MoveToConnectRequestSentState(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  uVar2 = 0x103;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  puVar1 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 2;
    lVar3 = param_1;
    SstpTimerReschedule(param_1 + 0x30,PTR_ConnectRequestSentTimeout_14000b028,param_1,1,
                        DAT_14000b020,'\0');
    GenerateSstpConnectionRequest
              ((ushort)*(undefined4 *)(param_1 + 0x80),(undefined2 *)((longlong)puVar1 + 0x12),lVar3
               ,(ushort *)(puVar1 + 2));
    SendControlFrame(param_1,puVar1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return uVar2;
}



===== MoveToDisconnectState1 @ 140016c5c =====

void MoveToDisconnectState1(longlong param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  ushort uVar3;
  int iVar4;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  if (*(char *)(param_1 + 0x146) == '\0') {
    uVar1 = *(int *)(param_1 + 0x18) - 0xd;
  }
  else {
    uVar1 = *(int *)(param_1 + 0x18) - 5;
  }
  if (3 < uVar1) {
    *(undefined4 *)(param_1 + 0x13c) = 0;
    uVar1 = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 0xf;
    *(uint *)(param_1 + 0x18) = uVar1;
    iVar4 = *(int *)(&TimeoutInfo + (ulonglong)uVar1 * 0x10);
    SstpTimerReschedule(param_1 + 0x30,(&PTR_DummyTimeoutHandler_14000b008)[(ulonglong)uVar1 * 2],
                        param_1,1,iVar4,'\0');
    uVar3 = (ushort)iVar4;
    puVar2 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
    if (puVar2 == (undefined8 *)0x0) {
      MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
    }
    else {
      GenerateSstpMessageWithStatus
                (6,0,0,(undefined2 *)((longlong)puVar2 + 0x12),uVar3,(ushort *)(puVar2 + 2));
      SendControlFrame(param_1,puVar2);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== MoveToDisconnectState2 @ 140016de4 =====

void MoveToDisconnectState2(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x146) == '\0') {
    if (((iVar2 - 0xdU & 0xfffffffc) == 0) && (iVar2 != 0xf)) goto LAB_140016f2a;
  }
  else if (((iVar2 - 5U & 0xfffffffc) == 0) && (iVar2 != 7)) goto LAB_140016f2a;
  uVar1 = (-(uint)(*(char *)(param_1 + 0x146) != '\0') & 0xfffffff8) + 0x10;
  *(uint *)(param_1 + 0x18) = uVar1;
  SstpTimerReschedule(param_1 + 0x30,(&PTR_DummyTimeoutHandler_14000b008)[(ulonglong)uVar1 * 2],
                      param_1,1,*(int *)(&TimeoutInfo + (ulonglong)uVar1 * 0x10),'\0');
  puVar3 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
  if (puVar3 == (undefined8 *)0x0) {
    MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x10);
  }
  else {
    *(undefined4 *)(puVar3 + 2) = 0x1100008;
    *(undefined4 *)((longlong)puVar3 + 0x16) = 0x700;
    *(ushort *)((longlong)puVar3 + 0x14) =
         *(ushort *)(puVar3 + 2) >> 8 | *(ushort *)(puVar3 + 2) << 8;
    SendControlFrame(param_1,puVar3);
  }
LAB_140016f2a:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== ProcessCryptoBinding @ 140016f70 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ProcessCryptoBinding(longlong param_1,undefined1 param_2)

{
  char cVar1;
  undefined1 auStackY_1048 [32];
  UCHAR local_1018 [4096];
  ulonglong local_18;
  undefined8 local_10;
  
  local_10 = 0x140016f85;
  local_18 = __security_cookie ^ (ulonglong)auStackY_1048;
  memset(local_1018,0,0xfff);
  cVar1 = IsValidCryptoBinding(param_1,local_1018,param_2);
  if (cVar1 == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    MoveToAbortState1(param_1,3,4,'\0',(undefined1 *)0x0);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    if (*(int *)(param_1 + 0x18) == 0xb) {
      MoveToCallConnectedState(param_1,param_2);
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
            (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
    }
  }
  return;
}



===== ProcessCryptoBindingPassive @ 1400170d0 =====

void ProcessCryptoBindingPassive(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  ProcessCryptoBinding(param_1,uVar1);
  KeReleaseSpinLock(param_1 + 0x10,uVar1);
  DereferenceRefCount((int *)(param_1 + 0x20));
  return;
}



===== ReceiveCtrlMessage @ 140017130 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ReceiveCtrlMessage(longlong param_1,char *param_2,ushort param_3,undefined8 param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  int iVar10;
  undefined1 uVar11;
  undefined2 uVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  UCHAR *pUVar16;
  undefined *puVar17;
  int *piVar18;
  undefined1 auStackY_1338 [32];
  char local_12e8;
  char local_12e7;
  undefined1 local_12e6 [2];
  ushort local_12e4 [2];
  short local_12e0 [2];
  uint local_12dc;
  undefined4 local_12d8;
  int local_12d4 [7];
  undefined4 local_12b8;
  undefined1 local_12b4 [116];
  uint local_1240;
  int local_123c;
  char local_1238;
  int local_1234;
  undefined1 local_11d0;
  undefined4 local_11cc;
  undefined4 local_11c8;
  undefined1 local_11c0;
  undefined1 local_1158;
  undefined4 local_1154;
  int local_114c;
  char local_1148;
  byte local_1141;
  undefined1 local_1140 [32];
  undefined1 local_1120 [32];
  undefined8 local_1100;
  undefined8 uStack_10f8;
  undefined4 local_10f0;
  undefined4 uStack_10ec;
  undefined8 uStack_10e8;
  int local_10d4;
  byte local_10c9;
  undefined8 local_10c8;
  undefined8 uStack_10c0;
  undefined8 local_10b8;
  undefined8 uStack_10b0;
  char local_1058 [16];
  UCHAR local_1048 [4096];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x140017152;
  local_48 = __security_cookie ^ (ulonglong)auStackY_1338;
  local_12e4[0] = 0;
  local_12e0[0] = 0;
  local_12b8 = 0;
  memset(local_12b4,0,0x74);
  memset(&local_1240,0,0x1e0);
  local_12dc = 0;
  local_1058[0] = '\0';
  local_1058[1] = '\0';
  local_1058[2] = '\0';
  local_1058[3] = '\0';
  local_1058[4] = '\0';
  local_1058[5] = '\0';
  local_1058[6] = '\0';
  local_1058[7] = '\0';
  local_1058[8] = '\0';
  local_1058[9] = '\0';
  local_12e6[0] = 0;
  local_12e7 = '\0';
  local_12e8 = '\0';
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  pUVar16 = local_1048;
  uVar6 = ParseSstpControlMessage
                    (param_2,param_3,(longlong)pUVar16,param_4,local_12e4,local_12e0,
                     (longlong)&local_12b8,&local_12dc,local_12e6,&local_12e8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF__guid_Lq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                    (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),pUVar16,param_1 + 0x16c,
                    (char)local_12dc,(char)*(undefined8 *)(param_1 + 0x88));
  }
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x10);
  if (local_1148 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
              &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
    }
    *(undefined1 *)(param_1 + 0x142) = 1;
  }
  uVar5 = local_12dc;
  uVar1 = local_12e4[0];
  *(undefined1 *)(param_1 + 0x140) = 1;
  if ((*(int *)(param_1 + 0x18) - 1U & 0xfffffff7) == 0) goto LAB_140017448;
  if (((local_12e4[0] < 0x1000) && (lVar15 = (longlong)(int)local_12dc, local_12dc - 1 < 9)) &&
     ((char)uVar6 != '\0')) {
    GetAcceptedMessageTypesForCurrentState
              (*(int *)(param_1 + 0x18),(undefined8 *)local_1058,&local_12e7);
    if (local_12e7 == '\0') {
      if (local_1058[lVar15] == '\0') {
        uVar5 = 5;
        goto LAB_140017bfd;
      }
      puVar13 = &local_12d8;
      GetAttributeRequirementsForControlMessage(uVar5,puVar13);
      if (local_12d4[3] == 1) {
        local_12d4[3] = ~-(uint)(*(char *)(param_1 + 0xb0) != '\0') & 2;
      }
      if (local_12d4[2] == 1) {
        local_12d4[2] = ~-(uint)(*(char *)(param_1 + 0xb0) != '\0') & 2;
      }
      uVar6 = CONCAT71((int7)((ulonglong)puVar13 >> 8),local_12e6[0]);
      puVar7 = &local_1240;
      piVar18 = local_12d4;
      uVar9 = 1;
      do {
        *puVar7 = uVar9;
        if (puVar7[1] == 3) {
          if (*piVar18 != 2) goto LAB_1400173fa;
          puVar7[0x1d] = 9;
LAB_1400173eb:
          *(char *)(puVar7 + 0x1c) = (char)uVar9;
          uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
          *(undefined1 *)(puVar7 + 2) = 1;
          *puVar7 = 2;
        }
        else {
          if ((puVar7[1] == 4) && (*piVar18 == 0)) {
            puVar7[0x1d] = 10;
            goto LAB_1400173eb;
          }
LAB_1400173fa:
          *(undefined1 *)(puVar7 + 2) = 0;
        }
        uVar9 = uVar9 + 1;
        piVar18 = piVar18 + 1;
        puVar7 = puVar7 + 0x1e;
      } while (uVar9 < 5);
      iVar10 = *(int *)(param_1 + 0x18);
      if (*(char *)(param_1 + 0x146) == '\0') {
        if (iVar10 == 10) {
          if (uVar5 == 1) {
            if ((((local_1240 == 1) && (local_1238 == '\0')) && (local_123c == 3)) &&
               (local_1234 != *(int *)(param_1 + 0x80))) {
              local_1238 = '\x01';
              uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
              local_11d0 = 1;
              local_11cc = 4;
            }
            if (local_12e8 != '\0') {
              local_11c0 = 1;
              uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
              local_1158 = 2;
              local_1154 = 0xb;
              local_11c8 = 2;
            }
            if ((char)uVar6 == '\0') {
              MoveToCallConnectPendingState(param_1,uVar6);
              goto LAB_140017448;
            }
            uVar5 = *(int *)(param_1 + 0x13c) + 1;
            *(uint *)(param_1 + 0x13c) = uVar5;
            if (3 < uVar5) goto LAB_140017b6d;
            puVar8 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
            if (puVar8 == (undefined8 *)0x0) goto LAB_140017b97;
            GenerateSstpConnectNak
                      ((longlong)&local_12b8,(undefined2 *)((longlong)puVar8 + 0x12),piVar18,
                       (ushort *)(puVar8 + 2),local_1048,uVar1,local_12e0[0]);
LAB_140017553:
            SendControlFrame(param_1,puVar8);
            goto LAB_140017448;
          }
        }
        else {
          iVar10 = iVar10 + -0xb;
          if (iVar10 != 0) goto LAB_14001769f;
          if (uVar5 == 4) {
            if ((local_12e8 != '\0') || ((char)uVar6 != '\0')) goto LAB_140017aeb;
            if (*(char *)(param_1 + 0x144) == '\0') {
              if (local_114c == 4) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
                                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
                }
                goto LAB_140017a00;
              }
              bVar3 = local_1141 & *(byte *)(param_1 + 0xb0);
              if (bVar3 == 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                   (WPP_GLOBAL_Control[0x29] != '\0')) {
                  uVar12 = 0x61;
LAB_1400177d1:
                  WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                                &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,param_1 + 0x16c);
                }
              }
              else {
                uVar12 = 0x20;
                *(byte *)(param_1 + 0xb0) = bVar3;
                lVar15 = RtlCompareMemory(param_1 + 0x90,local_1140,0x20);
                if (lVar15 == 0x20) {
                  if (local_1141 == 1) {
                    uVar12 = 0x14;
                    uVar6 = 0;
                    lVar15 = RtlCompareMemory(param_1 + 0xb1,local_1120,0x14);
                    if (lVar15 == 0x14) {
                      *(undefined8 *)(param_1 + 0x147) = local_1100;
                      *(undefined8 *)(param_1 + 0x14f) = uStack_10f8;
                      *(undefined4 *)(param_1 + 0x157) = local_10f0;
LAB_140017950:
                      *(undefined2 *)(param_1 + 0x168) = uVar12;
                      if (*(char *)(param_1 + 0x143) == '\0') {
                        *(undefined1 *)(param_1 + 0x144) = 1;
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                                        &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,
                                        param_1 + 0x16c);
                        }
                      }
                      else {
                        puVar17 = (undefined *)CONCAT71((int7)((ulonglong)uVar6 >> 8),uVar2);
                        cVar4 = IsValidCryptoBinding(param_1,local_1048,uVar2);
                        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                          uVar14 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c);
                          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
                             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                            puVar17 = &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids;
                            uVar14 = 0x66;
                            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                                    &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
                          }
                          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                             (WPP_GLOBAL_Control[0x29] != '\0')) {
                            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,puVar17,
                                     (uint)(cVar4 == '\0'));
                          }
                        }
                        if (cVar4 == '\0') goto LAB_140017ade;
                        if (*(int *)(param_1 + 0x18) == 0xb) goto LAB_140017a00;
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                           (WPP_GLOBAL_Control[0x29] != '\0')) {
                          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                                        &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids,
                                        param_1 + 0x16c);
                        }
                      }
                      goto LAB_140017448;
                    }
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                       (WPP_GLOBAL_Control[0x29] != '\0')) {
                      uVar12 = 99;
                      goto LAB_1400177d1;
                    }
                  }
                  else if (local_1141 == 2) {
                    uVar6 = 0;
                    lVar15 = RtlCompareMemory(param_1 + 0xc5,local_1120,0x20);
                    if (lVar15 == 0x20) {
                      *(undefined8 *)(param_1 + 0x147) = local_1100;
                      *(undefined8 *)(param_1 + 0x14f) = uStack_10f8;
                      *(ulonglong *)(param_1 + 0x157) = CONCAT44(uStack_10ec,local_10f0);
                      *(undefined8 *)(param_1 + 0x15f) = uStack_10e8;
                      goto LAB_140017950;
                    }
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                       (WPP_GLOBAL_Control[0x29] != '\0')) {
                      uVar12 = 100;
                      goto LAB_1400177d1;
                    }
                  }
                  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                          (WPP_GLOBAL_Control[0x29] != '\0')) {
                    uVar12 = 0x65;
                    goto LAB_1400177d1;
                  }
                }
                else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                        (WPP_GLOBAL_Control[0x29] != '\0')) {
                  uVar12 = 0x62;
                  goto LAB_1400177d1;
                }
              }
LAB_140017ade:
              uVar5 = 4;
              uVar11 = 3;
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
                        &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
              }
              uVar5 = 5;
              uVar11 = 2;
            }
            MoveToAbortState1(param_1,uVar11,uVar5,'\0',(undefined1 *)0x0);
            goto LAB_140017448;
          }
        }
LAB_140017569:
        if (uVar5 == 5) {
          *(undefined1 *)(param_1 + 0x141) = 1;
LAB_1400174df:
          cVar4 = '\x01';
LAB_1400174e5:
          MoveToAbortState2(param_1,cVar4,piVar18,0,'\0',(undefined1 *)0x0);
        }
        else if (uVar5 == 6) {
          *(undefined1 *)(param_1 + 0x141) = 1;
LAB_1400174ca:
          MoveToDisconnectState2(param_1);
        }
      }
      else if (iVar10 == 2) {
        if (uVar5 == 2) {
          if ((local_12e8 != '\0') || ((char)uVar6 != '\0')) {
LAB_140017aeb:
            uVar5 = 9;
            goto LAB_140017af1;
          }
          bVar3 = *(byte *)(param_1 + 0xb0);
          if (bVar3 == 0) {
            if (local_10d4 == 4) {
LAB_140017a00:
              MoveToCallConnectedState(param_1,uVar2);
              goto LAB_140017448;
            }
            if (local_10d4 != 3) {
LAB_140017611:
              local_10c9 = local_10c9 & bVar3;
              *(byte *)(param_1 + 0xb0) = local_10c9;
              *(undefined8 *)(param_1 + 0x90) = local_10c8;
              *(undefined8 *)(param_1 + 0x98) = uStack_10c0;
              *(undefined8 *)(param_1 + 0xa0) = local_10b8;
              *(undefined8 *)(param_1 + 0xa8) = uStack_10b0;
              if ((local_10c9 & 2) == 0) {
                if ((local_10c9 & 1) != 0) {
                  *(undefined1 *)(param_1 + 0xb0) = 1;
                }
              }
              else {
                *(undefined1 *)(param_1 + 0xb0) = 2;
              }
              MoveToConnectAckReceivedState(param_1);
              goto LAB_140017448;
            }
            uVar5 = 9;
          }
          else if (local_10d4 == 4) {
            uVar5 = 10;
          }
          else {
            if ((local_10d4 != 3) || ((bVar3 & local_10c9) != 0)) goto LAB_140017611;
            uVar5 = 4;
          }
          uVar11 = 4;
        }
        else {
          if (uVar5 != 3) goto LAB_140017569;
          uVar5 = *(int *)(param_1 + 0x13c) + 1;
          *(uint *)(param_1 + 0x13c) = uVar5;
          if (uVar5 < 4) {
            uVar6 = MoveToConnectRequestSentState(param_1);
            if (-1 < (int)uVar6) goto LAB_140017448;
            goto LAB_140017b97;
          }
LAB_140017b6d:
          uVar5 = 6;
LAB_140017af1:
          uVar11 = 2;
        }
        MoveToAbortState1(param_1,uVar11,uVar5,'\0',(undefined1 *)0x0);
      }
      else {
        iVar10 = iVar10 + -3;
        if (iVar10 == 0) goto LAB_140017569;
LAB_14001769f:
        if (iVar10 == 1) {
          if (uVar5 == 8) {
            puVar8 = (undefined8 *)ExAllocateFromNPagedLookasideList(SstpFsmGlobalInfo + 0x80);
            if (puVar8 != (undefined8 *)0x0) {
              *(undefined4 *)(puVar8 + 2) = 0x1100008;
              *(undefined4 *)((longlong)puVar8 + 0x16) = 0x900;
              *(ushort *)((longlong)puVar8 + 0x14) =
                   *(ushort *)(puVar8 + 2) >> 8 | *(ushort *)(puVar8 + 2) << 8;
              goto LAB_140017553;
            }
          }
          else if (uVar5 != 9) goto LAB_140017569;
        }
        else {
          if (iVar10 != 2) {
            if (iVar10 == 4) {
              if (uVar5 != 7) {
                if (uVar5 == 6) goto LAB_1400174ca;
                if (uVar5 != 5) goto LAB_140017448;
                goto LAB_1400174df;
              }
            }
            else if ((iVar10 != 5) || (uVar5 != 7)) goto LAB_140017448;
LAB_140017b97:
            MoveToCallDisconnectedState(param_1,0,(undefined1 *)0x0);
            KeLowerIrql(uVar2);
            goto LAB_14001745b;
          }
          if (uVar5 == 5) {
            cVar4 = '\0';
            goto LAB_1400174e5;
          }
        }
      }
LAB_140017448:
      KeReleaseSpinLock(param_1 + 0x10,uVar2);
      goto LAB_14001745b;
    }
  }
  else {
    uVar5 = 7;
LAB_140017bfd:
    MoveToAbortState1(param_1,2,uVar5,'\0',(undefined1 *)0x0);
  }
  KeReleaseSpinLock(param_1 + 0x10,uVar2);
LAB_14001745b:
  DereferenceRefCount((int *)(param_1 + 0x20));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== SendControlFrame @ 140017c38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SendControlFrame(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  *param_2 = 0;
  lVar1 = SstpFsmGlobalInfo;
  *(undefined1 *)(param_2 + 1) = 1;
  iVar2 = (**(code **)(lVar1 + 0x70))(*(undefined8 *)(param_1 + 0x88),param_2);
  if (iVar2 == 0) {
    FsmTpiControlFrameSendComplete(param_2);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x84) == 0x84)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_5005d3f2f4aa383d1cff75d2f89e1f8e_Traceguids);
  }
  return;
}



===== GenerateSstpAttribute @ 140017cf4 =====

bool GenerateSstpAttribute
               (undefined1 param_1,void *param_2,ushort param_3,undefined1 *param_4,ushort param_5,
               ushort *param_6)

{
  ushort uVar1;
  bool bVar2;
  
  bVar2 = (ulonglong)param_3 + 4 <= (ulonglong)param_5;
  if (bVar2) {
    uVar1 = param_3 + 4;
    param_4[1] = param_1;
    *param_4 = 0;
    *(ushort *)(param_4 + 2) = uVar1 >> 8 | uVar1 * 0x100;
    memmove(param_4 + 4,param_2,(ulonglong)param_3);
    *param_6 = uVar1;
  }
  return bVar2;
}



===== GenerateSstpCallConnected @ 140017d50 =====

bool GenerateSstpCallConnected
               (undefined2 *param_1,undefined8 param_2,ushort *param_3,char param_4,
               undefined4 *param_5,short param_6,undefined8 *param_7,longlong *param_8,
               undefined2 *param_9)

{
  bool bVar1;
  undefined2 uVar2;
  longlong lVar3;
  ushort local_res20 [4];
  undefined1 local_98 [3];
  char local_95;
  undefined8 local_94;
  undefined8 uStack_8c;
  undefined8 local_84;
  undefined8 uStack_7c;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  
  local_res20[0] = 0;
  if (param_4 == '\0') {
    *param_1 = 0x110;
    param_1[2] = 0x400;
    *param_3 = 8;
    param_1[3] = 0;
    param_1[1] = *param_3 >> 8 | *param_3 << 8;
LAB_140017eac:
    bVar1 = true;
  }
  else {
    if (param_4 == '\x03') {
      return false;
    }
    memset(local_98,0,100);
    *param_1 = 0x110;
    param_1[2] = 0x400;
    *param_9 = 0;
    *param_8 = 0;
    *param_3 = 8;
    param_1[3] = 0x100;
    local_94 = *param_7;
    uStack_8c = param_7[1];
    local_84 = param_7[2];
    uStack_7c = param_7[3];
    if (param_4 == '\x01') {
      uVar2 = 0x14;
      if (param_6 == 0x14) {
        local_74 = *param_5;
        uStack_70 = param_5[1];
        uStack_6c = param_5[2];
        uStack_68 = param_5[3];
        local_64 = CONCAT44(local_64._4_4_,param_5[4]);
LAB_140017e4e:
        lVar3 = 0x44;
        *param_9 = uVar2;
LAB_140017e5b:
        local_95 = param_4;
        bVar1 = GenerateSstpAttribute
                          (3,local_98,100,(undefined1 *)((ulonglong)*param_3 + (longlong)param_1),
                           0xfff - *param_3,local_res20);
        if (!bVar1) {
          return bVar1;
        }
        *param_3 = *param_3 + local_res20[0];
        param_1[1] = *param_3 >> 8 | *param_3 << 8;
        *param_8 = (longlong)param_1 + lVar3 + 0xc;
        goto LAB_140017eac;
      }
    }
    else {
      lVar3 = 0;
      if (param_4 != '\x02') goto LAB_140017e5b;
      uVar2 = 0x20;
      if (param_6 == 0x20) {
        local_64 = *(undefined8 *)(param_5 + 4);
        uStack_5c = *(undefined8 *)(param_5 + 6);
        local_74 = *param_5;
        uStack_70 = param_5[1];
        uStack_6c = param_5[2];
        uStack_68 = param_5[3];
        goto LAB_140017e4e;
      }
    }
    bVar1 = false;
  }
  return bVar1;
}



===== GenerateSstpConnectNak @ 140017ed4 =====

bool GenerateSstpConnectNak
               (longlong param_1,undefined2 *param_2,undefined8 param_3,ushort *param_4,
               void *param_5,ushort param_6,short param_7)

{
  ushort uVar1;
  undefined4 uVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  longlong lVar7;
  uint uVar8;
  ushort local_res18 [4];
  undefined1 local_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  ushort uStack_33;
  undefined1 uStack_31;
  
  *param_2 = 0x110;
  param_2[2] = 0x300;
  local_res18[0] = 0;
  local_38 = 0;
  uStack_37 = 0;
  uStack_36 = 0;
  uStack_35 = 0;
  uStack_34 = 0;
  uStack_33 = 0;
  *param_4 = 8;
  uStack_31 = 0;
  uVar5 = 0;
  uVar8 = 0;
  do {
    if (4 < uVar8) {
      if (param_6 != 0) {
        if ((int)(uint)param_6 <= (int)(0xfff - (uint)*param_4)) {
          memmove((void *)((ulonglong)*param_4 + (longlong)param_2),param_5,(ulonglong)(uint)param_6
                 );
          *param_4 = *param_4 + param_6;
          uVar5 = uVar5 + param_7;
        }
      }
      param_2[3] = uVar5 >> 8 | uVar5 << 8;
      param_2[1] = *param_4 >> 8 | *param_4 << 8;
      return true;
    }
    lVar7 = (ulonglong)uVar8 * 0x78;
    if (*(char *)(lVar7 + 8 + param_1) != '\0') {
      uVar2 = *(undefined4 *)(lVar7 + 0x74 + param_1);
      local_38 = 0;
      uStack_37 = 0;
      uStack_33 = (ushort)((uint)uVar2 >> 0x10) & 0xff | (ushort)uVar2 & 0xff00;
      uStack_34 = (undefined1)((uint)uVar2 >> 0x18);
      uStack_31 = (undefined1)uVar2;
      uStack_36 = 0;
      uStack_35 = (undefined1)uVar8;
      bVar3 = GenerateSstpAttribute
                        (2,&local_38,8,(undefined1 *)((ulonglong)*param_4 + (longlong)param_2),
                         0xfff - *param_4,local_res18);
      if (!bVar3) {
        return bVar3;
      }
      uVar5 = uVar5 + 1;
      uVar6 = local_res18[0] + *param_4;
      *param_4 = uVar6;
      if ((*(int *)(lVar7 + param_1) == 1) && (2 < 0xfff - (ulonglong)uVar6)) {
        uVar1 = *(ushort *)(lVar7 + 0xc + param_1);
        uVar4 = *(ushort *)(((ulonglong)uVar6 - (ulonglong)local_res18[0]) + 2 + (longlong)param_2);
        uVar4 = (uVar4 >> 8 | (uVar4 & 0xf) << 8) + 2;
        *(ushort *)(((ulonglong)uVar6 - (ulonglong)local_res18[0]) + 2 + (longlong)param_2) =
             uVar4 >> 8 | uVar4 * 0x100;
        *(ushort *)((ulonglong)*param_4 + (longlong)param_2) = uVar1 >> 8 | uVar1 << 8;
        *param_4 = *param_4 + 2;
      }
    }
    uVar8 = uVar8 + 1;
  } while( true );
}



===== GenerateSstpConnectionAck @ 140018084 =====

bool GenerateSstpConnectionAck
               (undefined1 *param_1,undefined8 param_2,ushort *param_3,byte param_4,
               undefined8 *param_5)

{
  bool bVar1;
  ushort local_res20 [4];
  int local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  local_res20[0] = 0;
  *param_1 = 0x10;
  param_1[1] = 1;
  *(undefined2 *)(param_1 + 4) = 0x200;
  *param_3 = 8;
  if (param_4 == 0) {
    *(undefined2 *)(param_1 + 6) = 0;
    *(ushort *)(param_1 + 2) = *param_3 >> 8 | *param_3 << 8;
  }
  else {
    *(undefined2 *)(param_1 + 6) = 0x100;
    local_38 = (uint)param_4 << 0x18;
    uStack_34 = (undefined4)*param_5;
    uStack_30 = (undefined4)((ulonglong)*param_5 >> 0x20);
    uStack_2c = (undefined4)param_5[1];
    local_28 = (undefined4)((ulonglong)param_5[1] >> 0x20);
    uStack_24 = (undefined4)param_5[2];
    uStack_20 = (undefined4)((ulonglong)param_5[2] >> 0x20);
    uStack_1c = (undefined4)param_5[3];
    local_18 = (undefined4)((ulonglong)param_5[3] >> 0x20);
    bVar1 = GenerateSstpAttribute(4,&local_38,0x24,param_1 + *param_3,0xfff - *param_3,local_res20);
    if (!bVar1) {
      return bVar1;
    }
    *param_3 = *param_3 + local_res20[0];
    *(ushort *)(param_1 + 2) = *param_3 >> 8 | *param_3 << 8;
  }
  return true;
}



===== GenerateSstpConnectionRequest @ 14001816c =====

bool GenerateSstpConnectionRequest
               (ushort param_1,undefined2 *param_2,undefined8 param_3,ushort *param_4)

{
  bool bVar1;
  ushort local_res18 [8];
  ushort local_18 [8];
  
  *param_2 = 0x110;
  local_18[0] = param_1 >> 8 | param_1 << 8;
  local_res18[0] = 0;
  param_2[2] = 0x100;
  *param_4 = 8;
  param_2[3] = 0x100;
  bVar1 = GenerateSstpAttribute
                    (1,local_18,2,(undefined1 *)((ulonglong)*param_4 + (longlong)param_2),
                     0xfff - *param_4,local_res18);
  if (bVar1) {
    *param_4 = *param_4 + local_res18[0];
    param_2[1] = *param_4 >> 8 | *param_4 << 8;
  }
  return bVar1;
}



===== GenerateSstpMessageWithStatus @ 14001820c =====

bool GenerateSstpMessageWithStatus
               (ushort param_1,undefined1 param_2,uint param_3,undefined2 *param_4,ushort param_5,
               ushort *param_6)

{
  ushort *puVar1;
  bool bVar2;
  undefined1 local_18;
  undefined2 local_17;
  undefined1 uStack_15;
  uint uStack_14;
  
  puVar1 = param_6;
  *param_4 = 0x110;
  param_4[2] = param_1 >> 8 | param_1 << 8;
  param_5 = 0;
  *param_6 = 8;
  local_18 = 0;
  local_17 = 0;
  uStack_14 = param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
              param_3 << 0x18;
  param_4[3] = 0x100;
  uStack_15 = param_2;
  bVar2 = GenerateSstpAttribute
                    (2,&local_18,8,(undefined1 *)((ulonglong)*param_6 + (longlong)param_4),
                     0xfff - *param_6,&param_5);
  if (bVar2) {
    *puVar1 = *puVar1 + param_5;
    param_4[1] = *puVar1 >> 8 | *puVar1 << 8;
  }
  return bVar2;
}



===== GetAttributeRequirementsForControlMessage @ 1400182bc =====

void GetAttributeRequirementsForControlMessage(int param_1,undefined4 *param_2)

{
  *param_2 = 2;
  param_2[1] = 2;
  param_2[2] = 2;
  param_2[3] = 2;
  param_2[4] = 2;
  if (param_1 == 1) {
    param_2[1] = 0;
  }
  else {
    if (param_1 == 2) {
      param_2[4] = 1;
      return;
    }
    if (param_1 == 3) {
      param_2[2] = 0;
      return;
    }
    if (param_1 == 4) {
      param_2[3] = 1;
      return;
    }
    if ((param_1 == 5) || (param_1 == 6)) {
      param_2[2] = 1;
      return;
    }
  }
  return;
}



===== ParseSstpControlMessage @ 140018318 =====

undefined8
ParseSstpControlMessage
          (char *param_1,ushort param_2,longlong param_3,undefined8 param_4,ushort *param_5,
          short *param_6,longlong param_7,uint *param_8,undefined1 *param_9,undefined1 *param_10)

{
  byte bVar1;
  short sVar2;
  undefined8 uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  undefined1 *puVar7;
  longlong lVar8;
  ushort uVar9;
  ushort uVar10;
  undefined1 uVar11;
  ushort uVar12;
  int iVar13;
  undefined1 *puVar14;
  ushort uVar15;
  char *pcVar16;
  char *pcVar17;
  undefined2 *puVar18;
  
  uVar11 = 1;
  uVar15 = 0;
  *param_9 = 0;
  lVar8 = 8;
  *param_10 = 0;
  *param_5 = 0;
  *param_6 = 0;
  puVar6 = (ushort *)param_6;
  if (7 < param_2) {
    puVar14 = param_10;
    puVar6 = (ushort *)SstpValidateSstpHeader(param_1,'\x01');
    if ((char)puVar6 != '\0') {
      uVar4 = *(ushort *)(param_1 + 4) >> 8 | *(ushort *)(param_1 + 4) << 8;
      *param_8 = (uint)uVar4;
      uVar5 = uVar4 - 1;
      puVar6 = (ushort *)(ulonglong)uVar5;
      if (uVar5 <= (uint)lVar8) {
        puVar6 = (ushort *)0x3fd;
        uVar4 = *(ushort *)(param_1 + 6) >> 8 | *(ushort *)(param_1 + 6) << 8;
        if (uVar4 < 0x3fe) {
          uVar12 = param_2 - 8;
          uVar5 = 0;
          puVar7 = (undefined1 *)(param_7 + 8);
          do {
            *(uint *)(puVar7 + -8) = uVar5;
            uVar5 = uVar5 + 1;
            *(undefined4 *)(puVar7 + -4) = 4;
            *puVar7 = 0;
            puVar7 = puVar7 + 0x78;
            pcVar17 = param_1 + lVar8;
          } while (uVar5 < 5);
LAB_14001840f:
          pcVar16 = pcVar17;
          iVar13 = 3;
          puVar6 = (ushort *)0xfff;
          if (uVar4 == 0) goto LAB_140018708;
          if ((((uVar12 == 0) || (uVar12 < 4)) ||
              (uVar9 = *(ushort *)(pcVar16 + 2) >> 8 | (*(ushort *)(pcVar16 + 2) & 0xf) << 8,
              uVar9 < 4)) || (uVar12 < uVar9)) goto LAB_140018718;
          puVar6 = (ushort *)(ulonglong)uVar12;
          if (puVar6 < (ushort *)((ulonglong)uVar9 - 4)) goto LAB_140018718;
          bVar1 = pcVar16[1];
          uVar4 = uVar4 - 1;
          uVar12 = uVar12 - uVar9;
          pcVar17 = pcVar16 + uVar9;
          uVar10 = uVar9 - 4;
          if ((byte)(bVar1 - 1) < 4) {
            if (*(int *)((ulonglong)bVar1 * 0x78 + 4 + param_7) == 3) {
              iVar13 = 1;
              goto LAB_140018651;
            }
            if (bVar1 == 1) {
              if (uVar10 != 2) goto LAB_140018651;
              *(uint *)(param_7 + 0x84) =
                   (uint)(ushort)(*(ushort *)(pcVar16 + 4) >> 8 | *(ushort *)(pcVar16 + 4) << 8);
              *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + 4 + param_7) = 3;
              *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + param_7) = 1;
              goto LAB_14001840f;
            }
            if (bVar1 == 2) {
              puVar6 = (ushort *)0x0;
              if (0x40 < (ushort)(uVar9 - 0xc)) goto LAB_140018718;
              if ((byte)(pcVar16[7] - 1U) < 4) {
                lVar8 = (ulonglong)(byte)pcVar16[7] * 0x78;
                if (*(char *)(lVar8 + 8 + param_7) == '\0') {
                  *(undefined1 *)(lVar8 + 8 + param_7) = 1;
                  *(char *)((ulonglong)(byte)pcVar16[7] * 0x78 + 0x70 + param_7) = pcVar16[7];
                  uVar5 = *(uint *)(pcVar16 + 8);
                  *(uint *)((ulonglong)(byte)pcVar16[7] * 0x78 + 0x74 + param_7) =
                       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |
                       uVar5 << 0x18;
                  if (*(int *)((ulonglong)(byte)pcVar16[7] * 0x78 + 0x74 + param_7) != 0) {
                    *puVar14 = 1;
                  }
                }
              }
              else {
                *puVar14 = 1;
              }
              goto LAB_14001840f;
            }
            if (bVar1 != 3) {
              if (bVar1 == 4) {
                if (uVar10 != 0x24) goto LAB_140018651;
                uVar3 = *(undefined8 *)(pcVar16 + 0xc);
                *(undefined8 *)(param_7 + 0x1ec) = *(undefined8 *)(pcVar16 + 4);
                *(undefined8 *)(param_7 + 500) = uVar3;
                uVar3 = *(undefined8 *)(pcVar16 + 0x1c);
                *(undefined8 *)(param_7 + 0x1fc) = *(undefined8 *)(pcVar16 + 0x14);
                *(undefined8 *)(param_7 + 0x204) = uVar3;
                *(undefined4 *)(param_7 + 0x20c) = *(undefined4 *)(pcVar16 + 0x24);
                *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + 4 + param_7) = 3;
                *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + param_7) = 4;
              }
              goto LAB_14001840f;
            }
            if (uVar10 == 100) {
              uVar3 = *(undefined8 *)(pcVar16 + 0xc);
              *(undefined8 *)(param_7 + 0x174) = *(undefined8 *)(pcVar16 + 4);
              *(undefined8 *)(param_7 + 0x17c) = uVar3;
              uVar3 = *(undefined8 *)(pcVar16 + 0x1c);
              *(undefined8 *)(param_7 + 0x184) = *(undefined8 *)(pcVar16 + 0x14);
              *(undefined8 *)(param_7 + 0x18c) = uVar3;
              uVar3 = *(undefined8 *)(pcVar16 + 0x2c);
              *(undefined8 *)(param_7 + 0x194) = *(undefined8 *)(pcVar16 + 0x24);
              *(undefined8 *)(param_7 + 0x19c) = uVar3;
              uVar3 = *(undefined8 *)(pcVar16 + 0x3c);
              *(undefined8 *)(param_7 + 0x1a4) = *(undefined8 *)(pcVar16 + 0x34);
              *(undefined8 *)(param_7 + 0x1ac) = uVar3;
              uVar3 = *(undefined8 *)(pcVar16 + 0x4c);
              *(undefined8 *)(param_7 + 0x1b4) = *(undefined8 *)(pcVar16 + 0x44);
              *(undefined8 *)(param_7 + 0x1bc) = uVar3;
              uVar3 = *(undefined8 *)(pcVar16 + 0x5c);
              *(undefined8 *)(param_7 + 0x1c4) = *(undefined8 *)(pcVar16 + 0x54);
              *(undefined8 *)(param_7 + 0x1cc) = uVar3;
              *(undefined4 *)(param_7 + 0x1d4) = *(undefined4 *)(pcVar16 + 100);
              *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + 4 + param_7) = 3;
              *(undefined4 *)((ulonglong)(byte)pcVar16[1] * 0x78 + param_7) = 3;
              goto LAB_14001840f;
            }
          }
          else {
            iVar13 = 2;
          }
LAB_140018651:
          sVar2 = -uVar15;
          if (0xb < (ushort)(sVar2 + 0xfffU)) {
            puVar18 = (undefined2 *)((ulonglong)uVar15 + param_3);
            uVar15 = uVar15 + 0xc;
            *puVar18 = 0x200;
            puVar18[2] = 0;
            *(undefined1 *)(puVar18 + 3) = 0;
            *(char *)((longlong)puVar18 + 7) = pcVar16[1];
            *(int *)(puVar18 + 4) = iVar13 << 0x18;
            *param_6 = *param_6 + 1;
            uVar9 = 0x40;
            if (uVar10 < 0x40) {
              uVar9 = uVar10;
            }
            if ((ushort)(sVar2 + 0xff3U) < uVar9) {
              uVar9 = 0;
            }
            else if (uVar9 != 0) {
              memmove(puVar18 + 6,pcVar16 + 4,(ulonglong)uVar9);
              uVar15 = uVar15 + uVar9;
              puVar14 = param_10;
            }
            puVar18[1] = (ushort)(uVar9 + 0xc) >> 8 | (uVar9 + 0xc) * 0x100;
          }
          *param_9 = 1;
          goto LAB_14001840f;
        }
      }
    }
  }
LAB_140018718:
  uVar11 = 0;
  param_5 = puVar6;
LAB_14001871b:
  return CONCAT71((int7)((ulonglong)param_5 >> 8),uVar11);
LAB_140018708:
  if (uVar12 == 0) {
    *param_5 = uVar15;
    goto LAB_14001871b;
  }
  goto LAB_140018718;
}



===== WTSExCallback @ 140018750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WTSExCallback(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x30);
  (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));
  NdisFreeMemory(param_1,0x38);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2);
  piVar1 = (int *)(lVar2 + 8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeReleaseSpinLock();
    KeSetEvent(lVar2 + 0x10,0,0);
  }
  else {
    KeReleaseSpinLock(lVar2,uVar3);
  }
  return;
}



===== WTSScheduleSafeWorkItem @ 1400187e0 =====

int WTSScheduleSafeWorkItem(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  if (*(char *)(param_1 + 0x28) == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = NdisAllocateMemoryWithTag(&local_res8,0x38,0x73745753);
    if (iVar2 == 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      local_res8[5] = param_3;
      local_res8[4] = param_2;
      local_res8[6] = param_1;
      *local_res8 = 0;
      local_res8[2] = WTSExCallback;
      local_res8[3] = local_res8;
      if (*(int *)(param_1 + 8) == 1) {
        KeClearEvent(param_1 + 0x10);
      }
      KeReleaseSpinLock(param_1,uVar1);
      ExQueueWorkItem(local_res8,0);
      return 0;
    }
  }
  KeReleaseSpinLock(param_1,uVar1);
  return iVar2;
}



===== TpiDispatchFastIoDeviceControl @ 1400188f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
TpiDispatchFastIoDeviceControl
          (longlong param_1,undefined8 param_2,int *param_3,ulonglong param_4,longlong param_5,
          int param_6,uint param_7,int *param_8)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 local_28;
  int *local_20;
  int *local_18;
  int *local_10;
  
  local_28 = 1;
  uVar7 = (uint)param_4;
  if (param_1 == *(longlong *)(SstpGlobals + 0x18)) {
    TpiNonSstpFastIoDeviceControl((longlong)param_3,uVar7,param_7,param_8);
  }
  else if (param_1 == *(longlong *)(SstpGlobals + 0x10)) {
    if (param_7 == 0x128026) {
      uVar5 = RetrieveSendPackets(param_8,param_3,param_3,param_5,param_6);
      local_28 = (undefined1)uVar5;
    }
    else if (param_7 == 0x128035) {
      local_20 = (int *)0x0;
      if (uVar7 == 0x4008) {
        ProbeForRead(param_3,param_4 & 0xffffffff,4);
        uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
        iVar3 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),*param_3,&local_20);
        if (iVar3 == 0) {
          LOCK();
          *local_20 = *local_20 + 1;
          UNLOCK();
          KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
          uVar1 = KeAcquireSpinLockRaiseToDpc(local_20 + 8);
          local_20[0x496] = local_20[0x496] | 0x10000;
          KeReleaseSpinLock(local_20 + 8,uVar1);
          uVar5 = DelineateSSTPFrame((uint *)(local_20 + 0x86),(longlong)local_20,param_3 + 2,
                                     param_4,(char *)(param_3 + 2),param_3[1]);
          iVar3 = (int)uVar5;
          bVar2 = KeAcquireSpinLockRaiseToDpc(local_20 + 8);
          local_20[0x496] = local_20[0x496] & 0xfffeffff;
          if (iVar3 < 0) {
            InitiateSstpContextCleanup(local_20,0,(undefined *)(ulonglong)bVar2);
          }
          else if ((char)local_20[0x497] == '\0') {
            KeReleaseSpinLock(local_20 + 8,bVar2);
          }
          else {
            InitiateSstpContextCleanup(local_20,4,(undefined *)(ulonglong)bVar2);
          }
          LOCK();
          iVar4 = *local_20;
          *local_20 = *local_20 + -1;
          UNLOCK();
          if (iVar4 == 1) {
            (**(code **)(local_20 + 2))();
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                          &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_20 + 0x79);
          }
          KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
        }
        *param_8 = iVar3;
        param_8[2] = 0;
        param_8[3] = 0;
        if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (WPP_GLOBAL_Control[0x29] != '\0')))
           ) {
          WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                         &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_20 + 0x79,
                         (char)iVar3);
        }
      }
    }
    else {
      if (param_7 == 0x128004) {
        if (3 < uVar7) {
          ProbeForRead(param_3,4,4);
          iVar3 = *param_3;
          uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1b8);
          if (*(int *)(SstpGlobals + 0x1c0) != 1) {
            KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
            return 1;
          }
          *param_8 = 0;
          uVar6 = 3;
          if (iVar3 != 0) {
            uVar6 = 0;
          }
          *(undefined4 *)(SstpGlobals + 0x1c0) = uVar6;
          KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
          NdisCmRegisterSapComplete
                    (-(uint)(iVar3 != 0) & 0xc0000001,*(undefined8 *)(SstpGlobals + 0x1c8),0);
          return 1;
        }
      }
      else {
        if (param_7 != 0x12800c) {
          if (param_7 != 0x128018) {
            if (param_7 != 0x128040) {
              return 0;
            }
            *param_8 = 0;
            if (uVar7 < 4) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
              }
              *param_8 = -0x3ffffff3;
              return 1;
            }
            local_10 = (int *)0x0;
            ProbeForRead(param_3,4,4);
            iVar3 = *param_3;
            uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
            iVar4 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),iVar3,&local_10);
            if (iVar4 < 0) {
              KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
              return 1;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_10 + 0x79);
            }
            LOCK();
            *local_10 = *local_10 + 1;
            UNLOCK();
            HfSuspendHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),iVar3);
            KeReleaseSpinLock(SstpGlobals + 0x1f0);
            bVar2 = KeAcquireSpinLockRaiseToDpc(local_10 + 8);
            InitiateSstpContextCleanup(local_10,0,(undefined *)(ulonglong)bVar2);
            DereferenceRefCount(local_10);
            return 1;
          }
          local_18 = (int *)0x0;
          if (uVar7 != 0x68) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
            }
            *param_8 = -0x3ffffff3;
            param_8[2] = 0x68;
            param_8[3] = 0;
            return 1;
          }
          ProbeForRead(param_3,0x68,8);
          iVar3 = param_3[6];
          if (iVar3 == 0) {
            return 0;
          }
          iVar4 = *param_3;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                    &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
          }
          *param_8 = 0;
          param_8[2] = 0;
          param_8[3] = 0;
          uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
          iVar4 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),iVar4,&local_18);
          if (iVar4 == 0) {
            LOCK();
            *local_18 = *local_18 + 1;
            UNLOCK();
            KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
            bVar2 = KeAcquireSpinLockRaiseToDpc(local_18 + 8);
            local_18[0x498] = iVar3;
            local_18[0x496] = local_18[0x496] & 0xffffdfff;
            InitiateSstpContextCleanup(local_18,0,(undefined *)(ulonglong)bVar2);
            DereferenceRefCount(local_18);
            return 1;
          }
          KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar1);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return 1;
          }
          if (WPP_GLOBAL_Control[0x29] == '\0') {
            return 1;
          }
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
                  &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
          return 1;
        }
        if (3 < uVar7) {
          ProbeForRead(param_3,4,4);
          iVar3 = *param_3;
          *param_8 = 0;
          uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1b8);
          if (*(int *)(SstpGlobals + 0x1c0) == 2) {
            *(undefined4 *)(SstpGlobals + 0x1c0) = 0;
            KeReleaseSpinLock(SstpGlobals + 0x1b8);
            NdisCmDeregisterSapComplete
                      (-(uint)(iVar3 != 0) & 0xc0000001,*(undefined8 *)(SstpGlobals + 0x1c8));
            return 1;
          }
          KeReleaseSpinLock(SstpGlobals + 0x1b8,uVar1);
          return 1;
        }
      }
      *param_8 = -0x3ffffff3;
      param_8[2] = 4;
      param_8[3] = 0;
    }
  }
  else {
    *param_8 = -0x3fffff45;
    param_8[2] = 0;
    param_8[3] = 0;
    local_28 = 1;
  }
  return local_28;
}



===== RetrieveSendPackets @ 140019210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
RetrieveSendPackets(int *param_1,undefined4 *param_2,undefined8 param_3,longlong param_4,int param_5
                   )

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  ulonglong uVar8;
  int **_Size;
  int *piVar9;
  void *_Src;
  undefined8 *puVar10;
  int **ppiVar11;
  undefined8 *puVar12;
  int iVar13;
  uint uVar14;
  int *local_48;
  ulonglong local_40;
  
  local_48 = (int *)0x0;
  uVar14 = 0;
  puVar12 = (undefined8 *)0x0;
  iVar13 = 0;
  ProbeForRead(param_2,4,4);
  ProbeForWrite(param_4,param_5,1);
  bVar5 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
  ppiVar11 = &local_48;
  iVar7 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),*param_2);
  _Src = (void *)(ulonglong)bVar5;
  if (iVar7 == 0) {
    LOCK();
    *local_48 = *local_48 + 1;
    UNLOCK();
    KeReleaseSpinLock(SstpGlobals + 0x1f0);
    bVar5 = KeAcquireSpinLockRaiseToDpc(local_48 + 8);
    while (puVar3 = *(undefined8 **)(local_48 + 0x18), puVar3 != (undefined8 *)0x0) {
      _Src = (void *)(ulonglong)bVar5;
      *(undefined8 *)(local_48 + 0x18) = *puVar3;
      KeReleaseSpinLock(local_48 + 8);
      if (*(char *)(puVar3 + 1) == '\0') {
        puVar10 = (undefined8 *)puVar3[2];
        local_40 = 0;
        while (puVar10 != (undefined8 *)0x0) {
          puVar3[2] = puVar10;
          uVar2 = *(uint *)(puVar10 + 3);
          if (uVar2 < 0xffc) {
            if (param_5 - uVar14 < uVar2 + 4) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                ppiVar11 = (int **)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
                _Src = (void *)0x43;
                WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_48 + 0x79);
              }
              goto LAB_140019455;
            }
            uVar8 = (ulonglong)uVar14;
            uVar6 = (short)uVar2 + 4;
            uVar14 = uVar14 + 4;
            *(undefined2 *)(uVar8 + param_4) = 0x10;
            ((undefined2 *)(uVar8 + param_4))[1] = uVar6 >> 8 | uVar6 * 0x100;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_48 + 0x79);
            }
            _Src = (void *)(ulonglong)*(uint *)(puVar10 + 2);
            ppiVar11 = (int **)((ulonglong)uVar14 + param_4);
            RtlCopyMdlToBuffer(puVar10[1],_Src,ppiVar11,(ulonglong)uVar2,&local_40);
            if (uVar2 == local_40) {
              uVar14 = uVar14 + (int)local_40;
            }
            puVar10 = (undefined8 *)*puVar10;
          }
          else {
            puVar10 = (undefined8 *)*puVar10;
          }
        }
        iVar13 = iVar13 + 1;
        *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
        if (puVar12 != (undefined8 *)0x0) {
          puVar3[-0xc] = puVar12;
        }
        puVar12 = puVar3 + -0xc;
        _Size = ppiVar11;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          ppiVar11 = (int **)&WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
          _Src = (void *)0x41;
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_48 + 0x79);
        }
        _Size = (int **)(ulonglong)*(ushort *)(puVar3 + 2);
        if (param_5 - uVar14 < (uint)*(ushort *)(puVar3 + 2)) {
LAB_140019455:
          bVar5 = KeAcquireSpinLockRaiseToDpc(local_48 + 8);
          *puVar3 = *(undefined8 *)(local_48 + 0x18);
          *(undefined8 **)(local_48 + 0x18) = puVar3;
          break;
        }
        _Src = (void *)((longlong)puVar3 + 0x12);
        memmove((void *)((ulonglong)uVar14 + param_4),_Src,(size_t)_Size);
        uVar14 = uVar14 + *(ushort *)(puVar3 + 2);
        (**(code **)(SstpGlobals + 0x220))(puVar3);
      }
      bVar5 = KeAcquireSpinLockRaiseToDpc(local_48 + 8);
      ppiVar11 = _Size;
    }
    if (*(longlong *)(local_48 + 0x18) == 0) {
      *(undefined1 *)(local_48 + 0x16) = 0;
      local_48[0x1a] = 0;
      local_48[0x1b] = 0;
    }
    else {
      *(undefined1 *)(local_48 + 0x16) = 1;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),_Src,ppiVar11,local_48 + 0x79,
                     (char)local_48[0x16]);
    }
    KeReleaseSpinLock(local_48 + 8,bVar5);
    if (puVar12 != (undefined8 *)0x0) {
      NdisMCoSendNetBufferListsComplete(*(undefined8 *)(local_48 + 10),puVar12,0);
    }
    LOCK();
    iVar1 = *local_48;
    *local_48 = *local_48 + -1;
    UNLOCK();
    lVar4 = SstpGlobals;
    if (iVar1 == 1) {
      (**(code **)(local_48 + 2))();
      lVar4 = SstpGlobals;
    }
    for (; SstpGlobals = lVar4, iVar13 != 0; iVar13 = iVar13 + -1) {
      piVar9 = (int *)(lVar4 + 0x90);
      LOCK();
      iVar1 = *piVar9;
      *piVar9 = *piVar9 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        (**(code **)(lVar4 + 0x98))();
      }
      lVar4 = SstpGlobals;
    }
  }
  else {
    KeReleaseSpinLock(SstpGlobals + 0x1f0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
  }
  *param_1 = iVar7;
  *(ulonglong *)(param_1 + 2) = (ulonglong)uVar14;
  return CONCAT71((uint7)(uint3)(uVar14 >> 8),1);
}



===== TpiNonSstpFastIoDeviceControl @ 140019710 =====

void TpiNonSstpFastIoDeviceControl(longlong param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  int *piVar7;
  undefined *puVar8;
  longlong lVar9;
  longlong lVar10;
  bool bVar11;
  undefined8 local_68;
  code *local_60;
  code *pcStack_58;
  ulonglong local_50;
  longlong lStack_48;
  
  bVar11 = false;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  lVar9 = param_1;
  if (param_3 != 0x128018) {
    lVar9 = 0;
  }
  lVar10 = param_1;
  if (param_3 != 0x128040) {
    lVar10 = 0;
  }
  local_68 = 0;
  if (lVar9 == 0) {
    if (lVar10 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                 &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_3);
      }
      *param_4 = 0xc00000bb;
      *(ulonglong *)(param_4 + 2) = (ulonglong)param_3;
      goto LAB_140019ce4;
    }
LAB_1400197fd:
    if ((lVar10 == 0) || (param_2 == 0x10)) {
      if (lVar9 == 0) {
        puVar8 = (undefined *)0x4;
        ProbeForRead(param_1);
      }
      else {
        puVar8 = (undefined *)0x8;
        ProbeForRead(param_1,0x1030);
        if (0x1000 < *(uint *)(lVar9 + 0x28)) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                     &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,*(uint *)(lVar9 + 0x28));
          }
          *param_4 = 0xc000000d;
          *(undefined8 *)(param_4 + 2) = 0x1000;
          goto LAB_140019ce4;
        }
        lVar10 = lVar9;
      }
      uVar2 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
      for (puVar4 = *(undefined8 **)(SstpGlobals + 0x1e0); piVar7 = (int *)0x0,
          puVar4 != (undefined8 *)(SstpGlobals + 0x1e0); puVar4 = (undefined8 *)*puVar4) {
        piVar7 = (int *)(puVar4 + -2);
        if ((puVar4[0x24d] != 0) && (*(char *)((longlong)puVar4 + 0x1274) != '\0')) {
          puVar8 = (undefined *)0x10;
          lVar5 = RtlCompareMemory(lVar10,(longlong)puVar4 + 0x1d4);
          if (lVar5 == 0x10) {
            LOCK();
            *piVar7 = *piVar7 + 1;
            UNLOCK();
            break;
          }
        }
      }
      KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar2);
      if (piVar7 == (int *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')
           ) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,lVar10);
        }
        *param_4 = 0xc0000008;
        *(undefined8 *)(param_4 + 2) = 0;
      }
      else {
        *param_4 = 0;
        *(undefined8 *)(param_4 + 2) = 0;
        if (lVar9 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                          &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,lVar10);
          }
          uVar2 = KeAcquireSpinLockRaiseToDpc(piVar7 + 8);
          bVar11 = ((uint)piVar7[0x496] >> 9 & 1) == 0;
          if (bVar11) {
            piVar7[0x496] = piVar7[0x496] & 0xfffffffb;
            KeReleaseSpinLock(piVar7 + 8,uVar2);
          }
          else {
            KeReleaseSpinLock();
          }
          TpiFsmDisconnectComplete(piVar7,bVar11,(undefined *)0x0);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar8 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
            WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                           &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,lVar10,
                           (char)*(undefined4 *)(lVar9 + 0x10));
          }
          uVar6 = 0;
          if (*(int *)(lVar9 + 0x10) == 0) {
            uVar2 = KeAcquireSpinLockRaiseToDpc(piVar7 + 8);
            uVar6 = *(undefined8 *)(piVar7 + 10);
            bVar11 = *(char *)((longlong)piVar7 + 0x1fb) == '\0';
            if (bVar11) {
              pcStack_58 = DPSendCompleteCallback;
              local_60 = DPReceiveCallback;
              local_50 = (ulonglong)*(uint *)(lVar9 + 0x28);
              lStack_48 = lVar9 + 0x2c;
              KeReleaseSpinLock(piVar7 + 8,uVar2);
              uVar3 = DPChannelCreate0(&local_60,&local_68);
              *(undefined4 *)(lVar9 + 0x10) = uVar3;
            }
            bVar11 = !bVar11;
            uVar1 = *(uint *)(lVar9 + 0x10);
            puVar8 = (undefined *)(ulonglong)uVar1;
            if ((int)uVar1 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                puVar8 = &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids;
                WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
                               &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,lVar10,(char)uVar1);
              }
              *param_4 = *(undefined4 *)(lVar9 + 0x10);
            }
            else {
              if (!bVar11) {
                uVar2 = KeAcquireSpinLockRaiseToDpc(piVar7 + 8);
                *(undefined8 *)(piVar7 + 0x4a2) = local_68;
              }
              piVar7[0x4a0] = *(int *)(lVar9 + 0x14);
              *(undefined8 *)(piVar7 + 0x49a) = *(undefined8 *)(lVar9 + 0x18);
              *(undefined8 *)(piVar7 + 0x49c) = *(undefined8 *)(lVar9 + 0x20);
              KeReleaseSpinLock(piVar7 + 8,uVar2);
            }
          }
          if (bVar11) {
            TpiFsmIndicateLinkParamChange
                      (uVar6,*(undefined4 *)(lVar9 + 0x14),*(ulonglong *)(lVar9 + 0x18),
                       *(ulonglong *)(lVar9 + 0x20));
          }
          else {
            TpiFsmNewCallComplete(piVar7,*(int *)(lVar9 + 0x10),puVar8);
            if (*(int *)(lVar9 + 0x10) == 0) {
              TpiFsmCryptoBindingComplete(piVar7);
            }
          }
        }
        DereferenceRefCount(piVar7);
      }
      goto LAB_140019ce4;
    }
  }
  else if (param_2 == 0x1030) goto LAB_1400197fd;
  uVar6 = 0x1030;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
             &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_2);
  }
  *param_4 = 0xc000000d;
  if (lVar9 == 0) {
    uVar6 = 0x10;
  }
  *(undefined8 *)(param_4 + 2) = uVar6;
LAB_140019ce4:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (((byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) & 0x81) == 0x81)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
  }
  return;
}



===== SmpCoSendNetBufferListChain @ 140019d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmpCoSendNetBufferListChain(int *param_1,undefined8 *param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  int *piVar6;
  longlong lVar7;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 200);
  if ((*(int *)(SstpGlobals + 0xa0) == 2) && (*(char *)((longlong)param_1 + 0x1fb) != '\0')) {
    LOCK();
    *(int *)(SstpGlobals + 0x90) = *(int *)(SstpGlobals + 0x90) + 1;
    UNLOCK();
    KeReleaseSpinLock(SstpGlobals + 200,uVar5);
    if ((char)param_1[0x4a1] == '\0') {
      while (param_2 != (undefined8 *)0x0) {
        lVar7 = 0;
        puVar3 = (undefined8 *)*param_2;
        *param_2 = 0;
        puVar4 = param_2 + 0xc;
        *(undefined1 *)(param_2 + 0xd) = 0;
        *puVar4 = 0;
        param_2[0xe] = param_2[1];
        LOCK();
        *(int *)(SstpGlobals + 0x90) = *(int *)(SstpGlobals + 0x90) + 1;
        UNLOCK();
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
        if (*(longlong *)(param_1 + 0x18) == 0) {
          *(undefined8 **)(param_1 + 0x18) = puVar4;
          if (*(longlong *)(param_1 + 0x14) == 0) {
            *(undefined1 *)(param_1 + 0x16) = 1;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
            }
            lVar7 = *(longlong *)(param_1 + 0x14);
            param_1[0x14] = 0;
            param_1[0x15] = 0;
            LOCK();
            lVar2 = *(longlong *)(lVar7 + 0x68);
            *(longlong *)(lVar7 + 0x68) = 0;
            UNLOCK();
            if (lVar2 == 0) {
              *(undefined1 *)(param_1 + 0x16) = 1;
              lVar7 = 0;
            }
            else {
              LOCK();
              iVar1 = *param_1;
              *param_1 = *param_1 + -1;
              UNLOCK();
              if (iVar1 == 1) {
                (**(code **)(param_1 + 2))(param_1);
              }
            }
          }
          *(undefined8 **)(param_1 + 0x1a) = puVar4;
          KeReleaseSpinLock(param_1 + 8,uVar5);
          param_2 = puVar3;
          if (lVar7 != 0) {
            *(undefined4 *)(lVar7 + 0x30) = 0;
            *(undefined8 *)(lVar7 + 0x38) = 0;
            IofCompleteRequest(lVar7,2);
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                          &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
          }
          if (*(char *)(param_2 + 0xd) == '\0') {
            **(undefined8 **)(param_1 + 0x1a) = puVar4;
            *(undefined8 **)(param_1 + 0x1a) = puVar4;
          }
          else {
            *puVar4 = *(undefined8 *)(param_1 + 0x18);
            *(undefined8 **)(param_1 + 0x18) = puVar4;
          }
          KeReleaseSpinLock(param_1 + 8,uVar5);
          param_2 = puVar3;
        }
      }
    }
    else {
      DPSendNetBufferList0(*(undefined8 *)(param_1 + 0x4a2),param_2);
    }
    lVar7 = SstpGlobals;
    piVar6 = (int *)(SstpGlobals + 0x90);
    LOCK();
    iVar1 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      (**(code **)(lVar7 + 0x98))();
    }
  }
  else {
    KeReleaseSpinLock(SstpGlobals + 200,uVar5);
    puVar4 = param_2;
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        param_3 = &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_9e10efe45ec1381d72e9dbd2310f4771_Traceguids,0xc0000001);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                  (ulonglong)*(uint *)(SstpGlobals + 0xa0),param_3,
                  (uint)*(byte *)((longlong)param_1 + 0x1fb),(char)*(uint *)(SstpGlobals + 0xa0));
      }
    }
    for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
      *(undefined4 *)((longlong)puVar4 + 0x8c) = 0xc0000001;
    }
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_1 + 10),param_2,0);
  }
  return;
}



===== DelinProcessSstpDataFrame @ 14001a0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DelinProcessSstpDataFrame
               (void *param_1,uint param_2,longlong param_3,longlong param_4,char param_5,
               char param_6)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (*(char *)(param_4 + 0x214) != '\0') {
    if (param_6 == '\0') {
      return;
    }
    *(undefined1 *)(param_4 + 0x214) = 0;
    return;
  }
  if (*(longlong *)(param_4 + 0x200) == 0) {
    lVar2 = NdisAllocateNetBufferList(*(undefined8 *)(SstpGlobals + 0x240),0,0);
    *(longlong *)(param_4 + 0x200) = lVar2;
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_4 + 0x1e4);
      }
      if (param_5 != '\0') {
        *(undefined1 *)(param_4 + 0x214) = 1;
      }
    }
    else {
      uVar4 = (ushort)(*(ushort *)(param_3 + 2) >> 8 | *(ushort *)(param_3 + 2) << 8) & 0xfff;
      uVar5 = 0;
      NdisRetreatNetBufferListDataStart(lVar2,uVar4 - 4,0,0,0);
      uVar3 = NdisGetDataBuffer(*(undefined8 *)(*(longlong *)(param_4 + 0x200) + 8),uVar4 - 4,0,1,
                                uVar5 & 0xffffffff00000000);
      *(undefined8 *)(param_4 + 0x208) = uVar3;
      *(undefined4 *)(param_4 + 0x210) = 0;
    }
  }
  if (*(longlong *)(param_4 + 0x200) == 0) {
    return;
  }
  if (0xfff < *(int *)(param_4 + 0x210) + param_2) {
    NdisFreeNetBufferList();
    *(undefined8 *)(param_4 + 0x200) = 0;
    *(undefined8 *)(param_4 + 0x208) = 0;
    if (param_6 != '\0') {
      return;
    }
    if (param_5 == '\0') {
      return;
    }
    *(undefined1 *)(param_4 + 0x214) = 1;
    return;
  }
  memmove(*(void **)(param_4 + 0x208),param_1,(ulonglong)param_2);
  *(longlong *)(param_4 + 0x208) = *(longlong *)(param_4 + 0x208) + (ulonglong)param_2;
  *(int *)(param_4 + 0x210) = *(int *)(param_4 + 0x210) + param_2;
  if ((param_5 != '\0') && (param_6 == '\0')) {
    return;
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 200);
  if ((*(char *)(param_4 + 0x1fb) == '\0') || (*(int *)(SstpGlobals + 0xa0) != 2)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF__guid_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_4 + 0x1e4,
                      *(char *)(param_4 + 0x1fb),(char)*(undefined4 *)(SstpGlobals + 0xa0));
    }
    lVar2 = SstpGlobals + 200;
  }
  else {
    LOCK();
    *(int *)(SstpGlobals + 0x90) = *(int *)(SstpGlobals + 0x90) + 1;
    UNLOCK();
    KeReleaseSpinLock(SstpGlobals + 200,uVar1);
    (**(code **)(SstpGlobals + 0x228))(param_4);
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_4 + 0x20);
    if ((*(uint *)(param_4 + 0x1258) & 0x10) != 0) {
      *(int *)(param_4 + 0x30) = *(int *)(param_4 + 0x30) + 1;
      *(longlong *)(*(longlong *)(param_4 + 0x200) + 0x60) = param_4;
      *(undefined8 *)(*(longlong *)(param_4 + 0x200) + 0x78) = *(undefined8 *)(param_4 + 0x28);
      *(undefined8 *)(*(longlong *)(param_4 + 0x200) + 0x70) = 0;
      KeReleaseSpinLock(param_4 + 0x20,uVar1);
      NdisMCoIndicateReceiveNetBufferLists
                (*(undefined8 *)(param_4 + 0x28),*(undefined8 *)(param_4 + 0x200),1);
      goto LAB_14001a308;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF__guid_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_4 + 0x1e4,
                      *(undefined1 *)(param_4 + 0x1fb),(char)*(undefined4 *)(SstpGlobals + 0xa0));
    }
    lVar2 = param_4 + 0x20;
  }
  KeReleaseSpinLock(lVar2,uVar1);
  NdisFreeNetBufferList(*(undefined8 *)(param_4 + 0x200));
LAB_14001a308:
  *(undefined8 *)(param_4 + 0x200) = 0;
  *(undefined8 *)(param_4 + 0x208) = 0;
  return;
}



===== SmpReturnNetBufferListChain @ 14001a4d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmpReturnNetBufferListChain(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  longlong lVar4;
  byte bVar5;
  int *piVar6;
  
  if (param_2 != (undefined8 *)0x0) {
    do {
      puVar2 = (undefined8 *)*param_2;
      *param_2 = 0;
      if (param_2[0xe] == 0) {
        piVar3 = (int *)param_2[0xc];
        bVar5 = KeAcquireSpinLockRaiseToDpc(piVar3 + 8);
        piVar6 = piVar3 + 0xc;
        *piVar6 = *piVar6 + -1;
        if ((*piVar6 == 0) && ((char)piVar3[0x497] == '\x01')) {
          InitiateSstpContextCleanup(piVar3,4,(undefined *)(ulonglong)bVar5);
        }
        else {
          KeReleaseSpinLock(piVar3 + 8,bVar5);
        }
        NdisFreeNetBufferList(param_2);
      }
      else {
        DPReceiveNetBufferListComplete0(param_2[0xe],param_2);
      }
      lVar4 = SstpGlobals;
      piVar6 = (int *)(SstpGlobals + 0x90);
      LOCK();
      iVar1 = *piVar6;
      *piVar6 = *piVar6 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        (**(code **)(lVar4 + 0x98))();
      }
      param_2 = puVar2;
    } while (puVar2 != (undefined8 *)0x0);
  }
  return;
}



===== DPReceiveCallback @ 14001a5d0 =====

void DPReceiveCallback(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
  for (puVar1 = *(undefined8 **)(SstpGlobals + 0x1e0);
      (puVar3 = (undefined8 *)0x0, puVar1 != (undefined8 *)(SstpGlobals + 0x1e0) &&
      ((puVar3 = puVar1 + -2, *(char *)((longlong)puVar1 + 0x1274) == '\0' ||
       (param_1 != puVar1[0x24f])))); puVar1 = (undefined8 *)*puVar1) {
  }
  KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar2);
  if (puVar3 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
               &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1);
    }
    DPReceiveNetBufferListComplete0(param_1,param_2);
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 200);
    puVar1 = param_2;
    if (*(int *)(SstpGlobals + 0xa0) == 2) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        LOCK();
        *(int *)(SstpGlobals + 0x90) = *(int *)(SstpGlobals + 0x90) + 1;
        UNLOCK();
        iVar4 = iVar4 + 1;
        puVar1[0xf] = puVar3[5];
        puVar1[0xe] = param_1;
      }
      KeReleaseSpinLock(SstpGlobals + 200,uVar2);
      NdisMCoIndicateReceiveNetBufferLists(puVar3[5],param_2,iVar4,0);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0'))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                 &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,*(int *)(SstpGlobals + 0xa0));
      }
      KeReleaseSpinLock(SstpGlobals + 200,uVar2);
      DPReceiveNetBufferListComplete0(param_1,param_2);
    }
  }
  return;
}



===== DPSendCompleteCallback @ 14001a800 =====

void DPSendCompleteCallback(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1d8);
  for (puVar1 = *(undefined8 **)(SstpGlobals + 0x1e0);
      (puVar3 = (undefined8 *)0x0, puVar1 != (undefined8 *)(SstpGlobals + 0x1e0) &&
      ((puVar3 = puVar1 + -2, *(char *)((longlong)puVar1 + 0x1274) == '\0' ||
       (param_1 != puVar1[0x24f])))); puVar1 = (undefined8 *)*puVar1) {
  }
  KeReleaseSpinLock(SstpGlobals + 0x1d8,uVar2);
  if (puVar3 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
               &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1);
    }
  }
  else {
    NdisMCoSendNetBufferListsComplete(puVar3[5],param_2,0);
  }
  return;
}



===== QueuePacketForSend @ 14001a900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QueuePacketForSend(int *param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  
  lVar4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  if (*(longlong *)(param_1 + 0x18) == 0) {
    *(undefined8 **)(param_1 + 0x18) = param_2;
    if (*(longlong *)(param_1 + 0x14) == 0) {
      *(undefined1 *)(param_1 + 0x16) = 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
      }
      lVar4 = *(longlong *)(param_1 + 0x14);
      param_1[0x14] = 0;
      param_1[0x15] = 0;
      LOCK();
      lVar2 = *(longlong *)(lVar4 + 0x68);
      *(longlong *)(lVar4 + 0x68) = 0;
      UNLOCK();
      if (lVar2 == 0) {
        *(undefined1 *)(param_1 + 0x16) = 1;
        lVar4 = 0;
      }
      else {
        LOCK();
        iVar1 = *param_1;
        *param_1 = *param_1 + -1;
        UNLOCK();
        if (iVar1 == 1) {
          (**(code **)(param_1 + 2))(param_1);
        }
      }
    }
    *(undefined8 **)(param_1 + 0x1a) = param_2;
    KeReleaseSpinLock(param_1 + 8,uVar3);
    if (lVar4 != 0) {
      *(undefined4 *)(lVar4 + 0x30) = 0;
      *(undefined8 *)(lVar4 + 0x38) = 0;
      IofCompleteRequest(lVar4,2);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                    &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1 + 0x79);
    }
    if (*(char *)(param_2 + 1) == '\0') {
      **(undefined8 **)(param_1 + 0x1a) = param_2;
      *(undefined8 **)(param_1 + 0x1a) = param_2;
    }
    else {
      *param_2 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 **)(param_1 + 0x18) = param_2;
    }
    KeReleaseSpinLock(param_1 + 8,uVar3);
  }
  return;
}



===== SstpValidateSstpHeader @ 14001ab10 =====

ulonglong SstpValidateSstpHeader(char *param_1,char param_2)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  uVar1 = in_RAX & 0xffffffffffffff00;
  if (*param_1 == '\x10') {
    if ((param_1[1] & 1U) == 0) {
      if (param_2 != '\0') {
        return uVar1;
      }
    }
    else if (param_2 == '\0') {
      return uVar1;
    }
    uVar1 = 0;
    if (4 < (ushort)(*(ushort *)(param_1 + 2) >> 8 | (*(ushort *)(param_1 + 2) & 0xf) << 8)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



===== ProcessQueueForSendNotification @ 14001ab60 =====

int ProcessQueueForSendNotification(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  int *local_res8;
  
  local_res8 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
             &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,param_1);
  }
  if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x10) != 4) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
              &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids);
    }
    return -0x3ffffff3;
  }
  uVar3 = **(undefined4 **)(param_1 + 0x18);
  uVar4 = KeAcquireSpinLockRaiseToDpc(SstpGlobals + 0x1f0);
  iVar5 = HfGetPointerFromHandle32(*(undefined8 *)(SstpGlobals + 0x1f8),uVar3,&local_res8);
  if (iVar5 == 0) {
    LOCK();
    *local_res8 = *local_res8 + 1;
    UNLOCK();
    KeReleaseSpinLock(SstpGlobals + 0x1f0);
    uVar4 = KeAcquireSpinLockRaiseToDpc(local_res8 + 8);
    if (((char)local_res8[0x497] == '\0') && (local_res8[0x496] != 0)) {
      if ((char)local_res8[0x16] == '\0') {
        *(longlong *)(local_res8 + 0x14) = param_1;
        *(int **)(param_1 + 0x78) = local_res8;
        LOCK();
        *(code **)(param_1 + 0x68) = SendNotificationCancelIrp;
        UNLOCK();
        if (*(char *)(param_1 + 0x44) == '\0') {
          pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
        }
        else {
          LOCK();
          lVar2 = *(longlong *)(param_1 + 0x68);
          *(longlong *)(param_1 + 0x68) = 0;
          UNLOCK();
          if (lVar2 != 0) {
            local_res8[0x14] = 0;
            local_res8[0x15] = 0;
            KeReleaseSpinLock(local_res8 + 8,uVar4);
            DereferenceRefCount(local_res8);
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                            &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res8 + 0x79);
            }
            return -0x3ffffee0;
          }
        }
        iVar5 = 0x103;
        KeReleaseSpinLock(local_res8 + 8,uVar4);
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                        &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res8 + 0x79);
        }
        KeReleaseSpinLock(local_res8 + 8,uVar4);
        DereferenceRefCount(local_res8);
        iVar5 = 0;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (WPP_GLOBAL_Control[0x29] != '\0'))))
      {
        WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                      &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,local_res8 + 0x79);
      }
      KeReleaseSpinLock(local_res8 + 8,uVar4);
      DereferenceRefCount(local_res8);
      iVar5 = -0x3ffffddb;
    }
  }
  else {
    KeReleaseSpinLock(SstpGlobals + 0x1f0,uVar4);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
               &WPP_0530794af2d8397ceceb47931401a9a3_Traceguids,iVar5);
    }
  }
  return iVar5;
}



===== SetCancelRoutineSafe @ 14001aef0 =====

ulonglong SetCancelRoutineSafe(longlong param_1,undefined8 param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  
  LOCK();
  *(undefined8 *)(param_1 + 0x68) = param_2;
  UNLOCK();
  if (*(char *)(param_1 + 0x44) == '\0') {
    lVar2 = *(longlong *)(param_1 + 0xb8);
    *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
  }
  else {
    LOCK();
    uVar1 = *(ulonglong *)(param_1 + 0x68);
    *(ulonglong *)(param_1 + 0x68) = 0;
    UNLOCK();
    lVar2 = 0;
    if (uVar1 != 0) {
      return uVar1 & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
}



===== RemoveCancelRoutineSafe @ 14001af20 =====

ulonglong RemoveCancelRoutineSafe(longlong param_1)

{
  longlong lVar1;
  undefined8 in_RAX;
  ulonglong uVar2;
  
  LOCK();
  lVar1 = *(longlong *)(param_1 + 0x68);
  *(longlong *)(param_1 + 0x68) = 0;
  UNLOCK();
  uVar2 = CONCAT71((int7)((ulonglong)in_RAX >> 8),1) & 0xffffffff;
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}



===== FsmTpiSetDataReceivedStatus @ 14001af40 =====

void FsmTpiSetDataReceivedStatus(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x1b8) = 1;
  return;
}



===== entry @ 14001b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001b044 =====

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
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== wil_InitializeFeatureStaging @ 14001b078 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001b168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


