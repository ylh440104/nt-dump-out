
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== SmartcardAcquireRemoveLock @ 1c0001030 =====

void SmartcardAcquireRemoveLock(longlong param_1)

{
                    /* 0x1030  1  SmartcardAcquireRemoveLock */
  SmartcardAcquireRemoveLockWithTag(param_1);
  return;
}



===== SmartcardAcquireRemoveLockWithTag @ 1c0001050 =====

undefined8 SmartcardAcquireRemoveLockWithTag(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
                    /* 0x1050  2  SmartcardAcquireRemoveLockWithTag */
  uVar3 = 0;
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x290) + 0x5c);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*(char *)(*(longlong *)(param_1 + 0x290) + 0x58) == '\x01') {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0x290) + 0x5c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(*(longlong *)(param_1 + 0x290) + 0x60,0,0);
    }
    uVar3 = 0xc0000056;
  }
  return uVar3;
}



===== SmartcardDeviceControl @ 1c00010b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SmartcardDeviceControl(uint *param_1,longlong param_2)

{
  byte *pbVar1;
  uint uVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  bool bVar10;
  
                    /* 0x10b0  4  SmartcardDeviceControl */
  lVar7 = *(longlong *)(param_2 + 0xb8);
  iVar6 = 0;
  bVar4 = true;
  uVar2 = *(uint *)(lVar7 + 0x18);
  if (param_1 == (uint *)0x0) {
    iVar6 = -0x3fffff11;
LAB_1c0001408:
    *(int *)(param_2 + 0x30) = iVar6;
    IofCompleteRequest(param_2,0);
    return iVar6;
  }
  if ((((*param_1 < 0x100) || (plVar3 = *(longlong **)(param_1 + 0xa4), plVar3 == (longlong *)0x0))
      || (*plVar3 == 0)) || ((uVar2 & 3) != 0)) {
    iVar6 = -0x3ffffff3;
    goto LAB_1c0001408;
  }
  KeWaitForSingleObject(plVar3 + 3,6,0,0,0);
  LOCK();
  bVar10 = *(longlong *)(*(longlong *)(param_1 + 0xa4) + 8) == 0;
  if (bVar10) {
    *(longlong *)(*(longlong *)(param_1 + 0xa4) + 8) = param_2;
  }
  UNLOCK();
  if (bVar10) {
    if (uVar2 == 0x310028) {
      LOCK();
      *(undefined8 *)(*(longlong *)(param_1 + 0xa4) + 8) = 0;
      UNLOCK();
      if (*(longlong *)(param_1 + 0x3e) == 0) {
LAB_1c0001205:
        bVar4 = false;
        iVar6 = -0x3fffff45;
      }
      else {
        uVar5 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0xa4) + 0x50);
        lVar7 = *(longlong *)(param_1 + 0xa4);
        uVar2 = param_1[0xaa];
        uVar9 = (ulonglong)uVar2;
        if (*(longlong *)(lVar7 + 0x10) == 0) {
          if (uVar2 == 0) {
LAB_1c00012af:
            iVar6 = -0x3ffffe7c;
          }
          else if (uVar2 < 2) {
            *(longlong *)(lVar7 + 0x10) = param_2;
            uVar8 = CONCAT31((int3)(uVar2 >> 8),uVar5);
            param_1[0xa2] = 0x310028;
LAB_1c0001352:
            KeReleaseSpinLock(*(longlong *)(param_1 + 0xa4) + 0x50,uVar8);
            iVar6 = (**(code **)(param_1 + 0x3e))(param_1);
            goto LAB_1c000137a;
          }
        }
        else {
LAB_1c0001236:
          iVar6 = -0x7fffffef;
        }
        bVar4 = false;
        KeReleaseSpinLock(lVar7 + 0x50,CONCAT71((int7)(uVar9 >> 8),uVar5));
      }
    }
    else if (uVar2 == 0x31002c) {
      LOCK();
      *(undefined8 *)(*(longlong *)(param_1 + 0xa4) + 8) = 0;
      UNLOCK();
      if (*(longlong *)(param_1 + 0x3e) == 0) goto LAB_1c0001205;
      uVar5 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0xa4) + 0x50);
      lVar7 = *(longlong *)(param_1 + 0xa4);
      uVar2 = param_1[0xaa];
      uVar9 = (ulonglong)uVar2;
      if (*(longlong *)(lVar7 + 0x10) != 0) goto LAB_1c0001236;
      if (uVar2 == 0) goto LAB_1c00012af;
      uVar8 = CONCAT31((int3)(uVar2 >> 8),uVar5);
      if (1 < uVar2) {
        *(longlong *)(lVar7 + 0x10) = param_2;
        param_1[0xa2] = 0x31002c;
        goto LAB_1c0001352;
      }
      KeReleaseSpinLock(lVar7 + 0x50,uVar8);
LAB_1c000137a:
      bVar4 = false;
      if (iVar6 == 0x103) goto LAB_1c0001386;
    }
    else {
      param_1[0xa2] = uVar2;
      if ((*(uint **)(param_2 + 0x18) != (uint *)0x0) && (3 < *(uint *)(lVar7 + 0x10))) {
        param_1[0xa3] = **(uint **)(param_2 + 0x18);
      }
      *(undefined8 *)(param_1 + 0x9a) = *(undefined8 *)(param_2 + 0x18);
      param_1[0x9c] = *(uint *)(lVar7 + 0x10);
      *(undefined8 *)(param_1 + 0x9e) = *(undefined8 *)(param_2 + 0x18);
      param_1[0xa0] = *(uint *)(lVar7 + 8);
      *(undefined8 **)(param_1 + 0x98) = (undefined8 *)(param_2 + 0x38);
      *(undefined8 *)(param_2 + 0x38) = 0;
      iVar6 = SmartcardDeviceIoControl((longlong)param_1);
      if (iVar6 == 0x103) {
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
LAB_1c0001386:
        bVar4 = false;
        uVar5 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0xa4) + 0x50);
        lVar7 = *(longlong *)(param_1 + 0xa4);
        if ((param_2 == *(longlong *)(lVar7 + 0x10)) || (param_2 == *(longlong *)(lVar7 + 8))) {
          bVar4 = true;
        }
        KeReleaseSpinLock(lVar7 + 0x50,uVar5);
        if ((bVar4) &&
           (*(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0xa4) + 8) + 0x60) != 0)) {
          IoStartPacket(**(longlong **)(param_1 + 0xa4),param_2,0,0);
        }
        goto LAB_1c000128b;
      }
    }
  }
  else {
    bVar4 = false;
    iVar6 = -0x7fffffef;
  }
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  if (bVar4) {
    LOCK();
    *(undefined8 *)(*(longlong *)(param_1 + 0xa4) + 8) = 0;
    UNLOCK();
    param_1[0x98] = 0;
    param_1[0x99] = 0;
    param_1[0x9a] = 0;
    param_1[0x9b] = 0;
    param_1[0x9c] = 0;
    param_1[0x9d] = 0;
    param_1[0x9e] = 0;
    param_1[0x9f] = 0;
    param_1[0xa0] = 0;
    param_1[0xa1] = 0;
  }
LAB_1c000128b:
  KeReleaseMutex(*(longlong *)(param_1 + 0xa4) + 0x18,0);
  return iVar6;
}



===== SmartcardLogError @ 1c0001450 =====

void SmartcardLogError(undefined8 param_1,undefined4 param_2,ushort *param_3,int param_4)

{
  undefined2 *puVar1;
  
                    /* 0x1450  10  SmartcardLogError */
  puVar1 = (undefined2 *)IoAllocateErrorLogEntry();
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 10) = 0;
    *(undefined4 *)(puVar1 + 6) = param_2;
    *(int *)(puVar1 + 0x14) = param_4;
    puVar1[1] = -(ushort)(param_4 != 0) & 4;
    if (param_3 != (ushort *)0x0) {
      *(undefined4 *)(puVar1 + 2) = 0x300001;
      memcpy(puVar1 + 0x18,*(void **)(param_3 + 4),(ulonglong)*param_3);
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== SmartcardReleaseRemoveLock @ 1c0001510 =====

void SmartcardReleaseRemoveLock(longlong param_1)

{
                    /* 0x1510  13  SmartcardReleaseRemoveLock */
  SmartcardReleaseRemoveLockWithTag(param_1);
  return;
}



===== SmartcardReleaseRemoveLockAndWait @ 1c0001530 =====

void SmartcardReleaseRemoveLockAndWait(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x1530  14  SmartcardReleaseRemoveLockAndWait */
  *(undefined1 *)(*(longlong *)(param_1 + 0x290) + 0x58) = 1;
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x290) + 0x5c);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x290) + 0x5c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (1 < iVar2) {
    KeWaitForSingleObject(*(longlong *)(param_1 + 0x290) + 0x60,0,0,0,0);
  }
  return;
}



===== SmartcardReleaseRemoveLockWithTag @ 1c00015a0 =====

void SmartcardReleaseRemoveLockWithTag(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* 0x15a0  15  SmartcardReleaseRemoveLockWithTag */
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x290) + 0x5c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(*(longlong *)(param_1 + 0x290) + 0x60,0,0);
  }
  return;
}



===== StringCchPrintfW @ 1c00015e0 =====

HRESULT __stdcall
StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...)

{
  ulonglong _Count;
  int iVar1;
  HRESULT HVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (cchDest - 1 < 0x7fffffff) {
    _Count = cchDest - 1;
    HVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf(pszDest,_Count,pszFormat,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      HVar2 = -0x7ff8ff86;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    pszDest[_Count] = L'\0';
  }
  else {
    HVar2 = -0x7ff8ffa9;
    if (cchDest != 0) {
      *pszDest = L'\0';
    }
  }
  return HVar2;
}



===== SmartcardDeviceIoControl @ 1c000165c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SmartcardDeviceIoControl(longlong param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  uint *puVar7;
  byte *pbVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  byte bVar12;
  
  uVar4 = *(uint *)(param_1 + 0x288);
  iVar3 = 0;
  if (uVar4 == 0x310004) {
    if (*(longlong *)(param_1 + 0xd8) != 0) {
      if (*(uint *)(param_1 + 0x2a8) < 2) {
        return -0x3ffffe7c;
      }
      SmartcardInitializeCardCapabilities(param_1);
      iVar3 = *(int *)(param_1 + 0x28c);
      if (iVar3 != 0) {
        if ((iVar3 != 1) && (iVar3 != 2)) {
          return -0x3ffffff0;
        }
        if (*(longlong *)(param_1 + 0x278) == 0) {
          return -0x3fffffdd;
        }
        if (*(uint *)(param_1 + 0x280) < 0x21) {
          return -0x3fffffdd;
        }
      }
      pcVar5 = *(code **)(param_1 + 0xd8);
      goto LAB_1c000208d;
    }
LAB_1c00018a2:
    iVar3 = -0x3fffff45;
  }
  else {
    if (uVar4 == 0x310008) {
      uVar4 = *(uint *)(param_1 + 0x28c);
      if (uVar4 < 0x80203) {
        if (uVar4 == 0x80202) {
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          uVar4 = *(uint *)(param_1 + 0x1f8);
          puVar7 = *(uint **)(param_1 + 0x278);
          if (uVar4 != 0) goto LAB_1c0001ccd;
LAB_1c0001bd4:
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x2b0);
        }
        else if (uVar4 < 0x30123) {
          if (uVar4 == 0x30122) {
            puVar7 = *(uint **)(param_1 + 0x278);
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = *(uint *)(param_1 + 0x2b4);
          }
          else {
            if (uVar4 == 0x10100) {
              if (*(void **)(param_1 + 0x278) == (void *)0x0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < (uint)*(ushort *)(param_1 + 4)) {
                return -0x3fffffdd;
              }
              memcpy(*(void **)(param_1 + 0x278),(void *)(param_1 + 6),
                     (ulonglong)(uint)*(ushort *)(param_1 + 4));
              uVar4 = (uint)*(ushort *)(param_1 + 4);
LAB_1c0001a6b:
              **(uint **)(param_1 + 0x260) = uVar4;
              return 0;
            }
            if (uVar4 == 0x10101) {
              if (*(void **)(param_1 + 0x278) == (void *)0x0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < (uint)*(ushort *)(param_1 + 0x26)) {
                return -0x3fffffdd;
              }
              memcpy(*(void **)(param_1 + 0x278),(void *)(param_1 + 0x28),
                     (ulonglong)(uint)*(ushort *)(param_1 + 0x26));
              uVar4 = (uint)*(ushort *)(param_1 + 0x26);
              goto LAB_1c0001a6b;
            }
            if (uVar4 == 0x10102) {
              puVar10 = *(undefined4 **)(param_1 + 0x278);
              if (puVar10 == (undefined4 *)0x0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < 4) {
                return -0x3fffffdd;
              }
              uVar6 = *(undefined4 *)(param_1 + 0x4c);
              goto LAB_1c0001a02;
            }
            if (uVar4 == 0x10103) {
              uVar1 = *(ushort *)(param_1 + 0x50);
              if (uVar1 != 0) {
                if (*(void **)(param_1 + 0x278) == (void *)0x0) {
                  return -0x3fffffdd;
                }
                if (*(uint *)(param_1 + 0x280) < (uint)uVar1) {
                  return -0x3fffffdd;
                }
                memcpy(*(void **)(param_1 + 0x278),(void *)(param_1 + 0x52),(ulonglong)(uint)uVar1);
                uVar4 = (uint)*(ushort *)(param_1 + 0x50);
                goto LAB_1c0001a6b;
              }
              goto LAB_1c00018a2;
            }
            if (uVar4 == 0x20110) {
              puVar7 = *(uint **)(param_1 + 0x278);
              if (puVar7 == (uint *)0x0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < 4) {
                return -0x3fffffdd;
              }
              uVar4 = *(int *)(param_1 + 0x2a0) << 0x10 | *(uint *)(param_1 + 0x2ac);
            }
            else {
              if (uVar4 != 0x30120) {
                if (uVar4 == 0x30121) {
                  puVar7 = *(uint **)(param_1 + 0x278);
                  goto LAB_1c0001bd4;
                }
                goto LAB_1c00018a2;
              }
              puVar7 = *(uint **)(param_1 + 0x278);
              if (puVar7 == (uint *)0x0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < 4) {
                return -0x3fffffdd;
              }
              uVar4 = *(uint *)(param_1 + 0x298);
            }
          }
        }
        else if (uVar4 == 0x30123) {
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x2b8);
        }
        else if (uVar4 == 0x30124) {
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 700);
        }
        else if (uVar4 == 0x30125) {
          puVar7 = *(uint **)(param_1 + 0x278);
LAB_1c0001c91:
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x2c0);
        }
        else if (uVar4 == 0x40131) {
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x2c4);
        }
        else if (uVar4 == 0x60150) {
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x2a4);
        }
        else {
          if (uVar4 != 0x80201) goto LAB_1c00018a2;
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = *(uint *)(param_1 + 0x1d8);
        }
      }
      else if (uVar4 < 0x8020b) {
        if (uVar4 == 0x8020a) {
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          puVar7 = *(uint **)(param_1 + 0x278);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          uVar4 = (uint)*(byte *)(param_1 + 0x1e5);
        }
        else {
          if (uVar4 == 0x80203) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            if (0xf < *(byte *)(param_1 + 0x1c8)) {
              return -0x3fffffec;
            }
            puVar10 = *(undefined4 **)(param_1 + 0x278);
            if (puVar10 == (undefined4 *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar6 = *(undefined4 *)
                     (*(longlong *)(param_1 + 0x1b8) + (ulonglong)*(byte *)(param_1 + 0x1c8) * 8);
LAB_1c0001a02:
            *puVar10 = uVar6;
            goto LAB_1c0001ce4;
          }
          if (uVar4 == 0x80204) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            bVar12 = *(byte *)(param_1 + 0x1c9);
            if (0xf < bVar12) {
              return -0x3fffffec;
            }
            uVar4 = *(uint *)(*(longlong *)(param_1 + 0x1c0) + 4 + (ulonglong)bVar12 * 8);
            if (uVar4 == 0) {
              return -0x3fffffec;
            }
            puVar7 = *(uint **)(param_1 + 0x278);
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = *(uint *)(*(longlong *)(param_1 + 0x1c0) + (ulonglong)bVar12 * 8) / uVar4;
          }
          else if (uVar4 == 0x80205) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            puVar7 = *(uint **)(param_1 + 0x278);
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x1cc);
          }
          else if (uVar4 == 0x80206) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            puVar7 = *(uint **)(param_1 + 0x278);
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x1dc);
          }
          else if (uVar4 == 0x80207) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x360);
            puVar7 = *(uint **)(param_1 + 0x278);
            if (*(byte *)(param_1 + 0x360) != 0) goto LAB_1c0001ccd;
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x1e4);
          }
          else if (uVar4 == 0x80208) {
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x361);
            puVar7 = *(uint **)(param_1 + 0x278);
            if (*(byte *)(param_1 + 0x361) == 0) goto LAB_1c0001c91;
LAB_1c0001ccd:
            if ((puVar7 == (uint *)0x0) || (*(uint *)(param_1 + 0x280) < 4)) {
              return -0x3fffffdd;
            }
          }
          else {
            if (uVar4 != 0x80209) goto LAB_1c00018a2;
            if (*(uint *)(param_1 + 0x2a8) < 5) {
              return -0x3ffffe7c;
            }
            puVar7 = *(uint **)(param_1 + 0x278);
            if (puVar7 == (uint *)0x0) {
              return -0x3fffffdd;
            }
            if (*(uint *)(param_1 + 0x280) < 4) {
              return -0x3fffffdd;
            }
            uVar4 = (uint)*(byte *)(param_1 + 0x1e6);
          }
        }
      }
      else if (uVar4 == 0x8020b) {
        if (*(uint *)(param_1 + 0x2a8) < 5) {
          return -0x3ffffe7c;
        }
        puVar7 = *(uint **)(param_1 + 0x278);
        if (puVar7 == (uint *)0x0) {
          return -0x3fffffdd;
        }
        if (*(uint *)(param_1 + 0x280) < 4) {
          return -0x3fffffdd;
        }
        uVar4 = (uint)*(byte *)(param_1 + 0x1e7);
      }
      else {
        if (uVar4 == 0x90300) {
          uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x290) + 0x50);
          if (*(int *)(param_1 + 0x2a8) == 0) {
            iVar3 = -0x3ffffe7c;
            uVar11 = 0;
          }
          else {
            uVar4 = *(int *)(param_1 + 0x2a8) - 1;
            uVar11 = (ulonglong)uVar4;
            if (uVar4 == 0) {
              if ((*(undefined1 **)(param_1 + 0x278) == (undefined1 *)0x0) ||
                 (*(int *)(param_1 + 0x280) == 0)) goto LAB_1c0001ff0;
              **(undefined1 **)(param_1 + 0x278) = 0;
            }
            else if (uVar4 == 1) {
              if ((*(undefined1 **)(param_1 + 0x278) == (undefined1 *)0x0) ||
                 (*(int *)(param_1 + 0x280) == 0)) goto LAB_1c0001ff0;
              **(undefined1 **)(param_1 + 0x278) = 1;
            }
            else {
              if ((*(undefined1 **)(param_1 + 0x278) == (undefined1 *)0x0) ||
                 (*(int *)(param_1 + 0x280) == 0)) {
LAB_1c0001ff0:
                iVar3 = -0x3fffffdd;
                goto LAB_1c0001ffc;
              }
              **(undefined1 **)(param_1 + 0x278) = 2;
            }
            **(undefined4 **)(param_1 + 0x260) = 1;
          }
LAB_1c0001ffc:
          uVar9 = CONCAT71((int7)(uVar11 >> 8),uVar2);
LAB_1c0001734:
          KeReleaseSpinLock(*(longlong *)(param_1 + 0x290) + 0x50,uVar9);
          return iVar3;
        }
        if (uVar4 == 0x90301) {
          pbVar8 = *(byte **)(param_1 + 0x278);
          if (pbVar8 == (byte *)0x0) {
            return -0x3fffffdd;
          }
          if (*(int *)(param_1 + 0x280) == 0) {
            return -0x3fffffdd;
          }
          bVar12 = ~-(*(uint *)(param_1 + 0x2a8) < 3);
LAB_1c0001edc:
          *pbVar8 = bVar12;
          **(undefined4 **)(param_1 + 0x260) = 1;
          return 0;
        }
        if (uVar4 == 0x90303) {
          if (*(void **)(param_1 + 0x278) == (void *)0x0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 0x21) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          memcpy(*(void **)(param_1 + 0x278),(void *)(param_1 + 0x160),
                 (ulonglong)*(byte *)(param_1 + 0x1a0));
          uVar4 = (uint)*(byte *)(param_1 + 0x1a0);
          goto LAB_1c0001a6b;
        }
        if (uVar4 == 0x90304) {
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          pbVar8 = *(byte **)(param_1 + 0x278);
          if (pbVar8 == (byte *)0x0) {
            return -0x3fffffdd;
          }
          if (*(int *)(param_1 + 0x280) == 0) {
            return -0x3fffffdd;
          }
          bVar12 = (*(uint *)(param_1 + 0x1d8) & 3) != 0;
          goto LAB_1c0001edc;
        }
        if (uVar4 != 0x7fff0001) goto LAB_1c00018a2;
        puVar7 = *(uint **)(param_1 + 0x278);
        if (puVar7 == (uint *)0x0) {
          return -0x3fffffdd;
        }
        if (*(uint *)(param_1 + 0x280) < 4) {
          return -0x3fffffdd;
        }
        uVar4 = *(uint *)(param_1 + 0x48);
      }
      *puVar7 = uVar4;
LAB_1c0001ce4:
      **(undefined4 **)(param_1 + 0x260) = 4;
      return 0;
    }
    if (uVar4 == 0x31000c) {
      if (*(int *)(param_1 + 0x28c) == 0x7fff0007) {
        *(undefined4 *)(param_1 + 0x37c) = 1;
        return 0;
      }
      goto LAB_1c00018a2;
    }
    if (uVar4 == 0x310010) {
      pcVar5 = *(code **)(param_1 + 0x110);
      goto LAB_1c0001899;
    }
    if (uVar4 == 0x310014) {
      pcVar5 = *(code **)(param_1 + 0xe0);
      if (pcVar5 == (code *)0x0) goto LAB_1c00018a2;
      if (*(int *)(param_1 + 0x2a8) != 6) {
        return -0x3ffffe7c;
      }
      if (*(uint *)(param_1 + 0x270) < 8) {
        return -0x3ffffff3;
      }
      if (**(int **)(param_1 + 0x268) != *(int *)(param_1 + 0x1d8)) {
        return -0x3ffffe7c;
      }
      *(undefined4 *)(param_1 + 0x354) = 0;
    }
    else {
      if (uVar4 == 0x310018) {
        pcVar5 = *(code **)(param_1 + 0xe8);
      }
      else {
        if (uVar4 != 0x31001c) {
          if (uVar4 != 0x310030) {
            if (uVar4 == 0x310038) {
              if (*(longlong *)(param_1 + 0x278) == 0) {
                return -0x3fffffdd;
              }
              if (*(uint *)(param_1 + 0x280) < 4) {
                return -0x3fffffdd;
              }
              uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x290) + 0x50);
              puVar10 = *(undefined4 **)(param_1 + 0x278);
              *puVar10 = *(undefined4 *)(param_1 + 0x2a8);
              uVar9 = CONCAT71((int7)((ulonglong)puVar10 >> 8),uVar2);
              **(undefined4 **)(param_1 + 0x260) = 4;
              goto LAB_1c0001734;
            }
            if ((uVar4 >> 0xd & 1) == 0) {
              return -0x3ffffff0;
            }
            pcVar5 = *(code **)(param_1 + 0x118);
            if (pcVar5 == (code *)0x0) {
              return -0x3ffffff0;
            }
            goto LAB_1c000208d;
          }
          if (*(longlong *)(param_1 + 0x278) == 0) {
            return -0x3fffffdd;
          }
          if (*(uint *)(param_1 + 0x280) < 4) {
            return -0x3fffffdd;
          }
          if (*(longlong *)(param_1 + 0x100) == 0) goto LAB_1c00018a2;
          if (*(uint *)(param_1 + 0x2a8) == 6) {
            if ((*(uint *)(param_1 + 0x28c) & *(uint *)(param_1 + 0x1d8)) != 0) {
              return 0;
            }
          }
          else if (*(uint *)(param_1 + 0x2a8) < 2) {
            return -0x3ffffe7c;
          }
          if ((*(uint *)(param_1 + 0x28c) & 3) == 0) {
            iVar3 = -0x3fffffec;
LAB_1c00017d7:
            if (*(code **)(param_1 + 0x120) == (code *)0x0) {
              return iVar3;
            }
            iVar3 = (**(code **)(param_1 + 0x120))(param_1);
          }
          else {
            *(byte *)(param_1 + 500) = (byte)(*(uint *)(param_1 + 0x28c) >> 0x1f) ^ 1;
            iVar3 = SmartcardUpdateCardCapabilities(param_1);
            if (iVar3 == -0x3fffffec) goto LAB_1c00017d7;
          }
          if (iVar3 != 0) {
            return iVar3;
          }
          if (*(uint *)(param_1 + 0x2a8) < 5) {
            return -0x3ffffe7c;
          }
          if ((*(uint *)(param_1 + 0x28c) & *(uint *)(param_1 + 0x1d4)) == 0) {
            *(undefined4 *)(param_1 + 0x2a8) = 5;
            *(undefined4 *)(param_1 + 0x1d8) = 0;
            goto LAB_1c00018a2;
          }
          pcVar5 = *(code **)(param_1 + 0x100);
          goto LAB_1c000208d;
        }
        pcVar5 = *(code **)(param_1 + 0xf0);
      }
LAB_1c0001899:
      if (pcVar5 == (code *)0x0) goto LAB_1c00018a2;
    }
LAB_1c000208d:
    iVar3 = (*pcVar5)(param_1);
  }
  return iVar3;
}



===== SmartcardRawReply @ 1c00020c0 =====

undefined8 SmartcardRawReply(longlong param_1)

{
  undefined8 uVar1;
  
                    /* 0x20c0  11  SmartcardRawReply */
  if (*(uint *)(param_1 + 0x280) < *(uint *)(param_1 + 0x344)) {
    uVar1 = 0xc0000023;
  }
  else {
    memcpy(*(void **)(param_1 + 0x278),*(void **)(param_1 + 0x338),
           (ulonglong)*(uint *)(param_1 + 0x344));
    **(undefined4 **)(param_1 + 0x260) = *(undefined4 *)(param_1 + 0x344);
    uVar1 = 0;
  }
  return uVar1;
}



===== SmartcardRawRequest @ 1c0002120 =====

undefined8 SmartcardRawRequest(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
                    /* 0x2120  12  SmartcardRawRequest */
  uVar1 = *(uint *)(param_1 + 0x354);
  if ((*(uint *)(param_1 + 0x350) < uVar1) ||
     (*(uint *)(param_1 + 0x350) - uVar1 <= *(uint *)(param_1 + 0x270))) {
    uVar2 = 0xc0000023;
  }
  else {
    memcpy((void *)((ulonglong)uVar1 + *(longlong *)(param_1 + 0x348)),*(void **)(param_1 + 0x268),
           (ulonglong)*(uint *)(param_1 + 0x270));
    if (*(char *)(param_1 + 0x158) != '\0') {
      SmartcardInvertData((byte *)((ulonglong)*(uint *)(param_1 + 0x354) +
                                  *(longlong *)(param_1 + 0x348)),*(uint *)(param_1 + 0x270));
    }
    *(int *)(param_1 + 0x354) = *(int *)(param_1 + 0x354) + *(int *)(param_1 + 0x270);
    uVar2 = 0;
  }
  return uVar2;
}



===== SmartcardT0Reply @ 1c00021a0 =====

undefined8 SmartcardT0Reply(longlong param_1)

{
  undefined8 uVar1;
  
                    /* 0x21a0  17  SmartcardT0Reply */
  if (*(uint *)(param_1 + 0x344) < 2) {
    uVar1 = 0xc0000186;
  }
  else if ((ulonglong)*(uint *)(param_1 + 0x280) < (ulonglong)*(uint *)(param_1 + 0x344) + 8) {
    uVar1 = 0xc0000023;
  }
  else {
    **(undefined8 **)(param_1 + 0x278) = **(undefined8 **)(param_1 + 0x268);
    if (*(char *)(param_1 + 0x158) != '\0') {
      SmartcardInvertData(*(byte **)(param_1 + 0x338),*(uint *)(param_1 + 0x344));
    }
    memcpy((void *)(*(longlong *)(param_1 + 0x278) + 8),*(void **)(param_1 + 0x338),
           (ulonglong)*(uint *)(param_1 + 0x344));
    **(int **)(param_1 + 0x260) = *(int *)(param_1 + 0x344) + 8;
    uVar1 = 0;
  }
  return uVar1;
}



===== SmartcardT0Request @ 1c0002240 =====

undefined8 SmartcardT0Request(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  
                    /* 0x2240  18  SmartcardT0Request */
  uVar2 = *(uint *)(param_1 + 0x354);
  if ((*(uint *)(param_1 + 0x350) < uVar2) ||
     (uVar4 = *(uint *)(param_1 + 0x270), *(uint *)(param_1 + 0x350) - uVar2 <= uVar4)) {
    return 0x80000005;
  }
  uVar7 = uVar4 - 8;
  memcpy((void *)((ulonglong)uVar2 + *(longlong *)(param_1 + 0x348)),
         (void *)(*(longlong *)(param_1 + 0x268) + 8),(ulonglong)uVar7);
  uVar2 = *(uint *)(param_1 + 0x354);
  *(uint *)(param_1 + 0x354) = uVar2 + uVar7;
  if (uVar7 < 4) {
LAB_1c0002322:
    uVar6 = 0xc000000d;
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x348);
    uVar5 = (ulonglong)(uVar2 + 4);
    if (uVar7 < 6) {
      *(undefined4 *)(param_1 + 0x358) = 0;
      if (uVar7 == 4) {
        *(undefined4 *)(param_1 + 0x35c) = 0;
        *(undefined1 *)(lVar3 + uVar5) = 0;
        *(int *)(param_1 + 0x354) = *(int *)(param_1 + 0x354) + 1;
      }
      else {
        uVar4 = (uint)*(byte *)(lVar3 + uVar5);
        if (*(byte *)(lVar3 + uVar5) == 0) {
          uVar4 = 0x100;
        }
        *(uint *)(param_1 + 0x35c) = uVar4;
      }
    }
    else {
      bVar1 = *(byte *)(uVar5 + lVar3);
      *(uint *)(param_1 + 0x358) = (uint)bVar1;
      *(undefined4 *)(param_1 + 0x35c) = 0;
      if ((uint)bVar1 != uVar4 - 0xd) goto LAB_1c0002322;
    }
    if (*(char *)(param_1 + 0x158) != '\0') {
      SmartcardInvertData((byte *)((ulonglong)uVar2 + *(longlong *)(param_1 + 0x348)),
                          *(int *)(param_1 + 0x354) - uVar2);
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== SmartcardT1Chksum @ 1c0002340 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SmartcardT1Chksum(byte *param_1,byte param_2,char param_3)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  ushort uVar6;
  byte *pbVar7;
  bool bVar8;
  ushort local_68 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_68;
  bVar1 = param_1[2];
  uVar3 = (ulonglong)bVar1;
  local_68[0] = 0;
  local_68[1] = 0xc0c1;
  local_68[2] = 0xc181;
  local_68[3] = 0x140;
  uVar6 = 0;
  local_68[4] = 0xc301;
  local_68[5] = 0x3c0;
  local_68[6] = 0x280;
  local_68[7] = 0xc241;
  local_68[8] = 0xc601;
  local_68[9] = 0x6c0;
  uVar5 = bVar1 + 3;
  local_68[10] = 0x780;
  local_68[0xb] = 0xc741;
  local_68[0xc] = 0x500;
  local_68[0xd] = 0xc5c1;
  local_68[0xe] = 0xc481;
  local_68[0xf] = 0x440;
  local_68[0x10] = 0;
  local_68[0x11] = 0xcc01;
  local_68[0x12] = 0xd801;
  local_68[0x13] = 0x1400;
  local_68[0x14] = 0xf001;
  local_68[0x15] = 0x3c00;
  local_68[0x16] = 0x2800;
  local_68[0x17] = 0xe401;
  local_68[0x18] = 0xa001;
  local_68[0x19] = 0x6c00;
  local_68[0x1a] = 0x7800;
  local_68[0x1b] = 0xb401;
  local_68[0x1c] = 0x5000;
  local_68[0x1d] = 0x9c01;
  local_68[0x1e] = 0x8801;
  local_68[0x1f] = 0x4600;
  if ((param_2 & 1) == 0) {
    uVar2 = CONCAT71((int7)((__security_cookie ^ (ulonglong)local_68) >> 8),*param_1);
    if (1 < (ushort)uVar5) {
      uVar3 = (ulonglong)(ushort)(bVar1 + 2);
      pbVar7 = param_1;
      do {
        pbVar7 = pbVar7 + 1;
        uVar2 = CONCAT71((int7)(uVar2 >> 8),(byte)uVar2 ^ *pbVar7);
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    if (param_3 == '\0') {
      param_1[uVar5] = (byte)uVar2;
      goto LAB_1c00024aa;
    }
    bVar8 = (byte)uVar2 == param_1[uVar5];
  }
  else {
    if ((ushort)uVar5 != 0) {
      lVar4 = uVar3 + 3;
      pbVar7 = param_1;
      do {
        bVar1 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        bVar1 = (byte)uVar6 ^ bVar1;
        uVar6 = local_68[(ulonglong)(bVar1 >> 4) + 0x10] ^ local_68[bVar1 & 0xf] ^ uVar6 >> 8;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    uVar2 = 0;
    if (param_3 == '\0') {
      param_1[uVar3 + 4] = (byte)uVar6;
      param_1[uVar3 + 3] = (byte)(uVar6 >> 8);
LAB_1c00024aa:
      return CONCAT71((int7)(uVar2 >> 8),1);
    }
    uVar2 = (ulonglong)uVar6;
    bVar8 = uVar6 == CONCAT11(param_1[uVar3 + 3],param_1[uVar3 + 4]);
  }
  return CONCAT71((int7)(uVar2 >> 8),bVar8);
}



===== SmartcardT1Reply @ 1c00024e0 =====

int SmartcardT1Reply(longlong param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined8 uVar9;
  int iVar10;
  char cVar11;
  undefined4 uVar12;
  
                    /* 0x24e0  19  SmartcardT1Reply */
  iVar10 = -0x3fffffea;
  lVar5 = *(longlong *)(param_1 + 0x388);
  cVar11 = '\x01';
  if (lVar5 == 0) {
    return -0x3fffff1b;
  }
  *(undefined1 *)(param_1 + 0x390) = 0;
  if (*(char *)(param_1 + 0x158) != '\0') {
    SmartcardInvertData(*(byte **)(param_1 + 0x338),*(uint *)(param_1 + 0x344));
  }
  bVar8 = false;
  *(undefined1 *)(param_1 + 0x380) = 0;
  pbVar6 = *(byte **)(param_1 + 0x338);
  uVar4 = *(uint *)(param_1 + 0x344);
  if ((3 < uVar4) && (uVar4 == pbVar6[2] + 4 + (*(byte *)(param_1 + 0x1e7) & 1))) {
    uVar9 = SmartcardT1Chksum(pbVar6,*(byte *)(param_1 + 0x1e7),'\x01');
    cVar11 = (char)uVar9;
    bVar8 = true;
  }
  if ((!bVar8) || (cVar11 == '\0')) {
    *(char *)(param_1 + 0x370) = (cVar11 != '\0') + '\x01';
    if (*(int *)(param_1 + 0x374) == 0) {
      *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x37c);
    }
    cVar11 = *(char *)(param_1 + 0x378);
    *(char *)(param_1 + 0x378) = cVar11 + '\x01';
    if (cVar11 == '\x02') {
      *(undefined1 *)(param_1 + 0x378) = 0;
      *(undefined4 *)(param_1 + 0x37c) = 0xc0;
    }
    else if (*(int *)(param_1 + 0x37c) != 0xc0) {
      *(undefined4 *)(param_1 + 0x37c) = 3;
    }
    goto LAB_1c000296c;
  }
  *(undefined1 *)(param_1 + 0x370) = 0;
  puVar7 = *(undefined1 **)(param_1 + 0x338);
  bVar2 = puVar7[1];
  bVar3 = puVar7[2];
  if (*(int *)(param_1 + 0x37c) == 0xc1) {
    if ((bVar2 == 0xe1) || ((bVar2 & 0x82) == 0x82)) goto LAB_1c0002612;
  }
  else if (*(int *)(param_1 + 0x37c) == 0xc0) {
    if (bVar2 == 0xe0) {
      *(undefined1 *)(param_1 + 0x378) = 0;
      *(undefined2 *)(param_1 + 0x37a) = 0;
      *(undefined4 *)(param_1 + 0x37c) = 4;
      goto LAB_1c000296c;
    }
  }
  else {
    if ((((8 < *(uint *)(lVar5 + 4)) && (*(char *)(lVar5 + 8) == -0x7f)) &&
        (*(char *)(lVar5 + 9) == '\x01')) && (*(char *)(lVar5 + 0xb) == '\0')) {
      *(undefined1 *)(lVar5 + 10) = *puVar7;
    }
    if (-1 < (char)bVar2) {
      if ((bVar2 >> 6 & 1) == *(byte *)(param_1 + 0x37a)) {
        *(undefined1 *)(param_1 + 0x378) = 0;
        *(undefined4 *)(param_1 + 0x374) = 0;
        *(byte *)(param_1 + 0x37a) = *(byte *)(param_1 + 0x37a) ^ 1;
        if (*(int *)(param_1 + 0x37c) == 2) {
          *(byte *)(param_1 + 0x37b) = *(byte *)(param_1 + 0x37b) ^ 1;
        }
        if (*(uint *)(param_1 + 0x280) <
            (uint)bVar3 + *(uint *)(param_1 + 0x364) + *(uint *)(lVar5 + 4)) {
          iVar10 = -0x3fffffdd;
        }
        else {
          memcpy((void *)(*(longlong *)(param_1 + 0x388) + (ulonglong)*(uint *)(param_1 + 0x364) +
                         (ulonglong)*(uint *)(lVar5 + 4)),puVar7 + 3,(ulonglong)bVar3);
          iVar1 = (uint)bVar3 + *(int *)(param_1 + 0x364);
          *(int *)(param_1 + 0x364) = iVar1;
          if ((bVar2 & 0x20) == 0) {
            **(int **)(param_1 + 0x260) = iVar1 + *(int *)(lVar5 + 4);
            memcpy(*(void **)(param_1 + 0x278),*(void **)(param_1 + 0x388),
                   (ulonglong)(uint)(*(int *)(lVar5 + 4) + *(int *)(param_1 + 0x364)));
            iVar10 = 0;
          }
          else {
            *(undefined4 *)(param_1 + 0x37c) = 3;
          }
        }
        goto LAB_1c000296c;
      }
      *(undefined1 *)(param_1 + 0x370) = 2;
      if (*(int *)(param_1 + 0x374) == 0) {
        *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x37c);
      }
      cVar11 = *(char *)(param_1 + 0x378);
      *(char *)(param_1 + 0x378) = cVar11 + '\x01';
      if (cVar11 != '\x02') {
        *(undefined4 *)(param_1 + 0x37c) = 3;
        goto LAB_1c000296c;
      }
      *(undefined1 *)(param_1 + 0x378) = 0;
LAB_1c00027a7:
      *(undefined4 *)(param_1 + 0x37c) = 0xc0;
      goto LAB_1c000296c;
    }
    if ((bVar2 & 0xc0) == 0x80) {
      if (((bVar2 >> 4 & 1) == *(byte *)(param_1 + 0x37b)) || (*(char *)(param_1 + 0x371) == '\0'))
      {
        if (((bVar2 & 2) == 0) || (*(int *)(param_1 + 0x37c) != 0xc1)) {
          cVar11 = *(char *)(param_1 + 0x378);
          *(char *)(param_1 + 0x378) = cVar11 + '\x01';
          if (cVar11 != '\x02') goto LAB_1c000296c;
          *(undefined1 *)(param_1 + 0x378) = 0;
          if (*(int *)(param_1 + 0x374) == 0) {
            *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x37c);
          }
          goto LAB_1c00027a7;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x378) = 0;
        *(uint *)(param_1 + 0x368) = *(int *)(param_1 + 0x368) + (uint)*(byte *)(param_1 + 0x391);
        *(uint *)(param_1 + 0x36c) = *(int *)(param_1 + 0x36c) - (uint)*(byte *)(param_1 + 0x391);
        *(byte *)(param_1 + 0x37b) = *(byte *)(param_1 + 0x37b) ^ 1;
      }
LAB_1c0002612:
      *(undefined4 *)(param_1 + 0x37c) = 2;
      goto LAB_1c000296c;
    }
    if (bVar2 == 0xc1) {
      *(undefined1 *)(param_1 + 0x360) = *(undefined1 *)(*(longlong *)(param_1 + 0x338) + 3);
      *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x37c);
      *(undefined4 *)(param_1 + 0x37c) = 0xe1;
      goto LAB_1c000296c;
    }
    if (bVar2 == 0xc2) {
      *(undefined4 *)(param_1 + 0x37c) = 0xe2;
      goto LAB_1c000296c;
    }
    if (bVar2 == 0xc3) {
      *(undefined1 *)(param_1 + 0x380) = *(undefined1 *)(*(longlong *)(param_1 + 0x338) + 3);
      *(undefined4 *)(param_1 + 0x374) = *(undefined4 *)(param_1 + 0x37c);
      *(undefined4 *)(param_1 + 0x37c) = 0xe3;
      goto LAB_1c000296c;
    }
    if (bVar2 == 0xe4) {
      iVar10 = -0x3fffff62;
      goto LAB_1c000296c;
    }
  }
  iVar10 = -0x3ffffe7a;
LAB_1c000296c:
  if ((*(int *)(param_1 + 0x37c) == 0xc0) &&
     (cVar11 = *(char *)(param_1 + 0x379), *(char *)(param_1 + 0x379) = cVar11 + '\x01',
     cVar11 == '\x02')) {
    iVar10 = -0x3ffffe7a;
  }
  if (iVar10 != -0x3fffffea) {
    uVar12 = 0xc1;
    if (*(int *)(param_1 + 0x374) != 0xc1) {
      uVar12 = 1;
    }
    *(undefined4 *)(param_1 + 0x37c) = uVar12;
    if (*(longlong *)(param_1 + 0x388) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x388),0);
      *(undefined8 *)(param_1 + 0x388) = 0;
    }
    *(undefined4 *)(param_1 + 0x374) = 0;
    *(undefined1 *)(param_1 + 0x372) = 0;
  }
  return iVar10;
}



===== SmartcardT1Request @ 1c00029f0 =====

undefined8 SmartcardT1Request(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  longlong lVar5;
  byte bVar6;
  int *piVar7;
  undefined8 local_18;
  void *pvStack_10;
  
                    /* 0x29f0  20  SmartcardT1Request */
  lVar3 = *(longlong *)(param_1 + 0x268);
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  puVar1 = (uint *)(param_1 + 0x37c);
  if (*(char *)(param_1 + 0x390) != '\0') {
    *puVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x390) = 1;
  uVar2 = *puVar1;
  if (uVar2 < 0xc1) {
    if (uVar2 == 0xc0) {
      local_18._0_3_ = CONCAT21(0xc0,*(undefined1 *)(param_1 + 0x372));
      local_18 = (ulonglong)(uint3)local_18;
      pvStack_10 = (void *)0x0;
      *(undefined1 *)(param_1 + 0x37b) = 0;
      goto LAB_1c0002d37;
    }
    if (uVar2 == 0) {
      *puVar1 = 0xc1;
LAB_1c0002b73:
      *(undefined1 *)(param_1 + 0x379) = 0;
      if (*(longlong *)(param_1 + 0x388) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x388),0);
        *(undefined8 *)(param_1 + 0x388) = 0;
      }
      if (*(uint *)(param_1 + 0x280) < *(int *)(lVar3 + 4) + 2U) {
        return 0xc0000023;
      }
      lVar5 = ExAllocatePool2(0x40,*(uint *)(param_1 + 0x280),0x624c4353);
      *(longlong *)(param_1 + 0x388) = lVar5;
      if (lVar5 == 0) {
        return 0xc000009a;
      }
LAB_1c0002a6d:
      memcpy(*(void **)(param_1 + 0x388),*(void **)(param_1 + 0x268),(ulonglong)*(uint *)(lVar3 + 4)
            );
      if ((((8 < *(uint *)(lVar3 + 4)) && (*(char *)(lVar3 + 8) == -0x7f)) &&
          (*(char *)(lVar3 + 9) == '\x01')) && (*(char *)(lVar3 + 0xb) == '\0')) {
        *(undefined1 *)(param_1 + 0x372) = *(undefined1 *)(lVar3 + 10);
      }
      *(int *)(param_1 + 0x36c) = *(int *)(param_1 + 0x270) - *(int *)(lVar3 + 4);
      *(undefined8 *)(param_1 + 0x364) = 0;
      *(undefined1 *)(param_1 + 0x360) = *(undefined1 *)(param_1 + 0x1e4);
      *(undefined1 *)(param_1 + 0x378) = 0;
      *(undefined4 *)(param_1 + 0x374) = 0;
      *(undefined1 *)(param_1 + 0x371) = 0;
      goto LAB_1c0002ae2;
    }
    if (uVar2 == 1) goto LAB_1c0002b73;
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        local_18._0_2_ =
             CONCAT11((*(byte *)(param_1 + 0x37a) | 0xf8) << 4 | *(byte *)(param_1 + 0x370),
                      *(undefined1 *)(param_1 + 0x372));
        if (*(byte *)(param_1 + 0x370) != 0) {
          *(undefined1 *)(param_1 + 0x370) = 0;
          if (*(uint *)(param_1 + 0x374) == 0) {
            *puVar1 = 1;
            return 0xc00000e5;
          }
          *puVar1 = *(uint *)(param_1 + 0x374);
        }
        local_18 = (ulonglong)(ushort)local_18;
        goto LAB_1c0002b63;
      }
      if (uVar2 != 4) goto LAB_1c0002d37;
      goto LAB_1c0002a6d;
    }
  }
  else {
    if (uVar2 != 0xc1) {
      if (uVar2 == 0xc2) {
        local_18._0_3_ = CONCAT21(0xc2,*(undefined1 *)(param_1 + 0x372));
        local_18 = (ulonglong)(uint3)local_18;
      }
      else {
        if (uVar2 == 0xe1) {
          *puVar1 = *(uint *)(param_1 + 0x374);
          local_18._0_3_ = CONCAT21(0x1e1,*(undefined1 *)(param_1 + 0x372));
          local_18 = (ulonglong)(uint3)local_18;
          pvStack_10 = (void *)(param_1 + 0x360);
          goto LAB_1c0002d37;
        }
        if (uVar2 != 0xe2) {
          if (uVar2 == 0xe3) {
            *puVar1 = *(uint *)(param_1 + 0x374);
            *(undefined4 *)(param_1 + 0x374) = 0;
            local_18._0_3_ = CONCAT21(0x1e3,*(undefined1 *)(param_1 + 0x372));
            local_18 = (ulonglong)(uint3)local_18;
            pvStack_10 = (void *)(param_1 + 0x380);
          }
          goto LAB_1c0002d37;
        }
        *puVar1 = 1;
        local_18._0_3_ = CONCAT21(0xe2,*(undefined1 *)(param_1 + 0x372));
        local_18 = (ulonglong)(uint3)local_18;
      }
LAB_1c0002b63:
      pvStack_10 = (void *)0x0;
      goto LAB_1c0002d37;
    }
LAB_1c0002ae2:
    piVar7 = (int *)(param_1 + 0x37c);
    if (*piVar7 == 0xc1) {
      *piVar7 = 0xc1;
      local_18._0_3_ = CONCAT21(0x1c1,*(undefined1 *)(param_1 + 0x372));
      local_18 = (ulonglong)(uint3)local_18;
      pvStack_10 = (void *)(param_1 + 0x361);
      goto LAB_1c0002d37;
    }
    *piVar7 = 2;
  }
  *(undefined4 *)(param_1 + 0x37c) = 2;
  bVar4 = *(byte *)(param_1 + 0x360);
  *(byte *)(param_1 + 0x391) = bVar4;
  bVar6 = *(byte *)(param_1 + 0x361);
  if (bVar6 < bVar4) {
    *(byte *)(param_1 + 0x391) = bVar6;
    bVar4 = bVar6;
  }
  if ((uint)bVar4 < *(uint *)(param_1 + 0x36c)) {
    *(undefined1 *)(param_1 + 0x371) = 1;
    bVar6 = 0x20;
  }
  else {
    *(undefined1 *)(param_1 + 0x371) = 0;
    bVar4 = *(byte *)(param_1 + 0x36c);
    bVar6 = 0;
  }
  local_18._0_2_ =
       CONCAT11(*(char *)(param_1 + 0x37b) << 6 | bVar6,*(undefined1 *)(param_1 + 0x372));
  local_18 = (ulonglong)CONCAT12(bVar4,(ushort)local_18);
  pvStack_10 = (void *)((ulonglong)*(uint *)(param_1 + 0x368) + (ulonglong)*(uint *)(lVar3 + 4) +
                       *(longlong *)(param_1 + 0x268));
LAB_1c0002d37:
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x354) + *(longlong *)(param_1 + 0x348)) =
       (undefined1)local_18;
  *(undefined1 *)((ulonglong)(*(int *)(param_1 + 0x354) + 1) + *(longlong *)(param_1 + 0x348)) =
       local_18._1_1_;
  *(byte *)((ulonglong)(*(int *)(param_1 + 0x354) + 2) + *(longlong *)(param_1 + 0x348)) =
       local_18._2_1_;
  if (local_18._2_1_ != 0) {
    memcpy((void *)((ulonglong)(*(int *)(param_1 + 0x354) + 3) + *(longlong *)(param_1 + 0x348)),
           pvStack_10,(ulonglong)local_18._2_1_);
  }
  SmartcardT1Chksum((byte *)((ulonglong)*(uint *)(param_1 + 0x354) + *(longlong *)(param_1 + 0x348))
                    ,*(byte *)(param_1 + 0x1e7),'\0');
  if (*(char *)(param_1 + 0x158) != '\0') {
    SmartcardInvertData((byte *)((ulonglong)*(uint *)(param_1 + 0x354) +
                                *(longlong *)(param_1 + 0x348)),
                        local_18._2_1_ + 4 + (*(byte *)(param_1 + 0x1e7) & 1));
  }
  *(int *)(param_1 + 0x354) =
       *(int *)(param_1 + 0x354) + (*(byte *)(param_1 + 0x1e7) & 1) + local_18._2_1_ + 4;
  return 0;
}



===== SmartcardGetDebugLevel @ 1c0002e20 =====

undefined4 SmartcardGetDebugLevel(void)

{
                    /* 0x2e20  6  SmartcardGetDebugLevel */
  return DebugLevel;
}



===== SmartcardInitializeCardCapabilities @ 1c0002e30 =====

void SmartcardInitializeCardCapabilities(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
                    /* 0x2e30  8  SmartcardInitializeCardCapabilities */
  uVar1 = *(undefined8 *)(param_1 + 0x1b8);
  uVar2 = *(undefined8 *)(param_1 + 0x1c0);
  memset((void *)(param_1 + 0x158),0,0x100);
  *(undefined8 *)(param_1 + 0x1b8) = uVar1;
  *(undefined4 *)(param_1 + 0x37c) = 0;
  *(undefined2 *)(param_1 + 0x37a) = 0;
  *(undefined1 *)(param_1 + 0x360) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = uVar2;
  *(undefined4 *)(param_1 + 0x1d4) = 0x10000;
  if (*(int *)(param_1 + 0x2c0) - 1U < 0xfe) {
    uVar3 = *(undefined1 *)(param_1 + 0x2c0);
  }
  else {
    uVar3 = 0x20;
  }
  *(undefined1 *)(param_1 + 0x361) = uVar3;
  return;
}



===== SmartcardInvertData @ 1c0002ed0 =====

void SmartcardInvertData(byte *param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  
                    /* 0x2ed0  9  SmartcardInvertData */
  if (param_2 != 0) {
    uVar3 = (ulonglong)param_2;
    do {
      uVar1 = 0;
      bVar2 = 0;
      do {
        if ((*param_1 >> (bVar2 & 0x1f) & 1) != 0) {
          uVar1 = uVar1 & 0xff | 1 << (7 - bVar2 & 0x1f);
        }
        bVar2 = bVar2 + 1;
      } while (bVar2 < 8);
      *param_1 = ~(byte)uVar1;
      param_1 = param_1 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== SmartcardSetDebugLevel @ 1c0002f20 =====

void SmartcardSetDebugLevel(undefined4 param_1)

{
                    /* 0x2f20  16  SmartcardSetDebugLevel */
  DebugLevel = param_1;
  return;
}



===== SmartcardUpdateCardCapabilities @ 1c0002f30 =====

int SmartcardUpdateCardCapabilities(longlong param_1)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  int iVar13;
  int iVar14;
  char cVar15;
  uint uVar16;
  byte bVar17;
  uint uVar18;
  byte *pbVar19;
  byte local_res8;
  byte local_res18 [8];
  byte local_res20 [8];
  byte local_74 [12];
  uint local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  byte *local_58;
  uint local_50;
  uint local_4c;
  char *local_48;
  
                    /* 0x2f30  21  SmartcardUpdateCardCapabilities */
  pcVar1 = (char *)(param_1 + 0x158);
  bVar7 = *(byte *)(param_1 + 0x1a0);
  local_64 = 0;
  uVar18 = 0;
  local_5c = 0;
  local_60 = 0;
  cVar15 = '\0';
  if (1 < bVar7) {
    bVar17 = *(byte *)(param_1 + 0x160);
    if ((bVar17 < 0x40) && ((0x8800000000000008U >> ((ulonglong)bVar17 & 0x3f) & 1) != 0)) {
      local_48 = pcVar1;
      if (bVar17 == 3) {
        *pcVar1 = '\x01';
        SmartcardInvertData((byte *)(param_1 + 0x160),(uint)bVar7);
      }
      pbVar19 = (byte *)(param_1 + 0x161);
      bVar17 = 0;
      for (uVar10 = 0; uVar10 < bVar7 - 1; uVar10 = uVar10 + 1) {
        bVar17 = bVar17 ^ pbVar19[uVar10];
      }
      *(undefined4 *)(param_1 + 0x1d4) = 0;
      local_74[4] = 0;
      local_74[5] = 0;
      local_74[6] = 0;
      local_74[7] = 0;
      local_res8 = 0x11;
      local_74[0] = 0x11;
      local_74[1] = 0;
      local_74[2] = 0;
      local_74[3] = 0;
      local_res18[0] = 0x25;
      local_res18[1] = 0;
      local_res18[2] = 0;
      local_res18[3] = 0;
      local_res20[0] = 0;
      local_res20[1] = 10;
      local_res20[2] = 0;
      local_res20[3] = 0;
      *(byte *)(param_1 + 0x1b1) = *pbVar19 & 0xf;
      bVar2 = *pbVar19;
      local_58 = (byte *)(param_1 + 0x162);
      uVar10 = bVar7 - 2;
      for (local_68 = 0; uVar5 = local_74._4_4_, local_68 < 4; local_68 = local_68 + 1) {
        if ((bVar2 & 0x10) != 0) {
          local_74[8] = cVar15;
          if (local_68 == 1) {
            local_74[8] = '\x01';
          }
          local_74[local_68] = *local_58;
          local_58 = local_58 + 1;
          uVar10 = uVar10 - 1;
          local_res8 = local_74[0];
          cVar15 = local_74[8];
        }
        uVar9 = (ulonglong)local_68;
        if ((bVar2 & 0x20) != 0) {
          local_res18[uVar9] = *local_58;
          local_58 = local_58 + 1;
          uVar10 = uVar10 - 1;
        }
        if ((bVar2 & 0x40) != 0) {
          local_res20[uVar9] = *local_58;
          local_58 = local_58 + 1;
          uVar10 = uVar10 - 1;
        }
        if (-1 < (char)bVar2) break;
        bVar2 = *local_58;
        local_74[uVar9 + 4] = bVar2 & 0xf;
        local_58 = local_58 + 1;
        uVar10 = uVar10 - 1;
        uVar8 = 1 << (bVar2 & 0xf);
        if ((uVar18 & uVar8) == 0) {
          local_64 = local_64 + 1;
          local_50 = local_64;
        }
        uVar18 = uVar18 | uVar8;
        local_5c = uVar18;
        local_4c = uVar18;
      }
      pbVar19 = local_58;
      if (((uVar18 & 0xfffffffe) == 0) || (uVar10 = uVar10 - 1, bVar17 == 0)) {
        local_60 = 0;
        if (uVar10 != *(byte *)(param_1 + 0x1b1)) {
          local_60 = -0x3fffffec;
        }
      }
      else {
        local_60 = -0x3fffffec;
      }
      iVar13 = local_60;
      if (local_60 != 0) {
        if (*pcVar1 == '\x01') {
          SmartcardInvertData((byte *)(param_1 + 0x160),(uint)*(byte *)(param_1 + 0x1a0));
          *pcVar1 = '\0';
        }
        if (iVar13 != 0) {
          return iVar13;
        }
      }
      memcpy((void *)(param_1 + 0x1a1),pbVar19,(ulonglong)*(byte *)(param_1 + 0x1b1));
      bVar17 = local_res8 >> 4;
      *(byte *)(param_1 + 0x1c8) = bVar17;
      *(byte *)(param_1 + 0x1c9) = local_res8 & 0xf;
      *(byte *)(param_1 + 0x1ca) = local_res18[0] >> 6;
      uVar18 = 0;
      bVar7 = local_res18[1];
      if (local_res18[1] == '\0') {
        bVar7 = (local_res18[0] & 0x1f) * '\n';
      }
      *(byte *)(param_1 + 0x1cb) = bVar7;
      *(byte *)(param_1 + 0x1cc) = local_res20[0];
      if ((*(int *)(&DAT_1c0007110 + ((ulonglong)local_res8 & 0xf) * 8) != 0) &&
         (*(int *)(&DAT_1c0007190 + (ulonglong)bVar17 * 8) != 0)) {
        iVar13 = *(int *)(param_1 + 0x2b0) * 1000;
        if (iVar13 == 0) {
          iVar13 = 0x367e00;
        }
        if (*(char *)(param_1 + 500) == '\0') {
          *(undefined2 *)(param_1 + 0x1f5) = 0x101;
LAB_1c000326a:
          *(undefined4 *)(param_1 + 0x1fc) = *(undefined4 *)(param_1 + 0x2b8);
          *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(param_1 + 0x2b0);
        }
        else {
          if (*(char *)(param_1 + 500) == '\x01') {
            *(byte *)(param_1 + 0x1f5) = bVar17;
          }
          if ((0xf < *(byte *)(param_1 + 0x1f5)) ||
             (*(int *)(&DAT_1c0007190 + (ulonglong)*(byte *)(param_1 + 0x1f5) * 8) == 0)) {
            return -0x3ffffff3;
          }
          do {
            if ((*(char *)(param_1 + 0x2e8) == '\0') || (*(longlong *)(param_1 + 0x2e0) == 0)) {
              *(longlong *)(param_1 + 0x2e0) = param_1 + 0x2b0;
              *(undefined1 *)(param_1 + 0x2e8) = 2;
            }
            uVar8 = *(uint *)(&DAT_1c0007194 + (ulonglong)*(byte *)(param_1 + 0x1f5) * 8);
            *(undefined4 *)(param_1 + 0x1f8) = 0;
            uVar11 = uVar18;
            if (*(char *)(param_1 + 0x2e8) != '\0') {
              uVar16 = uVar18;
              do {
                uVar4 = *(uint *)(*(longlong *)(param_1 + 0x2e0) + (ulonglong)uVar16 * 4);
                if ((uVar11 < uVar4) && (uVar4 <= uVar8 / 1000)) {
                  *(uint *)(param_1 + 0x1f8) = uVar4;
                  uVar11 = uVar4;
                }
                uVar16 = uVar16 + 1;
              } while (uVar16 < *(byte *)(param_1 + 0x2e8));
            }
            iVar13 = uVar11 * 1000;
            *(undefined4 *)(param_1 + 0x1fc) = 0;
            if (iVar13 == 0) {
              return -0x3ffffff3;
            }
            if (*(char *)(param_1 + 500) == '\x01') {
              *(undefined1 *)(param_1 + 0x1f6) = *(undefined1 *)(param_1 + 0x1c9);
            }
            if (0xf < *(byte *)(param_1 + 0x1f6)) {
              return -0x3ffffff3;
            }
            if (*(int *)(&DAT_1c0007110 + (ulonglong)*(byte *)(param_1 + 0x1f6) * 8) == 0) {
              return -0x3ffffff3;
            }
            if ((*(char *)(param_1 + 0x2d8) == '\0') || (*(longlong *)(param_1 + 0x2d0) == 0)) {
              *(longlong *)(param_1 + 0x2d0) = param_1 + 0x2b8;
              *(undefined1 *)(param_1 + 0x2d8) = 2;
            }
            uVar9 = (ulonglong)*(byte *)(param_1 + 0x1f6);
            if (1 < *(byte *)(param_1 + 0x1f6)) {
              do {
                uVar12 = 0;
                if (*(byte *)(param_1 + 0x2d8) != 0) {
                  uVar8 = ((uint)(iVar13 * *(int *)(&DAT_1c0007110 + uVar9 * 8)) /
                          (uint)(*(int *)(&DAT_1c0007114 + uVar9 * 8) *
                                *(int *)(&DAT_1c0007190 + (ulonglong)*(byte *)(param_1 + 0x1f5) * 8)
                                )) * 100;
                  do {
                    iVar3 = *(int *)(*(longlong *)(param_1 + 0x2d0) + uVar12 * 4);
                    if ((uVar8 < (uint)(iVar3 * 0x65)) && ((uint)(iVar3 * 99) < uVar8)) {
                      *(int *)(param_1 + 0x1fc) = iVar3;
                      break;
                    }
                    uVar11 = (int)uVar12 + 1;
                    uVar12 = (ulonglong)uVar11;
                  } while (uVar11 < *(byte *)(param_1 + 0x2d8));
                }
                if (*(int *)(param_1 + 0x1fc) != 0) break;
                uVar9 = (ulonglong)*(byte *)(param_1 + 0x1f6);
                do {
                  bVar7 = (char)uVar9 - 1;
                  uVar9 = (ulonglong)bVar7;
                  *(byte *)(param_1 + 0x1f6) = bVar7;
                } while (*(int *)(&DAT_1c0007110 + uVar9 * 8) == 0);
              } while (1 < bVar7);
            }
            uVar9 = (ulonglong)*(byte *)(param_1 + 0x1f5);
            if ((*(byte *)(param_1 + 0x1f5) == 1) && (*(char *)(param_1 + 0x1f6) == '\x01'))
            goto LAB_1c000326a;
            if (*(int *)(param_1 + 0x1fc) != 0) break;
            uVar8 = *(uint *)(&DAT_1c0007194 + (ulonglong)*(byte *)(param_1 + 0x1c8) * 8);
            do {
              do {
                bVar7 = (char)uVar9 - 1;
                uVar9 = (ulonglong)bVar7;
                *(byte *)(param_1 + 0x1f5) = bVar7;
              } while (*(int *)(&DAT_1c0007190 + uVar9 * 8) == 0);
            } while (uVar8 < *(uint *)(&DAT_1c0007194 + uVar9 * 8));
          } while (*(int *)(param_1 + 0x1fc) == 0);
        }
        uVar8 = *(int *)(&DAT_1c0007190 + (ulonglong)*(byte *)(param_1 + 0x1f5) * 8) *
                *(int *)(&DAT_1c0007114 + (ulonglong)*(byte *)(param_1 + 0x1f6) * 8) * 1000000;
        iVar3 = *(int *)(&DAT_1c0007110 + (ulonglong)*(byte *)(param_1 + 0x1f6) * 8);
        iVar14 = uVar8 / (uint)(iVar13 * iVar3) + 1;
        *(int *)(param_1 + 0x15c) = iVar14;
        *(undefined4 *)(param_1 + 0x1d0) = 0;
        *(undefined1 *)(param_1 + 0x200) = 2;
        bVar7 = *(byte *)(param_1 + 0x1cc);
        if (bVar7 == 0xff) {
          *(undefined1 *)(param_1 + 0x200) = 1;
        }
        else if (bVar7 != 0) {
          *(uint *)(param_1 + 0x1d0) = (uint)bVar7 * iVar14;
        }
        uVar6 = KeAcquireSpinLockRaiseToDpc
                          (*(longlong *)(param_1 + 0x290) + 0x50,
                           (ulonglong)uVar8 % (ulonglong)(uint)(iVar13 * iVar3),iVar14,0x1c0000000,
                           uVar10);
        if (1 < *(uint *)(param_1 + 0x2a8)) {
          if ((cVar15 == '\0') &&
             (((1 < local_64 || (*(char *)(param_1 + 0x1c8) != '\x01')) ||
              (*(char *)(param_1 + 0x1c9) != '\x01')))) {
            *(undefined4 *)(param_1 + 0x2a8) = 5;
          }
          else {
            *(undefined4 *)(param_1 + 0x2a8) = 6;
          }
        }
        KeReleaseSpinLock(*(longlong *)(param_1 + 0x290) + 0x50,uVar6);
        if ((char)uVar5 == '\0') {
          *(uint *)(param_1 + 0x1d4) = *(uint *)(param_1 + 0x1d4) | 1;
          *(byte *)(param_1 + 0x1dc) = local_res20[1];
          bVar7 = *(char *)(param_1 + 0x1f6) - 1;
          uVar10 = 1;
          if (bVar7 < 5) {
            for (; bVar7 != 0; bVar7 = bVar7 - 1) {
              uVar10 = uVar10 * 2;
            }
            uVar10 = (uint)local_res20[1] * *(int *)(param_1 + 0x15c) * uVar10 * 0x3c0;
          }
          else {
            do {
              bVar7 = bVar7 - 1;
              uVar10 = uVar10 * 2;
            } while (bVar7 != 0);
            uVar10 = ((uint)local_res20[1] * *(int *)(param_1 + 0x15c) * 0x3c0) / uVar10;
          }
          *(uint *)(param_1 + 0x1e0) = uVar10 + 1;
        }
        if ((local_5c & 2) != 0) {
          pbVar19 = local_74 + 4;
          do {
            if (*pbVar19 == 1) break;
            uVar18 = uVar18 + 1;
            pbVar19 = pbVar19 + 1;
          } while (uVar18 < 4);
          if (uVar18 < 4) {
            pbVar19 = local_74 + (ulonglong)uVar18 + 4;
            do {
              if (*pbVar19 != 1) break;
              uVar18 = uVar18 + 1;
              pbVar19 = pbVar19 + 1;
            } while (uVar18 < 4);
          }
          if (uVar18 == 4) {
            return -0x3fffffec;
          }
          *(uint *)(param_1 + 0x1d4) = *(uint *)(param_1 + 0x1d4) | 2;
          bVar7 = 0x20;
          if (local_74[uVar18] != 0) {
            bVar7 = local_74[uVar18];
          }
          *(byte *)(param_1 + 0x1e4) = bVar7;
          bVar7 = local_res18[uVar18];
          if ((bVar7 & 0xf) == 0) {
            bVar17 = 0xd;
          }
          else {
            bVar17 = bVar7 & 0xf;
          }
          *(byte *)(param_1 + 0x1e5) = bVar17;
          if ((bVar7 & 0xf0) == 0) {
            bVar7 = 4;
          }
          else {
            bVar7 = bVar7 >> 4;
          }
          *(byte *)(param_1 + 0x1e6) = bVar7;
          *(byte *)(param_1 + 0x1e7) = local_res20[uVar18] & 1;
          iVar13 = 1;
          for (; bVar17 != 0; bVar17 = bVar17 - 1) {
            iVar13 = iVar13 * 2;
          }
          *(int *)(param_1 + 0x1e8) = (iVar13 + 0xb) * *(int *)(param_1 + 0x15c) + 1;
          iVar13 = 1;
          for (; bVar7 != 0; bVar7 = bVar7 - 1) {
            iVar13 = iVar13 * 2;
          }
          *(uint *)(param_1 + 0x1ec) =
               ((uint)(iVar13 * 0x57300) / *(uint *)(param_1 + 0x1f8) +
               *(int *)(param_1 + 0x15c) * 0xb) * 1000 + 1;
        }
        if (*(int *)(param_1 + 0x2a8) == 6) {
          if (cVar15 == '\0') {
            *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x1d4);
          }
          else {
            *(int *)(param_1 + 0x1d8) = 1 << (local_74[1] & 0xf);
          }
        }
        *(uint *)(param_1 + 0x1d4) = *(uint *)(param_1 + 0x1d4) | 0x10000;
        return 0;
      }
    }
  }
  return -0x3fffffec;
}



===== _guard_check_icall @ 1c0003770 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003788 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00037ac =====

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



===== __cpu_features_init @ 1c0003820 =====

/* WARNING: Removing unreachable block (ram,0x0001c000388a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003839) */
/* WARNING: Removing unreachable block (ram,0x0001c000382a) */

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



===== __security_check_cookie @ 1c00038f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003930 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003960 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003990 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003a00 =====

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



===== memset @ 1c0003d00 =====

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



===== __memset_repmovs @ 1c0003e40 =====

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



===== __memset_query @ 1c0003ec0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003f40 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004080 =====

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



===== __memset_spec_plain @ 1c0004100 =====

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



===== SmartcardT1Reply$fin$0 @ 1c00041fd =====

void SmartcardT1Reply_fin_0(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  lVar2 = *(longlong *)(param_2 + 0x70);
  if ((*(int *)(lVar2 + 0x37c) == 0xc0) &&
     (cVar1 = *(char *)(lVar2 + 0x379), *(char *)(lVar2 + 0x379) = cVar1 + '\x01', cVar1 == '\x02'))
  {
    *(undefined4 *)(param_2 + 0x20) = 0xc0000186;
  }
  if (*(int *)(param_2 + 0x20) != -0x3fffffea) {
    uVar3 = 1;
    if (*(int *)(lVar2 + 0x374) == 0xc1) {
      uVar3 = 0xc1;
    }
    *(undefined4 *)(lVar2 + 0x37c) = uVar3;
    if (*(longlong *)(lVar2 + 0x388) != 0) {
      ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x388),0);
      *(undefined8 *)(lVar2 + 0x388) = 0;
    }
    *(undefined4 *)(lVar2 + 0x374) = 0;
    *(undefined1 *)(lVar2 + 0x372) = 0;
  }
  return;
}



===== SmartcardT1Request$fin$0 @ 1c0004297 =====

void SmartcardT1Request_fin_0(void)

{
  return;
}



===== SmartcardUpdateCardCapabilities$fin$0 @ 1c00042ad =====

void SmartcardUpdateCardCapabilities_fin_0(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  
  if ((*(int *)(param_2 + 0x38) != 0) && (pcVar1 = *(char **)(param_2 + 0x50), *pcVar1 == '\x01')) {
    SmartcardInvertData((byte *)(pcVar1 + 8),(uint)(byte)pcVar1[0x48]);
    *pcVar1 = '\0';
  }
  return;
}



===== DriverEntry @ 1c000a008 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== SmartcardCreateLink @ 1c000a020 =====

ulonglong SmartcardCreateLink(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  STRSAFE_LPWSTR pszDest;
  ulonglong uVar2;
  uint uVar3;
  
                    /* 0xa020  3  SmartcardCreateLink */
  if (param_1 == 0) {
    uVar1 = 0xc00000ef;
  }
  else if (param_2 == 0) {
    uVar1 = 0xc00000f0;
  }
  else {
    pszDest = (STRSAFE_LPWSTR)ExAllocatePool2(0x40,0x40,0x624c4353);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      uVar3 = 0;
      do {
        StringCchPrintfW(pszDest,0x20,L"\\DosDevices\\SCReader%d",(ulonglong)uVar3);
        RtlInitUnicodeString(param_1,pszDest);
        uVar2 = IoCreateSymbolicLink(param_1,param_2);
        uVar1 = uVar2 & 0xffffffff;
        if (-1 < (int)uVar2) {
          return uVar2;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 10);
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0);
    }
  }
  return uVar1;
}



===== SmartcardExit @ 1c000a110 =====

void SmartcardExit(longlong param_1)

{
                    /* 0xa110  5  SmartcardExit */
  if (*(longlong *)(param_1 + 0x348) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x348),0);
    *(undefined8 *)(param_1 + 0x348) = 0;
  }
  if (*(longlong *)(param_1 + 0x338) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x338),0);
    *(undefined8 *)(param_1 + 0x338) = 0;
  }
  if (*(longlong *)(param_1 + 0x290) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x290),0);
    *(undefined8 *)(param_1 + 0x290) = 0;
  }
  if (*(longlong *)(param_1 + 0x388) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x388),0);
    *(undefined8 *)(param_1 + 0x388) = 0;
  }
  return;
}



===== SmartcardInitialize @ 1c000a1b0 =====

undefined8 SmartcardInitialize(int *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  void *_Dst;
  longlong lVar3;
  
                    /* 0xa1b0  7  SmartcardInitialize */
  if (param_1 == (int *)0x0) {
    uVar2 = 0xc00000ef;
  }
  else if (*param_1 - 0x100U < 0x51) {
    uVar1 = param_1[0xd4];
    if (uVar1 < 0x120) {
      param_1[0xd4] = 0x120;
      uVar1 = 0x120;
    }
    if ((uint)param_1[0xd0] < 0x120) {
      param_1[0xd0] = 0x120;
    }
    uVar2 = ExAllocatePool2(0x40,uVar1,0x624c4353);
    *(undefined8 *)(param_1 + 0xd2) = uVar2;
    uVar2 = ExAllocatePool2(0x40,param_1[0xd0],0x624c4353);
    *(undefined8 *)(param_1 + 0xce) = uVar2;
    _Dst = (void *)ExAllocatePool2(0x40,0x88,0x624c4353);
    *(void **)(param_1 + 0xa4) = _Dst;
    if (*(longlong *)(param_1 + 0xd2) != 0) {
      if ((*(longlong *)(param_1 + 0xce) != 0) && (_Dst != (void *)0x0)) {
        memset(_Dst,0,0x88);
        KeInitializeMutex(*(longlong *)(param_1 + 0xa4) + 0x18,0);
        KeInitializeSpinLock(*(longlong *)(param_1 + 0xa4) + 0x50);
        *(undefined1 *)(*(longlong *)(param_1 + 0xa4) + 0x58) = 0;
        *(undefined4 *)(*(longlong *)(param_1 + 0xa4) + 0x5c) = 1;
        KeInitializeEvent(*(longlong *)(param_1 + 0xa4) + 0x60,1,0);
        lVar3 = *(longlong *)(param_1 + 0xa4) + 0x78;
        *(longlong *)(*(longlong *)(param_1 + 0xa4) + 0x80) = lVar3;
        *(longlong *)lVar3 = lVar3;
        *(undefined **)(param_1 + 0x6e) = &DAT_1c0007090;
        *(undefined **)(param_1 + 0x70) = &DAT_1c0007010;
        return 0;
      }
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xd2),0);
    }
    if (*(longlong *)(param_1 + 0xce) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xce),0);
    }
    if (*(longlong *)(param_1 + 0xa4) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xa4),0);
    }
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== entry @ 1c000c010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c000c044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  uint uVar1;
  code *pcVar2;
  undefined3 uVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bVar10;
  byte *pbVar8;
  char *pcVar9;
  byte *pbVar11;
  char in_DL;
  char cVar12;
  byte in_DH;
  undefined6 in_register_00000012;
  char unaff_BL;
  byte unaff_BH;
  byte *unaff_RSI;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  pbVar11 = (byte *)0x6;
  pcVar2 = (code *)swi(0x29);
  pbVar8 = (byte *)(*pcVar2)();
  bVar10 = (byte)pbVar8;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + bVar10;
  bVar5 = *pbVar8;
  *pbVar8 = *pbVar8 + bVar10;
  *pbVar8 = *pbVar8 + in_DL + CARRY1(bVar5,bVar10);
  *pbVar8 = *pbVar8 + bVar10;
  bVar5 = *pbVar8;
  *pbVar8 = *pbVar8 + in_DH;
  *pbVar8 = *pbVar8 + bVar10 + CARRY1(bVar5,in_DH);
  bVar5 = *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL));
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + bVar10;
  *pbVar8 = *pbVar8 + bVar10 + CARRY1(bVar5,bVar10);
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + bVar10;
  pbVar8 = (byte *)CONCAT71((int7)((ulonglong)pbVar8 >> 8),0x10);
  *pbVar8 = *pbVar8 + 0x10;
  *pbVar8 = *pbVar8 + 0x10;
  cVar12 = in_DL + pbVar8[0x14] + *pbVar8;
  uVar7 = (uint)CARRY1(in_DL + pbVar8[0x14],*pbVar8);
  uVar1 = (uint)pbVar8 + 0x30020000;
  uVar6 = uVar1 + uVar7;
  uVar7 = (uint)(0xcffdffff < (uint)pbVar8 || CARRY4(uVar1,uVar7));
  uVar1 = uVar6 + 0xa0020000;
  uVar7 = uVar1 + uVar7 + -0x3ffe0000 + (uint)(0x5ffdffff < uVar6 || CARRY4(uVar1,uVar7));
  pbVar8 = (byte *)(ulonglong)uVar7;
  bVar5 = (byte)uVar7;
  *pbVar8 = *pbVar8 & bVar5;
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,cVar12)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,cVar12)) + bVar5;
  bVar10 = (byte)(uVar7 >> 8);
  *pbVar11 = *pbVar11 & bVar10;
  *pbVar8 = *pbVar8 + bVar5;
  bVar10 = bVar10 + pbVar8[0x2000021];
  uVar7 = CONCAT22((short)(uVar7 >> 0x10),CONCAT11(bVar10,bVar5));
  uVar3 = (undefined3)(uVar7 >> 8);
  bVar5 = bVar5 & *(byte *)(ulonglong)uVar7;
  uVar7 = CONCAT31(uVar3,bVar5);
  pbVar8 = (byte *)(ulonglong)uVar7;
  *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH,cVar12)) =
       *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,cVar12)) + bVar5;
  pbVar11 = pbVar11 + -1;
  if (pbVar11 == (byte *)0x0 ||
      *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH,cVar12)) == '\0') {
    *pbVar8 = *pbVar8 + bVar5;
    *(uint *)pbVar8 = *(int *)pbVar8 - uVar7;
    *(byte *)CONCAT62(in_register_00000012,CONCAT11(in_DH + bVar5,cVar12)) =
         *(char *)CONCAT62(in_register_00000012,CONCAT11(in_DH + bVar5,cVar12)) + bVar5;
    *unaff_RSI = *unaff_RSI & (byte)((ulonglong)pbVar11 >> 8);
    *pbVar8 = *pbVar8 + bVar5;
    *pbVar8 = *pbVar8 + bVar5;
    *pbVar8 = *pbVar8 + bVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 & unaff_BH;
  *pbVar8 = *pbVar8 + bVar5;
  pbVar8[0x3e] = pbVar8[0x3e] + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  cVar4 = bVar5 * '\x02';
  pcVar9 = (char *)(ulonglong)CONCAT31(uVar3,cVar4);
  *pcVar9 = *pcVar9 + cVar4;
  pcVar9[0x40] = pcVar9[0x40] + cVar4;
  pcVar9[0x10020000] = pcVar9[0x10020000] & bVar10;
  bVar5 = (char)uRam020000a1b0020000 * '\x02';
  uVar7 = CONCAT31((int3)((uint)uRam020000a1b0020000 >> 8),bVar5);
  pbVar8 = (byte *)(ulonglong)uVar7;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar11 = *pbVar11 + bVar5;
  *pbVar8 = *pbVar8 + cVar12;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + unaff_BL;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *(uint *)pbVar8 = *(int *)pbVar8 + uVar7;
  *(uint *)pbVar8 = *(int *)pbVar8 + uVar7;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 ^ bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *pbVar8 = *pbVar8 + bVar5;
  *(uint *)pbVar8 = *(int *)pbVar8 + uVar7;
  *(uint *)((longlong)pbVar8 * 2) = *(uint *)((longlong)pbVar8 * 2) | uVar7;
  *pbVar8 = *pbVar8 + (char)pbVar11;
  *pbVar8 = *pbVar8 + bVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


