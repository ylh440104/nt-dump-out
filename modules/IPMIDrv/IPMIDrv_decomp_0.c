
===== _tlgKeywordOn @ 140001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(undefined8 param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if (((_DAT_140014098 & param_2) == 0) ||
     (in_RAX = DAT_1400140a0 & param_2, in_RAX != DAT_1400140a0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001034 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_140014090;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140014090;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1400140a8,&local_18,0,0,param_5,param_6);
  return;
}



===== _tlgCreate1Sz_char @ 1400010e4 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== WaitForEventOrTimeout @ 140001120 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WaitForEventOrTimeout(longlong param_1,ulonglong param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  int iStackX_14;
  undefined *local_28;
  undefined *local_20;
  
  local_28 = &DAT_14002aa00;
  uVar6 = 0;
  local_20 = &DAT_14002a960;
  uVar1 = KeQueryTimeIncrement();
  iStackX_14 = (int)(param_2 >> 0x20);
  lVar3 = (((longlong)iStackX_14 - (longlong)(int)(_DAT_fffff78000000320 >> 0x20) << 0x20) -
          (_DAT_fffff78000000320 & 0xffffffff)) + (param_2 & 0xffffffff);
  if (lVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000b5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc00000b5;
    }
    uVar4 = 10;
  }
  else {
    uVar7 = (ulonglong)uVar1 * lVar3;
    uVar5 = (ulonglong)(uint)(*(int *)(param_1 + 0x4c) * 10);
    if ((longlong)uVar7 <= (longlong)uVar5) {
      uVar5 = uVar7;
    }
    if ((int)((longlong)uVar5 / 10000) != 0) {
      KeInitializeTimerEx(&DAT_14002a960,1);
      KeSetTimerEx(&DAT_14002a960,0xffffffffffffffff,(longlong)uVar5 / 10000 & 0xffffffff,0);
      do {
        iVar2 = KeWaitForMultipleObjects(2,&local_28,1,0,0,0,0,0);
        if (iVar2 == 0) {
          KeClearEvent(&DAT_14002aa00);
          KeCancelTimer(&DAT_14002a960);
          return 0;
        }
      } while ((iVar2 != 1) || (uVar6 = uVar6 + 1, uVar6 < 2));
      KeCancelTimer(&DAT_14002a960);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,0xc00000b5);
      }
      return 0xc00000b5;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000b5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc00000b5;
    }
    uVar4 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,0xc00000b5);
  return 0xc00000b5;
}



===== IpmiLibpKcsBmcTransact @ 140001340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong IpmiLibpKcsBmcTransact(longlong param_1,ushort *param_2,undefined8 param_3)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort uVar6;
  ushort uVar7;
  char local_res10 [16];
  undefined1 local_res20 [8];
  
  uVar7 = 0x122;
  if (*param_2 < 0x122) {
    uVar7 = *param_2;
  }
  uVar4 = IpmiLibpKcsSendRequestToBMC(param_1,(longlong)param_2 + 5,uVar7,param_3);
  uVar3 = (uint)uVar4;
  if (uVar3 == 0) {
    uVar7 = param_2[1];
    if (0x122 < uVar7) {
      param_2[1] = 0x122;
      uVar7 = 0x122;
    }
    uVar6 = 0;
LAB_1400013a4:
    while ((*(uint *)(param_1 + 0x20) & 1) == 0) {
      uVar5 = IpmiLibpKcsSpinRegister(param_1,param_3,2);
      if ((int)uVar5 != 0) goto LAB_1400015aa;
      bVar1 = IpmiLibReadOneByte(param_1,1);
      if ((char)bVar1 < '\0') {
LAB_14000155c:
        uVar3 = 0xc000003e;
        goto LAB_140001439;
      }
      if ((bVar1 >> 6 & 1) == 0) {
        uVar5 = IpmiLibpKcsSpinRegister(param_1,param_3,1);
        if ((int)uVar5 == 0) {
          IpmiLibReadOneByte(param_1,0);
          *(undefined4 *)(param_1 + 0x54) = 7;
          if (2 < uVar6) {
            param_2[1] = uVar6;
            uVar3 = 0;
            goto LAB_140001455;
          }
LAB_14000159f:
          uVar3 = 0xc00000e5;
          goto LAB_140001439;
        }
        goto LAB_1400015aa;
      }
      uVar5 = IpmiLibpKcsSpinRegister(param_1,param_3,1);
      if ((int)uVar5 != 0) goto LAB_1400015aa;
      uVar2 = IpmiLibReadOneByte(param_1,0);
      IpmiLibWriteOneByte(param_1,0,0x68);
      if ((int)(uint)uVar6 <= (int)(uVar7 - 1)) {
        uVar4 = (ulonglong)uVar6;
        uVar6 = uVar6 + 1;
        *(undefined1 *)(uVar4 + 0x127 + (longlong)param_2) = uVar2;
      }
    }
    local_res20[0] = 0;
    local_res10[0] = '\0';
    if (*(code **)(param_1 + 0x30) == (code *)0x0) {
      uVar3 = 0xc000000d;
      goto LAB_140001439;
    }
    uVar3 = (**(code **)(param_1 + 0x30))
                      (*(undefined8 *)(param_1 + 0x38),param_1,param_3,local_res10,local_res20,0);
    if ((int)uVar3 < 0) goto LAB_140001439;
    if (local_res10[0] == '\0') {
      if (*(char *)(param_1 + 0x18) == '\0') {
        **(undefined1 **)(param_1 + 0x60) = 0x68;
        LOCK();
        UNLOCK();
      }
      else {
        out((short)*(undefined8 *)(param_1 + 0x60),0x68);
      }
      if ((int)(uint)uVar6 <= (int)(uVar7 - 1)) {
        uVar4 = (ulonglong)uVar6;
        uVar6 = uVar6 + 1;
        *(undefined1 *)(uVar4 + 0x127 + (longlong)param_2) = local_res20[0];
      }
      goto LAB_1400013a4;
    }
    if (local_res10[0] != '\x01') {
      if (local_res10[0] != '\x02') {
        if (local_res10[0] == -1) goto LAB_14000155c;
        uVar3 = 0xc0000001;
        goto LAB_140001439;
      }
      *(undefined4 *)(param_1 + 0x54) = 7;
      uVar3 = 0;
      if (uVar6 < 3) goto LAB_14000159f;
      param_2[1] = uVar6;
      goto LAB_140001455;
    }
LAB_1400015aa:
    uVar3 = 0x102;
LAB_140001439:
    param_2[1] = 0;
    IpmiLibWriteOneByte(param_1,1,0x60);
  }
LAB_140001455:
  if ((int)uVar3 < 0) {
    uVar4 = IpmiLibpKcsHandleError(param_1,param_3);
    if ((int)uVar4 < 0) {
      if (*(code **)(param_1 + 0x28) != (code *)0x0) {
        (**(code **)(param_1 + 0x28))(*(undefined8 *)(param_1 + 0x38));
      }
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  else {
    uVar4 = (ulonglong)uVar3;
  }
  return uVar4;
}



===== IpmiLibpKcsSendRequestToBMC @ 1400015f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong IpmiLibpKcsSendRequestToBMC
                    (longlong param_1,longlong param_2,ushort param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  undefined4 uVar4;
  longlong lVar5;
  uint uVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  ushort uVar11;
  int iVar12;
  char local_res8 [8];
  longlong local_res10;
  char local_res18 [8];
  char local_68 [8];
  longlong local_60;
  longlong local_58;
  longlong local_50;
  longlong local_48 [2];
  
  uVar10 = *(uint *)(param_1 + 0x48);
  uVar1 = *(uint *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x54) = 7;
  uVar11 = 0;
  local_60 = 0;
  iVar12 = 0;
  local_res10 = param_2;
  lVar5 = KeQueryPerformanceCounter(&local_60);
  lVar2 = local_60 / 1000000;
  while( true ) {
    iVar12 = iVar12 + 1;
    uVar9 = (ulonglong)*(byte *)(param_1 + 0x18);
    pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
    if (*(byte *)(param_1 + 0x18) == 0) {
      bVar3 = *pbVar7;
    }
    else {
      bVar3 = in((short)pbVar7);
    }
    if ((bVar3 & 2) == 0) {
      if (*(char *)(param_1 + 0x18) != '\0') {
        in((short)*(undefined8 *)(param_1 + 0x60));
      }
      puVar8 = (undefined1 *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
      *(undefined4 *)(param_1 + 0x54) = 0;
      if (*(char *)(param_1 + 0x18) == '\0') {
        *puVar8 = 0x61;
        LOCK();
        UNLOCK();
      }
      else {
        out((short)puVar8,0x61);
      }
      if ((*(uint *)(param_1 + 0x20) & 1) != 0) {
        local_res18[0] = '\0';
        if (*(code **)(param_1 + 0x30) == (code *)0x0) goto LAB_140001b48;
        uVar10 = (**(code **)(param_1 + 0x30))
                           (*(undefined8 *)(param_1 + 0x38),param_1,param_4,local_res18,0,0);
        uVar9 = (ulonglong)uVar10;
        if ((int)uVar10 < 0) goto LAB_140001848;
        if (local_res18[0] == -1) goto LAB_140001a80;
      }
      uVar10 = *(uint *)(param_1 + 0x48);
      iVar12 = 0;
      uVar1 = *(uint *)(param_1 + 0x44);
      local_58 = 0;
      lVar5 = KeQueryPerformanceCounter(&local_58);
      lVar2 = local_58 / 1000000;
      goto LAB_14000175d;
    }
    uVar4 = IpmiLibpTimeAfter(uVar9,param_4);
    if (((char)uVar4 != '\0') ||
       (uVar4 = IpmiLibpTimeAfter(uVar9,lVar2 * (ulonglong)uVar1 + lVar5), (char)uVar4 != '\0'))
    break;
    if ((uVar10 < 0x32) && (iVar12 == 0x28)) {
      uVar10 = uVar10 + 100;
    }
    uVar6 = uVar10;
    if (*(uint *)(param_1 + 0x4c) <= uVar10) {
      uVar6 = *(uint *)(param_1 + 0x4c);
    }
    IpmiLibpDelay(param_1,uVar6);
  }
  goto LAB_140001b31;
LAB_14000175d:
  iVar12 = iVar12 + 1;
  uVar9 = (ulonglong)*(byte *)(param_1 + 0x18);
  pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
  if (*(byte *)(param_1 + 0x18) == 0) {
    bVar3 = *pbVar7;
  }
  else {
    bVar3 = in((short)pbVar7);
  }
  if ((bVar3 & 2) == 0) {
    pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
    if (*(char *)(param_1 + 0x18) == '\0') {
      bVar3 = *pbVar7;
    }
    else {
      bVar3 = in((short)pbVar7);
    }
    if ((-1 < (char)bVar3) || ((bVar3 & 0x40) != 0)) goto LAB_140001a80;
    if (*(char *)(param_1 + 0x18) != '\0') {
      in((short)*(undefined8 *)(param_1 + 0x60));
    }
    *(undefined4 *)(param_1 + 0x54) = 1;
    goto LAB_1400017d0;
  }
  uVar4 = IpmiLibpTimeAfter(uVar9,param_4);
  if (((char)uVar4 != '\0') ||
     (uVar4 = IpmiLibpTimeAfter(uVar9,lVar2 * (ulonglong)uVar1 + lVar5), (char)uVar4 != '\0'))
  goto LAB_140001b31;
  if ((uVar10 < 0x32) && (iVar12 == 0x28)) {
    uVar10 = uVar10 + 100;
  }
  uVar6 = uVar10;
  if (*(uint *)(param_1 + 0x4c) <= uVar10) {
    uVar6 = *(uint *)(param_1 + 0x4c);
  }
  IpmiLibpDelay(param_1,uVar6);
  goto LAB_14000175d;
LAB_1400017d0:
  if (1 < param_3) {
    if (*(char *)(param_1 + 0x18) == '\0') {
      **(undefined1 **)(param_1 + 0x60) = *(undefined1 *)((ulonglong)uVar11 + local_res10);
      LOCK();
      UNLOCK();
    }
    else {
      out((short)*(undefined1 **)(param_1 + 0x60),*(undefined1 *)((ulonglong)uVar11 + local_res10));
    }
    if ((*(uint *)(param_1 + 0x20) & 1) != 0) {
      local_res8[0] = '\0';
      if (*(code **)(param_1 + 0x30) == (code *)0x0) goto LAB_140001b48;
      uVar10 = (**(code **)(param_1 + 0x30))
                         (*(undefined8 *)(param_1 + 0x38),param_1,param_4,local_res8,0,0);
      uVar9 = (ulonglong)uVar10;
      if ((int)uVar10 < 0) goto LAB_140001848;
      if (local_res8[0] == -1) goto LAB_140001a80;
    }
    uVar10 = *(uint *)(param_1 + 0x48);
    uVar1 = *(uint *)(param_1 + 0x44);
    iVar12 = 0;
    local_50 = 0;
    lVar5 = KeQueryPerformanceCounter(&local_50);
    lVar2 = local_50 / 1000000;
    while( true ) {
      iVar12 = iVar12 + 1;
      uVar9 = (ulonglong)*(byte *)(param_1 + 0x18);
      pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
      if (*(byte *)(param_1 + 0x18) == 0) {
        bVar3 = *pbVar7;
      }
      else {
        bVar3 = in((short)pbVar7);
      }
      if ((bVar3 & 2) == 0) break;
      uVar4 = IpmiLibpTimeAfter(uVar9,param_4);
      if (((char)uVar4 != '\0') ||
         (uVar4 = IpmiLibpTimeAfter(uVar9,lVar2 * (ulonglong)uVar1 + lVar5), (char)uVar4 != '\0'))
      goto LAB_140001b31;
      if ((uVar10 < 0x32) && (iVar12 == 0x28)) {
        uVar10 = uVar10 + 100;
      }
      uVar6 = uVar10;
      if (*(uint *)(param_1 + 0x4c) <= uVar10) {
        uVar6 = *(uint *)(param_1 + 0x4c);
      }
      IpmiLibpDelay(param_1,uVar6);
    }
    pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
    if (*(char *)(param_1 + 0x18) == '\0') {
      bVar3 = *pbVar7;
    }
    else {
      bVar3 = in((short)pbVar7);
    }
    if ((-1 < (char)bVar3) || ((bVar3 & 0x40) != 0)) goto LAB_140001a80;
    if (*(char *)(param_1 + 0x18) == '\0') {
      uVar11 = uVar11 + 1;
      param_3 = param_3 - 1;
    }
    else {
      in((short)*(undefined8 *)(param_1 + 0x60));
      uVar11 = uVar11 + 1;
      param_3 = param_3 - 1;
    }
    goto LAB_1400017d0;
  }
  puVar8 = (undefined1 *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
  if (*(char *)(param_1 + 0x18) == '\0') {
    *puVar8 = 0x62;
    LOCK();
    UNLOCK();
  }
  else {
    out((short)puVar8,0x62);
  }
  *(undefined4 *)(param_1 + 0x54) = 2;
  if ((*(uint *)(param_1 + 0x20) & 1) != 0) {
    local_68[0] = '\0';
    if (*(code **)(param_1 + 0x30) == (code *)0x0) {
LAB_140001b48:
      uVar9 = 0xc000000d;
      goto LAB_140001848;
    }
    uVar10 = (**(code **)(param_1 + 0x30))
                       (*(undefined8 *)(param_1 + 0x38),param_1,param_4,local_68,0,0);
    uVar9 = (ulonglong)uVar10;
    if ((int)uVar10 < 0) goto LAB_140001848;
    if (local_68[0] == -1) {
LAB_140001a80:
      uVar9 = 0xc000003e;
      goto LAB_140001848;
    }
  }
  uVar10 = *(uint *)(param_1 + 0x48);
  uVar1 = *(uint *)(param_1 + 0x44);
  iVar12 = 0;
  local_48[0] = 0;
  lVar5 = KeQueryPerformanceCounter(local_48);
  lVar2 = local_48[0] / 1000000;
  while( true ) {
    iVar12 = iVar12 + 1;
    uVar9 = (ulonglong)*(byte *)(param_1 + 0x18);
    pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
    if (*(byte *)(param_1 + 0x18) == 0) {
      bVar3 = *pbVar7;
    }
    else {
      bVar3 = in((short)pbVar7);
    }
    if ((bVar3 & 2) == 0) {
      pbVar7 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
      if (*(char *)(param_1 + 0x18) == '\0') {
        bVar3 = *pbVar7;
      }
      else {
        bVar3 = in((short)pbVar7);
      }
      if (((char)bVar3 < '\0') && ((bVar3 & 0x40) == 0)) {
        if (*(char *)(param_1 + 0x18) != '\0') {
          in((short)*(undefined8 *)(param_1 + 0x60));
        }
        if (*(char *)(param_1 + 0x18) == '\0') {
          **(undefined1 **)(param_1 + 0x60) = *(undefined1 *)((ulonglong)uVar11 + local_res10);
          LOCK();
          UNLOCK();
        }
        else {
          out((short)*(undefined8 *)(param_1 + 0x60),
              *(undefined1 *)((ulonglong)uVar11 + local_res10));
        }
        *(undefined4 *)(param_1 + 0x54) = 3;
        return 0;
      }
      goto LAB_140001a80;
    }
    uVar4 = IpmiLibpTimeAfter(uVar9,param_4);
    if (((char)uVar4 != '\0') ||
       (uVar4 = IpmiLibpTimeAfter(uVar9,lVar2 * (ulonglong)uVar1 + lVar5), (char)uVar4 != '\0'))
    break;
    if ((uVar10 < 0x32) && (iVar12 == 0x28)) {
      uVar10 = uVar10 + 100;
    }
    uVar6 = uVar10;
    if (*(uint *)(param_1 + 0x4c) <= uVar10) {
      uVar6 = *(uint *)(param_1 + 0x4c);
    }
    IpmiLibpDelay(param_1,uVar6);
  }
LAB_140001b31:
  uVar9 = 0x102;
LAB_140001848:
  IpmiLibWriteOneByte(param_1,1,0x60);
  return uVar9 & 0xffffffff;
}



===== IpmiLibWriteOneByte @ 140001c70 =====

ulonglong IpmiLibWriteOneByte(longlong param_1,byte param_2,byte param_3)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_1 + 0x60);
  if (*(char *)(param_1 + 0x18) == '\0') {
    *(byte *)((uint)*(byte *)(param_1 + 8) * (uint)param_2 + uVar1) = param_3;
    LOCK();
    UNLOCK();
    return uVar1;
  }
  out((ushort)*(byte *)(param_1 + 8) * (ushort)param_2 + (short)uVar1,param_3);
  return (ulonglong)param_3;
}



===== IPMIInterruptDataSynchronize @ 140001cb0 =====

undefined8 IPMIInterruptDataSynchronize(longlong param_1)

{
  byte bVar1;
  undefined8 in_RAX;
  
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0xbb) = 1;
    if (*(char *)(param_1 + 0xa8) != '\0') {
      bVar1 = *(byte *)(param_1 + 0xba);
      *(undefined1 *)(param_1 + 0xbe) = *(undefined1 *)((ulonglong)bVar1 + 0xa9 + param_1);
      in_RAX = 0;
      *(undefined1 *)(param_1 + 0xbf) = *(undefined1 *)((ulonglong)bVar1 + 0xb1 + param_1);
      *(byte *)(param_1 + 0xba) = bVar1 + 1 & 7;
      *(char *)(param_1 + 0xa8) = *(char *)(param_1 + 0xa8) + -1;
      *(undefined1 *)(param_1 + 0xbb) = 0;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== IpmiLibpKcsSpinRegister @ 140001d20 =====

undefined8 IpmiLibpKcsSpinRegister(longlong param_1,undefined8 param_2,ushort param_3)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  undefined4 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  longlong local_res8;
  
  uVar9 = *(uint *)(param_1 + 0x48);
  uVar1 = *(uint *)(param_1 + 0x44);
  iVar10 = 0;
  local_res8 = 0;
  lVar5 = KeQueryPerformanceCounter(&local_res8);
  lVar2 = local_res8 / 1000000;
  do {
    iVar10 = iVar10 + 1;
    pbVar8 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
    if (*(char *)(param_1 + 0x18) == '\0') {
      bVar3 = *pbVar8;
    }
    else {
      bVar3 = in((short)pbVar8);
    }
    uVar6 = param_3 - 1;
    uVar7 = (ulonglong)uVar6;
    if (uVar6 == 0) {
      if ((bVar3 & 1) != 0) {
        return 0;
      }
    }
    else {
      if (uVar6 != 1) {
        return 0xc000000d;
      }
      if ((bVar3 & 2) == 0) {
        return 0;
      }
    }
    uVar4 = IpmiLibpTimeAfter(uVar7,param_2);
    if (((char)uVar4 != '\0') ||
       (uVar4 = IpmiLibpTimeAfter(uVar7,lVar2 * (ulonglong)uVar1 + lVar5), (char)uVar4 != '\0')) {
      return 0x102;
    }
    if ((uVar9 < 0x32) && (iVar10 == 0x28)) {
      uVar9 = uVar9 + 100;
    }
    uVar6 = uVar9;
    if (*(uint *)(param_1 + 0x4c) <= uVar9) {
      uVar6 = *(uint *)(param_1 + 0x4c);
    }
    IpmiLibpDelay(param_1,uVar6);
  } while( true );
}



===== QueryDataBlock @ 140001e30 =====

undefined4
QueryDataBlock(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,int param_5,
              undefined4 *param_6,int param_7,undefined1 *param_8)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
  }
  if ((param_4 == 0) && (param_5 == 1)) {
    if ((param_6 == (undefined4 *)0x0) || (param_7 == 0)) {
      uVar2 = 0xc0000023;
    }
    else {
      *param_8 = *(undefined1 *)(lVar1 + 0x159);
      *param_6 = 1;
    }
    uVar2 = WmiCompleteRequest(param_1,param_2,uVar2,1,0);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar2;
    }
    uVar3 = 0x14;
  }
  else {
    uVar2 = WmiCompleteRequest(param_1,param_2,0xc0000295,0,0);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar2;
    }
    uVar3 = 0x13;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,uVar2);
  return uVar2;
}



===== IpmiLibReadOneByte @ 140001f90 =====

undefined1 IpmiLibReadOneByte(longlong param_1,byte param_2)

{
  undefined1 uVar1;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    return *(undefined1 *)
            ((ulonglong)((uint)*(byte *)(param_1 + 8) * (uint)param_2) +
            *(longlong *)(param_1 + 0x60));
  }
  uVar1 = in((ushort)*(byte *)(param_1 + 8) * (ushort)param_2 + (short)*(longlong *)(param_1 + 0x60)
            );
  return uVar1;
}



===== KCSRequestResponseEngine @ 140001fd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KCSRequestResponseEngine(void)

{
  longlong *plVar1;
  char *pcVar2;
  int *piVar3;
  ushort uVar4;
  int *piVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined1 auStack_118 [32];
  undefined1 *local_f8;
  undefined4 *local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  ushort local_d8 [2];
  undefined4 local_d4;
  longlong local_d0;
  undefined *local_c8;
  undefined *local_c0;
  char local_b8 [64];
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  bVar8 = false;
  local_c8 = &DAT_14002a8e8;
  local_c0 = &DAT_14002a920;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
  }
  KeInitializeTimerEx(&DAT_14002a920,1);
  KeSetTimerEx(&DAT_14002a920,0,10000,0);
  do {
    local_e0 = 0;
    local_e8 = 0;
    local_f0 = (undefined4 *)((ulonglong)local_f0 & 0xffffffffffffff00);
    local_f8 = (undefined1 *)((ulonglong)local_f8 & 0xffffffffffffff00);
    iVar10 = KeWaitForMultipleObjects(2,&local_c8,1);
    if (iVar10 == 0) {
      KeClearEvent(&DAT_14002a8e8);
      lVar11 = ExInterlockedRemoveHeadList(&DAT_14002a900,&EngineState);
      while ((lVar11 != 0 && (plVar1 = (longlong *)(lVar11 + -0x10), plVar1 != (longlong *)0x0))) {
        iVar10 = *(int *)(lVar11 + -8);
        if (iVar10 == 1) {
          piVar5 = (int *)*plVar1;
          if (bVar8) {
            iVar10 = -0x3ffffee0;
          }
          else {
            lVar6 = *(longlong *)(lVar11 + 0x28);
            piVar3 = piVar5 + 1;
            local_d8[0] = 0x40;
            uVar9 = (uint)local_d4 >> 0x10;
            local_d4 = CONCAT22((short)uVar9,0x40);
            plVar1 = (longlong *)(lVar6 + 0x138);
            local_d0 = lVar6;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x30,
                      &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
            }
            if (((piVar3 == (int *)0x0) || (plVar1 == (longlong *)0x0)) ||
               (lVar7 = *plVar1, lVar7 == 0)) {
              iVar10 = -0x3ffffff3;
LAB_140002224:
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                         &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,iVar10);
              }
            }
            else {
              memset(local_b8,0,0x40);
              memset(local_78,0,0x40);
              uVar4 = *(ushort *)((longlong)piVar5 + 5);
              if ((char)*piVar3 == *(char *)(lVar6 + 0x159)) {
                iVar10 = (**(code **)(lVar7 + 8))
                                   (plVar1,piVar3,(char *)((longlong)piVar3 + (ulonglong)uVar4 + 6))
                ;
                goto LAB_140002224;
              }
              if (*(longlong *)(lVar7 + 0x10) != 0) {
                uVar12 = IpmiLibIpmbMessagePack
                                   (*(char *)(lVar6 + 0x159),local_b8,(char *)piVar3,local_d8);
                iVar10 = (int)uVar12;
                if (iVar10 == 0) {
                  local_f0 = &local_d4;
                  local_f8 = local_78;
                  *(undefined1 *)(lVar6 + 0x1f5) = 1;
                  iVar10 = (**(code **)(*plVar1 + 0x10))(plVar1,local_b8,local_d8[0]);
                  HandleNonCommunicationInterrupt((longlong)plVar1);
                  *(undefined1 *)(lVar6 + 0x1f5) = 0;
                  if ((iVar10 == 0) && (*(char *)((longlong)piVar3 + (ulonglong)uVar4 + 8) == '\0'))
                  {
                    uVar12 = IpmiLibIpmbMessageUnpack
                                       ((longlong)local_78,
                                        (ushort *)((longlong)piVar3 + (ulonglong)uVar4 + 6),
                                        (ushort)local_d4);
                    iVar10 = (int)uVar12;
                  }
                  else {
                    pcVar2 = (char *)((longlong)piVar3 + (ulonglong)uVar4 + 6);
                    pcVar2[0] = '\0';
                    pcVar2[1] = '\0';
                  }
                }
                goto LAB_140002224;
              }
              iVar10 = -0x3ffffffe;
            }
            local_d4 = iVar10;
            if (iVar10 == -0x3fffff1b) {
              LogEvent(0x800503ec,*(undefined8 *)(local_d0 + 8),4,&local_d4);
              iVar10 = local_d4;
            }
          }
          *piVar5 = iVar10;
LAB_140002256:
          KeSetEvent(lVar11 + 0x10,0,0);
        }
        else {
          if (iVar10 == 2) {
            if (*(longlong *)(lVar11 + 0x28) == 0) {
              bVar8 = true;
            }
            else {
              DrainDeviceIrps(*(longlong *)(lVar11 + 0x28));
            }
            goto LAB_140002256;
          }
          if (iVar10 != 3) goto LAB_140002256;
          HandleNonCommunicationInterrupt(*(longlong *)(lVar11 + 0x28) + 0x138);
          ExFreePoolWithTag(plVar1,0x494d5049);
        }
        lVar11 = ExInterlockedRemoveHeadList(&DAT_14002a900);
      }
    }
    else if (iVar10 == 2) {
      HandleTimeouts();
    }
    if (bVar8) {
      KeCancelTimer(&DAT_14002a920);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
      }
      PsTerminateSystemThread(0);
      return;
    }
  } while( true );
}



===== IpmiLibpGetTimeout @ 140002470 =====

longlong IpmiLibpGetTimeout(undefined8 param_1,ulonglong param_2)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  lVar1 = KeQueryPerformanceCounter(local_res8);
  return (param_2 & 0xffffffff) * (local_res8[0] / 1000000) + lVar1;
}



===== KCSDpc @ 1400024d0 =====

void KCSDpc(void)

{
  byte bVar1;
  byte *pbVar2;
  longlong in_R9;
  
  pbVar2 = (byte *)((ulonglong)*(byte *)(in_R9 + 0x148) + *(longlong *)(in_R9 + 0x1a0));
  if (*(char *)(in_R9 + 0x158) == '\0') {
    bVar1 = *pbVar2;
  }
  else {
    bVar1 = in((short)pbVar2);
  }
  if (*(int *)(in_R9 + 0x194) == 7) {
    if ((bVar1 & 4) == 0) {
      return;
    }
    if (*(char *)(in_R9 + 0x1f5) != '\x01') {
      ipmi_send_noncommunicationrequest(in_R9);
      return;
    }
  }
  KeSetEvent(&DAT_14002aa00,0,0);
  return;
}



===== ipmi_ioctl_func @ 140002540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ipmi_ioctl_func(longlong *param_1,int param_2,char *param_3)

{
  ushort uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_108 [32];
  undefined1 *local_e8;
  ushort *local_e0;
  char local_c8 [4];
  ushort local_c4 [2];
  ushort local_c0 [4];
  char local_b8 [64];
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  local_c8[0] = '\0';
  local_c4[0] = 0x40;
  local_c0[0] = 0x40;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  if (((param_3 == (char *)0x0) || (param_1 == (longlong *)0x0)) ||
     (puVar2 = (undefined8 *)*param_1, puVar2 == (undefined8 *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    memset(local_b8,0,0x40);
    memset(local_78,0,0x40);
    if (param_2 == 0x222004) {
      uVar3 = (*(code *)*puVar2)(param_1,local_c8);
      uVar5 = (ulonglong)uVar3;
      if (uVar3 == 0) {
        *param_3 = local_c8[0];
      }
    }
    else if (param_2 == 0x222008) {
      uVar1 = *(ushort *)(param_3 + 1);
      if (*param_3 == *(char *)((longlong)param_1 + 0x21)) {
        uVar3 = (*(code *)puVar2[1])(param_1,param_3,param_3 + (ulonglong)uVar1 + 6);
        uVar5 = (ulonglong)uVar3;
      }
      else {
        if (puVar2[2] == 0) {
          return 0xc0000002;
        }
        uVar4 = IpmiLibIpmbMessagePack
                          (*(char *)((longlong)param_1 + 0x21),local_b8,param_3,local_c4);
        uVar5 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          local_e0 = local_c0;
          local_e8 = local_78;
          *(undefined1 *)((longlong)param_1 + 0xbd) = 1;
          uVar3 = (**(code **)(*param_1 + 0x10))
                            (param_1,local_b8,local_c4[0],param_3 + (ulonglong)uVar1 + 8);
          uVar5 = (ulonglong)uVar3;
          HandleNonCommunicationInterrupt((longlong)param_1);
          *(undefined1 *)((longlong)param_1 + 0xbd) = 0;
          if ((uVar3 == 0) && (param_3[(ulonglong)uVar1 + 8] == '\0')) {
            uVar5 = IpmiLibIpmbMessageUnpack
                              ((longlong)local_78,(ushort *)(param_3 + (ulonglong)uVar1 + 6),
                               local_c0[0]);
            uVar5 = uVar5 & 0xffffffff;
          }
          else {
            (param_3 + (ulonglong)uVar1 + 6)[0] = '\0';
            (param_3 + (ulonglong)uVar1 + 6)[1] = '\0';
          }
        }
      }
    }
    else {
      uVar5 = 0xc0000010;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,(int)uVar5);
  }
  return uVar5;
}



===== Check_IBFNotSet @ 140002780 =====

uint Check_IBFNotSet(longlong param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
  if (*(char *)(param_1 + 0x18) == '\0') {
    return -(uint)((*pbVar2 & 2) != 0) & 0xc00000b5;
  }
  bVar1 = in((short)pbVar2);
  return -(uint)((bVar1 & 2) != 0) & 0xc00000b5;
}



===== Check_OBFSet @ 1400027c0 =====

undefined8 Check_OBFSet(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)((ulonglong)*(byte *)(param_1 + 8) + *(longlong *)(param_1 + 0x60));
  if (*(char *)(param_1 + 0x18) == '\0') {
    uVar2 = 0xc00000b5;
    if ((*pbVar3 & 1) != 0) {
      uVar2 = 0;
    }
    return uVar2;
  }
  bVar1 = in((short)pbVar3);
  uVar2 = 0xc00000b5;
  if ((bVar1 & 1) != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



===== KcsRequestReceive @ 140002810 =====

ulonglong KcsRequestReceive(longlong param_1,longlong param_2,ushort *param_3)

{
  ulonglong uVar1;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    uVar1 = IpmiLibpKcsRequestAndReceive(param_1 + 8,param_2,param_3);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== IpmiLibpKcsRequestAndReceive @ 140002840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IpmiLibpKcsRequestAndReceive(longlong param_1,longlong param_2,ushort *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStack_2b8 [32];
  longlong local_298 [2];
  ushort local_288;
  ushort local_286;
  undefined1 local_284;
  undefined1 local_283 [292];
  char local_15f;
  undefined1 local_15e [294];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  memset(&local_284,0,0x246);
  uVar1 = *(uint *)(param_1 + 0x40);
  local_298[0] = 0;
  lVar3 = KeQueryPerformanceCounter(local_298);
  lVar2 = local_298[0] / 1000000;
  local_288 = *(short *)(param_2 + 1) + 2;
  if (local_288 < 0x123) {
    memmove(local_283,(void *)(param_2 + 3),(ulonglong)local_288);
    local_286 = 0x122;
    uVar4 = IpmiLibpKcsBmcTransact(param_1,&local_288,lVar2 * (ulonglong)uVar1 + lVar3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    if ((int)uVar4 == 0x102) {
      return uVar4;
    }
    if (param_3 == (ushort *)0x0) {
      return 0xc000000d;
    }
    if ((uint)local_286 <= *param_3 + 3) {
      *(char *)(param_3 + 1) = local_15f;
      *param_3 = 0;
      if ((local_15f == '\0') && (3 < local_286)) {
        *param_3 = local_286 - 3;
        memmove((void *)((longlong)param_3 + 3),local_15e,(ulonglong)(ushort)(local_286 - 3));
      }
      return 0;
    }
  }
  return 0xc0000017;
}



===== AcquireStopLock @ 1400029a0 =====

undefined8 AcquireStopLock(char *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  if (*param_1 == '\0') {
    uVar3 = 0;
  }
  else {
    LOCK();
    piVar1 = (int *)(param_1 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(param_1 + 8,0,0);
    }
    uVar3 = 0xc0000056;
  }
  return uVar3;
}



===== ReleaseStopLock @ 1400029f0 =====

void ReleaseStopLock(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_1 + 8,0,0);
  }
  return;
}



===== ipmi_send_request @ 140002a30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ipmi_send_request(undefined8 param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined1 auStack_158 [32];
  undefined8 local_138;
  undefined **local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined *local_d8;
  uint local_d0;
  undefined4 local_cc;
  undefined *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 *local_b8;
  undefined8 local_b0;
  undefined *local_a8;
  uint local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined *local_88;
  uint local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 local_60;
  undefined *local_58;
  uint local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_158;
  if (5 < DAT_140014088) {
    if (((DAT_140014098 & 8) == 0) || (((uint)DAT_1400140a0 & 8) != DAT_1400140a0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_104 = 5;
      local_a8 = PTR_DAT_140014090;
      local_108 = 0xb000000;
      local_100 = 8;
      local_a0 = (uint)*(ushort *)PTR_DAT_140014090;
      local_98 = &DAT_14001125e;
      local_9c = 2;
      local_90 = 0x1c;
      local_8c = 1;
      local_128 = 0x1bf9;
      local_130 = &local_a8;
      local_138 = CONCAT44(local_138._4_4_,2);
      EtwWriteTransfer(DAT_1400140a8,&local_108,0,0);
    }
  }
  puVar3 = (undefined8 *)ExAllocatePool2(0x42,0x40,0x494d5049);
  if (puVar3 == (undefined8 *)0x0) {
    if (1 < DAT_140014088) {
      if (((DAT_140014098 & 8) == 0) || (((uint)DAT_1400140a0 & 8) != DAT_1400140a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_68 = &local_11c;
        local_11c = 0xc0000017;
        local_114 = 1;
        local_88 = PTR_DAT_140014090;
        local_60 = 4;
        local_118 = 0xb000000;
        local_110 = 8;
        local_80 = (uint)*(ushort *)PTR_DAT_140014090;
        local_78 = &DAT_140011219;
        local_7c = 2;
        local_70 = 0x39;
        local_6c = 1;
        local_128 = 0x1bf9;
        local_130 = &local_88;
        local_138 = CONCAT44(local_138._4_4_,3);
        EtwWriteTransfer(DAT_1400140a8,&local_118,0,0);
      }
    }
    uVar2 = 0xc0000017;
  }
  else {
    *puVar3 = param_2;
    *(undefined4 *)(puVar3 + 1) = 1;
    puVar3[7] = param_1;
    KeInitializeEvent(puVar3 + 4,0,0);
    ExInterlockedInsertTailList(&DAT_14002a900,puVar3 + 2,&EngineState);
    if (5 < DAT_140014088) {
      if (((DAT_140014098 & 8) == 0) || (((uint)DAT_1400140a0 & 8) != DAT_1400140a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_124 = *param_2;
        local_38 = &local_124;
        local_30 = 4;
        local_f4 = 5;
        local_58 = PTR_DAT_140014090;
        local_f8 = 0xb000000;
        local_f0 = 8;
        local_50 = (uint)*(ushort *)PTR_DAT_140014090;
        local_48 = &DAT_1400112f5;
        local_4c = 2;
        local_40 = 0x3d;
        local_3c = 1;
        local_128 = 0x1bf9;
        local_138 = CONCAT44(local_138._4_4_,3);
        local_130 = &local_58;
        EtwWriteTransfer(DAT_1400140a8,&local_f8,0,0);
      }
    }
    KeSetEvent(&DAT_14002a8e8,0,0);
    if (5 < DAT_140014088) {
      if (((DAT_140014098 & 8) == 0) || (((uint)DAT_1400140a0 & 8) != DAT_1400140a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_120 = *param_2;
        local_b8 = &local_120;
        local_b0 = 4;
        local_e4 = 5;
        local_d8 = PTR_DAT_140014090;
        local_e8 = 0xb000000;
        local_e0 = 8;
        local_d0 = (uint)*(ushort *)PTR_DAT_140014090;
        local_c8 = &DAT_140011286;
        local_cc = 2;
        local_c0 = 0x3d;
        local_bc = 1;
        local_128 = 0x1bf9;
        local_130 = &local_d8;
        local_138 = CONCAT44(local_138._4_4_,3);
        EtwWriteTransfer(DAT_1400140a8,&local_e8,0,0);
      }
    }
    local_138 = 0;
    KeWaitForSingleObject(puVar3 + 4,0,0,0);
    ExFreePoolWithTag(puVar3,0x494d5049);
    if (5 < DAT_140014088) {
      if (((DAT_140014098 & 8) == 0) || (((uint)DAT_1400140a0 & 8) != DAT_1400140a0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_120 = *param_2;
        local_b8 = &local_120;
        local_b0 = 4;
        local_114 = 5;
        local_d8 = PTR_DAT_140014090;
        local_118 = 0xb000000;
        local_110 = 8;
        local_d0 = (uint)*(ushort *)PTR_DAT_140014090;
        local_c8 = &DAT_1400111d7;
        local_cc = 2;
        local_c0 = 0x36;
        local_bc = 1;
        local_124 = 0x1bf9;
        local_130 = &local_d8;
        local_138 = CONCAT44(local_138._4_4_,3);
        EtwWriteTransfer(DAT_1400140a8,&local_118,0,0);
      }
    }
    uVar2 = *param_2;
  }
  return uVar2;
}



===== WaitInterruptIfSupported @ 140002f90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WaitInterruptIfSupported
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined1 *param_4,
                    undefined1 *param_5,char param_6)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  byte *pbVar7;
  ulonglong uVar8;
  
  lVar3 = _DAT_fffff78000000320;
  iVar1 = *(int *)(param_1 + 0x48);
  uVar5 = KeQueryTimeIncrement();
  uVar8 = 0;
  if ((*(longlong *)(param_1 + 0xa0) == 0) || ((*(uint *)(param_2 + 0x20) & 1) == 0)) {
    *param_4 = 0;
  }
  else {
    KeSynchronizeExecution(*(longlong *)(param_1 + 0xa0),IPMIInterruptDataSynchronize,param_1);
    *param_4 = *(undefined1 *)(param_1 + 0xbe);
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = *(undefined1 *)(param_1 + 0xbf);
    }
  }
  if ((param_6 != '\0') && (*(char *)(param_1 + 0xbb) != '\0')) {
    pbVar7 = (byte *)((ulonglong)*(byte *)(param_2 + 8) + *(longlong *)(param_2 + 0x60));
    if (*(char *)(param_2 + 0x18) == '\0') {
      bVar4 = *pbVar7;
    }
    else {
      bVar4 = in((short)pbVar7);
    }
    if (((bVar4 & 4) != 0) && (*(int *)(param_2 + 0x54) == 7)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids);
      }
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids);
    }
  }
  uVar2 = *(uint *)(param_2 + 0x20);
  while( true ) {
    if ((uVar2 & 1) == 0) {
      return uVar8;
    }
    if (*(char *)(param_1 + 0xbb) == '\0') break;
    uVar6 = WaitForEventOrTimeout(param_1,(ulonglong)(uint)(iVar1 * 10) / (ulonglong)uVar5 + lVar3);
    uVar8 = uVar6 & 0xffffffff;
    if ((int)uVar6 != 0) {
      *(undefined1 *)(param_1 + 0xbe) = 0;
      return uVar8;
    }
    KeSynchronizeExecution(*(undefined8 *)(param_1 + 0xa0),IPMIInterruptDataSynchronize,param_1);
    *param_4 = *(undefined1 *)(param_1 + 0xbe);
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = *(undefined1 *)(param_1 + 0xbf);
    }
    uVar2 = *(uint *)(param_2 + 0x20);
  }
  return uVar8;
}



===== __C_specific_handler @ 140003160 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140003160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __report_gsfailure @ 140003180 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AssembleOSRECBody @ 140003190 =====

void AssembleOSRECBody(undefined8 *param_1,undefined1 param_2,void *param_3,byte param_4)

{
  uint uVar1;
  
  uVar1 = (uint)param_4;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0xdd;
  *(undefined2 *)((longlong)param_1 + 7) = 0x137;
  *(undefined1 *)((longlong)param_1 + 10) = param_2;
  if (4 < param_4) {
    uVar1 = 4;
  }
  memmove((void *)((longlong)param_1 + 0xb),param_3,(ulonglong)uVar1);
  return;
}



===== BugCheckReasonCallbackRoutine @ 1400031e0 =====

void BugCheckReasonCallbackRoutine
               (undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(char *)(*(ulonglong *)(param_2 + 0x30) + 0x1f8) == '\0') {
    WriteBSOD2SEL(*(ulonglong *)(param_2 + 0x30),param_2,param_3,param_4);
  }
  return;
}



===== CompleteRequest @ 140003204 =====

undefined4 CompleteRequest(longlong param_1,undefined4 param_2)

{
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = param_2;
  IofCompleteRequest(param_1,0);
  return param_2;
}



===== CompleteRequest2 @ 140003234 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
CompleteRequest2(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  *(undefined4 *)(param_1 + 0x30) = param_2;
  IofCompleteRequest(param_1,0);
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010f45,param_3,param_4,2,local_38);
    }
  }
  return param_2;
}



===== DeregisterAllInterfaces @ 1400032b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
DeregisterAllInterfaces(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar3 = param_1 + 0x128;
  uVar1 = IoSetDeviceInterfaceState(lVar3,0);
  RtlFreeUnicodeString();
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(lVar3,1);
    if ((char)uVar2 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_18 = 4;
      local_48[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_14001058f,param_3,param_4,3,local_40);
    }
  }
  return uVar1;
}



===== EnableAllInterfaces @ 140003368 =====

void EnableAllInterfaces(longlong param_1)

{
  IoSetDeviceInterfaceState(param_1 + 0x128);
  return;
}



===== GenerateMSRDump @ 14000338c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GenerateMSRDump(ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte *pbVar3;
  undefined *puVar4;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar4 = (undefined *)(ulonglong)DAT_140014088;
  uVar2 = param_1;
  if ((5 < DAT_140014088) && (uVar1 = _tlgKeywordOn(param_1,1), (char)uVar1 != '\0')) {
    local_48[0] = 0;
    local_20 = local_48;
    local_14 = 0;
    local_18 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar2,&DAT_140010be6,puVar4,param_4,3,local_40);
    puVar4 = (undefined *)(ulonglong)DAT_140014088;
  }
  if (IpmiPolicyMsrDumpEnabled == '\0') {
    if ((uint)puVar4 < 2) {
      return;
    }
    uVar1 = _tlgKeywordOn(uVar2,1);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_48[0] = 0;
    pbVar3 = &DAT_1400104b8;
  }
  else {
    callbackBuffer = *(undefined1 *)(param_1 + 0x159);
    puVar4 = &callbackBuffer;
    _DAT_14002a481 = 0xf5d80001;
    _DAT_14002a487 = 0x3f5;
    DAT_14002a485 = 0;
    DAT_14002a489 = 0xff;
    uVar2 = ipmi_ioctl_func((longlong *)(param_1 + 0x138),0x222008,&callbackBuffer);
    uVar2 = uVar2 & 0xffffffff;
    if (DAT_140014088 < 6) {
      return;
    }
    uVar1 = _tlgKeywordOn(uVar2,1);
    if ((char)uVar1 == '\0') {
      return;
    }
    local_48[0] = (undefined4)uVar2;
    pbVar3 = &DAT_140010a8f;
  }
  local_14 = 0;
  local_20 = local_48;
  local_18 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(uVar2,pbVar3,puVar4,param_4,3,local_40);
  return;
}



===== OnRequestComplete @ 1400034f0 =====

undefined8 OnRequestComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== WPP_SF_D @ 14000351c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dd @ 140003560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,0x11,local_res20,4,
             &param_5,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400035c0 =====

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



===== WriteBSOD2SEL @ 1400035f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WriteBSOD2SEL(ulonglong param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 extraout_var;
  ulonglong uVar8;
  longlong lVar9;
  undefined *puVar10;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [2];
  undefined1 local_60 [32];
  undefined4 *local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  puVar10 = &DAT_140014a3c;
  SelCacheWorkerRunning = 0;
  lVar9 = 0x100;
  iVar2 = *(int *)KiBugCheckData_exref;
  uVar3 = *(undefined8 *)(KiBugCheckData_exref + 8);
  uVar4 = *(undefined8 *)(KiBugCheckData_exref + 0x10);
  uVar5 = *(undefined8 *)(KiBugCheckData_exref + 0x18);
  uVar6 = *(undefined8 *)(KiBugCheckData_exref + 0x20);
  *(undefined1 *)(param_1 + 0x1f8) = 1;
  *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x160) & 0xfffffffe | 4;
  do {
    if (*(int *)(puVar10 + -4) != 0) {
      param_2 = puVar10;
      WriteOSREC2SEL(DAT_14002a338,(longlong)puVar10,param_3,param_4);
    }
    puVar10 = puVar10 + 0x158;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  *(undefined4 *)(param_1 + 0x18c) = 0x1e;
  if (((iVar2 == 0x80) && (IpmiPolicyDoes0x80Dump != '\0')) ||
     ((iVar2 == 0x9c && (IpmiPolicyDoes0x9cDump != '\0')))) {
    GenerateMSRDump(param_1,param_2,param_3,param_4);
  }
  plVar1 = (longlong *)(param_1 + 0x138);
  iVar7 = ipmi_interface_abort((longlong)plVar1);
  uVar8 = CONCAT44(extraout_var,iVar7);
  if (iVar7 == 0) {
    callbackBuffer = *(undefined1 *)(param_1 + 0x159);
    _DAT_14002a481 = 0x2100008;
    _DAT_14002a48e = 0x3ee;
    _DAT_14002a490 = CONCAT31(DAT_14002a490_1,0xff);
    _DAT_14002a485 = 0x441;
    DAT_14002a487 = 0x20;
    _DAT_14002a488 = 0xff016f00;
    DAT_14002a48c = 0xff;
    uVar8 = ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
    if (((int)uVar8 == 0) && (DAT_14002a490 == '\0')) {
      _DAT_14002a481 = 0x44280010;
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a498._0_1_ = 0xff;
      _DAT_14002a496 = 0x3e6;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x100;
      DAT_14002a494 = 1;
      _DAT_14002a490 = iVar2;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x200;
      _DAT_14002a490 = (int)uVar3;
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x200;
      _DAT_14002a490 = (int)((ulonglong)uVar3 >> 0x20);
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x300;
      _DAT_14002a490 = (int)uVar4;
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x300;
      _DAT_14002a490 = (int)((ulonglong)uVar4 >> 0x20);
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x400;
      _DAT_14002a490 = (int)uVar5;
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x400;
      _DAT_14002a490 = (int)((ulonglong)uVar5 >> 0x20);
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x500;
      _DAT_14002a490 = (int)uVar6;
      DAT_14002a494 = 1;
      ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      _DAT_14002a485 = 0;
      _DAT_14002a488 = 0;
      puVar10 = &callbackBuffer;
      DAT_14002a487 = 0xde;
      DAT_14002a48c = 0x37;
      uRam000000014002a48d = 1;
      _DAT_14002a48e = 0x500;
      _DAT_14002a490 = (int)((ulonglong)uVar6 >> 0x20);
      DAT_14002a494 = 1;
      uVar8 = ipmi_ioctl_func(plVar1,0x222008,&callbackBuffer);
      local_68[0] = (undefined4)uVar8;
      if ((5 < DAT_140014088) && (uVar8 = _tlgKeywordOn(uVar8 & 0xffffffff,1), (char)uVar8 != '\0'))
      {
        local_40 = local_68;
        local_38 = 4;
        uVar8 = _tlgWriteTransfer_EtwWriteTransfer
                          (local_60,&DAT_140010d1a,puVar10,param_4,3,(undefined8 *)local_60);
      }
      return CONCAT71((int7)(uVar8 >> 8),1);
    }
  }
  return uVar8 & 0xffffffffffffff00;
}



===== WriteOSREC2SEL @ 1400039dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

byte WriteOSREC2SEL(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  byte *pbVar8;
  uint uVar9;
  byte bVar10;
  void *_Size;
  byte bVar11;
  undefined7 uVar12;
  char cVar13;
  void *pvVar14;
  longlong lVar15;
  undefined1 auStackY_318 [32];
  char local_2e8 [4];
  uint local_2e4 [3];
  undefined4 local_2d8;
  undefined1 local_2d4;
  undefined4 local_2d3;
  undefined2 local_2cf;
  undefined1 uStack_2cd;
  undefined4 uStack_2cc;
  undefined1 uStack_2c8;
  undefined1 uStack_2c7;
  undefined1 uStack_2c6;
  char cStack_2c5;
  undefined4 uStack_2c4;
  undefined1 uStack_2c0;
  short local_2be;
  char local_2bc;
  undefined8 local_88 [4];
  uint *local_68;
  undefined8 local_60;
  char *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  bVar11 = (byte)param_4;
  uVar12 = (undefined7)((ulonglong)param_4 >> 8);
  local_48 = __security_cookie ^ (ulonglong)auStackY_318;
  _Size = (void *)0x248;
  memset(&local_2d8,0,0x248);
  bVar10 = 0;
  lVar6 = 2;
  if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(2,1), (char)uVar4 != '\0')) {
    _tlgWriteTransfer_EtwWriteTransfer
              (lVar6,&DAT_140010b92,_Size,CONCAT71(uVar12,bVar11),(int)lVar6,local_88);
    lVar6 = 2;
  }
  local_2d4 = *(undefined1 *)(param_1 + 0x159);
  if (*(int *)(param_2 + 0xc) == 6) {
    if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar6,1), (char)uVar4 != '\0')) {
      _tlgWriteTransfer_EtwWriteTransfer
                (lVar6,&DAT_140010b64,_Size,CONCAT71(uVar12,bVar11),(int)lVar6,local_88);
    }
    uVar4 = (ulonglong)*(uint *)(param_2 + 0x10);
    if (*(uint *)(param_2 + 0x10) != 0x10) goto LAB_140003fcc;
    local_2d3 = 0x44280010;
    local_2bc = -1;
    uVar5 = IpmiComputeBufferResponseLength(0x10);
    _Size = (void *)(uVar4 & 0xffffffff);
    local_2be = (short)uVar5;
    memmove(&local_2cf,(void *)(param_2 + 0x14),(size_t)_Size);
    uVar2 = IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
    lVar6 = param_1;
    if (1 < DAT_140014088) {
      uVar7 = 1;
      uVar4 = _tlgKeywordOn(param_1,1);
      lVar6 = param_1;
      if ((char)uVar4 != '\0') {
        local_50 = uVar7;
        local_68 = local_2e4;
        local_2e8[0] = local_2bc;
        local_58 = local_2e8;
        local_60 = 4;
        local_2e4[0] = uVar2;
        _tlgWriteTransfer_EtwWriteTransfer
                  (param_1,&DAT_140010982,_Size,CONCAT71(uVar12,bVar11),4,local_88);
        lVar6 = param_1;
      }
    }
    if ((uVar2 != 0) || (local_2bc != '\0')) {
      if (DAT_140014088 < 2) goto LAB_140003fcc;
      uVar7 = 1;
      uVar4 = _tlgKeywordOn(lVar6,1);
      if ((char)uVar4 == '\0') goto LAB_140003fcc;
      local_50 = uVar7;
      local_68 = local_2e4;
      pbVar8 = &DAT_140010664;
      local_2e8[0] = local_2bc;
      local_2e4[0] = uVar2;
      goto LAB_140003f9c;
    }
  }
  else if (*(int *)(param_2 + 0xc) == 9) {
    if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar6,1), (char)uVar4 != '\0')) {
      _tlgWriteTransfer_EtwWriteTransfer
                (lVar6,&DAT_140010c51,_Size,CONCAT71(uVar12,bVar11),(int)lVar6,local_88);
    }
    local_2d3 = 0x2100008;
    uStack_2c4 = CONCAT31(uStack_2c4._1_3_,0xff);
    uVar4 = IpmiComputeBufferResponseLength(8);
    uStack_2c6 = (undefined1)uVar4;
    cStack_2c5 = (char)(uVar4 >> 8);
    local_2cf = 0x441;
    uStack_2cd = 0x20;
    uStack_2cc = 0xff016f00;
    uStack_2c8 = 0xff;
    lVar6 = param_1;
    uVar2 = IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
    lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),(char)uStack_2c4);
    _Size = (void *)(ulonglong)uVar2;
    if (((uVar2 != 0) || ((char)uStack_2c4 != '\0')) || (CONCAT11(cStack_2c5,uStack_2c6) != 0)) {
      if (DAT_140014088 < 2) goto LAB_140003fcc;
      uVar7 = 1;
      uVar4 = _tlgKeywordOn(lVar6,1);
      if ((char)uVar4 == '\0') goto LAB_140003fcc;
      local_68 = local_2e4;
      pbVar8 = &DAT_140010755;
      local_2e8[0] = (char)lVar6;
      local_2e4[0] = (uint)_Size;
      local_50 = uVar7;
      goto LAB_140003f9c;
    }
    local_2d3 = 0x44280010;
    local_2bc = -1;
    uVar4 = IpmiComputeBufferResponseLength(0x10);
    local_2be = (short)uVar4;
    uStack_2c4 = *(undefined4 *)KiBugCheckData_exref;
    local_2cf = 0;
    uStack_2cc = 0;
    uStack_2cd = 0xde;
    uStack_2c8 = 0x37;
    uStack_2c7 = 1;
    uStack_2c6 = 0;
    cStack_2c5 = 1;
    uStack_2c0 = 1;
    IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
    uVar2 = 1;
    lVar15 = 8;
    do {
      cVar13 = (char)uVar2 + '\x01';
      uStack_2c4 = *(undefined4 *)(KiBugCheckData_exref + lVar15);
      local_2cf = 0;
      uStack_2cc = 0;
      uStack_2cd = 0xde;
      uStack_2c8 = 0x37;
      uStack_2c7 = 1;
      uStack_2c6 = 0;
      uStack_2c0 = 1;
      cStack_2c5 = cVar13;
      IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
      local_2cf = 0;
      uStack_2cc = 0;
      uStack_2c4 = (undefined4)((ulonglong)*(undefined8 *)(KiBugCheckData_exref + lVar15) >> 0x20);
      uStack_2cd = 0xde;
      uStack_2c8 = 0x37;
      uStack_2c7 = 1;
      uStack_2c6 = 0;
      uStack_2c0 = 1;
      lVar6 = param_1;
      cStack_2c5 = cVar13;
      IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
      uVar2 = uVar2 + 1;
      lVar15 = lVar15 + 8;
    } while (uVar2 < 5);
  }
  else {
    if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar6,1), (char)uVar4 != '\0')) {
      _tlgWriteTransfer_EtwWriteTransfer
                (lVar6,&DAT_140010485,_Size,CONCAT71(uVar12,bVar11),(int)lVar6,local_88);
    }
    local_2d3 = 0x2100008;
    uStack_2c4 = CONCAT31(uStack_2c4._1_3_,0xff);
    uVar4 = IpmiComputeBufferResponseLength(8);
    uStack_2c6 = (undefined1)uVar4;
    cStack_2c5 = (char)(uVar4 >> 8);
    local_2cf = 0x441;
    uStack_2cd = 0x30;
    uStack_2cc = 0xff016f00;
    uStack_2c8 = 0xff;
    lVar6 = param_1;
    uVar2 = IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
    lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),(char)uStack_2c4);
    _Size = (void *)(ulonglong)uVar2;
    if ((uVar2 != 0) || ((char)uStack_2c4 != '\0')) {
      if (DAT_140014088 < 2) goto LAB_140003fcc;
      uVar7 = 1;
      uVar4 = _tlgKeywordOn(lVar6,1);
      if ((char)uVar4 == '\0') goto LAB_140003fcc;
      local_68 = local_2e4;
      pbVar8 = &DAT_140010e3d;
      local_2e8[0] = (char)lVar6;
      local_2e4[0] = (uint)_Size;
      local_50 = uVar7;
LAB_140003f9c:
      local_58 = local_2e8;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar6,pbVar8,_Size,CONCAT71(uVar12,bVar11),4,local_88);
      goto LAB_140003fcc;
    }
    if (5 < DAT_140014088) {
      uVar7 = 1;
      uVar4 = _tlgKeywordOn(lVar6,1);
      if ((char)uVar4 != '\0') {
        local_68 = local_2e4;
        local_2e4[0] = 0;
        local_58 = local_2e8;
        local_60 = 4;
        local_2e8[0] = '\0';
        local_50 = uVar7;
        _tlgWriteTransfer_EtwWriteTransfer
                  (4,&DAT_140010b14,_Size,CONCAT71(uVar12,bVar11),4,local_88);
      }
    }
    local_2d3 = 0x44280010;
    local_2bc = -1;
    uVar4 = IpmiComputeBufferResponseLength(0x10);
    bVar11 = 4;
    local_2be = (short)uVar4;
    _Size = (void *)(param_2 + 0xc);
    AssembleOSRECBody((undefined8 *)&local_2cf,0,_Size,4);
    cVar13 = '\x01';
    iVar3 = IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
    lVar6 = 0;
    if (((iVar3 != 0) || (local_2bc != '\0')) || (local_2be != 2)) goto LAB_140003fcc;
    uVar2 = *(uint *)(param_2 + 0x10);
    pvVar14 = (void *)(param_2 + 0x14);
    if ((uVar2 != 0) && ((uVar9 = 0x100, 0x100 < uVar2 || (uVar9 = uVar2, uVar2 != 0)))) {
      uVar2 = 0;
      do {
        uVar1 = uVar2 + 4;
        if (uVar9 < uVar1) {
          uVar2 = uVar9 - uVar2;
        }
        else {
          uVar2 = 4;
        }
        bVar11 = (byte)uVar2;
        _Size = pvVar14;
        AssembleOSRECBody((undefined8 *)&local_2cf,cVar13,pvVar14,bVar11);
        pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar2);
        cVar13 = cVar13 + '\x01';
        iVar3 = IpmiDrvWriteSel(param_1,&local_2d8,_Size,CONCAT71(uVar12,bVar11));
        lVar6 = 0;
        if (((iVar3 != 0) || (local_2bc != '\0')) || (local_2be != 2)) goto LAB_140003fcc;
        uVar2 = uVar1;
      } while (uVar1 < uVar9);
    }
  }
  bVar10 = 1;
LAB_140003fcc:
  if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar6,1), (char)uVar4 != '\0')) {
    local_68 = local_2e4;
    local_2e4[0] = (uint)bVar10;
    local_60 = 4;
    _tlgWriteTransfer_EtwWriteTransfer
              ((ulonglong)bVar10,&DAT_140010561,_Size,CONCAT71(uVar12,bVar11),3,local_88);
  }
  return bVar10;
}



===== WriteShutdown2SEL @ 14000405c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WriteShutdown2SEL(longlong *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  byte *pbVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  int *piVar9;
  int *piVar10;
  undefined7 uVar11;
  uint uVar12;
  undefined1 auStackY_418 [32];
  int local_3e8;
  undefined1 local_3e4 [4];
  uint local_3e0 [2];
  undefined8 local_3d8;
  undefined8 uStack_3d0;
  longlong local_3c8 [2];
  undefined4 local_3b8;
  undefined1 local_3b4;
  undefined4 local_3b3;
  undefined8 local_3af;
  short local_39e;
  char local_39c;
  undefined8 local_168 [4];
  int *local_148;
  undefined4 local_140;
  undefined4 local_13c;
  undefined1 *local_138;
  undefined4 local_130;
  undefined4 local_12c;
  int local_128 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_418;
  local_3e8 = 0;
  local_3c8[0] = 0;
  local_3c8[1] = 0;
  local_3d8 = 0;
  uStack_3d0 = 0;
  RtlInitUnicodeString
            (local_3c8,
             L"\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Reliability\\shutdown"
            );
  RtlInitUnicodeString(&local_3d8,L"ReasonCode");
  local_3e0[0] = 4;
  piVar10 = &local_3e8;
  iVar1 = QueryConfigFromRegistry
                    (local_3c8,(longlong)&local_3d8,(undefined8 *)0x4,piVar10,local_3e0,'\0');
  if (iVar1 == 0) {
    uVar8 = 0x248;
    memset(&local_3b8,0,0x248);
    local_3b4 = *(undefined1 *)((longlong)param_1 + 0x159);
    local_3b3 = 0x2100008;
    AssembleShutdownHead((undefined4 *)&local_3af);
    uVar7 = (ulonglong)(ushort)local_3b3;
    *(undefined1 *)((longlong)&local_3af + uVar7 + 3) = 0xff;
    uVar3 = IpmiComputeBufferResponseLength((ushort)local_3b3);
    *(short *)((longlong)&local_3af + uVar7 + 1) = (short)uVar3;
    plVar4 = param_1;
    iVar1 = ipmi_send_request(param_1,&local_3b8);
    if ((iVar1 < 0) || (*(char *)((longlong)&local_3af + uVar7 + 3) != '\0')) {
      if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(plVar4,1), (char)uVar3 != '\0')) {
        local_13c = 0;
        local_12c = 0;
        local_148 = &local_3e8;
        local_3e4[0] = *(undefined1 *)((longlong)&local_3af + uVar7 + 3);
        local_138 = local_3e4;
        local_140 = 4;
        local_130 = 1;
        local_3e8 = iVar1;
        _tlgWriteTransfer_EtwWriteTransfer(plVar4,&DAT_140010a34,uVar8,piVar10,4,local_168);
      }
      return iVar1;
    }
    local_3b3 = 0x44280010;
    local_39c = -1;
    uVar3 = IpmiComputeBufferResponseLength(0x10);
    piVar10 = (int *)CONCAT71((int7)((ulonglong)piVar10 >> 8),4);
    local_39e = (short)uVar3;
    piVar9 = &local_3e8;
    AssembleShutdownBody(&local_3af,0,piVar9,4);
    plVar4 = param_1;
    iVar1 = ipmi_send_request(param_1,&local_3b8);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_39c != '\0') {
      return iVar1;
    }
    if (local_39e != 2) {
      return iVar1;
    }
    if ((char)param_1[0x41] == '\0') {
      local_3e0[0] = 0x100;
      RtlInitUnicodeString(&local_3d8,L"Comment");
      piVar10 = local_128;
      piVar9 = (int *)0x1;
      plVar4 = local_3c8;
      iVar2 = QueryConfigFromRegistry
                        (plVar4,(longlong)&local_3d8,(undefined8 *)0x1,piVar10,local_3e0,'\x01');
      if (iVar2 != 0) goto LAB_14000439b;
      uVar6 = local_3e0[0];
      if ((local_3e0[0] != 0) && (local_3e0[0] - 2 < 0xfe)) {
        uVar6 = local_3e0[0] - 2;
      }
      uVar3 = 0;
      if (uVar6 != 0) {
        do {
          uVar12 = (int)uVar3 + 4;
          uVar11 = (undefined7)((ulonglong)piVar10 >> 8);
          if (uVar6 < uVar12) {
            piVar10 = (int *)CONCAT71(uVar11,(char)uVar6 - (char)uVar3);
          }
          else {
            piVar10 = (int *)CONCAT71(uVar11,4);
          }
          piVar9 = (int *)((longlong)local_128 + uVar3);
          AssembleShutdownBody(&local_3af,1,piVar9,(byte)piVar10);
          plVar4 = param_1;
          iVar1 = ipmi_send_request(param_1,&local_3b8);
          if (((iVar1 < 0) || (local_39c != '\0')) || (local_39e != 2)) {
            if ((DAT_140014088 < 6) || (uVar3 = _tlgKeywordOn(plVar4,1), (char)uVar3 == '\0'))
            goto LAB_1400043a0;
            pbVar5 = &DAT_140010852;
            goto LAB_1400042e7;
          }
          uVar3 = (ulonglong)uVar12;
        } while (uVar12 < uVar6);
      }
    }
    if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(plVar4,1), (char)uVar3 != '\0')) {
      pbVar5 = &DAT_140010822;
LAB_1400042e7:
      local_13c = 0;
      local_148 = &local_3e8;
      local_140 = 4;
      local_3e8 = iVar1;
      _tlgWriteTransfer_EtwWriteTransfer(plVar4,pbVar5,piVar9,piVar10,3,local_168);
    }
  }
  else {
LAB_14000439b:
    iVar1 = -0x3fffffff;
  }
LAB_1400043a0:
  return iVar1;
}



===== _tlgDefineProvider_annotation__TlgIpmiLoggerProv @ 1400043d8 =====

void _tlgDefineProvider_annotation__TlgIpmiLoggerProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400043e4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001337f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000440c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004560 =====

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



===== CommitMsrDumpTime @ 1400045e4 =====

void CommitMsrDumpTime(void)

{
  RtlWriteRegistryValue(2,L"IPMI\\Policy",L"DumpTime",4,&IpmiPolicyDumpTimeStamp,4);
  return;
}



===== DispatchWmi @ 140004630 =====

undefined4 DispatchWmi(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
  }
  uVar2 = WmiSystemControl(&libinfo,param_1,param_2,local_res8);
  if (local_res8[0] != 0) {
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,uVar2);
  }
  return uVar2;
}



===== ExecuteMethod @ 140004730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ExecuteMethod(longlong param_1,undefined8 param_2,undefined *param_3,undefined8 param_4,
                       uint param_5,uint param_6,uint param_7,uint *param_8)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int *piVar10;
  undefined *puVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  wchar_t *pwVar14;
  undefined *puVar15;
  undefined1 auStackY_358 [32];
  uint local_308;
  uint local_304;
  uint local_300 [2];
  undefined8 local_2f8;
  longlong local_2f0;
  undefined8 local_2e0 [4];
  uint *local_2c0;
  undefined4 local_2b8;
  undefined4 local_2b4;
  char local_2a8 [304];
  char local_178 [304];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_358;
  uVar3 = 0;
  local_308 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_2f8 = param_2;
  local_2f0 = param_1;
  if (5 < DAT_140014088) {
    uVar7 = param_4;
    uVar6 = _tlgKeywordOn(param_1,2);
    if ((char)uVar6 != '\0') {
      local_304 = 0;
      local_2c0 = &local_304;
      local_2b4 = 0;
      local_2b8 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011100,param_3,uVar7,3,local_2e0);
    }
  }
  if ((int)param_4 != 0) {
    uVar3 = WmiCompleteRequest();
    uVar6 = (ulonglong)uVar3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar6;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar6;
    }
    uVar12 = 0x15;
LAB_140004825:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
             &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,(int)uVar6);
    return uVar6;
  }
  uVar7 = 0x15;
  if ((*(short *)(lVar1 + 0x140) != 0x15) && (*(short *)(lVar1 + 0x140) != 0x20)) {
    uVar3 = WmiCompleteRequest();
    uVar6 = (ulonglong)uVar3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar6;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar6;
    }
    uVar12 = 0x16;
    goto LAB_140004825;
  }
  if (*(int *)(lVar1 + 0x124) != 1) {
    uVar3 = WmiCompleteRequest();
    uVar6 = (ulonglong)uVar3;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar6;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar6;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
    return uVar6;
  }
  if (param_5 < 8) {
    if (param_5 == 7) {
      IpmiPolicyClearDump = (char)*param_8;
      local_304 = (uint)(IpmiPolicyClearDump != '\0');
      pwVar14 = L"ClearDump";
      goto LAB_14000504d;
    }
    if (param_5 == 1) {
      local_300[0] = CONCAT22(local_300[0]._2_2_,0x122);
      if (param_6 == param_8[1] + 8) {
        if (param_7 < 9) {
          uVar3 = 0xc0000023;
          local_308 = 0x12a;
          goto LAB_14000507c;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            param_3 = &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids;
            uVar7 = 0x19;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                    &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
                uVar7 = 0x1a;
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,param_3,
                         (uint)(byte)*param_8);
              }
              if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
                  uVar7 = 0x1b;
                  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,param_3,
                           (uint)*(byte *)((longlong)param_8 + 3));
                }
                if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
                    uVar7 = 0x1c;
                    WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,
                             (uint)*(byte *)((longlong)param_8 + 1));
                  }
                  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
                      uVar7 = 0x1d;
                      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,param_3,
                               (uint)*(byte *)((longlong)param_8 + 2));
                    }
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                      uVar7 = 0x1e;
                      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,param_3,param_8[1]);
                    }
                  }
                }
              }
            }
          }
          uVar6 = 0;
          if (param_8[1] != 0) {
            do {
              uVar3 = (int)uVar6 + 8;
              if ((param_6 <= uVar3) || (param_7 <= uVar3)) break;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                uVar7 = 0x1f;
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,
                         (uint)*(byte *)(uVar6 + 8 + (longlong)param_8));
              }
              uVar3 = (int)uVar6 + 1;
              uVar6 = (ulonglong)uVar3;
            } while (uVar3 < param_8[1]);
          }
        }
        uVar8 = AcquireStopLock((char *)(lVar1 + 0xb0));
        uVar3 = (uint)uVar8;
        if (-1 < (int)uVar3) {
          uVar6 = CONCAT71((int7)((ulonglong)param_3 >> 8),*(undefined1 *)((longlong)param_8 + 2));
          iVar4 = ipmi_send_ioctl(lVar1,uVar7,*(undefined1 *)((longlong)param_8 + 2),
                                  *(byte *)((longlong)param_8 + 1) & 3 | (char)*param_8 << 2,
                                  *(undefined1 *)((longlong)param_8 + 3),(ushort)param_8[1],
                                  param_8 + 2,(ushort *)local_300,local_2a8);
          ReleaseStopLock(lVar1 + 0xb0);
          if (iVar4 == 0) {
            uVar13 = (ulonglong)(ushort)local_300[0];
            param_8[1] = local_300[0] & 0xffff;
            if (param_7 < (local_300[0] & 0xffff) + 8) {
              uVar3 = 0xc0000023;
            }
            else {
              uVar6 = (ulonglong)(ushort)local_300[0];
              memmove(param_8 + 2,local_2a8,uVar6);
              uVar13 = (ulonglong)param_8[1];
              *(char *)param_8 = local_2a8[0];
            }
          }
          else {
            uVar3 = 0;
            param_8[1] = 1;
            local_2a8[0] = -1;
            uVar13 = 1;
            *(undefined1 *)param_8 = 0xff;
          }
          local_308 = (int)uVar13 + 8;
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              WPP_SF_LLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,uVar6,local_308,
                         (char)*param_8,(char)uVar13);
            }
            uVar13 = 0;
            if (param_8[1] != 0) {
              do {
                uVar5 = (int)uVar13 + 8;
                if ((param_6 <= uVar5) || (param_7 <= uVar5)) break;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                  WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,uVar6,
                           (uint)*(byte *)(uVar13 + 8 + (longlong)param_8));
                }
                uVar5 = (int)uVar13 + 1;
                uVar13 = (ulonglong)uVar5;
              } while (uVar5 < param_8[1]);
            }
          }
          goto LAB_14000507c;
        }
        uVar3 = 0xc0000120;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000507c;
        uVar12 = 0x20;
LAB_140004acb:
        uVar3 = 0xc0000120;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
        goto LAB_14000507c;
      }
    }
    else {
      if (param_5 == 2) {
        local_300[0] = local_300[0] & 0xffffff00;
        if (param_7 < 2) {
          uVar3 = 0xc0000023;
        }
        else {
          uVar7 = AcquireStopLock((char *)(lVar1 + 0xb0));
          if ((int)(uint)uVar7 < 0) {
            uVar3 = 0xc0000120;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000507c;
            uVar12 = 0x18;
            goto LAB_140004acb;
          }
          uVar6 = ipmi_ioctl_func((longlong *)(lVar1 + 0x138),0x222004,(char *)local_300);
          ReleaseStopLock(lVar1 + 0xb0);
          uVar3 = (uint)uVar6;
          if (uVar3 == 0) {
            *(byte *)((longlong)param_8 + 1) = (byte)local_300[0];
            bVar2 = (byte)local_300[0] >> 2 & 1;
            uVar3 = (uint)uVar7;
          }
          else {
            *(undefined1 *)((longlong)param_8 + 1) = 0;
            bVar2 = 0;
          }
          *(byte *)param_8 = bVar2;
        }
LAB_140004ba3:
        local_308 = 2;
        goto LAB_14000507c;
      }
      if (param_5 == 3) {
        if ((0xf < param_6) && (param_6 == param_8[2] + 0xc)) {
          local_300[0] = CONCAT22(local_300[0]._2_2_,0x122);
          if (param_7 < 9) {
            uVar3 = 0xc0000023;
            local_308 = 100;
            goto LAB_14000507c;
          }
          piVar10 = (int *)((ulonglong)param_8[1] + 0xf + (longlong)param_8 & 0xfffffffffffffffc);
          uVar6 = ((ulonglong)param_8[2] - (longlong)piVar10) + 0xc + (longlong)param_8;
          if (((3 < uVar6) && (*piVar10 == 1)) && (uVar6 == 0x14)) {
            uVar7 = AcquireStopLock((char *)(lVar1 + 0xb0));
            uVar3 = (uint)uVar7;
            if (-1 < (int)uVar3) {
              iVar4 = ipmi_send_ioctl(lVar1,param_8 + 3,*(undefined1 *)((longlong)param_8 + 2),
                                      *(byte *)((longlong)param_8 + 1) & 3 | (char)*param_8 << 2,
                                      *(undefined1 *)((longlong)param_8 + 3),(ushort)param_8[1],
                                      param_8 + 3,(ushort *)local_300,local_178);
              ReleaseStopLock(lVar1 + 0xb0);
              if (iVar4 == 0) {
                local_308 = local_300[0] & 0xffff;
                param_8[1] = local_300[0] & 0xffff;
                if (param_7 < (local_300[0] & 0xffff) + 8) {
                  uVar3 = 0xc0000023;
                }
                else {
                  memmove(param_8 + 2,local_178,(ulonglong)(ushort)local_300[0]);
                  local_308 = param_8[1];
                  *(char *)param_8 = local_178[0];
                }
              }
              else {
                uVar3 = 0;
                param_8[1] = 1;
                *(undefined1 *)param_8 = 0xff;
                local_308 = 1;
              }
              local_308 = local_308 + 8;
              goto LAB_14000507c;
            }
            uVar3 = 0xc0000120;
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000507c;
            uVar12 = 0x23;
            goto LAB_140004acb;
          }
        }
      }
      else {
        if (param_5 == 4) {
          if (param_7 < 2) {
            uVar3 = 0xc0000023;
            goto LAB_14000507c;
          }
          *(char *)param_8 = IpmiPolicyDoes0x80Dump;
          *(char *)((longlong)param_8 + 1) = IpmiPolicyDoes0x9cDump;
          uVar3 = 0;
          goto LAB_140004ba3;
        }
        if (param_5 != 5) {
          if (param_5 != 6) goto LAB_140004f6f;
          local_308 = 1;
          *(char *)param_8 = IpmiPolicyClearDump;
          goto LAB_14000507c;
        }
        if (1 < param_6) {
          IpmiPolicyDoes0x80Dump = (char)*param_8;
          IpmiPolicyDoes0x9cDump = *(char *)((longlong)param_8 + 1);
          local_300[0] = (uint)(IpmiPolicyDoes0x80Dump != '\0');
          local_304 = (uint)(IpmiPolicyDoes0x9cDump != '\0');
          RtlWriteRegistryValue(2,L"IPMI\\Policy",L"Dump0x80");
          pwVar14 = L"Dump0x9c";
          goto LAB_14000504d;
        }
      }
    }
LAB_14000497b:
    uVar3 = 0xc000000d;
    goto LAB_14000507c;
  }
  if (param_5 == 8) {
    local_304 = 1;
    SelCacheWorkerEnabled = 1;
    SelSignalWorkerEvent();
LAB_140005041:
    pwVar14 = L"SelCacheWorkerEnabled";
  }
  else {
    if (param_5 == 9) {
      local_304 = 0;
      SelCacheWorkerEnabled = 0;
      SelClearWorkerEvent();
      goto LAB_140005041;
    }
    if (param_5 == 10) {
      if (param_6 < 4) goto LAB_14000497b;
      SelCachePollingInterval = *param_8;
      pwVar14 = L"SelCachePollingInterval";
      if (SelCachePollingInterval < 1000) {
        SelCachePollingInterval = 1000;
      }
    }
    else if (param_5 == 0xb) {
      if (param_6 < 4) goto LAB_14000497b;
      SelCacheReadRecordLimit = *param_8;
      if (SelCacheReadRecordLimit < 0x400) {
        if (SelCacheReadRecordLimit == 0) {
          SelCacheReadRecordLimit = 1;
        }
      }
      else {
        SelCacheReadRecordLimit = 0x400;
      }
      pwVar14 = L"SelCacheReadRecordLimit";
    }
    else {
      if (param_5 == 0xc) {
        IpmiPolicyMsrDumpEnabled = 1;
        local_304 = 1;
      }
      else {
        if (param_5 != 0xd) {
LAB_140004f6f:
          uVar6 = WmiCompleteRequest();
          return uVar6;
        }
        local_304 = 0;
        IpmiPolicyMsrDumpEnabled = 0;
      }
      pwVar14 = L"EnableMsrDump";
    }
  }
LAB_14000504d:
  RtlWriteRegistryValue(2,L"IPMI\\Policy",pwVar14);
  uVar3 = 0;
LAB_14000507c:
  uVar13 = (ulonglong)local_308;
  puVar15 = (undefined *)(ulonglong)uVar3;
  uVar3 = WmiCompleteRequest(local_2f0,local_2f8);
  uVar6 = (ulonglong)uVar3;
  puVar11 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (puVar15 = (undefined *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
     (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar11 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar15 = &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids;
    uVar13 = (ulonglong)uVar3;
    WPP_SF_D(puVar11,0x24,&WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,uVar3);
  }
  if (DAT_140014088 < 6) {
    return uVar6;
  }
  uVar9 = _tlgKeywordOn(puVar11,2);
  if ((char)uVar9 == '\0') {
    return uVar6;
  }
  local_2b4 = 0;
  local_2c0 = &local_304;
  local_2b8 = 4;
  local_304 = uVar3;
  _tlgWriteTransfer_EtwWriteTransfer(puVar11,&DAT_1400110d4,puVar15,uVar13,3,local_2e0);
  return uVar6;
}



===== FunctionControl @ 140005150 =====

void FunctionControl(undefined8 param_1,undefined8 param_2)

{
  WmiCompleteRequest(param_1,param_2,0,0,0);
  return;
}



===== GetRegValues @ 140005178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetRegValues(void)

{
  int iVar1;
  code *pcVar2;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  undefined4 local_274;
  int local_270;
  undefined4 local_26c;
  undefined4 local_268 [2];
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 local_248;
  undefined4 local_240;
  wchar_t *local_238;
  int *local_230;
  undefined4 local_228;
  undefined8 local_220;
  undefined4 local_218;
  undefined8 local_210;
  undefined4 local_208;
  wchar_t *local_200;
  int *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1e8;
  undefined4 local_1e0;
  undefined8 local_1d8;
  undefined4 local_1d0;
  wchar_t *local_1c8;
  int *local_1c0;
  undefined4 local_1b8;
  undefined8 local_1b0;
  undefined4 local_1a8;
  undefined8 local_1a0;
  undefined4 local_198;
  wchar_t *local_190;
  undefined4 *local_188;
  undefined4 local_180;
  undefined8 local_178;
  undefined4 local_170;
  undefined8 local_168;
  undefined4 local_160;
  wchar_t *local_158;
  int *local_150;
  undefined4 local_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined4 local_128;
  wchar_t *local_120;
  undefined4 *local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  wchar_t *local_e8;
  undefined4 *local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  int *local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_288 = 1;
  local_284 = 1;
  local_238 = L"Dump0x80";
  local_230 = &local_288;
  local_200 = L"Dump0x9c";
  local_1f8 = &local_284;
  local_280 = 0;
  local_1c8 = L"ClearDump";
  local_1c0 = &local_280;
  local_190 = L"DumpTime";
  local_188 = &local_274;
  local_158 = L"SelCacheWorkerEnabled";
  local_150 = &local_270;
  local_120 = L"SelCachePollingInterval";
  local_118 = &local_26c;
  local_e8 = L"SelCacheReadRecordLimit";
  local_e0 = local_268;
  local_b0 = L"EnableMsrDump";
  local_a8 = &local_27c;
  local_27c = 0;
  local_274 = 0;
  local_270 = 0;
  local_26c = 10000;
  local_268[0] = 0x10;
  local_278 = 1;
  local_248 = 0;
  local_240 = 0x20;
  local_228 = 0;
  local_220 = 0;
  local_218 = 0;
  local_210 = 0;
  local_208 = 0x20;
  local_1f0 = 0;
  local_1e8 = 0;
  local_1e0 = 0;
  local_1d8 = 0;
  local_1d0 = 0x20;
  local_1b8 = 0;
  local_1b0 = 0;
  local_1a8 = 0;
  local_1a0 = 0;
  local_198 = 0x20;
  local_180 = 0;
  local_178 = 0;
  local_170 = 0;
  local_168 = 0;
  local_160 = 0x20;
  local_148 = 0;
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0x20;
  local_110 = 0;
  local_108 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_f0 = 0x20;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0x20;
  local_a0 = 0;
  local_80 = 0x20;
  local_78 = L"IpmiConfigureInterrupts";
  local_70 = &local_278;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_260 = 0;
  uStack_258 = 0;
  RtlInitUnicodeString(&local_260,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_260);
  local_298 = 0;
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar2)(2,L"IPMI\\Policy",&local_248,0);
  if (-1 < iVar1) {
    IpmiPolicyDoes0x80Dump = local_288 != 0;
    IpmiPolicyDumpTimeStamp = local_274;
    IpmiPolicyDoes0x9cDump = local_284 != 0;
    IpmiPolicyClearDump = local_280 != 0;
    IpmiPolicyMsrDumpEnabled = local_27c != 0;
    IpmiPolicyConfigureInterrupts = local_278 != 0;
    if (local_270 == 0) {
      SelCacheWorkerEnabled = 0;
      SelClearWorkerEvent();
    }
    else {
      SelCacheWorkerEnabled = 1;
      SelSignalWorkerEvent();
    }
    SelCachePollingInterval = local_26c;
    SelCacheReadRecordLimit = local_268[0];
  }
  return;
}



===== QueryRegInfo @ 1400054b0 =====

undefined8
QueryRegInfo(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
            undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
  }
  *param_2 = 0x20;
  *param_4 = &servkey;
  RtlInitUnicodeString(param_5,L"MofResource");
  *param_6 = *(undefined8 *)(lVar1 + 0x18);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,0);
  }
  return 0;
}



===== SetDataItem @ 140005580 =====

void SetDataItem(undefined8 param_1,undefined8 param_2)

{
  WmiCompleteRequest(param_1,param_2,0xc00002c7,0,0);
  return;
}



===== WPP_SF_ @ 1400055ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_L @ 1400055d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_LLL @ 140005620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,0x21,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WmiInitialize @ 140005684 =====

undefined4 WmiInitialize(undefined8 param_1)

{
  undefined4 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
  }
  uVar1 = IoWMIRegistrationControl(param_1,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,uVar1);
  }
  return uVar1;
}



===== WmiTerminate @ 140005718 =====

undefined4 WmiTerminate(undefined8 param_1)

{
  undefined4 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids);
  }
  uVar1 = IoWMIRegistrationControl(param_1,2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_0d53edb7bab8353abd82f8537252e9cf_Traceguids,uVar1);
  }
  return uVar1;
}



===== BmcWheaAddErrorSource @ 1400057ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BmcWheaAddErrorSource(void)

{
  if (IpmipWheaInitialized == '\0') {
    _DAT_140014674 = 0;
    _DAT_14001465c = 1;
    _DAT_140014668 = 1;
    _IpmipBmcErrorSource = 0x3cc;
    _DAT_140014654 = 10;
    _DAT_140014658 = 0xe;
    _DAT_140014660 = 0x18000;
    WheaAddErrorSource(&IpmipBmcErrorSource,0);
  }
  return;
}



===== BmcWheaCorrectErrorSource @ 140005820 =====

undefined8 BmcWheaCorrectErrorSource(longlong param_1,int *param_2)

{
  if (IpmipWheaRemoved == '\x01') {
    return 0xc0000001;
  }
  *param_2 = 0xc0;
  *param_2 = *(int *)(param_1 + 0x10) + 0xc0;
  return 0;
}



===== BmcWheaCreateErrorRecord @ 140005850 =====

undefined8 BmcWheaCreateErrorRecord(longlong param_1,longlong param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  if (IpmipWheaRemoved == '\x01') {
    uVar3 = 0xc0000001;
  }
  else if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (void *)0x0)) ||
          (*(int *)(param_1 + 0x18) == 0)) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar5 = *(int *)(param_2 + 0x54) + 0x85 + *(int *)(param_1 + 0x18) * 0x48;
    if (param_4 < uVar5) {
      *(uint *)(param_2 + 0x54) = (*(int *)(param_2 + 0x54) - uVar5) + param_4;
    }
    memset(param_3,0,(ulonglong)param_4);
    WheaInitializeRecordHeader(param_3);
    *(undefined2 *)((longlong)param_3 + 10) = 1;
    uVar1 = *(undefined4 *)(param_2 + 0x14);
    *(uint *)((longlong)param_3 + 0x68) = *(uint *)((longlong)param_3 + 0x68) | 2;
    *(undefined4 *)((longlong)param_3 + 0xc) = uVar1;
    *(undefined8 *)((longlong)param_3 + 0x50) = 0x43676494487565ba;
    *(undefined8 *)((longlong)param_3 + 0x58) = 0xf6223589ff4eca95;
    *(uint *)((longlong)param_3 + 0x14) = param_4;
    uVar5 = *(int *)(param_1 + 0x18) * 0x48 + 0x80;
    *(uint *)((longlong)param_3 + 0x80) = uVar5;
    iVar2 = *(int *)(param_2 + 0x54);
    *(uint *)((longlong)param_3 + 0x8c) = *(uint *)((longlong)param_3 + 0x8c) | 1;
    *(int *)((longlong)param_3 + 0x84) = iVar2 + 5;
    *(undefined2 *)((longlong)param_3 + 0x88) = 0x300;
    RtlStringCbPrintfA((char *)((longlong)param_3 + 0xb4),0x14,"BMC Buffer %d",
                       (ulonglong)*(byte *)(param_2 + 0x50));
    puVar4 = (undefined1 *)((ulonglong)uVar5 + (longlong)param_3);
    *(undefined8 *)((longlong)param_3 + 0x90) = 0x46679b061c15b445;
    *(undefined8 *)((longlong)param_3 + 0x98) = 0x388b856c03325ac;
    *(undefined4 *)((longlong)param_3 + 0xb0) = *(undefined4 *)(param_2 + 0x14);
    *puVar4 = *(undefined1 *)(param_2 + 0x50);
    *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(param_2 + 0x54);
    memmove(puVar4 + 5,(void *)(param_2 + 0x58),(ulonglong)*(uint *)(param_2 + 0x54));
    uVar3 = 0;
  }
  return uVar3;
}



===== BmcWheaInit @ 1400059bc =====

void BmcWheaInit(void)

{
  WheaConfigureErrorSource(0xe,&BmcpErrorSourceConfiguration);
  IpmipWheaRemoved = 0;
  return;
}



===== BmcWheaReportError @ 1400059ec =====

void BmcWheaReportError(undefined1 param_1,uint param_2,void *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  if (IpmipWheaInitialized != '\0') {
    puVar2 = (undefined4 *)ExAllocatePool2(0x42,(ulonglong)param_2 + 0x5c,0x61656857);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0x41454857;
      puVar2[2] = param_2 + 0x5c;
      puVar2[1] = 3;
      puVar2[4] = 6;
      puVar2[5] = 1;
      uVar1 = DAT_14001466c;
      puVar2[3] = puVar2[3] | 1;
      puVar2[6] = uVar1;
      puVar2[7] = 0xe;
      *(undefined8 *)(puVar2 + 8) = 0x43676494487565ba;
      *(undefined8 *)(puVar2 + 10) = 0xf6223589ff4eca95;
      puVar2[0xe] = 7;
      puVar2[0x10] = 0x50;
      puVar2[0x11] = param_2 + 0x5c;
      *(undefined1 *)(puVar2 + 0x14) = param_1;
      puVar2[0x15] = param_2;
      memmove(puVar2 + 0x16,param_3,(ulonglong)param_2);
      uVar3 = WheaGetErrorSource(puVar2[6]);
      PshedRetrieveErrorInfo(puVar2,uVar3);
      WheaReportHwError(puVar2);
      ExFreePoolWithTag(puVar2,0x61656857);
    }
  }
  return;
}



===== BmcWheaUninit @ 140005b14 =====

void BmcWheaUninit(void)

{
  WheaUnconfigureErrorSource(0xe);
  return;
}



===== RtlStringCbPrintfA @ 140005b38 =====

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



===== InitializeStopLock @ 140005bac =====

void InitializeStopLock(undefined1 *param_1)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 1;
    KeInitializeEvent(param_1 + 8,1,0);
  }
  return;
}



===== ReleaseStopLockAndWait @ 140005be0 =====

void ReleaseStopLockAndWait(undefined1 *param_1)

{
  int *piVar1;
  int iVar2;
  
  *param_1 = 1;
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (1 < iVar2) {
    KeWaitForSingleObject(param_1 + 8,0,0,0,0);
  }
  return;
}



===== DefaultPowerHandler @ 140005c24 =====

undefined4 DefaultPowerHandler(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar1 = PoCallDriver(*(undefined8 *)(param_1 + 0x10),param_2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,uVar1);
  }
  return uVar1;
}



===== DispatchPower @ 140005ce0 =====

int DispatchPower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined *puVar7;
  ulonglong uVar8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  pcVar6 = "";
  uVar8 = 1;
  uVar2 = IoAcquireRemoveLockEx(lVar1 + 0x90,param_2,"",1,0x20);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    PoStartNextPowerIrp(param_2);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      pcVar6 = &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,uVar2);
      uVar8 = uVar5;
    }
    iVar3 = CompleteRequest2(param_2,uVar2,pcVar6,uVar8);
  }
  else {
    if ((byte)(*(char *)(*(longlong *)(param_2 + 0xb8) + 1) - 2U) < 2) {
      puVar7 = (undefined *)0x494d5049;
      piVar4 = (int *)ExAllocatePool2(0x40);
      if (piVar4 == (int *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar7 = &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
        }
        PoStartNextPowerIrp(param_2);
        iVar3 = CompleteRequest2(param_2,0xc000009a,puVar7,uVar8);
      }
      else {
        *(longlong *)(piVar4 + 2) = lVar1;
        *(longlong *)(piVar4 + 4) = param_2;
        LOCK();
        UNLOCK();
        iVar3 = DAT_140014a1c + 1;
        DAT_140014a1c = DAT_140014a1c + 1;
        *piVar4 = iVar3;
        iVar3 = HandlePowerEvent((longlong)piVar4,0);
      }
    }
    else {
      iVar3 = DefaultPowerHandler(lVar1,param_2);
    }
    IoReleaseRemoveLockEx(lVar1 + 0x90,param_2,0x20);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar3);
    }
  }
  return iVar3;
}



===== GetLowestDevicePowerState @ 140005ec4 =====

int GetLowestDevicePowerState(longlong param_1,int param_2)

{
  int iVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  iVar1 = *(int *)(param_1 + 0xf0 + (longlong)param_2 * 4);
  if (iVar1 < 4) {
    iVar1 = 4;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar1);
  }
  return iVar1;
}



===== HandlePowerEvent @ 140005f5c =====

int HandlePowerEvent(longlong param_1,int param_2)

{
  byte *pbVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  code *pcVar11;
  
  iVar9 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (lVar3 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar10 = 0x13;
  }
  else {
    lVar4 = *(longlong *)(lVar3 + 0xb8);
    if (lVar4 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3ffffff3;
      }
      uVar10 = 0x14;
    }
    else {
      lVar5 = *(longlong *)(param_1 + 8);
      if (lVar5 != 0) {
        iVar8 = *(int *)(&DAT_14000f9a0 +
                        ((longlong)*(int *)(param_1 + 0x18) * 3 + (longlong)param_2) * 4);
LAB_14000604f:
        do {
          while( true ) {
            while (8 < iVar8) {
              if (iVar8 == 9) goto LAB_1400061c8;
              if ((iVar8 == 0xc) || (iVar8 == 0xd)) {
                iVar8 = *(int *)(param_1 + 0x1c);
                if ((-1 < iVar8) && (*(char *)(lVar4 + 1) == '\x02')) {
                  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(lVar5 + 0xd8);
                  *(undefined4 *)(lVar5 + 0xd8) = *(undefined4 *)(lVar4 + 0x18);
                  iVar9 = iVar8;
                }
              }
              else {
                if ((iVar8 != 0x10) && (iVar8 != 0x11)) goto LAB_140006332;
                if ((-1 < *(int *)(param_1 + 0x1c)) && (*(char *)(lVar4 + 1) == '\x02')) {
                  iVar9 = *(int *)(param_1 + 0x1c);
                }
              }
              iVar8 = 4;
            }
            if (iVar8 != 8) break;
LAB_1400061c8:
            if (*(char *)(lVar4 + 1) == '\x02') {
              *(undefined4 *)(lVar5 + 0xdc) = *(undefined4 *)(lVar4 + 0x18);
            }
            iVar8 = (-1 < *(int *)(param_1 + 0x1c)) + 4;
          }
          if (iVar8 == 0) goto LAB_140006332;
          if (iVar8 != 1) {
            if (iVar8 == 2) {
              PoStartNextPowerIrp(lVar3);
              *(int *)(lVar3 + 0x30) = iVar9;
              IofCompleteRequest(lVar3,0);
              goto LAB_140006337;
            }
            if (iVar8 == 3) {
LAB_140006332:
              iVar9 = -0x3fffffff;
              goto LAB_140006337;
            }
            if (iVar8 == 4) {
              PoStartNextPowerIrp(lVar3);
              *(undefined4 *)(lVar3 + 0x30) = *(undefined4 *)(param_1 + 0x1c);
              IofCompleteRequest(lVar3,0);
              IoReleaseRemoveLockEx(lVar5 + 0x90,lVar3,0x20);
              ExFreePoolWithTag(param_1,0x494d5049);
            }
            else {
              if (iVar8 != 5) goto LAB_140006332;
              *(uint *)(param_1 + 0x18) = (*(int *)(lVar5 + 0xdc) <= *(int *)(lVar4 + 0x18)) + 10;
              iVar8 = GetLowestDevicePowerState(lVar5,*(int *)(lVar4 + 0x18));
              *(int *)(param_1 + 0x20) = iVar8;
              uVar2 = *(undefined1 *)(lVar4 + 1);
              *(undefined1 *)(param_1 + 0x28) = uVar2;
              iVar8 = PoRequestPowerIrp(*(undefined8 *)(lVar5 + 0x18),uVar2,iVar8,
                                        PowerCompletionRoutine,param_1,0);
              if (iVar8 != 0x103) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                           &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar8);
                }
                *(int *)(param_1 + 0x1c) = iVar8;
                iVar8 = 4;
                goto LAB_14000604f;
              }
            }
            iVar9 = -0x3fffffea;
            goto LAB_140006337;
          }
          iVar9 = IoAcquireRemoveLockEx(lVar5 + 0x90,lVar3,"",1,0x20);
          if (iVar9 == 0) {
            if (*(int *)(lVar4 + 0x10) == 0) {
              iVar9 = (*(int *)(lVar5 + 0xdc) <= *(int *)(lVar4 + 0x18)) + 6;
            }
            else {
              iVar9 = 0xe;
              if (*(int *)(lVar5 + 0xd8) <= *(int *)(lVar4 + 0x18)) {
                iVar9 = 0xf;
              }
            }
            pcVar11 = MainSystemCompletionRoutine;
            *(int *)(param_1 + 0x18) = iVar9;
            pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
            puVar6 = *(undefined8 **)(lVar3 + 0xb8);
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
            lVar7 = *(longlong *)(lVar3 + 0xb8);
            if (*(int *)(lVar4 + 0x10) != 0) {
              pcVar11 = MainDeviceCompletionRoutine;
            }
            *(code **)(lVar7 + -0x10) = pcVar11;
            *(longlong *)(lVar7 + -8) = param_1;
            *(undefined1 *)(lVar7 + -0x45) = 0xe0;
            PoStartNextPowerIrp(lVar3);
            PoCallDriver(*(undefined8 *)(lVar5 + 0x10),lVar3);
            iVar9 = 0x103;
LAB_140006337:
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar9;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
              return iVar9;
            }
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                     &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar9);
            return iVar9;
          }
          iVar8 = 2;
        } while( true );
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3ffffff3;
      }
      uVar10 = 0x15;
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,0xc000000d);
  return -0x3ffffff3;
}



===== MainDeviceCompletionRoutine @ 140006390 =====

int MainDeviceCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  iVar2 = HandlePowerEvent(param_3,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar2);
  }
  return iVar2;
}



===== MainSystemCompletionRoutine @ 140006440 =====

int MainSystemCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_2 + 0x30);
  iVar2 = HandlePowerEvent(param_3,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids,iVar2);
  }
  return iVar2;
}



===== PowerCompletionRoutine @ 1400064f0 =====

void PowerCompletionRoutine(void)

{
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  *(undefined4 *)(in_R9 + 0x1c) = *in_stack_00000028;
  HandlePowerEvent(in_R9,2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_a64a6516c76d3c706cd782261bea4759_Traceguids);
  }
  return;
}



===== GetEnumerator @ 140006580 =====

int GetEnumerator(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  uint local_res8 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar5 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  iVar3 = IoGetDeviceProperty(*(undefined8 *)(lVar1 + 0x18),0xf,0,0,local_res8);
  uVar2 = local_res8[0];
  if (iVar3 == -0x3fffffdd) {
    lVar5 = ExAllocatePool2(0x102,local_res8[0],0x494d5049);
    if (lVar5 == 0) {
      iVar3 = -0x3fffffe9;
      goto LAB_1400066c5;
    }
    iVar3 = IoGetDeviceProperty(*(undefined8 *)(lVar1 + 0x18),0xf,uVar2,lVar5,local_res8);
  }
  if (-1 < iVar3) {
    RtlInitUnicodeString(&local_28,lVar5);
    RtlInitUnicodeString(&local_38,L"ACPI");
    iVar4 = RtlCompareUnicodeString(&local_28,&local_38,1);
    *param_2 = (uint)(iVar4 == 0);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x494d5049);
  }
LAB_1400066c5:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,iVar3);
  }
  return iVar3;
}



===== IpmiComputeBufferResponseLength @ 140006718 =====

ulonglong IpmiComputeBufferResponseLength(short param_1)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  ushort local_res10 [12];
  
  uVar3 = 0;
  local_res10[0] = 0;
  sVar2 = 4;
  uVar1 = RtlUShortAdd(4,6,local_res10);
  if (uVar1 == 0) {
    uVar1 = RtlUShortAdd(local_res10[0],sVar2,local_res10);
    if (uVar1 == 0) {
      uVar1 = RtlUShortAdd(local_res10[0],param_1,local_res10);
      if (((uVar1 == 0) && (local_res10[0] < 0x249)) &&
         (uVar3 = (ulonglong)(ushort)(0x248 - local_res10[0]),
         0x122 < (ushort)(0x248 - local_res10[0]))) {
        uVar3 = 0x122;
      }
    }
  }
  return uVar3 & 0xffff;
}



===== IpmiErrorCallback @ 1400067a0 =====

undefined8 IpmiErrorCallback(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
  UNLOCK();
  return 0;
}



===== RtlUShortAdd @ 1400067b4 =====

uint RtlUShortAdd(ushort param_1,short param_2,ushort *param_3)

{
  ushort uVar1;
  bool bVar2;
  
  uVar1 = param_2 + param_1;
  bVar2 = uVar1 < param_1;
  if (bVar2) {
    uVar1 = 0xffff;
  }
  *param_3 = uVar1;
  return -(uint)bVar2 & 0xc0000095;
}



===== acpi_ipmi_probe @ 1400067dc =====

int acpi_ipmi_probe(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_res18 [2];
  undefined1 auStackX_1a [6];
  
  auStackX_1a._1_5_ = SUB85((ulonglong)param_3 >> 0x18,0);
  _local_res18 = (uint3)(byte)param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0x21) = 0x20;
  _local_res18 = CONCAT71(stack0x00000019,2);
  iVar1 = acpi_get_integer(param_2,local_res18,0x5652535f);
  if (-1 < iVar1) {
    if (auStackX_1a._0_2_ == 0x100) {
      *(undefined2 *)(param_1 + 8) = 0x10;
    }
    else if (auStackX_1a._0_2_ == 0x150) {
      *(undefined2 *)(param_1 + 8) = 0x15;
    }
    else {
      if (auStackX_1a._0_2_ != 0x200) {
        iVar1 = -0x3ffffff3;
        goto LAB_1400068cb;
      }
      *(undefined2 *)(param_1 + 8) = 0x20;
    }
    _local_res18 = CONCAT71(stack0x00000019,1);
    iVar1 = acpi_get_integer(param_2,local_res18,0x5446495f);
    if (-1 < iVar1) {
      iVar2 = (int)auStackX_1a[0];
      *(int *)(param_1 + 0xc) = iVar2;
      if ((iVar2 != 1) && (iVar2 != 4)) {
        iVar1 = -0x3ffffff3;
      }
    }
  }
LAB_1400068cb:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,iVar1);
  }
  return iVar1;
}



===== ipmi_interface_abort @ 140006918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ipmi_interface_abort(longlong param_1)

{
  undefined4 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  if (*(code **)(&DAT_14000f010 + (ulonglong)*(byte *)(param_1 + 0xc) * 0x18) == (code *)0x0) {
    uVar1 = 0xc000003e;
  }
  else {
    uVar1 = (**(code **)(&DAT_14000f010 + (ulonglong)*(byte *)(param_1 + 0xc) * 0x18))(param_1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar1);
  }
  return uVar1;
}



===== ipmi_interface_cleanup @ 1400069c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ipmi_interface_cleanup(longlong param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  if (*(code **)(&DAT_14000f008 + (ulonglong)*(byte *)(param_1 + 0xc) * 0x18) == (code *)0x0) {
    uVar1 = 0xc000003e;
  }
  else {
    uVar1 = (**(code **)(&DAT_14000f008 + (ulonglong)*(byte *)(param_1 + 0xc) * 0x18))
                      (param_1,param_2);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar1);
  }
  return uVar1;
}



===== ipmi_interface_find_resources @ 140006a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ipmi_interface_find_resources(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xc000003e;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  if ((*(byte *)(param_1 + 0xc) < 5) &&
     (*(code **)(&cResourceDiscovery + (ulonglong)*(byte *)(param_1 + 0xc) * 8) != (code *)0x0)) {
    uVar1 = (**(code **)(&cResourceDiscovery + (ulonglong)*(byte *)(param_1 + 0xc) * 8))
                      (param_1,param_2,param_3);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar1);
  }
  return uVar1;
}



===== ipmi_interface_init @ 140006b44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ipmi_interface_init(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  if (*(code **)(&cEntry + (ulonglong)bVar1 * 0x18) == (code *)0x0) {
    uVar2 = 0xc000003e;
  }
  else {
    uVar2 = (**(code **)(&cEntry + (ulonglong)bVar1 * 0x18))(param_1,param_2);
  }
  *(longlong *)(param_1 + 0x40) = param_1;
  *(code **)(param_1 + 0x30) = IpmiErrorCallback;
  *(undefined4 *)(param_1 + 0x4c) = 5000000;
  *(undefined4 *)(param_1 + 0x58) = 5000000;
  *(undefined4 *)(param_1 + 0x50) = 0x1e;
  *(undefined4 *)(param_1 + 0x48) = 2000000;
  *(undefined4 *)(param_1 + 0x54) = 1000;
  if (bVar1 == 1) {
    KcsInitInterruptObject(param_1,param_2);
  }
  *(undefined1 *)(param_1 + 0x60) = 1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar2);
  }
  return uVar2;
}



===== ipmi_probe @ 140006c54 =====

uint ipmi_probe(longlong param_1,longlong param_2,undefined *param_3)

{
  uint uVar1;
  undefined *puVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  puVar2 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar2 = &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
  *(undefined1 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 7;
  *(undefined1 *)(param_1 + 0xbd) = 0;
  uVar1 = GetEnumerator(param_2,local_res8);
  if (-1 < (int)uVar1) {
    if ((local_res8[0] == 0) || (local_res8[0] != 1)) {
      uVar1 = 0xc0000225;
    }
    else {
      uVar1 = acpi_ipmi_probe(param_1,param_2,puVar2);
      if (-1 < (int)uVar1) {
        *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x48) = 1;
        uVar1 = smbios_ipmi_probe(param_1,param_2);
        if (-1 < (int)uVar1) {
          uVar1 = ipmi_interface_find_resources(param_1,local_res8[0],param_3);
        }
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar1);
  }
  return uVar1;
}



===== smbios_ipmi_probe @ 140006d68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint smbios_ipmi_probe(longlong param_1,undefined8 param_2)

{
  byte bVar1;
  uint uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined2 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = 0xc000000d;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  if (*(int *)(param_1 + 200) == 0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 200) == 1) {
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    bVar1 = SMBIOSRecord38Found(&local_40);
    if (bVar1 == 0) {
      local_48[0] = 0x4e534d42;
      LogEvent(0xc00503e9,param_2,4,local_48);
    }
    else {
      *(byte *)(param_1 + 0x21) = local_40._6_1_ & 0xfe;
      uVar2 = ~-(uint)((local_40 & 0xfe000000000000) != 0) & 0xc000000d;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar2);
  }
  return uVar2;
}



===== SelCacheClose @ 140006e74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SelCacheClose(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (SelCacheThread != 0) {
    ExAcquireFastMutex(&SelCacheRunningLock);
    SelCacheWorkerRunning = 0;
    KeSetEvent(&SelCacheWorkerSignal,0);
    ExReleaseFastMutex(&SelCacheRunningLock);
    KeSetEvent(&SelCacheWorkerWait,0);
    param_4 = 0;
    param_3 = 0;
    KeWaitForSingleObject(SelCacheThread,0);
    ObfDereferenceObject(SelCacheThread);
    SelCacheThread = 0;
  }
  lVar2 = SelCache;
  if (SelCache != 0) {
    ExFreePoolWithTag(SelCache,0x494d5049);
    SelCache = 0;
  }
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(lVar2,1);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_140011183,param_3,param_4,2,local_38);
    }
  }
  return;
}



===== SelCacheInit @ 140006fa4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SelCacheInit(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong local_res10;
  undefined8 local_18;
  undefined4 local_10;
  undefined2 local_c;
  undefined1 local_a;
  
  local_res10 = 0;
  if (SelCache == 0) {
    local_18 = 0;
    local_10 = 0;
    local_c = 0;
    local_a = 0;
    uVar3 = SelGetInfo(param_1,&local_18);
    if (((int)uVar3 < 0) || ((char)local_18 != '\0')) {
      uVar1 = 0x10000;
      SelCacheCount = 0x1000;
    }
    else {
      uVar4 = (uint)local_18._2_2_ * 0x10 + (uint)local_18._4_2_ >> 4;
      uVar1 = uVar4 << 6;
      SelCacheCount = uVar4 << 2;
    }
    SelCacheIndex = 0;
    uVar3 = 0x494d5049;
    plVar5 = (longlong *)0x40;
    uVar6 = (ulonglong)uVar1;
    SelCache = ExAllocatePool2();
    if (SelCache == 0) {
      iVar2 = -0x3fffffe9;
    }
    else {
      _DAT_14002a428 = 0;
      _DAT_14002a430 = 0;
      _SelCacheRunningLock = 1;
      KeInitializeEvent(&DAT_14002a438);
      KeInitializeEvent(&SelCacheWorkerSignal);
      KeInitializeEvent(&SelCacheWorkerWait);
      plVar5 = &local_res10;
      param_4 = 0;
      uVar3 = 0;
      SelCacheWorkerRunning = 1;
      uVar6 = 0;
      iVar2 = PsCreateSystemThread();
      if (-1 < iVar2) {
        if (local_res10 == 0) {
          iVar2 = -0x3fffffff;
          plVar5 = (longlong *)0x0;
        }
        else {
          param_4 = 0;
          iVar2 = ObReferenceObjectByHandle();
          ZwClose(local_res10);
          if (-1 < iVar2) {
            if (SelCacheWorkerEnabled == '\0') {
              return iVar2;
            }
            SelSignalWorkerEvent();
            return iVar2;
          }
          ExAcquireFastMutex(&SelCacheRunningLock);
          uVar3 = 0;
          SelCacheWorkerRunning = 0;
          uVar6 = 0;
          KeSetEvent(&SelCacheWorkerSignal);
          plVar5 = (longlong *)&SelCacheRunningLock;
          ExReleaseFastMutex();
          SelCacheThread = 0;
        }
      }
    }
    SelCacheClose(plVar5,uVar6,uVar3,param_4);
  }
  else {
    iVar2 = 0;
    LogEvent(0x800503ef,param_1,0,(void *)0x0);
  }
  return iVar2;
}



===== SelClearWorkerEvent @ 1400071e4 =====

undefined8 SelClearWorkerEvent(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (SelCacheThread == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    ExAcquireFastMutex(&SelCacheRunningLock);
    if (SelCacheWorkerRunning == '\0') {
      uVar1 = 0xc0000001;
    }
    else {
      KeClearEvent(&SelCacheWorkerSignal);
    }
    ExReleaseFastMutex(&SelCacheRunningLock);
  }
  return uVar1;
}



===== SelGetInfo @ 140007254 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SelGetInfo(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStack_288 [32];
  undefined4 local_268;
  undefined1 local_264;
  undefined4 local_263;
  undefined2 local_25e;
  undefined1 local_25c;
  undefined7 uStack_25b;
  undefined4 local_254;
  undefined2 local_250;
  undefined1 local_24e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(&local_268,0,0x248);
  uVar4 = 0;
  memset(&local_264,0,0x244);
  local_264 = *(undefined1 *)(lVar1 + 0x159);
  local_263 = 0x40280000;
  local_25c = 0xff;
  uVar3 = IpmiComputeBufferResponseLength(0);
  local_25e = (undefined2)uVar3;
  iVar2 = ipmi_send_request(lVar1,&local_268);
  if (iVar2 == 0) {
    *param_2 = CONCAT71(uStack_25b,local_25c);
    *(undefined4 *)(param_2 + 1) = local_254;
    *(undefined2 *)((longlong)param_2 + 0xc) = local_250;
    *(undefined1 *)((longlong)param_2 + 0xe) = local_24e;
  }
  else {
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



===== SelReadRecord @ 140007340 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SelReadRecord(longlong param_1,undefined2 param_2,undefined8 param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStack_298 [32];
  undefined4 local_278;
  undefined1 local_274;
  undefined8 local_273;
  undefined2 local_26b;
  undefined2 local_268;
  undefined1 local_266;
  undefined7 uStack_265;
  undefined8 uStack_25e;
  undefined2 local_256;
  undefined1 local_254;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_298;
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(&local_278,0,0x248);
  uVar4 = 0;
  memset(&local_274,0,0x244);
  local_274 = *(undefined1 *)(lVar1 + 0x159);
  local_273 = 0x43280006;
  local_266 = 0xff;
  uVar3 = IpmiComputeBufferResponseLength(6);
  local_268 = (undefined2)uVar3;
  local_273 = CONCAT26(param_2,(undefined6)local_273);
  local_26b = 0xff00;
  iVar2 = ipmi_send_request(lVar1,&local_278);
  if (iVar2 == 0) {
    *param_4 = CONCAT71(uStack_265,local_266);
    param_4[1] = uStack_25e;
    *(undefined2 *)(param_4 + 2) = local_256;
    *(undefined1 *)((longlong)param_4 + 0x12) = local_254;
  }
  else {
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



===== SelSignalWorkerEvent @ 140007438 =====

undefined8 SelSignalWorkerEvent(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (SelCacheThread == 0) {
    uVar1 = 0xc0000001;
  }
  else {
    ExAcquireFastMutex(&SelCacheRunningLock);
    if (SelCacheWorkerRunning == '\0') {
      uVar1 = 0xc0000001;
    }
    else {
      KeSetEvent(&SelCacheWorkerSignal,0,0);
    }
    ExReleaseFastMutex(&SelCacheRunningLock);
  }
  return uVar1;
}



===== SelpAppendToCache @ 1400074ac =====

void SelpAppendToCache(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  if (SelCacheCount <= SelCacheIndex) {
    SelCacheIndex = 0;
  }
  uVar2 = param_1[1];
  uVar3 = (ulonglong)SelCacheIndex;
  SelCacheIndex = SelCacheIndex + 1;
  puVar1 = (undefined8 *)(SelCache + uVar3 * 0x10);
  *puVar1 = *param_1;
  puVar1[1] = uVar2;
  return;
}



===== SelpCacheWorker @ 1400074f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SelpCacheWorker(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStackY_b8 [32];
  char local_88;
  short sStack_87;
  short sStack_85;
  undefined1 uStack_83;
  undefined2 uStack_82;
  undefined2 uStack_80;
  undefined6 uStack_7e;
  undefined2 local_78;
  undefined1 local_76;
  char local_70;
  undefined5 uStack_6f;
  undefined2 uStack_6a;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined2 local_64;
  undefined1 local_62;
  longlong local_60;
  undefined8 local_58 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = 0;
  local_88 = '\0';
  sStack_87 = 0;
  sStack_85 = 0;
  uStack_83 = 0;
  uStack_82 = 0;
  uStack_80 = 0;
  uStack_7e = 0;
  local_76 = 0;
  local_70 = '\0';
  uStack_6f = 0;
  uStack_6a = 0;
  uStack_68 = 0;
  uStack_66 = 0;
  local_64 = 0;
  local_62 = 0;
  local_60 = 0;
  if (5 < DAT_140014088) {
    uVar5 = 2;
    lVar4 = param_1;
    uVar2 = _tlgKeywordOn(param_1,2);
    if ((char)uVar2 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar4,&DAT_1400111a6,param_3,param_4,uVar5,local_58);
    }
  }
  sVar7 = 0;
  uVar10 = 0;
  uVar6 = 0;
  do {
    if (SelCacheWorkerRunning == '\0') break;
    uVar8 = 0;
    KeWaitForSingleObject(&SelCacheWorkerSignal,0);
    if ((SelCacheWorkerRunning == '\0') || (SelCache == 0)) break;
    uVar3 = SelGetInfo(param_1,(undefined8 *)&local_70);
    if (((int)uVar3 < 0) || (local_70 != '\0')) {
      uVar6 = uVar6 + 1;
      if (uVar6 == 10) {
        LogEvent(0x800503ed,param_1,0,(void *)0x0);
      }
      else if (599 < uVar6) {
        LogEvent(0x800503ee,param_1,0,(void *)0x0);
        break;
      }
    }
    else {
      uVar6 = 0;
      if (uVar10 < CONCAT22(uStack_68,uStack_6a)) {
        uVar3 = SelReadRecord(param_1,sVar7,uVar8,(undefined8 *)&local_88);
        if (((int)uVar3 < 0) || (local_88 != '\0')) {
          sVar7 = 0;
        }
        else {
          if (sVar7 == 0) {
            if (sStack_85 == 0) goto LAB_1400076b2;
            sVar7 = sStack_85;
            SelpAppendToCache((undefined8 *)&sStack_85);
            uVar10 = CONCAT22(uStack_80,uStack_82);
          }
          uVar9 = 0;
          while ((sStack_87 != -1 && (uVar9 < SelCacheReadRecordLimit))) {
            uVar9 = uVar9 + 1;
            uVar3 = SelReadRecord(param_1,sStack_87,uVar8,(undefined8 *)&local_88);
            if (((int)uVar3 < 0) || ((local_88 != '\0' || (sStack_85 == 0)))) break;
            sVar7 = sStack_85;
            SelpAppendToCache((undefined8 *)&sStack_85);
            uVar10 = CONCAT22(uStack_80,uStack_82);
          }
        }
      }
    }
LAB_1400076b2:
    local_60 = (longlong)(SelCachePollingInterval * -10000);
    iVar1 = KeWaitForSingleObject(&SelCacheWorkerWait,0,0,0);
  } while (iVar1 != 0);
  PsTerminateSystemThread(0);
  return;
}



===== DispatchControl @ 140007750 =====

undefined4 DispatchControl(longlong param_1,longlong param_2,char *param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (lVar1 == 0) {
    uVar3 = 0xc000000e;
  }
  else {
    param_3 = "";
    param_4 = 1;
    uVar3 = IoAcquireRemoveLockEx(lVar1 + 0x90);
    uVar4 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      if (*(longlong *)(lVar1 + 0x10) == 0) {
        uVar2 = *(undefined4 *)(param_2 + 0x30);
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = uVar2;
        IofCompleteRequest(param_2,0);
      }
      else {
        uVar2 = IofCallDriver(*(longlong *)(lVar1 + 0x10),param_2);
      }
      IoReleaseRemoveLockEx(lVar1 + 0x90,param_2,0x20);
      return uVar2;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      param_3 = &WPP_2385484360da3bf12a11795396b0f904_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_2385484360da3bf12a11795396b0f904_Traceguids,uVar3);
      param_4 = uVar4;
    }
  }
  uVar2 = CompleteRequest2(param_2,uVar3,param_3,param_4);
  return uVar2;
}



===== DispatchInternalControl @ 140007870 =====

ulonglong DispatchInternalControl
                    (longlong param_1,longlong param_2,char *param_3,undefined *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_var;
  ulonglong uVar7;
  uint uVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (lVar2 == 0) {
    iVar6 = -0x3ffffff2;
LAB_140007890:
    uVar5 = CompleteRequest2(param_2,iVar6,param_3,param_4);
    return CONCAT44(extraout_var,uVar5);
  }
  param_4 = (code *)0x1;
  param_3 = "";
  iVar6 = IoAcquireRemoveLockEx();
  if (iVar6 < 0) goto LAB_140007890;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar3 + 0x18) == 0x221000) {
    if (0x13 < *(uint *)(lVar3 + 0x10)) {
      piVar4 = *(int **)(param_2 + 0x18);
      if (*(char *)(param_2 + 0x40) != '\0') {
        if (((ulonglong)piVar4 & 7) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        param_3 = *(char **)MmUserProbeAddress_exref;
      }
      param_4 = MmUserProbeAddress_exref;
      if ((((*piVar4 == 0x5253534f) && (piVar4[1] == 1)) &&
          (uVar1 = piVar4[2], uVar1 <= *(uint *)(lVar3 + 0x10))) && (0x13 < uVar1)) {
        uVar8 = piVar4[4] + 0x14;
        param_3 = (char *)(ulonglong)uVar8;
        if (uVar8 < 0x14) {
          param_3 = (char *)0xffffffff;
        }
        else if (uVar8 <= uVar1) {
          if ((*(char *)(param_2 + 0x40) != '\0') && (piVar4[4] != 0)) {
            param_3 = *(char **)MmUserProbeAddress_exref;
          }
          uVar7 = LogSelEventInternal(piVar4,param_2,param_3);
          uVar7 = uVar7 & 0xffffffff;
          goto LAB_1400079d0;
        }
      }
    }
    uVar7 = 0xc000000d;
  }
  else {
    uVar7 = 0xc00000bb;
LAB_1400079d0:
    if ((int)uVar7 == 0x103) goto LAB_1400079e2;
  }
  CompleteRequest2(param_2,(int)uVar7,param_3,param_4);
LAB_1400079e2:
  IoReleaseRemoveLockEx(lVar2 + 0x90,param_2,0x20);
  return uVar7;
}



===== DrainDeviceIrps @ 140007a10 =====

void DrainDeviceIrps(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&EngineState,&local_28);
  plVar1 = DAT_14002a900;
  while( true ) {
    do {
      plVar5 = plVar1;
      if ((plVar5 == (longlong *)0x0) ||
         (plVar1 = (longlong *)*plVar5, (longlong **)plVar1 == &DAT_14002a900)) {
        KeReleaseInStackQueuedSpinLock(&local_28);
        return;
      }
    } while (plVar5[5] != param_1);
    if ((int)plVar5[-1] != 2) {
      *(undefined4 *)plVar5[-2] = 0xc0000120;
      KeSetEvent(plVar5 + 2,0,0);
    }
    lVar2 = *plVar5;
    if ((*(longlong **)(lVar2 + 8) != plVar5) ||
       (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) break;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== GetProductType @ 140007ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 GetProductType(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_88 [32];
  undefined4 *local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [2];
  undefined8 local_48;
  wchar_t *local_40;
  wchar_t local_38 [20];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  builtin_wcsncpy(local_38,L"Kernel-ProductInfo",0x13);
  local_40 = local_38;
  local_58 = 0;
  local_68 = &local_54;
  local_50[0] = 0;
  local_54 = 0;
  local_48 = 0x260024;
  iVar1 = ZwQueryLicenseValue(&local_48,local_50,&local_58,4);
  uVar2 = 0;
  if (-1 < iVar1) {
    uVar2 = local_58;
  }
  return uVar2;
}



===== HandleTimeouts @ 140007b98 =====

void HandleTimeouts(void)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&DAT_14002a9e0,&local_28);
  for (puVar2 = DAT_14002a9e8;
      (puVar2 != (undefined8 *)0x0 && ((undefined8 **)*puVar2 != &DAT_14002a9e8));
      puVar2 = (undefined8 *)*puVar2) {
    puVar1 = (uint *)((longlong)puVar2 + 0x1dc);
    if (0x14 < *puVar1) {
      *(undefined1 *)(puVar2 + 0x20) = 1;
      IoInvalidateDeviceState(puVar2[-1]);
      LogEvent(0xc00503e8,puVar2[-3],4,puVar1);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
      }
    }
    LOCK();
    *puVar1 = *puVar1 ^ *puVar1;
    UNLOCK();
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== IpmiDrvWriteSel @ 140007c7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IpmiDrvWriteSel(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (5 < DAT_140014088) {
    lVar2 = param_1;
    uVar1 = _tlgKeywordOn(param_1,8);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_1400112c4,param_3,param_4,2,local_38);
    }
  }
  if (*(char *)(param_1 + 0x1f8) == '\0') {
    ipmi_send_request(param_1,param_2);
  }
  else {
    ipmi_ioctl_func((longlong *)(param_1 + 0x138),0x222008,(char *)(param_2 + 1));
  }
  return;
}



===== LogEvent @ 140007d20 =====

void LogEvent(undefined4 param_1,undefined8 param_2,ushort param_3,void *param_4)

{
  void *_Dst;
  undefined2 uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
  }
  uVar2 = (ulonglong)param_3 + 3 >> 2;
  uVar3 = (int)uVar2 * 4 + 0x2c;
  if (uVar3 < 0xf1) {
    _Dst = (void *)IoAllocateErrorLogEntry(param_2);
    if (_Dst == (void *)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return;
      }
      uVar1 = 0x10;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar3);
      *(undefined4 *)((longlong)_Dst + 0xc) = param_1;
      *(short *)((longlong)_Dst + 2) = (short)uVar2 << 2;
      if ((param_3 != 0) && (param_4 != (void *)0x0)) {
        memmove((void *)((longlong)_Dst + 0x28),param_4,(ulonglong)param_3);
      }
      IoWriteErrorLogEntry(_Dst);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return;
      }
      uVar1 = 0x11;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    uVar1 = 0xf;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
          &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
  return;
}



===== ipmi_send_noncommunicationrequest @ 140007e8c =====

undefined8 ipmi_send_noncommunicationrequest(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
  }
  puVar1 = (undefined8 *)ExAllocatePool2(0x42,0x40,0x494d5049);
  if (puVar1 == (undefined8 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_2385484360da3bf12a11795396b0f904_Traceguids,0xc0000017);
    }
    uVar2 = 0xc0000017;
  }
  else {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 3;
    puVar1[7] = param_1;
    KeInitializeEvent(puVar1 + 4,0,0);
    ExInterlockedInsertHeadList(&DAT_14002a900,puVar1 + 2,&EngineState);
    KeSetEvent(&DAT_14002a8e8,0,0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_2385484360da3bf12a11795396b0f904_Traceguids);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== Func_GetTimeOut @ 140007fc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong Func_GetTimeOut(int param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = _DAT_fffff78000000320;
  uVar2 = KeQueryTimeIncrement();
  return (ulonglong)(uint)(param_1 * 10) / (ulonglong)uVar2 + lVar1;
}



===== Func_InterruptClean @ 14000800c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Func_InterruptClean(longlong param_1,longlong param_2,char param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  short sVar5;
  longlong lVar6;
  undefined1 auStack_2b8 [32];
  ushort local_298 [2];
  undefined2 local_293;
  byte local_291;
  byte local_16f;
  byte local_16e;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2b8;
  uVar3 = 0;
  if (param_2 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x40);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids);
  }
  if (lVar6 == 0) goto LAB_140008219;
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x28) & 1) != 0)) {
    lVar2 = Func_GetTimeOut(*(int *)(param_1 + 0x48));
    memset(local_298,0,0x24a);
    local_298[0] = 2;
    local_298[1] = 0x122;
    local_293 = 0x2f18;
    uVar3 = IpmiLibpKcsBmcTransact(param_1 + 8,local_298,lVar2);
    uVar1 = (uint)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (uVar1 == 0) {
      if (local_16f == 0) {
        if ((local_16e & 1) != 0) {
          memset(local_298,0,0x24a);
          local_291 = local_16e & 0xfe;
          local_298[0] = 3;
          local_298[1] = 0x122;
          local_293 = 0x2e18;
          uVar4 = IpmiLibpKcsBmcTransact(param_1 + 8,local_298,lVar2);
          uVar3 = uVar4 & 0xffffffff;
          if ((int)uVar4 == 0) {
            if (((local_16f == (byte)uVar4) &&
                ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              sVar5 = (short)uVar4 + 0x12;
              uVar1 = 0;
LAB_1400081bf:
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),sVar5,
                       &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,uVar1);
            }
          }
          else {
            uVar3 = 0xc000003e;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              sVar5 = 0x13;
              uVar1 = 0xc000003e;
              goto LAB_1400081bf;
            }
          }
        }
      }
      else {
        uVar3 = 0xc000003e;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar1 = (uint)local_16f;
          sVar5 = 0x14;
          goto LAB_1400081bf;
        }
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      sVar5 = 0x15;
      goto LAB_1400081bf;
    }
  }
  if (param_3 != '\0') {
    IoDisconnectInterrupt(*(undefined8 *)(param_1 + 0xa0));
  }
  HandleNonCommunicationInterrupt(lVar6 + 0x138);
LAB_140008219:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,(int)uVar3);
  }
  return uVar3;
}



===== Func_InterruptInit @ 140008278 =====

undefined4 Func_InterruptInit(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  int *piVar5;
  char cVar6;
  int *piVar7;
  uint uVar8;
  bool bVar9;
  char local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  undefined8 local_60;
  
  uVar3 = 0xffffffff;
  local_78 = '\x04';
  local_60 = 0xffffffffffffffff;
  cVar6 = '\x03';
  bVar9 = *(char *)(param_1 + 0xbc) == '\0';
  local_68 = 0;
  bVar2 = false;
  if (((param_2 == 0) || (lVar1 = *(longlong *)(param_2 + 0x40), lVar1 == 0)) ||
     (piVar5 = *(int **)(lVar1 + 0x40), piVar5 == (int *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids);
    }
  }
  else {
    piVar7 = piVar5 + 1;
    local_6c = 0;
    if (*piVar5 != 0) {
      do {
        piVar5 = piVar7 + 4;
        uVar4 = 0x10;
        local_70 = 0;
        local_74 = 0x10;
        if (piVar7[3] != 0) {
          do {
            uVar8 = 0x14;
            if ((char)*piVar5 == '\x02') {
              local_78 = (char)piVar5[1];
              bVar9 = *(short *)((longlong)piVar5 + 2) == 1;
              local_60 = *(undefined8 *)(piVar5 + 3);
              cVar6 = *(char *)((longlong)piVar5 + 1);
              local_68 = piVar5[2];
              bVar2 = true;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_DDiDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,WPP_GLOBAL_Control,
                             local_68,local_78,(char)local_60,bVar9,cVar6);
                uVar4 = (ulonglong)local_74;
              }
            }
            else if ((char)*piVar5 == '\x05') {
              uVar8 = piVar5[1] + 0x14;
            }
            local_74 = (int)uVar4 + uVar8;
            uVar4 = (ulonglong)local_74;
            local_70 = local_70 + 1;
            piVar5 = (int *)((longlong)piVar5 + (ulonglong)uVar8);
          } while (local_70 < (uint)piVar7[3]);
        }
        local_6c = local_6c + 1;
        piVar7 = (int *)((longlong)piVar7 + uVar4);
      } while (local_6c < **(uint **)(lVar1 + 0x40));
      uVar3 = 0xffffffff;
      if (bVar2) {
        *(undefined4 *)(param_1 + 0x5c) = 7;
        if (param_3 == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = IoConnectInterrupt(param_1 + 0xa0,KCSInterrupt,param_2,0,local_68,local_78,
                                     local_78,bVar9,cVar6,local_60,0);
        }
      }
    }
  }
  return uVar3;
}



===== HandleNonCommunicationInterrupt @ 1400084ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleNonCommunicationInterrupt(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  longlong lVar3;
  undefined1 auStack_298 [32];
  ushort local_278 [2];
  undefined2 local_273;
  undefined1 local_271;
  byte local_14e;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_298;
  lVar1 = param_1 + 8;
  bVar2 = IpmiLibReadOneByte(lVar1,1);
  if ((bVar2 & 4) != 0) {
    lVar3 = Func_GetTimeOut(*(int *)(param_1 + 0x48));
    memset(local_278,0,0x24a);
    local_278[0] = 3;
    local_278[1] = 0x122;
    local_273 = 0x3118;
    local_271 = 0xff;
    IpmiLibpKcsBmcTransact(lVar1,local_278,lVar3);
    if (((local_14e & 1) == 0) || (*(char *)(param_1 + 0xbd) != '\x01')) {
      lVar3 = Func_GetTimeOut(*(int *)(param_1 + 0x48));
      memset(local_278,0,0x24a);
      local_278[0] = 3;
      local_278[1] = 0x122;
      local_273 = 0x3018;
      local_271 = 0xff;
      IpmiLibpKcsBmcTransact(lVar1,local_278,lVar3);
    }
  }
  return;
}



===== KCSInterrupt @ 140008600 =====

undefined8 KCSInterrupt(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined7 extraout_var;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  byte bVar9;
  longlong lVar10;
  
  lVar10 = *(longlong *)(param_2 + 0x40);
  bVar9 = 0;
  lVar1 = lVar10 + 0x140;
  bVar3 = IpmiLibReadOneByte(lVar1,1);
  uVar6 = CONCAT71(extraout_var,bVar3);
  if (((bVar3 & 1) == 0) ||
     (uVar6 = (ulonglong)*(uint *)(lVar10 + 0x160), (*(uint *)(lVar10 + 0x160) & 1) == 0)) {
    return uVar6 & 0xffffffffffffff00;
  }
  iVar2 = *(int *)(lVar10 + 0x194);
  if (((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) {
    uVar5 = Check_IBFNotSet(lVar1);
    if (uVar5 == 0) {
      if (((char)bVar3 < '\0') && ((bVar3 & 0x40) == 0)) goto LAB_140008701;
LAB_1400086fe:
      bVar9 = 0xff;
      goto LAB_140008701;
    }
  }
  else {
    if (iVar2 != 3) {
      if (iVar2 == 4) {
        uVar5 = Check_IBFNotSet(lVar1);
      }
      else {
        lVar8 = lVar1;
        if (iVar2 == 5) {
          uVar5 = Check_IBFNotSet(lVar1);
          if (uVar5 != 0) goto LAB_1400086ee;
          if (((char)bVar3 < '\0') || ((bVar3 & 0x40) == 0)) goto LAB_1400086fe;
        }
        else {
          if (iVar2 != 6) goto LAB_140008701;
          uVar5 = Check_IBFNotSet(lVar1);
          if (uVar5 != 0) goto LAB_1400086ee;
          if (((char)bVar3 < '\0') || ((bVar3 & 0x40) != 0)) goto LAB_1400086fe;
        }
        uVar7 = Check_OBFSet(lVar8);
        uVar5 = (uint)uVar7;
      }
      bVar9 = uVar5 != 0;
      goto LAB_140008701;
    }
    lVar8 = lVar1;
    uVar5 = Check_IBFNotSet(lVar1);
    if (uVar5 == 0) {
      if ((char)bVar3 < '\0') goto LAB_1400086fe;
      bVar9 = ~(bVar3 >> 5) & 2;
      uVar7 = Check_OBFSet(lVar8);
      if ((int)uVar7 == 0) goto LAB_140008701;
    }
  }
LAB_1400086ee:
  bVar9 = 1;
LAB_140008701:
  if ((*(int *)(lVar10 + 0x194) != 7) ||
     (((bVar3 & 4) != 0 && (*(char *)(lVar10 + 0x1f5) == '\x01')))) {
    *(char *)(lVar10 + 0x1e0) = *(char *)(lVar10 + 0x1e0) + '\x01';
    bVar3 = *(char *)(lVar10 + 0x1f1) + 1U & 7;
    *(byte *)(lVar10 + 0x1f1) = bVar3;
    *(byte *)((ulonglong)bVar3 + 0x1e1 + lVar10) = bVar9;
    uVar4 = IpmiLibReadOneByte(lVar1,0);
    *(undefined1 *)((ulonglong)*(byte *)(lVar10 + 0x1f1) + 0x1e9 + lVar10) = uVar4;
  }
  uVar7 = KeInsertQueueDpc(*(longlong *)(lVar10 + 8) + 200,0,lVar10);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== KcsInitInterruptObject @ 140008788 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KcsInitInterruptObject(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined1 auStack_2a8 [32];
  ushort local_288 [2];
  undefined2 local_283;
  byte local_281;
  byte local_15f;
  byte local_15e;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2a8;
  if (*(char *)(param_1 + 0x98) == '\0') {
    return 0xc0000001;
  }
  iVar1 = Func_InterruptInit(param_1,param_2,'\0');
  if (iVar1 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,iVar1);
    }
    return 0;
  }
  lVar3 = Func_GetTimeOut(*(int *)(param_1 + 0x48));
  memset(local_288,0,0x24a);
  local_288[0] = 2;
  local_288[1] = 0x122;
  local_283 = 0x2f18;
  uVar4 = IpmiLibpKcsBmcTransact(param_1 + 8,local_288,lVar3);
  uVar2 = (uint)uVar4;
  uVar4 = uVar4 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar4;
    }
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar6 = 0x18;
    goto LAB_140008a34;
  }
  uVar2 = (uint)local_15f;
  if (local_15f == 0) {
    if ((local_15e & 1) == 0) {
      memset(local_288,0,0x24a);
      local_281 = local_15e | 1;
      local_288[0] = 3;
      local_288[1] = 0x122;
      local_283 = 0x2e18;
      uVar4 = IpmiLibpKcsBmcTransact(param_1 + 8,local_288,lVar3);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000003e;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return 0xc000003e;
        }
        uVar6 = 0x1a;
      }
      else {
        if (local_15f == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                     &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,0);
          }
          goto LAB_1400089b7;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000003e;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return 0xc000003e;
        }
        uVar6 = 0x1b;
      }
      uVar4 = 0xc000003e;
      uVar2 = 0xc000003e;
    }
    else {
LAB_1400089b7:
      uVar2 = Func_InterruptInit(param_1,param_2,'\x01');
      uVar4 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        uVar4 = Func_InterruptClean(param_1,param_2,'\0');
        uVar4 = uVar4 & 0xffffffff;
      }
      else {
        *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 1;
        *(code **)(param_1 + 0x38) = WaitInterruptIfSupported;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar4;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                  &WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids);
        }
      }
      uVar2 = (uint)uVar4;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar4;
      }
      uVar6 = 0x1e;
    }
  }
  else {
    uVar4 = 0xc000003e;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000003e;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000003e;
    }
    uVar6 = 0x19;
  }
  uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
LAB_140008a34:
  WPP_SF_D(uVar5,uVar6,&WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,uVar2);
  return uVar4;
}



===== WPP_SF_DDiDD @ 140008a74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDiDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_d24f214dd9563cb6c478c008daa022f3_Traceguids,0xf,local_res20,4,
             &param_5,4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_Dd @ 140008af8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined4 local_18 [6];
  
  local_18[0] = 0;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4107e96cfe8c31fa2a2b60f38ace0bb3_Traceguids,param_2,local_18,4,
             &param_5,4,0);
  return;
}



===== HandleCancelRemove @ 140008b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HandleCancelRemove(undefined8 *param_1,undefined8 *param_2,undefined *param_3,undefined8 param_4
                      )

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  byte *pbVar4;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50 [4];
  int *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = param_1[8];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  *(undefined4 *)(param_2 + 6) = 0;
  if (*(int *)(lVar1 + 0xd0) != 3) {
    iVar2 = DefaultPnpHandler((longlong)param_1,(longlong)param_2,param_3,param_4);
    if (DAT_140014088 < 6) {
      return iVar2;
    }
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 == '\0') {
      return iVar2;
    }
    pbVar4 = &DAT_140011b43;
    param_2 = param_1;
    goto LAB_140008caa;
  }
  iVar2 = ForwardAndWait((longlong)param_1,(longlong)param_2,param_3,param_4);
  if (iVar2 < 0) {
    if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
      local_24 = 0;
      local_30 = local_58;
      pbVar4 = &DAT_1400114fd;
      local_28 = 4;
      local_58[0] = iVar2;
      goto LAB_140008c4c;
    }
  }
  else if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
    _tlgCreate1Sz_char((longlong *)&local_30,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd4)]);
    param_1 = local_50;
    pbVar4 = &DAT_140011b07;
LAB_140008c4c:
    _tlgWriteTransfer_EtwWriteTransfer(param_1,pbVar4,param_3,param_4,3,local_50);
  }
  iVar2 = CompleteRequest2((longlong)param_2,iVar2,param_3,param_4);
  if (DAT_140014088 < 6) {
    return iVar2;
  }
  uVar3 = _tlgKeywordOn(param_2,4);
  if ((char)uVar3 == '\0') {
    return iVar2;
  }
  pbVar4 = &DAT_140011aa0;
LAB_140008caa:
  local_30 = local_58;
  local_24 = 0;
  local_28 = 4;
  local_58[0] = iVar2;
  _tlgWriteTransfer_EtwWriteTransfer(param_2,pbVar4,param_3,param_4,3,local_50);
  return iVar2;
}



===== HandleCancelStop @ 140008d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleCancelStop(undefined8 *param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50 [4];
  int *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar1 = param_1[8];
  if (*(int *)(lVar1 + 0xd0) != 1) {
    iVar2 = DefaultPnpHandler((longlong)param_1,param_2,param_3,param_4);
    if (DAT_140014088 < 6) {
      return iVar2;
    }
    local_28 = 4;
    uVar4 = _tlgKeywordOn(param_1,4);
    if ((char)uVar4 == '\0') {
      return iVar2;
    }
    local_24 = 0;
    local_30 = local_58;
    local_58[0] = iVar2;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011d0a,param_3,param_4,3,local_50);
    return iVar2;
  }
  iVar2 = ForwardAndWait((longlong)param_1,param_2,param_3,param_4);
  if (iVar2 < 0) {
    if (DAT_140014088 < 6) goto LAB_140008e13;
    uVar3 = 4;
    uVar4 = _tlgKeywordOn(param_1,4);
    if ((char)uVar4 == '\0') goto LAB_140008e13;
    local_24 = 0;
    local_30 = local_58;
    pbVar5 = &DAT_140011be2;
    local_58[0] = iVar2;
    local_28 = uVar3;
  }
  else {
    *(undefined4 *)(lVar1 + 0xd0) = 0;
    if ((DAT_140014088 < 6) || (uVar4 = _tlgKeywordOn(param_1,4), (char)uVar4 == '\0'))
    goto LAB_140008e13;
    _tlgCreate1Sz_char((longlong *)&local_30,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd4)]);
    param_1 = local_50;
    pbVar5 = &DAT_1400118f3;
  }
  _tlgWriteTransfer_EtwWriteTransfer(param_1,pbVar5,param_3,param_4,3,local_50);
LAB_140008e13:
  uVar3 = CompleteRequest2(param_2,iVar2,param_3,param_4);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,uVar3);
  }
  return uVar3;
}



===== HandleFilterResourceRequirements @ 140008ed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleFilterResourceRequirements
          (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar1 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
  if (5 < DAT_140014088) {
    local_18 = 4;
    uVar2 = _tlgKeywordOn(param_1,4);
    if ((char)uVar2 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011542,param_3,param_4,3,local_40);
    }
  }
  return uVar1;
}



===== HandleQueryCapabilities @ 140008f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleQueryCapabilities(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  byte *pbVar7;
  longlong lVar8;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  undefined8 local_50 [4];
  undefined4 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar8 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(short *)(lVar8 + 2) == 0) {
    uVar4 = DefaultPnpHandler(param_1,param_2,lVar8,param_4);
    if (DAT_140014088 < 6) {
      return uVar4;
    }
    local_28 = 4;
    uVar6 = _tlgKeywordOn(param_1,4);
    if ((char)uVar6 == '\0') {
      return uVar4;
    }
    pbVar7 = &DAT_140011f93;
  }
  else {
    iVar5 = ForwardAndWait(param_1,param_2,lVar8,param_4);
    if (-1 < iVar5) {
      puVar2 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 8);
      AdjustDeviceCapabilities(*(longlong *)(param_2 + 0xb8),(longlong)puVar2,lVar8,param_4);
      uVar3 = puVar2[1];
      *(undefined8 *)(lVar1 + 0xe0) = *puVar2;
      *(undefined8 *)(lVar1 + 0xe8) = uVar3;
      uVar3 = puVar2[3];
      *(undefined8 *)(lVar1 + 0xf0) = puVar2[2];
      *(undefined8 *)(lVar1 + 0xf8) = uVar3;
      uVar3 = puVar2[5];
      *(undefined8 *)(lVar1 + 0x100) = puVar2[4];
      *(undefined8 *)(lVar1 + 0x108) = uVar3;
      uVar3 = puVar2[7];
      *(undefined8 *)(lVar1 + 0x110) = puVar2[6];
      *(undefined8 *)(lVar1 + 0x118) = uVar3;
    }
    uVar4 = CompleteRequest2(param_2,iVar5,lVar8,param_4);
    if (DAT_140014088 < 6) {
      return uVar4;
    }
    local_28 = 4;
    uVar6 = _tlgKeywordOn(param_2,4);
    if ((char)uVar6 == '\0') {
      return uVar4;
    }
    pbVar7 = &DAT_140011dd7;
    param_1 = param_2;
  }
  local_30 = local_58;
  local_24 = 0;
  local_58[0] = uVar4;
  _tlgWriteTransfer_EtwWriteTransfer(param_1,pbVar7,lVar8,param_4,3,local_50);
  return uVar4;
}



===== HandleQueryPnpDeviceState @ 1400090d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleQueryPnpDeviceState(longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  if (*(char *)(lVar1 + 0x120) != '\0') {
    *(undefined8 *)(param_2 + 0x38) = 4;
  }
  if (*(char *)(lVar1 + 0x121) != '\0') {
    *(undefined8 *)(param_2 + 0x38) = 8;
  }
  uVar2 = ForwardAndWait(param_1,param_2,param_3,param_4);
  *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) & 0xffffffffffffffdf;
  uVar2 = CompleteRequest2(param_2,uVar2,param_3,param_4);
  if (5 < DAT_140014088) {
    local_18 = 4;
    uVar3 = _tlgKeywordOn(param_2,4);
    if ((char)uVar3 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(param_2,&DAT_1400114c5,param_3,param_4,3,local_40);
    }
  }
  return uVar2;
}



===== HandleQueryRemove @ 1400091e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleQueryRemove(longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar4 = (ulonglong)*(uint *)(lVar1 + 0xd0);
  if ((*(uint *)(lVar1 + 0xd0) == 0) && (5 < DAT_140014088)) {
    uVar3 = _tlgKeywordOn(0,4);
    if ((char)uVar3 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1400119fe,param_3,param_4,2,local_40);
      uVar4 = (ulonglong)*(uint *)(lVar1 + 0xd0);
    }
  }
  *(int *)(lVar1 + 0xd4) = (int)uVar4;
  *(undefined4 *)(lVar1 + 0xd0) = 3;
  uVar2 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
  if (5 < DAT_140014088) {
    local_18 = 4;
    uVar4 = _tlgKeywordOn(param_1,4);
    if ((char)uVar4 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011f63,param_3,param_4,3,local_40);
    }
  }
  return uVar2;
}



===== HandleQueryStop @ 140009310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 HandleQueryStop(longlong param_1,longlong param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined1 local_78 [32];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
    local_58 = local_88;
    local_88[0] = 0;
    local_4c = 0;
    local_50 = 4;
    _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[_DAT_000000d0]);
    _tlgWriteTransfer_EtwWriteTransfer
              (local_78,&DAT_14001148a,param_3,param_4,4,(undefined8 *)local_78);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0xd0) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      param_4 = "STOPPED";
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,"STOPPED");
    }
    *(undefined4 *)(lVar1 + 0xd4) = *(undefined4 *)(lVar1 + 0xd0);
    *(undefined4 *)(lVar1 + 0xd0) = 1;
    uVar2 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
    if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
      local_58 = local_88;
      local_4c = 0;
      local_50 = 4;
      local_88[0] = uVar2;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd0)]);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_1400116e0,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  else {
    uVar2 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,uVar2);
    }
  }
  return uVar2;
}



===== HandleRemoveDevice @ 1400094d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong HandleRemoveDevice(longlong param_1,longlong param_2,undefined *param_3,ulonglong param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined *puVar7;
  longlong lVar8;
  undefined *puVar9;
  undefined1 auStackY_98 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 local_50 [32];
  longlong local_30 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(param_2 + 0x30) = 0;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  lVar8 = param_2;
  DeregisterAllInterfaces(lVar2,param_2,param_3,param_4);
  StopDevice(param_1,lVar8,param_3,param_4);
  *(undefined4 *)(lVar2 + 0xd4) = *(undefined4 *)(lVar2 + 0xd0);
  *(undefined4 *)(lVar2 + 0xd0) = 5;
  KeAcquireInStackQueuedSpinLock(&DAT_14002a9e0,&local_68);
  plVar1 = (longlong *)(lVar2 + 0x20);
  lVar8 = *plVar1;
  if ((*(longlong **)(lVar8 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(lVar2 + 0x28), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)();
    return uVar6;
  }
  *plVar3 = lVar8;
  *(longlong **)(lVar8 + 8) = plVar3;
  KeReleaseInStackQueuedSpinLock(&local_68);
  uVar5 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
  puVar9 = (undefined *)0x20;
  IoReleaseRemoveLockAndWaitEx(lVar2 + 0x90);
  if (IpmipWheaInitialized != '\0') {
    WheaRemoveErrorSource(DAT_14001466c);
    IpmipWheaRemoved = 1;
  }
  RemoveDevice(param_1,param_2,puVar9,param_4);
  puVar7 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar9 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    param_4 = (ulonglong)uVar5;
    WPP_SF_D(puVar7,0x14,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,uVar5);
  }
  if (5 < DAT_140014088) {
    uVar6 = _tlgKeywordOn(puVar7,4);
    if ((char)uVar6 != '\0') {
      _tlgCreate1Sz_char(local_30,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar2 + 0xd0)]);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_50,&DAT_14001198d,puVar9,param_4,3,(undefined8 *)local_50);
    }
  }
  return (ulonglong)uVar5;
}



===== HighIrqlLogSelEventHandler @ 140009690 =====

void HighIrqlLogSelEventHandler(undefined8 param_1,void *param_2,undefined8 param_3)

{
  LogSelEventInternal(param_2,0,param_3);
  return;
}



===== IpmiWorkQueueDpcRoutine @ 1400096b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IpmiWorkQueueDpcRoutine
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  lVar2 = param_2 + 0x60;
  ExQueueWorkItem(lVar2,1);
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(lVar2,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_1400117e2,param_3,param_4,2,local_38);
    }
  }
  return;
}



===== LogSelEventInternal @ 140009728 =====

undefined8 LogSelEventInternal(void *param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int *piVar6;
  
  if (0x13c < *(uint *)((longlong)param_1 + 8)) {
    return 0xc000009a;
  }
  if (*(char *)(DAT_14002a338 + 0x1f8) == '\0') {
    uVar4 = 0;
    piVar6 = &DAT_140014a38;
    do {
      uVar3 = (uint)uVar4;
      if (*piVar6 == 0) {
        LOCK();
        iVar1 = (&DAT_140014a38)[uVar4 * 0x56];
        (&DAT_140014a38)[uVar4 * 0x56] = 1;
        UNLOCK();
        if (iVar1 == 0) break;
      }
      uVar3 = uVar3 + 1;
      uVar4 = (ulonglong)uVar3;
      piVar6 = piVar6 + 0x56;
    } while (uVar3 < 0x100);
    if (0xff < uVar3) {
      return 0x80000011;
    }
    lVar5 = (ulonglong)uVar3 * 0x158;
    *(longlong *)(&DAT_140014a30 + lVar5) = param_2;
    memmove(&DAT_140014a3c + lVar5,param_1,(ulonglong)*(uint *)((longlong)param_1 + 8));
    lVar5 = ExInterlockedInsertTailList(&OsSelRecWorkQueue,&OsRecWrapper + lVar5,&DAT_14002a330);
    if (lVar5 == 0) {
      bVar2 = KeGetCurrentIrql();
      if (bVar2 < 3) {
        ExQueueWorkItem(&DAT_14002a380,1);
      }
      else {
        KeInsertQueueDpc(&DAT_14002a340,0,0);
      }
    }
    if (param_2 != 0) {
      return 0x103;
    }
  }
  else {
    WriteOSREC2SEL(DAT_14002a338,(longlong)param_1,param_3,param_1);
  }
  return 0;
}



===== PublishSystemInfo @ 14000986c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PublishSystemInfo(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined4 extraout_var;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined2 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  uint uVar12;
  undefined2 *puVar13;
  void *pvVar14;
  undefined *puVar15;
  byte bVar16;
  undefined **ppuVar17;
  byte bVar18;
  uint uVar19;
  longlong lVar20;
  undefined1 auStackY_a8 [32];
  uint local_78 [2];
  ulonglong local_70;
  void *pvStack_68;
  uint local_60 [2];
  undefined8 local_58;
  undefined2 *puStack_50;
  longlong local_48;
  undefined2 *local_40;
  undefined4 local_38;
  undefined1 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  callbackBuffer = *(undefined1 *)(param_1 + 0x159);
  local_60[0] = 0x39c;
  local_70 = 0;
  pvStack_68 = (void *)0x0;
  local_38 = 0x8050402;
  local_34 = 9;
  _DAT_14002a483 = 0x5818;
  local_48 = param_1;
  RtlInitUnicodeString(&local_70,L"ProductType");
  lVar20 = 0;
  iVar3 = QueryConfigFromRegistry
                    (&PRODUCT_OPTIONS_CONFIG_KEY,(longlong)&local_70,(undefined8 *)0x1,
                     &DAT_14002a4e4,local_60,'\0');
  if (iVar3 == 0) {
    if (DAT_14002a4e4 == 0x57) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
      }
      lVar20 = 2;
    }
    else {
      lVar20 = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
      }
    }
  }
  ppuVar5 = (undefined **)RtlInitUnicodeString(&local_70,L"http://");
  uVar2 = (ushort)local_70;
  if (0x39c < (ushort)local_70) goto LAB_140009b5c;
  uVar7 = local_70 & 0xffff;
  memmove(&DAT_14002a4e4,pvStack_68,local_70 & 0xffff);
  puVar13 = (undefined2 *)((longlong)&DAT_14002a4e4 + uVar7);
  RtlInitUnicodeString(&local_70,L"ComputerName");
  local_78[0] = 0x39c - uVar2;
  local_40 = puVar13;
  iVar3 = QueryConfigFromRegistry
                    ((longlong *)&COMPUTER_NAME_CONFIG_KEY,(longlong)&local_70,(undefined8 *)0x1,
                     puVar13,local_78,'\0');
  ppuVar5 = (undefined **)CONCAT44(extraout_var,iVar3);
  if (iVar3 == 0) {
    uVar19 = local_78[0] - 2;
    uVar7 = (ulonglong)uVar19;
    uVar11 = (0x39c - uVar2) - uVar19;
    local_60[0] = uVar19;
    RtlInitUnicodeString(&local_70,L".");
    ppuVar5 = (undefined **)(local_70 & 0xffff);
    if (uVar11 < (ushort)local_70) goto LAB_140009b5c;
    memmove((void *)((longlong)puVar13 + uVar7),pvStack_68,local_70 & 0xffff);
    uVar6 = local_70 & 0xffff;
    pvVar14 = (void *)((longlong)((longlong)puVar13 + uVar7) + (local_70 & 0xffff));
    uVar12 = uVar11 - (ushort)local_70;
    uVar4 = (uint)(ushort)local_70;
    RtlInitUnicodeString(&local_70,L"NV Domain");
    local_78[0] = uVar12;
    iVar3 = QueryConfigFromRegistry
                      (&TCPIP_PARAMETERS_CONFIG_KEY,(longlong)&local_70,(undefined8 *)0x1,pvVar14,
                       local_78,'\0');
    if (iVar3 != 0) {
      RtlInitUnicodeString(&local_70,L"Domain");
      local_78[0] = uVar12;
      iVar3 = QueryConfigFromRegistry
                        (&TCPIP_PARAMETERS_CONFIG_KEY,(longlong)&local_70,(undefined8 *)0x1,pvVar14,
                         local_78,'\0');
      if (iVar3 != 0) {
        ppuVar5 = &WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (ppuVar5 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
           (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140009b5c;
        uVar9 = 0x20;
        goto LAB_140009b4c;
      }
    }
    uVar8 = local_78[0] - 2;
    if (uVar8 == 0) {
      uVar6 = -uVar6;
    }
    else {
      uVar6 = (ulonglong)uVar8;
      local_60[0] = uVar8 + uVar4 + uVar19;
      uVar7 = (ulonglong)local_60[0];
      uVar11 = uVar12 - uVar8;
    }
    RtlInitUnicodeString(&local_70,L":5985/wsman");
    ppuVar5 = (undefined **)(local_70 & 0xffff);
    if ((ushort)local_70 <= uVar11) {
      memmove((void *)((longlong)pvVar14 + uVar6),pvStack_68,local_70 & 0xffff);
      local_78[0] = ((ushort)local_70 - uVar11) + 0x39c;
      ppuVar17 = (undefined **)0x0;
      do {
        uVar11 = (uint)uVar7;
        local_58 = 0;
        puStack_50 = (undefined2 *)0x0;
        bVar16 = *(byte *)((longlong)&local_38 + (longlong)ppuVar17);
        uVar19 = (uint)bVar16;
        ppuVar5 = ppuVar17;
        if (uVar19 == 2) {
          puVar13 = local_40;
LAB_140009c93:
          if (puVar13 != (undefined2 *)0x0) {
LAB_140009c9c:
            uVar4 = uVar11 + 4;
            if (0xe < uVar11) {
              uVar4 = 0x12;
            }
            DAT_14002a481 = (ushort)uVar4;
            _DAT_14002a486 = 0x200;
            bVar18 = 1;
            DAT_14002a488 = (undefined1)uVar11;
            DAT_14002a485 = bVar16;
            memmove(&DAT_14002a489,puVar13,(ulonglong)(uVar4 & 0xffff) - 4);
            uVar7 = (ulonglong)DAT_14002a481;
            puVar15 = &callbackBuffer;
            *(undefined2 *)(&DAT_14002a486 + uVar7) = 4;
            ppuVar5 = (undefined **)
                      ipmi_ioctl_func((longlong *)(local_48 + 0x138),0x222008,&callbackBuffer);
            if ((int)ppuVar5 != 0) break;
            cVar1 = (&DAT_14002a488)[uVar7];
            if (cVar1 == '\0') {
              if (0xe < uVar11) {
                puVar13 = puVar13 + 7;
                for (uVar11 = uVar11 - 0xe; uVar11 != 0; uVar11 = uVar11 - 0x10) {
                  DAT_14002a481 = (short)uVar11 + 2;
                  if (0x10 < uVar11) {
                    DAT_14002a481 = 0x12;
                  }
                  uVar2 = (ushort)_DAT_14002a486 >> 8;
                  _DAT_14002a486 = CONCAT11((char)uVar2,bVar18);
                  bVar18 = bVar18 + 1;
                  DAT_14002a485 = bVar16;
                  memmove(&DAT_14002a487,puVar13,(ulonglong)DAT_14002a481 - 2);
                  uVar7 = (ulonglong)DAT_14002a481;
                  *(undefined2 *)(&DAT_14002a486 + uVar7) = 4;
                  ppuVar5 = (undefined **)
                            ipmi_ioctl_func((longlong *)(local_48 + 0x138),0x222008,&callbackBuffer)
                  ;
                  if (((int)ppuVar5 != 0) || ((&DAT_14002a488)[uVar7] != (char)ppuVar5)) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar18,
                                 (ulonglong)(byte)(&DAT_14002a488)[uVar7],
                                 (uint)*(byte *)((longlong)&local_38 + (longlong)ppuVar17),
                                 (&DAT_14002a488)[uVar7],bVar18);
                    }
                    _DAT_14002a486 = 0;
                    DAT_14002a481 = 4;
                    _DAT_14002a48a = 4;
                    DAT_14002a488 = 0;
                    DAT_14002a485 = *(byte *)((longlong)&local_38 + (longlong)ppuVar17);
                    ppuVar5 = (undefined **)
                              ipmi_ioctl_func((longlong *)(local_48 + 0x138),0x222008,
                                              &callbackBuffer);
                    break;
                  }
                  if (uVar11 < 0x11) break;
                  puVar13 = puVar13 + 8;
                }
              }
            }
            else {
              if (cVar1 != -0x80) {
                ppuVar5 = &WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (ppuVar5 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
                   (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                  ppuVar5 = (undefined **)
                            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,puVar15,
                                      (uint)bVar16,cVar1);
                }
                break;
              }
              ppuVar5 = &WPP_GLOBAL_Control;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (ppuVar5 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
                 (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                ppuVar5 = (undefined **)
                          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                                   &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,uVar19);
              }
            }
          }
        }
        else {
          if (uVar19 != 4) {
            if (uVar19 == 5) {
              pwVar10 = L"10.0";
              goto LAB_140009c72;
            }
            if (((uVar19 != 8) && (uVar19 != 9)) || (lVar20 != 1)) goto LAB_140009ea2;
            puVar13 = &DAT_14002a4e4;
            uVar11 = local_78[0];
            goto LAB_140009c9c;
          }
          if (lVar20 != 0) {
            iVar3 = GetProductType();
            if (iVar3 == 0x196) {
              pwVar10 = L"Microsoft Azure Stack HCI";
            }
            else {
              pwVar10 = L"Windows Server 2025";
              if (lVar20 != 1) {
                pwVar10 = L"Windows 11";
              }
            }
LAB_140009c72:
            ppuVar5 = (undefined **)RtlInitUnicodeString(&local_58,pwVar10);
            uVar11 = (uint)(ushort)local_58;
            puVar13 = puStack_50;
            goto LAB_140009c93;
          }
        }
LAB_140009ea2:
        bVar16 = (char)ppuVar17 + 1;
        ppuVar17 = (undefined **)(ulonglong)bVar16;
        if (4 < bVar16) {
          return CONCAT71((int7)((ulonglong)ppuVar5 >> 8),1);
        }
        uVar7 = (ulonglong)local_60[0];
      } while( true );
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (ppuVar5 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140009b5c;
    uVar9 = 0x1f;
LAB_140009b4c:
    ppuVar5 = (undefined **)
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                      &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
LAB_140009b5c:
  return (ulonglong)ppuVar5 & 0xffffffffffffff00;
}



===== WPP_SF_DD @ 140009f04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 140009f5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,0x23,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DDDI @ 140009fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,0x16,local_res20,4,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_s @ 14000a034 =====

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
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,param_2,param_4,lVar2,0);
  return;
}



===== WriteOSBootupSEL @ 14000a09c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong WriteOSBootupSEL(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined8 uVar4;
  longlong *plVar5;
  undefined2 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined1 auStackY_2c8 [32];
  uint local_298;
  uint local_294 [3];
  undefined8 local_288;
  longlong local_280 [3];
  undefined4 local_268;
  undefined1 local_264;
  undefined4 local_263;
  undefined8 local_25f;
  undefined2 local_256;
  char local_254;
  short local_24e;
  char local_24c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2c8;
  memset(&local_268,0,0x248);
  local_298 = 0;
  local_288 = 0;
  local_280[1] = 0;
  local_280[2] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  RtlInitUnicodeString(local_280 + 1,L"OSBootTime");
  local_294[1] = 4;
  QueryConfigFromRegistry
            ((longlong *)&CONFIG_KEY,(longlong)(local_280 + 1),(undefined8 *)0x4,&local_298,
             local_294 + 1,'\0');
  uVar1 = KeQueryTimeIncrement();
  local_280[0] = (((longlong)(int)(_DAT_fffff78000000014 >> 0x20) << 0x20) -
                 (((longlong)(int)(_DAT_fffff78000000320 >> 0x20) << 0x20) +
                 (_DAT_fffff78000000320 & 0xffffffff)) * (ulonglong)uVar1) +
                 (_DAT_fffff78000000014 & 0xffffffff);
  ExSystemTimeToLocalTime(local_280,&local_288);
  lVar7 = ((longlong)local_288._4_4_ << 0x20) + -0x19db1ded53e8000 + (local_288 & 0xffffffff);
  lVar7 = lVar7 + SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar7),8);
  puVar8 = (undefined8 *)(ulonglong)local_298;
  uVar3 = -(lVar7 >> 0x3f);
  local_294[0] = (int)(lVar7 >> 0x17) + (int)uVar3;
  if (local_298 < local_294[0]) {
    local_264 = *(undefined1 *)(param_1 + 0x159);
    local_263 = 0x2100008;
    local_254 = -1;
    uVar3 = IpmiComputeBufferResponseLength(8);
    local_256 = (undefined2)uVar3;
    AssembleBootupHead((undefined4 *)&local_25f);
    iVar2 = ipmi_send_request(param_1,&local_268);
    uVar3 = CONCAT44(extraout_var,iVar2);
    if ((iVar2 == 0) && (local_254 == '\0')) {
      local_263 = 0x44280010;
      local_24c = -1;
      uVar3 = IpmiComputeBufferResponseLength(0x10);
      local_24e = (short)uVar3;
      AssembleBootupBody(&local_25f,local_294);
      iVar2 = ipmi_send_request(param_1,&local_268);
      uVar3 = CONCAT44(extraout_var_00,iVar2);
      if (((iVar2 == 0) && (local_24c == '\0')) && (local_24e == 2)) {
        plVar5 = local_280 + 1;
        RtlInitUnicodeString(plVar5,L"OSBootTime");
        uVar4 = WriteToRegistry(plVar5,(longlong)(local_280 + 1),puVar8,(longlong)local_294);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar4 = WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                          &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
        }
        return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar3 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000a3a9;
      uVar6 = 0x27;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (uVar3 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_14000a3a9;
      uVar6 = 0x26;
    }
    uVar3 = WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                     &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids,iVar2);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar3 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    uVar3 = WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,puVar8,local_294[0],
                      (char)local_298);
  }
LAB_14000a3a9:
  return uVar3 & 0xffffffffffffff00;
}



===== IoTarget_Open @ 14000a3dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoTarget_Open(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong in_stack_ffffffffffffff48;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_50 = 0x30;
  local_38 = 0x200;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = param_2;
  iVar2 = ZwCreateFile(0,0xc0000000,&local_50,&local_78,0,0x80,
                       in_stack_ffffffffffffff48 & 0xffffffff00000000,1,0x50,0,0);
  if (-1 < iVar2) {
    iVar2 = ObReferenceObjectByHandle
                      (*param_1,0xc0000000,*(undefined8 *)IoFileObjectType_exref,0,param_1 + 1,0);
    if (-1 < iVar2) {
      lVar4 = IoGetRelatedDeviceObject(param_1[1]);
      param_1[2] = lVar4;
      if (lVar4 == 0) {
        iVar2 = -0x3ffffff2;
      }
      else {
        local_58 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_88 = 0;
        uStack_80 = 0;
        KeInitializeEvent(&local_68,0,0);
        lVar4 = IoBuildSynchronousFsdRequest(0x1b,param_1[2],0,0,0,&local_68,&local_88);
        if (lVar4 != 0) {
          lVar1 = *(longlong *)(lVar4 + 0xb8);
          *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
          *(undefined8 *)(lVar4 + 0x38) = 0;
          *(undefined **)(lVar1 + -0x40) = &GUID_I2C_INTERFACE;
          *(undefined **)(lVar1 + -0x30) = &I2cInterface;
          *(undefined1 *)(lVar1 + -0x47) = 8;
          *(undefined4 *)(lVar1 + -0x38) = 0x10028;
          *(undefined8 *)(lVar1 + -0x28) = 0;
          iVar3 = IofCallDriver(param_1[2],lVar4);
          if (iVar3 == 0x103) {
            KeWaitForSingleObject(&local_68,0,0,0,0);
            iVar3 = (int)local_88;
          }
          if (-1 < iVar3) {
            I2cInterfaceReady = 1;
            (*DAT_14002a250)(DAT_14002a248);
          }
        }
      }
    }
  }
  return iVar2;
}



===== RESOURCE_HUB_STRING_PRINTF @ 14000a5e8 =====

void RESOURCE_HUB_STRING_PRINTF
               (wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res20 = param_4;
  RtlStringCbVPrintfExW
            (param_1,param_2,(longlong *)0x0,param_4,in_stack_ffffffffffffffc8,param_3,
             (va_list)&local_res20);
  return;
}



===== RESOURCE_HUB_UNICODE_STRING_PRINTF @ 14000a618 =====

void RESOURCE_HUB_UNICODE_STRING_PRINTF
               (short *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar1 = RtlStringCbVPrintfExW
                    (*(wchar_t **)(param_1 + 4),(ulonglong)(ushort)param_1[1],local_18,param_4,
                     in_stack_ffffffffffffffc8,param_2,(va_list)&local_res18);
  if (-1 < iVar1) {
    *param_1 = (short)((longlong)(ulonglong)(uint)((int)local_18[0] - *(int *)(param_1 + 4)) >> 1) *
               2;
  }
  return;
}



===== RtlStringCbVPrintfExW @ 14000a67c =====

int RtlStringCbVPrintfExW
              (wchar_t *param_1,ulonglong param_2,longlong *param_3,undefined8 param_4,
              undefined8 param_5,wchar_t *param_6,va_list param_7)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _Count;
  int iVar3;
  
  if (0x7ffffffe < (param_2 >> 1) - 1) {
    return -0x3ffffff3;
  }
  _Count = (param_2 >> 1) - 1;
  iVar3 = 0;
  iVar1 = _vsnwprintf(param_1,_Count,param_6,param_7);
  if (iVar1 < 0) {
LAB_14000a6ea:
    iVar3 = -0x7ffffffb;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_Count < uVar2) goto LAB_14000a6ea;
    if (uVar2 != _Count) {
      _Count = uVar2;
      goto LAB_14000a6f1;
    }
  }
  param_1[_Count] = L'\0';
LAB_14000a6f1:
  if (((-1 < iVar3) || (iVar3 == -0x7ffffffb)) && (param_3 != (longlong *)0x0)) {
    *param_3 = (longlong)(param_1 + _Count);
  }
  return iVar3;
}



===== SSIFReceiveResponseFromBMC @ 14000a72c =====

int SSIFReceiveResponseFromBMC
              (longlong param_1,void *param_2,ushort *param_3,undefined8 param_4,undefined1 *param_5
              )

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res20;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  bVar1 = false;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_res20 = param_4;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  KeInitializeEvent(&local_48,0,0);
  spb_request = '\x03';
  *param_3 = 0;
  while( true ) {
    lVar3 = IoBuildDeviceIoControlRequest
                      (0x41808,*(undefined8 *)(param_1 + 0x90),&cmd,0x50,0,0,0,&local_48,&local_58);
    if (lVar3 == 0) {
      iVar2 = -0x3fffffe9;
      goto LAB_14000a983;
    }
    *(undefined8 *)(*(longlong *)(lVar3 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0x88);
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x90),lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_48,0,0,0,0);
      iVar2 = (int)local_58;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,(uint)(ushort)uStack_50);
      }
    }
    KeClearEvent(&local_48);
    if (uStack_50 < 4) break;
    if (iVar2 < 0) goto LAB_14000a983;
    if (spb_request == '\x03') {
      *param_5 = DAT_14002a2e3;
    }
    *param_3 = *param_3 + SPBReadBuffer + 1;
    if (0x122 < *param_3) {
      iVar2 = -0x3fffffc2;
      goto LAB_14000a983;
    }
    memmove(param_2,&SPBReadBuffer,(ulonglong)(SPBReadBuffer + 1));
    param_2 = (void *)((longlong)param_2 + (ulonglong)(SPBReadBuffer + 1));
    if ((DAT_14002a2e1 == '\0') && (DAT_14002a2e2 == '\x01')) {
      bVar1 = true;
      *param_5 = DAT_14002a2e5;
      spb_request = '\t';
    }
    else {
      local_res20 = 0xfffffffffffcf2c0;
      KeDelayExecutionThread(0,0,&local_res20);
      iVar2 = 0;
      if ((DAT_14002a2e1 == -1) || (!bVar1)) goto LAB_14000a983;
    }
  }
  iVar2 = -0x3fffffc2;
LAB_14000a983:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,iVar2);
  }
  return iVar2;
}



===== SSIFSendRequestToBMC @ 14000a9e0 =====

int SSIFSendRequestToBMC(longlong param_1,longlong param_2,ushort param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  undefined8 local_res20;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_res20 = param_4;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  KeInitializeEvent(&local_48,0,0);
  local_res20 = 0;
  do {
    iVar1 = 0;
    if (param_3 == 0) {
LAB_14000ab4d:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,iVar1);
      }
      return iVar1;
    }
    uVar3 = 0x22;
    if (param_3 < 0x23) {
      uVar3 = param_3;
    }
    lVar2 = IoBuildSynchronousFsdRequest
                      (4,*(undefined8 *)(param_1 + 0x90),param_2,uVar3,&local_res20,&local_48,
                       &local_58);
    if (lVar2 == 0) {
      iVar1 = -0x3fffffe9;
      goto LAB_14000ab4d;
    }
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0x88);
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 0x90),lVar2);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_48,0,0,0,0);
      iVar1 = (int)local_58;
    }
    if (iVar1 < 0) goto LAB_14000ab4d;
    if (uStack_50 != uVar3) {
      iVar1 = -0x3fffffc2;
      goto LAB_14000ab4d;
    }
    KeClearEvent(&local_48);
    param_2 = param_2 + (ulonglong)uVar3;
    param_3 = param_3 - uVar3;
  } while( true );
}



===== SSIF_BMC_Transact @ 14000aba8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SSIF_BMC_Transact(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  ushort uVar6;
  ulonglong local_res8;
  
  uVar2 = SsifRetryCount;
  bVar5 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  uVar3 = 0xc0000001;
  uVar4 = 0xc000022d;
  if (uVar2 != 0) {
    if (*(char *)(param_1 + 0xc0) == '\0') {
      do {
        if (-1 < (int)uVar3) break;
        bVar5 = bVar5 + 1;
        if ((uVar4 & 0xc0000000) == 0xc0000000) {
          uVar6 = *param_2;
          if (0x121 < uVar6) {
            uVar6 = 0x122;
          }
          uVar3 = SSIFSendRequestToBMC(param_1,(longlong)param_2 + 5,uVar6,param_4);
          uVar4 = uVar3;
        }
        if (SsifRetryDelay < 0x32) {
          KeStallExecutionProcessor(SsifRetryDelay);
        }
        else {
          local_res8 = (ulonglong)(int)(SsifRetryDelay * -10);
          KeDelayExecutionThread(0,0,&local_res8);
        }
        if (-1 < (int)uVar4) {
          puVar1 = param_2 + 1;
          local_res8 = CONCAT71(local_res8._1_7_,0xff);
          uVar6 = *puVar1;
          if (uVar6 < 0x122) {
            uVar6 = 0x122;
          }
          *puVar1 = uVar6;
          uVar3 = SSIFReceiveResponseFromBMC
                            (param_1,(void *)((longlong)param_2 + 0x127),puVar1,param_4,
                             (undefined1 *)&local_res8);
        }
      } while (bVar5 < uVar2);
    }
    else {
      do {
        if (-1 < (int)uVar3) break;
        local_res8 = local_res8 & 0xffffffff00000000;
        bVar5 = bVar5 + 1;
        if (I2cInterfaceReady == '\0') {
          uVar3 = 0;
        }
        else {
          uVar6 = *param_2;
          if (0x121 < uVar6) {
            uVar6 = 0x122;
          }
          uVar3 = (*DAT_14002a260)((longlong)param_2 + 5,uVar6,0,0,&local_res8);
        }
      } while (bVar5 < uVar2);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,uVar3);
  }
  return uVar3;
}



===== SSIF_IPMI_Message_Pack @ 14000ad80 =====

undefined8 SSIF_IPMI_Message_Pack(ushort *param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  void *_Src;
  
  if ((param_2 == 0) || (param_1 == (ushort *)0x0)) {
    uVar1 = 0xc000003e;
  }
  else {
    sVar5 = 0x1e;
    puVar2 = (undefined1 *)((longlong)param_1 + 5);
    if (*(ushort *)(param_2 + 1) < 0x1f) {
      *puVar2 = 2;
      sVar5 = *(short *)(param_2 + 1);
    }
    else {
      *puVar2 = 6;
    }
    uVar4 = sVar5 + 2;
    _Src = (void *)(param_2 + 3);
    *(char *)(param_1 + 3) = (char)uVar4;
    memmove((void *)((longlong)param_1 + 7),_Src,(ulonglong)uVar4);
    *param_1 = sVar5 + 4;
    param_1[1] = 0x122;
    if (0x20 < *(ushort *)(param_2 + 1)) {
      for (uVar3 = *(ushort *)(param_2 + 1) - sVar5; (uVar3 != 0 && (uVar3 < 0x122));
          uVar3 = uVar3 - uVar4) {
        _Src = (void *)((longlong)_Src + (ulonglong)uVar4);
        puVar2 = (undefined1 *)((longlong)param_1 + (ulonglong)*param_1 + 5);
        if (uVar3 < 0x21) {
          uVar4 = uVar3;
        }
        else {
          uVar4 = 0x20;
        }
        *param_1 = *param_1 + 2 + uVar4;
        *puVar2 = 7;
        memmove(puVar2 + 2,_Src,(ulonglong)uVar4);
        puVar2[1] = (char)uVar4;
      }
      *puVar2 = 8;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== SSIF_IPMI_Message_unPack @ 14000aec4 =====

undefined4 SSIF_IPMI_Message_unPack(ushort *param_1,longlong param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined4 unaff_EDI;
  undefined4 uVar5;
  ushort uVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  uVar5 = 0;
  if ((param_1 == (ushort *)0x0) || (param_2 == 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EDI;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return unaff_EDI;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,0xc000000d);
    return unaff_EDI;
  }
  uVar6 = 0;
  if ((ulonglong)*param_1 + 4 < (ulonglong)*(ushort *)(param_2 + 2)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EDI;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,0xc0000017);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EDI;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,(uint)*param_1);
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EDI;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return unaff_EDI;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,(uint)*(ushort *)(param_2 + 2));
    return unaff_EDI;
  }
  if ((*(char *)(param_2 + 0x128) == '\0') && (*(char *)(param_2 + 0x129) == '\x01')) {
    cVar1 = *(char *)(param_2 + 300);
    *(char *)(param_1 + 1) = cVar1;
    *param_1 = 0;
    if (cVar1 != '\0') goto LAB_14000b0dd;
    if (6 < *(ushort *)(param_2 + 2)) {
      *param_1 = *(ushort *)(param_2 + 2) - 6;
      uVar2 = *(byte *)(param_2 + 0x127) - 5;
      *param_1 = uVar2;
      memmove((void *)((longlong)param_1 + 3),(void *)(param_2 + 0x12d),(ulonglong)uVar2);
      while( true ) {
        uVar2 = *param_1;
        uVar6 = uVar6 + *(byte *)(param_2 + 0x127) + 1;
        uVar4 = (ulonglong)uVar6;
        uVar3 = (*(byte *)(param_2 + 0x127 + uVar4) + uVar2) - 1;
        *param_1 = uVar3;
        if (0x121 < uVar3) break;
        memmove((void *)((ulonglong)uVar2 + 3 + (longlong)param_1),(void *)(param_2 + 0x129 + uVar4)
                ,(ulonglong)*(byte *)(param_2 + 0x127 + uVar4) - 1);
        if ((*(char *)(param_2 + 0x128 + uVar4) == -1) || (0x121 < *param_1)) goto LAB_14000b0dd;
      }
      uVar5 = 0xc000003e;
      goto LAB_14000b0dd;
    }
  }
  cVar1 = *(char *)(param_2 + 0x12a);
  *(char *)(param_1 + 1) = cVar1;
  *param_1 = 0;
  if ((cVar1 == '\0') && (4 < *(ushort *)(param_2 + 2))) {
    uVar6 = *(ushort *)(param_2 + 2) - 4;
    *param_1 = uVar6;
    memmove((void *)((longlong)param_1 + 3),(void *)(param_2 + 299),(ulonglong)uVar6);
  }
LAB_14000b0dd:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,uVar5);
  }
  return unaff_EDI;
}



===== SSIF_RequestandReceive @ 14000b160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SSIF_RequestandReceive
                    (longlong param_1,longlong param_2,ushort *param_3,ulonglong param_4)

{
  uint uVar1;
  uint extraout_EAX;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_2a8 [32];
  ushort local_288 [296];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2a8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  lVar2 = Func_GetTimeOut(*(int *)(param_1 + 0x48));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_4 = (ulonglong)*param_3;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,(uint)*param_3);
  }
  memset(local_288,0,0x24a);
  uVar3 = SSIF_IPMI_Message_Pack(local_288,param_2);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == 0) {
    uVar1 = SSIF_BMC_Transact(param_1,local_288,lVar2,param_4);
    uVar4 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      SSIF_IPMI_Message_unPack(param_3,(longlong)local_288);
      uVar4 = (ulonglong)extraout_EAX;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,(int)uVar4);
  }
  return uVar4;
}



===== SSIF_abort @ 14000b290 =====

undefined8 SSIF_abort(void)

{
  return 0;
}



===== SSIF_cleanup @ 14000b2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SSIF_cleanup(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = param_1[0x10];
  if (param_1[0x11] != 0) {
    ObfDereferenceObject();
  }
  if (lVar1 != 0) {
    ObCloseHandle(lVar1,0);
  }
  if (I2cInterfaceReady != '\0') {
    (*DAT_14002a258)(DAT_14002a248);
  }
  *param_1 = 0;
  return 0;
}



===== SSIF_init @ 14000b320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SSIF_init(undefined8 *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  short local_108 [4];
  wchar_t *local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  wchar_t local_f0 [8];
  undefined1 *local_e0;
  undefined8 uStack_d8;
  wchar_t local_c8 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_138;
  local_100 = local_c8;
  local_108[0] = 0;
  local_108[1] = 0x98;
  local_108[2] = 0;
  local_108[3] = 0;
  iVar3 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids);
  }
  local_f8 = *(undefined4 *)(param_1 + 0xf);
  pwVar4 = L"%0*I64x";
  uStack_f4 = *(undefined4 *)((longlong)param_1 + 0x7c);
  local_118 = param_1[0xf];
  pwVar2 = (wchar_t *)0x22;
  iVar1 = RESOURCE_HUB_STRING_PRINTF(local_f0,0x22,L"%0*I64x",0x10);
  if (-1 < iVar1) {
    pwVar4 = L"\\Device\\RESOURCE_HUB\\";
    pwVar2 = L"%s%s";
    RESOURCE_HUB_UNICODE_STRING_PRINTF(local_108,L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_f0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar2,pwVar4,local_100);
  }
  iVar1 = IoTarget_Open(param_1 + 0x10,local_108);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,iVar1);
    }
    iVar3 = iVar1;
  }
  else {
    *param_1 = &cSSIFEngine;
    local_f0[4] = L'\x01';
    local_f0[5] = L'\0';
    local_f0[6] = L'\0';
    local_f0[7] = L'\0';
    _DAT_14002a2a0 = &spb_request;
    uRam000000014002a2a8 = 1;
    uStack_d8 = 0x21;
    _DAT_14002a290 = 2;
    uRam000000014002a298 = 1;
    local_f0[0] = L'\x01';
    local_f0[1] = L'\0';
    local_f0[2] = L'\0';
    local_f0[3] = L'\0';
    local_e0 = &SPBReadBuffer;
    _cmd = 0x30;
    _DAT_14002a288 = 2;
    _DAT_14002a2c0 = &SPBReadBuffer;
    uRam000000014002a2c8 = 0x21;
    _DAT_14002a2b0 = 1;
    uRam000000014002a2b8 = 1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,iVar3);
  }
  return iVar3;
}



===== WPP_SF_S @ 14000b544 =====

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
            (param_1,0x2b,&WPP_d5feaabe301539cca3b1206438cdd628_Traceguids,0x1c,param_4,lVar1,0);
  return;
}



===== SMBIOSRecord38Found @ 14000b5bc =====

byte SMBIOSRecord38Found(void *param_1)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  byte bVar4;
  int *piVar5;
  undefined7 extraout_var;
  char *pcVar6;
  ushort uVar7;
  ulonglong _Size;
  undefined2 uVar8;
  int *piVar9;
  char *_Src;
  byte bVar10;
  uint uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uStack_32;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids);
  }
  piVar5 = (int *)MmMapIoSpaceEx(0xf0000,0xffff,0x204);
  bVar10 = 0;
  if (piVar5 == (int *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0;
    }
    uVar8 = 0xd;
  }
  else {
    for (piVar9 = piVar5; piVar9 <= piVar5 + 0x3ff8; piVar9 = piVar9 + 4) {
      if ((*piVar9 == 0x5f4d535f) &&
         (bVar4 = smbios_checksum((longlong)piVar9,(uint)*(byte *)((longlong)piVar9 + 5)),
         (int)CONCAT71(extraout_var,bVar4) == 0)) {
        uVar3 = *(ushort *)(piVar9 + 7);
        uStack_32 = (ushort)((ulonglong)*(undefined8 *)(piVar9 + 4) >> 0x30);
        pcVar6 = (char *)MmMapIoSpaceEx(piVar9[6],uStack_32,0x204);
        if (pcVar6 != (char *)0x0) {
          MmUnmapIoSpace(piVar5,0xffff);
          uVar12 = 0;
          uVar13 = 0;
          _Src = pcVar6;
          if (uVar3 == 0) goto LAB_14000b7d8;
          goto LAB_14000b76d;
        }
        MmUnmapIoSpace();
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return 0;
        }
        uVar8 = 0xf;
        goto LAB_14000b6b5;
      }
    }
    MmUnmapIoSpace(piVar5,0xffff);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0;
    }
    uVar8 = 0xe;
  }
LAB_14000b6b5:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
           &WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids,0);
  return 0;
  while( true ) {
    if (*_Src == '&') {
      memmove(param_1,_Src,_Size);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        bVar10 = *(byte *)((longlong)param_1 + 0x10);
        uVar11 = bVar10 >> 1 & 1;
        WPP_SF_DiDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(bVar10 & 1),
                        (ulonglong)uVar11,(uint)*(byte *)((longlong)param_1 + 4),
                        (char)*(undefined8 *)((longlong)param_1 + 8),
                        *(undefined1 *)((longlong)param_1 + 0x11),bVar10 >> 4 & 1,(char)(bVar10 & 1)
                        ,(char)uVar11,bVar10 >> 3 & 1,*(undefined1 *)((longlong)param_1 + 6));
      }
      bVar10 = 1;
      break;
    }
    pcVar1 = _Src + _Size;
    uVar11 = (uint)bVar4;
    while ((uVar11 < (uint)uStack_32 - (uint)uVar12 &&
           ((cVar2 = *pcVar1, pcVar1 = pcVar1 + 1, cVar2 != '\0' || (*pcVar1 != '\0'))))) {
      uVar7 = (short)_Size + 1;
      _Size = (ulonglong)uVar7;
      uVar11 = (uint)uVar7;
    }
    uVar7 = (short)_Size + 2;
    if ((uint)uStack_32 - (uint)uVar12 < (uint)uVar7) break;
    uVar12 = uVar12 + uVar7;
    _Src = _Src + uVar7;
    uVar13 = uVar13 + 1;
    if (uVar3 <= uVar13) break;
LAB_14000b76d:
    bVar4 = _Src[1];
    _Size = (ulonglong)bVar4;
    if ((uint)uStack_32 < (uint)uVar12 + (uint)bVar4) break;
  }
LAB_14000b7d8:
  MmUnmapIoSpace(pcVar6,uStack_32);
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return bVar10;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
    return bVar10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
           &WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids,(uint)bVar10);
  return bVar10;
}



===== WPP_SF_DiDDDDDD @ 14000b8b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DiDDDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids,0x10,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== smbios_checksum @ 14000b964 =====

byte smbios_checksum(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids);
  }
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      uVar1 = (ulonglong)uVar2;
      uVar2 = uVar2 + 1;
      bVar3 = bVar3 + *(char *)(uVar1 + param_1);
    } while (uVar2 < param_2);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_440dcddfe27637c627c3f5fc55249aaa_Traceguids,(uint)bVar3);
  }
  return bVar3;
}



===== KcsAbort @ 14000ba10 =====

ulonglong KcsAbort(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  lVar1 = IpmiLibpGetTimeout(param_1,(ulonglong)*(uint *)(param_1 + 0x48));
  uVar2 = IpmiLibpKcsSpinRegister(param_1 + 8,lVar1,2);
  uVar3 = 0;
  if ((int)uVar2 == 0) {
    IpmiLibWriteOneByte(param_1 + 8,1,0x60);
  }
  else {
    uVar3 = 0x102;
  }
  return uVar3 & 0xffffffff;
}



===== KcsCleanup @ 14000ba60 =====

undefined8 KcsCleanup(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if ((*(char *)(param_1 + 0x13) != '\0') && ((*(uint *)(param_1 + 5) & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x13) = 0;
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffffe;
    Func_InterruptClean((longlong)param_1,param_2,'\x01');
  }
  *param_1 = 0;
  uVar1 = IpmiHwContextInitialized((longlong)(param_1 + 1));
  if ((char)uVar1 != '\0') {
    if (((*(int *)((longlong)param_1 + 0xc) == 1) && (*(char *)(param_1 + 4) == '\0')) &&
       (*(int *)(param_1 + 0xe) != 0)) {
      MmUnmapIoSpace(param_1[0xd],*(int *)(param_1 + 0xe));
      param_1[0xd] = 0;
      *(undefined4 *)(param_1 + 0xe) = 0;
    }
    LOCK();
    *(undefined1 *)(param_1 + 0xc) = 0;
    UNLOCK();
  }
  return 0;
}



===== KcsInit @ 14000baf0 =====

undefined8 KcsInit(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = IpmiHwInitializeContext
                    ((undefined8 *)(-(ulonglong)(param_1[3] != 0) & (ulonglong)(param_1 + 1)),
                     (ushort *)(param_1 + 1));
  if (-1 < (int)uVar1) {
    *param_1 = &KcsEngine;
    uVar1 = 0;
  }
  return uVar1;
}



===== KcsMessageTransfer @ 14000bb30 =====

ulonglong KcsMessageTransfer(longlong param_1,void *param_2,ushort param_3,char *param_4,
                            void *param_5,ushort *param_6)

{
  ulonglong uVar1;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    uVar1 = IpmiLibpKcsMessageTransfer
                      ((void *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== KcsSmsAtn @ 14000bb70 =====

undefined8 KcsSmsAtn(longlong param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    uVar1 = IpmiLibpKcsSmsAtn(param_1 + 8,param_2);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== WdmlibRtlInitUnicodeStringEx @ 14000bb98 =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== IpmiHwContextInitialized @ 14000bbe4 =====

ulonglong IpmiHwContextInitialized(longlong param_1)

{
  byte bVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    return in_RAX & 0xffffffffffffff00;
  }
  uVar2 = 0;
  LOCK();
  bVar1 = *(byte *)(param_1 + 0x58);
  if (bVar1 == 0) {
    *(byte *)(param_1 + 0x58) = 0;
  }
  else {
    uVar2 = (ulonglong)bVar1;
  }
  UNLOCK();
  return uVar2;
}



===== IpmiHwInitializeContext @ 14000bc00 =====

undefined8 IpmiHwInitializeContext(undefined8 *param_1,ushort *param_2)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  ushort *puVar5;
  
  puVar5 = param_2;
  uVar3 = IpmiHwContextInitialized((longlong)param_2);
  if ((char)uVar3 != '\0') {
    return 0;
  }
  if (param_1 == (undefined8 *)0x0) {
    uVar3 = IpmiHwpReadSpmiConfiguration(puVar5);
    if (((int)uVar3 < 0) && (iVar2 = IpmiHwpReadSmbiosConfiguration(param_2), iVar2 < 0))
    goto LAB_14000bc7a;
  }
  else {
    uVar1 = param_1[1];
    *(undefined8 *)puVar5 = *param_1;
    *(undefined8 *)(puVar5 + 4) = uVar1;
    uVar1 = param_1[3];
    *(undefined8 *)(puVar5 + 8) = param_1[2];
    *(undefined8 *)(puVar5 + 0xc) = uVar1;
  }
  param_2[0x2a] = 7;
  param_2[0x2b] = 0;
  param_2[0x22] = 0x4b40;
  param_2[0x23] = 0x4c;
  param_2[0x28] = 0x4b40;
  param_2[0x29] = 0x4c;
  param_2[0x26] = 1000;
  param_2[0x27] = 0;
  param_2[0x24] = 0x1e;
  param_2[0x25] = 0;
  param_2[0x20] = 0x8480;
  param_2[0x21] = 0x1e;
LAB_14000bc7a:
  if ((*(int *)(param_2 + 2) != 1) ||
     ((uVar3 = IpmiHwContextInitialized((longlong)param_2), (char)uVar3 != '\0' &&
      ((char)param_2[0xc] == '\0')))) {
    return 0xc00000bb;
  }
  if (*(longlong *)(param_2 + 8) == 0) {
    return 0xc000000d;
  }
  param_2[0x30] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = 0;
  param_2[0x33] = 0;
  param_2[0x34] = 0;
  param_2[0x35] = 0;
  param_2[0x36] = 0;
  param_2[0x37] = 0;
  if ((char)param_2[0xc] == '\0') {
    lVar4 = MmMapIoSpaceEx(*(undefined8 *)(param_2 + 8),(ulonglong)(byte)param_2[4] * 2,0x204);
    *(longlong *)(param_2 + 0x30) = lVar4;
    if (lVar4 == 0) {
      return 0xc0000001;
    }
    iVar2 = (uint)(byte)param_2[4] * 2;
  }
  else {
    *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_2 + 8);
    iVar2 = 0;
  }
  *(int *)(param_2 + 0x34) = iVar2;
  LOCK();
  *(undefined1 *)(param_2 + 0x2c) = 1;
  UNLOCK();
  return 0;
}



===== IpmiHwpParseSpmiTable @ 14000bd18 =====

undefined8 IpmiHwpParseSpmiTable(ushort *param_1,longlong param_2)

{
  char cVar1;
  short sVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
  sVar2 = *(short *)(param_2 + 0x26);
  if ((sVar2 == 0x100) || ((sVar2 != 0x150 && (sVar2 != 0x200)))) {
    return 0xc00000bb;
  }
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *param_1 = *(ushort *)(param_2 + 0x26) >> 4;
  *(uint *)(param_1 + 2) = (uint)*(byte *)(param_2 + 0x24);
  cVar1 = *(char *)(param_2 + 0x30);
  *(char *)(param_1 + 0xc) = cVar1;
  uVar3 = (ulonglong)((uint)*(ulonglong *)(param_2 + 0x34) & 0xfe);
  if (cVar1 != '\x04') {
    uVar3 = *(ulonglong *)(param_2 + 0x34);
  }
  uVar4 = 0;
  *(ulonglong *)(param_1 + 8) = uVar3;
  cVar1 = *(char *)(param_2 + 0x33);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      uVar4 = 1;
    }
    else if (cVar1 == '\x02') {
      uVar4 = 2;
    }
    else if (cVar1 == '\x03') {
      uVar4 = 4;
    }
    else if (cVar1 == '\x04') {
      uVar4 = 8;
    }
  }
  *(undefined1 *)(param_1 + 4) = uVar4;
  *(undefined1 *)((longlong)param_1 + 0x19) = 0x20;
  return 0;
}



===== IpmiHwpReadSpmiConfiguration @ 14000bdc0 =====

ulonglong IpmiHwpReadSpmiConfiguration(ushort *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 local_res10 [2];
  
  lVar2 = 0;
  local_res10[0] = 0;
  uVar1 = ExGetSystemFirmwareTable(0x41435049,0x494d5053,0,0,local_res10);
  if (uVar1 == 0xc0000023) {
    lVar2 = ExAllocatePool2(0x100,local_res10[0],0x494d5049);
    if (lVar2 == 0) {
      return 0xc0000017;
    }
    uVar1 = ExGetSystemFirmwareTable(0x41435049,0x494d5053,lVar2,local_res10[0],local_res10);
  }
  uVar3 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar3 = IpmiHwpParseSpmiTable(param_1,lVar2);
    uVar3 = uVar3 & 0xffffffff;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x494d5049);
  }
  return uVar3;
}



===== IpmiHwpReadSmbiosConfiguration @ 14000be9c =====

int IpmiHwpReadSmbiosConfiguration(ushort *param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined2 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = IpmiLibReadSmbiosRecord38((undefined4 *)&local_28);
  uVar2 = 0;
  if (-1 < iVar1) {
    if ((local_28._5_1_ == 0x10) || ((local_28._5_1_ != 0x15 && (local_28._5_1_ != 0x20)))) {
      iVar1 = -0x3fffff45;
    }
    else {
      param_1[0] = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      local_18._0_1_ = (byte)local_18 >> 6;
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      *param_1 = (ushort)local_28._5_1_;
      *(uint *)(param_1 + 2) = (uint)local_28._4_1_;
      if ((byte)local_18 == 0) {
        uVar2 = 1;
      }
      else if ((byte)local_18 == 1) {
        uVar2 = 4;
      }
      else if ((byte)local_18 == 2) {
        uVar2 = 0x10;
      }
      *(undefined1 *)(param_1 + 4) = uVar2;
      *(ulonglong *)(param_1 + 8) = uStack_20 & 0xfffffffffffffffe;
      *(byte *)(param_1 + 0xc) = (byte)uStack_20 & 1;
      *(byte *)((longlong)param_1 + 0x19) = local_28._6_1_ & 0xfe;
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== IpmiLibReadSmbiosRecord38 @ 14000bf44 =====

int IpmiLibReadSmbiosRecord38(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  lVar6 = 0;
  iVar5 = ExGetSystemFirmwareTable(0x52534d42,0,0,0,local_res10);
  if (iVar5 == -0x3fffffdd) {
    lVar6 = ExAllocatePool2(0x100,local_res10[0],0x494d5049);
    if (lVar6 == 0) {
      return -0x3fffffe9;
    }
    iVar5 = ExGetSystemFirmwareTable(0x52534d42,0,lVar6,local_res10[0],local_res10);
  }
  if (-1 < iVar5) {
    psVar9 = (short *)((ulonglong)local_res10[0] + lVar6);
    for (psVar8 = (short *)(lVar6 + 8); psVar8 < psVar9; psVar8 = psVar8 + 1) {
      if (psVar9 < psVar8 + 2) {
LAB_14000c053:
        iVar5 = -0x3fffffc2;
        goto LAB_14000c05f;
      }
      if ((char)*psVar8 == '\x7f') break;
      bVar1 = *(byte *)((longlong)psVar8 + 1);
      if ((char)*psVar8 == '&') {
        if ((bVar1 < 0x12) || (psVar9 < (short *)((ulonglong)bVar1 + (longlong)psVar8)))
        goto LAB_14000c053;
        uVar2 = *(undefined4 *)(psVar8 + 2);
        uVar3 = *(undefined4 *)(psVar8 + 4);
        uVar4 = *(undefined4 *)(psVar8 + 6);
        iVar5 = 0;
        *param_1 = *(undefined4 *)psVar8;
        param_1[1] = uVar2;
        param_1[2] = uVar3;
        param_1[3] = uVar4;
        *(short *)(param_1 + 4) = psVar8[8];
        goto LAB_14000c05f;
      }
      psVar8 = (short *)((longlong)psVar8 + (ulonglong)bVar1);
      if (psVar9 < psVar8) goto LAB_14000c053;
      psVar7 = psVar8 + 1;
      for (; (psVar7 < psVar9 && (*psVar8 != 0)); psVar8 = (short *)((longlong)psVar8 + 1)) {
        psVar7 = (short *)((longlong)psVar7 + 1);
      }
    }
    iVar5 = -0x3ffffddb;
  }
LAB_14000c05f:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x494d5049);
  }
  return iVar5;
}



===== IpmiLibIpmbMessagePack @ 14000c098 =====

undefined8 IpmiLibIpmbMessagePack(char param_1,char *param_2,char *param_3,ushort *param_4)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  undefined8 uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  if ((((param_2 == (char *)0x0) || (param_3 == (char *)0x0)) || (param_4 == (ushort *)0x0)) ||
     ((uVar1 = *(ushort *)(param_3 + 1) + 8, uVar1 < *(ushort *)(param_3 + 1) || (*param_4 < uVar1))
     )) {
    uVar4 = 0xc000000d;
  }
  else {
    *param_2 = '\0';
    param_2[1] = *param_3;
    param_2[2] = param_3[3];
    cVar2 = IpmiLibpGetCheckSum(param_2,3);
    param_2[3] = cVar2;
    param_2[4] = param_1;
    bVar3 = DAT_1400145a0 << 2;
    bVar5 = DAT_1400145a0 + 1;
    DAT_1400145a0 = bVar5;
    param_2[5] = bVar3 | 2;
    param_2[6] = param_3[4];
    memmove(param_2 + 7,param_3 + 5,(ulonglong)*(ushort *)(param_3 + 1));
    uVar6 = (ulonglong)*(ushort *)(param_3 + 1);
    cVar2 = IpmiLibpGetCheckSum(param_2 + 4,*(ushort *)(param_3 + 1) + 3);
    param_2[uVar6 + 7] = cVar2;
    *param_4 = uVar1;
    if (0x3f < bVar5) {
      DAT_1400145a0 = 1;
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== IpmiLibIpmbMessageUnpack @ 14000c1a0 =====

undefined8 IpmiLibIpmbMessageUnpack(longlong param_1,ushort *param_2,ushort param_3)

{
  undefined8 uVar1;
  ushort uVar2;
  
  if (((param_1 == 0) || (param_2 == (ushort *)0x0)) || (param_3 < 8)) {
    uVar1 = 0xc000000d;
  }
  else if ((int)(uint)*param_2 < (int)(param_3 - 8)) {
    uVar1 = 0xc0000017;
  }
  else {
    uVar2 = param_3 - 8;
    *param_2 = uVar2;
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 6);
    if (uVar2 != 0) {
      memmove((void *)((longlong)param_2 + 3),(void *)(param_1 + 7),(ulonglong)uVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== IpmiLibpGetCheckSum @ 14000c210 =====

char IpmiLibpGetCheckSum(char *param_1,uint param_2)

{
  char cVar1;
  ulonglong uVar2;
  
  cVar1 = '\0';
  if (param_2 != 0) {
    uVar2 = (ulonglong)param_2;
    do {
      cVar1 = cVar1 + *param_1;
      param_1 = param_1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return -cVar1;
}



===== IpmiLibpDelay @ 14000c230 =====

void IpmiLibpDelay(longlong param_1,uint param_2)

{
  longlong local_res8 [4];
  
  if (((*(uint *)(param_1 + 0x20) & 4) == 0) && (0x31 < param_2)) {
    local_res8[0] = (longlong)(int)(param_2 * -10);
    KeDelayExecutionThread(0,0,local_res8);
  }
  else {
    KeStallExecutionProcessor(param_2);
  }
  return;
}



===== IpmiLibpKcsHandleError @ 14000c27c =====

ulonglong IpmiLibpKcsHandleError(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  ulonglong uVar4;
  char local_res8 [8];
  undefined1 local_res18 [8];
  
  local_res18[0] = 0;
  local_res8[0] = '\0';
  bVar3 = 0;
  do {
    if (10 < bVar3) {
      uVar4 = 0;
LAB_14000c3c7:
      return uVar4 & 0xffffffff;
    }
    uVar2 = IpmiLibpKcsSpinRegister(param_1,param_2,2);
    if ((int)uVar2 != 0) {
LAB_14000c3af:
      uVar4 = 0x102;
LAB_14000c3b5:
      IpmiLibWriteOneByte(param_1,1,0x60);
      goto LAB_14000c3c7;
    }
    *(undefined4 *)(param_1 + 0x54) = 4;
    IpmiLibWriteOneByte(param_1,1,0x60);
    uVar1 = IpmiLibpHandleErrorInterrupt(param_1,param_2,local_res8,local_res18);
    uVar4 = 0;
    if (uVar1 != 0xc0000002) {
      uVar4 = (ulonglong)uVar1;
    }
    if ((int)uVar4 != 0) goto LAB_14000c3b5;
    *(undefined4 *)(param_1 + 0x54) = 5;
    IpmiLibWriteOneByte(param_1,0,0);
    uVar1 = IpmiLibpHandleErrorInterrupt(param_1,param_2,local_res8,local_res18);
    uVar4 = 0;
    if (uVar1 != 0xc0000002) {
      uVar4 = (ulonglong)uVar1;
    }
    if ((int)uVar4 != 0) goto LAB_14000c3b5;
    if (local_res8[0] == '\x01') goto LAB_14000c3af;
    if (local_res8[0] != -1) {
      if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
        IpmiLibReadOneByte(param_1,0);
      }
      IpmiLibWriteOneByte(param_1,0,0x68);
      *(undefined4 *)(param_1 + 0x54) = 6;
      uVar1 = IpmiLibpHandleErrorInterrupt(param_1,param_2,local_res8,local_res18);
      uVar4 = 0;
      if (uVar1 != 0xc0000002) {
        uVar4 = (ulonglong)uVar1;
      }
      if ((int)uVar4 != 0) goto LAB_14000c3b5;
      if (local_res8[0] == '\x01') goto LAB_14000c3af;
      if (local_res8[0] != -1) goto LAB_14000c3c7;
    }
    bVar3 = bVar3 + 1;
  } while( true );
}



===== IpmiLibpKcsMessageTransfer @ 14000c3e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IpmiLibpKcsMessageTransfer
                    (void *param_1,void *param_2,ushort param_3,char *param_4,void *param_5,
                    ushort *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ushort *_Dst;
  void *pvVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined1 auStack_2f8 [32];
  ushort local_2d8 [2];
  undefined4 local_2d4;
  undefined2 local_2d0;
  undefined1 local_2ce;
  ushort *local_2c8;
  void *local_2c0;
  char *local_2b8;
  ushort local_2a8 [2];
  undefined2 local_2a3;
  undefined1 local_2a1 [290];
  char local_17f;
  byte local_17e;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_2f8;
  _Dst = local_2a8;
  local_2c0 = param_5;
  local_2c8 = param_6;
  bVar1 = true;
  local_2b8 = param_4;
  memset(_Dst,0,0x24a);
  lVar3 = IpmiLibpGetTimeout(_Dst,(ulonglong)
                                  (uint)(*(int *)((longlong)param_1 + 0x40) +
                                        *(int *)((longlong)param_1 + 0x50)));
  if (((param_2 == (void *)0x0) || (param_3 < 8)) ||
     (local_2a8[0] = param_3 + 2, 0x120 < (ushort)(param_3 + 2))) {
    uVar9 = 0xc000003e;
  }
  else {
    local_2a3 = 0x3418;
    memmove(local_2a1,param_2,(ulonglong)param_3);
    local_2a8[1] = 0x122;
    local_2d4 = *(undefined4 *)((longlong)param_2 + 1);
    local_2d0 = *(undefined2 *)((longlong)param_2 + 5);
    local_2ce = *(undefined1 *)((longlong)param_2 + 7);
    pvVar7 = param_1;
    uVar4 = IpmiLibpKcsBmcTransact((longlong)param_1,local_2a8,lVar3);
    uVar9 = uVar4 & 0xffffffff;
    if ((int)uVar4 == 0) {
      if (local_17f == (char)uVar4) {
        while (uVar2 = IpmiLibpTimeAfter(pvVar7,lVar3), (char)uVar2 == '\0') {
          lVar5 = IpmiLibpGetTimeout(pvVar7,(ulonglong)*(uint *)((longlong)param_1 + 0x50));
          lVar6 = IpmiLibpGetTimeout(pvVar7,(ulonglong)*(uint *)((longlong)param_1 + 0x44));
          if ((bVar1) && ((*(uint *)((longlong)param_1 + 0x20) & 1) == 0)) {
            local_2d8[0] = local_2d8[0] & 0xff00;
            bVar8 = 0;
            do {
              uVar2 = IpmiLibpTimeAfter(pvVar7,lVar5);
              if (((char)uVar2 != '\0') ||
                 (uVar2 = IpmiLibpTimeAfter(pvVar7,lVar6), (char)uVar2 != '\0')) break;
              IpmiLibpDelay((longlong)param_1,*(uint *)((longlong)param_1 + 0x48));
              pvVar7 = param_1;
              IpmiLibpKcsSmsAtn((longlong)param_1,(undefined1 *)local_2d8);
              bVar8 = (byte)local_2d8[0];
            } while ((local_2d8[0] & 4) == 0);
            param_6 = local_2c8;
            if (((*(uint *)((longlong)param_1 + 0x20) & 2) == 0) && ((bVar8 & 4) == 0)) {
              return 0x102;
            }
          }
          local_2a8[0] = 2;
          local_2a8[1] = 4;
          local_2a3 = CONCAT11(0x31,(undefined1)local_2a3);
          local_17e = 0;
          pvVar7 = param_1;
          uVar4 = IpmiLibpKcsBmcTransact((longlong)param_1,local_2a8,lVar3);
          uVar9 = uVar4 & 0xffffffff;
          if ((int)uVar4 != 0) {
            return uVar9;
          }
          if (local_17f != (char)uVar4) goto LAB_14000c639;
          if ((local_17e & 1) == 0) {
            bVar1 = true;
          }
          else {
            local_2a3 = CONCAT11(0x33,(undefined1)local_2a3);
            local_2a8[1] = 0x122;
            uVar4 = IpmiLibpKcsBmcTransact((longlong)param_1,local_2a8,lVar3);
            uVar9 = uVar4 & 0xffffffff;
            if ((int)uVar4 != 0) {
              return uVar9;
            }
            if (local_17f != (char)uVar4) goto LAB_14000c639;
            local_2d8[0] = *param_6;
            pvVar7 = local_2c0;
            uVar4 = IpmiLibpKcsIpmiToIpmbUnpack
                              (local_2c0,local_2d8,(longlong)local_2a8,(char *)&local_2d4);
            uVar9 = uVar4 & 0xffffffff;
            if (local_2d8[0] < *param_6) {
              return 0xc0000023;
            }
            *param_6 = local_2d8[0];
            if ((int)uVar4 != -0x3ffffdd3) break;
            bVar1 = false;
          }
        }
        if ((int)uVar9 != 0) {
          return uVar9;
        }
      }
LAB_14000c639:
      *local_2b8 = local_17f;
    }
  }
  return uVar9;
}



===== IpmiLibpKcsSmsAtn @ 14000c678 =====

undefined8 IpmiLibpKcsSmsAtn(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = IpmiLibReadOneByte(param_1,1);
  *param_2 = uVar1;
  return 0;
}



===== IpmiLibpTimeAfter @ 14000c698 =====

int IpmiLibpTimeAfter(undefined8 param_1,undefined8 param_2)

{
  uint3 uVar3;
  int iVar1;
  undefined8 uVar2;
  int iStackX_14;
  
  uVar2 = KeQueryPerformanceCounter(0);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
  uVar3 = (uint3)((ulonglong)uVar2 >> 8);
  if (((iVar1 == iStackX_14) && ((uint)param_2 <= (uint)uVar2)) || (iStackX_14 < iVar1)) {
    iVar1 = CONCAT31(uVar3,1);
  }
  else {
    iVar1 = (uint)uVar3 << 8;
  }
  return iVar1;
}



===== IpmiLibpKcsIpmiToIpmbUnpack @ 14000c6e0 =====

undefined8 IpmiLibpKcsIpmiToIpmbUnpack(void *param_1,ushort *param_2,longlong param_3,char *param_4)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  
  if ((((param_3 != 0) && (param_1 != (void *)0x0)) && (param_4 != (char *)0x0)) &&
     (param_2 != (ushort *)0x0)) {
    uVar2 = *(ushort *)(param_3 + 2);
    uVar1 = uVar2 - 3;
    if ((2 < uVar2) && (7 < uVar1)) {
      if (*param_2 < uVar1) {
        return 0xc0000017;
      }
      if ((void *)(param_3 + 0x12a) != (void *)0x0) {
        if (((*(char *)(param_3 + 0x12d) != *param_4) || (*(char *)(param_3 + 0x12f) != param_4[5]))
           || (((*(byte *)(param_3 + 299) & 0xfc) != (param_4[1] & 0xfcU | 4) ||
               (bVar3 = true, ((*(byte *)(param_3 + 0x12e) ^ param_4[4]) & 0xfc) != 0)))) {
          bVar3 = false;
        }
        if (bVar3) {
          *param_2 = 0;
          if (3 < uVar2) {
            *param_2 = uVar1;
            memmove(param_1,(void *)(param_3 + 0x12a),(ulonglong)uVar1);
          }
          return 0;
        }
      }
      return 0xc000022d;
    }
  }
  return 0xc000003e;
}



===== IpmiLibpHandleErrorInterrupt @ 14000c7d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IpmiLibpHandleErrorInterrupt
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
    iVar2 = -0x3ffffffe;
  }
  else if (*(code **)(param_1 + 0x30) == (code *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x30))
                      (*(undefined8 *)(param_1 + 0x38),param_1,param_2,param_3,param_4,0);
    iVar2 = -0x3ffffff3;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== _guard_check_icall @ 14000c840 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000c858 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000c87c =====

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



===== __cpu_features_init @ 14000c8f0 =====

/* WARNING: Removing unreachable block (ram,0x00014000c95a) */
/* WARNING: Removing unreachable block (ram,0x00014000c909) */
/* WARNING: Removing unreachable block (ram,0x00014000c8fa) */

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



===== __security_check_cookie @ 14000c9c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000ca00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000ca30 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ca30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000ca60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000cac0 =====

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



===== memset @ 14000cdc0 =====

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



===== __memset_repmovs @ 14000cf00 =====

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



===== __memset_query @ 14000cf80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000d000 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000d140 =====

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



===== __memset_spec_plain @ 14000d1c0 =====

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



===== AddDevice @ 14002e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AddDevice(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined8 *_Dst;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined *puVar7;
  byte *pbVar8;
  uint unaff_EDI;
  undefined8 uVar9;
  undefined8 uVar10;
  uint *puVar11;
  undefined4 *puVar12;
  undefined1 auStackY_e8 [32];
  uint local_98;
  uint local_94;
  byte *local_90;
  byte local_88 [16];
  undefined8 local_78 [4];
  uint *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_90 = (byte *)0x0;
  if ((5 < DAT_140014088) &&
     (uVar6 = param_1, uVar4 = _tlgKeywordOn(param_1,1), (char)uVar4 != '\0')) {
    local_58 = &local_94;
    local_94 = 0;
    local_50 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140010abd,param_3,param_4,3,local_78);
  }
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  uVar10 = 0x22;
  uVar9 = 0;
  uVar6 = param_1;
  uVar2 = (*PfnIoCreateDeviceSecure)(param_1,600);
  if ((int)uVar2 < 0) {
    if (DAT_140014088 < 6) {
      return unaff_EDI;
    }
    uVar4 = _tlgKeywordOn(uVar6,1);
    if ((char)uVar4 == '\0') {
      return unaff_EDI;
    }
    local_58 = &local_94;
    local_50 = 4;
    local_94 = uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140010e15,uVar9,uVar10,3,local_78);
    return unaff_EDI;
  }
  _Dst = *(undefined8 **)(local_90 + 0x40);
  KeInitializeDpc(local_90 + 200);
  KeInitializeEvent(&DAT_14002aa00,0,0);
  memset(_Dst,0,600);
  puVar1 = (uint *)(_Dst + 0x25);
  _Dst[1] = local_90;
  _Dst[3] = param_2;
  *_Dst = param_1;
  *(undefined4 *)(_Dst + 6) = 0;
  *(undefined2 *)(_Dst + 0x24) = 0;
  *(undefined4 *)((longlong)_Dst + 0x124) = 0;
  *(undefined4 *)(_Dst + 9) = 0;
  _Dst[7] = 0;
  _Dst[8] = 0;
  RtlInitUnicodeString(puVar1,0);
  *(undefined4 *)((longlong)_Dst + 0x1fc) = 0;
  *(undefined1 *)(_Dst + 0x3f) = 0;
  *(undefined2 *)(_Dst + 0x49) = 0;
  *(undefined4 *)(_Dst + 0xb) = 2;
  _Dst[0x11] = _Dst;
  KeInitializeEvent(_Dst + 0xe,0);
  KeInitializeSpinLock(_Dst + 0x4a);
  _Dst[7] = 0;
  puVar7 = (undefined *)0x0;
  _Dst[8] = 0;
  puVar11 = puVar1;
  uVar2 = IoRegisterDeviceInterface(param_2,&GUID_DEVICE);
  if (-1 < (int)uVar2) {
    puVar11 = (uint *)0x0;
    puVar7 = (undefined *)0x0;
    IoInitializeRemoveLockEx(_Dst + 0x12,0x494d5049);
    *(undefined4 *)((longlong)_Dst + 0xd4) = 2;
    *(undefined4 *)(_Dst + 0x1a) = 2;
    lVar5 = IoAttachDeviceToDeviceStack(local_90,param_2);
    _Dst[2] = lVar5;
    if (lVar5 != 0) {
      InitializeStopLock((undefined1 *)(_Dst + 0x16));
      *(uint *)(local_90 + 0x30) = *(uint *)(local_90 + 0x30) | 0x2000;
      *(uint *)(local_90 + 0x30) = *(uint *)(local_90 + 0x30) | 4;
      *(undefined4 *)((longlong)_Dst + 0xdc) = 1;
      *(undefined4 *)(_Dst + 0x1b) = 1;
      PoSetPowerState(local_90,1,1);
      *(uint *)(_Dst + 0x2c) = *(uint *)(_Dst + 0x2c) & 0xfffffffd;
      puVar11 = (uint *)(_Dst + 0x40);
      local_94 = 0;
      local_98 = 4;
      *puVar11 = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      local_88[2] = 0;
      local_88[3] = 0;
      local_88[4] = 0;
      local_88[5] = 0;
      local_88[6] = 0;
      local_88[7] = 0;
      local_88[8] = 0;
      local_88[9] = 0;
      local_88[10] = 0;
      local_88[0xb] = 0;
      local_88[0xc] = 0;
      local_88[0xd] = 0;
      local_88[0xe] = 0;
      local_88[0xf] = 0;
      *(undefined2 *)(_Dst + 0x41) = 0;
      *(undefined2 *)((longlong)_Dst + 0x1f1) = 0xff;
      *(undefined1 *)(_Dst + 0x3c) = 0;
      *(undefined1 *)((longlong)_Dst + 499) = 1;
      RtlInitUnicodeString(local_88,L"SlaveAddressDetectionMethod");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if (local_98 == 4) {
          *puVar11 = local_94;
        }
        else {
          LogEvent(0x800503ea,local_90,4,puVar11);
          *puVar11 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,0);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"IpmbMessageDetectionMode");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if (local_98 == 4) {
          *(uint *)(_Dst + 0x2c) = (local_94 & 1) * 2 | *(uint *)(_Dst + 0x2c) & 0xfffffffd;
        }
        else {
          *(uint *)(_Dst + 0x2c) = *(uint *)(_Dst + 0x2c) & 0xfffffffd;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,0);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"CommandWaitTimeoutPeriod");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_94 == 0) || (local_98 != 4)) {
          LogEvent(0x800503ea,local_90,4,_Dst + 0x30);
          *(undefined4 *)(_Dst + 0x30) = 2000000;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,2000000);
          }
        }
        else {
          *(uint *)(_Dst + 0x30) = local_94;
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"IpmbWaitTimeoutPeriod");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_94 == 0) || (local_98 != 4)) {
          LogEvent(0x800503ea,local_90,4,_Dst + 0x32);
          *(undefined4 *)(_Dst + 0x32) = 5000000;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,5000000);
          }
        }
        else {
          *(uint *)(_Dst + 0x32) = local_94;
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"BusyWaitPeriod");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_98 == 4) && (local_94 - 1 < 0x32)) {
          *(uint *)(_Dst + 0x31) = local_94;
        }
        else {
          LogEvent(0x800503ea,local_90,4,_Dst + 0x31);
          *(undefined4 *)(_Dst + 0x31) = 0x1e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,0x1e);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"BusyWaitTimeout");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_98 == 4) && (*(uint *)(_Dst + 0x31) <= local_94)) {
          *(uint *)((longlong)_Dst + 0x184) = local_94;
        }
        else {
          LogEvent(0x800503ea,local_90,4,(undefined4 *)((longlong)_Dst + 0x184));
          *(undefined4 *)((longlong)_Dst + 0x184) = 5000000;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,5000000);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"SsifRetryCount");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_98 == 4) && (SsifRetryCount <= local_94)) {
          SsifRetryCount = local_94;
        }
        else {
          puVar12 = &SsifRetryCount;
          uVar9 = 4;
          uVar6 = 0x800503ea;
          LogEvent(0x800503ea,local_90,4,&SsifRetryCount);
          SsifRetryCount = 0x32;
          if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(uVar6,1), (char)uVar4 != '\0')) {
            local_58 = &local_98;
            local_50 = 4;
            local_98 = uVar2;
            _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_140010526,uVar9,puVar12,3,local_78);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"SsifRetryDelay");
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)local_88,(undefined8 *)0x4,&local_94,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if ((local_98 == 4) && (SsifRetryDelay <= local_94)) {
          SsifRetryDelay = local_94;
        }
        else {
          LogEvent(0x800503ea,local_90,4,&SsifRetryDelay);
          SsifRetryDelay = 30000;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                     &WPP_b33591bc80fe38cf8c85745eb2752e34_Traceguids,30000);
          }
        }
      }
      local_98 = 4;
      RtlInitUnicodeString(local_88,L"DisableSELShutdownComment");
      puVar11 = &local_94;
      uVar6 = 4;
      pbVar8 = local_88;
      puVar7 = &CONFIG_KEY;
      iVar3 = QueryConfigFromRegistry
                        ((longlong *)&CONFIG_KEY,(longlong)pbVar8,(undefined8 *)0x4,puVar11,
                         &local_98,'\0');
      if (iVar3 == 0) {
        if (local_98 == 4) {
          *(bool *)(_Dst + 0x41) = local_94 != 0;
        }
        else {
          puVar11 = (uint *)((longlong)_Dst + 0x184);
          uVar6 = 4;
          puVar7 = (undefined *)0x800503ea;
          pbVar8 = local_90;
          LogEvent(0x800503ea,local_90,4,puVar11);
          *(undefined1 *)(_Dst + 0x41) = 0;
        }
      }
      if (*(char *)(_Dst + 0x41) == '\0') {
        if (5 < DAT_140014088) {
          pbVar8 = (byte *)0x1;
          uVar4 = _tlgKeywordOn(puVar7,1);
          if ((char)uVar4 != '\0') {
            pbVar8 = &DAT_1400105fc;
            goto LAB_14002e9dc;
          }
        }
      }
      else if (5 < DAT_140014088) {
        pbVar8 = (byte *)0x1;
        uVar4 = _tlgKeywordOn(puVar7,1);
        if ((char)uVar4 != '\0') {
          pbVar8 = &DAT_140010c81;
LAB_14002e9dc:
          local_58 = &local_94;
          local_50 = 4;
          local_94 = uVar2;
          _tlgWriteTransfer_EtwWriteTransfer(puVar7,pbVar8,uVar6,puVar11,3,local_78);
        }
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        puVar11 = (uint *)(ulonglong)*(uint *)(_Dst + 0x31);
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pbVar8,uVar6,*(uint *)(_Dst + 0x31),
                  (char)*(undefined4 *)((longlong)_Dst + 0x184));
      }
      puVar7 = &DAT_14002a9e0;
      pbVar8 = (byte *)&DAT_14002a9e8;
      ExInterlockedInsertTailList(&DAT_14002a9e8,_Dst + 4);
      *(uint *)(local_90 + 0x30) = *(uint *)(local_90 + 0x30) & 0xffffff7f;
      goto LAB_14002e2dd;
    }
    uVar2 = 0xc00002b6;
  }
  if (_Dst[0x26] != 0) {
    RtlFreeUnicodeString(puVar1);
  }
  if (_Dst[2] != 0) {
    IoDetachDevice();
  }
  pbVar8 = local_90;
  IoDeleteDevice();
LAB_14002e2dd:
  if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(pbVar8,1), (char)uVar4 != '\0')) {
    local_58 = &local_94;
    local_50 = 4;
    local_94 = uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(pbVar8,&DAT_140010ecb,puVar7,puVar11,3,local_78);
  }
  return unaff_EDI;
}



===== AssembleShutdownBody @ 14002ea64 =====

void AssembleShutdownBody(undefined8 *param_1,undefined1 param_2,void *param_3,byte param_4)

{
  uint uVar1;
  
  uVar1 = (uint)param_4;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0xdd;
  *(undefined2 *)((longlong)param_1 + 7) = 0x137;
  *(undefined1 *)((longlong)param_1 + 10) = param_2;
  if (4 < param_4) {
    uVar1 = 4;
  }
  memmove((void *)((longlong)param_1 + 0xb),param_3,(ulonglong)uVar1);
  return;
}



===== AssembleShutdownHead @ 14002eaa8 =====

void AssembleShutdownHead(undefined4 *param_1)

{
  *param_1 = 0x200441;
  param_1[1] = 0xffff036f;
  return;
}



===== CheckMSRDump @ 14002eac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CheckMSRDump(void *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  void *pvVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  undefined1 auStackY_b8 [32];
  int local_88;
  uint local_84;
  uint local_80 [2];
  uint *local_78;
  void *local_70;
  undefined8 local_68 [4];
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_84 = 0;
  local_80[0] = 0;
  puVar8 = (uint *)(ulonglong)DAT_140014088;
  pvVar4 = param_1;
  if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,1), (char)uVar3 != '\0')) {
    local_88 = 0;
    local_48 = &local_88;
    local_3c = 0;
    local_40 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(pvVar4,&DAT_1400109d2,puVar8,param_4,3,local_68);
    puVar8 = (uint *)(ulonglong)DAT_140014088;
  }
  if (IpmiPolicyMsrDumpEnabled == '\0') {
    if ((uint)puVar8 < 6) {
      return;
    }
    uVar3 = _tlgKeywordOn(pvVar4,1);
    if ((char)uVar3 == '\0') {
      return;
    }
    local_88 = 0;
    pbVar5 = &DAT_1400106b4;
  }
  else {
    bVar6 = 0;
    do {
      puVar8 = &local_84;
      pvVar4 = param_1;
      iVar2 = SendMsrDumpLengthRequest((ulonglong)param_1,bVar6,puVar8,param_4);
      if ((-1 < iVar2) && (local_84 != 0)) {
        param_4 = 0;
        puVar8 = local_80;
        pvVar4 = param_1;
        iVar2 = SendMsrDumpReadRequest(param_1,bVar6,puVar8,0,4);
        uVar1 = local_80[0];
        uVar7 = local_84;
        if ((-1 < iVar2) && (IpmiPolicyDumpTimeStamp < local_80[0])) {
          pvVar4 = (void *)0x102;
          puVar8 = (uint *)0x494d5049;
          local_70 = (void *)ExAllocatePool2(0x102,local_84 + 0x112);
          if (local_70 == (void *)0x0) break;
          local_78 = (uint *)((longlong)local_70 + 0x112);
          uVar3 = 0;
          if (uVar7 == 0) {
LAB_14002ec64:
            puVar8 = local_78;
            BmcWheaReportError(bVar6,local_84,local_78);
            IpmiPolicyDumpTimeStamp = uVar1;
            CommitMsrDumpTime();
            if (IpmiPolicyClearDump != '\0') {
              SendMsrDumpClearRequest((longlong)param_1,bVar6,puVar8,param_4);
            }
          }
          else {
            do {
              param_4 = uVar3;
              puVar8 = (uint *)(param_4 + (longlong)local_78);
              iVar9 = (int)param_4;
              if (uVar7 < 0x101) {
                iVar2 = SendMsrDumpReadRequest(param_1,bVar6,puVar8,param_4,uVar7);
                if (-1 < iVar2) goto LAB_14002ec64;
                break;
              }
              iVar2 = SendMsrDumpReadRequest(param_1,bVar6,puVar8,param_4,0x100);
              if (iVar2 < 0) goto LAB_14002ec91;
              uVar7 = uVar7 - 0x100;
              uVar3 = (ulonglong)(iVar9 + 0x100);
            } while (uVar7 != 0);
            if (uVar7 == 0) goto LAB_14002ec64;
          }
LAB_14002ec91:
          pvVar4 = local_70;
          ExFreePoolWithTag(local_70,0x494d5049);
        }
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    if (DAT_140014088 < 6) {
      return;
    }
    uVar3 = _tlgKeywordOn(pvVar4,1);
    if ((char)uVar3 == '\0') {
      return;
    }
    pbVar5 = &DAT_140010d46;
    local_88 = iVar2;
  }
  local_3c = 0;
  local_48 = &local_88;
  local_40 = 4;
  _tlgWriteTransfer_EtwWriteTransfer(pvVar4,pbVar5,puVar8,param_4,3,local_68);
  return;
}



===== DispatchShutdown @ 14002ed30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
DispatchShutdown(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined1 auStackY_98 [32];
  int local_68 [2];
  undefined8 local_60 [4];
  int *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  plVar2 = *(longlong **)(param_1 + 0x40);
  if (5 < DAT_140014088) {
    uVar4 = _tlgKeywordOn(param_1,1);
    if ((char)uVar4 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400108fd,param_3,param_4,2,local_60);
    }
  }
  plVar1 = plVar2 + 0x16;
  plVar6 = plVar1;
  uVar5 = AcquireStopLock((char *)plVar1);
  iVar3 = (int)uVar5;
  if (iVar3 < 0) {
    if (2 < DAT_140014088) {
      uVar4 = _tlgKeywordOn(plVar6,1);
      if ((char)uVar4 != '\0') {
        local_34 = 0;
        local_40 = local_68;
        local_38 = 4;
        local_68[0] = iVar3;
        _tlgWriteTransfer_EtwWriteTransfer(plVar6,&DAT_140010411,param_3,param_4,3,local_60);
      }
    }
  }
  else {
    WriteShutdown2SEL(plVar2);
    ReleaseStopLock((longlong)plVar1);
  }
  IofCompleteRequest(param_2,0);
  if (5 < DAT_140014088) {
    uVar4 = _tlgKeywordOn(param_2,1);
    if ((char)uVar4 != '\0') {
      local_34 = 0;
      local_40 = local_68;
      local_38 = 4;
      local_68[0] = iVar3;
      _tlgWriteTransfer_EtwWriteTransfer(param_2,&DAT_140010bb7,param_3,param_4,3,local_60);
    }
  }
  return 0;
}



===== DriverEntry @ 14002ee84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  ushort *puVar7;
  undefined8 uVar8;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50 [4];
  int *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  wil_InitializeFeatureStaging();
  uVar2 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  uVar5 = (ulonglong)uVar2;
  if ((DAT_140014088 != 0) && (uVar4 = _tlgKeywordOn(uVar5,1), (char)uVar4 != '\0')) {
    local_30 = local_58;
    local_58[0] = (int)uVar5;
    local_28 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar5,&DAT_140010cef,param_3,param_4,3,local_50);
  }
  uVar1 = *param_2;
  RtlInitUnicodeString(&servkey,0);
  uVar8 = 0x494d5049;
  DAT_14002a8c8 = ExAllocatePool2(0x42,uVar1 + 2);
  pcVar6 = DAT_1400140a8;
  if (DAT_14002a8c8 == 0) {
    DAT_1400140a8 = (code *)0x0;
    DAT_140014088 = 0;
    EtwUnregister(pcVar6);
    wil_UninitializeFeatureStaging();
    iVar3 = -0x3fffff66;
  }
  else {
    puVar7 = param_2;
    _DAT_14002a8c2 = uVar1 + 2;
    RtlCopyUnicodeString(&servkey);
    *(undefined2 *)(DAT_14002a8c8 + (ulonglong)(*param_2 >> 1) * 2) = 0;
    pcVar6 = AddDevice;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = AddDevice;
    *(code **)(param_1 + 0x68) = DriverUnload;
    *(code **)(param_1 + 0x70) = DispatchCreate;
    *(code **)(param_1 + 0x80) = DispatchClose;
    *(code **)(param_1 + 0xe0) = DispatchControl;
    *(code **)(param_1 + 0x120) = DispatchPower;
    *(code **)(param_1 + 0x128) = DispatchWmi;
    *(code **)(param_1 + 0x148) = DispatchPnp;
    *(code **)(param_1 + 0xf0) = DispatchShutdown;
    *(code **)(param_1 + 0xe8) = DispatchInternalControl;
    iVar3 = InitializeWorkQueue(AddDevice,puVar7,uVar8,param_4);
    if (iVar3 == 0) {
      BmcWheaInit();
    }
    else {
      RtlFreeUnicodeString(&servkey);
      pcVar6 = DAT_1400140a8;
      DAT_1400140a8 = (code *)0x0;
      DAT_140014088 = 0;
      EtwUnregister();
      wil_UninitializeFeatureStaging();
    }
    _WPP_MAIN_CB = 0;
    DAT_14002a888 = &WPP_ThisDir_CTLGUID_IPMIDRIVER;
    DAT_14002a890 = 0;
    _DAT_14002a8a0 = 0;
    _DAT_14002a8a8 = 1;
    WppLoadTracingSupport();
    _DAT_14002a8a0 = 0;
    WppInitKm();
    if ((DAT_140014088 != 0) && (uVar5 = _tlgKeywordOn(pcVar6,1), (char)uVar5 != '\0')) {
      local_30 = local_58;
      local_28 = 4;
      local_58[0] = iVar3;
      _tlgWriteTransfer_EtwWriteTransfer(pcVar6,&DAT_140010f6b,uVar8,param_4,3,local_50);
    }
  }
  return iVar3;
}



===== DriverUnload @ 14002f130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverUnload(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (5 < DAT_140014088) {
    param_2 = (undefined *)0x1;
    uVar1 = _tlgKeywordOn(param_1,1);
    if ((char)uVar1 != '\0') {
      param_2 = &DAT_140010f95;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010f95,param_3,param_4,2,local_38);
    }
  }
  uVar2 = DAT_1400140a8;
  DAT_1400140a8 = 0;
  DAT_140014088 = 0;
  EtwUnregister();
  SelCacheClose(uVar2,param_2,param_3,param_4);
  UnInitializeWorkQueue(uVar2,param_2,param_3,param_4);
  puVar3 = &servkey;
  RtlFreeUnicodeString();
  if ((5 < DAT_140014088) && (uVar1 = _tlgKeywordOn(puVar3,1), (char)uVar1 != '\0')) {
    _tlgWriteTransfer_EtwWriteTransfer(puVar3,&DAT_140010ff0,param_3,param_4,2,local_38);
  }
  uVar2 = DAT_1400140a8;
  DAT_1400140a8 = 0;
  DAT_140014088 = 0;
  EtwUnregister(uVar2);
  BmcWheaUninit();
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar3 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar3 != (undefined *)0x0; puVar3 = *(undefined **)(puVar3 + 0x10)) {
        if (*(longlong *)(puVar3 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar3 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  wil_UninitializeFeatureStaging();
  return;
}



===== ForwardAndWait @ 14002f2a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ForwardAndWait(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48 [4];
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (5 < DAT_140014088) {
    lVar2 = param_1;
    uVar1 = _tlgKeywordOn(param_1,1);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_1400108d8,param_3,param_4,2,local_48);
    }
  }
  KeInitializeEvent(&local_60,0);
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  puVar3[-9] = *puVar3;
  puVar3[-8] = puVar3[1];
  puVar3[-7] = puVar3[2];
  puVar3[-6] = puVar3[3];
  *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
  *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
  *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
  *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
  puVar3[-3] = puVar3[6];
  *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = OnRequestComplete;
  *(undefined8 **)(lVar2 + -8) = &local_60;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10), lVar2 != 0)) {
    IofCallDriver(lVar2,param_2);
  }
  puVar3 = &local_60;
  uVar5 = 0;
  uVar4 = 0;
  KeWaitForSingleObject(puVar3,0);
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(puVar3,1);
    if ((char)uVar1 != '\0') {
      local_68[0] = *(uint *)(param_2 + 0x30);
      local_28 = local_68;
      local_1c = 0;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_68[0],&DAT_14001071a,uVar4,uVar5,3,local_48);
    }
  }
  return *(undefined4 *)(param_2 + 0x30);
}



===== InitializeWorkQueue @ 14002f420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int InitializeWorkQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_98 [32];
  int local_58 [2];
  longlong local_50;
  undefined8 local_48 [4];
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 0;
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_1,2);
    if ((char)uVar2 != '\0') {
      local_58[0] = 0;
      local_28 = local_58;
      local_1c = 0;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010924,param_3,param_4,3,local_48);
    }
  }
  _DAT_14002a9d8 = 0;
  DAT_14002a918 = 1;
  _DAT_14002a9a8 = 2;
  KeInitializeEvent(&DAT_14002a9c0,0);
  _DAT_14002a9f8 = 0;
  _DAT_14002a9fc = 0;
  KeInitializeSpinLock(&EngineState);
  KeInitializeEvent(&DAT_14002a8e8,0);
  _DAT_14002a908 = &DAT_14002a900;
  DAT_14002a900 = &DAT_14002a900;
  KeInitializeSpinLock(&DAT_14002a9e0);
  _DAT_14002a9f0 = &DAT_14002a9e8;
  DAT_14002a9e8 = &DAT_14002a9e8;
  iVar1 = PsCreateSystemThread(&local_50,0);
  if ((-1 < iVar1) && (local_50 != 0)) {
    uVar5 = 0;
    uVar4 = 0;
    ObReferenceObjectByHandle(local_50,0x1fffff);
    lVar3 = local_50;
    ZwClose();
    DAT_14002a918 = 0;
    if (5 < DAT_140014088) {
      uVar2 = _tlgKeywordOn(lVar3,2);
      if ((char)uVar2 != '\0') {
        local_1c = 0;
        local_28 = local_58;
        local_20 = 4;
        local_58[0] = iVar1;
        _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140010632,uVar4,uVar5,3,local_48);
      }
    }
  }
  return iVar1;
}



===== QueryConfigFromRegistry @ 14002f630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
QueryConfigFromRegistry
          (longlong *param_1,longlong param_2,undefined8 *param_3,void *param_4,uint *param_5,
          char param_6)

{
  int iVar1;
  ulonglong uVar2;
  void *pvVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  byte *pbVar7;
  undefined8 *_Size;
  void *pvVar8;
  undefined4 uVar9;
  undefined1 auStackY_e8 [32];
  undefined4 uVar10;
  int local_b8;
  uint local_b4;
  longlong local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  longlong *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined8 local_70 [4];
  int *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = 0;
  local_b0 = 0;
  local_b4 = 0;
  iVar1 = 0;
  uVar9 = 0xffffffff;
  local_80 = 0;
  uStack_78 = uStack_78 & 0xffffffff00000000;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = (longlong *)0x0;
  uStack_88 = 0;
  plVar4 = param_1;
  _Size = param_3;
  pvVar8 = param_4;
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(plVar4,&DAT_1400106ec,_Size,pvVar8,2,local_70);
    }
  }
  if ((((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_4 == (void *)0x0)) ||
     ((param_5 == (uint *)0x0 || (*param_5 == 0)))) {
    if (DAT_140014088 < 3) goto LAB_14002f988;
    uVar2 = _tlgKeywordOn(plVar4,1);
    if ((char)uVar2 == '\0') goto LAB_14002f988;
    pbVar7 = &DAT_140010ddc;
    uVar10 = 2;
    iVar1 = 0;
  }
  else {
    uStack_98 = 0;
    _Size = &local_a0;
    local_a0 = CONCAT44(local_a0._4_4_,0x30);
    uStack_88 = CONCAT44(uStack_88._4_4_,0x640);
    plVar4 = &local_b0;
    local_80 = 0;
    uStack_78 = 0;
    local_90 = param_1;
    iVar1 = ZwOpenKey(plVar4,0x20019);
    if (iVar1 < 0) {
      if (DAT_140014088 < 3) goto LAB_14002f988;
      uVar2 = _tlgKeywordOn(plVar4,1);
      if ((char)uVar2 == '\0') goto LAB_14002f988;
      local_50 = &local_b8;
      pbVar7 = &DAT_140011012;
      uVar10 = 3;
      local_48 = 4;
      local_b8 = iVar1;
    }
    else {
      pvVar8 = (void *)0x0;
      _Size = (undefined8 *)0x2;
      iVar1 = ZwQueryValueKey(local_b0,param_2);
      plVar4 = (longlong *)0x1000;
      if (0xfff < local_b4) {
        local_b4 = 0x1000;
      }
      if (local_b4 == 0) {
        if (DAT_140014088 < 3) goto LAB_14002f988;
        uVar2 = _tlgKeywordOn(0x1000,1);
        if ((char)uVar2 == '\0') goto LAB_14002f988;
        local_50 = &local_b8;
        pbVar7 = &DAT_140011053;
        uVar10 = 3;
        local_48 = 4;
        local_b8 = iVar1;
      }
      else {
        plVar4 = (longlong *)0x42;
        _Size = (undefined8 *)0x494d5049;
        pvVar3 = (void *)ExAllocatePool2(0x42,local_b4);
        if (pvVar3 != (void *)0x0) {
          _Size = (undefined8 *)0x2;
          lVar5 = local_b0;
          pvVar8 = pvVar3;
          iVar1 = ZwQueryValueKey(local_b0,param_2);
          if (((iVar1 < 0) || (*(int *)((longlong)pvVar3 + 4) != (int)param_3)) ||
             (uVar6 = *(uint *)((longlong)pvVar3 + 8), uVar6 == 0)) {
            *param_5 = 0;
            if (1 < DAT_140014088) {
              uVar2 = _tlgKeywordOn(lVar5,1);
              if ((char)uVar2 != '\0') {
                local_50 = &local_b8;
                local_48 = 4;
                local_b8 = iVar1;
                _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140011090,_Size,pvVar8,3,local_70);
              }
            }
          }
          else {
            uVar9 = 0;
            if (*param_5 < uVar6) {
              uVar6 = *param_5;
            }
            _Size = (undefined8 *)(ulonglong)uVar6;
            memmove(param_4,(void *)((longlong)pvVar3 + 0xc),(size_t)_Size);
            uVar6 = *(uint *)((longlong)pvVar3 + 8);
            if (uVar6 < *param_5) {
              *param_5 = uVar6;
            }
            else if ((*param_5 < uVar6) && (param_6 == '\0')) {
              uVar9 = 0xffffffff;
            }
          }
          ExFreePoolWithTag(pvVar3,0x494d5049);
          goto LAB_14002f988;
        }
        iVar1 = -0x3fffff66;
        if (DAT_140014088 < 2) goto LAB_14002f988;
        uVar2 = _tlgKeywordOn(plVar4,1);
        if ((char)uVar2 == '\0') goto LAB_14002f988;
        local_50 = &local_b8;
        pbVar7 = &DAT_1400107de;
        local_b8 = -0x3fffff66;
        uVar10 = 3;
        local_48 = 4;
        iVar1 = -0x3fffff66;
      }
    }
  }
  _tlgWriteTransfer_EtwWriteTransfer(plVar4,pbVar7,_Size,pvVar8,uVar10,local_70);
LAB_14002f988:
  lVar5 = local_b0;
  if (local_b0 != 0) {
    ZwClose();
  }
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(lVar5,1);
    if ((char)uVar2 != '\0') {
      local_50 = &local_b8;
      local_48 = 4;
      local_b8 = iVar1;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_1400109fe,_Size,pvVar8,3,local_70);
    }
  }
  return uVar9;
}



===== RemoveDevice @ 14002fa18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RemoveDevice(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (5 < DAT_140014088) {
    lVar3 = param_1;
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140010ef3,param_3,param_4,2,local_40);
    }
  }
  if (*(longlong *)(lVar1 + 0x10) != 0) {
    IoDetachDevice();
  }
  IoDeleteDevice();
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_48[0] = 0;
      local_20 = local_48;
      local_14 = 0;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010957,param_3,param_4,3,local_40);
    }
  }
  return 0;
}



===== SendMsrDumpClearRequest @ 14002fb08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SendMsrDumpClearRequest(longlong param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auStackY_2d8 [32];
  undefined4 local_2a8 [4];
  undefined4 local_298;
  undefined1 local_294;
  undefined4 local_293;
  undefined1 local_28f;
  undefined1 local_28e;
  undefined2 local_28c;
  char local_28a;
  undefined8 local_48 [4];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2d8;
  if (5 < DAT_140014088) {
    lVar3 = param_1;
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_2a8[0] = 0;
      local_28 = local_2a8;
      local_1c = 0;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140010cb8,param_3,param_4,3,local_48);
    }
  }
  uVar5 = 0x248;
  memset(&local_298,0,0x248);
  local_294 = *(undefined1 *)(param_1 + 0x159);
  local_293 = 0xf5d80002;
  local_28f = 3;
  local_28a = -1;
  local_28e = param_2;
  uVar2 = IpmiComputeBufferResponseLength(2);
  local_28c = (undefined2)uVar2;
  iVar1 = ipmi_send_request(param_1,&local_298);
  if ((iVar1 != 0) || (uVar4 = 0, local_28a != '\0')) {
    uVar4 = 0xc0000001;
  }
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_1c = 0;
      local_28 = local_2a8;
      local_20 = 4;
      local_2a8[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010da6,uVar5,param_4,3,local_48);
    }
  }
  return uVar4;
}



===== SendMsrDumpLengthRequest @ 14002fc78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SendMsrDumpLengthRequest
          (ulonglong param_1,undefined1 param_2,undefined4 *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined1 auStackY_2d8 [32];
  undefined4 local_2a8 [4];
  undefined4 local_298;
  undefined1 local_294;
  undefined4 local_293;
  undefined1 local_28f;
  undefined1 local_28e;
  undefined2 local_28c;
  char local_28a;
  undefined4 local_289;
  undefined8 local_48 [4];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_2d8;
  if (5 < DAT_140014088) {
    uVar3 = param_1;
    puVar5 = param_3;
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_2a8[0] = 0;
      local_28 = local_2a8;
      local_1c = 0;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar3,&DAT_140010fb8,puVar5,param_4,3,local_48);
    }
  }
  uVar6 = 0x248;
  memset(&local_298,0,0x248);
  local_294 = *(undefined1 *)(param_1 + 0x159);
  local_293 = 0xf5d80002;
  local_28f = 4;
  local_28a = -1;
  local_28e = param_2;
  uVar3 = IpmiComputeBufferResponseLength(2);
  local_28c = (undefined2)uVar3;
  iVar1 = ipmi_send_request(param_1,&local_298);
  if ((iVar1 == 0) && (local_28a == '\0')) {
    param_1 = (ulonglong)local_289._1_1_;
    *param_3 = local_289;
    uVar4 = 0;
  }
  else {
    uVar4 = 0xc0000001;
  }
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(param_1,1);
    if ((char)uVar3 != '\0') {
      local_1c = 0;
      local_28 = local_2a8;
      local_20 = 4;
      local_2a8[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400105c5,uVar6,param_4,3,local_48);
    }
  }
  return uVar4;
}



===== SendMsrDumpReadRequest @ 14002fe1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SendMsrDumpReadRequest
          (void *param_1,undefined1 param_2,void *param_3,undefined8 param_4,uint param_5)

{
  int iVar1;
  ulonglong uVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *pvVar5;
  ulonglong _Size;
  undefined8 uVar6;
  undefined1 auStackY_2e8 [32];
  undefined4 local_2b8 [4];
  undefined4 local_2a8;
  undefined1 local_2a4;
  undefined4 local_2a3;
  undefined1 local_29f;
  undefined1 local_29e;
  undefined1 local_29d;
  undefined1 local_29c;
  undefined1 local_29b;
  undefined1 local_29a;
  undefined1 local_299;
  undefined1 local_298;
  undefined2 local_296;
  char local_294;
  undefined1 local_293 [571];
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2e8;
  uVar6 = param_4;
  if (5 < DAT_140014088) {
    pvVar3 = param_1;
    pvVar5 = param_3;
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_2b8[0] = 0;
      local_38 = local_2b8;
      local_2c = 0;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(pvVar3,&DAT_140010e95,pvVar5,uVar6,3,local_58);
    }
  }
  _Size = 0x248;
  memset(&local_2a8,0,0x248);
  local_2a4 = *(undefined1 *)((longlong)param_1 + 0x159);
  pvVar3 = (void *)0x8;
  local_29c = (undefined1)((ulonglong)param_4 >> 8);
  local_29b = (undefined1)((ulonglong)param_4 >> 0x10);
  local_29d = (undefined1)param_4;
  local_298 = (undefined1)(param_5 >> 8);
  local_2a3 = 0xf5d80008;
  local_29f = 1;
  local_29a = (undefined1)((ulonglong)param_4 >> 0x18);
  local_299 = (undefined1)param_5;
  local_294 = -1;
  local_29e = param_2;
  uVar2 = IpmiComputeBufferResponseLength(8);
  local_296 = (undefined2)uVar2;
  if (param_5 <= ((uint)uVar2 & 0xffff)) {
    iVar1 = ipmi_send_request(param_1,&local_2a8);
    pvVar3 = param_1;
    if ((iVar1 == 0) && (pvVar3 = param_1, local_294 == '\0')) {
      _Size = (ulonglong)param_5;
      memmove(param_3,local_293,_Size);
      uVar4 = 0;
      goto LAB_14002ff61;
    }
  }
  param_3 = pvVar3;
  uVar4 = 0xc0000001;
LAB_14002ff61:
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_3,1);
    if ((char)uVar2 != '\0') {
      local_2c = 0;
      local_38 = local_2b8;
      local_30 = 4;
      local_2b8[0] = uVar4;
      _tlgWriteTransfer_EtwWriteTransfer(param_3,&DAT_140010450,_Size,uVar6,3,local_58);
    }
  }
  return uVar4;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14002ffec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_140014090 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140014090 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140014090 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140014090 + -4);
  if (DAT_1400140a8 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1400140b0 = 0;
  uRam00000001400140b8 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14003004f;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140014088,&DAT_1400140a8);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140014090;
    *(undefined8 *)(puVar4 + -8) = 0x140030076;
    EtwSetInformation(DAT_1400140a8,2,PTR_DAT_140014090,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14003008a;
  return iVar3;
}



===== UnInitializeWorkQueue @ 140030098 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
UnInitializeWorkQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(param_1,2);
    if ((char)uVar1 != '\0') {
      local_48[0] = 0;
      local_20 = local_48;
      local_14 = 0;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010d71,param_3,param_4,3,local_40);
    }
  }
  if (DAT_14002a918 == '\0') {
    DAT_14002a918 = '\x01';
    ExInterlockedInsertTailList(&DAT_14002a900,&DAT_14002a9b0);
    KeSetEvent(&DAT_14002a8e8,0);
    param_4 = 0;
    param_3 = 0;
    KeWaitForSingleObject(DAT_14002a910,0);
    param_1 = DAT_14002a910;
    ObfDereferenceObject();
  }
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(param_1,2);
    if ((char)uVar1 != '\0') {
      local_48[0] = 0;
      local_20 = local_48;
      local_14 = 0;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1400107aa,param_3,param_4,3,local_40);
    }
  }
  return 0;
}



===== WppInitKm @ 1400301e0 =====

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



===== WppLoadTracingSupport @ 140030270 =====

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



===== WppTraceCallback @ 1400303c0 =====

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



===== WriteToRegistry @ 140030648 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WriteToRegistry(undefined8 param_1,longlong param_2,undefined8 *param_3,longlong param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 ***pppuVar3;
  byte *pbVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStackY_108 [32];
  undefined4 uVar7;
  undefined *local_d8;
  undefined8 ***local_d0;
  longlong local_c8;
  longlong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong uStack_90;
  undefined8 local_88 [4];
  undefined **local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d0 = (undefined8 ***)0x0;
  iVar1 = 0;
  uVar6 = 0xffffffff;
  local_98 = 0;
  uStack_90 = uStack_90 & 0xffffffff00000000;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = (undefined *)0x0;
  uStack_a0 = 0;
  lVar5 = param_4;
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 != '\0') {
      local_d8 = (undefined *)((ulonglong)local_d8 & 0xffffffff00000000);
      local_68 = &local_d8;
      local_5c = 0;
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140010f16,param_3,lVar5,3,local_88);
    }
  }
  if ((param_2 == 0) || (param_4 == 0)) {
    if (DAT_140014088 < 3) goto LAB_140030880;
    uVar2 = _tlgKeywordOn(param_1,1);
    if ((char)uVar2 == '\0') goto LAB_140030880;
    local_4c = 0;
    pbVar4 = &DAT_14001088c;
    local_3c = 0;
    pppuVar3 = (undefined8 ***)0x8;
    local_d8 = &CONFIG_KEY;
    local_58 = &local_c8;
    local_48 = &local_c0;
    uVar7 = 5;
    local_60 = 8;
    local_50 = 8;
    local_40 = 8;
    iVar1 = 0;
    local_c8 = param_2;
    local_c0 = param_4;
  }
  else {
    uStack_b0 = 0;
    local_a8 = &CONFIG_KEY;
    param_3 = &local_b8;
    local_b8 = CONCAT44(local_b8._4_4_,0x30);
    uStack_a0 = CONCAT44(uStack_a0._4_4_,0x640);
    pppuVar3 = &local_d0;
    local_98 = 0;
    uStack_90 = 0;
    iVar1 = ZwOpenKey(pppuVar3,0x20006);
    if (iVar1 < 0) {
      if (DAT_140014088 < 3) goto LAB_140030880;
      uVar2 = _tlgKeywordOn(pppuVar3,1);
      if ((char)uVar2 == '\0') goto LAB_140030880;
      pbVar4 = &DAT_1400104ee;
      local_d8 = (undefined *)CONCAT44(local_d8._4_4_,iVar1);
      uVar7 = 3;
      local_60 = 4;
    }
    else {
      lVar5 = 4;
      param_3 = (undefined8 *)0x0;
      pppuVar3 = local_d0;
      iVar1 = ZwSetValueKey(local_d0,param_2);
      if (-1 < iVar1) {
        uVar6 = 0;
        goto LAB_140030880;
      }
      if (DAT_140014088 < 3) goto LAB_140030880;
      uVar2 = _tlgKeywordOn(pppuVar3,1);
      if ((char)uVar2 == '\0') goto LAB_140030880;
      pbVar4 = &DAT_140010c15;
      local_d8 = (undefined *)CONCAT44(local_d8._4_4_,iVar1);
      uVar7 = 3;
      local_60 = 4;
    }
  }
  local_5c = 0;
  local_68 = &local_d8;
  _tlgWriteTransfer_EtwWriteTransfer(pppuVar3,pbVar4,param_3,lVar5,uVar7,local_88);
LAB_140030880:
  pppuVar3 = local_d0;
  if (local_d0 != (undefined8 ***)0x0) {
    ZwClose();
  }
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(pppuVar3,1);
    if ((char)uVar2 != '\0') {
      local_5c = 0;
      local_68 = &local_d8;
      local_d8 = (undefined *)CONCAT44(local_d8._4_4_,iVar1);
      local_60 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(pppuVar3,&DAT_140010ae6,param_3,lVar5,3,local_88);
    }
  }
  return uVar6;
}



===== _tlgEnableCallback @ 140030910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== wil_UninitializeFeatureStaging @ 14003098c =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400309e4 =====

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
      goto LAB_140030a41;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140030a41;
    }
  }
  uVar1 = 0x206;
LAB_140030a41:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140030a4c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  plVar1 = (longlong *)&wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140030b04 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140030b3c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140030bbe;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140030bbe;
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
LAB_140030bbe:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140030c10 =====

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
      plVar2 = (longlong *)&wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2), plVar2 != (longlong *)0x0)
      {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        plVar2 = plVar2 + 7;
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140030c70 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140030c8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar2 = (longlong *)&wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2);
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
    plVar2 = plVar2 + 7;
  }
  return;
}



===== BmcWheaInitErrorSource @ 140030d40 =====

undefined8 BmcWheaInitErrorSource(undefined8 param_1,longlong param_2)

{
  if (IpmipWheaRemoved == '\x01') {
    return 0xc0000001;
  }
  DAT_14001466c = *(undefined4 *)(param_2 + 0x1c);
  IpmipWheaInitialized = 1;
  return 0;
}



===== BmcWheaUninitErrorSource @ 140030d70 =====

void BmcWheaUninitErrorSource(void)

{
  memset(&IpmipBmcErrorSource,0,0x3cc);
  IpmipWheaInitialized = 0;
  return;
}



===== AcpiFindKcsResources @ 140030d9c =====

undefined4 AcpiFindKcsResources(longlong param_1,uint *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  undefined4 unaff_EBX;
  undefined4 uVar9;
  longlong lVar10;
  byte bVar11;
  uint *puVar12;
  uint uVar13;
  undefined1 uVar14;
  ulonglong uVar15;
  byte bVar16;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint *local_40;
  
  uVar9 = 0;
  local_54 = 0;
  bVar5 = false;
  bVar6 = false;
  lVar10 = 0;
  bVar2 = false;
  bVar11 = 0;
  uVar15 = 0;
  bVar16 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  bVar4 = false;
  bVar3 = false;
  local_40 = param_2 + 1;
  local_48 = 0;
  if (*param_2 != 0) {
    uVar14 = 0x10;
    do {
      puVar12 = local_40 + 4;
      uVar13 = 0x10;
      local_50 = 0x10;
      local_4c = 0;
      if (local_40[3] != 0) {
        do {
          cVar1 = (char)*puVar12;
          if (cVar1 == '\x01') {
LAB_140030ee4:
            if ((cVar1 == '\x01') || (cVar1 == '\x03')) {
              local_54 = puVar12[3];
            }
            if (bVar3) {
              if (bVar4) {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return unaff_EBX;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return unaff_EBX;
                }
                uVar8 = 0x1c;
LAB_140031123:
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                        &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
                return unaff_EBX;
              }
              bVar4 = true;
              bVar5 = true;
              if (*(char *)((longlong)puVar12 + 1) != '\x01') {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return unaff_EBX;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return unaff_EBX;
                }
                uVar8 = 0x1b;
                goto LAB_140031123;
              }
              uVar15 = *(ulonglong *)(puVar12 + 1);
              if (cVar1 == '\x01') {
                bVar16 = *(byte *)((longlong)puVar12 + 2) & 1;
              }
              else {
                bVar16 = 0;
              }
            }
            else if (local_54 == 1) {
              bVar3 = true;
              bVar6 = true;
              if (*(char *)((longlong)puVar12 + 1) != '\x01') {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return unaff_EBX;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return unaff_EBX;
                }
                uVar8 = 0x18;
                goto LAB_140031123;
              }
              lVar10 = *(longlong *)(puVar12 + 1);
              if (cVar1 == '\x01') {
                bVar11 = *(byte *)((longlong)puVar12 + 2) & 1;
              }
              else {
                bVar11 = 0;
              }
            }
            else {
              if (local_54 != 2) {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return unaff_EBX;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return unaff_EBX;
                }
                uVar8 = 0x1a;
                goto LAB_140031123;
              }
              bVar3 = true;
              bVar6 = true;
              bVar5 = true;
              if (*(char *)((longlong)puVar12 + 1) != '\x01') {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return unaff_EBX;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                  return unaff_EBX;
                }
                uVar8 = 0x19;
                goto LAB_140031123;
              }
              if (cVar1 == '\x01') {
                bVar11 = *(byte *)((longlong)puVar12 + 2) & 1;
              }
              else {
                bVar11 = 0;
              }
              lVar10 = *(longlong *)(puVar12 + 1);
              uVar15 = lVar10 + 1;
              bVar16 = bVar11;
              bVar4 = bVar3;
            }
          }
          else if (cVar1 == '\x02') {
            if (bVar2) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return unaff_EBX;
              }
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                return unaff_EBX;
              }
              uVar8 = 0x1d;
              goto LAB_140031123;
            }
            bVar2 = true;
            if (IpmiPolicyConfigureInterrupts != '\0') {
              *(undefined1 *)(param_1 + 0x98) = 1;
            }
          }
          else {
            if (cVar1 == '\x03') goto LAB_140030ee4;
            if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                        &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
                bVar3 = bVar6;
                bVar4 = bVar5;
              }
            }
          }
          uVar13 = local_50 + 0x14;
          local_4c = local_4c + 1;
          puVar12 = puVar12 + 5;
          local_50 = uVar13;
        } while (local_4c < local_40[3]);
      }
      local_48 = local_48 + 1;
      local_40 = (uint *)((longlong)local_40 + (ulonglong)uVar13);
    } while (local_48 < *param_2);
    if ((bVar4) && (bVar3)) {
      if ((bVar11 == bVar16) && (uVar7 = uVar15 - lVar10, uVar7 < uVar15)) {
        if (uVar7 == 1) {
          uVar14 = 1;
        }
        else if (uVar7 == 4) {
          uVar14 = 4;
        }
        else if (uVar7 != 0x10) goto LAB_140031038;
        *(longlong *)(param_1 + 0x18) = lVar10;
        *(undefined1 *)(param_1 + 0x10) = uVar14;
        *(byte *)(param_1 + 0x20) = bVar11;
      }
      else {
LAB_140031038:
        uVar9 = 0xc000000d;
      }
      goto LAB_140031155;
    }
  }
  uVar9 = 0xc0000225;
LAB_140031155:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,uVar9);
  }
  return unaff_EBX;
}



===== KCS_find_resources @ 1400311b0 =====

undefined4 KCS_find_resources(longlong param_1,int param_2,uint *param_3)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  
  uVar1 = 0xc000000d;
  if (param_2 == 1) {
    AcpiFindKcsResources(param_1,param_3);
    uVar1 = extraout_EAX;
  }
  return uVar1;
}



===== SSIF_find_resources @ 1400311e0 =====

undefined8 SSIF_find_resources(longlong param_1,int param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 uVar7;
  
  uVar7 = 0xc000000d;
  if (param_2 == 1) {
    bVar1 = false;
    puVar6 = param_3 + 1;
    uVar5 = 0;
    if (*param_3 != 0) {
      do {
        if (bVar1) {
          return uVar7;
        }
        uVar2 = puVar6[3];
        uVar4 = 0;
        if (uVar2 != 0) {
          do {
            if (bVar1) break;
            if ((((char)puVar6[uVar4 * 5 + 4] == -0x7c) && ((char)puVar6[uVar4 * 5 + 5] == '\x02'))
               && (*(char *)((longlong)puVar6 + uVar4 * 0x14 + 0x15) == '\x01')) {
              bVar1 = true;
              *(uint *)(param_1 + 0x78) = puVar6[uVar4 * 5 + 6];
              uVar7 = 0;
              *(uint *)(param_1 + 0x7c) = puVar6[uVar4 * 5 + 7];
            }
            uVar2 = puVar6[3];
            uVar3 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar3;
          } while (uVar3 < uVar2);
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + (ulonglong)uVar2 * 5 + 4;
      } while (uVar5 < *param_3);
    }
  }
  return uVar7;
}



===== SendIoctl @ 140031280 =====

int SendIoctl(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,int *param_6)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_28 [2];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  lVar2 = ExAllocatePool2(0x42,0x18,0x494d5049);
  if (lVar2 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    KeInitializeEvent(lVar2,0,0);
    lVar3 = IoBuildDeviceIoControlRequest(0x32c004,param_1,param_2,8,param_4,0x14,0,lVar2,param_6);
    if (lVar3 == 0) {
      iVar1 = -0x3fffffe9;
    }
    else {
      iVar1 = IofCallDriver(param_1,lVar3);
      if (-1 < iVar1) {
        local_28[0] = 0xfffffffffd050f80;
        iVar1 = KeWaitForSingleObject(lVar2,0,0,0,local_28);
        if (iVar1 == 0x102) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                    &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
          }
          iVar1 = -0x3fffff4b;
        }
        else if (-1 < iVar1) {
          iVar1 = *param_6;
        }
      }
    }
    ExFreePoolWithTag(lVar2,0x494d5049);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,iVar1);
  }
  return iVar1;
}



===== acpi_get_integer @ 140031444 =====

int acpi_get_integer(longlong param_1,char *param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffffc8;
  int local_28 [2];
  longlong lStack_20;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  lStack_20 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  uVar4 = 0x494d5049;
  lVar3 = ExAllocatePool2(0x40);
  if (lVar3 == 0) {
    iVar2 = -0x3fffffe9;
    goto LAB_14003154e;
  }
  local_res8 = CONCAT44(param_3,0x42696541);
  iVar2 = SendIoctl(*(undefined8 *)(lVar1 + 0x10),&local_res8,uVar4,lVar3,in_stack_ffffffffffffffc8,
                    local_28);
  if (-1 < iVar2) {
    if ((((lStack_20 == 0x14) && (*(int *)(lVar3 + 8) == 1)) && (0x13 < *(uint *)(lVar3 + 4))) &&
       (*(short *)(lVar3 + 0xc) == 0)) {
      if (*param_2 == '\x01') {
        param_2[2] = *(char *)(lVar3 + 0x10);
      }
      else {
        if (*param_2 != '\x02') goto LAB_140031535;
        *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar3 + 0x10);
      }
    }
    else {
LAB_140031535:
      iVar2 = -0x3ffffff3;
    }
  }
  ExFreePoolWithTag(lVar3,0x494d5049);
LAB_14003154e:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids,iVar2);
  }
  return iVar2;
}



===== DispatchClose @ 1400315a0 =====

void DispatchClose(longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_4107e96cfe8c31fa2a2b60f38ace0bb3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_4107e96cfe8c31fa2a2b60f38ace0bb3_Traceguids);
  }
  LOCK();
  piVar1 = (int *)(lVar2 + 0x30);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,param_3,param_4,
              (char)*(undefined4 *)(lVar2 + 0x30));
  }
  CompleteRequest(param_2,0);
  return;
}



===== DispatchCreate @ 140031640 =====

void DispatchCreate(longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_4107e96cfe8c31fa2a2b60f38ace0bb3_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_4107e96cfe8c31fa2a2b60f38ace0bb3_Traceguids);
  }
  LOCK();
  piVar1 = (int *)(lVar2 + 0x30);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_3,param_4,
              (char)*(undefined4 *)(lVar2 + 0x30));
  }
  CompleteRequest(param_2,0);
  return;
}



===== AdjustDeviceCapabilities @ 1400316d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AdjustDeviceCapabilities
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  int *piVar5;
  int iVar6;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14001145b,param_3,param_4,2,local_38);
  }
  piVar5 = (int *)(param_2 + 0x18);
  lVar4 = 4;
  iVar6 = 3;
  do {
    if (*piVar5 == 2) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
    }
    if (*piVar5 == 3) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 2;
    }
    piVar5 = piVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  AdjustWakeCapabilities(param_2,*(int *)(param_2 + 0x30),param_3,param_4);
  piVar5 = (int *)(longlong)*(int *)(param_2 + 0x2c);
  if (*(int *)(param_2 + 0x2c) != 0) {
    AdjustWakeCapabilities(param_2,*(int *)(param_2 + 0x10 + (longlong)piVar5 * 4),param_3,param_4);
    piVar5 = (int *)(ulonglong)*(uint *)(param_2 + 0x2c);
  }
  uVar1 = *(uint *)(param_2 + 4);
  if ((uVar1 >> 0xd & 1) == 0) {
    if ((uVar1 >> 0xc & 1) == 0) {
      if ((uVar1 >> 0xb & 1) == 0) {
        iVar6 = 1;
        if ((uVar1 >> 10 & 1) != 0) {
          iVar6 = 1;
        }
      }
      else {
        iVar6 = 2;
      }
    }
  }
  else {
    iVar6 = 4;
  }
  if (((int)piVar5 == 0) && (iVar6 != 1)) {
    iVar2 = 4;
    piVar5 = (int *)(param_2 + 0x20);
    do {
      if ((*piVar5 != 0) && (*piVar5 <= iVar6)) {
        *(int *)(param_2 + 0x2c) = iVar2;
        break;
      }
      iVar2 = iVar2 + -1;
      piVar5 = piVar5 + -1;
    } while (0 < iVar2);
  }
  if ((5 < DAT_140014088) && (uVar3 = _tlgKeywordOn(piVar5,4), (char)uVar3 != '\0')) {
    _tlgWriteTransfer_EtwWriteTransfer(piVar5,&DAT_1400116b2,param_3,param_4,2,local_38);
  }
  return;
}



===== AdjustWakeCapabilities @ 140031828 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AdjustWakeCapabilities(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  lVar2 = param_1;
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_14001192f,param_3,param_4,2,local_38);
    }
  }
  if (param_2 == 1) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x400;
  }
  else if (param_2 == 2) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x801;
  }
  else if (param_2 == 3) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x1002;
  }
  else if (param_2 == 4) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  }
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(lVar2,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_140011686,param_3,param_4,2,local_38);
    }
  }
  return;
}



===== AllocateResources @ 140031904 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 AllocateResources(longlong param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  void *pvVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint *_Size;
  undefined1 auStackY_98 [32];
  undefined4 local_68 [2];
  undefined8 local_60 [4];
  undefined4 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar4 = 4;
  uVar6 = 0xc000000d;
  _Size = param_3;
  if ((5 < DAT_140014088) && (uVar2 = _tlgKeywordOn(4,4), (char)uVar2 != '\0')) {
    local_34 = 0;
    local_40 = local_68;
    local_68[0] = 0xc000000d;
    local_38 = (undefined4)uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_140011d68,_Size,param_4,3,local_60);
  }
  if (param_2 != (uint *)0x0) {
    if (*param_2 == 1) {
      uVar1 = DetermineResourceListSize(param_2);
      if (uVar1 == 0xffffffff) {
        *(undefined8 *)(param_1 + 0x38) = 0;
      }
      else {
        _Size = (uint *)0x494d5049;
        pvVar3 = (void *)ExAllocatePool2(0x40,uVar1);
        *(void **)(param_1 + 0x38) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          uVar6 = 0;
          _Size = (uint *)(ulonglong)uVar1;
          memmove(pvVar3,param_2,(size_t)_Size);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar5 = 0x17;
            goto LAB_140031a3a;
          }
          goto LAB_140031a4a;
        }
      }
      uVar6 = 0xc0000017;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar5 = 0x18;
LAB_140031a3a:
        _Size = (uint *)&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar5 = 0x19;
      goto LAB_140031a3a;
    }
  }
LAB_140031a4a:
  if (param_3 == (uint *)0x0) goto LAB_140031b0e;
  if (*param_3 == 1) {
    uVar1 = DetermineResourceListSize(param_3);
    if (uVar1 == 0xffffffff) {
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    else {
      _Size = (uint *)0x494d5049;
      pvVar3 = (void *)ExAllocatePool2(0x40,uVar1);
      *(void **)(param_1 + 0x40) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        uVar6 = 0;
        _Size = (uint *)(ulonglong)uVar1;
        memmove(pvVar3,param_3,(size_t)_Size);
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140031b0e;
        uVar5 = 0x1a;
        goto LAB_140031afe;
      }
    }
    uVar6 = 0xc0000017;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140031b0e;
    uVar5 = 0x1b;
  }
  else {
    uVar6 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140031b0e;
    uVar5 = 0x1c;
  }
LAB_140031afe:
  _Size = (uint *)&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
          &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
LAB_140031b0e:
  if (5 < DAT_140014088) {
    uVar4 = 4;
    uVar2 = _tlgKeywordOn(4,4);
    if ((char)uVar2 != '\0') {
      local_34 = 0;
      local_40 = local_68;
      local_38 = (undefined4)uVar4;
      local_68[0] = uVar6;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1400115ef,_Size,param_4,3,local_60);
    }
  }
  return uVar6;
}



===== AssembleBootupBody @ 140031b80 =====

void AssembleBootupBody(undefined8 *param_1,undefined4 *param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0xdc;
  *(undefined2 *)((longlong)param_1 + 7) = 0x137;
  *(undefined4 *)((longlong)param_1 + 0xb) = *param_2;
  return;
}



===== AssembleBootupHead @ 140031ba0 =====

void AssembleBootupHead(undefined4 *param_1)

{
  *param_1 = 0x1f0441;
  param_1[1] = 0xffff016f;
  return;
}



===== DeRegisterDevice @ 140031bb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DeRegisterDevice(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40 [4];
  int *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_50 = 0;
  uStack_48 = 0;
  if (*(char *)(lVar1 + 0x248) == '\x01') {
    KeDeregisterBugCheckReasonCallback(lVar1 + 0x210);
    *(undefined1 *)(lVar1 + 0x248) = 0;
  }
  if (*(char *)(lVar1 + 0x249) == '\x01') {
    IoUnregisterShutdownNotification(param_1);
    *(undefined1 *)(lVar1 + 0x249) = 0;
  }
  if (*(char *)(lVar1 + 0x24a) == '\x01') {
    *(undefined1 *)(lVar1 + 0x24a) = 0;
    RtlInitUnicodeString(&local_50,L"WheaHighIrqlLogSelEventHandlerUnregister");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_50);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)();
    }
  }
  iVar2 = WmiTerminate(param_1);
  if (iVar2 < 0) {
    if (DAT_140014088 < 6) {
      return iVar2;
    }
    uVar4 = _tlgKeywordOn(param_1,4);
    if ((char)uVar4 != '\0') {
      local_14 = 0;
      local_20 = local_58;
      local_18 = 4;
      local_58[0] = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14001161f,param_3,param_4,3,local_40);
    }
  }
  if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(param_1,4), (char)uVar4 != '\0')) {
    local_14 = 0;
    local_20 = local_58;
    local_18 = 4;
    local_58[0] = iVar2;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011880,param_3,param_4,3,local_40);
  }
  return iVar2;
}



===== DefaultPnpHandler @ 140031d30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
DefaultPnpHandler(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  undefined8 local_50 [4];
  undefined4 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 != '\0') {
      local_58[0] = 0;
      local_30 = local_58;
      local_24 = 0;
      local_28 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011373,param_3,param_4,3,local_50);
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar4 = *(undefined8 *)(lVar1 + 0x10);
  uVar2 = IofCallDriver(uVar4,param_2);
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(uVar4,4);
    if ((char)uVar3 != '\0') {
      local_24 = 0;
      local_30 = local_58;
      local_28 = 4;
      local_58[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1400115bf,param_3,param_4,3,local_50);
    }
  }
  return uVar2;
}



===== DetermineResourceListSize @ 140031e2c =====

uint DetermineResourceListSize(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar3 = 0;
  if (param_1 != (uint *)0x0) {
    puVar4 = param_1 + 1;
    uVar5 = 0;
    uVar3 = 4;
    uVar1 = 4;
    if (*param_1 != 0) {
      do {
        puVar7 = puVar4 + 4;
        uVar3 = 0;
        uVar2 = 0x10;
        if (puVar4[3] != 0) {
          do {
            uVar6 = 0x14;
            if ((char)*puVar7 == '\x05') {
              if (~puVar7[1] < 0x14) {
                return 0xffffffff;
              }
              uVar6 = puVar7[1] + 0x14;
            }
            if (~uVar6 < uVar2) {
              return 0xffffffff;
            }
            uVar2 = uVar2 + uVar6;
            puVar7 = (uint *)((longlong)puVar7 + (ulonglong)uVar6);
            uVar3 = uVar3 + 1;
          } while (uVar3 < puVar4[3]);
        }
        if (~uVar2 < uVar1) {
          return 0xffffffff;
        }
        uVar3 = uVar1 + uVar2;
        puVar4 = (uint *)((longlong)puVar4 + (ulonglong)uVar2);
        uVar5 = uVar5 + 1;
        uVar1 = uVar3;
      } while (uVar5 < *param_1);
    }
  }
  return uVar3;
}



===== DispatchPnp @ 140031ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint DispatchPnp(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *pcVar6;
  undefined8 uVar7;
  char *pcVar8;
  longlong lVar9;
  undefined1 auStackY_b8 [32];
  int local_88;
  uint local_84 [3];
  undefined8 local_78 [4];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar9 = *(longlong *)(param_1 + 0x40);
  if (5 < DAT_140014088) {
    lVar5 = param_1;
    uVar4 = _tlgKeywordOn(param_1,4);
    if ((char)uVar4 != '\0') {
      local_88 = 0;
      local_58 = (uint *)&local_88;
      local_4c = 0;
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_1400113a4,param_3,param_4,3,local_78);
    }
  }
  lVar9 = lVar9 + 0x90;
  pcVar6 = "";
  pcVar8 = (char *)0x1;
  lVar5 = lVar9;
  iVar2 = IoAcquireRemoveLockEx(lVar9,param_2);
  if (iVar2 < 0) {
    if ((2 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar5,4), (char)uVar4 != '\0')) {
      local_4c = 0;
      local_58 = (uint *)&local_88;
      local_50 = 4;
      local_88 = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_14001141c,pcVar6,pcVar8,3,local_78);
    }
    uVar3 = CompleteRequest2(param_2,iVar2,pcVar6,pcVar8);
  }
  else {
    bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
    if (bVar1 < 0x18) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        pcVar8 = (&PTR_s_IRP_MN_START_DEVICE_14000f1a0)[bVar1];
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,pcVar6,pcVar8);
      }
      uVar3 = (*(code *)(&PTR_HandleStartDevice_14000f0a0)[bVar1])(param_1,param_2);
      if (bVar1 != 2) {
        pcVar6 = (char *)0x20;
        IoReleaseRemoveLockEx(lVar9,param_2);
        param_1 = lVar9;
      }
      if ((5 < DAT_140014088) && (uVar4 = _tlgKeywordOn(param_1,4), (char)uVar4 != '\0')) {
        local_4c = 0;
        local_58 = local_84;
        local_50 = 4;
        local_84[0] = uVar3;
        _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011e3e,pcVar6,pcVar8,3,local_78);
      }
    }
    else {
      if ((2 < DAT_140014088) && (uVar4 = _tlgKeywordOn(lVar5,4), (char)uVar4 != '\0')) {
        local_4c = 0;
        local_58 = (uint *)&local_88;
        local_3c = 0;
        local_48 = local_84;
        local_50 = 4;
        local_40 = 4;
        local_88 = iVar2;
        local_84[0] = (uint)bVar1;
        _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_1400118af,pcVar6,pcVar8,4,local_78);
      }
      uVar3 = DefaultPnpHandler(param_1,param_2,pcVar6,pcVar8);
      uVar7 = 0x20;
      IoReleaseRemoveLockEx(lVar9,param_2);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,uVar7,uVar3,bVar1);
      }
    }
  }
  return uVar3;
}



===== FreeResources @ 140032190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FreeResources(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (*(longlong *)(param_1 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0x494d5049);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x494d5049);
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(lVar2,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_1400117bf,param_3,param_4,2,local_38);
    }
  }
  return;
}



===== HWInitialize @ 140032238 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HWInitialize(undefined *param_1,undefined *param_2,undefined8 param_3,short *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  byte *pbVar6;
  undefined *puVar7;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  undefined8 local_60 [4];
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((5 < DAT_140014088) &&
     (puVar7 = param_1, uVar3 = _tlgKeywordOn(param_1,4), (char)uVar3 != '\0')) {
    _tlgWriteTransfer_EtwWriteTransfer(puVar7,&DAT_140011a30,param_3,param_4,2,local_60);
  }
  lVar5 = lVar1 + 0x138;
  uVar2 = ipmi_probe(lVar5,(longlong)param_1,param_2);
  if ((int)uVar2 < 0) {
    uVar4 = *(undefined8 *)(lVar1 + 0x18);
    *(undefined1 *)(lVar1 + 0x121) = 1;
    IoInvalidateDeviceState();
    if (DAT_140014088 < 6) {
      return uVar2;
    }
    uVar3 = _tlgKeywordOn(uVar4,4);
    if ((char)uVar3 == '\0') {
      return uVar2;
    }
    pbVar6 = &DAT_140011ad1;
  }
  else {
    param_4 = (short *)(lVar1 + 0x140);
    if ((*param_4 == 0x15) || (*param_4 == 0x20)) {
      puVar7 = param_1;
      uVar2 = ipmi_interface_init(lVar5,(longlong)param_1);
      if (5 < DAT_140014088) {
        puVar7 = (undefined *)0x4;
        uVar3 = _tlgKeywordOn(lVar5,4);
        if ((char)uVar3 != '\0') {
          local_34 = 0;
          local_40 = local_68;
          puVar7 = &DAT_140011d99;
          local_38 = 4;
          local_68[0] = uVar2;
          _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_140011d99,param_2,param_4,3,local_60);
        }
      }
      if ((int)uVar2 < 0) {
        param_4 = (short *)(lVar1 + 0x120);
        *(undefined1 *)param_4 = 1;
        IoInvalidateDeviceState(*(undefined8 *)(lVar1 + 0x18));
        param_2 = (undefined *)0x1;
        puVar7 = (undefined *)0xc00503eb;
        LogEvent(0xc00503eb,param_1,1,param_4);
        if (DAT_140014088 < 2) {
          return uVar2;
        }
        uVar3 = _tlgKeywordOn(puVar7,4);
        if ((char)uVar3 == '\0') {
          return uVar2;
        }
        pbVar6 = &DAT_140011581;
      }
      else {
        SelCacheInit((longlong)param_1,puVar7,param_2,param_4);
        puVar7 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          param_2 = (undefined *)(ulonglong)*(byte *)(lVar1 + 0x148);
          param_4 = (short *)(ulonglong)*(uint *)(lVar1 + 0x144);
          puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          WPP_SF_DDDI(puVar7,(ulonglong)*(byte *)(lVar1 + 0x158),param_2,*(uint *)(lVar1 + 0x144),
                      *(byte *)(lVar1 + 0x148),*(byte *)(lVar1 + 0x158),
                      (char)*(undefined8 *)(lVar1 + 0x150));
        }
        if (DAT_140014088 < 6) {
          return uVar2;
        }
        uVar3 = _tlgKeywordOn(puVar7,4);
        if ((char)uVar3 == '\0') {
          return uVar2;
        }
        pbVar6 = &DAT_140011e98;
      }
      local_40 = local_68;
      local_34 = 0;
      local_38 = 4;
      local_68[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer(puVar7,pbVar6,param_2,param_4,3,local_60);
      return uVar2;
    }
    param_2 = (undefined *)0x1;
    uVar4 = 0xc00503e9;
    LogEvent(0xc00503e9,param_1,1,param_4);
    if (DAT_140014088 < 2) {
      return uVar2;
    }
    uVar3 = _tlgKeywordOn(uVar4,4);
    if ((char)uVar3 == '\0') {
      return uVar2;
    }
    pbVar6 = &DAT_140011333;
  }
  local_40 = local_68;
  local_34 = 0;
  local_38 = 4;
  local_68[0] = uVar2;
  _tlgWriteTransfer_EtwWriteTransfer(uVar4,pbVar6,param_2,param_4,3,local_60);
  return uVar2;
}



===== HandleStartDevice @ 1400324e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HandleStartDevice(undefined *param_1,uint *param_2,uint *param_3,short *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined *puVar7;
  void *pvVar8;
  uint *puVar9;
  undefined1 auStackY_b8 [32];
  uint local_88 [4];
  undefined8 local_78 [4];
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar2 = *(longlong *)(param_2 + 0x2e);
  pvVar3 = *(void **)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = (uint *)&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  param_2[0xc] = 0;
  puVar9 = param_2;
  uVar5 = ForwardAndWait((longlong)param_1,(longlong)param_2,param_3,param_4);
  if (-1 < (int)uVar5) {
    param_3 = *(uint **)(lVar2 + 0x10);
    puVar9 = *(uint **)(lVar2 + 8);
    puVar7 = param_1;
    uVar5 = StartDevice(param_1,puVar9,param_3,param_4);
    if (-1 < (int)uVar5) {
      if (*(int *)((longlong)pvVar3 + 0xd0) == 2) {
        if (5 < DAT_140014088) {
          puVar9 = (uint *)0x0;
          uVar6 = _tlgKeywordOn(puVar7,4);
          if ((char)uVar6 != '\0') {
            local_58 = local_88;
            local_4c = 0;
            local_50 = 4;
            local_88[0] = uVar5;
            _tlgCreate1Sz_char(local_48,"PENDINGSTOP");
            puVar9 = (uint *)&DAT_1400113cf;
            _tlgWriteTransfer_EtwWriteTransfer(local_78,&DAT_1400113cf,param_3,param_4,4,local_78);
          }
        }
        InitializeStopLock((undefined1 *)((longlong)pvVar3 + 0xb0));
      }
      puVar9 = (uint *)CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
      pvVar8 = pvVar3;
      uVar5 = EnableAllInterfaces((longlong)pvVar3);
      if (5 < DAT_140014088) {
        puVar9 = (uint *)0x4;
        uVar6 = _tlgKeywordOn(pvVar8,4);
        if ((char)uVar6 != '\0') {
          local_58 = local_88;
          local_4c = 0;
          local_50 = 4;
          local_88[0] = uVar5;
          _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[*(int *)((longlong)pvVar3 + 0xd0)])
          ;
          puVar9 = (uint *)&DAT_140011a53;
          _tlgWriteTransfer_EtwWriteTransfer(local_78,&DAT_140011a53,param_3,param_4,4,local_78);
        }
      }
      uVar1 = *(undefined4 *)((longlong)pvVar3 + 0xd0);
      *(undefined4 *)((longlong)pvVar3 + 0xd0) = 0;
      *(undefined4 *)((longlong)pvVar3 + 0xd4) = uVar1;
      if (-1 < (int)uVar5) {
        uVar5 = RegisterDevice((longlong)param_1,puVar9,param_3,(char *)param_4);
      }
    }
  }
  cVar4 = ExIsSoftBoot();
  if (cVar4 == '\0') {
    CheckMSRDump(pvVar3,puVar9,param_3,(ulonglong)param_4);
  }
  uVar5 = CompleteRequest2((longlong)param_2,uVar5,param_3,param_4);
  if (5 < DAT_140014088) {
    uVar6 = _tlgKeywordOn(param_2,4);
    if ((char)uVar6 != '\0') {
      local_4c = 0;
      local_58 = local_88;
      local_50 = 4;
      local_88[0] = uVar5;
      _tlgWriteTransfer_EtwWriteTransfer(param_2,&DAT_140011850,param_3,param_4,3,local_78);
    }
  }
  return uVar5;
}



===== HandleStopDevice @ 140032720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
HandleStopDevice(longlong param_1,undefined *param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined1 local_78 [32];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar5 = param_2;
  if (5 < DAT_140014088) {
    puVar5 = (undefined *)0x4;
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 != '\0') {
      local_58 = local_88;
      local_88[0] = 0;
      local_4c = 0;
      local_50 = 4;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd0)]);
      puVar5 = &DAT_140011782;
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_140011782,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  lVar4 = (longlong)*(int *)(lVar1 + 0xd0);
  if ((*(int *)(lVar1 + 0xd0) != 1) && (5 < DAT_140014088)) {
    puVar5 = (undefined *)0x4;
    uVar3 = _tlgKeywordOn(lVar4,4);
    if ((char)uVar3 != '\0') {
      local_58 = local_88;
      local_88[0] = 0;
      local_4c = 0;
      local_50 = 4;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[lVar4]);
      puVar5 = &DAT_140011cb6;
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_140011cb6,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  StopDevice(param_1,puVar5,param_3,param_4);
  *(undefined4 *)(lVar1 + 0xd4) = *(undefined4 *)(lVar1 + 0xd0);
  *(undefined4 *)(lVar1 + 0xd0) = 2;
  uVar2 = DefaultPnpHandler(param_1,(longlong)param_2,param_3,param_4);
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 != '\0') {
      local_58 = local_88;
      local_4c = 0;
      local_50 = 4;
      local_88[0] = uVar2;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd0)]);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_140011b74,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  return uVar2;
}



===== HandleSurpriseRemoval @ 1400328d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
HandleSurpriseRemoval(longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined1 local_78 [32];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 != '\0') {
      local_58 = local_88;
      local_88[0] = 0;
      local_4c = 0;
      local_50 = 4;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[_DAT_000000d0]);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_140011eea,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  uVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  EnableAllInterfaces(lVar1);
  StopDevice(param_1,uVar4,param_3,param_4);
  *(undefined4 *)(lVar1 + 0xd4) = *(undefined4 *)(lVar1 + 0xd0);
  *(undefined4 *)(lVar1 + 0xd0) = 4;
  uVar2 = DefaultPnpHandler(param_1,param_2,param_3,param_4);
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(param_1,4);
    if ((char)uVar3 != '\0') {
      local_58 = local_88;
      local_4c = 0;
      local_50 = 4;
      local_88[0] = uVar2;
      _tlgCreate1Sz_char(local_48,(&PTR_s_STOPPED_14000f260)[*(int *)(lVar1 + 0xd0)]);
      _tlgWriteTransfer_EtwWriteTransfer
                (local_78,&DAT_14001180f,param_3,param_4,4,(undefined8 *)local_78);
    }
  }
  return uVar2;
}



===== IpmiProcessOsRecWorkQueueItem @ 140032a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IpmiProcessOsRecWorkQueueItem
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStackY_78 [32];
  uint local_48 [2];
  undefined8 local_40 [4];
  uint *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  bVar2 = WriteOSREC2SEL(*(longlong *)(param_1 + 0x18),param_2 + 0x1c,param_3,param_4);
  lVar4 = *(longlong *)(param_2 + 0x10);
  uVar5 = ~-(uint)(bVar2 != 0) & 0xc0000001;
  if (lVar4 != 0) {
    CompleteRequest2(lVar4,uVar5,param_3,param_4);
  }
  LOCK();
  uVar1 = *(uint *)(param_2 + 0x18);
  *(uint *)(param_2 + 0x18) = 0;
  uVar3 = (ulonglong)uVar1;
  UNLOCK();
  if (5 < DAT_140014088) {
    local_18 = 4;
    uVar3 = _tlgKeywordOn(lVar4,4);
    if ((char)uVar3 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = uVar5;
      uVar3 = _tlgWriteTransfer_EtwWriteTransfer(lVar4,&DAT_140011c28,param_3,param_4,3,local_40);
    }
  }
  return uVar3;
}



===== IpmiWorkQueueInit @ 140032ad8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IpmiWorkQueueInit(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  memset(&OsSelRecWorkQueue,0,0x88);
  _DAT_14002a328 = &OsSelRecWorkQueue;
  _OsSelRecWorkQueue = &OsSelRecWorkQueue;
  DAT_14002a338 = param_2;
  KeInitializeSpinLock(&DAT_14002a330);
  puVar3 = &OsSelRecWorkQueue;
  puVar2 = &DAT_14002a340;
  KeInitializeDpc(&DAT_14002a340,IpmiWorkQueueDpcRoutine);
  _DAT_14002a380 = 0;
  _DAT_14002a390 = IpmiWorkQueueWorkerRoutine;
  _DAT_14002a3a0 = IpmiProcessOsRecWorkQueueItem;
  _DAT_14002a398 = &OsSelRecWorkQueue;
  if (5 < DAT_140014088) {
    uVar1 = _tlgKeywordOn(puVar2,4);
    if ((char)uVar1 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(puVar2,&DAT_140011ec3,puVar3,param_4,2,local_38);
    }
  }
  return;
}



===== IpmiWorkQueueWorkerRoutine @ 140032bd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IpmiWorkQueueWorkerRoutine
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  lVar1 = *(longlong *)(param_1 + 0x18);
  while( true ) {
    lVar2 = ExInterlockedRemoveHeadList(param_1,param_1 + 0x10);
    if ((lVar2 == 0) || (*(char *)(lVar1 + 0x1f8) != '\0')) break;
    (**(code **)(param_1 + 0x80))(param_1,lVar2);
  }
  if (5 < DAT_140014088) {
    uVar3 = _tlgKeywordOn(lVar2,4);
    if ((char)uVar3 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_140011e68,param_3,param_4,2,local_38);
    }
  }
  return;
}



===== RegisterDevice @ 140032c8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RegisterDevice(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  byte extraout_var;
  int iVar5;
  code *pcVar6;
  ulonglong uVar7;
  undefined *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40 [4];
  int *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar8 = &OsRecWrapper;
  uVar10 = 0x15800;
  local_50 = 0;
  uStack_48 = 0;
  memset(&OsRecWrapper,0,0x15800);
  if (*(char *)(lVar1 + 0x24b) == '\0') {
    *(undefined1 *)(lVar1 + 0x24b) = 1;
    IpmiWorkQueueInit(puVar8,lVar1,uVar10,param_4);
  }
  if (*(char *)(lVar1 + 0x24a) == '\0') {
    RtlInitUnicodeString(&local_50,L"WheaHighIrqlLogSelEventHandlerRegister");
    pcVar6 = (code *)MmGetSystemRoutineAddress(&local_50);
    if (pcVar6 != (code *)0x0) {
      uVar2 = (*pcVar6)(HighIrqlLogSelEventHandler,lVar1);
      *(undefined1 *)(lVar1 + 0x24a) = uVar2;
    }
  }
  if ((*(char *)(lVar1 + 0x248) == '\0') &&
     ((*(int *)(lVar1 + 0x144) == 1 || (*(int *)(lVar1 + 0x144) == 4)))) {
    lVar9 = lVar1 + 0x210;
    *(undefined1 *)(lVar1 + 0x23c) = 0;
    param_4 = "Microsoft IPMI Device Driver";
    *(longlong *)(lVar1 + 0x240) = lVar1;
    uVar10 = 8;
    cVar3 = KeRegisterBugCheckReasonCallback(lVar9,BugCheckReasonCallbackRoutine);
    *(char *)(lVar1 + 0x248) = cVar3;
    if ((cVar3 == '\0') && (5 < DAT_140014088)) {
      uVar7 = _tlgKeywordOn(lVar9,4);
      if ((char)uVar7 != '\0') {
        _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_140011bb0,uVar10,param_4,2,local_40);
      }
    }
  }
  if (*(char *)(lVar1 + 0x249) == '\0') {
    lVar9 = param_1;
    IoRegisterShutdownNotification();
    bVar4 = extraout_var >> 7 ^ 1;
    *(byte *)(lVar1 + 0x249) = bVar4;
    if ((bVar4 == 0) && (5 < DAT_140014088)) {
      uVar7 = _tlgKeywordOn(lVar9,4);
      if ((char)uVar7 != '\0') {
        _tlgWriteTransfer_EtwWriteTransfer(lVar9,&DAT_140011e08,uVar10,param_4,2,local_40);
      }
    }
  }
  iVar5 = WmiInitialize(param_1);
  if ((iVar5 < 0) && (5 < DAT_140014088)) {
    uVar7 = _tlgKeywordOn(param_1,4);
    if ((char)uVar7 != '\0') {
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14001174f,uVar10,param_4,2,local_40);
    }
  }
  BmcWheaAddErrorSource();
  if (5 < DAT_140014088) {
    uVar7 = _tlgKeywordOn(param_1,4);
    if ((char)uVar7 != '\0') {
      local_14 = 0;
      local_20 = local_58;
      local_18 = 4;
      local_58[0] = iVar5;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140011d3b,uVar10,param_4,3,local_40);
    }
  }
  return iVar5;
}



===== StartDevice @ 140032edc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint StartDevice(undefined *param_1,uint *param_2,uint *param_3,short *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined1 auStackY_98 [32];
  uint local_68 [2];
  undefined8 local_60 [4];
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  puVar3 = *(undefined **)(param_1 + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  GetRegValues();
  puVar5 = param_3;
  uVar1 = AllocateResources((longlong)puVar3,param_2,param_3,param_4);
  if ((int)uVar1 < 0) {
LAB_140033032:
    FreeResources((longlong)puVar3,param_2,puVar5,param_4);
    if (DAT_140014088 < 3) goto LAB_14003307f;
    uVar2 = _tlgKeywordOn(puVar3,4);
    if ((char)uVar2 == '\0') goto LAB_14003307f;
    pbVar4 = &DAT_14001171b;
  }
  else {
    uVar1 = HWInitialize(param_1,(undefined *)param_3,puVar5,param_4);
    param_2 = param_3;
    if ((int)uVar1 < 0) goto LAB_140033032;
    *(undefined4 *)(puVar3 + 0x124) = 1;
    if (puVar3[0x209] == '\0') {
      puVar3[0x209] = 1;
      if (2 < DAT_140014088) {
        uVar2 = _tlgKeywordOn(param_1,4);
        if ((char)uVar2 != '\0') {
          local_34 = 0;
          local_40 = local_68;
          local_38 = 4;
          local_68[0] = uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14001195c,puVar5,param_4,3,local_60);
        }
      }
      PublishSystemInfo((longlong)puVar3);
      WriteOSBootupSEL((longlong)puVar3);
      goto LAB_14003307f;
    }
    puVar3 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar5 = (uint *)&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
      WPP_SF_(puVar3,0x2a,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
    }
    if (DAT_140014088 < 3) goto LAB_14003307f;
    uVar2 = _tlgKeywordOn(puVar3,4);
    if ((char)uVar2 == '\0') goto LAB_14003307f;
    pbVar4 = &DAT_140011f2c;
  }
  local_40 = local_68;
  local_34 = 0;
  local_38 = 4;
  local_68[0] = uVar1;
  _tlgWriteTransfer_EtwWriteTransfer(puVar3,pbVar4,puVar5,param_4,3,local_60);
LAB_14003307f:
  if (5 < DAT_140014088) {
    uVar2 = _tlgKeywordOn(puVar3,4);
    if ((char)uVar2 != '\0') {
      local_34 = 0;
      local_40 = local_68;
      local_38 = 4;
      local_68[0] = uVar1;
      _tlgWriteTransfer_EtwWriteTransfer(puVar3,&DAT_14001165c,puVar5,param_4,3,local_60);
    }
  }
  return uVar1;
}



===== StopDevice @ 1400330f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void StopDevice(longlong param_1,undefined8 param_2,undefined *param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined *puVar7;
  byte *pbVar8;
  undefined1 auStackY_88 [32];
  int local_58 [2];
  undefined8 local_50 [4];
  int *local_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  puVar7 = *(undefined **)(param_1 + 0x40);
  iVar3 = 0;
  puVar6 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_2 = 0x2b;
    param_3 = &WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids;
    WPP_SF_(puVar6,0x2b,&WPP_ddb1df8791ca3ee93612b76f629e2340_Traceguids);
  }
  iVar2 = 1;
  LOCK();
  iVar1 = *(int *)(puVar7 + 0x124);
  if (iVar1 == 1) {
    *(int *)(puVar7 + 0x124) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if (iVar2 != 0) {
    uVar4 = AcquireStopLock(puVar7 + 0xb0);
    iVar3 = (int)uVar4;
    if (iVar3 < 0) {
      puVar6 = (undefined *)(ulonglong)DAT_140014088;
      iVar3 = -0x3ffffee0;
      if ((1 < DAT_140014088) && (uVar5 = _tlgKeywordOn(puVar6,4), (char)uVar5 != '\0')) {
        local_30 = local_58;
        local_58[0] = -0x3ffffee0;
        local_28 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(puVar6,&DAT_1400119c2,param_3,param_4,3,local_50);
        puVar6 = (undefined *)(ulonglong)DAT_140014088;
      }
      if ((uint)puVar6 < 6) {
        return;
      }
      uVar5 = _tlgKeywordOn(puVar6,4);
      if ((char)uVar5 == '\0') {
        return;
      }
      local_28 = 4;
      pbVar8 = &DAT_140011c64;
      goto LAB_14003323c;
    }
    ReleaseStopLockAndWait(puVar7 + 0xb0);
    DeRegisterDevice(param_1,param_2,param_3,param_4);
    ipmi_interface_cleanup((longlong)(puVar7 + 0x138),param_1);
    FreeResources((longlong)puVar7,param_1,param_3,param_4);
    puVar6 = puVar7;
  }
  if (DAT_140014088 < 6) {
    return;
  }
  uVar4 = 4;
  uVar5 = _tlgKeywordOn(puVar6,4);
  if ((char)uVar5 == '\0') {
    return;
  }
  pbVar8 = &DAT_140011c8d;
  local_28 = uVar4;
LAB_14003323c:
  local_30 = local_58;
  local_58[0] = iVar3;
  _tlgWriteTransfer_EtwWriteTransfer(puVar6,pbVar8,param_3,param_4,3,local_50);
  return;
}



===== WdmlibInit @ 14003328c =====

void WdmlibInit(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
  PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
  if (PfnIoCreateDeviceSecure == (code *)0x0) {
    PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
  }
  RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
  MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = 1;
  return;
}



===== IoDevObjCreateDeviceSecure @ 140033320 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,uint *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (uint *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140033480;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (uint *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140033480;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_140033480:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1400334b4 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 1400335a4 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 140033684 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 140033784 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 140033870 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  short *local_res8;
  uint local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_res18[0] = 0;
  iVar5 = 0;
  local_58 = (wchar_t *)0x0;
  local_50[0] = 0;
  uVar15 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar3 = false;
  bVar2 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar15 = uVar15 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar11 = uVar15 / 5;
  local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11);
  if ((uVar15 != uVar11 * 5) || ((uVar15 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar11 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar15 = uVar11 * 0x30 + 8;
      if (0xffff < uVar15) {
        uVar15 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar15,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar15);
        *_Dst = 2;
        _Dst[1] = (short)uVar15;
        *(undefined4 *)(_Dst + 2) = 0;
        uVar15 = (uint)local_res8;
        for (local_res10 = 0; uVar11 = 0, local_res10 < uVar15; local_res10 = local_res10 + 1) {
          local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
          for (; *param_1 == L' '; param_1 = param_1 + 1) {
          }
          if (*param_1 == L'(') {
            do {
              param_1 = param_1 + 1;
            } while (*param_1 == L' ');
          }
          iVar4 = _wcsnicmp(param_1,L"A",1);
          if (iVar4 != 0) {
LAB_140033b94:
            iVar5 = -0x3ffffff3;
LAB_140033b96:
            lVar7 = *param_2;
            goto LAB_140033ba2;
          }
          for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          if (*pwVar6 != L';') goto LAB_140033b94;
          do {
            pwVar6 = pwVar6 + 1;
          } while (*pwVar6 == L' ');
          while (wVar1 = *pwVar6, wVar1 != L';') {
            while (wVar1 == L' ') {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            }
            uVar9 = SepSddlLookupAccessMaskInTable(pwVar6,local_res18,(longlong *)&local_58);
            if ((int)uVar9 == 0) {
              SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
              if (local_58 == pwVar6) goto LAB_140033b94;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar6 = local_58;
          }
          pwVar6 = pwVar6 + 1;
          if (iVar5 != 0) goto LAB_140033b96;
          lVar7 = 2;
          do {
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') {
              iVar5 = -0x3ffffff3;
            }
            pwVar6 = pwVar6 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
          if (iVar5 != 0) goto LAB_140033b96;
          for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          local_res8 = (short *)0x0;
          ppsVar13 = &local_res8;
          uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
          iVar5 = (int)uVar9;
          if (iVar5 != 0) break;
          psVar12 = local_res8;
          if (local_res8 == (short *)0x0) {
LAB_140033b2e:
            iVar5 = -0x3fffff89;
            goto LAB_140033b96;
          }
          for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
          }
          if (*psVar12 != 0x29) goto LAB_140033b2e;
          param_1 = psVar12 + 1;
          if (local_50[0] != 0) {
            uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar11,
                                       uVar15 - local_res10,local_50[0]);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) goto LAB_140033b96;
          }
          if (*param_1 == L'(') {
            param_1 = psVar12 + 2;
          }
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(undefined2 *)(lVar7 + 2) = (undefined2)local_res20[0];
          return 0;
        }
LAB_140033ba2:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140033be0 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  do {
    if (0xd < uVar6) {
      uVar4 = 0xc0000073;
LAB_140033c88:
      *param_2 = uVar5;
      return uVar4;
    }
    uVar3 = (ulonglong)uVar6;
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14001442c + uVar3 * 0x18),
                      (ulonglong)*(uint *)(&DAT_140014434 + uVar3 * 0x18));
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_140014428 + uVar3 * 0x18);
      uVar6 = *(uint *)(&DAT_140014434 + uVar3 * 0x18);
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto code_r0x000140033c6d;
      }
      else {
code_r0x000140033c6d:
        uVar5 = *(undefined8 *)
                 (*(longlong *)(&DAT_140014420 + uVar3 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar4 = 0;
      goto LAB_140033c88;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 140033cb4 =====

undefined8 SepSddlLookupAccessMaskInTable(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  while( true ) {
    if (7 < uVar2) {
      *param_2 = 0;
      *param_3 = (longlong)param_1;
      return 0;
    }
    uVar3 = (ulonglong)uVar2;
    iVar1 = _wcsnicmp(param_1,(wchar_t *)(&PTR_u_RC_140014110)[uVar3 * 2],
                      (ulonglong)(uint)(&DAT_140014118)[uVar3 * 4]);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = (&DAT_14001411c)[uVar3 * 4];
  *param_3 = (longlong)(param_1 + (uint)(&DAT_140014118)[uVar3 * 4]);
  return 1;
}



===== SepSddlParseWideStringUlong @ 140033d4c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *param_1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_140033db9:
      iVar6 = 10;
      goto LAB_140033d90;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140033db9;
  iVar6 = 0x10;
LAB_140033d90:
  uVar7 = 0;
  for (puVar4 = param_1; uVar1 = *puVar4, uVar1 != 0; puVar4 = puVar4 + 1) {
    if ((ushort)(uVar1 - 0x30) < 10) {
      iVar2 = uVar1 - 0x30;
    }
    else {
      if (iVar6 != 0x10) break;
      if ((ushort)(uVar1 - 0x41) < 6) {
        iVar2 = uVar1 - 0x37;
      }
      else {
        if (5 < (ushort)(uVar1 - 0x61)) break;
        iVar2 = uVar1 - 0x57;
      }
    }
    uVar5 = iVar6 * uVar7 + iVar2;
    if (uVar5 < uVar7) goto LAB_140033dfd;
    uVar7 = uVar5;
  }
  if (puVar4 == param_1) {
LAB_140033dfd:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140033e24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_140033f69;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140033f69:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 140033fc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (uint *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140010270,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar3 = (ulonglong)*param_1;
    pwVar5 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar4 = 2;
    }
    else {
      uVar2 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar5,uVar3,0,&local_b8,local_a8);
      uVar4 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar4;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 140034164 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1400101f0);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_1400342e3;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140010208,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1400342e3;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140010220,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1400342e3;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140010250,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1400342e3:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 140034328 =====

ulonglong PpRegStateReadCreateClassCreationSettings(uint *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140010190,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1400101a8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400101b8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400101d8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 14003448c =====

ulonglong PpRegStateUpdateStackCreationSettings(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,0x140010190,uVar7,uVar8,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = (ulonglong)uVar2;
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1400101f0);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar2 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar3);
        uVar4 = (ulonglong)uVar2;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1400345f4 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateUcKey @ 1400346f0 =====

int CmRegUtilCreateUcKey
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined8 local_res8 [3];
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res20[0] = 0;
  local_res8[0] = 0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,0xf003f,&local_38,0,0,0,local_res20);
  if (iVar1 < 0) {
    local_res8[0] = 0;
    local_res20[0] = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_res20[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 140034798 =====

void CmRegUtilCreateWstrKey
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [12];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilCreateUcKey(param_1,local_18,param_3,param_1,param_5,param_6,param_7);
  }
  return;
}



===== CmRegUtilOpenExistingWstrKey @ 1400347f8 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 14003488c =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_1400349c4;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1400349c4:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 140034a08 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 140034b54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 140034bf8 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== ipmi_send_ioctl @ 140034c60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ipmi_send_ioctl(undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
                   undefined1 param_5,ushort param_6,void *param_7,ushort *param_8,char *param_9)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong _Size;
  undefined1 auStack_2f8 [32];
  undefined4 local_2d8;
  undefined **local_2d0;
  int local_2c8 [8];
  undefined4 local_2a8;
  undefined1 local_2a4;
  ushort local_2a3;
  undefined1 local_2a1;
  undefined1 local_2a0;
  undefined1 local_29f;
  ushort local_29e;
  char acStack_29c [580];
  undefined *local_58;
  uint local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2f8;
  memset(&local_2a8,0,0x248);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_4f9253013b2e3457212a0e6bed52ec85_Traceguids);
  }
  _Size = (ulonglong)param_6;
  if ((((param_6 == 0) || (param_7 != (void *)0x0)) && (param_9 != (char *)0x0)) &&
     ((_Size + 6 < 0x245 && (_Size + 10 < 0x245)))) {
    local_2a0 = param_5;
    local_2a3 = param_6;
    local_2a4 = param_3;
    local_2a1 = param_4;
    if ((param_6 != 0) && (param_7 != (void *)0x0)) {
      memmove(&local_29f,param_7,_Size);
      _Size = (ulonglong)local_2a3;
    }
    acStack_29c[_Size] = -1;
    uVar5 = IpmiComputeBufferResponseLength(local_2a3);
    *(ushort *)(acStack_29c + (_Size - 2)) = (ushort)uVar5;
    iVar4 = ipmi_send_request(param_1,&local_2a8);
    if (iVar4 == 0) {
      cVar1 = acStack_29c[_Size];
      *param_9 = cVar1;
      if (cVar1 == '\0') {
        uVar2 = *(ushort *)(acStack_29c + (_Size - 2));
        if ((uint)*param_8 < uVar2 + 1) {
          iVar4 = -0x3fffffe9;
        }
        else {
          if (uVar2 != 0) {
            memmove(param_9 + 1,acStack_29c + _Size + 1,(ulonglong)uVar2);
          }
          *param_8 = uVar2 + 1;
        }
      }
      else {
        *param_8 = 1;
      }
    }
    if (5 < DAT_140014088) {
      if (((DAT_140014098 & 2) == 0) || (((uint)DAT_1400140a0 & 2) != DAT_1400140a0)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        local_38 = local_2c8;
        local_2c8[3] = 5;
        local_58 = PTR_DAT_140014090;
        local_30 = 4;
        local_2c8[2] = 0xb000000;
        local_2c8[4] = 2;
        local_2c8[5] = 0;
        local_50 = (uint)*(ushort *)PTR_DAT_140014090;
        local_48 = &DAT_140011138;
        local_4c = 2;
        local_40 = 0x1e;
        local_3c = 1;
        local_2c8[1] = 0x1bf9;
        local_2d0 = &local_58;
        local_2d8 = 3;
        local_2c8[0] = iVar4;
        EtwWriteTransfer(DAT_1400140a8,local_2c8 + 2,0,0);
      }
    }
  }
  else {
    iVar4 = -0x3ffffff3;
  }
  return iVar4;
}



===== entry @ 140035010 =====

void entry(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140035044 =====

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



===== wil_InitializeFeatureStaging @ 140035078 =====

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
    plVar3 = (longlong *)&wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding(plVar3), plVar3 != (longlong *)0x0) {
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
      plVar3 = plVar3 + 7;
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140035168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar3 = (longlong *)&wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar3);
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
    plVar3 = plVar2 + 7;
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


