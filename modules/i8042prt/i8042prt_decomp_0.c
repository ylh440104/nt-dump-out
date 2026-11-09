
===== _tlgKeywordOn @ 1c0001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_1c0012020 & 0x400000000000) == 0) ||
     (in_RAX = DAT_1c0012028 & 0x400000000000, in_RAX != DAT_1c0012028)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c000103c =====

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
  *param_6 = PTR_DAT_1c0012018;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c0012018;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c0012030,&local_18,0,0,param_5,param_6);
  return;
}



===== I8xReadPortUchar @ 1c00010f0 =====

undefined1 I8xReadPortUchar(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== I8xMouseIsrWritePort @ 1c0001100 =====

void I8xMouseIsrWritePort(undefined8 param_1,ulonglong param_2)

{
  I8xPutByteAsynchronous('\x01',CONCAT71((int7)(param_2 >> 8),0xd4));
  I8xPutByteAsynchronous('\0',param_2 & 0xff);
  return;
}



===== I8xPutByteAsynchronous @ 1c0001130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xPutByteAsynchronous(char param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined2 uVar6;
  
  uVar3 = param_2 & 0xff;
  uVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0x37,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  uVar5 = 0;
  if (*(short *)(Globals + 0x48) != 0) {
    do {
      uVar5 = uVar5 + 1;
      uVar1 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
      if ((uVar1 & 2) == 0) goto LAB_1c00011b3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x12,0x38,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
    } while (uVar5 < *(ushort *)(Globals + 0x48));
  }
  uVar5 = uVar5 + 1;
LAB_1c00011b3:
  if (uVar5 < *(ushort *)(Globals + 0x48)) {
    if (param_1 == '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x14,0x3a,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)param_2);
      }
      uVar2 = *(undefined8 *)(Globals + 0xd8);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x14,0x3b,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)param_2);
      }
      uVar2 = *(undefined8 *)(Globals + 0xd0);
    }
    (*DAT_1c00121e0)(uVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar6 = 0x3c;
    uVar5 = 0x13;
    uVar4 = uVar3;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar6 = 0x39;
    uVar5 = 0x15;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar5,uVar6,
                   &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  return;
}



===== I8xInitiateOutputWrapper @ 1c0001310 =====

undefined8 I8xInitiateOutputWrapper(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x40);
  *(longlong *)(lVar2 + 0x200) = param_1[1];
  *(int *)(lVar2 + 0x20c) = (int)param_1[2];
  *(undefined4 *)(lVar2 + 0x208) = 0;
  *(undefined2 *)(lVar2 + 0x230) = 0;
  *(undefined4 *)(lVar2 + 0x210) = 1;
  uVar3 = I8xInitiateIo(lVar1,lVar2);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== I8xInitiateIo @ 1c0001360 =====

void I8xInitiateIo(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,99,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(Globals + 0xcc) = 3;
  lVar3 = *(longlong *)(lVar2 + 0x200);
  if ((lVar3 != 0) && (*(int *)(lVar2 + 0x210) == 1)) {
    uVar1 = *(uint *)(lVar2 + 0x208);
    uVar4 = (ulonglong)uVar1;
    if (uVar1 < *(uint *)(lVar2 + 0x20c)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,4,100,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,(char)uVar1,
                           *(undefined1 *)(uVar4 + lVar3));
      }
      if (*(char *)(lVar2 + 0x235) == '\0') {
        I8xPutByteAsynchronous('\x01',CONCAT71((int7)(uVar4 >> 8),0xd4));
      }
      uVar4 = (ulonglong)*(byte *)((ulonglong)*(uint *)(lVar2 + 0x208) + lVar3);
      *(uint *)(lVar2 + 0x208) = *(uint *)(lVar2 + 0x208) + 1;
      I8xPutByteAsynchronous('\0',uVar4);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,5,0x65,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      uVar5 = 0xffffffffc005000e;
      if (*(char *)(lVar2 + 0x235) == '\0') {
        uVar5 = 0xffffffffc0050034;
      }
      uVar4 = 0;
      KeInsertQueueDpc(lVar2 + 0xe8,0,uVar5);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,3,0x66,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
  }
  return;
}



===== I8xProcessCrashDump @ 1c00014f0 =====

void I8xProcessCrashDump(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  undefined1 local_res10 [8];
  
  bVar1 = *(byte *)(param_1 + 0x3b8);
  bVar2 = *(byte *)(param_1 + 0x3b9);
  bVar3 = *(byte *)(param_1 + 0x3c0);
  bVar4 = *(byte *)(param_1 + 0x3c1);
  if (param_2 < 0x80) {
    if (param_2 == 0x1d) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 0x20;
        return;
      }
      if (param_3 == 1) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 2;
        return;
      }
      return;
    }
    if (param_2 == 0x2a) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 0x10;
        return;
      }
      return;
    }
    if (param_2 == 0x38) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 0x40;
        return;
      }
      if (param_3 == 1) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 4;
        return;
      }
      return;
    }
    if (param_2 == 0x36) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) | 1;
        return;
      }
      return;
    }
    if (bVar1 < 0x80) {
      if ((param_3 == 0) && ((param_2 & 0x7f) == bVar1)) {
        return;
      }
    }
    else if ((param_3 == 1) && (((bVar1 ^ param_2) & 0x7f) == 0)) {
      return;
    }
    if (bVar2 < 0x80) {
      if ((param_3 == 0) && ((param_2 & 0x7f) == bVar2)) {
        return;
      }
    }
    else if ((param_3 == 1) && (((bVar2 ^ param_2) & 0x7f) == 0)) {
      return;
    }
    if (bVar3 < 0x80) {
      if ((param_3 == 0) && ((param_2 & 0x7f) == bVar3)) {
        return;
      }
    }
    else if ((param_3 == 1) && (((bVar3 ^ param_2) & 0x7f) == 0)) {
      return;
    }
    if (bVar4 < 0x80) {
      if ((param_3 == 0) && ((param_2 & 0x7f) == bVar4)) {
        return;
      }
    }
    else if ((param_3 == 1) && (((bVar4 ^ param_2) & 0x7f) == 0)) {
      return;
    }
LAB_1c000165b:
    *(undefined4 *)(param_1 + 0x3b4) = 0;
    return;
  }
  bVar6 = param_2 & 0x7f;
  if (bVar6 == 0x36) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0fe;
      return;
    }
    return;
  }
  if (bVar6 == 0x2a) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0ef;
      return;
    }
    return;
  }
  if (bVar6 == 0x1d) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0df;
      return;
    }
    if (param_3 == 1) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0fd;
      return;
    }
    return;
  }
  if (bVar6 == 0x38) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0bf;
      return;
    }
    if (param_3 == 1) {
      *(uint *)(param_1 + 0x3b4) = *(uint *)(param_1 + 0x3b4) & 0xfffff0fb;
      return;
    }
    return;
  }
  if (bVar1 < 0x80) {
    if ((param_3 == 0) && ((param_2 & 0x7f) == bVar1)) goto LAB_1c00015d9;
  }
  else if ((param_3 == 1) && (((bVar1 ^ param_2) & 0x7f) == 0)) goto LAB_1c00015d9;
  if (bVar2 < 0x80) {
    if ((param_3 == 0) && ((param_2 & 0x7f) == bVar2)) goto LAB_1c00015d9;
  }
  else if ((param_3 == 1) && (((bVar2 ^ param_2) & 0x7f) == 0)) {
LAB_1c00015d9:
    uVar5 = *(uint *)(param_1 + 0x3b4);
    uVar7 = uVar5 | 0x200;
    if ((uVar5 >> 8 & 1) == 0) {
      uVar7 = uVar5 | 0x100;
    }
    *(uint *)(param_1 + 0x3b4) = uVar7;
    if (uVar7 == (*(uint *)(param_1 + 0x3b0) | 0x300)) {
      *(undefined4 *)(param_1 + 0x3b4) = 0;
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xe2,0,0,0,0);
    }
    return;
  }
  if (bVar3 < 0x80) {
    if ((param_3 == 0) && ((param_2 & 0x7f) == bVar3)) goto LAB_1c0001889;
  }
  else if ((param_3 == 1) && (((bVar3 ^ param_2) & 0x7f) == 0)) goto LAB_1c0001889;
  if (bVar4 < 0x80) {
    if ((param_3 != 0) || ((param_2 & 0x7f) != bVar4)) goto LAB_1c000165b;
  }
  else if ((param_3 != 1) || (((bVar4 ^ param_2) & 0x7f) != 0)) goto LAB_1c000165b;
LAB_1c0001889:
  uVar5 = *(uint *)(param_1 + 0x3b4);
  uVar7 = uVar5 | 0x800;
  if ((uVar5 >> 10 & 1) == 0) {
    uVar7 = uVar5 | 0x400;
  }
  *(uint *)(param_1 + 0x3b4) = uVar7;
  if (uVar7 == (*(uint *)(param_1 + 0x3bc) | 0xc00)) {
    *(undefined4 *)(param_1 + 0x3b4) = 0;
    local_res10[0] = 0;
    KdChangeOption(0,1,local_res10,0,0,0);
    KdEnableDebugger();
    return;
  }
  return;
}



===== I8xQueueCurrentKeyboardInput @ 1c0001960 =====

void I8xQueueCurrentKeyboardInput(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0x60) != 0) {
    puVar3 = (undefined8 *)(lVar1 + 0x388);
    uVar2 = I8xWriteDataToKeyboardQueue(lVar1,puVar3);
    if ((char)uVar2 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,0x1c,0x43,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      if (*(char *)(lVar1 + 0x232) != '\0') {
        KeInsertQueueDpc(lVar1 + 0xe8,0,0x4005000b);
        *(undefined1 *)(lVar1 + 0x232) = 0;
      }
    }
    else if (*(int *)(lVar1 + 0x360) < 0) {
      KeInsertQueueDpc(lVar1 + 0x2e0,*(undefined8 *)(param_1 + 0x20),0);
    }
    else {
      *(int *)(lVar1 + 0x360) = *(int *)(lVar1 + 0x360) + 1;
    }
  }
  *(undefined2 *)(lVar1 + 0x38c) = 0;
  return;
}



===== I8xWriteDataToKeyboardQueue @ 1c0001a40 =====

ulonglong I8xWriteDataToKeyboardQueue(longlong param_1,undefined8 *param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  
  puVar5 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x16,
                     &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,2,0x17,
                         &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x370),
                         (char)*(undefined8 *)(param_1 + 0x378));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,2,0x18,
                          &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,
                          (char)*(undefined4 *)(param_1 + 0x5c));
      }
    }
  }
  puVar1 = (ulonglong *)(param_1 + 0x370);
  puVar2 = (undefined8 *)*puVar1;
  if ((puVar2 == *(undefined8 **)(param_1 + 0x378)) && (*(int *)(param_1 + 0x5c) != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,5,0x19,
                       &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
    }
    uVar4 = *puVar1;
    if (uVar4 == *(ulonglong *)(param_1 + 0x368)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,2,0x1a,
                         &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
      }
      uVar4 = *(ulonglong *)(param_1 + 0x380);
    }
    *(undefined4 *)(uVar4 - 10) = 0xff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,3,0x1b,
                               &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
    }
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    *puVar2 = *param_2;
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(param_2 + 1);
    iVar3 = *(int *)(param_1 + 0x5c) + 1;
    *puVar1 = *puVar1 + 0xc;
    *(int *)(param_1 + 0x5c) = iVar3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,4,0x1c,
                        &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,(char)iVar3);
    }
    uVar4 = *(ulonglong *)(param_1 + 0x380);
    if (*puVar1 == uVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,2,0x1d,
                         &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
      }
      uVar4 = *(ulonglong *)(param_1 + 0x368);
      *(ulonglong *)(param_1 + 0x370) = uVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar5,3,0x1e,
                               &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
    }
    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4;
}



===== I8042KeyboardInterruptService @ 1c0001cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 I8042KeyboardInterruptService(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  byte bVar6;
  ulonglong in_RAX;
  code *pcVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  code *pcVar11;
  code *pcVar12;
  undefined8 uVar13;
  undefined2 uVar14;
  code *pcVar15;
  byte local_res18 [8];
  char local_res20 [8];
  
  local_res18[0] = 0;
  lVar9 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_RAX = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x1a,10,
                              &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
  }
  lVar5 = *(longlong *)(param_2 + 0x40);
  if (*(int *)(lVar5 + 0x50) != 1) {
LAB_1c0001ee0:
    return in_RAX & 0xffffffffffffff00;
  }
  bVar6 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
  pcVar15 = (code *)0x1;
  if ((bVar6 & 0x21) != 1) {
    uVar10 = 0;
    if (*(short *)(Globals + 0x4c) != 0) {
      do {
        KeStallExecutionProcessor(1);
        bVar6 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
        if ((bVar6 & 0x21) == 1) break;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(Globals + 0x4c));
    }
    uVar8 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
    bVar6 = (byte)uVar8;
    in_RAX = uVar8 & 0xffffffffffffff21;
    if ((char)in_RAX != '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_RAX = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar9,0x1c,0xb,
                                  &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      if (*(int *)(lVar5 + 0x60) == 0) {
        in_RAX = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd0));
      }
      goto LAB_1c0001ee0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar9,0x1b,0xc,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar10 + '\x01');
    }
  }
  I8xGetByteAsynchronous('\x01',local_res18);
  *(undefined1 *)(lVar5 + 0x24b) = *(undefined1 *)(lVar5 + 0x24a);
  *(byte *)(lVar5 + 0x24a) = local_res18[0];
  pcVar7 = (code *)0x0;
  if (*(code **)(lVar5 + 0x3a0) != (code *)0x0) {
    local_res20[0] = '\0';
    pcVar7 = (code *)(**(code **)(lVar5 + 0x3a0))
                               (*(undefined8 *)(lVar5 + 0x3a8),lVar5 + 0x388,lVar5 + 0x200,bVar6,
                                local_res18,local_res20,lVar5 + 0x394);
    if (local_res20[0] == '\0') {
      return pcVar7;
    }
  }
  pcVar12 = (code *)(ulonglong)local_res18[0];
  if (local_res18[0] == 0xfa) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xfa,0x1b,0xe,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    pcVar7 = Globals;
    if (*(int *)(Globals + 0xcc) == 0) goto LAB_1c0001e28;
    *(undefined4 *)(Globals + 0xcc) = 0xffffffff;
    *(undefined2 *)(lVar5 + 0x230) = 0;
    if (*(int *)(lVar5 + 0x210) != 1) goto LAB_1c0001e28;
    if (*(uint *)(lVar5 + 0x208) < *(uint *)(lVar5 + 0x20c)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1b,0x10,
                          &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,
                          (char)*(uint *)(lVar5 + 0x208));
      }
      pcVar7 = (code *)I8xInitiateIo(param_2,pcVar12);
      goto LAB_1c0001e28;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1b,0x11,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    lVar9 = param_2 + 200;
    uVar13 = 1;
LAB_1c0002117:
    *(undefined4 *)(lVar5 + 0x210) = 0;
    pcVar12 = *(code **)(param_2 + 0x20);
    pcVar7 = (code *)KeInsertQueueDpc(lVar9,pcVar12,uVar13);
    goto LAB_1c0001e28;
  }
  if (local_res18[0] == 0xfe) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xfe,0x1b,0xd,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,
                        (char)*(undefined2 *)(lVar5 + 0x230) + '\x01');
    }
    pcVar7 = Globals;
    if (*(int *)(Globals + 0xcc) == 0) goto LAB_1c0001e28;
    *(undefined4 *)(Globals + 0xcc) = 0xffffffff;
    if ((*(int *)(lVar5 + 0x210) != 0) && (*(longlong *)(param_2 + 0x20) != 0)) {
      sVar2 = *(short *)(lVar5 + 0x230);
      if ((int)sVar2 < (int)(uint)*(ushort *)(Globals + 0x46)) {
        *(int *)(lVar5 + 0x208) = *(int *)(lVar5 + 0x208) + -1;
        pcVar12 = (code *)(ulonglong)CONCAT22(sVar2 >> 0xf,sVar2 + 1);
        *(short *)(lVar5 + 0x230) = sVar2 + 1;
        pcVar7 = (code *)I8xInitiateIo(param_2,pcVar12);
        goto LAB_1c0001e28;
      }
      lVar9 = lVar5 + 0xa8;
      uVar13 = 0;
      goto LAB_1c0002117;
    }
    pcVar12 = (code *)(ulonglong)local_res18[0];
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar7 = (code *)WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1b,0x12,
                                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    pcVar12 = (code *)(ulonglong)local_res18[0];
  }
  piVar1 = (int *)(lVar5 + 0x394);
  bVar6 = (byte)pcVar12;
  if (bVar6 == 0xff) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar7 = (code *)WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1c,0x13
                                        ,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    *(undefined4 *)(lVar5 + 0x38a) = 0xff;
LAB_1c0001e11:
    *piVar1 = 0;
  }
  else {
    iVar4 = *piVar1;
    if (iVar4 == 2) {
LAB_1c0001dc4:
      if ((*(int *)(lVar5 + 0x3b0) != 0) || (pcVar11 = pcVar12, *(int *)(lVar5 + 0x3bc) != 0)) {
        I8xProcessCrashDump(lVar5,bVar6,iVar4);
        pcVar11 = (code *)(ulonglong)local_res18[0];
      }
      if ((byte)pcVar11 < 0x80) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x1b,0x1d,
                           &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          pcVar11 = (code *)(ulonglong)local_res18[0];
        }
        *(short *)(lVar5 + 0x38a) = (short)pcVar11;
        pcVar7 = KdDebuggerEnabled_exref;
        pcVar12 = pcVar11;
        if (*KdDebuggerEnabled_exref != (code)0x0) {
          uVar3 = *(ushort *)(lVar5 + 0x38c);
          pcVar12 = (code *)(ulonglong)uVar3;
          if ((uVar3 & 1) == 0) {
            pcVar7 = (code *)0x0;
            if ((*(byte *)(lVar5 + 0x2b0) < 9) &&
               ((0x194U >> (*(byte *)(lVar5 + 0x2b0) & 0x1f) & 1) != 0)) {
              if (((int)pcVar11 == 0x37) &&
                 ((((uVar3 & 2) != 0 &&
                   (pcVar7 = (code *)KdRefreshDebuggerNotPresent(), (char)pcVar7 == '\0')) &&
                  (DAT_1c0012245 != '\0')))) {
                pcVar7 = (code *)DbgBreakPointWithStatus(2);
              }
            }
            else if ((((int)pcVar11 == 0x54) &&
                     (pcVar7 = (code *)KdRefreshDebuggerNotPresent(), (char)pcVar7 == '\0')) &&
                    (DAT_1c0012245 != '\0')) {
              pcVar7 = (code *)DbgBreakPointWithStatus(2);
            }
          }
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x1b,0x16,
                           &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          pcVar11 = (code *)(ulonglong)local_res18[0];
        }
        pcVar12 = (code *)((ulonglong)pcVar11 & 0xffffffffffffff7f);
        *(short *)(lVar5 + 0x38a) = (short)pcVar12;
        *(ushort *)(lVar5 + 0x38c) = *(ushort *)(lVar5 + 0x38c) | 1;
        pcVar7 = (code *)(ulonglong)*(ushort *)(lVar5 + 0x38c);
        if ((*(ushort *)(lVar5 + 0x38c) & 2) != 0) {
          pcVar7 = pcVar15;
          if ((int)pcVar12 == 0x5e) {
            pcVar12 = (code *)0x0;
            if ((*(byte *)(lVar5 + 0x248) & 1) == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar14 = 0x18;
LAB_1c0002458:
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1a,uVar14,
                                 &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
              }
LAB_1c000246d:
              pcVar7 = (code *)0x2;
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar14 = 0x17;
LAB_1c00023d0:
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1a,uVar14,
                               &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
            }
          }
          else {
            uVar10 = (int)pcVar12 - 0x5f;
            pcVar12 = (code *)(ulonglong)uVar10;
            if (uVar10 == 0) {
              if ((*(byte *)(lVar5 + 0x248) & 2) == 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar14 = 0x1a;
                  goto LAB_1c0002458;
                }
                goto LAB_1c000246d;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar14 = 0x19;
                goto LAB_1c00023d0;
              }
            }
            else if (uVar10 == 4) {
              if ((*(byte *)(lVar5 + 0x248) & 4) == 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar14 = 0x1c;
                  goto LAB_1c0002458;
                }
                goto LAB_1c000246d;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar14 = 0x1b;
                goto LAB_1c00023d0;
              }
            }
            else {
              pcVar7 = (code *)0x0;
            }
          }
          if ((int)pcVar7 != 0) {
            pcVar12 = pcVar7;
            pcVar7 = (code *)KeInsertQueueDpc(lVar5 + 600,pcVar7,*(undefined2 *)(lVar5 + 0x38a));
          }
        }
      }
      goto LAB_1c0001e11;
    }
    if (iVar4 == 0) {
      if (bVar6 == 0xe0) {
        *(ushort *)(lVar5 + 0x38c) = *(ushort *)(lVar5 + 0x38c) | 2;
        *piVar1 = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x14;
LAB_1c0002011:
          pcVar7 = (code *)WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1b,
                                            uVar14,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids)
          ;
        }
      }
      else {
        if (bVar6 != 0xe1) goto LAB_1c0001dc4;
        *(ushort *)(lVar5 + 0x38c) = *(ushort *)(lVar5 + 0x38c) | 4;
        *piVar1 = 2;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x15;
          goto LAB_1c0002011;
        }
      }
    }
    else {
      if (iVar4 == 1) goto LAB_1c0001dc4;
      pcVar12 = (code *)0x0;
      pcVar7 = (code *)KeInsertQueueDpc(lVar5 + 0xe8,0,0xffffffffc005000a);
    }
  }
  if (*piVar1 == 0) {
    pcVar7 = (code *)I8xQueueCurrentKeyboardInput(param_2);
  }
LAB_1c0001e28:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar7 = (code *)WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar12,0x1a,0x1e,
                                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
  }
  return CONCAT71((int7)((ulonglong)pcVar7 >> 8),1);
}



===== I8042MouseInterruptService @ 1c0002580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 I8042MouseInterruptService(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  short sVar2;
  longlong lVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  byte bVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  ushort uVar13;
  undefined4 uVar14;
  byte bVar15;
  uint uVar16;
  longlong lVar17;
  byte *pbVar18;
  undefined7 uVar19;
  uint7 uVar20;
  undefined8 uVar21;
  bool bVar22;
  byte local_res10 [8];
  char local_res18 [16];
  
  local_res10[0] = 0;
  bVar22 = false;
  uVar8 = 1;
  lVar17 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x1d,10,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  lVar3 = *(longlong *)(param_2 + 0x40);
  if (*(int *)(lVar3 + 0x50) != 1) {
    return 0;
  }
  bVar7 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0x36));
  if ((bVar7 & 0x21) != 0x21) {
    KeStallExecutionProcessor(10);
    bVar7 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0x36));
    if ((bVar7 & 0x21) != 0x21) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar17,0x1f,0xb,
                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
      return 0;
    }
  }
  pbVar18 = local_res10;
  I8xGetByteAsynchronous('\x02',pbVar18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0xc,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
  }
  lVar17 = _DAT_fffff78000000320;
  piVar1 = (int *)(lVar3 + 0x3ec);
  if (*piVar1 == 0x44c) {
switchD_1c0002c57_caseD_44d:
    uVar8 = 1;
  }
  else {
    if ((*(int *)(lVar3 + 1000) == 5) && (local_res10[0] == 0xfc)) {
      *(undefined1 *)(lVar3 + 0x450) = 0xfc;
LAB_1c000281d:
      if (*(char *)(lVar3 + 0x452) == '\x01') {
        *(undefined1 *)(lVar3 + 0x452) = 2;
      }
    }
    else {
      if (*(code **)(lVar3 + 0x428) != (code *)0x0) {
        pbVar18 = (byte *)(lVar3 + 0x3d0);
        local_res18[0] = '\0';
        uVar8 = (**(code **)(lVar3 + 0x428))
                          (*(undefined8 *)(lVar3 + 0x430),pbVar18,lVar3 + 0x200,bVar7,local_res10,
                           local_res18,(int *)(lVar3 + 1000),piVar1);
        if (local_res18[0] == '\0') {
          return uVar8;
        }
      }
      if ((*(char *)(lVar3 + 0x450) != -0x56) || ((local_res10[0] != 0 && (local_res10[0] != 3)))) {
        if ((*(int *)(lVar3 + 1000) == 0) &&
           ((*(int *)(lVar3 + 0x210) != 0 && (*(longlong *)(param_2 + 0x20) != 0)))) {
          if (local_res10[0] == 0xfe) {
            if (Globals[0x33] == 0) {
              return 0;
            }
            Globals[0x33] = 0xffffffff;
            sVar2 = *(short *)(lVar3 + 0x230);
            if ((int)(uint)*(ushort *)((longlong)Globals + 0x46) <= (int)sVar2) {
              *(undefined4 *)(lVar3 + 0x210) = 0;
              KeInsertQueueDpc(lVar3 + 0xa8,*(undefined8 *)(param_2 + 0x20),0);
              return 1;
            }
            *(int *)(lVar3 + 0x208) = *(int *)(lVar3 + 0x208) + -1;
            pbVar18 = (byte *)(ulonglong)CONCAT22(sVar2 >> 0xf,sVar2 + 1);
            *(short *)(lVar3 + 0x230) = sVar2 + 1;
            I8xInitiateIo(param_2,pbVar18);
          }
          else if (local_res10[0] == 0xfa) {
            if (Globals[0x33] == 0) {
              return 0;
            }
            Globals[0x33] = 0xffffffff;
            *(undefined2 *)(lVar3 + 0x230) = 0;
            if (*(uint *)(lVar3 + 0x208) < *(uint *)(lVar3 + 0x20c)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0xf,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,
                                  (char)*(uint *)(lVar3 + 0x208));
              }
              I8xInitiateIo(param_2,pbVar18);
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x10,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
              }
              *(undefined4 *)(lVar3 + 0x210) = 0;
              KeInsertQueueDpc(param_2 + 200,*(undefined8 *)(param_2 + 0x20),2);
            }
            goto switchD_1c0002c57_caseD_44d;
          }
        }
        *(byte *)(lVar3 + 0x450) = local_res10[0];
        lVar11 = lVar17 - *(longlong *)(lVar3 + 0x3f8);
        uVar9 = *(uint *)(lVar3 + 1000);
        if ((((uVar9 & 0xfffffffa) != 0) || (uVar9 == 1)) &&
           ((*(uint *)(lVar3 + 0x400) <= (uint)lVar11 || ((int)((ulonglong)lVar11 >> 0x20) != 0))))
        {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x11,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar9);
          }
          goto LAB_1c000281d;
        }
        *(longlong *)(lVar3 + 0x3f8) = lVar17;
        if (uVar9 == 2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x14,
                             &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
          }
          bVar7 = *(byte *)(lVar3 + 0x3f6);
          if ((char)bVar7 < '\0') {
            pbVar18 = (byte *)(ulonglong)bVar7;
            if (((char)*(byte *)(lVar3 + 0x3f7) < '\0') &&
               (((bVar7 ^ *(byte *)(lVar3 + 0x3f7)) & 0x20) != 0)) {
              pbVar18 = (byte *)(ulonglong)(bVar7 ^ 0x20);
              *(byte *)(lVar3 + 0x3f6) = bVar7 ^ 0x20;
            }
            iVar10 = 0xff;
            if (((ulonglong)pbVar18 & 0x20) == 0) {
              iVar10 = -0x100;
            }
          }
          else {
            uVar9 = (uint)local_res10[0];
            *(uint *)(lVar3 + 0x3e0) = (uint)local_res10[0];
            if ((bVar7 & 0x20) != 0) {
              uVar9 = local_res10[0] | 0xffffff00;
              *(uint *)(lVar3 + 0x3e0) = uVar9;
            }
            iVar10 = -uVar9;
          }
          *(int *)(lVar3 + 0x3e0) = iVar10;
          *(undefined1 *)(lVar3 + 0x3f7) = *(undefined1 *)(lVar3 + 0x3f6);
          if ((*Globals & 8) != 0) {
            *(undefined4 *)(lVar3 + 1000) = 3;
            goto LAB_1c000273a;
          }
LAB_1c000310f:
          I8xQueueCurrentMouseInput(param_2);
          *(undefined4 *)(lVar3 + 1000) = 0;
          goto LAB_1c000273a;
        }
        if (uVar9 == 5) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x18,
                               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,5,
                               (char)*(undefined4 *)(lVar3 + 0x3ec));
          }
          bVar7 = 0;
LAB_1c000287e:
          uVar9 = *(uint *)(lVar3 + 0x3ec);
          pbVar18 = (byte *)(longlong)(int)uVar9;
          bVar22 = true;
          if (uVar9 != 4) {
            if (uVar9 == 10) {
switchD_1c00032a5_caseD_8:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1f,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                if (*(int *)(lVar3 + 0x3ec) == 10) {
                  bVar15 = 0xe9;
                  iVar10 = 0xb;
                }
                else {
                  bVar15 = 0xe6;
                  iVar10 = *(int *)(lVar3 + 0x3ec) + 1;
                }
                *(int *)(lVar3 + 0x3ec) = iVar10;
                uVar12 = (ulonglong)uVar20 << 8;
                goto LAB_1c0002741;
              }
              if (local_res10[0] == 0xfe) {
                uVar12 = CONCAT71(uVar20,0xe6);
                goto LAB_1c000273e;
              }
LAB_1c0002b70:
              uVar21 = 0xffffffffc0050022;
LAB_1c0002b77:
              pbVar18 = (byte *)0x0;
              KeInsertQueueDpc(lVar3 + 0xe8,0,uVar21);
switchD_1c0002c57_caseD_3eb:
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x1b;
              bVar7 = 0xf2;
              goto LAB_1c000273c;
            }
            if (uVar9 == 0xd) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xd,0x1d,0x22,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0,local_res10[0]
                                  );
              }
              *(undefined4 *)(lVar3 + 0x3ec) = 0xe;
              bVar22 = false;
              if ((byte)(local_res10[0] - 2) < 2) {
                uVar13 = (ushort)local_res10[0];
              }
              else {
                uVar13 = 2;
              }
              *(ushort *)(lVar3 + 0x24a) = uVar13;
              goto LAB_1c000273c;
            }
            if (uVar9 == 0x10) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x10,0x1e,0x26,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                uVar12 = (ulonglong)uVar20 << 8;
                bVar15 = *(byte *)((ulonglong)*(byte *)(lVar3 + 0x44c) +
                                  *(longlong *)(lVar3 + 0x440));
                *(undefined4 *)(lVar3 + 0x3ec) = 0x11;
                goto LAB_1c0002741;
              }
              if (local_res10[0] != 0xfe) {
LAB_1c000354c:
                uVar21 = 0xffffffffc0050016;
                goto LAB_1c0002b77;
              }
              uVar12 = CONCAT71(uVar20,0xf3);
              goto LAB_1c000273e;
            }
            if (0x3ea < (int)uVar9) {
              switch(uVar9) {
              case 0x3eb:
              case 0x4bb:
                goto switchD_1c0002c57_caseD_3eb;
              case 0x3ec:
                bVar22 = false;
                *(undefined4 *)(lVar3 + 0x3ec) = 0x22;
                bVar7 = 0xf2;
                break;
              default:
                goto switchD_1c0002c57_caseD_3ed;
              case 0x44d:
                goto switchD_1c0002c57_caseD_44d;
              case 0x4b0:
              case 0x4b1:
              case 0x4b2:
              case 0x4b3:
              case 0x4b4:
              case 0x4b5:
              case 0x4b6:
              case 0x4b7:
              case 0x4b8:
              case 0x4b9:
              case 0x4ba:
                bVar22 = false;
                *(uint *)(lVar3 + 0x3ec) = uVar9 + 1;
              }
              goto LAB_1c000273c;
            }
            if (uVar9 == 0x3ea) {
              DAT_1c0012148 = (ushort *)(lVar3 + 0x418);
              *(undefined4 *)(lVar3 + 0x3ec) = 0x12;
              puVar4 = DAT_1c0012148 + 1;
              puVar5 = DAT_1c0012148 + 2;
              puVar6 = DAT_1c0012148 + 3;
              DAT_1c0012148[0] = 0;
              *puVar4 = 0;
              *puVar5 = 0;
              *puVar6 = 0;
              *(undefined8 *)(lVar3 + 0x420) = 0;
              bVar22 = false;
              goto LAB_1c000273c;
            }
            if (0x23 < uVar9) {
switchD_1c0002c57_caseD_3ed:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1f,0x32,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar9);
              }
              pbVar18 = (byte *)0x0;
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050032);
              goto LAB_1c000273c;
            }
            uVar20 = (uint7)(int3)(uVar9 >> 8);
            switch(uVar9) {
            case 0:
              if (local_res10[0] == 0xfa) {
                bVar22 = false;
                goto LAB_1c000273c;
              }
              if (local_res10[0] == 0xfe) {
                sVar2 = *(short *)(lVar3 + 0x230);
                bVar22 = false;
                *(short *)(lVar3 + 0x230) = sVar2 + 1;
                if ((sVar2 < 10) && (*(int *)(lVar3 + 0x3a0) == 0)) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1a,
                                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
                  }
                  KeStallExecutionProcessor(*(undefined4 *)(lVar3 + 0x448));
                  bVar7 = 0xff;
                }
                goto LAB_1c000273c;
              }
              if (local_res10[0] != 0xaa) goto LAB_1c000273c;
              if (2 < *(byte *)(lVar3 + 0x3f4)) goto LAB_1c000281d;
              *(undefined4 *)(lVar3 + 0x3ec) = 1;
              goto LAB_1c000273c;
            case 1:
              uVar12 = (ulonglong)uVar20 << 8;
              *(undefined4 *)(lVar3 + 0x3ec) = 2;
              if (local_res10[0] == 3) {
                bVar22 = false;
                bVar7 = 0xf2;
              }
              else {
                *(undefined4 *)(lVar3 + 0x3ec) = 0;
              }
              goto LAB_1c000273e;
            case 2:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1b,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                *(undefined4 *)(lVar3 + 0x3ec) = 3;
                bVar22 = false;
                goto LAB_1c000273c;
              }
              if (local_res10[0] != 0xfe) goto LAB_1c000281d;
              uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xf2);
              goto LAB_1c000273e;
            case 3:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1c,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
              }
              bVar22 = false;
              bVar7 = 0xe8;
              uVar14 = 4;
              if (*(char *)(lVar3 + 0x453) == '\0') {
                uVar14 = 6;
              }
              *(undefined4 *)(lVar3 + 0x3ec) = uVar14;
              goto LAB_1c000273c;
            case 4:
            case 10:
            case 0xd:
            case 0x10:
              goto switchD_1c0002c57_caseD_3ed;
            case 5:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x25,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                if (*(char *)(lVar3 + 0x452) == '\x02') {
                  *(undefined4 *)(lVar3 + 0x3ec) = 0x19;
                  goto LAB_1c000287e;
                }
                if (*(char *)(lVar3 + 0x452) == '\x01') {
                  *(undefined4 *)(lVar3 + 0x3ec) = 0xf;
                  goto LAB_1c000287e;
                }
                bVar15 = 0xf2;
                uVar14 = 0x1b;
                uVar12 = (ulonglong)uVar20 << 8;
              }
              else {
                if (local_res10[0] != 0xfe) goto LAB_1c0002c5d;
                uVar12 = CONCAT71(uVar20,0xe8);
                uVar14 = 4;
                bVar15 = 0;
              }
              *(undefined4 *)(lVar3 + 0x3ec) = uVar14;
              goto LAB_1c0002741;
            case 6:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1d,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                *(undefined4 *)(lVar3 + 0x3ec) = 7;
                goto LAB_1c000273c;
              }
              if (local_res10[0] != 0xfe) {
                uVar21 = 0xffffffffc0050017;
                goto LAB_1c0002b77;
              }
              uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xe8);
              goto LAB_1c000273e;
            case 7:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x1e,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                bVar15 = 0xe6;
                *(undefined4 *)(lVar3 + 0x3ec) = 8;
              }
              else {
                bVar22 = local_res10[0] == 0xfe;
                if (!bVar22) {
                  pbVar18 = (byte *)0x0;
                  KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050016);
                  *(undefined4 *)(lVar3 + 0x3ec) = 0x1b;
                  bVar7 = 0xf2;
                }
                bVar15 = 0;
              }
              uVar12 = (ulonglong)pbVar18 & 0xffffffffffffff00;
              goto LAB_1c0002741;
            case 8:
            case 9:
              goto switchD_1c00032a5_caseD_8;
            case 0xb:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x20,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                *(undefined4 *)(lVar3 + 0x3ec) = 0xc;
                bVar22 = false;
                goto LAB_1c000273c;
              }
              if (local_res10[0] != 0xfe) goto LAB_1c0002b70;
              uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xe9);
              goto LAB_1c000273e;
            case 0xc:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1d,0x21,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0,local_res10[0]
                                  );
              }
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 0xd;
              goto LAB_1c000273c;
            case 0xe:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1d,0x23,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0,local_res10[0]
                                  );
              }
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 4;
              bVar7 = 0xe8;
              goto LAB_1c000273c;
            case 0xf:
              *(undefined4 *)(lVar3 + 0x3ec) = 0x10;
              *(undefined **)(lVar3 + 0x440) = &DAT_1c000f9a8;
              bVar15 = 0xf3;
              *(undefined1 *)(lVar3 + 0x44c) = 0;
              uVar12 = (ulonglong)uVar20 << 8;
              *(undefined2 *)(lVar3 + 0x44e) = 0x3ea;
              goto LAB_1c0002741;
            case 0x11:
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x27,
                                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                     local_res10[0]),
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                bVar15 = *(byte *)((ulonglong)*(byte *)(lVar3 + 0x44c) +
                                  *(longlong *)(lVar3 + 0x440));
                pbVar18 = (byte *)(ulonglong)bVar15;
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x28,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,bVar15);
              }
              if (local_res10[0] != 0xfa) {
                if (local_res10[0] != 0xfe) goto LAB_1c000354c;
                uVar12 = (ulonglong)
                         *(byte *)((ulonglong)*(byte *)(lVar3 + 0x44c) +
                                  *(longlong *)(lVar3 + 0x440));
                goto LAB_1c000273e;
              }
              *(char *)(lVar3 + 0x44c) = *(char *)(lVar3 + 0x44c) + '\x01';
              if (*(char *)((ulonglong)*(byte *)(lVar3 + 0x44c) + *(longlong *)(lVar3 + 0x440)) !=
                  '\0') {
                bVar15 = 0xf3;
                *(undefined4 *)(lVar3 + 0x3ec) = 0x10;
                uVar12 = (ulonglong)pbVar18 & 0xffffffffffffff00;
                goto LAB_1c0002741;
              }
              *(uint *)(lVar3 + 0x3ec) = (uint)*(ushort *)(lVar3 + 0x44e);
              goto LAB_1c000287e;
            case 0x13:
              if ((*(short *)(lVar3 + 0x418) == 0x50) && (local_res10[0] == 0x99)) {
                *(undefined4 *)(lVar3 + 0x3ec) = 0x4b0;
                bVar22 = false;
                goto LAB_1c000273c;
              }
              break;
            case 0x19:
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x10;
              *(undefined1 *)(lVar3 + 0x44c) = 0;
              *(undefined **)(lVar3 + 0x440) = &DAT_1c000f968;
              bVar7 = 0xf3;
              *(undefined2 *)(lVar3 + 0x44e) = 0x3ec;
              goto LAB_1c000273c;
            case 0x1a:
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x10;
              *(undefined1 *)(lVar3 + 0x44c) = 0;
              *(undefined **)(lVar3 + 0x440) = &DAT_1c000f964;
              bVar7 = 0xf3;
              *(undefined2 *)(lVar3 + 0x44e) = 0x3eb;
              goto LAB_1c000273c;
            case 0x1b:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x2a,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] != 0xfa) goto LAB_1c0003627;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x1c;
              bVar22 = false;
              goto LAB_1c000273c;
            case 0x1c:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1d,0x2b,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
              }
              *Globals = *Globals & 0xffffeff7;
              uVar9 = *Globals;
              *Globals = uVar9 | 2;
              if (local_res10[0] == 0) {
                *(undefined2 *)(lVar3 + 0x248) = 2;
                pbVar18 = (byte *)0x0;
                if (*(byte *)(lVar3 + 0x453) != 0) {
                  *(ushort *)(lVar3 + 0x24a) = (ushort)*(byte *)(lVar3 + 0x453);
                }
              }
              else {
                uVar16 = local_res10[0] - 3;
                pbVar18 = (byte *)(ulonglong)uVar16;
                if (uVar16 == 0) {
                  *Globals = uVar9 | 10;
                  *(undefined4 *)(lVar3 + 0x248) = 0x30020;
                }
                else {
                  if (uVar16 != 1) {
                    uVar21 = 0;
                    KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffff80050012);
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar21,0x1e,0x2c,
                                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
                    }
                    *Globals = *Globals & 0xfffffdf5;
                    *(undefined4 *)(lVar3 + 0x248) = 0;
                    goto LAB_1c000281d;
                  }
                  *Globals = uVar9 | 0x100a;
                  *(undefined4 *)(lVar3 + 0x248) = 0x50020;
                }
              }
              bVar22 = false;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x1d;
              bVar7 = 0xf3;
              goto LAB_1c000273c;
            case 0x1d:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x2d,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                bVar15 = *(byte *)(lVar3 + 0x24c);
                uVar12 = (ulonglong)uVar20 << 8;
                *(undefined4 *)(lVar3 + 0x3ec) = 0x1e;
                goto LAB_1c0002741;
              }
              if (local_res10[0] == 0xfe) {
                uVar12 = CONCAT71(uVar20,0xf3);
                goto LAB_1c000273e;
              }
LAB_1c0003c0b:
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050016);
              goto LAB_1c000281d;
            case 0x1e:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x2e,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                bVar15 = 0xe8;
                uVar14 = 0x20;
                uVar12 = (ulonglong)uVar20 << 8;
              }
              else {
                if (local_res10[0] != 0xfe) goto LAB_1c0003c0b;
                uVar12 = CONCAT71(uVar20,0xf3);
                uVar14 = 0x1d;
                bVar15 = 0;
              }
              *(undefined4 *)(lVar3 + 0x3ec) = uVar14;
              goto LAB_1c0002741;
            case 0x1f:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x31,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                *(ushort *)(lVar3 + 0x3d2) = *(ushort *)(lVar3 + 0x3d2) | 4;
                *(undefined4 *)(lVar3 + 1000) = 0;
                *(undefined2 *)(lVar3 + 0x3f4) = 0xffff;
                *(undefined2 *)(lVar3 + 0x230) = 0;
                I8xQueueCurrentMouseInput(param_2);
                pbVar18 = *(byte **)(lVar3 + 600);
                KeInsertQueueDpc(param_2 + 200,pbVar18,3);
                goto LAB_1c000273c;
              }
              if (local_res10[0] == 0xfe) {
                uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xf4);
                goto LAB_1c000273e;
              }
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050029);
              goto LAB_1c000281d;
            case 0x20:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x2f,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] != 0xfa) goto LAB_1c0002a7a;
              bVar15 = *(byte *)(lVar3 + 0x451);
              uVar12 = (ulonglong)pbVar18 & 0xffffffffffffff00;
              *(undefined4 *)(lVar3 + 0x3ec) = 0x21;
              goto LAB_1c0002741;
            case 0x21:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x30,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              uVar20 = (uint7)((ulonglong)pbVar18 >> 8);
              if (local_res10[0] == 0xfa) {
                bVar15 = 0xf4;
                uVar14 = 0x1f;
                uVar12 = (ulonglong)uVar20 << 8;
              }
              else {
                if (local_res10[0] != 0xfe) goto LAB_1c0002c5d;
                uVar12 = CONCAT71(uVar20,0xe8);
                uVar14 = 0x20;
                bVar15 = 0;
              }
              *(undefined4 *)(lVar3 + 0x3ec) = uVar14;
              goto LAB_1c0002741;
            case 0x22:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x19,
                                   &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                   local_res10[0]);
              }
              if (local_res10[0] == 0xfa) {
                bVar22 = false;
                *(undefined4 *)(lVar3 + 0x3ec) = 0x23;
                goto LAB_1c000273c;
              }
LAB_1c0003627:
              if (local_res10[0] == 0xfe) {
                uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xf2);
                goto LAB_1c000273e;
              }
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050028);
              goto LAB_1c000281d;
            case 0x23:
              goto switchD_1c00032a5_caseD_23;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1d,0x29,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,
                                 (char)*(undefined4 *)(lVar3 + 0x3ec) + -0x11,local_res10[0]);
            }
            if (local_res10[0] < 0x36) {
              *DAT_1c0012148 = (ushort)(byte)(&DAT_1c000f970)[local_res10[0]];
            }
            else {
              *DAT_1c0012148 = 0x3f;
            }
            DAT_1c0012148 = DAT_1c0012148 + 1;
            bVar22 = false;
            if (*(int *)(lVar3 + 0x3ec) == 0x18) {
              pbVar18 = (byte *)(lVar3 + 0x418);
              uVar12 = I8xVerifyMousePnPID(lVar3,(longlong)pbVar18);
              if ((char)uVar12 != '\0') {
                *(undefined4 *)(lVar3 + 0x3ec) = 0x19;
                goto LAB_1c000287e;
              }
              bVar7 = 0xf2;
              iVar10 = 0x1b;
            }
            else {
              iVar10 = *(int *)(lVar3 + 0x3ec) + 1;
            }
            *(int *)(lVar3 + 0x3ec) = iVar10;
            goto LAB_1c000273c;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0x1e,0x24,
                               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,local_res10[0])
            ;
          }
          if (local_res10[0] != 0xfa) {
LAB_1c0002a7a:
            if (local_res10[0] != 0xfe) {
LAB_1c0002c5d:
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050017);
              goto LAB_1c000281d;
            }
            uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xe8);
            goto LAB_1c000273e;
          }
          bVar15 = *(byte *)(lVar3 + 0x451);
          uVar12 = (ulonglong)pbVar18 & 0xffffffffffffff00;
          *(undefined4 *)(lVar3 + 0x3ec) = 5;
        }
        else {
          if (uVar9 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x1e,0x12,
                               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
            }
            if (((*Globals & 8) != 0) && ((local_res10[0] & 200) != 8)) goto LAB_1c000281d;
            bVar7 = *(byte *)(lVar3 + 0x44d);
            *(undefined4 *)(lVar3 + 0x3d4) = 0;
            *(undefined2 *)(lVar3 + 0x3d2) = 0;
            if (((bVar7 & 1) == 0) && ((local_res10[0] & 1) != 0)) {
              *(undefined2 *)(lVar3 + 0x3d4) = 1;
              uVar13 = 1;
            }
            else {
              uVar13 = 0;
              if (((bVar7 & 1) != 0) && ((local_res10[0] & 1) == 0)) {
                *(undefined2 *)(lVar3 + 0x3d4) = 2;
                uVar13 = 2;
              }
            }
            if (((bVar7 & 2) == 0) && ((local_res10[0] & 2) != 0)) {
              uVar13 = uVar13 | 4;
              *(ushort *)(lVar3 + 0x3d4) = uVar13;
            }
            else if (((bVar7 & 2) != 0) && ((local_res10[0] & 2) == 0)) {
              uVar13 = uVar13 | 8;
              *(ushort *)(lVar3 + 0x3d4) = uVar13;
            }
            pbVar18 = (byte *)0x0;
            if ((bVar7 & 4) == 0) {
              if ((local_res10[0] & 4) != 0) {
                uVar13 = uVar13 | 0x10;
                goto LAB_1c0002b1a;
              }
            }
            else if ((local_res10[0] & 4) == 0) {
              uVar13 = uVar13 | 0x20;
LAB_1c0002b1a:
              *(ushort *)(lVar3 + 0x3d4) = uVar13;
            }
            *(byte *)(lVar3 + 0x44d) = bVar7 & 0x30 | local_res10[0] & 7;
            *(undefined4 *)(lVar3 + 1000) = 1;
            *(byte *)(lVar3 + 0x3f6) = local_res10[0] & 0xf0;
LAB_1c000273a:
            bVar7 = 0;
          }
          else {
            pbVar18 = (byte *)(ulonglong)(uVar9 - 1);
            if (uVar9 - 1 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x1e,0x13,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
              }
              bVar7 = *(byte *)(lVar3 + 0x3f6);
              if ((bVar7 & 0x40) == 0) {
                *(uint *)(lVar3 + 0x3dc) = (uint)local_res10[0];
                if ((bVar7 & 0x10) != 0) {
                  *(uint *)(lVar3 + 0x3dc) = local_res10[0] | 0xffffff00;
                }
              }
              else {
                pbVar18 = (byte *)(ulonglong)bVar7;
                if (((*(byte *)(lVar3 + 0x3f7) & 0x40) != 0) &&
                   (((bVar7 ^ *(byte *)(lVar3 + 0x3f7)) & 0x10) != 0)) {
                  pbVar18 = (byte *)(ulonglong)(bVar7 ^ 0x10);
                  *(byte *)(lVar3 + 0x3f6) = bVar7 ^ 0x10;
                }
                uVar14 = 0xffffff00;
                if (((ulonglong)pbVar18 & 0x10) == 0) {
                  uVar14 = 0xff;
                }
                *(undefined4 *)(lVar3 + 0x3dc) = uVar14;
              }
              *(undefined4 *)(lVar3 + 1000) = 2;
              goto LAB_1c000273a;
            }
            uVar16 = uVar9 - 3;
            pbVar18 = (byte *)(ulonglong)uVar16;
            if (uVar16 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x1e,0x15,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
              }
              if ((*Globals & 0x1000) == 0) {
                if (local_res10[0] != 0) {
                  *(ushort *)(lVar3 + 0x3d4) = *(ushort *)(lVar3 + 0x3d4) | 0x400;
                  *(short *)(lVar3 + 0x3d6) = (char)local_res10[0] * -0x78;
                }
                goto LAB_1c000310f;
              }
              if ((local_res10[0] & 0xf) != 0) {
                if ((local_res10[0] & 8) == 0) {
                  uVar13 = (ushort)(local_res10[0] & 0xf);
                }
                else {
                  uVar13 = (ushort)(char)(local_res10[0] | 0xf0);
                }
                *(ushort *)(lVar3 + 0x3d6) = uVar13 * -0x78;
                *(ushort *)(lVar3 + 0x3d4) = *(ushort *)(lVar3 + 0x3d4) | 0x400;
              }
              bVar7 = *(byte *)(lVar3 + 0x44d);
              if ((bVar7 & 0x10) == 0 && (local_res10[0] & 0x10) != 0) {
                *(ushort *)(lVar3 + 0x3d4) = *(ushort *)(lVar3 + 0x3d4) | 0x40;
              }
              else if ((bVar7 & 0x10) != 0 && (local_res10[0] & 0x10) == 0) {
                *(ushort *)(lVar3 + 0x3d4) = *(ushort *)(lVar3 + 0x3d4) | 0x80;
              }
              if ((bVar7 & 0x20) == 0 && (local_res10[0] & 0x20) != 0) {
                uVar13 = 0x100;
LAB_1c00030f4:
                *(ushort *)(lVar3 + 0x3d4) = *(ushort *)(lVar3 + 0x3d4) | uVar13;
              }
              else if ((bVar7 & 0x20) != 0 && (local_res10[0] & 0x20) == 0) {
                uVar13 = 0x200;
                goto LAB_1c00030f4;
              }
              pbVar18 = (byte *)0x0;
              *(byte *)(lVar3 + 0x44d) = local_res10[0] & 0x30 | bVar7 & 7;
              goto LAB_1c000310f;
            }
            if (uVar16 != 1) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1f,0x33,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar9);
              }
              pbVar18 = (byte *)0x0;
              KeInsertQueueDpc(lVar3 + 0xe8,0,0xffffffffc0050032);
              goto LAB_1c000273a;
            }
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,0x1e,0x16,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids),
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0x17,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0xfa,
                                 local_res10[0]);
            }
            bVar7 = 0;
            if (local_res10[0] == 0xfa) {
              *(undefined4 *)(lVar3 + 1000) = 0;
              *(undefined1 *)(lVar3 + 0x3a3) = 0;
            }
            else if (local_res10[0] == 0xfe) {
              uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xf4);
              goto LAB_1c000273e;
            }
          }
LAB_1c000273c:
          uVar12 = (ulonglong)pbVar18 & 0xffffffffffffff00;
LAB_1c000273e:
          bVar15 = 0;
        }
LAB_1c0002741:
        if (*(int *)(lVar3 + 1000) == 5) {
          uVar19 = (undefined7)(uVar12 >> 8);
          if (bVar22) {
            if (local_res10[0] == 0xfa) {
LAB_1c0002c0d:
              I8xPutByteAsynchronous('\x01',CONCAT71(uVar19,0xd4));
              goto LAB_1c0002c1a;
            }
            if (local_res10[0] == 0xfe) {
              sVar2 = *(short *)(lVar3 + 0x230);
              *(short *)(lVar3 + 0x230) = sVar2 + 1;
              if (3 < sVar2) {
                *(undefined2 *)(lVar3 + 0x230) = 0;
                goto LAB_1c000281d;
              }
              bVar15 = (byte)uVar12;
              goto LAB_1c0002c0d;
            }
          }
          else {
            if (bVar7 != 0) {
              I8xPutByteAsynchronous('\x01',CONCAT71(uVar19,0xd4));
              bVar15 = bVar7;
LAB_1c0002c1a:
              uVar12 = (ulonglong)bVar15;
              I8xPutByteAsynchronous('\0',uVar12);
            }
            if (local_res10[0] == 0xfe) goto LAB_1c000274e;
          }
          *(undefined2 *)(lVar3 + 0x230) = 0;
        }
LAB_1c000274e:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar12,0x1d,0x34,
                           &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
        }
        goto switchD_1c0002c57_caseD_44d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0xd,
                          &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
      }
      LOCK();
      bVar22 = *(longlong *)(lVar3 + 600) == 0;
      if (bVar22) {
        *(longlong *)(lVar3 + 600) = 0;
      }
      UNLOCK();
      if (!bVar22) {
        uVar12 = CONCAT71((int7)((ulonglong)pbVar18 >> 8),0xd4);
        I8xPutByteAsynchronous('\x01',uVar12);
        I8xPutByteAsynchronous('\0',CONCAT71((int7)(uVar12 >> 8),0xf2));
        *(undefined4 *)(lVar3 + 1000) = 5;
        *piVar1 = 2;
        *(byte *)(lVar3 + 0x450) = local_res10[0];
        *(undefined2 *)(lVar3 + 0x230) = 0;
        goto switchD_1c0002c57_caseD_44d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar18,0x1e,0xe,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
      }
    }
    *(undefined4 *)(lVar3 + 0x3ec) = 0x44c;
    KeInsertQueueDpc(lVar3 + 0x2e0,0,0);
  }
  return uVar8;
switchD_1c00032a5_caseD_23:
  *(undefined4 *)(lVar3 + 0x3ec) = 0x1a;
  goto LAB_1c000287e;
}



===== I8xGetByteAsynchronous @ 1c00040b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xGetByteAsynchronous(char param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  byte bVar6;
  undefined2 uVar7;
  
  puVar4 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0xf,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    if (param_1 == '\x01') {
      pcVar3 = "keyboard";
    }
    else {
      pcVar3 = "mouse";
      if (param_1 != '\x02') {
        pcVar3 = "8042 controller";
      }
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x14,0x10,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar3);
  }
  uVar5 = 0;
  bVar6 = 0x21;
  if (param_1 != '\x02') {
    bVar6 = 1;
  }
  if (*(short *)(Globals + 0x48) != 0) {
    do {
      bVar1 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
      if ((bVar6 & bVar1) == bVar6) break;
      if ((bVar1 & 1) == 0) {
        uVar5 = uVar5 + 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x12,0x12,
                           &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
        }
      }
      else {
        uVar2 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd0));
        *param_2 = uVar2;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x14,0x11,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,uVar2);
        }
      }
    } while (uVar5 < *(ushort *)(Globals + 0x48));
  }
  if (uVar5 < *(ushort *)(Globals + 0x48)) {
    uVar2 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd0));
    *param_2 = uVar2;
    if (param_1 == '\x02') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x13,0x14,
                        &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,uVar2);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar7 = 0x15;
    uVar5 = 0x13;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar7 = 0x13;
    uVar5 = 0x15;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,uVar5,uVar7,
                   &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  return;
}



===== WPP_RECORDER_SF_s @ 1c0004310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,char *param_6)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (param_6[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar1,lVar2,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
    param_6 = "NULL";
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_6[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_ @ 1c0004460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,0);
  return;
}



===== I8xDpcVariableOperation @ 1c0004520 =====

undefined8 I8xDpcVariableOperation(undefined8 *param_1,char *param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x4b,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    iVar1 = *(int *)(param_1 + 1);
    if (iVar1 == 0) {
      param_2 = "increment";
    }
    else if (iVar1 == 1) {
      param_2 = "decrement";
    }
    else if (iVar1 == 2) {
      param_2 = "write";
    }
    else {
      param_2 = "read";
      if (iVar1 != 3) {
        param_2 = "";
      }
    }
    WPP_RECORDER_SF_sqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  iVar1 = *(int *)(param_1 + 1);
  if (iVar1 == 0) {
    *(int *)*param_1 = *(int *)*param_1 + 1;
  }
  else if (iVar1 == 1) {
    *(int *)*param_1 = *(int *)*param_1 + -1;
  }
  else if (iVar1 == 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,8,0x4d,
                        &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                        (char)*(undefined4 *)param_1[2]);
    }
    *(undefined4 *)*param_1 = *(undefined4 *)param_1[2];
  }
  uVar2 = (ulonglong)*(uint *)*param_1;
  *(uint *)param_1[2] = *(uint *)*param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar2 = WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x4e,
                              &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                              (char)*(undefined4 *)param_1[2]);
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== WPP_RECORDER_SF_sqD @ 1c00046a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000030 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (in_stack_00000030[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x4c,pcVar1,lVar2,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x4c,
                  in_stack_00000030,lVar3,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== I8xTransmitControllerCommand @ 1c0004830 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void I8xTransmitControllerCommand
               (uint *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  longlong lVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined2 *puVar7;
  undefined8 *puVar8;
  byte *pbVar9;
  byte bVar10;
  byte local_res8 [8];
  byte local_res10 [8];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0x59;
    param_3 = 0x13;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0x59,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  pbVar9 = local_res8;
  uVar6 = I8xGetControllerCommand(*param_1,pbVar9);
  param_1[2] = (uint)uVar6;
  if (-1 < (int)(uint)uVar6) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0x5a;
      param_3 = 0x14;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar9,0x14,0x5a,
                        &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,local_res8[0]);
    }
    lVar1 = _DAT_fffff78000000320;
    if ((char)param_1[1] == '\0') {
      bVar10 = *(byte *)((longlong)param_1 + 5) | local_res8[0];
    }
    else {
      bVar10 = *(byte *)((longlong)param_1 + 5) & local_res8[0];
    }
    iVar4 = KeQueryTimeIncrement();
    do {
      uVar5 = I8xPutControllerCommand(bVar10,pbVar9);
      param_1[2] = uVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 0x5b;
        param_3 = 0x14;
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar9,0x14,0x5b,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,bVar10);
      }
      pbVar9 = local_res10;
      uVar6 = I8xGetControllerCommand(*param_1,pbVar9);
      param_1[2] = (uint)uVar6;
    } while ((local_res10[0] == 0xff) &&
            (KeStallExecutionProcessor(0x32),
            _DAT_fffff78000000320 < (longlong)((ulonglong)(uint)(iVar4 * 20000000) + lVar1)));
    bVar2 = local_res10[0];
    if ((-1 < (int)param_1[2]) && ((local_res10[0] != bVar10 && (local_res10[0] != 0xfa)))) {
      param_1[2] = 0xc000009c;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 0x5c;
        param_3 = 0x15;
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar9,0x15,0x5c,
                           &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,bVar10,local_res10[0]);
      }
      bVar3 = KeGetCurrentIrql();
      if (bVar3 < 3) {
        puVar8 = DAT_1c00121c8;
        if (DAT_1c00121d0 != (undefined8 *)0x0) {
          puVar8 = DAT_1c00121d0;
        }
        puVar7 = (undefined2 *)IoAllocateErrorLogEntry(*puVar8,0x40);
        if (puVar7 != (undefined2 *)0x0) {
          uVar5 = param_1[2];
          param_3 = (ulonglong)uVar5;
          *(undefined4 *)(puVar7 + 6) = 0x4005001c;
          puVar7[1] = 0x10;
          *(undefined8 *)(puVar7 + 0xc) = 0;
          *puVar7 = 0;
          *(uint *)(puVar7 + 0x1a) = (uint)bVar10;
          *(undefined4 *)(puVar7 + 8) = 0x50;
          *(uint *)(puVar7 + 10) = uVar5;
          *(undefined8 *)(puVar7 + 0x14) = 1;
          *(undefined4 *)(puVar7 + 0x18) = 0x60;
          IoWriteErrorLogEntry();
        }
      }
      pbVar9 = (byte *)(ulonglong)bVar2;
      TraceLoggingTransmitControllerCommandFailed(bVar10,bVar2,param_3,param_4);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar9,0x13,0x5d,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
  }
  return;
}



===== I8xPutControllerCommand @ 1c0004b00 =====

void I8xPutControllerCommand(byte param_1,undefined8 param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0x47,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  uVar2 = 0;
  uVar1 = I8xPutBytePolled('\x01','\0','\x03',0x60);
  if (-1 < (int)uVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0x13,0x48,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
    I8xPutBytePolled('\0','\0','\x03',param_1);
  }
  return;
}



===== I8xGetControllerCommand @ 1c0004bb0 =====

ulonglong I8xGetControllerCommand(uint param_1,byte *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  byte *pbVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0x1c,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  uVar4 = param_1 & 1;
  if ((uVar4 != 0) && (uVar1 = I8xPutBytePolled('\x01','\0','\x03',0xad), (int)uVar1 < 0)) {
    return uVar1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = I8xPutBytePolled('\x01','\0','\x03',0xa7);
    if ((int)uVar1 < 0) {
      if (uVar4 == 0) {
        return uVar1 & 0xffffffff;
      }
      I8xPutBytePolled('\x01','\0','\x03',0xae);
      return uVar1 & 0xffffffff;
    }
  }
  pbVar3 = (byte *)0x0;
  uVar1 = I8xPutBytePolled('\x01','\0','\x03',0x20);
  if (-1 < (int)uVar1) {
    uVar6 = 0;
    do {
      pbVar3 = param_2;
      uVar1 = I8xGetBytePolled('\0',param_2);
      if ((int)uVar1 != -0x3fffff4b) break;
      KeStallExecutionProcessor();
      uVar6 = uVar6 + 1;
    } while (uVar6 < 5);
  }
  uVar5 = uVar1 & 0xffffffff;
  if (uVar4 != 0) {
    pbVar3 = (byte *)0x0;
    uVar2 = I8xPutBytePolled('\x01','\0','\x03',0xae);
    if ((int)uVar2 < 0) {
      if (-1 < (int)uVar1) {
        uVar5 = uVar2 & 0xffffffff;
      }
    }
    else if ((int)uVar1 == 0) {
      *param_2 = *param_2 & 0xef;
    }
  }
  if ((param_1 & 2) != 0) {
    pbVar3 = (byte *)0x0;
    uVar1 = I8xPutBytePolled('\x01','\0','\x03',0xa8);
    if (-1 < (int)uVar5) {
      if ((int)uVar1 < 0) {
        uVar5 = uVar1 & 0xffffffff;
      }
      else {
        *param_2 = *param_2 & 0xdf;
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar3,0x13,0x1d,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  return uVar5;
}



===== I8xGetDataQueuePointer @ 1c0004d40 =====

undefined8 I8xGetDataQueuePointer(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x4f,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  uVar2 = 0;
  if ((char)param_1[1] == '\x01') {
    lVar3 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x50,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x51,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                           (char)*(undefined8 *)(lVar3 + 0x370),(char)*(undefined8 *)(lVar3 + 0x378)
                          );
      }
    }
    param_1[2] = *(longlong *)(lVar3 + 0x370);
    lVar1 = *(longlong *)(lVar3 + 0x378);
  }
  else {
    if ((char)param_1[1] != '\x02') goto LAB_1c0004da7;
    lVar3 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x52,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x53,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                           (char)*(undefined8 *)(lVar3 + 0x3b8),(char)*(undefined8 *)(lVar3 + 0x3c0)
                          );
      }
    }
    param_1[2] = *(longlong *)(lVar3 + 0x3b8);
    lVar1 = *(longlong *)(lVar3 + 0x3c0);
  }
  param_1[3] = lVar1;
  uVar2 = (ulonglong)*(uint *)(lVar3 + 0x5c);
  *(uint *)(param_1 + 4) = *(uint *)(lVar3 + 0x5c);
LAB_1c0004da7:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar2 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x54,
                             &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== I8042MouseIsrDpc @ 1c0004f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8042MouseIsrDpc(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined7 extraout_var;
  uint uVar4;
  code *pcVar5;
  ulonglong uVar6;
  int iVar7;
  uint local_res10 [2];
  ulonglong local_res18 [2];
  longlong local_90;
  undefined4 local_88;
  undefined4 local_84;
  ulonglong *local_80;
  longlong local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  longlong local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
  local_40 = 0;
  local_84 = 0;
  local_res18[0] = param_3 & 0xffffffff00000000;
  local_res10[0] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,10,
                     &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x238) = *(int *)(lVar1 + 0x238) + 1;
  UNLOCK();
  local_90 = lVar1 + 0x3a8;
  local_88 = 0;
  local_80 = local_res18;
  pcVar5 = I8xDpcVariableOperation;
  KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
  if ((int)local_res18[0] == 0) {
    do {
      local_res10[0] = 0;
      uStack_58 = CONCAT71(uStack_58._1_7_,2);
      uStack_70 = CONCAT71(uStack_70._1_7_,2);
      uStack_70 = uStack_70 & 0xffffffff;
      local_78 = lVar1;
      local_60 = lVar1;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xGetDataQueuePointer,&local_60);
      uVar6 = local_40 & 0xffffffff;
      if ((int)local_40 != 0) {
        uVar2 = *(undefined8 *)(lVar1 + 0x1b0);
        pcVar5 = *(code **)(lVar1 + 0x1b8);
        if (uStack_48 < local_50) {
LAB_1c0005035:
          uVar4 = 0;
          if (local_res10[0] < (uint)uVar6) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,6,0xe,
                                 &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids),
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,8,0xf,
                                 &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,(char)uStack_48,
                                 (char)local_50);
            }
            (*pcVar5)(uVar2,uStack_48,local_50,local_res10);
            uVar4 = (uint)((int)local_50 - (int)uStack_48) / 0x18 - local_res10[0];
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar4,8,0x10,
                                 &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,
                                 (char)local_res10[0],(char)uVar4);
            }
            uStack_70 = CONCAT44(uStack_70._4_4_ + local_res10[0],(undefined4)uStack_70);
            local_68 = uStack_48 + (ulonglong)local_res10[0] * 0x18;
          }
          pcVar5 = I8xSetDataQueuePointer;
          KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xSetDataQueuePointer,&local_78);
          if (uVar4 == 0) goto LAB_1c000515c;
        }
        else {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,6,0xb,
                               &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids),
             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,8,0xc,
                               &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,(char)uStack_48,
                               (char)*(undefined8 *)(lVar1 + 0x3c8));
          }
          (*pcVar5)(uVar2,uStack_48,*(undefined8 *)(lVar1 + 0x3c8),local_res10);
          uVar4 = *(int *)(lVar1 + 0x3c8) - (int)uStack_48;
          iVar7 = uVar4 / 0x18 - local_res10[0];
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                               SUB168(ZEXT816(0xaaaaaaaaaaaaaaab) * ZEXT416(uVar4),8),8,0xd,
                               &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,(char)local_res10[0]
                               ,(char)iVar7);
          }
          uStack_70 = CONCAT44(uStack_70._4_4_ + local_res10[0],(undefined4)uStack_70);
          if (iVar7 == 0) {
            local_68 = *(ulonglong *)(lVar1 + 0x3b0);
            uVar6 = local_40 & 0xffffffff;
            uStack_48 = local_68;
            goto LAB_1c0005035;
          }
          pcVar5 = I8xSetDataQueuePointer;
          local_68 = uStack_48 + (ulonglong)local_res10[0] * 0x18;
          KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xSetDataQueuePointer,&local_78);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,8,0x11,
                           &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
        }
        goto LAB_1c0005427;
      }
LAB_1c000515c:
      local_80 = local_res18;
      local_88 = 1;
      pcVar5 = I8xDpcVariableOperation;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
      if ((int)local_res18[0] == -1) goto LAB_1c00051a0;
      local_80 = local_res18;
      local_88 = 2;
      local_res18[0] = local_res18[0] & 0xffffffff00000000;
      pcVar5 = I8xDpcVariableOperation;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,8,0x12,
                         &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
      }
      bVar3 = I8xCheckDpcWatchdogLimit();
      iVar7 = (int)CONCAT71(extraout_var,bVar3);
      if (iVar7 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,0x13,
                           &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
        }
        *(int *)(lVar1 + 0x23c) = *(int *)(lVar1 + 0x23c) + 1;
        local_80 = local_res18;
        local_88 = 2;
        local_res18[0] = CONCAT44(local_res18[0]._4_4_,0xffffffff);
        KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
        pcVar5 = *(code **)(param_2 + 0x20);
        KeInsertQueueDpc(lVar1 + 0x260,pcVar5,0);
        goto LAB_1c00051a0;
      }
    } while (iVar7 != 2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,
                       (short)CONCAT71(extraout_var,bVar3) + 0x12,
                       &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
    }
    *(int *)(lVar1 + 0x240) = *(int *)(lVar1 + 0x240) + 1;
LAB_1c0005427:
    local_80 = local_res18;
    local_88 = 2;
    local_res18[0] = CONCAT44(local_res18[0]._4_4_,0xffffffff);
    KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
    pcVar5 = (code *)0xffffffffff676980;
    KeSetTimer(lVar1 + 0x68,0xffffffffff676980,lVar1 + 0x2a0);
  }
LAB_1c00051a0:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,0x15,
                     &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0005510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c0005630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== I8xSetDataQueuePointer @ 1c0005750 =====

undefined8 I8xSetDataQueuePointer(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined *in_stack_ffffffffffffffc8;
  undefined1 uVar6;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffc8 = &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids;
    param_3 = 3;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x59,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  uVar4 = 0;
  if ((char)param_1[1] == '\x01') {
    lVar2 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x5a,
                         in_stack_ffffffffffffffc8,(char)*(undefined8 *)(lVar2 + 0x378),
                         (char)*(undefined4 *)(lVar2 + 0x5c));
    }
    *(longlong *)(lVar2 + 0x378) = param_1[2];
    uVar4 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
    piVar1 = (int *)(lVar2 + 0x5c);
    *piVar1 = *piVar1 - *(uint *)((longlong)param_1 + 0xc);
    if (*piVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffc8 = &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids;
        param_3 = 4;
        uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x5b,
                                 &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      *(undefined1 *)(lVar2 + 0x232) = 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00057d2;
    uVar6 = (undefined1)*(undefined4 *)(lVar2 + 0x5c);
    uVar5 = 0x5c;
    uVar3 = (undefined1)*(undefined8 *)(lVar2 + 0x378);
LAB_1c0005845:
    uVar4 = WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,uVar5,
                               in_stack_ffffffffffffffc8,uVar3,uVar6);
  }
  else if ((char)param_1[1] == '\x02') {
    lVar2 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x5d,
                         in_stack_ffffffffffffffc8,(char)*(undefined8 *)(lVar2 + 0x3c0),
                         (char)*(undefined4 *)(lVar2 + 0x5c));
    }
    *(longlong *)(lVar2 + 0x3c0) = param_1[2];
    uVar4 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
    piVar1 = (int *)(lVar2 + 0x5c);
    *piVar1 = *piVar1 - *(uint *)((longlong)param_1 + 0xc);
    if (*piVar1 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffc8 = &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids;
        param_3 = 4;
        uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,0x5e,
                                 &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      *(undefined1 *)(lVar2 + 0x232) = 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00057d2;
    uVar6 = (undefined1)*(undefined4 *)(lVar2 + 0x5c);
    uVar5 = 0x5f;
    uVar3 = (undefined1)*(undefined8 *)(lVar2 + 0x3c0);
    goto LAB_1c0005845;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x60,
                             &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
LAB_1c00057d2:
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== I8xQueueCurrentMouseInput @ 1c0005980 =====

void I8xQueueCurrentMouseInput(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0x60) != 0) {
    puVar3 = (undefined8 *)(lVar1 + 0x3d0);
    uVar2 = I8xWriteDataToMouseQueue(lVar1,puVar3);
    if ((char)uVar2 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,0x1f,0x5e,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
      }
      if (*(char *)(lVar1 + 0x232) != '\0') {
        KeInsertQueueDpc(lVar1 + 0xe8,0,0x4005000c);
        *(undefined1 *)(lVar1 + 0x232) = 0;
      }
    }
    else if (*(int *)(lVar1 + 0x3a8) < 0) {
      KeInsertQueueDpc(lVar1 + 0x260,0,0);
    }
    else {
      *(int *)(lVar1 + 0x3a8) = *(int *)(lVar1 + 0x3a8) + 1;
    }
  }
  return;
}



===== I8xWriteDataToMouseQueue @ 1c0005a50 =====

ulonglong I8xWriteDataToMouseQueue(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  puVar7 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x16,
                     &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,2,0x17,
                         &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x3b8),
                         (char)*(undefined8 *)(param_1 + 0x3c0));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,2,0x18,
                          &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,
                          (char)*(undefined4 *)(param_1 + 0x5c));
      }
    }
  }
  plVar1 = (longlong *)(param_1 + 0x3b8);
  puVar6 = (undefined8 *)*plVar1;
  if ((puVar6 == *(undefined8 **)(param_1 + 0x3c0)) && (*(int *)(param_1 + 0x5c) != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar6 = (undefined8 *)
               WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,5,0x19,
                                &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
    }
    uVar5 = (ulonglong)puVar6 & 0xffffffffffffff00;
  }
  else {
    uVar2 = param_2[1];
    *puVar6 = *param_2;
    puVar6[1] = uVar2;
    puVar6[2] = param_2[2];
    iVar3 = *(int *)(param_1 + 0x5c) + 1;
    *plVar1 = *plVar1 + 0x18;
    *(int *)(param_1 + 0x5c) = iVar3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,8,0x1a,
                        &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids,(char)iVar3);
    }
    lVar4 = *(longlong *)(param_1 + 0x3c8);
    if (*plVar1 == lVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,6,0x1b,
                         &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
      }
      lVar4 = *(longlong *)(param_1 + 0x3b0);
      *(longlong *)(param_1 + 0x3b8) = lVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar4 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,7,0x1c,
                               &WPP_15ecbda4bf0b3f54a10722a21773d3ef_Traceguids);
    }
    uVar5 = CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
  }
  return uVar5;
}



===== WPP_RECORDER_SF_d @ 1c0005c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== I8042CompletionDpc @ 1c0005d70 =====

void I8042CompletionDpc(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  longlong lVar6;
  
  puVar4 = *(undefined8 **)(param_2 + 0x40);
  lVar6 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x11,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  KeCancelTimer(Globals + 0x78);
  if (param_3 == 0) {
    IoFreeController(*(undefined8 *)(Globals + 8));
    param_3 = 0;
    IoStartNextPacket(param_2);
  }
  else {
    iVar2 = *(int *)(*(longlong *)(param_3 + 0xb8) + 0x18);
    if (iVar2 == 0xb0004) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,6,0x15,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      puVar5 = *(undefined4 **)(param_3 + 0x18);
      *(undefined4 *)((longlong)puVar4 + 0x2d4) = *puVar5;
      uVar1 = *(undefined2 *)(puVar5 + 1);
      *(undefined2 *)(puVar4 + 0x5b) = uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,8,0x16,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                           (char)*(undefined2 *)((longlong)puVar4 + 0x2d6),(char)uVar1);
      }
    }
    else if (iVar2 == 0xb0008) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,6,0x13,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      uVar3 = **(undefined4 **)(param_3 + 0x18);
      *(undefined4 *)((longlong)puVar4 + 0x2da) = uVar3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,8,0x14,
                          &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,
                          (char)((uint)uVar3 >> 0x10));
      }
    }
    else {
      if (iVar2 == 0xf3fff) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,6,0x17,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        I8xFinishResetRequest(puVar4,0,'\0','\x01');
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,8,0x18,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
    }
    *(undefined4 *)(param_3 + 0x30) = 0;
    IofCompleteRequest(param_3,6);
    KeAcquireSpinLockAtDpcLevel(Globals + 0xb8);
    lVar6 = puVar4[0x40];
    if ((lVar6 != 0) && (lVar6 != Globals + 200)) {
      ExFreePoolWithTag(lVar6,0);
    }
    puVar4[0x40] = 0;
    KeReleaseSpinLockFromDpcLevel(Globals + 0xb8);
    IoFreeController(*(undefined8 *)(Globals + 8));
    IoStartNextPacket(param_2,0);
    IoReleaseRemoveLockEx(puVar4 + 5,param_3,0x20);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,7,0x19,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_DD @ 1c0006090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1c00061c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c00062b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,4,&WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== I8042KeyboardIsrDpc @ 1c0006390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8042KeyboardIsrDpc(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined7 extraout_var;
  uint uVar4;
  code *pcVar5;
  ulonglong uVar6;
  int iVar7;
  uint local_res10 [2];
  ulonglong local_res18 [2];
  longlong local_90;
  undefined4 local_88;
  undefined4 local_84;
  ulonglong *local_80;
  longlong local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  longlong local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
  local_40 = 0;
  local_84 = 0;
  local_res18[0] = param_3 & 0xffffffff00000000;
  local_res10[0] = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,10,
                     &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x238) = *(int *)(lVar1 + 0x238) + 1;
  UNLOCK();
  local_90 = lVar1 + 0x360;
  local_88 = 0;
  local_80 = local_res18;
  pcVar5 = I8xDpcVariableOperation;
  KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
  if ((int)local_res18[0] == 0) {
    do {
      local_res10[0] = 0;
      uStack_58 = CONCAT71(uStack_58._1_7_,1);
      uStack_70 = CONCAT71(uStack_70._1_7_,1);
      uStack_70 = uStack_70 & 0xffffffff;
      local_78 = lVar1;
      local_60 = lVar1;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xGetDataQueuePointer,&local_60);
      uVar6 = local_40 & 0xffffffff;
      if ((int)local_40 != 0) {
        uVar2 = *(undefined8 *)(lVar1 + 0x1b0);
        pcVar5 = *(code **)(lVar1 + 0x1b8);
        if (uStack_48 < local_50) {
LAB_1c00064b5:
          uVar4 = 0;
          if (local_res10[0] < (uint)uVar6) {
            if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
               (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,6,0xe,
                                 &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids),
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,8,0xf,
                                 &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,(char)uStack_48,
                                 (char)local_50);
            }
            (*pcVar5)(uVar2,uStack_48,local_50,local_res10);
            uVar4 = (uint)((int)local_50 - (int)uStack_48) / 0xc - local_res10[0];
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar4,8,0x10,
                                 &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,
                                 (char)local_res10[0],(char)uVar4);
            }
            uStack_70 = CONCAT44(uStack_70._4_4_ + local_res10[0],(undefined4)uStack_70);
            local_68 = uStack_48 + (ulonglong)local_res10[0] * 0xc;
          }
          pcVar5 = I8xSetDataQueuePointer;
          KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xSetDataQueuePointer,&local_78);
          if (uVar4 == 0) goto LAB_1c000654d;
        }
        else {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,6,0xb,
                               &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids),
             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,8,0xc,
                               &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,(char)uStack_48,
                               (char)*(undefined8 *)(lVar1 + 0x380));
          }
          (*pcVar5)(uVar2,uStack_48,*(undefined8 *)(lVar1 + 0x380),local_res10);
          uVar4 = *(int *)(lVar1 + 0x380) - (int)uStack_48;
          iVar7 = uVar4 / 0xc - local_res10[0];
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                               SUB168(ZEXT816(0xaaaaaaaaaaaaaaab) * ZEXT416(uVar4),8),8,0xd,
                               &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids,(char)local_res10[0]
                               ,(char)iVar7);
          }
          uStack_70 = CONCAT44(uStack_70._4_4_ + local_res10[0],(undefined4)uStack_70);
          if (iVar7 == 0) {
            local_68 = *(ulonglong *)(lVar1 + 0x368);
            uVar6 = local_40 & 0xffffffff;
            uStack_48 = local_68;
            goto LAB_1c00064b5;
          }
          pcVar5 = I8xSetDataQueuePointer;
          local_68 = uStack_48 + (ulonglong)local_res10[0] * 0xc;
          KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xSetDataQueuePointer,&local_78);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,8,0x11,
                           &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
        }
        goto LAB_1c000689c;
      }
LAB_1c000654d:
      local_80 = local_res18;
      local_88 = 1;
      pcVar5 = I8xDpcVariableOperation;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
      if ((int)local_res18[0] == -1) goto LAB_1c0006591;
      local_80 = local_res18;
      local_88 = 2;
      local_res18[0] = local_res18[0] & 0xffffffff00000000;
      pcVar5 = I8xDpcVariableOperation;
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,8,0x12,
                         &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
      }
      bVar3 = I8xCheckDpcWatchdogLimit();
      iVar7 = (int)CONCAT71(extraout_var,bVar3);
      if (iVar7 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,0x13,
                           &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
        }
        *(int *)(lVar1 + 0x23c) = *(int *)(lVar1 + 0x23c) + 1;
        local_80 = local_res18;
        local_88 = 2;
        local_res18[0] = CONCAT44(local_res18[0]._4_4_,0xffffffff);
        KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
        pcVar5 = *(code **)(param_2 + 0x20);
        KeInsertQueueDpc(lVar1 + 0x2e0,pcVar5,0);
        goto LAB_1c0006591;
      }
    } while (iVar7 != 2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,
                       (short)CONCAT71(extraout_var,bVar3) + 0x12,
                       &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
    }
    *(int *)(lVar1 + 0x240) = *(int *)(lVar1 + 0x240) + 1;
LAB_1c000689c:
    local_80 = local_res18;
    local_88 = 2;
    local_res18[0] = CONCAT44(local_res18[0]._4_4_,0xffffffff);
    KeSynchronizeExecution(*(undefined8 *)(lVar1 + 8),I8xDpcVariableOperation,&local_90);
    pcVar5 = (code *)0xffffffffff676980;
    KeSetTimer(lVar1 + 0x68,0xffffffffff676980,lVar1 + 800);
  }
LAB_1c0006591:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,7,0x15,
                     &WPP_575c8870bf553b08b608d7700ff895e9_Traceguids);
  }
  return;
}



===== I8xPutBytePolled @ 1c00069a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong I8xPutBytePolled(char param_1,char param_2,char param_3,byte param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  char local_res18 [8];
  
  local_res18[0] = '\0';
  uVar7 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x13,0x3d,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  if (param_3 == '\x02') {
    I8xPutBytePolled('\x01','\0','\x03',0xd4);
  }
  uVar8 = 0;
  uVar1 = *(undefined8 *)(Globals + 0xd0);
  uVar2 = *(undefined8 *)(Globals + 0xd8);
  do {
    uVar6 = 0;
    if (*(ushort *)(Globals + 0x46) <= uVar8) {
LAB_1c0006adb:
      if (*(ushort *)(Globals + 0x46) <= uVar8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x15
                           ,0x45,&WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
        }
        uVar7 = 0xc00000b5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x13,
                         0x46,&WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
      return uVar7;
    }
    if (*(short *)(Globals + 0x48) != 0) {
      do {
        uVar7 = (*DAT_1c00121d8)(uVar2);
        if ((uVar7 & 2) == 0) break;
        KeStallExecutionProcessor(*(undefined2 *)(Globals + 0x4e));
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(Globals + 0x48));
      if (uVar6 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                             0x12,0x3e,&WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                             (char)*(undefined2 *)(Globals + 0x4e),(char)uVar6);
        }
        if (*(ushort *)(Globals + 0x48) <= uVar6) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                             0x14,0x3f,&WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
          }
          uVar7 = 0xc00000b5;
          goto LAB_1c0006adb;
        }
      }
    }
    uVar4 = uVar2;
    I8xDrainOutputBuffer(uVar1,uVar2);
    if (param_1 == '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x14,0x40,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,param_4);
      }
      uVar4 = uVar2;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x14,0x41,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,param_4);
      }
      uVar4 = uVar1;
    }
    uVar7 = (ulonglong)param_4;
    (*DAT_1c00121e0)(uVar4);
    if (param_2 == '\0') {
      uVar7 = 0;
      goto LAB_1c0006adb;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0x12,0x42,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
    do {
      pcVar5 = local_res18;
      uVar3 = I8xGetBytePolled(param_3,pcVar5);
      uVar7 = uVar3 & 0xffffffff;
      if ((int)uVar3 != 0) goto LAB_1c0006adb;
      if (local_res18[0] == -6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x12
                           ,0x43,&WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
        }
        goto LAB_1c0006adb;
      }
    } while (local_res18[0] != -2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,0x12,(short)uVar3 + 0x44,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
    if (param_3 == '\x02') {
      I8xPutBytePolled('\x01','\0','\x03',0xd4);
    }
    uVar8 = uVar8 + 1;
  } while( true );
}



===== I8xDrainOutputBuffer @ 1c0006dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xDrainOutputBuffer(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 local_res18;
  
  uVar3 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0xd,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  local_res18 = 0xffffffffffffd8f0;
  cVar1 = KeGetCurrentIrql();
  uVar4 = 0;
  do {
    uVar2 = (*DAT_1c00121d8)(param_2);
    if ((uVar2 & 2) == 0) break;
    if (cVar1 == '\0') {
      uVar3 = 0;
      KeDelayExecutionThread(0,0,&local_res18);
    }
    else {
      KeStallExecutionProcessor(1000);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 1000);
  while (uVar2 = (*DAT_1c00121d8)(param_2), (uVar2 & 1) != 0) {
    (*DAT_1c00121d8)(param_1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x13,0xe,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  return;
}



===== I8xGetBytePolled @ 1c0006f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 I8xGetBytePolled(char param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  byte bVar6;
  
  puVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x13,0x16,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  if (param_1 == '\x01') {
    pcVar3 = "keyboard";
  }
  else {
    pcVar3 = "mouse";
    if (param_1 != '\x02') {
      pcVar3 = "8042 controller";
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x14,0x17,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar3);
  }
  uVar5 = 0;
  bVar6 = 0x21;
  if (param_1 != '\x02') {
    bVar6 = 1;
  }
  if (*(short *)(Globals + 0x48) != 0) {
    do {
      bVar1 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd8));
      if ((bVar6 & bVar1) == bVar6) break;
      if ((bVar1 & 1) == 0) {
        KeStallExecutionProcessor(*(undefined2 *)(Globals + 0x4e));
        uVar5 = uVar5 + 1;
      }
      else {
        uVar2 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd0));
        *param_2 = uVar2;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x14,0x18,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,uVar2);
        }
      }
    } while (uVar5 < *(ushort *)(Globals + 0x48));
    if (uVar5 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x12,0x19,
                           &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                           (char)*(undefined2 *)(Globals + 0x4e),(char)uVar5);
      }
      if (*(ushort *)(Globals + 0x48) <= uVar5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x15,0x1a,
                           &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
        }
        return 0xc00000b5;
      }
    }
  }
  uVar2 = (*DAT_1c00121d8)(*(undefined8 *)(Globals + 0xd0));
  *param_2 = uVar2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0x13,0x1b,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,uVar2);
  }
  return 0;
}



===== I8xInternalDeviceControl @ 1c0007190 =====

int I8xInternalDeviceControl(longlong param_1,undefined *param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  ushort uVar11;
  undefined4 uVar12;
  undefined *puVar13;
  uint uVar14;
  undefined2 uVar15;
  undefined4 uVar16;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  puVar13 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xb,0x1f,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar9 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar14 = *(uint *)(lVar9 + 0x18);
  if (uVar14 == 0xb0008) {
    if (puVar2[1] == 0) {
      iVar8 = -0x3fffff5d;
    }
    else if (*(int *)(puVar2 + 10) == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x31,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      if (3 < *(uint *)(lVar9 + 0x10)) {
        lVar9 = *(longlong *)(param_2 + 0x18);
        uVar1 = *(ushort *)(lVar9 + 2);
        puVar13 = (undefined *)(ulonglong)uVar1;
        if ((uVar1 & 0xfff0) == 0) {
          if ((char)*(undefined2 *)(puVar2 + 0x56) == '\a') {
            cVar6 = (char)((ushort)*(undefined2 *)(puVar2 + 0x56) >> 8);
            if ((byte)(cVar6 + 0x7fU) < 2) {
              if ((uVar1 & 8) == 0) {
                uVar11 = 0xfffd;
                goto LAB_1c0007b57;
              }
              puVar13 = (undefined *)(ulonglong)(uVar1 | 2);
              *(ushort *)(lVar9 + 2) = uVar1 | 2;
              *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) =
                   *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) & 0xfff7;
            }
            else if (cVar6 != '\x01') goto LAB_1c0007b4d;
          }
          else {
LAB_1c0007b4d:
            if ((uVar1 & 8) != 0) {
              uVar11 = 0xfff7;
LAB_1c0007b57:
              puVar13 = (undefined *)(ulonglong)(uVar1 & uVar11);
              *(ushort *)(lVar9 + 2) = uVar1 & uVar11;
            }
          }
LAB_1c0007b5f:
          *(undefined4 *)(param_2 + 0x30) = 0x103;
          goto LAB_1c0007b66;
        }
      }
LAB_1c0007510:
      iVar8 = -0x3ffffff3;
    }
    else {
      iVar8 = -0x3ffffd2d;
    }
LAB_1c0007515:
    *(int *)(param_2 + 0x30) = iVar8;
  }
  else {
    if (uVar14 == 0xb0004) {
      if (puVar2[1] == 0) {
        iVar8 = -0x3fffff5d;
      }
      else {
        if (*(int *)(puVar2 + 10) == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x33,
                             &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
          }
          if (5 < *(uint *)(lVar9 + 0x10)) {
            uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x18) + 2);
            if ((((*(ushort *)((longlong)puVar2 + 0x2c2) <= uVar1) &&
                 (uVar1 <= *(ushort *)(puVar2 + 0x59))) &&
                (uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x18) + 4),
                *(ushort *)((longlong)puVar2 + 0x2c4) <= uVar1)) &&
               (uVar1 <= *(ushort *)((longlong)puVar2 + 0x2ca))) goto LAB_1c0007b5f;
          }
LAB_1c0007a8b:
          iVar8 = -0x3ffffff3;
          goto LAB_1c0007a90;
        }
        iVar8 = -0x3ffffd2d;
      }
      goto LAB_1c0007515;
    }
    if (0xb3fcb < uVar14) {
      if (uVar14 < 0xf0404) {
        if (uVar14 != 0xf0403) {
          if (uVar14 != 0xb3fcf) {
            if (uVar14 == 0xf0000) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x35,
                                 &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
              }
              if (*(uint *)(lVar9 + 8) < 0xc) {
                iVar8 = -0x3fffffdd;
                goto LAB_1c0007515;
              }
              puVar5 = *(undefined8 **)(param_2 + 0x18);
              *puVar5 = puVar2[0x49];
              iVar8 = 0;
              *(undefined4 *)(puVar5 + 1) = *(undefined4 *)(puVar2 + 0x4a);
              *(undefined8 *)(param_2 + 0x38) = 0xc;
              goto LAB_1c0007a90;
            }
            if (uVar14 != 0xf0203) goto LAB_1c0007930;
            if ((*Globals & 2) != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,1,0x27,
                                 &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
              }
              *Globals = *Globals | 0x20;
            }
            LOCK();
            DAT_1c00121fc = DAT_1c00121fc + 1;
            UNLOCK();
            *(undefined1 *)((longlong)puVar2 + 0x235) = 0;
            *Globals = *Globals | 2;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xc,0x28,
                               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
            }
            if (puVar2[0x37] != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = 0x29;
                goto LAB_1c00074ba;
              }
              goto LAB_1c00074d5;
            }
            if (*(uint *)(lVar9 + 0x10) < 0x10) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = 0x2a;
                goto LAB_1c00074f5;
              }
              goto LAB_1c0007510;
            }
            puVar4 = *(undefined4 **)(lVar9 + 0x20);
            uVar12 = puVar4[1];
            uVar16 = puVar4[2];
            uVar7 = puVar4[3];
            *(undefined4 *)(puVar2 + 0x36) = *puVar4;
            *(undefined4 *)((longlong)puVar2 + 0x1b4) = uVar12;
            *(undefined4 *)(puVar2 + 0x37) = uVar16;
            *(undefined4 *)((longlong)puVar2 + 0x1bc) = uVar7;
            lVar9 = ExAllocatePool2(0x100,0x28,0x32343038);
            if (lVar9 != 0) {
              uVar10 = IoGetAttachedDeviceReference(*puVar2);
              *(longlong *)(lVar9 + 0x20) = param_1;
              uVar16 = 0x28;
              uVar12 = 0xf3fc3;
              *(code **)(lVar9 + 0x18) = I8xQueueCurrentMouseInput;
              *(code **)(lVar9 + 0x10) = I8xMouseIsrWritePort;
              goto LAB_1c00075e0;
            }
          }
LAB_1c000760b:
          iVar8 = 0;
          *(undefined4 *)(param_2 + 0x30) = 0;
          goto LAB_1c0007518;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x2b;
LAB_1c00076d1:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xc,uVar15,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
LAB_1c00076ec:
        iVar8 = -0x3ffffffe;
      }
      else {
        if (uVar14 == 0xf3fc3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xc,0x2c,
                             &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
          }
          if (*(uint *)(lVar9 + 0x10) < 0x28) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = 0x2d;
              goto LAB_1c00074f5;
            }
            goto LAB_1c0007510;
          }
          puVar5 = *(undefined8 **)(lVar9 + 0x20);
          puVar2[0x86] = *puVar5;
          lVar9 = puVar5[1];
          if (lVar9 != 0) {
            puVar2[0x85] = lVar9;
          }
          iVar8 = 0;
          goto LAB_1c0007a90;
        }
        if (uVar14 != 0xf3fc7) {
          if (uVar14 != 0xf3fcf) {
LAB_1c0007930:
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = 0x38;
              uVar14 = 0xd;
              goto LAB_1c0007712;
            }
            goto LAB_1c0007727;
          }
          goto LAB_1c000760b;
        }
LAB_1c0007632:
        if (puVar2[1] == 0) {
          iVar8 = -0x3fffff5d;
        }
        else {
          if (*(int *)(puVar2 + 10) == 1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x36,
                               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
            }
            if ((*(int *)(lVar9 + 0x10) != 0) && (*(longlong *)(lVar9 + 0x20) != 0))
            goto LAB_1c0007b5f;
            goto LAB_1c0007a8b;
          }
          iVar8 = -0x3ffffd2d;
        }
      }
      goto LAB_1c0007515;
    }
    if (uVar14 == 0xb3fcb) {
      if (*(char *)((longlong)puVar2 + 0x235) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x37;
          uVar14 = 1;
LAB_1c0007712:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,uVar14,uVar15,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
LAB_1c0007727:
        iVar8 = -0x3ffffff0;
        goto LAB_1c0007515;
      }
      iVar8 = -0x3fffff45;
    }
    else if (uVar14 < 0xb0204) {
      if (uVar14 == 0xb0203) {
        if ((*Globals & 1) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,1,0x20,
                             &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
          }
          *Globals = *Globals | 0x10;
        }
        LOCK();
        DAT_1c00121f8 = DAT_1c00121f8 + 1;
        UNLOCK();
        *(undefined1 *)((longlong)puVar2 + 0x235) = 1;
        *Globals = *Globals | 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xc,0x21,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        if (puVar2[0x37] == 0) {
          if (0xf < *(uint *)(lVar9 + 0x10)) {
            puVar4 = *(undefined4 **)(lVar9 + 0x20);
            uVar12 = puVar4[1];
            uVar16 = puVar4[2];
            uVar7 = puVar4[3];
            *(undefined4 *)(puVar2 + 0x36) = *puVar4;
            *(undefined4 *)((longlong)puVar2 + 0x1b4) = uVar12;
            *(undefined4 *)(puVar2 + 0x37) = uVar16;
            *(undefined4 *)((longlong)puVar2 + 0x1bc) = uVar7;
            lVar9 = ExAllocatePool2(0x100,0x30,0x32343038);
            if (lVar9 != 0) {
              uVar10 = IoGetAttachedDeviceReference(*puVar2);
              *(longlong *)(lVar9 + 0x28) = param_1;
              uVar16 = 0x30;
              uVar12 = 0xb3fc3;
              *(code **)(lVar9 + 0x20) = I8xQueueCurrentKeyboardInput;
              *(code **)(lVar9 + 0x18) = I8xKeyboardIsrWritePort;
LAB_1c00075e0:
              I8xSendIoctl(uVar10,uVar12,lVar9,uVar16);
              ObfDereferenceObject(uVar10);
              ExFreePoolWithTag(lVar9);
            }
            goto LAB_1c000760b;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x23;
            goto LAB_1c00074f5;
          }
          goto LAB_1c0007510;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x22;
LAB_1c00074ba:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xd,uVar15,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
LAB_1c00074d5:
        iVar8 = -0x3fffffbd;
        goto LAB_1c0007515;
      }
      if (uVar14 == 0xb0000) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x2e,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        if (*(uint *)(lVar9 + 8) < 0x1c) {
          iVar8 = -0x3fffffdd;
          goto LAB_1c0007515;
        }
        uVar10 = puVar2[0x57];
        puVar5 = *(undefined8 **)(param_2 + 0x18);
        *puVar5 = puVar2[0x56];
        puVar5[1] = uVar10;
        puVar5[2] = puVar2[0x58];
        iVar8 = 0;
        *(undefined4 *)(puVar5 + 3) = *(undefined4 *)(puVar2 + 0x59);
        *(undefined8 *)(param_2 + 0x38) = 0x1c;
      }
      else if (uVar14 == 0xb0020) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x32,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        if (*(uint *)(lVar9 + 8) < 6) {
          iVar8 = -0x3fffffdd;
          goto LAB_1c0007515;
        }
        puVar4 = *(undefined4 **)(param_2 + 0x18);
        *puVar4 = *(undefined4 *)((longlong)puVar2 + 0x2d4);
        iVar8 = 0;
        *(undefined2 *)(puVar4 + 1) = *(undefined2 *)(puVar2 + 0x5b);
        *(undefined8 *)(param_2 + 0x38) = 6;
      }
      else if (uVar14 == 0xb0040) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x30,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        if (*(uint *)(lVar9 + 8) < 4) {
          iVar8 = -0x3fffffdd;
          goto LAB_1c0007515;
        }
        **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)((longlong)puVar2 + 0x2da);
        if (((char)*(undefined2 *)(puVar2 + 0x56) == '\a') &&
           ((byte)((char)((ushort)*(undefined2 *)(puVar2 + 0x56) >> 8) + 0x7fU) < 2)) {
          uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x18) + 2);
          if ((uVar1 & 2) != 0) {
            *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) = uVar1 | 8;
            *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) =
                 *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) & 0xfffd;
          }
        }
        *(undefined8 *)(param_2 + 0x38) = 4;
        iVar8 = 0;
      }
      else {
        if (uVar14 != 0xb0080) goto LAB_1c0007930;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x2f,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        uVar1 = *(ushort *)((longlong)puVar2 + 0x2b6);
        uVar14 = (uint)uVar1 * 4 + 2;
        if (*(uint *)(lVar9 + 8) < uVar14) {
          iVar8 = -0x3fffffdd;
          goto LAB_1c0007515;
        }
        puVar3 = *(ushort **)(param_2 + 0x18);
        puVar13 = &DAT_1c000f278;
        *puVar3 = uVar1;
        memcpy(puVar3 + 1,&DAT_1c000f278,(ulonglong)uVar1 << 2);
        iVar8 = 0;
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar14;
      }
    }
    else {
      if (uVar14 == 0xb0403) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x24;
          goto LAB_1c00076d1;
        }
        goto LAB_1c00076ec;
      }
      if (uVar14 != 0xb3fc3) {
        if (uVar14 != 0xb3fc7) goto LAB_1c0007930;
        goto LAB_1c0007632;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xc,0x25,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
      if (*(uint *)(lVar9 + 0x10) < 0x30) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x26;
LAB_1c00074f5:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,0xd,uVar15,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        goto LAB_1c0007510;
      }
      puVar5 = *(undefined8 **)(lVar9 + 0x20);
      puVar2[0x75] = *puVar5;
      if (puVar5[1] != 0) {
        puVar2[0x73] = puVar5[1];
      }
      if (puVar5[2] != 0) {
        puVar2[0x74] = puVar5[2];
      }
      iVar8 = 0;
    }
LAB_1c0007a90:
    *(int *)(param_2 + 0x30) = iVar8;
    if (iVar8 == 0x103) {
LAB_1c0007b66:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar13,10,0x39,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,(char)param_2,
                           (char)*(undefined8 *)(param_1 + 0x40) + '(');
      }
      iVar8 = IoAcquireRemoveLockEx(*(longlong *)(param_1 + 0x40) + 0x28,param_2,"",1,0x20);
      if (-1 < iVar8) {
        iVar8 = 0x103;
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        IoStartPacket(param_1,param_2,0,0);
        goto LAB_1c0007529;
      }
      *(int *)(param_2 + 0x30) = iVar8;
    }
  }
LAB_1c0007518:
  puVar13 = (undefined *)0x0;
  IofCompleteRequest(param_2);
  param_2 = puVar13;
LAB_1c0007529:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xb,0x3a,
                      &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,(char)iVar8);
  }
  return iVar8;
}



===== I8xWritePortUchar @ 1c0007c10 =====

undefined1 I8xWritePortUchar(undefined2 param_1,undefined1 param_2)

{
  out(param_1,param_2);
  return param_2;
}



===== I8xControllerRoutine @ 1c0007c30 =====

undefined8 I8xControllerRoutine(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  longlong local_48;
  undefined1 *puStack_40;
  undefined8 local_38;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  local_res10 = 0;
  local_48 = 0;
  puStack_40 = (undefined1 *)0x0;
  local_38 = 0;
  *(int *)(lVar3 + 0x1a8) = *(int *)(lVar3 + 0x1a8) + 1;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  iVar1 = *(int *)(lVar4 + 0x18);
  if (iVar1 == 0xb0008) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = 10;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,10,0x40,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
    lVar4 = Globals;
    if (*(short *)(lVar3 + 0x2dc) == *(short *)(*(longlong *)(param_2 + 0x18) + 2)) {
      I8xCompletePendedRequest(param_1,param_2,param_3,0);
      return 1;
    }
    puStack_40 = (undefined1 *)(Globals + 200);
    local_38 = CONCAT44(local_38._4_4_,2);
    *puStack_40 = 0xed;
    *(undefined1 *)(lVar4 + 0xc9) = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 2);
    local_48 = param_1;
  }
  else if (iVar1 == 0xb0004) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,10,0x41,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
    puStack_40 = (undefined1 *)(Globals + 200);
    local_38 = CONCAT44(local_38._4_4_,2);
    *puStack_40 = 0xf3;
    local_48 = param_1;
    bVar5 = I8xConvertTypematicParameters
                      (*(ushort *)(*(longlong *)(param_2 + 0x18) + 2),
                       (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x18) + 4));
    puStack_40[1] = bVar5;
  }
  else {
    if ((iVar1 != 0xb3fc7) && (iVar1 != 0xf3fc7)) {
      if (iVar1 == 0xf3fff) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,10,0x45,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        I8xSendResetCommand(lVar3);
        return 1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_3 = 0xd;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xd,0x46,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
      }
LAB_1c0007d97:
      IoAcquireCancelSpinLock(local_res8);
      LOCK();
      *(undefined8 *)(param_2 + 0x68) = 0;
      UNLOCK();
      IoReleaseCancelSpinLock(local_res8[0]);
      I8xCompletePendedRequest(param_1,param_2,param_3,uVar6);
      return 1;
    }
    uVar2 = *(uint *)(lVar4 + 0x10);
    if (uVar2 < 5) {
      puStack_40 = (undefined1 *)(Globals + 200);
    }
    else {
      param_3 = 0x32343038;
      puStack_40 = (undefined1 *)ExAllocatePool2(0x40,(ulonglong)uVar2);
      if (puStack_40 == (undefined1 *)0x0) {
        uVar6 = 0xc000009a;
        puStack_40 = (undefined1 *)0x0;
        goto LAB_1c0007d97;
      }
    }
    local_48 = param_1;
    memcpy(puStack_40,*(void **)(lVar4 + 0x20),(ulonglong)uVar2);
    local_38 = CONCAT44(local_38._4_4_,uVar2);
  }
  KeSynchronizeExecution(*(undefined8 *)(lVar3 + 8),I8xInitiateOutputWrapper,&local_48);
  local_res10 = 0xffffffffff676980;
  KeSetTimer(Globals + 0x78,0xffffffffff676980,lVar3 + 0x128);
  return 1;
}



===== I8xCompletePendedRequest @ 1c0007f50 =====

void I8xCompletePendedRequest
               (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  IofCompleteRequest(param_2,6);
  IoFreeController(*(undefined8 *)(Globals + 8));
  IoStartNextPacket(param_1,0);
  IoReleaseRemoveLockEx(lVar1 + 0x28,param_2,0x20);
  return;
}



===== I8xConvertTypematicParameters @ 1c0008020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte I8xConvertTypematicParameters(ushort param_1,ulonglong param_2)

{
  byte bVar1;
  undefined1 auStackY_68 [32];
  byte local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38[0] = 0x1f;
  local_38[1] = 0x1f;
  local_38[2] = 0x1c;
  local_38[3] = 0x1a;
  local_38[4] = 0x17;
  local_38[5] = 0x14;
  local_38[6] = 0x12;
  local_38[7] = 0x11;
  local_38[8] = 0xf;
  local_38[9] = 0xd;
  local_38[10] = 0xc;
  local_38[0xb] = 0xb;
  local_38[0xc] = 10;
  local_38[0xd] = 9;
  local_38[0xe] = 9;
  local_38[0xf] = 8;
  local_38[0x10] = 7;
  local_38[0x11] = 6;
  local_38[0x12] = 5;
  local_38[0x13] = 4;
  local_38[0x14] = 4;
  local_38[0x15] = 3;
  local_38[0x16] = 3;
  local_38[0x17] = 2;
  local_38[0x18] = 2;
  local_38[0x19] = 1;
  local_38[0x1a] = 1;
  local_38[0x1b] = 1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x1f,
                     &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
  }
  bVar1 = ((char)((param_2 & 0xffff) / 0xfa) + -1) * ' ';
  if (param_1 < 0x1c) {
    bVar1 = bVar1 | local_38[param_1];
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                     (param_2 & 0xffff) * 0x10624dd3 >> 0x20,3,0x20,
                     &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
  }
  return bVar1;
}



===== I8xPowerUpToD0Complete @ 1c0008130 =====

undefined8 I8xPowerUpToD0Complete(longlong param_1,undefined *param_2)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  longlong *plVar6;
  longlong lVar7;
  char *pcVar8;
  ulonglong uVar9;
  code *pcVar10;
  code *pcVar11;
  undefined8 uVar12;
  char cVar13;
  longlong lVar14;
  char cVar15;
  char local_res20;
  char local_48;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar12 = 0;
  bVar4 = false;
  bVar3 = false;
  local_res20 = '\0';
  pcVar10 = (code *)0x0;
  local_48 = '\0';
  lVar14 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar8 = "kb";
    if (*(char *)(lVar1 + 0x235) == '\0') {
      pcVar8 = "mouse";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"mouse",0x17,0x34,
                      &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar8);
  }
  plVar6 = (longlong *)ExAllocatePool2(0x40);
  if (plVar6 != (longlong *)0x0) {
    lVar7 = IoAllocateWorkItem(param_1);
    *plVar6 = lVar7;
    if (lVar7 == 0) {
      ExFreePoolWithTag(plVar6,0);
      plVar6 = (longlong *)0x0;
    }
  }
  bVar5 = KeAcquireSpinLockRaiseToDpc();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x17,0x35,
                      &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)DAT_1c0012204);
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    if (*(char *)(lVar1 + 0x235) == '\0') {
      DAT_1c0012204 = DAT_1c0012204 | 0x2000;
    }
    else {
      DAT_1c0012204 = DAT_1c0012204 | 0x200;
    }
  }
  else {
    *(undefined **)(lVar1 + 0x48) = param_2;
    uVar12 = 0xc0000016;
    if (*(char *)(lVar1 + 0x235) == '\0') {
      DAT_1c0012204 = DAT_1c0012204 | 0x1000;
    }
    else {
      DAT_1c0012204 = DAT_1c0012204 | 0x100;
    }
  }
  if ((DAT_1c0012204 & 2) == 0) {
    cVar13 = '\0';
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x16,0x36,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    }
    cVar13 = '\x01';
    local_res20 = '\x01';
  }
  if ((DAT_1c0012204 & 0x20) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x16,0x37,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      cVar13 = local_res20;
    }
    local_res20 = cVar13 + '\x01';
  }
  if ((DAT_1c0012204 & 0x100) == 0) {
    cVar13 = '\0';
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x16,0x38,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    }
    cVar13 = '\x01';
    local_48 = '\x01';
  }
  if ((DAT_1c0012204 & 0x1000) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x16,0x39,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      cVar13 = local_48;
    }
    cVar13 = cVar13 + '\x01';
    local_48 = cVar13;
  }
  if ((DAT_1c0012204 & 0x200) == 0) {
    cVar15 = '\0';
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x19,0x3a,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      cVar13 = local_48;
    }
    cVar15 = '\x01';
  }
  if ((DAT_1c0012204 & 0x2000) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x19,0x3b,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      cVar13 = local_48;
    }
    cVar15 = cVar15 + '\x01';
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    cVar13 = local_48;
  }
  uVar9 = (ulonglong)bVar5;
  if ((char)(cVar13 + cVar15) == local_res20) {
    if (cVar13 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x18,0x3e,
                          &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)DAT_1c0012204);
      }
      bVar2 = false;
    }
    else if ((cVar15 == '\0') || ((DAT_1c0012204 & 0x200) == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x18,0x3d,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      bVar2 = true;
    }
    else {
      bVar2 = false;
      pcVar10 = *(code **)(DAT_1c00121c8 + 0x48);
      *(undefined8 *)(DAT_1c00121c8 + 0x48) = 0;
      DAT_1c0012204 = DAT_1c0012204 & 0xffffefcf;
      if (pcVar10 == (code *)param_2) {
        uVar12 = 0xc0000001;
        *(undefined4 *)(pcVar10 + 0x30) = 0xc0000001;
      }
      else {
        bVar4 = true;
      }
    }
    if ((DAT_1c0012204 >> 0xc & 1) == 0) {
      DAT_1c0012204 = DAT_1c0012204 & 0xffffdfff;
    }
    else {
      pcVar10 = *(code **)(DAT_1c00121c8 + 0x48);
      *(undefined8 *)(DAT_1c00121c8 + 0x48) = 0;
      DAT_1c0012204 = DAT_1c0012204 & 0xffffefcf;
    }
    if ((DAT_1c0012204 >> 8 & 1) == 0) {
      DAT_1c0012204 = DAT_1c0012204 & 0xfffffdff;
    }
    else {
      lVar14 = *(longlong *)(DAT_1c00121d0 + 0x48);
      *(undefined8 *)(DAT_1c00121d0 + 0x48) = 0;
      DAT_1c0012204 = DAT_1c0012204 & 0xfffffefc;
    }
    bVar3 = bVar4;
    if ((plVar6 == (longlong *)0x0) || (!bVar2)) {
LAB_1c000873d:
      pcVar11 = (code *)(ulonglong)bVar5;
      KeReleaseSpinLock(Globals + 0xc0);
      if (!bVar2) goto LAB_1c0008915;
      if (plVar6 == (longlong *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x41,
                           &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
        }
        if (pcVar10 != (code *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x42,
                              &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)pcVar10);
          }
          *(undefined4 *)(pcVar10 + 0x30) = 0xc000009a;
          *(undefined8 *)(pcVar10 + 0x38) = 0;
          PoStartNextPowerIrp(pcVar10);
          IofCompleteRequest(pcVar10,0);
          IoReleaseRemoveLockEx(DAT_1c00121c8 + 0x28,pcVar10,0x20);
          pcVar11 = pcVar10;
        }
        if (lVar14 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x43,
                              &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)lVar14);
          }
          *(undefined4 *)(lVar14 + 0x30) = 0xc000009a;
          *(undefined8 *)(lVar14 + 0x38) = 0;
          PoStartNextPowerIrp(lVar14);
          IofCompleteRequest(lVar14,0);
          IoReleaseRemoveLockEx(DAT_1c00121d0 + 0x28,lVar14,0x20);
        }
        return 0xc0000016;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar5,0x18,0x40,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      pcVar11 = (code *)(ulonglong)bVar5;
      DAT_1c0012204 = DAT_1c0012204 | 0x10000000;
      KeReleaseSpinLock(Globals + 0xc0);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x18,0x44,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    }
    pcVar11 = I8xReinitializeHardware;
    plVar6[2] = lVar14;
    plVar6[1] = (longlong)pcVar10;
    IoQueueWorkItem(*plVar6,I8xReinitializeHardware,1,plVar6);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      bVar2 = false;
      bVar3 = bVar4;
      goto LAB_1c000873d;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x18,0x3f,
                     &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    pcVar11 = (code *)(ulonglong)bVar5;
    KeReleaseSpinLock(Globals + 0xc0);
LAB_1c0008915:
    if (plVar6 != (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x16,0x45,
                          &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)plVar6);
      }
      IoFreeWorkItem(*plVar6);
      pcVar11 = (code *)0x0;
      ExFreePoolWithTag(plVar6);
    }
  }
  if (bVar3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x46,
                        &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)pcVar10);
    }
    PoStartNextPowerIrp(pcVar10);
    IofCompleteRequest(pcVar10,0);
    IoReleaseRemoveLockEx(DAT_1c00121c8 + 0x28,pcVar10,0x20);
    pcVar11 = pcVar10;
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x47,
                        &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)param_2);
    }
    PoStartNextPowerIrp(param_2);
  }
  return uVar12;
}



===== WPP_RECORDER_SF_sD @ 1c0008a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
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
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pcVar3,lVar2,&param_7,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_6[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar1,&param_7,4,0);
  return;
}



===== I8xStartIo @ 1c0008be0 =====

void I8xStartIo(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  lVar3 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xb,0x3d,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar1 = *(int *)(lVar2 + 0x18);
  if ((((iVar1 == 0xf3fff) || (iVar1 == 0xb0004)) || (iVar1 == 0xb0008)) ||
     ((iVar1 == 0xb3fc7 || (iVar1 == 0xf3fc7)))) {
    IoAllocateController(*(undefined8 *)(Globals + 8),param_1,I8xControllerRoutine,0);
    param_2 = param_1;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,0xd,0x3e,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
    lVar3 = *(longlong *)(param_1 + 0x40);
    uVar6 = 0xc0000010;
    uVar4 = 0xc005000d;
    if (*(char *)(lVar3 + 0x235) == '\0') {
      uVar4 = 0xc0050033;
    }
    uVar5 = 0;
    I8xLogError(param_1,(int)uVar4,0,0xc0000010,(undefined4 *)0x0,0);
    TraceLoggingInvalidStartIoRequest((ulonglong)*(uint *)(lVar2 + 0x18),uVar4,uVar5,uVar6);
    IoAcquireCancelSpinLock(local_res10);
    LOCK();
    *(undefined8 *)(param_2 + 0x68) = 0;
    UNLOCK();
    IoReleaseCancelSpinLock(local_res10[0]);
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    IoStartNextPacket(param_1,0);
    IoReleaseRemoveLockEx(lVar3 + 0x28,param_2,0x20);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xb,0x3f,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_qDD @ 1c0008dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x47,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,0xc,&WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x47,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== I8xSetPowerFlag @ 1c0008ed0 =====

void I8xSetPowerFlag(uint param_1,char param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(Globals + 0xc0);
  if (param_2 == '\0') {
    DAT_1c0012204 = DAT_1c0012204 & ~param_1;
  }
  else {
    DAT_1c0012204 = DAT_1c0012204 | param_1;
  }
  KeReleaseSpinLock(Globals + 0xc0,uVar1);
  return;
}



===== I8xCheckPowerFlag @ 1c0008f40 =====

bool I8xCheckPowerFlag(void)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(Globals + 0xc0);
  uVar1 = DAT_1c0012204 & 0x10000000;
  KeReleaseSpinLock(Globals + 0xc0,uVar2);
  return uVar1 != 0;
}



===== __report_gsfailure @ 1c0008fb0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c0008fbd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0008fbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== I8042ErrorLogDpc @ 1c0008fd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void I8042ErrorLogDpc(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  longlong lVar5;
  byte *pbVar6;
  longlong lVar7;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  undefined8 local_50 [4];
  undefined4 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar5 = param_2;
  lVar7 = param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    lVar7 = 0x1a;
    param_3 = 7;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x1a,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  pbVar6 = (byte *)CONCAT71((int7)((ulonglong)lVar5 >> 8),0x38);
  puVar1 = (undefined2 *)IoAllocateErrorLogEntry();
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[1] = 8;
    if (param_4 == 0x4005000b) {
      *(undefined4 *)(puVar1 + 8) = 0x51e;
      *(undefined4 *)(puVar1 + 0x14) = 0xc;
      uVar3 = *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 700);
    }
    else if (param_4 == 0x4005000c) {
      *(undefined4 *)(puVar1 + 8) = 0x528;
      *(undefined4 *)(puVar1 + 0x14) = 0x18;
      uVar3 = *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x250);
    }
    else {
      *(undefined4 *)(puVar1 + 0x14) = 0;
      uVar3 = 0;
      *(undefined4 *)(puVar1 + 8) = 0x532;
    }
    *(undefined4 *)(puVar1 + 0x16) = uVar3;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 0xe) = 0;
    *(undefined4 *)(puVar1 + 10) = 0;
    *(int *)(puVar1 + 6) = (int)param_4;
    puVar4 = puVar1;
    IoWriteErrorLogEntry();
    if ((param_4 == 0x4005000b) || (param_4 == 0x4005000c)) {
      if ((DAT_1c0012010 < 6) || (uVar2 = _tlgKeywordOn(), (char)uVar2 == '\0')) goto LAB_1c0009146;
      pbVar6 = &DAT_1c000fe33;
    }
    else {
      if ((DAT_1c0012010 < 6) || (uVar2 = _tlgKeywordOn(), (char)uVar2 == '\0')) goto LAB_1c0009146;
      pbVar6 = &DAT_1c000fdbf;
    }
    local_58[0] = *(undefined4 *)(puVar1 + 6);
    local_24 = 0;
    local_30 = local_58;
    local_28 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(puVar4,pbVar6,param_3,lVar7,3,local_50);
  }
LAB_1c0009146:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar6,7,0x1b,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return;
}



===== I8042RetriesExceededDpc @ 1c00091a0 =====

void I8042RetriesExceededDpc
               (undefined8 param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  ulonglong uVar9;
  
  uVar9 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0;
    uVar9 = 7;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x3b,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar3 = *(longlong *)(param_2 + 0x40);
  *(undefined4 *)(param_3 + 0x30) = 0xc00000b5;
  if (DAT_1c0012247 == '\x01') {
    uVar7 = *(uint *)(lVar3 + 0x20c);
    if (0x30 < uVar7) {
      uVar7 = 0x30;
    }
    puVar5 = (undefined1 *)IoAllocateErrorLogEntry(param_2);
    KeAcquireSpinLockAtDpcLevel(Globals + 0xb8);
    if (puVar5 != (undefined1 *)0x0) {
      cVar2 = *(char *)(lVar3 + 0x235);
      *(short *)(puVar5 + 2) = (short)uVar7 << 2;
      *(uint *)(puVar5 + 0xc) = (-(uint)(cVar2 != '\0') & 0xffffffe5) + 0xc0050035;
      *(undefined4 *)(puVar5 + 0x18) = *(undefined4 *)(lVar3 + 0x1a8);
      puVar4 = *(undefined1 **)(param_3 + 0xb8);
      *puVar5 = *puVar4;
      *(undefined4 *)(puVar5 + 0x1c) = *(undefined4 *)(puVar4 + 0x18);
      puVar5[1] = *(undefined1 *)(lVar3 + 0x230);
      *(undefined4 *)(puVar5 + 0x10) = 0x4ba;
      *(undefined4 *)(puVar5 + 0x14) = *(undefined4 *)(param_3 + 0x30);
      if (uVar7 != 0) {
        lVar6 = 0;
        uVar9 = (ulonglong)uVar7;
        puVar8 = (uint *)(puVar5 + 0x28);
        do {
          pbVar1 = (byte *)(*(longlong *)(lVar3 + 0x200) + lVar6);
          lVar6 = lVar6 + 1;
          *puVar8 = (uint)*pbVar1;
          puVar8 = puVar8 + 1;
          uVar9 = uVar9 - 1;
          param_4 = 0;
        } while (uVar9 != 0);
      }
      IoWriteErrorLogEntry(puVar5);
      uVar9 = (ulonglong)*(uint *)(puVar5 + 0x1c);
      TraceLoggingRetriesExceeded
                ((ulonglong)*(uint *)(puVar5 + 0x14),*puVar5,uVar9,
                 CONCAT71((int7)((ulonglong)param_4 >> 8),puVar5[1]));
    }
  }
  else {
    KeAcquireSpinLockAtDpcLevel(Globals + 0xb8);
  }
  lVar6 = *(longlong *)(lVar3 + 0x200);
  if ((lVar6 != 0) && (lVar6 != Globals + 200)) {
    ExFreePoolWithTag(lVar6,0);
  }
  *(undefined8 *)(lVar3 + 0x200) = 0;
  KeReleaseSpinLockFromDpcLevel(Globals + 0xb8);
  I8xCompletePendedRequest(param_2,param_3,uVar9,0xc00000b5);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,7,0x3c,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return;
}



===== I8042TimeOutDpc @ 1c00093c0 =====

void I8042TimeOutDpc(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  longlong lVar6;
  longlong lVar7;
  uint *puVar8;
  undefined2 uVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 local_res10 [8];
  longlong local_30;
  longlong local_28;
  undefined8 local_20;
  
  local_20 = 0;
  local_res10[0] = 0;
  lVar6 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0x48;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,7,0x48,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar3 = *(longlong *)(param_2 + 0x40);
  IoAcquireCancelSpinLock(local_res10);
  lVar7 = *(longlong *)(param_2 + 0x20);
  if (lVar7 == 0) {
    IoReleaseCancelSpinLock(local_res10[0]);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar9 = 0x49;
    lVar7 = lVar6;
  }
  else {
    LOCK();
    *(undefined8 *)(lVar7 + 0x68) = 0;
    UNLOCK();
    IoReleaseCancelSpinLock(local_res10[0]);
    puVar8 = (uint *)&local_30;
    local_28 = Globals + 0xcc;
    local_30 = param_2;
    KeSynchronizeExecution(*(undefined8 *)(lVar3 + 8),I8xDecrementTimer);
    if ((int)local_20 == 0) {
      *(undefined8 *)(lVar7 + 0x38) = 0;
      *(undefined4 *)(lVar7 + 0x30) = 0xc00000b5;
      if (DAT_1c0012247 == '\x01') {
        uVar11 = *(uint *)(lVar3 + 0x20c);
        if (0x30 < uVar11) {
          uVar11 = 0x30;
        }
        puVar5 = (undefined1 *)IoAllocateErrorLogEntry(param_2);
        KeAcquireSpinLockAtDpcLevel(Globals + 0xb8);
        if (puVar5 != (undefined1 *)0x0) {
          cVar2 = *(char *)(lVar3 + 0x235);
          *(short *)(puVar5 + 2) = (short)uVar11 << 2;
          *(uint *)(puVar5 + 0xc) = (-(uint)(cVar2 != '\0') & 0xffffffe5) + 0xc0050036;
          *(undefined4 *)(puVar5 + 0x18) = *(undefined4 *)(lVar3 + 0x1a8);
          puVar4 = *(undefined1 **)(lVar7 + 0xb8);
          *puVar5 = *puVar4;
          *(undefined4 *)(puVar5 + 0x1c) = *(undefined4 *)(puVar4 + 0x18);
          puVar5[1] = *(undefined1 *)(lVar3 + 0x230);
          *(undefined4 *)(puVar5 + 0x10) = 0x5a;
          *(undefined4 *)(puVar5 + 0x14) = 0xc00000b5;
          if (uVar11 != 0) {
            lVar6 = 0;
            uVar10 = (ulonglong)uVar11;
            puVar8 = (uint *)(puVar5 + 0x28);
            do {
              pbVar1 = (byte *)(*(longlong *)(lVar3 + 0x200) + lVar6);
              lVar6 = lVar6 + 1;
              *puVar8 = (uint)*pbVar1;
              puVar8 = puVar8 + 1;
              uVar10 = uVar10 - 1;
              param_4 = 0;
            } while (uVar10 != 0);
          }
          IoWriteErrorLogEntry(puVar5);
          TraceLoggingTimeout(*puVar5,*(uint *)(puVar5 + 0x1c),puVar8,param_4);
        }
      }
      else {
        KeAcquireSpinLockAtDpcLevel(Globals + 0xb8);
      }
      lVar6 = *(longlong *)(lVar3 + 0x200);
      if ((lVar6 != 0) && (lVar6 != Globals + 200)) {
        ExFreePoolWithTag(lVar6,0);
      }
      *(undefined8 *)(lVar3 + 0x200) = 0;
      KeReleaseSpinLockFromDpcLevel(Globals + 0xb8);
      I8xCompletePendedRequest(param_2,lVar7,puVar8,*(undefined4 *)(lVar7 + 0x30));
    }
    else {
      lVar7 = -10000000;
      KeSetTimer(Globals + 0x78,0xffffffffff676980,lVar3 + 0x128);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar9 = 0x4a;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,7,uVar9,
                   &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  return;
}



===== I8xCheckDpcWatchdogLimit @ 1c00096ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool I8xCheckDpcWatchdogLimit(void)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = KeQueryDpcWatchdogInformation(&local_28);
  if (iVar1 < 0) {
    return false;
  }
  if ((int)local_28 == 0) {
    if ((int)uStack_20 == 0) {
      return false;
    }
  }
  else if ((int)uStack_20 == 0) goto LAB_1c000972e;
  if (uStack_20._4_4_ < (uint)((int)uStack_20 * 0x19) / 100) {
    return true;
  }
LAB_1c000972e:
  if ((int)local_28 == 0) {
    return false;
  }
  return local_28._4_4_ < (uint)((int)local_28 * 0x14) / 100;
}



===== I8xDecrementTimer @ 1c0009760 =====

undefined8 I8xDecrementTimer(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*param_1 + 0x40);
  iVar1 = *(int *)param_1[1];
  if (iVar1 != -1) {
    *(int *)param_1[1] = iVar1 + -1;
  }
  *(int *)(param_1 + 2) = *(int *)param_1[1];
  if (*(int *)param_1[1] == 0) {
    *(undefined4 *)(lVar2 + 0x210) = 0;
    *(undefined2 *)(lVar2 + 0x230) = 0;
  }
  return 1;
}



===== I8xFlush @ 1c00097b0 =====

undefined8 I8xFlush(undefined8 param_1,undefined8 param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x1c,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x1d,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
  }
  return 0xc0000002;
}



===== I8xInitializeDataQueue @ 1c0009830 =====

void I8xInitializeDataQueue(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x55,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  if ((char)param_1[1] == '\x01') {
    lVar1 = *param_1;
    *(undefined4 *)(lVar1 + 0x5c) = 0;
    *(undefined8 *)(lVar1 + 0x370) = *(undefined8 *)(lVar1 + 0x368);
    *(undefined8 *)(lVar1 + 0x378) = *(undefined8 *)(lVar1 + 0x368);
    *(undefined1 *)(lVar1 + 0x232) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar2 = 0x56;
  }
  else {
    if ((char)param_1[1] != '\x02') goto LAB_1c0009908;
    lVar1 = *param_1;
    *(undefined4 *)(lVar1 + 0x5c) = 0;
    *(undefined8 *)(lVar1 + 0x3b8) = *(undefined8 *)(lVar1 + 0x3b0);
    *(undefined8 *)(lVar1 + 0x3c0) = *(undefined8 *)(lVar1 + 0x3b0);
    *(undefined1 *)(lVar1 + 0x232) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar2 = 0x57;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,4,uVar2,
                   &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
LAB_1c0009908:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,3,0x58,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  return;
}



===== I8xLogError @ 1c0009948 =====

void I8xLogError(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,uint param_6)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined4 in_register_00000014;
  ulonglong uVar3;
  
  puVar1 = (undefined2 *)
           IoAllocateErrorLogEntry
                     (param_1,CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),
                                       ((char)param_6 + '\f') * '\x04'));
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar1 + 6) = param_2;
    puVar1[1] = (short)param_6 << 2;
    *(undefined8 *)(puVar1 + 0xc) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 8) = param_3;
    *(undefined4 *)(puVar1 + 10) = param_4;
    if (param_6 != 0) {
      uVar3 = (ulonglong)param_6;
      puVar2 = param_5;
      do {
        *(undefined4 *)((longlong)puVar1 + (0x28 - (longlong)param_5) + (longlong)puVar2) = *puVar2;
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== I8xReadRegisterUchar @ 1c00099f0 =====

undefined1 I8xReadRegisterUchar(undefined1 *param_1)

{
  return *param_1;
}



===== I8xSendIoctl @ 1c0009a00 =====

int I8xSendIoctl(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest(param_2,param_1,param_3,param_4,0,0,1,&local_28,&local_38);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,0xc,0x1e,
                         &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,(char)param_2,(char)iVar1)
      ;
    }
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
  }
  return iVar1;
}



===== I8xWriteRegisterUchar @ 1c0009b30 =====

void I8xWriteRegisterUchar(undefined1 *param_1,undefined1 param_2)

{
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== TraceLoggingInvalidStartIoRequest @ 1c0009b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingInvalidStartIoRequest
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000fd69,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingRetriesExceeded @ 1c0009bb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingRetriesExceeded
               (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_88;
  undefined1 local_87 [3];
  undefined4 local_84;
  undefined4 local_80 [2];
  undefined8 local_78 [4];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  uVar2 = (undefined1)param_4;
  uVar3 = (undefined7)((ulonglong)param_4 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    local_80[0] = (undefined4)param_3;
    if ((char)uVar1 != '\0') {
      local_58 = &local_84;
      local_84 = (undefined4)param_1;
      local_48 = &local_88;
      local_50 = 4;
      local_38 = local_80;
      local_28 = local_87;
      local_40 = 1;
      local_30 = 4;
      local_20 = 1;
      local_88 = param_2;
      local_87[0] = uVar2;
      _tlgWriteTransfer_EtwWriteTransfer
                (param_1,&DAT_1c000fded,param_3,CONCAT71(uVar3,uVar2),6,local_78);
    }
  }
  return;
}



===== TraceLoggingTimeout @ 1c0009c74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingTimeout(undefined1 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStackY_98 [32];
  undefined1 local_68 [4];
  undefined4 local_64 [3];
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_2c = 0;
      local_38 = local_68;
      local_1c = 0;
      local_28 = local_64;
      local_30 = 1;
      local_64[0] = (undefined4)uVar2;
      local_20 = 4;
      local_68[0] = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_1c000fd96,uVar2,param_4,4,local_58);
    }
  }
  return;
}



===== WPP_RECORDER_SF_sd @ 1c0009d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    if (param_6 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_6[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,param_4,pcVar1,lVar3,&param_7,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,param_4,param_6,
                  lVar2,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_sdDD @ 1c0009e50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdDD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x62,pcVar1,lVar3,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,0x62,
                  in_stack_00000030,lVar2,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== TraceLoggingDriverLoaded @ 1c0009fd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingDriverLoaded
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000fe5b,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingTransmitControllerCommandFailed @ 1c000a050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingTransmitControllerCommandFailed
               (undefined1 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined7 uVar2;
  undefined1 auStackY_98 [32];
  undefined1 local_68;
  undefined1 local_67 [15];
  undefined8 local_58 [4];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_2c = 0;
      local_38 = &local_68;
      local_1c = 0;
      local_28 = local_67;
      local_30 = 1;
      local_20 = 1;
      local_68 = param_1;
      local_67[0] = param_2;
      _tlgWriteTransfer_EtwWriteTransfer
                (1,&DAT_1c000fe81,CONCAT71(uVar2,param_2),param_4,4,local_58);
    }
  }
  return;
}



===== WppClassicProviderCallback @ 1c000a0f0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 1c000a14c =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1c000a158 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1c001153f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1c000a184 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c000a2e0 =====

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



===== TraceLoggingDeviceNotConnected @ 1c000a364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingDeviceNotConnected
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000ff6e,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingResetCommandFailed @ 1c000a3dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingResetCommandFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000ff9a,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingResetResponseFailed @ 1c000a454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingResetResponseFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000ff41,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingSelectScansetFailed @ 1c000a4cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingSelectScansetFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000fec2,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingSetLedFailed @ 1c000a544 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingSetLedFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000feef,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingSetTypematicFailed @ 1c000a5bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingSetTypematicFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000ff15,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== WPP_RECORDER_SF_S @ 1c000a634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,pwVar2,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,param_6,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_SD @ 1c000a784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10000) != 0) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,pwVar2,lVar1,&param_7
               ,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,0,0x11,param_5,param_4,param_6,lVar3,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c000a8d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,0x54,L"PollStatusIterations",0x2a,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,0,0xe,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,0x54,
                  L"PollStatusIterations",0x2a,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_ddD @ 1c000a9a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,0x41,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,0x41,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_ssD @ 1c000aa90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,char *param_6,char *param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    if (param_7 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (param_7[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (param_6 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_6[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,pcVar1,lVar3,pcVar5,
               lVar4,&param_8,4,0);
  }
  if (param_7 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_7[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,0x10,param_5,param_4,param_6,lVar2,param_7,lVar4,&param_8,4,0);
  return;
}



===== I8xKeyboardRemoveDeviceInitialized @ 1c000ac3c =====

void I8xKeyboardRemoveDeviceInitialized(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x298);
  KeRemoveQueueDpc(param_1 + 600);
  lVar2 = *(longlong *)(param_1 + 0x250);
  *(undefined8 *)(param_1 + 0x250) = 0;
  if (lVar2 != 0) {
    if (*(char *)(lVar2 + 0x44) == '\0') {
      LOCK();
      lVar1 = *(longlong *)(lVar2 + 0x68);
      *(longlong *)(lVar2 + 0x68) = 0;
      UNLOCK();
      if (lVar1 != 0) goto LAB_1c000aca6;
    }
    lVar2 = 0;
  }
LAB_1c000aca6:
  KeReleaseSpinLock(param_1 + 0x298);
  if (lVar2 != 0) {
    I8xCompleteSysButtonIrp(lVar2,0,0xc0000056);
  }
  return;
}



===== TraceLoggingAllocateMemoryFailed @ 1c000acec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingAllocateMemoryFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000ffc6,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingConnectInterruptFailed @ 1c000ad64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingConnectInterruptFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c000fff1,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== WPP_RECORDER_SF_qDDDssDs @ 1c000addc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDssDs
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,char *param_10,char *param_11,undefined1 param_12,char *param_13)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  longlong lVar8;
  char *pcVar9;
  char *pcVar10;
  
  pcVar6 = param_13;
  pcVar5 = param_11;
  pcVar4 = param_10;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) != 0) {
    if (param_13 == (char *)0x0) {
      lVar8 = 5;
    }
    else {
      lVar7 = -1;
      do {
        lVar8 = lVar7;
        lVar7 = lVar8 + 1;
      } while (param_13[lVar7] != '\0');
      lVar8 = lVar8 + 2;
    }
    pcVar10 = param_13;
    if (param_13 == (char *)0x0) {
      pcVar10 = "NULL";
    }
    if (param_11 == (char *)0x0) {
      lVar7 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar7 = lVar3;
        lVar3 = lVar7 + 1;
      } while (param_11[lVar3] != '\0');
      lVar7 = lVar7 + 2;
    }
    pcVar9 = param_11;
    if (param_11 == (char *)0x0) {
      pcVar9 = "NULL";
    }
    if (param_10 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_10[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_10;
    if (param_10 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,&param_8,4,&param_9,4,pcVar1,lVar3,pcVar9,lVar7,&param_12,4,pcVar10,lVar8,0);
  }
  if (pcVar6 == (char *)0x0) {
    lVar8 = 5;
  }
  else {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (pcVar6[lVar7] != '\0');
    lVar8 = lVar8 + 2;
  }
  if (pcVar6 == (char *)0x0) {
    pcVar6 = "NULL";
  }
  if (pcVar5 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar7 = lVar3;
      lVar3 = lVar7 + 1;
    } while (pcVar5[lVar3] != '\0');
    lVar7 = lVar7 + 2;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "NULL";
  }
  lVar3 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (pcVar4[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,0,0xe,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,&param_9,4,pcVar4,
                  lVar2,pcVar5,lVar7,&param_12,4,pcVar6,lVar8,0);
  return;
}



===== I8xFinishResetRequest @ 1c000b0b4 =====

void I8xFinishResetRequest(undefined8 *param_1,undefined8 param_2,char param_3,char param_4)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  cVar2 = (char)param_2;
  LOCK();
  lVar1 = param_1[0x4b];
  param_1[0x4b] = 0;
  UNLOCK();
  if (param_4 != '\0') {
    KeCancelTimer(param_1 + 0x6c);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xc,0x58,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)lVar1);
  }
  if (param_3 != '\0') {
    uVar3 = KfRaiseIrql(2);
  }
  if ((cVar2 != '\0') && (DAT_1c0012247 != '\0')) {
    KeInsertQueueDpc(param_1 + 0x1d,0,0xffffffff80050012);
  }
  *(undefined1 *)(param_1 + 0x8a) = 0;
  IoFreeController(*(undefined8 *)(Globals + 8));
  IoStartNextPacket(*param_1,0);
  if (param_3 != '\0') {
    KeLowerIrql(uVar3);
  }
  if (lVar1 != 0) {
    IoFreeIrp(lVar1);
    IoReleaseRemoveLockEx(param_1 + 5,lVar1,0x20);
  }
  return;
}



===== I8xMouseEnableTransmission @ 1c000b208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I8xMouseEnableTransmission
                    (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStackY_98 [32];
  int local_68 [2];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50 [4];
  int *local_30;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = (undefined8 *)0x0;
    param_3 = 0;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x4d,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  local_60 = 0;
  uStack_58 = 0;
  if (*(char *)((longlong)param_1 + 0x3a2) != '\0') {
    param_4 = param_1 + 100;
    *(undefined1 *)((longlong)param_1 + 0x3a2) = 0;
    param_3 = 5000;
    KeSetTimerEx(param_1 + 0x6c,0xfffffffffd050f80,5000,param_4);
  }
  uVar8 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xf4);
  uVar7 = CONCAT71((int7)((ulonglong)param_3 >> 8),2);
  puVar6 = (undefined *)0x0;
  uVar5 = 0;
  uVar2 = I8xPutBytePolled('\0','\0','\x02',0xf4);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x4e;
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      uVar7 = 0x11;
      WPP_RECORDER_SF_D(uVar5,puVar6,0x11,0x4e,&WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,
                        (char)uVar2);
    }
    local_60 = 1;
    uStack_58 = 0xf4000000d4;
    if (5 < DAT_1c0012010) {
      uVar3 = _tlgKeywordOn();
      if ((char)uVar3 != '\0') {
        local_24 = 0;
        local_30 = local_68;
        puVar6 = &DAT_1c00100ae;
        local_28 = 4;
        local_68[0] = iVar1;
        _tlgWriteTransfer_EtwWriteTransfer(uVar5,&DAT_1c00100ae,uVar7,uVar8,3,local_50);
      }
    }
    puVar6 = (undefined *)CONCAT71((int7)((ulonglong)puVar6 >> 8),0x40);
    puVar4 = (undefined4 *)IoAllocateErrorLogEntry(*param_1);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4[3] = 0xc0050018;
      *puVar4 = 0x100000;
      puVar4[4] = 0x5c3;
      puVar4[5] = iVar1;
      puVar4[10] = (undefined4)local_60;
      puVar4[0xb] = local_60._4_4_;
      puVar4[0xc] = (undefined4)uStack_58;
      puVar4[0xd] = uStack_58._4_4_;
      IoWriteErrorLogEntry(puVar4);
    }
  }
  *(undefined1 *)((longlong)param_1 + 0x3f7) = 0;
  *(undefined4 *)(param_1 + 0x7d) = 4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,0xf,0x4f,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar2);
  }
  return uVar2 & 0xffffffff;
}



===== I8xResetMouse @ 1c000b400 =====

int I8xResetMouse(longlong *param_1,undefined8 param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  byte bVar5;
  longlong lVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar8;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  pbVar1 = (byte *)((longlong)param_1 + 0x3f4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar8 = 1;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xe,0x5a,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,*pbVar1);
  }
  iVar3 = 0;
  *pbVar1 = *pbVar1 + 1;
  bVar5 = *(char *)((longlong)param_1 + 0x3f5) + 1;
  lVar2 = *param_1;
  *(byte *)((longlong)param_1 + 0x3f5) = bVar5;
  if ((*pbVar1 < 3) && (bVar5 < 3)) {
    lVar4 = IoAllocateIrp(*(undefined1 *)(lVar2 + 0x4c),0);
    if (lVar4 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      LOCK();
      bVar7 = param_1[0x4b] == 0;
      if (bVar7) {
        param_1[0x4b] = lVar4;
      }
      UNLOCK();
      if (bVar7) {
        lVar6 = *(longlong *)(lVar4 + 0xb8);
        *(undefined1 *)(lVar6 + -0x48) = 0xf;
        *(undefined4 *)(lVar6 + -0x30) = 0xf3fff;
        *(char *)(lVar4 + 0x43) = *(char *)(lVar4 + 0x43) + -1;
        *(longlong *)(lVar4 + 0xb8) = *(longlong *)(lVar4 + 0xb8) + -0x48;
        lVar6 = lVar4;
        iVar3 = IoAcquireRemoveLockEx(param_1 + 5,lVar4,"",1,CONCAT44(uVar8,0x20));
        if (iVar3 < 0) {
          LOCK();
          lVar2 = param_1[0x4b];
          param_1[0x4b] = 0;
          UNLOCK();
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0x10,0x5d,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)lVar2);
          }
          if (lVar2 != 0) {
            IoFreeIrp(lVar2);
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0x10,0x5c,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)lVar4);
          }
          IoStartPacket(lVar2,lVar4,0,0);
        }
      }
      else {
        IoFreeIrp(lVar4);
        I8xSendResetCommand((longlong)param_1);
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x5b,
                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
    }
    I8xResetMouseFailed(param_1,param_2);
    iVar3 = -0x3fffff63;
  }
  return iVar3;
}



===== I8xResetMouseFailed @ 1c000b608 =====

void I8xResetMouseFailed(undefined8 *param_1,undefined8 param_2)

{
  undefined7 uVar1;
  
  uVar1 = (undefined7)((ulonglong)param_2 >> 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x59,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x74) = 0x44d;
  I8xFinishResetRequest(param_1,CONCAT71(uVar1,1),'\x01','\x01');
  return;
}



===== I8xSendResetCommand @ 1c000b670 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void I8xSendResetCommand(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  KeSetTimer(param_1 + 0x360,0xffffffffff1b1e40,param_1 + 800);
  *(undefined4 *)(param_1 + 0x3ec) = 0;
  *(undefined1 *)(param_1 + 0x3f7) = 0;
  *(undefined4 *)(param_1 + 1000) = 5;
  *(undefined1 *)(param_1 + 0x450) = 0;
  *(undefined8 *)(param_1 + 0x3f8) = _DAT_fffff78000000320;
  I8xPutBytePolled('\0','\0','\x02',0xff);
  return;
}



===== TraceLoggingSetResolutionFailed @ 1c000b6f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingSetResolutionFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c0010054,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== TraceLoggingSetSampleRateFailed @ 1c000b768 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TraceLoggingSetSampleRateFailed
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  if (5 < DAT_1c0012010) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c0010081,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== WPP_RECORDER_SF_dddddddd @ 1c000b7e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddddddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,99,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_1,0,0xe,&WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,99,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_ddddddddd @ 1c000b968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddddddddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0x62,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,0);
  }
  WppAutoLogTrace(param_1,0,0xe,&WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,0x62,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c000bb14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== I8xIsrResetDpc @ 1c000bc00 =====

void I8xIsrResetDpc(undefined8 param_1,undefined8 *param_2,int param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  if (param_3 == 0) {
    if (*(char *)((longlong)param_2 + 0x454) != '\0') {
      KeInitializeDpc(param_2 + 100,I8xMouseResetTimeoutProc,param_2);
      KeInitializeTimer(param_2 + 0x6c);
      *(undefined1 *)((longlong)param_2 + 0x454) = 0;
    }
    I8xResetMouseFromDpc(param_2,0);
  }
  else {
    puVar2 = param_2;
    lVar1 = IoAllocateWorkItem(*param_2);
    if (lVar1 == 0) {
      I8xResetMouseFailed(param_2,puVar2);
    }
    else {
      if (*(char *)((longlong)param_2 + 0x454) == '\0') {
        KeInitializeDpc(param_2 + 100,I8xMouseEnableDpc,param_2);
        KeInitializeTimerEx(param_2 + 0x6c,1);
        *(undefined1 *)((longlong)param_2 + 0x454) = 1;
      }
      IoQueueWorkItem(lVar1,I8xMouseInitializePolledWorker,1,lVar1);
    }
  }
  return;
}



===== I8xMouseEnableDpc @ 1c000bd00 =====

void I8xMouseEnableDpc(undefined8 param_1,undefined *param_2)

{
  char cVar1;
  code *pcVar2;
  undefined2 uVar3;
  
  if (param_2[0x3a3] == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bd80;
    uVar3 = 0x1e;
    pcVar2 = (code *)param_2;
  }
  else {
    pcVar2 = I8xMouseEnableSynchRoutine;
    cVar1 = KeSynchronizeExecution(*(undefined8 *)(param_2 + 8),I8xMouseEnableSynchRoutine,param_2);
    if (cVar1 != '\0') {
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000bd80;
    uVar3 = 0x1f;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar2,0xe,uVar3,
                   &WPP_43ac60d525913f552003ebac30591673_Traceguids);
LAB_1c000bd80:
  KeCancelTimer(param_2 + 0x360);
  return;
}



===== I8xMouseEnableSynchRoutine @ 1c000bda0 =====

ulonglong I8xMouseEnableSynchRoutine
                    (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined **ppuVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  *(short *)(param_1 + 0x74) = *(short *)(param_1 + 0x74) + 1;
  uVar3 = 0xf;
  if (*(ushort *)(param_1 + 0x74) < 0x10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = (undefined8 *)0x1d;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x1d,
                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
    }
    uVar2 = I8xMouseEnableTransmission(param_1,param_2,uVar3,param_4);
    uVar2 = (ulonglong)((byte)(uVar2 >> 0x1f) & 1 ^ 1);
  }
  else {
    ppuVar1 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar1 = (undefined **)
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x1c,
                                 &WPP_43ac60d525913f552003ebac30591673_Traceguids);
    }
    uVar2 = (ulonglong)ppuVar1 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== I8xMouseResetSynchRoutine @ 1c000be50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 I8xMouseResetSynchRoutine(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined2 uVar6;
  int iStackX_c;
  
  lVar1 = *param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_RAX = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xe,0x22,
                              &WPP_43ac60d525913f552003ebac30591673_Traceguids);
  }
  if (*(int *)(lVar1 + 1000) != 5) {
LAB_1c000c0c7:
    return in_RAX & 0xffffffffffffff00;
  }
  lVar5 = _DAT_fffff78000000320 - *(longlong *)(lVar1 + 0x3f8);
  uVar2 = KeQueryTimeIncrement();
  in_RAX = 10000000 / (ulonglong)uVar2;
  uVar2 = *(uint *)(lVar1 + 0x3ec);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0x4b1) {
    if (uVar2 != 0x4b0) {
      if ((int)uVar2 < 0x15) {
        if (uVar2 != 0x14) {
          if (uVar2 == 0) {
            if (*(byte *)(lVar1 + 0x450) == 0) {
              if ((lVar5 <= (longlong)in_RAX) ||
                 (*(undefined4 *)(param_1 + 1) = 1,
                 (undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
              goto LAB_1c000c02f;
              uVar6 = 0x23;
              uVar3 = 0;
            }
            else {
              uVar2 = *(byte *)(lVar1 + 0x450) - 0xfa;
              uVar3 = (ulonglong)uVar2;
              if (uVar2 != 0) {
                if (uVar2 == 4) {
                  if (*(short *)(lVar1 + 0x230) < 10) {
                    if ((longlong)in_RAX < lVar5) {
                      *(undefined4 *)(param_1 + 1) = 1;
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                      goto LAB_1c000bfe3;
                      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0x11,0x25,
                                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
                    }
                  }
                  else {
                    *(undefined4 *)(param_1 + 1) = 2;
                    *(undefined4 *)(lVar1 + 0x3a0) = 1;
                  }
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x11,0x26,
                                   &WPP_43ac60d525913f552003ebac30591673_Traceguids);
                }
                goto LAB_1c000bfe3;
              }
              if (lVar5 <= (longlong)in_RAX) goto LAB_1c000c02f;
              uVar4 = 0;
              I8xPutByteAsynchronous('\x01',0xd4);
              uVar3 = CONCAT71((int7)((ulonglong)uVar4 >> 8),0xf2);
              in_RAX = I8xPutByteAsynchronous('\0',uVar3);
              *(undefined4 *)(lVar1 + 0x3ec) = 2;
              *(undefined1 *)(lVar1 + 0x450) = 0;
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c000c02f;
              uVar6 = 0x24;
            }
            in_RAX = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x11,uVar6,
                                      &WPP_43ac60d525913f552003ebac30591673_Traceguids);
            goto LAB_1c000c02f;
          }
          uVar3 = (ulonglong)(uVar2 - 0xc);
          if (((uVar2 - 0xc == 0) || (uVar3 = (ulonglong)(uVar2 - 0xd), uVar2 - 0xd == 0)) ||
             (uVar3 = (ulonglong)(uVar2 - 0xe), uVar2 - 0xe == 0)) {
            if ((longlong)in_RAX < lVar5) {
              uVar3 = CONCAT71((int7)(uVar3 >> 8),0xd4);
              I8xPutByteAsynchronous('\x01',uVar3);
              in_RAX = I8xPutByteAsynchronous('\0',CONCAT71((int7)(uVar3 >> 8),0xe8));
              *(undefined4 *)(lVar1 + 0x3ec) = 4;
            }
            goto LAB_1c000c02f;
          }
          uVar2 = uVar2 - 0x12;
          goto LAB_1c000c10d;
        }
      }
      else {
        uVar3 = (ulonglong)(uVar2 - 0x15);
        if (((uVar2 - 0x15 != 0) && (uVar3 = (ulonglong)(uVar2 - 0x16), uVar2 - 0x16 != 0)) &&
           (uVar3 = (ulonglong)(uVar2 - 0x17), uVar2 - 0x17 != 0)) {
          uVar2 = uVar2 - 0x18;
          uVar3 = (ulonglong)uVar2;
          if (uVar2 != 0) {
            if (uVar2 == 0x434) goto LAB_1c000c0c7;
            goto LAB_1c000bfe3;
          }
        }
      }
    }
  }
  else {
    in_RAX = 0x514;
    if (0x514 < (int)uVar2) {
LAB_1c000bfe3:
      uVar2 = KeQueryTimeIncrement();
      in_RAX = 30000000 / (ulonglong)uVar2;
      if ((longlong)in_RAX < lVar5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_RAX = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                    30000000 % (ulonglong)uVar2,0x11,0x27,
                                    &WPP_43ac60d525913f552003ebac30591673_Traceguids);
        }
        *(undefined4 *)(param_1 + 1) = 1;
      }
      goto LAB_1c000c02f;
    }
    if (uVar2 == 0x514) goto LAB_1c000c0c7;
    in_RAX = 0x4b6;
    if ((int)uVar2 < 0x4b7) {
      if (uVar2 == 0x4b6) goto LAB_1c000c118;
      uVar2 = uVar2 - 0x4b1;
    }
    else {
      uVar2 = uVar2 - 0x4b7;
    }
    uVar3 = (ulonglong)uVar2;
    if (((uVar2 != 0) && (uVar3 = (ulonglong)(uVar2 - 1), uVar2 - 1 != 0)) &&
       (uVar3 = (ulonglong)(uVar2 - 2), uVar2 - 2 != 0)) {
      uVar2 = uVar2 - 3;
LAB_1c000c10d:
      uVar3 = (ulonglong)uVar2;
      if ((uVar2 != 0) && (uVar2 != 1)) goto LAB_1c000bfe3;
    }
  }
LAB_1c000c118:
  if ((*(uint *)(lVar1 + 0x404) <= (uint)lVar5) ||
     (iStackX_c = (int)((ulonglong)lVar5 >> 0x20), iStackX_c != 0)) {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),0xd4);
    *(undefined1 *)(lVar1 + 0x452) = 0;
    I8xPutByteAsynchronous('\x01',uVar3);
    in_RAX = I8xPutByteAsynchronous('\0',CONCAT71((int7)(uVar3 >> 8),0xf2));
    *(undefined4 *)(lVar1 + 0x3ec) = 0x1b;
  }
LAB_1c000c02f:
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== I8xMouseResetTimeoutProc @ 1c000c170 =====

void I8xMouseResetTimeoutProc(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *local_18;
  int local_10;
  undefined4 local_c;
  
  local_c = 0;
  if (*(int *)(param_2 + 0x74) == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x20,
                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
    }
  }
  else {
    if (*(int *)(param_2 + 0x74) == 0x44d) {
      return;
    }
    local_10 = 0;
    local_18 = param_2;
    cVar1 = KeSynchronizeExecution(param_2[1],I8xMouseResetSynchRoutine,&local_18);
    if (cVar1 == '\0') {
      return;
    }
    if (local_10 == 0) {
      uVar2 = 0xffffffffff1b1e40;
      KeSetTimer(param_2 + 0x6c,0xffffffffff1b1e40,param_2 + 100);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0xe,0x21,
                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
      return;
    }
    if (local_10 != 1) {
      if (local_10 == 2) {
        KeSetTimer(param_2 + 0x6c,0xffffffffff676980,param_2 + 100);
        return;
      }
      return;
    }
  }
  I8xResetMouseFromDpc(param_2,0x578);
  return;
}



===== I8xResetMouseFromDpc @ 1c000c2a4 =====

bool I8xResetMouseFromDpc(undefined8 *param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = param_2;
  lVar1 = IoAllocateWorkItem(*param_1);
  if (lVar1 == 0) {
    I8xResetMouseFailed(param_1,uVar2);
  }
  else {
    *(int *)(param_1 + 0x7e) = (int)param_2;
    IoQueueWorkItem(lVar1,I8xMouseInitializeInterruptWorker,1,lVar1);
  }
  return lVar1 != 0;
}



===== I8xVerifyMousePnPID @ 1c000c31c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I8xVerifyMousePnPID(longlong param_1,longlong param_2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  longlong lVar5;
  longlong lVar4;
  wchar_t *pwVar6;
  short *psVar7;
  wchar_t local_d8 [96];
  ulonglong local_18;
  
  pwVar6 = local_d8;
  local_18 = __security_cookie ^ (ulonglong)local_d8;
  builtin_wcsncpy(local_d8,L"MSH0002",8);
  builtin_wcsncpy(local_d8 + 8,L"MSH0005",8);
  builtin_wcsncpy(local_d8 + 0x10,L"MSH001F",8);
  builtin_wcsncpy(local_d8 + 0x18,L"MSH0020",8);
  builtin_wcsncpy(local_d8 + 0x20,L"MSH002A",8);
  builtin_wcsncpy(local_d8 + 0x28,L"MSH0030",8);
  builtin_wcsncpy(local_d8 + 0x30,L"MSH0031",8);
  psVar7 = *(short **)(param_1 + 0x410);
  builtin_wcsncpy(local_d8 + 0x38,L"MSH003A",8);
  builtin_wcsncpy(local_d8 + 0x40,L"MSH0041",8);
  builtin_wcsncpy(local_d8 + 0x48,L"MSH0043",8);
  builtin_wcsncpy(local_d8 + 0x50,L"MSH0044",8);
  local_d8[0x58] = L'\0';
  local_d8[0x59] = L'\0';
  if (psVar7 != (short *)0x0) {
    for (; *psVar7 != 0; psVar7 = psVar7 + lVar5 + 2) {
      psVar3 = psVar7;
      do {
        sVar1 = *psVar3;
        sVar2 = *(short *)((longlong)psVar3 + (param_2 - (longlong)psVar7));
        if (sVar1 != sVar2) break;
        psVar3 = psVar3 + 1;
      } while (sVar2 != 0);
      if (sVar1 == sVar2) goto LAB_1c000c449;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (psVar7[lVar4] != 0);
    }
  }
  do {
    if (*pwVar6 == 0) {
      return (ulonglong)pwVar6 & 0xffffffffffffff00;
    }
    psVar7 = pwVar6;
    do {
      sVar1 = *psVar7;
      sVar2 = *(short *)((longlong)psVar7 + (param_2 - (longlong)pwVar6));
      if (sVar1 != sVar2) break;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    psVar3 = pwVar6;
    if (sVar1 == sVar2) {
LAB_1c000c449:
      return CONCAT71((int7)((ulonglong)psVar3 >> 8),1);
    }
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (pwVar6[lVar4] != 0);
    pwVar6 = pwVar6 + lVar5 + 2;
  } while( true );
}



===== WPP_RECORDER_SF_Dddd @ 1c000c470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_43ac60d525913f552003ebac30591673_Traceguids,0xe,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,0,0x11,&WPP_43ac60d525913f552003ebac30591673_Traceguids,0xe,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== I8xPnPComplete @ 1c000c580 =====

undefined8 I8xPnPComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== I8xPnPStartComplete @ 1c000c5b0 =====

undefined8 I8xPnPStartComplete(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0xc,
                     &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
  }
  if (*(char *)(lVar1 + 0x235) == '\0') {
    param_3[1] = param_2;
  }
  else {
    param_3[2] = param_2;
  }
  IoQueueWorkItem(*param_3,I8xStartDeviceCallback,1,param_3);
  return 0xc0000016;
}



===== WPP_RECORDER_SF_DDDD @ 1c000c650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,param_4,&param_6,4
                  ,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_DDd @ 1c000c758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x1b,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x1b,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_ddd @ 1c000c840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddd(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x22,local_18,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x22,local_18,4,
                  &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_dddD @ 1c000c92c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x3c,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,0,0x18,&WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x3c,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 1c000ca34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x8000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x12,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,0,0x10,&WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,0x12,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== I8xCompleteSysButtonIrp @ 1c000cb00 =====

void I8xCompleteSysButtonIrp(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  **(undefined4 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 0x38) = 4;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  IofCompleteRequest(param_1,0);
  return;
}



===== I8xKeyboardGetSysButtonEvent @ 1c000cb80 =====

int I8xKeyboardGetSysButtonEvent(undefined8 *param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x19,0xf,
                       &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000206;
    IofCompleteRequest(param_2,0);
    return -0x3ffffdfa;
  }
  if (*(char *)((longlong)param_1 + 0x249) != '\0') {
    pcVar6 = (code *)0x18;
    iVar7 = -0x3fffff66;
    plVar4 = (longlong *)ExAllocatePool2(0x40,0x18,0x32343038);
    if (plVar4 != (longlong *)0x0) {
      lVar5 = IoAllocateWorkItem(*param_1);
      *plVar4 = lVar5;
      if (lVar5 == 0) {
        pcVar6 = (code *)0x0;
        ExFreePoolWithTag(plVar4);
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,0x16,0x10,
                           &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        }
        pcVar6 = I8xCompleteSysButtonEventWorker;
        *(uint *)(plVar4 + 1) = (uint)*(byte *)((longlong)param_1 + 0x249);
        plVar4[2] = param_2;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        IoQueueWorkItem(*plVar4,I8xCompleteSysButtonEventWorker,1,plVar4);
        iVar7 = 0x103;
      }
    }
    *(undefined1 *)((longlong)param_1 + 0x249) = 0;
    goto LAB_1c000cde0;
  }
  lVar5 = param_2;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x53);
  if (param_1[0x4a] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,0x18,0x12,
                       &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
    }
    param_1[0x4a] = param_2;
    LOCK();
    *(code **)(param_2 + 0x68) = I8xSysButtonCancelRoutine;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) != '\0') {
      LOCK();
      lVar2 = *(longlong *)(param_2 + 0x68);
      *(longlong *)(param_2 + 0x68) = 0;
      UNLOCK();
      if (lVar2 != 0) {
        param_1[0x4a] = 0;
        iVar7 = -0x3ffffee0;
        goto LAB_1c000cdcf;
      }
    }
    iVar7 = 0x103;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,0x19,0x13,
                       &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
    }
    iVar7 = -0x3fffffff;
  }
LAB_1c000cdcf:
  pcVar6 = (code *)CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar3);
  KeReleaseSpinLock(param_1 + 0x53);
LAB_1c000cde0:
  if (iVar7 != 0x103) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,0x16,0x14,
                        &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,(char)iVar7);
    }
    I8xCompleteSysButtonIrp(param_2,0,iVar7);
  }
  return iVar7;
}



===== I8xKeyboardSysButtonEventDpc @ 1c000ce50 =====

void I8xKeyboardSysButtonEventDpc(undefined8 param_1,longlong param_2,int param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  if (param_4 == 0x5e) {
    uVar7 = 1;
  }
  else if (param_4 == 0x5f) {
    uVar7 = 2;
  }
  else if (param_4 == 99) {
    uVar7 = 0x80000000;
  }
  else {
    uVar7 = 0;
  }
  if (param_3 != 1) {
    uVar6 = 0x18;
    plVar4 = (longlong *)ExAllocatePool2(0x40,0x18,0x32343038);
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    lVar5 = IoAllocateWorkItem(param_2);
    *plVar4 = lVar5;
    if (lVar5 == 0) {
      ExFreePoolWithTag(plVar4,0);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x16,0x16,
                       &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
    }
    *(byte *)(lVar2 + 0x249) = *(byte *)(lVar2 + 0x249) | (byte)uVar7;
    *(int *)(plVar4 + 1) = param_4;
    IoQueueWorkItem(*plVar4,I8xUpdateSysButtonCaps,1,plVar4);
    return;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x18,0x15,
                      &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,(byte)uVar7);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x298);
  lVar5 = *(longlong *)(lVar2 + 0x250);
  *(undefined8 *)(lVar2 + 0x250) = 0;
  if (lVar5 != 0) {
    if (*(char *)(lVar5 + 0x44) == '\0') {
      LOCK();
      lVar1 = *(longlong *)(lVar5 + 0x68);
      *(longlong *)(lVar5 + 0x68) = 0;
      UNLOCK();
      if (lVar1 != 0) goto LAB_1c000cf1c;
    }
    lVar5 = 0;
  }
LAB_1c000cf1c:
  KeReleaseSpinLock(lVar2 + 0x298,uVar3);
  if (lVar5 != 0) {
    I8xCompleteSysButtonIrp(lVar5,uVar7,0);
  }
  return;
}



===== I8xSysButtonCancelRoutine @ 1c000d020 =====

void I8xSysButtonCancelRoutine(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x17,0x17,
                     &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x298);
  uVar2 = *(undefined8 *)(lVar1 + 0x250);
  *(undefined8 *)(lVar1 + 0x250) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,0x18,0x18,
                      &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,(char)uVar2);
  }
  KeReleaseSpinLock(lVar1 + 0x298,uVar3);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== I8xUpdateSysButtonCapsGetPendedIrp @ 1c000d128 =====

ulonglong I8xUpdateSysButtonCapsGetPendedIrp(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x298);
  uVar2 = *(ulonglong *)(param_1 + 0x250);
  uVar4 = 0;
  *(undefined8 *)(param_1 + 0x250) = 0;
  uVar5 = 0;
  if (uVar2 != 0) {
    LOCK();
    lVar1 = *(longlong *)(uVar2 + 0x68);
    *(longlong *)(uVar2 + 0x68) = 0;
    UNLOCK();
    uVar4 = -(ulonglong)(lVar1 != 0);
    uVar5 = uVar2 & uVar4;
  }
  KeReleaseSpinLock(param_1 + 0x298,CONCAT71((int7)(uVar4 >> 8),uVar3));
  return uVar5;
}



===== WPP_RECORDER_SF_qdD @ 1c000d1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200000) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,10,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,0,0x16,&WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,10,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== I8xKeyboardIsrWritePort @ 1c000d290 =====

void I8xKeyboardIsrWritePort(undefined8 param_1,ulonglong param_2)

{
  I8xPutByteAsynchronous('\0',param_2);
  return;
}



===== I8xKeyboardSynchReadPort @ 1c000d2b0 =====

void I8xKeyboardSynchReadPort(undefined8 param_1,undefined1 *param_2)

{
  I8xGetBytePolled('\x01',param_2);
  return;
}



===== I8xKeyboardSynchWritePort @ 1c000d2d0 =====

void I8xKeyboardSynchWritePort(undefined8 param_1,byte param_2,char param_3)

{
  I8xPutBytePolled('\0',param_3,'\x01',param_2);
  return;
}



===== _guard_check_icall @ 1c000d300 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c000d318 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000d33c =====

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



===== __cpu_features_init @ 1c000d3b0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000d41a) */
/* WARNING: Removing unreachable block (ram,0x0001c000d3c9) */
/* WARNING: Removing unreachable block (ram,0x0001c000d3ba) */

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



===== __security_check_cookie @ 1c000d480 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c000d4c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000d4f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000d4f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000d520 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c000d580 =====

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



===== memset @ 1c000d880 =====

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



===== __memset_repmovs @ 1c000d9c0 =====

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



===== __memset_query @ 1c000da40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000dac0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c000dc00 =====

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



===== __memset_spec_plain @ 1c000dc80 =====

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



===== I8xSanityCheckResources @ 1c0016008 =====

undefined4 I8xSanityCheckResources(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  
  lVar2 = Globals;
  uVar8 = 0;
  uVar3 = 0;
  if (*(int *)(Globals + 0x40) != 0) {
    if (*(int *)(Globals + 0x40) == 1) {
      *(undefined4 *)(Globals + 0x24) = 1;
      *(undefined8 *)(lVar2 + 0x2c) = *(undefined8 *)(lVar2 + 0x18);
      *(undefined8 *)(lVar2 + 0x34) = *(undefined8 *)(lVar2 + 0x20);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(lVar2 + 0x28);
      *(int *)(lVar2 + 0x30) = *(int *)(lVar2 + 0x30) + 4;
      *(undefined4 *)(lVar2 + 0x40) = 2;
    }
    uVar7 = *(uint *)(lVar2 + 0x1c);
    if (*(uint *)(lVar2 + 0x30) < uVar7) {
      uVar4 = *(undefined8 *)(lVar2 + 0x2c);
      uVar1 = *(undefined8 *)(lVar2 + 0x34);
      uVar7 = *(uint *)(lVar2 + 0x3c);
      *(undefined8 *)(lVar2 + 0x2c) = *(undefined8 *)(lVar2 + 0x18);
      *(undefined8 *)(lVar2 + 0x34) = *(undefined8 *)(lVar2 + 0x20);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(lVar2 + 0x28);
      *(undefined8 *)(lVar2 + 0x18) = uVar4;
      *(undefined8 *)(lVar2 + 0x20) = uVar1;
      *(uint *)(lVar2 + 0x28) = uVar7;
    }
    pcVar5 = (code *)(ulonglong)uVar7;
    if (*(longlong *)(Globals + 0xd0) == 0) {
      if (DAT_1c0012244 == '\0') {
        uVar6 = 0;
        if (*(int *)(Globals + 0x40) != 0) {
          do {
            uVar7 = (int)uVar6 + 1;
            *(ulonglong *)(Globals + 0xd0 + uVar6 * 8) =
                 (ulonglong)*(uint *)(Globals + 0x1c + uVar6 * 0x14);
            uVar6 = (ulonglong)uVar7;
          } while (uVar7 < *(uint *)(Globals + 0x40));
        }
        DAT_1c00121d8 = I8xReadPortUchar;
        pcVar5 = I8xWritePortUchar;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x61,
                           &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
        }
        uVar7 = 0;
        if (*(int *)(Globals + 0x40) != 0) {
          do {
            uVar6 = (ulonglong)uVar7;
            uVar4 = MmMapIoSpaceEx(*(undefined8 *)(Globals + 0x1c + uVar6 * 0x14),
                                   *(undefined4 *)(Globals + 0x24 + uVar6 * 0x14),0x204);
            uVar7 = uVar7 + 1;
            *(undefined8 *)(Globals + 0xd0 + uVar6 * 8) = uVar4;
          } while (uVar7 < *(uint *)(Globals + 0x40));
        }
        DAT_1c00121d8 = I8xReadRegisterUchar;
        pcVar5 = I8xWriteRegisterUchar;
      }
      DAT_1c00121e0 = pcVar5;
    }
    if (*(int *)(lVar2 + 0x40) != 0) {
      do {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          pcVar5 = (code *)WPP_RECORDER_SF_sdDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(lVar2 + 0x40));
    }
    uVar3 = (undefined4)CONCAT71((int7)((ulonglong)pcVar5 >> 8),1);
  }
  return uVar3;
}



===== I8xInitializeHardwareAtBoot @ 1c0016208 =====

int I8xInitializeHardwareAtBoot(int *param_1,int *param_2,ulonglong param_3,undefined8 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  
  if ((DAT_1c00121d0 == 0) || (*(longlong *)(DAT_1c00121d0 + 8) == 0)) {
    piVar3 = param_2;
    uVar1 = I8xSanityCheckResources(param_1,param_2);
    if ((char)uVar1 == '\0') {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = I8xToggleInterrupts('\0',piVar3,param_3,param_4);
      if (-1 < iVar2) {
        uVar4 = 1;
        I8xInitializeHardware(param_1,param_2,(undefined8 *)0x1,param_4);
        if ((((-1 < *param_1) ||
             (((*param_1 == -0x3fffff63 && (DAT_1c0012246 != '\0')) || (-1 < *param_2)))) ||
            ((*param_2 == -0x3fffff63 && (DAT_1c0012246 != '\0')))) && ((*Globals & 3) != 0)) {
          iVar2 = I8xToggleInterrupts('\x01',(ulonglong)*Globals,uVar4,param_4);
        }
      }
    }
  }
  else {
    iVar2 = -0x3ffffff0;
  }
  return iVar2;
}



===== I8xStartDevice @ 1c00162c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int I8xStartDevice(longlong param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  char *pcVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  ExAcquireFastMutexUnsafe(&DAT_1c0012208);
  if ((*(char *)(lVar1 + 0x236) != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    param_4 = 0x25;
    pcVar4 = "kb";
    if (*(char *)(lVar1 + 0x235) == '\0') {
      pcVar4 = "mouse";
    }
    param_3 = 0x11;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"mouse",0x11,0x25,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar4);
  }
  lVar5 = param_2[2];
  if (lVar5 == 0) {
    lVar5 = param_2[1];
    uVar3 = I8xMouseStartDevice(*(byte **)(param_1 + 0x40),
                                *(byte **)(*(longlong *)(lVar5 + 0xb8) + 0x10),param_3,param_4);
    iVar2 = (int)uVar3;
  }
  else {
    uVar3 = I8xKeyboardStartDevice
                      ((longlong *)*(byte **)(param_1 + 0x40),
                       *(undefined **)(*(longlong *)(lVar5 + 0xb8) + 0x10),param_3,param_4);
    iVar2 = (int)uVar3;
  }
  if (-1 < iVar2) {
    LOCK();
    _DAT_1c0012200 = _DAT_1c0012200 + 1;
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x236) = 1;
  }
  ExReleaseFastMutexUnsafe(&DAT_1c0012208);
  *(undefined8 *)(lVar5 + 0x38) = 0;
  *(int *)(lVar5 + 0x30) = iVar2;
  IofCompleteRequest(lVar5,0);
  IoReleaseRemoveLockEx(lVar1 + 0x28,lVar5,0x20);
  if (*param_2 != 0) {
    IoFreeWorkItem();
  }
  if ((char)param_2[3] == '\0') {
    ExFreePoolWithTag(param_2,0);
  }
  return iVar2;
}



===== I8xStartDeviceCallback @ 1c0016430 =====

void I8xStartDeviceCallback(longlong param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  I8xStartDevice(param_1,param_2,param_3,param_4);
  return;
}



===== I8xUnload @ 1c0016450 =====

void I8xUnload(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0xc,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  if (DAT_1c0012244 != '\0') {
    uVar3 = 0;
    if (*(int *)(Globals + 0x40) != 0) {
      do {
        MmUnmapIoSpace(*(undefined8 *)(Globals + 0xd0 + uVar3 * 8),
                       *(undefined4 *)(Globals + 0x24 + uVar3 * 0x14));
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(Globals + 0x40));
    }
  }
  ExFreePoolWithTag(DAT_1c00121f0,0);
  if (*(longlong *)(Globals + 8) != 0) {
    IoDeleteController();
  }
  ExFreePoolWithTag(Globals,0);
  wil_UninitializeFeatureStaging();
  uVar1 = DAT_1c0012030;
  DAT_1c0012030 = 0;
  DAT_1c0012010 = 0;
  EtwUnregister(uVar1);
  WppCleanupKm(param_1);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c0016560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
  local_28 = *(undefined4 *)(PTR_DAT_1c0012018 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c0012018 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c0012018 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c0012018 + -4);
  if (DAT_1c0012030 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  DAT_1c0012038 = 0;
  DAT_1c0012040 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c00165c3;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c0012010,&DAT_1c0012030);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0012018;
    *(undefined8 *)(puVar4 + -8) = 0x1c00165ea;
    EtwSetInformation(DAT_1c0012030,2,PTR_DAT_1c0012018,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c00165fe;
  return iVar3;
}



===== WppCleanupKm @ 1c001660c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1c00166bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c0016798 =====

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



===== WppTraceCallback @ 1c00168e0 =====

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



===== wil_UninitializeFeatureStaging @ 1c0016b68 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1c0016bc0 =====

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
      goto LAB_1c0016c1d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1c0016c1d;
    }
  }
  uVar1 = 0x206;
LAB_1c0016c1d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1c0016c28 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_z)
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
  plVar1 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c0016ce0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1c0016d18 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1c0016d9a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1c0016d9a;
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
LAB_1c0016d9a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c0016df0 =====

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
      plVar2 = (longlong *)&wil_details_featureDescriptors_z;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c0016e50 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1c0016e6c =====

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
  plVar2 = (longlong *)&wil_details_featureDescriptors_z;
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



===== I8xKeyboardConfiguration @ 1c0016f20 =====

undefined8 I8xKeyboardConfiguration(longlong param_1,byte *param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  wchar_t wVar7;
  uint uVar8;
  char *pcVar9;
  undefined2 *puVar10;
  char *pcVar11;
  byte *pbVar12;
  ulonglong uVar13;
  
  lVar5 = Globals;
  if (param_2 == (byte *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x11,0x3b,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
  }
  else if (param_2 + 4 != (byte *)0x0) {
    uVar8 = *(uint *)(param_2 + 0x10);
    pcVar11 = (char *)(ulonglong)uVar8;
    *(undefined1 *)(Globals + 0x50) = 0;
    *(undefined4 *)(lVar5 + 0x14) = *(undefined4 *)(param_2 + 8);
    iVar3 = *(int *)(param_2 + 4);
    *(int *)(lVar5 + 0x10) = iVar3;
    if (uVar8 != 0) {
      uVar13 = (ulonglong)uVar8;
      do {
        pbVar12 = param_2 + 0x14;
        bVar2 = *pbVar12;
        pcVar11 = (char *)(ulonglong)bVar2;
        if (bVar2 == 1) {
LAB_1c0017022:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            pcVar9 = "memory";
            if (DAT_1c0012244 == '\0') {
              pcVar9 = "io";
            }
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0xe,0x3c,
                              &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pcVar9);
          }
          uVar8 = *(uint *)(lVar5 + 0x40);
          if (uVar8 < 2) {
            uVar4 = *(undefined8 *)(param_2 + 0x1c);
            puVar1 = (undefined8 *)(lVar5 + 0x18 + (ulonglong)uVar8 * 0x14);
            *puVar1 = *(undefined8 *)pbVar12;
            puVar1[1] = uVar4;
            *(undefined4 *)(lVar5 + 0x28 + (ulonglong)uVar8 * 0x14) =
                 *(undefined4 *)(param_2 + 0x24);
            *(undefined1 *)(lVar5 + 0x19 + (ulonglong)*(uint *)(lVar5 + 0x40) * 0x14) = 2;
            *(int *)(lVar5 + 0x40) = *(int *)(lVar5 + 0x40) + 1;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x11,0x3d,
                              &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar8);
          }
        }
        else if (bVar2 == 2) {
          uVar4 = *(undefined8 *)(param_2 + 0x1c);
          *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)pbVar12;
          *(undefined8 *)(param_1 + 0x220) = uVar4;
          *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(param_2 + 0x24);
          uVar6 = 3;
          if (iVar3 != 3) {
            uVar6 = 1;
          }
          *(undefined1 *)(param_1 + 0x219) = uVar6;
        }
        else {
          if (bVar2 == 3) {
            DAT_1c0012244 = '\x01';
            goto LAB_1c0017022;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,1,0x3e,
                              &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,bVar2);
          }
        }
        uVar13 = uVar13 - 1;
        param_2 = pbVar12;
      } while (uVar13 != 0);
    }
    if (((*(byte *)(param_1 + 0x218) & 2) != 0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      pcVar11 = "Latched";
      if (*(short *)(param_1 + 0x21a) != 1) {
        pcVar11 = "Level Sensitive";
      }
      pcVar9 = "Sharable";
      if (*(char *)(param_1 + 0x219) != '\x03') {
        pcVar9 = "NonSharable";
      }
      WPP_RECORDER_SF_ssD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,"NonSharable",0x3f,
                          &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pcVar9,pcVar11,
                          (char)*(undefined4 *)(param_1 + 0x220));
    }
    uVar13 = CONCAT71((int7)((ulonglong)pcVar11 >> 8),*(char *)(param_1 + 0x2b0));
    if (*(char *)(param_1 + 0x2b0) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,0x10,0x40,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      uVar13 = 4;
      *(undefined2 *)(param_1 + 0x2dc) = 0;
      *(undefined1 *)(param_1 + 0x2b0) = 4;
      *(undefined4 *)(param_1 + 0x2cc) = 4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = uVar13 & 0xff;
      WPP_RECORDER_SF_ddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if ((8 < *(byte *)(param_1 + 0x2b0)) ||
       ((0x194U >> (*(byte *)(param_1 + 0x2b0) & 0x1f) & 1) == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,0x10,0x42,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      *(undefined2 *)(lVar5 + 0x48) = *(undefined2 *)(lVar5 + 0x4a);
    }
    bVar2 = *(byte *)(param_1 + 0x2b0);
    uVar13 = (ulonglong)bVar2;
    if ((byte)(bVar2 - 7) < 2) {
      uVar8 = 0;
      while( true ) {
        uVar13 = (ulonglong)uVar8;
        if ((&DAT_1c000f720)[uVar13 * 8] == 0) break;
        if (((&DAT_1c000f720)[uVar13 * 8] == bVar2) &&
           ((&DAT_1c000f721)[uVar13 * 8] == *(char *)(param_1 + 0x2b1))) {
          puVar10 = (undefined2 *)(&DAT_1c000f722 + uVar13 * 8);
          if (puVar10 != (undefined2 *)0x0) goto LAB_1c00172d6;
          break;
        }
        uVar8 = uVar8 + 1;
      }
      puVar10 = &DAT_1c000f702;
LAB_1c00172d6:
      *(undefined2 *)(param_1 + 0x2b4) = *puVar10;
      *(undefined2 *)(param_1 + 0x2b6) = puVar10[1];
      wVar7 = puVar10[2];
    }
    else {
      *(wchar_t *)(param_1 + 0x2b4) = L"KdEnableOnCtrlSysRq"[uVar13 * 3 + 0x11];
      *(wchar_t *)(param_1 + 0x2b6) = L"KdEnableOnCtrlSysRq"[uVar13 * 3 + 0x12];
      wVar7 = L"KdEnableOnCtrlSysRq"[uVar13 * 3 + 0x13];
    }
    *(wchar_t *)(param_1 + 0x2b8) = wVar7;
    *(undefined2 *)(param_1 + 0x2b2) = 1;
    *(undefined4 *)(param_1 + 0x2c2) = 0xfa0002;
    *(undefined4 *)(param_1 + 0x2c8) = 0x3e8001e;
    *(undefined4 *)(param_1 + 0x2d6) = 0xfa001e;
    return 0;
  }
  return 0xc000009a;
}



===== I8xKeyboardServiceParameters @ 1c0017344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xKeyboardServiceParameters(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  void *_Dst;
  code *pcVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  void *pvVar7;
  int *piVar8;
  uint local_res8 [2];
  int local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90 [6];
  uint local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  longlong local_60 [4];
  
  lVar1 = Globals;
  local_60[0] = 0;
  local_98 = -1;
  local_res10[0] = -1;
  local_a0 = 1;
  local_90[3] = 1;
  local_a8 = 100;
  lVar4 = 0;
  local_9c = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_90[1] = 0;
  local_res20[0] = 0;
  local_68 = 0;
  local_a4 = 12000;
  local_94 = 0;
  local_90[2] = 0;
  local_90[0] = 0;
  local_90[4] = 0;
  iVar2 = IoOpenDriverRegistryKey(*(undefined8 *)(*param_1 + 8),0,1,0,local_60);
  if (iVar2 < 0) {
    _Dst = (void *)0x0;
LAB_1c00176a1:
    *(undefined2 *)(lVar1 + 0x4c) = (undefined2)local_a4;
    *(int *)((longlong)param_1 + 700) = local_a8;
  }
  else {
    lVar5 = 0x230;
    _Dst = (void *)ExAllocatePool2(0x100,0x230,0x32343038);
    lVar4 = local_60[0];
    if (_Dst == (void *)0x0) {
      lVar4 = lVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,0x11,0x4e,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
        lVar4 = lVar5;
      }
      goto LAB_1c00176a1;
    }
    *(undefined4 *)((longlong)_Dst + 8) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x20) = 0x4000004;
    *(wchar_t **)((longlong)_Dst + 0x10) = L"KeyboardDataQueueSize";
    *(undefined4 *)((longlong)_Dst + 0x30) = 4;
    *(longlong *)((longlong)_Dst + 0x18) = (longlong)param_1 + 700;
    *(int **)((longlong)_Dst + 0x28) = &local_a8;
    *(wchar_t **)((longlong)_Dst + 0x48) = L"OverrideKeyboardType";
    *(uint **)((longlong)_Dst + 0x50) = local_res8;
    *(uint **)((longlong)_Dst + 0x60) = &local_9c;
    *(undefined4 *)((longlong)_Dst + 0x40) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x58) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x68) = 4;
    *(wchar_t **)((longlong)_Dst + 0x80) = L"OverrideKeyboardSubType";
    *(int **)((longlong)_Dst + 0x88) = local_res10;
    *(int **)((longlong)_Dst + 0x98) = &local_98;
    *(undefined4 *)((longlong)_Dst + 0x78) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x90) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0xa0) = 4;
    *(wchar_t **)((longlong)_Dst + 0xb8) = L"PollStatusIterations";
    *(undefined4 **)((longlong)_Dst + 0xc0) = local_res18;
    *(undefined4 **)((longlong)_Dst + 0xd0) = &local_a4;
    *(undefined4 *)((longlong)_Dst + 0xb0) = 0x120;
    *(undefined4 *)((longlong)_Dst + 200) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0xd8) = 4;
    *(wchar_t **)((longlong)_Dst + 0xf0) = L"PowerCapabilities";
    *(undefined4 **)((longlong)_Dst + 0xf8) = local_res20;
    *(int **)((longlong)_Dst + 0x108) = local_90 + 1;
    *(undefined4 *)((longlong)_Dst + 0xe8) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x100) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x110) = 4;
    *(wchar_t **)((longlong)_Dst + 0x128) = L"CrashOnCtrlScroll";
    *(int **)((longlong)_Dst + 0x130) = &local_94;
    *(int **)((longlong)_Dst + 0x140) = local_90 + 2;
    *(undefined4 *)((longlong)_Dst + 0x120) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x138) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x148) = 4;
    *(wchar_t **)((longlong)_Dst + 0x160) = L"KeyboardFailedReset";
    *(int **)((longlong)_Dst + 0x168) = &local_a0;
    *(int **)((longlong)_Dst + 0x178) = local_90 + 3;
    *(undefined4 *)((longlong)_Dst + 0x158) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x170) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x180) = 4;
    *(wchar_t **)((longlong)_Dst + 0x198) = L"KdEnableOnCtrlSysRq";
    *(int **)((longlong)_Dst + 0x1a0) = local_90;
    *(undefined4 *)((longlong)_Dst + 400) = 0x120;
    *(undefined4 *)((longlong)_Dst + 0x1a8) = 0x4000004;
    *(int **)((longlong)_Dst + 0x1b0) = local_90 + 4;
    *(undefined4 *)((longlong)_Dst + 0x1b8) = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    RtlInitUnicodeString(local_60 + 1,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(local_60 + 1);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(0xc0000000,lVar4,_Dst,0,0);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,0x10,0x4f,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)iVar2);
      goto LAB_1c00176a1;
    }
    if (iVar2 < 0) goto LAB_1c00176a1;
    *(undefined2 *)(lVar1 + 0x4c) = (undefined2)local_res18[0];
  }
  piVar8 = (int *)((longlong)param_1 + 700);
  if (((local_a0 == 0) || (local_a0 == 1)) || (local_a0 == 2)) {
    *(char *)((longlong)param_1 + 0x3ba) = (char)local_a0;
    iVar2 = local_a0;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x3ba) = 1;
    iVar2 = 1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,0xe,0x50,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)iVar2);
  }
  uVar6 = 1;
  pvVar7 = (void *)0x20000;
  iVar2 = IoOpenDeviceRegistryKey(param_1[4],1,0x20000,&local_68);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0017976;
    pvVar7 = (void *)0x11;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x11,0x52,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)iVar2);
  }
  else {
    local_90[5] = *piVar8;
    local_6c = local_res20[0];
    local_78 = local_res8[0];
    local_74 = local_res10[0];
    local_70 = local_res18[0];
    memset(_Dst,0,0x230);
    uVar6 = local_68;
    *(int **)((longlong)_Dst + 0x18) = piVar8;
    *(wchar_t **)((longlong)_Dst + 0x10) = L"KeyboardDataQueueSize";
    *(undefined4 *)((longlong)_Dst + 8) = 0x20;
    *(int **)((longlong)_Dst + 0x28) = local_90 + 5;
    *(undefined4 *)((longlong)_Dst + 0x20) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x30) = 4;
    *(wchar_t **)((longlong)_Dst + 0x48) = L"OverrideKeyboardType";
    *(uint **)((longlong)_Dst + 0x50) = local_res8;
    *(uint **)((longlong)_Dst + 0x60) = &local_78;
    *(undefined4 *)((longlong)_Dst + 0x40) = 0x20;
    *(undefined4 *)((longlong)_Dst + 0x58) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0x68) = 4;
    *(wchar_t **)((longlong)_Dst + 0x80) = L"OverrideKeyboardSubType";
    *(int **)((longlong)_Dst + 0x88) = local_res10;
    *(int **)((longlong)_Dst + 0x98) = &local_74;
    *(undefined4 *)((longlong)_Dst + 0x78) = 0x20;
    *(undefined4 *)((longlong)_Dst + 0x90) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0xa0) = 4;
    *(wchar_t **)((longlong)_Dst + 0xb8) = L"PollStatusIterations";
    *(undefined4 **)((longlong)_Dst + 0xc0) = local_res18;
    *(undefined4 **)((longlong)_Dst + 0xd0) = &local_70;
    *(undefined4 *)((longlong)_Dst + 0xb0) = 0x20;
    *(undefined4 *)((longlong)_Dst + 200) = 0x4000004;
    *(undefined4 *)((longlong)_Dst + 0xd8) = 4;
    *(wchar_t **)((longlong)_Dst + 0xf0) = L"PowerCapabilities";
    *(undefined4 **)((longlong)_Dst + 0xf8) = local_res20;
    *(undefined4 *)((longlong)_Dst + 0xe8) = 0x20;
    *(undefined4 *)((longlong)_Dst + 0x100) = 0x4000004;
    *(undefined4 **)((longlong)_Dst + 0x108) = &local_6c;
    *(undefined4 *)((longlong)_Dst + 0x110) = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    RtlInitUnicodeString(local_60 + 1,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(local_60 + 1);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    pvVar7 = _Dst;
    iVar2 = (*pcVar3)(0x40000000,uVar6,_Dst,0,0);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      pvVar7 = (void *)0x10;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x10,0x51,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)iVar2);
    }
    ZwClose(local_68);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pvVar7 = (void *)0xe;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x53,
                     &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
LAB_1c0017976:
  iVar2 = *piVar8;
  if (*piVar8 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,pvVar7,0x55,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,L"KeyboardDataQueueSize",0
                        );
    }
    *piVar8 = local_a8;
    iVar2 = local_a8;
  }
  *piVar8 = iVar2 * 0xc;
  *(byte *)(param_1 + 0x49) = (byte)local_res20[0] & 7;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x56,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(byte)local_res20[0] & 7);
  }
  if (local_res8[0] != local_9c) {
    if (local_res8[0] < 9) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x57,
                          &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)local_res8[0]);
      }
      *(char *)(param_1 + 0x56) = (char)local_res8[0];
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x58,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)local_res8[0]);
    }
    *(uint *)((longlong)param_1 + 0x2cc) = local_res8[0];
  }
  if (local_res10[0] != local_98) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x59,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)local_res10[0]);
    }
    *(char *)((longlong)param_1 + 0x2b1) = (char)local_res10[0];
    *(int *)(param_1 + 0x5a) = local_res10[0];
  }
  if (local_94 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x10,0x5a,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    *(undefined4 *)(param_1 + 0x76) = 2;
    *(undefined2 *)(param_1 + 0x77) = 0x46;
  }
  if (local_90[0] != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x10,0x5b,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    *(undefined4 *)((longlong)param_1 + 0x3bc) = 2;
    *(undefined2 *)(param_1 + 0x78) = 0x54b7;
  }
  if (local_60[0] != 0) {
    ZwClose();
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  return;
}



===== I8xServiceCrashDump @ 1c0017b7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xServiceCrashDump(longlong param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  undefined2 uVar8;
  undefined1 auStackY_138 [32];
  int local_f8;
  uint local_f4;
  int local_f0;
  uint local_ec;
  undefined8 local_e8;
  wchar_t *pwStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
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
  undefined2 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  pwVar7 = *(wchar_t **)(param_2 + 4);
  local_f4 = 0;
  uVar6 = 0xa8;
  local_ec = 0;
  local_f0 = 0;
  local_f8 = 0;
  local_c8 = 0x3022900;
  local_c4 = 0x7060504;
  local_c0 = 0xb0a0908;
  local_bc = 0xe7d0d0c;
  local_b8 = 0x1211100f;
  local_b4 = 0x16151413;
  local_b0 = 0x1a191817;
  local_ac = 0x1e3a001b;
  local_a8 = 0x2221201f;
  local_a4 = 0x26252423;
  local_a0 = 0x1c2b2827;
  local_9c = 0x2d2c002a;
  local_98 = 0x31302f2e;
  local_94 = 0x35343332;
  local_90 = 0x1d3673;
  local_8c = 0xb83938;
  local_88 = 0x9d;
  local_80 = 0xd2000000;
  local_7c = 0xcb0000d3;
  local_78 = 0xc800cfc7;
  local_74 = 0xd1c9d0;
  local_70 = 0x4745cd00;
  local_6c = 0xb5004f4b;
  local_68 = 0x52504c48;
  local_64 = 0x514d4937;
  local_60 = 0x4e4a53;
  local_5c = 0x1009c;
  local_58 = 0x3e3d3c3b;
  local_54 = 0x4241403f;
  local_50 = 0x58574443;
  local_4c = 0x4600;
  local_48 = 0x7b000000;
  local_44 = 0x7079;
  local_e8 = 0;
  pwStack_e0 = (wchar_t *)0x0;
  lVar3 = ExAllocatePool2(0x100,0xa8,0x32343038);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x44;
LAB_1c0017d62:
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x11,uVar8,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pwVar7);
    }
  }
  else {
    RtlInitUnicodeString(&local_e8,0);
    uVar6 = (ulonglong)(ushort)(*param_2 + 0x16U);
    local_e8._0_4_ = CONCAT22(*param_2 + 0x16U,(undefined2)local_e8);
    pwStack_e0 = (wchar_t *)ExAllocatePool2(0x100,uVar6,0x32343038);
    if (pwStack_e0 == (wchar_t *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x45;
        goto LAB_1c0017d62;
      }
    }
    else {
      RtlAppendUnicodeToString(&local_e8,pwVar7);
      pwVar7 = L"\\Crashdump";
      RtlAppendUnicodeToString(&local_e8);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,0x10,0x46,
                          &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pwStack_e0);
      }
      pwVar7 = pwStack_e0;
      *(wchar_t **)(lVar3 + 0x10) = L"Dump1Keys";
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      *(uint **)(lVar3 + 0x18) = &local_ec;
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(uint **)(lVar3 + 0x28) = &local_f4;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      *(wchar_t **)(lVar3 + 0x48) = L"Dump2Key";
      *(undefined4 *)(lVar3 + 0x30) = 4;
      *(int **)(lVar3 + 0x50) = &local_f8;
      *(int **)(lVar3 + 0x60) = &local_f0;
      *(undefined4 *)(lVar3 + 0x68) = 4;
      local_d8 = 0;
      uStack_d0 = 0;
      RtlInitUnicodeString(&local_d8,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(&local_d8);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      iVar1 = (*pcVar4)(0x80000000,pwVar7,lVar3,0);
      if (-1 < iVar1) {
        uVar2 = local_ec;
        goto LAB_1c0017ec8;
      }
    }
  }
  local_f8 = local_f0;
  uVar2 = local_f4;
LAB_1c0017ec8:
  *(uint *)(param_1 + 0x3b0) = uVar2;
  uVar6 = (ulonglong)uVar2;
  if (uVar2 != 0) {
    if (local_f8 == 0x7c) {
      *(undefined2 *)(param_1 + 0x3b8) = 0x54b7;
    }
    else {
      if (local_f8 < 0x86) {
        uVar5 = *(undefined1 *)((longlong)&local_c8 + (longlong)local_f8);
      }
      else {
        uVar5 = 0;
      }
      *(undefined1 *)(param_1 + 0x3b8) = uVar5;
      *(undefined1 *)(param_1 + 0x3b9) = 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x47,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x48,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,
                         *(undefined1 *)(param_1 + 0x3b8),*(undefined1 *)(param_1 + 0x3b9));
    }
  }
  if (pwStack_e0 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwStack_e0,0);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return;
}



===== I8xServiceDebugEnable @ 1c0017fcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xServiceDebugEnable(longlong param_1,short *param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  undefined2 uVar8;
  undefined1 auStackY_148 [32];
  uint local_108;
  uint local_104;
  int local_100 [2];
  undefined8 local_f8;
  wchar_t *pwStack_f0;
  undefined4 local_e8 [2];
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
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
  undefined2 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  pwVar7 = *(wchar_t **)(param_2 + 4);
  local_108 = 0;
  uVar6 = 0xa8;
  local_104 = 0;
  local_e8[0] = 0;
  local_100[0] = 0;
  local_c8 = 0x3022900;
  local_c4 = 0x7060504;
  local_c0 = 0xb0a0908;
  local_bc = 0xe7d0d0c;
  local_b8 = 0x1211100f;
  local_b4 = 0x16151413;
  local_b0 = 0x1a191817;
  local_ac = 0x1e3a001b;
  local_a8 = 0x2221201f;
  local_a4 = 0x26252423;
  local_a0 = 0x1c2b2827;
  local_9c = 0x2d2c002a;
  local_98 = 0x31302f2e;
  local_94 = 0x35343332;
  local_90 = 0x1d3673;
  local_8c = 0xb83938;
  local_88 = 0x9d;
  local_80 = 0xd2000000;
  local_7c = 0xcb0000d3;
  local_78 = 0xc800cfc7;
  local_74 = 0xd1c9d0;
  local_70 = 0x4745cd00;
  local_6c = 0xb5004f4b;
  local_68 = 0x52504c48;
  local_64 = 0x514d4937;
  local_60 = 0x4e4a53;
  local_5c = 0x1009c;
  local_58 = 0x3e3d3c3b;
  local_54 = 0x4241403f;
  local_50 = 0x58574443;
  local_4c = 0x4600;
  local_48 = 0x7b000000;
  local_44 = 0x7079;
  local_f8 = 0;
  pwStack_f0 = (wchar_t *)0x0;
  lVar3 = ExAllocatePool2(0x100,0xa8,0x32343038);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x49;
LAB_1c00181ae:
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0x11,uVar8,
                        &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pwVar7);
    }
  }
  else {
    RtlInitUnicodeString(&local_f8,0);
    uVar6 = (ulonglong)(ushort)(*param_2 + 0x1aU);
    local_f8._0_4_ = CONCAT22(*param_2 + 0x1aU,(undefined2)local_f8);
    pwStack_f0 = (wchar_t *)ExAllocatePool2(0x100,uVar6,0x32343038);
    if (pwStack_f0 == (wchar_t *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x4a;
        goto LAB_1c00181ae;
      }
    }
    else {
      RtlAppendUnicodeToString(&local_f8,pwVar7);
      pwVar7 = L"\\DebugEnable";
      RtlAppendUnicodeToString(&local_f8);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,0x10,0x4b,
                          &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,pwStack_f0);
      }
      pwVar7 = pwStack_f0;
      *(wchar_t **)(lVar3 + 0x10) = L"Debug1Keys";
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      *(uint **)(lVar3 + 0x18) = &local_104;
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(uint **)(lVar3 + 0x28) = &local_108;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      *(wchar_t **)(lVar3 + 0x48) = L"Debug2Key";
      *(undefined4 *)(lVar3 + 0x30) = 4;
      *(int **)(lVar3 + 0x50) = local_100;
      *(undefined4 **)(lVar3 + 0x60) = local_e8;
      *(undefined4 *)(lVar3 + 0x68) = 4;
      local_e0 = 0;
      uStack_d8 = 0;
      RtlInitUnicodeString(&local_e0,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(&local_e0);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      iVar1 = (*pcVar4)(0x80000000,pwVar7,lVar3,0);
      if (-1 < iVar1) {
        uVar2 = local_104;
        goto LAB_1c0018308;
      }
    }
  }
  uVar2 = local_108;
LAB_1c0018308:
  *(uint *)(param_1 + 0x3bc) = uVar2;
  uVar6 = (ulonglong)uVar2;
  if (uVar2 != 0) {
    if (local_100[0] == 0x7c) {
      *(undefined2 *)(param_1 + 0x3c0) = 0x54b7;
    }
    else {
      if (local_100[0] < 0x86) {
        uVar5 = *(undefined1 *)((longlong)&local_c8 + (longlong)local_100[0]);
      }
      else {
        uVar5 = 0;
      }
      *(undefined1 *)(param_1 + 0x3c0) = uVar5;
      *(undefined1 *)(param_1 + 0x3c1) = 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x4c,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,0xe,0x4d,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,
                         *(undefined1 *)(param_1 + 0x3c0),*(undefined1 *)(param_1 + 0x3c1));
    }
  }
  if (pwStack_f0 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwStack_f0,0);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return;
}



===== I8xKeyboardConnectInterrupt @ 1c0018410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I8xKeyboardConnectInterrupt(undefined8 *param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  code *pcVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined1 auStackY_d8 [32];
  undefined4 local_68 [2];
  ulonglong local_60;
  longlong lStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  plVar1 = param_1 + 1;
  if (*plVar1 == 0) {
    uVar4 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar11 = "yes";
      if (*(char *)(Globals + 0x50) == '\0') {
        pcVar11 = "no";
      }
      pcVar8 = "true";
      pcVar5 = "Latched";
      if (*(char *)((longlong)param_1 + 0x219) != '\x03') {
        pcVar8 = "false";
      }
      if (*(short *)((longlong)param_1 + 0x21a) != 1) {
        pcVar5 = "LevelSensitive";
      }
      WPP_RECORDER_SF_qDDDssDs
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,pcVar8,10,
                 &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids,(char)uVar4,
                 (char)*(undefined4 *)(param_1 + 0x44),
                 (char)*(undefined4 *)((longlong)param_1 + 0x21c),*(undefined1 *)(Globals + 0x44),
                 pcVar5,pcVar8,(char)*(undefined4 *)((longlong)param_1 + 0x224),pcVar11);
    }
    *(undefined1 *)((longlong)param_1 + 0x234) = 1;
    pcVar6 = I8042KeyboardInterruptService;
    uVar2 = IoConnectInterrupt(plVar1,I8042KeyboardInterruptService,uVar4,param_1 + 2);
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,0x11,0xb,
                         &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      }
      local_68[0] = *(undefined4 *)((longlong)param_1 + 0x21c);
      uVar7 = 0xc0050009;
      uVar10 = 0xc000009a;
      uVar9 = 0x438;
      I8xLogError(uVar4,0xc0050009,0x438,0xc000009a,local_68,1);
      TraceLoggingConnectInterruptFailed(uVar3,uVar7,uVar9,uVar10);
      I8xManuallyRemoveDevice((longlong)param_1,uVar7);
    }
    else {
      local_60 = (ulonglong)(uint)local_60;
      uVar4 = IoGetAttachedDeviceReference(uVar4);
      lStack_58 = *plVar1;
      local_60 = 0x30;
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      I8xSendIoctl(uVar4,0xb3fcf,&local_60,0x30);
      ObfDereferenceObject(uVar4);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== I8xKeyboardInitializeHardware @ 1c00186b0 =====

int I8xKeyboardInitializeHardware
              (undefined8 *param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_res18 [2];
  int local_res20 [2];
  
  local_res20[0] = -0x3fffffff;
  piVar3 = local_res18;
  local_res18[0] = -0x3fffffff;
  iVar1 = I8xInitializeHardwareAtBoot(local_res20,piVar3,param_3,param_4);
  if (-1 < iVar1) {
    if (((local_res18[0] + 0x80000000U & 0x80000000) != 0) || (local_res18[0] == -0x3fffff63)) {
      uVar4 = CONCAT71((int7)((ulonglong)piVar3 >> 8),local_res18[0] != -0x3fffff63);
      uVar2 = I8xMouseConnectInterruptAndEnable(param_2,uVar4);
      if (((int)uVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0x11,0xc,
                         &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      }
    }
    if (((local_res20[0] + 0x80000000U & 0x80000000) != 0) ||
       (iVar1 = local_res20[0], local_res20[0] == -0x3fffff63)) {
      uVar2 = I8xKeyboardConnectInterrupt(param_1);
      iVar1 = (int)uVar2;
    }
  }
  return iVar1;
}



===== I8xKeyboardRemoveDevice @ 1c0018784 =====

void I8xKeyboardRemoveDevice(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x15,
                     &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
  }
  if ((DAT_1c00121d0 == lVar1) && (lVar1 != 0)) {
    *Globals = *Globals & 0xfffffefe;
    DAT_1c00121d0 = 0;
  }
  if (*(longlong *)(lVar1 + 8) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x368) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x368),0);
    *(undefined8 *)(lVar1 + 0x368) = 0;
  }
  if (*(char *)(lVar1 + 0x233) != '\0') {
    I8xKeyboardRemoveDeviceInitialized(lVar1);
  }
  if (*(longlong *)(lVar1 + 0x2a8) != 0) {
    IoSetDeviceInterfaceState(lVar1 + 0x2a0,0);
    RtlFreeUnicodeString(lVar1 + 0x2a0);
  }
  return;
}



===== I8xKeyboardStartDevice @ 1c0018874 =====

ulonglong I8xKeyboardStartDevice
                    (longlong *param_1,undefined *param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  char *pcVar5;
  code *pcVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined4 local_res18 [4];
  longlong *local_28;
  undefined8 uStack_20;
  
  local_28 = (longlong *)0x0;
  uStack_20 = 0;
  pcVar6 = (code *)param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0xd;
    param_3 = 0xf;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0xd,
                     &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
  }
  if ((*Globals & 0x100) == 0) {
    if (param_1[0x37] == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,0x11,0xf,
                         &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      }
      return 0xc0000184;
    }
    uVar3 = I8xKeyboardConfiguration((longlong)param_1,param_2);
    uVar7 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      iVar1 = I8xManuallyRemoveDevice((longlong)param_1,param_2);
      if (0 < iVar1) goto LAB_1c0018c05;
    }
    else {
      plVar8 = (longlong *)*param_1;
      DAT_1c00121d0 = param_1;
      if ((byte)Globals[0x11] < *(byte *)((longlong)param_1 + 0x21c)) {
        *(byte *)(Globals + 0x11) = *(byte *)((longlong)param_1 + 0x21c);
      }
      *(undefined4 *)(param_1 + 0x76) = 0;
      *(undefined4 *)((longlong)param_1 + 0x3b4) = 0;
      *(undefined2 *)(param_1 + 0x77) = 0;
      I8xKeyboardServiceParameters(param_1);
      if ((int)param_1[0x76] == 0) {
        I8xServiceCrashDump((longlong)param_1,(short *)&DAT_1c00121e8);
      }
      if (*(int *)((longlong)param_1 + 0x3bc) == 0) {
        I8xServiceDebugEnable((longlong)param_1,(short *)&DAT_1c00121e8);
      }
      uVar3 = (ulonglong)*(uint *)((longlong)param_1 + 700);
      lVar4 = ExAllocatePool2(0x40,uVar3,0x32343038);
      param_1[0x6d] = lVar4;
      if (lVar4 != 0) {
        param_1[0x70] = (ulonglong)*(uint *)((longlong)param_1 + 700) + lVar4;
        uStack_20 = CONCAT71(uStack_20._1_7_,1);
        local_28 = param_1;
        I8xInitializeDataQueue((longlong *)&local_28,uVar3);
        *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
        KeInitializeDpc(param_1 + 0x5c,I8042KeyboardIsrDpc,plVar8);
        KeInitializeDpc(param_1 + 100,I8042KeyboardIsrDpc,plVar8);
        pcVar6 = I8xKeyboardSysButtonEventDpc;
        KeInitializeDpc(param_1 + 0x4b);
        KeInitializeSpinLock(param_1 + 0x53);
        param_2 = pcVar6;
        if ((char)param_1[0x49] != '\0') {
          plVar8 = param_1 + 0x54;
          I8xRegisterDeviceInterface(param_1[4],pcVar6,plVar8);
          param_2 = pcVar6;
        }
        I8xInitWmi(param_1);
        *(undefined1 *)((longlong)param_1 + 0x233) = 1;
        if (((*Globals & 2) == 0) ||
           ((DAT_1c00121c8 != (code *)0x0 && (DAT_1c00121c8[0x236] != (code)0x0)))) {
          param_2 = DAT_1c00121c8;
          uVar2 = I8xKeyboardInitializeHardware
                            (param_1,(longlong *)DAT_1c00121c8,(ulonglong)plVar8,param_4);
          uVar7 = (ulonglong)uVar2;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar7;
          }
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x11,
                           &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
        }
        goto LAB_1c0018c05;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x11,0x10,
                         &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      }
      local_res18[0] = *(undefined4 *)((longlong)param_1 + 700);
      uVar7 = 0xc000009a;
      param_4 = 0xc000009a;
      param_2 = (code *)0xc0050002;
      param_3 = 0x41a;
      I8xLogError(plVar8,0xc0050002,0x41a,0xc000009a,local_res18,1);
      TraceLoggingAllocateMemoryFailed
                ((ulonglong)*(uint *)((longlong)param_1 + 700),param_2,param_3,param_4);
    }
    if (((DAT_1c00121c8 != (code *)0x0) && (DAT_1c00121c8[0x236] != (code)0x0)) &&
       ((*Globals & 0x200) == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 0x12;
        param_3 = 0x10;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x12,
                         &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      }
      param_2 = DAT_1c00121c8;
      I8xMouseInitializeHardware(param_1,(longlong *)DAT_1c00121c8,param_3,param_4);
    }
  }
  else {
    param_2 = pcVar6;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,0x11,0xe,
                       &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids);
      param_2 = pcVar6;
    }
    LOCK();
    DAT_1c00121f8 = DAT_1c00121f8 + -1;
    UNLOCK();
    uVar7 = 0xc000000e;
  }
LAB_1c0018c05:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar5 = "successful";
    if ((int)uVar7 < 0) {
      pcVar5 = "unsuccessful";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x13,
                      &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids,pcVar5);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x14,
                        &WPP_b71d3786c0783d031954a21c92de3f01_Traceguids,(char)uVar7);
    }
  }
  return uVar7;
}



===== I8xFindWheelMouse @ 1c0018c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I8xFindWheelMouse(undefined8 *param_1,undefined8 param_2)

{
  byte bVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  byte *_Src;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  wchar_t *pwVar10;
  int *piVar11;
  undefined2 uVar12;
  byte *pbVar13;
  int iVar14;
  bool bVar15;
  undefined1 auStackY_b8 [32];
  byte local_78 [4];
  uint local_74;
  int local_70;
  undefined4 local_6c;
  byte local_68 [8];
  longlong lStack_60;
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  wchar_t local_40 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_50 = 0x64f3c8f3;
  local_70 = 0;
  local_78[0] = 0;
  local_52 = 0;
  local_74 = 0;
  local_4c = 0xf250f3;
  local_48 = 0xc8f3c8f3;
  local_44 = 0xf250f3;
  local_58 = 0x28f314f3;
  local_54 = 0x3cf3;
  local_6c = 0x5c8;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x51,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x452) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000e;
    }
    uVar12 = 0x52;
LAB_1c0018f66:
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,uVar12,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
    return 0xc000000e;
  }
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  lStack_60 = 0;
  if (param_1[1] == 0) {
    KeStallExecutionProcessor(0x32);
    if (*(char *)((longlong)param_1 + 0x452) != '\x01') {
      if (*(char *)((longlong)param_1 + 0x452) != '\x02') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000e;
        }
        uVar12 = 0x54;
        goto LAB_1c0018f66;
      }
      goto LAB_1c0018d7f;
    }
    _Src = (byte *)&local_6c;
    puVar5 = &local_58;
    uVar2 = I8xTransmitByteSequence
                      ((longlong)puVar5,(int *)_Src,&local_70,(undefined4 *)local_68,&local_74);
    uVar9 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      pwVar10 = local_40;
      local_40[0] = L'\0';
      local_40[1] = L'\0';
      local_40[2] = L'\0';
      local_40[3] = L'\0';
      local_40[4] = L'\0';
      local_40[5] = L'\0';
      local_40[6] = L'\0';
      local_40[7] = L'\0';
      for (uVar7 = 0; uVar7 < 7; uVar7 = uVar7 + 1) {
        _Src = local_78;
        uVar2 = I8xGetBytePolledIterated(puVar5,_Src);
        if (local_78[0] < 0x36) {
          puVar5 = (undefined4 *)(ulonglong)local_78[0];
          bVar1 = *(byte *)(puVar5 + 0x70003e5c);
          _Src = (byte *)(ulonglong)bVar1;
          *pwVar10 = (ushort)bVar1;
          if ((ushort)bVar1 != L'\0') {
            pwVar10 = pwVar10 + 1;
          }
        }
        if ((int)uVar2 < 0) {
          do {
            KeStallExecutionProcessor();
            uVar3 = I8xGetBytePolled('\0',local_78);
          } while ((int)uVar3 != -0x3fffff4b);
          return 0xc000000e;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,0x10,0x53,
                          &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_40);
      }
      uVar2 = I8xVerifyMousePnPID((longlong)param_1,(longlong)local_40);
      bVar15 = (char)uVar2 == '\0';
      goto LAB_1c0018d79;
    }
LAB_1c0019021:
    uVar8 = (ulonglong)local_74;
    iVar14 = local_70;
  }
  else {
    bVar15 = (*Globals & 8) == 0;
LAB_1c0018d79:
    if (bVar15) {
      return 0xc000000e;
    }
LAB_1c0018d7f:
    pbVar13 = local_68;
    piVar11 = &local_70;
    _Src = (byte *)&local_6c;
    puVar5 = &local_50;
    uVar2 = I8xTransmitByteSequence
                      ((longlong)puVar5,(int *)_Src,piVar11,(undefined4 *)pbVar13,&local_74);
    uVar9 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_1c0019021;
    _Src = local_78;
    uVar2 = I8xGetBytePolledIterated(puVar5,_Src);
    bVar1 = local_78[0];
    uVar9 = uVar2 & 0xffffffff;
    if ((-1 < (int)uVar2) && ((local_78[0] == 0 || (local_78[0] == 3)))) {
      if (local_78[0] != 3) {
        *Globals = *Globals | 2;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar9;
        }
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,0x10,0x56,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
        goto LAB_1c001909f;
      }
      *Globals = *Globals | 8;
      _Src = (byte *)&local_6c;
      *(undefined2 *)(param_1 + 0x49) = 0x20;
      puVar5 = &local_48;
      uVar2 = I8xTransmitByteSequence
                        ((longlong)puVar5,(int *)_Src,&local_70,(undefined4 *)local_68,&local_74);
      uVar9 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        _Src = local_78;
        uVar2 = I8xGetBytePolledIterated(puVar5,_Src);
        uVar9 = uVar2 & 0xffffffff;
        if (-1 < (int)uVar2) {
          if (local_78[0] == 4) {
            *Globals = *Globals | 0x1008;
            *(undefined2 *)(param_1 + 0x49) = 0x20;
          }
          goto LAB_1c001909f;
        }
      }
      goto LAB_1c0019021;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pbVar13 = (byte *)0x55;
      piVar11 = (int *)0x11;
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,0x11,0x55,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar2,local_78[0]);
    }
    uVar8 = 4;
    local_68[0] = 4;
    local_68[1] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    local_68[4] = 0;
    local_68[5] = 0;
    local_68[6] = 0;
    local_68[7] = 0;
    iVar14 = -0x7ffaffee;
    lStack_60 = (ulonglong)bVar1 << 0x20;
    TraceLoggingResetResponseFailed(uVar9,_Src,piVar11,pbVar13);
    if (-1 < (int)uVar2) goto LAB_1c001909f;
  }
  if (iVar14 != 0) {
    iVar6 = (int)uVar8 + 0xc;
    _Src = (byte *)(ulonglong)CONCAT31((int3)((uint)iVar6 >> 8),(char)iVar6 << 2);
    puVar4 = (undefined2 *)IoAllocateErrorLogEntry(*param_1);
    if (puVar4 != (undefined2 *)0x0) {
      *(int *)(puVar4 + 6) = iVar14;
      puVar4[1] = (short)uVar8 << 2;
      *(undefined4 *)(puVar4 + 8) = local_6c;
      *(undefined8 *)(puVar4 + 0xc) = 0;
      *puVar4 = 0;
      *(int *)(puVar4 + 10) = (int)uVar9;
      if ((int)uVar8 != 0) {
        _Src = local_68;
        memcpy(puVar4 + 0x14,_Src,uVar8 << 2);
      }
      IoWriteErrorLogEntry(puVar4);
    }
  }
LAB_1c001909f:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,0xf,0x57,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar9);
  }
  return uVar9;
}



===== I8xGetBytePolledIterated @ 1c0019104 =====

ulonglong I8xGetBytePolledIterated(undefined8 param_1,undefined1 *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = I8xGetBytePolled('\0',param_2);
    if ((int)uVar1 != -0x3fffff4b) {
      return uVar1 & 0xffffffff;
    }
    KeStallExecutionProcessor();
    uVar2 = uVar2 + 1;
  } while (uVar2 < 5);
  return uVar1 & 0xffffffff;
}



===== I8xInitializeMouse @ 1c001915c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong I8xInitializeMouse(undefined8 *param_1,undefined8 param_2,undefined8 param_3,
                            undefined8 param_4)

{
  undefined8 uVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  byte *pbVar11;
  ulonglong uVar12;
  byte *pbVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 uVar18;
  undefined1 auStackY_c8 [32];
  byte local_88;
  byte local_87 [3];
  int local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68 [4];
  int *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = 0;
  local_87[0] = 0;
  local_80 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0;
    param_3 = 0;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x35,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  uVar1 = *param_1;
  uVar16 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xff);
  puVar14 = (undefined8 *)CONCAT71((int7)((ulonglong)param_3 >> 8),2);
  pbVar11 = (byte *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  local_78 = 0;
  uStack_70 = 0;
  uVar8 = I8xPutBytePolled('\0','\x01','\x02',0xff);
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar16 = 0x36;
      puVar14 = (undefined8 *)0x11;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x11,0x36,
                        &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8);
    }
    cVar2 = DAT_1c0012247;
    local_78 = 1;
    uVar18 = 0x587;
    uStack_70 = 0xff000000d4;
    uVar7 = 4;
    TraceLoggingDeviceNotConnected(uVar8 & 0xffffffff,pbVar11,puVar14,uVar16);
    uVar12 = 0xc000009d;
    *Globals = *Globals | 0x8000;
    pbVar13 = (byte *)0x4005001f;
    if (cVar2 == '\0') goto LAB_1c001974c;
  }
  else {
    *(undefined2 *)((longlong)param_1 + 0x3f4) = 0xffff;
    *(undefined2 *)(param_1 + 0x46) = 0;
    lVar3 = _DAT_fffff78000000320;
    local_80 = 0xffffffffffffff9c;
    do {
      pbVar11 = &local_88;
      uVar8 = I8xGetBytePolled('\0',pbVar11);
      iVar6 = (int)uVar8;
      uVar12 = uVar8 & 0xffffffff;
      if ((-1 < iVar6) && (local_88 == 0xaa)) goto LAB_1c001936a;
      if (iVar6 != -0x3fffff4b) break;
      puVar14 = &local_80;
      pbVar11 = (byte *)0x0;
      KeDelayExecutionThread();
      lVar4 = _DAT_fffff78000000320;
      uVar7 = KeQueryTimeIncrement();
    } while ((longlong)((ulonglong)uVar7 * (lVar4 - lVar3)) < 100000000);
    bVar5 = local_88;
    if (iVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar16 = 0x37;
        puVar14 = (undefined8 *)0x11;
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x11,0x37,
                           &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8,local_88);
      }
      local_78 = 4;
      uVar7 = 4;
      uStack_70 = CONCAT44((uint)bVar5,0xaa);
      uVar18 = 0x58c;
      TraceLoggingResetResponseFailed(uVar8 & 0xffffffff,pbVar11,puVar14,uVar16);
      pbVar13 = (byte *)0x80050012;
    }
    else {
LAB_1c001936a:
      pbVar11 = &local_88;
      uVar8 = I8xGetBytePolled('\0',pbVar11);
      bVar5 = local_88;
      uVar12 = uVar8 & 0xffffffff;
      if (((int)uVar8 < 0) || (local_88 != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar16 = 0x38;
          puVar14 = (undefined8 *)0x11;
          WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x11,0x38,
                             &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8,local_88);
        }
        local_78 = 4;
        uStack_70 = (ulonglong)bVar5 << 0x20;
        TraceLoggingResetResponseFailed(uVar12,pbVar11,puVar14,uVar16);
        if (-1 < (int)uVar8) goto LAB_1c001974c;
        uVar7 = 4;
        uVar18 = 0x591;
        pbVar13 = (byte *)0x80050012;
      }
      else {
        if (*(char *)((longlong)param_1 + 0x454) == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0xe,0x39,
                             &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
          }
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar16 = 0x3a;
          puVar14 = (undefined8 *)0xe;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0xe,0x3a,
                           &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
        }
        *(undefined4 *)(param_1 + 0x74) = 0x1010000;
        I8xFindWheelMouse(param_1,pbVar11);
        pbVar10 = local_87;
        uVar8 = I8xQueryNumberOfMouseButtons((char *)pbVar10);
        bVar5 = local_87[0];
        uVar12 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar16 = 0x3b;
            pbVar10 = *(byte **)(WPP_GLOBAL_Control + 0x40);
            puVar14 = (undefined8 *)0x11;
            WPP_RECORDER_SF_D(pbVar10,pbVar11,0x11,0x3b,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8);
          }
          local_78 = 1;
          pbVar13 = (byte *)0xc0050022;
          uVar18 = 0x592;
          uStack_70 = CONCAT44(uStack_70._4_4_,0xd4);
          uVar7 = 3;
          if (5 < DAT_1c0012010) {
            uVar9 = _tlgKeywordOn();
            if ((char)uVar9 != '\0') {
              local_48 = &local_84;
              local_40 = 4;
              local_84 = (int)uVar8;
              _tlgWriteTransfer_EtwWriteTransfer(pbVar10,&DAT_1c0010021,puVar14,uVar16,3,local_68);
            }
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar16 = 0;
            puVar14 = (undefined8 *)0x0;
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x10,0x3c,
                               &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_87[0],
                               (char)*(undefined2 *)((longlong)param_1 + 0x24a));
          }
          if (bVar5 != 0) {
            *(ushort *)((longlong)param_1 + 0x24a) = (ushort)bVar5;
          }
          if ((*Globals >> 0xc & 1) == 0) {
            if ((*Globals & 8) != 0) {
              *(undefined2 *)((longlong)param_1 + 0x24a) = 3;
            }
          }
          else {
            *(undefined2 *)((longlong)param_1 + 0x24a) = 5;
          }
          uVar17 = CONCAT71((int7)((ulonglong)uVar16 >> 8),0xf3);
          uVar16 = CONCAT71((int7)((ulonglong)pbVar11 >> 8),1);
          uVar15 = CONCAT71((int7)((ulonglong)puVar14 >> 8),2);
          uVar12 = I8xPutBytePolled('\0','\x01','\x02',0xf3);
          if ((int)uVar12 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar17 = 0x3d;
              uVar15 = 0x11;
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar16,0x11,0x3d,
                                &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar12);
            }
            uVar18 = 0x59b;
            uStack_70._4_4_ = 0xf3;
          }
          else {
            uVar17 = CONCAT71((int7)((ulonglong)uVar17 >> 8),*(byte *)((longlong)param_1 + 0x24c));
            uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),2);
            uVar16 = CONCAT71((int7)((ulonglong)uVar16 >> 8),1);
            uVar12 = I8xPutBytePolled('\0','\x01','\x02',*(byte *)((longlong)param_1 + 0x24c));
            if (-1 < (int)uVar12) {
              uVar17 = CONCAT71((int7)((ulonglong)uVar17 >> 8),0xe8);
              uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),2);
              pbVar11 = (byte *)CONCAT71((int7)((ulonglong)uVar16 >> 8),1);
              uVar8 = I8xPutBytePolled('\0','\x01','\x02',0xe8);
              uVar12 = uVar8 & 0xffffffff;
              if ((int)uVar8 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar17 = 0x3f;
                  uVar15 = 0x11;
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x11,0x3f,
                                    &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8);
                }
                uVar18 = 0x5af;
                uStack_70._4_4_ = 0xe8;
              }
              else {
                uVar17 = CONCAT71((int7)((ulonglong)uVar17 >> 8),
                                  *(byte *)((longlong)param_1 + 0x451));
                uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),2);
                pbVar11 = (byte *)CONCAT71((int7)((ulonglong)pbVar11 >> 8),1);
                uVar8 = I8xPutBytePolled('\0','\x01','\x02',*(byte *)((longlong)param_1 + 0x451));
                uVar12 = uVar8 & 0xffffffff;
                if (-1 < (int)uVar8) goto LAB_1c001974c;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar17 = 0x40;
                  uVar15 = 0x11;
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0x11,0x40,
                                    &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar8);
                }
                uVar18 = 0x5b9;
                uStack_70._4_4_ = (uint)*(byte *)((longlong)param_1 + 0x451);
              }
              uStack_70 = CONCAT44(uStack_70._4_4_,0xd4);
              local_78 = 1;
              uVar7 = 4;
              TraceLoggingSetResolutionFailed(uVar12,pbVar11,uVar15,uVar17);
              pbVar13 = (byte *)0xc0050017;
              goto LAB_1c0019724;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar17 = 0x3e;
              uVar15 = 0x11;
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar16,0x11,0x3e,
                                &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar12);
            }
            uVar18 = 0x5a5;
            uStack_70._4_4_ = (uint)*(ushort *)((longlong)param_1 + 0x24c);
          }
          uVar12 = uVar12 & 0xffffffff;
          uStack_70 = CONCAT44(uStack_70._4_4_,0xd4);
          local_78 = 1;
          uVar7 = 4;
          TraceLoggingSetSampleRateFailed(uVar12,uVar16,uVar15,uVar17);
          pbVar13 = (byte *)0xc0050016;
        }
      }
    }
  }
LAB_1c0019724:
  pbVar11 = pbVar13;
  I8xLogError(uVar1,(int)pbVar11,uVar18,(int)uVar12,(undefined4 *)&local_78,uVar7);
LAB_1c001974c:
  *(undefined1 *)((longlong)param_1 + 0x3f7) = 0;
  param_1[0x7d] = 4;
  *(undefined1 *)(param_1 + 0x8a) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,0xf,0x41,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  return uVar12;
}



===== I8xMouseConfiguration @ 1c00197cc =====

undefined8 I8xMouseConfiguration(longlong param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  ulonglong uVar9;
  char *pcVar10;
  undefined4 uVar11;
  byte *pbVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  
  if (param_2 == (byte *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x11,0x42,
                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
    }
  }
  else if ((uint *)(param_2 + 4) != (uint *)0x0) {
    *Globals = *Globals | 2;
    puVar5 = Globals;
    uVar2 = *(uint *)(param_2 + 0x10);
    uVar9 = (ulonglong)uVar2;
    uVar11 = 1;
    *(undefined1 *)(Globals + 0x14) = 0;
    puVar5[5] = *(uint *)(param_2 + 8);
    uVar3 = *(uint *)(param_2 + 4);
    puVar5[4] = uVar3;
    if (uVar2 != 0) {
      uVar14 = (ulonglong)uVar2;
      do {
        uVar13 = uVar14;
        pbVar12 = param_2 + 0x14;
        bVar1 = *pbVar12;
        uVar9 = (ulonglong)bVar1;
        if (bVar1 == 1) {
LAB_1c00198df:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xe,0x43,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,
                              (char)*(undefined2 *)(param_2 + 0x16));
          }
          uVar2 = puVar5[0x10];
          if (uVar2 < 2) {
            uVar4 = *(undefined8 *)(param_2 + 0x1c);
            *(undefined8 *)(puVar5 + (ulonglong)uVar2 * 5 + 6) = *(undefined8 *)pbVar12;
            *(undefined8 *)(puVar5 + (ulonglong)uVar2 * 5 + 6 + 2) = uVar4;
            puVar5[(ulonglong)uVar2 * 5 + 10] = *(uint *)(param_2 + 0x24);
            *(undefined1 *)((longlong)puVar5 + (ulonglong)puVar5[0x10] * 0x14 + 0x19) = 2;
            puVar5[0x10] = puVar5[0x10] + 1;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x11,0x44,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar2);
          }
        }
        else if (bVar1 == 2) {
          uVar4 = *(undefined8 *)(param_2 + 0x1c);
          *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)pbVar12;
          *(undefined8 *)(param_1 + 0x220) = uVar4;
          *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(param_2 + 0x24);
          uVar6 = 3;
          if (uVar3 != 3) {
            uVar6 = 1;
          }
          *(undefined1 *)(param_1 + 0x219) = uVar6;
        }
        else {
          if (bVar1 == 3) {
            DAT_1c0012244 = 1;
            goto LAB_1c00198df;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,1,0x45,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,bVar1);
          }
        }
        uVar14 = uVar13 - 1;
        param_2 = pbVar12;
      } while (uVar14 != 0);
      uVar11 = (undefined4)uVar13;
    }
    *(undefined2 *)(param_1 + 0x248) = 2;
    if ((*(byte *)(param_1 + 0x218) & 2) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x11,0x46,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
      }
      *(undefined1 *)(param_1 + 0x218) = 2;
      uVar7 = 3;
      if (uVar3 != 3) {
        uVar7 = uVar11;
      }
      *(char *)(param_1 + 0x219) = (char)uVar7;
      *(undefined4 *)(param_1 + 0x21c) = 0xc;
      *(undefined4 *)(param_1 + 0x220) = 0xc;
      *(ushort *)(param_1 + 0x21a) = (ushort)(uVar3 != 3);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar10 = "Latched";
      if (*(short *)(param_1 + 0x21a) != (short)uVar11) {
        pcVar10 = "Level Sensitive";
      }
      pcVar8 = "Sharable";
      if (*(char *)(param_1 + 0x219) != '\x03') {
        pcVar8 = "NonSharable";
      }
      WPP_RECORDER_SF_ssD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar10,"NonSharable",0x47,
                          &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,pcVar8,pcVar10,
                          (char)*(undefined4 *)(param_1 + 0x220));
    }
    *Globals = *Globals | 0x200;
    return 0;
  }
  return 0xc000009a;
}



===== I8xMouseServiceParameters @ 1c0019ac4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xMouseServiceParameters(longlong *param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined4 local_res8 [2];
  int local_res10 [2];
  int local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  longlong local_78 [7];
  
  local_c4 = 100;
  local_78[0] = 0;
  local_80 = 0;
  local_c0 = 10000000;
  local_b8 = 0;
  local_bc = 1;
  local_b4 = 0x3c;
  local_res20[0] = 0x3c;
  local_b0 = 3;
  local_c8 = 3;
  local_res10[0] = 1;
  local_84 = 0x5dc;
  local_ac = 0;
  local_res18[0] = 2;
  local_res8[0] = 0;
  local_a8 = 1000;
  local_88 = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  iVar2 = IoOpenDriverRegistryKey(*(undefined8 *)(*param_1 + 8),0,1,0,local_78);
  if (iVar2 < 0) {
    lVar5 = 0;
  }
  else {
    uVar7 = 0x268;
    lVar5 = ExAllocatePool2(0x100,0x268,0x32343038);
    lVar12 = local_78[0];
    if (lVar5 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0x11,0x60,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
      }
    }
    else {
      *(undefined4 *)(lVar5 + 8) = 0x120;
      *(longlong **)(lVar5 + 0x18) = param_1 + 0x4a;
      *(wchar_t **)(lVar5 + 0x10) = L"MouseDataQueueSize";
      *(int **)(lVar5 + 0x28) = &local_c4;
      *(undefined4 *)(lVar5 + 0x30) = 4;
      *(undefined4 *)(lVar5 + 0x20) = 0x4000004;
      *(wchar_t **)(lVar5 + 0x48) = L"NumberOfButtons";
      *(int **)(lVar5 + 0x50) = local_res18;
      *(undefined4 **)(lVar5 + 0x60) = &local_b8;
      *(undefined4 *)(lVar5 + 0x40) = 0x120;
      *(undefined4 *)(lVar5 + 0x68) = 4;
      *(undefined4 *)(lVar5 + 0x58) = 0x4000004;
      *(wchar_t **)(lVar5 + 0x80) = L"SampleRate";
      *(undefined4 **)(lVar5 + 0x88) = local_res20;
      *(undefined4 **)(lVar5 + 0x98) = &local_b4;
      *(undefined4 *)(lVar5 + 0x78) = 0x120;
      *(undefined4 *)(lVar5 + 0xa0) = 4;
      *(undefined4 *)(lVar5 + 0x90) = 0x4000004;
      *(wchar_t **)(lVar5 + 0xb8) = L"MouseResolution";
      *(undefined4 **)(lVar5 + 0xc0) = &local_c8;
      *(undefined4 **)(lVar5 + 0xd0) = &local_b0;
      *(undefined4 *)(lVar5 + 0xb0) = 0x120;
      *(undefined4 *)(lVar5 + 0xd8) = 4;
      *(undefined4 *)(lVar5 + 200) = 0x4000004;
      *(wchar_t **)(lVar5 + 0xf0) = L"MouseSynchIn100ns";
      *(undefined4 **)(lVar5 + 0x108) = &local_c0;
      *(undefined4 *)(lVar5 + 0xe8) = 0x120;
      *(undefined4 *)(lVar5 + 0x110) = 4;
      *(longlong **)(lVar5 + 0xf8) = param_1 + 0x80;
      *(undefined4 *)(lVar5 + 0x100) = 0x4000004;
      *(wchar_t **)(lVar5 + 0x128) = L"EnableWheelDetection";
      *(int **)(lVar5 + 0x130) = local_res10;
      *(undefined4 **)(lVar5 + 0x140) = &local_bc;
      *(undefined4 *)(lVar5 + 0x120) = 0x120;
      *(undefined4 *)(lVar5 + 0x148) = 4;
      *(undefined4 *)(lVar5 + 0x138) = 0x4000004;
      *(wchar_t **)(lVar5 + 0x160) = L"MouseInitializePolled";
      *(undefined4 **)(lVar5 + 0x168) = local_res8;
      *(undefined4 **)(lVar5 + 0x178) = &local_ac;
      *(undefined4 *)(lVar5 + 0x158) = 0x120;
      *(undefined4 *)(lVar5 + 0x180) = 4;
      *(undefined4 *)(lVar5 + 0x170) = 0x4000004;
      *(wchar_t **)(lVar5 + 0x198) = L"MouseResendStallTime";
      *(undefined4 *)(lVar5 + 400) = 0x120;
      *(undefined4 *)(lVar5 + 0x1b8) = 4;
      *(undefined4 **)(lVar5 + 0x1b0) = &local_a8;
      *(longlong **)(lVar5 + 0x1a0) = param_1 + 0x89;
      *(undefined4 *)(lVar5 + 0x1a8) = 0x4000004;
      local_78[1] = 0;
      local_78[2] = 0;
      RtlInitUnicodeString(local_78 + 1,L"RtlQueryRegistryValuesEx");
      pcVar6 = (code *)MmGetSystemRoutineAddress(local_78 + 1);
      if (pcVar6 == (code *)0x0) {
        pcVar6 = RtlQueryRegistryValues_exref;
      }
      iVar2 = (*pcVar6)(0xc0000000,lVar12,lVar5,0,0);
      if (-1 < iVar2) goto LAB_1c0019e40;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar12,0x10,0x61,
                          &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)iVar2);
      }
    }
  }
  *(int *)(param_1 + 0x4a) = local_c4;
  *(undefined1 *)((longlong)param_1 + 0x452) = (undefined1)local_bc;
  *(undefined4 *)(param_1 + 0x80) = local_c0;
LAB_1c0019e40:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_ddddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar7 = 1;
  lVar12 = 0x20000;
  iVar2 = IoOpenDeviceRegistryKey(param_1[4],1,0x20000,&local_80);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar12 = 0x11;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0x11,0x65,
                        &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)iVar2);
    }
  }
  else {
    RtlInitUnicodeString(local_78 + 3,0);
    uVar7 = local_80;
    local_a4 = (undefined4)param_1[0x4a];
    local_a0 = local_res18[0];
    local_9c = local_res20[0];
    local_98 = local_c8;
    local_94 = (undefined4)param_1[0x80];
    local_90 = local_res10[0];
    *(undefined4 *)(lVar5 + 8) = 0x120;
    *(longlong **)(lVar5 + 0x18) = param_1 + 0x4a;
    *(undefined4 *)(lVar5 + 0x20) = 0x4000004;
    *(undefined4 *)(lVar5 + 0x30) = 4;
    local_8c = local_res8[0];
    *(wchar_t **)(lVar5 + 0x10) = L"MouseDataQueueSize";
    *(undefined4 **)(lVar5 + 0x28) = &local_a4;
    *(wchar_t **)(lVar5 + 0x48) = L"NumberOfButtons";
    *(int **)(lVar5 + 0x50) = local_res18;
    *(int **)(lVar5 + 0x60) = &local_a0;
    *(undefined4 *)(lVar5 + 0x40) = 0x120;
    *(undefined4 *)(lVar5 + 0x58) = 0x4000004;
    *(undefined4 *)(lVar5 + 0x68) = 4;
    *(wchar_t **)(lVar5 + 0x80) = L"SampleRate";
    *(undefined4 **)(lVar5 + 0x88) = local_res20;
    *(undefined4 **)(lVar5 + 0x98) = &local_9c;
    *(undefined4 *)(lVar5 + 0x78) = 0x120;
    *(undefined4 *)(lVar5 + 0x90) = 0x4000004;
    *(undefined4 *)(lVar5 + 0xa0) = 4;
    *(wchar_t **)(lVar5 + 0xb8) = L"MouseResolution";
    *(undefined4 **)(lVar5 + 0xc0) = &local_c8;
    *(undefined4 **)(lVar5 + 0xd0) = &local_98;
    *(undefined4 *)(lVar5 + 0xb0) = 0x120;
    *(undefined4 *)(lVar5 + 200) = 0x4000004;
    *(undefined4 *)(lVar5 + 0xd8) = 4;
    *(wchar_t **)(lVar5 + 0xf0) = L"MouseSynchIn100ns";
    *(undefined4 **)(lVar5 + 0x108) = &local_94;
    *(undefined4 *)(lVar5 + 0xe8) = 0x120;
    *(longlong **)(lVar5 + 0xf8) = param_1 + 0x80;
    *(undefined4 *)(lVar5 + 0x100) = 0x4000004;
    *(undefined4 *)(lVar5 + 0x110) = 4;
    *(wchar_t **)(lVar5 + 0x128) = L"EnableWheelDetection";
    *(int **)(lVar5 + 0x130) = local_res10;
    *(int **)(lVar5 + 0x140) = &local_90;
    *(undefined4 *)(lVar5 + 0x120) = 0x120;
    *(undefined4 *)(lVar5 + 0x138) = 0x4000004;
    *(undefined4 *)(lVar5 + 0x148) = 4;
    *(wchar_t **)(lVar5 + 0x160) = L"MouseInitializePolled";
    *(undefined4 **)(lVar5 + 0x168) = local_res8;
    *(undefined4 **)(lVar5 + 0x178) = &local_8c;
    *(undefined4 *)(lVar5 + 0x158) = 0x120;
    *(undefined4 *)(lVar5 + 0x170) = 0x4000004;
    *(undefined4 *)(lVar5 + 0x180) = 4;
    *(undefined4 *)(lVar5 + 0x1b8) = 4;
    *(wchar_t **)(lVar5 + 0x198) = L"WheelDetectIDs";
    *(undefined4 *)(lVar5 + 400) = 0x130;
    *(longlong **)(lVar5 + 0x1a0) = local_78 + 3;
    *(undefined4 **)(lVar5 + 0x1b0) = &local_88;
    *(undefined4 *)(lVar5 + 0x1a8) = 0x7000007;
    *(wchar_t **)(lVar5 + 0x1d0) = L"WheelDetectionTimeout";
    *(undefined4 *)(lVar5 + 0x1c8) = 0x120;
    *(undefined4 *)(lVar5 + 0x1f0) = 4;
    *(undefined4 **)(lVar5 + 0x1e8) = &local_84;
    *(longlong *)(lVar5 + 0x1d8) = (longlong)param_1 + 0x404;
    *(undefined4 *)(lVar5 + 0x1e0) = 0x4000004;
    local_78[1] = 0;
    local_78[2] = 0;
    RtlInitUnicodeString(local_78 + 1,L"RtlQueryRegistryValuesEx");
    pcVar6 = (code *)MmGetSystemRoutineAddress(local_78 + 1);
    if (pcVar6 == (code *)0x0) {
      pcVar6 = RtlQueryRegistryValues_exref;
    }
    lVar12 = lVar5;
    iVar2 = (*pcVar6)(0x40000000,uVar7,lVar5,0,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        lVar12 = 0x11;
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0x11,100,
                          &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)iVar2);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    ZwClose(local_80);
  }
  plVar11 = param_1 + 0x4a;
  plVar8 = local_78 + 3;
  MouseCopyWheelIDs(param_1 + 0x81,(longlong)plVar8);
  RtlFreeUnicodeString(local_78 + 3);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    lVar12 = 0xe;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x66,
                     &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
  }
  iVar2 = (int)*plVar11;
  if ((int)*plVar11 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,lVar12,0x67,
                         &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,L"MouseDataQueueSize",0);
    }
    *(int *)plVar11 = local_c4;
    iVar2 = local_c4;
  }
  *(int *)plVar11 = iVar2 * 0x18;
  *(undefined1 *)((longlong)param_1 + 0x454) = (undefined1)local_res8[0];
  if ((local_res10[0] == 1) || (local_res10[0] == 2)) {
    *(char *)((longlong)param_1 + 0x452) = (char)local_res10[0];
    iVar2 = local_res10[0];
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x452) = 0;
    iVar2 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x68,
                        &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)iVar2),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x69,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)param_1[0x4a]);
  }
  uVar1 = (undefined1)local_res18[0];
  if (local_res18[0] == 0) {
    *(undefined1 *)((longlong)param_1 + 0x453) = 0;
    *(undefined2 *)((longlong)param_1 + 0x24a) = 2;
    uVar1 = 2;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x453) = uVar1;
    *(short *)((longlong)param_1 + 0x24a) = (short)local_res18[0];
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x6a,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,uVar1);
  }
  *(short *)((longlong)param_1 + 0x24c) = (short)local_res20[0];
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x6b,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)local_res20[0]);
  }
  *(char *)((longlong)param_1 + 0x451) = (char)local_c8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x6c,
                        &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)local_c8),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar8,0xe,0x6d,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)param_1[0x89]);
  }
  uVar10 = *(uint *)((longlong)param_1 + 0x404);
  if (4000 < uVar10) {
    uVar10 = 0x5dc;
    *(undefined4 *)((longlong)param_1 + 0x404) = 0x5dc;
  }
  uVar3 = KeQueryTimeIncrement();
  uVar4 = (uVar10 * 10000) / uVar3;
  uVar9 = (ulonglong)(uVar10 * 10000) % (ulonglong)uVar3;
  *(uint *)((longlong)param_1 + 0x404) = uVar4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xe,0x6e,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar4);
  }
  if ((int)param_1[0x80] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x11,0x6f,
                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
    }
    *(undefined4 *)(param_1 + 0x80) = local_c0;
  }
  uVar3 = KeQueryTimeIncrement();
  uVar10 = *(uint *)(param_1 + 0x80);
  uVar4 = uVar10 / uVar3;
  *(uint *)(param_1 + 0x80) = uVar4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                      (ulonglong)uVar10 % (ulonglong)uVar3,0xe,0x70,
                      &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar4);
  }
  if (local_78[0] != 0) {
    ZwClose();
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  return;
}



===== I8xQueryNumberOfMouseButtons @ 1c001a590 =====

ulonglong I8xQueryNumberOfMouseButtons(char *param_1)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 local_res10 [8];
  char local_res18 [16];
  
  local_res10[0] = 0;
  local_res18[0] = '\0';
  uVar2 = I8xPutBytePolled('\0','\x01','\x02',0xe8);
  if ((-1 < (int)uVar2) && (uVar2 = I8xPutBytePolled('\0','\x01','\x02',0), -1 < (int)uVar2)) {
    for (uVar6 = 0; uVar6 < 3; uVar6 = uVar6 + 1) {
      uVar2 = I8xPutBytePolled('\0','\x01','\x02',0xe6);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    uVar2 = I8xPutBytePolled('\0','\x01','\x02',0xe9);
    if (-1 < (int)uVar2) {
      puVar4 = local_res10;
      uVar2 = I8xGetBytePolled('\0',puVar4);
      if (-1 < (int)uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0xe,0x48,
                            &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
        }
        pcVar5 = local_res18;
        uVar2 = I8xGetBytePolled('\0',pcVar5);
        cVar1 = local_res18[0];
        if (-1 < (int)uVar2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,0xe,0x49,
                              &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res18[0]);
          }
          puVar4 = local_res10;
          uVar3 = I8xGetBytePolled('\0',puVar4);
          uVar2 = uVar3 & 0xffffffff;
          if (-1 < (int)uVar3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0xe,0x4a,
                                &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,local_res10[0]);
            }
            if ((byte)(cVar1 - 2U) < 2) {
              *param_1 = cVar1;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0xe,0x4b,
                                  &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,cVar1);
              }
            }
            else {
              *param_1 = '\0';
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,0xe,0x4c,
                                 &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids);
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}



===== I8xTransmitByteSequence @ 1c001a76c =====

ulonglong I8xTransmitByteSequence
                    (longlong param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 *param_5)

{
  byte bVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  uVar5 = 0;
  uVar6 = 0;
  puVar7 = param_3;
  puVar8 = param_4;
  while( true ) {
    bVar1 = *(byte *)(uVar6 + param_1);
    puVar8 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar8 >> 8),bVar1);
    if (bVar1 == 0) {
      return uVar5;
    }
    puVar7 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar7 >> 8),2);
    uVar3 = 1;
    uVar2 = I8xPutBytePolled('\0','\x01','\x02',bVar1);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) break;
    *param_2 = *param_2 + 5;
    uVar6 = (ulonglong)((int)uVar6 + 1);
    KeStallExecutionProcessor();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar8 = (undefined4 *)0x50;
    puVar7 = (undefined4 *)0x11;
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar4,uVar3),0x11,0x50,
                       &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,(char)uVar6,(char)uVar2);
  }
  param_4[1] = 0;
  *param_3 = 0xc0050016;
  *param_4 = 1;
  *param_5 = 4;
  param_4[3] = (uint)*(byte *)(uVar6 + param_1);
  param_4[2] = 0xd4;
  TraceLoggingSetSampleRateFailed(uVar5,CONCAT71(uVar4,uVar3),puVar7,puVar8);
  return uVar5;
}



===== MouseCopyWheelIDs @ 1c001a870 =====

void MouseCopyWheelIDs(undefined8 *param_1,longlong param_2)

{
  undefined2 uVar1;
  void *_Dst;
  longlong lVar3;
  longlong lVar2;
  void *_Src;
  wchar_t *_Str;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (4 < *(ushort *)(param_2 + 2)) {
    _Dst = (void *)ExAllocatePool2(0x40,(uint)*(ushort *)(param_2 + 2) * 2,0x32343038);
    param_1[1] = _Dst;
    if (_Dst != (void *)0x0) {
      _Src = *(void **)(param_2 + 8);
      memcpy(_Dst,_Src,(ulonglong)*(ushort *)(param_2 + 2) * 2);
      uVar1 = *(undefined2 *)(param_2 + 2);
      *(undefined2 *)((longlong)param_1 + 2) = uVar1;
      *(undefined2 *)param_1 = uVar1;
      for (_Str = (wchar_t *)param_1[1]; *_Str != L'\0'; _Str = _Str + lVar3 + 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,0xe,0x5f,
                            &WPP_29d76d6c08853dbe1cdb1688141aa879_Traceguids,_Str);
        }
        _wcsupr(_Str);
        lVar2 = -1;
        do {
          lVar3 = lVar2;
          lVar2 = lVar3 + 1;
        } while (_Str[lVar2] != L'\0');
      }
    }
  }
  return;
}



===== I8xMouseConnectInterruptAndEnable @ 1c001a964 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong I8xMouseConnectInterruptAndEnable(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char *pcVar7;
  code *pcVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  char *pcVar14;
  undefined1 auStackY_d8 [32];
  undefined4 local_68 [2];
  ulonglong local_60;
  longlong lStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xe,10,
                      &WPP_43ac60d525913f552003ebac30591673_Traceguids,(char)param_2);
  }
  plVar1 = param_1 + 1;
  if (*plVar1 == 0) {
    lVar2 = *param_1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar14 = "yes";
      if (*(char *)(Globals + 0x50) == '\0') {
        pcVar14 = "no";
      }
      pcVar10 = "true";
      pcVar7 = "Latched";
      if (*(char *)((longlong)param_1 + 0x219) != '\x03') {
        pcVar10 = "false";
      }
      if (*(short *)((longlong)param_1 + 0x21a) != 1) {
        pcVar7 = "LevelSensitive";
      }
      WPP_RECORDER_SF_qDDDssDs
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar7,pcVar10,0xb,
                 &WPP_43ac60d525913f552003ebac30591673_Traceguids,(char)lVar2,(char)param_1[0x44],
                 (char)*(undefined4 *)((longlong)param_1 + 0x21c),*(undefined1 *)(Globals + 0x44),
                 pcVar7,pcVar10,(char)*(undefined4 *)((longlong)param_1 + 0x224),pcVar14);
    }
    *(undefined1 *)((longlong)param_1 + 0x234) = 1;
    pcVar8 = I8042MouseInterruptService;
    uVar3 = IoConnectInterrupt(plVar1,I8042MouseInterruptService,lVar2,param_1 + 2);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,0x11,0xc,
                         &WPP_43ac60d525913f552003ebac30591673_Traceguids);
      }
      local_68[0] = *(undefined4 *)((longlong)param_1 + 0x21c);
      uVar5 = 0xc0050031;
      uVar13 = 0xc000009a;
      uVar9 = 0x442;
      I8xLogError(lVar2,0xc0050031,0x442,0xc000009a,local_68,1);
      TraceLoggingConnectInterruptFailed(uVar4,uVar5,uVar9,uVar13);
      I8xManuallyRemoveDevice((longlong)param_1,uVar5);
    }
    else {
      local_60 = (ulonglong)(uint)local_60;
      uVar5 = IoGetAttachedDeviceReference(lVar2);
      lStack_58 = *plVar1;
      puVar11 = &local_60;
      puVar12 = (undefined8 *)0x30;
      uVar9 = 0xf3fcf;
      local_60 = 0x30;
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      I8xSendIoctl(uVar5,0xf3fcf,puVar11,0x30);
      ObfDereferenceObject(uVar5);
      if ((char)param_2 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0xe,0xf,
                           &WPP_43ac60d525913f552003ebac30591673_Traceguids);
        }
      }
      else if (*(char *)((longlong)param_1 + 0x454) == '\0') {
        *(undefined2 *)((longlong)param_1 + 0x3f4) = 0xffff;
        *(undefined2 *)(param_1 + 0x46) = 0;
        uVar3 = I8xResetMouse(param_1,uVar9);
        uVar4 = (ulonglong)uVar3;
        if (((int)uVar3 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_Dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        uVar6 = I8xMouseEnableTransmission(param_1,uVar9,puVar11,puVar12);
        uVar4 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,0x11,0xd,
                              &WPP_43ac60d525913f552003ebac30591673_Traceguids,(char)uVar6);
          }
          uVar4 = 0;
        }
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



===== I8xMouseInitializeHardware @ 1c001ad44 =====

int I8xMouseInitializeHardware
              (undefined8 *param_1,longlong *param_2,ulonglong param_3,undefined8 param_4)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  int *piVar4;
  int local_res18 [2];
  int local_res20 [2];
  
  local_res18[0] = -0x3fffffff;
  piVar4 = local_res20;
  local_res20[0] = -0x3fffffff;
  bVar1 = *Globals;
  iVar2 = I8xInitializeHardwareAtBoot(local_res18,piVar4,param_3,param_4);
  if (iVar2 == -0x3ffffff0) {
    I8xManuallyRemoveDevice((longlong)param_2,piVar4);
  }
  else if (-1 < iVar2) {
    if (((local_res18[0] + 0x80000000U & 0x80000000) == 0) && (local_res18[0] != -0x3fffff63)) {
      if (((bVar1 & 1) != 0) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar4,0x11,0x10,
                         &WPP_43ac60d525913f552003ebac30591673_Traceguids);
      }
    }
    else {
      I8xKeyboardConnectInterrupt(param_1);
    }
    if (((local_res20[0] + 0x80000000U & 0x80000000) != 0) || (local_res20[0] == -0x3fffff63)) {
      uVar3 = I8xMouseConnectInterruptAndEnable
                        (param_2,CONCAT71((int7)((ulonglong)piVar4 >> 8),
                                          local_res20[0] != -0x3fffff63));
      local_res20[0] = (int)uVar3;
    }
    return local_res20[0];
  }
  return iVar2;
}



===== I8xMouseInitializeInterruptWorker @ 1c001ae40 =====

void I8xMouseInitializeInterruptWorker(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  if ((int)plVar1[0x7e] != 0x578) {
    *(int *)(plVar1 + 0x74) = (int)plVar1[0x7e];
  }
  I8xResetMouse(plVar1,param_2);
  IoFreeWorkItem(param_2);
  return;
}



===== I8xMouseInitializePolledWorker @ 1c001ae90 =====

void I8xMouseInitializePolledWorker
               (longlong param_1,undefined8 param_2,ulonglong param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar5 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = (undefined8 *)0x28;
    param_3 = 0x11;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x28,
                     &WPP_43ac60d525913f552003ebac30591673_Traceguids);
  }
  if (((*Globals & 1) != 0) && (DAT_1c00121d0 != 0)) {
    uVar6 = *(undefined4 *)(DAT_1c00121d0 + 0x50);
    *(undefined4 *)(DAT_1c00121d0 + 0x50) = 4;
  }
  I8xToggleInterrupts('\0',uVar5,param_3,param_4);
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  uVar3 = I8xInitializeMouse(puVar1,uVar5,param_3,param_4);
  iVar2 = (int)uVar3;
  I8xToggleInterrupts('\x01',uVar5,param_3,param_4);
  uVar3 = (ulonglong)*Globals;
  if (((*Globals & 1) != 0) && (DAT_1c00121d0 != 0)) {
    *(undefined4 *)(DAT_1c00121d0 + 0x50) = uVar6;
  }
  if ((-1 < iVar2) && ((*Globals & 2) != 0)) {
    uVar4 = I8xMouseEnableTransmission(puVar1,uVar3,param_3,param_4);
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x11,0x29,
                         &WPP_43ac60d525913f552003ebac30591673_Traceguids);
      }
      I8xFinishResetRequest(puVar1,0,'\x01','\0');
      goto LAB_1c001afce;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0x11,0x2a,
                      &WPP_43ac60d525913f552003ebac30591673_Traceguids,(char)iVar2);
  }
  I8xResetMouseFailed(puVar1,uVar3);
LAB_1c001afce:
  IoFreeWorkItem(param_2);
  return;
}



===== I8xMouseRemoveDevice @ 1c001b000 =====

void I8xMouseRemoveDevice(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x19,
                     &WPP_43ac60d525913f552003ebac30591673_Traceguids);
  }
  if ((*(char *)(lVar1 + 0x233) != '\0') && (*(longlong *)(lVar1 + 0x438) != 0)) {
    IoUnregisterPlugPlayNotification();
    *(undefined8 *)(lVar1 + 0x438) = 0;
  }
  if (*(longlong *)(lVar1 + 8) != 0) {
    IoDisconnectInterrupt();
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x3b0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x3b0),0);
    *(undefined8 *)(lVar1 + 0x3b0) = 0;
  }
  RtlFreeUnicodeString(lVar1 + 0x408);
  if (DAT_1c00121c8 == lVar1) {
    *Globals = *Globals & 0xfffffdf5;
    DAT_1c00121c8 = 0;
  }
  return;
}



===== I8xMouseStartDevice @ 1c001b0e4 =====

ulonglong I8xMouseStartDevice(byte *param_1,byte *param_2,ulonglong param_3,undefined8 param_4)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  char *pcVar7;
  byte *pbVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined4 local_res18 [2];
  byte *local_28;
  undefined8 uStack_20;
  
  local_28 = (byte *)0x0;
  uStack_20 = 0;
  pbVar8 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_3 = 0xf;
    param_4 = 0x11;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x11,
                     &WPP_43ac60d525913f552003ebac30591673_Traceguids);
  }
  if ((*Globals & 0x200) == 0) {
    if (*(longlong *)(param_1 + 0x1b8) == 0) {
      param_2 = pbVar8;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar8,0x11,0x13,
                         &WPP_43ac60d525913f552003ebac30591673_Traceguids);
        param_2 = pbVar8;
      }
      uVar9 = 0xc0000184;
    }
    else {
      uVar5 = I8xMouseConfiguration((longlong)param_1,param_2);
      uVar9 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) {
        iVar3 = I8xManuallyRemoveDevice((longlong)param_1,param_2);
        if (0 < iVar3) goto LAB_1c001b4cd;
      }
      else {
        lVar2 = *(longlong *)param_1;
        DAT_1c00121c8 = param_1;
        if ((byte)Globals[0x11] < param_1[0x21c]) {
          *(byte *)(Globals + 0x11) = param_1[0x21c];
        }
        I8xMouseServiceParameters((longlong *)param_1);
        uVar5 = (ulonglong)*(uint *)(param_1 + 0x250);
        lVar6 = ExAllocatePool2(0x40,uVar5,0x32343038);
        *(longlong *)(param_1 + 0x3b0) = lVar6;
        if (lVar6 != 0) {
          *(ulonglong *)(param_1 + 0x3c8) = (ulonglong)*(uint *)(param_1 + 0x250) + lVar6;
          uStack_20 = CONCAT71(uStack_20._1_7_,2);
          local_28 = param_1;
          I8xInitializeDataQueue((longlong *)&local_28,uVar5);
          param_1[0x3a8] = 0xff;
          param_1[0x3a9] = 0xff;
          param_1[0x3aa] = 0xff;
          param_1[0x3ab] = 0xff;
          KeInitializeDpc(param_1 + 0xe8,I8042ErrorLogDpc,lVar2);
          KeInitializeDpc(param_1 + 0x260,I8042MouseIsrDpc,lVar2);
          KeInitializeDpc(param_1 + 0x2a0,I8042MouseIsrDpc,lVar2);
          KeInitializeDpc(param_1 + 0x2e0,I8xIsrResetDpc,param_1);
          bVar1 = param_1[0x454];
          if (bVar1 == 0) {
            KeInitializeDpc(param_1 + 800);
            KeInitializeTimer(param_1 + 0x360);
          }
          else {
            KeInitializeDpc(param_1 + 800,I8xMouseEnableDpc);
            KeInitializeTimerEx(param_1 + 0x360);
          }
          param_1[0x454] = bVar1 != 0;
          I8xInitWmi((undefined8 *)param_1);
          param_2 = (byte *)0x0;
          param_1[0x233] = 1;
          uVar10 = *(undefined8 *)(lVar2 + 8);
          uVar5 = 0;
          IoRegisterPlugPlayNotification(1);
          if (((*Globals & 1) == 0) ||
             ((DAT_1c00121d0 != (undefined8 *)0x0 &&
              (*(char *)((longlong)DAT_1c00121d0 + 0x236) != '\0')))) {
            uVar4 = I8xMouseInitializeHardware(DAT_1c00121d0,(longlong *)param_1,uVar5,uVar10);
            uVar9 = (ulonglong)uVar4;
            param_2 = param_1;
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return uVar9;
            }
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x15,
                             &WPP_43ac60d525913f552003ebac30591673_Traceguids);
          }
          goto LAB_1c001b4cd;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x11,0x14,
                           &WPP_43ac60d525913f552003ebac30591673_Traceguids);
        }
        local_res18[0] = *(undefined4 *)(param_1 + 0x250);
        uVar9 = 0xc000009a;
        param_4 = 0xc000009a;
        param_2 = (byte *)0xc0050030;
        param_3 = 0x41a;
        I8xLogError(lVar2,0xc0050030,0x41a,0xc000009a,local_res18,1);
        TraceLoggingAllocateMemoryFailed
                  ((ulonglong)*(uint *)(param_1 + 0x250),param_2,param_3,param_4);
      }
      if (((DAT_1c00121d0 != (undefined8 *)0x0) &&
          (*(char *)((longlong)DAT_1c00121d0 + 0x236) != '\0')) && ((*Globals & 0x100) == 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = 0x16;
          param_3 = 0x10;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x16,
                           &WPP_43ac60d525913f552003ebac30591673_Traceguids);
        }
        I8xKeyboardInitializeHardware(DAT_1c00121d0,(longlong *)param_1,param_3,param_4);
        param_2 = param_1;
      }
    }
  }
  else {
    param_2 = pbVar8;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar8,0x11,0x12,
                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
      param_2 = pbVar8;
    }
    LOCK();
    DAT_1c00121fc = DAT_1c00121fc + -1;
    UNLOCK();
    uVar9 = 0xc000000e;
  }
LAB_1c001b4cd:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar7 = "successful";
    if ((int)uVar9 < 0) {
      pcVar7 = "unsuccessful";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x17,
                      &WPP_43ac60d525913f552003ebac30591673_Traceguids,pcVar7);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x18,
                        &WPP_43ac60d525913f552003ebac30591673_Traceguids,(char)uVar9);
    }
  }
  return uVar9;
}



===== I8xProfileNotificationCallback @ 1c001b560 =====

undefined8 I8xProfileNotificationCallback(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4003;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar1 == 0) {
    plVar2 = param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x1a,
                       &WPP_43ac60d525913f552003ebac30591673_Traceguids);
    }
    *(undefined2 *)((longlong)param_2 + 0x3f4) = 0xffff;
    *(undefined2 *)(param_2 + 0x46) = 0;
    I8xResetMouse(param_2,plVar2);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xe,0x1b,
                     &WPP_43ac60d525913f552003ebac30591673_Traceguids);
  }
  return 0;
}



===== I8xAddDevice @ 1c001b630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int I8xAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_b8 [32];
  undefined4 local_70 [2];
  undefined1 local_68 [32];
  undefined4 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,10,
                     &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
  }
  uVar7 = 0x27;
  iVar2 = IoCreateDevice(param_1,0x458,0);
  if (-1 < iVar2) {
    uVar6 = 0x458;
    memset(puRam0000000000000040,0,0x458);
    puVar1 = puRam0000000000000040;
    lVar3 = IoAttachDeviceToDeviceStack(0,param_2);
    puVar1[3] = lVar3;
    if (lVar3 == 0) {
      puVar4 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
      iVar2 = -0x3fffff63;
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[3] = 0xc0050037;
        *puVar4 = 0;
        *(undefined8 *)(puVar4 + 6) = 0;
        puVar4[4] = 0;
        puVar4[5] = 0xc000009d;
        IoWriteErrorLogEntry(puVar4);
      }
      if (5 < DAT_1c0012010) {
        uVar5 = _tlgKeywordOn();
        if ((char)uVar5 != '\0') {
          local_48 = local_70;
          local_70[0] = 0xc000009d;
          local_40 = 4;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_68,&DAT_1c00100e0,uVar6,uVar7,3,(undefined8 *)local_68);
        }
      }
      IoDeleteDevice(0);
    }
    else {
      *puVar1 = 0;
      puVar1[4] = param_2;
      *(undefined4 *)(puVar1 + 10) = 1;
      puVar1[0x47] = 0;
      *(undefined4 *)(puVar1 + 0x48) = 0;
      KeInitializeSpinLock(puVar1 + 2);
      KeInitializeTimer(puVar1 + 0xd);
      KeInitializeDpc(puVar1 + 0x1d,I8042ErrorLogDpc,0);
      KeInitializeDpc(puVar1 + 0x15,I8042RetriesExceededDpc,0);
      KeInitializeDpc(puVar1 + 0x25,I8042TimeOutDpc,0);
      KeInitializeDpc(200,I8042CompletionDpc);
      uVar7 = 0x32343038;
      IoInitializeRemoveLockEx(puVar1 + 5,0x32343038,0,0);
      uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
      IoSetStartIoAttributes(0,uVar7,0);
      uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f | 0x2004;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,0xf,0xb,
                          &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)iVar2);
      }
    }
  }
  return iVar2;
}



===== I8xFilterResourceRequirements @ 1c001b914 =====

undefined8 I8xFilterResourceRequirements(longlong param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  char *pcVar10;
  ulonglong uVar11;
  uint *_Dst;
  uint *puVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint *puVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  char *local_res10;
  undefined4 local_res18 [2];
  uint local_res20 [2];
  undefined *in_stack_ffffffffffffff88;
  
  uVar19 = 0;
  bVar6 = false;
  bVar5 = false;
  pcVar16 = "kb";
  pcVar13 = param_2;
  local_res10 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar13 = "mouse";
    pcVar10 = "kb";
    if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x235) == '\0') {
      pcVar10 = "mouse";
    }
    in_stack_ffffffffffffff88 = &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"mouse",0xe,0x1e,
                      &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar10);
  }
  puVar12 = *(uint **)(param_2 + 0x38);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (puVar12 == (uint *)0x0) {
    puVar12 = *(uint **)(lVar3 + 8);
    *(uint **)(param_2 + 0x38) = puVar12;
    if (puVar12 == (uint *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x235) == '\0') {
        pcVar16 = "mou";
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar13,0xf,0x1f,
                        &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar16);
      return 0;
    }
  }
  if (1 < puVar12[7]) {
    return 0;
  }
  iVar9 = 0;
  uVar14 = 0;
  bVar7 = false;
  bVar8 = false;
  if (puVar12[9] != 0) {
    do {
      bVar6 = bVar8;
      bVar5 = bVar7;
      cVar1 = *(char *)((longlong)puVar12 + (ulonglong)uVar14 * 0x20 + 0x29);
      if (cVar1 == '\x01') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffff88 = &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids;
          WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar13,0x10,0x20,
                             &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,
                             (char)puVar12[(ulonglong)uVar14 * 8 + 10],
                             (char)puVar12[(ulonglong)uVar14 * 8 + 0xb]);
        }
        uVar11 = I8xRemovePort((longlong)(puVar12 + (ulonglong)uVar14 * 8 + 10));
        if ((char)uVar11 != '\0') {
          iVar9 = iVar9 + 1;
          *(undefined1 *)((longlong)puVar12 + (ulonglong)uVar14 * 0x20 + 0x29) = 0xef;
        }
        bVar5 = true;
      }
      else if (cVar1 == '\x02') {
        if (*(char *)((longlong)Globals + 0x51) != '\0') {
          if ((*(char *)((longlong)puVar12 + (ulonglong)uVar14 * 0x20 + 0x2a) != '\x03') &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff88 = &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar13,0x10,0x21,
                             &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
          }
          *(undefined1 *)((longlong)puVar12 + (ulonglong)uVar14 * 0x20 + 0x2a) = 3;
        }
        bVar6 = true;
      }
      param_2 = local_res10;
      uVar14 = uVar14 + 1;
      bVar7 = bVar5;
      bVar8 = bVar6;
    } while (uVar14 < puVar12[9]);
    if (iVar9 != 0) {
      uVar14 = *puVar12;
      if (1 < puVar12[9]) {
        uVar14 = uVar14 + iVar9 * -0x20;
      }
      uVar11 = (ulonglong)uVar14;
      uVar18 = 0x32343038;
      _Dst = (uint *)ExAllocatePool2(0x100);
      if (_Dst == (uint *)0x0) {
        uVar14 = *(uint *)(*(longlong *)(lVar3 + 8) + 0x1c);
        if (uVar14 == 0) {
          return 0;
        }
        puVar12 = (uint *)(*(longlong *)(lVar3 + 8) + 0x24);
        uVar19 = (ulonglong)uVar14;
        do {
          uVar14 = 0;
          if (*puVar12 != 0) {
            do {
              if (*(char *)((ulonglong)uVar14 * 0x20 + 5 + (longlong)puVar12) == -0x11) {
                *(undefined1 *)((ulonglong)uVar14 * 0x20 + 5 + (longlong)puVar12) = 1;
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *puVar12);
          }
          puVar12 = puVar12 + 10;
          uVar19 = uVar19 - 1;
        } while (uVar19 != 0);
        return 0;
      }
      uVar4 = *(undefined8 *)(puVar12 + 2);
      *(undefined8 *)_Dst = *(undefined8 *)puVar12;
      *(undefined8 *)(_Dst + 2) = uVar4;
      uVar4 = *(undefined8 *)(puVar12 + 6);
      *(undefined8 *)(_Dst + 4) = *(undefined8 *)(puVar12 + 4);
      *(undefined8 *)(_Dst + 6) = uVar4;
      *_Dst = uVar14;
      puVar17 = _Dst + 10;
      *(undefined8 *)(_Dst + 8) = *(undefined8 *)(puVar12 + 8);
      _Dst[9] = 0;
      if (puVar12[9] != 0) {
        do {
          if (*(char *)(uVar19 * 0x20 + 0x29 + (longlong)puVar12) == -0x11) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DDDD
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar11,uVar18,0x23,
                         in_stack_ffffffffffffff88,(char)puVar12[uVar19 * 8 + 0xf],
                         (char)puVar12[uVar19 * 8 + 0xe],(char)puVar12[uVar19 * 8 + 0x11],
                         (char)puVar12[uVar19 * 8 + 0x10]);
            }
          }
          else {
            uVar4 = *(undefined8 *)(puVar12 + uVar19 * 8 + 10 + 2);
            *(undefined8 *)puVar17 = *(undefined8 *)(puVar12 + uVar19 * 8 + 10);
            *(undefined8 *)(puVar17 + 2) = uVar4;
            uVar4 = *(undefined8 *)(puVar12 + uVar19 * 8 + 0xe + 2);
            *(undefined8 *)(puVar17 + 4) = *(undefined8 *)(puVar12 + uVar19 * 8 + 0xe);
            *(undefined8 *)(puVar17 + 6) = uVar4;
            puVar17 = puVar17 + 8;
            _Dst[9] = _Dst[9] + 1;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
          }
          uVar14 = (int)uVar19 + 1;
          uVar19 = (ulonglong)uVar14;
        } while (uVar14 < puVar12[9]);
      }
      memset(puVar12,0,(ulonglong)*puVar12);
      goto LAB_1c001bd87;
    }
  }
  if ((*Globals & 1) != 0) {
    return 0;
  }
  if (bVar5) {
    return 0;
  }
  if (!bVar6) {
    return 0;
  }
  local_res18[0] = 0x16;
  local_res10 = (char *)CONCAT44(local_res10._4_4_,0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar13,0x10,0x24,
                     &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
  }
  uVar14 = *puVar12;
  _Dst = (uint *)ExAllocatePool2(0x100,uVar14 + 0x40,0x32343038);
  if (_Dst == (uint *)0x0) {
    return 0;
  }
  memcpy(_Dst,puVar12,(ulonglong)*puVar12);
  uVar15 = 0;
  uVar2 = _Dst[9];
  do {
    local_res20[0] = uVar15;
    iVar9 = IoQueryDeviceDescription
                      (local_res20,0,local_res18,0,&local_res10,0,I8xFindPortCallout,_Dst + 8);
    if ((-1 < iVar9) || (uVar2 != _Dst[9])) goto LAB_1c001bd78;
    uVar15 = uVar15 + 1;
  } while (uVar15 < 0x12);
  if (uVar2 == _Dst[9]) {
    ExFreePoolWithTag(_Dst,0);
    return 0;
  }
LAB_1c001bd78:
  *_Dst = (_Dst[9] - uVar2) + -2 + uVar14 + 0x40;
LAB_1c001bd87:
  ExFreePoolWithTag(puVar12,0);
  *(uint **)(lVar3 + 8) = _Dst;
  *(uint **)(param_2 + 0x38) = _Dst;
  return 0;
}



===== I8xFindPortCallout @ 1c001bdd0 =====

undefined4 I8xFindPortCallout(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  longlong in_stack_00000040;
  
  uVar2 = *(uint *)(param_1 + 4);
  uVar7 = 0xc0000001;
  lVar4 = *(longlong *)(in_stack_00000040 + 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x1a,
                     &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
  }
  if (*(int *)(lVar4 + 0xc) != 0) {
    uVar3 = *(uint *)((ulonglong)*(uint *)(lVar4 + 8) + 0xc + lVar4);
    if (uVar3 != 0) {
      uVar6 = (ulonglong)uVar3;
      pbVar5 = (byte *)(lVar4 + 0x10 + (ulonglong)*(uint *)(lVar4 + 8));
      puVar8 = (undefined2 *)((ulonglong)uVar2 * 0x20 + 0xc + param_1);
      do {
        bVar1 = *pbVar5;
        param_2 = (ulonglong)bVar1;
        if (bVar1 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          *(byte *)((longlong)puVar8 + -3) = *pbVar5;
          *puVar8 = *(undefined2 *)(pbVar5 + 2);
          *(undefined1 *)(puVar8 + -1) = 1;
          *(undefined4 *)(puVar8 + 4) = 1;
          uVar2 = *(uint *)(pbVar5 + 0xc);
          *(uint *)(puVar8 + 2) = uVar2;
          lVar4 = *(longlong *)(pbVar5 + 4);
          *(longlong *)(puVar8 + 6) = lVar4;
          *(ulonglong *)(puVar8 + 10) = lVar4 + ((ulonglong)uVar2 - 1);
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
          I8xRemovePort((longlong)(puVar8 + -2));
          puVar8 = puVar8 + 0x10;
          uVar7 = 0;
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xe,0x1c,
                            &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,bVar1);
        }
        pbVar5 = pbVar5 + 0x14;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x1d,
                      &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)uVar7);
  }
  return uVar7;
}



===== I8xManuallyRemoveDevice @ 1c001bf78 =====

int I8xManuallyRemoveDevice(longlong param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x235) == '\0') {
    LOCK();
    iVar1 = DAT_1c00121fc + -1;
    UNLOCK();
    iVar2 = DAT_1c00121fc + -1;
    DAT_1c00121fc = iVar1;
    if (iVar2 < 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x18,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      *Globals = *Globals & 0xfffffdf5;
    }
  }
  else {
    LOCK();
    iVar1 = DAT_1c00121f8 + -1;
    UNLOCK();
    iVar2 = DAT_1c00121f8 + -1;
    DAT_1c00121f8 = iVar1;
    if (iVar2 < 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x10,0x17,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      *Globals = *Globals & 0xfffffefe;
    }
  }
  *(uint *)(param_1 + 0x22c) = *(uint *)(param_1 + 0x22c) | 10;
  IoInvalidateDeviceState(*(undefined8 *)(param_1 + 0x20));
  return iVar2;
}



===== I8xRegisterDeviceInterface @ 1c001c068 =====

void I8xRegisterDeviceInterface(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = IoRegisterDeviceInterface(param_1,&GUID_DEVICE_SYS_BUTTON,0,param_3);
  if (-1 < iVar1) {
    IoSetDeviceInterfaceState(param_3,1);
  }
  return;
}



===== I8xRemovePort @ 1c001c0ac =====

ulonglong I8xRemovePort(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  int iStackX_14;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar2 = Globals;
  uVar1 = *(uint *)(Globals + 0xf0);
  if (uVar1 != 0xffffffff) {
    in_RAX = *(ulonglong *)(param_1 + 0x10);
    uVar3 = 0;
    iStackX_14 = (int)(in_RAX >> 0x20);
    while( true ) {
      if (uVar1 <= (uint)uVar3) break;
      if (((int)in_RAX == *(int *)(Globals + 0xe0 + uVar3 * 8)) &&
         (iStackX_14 == *(int *)(Globals + 0xe4 + uVar3 * 8))) {
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
      uVar3 = (ulonglong)((uint)uVar3 + 1);
    }
    if (uVar1 < 2) {
      *(ulonglong *)(Globals + 0xe0 + (ulonglong)uVar1 * 8) = in_RAX;
      *(int *)(Globals + 0xf0) = *(int *)(Globals + 0xf0) + 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_RAX = WPP_RECORDER_SF_DDDD
                         (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,lVar2,0x19,
                          in_stack_ffffffffffffffc8,(char)(in_RAX >> 0x20),(char)in_RAX,
                          (char)*(undefined4 *)(param_1 + 0x1c),
                          (char)*(undefined4 *)(param_1 + 0x18));
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== I8xSendIrpSynchronously @ 1c001c164 =====

ulonglong I8xSendIrpSynchronously(undefined8 param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,1,0);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = I8xPnPComplete;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar3 = IofCallDriver(param_1,param_2);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  if ((param_3 == '\0') && (((int)uVar3 == -0x3fffff45 || ((int)uVar3 == -0x3ffffff0)))) {
    uVar3 = 0;
  }
  return uVar3;
}



===== I8xCompleteSysButtonEventWorker @ 1c001c260 =====

void I8xCompleteSysButtonEventWorker(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_2[2] + 0x44) != '\0') {
    *(undefined4 *)(param_2 + 1) = 0;
    uVar1 = 0xc0000120;
  }
  I8xCompleteSysButtonIrp(param_2[2],*(undefined4 *)(param_2 + 1),uVar1);
  IoFreeWorkItem(*param_2);
  ExFreePoolWithTag(param_2,0);
  return;
}



===== I8xKeyboardGetSysButtonCaps @ 1c001c2b8 =====

undefined4 I8xKeyboardGetSysButtonCaps(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x19,0xb,
                       &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
    }
    uVar4 = 0xc0000206;
    uVar5 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x248);
    uVar3 = 0;
    lVar2 = param_2;
    if ((bVar1 & 1) != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,10,0xc,
                         &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        bVar1 = *(byte *)(param_1 + 0x248);
      }
      uVar3 = 1;
    }
    if ((bVar1 & 2) != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,10,0xd,
                         &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        bVar1 = *(byte *)(param_1 + 0x248);
      }
      uVar3 = uVar3 | 2;
    }
    if ((bVar1 & 4) != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,10,0xe,
                         &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
      }
      uVar3 = uVar3 | 0x80000000;
    }
    **(uint **)(param_2 + 0x18) = uVar3;
    uVar4 = 0;
    uVar5 = 4;
  }
  *(undefined8 *)(param_2 + 0x38) = uVar5;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== I8xUpdateSysButtonCaps @ 1c001c420 =====

void I8xUpdateSysButtonCaps(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10 = 0;
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_28 = 0;
  uStack_20 = 0;
  if (*(int *)(param_2 + 1) != 0) {
    uVar5 = 1;
    iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x20),1,0x1f0000,&local_res10);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x19,0x1f,
                         &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
      }
    }
    else {
      iVar3 = *(int *)(param_2 + 1);
      if (iVar3 == 0x5e) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x16,0x19,
                           &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        }
        *(byte *)(lVar1 + 0x248) = *(byte *)(lVar1 + 0x248) | 1;
      }
      else if (iVar3 == 0x5f) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x16,0x1a,
                           &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        }
        *(byte *)(lVar1 + 0x248) = *(byte *)(lVar1 + 0x248) | 2;
      }
      else if (iVar3 == 99) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x16,0x1b,
                           &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        }
        *(byte *)(lVar1 + 0x248) = *(byte *)(lVar1 + 0x248) | 4;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,0x19,0x1c,
                          &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,(char)iVar3);
      }
      RtlInitUnicodeString(&local_28,L"PowerCapabilities");
      puVar6 = &local_28;
      local_res8[0] = (uint)*(byte *)(lVar1 + 0x248);
      ZwSetValueKey(local_res10,puVar6,0,4,local_res8,4);
      ZwClose(local_res10);
      if (*(longlong *)(lVar1 + 0x2a8) == 0) {
        uVar2 = I8xRegisterDeviceInterface(*(undefined8 *)(lVar1 + 0x20),puVar6,lVar1 + 0x2a0);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,0x16,0x1d,
                            &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids,uVar2);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,0x18,0x1e,
                           &WPP_9a74d45702a83a61696de9b252942f2f_Traceguids);
        }
        uVar4 = I8xUpdateSysButtonCapsGetPendedIrp(lVar1);
        if (uVar4 != 0) {
          I8xCompleteSysButtonIrp(uVar4,0,0xc000009d);
        }
        IoSetDeviceInterfaceState(lVar1 + 0x2a0,0);
        IoSetDeviceInterfaceState(lVar1 + 0x2a0,1);
      }
    }
  }
  IoFreeWorkItem(*param_2);
  ExFreePoolWithTag(param_2,0);
  return;
}



===== I8xInitWmi @ 1c001c708 =====

void I8xInitWmi(undefined8 *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  code *pcVar3;
  
  cVar1 = *(char *)((longlong)param_1 + 0x235);
  ppuVar2 = &KbWmiGuidList;
  *(uint *)(param_1 + 0x38) = (cVar1 != '\0') + 1;
  if (cVar1 == '\0') {
    ppuVar2 = &MouWmiGuidList;
  }
  param_1[0x39] = ppuVar2;
  pcVar3 = I8xKeyboardQueryWmiDataBlock;
  if (cVar1 == '\0') {
    pcVar3 = I8xMouseQueryWmiDataBlock;
  }
  param_1[0x3b] = pcVar3;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x3a] = I8xQueryWmiRegInfo;
  param_1[0x3c] = I8xSetWmiDataBlock;
  param_1[0x3d] = I8xSetWmiDataBlock;
  IoWMIRegistrationControl(*param_1,1);
  return;
}



===== I8xKeyboardQueryWmiDataBlock @ 1c001c7c0 =====

void I8xKeyboardQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined8 *param_8)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  lVar4 = *(longlong *)(param_1 + 0x40);
  if (param_3 == 0) {
    uVar6 = 0x14;
    if (param_7 < 0x14) {
LAB_1c001c81f:
      uVar5 = 0xc0000023;
      goto LAB_1c001c86a;
    }
    uVar3 = *(uint *)(lVar4 + 700);
    uVar1 = *(ushort *)(lVar4 + 0x2b4);
    uVar2 = *(ushort *)(lVar4 + 0x2b6);
    *(undefined4 *)param_8 = 0;
    *(uint *)((longlong)param_8 + 4) = uVar3 / 0xc;
    *(undefined4 *)(param_8 + 1) = 0;
    *(uint *)((longlong)param_8 + 0xc) = (uint)uVar1;
    *(uint *)(param_8 + 2) = (uint)uVar2;
  }
  else {
    if (param_3 != 1) {
      uVar5 = 0xc0000295;
      goto LAB_1c001c86a;
    }
    uVar6 = 8;
    if (param_7 < 8) goto LAB_1c001c81f;
    *param_8 = *(undefined8 *)(lVar4 + 0x2cc);
  }
  uVar5 = 0;
  *param_6 = uVar6;
LAB_1c001c86a:
  WmiCompleteRequest(param_1,param_2,uVar5,uVar6,0);
  return;
}



===== I8xMouseQueryWmiDataBlock @ 1c001c8a0 =====

void I8xMouseQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined4 *param_8)

{
  ushort uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    if (param_7 < 0x14) {
      uVar3 = 0xc0000023;
    }
    else {
      uVar2 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x250);
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x40) + 0x24a);
      *param_8 = 0;
      param_8[1] = uVar2 / 0x18;
      param_8[2] = 0;
      param_8[3] = (uint)uVar1;
      param_8[4] = 0;
      uVar3 = 0;
      *param_6 = 0x14;
    }
  }
  else {
    uVar3 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar3,0x14,0);
  return;
}



===== I8xQueryWmiRegInfo @ 1c001c940 =====

undefined8
I8xQueryWmiRegInfo(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
                  undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &DAT_1c00121e8;
  *param_6 = *(undefined8 *)(lVar1 + 0x20);
  return 0;
}



===== I8xSetWmiDataBlock @ 1c001c970 =====

void I8xSetWmiDataBlock(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_3 == 0) || (uVar1 = 0xc0000295, param_3 == 1)) {
    uVar1 = 0xc00002c6;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== I8xInitializeKeyboard @ 1c001c9b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong I8xInitializeKeyboard
                    (undefined8 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  char cVar11;
  byte *pbVar12;
  undefined8 uVar13;
  wchar_t *pwVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  code *pcVar17;
  code *pcVar18;
  bool bVar19;
  undefined1 auStackY_108 [32];
  uint uVar20;
  byte local_c7 [3];
  uint local_c4;
  char local_c0;
  byte local_bf;
  undefined8 local_b8;
  uint local_b0;
  undefined8 local_a8;
  uint local_a0;
  ulonglong local_98;
  ulonglong local_90;
  uint local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  ulonglong local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c7[0] = 0;
  local_90 = local_90 & 0xffffffff00000000;
  uVar15 = 1;
  local_a8 = 0;
  bVar1 = false;
  local_a0 = 0;
  local_98 = local_98 & 0xffffffff00000000;
  local_b0 = 0;
  local_88 = 0;
  local_c4 = 0;
  local_80 = 0;
  local_c0 = '\x01';
  bVar19 = false;
  local_bf = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0;
    param_3 = (undefined8 *)0x0;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x21,
                     &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
  }
  local_b8 = *param_1;
  local_48 = 0;
  uStack_40 = 0;
  do {
    bVar2 = false;
    param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xff);
    param_3 = (undefined8 *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
    cVar11 = (char)uVar15;
    uVar9 = I8xPutBytePolled('\0',cVar11,'\x01',0xff);
    uVar20 = (uint)uVar9;
    if ((int)uVar20 < 0) {
      bVar1 = true;
      local_b0 = uVar20;
      if (*(char *)((longlong)param_1 + 0x3ba) == '\0') {
        uVar9 = 0xc000009d;
        *Globals = *Globals | 0x4000;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x10,0x22,
                           &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          bVar3 = false;
          bVar6 = 0;
          goto LAB_1c001cbea;
        }
        bVar3 = false;
        bVar6 = 0;
        goto LAB_1c001cc2d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 0x23;
        param_3 = (undefined8 *)0x10;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x10,0x23,
                         &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
    }
    lVar4 = _DAT_fffff78000000320;
    local_80 = 0xffffffffffffff9c;
    bVar2 = false;
    do {
      pbVar12 = local_c7;
      uVar10 = I8xGetBytePolled('\x01',pbVar12);
      uVar9 = uVar10 & 0xffffffff;
      uVar20 = (uint)uVar10;
      if (-1 < (int)uVar20) {
        bVar19 = local_c7[0] != 0xaa;
        if (bVar19) {
          local_bf = local_c7[0];
          local_88 = uVar20;
        }
        local_a8 = CONCAT26(local_a8._6_2_,0xbf0100000000);
        local_a8 = CONCAT44(local_a8._4_4_,*Globals);
        I8xTransmitControllerCommand((uint *)&local_a8,pbVar12,(ulonglong)param_3,param_4);
        if ((int)local_a0 < 0) {
          I8xTransmitControllerCommand((uint *)&local_a8,pbVar12,(ulonglong)param_3,param_4);
          uVar9 = (ulonglong)local_a0;
          if ((int)local_a0 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                               0x11,0x25,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
            }
            bVar3 = false;
            bVar6 = 0;
            goto LAB_1c001d24c;
          }
        }
        uVar15 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        uVar9 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xf3);
        uVar13 = 1;
        uVar10 = I8xPutBytePolled('\0','\x01','\x01',0xf3);
        if ((int)uVar10 == 0) {
          bVar6 = I8xConvertTypematicParameters
                            (*(ushort *)((longlong)param_1 + 0x2d6),
                             (ulonglong)*(ushort *)(param_1 + 0x5b));
          uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),1);
          uVar9 = 0;
          uVar13 = 1;
          uVar10 = I8xPutBytePolled('\0','\x01','\x01',bVar6);
          if ((int)uVar10 == 0) {
            bVar3 = false;
            goto LAB_1c001ce73;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,0x11,0x27,
                             &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          }
          local_48 = 1;
          uStack_40 = CONCAT44(uStack_40._4_4_,0xf3);
          bVar6 = I8xConvertTypematicParameters
                            (*(ushort *)((longlong)param_1 + 0x2d6),
                             (ulonglong)*(ushort *)(param_1 + 0x5b));
          uVar13 = local_b8;
          uVar9 = uVar10 & 0xffffffff;
          uVar16 = 0x80050013;
          uStack_40 = (ulonglong)CONCAT14(bVar6,(undefined4)uStack_40);
          uVar15 = 0x604;
          I8xLogError(local_b8,0x80050013,0x604,(int)uVar10,(undefined4 *)&local_48,4);
          TraceLoggingSetTypematicFailed(uVar10 & 0xffffffff,uVar16,uVar15,uVar9);
          bVar3 = false;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0;
            uVar15 = 0;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,0x10,0x26,
                             &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          }
          bVar3 = true;
          local_98 = CONCAT44(local_98._4_4_,(int)uVar10);
LAB_1c001ce73:
          uVar13 = local_b8;
        }
        pcVar17 = (code *)CONCAT71((int7)((ulonglong)uVar15 >> 8),1);
        pcVar18 = (code *)CONCAT71((int7)(uVar9 >> 8),0xed);
        uVar9 = I8xPutBytePolled('\0','\x01','\x01',0xed);
        if ((int)uVar9 == 0) {
          pcVar18 = (code *)(ulonglong)*(byte *)((longlong)param_1 + 0x2dc);
          pcVar17 = (code *)CONCAT71((int7)((ulonglong)pcVar17 >> 8),1);
          uVar15 = 1;
          uVar9 = I8xPutBytePolled('\0','\x01','\x01',*(byte *)((longlong)param_1 + 0x2dc));
          if ((int)uVar9 != 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x29,
                               &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
            }
            pcVar18 = (code *)(uVar9 & 0xffffffff);
            uVar15 = 0x80050014;
            pcVar17 = (code *)0x60e;
            local_48 = 1;
            uStack_40._4_4_ = (uint)*(ushort *)((longlong)param_1 + 0x2dc);
            uStack_40 = CONCAT44(uStack_40._4_4_,0xed);
            I8xLogError(uVar13,0x80050014,0x60e,(int)uVar9,(undefined4 *)&local_48,4);
            TraceLoggingSetLedFailed(uVar9 & 0xffffffff,uVar15,pcVar17,pcVar18);
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            pcVar18 = (code *)0x28;
            pcVar17 = (code *)0x10;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                             0x10,0x28,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          }
          bVar2 = true;
          local_90 = CONCAT44(local_90._4_4_,(int)uVar9);
        }
        uVar9 = 0;
        if ((*(char *)(param_1 + 0x56) == '\a') && (*(char *)((longlong)param_1 + 0x2b1) == '\x03'))
        {
          pcVar17 = (code *)CONCAT71((int7)((ulonglong)pcVar17 >> 8),1);
          pcVar18 = (code *)CONCAT71((int7)((ulonglong)pcVar18 >> 8),0xf0);
          uVar10 = I8xPutBytePolled('\0','\x01','\x01',0xf0);
          uVar9 = uVar10 & 0xffffffff;
          if ((int)uVar10 == 0) {
            pcVar17 = (code *)CONCAT71((int7)((ulonglong)pcVar17 >> 8),1);
            pcVar18 = (code *)CONCAT71((int7)((ulonglong)pcVar18 >> 8),0x82);
            uVar10 = I8xPutBytePolled('\0','\x01','\x01',0x82);
            uVar9 = uVar10 & 0xffffffff;
            if ((int)uVar10 == 0) goto LAB_1c001d094;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              pcVar18 = (code *)0x2c;
              pcVar17 = (code *)0x11;
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                               0x11,0x2c,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                pcVar18 = (code *)0x2d;
                goto LAB_1c001cff7;
              }
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            pcVar18 = (code *)0x2a;
            pcVar17 = (code *)0x11;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                             0x11,0x2a,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              pcVar18 = (code *)0x2b;
LAB_1c001cff7:
              pcVar17 = (code *)0x11;
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                               0x11,(short)pcVar18,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids)
              ;
            }
          }
          *(undefined2 *)((longlong)param_1 + 0x2b2) = 3;
        }
LAB_1c001d094:
        if ((code *)param_1[0x73] != (code *)0x0) {
          pcVar18 = I8xKeyboardSynchWritePort;
          pcVar17 = I8xKeyboardSynchReadPort;
          (*(code *)param_1[0x73])(param_1[0x75],local_b8);
        }
        if ((*(short *)((longlong)param_1 + 0x2b2) == 1) && (local_c0 != '\0')) {
          local_a8 = CONCAT26(local_a8._6_2_,0x400000000000);
          local_a8 = CONCAT44(local_a8._4_4_,*Globals);
          I8xTransmitControllerCommand
                    ((uint *)&local_a8,&WPP_RECORDER_INITIALIZED,(ulonglong)pcVar17,pcVar18);
          uVar20 = local_a0;
          if ((int)local_a0 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,
                               0x11,0x2e,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
            }
            if (uVar20 != 0xc000009c) {
              uVar9 = (ulonglong)uVar20;
              bVar6 = 0;
              goto LAB_1c001d24c;
            }
            if ((8 < *(byte *)(param_1 + 0x56)) ||
               ((0x194U >> (*(byte *)(param_1 + 0x56) & 0x1f) & 1) == 0)) goto LAB_1c001d483;
            uVar15 = 1;
            uVar10 = I8xPutBytePolled('\0','\x01','\x01',0xf0);
            uVar9 = uVar10 & 0xffffffff;
            if ((int)uVar10 < 0) {
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x2f,
                                   &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids),
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x30,
                                 &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
              }
              local_48 = 0;
              uVar15 = 0x613;
              uVar20 = 3;
            }
            else {
              if ((*(char *)(param_1 + 0x56) != '\a') ||
                 (bVar6 = 0x81, *(char *)((longlong)param_1 + 0x2b1) != '\x03')) {
                bVar6 = 1;
              }
              uVar15 = 1;
              uVar10 = I8xPutBytePolled('\0','\x01','\x01',bVar6);
              uVar9 = uVar10 & 0xffffffff;
              if (-1 < (int)uVar10) goto LAB_1c001d23b;
              if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
                 (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x31,
                                   &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids),
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x32,
                                 &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
              }
              local_48 = 1;
              uVar15 = 0x618;
              uStack_40._4_4_ = 1;
              uVar20 = 4;
            }
            uVar13 = 0x80050015;
            uStack_40 = CONCAT44(uStack_40._4_4_,0xf0);
            *(undefined2 *)((longlong)param_1 + 0x2b2) = 2;
            uVar10 = uVar9;
            I8xLogError(local_b8,0x80050015,(int)uVar15,(int)uVar9,(undefined4 *)&local_48,uVar20);
            TraceLoggingSelectScansetFailed(uVar9,uVar13,uVar15,uVar10);
          }
LAB_1c001d23b:
          bVar6 = 0;
        }
        else {
LAB_1c001d483:
          bVar6 = 0;
        }
        goto LAB_1c001d24c;
      }
      if (uVar20 != 0xc00000b5) goto LAB_1c001cb88;
      param_3 = &local_80;
      uVar15 = 0;
      KeDelayExecutionThread();
      lVar5 = _DAT_fffff78000000320;
      uVar7 = KeQueryTimeIncrement();
    } while ((longlong)((ulonglong)uVar7 * (lVar5 - lVar4)) < 100000000);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0;
      param_3 = (undefined8 *)0x0;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar15,0x11,0x24,
                       &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
LAB_1c001cb88:
    if (cVar11 != '\x01') break;
    uVar15 = 0;
  } while( true );
  bVar3 = false;
  bVar6 = 1;
  local_c4 = uVar20;
LAB_1c001d24c:
  if (bVar1) {
    if ((!bVar3) || (!bVar2)) {
LAB_1c001cbea:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x11,
                          0x35,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar9);
      }
LAB_1c001cc2d:
      uVar15 = local_b8;
      if (DAT_1c0012247 == '\0') {
      }
      else {
        uVar10 = (ulonglong)local_b0;
        local_48 = 0;
        uVar13 = 0x8005000f;
        uVar16 = 0x5e6;
        uStack_40 = CONCAT44(uStack_40._4_4_,0xff);
        I8xLogError(local_b8,0x8005000f,0x5e6,local_b0,(undefined4 *)&local_48,3);
        TraceLoggingResetCommandFailed((ulonglong)local_b0,uVar13,uVar16,uVar10);
      }
      goto LAB_1c001d5c4;
    }
    if (*(char *)((longlong)param_1 + 0x3ba) == '\x01') {
      local_78 = 0x30;
      local_60 = 0x240;
      local_68 = (undefined8 *)&DAT_1c00121e8;
      local_98 = 0;
      local_90 = 0;
      local_48 = 0;
      uStack_40 = 0;
      local_70 = 0;
      local_58 = 0;
      uStack_50 = 0;
      iVar8 = ZwOpenKey(&local_98,0xf003f);
      if (-1 < iVar8) {
        RtlInitUnicodeString(&local_48,L"Parameters");
        local_70 = local_98;
        local_68 = &local_48;
        local_78 = CONCAT44(local_78._4_4_,0x30);
        local_60 = CONCAT44(local_60._4_4_,0x240);
        local_58 = 0;
        uStack_50 = 0;
        iVar8 = ZwOpenKey(&local_90,0xf003f);
        if (-1 < iVar8) {
          pwVar14 = L"KeyboardFailedReset";
          RtlInitUnicodeString(&local_48);
          local_84 = 0;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar14,0x11,0x33,
                             &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
          }
          ZwSetValueKey(local_90,&local_48,0,4);
          ZwClose(local_90);
        }
        ZwClose(local_98);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x10,
                       0x34,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
    }
    uVar9 = 0xc000009d;
    *Globals = *Globals | 0x4000;
    if (DAT_1c0012247 != '\0') {
      uVar16 = 0xc000009d;
      uVar13 = 0;
      uVar15 = 0x40050020;
      I8xLogError(local_b8,0x40050020,0,0xc000009d,(undefined4 *)0x0,0);
      TraceLoggingDeviceNotConnected(0xc000009d,uVar15,uVar13,uVar16);
    }
  }
  else {
    uVar15 = local_b8;
LAB_1c001d5c4:
    if (bVar6 == 0) {
      if (bVar19) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x11
                           ,0x37,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
        }
        uVar13 = 0x80050011;
        uVar10 = (ulonglong)local_88;
        uVar16 = 0x5eb;
        local_48 = 0x100000004;
        uStack_40._4_4_ = (uint)local_bf;
        uStack_40 = CONCAT44(uStack_40._4_4_,0xaa);
        I8xLogError(uVar15,0x80050011,0x5eb,local_88,(undefined4 *)&local_48,4);
        uVar20 = local_88;
        goto LAB_1c001d650;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x11
                           ,0x36,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar9,
                           local_c7[0]);
      }
      uVar10 = (ulonglong)local_c4;
      uVar13 = 0x80050011;
      uVar16 = 0x5f0;
      local_48 = 0x100000004;
      uStack_40._4_4_ = (uint)bVar6;
      uStack_40 = CONCAT44(uStack_40._4_4_,0xaa);
      I8xLogError(uVar15,0x80050011,0x5f0,local_c4,(undefined4 *)&local_48,4);
      uVar20 = local_c4;
LAB_1c001d650:
      TraceLoggingResetResponseFailed((ulonglong)uVar20,uVar13,uVar16,uVar10);
    }
    if (bVar3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x11,
                         0x38,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      uVar10 = local_98 & 0xffffffff;
      uVar13 = 0x80050013;
      local_48 = 0;
      uVar16 = 0x5ff;
      uStack_40 = CONCAT44(uStack_40._4_4_,0xf3);
      I8xLogError(uVar15,0x80050013,0x5ff,(undefined4)local_98,(undefined4 *)&local_48,3);
      TraceLoggingSetTypematicFailed(local_98 & 0xffffffff,uVar13,uVar16,uVar10);
    }
    if (bVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0x11,
                         0x39,&WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids);
      }
      uVar10 = local_90 & 0xffffffff;
      uVar13 = 0x80050014;
      uVar16 = 0x609;
      local_48 = 0;
      uStack_40 = CONCAT44(uStack_40._4_4_,0xed);
      I8xLogError(uVar15,0x80050014,0x609,(undefined4)local_90,(undefined4 *)&local_48,3);
      TraceLoggingSetLedFailed(local_90 & 0xffffffff,uVar13,uVar16,uVar10);
    }
    if ((((int)uVar9 + 0x80000000U & 0x80000000) == 0) && ((int)uVar9 != -0x3fffff63)) {
      *Globals = *Globals & 0xfffffefe;
      goto LAB_1c001d546;
    }
  }
  *Globals = *Globals | 0x101;
LAB_1c001d546:
  *(undefined8 *)((longlong)param_1 + 0x20c) = 0;
  param_1[0x40] = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&WPP_RECORDER_INITIALIZED,0xf,0x3a,
                      &WPP_4c5c8ccea6b037357f7765b1595ce456_Traceguids,(char)uVar9);
  }
  return uVar9;
}



===== I8xCreate @ 1c001d810 =====

undefined4 I8xCreate(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined *in_stack_ffffffffffffffd8;
  
  uVar7 = 0;
  lVar5 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,10,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(lVar3 + 0x1b8) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,0x11,0xb,
                       &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
    }
    uVar7 = 0xc0000184;
  }
  else if ((*(uint *)(lVar3 + 0x22c) & 8) == 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x60);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if ((iVar2 + 1 < 2) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      pcVar6 = "Keyboard";
      if (*(char *)(lVar3 + 0x235) == '\0') {
        pcVar6 = "Mouse";
      }
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,"Mouse",0xd,
                         in_stack_ffffffffffffffd8,pcVar6,(char)*(undefined4 *)(lVar3 + 0x60));
    }
  }
  else {
    uVar7 = 0xc000000e;
  }
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar7;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,0xf,0xe,
                      &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids,(char)uVar7);
  }
  return uVar7;
}



===== I8xClose @ 1c001d9a0 =====

undefined8 I8xClose(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined *in_stack_ffffffffffffffd8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0xf,
                     &WPP_69ad5fa20b14395ecb5f7e203cce2975_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 == 1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    pcVar4 = "Keyboard";
    if (*(char *)(lVar3 + 0x235) == '\0') {
      pcVar4 = "Mouse";
    }
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,"Mouse",0x10,
                       in_stack_ffffffffffffffd8,pcVar4,(char)*(undefined4 *)(lVar3 + 0x60));
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== I8xReinitializeHardware @ 1c001da80 =====

void I8xReinitializeHardware(ulonglong param_1,int *param_2,undefined8 *param_3,undefined8 *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_res10 [2];
  int local_res18 [2];
  longlong *local_res20;
  
  puVar5 = DAT_1c00121d0;
  plVar4 = DAT_1c00121c8;
  lVar1 = *(longlong *)(param_2 + 4);
  iVar10 = -0x3fffffff;
  iVar9 = -0x3fffffff;
  lVar2 = *(longlong *)(param_2 + 2);
  local_res18[0] = -0x3fffffff;
  local_res10[0] = -0x3fffffff;
  local_res20 = DAT_1c00121c8;
  uVar8 = 0;
  if ((lVar1 != 0) ||
     (((param_1 = (ulonglong)*Globals, (*Globals & 1) != 0 && (DAT_1c00121d0 != (undefined8 *)0x0))
      && (*(int *)(DAT_1c00121d0 + 10) == 1)))) {
    uVar8 = 0x10000;
  }
  if ((lVar2 != 0) ||
     (((param_1 = (ulonglong)*Globals, (*Globals & 2) != 0 && (DAT_1c00121c8 != (longlong *)0x0)) &&
      ((int)DAT_1c00121c8[10] == 1)))) {
    uVar8 = uVar8 | 0x20000;
  }
  piVar7 = param_2;
  if ((DAT_1c00121d8 == 0) &&
     (uVar6 = I8xSanityCheckResources(param_1,param_2), (char)uVar6 == '\0')) {
    if ((uVar8 >> 0x10 & 1) != 0) {
      I8xManuallyRemoveDevice((longlong)puVar5,piVar7);
    }
    if (uVar8 >> 0x11 != 0) {
      I8xManuallyRemoveDevice((longlong)plVar4,piVar7);
    }
  }
  else {
    I8xToggleInterrupts('\0',piVar7,(ulonglong)param_3,param_4);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = (undefined8 *)0x20;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,0x16,0x20,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
    param_3 = (undefined8 *)(ulonglong)uVar8;
    piVar7 = local_res10;
    I8xInitializeHardware(local_res18,piVar7,param_3,param_4);
    iVar9 = local_res10[0];
    iVar10 = local_res18[0];
    if (((local_res18[0] + 0x80000000U & 0x80000000) != 0) || (local_res18[0] == -0x3fffff63))
    goto LAB_1c001dc05;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = (undefined8 *)0x21;
    param_3 = (undefined8 *)0x11;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,0x11,0x21,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)iVar10);
  }
LAB_1c001dc05:
  if ((((iVar9 + 0x80000000U & 0x80000000) == 0) && (iVar9 != -0x3fffff63)) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    param_4 = (undefined8 *)0x22;
    param_3 = (undefined8 *)0x11;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,0x11,0x22,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)iVar9);
  }
  if ((((iVar10 + 0x80000000U & 0x80000000) != 0) || (iVar10 == -0x3fffff63)) ||
     (((iVar9 + 0x80000000U & 0x80000000) != 0 || (iVar9 == -0x3fffff63)))) {
    I8xToggleInterrupts('\x01',piVar7,(ulonglong)param_3,param_4);
  }
  if (((-1 < iVar9) || (iVar9 == -0x3fffff63)) || (iVar9 == -0x3fffff4b)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = (undefined8 *)0x23;
      param_3 = (undefined8 *)0xe;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,0xe,0x23,
                        &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)iVar9);
    }
    if (lVar2 != 0) {
      lVar3 = *(longlong *)(lVar2 + 0xb8);
      *(undefined4 *)(local_res20 + 10) = *(undefined4 *)(lVar3 + 0x18);
      *(undefined4 *)(local_res20 + 0xb) = 0;
      param_3 = (undefined8 *)(ulonglong)*(uint *)(lVar3 + 0x18);
      piVar7 = (int *)(ulonglong)*(uint *)(lVar3 + 0x10);
      PoSetPowerState();
    }
    if (*(short *)((longlong)local_res20 + 0x21a) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = (undefined8 *)0x24;
        param_3 = (undefined8 *)0xe;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar7,0xe,0x24,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
      piVar7 = (int *)0x0;
      I8xMouseConnectInterruptAndEnable(local_res20,0);
    }
    if ((iVar9 != -0x3fffff4b) && (iVar9 != -0x3fffff63)) {
      if (*(char *)((longlong)local_res20 + 0x454) == '\0') {
        *(undefined2 *)((longlong)local_res20 + 0x3f4) = 0xffff;
        *(undefined2 *)(local_res20 + 0x46) = 0;
        I8xResetMouse(local_res20,piVar7);
      }
      else {
        I8xMouseEnableTransmission(local_res20,piVar7,param_3,param_4);
      }
    }
    iVar9 = 0;
  }
  if (lVar2 != 0) {
    *(int *)(lVar2 + 0x30) = iVar9;
    *(undefined8 *)(lVar2 + 0x38) = 0;
    PoStartNextPowerIrp(lVar2);
    IofCompleteRequest(lVar2,0);
    IoReleaseRemoveLockEx(local_res20 + 5,lVar2,0x20);
  }
  if ((((iVar10 + 0x80000000U & 0x80000000) != 0) || (iVar10 == -0x3fffff63)) &&
     (iVar10 = 0, lVar1 != 0)) {
    lVar2 = *(longlong *)(lVar1 + 0xb8);
    *(undefined4 *)(puVar5 + 10) = *(undefined4 *)(lVar2 + 0x18);
    *(undefined4 *)(puVar5 + 0xb) = 0;
    PoSetPowerState(*puVar5,*(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18));
  }
  if (lVar1 != 0) {
    *(int *)(lVar1 + 0x30) = iVar10;
    *(undefined8 *)(lVar1 + 0x38) = 0;
    PoStartNextPowerIrp(lVar1);
    IofCompleteRequest(lVar1,0);
    IoReleaseRemoveLockEx(puVar5 + 5,lVar1,0x20);
  }
  I8xSetPowerFlag(0x10000000,'\0');
  IoFreeWorkItem(*(undefined8 *)param_2);
  ExFreePoolWithTag(param_2,0);
  return;
}



===== I8xInitializeHardware @ 1c001dea0 =====

void I8xInitializeHardware(int *param_1,int *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  bool bVar2;
  bool bVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined2 uVar11;
  byte bVar12;
  bool bVar13;
  bool bVar14;
  
  puVar5 = DAT_1c00121d0;
  puVar4 = DAT_1c00121c8;
  puVar10 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0x26;
    puVar10 = (undefined8 *)0xf;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x26,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  uVar1 = *(undefined8 *)(Globals + 0x34);
  uVar9 = *(undefined8 *)(Globals + 0x36);
  uVar8 = uVar9;
  I8xDrainOutputBuffer(uVar1,uVar9);
  if (((*Globals & 2) == 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
     ) {
    param_4 = 0x27;
    puVar10 = (undefined8 *)0x10;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x27,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  if (((*Globals & 1) == 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
     ) {
    param_4 = 0x28;
    puVar10 = (undefined8 *)0x10;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x28,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  bVar14 = ((ulonglong)param_3 & 1) == 0;
  if (bVar14) {
    bVar12 = (byte)((ulonglong)param_3 >> 0x10) & 1;
  }
  else {
    bVar12 = 1;
  }
  bVar13 = ((uint)param_3 >> 0x11 & 1) != 0;
  bVar3 = !bVar14 || bVar13;
  bVar2 = !bVar14;
  if (((((*Globals & 1) != 0) && (!bVar2)) && (bVar12 != 0)) && (*(int *)(puVar5 + 0xb) == 2)) {
    param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xad);
    puVar10 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar10 >> 8),3);
    I8xPutBytePolled('\x01','\0','\x03',0xad);
  }
  if ((((*Globals & 2) != 0) && (!bVar2)) && ((bVar3 && (*(int *)(puVar4 + 0xb) == 2)))) {
    param_4 = CONCAT71((int7)((ulonglong)param_4 >> 8),0xa7);
    puVar10 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar10 >> 8),3);
    I8xPutBytePolled('\x01','\0','\x03',0xa7);
  }
  uVar8 = uVar9;
  I8xDrainOutputBuffer(uVar1,uVar9);
  if (((*Globals & 1) == 0) || (bVar12 == 0)) {
    *param_1 = -0x3ffffff2;
  }
  else {
    uVar7 = I8xInitializeKeyboard(puVar5,uVar8,puVar10,param_4);
    iVar6 = (int)uVar7;
    *param_1 = iVar6;
    if (iVar6 < 0) {
      if (iVar6 == -0x3fffff63) {
        if (DAT_1c0012246 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_4 = 0x2b;
            puVar10 = (undefined8 *)0x10;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x2b,
                             &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
          }
          I8xManuallyRemoveDevice((longlong)puVar5,uVar8);
        }
        else if (bVar2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_4 = 0x2c;
            puVar10 = (undefined8 *)0x10;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x2c,
                             &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
          }
          *(uint *)((longlong)puVar5 + 0x22c) = *(uint *)((longlong)puVar5 + 0x22c) | 2;
          IoInvalidateDeviceState(puVar5[4]);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = 0x2d;
          puVar10 = (undefined8 *)0x11;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x11,0x2d,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)uVar7);
        }
        I8xManuallyRemoveDevice((longlong)puVar5,uVar8);
      }
    }
  }
  if (((*Globals & 2) == 0) || (bVar14 && !bVar13)) {
    *param_2 = -0x3ffffff2;
  }
  else {
    uVar7 = I8xInitializeMouse(puVar4,uVar8,puVar10,param_4);
    iVar6 = (int)uVar7;
    *param_2 = iVar6;
    if ((iVar6 < 0) && (bVar2)) {
      if (iVar6 == -0x3fffff63) {
        if (DAT_1c0012246 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x2e,
                             &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
          }
          I8xManuallyRemoveDevice((longlong)puVar4,uVar8);
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x2f,
                             &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
          }
          *(uint *)((longlong)puVar4 + 0x22c) = *(uint *)((longlong)puVar4 + 0x22c) | 2;
          IoInvalidateDeviceState(puVar4[4]);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x11,0x30,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)uVar7);
        }
        I8xManuallyRemoveDevice((longlong)puVar4,uVar8);
      }
    }
  }
  if ((((*Globals & 1) != 0) && (-1 < *param_1)) && (bVar12 != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,0x31,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    }
    uVar8 = 1;
    uVar7 = I8xPutBytePolled('\0','\x01','\x01',0xed);
    iVar6 = (int)uVar7;
    if (iVar6 == 0) {
      uVar8 = 1;
      uVar7 = I8xPutBytePolled('\0','\x01','\x01',*(byte *)((longlong)puVar5 + 0x2dc));
      iVar6 = (int)uVar7;
      if ((iVar6 == 0) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      goto LAB_1c001e364;
      uVar11 = 0x32;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001e364;
      uVar11 = 0x33;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x10,uVar11,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)iVar6);
  }
LAB_1c001e364:
  if (((*Globals & 1) != 0) && (bVar12 != 0)) {
    uVar8 = 0;
    uVar7 = I8xPutBytePolled('\x01','\0','\x03',0xae);
    if (((int)uVar7 < 0) && (bVar2)) {
      *param_1 = (int)uVar7;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x11,0x34,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)uVar7);
      }
      I8xManuallyRemoveDevice((longlong)puVar5,uVar8);
    }
    uVar8 = uVar9;
    I8xDrainOutputBuffer(uVar1,uVar9);
  }
  if (((*Globals & 2) != 0) && (bVar3)) {
    uVar8 = 0;
    uVar7 = I8xPutBytePolled('\x01','\0','\x03',0xa8);
    if (((int)uVar7 < 0) && (bVar2)) {
      *param_2 = (int)uVar7;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x11,0x35,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)uVar7);
      }
      I8xManuallyRemoveDevice((longlong)puVar4,uVar8);
    }
    I8xDrainOutputBuffer(uVar1,uVar9);
    uVar8 = uVar9;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0xf,0x36,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)*param_1,
                       (char)*param_2);
  }
  return;
}



===== I8xToggleInterrupts @ 1c001e4e0 =====

int I8xToggleInterrupts(char param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined8 local_18;
  int local_10;
  
  local_18 = 0;
  local_10 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = 0x1e;
    pcVar3 = "TRUE";
    if (param_1 == '\0') {
      pcVar3 = "FALSE";
    }
    param_3 = 0xf;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0xf,0x1e,
                      &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar3);
  }
  uVar1 = *Globals;
  if (param_1 == '\0') {
    local_18._0_6_ = CONCAT24(0xfc01,uVar1);
  }
  else {
    local_18._0_5_ = (uint5)uVar1;
    local_18 = CONCAT26(local_18._6_2_,CONCAT15((char)uVar1,(uint5)local_18)) & 0xffff03ffffffffff;
  }
  I8xTransmitControllerCommand((uint *)&local_18,param_2,param_3,param_4);
  iVar2 = local_10;
  if ((local_10 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    pcVar3 = "en";
    if (param_1 == '\0') {
      pcVar3 = "dis";
    }
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,0x11,0x1f,
                       &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar3,(char)local_10);
  }
  return iVar2;
}



===== I8xPower @ 1c001e600 =====

undefined8 I8xPower(longlong param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  byte bVar6;
  bool bVar7;
  undefined8 uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  pcVar11 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar11 = "mouse";
    pcVar9 = "keyboard";
    if (*(char *)(lVar2 + 0x235) == '\0') {
      pcVar9 = "mouse";
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"mouse",0x17,0x25,
                      &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar9);
  }
  if ((*(char *)(lVar2 + 0x236) == '\0') || (*(char *)(lVar2 + 0x233) == '\0')) {
    PoStartNextPowerIrp(param_2);
    param_2[0x30] = '\0';
    param_2[0x31] = '\0';
    param_2[0x32] = '\0';
    param_2[0x33] = '\0';
    goto LAB_1c001eaf3;
  }
  bVar6 = *(byte *)(lVar3 + 1);
  uVar10 = (uint)bVar6;
  if (uVar10 == 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x16,0x29,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    }
    iVar1 = *(int *)(lVar3 + 0x18);
    if (*(int *)(lVar3 + 0x10) == 1) {
      if (iVar1 != *(int *)(lVar2 + 0x50)) {
        if (iVar1 != 4) {
          if (iVar1 == 1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x18,0x2c,
                               &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
            }
            IoAcquireRemoveLockEx(lVar2 + 0x28,param_2,"",1,0x20);
            uVar10 = 1;
            if (*(char *)(lVar2 + 0x235) == '\0') {
              uVar10 = 0x10;
            }
            I8xSetPowerFlag(uVar10,'\x01');
            puVar4 = *(undefined8 **)(param_2 + 0xb8);
            puVar4[-9] = *puVar4;
            puVar4[-8] = puVar4[1];
            puVar4[-7] = puVar4[2];
            puVar4[-6] = puVar4[3];
            *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
            *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
            *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
            *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
            puVar4[-3] = puVar4[6];
            *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
            lVar3 = *(longlong *)(param_2 + 0xb8);
            *(code **)(lVar3 + -0x10) = I8xPowerUpToD0Complete;
            *(undefined8 *)(lVar3 + -8) = 0;
            *(undefined1 *)(lVar3 + -0x45) = 0xe0;
            *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
                 *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
            PoCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
            return 0x103;
          }
          uVar10 = iVar1 - 2;
          pcVar11 = (char *)(ulonglong)uVar10;
          if ((uVar10 != 0) && (uVar10 != 1)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x30;
              uVar10 = 0x18;
              goto LAB_1c001e872;
            }
            goto LAB_1c001e8af;
          }
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x18,0x2d,
                            &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,(char)iVar1 + -1);
        }
        bVar7 = I8xCheckPowerFlag();
        if (bVar7) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x19,0x2e,
                             &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
          }
          PoStartNextPowerIrp(param_2);
          param_2[0x30] = -0x2d;
          param_2[0x31] = '\x02';
          param_2[0x32] = '\0';
          param_2[0x33] = -0x40;
          IofCompleteRequest(param_2,0);
          return 0xc00002d3;
        }
        uVar10 = 2;
        if (*(char *)(lVar2 + 0x235) == '\0') {
          uVar10 = 0x20;
        }
        I8xSetPowerFlag(uVar10,'\x01');
        uVar12 = (ulonglong)*(uint *)(lVar3 + 0x10);
        PoSetPowerState(param_1,uVar12,*(undefined4 *)(lVar3 + 0x18));
        if ((*(char *)(lVar2 + 0x235) == '\0') && (*(short *)(lVar2 + 0x21a) == 0)) {
          lVar5 = *(longlong *)(lVar2 + 8);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar12,0x16,0x2f,
                             &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
          }
          *(undefined8 *)(lVar2 + 8) = 0;
          if (lVar5 != 0) {
            IoDisconnectInterrupt(lVar5);
          }
        }
        *(undefined4 *)(lVar2 + 0x50) = *(undefined4 *)(lVar3 + 0x18);
        *(undefined4 *)(lVar2 + 0x58) = *(undefined4 *)(lVar3 + 0x20);
        param_2[0x30] = '\0';
        param_2[0x31] = '\0';
        param_2[0x32] = '\0';
        param_2[0x33] = '\0';
        PoStartNextPowerIrp(param_2);
        goto LAB_1c001eaf3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x2b;
        bVar6 = (char)*(int *)(lVar2 + 0x50) - 1;
        uVar10 = 0x18;
        goto LAB_1c001e6cf;
      }
    }
    else {
      *(int *)(lVar2 + 0x54) = iVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x2a;
        bVar6 = (char)iVar1 - 1;
        uVar10 = 0x18;
LAB_1c001e6cf:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,uVar10,uVar13,
                          &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,bVar6);
        goto LAB_1c001e887;
      }
    }
  }
  else {
    pcVar11 = (char *)(ulonglong)uVar10;
    if (bVar6 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,0x16,0x26,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      if ((*(char *)(lVar2 + 0x235) == '\0') && (*(short *)(lVar2 + 0x21a) == 0)) {
        PoStartNextPowerIrp(param_2);
        uVar8 = 0;
        param_2[0x30] = -0x7c;
        param_2[0x31] = '\x01';
        param_2[0x32] = '\0';
        param_2[0x33] = -0x40;
        IofCompleteRequest(param_2);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,0x19,0x27,
                           &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
        }
        return 0xc0000184;
      }
LAB_1c001e887:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,0x17,0x33,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
    }
    else {
      uVar10 = uVar10 - 1;
      pcVar11 = (char *)(ulonglong)uVar10;
      if (uVar10 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x28;
          uVar10 = 0x16;
LAB_1c001e872:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar11,uVar10,uVar13,
                           &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
          goto LAB_1c001e887;
        }
      }
      else if (uVar10 == 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x31;
          uVar10 = 0x16;
          goto LAB_1c001e872;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x32;
        uVar10 = 0x16;
        goto LAB_1c001e6cf;
      }
    }
  }
LAB_1c001e8af:
  PoStartNextPowerIrp(param_2);
LAB_1c001eaf3:
  param_2[0x43] = param_2[0x43] + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar8 = PoCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
  return uVar8;
}



===== _tlgEnableCallback @ 1c001eb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = 0x100;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
      else {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = param_3 + 1;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== I8xPnP @ 1c001ebd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong I8xPnP(longlong param_1,longlong *param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  bool bVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  char *pcVar11;
  longlong *plVar12;
  undefined2 uVar13;
  undefined8 uVar14;
  char *pcVar15;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar16;
  longlong local_48;
  longlong *plStack_40;
  longlong *local_38;
  undefined8 uStack_30;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  lVar8 = param_2[0x17];
  uVar14 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff98 >> 0x20),0x20);
  uVar6 = IoAcquireRemoveLockEx(puVar2 + 5,param_2,"",1,uVar14);
  uVar16 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uVar9 = (ulonglong)uVar6;
  if ((int)uVar6 < 0) {
    *(uint *)(param_2 + 6) = uVar6;
    param_2[7] = 0;
    IofCompleteRequest(param_2,0);
    return uVar9;
  }
  pcVar15 = "kb";
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar11 = "kb";
    bVar1 = *(byte *)(lVar8 + 1);
    if (*(char *)((longlong)puVar2 + 0x235) == '\0') {
      pcVar11 = "mou";
    }
    uVar16 = 1;
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar1,0xf,0xd,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar11,bVar1);
  }
  bVar1 = *(byte *)(lVar8 + 1);
  plVar12 = (longlong *)(ulonglong)bVar1;
  if (bVar1 == 9) {
    if (((*(char *)((longlong)puVar2 + 0x236) == '\0') ||
        (*(char *)((longlong)puVar2 + 0x235) != '\0')) ||
       (*(short *)((longlong)puVar2 + 0x21a) != 0)) goto switchD_1c001ecfa_caseD_4;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),9,0xe,0x13,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
    }
    plVar12 = param_2;
    uVar10 = I8xSendIrpSynchronously(puVar2[3],(longlong)param_2,'\x01');
    uVar9 = uVar10 & 0xffffffff;
    if ((-1 < (int)uVar10) && (-1 < (int)param_2[6])) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar12,0x10,0x14,
                         &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
      }
      lVar8 = *(longlong *)(param_2[0x17] + 8);
      if (lVar8 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar12,0xe,0x15,
                             &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,
                             (char)*(undefined4 *)(lVar8 + 0x30) + -1,
                             (char)*(undefined4 *)(lVar8 + 0x2c) + -1);
        }
        *(undefined8 *)(lVar8 + 0x2c) = 0;
      }
    }
LAB_1c001eff8:
    plVar12 = (longlong *)0x0;
    IofCompleteRequest(param_2);
    goto LAB_1c001f286;
  }
  plVar7 = param_2;
  switch(plVar12) {
  case (longlong *)0x0:
    if (DAT_1c0012240 == 1) {
      plVar12 = (longlong *)0x20;
      plVar7 = (longlong *)ExAllocatePool2(0x40,0x20,0x32343038);
      if (plVar7 == (longlong *)0x0) {
        bVar4 = true;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0xf;
LAB_1c001ee7f:
          bVar4 = true;
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar12,0x11,uVar13,
                           &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids);
        }
      }
      else {
        lVar8 = IoAllocateWorkItem(param_1);
        *plVar7 = lVar8;
        if (lVar8 == 0) {
          plVar12 = (longlong *)0x0;
          ExFreePoolWithTag(plVar7);
          bVar4 = true;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0xe;
            goto LAB_1c001ee7f;
          }
        }
        else {
          IoAcquireRemoveLockEx(puVar2 + 5,param_2,"",1,CONCAT44(uVar16,0x20));
          puVar3 = (undefined8 *)param_2[0x17];
          uVar9 = 0x103;
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
          lVar8 = param_2[0x17];
          *(code **)(lVar8 + -0x10) = I8xPnPStartComplete;
          *(longlong **)(lVar8 + -8) = plVar7;
          *(undefined1 *)(lVar8 + -0x45) = 0xe0;
          *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
          plVar12 = param_2;
          IofCallDriver(puVar2[3]);
          bVar4 = false;
        }
      }
    }
    else {
      bVar4 = false;
    }
    if ((DAT_1c0012240 != 0) && (!bVar4)) goto LAB_1c001f286;
    plVar12 = param_2;
    uVar10 = I8xSendIrpSynchronously(puVar2[3],(longlong)param_2,'\x01');
    uVar9 = uVar10 & 0xffffffff;
    if (((int)uVar10 < 0) || ((int)param_2[6] < 0)) {
      *(int *)(param_2 + 6) = (int)uVar10;
      goto LAB_1c001f286;
    }
    local_48 = 0;
    plStack_40 = (longlong *)0x0;
    local_38 = (longlong *)0x0;
    if (*(char *)((longlong)puVar2 + 0x235) == '\0') {
      plStack_40 = param_2;
    }
    else {
      local_38 = param_2;
    }
    uVar14 = 1;
    uStack_30 = 1;
    pcVar11 = "";
    IoAcquireRemoveLockEx(puVar2 + 5,param_2,"",1,0x20);
    plVar12 = &local_48;
    uVar6 = I8xStartDevice(param_1,plVar12,(ulonglong)pcVar11,uVar14);
    goto LAB_1c001f276;
  case (longlong *)0x1:
  case (longlong *)0x5:
    if ((*(uint *)((longlong)puVar2 + 0x22c) & 8) == 0) {
      uVar9 = 0xc0000001;
      *(undefined4 *)(param_2 + 6) = 0xc0000001;
      goto LAB_1c001eff2;
    }
    param_2[0x17] = param_2[0x17] + 0x48;
    break;
  case (longlong *)0x2:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (*(char *)((longlong)puVar2 + 0x233) != '\0') {
      IoWMIRegistrationControl(*puVar2,2);
    }
    if (*(char *)((longlong)puVar2 + 0x236) != '\0') {
      LOCK();
      _DAT_1c0012200 = _DAT_1c0012200 + -1;
      UNLOCK();
    }
    plVar12 = param_2;
    IoReleaseRemoveLockAndWaitEx(puVar2 + 5,param_2,0x20);
    ExAcquireFastMutexUnsafe(&DAT_1c0012208);
    if (*(char *)((longlong)puVar2 + 0x235) == '\0') {
      I8xMouseRemoveDevice(param_1,plVar12);
    }
    else {
      I8xKeyboardRemoveDevice(param_1,plVar12);
    }
    ExReleaseFastMutexUnsafe(&DAT_1c0012208);
    *(undefined1 *)((longlong)puVar2 + 0x236) = 0;
    *(undefined1 *)((longlong)puVar2 + 0x233) = 0;
    *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
    param_2[0x17] = param_2[0x17] + 0x48;
    *(undefined4 *)(param_2 + 6) = 0;
    uVar6 = IofCallDriver(puVar2[3],param_2);
    IoDetachDevice(puVar2[3]);
    IoDeleteDevice(param_1);
    return (ulonglong)uVar6;
  case (longlong *)0x3:
  case (longlong *)0x6:
    uVar10 = I8xSendIrpSynchronously(puVar2[3],(longlong)param_2,'\0');
    uVar9 = uVar10 & 0xffffffff;
    *(int *)(param_2 + 6) = (int)uVar10;
LAB_1c001eff2:
    param_2[7] = 0;
    goto LAB_1c001eff8;
  default:
switchD_1c001ecfa_caseD_4:
    param_2[0x17] = param_2[0x17] + 0x48;
    break;
  case (longlong *)0xd:
    uVar10 = I8xSendIrpSynchronously(puVar2[3],(longlong)param_2,'\0');
    uVar9 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x10;
        uVar5 = (undefined1)uVar10;
LAB_1c001ef69:
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar7,0x11,uVar13,
                          &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,uVar5);
      }
    }
    else {
      uVar9 = I8xFilterResourceRequirements(param_1,(char *)param_2);
      uVar9 = uVar9 & 0xffffffff;
    }
    goto LAB_1c001ef85;
  case (longlong *)0x14:
    uVar10 = I8xSendIrpSynchronously(puVar2[3],(longlong)param_2,'\0');
    uVar9 = uVar10 & 0xffffffff;
    if ((int)uVar10 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x11;
        uVar5 = (undefined1)uVar10;
        goto LAB_1c001ef69;
      }
    }
    else {
      param_2[7] = param_2[7] | (ulonglong)*(uint *)((longlong)puVar2 + 0x22c);
    }
LAB_1c001ef85:
    plVar12 = (longlong *)0x0;
    *(int *)(param_2 + 6) = (int)uVar9;
    IofCompleteRequest(param_2);
    goto LAB_1c001f286;
  }
  *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
  plVar12 = param_2;
  uVar6 = IofCallDriver(puVar2[3]);
LAB_1c001f276:
  uVar9 = (ulonglong)uVar6;
LAB_1c001f286:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(char *)((longlong)puVar2 + 0x235) == '\0') {
      pcVar15 = "mou";
    }
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar12,0xf,0x16,
                       &WPP_2842e8c1d8f03f4a13b4c4f7b213f744_Traceguids,pcVar15,(char)uVar9);
  }
  IoReleaseRemoveLockEx(puVar2 + 5,param_2,0x20);
  return uVar9;
}



===== I8xSystemControl @ 1c001f310 =====

ulonglong I8xSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  uVar2 = WmiSystemControl(lVar1 + 0x1c0,param_1,param_2,local_res8);
  if (local_res8[0] != 0) {
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
    }
  }
  return uVar2;
}



===== I8xDeviceControl @ 1c001f3b0 =====

int I8xDeviceControl(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (((*(char *)((longlong)puVar1 + 0x235) != '\0') &&
      (*(char *)((longlong)puVar1 + 0x236) != '\0')) &&
     ((*(uint *)((longlong)puVar1 + 0x22c) & 8) == 0)) {
    iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (iVar2 == 0x294140) {
      iVar2 = I8xKeyboardGetSysButtonCaps((longlong)puVar1,param_2);
      return iVar2;
    }
    if (iVar2 == 0x294144) {
      iVar2 = I8xKeyboardGetSysButtonEvent(puVar1,param_2);
      return iVar2;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  IofCompleteRequest(param_2,0);
  return -0x3ffffff0;
}



===== entry @ 1c0020010 =====

void entry(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
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

undefined8 DriverEntry(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  _DAT_1c0012188 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0012168 = &WPP_ThisDir_CTLGUID_I8042prtTraceGuid;
  DAT_1c0012170 = 0;
  _DAT_1c0012180 = 0;
  _DAT_1c00121a0 = 0;
  _DAT_1c00121a8 = 0;
  WppLoadTracingSupport();
  _DAT_1c0012180 = 0;
  WppInitKm(param_1,param_2);
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  wil_InitializeFeatureStaging();
  memset(&Globals,0,0x88);
  uVar2 = 0xf8;
  uVar3 = 0x32343038;
  Globals = ExAllocatePool2(0x40);
  if (Globals != 0) {
    uVar1 = IoCreateController(0);
    uVar2 = Globals;
    *(undefined8 *)(Globals + 8) = uVar1;
    if (*(longlong *)(Globals + 8) != 0) {
      _DAT_1c00121ea = *param_2 + 2;
      uVar3 = 0x32343038;
      uVar2 = (ulonglong)_DAT_1c00121ea;
      _DAT_1c00121e8 = *param_2;
      DAT_1c00121f0 = (void *)ExAllocatePool2(0x40);
      if (DAT_1c00121f0 != (void *)0x0) {
        memcpy(DAT_1c00121f0,*(void **)(param_2 + 4),(ulonglong)*param_2);
        I8xServiceParameters(param_1);
        uVar1 = 0;
        _DAT_1c0012208 = 1;
        _DAT_1c0012210 = 0;
        _DAT_1c0012218 = 0;
        uVar3 = 1;
        KeInitializeEvent(&DAT_1c0012220);
        KeInitializeSpinLock(Globals + 0xb8);
        KeInitializeSpinLock(Globals + 0xc0);
        KeInitializeTimer(Globals + 0x78);
        *(undefined4 *)(Globals + 0xcc) = 0xffffffff;
        *(code **)(param_1 + 0x60) = I8xStartIo;
        *(code **)(param_1 + 0x68) = I8xUnload;
        *(code **)(*(longlong *)(param_1 + 0x30) + 8) = I8xAddDevice;
        *(code **)(param_1 + 0x70) = I8xCreate;
        *(code **)(param_1 + 0x80) = I8xClose;
        *(code **)(param_1 + 0xe8) = I8xInternalDeviceControl;
        *(code **)(param_1 + 0xe0) = I8xDeviceControl;
        *(code **)(param_1 + 0xb8) = I8xFlush;
        *(code **)(param_1 + 0x148) = I8xPnP;
        *(code **)(param_1 + 0x120) = I8xPower;
        *(code **)(param_1 + 0x128) = I8xSystemControl;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = 0xb;
          uVar1 = 0xf;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,0xf,0xb,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,0);
        }
        TraceLoggingDriverLoaded(0,uVar3,uVar1,param_4);
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = 10;
        uVar3 = 0x11;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0x11,10,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
    }
  }
  if (Globals != 0) {
    if (*(longlong *)(Globals + 8) != 0) {
      IoDeleteController();
    }
    uVar2 = 0;
    ExFreePoolWithTag(Globals);
  }
  if (DAT_1c00121f0 != (void *)0x0) {
    uVar2 = 0;
    ExFreePoolWithTag();
  }
  TraceLoggingDriverLoaded(0xc000009a,uVar2,uVar3,param_4);
  wil_UninitializeFeatureStaging();
  uVar3 = DAT_1c0012030;
  DAT_1c0012030 = 0;
  DAT_1c0012010 = 0;
  EtwUnregister(uVar3);
  WppCleanupKm(param_1);
  return 0xc000009a;
}



===== I8xServiceParameters @ 1c00203e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void I8xServiceParameters(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  char *pcVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  undefined2 uVar9;
  undefined2 local_res10 [4];
  undefined2 local_res18 [4];
  undefined2 local_res20 [4];
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c [5];
  longlong local_58 [4];
  
  lVar1 = Globals;
  local_58[0] = 0;
  local_res18[0] = 12000;
  local_res20[0] = 12000;
  local_6c[2] = 0;
  local_6c[1] = 1;
  local_res10[0] = 3;
  local_88 = 1;
  local_74 = 1;
  lVar6 = 0;
  local_6c[3] = 0;
  local_80 = 0;
  local_7c = 0;
  local_84 = 0;
  local_70 = 0;
  local_6c[0] = 0;
  local_78 = 0;
  *(undefined2 *)(Globals + 0x4e) = 0x32;
  *(undefined1 *)(lVar1 + 0x51) = 0;
  iVar2 = IoOpenDriverRegistryKey(param_1,0,1,0,local_58);
  if (iVar2 < 0) {
    lVar3 = 0;
  }
  else {
    lVar7 = 0x1f8;
    lVar3 = ExAllocatePool2(0x100,0x1f8,0x32343038);
    lVar6 = local_58[0];
    if (lVar3 == 0) {
      lVar6 = lVar7;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,0x11,0x4a,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
        lVar6 = lVar7;
      }
      iVar2 = -0x3fffffff;
    }
    else {
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(undefined4 *)(lVar3 + 0x30) = 2;
      *(wchar_t **)(lVar3 + 0x10) = L"ResendIterations";
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      *(undefined4 **)(lVar3 + 0x18) = &local_84;
      *(undefined2 **)(lVar3 + 0x28) = local_res10;
      *(wchar_t **)(lVar3 + 0x48) = L"PollingIterations";
      *(undefined4 **)(lVar3 + 0x50) = &local_80;
      *(undefined2 **)(lVar3 + 0x60) = local_res18;
      *(undefined4 *)(lVar3 + 0x68) = 2;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(wchar_t **)(lVar3 + 0x80) = L"PollingTerationsMaximum";
      *(undefined4 **)(lVar3 + 0x88) = &local_7c;
      *(undefined2 **)(lVar3 + 0x98) = local_res20;
      *(undefined4 *)(lVar3 + 0xa0) = 2;
      *(undefined4 *)(lVar3 + 0x90) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x78) = 0x120;
      *(wchar_t **)(lVar3 + 0xb8) = L"BreakOnSysRq";
      *(int **)(lVar3 + 0xc0) = &local_74;
      *(int **)(lVar3 + 0xd0) = local_6c + 1;
      *(undefined4 *)(lVar3 + 200) = 0x4000004;
      *(undefined4 *)(lVar3 + 0xd8) = 4;
      *(undefined4 *)(lVar3 + 0xb0) = 0x120;
      *(wchar_t **)(lVar3 + 0xf0) = L"Headless";
      *(int **)(lVar3 + 0xf8) = &local_70;
      *(int **)(lVar3 + 0x108) = local_6c + 2;
      *(undefined4 *)(lVar3 + 0x100) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x110) = 4;
      *(undefined4 *)(lVar3 + 0xe8) = 0x120;
      *(wchar_t **)(lVar3 + 0x128) = L"ReportResetErrors";
      *(int **)(lVar3 + 0x130) = local_6c;
      *(int **)(lVar3 + 0x140) = local_6c + 3;
      *(undefined4 *)(lVar3 + 0x138) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x148) = 4;
      *(undefined4 *)(lVar3 + 0x120) = 0x120;
      *(wchar_t **)(lVar3 + 0x160) = L"AsyncStart";
      *(int **)(lVar3 + 0x168) = &local_78;
      *(undefined4 *)(lVar3 + 0x170) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x180) = 4;
      *(int **)(lVar3 + 0x178) = &local_88;
      *(undefined4 *)(lVar3 + 0x158) = 0x120;
      local_58[1] = 0;
      local_58[2] = 0;
      RtlInitUnicodeString(local_58 + 1,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      iVar2 = (*pcVar4)(0xc0000000,lVar6,lVar3,0,0);
      if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0x10,0x4b,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)iVar2);
      }
    }
  }
  if (iVar2 < 0) {
    *(undefined2 *)(lVar1 + 0x46) = local_res10[0];
    *(undefined2 *)(lVar1 + 0x48) = local_res18[0];
    *(undefined2 *)(lVar1 + 0x4a) = local_res20[0];
    DAT_1c0012240 = local_88;
  }
  else {
    *(undefined2 *)(lVar1 + 0x46) = (undefined2)local_84;
    *(undefined2 *)(lVar1 + 0x48) = (undefined2)local_80;
    *(undefined2 *)(lVar1 + 0x4a) = (undefined2)local_7c;
    DAT_1c0012240 = local_78;
    if (1 < local_78) {
      DAT_1c0012240 = local_88;
    }
    if (local_74 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4d;
        goto LAB_1c0020769;
      }
    }
    else {
      DAT_1c0012245 = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4c;
LAB_1c0020769:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0xe,uVar9,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
    }
    if (local_70 == 0) {
      DAT_1c0012246 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4f;
        goto LAB_1c00207b5;
      }
    }
    else {
      DAT_1c0012246 = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x4e;
LAB_1c00207b5:
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0xe,uVar9,
                         &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
      }
    }
    if (local_6c[0] == 0) {
      DAT_1c0012247 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c002098b;
      uVar9 = 0x51;
    }
    else {
      DAT_1c0012247 = 1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c002098b;
      uVar9 = 0x50;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0xe,uVar9,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0xe,0x52,
                     &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,0xe,0x53,
                        &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,(char)DAT_1c0012240);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar8 = "not";
        pcVar5 = "";
        if (*(char *)(lVar1 + 0x51) == '\0') {
          pcVar5 = "not";
        }
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),"not",0xe,0x54,
                          &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,pcVar5);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,0xe,0x55,
                            &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                            (char)*(undefined2 *)(lVar1 + 0x4e));
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,0xe,0x56,
                              &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                              (char)*(undefined2 *)(lVar1 + 0x46));
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,0xe,0x57,
                                &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                                (char)*(undefined2 *)(lVar1 + 0x48));
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,0xe,0x58,
                                  &WPP_302e7ed89cfa3d9fb97f1e0f79e25f62_Traceguids,
                                  (char)*(undefined2 *)(lVar1 + 0x4a));
              }
            }
          }
        }
      }
    }
  }
LAB_1c002098b:
  if (local_58[0] != 0) {
    ZwClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return;
}



===== wil_InitializeFeatureStaging @ 1c00209d8 =====

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
    plVar3 = (longlong *)&wil_details_featureDescriptors_z;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c0020ac8 =====

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
  plVar3 = (longlong *)&wil_details_featureDescriptors_z;
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


