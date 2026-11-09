
===== TdiMapUserRequest @ 140001010 =====

undefined8 TdiMapUserRequest(undefined8 param_1,longlong param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  
                    /* 0x1010  45  TdiMapUserRequest */
  uVar8 = 0xc000000d;
  if (*(int *)(param_3 + 0xc) == 0x210024) {
    return 0xc000000d;
  }
  switch(*(int *)(param_3 + 0xc)) {
  case 0x210000:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    *param_3 = 0x50f;
    uVar8 = 0;
    break;
  default:
    uVar8 = 0xc0000002;
    break;
  case 0x210004:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) == 0x38) {
      *param_3 = 0x30f;
      piVar3 = *(int **)(*(longlong *)(param_2 + 0x18) + 0x20);
      *(int **)(piVar3 + 2) = piVar3 + 0xc;
      lVar6 = (longlong)(piVar3 + 0xc) + (longlong)*piVar3;
      *(longlong *)(piVar3 + 6) = lVar6;
      *(longlong *)(piVar3 + 10) = piVar3[4] + lVar6;
      uVar8 = 0;
      *(int **)(param_3 + 8) = piVar3;
      *(undefined8 *)(param_3 + 0xc) = 0;
    }
    break;
  case 0x210008:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    *param_3 = 0x60f;
    uVar8 = 0;
    break;
  case 0x21000c:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) == 0x38) {
      lVar6 = *(longlong *)(param_2 + 0x18);
      uVar8 = 0;
      *param_3 = 0x40f;
      *(ulonglong *)(param_3 + 4) = (ulonglong)*(ushort *)(lVar6 + 0x30);
    }
    break;
  case 0x210012:
    cVar4 = IoIs32bitProcess(param_2);
    if (cVar4 != '\0') {
      return 0xc0000002;
    }
    uVar5 = *(uint *)(param_3 + 8);
    if (uVar5 < 0x30) {
      return 0xc000000d;
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    *param_3 = 0xc0f;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(lVar6 + 0x20);
    if (uVar5 - 0x30 < 0x30) {
      lVar7 = 0;
    }
    else {
      uVar1 = *(uint *)(lVar6 + 0x30);
      lVar7 = lVar6 + 0x30;
      if (uVar5 - 0x60 < uVar1) {
        return 0xc000000d;
      }
      uVar2 = *(uint *)(lVar6 + 0x40);
      uVar5 = (uVar5 - 0x60) - uVar1;
      if (uVar5 < uVar2) {
        return 0xc000000d;
      }
      if (uVar5 - uVar2 < *(uint *)(lVar6 + 0x50)) {
        return 0xc000000d;
      }
      *(longlong *)(lVar6 + 0x38) = lVar6 + 0x60;
      lVar9 = lVar6 + 0x60 + (longlong)(int)uVar1;
      *(longlong *)(lVar6 + 0x48) = lVar9;
      *(longlong *)(lVar6 + 0x58) = lVar9 + (int)uVar2;
    }
    *(longlong *)(param_3 + 8) = lVar7;
    uVar8 = 0;
    break;
  case 0x210016:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) != 0x28) {
      return 0xc000000d;
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    *param_3 = 0x80f;
    goto LAB_1400011fd;
  case 0x21001a:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) == 0x38) {
      lVar6 = *(longlong *)(param_2 + 0x18);
      uVar8 = 0;
      *param_3 = 0xa0f;
      *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 4);
      *(uint *)(param_3 + 0x10) = (uint)*(ushort *)(lVar6 + 0x30);
      *(undefined8 *)(param_3 + 8) = *(undefined8 *)(lVar6 + 0x20);
      *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(lVar6 + 0x28);
    }
    break;
  case 0x21001d:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) != 0x28) {
      return 0xc000000d;
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    *param_3 = 0x70f;
LAB_1400011fd:
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 4);
    *(uint *)(param_3 + 6) = (uint)*(ushort *)(lVar6 + 0x20);
    goto LAB_140001215;
  case 0x210021:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) != 0x28) {
      return 0xc000000d;
    }
    *param_3 = 0x90f;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 4);
    *(undefined8 *)(param_3 + 8) = *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x20);
    goto LAB_140001215;
  case 0x210029:
    cVar4 = IoIs32bitProcess(param_2);
    if (cVar4 != '\0') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) != 0x30) {
      return 0xc000000d;
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    *param_3 = 0xd0f;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(lVar6 + 0x20);
    *(undefined8 *)(param_3 + 8) = 0;
    goto LAB_140001215;
  case 0x21002c:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    if (*(int *)(param_3 + 8) != 0x28) {
      return 0xc000000d;
    }
    *param_3 = 0x10f;
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x20);
    goto LAB_140001215;
  case 0x210030:
    if (*(char *)(param_2 + 0x40) == '\x01') {
      return 0xc0000002;
    }
    *param_3 = 0x20f;
LAB_140001215:
    uVar8 = 0;
    break;
  case 0x210036:
    cVar4 = IoIs32bitProcess(param_2);
    if (cVar4 != '\0') {
      return 0xc0000002;
    }
    *param_3 = 0xe0f;
    uVar8 = 0;
  }
  return uVar8;
}



===== TdiCopyBufferToMdl @ 140001330 =====

undefined8
TdiCopyBufferToMdl(longlong param_1,ulonglong param_2,uint param_3,longlong *param_4,uint param_5,
                  int *param_6)

{
  void *_Dst;
  uint uVar1;
  ulonglong _Size;
  void *_Src;
  uint uVar2;
  uint uVar3;
  
                    /* 0x1330  21  TdiCopyBufferToMdl */
  uVar2 = 0;
  _Size = (ulonglong)param_3;
  *param_6 = 0;
  if (param_3 == 0) {
    return 0;
  }
  if (param_4 == (longlong *)0x0) {
    return 0x80000005;
  }
  if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
    _Dst = (void *)MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000010);
  }
  else {
    _Dst = (void *)param_4[3];
  }
  while( true ) {
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    uVar3 = *(uint *)(param_4 + 5);
    if (param_5 <= uVar2) break;
    uVar1 = param_5 - uVar2;
    if (uVar1 < uVar3) {
      uVar3 = uVar3 + (uVar2 - param_5);
      _Dst = (void *)((longlong)_Dst + (ulonglong)uVar1);
      break;
    }
    param_4 = (longlong *)*param_4;
    if (uVar3 == uVar1) {
      if (param_4 == (longlong *)0x0) {
        return 0x80000005;
      }
      if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
        _Dst = (void *)MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000010);
      }
      else {
        _Dst = (void *)param_4[3];
      }
      if (_Dst == (void *)0x0) {
        return 0xc000009a;
      }
      uVar3 = *(uint *)(param_4 + 5);
      break;
    }
    uVar2 = uVar2 + uVar3;
    if (param_4 == (longlong *)0x0) {
      return 0x80000005;
    }
    if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000010);
    }
    else {
      _Dst = (void *)param_4[3];
    }
  }
  _Src = (void *)((param_2 & 0xffffffff) + param_1);
  while( true ) {
    while( true ) {
      uVar2 = (uint)_Size;
      if (uVar2 == 0) {
        return 0;
      }
      if (uVar3 == 0) break;
      if (uVar2 <= uVar3) {
        memmove(_Dst,_Src,_Size);
        *param_6 = *param_6 + uVar2;
        return 0;
      }
      memmove(_Dst,_Src,(ulonglong)uVar3);
      *param_6 = *param_6 + uVar3;
      _Size = (ulonglong)(uVar2 - uVar3);
      _Src = (void *)((longlong)_Src + (ulonglong)uVar3);
      uVar3 = 0;
    }
    param_4 = (longlong *)*param_4;
    if (param_4 == (longlong *)0x0) {
      return 0x80000005;
    }
    if ((*(byte *)((longlong)param_4 + 10) & 5) == 0) {
      _Dst = (void *)MmMapLockedPagesSpecifyCache(param_4,0,1,0,0,0x40000010);
    }
    else {
      _Dst = (void *)param_4[3];
    }
    if (_Dst == (void *)0x0) break;
    uVar3 = *(uint *)(param_4 + 5);
  }
  return 0x80000005;
}



===== TdipAddMultiSzToMultiSz @ 140001550 =====

undefined8 TdipAddMultiSzToMultiSz(ushort *param_1,wchar_t *param_2,undefined8 *param_3)

{
  longlong lVar1;
  uint uVar2;
  HRESULT HVar3;
  wchar_t *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  size_t sVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  STRSAFE_PCNZWCH pwVar10;
  size_t local_res8;
  
  uVar7 = 0;
  lVar1 = *(longlong *)(param_1 + 4);
  local_res8 = 0;
  *param_3 = 0;
  if ((ulonglong)param_1[1] - (ulonglong)*param_1 < 2) {
    return 0xc000000d;
  }
  lVar9 = 0;
  for (uVar4 = 0; uVar4 < *param_1 >> 1; uVar4 = uVar4 + local_res8 + 1) {
    pwVar10 = (STRSAFE_PCNZWCH)(uVar4 * 2 + lVar1);
    sVar6 = (ulonglong)*param_1 + uVar4 * -2 + 1;
    if (pwVar10 == (STRSAFE_PCNZWCH)0x0) {
      return 0xc000000d;
    }
    if (0x7fffffff < sVar6) {
      return 0xc000000d;
    }
    HVar3 = StringLengthWorkerW(pwVar10,sVar6,&local_res8);
    if (HVar3 < 0) {
      return 0xc000000d;
    }
    if (HVar3 != 0) {
      return 0xc000000d;
    }
    uVar8 = TdipIsSzInMultiSzSafe(pwVar10,param_2);
    if ((char)uVar8 == '\0') {
      lVar9 = lVar9 + local_res8 * 2 + 2;
    }
  }
  if (lVar9 != 0) {
    uVar2 = TdipCbOfMultiSzSafe(param_2);
    lVar9 = (ulonglong)uVar2 + lVar9;
    _Dst = (wchar_t *)ExAllocatePool2(0x40,lVar9 + 2,0x6a494454);
    if (_Dst == (wchar_t *)0x0) {
      uVar7 = 0xc000009a;
    }
    else {
      uVar4 = (ulonglong)(uVar2 >> 1);
      memmove(_Dst,param_2,(ulonglong)uVar2);
      uVar8 = 0;
      while (uVar8 < *param_1 >> 1) {
        sVar6 = ((*param_1 >> 1) - uVar8) + 1;
        pwVar10 = (STRSAFE_PCNZWCH)(lVar1 + uVar8 * 2);
        if ((pwVar10 == (STRSAFE_PCNZWCH)0x0) || (0x7fffffff < sVar6)) {
LAB_140001665:
          ExFreePoolWithTag(_Dst,0x6a494454);
          return 0xc000000d;
        }
        HVar3 = StringLengthWorkerW(pwVar10,sVar6,&local_res8);
        if ((HVar3 < 0) || (HVar3 != 0)) goto LAB_140001665;
        uVar5 = TdipIsSzInMultiSzSafe(pwVar10,_Dst);
        if ((char)uVar5 == '\0') {
          HVar3 = StringCchCatW(_Dst + uVar4,(lVar9 + 2U >> 1) - uVar4,pwVar10);
          if (HVar3 != 0) goto LAB_140001665;
          uVar4 = uVar4 + 1 + local_res8;
          uVar8 = uVar8 + 1 + local_res8;
        }
        else {
          uVar8 = uVar8 + 1 + local_res8;
        }
      }
      *param_3 = _Dst;
    }
  }
  return uVar7;
}



===== TdiNotifyPnpClientList @ 140001770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TdiNotifyPnpClientList(undefined8 *param_1,longlong param_2,char param_3)

{
  char cVar1;
  wchar_t wVar2;
  longlong *plVar3;
  bool bVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  HRESULT HVar8;
  code *pcVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  undefined8 uVar13;
  wchar_t *pwVar14;
  wchar_t *_Str1;
  longlong lVar15;
  longlong lVar16;
  ulonglong uVar17;
  undefined8 *puVar18;
  undefined4 uVar19;
  undefined4 local_res10;
  size_t local_res20;
  
  puVar18 = (undefined8 *)*param_1;
  uVar19 = 0;
  local_res10 = 0;
  if (puVar18 != param_1) {
    do {
      cVar1 = *(char *)(param_2 + 0x10);
      *(undefined8 **)(param_2 + 0x18) = puVar18;
      if (cVar1 == '\0') {
        pwVar12 = (wchar_t *)puVar18[0xd];
        pwVar11 = *(wchar_t **)(param_2 + 0x80);
        if ((pwVar12 != (wchar_t *)0x0) && (pwVar11 != (wchar_t *)0x0)) {
          for (; *pwVar12 != L'\0'; pwVar12 = pwVar12 + lVar16 + 2) {
            iVar6 = _wcsicmp(pwVar12,pwVar11);
            if (iVar6 == 0) {
              bVar4 = true;
              goto LAB_1400018fd;
            }
            lVar15 = -1;
            do {
              lVar16 = lVar15;
              lVar15 = lVar16 + 1;
            } while (pwVar12[lVar16 + 1] != L'\0');
          }
        }
        bVar4 = false;
LAB_1400018fd:
        if (*(short *)(puVar18 + 3) == 1) {
          if (param_3 == '\0') {
            pcVar9 = (code *)puVar18[7];
          }
          else {
            pcVar9 = (code *)puVar18[6];
          }
LAB_140001ccc:
          if (pcVar9 != (code *)0x0) {
            (*pcVar9)(param_2 + 0x78);
          }
          goto LAB_1400017fb;
        }
        if (((bVar4) || (puVar18[6] == 0)) ||
           (plVar3 = (longlong *)puVar18[0xb], plVar3 == (longlong *)0x0)) goto LAB_1400017fb;
        pwVar12 = (wchar_t *)*plVar3;
        lVar15 = 0;
        if (pwVar12 != (wchar_t *)0x0) {
          do {
            uVar10 = 0xffffffffffffffff;
            uVar17 = (ulonglong)(*(ushort *)(param_2 + 0x78) >> 1);
            do {
              uVar10 = uVar10 + 1;
            } while (pwVar12[uVar10] != L'\0');
            if ((uVar17 == uVar10) &&
               (iVar6 = _wcsnicmp(*(wchar_t **)(param_2 + 0x80),pwVar12,uVar17), iVar6 == 0)) break;
            pwVar12 = (wchar_t *)plVar3[lVar15 + 1];
            lVar15 = lVar15 + 1;
          } while (pwVar12 != (wchar_t *)0x0);
        }
        if (plVar3[lVar15] == 0) goto LAB_1400017fb;
        local_res20 = 0;
        pwVar12 = (wchar_t *)(puVar18[0xb] + (ulonglong)*(uint *)(puVar18 + 0xc) * 8);
        lVar15 = 0;
        lVar16 = 0;
        while (lVar16 == 0) {
          pwVar11 = L"";
          HVar8 = StringLengthWorkerW(L"",3,&local_res20);
          if (HVar8 < 0) {
            local_res20 = 0;
            goto LAB_14000180b;
          }
          if (HVar8 != 0) goto LAB_14000180b;
          uVar10 = TdipIsSzInMultiSzSafe(pwVar11,pwVar12);
          if ((char)uVar10 == '\0') {
            lVar15 = lVar15 + local_res20 * 2 + 2;
          }
          lVar16 = local_res20 + 1;
        }
        if (lVar15 == 0) {
          pwVar11 = (wchar_t *)0x0;
LAB_140001c61:
          uVar13 = 1;
          if (param_3 == '\0') {
            uVar13 = 2;
          }
          (*(code *)puVar18[6])(uVar13,param_2 + 0x78,pwVar11);
          ExFreePoolWithTag(pwVar11,0x6a494454);
          goto LAB_1400017fb;
        }
        uVar7 = TdipCbOfMultiSzSafe(pwVar12);
        lVar15 = (ulonglong)uVar7 + lVar15;
        pwVar11 = (wchar_t *)ExAllocatePool2(0x40,lVar15 + 2,0x6a494454);
        uVar19 = local_res10;
        if (pwVar11 != (wchar_t *)0x0) {
          uVar10 = (ulonglong)(uVar7 >> 1);
          memmove(pwVar11,pwVar12,(ulonglong)uVar7);
          lVar16 = 0;
          while (lVar16 == 0) {
            pwVar12 = L"";
            HVar8 = StringLengthWorkerW(L"",2,&local_res20);
            if (HVar8 < 0) {
              local_res20 = 0;
LAB_140001af1:
              ExFreePoolWithTag(pwVar11,0x6a494454);
              goto LAB_14000180b;
            }
            if (HVar8 != 0) goto LAB_140001af1;
            uVar17 = TdipIsSzInMultiSzSafe(pwVar12,pwVar11);
            sVar5 = local_res20;
            if ((char)uVar17 == '\0') {
              HVar8 = StringCchCatW(pwVar11 + uVar10,(lVar15 + 2U >> 1) - uVar10,L"");
              if (HVar8 != 0) goto LAB_140001af1;
              uVar10 = uVar10 + 1 + sVar5;
            }
            lVar16 = sVar5 + 1;
          }
          pwVar12 = (wchar_t *)puVar18[0xd];
          if ((pwVar12 != (wchar_t *)0x0) && (*pwVar12 != L'\0')) {
            wVar2 = *pwVar11;
            _Str1 = pwVar11;
            while (wVar2 != L'\0') {
              for (pwVar14 = pwVar12; *pwVar14 != L'\0'; pwVar14 = pwVar14 + ((int)uVar17 + 2)) {
                uVar10 = 0xffffffffffffffff;
                do {
                  uVar17 = uVar10;
                  uVar10 = uVar17 + 1;
                } while (pwVar14[uVar10] != L'\0');
                iVar6 = _wcsicmp(_Str1,pwVar14);
                if (iVar6 == 0) {
                  pwVar14 = _Str1 + (uVar10 & 0xffffffff) + 1;
                  iVar6 = TdipCbOfMultiSzSafe(pwVar14);
                  memmove(_Str1,pwVar14,(longlong)(iVar6 + 2));
                  goto LAB_140001d85;
                }
              }
              lVar15 = -1;
              do {
                lVar16 = lVar15;
                lVar15 = lVar16 + 1;
              } while (_Str1[lVar16 + 1] != L'\0');
              _Str1 = _Str1 + lVar16 + 2;
LAB_140001d85:
              wVar2 = *_Str1;
            }
          }
          goto LAB_140001c61;
        }
      }
      else {
        if (cVar1 == '\x01') {
          if (*(short *)(puVar18 + 3) == 1) {
            if (param_3 == '\0') {
              pcVar9 = (code *)puVar18[9];
            }
            else {
              pcVar9 = (code *)puVar18[8];
            }
            goto LAB_140001ccc;
          }
          if (param_3 == '\0') {
            pcVar9 = (code *)puVar18[9];
          }
          else {
            pcVar9 = (code *)puVar18[8];
          }
          if (pcVar9 != (code *)0x0) {
            (*pcVar9)(param_2 + 0x78,param_2 + 0x40,*(undefined8 *)(param_2 + 0x58));
          }
        }
        else if (cVar1 == '\x02') {
          if ((code *)puVar18[10] != (code *)0x0) {
            iVar6 = (*(code *)puVar18[10])
                              (param_2 + 0x78,*(undefined8 *)(param_2 + 0x28),
                               *(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58));
            if (iVar6 == 0x103) {
              uVar19 = 0x103;
              local_res10 = 0x103;
            }
            else {
              if (iVar6 < 0) {
                *(int *)(param_2 + 0x38) = iVar6;
                DbgPrint("Client: %wZ returned %x\n",puVar18 + 4,iVar6);
              }
              LOCK();
              *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + -1;
              UNLOCK();
            }
          }
        }
        else if ((((cVar1 == '\x03') && (*(int *)(param_2 + 100) != 0)) &&
                 (*(short *)(puVar18 + 3) != 1)) &&
                (((code *)puVar18[6] != (code *)0x0 &&
                 ((*(code *)puVar18[6])(4,param_2 + 0x78,0), ProvidersReady == ProvidersRegistered))
                )) {
          (*(code *)puVar18[6])(5,0,0);
        }
LAB_1400017fb:
        puVar18 = (undefined8 *)*puVar18;
        *(undefined8 *)(param_2 + 0x18) = 0;
        *(undefined4 *)(param_2 + 0x20) = uVar19;
      }
LAB_14000180b:
    } while (puVar18 != param_1);
  }
  return uVar19;
}



===== TdipCbOfMultiSzSafe @ 140001df0 =====

int TdipCbOfMultiSzSafe(short *param_1)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_1 == (short *)0x0) {
    return 0;
  }
  sVar2 = *param_1;
  while (sVar2 != 0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (param_1[lVar4] != 0);
    uVar3 = (int)lVar4 + 1;
    iVar5 = iVar5 + uVar3;
    psVar1 = param_1 + uVar3;
    param_1 = param_1 + uVar3;
    sVar2 = *psVar1;
  }
  return iVar5 * 2;
}



===== TdipIsSzInMultiSzSafe @ 140001e50 =====

ulonglong TdipIsSzInMultiSzSafe(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  ulonglong in_RAX;
  undefined4 extraout_var;
  ulonglong uVar2;
  
  if ((param_2 != (wchar_t *)0x0) && (param_1 != (wchar_t *)0x0)) {
    for (; *param_2 != L'\0'; param_2 = param_2 + uVar2 + 2) {
      iVar1 = _wcsicmp(param_2,param_1);
      if (iVar1 == 0) {
        return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),1);
      }
      in_RAX = 0xffffffffffffffff;
      do {
        uVar2 = in_RAX;
        in_RAX = uVar2 + 1;
      } while (param_2[uVar2 + 1] != L'\0');
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== StringLengthWorkerW @ 140001ed0 =====

HRESULT __stdcall StringLengthWorkerW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  HRESULT HVar1;
  size_t sVar2;
  
  sVar2 = cchMax;
  for (; (sVar2 != 0 && (*psz != L'\0')); psz = psz + 1) {
    sVar2 = sVar2 - 1;
  }
  HVar1 = -0x7ff8ffa9;
  if (sVar2 != 0) {
    HVar1 = 0;
  }
  if (pcchLength == (size_t *)0x0) {
    return HVar1;
  }
  if (sVar2 == 0) {
    *pcchLength = 0;
    return HVar1;
  }
  *pcchLength = cchMax - sVar2;
  return HVar1;
}



===== StringCchCatW @ 140001f20 =====

HRESULT __stdcall StringCchCatW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc)

{
  wchar_t wVar1;
  STRSAFE_LPWSTR pwVar2;
  longlong lVar3;
  STRSAFE_LPWSTR pwVar4;
  HRESULT HVar5;
  longlong lVar6;
  size_t sVar7;
  longlong lVar8;
  
  if (0x7ffffffe < cchDest - 1) {
    return -0x7ff8ffa9;
  }
  pwVar2 = pszDest;
  sVar7 = cchDest;
  do {
    if (*pwVar2 == L'\0') break;
    pwVar2 = pwVar2 + 1;
    sVar7 = sVar7 - 1;
  } while (sVar7 != 0);
  HVar5 = -0x7ff8ffa9;
  if (sVar7 != 0) {
    HVar5 = 0;
  }
  lVar3 = cchDest - sVar7;
  if (sVar7 == 0) {
    return HVar5;
  }
  pwVar2 = pszDest + lVar3;
  lVar6 = cchDest - lVar3;
  if (lVar6 != 0) {
    lVar8 = (lVar3 - cchDest) + 0x7ffffffe + lVar6;
    lVar3 = (longlong)pszSrc - (longlong)pwVar2;
    do {
      if ((lVar8 == 0) || (wVar1 = *(wchar_t *)(lVar3 + (longlong)pwVar2), wVar1 == L'\0')) break;
      *pwVar2 = wVar1;
      lVar8 = lVar8 + -1;
      pwVar2 = pwVar2 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  pwVar4 = pwVar2 + -1;
  if (lVar6 != 0) {
    pwVar4 = pwVar2;
  }
  *pwVar4 = L'\0';
  HVar5 = -0x7ff8ff86;
  if (lVar6 != 0) {
    HVar5 = 0;
  }
  return HVar5;
}



===== TdiNotifyNewPnpClient @ 140001fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TdiNotifyNewPnpClient(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  
  puVar1 = (undefined8 *)*param_1;
  do {
    if (puVar1 == param_1) {
      if ((*(longlong *)(param_2 + 0x30) != 0) && (*(short *)(param_2 + 0x18) != 1)) {
        for (puVar1 = (undefined8 *)*param_1; puVar1 != param_1; puVar1 = (undefined8 *)*puVar1) {
          if ((*(char *)(puVar1 + 2) == '\x03') && (*(int *)((longlong)puVar1 + 100) != 0)) {
            (**(code **)(param_2 + 0x30))(4,puVar1 + 0xf);
          }
        }
        if (ProvidersReady == ProvidersRegistered) {
          (**(code **)(param_2 + 0x30))(5,0,0);
        }
      }
      return;
    }
    if (*(char *)(puVar1 + 2) == '\0') {
      pcVar3 = *(code **)(param_2 + 0x30);
      if (*(short *)(param_2 + 0x18) == 1) {
LAB_140002105:
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)(puVar1 + 0xf);
        }
      }
      else if ((pcVar3 != (code *)0x0) &&
              (uVar2 = TdipMultiSzStrStr(*(longlong **)(param_2 + 0x58),(ushort *)(puVar1 + 0xf)),
              (char)uVar2 != '\0')) {
        (**(code **)(param_2 + 0x30))
                  (1,puVar1 + 0xf,
                   *(longlong *)(param_2 + 0x58) + (ulonglong)*(uint *)(param_2 + 0x60) * 8);
      }
    }
    else if (*(char *)(puVar1 + 2) == '\x01') {
      pcVar3 = *(code **)(param_2 + 0x40);
      if (*(short *)(param_2 + 0x18) == 1) goto LAB_140002105;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(puVar1 + 0xf,puVar1 + 8,puVar1[0xb]);
      }
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== TdiHandlePnpOperation @ 140002140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TdiHandlePnpOperation
               (undefined8 *param_1,undefined8 *param_2,undefined4 *param_3,undefined8 param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined8 *puVar8;
  wchar_t *local_res8;
  ushort local_28 [4];
  wchar_t *local_20;
  
  iVar3 = *(int *)((longlong)param_2 + 0x24);
  puVar7 = param_3;
  for (puVar8 = (undefined8 *)*param_1; puVar8 != param_1; puVar8 = (undefined8 *)*puVar8) {
    puVar6 = puVar8 + 4;
    puVar7 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
    iVar2 = RtlCompareUnicodeString(*param_2);
    if (iVar2 == 0) {
      if (puVar8[0xb] != 0) {
        puVar6 = (undefined8 *)0x0;
        ExFreePoolWithTag();
      }
      TdipBuildProviderList((longlong)puVar8,puVar6,puVar7,param_4);
      if (iVar3 != 3) {
        if (iVar3 == 7) goto LAB_140002478;
        if (iVar3 == 8) goto LAB_140002264;
        puVar6 = PnpHandlerProviderList;
        goto LAB_1400021d0;
      }
      if (*(int *)(param_2 + 4) == 0) {
        param_3[4] = (uint)*(ushort *)param_2[2];
        uVar5 = 5;
        uVar4 = *(undefined8 *)(param_2[2] + 8);
      }
      else {
        param_3[4] = *(int *)(param_2 + 4);
        uVar5 = 4;
        uVar4 = param_2[3];
      }
      *(undefined8 *)(param_3 + 2) = uVar4;
      *param_3 = uVar5;
      if (((code *)puVar8[10] != (code *)0x0) &&
         (iVar3 = (*(code *)puVar8[10])(param_2[1],param_3,0,0), iVar3 == 0x103)) {
        return;
      }
      break;
    }
  }
  goto LAB_14000216f;
LAB_1400021d0:
  if ((undefined8 **)puVar6 != &PnpHandlerProviderList) {
    if (*(char *)(puVar6 + 2) == '\0') {
      iVar2 = RtlCompareUnicodeString(param_2[1],puVar6 + 0xf,1);
      if (iVar2 == 0) {
        if (iVar3 == 1) {
          TdipMultiSzStrStr((longlong *)puVar8[0xb],(ushort *)(puVar6 + 0xf));
          if ((code *)puVar8[6] != (code *)0x0) {
            (*(code *)puVar8[6])(1,param_2[1],puVar8[0xb] + (ulonglong)*(uint *)(puVar8 + 0xc) * 8);
          }
          goto LAB_14000216f;
        }
        if (iVar3 == 2) {
          if (puVar8[10] != 0) {
            *param_3 = 2;
            *(undefined8 *)(param_3 + 2) = 0;
            param_3[4] = 0;
            iVar3 = (*(code *)puVar8[10])(param_2[1],param_3,0,0);
            if (iVar3 == 0x103) {
              return;
            }
            if (iVar3 != 0) goto LAB_14000216f;
          }
        }
        else if (iVar3 != 4) {
          if (iVar3 == 7) {
LAB_140002478:
            local_res8 = (wchar_t *)0x0;
            if (((ushort *)param_2[2] != (ushort *)0x0) &&
               (TdipAddMultiSzToMultiSz((ushort *)param_2[2],(wchar_t *)puVar8[0xd],&local_res8),
               pwVar1 = local_res8, local_res8 != (wchar_t *)0x0)) {
              if (puVar8[0xd] != 0) {
                ExFreePoolWithTag(puVar8[0xd],0);
              }
              puVar8[0xd] = pwVar1;
            }
            if (puVar8[6] != 0) {
              local_20 = L"";
              local_28[0] = 2;
              local_28[1] = 4;
              local_28[2] = 0;
              local_28[3] = 0;
              local_res8 = (wchar_t *)0x0;
              uVar4 = TdipAddMultiSzToMultiSz
                                (local_28,(wchar_t *)
                                          (puVar8[0xb] + (ulonglong)*(uint *)(puVar8 + 0xc) * 8),
                                 &local_res8);
              pwVar1 = local_res8;
              if ((int)uVar4 == 0) {
                TdipRemoveMultiSzFromMultiSz((wchar_t *)puVar8[0xd],local_res8);
                (*(code *)puVar8[6])(3,param_2[1],pwVar1);
                ExFreePoolWithTag(pwVar1,0x6a494454);
              }
            }
          }
          else if (iVar3 == 8) {
LAB_140002264:
            if (((wchar_t *)puVar8[0xd] != (wchar_t *)0x0) && (param_2[2] != 0)) {
              TdipRemoveMultiSzFromMultiSz(*(wchar_t **)(param_2[2] + 8),(wchar_t *)puVar8[0xd]);
              if (*(short *)puVar8[0xd] != 0) {
                ExFreePoolWithTag((short *)puVar8[0xd],0);
                puVar8[0xd] = 0;
              }
            }
            if (puVar8[6] != 0) {
              local_20 = L"";
              local_28[0] = 2;
              local_28[1] = 4;
              local_28[2] = 0;
              local_28[3] = 0;
              local_res8 = (wchar_t *)0x0;
              TdipAddMultiSzToMultiSz
                        (local_28,(wchar_t *)(puVar8[0xb] + (ulonglong)*(uint *)(puVar8 + 0xc) * 8),
                         &local_res8);
              pwVar1 = local_res8;
              TdipRemoveMultiSzFromMultiSz((wchar_t *)puVar8[0xd],local_res8);
              (*(code *)puVar8[6])(3,param_2[1],pwVar1);
              ExFreePoolWithTag(pwVar1,0x6a494454);
            }
          }
          goto LAB_14000216f;
        }
        if ((code *)puVar8[6] != (code *)0x0) {
          (*(code *)puVar8[6])(2,param_2[1],puVar8[0xb] + (ulonglong)*(uint *)(puVar8 + 0xc) * 8);
        }
        goto LAB_14000216f;
      }
      puVar6 = (undefined8 *)*puVar6;
    }
    else {
      puVar6 = (undefined8 *)*puVar6;
    }
    goto LAB_1400021d0;
  }
  if ((code *)puVar8[6] != (code *)0x0) {
    (*(code *)puVar8[6])(3,param_2[1],puVar8[0xb] + (ulonglong)*(uint *)(puVar8 + 0xc) * 8);
  }
LAB_14000216f:
  ExFreePoolWithTag(*(undefined8 *)(param_3 + 0x16),0);
  ExFreePoolWithTag(param_3,0);
  return;
}



===== TdipBuildProviderList @ 140002550 =====

bool TdipBuildProviderList
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_stack_ffffffffffffffe8;
  
  TdipGetMultiSZList((longlong *)(param_1 + 0x58),param_2,param_1 + 0x20,param_4,
                     in_stack_ffffffffffffffe8,(uint *)(param_1 + 0x60));
  return *(longlong *)(param_1 + 0x58) != 0;
}



===== TdipGetMultiSZList @ 140002590 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TdipGetMultiSZList(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                       ,undefined8 param_5,uint *param_6)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *_Dst;
  short *psVar7;
  short *_Src;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 auStack_2d8 [32];
  uint local_2b8;
  uint *local_2b0;
  uint local_2a8 [2];
  undefined8 local_2a0;
  undefined8 local_298;
  undefined1 *local_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined8 local_270;
  undefined8 *local_268;
  undefined4 local_260;
  undefined4 local_25c;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_274 = 0;
  local_25c = 0;
  local_2a0 = 0;
  local_298 = 0x1000000;
  local_288 = 0;
  uStack_280 = 0;
  memset(local_248,0,0x200);
  local_290 = local_248;
  local_2a8[0] = 0;
  RtlAppendUnicodeToString(&local_298,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\")
  ;
  RtlAppendUnicodeStringToString(&local_298,param_3);
  RtlAppendUnicodeToString(&local_298,L"\\Linkage");
  RtlInitUnicodeString(&local_288,L"Bind");
  local_268 = &local_298;
  local_278 = 0x30;
  local_270 = 0;
  local_260 = 0x240;
  local_258 = 0;
  uStack_250 = 0;
  iVar2 = ZwOpenKey(&local_2a0,1,&local_278);
  if (-1 < iVar2) {
    local_2b0 = local_2a8;
    local_2b8 = 0;
    iVar2 = ZwQueryValueKey(local_2a0,&local_288,1,0);
    if ((iVar2 != -0x3fffffdd) ||
       (lVar3 = ExAllocatePool2(0x40,local_2a8[0],0x6a494454), lVar3 == 0)) {
      ZwClose(local_2a0);
      *param_1 = 0;
      *param_6 = 0;
      return;
    }
    local_2b0 = local_2a8;
    local_2b8 = local_2a8[0];
    iVar2 = ZwQueryValueKey(local_2a0,&local_288,1,lVar3);
    ZwClose(local_2a0);
    if (-1 < iVar2) {
      local_2a8[0] = *(uint *)(lVar3 + 0xc);
      if (2 < local_2a8[0]) {
        _Src = (short *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3);
        uVar6 = 0;
        psVar7 = _Src;
        uVar10 = (ulonglong)((local_2a8[0] - 1 >> 1) + 1);
        do {
          uVar9 = uVar10;
          sVar1 = *psVar7;
          psVar7 = psVar7 + 1;
          uVar5 = uVar6 + 1;
          if (sVar1 != 0) {
            uVar5 = uVar6;
          }
          uVar6 = uVar5;
          uVar10 = uVar9 - 1;
        } while (uVar10 != 0);
        puVar4 = (undefined8 *)
                 ExAllocatePool2((int)uVar9 + 0x3f,(ulonglong)uVar6 * 8 + (ulonglong)local_2a8[0],
                                 0x6b494454);
        if (puVar4 != (undefined8 *)0x0) {
          _Dst = puVar4 + uVar6;
          memmove(_Dst,_Src,(ulonglong)local_2a8[0]);
          ExFreePoolWithTag(lVar3,0);
          puVar8 = puVar4;
          if (1 < uVar6) {
            *puVar4 = _Dst;
            puVar8 = puVar4 + 1;
            psVar7 = (short *)((longlong)_Dst + 2);
            uVar5 = 6;
            if (6 < local_2a8[0]) {
              do {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
                if (sVar1 == 0) {
                  *puVar8 = psVar7;
                  puVar8 = puVar8 + 1;
                }
                uVar5 = uVar5 + 2;
              } while (uVar5 < local_2a8[0]);
            }
          }
          *puVar8 = 0;
          *param_1 = puVar4;
          *param_6 = uVar6;
          return;
        }
      }
    }
    ExFreePoolWithTag(lVar3,0);
  }
  *param_1 = 0;
  *param_6 = 0;
  return;
}



===== TdipMultiSzStrStr @ 1400028c0 =====

ulonglong TdipMultiSzStrStr(longlong *param_1,ushort *param_2)

{
  int iVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  wchar_t *_Str2;
  longlong lVar3;
  int iVar4;
  
  if (param_1 == (longlong *)0x0) {
    return in_RAX & 0xffffffffffffff00;
  }
  _Str2 = (wchar_t *)*param_1;
  iVar4 = 0;
  if (_Str2 != (wchar_t *)0x0) {
    lVar3 = 0;
    do {
      uVar2 = 0xffffffffffffffff;
      do {
        uVar2 = uVar2 + 1;
      } while (_Str2[uVar2] != L'\0');
      if ((*param_2 >> 1 == uVar2) &&
         (iVar1 = _wcsnicmp(*(wchar_t **)(param_2 + 4),_Str2,(ulonglong)(*param_2 >> 1)), iVar1 == 0
         )) break;
      _Str2 = (wchar_t *)param_1[lVar3 + 1];
      lVar3 = lVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (_Str2 != (wchar_t *)0x0);
  }
  return CONCAT71((int7)(int3)((uint)iVar4 >> 8),param_1[iVar4] != 0);
}



===== TdiRegisterPnPHandlers @ 140002970 =====

int TdiRegisterPnPHandlers(byte *param_1,uint param_2,longlong *param_3)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  
                    /* 0x2970  55  TdiRegisterPnPHandlers */
  lVar5 = 0;
  if (2 < *param_1) {
    return -0x3ffefffc;
  }
  if (param_2 < 0x38) {
    return -0x3ffefffb;
  }
  lVar3 = ExAllocatePool2(0x40,0x78,0x66494454);
  if (lVar3 != 0) {
    lVar4 = ExAllocatePool2(0x40,0x88,0x61494454);
    *(longlong *)(lVar3 + 0x70) = lVar4;
    if (lVar4 != 0) {
      if (*(longlong *)(param_1 + 8) == 0) {
        *(undefined4 *)(lVar3 + 0x20) = 0;
        *(undefined8 *)(lVar3 + 0x28) = 0;
LAB_140002a8e:
        *(undefined2 *)(lVar3 + 0x18) = *(undefined2 *)param_1;
        *(undefined1 *)(lVar3 + 0x10) = 2;
        sVar1 = *(short *)param_1;
        *(undefined8 *)(lVar3 + 0x30) = *(undefined8 *)(param_1 + 0x18);
        if (sVar1 == 1) {
          *(undefined8 *)(lVar3 + 0x38) = *(undefined8 *)(param_1 + 0x20);
          *(undefined8 *)(lVar3 + 0x40) = *(undefined8 *)(param_1 + 0x28);
          *(undefined8 *)(lVar3 + 0x48) = *(undefined8 *)(param_1 + 0x30);
          uVar6 = 0;
        }
        else {
          *(undefined8 *)(lVar3 + 0x40) = *(undefined8 *)(param_1 + 0x28);
          *(undefined8 *)(lVar3 + 0x48) = *(undefined8 *)(param_1 + 0x30);
          uVar6 = *(undefined8 *)(param_1 + 0x10);
        }
        *(undefined8 *)(lVar3 + 0x50) = uVar6;
        *(undefined8 *)(lVar3 + 0x68) = 0;
        *param_3 = lVar3;
        iVar2 = TdiHandleSerializedRequest(lVar3,8);
        if (iVar2 == 0) {
          return 0;
        }
        if (lVar5 != 0) {
          ExFreePoolWithTag(lVar5,0);
        }
        ExFreePoolWithTag(*(undefined8 *)(lVar3 + 0x70),0);
        ExFreePoolWithTag(lVar3,0);
        *param_3 = 0;
        return iVar2;
      }
      lVar5 = ExAllocatePool2(0x40,*(undefined2 *)(*(longlong *)(param_1 + 8) + 2),0x67494454);
      if (lVar5 != 0) {
        *(undefined2 *)(lVar3 + 0x20) = **(undefined2 **)(param_1 + 8);
        *(undefined2 *)(lVar3 + 0x22) = *(undefined2 *)(*(longlong *)(param_1 + 8) + 2);
        *(longlong *)(lVar3 + 0x28) = lVar5;
        RtlCopyUnicodeString((undefined2 *)(lVar3 + 0x20),*(undefined8 *)(param_1 + 8));
        goto LAB_140002a8e;
      }
      ExFreePoolWithTag(*(undefined8 *)(lVar3 + 0x70),0);
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return -0x3fffff66;
}



===== TdiEnumerateAddresses @ 140002b60 =====

void TdiEnumerateAddresses(longlong param_1)

{
                    /* 0x2b60  41  TdiEnumerateAddresses */
  TdiHandleSerializedRequest(param_1,0x10);
  return;
}



===== TdiExecuteRequestWrapper @ 140002b80 =====

void TdiExecuteRequestWrapper(longlong *param_1)

{
  TdiExecuteRequest(param_1,'\x01');
  return;
}



===== TdiRegisterNetAddress @ 140002ba0 =====

int TdiRegisterNetAddress(ushort *param_1,undefined2 *param_2,ushort *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  void *_Dst;
  
                    /* 0x2ba0  53  TdiRegisterNetAddress */
  lVar2 = ExAllocatePool2(0x40,(ulonglong)*param_1 + 0x7c,0x65494454);
  if (lVar2 == 0) {
    return -0x3fffff66;
  }
  *(undefined1 *)(lVar2 + 0x10) = 1;
  *(ushort *)(lVar2 + 0x78) = *param_1;
  *(ushort *)(lVar2 + 0x7a) = param_1[1];
  memmove((void *)(lVar2 + 0x7c),param_1 + 2,(ulonglong)*param_1);
  *param_4 = lVar2;
  if (param_2 == (undefined2 *)0x0) {
    *(undefined8 *)(lVar2 + 0x48) = 0;
LAB_140002c3a:
    if (param_3 == (ushort *)0x0) {
      *(undefined8 *)(lVar2 + 0x58) = 0;
    }
    else {
      lVar3 = ExAllocatePool2(0x40,(ulonglong)*param_3 + 8,0x76494454);
      *(longlong *)(lVar2 + 0x58) = lVar3;
      if (lVar3 == 0) {
        if (*(longlong *)(lVar2 + 0x48) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 0x48),0);
        }
        goto LAB_140002d19;
      }
      *(ushort *)(lVar3 + 2) = param_3[1];
      **(ushort **)(lVar2 + 0x58) = *param_3;
      memmove((void *)(*(longlong *)(lVar2 + 0x58) + 8),param_3 + 4,(ulonglong)*param_3);
    }
    iVar1 = TdiHandleSerializedRequest(lVar2,0xb);
    if (iVar1 != 0) {
      *param_4 = 0;
      if (*(longlong *)(lVar2 + 0x48) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x48),0);
        *(undefined8 *)(lVar2 + 0x48) = 0;
      }
      if (*(longlong *)(lVar2 + 0x58) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x58),0);
        *(undefined8 *)(lVar2 + 0x58) = 0;
      }
      ExFreePoolWithTag(lVar2,0);
    }
  }
  else {
    _Dst = (void *)ExAllocatePool2(0x40,param_2[1],0x75494454);
    *(void **)(lVar2 + 0x48) = _Dst;
    if (_Dst != (void *)0x0) {
      memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)(ushort)param_2[1]);
      *(undefined2 *)(lVar2 + 0x40) = *param_2;
      *(undefined2 *)(lVar2 + 0x42) = param_2[1];
      goto LAB_140002c3a;
    }
LAB_140002d19:
    ExFreePoolWithTag(lVar2,0);
    iVar1 = -0x3fffff66;
  }
  return iVar1;
}



===== TdiRegisterDeviceObject @ 140002d90 =====

int TdiRegisterDeviceObject(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
                    /* 0x2d90  52  TdiRegisterDeviceObject */
  lVar2 = ExAllocatePool2(0x40,0x88,0x63494454);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    lVar3 = ExAllocatePool2(0x40,*(undefined2 *)(param_1 + 2),0x64494454);
    if (lVar3 == 0) {
      ExFreePoolWithTag(lVar2,0);
      iVar1 = -0x3fffff66;
    }
    else {
      *(undefined1 *)(lVar2 + 0x10) = 0;
      *(undefined2 *)(lVar2 + 0x7a) = *(undefined2 *)(param_1 + 2);
      *(longlong *)(lVar2 + 0x80) = lVar3;
      RtlCopyUnicodeString(lVar2 + 0x78,param_1);
      *param_2 = lVar2;
      iVar1 = TdiHandleSerializedRequest(lVar2,0xd);
      if (iVar1 != 0) {
        ExFreePoolWithTag(lVar3,0);
        ExFreePoolWithTag(lVar2,0);
        *param_2 = 0;
      }
    }
  }
  return iVar1;
}



===== TdiPnPHandler @ 140002ea0 =====

undefined4
TdiPnPHandler(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x6b494454);
  if (puVar2 == (undefined8 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    *puVar2 = param_1;
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    puVar2[3] = param_4;
    *(undefined4 *)(puVar2 + 4) = param_5;
    *(undefined4 *)((longlong)puVar2 + 0x24) = param_6;
    uVar1 = TdiHandleSerializedRequest((longlong)puVar2,0xf);
    ExFreePoolWithTag(puVar2,0);
  }
  return uVar1;
}



===== TdiDeregisterDeviceObject @ 140002f50 =====

void TdiDeregisterDeviceObject(longlong param_1)

{
                    /* 0x2f50  36  TdiDeregisterDeviceObject */
  TdiHandleSerializedRequest(param_1,0xe);
  return;
}



===== TdiPnPPowerRequest @ 140002f70 =====

int TdiPnPPowerRequest(longlong param_1,longlong param_2,ushort *param_3,ushort *param_4,
                      undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  ushort *puVar5;
  longlong lVar6;
  
                    /* 0x2f70  49  TdiPnPPowerRequest */
  lVar3 = ExAllocatePool2(0x40,0x88,0x68494454);
  if (lVar3 == 0) {
    return -0x3fffff66;
  }
  lVar4 = ExAllocatePool2(0x40,*(undefined2 *)(param_1 + 2),0x69494454);
  if (lVar4 != 0) {
    *(undefined1 *)(lVar3 + 0x10) = 2;
    *(undefined2 *)(lVar3 + 0x7a) = *(undefined2 *)(param_1 + 2);
    *(undefined8 *)(lVar3 + 0x30) = param_5;
    *(longlong *)(lVar3 + 0x80) = lVar4;
    lVar6 = *(longlong *)(param_2 + 0x58);
    if (lVar6 == 0) {
      *(longlong *)(param_2 + 0x58) = lVar3;
    }
    else {
      for (lVar1 = *(longlong *)(lVar6 + 0x68); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x68)) {
        lVar6 = lVar1;
      }
      *(longlong *)(lVar6 + 0x68) = lVar3;
    }
    *(longlong *)(lVar3 + 0x28) = param_2;
    *(undefined8 *)(lVar3 + 0x68) = 0;
    *(undefined4 *)(lVar3 + 0x38) = 0;
    if (param_3 == (ushort *)0x0) {
      *(undefined8 *)(lVar3 + 0x50) = 0;
    }
    else {
      puVar5 = (ushort *)ExAllocatePool2(0x40,(ulonglong)*param_3 + 8,0x78494454);
      *(ushort **)(lVar3 + 0x50) = puVar5;
      if (puVar5 == (ushort *)0x0) {
        if (lVar6 != 0) {
          *(undefined8 *)(lVar6 + 0x68) = 0;
        }
        ExFreePoolWithTag(lVar3,0);
        goto LAB_1400031de;
      }
      *puVar5 = *param_3;
      *(ushort *)(*(longlong *)(lVar3 + 0x50) + 2) = param_3[1];
      memmove((void *)(*(longlong *)(lVar3 + 0x50) + 8),param_3 + 4,(ulonglong)*param_3);
    }
    if (param_4 == (ushort *)0x0) {
      *(undefined8 *)(lVar3 + 0x58) = 0;
LAB_140003043:
      RtlCopyUnicodeString(lVar3 + 0x78,param_1);
      iVar2 = TdiHandleSerializedRequest(lVar3,10);
      if (iVar2 != 0x103) {
        iVar2 = *(int *)(lVar3 + 0x38);
        ExFreePoolWithTag(lVar4,0);
        if (*(longlong *)(lVar3 + 0x50) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar3 + 0x50),0);
          *(undefined8 *)(lVar3 + 0x50) = 0;
        }
        if (*(longlong *)(lVar3 + 0x58) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar3 + 0x58),0);
          *(undefined8 *)(lVar3 + 0x58) = 0;
        }
        if (lVar6 != 0) {
          *(undefined8 *)(lVar6 + 0x68) = 0;
        }
        ExFreePoolWithTag(lVar3,0);
      }
      return iVar2;
    }
    puVar5 = (ushort *)ExAllocatePool2(0x40,(ulonglong)*param_4 + 8,0x79494454);
    *(ushort **)(lVar3 + 0x58) = puVar5;
    if (puVar5 != (ushort *)0x0) {
      *puVar5 = *param_4;
      *(ushort *)(*(longlong *)(lVar3 + 0x58) + 2) = param_4[1];
      memmove((void *)(*(longlong *)(lVar3 + 0x58) + 8),param_4 + 4,(ulonglong)*param_4);
      goto LAB_140003043;
    }
    ExFreePoolWithTag(lVar4,0);
    if (*(longlong *)(lVar3 + 0x50) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar3 + 0x50),0);
    }
    if (lVar6 != 0) {
      *(undefined8 *)(lVar6 + 0x68) = 0;
    }
  }
  lVar4 = lVar3;
LAB_1400031de:
  ExFreePoolWithTag(lVar4,0);
  return -0x3fffff66;
}



===== TdiDeregisterNetAddress @ 140003270 =====

void TdiDeregisterNetAddress(longlong param_1)

{
                    /* 0x3270  37  TdiDeregisterNetAddress */
  TdiHandleSerializedRequest(param_1,0xc);
  return;
}



===== TdiHandleSerializedRequest @ 140003290 =====

undefined4 TdiHandleSerializedRequest(longlong param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  void *pvVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong local_res18;
  longlong local_res20;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res18 = 0;
  local_res20 = 0;
  RtlGetCallersAddress(&local_res18,&local_res20);
  pvVar4 = SystemReserved1[0xf];
  if (param_2 == 9) {
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar8[6] = 0;
    plVar8[7] = 0;
    *(undefined4 *)((longlong)plVar8 + 0x4c) = 0;
    plVar8[0xb] = 0;
  }
  else {
    plVar8 = (longlong *)ExAllocatePool2(0x40,0x88,0x61494454);
    if (plVar8 == (longlong *)0x0) {
      return 0xc000009a;
    }
  }
  plVar8[8] = param_1;
  plVar8[3] = (longlong)&PnpHandlerClientList;
  plVar8[4] = (longlong)&PnpHandlerProviderList;
  plVar8[5] = (longlong)&PnpHandlerRequestList;
  plVar8[0xc] = (longlong)&PnpHandlerRequestThread;
  *(int *)(plVar8 + 9) = param_2;
  plVar8[10] = 0;
  *(undefined4 *)(plVar8 + 2) = 0x1234cdef;
  plVar8[0xd] = local_res18;
  plVar8[0xe] = local_res20;
  plVar8[0xf] = (longlong)pvVar4;
  if (param_2 == 0xf) {
    plVar9 = (longlong *)ExAllocatePool2(0x40,0x98,0x70494454);
    if (plVar9 != (longlong *)0x0) {
      lVar10 = ExAllocatePool2(0x40,0x88,0x72494454);
      if (lVar10 != 0) {
        plVar9[0xb] = lVar10;
        *(code **)(lVar10 + 0x30) = TdiPnPPowerCompleteHelper;
        *(undefined4 *)(lVar10 + 0x60) = 1;
        plVar8[0x10] = (longlong)plVar9;
        goto LAB_140003362;
      }
      ExFreePoolWithTag(plVar8,0);
      plVar8 = plVar9;
    }
    ExFreePoolWithTag(plVar8,0);
    uVar7 = 0xc000009a;
  }
  else {
LAB_140003362:
    uVar5 = KeAcquireSpinLockRaiseToDpc(&TDIListLock);
    iVar3 = PnpExclusiveRequestsInQueue;
    iVar1 = (int)plVar8[9];
    if ((iVar1 != 10) && (iVar1 != 0xf)) {
      PnpExclusiveRequestsInQueue = PnpExclusiveRequestsInQueue + 1;
    }
    iVar6 = PnpRequestsInQueue + 1;
    if ((PnpRequestsInQueue == 0) || ((iVar3 == 0 && (param_2 == 10)))) {
      PnpRequestsExecuting = PnpRequestsExecuting + 1;
      PnpRequestsInQueue = iVar6;
      KeReleaseSpinLock(&TDIListLock);
      uVar7 = TdiExecuteRequest(plVar8,'\0');
    }
    else if ((iVar1 == 9) || (iVar1 == 0xf)) {
      if (PnpHandlerRequestThread == SystemReserved1[0xf]) {
        PnpRequestsInQueue = iVar6;
        KeReleaseSpinLock(&TDIListLock,uVar5);
        if ((int)plVar8[9] != 9) {
          ExFreePoolWithTag(plVar8,0);
        }
        uVar7 = 0xc00000bf;
      }
      else {
        local_28 = 0;
        local_38 = 0;
        uStack_30 = 0;
        PnpRequestsInQueue = iVar6;
        KeInitializeEvent(&local_38,1,0);
        plVar8[10] = (longlong)&local_38;
        lVar10 = plVar8[5];
        plVar9 = *(longlong **)(lVar10 + 8);
        if (*plVar9 != lVar10) goto LAB_1400035f9;
        plVar8[1] = (longlong)plVar9;
        *plVar8 = lVar10;
        *plVar9 = (longlong)plVar8;
        *(longlong **)(lVar10 + 8) = plVar8;
        KeReleaseSpinLock(&TDIListLock,uVar5);
        KeWaitForSingleObject(&local_38,6,0,0,0);
        uVar7 = 0;
      }
    }
    else {
      lVar10 = plVar8[5];
      plVar9 = *(longlong **)(lVar10 + 8);
      PnpRequestsInQueue = iVar6;
      if (*plVar9 != lVar10) {
LAB_1400035f9:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        uVar7 = (*pcVar2)();
        return uVar7;
      }
      plVar8[1] = (longlong)plVar9;
      *plVar8 = lVar10;
      *plVar9 = (longlong)plVar8;
      *(longlong **)(lVar10 + 8) = plVar8;
      if ((int)plVar8[9] == 10) {
        *(undefined1 *)(plVar8 + 0xb) = 1;
        KeReleaseSpinLock(&TDIListLock,uVar5);
        uVar7 = 0x103;
      }
      else {
        KeReleaseSpinLock();
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}



===== TdiExecuteRequest @ 140003610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 TdiExecuteRequest(longlong *param_1,char param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  longlong lVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  longlong *plVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong lVar14;
  int iVar15;
  undefined1 *puVar16;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined8 in_stack_ffffffffffffffc8;
  
  do {
    uVar7 = 0xef;
    uVar8 = 0;
    bVar6 = KeAcquireSpinLockRaiseToDpc(&TDIListLock);
    uVar11 = (ulonglong)bVar6;
    if (param_1[10] != 0) {
      *(void **)param_1[0xc] = SystemReserved1[0xf];
    }
    iVar15 = NextExec + 1;
    lVar12 = (longlong)NextExec * 0x20;
    NextExec = iVar15;
    *(longlong **)(&TrackExecs + lVar12) = param_1;
    *(int *)(&DAT_140009248 + lVar12) = (int)param_1[9];
    *(longlong *)(&DAT_140009250 + lVar12) = param_1[8];
    *(longlong *)(&DAT_140009258 + lVar12) = param_1[0xc];
    if (iVar15 == 8) {
      NextExec = 0;
    }
    _DAT_140009348 = SystemReserved1[0xf];
    KeReleaseSpinLock(&TDIListLock,uVar11);
    switch((int)param_1[9]) {
    case 8:
      lVar12 = param_1[3];
      plVar13 = (longlong *)param_1[8];
      plVar9 = *(longlong **)(lVar12 + 8);
      if (*plVar9 == lVar12) {
        *plVar13 = lVar12;
        plVar13[1] = (longlong)plVar9;
        *plVar9 = (longlong)plVar13;
        *(longlong **)(lVar12 + 8) = plVar13;
        TdipGetMultiSZList(plVar13 + 0xb,plVar9,plVar13 + 4,uVar11,in_stack_ffffffffffffffc8,
                           (uint *)(plVar13 + 0xc));
        TdiNotifyNewPnpClient((undefined8 *)param_1[4],param_1[8]);
        break;
      }
      goto LAB_140003bae;
    case 9:
      plVar13 = (longlong *)param_1[8];
      lVar12 = *plVar13;
      if ((*(longlong **)(lVar12 + 8) != plVar13) ||
         (plVar9 = (longlong *)plVar13[1], (longlong *)*plVar9 != plVar13)) goto LAB_140003bae;
      *plVar9 = lVar12;
      *(longlong **)(lVar12 + 8) = plVar9;
      *plVar13 = 0xabababab;
      plVar13[1] = 0xefefefef;
      lVar12 = param_1[8];
      lVar10 = *(longlong *)(lVar12 + 0x28);
      if (lVar10 != 0) {
        ExFreePoolWithTag(lVar10,0);
      }
      lVar12 = *(longlong *)(lVar12 + 0x58);
      if (lVar12 != 0) {
        ExFreePoolWithTag(lVar12,0);
      }
      goto LAB_1400037bd;
    case 10:
      lVar12 = param_1[8];
      *(undefined4 *)(lVar12 + 0x60) = 1;
      plVar13 = (longlong *)param_1[3];
      plVar9 = (longlong *)*plVar13;
      if (plVar9 != plVar13) {
        do {
          if (plVar9[10] != 0) {
            *(int *)(lVar12 + 0x60) = *(int *)(lVar12 + 0x60) + 1;
          }
          plVar9 = (longlong *)*plVar9;
          plVar13 = (longlong *)param_1[3];
        } while (plVar9 != plVar13);
      }
      uVar8 = TdiNotifyPnpClientList(plVar13,param_1[8],'\0');
      LOCK();
      piVar1 = (int *)(lVar12 + 0x60);
      iVar15 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar15 == 1) {
        lVar10 = *(longlong *)(lVar12 + 0x28);
        uVar8 = *(undefined4 *)(lVar12 + 0x38);
        lVar14 = *(longlong *)(*(longlong *)(lVar10 + 0x58) + 0x68);
        lVar5 = *(longlong *)(lVar10 + 0x58);
        if (lVar14 == 0) {
          *(undefined8 *)(lVar10 + 0x58) = 0;
          *(undefined8 *)(lVar10 + 0x60) = 0;
          *(undefined8 *)(lVar10 + 0x68) = 0;
          *(undefined8 *)(lVar10 + 0x70) = 0;
        }
        else {
          do {
            lVar10 = lVar5;
            plVar13 = (longlong *)(lVar14 + 0x68);
            lVar5 = lVar14;
            lVar14 = *plVar13;
          } while (*plVar13 != 0);
          *(undefined8 *)(lVar10 + 0x68) = 0;
        }
        if (((char)param_1[0xb] != '\0') && (*(code **)(lVar12 + 0x30) != (code *)0x0)) {
          (**(code **)(lVar12 + 0x30))
                    (*(undefined8 *)(lVar12 + 0x28),*(undefined4 *)(lVar12 + 0x38));
          uVar11 = Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar11 != 0) {
            if (*(longlong *)(lVar12 + 0x80) != 0) {
              ExFreePoolWithTag(*(longlong *)(lVar12 + 0x80),0);
              *(undefined8 *)(lVar12 + 0x80) = 0;
            }
            if (*(longlong *)(lVar12 + 0x50) != 0) {
              ExFreePoolWithTag(*(longlong *)(lVar12 + 0x50),0);
              *(undefined8 *)(lVar12 + 0x50) = 0;
            }
            if (*(longlong *)(lVar12 + 0x58) != 0) {
              ExFreePoolWithTag(*(longlong *)(lVar12 + 0x58),0);
              *(undefined8 *)(lVar12 + 0x58) = 0;
            }
          }
        }
      }
      break;
    case 0xb:
    case 0xd:
      goto switchD_14000370e_caseD_b;
    case 0xc:
    case 0xe:
      goto switchD_14000370e_caseD_c;
    case 0xf:
      TdiHandlePnpOperation
                ((undefined8 *)param_1[3],(undefined8 *)param_1[8],(undefined4 *)param_1[0x10],
                 uVar11);
      break;
    case 0x10:
      puVar2 = (undefined8 *)param_1[4];
      lVar12 = param_1[8];
      for (puVar3 = (undefined8 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined8 *)*puVar3) {
        if ((*(char *)(puVar3 + 2) == '\x01') && (*(code **)(lVar12 + 0x40) != (code *)0x0)) {
          (**(code **)(lVar12 + 0x40))(puVar3 + 0xf,puVar3 + 8,puVar3[0xb]);
        }
      }
      break;
    case 0x11:
      LOCK();
      ProvidersRegistered = ProvidersRegistered + 1;
      UNLOCK();
switchD_14000370e_caseD_b:
      lVar12 = param_1[4];
      plVar13 = (longlong *)param_1[8];
      plVar9 = *(longlong **)(lVar12 + 8);
      if (*plVar9 == lVar12) {
        *plVar13 = lVar12;
        plVar13[1] = (longlong)plVar9;
        *plVar9 = (longlong)plVar13;
        *(longlong **)(lVar12 + 8) = plVar13;
LAB_140003a2f:
        TdiNotifyPnpClientList((undefined8 *)param_1[3],param_1[8],'\x01');
        break;
      }
      goto LAB_140003bae;
    case 0x12:
      LOCK();
      ProvidersRegistered = ProvidersRegistered + -1;
      UNLOCK();
switchD_14000370e_caseD_c:
      plVar13 = (longlong *)param_1[8];
      lVar12 = *plVar13;
      if ((*(longlong **)(lVar12 + 8) == plVar13) &&
         (plVar9 = (longlong *)plVar13[1], (longlong *)*plVar9 == plVar13)) {
        *plVar9 = lVar12;
        *(longlong **)(lVar12 + 8) = plVar9;
        *plVar13 = 0xabababab;
        plVar13[1] = 0xefefefef;
        if ((int)param_1[9] == 0x12) {
          if (*(int *)((longlong)plVar13 + 100) != 0) {
            LOCK();
            ProvidersReady = ProvidersReady + -1;
            UNLOCK();
          }
        }
        else {
          TdiNotifyPnpClientList((undefined8 *)param_1[3],param_1[8],'\0');
        }
        if ((int)param_1[9] == 0xe) {
          ExFreePoolWithTag(plVar13[0x10],0);
        }
        if (plVar13[9] != 0) {
          ExFreePoolWithTag(plVar13[9],0);
          plVar13[9] = 0;
          *(undefined4 *)(plVar13 + 8) = 0;
        }
        if (plVar13[0xb] != 0) {
          ExFreePoolWithTag(plVar13[0xb],0);
          plVar13[0xb] = 0;
        }
LAB_1400037bd:
        ExFreePoolWithTag(plVar13,0);
        break;
      }
      goto LAB_140003bae;
    case 0x13:
      LOCK();
      ProvidersReady = ProvidersReady + 1;
      UNLOCK();
      *(undefined4 *)(param_1[8] + 100) = 1;
      goto LAB_140003a2f;
    }
    if (param_1[10] != 0) {
      *(undefined8 *)param_1[0xc] = 0;
      KeSetEvent(param_1[10],0,0);
    }
    uVar7 = KeAcquireSpinLockRaiseToDpc(&TDIListLock);
    iVar15 = NextExecComplete + 1;
    lVar12 = (longlong)NextExecComplete * 0x20;
    NextExecComplete = iVar15;
    *(longlong **)(&TrackExecCompletes + lVar12) = param_1;
    *(int *)(&DAT_140009148 + lVar12) = (int)param_1[9];
    *(longlong *)(&DAT_140009150 + lVar12) = param_1[8];
    *(longlong *)(&DAT_140009158 + lVar12) = param_1[0xc];
    if (iVar15 == 8) {
      NextExecComplete = 0;
    }
    PnpRequestsExecuting = PnpRequestsExecuting + -1;
    PnpRequestsInQueue = PnpRequestsInQueue + -1;
    _DAT_140009348 = (void *)0x0;
    plVar13 = (longlong *)param_1[5];
    plVar9 = (longlong *)*plVar13;
    if (((int)param_1[9] != 10) && ((int)param_1[9] != 0xf)) {
      PnpExclusiveRequestsInQueue = PnpExclusiveRequestsInQueue + -1;
    }
    ExFreePoolWithTag(param_1,0);
    puVar16 = auStackY_58;
    if ((plVar9 == plVar13) || (puVar16 = auStackY_58, PnpRequestsExecuting != 0)) {
LAB_140003bb5:
      if (param_2 != '\0') {
        PnpWorkerThreadActive = '\0';
      }
      goto LAB_140003bc1;
    }
    if ((param_2 == '\0') && (puVar16 = auStackY_58, PnpWorkerThreadActive != '\0'))
    goto LAB_140003bc1;
    param_1 = (longlong *)*plVar13;
    PnpRequestsExecuting = 1;
    if (((longlong *)param_1[1] != plVar13) ||
       (lVar12 = *param_1, *(longlong **)(lVar12 + 8) != param_1)) {
LAB_140003bae:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar16 = auStackY_50;
      goto LAB_140003bb5;
    }
    *plVar13 = lVar12;
    *(longlong **)(lVar12 + 8) = plVar13;
    if (param_2 == '\0') {
      _DAT_140009130 = TdiExecuteRequestWrapper;
      _PnpTdiWorkItem = 0;
      _DAT_140009138 = param_1;
      ExQueueWorkItem(&PnpTdiWorkItem,1);
      PnpWorkerThreadActive = '\x01';
      puVar16 = auStackY_58;
LAB_140003bc1:
      *(undefined8 *)(puVar16 + -8) = 0x140003bd3;
      KeReleaseSpinLock(&TDIListLock,uVar7);
      return uVar8;
    }
    KeReleaseSpinLock(&TDIListLock,uVar7);
  } while( true );
}



===== TdiCopyMdlToBuffer @ 140003c00 =====

uint TdiCopyMdlToBuffer(longlong *param_1,uint param_2,longlong param_3,uint param_4,int param_5,
                       int *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *_Dst;
  void *_Src;
  
                    /* 0x3c00  24  TdiCopyMdlToBuffer */
  uVar2 = 0;
  *param_6 = 0;
  if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
    _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
  }
  else {
    _Src = (void *)param_1[3];
  }
  while( true ) {
    if (_Src == (void *)0x0) {
      return 0xc000009a;
    }
    uVar3 = *(uint *)(param_1 + 5);
    if (param_2 <= uVar2) break;
    uVar1 = param_2 - uVar2;
    if (uVar1 < uVar3) {
      uVar3 = uVar3 + (uVar2 - param_2);
      _Src = (void *)((longlong)_Src + (ulonglong)uVar1);
      break;
    }
    param_1 = (longlong *)*param_1;
    if (uVar3 == uVar1) {
      if (param_1 == (longlong *)0x0) {
        return 0;
      }
      if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
        _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
      }
      else {
        _Src = (void *)param_1[3];
      }
      if (_Src == (void *)0x0) {
        return 0xc000009a;
      }
      uVar3 = *(uint *)(param_1 + 5);
      break;
    }
    uVar2 = uVar2 + uVar3;
    if (param_1 == (longlong *)0x0) {
      return 0;
    }
    if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
      _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
    }
    else {
      _Src = (void *)param_1[3];
    }
  }
  _Dst = (void *)((ulonglong)param_4 + param_3);
  uVar2 = param_5 - param_4;
  while( true ) {
    while( true ) {
      if (uVar2 == 0) {
        return -(uint)(param_1 != (longlong *)0x0) & 0x80000005;
      }
      if (uVar3 == 0) break;
      if (uVar2 == uVar3) {
        memmove(_Dst,_Src,(ulonglong)uVar2);
        *param_6 = *param_6 + uVar2;
        return 0;
      }
      if (uVar2 < uVar3) {
        memmove(_Dst,_Src,(ulonglong)uVar2);
        *param_6 = *param_6 + uVar2;
        return 0x80000005;
      }
      memmove(_Dst,_Src,(ulonglong)uVar3);
      *param_6 = *param_6 + uVar3;
      uVar2 = uVar2 - uVar3;
      _Dst = (void *)((longlong)_Dst + (ulonglong)uVar3);
      uVar3 = 0;
    }
    param_1 = (longlong *)*param_1;
    if (param_1 == (longlong *)0x0) {
      return 0;
    }
    if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
      _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
    }
    else {
      _Src = (void *)param_1[3];
    }
    if (_Src == (void *)0x0) break;
    uVar3 = *(uint *)(param_1 + 5);
  }
  return 0xc000009a;
}



===== TdiOpenNetbiosAddress @ 140003e40 =====

ulonglong TdiOpenNetbiosAddress
                    (undefined8 param_1,undefined4 *param_2,undefined8 param_3,
                    undefined1 (*param_4) [16])

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  ulonglong local_68 [5];
  undefined2 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x3e40  47  TdiOpenNetbiosAddress */
  local_68[0] = 0;
  local_68[1] = 0;
  local_34 = 0;
  local_1c = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  if (param_4 == (undefined1 (*) [16])0x0) {
    param_2 = (undefined4 *)0x0;
    uVar3 = 0;
  }
  else {
    uVar3 = 0x33;
    if (param_2 == (undefined4 *)0x0) {
      return 0xc0000001;
    }
    *param_2 = 0;
    param_2[1] = 0x1a1000;
    builtin_strncpy((char *)(param_2 + 2),"Transpor",8);
    builtin_strncpy((char *)(param_2 + 4),"tAddress",8);
    *(undefined1 *)(param_2 + 6) = 0;
    local_68[2] = 0x11001200000001;
    local_68[4] = *(ulonglong *)(*param_4 + 6);
    uStack_40 = *(undefined2 *)(*param_4 + 0xe);
    local_68[3] = (ulonglong)*(uint6 *)*param_4 << 0x10;
    puVar1 = (undefined8 *)((ulonglong)*(byte *)((longlong)param_2 + 5) + 9 + (longlong)param_2);
    *puVar1 = 0x11001200000001;
    puVar1[1] = local_68[3];
    puVar1[2] = local_68[4];
    *(undefined2 *)(puVar1 + 3) = uStack_40;
  }
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_3;
  uVar2 = NtCreateFile(param_1,0x180,&local_38,local_68,0,0,3,2,0,param_2,uVar3);
  if (-1 < (int)uVar2) {
    uVar2 = local_68[0] & 0xffffffff;
  }
  return uVar2;
}



===== CTEScheduleDelayedEvent @ 140003fc0 =====

undefined8 CTEScheduleDelayedEvent(int *param_1,undefined8 param_2)

{
  undefined1 uVar1;
  
                    /* 0x3fc0  12  CTEScheduleDelayedEvent
                       0x3fc0  13  CTEScheduleEvent */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  if (*param_1 == 0) {
    *param_1 = 1;
    *(undefined8 *)(param_1 + 6) = param_2;
    ExQueueWorkItem(param_1 + 8,1);
  }
  KeReleaseSpinLock(param_1 + 2,uVar1);
  return 1;
}



===== TdiGet9FTriageBlock @ 140004050 =====

void TdiGet9FTriageBlock(undefined8 *param_1)

{
                    /* 0x4050  42  TdiGet9FTriageBlock */
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = &TdiGlobalTriageBlock;
  }
  return;
}



===== TdiRegisterProvider @ 140004070 =====

int TdiRegisterProvider(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
                    /* 0x4070  56  TdiRegisterProvider */
  lVar2 = ExAllocatePool2(0x40,0x88,0x63494454);
  if (lVar2 == 0) {
    return -0x3fffff66;
  }
  lVar3 = ExAllocatePool2(0x40,*(undefined2 *)(param_1 + 2),0x64494454);
  if (lVar3 == 0) {
    ExFreePoolWithTag(lVar2,0);
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined1 *)(lVar2 + 0x10) = 3;
    *(undefined2 *)(lVar2 + 0x7a) = *(undefined2 *)(param_1 + 2);
    *(longlong *)(lVar2 + 0x80) = lVar3;
    RtlCopyUnicodeString(lVar2 + 0x78,param_1);
    *param_2 = lVar2;
    *(undefined8 *)(lVar2 + 0x50) = 0;
    *(undefined8 *)(lVar2 + 0x58) = 0;
    iVar1 = TdiHandleSerializedRequest(lVar2,0x11);
    if (iVar1 != 0) {
      ExFreePoolWithTag(lVar3,0);
      ExFreePoolWithTag(lVar2,0);
      *param_2 = 0;
    }
  }
  return iVar1;
}



===== CTEpTimerHandler @ 140004190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CTEpTimerHandler(undefined8 param_1,longlong param_2)

{
  (**(code **)(param_2 + 0x10))(param_2,*(undefined8 *)(param_2 + 0x18));
  return;
}



===== TdipRemoveMultiSzFromMultiSz @ 1400041b0 =====

void TdipRemoveMultiSzFromMultiSz(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  ulonglong uVar7;
  ulonglong uVar6;
  
  if (((param_2 != (wchar_t *)0x0) && (param_1 != (wchar_t *)0x0)) && (*param_1 != L'\0')) {
    wVar1 = *param_2;
    while (wVar1 != L'\0') {
      for (pwVar5 = param_1; *pwVar5 != L'\0'; pwVar5 = pwVar5 + ((int)uVar7 + 2)) {
        uVar6 = 0xffffffffffffffff;
        do {
          uVar7 = uVar6;
          uVar6 = uVar7 + 1;
        } while (pwVar5[uVar6] != L'\0');
        iVar3 = _wcsicmp(param_2,pwVar5);
        if (iVar3 == 0) {
          pwVar5 = param_2 + (uVar6 & 0xffffffff) + 1;
          iVar3 = TdipCbOfMultiSzSafe(pwVar5);
          memmove(param_2,pwVar5,(longlong)(iVar3 + 2));
          goto LAB_140004265;
        }
      }
      lVar2 = -1;
      do {
        lVar4 = lVar2;
        lVar2 = lVar4 + 1;
      } while (param_2[lVar4 + 1] != L'\0');
      param_2 = param_2 + lVar4 + 2;
LAB_140004265:
      wVar1 = *param_2;
    }
  }
  return;
}



===== __report_gsfailure @ 1400042a0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400042ad =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400042ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== CTEAllocateString @ 1400042c0 =====

undefined1 CTEAllocateString(undefined2 *param_1,ushort param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  
                    /* 0x42c0  1  CTEAllocateString */
  lVar2 = ExAllocatePool2(0x40,(ulonglong)param_2 + 2,0x6c494454);
  uVar1 = (undefined1)lVar2;
  *(longlong *)(param_1 + 4) = lVar2;
  if (lVar2 != 0) {
    *param_1 = 0;
    param_1[1] = param_2 + 2;
    uVar1 = 1;
  }
  return uVar1;
}



===== CTEBlock @ 140004330 =====

int CTEBlock(int *param_1)

{
  int iVar1;
  
                    /* 0x4330  2  CTEBlock */
  iVar1 = KeWaitForSingleObject(param_1 + 2,6,0,0,0);
  if (iVar1 < 0) {
    *param_1 = iVar1;
  }
  return *param_1;
}



===== CTEBlockWithTracker @ 140004370 =====

int CTEBlockWithTracker(int *param_1,longlong *param_2,undefined8 param_3)

{
  int iVar1;
  
                    /* 0x4370  3  CTEBlockWithTracker */
  CTEInsertBlockTracker(param_2,param_3);
  iVar1 = CTEBlock(param_1);
  CTERemoveBlockTracker(param_2);
  return iVar1;
}



===== CTEInitEvent @ 1400043c0 =====

void CTEInitEvent(undefined4 *param_1,undefined8 param_2)

{
                    /* 0x43c0  4  CTEInitEvent */
  *param_1 = 0;
  *(undefined8 *)(param_1 + 4) = param_2;
  KeInitializeSpinLock(param_1 + 2);
  *(undefined8 *)(param_1 + 8) = 0;
  *(code **)(param_1 + 0xc) = CTEpEventHandler;
  *(undefined4 **)(param_1 + 0xe) = param_1;
  return;
}



===== CTEInitString @ 140004410 =====

bool CTEInitString(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x4410  5  CTEInitString */
  local_18 = 0;
  uStack_10 = 0;
  RtlInitString(&local_18);
  iVar1 = RtlxAnsiStringToUnicodeSize(&local_18);
  lVar2 = ExAllocatePool2(0x40,iVar1 + 2,0x6c494454);
  *(longlong *)(param_1 + 8) = lVar2;
  if (lVar2 != 0) {
    *(short *)(param_1 + 2) = (short)(iVar1 + 2);
    RtlAnsiStringToUnicodeString(param_1,&local_18,0);
  }
  else {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  return lVar2 != 0;
}



===== CTEInitTimer @ 1400044b0 =====

void CTEInitTimer(longlong param_1)

{
                    /* 0x44b0  6  CTEInitTimer */
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  KeInitializeDpc(param_1 + 0x20,CTEpTimerHandler,param_1);
  KeInitializeTimer(param_1 + 0x60);
  return;
}



===== CTEInitialize @ 140004500 =====

undefined8 CTEInitialize(void)

{
                    /* 0x4500  7  CTEInitialize */
  return 1;
}



===== CTEInsertBlockTracker @ 140004510 =====

void CTEInsertBlockTracker(undefined8 *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x4510  8  CTEInsertBlockTracker */
  param_1[2] = SystemReserved1[0xf];
  param_1[3] = param_2;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&CTEBlockSpinLock);
  puVar5 = auStack_28;
  puVar4 = &CTEBlockListHead;
  puVar3 = DAT_1400093a8;
  if ((undefined *)*DAT_1400093a8 != &CTEBlockListHead) {
    puVar3 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar5 = auStack_20;
  }
  *param_1 = puVar4;
  param_1[1] = puVar3;
  *puVar3 = param_1;
  *(undefined8 *)(puVar5 + -8) = 0x140004578;
  DAT_1400093a8 = param_1;
  KeReleaseSpinLock(&CTEBlockSpinLock,uVar2);
  return;
}



===== CTERemoveBlockTracker @ 140004590 =====

void CTERemoveBlockTracker(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  
                    /* 0x4590  10  CTERemoveBlockTracker */
  uVar4 = KeAcquireSpinLockRaiseToDpc(&CTEBlockSpinLock);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseSpinLock(&CTEBlockSpinLock,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4));
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== CTEScheduleCriticalEvent @ 1400045f0 =====

undefined8 CTEScheduleCriticalEvent(int *param_1,undefined8 param_2)

{
  undefined1 uVar1;
  
                    /* 0x45f0  11  CTEScheduleCriticalEvent */
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  if (*param_1 == 0) {
    *param_1 = 1;
    *(undefined8 *)(param_1 + 6) = param_2;
    ExQueueWorkItem(param_1 + 8,0);
  }
  KeReleaseSpinLock(param_1 + 2,uVar1);
  return 1;
}



===== CTESignal @ 140004680 =====

void CTESignal(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x4680  14  CTESignal */
  *param_1 = param_2;
  KeSetEvent(param_1 + 2,0,0);
  return;
}



===== CTEStartTimer @ 1400046b0 =====

undefined8 CTEStartTimer(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x46b0  15  CTEStartTimer */
  *(undefined8 *)(param_1 + 0x10) = param_3;
  *(undefined8 *)(param_1 + 0x18) = param_4;
  KeSetTimer(param_1 + 0x60,(ulonglong)param_2 * -10000,param_1 + 0x20);
  return 1;
}



===== CTESystemUpTime @ 140004700 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CTESystemUpTime(void)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulonglong uVar3;
  ulonglong uVar4;
  
                    /* 0x4700  16  CTESystemUpTime */
  uVar3 = CTEpTimeIncrement * _DAT_fffff78000000320;
  if ((longlong)uVar3 < 0) {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = -uVar3;
    uVar4 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar2,8);
  }
  else {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    uVar4 = SUB168(ZEXT816(0xd1b71758e219652c) * auVar1,8);
  }
  uVar4 = uVar4 >> 0xd;
  if ((longlong)uVar3 < 0) {
    uVar4 = -uVar4;
  }
  return uVar4 & 0xffffffff;
}



===== CTEpEventHandler @ 140004750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CTEpEventHandler(undefined4 *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
  pcVar1 = *(code **)(param_1 + 4);
  uVar2 = *(undefined8 *)(param_1 + 6);
  *param_1 = 0;
  KeReleaseSpinLock(param_1 + 2,uVar3);
  (*pcVar1)(param_1,uVar2);
  return;
}



===== CTEpInitialize @ 1400047c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CTEpInitialize(void)

{
  CTEpTimeIncrement = KeQueryTimeIncrement();
  KeInitializeSpinLock(&CTEBlockSpinLock);
  DAT_1400093a8 = &CTEBlockListHead;
  _CTEBlockListHead = &CTEBlockListHead;
  return;
}



===== DllInitialize @ 140004810 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(void)

{
  int iVar1;
  undefined8 uVar2;
  
                    /* 0x4810  17  DllInitialize */
  __security_init_cookie();
  iVar1 = wil_InitializeFeatureStaging();
  if (iVar1 < 0) {
    uVar2 = 0xc0000002;
  }
  else {
    KeInitializeSpinLock(&TDIListLock);
    _DAT_140009378 = &PnpHandlerClientList;
    _PnpHandlerClientList = &PnpHandlerClientList;
    _DAT_140009358 = &PnpHandlerProviderList;
    PnpHandlerProviderList = &PnpHandlerProviderList;
    DAT_140009368 = &PnpHandlerRequestList;
    _PnpHandlerRequestList = &PnpHandlerRequestList;
    CTEpInitialize();
    KeInitializeSpinLock(&TdiMappingAddressLock);
    TdiMappingAddress = MmAllocateMappingAddress(0x1000,0x6d494454);
    if (TdiMappingAddress == 0) {
      wil_UninitializeFeatureStaging();
      uVar2 = 0xc000009a;
    }
    else {
      NdisRegisterTdiCallBack(TdiRegisterDeviceObject,TdiPnPHandler);
      _DAT_140009348 = 0;
      uVar2 = 0;
      _TdiGlobalTriageBlock = 0xefcdbaef;
      _DAT_140009344 = 0x100001;
    }
  }
  return uVar2;
}



===== DllUnload @ 140004910 =====

undefined8 DllUnload(void)

{
                    /* 0x4910  18  DllUnload */
  NdisDeregisterTdiCallBack();
  if (TdiMappingAddress != 0) {
    MmFreeMappingAddress(TdiMappingAddress,0x6d494454);
    TdiMappingAddress = 0;
  }
  wil_UninitializeFeatureStaging();
  return 0;
}



===== TdiDefaultDisconnectHandler @ 140004960 =====

undefined8 TdiDefaultDisconnectHandler(void)

{
                    /* 0x4960  29  TdiDefaultDisconnectHandler
                       0x4960  30  TdiDefaultErrorHandler
                       0x4960  34  TdiDefaultSendPossibleHandler */
  return 0;
}



===== TdiBuildNetbiosAddress @ 140004970 =====

void TdiBuildNetbiosAddress(undefined8 *param_1,char param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
                    /* 0x4970  19  TdiBuildNetbiosAddress */
  *param_3 = 1;
  param_3[1] = 0x110012;
  *(ushort *)(param_3 + 2) = (ushort)(param_2 != '\0');
  uVar1 = param_1[1];
  *(undefined8 *)((longlong)param_3 + 10) = *param_1;
  *(undefined8 *)((longlong)param_3 + 0x12) = uVar1;
  return;
}



===== TdiBuildNetbiosAddressEa @ 1400049a0 =====

undefined8 TdiBuildNetbiosAddressEa(undefined4 *param_1,char param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
                    /* 0x49a0  20  TdiBuildNetbiosAddressEa */
  if (param_1 == (undefined4 *)0x0) {
    return 0xc0000001;
  }
  *param_1 = 0;
  param_1[1] = 0x1a1000;
  builtin_strncpy((char *)(param_1 + 2),"Transpor",8);
  builtin_strncpy((char *)(param_1 + 4),"tAddress",8);
  *(undefined1 *)(param_1 + 6) = 0;
  uVar3 = (ulonglong)*(byte *)((longlong)param_1 + 5);
  *(undefined4 *)(uVar3 + 9 + (longlong)param_1) = 1;
  *(undefined4 *)(uVar3 + 0xd + (longlong)param_1) = 0x110012;
  if (param_2 == '\0') {
    *(undefined2 *)(uVar3 + 0x11 + (longlong)param_1) = 0;
  }
  else {
    *(undefined2 *)(uVar3 + 0x11 + (longlong)param_1) = 1;
  }
  uVar2 = param_3[1];
  puVar1 = (undefined8 *)(uVar3 + 0x13 + (longlong)param_1);
  *puVar1 = *param_3;
  puVar1[1] = uVar2;
  return 0;
}



===== TdiCopyBufferToMdlWithReservedMappingAtDpcLevel @ 140004a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TdiCopyBufferToMdlWithReservedMappingAtDpcLevel
               (void *param_1,longlong param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_148 [32];
  undefined8 local_128;
  uint local_120;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  ulonglong local_48;
  
                    /* 0x4a10  22  TdiCopyBufferToMdlWithReservedMappingAtDpcLevel */
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  local_120 = 0x38;
  local_100 = 0x1000;
  local_128 = 0;
  local_108 = 0;
  KeAcquireSpinLockAtDpcLevel(&TdiMappingAddressLock);
  uVar3 = param_4 + param_3;
  while (param_3 < uVar3) {
    uVar1 = *(uint *)(param_2 + 0x2c);
    uVar2 = (uVar1 + 0x1000 + param_3 & 0xfffff000) - uVar1;
    uVar4 = uVar3;
    if (uVar2 <= uVar3) {
      uVar4 = uVar2;
    }
    uVar2 = uVar4 - param_3;
    IoBuildPartialMdl(param_2,&local_128,
                      (ulonglong)uVar1 + (ulonglong)param_3 + *(longlong *)(param_2 + 0x20),
                      (ulonglong)uVar2);
    _Dst = (void *)MmMapLockedPagesWithReservedMapping(TdiMappingAddress,0x6d494454,&local_128,1);
    memmove(_Dst,param_1,(ulonglong)uVar2);
    MmUnmapReservedMapping(TdiMappingAddress,0x6d494454,&local_128);
    if ((local_120 & 0x200000) != 0) {
      MmUnmapLockedPages(local_110,&local_128);
    }
    param_1 = (void *)((longlong)param_1 + (ulonglong)uVar2);
    param_3 = uVar4;
  }
  KeReleaseSpinLockFromDpcLevel(&TdiMappingAddressLock);
  return;
}



===== TdiCopyMdlChainToMdlChain @ 140004b80 =====

undefined8
TdiCopyMdlChainToMdlChain
          (longlong *param_1,uint param_2,longlong *param_3,uint param_4,int *param_5)

{
  void *_Dst;
  void *_Src;
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
                    /* 0x4b80  23  TdiCopyMdlChainToMdlChain */
  *param_5 = 0;
  if (param_3 == (longlong *)0x0) {
LAB_140004da3:
    uVar1 = 0x80000005;
  }
  else {
    uVar2 = 0;
    if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) goto LAB_140004bd7;
    _Dst = (void *)param_3[3];
    while (_Dst != (void *)0x0) {
      uVar3 = *(uint *)(param_3 + 5);
      if (param_4 <= uVar2) {
LAB_140004c3e:
        uVar2 = 0;
        if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) goto LAB_140004c58;
        do {
          _Src = (void *)param_1[3];
          while( true ) {
            if (_Src == (void *)0x0) goto LAB_140004d9c;
            uVar4 = *(uint *)(param_1 + 5);
            if (param_2 <= uVar2) goto LAB_140004cbc;
            if (param_2 - uVar2 < uVar4) {
              _Src = (void *)((longlong)_Src + (ulonglong)(param_2 - uVar2));
              uVar4 = uVar4 + (uVar2 - param_2);
              goto LAB_140004cbc;
            }
            param_1 = (longlong *)*param_1;
            uVar2 = uVar2 + uVar4;
            if (param_1 == (longlong *)0x0) goto LAB_140004da3;
            if ((*(byte *)((longlong)param_1 + 10) & 5) != 0) break;
LAB_140004c58:
            _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
          }
        } while( true );
      }
      if (param_4 - uVar2 < uVar3) {
        _Dst = (void *)((longlong)_Dst + (ulonglong)(param_4 - uVar2));
        uVar3 = uVar3 + (uVar2 - param_4);
        goto LAB_140004c3e;
      }
      param_3 = (longlong *)*param_3;
      uVar2 = uVar2 + uVar3;
      if (param_3 == (longlong *)0x0) goto LAB_140004da3;
      if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
LAB_140004bd7:
        _Dst = (void *)MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000010);
      }
      else {
        _Dst = (void *)param_3[3];
      }
    }
LAB_140004d9c:
    uVar1 = 0xc000009a;
  }
  return uVar1;
LAB_140004cbc:
  if (uVar4 == 0) {
    param_1 = (longlong *)*param_1;
    if (param_1 == (longlong *)0x0) {
      return 0;
    }
    if ((*(byte *)((longlong)param_1 + 10) & 5) == 0) {
      _Src = (void *)MmMapLockedPagesSpecifyCache(param_1,0,1,0,0,0x40000010);
    }
    else {
      _Src = (void *)param_1[3];
    }
    if (_Src == (void *)0x0) goto LAB_140004d9c;
    uVar4 = *(uint *)(param_1 + 5);
    goto LAB_140004cbc;
  }
  if (uVar3 != 0) {
    uVar2 = uVar4;
    if (uVar3 <= uVar4) {
      uVar2 = uVar3;
    }
    memmove(_Dst,_Src,(ulonglong)uVar2);
    uVar4 = uVar4 - uVar2;
    _Src = (void *)((longlong)_Src + (ulonglong)uVar2);
    uVar3 = uVar3 - uVar2;
    _Dst = (void *)((longlong)_Dst + (ulonglong)uVar2);
    *param_5 = *param_5 + uVar2;
    goto LAB_140004cbc;
  }
  param_3 = (longlong *)*param_3;
  if (param_3 == (longlong *)0x0) goto LAB_140004da3;
  if ((*(byte *)((longlong)param_3 + 10) & 5) == 0) {
    _Dst = (void *)MmMapLockedPagesSpecifyCache(param_3,0,1,0,0,0x40000010);
  }
  else {
    _Dst = (void *)param_3[3];
  }
  if (_Dst == (void *)0x0) goto LAB_140004da3;
  uVar3 = *(uint *)(param_3 + 5);
  goto LAB_140004cbc;
}



===== TdiDefaultChainedRcvDatagramHandler @ 140004dd0 =====

undefined8 TdiDefaultChainedRcvDatagramHandler(void)

{
                    /* 0x4dd0  25  TdiDefaultChainedRcvDatagramHandler
                       0x4dd0  26  TdiDefaultChainedRcvExpeditedHandler
                       0x4dd0  27  TdiDefaultChainedReceiveHandler
                       0x4dd0  31  TdiDefaultRcvDatagramHandler
                       0x4dd0  32  TdiDefaultRcvExpeditedHandler
                       0x4dd0  33  TdiDefaultReceiveHandler */
  return 0xc000021b;
}



===== TdiDefaultConnectHandler @ 140004de0 =====

undefined8 TdiDefaultConnectHandler(void)

{
                    /* 0x4de0  28  TdiDefaultConnectHandler */
  return 0xc000009a;
}



===== _guard_check_icall @ 140004df0 =====

void _guard_check_icall(void)

{
                    /* 0x4df0  43  TdiInitialize */
  return;
}



===== TdiReturnChainedReceives @ 140004e00 =====

void TdiReturnChainedReceives(void)

{
                    /* 0x4e00  57  TdiReturnChainedReceives */
  NdisReturnPackets();
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140004e1c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140008f8f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140004e44 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004fa0 =====

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



===== Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledDeviceUsageNoInline @ 140005024 =====

ulonglong Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState;
  if ((Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState & 0x10) == 0) {
    uVar1 = Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledFallback @ 14000505c =====

void Feature_TCPIP_2025_Wave2_TdiMemLeak__private_IsEnabledFallback
               (undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== TdiDeregisterAddressChangeHandler @ 140005080 =====

void TdiDeregisterAddressChangeHandler(longlong param_1)

{
                    /* 0x5080  35  TdiDeregisterAddressChangeHandler
                       0x5080  38  TdiDeregisterNotificationHandler
                       0x5080  39  TdiDeregisterPnPHandlers */
  TdiHandleSerializedRequest(param_1,9);
  return;
}



===== TdiDeregisterProvider @ 1400050a0 =====

void TdiDeregisterProvider(longlong param_1)

{
                    /* 0x50a0  40  TdiDeregisterProvider */
  TdiHandleSerializedRequest(param_1,0x12);
  return;
}



===== TdiIsIPTransportSupported @ 1400050c0 =====

bool TdiIsIPTransportSupported(void)

{
  int iVar1;
  
                    /* 0x50c0  44  TdiIsIPTransportSupported */
  iVar1 = RtlCheckRegistryKey(1,L"Tdx");
  return iVar1 == 0;
}



===== TdiPnPPowerComplete @ 1400050f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TdiPnPPowerComplete(undefined8 param_1,longlong param_2,int param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  
                    /* 0x50f0  48  TdiPnPPowerComplete */
  lVar7 = *(longlong *)(param_2 + 0x58);
  if (lVar7 != 0) {
    lVar6 = *(longlong *)(lVar7 + 0x68);
    while (lVar4 = lVar6, lVar4 != 0) {
      lVar7 = lVar4;
      lVar6 = *(longlong *)(lVar4 + 0x68);
    }
    if (param_3 != 0) {
      *(int *)(lVar7 + 0x38) = param_3;
    }
    LOCK();
    piVar1 = (int *)(lVar7 + 0x60);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      lVar6 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x68);
      lVar4 = *(longlong *)(param_2 + 0x58);
      if (lVar6 == 0) {
        *(undefined8 *)(param_2 + 0x58) = 0;
        *(undefined8 *)(param_2 + 0x60) = 0;
        *(undefined8 *)(param_2 + 0x68) = 0;
        *(undefined8 *)(param_2 + 0x70) = 0;
      }
      else {
        do {
          lVar5 = lVar4;
          plVar2 = (longlong *)(lVar6 + 0x68);
          lVar4 = lVar6;
          lVar6 = *plVar2;
        } while (*plVar2 != 0);
        *(undefined8 *)(lVar5 + 0x68) = 0;
        param_3 = 0;
      }
      if (*(code **)(lVar7 + 0x30) != (code *)0x0) {
        (**(code **)(lVar7 + 0x30))(param_2,param_3);
      }
      if (*(longlong *)(lVar7 + 0x80) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x80),0);
      }
      if (*(longlong *)(lVar7 + 0x50) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x50),0);
        *(undefined8 *)(lVar7 + 0x50) = 0;
      }
      if (*(longlong *)(lVar7 + 0x58) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x58),0);
        *(undefined8 *)(lVar7 + 0x58) = 0;
      }
      ExFreePoolWithTag(lVar7,0);
    }
  }
  return;
}



===== TdiPnPPowerCompleteHelper @ 1400051f0 =====

void TdiPnPPowerCompleteHelper(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== TdiProviderReady @ 140005210 =====

void TdiProviderReady(longlong param_1)

{
                    /* 0x5210  50  TdiProviderReady */
  TdiHandleSerializedRequest(param_1,0x13);
  return;
}



===== TdiRegisterAddressChangeHandler @ 140005230 =====

void TdiRegisterAddressChangeHandler(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  byte local_48 [40];
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_48[0x20] = 0;
  local_48[0x21] = 0;
  local_48[0x22] = 0;
  local_48[0x23] = 0;
  local_48[0x24] = 0;
  local_48[0x25] = 0;
  local_48[0x26] = 0;
  local_48[0x27] = 0;
                    /* 0x5230  51  TdiRegisterAddressChangeHandler */
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
  local_48[0] = 1;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_48[0x10] = 0;
  local_48[0x11] = 0;
  local_48[0x12] = 0;
  local_48[0x13] = 0;
  local_48[0x14] = 0;
  local_48[0x15] = 0;
  local_48[0x16] = 0;
  local_48[0x17] = 0;
  local_48[0x18] = 0;
  local_48[0x19] = 0;
  local_48[0x1a] = 0;
  local_48[0x1b] = 0;
  local_48[0x1c] = 0;
  local_48[0x1d] = 0;
  local_48[0x1e] = 0;
  local_48[0x1f] = 0;
  uStack_20 = param_1;
  local_18 = param_2;
  TdiRegisterPnPHandlers(local_48,0x38,param_3);
  return;
}



===== TdiRegisterNotificationHandler @ 140005270 =====

void TdiRegisterNotificationHandler(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  byte local_48 [24];
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
                    /* 0x5270  54  TdiRegisterNotificationHandler */
  local_48[0x10] = 0;
  local_48[0x11] = 0;
  local_48[0x12] = 0;
  local_48[0x13] = 0;
  local_48[0x14] = 0;
  local_48[0x15] = 0;
  local_48[0x16] = 0;
  local_48[0x17] = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_48[0] = 1;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  uStack_30 = param_1;
  local_28 = param_2;
  TdiRegisterPnPHandlers(local_48,0x38,param_3);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400052b8 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140005390 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140005474 =====

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
LAB_1400055cc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400055bf:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400055cc;
      if (uVar5 == 5) goto LAB_1400055bf;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400055f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x2b2cf63,&Feature_TCPIP_2025_Wave1_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140005670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_TCPIP_2025_Wave2_TdiMemLeak__private_reporting,
                      param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x2b2cf63,param_3 & 0xffffffff,1,
               &Feature_TCPIP_2025_Wave2_TdiMemLeak__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x2b2cf63);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000575c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000586c =====

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
  if ((Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState & 2) != 0) {
    uVar1 = Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState;
      if (bVar3) {
        Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 1400058c0 =====

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



===== wil_details_IsEnabledFallback @ 140005a20 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_TCPIP_2025_Wave2_TdiMemLeak__private_featureState,
                             (ulonglong)param_1,0x140008f20);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 140005ab0 =====

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



===== __GSHandlerCheck @ 140005b58 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005b7c =====

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



===== __cpu_features_init @ 140005bf0 =====

/* WARNING: Removing unreachable block (ram,0x000140005c5a) */
/* WARNING: Removing unreachable block (ram,0x000140005c09) */
/* WARNING: Removing unreachable block (ram,0x000140005bfa) */

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



===== __security_check_cookie @ 140005cc0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005d00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005d30 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005d60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140005dc0 =====

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



===== memset @ 1400060c0 =====

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



===== __memset_repmovs @ 140006200 =====

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



===== __memset_query @ 140006280 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006300 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006440 =====

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



===== __memset_spec_plain @ 1400064c0 =====

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



===== CTELogEvent @ 14000c010 =====

undefined8
CTELogEvent(undefined8 param_1,undefined4 param_2,undefined4 param_3,ushort param_4,
           undefined8 *param_5,uint param_6,void *param_7)

{
  short sVar1;
  undefined8 uVar2;
  longlong lVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  ulonglong uVar8;
  ushort uVar9;
  uint uVar10;
  
                    /* 0xc010  9  CTELogEvent */
  uVar8 = (ulonglong)param_4;
  uVar9 = 0;
  uVar10 = 0;
  while( true ) {
    if (param_4 <= uVar9) {
      uVar7 = param_6;
      if ((param_6 & 3) != 0) {
        uVar7 = (param_6 - (param_6 & 3)) + 4;
      }
      uVar10 = uVar10 + uVar7;
      if (uVar10 < 0xc5) {
        iVar5 = uVar10 + 0x2c;
        if (uVar10 < 5) {
          iVar5 = uVar10 + 0x30;
        }
        lVar3 = IoAllocateErrorLogEntry(param_1,iVar5);
        if (lVar3 == 0) {
          uVar2 = 0xc000009a;
        }
        else {
          *(undefined4 *)(lVar3 + 0x10) = param_3;
          *(undefined4 *)(lVar3 + 0xc) = param_2;
          *(ushort *)(lVar3 + 4) = param_4;
          *(short *)(lVar3 + 6) = (short)uVar7 + 0x2c;
          *(short *)(lVar3 + 2) = (short)uVar7;
          if (param_6 != 0) {
            memmove((void *)(lVar3 + 0x28),param_7,(ulonglong)param_6);
          }
          psVar4 = (short *)((ulonglong)uVar7 + (ulonglong)*(ushort *)(lVar3 + 6) + lVar3);
          if (param_4 != 0) {
            do {
              psVar6 = (short *)*param_5;
              do {
                sVar1 = *psVar6;
                psVar6 = psVar6 + 1;
                *psVar4 = sVar1;
                psVar4 = psVar4 + 1;
              } while (sVar1 != 0);
              param_5 = param_5 + 1;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
          IoWriteErrorLogEntry(lVar3);
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xc0000023;
      }
      return uVar2;
    }
    iVar5 = 2;
    for (psVar4 = (short *)param_5[uVar9]; *psVar4 != 0; psVar4 = psVar4 + 1) {
      iVar5 = iVar5 + 2;
    }
    if (iVar5 + uVar10 < uVar10) break;
    uVar9 = uVar9 + 1;
    uVar10 = iVar5 + uVar10;
  }
  return 0xc0000206;
}



===== wil_UninitializeFeatureStaging @ 14000c178 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000c1d0 =====

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
      goto LAB_14000c22d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000c22d;
    }
  }
  uVar1 = 0x206;
LAB_14000c22d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c238 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c2f0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000c328 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000c3aa;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000c3aa;
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
LAB_14000c3aa:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000c400 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000c460 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000c47c =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14000c530 =====

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



===== entry @ 14000e010 =====

void entry(void)

{
  __security_init_cookie();
  TdiDefaultDisconnectHandler();
  return;
}



===== __security_init_cookie @ 14000e044 =====

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



===== wil_InitializeFeatureStaging @ 14000e078 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000e168 =====

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



===== TdiMatchPdoWithChainedReceiveContext @ 140012000 =====

/* WARNING: Control flow encountered bad instruction data */
/* 0xd67d  46  TdiMatchPdoWithChainedReceiveContext  (forwarder -> NDIS.NdisMatchPdoWithPacket) */

void TdiMatchPdoWithChainedReceiveContext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


