
===== _tlgWriteEx_EtwWriteEx @ 1c0001008 =====

void _tlgWriteEx_EtwWriteEx(undefined8 param_1,byte *param_2)

{
  undefined8 *in_stack_00000040;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *in_stack_00000040 = PTR_DAT_1c0009008;
  *(uint *)(in_stack_00000040 + 1) = (uint)*(ushort *)PTR_DAT_1c0009008;
  in_stack_00000040[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)in_stack_00000040 + 0xc) = 2;
  *(uint *)(in_stack_00000040 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)in_stack_00000040 + 0x1c) = 1;
  EtwWriteEx(DAT_1c0009020,&local_18,0,1,0,0);
  return;
}



===== __report_gsfailure @ 1c00010d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AccelpGetSupportedCompression @ 1c00010e0 =====

void AccelpGetSupportedCompression(longlong param_1,void *param_2)

{
  uint uVar1;
  ulonglong *puVar2;
  
  memset(param_2,0,0x60);
  uVar1 = 1;
  puVar2 = (ulonglong *)((longlong)param_2 + 0x30);
  do {
    if (uVar1 == 1) {
      if (*(int *)(*(longlong *)(param_1 + 0x10) + 0xbc) == 2) {
        puVar2[-2] = puVar2[-2] | 1;
        puVar2[1] = 0x1000;
      }
    }
    else if ((uVar1 == 2) && (*(int *)(*(longlong *)(param_1 + 0x10) + 0xbc) == 2)) {
      puVar2[-2] = puVar2[-2] | 6;
      puVar2[-1] = puVar2[-1] | 1;
      *puVar2 = *puVar2 | 7;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (uVar1 < 3);
  return;
}



===== AccelpTimerCallback @ 1c0001170 =====

ulonglong AccelpTimerCallback(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  LOCK();
  uVar1 = *(uint *)(param_2 + 0x108);
  if (uVar1 == 0) {
    *(uint *)(param_2 + 0x108) = 1;
  }
  else {
    uVar2 = (ulonglong)uVar1;
  }
  UNLOCK();
  if (uVar1 == 0) {
    uVar2 = ExQueueWorkItem(param_2 + 0xe0,1);
  }
  return uVar2;
}



===== AccelpUnregisterAndFreeDevice @ 1c00011a8 =====

void AccelpUnregisterAndFreeDevice(longlong param_1)

{
  longlong lVar1;
  
  if (param_1 != 0) {
    AccelpUnregisterPlugPlayNotification(*(longlong *)(param_1 + 0x118));
    AccelpDeleteLock();
    RtlFreeUnicodeString(param_1 + 0x28);
    AccelpDeleteLock();
    lVar1 = param_1 + 0x130;
    AccelpDeleteLock();
    AccelpFree(lVar1,param_1);
  }
  return;
}



===== AccelpSetEvent @ 1c0001208 =====

void AccelpSetEvent(undefined8 param_1)

{
  KeSetEvent(param_1,0,0);
  return;
}



===== AccelpVerifyIrqlLessThanOrEqual @ 1c000122c =====

uint AccelpVerifyIrqlLessThanOrEqual(void)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  return -(uint)(cVar1 != '\0') & 0xc0000010;
}



===== AccelpWaitEvent @ 1c0001254 =====

void AccelpWaitEvent(undefined8 param_1)

{
  KeWaitForSingleObject(param_1,0,0,0,0);
  return;
}



===== AccelBuildDescriptorBatch @ 1c0001280 =====

undefined4 AccelBuildDescriptorBatch(longlong *param_1,ulonglong param_2,longlong param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0x1280  5  AccelBuildDescriptorBatch */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if ((((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_3 != 0)) ||
     (lVar1 = param_1[1], *(uint *)(lVar1 + 0x10) < param_2)) {
    uVar2 = 0xc000000d;
  }
  else {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_50 = 0;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_40 = *(undefined8 *)(lVar1 + 0x30);
    local_78[0] = 10;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_48 = lVar1;
      local_38 = param_2;
      uVar2 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar2 = 0xc00000bb;
    }
  }
  return uVar2;
}



===== AccelBuildDescriptorMemoryCompare @ 1c00013a0 =====

undefined4
AccelBuildDescriptorMemoryCompare
          (longlong *param_1,longlong param_2,longlong param_3,longlong param_4,undefined8 param_5)

{
  undefined4 uVar1;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  
                    /* 0x13a0  6  AccelBuildDescriptorMemoryCompare */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if ((((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_50 = param_5;
    local_78[0] = 8;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_48 = param_2;
      local_40 = param_3;
      local_38 = param_4;
      uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar1 = 0xc00000bb;
    }
  }
  return uVar1;
}



===== AccelBuildDescriptorMemoryCompress @ 1c00014c0 =====

undefined4 AccelBuildDescriptorMemoryCompress(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  longlong local_18;
  
                    /* 0x14c0  7  AccelBuildDescriptorMemoryCompress */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  plVar1 = *(longlong **)(param_1 + 8);
  if ((((plVar1 == (longlong *)0x0) || (lVar2 = *(longlong *)(param_1 + 0x18), lVar2 == 0)) ||
      (*(int *)(lVar2 + 4) != 6)) ||
     ((*(int *)(lVar2 + 8) != *(int *)(param_1 + 0x10) ||
      (*(int *)(lVar2 + 0xc) != *(int *)(param_1 + 0x14))))) {
    uVar3 = 0xc000000d;
  }
  else {
    memset((void *)plVar1[3],0,(ulonglong)*(uint *)(*(longlong *)(*plVar1 + 0x10) + 0x10c));
    memset((void *)plVar1[4],0,(ulonglong)*(uint *)(*(longlong *)(*plVar1 + 0x10) + 0x110));
    local_68 = (undefined4)plVar1[2];
    local_70 = *plVar1;
    local_60 = plVar1[3];
    local_58 = plVar1[4];
    local_50 = *(undefined8 *)(param_1 + 0x20);
    local_48 = *(undefined8 *)(param_1 + 0x28);
    local_40 = *(undefined4 *)(param_1 + 0x30);
    local_38 = *(undefined8 *)(param_1 + 0x38);
    local_30 = *(undefined4 *)(param_1 + 0x40);
    local_20 = *(undefined4 *)(param_1 + 0x10);
    local_1c = *(undefined4 *)(param_1 + 0x14);
    local_18 = param_1 + 0x44;
    local_78[0] = 0xb;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_28 = lVar2;
      uVar3 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== AccelBuildDescriptorMemoryCopy @ 1c0001610 =====

undefined4
AccelBuildDescriptorMemoryCopy
          (longlong *param_1,longlong param_2,longlong param_3,longlong param_4,undefined8 param_5)

{
  undefined4 uVar1;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  
                    /* 0x1610  8  AccelBuildDescriptorMemoryCopy */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if ((((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_50 = param_5;
    local_78[0] = 7;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_48 = param_2;
      local_40 = param_3;
      local_38 = param_4;
      uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar1 = 0xc00000bb;
    }
  }
  return uVar1;
}



===== AccelBuildDescriptorMemoryDecompress @ 1c0001730 =====

undefined4 AccelBuildDescriptorMemoryDecompress(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  longlong local_10;
  
                    /* 0x1730  9  AccelBuildDescriptorMemoryDecompress */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  plVar1 = *(longlong **)(param_1 + 8);
  if ((((plVar1 == (longlong *)0x0) || (lVar2 = *(longlong *)(param_1 + 0x18), lVar2 == 0)) ||
      (*(int *)(lVar2 + 4) != 7)) ||
     ((*(int *)(lVar2 + 8) != *(int *)(param_1 + 0x10) ||
      (*(int *)(lVar2 + 0xc) != *(int *)(param_1 + 0x14))))) {
    uVar3 = 0xc000000d;
  }
  else {
    memset((void *)plVar1[3],0,(ulonglong)*(uint *)(*(longlong *)(*plVar1 + 0x10) + 0x10c));
    memset((void *)plVar1[4],0,(ulonglong)*(uint *)(*(longlong *)(*plVar1 + 0x10) + 0x110));
    local_68 = (undefined4)plVar1[2];
    local_70 = *plVar1;
    local_60 = plVar1[3];
    local_58 = plVar1[4];
    local_50 = *(undefined8 *)(param_1 + 0x20);
    local_48 = *(undefined8 *)(param_1 + 0x28);
    local_40 = *(undefined4 *)(param_1 + 0x30);
    local_38 = *(undefined8 *)(param_1 + 0x38);
    local_30 = *(undefined4 *)(param_1 + 0x40);
    local_20 = *(undefined4 *)(param_1 + 0x10);
    local_1c = *(undefined4 *)(param_1 + 0x14);
    local_10 = param_1 + 0x44;
    local_78[0] = 0xc;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_28 = lVar2;
      uVar3 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== AccelBuildDescriptorMemoryFill @ 1c0001880 =====

undefined4
AccelBuildDescriptorMemoryFill
          (longlong *param_1,longlong param_2,longlong param_3,undefined8 param_4,undefined8 param_5
          )

{
  undefined4 uVar1;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  longlong local_40;
  undefined8 local_38;
  
                    /* 0x1880  10  AccelBuildDescriptorMemoryFill */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if (((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_50 = param_5;
    local_78[0] = 6;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_48 = param_2;
      local_40 = param_3;
      local_38 = param_4;
      uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar1 = 0xc00000bb;
    }
  }
  return uVar1;
}



===== AccelBuildDescriptorNop @ 1c0001990 =====

undefined8 AccelBuildDescriptorNop(longlong *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 extraout_var;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  
                    /* 0x1990  11  AccelBuildDescriptorNop */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if (param_1 == (longlong *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_78[0] = 9;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_50 = param_2;
      uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
      uVar2 = CONCAT44(extraout_var,uVar1);
    }
    else {
      uVar2 = 0xc00000bb;
    }
  }
  return uVar2;
}



===== AccelCompareMemory @ 1c0001a60 =====

uint AccelCompareMemory(longlong *param_1,longlong param_2,longlong param_3,longlong param_4,
                       ulonglong param_5)

{
  uint uVar1;
  
                    /* 0x1a60  13  AccelCompareMemory */
  uVar1 = AccelBuildDescriptorMemoryCompare(param_1,param_2,param_3,param_4,param_5);
  if (-1 < (int)uVar1) {
    if ((param_5 & 0xfffffffffffffff0) == 0) {
      if ((param_5 & 4) == 0) {
        uVar1 = AccelSubmitWorkSync(param_1);
      }
      else {
        uVar1 = AccelSubmitWorkAsync(param_1);
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== AccelCompressBuffer @ 1c0001ac0 =====

uint AccelCompressBuffer(longlong param_1)

{
  longlong *plVar1;
  ulonglong *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  longlong local_a0;
  ulonglong local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined4 local_78;
  undefined1 local_74;
  undefined2 local_73;
  undefined1 local_71;
  short local_68 [4];
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
                    /* 0x1ac0  14  AccelCompressBuffer */
  plVar1 = (longlong *)(param_1 + 0x18);
  puVar2 = (ulonglong *)(param_1 + 0x20);
  puVar3 = (undefined8 *)(param_1 + 8);
  if (*(int *)(param_1 + 0x14) == 3) {
    uVar4 = AccelpComputeHistogram
                      ((longlong *)*puVar3,*(longlong *)(param_1 + 0x28),
                       *(undefined4 *)(param_1 + 0x30),*plVar1,*puVar2 & 0xfffffffffffffffb);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar5 = AccelpBuildHuffmanEncoding(*plVar1);
    if ((int)(uint)uVar5 < 0) {
      return (uint)uVar5;
    }
  }
  local_b0 = *puVar3;
  local_a8 = *(undefined4 *)(param_1 + 0x10);
  local_a4 = *(undefined4 *)(param_1 + 0x14);
  local_a0 = *plVar1;
  local_98 = *puVar2;
  local_90 = *(undefined8 *)(param_1 + 0x28);
  local_88 = *(undefined4 *)(param_1 + 0x30);
  local_80 = *(undefined8 *)(param_1 + 0x38);
  local_78 = *(undefined4 *)(param_1 + 0x40);
  local_74 = *(undefined1 *)(param_1 + 0x44);
  local_b8 = 0x480001;
  local_84 = 0;
  local_73 = 0;
  local_71 = 0;
  uVar4 = AccelBuildDescriptorMemoryCompress((longlong)&local_b8);
  if (-1 < (int)uVar4) {
    if ((*puVar2 & 0xfffffffffffffff0) == 0) {
      if ((*puVar2 & 4) == 0) {
        uVar4 = AccelSubmitWorkSync((longlong *)*puVar3);
      }
      else {
        uVar4 = AccelSubmitWorkAsync((longlong *)*puVar3);
      }
      if ((-1 < (int)uVar4) && ((*(byte *)(param_1 + 0x20) & 4) == 0)) {
        local_38 = 0;
        uStack_50 = 0;
        local_68[0] = 1;
        local_68[1] = 0x38;
        local_68[2] = 0;
        local_68[3] = 0;
        uStack_60 = *(undefined8 *)(param_1 + 8);
        local_58 = 1;
        local_48 = 0;
        uStack_40 = 0;
        uVar4 = AccelQueryCompletionInformation(local_68);
        if (-1 < (int)uVar4) {
          *(undefined4 *)(param_1 + 0x48) = (undefined4)uStack_50;
          *(undefined4 *)(param_1 + 0x54) = local_48._4_4_;
          *(undefined1 *)(param_1 + 0x50) = (undefined1)local_48;
          *(undefined4 *)(param_1 + 0x4c) = uStack_50._4_4_;
        }
      }
    }
    else {
      uVar4 = 0xc000000d;
    }
  }
  return uVar4;
}



===== AccelCopyMemory @ 1c0001c50 =====

uint AccelCopyMemory(longlong *param_1,longlong param_2,longlong param_3,longlong param_4,
                    ulonglong param_5)

{
  uint uVar1;
  
                    /* 0x1c50  15  AccelCopyMemory */
  uVar1 = AccelBuildDescriptorMemoryCopy(param_1,param_2,param_3,param_4,param_5);
  if (-1 < (int)uVar1) {
    if ((param_5 & 0xfffffffffffffff0) == 0) {
      if ((param_5 & 4) == 0) {
        uVar1 = AccelSubmitWorkSync(param_1);
      }
      else {
        uVar1 = AccelSubmitWorkAsync(param_1);
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== AccelDecompressBuffer @ 1c0001cb0 =====

uint AccelDecompressBuffer(longlong param_1)

{
  uint uVar1;
  short local_98 [4];
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1cb0  16  AccelDecompressBuffer */
  local_50 = *(undefined8 *)(param_1 + 8);
  local_54 = 0;
  local_24 = 0;
  local_48 = *(undefined4 *)(param_1 + 0x10);
  local_44 = *(undefined4 *)(param_1 + 0x14);
  local_40 = *(undefined8 *)(param_1 + 0x18);
  local_38 = *(undefined8 *)(param_1 + 0x20);
  local_30 = *(undefined8 *)(param_1 + 0x38);
  local_28 = *(undefined4 *)(param_1 + 0x40);
  local_20 = *(undefined8 *)(param_1 + 0x28);
  local_18 = *(undefined4 *)(param_1 + 0x30);
  local_14 = *(undefined4 *)(param_1 + 0x44);
  local_58 = 0x480001;
  uVar1 = AccelBuildDescriptorMemoryDecompress((longlong)&local_58);
  if (-1 < (int)uVar1) {
    if ((*(ulonglong *)(param_1 + 0x20) & 0xfffffffffffffff0) == 0) {
      if ((*(ulonglong *)(param_1 + 0x20) & 4) == 0) {
        uVar1 = AccelSubmitWorkSync(*(longlong **)(param_1 + 8));
      }
      else {
        uVar1 = AccelSubmitWorkAsync(*(longlong **)(param_1 + 8));
      }
      if ((-1 < (int)uVar1) && ((*(byte *)(param_1 + 0x20) & 4) == 0)) {
        local_68 = 0;
        uStack_90 = *(undefined8 *)(param_1 + 8);
        uStack_80 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_98[0] = 1;
        local_98[1] = 0x38;
        local_98[2] = 0;
        local_98[3] = 0;
        local_88 = 1;
        uVar1 = AccelQueryCompletionInformation(local_98);
        if (-1 < (int)uVar1) {
          *(undefined4 *)(param_1 + 0x48) = (undefined4)uStack_80;
          *(undefined4 *)(param_1 + 0x54) = local_78._4_4_;
          *(undefined1 *)(param_1 + 0x50) = (undefined1)local_78;
          *(undefined4 *)(param_1 + 0x4c) = uStack_80._4_4_;
        }
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== AccelFillMemory @ 1c0001de0 =====

uint AccelFillMemory(longlong *param_1,longlong param_2,longlong param_3,undefined8 param_4,
                    ulonglong param_5)

{
  uint uVar1;
  
                    /* 0x1de0  19  AccelFillMemory */
  uVar1 = AccelBuildDescriptorMemoryFill(param_1,param_2,param_3,param_4,param_5);
  if (-1 < (int)uVar1) {
    if ((param_5 & 0xfffffffffffffff0) == 0) {
      if ((param_5 & 4) == 0) {
        uVar1 = AccelSubmitWorkSync(param_1);
      }
      else {
        uVar1 = AccelSubmitWorkAsync(param_1);
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== AccelGetStatusFromCompletionRecord @ 1c0001e40 =====

undefined4 AccelGetStatusFromCompletionRecord(longlong *param_1)

{
  undefined4 uVar1;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  
                    /* 0x1e40  20  AccelGetStatusFromCompletionRecord */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if (param_1 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_50 = 0;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_78[0] = 3;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar1 = 0xc00000bb;
    }
  }
  return uVar1;
}



===== AccelGetSubdescriptorInBatch @ 1c0001ed0 =====

longlong AccelGetSubdescriptorInBatch(longlong param_1,uint param_2)

{
                    /* 0x1ed0  21  AccelGetSubdescriptorInBatch */
  if ((param_1 == 0) || (*(uint *)(*(longlong *)(param_1 + 8) + 0x10) <= param_2)) {
    return 0;
  }
  return *(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + (ulonglong)param_2 * 0x28;
}



===== AccelInitializeBatchDescriptor @ 1c0001f00 =====

int AccelInitializeBatchDescriptor(short *param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint local_res8 [2];
  uint local_res20 [2];
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28 [4];
  
                    /* 0x1f00  22  AccelInitializeBatchDescriptor */
  local_28[0] = 0;
  if (((param_1 == (short *)0x0) || (param_2 == 0)) || (param_3 == (longlong *)0x0)) {
    iVar5 = -0x3ffffff3;
  }
  else if ((*param_1 == 0) || ((ushort)param_1[1] < 0x20)) {
    iVar5 = -0x3fffffa7;
  }
  else {
    local_2c = 0;
    local_res8[0] = 0;
    local_res20[0] = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    iVar5 = AccelpGetBatchDescriptorInfo
                      ((longlong)param_1,(longlong)param_3,&local_2c,(int *)local_res8,
                       (int *)local_res20,(int *)&local_38,(int *)&local_34,&local_30);
    uVar4 = local_2c;
    if ((((-1 < iVar5) && (local_2c != 0)) &&
        ((local_res8[0] != 0 && (((local_res20[0] != 0 && (local_38 != 0)) && (local_34 != 0))))))
       && (local_30 != 0)) {
      iVar5 = AccelQueryDescriptorSize(*(longlong *)(param_1 + 4),(int *)local_28);
      if (iVar5 < 0) {
        return iVar5;
      }
      iVar5 = AccelInitializeDescriptor(*(longlong *)(param_1 + 4),local_28[0],param_3);
      if (iVar5 < 0) {
        return iVar5;
      }
      lVar1 = *(longlong *)(*param_3 + 0x10);
      if (local_res8[0] <= param_2) {
        puVar7 = (undefined8 *)((ulonglong)local_res20[0] + (longlong)param_3);
        param_3[1] = (longlong)puVar7;
        lVar8 = (ulonglong)local_38 + (longlong)param_3;
        uVar2 = *(undefined8 *)(param_1 + 4);
        *puVar7 = *(undefined8 *)param_1;
        puVar7[1] = uVar2;
        uVar2 = *(undefined8 *)(param_1 + 8);
        uVar3 = *(undefined8 *)(param_1 + 0xc);
        puVar7[6] = (ulonglong)local_34 + (longlong)param_3;
        puVar7[5] = lVar8;
        puVar7[7] = (ulonglong)local_30 + (longlong)param_3;
        *(uint *)(puVar7 + 4) = uVar4;
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
        uVar6 = 0;
        if (uVar4 != 0) {
          do {
            *(undefined8 *)(lVar8 + uVar6 * 0x28) = *(undefined8 *)(param_1 + 4);
            iVar5 = (int)uVar6;
            *(ulonglong *)(lVar8 + 0x18 + uVar6 * 0x28) =
                 (ulonglong)(uint)(iVar5 * *(int *)(lVar1 + 0x10c)) + puVar7[6];
            *(ulonglong *)(lVar8 + 0x20 + uVar6 * 0x28) =
                 (ulonglong)(uint)(iVar5 * *(int *)(lVar1 + 0x110)) + puVar7[7];
            uVar6 = (ulonglong)(iVar5 + 1U);
          } while (iVar5 + 1U < *(uint *)(puVar7 + 4));
        }
        return 0;
      }
    }
    iVar5 = -0x3fffffff;
  }
  return iVar5;
}



===== AccelInitializeCompressionWorkspace @ 1c00020e0 =====

int AccelInitializeCompressionWorkspace(short *param_1)

{
  int iVar1;
  undefined8 local_88;
  int local_80;
  undefined4 local_7c;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  
                    /* 0x20e0  23  AccelInitializeCompressionWorkspace */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  local_7c = 0;
  if (param_1 != (short *)0x0) {
    local_38 = *(int *)(param_1 + 0x10);
    if ((local_38 == 1) && (*(int *)(param_1 + 0x12) - 2U < 3)) {
      return -0x3ffffffe;
    }
    if ((*param_1 == 0) || ((ushort)param_1[1] < 0x40)) {
      return -0x3fffffa7;
    }
    if ((*(longlong **)(param_1 + 4) != (longlong *)0x0) &&
       ((((local_80 = *(int *)(param_1 + 0x1c), local_80 == 0 ||
          (*(longlong *)(param_1 + 0x18) != 0)) &&
         (local_3c = *(int *)(param_1 + 0xe), local_3c - 6U < 2)) &&
        ((local_38 - 1U < 2 && (local_34 = *(int *)(param_1 + 0x12), local_34 - 1U < 4)))))) {
      local_48 = *(undefined8 *)(param_1 + 8);
      local_70 = **(longlong **)(param_1 + 4);
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      local_50 = 0;
      local_40 = *(undefined4 *)(param_1 + 0xc);
      local_88 = *(undefined8 *)(param_1 + 0x18);
      local_78[0] = 0xd;
      if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) != 1) {
        return -0x3fffff45;
      }
      iVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)&local_88);
      if ((iVar1 < 0) && (iVar1 != -0x3fffffdd)) {
        return iVar1;
      }
      *(int *)(param_1 + 0x1c) = local_80;
      return iVar1;
    }
  }
  return -0x3ffffff3;
}



===== AccelInitializeDescriptor @ 1c0002230 =====

int AccelInitializeDescriptor(longlong param_1,uint param_2,longlong *param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  
                    /* 0x2230  24  AccelInitializeDescriptor */
  local_res8[0] = 0;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != (longlong *)0x0)) {
    iVar2 = AccelQueryDescriptorSize(param_1,(int *)local_res8);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_res8[0] <= param_2) {
      *param_3 = param_1;
      uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x20);
      param_3[3] = (longlong)(param_3 + 5);
      *(undefined4 *)(param_3 + 2) = uVar1;
      uVar3 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x114);
      param_3[4] = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x10c) + 0x27 + uVar3 +
                   (longlong)param_3 & -uVar3;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== AccelQueryBatchDescriptorSize @ 1c00022d0 =====

int AccelQueryBatchDescriptorSize(longlong param_1,int *param_2)

{
  int iVar1;
  int local_res8 [8];
  
                    /* 0x22d0  26  AccelQueryBatchDescriptorSize */
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else if (*(longlong *)(param_1 + 0x18) == 0) {
    local_res8[0] = 0;
    iVar1 = AccelpGetBatchDescriptorInfo
                      (param_1,0,(uint *)0x0,local_res8,(int *)0x0,(int *)0x0,(int *)0x0,(uint *)0x0
                      );
    if (-1 < iVar1) {
      *param_2 = local_res8[0];
    }
  }
  else {
    iVar1 = -0x3fffff45;
  }
  return iVar1;
}



===== AccelQueryCompletionInformation @ 1c0002340 =====

undefined4 AccelQueryCompletionInformation(short *param_1)

{
  longlong *plVar1;
  undefined4 uVar2;
  short *local_88;
  undefined8 local_80;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined4 local_48;
  
                    /* 0x2340  27  AccelQueryCompletionInformation */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  local_80 = 0;
  if (param_1 == (short *)0x0) {
    uVar2 = 0xc000000d;
  }
  else if ((*param_1 == 0) || ((ushort)param_1[1] < 0x38)) {
    uVar2 = 0xc0000059;
  }
  else {
    plVar1 = *(longlong **)(param_1 + 4);
    local_78[0] = 4;
    local_68 = 0;
    local_50 = 0;
    local_60 = plVar1[3];
    local_70 = *plVar1;
    local_58 = plVar1[4];
    local_48 = *(undefined4 *)(param_1 + 8);
    local_88 = param_1 + 0xc;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      uVar2 = AccelpSiovInternalOperationHandler(local_78,(uint *)&local_88);
    }
    else {
      uVar2 = 0xc00000bb;
    }
  }
  return uVar2;
}



===== AccelQueryDescriptorSize @ 1c0002410 =====

int AccelQueryDescriptorSize(longlong param_1,int *param_2)

{
  int iVar1;
  uint local_88 [6];
  longlong local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  
                    /* 0x2410  28  AccelQueryDescriptorSize */
  local_88[5] = 0;
  memset(local_88 + 4,0,0x6c);
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_88[4] = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0xb8) == 1) {
      local_70 = param_1;
      iVar1 = AccelpSiovInternalOperationHandler((int *)(local_88 + 4),local_88);
      if (-1 < iVar1) {
        *param_2 = local_88[2] + 0x27 + local_88[0] + local_88[1];
      }
    }
    else {
      iVar1 = -0x3fffff45;
    }
  }
  return iVar1;
}



===== AccelResetCompletionRecord @ 1c00024d0 =====

undefined8 AccelResetCompletionRecord(longlong *param_1)

{
  undefined8 uVar1;
  
                    /* 0x24d0  30  AccelResetCompletionRecord */
  if (param_1 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    uVar1 = 0;
  }
  return uVar1;
}



===== AccelResetDescriptorAddressSpace @ 1c0002510 =====

void AccelResetDescriptorAddressSpace(longlong *param_1)

{
                    /* 0x2510  31  AccelResetDescriptorAddressSpace */
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(*(longlong *)(*param_1 + 0x10) + 0x20);
  return;
}



===== AccelSetDescriptorAddressSpace @ 1c0002530 =====

void AccelSetDescriptorAddressSpace(longlong param_1,longlong param_2)

{
                    /* 0x2530  32  AccelSetDescriptorAddressSpace */
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x28);
  return;
}



===== AccelSubmitWorkAsync @ 1c0002540 =====

undefined4 AccelSubmitWorkAsync(longlong *param_1)

{
  undefined4 uVar1;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  
                    /* 0x2540  35  AccelSubmitWorkAsync */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  if (param_1 != (longlong *)0x0) {
    local_70 = *param_1;
    local_48 = *(longlong *)(local_70 + 0x20);
    if (local_48 != 0) {
      local_68 = (undefined4)param_1[2];
      local_50 = 0;
      local_60 = param_1[3];
      local_58 = param_1[4];
      local_78[0] = 1;
      if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
        uVar1 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
        return uVar1;
      }
      return 0xc00000bb;
    }
  }
  return 0xc000000d;
}



===== AccelSubmitWorkSync @ 1c00025e0 =====

uint AccelSubmitWorkSync(longlong *param_1)

{
  uint uVar1;
  
                    /* 0x25e0  36  AccelSubmitWorkSync */
  if (param_1 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = AccelSubmitWorkAsync(param_1);
    if (-1 < (int)uVar1) {
      uVar1 = AccelWaitForWorkCompletion(param_1,0,0);
      if (-1 < (int)uVar1) {
        uVar1 = AccelGetStatusFromCompletionRecord(param_1);
      }
    }
  }
  return uVar1;
}



===== AccelWaitForMultipleWorkCompletion @ 1c0002630 =====

uint AccelWaitForMultipleWorkCompletion
               (undefined8 *param_1,uint param_2,longlong *param_3,uint param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  byte local_38;
  
                    /* 0x2630  37  AccelWaitForMultipleWorkCompletion */
  if ((((param_1 == (undefined8 *)0x0) || (param_2 == 0)) || ((param_4 & 0xfffffffc) != 0)) ||
     (((param_4 & 2) != 0 && (param_5 == (uint *)0x0)))) {
LAB_1c000278e:
    uVar4 = 0xc000000d;
  }
  else {
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(*(longlong *)*param_1 + 0x10) + 0x10) + 0xa0);
    if (param_3 == (longlong *)0x0) {
      lVar3 = -1;
    }
    else {
      if (*param_3 < 1) goto LAB_1c000278e;
      lVar3 = KeQueryPerformanceCounter(0);
      lVar5 = lVar5 * *param_3;
      lVar5 = lVar5 + SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar5),8);
      lVar3 = ((lVar5 >> 0x17) - (lVar5 >> 0x3f)) + lVar3;
    }
    local_38 = 1;
    do {
      bVar1 = 0;
      uVar4 = 0;
      if (param_2 != 0) {
        puVar6 = param_1;
        bVar1 = 0;
        do {
          if ((param_3 != (longlong *)0x0) && (lVar5 = KeQueryPerformanceCounter(0), lVar3 <= lVar5)
             ) {
            return 0x102;
          }
          uVar2 = AccelGetStatusFromCompletionRecord((longlong *)*puVar6);
          if (((int)uVar2 < 0) || (uVar2 == 0x103)) {
            bVar1 = 1;
          }
          else if ((param_4 & 2) != 0) {
            *param_5 = uVar4;
            return uVar2;
          }
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < param_2);
      }
      if ((param_4 & 1) != 0) {
        return -(uint)bVar1 & 0xc0000001;
      }
      local_38 = local_38 & -bVar1;
    } while (local_38 != 0);
    uVar4 = 0;
  }
  return uVar4;
}



===== AccelWaitForWorkCompletion @ 1c00027c0 =====

uint AccelWaitForWorkCompletion(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int local_78 [2];
  longlong local_70;
  undefined4 local_68;
  longlong local_60;
  longlong local_58;
  ulonglong local_50;
  undefined8 local_48;
  
                    /* 0x27c0  38  AccelWaitForWorkCompletion */
  local_78[1] = 0;
  memset(local_78,0,0x6c);
  bVar2 = 0;
  if ((param_1 == (longlong *)0x0) || ((param_3 & 0xfffffffc) != 0)) {
    uVar3 = 0xc000000d;
  }
  else if ((param_3 & 1) == 0) {
    local_68 = (undefined4)param_1[2];
    local_70 = *param_1;
    local_60 = param_1[3];
    local_58 = param_1[4];
    local_78[0] = 2;
    if (*(int *)(*(longlong *)(local_70 + 0x10) + 0xb8) == 1) {
      local_50 = param_3 & 0xffffffff;
      local_48 = param_2;
      uVar3 = AccelpSiovInternalOperationHandler(local_78,(uint *)0x0);
    }
    else {
      uVar3 = 0xc00000bb;
    }
  }
  else {
    iVar1 = *(int *)(*(longlong *)(*param_1 + 0x10) + 0xbc);
    if ((iVar1 == 1) || (iVar1 == 2)) {
      bVar2 = *(byte *)param_1[4] & 0x3f;
    }
    uVar3 = ~-(uint)(bVar2 != 0) & 0xc0000001;
  }
  return uVar3;
}



===== AccelZeroMemory @ 1c00028d0 =====

void AccelZeroMemory(longlong *param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
                    /* 0x28d0  39  AccelZeroMemory */
  AccelFillMemory(param_1,param_2,param_3,0,param_4);
  return;
}



===== AccelpBuildHuffmanEncoding @ 1c00028f0 =====

undefined8 AccelpBuildHuffmanEncoding(longlong param_1)

{
  ulonglong *_Base;
  ulonglong uVar1;
  ulonglong *puVar2;
  ulonglong *puVar3;
  uint uVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  size_t _NumOfElements;
  ulonglong *puVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  
  _Base = *(ulonglong **)(param_1 + 0x18);
  _NumOfElements = 0;
  memset(_Base + 0x749,0,0x100);
  uVar1 = 0;
  puVar5 = _Base + 0x6a9;
  puVar7 = _Base;
  do {
    if ((ulonglong)(uint)*puVar5 != 0) {
      *puVar7 = (ulonglong)(uint)*puVar5;
      puVar7[1] = 0;
      puVar7[2] = uVar1;
      puVar7 = puVar7 + 3;
      _NumOfElements = _NumOfElements + 1;
    }
    uVar1 = uVar1 + 1;
    puVar5 = (ulonglong *)((longlong)puVar5 + 4);
  } while (uVar1 < 0x100);
  if (_NumOfElements == 0) {
    return 0xc000000d;
  }
  if (_NumOfElements == 1) {
    *(uint *)((longlong)_Base + _Base[2] * 4 + 0x3148) =
         *(uint *)((longlong)_Base + _Base[2] * 4 + 0x3148) & 0xfff88000 | 0x8000;
    return 0;
  }
  qsort(_Base,_NumOfElements,0x18,AccelpCodeSort);
  while( true ) {
    puVar7[1] = (ulonglong)_Base;
    puVar5 = _Base + 6;
    puVar7[2] = (ulonglong)(_Base + 3);
    *puVar7 = _Base[3] + *_Base;
    puVar3 = puVar7;
    puVar8 = puVar7;
    while ((puVar5 != puVar7 || (puVar8 != puVar3))) {
      puVar2 = puVar3 + 3;
      if ((puVar5 == puVar7) || ((puVar8 < puVar2 && (*puVar8 < *puVar5)))) {
        puVar3[4] = (ulonglong)puVar8;
        uVar1 = *puVar8;
        puVar8 = puVar8 + 3;
      }
      else {
        puVar3[4] = (ulonglong)puVar5;
        uVar1 = *puVar5;
        puVar5 = puVar5 + 3;
      }
      *puVar2 = uVar1;
      if ((puVar5 == puVar7) || ((puVar8 < puVar2 && (*puVar8 < *puVar5)))) {
        puVar3[5] = (ulonglong)puVar8;
        *puVar2 = *puVar2 + *puVar8;
        puVar8 = puVar8 + 3;
        puVar3 = puVar2;
      }
      else {
        puVar3[5] = (ulonglong)puVar5;
        *puVar2 = *puVar2 + *puVar5;
        puVar5 = puVar5 + 3;
        puVar3 = puVar2;
      }
    }
    uVar1 = 0;
    puVar5 = _Base + 0x603;
    lVar11 = 0;
    puVar8 = _Base + 0x604;
    while( true ) {
      for (; puVar3[1] != 0; puVar3 = (ulonglong *)puVar3[2]) {
        uVar1 = uVar1 + 1;
        lVar11 = lVar11 + 1;
        *puVar8 = uVar1;
        puVar8 = puVar8 + 2;
        *puVar5 = puVar3[1];
        puVar5 = puVar5 + 2;
      }
      puVar3[1] = uVar1;
      *(char *)(puVar3[2] + 0x3a48 + (longlong)_Base) = (char)uVar1;
      if (lVar11 == 0) break;
      puVar3 = (ulonglong *)puVar5[-2];
      puVar8 = puVar8 + -2;
      lVar11 = lVar11 + -1;
      puVar5 = puVar5 + -2;
      uVar1 = *puVar8;
    }
    uVar1 = _Base[1];
    puVar5 = _Base;
    if (uVar1 < 0x10) break;
    for (; puVar5 < puVar7; puVar5 = puVar5 + 3) {
      puVar5[1] = 0;
      *puVar5 = *puVar5 + 1 >> 1;
    }
  }
  uVar10 = 0;
  for (uVar9 = puVar7[-2]; uVar9 <= uVar1; uVar9 = uVar9 + 1) {
    uVar6 = 0;
    puVar5 = _Base + 0x629;
    do {
      if (*(byte *)((longlong)_Base + uVar6 + 0x3a48) == uVar9) {
        uVar4 = (((uint)uVar9 & 0xffff) << 0xf ^ (uint)*puVar5) & 0x78000 ^ (uint)*puVar5;
        *(uint *)puVar5 = (uVar10 ^ uVar4) & 0x7fff ^ uVar4;
        uVar10 = uVar10 + 1;
      }
      uVar6 = uVar6 + 1;
      puVar5 = (ulonglong *)((longlong)puVar5 + 4);
    } while (uVar6 < 0x100);
    uVar10 = uVar10 * 2;
  }
  return 0;
}



===== AccelpCalculateAccelDescriptorSize @ 1c0002ba8 =====

int AccelpCalculateAccelDescriptorSize(int param_1,int param_2,int param_3)

{
  return param_2 + 0x27 + param_1 + param_3;
}



===== AccelpCodeSort @ 1c0002bc0 =====

int AccelpCodeSort(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  if (uVar1 < uVar2) {
    return -1;
  }
  if (uVar2 < uVar1) {
    return 1;
  }
  if (uVar1 == uVar2) {
    return -(uint)(param_1[2] < param_2[2]);
  }
  return 0;
}



===== AccelpComputeHistogram @ 1c0002bf0 =====

uint AccelpComputeHistogram
               (longlong *param_1,longlong param_2,undefined4 param_3,longlong param_4,
               ulonglong param_5)

{
  uint uVar1;
  int local_88 [2];
  longlong local_80;
  undefined4 local_78;
  longlong local_70;
  longlong local_68;
  ulonglong local_60;
  longlong local_58;
  undefined4 local_50;
  longlong local_48;
  
  local_88[1] = 0;
  memset(local_88,0,0x6c);
  if (((param_1 != (longlong *)0x0) && (param_2 != 0)) && (param_4 != 0)) {
    memset((void *)param_1[3],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x10c));
    memset((void *)param_1[4],0,(ulonglong)*(uint *)(*(longlong *)(*param_1 + 0x10) + 0x110));
    local_78 = (undefined4)param_1[2];
    local_80 = *param_1;
    local_70 = param_1[3];
    local_68 = param_1[4];
    local_88[0] = 0xe;
    local_60 = param_5;
    local_58 = param_2;
    local_50 = param_3;
    local_48 = param_4;
    if (*(int *)(*(longlong *)(local_80 + 0x10) + 0xb8) == 1) {
      uVar1 = AccelpSiovInternalOperationHandler(local_88,(uint *)0x0);
    }
    else {
      uVar1 = 0xc00000bb;
    }
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((param_5 & 0xfffffffffffffff0) == 0) {
      if ((param_5 & 4) == 0) {
        uVar1 = AccelSubmitWorkSync(param_1);
        return uVar1;
      }
      uVar1 = AccelSubmitWorkAsync(param_1);
      return uVar1;
    }
  }
  return 0xc000000d;
}



===== AccelpGetBatchDescriptorInfo @ 1c0002d20 =====

int AccelpGetBatchDescriptorInfo
              (longlong param_1,longlong param_2,uint *param_3,int *param_4,int *param_5,
              int *param_6,int *param_7,uint *param_8)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_a8 [6];
  longlong local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  int local_68;
  
  local_a8[5] = 0;
  memset(local_a8 + 4,0,0x6c);
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  if ((param_1 == 0) || (local_68 = *(int *)(param_1 + 0x10), local_68 == 0)) {
    return -0x3ffffff3;
  }
  lVar1 = *(longlong *)(param_1 + 8);
  local_a8[4] = 5;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  if (*(int *)(*(longlong *)(lVar1 + 0x10) + 0xb8) == 1) {
    local_90 = lVar1;
    iVar3 = AccelpSiovInternalOperationHandler((int *)(local_a8 + 4),local_a8);
    if (iVar3 < 0) {
      return iVar3;
    }
    uVar2 = local_a8[0];
    local_a8[4] = 0;
    local_88 = 0;
    local_80 = 0;
    local_78 = 0;
    local_70 = 0;
    if (*(int *)(*(longlong *)(lVar1 + 0x10) + 0xb8) == 1) {
      local_90 = lVar1;
      iVar3 = AccelpSiovInternalOperationHandler((int *)(local_a8 + 4),local_a8);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = local_a8[2] + local_a8[1] + local_a8[0];
      iVar5 = iVar3 + 0x67;
      iVar6 = iVar5 + uVar2 * 0x28;
      if (param_2 == 0) {
        iVar6 = iVar6 + -1 + local_a8[3];
      }
      else {
        iVar4 = iVar6 + (int)param_2;
        iVar6 = iVar6 + (((local_a8[3] - 1) + iVar4 & -local_a8[3]) - iVar4);
      }
      uVar7 = iVar6 + local_a8[0] * uVar2;
      if (local_a8[3] % local_a8[2] != 0) {
        uVar7 = (uVar7 - 1) + local_a8[2] & -local_a8[2];
      }
      if (param_4 != (int *)0x0) {
        *param_4 = uVar7 + local_a8[1] * uVar2;
      }
      if (param_5 != (int *)0x0) {
        *param_5 = iVar3 + 0x27;
      }
      if (param_6 != (int *)0x0) {
        *param_6 = iVar5;
      }
      if (param_7 != (int *)0x0) {
        *param_7 = iVar6;
      }
      if (param_8 != (uint *)0x0) {
        *param_8 = uVar7;
      }
      if (param_3 != (uint *)0x0) {
        *param_3 = uVar2;
      }
      return 0;
    }
  }
  return -0x3fffff45;
}



===== AccelpInternalOperationHandler @ 1c0002ef0 =====

undefined4 AccelpInternalOperationHandler(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 2) + 0x10) + 0xb8) == 1) {
    uVar1 = AccelpSiovInternalOperationHandler(param_1,param_2);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== AccelpSiovCompressionDecompression @ 1c0002f20 =====

undefined8
AccelpSiovCompressionDecompression(int *param_1,byte param_2,uint param_3,char param_4,char param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  longlong lVar7;
  uint *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  byte bVar11;
  byte bVar12;
  undefined8 uVar13;
  
  iVar3 = param_1[0x16];
  lVar9 = 0;
  if (((iVar3 == 1) && (param_1[0x17] == 1)) ||
     (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x14) + 0x18), lVar9 != 0)) {
    if (*param_1 == 0xb) {
      if (iVar3 != 1) {
        if (iVar3 == 2) {
          IaaBuildDescriptorHuffmanCompress
                    (*(uint **)(param_1 + 6),*(undefined8 *)(param_1 + 8),
                     *(void **)(*(longlong *)(param_1 + 0x14) + 0x10),(undefined8 *)(lVar9 + 0x3148)
                     ,*(undefined8 *)(param_1 + 0xc),param_1[0xe],*(undefined8 *)(param_1 + 0x10),
                     param_1[0x12],**(byte **)(param_1 + 0x18),param_2,param_3,param_4,param_5);
          return 0;
        }
        goto LAB_1c0002f73;
      }
      if (param_1[0x17] == 1) {
        IaaBuildDescriptorFixedCompress
                  (*(uint **)(param_1 + 6),*(undefined8 *)(param_1 + 8),
                   *(void **)(*(longlong *)(param_1 + 0x14) + 0x10),*(undefined8 *)(param_1 + 0xc),
                   param_1[0xe],*(undefined8 *)(param_1 + 0x10),param_1[0x12],param_2,param_3,
                   param_4,param_5);
        return 0;
      }
    }
    else if (iVar3 == 1) {
      if (param_1[0x17] == 1) {
        puVar8 = *(uint **)(param_1 + 6);
        uVar4 = param_1[0x12];
        uVar10 = *(undefined8 *)(param_1 + 0x10);
        uVar5 = param_1[0xe];
        uVar13 = *(undefined8 *)(param_1 + 0xc);
        DsaBuildDescriptorCommon
                  (0x42,puVar8,*(undefined8 *)(param_1 + 8),param_2,param_3,param_4,param_5);
        *(ushort *)((longlong)puVar8 + 0x26) = *(ushort *)((longlong)puVar8 + 0x26) | 0x1f;
        *(undefined8 *)(puVar8 + 4) = uVar10;
        puVar8[8] = uVar4;
        *(undefined8 *)(puVar8 + 6) = uVar13;
        puVar8[0xc] = uVar5;
        return 0;
      }
    }
    else if (iVar3 == 2) {
      pbVar6 = *(byte **)(param_1 + 0x1a);
      puVar8 = *(uint **)(param_1 + 6);
      bVar1 = pbVar6[3];
      bVar2 = pbVar6[2];
      bVar12 = pbVar6[1];
      bVar11 = *pbVar6;
      uVar4 = param_1[0x12];
      uVar10 = *(undefined8 *)(param_1 + 0x10);
      uVar5 = param_1[0xe];
      uVar13 = *(undefined8 *)(param_1 + 0xc);
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x14) + 0x10);
      DsaBuildDescriptorCommon
                (0x42,puVar8,*(undefined8 *)(param_1 + 8),param_2,param_3,param_4,param_5);
      *(byte *)((longlong)puVar8 + 6) = *(byte *)((longlong)puVar8 + 6) & 0xfd | 1;
      *(ushort *)((longlong)puVar8 + 0x26) =
           (ushort)(bVar11 & 1) << 5 | *(ushort *)((longlong)puVar8 + 0x26) & 0xfe1f |
           (ushort)(bVar12 & 7) << 6 | 3;
      if (bVar2 != 0) {
        *(ulonglong *)(lVar7 + 0xb8) = (ulonglong)bVar1;
        *(byte *)(lVar7 + 0x1b8) = bVar2;
      }
      *(undefined8 *)(puVar8 + 4) = uVar10;
      puVar8[8] = uVar4;
      *(undefined8 *)(puVar8 + 6) = uVar13;
      puVar8[0xc] = uVar5;
      *(longlong *)(puVar8 + 10) = lVar7;
      puVar8[0xd] = 0x1500;
      IaapSetAecsDecompressionHuffmanTable
                ((uint *)(lVar9 + 0x3148),*(void **)(*(longlong *)(param_1 + 0x14) + 0x10),
                 (ushort *)(lVar9 + 0x3b48),lVar9 + 0x3f48,(ushort *)(lVar9 + 0x4348));
      return 0;
    }
    uVar10 = 0xc000025f;
  }
  else {
LAB_1c0002f73:
    uVar10 = 0xc000000d;
  }
  return uVar10;
}



===== AccelpSiovDsaOperationHandler @ 1c0003210 =====

ulonglong AccelpSiovDsaOperationHandler(int *param_1,uint *param_2)

{
  longlong *plVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 uVar11;
  longlong lVar12;
  uint *puVar13;
  byte *pbVar14;
  int local_res8 [2];
  
  iVar8 = *param_1;
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 2) + 0x10);
  uVar9 = *(ulonglong *)(lVar12 + 0xc0);
  if (iVar8 == 0) {
    *param_2 = 0x40;
    param_2[1] = 0x20;
    param_2[2] = 0x20;
    if (param_2 + 3 != (uint *)0x0) {
      param_2[3] = 0x40;
    }
LAB_1c0003582:
    uVar10 = 0x21;
LAB_1c0003587:
    uVar9 = *(ulonglong *)(param_1 + 10);
    lVar12 = *(longlong *)(param_1 + 6);
    if ((((uVar10 == 0) || (uVar10 == 1)) || (uVar10 == 3)) || ((uVar10 == 4 || (uVar10 == 5)))) {
      if ((uVar9 & 0xfffffffffffffff0) != 0) {
        return 0xc000000d;
      }
      if ((uVar9 & 1) != 0) {
        if (uVar10 < 2) goto LAB_1c00035ae;
        *(byte *)(lVar12 + 4) = *(byte *)(lVar12 + 4) & 0xfd;
      }
      if ((uVar9 & 2) != 0) {
        if (((uVar10 & 0xfffffffa) == 0) && (uVar10 != 4)) goto LAB_1c00035ae;
        *(byte *)(lVar12 + 5) = *(byte *)(lVar12 + 5) & 0xfe;
      }
      if ((uVar9 & 8) != 0) {
        *(byte *)(lVar12 + 4) = *(byte *)(lVar12 + 4) & 0xf7;
      }
    }
    else if (uVar10 != 0x21) goto LAB_1c00035ae;
    uVar9 = 0;
  }
  else {
    uVar10 = 3;
    if (iVar8 == 3) {
      pbVar14 = *(byte **)(param_1 + 8);
      if ((*pbVar14 & 0x3f) == 0) {
        return 0x103;
      }
      if ((*pbVar14 & 0x3f) != 1) {
        return 0xc0000001;
      }
      if (*(char *)(*(longlong *)(param_1 + 6) + 7) == '\x05') {
        uVar9 = (ulonglong)(-(uint)(pbVar14[1] != 0) & 0xc0000001);
      }
      else {
        uVar9 = 0;
      }
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      if (((*(uint *)(*(longlong *)(lVar12 + 0x10) + 0x98) & 1) != 0) &&
         (lVar5 = *(longlong *)(param_1 + 6), *(int *)(lVar12 + 0xbc) == 1)) {
        local_res8[0] = 8;
        iVar8 = AccelpSiovGetOperationType(*(longlong *)(param_1 + 2),lVar5,local_res8);
        if ((-1 < iVar8) && ((local_res8[0] != 8 && (pbVar14 != (byte *)0x0)))) {
          bVar7 = *pbVar14 & 0x3f;
          if (bVar7 == 1) {
            uVar10 = *(uint *)(lVar5 + 0x20);
          }
          else {
            if ((bVar7 != 3) && (bVar7 != 4)) goto LAB_1c0003582;
            uVar10 = *(uint *)(pbVar14 + 4);
          }
          LOCK();
          plVar1 = (longlong *)(lVar12 + 0x248 + (longlong)local_res8[0] * 0x18);
          *plVar1 = *plVar1 + (ulonglong)uVar10;
          UNLOCK();
        }
      }
      goto LAB_1c0003582;
    }
    if (iVar8 != 5) {
      bVar7 = (byte)uVar9;
      if (iVar8 == 6) {
        puVar13 = *(uint **)(param_1 + 6);
        uVar3 = *(undefined8 *)(param_1 + 0x10);
        uVar4 = *(undefined8 *)(param_1 + 0xe);
        uVar11 = *(undefined8 *)(param_1 + 0xc);
        DsaBuildDescriptorCommon
                  (4,puVar13,*(undefined8 *)(param_1 + 8),(byte)((uint)param_1[4] >> 0x1f),
                   param_1[4] & 0xfffff,bVar7 >> 7,(byte)(uVar9 >> 10) & 1);
        *(undefined8 *)(puVar13 + 6) = uVar11;
        uVar10 = 4;
        puVar13[8] = (uint)uVar4;
        *(undefined8 *)(puVar13 + 4) = uVar3;
      }
      else if (iVar8 == 7) {
        puVar13 = *(uint **)(param_1 + 6);
        uVar3 = *(undefined8 *)(param_1 + 0x10);
        uVar4 = *(undefined8 *)(param_1 + 0xe);
        uVar11 = *(undefined8 *)(param_1 + 0xc);
        DsaBuildDescriptorCommon
                  (3,puVar13,*(undefined8 *)(param_1 + 8),(byte)((uint)param_1[4] >> 0x1f),
                   param_1[4] & 0xfffff,bVar7 >> 7,(byte)(uVar9 >> 10) & 1);
        *(undefined8 *)(puVar13 + 4) = uVar11;
        *(undefined8 *)(puVar13 + 6) = uVar4;
        puVar13[8] = (uint)uVar3;
      }
      else if (iVar8 == 8) {
        puVar13 = *(uint **)(param_1 + 6);
        uVar10 = 5;
        uVar2 = param_1[4];
        uVar3 = *(undefined8 *)(param_1 + 0x10);
        uVar4 = *(undefined8 *)(param_1 + 0xe);
        uVar11 = *(undefined8 *)(param_1 + 0xc);
        uVar6 = puVar13[1];
        *(undefined8 *)(puVar13 + 2) = *(undefined8 *)(param_1 + 8);
        *(undefined1 *)((longlong)puVar13 + 7) = 5;
        *(byte *)(puVar13 + 1) = (byte)uVar6 | 0xc;
        if ((char)bVar7 < '\0') {
          *(byte *)(puVar13 + 1) = (byte)uVar6 | 0xe;
        }
        *(undefined8 *)(puVar13 + 4) = uVar11;
        *(undefined8 *)(puVar13 + 6) = uVar4;
        puVar13[8] = (uint)uVar3;
        *puVar13 = ((*puVar13 ^ uVar2) & 0xfffff ^ *puVar13 ^ uVar2) & 0x7fffffff ^ uVar2;
        *(undefined1 *)(puVar13 + 10) = 1;
      }
      else if (iVar8 == 9) {
        puVar13 = *(uint **)(param_1 + 6);
        uVar3 = *(undefined8 *)(param_1 + 8);
        uVar10 = param_1[4];
        *(byte *)(puVar13 + 1) = (byte)puVar13[1] | 0xc;
        *(undefined8 *)(puVar13 + 2) = uVar3;
        *(undefined1 *)((longlong)puVar13 + 7) = 0;
        *puVar13 = *puVar13 & 0x7ff00000 ^ uVar10 & 0x800fffff;
        uVar10 = 0;
      }
      else {
        if (iVar8 != 10) goto LAB_1c00035ae;
        if (*(uint *)(*(longlong *)(param_1 + 0xc) + 0x20) < 2) {
          return 0xc0000001;
        }
        if (*(longlong *)(param_1 + 0x10) == 1) {
          param_1[0x10] = 2;
          param_1[0x11] = 0;
          uVar9 = AccelBuildDescriptorNop
                            ((longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xc) + 0x28) + 0x28)
                             ,0);
          if ((int)uVar9 < 0) {
            return uVar9;
          }
        }
        puVar13 = *(uint **)(param_1 + 6);
        uVar10 = 1;
        uVar3 = *(undefined8 *)(param_1 + 8);
        uVar2 = param_1[4];
        uVar4 = *(undefined8 *)(param_1 + 0x10);
        uVar11 = *(undefined8 *)(param_1 + 0xe);
        *(byte *)(puVar13 + 1) = (byte)puVar13[1] | 0xc;
        *(undefined8 *)(puVar13 + 2) = uVar3;
        *(undefined1 *)((longlong)puVar13 + 7) = 1;
        *(undefined8 *)(puVar13 + 4) = uVar11;
        *puVar13 = *puVar13 & 0x7ff00000 ^ uVar2 & 0x800fffff;
        puVar13[8] = (uint)uVar4;
      }
      goto LAB_1c0003587;
    }
    if (((*(byte *)(lVar12 + 0xd8) & 1) != 0) && ((uint)param_1[0xc] <= *(uint *)(lVar12 + 0xe0))) {
      *param_2 = param_1[0xc];
      if (param_1[0xc] == 1) {
        *param_2 = 2;
      }
      goto LAB_1c0003582;
    }
LAB_1c00035ae:
    uVar9 = 0xc00000bb;
  }
  return uVar9;
}



===== AccelpSiovGetOperationType @ 1c0003614 =====

undefined4 AccelpSiovGetOperationType(longlong param_1,longlong param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == (undefined4 *)0x0)) {
    return 0xc000000d;
  }
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x10) + 0xbc);
  if (iVar2 == 1) {
    cVar1 = *(char *)(param_2 + 7);
    if (cVar1 == '\0') {
LAB_1c00036af:
      *param_3 = 1;
      return 0;
    }
    if (cVar1 == '\x01') {
      *param_3 = 2;
      return 0;
    }
    if (cVar1 == '\x03') {
LAB_1c000366d:
      *param_3 = 4;
      return 0;
    }
    if (cVar1 == '\x04') {
      *param_3 = 3;
      return 0;
    }
  }
  else if (iVar2 == 2) {
    cVar1 = *(char *)(param_2 + 7);
    if (cVar1 == '\0') goto LAB_1c00036af;
    if (cVar1 == '\x03') goto LAB_1c000366d;
    if (cVar1 == 'B') {
      *param_3 = 7;
      return 0;
    }
    if (cVar1 == 'C') {
      *param_3 = 6;
      return 0;
    }
  }
  return 0xc0000001;
}



===== AccelpSiovIaaOperationHandler @ 1c00036c4 =====

ulonglong AccelpSiovIaaOperationHandler(int *param_1,undefined8 *param_2)

{
  byte *pbVar1;
  longlong lVar2;
  uint *puVar3;
  int iVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  
  iVar4 = *param_1;
  iVar7 = 0x57;
  uVar5 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_1 + 2) + 0x10) + 0xc0);
  if (iVar4 == 0) {
    *(undefined4 *)param_2 = 0x40;
    *(undefined4 *)((longlong)param_2 + 4) = 0x40;
    *(undefined4 *)(param_2 + 1) = 0x40;
LAB_1c00038f0:
    uVar5 = *(ulonglong *)(param_1 + 10);
    lVar2 = *(longlong *)(param_1 + 6);
    if (((iVar7 == 0) || (iVar7 == 0x42)) || (iVar7 == 0x43)) {
      if ((uVar5 & 0xfffffffffffffff0) != 0) {
        return 0xc000000d;
      }
      if ((uVar5 & 1) != 0) {
        if (iVar7 == 0) goto LAB_1c000390d;
        pbVar1 = (byte *)(lVar2 + 4);
        *pbVar1 = *pbVar1 & 0xfd;
      }
      if ((uVar5 & 2) != 0) {
        if (iVar7 == 0) goto LAB_1c000390d;
        pbVar1 = (byte *)(lVar2 + 5);
        *pbVar1 = *pbVar1 & 0xfe;
      }
    }
    else if (iVar7 != 0x57) goto LAB_1c000390d;
    uVar5 = 0;
  }
  else {
    if (iVar4 == 3) {
      iVar4 = IaaGetStatusFromCompletionRecord(*(byte **)(param_1 + 8));
      if (iVar4 < 0) {
        return CONCAT44(extraout_var_00,iVar4);
      }
      if (iVar4 == 0x103) {
        return CONCAT44(extraout_var_00,iVar4);
      }
      goto LAB_1c00038f0;
    }
    if (iVar4 == 4) {
      iVar4 = AccelpSiovIaaQueryCompletionInformation
                        (*(longlong *)(param_1 + 6),*(byte **)(param_1 + 8),param_1[0xc],
                         ((undefined4 *)*param_2)[6],(undefined4 *)*param_2);
      uVar5 = CONCAT44(extraout_var,iVar4);
LAB_1c00038c7:
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      goto LAB_1c00038f0;
    }
    if (iVar4 == 9) {
      puVar3 = *(uint **)(param_1 + 6);
      uVar8 = *(undefined8 *)(param_1 + 8);
      uVar9 = param_1[4];
      *(byte *)(puVar3 + 1) = (byte)puVar3[1] | 0xc;
      *(undefined8 *)(puVar3 + 2) = uVar8;
      *(undefined1 *)((longlong)puVar3 + 7) = 0;
      *puVar3 = *puVar3 & 0x7ff00000 ^ uVar9 & 0x800fffff;
      iVar7 = 0;
      goto LAB_1c00038f0;
    }
    if ((iVar4 == 0xb) || (iVar4 == 0xc)) {
      uVar5 = AccelpSiovCompressionDecompression
                        (param_1,(byte)((uint)param_1[4] >> 0x1f),param_1[4] & 0xfffff,
                         (byte)uVar5 >> 7,(byte)(uVar5 >> 10) & 1);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      iVar7 = 0x43 - (uint)(*param_1 != 0xb);
      goto LAB_1c00038f0;
    }
    if (iVar4 == 0xd) {
      uVar9 = *(uint *)(param_2 + 1);
      if (param_1[0xf] == 6) {
        uVar6 = 0x65f;
      }
      else {
        if (param_1[0xf] != 7) {
          return 0xc000000d;
        }
        uVar6 = 0x153f;
      }
      if ((param_1[0x10] != 1) || (param_1[0x11] != 1)) {
        uVar6 = uVar6 + 0x44c0;
      }
      *(uint *)(param_2 + 1) = uVar6;
      if (uVar9 < uVar6) {
        return 0xc0000023;
      }
      if ((uint *)*param_2 == (uint *)0x0) {
        return 0xc000000d;
      }
      uVar5 = AccelpSiovSetCompressionWorkspace
                        ((uint *)*param_2,uVar6,*(undefined8 **)(param_1 + 0xc),param_1[0xe],
                         param_1[0xf],param_1[0x10],param_1[0x11]);
      goto LAB_1c00038c7;
    }
    if (iVar4 == 0xe) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
      if (lVar2 == 0) {
        return 0xc000000d;
      }
      puVar3 = *(uint **)(param_1 + 6);
      uVar9 = param_1[0xe];
      uVar8 = *(undefined8 *)(param_1 + 0xc);
      DsaBuildDescriptorCommon
                (0x43,puVar3,*(undefined8 *)(param_1 + 8),(byte)((uint)param_1[4] >> 0x1f),
                 param_1[4] & 0xfffff,(byte)uVar5 >> 7,(byte)(uVar5 >> 10) & 1);
      *(ushort *)((longlong)puVar3 + 0x26) = *(ushort *)((longlong)puVar3 + 0x26) | 0x11;
      *(longlong *)(puVar3 + 6) = lVar2 + 0x3548;
      *(undefined8 *)(puVar3 + 4) = uVar8;
      puVar3[8] = uVar9;
      puVar3[0xc] = 0x500;
      goto LAB_1c00038f0;
    }
LAB_1c000390d:
    uVar5 = 0xc00000bb;
  }
  return uVar5;
}



===== AccelpSiovIaaQueryCompletionInformation @ 1c0003960 =====

int AccelpSiovIaaQueryCompletionInformation
              (longlong param_1,byte *param_2,int param_3,uint param_4,undefined4 *param_5)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  uint uVar8;
  
  if (param_3 == 1) {
    iVar4 = IaaGetStatusFromCompletionRecord(param_2);
    if ((-1 < iVar4) || (iVar4 == -0x3fffffdd)) {
      uVar8 = 1;
      do {
        if (uVar8 != 1) {
          AccelpSiovIaaQueryCompletionInformation(param_1,param_2,uVar8,param_4,param_5);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < 7);
      iVar4 = 0;
    }
    return iVar4;
  }
  if (param_3 == 2) {
    if (*(char *)(param_1 + 7) == 'B') {
      iVar4 = IaaGetStatusFromCompletionRecord(param_2);
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffffdd)) {
        return iVar4;
      }
      *param_5 = *(undefined4 *)(param_2 + 4);
      return 0;
    }
  }
  else if (param_3 == 3) {
    iVar4 = 0;
    if ((param_5[6] == 0) || (*(longlong *)(param_5 + 4) != 0)) {
      if (param_4 < 0x400) {
        iVar4 = -0x3fffffdd;
      }
      else {
        if (*(char *)(param_1 + 7) != 'C') {
          return -0x3fffff45;
        }
        lVar7 = 8;
        puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x120);
        puVar6 = *(undefined8 **)(param_5 + 4);
        do {
          uVar3 = puVar5[1];
          *puVar6 = *puVar5;
          puVar6[1] = uVar3;
          uVar3 = puVar5[3];
          puVar6[2] = puVar5[2];
          puVar6[3] = uVar3;
          uVar3 = puVar5[5];
          puVar6[4] = puVar5[4];
          puVar6[5] = uVar3;
          uVar3 = puVar5[7];
          puVar6[6] = puVar5[6];
          puVar6[7] = uVar3;
          uVar3 = puVar5[9];
          puVar6[8] = puVar5[8];
          puVar6[9] = uVar3;
          uVar3 = puVar5[0xb];
          puVar6[10] = puVar5[10];
          puVar6[0xb] = uVar3;
          uVar3 = puVar5[0xd];
          puVar6[0xc] = puVar5[0xc];
          puVar6[0xd] = uVar3;
          puVar1 = puVar5 + 0xe;
          uVar3 = puVar5[0xf];
          puVar5 = puVar5 + 0x10;
          puVar6[0xe] = *puVar1;
          puVar6[0xf] = uVar3;
          lVar7 = lVar7 + -1;
          puVar6 = puVar6 + 0x10;
        } while (lVar7 != 0);
      }
      param_5[6] = 0x400;
      return iVar4;
    }
  }
  else if (param_3 == 4) {
    bVar2 = *(byte *)(param_1 + 7);
    if ((((byte)(bVar2 - 4) < 0x40) || (bVar2 == 1)) || (0x44 < bVar2)) {
      iVar4 = IaaGetStatusFromCompletionRecord(param_2);
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffffdd)) {
        return iVar4;
      }
      param_5[1] = *(undefined4 *)(param_2 + 0x20);
      return iVar4;
    }
  }
  else if (param_3 == 5) {
    if ((*(byte *)(param_1 + 7) & 0xfd) != 0) {
      iVar4 = IaaGetStatusFromCompletionRecord(param_2);
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffffdd)) {
        return iVar4;
      }
      *(byte *)(param_5 + 2) = param_2[0x1c];
      return iVar4;
    }
  }
  else {
    if (param_3 != 6) {
      return -0x3fffff45;
    }
    if (((*(byte *)(param_1 + 7) & 0xfc) != 0) || (*(byte *)(param_1 + 7) == 1)) {
      iVar4 = IaaGetStatusFromCompletionRecord(param_2);
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffffdd)) {
        return iVar4;
      }
      param_5[3] = *(undefined4 *)(param_2 + 0x18);
      return iVar4;
    }
  }
  return -0x3ffffff3;
}



===== AccelpSiovInternalOperationHandler @ 1c0003ba4 =====

/* WARNING: Removing unreachable block (ram,0x0001c0003c1d) */

undefined4 AccelpSiovInternalOperationHandler(int *param_1,uint *param_2)

{
  int *piVar1;
  longlong *plVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  int iVar11;
  longlong lVar12;
  bool bVar13;
  int local_res18 [4];
  
  lVar10 = 0;
  if (*(longlong *)(param_1 + 2) != 0) {
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 2) + 0x10);
  }
  if (*param_1 == 1) {
    if (((*(int *)(lVar10 + 0xbc) == 1) || (*(int *)(lVar10 + 0xbc) == 2)) &&
       ((**(byte **)(param_1 + 8) & 0x3f) != 0)) {
      uVar4 = 0xc000000d;
    }
    else {
      uVar8 = 0;
      iVar11 = 1;
      do {
        bVar13 = (bool)enqcmds((int)*(undefined8 *)(param_1 + 0xc),
                               **(undefined1 (**) [64])(param_1 + 6));
        if (!bVar13) {
          if ((*(uint *)(*(longlong *)(lVar10 + 0x10) + 0x98) & 1) == 0) {
            return 0;
          }
          lVar10 = *(longlong *)(param_1 + 6);
          lVar12 = *(longlong *)(*(longlong *)(param_1 + 2) + 0x10);
          if (*(int *)(lVar12 + 0xbc) != 1) {
            return 0;
          }
          local_res18[0] = 8;
          iVar5 = AccelpSiovGetOperationType(*(longlong *)(param_1 + 2),lVar10,local_res18);
          if (iVar5 < 0) {
            return 0;
          }
          lVar7 = (longlong)local_res18[0];
          if (local_res18[0] == 8) {
            return 0;
          }
          if ((local_res18[0] - iVar11 == 0) ||
             (iVar5 = (local_res18[0] - iVar11) - iVar11, iVar5 == 0)) {
            LOCK();
            piVar1 = (int *)(lVar12 + 0x238 + lVar7 * 0x18);
            *piVar1 = *piVar1 + iVar11;
            UNLOCK();
            return 0;
          }
          iVar5 = iVar5 - iVar11;
          if (((iVar5 == 0) || (iVar5 == iVar11)) || (iVar5 - iVar11 == iVar11)) {
            LOCK();
            piVar1 = (int *)(lVar12 + 0x238 + lVar7 * 0x18);
            *piVar1 = *piVar1 + iVar11;
            UNLOCK();
            LOCK();
            plVar2 = (longlong *)(lVar12 + 0x240 + lVar7 * 0x18);
            *plVar2 = *plVar2 + (ulonglong)*(uint *)(lVar10 + 0x20);
            UNLOCK();
            return 0;
          }
          return 0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < 3);
      uVar4 = 0xc0ef0001;
    }
  }
  else if (*param_1 == 2) {
    if (AccelUMWaitSupported == -1) {
      lVar12 = cpuid_Extended_Feature_Enumeration_info(7);
      if ((*(uint *)(lVar12 + 0xc) & 0x20) == 0) {
        AccelUMWaitSupported = 0;
      }
      else {
        AccelUMWaitSupported = 1;
      }
    }
    pbVar3 = *(byte **)(param_1 + 8);
    iVar11 = *(int *)(lVar10 + 0xbc);
    if ((char)AccelUMWaitSupported == '\0') {
      while (((iVar11 != 1 && (iVar11 != 2)) || ((*pbVar3 & 0x3f) == 0))) {
        KeStallExecutionProcessor(0x14);
      }
    }
    else {
      bVar13 = true;
      uVar6 = rdtsc();
      uVar9 = uVar6 + 5000000;
      while (((iVar11 != 1 && (iVar11 != 2)) ||
             (uVar6 = CONCAT71((int7)(uVar6 >> 8),*pbVar3) & 0xffffffffffffff3f, (char)uVar6 == '\0'
             ))) {
        if (!bVar13) {
          uVar9 = rdtsc();
          uVar9 = (CONCAT44((int)(uVar6 >> 0x20),(int)uVar9) | uVar9 & 0xffffffff00000000) + 5000000
          ;
        }
        uVar6 = uVar9;
        umonitor(pbVar3);
        if (((iVar11 == 1) || (iVar11 == 2)) && ((*pbVar3 & 0x3f) != 0)) break;
        bVar13 = (uVar6 >> 0x1f & 1) != 0;
        umwait(1,(int)(uVar6 >> 0x20),(int)uVar6);
        uVar9 = uVar6;
      }
    }
    uVar4 = 0;
  }
  else if (*(int *)(lVar10 + 0xbc) == 1) {
    uVar6 = AccelpSiovDsaOperationHandler(param_1,param_2);
    uVar4 = (undefined4)uVar6;
  }
  else {
    if (*(int *)(lVar10 + 0xbc) != 2) {
      return 0xc00000bb;
    }
    uVar6 = AccelpSiovIaaOperationHandler(param_1,(undefined8 *)param_2);
    uVar4 = (undefined4)uVar6;
  }
  return uVar4;
}



===== AccelpSiovSetCompressionWorkspace @ 1c0003e04 =====

undefined8
AccelpSiovSetCompressionWorkspace
          (uint *param_1,uint param_2,undefined8 *param_3,uint param_4,uint param_5,uint param_6,
          uint param_7)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint *puVar4;
  longlong lVar5;
  
  memset(param_1,0,(ulonglong)param_2);
  param_1[1] = param_5;
  *param_1 = param_2;
  param_1[2] = param_6;
  param_1[3] = param_7;
  if ((param_6 == 1) && (param_7 == 1)) {
    lVar3 = 0x20;
  }
  else {
    lVar3 = 0x44e0;
    *(uint **)(param_1 + 6) = param_1 + 8;
    if (param_3 != (undefined8 *)0x0) {
      if (param_4 < 0x400) {
        return 0xc000000d;
      }
      lVar5 = 8;
      puVar4 = param_1 + 0xc5a;
      do {
        uVar2 = param_3[1];
        *(undefined8 *)puVar4 = *param_3;
        *(undefined8 *)(puVar4 + 2) = uVar2;
        uVar2 = param_3[3];
        *(undefined8 *)(puVar4 + 4) = param_3[2];
        *(undefined8 *)(puVar4 + 6) = uVar2;
        uVar2 = param_3[5];
        *(undefined8 *)(puVar4 + 8) = param_3[4];
        *(undefined8 *)(puVar4 + 10) = uVar2;
        uVar2 = param_3[7];
        *(undefined8 *)(puVar4 + 0xc) = param_3[6];
        *(undefined8 *)(puVar4 + 0xe) = uVar2;
        uVar2 = param_3[9];
        *(undefined8 *)(puVar4 + 0x10) = param_3[8];
        *(undefined8 *)(puVar4 + 0x12) = uVar2;
        uVar2 = param_3[0xb];
        *(undefined8 *)(puVar4 + 0x14) = param_3[10];
        *(undefined8 *)(puVar4 + 0x16) = uVar2;
        uVar2 = param_3[0xd];
        *(undefined8 *)(puVar4 + 0x18) = param_3[0xc];
        *(undefined8 *)(puVar4 + 0x1a) = uVar2;
        puVar1 = param_3 + 0xe;
        uVar2 = param_3[0xf];
        param_3 = param_3 + 0x10;
        *(undefined8 *)(puVar4 + 0x1c) = *puVar1;
        *(undefined8 *)(puVar4 + 0x1e) = uVar2;
        lVar5 = lVar5 + -1;
        puVar4 = puVar4 + 0x20;
      } while (lVar5 != 0);
    }
  }
  *(ulonglong *)(param_1 + 4) = (longlong)param_1 + lVar3 + 0x1f & 0xffffffffffffffe0;
  return 0;
}



===== DsaBuildDescriptorCommon @ 1c0003f00 =====

void DsaBuildDescriptorCommon
               (undefined1 param_1,uint *param_2,undefined8 param_3,byte param_4,uint param_5,
               char param_6,char param_7)

{
  uint uVar1;
  
  *(undefined1 *)((longlong)param_2 + 7) = param_1;
  *(undefined8 *)(param_2 + 2) = param_3;
  uVar1 = param_2[1];
  *(byte *)(param_2 + 1) = (byte)uVar1 | 0xc;
  if (param_6 != '\0') {
    *(byte *)(param_2 + 1) = (byte)uVar1 | 0xe;
  }
  if (param_7 != '\0') {
    *(byte *)((longlong)param_2 + 5) = *(byte *)((longlong)param_2 + 5) | 1;
  }
  *param_2 = (uint)param_4 << 0x1f | ((*param_2 ^ param_5) & 0xfffff ^ *param_2) & 0x7fffffff;
  return;
}



===== IaaBuildDescriptorFixedCompress @ 1c0003f54 =====

void IaaBuildDescriptorFixedCompress
               (uint *param_1,undefined8 param_2,void *param_3,undefined8 param_4,uint param_5,
               undefined8 param_6,uint param_7,byte param_8,uint param_9,char param_10,char param_11
               )

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong lVar8;
  
  DsaBuildDescriptorCommon(0x43,param_1,param_2,param_8,param_9,param_10,param_11);
  *(undefined8 *)(param_1 + 4) = param_4;
  *(void **)(param_1 + 10) = param_3;
  *(byte *)((longlong)param_1 + 6) = *(byte *)((longlong)param_1 + 6) & 0xfd | 1;
  param_1[0xd] = 0x620;
  *(ushort *)((longlong)param_1 + 0x26) = *(ushort *)((longlong)param_1 + 0x26) & 0xfff7 | 6;
  param_1[8] = param_5;
  *(undefined8 *)(param_1 + 6) = param_6;
  param_1[0xc] = param_7;
  memset(param_3,0,0x620);
  puVar2 = (undefined8 *)&FixedLiteralLengthCodes;
  puVar3 = (undefined8 *)((longlong)param_3 + 0x120);
  lVar8 = 8;
  do {
    lVar7 = lVar8;
    puVar6 = puVar3;
    puVar5 = puVar2;
    uVar1 = puVar5[1];
    *puVar6 = *puVar5;
    puVar6[1] = uVar1;
    uVar1 = puVar5[3];
    puVar6[2] = puVar5[2];
    puVar6[3] = uVar1;
    uVar1 = puVar5[5];
    puVar6[4] = puVar5[4];
    puVar6[5] = uVar1;
    uVar1 = puVar5[7];
    puVar6[6] = puVar5[6];
    puVar6[7] = uVar1;
    uVar1 = puVar5[9];
    puVar6[8] = puVar5[8];
    puVar6[9] = uVar1;
    uVar1 = puVar5[0xb];
    puVar6[10] = puVar5[10];
    puVar6[0xb] = uVar1;
    uVar1 = puVar5[0xd];
    puVar6[0xc] = puVar5[0xc];
    puVar6[0xd] = uVar1;
    uVar1 = puVar5[0xf];
    puVar6[0xe] = puVar5[0xe];
    puVar6[0xf] = uVar1;
    lVar8 = lVar7 + -1;
    puVar2 = puVar5 + 0x10;
    puVar3 = puVar6 + 0x10;
  } while (lVar8 != 0);
  uVar1 = puVar5[0x11];
  puVar6[0x10] = puVar5[0x10];
  puVar6[0x11] = uVar1;
  uVar1 = puVar5[0x13];
  puVar6[0x12] = puVar5[0x12];
  puVar6[0x13] = uVar1;
  uVar1 = puVar5[0x15];
  puVar6[0x14] = puVar5[0x14];
  puVar6[0x15] = uVar1;
  uVar1 = puVar5[0x17];
  puVar6[0x16] = puVar5[0x16];
  puVar6[0x17] = uVar1;
  uVar1 = puVar5[0x19];
  puVar6[0x18] = puVar5[0x18];
  puVar6[0x19] = uVar1;
  uVar1 = puVar5[0x1b];
  puVar6[0x1a] = puVar5[0x1a];
  puVar6[0x1b] = uVar1;
  uVar1 = puVar5[0x1d];
  puVar6[0x1c] = puVar5[0x1c];
  puVar6[0x1d] = uVar1;
  puVar6[0x1e] = puVar5[0x1e];
  iVar4 = (int)lVar7 + 2;
  *(undefined8 *)((longlong)param_3 + 0x5a0) = 0x2800100028000;
  *(undefined8 *)((longlong)param_3 + 0x5a8) = 0x2800300028002;
  *(undefined8 *)((longlong)param_3 + 0x5b0) = 0x2800500028004;
  *(undefined8 *)((longlong)param_3 + 0x5b8) = 0x2800700028006;
  *(undefined8 *)((longlong)param_3 + 0x5c0) = 0x2800900028008;
  *(undefined8 *)((longlong)param_3 + 0x5c8) = 0x2800b0002800a;
  *(undefined8 *)((longlong)param_3 + 0x5d0) = 0x2800d0002800c;
  *(undefined8 *)((longlong)param_3 + 0x5d8) = 0x2800f0002800e;
  *(undefined8 *)((longlong)param_3 + 0x5e0) = 0x2801100028010;
  *(undefined8 *)((longlong)param_3 + 0x5e8) = 0x2801300028012;
  *(undefined8 *)((longlong)param_3 + 0x5f0) = 0x2801500028014;
  *(undefined8 *)((longlong)param_3 + 0x5f8) = 0x2801700028016;
  *(undefined8 *)((longlong)param_3 + 0x600) = 0x2801900028018;
  *(undefined8 *)((longlong)param_3 + 0x608) = 0x2801b0002801a;
  *(undefined8 *)((longlong)param_3 + 0x610) = 0x2801d0002801c;
  *(char *)((longlong)param_3 + 0x20) = (char)iVar4;
  *(short *)((longlong)param_3 + 0x1c) = (short)iVar4;
  return;
}



===== IaaBuildDescriptorHuffmanCompress @ 1c0004118 =====

void IaaBuildDescriptorHuffmanCompress
               (uint *param_1,undefined8 param_2,void *param_3,undefined8 *param_4,
               undefined8 param_5,uint param_6,undefined8 param_7,uint param_8,byte param_9,
               byte param_10,uint param_11,char param_12,char param_13)

{
  undefined8 *puVar1;
  byte bVar2;
  ushort uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint *puVar7;
  
  puVar7 = param_1;
  DsaBuildDescriptorCommon(0x43,param_1,param_2,param_10,param_11,param_12,param_13);
  bVar2 = *(byte *)((longlong)param_1 + 6);
  *(void **)(puVar7 + 10) = param_3;
  puVar7[0xd] = 0x620;
  *(byte *)((longlong)param_1 + 6) = bVar2 & 0xfd | 1;
  uVar3 = *(ushort *)((longlong)param_1 + 0x26);
  *(undefined8 *)(puVar7 + 4) = param_5;
  puVar7[8] = param_6;
  *(undefined8 *)(puVar7 + 6) = param_7;
  *(ushort *)((longlong)puVar7 + 0x26) = (ushort)(param_9 & 1) << 5 | uVar3 & 0xffdf | 0x12;
  puVar7[0xc] = param_8;
  memset(param_3,0,0x620);
  lVar5 = 8;
  puVar6 = (undefined8 *)((longlong)param_3 + 0x120);
  do {
    uVar4 = param_4[1];
    *puVar6 = *param_4;
    puVar6[1] = uVar4;
    uVar4 = param_4[3];
    puVar6[2] = param_4[2];
    puVar6[3] = uVar4;
    uVar4 = param_4[5];
    puVar6[4] = param_4[4];
    puVar6[5] = uVar4;
    uVar4 = param_4[7];
    puVar6[6] = param_4[6];
    puVar6[7] = uVar4;
    uVar4 = param_4[9];
    puVar6[8] = param_4[8];
    puVar6[9] = uVar4;
    uVar4 = param_4[0xb];
    puVar6[10] = param_4[10];
    puVar6[0xb] = uVar4;
    uVar4 = param_4[0xd];
    puVar6[0xc] = param_4[0xc];
    puVar6[0xd] = uVar4;
    puVar1 = param_4 + 0xe;
    uVar4 = param_4[0xf];
    param_4 = param_4 + 0x10;
    puVar6[0xe] = *puVar1;
    puVar6[0xf] = uVar4;
    lVar5 = lVar5 + -1;
    puVar6 = puVar6 + 0x10;
  } while (lVar5 != 0);
  return;
}



===== IaaCodeValuesSort @ 1c0004250 =====

ulonglong IaaCodeValuesSort(ushort *param_1,ushort *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(*param_2 < *param_1);
}



===== IaaGetStatusFromCompletionRecord @ 1c0004274 =====

undefined4 IaaGetStatusFromCompletionRecord(byte *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  uVar1 = 0;
  bVar2 = *param_1 & 0x3f;
  if ((*param_1 & 0x3f) == 0) {
    uVar1 = 0x103;
  }
  else if (bVar2 != 1) {
    if (bVar2 == 10) {
      uVar1 = 0xc0000023;
      if (param_1[1] != 0x19) {
        uVar1 = 0xc0000001;
      }
    }
    else if (bVar2 == 0xb) {
      uVar1 = 0xc0000023;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}



===== IaapSetAecsDecompressionHuffmanTable @ 1c00042c8 =====

void IaapSetAecsDecompressionHuffmanTable
               (uint *param_1,void *param_2,ushort *param_3,longlong param_4,ushort *param_5)

{
  ushort *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint *puVar8;
  longlong lVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  ushort *puVar17;
  
  memset(param_2,0,0x1500);
  memset(param_5,0,0x178);
  uVar5 = 0;
  uVar15 = 0;
  lVar6 = param_4 - (longlong)param_1;
  puVar8 = param_1;
  do {
    *(ushort *)(lVar6 + (longlong)puVar8) = (ushort)*puVar8 & 0x7fff;
    uVar13 = *puVar8;
    *(char *)(lVar6 + 3 + (longlong)puVar8) = (char)uVar15;
    puVar8 = puVar8 + 1;
    uVar15 = uVar15 + 1;
    *(byte *)(lVar6 + -2 + (longlong)puVar8) = (byte)(uVar13 >> 0xf) & 0xf;
  } while (uVar15 < 0x100);
  lVar6 = 0x100;
  do {
    lVar9 = lVar6;
    uVar15 = *param_1 >> 0xf & 0xf;
    if (uVar15 != 0) {
      param_5[(ulonglong)(uVar15 - 1) + 0xf] = param_5[(ulonglong)(uVar15 - 1) + 0xf] + 1;
    }
    param_1 = param_1 + 1;
    lVar6 = lVar9 + -1;
  } while (lVar6 != 0);
  puVar17 = param_5 + 0x1e;
  uVar15 = 0;
  uVar16 = (ulonglong)((int)lVar9 + 1);
  do {
    memset(param_3,0,0x400);
    uVar13 = uVar5;
    if (puVar17[-0xf] != 0) {
      uVar14 = 0;
      pbVar10 = (byte *)(param_4 + 2);
      lVar6 = 0x100;
      do {
        if ((uint)*pbVar10 == uVar15 + 1) {
          uVar7 = (ulonglong)uVar14;
          uVar14 = uVar14 + 1;
          *(byte *)((longlong)param_3 + uVar7 * 4 + 3) = pbVar10[1];
          param_3[uVar7 * 2] = *(ushort *)(pbVar10 + -2);
          *(byte *)(param_3 + uVar7 * 2 + 1) = *pbVar10;
        }
        pbVar10 = pbVar10 + 4;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      qsort(param_3,(ulonglong)uVar14,4,IaaCodeValuesSort);
      *puVar17 = *param_3;
      puVar17[-0x1e] = (ushort)uVar5;
      if (uVar5 < uVar5 + uVar14) {
        puVar11 = (undefined1 *)((ulonglong)uVar5 + 0x78 + (longlong)param_5);
        uVar12 = uVar5;
        do {
          uVar13 = uVar12 + 1;
          *puVar11 = *(undefined1 *)((longlong)param_3 + (ulonglong)(uVar12 - uVar5) * 4 + 3);
          puVar11 = puVar11 + 1;
          uVar12 = uVar13;
        } while (uVar13 < uVar5 + uVar14);
      }
    }
    uVar5 = uVar13;
    uVar15 = uVar15 + 1;
    puVar17 = (ushort *)((longlong)puVar17 + uVar16);
  } while (uVar15 < 0xf);
  *(undefined8 *)((longlong)param_2 + 0x1e0) = 0;
  *(undefined8 *)((longlong)param_2 + 0x1e8) = 0;
  *(undefined4 *)((longlong)param_2 + 0x1f0) = 0;
  uVar2 = *param_5;
  *(uint *)((longlong)param_2 + 0x1e0) = uVar2 & 3;
  uVar5 = (param_5[1] & 7) << 2 | uVar2 & 3;
  *(uint *)((longlong)param_2 + 0x1e0) = uVar5;
  uVar5 = (param_5[2] & 0xf) << 5 | uVar5;
  *(uint *)((longlong)param_2 + 0x1e0) = uVar5;
  uVar5 = (param_5[3] & 0x1f) << 9 | uVar5;
  *(uint *)((longlong)param_2 + 0x1e0) = uVar5;
  uVar5 = (param_5[4] & 0x3f) << 0xe | uVar5;
  *(uint *)((longlong)param_2 + 0x1e0) = uVar5;
  *(uint *)((longlong)param_2 + 0x1e0) = (param_5[5] & 0x7f) << 0x14 | uVar5;
  *(char *)((longlong)param_2 + 0x1e4) = (char)param_5[6];
  uVar5 = ((uint)param_5[7] << 8 ^ *(uint *)((longlong)param_2 + 0x1e4)) & 0x1ff00 ^
          *(uint *)((longlong)param_2 + 0x1e4);
  *(uint *)((longlong)param_2 + 0x1e4) = uVar5;
  *(uint *)((longlong)param_2 + 0x1e4) = ((uint)param_5[8] << 0x11 ^ uVar5) & 0x7fe0000 ^ uVar5;
  uVar5 = ((uint)param_5[9] ^ *(uint *)((longlong)param_2 + 0x1e8)) & 0x7ff ^
          *(uint *)((longlong)param_2 + 0x1e8);
  *(uint *)((longlong)param_2 + 0x1e8) = uVar5;
  *(uint *)((longlong)param_2 + 0x1e8) = ((uint)param_5[10] << 0xb ^ uVar5) & 0x7ff800 ^ uVar5;
  uVar5 = ((uint)param_5[0xb] ^ *(uint *)((longlong)param_2 + 0x1ec)) & 0x1fff ^
          *(uint *)((longlong)param_2 + 0x1ec);
  *(uint *)((longlong)param_2 + 0x1ec) = uVar5;
  *(uint *)((longlong)param_2 + 0x1ec) = ((uint)param_5[0xc] << 0xd ^ uVar5) & 0x7ffe000 ^ uVar5;
  uVar5 = ((uint)param_5[0xd] ^ *(uint *)((longlong)param_2 + 0x1f0)) & 0x7fff ^
          *(uint *)((longlong)param_2 + 0x1f0);
  *(uint *)((longlong)param_2 + 0x1f0) = uVar5;
  *(uint *)((longlong)param_2 + 0x1f0) = (uint)param_5[0xe] << 0xf | uVar5 & 0x80007fff;
  *(undefined8 *)((longlong)param_2 + 500) = 0;
  *(undefined8 *)((longlong)param_2 + 0x1fc) = 0;
  *(undefined4 *)((longlong)param_2 + 0x204) = 0;
  uVar2 = param_5[0xf];
  *(uint *)((longlong)param_2 + 500) = uVar2 & 3;
  uVar5 = (param_5[0x10] & 7) << 2 | uVar2 & 3;
  *(uint *)((longlong)param_2 + 500) = uVar5;
  uVar5 = (param_5[0x11] & 0xf) << 5 | uVar5;
  *(uint *)((longlong)param_2 + 500) = uVar5;
  uVar5 = (param_5[0x12] & 0x1f) << 9 | uVar5;
  *(uint *)((longlong)param_2 + 500) = uVar5;
  uVar5 = (param_5[0x13] & 0x3f) << 0xe | uVar5;
  *(uint *)((longlong)param_2 + 500) = uVar5;
  *(uint *)((longlong)param_2 + 500) = (param_5[0x14] & 0x7f) << 0x14 | uVar5;
  *(char *)((longlong)param_2 + 0x1f8) = (char)param_5[0x15];
  uVar5 = ((uint)param_5[0x16] << 8 ^ *(uint *)((longlong)param_2 + 0x1f8)) & 0x1ff00 ^
          *(uint *)((longlong)param_2 + 0x1f8);
  *(uint *)((longlong)param_2 + 0x1f8) = uVar5;
  *(uint *)((longlong)param_2 + 0x1f8) = ((uint)param_5[0x17] << 0x11 ^ uVar5) & 0x7fe0000 ^ uVar5;
  uVar5 = ((uint)param_5[0x18] ^ *(uint *)((longlong)param_2 + 0x1fc)) & 0x7ff ^
          *(uint *)((longlong)param_2 + 0x1fc);
  *(uint *)((longlong)param_2 + 0x1fc) = uVar5;
  *(uint *)((longlong)param_2 + 0x1fc) = ((uint)param_5[0x19] << 0xb ^ uVar5) & 0x7ff800 ^ uVar5;
  uVar5 = ((uint)param_5[0x1a] ^ *(uint *)((longlong)param_2 + 0x200)) & 0x1fff ^
          *(uint *)((longlong)param_2 + 0x200);
  *(uint *)((longlong)param_2 + 0x200) = uVar5;
  *(uint *)((longlong)param_2 + 0x200) = ((uint)param_5[0x1b] << 0xd ^ uVar5) & 0x7ffe000 ^ uVar5;
  uVar5 = ((uint)param_5[0x1c] ^ *(uint *)((longlong)param_2 + 0x204)) & 0x7fff ^
          *(uint *)((longlong)param_2 + 0x204);
  *(uint *)((longlong)param_2 + 0x204) = uVar5;
  *(uint *)((longlong)param_2 + 0x204) = (uint)param_5[0x1d] << 0xf | uVar5 & 0x80007fff;
  *(undefined8 *)((longlong)param_2 + 0x208) = 0;
  *(undefined8 *)((longlong)param_2 + 0x210) = 0;
  *(undefined4 *)((longlong)param_2 + 0x218) = 0;
  uVar2 = param_5[0x1e];
  *(uint *)((longlong)param_2 + 0x208) = uVar2 & 3;
  uVar5 = (param_5[0x1f] & 7) << 2 | uVar2 & 3;
  *(uint *)((longlong)param_2 + 0x208) = uVar5;
  uVar5 = (param_5[0x20] & 0xf) << 5 | uVar5;
  *(uint *)((longlong)param_2 + 0x208) = uVar5;
  uVar5 = (param_5[0x21] & 0x1f) << 9 | uVar5;
  *(uint *)((longlong)param_2 + 0x208) = uVar5;
  uVar5 = (param_5[0x22] & 0x3f) << 0xe | uVar5;
  *(uint *)((longlong)param_2 + 0x208) = uVar5;
  *(uint *)((longlong)param_2 + 0x208) = (param_5[0x23] & 0x7f) << 0x14 | uVar5;
  *(char *)((longlong)param_2 + 0x20c) = (char)param_5[0x24];
  uVar5 = ((uint)param_5[0x25] << 8 ^ *(uint *)((longlong)param_2 + 0x20c)) & 0x1ff00 ^
          *(uint *)((longlong)param_2 + 0x20c);
  *(uint *)((longlong)param_2 + 0x20c) = uVar5;
  *(uint *)((longlong)param_2 + 0x20c) = ((uint)param_5[0x26] << 0x11 ^ uVar5) & 0x7fe0000 ^ uVar5;
  uVar5 = ((uint)param_5[0x27] ^ *(uint *)((longlong)param_2 + 0x210)) & 0x7ff ^
          *(uint *)((longlong)param_2 + 0x210);
  *(uint *)((longlong)param_2 + 0x210) = uVar5;
  *(uint *)((longlong)param_2 + 0x210) = ((uint)param_5[0x28] << 0xb ^ uVar5) & 0x7ff800 ^ uVar5;
  uVar5 = ((uint)param_5[0x29] ^ *(uint *)((longlong)param_2 + 0x214)) & 0x1fff ^
          *(uint *)((longlong)param_2 + 0x214);
  *(uint *)((longlong)param_2 + 0x214) = uVar5;
  *(uint *)((longlong)param_2 + 0x214) = ((uint)param_5[0x2a] << 0xd ^ uVar5) & 0x7ffe000 ^ uVar5;
  uVar5 = ((uint)param_5[0x2b] ^ *(uint *)((longlong)param_2 + 0x218)) & 0x7fff ^
          *(uint *)((longlong)param_2 + 0x218);
  *(uint *)((longlong)param_2 + 0x218) = uVar5;
  *(uint *)((longlong)param_2 + 0x218) = (uint)param_5[0x2c] << 0xf | uVar5 & 0x80007fff;
  param_5[0x2d] = 0xffff;
  param_5[0x2e] = 0xffff;
  param_5[0x2f] = 0xffff;
  param_5[0x30] = 0xffff;
  param_5[0x31] = 0xffff;
  param_5[0x32] = 0xffff;
  param_5[0x33] = 0xffff;
  param_5[0x34] = 0xffff;
  param_5[0x35] = 0xffff;
  param_5[0x36] = 0xffff;
  param_5[0x37] = 0xffff;
  param_5[0x38] = 0xffff;
  param_5[0x39] = 0xffff;
  param_5[0x3a] = 0xffff;
  param_5[0x3b] = 0xffff;
  *(undefined8 *)((longlong)param_2 + 0x21c) = 0;
  *(undefined8 *)((longlong)param_2 + 0x224) = 0;
  *(undefined4 *)((longlong)param_2 + 0x22c) = 0;
  uVar2 = param_5[0x2d];
  *(uint *)((longlong)param_2 + 0x21c) = uVar2 & 3;
  uVar5 = (param_5[0x2e] & 7) << 2 | uVar2 & 3;
  *(uint *)((longlong)param_2 + 0x21c) = uVar5;
  uVar5 = (param_5[0x2f] & 0xf) << 5 | uVar5;
  *(uint *)((longlong)param_2 + 0x21c) = uVar5;
  uVar5 = (param_5[0x30] & 0x1f) << 9 | uVar5;
  *(uint *)((longlong)param_2 + 0x21c) = uVar5;
  uVar5 = (param_5[0x31] & 0x3f) << 0xe | uVar5;
  *(uint *)((longlong)param_2 + 0x21c) = uVar5;
  *(uint *)((longlong)param_2 + 0x21c) = (param_5[0x32] & 0x7f) << 0x14 | uVar5;
  *(char *)((longlong)param_2 + 0x220) = (char)param_5[0x33];
  uVar5 = ((uint)param_5[0x34] << 8 ^ *(uint *)((longlong)param_2 + 0x220)) & 0x1ff00 ^
          *(uint *)((longlong)param_2 + 0x220);
  *(uint *)((longlong)param_2 + 0x220) = uVar5;
  *(uint *)((longlong)param_2 + 0x220) = ((uint)param_5[0x35] << 0x11 ^ uVar5) & 0x7fe0000 ^ uVar5;
  uVar5 = ((uint)param_5[0x36] ^ *(uint *)((longlong)param_2 + 0x224)) & 0x7ff ^
          *(uint *)((longlong)param_2 + 0x224);
  *(uint *)((longlong)param_2 + 0x224) = uVar5;
  *(uint *)((longlong)param_2 + 0x224) = ((uint)param_5[0x37] << 0xb ^ uVar5) & 0x7ff800 ^ uVar5;
  uVar5 = ((uint)param_5[0x38] ^ *(uint *)((longlong)param_2 + 0x228)) & 0x1fff ^
          *(uint *)((longlong)param_2 + 0x228);
  *(uint *)((longlong)param_2 + 0x228) = uVar5;
  *(uint *)((longlong)param_2 + 0x228) = ((uint)param_5[0x39] << 0xd ^ uVar5) & 0x7ffe000 ^ uVar5;
  uVar5 = ((uint)param_5[0x3a] ^ *(uint *)((longlong)param_2 + 0x22c)) & 0x7fff ^
          *(uint *)((longlong)param_2 + 0x22c);
  *(uint *)((longlong)param_2 + 0x22c) = uVar5;
  puVar17 = param_5 + 0x3c;
  *(uint *)((longlong)param_2 + 0x22c) = (uint)param_5[0x3b] << 0xf | uVar5 & 0x80007fff;
  puVar4 = (undefined8 *)((longlong)param_2 + 0x328);
  do {
    uVar3 = *(undefined8 *)(puVar17 + 4);
    *puVar4 = *(undefined8 *)puVar17;
    puVar4[1] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0xc);
    puVar4[2] = *(undefined8 *)(puVar17 + 8);
    puVar4[3] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0x14);
    puVar4[4] = *(undefined8 *)(puVar17 + 0x10);
    puVar4[5] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0x1c);
    puVar4[6] = *(undefined8 *)(puVar17 + 0x18);
    puVar4[7] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0x24);
    puVar4[8] = *(undefined8 *)(puVar17 + 0x20);
    puVar4[9] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0x2c);
    puVar4[10] = *(undefined8 *)(puVar17 + 0x28);
    puVar4[0xb] = uVar3;
    uVar3 = *(undefined8 *)(puVar17 + 0x34);
    puVar4[0xc] = *(undefined8 *)(puVar17 + 0x30);
    puVar4[0xd] = uVar3;
    puVar1 = puVar17 + 0x38;
    uVar3 = *(undefined8 *)(puVar17 + 0x3c);
    puVar17 = puVar17 + 0x40;
    puVar4[0xe] = *(undefined8 *)puVar1;
    puVar4[0xf] = uVar3;
    uVar16 = uVar16 - 1;
    puVar4 = puVar4 + 0x10;
  } while (uVar16 != 0);
  return;
}



===== AccelpLogAcceleratorAcquired @ 1c0004a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AccelpLogAcceleratorAcquired(longlong param_1,longlong param_2,byte param_3)

{
  undefined1 auStack_f8 [48];
  undefined4 local_c8;
  undefined1 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  uint local_ac;
  undefined1 local_a8 [32];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  undefined4 *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  if (5 < DAT_1c0009000) {
    local_88 = *(undefined8 *)(param_1 + 0x90);
    local_b8 = *(undefined4 *)(param_2 + 0xb8);
    local_78 = &local_b8;
    local_b4 = *(undefined4 *)(param_2 + 0xbc);
    local_68 = &local_b4;
    local_58 = local_40;
    local_48 = *(undefined8 *)(param_2 + 0x30);
    local_40[0] = (uint)*(ushort *)(param_2 + 0x28);
    local_b0 = *(undefined4 *)(param_1 + 0x10);
    local_38 = &local_b0;
    local_ac = (uint)param_3;
    local_28 = &local_ac;
    local_c0 = local_a8;
    local_c8 = 9;
    local_80 = 0x10;
    local_70 = 4;
    local_60 = 4;
    local_50 = 2;
    local_40[1] = 0;
    local_30 = 4;
    local_20 = 4;
    _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c0007b2e);
  }
  return;
}



===== AccelpLogAcceleratorClosed @ 1c0004b0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AccelpLogAcceleratorClosed(longlong param_1,longlong param_2)

{
  undefined1 auStack_e8 [48];
  undefined4 local_b8;
  undefined1 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  undefined1 local_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30 [2];
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  if (5 < DAT_1c0009000) {
    local_78 = *(undefined8 *)(param_1 + 0x90);
    local_a8 = *(undefined4 *)(param_2 + 0xb8);
    local_68 = &local_a8;
    local_a4 = *(undefined4 *)(param_2 + 0xbc);
    local_58 = &local_a4;
    local_48 = local_30;
    local_38 = *(undefined8 *)(param_2 + 0x30);
    local_30[0] = (uint)*(ushort *)(param_2 + 0x28);
    local_a0[0] = *(undefined4 *)(param_1 + 0x10);
    local_28 = local_a0;
    local_b0 = local_98;
    local_b8 = 8;
    local_70 = 0x10;
    local_60 = 4;
    local_50 = 4;
    local_40 = 2;
    local_30[1] = 0;
    local_20 = 4;
    _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c0007ac1);
  }
  return;
}



===== AccelpUnregisterProviderGUID @ 1c0004bf0 =====

void AccelpUnregisterProviderGUID(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_1c0009020;
  DAT_1c0009020 = 0;
  DAT_1c0009000 = 0;
  EtwUnregister(uVar1);
  return;
}



===== _tlgDefineProvider_annotation__TlgAccelLibProviderProv @ 1c0004c24 =====

void _tlgDefineProvider_annotation__TlgAccelLibProviderProv(void)

{
  return;
}



===== _guard_check_icall @ 1c0004c40 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004c58 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0004c7c =====

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



===== __cpu_features_init @ 1c0004cf0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0004d5a) */
/* WARNING: Removing unreachable block (ram,0x0001c0004d09) */
/* WARNING: Removing unreachable block (ram,0x0001c0004cfa) */

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



===== __security_check_cookie @ 1c0004dc0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004e00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004e30 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004e60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004ec0 =====

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



===== memset @ 1c00051c0 =====

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



===== __memset_repmovs @ 1c0005300 =====

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



===== __memset_query @ 1c0005380 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005400 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005540 =====

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



===== __memset_spec_plain @ 1c00055c0 =====

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



===== AccelAcquireResourcesAsync @ 1c000c010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AccelAcquireResourcesAsync(short *param_1)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  longlong *plVar4;
  void *_Dst;
  undefined8 uVar5;
  longlong lVar7;
  longlong lVar6;
  undefined8 uVar8;
  longlong *plVar9;
  size_t _Size;
  undefined1 *puVar10;
  short *psVar11;
  undefined1 auStack_168 [8];
  undefined1 auStack_160 [72];
  undefined8 local_118;
  undefined8 uStack_110;
  char *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 local_78 [32];
  char *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
                    /* 0xc010  2  AccelAcquireResourcesAsync */
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  local_118 = 0;
  uStack_110 = 0;
  plVar4 = (longlong *)0x0;
  uVar3 = AccelpVerifyIrqlLessThanOrEqual();
  puVar10 = auStack_168;
  if ((int)uVar3 < 0) {
LAB_1c000c40e:
    if (5 < DAT_1c0009000) {
      local_50 = 0x1b;
      *(uint *)(puVar10 + 0x40) = uVar3;
      local_58 = "AccelAcquireResourcesAsync";
      local_48 = puVar10 + 0x40;
      local_40 = 4;
      *(undefined1 **)(puVar10 + 0x38) = local_78;
      *(undefined4 *)(puVar10 + 0x30) = 4;
      *(undefined8 *)(puVar10 + -8) = 0x1c000c459;
      _tlgWriteEx_EtwWriteEx(4,&DAT_1c0007930);
    }
    if (plVar4 == (longlong *)0x0) goto LAB_1c000c49c;
  }
  else {
    if (param_1 == (short *)0x0) goto LAB_1c000c409;
    if ((*param_1 == 0) || ((ushort)param_1[1] < 0x58)) {
      uVar3 = 0xc0000059;
      puVar10 = auStack_168;
      goto LAB_1c000c40e;
    }
    if (*(longlong *)(param_1 + 0x28) != 0) {
LAB_1c000c409:
      uVar3 = 0xc000000d;
      puVar10 = auStack_168;
      goto LAB_1c000c40e;
    }
    puVar1 = (uint *)(param_1 + 0x1c);
    uVar3 = *puVar1;
    if (((((uVar3 >> 0x10 & 1) != 0) && ((uVar3 & 2) != 0)) || ((uVar3 & 0xffe8fffc) != 0)) ||
       ((*(longlong *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0xe) == 0)))) goto LAB_1c000c409;
    plVar4 = (longlong *)ExAllocatePool2(0x40,0x1b8,0x65636341);
    if (plVar4 == (longlong *)0x0) {
      uVar3 = 0xc0000017;
      puVar10 = auStack_168;
      goto LAB_1c000c40e;
    }
    ExInitializeRundownProtection(plVar4 + 0x36);
    uVar3 = *(uint *)(param_1 + 0xe);
    plVar9 = plVar4 + 0xb;
    plVar4[0xc] = (longlong)plVar9;
    *plVar9 = (longlong)plVar9;
    ExInitializeResourceLite(plVar4 + 0xe);
    plVar4[3] = *(longlong *)(param_1 + 8);
    plVar4[2] = *(longlong *)(param_1 + 4);
    *(uint *)(plVar4 + 6) = *puVar1;
    plVar4[8] = *(longlong *)(param_1 + 0x14);
    plVar4[9] = *(longlong *)(param_1 + 0x18);
    *(undefined4 *)(plVar4 + 4) = *(undefined4 *)(param_1 + 0xc);
    *(uint *)((longlong)plVar4 + 0x24) = uVar3;
    if (*(longlong *)(param_1 + 0x10) == 0) {
LAB_1c000c268:
      plVar4[7] = *(longlong *)(param_1 + 0x28);
      KeInitializeEvent(plVar4 + 0x22,0,0);
      KeInitializeDpc(plVar4 + 0x26,AccelpTimerCallback);
      KeInitializeTimer(plVar4 + 0x2e);
      puVar10 = auStack_168;
      plVar4[0x20] = (longlong)plVar4;
      plVar4[0x1f] = (longlong)(plVar4 + 0x1c);
      plVar4[0x1e] = (longlong)AccelpNotifyUser;
      uVar8 = 0;
      plVar4[0x1c] = 0;
      if ((*puVar1 & 1) != 0) {
        psVar11 = *(short **)(param_1 + 0x20);
        if (psVar11 == (short *)0x0) {
          uVar3 = 0xc000000d;
          puVar10 = auStack_168;
          goto LAB_1c000c188;
        }
        for (; (*psVar11 != 0 &&
               (psVar11 < (short *)((ulonglong)*(uint *)(param_1 + 0x24) +
                                   *(longlong *)(param_1 + 0x20)))); psVar11 = psVar11 + lVar7 + 2)
        {
          RtlInitUnicodeString(&local_118,psVar11);
          uVar5 = AccelpAddInterfaceListEntry((longlong)plVar4,(longlong)&local_118,0);
          uVar8 = 0;
          uVar3 = (uint)uVar5;
          if ((int)uVar3 < 0) goto LAB_1c000c188;
          lVar6 = -1;
          do {
            lVar7 = lVar6;
            lVar6 = lVar7 + 1;
          } while (psVar11[lVar6] != 0);
        }
      }
      ExEnterCriticalRegionAndAcquireResourceExclusive(plVar4[2] + 0x28);
      lVar6 = plVar4[2] + 0x18;
      plVar9 = *(longlong **)(plVar4[2] + 0x20);
      puVar10 = auStack_168;
      if (*plVar9 != lVar6) {
        plVar9 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        lVar6 = (*pcVar2)();
        puVar10 = auStack_160;
      }
      plVar4[1] = (longlong)plVar9;
      *plVar4 = lVar6;
      *plVar9 = (longlong)plVar4;
      *(longlong **)(lVar6 + 8) = plVar4;
      lVar6 = plVar4[2];
      *(undefined8 *)(puVar10 + -8) = 0x1c000c3a1;
      ExReleaseResourceAndLeaveCriticalRegion(lVar6 + 0x28);
      lVar6 = plVar4[2];
      uVar3 = *(uint *)(plVar4 + 6);
      uVar8 = 2;
      lVar7 = plVar4[3];
      *(longlong **)(puVar10 + 0x30) = plVar4 + 0x1b;
      uVar5 = *(undefined8 *)(lVar6 + 0xa8);
      *(longlong **)(puVar10 + 0x28) = plVar4;
      *(code **)(puVar10 + 0x20) = AccelpNotificationHandler;
      *(undefined8 *)(puVar10 + -8) = 0x1c000c3e6;
      uVar3 = IoRegisterPlugPlayNotification(2,~uVar3 & 1,lVar7,uVar5);
      if (-1 < (int)uVar3) {
        *(undefined8 *)(puVar10 + -8) = 0x1c000c3fd;
        AccelpSetEvent(plVar4 + 0x22);
        goto LAB_1c000c49c;
      }
    }
    else {
      _Size = (ulonglong)uVar3 << 2;
      uVar8 = 0x100;
      _Dst = (void *)ExAllocatePool2(0x100,_Size,0x65636341);
      plVar4[5] = (longlong)_Dst;
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,*(void **)(param_1 + 0x10),_Size);
        goto LAB_1c000c268;
      }
      uVar3 = 0xc0000017;
      puVar10 = auStack_168;
    }
LAB_1c000c188:
    lVar6 = plVar4[2];
    if (lVar6 == 0) goto LAB_1c000c40e;
    if (5 < DAT_1c0009000) {
      local_e0 = 0x1b;
      local_e8 = "AccelAcquireResourcesAsync";
      local_d8 = puVar10 + 0x48;
      *(uint *)(puVar10 + 0x48) = uVar3;
      local_d0 = 4;
      local_c8 = *(undefined8 *)(lVar6 + 0x90);
      *(short *)(puVar10 + 0x44) = *param_1;
      local_b8 = puVar10 + 0x44;
      *(undefined4 *)(puVar10 + 0x4c) = *(undefined4 *)(param_1 + 0xc);
      local_a8 = puVar10 + 0x4c;
      local_98 = *(undefined8 *)(param_1 + 8);
      *(uint *)(puVar10 + 0x40) = *puVar1;
      local_88 = puVar10 + 0x40;
      *(undefined1 **)(puVar10 + 0x38) = puVar10 + 0x60;
      *(undefined4 *)(puVar10 + 0x30) = 9;
      local_c0 = 0x10;
      local_b0 = 2;
      local_a0 = 4;
      local_90 = 0x10;
      local_80 = 4;
      *(undefined8 *)(puVar10 + -8) = 0x1c000c254;
      _tlgWriteEx_EtwWriteEx(uVar8,&DAT_1c0007a4f);
    }
  }
  lVar6 = plVar4[5];
  if (lVar6 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x1c000c473;
    ExFreePoolWithTag(lVar6,0x65636341);
  }
  *(undefined8 *)(puVar10 + -8) = 0x1c000c483;
  ExDeleteResourceLite(plVar4 + 0xe);
  *(undefined8 *)(puVar10 + -8) = 0x1c000c497;
  ExFreePoolWithTag(plVar4,0x65636341);
LAB_1c000c49c:
  *(undefined8 *)(puVar10 + -8) = 0x1c000c4aa;
  return uVar3;
}



===== AccelAcquireResourcesSync @ 1c000c4e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AccelAcquireResourcesSync(short *param_1,short *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  longlong *plVar5;
  code *pcVar6;
  short *psVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar11;
  longlong lVar10;
  ulonglong uVar12;
  byte *pbVar13;
  short *psVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  longlong *plVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  uint uVar22;
  uint uVar23;
  void *pvVar24;
  undefined1 auStackY_1b8 [8];
  undefined1 auStackY_1b0 [24];
  uint local_158;
  uint local_154;
  uint local_150;
  void *local_148;
  longlong *local_140;
  short *local_138;
  int local_130;
  int local_12c;
  short *local_128;
  short *local_120;
  undefined1 local_118 [32];
  char *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 local_88 [32];
  char *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0xc4e0  3  AccelAcquireResourcesSync */
  puVar17 = auStackY_1b8;
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_120 = param_2;
  local_138 = (short *)0x0;
  local_158 = 0;
  local_130 = 0;
  psVar14 = (short *)0x0;
  local_140 = (longlong *)0x0;
  local_148 = (void *)0x0;
  uVar22 = 0;
  uVar23 = 0;
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
LAB_1c000c940:
    uVar8 = 0xc000000d;
    puVar17 = auStackY_1b8;
LAB_1c000c945:
    if (5 < DAT_1c0009000) {
      local_60 = 0x1a;
      local_68 = "AccelAcquireResourcesSync";
      pbVar13 = &DAT_1c0007903;
      local_58 = puVar17 + 0x50;
      uVar12 = 4;
      *(undefined1 **)(puVar17 + 0x38) = local_88;
      *(undefined4 *)(puVar17 + 0x30) = 4;
      local_50 = 4;
LAB_1c000c987:
      *(uint *)(puVar17 + 0x50) = uVar8;
      *(undefined8 *)(puVar17 + -8) = 0x1c000c990;
      _tlgWriteEx_EtwWriteEx(uVar12,pbVar13);
    }
LAB_1c000c993:
    puVar15 = puVar17;
    if (uVar23 != 0) {
      plVar9 = *(longlong **)(puVar17 + 0x70);
      uVar12 = (ulonglong)uVar23;
      do {
        plVar5 = *(longlong **)(*plVar9 + 0x10);
        LOCK();
        plVar19 = plVar5 + 0x16;
        lVar10 = *plVar19;
        *plVar19 = *plVar19 + -1;
        UNLOCK();
        if (lVar10 < 2) {
          if (lVar10 == 1) {
            *(undefined8 *)(puVar17 + -8) = 0x1c000c9cb;
            AccelpCloseDevice(plVar5,'\0');
          }
          else {
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(0xe);
            puVar17 = puVar17 + 8;
          }
        }
        plVar9 = plVar9 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
      puVar15 = puVar17;
      psVar14 = local_138;
    }
    plVar9 = *(longlong **)(puVar15 + 0x78);
  }
  else {
    if ((*param_1 == 0) ||
       ((((ushort)param_1[1] < 0x58 || (*param_2 == 0)) || ((ushort)param_2[1] < 0x20)))) {
      uVar8 = 0xc0000059;
      goto LAB_1c000c945;
    }
    uVar8 = *(uint *)(param_1 + 0x1c);
    if ((((((uVar8 >> 0x10 & 1) != 0) && ((uVar8 & 2) != 0)) ||
         (((uVar8 >> 0x14 & 1) != 0 || (((uVar8 >> 0x12 & 1) != 0 || ((uVar8 & 0xffe8fffc) != 0)))))
         ) || (*(longlong *)(param_1 + 0x28) != 0)) ||
       ((((*(int *)(param_1 + 0xc) == 0 || (*(longlong *)(param_1 + 0x14) == 0)) ||
         (*(int *)(param_1 + 0xe) == 0)) ||
        ((*(uint *)(param_2 + 0xc) != 0 && ((*(uint *)(param_2 + 0xc) & 7) != 0))))))
    goto LAB_1c000c940;
    if ((uVar8 & 1) == 0) {
      uVar8 = AccelpEnumAcceleratorsHelper
                        (*(undefined8 *)(param_1 + 8),&local_138,&local_158,&local_130);
      puVar17 = auStackY_1b8;
      psVar14 = local_138;
      if ((int)uVar8 < 0) goto LAB_1c000c945;
    }
    else {
      if (*(short **)(param_1 + 0x20) == (short *)0x0) goto LAB_1c000c940;
      local_158 = *(uint *)(param_1 + 0x24);
      local_138 = *(short **)(param_1 + 0x20);
    }
    psVar14 = local_138;
    uVar8 = local_158;
    local_154 = *(uint *)(param_1 + 0xc);
    local_12c = *(int *)(param_1 + 0xe);
    local_150 = *(int *)(param_1 + 0xe) * local_154;
    uVar1 = local_150 * 8;
    if (*(uint *)(param_2 + 0xc) < uVar1) {
      *(uint *)(param_2 + 0xc) = uVar1;
      uVar8 = 0xc0000023;
LAB_1c000c65f:
      uVar23 = 0;
      puVar17 = auStackY_1b8;
      goto LAB_1c000c945;
    }
    local_148 = (void *)ExAllocatePool2(0x100,*(uint *)(param_2 + 0xc),0x65636341);
    if (local_148 == (void *)0x0) {
LAB_1c000c68b:
      uVar8 = 0xc0000017;
      goto LAB_1c000c65f;
    }
    uVar12 = 0x100;
    plVar9 = (longlong *)ExAllocatePool2();
    pvVar24 = local_148;
    puVar17 = auStackY_1b8;
    puVar16 = auStackY_1b8;
    puVar18 = auStackY_1b8;
    puVar15 = auStackY_1b8;
    local_140 = plVar9;
    if (plVar9 == (longlong *)0x0) goto LAB_1c000c68b;
    uVar2 = *(ulonglong *)(param_1 + 4);
    if (*psVar14 == 0) {
      uVar23 = 0;
LAB_1c000c879:
      uVar8 = 0xc0000001;
      if (uVar2 == 0) goto LAB_1c000c945;
      if (5 < DAT_1c0009000) {
        local_f0 = 0x1a;
        local_f8 = "AccelAcquireResourcesSync";
        pbVar13 = &DAT_1c0007891;
        local_e8 = puVar17 + 0x50;
        local_e0 = 4;
        local_d8 = *(undefined8 *)(uVar2 + 0x90);
        *(short *)(puVar17 + 0x58) = *param_1;
        local_c8 = puVar17 + 0x58;
        *(undefined4 *)(puVar17 + 0x68) = *(undefined4 *)(param_1 + 0xc);
        local_b8 = puVar17 + 0x68;
        local_a8 = *(undefined8 *)(param_1 + 8);
        *(undefined4 *)(puVar17 + 100) = *(undefined4 *)(param_1 + 0x1c);
        local_98 = puVar17 + 100;
        *(undefined1 **)(puVar17 + 0x38) = local_118;
        *(undefined4 *)(puVar17 + 0x30) = 9;
        local_d0 = 0x10;
        local_c0 = 2;
        local_b0 = 4;
        local_a0 = 0x10;
        local_90 = 4;
        goto LAB_1c000c987;
      }
      goto LAB_1c000c993;
    }
    uVar23 = 0;
    local_128 = (short *)((ulonglong)uVar8 + (longlong)psVar14);
    do {
      if (local_128 <= psVar14) break;
      plVar19 = (longlong *)((longlong)pvVar24 + (ulonglong)uVar23 * 8);
      uVar12 = uVar2;
      uVar8 = AccelpOpenAndAllocateAccelerator
                        (uVar2,(undefined8 *)psVar14,*(uint *)(param_1 + 0x1c),
                         *(uint *)(param_1 + 0xe),*(undefined4 **)(param_1 + 0x10),
                         *(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x14),
                         *(undefined8 *)(param_1 + 0x18),plVar19);
      if (-1 < (int)uVar8) {
        uVar23 = uVar23 + local_12c;
        uVar12 = (ulonglong)uVar22;
        uVar22 = uVar22 + 1;
        plVar9[uVar12] = *(longlong *)(*plVar19 + 0x10);
        if (uVar22 == local_154) break;
      }
      lVar10 = -1;
      do {
        lVar11 = lVar10;
        lVar10 = lVar11 + 1;
      } while (psVar14[lVar10] != 0);
      psVar14 = psVar14 + lVar11 + 2;
    } while (*psVar14 != 0);
    psVar7 = local_120;
    psVar14 = local_138;
    uVar21 = 0;
    uVar20 = 0;
    puVar17 = auStackY_1b8;
    if (uVar23 == 0) goto LAB_1c000c879;
    psVar7[0] = 1;
    psVar7[1] = 0x20;
    if (uVar23 != local_150) {
LAB_1c000c863:
      *(undefined4 *)(psVar7 + 4) = uVar20;
      psVar7[2] = 1;
      psVar7[3] = -0x4000;
      puVar17 = puVar16;
      goto LAB_1c000c879;
    }
    ExEnterCriticalRegionAndAcquireResourceExclusive(uVar2 + 0x28);
    uVar12 = 0;
    if (uVar22 != 0) {
      do {
        uVar20 = (undefined4)uVar21;
        puVar3 = *(ulonglong **)(uVar2 + 8);
        puVar4 = (ulonglong *)local_140[uVar12];
        if (*puVar3 != uVar2) {
          uVar12 = 3;
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)();
          puVar16 = auStackY_1b0;
          goto LAB_1c000c863;
        }
        puVar4[1] = (ulonglong)puVar3;
        *puVar4 = uVar2;
        *puVar3 = (ulonglong)puVar4;
        *(ulonglong **)(uVar2 + 8) = puVar4;
        uVar21 = CONCAT71((int7)((ulonglong)uVar21 >> 8),1);
        *(int *)(uVar2 + 0x10) = *(int *)(uVar2 + 0x10) + 1;
        AccelpLogAcceleratorAcquired(uVar2,(longlong)puVar4,1);
        uVar8 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar8;
      } while (uVar8 < uVar22);
    }
    ExReleaseResourceAndLeaveCriticalRegion(uVar2 + 0x28);
    pvVar24 = local_148;
    uVar8 = 0;
    *(uint *)(psVar7 + 4) = uVar23;
    memcpy(*(void **)(psVar7 + 8),local_148,(ulonglong)uVar1);
    plVar9 = local_140;
    psVar7[2] = 0;
    psVar7[3] = 0;
    if (uVar22 == 0) goto LAB_1c000c9f4;
    uVar12 = (ulonglong)uVar22;
    plVar19 = local_140;
    do {
      AccelpSetDeviceActive(*plVar19);
      plVar19 = plVar19 + 1;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  pvVar24 = *(void **)(puVar15 + 0x70);
  puVar18 = puVar15;
LAB_1c000c9f4:
  if ((psVar14 != (short *)0x0) && ((*(uint *)(param_1 + 0x1c) & 1) == 0)) {
    *(undefined8 *)(puVar18 + -8) = 0x1c000ca10;
    ExFreePoolWithTag(psVar14,0x65636341);
  }
  if (plVar9 != (longlong *)0x0) {
    *(undefined8 *)(puVar18 + -8) = 0x1c000ca29;
    ExFreePoolWithTag(plVar9,0x65636341);
  }
  if (pvVar24 != (void *)0x0) {
    *(undefined8 *)(puVar18 + -8) = 0x1c000ca42;
    ExFreePoolWithTag(pvVar24,0x65636341);
  }
  *(undefined8 *)(puVar18 + -8) = 0x1c000ca55;
  return uVar8;
}



===== AccelCloseResource @ 1c000ca80 =====

ulonglong AccelCloseResource(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 extraout_var;
  ulonglong uVar6;
  
                    /* 0xca80  12  AccelCloseResource */
  uVar5 = AccelpVerifyIrqlLessThanOrEqual();
  uVar6 = CONCAT44(extraout_var,uVar5);
  if (-1 < (int)uVar5) {
    if (param_1 == 0) {
      uVar6 = 0xc000000d;
    }
    else {
      LOCK();
      *(undefined4 *)(param_1 + 0x18) = 1;
      UNLOCK();
      plVar3 = *(longlong **)(param_1 + 0x10);
      uVar6 = 0;
      LOCK();
      plVar1 = plVar3 + 0x16;
      lVar2 = *plVar1;
      *plVar1 = *plVar1 + -1;
      UNLOCK();
      if (lVar2 < 2) {
        if (lVar2 == 1) {
          uVar6 = AccelpCloseDevice(plVar3,'\0');
        }
        else {
          pcVar4 = (code *)swi(0x29);
          uVar6 = (*pcVar4)(0xe);
        }
      }
    }
  }
  return uVar6;
}



===== AccelDestroyOffloadWorkspace @ 1c000caf0 =====

void AccelDestroyOffloadWorkspace(longlong *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0xcaf0  17  AccelDestroyOffloadWorkspace */
  uVar4 = AccelpVerifyIrqlLessThanOrEqual();
  if ((-1 < (int)uVar4) && (param_1 != (longlong *)0x0)) {
    plVar1 = param_1 + 5;
    ExEnterCriticalRegionAndAcquireResourceExclusive(plVar1);
    puVar5 = auStack_28;
    plVar7 = (longlong *)param_1[3];
    while (plVar7 != param_1 + 3) {
      plVar6 = (longlong *)*plVar7;
      if (((longlong *)plVar6[1] != plVar7) ||
         (puVar2 = (undefined8 *)plVar7[1], (longlong *)*puVar2 != plVar7)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar5 = auStack_20;
        goto LAB_1c000cb71;
      }
      *puVar2 = plVar6;
      plVar6[1] = (longlong)puVar2;
      AccelpFreeNotificationContext((longlong)plVar7,'\x01');
      plVar7 = plVar6;
    }
    plVar7 = (longlong *)*param_1;
    while (plVar6 = plVar7, plVar7 != param_1) {
LAB_1c000cb71:
      plVar7 = (longlong *)*plVar6;
      *(undefined8 *)(puVar5 + -8) = 0x1c000cb7e;
      AccelpCloseDevice(plVar6,'\x01');
    }
    *(undefined8 *)(puVar5 + -8) = 0x1c000cb8d;
    ExReleaseResourceAndLeaveCriticalRegion(plVar1);
    *(undefined8 *)(puVar5 + -8) = 0x1c000cb9c;
    ExDeleteResourceLite(plVar1);
    *(undefined8 *)(puVar5 + -8) = 0x1c000cbb0;
    ExFreePoolWithTag(param_1,0x65636341);
  }
  return;
}



===== AccelEnumAccelerators @ 1c000cbe0 =====

uint AccelEnumAccelerators(undefined8 param_1,void *param_2,uint *param_3,int *param_4)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  short *_Src;
  int iVar7;
  short *local_38 [2];
  
                    /* 0xcbe0  18  AccelEnumAccelerators */
  iVar7 = 0;
  iVar6 = 0;
  uVar2 = AccelpVerifyIrqlLessThanOrEqual();
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (param_3 == (uint *)0x0) {
    return 0xc000000d;
  }
  local_38[0] = (short *)0x0;
  uVar2 = IoGetDeviceInterfaces(param_1,0,0,local_38);
  if (-1 < (int)uVar2) {
    if (*local_38[0] != 0) {
      _Src = local_38[0];
      goto LAB_1c000cc80;
    }
    uVar2 = 0xc00000c0;
  }
  if (local_38[0] != (short *)0x0) {
    ExFreePoolWithTag();
  }
  _Src = (short *)0x0;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
LAB_1c000cc80:
  sVar1 = *_Src;
  psVar3 = _Src;
  while (sVar1 != 0) {
    iVar7 = iVar7 + 1;
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (psVar3[lVar4] != 0);
    iVar6 = iVar6 + (int)lVar4 * 2 + 2;
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (psVar3[lVar4] != 0);
    psVar3 = psVar3 + lVar5 + 2;
    sVar1 = *psVar3;
  }
  uVar2 = iVar6 + 2;
  if (*param_3 < uVar2) {
    *param_3 = uVar2;
    uVar2 = 0xc0000023;
  }
  else if (param_2 == (void *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    memcpy(param_2,_Src,(ulonglong)uVar2);
    *param_3 = uVar2;
    if (param_4 != (int *)0x0) {
      *param_4 = iVar7;
    }
    uVar2 = 0;
  }
  if (_Src != (short *)0x0) {
    ExFreePoolWithTag(_Src,0x65636341);
  }
  return uVar2;
}



===== AccelInitializeOffloadWorkspace @ 1c000cd40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000cdb4) */

uint AccelInitializeOffloadWorkspace(short *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  int local_a8 [4];
  undefined1 local_98 [8];
  undefined4 local_90;
  wchar_t *local_88;
  int *local_80;
  undefined4 local_78;
  int *local_70;
  undefined4 local_68;
  ulonglong local_18;
  
                    /* 0xcd40  25  AccelInitializeOffloadWorkspace */
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar3 = AccelpVerifyIrqlLessThanOrEqual();
  if (-1 < (int)uVar3) {
    if (((param_1 == (short *)0x0) || (param_2 == (longlong *)0x0)) ||
       (plVar2 = *(longlong **)(param_1 + 4), plVar2 == (longlong *)0x0)) {
      uVar3 = 0xc000000d;
    }
    else if ((*param_1 == 0) || ((ushort)param_1[1] < 0x20)) {
      uVar3 = 0xc0000059;
    }
    else {
      lVar5 = cpuid_basic_info(0);
      if (((*(int *)(lVar5 + 4) == 0x756e6547) && (*(int *)(lVar5 + 8) == 0x49656e69)) &&
         (*(int *)(lVar5 + 0xc) == 0x6c65746e)) {
        if ((*plVar2 == 0x4cb528213a127057) && (plVar2[1] == 0x8b76b7c2ec981be)) {
          local_a8[1] = 0;
          local_a8[0] = 0;
          memset(local_98,0,0x70);
          local_b8 = 0;
          local_88 = L"DisableMmOffload";
          local_68 = 4;
          local_80 = local_a8;
          local_90 = 0x120;
          local_70 = local_a8 + 1;
          local_78 = 0x4000004;
          iVar4 = RtlQueryRegistryValuesEx(2,L"WinAccel",local_98);
          if ((-1 < iVar4) && (local_a8[0] != 0)) goto LAB_1c000ce6c;
        }
        lVar5 = ExAllocatePool2(0x40,0xb0,0x65636341);
        if (lVar5 != 0) {
          *(undefined8 *)(lVar5 + 0x90) = *(undefined8 *)(param_1 + 4);
          *(undefined4 *)(lVar5 + 0x9c) = *(undefined4 *)(param_1 + 8);
          *(undefined8 *)(lVar5 + 0xa8) = *(undefined8 *)(param_1 + 0xc);
          lVar1 = lVar5 + 0x18;
          *(longlong *)(lVar5 + 0x20) = lVar1;
          *(longlong *)lVar1 = lVar1;
          *(longlong *)(lVar5 + 8) = lVar5;
          *(longlong *)lVar5 = lVar5;
          ExInitializeResourceLite(lVar5 + 0x28);
          KeQueryPerformanceCounter(lVar5 + 0xa0);
          uVar3 = 0;
          goto LAB_1c000cf05;
        }
        uVar3 = 0xc0000017;
      }
      else {
LAB_1c000ce6c:
        uVar3 = 0xc00000bb;
      }
    }
  }
  lVar5 = 0;
LAB_1c000cf05:
  *param_2 = lVar5;
  return uVar3;
}



===== AccelQueryResourceInformation @ 1c000cf40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AccelQueryResourceInformation(short *param_1,short *param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  undefined4 uVar6;
  short sVar7;
  undefined1 auStack_158 [32];
  undefined8 *local_138;
  undefined4 local_130;
  undefined8 *local_128;
  undefined4 local_120;
  ulonglong *local_118;
  undefined4 local_110;
  longlong local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  ulonglong local_e0 [2];
  undefined8 local_d0;
  ulonglong local_c8 [2];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0xcf40  29  AccelQueryResourceInformation */
  local_48 = __security_cookie ^ (ulonglong)auStack_158;
  local_100 = 0;
  uStack_f8 = 0;
  local_c8[0] = (ulonglong)(uint)local_c8[0];
  local_98._4_4_ = 0;
  local_f0._0_4_ = (uint)(ushort)local_f0;
  local_e0[0] = (ulonglong)(uint)local_e0[0];
  uVar3 = AccelpVerifyIrqlLessThanOrEqual();
  sVar5 = 0;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    return 0xc000000d;
  }
  if ((((*param_1 == 0) || ((ushort)param_1[1] < 0x10)) || (*param_2 == 0)) ||
     ((ushort)param_2[1] < 0x68)) {
    return 0xc0000059;
  }
  uVar3 = *(uint *)(param_1 + 2);
  if (5 < uVar3) {
    return 0xc000000d;
  }
  uVar6 = 0x50;
  local_f0 = 0;
  local_e8 = 0;
  local_a8 = 0;
  local_d0 = 0;
  uVar4 = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_e0[0] = 0;
  local_e0[1] = 0;
  memset(&local_98,0,0x50);
  lVar2 = *(longlong *)(param_1 + 4);
  local_108 = *(longlong *)(lVar2 + 0x10);
  if (uVar3 == 0) {
    uVar6 = 0x28;
    local_f0 = CONCAT62(local_f0._2_6_,1);
    local_118 = local_c8;
LAB_1c000d09f:
    local_120 = 0xc;
    local_128 = &local_f0;
    local_138 = &local_100;
    local_f0 = CONCAT44(uVar3,(uint)local_f0);
    local_130 = 0x64100c;
    local_110 = uVar6;
    uVar4 = ZwDeviceIoControlFile(*(undefined8 *)(local_108 + 0x18),0,0,0);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  else {
    if (uVar3 == 1) {
      uVar6 = 0x18;
      local_f0 = CONCAT62(local_f0._2_6_,1);
      local_118 = local_e0;
      goto LAB_1c000d09f;
    }
    if (uVar3 == 2) {
      local_f0 = CONCAT62(local_f0._2_6_,1);
      local_118 = &local_98;
      goto LAB_1c000d09f;
    }
    if (((uVar3 != 3) && (uVar3 != 4)) && (uVar3 != 5)) {
      return 0xc00000bb;
    }
  }
  iVar1 = *(int *)(param_1 + 2);
  sVar7 = 0;
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 8) = (undefined4)local_b8;
    *(undefined4 *)(param_2 + 10) = local_b8._4_4_;
LAB_1c000d1be:
    sVar7 = 0x10;
  }
  else {
    if (iVar1 == 1) {
LAB_1c000d172:
      *(undefined4 *)(param_2 + 8) = (undefined4)local_d0;
      goto LAB_1c000d1be;
    }
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        if (iVar1 != 4) {
          if (iVar1 == 5) {
            sVar7 = 0x60;
            AccelpGetSupportedCompression(lVar2,param_2 + 4);
            sVar5 = 1;
          }
          goto LAB_1c000d1c9;
        }
        *(ulonglong *)(param_2 + 4) =
             (*(ulonglong *)(local_108 + 0xd8) ^ *(ulonglong *)(param_2 + 4)) & 0xfffffffffffffffe ^
             *(ulonglong *)(local_108 + 0xd8);
        *(ulonglong *)(param_2 + 8) = (ulonglong)*(uint *)(local_108 + 0xe0);
        goto LAB_1c000d1be;
      }
      *(undefined4 *)(param_2 + 10) = *(undefined4 *)(lVar2 + 0x2c);
      local_d0._0_4_ = *(undefined4 *)(lVar2 + 0x28);
      goto LAB_1c000d172;
    }
    sVar7 = 0x48;
    *(undefined8 *)(param_2 + 0x10) = local_78;
    *(undefined8 *)(param_2 + 0x14) = uStack_70;
    *(undefined8 *)(param_2 + 4) = local_90;
    *(undefined8 *)(param_2 + 8) = local_88;
    *(undefined8 *)(param_2 + 0x18) = local_68;
    *(undefined8 *)(param_2 + 0x1c) = uStack_60;
    *(undefined4 *)(param_2 + 0xc) = local_80;
    *(undefined8 *)(param_2 + 0x20) = local_58;
    *(undefined8 *)(param_2 + 0x24) = uStack_50;
  }
  sVar5 = 1;
LAB_1c000d1c9:
  *param_2 = sVar5;
  param_2[1] = sVar7;
  return uVar4;
}



===== AccelShareAddressSpaceWithResource @ 1c000d210 =====

/* WARNING: Removing unreachable block (ram,0x0001c000d35c) */

int AccelShareAddressSpaceWithResource(longlong param_1,char param_2,longlong *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  uint local_res8 [2];
  longlong local_res20;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
                    /* 0xd210  33  AccelShareAddressSpaceWithResource */
  lVar5 = 0;
  local_res8[0] = 0;
  local_res20 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x24);
  if ((((uVar1 >> 0x10 & 1) == 0) && ((uVar1 & 2) == 0)) || (*(longlong *)(param_1 + 0x20) == 0)) {
    iVar3 = -0x3fffff45;
  }
  else {
    iVar3 = AccelpOpenAccelerator
                      (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x30),&local_res20);
    lVar5 = local_res20;
    if ((-1 < iVar3) && (iVar3 = AccelpEnableSvm(local_res20,param_2,local_res8), -1 < iVar3)) {
      uVar6 = 0x100;
      if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x24) & 0x20000) == 0) {
        uVar6 = 0x40;
      }
      plVar4 = (longlong *)ExAllocatePool2(uVar6,0x30,0x65636341);
      if (plVar4 != (longlong *)0x0) {
        plVar4[2] = param_1;
        plVar4[3] = lVar5;
        lVar5 = PsGetCurrentProcess();
        plVar4[4] = lVar5;
        *(uint *)(plVar4 + 5) = local_res8[0];
        ExEnterCriticalRegionAndAcquireResourceExclusive(*(longlong *)(param_1 + 0x10) + 0x1d0);
        puVar8 = auStack_48;
        lVar5 = *(longlong *)(param_1 + 0x10) + 0x1c0;
        plVar7 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1c8);
        if (*plVar7 != lVar5) {
          plVar7 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          lVar5 = (*pcVar2)();
          puVar8 = auStack_40;
        }
        plVar4[1] = (longlong)plVar7;
        *plVar4 = lVar5;
        *plVar7 = (longlong)plVar4;
        *(longlong **)(lVar5 + 8) = plVar4;
        lVar5 = *(longlong *)(param_1 + 0x10);
        *(undefined8 *)(puVar8 + -8) = 0x1c000d334;
        ExReleaseResourceAndLeaveCriticalRegion(lVar5 + 0x1d0);
        *param_3 = (longlong)plVar4;
        return iVar3;
      }
      iVar3 = -0x3fffffe9;
    }
  }
  if (lVar5 != 0) {
    ZwClose(lVar5);
  }
  return iVar3;
}



===== AccelStopSharingAddressSpaceWithResource @ 1c000d390 =====

undefined8 AccelStopSharingAddressSpaceWithResource(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  
                    /* 0xd390  34  AccelStopSharingAddressSpaceWithResource */
  lVar1 = param_1[2];
  ExEnterCriticalRegionAndAcquireResourceExclusive(*(longlong *)(lVar1 + 0x10) + 0x1d0);
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExReleaseResourceAndLeaveCriticalRegion(*(longlong *)(lVar1 + 0x10) + 0x1d0);
    ZwClose(param_1[3]);
    ExFreePoolWithTag(param_1,0x65636341);
    return 0;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== AccelpAddInterfaceListEntry @ 1c000d428 =====

undefined8 AccelpAddInterfaceListEntry(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  plVar5 = (longlong *)ExAllocatePool2(0x100,0x20,0x65636341);
  if (plVar5 == (longlong *)0x0) {
    return 0xc0000017;
  }
  lVar6 = ExAllocatePool2(0x100,*(undefined2 *)(param_2 + 2),0x65636341);
  plVar5[3] = lVar6;
  if (lVar6 == 0) {
    ExFreePoolWithTag(plVar5,0x65636341);
    return 0xc0000017;
  }
  *(undefined2 *)((longlong)plVar5 + 0x12) = *(undefined2 *)(param_2 + 2);
  RtlCopyUnicodeString(plVar5 + 2,param_2);
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x70);
  puVar8 = auStack_48;
  plVar7 = (longlong *)(param_1 + 0x58);
  if (param_3 != 0) {
    *(bool *)param_3 = (longlong *)*plVar7 == plVar7;
  }
  plVar10 = (longlong *)*plVar7;
  bVar3 = false;
  if (plVar10 != plVar7) {
    do {
      plVar1 = (longlong *)*plVar10;
      iVar4 = RtlCompareUnicodeString(plVar10 + 2,plVar5 + 2,0);
      if (iVar4 == 0) {
        bVar3 = true;
      }
      plVar10 = plVar1;
    } while (plVar1 != plVar7);
    puVar9 = auStack_48;
    if (bVar3) goto LAB_1c000d571;
  }
  iVar4 = 1;
  plVar7 = *(longlong **)(param_1 + 0x60);
  if (*plVar7 != param_1 + 0x58) {
    iVar4 = 3;
    pcVar2 = (code *)swi(0x29);
    plVar7 = (longlong *)(*pcVar2)();
    puVar8 = auStack_40;
  }
  *plVar5 = param_1 + 0x58;
  plVar5[1] = (longlong)plVar7;
  *plVar7 = (longlong)plVar5;
  *(longlong **)(param_1 + 0x60) = plVar5;
  *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + iVar4;
  puVar9 = puVar8;
LAB_1c000d571:
  *(undefined8 *)(puVar9 + -8) = 0x1c000d57b;
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x70);
  return 0;
}



===== AccelpAllocateAccelerator @ 1c000d5a8 =====

int AccelpAllocateAccelerator
              (undefined8 param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *_Dst;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar9 = (ulonglong)param_3;
  uVar11 = 0x2c;
  local_38 = 0;
  uStack_30 = 0;
  if (param_4 != (undefined4 *)0x0) {
    uVar11 = param_3 * 4 + 0x28;
  }
  _Dst = (undefined2 *)ExAllocatePool2(0x100,uVar11,0x65636341);
  if (_Dst == (undefined2 *)0x0) {
    iVar4 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar11);
    iVar10 = param_3 * 4 + 0x18;
    lVar5 = ExAllocatePool2(0x100,iVar10,0x65636341);
    if (lVar5 == 0) {
      iVar4 = -0x3fffffe9;
    }
    else {
      *(undefined4 *)(_Dst + 0xc) = 0;
      *(undefined4 *)(_Dst + 2) = 0;
      *_Dst = 1;
      *(undefined4 *)(_Dst + 0xe) = 1;
      *(uint *)(_Dst + 0x10) = param_3;
      if ((param_4 != (undefined4 *)0x0) && (*(undefined4 *)(_Dst + 0xc) = 1, param_3 != 0)) {
        uVar6 = uVar9;
        puVar7 = param_4;
        do {
          *(undefined4 *)((longlong)_Dst + (0x24 - (longlong)param_4) + (longlong)puVar7) = *puVar7;
          puVar7 = puVar7 + 1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      uVar1 = param_2[1];
      uVar2 = param_2[2];
      uVar3 = param_2[3];
      *(undefined4 *)(_Dst + 4) = *param_2;
      *(undefined4 *)(_Dst + 6) = uVar1;
      *(undefined4 *)(_Dst + 8) = uVar2;
      *(undefined4 *)(_Dst + 10) = uVar3;
      do {
        iVar4 = ZwDeviceIoControlFile(param_1,0,0,0,&local_38,0x641000,_Dst,uVar11,lVar5,iVar10);
      } while (iVar4 == -0x3ffffdd3);
      if ((-1 < iVar4) && (param_3 != 0)) {
        lVar8 = lVar5 - (longlong)param_5;
        do {
          *param_5 = *(undefined4 *)(lVar8 + 0x18 + (longlong)param_5);
          param_5 = param_5 + 1;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
    }
    ExFreePoolWithTag(_Dst,0x65636341);
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0x65636341);
    }
  }
  return iVar4;
}



===== AccelpCapacityChangeAvailable @ 1c000d764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AccelpCapacityChangeAvailable(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  longlong *local_50;
  undefined4 local_48;
  undefined4 local_44;
  
  local_res10[0] = 0;
  lVar4 = param_1 + 0x130;
  local_70 = 0;
  local_5c = 0;
  local_54 = 0;
  local_44 = 0;
  local_res8[0] = 0;
  local_res18 = 0;
  ExEnterCriticalRegionAndAcquireResourceExclusive(lVar4);
  if ((*(int *)(param_1 + 0x19c) == 0) && (*(int *)(param_1 + 0x198) == 5)) {
    *(undefined4 *)(param_1 + 0x198) = 4;
    *(undefined4 *)(param_1 + 0x1a0) = 3;
    ExReleaseResourceAndLeaveCriticalRegion(lVar4);
    iVar2 = AccelpAllocateAccelerator
                      (*(undefined8 *)(param_1 + 0x18),
                       *(undefined4 **)(*(longlong *)(param_1 + 0x10) + 0x90),1,(undefined4 *)0x0,
                       local_res10);
    if ((-1 < iVar2) &&
       (((*(uint *)(param_1 + 0x24) & 2) == 0 ||
        (iVar2 = AccelpEnableSvm(*(undefined8 *)(param_1 + 0x18),'\0',(uint *)0x0), -1 < iVar2)))) {
      uVar3 = 0;
      if ((*(uint *)(param_1 + 0x24) >> 0x10 & 1) != 0) {
        iVar2 = AccelpEnableSvm(*(undefined8 *)(param_1 + 0x18),'\x01',local_res8);
        if (iVar2 < 0) {
          return;
        }
        uVar3 = local_res8[0];
      }
      if ((((*(uint *)(param_1 + 0x24) & 2) == 0) &&
          (lVar4 = 0, (*(uint *)(param_1 + 0x24) >> 0x10 & 1) == 0)) ||
         ((iVar2 = AccelpMapAccelerator(*(undefined8 *)(param_1 + 0x18),0,1,&local_res18),
          -1 < iVar2 && (lVar4 = local_res18, local_res18 != 0)))) {
        ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x48);
        lVar1 = *(longlong *)(param_1 + 0x38);
        *(undefined4 *)(lVar1 + 0x28) = 0;
        *(undefined4 *)(lVar1 + 0x18) = 0;
        *(longlong *)(lVar1 + 0x20) = lVar4;
        *(undefined4 *)(lVar1 + 0x2c) = local_res10[0];
        *(undefined8 *)(param_1 + 0xb0) = 1;
        *(uint *)(param_1 + 0x20) = uVar3;
        ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x48);
        local_50 = &local_res20;
        local_74 = 0;
        local_68 = &local_60;
        local_60 = 0x200001;
        local_58 = 1;
        local_48 = 8;
        local_78 = 0x180001;
        local_res20 = lVar1;
        (**(code **)(param_1 + 0x120))(&local_78,*(undefined8 *)(param_1 + 0x128));
        AccelpSetDeviceActive(param_1);
      }
    }
  }
  else {
    ExReleaseResourceAndLeaveCriticalRegion(lVar4);
  }
  return;
}



===== AccelpCapacityChangeRelease @ 1c000d954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AccelpCapacityChangeRelease(longlong param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined8 *puVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  
  lVar1 = param_1 + 0x130;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (undefined8 *)0x0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  ExEnterCriticalRegionAndAcquireResourceExclusive(lVar1);
  if (*(int *)(param_1 + 0x19c) != 0) {
LAB_1c000d9dd:
    ExReleaseResourceAndLeaveCriticalRegion(lVar1);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x198);
  *(int *)(param_1 + 0x1a0) = param_2;
  if ((iVar2 == 1) || (iVar2 == 2)) {
    bVar4 = true;
  }
  else if (iVar2 == 3) {
    bVar6 = true;
    *(undefined4 *)(param_1 + 0x198) = 4;
  }
  else if (((iVar2 != 4) && (iVar2 != 5)) && (iVar2 == 6)) goto LAB_1c000d9dd;
  ExReleaseResourceAndLeaveCriticalRegion(lVar1);
  if (bVar4) {
    AccelpWaitEvent(param_1 + 0x1a8);
    KeResetEvent(param_1 + 0x1a8);
    ExEnterCriticalRegionAndAcquireResourceExclusive(lVar1);
    iVar2 = *(int *)(param_1 + 0x198);
    if (iVar2 == 1) {
      if (param_2 == 2) {
        AccelpFreeDevice(param_1);
        *(undefined4 *)(param_1 + 0x198) = 5;
      }
      else {
        ZwClose(*(undefined8 *)(param_1 + 0x18));
        *(undefined8 *)(param_1 + 0x18) = 0;
        *(undefined4 *)(param_1 + 0x198) = 7;
LAB_1c000dac1:
        bVar5 = true;
      }
    }
    else if (iVar2 == 3) {
      bVar6 = true;
      *(undefined4 *)(param_1 + 0x198) = 4;
    }
    else if (iVar2 == 7) goto LAB_1c000dac1;
    ExReleaseResourceAndLeaveCriticalRegion(lVar1);
    if (bVar5) goto LAB_1c000db8e;
  }
  if (!bVar6) {
    return;
  }
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x48);
  puVar3 = *(undefined8 **)(param_1 + 0x38);
  while (puVar7 = puVar3, puVar7 != (undefined8 *)(param_1 + 0x38)) {
    puVar3 = (undefined8 *)*puVar7;
    if (*(int *)(puVar7 + 3) == 0) {
      local_38 = 0x100180001;
      local_28 = puVar7;
      (**(code **)(param_1 + 0x120))(&local_38,*(undefined8 *)(param_1 + 0x128));
    }
  }
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x48);
  ExEnterCriticalRegionAndAcquireResourceExclusive(lVar1);
  iVar2 = *(int *)(param_1 + 0x198);
  ExReleaseResourceAndLeaveCriticalRegion(lVar1);
  if ((iVar2 - 5U & 0xfffffffd) != 0) {
    AccelpSetDeviceActive(param_1);
    return;
  }
  if (param_2 != 1) {
    return;
  }
LAB_1c000db8e:
  AccelpUnregisterAndFreeDevice(param_1);
  return;
}



===== AccelpCloseDevice @ 1c000dba4 =====

undefined8 AccelpCloseDevice(longlong *param_1,char param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 uVar7;
  
  lVar2 = param_1[2];
  bVar6 = false;
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x26);
  iVar1 = (int)param_1[0x33];
  if (iVar1 == 4) {
    if ((int)param_1[0x34] == 2) {
      AccelpFreeDevice((longlong)param_1);
      *(int *)(param_1 + 0x33) = 5;
      ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x26);
      return 0;
    }
LAB_1c000dc3a:
    if ((*(int *)((longlong)param_1 + 0x19c) == 0) &&
       ((iVar1 != 4 || (((int)param_1[0x34] != 1 && ((int)param_1[0x34] != 3))))))
    goto LAB_1c000dc71;
  }
  else if (iVar1 != 2) goto LAB_1c000dc3a;
  bVar6 = true;
LAB_1c000dc71:
  *(undefined4 *)(param_1 + 0x33) = 6;
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x26);
  if (param_2 == '\0') {
    ExEnterCriticalRegionAndAcquireResourceExclusive(lVar2 + 0x28);
  }
  lVar3 = *param_1;
  if (lVar3 != 0) {
    if ((*(longlong **)(lVar3 + 8) != param_1) ||
       (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar7 = (*pcVar5)();
      return uVar7;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + -1;
  }
  if (param_2 == '\0') {
    ExReleaseResourceAndLeaveCriticalRegion(lVar2 + 0x28);
  }
  ZwClose(param_1[3]);
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x26);
  *(undefined4 *)(param_1 + 0x33) = 7;
  iVar1 = *(int *)((longlong)param_1 + 0x19c);
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x26);
  if (iVar1 != 0) {
    AccelpSetEvent(param_1 + 0x35);
  }
  if (!bVar6) {
    AccelpUnregisterAndFreeDevice((longlong)param_1);
  }
  AccelpLogAcceleratorClosed(lVar2,(longlong)param_1);
  return 0;
}



===== AccelpDeviceQueryComplete @ 1c000dd74 =====

undefined8 AccelpDeviceQueryComplete(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  
  plVar1 = param_1 + 0x26;
  cVar5 = '\0';
  ExEnterCriticalRegionAndAcquireResourceExclusive(plVar1);
  iVar2 = (int)param_1[0x33];
  iVar3 = *(int *)((longlong)param_1 + 0x19c);
  *(undefined4 *)((longlong)param_1 + 0x19c) = 3;
  if (iVar2 == 3) {
    cVar5 = '\x01';
    *(undefined4 *)((longlong)param_1 + 0x19c) = 4;
    cVar4 = '\0';
  }
  else {
    cVar4 = '\0';
    if (iVar2 != 5) {
      cVar4 = '\x01';
    }
  }
  ExReleaseResourceAndLeaveCriticalRegion(plVar1);
  if (iVar3 == 0) {
    AccelpDeviceRemoveCommon(param_1,iVar2,'\x01',cVar4,cVar5);
  }
  ExEnterCriticalRegionAndAcquireResourceExclusive(plVar1);
  if ((int)param_1[0x33] == 7) {
    ExReleaseResourceAndLeaveCriticalRegion(plVar1);
    AccelpUnregisterAndFreeDevice((longlong)param_1);
  }
  else {
    KeResetEvent(param_1 + 0x35);
    ExReleaseResourceAndLeaveCriticalRegion(plVar1);
  }
  return 0;
}



===== AccelpDeviceQueryRemove @ 1c000de94 =====

undefined8 AccelpDeviceQueryRemove(longlong *param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  cVar2 = '\0';
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x26);
  iVar1 = (int)param_1[0x33];
  *(undefined4 *)((longlong)param_1 + 0x19c) = 1;
  if (iVar1 == 3) {
    cVar3 = '\x01';
    *(undefined4 *)((longlong)param_1 + 0x19c) = 2;
  }
  else if (iVar1 != 5) {
    cVar2 = '\x01';
  }
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x26);
  AccelpDeviceRemoveCommon(param_1,iVar1,'\0',cVar2,cVar3);
  return 0;
}



===== AccelpDeviceRemoveCommon @ 1c000df40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AccelpDeviceRemoveCommon(longlong *param_1,int param_2,char param_3,char param_4,char param_5)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  bool bVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong *local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (longlong *)0x0;
  if (param_4 != '\0') {
    AccelpWaitEvent(param_1 + 0x35);
  }
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x26);
  bVar5 = (param_2 - 1U & 0xfffffffb) == 0;
  if (bVar5) {
    ZwClose(param_1[3]);
    param_1[3] = 0;
    *(undefined4 *)(param_1 + 0x33) = 7;
  }
  if ((param_2 == 2) && ((int)param_1[0x33] == 3)) {
    param_5 = '\x01';
    *(uint *)((longlong)param_1 + 0x19c) = (-(uint)(param_3 != '\0') & 2) + 2;
  }
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x26);
  if (bVar5) {
    ExEnterCriticalRegionAndAcquireResourceExclusive(param_1[2] + 0x28);
    lVar1 = *param_1;
    if (lVar1 != 0) {
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
      *(int *)(param_1[2] + 0x10) = *(int *)(param_1[2] + 0x10) + -1;
    }
    ExReleaseResourceAndLeaveCriticalRegion(param_1[2] + 0x28);
  }
  if (param_5 != '\0') {
    ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 9);
    plVar2 = (longlong *)param_1[7];
    plVar4 = local_28;
    while (local_28 = plVar2, local_28 != param_1 + 7) {
      plVar2 = (longlong *)*local_28;
      if ((int)local_28[3] == 0) {
        local_38 = 0x100180001;
        (*(code *)param_1[0x24])(&local_38,param_1[0x25]);
        plVar4 = local_28;
      }
    }
    local_28 = plVar4;
    ExReleaseResourceAndLeaveCriticalRegion(param_1 + 9);
  }
  return;
}



===== AccelpEnableSvm @ 1c000e0fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AccelpEnableSvm(undefined8 param_1,char param_2,uint *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 *local_88;
  undefined4 local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40;
  longlong local_38;
  uint local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_48._0_4_ = (uint)(ushort)local_48;
  local_50 = 0;
  local_38 = 0;
  local_30 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (param_3 != (uint *)0x0) {
    *param_3 = *param_3 & 0xfff00000;
  }
  if (param_2 == '\0') {
    local_80 = 0xc;
    local_48 = 0;
    local_40 = 0;
    local_88 = &local_48;
    local_a8 = &local_70;
    local_90 = (undefined8 *)((ulonglong)local_90 & 0xffffffff00000000);
    local_98 = 0;
    local_a0 = CONCAT44(local_a0._4_4_,0x641004);
    iVar2 = ZwDeviceIoControlFile(0,0,0,0);
    if ((-1 < iVar2) && (param_3 != (uint *)0x0)) {
      *param_3 = *param_3 & 0xfff00000 | local_40 & 0xfffff;
    }
  }
  else {
    local_a0 = 0;
    local_78 = 0;
    local_a8 = &local_78;
    iVar2 = ObReferenceObjectByHandle(0,0,*(undefined8 *)IoFileObjectType_exref,0);
    lVar1 = local_78;
    if (-1 < iVar2) {
      uVar3 = IoGetRelatedDeviceObject(local_78);
      KeInitializeEvent(&local_60,0,0);
      local_88 = &local_70;
      local_90 = &local_60;
      local_98 = CONCAT71(local_98._1_7_,1);
      local_a8 = &local_38;
      local_a0 = CONCAT44(local_a0._4_4_,0xc);
      lVar4 = IoBuildDeviceIoControlRequest(0x641400,uVar3,0,0);
      if (lVar4 == 0) {
        iVar2 = -0x3fffff66;
      }
      else {
        *(longlong *)(*(longlong *)(lVar4 + 0xb8) + -0x18) = lVar1;
        iVar2 = IofCallDriver(uVar3,lVar4);
        if (iVar2 == 0x103) {
          local_a8 = (longlong *)0x0;
          KeWaitForSingleObject(&local_60,0,0,0);
          iVar2 = (int)local_70;
        }
        if (-1 < iVar2) {
          *param_3 = *param_3 & 0xfff00000 | local_30 & 0xfffff | 0x80000000;
        }
      }
    }
    if (lVar1 != 0) {
      ObfDereferenceObject(lVar1);
    }
  }
  return iVar2;
}



===== AccelpEnumAcceleratorsHelper @ 1c000e314 =====

uint AccelpEnumAcceleratorsHelper(undefined8 param_1,undefined8 *param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  void *pvVar2;
  uint local_28;
  int local_24 [3];
  
  local_24[0] = 0;
  pvVar2 = (void *)0x0;
  local_28 = 0;
  while( true ) {
    uVar1 = local_28;
    if (pvVar2 != (void *)0x0) {
      ExFreePoolWithTag(pvVar2,0x65636341);
      pvVar2 = (void *)0x0;
    }
    if ((uVar1 != 0) &&
       (pvVar2 = (void *)ExAllocatePool2(0x100,uVar1,0x65636341), pvVar2 == (void *)0x0)) break;
    uVar1 = AccelEnumAccelerators(param_1,pvVar2,&local_28,local_24);
    if (uVar1 != 0xc0000023) {
      if ((int)uVar1 < 0) {
        if (pvVar2 != (void *)0x0) {
          ExFreePoolWithTag(pvVar2,0x65636341);
        }
      }
      else {
        *param_3 = local_28;
        *param_4 = local_24[0];
        *param_2 = pvVar2;
      }
      return uVar1;
    }
  }
  return 0xc0000017;
}



===== AccelpFreeDevice @ 1c000e400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AccelpFreeDevice(longlong param_1)

{
  undefined4 *puVar1;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_60;
  undefined2 *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_28 = 1;
  uStack_26 = 0;
  local_40 = 0;
  local_48 = 0;
  local_14 = 0;
  local_38 = 0;
  uStack_30 = 0;
  puVar1 = *(undefined4 **)(*(longlong *)(param_1 + 0x10) + 0x90);
  local_58 = &local_28;
  local_50 = 0x18;
  local_68 = &local_38;
  local_60 = 0x641010;
  uStack_24 = *puVar1;
  uStack_1c = puVar1[2];
  uStack_20 = (undefined2)puVar1[1];
  uStack_1e = (undefined2)((uint)puVar1[1] >> 0x10);
  uStack_18 = (undefined2)puVar1[3];
  uStack_16 = (undefined2)((uint)puVar1[3] >> 0x10);
  ZwDeviceIoControlFile(*(undefined8 *)(param_1 + 0x18),0,0,0);
  return;
}



===== AccelpFreeNotificationContext @ 1c000e4a8 =====

void AccelpFreeNotificationContext(longlong param_1,char param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar4 = PsGetCurrentThreadId();
  puVar6 = auStack_28;
  if ((param_2 != '\0') && (puVar6 = auStack_28, *(longlong *)(param_1 + 0x50) == lVar4)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(7);
    puVar6 = auStack_20;
  }
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x1c000e4f5;
    IoUnregisterPlugPlayNotificationEx();
  }
  *(undefined8 *)(puVar6 + -8) = 0x1c000e508;
  ExWaitForRundownProtectionRelease(param_1 + 0x1b0);
  puVar5 = *(undefined8 **)(param_1 + 0x58);
  while( true ) {
    if (puVar5 == (undefined8 *)(param_1 + 0x58)) {
      *(undefined8 *)(puVar6 + -8) = 0x1c000e57b;
      ExDeleteResourceLite(param_1 + 0x70);
      lVar4 = *(longlong *)(param_1 + 0x28);
      if (lVar4 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c000e595;
        ExFreePoolWithTag(lVar4,0x65636341);
      }
      *(undefined8 *)(puVar6 + -8) = 0x1c000e5a9;
      ExFreePoolWithTag(param_1,0x65636341);
      return;
    }
    puVar1 = (undefined8 *)*puVar5;
    if (((undefined8 *)puVar1[1] != puVar5) ||
       (puVar2 = (undefined8 *)puVar5[1], (undefined8 *)*puVar2 != puVar5)) break;
    *puVar2 = puVar1;
    puVar1[1] = puVar2;
    lVar4 = puVar5[3];
    if (lVar4 != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1c000e552;
      ExFreePoolWithTag(lVar4,0x65636341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x1c000e566;
    ExFreePoolWithTag(puVar5,0x65636341);
    puVar5 = puVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== AccelpInitializeResources @ 1c000e5d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AccelpInitializeResources
               (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
               uint param_5,undefined4 *param_6,longlong param_7,longlong param_8,
               undefined8 *param_9,undefined4 param_10,uint param_11,undefined8 param_12,
               undefined8 param_13)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined8 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined1 auStack_1f8 [8];
  undefined1 auStack_1f0 [56];
  undefined8 *local_1b8;
  longlong local_1b0;
  undefined8 local_198;
  uint local_190 [6];
  short local_178 [2];
  undefined1 local_174 [4];
  undefined8 local_170;
  uint uStack_168;
  undefined4 uStack_164;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  int local_108 [2];
  longlong local_100;
  char *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  char *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1f8;
  local_108[1] = 0;
  local_1b8 = param_3;
  local_198 = param_2;
  memset(local_108,0,0x6c);
  *(undefined4 *)(param_1 + 0x20) = param_10;
  *(undefined8 *)(param_1 + 0x120) = param_12;
  *(undefined8 *)(param_1 + 0x128) = param_13;
  local_190[0] = 0;
  local_190[1] = 0;
  local_190[2] = 0;
  local_190[3] = 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined8 *)(param_1 + 0x18) = param_4;
  *(uint *)(param_1 + 0x24) = param_11;
  ExInitializeResourceLite(param_1 + 0x48);
  lVar1 = param_1 + 0x38;
  uVar15 = 0;
  *(longlong *)(param_1 + 0x40) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(ulonglong *)(param_1 + 0xb0) = (ulonglong)param_5;
  if (param_5 != 0) {
    puVar8 = (undefined8 *)(param_8 + 0x20);
    puVar12 = param_6;
    puVar13 = param_9;
    do {
      *puVar8 = 0;
      *(undefined4 *)(puVar8 + 1) = 0;
      puVar8[-2] = param_1;
      *(undefined4 *)((longlong)puVar8 + 0xc) =
           *(undefined4 *)((param_7 - (longlong)param_6) + (longlong)puVar12);
      if ((((param_11 & 2) != 0) || ((param_11 >> 0x10 & 1) != 0)) && (param_9 != (undefined8 *)0x0)
         ) {
        *puVar8 = *puVar13;
      }
      if (param_6 != (undefined4 *)0x0) {
        *(undefined4 *)(puVar8 + 1) = *puVar12;
      }
      plVar3 = *(longlong **)(param_1 + 0x40);
      if (*plVar3 != lVar1) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar10 = auStack_1f0;
        param_3 = param_9;
        goto LAB_1c000e886;
      }
      plVar2 = puVar8 + -4;
      puVar8[-3] = plVar3;
      *plVar2 = lVar1;
      puVar8 = puVar8 + 6;
      uVar14 = (int)uVar15 + 1;
      uVar15 = (ulonglong)uVar14;
      *plVar3 = (longlong)plVar2;
      puVar13 = puVar13 + 1;
      *(longlong **)(param_1 + 0x40) = plVar2;
      puVar12 = puVar12 + 1;
    } while (uVar14 < param_5);
    param_3 = local_1b8;
  }
  memset(local_174,0,100);
  local_178[0] = 1;
  local_178[1] = 0x68;
  local_1b8 = (undefined8 *)0x100001;
  param_11 = 1;
  local_1b0 = param_8;
  uVar15 = 0;
  uVar14 = AccelQueryResourceInformation((short *)&local_1b8,local_178);
  puVar10 = auStack_1f8;
  if (-1 < (int)uVar14) {
    *(uint *)(param_1 + 0xb8) = uStack_168;
    *(undefined4 *)(param_1 + 0xbc) = uStack_164;
    memset(local_174,0,100);
    local_178[0] = 1;
    local_178[1] = 0x68;
    local_1b8 = (undefined8 *)0x200100001;
    local_1b0 = param_8;
    uVar14 = AccelQueryResourceInformation((short *)&local_1b8,local_178);
    puVar10 = auStack_1f8;
    if (-1 < (int)uVar14) {
      local_108[0] = 0;
      local_100 = param_8;
      *(undefined8 *)(param_1 + 0xc0) = local_170;
      *(ulonglong *)(param_1 + 200) = CONCAT44(uStack_164,uStack_168);
      *(undefined8 *)(param_1 + 0xd0) = local_160;
      *(undefined8 *)(param_1 + 0xd8) = uStack_158;
      *(undefined8 *)(param_1 + 0xe0) = local_150;
      *(undefined8 *)(param_1 + 0xe8) = uStack_148;
      *(undefined8 *)(param_1 + 0xf0) = local_140;
      *(undefined8 *)(param_1 + 0xf8) = uStack_138;
      *(undefined8 *)(param_1 + 0x100) = local_130;
      uVar14 = AccelpInternalOperationHandler(local_108,local_190);
      puVar10 = auStack_1f8;
      if (-1 < (int)uVar14) {
        uVar14 = local_190[0];
        uVar9 = local_190[1];
        uVar11 = local_190[2];
        iVar7 = AccelpCalculateAccelDescriptorSize(local_190[0],local_190[1],local_190[2]);
        *(uint *)(param_1 + 0x10c) = uVar14;
        *(uint *)(param_1 + 0x110) = uVar9;
        *(int *)(param_1 + 0x108) = iVar7;
        *(uint *)(param_1 + 0x114) = uVar11;
        cVar5 = RtlCreateUnicodeString(param_1 + 0x28);
        puVar10 = auStack_1f8;
        if (cVar5 == '\0') {
          uVar14 = 0xc000009a;
          puVar10 = auStack_1f8;
        }
        else {
LAB_1c000e886:
          *(undefined8 *)(puVar10 + -8) = 0x1c000e88d;
          uVar6 = KeQueryHighestNodeNumber();
          *(undefined4 *)(puVar10 + 0x40) = 0x100001;
          *(uint *)(puVar10 + 0x44) = param_11;
          *(longlong *)(puVar10 + 0x48) = param_8;
          *(undefined8 *)(puVar10 + -8) = 0x1c000e8b6;
          memset(local_174,0,100);
          local_178[0] = 1;
          local_178[1] = 0x68;
          *(undefined8 *)(puVar10 + -8) = 0x1c000e8cb;
          uVar14 = AccelQueryResourceInformation((short *)(puVar10 + 0x40),local_178);
          if (-1 < (int)uVar14) {
            if ((uVar6 < uStack_168) && (5 < DAT_1c0009000)) {
              local_e0 = 0x1a;
              local_e8 = "AccelpInitializeResources";
              local_d8 = puVar10 + 0x50;
              local_6c = (undefined4)uVar15;
              *(undefined4 *)(puVar10 + 0x50) = local_6c;
              local_c8 = "Non-fatal error: Queried node exceeded KeNumberNodes";
              local_d0 = 4;
              local_c0 = 0x35;
              local_b0 = 0x10;
              local_b8 = *(undefined8 *)(*(longlong *)(puVar10 + 0x60) + 0x90);
              *(undefined4 *)(puVar10 + 0x54) = *(undefined4 *)(param_1 + 0xb8);
              local_a8 = puVar10 + 0x54;
              *(undefined4 *)(puVar10 + 0x58) = *(undefined4 *)(param_1 + 0xbc);
              local_98 = puVar10 + 0x58;
              local_88 = &local_70;
              local_78 = *(undefined8 *)(param_1 + 0x30);
              local_70 = (uint)*(ushort *)(param_1 + 0x28);
              local_68 = puVar10 + 0x60;
              local_58 = puVar10 + 0x40;
              *(int **)(puVar10 + 0x38) = local_108;
              *(undefined4 *)(puVar10 + 0x30) = 0xc;
              local_a0 = 4;
              local_90 = 4;
              local_80 = 2;
              *(uint *)(puVar10 + 0x60) = (uint)uVar6;
              local_60 = 4;
              *(uint *)(puVar10 + 0x40) = uStack_168;
              local_50 = 4;
              *(undefined8 *)(puVar10 + -8) = 0x1c000e9f7;
              _tlgWriteEx_EtwWriteEx((ulonglong)uStack_168,&DAT_1c000795d);
            }
          }
          *(undefined8 *)(puVar10 + -8) = 0x1c000ea0a;
          KeInitializeEvent(param_1 + 0x1a8,0,0);
          lVar1 = param_1 + 0x1c0;
          *(longlong *)(param_1 + 0x1c8) = lVar1;
          *(longlong *)lVar1 = lVar1;
          *(undefined8 *)(puVar10 + -8) = 0x1c000ea2b;
          ExInitializeResourceLite(param_1 + 0x1d0);
          *(undefined8 *)(puVar10 + -8) = 0x1c000ea3e;
          ExInitializeResourceLite(param_1 + 0x130);
          *(uint *)(param_1 + 0x198) = param_11;
          *(undefined8 *)(puVar10 + -8) = 0x1c000ea55;
          uVar14 = AccelpRegisterTargetDeviceChange(param_3,param_1);
          if (-1 < (int)uVar14) goto LAB_1c000ea71;
        }
      }
    }
  }
  if (*(ulonglong *)(param_1 + 0x30) != uVar15) {
    *(undefined8 *)(puVar10 + -8) = 0x1c000ea6c;
    RtlFreeUnicodeString(param_1 + 0x28);
  }
LAB_1c000ea71:
  *(undefined8 *)(puVar10 + -8) = 0x1c000ea82;
  return uVar14;
}



===== AccelpMapAccelerator @ 1c000eaa4 =====

int AccelpMapAccelerator(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 *param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar4 = (ulonglong)param_3;
  local_46 = 0;
  iVar3 = param_3 * 8 + 0x18;
  local_38 = 0;
  uStack_30 = 0;
  lVar1 = ExAllocatePool2(0x100,iVar3,0x65636341);
  if (lVar1 == 0) {
    iVar3 = -0x3fffffe9;
  }
  else {
    local_48 = 1;
    local_44 = 0;
    local_40 = param_2;
    iVar3 = ZwDeviceIoControlFile(param_1,0,0,0,&local_38,0x641008,&local_48,0x10,lVar1,iVar3);
    if ((-1 < iVar3) && (param_3 != 0)) {
      lVar2 = lVar1 - (longlong)param_4;
      do {
        *param_4 = *(undefined8 *)(lVar2 + 0x10 + (longlong)param_4);
        param_4 = param_4 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    ExFreePoolWithTag(lVar1,0x65636341);
  }
  return iVar3;
}



===== AccelpNotificationHandler @ 1c000ebd0 =====

ulonglong AccelpNotificationHandler(longlong param_1,longlong param_2)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  bool bVar4;
  char local_res8 [8];
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  cVar1 = ExAcquireRundownProtection(param_2 + 0x1b0);
  if (cVar1 == '\0') {
    return 0;
  }
  if ((*(longlong *)(param_1 + 0x14) == **(longlong **)(param_2 + 0x18)) &&
     (*(longlong *)(param_1 + 0x1c) == (*(longlong **)(param_2 + 0x18))[1])) {
    if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
      bVar4 = true;
    }
    else {
      if ((*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4005) ||
         (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0)) goto LAB_1c000ed17;
      bVar4 = false;
    }
    RtlInitUnicodeString(&local_28,*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 8));
    if (bVar4) {
      local_res8[0] = '\0';
      bVar4 = false;
      uVar2 = AccelpAddInterfaceListEntry(param_2,(longlong)&local_28,(longlong)local_res8);
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        if ((*(uint *)(param_2 + 0x30) & 0x40000) == 0) {
          if (local_res8[0] != '\0') {
            ExQueueWorkItem(param_2 + 0xe0,1);
            return uVar3;
          }
          if ((int)uVar2 < 0) goto LAB_1c000ed17;
        }
        else if (*(int *)(param_2 + 0x108) == 0) {
          cVar1 = KeSetTimer(param_2 + 0x170,0xfffffffffff0bdc0,param_2 + 0x130);
          bVar4 = cVar1 == '\0';
        }
        if (bVar4) {
          return uVar3;
        }
      }
    }
  }
LAB_1c000ed17:
  ExReleaseRundownProtection(param_2 + 0x1b0);
  return uVar3;
}



===== AccelpNotifyUser @ 1c000ed50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AccelpNotifyUser(longlong param_1)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 *puVar6;
  char cVar7;
  uint uVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  int iVar12;
  longlong lVar13;
  byte *pbVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  uint uVar17;
  ulonglong uVar18;
  uint uVar19;
  ulonglong uVar20;
  bool bVar21;
  undefined1 auStackY_168 [8];
  undefined1 auStackY_160 [24];
  uint local_110 [2];
  code *local_108;
  longlong local_100;
  longlong *local_f8;
  longlong *local_f0;
  ulonglong local_e8;
  undefined8 uStack_e0;
  longlong local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  longlong local_a0;
  longlong *local_98;
  undefined1 local_88 [32];
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  plVar15 = *(longlong **)(param_1 + 0x20);
  local_100 = 0;
  bVar5 = true;
  local_108 = (code *)((ulonglong)local_108 & 0xffffffff00000000);
  uVar1 = *(uint *)((longlong)plVar15 + 0x24);
  lVar13 = plVar15[2];
  uVar18 = 0;
  plVar9 = (longlong *)0x0;
  local_b8 = (ulonglong *)0x0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_a8 = plVar15;
  local_a0 = lVar13;
  ExEnterCriticalRegionAndAcquireResourceExclusive(plVar15 + 0xe);
  if (((*(uint *)(plVar15 + 6) >> 0x12 & 1) == 0) && ((*(uint *)(plVar15 + 6) >> 0x14 & 1) == 0)) {
    if (*(uint *)((longlong)plVar15 + 300) < *(uint *)(plVar15 + 4)) {
      uVar19 = *(uint *)(plVar15 + 4) - *(uint *)((longlong)plVar15 + 300);
      goto LAB_1c000ee02;
    }
  }
  else {
    uVar19 = *(uint *)(plVar15 + 0xd);
LAB_1c000ee02:
    if (uVar19 != 0) {
      local_100 = ExAllocatePool2(0x100,uVar1 * uVar19 * 8,0x65636341);
      if (local_100 != 0) {
        plVar9 = (longlong *)ExAllocatePool2(0x100,uVar19 * 8,0x65636341);
        local_98 = plVar9;
        if (plVar9 != (longlong *)0x0) {
          plVar10 = (longlong *)plVar15[0xb];
          uVar8 = 0;
          if (plVar10 != plVar15 + 0xb) {
            while( true ) {
              puVar16 = auStackY_168;
              local_f0 = (longlong *)*plVar10;
              local_f8 = plVar10;
              if (((longlong *)local_f0[1] != plVar10) ||
                 (plVar2 = (longlong *)plVar10[1], (longlong *)*plVar2 != plVar10)) break;
              *plVar2 = (longlong)local_f0;
              local_f0[1] = (longlong)plVar2;
              local_b0 = (longlong *)(local_100 + (ulonglong)uVar8 * 8);
              uVar8 = AccelpOpenAndAllocateAccelerator
                                (plVar15[2],(undefined8 *)plVar10[3],*(uint *)(plVar15 + 6),uVar1,
                                 (undefined4 *)plVar15[5],plVar15[7],plVar15[8],plVar15[9],local_b0)
              ;
              *(int *)(plVar15 + 0xd) = (int)plVar15[0xd] + -1;
              local_110[0] = uVar8;
              if (local_f8[3] != 0) {
                ExFreePoolWithTag(local_f8[3],0x65636341);
              }
              ExFreePoolWithTag(local_f8,0x65636341);
              if (-1 < (int)uVar8) {
                lVar3 = *(longlong *)(*local_b0 + 0x10);
                plVar9[uVar18] = lVar3;
                if (((*(uint *)(plVar15 + 6) & 0x40000) != 0) &&
                   (cVar7 = AccelpSetDeviceAcquireInProgress(lVar3), cVar7 == '\0'))
                goto LAB_1c000eff1;
                uVar17 = (int)uVar18 + 1;
                uVar18 = (ulonglong)uVar17;
                iVar12 = (uint)local_108 + uVar1;
                local_108 = (code *)CONCAT44(local_108._4_4_,iVar12);
                if (uVar17 != uVar19) goto LAB_1c000eff5;
LAB_1c000f007:
                if (iVar12 == 0) goto LAB_1c000ee75;
                uVar19 = (uint)uVar18;
                *(int *)((longlong)plVar15 + 300) = *(int *)((longlong)plVar15 + 300) + uVar19;
                local_e8 = local_e8 & 0xffffffff;
                uStack_d0 = CONCAT44(uStack_d0._4_4_,iVar12 * 8);
                local_d8 = local_100;
                uStack_e0 = CONCAT44(uStack_e0._4_4_,iVar12);
                plVar10 = (longlong *)plVar15[9];
                local_108 = (code *)plVar15[8];
                if ((*(uint *)(plVar15 + 6) & 0x100000) != 0) {
                  *(undefined4 *)(plVar15 + 0x21) = 0;
                  *(undefined1 *)(plVar15 + 0x25) = 1;
                }
                local_f8 = plVar10;
                ExReleaseResourceAndLeaveCriticalRegion();
                uVar20 = local_e8;
                local_e8 = CONCAT44(local_e8._4_4_,0x200001);
                local_b8 = &local_e8;
                local_c8 = 0x180001;
                if ((longlong)uVar20 < 0) goto LAB_1c000f0f1;
                ExEnterCriticalRegionAndAcquireResourceExclusive(lVar13 + 0x28);
                uVar20 = 0;
                if (uVar19 != 0) goto LAB_1c000f0a6;
                goto LAB_1c000f0dc;
              }
LAB_1c000eff1:
              iVar12 = (uint)local_108;
LAB_1c000eff5:
              if (local_f0 == plVar15 + 0xb) goto LAB_1c000f007;
              plVar10 = local_f0;
              uVar8 = (uint)local_108;
            }
            goto LAB_1c000f25e;
          }
          goto LAB_1c000ee75;
        }
      }
      uVar8 = 0xc0000017;
      goto LAB_1c000ee7a;
    }
  }
LAB_1c000ee75:
  uVar8 = 0xc0000001;
LAB_1c000ee7a:
  puVar16 = auStackY_168;
  lVar13 = plVar15[2];
  puVar6 = auStackY_168;
  if (lVar13 == 0) goto LAB_1c000f265;
  if (DAT_1c0009000 < 6) goto LAB_1c000f2b9;
  pbVar14 = &DAT_1c00079e6;
  local_58 = local_110;
  local_48 = *(undefined8 *)(lVar13 + 0x90);
  local_3c = 0;
  local_40 = 0x10;
  puVar16 = auStackY_168;
  local_110[0] = uVar8;
  goto LAB_1c000f2b4;
  while( true ) {
    *plVar2 = lVar13;
    plVar2[1] = (longlong)plVar10;
    *plVar10 = (longlong)plVar2;
    *(longlong **)(lVar13 + 8) = plVar2;
    *(int *)(lVar13 + 0x10) = *(int *)(lVar13 + 0x10) + 1;
    AccelpLogAcceleratorAcquired(lVar13,(longlong)plVar2,0);
    uVar17 = (int)uVar20 + 1;
    uVar20 = (ulonglong)uVar17;
    if (uVar19 <= uVar17) break;
LAB_1c000f0a6:
    plVar10 = *(longlong **)(lVar13 + 8);
    plVar2 = (longlong *)plVar9[uVar20];
    if (*plVar10 != lVar13) goto LAB_1c000f25e;
  }
LAB_1c000f0dc:
  ExReleaseResourceAndLeaveCriticalRegion(lVar13 + 0x28);
  plVar10 = local_f8;
LAB_1c000f0f1:
  lVar11 = PsGetCurrentThreadId();
  plVar2 = local_f8;
  lVar3 = local_100;
  LOCK();
  plVar15[10] = lVar11;
  UNLOCK();
  if ((*(uint *)(plVar15 + 6) & 0x40000) == 0) {
    uVar17 = 0;
    uStack_e0 = CONCAT44(uStack_e0._4_4_,uVar1);
    uStack_d0 = CONCAT44(uStack_d0._4_4_,uVar1 << 3);
    if (uVar19 != 0) {
      do {
        local_d8 = lVar3 + (ulonglong)(uVar1 * uVar17) * 8;
        local_f0 = (longlong *)*plVar9;
        cVar7 = AccelpSetDeviceAcquireInProgress((longlong)local_f0);
        if (cVar7 != '\0') {
          (*local_108)(&local_c8,plVar2);
          AccelpSetDeviceActive((longlong)local_f0);
        }
        uVar17 = uVar17 + 1;
        plVar9 = plVar9 + 1;
      } while (uVar17 < uVar19);
      plVar15 = local_a8;
      plVar9 = local_98;
      lVar13 = local_a0;
      uVar8 = local_110[0];
    }
  }
  else {
    (*local_108)(&local_c8,plVar10);
    if (uVar19 != 0) {
      plVar10 = plVar9;
      do {
        AccelpSetDeviceActive(*plVar10);
        plVar10 = plVar10 + 1;
        uVar18 = uVar18 - 1;
      } while (uVar18 != 0);
    }
  }
  LOCK();
  plVar15[10] = 0;
  UNLOCK();
  if (((*(uint *)((longlong)plVar15 + 300) < *(uint *)(plVar15 + 4)) ||
      ((*(uint *)(plVar15 + 6) & 0x40000) != 0)) || ((char)plVar15[0x25] != '\0')) {
LAB_1c000f255:
    if (-1 < (int)uVar8) goto LAB_1c000f2b9;
    goto LAB_1c000ee7a;
  }
  LOCK();
  bVar21 = *(int *)((longlong)plVar15 + 0x10c) == 0;
  if (bVar21) {
    *(int *)((longlong)plVar15 + 0x10c) = 1;
  }
  UNLOCK();
  if (!bVar21) goto LAB_1c000f255;
  AccelpWaitEvent(plVar15 + 0x22);
  ExEnterCriticalRegionAndAcquireResourceExclusive(lVar13 + 0x28);
  lVar3 = *plVar15;
  if ((*(longlong **)(lVar3 + 8) == plVar15) &&
     (plVar10 = (longlong *)plVar15[1], (longlong *)*plVar10 == plVar15)) {
    *plVar10 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar10;
    ExReleaseRundownProtection(plVar15 + 0x36);
    bVar5 = false;
    AccelpFreeNotificationContext((longlong)plVar15,'\0');
    ExReleaseResourceAndLeaveCriticalRegion(lVar13 + 0x28);
    goto LAB_1c000f255;
  }
LAB_1c000f25e:
  lVar13 = 3;
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)();
  puVar6 = auStackY_160;
LAB_1c000f265:
  puVar16 = puVar6;
  if (DAT_1c0009000 < 6) goto LAB_1c000f2b9;
  pbVar14 = &DAT_1c0007a22;
  local_58 = (uint *)(puVar16 + 0x58);
  *(undefined1 **)(puVar16 + 0x38) = local_88;
  *(undefined4 *)(puVar16 + 0x30) = 4;
  *(uint *)(puVar16 + 0x58) = uVar8;
LAB_1c000f2b4:
  local_4c = 0;
  local_50 = 4;
  local_5c = 0;
  local_60 = 0x11;
  local_68 = "AccelpNotifyUser";
  *(undefined8 *)(puVar16 + -8) = 0x1c000f2b9;
  _tlgWriteEx_EtwWriteEx(lVar13,pbVar14);
LAB_1c000f2b9:
  if (puVar16[0x50] != '\0') {
    *(undefined8 *)(puVar16 + -8) = 0x1c000f2cb;
    ExReleaseResourceAndLeaveCriticalRegion(plVar15 + 0xe);
  }
  if (plVar9 != (longlong *)0x0) {
    *(undefined8 *)(puVar16 + -8) = 0x1c000f2e4;
    ExFreePoolWithTag(plVar9,0x65636341);
  }
  if (*(longlong *)(puVar16 + 0x68) != 0) {
    *(undefined8 *)(puVar16 + -8) = 0x1c000f302;
    ExFreePoolWithTag(*(longlong *)(puVar16 + 0x68),0x65636341);
  }
  if (bVar5) {
    *(undefined8 *)(puVar16 + -8) = 0x1c000f31a;
    ExReleaseRundownProtection(plVar15 + 0x36);
  }
  *(undefined8 *)(puVar16 + -8) = 0x1c000f32b;
  return;
}



===== AccelpOpenAccelerator @ 1c000f354 =====

int AccelpOpenAccelerator(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  longlong local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res10 = 0;
  local_34 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_2 == (longlong *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    RtlInitUnicodeString(&local_58,param_1);
    local_28 = &local_58;
    local_30 = 0;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwCreateFile(&local_res10,0xc0100000,&local_38,&local_48,0,0,3,1,0x20,0,0);
    if (iVar1 < 0) {
      if (local_res10 != 0) {
        ZwClose();
      }
    }
    else {
      *param_2 = local_res10;
    }
  }
  return iVar1;
}



===== AccelpOpenAndAllocateAccelerator @ 1c000f45c =====

uint AccelpOpenAndAllocateAccelerator
               (longlong param_1,undefined8 *param_2,uint param_3,uint param_4,undefined4 *param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8,longlong *param_9)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 *_Dst;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint local_48 [2];
  longlong local_40;
  
  local_40 = 0;
  local_48[0] = 0;
  uVar7 = (ulonglong)param_4;
  _Dst = (undefined8 *)0x0;
  lVar5 = 0;
  puVar4 = (undefined4 *)0x0;
  cVar2 = KeAreAllApcsDisabled();
  if (cVar2 != '\0') {
    return 0xc0000001;
  }
  uVar3 = AccelpOpenAccelerator(param_2,&local_40);
  lVar1 = local_40;
  if (-1 < (int)uVar3) {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,uVar7 * 4,0x65636341);
    if (puVar4 == (undefined4 *)0x0) {
LAB_1c000f4fb:
      uVar3 = 0xc0000017;
    }
    else {
      uVar3 = AccelpAllocateAccelerator
                        (lVar1,*(undefined4 **)(param_1 + 0x90),param_4,param_5,puVar4);
      if (((-1 < (int)uVar3) &&
          (((param_3 & 2) == 0 || (uVar3 = AccelpEnableSvm(lVar1,'\0',local_48), -1 < (int)uVar3))))
         && (((param_3 & 0x10000) == 0 ||
             (uVar3 = AccelpEnableSvm(lVar1,'\x01',local_48), -1 < (int)uVar3)))) {
        if (((param_3 & 2) != 0) || ((param_3 & 0x10000) != 0)) {
          _Dst = (undefined8 *)ExAllocatePool2(0x100,param_4 * 8,0x65636341);
          if (_Dst == (undefined8 *)0x0) goto LAB_1c000f4fb;
          memset(_Dst,0,(ulonglong)(param_4 * 8));
          uVar3 = AccelpMapAccelerator(lVar1,param_6,param_4,_Dst);
          if ((int)uVar3 < 0) goto LAB_1c000f500;
        }
        uVar6 = 0x100;
        if ((param_3 >> 0x11 & 1) == 0) {
          uVar6 = 0x40;
        }
        lVar5 = ExAllocatePool2(uVar6,param_4 * 0x30 + 0x2f8,0x65636341);
        if (lVar5 == 0) goto LAB_1c000f4fb;
        lVar8 = lVar5 + 0x2f8;
        uVar3 = AccelpInitializeResources
                          (lVar5,param_1,param_2,lVar1,param_4,param_5,(longlong)puVar4,lVar8,_Dst,
                           local_48[0],param_3,param_7,param_8);
        if (-1 < (int)uVar3) {
          if (param_4 != 0) {
            do {
              *param_9 = lVar8;
              lVar8 = lVar8 + 0x30;
              param_9 = param_9 + 1;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          goto LAB_1c000f52d;
        }
      }
    }
  }
LAB_1c000f500:
  if (lVar1 != 0) {
    ZwClose(lVar1);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x65636341);
  }
LAB_1c000f52d:
  if (_Dst != (undefined8 *)0x0) {
    ExFreePoolWithTag(_Dst,0x65636341);
  }
  if (puVar4 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar4,0x65636341);
  }
  return uVar3;
}



===== AccelpRegisterTargetDeviceChange @ 1c000f734 =====

int AccelpRegisterTargetDeviceChange(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[1] = 0;
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,param_1);
  iVar1 = IoGetDeviceObjectPointer(&local_18,1,local_res18,local_res18 + 1);
  if (-1 < iVar1) {
    iVar1 = IoRegisterPlugPlayNotification
                      (3,0,local_res18[0],*(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0xa8),
                       AccelpTargetDeviceChangeHandler,param_2,param_2 + 0x118);
  }
  if (local_res18[0] != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== AccelpSetDeviceAcquireInProgress @ 1c000f7f8 =====

undefined1 AccelpSetDeviceAcquireInProgress(longlong param_1)

{
  bool bVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  bVar1 = false;
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x130);
  if ((*(int *)(param_1 + 0x19c) == 0) && (*(int *)(param_1 + 0x1a0) == 0)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x198) = 2;
  }
  else {
    bVar1 = true;
  }
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x130);
  if (bVar1) {
    AccelpSetEvent(param_1 + 0x1a8);
  }
  return uVar2;
}



===== AccelpSetDeviceActive @ 1c000f890 =====

undefined1 AccelpSetDeviceActive(longlong param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  
  bVar3 = false;
  uVar4 = 0;
  bVar2 = false;
  ExEnterCriticalRegionAndAcquireResourceExclusive(param_1 + 0x130);
  iVar1 = *(int *)(param_1 + 0x198);
  if (((iVar1 - 1U & 0xfffffffc) == 0) && (iVar1 != 3)) {
    uVar4 = 1;
    *(undefined4 *)(param_1 + 0x198) = 3;
  }
  if (iVar1 == 7) {
    if (*(int *)(param_1 + 0x19c) == 0) {
      bVar3 = true;
      goto LAB_1c000f919;
    }
  }
  else if ((*(int *)(param_1 + 0x19c) == 0) &&
          ((iVar1 != 1 || ((*(int *)(param_1 + 0x1a0) != 1 && (*(int *)(param_1 + 0x1a0) != 2))))))
  goto LAB_1c000f919;
  bVar2 = true;
LAB_1c000f919:
  ExReleaseResourceAndLeaveCriticalRegion(param_1 + 0x130);
  if (bVar2) {
    AccelpSetEvent(param_1 + 0x1a8);
  }
  if (bVar3) {
    AccelpUnregisterAndFreeDevice(param_1);
  }
  return uVar4;
}



===== AccelpTargetDeviceChangeHandler @ 1c000f970 =====

undefined4 AccelpTargetDeviceChangeHandler(longlong param_1,longlong *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4006) &&
     (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
    uVar3 = AccelpDeviceQueryRemove(param_2);
    uVar2 = (undefined4)uVar3;
  }
  else {
    if ((*(longlong *)(param_1 + 4) != 0x11d046f0cb3a4008) ||
       (*(longlong *)(param_1 + 0xc) != 0x3f05139760008fb0)) {
      if ((*(longlong *)(param_1 + 4) == 0x11d046f0cb3a4007) &&
         (*(longlong *)(param_1 + 0xc) == 0x3f05139760008fb0)) {
        bVar1 = false;
        ExEnterCriticalRegionAndAcquireResourceExclusive(param_2 + 0x26);
        if (((int)param_2[0x33] == 7) || (*(int *)((longlong)param_2 + 0x19c) == 0)) {
          bVar1 = true;
        }
        else {
          *(undefined4 *)((longlong)param_2 + 0x19c) = 0;
        }
        ExReleaseResourceAndLeaveCriticalRegion(param_2 + 0x26);
        if (bVar1) {
          AccelpUnregisterAndFreeDevice((longlong)param_2);
          return 0;
        }
        return 0;
      }
      if (*(longlong *)(param_1 + 4) != 0x41265942865ef6dd) {
        return 0;
      }
      if (*(longlong *)(param_1 + 0xc) != -0x21b0aaf6871a7069) {
        return 0;
      }
      if (*(short *)(param_1 + 2) != 0x38) {
        return 0;
      }
      if (*(longlong *)(param_1 + 0x28) != **(longlong **)(param_2[2] + 0x90)) {
        return 0;
      }
      if (*(longlong *)(param_1 + 0x30) != (*(longlong **)(param_2[2] + 0x90))[1]) {
        return 0;
      }
      if (*(int *)(param_1 + 0x24) == 3) {
        AccelpCapacityChangeAvailable((longlong)param_2);
        return 0;
      }
      AccelpCapacityChangeRelease((longlong)param_2,*(int *)(param_1 + 0x24));
      return 0;
    }
    uVar3 = AccelpDeviceQueryComplete(param_2);
    uVar2 = (undefined4)uVar3;
  }
  return uVar2;
}



===== AccelpUnregisterPlugPlayNotification @ 1c000fab8 =====

undefined8 AccelpUnregisterPlugPlayNotification(longlong param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = IoUnregisterPlugPlayNotificationEx();
  }
  return uVar1;
}



===== AccelpDeleteLock @ 1c000fae0 =====

void AccelpDeleteLock(void)

{
  ExDeleteResourceLite();
  return;
}



===== AccelpFree @ 1c000fafc =====

void AccelpFree(undefined8 param_1,longlong param_2)

{
  if (param_2 != 0) {
    ExFreePoolWithTag(param_2,0x65636341);
  }
  return;
}



===== AccelAbortOffloadRequests @ 1c000fb30 =====

undefined8 AccelAbortOffloadRequests(void)

{
                    /* 0xfb30  1  AccelAbortOffloadRequests */
  return 0xc0000002;
}



===== AccelBuildCompressionEncoding @ 1c000fb40 =====

uint AccelBuildCompressionEncoding
               (longlong *param_1,longlong param_2,int param_3,void *param_4,uint *param_5,
               ulonglong param_6)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  short local_68 [4];
  longlong *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  longlong local_38;
  ulonglong local_30;
  
                    /* 0xfb40  4  AccelBuildCompressionEncoding */
  if ((((param_1 == (longlong *)0x0) || (param_2 == 0)) || (param_5 == (uint *)0x0)) ||
     (param_3 == 0)) {
    uVar1 = 0xc000000d;
  }
  else if ((param_4 == (void *)0x0) || (*param_5 < 0x400)) {
    uVar1 = 0xc0000023;
    *param_5 = 0x400;
  }
  else {
    local_48 = 2;
    local_44 = 2;
    local_68[0] = 1;
    local_68[1] = 0x40;
    local_68[2] = 0;
    local_68[3] = 0;
    local_40 = 0;
    local_30 = 0;
    local_58 = 0;
    local_50 = 0;
    local_4c = 6;
    local_38 = 0;
    local_60 = param_1;
    uVar1 = AccelInitializeCompressionWorkspace(local_68);
    if (uVar1 == 0xc0000023) {
      lVar2 = ExAllocatePool2(0x100,local_30 & 0xffffffff,0x65636341);
      if (lVar2 == 0) {
        uVar1 = 0xc0000017;
      }
      else {
        local_38 = lVar2;
        uVar1 = AccelInitializeCompressionWorkspace(local_68);
        if (-1 < (int)uVar1) {
          uVar1 = AccelpComputeHistogram(param_1,param_2,param_3,lVar2,param_6);
          if (-1 < (int)uVar1) {
            uVar3 = AccelpBuildHuffmanEncoding(lVar2);
            uVar1 = (uint)uVar3;
            if (-1 < (int)uVar1) {
              memcpy(param_4,(void *)(*(longlong *)(lVar2 + 0x18) + 0x3148),(ulonglong)*param_5);
            }
          }
        }
        ExFreePoolWithTag(lVar2,0x65636341);
      }
    }
    else if (uVar1 == 0) {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}



===== _tlgEnableCallback @ 1c000fcd0 =====

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



===== DllUnload @ 1c000fd50 =====

undefined8 DllUnload(void)

{
                    /* 0xfd50  41  DllUnload */
  AccelpUnregisterProviderGUID();
  return 0;
}



===== entry @ 1c0011010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0011044 =====

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



===== DllInitialize @ 1c0011080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DllInitialize(void)

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
  
                    /* 0x11080  40  DllInitialize */
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_1c0009008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c0009008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c0009008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c0009008 + -4);
  if (DAT_1c0009020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c0009028 = 0;
  uRam00000001c0009030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c00110e3;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c0009000,&DAT_1c0009020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0009008;
    *(undefined8 *)(puVar4 + -8) = 0x1c001110a;
    EtwSetInformation(DAT_1c0009020,2,PTR_DAT_1c0009008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c001111e;
  return iVar3;
}



===== DriverEntry @ 1c001112c =====

undefined8 DriverEntry(void)

{
  return 0;
}


