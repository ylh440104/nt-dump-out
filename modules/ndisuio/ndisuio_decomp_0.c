
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 1c0001020 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== NdisuioCleanup @ 1c0001030 =====

undefined8 NdisuioCleanup(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  if (((WwanIsInitialized == '\0') || (WwanGlobals == (longlong *)0x0)) || (*WwanGlobals != param_1)
     ) {
    lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
    if (lVar1 != 0) {
      lVar4 = param_2;
      uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x20);
      *(uint *)(lVar1 + 0x18) = *(uint *)(lVar1 + 0x18) & 0xffffff0f;
      *(undefined8 *)(lVar1 + 0x30) = 0;
      uVar3 = CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar2);
      *(undefined1 *)(lVar1 + 0x28) = uVar2;
      KeReleaseSpinLock(lVar1 + 0x20);
      ndisuioValidateOpenAndDoRequest
                (lVar1,uVar3,param_3,local_res20,in_stack_ffffffffffffffd8,local_res18,'\0');
      ndisuioCancelPendingReads(lVar1);
      ndisuioFlushReceiveQueue(lVar1);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    uVar3 = 0;
  }
  else {
    uVar3 = WwanprotCleanup(param_2);
  }
  return uVar3;
}



===== ndisuioDerefOpen @ 1c0001118 =====

void ndisuioDerefOpen(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + 1;
    NdisFreeMemory(param_1,0,0);
  }
  return;
}



===== ndisuioOpenDevice @ 1c000114c =====

int ndisuioOpenDevice(void *param_1,uint param_2,longlong param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffb8;
  uint local_28 [4];
  
  iVar7 = 0;
  local_28[0] = 0;
  lVar8 = param_3;
  puVar5 = ndisuioLookupDevice(param_1,param_2);
  if (puVar5 == (undefined8 *)0x0) {
    iVar7 = -0x3fffffcc;
  }
  else {
    puVar1 = puVar5 + 4;
    uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
    *(undefined1 *)(puVar5 + 5) = uVar3;
    uVar2 = (undefined3)(*(uint *)(puVar5 + 3) >> 8);
    if ((*(uint *)(puVar5 + 3) & 0xf0) == 0) {
      LOCK();
      bVar9 = *(longlong *)(param_3 + 0x18) == 0;
      if (bVar9) {
        *(longlong *)(param_3 + 0x18) = (longlong)puVar5;
      }
      UNLOCK();
      uVar6 = (ulonglong)CONCAT31(uVar2,*(undefined1 *)(puVar5 + 5));
      if (bVar9) {
        puVar5[6] = param_3;
        *(uint *)(puVar5 + 3) = *(uint *)(puVar5 + 3) & 0xffffff1f | 0x10;
        KeReleaseSpinLock(puVar1);
        local_28[1] = 0xb;
        iVar4 = ndisuioValidateOpenAndDoRequest
                          ((longlong)puVar5,uVar6,lVar8,local_28 + 1,in_stack_ffffffffffffffb8,
                           local_28,'\x01');
        if (iVar4 == 0) {
          *(undefined4 *)(puVar5 + 7) = 0;
          *param_4 = puVar5;
        }
        else {
          uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
          *(undefined1 *)(puVar5 + 5) = uVar3;
          LOCK();
          if (puVar5 == *(undefined8 **)(param_3 + 0x18)) {
            *(longlong *)(param_3 + 0x18) = 0;
          }
          UNLOCK();
          *(uint *)(puVar5 + 3) = *(uint *)(puVar5 + 3) & 0xffffff0f;
          puVar5[6] = 0;
          KeReleaseSpinLock(puVar1,*(undefined1 *)(puVar5 + 5));
          ndisuioDerefOpen((longlong)puVar5);
          if ((((iVar4 == 0x103) || (iVar4 == -0x7ffffffb)) || (iVar4 == -0x3fffffff)) ||
             ((iVar4 == -0x3fffff66 || (iVar4 == -0x3fffff45)))) {
            iVar7 = iVar4;
          }
          else if (iVar4 == -0x3ffeffea) {
            iVar7 = -0x3fffffdd;
          }
          else if (iVar4 == -0x3ffeffec) {
            iVar7 = -0x3ffffdfa;
          }
          else if (iVar4 == -0x3ffeffeb) {
            iVar7 = -0x3ffffff3;
          }
          else if (iVar4 == -0x3ffefffa) {
            iVar7 = -0x7fffffe6;
          }
          else {
            iVar7 = -0x3fffffff;
            if (iVar4 == -0x3ffeffef) {
              iVar7 = -0x3fffff5d;
            }
          }
        }
      }
      else {
        KeReleaseSpinLock();
        ndisuioDerefOpen((longlong)puVar5);
        iVar7 = -0x3ffffff0;
      }
    }
    else {
      KeReleaseSpinLock(puVar1,CONCAT31(uVar2,uVar3));
      ndisuioDerefOpen((longlong)puVar5);
      iVar7 = -0x7fffffef;
    }
  }
  return iVar7;
}



===== ndisuioOpenDeviceEx @ 1c0001320 =====

int ndisuioOpenDeviceEx(int *param_1,uint param_2,longlong param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  bool bVar8;
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 local_38 [4];
  
  local_res10[0] = 0;
  uVar7 = (ulonglong)param_2;
  if (0xb < param_2) {
    if (*param_1 != 1) {
      return -0x3ffffff3;
    }
    if ((uint)param_1[1] <= param_2 - 8) {
      puVar5 = ndisuioLookupDevice(param_1 + 2,param_1[1]);
      if (puVar5 == (undefined8 *)0x0) {
        return -0x3fffffcc;
      }
      puVar1 = puVar5 + 4;
      uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
      *(undefined1 *)(puVar5 + 5) = uVar3;
      uVar2 = (undefined3)(*(uint *)(puVar5 + 3) >> 8);
      if ((*(uint *)(puVar5 + 3) & 0xf0) != 0) {
        KeReleaseSpinLock(puVar1,CONCAT31(uVar2,uVar3));
        ndisuioDerefOpen((longlong)puVar5);
        return -0x7fffffef;
      }
      LOCK();
      bVar8 = *(longlong *)(param_3 + 0x18) == 0;
      if (bVar8) {
        *(longlong *)(param_3 + 0x18) = (longlong)puVar5;
      }
      UNLOCK();
      uVar6 = (ulonglong)CONCAT31(uVar2,*(undefined1 *)(puVar5 + 5));
      if (!bVar8) {
        KeReleaseSpinLock();
        ndisuioDerefOpen((longlong)puVar5);
        return -0x3ffffff0;
      }
      puVar5[6] = param_3;
      *(uint *)(puVar5 + 3) = *(uint *)(puVar5 + 3) & 0xffffff1f | 0x10;
      KeReleaseSpinLock(puVar1);
      local_38[0] = 0xb;
      iVar4 = ndisuioValidateOpenAndDoRequest
                        ((longlong)puVar5,uVar6,uVar7,local_38,in_stack_ffffffffffffffa8,local_res10
                         ,'\x01');
      if (iVar4 == 0) {
        *(int *)(puVar5 + 7) = *param_1;
        *param_4 = puVar5;
        return 0;
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
      *(undefined1 *)(puVar5 + 5) = uVar3;
      LOCK();
      if (puVar5 == *(undefined8 **)(param_3 + 0x18)) {
        *(longlong *)(param_3 + 0x18) = 0;
      }
      UNLOCK();
      *(uint *)(puVar5 + 3) = *(uint *)(puVar5 + 3) & 0xffffff0f;
      puVar5[6] = 0;
      KeReleaseSpinLock(puVar1,*(undefined1 *)(puVar5 + 5));
      ndisuioDerefOpen((longlong)puVar5);
      if ((((iVar4 == 0x103) || (iVar4 == -0x7ffffffb)) || (iVar4 == -0x3fffffff)) ||
         ((iVar4 == -0x3fffff66 || (iVar4 == -0x3fffff45)))) {
        return iVar4;
      }
      if (iVar4 != -0x3ffeffea) {
        if (iVar4 == -0x3ffeffec) {
          return -0x3ffffdfa;
        }
        if (iVar4 == -0x3ffeffeb) {
          return -0x3ffffff3;
        }
        if (iVar4 == -0x3ffefffa) {
          return -0x7fffffe6;
        }
        if (iVar4 == -0x3ffeffef) {
          return -0x3fffff5d;
        }
        return -0x3fffffff;
      }
    }
  }
  return -0x3fffffdd;
}



===== NdisuioBindAdapter @ 1c0001530 =====

int NdisuioBindAdapter(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  void *pvVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  void *local_res18 [2];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  local_res18[0] = (void *)0x0;
  if ((*(int *)(param_3 + 0x20) == 9) ||
     ((*(int *)(param_3 + 0x8c) == 8 && (*(int *)(param_3 + 0x20) == 0)))) {
    iVar3 = -0x3fffffff;
    if (WwanIsInitialized == '\x01') {
      iVar3 = WwanprotBindAdapter(param_1,param_2,param_3,param_4);
    }
  }
  else {
    NdisAllocateMemoryWithTag(local_res18,0x1f8,0x6f69754e);
    if (local_res18[0] == (void *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      memset(local_res18[0],0,0x1f8);
      KeInitializeSpinLock((longlong)local_res18[0] + 0x20);
      lVar4 = (longlong)local_res18[0] + 0x88;
      *(longlong *)((longlong)local_res18[0] + 0x90) = lVar4;
      *(longlong *)lVar4 = lVar4;
      lVar4 = (longlong)local_res18[0] + 0x70;
      *(longlong *)((longlong)local_res18[0] + 0x78) = lVar4;
      *(longlong *)lVar4 = lVar4;
      lVar4 = (longlong)local_res18[0] + 0xa0;
      *(longlong *)((longlong)local_res18[0] + 0xa8) = lVar4;
      *(longlong *)lVar4 = lVar4;
      NdisInitializeEvent((longlong)local_res18[0] + 0xc0);
      NdisSetEvent((longlong)local_res18[0] + 0xc0);
      LOCK();
      *(int *)((longlong)local_res18[0] + 0x1c) = *(int *)((longlong)local_res18[0] + 0x1c) + 1;
      UNLOCK();
      DAT_1c000d340 = KeAcquireSpinLockRaiseToDpc(&DAT_1c000d338);
      puVar8 = auStack_38;
      puVar7 = &DAT_1c000d328;
      puVar5 = (undefined8 *)((longlong)local_res18[0] + 8);
      puVar6 = DAT_1c000d330;
      if ((undefined8 *)*DAT_1c000d330 != &DAT_1c000d328) {
        puVar6 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        puVar5 = (undefined8 *)(*pcVar2)();
        puVar8 = auStack_30;
      }
      puVar5[1] = puVar6;
      *puVar5 = puVar7;
      *puVar6 = puVar5;
      *(undefined8 *)(puVar8 + -8) = 0x1c0001682;
      DAT_1c000d330 = puVar5;
      KeReleaseSpinLock(&DAT_1c000d338,DAT_1c000d340);
      *(undefined4 *)((longlong)local_res18[0] + 0x124) = 0;
      pvVar1 = *(void **)(*(ushort **)(param_3 + 0x10) + 4);
      *(uint *)(puVar8 + 0x20) = (uint)**(ushort **)(param_3 + 0x10);
      *(undefined8 *)(puVar8 + -8) = 0x1c00016b1;
      iVar3 = ndisuioCreateBinding
                        ((longlong)local_res18[0],param_3,param_2,pvVar1,*(uint *)(puVar8 + 0x20));
    }
  }
  return iVar3;
}



===== NdisuioCloseAdapterComplete @ 1c00016e0 =====

void NdisuioCloseAdapterComplete(int *param_1,undefined8 param_2,undefined8 param_3)

{
  if (((WwanIsInitialized == '\0') || (param_1 == (int *)0x0)) || (*param_1 != 0x1000)) {
    NdisSetEvent(param_1 + 0x42);
  }
  else {
    WwanprotCloseAdapterComplete((longlong)param_1,param_2,param_3);
  }
  return;
}



===== NdisuioOpenAdapterComplete @ 1c0001720 =====

void NdisuioOpenAdapterComplete(int *param_1,int param_2,undefined8 param_3)

{
  if (((WwanIsInitialized == '\0') || (param_1 == (int *)0x0)) || (*param_1 != 0x1000)) {
    param_1[0x41] = param_2;
    NdisSetEvent(param_1 + 0x42);
  }
  else {
    WwanprotOpenAdapterComplete((longlong)param_1,param_2,param_3);
  }
  return;
}



===== NdisuioPnPEventHandler @ 1c0001770 =====

undefined8 NdisuioPnPEventHandler(int *param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  undefined1 uVar6;
  ushort uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  ushort *puVar10;
  undefined8 uVar11;
  uint uVar12;
  bool bVar13;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar11 = 0;
  if ((((param_1 == (int *)0x0) && (WwanIsInitialized != '\0')) ||
      ((WwanIsInitialized != '\0' && ((param_1 != (int *)0x0 && (*param_1 == 0x1000)))))) &&
     (uVar8 = WwanprotPnPEvent((longlong)param_1,param_2), param_1 != (int *)0x0)) {
    return uVar8;
  }
  iVar2 = *(int *)(param_2 + 8);
  if (iVar2 < 6) {
    if (iVar2 == 5) {
      return 0;
    }
    if (iVar2 == 0) {
      piVar1 = param_1 + 8;
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
      *(undefined1 *)(param_1 + 10) = uVar6;
      iVar2 = **(int **)(param_2 + 0x10);
      param_1[0x2e] = iVar2;
      if (iVar2 < 2) {
        NdisSetEvent(param_1 + 0x30,uVar6);
      }
      else {
        *(undefined1 *)(param_1 + 0x36) = 1;
        KeReleaseSpinLock(piVar1);
        NdisInitializeEvent(param_1 + 0x30);
        ndisuioFlushReceiveQueue((longlong)param_1);
        uVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
        *(undefined1 *)(param_1 + 10) = uVar6;
        *(undefined1 *)(param_1 + 0x36) = 0;
      }
      KeReleaseSpinLock(piVar1,(char)param_1[10]);
      return 0;
    }
    if (iVar2 == 1) {
      return 0;
    }
    if (iVar2 == 2) {
      return 0;
    }
    if (iVar2 == 3) {
      return 0;
    }
    bVar13 = iVar2 == 4;
  }
  else {
    if (iVar2 == 6) {
      NdisSetEvent(&DAT_1c000d348);
      return 0;
    }
    if (iVar2 == 7) {
      return 0;
    }
    if (iVar2 == 8) {
      piVar1 = param_1 + 8;
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
      param_1[0x49] = 2;
      while (*(undefined1 *)(param_1 + 10) = uVar6, param_1[0x20] != 0) {
        KeReleaseSpinLock(piVar1,uVar6);
        local_38 = 0;
        uStack_30 = 0;
        local_28 = 0;
        NdisInitializeEvent(&local_38);
        NdisWaitEvent(&local_38,1000);
        uVar6 = KeAcquireSpinLockRaiseToDpc(piVar1);
      }
      KeReleaseSpinLock();
      ndisuioFlushReceiveQueue((longlong)param_1);
      param_1[0x49] = 3;
      return 0;
    }
    if (iVar2 == 9) {
      lVar3 = *(longlong *)(param_2 + 0x10);
      if (lVar3 != 0) {
        puVar10 = *(ushort **)(lVar3 + 8);
        uVar12 = 0;
        if ((puVar10 != (ushort *)0x0) && (*(uint *)(lVar3 + 0x10) != 0)) {
          do {
            uVar7 = *puVar10;
            uVar12 = uVar12 + 2 + (uint)uVar7;
            uVar5 = (uint)uVar7;
            if (0x1ff < uVar7) {
              uVar7 = 0x1ff;
            }
            if (0x3ff < (uVar7 & 0xfffe)) {
              __report_rangecheckfailure();
              pcVar4 = (code *)swi(3);
              uVar11 = (*pcVar4)();
              return uVar11;
            }
            puVar10 = (ushort *)((longlong)puVar10 + (ulonglong)(uVar5 + 2));
          } while (uVar12 < *(uint *)(lVar3 + 0x10));
        }
        for (puVar9 = *(undefined8 **)(lVar3 + 0x18); puVar9 != (undefined8 *)0x0;
            puVar9 = (undefined8 *)*puVar9) {
          if (*(int *)(puVar9 + 1) == 0x1021d) {
            param_1[0x1a] = *(int *)((longlong)puVar9 + 0x2c);
            param_1[0x1b] = *(int *)((longlong)puVar9 + 0x14);
            break;
          }
        }
      }
      param_1[0x49] = 1;
      return 0;
    }
    bVar13 = iVar2 == 0x10;
  }
  if (!bVar13) {
    uVar11 = 0xc00000bb;
  }
  return uVar11;
}



===== NdisuioRequestComplete @ 1c0001a20 =====

void NdisuioRequestComplete(int *param_1,longlong param_2,undefined4 param_3)

{
  if (((WwanIsInitialized == '\0') || (param_1 == (int *)0x0)) || (*param_1 != 0x1000)) {
    *(undefined4 *)(param_2 + 0x110) = param_3;
    NdisSetEvent(param_2 + 0xf8);
  }
  else {
    *(undefined4 *)(param_2 + 0x110) = param_3;
    NdisSetEvent(param_2 + 0xf8);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids);
    }
  }
  return;
}



===== NdisuioStatus @ 1c0001ac0 =====

void NdisuioStatus(int *param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  bool bVar6;
  uint uVar7;
  undefined4 uVar8;
  uint local_res18 [2];
  void *local_res20;
  
  uVar8 = 0;
  bVar2 = false;
  local_res20 = (void *)0x0;
  bVar4 = false;
  bVar3 = false;
  local_res18[0] = 0;
  if (((WwanIsInitialized != '\0') && (param_1 != (int *)0x0)) && (*param_1 == 0x1000)) {
    WwanprotStatus((longlong)param_1,(longlong)param_2,param_3);
    return;
  }
  if (*param_2 != -0x68) {
    return;
  }
  if (*(short *)(param_2 + 2) != 0x70) {
    return;
  }
  iVar1 = *(int *)(param_2 + 0x14);
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(undefined1 *)(param_1 + 10) = uVar5;
  if (iVar1 == 0x40010004) {
    param_1[6] = param_1[6] | 0x100;
    goto LAB_1c0001c42;
  }
  if (iVar1 == 0x40010005) {
    param_1[6] = param_1[6] & 0xfffffeff;
    goto LAB_1c0001c42;
  }
  if (iVar1 == 0x40010017) {
    uVar7 = param_1[6];
    if (*(int *)(*(longlong *)(param_2 + 0x30) + 4) == 1) {
      if (((uVar7 & 0x200) == 0) && ((*(uint *)(param_2 + 0x18) & 0x1000) == 0)) goto LAB_1c0001c42;
      uVar8 = 1;
      param_1[6] = uVar7 & 0xfffffdff;
      if ((uVar7 >> 10 & 1) != 0) {
        bVar4 = true;
        uVar7 = uVar7 & 0xfffff9ff;
        goto LAB_1c0001c0d;
      }
    }
    else {
      if ((uVar7 & 0x200) != 0) goto LAB_1c0001c42;
      uVar7 = uVar7 | 0x200;
      uVar8 = 2;
LAB_1c0001c0d:
      param_1[6] = uVar7;
    }
    bVar6 = ndisuioFillEventData((longlong)param_1,&local_res20,local_res18);
    bVar3 = bVar4;
  }
  else {
    if ((iVar1 != 0x40010023) || ((param_1[0x40] != 0xe && (param_1[0x40] != 0))))
    goto LAB_1c0001c42;
    iVar1 = *(int *)(*(longlong *)(param_2 + 0x30) + 4);
    bVar3 = bVar2;
    if (iVar1 != 1) {
      if ((iVar1 == 5) && ((*(uint *)(*(longlong *)(param_2 + 0x30) + 8) & 8) != 0)) {
        param_1[6] = param_1[6] | 0x400;
      }
      goto LAB_1c0001c42;
    }
    if (((uint)param_1[6] >> 10 & 1) == 0) goto LAB_1c0001c42;
    uVar8 = 1;
    param_1[6] = param_1[6] & 0xfffffbff;
    bVar3 = true;
    bVar6 = ndisuioFillEventData((longlong)param_1,&local_res20,local_res18);
  }
  bVar2 = true;
  if (!bVar6) {
    bVar2 = false;
    bVar3 = bVar4;
  }
LAB_1c0001c42:
  KeReleaseSpinLock(param_1 + 8,(char)param_1[10]);
  if (bVar2) {
    if (bVar3) {
      NdisuioReceiveEvent((longlong)param_1,2,local_res20,local_res18[0]);
    }
    NdisuioReceiveEvent((longlong)param_1,uVar8,local_res20,local_res18[0]);
  }
  if (local_res20 != (void *)0x0) {
    NdisFreeMemory(local_res20,0,0);
  }
  return;
}



===== NdisuioUnbindAdapter @ 1c0001cc0 =====

undefined8 NdisuioUnbindAdapter(undefined8 param_1,int *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  if (((WwanIsInitialized == '\0') || (param_2 == (int *)0x0)) || (*param_2 != 0x1000)) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 8);
    param_2[6] = param_2[6] | 0x10000000;
    *(undefined1 *)(param_2 + 10) = uVar1;
    NdisSetEvent(param_2 + 0x30);
    KeReleaseSpinLock(param_2 + 8,(char)param_2[10]);
    param_2[0x49] = 5;
    ndisuioShutdownBinding((longlong)param_2);
    uVar2 = 0;
  }
  else {
    uVar2 = WwanprotUnbindAdapter((longlong)param_2,param_2,param_3);
  }
  return uVar2;
}



===== ndisuioCreateBinding @ 1c0001d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ndisuioCreateBinding
              (longlong param_1,longlong param_2,undefined8 param_3,void *param_4,uint param_5)

{
  longlong lVar1;
  undefined1 *puVar2;
  uint *puVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 *puVar8;
  longlong lVar9;
  uint uVar10;
  undefined1 auStackY_108 [32];
  undefined4 local_d4;
  undefined4 local_d0;
  uint local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 *local_b8;
  undefined8 uStack_b0;
  undefined4 *local_a8;
  undefined4 *puStack_a0;
  ulonglong local_98;
  void *local_90;
  longlong local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_60;
  undefined2 local_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_108;
  local_98 = local_98 & 0xffffffff00000000;
  local_d4 = 0;
  local_5c = 0x88c7;
  bVar5 = false;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d0 = 0;
  local_b8 = (undefined4 *)0x0;
  uStack_b0 = 0;
  local_cc = 0;
  local_a8 = (undefined4 *)0x0;
  puStack_a0 = (undefined4 *)0x0;
  local_60 = 0x8100888e;
  local_90 = param_4;
  local_88 = param_2;
  local_80 = param_3;
  puVar8 = ndisuioLookupDevice(param_4,param_5);
  lVar1 = param_1 + 0x20;
  puVar2 = (undefined1 *)(param_1 + 0x28);
  puVar3 = (uint *)(param_1 + 0x18);
  if (puVar8 == (undefined8 *)0x0) {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *puVar2 = uVar6;
    if ((*puVar3 & 0x1000000f) != 0) {
      KeReleaseSpinLock(lVar1,uVar6);
      return 0x10003;
    }
    *puVar3 = *puVar3 & 0xfffffff1 | 1;
    KeReleaseSpinLock();
    plVar4 = (longlong *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_2 + 0x8c);
    if (param_5 < 0xfffffffe) {
      NdisAllocateMemoryWithTag(plVar4,param_5 + 2,0x6f69754e);
    }
    else {
      *plVar4 = 0;
    }
    if ((void *)*plVar4 != (void *)0x0) {
      memcpy((void *)*plVar4,local_90,(ulonglong)param_5);
      *(undefined2 *)((ulonglong)param_5 + *plVar4) = 0;
      RtlInitUnicodeString(param_1 + 0xe0,*plVar4);
      local_78 = 0x140180;
      local_6c = 0;
      local_74 = 0x100100;
      local_70 = 0x6f69754e;
      lVar9 = NdisAllocateNetBufferListPool(DAT_1c000d310,&local_78);
      *(longlong *)(param_1 + 0x48) = lVar9;
      if (lVar9 != 0) {
        local_74 = CONCAT22(0x20,(undefined2)local_74);
        lVar9 = NdisAllocateNetBufferListPool(DAT_1c000d310,&local_78);
        *(longlong *)(param_1 + 0x58) = lVar9;
        if (lVar9 != 0) {
          *(undefined4 *)(param_1 + 0xb8) = 1;
          NdisInitializeEvent(param_1 + 0x108);
          lVar9 = local_88;
          local_c8 = 0x380187;
          uStack_b0 = 1;
          local_98 = 3;
          uStack_c0 = *(undefined8 *)(local_88 + 0x10);
          local_b8 = &local_d4;
          local_a8 = &local_d0;
          puStack_a0 = &local_60;
          iVar7 = NdisOpenAdapterEx(DAT_1c000d310,param_1,&local_c8,local_80);
          if (iVar7 == 0x103) {
            NdisWaitEvent(param_1 + 0x108,0);
            iVar7 = *(int *)(param_1 + 0x104);
          }
          if (iVar7 == 0) {
            *(undefined4 *)(param_1 + 0x124) = 3;
            bVar5 = true;
            NdisQueryAdapterInstanceName(param_1 + 0xf0);
            *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(lVar9 + 0x6a);
            *(undefined2 *)(param_1 + 300) = *(undefined2 *)(lVar9 + 0x6e);
            iVar7 = ndisuioDoRequest(param_1,0,0x10113,param_1 + 0x68,4,&local_cc);
            if (iVar7 == 0) {
              *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(lVar9 + 0x24);
              uVar10 = *puVar3 & 0xfffffdff;
              if (*(int *)(lVar9 + 0x48) != 0) {
                uVar10 = *puVar3 | 0x200;
              }
              *puVar3 = uVar10;
              uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
              uVar10 = *puVar3;
              *puVar2 = uVar6;
              *puVar3 = uVar10 & 0xfffffff4 | 4;
              if ((uVar10 >> 0x1c & 1) != 0) {
                iVar7 = -0x3fffffff;
              }
              KeReleaseSpinLock(lVar1,uVar6);
              if (iVar7 == 0) {
                return 0;
              }
            }
          }
          goto LAB_1c0002087;
        }
      }
    }
    iVar7 = -0x3fffff66;
  }
  else {
    ndisuioDerefOpen((longlong)puVar8);
    iVar7 = -0x3fffffff;
  }
LAB_1c0002087:
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar10 = *puVar3;
  *puVar2 = uVar6;
  if (bVar5) {
    uVar10 = uVar10 & 0xfffffff4 | 4;
  }
  else {
    if (((byte)uVar10 & 0xf) != 1) goto LAB_1c00020ba;
    uVar10 = uVar10 & 0xfffffff2 | 2;
  }
  *puVar3 = uVar10;
LAB_1c00020ba:
  KeReleaseSpinLock(lVar1,uVar6);
  ndisuioShutdownBinding(param_1);
  return iVar7;
}



===== ndisuioDoProtocolUnload @ 1c0002110 =====

void ndisuioDoProtocolUnload(void)

{
  if (DAT_1c000d310 != 0) {
    DAT_1c000d310 = 0;
    NdisDeregisterProtocolDriver();
  }
  return;
}



===== ndisuioDoRequest @ 1c0002140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ndisuioDoRequest(longlong param_1,int param_2,undefined4 param_3,undefined8 param_4,uint param_5
                    ,uint *param_6)

{
  int iVar1;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  int local_154;
  undefined4 local_138;
  undefined8 local_130;
  uint local_128;
  uint local_124;
  undefined1 local_60 [24];
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  memset(&local_158,0,0x118);
  NdisInitializeEvent(local_60);
  local_158 = 0xf80196;
  if ((param_2 == 0) || (param_2 == 1)) {
    local_128 = param_5;
    local_138 = param_3;
    local_130 = param_4;
  }
  local_154 = param_2;
  iVar1 = NdisOidRequest(*(undefined8 *)(param_1 + 0x40),&local_158);
  if (iVar1 == 0x103) {
    NdisWaitEvent(local_60,0);
    iVar1 = local_48;
  }
  if ((iVar1 == 0) && (*param_6 = local_124, param_5 < local_124)) {
    *param_6 = param_5;
  }
  return iVar1;
}



===== ndisuioFillEventData @ 1c0002240 =====

bool ndisuioFillEventData(longlong param_1,undefined8 *param_2,uint *param_3)

{
  void *_Dst;
  uint uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0xe0) + 2;
  *param_3 = uVar1;
  NdisAllocateMemoryWithTag(param_2,uVar1,0x6f69754e);
  _Dst = (void *)*param_2;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,(ulonglong)*param_3);
    memcpy((void *)*param_2,*(void **)(param_1 + 0xe8),(ulonglong)*(ushort *)(param_1 + 0xe0));
  }
  return _Dst != (void *)0x0;
}



===== ndisuioLookupDevice @ 1c00022c0 =====

undefined8 * ndisuioLookupDevice(void *param_1,uint param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  DAT_1c000d340 = KeAcquireSpinLockRaiseToDpc(&DAT_1c000d338);
  puVar3 = DAT_1c000d328;
  do {
    puVar2 = (undefined8 *)0x0;
    if ((undefined8 **)puVar3 == &DAT_1c000d328) {
LAB_1c000233e:
      KeReleaseSpinLock(&DAT_1c000d338,DAT_1c000d340);
      return puVar2;
    }
    puVar2 = puVar3 + -1;
    if ((*(ushort *)(puVar3 + 0x1b) == param_2) &&
       (iVar1 = memcmp((void *)puVar3[0x1c],param_1,(ulonglong)param_2), iVar1 == 0)) {
      LOCK();
      *(int *)((longlong)puVar3 + 0x14) = *(int *)((longlong)puVar3 + 0x14) + 1;
      UNLOCK();
      goto LAB_1c000233e;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== ndisuioQueryBinding @ 1c000237c =====

undefined8 ndisuioQueryBinding(int *param_1,uint param_2,uint param_3,int *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 *puVar8;
  
  if (param_2 < 0x14) {
    uVar6 = 0xc000009a;
  }
  else if (param_3 < 0x14) {
    uVar6 = 0x80000005;
  }
  else {
    iVar7 = *param_1;
    uVar6 = 0xc0010006;
    DAT_1c000d340 = KeAcquireSpinLockRaiseToDpc(&DAT_1c000d338);
    for (puVar8 = DAT_1c000d328; (undefined8 **)puVar8 != &DAT_1c000d328;
        puVar8 = (undefined8 *)*puVar8) {
      puVar1 = puVar8 + 3;
      uVar5 = KeAcquireSpinLockRaiseToDpc(puVar1);
      *(undefined1 *)(puVar8 + 4) = uVar5;
      if (((byte)*(undefined4 *)(puVar8 + 2) & 0xf) == 4) {
        if (iVar7 == 0) {
          uVar3 = *(ushort *)(puVar8 + 0x1b);
          param_1[2] = uVar3 + 2;
          uVar4 = *(ushort *)(puVar8 + 0x1d);
          param_1[4] = uVar4 + 2;
          uVar2 = uVar4 + 2 + uVar3 + 2;
          if (param_3 - 0x14 < uVar2) {
            KeReleaseSpinLock(puVar1,CONCAT31((int3)(uVar2 >> 8),*(undefined1 *)(puVar8 + 4)));
            uVar6 = 0x80000005;
          }
          else {
            memset(param_1 + 5,0,(ulonglong)uVar2);
            param_1[1] = 0x14;
            memcpy(param_1 + 5,(void *)puVar8[0x1c],(ulonglong)*(ushort *)(puVar8 + 0x1b));
            param_1[3] = param_1[2] + param_1[1];
            memcpy((void *)((ulonglong)(uint)(param_1[2] + param_1[1]) + (longlong)param_1),
                   (void *)puVar8[0x1e],(ulonglong)*(ushort *)(puVar8 + 0x1d));
            KeReleaseSpinLock(puVar1,*(undefined1 *)(puVar8 + 4));
            *param_4 = param_1[4] + param_1[3];
            uVar6 = 0;
          }
          break;
        }
        KeReleaseSpinLock(puVar1,uVar5);
        iVar7 = iVar7 + -1;
      }
      else {
        KeReleaseSpinLock(puVar1);
      }
    }
    KeReleaseSpinLock(&DAT_1c000d338,DAT_1c000d340);
  }
  return uVar6;
}



===== ndisuioQueryOidValue @ 1c0002534 =====

int ndisuioQueryOidValue(longlong param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (param_3 < 8) {
    iVar4 = -0x3ffeffea;
  }
  else {
    uVar2 = *param_2;
    lVar1 = param_1 + 0x20;
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x28) = uVar3;
    if (((byte)*(undefined4 *)(param_1 + 0x18) & 0xf) == 4) {
      LOCK();
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
      UNLOCK();
      KeReleaseSpinLock(lVar1);
      iVar4 = ndisuioDoRequest(param_1,0,uVar2,param_2 + 1,param_3 - 4,param_4);
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined1 *)(param_1 + 0x28) = uVar3;
      LOCK();
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
      UNLOCK();
      KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
      if (iVar4 == 0) {
        *param_4 = *param_4 + 4;
      }
    }
    else {
      KeReleaseSpinLock(lVar1,uVar3);
      iVar4 = -0x3fffffff;
    }
  }
  return iVar4;
}



===== ndisuioSetOidValue @ 1c000262c =====

int ndisuioSetOidValue(longlong param_1,int *param_2,uint param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint local_res18 [4];
  
  uVar3 = 0;
  local_res18[0] = 0;
  if (param_3 < 8) {
    iVar4 = -0x3ffeffea;
  }
  else {
    iVar4 = *param_2;
    piVar5 = &ndisuioSupportedSetOids;
    do {
      if (*piVar5 == iVar4) {
        lVar1 = param_1 + 0x20;
        uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
        *(undefined1 *)(param_1 + 0x28) = uVar2;
        if (((byte)*(undefined4 *)(param_1 + 0x18) & 0xf) == 4) {
          LOCK();
          *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
          UNLOCK();
          KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
          iVar4 = ndisuioDoRequest(param_1,1,iVar4,param_2 + 1,param_3 - 4,local_res18);
          uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
          *(undefined1 *)(param_1 + 0x28) = uVar2;
          LOCK();
          *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
          UNLOCK();
          KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
          return iVar4;
        }
        KeReleaseSpinLock(lVar1,uVar2);
        return -0x3fffffff;
      }
      uVar3 = uVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar3 < 0x19);
    iVar4 = -0x3ffeffeb;
  }
  return iVar4;
}



===== ndisuioShutdownBinding @ 1c000273c =====

void ndisuioShutdownBinding(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar1 = param_1 + 0x20;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar8 = *(uint *)(param_1 + 0x18);
  uVar7 = uVar8 & 0xf;
  *(undefined1 *)(param_1 + 0x28) = uVar5;
  if (uVar7 == 1) {
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar8 >> 8),uVar5));
  }
  else {
    if (uVar7 == 4) {
      uVar8 = uVar8 & 0xfffffff8 | 8;
      *(uint *)(param_1 + 0x18) = uVar8;
    }
    KeReleaseSpinLock(lVar1,CONCAT31((int3)(uVar8 >> 8),uVar5));
    if (uVar7 == 4) {
      local_res10[0] = 0;
      local_res8[0] = 0;
      ndisuioDoRequest(param_1,1,0x1010e,local_res10,4,local_res8);
      ndisuioDoRequest(param_1,1,0x1010103,0,0,local_res8);
      uVar8 = 0;
      do {
        if ((*(int *)(param_1 + 0x80) == 0) && (*(int *)(param_1 + 0x84) == 0)) break;
        local_38 = 0;
        uStack_30 = 0;
        local_28 = 0;
        NdisInitializeEvent(&local_38);
        NdisWaitEvent(&local_38,1000);
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0x3c);
      while (*(int *)(param_1 + 0x98) != 0) {
        ndisuioCancelPendingReads(param_1);
        local_38 = 0;
        uStack_30 = 0;
        local_28 = 0;
        NdisInitializeEvent(&local_38);
        NdisWaitEvent(&local_38,1000);
      }
      ndisuioFlushReceiveQueue(param_1);
      NdisInitializeEvent(param_1 + 0x108);
      iVar6 = NdisCloseAdapterEx(*(undefined8 *)(param_1 + 0x40));
      if (iVar6 == 0x103) {
        NdisWaitEvent(param_1 + 0x108,0);
      }
      *(undefined8 *)(param_1 + 0x40) = 0;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xeffffff0;
      *(undefined1 *)(param_1 + 0x28) = uVar5;
      KeReleaseSpinLock(lVar1,uVar5);
    }
    DAT_1c000d340 = KeAcquireSpinLockRaiseToDpc(&DAT_1c000d338);
    plVar2 = (longlong *)(param_1 + 8);
    lVar1 = *plVar2;
    if ((*(longlong **)(lVar1 + 8) != plVar2) ||
       (plVar3 = *(longlong **)(param_1 + 0x10), (longlong *)*plVar3 != plVar2)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar3;
    KeReleaseSpinLock(&DAT_1c000d338,CONCAT71((int7)((ulonglong)plVar3 >> 8),DAT_1c000d340));
    if (*(longlong *)(param_1 + 0x48) != 0) {
      NdisFreeNetBufferListPool();
      *(undefined8 *)(param_1 + 0x48) = 0;
    }
    if (*(longlong *)(param_1 + 0x58) != 0) {
      NdisFreeNetBufferListPool();
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    if (*(longlong *)(param_1 + 0xe8) != 0) {
      NdisFreeMemory(*(longlong *)(param_1 + 0xe8),0,0);
      *(undefined8 *)(param_1 + 0xe8) = 0;
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    if (*(longlong *)(param_1 + 0xf8) != 0) {
      NdisFreeMemory(*(longlong *)(param_1 + 0xf8),0,0);
      *(undefined8 *)(param_1 + 0xf8) = 0;
    }
    ndisuioDerefOpen(param_1);
  }
  return;
}



===== ndisuioValidateOpenAndDoRequest @ 1c0002a18 =====

int ndisuioValidateOpenAndDoRequest
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,uint *param_6,char param_7)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return -0x3ffeffeb;
  }
  lVar1 = param_1 + 0x20;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x28) = uVar2;
  if ((((byte)*(undefined4 *)(param_1 + 0x18) & 0xf) != 4) || (*(char *)(param_1 + 0xd8) == '\x01'))
  {
    KeReleaseSpinLock(lVar1,uVar2);
    return -0x3ffeffeb;
  }
  LOCK();
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
  UNLOCK();
  if (*(int *)(param_1 + 0xb8) < 2) {
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
  }
  else {
    KeReleaseSpinLock();
    if (param_7 == '\0') {
      iVar3 = -0x3ffeffef;
      goto LAB_1c0002b3b;
    }
    NdisWaitEvent(param_1 + 0xc0,0);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x28) = uVar2;
  if ((*(uint *)(param_1 + 0x18) & 0x10000000) != 0) {
    LOCK();
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
    UNLOCK();
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
    return -0x3fffffff;
  }
  KeReleaseSpinLock(lVar1,uVar2);
  iVar3 = ndisuioDoRequest(param_1,1,0x1010e,param_4,4,param_6);
LAB_1c0002b3b:
  LOCK();
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
  UNLOCK();
  return iVar3;
}



===== NdisuioCancelRead @ 1c0002b60 =====

void NdisuioCancelRead(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  lVar1 = param_2[0xf];
  bVar4 = false;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x20);
  puVar7 = (undefined8 *)(lVar1 + 0x88);
  *(undefined1 *)(lVar1 + 0x28) = uVar5;
  puVar6 = (undefined8 *)*puVar7;
  do {
    if (puVar6 == puVar7) {
LAB_1c0002bc0:
      KeReleaseSpinLock(lVar1 + 0x20,
                        CONCAT71((int7)((ulonglong)puVar7 >> 8),*(undefined1 *)(lVar1 + 0x28)));
      if (bVar4) {
        param_2[7] = 0;
        *(undefined4 *)(param_2 + 6) = 0xc0000120;
        IofCompleteRequest(param_2,0);
        ndisuioDerefOpen(lVar1);
      }
      return;
    }
    if (param_2 == puVar6 + -0x15) {
      puVar6 = param_2 + 0x15;
      puVar7 = (undefined8 *)*puVar6;
      if (((undefined8 *)puVar7[1] != puVar6) ||
         (puVar2 = (undefined8 *)param_2[0x16], (undefined8 *)*puVar2 != puVar6)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar7;
      bVar4 = true;
      puVar7[1] = puVar2;
      *(int *)(lVar1 + 0x98) = *(int *)(lVar1 + 0x98) + -1;
      goto LAB_1c0002bc0;
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== NdisuioRead @ 1c0002c50 =====

undefined4 NdisuioRead(longlong param_1,longlong param_2,undefined *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined4 local_18;
  undefined4 local_10;
  
  if (((WwanIsInitialized != '\0') && (WwanGlobals != (longlong *)0x0)) && (*WwanGlobals == param_1)
     ) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_3 = &WPP_fee82b5a0d1433c7bfba478752b9252b_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_fee82b5a0d1433c7bfba478752b9252b_Traceguids);
    }
    WwanAssertFailed("NdisuioRead",0x3d,param_3);
    return 0xc00000bb;
  }
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (lVar2 != 0) {
    lVar5 = *(longlong *)(param_2 + 8);
    if (lVar5 == 0) {
      uVar9 = 0xc000000d;
      goto LAB_1c0002d73;
    }
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      local_10 = 0x40000010;
      local_18 = 0;
      lVar5 = MmMapLockedPagesSpecifyCache(lVar5,0,1);
    }
    else {
      lVar5 = *(longlong *)(lVar5 + 0x18);
    }
    if ((lVar5 == 0) ||
       ((*(int *)(lVar2 + 0x38) != 0 && (*(uint *)(*(longlong *)(param_2 + 8) + 0x28) < 8)))) {
      uVar9 = 0xc000009a;
      goto LAB_1c0002d73;
    }
    lVar5 = lVar2 + 0x20;
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar5);
    puVar10 = auStack_38;
    *(undefined1 *)(lVar2 + 0x28) = uVar4;
    if (((byte)*(undefined4 *)(lVar2 + 0x18) & 0xf) == 4) {
      lVar6 = lVar2 + 0x88;
      plVar7 = *(longlong **)(lVar2 + 0x90);
      plVar8 = (longlong *)(param_2 + 0xa8);
      if (*plVar7 != lVar6) {
        plVar7 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        lVar6 = (*pcVar3)();
        puVar10 = auStack_30;
      }
      *plVar8 = lVar6;
      plVar8[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar8;
      *(longlong **)(lVar6 + 8) = plVar8;
      LOCK();
      *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
      UNLOCK();
      *(int *)(lVar2 + 0x98) = *(int *)(lVar2 + 0x98) + 1;
      *(longlong *)(param_2 + 0x78) = lVar2;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      LOCK();
      *(code **)(param_2 + 0x68) = NdisuioCancelRead;
      UNLOCK();
      uVar4 = *(undefined1 *)(lVar2 + 0x28);
      *(undefined8 *)(puVar10 + -8) = 0x1c0002deb;
      KeReleaseSpinLock(lVar5,uVar4);
      *(undefined8 *)(puVar10 + -8) = 0x1c0002dfd;
      ndisuioServiceReads(lVar2);
      return 0x103;
    }
    KeReleaseSpinLock(lVar5,uVar4);
  }
  uVar9 = 0xc0000008;
LAB_1c0002d73:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar9;
  IofCompleteRequest(param_2,0);
  return uVar9;
}



===== NdisuioReceiveEvent @ 1c0002e18 =====

undefined8 NdisuioReceiveEvent(longlong param_1,undefined4 param_2,void *param_3,uint param_4)

{
  ulonglong _Size;
  longlong lVar1;
  undefined8 *puVar2;
  void *local_38 [2];
  
  _Size = (ulonglong)param_4;
  local_38[0] = (void *)0x0;
  lVar1 = 0;
  if (param_4 != 0) {
    NdisAllocateMemoryWithTag(local_38,_Size,0x6f69754e);
    if (local_38[0] == (void *)0x0) {
      return 0xc000009a;
    }
    lVar1 = NdisAllocateMdl(*(undefined8 *)(param_1 + 0x40),local_38[0],_Size);
    if (lVar1 == 0) goto LAB_1c0002ec9;
  }
  puVar2 = (undefined8 *)
           NdisAllocateNetBufferAndNetBufferList
                     (*(undefined8 *)(param_1 + 0x58),0x20,0,lVar1,0,_Size);
  if (puVar2 != (undefined8 *)0x0) {
    *(undefined4 *)((ulonglong)*(ushort *)(puVar2[2] + 10) + 0x28 + puVar2[2]) = param_2;
    *(uint *)(puVar2 + 0x11) = *(uint *)(puVar2 + 0x11) | 0x10000000;
    if (param_4 != 0) {
      memcpy(local_38[0],param_3,_Size);
    }
    ndisuioQueueEventNetBufferList(param_1,puVar2);
    return 0;
  }
  if (lVar1 != 0) {
    NdisFreeMdl(lVar1);
  }
LAB_1c0002ec9:
  if (local_38[0] != (void *)0x0) {
    NdisFreeMemory(local_38[0],0,0);
  }
  return 0xc000009a;
}



===== NdisuioReceiveNetBufferLists @ 1c0002f50 =====

void NdisuioReceiveNetBufferLists
               (int *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,byte param_5)

{
  uint uVar1;
  ushort *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  ushort uVar10;
  byte bVar11;
  ulonglong in_stack_ffffffffffffff98;
  undefined8 *local_50;
  longlong local_48 [2];
  undefined8 *local_38;
  
  local_48[1] = 0;
  puVar4 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  if (((WwanIsInitialized != '\0') && (param_1 != (int *)0x0)) && (*param_1 == 0x1000)) {
    return;
  }
  bVar11 = param_5 & 1;
  if (1 < param_1[0x49] - 2U) {
    if (param_2 == (undefined8 *)0x0) {
      return;
    }
    puVar8 = param_2;
    param_2 = (undefined8 *)0x0;
LAB_1c0002fca:
    *(uint *)(puVar8 + 0x11) = *(uint *)(puVar8 + 0x11) & 0xffffc;
    local_38 = (undefined8 *)*puVar8;
    lVar3 = puVar8[1];
    uVar1 = *(uint *)(lVar3 + 0x18);
    uVar6 = *(uint *)(lVar3 + 0x28);
    for (puVar9 = *(undefined8 **)(lVar3 + 0x20); puVar9 != (undefined8 *)0x0;
        puVar9 = (undefined8 *)*puVar9) {
      if (uVar6 < *(uint *)(puVar9 + 5)) {
        *(undefined8 **)(puVar8[1] + 8) = puVar9;
        *(uint *)(puVar8[1] + 0x10) = uVar6;
        if ((*(byte *)((longlong)puVar9 + 10) & 5) == 0) {
          in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
          lVar3 = MmMapLockedPagesSpecifyCache(puVar9,0,1,0,in_stack_ffffffffffffff98,0x40000010);
        }
        else {
          lVar3 = puVar9[3];
        }
        if ((lVar3 != 0) && (uVar6 < *(uint *)(puVar9 + 5))) {
          uVar7 = *(uint *)(puVar9 + 5) - uVar6;
          if (0xd < uVar7) {
            uVar10 = *(ushort *)(lVar3 + (ulonglong)uVar6 + 0xc);
            if (uVar10 == 0x81) {
              if (uVar7 < 0x12) goto LAB_1c00031bf;
              uVar10 = (ushort)*(byte *)(lVar3 + (ulonglong)uVar6 + 0x10);
            }
            uVar6 = 0;
            puVar2 = &DAT_1c000d318;
            goto LAB_1c0003097;
          }
        }
        break;
      }
      uVar6 = uVar6 - *(uint *)(puVar9 + 5);
    }
    goto LAB_1c00031c4;
  }
  if ((param_5 & 2) != 0) {
    return;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x10);
LAB_1c000320c:
  NdisReturnNetBufferLists(uVar5,param_2,bVar11);
  return;
  while( true ) {
    uVar6 = uVar6 + 1;
    puVar2 = puVar2 + 1;
    if (1 < uVar6) break;
LAB_1c0003097:
    if (uVar10 == *puVar2) {
      puVar4 = (undefined8 *)0x0;
      local_48[0] = 0;
      NdisAllocateMemoryWithTag(local_48,uVar1,0x6f69754e);
      if (local_48[0] == 0) break;
      lVar3 = NdisAllocateMdl(*(undefined8 *)(param_1 + 0x10),local_48[0],uVar1);
      if (lVar3 == 0) {
LAB_1c0003145:
        if ((local_48[0] == 0) || (NdisFreeMemory(local_48[0],0,0), puVar4 == (undefined8 *)0x0))
        break;
      }
      else {
        in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
        puVar4 = (undefined8 *)
                 NdisAllocateNetBufferAndNetBufferList
                           (*(undefined8 *)(param_1 + 0x16),0x20,0,lVar3,in_stack_ffffffffffffff98,
                            uVar1);
        if (puVar4 == (undefined8 *)0x0) {
          NdisFreeMdl(lVar3);
          goto LAB_1c0003145;
        }
        *(undefined4 *)((ulonglong)*(ushort *)(puVar4[2] + 10) + 0x28 + puVar4[2]) = 0;
      }
      *(uint *)(puVar4 + 0x11) = *(uint *)(puVar4 + 0x11) | 0x10000000;
      *(ushort *)((ulonglong)*(ushort *)(puVar4[2] + 10) + 0x2c + puVar4[2]) = uVar10;
      in_stack_ffffffffffffff98 = (ulonglong)uVar1;
      uVar5 = ndisuioCopyMdlToMdl(*(undefined8 **)(puVar8[1] + 8),
                                  (ulonglong)*(uint *)(puVar8[1] + 0x10),
                                  *(undefined8 **)(puVar4[1] + 0x20),local_48 + 1,
                                  in_stack_ffffffffffffff98,(ulonglong *)(local_48 + 1));
      if ((int)uVar5 == 0) {
        ndisuioQueueReceiveNetBufferList((longlong)param_1,puVar4,bVar11);
      }
      else {
        ndisuioFreeNetBufferList((longlong)param_1,puVar4,bVar11);
      }
      break;
    }
  }
LAB_1c00031bf:
  puVar4 = local_50;
LAB_1c00031c4:
  if ((param_5 & 2) == 0) {
    if (param_2 == (undefined8 *)0x0) {
      param_2 = puVar8;
    }
    else {
      *puVar4 = puVar8;
    }
    *puVar8 = 0;
    puVar4 = puVar8;
    local_50 = puVar8;
  }
  puVar8 = local_38;
  if (local_38 == (undefined8 *)0x0) goto code_r0x0001c00031f4;
  goto LAB_1c0002fca;
code_r0x0001c00031f4:
  if (param_2 == (undefined8 *)0x0) {
    return;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  goto LAB_1c000320c;
}



===== WPP_SF_ @ 1c0003240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== ndisuioCancelPendingReads @ 1c000326c =====

void ndisuioCancelPendingReads(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  LOCK();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  UNLOCK();
  lVar1 = param_1 + 0x20;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar8 = auStack_48;
LAB_1c00032a2:
  do {
    *(undefined1 *)(param_1 + 0x28) = uVar6;
    plVar3 = *(longlong **)(param_1 + 0x88);
    if (plVar3 == (longlong *)(param_1 + 0x88)) {
LAB_1c0003398:
      *(undefined8 *)(puVar8 + -8) = 0x1c00033a4;
      KeReleaseSpinLock(lVar1,uVar6);
      *(undefined8 *)(puVar8 + -8) = 0x1c00033b1;
      ndisuioDerefOpen(param_1);
      return;
    }
    LOCK();
    lVar2 = plVar3[-8];
    plVar3[-8] = 0;
    UNLOCK();
    uVar7 = (undefined7)((ulonglong)plVar3 >> 8);
    if (lVar2 != 0) {
      lVar2 = *plVar3;
      if (((longlong *)*(longlong *)(lVar2 + 8) != plVar3) ||
         (plVar4 = (longlong *)plVar3[1], (longlong *)*plVar4 != plVar3)) {
        pcVar5 = (code *)swi(0x29);
        uVar6 = (*pcVar5)(3);
        puVar8 = auStack_40;
        goto LAB_1c0003398;
      }
      *plVar4 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      KeReleaseSpinLock(lVar1,CONCAT71(uVar7,*(undefined1 *)(param_1 + 0x28)));
      plVar3[-0xe] = 0;
      *(undefined4 *)(plVar3 + -0xf) = 0xc0000120;
      IofCompleteRequest(plVar3 + -0x15,0);
      ndisuioDerefOpen(param_1);
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
      goto LAB_1c00032a2;
    }
    KeReleaseSpinLock(lVar1,CONCAT71(uVar7,*(undefined1 *)(param_1 + 0x28)));
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    NdisInitializeEvent(&local_28);
    NdisWaitEvent(&local_28,1000);
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  } while( true );
}



===== ndisuioCopyMdlToMdl @ 1c00033d0 =====

undefined8
ndisuioCopyMdlToMdl(undefined8 *param_1,ulonglong param_2,undefined8 *param_3,undefined8 param_4,
                   ulonglong param_5,ulonglong *param_6)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  void *_Src;
  ulonglong uVar6;
  ulonglong local_res20;
  
  uVar6 = 0;
  for (; (param_1 != (undefined8 *)0x0 && (*(uint *)(param_1 + 5) <= param_2));
      param_1 = (undefined8 *)*param_1) {
    param_2 = param_2 - *(uint *)(param_1 + 5);
  }
  for (; (param_3 != (undefined8 *)0x0 && (*(uint *)(param_3 + 5) <= uVar6));
      param_3 = (undefined8 *)*param_3) {
    uVar6 = uVar6 - *(uint *)(param_3 + 5);
  }
  if (((param_5 == 0) || (param_1 == (undefined8 *)0x0)) || (param_3 == (undefined8 *)0x0)) {
    *param_6 = 0;
LAB_1c0003600:
    uVar3 = 0;
  }
  else {
    local_res20 = param_5;
    uVar4 = *(uint *)(param_1 + 5) - param_2;
    if (param_5 < *(uint *)(param_1 + 5) - param_2) {
      uVar4 = param_5;
    }
    if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000000);
    }
    else {
      lVar2 = param_1[3];
    }
    if (lVar2 != 0) {
      _Src = (void *)(lVar2 + param_2);
      uVar5 = *(uint *)(param_3 + 5) - uVar6;
      if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
        lVar2 = MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
      }
      else {
        lVar2 = param_3[3];
      }
      if (lVar2 != 0) {
        _Dst = (void *)(lVar2 + uVar6);
LAB_1c00034e6:
        do {
          uVar6 = uVar5;
          if (uVar4 <= uVar5) {
            uVar6 = uVar4;
          }
          memcpy(_Dst,_Src,uVar6);
          if (local_res20 == uVar6) goto LAB_1c00035e7;
          local_res20 = local_res20 - uVar6;
          if (uVar5 == uVar6) {
            do {
              param_3 = (undefined8 *)*param_3;
              if (param_3 == (undefined8 *)0x0) goto LAB_1c00035e4;
              uVar5 = (ulonglong)*(uint *)(param_3 + 5);
            } while (uVar5 == 0);
            if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
              _Dst = (void *)MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000000);
            }
            else {
              _Dst = (void *)param_3[3];
            }
            if (_Dst == (void *)0x0) break;
          }
          else {
            _Dst = (void *)((longlong)_Dst + uVar6);
            uVar5 = uVar5 - uVar6;
          }
          if (uVar4 == uVar6) goto LAB_1c0003581;
          _Src = (void *)((longlong)_Src + uVar6);
          uVar4 = uVar4 - uVar6;
        } while( true );
      }
    }
LAB_1c000356c:
    uVar3 = 0xc000009a;
  }
  return uVar3;
LAB_1c0003581:
  do {
    param_1 = (undefined8 *)*param_1;
    if (param_1 == (undefined8 *)0x0) goto LAB_1c00035e4;
    uVar1 = *(uint *)(param_1 + 5);
  } while (uVar1 == 0);
  uVar4 = local_res20;
  if (uVar1 <= local_res20) {
    uVar4 = (ulonglong)uVar1;
  }
  if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
    _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000000);
  }
  else {
    _Src = (void *)param_1[3];
  }
  if (_Src == (void *)0x0) goto LAB_1c000356c;
  goto LAB_1c00034e6;
LAB_1c00035e4:
  param_5 = param_5 - local_res20;
LAB_1c00035e7:
  *param_6 = param_5;
  goto LAB_1c0003600;
}



===== ndisuioFlushReceiveQueue @ 1c0003628 =====

void ndisuioFlushReceiveQueue(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  UNLOCK();
  lVar1 = param_1 + 0x20;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  puVar8 = auStack_28;
  do {
    *(undefined1 *)(param_1 + 0x28) = uVar7;
    plVar2 = *(longlong **)(param_1 + 0xa0);
    if (plVar2 == (longlong *)(param_1 + 0xa0)) {
LAB_1c00036f3:
      *(undefined8 *)(puVar8 + -8) = 0x1c00036ff;
      KeReleaseSpinLock(lVar1,uVar7);
      *(undefined8 *)(puVar8 + -8) = 0x1c000370c;
      ndisuioDerefOpen(param_1);
      return;
    }
    lVar3 = *plVar2;
    if (((longlong *)*(longlong *)(lVar3 + 8) != plVar2) ||
       (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
      pcVar6 = (code *)swi(0x29);
      uVar7 = (*pcVar6)(3);
      puVar8 = auStack_20;
      goto LAB_1c00036f3;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    puVar5 = (undefined8 *)plVar2[2];
    lVar3 = puVar5[2];
    if (*(int *)((ulonglong)*(ushort *)(lVar3 + 10) + 0x28 + lVar3) == 0) {
      *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
    }
    else {
      *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -1;
    }
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x28));
    plVar2[2] = 0;
    ndisuioFreeNetBufferList(param_1,puVar5,0);
    ndisuioDerefOpen(param_1);
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  } while( true );
}



===== ndisuioFreeNetBufferList @ 1c0003730 =====

void ndisuioFreeNetBufferList(longlong param_1,undefined8 *param_2,undefined1 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if ((*(uint *)(param_2 + 0x11) & 0x10000000) == 0) {
    *param_2 = 0;
    NdisReturnNetBufferLists(*(undefined8 *)(param_1 + 0x40),param_2,param_3);
  }
  else {
    lVar1 = *(longlong *)(param_2[1] + 0x20);
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      uVar2 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
    }
    else {
      uVar2 = *(undefined8 *)(lVar1 + 0x18);
    }
    NdisFreeNetBufferList(param_2);
    NdisFreeMdl(lVar1);
    NdisFreeMemory(uVar2,0,0);
  }
  return;
}



===== ndisuioQueueEventNetBufferList @ 1c00037f0 =====

void ndisuioQueueEventNetBufferList(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined7 uVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar10 = (undefined8 *)0x0;
  plVar11 = (longlong *)(param_2[2] + 0x10 + (ulonglong)*(ushort *)(param_2[2] + 10));
  LOCK();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  UNLOCK();
  lVar1 = param_1 + 0x20;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x28) = uVar6;
  puVar9 = auStack_28;
  if (((1 < *(int *)(param_1 + 0x124) - 2U) &&
      (puVar9 = auStack_28, ((byte)*(undefined4 *)(param_1 + 0x18) & 0xf) == 4)) &&
     (puVar9 = auStack_28, *(int *)(param_1 + 0xb8) == 1)) {
    plVar2 = (longlong *)(param_1 + 0xa0);
    plVar3 = *(longlong **)(param_1 + 0xa8);
    if ((longlong *)*plVar3 == plVar2) {
      plVar11[1] = (longlong)plVar3;
      *plVar11 = (longlong)plVar2;
      *plVar3 = (longlong)plVar11;
      *(longlong **)(param_1 + 0xa8) = plVar11;
      plVar11[2] = (longlong)param_2;
      uVar7 = *(int *)(param_1 + 0xb4) + 1;
      *(uint *)(param_1 + 0xb4) = uVar7;
      uVar8 = (undefined7)((ulonglong)plVar2 >> 8);
      if (uVar7 < 0x11) {
        KeReleaseSpinLock(lVar1,CONCAT71(uVar8,*(undefined1 *)(param_1 + 0x28)));
LAB_1c000391d:
        ndisuioServiceReads(param_1);
        return;
      }
      plVar11 = (longlong *)*plVar2;
      while ((plVar11 != plVar2 &&
             (puVar10 = (undefined8 *)plVar11[2],
             *(int *)((ulonglong)*(ushort *)(puVar10[2] + 10) + 0x28 + puVar10[2]) == 0))) {
        plVar11 = (longlong *)*plVar11;
      }
      lVar4 = *plVar11;
      if ((*(longlong **)(lVar4 + 8) == plVar11) &&
         (plVar2 = (longlong *)plVar11[1], (longlong *)*plVar2 == plVar11)) {
        *plVar2 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar2;
        *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -1;
        KeReleaseSpinLock(lVar1,CONCAT71(uVar8,*(undefined1 *)(param_1 + 0x28)));
        ndisuioFreeNetBufferList(param_1,puVar10,0);
        ndisuioDerefOpen(param_1);
        goto LAB_1c000391d;
      }
    }
    pcVar5 = (code *)swi(0x29);
    uVar6 = (*pcVar5)(3);
    puVar9 = auStack_20;
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c000393a;
  KeReleaseSpinLock(lVar1,uVar6);
  *(undefined8 *)(puVar9 + -8) = 0x1c000394d;
  ndisuioFreeNetBufferList(param_1,param_2,0);
  *(undefined8 *)(puVar9 + -8) = 0x1c0003955;
  ndisuioDerefOpen(param_1);
  return;
}



===== ndisuioQueueReceiveNetBufferList @ 1c0003978 =====

void ndisuioQueueReceiveNetBufferList(longlong param_1,undefined8 *param_2,char param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined7 uVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar12 = (undefined8 *)0x0;
  LOCK();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  UNLOCK();
  lVar1 = param_1 + 0x20;
  plVar10 = (longlong *)(param_1 + 0x28);
  if (param_3 == '\x01') {
    KeAcquireSpinLockAtDpcLevel();
  }
  else {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)plVar10 = uVar6;
  }
  if (*(int *)(param_1 + 0x124) - 2U < 2) {
    if (param_3 == '\x01') {
      KeReleaseSpinLockFromDpcLevel();
    }
    else {
      KeReleaseSpinLock(lVar1,*(undefined1 *)plVar10);
    }
    ndisuioFreeNetBufferList(param_1,param_2,param_3);
    return;
  }
  puVar9 = auStack_38;
  if ((((byte)*(undefined4 *)(param_1 + 0x18) & 0xf) == 4) &&
     (puVar9 = auStack_38, *(int *)(param_1 + 0xb8) == 1)) {
    plVar2 = (longlong *)(param_1 + 0xa0);
    plVar11 = (longlong *)(param_2[2] + 0x10 + (ulonglong)*(ushort *)(param_2[2] + 10));
    puVar3 = *(undefined8 **)(param_1 + 0xa8);
    if ((longlong *)*puVar3 == plVar2) {
      plVar11[1] = (longlong)puVar3;
      *plVar11 = (longlong)plVar2;
      *puVar3 = plVar11;
      *(longlong **)(param_1 + 0xa8) = plVar11;
      plVar11[2] = (longlong)param_2;
      uVar7 = *(int *)(param_1 + 0xb0) + 1;
      *(uint *)(param_1 + 0xb0) = uVar7;
      uVar8 = (undefined7)((ulonglong)plVar2 >> 8);
      if (uVar7 < 5) {
        if (param_3 == '\x01') {
          KeReleaseSpinLockFromDpcLevel();
        }
        else {
          KeReleaseSpinLock(lVar1,CONCAT71(uVar8,*(undefined1 *)(param_1 + 0x28)));
        }
LAB_1c0003b0c:
        ndisuioServiceReads(param_1);
        return;
      }
      plVar10 = (longlong *)*plVar2;
      while ((plVar10 != plVar2 &&
             (puVar12 = (undefined8 *)plVar10[2],
             *(int *)((ulonglong)*(ushort *)(puVar12[2] + 10) + 0x28 + puVar12[2]) != 0))) {
        plVar10 = (longlong *)*plVar10;
      }
      lVar4 = *plVar10;
      if ((*(longlong **)(lVar4 + 8) == plVar10) &&
         (plVar2 = (longlong *)plVar10[1], (longlong *)*plVar2 == plVar10)) {
        *plVar2 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar2;
        if (*(int *)((ulonglong)*(ushort *)(puVar12[2] + 10) + 0x28 + puVar12[2]) == 0) {
          *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
        }
        else {
          *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -1;
        }
        if (param_3 == '\x01') {
          KeReleaseSpinLockFromDpcLevel();
        }
        else {
          KeReleaseSpinLock(lVar1,CONCAT71(uVar8,*(undefined1 *)(param_1 + 0x28)));
        }
        plVar10[2] = 0;
        ndisuioFreeNetBufferList(param_1,puVar12,param_3);
        ndisuioDerefOpen(param_1);
        goto LAB_1c0003b0c;
      }
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar9 = auStack_30;
  }
  if (param_3 == '\x01') {
    *(undefined8 *)(puVar9 + -8) = 0x1c0003b2d;
    KeReleaseSpinLockFromDpcLevel();
  }
  else {
    lVar4 = *plVar10;
    *(undefined8 *)(puVar9 + -8) = 0x1c0003b3d;
    KeReleaseSpinLock(lVar1,(char)lVar4);
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c0003b50;
  ndisuioFreeNetBufferList(param_1,param_2,param_3);
  *(undefined8 *)(puVar9 + -8) = 0x1c0003b58;
  ndisuioDerefOpen(param_1);
  return;
}



===== ndisuioServiceReads @ 1c0003bb0 =====

void ndisuioServiceReads(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  code *pcVar9;
  undefined1 uVar10;
  void *_Src;
  longlong *plVar11;
  undefined7 uVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  undefined4 *_Dst;
  
  LOCK();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  UNLOCK();
  uVar10 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
LAB_1c0003be9:
  do {
    lVar14 = param_1 + 0x20;
    *(undefined1 *)(param_1 + 0x28) = uVar10;
    plVar11 = *(longlong **)(param_1 + 0x88);
    if (plVar11 == (longlong *)(param_1 + 0x88)) {
LAB_1c0003ca9:
      KeReleaseSpinLock(lVar14,*(undefined1 *)(param_1 + 0x28));
      ndisuioDerefOpen(param_1);
      return;
    }
    plVar2 = (longlong *)(param_1 + 0xa0);
    plVar4 = (longlong *)*plVar2;
    if (plVar4 == plVar2) goto LAB_1c0003ca9;
    puVar5 = (undefined8 *)plVar4[2];
    plVar1 = puVar5 + 2;
    uVar12 = (undefined7)((ulonglong)plVar1 >> 8);
    if (*(int *)(param_1 + 0x38) == 0) {
      lVar6 = *plVar1;
      if ((*(int *)((ulonglong)*(ushort *)(lVar6 + 10) + 0x28 + lVar6) != 0) ||
         (*(short *)((ulonglong)*(ushort *)(lVar6 + 10) + 0x2c + lVar6) != -0x7178))
      goto LAB_1c0003c29;
LAB_1c0003c8b:
      while( true ) {
        LOCK();
        lVar6 = plVar11[-8];
        plVar11[-8] = 0;
        UNLOCK();
        plVar4 = (longlong *)*plVar11;
        if (lVar6 != 0) break;
        plVar11 = plVar4;
        if (plVar4 == (longlong *)(param_1 + 0x88)) goto LAB_1c0003ca9;
      }
      if (((longlong *)plVar4[1] == plVar11) &&
         (plVar7 = (longlong *)plVar11[1], (longlong *)*plVar7 == plVar11)) {
        *plVar7 = (longlong)plVar4;
        plVar4[1] = (longlong)plVar7;
        plVar2 = (longlong *)*plVar2;
        lVar6 = *plVar2;
        if ((*(longlong **)(lVar6 + 8) == plVar2) &&
           (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 == plVar2)) {
          *plVar4 = lVar6;
          *(longlong **)(lVar6 + 8) = plVar4;
          if (*(int *)((ulonglong)*(ushort *)(*plVar1 + 10) + 0x28 + *plVar1) == 0) {
            *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
          }
          else {
            *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -1;
          }
          KeReleaseSpinLock(lVar14,CONCAT71(uVar12,*(undefined1 *)(param_1 + 0x28)));
          ndisuioDerefOpen(param_1);
          puVar5 = (undefined8 *)plVar2[2];
          plVar4 = plVar11 + -0x14;
          plVar2[2] = 0;
          lVar14 = *plVar4;
          if ((*(byte *)(lVar14 + 10) & 5) == 0) {
            _Dst = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar14,0,1,0,0,0x40000010);
          }
          else {
            _Dst = *(undefined4 **)(lVar14 + 0x18);
          }
          uVar13 = *(uint *)(*plVar4 + 0x28);
          if (*(int *)(param_1 + 0x38) == 1) {
            if (_Dst != (undefined4 *)0x0) {
              *_Dst = *(undefined4 *)((ulonglong)*(ushort *)(puVar5[2] + 10) + 0x28 + puVar5[2]);
              _Dst = _Dst + 1;
            }
            uVar13 = uVar13 - 4;
          }
          puVar8 = *(undefined8 **)(puVar5[1] + 0x20);
          while (((uVar13 != 0 && (puVar8 != (undefined8 *)0x0)) && (_Dst != (undefined4 *)0x0))) {
            if ((*(byte *)((longlong)puVar8 + 10) & 5) == 0) {
              _Src = (void *)MmMapLockedPagesSpecifyCache(puVar8,0,1,0,0,0x40000010);
            }
            else {
              _Src = (void *)puVar8[3];
            }
            uVar3 = *(uint *)(puVar8 + 5);
            if (_Src == (void *)0x0) break;
            if (uVar3 != 0) {
              uVar15 = uVar13;
              if (uVar3 < uVar13) {
                uVar15 = uVar3;
              }
              memcpy(_Dst,_Src,(ulonglong)uVar15);
              uVar13 = uVar13 - uVar15;
              _Dst = (undefined4 *)((longlong)_Dst + (ulonglong)uVar15);
            }
            puVar8 = (undefined8 *)*puVar8;
          }
          if (_Dst == (undefined4 *)0x0) {
            *(undefined4 *)(plVar11 + -0xf) = 0xc0000001;
          }
          else {
            *(undefined4 *)(plVar11 + -0xf) = 0;
            plVar11[-0xe] = (ulonglong)(*(int *)(*plVar4 + 0x28) - uVar13);
          }
          IofCompleteRequest(plVar11 + -0x15,0);
          ndisuioFreeNetBufferList(param_1,puVar5,0);
          ndisuioDerefOpen(param_1);
          uVar10 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
          *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
          goto LAB_1c0003be9;
        }
      }
LAB_1c0003eee:
      pcVar9 = (code *)swi(0x29);
      (*pcVar9)(3);
      pcVar9 = (code *)swi(3);
      (*pcVar9)();
      return;
    }
    if (*(int *)(param_1 + 0x38) == 1) goto LAB_1c0003c8b;
LAB_1c0003c29:
    lVar6 = *plVar4;
    if (((longlong *)*(longlong *)(lVar6 + 8) != plVar4) ||
       (plVar11 = (longlong *)plVar4[1], (longlong *)*plVar11 != plVar4)) goto LAB_1c0003eee;
    *plVar11 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar11;
    if (*(int *)((ulonglong)*(ushort *)(*plVar1 + 10) + 0x28 + *plVar1) == 0) {
      *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
    }
    else {
      *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -1;
    }
    KeReleaseSpinLock(lVar14,CONCAT71(uVar12,*(undefined1 *)(param_1 + 0x28)));
    ndisuioDerefOpen(param_1);
    ndisuioFreeNetBufferList(param_1,puVar5,0);
    uVar10 = KeAcquireSpinLockRaiseToDpc(lVar14);
  } while( true );
}



===== NdisuioCancelWrite @ 1c0003f00 =====

void NdisuioCancelWrite(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  lVar4 = 0;
  IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  lVar2 = param_2[0xf];
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x20);
  puVar1 = (undefined8 *)(lVar2 + 0x70);
  *(undefined1 *)(lVar2 + 0x28) = uVar3;
  puVar5 = (undefined8 *)*puVar1;
  do {
    if (puVar5 == puVar1) {
LAB_1c0003f65:
      KeReleaseSpinLock(lVar2 + 0x20,CONCAT71((int7)((ulonglong)puVar1 >> 8),uVar3));
      if (lVar4 != 0) {
        NdisCancelSendNetBufferLists(*(undefined8 *)(lVar2 + 0x40),lVar4);
      }
      return;
    }
    if (param_2 == puVar5 + -0x15) {
      lVar4 = param_2[0x10];
      goto LAB_1c0003f65;
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== NdisuioSendComplete @ 1c0003fb0 =====

void NdisuioSendComplete(int *param_1,longlong *param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  code *pcVar10;
  undefined1 uVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  byte bVar14;
  
  if (((WwanIsInitialized == '\0') || (param_1 == (int *)0x0)) || (*param_1 != 0x1000)) {
    bVar14 = (byte)param_3 & 1;
    if (param_2 != (longlong *)0x0) {
      piVar1 = param_1 + 8;
      do {
        plVar6 = (longlong *)*param_2;
        lVar7 = *(longlong *)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x10 + param_2[2]);
        LOCK();
        *(undefined8 *)(lVar7 + 0x68) = 0;
        UNLOCK();
        if (bVar14 == 1) {
          KeAcquireSpinLockAtDpcLevel();
        }
        else {
          uVar11 = KeAcquireSpinLockRaiseToDpc(piVar1);
          *(undefined1 *)(param_1 + 10) = uVar11;
        }
        plVar2 = (longlong *)(lVar7 + 0xa8);
        lVar8 = *plVar2;
        if ((*(longlong **)(lVar8 + 8) != plVar2) ||
           (plVar9 = *(longlong **)(lVar7 + 0xb0), (longlong *)*plVar9 != plVar2)) {
          pcVar10 = (code *)swi(0x29);
          (*pcVar10)(3);
          pcVar10 = (code *)swi(3);
          (*pcVar10)();
          return;
        }
        *plVar9 = lVar8;
        *(longlong **)(lVar8 + 8) = plVar9;
        if (bVar14 == 1) {
          KeReleaseSpinLockFromDpcLevel();
        }
        else {
          KeReleaseSpinLock(piVar1,CONCAT71((int7)((ulonglong)lVar8 >> 8),(char)param_1[10]));
        }
        iVar5 = *(int *)((longlong)param_2 + 0x8c);
        LOCK();
        piVar3 = (int *)((ulonglong)*(ushort *)(param_2[2] + 10) + 0x18 + param_2[2]);
        iVar4 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar4 == 1) {
          NdisFreeNetBufferList();
        }
        if (iVar5 == 0) {
          uVar12 = 0;
          uVar13 = (ulonglong)*(uint *)(*(longlong *)(lVar7 + 0xb8) + 8);
        }
        else {
          uVar12 = 0xc0000001;
          uVar13 = 0;
        }
        *(ulonglong *)(lVar7 + 0x38) = uVar13;
        *(undefined4 *)(lVar7 + 0x30) = uVar12;
        IofCompleteRequest(lVar7,0);
        if (bVar14 == 1) {
          KeAcquireSpinLockAtDpcLevel();
        }
        else {
          uVar11 = KeAcquireSpinLockRaiseToDpc(piVar1);
          *(undefined1 *)(param_1 + 10) = uVar11;
        }
        param_1[0x20] = param_1[0x20] + -1;
        if (bVar14 == 1) {
          KeReleaseSpinLockFromDpcLevel();
        }
        else {
          KeReleaseSpinLock(piVar1,(char)param_1[10]);
        }
        ndisuioDerefOpen((longlong)param_1);
        param_2 = plVar6;
      } while (plVar6 != (longlong *)0x0);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_3 = &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids);
    }
    WwanAssertFailed("WwanprotSendNetBufferListsComplete",0x14d,param_3);
  }
  return;
}



===== NdisuioWrite @ 1c00041d0 =====

undefined4 NdisuioWrite(longlong param_1,longlong param_2,undefined *param_3)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 uVar6;
  longlong lVar7;
  short *psVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong lVar12;
  uint uVar13;
  longlong *plVar14;
  undefined4 uVar15;
  undefined1 *puVar16;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined4 local_18;
  ulonglong local_10;
  
  if (((WwanIsInitialized != '\0') && (WwanGlobals != (longlong *)0x0)) && (*WwanGlobals == param_1)
     ) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_3 = &WPP_0cdf289910a63b357434a6c8e39dfc33_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_0cdf289910a63b357434a6c8e39dfc33_Traceguids);
    }
    WwanAssertFailed("NdisuioWrite",0x45,param_3);
    return 0xc00000bb;
  }
  lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (lVar3 == 0) {
LAB_1c000426d:
    uVar15 = 0xc0000008;
    goto LAB_1c000431d;
  }
  lVar7 = *(longlong *)(param_2 + 8);
  if (lVar7 != 0) {
    if ((*(byte *)(lVar7 + 10) & 5) == 0) {
      local_10 = CONCAT44(local_10._4_4_,0x40000010);
      local_18 = 0;
      lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1,0);
    }
    else {
      lVar7 = *(longlong *)(lVar7 + 0x18);
    }
    if (lVar7 == 0) {
LAB_1c00042be:
      uVar15 = 0xc000009a;
      goto LAB_1c000431d;
    }
    uVar2 = *(uint *)(*(longlong *)(param_2 + 8) + 0x28);
    if (uVar2 < 0xe) {
      uVar15 = 0xc0000023;
      goto LAB_1c000431d;
    }
    if ((ulonglong)*(uint *)(lVar3 + 0x6c) + 0xe < (ulonglong)uVar2) {
      uVar15 = 0xc0000206;
      goto LAB_1c000431d;
    }
    if (*(int *)(lVar3 + 0x38) == 0) {
      if (*(short *)(lVar7 + 0xc) == -0x7178) {
LAB_1c000435a:
        if (((*(int *)(lVar7 + 6) == *(int *)(lVar3 + 0x128)) &&
            (*(short *)(lVar7 + 10) == *(short *)(lVar3 + 300))) &&
           ((*(int *)(lVar7 + 6) == *(int *)(lVar3 + 0x128) &&
            (*(short *)(lVar7 + 10) == *(short *)(lVar3 + 300))))) {
          lVar7 = lVar3 + 0x20;
          uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7);
          *(undefined1 *)(lVar3 + 0x28) = uVar6;
          if (((byte)*(undefined4 *)(lVar3 + 0x18) & 0xf) != 4) {
            KeReleaseSpinLock(lVar7);
            goto LAB_1c000426d;
          }
          if (*(int *)(lVar3 + 0x124) - 2U < 2) {
            KeReleaseSpinLock(lVar7,uVar6);
            uVar15 = 0xc0000001;
            goto LAB_1c000431d;
          }
          local_18 = 0;
          local_10 = (ulonglong)uVar2;
          lVar9 = NdisAllocateNetBufferAndNetBufferList
                            (*(undefined8 *)(lVar3 + 0x48),0x10,0,*(undefined8 *)(param_2 + 8));
          puVar16 = auStack_38;
          if (lVar9 != 0) {
            *(int *)(lVar3 + 0x80) = *(int *)(lVar3 + 0x80) + 1;
            LOCK();
            *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
            UNLOCK();
            pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
            *(undefined4 *)
             ((ulonglong)*(ushort *)(*(longlong *)(lVar9 + 0x10) + 10) + 0x18 +
             *(longlong *)(lVar9 + 0x10)) = 1;
            LOCK();
            UNLOCK();
            uVar10 = (ulonglong)DAT_1c000d31c | (longlong)(DAT_1c000d320 + 1) & 0xffffffffffffffU;
            lVar12 = lVar3 + 0x70;
            DAT_1c000d320 = DAT_1c000d320 + 1;
            *(ulonglong *)(lVar9 + 0xb8) = uVar10;
            *(ulonglong *)(param_2 + 0x80) = uVar10;
            plVar11 = (longlong *)(param_2 + 0xa8);
            *(longlong *)(param_2 + 0x78) = lVar3;
            plVar14 = *(longlong **)(lVar3 + 0x78);
            if (*plVar14 != lVar12) {
              lVar12 = 3;
              pcVar5 = (code *)swi(0x29);
              plVar11 = (longlong *)(*pcVar5)();
              puVar16 = auStack_30;
            }
            *plVar11 = lVar12;
            plVar11[1] = (longlong)plVar14;
            *plVar14 = (longlong)plVar11;
            *(longlong **)(lVar12 + 8) = plVar11;
            LOCK();
            *(code **)(param_2 + 0x68) = NdisuioCancelWrite;
            UNLOCK();
            uVar6 = *(undefined1 *)(lVar3 + 0x28);
            *(undefined8 *)(puVar16 + -8) = 0x1c00044ad;
            KeReleaseSpinLock(lVar7,uVar6);
            *(longlong *)
             ((ulonglong)*(ushort *)(*(longlong *)(lVar9 + 0x10) + 10) + 0x10 +
             *(longlong *)(lVar9 + 0x10)) = param_2;
            *(undefined8 *)(lVar9 + 0x78) = *(undefined8 *)(lVar3 + 0x40);
            uVar4 = *(undefined8 *)(lVar3 + 0x40);
            *(undefined8 *)(puVar16 + -8) = 0x1c00044e3;
            NdisSendNetBufferLists(uVar4,lVar9,0,2);
            return 0x103;
          }
          KeReleaseSpinLock(lVar7,*(undefined1 *)(lVar3 + 0x28));
          goto LAB_1c00042be;
        }
      }
    }
    else if (*(int *)(lVar3 + 0x38) == 1) {
      psVar8 = &DAT_1c000d318;
      uVar13 = 0;
      do {
        if (*(short *)(lVar7 + 0xc) == *psVar8) goto LAB_1c000435a;
        uVar13 = uVar13 + 1;
        psVar8 = psVar8 + 1;
      } while (uVar13 < 2);
    }
  }
  uVar15 = 0xc000000d;
LAB_1c000431d:
  *(undefined4 *)(param_2 + 0x30) = uVar15;
  IofCompleteRequest(param_2,0);
  return uVar15;
}



===== IsWwanDosDevice @ 1c000450c =====

bool IsWwanDosDevice(longlong param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((WwanIsInitialized != '\0') && (WwanGlobals != (longlong *)0x0)) {
    bVar1 = *WwanGlobals == param_1;
  }
  return bVar1;
}



===== McGenControlCallbackV2 @ 1c0004530 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c0004640 =====

void McGenEventRegister_EtwRegister(void)

{
  if (WWAN_NDISUIO_EVT_GUID_Context == 0) {
    EtwRegister(&WWAN_NDISUIO_EVT_GUID,McGenControlCallbackV2,&WWAN_NDISUIO_EVT_GUID_Context,
                &WWAN_NDISUIO_EVT_GUID_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c0004680 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (WWAN_NDISUIO_EVT_GUID_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    WWAN_NDISUIO_EVT_GUID_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c00046b4 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c000d008;
  uVar2 = 0;
  if (DAT_1c000d008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c000d008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(WWAN_NDISUIO_EVT_GUID_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1c0004718 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,&DAT_1c000d3a0,1,local_28);
  return;
}



===== McTemplateK0jqqq_EtwWriteTransfer @ 1c0004760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jqqq_EtwWriteTransfer(undefined8 param_1)

{
  undefined1 uStack0000000000000028;
  undefined1 auStackY_a8 [32];
  undefined4 local_78 [2];
  undefined4 local_70 [2];
  undefined8 local_68 [2];
  undefined *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_48 = &uStack0000000000000028;
  local_70[0] = 1;
  local_38 = local_78;
  local_78[0] = 0x2e8;
  local_28 = local_70;
  local_58 = &DAT_1c000d3a0;
  local_50 = 0x10;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,&WWanNDISUIOError,&DAT_1c000d3a0,5,local_68);
  return;
}



===== WPP_SF_D @ 1c0004804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDD @ 1c0004848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_S @ 1c00048a4 =====

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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF_sD @ 1c0004914 =====

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
            (param_1,0x2b,&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,0x27,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WPP_SF_sDSD @ 1c0004998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sDSD(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  
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
  pwVar4 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar4 = L"NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_4[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,param_2,param_4,lVar3,
             &param_5,4,pwVar4,lVar1,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0004a80 =====

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



===== WwanAssertFailed @ 1c0004ab4 =====

void WwanAssertFailed(char *param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (WPP_GLOBAL_Control[0x29] != '\0')) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_2);
  }
  return;
}



===== WwanDerefOpen @ 1c0004af4 =====

void WwanDerefOpen(longlong param_1,char *param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_sDSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,param_3,param_2,(char)param_3,
                *(wchar_t **)(param_1 + 0x48),(char)*(undefined4 *)(param_1 + 0x20));
  }
  LOCK();
  piVar1 = (int *)(param_1 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,*(wchar_t **)(param_1 + 0x48));
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    NdisFreeMemory(*(undefined8 *)(param_1 + 0x48),0,0);
    NdisFreeMemory(param_1,0,0);
  }
  return;
}



===== WwanGetGlobalSettingsFromRegistry @ 1c0004bc4 =====

undefined4 WwanGetGlobalSettingsFromRegistry(longlong param_1)

{
  undefined4 uVar1;
  undefined8 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  
  local_78 = 0;
  local_70 = 0x120;
  local_68 = L"LegacyPause";
  local_60 = &DAT_1c000d4f4;
  local_58 = 0x4000000;
  local_50 = &DAT_1c000d4f4;
  local_48 = 4;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  uVar1 = RtlQueryRegistryValuesEx(0,*(undefined8 *)(param_1 + 8),&local_78,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,DAT_1c000d4f4);
  }
  return uVar1;
}



===== WwanRefOpen @ 1c0004c84 =====

void WwanRefOpen(longlong param_1,char *param_2,undefined8 param_3)

{
  LOCK();
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_sDSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,param_3,param_2,(char)param_3,
                *(wchar_t **)(param_1 + 0x48),(char)*(undefined4 *)(param_1 + 0x20));
  }
  return;
}



===== WwanSetDeviceDacl @ 1c0004ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WwanSetDeviceDacl(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined2 uVar8;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined1 local_70;
  undefined8 *local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_24 = 0x500;
  local_58 = 0;
  local_30 = 0;
  lVar7 = 0;
  local_28 = 0;
  local_68 = &local_58;
  local_70 = 0;
  lVar5 = 0;
  local_78 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar1 = ObOpenObjectByPointer(0,0x200,0,0x40000);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (WPP_GLOBAL_Control[0x29] == '\0')) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
    goto LAB_1c0005180;
    uVar8 = 0xe;
  }
  else {
    uVar2 = RtlLengthRequiredSid(6);
    lVar5 = ExAllocatePool2(1,uVar2,0x4e415757);
    if (lVar5 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (WPP_GLOBAL_Control[0x29] == '\0')) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
      goto LAB_1c0005180;
      uVar8 = 0xf;
    }
    else {
      iVar1 = RtlInitializeSid(lVar5,&local_28,6);
      if (iVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            (WPP_GLOBAL_Control[0x29] == '\0')) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)
           ) goto LAB_1c0005180;
        uVar8 = 0x10;
      }
      else {
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,0);
        *puVar6 = 0x50;
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,1);
        *puVar6 = 0xed564f19;
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,2);
        *puVar6 = 0x22ad3107;
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,3);
        *puVar6 = 0x43bbb8e3;
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,4);
        *puVar6 = 0x7b31f7c2;
        puVar6 = (undefined4 *)RtlSubAuthoritySid(lVar5,5);
        *puVar6 = 0x18699616;
        iVar3 = RtlLengthSid(lVar5);
        iVar4 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
        iVar3 = iVar3 + iVar4 + 0x18;
        lVar7 = ExAllocatePool2(1,iVar3,0x4e415757);
        if (lVar7 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (WPP_GLOBAL_Control[0x29] == '\0')) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
          uVar8 = 0x11;
        }
        else {
          iVar1 = RtlCreateAcl(lVar7,iVar3,2);
          if (iVar1 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                (WPP_GLOBAL_Control[0x29] == '\0')) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
            uVar8 = 0x12;
          }
          else {
            iVar1 = RtlAddAccessAllowedAce(lVar7,2,0x10000000,lVar5);
            if (iVar1 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  (WPP_GLOBAL_Control[0x29] == '\0')) ||
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
              uVar8 = 0x13;
            }
            else {
              iVar1 = RtlAddAccessAllowedAce
                                (lVar7,2,0x10000000,
                                 *(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
              if (iVar1 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    (WPP_GLOBAL_Control[0x29] == '\0')) ||
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
                uVar8 = 0x14;
              }
              else {
                iVar1 = RtlCreateSecurityDescriptor(&local_50,1);
                if (iVar1 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      (WPP_GLOBAL_Control[0x29] == '\0')) ||
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
                  uVar8 = 0x15;
                }
                else {
                  iVar1 = RtlSetDaclSecurityDescriptor(&local_50,1,lVar7,0);
                  if (iVar1 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        (WPP_GLOBAL_Control[0x29] == '\0')) ||
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
                    uVar8 = 0x16;
                  }
                  else {
                    iVar1 = ZwSetSecurityObject(local_58,4,&local_50);
                    if ((((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control))
                        || (WPP_GLOBAL_Control[0x29] == '\0')) ||
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1c0005180;
                    uVar8 = 0x17;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
           &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar1);
LAB_1c0005180:
  ZwClose(local_58);
  local_58 = 0;
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  return iVar1;
}



===== WwanSupportedStatus @ 1c00051f4 =====

undefined8 WwanSupportedStatus(int param_1)

{
  if (0x40043000 < param_1) {
switchD_1c0005226_caseD_40041013:
    return 0;
  }
  if (param_1 == 0x40043000) {
switchD_1c0005226_caseD_40041000:
    return 1;
  }
  switch(param_1) {
  case 0x40041000:
  case 0x40041001:
  case 0x40041002:
  case 0x40041003:
  case 0x40041004:
  case 0x40041005:
  case 0x40041006:
  case 0x40041007:
  case 0x40041008:
  case 0x40041009:
  case 0x4004100a:
  case 0x4004100b:
  case 0x4004100c:
  case 0x4004100d:
  case 0x4004100e:
  case 0x4004100f:
  case 0x40041010:
  case 0x40041011:
  case 0x40041012:
  case 0x40041014:
  case 0x40041015:
  case 0x40041016:
  case 0x40041017:
  case 0x40041018:
  case 0x40041019:
  case 0x40041020:
  case 0x40041021:
  case 0x40041022:
  case 0x40041023:
  case 0x40041024:
  case 0x40041025:
  case 0x40041027:
  case 0x40041029:
  case 0x4004102a:
  case 0x4004102c:
  case 0x4004102d:
  case 0x4004102e:
  case 0x4004102f:
  case 0x40041030:
  case 0x40041031:
  case 0x40041032:
  case 0x40041033:
  case 0x40041034:
  case 0x40041035:
  case 0x40041036:
  case 0x40041037:
  case 0x40041038:
  case 0x40041039:
  case 0x4004103a:
  case 0x4004103b:
  case 0x4004103c:
  case 0x4004103d:
  case 0x4004103e:
  case 0x4004103f:
  case 0x40041040:
  case 0x40041041:
  case 0x40041042:
  case 0x40041043:
  case 0x40041044:
  case 0x40041045:
  case 0x40041046:
  case 0x40041047:
  case 0x40041048:
  case 0x40041049:
  case 0x4004104a:
  case 0x4004104b:
  case 0x4004104c:
  case 0x4004104f:
    goto switchD_1c0005226_caseD_40041000;
  default:
    goto switchD_1c0005226_caseD_40041013;
  }
}



===== WwanprotStatus @ 1c0005240 =====

void WwanprotStatus(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (*(int *)(param_1 + 0x18) != -0x21502153) {
    WwanAssertFailed("WwanprotStatus",0x107,param_3);
  }
  if (iVar1 == 0x40010004) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
    *(undefined1 *)(param_1 + 0x30) = uVar2;
    NdisResetEvent(param_1 + 0x88);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
    return;
  }
  if (iVar1 == 0x40010005) {
    WwanResetResumeIO(param_1);
    return;
  }
  if (iVar1 == 0x4004104d) {
    WwanPauseIO(param_1);
    return;
  }
  if (iVar1 == 0x4004104e) {
    WwanResumeIO(param_1);
    return;
  }
  if (((*(uint *)(WwanGlobals + 0xc0) & 2) == 0) || (0x40043000 < iVar1)) {
switchD_1c0005373_caseD_40041013:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar1);
    }
  }
  else {
    if (iVar1 != 0x40043000) {
      switch(iVar1) {
      case 0x40041000:
      case 0x40041001:
      case 0x40041002:
      case 0x40041003:
      case 0x40041004:
      case 0x40041005:
      case 0x40041006:
      case 0x40041007:
      case 0x40041008:
      case 0x40041009:
      case 0x4004100a:
      case 0x4004100b:
      case 0x4004100c:
      case 0x4004100d:
      case 0x4004100e:
      case 0x4004100f:
      case 0x40041010:
      case 0x40041011:
      case 0x40041012:
      case 0x40041014:
      case 0x40041015:
      case 0x40041016:
      case 0x40041017:
      case 0x40041018:
      case 0x40041019:
      case 0x40041020:
      case 0x40041021:
      case 0x40041022:
      case 0x40041023:
      case 0x40041024:
      case 0x40041025:
      case 0x40041027:
      case 0x40041029:
      case 0x4004102a:
      case 0x4004102c:
      case 0x4004102d:
      case 0x4004102e:
      case 0x4004102f:
      case 0x40041030:
      case 0x40041031:
      case 0x40041032:
      case 0x40041033:
      case 0x40041034:
      case 0x40041035:
      case 0x40041036:
      case 0x40041037:
      case 0x40041038:
      case 0x40041039:
      case 0x4004103a:
      case 0x4004103b:
      case 0x4004103c:
      case 0x4004103d:
      case 0x4004103e:
      case 0x4004103f:
      case 0x40041040:
      case 0x40041041:
      case 0x40041042:
      case 0x40041043:
      case 0x40041044:
      case 0x40041045:
      case 0x40041046:
      case 0x40041047:
      case 0x40041048:
      case 0x40041049:
      case 0x4004104a:
      case 0x4004104b:
      case 0x4004104c:
      case 0x4004104f:
        break;
      default:
        goto switchD_1c0005373_caseD_40041013;
      }
    }
    WwanprotDeliverIndication(param_1,param_2);
  }
  return;
}



===== McTemplateK0jqqqq_EtwWriteTransfer @ 1c00053d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [4];
  undefined8 local_78 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_58 = &param_5;
  local_88[0] = 0;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = local_88;
  local_60 = 0x10;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,6,local_78);
  return;
}



===== WPP_SF_DD @ 1c0005478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_Dd @ 1c00054d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x50,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_Dq @ 1c0005528 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_DqD @ 1c0005580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x39,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF__guid_S @ 1c00055e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   wchar_t *param_5)

{
  longlong lVar1;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x3f,param_4,0x10,param_5
             ,lVar1,0);
  return;
}



===== WPP_SF_dD @ 1c0005678 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x4a,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dddd @ 1c00056d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x43,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_q @ 1c0005740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_qd @ 1c0005788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,0x49,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WwanAllocIndication @ 1c00057e4 =====

longlong WwanAllocIndication(undefined4 param_1,uint param_2)

{
  longlong lVar1;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if ((uint)(*(int *)(WwanGlobals + 0xc4) - *(int *)(WwanGlobals + 200)) < param_2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,*(int *)(WwanGlobals + 200),
                 (char)param_2,(char)*(int *)(WwanGlobals + 0xc4));
    }
    lVar1 = WwanGlobals;
    *(int *)(WwanGlobals + 0xcc) = *(int *)(WwanGlobals + 0xcc) + 1;
    *(uint *)(lVar1 + 0xc0) = *(uint *)(lVar1 + 0xc0) | 4;
    local_res18[0] = 0;
  }
  else {
    NdisAllocateMemoryWithTag(local_res18,param_1,0x4e415757);
    if (local_res18[0] == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                  (ulonglong)*(uint *)(WwanGlobals + 200),param_2,(char)*(uint *)(WwanGlobals + 200)
                 );
      }
      lVar1 = WwanGlobals;
      *(int *)(WwanGlobals + 0xd0) = *(int *)(WwanGlobals + 0xd0) + 1;
      *(uint *)(lVar1 + 0xc0) = *(uint *)(lVar1 + 0xc0) | 4;
    }
    else {
      *(int *)(WwanGlobals + 200) = *(int *)(WwanGlobals + 200) + param_2;
    }
  }
  return local_res18[0];
}



===== WwanFindContext @ 1c0005904 =====

undefined8 * WwanFindContext(void *param_1,uint param_2,ulonglong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)(WwanGlobals + 0x18);
  puVar3 = (undefined8 *)*puVar2;
  while( true ) {
    if (puVar3 == puVar2) {
      return (undefined8 *)0x0;
    }
    if (*(int *)(puVar3 + 2) != -0x21502153) {
      WwanAssertFailed("WwanFindContext",0x305,param_3);
    }
    if ((param_2 == *(ushort *)(puVar3 + 7)) &&
       (param_3 = (ulonglong)param_2, iVar1 = memcmp(param_1,(void *)puVar3[8],(ulonglong)param_2),
       iVar1 == 0)) break;
    puVar3 = (undefined8 *)*puVar3;
    puVar2 = (undefined8 *)(WwanGlobals + 0x18);
  }
  return puVar3 + -1;
}



===== WwanFlushIndicationQueue @ 1c000599c =====

void WwanFlushIndicationQueue(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar5 = auStack_28;
  do {
    plVar1 = (longlong *)(WwanGlobals + 0x28);
    plVar2 = (longlong *)*plVar1;
    lVar4 = WwanGlobals;
    if (plVar2 == plVar1) {
LAB_1c00059da:
      if (*(int *)(lVar4 + 200) != 0) {
        *(undefined8 *)(puVar5 + -8) = 0x1c00059f4;
        WwanAssertFailed("WwanFlushIndicationQueue",0x48c,param_3);
      }
      return;
    }
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar4 = *plVar2, (longlong *)*(longlong *)(lVar4 + 8) != plVar2)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStack_20;
      goto LAB_1c00059da;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    WwanFreeIndication(plVar2,*(int *)((longlong)plVar2 + 0x14));
  } while( true );
}



===== WwanFlushWaitingIrpQ @ 1c0005a00 =====

void WwanFlushWaitingIrpQ(void)

{
  longlong lVar1;
  
  while( true ) {
    lVar1 = IoCsqRemoveNextIrp(WwanGlobals + 0x38,0);
    if (lVar1 == 0) break;
    *(undefined8 *)(lVar1 + 0x38) = 0;
    *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
    IofCompleteRequest(lVar1);
  }
  return;
}



===== WwanFreeIndication @ 1c0005a50 =====

void WwanFreeIndication(undefined8 param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = WwanGlobals;
  *(int *)(WwanGlobals + 200) = *(int *)(WwanGlobals + 200) - param_2;
  if (*(uint *)(lVar1 + 0xc4) <= *(uint *)(lVar1 + 200)) {
    WwanAssertFailed("WwanFreeIndication",0x3ab,lVar1);
  }
  NdisFreeMemory(param_1,0,0);
  return;
}



===== WwanGetIOCount @ 1c0005aac =====

undefined8 WwanGetIOCount(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined1 uVar3;
  
  lVar1 = param_1 + 0x28;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  while( true ) {
    *(undefined1 *)(param_1 + 0x30) = uVar3;
    if ((*(uint *)(param_1 + 0x1c) & 4) != 0) {
      KeReleaseSpinLock(lVar1,uVar3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
      }
      return 0;
    }
    if ((*(uint *)(param_1 + 0x1c) & 3) == 0) break;
    KeReleaseSpinLock(lVar1,uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_3 = &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    NdisWaitEvent(param_1 + 0x88,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      param_3 = &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  iVar2 = *(int *)(param_1 + 0x80);
  if (iVar2 < 0) {
    WwanAssertFailed("WwanGetIOCount",0x41,param_3);
    iVar2 = *(int *)(param_1 + 0x80);
  }
  if (iVar2 == 0) {
    NdisResetEvent(param_1 + 0xa0);
  }
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x30));
  return 1;
}



===== WwanIsSynchronousOid @ 1c0005c38 =====

undefined1 WwanIsSynchronousOid(int param_1)

{
  if ((((param_1 == 0x10101) || (param_1 == 0x10103)) || (param_1 == 0x10202)) ||
     (param_1 == 0xe010100)) {
    return 1;
  }
  return 0;
}



===== WwanPauseIO @ 1c0005c64 =====

void WwanPauseIO(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 2;
  *(undefined1 *)(param_1 + 0x30) = uVar1;
  NdisResetEvent(param_1 + 0x88);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
  return;
}



===== WwanReleaseIOCount @ 1c0005cf8 =====

void WwanReleaseIOCount(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  *(undefined1 *)(param_1 + 0x30) = uVar2;
  if (*(int *)(param_1 + 0x80) < 1) {
    WwanAssertFailed("WwanReleaseIOCount",0x51,param_3);
  }
  piVar1 = (int *)(param_1 + 0x80);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    NdisSetEvent(param_1 + 0xa0);
  }
  KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
  return;
}



===== WwanResetResumeIO @ 1c0005da8 =====

void WwanResetResumeIO(longlong param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffe;
  *(undefined1 *)(param_1 + 0x30) = uVar1;
  if ((*(uint *)(param_1 + 0x1c) & 3) == 0) {
    NdisSetEvent(param_1 + 0x88);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 4)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
    goto LAB_1c0005e45;
    uVar2 = 0x10;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 4)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
    goto LAB_1c0005e45;
    uVar2 = 0xf;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
LAB_1c0005e45:
  KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
  return;
}



===== WwanResumeIO @ 1c0005e6c =====

void WwanResumeIO(longlong param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffd;
  *(undefined1 *)(param_1 + 0x30) = uVar1;
  if ((*(uint *)(param_1 + 0x1c) & 3) == 0) {
    NdisSetEvent(param_1 + 0x88);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 4)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
    goto LAB_1c0005f09;
    uVar2 = 0x13;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((byte)WPP_GLOBAL_Control[0x29] < 4)) || ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0))
    goto LAB_1c0005f09;
    uVar2 = 0x12;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
LAB_1c0005f09:
  KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
  return;
}



===== WwanprotCleanup @ 1c0005f30 =====

undefined8 WwanprotCleanup(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  *(undefined1 *)(WwanGlobals + 0xa0) = uVar1;
  WwanFlushWaitingIrpQ();
  KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  IofCompleteRequest(param_1,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  return 0;
}



===== WwanprotClose @ 1c0005fe4 =====

undefined8 WwanprotClose(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  longlong lVar5;
  char *pcVar6;
  longlong lVar7;
  
  pcVar6 = (char *)(WwanGlobals + 0x98);
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  lVar7 = WwanGlobals;
  piVar1 = (int *)(WwanGlobals + 8);
  *piVar1 = *piVar1 + -1;
  iVar2 = *piVar1;
  uVar3 = *(undefined4 *)(lVar7 + 8);
  *(undefined1 *)(lVar7 + 0xa0) = uVar4;
  if (iVar2 < 0) {
    pcVar6 = "WwanprotClose";
    WwanAssertFailed("WwanprotClose",0x1fd,param_3);
  }
  if (*(longlong *)(WwanGlobals + 0x10) == 0) {
    pcVar6 = "WwanprotClose";
    WwanAssertFailed("WwanprotClose",0x1fe,param_3);
  }
  lVar5 = PsGetCurrentProcess();
  lVar7 = WwanGlobals;
  if (*(longlong *)(WwanGlobals + 0x10) != lVar5) {
    lVar7 = 0x1ff;
    pcVar6 = "WwanprotClose";
    WwanAssertFailed("WwanprotClose",0x1ff,param_3);
  }
  lVar5 = WwanGlobals;
  if (*(int *)(WwanGlobals + 8) == 0) {
    *(undefined8 *)(WwanGlobals + 0x10) = 0;
    *(uint *)(lVar5 + 0xc0) = *(uint *)(lVar5 + 0xc0) & 0xfffffffd;
    WwanFlushIndicationQueue(pcVar6,lVar7,param_3);
  }
  KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  IofCompleteRequest(param_1,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar3);
  }
  return 0;
}



===== WwanprotDeliverIndication @ 1c0006120 =====

void WwanprotDeliverIndication(longlong param_1,longlong param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  int iVar10;
  longlong *plVar11;
  undefined *puVar12;
  longlong lVar13;
  undefined1 *puVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined4 *unaff_R15;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined1 uVar17;
  
  if (param_2 == 0) {
    return;
  }
  if (*(longlong *)(param_2 + 0x28) == 0) {
    if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
      uVar6 = (undefined1)*(undefined4 *)(param_2 + 0x38);
      uVar17 = 0x31;
      uVar5 = (undefined1)*(undefined4 *)(param_2 + 0x14);
      puVar12 = &UnsolicitedNotification;
      goto LAB_1c0006198;
    }
  }
  else if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
    uVar17 = 0x2b;
    uVar6 = (undefined1)*(undefined4 *)(param_2 + 0x28);
    uVar5 = (undefined1)*(undefined4 *)(param_2 + 0x14);
    puVar12 = &OidRequestFinish;
LAB_1c0006198:
    McTemplateK0jqqqq_EtwWriteTransfer
              (param_1,puVar12,param_1 + 0x50,param_1 + 0x50,uVar5,uVar6,uVar17);
  }
  uVar15 = (uint)*(ushort *)(param_1 + 0x40);
  iVar10 = uVar15 + 2;
  if (uVar15 + 0x2a < 0x28) {
    return;
  }
  uVar3 = *(uint *)(param_2 + 0x38);
  if (uVar3 + 0x28 + iVar10 < uVar15 + 0x2a) {
    return;
  }
  uVar15 = uVar15 + 0x22;
  uVar16 = (ulonglong)uVar15;
  if (uVar15 < 0x20) {
    return;
  }
  if (uVar3 + 0x20 + iVar10 < uVar15) {
    return;
  }
  uVar15 = uVar3 + iVar10 + 0x28;
  plVar8 = (longlong *)(ulonglong)uVar15;
  uVar1 = uVar3 + iVar10 + 0x20;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar3,uVar16,
               *(undefined4 *)(param_2 + 0x14),(char)*(undefined8 *)(param_2 + 0x28),(char)uVar3);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  lVar9 = WwanGlobals;
  *(undefined1 *)(WwanGlobals + 0xa0) = uVar6;
  plVar7 = (longlong *)IoCsqRemoveNextIrp(lVar9 + 0x38,0);
  if (plVar7 == (longlong *)0x0) {
    plVar7 = (longlong *)WwanAllocIndication(uVar15,*(uint *)(param_2 + 0x38));
    if (plVar7 == (longlong *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,*(undefined4 *)(param_2 + 0x38));
      }
      lVar9 = WwanGlobals;
    }
    else {
      *(undefined4 *)(plVar7 + 2) = *(undefined4 *)(param_2 + 0x14);
      *(undefined4 *)((longlong)plVar7 + 0x14) = *(undefined4 *)(param_2 + 0x38);
      *(uint *)(plVar7 + 3) = (uint)*(ushort *)(param_1 + 0x40);
      plVar7[4] = *(longlong *)(param_2 + 0x28);
      memcpy(plVar7 + 5,*(void **)(param_2 + 0x30),(ulonglong)*(uint *)(param_2 + 0x38));
      uVar16 = (ulonglong)*(ushort *)(param_1 + 0x40);
      memcpy((void *)((ulonglong)*(uint *)(param_2 + 0x38) + 0x28 + (longlong)plVar7),
             *(void **)(param_1 + 0x48),uVar16);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,uVar16,
                  *(undefined4 *)(param_2 + 0x14),(char)*(undefined8 *)(param_2 + 0x28));
      }
      lVar9 = WwanGlobals;
      plVar11 = *(longlong **)(WwanGlobals + 0x30);
      if (*plVar11 != WwanGlobals + 0x28) {
LAB_1c0006499:
        plVar11 = (longlong *)0x3;
        pcVar4 = (code *)swi(0x29);
        lVar13 = WwanGlobals;
        lVar9 = (*pcVar4)();
        puVar14 = auStackY_50;
LAB_1c00064a0:
        *plVar8 = lVar9;
        plVar8[1] = (longlong)plVar11;
        *plVar11 = (longlong)plVar8;
        *(longlong **)(lVar9 + 8) = plVar8;
        goto LAB_1c00064ae;
      }
      *plVar7 = WwanGlobals + 0x28;
      plVar7[1] = (longlong)plVar11;
      *plVar11 = (longlong)plVar7;
      *(longlong **)(lVar9 + 0x30) = plVar7;
    }
    KeReleaseSpinLock(lVar9 + 0x98,*(undefined1 *)(lVar9 + 0xa0));
  }
  else {
    uVar3 = *(uint *)(plVar7[0x17] + 8);
    if (uVar3 < 0x20) {
      WwanAssertFailed("WwanprotDeliverIndication",0x56b,uVar16);
    }
    unaff_R15 = (undefined4 *)plVar7[3];
    if (uVar3 < uVar1) {
      plVar8 = (longlong *)WwanAllocIndication(uVar15,*(uint *)(param_2 + 0x38));
      if (plVar8 != (longlong *)0x0) {
        *(undefined4 *)(plVar8 + 2) = *(undefined4 *)(param_2 + 0x14);
        *(undefined4 *)((longlong)plVar8 + 0x14) = *(undefined4 *)(param_2 + 0x38);
        *(uint *)(plVar8 + 3) = (uint)*(ushort *)(param_1 + 0x40);
        plVar8[4] = *(longlong *)(param_2 + 0x28);
        memcpy(plVar8 + 5,*(void **)(param_2 + 0x30),(ulonglong)*(uint *)(param_2 + 0x38));
        uVar16 = (ulonglong)*(ushort *)(param_1 + 0x40);
        memcpy((void *)((ulonglong)*(uint *)(param_2 + 0x38) + 0x28 + (longlong)plVar8),
               *(void **)(param_1 + 0x48),uVar16);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,uVar16,
                    *(undefined4 *)(param_2 + 0x14),(char)*(undefined8 *)(param_2 + 0x28));
        }
        puVar14 = auStackY_58;
        lVar9 = WwanGlobals + 0x28;
        plVar11 = *(longlong **)(WwanGlobals + 0x30);
        lVar13 = WwanGlobals;
        if (*plVar11 != lVar9) goto LAB_1c0006499;
        goto LAB_1c00064a0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,*(undefined4 *)(param_2 + 0x38));
      }
      puVar14 = auStackY_58;
      lVar13 = WwanGlobals;
LAB_1c00064ae:
      uVar6 = *(undefined1 *)(lVar13 + 0xa0);
      *(undefined8 *)(puVar14 + -8) = 0x1c00064c2;
      KeReleaseSpinLock(lVar13 + 0x98,uVar6);
      unaff_R15[1] = uVar1;
      *(undefined8 *)(unaff_R15 + 4) = 1;
      plVar7[7] = 0x20;
    }
    else {
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,uVar16,
                  *(undefined4 *)(param_2 + 0x14),(char)*(undefined8 *)(param_2 + 0x28));
      }
      *unaff_R15 = *(undefined4 *)(param_2 + 0x14);
      unaff_R15[2] = *(undefined4 *)(param_2 + 0x38);
      uVar2 = *(ushort *)(param_1 + 0x40);
      *(undefined8 *)(unaff_R15 + 4) = 0;
      unaff_R15[3] = (uint)uVar2;
      *(undefined8 *)(unaff_R15 + 6) = *(undefined8 *)(param_2 + 0x28);
      memcpy(unaff_R15 + 8,*(void **)(param_2 + 0x30),(ulonglong)*(uint *)(param_2 + 0x38));
      memcpy((void *)((ulonglong)*(uint *)(param_2 + 0x38) + 0x20 + (longlong)unaff_R15),
             *(void **)(param_1 + 0x48),(ulonglong)*(ushort *)(param_1 + 0x40));
      puVar14 = auStackY_58;
      plVar7[7] = (ulonglong)uVar1;
    }
    *(undefined4 *)(plVar7 + 6) = 0;
    *(undefined8 *)(puVar14 + -8) = 0x1c000659d;
    IofCompleteRequest(plVar7,0);
  }
  return;
}



===== WwanprotDeliverPnPEvent @ 1c00065c8 =====

void WwanprotDeliverPnPEvent(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  if (*(int *)(param_2 + 8) != 0) {
    return;
  }
  puVar13 = (undefined4 *)0x4;
  iVar8 = **(int **)(param_2 + 0x10) + -1;
  if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
    param_3 = param_1 + 0x50;
    McTemplateK0jqqqq_EtwWriteTransfer(param_1,&UnsolicitedNotification,param_3,param_3,0x26,4,0x31)
    ;
  }
  uVar1 = *(ushort *)(param_1 + 0x40);
  if (uVar1 + 0x2a < 0x28) {
    return;
  }
  if (uVar1 + 0x2e < uVar1 + 0x2a) {
    return;
  }
  uVar9 = uVar1 + 0x22;
  if (uVar9 < 0x20) {
    return;
  }
  if (uVar1 + 0x26 < uVar9) {
    return;
  }
  uVar14 = uVar1 + 0x26;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar9,param_3,0x40041026,0,4);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  lVar4 = WwanGlobals;
  *(undefined1 *)(WwanGlobals + 0xa0) = uVar3;
  lVar4 = IoCsqRemoveNextIrp(lVar4 + 0x38,0);
  if (lVar4 == 0) {
    plVar5 = (longlong *)WwanAllocIndication(uVar1 + 0x2e,4);
    if (plVar5 == (longlong *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,4);
      }
      lVar6 = WwanGlobals;
    }
    else {
      *(undefined4 *)(plVar5 + 2) = 0x40041026;
      *(undefined4 *)((longlong)plVar5 + 0x14) = 4;
      uVar1 = *(ushort *)(param_1 + 0x40);
      plVar5[4] = 0;
      *(uint *)(plVar5 + 3) = (uint)uVar1;
      *(int *)(plVar5 + 5) = iVar8;
      uVar12 = (ulonglong)*(ushort *)(param_1 + 0x40);
      memcpy((void *)((longlong)plVar5 + 0x2c),*(void **)(param_1 + 0x48),uVar12);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,uVar12,0x40041026,0);
      }
      lVar6 = WwanGlobals;
      plVar7 = *(longlong **)(WwanGlobals + 0x30);
      if (*plVar7 != WwanGlobals + 0x28) {
LAB_1c00068ee:
        plVar7 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        lVar10 = WwanGlobals;
        lVar6 = (*pcVar2)();
        puVar11 = auStackY_50;
LAB_1c00068f5:
        *plVar5 = lVar6;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(lVar6 + 8) = plVar5;
        goto LAB_1c0006903;
      }
      *plVar5 = WwanGlobals + 0x28;
      plVar5[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar5;
      *(longlong **)(lVar6 + 0x30) = plVar5;
    }
    KeReleaseSpinLock(lVar6 + 0x98,*(undefined1 *)(lVar6 + 0xa0));
  }
  else {
    uVar9 = *(uint *)(*(longlong *)(lVar4 + 0xb8) + 8);
    if (uVar9 < 0x20) {
      WwanAssertFailed("WwanprotDeliverIndication",0x56b,param_3);
    }
    puVar13 = *(undefined4 **)(lVar4 + 0x18);
    if (uVar9 < uVar14) {
      plVar5 = (longlong *)WwanAllocIndication(uVar1 + 0x2e,4);
      if (plVar5 != (longlong *)0x0) {
        *(undefined4 *)(plVar5 + 2) = 0x40041026;
        *(undefined4 *)((longlong)plVar5 + 0x14) = 4;
        uVar1 = *(ushort *)(param_1 + 0x40);
        plVar5[4] = 0;
        *(uint *)(plVar5 + 3) = (uint)uVar1;
        *(int *)(plVar5 + 5) = iVar8;
        uVar12 = (ulonglong)*(ushort *)(param_1 + 0x40);
        memcpy((void *)((longlong)plVar5 + 0x2c),*(void **)(param_1 + 0x48),uVar12);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,uVar12,0x40041026,0);
        }
        puVar11 = auStackY_58;
        lVar6 = WwanGlobals + 0x28;
        plVar7 = *(longlong **)(WwanGlobals + 0x30);
        lVar10 = WwanGlobals;
        if (*plVar7 != lVar6) goto LAB_1c00068ee;
        goto LAB_1c00068f5;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,4);
      }
      puVar11 = auStackY_58;
      lVar10 = WwanGlobals;
LAB_1c0006903:
      uVar3 = *(undefined1 *)(lVar10 + 0xa0);
      *(undefined8 *)(puVar11 + -8) = 0x1c0006917;
      KeReleaseSpinLock(lVar10 + 0x98,uVar3);
      puVar13[1] = uVar14;
      *(undefined8 *)(puVar13 + 4) = 1;
      *(undefined8 *)(lVar4 + 0x38) = 0x20;
    }
    else {
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,param_3,0x40041026,0);
      }
      *puVar13 = 0x40041026;
      puVar13[2] = 4;
      uVar1 = *(ushort *)(param_1 + 0x40);
      *(undefined8 *)(puVar13 + 4) = 0;
      *(undefined8 *)(puVar13 + 6) = 0;
      puVar13[3] = (uint)uVar1;
      puVar13[8] = iVar8;
      memcpy(puVar13 + 9,*(void **)(param_1 + 0x48),(ulonglong)*(ushort *)(param_1 + 0x40));
      puVar11 = auStackY_58;
      *(ulonglong *)(lVar4 + 0x38) = (ulonglong)uVar14;
    }
    *(undefined4 *)(lVar4 + 0x30) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x1c00069e1;
    IofCompleteRequest(lVar4,0);
  }
  return;
}



===== WwanprotDeregisterIndication @ 1c0006a08 =====

undefined8 WwanprotDeregisterIndication(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  lVar2 = WwanGlobals;
  *(uint *)(WwanGlobals + 0xc0) = *(uint *)(WwanGlobals + 0xc0) & 0xfffffffd;
  *(undefined1 *)(lVar2 + 0xa0) = uVar1;
  WwanFlushWaitingIrpQ();
  WwanFlushIndicationQueue(lVar2,param_2,param_3);
  KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  return 0;
}



===== WwanprotGetD3ColdCapability @ 1c0006aa8 =====

int WwanprotGetD3ColdCapability(uint *param_1,uint param_2,ulonglong param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined8 uVar7;
  uint local_res18 [2];
  uint uVar8;
  
  *param_4 = 0;
  local_res18[0]._1_3_ = (uint3)(param_3 >> 8);
  local_res18[0] = (uint)local_res18[0]._1_3_ << 8;
  if (param_2 < 8) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      uVar8 = 0;
      uVar6 = 0x46;
LAB_1c0006c87:
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,param_3,param_2,(char)uVar8);
    }
  }
  else {
    uVar1 = *param_1;
    if (7 < uVar1 + 8) {
      uVar2 = param_1[1];
      uVar8 = uVar2 + 8 + uVar1;
      param_3 = (ulonglong)uVar8;
      if (uVar1 + 8 <= uVar8) {
        if (param_2 < uVar8) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            uVar6 = 0x48;
            goto LAB_1c0006c87;
          }
        }
        else {
          uVar3 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
          *(undefined1 *)(WwanGlobals + 0xa0) = uVar3;
          puVar5 = WwanFindContext((void *)((ulonglong)uVar1 + 8 + (longlong)param_1),uVar2,param_3)
          ;
          if ((puVar5 != (undefined8 *)0x0) && (puVar5[7] != 0)) {
            WwanRefOpen((longlong)puVar5,"WwanprotGetD3ColdCapability",0x6aa);
            KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
            iVar4 = WwanprotGetD3ColdCapabilityFromDevice(puVar5[0x21],(byte *)local_res18);
            param_3 = 0x6b0;
            WwanDerefOpen((longlong)puVar5,"WwanprotGetD3ColdCapability",0x6b0);
            goto LAB_1c0006c98;
          }
          uVar7 = CONCAT71((int7)((ulonglong)WwanGlobals >> 8),*(undefined1 *)(WwanGlobals + 0xa0));
          KeReleaseSpinLock(WwanGlobals + 0x98);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) {
            WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,param_3,param_1,(char)param_2
                     );
          }
        }
        goto LAB_1c0006c93;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      uVar6 = 0x47;
      uVar8 = 8;
      goto LAB_1c0006c87;
    }
  }
LAB_1c0006c93:
  iVar4 = -0x3fffffff;
LAB_1c0006c98:
  *(byte *)param_1 = (byte)local_res18[0];
  *param_4 = 1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(byte)local_res18[0],param_3,
              local_res18[0] & 0xff,(char)iVar4);
  }
  return iVar4;
}



===== WwanprotGetD3ColdCapabilityFromDevice @ 1c0006cf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WwanprotGetD3ColdCapabilityFromDevice(longlong param_1,byte *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  byte *pbVar5;
  undefined *puVar6;
  undefined1 local_68 [8];
  undefined8 local_60;
  code *local_38;
  
  puVar6 = (undefined *)0x48;
  memset(local_68,0,0x48);
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar3 = IoGetAttachedDeviceReference(param_1);
    lVar4 = IoAllocateIrp(*(undefined1 *)(lVar3 + 0x4c),0);
    if (lVar4 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
      }
      iVar2 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(lVar4 + 0x38) = 0;
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined8 *)(lVar1 + -0x28) = 0;
      *(undefined **)(lVar1 + -0x40) = &GUID_D3COLD_SUPPORT_INTERFACE;
      *(undefined1 **)(lVar1 + -0x30) = local_68;
      *(undefined2 *)(lVar1 + -0x48) = 0x81b;
      *(undefined4 *)(lVar1 + -0x38) = 0x10048;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        puVar6 = &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
      }
      iVar2 = IoSynchronousCallDriver(lVar3,lVar4);
      IoFreeIrp(lVar4);
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                   &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar2);
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar6 = &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
                  &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
        }
        if (local_38 == (code *)0x0) {
          iVar2 = -0x3fffffff;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                    &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
          }
        }
        else {
          pbVar5 = param_2;
          iVar2 = (*local_38)(local_60);
          if (iVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pbVar5,puVar6,iVar2,*param_2);
            }
          }
          else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                     &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,(uint)*param_2);
          }
        }
      }
    }
    ObfDereferenceObject(lVar3);
  }
  return iVar2;
}



===== WwanprotGetDeviceCount @ 1c0006fac =====

undefined8 WwanprotGetDeviceCount(int *param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  int iVar5;
  
  uVar4 = 0;
  *param_4 = 0;
  iVar5 = 0;
  if (param_3 < 4) {
    uVar4 = 0xc0000023;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
    puVar1 = (undefined8 *)(WwanGlobals + 0x18);
    *(undefined1 *)(WwanGlobals + 0xa0) = uVar2;
    for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
      iVar5 = iVar5 + 1;
    }
    KeReleaseSpinLock(WwanGlobals + 0x98);
    *param_1 = iVar5;
    *param_4 = 4;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar5);
    }
  }
  return uVar4;
}



===== WwanprotGetDeviceList @ 1c0007098 =====

undefined8 WwanprotGetDeviceList(uint *param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  longlong *plVar1;
  ushort uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  longlong *plVar13;
  
  uVar12 = 0;
  lVar6 = WwanGlobals + 0x98;
  *param_4 = 0;
  uVar10 = 0;
  iVar8 = 0;
  uVar5 = param_3;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar6);
  lVar6 = WwanGlobals;
  *(undefined1 *)(WwanGlobals + 0xa0) = uVar3;
  puVar4 = (undefined8 *)(lVar6 + 0x18);
  for (puVar7 = (undefined8 *)*puVar4; puVar7 != puVar4; puVar7 = (undefined8 *)*puVar7) {
    if (*(int *)(puVar7 + 2) != -0x21502153) {
      WwanAssertFailed("WwanprotGetDeviceList",0x2a2,uVar5);
    }
    iVar8 = iVar8 + *(ushort *)(puVar7 + 7) + 2;
    uVar10 = uVar10 + 1;
    puVar4 = (undefined8 *)(WwanGlobals + 0x18);
    lVar6 = WwanGlobals;
  }
  uVar9 = iVar8 + 4 + uVar10 * 8;
  uVar11 = (uint)param_3;
  if (uVar11 < uVar9) {
    *param_4 = uVar11;
    if (3 < uVar11) {
      *param_1 = uVar9;
    }
    KeReleaseSpinLock(lVar6 + 0x98,*(undefined1 *)(lVar6 + 0xa0));
    uVar5 = 0xc0000023;
  }
  else {
    plVar1 = (longlong *)(lVar6 + 0x18);
    *param_1 = uVar10;
    plVar13 = (longlong *)*plVar1;
    if (plVar13 != plVar1) {
      uVar11 = uVar10 * 8 + 4;
      do {
        param_1[uVar12 + 1] = uVar11;
        uVar2 = *(ushort *)(plVar13 + 7);
        param_1[(ulonglong)uVar10 + 1 + uVar12] = uVar2 + 2;
        memcpy((void *)((ulonglong)uVar11 + (longlong)param_1),(void *)plVar13[8],
               (ulonglong)(uVar2 + 2));
        uVar11 = uVar11 + param_1[(ulonglong)uVar10 + 1 + uVar12];
        uVar12 = (ulonglong)((int)uVar12 + 1);
        plVar13 = (longlong *)*plVar13;
      } while (plVar13 != plVar1);
    }
    KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
    *param_4 = uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar10);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== WwanprotOpen @ 1c0007250 =====

undefined4 WwanprotOpen(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  lVar4 = WwanGlobals;
  *(undefined1 *)(WwanGlobals + 0xa0) = uVar1;
  if (*(int *)(lVar4 + 8) < 0) {
    WwanAssertFailed("WwanprotOpen",0x1d6,param_3);
  }
  if (*(int *)(WwanGlobals + 8) == 0) {
    if (*(longlong *)(WwanGlobals + 0x10) != 0) {
      WwanAssertFailed("WwanprotOpen",0x1d8,param_3);
    }
    uVar2 = PsGetCurrentProcess();
    lVar4 = WwanGlobals;
    *(undefined8 *)(WwanGlobals + 0x10) = uVar2;
  }
  else {
    lVar3 = PsGetCurrentProcess();
    lVar4 = WwanGlobals;
    if (*(longlong *)(WwanGlobals + 0x10) != lVar3) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
      }
      uVar5 = 0xc0000136;
      goto LAB_1c00072f4;
    }
  }
  *(int *)(lVar4 + 8) = *(int *)(lVar4 + 8) + 1;
  uVar6 = *(undefined4 *)(lVar4 + 8);
LAB_1c00072f4:
  KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  IofCompleteRequest(param_1,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar6);
  }
  return uVar5;
}



===== WwanprotOpenNic @ 1c00073d4 =====

undefined8 WwanprotOpenNic(void *param_1,uint param_2,undefined8 param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int local_res18;
  undefined8 local_res20;
  
  lVar1 = WwanGlobals;
  *param_4 = 0;
  uVar3 = 0xc0000001;
  local_res18 = 0xfa;
  puVar4 = (undefined8 *)(ulonglong)*(uint *)(lVar1 + 0xc0);
  if ((*(uint *)(lVar1 + 0xc0) & 1) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      puVar4 = (undefined8 *)&WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    NdisWaitEvent(WwanGlobals + 0xa8,0);
  }
  while( true ) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
    *(undefined1 *)(WwanGlobals + 0xa0) = uVar2;
    local_res20 = 0xfffffffffffcf2c0;
    puVar4 = WwanFindContext(param_1,param_2,(ulonglong)puVar4);
    if ((puVar4 != (undefined8 *)0x0) && (puVar4[7] != 0)) break;
    if (local_res18 == 0) goto LAB_1c00074f9;
    KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
    puVar4 = &local_res20;
    KeDelayExecutionThread(0,0);
    local_res18 = local_res18 + -1;
  }
  uVar3 = 0;
LAB_1c00074f9:
  KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
  return uVar3;
}



===== WwanprotQueryOid @ 1c0007534 =====

int WwanprotQueryOid(uint *param_1,uint param_2,undefined8 param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  undefined7 extraout_var;
  undefined8 *puVar7;
  undefined2 uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  *param_4 = 0;
  if (param_2 < 0x20) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar8 = 0x2d;
  }
  else {
    uVar1 = param_1[2];
    if (uVar1 + 0x20 < 0x20) {
      return -0x3fffffff;
    }
    uVar2 = param_1[3];
    uVar9 = uVar2 + 0x20 + uVar1;
    uVar10 = (ulonglong)uVar9;
    if (uVar9 < uVar1 + 0x20) {
      return -0x3fffffff;
    }
    if (param_2 < uVar9) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffffff;
      }
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,uVar10,param_2,(char)uVar9);
      return -0x3fffffff;
    }
    uVar9 = *param_1;
    bVar4 = WwanSupportedOid(uVar9);
    if ((int)CONCAT71(extraout_var,bVar4) == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffffff;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar9);
      return -0x3fffffff;
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
    *(undefined1 *)(WwanGlobals + 0xa0) = uVar5;
    puVar7 = WwanFindContext((void *)((longlong)(param_1 + 8) + (ulonglong)uVar1),uVar2,uVar10);
    if (puVar7 != (undefined8 *)0x0) {
      WwanRefOpen((longlong)puVar7,"WwanprotQueryOid",0x442);
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      uVar3 = *(undefined8 *)(param_1 + 6);
      uVar2 = *param_1;
      *param_4 = 0x20;
      iVar6 = WwanOidRequest((longlong)puVar7,(ulonglong)uVar2,(undefined *)0x0,uVar3,param_1 + 8,
                             uVar1,param_1 + 1);
      WwanDerefOpen((longlong)puVar7,"WwanprotQueryOid",0x44d);
      if ((iVar6 + 0x3ffeffecU & 0xfffffffd) == 0) {
        param_1[4] = 1;
        param_1[5] = 0;
        iVar6 = 0;
      }
      else {
        param_1[4] = 0;
        param_1[5] = 0;
        if (iVar6 == 0x40230001) {
          *param_4 = 0;
        }
        else {
          *param_4 = param_1[1] + 0x20;
        }
      }
      return iVar6;
    }
    KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar8 = 0x30;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
          &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  return -0x3fffffff;
}



===== WwanprotReceiveIndication @ 1c0007798 =====

undefined8
WwanprotReceiveIndication
          (undefined8 param_1,undefined4 *param_2,undefined8 param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  if (param_4 < 0x20) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,param_4);
    }
    uVar6 = 0xc0000023;
  }
  else {
    lVar8 = WwanGlobals + 0x98;
    *(undefined8 *)(param_2 + 4) = 0;
    *param_5 = 0x20;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
    puVar10 = auStack_48;
    while (uVar9 = WwanGlobals, *(undefined1 *)(WwanGlobals + 0xa0) = uVar5,
          (*(uint *)(uVar9 + 0xc0) & 2) != 0) {
      if ((*(uint *)(uVar9 + 0xc0) & 4) != 0) {
        *(undefined8 *)(param_2 + 4) = 2;
        *(uint *)(uVar9 + 0xc0) = *(uint *)(uVar9 + 0xc0) & 0xfffffffb;
        KeReleaseSpinLock(uVar9 + 0x98,*(undefined1 *)(uVar9 + 0xa0));
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return 0;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
        return 0;
      }
      plVar7 = (longlong *)(uVar9 + 0x28);
      plVar3 = (longlong *)*plVar7;
      if (plVar3 == plVar7) goto LAB_1c0007ae9;
      if (((longlong *)plVar3[1] != plVar7) ||
         (lVar8 = *plVar3, (longlong *)*(longlong *)(lVar8 + 8) != plVar3)) {
LAB_1c0007ae2:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar10 = auStack_40;
LAB_1c0007ae9:
        *(undefined8 *)(puVar10 + -8) = 0x1c0007afa;
        IoCsqInsertIrp(uVar9 + 0x38,param_1,0);
        uVar5 = *(undefined1 *)(WwanGlobals + 0xa0);
        *(undefined8 *)(puVar10 + -8) = 0x1c0007b1a;
        KeReleaseSpinLock(WwanGlobals + 0x98,uVar5);
        return 0x103;
      }
      *plVar7 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar7;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((4 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,param_3,
                  *(undefined4 *)(plVar3 + 2),(char)*(undefined4 *)(plVar3 + 4));
      }
      uVar1 = *(uint *)((longlong)plVar3 + 0x14);
      uVar9 = (ulonglong)uVar1;
      if ((0x1f < uVar1 + 0x20) &&
         (uVar11 = *(int *)(plVar3 + 3) + 0x20 + uVar1, uVar1 + 0x20 <= uVar11)) {
        if (uVar11 <= param_4) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,param_3,
                      *(undefined4 *)(plVar3 + 2),(char)*(undefined4 *)(plVar3 + 4));
          }
          *param_2 = *(undefined4 *)(plVar3 + 2);
          param_2[2] = *(undefined4 *)((longlong)plVar3 + 0x14);
          *(longlong *)(param_2 + 6) = plVar3[4];
          uVar2 = *(undefined4 *)(plVar3 + 3);
          *(undefined8 *)(param_2 + 4) = 0;
          param_2[3] = uVar2;
          uVar1 = *(uint *)((longlong)plVar3 + 0x14);
          memcpy(param_2 + 8,plVar3 + 5,(ulonglong)uVar1);
          memcpy((void *)((ulonglong)uVar1 + (longlong)(param_2 + 8)),
                 (void *)((ulonglong)uVar1 + (longlong)(plVar3 + 5)),
                 (ulonglong)*(uint *)(plVar3 + 3));
          WwanFreeIndication(plVar3,*(int *)((longlong)plVar3 + 0x14));
          KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
          *param_5 = uVar11;
          return 0;
        }
        plVar7 = (longlong *)(WwanGlobals + 0x28);
        lVar8 = *plVar7;
        if (*(longlong **)(lVar8 + 8) == plVar7) {
          *plVar3 = lVar8;
          plVar3[1] = (longlong)plVar7;
          *(longlong **)(lVar8 + 8) = plVar3;
          *plVar7 = (longlong)plVar3;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,param_3,
                      *(undefined4 *)(plVar3 + 2),(char)*(undefined4 *)(plVar3 + 4));
          }
          KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
          *(undefined8 *)(param_2 + 4) = 1;
          param_2[1] = uVar11;
          return 0;
        }
        goto LAB_1c0007ae2;
      }
      WwanFreeIndication(plVar3,uVar1);
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      uVar9 = WwanGlobals;
      *(undefined8 *)(param_2 + 4) = 0;
      *param_5 = 0x20;
      uVar5 = KeAcquireSpinLockRaiseToDpc(uVar9 + 0x98);
    }
    KeReleaseSpinLock(uVar9 + 0x98,*(undefined1 *)(uVar9 + 0xa0));
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
              &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
    }
    uVar6 = 0xc0000001;
  }
  return uVar6;
}



===== WwanprotRegisterIndication @ 1c0007b8c =====

undefined8 WwanprotRegisterIndication(void)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  lVar1 = WwanGlobals;
  *(uint *)(WwanGlobals + 0xc0) = *(uint *)(WwanGlobals + 0xc0) | 2;
  *(undefined1 *)(lVar1 + 0xa0) = uVar2;
  KeReleaseSpinLock(lVar1 + 0x98,uVar2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  return 0;
}



===== WwanprotReportNicAoacCompliance @ 1c0007c18 =====

int WwanprotReportNicAoacCompliance
              (uint *param_1,uint param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  uVar7 = (ulonglong)param_2;
  *param_4 = 0;
  if (param_2 < 8) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar6 = 0x52;
    uVar8 = 0;
  }
  else {
    uVar1 = *param_1;
    if (7 < uVar1 + 8) {
      uVar2 = param_1[1];
      uVar8 = uVar2 + 8 + uVar1;
      if (uVar1 + 8 <= uVar8) {
        if (uVar8 <= param_2) {
          uVar3 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
          *(undefined1 *)(WwanGlobals + 0xa0) = uVar3;
          puVar5 = WwanFindContext((char *)((longlong)(param_1 + 2) + (ulonglong)uVar1),uVar2,uVar7)
          ;
          if (puVar5 == (undefined8 *)0x0) {
            KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return -0x3fffffff;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
              return -0x3fffffff;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
              return -0x3fffffff;
            }
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                    &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
            return -0x3fffffff;
          }
          WwanRefOpen((longlong)puVar5,"WwanprotReportNicAoacCompliance",0x75d);
          KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
          iVar4 = iReportNicAOACCompliance((longlong)puVar5,(char)param_1[2]);
          WwanDerefOpen((longlong)puVar5,"WwanprotReportNicAoacCompliance",0x765);
          if (iVar4 == 0) {
            return 0;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar4;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar4;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return iVar4;
          }
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                   &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar4);
          return iVar4;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x3fffffff;
        }
        uVar6 = 0x54;
        goto LAB_1c0007e3b;
      }
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar6 = 0x53;
    uVar8 = 8;
  }
LAB_1c0007e3b:
  WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar7,param_2,(char)uVar8);
  return -0x3fffffff;
}



===== WwanprotSetOid @ 1c0007e6c =====

int WwanprotSetOid(uint *param_1,uint param_2,undefined8 param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  undefined7 extraout_var;
  undefined8 *puVar7;
  undefined2 uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  *param_4 = 0;
  if (param_2 < 0x18) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar8 = 0x29;
  }
  else {
    uVar1 = param_1[2];
    if (uVar1 + 0x18 < 0x18) {
      return -0x3fffffff;
    }
    uVar2 = param_1[3];
    uVar9 = uVar2 + 0x18 + uVar1;
    uVar10 = (ulonglong)uVar9;
    if (uVar9 < uVar1 + 0x18) {
      return -0x3fffffff;
    }
    if (param_2 < uVar9) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffffff;
      }
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,uVar10,param_2,(char)uVar9);
      return -0x3fffffff;
    }
    uVar9 = *param_1;
    bVar4 = WwanSupportedOid(uVar9);
    if ((int)CONCAT71(extraout_var,bVar4) == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffffff;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar9);
      return -0x3fffffff;
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
    *(undefined1 *)(WwanGlobals + 0xa0) = uVar5;
    puVar7 = WwanFindContext((void *)((longlong)(param_1 + 6) + (ulonglong)uVar1),uVar2,uVar10);
    if (puVar7 != (undefined8 *)0x0) {
      WwanRefOpen((longlong)puVar7,"WwanprotSetOid",0x3ec);
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      uVar3 = *(undefined8 *)(param_1 + 4);
      uVar2 = *param_1;
      *param_4 = 0x18;
      iVar6 = WwanOidRequest((longlong)puVar7,(ulonglong)uVar2,(undefined *)0x1,uVar3,param_1 + 6,
                             uVar1,param_1 + 1);
      WwanDerefOpen((longlong)puVar7,"WwanprotSetOid",0x3f7);
      if ((iVar6 + 0x3ffeffecU & 0xfffffffd) == 0) {
        iVar6 = -0x3fffffdd;
      }
      else if (iVar6 == 0x40230001) {
        *param_4 = 0;
      }
      else {
        *param_4 = param_1[1] + 0x18;
      }
      return iVar6;
    }
    KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffffff;
    }
    uVar8 = 0x2c;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
          &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  return -0x3fffffff;
}



===== WwanprotUpdateDeviceProperties @ 1c00080c8 =====

int WwanprotUpdateDeviceProperties
              (uint *param_1,uint param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  uint uVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  wchar_t *local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 uVar11;
  wchar_t *pwVar10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  uVar8 = (ulonglong)param_2;
  *param_4 = 0;
  if (param_2 < 8) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,uVar8,param_2,0);
    }
    return -0x3fffffdd;
  }
  uVar1 = *param_1;
  if (7 < uVar1 + 8) {
    uVar2 = param_1[1];
    uVar6 = uVar2 + 8 + uVar1;
    if (uVar1 + 8 <= uVar6) {
      if (param_2 < uVar6) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x7ffffffb;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return -0x7ffffffb;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x7ffffffb;
        }
        WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar6,uVar8,param_2,
                    (char)uVar6,(char)uVar1,(char)uVar2);
        return -0x7ffffffb;
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
      *(undefined1 *)(WwanGlobals + 0xa0) = uVar3;
      puVar5 = WwanFindContext((void *)((ulonglong)uVar1 + 8 + (longlong)param_1),uVar2,uVar8);
      if (puVar5 == (undefined8 *)0x0) {
        KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                  &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
        }
        return -0x3fffffff;
      }
      WwanRefOpen((longlong)puVar5,"WwanprotUpdateDeviceProperties",0x64f);
      KeReleaseSpinLock(WwanGlobals + 0x98,*(undefined1 *)(WwanGlobals + 0xa0));
      uVar9 = 0;
      local_res20 = (wchar_t *)0x0;
      iVar4 = IoGetDeviceInterfaces(&GUID_DEVINTERFACE_NET,puVar5[0x21],0,&local_res20);
      if ((iVar4 == 0) && (*local_res20 != L'\0')) {
        local_18 = 0;
        uStack_10 = 0;
        pwVar7 = local_res20;
        RtlInitUnicodeString(&local_18);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((3 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
            ))) {
          pwVar10 = local_res20;
          WPP_SF__guid_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar7,uVar9,puVar5 + 10,
                         local_res20);
          uVar11 = (undefined4)((ulonglong)pwVar10 >> 0x20);
        }
        iVar4 = IoSetDeviceInterfacePropertyData
                          (&local_18,&DEVPKEY_Wwan_InterfaceGuid,0,0,CONCAT44(uVar11,0xd),0x10,
                           puVar5 + 10);
      }
      if (local_res20 != (wchar_t *)0x0) {
        ExFreePoolWithTag(local_res20,0);
        local_res20 = (wchar_t *)0x0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar4);
      }
      WwanDerefOpen((longlong)puVar5,"WwanprotUpdateDeviceProperties",0x655);
      if (iVar4 == 0) {
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar4;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar4);
      return iVar4;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,uVar8,param_2,8);
  }
  return -0x7ffffffb;
}



===== WwanCsqAcquireLock @ 1c0008430 =====

void WwanCsqAcquireLock(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  *(undefined1 *)(param_1 + 0x58) = uVar1;
  return;
}



===== WwanCsqCompleteCanceledIrp @ 1c0008460 =====

void WwanCsqCompleteCanceledIrp(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== WwanCsqInsertIrpEx @ 1c0008490 =====

undefined8 WwanCsqInsertIrpEx(longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar2 = *(longlong **)(param_1 + 0x48);
  lVar3 = param_1 + 0x40;
  plVar4 = (longlong *)(param_2 + 0xa8);
  if (*plVar2 != lVar3) {
    lVar3 = 3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  plVar4[1] = (longlong)plVar2;
  *plVar4 = lVar3;
  *plVar2 = (longlong)plVar4;
  *(longlong **)(lVar3 + 8) = plVar4;
  return 0;
}



===== WwanCsqPeekNextIrp @ 1c00084d0 =====

longlong WwanCsqPeekNextIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)(param_2 + 0xa8);
  if (param_2 == 0) {
    plVar1 = (longlong *)(param_1 + 0x40);
  }
  lVar2 = (longlong)((longlong *)*plVar1 + -0x15);
  if ((longlong *)*plVar1 == (longlong *)(param_1 + 0x40)) {
    lVar2 = 0;
  }
  return lVar2;
}



===== WwanCsqReleaseLock @ 1c0008500 =====

void WwanCsqReleaseLock(longlong param_1)

{
  KeReleaseSpinLock(param_1 + 0x50,*(undefined1 *)(param_1 + 0x58));
  return;
}



===== WwanCsqRemoveIrp @ 1c0008530 =====

void WwanCsqRemoveIrp(undefined8 param_1,longlong param_2)

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



===== WPP_SF_DS @ 1c0008560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,param_2,local_res20,4,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_SD @ 1c00085f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
            (param_1,0x2b,&WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,param_2,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF_qDS @ 1c0008680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,0x12,&local_res20,8,
             &param_5,4,pwVar2,lVar1,0);
  return;
}



===== WwanprotBindAdapter @ 1c0008734 =====

int WwanprotBindAdapter(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  ushort uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 *puVar7;
  wchar_t *pwVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 local_res8 [8];
  undefined4 *local_res20;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  undefined1 in_stack_ffffffffffffff98;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res20 = (undefined4 *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  NdisAllocateMemoryWithTag(&local_res20,0x118,0x4e415757);
  if (local_res20 == (undefined4 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,
               *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8));
    }
  }
  else {
    memset(local_res20,0,0x118);
    local_res20[6] = 0xdeafdead;
    puVar7 = local_res20 + 2;
    *(undefined4 **)(local_res20 + 4) = puVar7;
    *(undefined4 **)puVar7 = puVar7;
    KeInitializeSpinLock(local_res20 + 10);
    NdisInitializeEvent(local_res20 + 0x1a);
    local_res20[0x20] = 0;
    NdisInitializeEvent(local_res20 + 0x22);
    NdisInitializeEvent(local_res20 + 0x28);
    NdisSetEvent(local_res20 + 0x22);
    NdisSetEvent(local_res20 + 0x28);
    uVar13 = 0x4e415757;
    uVar1 = **(ushort **)(param_3 + 0x10);
    NdisAllocateMemoryWithTag(local_res20 + 0x12,uVar1 + 2);
    if (*(void **)(local_res20 + 0x12) != (void *)0x0) {
      memcpy(*(void **)(local_res20 + 0x12),*(void **)(*(longlong *)(param_3 + 0x10) + 8),
             (ulonglong)uVar1);
      *(undefined2 *)(*(longlong *)(local_res20 + 0x12) + (ulonglong)(uVar1 >> 1) * 2) = 0;
      *(ushort *)(local_res20 + 0x10) = uVar1;
      *(ushort *)((longlong)local_res20 + 0x42) = uVar1 + 2;
      *(undefined8 *)(local_res20 + 0x14) = 0;
      *(undefined8 *)(local_res20 + 0x16) = 0;
      pwVar8 = wcsrchr(*(wchar_t **)(local_res20 + 0x12),L'{');
      RtlInitUnicodeString(&local_48,pwVar8);
      RtlGUIDFromString(&local_48,local_res20 + 0x14);
      WwanRefOpen((longlong)local_res20,"WwanprotBindAdapter",0x15a);
      *local_res20 = 0x1000;
      *(undefined8 *)(local_res20 + 0x42) = *(undefined8 *)(param_3 + 0x18);
      iVar6 = WwanCreateBinding((longlong)local_res20,param_3,param_2,param_4,
                                in_stack_ffffffffffffff98);
      lVar4 = WwanGlobals;
      if (iVar6 == 0) {
        uVar5 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
        lVar14 = WwanGlobals;
        puVar12 = auStack_88;
        *(undefined1 *)(lVar4 + 0xa0) = uVar5;
        plVar10 = (longlong *)(local_res20 + 2);
        lVar9 = lVar14 + 0x18;
        plVar11 = *(longlong **)(lVar14 + 0x20);
        if (*plVar11 != lVar9) {
          plVar10 = (longlong *)0x3;
          pcVar3 = (code *)swi(0x29);
          lVar9 = (*pcVar3)();
          puVar12 = auStack_80;
        }
        *plVar10 = lVar9;
        plVar10[1] = (longlong)plVar11;
        *plVar11 = (longlong)plVar10;
        *(longlong **)(lVar9 + 8) = plVar10;
        uVar5 = *(undefined1 *)(lVar4 + 0xa0);
        *(undefined8 *)(puVar12 + -8) = 0x1c0008a96;
        KeReleaseSpinLock(lVar14 + 0x98,uVar5);
        puVar2 = *(undefined8 **)(param_3 + 0x108);
        uVar13 = puVar2[1];
        *(undefined8 *)(local_res20 + 0x2e) = *puVar2;
        *(undefined8 *)(local_res20 + 0x30) = uVar13;
        uVar13 = puVar2[3];
        *(undefined8 *)(local_res20 + 0x32) = puVar2[2];
        *(undefined8 *)(local_res20 + 0x34) = uVar13;
        uVar13 = puVar2[5];
        *(undefined8 *)(local_res20 + 0x36) = puVar2[4];
        *(undefined8 *)(local_res20 + 0x38) = uVar13;
        *(undefined8 *)(local_res20 + 0x3a) = puVar2[6];
        local_res20[0x3c] = *(undefined4 *)(puVar2 + 7);
        *(undefined8 *)(local_res20 + 0x40) = *(undefined8 *)(param_3 + 0xa8);
        if (((((*(char *)((longlong)local_res20 + 0xb9) == '\x02') && ((local_res20[0x30] & 1) != 0)
              ) && ((0xf < (uint)local_res20[0x31] &&
                    ((0x49 < (uint)local_res20[0x32] && (local_res20[0x39] - 3 < 2)))))) &&
            (((byte)local_res20[0x3c] & 3) == 3)) && ((local_res20[0x3b] & 2) != 0)) {
          local_res20[0x3d] = 1;
        }
        if (local_res20[0x3d] == 0) {
          if (DAT_1c000d360 != '\0') {
            *(undefined1 **)(puVar12 + 0x30) = local_res8;
            *(undefined4 *)(puVar12 + 0x28) = 0;
            *(undefined8 *)(puVar12 + 0x20) = 0;
            *(undefined8 *)(puVar12 + -8) = 0x1c0008b8e;
            iVar6 = WwanOidRequest((longlong)local_res20,0xfd010111,(undefined *)0x1,0,
                                   *(undefined8 *)(puVar12 + 0x20),*(undefined4 *)(puVar12 + 0x28),
                                   *(undefined4 **)(puVar12 + 0x30));
            if ((((iVar6 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              uVar13 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar12 + -8) = 0x1c0008bc4;
              WPP_SF_D(uVar13,10,&WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,iVar6);
            }
          }
        }
        else {
          *(undefined8 *)(puVar12 + -8) = 0x1c0008b5f;
          iEnableWakeCapabilities((longlong)local_res20);
        }
        *(undefined8 *)(puVar12 + -8) = 0x1c0008bcf;
        iReportNicAOACCompliance((longlong)local_res20,'\x01');
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar13 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          pwVar8 = *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8);
          *(undefined8 *)(puVar12 + -8) = 0x1c0008c05;
          WPP_SF_S(uVar13,0xe,&WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,pwVar8);
        }
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,param_2,
                  *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8),(char)iVar6);
      }
      goto LAB_1c0008a0f;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,uVar13,
                *(wchar_t **)(*(longlong *)(param_3 + 0x10) + 8),(char)(uVar1 + 2));
    }
  }
  iVar6 = -0x3fffff66;
LAB_1c0008a0f:
  if (local_res20 != (undefined4 *)0x0) {
    WwanDerefOpen((longlong)local_res20,"WwanprotBindAdapter",0x18e);
  }
  return iVar6;
}



===== WwanprotUnbindAdapter @ 1c0008c2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WwanprotUnbindAdapter(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined8 local_2c;
  undefined8 uStack_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (*(int *)(param_1 + 0x18) != -0x21502153) {
    WwanAssertFailed("WwanprotUnbindAdapter",0x19d,param_3);
  }
  WwanResumeIO(param_1);
  local_2c = 0;
  uStack_24 = 0;
  LOCK();
  iVar8 = *(int *)(param_1 + 0xf8);
  *(int *)(param_1 + 0xf8) = 0;
  UNLOCK();
  if (iVar8 != 0) {
    local_30 = 0x140280;
    WwanOidRequest(param_1,0xfd010109,(undefined *)0x1,0,&local_30,0x14,local_38);
  }
  iReportNicAOACCompliance(param_1,'\0');
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 4;
  *(undefined1 *)(param_1 + 0x30) = uVar7;
  NdisSetEvent(param_1 + 0x88);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  KeReleaseSpinLock(param_1 + 0x28,*(undefined1 *)(param_1 + 0x30));
  WwanWaitForPendingIOs(param_1);
  NdisResetEvent(param_1 + 0x68);
  iVar8 = NdisCloseAdapterEx(*(undefined8 *)(param_1 + 0x38));
  if (iVar8 == 0x103) {
    NdisWaitEvent(param_1 + 0x68,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,*(wchar_t **)(param_1 + 0x48));
    }
  }
  lVar5 = WwanGlobals;
  uVar7 = KeAcquireSpinLockRaiseToDpc(WwanGlobals + 0x98);
  *(undefined1 *)(lVar5 + 0xa0) = uVar7;
  lVar6 = WwanGlobals;
  plVar1 = (longlong *)(param_1 + 8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x10), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(lVar6 + 0x98,*(undefined1 *)(lVar5 + 0xa0));
    WwanDerefOpen(param_1,"WwanprotUnbindAdapter",0x1c8);
    return 0;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar9 = (*pcVar4)();
  return uVar9;
}



===== iEnableWakeCapabilities @ 1c0008e54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iEnableWakeCapabilities(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined8 local_2c;
  undefined4 local_24;
  uint local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_2c = 0;
  local_24 = 0;
  if (*(int *)(param_1 + 0xf4) != 0) {
    uVar1 = *(uint *)(param_1 + 0xf0);
    local_30 = 0x140280;
    uVar4 = uVar1 & 1 | 2;
    if ((uVar1 & 2) == 0) {
      uVar4 = uVar1 & 1;
    }
    uVar3 = uVar4 | 4;
    if ((uVar1 & 4) == 0) {
      uVar3 = uVar4;
    }
    uVar4 = uVar3 | 8;
    if ((uVar1 & 8) == 0) {
      uVar4 = uVar3;
    }
    local_20 = uVar4 | 0x10;
    if ((*(byte *)(param_1 + 0xf0) & 0x10) == 0) {
      local_20 = uVar4;
    }
    iVar2 = WwanOidRequest(param_1,0xfd010109,(undefined *)0x1,0,&local_30,0x14,local_38);
    if (iVar2 == 0) {
      LOCK();
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
      UNLOCK();
    }
  }
  return;
}



===== iReportNicAOACCompliance @ 1c0008f24 =====

int iReportNicAOACCompliance(longlong param_1,char param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_18;
  undefined4 local_10;
  char local_c;
  undefined1 local_b;
  undefined2 local_a;
  
  if (DAT_1c000d360 == '\0') {
    return 0;
  }
  local_18 = *(undefined8 *)(param_1 + 0x108);
  local_a = 0;
  local_b = *(undefined1 *)(param_1 + 0xf4);
  local_10 = 2;
  local_c = param_2;
  if (param_2 == '\0') {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x110);
    *(int *)(param_1 + 0x110) = 0;
    UNLOCK();
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = 0x10;
    iVar1 = ZwPowerInformation(0x4a,&local_18,0x10,0,0);
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  else {
    uVar2 = 0x10;
    iVar1 = ZwPowerInformation(0x4a,&local_18,0x10,0,0);
    if (-1 < iVar1) {
      if (*(int *)(param_1 + 0x110) != 0) {
        WwanAssertFailed("iReportNicAOACCompliance",0xd7,uVar2);
      }
      *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
      return iVar1;
    }
  }
  WwanAssertFailed("iReportNicAOACCompliance",0xe5,uVar2);
  return iVar1;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c0009014 =====

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



===== _guard_check_icall @ 1c0009070 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0009088 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00090ac =====

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



===== __cpu_features_init @ 1c0009120 =====

/* WARNING: Removing unreachable block (ram,0x0001c000918a) */
/* WARNING: Removing unreachable block (ram,0x0001c0009139) */
/* WARNING: Removing unreachable block (ram,0x0001c000912a) */

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



===== __security_check_cookie @ 1c00091f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0009230 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0009260 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0009260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0009290 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c00092e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0009323;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0009394;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0009390:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0009394;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c000938c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0009390;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c000938c;
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
LAB_1c0009394:
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
LAB_1c0009323:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0009400 =====

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



===== memset @ 1c0009700 =====

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



===== __memset_repmovs @ 1c0009840 =====

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



===== __memset_query @ 1c00098c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0009940 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0009a80 =====

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



===== __memset_spec_plain @ 1c0009b00 =====

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



===== NdisuioClose @ 1c0010010 =====

undefined8 NdisuioClose(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  lVar4 = param_2;
  bVar2 = IsWwanDosDevice(param_1);
  if (bVar2) {
    uVar3 = WwanprotClose(param_2,lVar4,param_3);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0xb8);
    lVar1 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x18);
    if (lVar1 != 0) {
      ndisuioDerefOpen(lVar1);
    }
    *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x18) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    uVar3 = 0;
  }
  return uVar3;
}



===== NdisuioIoControl @ 1c0010080 =====

ulonglong NdisuioIoControl(longlong param_1,char *param_2,ulonglong param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  uint uVar10;
  uint local_res18 [2];
  longlong local_res20;
  
  pcVar9 = param_2;
  bVar4 = IsWwanDosDevice(param_1);
  uVar10 = 0;
  if (bVar4) {
    uVar7 = WwanprotIoControl(param_2,pcVar9,param_3);
    return uVar7;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res18[0] = 0;
  lVar3 = *(longlong *)(lVar2 + 0x30);
  iVar1 = *(int *)(lVar2 + 0x18);
  local_res20 = *(longlong *)(lVar3 + 0x18);
  if (iVar1 == 0x12c800) {
LAB_1c00102e1:
    if (local_res20 == 0) {
      if (iVar1 == 0x12c800) {
        uVar6 = ndisuioOpenDevice(*(int **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10),lVar3,
                                  &local_res20);
      }
      else {
        uVar6 = ndisuioOpenDeviceEx(*(int **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10),lVar3,
                                    &local_res20);
      }
      goto LAB_1c001030d;
    }
    uVar10 = 0x80000011;
  }
  else if (iVar1 == 0x12c804) {
    if (local_res20 == 0) {
LAB_1c00102da:
      uVar10 = 0xc000009d;
      goto LAB_1c001030f;
    }
    uVar6 = ndisuioQueryOidValue
                      (local_res20,*(undefined4 **)(param_2 + 0x18),*(uint *)(lVar2 + 8),local_res18
                      );
    if ((((uVar6 == 0) || (uVar6 == 0x103)) || (uVar6 == 0x80000005)) ||
       (((uVar6 == 0xc0000001 || (uVar6 == 0xc000009a)) || (uVar6 == 0xc00000bb))))
    goto LAB_1c001030d;
    if (uVar6 == 0xc0010016) goto LAB_1c0010136;
    if (uVar6 == 0xc0010014) {
LAB_1c001014b:
      uVar10 = 0xc0000206;
    }
    else {
      if (uVar6 == 0xc0010015) goto LAB_1c0010155;
      if (uVar6 != 0xc0010006) {
        uVar10 = 0xc0000001;
        if (uVar6 == 0xc0010011) {
          uVar10 = 0xc00000a3;
        }
        goto LAB_1c0010313;
      }
LAB_1c0010166:
      uVar10 = 0x8000001a;
    }
  }
  else if (iVar1 == 0x12c808) {
    if (*(uint *)(lVar2 + 0x10) < 2) {
LAB_1c0010136:
      uVar10 = 0xc0000023;
    }
    else {
      if (**(short **)(param_2 + 0x18) == -0x7178) {
        DAT_1c000d318 = 0x8e88;
        goto LAB_1c0010313;
      }
LAB_1c0010155:
      uVar10 = 0xc000000d;
    }
  }
  else {
    if (iVar1 == 0x12c80c) {
      uVar8 = ndisuioQueryBinding(*(int **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10),
                                  *(uint *)(lVar2 + 8),(int *)local_res18);
      uVar6 = (uint)uVar8;
    }
    else {
      if (iVar1 == 0x12c810) {
        cVar5 = NdisWaitEvent(&DAT_1c000d348,5000);
        uVar10 = ~-(uint)(cVar5 != '\0') & 0x102;
        goto LAB_1c001030f;
      }
      if (iVar1 != 0x12c814) {
        if (iVar1 == 0x12c818) goto LAB_1c00102e1;
        uVar10 = 0xc00000bb;
        goto LAB_1c0010313;
      }
      if (local_res20 == 0) goto LAB_1c00102da;
      uVar6 = ndisuioSetOidValue(local_res20,*(int **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10));
    }
    if (((uVar6 != 0) && (uVar6 != 0x103)) && (uVar6 != 0x80000005)) {
      uVar10 = 0xc0000001;
      if (((uVar6 != 0xc0000001) && (uVar6 != 0xc000009a)) && (uVar6 != 0xc00000bb)) {
        if (uVar6 == 0xc0010016) goto LAB_1c0010136;
        if (uVar6 == 0xc0010014) goto LAB_1c001014b;
        if (uVar6 != 0xc0010015) {
          if (uVar6 == 0xc0010006) goto LAB_1c0010166;
          if (uVar6 == 0xc0010011) {
            uVar10 = 0xc00000a3;
          }
          goto LAB_1c0010313;
        }
        goto LAB_1c0010155;
      }
    }
LAB_1c001030d:
    uVar10 = uVar6;
LAB_1c001030f:
    if (uVar10 == 0x103) goto LAB_1c001032f;
  }
LAB_1c0010313:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res18[0];
  *(uint *)(param_2 + 0x30) = uVar10;
  IofCompleteRequest(param_2,0);
LAB_1c001032f:
  return (ulonglong)uVar10;
}



===== NdisuioOpen @ 1c0010350 =====

undefined4 NdisuioOpen(longlong param_1,longlong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = IsWwanDosDevice(param_1);
  if (bVar1) {
    uVar2 = WwanprotOpen(param_2,0,param_2);
  }
  else {
    *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2);
    uVar2 = 0;
  }
  return uVar2;
}



===== NdisuioUnload @ 1c00103a0 =====

void NdisuioUnload(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined *puVar2;
  wchar_t *pwVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  pwVar3 = L"\\DosDevices\\Ndisuio";
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  IoDeleteSymbolicLink(&local_18);
  lVar1 = DAT_1c000d308;
  if (DAT_1c000d308 != 0) {
    IoDeleteDevice();
    DAT_1c000d308 = 0;
  }
  if (WwanIsInitialized != '\0') {
    WwanDeleteDeviceFile();
  }
  ndisuioDoProtocolUnload();
  if (WwanIsInitialized != '\0') {
    WwanprotDeregisterIndication(lVar1,pwVar3,param_3);
    puVar2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      param_3 = &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids;
      pwVar3 = (wchar_t *)0xc;
      WPP_SF_(puVar2,0xc,&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids);
    }
    WwanDeInitWwanGlobals(puVar2,pwVar3,param_3);
    if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(puVar2,&StopWWanNDSIUIO);
    }
    McGenEventUnregister_EtwUnregister();
    WppCleanupKm();
    WwanIsInitialized = '\0';
  }
  return;
}



===== WppCleanupKm @ 1c0010484 =====

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



===== WppInitKm @ 1c0010504 =====

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



===== WppLoadTracingSupport @ 1c0010594 =====

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



===== WppTraceCallback @ 1c00106e0 =====

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



===== WwanCreateDeviceFile @ 1c0010968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WwanCreateDeviceFile(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 local_res10 [3];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_38,L"\\Device\\WwanProt");
  RtlInitUnicodeString(&local_28,L"D:P(A;;GA;;;BA)");
  if (WdmlibInitialized == '\0') {
    local_48 = 0;
    uStack_40 = 0;
    RtlInitUnicodeString(&local_48,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_48);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_48,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_48);
    WdmlibInitialized = '\x01';
  }
  iVar1 = (*PfnIoCreateDeviceSecure)(param_1,0,&local_38,0x12,0x100,0,&local_28,0,local_res10);
  if (iVar1 == 0) {
    iVar1 = WwanSetDeviceDacl();
    if (iVar1 < 0) {
      IoDeleteDevice(local_res10[0]);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar1;
      }
      uVar2 = 0x19;
    }
    else {
      RtlInitUnicodeString(&local_18,L"\\DosDevices\\WwanProt");
      iVar1 = IoCreateSymbolicLink(&local_18,&local_38);
      if (iVar1 == 0) {
        *WwanGlobals = local_res10[0];
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                   &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,0);
        }
        return 0;
      }
      IoDeleteDevice(local_res10[0]);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar1;
      }
      uVar2 = 0x1a;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (WPP_GLOBAL_Control[0x29] == '\0') {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    uVar2 = 0x18;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar1);
  return iVar1;
}



===== WwanDeInitWwanGlobals @ 1c0010bec =====

void WwanDeInitWwanGlobals(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if (WwanGlobals != 0) {
    if (*(longlong **)(WwanGlobals + 0x18) != (longlong *)(WwanGlobals + 0x18)) {
      WwanAssertFailed("WwanDeInitWwanGlobals",0x282,param_3);
    }
    if (*(longlong **)(WwanGlobals + 0x28) != (longlong *)(WwanGlobals + 0x28)) {
      WwanAssertFailed("WwanDeInitWwanGlobals",0x283,param_3);
    }
    if (*(longlong **)(WwanGlobals + 0x78) != (longlong *)(WwanGlobals + 0x78)) {
      WwanAssertFailed("WwanDeInitializeCSQ",0x90,param_3);
    }
    WwanGlobals = 0;
  }
  return;
}



===== WwanDeleteDeviceFile @ 1c0010c6c =====

void WwanDeleteDeviceFile(void)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"\\DosDevices\\WwanProt");
  iVar1 = IoDeleteSymbolicLink(&local_18);
  if ((((iVar1 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      (1 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar1);
  }
  IoDeleteDevice(*WwanGlobals);
  *WwanGlobals = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar1);
  }
  return;
}



===== WwanInitWwanGlobals @ 1c0010d4c =====

void WwanInitWwanGlobals(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  WwanGlobals = &g_Wwan;
  memset(&g_Wwan,0,0xd8);
  KeInitializeSpinLock(&DAT_1c000d4b8);
  puVar2 = WwanGlobals;
  puVar1 = WwanGlobals + 0x18;
  *(undefined **)(WwanGlobals + 0x20) = puVar1;
  *(undefined **)puVar1 = puVar1;
  puVar1 = puVar2 + 0x28;
  *(undefined **)(puVar2 + 0x30) = puVar1;
  *(undefined **)puVar1 = puVar1;
  NdisInitializeEvent(puVar2 + 0xa8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,0xffffffff,0,0);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if ((2 < (byte)WPP_GLOBAL_Control[0x29]) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
               &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,0x40000);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,0x40000);
    }
  }
  puVar2 = WwanGlobals;
  *(undefined4 *)(WwanGlobals + 200) = 0;
  *(undefined4 *)(puVar2 + 0xc4) = 0x40000;
  memset(puVar2 + 0x38,0,0x60);
  puVar1 = puVar2 + 0x78;
  *(undefined **)(puVar2 + 0x80) = puVar1;
  *(undefined **)puVar1 = puVar1;
  KeInitializeSpinLock(puVar2 + 0x88);
  IoCsqInitializeEx(puVar2 + 0x38,WwanCsqInsertIrpEx,WwanCsqRemoveIrp,WwanCsqPeekNextIrp,
                    WwanCsqAcquireLock,WwanCsqReleaseLock,WwanCsqCompleteCanceledIrp);
  return;
}



===== WwanprotPnPEvent @ 1c0010f08 =====

undefined8 WwanprotPnPEvent(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  
  lVar2 = WwanGlobals;
  iVar1 = *(int *)(param_2 + 8);
  uVar3 = 0;
  if (iVar1 < 6) {
    if (iVar1 == 5) {
      return 0;
    }
    if (iVar1 == 0) {
      if ((*(uint *)(WwanGlobals + 0xc0) & 2) == 0) {
        return 0;
      }
      WwanprotDeliverPnPEvent(param_1,param_2,0);
      return 0;
    }
    if (iVar1 == 1) {
      return 0;
    }
    if (iVar1 == 2) {
      return 0;
    }
    if (iVar1 == 3) {
      return 0;
    }
    bVar4 = iVar1 == 4;
  }
  else {
    if (iVar1 == 6) {
      *(uint *)(WwanGlobals + 0xc0) = *(uint *)(WwanGlobals + 0xc0) | 1;
      NdisSetEvent(lVar2 + 0xa8);
      return 0;
    }
    if (iVar1 == 7) {
      return 0;
    }
    if (iVar1 == 8) {
      if (DAT_1c000d4f4 == 0) {
        return 0;
      }
      WwanPauseIO(param_1);
      WwanWaitForPendingIOs(param_1);
      return 0;
    }
    if (iVar1 == 9) {
      if (DAT_1c000d4f4 == 0) {
        return 0;
      }
      WwanResumeIO(param_1);
      return 0;
    }
    bVar4 = iVar1 == 0x10;
  }
  if (!bVar4) {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== WwanOidRequest @ 1c0010fec =====

int WwanOidRequest(longlong param_1,ulonglong param_2,undefined *param_3,undefined8 param_4,
                  undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined *puVar12;
  undefined1 uVar13;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_48 = (undefined4 *)0x0;
  uVar7 = param_2;
  puVar12 = param_3;
  if (1 < (uint)param_3) {
    uVar7 = 0x165;
    WwanAssertFailed("WwanOidRequest",0x165,param_3);
  }
  uVar5 = WwanGetIOCount(param_1,uVar7,puVar12);
  while( true ) {
    if ((int)uVar5 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
      }
      return -0x3ffefffe;
    }
    uVar5 = 0x118;
    uVar9 = 0x4e415757;
    NdisAllocateMemoryWithTag(&local_48);
    iVar8 = (int)param_2;
    if (local_48 == (undefined4 *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)
         ) {
        uVar5 = 0x18;
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,uVar9,iVar8,0x18);
      }
      WwanReleaseIOCount(param_1,uVar5,uVar9);
      return -0x3fffff66;
    }
    lVar10 = 0x118;
    memset(local_48,0,0x118);
    puVar1 = local_48;
    *local_48 = 0xf80196;
    local_48[1] = (uint)param_3;
    *(undefined8 *)(local_48 + 4) = param_4;
    local_48[8] = iVar8;
    *(undefined8 *)(local_48 + 10) = param_5;
    local_48[0xc] = param_6;
    puVar6 = local_48 + 0x3e;
    NdisInitializeEvent();
    lVar11 = param_1 + 0x50;
    if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
      lVar10 = lVar11;
      McTemplateK0jqqqq_EtwWriteTransfer
                (puVar6,&OidRequestStart,lVar11,lVar11,(char)param_2,(char)param_4,0x8d);
    }
    puVar6 = puVar1;
    iVar3 = NdisOidRequest(*(undefined8 *)(param_1 + 0x38));
    if (iVar3 == 0x103) {
      puVar6 = (undefined4 *)0x0;
      NdisWaitEvent(local_48 + 0x3e);
      iVar3 = local_48[0x44];
    }
    WwanReleaseIOCount(param_1,puVar6,lVar10);
    uVar7 = param_2 & 0xffffffff;
    cVar2 = WwanIsSynchronousOid(iVar8);
    uVar13 = (undefined1)iVar3;
    if ((cVar2 != '\0') && ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0)) {
      McTemplateK0jqqqq_EtwWriteTransfer
                (uVar7,&OidRequestFinish,lVar11,lVar11,uVar13,(char)param_4,0x9a);
      lVar10 = lVar11;
    }
    if (iVar3 != -0x3ffefff3) break;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,lVar10,param_1);
    }
    puVar12 = (undefined *)0x0;
    NdisFreeMemory(local_48,0);
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    NdisInitializeEvent(&local_40);
    uVar5 = 1000;
    NdisWaitEvent(&local_40);
    uVar5 = WwanGetIOCount(param_1,uVar5,puVar12);
  }
  if ((iVar3 + 0x3ffeffecU & 0xfffffffd) == 0) {
    uVar4 = puVar1[0xe];
  }
  else {
    if (iVar3 != 0) {
      if (iVar3 == 0x40230001) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                   &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar8);
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                   &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar8,(char)param_3,uVar13);
      }
      goto LAB_1c001130d;
    }
    uVar4 = puVar1[0xd];
  }
  *param_7 = uVar4;
LAB_1c001130d:
  NdisFreeMemory(local_48,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,iVar8,(char)param_3,uVar13);
  }
  return iVar3;
}



===== WwanSupportedOid @ 1c00113b0 =====

bool WwanSupportedOid(uint param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 < 0xe01012b) {
    if (param_1 == 0xe01012a) {
      return true;
    }
    if (0xe01010e < param_1) {
      if (0xe010118 < param_1) {
        if (param_1 == 0xe010119) {
          return true;
        }
        if (param_1 == 0xe010121) {
          return true;
        }
        if (param_1 == 0xe010122) {
          return true;
        }
        if (param_1 == 0xe010123) {
          return true;
        }
        if (param_1 == 0xe010124) {
          return true;
        }
        if (param_1 == 0xe010125) {
          return true;
        }
        iVar1 = param_1 + 0xf1fefed8;
        goto LAB_1c00114f2;
      }
      if (param_1 == 0xe010118) {
        return true;
      }
      iVar1 = param_1 + 0xf1fefef1;
      bVar2 = iVar1 == 0;
      goto LAB_1c00114cf;
    }
    if (param_1 == 0xe01010e) {
      return true;
    }
    if (0xe010104 < param_1) {
      iVar1 = param_1 + 0xf1fefefb;
      bVar2 = iVar1 == 0;
      goto LAB_1c00114cf;
    }
    if (param_1 == 0xe010104) {
      return true;
    }
    if (param_1 == 0x10101) {
      return true;
    }
    if (param_1 == 0x10103) {
      return true;
    }
    if (param_1 == 0x10110) {
      return true;
    }
    if (param_1 == 0x10202) {
      return true;
    }
    if (param_1 == 0x2021e) {
      return true;
    }
    iVar1 = param_1 + 0xf1feff00;
  }
  else {
    if (param_1 < 0xe01013f) {
      if (param_1 == 0xe01013e) {
        return true;
      }
      switch(param_1) {
      case 0xe01012b:
      case 0xe01012c:
      case 0xe01012d:
      case 0xe01012e:
      case 0xe01012f:
      case 0xe010130:
      case 0xe010131:
      case 0xe010132:
      case 0xe010133:
      case 0xe010134:
      case 0xe010135:
      case 0xe010136:
      case 0xe010137:
      case 0xe010138:
      case 0xe010139:
      case 0xe01013a:
      case 0xe01013b:
      case 0xe01013c:
      case 0xe01013d:
        return true;
      default:
        return false;
      }
    }
    if (0xe010148 < param_1) {
      if (param_1 + 0xf1fefeb7 < 6) {
        return true;
      }
      if (param_1 == 0xfc01020d) {
        return true;
      }
      return param_1 == 0xfd010107;
    }
    if (param_1 == 0xe010148) {
      return true;
    }
    iVar1 = param_1 + 0xf1fefec1;
    bVar2 = iVar1 == 0;
LAB_1c00114cf:
    if (bVar2) {
      return true;
    }
    if (iVar1 == 1) {
      return true;
    }
    if (iVar1 == 2) {
      return true;
    }
    if (iVar1 == 3) {
      return true;
    }
    if (iVar1 == 4) {
      return true;
    }
    iVar1 = iVar1 + -5;
  }
  if (iVar1 == 0) {
    return true;
  }
  if (iVar1 == 1) {
    return true;
  }
  iVar1 = iVar1 + -2;
LAB_1c00114f2:
  if ((iVar1 == 0) || (iVar1 == 1)) {
    return true;
  }
  return false;
}



===== WwanWaitForPendingIOs @ 1c001152c =====

void WwanWaitForPendingIOs(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  NdisWaitEvent(param_1 + 0xa0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids);
  }
  return;
}



===== WwanprotIoControl @ 1c00115c4 =====

ulonglong WwanprotIoControl(char *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  char *pcVar8;
  ulonglong uVar9;
  uint local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0xb8);
  puVar4 = *(uint **)(param_1 + 0x18);
  uVar1 = *(uint *)(lVar3 + 0x18);
  uVar5 = *(uint *)(lVar3 + 0x10);
  uVar2 = *(uint *)(lVar3 + 8);
  pcVar8 = param_1;
  if ((uVar1 & 3) != 0) {
    param_2 = 0x247;
    pcVar8 = "WwanprotIoControl";
    WwanAssertFailed("WwanprotIoControl",0x247,param_3);
  }
  local_res8[0] = 0;
  if (uVar1 < 0x12c815) {
    if (uVar1 == 0x12c814) {
      uVar6 = WwanprotDeregisterIndication(pcVar8,param_2,param_3);
      uVar5 = (uint)uVar6;
    }
    else if (uVar1 == 0x12c800) {
      uVar6 = WwanprotGetDeviceList(puVar4,param_2,(ulonglong)uVar2,local_res8);
      uVar5 = (uint)uVar6;
    }
    else if (uVar1 == 0x12c804) {
      uVar6 = WwanprotOpenNic(puVar4,uVar5,param_3,local_res8);
      uVar5 = (uint)uVar6;
    }
    else if (uVar1 == 0x12c808) {
      uVar5 = WwanprotSetOid(puVar4,uVar5,param_3,(int *)local_res8);
    }
    else if (uVar1 == 0x12c80c) {
      uVar5 = WwanprotQueryOid(puVar4,uVar5,param_3,(int *)local_res8);
    }
    else {
      if (uVar1 != 0x12c810) goto LAB_1c0011734;
      uVar6 = WwanprotRegisterIndication();
      uVar5 = (uint)uVar6;
    }
  }
  else {
    if (uVar1 == 0x12c818) {
      uVar7 = WwanprotReceiveIndication(param_1,puVar4,param_3,uVar2,local_res8);
      uVar9 = uVar7 & 0xffffffff;
      if ((int)uVar7 == 0x103) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,param_1);
        }
        return 0x103;
      }
      goto LAB_1c0011697;
    }
    if (uVar1 == 0x12c81c) {
      uVar5 = WwanprotGetD3ColdCapability(puVar4,uVar5,param_3,local_res8);
    }
    else if (uVar1 == 0x12c820) {
      uVar5 = WwanprotReportNicAoacCompliance(puVar4,uVar5,param_3,local_res8);
    }
    else if (uVar1 == 0x12c824) {
      uVar6 = WwanprotGetDeviceCount((int *)puVar4,param_2,uVar2,local_res8);
      uVar5 = (uint)uVar6;
    }
    else {
      if (uVar1 != 0x12c828) {
LAB_1c0011734:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar1);
        }
        uVar9 = 0xc0000001;
        goto LAB_1c0011697;
      }
      uVar5 = WwanprotUpdateDeviceProperties(puVar4,uVar5,param_3,local_res8);
    }
  }
  uVar9 = (ulonglong)uVar5;
LAB_1c0011697:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (4 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_a8cbe1c0fbe03dbe0be564ac6e76c411_Traceguids,uVar1,(char)uVar9,
               (char)local_res8[0]);
  }
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)local_res8[0];
  *(int *)(param_1 + 0x30) = (int)uVar9;
  IofCompleteRequest(param_1,0);
  return uVar9;
}



===== WwanCreateBinding @ 1c0011828 =====

int WwanCreateBinding(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 local_res20;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  _param_5 = 0;
  local_54 = 0;
  local_res20 = 0x900000000;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_qDS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x1c),*(wchar_t **)(param_1 + 0x48));
  }
  local_50 = *(undefined8 *)(param_2 + 0x10);
  local_54 = 0;
  local_3c = 0;
  local_24 = 0;
  local_30 = 0;
  local_28 = 0;
  local_48 = &local_res20;
  local_38 = &param_5;
  local_58 = 0x380187;
  local_40 = 2;
  NdisResetEvent(param_1 + 0x68);
  puVar2 = &local_58;
  iVar1 = NdisOpenAdapterEx(DAT_1c000d310,param_1,puVar2,param_3,param_1 + 0x38);
  if (iVar1 == 0x103) {
    NdisWaitEvent(param_1 + 0x68,0);
    iVar1 = *(int *)(param_1 + 0x60);
  }
  if (iVar1 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,*(wchar_t **)(param_1 + 0x48));
    }
    iVar1 = 0;
  }
  else if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if ((1 < (byte)WPP_GLOBAL_Control[0x29]) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,puVar2,*(wchar_t **)(param_1 + 0x48)
                ,(char)iVar1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0))
    {
      WPP_SF_DS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,puVar2,iVar1,
                *(wchar_t **)(param_1 + 0x48));
    }
  }
  return iVar1;
}



===== WwanprotCloseAdapterComplete @ 1c00119e4 =====

void WwanprotCloseAdapterComplete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(int *)(param_1 + 0x18) != -0x21502153) {
    WwanAssertFailed("WwanprotCloseAdapterComplete",0x1e9,param_3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_c6587cb73c723c6303c92f65792488f3_Traceguids,*(wchar_t **)(param_1 + 0x48));
  }
  NdisSetEvent(param_1 + 0x68);
  return;
}



===== WwanprotOpenAdapterComplete @ 1c0011a60 =====

void WwanprotOpenAdapterComplete(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  if (*(int *)(param_1 + 0x18) != -0x21502153) {
    WwanAssertFailed("WwanprotOpenAdapterComplete",0x1d7,param_3);
  }
  *(undefined4 *)(param_1 + 0x60) = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,param_2,
              *(wchar_t **)(param_1 + 0x48));
  }
  NdisSetEvent(param_1 + 0x68);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c0011af0 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
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
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c0011c50;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c0011c50;
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
LAB_1c0011c50:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c0011c84 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 1c0011d74 =====

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
    memcpy(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 1c0011e54 =====

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
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 1c0011f54 =====

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



===== SepSddlGetAclForString @ 1c0012040 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
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
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
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
LAB_1c00123db:
              iVar5 = -0x3ffffff3;
LAB_1c00123dd:
              lVar7 = *param_2;
              goto LAB_1c00123c3;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c00123db;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_1c000d050;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 |
                             *(uint *)((longlong)&DAT_1c000d058 + uVar11 * 0x10 + 4);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + *(uint *)(&DAT_1c000d058 + uVar11 * 2);
                    goto LAB_1c00122cd;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c00123db;
                uVar15 = (uint)local_res8;
LAB_1c00122cd:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c00123dd;
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
            if (iVar5 != 0) goto LAB_1c00123dd;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c001234b:
              iVar5 = -0x3fffff89;
              goto LAB_1c00123dd;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c001234b;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c00123dd;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_1c00123c3:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c0012408 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_1c000d124;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c000d11c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c000d118 + uVar7 * 0x18);
      uVar6 = (&DAT_1c000d124)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c001249f;
      }
      else {
LAB_1c001249f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c000d110 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c00124b4;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c00124b4:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c00124dc =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1c001255f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c001253d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c001255f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c001253d:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 1c00125e8 =====

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
        goto LAB_1c001272d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c001272d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c001278c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c000b930,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1c0012928 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c000b8b0);
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
      if ((int)uVar3 < 0) goto LAB_1c0012aa7;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000b8c8,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012aa7;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000b8e0,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012aa7;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000b910,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c0012aa7:
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



===== PpRegStateReadCreateClassCreationSettings @ 1c0012aec =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c000b850,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c000b868);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000b878,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000b898,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c0012c50 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
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
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
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
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1c000b850,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c000b8b0);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c0012db8 =====

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



===== CmRegUtilCreateWstrKey @ 1c0012eb4 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 1c0012f84 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 1c0013018 =====

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
    if (iVar1 < 0) goto LAB_1c0013150;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c0013150:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c0013194 =====

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
      memcpy(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
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



===== CmRegUtilWstrValueGetDword @ 1c00132e0 =====

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



===== CmRegUtilWstrValueSetWstrString @ 1c0013384 =====

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



===== entry @ 1c0014010 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0014044 =====

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



===== DriverEntry @ 1c0014078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,longlong param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulonglong local_res8;
  longlong local_res18 [2];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined4 local_a8;
  undefined4 local_a4;
  wchar_t *local_a0;
  undefined8 local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  
  memset(&local_b8,0,0x80);
  local_res8 = 0;
  _DAT_1c000d318 = 0xc7888e88;
  local_res18[0] = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  bVar1 = false;
  local_c8 = 0;
  uStack_c0 = 0;
  _Globals = param_1;
  NdisInitializeEvent(&DAT_1c000d348);
  RtlInitUnicodeString(&local_d8,L"\\Device\\Ndisuio");
  puVar6 = &local_d8;
  iVar2 = IoCreateDevice(param_1,0,puVar6,0x12,0x100,0,local_res18);
  if (iVar2 < 0) goto LAB_1c0014431;
  RtlInitUnicodeString(&local_c8,L"\\DosDevices\\Ndisuio");
  puVar5 = &local_d8;
  iVar2 = IoCreateSymbolicLink(&local_c8);
  if (iVar2 < 0) goto LAB_1c0014431;
  puVar4 = &DAT_1c000d338;
  bVar1 = true;
  *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x10;
  DAT_1c000d308 = local_res18[0];
  DAT_1c000d330 = &DAT_1c000d328;
  DAT_1c000d328 = &DAT_1c000d328;
  KeInitializeSpinLock();
  _WPP_MAIN_CB = 0;
  DAT_1c000d3e8 = &WPP_ThisDir_CTLGUID_WwanProtoControlGuid;
  DAT_1c000d3f0 = 0;
  _DAT_1c000d400 = 0;
  _DAT_1c000d408 = 1;
  WppLoadTracingSupport();
  _DAT_1c000d400 = 0;
  WppInitKm();
  McGenEventRegister_EtwRegister();
  if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
    puVar5 = (undefined8 *)&StartWWanNDISUIO;
    McTemplateK0_EtwWriteTransfer(puVar4,&StartWWanNDISUIO);
  }
  iVar3 = WwanInitWwanGlobals();
  iVar2 = -0x3fffffff;
  if (iVar3 == 0) {
    WwanGetGlobalSettingsFromRegistry(param_2);
    iVar3 = WwanCreateDeviceFile(param_1);
    if (iVar3 != 0) {
      puVar4 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (WPP_GLOBAL_Control[0x29] != '\0')) &&
         (puVar5 = (undefined8 *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        puVar5 = (undefined8 *)0x22;
        puVar6 = (undefined8 *)&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids;
        WPP_SF_D(puVar4,0x22,&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar3);
      }
      iVar3 = -0x3fffffff;
      WwanDeInitWwanGlobals(puVar4,puVar5,puVar6);
      goto LAB_1c0014270;
    }
    WwanIsInitialized = 1;
  }
  else {
LAB_1c0014270:
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (WPP_GLOBAL_Control[0x29] != '\0')) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_D(puVar4,0x23,&WPP_ce69a35abda8383dac1756778a6d6e92_Traceguids,iVar3);
    }
    if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 2) != 0) {
      McTemplateK0jqqq_EtwWriteTransfer(puVar4);
    }
    if ((Microsoft_Windows_WWAN_NDISUIO_EVENTSEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer(puVar4,&StopWWanNDSIUIO);
    }
    McGenEventUnregister_EtwUnregister();
    WppCleanupKm();
  }
  local_a4 = (undefined4)local_res8;
  local_b8 = 0x800295;
  local_a0 = L"NDISUIO";
  local_b4 = 0x5906;
  local_80 = NdisuioOpenAdapterComplete;
  local_78 = NdisuioCloseAdapterComplete;
  local_48 = NdisuioSendComplete;
  local_60 = NdisuioRequestComplete;
  local_58 = NdisuioStatus;
  local_50 = NdisuioReceiveNetBufferLists;
  local_70 = NdisuioPnPEventHandler;
  local_90 = NdisuioBindAdapter;
  local_88 = NdisuioUnbindAdapter;
  local_a8 = 0x10000e;
  local_98 = 0;
  local_68 = 0;
  iVar3 = NdisRegisterProtocolDriver(0,&local_b8,&DAT_1c000d310);
  if (iVar3 == 0) {
    NdisGeneratePartialCancelId();
    DAT_1c000d31c = 0;
    *(code **)(param_1 + 0x70) = NdisuioOpen;
    local_res8 = local_res8 & 0xffffffffffffff00;
    *(code **)(param_1 + 0x80) = NdisuioClose;
    *(code **)(param_1 + 0x88) = NdisuioRead;
    *(code **)(param_1 + 0x90) = NdisuioWrite;
    *(code **)(param_1 + 0x100) = NdisuioCleanup;
    *(code **)(param_1 + 0xe0) = NdisuioIoControl;
    *(code **)(param_1 + 0x68) = NdisuioUnload;
    iVar2 = ZwPowerInformation(0x42,0,0,&local_res8,1);
    if (-1 < iVar2) {
      DAT_1c000d360 = (undefined1)local_res8;
      return 0;
    }
  }
LAB_1c0014431:
  if (local_res18[0] != 0) {
    IoDeleteDevice();
    DAT_1c000d308 = 0;
  }
  if (bVar1) {
    IoDeleteSymbolicLink(&local_c8);
  }
  return iVar2;
}


