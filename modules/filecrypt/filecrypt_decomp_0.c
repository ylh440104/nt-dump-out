
===== RtlStringCbCopyNW @ 140001010 =====

undefined8 RtlStringCbCopyNW(short *param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  
  if ((param_2 >> 1) - 1 < 0x7fffffff) {
    if (param_4 >> 1 < 0x7fffffff) {
      uVar1 = RtlStringCopyWorkerW(param_1,param_2 >> 1,param_3,param_3,param_4 >> 1);
      return uVar1;
    }
    *param_1 = 0;
  }
  return 0xc000000d;
}



===== RtlStringCopyWorkerW @ 140001060 =====

undefined8
RtlStringCopyWorkerW
          (short *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5)

{
  short sVar1;
  undefined8 uVar2;
  short *psVar3;
  longlong lVar4;
  
  if (param_2 != 0) {
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((param_5 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  uVar2 = 0x80000005;
  if (param_2 != 0) {
    uVar2 = 0;
  }
  *psVar3 = 0;
  return uVar2;
}



===== RtlStringLengthWorkerW @ 1400010c0 =====

undefined8 RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = 0xc000000d;
  if (lVar2 != 0) {
    uVar1 = 0;
  }
  if (param_3 != (longlong *)0x0) {
    if (lVar2 == 0) {
      *param_3 = 0;
      return uVar1;
    }
    *param_3 = param_2 - lVar2;
  }
  return uVar1;
}



===== RtlStringCbCopyW @ 140001110 =====

undefined8 RtlStringCbCopyW(short *param_1,ulonglong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar4 = param_2 >> 1;
  if (uVar4 - 1 < 0x7fffffff) {
    lVar6 = 0x7ffffffe - uVar4;
    lVar5 = param_3 - (longlong)param_1;
    do {
      if ((lVar6 + uVar4 == 0) || (sVar1 = *(short *)(lVar5 + (longlong)param_1), sVar1 == 0))
      break;
      *param_1 = sVar1;
      param_1 = param_1 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    psVar2 = param_1 + -1;
    if (uVar4 != 0) {
      psVar2 = param_1;
    }
    *psVar2 = 0;
    uVar3 = 0x80000005;
    if (uVar4 != 0) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar4 != 0) {
      *param_1 = 0;
      return uVar3;
    }
  }
  return uVar3;
}



===== RtlStringCbLengthW @ 140001190 =====

int RtlStringCbLengthW(short *param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = 0;
  if (param_1 == (short *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    lVar1 = 0x7fffffff;
    do {
      if (*param_1 == 0) break;
      param_1 = param_1 + 1;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    iVar2 = -0x3ffffff3;
    if (lVar1 == 0) {
      lVar1 = 0;
    }
    else {
      iVar2 = 0;
      lVar1 = 0x7fffffff - lVar1;
    }
  }
  if (param_3 != (longlong *)0x0) {
    if (iVar2 < 0) {
      *param_3 = 0;
      return iVar2;
    }
    *param_3 = lVar1 * 2;
  }
  return iVar2;
}



===== RtlStringCbCatNW @ 1400011f0 =====

undefined8 RtlStringCbCatNW(short *param_1,ulonglong param_2,longlong param_3,ulonglong param_4)

{
  short sVar1;
  ulonglong uVar2;
  short *psVar3;
  undefined8 uVar4;
  longlong lVar5;
  short *psVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar7 = param_2 >> 1;
  if (uVar7 - 1 < 0x7fffffff) {
    uVar2 = uVar7;
    psVar3 = param_1;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    if (uVar2 == 0) {
      uVar4 = 0xc000000d;
    }
    else {
      lVar5 = uVar7 - uVar2;
      if (param_4 >> 1 < 0x7fffffff) {
        psVar3 = param_1 + lVar5;
        lVar8 = uVar7 - lVar5;
        if (lVar8 != 0) {
          lVar5 = (lVar5 - uVar7) + lVar8 + (param_4 >> 1);
          lVar9 = param_3 - (longlong)psVar3;
          do {
            if ((lVar5 == 0) || (sVar1 = *(short *)(lVar9 + (longlong)psVar3), sVar1 == 0)) break;
            *psVar3 = sVar1;
            lVar5 = lVar5 + -1;
            psVar3 = psVar3 + 1;
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
        }
        psVar6 = psVar3 + -1;
        if (lVar8 != 0) {
          psVar6 = psVar3;
        }
        uVar4 = 0x80000005;
        if (lVar8 != 0) {
          uVar4 = 0;
        }
        *psVar6 = 0;
      }
      else {
        uVar4 = 0xc000000d;
      }
    }
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== RtlStringCbPrintfW @ 1400012d0 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  size_t _Count;
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    _Count = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = L'\0';
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = L'\0';
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== RtlStringCchCopyW @ 140001350 =====

undefined8 RtlStringCchCopyW(short *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  short *psVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (param_2 - 1U < 0x7fffffff) {
    lVar5 = 0x7ffffffe - param_2;
    lVar4 = param_3 - (longlong)param_1;
    do {
      if ((lVar5 + param_2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
      break;
      *param_1 = sVar1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    psVar2 = param_1 + -1;
    if (param_2 != 0) {
      psVar2 = param_1;
    }
    *psVar2 = 0;
    uVar3 = 0x80000005;
    if (param_2 != 0) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
      return uVar3;
    }
  }
  return uVar3;
}



===== McGenEventRegister_EtwRegister @ 1400013c0 =====

undefined8 McGenEventRegister_EtwRegister(void)

{
  undefined8 uVar1;
  
  if (FileCryptGuid_Context == 0) {
    uVar1 = EtwRegister(&FileCryptGuid,McGenControlCallbackV2,&FileCryptGuid_Context,
                        &FileCryptGuid_Context);
    return uVar1;
  }
  return 0;
}



===== __report_gsfailure @ 140001420 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000142d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000142d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _vsnwprintf @ 140001440 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 140001460 =====

int __cdecl
_vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if ((_Format == (wchar_t *)0x0) || ((_MaxCount != 0 && (_DstBuf == (wchar_t *)0x0)))) {
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    if (_MaxCount < 0x40000000) {
      local_38._cnt = (int)_MaxCount * 2;
    }
    else {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = (char *)_DstBuf;
    local_38._base = (char *)_DstBuf;
    iVar1 = _woutput_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
        local_38._ptr = (char *)((longlong)local_38._ptr + 1);
      }
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
      }
    }
  }
  return iVar1;
}



===== _wcsicmp @ 140001558 =====

int __cdecl _wcsicmp(wchar_t *_Str1,wchar_t *_Str2)

{
  wchar_t wVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  longlong lVar4;
  
  lVar4 = (longlong)_Str1 - (longlong)_Str2;
  do {
    wVar3 = *(wchar_t *)(lVar4 + (longlong)_Str2);
    wVar1 = *_Str2;
    _Str2 = _Str2 + 1;
    wVar2 = wVar3 + L' ';
    if (0x19 < (ushort)(wVar3 + L'﾿')) {
      wVar2 = wVar3;
    }
    wVar3 = wVar1 + L' ';
    if (0x19 < (ushort)(wVar1 + L'﾿')) {
      wVar3 = wVar1;
    }
  } while ((wVar2 != L'\0') && (wVar2 == wVar3));
  return (uint)(ushort)wVar2 - (uint)(ushort)wVar3;
}



===== _flsbuf @ 1400015ac =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 1400015bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _woutput_l(FILE *_File,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  char *pcVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  wchar_t *pwVar13;
  uint uVar14;
  FILE *pFVar15;
  uint uVar16;
  ulonglong uVar17;
  wchar_t wVar18;
  ulonglong uVar19;
  uint uVar20;
  wchar_t *pwVar21;
  int iVar22;
  undefined1 auStack_4d8 [32];
  undefined8 local_4b8;
  int local_4a8;
  uint local_4a4;
  uint local_4a0;
  wchar_t local_49c [2];
  int local_498;
  int local_494;
  char local_490 [4];
  wchar_t local_48c;
  short local_48a;
  uint local_488;
  wchar_t *local_480;
  int local_478;
  FILE *local_470;
  undefined4 local_468;
  wchar_t *local_460;
  wchar_t local_448 [255];
  undefined2 local_249;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_4d8;
  local_468 = 0;
  uVar16 = 0;
  local_488 = 0;
  uVar12 = 0;
  uVar14 = 0;
  local_4a0 = 0;
  pwVar13 = (wchar_t *)0x0;
  local_4a4 = 0;
  local_478 = 0;
  local_480 = (wchar_t *)_ArgList;
  local_470 = _File;
  memset(local_448,0,0x400);
  local_49c[0] = L'\0';
  local_498 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (wchar_t *)0x0)) {
LAB_140001e80:
    local_4b8 = 0;
    _guard_check_icall();
    iVar6 = -1;
  }
  else {
    wVar18 = *_Format;
    iVar6 = 0;
    local_4a8 = 0;
    uVar19 = 0;
    local_494 = 0;
    if (wVar18 != L'\0') {
      do {
        pwVar21 = _Format + 1;
        if (iVar6 < 0) break;
        uVar8 = 0;
        if ((ushort)(wVar18 + L'￠') < 0x5b) {
          uVar20 = (int)*(char *)((longlong)L"FolderId" + (ulonglong)(ushort)wVar18 + 0x10) & 0xf;
        }
        else {
          uVar20 = uVar8;
        }
        uVar11 = (uint)(ushort)wVar18;
        local_494 = (int)(char)(&__lookuptable)[(int)(local_494 + uVar20 * 8)] >> 4;
        uVar20 = uVar16;
        local_460 = pwVar21;
        if (local_494 == 0) {
LAB_140001d54:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_140001c02:
          iVar6 = local_4a8;
LAB_140001c0a:
        }
        else if (local_494 == 1) {
          uVar12 = 0xffffffff;
          uVar14 = 0xffffffff;
          local_478 = 0;
          local_4a0 = 0xffffffff;
          local_488 = 0;
          local_4a4 = 0;
          local_498 = 0;
          uVar16 = uVar8;
        }
        else if (local_494 == 2) {
          if (uVar11 == 0x20) {
            uVar16 = uVar16 | 2;
          }
          else if (uVar11 == 0x23) {
            uVar16 = uVar16 | 0x80;
          }
          else if (uVar11 == 0x2b) {
            uVar16 = uVar16 | 1;
          }
          else if (uVar11 == 0x2d) {
            uVar16 = uVar16 | 4;
          }
          else if (uVar11 == 0x30) {
            uVar16 = uVar16 | 8;
          }
        }
        else if (local_494 == 3) {
          if (wVar18 == L'*') {
            uVar8 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            if ((int)uVar8 < 0) {
              uVar16 = uVar16 | 4;
            }
            local_488 = -uVar8;
            if (-1 < (int)uVar8) {
              local_488 = uVar8;
            }
          }
          else {
            local_488 = uVar11 + (local_488 * 5 + -0x18) * 2;
          }
        }
        else if (local_494 == 4) {
          local_4a0 = 0;
          uVar14 = uVar8;
          uVar12 = uVar8;
        }
        else if (local_494 == 5) {
          if (wVar18 == L'*') {
            local_4a0 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            uVar14 = local_4a0;
            uVar12 = local_4a0;
            if ((int)local_4a0 < 0) {
              local_4a0 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar12 = 0xffffffff;
            }
          }
          else {
            local_4a0 = uVar11 + (uVar14 * 5 + -0x18) * 2;
            uVar14 = local_4a0;
            uVar12 = local_4a0;
          }
        }
        else if (local_494 == 6) {
          if (uVar11 == 0x49) {
LAB_140001ca5:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_140001d28;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_140001d28:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_140001c14;
                  }
                  local_494 = 0;
                  goto LAB_140001d54;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_140001d28;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_140001ca5;
            if (uVar11 == 0x6c) {
              if (*pwVar21 == L'l') {
                pwVar21 = _Format + 2;
                uVar16 = uVar16 | 0x1000;
              }
              else {
                uVar16 = uVar16 | 0x10;
              }
            }
            else {
              if (uVar11 == 0x74) goto LAB_140001ca5;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_140001ca5;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_14000174d:
              uVar16 = uVar16 | 0x40;
LAB_140001750:
              uVar19 = 10;
              goto LAB_14000175b;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140001884:
              local_49c[0] = *(wchar_t *)_ArgList;
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              local_498 = 1;
              if ((uVar16 & 0x20) == 0) {
                local_448[0] = local_49c[0];
              }
              else {
                local_490[0] = (char)local_49c[0];
                local_490[1] = 0;
                iVar22 = mbtowc(local_448,local_490,(longlong)__mb_cur_max);
                if (iVar22 < 0) {
                  local_478 = 1;
                }
              }
              pwVar13 = local_448;
              uVar19 = 1;
            }
            else if (uVar11 == 0x53) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_14000180d:
              pwVar13 = *(wchar_t **)_ArgList;
              uVar8 = uVar14;
              if (uVar14 == 0xffffffff) {
                uVar8 = 0x7fffffff;
              }
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 & 0x20) == 0) {
                local_498 = 1;
                pwVar9 = L"(null)";
                pwVar5 = L"(null)";
                if (pwVar13 != (wchar_t *)0x0) {
                  pwVar9 = pwVar13;
                  pwVar5 = pwVar13;
                }
                for (; (pwVar13 = pwVar5, uVar8 != 0 && (uVar8 = uVar8 - 1, *pwVar9 != L'\0'));
                    pwVar9 = pwVar9 + 1) {
                  pwVar5 = pwVar13;
                }
                uVar19 = (longlong)pwVar9 - (longlong)pwVar13 >> 1 & 0xffffffff;
              }
              else {
                if (pwVar13 == (wchar_t *)0x0) {
                  pwVar13 = L"渨汵⥬";
                }
                pwVar9 = pwVar13;
                uVar19 = 0;
                if (0 < (int)uVar8) {
                  do {
                    if ((char)*pwVar9 == '\0') break;
                    pwVar9 = (wchar_t *)((longlong)pwVar9 + 1);
                    uVar20 = (int)uVar19 + 1;
                    uVar19 = (ulonglong)uVar20;
                  } while ((int)uVar20 < (int)uVar8);
                }
              }
            }
            else {
              if (uVar11 == 0x58) goto LAB_14000195e;
              if (uVar11 == 0x5a) {
                puVar3 = *(ushort **)_ArgList;
                local_480 = (wchar_t *)((longlong)_ArgList + 8);
                if ((puVar3 == (ushort *)0x0) ||
                   (pwVar13 = *(wchar_t **)(puVar3 + 4), pwVar13 == (wchar_t *)0x0)) {
                  pwVar13 = L"渨汵⥬";
                  uVar7 = 0xffffffffffffffff;
                  do {
                    uVar19 = uVar7 + 1;
                    pcVar1 = "null)" + uVar7;
                    uVar7 = uVar19;
                  } while (*pcVar1 != '\0');
                }
                else {
                  uVar2 = *puVar3;
                  if (puVar3[1] < uVar2) goto LAB_140001e80;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140001e80;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_140001884;
                if (uVar11 == 100) goto LAB_14000174d;
              }
            }
LAB_140001a9a:
            if (local_478 != 0) goto LAB_140001c0a;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_140001ae8;
                  local_48c = L' ';
                }
                else {
                  local_48c = L'+';
                }
              }
              else {
                local_48c = L'-';
              }
              local_4a4 = 1;
            }
LAB_140001ae8:
            uVar14 = local_4a4;
            iVar6 = (int)uVar19;
            iVar22 = (local_488 - iVar6) - local_4a4;
            if ((uVar16 & 0xc) == 0) {
              write_multi_char(L' ',iVar22,local_470,&local_4a8);
            }
            write_string(&local_48c,uVar14,local_470,&local_4a8);
            pFVar15 = local_470;
            if ((uVar16 & 0xc) == 8) {
              write_multi_char(L'0',iVar22,local_470,&local_4a8);
            }
            if ((local_498 == 0) && (0 < iVar6)) {
              uVar7 = uVar19 & 0xffffffff;
              pwVar21 = pwVar13;
              do {
                iVar6 = mbtowc(local_49c,(char *)pwVar21,(longlong)__mb_cur_max);
                uVar14 = (int)uVar7 - ((iVar6 == 2) + 1);
                uVar7 = (ulonglong)uVar14;
                if (iVar6 < 1) {
                  local_4a8 = -1;
                  pFVar15 = local_470;
                  pwVar21 = local_460;
                  goto LAB_140001bde;
                }
                write_char(local_49c[0],local_470,&local_4a8);
                pwVar21 = (wchar_t *)((longlong)pwVar21 + (longlong)iVar6);
              } while (0 < (int)uVar14);
              pFVar15 = local_470;
              pwVar21 = local_460;
            }
            else {
              write_string(pwVar13,iVar6,pFVar15,&local_4a8);
            }
LAB_140001bde:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_140001c02;
            }
          }
          else {
            if (wVar18 != L'n') {
              if (wVar18 == L'o') {
                uVar19 = 8;
                if ((char)uVar16 < '\0') {
                  uVar16 = uVar16 | 0x200;
                }
              }
              else {
                if (wVar18 == L'p') {
                  uVar12 = 0x10;
                  uVar14 = 0x10;
                  uVar16 = uVar16 | 0x8000;
LAB_14000195e:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_14000180d;
                  if (wVar18 == L'u') goto LAB_140001750;
                  if (wVar18 != L'x') goto LAB_140001a9a;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_14000175b:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_1400019d5;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1400019d5:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_1400019d5;
              }
              uVar17 = uVar7 & 0xffffffff;
              if ((uVar16 & 0x9000) != 0) {
                uVar17 = uVar7;
              }
              if ((int)uVar14 < 0) {
                uVar12 = 1;
              }
              else {
                uVar16 = uVar16 & 0xfffffff7;
                if (0x200 < (int)uVar14) {
                  uVar12 = 0x200;
                }
              }
              local_4a4 = -(uint)(uVar17 != 0) & local_4a4;
              pwVar9 = &local_249;
              for (; (uVar14 = uVar12 - 1, 0 < (int)uVar12 || (uVar17 != 0));
                  uVar17 = uVar17 / uVar19) {
                uVar12 = (int)(uVar17 % uVar19) + 0x30;
                cVar10 = (char)uVar12;
                if (0x39 < uVar12) {
                  cVar10 = cVar10 + (char)local_468;
                }
                *(char *)pwVar9 = cVar10;
                pwVar9 = (wchar_t *)((longlong)pwVar9 + -1);
                uVar12 = uVar14;
              }
              uVar12 = (int)&local_249 - (int)pwVar9;
              uVar19 = (ulonglong)uVar12;
              pwVar13 = (wchar_t *)((longlong)pwVar9 + 1);
              if (((uVar16 >> 9 & 1) != 0) && ((uVar12 == 0 || (*(char *)pwVar13 != '0')))) {
                uVar19 = (ulonglong)(uVar12 + 1);
                *(char *)pwVar9 = '0';
                pwVar13 = pwVar9;
              }
              uVar12 = uVar14;
              local_4a0 = uVar14;
              goto LAB_140001a9a;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_140001e80;
            if ((uVar16 & 0x20) == 0) {
              *piVar4 = iVar6;
            }
            else {
              *(short *)piVar4 = (short)iVar6;
            }
            local_478 = 1;
          }
          uVar14 = local_4a0;
          uVar12 = local_4a0;
        }
LAB_140001c14:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 140001ec8 =====

void write_char(wchar_t param_1,FILE *param_2,int *param_3)

{
  wint_t wVar1;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    wVar1 = _fputwc_nolock(param_1,param_2);
    if ((wVar1 == 0xffff) && ((param_2->_flag & 0x20U) != 0)) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 140001f1c =====

void write_multi_char(wchar_t param_1,int param_2,FILE *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 140001f74 =====

void write_string(wchar_t *param_1,int param_2,FILE *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    do {
      if (param_2 < 1) {
        return;
      }
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
    } while (*param_4 != -1);
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _get_printf_count_output @ 140001fe8 =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_1400091c0 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 140002008 =====

wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File)

{
  int *piVar1;
  int iVar2;
  
  if (_File == (FILE *)0x0) {
    _guard_check_icall();
    _Ch = L'\xffff';
  }
  else {
    piVar1 = &_File->_cnt;
    *piVar1 = *piVar1 + -2;
    if (*piVar1 < 0) {
      iVar2 = _flswbuf((uint)(ushort)_Ch,_File);
      _Ch = (wchar_t)iVar2;
    }
    else {
      *(wchar_t *)_File->_ptr = _Ch;
      _File->_ptr = _File->_ptr + 2;
    }
  }
  return _Ch;
}



===== mbtowc @ 140002054 =====

int __cdecl mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  wchar_t wVar1;
  char *local_res10 [3];
  
  local_res10[0]._0_4_ = 0;
  if ((_SrcCh != (char *)0x0) && (_SrcSizeInBytes != 0)) {
    if (*_SrcCh == '\0') {
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = L'\0';
      }
    }
    else {
      local_res10[0] = _SrcCh;
      wVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *_DstCh = wVar1;
      local_res10[0]._0_4_ = (int)local_res10[0] - (int)_SrcCh;
    }
  }
  return (int)local_res10[0];
}



===== __GSHandlerCheck @ 1400020a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400020cc =====

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



===== _flswbuf @ 140002138 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 140002150 =====

/* WARNING: Removing unreachable block (ram,0x0001400021ba) */
/* WARNING: Removing unreachable block (ram,0x000140002169) */
/* WARNING: Removing unreachable block (ram,0x00014000215a) */

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



===== _guard_check_icall @ 140002220 =====

void _guard_check_icall(void)

{
  return;
}



===== RtlAnsiCharToUnicodeChar @ 14000222a =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000222a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== FCDecryptWorker @ 140002240 =====

void FCDecryptWorker(longlong param_1,undefined8 param_2,PUCHAR param_3)

{
  int iVar1;
  uint *puVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  PUCHAR pUVar6;
  uint *puVar7;
  undefined *puVar8;
  PUCHAR pUVar9;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar10;
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  puVar2 = *(uint **)param_3;
  lVar3 = *(longlong *)(puVar2 + 4);
  plVar4 = *(longlong **)(param_3 + 8);
  local_res20[0] = 0;
  puVar7 = *(uint **)(lVar3 + 0x38);
  pUVar9 = param_3;
  if (puVar7 == (uint *)0x0) {
    if ((*puVar2 & 8) == 0) {
      puVar7 = puVar2;
      pUVar6 = param_3;
      uVar5 = FltLockUserBuffer();
      if ((int)uVar5 < 0) {
        if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
          McTemplateK0d_EtwWriteTransfer(puVar7,&LockUserBufferFailure,pUVar6,uVar5);
        }
        goto LAB_140002416;
      }
      puVar7 = *(uint **)(lVar3 + 0x38);
      pUVar9 = pUVar6;
      goto LAB_140002288;
    }
    pUVar6 = *(PUCHAR *)(lVar3 + 0x30);
LAB_14000230a:
    puVar7 = puVar2;
    uVar5 = FltGetFsZeroingOffset(puVar2,local_res20);
    if (-1 < (int)uVar5) {
      iVar1 = *(int *)(*plVar4 + 0x10);
      uVar5 = FCpEncDecrypt(*plVar4 + 0x18,(undefined8 *)plVar4[1],pUVar6,pUVar6,
                            (puVar2[8] - 1) + iVar1 & -iVar1,*(longlong *)(lVar3 + 0x28),
                            local_res20[0]);
      goto LAB_140002416;
    }
    pUVar6 = pUVar9;
    if ((Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_140002416;
    puVar8 = &GetFsZeroingOffsetFailure;
  }
  else {
LAB_140002288:
    if ((*(byte *)((longlong)puVar7 + 10) & 5) == 0) {
      pUVar9 = (PUCHAR)0x1;
      pUVar6 = (PUCHAR)MmMapLockedPagesSpecifyCache
                                 (puVar7,0,1,0,0,
                                  CONCAT44(uVar10,ExDefaultMdlProtection) | 0x40000010);
    }
    else {
      pUVar6 = *(PUCHAR *)(puVar7 + 6);
    }
    if (pUVar6 != (PUCHAR)0x0) goto LAB_14000230a;
    uVar5 = 0xc000009a;
    pUVar6 = pUVar9;
    if ((Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_140002416;
    puVar8 = &GetSystemAddressFailure;
    uVar5 = 0xc000009a;
  }
  McTemplateK0d_EtwWriteTransfer(puVar7,puVar8,pUVar9,uVar5);
  pUVar6 = pUVar9;
LAB_140002416:
  FltReleaseContext(*plVar4);
  FltReleaseContext(plVar4[1]);
  puVar8 = &gPre2PostIoContextList;
  ExFreeToNPagedLookasideList(&gPre2PostIoContextList,plVar4);
  if ((int)uVar5 < 0) {
    puVar2[6] = uVar5;
    puVar2[8] = 0;
    puVar2[9] = 0;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(puVar8,&DecryptWorkerFailure,pUVar6,uVar5);
    }
  }
  if (param_1 != 0) {
    FltCompletePendedPostOperation(puVar2);
    FltFreeGenericWorkItem(param_1);
    ExFreePoolWithTag(param_3,0x63644346);
  }
  return;
}



===== FCFreeShadowBuffer @ 1400024c4 =====

void FCFreeShadowBuffer(undefined8 param_1,undefined8 param_2,char param_3)

{
  if (param_3 == '\x01') {
    ExFreeToNPagedLookasideList(&gShadowBufferList);
  }
  else if (param_3 == '\x02') {
    ExFreePoolWithTag(param_2,0x62734346);
  }
  return;
}



===== FCPostRead @ 140002510 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FCPostRead(uint *param_1,longlong param_2,uint **param_3,ulonglong param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 uVar7;
  uint *local_50;
  uint **ppuStack_48;
  
  bVar1 = true;
  lVar4 = 0;
  puVar5 = (undefined8 *)0x0;
  local_50 = (uint *)0x0;
  ppuStack_48 = (uint **)0x0;
  uVar7 = 0;
  uVar3 = 0;
  pcVar6 = (code *)param_3;
  if ((((param_4 & 1) == 0) && (-1 < (int)param_1[6])) && (*(longlong *)(param_1 + 8) != 0)) {
    bVar2 = KeGetCurrentIrql();
    if ((bVar2 < 2) ||
       ((*(ulonglong *)(param_1 + 8) < 0x20001 &&
        ((*(longlong *)(*(longlong *)(param_1 + 4) + 0x38) != 0 || ((*param_1 & 8) != 0)))))) {
      pcVar6 = (code *)&local_50;
      local_50 = param_1;
      ppuStack_48 = param_3;
      FCDecryptWorker(0,*(undefined8 *)(param_2 + 0x18),(PUCHAR)pcVar6);
      bVar1 = false;
      uVar3 = param_1[6];
    }
    else {
      lVar4 = FltAllocateGenericWorkItem();
      if (lVar4 != 0) {
        pcVar6 = (code *)0x63644346;
        puVar5 = (undefined8 *)ExAllocatePool2(0x40);
        if (puVar5 != (undefined8 *)0x0) {
          *puVar5 = param_1;
          puVar5[1] = param_3;
          pcVar6 = FCDecryptWorker;
          uVar3 = FltQueueGenericWorkItem
                            (lVar4,*(undefined8 *)(param_2 + 0x18),FCDecryptWorker,1,puVar5);
          if (-1 < (int)uVar3) {
            uVar7 = 1;
            bVar1 = false;
          }
          goto LAB_14000266f;
        }
      }
      uVar3 = 0xc000009a;
    }
  }
LAB_14000266f:
  if ((int)uVar3 < 0) {
    param_1[6] = uVar3;
    param_1[8] = 0;
    param_1[9] = 0;
  }
  if (bVar1) {
    FltReleaseContext(*param_3);
    FltReleaseContext(param_3[1]);
    ExFreeToNPagedLookasideList(&gPre2PostIoContextList,param_3);
    if (lVar4 != 0) {
      FltFreeGenericWorkItem(lVar4);
    }
    if (puVar5 != (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar5,0x63644346);
    }
    uVar7 = 0;
  }
  if (((int)uVar3 < 0) && ((_Microsoft_Windows_FileCryptEnableBits & 2) != 0)) {
    McTemplateK0d_EtwWriteTransfer
              ((ulonglong)_Microsoft_Windows_FileCryptEnableBits,&PostReadFailure,pcVar6,uVar3);
  }
  return uVar7;
}



===== FCPostWrite @ 140002720 =====

undefined8 FCPostWrite(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  FltReleaseContext(*param_3);
  uVar1 = param_3[1];
  FltReleaseContext();
  FCFreeShadowBuffer(uVar1,param_3[2],*(char *)(param_3 + 3));
  ExFreeToNPagedLookasideList(&gPre2PostIoContextList,param_3);
  return 0;
}



===== FCPreRead @ 140002780 =====

int FCPreRead(undefined *param_1,longlong param_2,longlong *param_3,undefined8 param_4)

{
  int iVar1;
  longlong *plVar2;
  undefined *puVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined *local_res20;
  undefined *local_40;
  longlong *local_38;
  
  local_res20 = (undefined *)0x0;
  local_40 = (undefined *)0x0;
  plVar2 = (longlong *)0x0;
  local_38 = (longlong *)0x0;
  iVar4 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x18);
  ppuVar5 = &local_40;
  puVar3 = *(undefined **)(param_2 + 0x18);
  iVar1 = FltGetStreamContext(puVar3,*(undefined8 *)(param_2 + 0x20),ppuVar5,param_4,1);
  if ((iVar1 < 0) ||
     (((*(longlong *)(param_2 + 0x20) != 0 &&
       ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) >> 8 & 1) != 0)) || (iVar4 == 0)))) {
    iVar4 = 1;
  }
  else {
    ppuVar5 = &local_res20;
    puVar3 = *(undefined **)(param_2 + 8);
    iVar1 = FltGetVolumeContext(puVar3,*(undefined8 *)(param_2 + 0x10));
    if (iVar1 < 0) {
      if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
        McTemplateK0d_EtwWriteTransfer(puVar3,&GetVolumeContextFailure,ppuVar5,iVar1);
      }
    }
    else {
      puVar3 = &gPre2PostIoContextList;
      plVar2 = (longlong *)ExAllocateFromNPagedLookasideList();
      local_38 = plVar2;
      if (plVar2 == (longlong *)0x0) {
        iVar1 = -0x3fffff66;
        iVar4 = 4;
        if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
          McTemplateK0d_EtwWriteTransfer(puVar3,&AllocationFailure,ppuVar5,0xc000009a);
        }
        goto LAB_1400028e4;
      }
      puVar3 = param_1;
      iVar1 = FltSetFsZeroingOffsetRequired();
      if (-1 < iVar1) {
        puVar3 = param_1;
        FltSetCallbackDataDirty();
        *plVar2 = (longlong)local_res20;
        plVar2[1] = (longlong)local_40;
        *param_3 = (longlong)plVar2;
        iVar4 = 0;
        goto LAB_1400028e0;
      }
    }
    iVar4 = 4;
  }
LAB_1400028e0:
LAB_1400028e4:
  if (iVar4 != 0) {
    if (plVar2 != (longlong *)0x0) {
      ExFreeToNPagedLookasideList(&gPre2PostIoContextList,plVar2);
    }
    if (local_res20 != (undefined *)0x0) {
      FltReleaseContext();
    }
    puVar3 = local_40;
    if (local_40 != (undefined *)0x0) {
      FltReleaseContext();
    }
  }
  if (iVar4 == 4) {
    *(int *)(param_1 + 0x18) = iVar1;
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if ((iVar1 < 0) && ((Microsoft_Windows_FileCryptEnableBits & 2) != 0)) {
    McTemplateK0d_EtwWriteTransfer(puVar3,&PreReadFailure,ppuVar5,iVar1);
  }
  return iVar4;
}



===== FCPreWrite @ 140002980 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FCPreWrite(PUCHAR param_1,longlong param_2,longlong *param_3)

{
  char cVar1;
  char cVar2;
  NTSTATUS NVar3;
  PUCHAR pUVar4;
  longlong lVar5;
  longlong *plVar6;
  PUCHAR pUVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  undefined8 **ppuVar11;
  ulonglong uVar12;
  undefined8 in_stack_ffffffffffffff80;
  undefined4 uVar13;
  undefined8 *local_68;
  int local_60;
  undefined8 *local_58;
  longlong local_50;
  undefined8 **local_48;
  PUCHAR local_40;
  longlong local_38;
  longlong *local_30;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  local_50 = *(longlong *)(param_1 + 0x10);
  iVar10 = 1;
  pUVar4 = (PUCHAR)0x0;
  local_40 = (PUCHAR)0x0;
  lVar5 = 0;
  local_38 = 0;
  local_68 = (undefined8 *)0x0;
  local_58 = (undefined8 *)0x0;
  plVar6 = (longlong *)0x0;
  local_30 = (longlong *)0x0;
  local_60 = *(int *)(local_50 + 0x18);
  cVar2 = '\0';
  ppuVar11 = &local_58;
  pUVar7 = *(PUCHAR *)(param_2 + 0x18);
  NVar3 = FltGetStreamContext(pUVar7,*(undefined8 *)(param_2 + 0x20));
  if ((NVar3 < 0) ||
     ((*(longlong *)(param_2 + 0x20) != 0 &&
      ((*(uint *)(*(longlong *)(param_2 + 0x20) + 0x50) >> 8 & 1) != 0)))) {
    iVar10 = 1;
  }
  else if (local_60 != 0) {
    ppuVar11 = &local_68;
    pUVar7 = *(PUCHAR *)(param_2 + 8);
    NVar3 = FltGetVolumeContext(pUVar7,*(undefined8 *)(param_2 + 0x10));
    if (-1 < NVar3) {
      uVar9 = local_60 + -1 + *(int *)(local_68 + 2) & -*(int *)(local_68 + 2);
      if (uVar9 < 0x10001) {
        pUVar7 = &gShadowBufferList;
        pUVar4 = (PUCHAR)ExAllocateFromNPagedLookasideList();
        cVar2 = '\x01';
      }
      else {
        pUVar7 = (PUCHAR)0x40;
        ppuVar11 = (undefined8 **)0x62734346;
        pUVar4 = (PUCHAR)ExAllocatePool2(0x40,uVar9);
        cVar2 = '\x02';
      }
      local_40 = pUVar4;
      cVar1 = '\0';
      if (pUVar4 == (PUCHAR)0x0) {
LAB_140002af3:
        cVar2 = cVar1;
        NVar3 = -0x3fffff66;
        iVar10 = 4;
        if ((_Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_140002cea;
        puVar8 = &AllocationFailure;
      }
      else {
        uVar12 = 0;
        ppuVar11 = (undefined8 **)0x0;
        pUVar7 = pUVar4;
        lVar5 = IoAllocateMdl(pUVar4,uVar9,0,0,0);
        local_38 = lVar5;
        cVar1 = cVar2;
        if (lVar5 == 0) goto LAB_140002af3;
        MmBuildMdlForNonPagedPool(lVar5);
        MmMdlPageContentsState(lVar5,1);
        pUVar7 = *(PUCHAR *)(local_50 + 0x38);
        if (pUVar7 == (PUCHAR)0x0) {
          local_48 = *(undefined8 ***)(local_50 + 0x30);
LAB_140002c0b:
          ppuVar11 = local_48;
          NVar3 = FCpEncEncrypt((longlong)(local_68 + 3),local_58,(PUCHAR)local_48,pUVar4,uVar9,
                                *(longlong *)(local_50 + 0x28));
          pUVar7 = &gPre2PostIoContextList;
          plVar6 = (longlong *)ExAllocateFromNPagedLookasideList();
          local_30 = plVar6;
          if (plVar6 != (longlong *)0x0) {
            *(PUCHAR *)(local_50 + 0x30) = pUVar4;
            *(longlong *)(local_50 + 0x38) = lVar5;
            pUVar7 = param_1;
            FltSetCallbackDataDirty();
            plVar6[2] = (longlong)pUVar4;
            *(char *)(plVar6 + 3) = cVar2;
            *plVar6 = (longlong)local_68;
            plVar6[1] = (longlong)local_58;
            *param_3 = (longlong)plVar6;
            iVar10 = 0;
            goto LAB_140002cea;
          }
          goto LAB_140002af3;
        }
        if ((pUVar7[10] & 5) == 0) {
          local_48 = (undefined8 **)
                     MmMapLockedPagesSpecifyCache
                               (pUVar7,0,1,0,uVar12 & 0xffffffff00000000,
                                CONCAT44(uVar13,ExDefaultMdlProtection) | 0x40000010);
        }
        else {
          local_48 = *(undefined8 ***)(pUVar7 + 0x18);
        }
        if (local_48 != (undefined8 **)0x0) goto LAB_140002c0b;
        NVar3 = -0x3fffff66;
        iVar10 = 4;
        ppuVar11 = local_48;
        if ((_Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_140002cea;
        puVar8 = &GetSystemAddressFailure;
      }
      iVar10 = 4;
      NVar3 = -0x3fffff66;
      McTemplateK0d_EtwWriteTransfer(pUVar7,puVar8,ppuVar11,0xc000009a);
      goto LAB_140002cea;
    }
    if ((_Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
      McTemplateK0d_EtwWriteTransfer(pUVar7,&GetVolumeContextFailure,ppuVar11,NVar3);
    }
    iVar10 = 4;
  }
LAB_140002cea:
  if (iVar10 != 0) {
    if (pUVar4 != (PUCHAR)0x0) {
      ppuVar11 = (undefined8 **)CONCAT71((int7)((ulonglong)ppuVar11 >> 8),cVar2);
      FCFreeShadowBuffer(pUVar7,pUVar4,cVar2);
    }
    if (lVar5 != 0) {
      IoFreeMdl(lVar5);
    }
    if (local_68 != (undefined8 *)0x0) {
      FltReleaseContext();
    }
    if (local_58 != (undefined8 *)0x0) {
      FltReleaseContext();
    }
    if (plVar6 != (longlong *)0x0) {
      ExFreeToNPagedLookasideList(&gPre2PostIoContextList,plVar6);
    }
  }
  if (iVar10 == 4) {
    *(NTSTATUS *)(param_1 + 0x18) = NVar3;
    param_1[0x20] = '\0';
    param_1[0x21] = '\0';
    param_1[0x22] = '\0';
    param_1[0x23] = '\0';
    param_1[0x24] = '\0';
    param_1[0x25] = '\0';
    param_1[0x26] = '\0';
    param_1[0x27] = '\0';
    if ((_Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer
                ((ulonglong)_Microsoft_Windows_FileCryptEnableBits,&PreWriteFailure,ppuVar11,NVar3);
    }
  }
  return iVar10;
}



===== Feature_3473298746__private_IsEnabledDeviceUsageNoInline @ 140002dac =====

ulonglong Feature_3473298746__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3473298746__private_featureState;
  if ((Feature_3473298746__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3473298746__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3473298746__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3473298746__private_IsEnabledFallback @ 140002de4 =====

void Feature_3473298746__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== McGenControlCallbackV2 @ 140002e00 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140002f10 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (FileCryptGuid_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    FileCryptGuid_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140002f44 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140009078;
  uVar2 = 0;
  if (DAT_140009078 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140009078;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(FileCryptGuid_Context,param_2,&FileCryptGuid,0,param_4,param_5);
  return;
}



===== McTemplateK0d_EtwWriteTransfer @ 140002fac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0d_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0pd_EtwWriteTransfer @ 140003008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&InvalidBufferFailure,param_3,3,local_48);
  return;
}



===== McTemplateK0zd_EtwWriteTransfer @ 140003080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_20 = 4;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&AccessCheckFailure,param_3,3,local_48);
  return;
}



===== McTemplateK0zzd_EtwWriteTransfer @ 14000311c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zzd_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  wchar_t *in_R9;
  wchar_t *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  uVar4 = 10;
  if (in_R9 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_40 = (undefined4)uVar3;
  local_3c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  if (in_stack_00000028 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    uVar4 = (ulonglong)((int)lVar1 * 2 + 2);
  }
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_30 = (undefined4)uVar4;
  local_28 = &uStack0000000000000030;
  local_2c = 0;
  local_20 = 4;
  local_48 = in_R9;
  local_38 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(uVar3,&MoveAcrossChamberFailure,uVar4,4,local_58);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400031f8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1400081df < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140003220 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400032f8 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400033dc =====

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
LAB_140003534:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140003527:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140003534;
      if (uVar5 == 5) goto LAB_140003527;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000355c =====

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
              (0x3c99fed,&Feature_3473298746_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400035d8 =====

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
                     (local_50,(uint *)&Feature_3473298746__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3c99fed,param_3 & 0xffffffff,1,&Feature_3473298746__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3c99fed);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400036c4 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400037d4 =====

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
  if ((Feature_3473298746__private_featureState & 2) != 0) {
    uVar1 = Feature_3473298746__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3473298746__private_featureState;
      if (bVar3) {
        Feature_3473298746__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3473298746__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 140003828 =====

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



===== wil_details_IsEnabledFallback @ 140003988 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3473298746__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3473298746__private_featureState,(ulonglong)param_1,
                             0x1400081a8);
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



===== wil_details_MapReportingKind @ 140003a18 =====

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



===== wil_details_RecordCachedUsage @ 140003ab8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140003c10 =====

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



===== FCpEncDecrypt @ 140003c94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS FCpEncDecrypt(longlong param_1,undefined8 *param_2,PUCHAR param_3,PUCHAR param_4,
                      int param_5,longlong param_6,uint param_7)

{
  uint uVar1;
  NTSTATUS NVar2;
  ulonglong uVar3;
  BCRYPT_KEY_HANDLE hKey;
  uint uVar4;
  undefined1 auStackY_c8 [32];
  ULONG local_78 [2];
  undefined8 *local_70;
  PUCHAR local_68;
  longlong local_60;
  longlong local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar4 = 0;
  local_78[0] = 0;
  NVar2 = 0;
  if (*(int *)(param_1 + 0xc) == 0x10) {
    local_70 = param_2;
    local_68 = param_4;
    if (param_7 == 0) {
      NVar2 = 0;
    }
    else {
      for (; param_5 != 0; param_5 = param_5 - uVar1) {
        uVar1 = *(uint *)(param_1 + 0x10);
        uVar3 = (ulonglong)uVar1;
        hKey = (BCRYPT_KEY_HANDLE)*local_70;
        local_60 = param_6;
        local_58 = param_6;
        NVar2 = BCryptDecrypt(hKey,param_3,uVar1,(void *)0x0,(PUCHAR)&local_60,
                              *(ULONG *)(param_1 + 0xc),param_4,uVar1,local_78,0);
        if (NVar2 < 0) {
          if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
            McTemplateK0d_EtwWriteTransfer(hKey,&DecryptFailure,uVar3,NVar2);
          }
          break;
        }
        uVar1 = *(uint *)(param_1 + 0x10);
        uVar3 = (ulonglong)uVar1;
        uVar4 = uVar4 + uVar1;
        if (param_7 < uVar4) {
          memset(local_68 + param_7,0,(ulonglong)(uVar4 - param_7));
          break;
        }
        param_6 = param_6 + uVar3;
        param_4 = param_4 + uVar3;
        param_3 = param_3 + uVar3;
      }
    }
  }
  else {
    NVar2 = -0x3ffffff3;
  }
  return NVar2;
}



===== FCpEncEncrypt @ 140003dd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS FCpEncEncrypt(longlong param_1,undefined8 *param_2,PUCHAR param_3,PUCHAR param_4,
                      int param_5,longlong param_6)

{
  uint cbInput;
  NTSTATUS NVar1;
  BCRYPT_KEY_HANDLE hKey;
  ulonglong uVar2;
  undefined1 auStackY_a8 [32];
  ULONG local_58 [2];
  longlong local_50;
  longlong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  NVar1 = 0;
  local_58[0] = 0;
  if (*(int *)(param_1 + 0xc) == 0x10) {
    for (; param_5 != 0; param_5 = param_5 - *(uint *)(param_1 + 0x10)) {
      cbInput = *(uint *)(param_1 + 0x10);
      uVar2 = (ulonglong)cbInput;
      hKey = (BCRYPT_KEY_HANDLE)*param_2;
      local_50 = param_6;
      local_48 = param_6;
      NVar1 = BCryptEncrypt(hKey,param_3,cbInput,(void *)0x0,(PUCHAR)&local_50,
                            *(ULONG *)(param_1 + 0xc),param_4,cbInput,local_58,0);
      if (NVar1 < 0) {
        if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
          McTemplateK0d_EtwWriteTransfer(hKey,&EncryptFailure,uVar2,NVar1);
        }
        break;
      }
      uVar2 = (ulonglong)*(uint *)(param_1 + 0x10);
      param_3 = param_3 + uVar2;
      param_4 = param_4 + uVar2;
      param_6 = param_6 + uVar2;
    }
  }
  else {
    NVar1 = -0x3ffffff3;
  }
  return NVar1;
}



===== RtlStringCbCatW @ 140003ed0 =====

undefined8 RtlStringCbCatW(short *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  uVar3 = param_2 >> 1;
  if (uVar3 - 1 < 0x7fffffff) {
    plVar2 = local_res10;
    uVar1 = RtlStringLengthWorkerW(param_1,uVar3,plVar2);
    if (-1 < (int)uVar1) {
      uVar1 = RtlStringCopyWorkerW
                        (param_1 + local_res10[0],uVar3 - local_res10[0],plVar2,param_3,0x7ffffffe);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== __GSHandlerCheck_SEH @ 140003f48 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __security_check_cookie @ 140003fe0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140004020 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140004050 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140004050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004080 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140004100 =====

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



===== __memset_repmovs @ 140004240 =====

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



===== __memset_query @ 1400042c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140004340 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004480 =====

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



===== __memset_spec_plain @ 140004500 =====

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



===== memmove @ 140004640 =====

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



===== FCDecryptWorker$fin$0 @ 1400048f0 =====

void FCDecryptWorker_fin_0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  puVar2 = *(undefined8 **)(param_2 + 0x50);
  FltReleaseContext(*puVar2);
  FltReleaseContext(puVar2[1]);
  puVar4 = &gPre2PostIoContextList;
  ExFreeToNPagedLookasideList(&gPre2PostIoContextList,puVar2);
  iVar1 = *(int *)(param_2 + 0x40);
  if (iVar1 < 0) {
    lVar3 = *(longlong *)(param_2 + 0x58);
    *(int *)(lVar3 + 0x18) = iVar1;
    *(undefined8 *)(lVar3 + 0x20) = 0;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(puVar4,&DecryptWorkerFailure,param_3,iVar1);
    }
  }
  return;
}



===== FCPostRead$fin$0 @ 14000496d =====

void FCPostRead_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  if (*(int *)(param_2 + 0x34) < 0) {
    lVar1 = *(longlong *)(param_2 + 0xa0);
    *(int *)(lVar1 + 0x18) = *(int *)(param_2 + 0x34);
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  if (*(char *)(param_2 + 0x30) != '\0') {
    puVar2 = *(undefined8 **)(param_2 + 0xb0);
    FltReleaseContext(*puVar2);
    FltReleaseContext(puVar2[1]);
    ExFreeToNPagedLookasideList(&gPre2PostIoContextList,puVar2);
    if (*(longlong *)(param_2 + 0x38) != 0) {
      FltFreeGenericWorkItem();
    }
    if (*(longlong *)(param_2 + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x40),0x63644346);
    }
  }
  return;
}



===== FCPreRead$fin$0 @ 140004a0e =====

void FCPreRead_fin_0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = *(int *)(param_2 + 0x20);
  if (iVar1 != 0) {
    if (*(longlong *)(param_2 + 0x30) != 0) {
      ExFreeToNPagedLookasideList(&gPre2PostIoContextList);
    }
    if (*(longlong *)(param_2 + 0x88) != 0) {
      FltReleaseContext();
    }
    if (*(longlong *)(param_2 + 0x28) != 0) {
      FltReleaseContext();
    }
  }
  if (iVar1 == 4) {
    lVar2 = *(longlong *)(param_2 + 0x70);
    *(undefined4 *)(lVar2 + 0x18) = *(undefined4 *)(param_2 + 0x24);
    *(undefined8 *)(lVar2 + 0x20) = 0;
  }
  return;
}



===== FCPreWrite$fin$0 @ 140004a8d =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FCPreWrite_fin_0(undefined *param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  char cVar4;
  undefined7 uVar5;
  
  cVar4 = (char)param_3;
  uVar5 = (undefined7)((ulonglong)param_3 >> 8);
  iVar1 = *(int *)(param_2 + 0x34);
  if (iVar1 != 0) {
    if (*(longlong *)(param_2 + 0x68) != 0) {
      cVar4 = *(char *)(param_2 + 0x30);
      FCFreeShadowBuffer(param_1,*(longlong *)(param_2 + 0x68),cVar4);
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      IoFreeMdl();
    }
    if (*(longlong *)(param_2 + 0x40) != 0) {
      FltReleaseContext();
    }
    param_1 = *(undefined **)(param_2 + 0x50);
    if (param_1 != (undefined *)0x0) {
      FltReleaseContext();
    }
    if (*(longlong *)(param_2 + 0x78) != 0) {
      param_1 = &gPre2PostIoContextList;
      ExFreeToNPagedLookasideList();
    }
  }
  if (iVar1 == 4) {
    uVar2 = *(undefined4 *)(param_2 + 0x38);
    lVar3 = *(longlong *)(param_2 + 0xb0);
    *(undefined4 *)(lVar3 + 0x18) = uVar2;
    *(undefined8 *)(lVar3 + 0x20) = 0;
    if ((_Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(param_1,&PreWriteFailure,CONCAT71(uVar5,cVar4),uVar2);
    }
  }
  return;
}



===== FCCleanupStreamContext @ 14000d010 =====

void FCCleanupStreamContext(undefined8 *param_1)

{
  if ((short *)param_1[3] != (short *)0x0) {
    FCpFreeChamberId((short *)param_1[3]);
    param_1[3] = 0;
  }
  FCpEncStreamCleanup(param_1);
  return;
}



===== FCCleanupVolumeContext @ 14000d050 =====

void FCCleanupVolumeContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 8),0x766e4346);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if (*(char *)(param_1 + 0x30) != '\0') {
    FCpEncVolumeCleanup((undefined8 *)(param_1 + 0x18));
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  return;
}



===== FCFilterUnload @ 14000d0a0 =====

undefined8 FCFilterUnload(void)

{
  StSecDeinitialize();
  FltUnregisterFilter(gFilterHandle);
  ExDeleteNPagedLookasideList(&gPre2PostIoContextList);
  ExDeleteNPagedLookasideList(&gPre2PostCreateContextList);
  ExDeleteNPagedLookasideList(&gShadowBufferList);
  if (DAT_140009718 != 0) {
    ExFreePoolWithTag(DAT_140009718,0x6e694346);
  }
  McGenEventUnregister_EtwUnregister();
  wil_UninitializeFeatureStaging();
  return 0;
}



===== FCInstanceQueryTeardown @ 14000d130 =====

undefined8 FCInstanceQueryTeardown(void)

{
  return 0;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14000d13c =====

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



===== wil_UninitializeFeatureStaging @ 14000d208 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000d260 =====

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
      goto LAB_14000d2bd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000d2bd;
    }
  }
  uVar1 = 0x206;
LAB_14000d2bd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000d2c8 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000d380 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000d3b8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000d43a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000d43a;
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
LAB_14000d43a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000d490 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000d4f0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000d50c =====

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



===== FCpEncStreamCleanup @ 14000d5c0 =====

void FCpEncStreamCleanup(undefined8 *param_1)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
  if ((BCRYPT_KEY_HANDLE)*param_1 != (BCRYPT_KEY_HANDLE)0x0) {
    BCryptDestroyKey((BCRYPT_KEY_HANDLE)*param_1);
    *param_1 = 0;
  }
  if ((undefined1 *)param_1[1] != (undefined1 *)0x0) {
    puVar2 = (undefined1 *)param_1[1];
    for (uVar1 = (ulonglong)*(uint *)(param_1 + 2); uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    ExFreePoolWithTag(param_1[1],0x72434346);
    param_1[1] = 0;
  }
  return;
}



===== FCpEncStreamStart @ 14000d624 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FCpEncStreamStart(undefined8 *param_1,short *param_2,int param_3,BCRYPT_KEY_HANDLE *param_4)

{
  ULONG cbKeyObject;
  uint uVar1;
  NTSTATUS NVar2;
  PUCHAR pbSecret;
  undefined8 uVar3;
  short *psVar4;
  ulonglong uVar5;
  undefined *puVar6;
  PUCHAR pUVar7;
  
  cbKeyObject = *(ULONG *)(param_1 + 1);
  *(ULONG *)(param_4 + 2) = cbKeyObject;
  pUVar7 = (PUCHAR)0x72434346;
  pbSecret = (PUCHAR)ExAllocatePool2(0x40,*(undefined4 *)((longlong)param_1 + 0x14));
  if (pbSecret == (PUCHAR)0x0) {
LAB_14000d686:
    NVar2 = -0x3fffff66;
  }
  else {
    uVar1 = *(uint *)((longlong)param_1 + 0x14);
    psVar4 = (short *)(ulonglong)uVar1;
    if ((param_2 == (short *)0x0) || (1 < param_3 - 1U)) {
      NVar2 = -0x3ffffff3;
    }
    else {
      psVar4 = param_2;
      pUVar7 = pbSecret;
      uVar3 = StSecpGetChamberProfileKey(param_2,param_3,pbSecret,uVar1);
      NVar2 = (NTSTATUS)uVar3;
      if ((NVar2 < 0) && (NVar2 == -0x3fffffcc)) {
        pUVar7 = pbSecret;
        NVar2 = StSecpDeriveChamberProfileKey(param_2,param_3,pbSecret,uVar1);
        psVar4 = param_2;
      }
    }
    if (NVar2 < 0) {
      if ((_Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_14000d78a;
      puVar6 = &GetChamberProfileEncryptionKeyFailure;
    }
    else {
      pUVar7 = (PUCHAR)ExAllocatePool2(0x40,cbKeyObject,0x72434346);
      param_4[1] = pUVar7;
      if (pUVar7 == (PUCHAR)0x0) goto LAB_14000d686;
      NVar2 = BCryptGenerateSymmetricKey
                        ((BCRYPT_ALG_HANDLE)*param_1,param_4,pUVar7,cbKeyObject,pbSecret,
                         *(ULONG *)((longlong)param_1 + 0x14),0);
      if ((-1 < NVar2) ||
         (psVar4 = (short *)(ulonglong)_Microsoft_Windows_FileCryptEnableBits,
         (_Microsoft_Windows_FileCryptEnableBits & 1) == 0)) goto LAB_14000d78a;
      puVar6 = &GenerateSymmetricKeyFailure;
    }
    McTemplateK0d_EtwWriteTransfer(psVar4,puVar6,pUVar7,NVar2);
  }
LAB_14000d78a:
  if (pbSecret != (PUCHAR)0x0) {
    pUVar7 = pbSecret;
    for (uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0x14); uVar5 != 0; uVar5 = uVar5 - 1) {
      *pUVar7 = '\0';
      pUVar7 = pUVar7 + 1;
    }
    ExFreePoolWithTag(pbSecret,0x72434346);
  }
  if (NVar2 < 0) {
    FCpEncStreamCleanup(param_4);
  }
  return NVar2;
}



===== FCpEncVolumeCleanup @ 14000d7dc =====

void FCpEncVolumeCleanup(undefined8 *param_1)

{
  if ((BCRYPT_ALG_HANDLE)*param_1 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider((BCRYPT_ALG_HANDLE)*param_1,0);
  }
  return;
}



===== FCpEncVolumeStart @ 14000d804 =====

NTSTATUS FCpEncVolumeStart(BCRYPT_ALG_HANDLE *param_1)

{
  uint uVar1;
  NTSTATUS NVar2;
  undefined4 local_res8 [2];
  ULONG local_res10 [2];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  NVar2 = BCryptOpenAlgorithmProvider(param_1,L"AES",(LPCWSTR)0x0,1);
  if ((-1 < NVar2) &&
     (NVar2 = BCryptGetProperty(*param_1,L"BlockLength",(PUCHAR)((longlong)param_1 + 0xc),4,
                                local_res10,0), -1 < NVar2)) {
    uVar1 = *(uint *)((longlong)param_1 + 0xc);
    if ((uVar1 == 0) || ((uVar1 & uVar1 - 1) != 0)) {
      NVar2 = -0x3ffffe8d;
    }
    else {
      NVar2 = BCryptGetProperty(*param_1,L"ObjectLength",(PUCHAR)local_res8,4,local_res10,0);
      if (-1 < NVar2) {
        *(undefined4 *)(param_1 + 1) = local_res8[0];
        NVar2 = BCryptSetProperty(*param_1,L"ChainingMode",(PUCHAR)L"ChainingModeCBC",0x20,0);
        if (-1 < NVar2) {
          return 0;
        }
      }
    }
  }
  FCpEncVolumeCleanup(param_1);
  return NVar2;
}



===== StSecDeinitialize @ 14000d924 =====

void StSecDeinitialize(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  StSecpCacheDeinitialize();
  if (g_HmacHashProvider != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(g_HmacHashProvider,0);
    g_HmacHashProvider = (BCRYPT_ALG_HANDLE)0x0;
  }
  puVar5 = auStack_28;
  while (puVar4 = g_StSecSecurityDescriptorCacheListHead,
        (undefined8 **)g_StSecSecurityDescriptorCacheListHead !=
        &g_StSecSecurityDescriptorCacheListHead) {
    if (((undefined8 **)g_StSecSecurityDescriptorCacheListHead[1] !=
         &g_StSecSecurityDescriptorCacheListHead) ||
       (puVar2 = (undefined8 *)*g_StSecSecurityDescriptorCacheListHead,
       (undefined8 *)puVar2[1] != g_StSecSecurityDescriptorCacheListHead)) goto LAB_14000da06;
    puVar1 = g_StSecSecurityDescriptorCacheListHead + 2;
    g_StSecSecurityDescriptorCacheListHead = puVar2;
    puVar2[1] = &g_StSecSecurityDescriptorCacheListHead;
    RtlFreeUnicodeString(puVar1);
    StSecFree(puVar4[4]);
    StSecFree(puVar4[5]);
    StSecFree((longlong)puVar4);
  }
  while (puVar4 = g_StSecFolderPropertyCacheListHead,
        (undefined8 **)g_StSecFolderPropertyCacheListHead != &g_StSecFolderPropertyCacheListHead) {
    if (((undefined8 **)g_StSecFolderPropertyCacheListHead[1] != &g_StSecFolderPropertyCacheListHead
        ) || (puVar2 = (undefined8 *)*g_StSecFolderPropertyCacheListHead,
             (undefined8 *)puVar2[1] != g_StSecFolderPropertyCacheListHead)) goto LAB_14000da06;
    puVar1 = g_StSecFolderPropertyCacheListHead + 2;
    g_StSecFolderPropertyCacheListHead = puVar2;
    puVar2[1] = &g_StSecFolderPropertyCacheListHead;
    RtlFreeUnicodeString(puVar1);
    StSecFree(puVar4[5]);
    StSecFree((longlong)puVar4);
  }
LAB_14000da0d:
  if (g_HashProvider != (BCRYPT_ALG_HANDLE)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x14000da22;
    BCryptCloseAlgorithmProvider(g_HashProvider,0);
    g_HashProvider = (BCRYPT_ALG_HANDLE)0x0;
  }
  if (g_DebugProfileKey != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x14000da42;
    ZwClose();
  }
  return;
LAB_14000da06:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar5 = auStack_20;
  goto LAB_14000da0d;
}



===== StSecInitialize @ 14000da5c =====

void StSecInitialize(ulonglong param_1)

{
  longlong lVar1;
  NTSTATUS NVar2;
  undefined8 uVar3;
  ulonglong local_res8;
  ULONG local_res10 [6];
  
  lVar1 = gFilterHandle;
  local_res8 = param_1 & 0xffffffff00000000;
  local_res10[0] = 0;
  if ((g_HashProvider == (BCRYPT_HANDLE)0x0) &&
     (NVar2 = BCryptOpenAlgorithmProvider(&g_HashProvider,L"SHA256",(LPCWSTR)0x0,0), NVar2 < 0)) {
    return;
  }
  NVar2 = BCryptGetProperty(g_HashProvider,L"ObjectLength",(PUCHAR)&g_cbHashObject,4,
                            (ULONG *)&local_res8,0);
  if ((-1 < NVar2) &&
     (NVar2 = BCryptGetProperty(g_HashProvider,L"HashDigestLength",(PUCHAR)&g_cbHashValue,4,
                                (ULONG *)&local_res8,0), -1 < NVar2)) {
    if ((g_HmacHashProvider == (BCRYPT_HANDLE)0x0) &&
       (NVar2 = BCryptOpenAlgorithmProvider(&g_HmacHashProvider,L"SHA256",(LPCWSTR)0x0,8), NVar2 < 0
       )) {
      return;
    }
    NVar2 = BCryptGetProperty(g_HmacHashProvider,L"HashDigestLength",(PUCHAR)&g_cbHashOutputLength,4
                              ,local_res10,0);
    if (((-1 < NVar2) &&
        (NVar2 = BCryptGetProperty(g_HmacHashProvider,L"ObjectLength",(PUCHAR)&g_cbHashObjectLength,
                                   4,local_res10,0), -1 < NVar2)) &&
       (uVar3 = StSecpCacheInitialize(lVar1), -1 < (int)uVar3)) {
      StSecpInitializePolicyCache();
    }
  }
  return;
}



===== StSecpCheckConditionalPolicy @ 14000dbec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong StSecpCheckConditionalPolicy(undefined8 param_1,ushort *param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  undefined4 *local_e0;
  undefined4 local_d8 [2];
  longlong local_d0 [2];
  wchar_t *local_c0;
  longlong local_b8;
  wchar_t *local_b0;
  longlong local_a8;
  wchar_t *local_a0;
  ushort local_98 [4];
  longlong lStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  local_d0[1] = 0x280026;
  local_a8 = 0x240022;
  local_c0 = L"<PackageFamilyName>";
  local_b8 = 0x180016;
  local_a0 = L"<PackageFullName>";
  local_b0 = L"<ProductId>";
  local_d0[0] = 0;
  local_d8[0] = 0;
  local_68 = 0;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  lStack_90 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = (undefined8 *)0x0;
  uStack_70 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = RtlCompareUnicodeString(0,local_d0 + 1,1);
  if (iVar1 == 0) {
LAB_14000dce4:
    if (g_DebugProfileKey == 0) {
      RtlInitUnicodeString
                (&local_58,
                 L"\\REGISTRY\\MACHINE\\Software\\Microsoft\\SecurityManager\\StorageCardProfiles\\Chambers"
                );
      uStack_80 = 0;
      local_78 = &local_58;
      local_88 = CONCAT44(local_88._4_4_,0x30);
      uStack_70 = CONCAT44(uStack_70._4_4_,0x240);
      local_68 = 0;
      uStack_60 = 0;
      uVar2 = ZwOpenKey(local_d0,0x80000000,&local_88);
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        LOCK();
        bVar5 = g_DebugProfileKey == 0;
        if (bVar5) {
          g_DebugProfileKey = local_d0[0];
        }
        UNLOCK();
        if (!bVar5) {
          ZwClose(local_d0[0]);
        }
        goto LAB_14000dd79;
      }
    }
    else {
LAB_14000dd79:
      local_e0 = local_d8;
      local_e8 = 0x10;
      uVar2 = ZwQueryValueKey(g_DebugProfileKey,param_2,2,&local_48);
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        *param_3 = uStack_40._4_4_ != 0;
        goto LAB_14000ddb9;
      }
    }
    if (uVar2 != 0xc0000034) goto LAB_14000ddb9;
  }
  else {
    iVar1 = RtlCompareUnicodeString(param_1,local_d0 + 3,1);
    if (iVar1 == 0) goto LAB_14000dce4;
    iVar1 = RtlCompareUnicodeString(param_1,local_d0 + 5,1);
    if (iVar1 == 0) {
      uVar3 = StSecpPackageFamilyNameFromFullName(param_2,(short *)local_98);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14000ddb9;
      param_2 = local_98;
      goto LAB_14000dce4;
    }
  }
  uVar4 = 0;
  *param_3 = 0;
LAB_14000ddb9:
  StSecFree(lStack_90);
  return uVar4;
}



===== StSecpDeriveChamberProfileKey @ 14000dde8 =====

int StSecpDeriveChamberProfileKey(short *param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  PUCHAR pbHashObject;
  PUCHAR pbHashObject_00;
  PUCHAR pbOutput;
  PUCHAR pbOutput_00;
  BCRYPT_HASH_HANDLE *phHash;
  PUCHAR _Src;
  short *pbInput;
  uint local_res20 [2];
  BCRYPT_HASH_HANDLE local_58;
  BCRYPT_HASH_HANDLE local_50;
  PUCHAR local_48;
  longlong local_40;
  
  local_48 = (PUCHAR)0x0;
  pbHashObject = (PUCHAR)0x0;
  local_res20[0] = 0;
  pbHashObject_00 = (PUCHAR)0x0;
  local_58 = (BCRYPT_HASH_HANDLE)0x0;
  pbOutput = (PUCHAR)0x0;
  local_50 = (BCRYPT_HASH_HANDLE)0x0;
  pbOutput_00 = (PUCHAR)0x0;
  local_40 = 0;
  if (g_cbHashOutputLength < param_4) {
    return -0x3ffffff3;
  }
  iVar1 = StSecpGetMasterKey((longlong *)&local_48,local_res20);
  if (iVar1 < 0) goto LAB_14000e07d;
  pbHashObject = (PUCHAR)ExAllocatePool2(0x40,g_cbHashObjectLength,0x6e537453);
  if (pbHashObject != (PUCHAR)0x0) {
    phHash = &local_58;
    iVar1 = BCryptCreateHash(g_HmacHashProvider,phHash,pbHashObject,g_cbHashObjectLength,local_48,
                             local_res20[0],0);
    if ((iVar1 < 0) ||
       (pbInput = param_1, iVar1 = RtlStringCbLengthW(param_1,phHash,&local_40), iVar1 < 0))
    goto LAB_14000e07d;
    iVar1 = BCryptHashData(local_58,(PUCHAR)pbInput,(ULONG)local_40,0);
    if (iVar1 < 0) goto LAB_14000e07d;
    pbHashObject_00 = (PUCHAR)ExAllocatePool2(0x40,g_cbHashObjectLength,0x6e537453);
    if (pbHashObject_00 != (PUCHAR)0x0) {
      iVar1 = BCryptDuplicateHash(local_58,&local_50,pbHashObject_00,g_cbHashObjectLength,0);
      if ((iVar1 < 0) || (iVar1 = BCryptHashData(local_58,(PUCHAR)L"Install",0xe,0), iVar1 < 0))
      goto LAB_14000e07d;
      pbOutput = (PUCHAR)ExAllocatePool2(0x40,g_cbHashOutputLength,0x6e537453);
      if (pbOutput != (PUCHAR)0x0) {
        iVar1 = BCryptFinishHash(local_58,pbOutput,g_cbHashOutputLength,0);
        if ((iVar1 < 0) || (iVar1 = BCryptHashData(local_50,(PUCHAR)L"Data",8,0), iVar1 < 0))
        goto LAB_14000e07d;
        pbOutput_00 = (PUCHAR)ExAllocatePool2(0x40,g_cbHashOutputLength,0x6e537453);
        if (pbOutput_00 != (PUCHAR)0x0) {
          iVar1 = BCryptFinishHash(local_50,pbOutput_00,g_cbHashOutputLength,0);
          if ((-1 < iVar1) &&
             (iVar1 = StSecpAddChamberProfileKey(param_1,pbOutput,pbOutput_00,param_4), -1 < iVar1))
          {
            if (param_2 == 1) {
              _Src = pbOutput;
            }
            else {
              if (param_2 != 2) goto LAB_14000e07d;
              _Src = pbOutput_00;
            }
            memmove(param_3,_Src,(ulonglong)param_4);
          }
          goto LAB_14000e07d;
        }
      }
    }
  }
  iVar1 = -0x3fffffe9;
LAB_14000e07d:
  if (local_58 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_58);
  }
  if (local_50 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_50);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    StSecpFreeNonPaged(pbHashObject,(ulonglong)g_cbHashObjectLength);
  }
  if (pbHashObject_00 != (PUCHAR)0x0) {
    StSecpFreeNonPaged(pbHashObject_00,(ulonglong)g_cbHashObjectLength);
  }
  if (pbOutput != (PUCHAR)0x0) {
    StSecpFreeNonPaged(pbOutput,(ulonglong)g_cbHashOutputLength);
  }
  if (pbOutput_00 != (PUCHAR)0x0) {
    StSecpFreeNonPaged(pbOutput_00,(ulonglong)g_cbHashOutputLength);
  }
  return iVar1;
}



===== StSecpFreeNonPaged @ 14000e114 =====

void StSecpFreeNonPaged(undefined1 *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  
  if (param_1 != (undefined1 *)0x0) {
    puVar2 = param_1;
    for (uVar1 = param_2 & 0xffffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    ExFreePoolWithTag(param_1,0x6e537453);
  }
  return;
}



===== StSecpGetSidFromPackageFullName @ 14000e14c =====

ulonglong StSecpGetSidFromPackageFullName(ushort *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  short local_18 [4];
  longlong lStack_10;
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  lStack_10 = 0;
  uVar1 = StSecpPackageFamilyNameFromFullName(param_1,local_18);
  if (-1 < (int)uVar1) {
    uVar1 = StSecpGetSidFromPackageFamilyName(local_18,param_2);
  }
  StSecFree(lStack_10);
  return uVar1 & 0xffffffff;
}



===== StSecpGetSidFromProductId @ 14000e1a0 =====

int StSecpGetSidFromProductId(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  ushort local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  iVar1 = RtlUpcaseUnicodeString(local_18,param_1,1);
  if (-1 < iVar1) {
    iVar1 = StSecpGetAppSid(local_18,param_2);
  }
  RtlFreeUnicodeString(local_18);
  return iVar1;
}



===== StSecpInitializePolicyCache @ 14000e208 =====

ulonglong StSecpInitializePolicyCache(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong local_res8;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_48 = 0x920090;
  local_40 = L"\\Registry\\Machine\\System\\ControlSet001\\Control\\StSec\\SecurityDescriptors";
  local_38 = 0x30;
  DAT_1400096e8 = &g_StSecSecurityDescriptorCacheListHead;
  g_StSecSecurityDescriptorCacheListHead = &g_StSecSecurityDescriptorCacheListHead;
  local_28 = &local_48;
  local_20 = 0x240;
  local_res8 = 0;
  local_30 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = ZwOpenKey(&local_res8,0x20019,&local_38);
  uVar3 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar2 = StSecpGetSecurityDescriptorPolicy(local_res8);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      ZwClose(local_res8);
      RtlInitUnicodeString
                (&local_48,
                 L"\\Registry\\Machine\\System\\ControlSet001\\Control\\StSec\\FolderProperties");
      local_res8 = 0;
      DAT_1400096f8 = &g_StSecFolderPropertyCacheListHead;
      g_StSecFolderPropertyCacheListHead = &g_StSecFolderPropertyCacheListHead;
      local_28 = &local_48;
      local_38 = CONCAT44(local_38._4_4_,0x30);
      local_30 = 0;
      local_20 = CONCAT44(local_20._4_4_,0x240);
      local_18 = 0;
      uStack_10 = 0;
      uVar1 = ZwOpenKey(&local_res8,0x20019,&local_38);
      if ((int)uVar1 < 0) {
        uVar3 = (ulonglong)uVar1;
        if (uVar1 == 0xc0000034) {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = StSecpGetFolderPropertyPolicy(local_res8);
        uVar3 = uVar3 & 0xffffffff;
      }
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return uVar3;
}



===== StSecpOpenMasterKeyHandle @ 14000e36c =====

int StSecpOpenMasterKeyHandle(longlong *param_1)

{
  int iVar1;
  longlong local_res10;
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
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,L"\\REGISTRY\\MACHINE\\Software\\Microsoft\\StorageSec\\Encrypt");
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&local_res10,0xf003f,&local_38);
  if (-1 < iVar1) {
    *param_1 = local_res10;
    local_res10 = 0;
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== StSecpPackageFamilyNameFromFullName @ 14000e42c =====

undefined8 StSecpPackageFamilyNameFromFullName(ushort *param_1,short *param_2)

{
  short sVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  short *psVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  int iVar11;
  
  uVar7 = (uint)(*param_1 >> 1);
  uVar9 = 0;
  uVar10 = 0;
  iVar11 = 0;
  lVar2 = ExAllocatePool2(0x100,0x82,0x70537453);
  if (lVar2 == 0) {
    uVar6 = 0xc0000017;
  }
  else {
    while( true ) {
      uVar8 = (uint)uVar9;
      if ((uVar7 <= uVar8) ||
         (sVar1 = *(short *)(uVar9 * 2 + *(longlong *)(param_1 + 4)), sVar1 == 0x5f)) break;
      if (0x3f < uVar10) goto LAB_14000e4f0;
      uVar3 = (ulonglong)uVar10;
      uVar10 = uVar10 + 1;
      uVar9 = (ulonglong)(uVar8 + 1);
      *(short *)(lVar2 + uVar3 * 2) = sVar1;
    }
    if (uVar8 != uVar7) {
      if (uVar7 <= uVar8) goto LAB_14000e4ff;
      psVar5 = (short *)(*(longlong *)(param_1 + 4) + uVar9 * 2);
      do {
        if ((*psVar5 == 0x5f) && (iVar11 = iVar11 + 1, iVar11 == 4)) break;
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
        psVar5 = psVar5 + 1;
      } while (uVar8 < uVar7);
      uVar8 = (uint)uVar9;
      uVar3 = uVar9;
      if (uVar8 != uVar7) {
        while( true ) {
          if (uVar7 <= uVar8) {
            sVar1 = (short)uVar10 * 2;
            *(undefined2 *)(lVar2 + (ulonglong)uVar10 * 2) = 0;
            *param_2 = sVar1;
            param_2[1] = sVar1 + 2;
            *(longlong *)(param_2 + 4) = lVar2;
            return 0;
          }
          if (0x3f < uVar10) break;
          uVar4 = (ulonglong)uVar10;
          uVar10 = uVar10 + 1;
          uVar9 = (ulonglong)((int)uVar3 + 1);
          *(undefined2 *)(lVar2 + uVar4 * 2) =
               *(undefined2 *)(*(longlong *)(param_1 + 4) + uVar3 * 2);
LAB_14000e4ff:
          uVar8 = (uint)uVar9;
          uVar3 = uVar9;
        }
      }
    }
LAB_14000e4f0:
    uVar6 = 0xc000090b;
    StSecFree(lVar2);
  }
  return uVar6;
}



===== StSecpReadSealedKeyBlob @ 14000e568 =====

int StSecpReadSealedKeyBlob(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res20 = 0;
  lVar3 = 0;
  local_res18[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = StSecpOpenMasterKeyHandle(&local_res20);
  if (-1 < iVar2) {
    RtlInitUnicodeString(&local_48,L"MK");
    iVar2 = ZwQueryValueKey(local_res20,&local_48,2,0,local_res18[0],local_res18);
    if ((iVar2 == -0x7ffffffb) || (iVar2 == -0x3fffffdd)) {
      lVar3 = ExAllocatePool2(0x100,local_res18[0],0x70537453);
      if (lVar3 != 0) {
        iVar2 = ZwQueryValueKey(local_res20,&local_48,2,lVar3,local_res18[0],local_res18);
        if (iVar2 < 0) goto LAB_14000e698;
        uVar1 = *(uint *)(lVar3 + 8);
        _Dst = (void *)ExAllocatePool2(0x100,uVar1,0x70537453);
        if (_Dst != (void *)0x0) {
          memmove(_Dst,(void *)(lVar3 + 0xc),(ulonglong)uVar1);
          *param_2 = uVar1;
          *param_1 = _Dst;
          goto LAB_14000e698;
        }
      }
      iVar2 = -0x3fffffe9;
    }
  }
LAB_14000e698:
  if (local_res20 != 0) {
    ZwClose(local_res20);
  }
  if (lVar3 != 0) {
    StSecFree(lVar3);
  }
  return iVar2;
}



===== StSecpWriteSealedKeyBlob @ 14000e6d8 =====

int StSecpWriteSealedKeyBlob(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  longlong local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = StSecpOpenMasterKeyHandle(local_res18);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,L"MK");
    iVar1 = ZwSetValueKey(local_res18[0],&local_18,0,3,param_1,param_2);
    if (-1 < iVar1) {
      iVar1 = ZwFlushKey(local_res18[0]);
    }
  }
  if (local_res18[0] != 0) {
    ZwClose(local_res18[0]);
  }
  return iVar1;
}



===== StSecpAddChamberProfileKey @ 14000e794 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int StSecpAddChamberProfileKey(short *param_1,void *param_2,void *param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  undefined8 uVar5;
  undefined1 *_Dst;
  undefined1 *_Dst_00;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong _Size;
  bool bVar9;
  char local_78 [8];
  ulonglong local_70 [2];
  short *psStack_60;
  undefined1 *local_58;
  undefined1 *puStack_50;
  undefined8 local_48;
  
  _Size = (ulonglong)param_4;
  local_70[0] = 0;
  local_48 = 0;
  local_70[1] = 0;
  psStack_60 = (short *)0x0;
  local_78[0] = '\0';
  local_58 = (undefined1 *)0x0;
  puStack_50 = (undefined1 *)0x0;
  _Dst = (undefined1 *)0x0;
  _Dst_00 = (undefined1 *)0x0;
  iVar2 = RtlStringCbLengthW(param_1,param_2,(longlong *)local_70);
  if (iVar2 < 0) {
    return iVar2;
  }
  uVar8 = local_70[0] + 2;
  local_70[0] = uVar8;
  psVar4 = (short *)ExAllocatePool2(0x100,uVar8,0x70537453);
  if (psVar4 == (short *)0x0) {
    return -0x3fffffe9;
  }
  uVar5 = RtlStringCbCopyW(psVar4,uVar8,(longlong)param_1);
  iVar2 = (int)uVar5;
  if (-1 < iVar2) {
    _Dst = (undefined1 *)ExAllocatePool2(0x40,_Size,0x6e537453);
    if (_Dst != (undefined1 *)0x0) {
      memmove(_Dst,param_2,_Size);
      _Dst_00 = (undefined1 *)ExAllocatePool2(0x40,_Size,0x6e537453);
      if (_Dst_00 != (undefined1 *)0x0) {
        memmove(_Dst_00,param_3,_Size);
        uVar5 = _DAT_fffff78000000320;
        local_48 = CONCAT44(local_48._4_4_,param_4);
        psStack_60 = psVar4;
        local_58 = _Dst;
        puStack_50 = _Dst_00;
        ExAcquireFastMutex(&g_StSecKeyMutex);
        puVar6 = (undefined8 *)
                 RtlInsertElementGenericTable(&g_StSecCacheGenericTable,local_70 + 1,0x28,local_78);
        if (puVar6 == (undefined8 *)0x0) {
          iVar2 = -0x3fffffff;
        }
        else {
          if (local_78[0] != '\0') {
            psVar4 = (short *)0x0;
            _Dst = (undefined1 *)0x0;
            _Dst_00 = (undefined1 *)0x0;
          }
          *puVar6 = uVar5;
        }
        uVar3 = RtlNumberGenericTableElements(&g_StSecCacheGenericTable);
        if (g_CacheMaxSize < uVar3) {
          lVar7 = RtlGetElementGenericTable(&g_StSecCacheGenericTable,0);
          lVar1 = *(longlong *)(lVar7 + 8);
          StSecpFreeNonPaged(*(undefined1 **)(lVar7 + 0x10),(ulonglong)*(uint *)(lVar7 + 0x20));
          StSecpFreeNonPaged(*(undefined1 **)(lVar7 + 0x18),(ulonglong)*(uint *)(lVar7 + 0x20));
          RtlDeleteElementGenericTable(&g_StSecCacheGenericTable,lVar7);
          StSecFree(lVar1);
        }
        ExReleaseFastMutex(&g_StSecKeyMutex);
        if (g_CacheCleanupTriggerSize < uVar3) {
          LOCK();
          bVar9 = g_WorkItemQueued == 0;
          if (bVar9) {
            g_WorkItemQueued = 1;
          }
          UNLOCK();
          if (bVar9) {
            iVar2 = FltQueueGenericWorkItem
                              (g_WorkItem,g_FilterObject,StSecpCacheCleanupWorkItem,1,0);
          }
        }
        if (psVar4 == (short *)0x0) goto LAB_14000e9f3;
        goto LAB_14000e9eb;
      }
    }
    iVar2 = -0x3fffffe9;
  }
LAB_14000e9eb:
  StSecFree((longlong)psVar4);
LAB_14000e9f3:
  if (_Dst != (undefined1 *)0x0) {
    StSecpFreeNonPaged(_Dst,(ulonglong)param_4);
  }
  if (_Dst_00 != (undefined1 *)0x0) {
    StSecpFreeNonPaged(_Dst_00,(ulonglong)param_4);
  }
  return iVar2;
}



===== StSecpCacheCleanupWorkItem @ 14000ea40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StSecpCacheCleanupWorkItem(void)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined8 local_res20;
  
  lVar2 = _DAT_fffff78000000320;
  local_res20 = 0;
  uVar4 = (ulonglong)g_CacheLifetime;
  uVar3 = KeQueryTimeIncrement();
  ExAcquireFastMutex(&g_StSecKeyMutex,(uVar4 * 10000000) % (ulonglong)uVar3);
  while( true ) {
    plVar5 = (longlong *)
             RtlEnumerateGenericTableWithoutSplaying(&g_StSecCacheGenericTable,&local_res20);
    if (plVar5 == (longlong *)0x0) break;
    if ((longlong)((uVar4 * 10000000) / (ulonglong)uVar3) < lVar2 - *plVar5) {
      lVar1 = plVar5[1];
      StSecpFreeNonPaged((undefined1 *)plVar5[2],(ulonglong)*(uint *)(plVar5 + 4));
      StSecpFreeNonPaged((undefined1 *)plVar5[3],(ulonglong)*(uint *)(plVar5 + 4));
      RtlDeleteElementGenericTable(&g_StSecCacheGenericTable,plVar5);
      StSecFree(lVar1);
      local_res20 = 0;
    }
  }
  ExReleaseFastMutex(&g_StSecKeyMutex);
  return;
}



===== StSecpCacheDeinitialize @ 14000eb3c =====

void StSecpCacheDeinitialize(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (g_WorkItem != 0) {
    FltFreeGenericWorkItem();
    g_WorkItem = 0;
  }
  if (g_FilterObject != 0) {
    g_FilterObject = 0;
  }
  ExAcquireFastMutex(&g_StSecKeyMutex);
  while( true ) {
    lVar2 = RtlEnumerateGenericTableWithoutSplaying(&g_StSecCacheGenericTable,&local_res8);
    if (lVar2 == 0) break;
    lVar1 = *(longlong *)(lVar2 + 8);
    StSecpFreeNonPaged(*(undefined1 **)(lVar2 + 0x10),(ulonglong)*(uint *)(lVar2 + 0x20));
    StSecpFreeNonPaged(*(undefined1 **)(lVar2 + 0x18),(ulonglong)*(uint *)(lVar2 + 0x20));
    RtlDeleteElementGenericTable(&g_StSecCacheGenericTable,lVar2);
    StSecFree(lVar1);
    local_res8 = 0;
  }
  ExReleaseFastMutex(&g_StSecKeyMutex);
  if (g_MasterKey != (undefined1 *)0x0) {
    StSecpFreeNonPaged(g_MasterKey,0x80);
    g_MasterKey = (undefined1 *)0x0;
  }
  return;
}



===== StSecpCacheGenericTableAllocRoutine @ 14000ec40 =====

void StSecpCacheGenericTableAllocRoutine(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePool2(0x100,param_2,0x70537453);
  return;
}



===== StSecpCacheGenericTableCompareRoutine @ 14000ec70 =====

char StSecpCacheGenericTableCompareRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = _wcsicmp(*(wchar_t **)(param_2 + 8),*(wchar_t **)(param_3 + 8));
  cVar1 = '\0';
  if (-1 < iVar2) {
    cVar1 = (iVar2 < 1) + '\x01';
  }
  return cVar1;
}



===== StSecpCacheGenericTableFreeRoutine @ 14000eca0 =====

void StSecpCacheGenericTableFreeRoutine(undefined8 param_1,longlong param_2)

{
  StSecFree(param_2);
  return;
}



===== StSecpCacheInitialize @ 14000ecb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 StSecpCacheInitialize(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined8 local_108;
  undefined8 uStack_100;
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
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  wchar_t *local_78;
  undefined4 *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_e8 = L"CacheLifetime";
  local_f8 = 0;
  local_f0 = 0x120;
  local_e0 = &g_CacheLifetime;
  local_d8 = 0x4000000;
  local_d0 = 0;
  local_b0 = L"CacheCleanupTriggerSize";
  local_a8 = &g_CacheCleanupTriggerSize;
  local_78 = L"CacheMaxSize";
  local_c8 = 4;
  local_70 = &g_CacheMaxSize;
  local_c0 = 0;
  local_b8 = 0x120;
  local_a0 = 0x4000000;
  local_98 = 0;
  local_90 = 4;
  local_88 = 0;
  local_80 = 0x120;
  local_68 = 0x4000000;
  local_60 = 0;
  local_58 = 4;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    _DAT_1400096a8 = 0;
    _g_StSecKeyMutex = 1;
    _DAT_1400096b0 = 0;
    KeInitializeEvent(&DAT_1400096b8,1,0);
    local_108 = 0;
    uStack_100 = 0;
    RtlInitUnicodeString(&local_108,L"RtlQueryRegistryValuesEx");
    pcVar2 = (code *)MmGetSystemRoutineAddress(&local_108);
    local_118 = 0;
    if (pcVar2 == (code *)0x0) {
      pcVar2 = RtlQueryRegistryValues_exref;
    }
    uVar1 = (*pcVar2)(2,L"StSec",&local_f8);
    if ((((int)uVar1 + 0x80000000U & 0x80000000) != 0) || ((int)uVar1 == -0x3fffffcc)) {
      local_118 = 0;
      RtlInitializeGenericTable
                (&g_StSecCacheGenericTable,StSecpCacheGenericTableCompareRoutine,
                 StSecpCacheGenericTableAllocRoutine,StSecpCacheGenericTableFreeRoutine);
      g_WorkItem = FltAllocateGenericWorkItem();
      if (g_WorkItem == 0) {
        uVar1 = 0xc0000017;
      }
      else {
        uVar1 = 0;
        g_FilterObject = param_1;
      }
    }
  }
  return uVar1;
}



===== StSecpGetChamberProfileKey @ 14000eeac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 StSecpGetChamberProfileKey(undefined8 param_1,int param_2,void *param_3,uint param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  void *_Src;
  undefined8 uVar3;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = _DAT_fffff78000000320;
  uVar3 = 0;
  local_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_40 = param_1;
  ExAcquireFastMutex(&g_StSecKeyMutex);
  puVar2 = (undefined8 *)RtlLookupElementGenericTable(&g_StSecCacheGenericTable,&local_48);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = uVar1;
  }
  ExReleaseFastMutex(&g_StSecKeyMutex);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc0000034;
  }
  else if (param_4 == *(uint *)(puVar2 + 4)) {
    if (param_2 == 1) {
      _Src = (void *)puVar2[2];
    }
    else {
      if (param_2 != 2) {
        return 0;
      }
      _Src = (void *)puVar2[3];
    }
    memmove(param_3,_Src,(ulonglong)param_4);
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== StSecpGetMasterKey @ 14000ef98 =====

int StSecpGetMasterKey(longlong *param_1,uint *param_2)

{
  int iVar1;
  PUCHAR pbBuffer;
  PUCHAR pUVar2;
  void *pvVar3;
  longlong *plVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_res18 [2];
  uint local_res20 [2];
  void *local_38 [2];
  
  pbBuffer = (PUCHAR)0x0;
  local_res18[0] = 0;
  uVar6 = 0x80;
  local_38[0] = (void *)0x0;
  local_res20[0] = 0x80;
  plVar4 = param_1;
  if (g_MasterKey == (PUCHAR)0x0) {
    pbBuffer = (PUCHAR)ExAllocatePool2(0x40,0x80,0x6e537453);
    if (pbBuffer == (PUCHAR)0x0) {
      return -0x3fffffe9;
    }
    iVar1 = StSecpReadSealedKeyBlob(local_38,local_res18);
    pvVar3 = local_38[0];
    if (iVar1 < 0) {
      if ((iVar1 == -0x3fffffcc) &&
         (iVar1 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,pbBuffer,0x80,2), -1 < iVar1))
      goto LAB_14000f068;
      pvVar3 = local_38[0];
    }
    else {
      iVar1 = StSecpUnsealKey(local_38[0],local_res18[0],pbBuffer,local_res20);
      if (-1 < iVar1) {
        g_MasterKeyPersisted = '\x01';
LAB_14000f068:
        pUVar2 = (PUCHAR)0x0;
        LOCK();
        if (g_MasterKey == (PUCHAR)0x0) {
          g_MasterKey = pbBuffer;
        }
        else {
          pUVar2 = g_MasterKey;
        }
        UNLOCK();
        plVar4 = (longlong *)-(ulonglong)(pUVar2 != (PUCHAR)0x0);
        pbBuffer = (PUCHAR)((ulonglong)pbBuffer & (ulonglong)plVar4);
        goto LAB_14000f083;
      }
      uVar6 = local_res20[0];
    }
  }
  else {
LAB_14000f083:
    pvVar3 = local_38[0];
    uVar6 = local_res20[0];
    if (g_MasterKeyPersisted == '\0') {
      iVar1 = StSecpSealKey(plVar4,local_res20[0],local_38[0],local_res18);
      if (iVar1 == -0x3fffffdd) {
        uVar5 = 0x100;
        pvVar3 = (void *)ExAllocatePool2(0x100,local_res18[0],0x70537453);
        if (pvVar3 == (void *)0x0) {
          iVar1 = -0x3fffffe9;
        }
        else {
          iVar1 = StSecpSealKey(uVar5,uVar6,pvVar3,local_res18);
          if ((-1 < iVar1) && (iVar1 = StSecpWriteSealedKeyBlob(pvVar3,local_res18[0]), -1 < iVar1))
          {
            g_MasterKeyPersisted = '\x01';
            goto LAB_14000f103;
          }
        }
      }
      else {
        iVar1 = -0x3fffffff;
      }
    }
    else {
LAB_14000f103:
      iVar1 = 0;
      *param_1 = (longlong)g_MasterKey;
      *param_2 = uVar6;
    }
    if (pbBuffer == (PUCHAR)0x0) goto LAB_14000f122;
  }
  StSecpFreeNonPaged(pbBuffer,(ulonglong)uVar6);
LAB_14000f122:
  if (pvVar3 != (void *)0x0) {
    StSecFree((longlong)pvVar3);
  }
  return iVar1;
}



===== StSecpSealKey @ 14000f150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 StSecpSealKey(undefined8 param_1,uint param_2,void *param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  byte *_Src;
  undefined4 uVar3;
  ulonglong _Size;
  int iVar4;
  undefined1 auStack_2c8 [32];
  int local_2a8;
  undefined2 *local_2a0;
  undefined4 *local_298;
  undefined4 local_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 local_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 local_260 [2];
  longlong local_258;
  undefined4 local_250;
  undefined4 local_24c;
  undefined2 local_248;
  undefined1 uStack_246;
  undefined1 uStack_245;
  undefined1 uStack_244;
  undefined1 uStack_243;
  undefined2 uStack_242;
  undefined2 uStack_240;
  undefined4 uStack_23e;
  byte bStack_23a;
  byte bStack_239;
  undefined8 local_238;
  undefined3 uStack_230;
  undefined1 uStack_22d;
  char cStack_22c;
  undefined1 auStack_22b [3];
  char local_228;
  undefined4 local_227 [3];
  undefined8 uStack_21b;
  undefined2 auStack_213 [229];
  ulonglong local_48;
  
  _Src = g_MasterKey;
  local_48 = __security_cookie ^ (ulonglong)auStack_2c8;
  _Size = (ulonglong)param_2;
  local_288 = 0xffff0280;
  uStack_284 = 0xffff;
  uStack_280 = 0x815301;
  uStack_27c = 0x100;
  local_278 = 0x400900;
  uStack_274 = 0x900;
  uStack_270 = 0xff000001;
  uStack_26c = 0xff0000ff;
  local_250 = 2;
  local_24c = 4;
  local_258 = 0;
  memset(&local_248,0,0x200);
  local_260[0] = 0x200;
  iVar4 = param_2 + 0x37;
  uVar3 = 0;
  bVar1 = StSecpSealKeyTestHookSet();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    if (0x80 < param_2) {
      uVar3 = 0xc000000d;
      goto LAB_14000f382;
    }
    iVar2 = Tbsi_Context_Create(&local_250,&local_258);
    if (iVar2 == 0) {
      local_238 = CONCAT44(uStack_274,local_278);
      local_248 = (undefined2)local_288;
      uStack_242 = (undefined2)((uint)uStack_284 >> 0x10);
      uStack_240 = (undefined2)uStack_280;
      uStack_23e = (undefined4)(CONCAT44(uStack_27c,uStack_280) >> 0x10);
      bStack_23a = (byte)((uint)uStack_27c >> 0x10);
      bStack_239 = (byte)((uint)uStack_27c >> 0x18);
      uStack_246 = (undefined1)((uint)iVar4 >> 0x18);
      uStack_245 = (undefined1)((uint)iVar4 >> 0x10);
      uStack_244 = (undefined1)((uint)iVar4 >> 8);
      local_228 = (char)param_2;
      auStack_22b = SUB43((uint)uStack_26c >> 8,0);
      _uStack_230 = CONCAT14(local_228 + '\x04',CONCAT13((char)(param_2 + 4 >> 8),(int3)uStack_270))
      ;
      _uStack_230 = CONCAT17((char)(param_2 >> 8),_uStack_230);
      uStack_243 = (undefined1)iVar4;
      memmove(local_227,_Src,_Size);
      *(undefined4 *)((longlong)local_227 + _Size) = 0x8000e00;
      local_298 = local_260;
      *(undefined4 *)((longlong)local_227 + _Size + 4) = 0xb00;
      *(undefined4 *)((longlong)local_227 + _Size + 8) = 0x5204;
      local_2a0 = &local_248;
      *(undefined8 *)((longlong)local_227 + _Size + 0xc) = 0x1000;
      *(undefined2 *)((longlong)auStack_213 + _Size) = 0;
      local_2a8 = iVar4;
      iVar4 = Tbsip_Submit_Command(local_258,0,200,&local_248);
      if ((iVar4 == 0) && (CONCAT22(uStack_240,uStack_242) == 0)) {
        iVar4 = bStack_239 + 2 + (uint)bStack_23a * 0x100;
        param_2 = (uint)(byte)auStack_22b[(ulonglong)(iVar4 + 0xe) - 0x1d] * 0x100 + 2 +
                  (uint)(byte)auStack_22b[(ulonglong)(iVar4 + 0xf) - 0x1d] + iVar4;
        if ((param_3 == (void *)0x0) || (*param_4 < param_2)) goto LAB_14000f227;
        _Size = (ulonglong)param_2;
        _Src = &bStack_23a;
        goto LAB_14000f21d;
      }
    }
    uVar3 = 0xc0000001;
  }
  else {
    if ((param_3 == (void *)0x0) || (*param_4 < param_2)) {
LAB_14000f227:
      uVar3 = 0xc0000023;
    }
    else {
LAB_14000f21d:
      memmove(param_3,_Src,_Size);
    }
    *param_4 = param_2;
  }
LAB_14000f382:
  if (local_258 != 0) {
    Tbsip_Context_Close();
  }
  return uVar3;
}



===== StSecpSealKeyTestHookSet @ 14000f3cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool StSecpSealKeyTestHookSet(void)

{
  int iVar1;
  code *pcVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined4 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_70 = 0x120;
  local_78 = 0;
  local_58 = 0x4000000;
  local_68 = L"SkipSealKey";
  local_50 = 0;
  local_60 = &g_SkipSealKey;
  local_48 = 4;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_88 = 0;
  uStack_80 = 0;
  RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_88);
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar2)(0,L"\\REGISTRY\\MACHINE\\Software\\Microsoft\\StorageSec\\Encrypt",&local_78,0,0
                   );
  if (iVar1 < 0) {
    g_SkipSealKey = 0;
  }
  return g_SkipSealKey != 0;
}



===== StSecpUnsealKey @ 14000f4a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 StSecpUnsealKey(void *param_1,uint param_2,void *param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_2d8 [32];
  int local_2b8;
  undefined4 *local_2b0;
  undefined4 *local_2a8;
  undefined4 local_298 [2];
  undefined4 local_290;
  undefined4 uStack_28c;
  undefined2 uStack_288;
  undefined2 uStack_286;
  undefined2 uStack_284;
  undefined2 uStack_282;
  undefined2 uStack_280;
  undefined4 uStack_27e;
  undefined2 uStack_27a;
  undefined2 uStack_278;
  longlong local_270;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_258;
  undefined1 uStack_254;
  undefined1 uStack_253;
  undefined2 uStack_252;
  undefined2 uStack_250;
  undefined2 uStack_24e;
  undefined2 uStack_24c;
  undefined1 uStack_24a;
  undefined1 uStack_249;
  undefined2 uStack_248;
  undefined4 uStack_246;
  undefined2 uStack_242;
  undefined2 uStack_240;
  undefined1 local_23e;
  undefined1 local_23d [485];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_290 = 0x280;
  uStack_28c = 0x1b00;
  uStack_288 = 0x5e01;
  uStack_282 = 0;
  uStack_280 = 0x900;
  uStack_27e = 0x9000040;
  uStack_27a = 0;
  uStack_278 = 1;
  local_268 = 2;
  local_264 = 4;
  local_270 = 0;
  memset(&local_258,0,0x200);
  local_298[0] = 0x200;
  iVar4 = param_2 + 0x1b;
  uVar3 = 0;
  bVar1 = StSecpSealKeyTestHookSet();
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    if (0x1e5 < param_2) {
      uVar3 = 0xc000000d;
      goto LAB_14000f6ea;
    }
    iVar2 = Tbsi_Context_Create(&local_268,&local_270);
    if (iVar2 == 0) {
      uStack_252 = 0;
      uStack_250 = 0x5701;
      local_258 = CONCAT13((char)((uint)iVar4 >> 0x10),CONCAT12((char)((uint)iVar4 >> 0x18),0x280));
      uStack_254 = (undefined1)((uint)iVar4 >> 8);
      uStack_24e = 0x81;
      uStack_24c = 0x100;
      uStack_24a = 0;
      uStack_249 = 0;
      uStack_248 = 0x900;
      uStack_246 = 0x9000040;
      uStack_242 = 0;
      uStack_240 = 1;
      local_23e = 0;
      uStack_253 = (undefined1)iVar4;
      memmove(local_23d,param_1,(ulonglong)param_2);
      local_2a8 = local_298;
      local_2b0 = &local_258;
      local_2b8 = iVar4;
      iVar4 = Tbsip_Submit_Command(local_270,0,200,&local_258);
      if ((iVar4 == 0) && (CONCAT22(uStack_250,uStack_252) == 0)) {
        uStack_286 = uStack_24e;
        uStack_284 = uStack_24c;
        uStack_240 = uStack_278;
        local_2a8 = local_298;
        local_2b0 = &local_258;
        local_2b8 = 0x1b;
        local_298[0] = 0x200;
        local_258 = local_290;
        uStack_254 = (undefined1)uStack_28c;
        uStack_253 = (undefined1)((uint)uStack_28c >> 8);
        uStack_252 = (undefined2)((uint)uStack_28c >> 0x10);
        uStack_250 = uStack_288;
        uStack_24a = (undefined1)uStack_282;
        uStack_249 = (undefined1)((ushort)uStack_282 >> 8);
        uStack_248 = uStack_280;
        uStack_246 = uStack_27e;
        uStack_242 = uStack_27a;
        local_23e = 0;
        iVar4 = Tbsip_Submit_Command(local_270,0,200,&local_258);
        if (iVar4 == 0) {
          param_2 = (uint)CONCAT11(uStack_24a,uStack_249);
          if ((param_3 == (void *)0x0) || (*param_4 < param_2)) goto LAB_14000f6e3;
          memmove(param_3,&uStack_248,(ulonglong)param_2);
          uVar3 = 0;
          goto LAB_14000f6e8;
        }
      }
    }
    uVar3 = 0xc0000001;
  }
  else {
    if ((param_3 == (void *)0x0) || (*param_4 < param_2)) {
LAB_14000f6e3:
      uVar3 = 0xc0000023;
    }
    else {
      memmove(param_3,param_1,(ulonglong)param_2);
    }
LAB_14000f6e8:
    *param_4 = param_2;
  }
LAB_14000f6ea:
  if (local_270 != 0) {
    Tbsip_Context_Close();
  }
  return uVar3;
}



===== FCPreSetInformation @ 14000f730 =====

undefined8 FCPreSetInformation(longlong param_1,longlong param_2,ulonglong param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if ((iVar1 == 0x41) || (iVar1 == 10)) {
    uVar2 = FCpPreRename(param_1,param_2,param_3);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== FCpPreRename @ 14000f760 =====

undefined8 FCpPreRename(longlong param_1,longlong param_2,ulonglong param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  short **ppsVar10;
  int iVar11;
  undefined8 uVar12;
  ulonglong local_res18;
  int local_res20 [2];
  int local_f0;
  short *local_e8;
  short *local_e0;
  longlong local_d8;
  short *local_d0;
  short *local_c8;
  short *local_c0;
  ulonglong local_b8;
  short *psStack_b0;
  ulonglong local_a8;
  short *psStack_a0;
  longlong local_98;
  ulonglong *local_90;
  longlong lStack_88;
  short *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong *local_68;
  longlong lStack_60;
  short *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_e8 = (short *)0x0;
  local_b8 = 0;
  psStack_b0 = (short *)0x0;
  local_a8 = 0;
  psStack_a0 = (short *)0x0;
  local_e0 = (short *)0x0;
  local_d8 = 0;
  local_98 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
  uVar12 = 1;
  psVar8 = (short *)0x0;
  local_c8 = (short *)0x0;
  psVar9 = (short *)0x0;
  local_c0 = (short *)0x0;
  local_res18 = param_3 & 0xffffffff00000000;
  local_res20[0] = 0;
  local_d0 = (short *)0x0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  ppsVar10 = &local_e8;
  iVar4 = FltGetVolumeContext(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10));
  if (-1 < iVar4) {
    if (*(char *)((longlong)local_e8 + 0x31) == '\0') goto LAB_14000fb77;
    iVar4 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),
                                &local_d0);
    if (iVar4 < 0) {
      ppsVar10 = &local_e0;
      iVar4 = FltGetFileNameInformation(param_1,0x101);
      if ((-1 < iVar4) && (iVar4 = FltParseFileNameInformation(local_e0), -1 < iVar4)) {
        uVar5 = FCpConstructFullPath((longlong)local_e0,(short *)&local_b8);
        iVar4 = (int)uVar5;
        if (-1 < iVar4) {
          bVar1 = true;
          lStack_88 = 0;
          local_80 = (short *)0x0;
          uStack_78 = 0;
          local_70 = 0;
          local_90 = &local_b8;
          ppsVar10 = (short **)0x3000;
          iVar4 = KeExpandKernelStackAndCalloutEx(FCpObtainSecurityInfoCallout,&local_90,0x3000,0,0)
          ;
          if (iVar4 < 0) {
            ppsVar10 = &local_c8;
            uVar6 = FCpObtainSecurityInfoWorker
                              ((longlong *)&local_b8,(longlong **)0x0,(longlong *)ppsVar10,
                               (undefined4 *)&local_res18);
            local_f0 = (int)local_res18;
            iVar4 = (int)uVar6;
          }
          else {
            if (lStack_88 != 0) {
              ExFreePoolWithTag(lStack_88,0x70537453);
            }
            local_c8 = local_80;
            local_res18 = CONCAT44(local_res18._4_4_,(int)uStack_78);
            local_f0 = (int)uStack_78;
            iVar4 = (int)local_70;
          }
          psVar8 = local_c8;
          if (-1 < iVar4) goto LAB_14000f953;
        }
      }
    }
    else {
      local_c8 = *(short **)(local_d0 + 0xc);
      local_f0 = *(int *)(local_d0 + 0x10);
      local_res18 = CONCAT44(local_res18._4_4_,local_f0);
LAB_14000f953:
      psVar8 = local_c8;
      ppsVar10 = *(short ***)(local_98 + 8);
      iVar4 = FltGetDestinationFileNameInformation
                        (*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20),ppsVar10,
                         local_98 + 0x14,*(undefined4 *)(local_98 + 0x10),0x101,&local_d8);
      if ((-1 < iVar4) && (iVar4 = FltParseFileNameInformation(local_d8), -1 < iVar4)) {
        uVar5 = FCpConstructFullPath(local_d8,(short *)&local_a8);
        iVar4 = (int)uVar5;
        if (-1 < iVar4) {
          bVar2 = true;
          lStack_60 = 0;
          local_58 = (short *)0x0;
          uStack_50 = 0;
          local_48 = 0;
          local_68 = &local_a8;
          ppsVar10 = (short **)0x3000;
          iVar4 = KeExpandKernelStackAndCalloutEx(FCpObtainSecurityInfoCallout,&local_68,0x3000,0,0)
          ;
          if (iVar4 < 0) {
            ppsVar10 = &local_c0;
            uVar6 = FCpObtainSecurityInfoWorker
                              ((longlong *)&local_a8,(longlong **)0x0,(longlong *)ppsVar10,
                               local_res20);
            iVar4 = (int)uVar6;
          }
          else {
            if (lStack_60 != 0) {
              ExFreePoolWithTag(lStack_60,0x70537453);
            }
            local_c0 = local_58;
            local_res20[0] = (int)uStack_50;
            iVar4 = (int)local_48;
          }
          psVar9 = local_c0;
          if ((-1 < iVar4) &&
             (((iVar11 = local_res20[0], bVar3 = FCpEqualChamberIds(psVar8,local_c0), !bVar3 ||
               (iVar11 != local_f0)) &&
              (iVar4 = -0x3fffff45, (Microsoft_Windows_FileCryptEnableBits & 2) != 0)))) {
            McTemplateK0zzd_EtwWriteTransfer();
          }
        }
      }
    }
  }
  bVar3 = bVar2;
LAB_14000fb77:
  if (local_e8 != (short *)0x0) {
    FltReleaseContext();
    local_e8 = (short *)0x0;
  }
  if (local_e0 != (short *)0x0) {
    FltReleaseFileNameInformation();
    local_e0 = (short *)0x0;
  }
  if (local_d8 != 0) {
    FltReleaseFileNameInformation();
    local_d8 = 0;
  }
  psVar7 = local_d0;
  if (local_d0 == (short *)0x0) {
    if (psVar8 != (short *)0x0) {
      FCpFreeChamberId(psVar8);
      psVar7 = psVar8;
    }
  }
  else {
    FltReleaseContext();
    local_d0 = (short *)0x0;
  }
  if (psVar9 != (short *)0x0) {
    FCpFreeChamberId(psVar9);
    psVar7 = psVar9;
  }
  if (bVar1) {
    psVar7 = psStack_b0;
    ExFreePoolWithTag(psStack_b0,0x666e4346);
    local_b8 = local_b8 & 0xffffffff00000000;
  }
  if (bVar3) {
    psVar7 = psStack_a0;
    ExFreePoolWithTag(psStack_a0,0x666e4346);
    local_a8 = local_a8 & 0xffffffff00000000;
  }
  if (iVar4 < 0) {
    *(int *)(param_1 + 0x18) = iVar4;
    *(undefined8 *)(param_1 + 0x20) = 0;
    uVar12 = 4;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(psVar7,&PreRenameFailure,ppsVar10,iVar4);
    }
  }
  return uVar12;
}



===== FCpEqualChamberIds @ 14000fcf0 =====

bool FCpEqualChamberIds(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    return param_1 == param_2;
  }
  lVar3 = (longlong)param_2 - (longlong)param_1;
  do {
    sVar1 = *param_1;
    sVar2 = *(short *)((longlong)param_1 + lVar3);
    if (sVar1 != sVar2) break;
    param_1 = param_1 + 1;
  } while (sVar2 != 0);
  return sVar1 == sVar2;
}



===== FCpConstructFullPath @ 14000fd30 =====

undefined8 FCpConstructFullPath(longlong param_1,short *param_2)

{
  ushort uVar1;
  bool bVar2;
  void *pvVar3;
  undefined8 uVar4;
  undefined2 *puVar5;
  short sVar6;
  
  uVar1 = *(ushort *)(param_1 + 0x58);
  bVar2 = true;
  sVar6 = uVar1 + 2 + *(short *)(param_1 + 0x68);
  if ((uVar1 != 0) &&
     (*(short *)(*(longlong *)(param_1 + 0x60) + -2 + (ulonglong)(uVar1 >> 1) * 2) != 0x5c)) {
    sVar6 = sVar6 + 2;
    bVar2 = false;
  }
  pvVar3 = (void *)ExAllocatePool2(0x100,sVar6,0x666e4346);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(void **)(param_2 + 4) = pvVar3;
    param_2[1] = sVar6;
    *param_2 = 0;
    memmove(pvVar3,*(void **)(param_1 + 0x70),(ulonglong)*(ushort *)(param_1 + 0x68));
    pvVar3 = (void *)((longlong)pvVar3 + (ulonglong)(*(ushort *)(param_1 + 0x68) >> 1) * 2);
    memmove(pvVar3,*(void **)(param_1 + 0x60),(ulonglong)*(ushort *)(param_1 + 0x58));
    puVar5 = (undefined2 *)((longlong)pvVar3 + (ulonglong)(*(ushort *)(param_1 + 0x58) >> 1) * 2);
    if (!bVar2) {
      *puVar5 = 0x5c;
      puVar5 = puVar5 + 1;
    }
    *puVar5 = 0;
    uVar4 = 0;
    *param_2 = sVar6 + -2;
  }
  return uVar4;
}



===== FCpObtainSecurityInfo @ 14000fe30 =====

ulonglong FCpObtainSecurityInfo
                    (longlong *param_1,longlong **param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  longlong *local_38;
  longlong *local_30;
  longlong lStack_28;
  undefined8 local_20;
  ulonglong uStack_18;
  
  local_30 = (longlong *)0x0;
  lStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_38 = param_1;
  iVar1 = KeExpandKernelStackAndCalloutEx(FCpObtainSecurityInfoCallout,&local_38,0x3000,0,0);
  if (iVar1 < 0) {
    uStack_18 = FCpObtainSecurityInfoWorker(param_1,param_2,param_3,param_4);
  }
  else {
    if (param_2 == (longlong **)0x0) {
      if (local_30 != (longlong *)0x0) {
        ExFreePoolWithTag(local_30,0x70537453);
      }
    }
    else {
      *param_2 = local_30;
    }
    *param_3 = lStack_28;
    *param_4 = (undefined4)local_20;
    uStack_18 = uStack_18 & 0xffffffff;
  }
  return uStack_18;
}



===== FCpObtainSecurityInfoWorker @ 14000ff00 =====

ulonglong FCpObtainSecurityInfoWorker
                    (longlong *param_1,longlong **param_2,longlong *param_3,undefined4 *param_4)

{
  char cVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  longlong *plVar4;
  longlong **pplVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  longlong *local_res8;
  
  uVar6 = SUB81(param_3,0);
  uVar7 = (undefined7)((ulonglong)param_3 >> 8);
  *param_3 = 0;
  local_res8 = (longlong *)0x0;
  if ((short)*param_1 == 0) {
    return 0;
  }
  pplVar5 = &local_res8;
  if (param_2 != (longlong **)0x0) {
    pplVar5 = param_2;
  }
  plVar4 = param_1;
  uVar2 = StSecGetSecurityDescriptor(param_1,(longlong)pplVar5,param_3,param_4);
  if ((param_2 == (longlong **)0x0) && (plVar4 = local_res8, local_res8 != (longlong *)0x0)) {
    ExFreePoolWithTag(local_res8,0x70537453);
  }
  if ((int)uVar2 < 0) {
    if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
      McTemplateK0d_EtwWriteTransfer
                (plVar4,&GetSecurityDescriptorFailure,CONCAT71(uVar7,uVar6),(int)uVar2);
    }
    goto LAB_14000ff61;
  }
  if (*param_3 != 0) goto LAB_14000ff61;
  if ((gFCFlags & 4) != 0) {
    *param_3 = (longlong)L"{0b7992da-c5e6-41e3-b24f-55419b997a15}";
    *param_4 = 1;
    goto LAB_14000ff61;
  }
  if ((gFCFlags & 2) == 0) goto LAB_14000ff61;
  cVar1 = RtlPrefixUnicodeString(&gMusicPath,param_1,1);
  if (cVar1 == '\0') {
    cVar1 = RtlPrefixUnicodeString(&gPicturesPath,param_1,1);
    if (cVar1 != '\0') {
      pwVar3 = L"PicturesChamber";
      goto LAB_140010017;
    }
    cVar1 = RtlPrefixUnicodeString(&gVideosPath,param_1,1);
    if (cVar1 != '\0') {
      pwVar3 = L"VideosChamber";
      goto LAB_140010017;
    }
  }
  else {
    pwVar3 = L"MusicChamber";
LAB_140010017:
    *param_3 = (longlong)pwVar3;
  }
  *param_4 = 1;
LAB_14000ff61:
  return uVar2 & 0xffffffff;
}



===== FCpObtainSecurityInfoCallout @ 140010050 =====

void FCpObtainSecurityInfoCallout(undefined8 *param_1)

{
  longlong **pplVar1;
  longlong *plVar2;
  char cVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  longlong *plVar6;
  longlong **pplVar7;
  int iVar8;
  longlong *plVar9;
  longlong *local_res8;
  
  plVar2 = (longlong *)*param_1;
  pplVar1 = (longlong **)(param_1 + 1);
  param_1[2] = 0;
  local_res8 = (longlong *)0x0;
  pplVar7 = &local_res8;
  if (pplVar1 != (longlong **)0x0) {
    pplVar7 = pplVar1;
  }
  if ((short)*plVar2 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
  plVar9 = param_1 + 2;
  plVar6 = plVar2;
  uVar4 = StSecGetSecurityDescriptor(plVar2,(longlong)pplVar7,plVar9,(undefined4 *)(param_1 + 3));
  if ((pplVar1 == (longlong **)0x0) && (plVar6 = local_res8, local_res8 != (longlong *)0x0)) {
    ExFreePoolWithTag(local_res8,0x70537453);
  }
  iVar8 = (int)uVar4;
  if (iVar8 < 0) {
    if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
      McTemplateK0d_EtwWriteTransfer(plVar6,&GetSecurityDescriptorFailure,plVar9,iVar8);
    }
    goto LAB_1400100c3;
  }
  if (param_1[2] != 0) goto LAB_1400100c3;
  if ((gFCFlags & 4) != 0) {
    pwVar5 = L"{0b7992da-c5e6-41e3-b24f-55419b997a15}";
    goto LAB_14001017b;
  }
  if ((gFCFlags & 2) == 0) goto LAB_1400100c3;
  cVar3 = RtlPrefixUnicodeString(&gMusicPath,plVar2,1);
  if (cVar3 == '\0') {
    cVar3 = RtlPrefixUnicodeString(&gPicturesPath,plVar2,1);
    if (cVar3 != '\0') {
      pwVar5 = L"PicturesChamber";
      goto LAB_14001017b;
    }
    cVar3 = RtlPrefixUnicodeString(&gVideosPath,plVar2,1);
    if (cVar3 != '\0') {
      pwVar5 = L"VideosChamber";
      goto LAB_14001017b;
    }
  }
  else {
    pwVar5 = L"MusicChamber";
LAB_14001017b:
    param_1[2] = pwVar5;
  }
  *(undefined4 *)(param_1 + 3) = 1;
LAB_1400100c3:
  *(int *)(param_1 + 4) = iVar8;
  return;
}



===== StSecGetSecurityDescriptor @ 1400101c0 =====

ulonglong StSecGetSecurityDescriptor
                    (longlong *param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  short *psVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  short *psVar6;
  ulonglong uVar7;
  short *psVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong local_res8;
  longlong local_78;
  short *psStack_70;
  ulonglong local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong local_48;
  undefined8 uStack_40;
  longlong local_38;
  short *psStack_30;
  
  local_res8 = 0;
  uVar11 = 0;
  if ((((param_1 == (longlong *)0x0) || (param_1[1] == 0)) || (param_2 == 0)) ||
     ((param_3 == (longlong *)0x0 || (param_4 == (undefined4 *)0x0)))) {
LAB_14001037a:
    uVar10 = 0xc000000d;
    goto LAB_140010331;
  }
  uVar3 = StSecpGetStorageFolderStringSecurityDescriptor((undefined4 *)param_1,&local_res8);
  uVar11 = local_res8;
  uVar10 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_140010331;
  uVar3 = SeConvertStringSecurityDescriptorToSecurityDescriptor(local_res8,1,param_2,0);
  uVar10 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_140010331;
  local_res8 = local_res8 & 0xffffffff00000000;
  local_68 = 0;
  lStack_60 = 0;
  local_38 = 0;
  psStack_30 = (short *)0x0;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  puVar5 = StSecpFindFolderPropertyPolicyElement((undefined4 *)param_1);
  psVar6 = (short *)0x0;
  lVar9 = local_78;
  psVar1 = psStack_70;
  if (puVar5 == (undefined8 *)0x0) goto LAB_140010293;
  psVar1 = (short *)puVar5[5];
  local_res8 = CONCAT44(local_res8._4_4_,*(undefined4 *)(puVar5 + 4));
  if (psVar1 == (short *)0x0) goto LAB_14001037a;
  lVar9 = 0x7fffffff;
  psVar8 = psVar1;
  do {
    if (*psVar8 == 0) break;
    psVar8 = psVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar10 = 0xc000000d;
  if (lVar9 == 0) {
    local_78 = 0;
    goto LAB_140010331;
  }
  lVar2 = -lVar9;
  local_78 = lVar2 + 0x7fffffff;
  lVar9 = 0x7fffffff - lVar9;
  if ((*psVar1 == 0x3c) && (lVar9 = local_78, psVar1[lVar2 + 0x7ffffffe] == 0x3e)) {
    local_78 = puVar5[2];
    psStack_70 = (short *)puVar5[3];
    FsRtlDissectName(&local_78,&local_58,&local_48);
    local_78 = *param_1;
    psStack_70 = (short *)param_1[1];
    FsRtlDissectName(&local_78,&local_68,&local_38);
    lVar9 = local_78;
    psVar1 = psStack_70;
    local_78 = local_48;
    psStack_70 = (short *)uStack_40;
    while (local_48 = local_78, uStack_40 = psStack_70, lStack_50 != 0) {
      FsRtlDissectName(&local_78,&local_58,&local_48);
      local_78 = local_38;
      psStack_70 = psStack_30;
      FsRtlDissectName(&local_78,&local_68,&local_38);
      lVar9 = local_78;
      psVar1 = psStack_70;
      local_78 = local_48;
      psStack_70 = (short *)uStack_40;
    }
    if (lStack_60 != 0) {
      local_78 = lVar9;
      psStack_70 = psVar1;
      iVar4 = _wcsicmp((wchar_t *)puVar5[5],L"<PackageFamilyName>");
      if ((iVar4 == 0) || (iVar4 = _wcsicmp((wchar_t *)puVar5[5],L"<ProductId>"), iVar4 == 0)) {
        psVar6 = (short *)ExAllocatePool2(0x100,(local_68 & 0xffff) + 2,0x70537453);
        if (psVar6 == (short *)0x0) {
          uVar10 = 0xc0000017;
          goto LAB_140010331;
        }
        uVar10 = RtlStringCbCopyNW(psVar6,(local_68 & 0xffff) + 2,lStack_60,local_68 & 0xffff);
        iVar4 = (int)uVar10;
        goto joined_r0x000140010317;
      }
      iVar4 = _wcsicmp((wchar_t *)puVar5[5],L"<PackageFullName>");
      if (iVar4 != 0) {
        uVar10 = 0xc0000001;
        goto LAB_140010331;
      }
      local_78 = 0;
      psStack_70 = (short *)0x0;
      uVar7 = StSecpPackageFamilyNameFromFullName((ushort *)&local_68,(short *)&local_78);
      uVar10 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) goto LAB_140010331;
      psVar6 = psStack_70;
      lVar9 = local_78;
      psVar1 = psStack_70;
    }
  }
  else {
    psVar6 = (short *)ExAllocatePool2(0x100,lVar9 * 2 + 2,0x70537453);
    if (psVar6 == (short *)0x0) {
      uVar10 = 0xc0000017;
      goto LAB_140010331;
    }
    uVar10 = RtlStringCchCopyW(psVar6,lVar2 + 0x80000000,puVar5[5]);
    iVar4 = (int)uVar10;
joined_r0x000140010317:
    lVar9 = local_78;
    psVar1 = psStack_70;
    if (iVar4 < 0) {
      uVar10 = uVar10 & 0xffffffff;
      ExFreePoolWithTag(psVar6,0x70537453);
      goto LAB_140010331;
    }
  }
LAB_140010293:
  psStack_70 = psVar1;
  local_78 = lVar9;
  uVar10 = 0;
  *param_4 = (undefined4)local_res8;
  *param_3 = (longlong)psVar6;
LAB_140010331:
  if (uVar11 != 0) {
    ExFreePoolWithTag(uVar11,0x70537453);
  }
  return uVar10;
}



===== StSecpGetStorageFolderStringSecurityDescriptor @ 140010560 =====

int StSecpGetStorageFolderStringSecurityDescriptor(undefined4 *param_1,undefined8 *param_2)

{
  wchar_t wVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  short *psVar7;
  undefined8 uVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  ushort *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong *plVar14;
  longlong lVar15;
  uint uVar16;
  char local_res18 [8];
  longlong local_res20;
  ulonglong local_98;
  short *psStack_90;
  ushort local_88 [4];
  longlong lStack_80;
  longlong local_78 [2];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  local_res20 = 0;
  local_98 = 0;
  psStack_90 = (short *)0x0;
  uVar16 = 0;
  pwVar5 = (wchar_t *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_res18[0] = '\0';
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  lStack_80 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  puVar4 = StSecpFindSecurityDescriptorPolicyElement(param_1);
  if (puVar4 == (undefined8 *)0x0) {
    return -0x3fffffcc;
  }
  psVar7 = (short *)puVar4[4];
  if (psVar7 == (short *)0x0) {
    return -0x3ffffff3;
  }
  lVar9 = 0x7fffffff;
  do {
    if (*psVar7 == 0) break;
    psVar7 = psVar7 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (lVar9 == 0) {
    return -0x3ffffff3;
  }
  iVar3 = 0;
  if (lVar9 == 0) {
    return 0;
  }
  local_48 = *(undefined4 *)(puVar4 + 2);
  uStack_44 = *(undefined4 *)((longlong)puVar4 + 0x14);
  uStack_40 = *(undefined4 *)(puVar4 + 3);
  uStack_3c = *(undefined4 *)((longlong)puVar4 + 0x1c);
  uVar13 = (0x7fffffff - lVar9) * 2 + 2;
  FsRtlDissectName(&local_48,&local_98,&local_68);
  local_48 = *param_1;
  uStack_44 = param_1[1];
  uStack_40 = param_1[2];
  uStack_3c = param_1[3];
  while( true ) {
    puVar11 = local_88;
    FsRtlDissectName(&local_48,puVar11,&local_58);
    cVar2 = local_res18[0];
    if (psStack_90 == (short *)0x0) break;
    if ((*psStack_90 == 0x3c) && (psStack_90[(local_98 >> 1 & 0x7fff) - 1] == 0x3e)) {
      if ((lStack_80 == 0) || (uVar16 == 2)) {
        iVar3 = -0x3fffffff;
        goto LAB_14001070f;
      }
      uVar12 = StSecpGetParameterValue(&local_98,local_88,local_78 + uVar16);
      iVar3 = (int)uVar12;
      if (iVar3 < 0) goto LAB_14001070f;
      psVar7 = (short *)local_78[uVar16];
      if (psVar7 == (short *)0x0) {
        iVar3 = -0x3ffffff3;
        goto LAB_14001070f;
      }
      lVar9 = 0x7fffffff;
      do {
        if (*psVar7 == 0) break;
        psVar7 = psVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      iVar3 = -0x3ffffff3;
      if (lVar9 == 0) goto LAB_14001070f;
      iVar3 = 0;
      lVar15 = (0x7fffffff - lVar9) * 2;
      if (lVar9 == 0) goto LAB_14001070f;
      uVar13 = uVar13 + lVar15;
      uVar16 = uVar16 + 1;
      local_res20 = lVar15;
    }
    if (puVar4[5] != 0) {
      uVar12 = StSecpCheckConditionalPolicy(&local_98,local_88,local_res18);
      iVar3 = (int)uVar12;
      if (iVar3 < 0) goto LAB_14001070f;
    }
    local_48 = (undefined4)local_68;
    uStack_44 = local_68._4_4_;
    uStack_40 = (undefined4)uStack_60;
    uStack_3c = uStack_60._4_4_;
    FsRtlDissectName(&local_48,&local_98,&local_68);
    local_48 = (undefined4)local_58;
    uStack_44 = local_58._4_4_;
    uStack_40 = (undefined4)uStack_50;
    uStack_3c = uStack_50._4_4_;
  }
  if (local_res18[0] != '\0') {
    iVar3 = RtlStringCbLengthW((short *)puVar4[5],puVar11,&local_res20);
    if (iVar3 < 0) goto LAB_14001070f;
    uVar13 = uVar13 + local_res20;
  }
  pwVar5 = (wchar_t *)ExAllocatePool2(0x100,uVar13,0x70537453);
  if (pwVar5 == (wchar_t *)0x0) {
    iVar3 = -0x3fffffe9;
  }
  else {
    if (uVar16 == 0) {
      lVar9 = puVar4[4];
      uVar12 = uVar13 >> 1;
      if (uVar12 - 1 < 0x7fffffff) {
        lVar15 = 0x7ffffffe - uVar12;
        pwVar10 = pwVar5;
        do {
          if ((lVar15 + uVar12 == 0) ||
             (wVar1 = *(wchar_t *)((lVar9 - (longlong)pwVar5) + (longlong)pwVar10), wVar1 == L'\0'))
          break;
          *pwVar10 = wVar1;
          pwVar10 = pwVar10 + 1;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
        pwVar6 = pwVar10 + -1;
        if (uVar12 != 0) {
          pwVar6 = pwVar10;
        }
        iVar3 = -0x7ffffffb;
        if (uVar12 != 0) {
          iVar3 = 0;
        }
        *pwVar6 = L'\0';
      }
      else {
        iVar3 = -0x3ffffff3;
        if (uVar12 != 0) {
          *pwVar5 = L'\0';
        }
      }
    }
    else if (uVar16 == 1) {
      uVar8 = RtlStringCbPrintfW(pwVar5,uVar13,(wchar_t *)puVar4[4],local_78[0]);
      iVar3 = (int)uVar8;
    }
    else if (uVar16 == 2) {
      uVar8 = RtlStringCbPrintfW(pwVar5,uVar13,(wchar_t *)puVar4[4],local_78[0]);
      iVar3 = (int)uVar8;
    }
    if (-1 < iVar3) {
      if (cVar2 != '\0') {
        uVar8 = RtlStringCbCatW(pwVar5,uVar13,puVar4[5]);
        iVar3 = (int)uVar8;
        if (iVar3 < 0) goto LAB_14001070f;
      }
      *param_2 = pwVar5;
      pwVar5 = (wchar_t *)0x0;
    }
  }
LAB_14001070f:
  if (uVar16 != 0) {
    plVar14 = local_78;
    uVar13 = (ulonglong)uVar16;
    do {
      if (*plVar14 != 0) {
        ExFreePoolWithTag(*plVar14,0);
      }
      plVar14 = plVar14 + 1;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  if (pwVar5 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar5,0x70537453);
  }
  return iVar3;
}



===== StSecpFindSecurityDescriptorPolicyElement @ 140010960 =====

undefined8 * StSecpFindSecurityDescriptorPolicyElement(undefined4 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  ulonglong local_58;
  short *psStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_48 = 0;
  lStack_40 = 0;
  iVar1 = -1;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  puVar2 = g_StSecSecurityDescriptorCacheListHead;
  do {
    if ((undefined8 **)puVar2 == &g_StSecSecurityDescriptorCacheListHead) {
      return (undefined8 *)0x0;
    }
    local_18 = *param_1;
    uStack_14 = param_1[1];
    uStack_10 = param_1[2];
    uStack_c = param_1[3];
    FsRtlDissectName(&local_18,&local_48,&local_38);
    local_18 = *(undefined4 *)(puVar2 + 2);
    uStack_14 = *(undefined4 *)((longlong)puVar2 + 0x14);
    uStack_10 = *(undefined4 *)(puVar2 + 3);
    uStack_c = *(undefined4 *)((longlong)puVar2 + 0x1c);
    FsRtlDissectName(&local_18,&local_58,&local_28);
    while ((lStack_40 != 0 && (psStack_50 != (short *)0x0))) {
      if ((short)local_58 == 0) {
LAB_140010a4f:
        iVar1 = 0;
      }
      else {
        iVar1 = RtlCompareUnicodeString(&local_48,&local_58,1);
        if (iVar1 != 0) {
          if ((*psStack_50 == 0x3c) && (psStack_50[(local_58 >> 1 & 0x7fff) - 1] == 0x3e))
          goto LAB_140010a4f;
          goto LAB_140010aa8;
        }
      }
      local_18 = (undefined4)local_38;
      uStack_14 = local_38._4_4_;
      uStack_10 = (undefined4)uStack_30;
      uStack_c = uStack_30._4_4_;
      FsRtlDissectName(&local_18,&local_48,&local_38);
      local_18 = (undefined4)local_28;
      uStack_14 = local_28._4_4_;
      uStack_10 = (undefined4)uStack_20;
      uStack_c = uStack_20._4_4_;
      FsRtlDissectName(&local_18,&local_58,&local_28);
    }
    if (iVar1 == 0) {
      if ((lStack_40 != 0) || (psStack_50 == (short *)0x0)) {
        return puVar2;
      }
      iVar1 = -1;
    }
LAB_140010aa8:
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== StSecpFindFolderPropertyPolicyElement @ 140010af0 =====

undefined8 * StSecpFindFolderPropertyPolicyElement(undefined4 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_48 = 0;
  lStack_40 = 0;
  iVar1 = -1;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_28 = 0;
  uStack_20 = 0;
  puVar2 = g_StSecFolderPropertyCacheListHead;
  do {
    if ((undefined8 **)puVar2 == &g_StSecFolderPropertyCacheListHead) {
      return (undefined8 *)0x0;
    }
    local_18 = *param_1;
    uStack_14 = param_1[1];
    uStack_10 = param_1[2];
    uStack_c = param_1[3];
    FsRtlDissectName(&local_18,&local_48,&local_38);
    local_18 = *(undefined4 *)(puVar2 + 2);
    uStack_14 = *(undefined4 *)((longlong)puVar2 + 0x14);
    uStack_10 = *(undefined4 *)(puVar2 + 3);
    uStack_c = *(undefined4 *)((longlong)puVar2 + 0x1c);
    FsRtlDissectName(&local_18,&local_58,&local_28);
    while ((lStack_40 != 0 && (lStack_50 != 0))) {
      if ((short)local_58 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = RtlCompareUnicodeString(&local_48,&local_58,1);
        if (iVar1 != 0) goto LAB_140010bbe;
      }
      local_18 = (undefined4)local_38;
      uStack_14 = local_38._4_4_;
      uStack_10 = (undefined4)uStack_30;
      uStack_c = uStack_30._4_4_;
      FsRtlDissectName(&local_18,&local_48,&local_38);
      local_18 = (undefined4)local_28;
      uStack_14 = local_28._4_4_;
      uStack_10 = (undefined4)uStack_20;
      uStack_c = uStack_20._4_4_;
      FsRtlDissectName(&local_18,&local_58,&local_28);
    }
    if (iVar1 == 0) {
      if ((lStack_40 != 0) || (lStack_50 == 0)) {
        return puVar2;
      }
      iVar1 = -1;
    }
LAB_140010bbe:
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== StSecpGetParameterValue @ 140010c60 =====

/* WARNING: Type propagation algorithm not settling */

ulonglong StSecpGetParameterValue(undefined8 param_1,ushort *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res20;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  wchar_t *local_30;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_58 = 0xe000c;
  local_50 = L"<User>";
  local_48 = 0x280026;
  local_40 = L"<PackageFamilyName>";
  local_28 = 0x240022;
  local_20 = L"<PackageFullName>";
  local_18 = 0x180016;
  local_10 = L"<ProductId>";
  local_38 = 0x380036;
  local_30 = L"<PackageFullNameRedirected>";
  local_res20 = 0;
  iVar1 = RtlCompareUnicodeString(param_1,&local_58,1);
  if (iVar1 == 0) {
    uVar3 = StSecpGetSidFromUserName(param_2,&local_res20);
    uVar2 = (uint)uVar3;
joined_r0x000140010d60:
    uVar3 = uVar3 & 0xffffffff;
  }
  else {
    iVar1 = RtlCompareUnicodeString(param_1,&local_48,1);
    if (iVar1 == 0) {
      uVar3 = StSecpGetSidFromPackageFamilyName((short *)param_2,&local_res20);
      uVar2 = (uint)uVar3;
      goto joined_r0x000140010d60;
    }
    iVar1 = RtlCompareUnicodeString(param_1,&local_38,1);
    if (iVar1 == 0) {
      uVar3 = KappxGetSecurityDescriptorStringForPackageFullName(param_2,&local_res20);
      uVar2 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
    }
    else {
      iVar1 = RtlCompareUnicodeString(param_1,&local_28,1);
      if (iVar1 == 0) {
        uVar3 = StSecpGetSidFromPackageFullName(param_2,&local_res20);
        uVar2 = (uint)uVar3;
        uVar3 = uVar3 & 0xffffffff;
      }
      else {
        iVar1 = RtlCompareUnicodeString(param_1,&local_18,1);
        if (iVar1 != 0) {
          uVar3 = 0xc0000001;
          goto LAB_140010d10;
        }
        uVar2 = StSecpGetSidFromProductId(param_2,&local_res20);
        uVar3 = (ulonglong)uVar2;
      }
    }
  }
  if (-1 < (int)uVar2) {
    *param_3 = local_res20;
    return 0;
  }
LAB_140010d10:
  if (local_res20 != 0) {
    ExFreePoolWithTag(local_res20,0);
  }
  return uVar3;
}



===== StSecpGetSidFromUserName @ 140010e30 =====

ulonglong StSecpGetSidFromUserName(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  short *psVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  uVar1 = *param_1;
  uVar5 = 0x6e537453;
  psVar2 = (short *)ExAllocatePool2(0x40,(ulonglong)uVar1 + 2);
  if (psVar2 == (short *)0x0) {
    uVar4 = 0xc0000017;
  }
  else {
    uVar4 = (ulonglong)uVar1 + 2 >> 1;
    if (uVar4 == 0) {
      uVar4 = 0xc000000d;
    }
    else {
      uVar3 = RtlStringCopyWorkerW
                        (psVar2,uVar4,uVar5,*(longlong *)(param_1 + 4),(ulonglong)(*param_1 >> 1));
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        *param_2 = psVar2;
        return uVar3;
      }
    }
    ExFreePoolWithTag(psVar2,0);
  }
  return uVar4;
}



===== StSecpGetSidFromPackageFamilyName @ 140010ed0 =====

ulonglong StSecpGetSidFromPackageFamilyName(short *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar2 = KappxGetPackageSidFromPackageFamilyNameInRegistry(param_1,param_2);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == -0x3fffffcc) {
    uVar1 = RtlDowncaseUnicodeString(local_18,param_1,1);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = StSecpGetAppSid(local_18,param_2);
      uVar3 = (ulonglong)uVar1;
    }
  }
  RtlFreeUnicodeString(local_18);
  return uVar3;
}



===== KappxGetPackageSidFromPackageFamilyNameInRegistry @ 140010f60 =====

ulonglong KappxGetPackageSidFromPackageFamilyNameInRegistry(short *param_1,undefined8 *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  short *psVar5;
  ulonglong uVar6;
  short *psVar7;
  longlong lVar8;
  ushort uVar9;
  ulonglong uVar10;
  undefined4 local_res8 [2];
  longlong local_res18 [2];
  short *psVar11;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar12;
  undefined8 local_98;
  void *pvStack_90;
  undefined8 local_88;
  short *psStack_80;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  local_70 = L"PackageSid";
  local_78 = 0x160014;
  lVar4 = 0;
  local_48 = 0;
  psVar5 = (short *)0x0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_68 = 0;
  uStack_60 = 0;
  local_res18[0] = 0;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  local_res8[0] = 0;
  local_98 = 0;
  pvStack_90 = (void *)0x0;
  local_88 = 0;
  psStack_80 = (short *)0x0;
  if (*param_1 == 0) {
    uVar10 = 0xc0000034;
  }
  else {
    psVar3 = (short *)ExAllocatePool2(0x100,0x20a,0x58707041);
    if (psVar3 == (short *)0x0) {
      uVar10 = 0xc0000017;
    }
    else {
      psVar11 = psVar3;
      uVar2 = RtlGetPersistedStateLocation
                        (L"AppxPackageSidRef",L"TargetNtPath",
                         L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Appx\\PackageSidRef"
                         ,0,psVar3,CONCAT44(uVar12,0x20a),local_res8);
      uVar10 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        lVar8 = 0x7fff;
        psVar7 = psVar3;
        do {
          if (*psVar7 == 0) {
            sVar1 = (0x7fff - (short)lVar8) * 2;
            local_88._0_4_ = CONCAT22(sVar1 + 2,sVar1);
            psStack_80 = psVar3;
            RtlInitUnicodeString(&local_98,0);
            uVar9 = (short)local_88 + 2 + *param_1;
            pvStack_90 = (void *)ExAllocatePool2(0x100,uVar9,0x58707041);
            if (pvStack_90 == (void *)0x0) {
              uVar10 = 0xc0000017;
            }
            else {
              memset(pvStack_90,0,(ulonglong)uVar9);
              local_98 = (ulonglong)CONCAT42(local_98._4_4_,uVar9) << 0x10;
              uVar2 = RtlAppendUnicodeStringToString(&local_98,&local_88);
              uVar10 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                uVar2 = RtlAppendUnicodeStringToString(&local_98,param_1);
                uVar10 = (ulonglong)uVar2;
                if (-1 < (int)uVar2) {
                  uVar2 = RtlAppendUnicodeToString(&local_98,L"");
                  uVar10 = (ulonglong)uVar2;
                  if (-1 < (int)uVar2) {
                    local_58 = &local_98;
                    local_68 = CONCAT44(local_68._4_4_,0x30);
                    uStack_60 = 0;
                    uStack_50 = CONCAT44(uStack_50._4_4_,0x240);
                    local_48 = 0;
                    uStack_40 = 0;
                    uVar2 = ZwOpenKey(local_res18,0x2000000,&local_68);
                    uVar10 = (ulonglong)uVar2;
                    if (-1 < (int)uVar2) {
                      uVar10 = (ulonglong)psVar11 & 0xffffffff00000000;
                      uVar2 = ZwQueryValueKey(local_res18[0],&local_78,1,0,uVar10,local_res8);
                      uVar12 = (undefined4)(uVar10 >> 0x20);
                      uVar10 = (ulonglong)uVar2;
                      if (uVar2 == 0xc0000023) {
                        lVar4 = ExAllocatePool2(0x100,local_res8[0],0x58707041);
                        if (lVar4 == 0) {
                          uVar10 = 0xc0000017;
                        }
                        else {
                          uVar2 = ZwQueryValueKey(local_res18[0],&local_78,1,lVar4,
                                                  CONCAT44(uVar12,local_res8[0]),local_res8);
                          uVar10 = (ulonglong)uVar2;
                          if (-1 < (int)uVar2) {
                            if (((*(int *)(lVar4 + 4) == 1) &&
                                (uVar2 = *(uint *)(lVar4 + 0xc), 3 < uVar2)) ||
                               (uVar2 = *(uint *)(lVar4 + 0xc),
                               *(short *)(((ulonglong)uVar2 - 2) +
                                         (ulonglong)*(uint *)(lVar4 + 8) + lVar4) != 0)) {
                              psVar5 = (short *)ExAllocatePool2(0x100,(ulonglong)uVar2 + 2,
                                                                0x58707041);
                              if (psVar5 == (short *)0x0) {
                                uVar10 = 0xc0000017;
                              }
                              else {
                                uVar6 = RtlStringCbCopyNW(psVar5,(ulonglong)*(uint *)(lVar4 + 0xc) +
                                                                 2,(ulonglong)*(uint *)(lVar4 + 8) +
                                                                   lVar4,
                                                          (ulonglong)*(uint *)(lVar4 + 0xc));
                                uVar10 = uVar6 & 0xffffffff;
                                if (-1 < (int)uVar6) {
                                  *param_2 = psVar5;
                                  psVar5 = (short *)0x0;
                                }
                              }
                            }
                            else {
                              uVar10 = 0xc000090b;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_140011058;
          }
          psVar7 = psVar7 + 1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        uVar10 = 0xc000000d;
      }
    }
LAB_140011058:
    if (local_res18[0] != 0) {
      ZwClose();
    }
    if (psVar3 != (short *)0x0) {
      ExFreePoolWithTag(psVar3,0x58707041);
    }
  }
  if (pvStack_90 != (void *)0x0) {
    ExFreePoolWithTag(pvStack_90,0);
  }
  if (psVar5 != (short *)0x0) {
    ExFreePoolWithTag(psVar5,0);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return uVar10;
}



===== StSecpGetAppSid @ 140011370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS StSecpGetAppSid(ushort *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  NTSTATUS NVar2;
  PUCHAR pbHashObject;
  PUCHAR pbOutput;
  undefined4 *puVar3;
  byte bVar4;
  PUCHAR pUVar5;
  undefined1 auStackY_98 [32];
  BCRYPT_HASH_HANDLE local_58;
  undefined4 local_50;
  undefined2 local_4c;
  undefined1 local_48 [40];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_4c = 0xf00;
  local_58 = (BCRYPT_HASH_HANDLE)0x0;
  local_50 = 0;
  pbOutput = (PUCHAR)0x0;
  pbHashObject = (PUCHAR)ExAllocatePool2(0x100,g_cbHashObject,0x70537453);
  if (pbHashObject == (PUCHAR)0x0) {
    NVar2 = -0x3fffffe9;
  }
  else {
    pbOutput = (PUCHAR)ExAllocatePool2(0x100,g_cbHashValue,0x70537453);
    if (pbOutput == (PUCHAR)0x0) {
      NVar2 = -0x3fffffe9;
    }
    else {
      NVar2 = BCryptCreateHash(g_HashProvider,&local_58,pbHashObject,g_cbHashObject,(PUCHAR)0x0,0,0)
      ;
      if (-1 < NVar2) {
        NVar2 = BCryptHashData(local_58,*(PUCHAR *)(param_1 + 4),(uint)*param_1,0);
        if (-1 < NVar2) {
          NVar2 = BCryptFinishHash(local_58,pbOutput,g_cbHashValue,0);
          if (-1 < NVar2) {
            NVar2 = RtlInitializeSid(local_48,&local_50,8);
            if (-1 < NVar2) {
              puVar3 = (undefined4 *)RtlSubAuthoritySid(local_48,0);
              bVar4 = 1;
              *puVar3 = 2;
              pUVar5 = pbOutput;
              do {
                puVar3 = (undefined4 *)RtlSubAuthoritySid(local_48,bVar4);
                uVar1 = *(undefined4 *)pUVar5;
                pUVar5 = pUVar5 + 4;
                bVar4 = bVar4 + 1;
                *puVar3 = uVar1;
              } while (bVar4 < 8);
              NVar2 = SeConvertSidToStringSid(local_48,param_2);
            }
          }
        }
      }
    }
  }
  if (local_58 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash(local_58);
  }
  if (pbHashObject != (PUCHAR)0x0) {
    ExFreePoolWithTag(pbHashObject,0x70537453);
  }
  if (pbOutput != (PUCHAR)0x0) {
    ExFreePoolWithTag(pbOutput,0x70537453);
  }
  return NVar2;
}



===== KappxGetSecurityDescriptorStringForPackageFullName @ 140011580 =====

ulonglong KappxGetSecurityDescriptorStringForPackageFullName(ushort *param_1,undefined8 *param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  longlong lVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  longlong local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  lVar5 = 0;
  local_b0 = 0;
  local_b8 = 0;
  local_88 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_80 = uStack_80 & 0xffffffff00000000;
  psVar6 = (short *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_res18[0] = 0;
  local_98 = (undefined8 *)0x0;
  uStack_90 = 0;
  local_res20[0] = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar4 = KappxGetPackageRootPathForPackageFullName(param_1,&local_b0);
  lVar2 = local_b0;
  uVar10 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    RtlInitUnicodeString(&local_78,local_b0);
    local_98 = &local_78;
    local_a8 = CONCAT44(local_a8._4_4_,0x30);
    uStack_a0 = 0;
    local_68 = CONCAT62(local_68._2_6_,0x28);
    uStack_90 = CONCAT44(uStack_90._4_4_,0x240);
    local_88 = 0;
    uStack_80 = 0;
    local_48 = PsGetHostSilo();
    uVar3 = IoCreateFileEx(&local_b8,0x20000,&local_a8,&local_40,0,0,7,1,0x200009,0,0,0,0,0,
                           &local_68);
    uVar10 = (ulonglong)uVar3;
    if (uVar3 == 0xc0000034) {
      psVar6 = (short *)ExAllocatePool2(0x100,0x23a,0x58707041);
      if (psVar6 == (short *)0x0) {
        uVar10 = 0xc0000017;
      }
      else {
        lVar9 = 0x11d;
        psVar7 = psVar6;
        do {
          if ((lVar9 == -0x7ffffee1) ||
             (sVar1 = *(short *)(((longlong)
                                  L"D:AI(A;OICI;0x1200a9;;;BU)(A;ID;FA;;;S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464)(A;CIIOID;FA;;;S-1-5-80-956008885-3418522649-1831038044-1853292631-2271478464)(A;ID;FA;;;SY)(A;OICIIOID;FA;;;SY)(A;OICIID;0x1200a9;;;BA)(A;OICIID;0x1200a9;;;LS)(A;OICIID;0x1200a9;;;NS)"
                                 - (longlong)psVar6) + (longlong)psVar7), sVar1 == 0)) break;
          *psVar7 = sVar1;
          psVar7 = psVar7 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        bVar11 = lVar9 != 0;
        psVar8 = psVar7 + -1;
        if (bVar11) {
          psVar8 = psVar7;
        }
        uVar10 = 0x80000005;
        if (bVar11) {
          uVar10 = 0;
        }
        *psVar8 = 0;
        if (bVar11) {
          *param_2 = psVar6;
          psVar6 = (short *)0x0;
        }
      }
    }
    else if (-1 < (int)uVar3) {
      uVar3 = ZwQuerySecurityObject(local_b8,0xc,0,0,local_res18);
      uVar10 = (ulonglong)uVar3;
      if (uVar3 == 0xc0000023) {
        lVar5 = ExAllocatePool2(0x100,local_res18[0],0x58707041);
        if (lVar5 == 0) {
          uVar10 = 0xc0000017;
        }
        else {
          uVar3 = ZwQuerySecurityObject(local_b8,0xc,lVar5,local_res18[0],local_res18);
          uVar10 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            uVar3 = SeConvertSecurityDescriptorToStringSecurityDescriptor
                              (lVar5,1,0xc,param_2,local_res20);
            uVar10 = (ulonglong)uVar3;
          }
        }
      }
    }
  }
  if (local_b8 != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  if (psVar6 != (short *)0x0) {
    ExFreePoolWithTag(psVar6,0);
  }
  return uVar10;
}



===== KappxGetPackageRootPathForPackageFullName @ 140011860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KappxGetPackageRootPathForPackageFullName(ushort *param_1,undefined8 *param_2)

{
  short *psVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_2d8 [32];
  undefined4 local_2b8;
  undefined4 *local_2b0;
  undefined4 local_2a8 [2];
  longlong local_2a0 [2];
  wchar_t *local_290;
  longlong local_288;
  wchar_t *local_280;
  longlong local_278 [2];
  longlong *local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined1 local_248 [4];
  int local_244;
  uint local_240;
  uint local_23c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_2a0[1] = 0x820080;
  local_288 = 0x180016;
  local_290 = L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Appx";
  local_2a0[0] = 0;
  local_280 = L"PackageRoot";
  local_2a8[0] = 0;
  local_258 = 0;
  psVar1 = (short *)0x0;
  uStack_250 = uStack_250 & 0xffffffff00000000;
  local_278[0] = 0;
  local_278[1] = 0;
  local_268 = (longlong *)0x0;
  uStack_260 = 0;
  if (*param_1 == 0) {
    return 0xc0000034;
  }
  if (g_PackageRoot == 0) {
    local_268 = local_2a0 + 1;
    local_278[0] = 0x30;
    local_278[1] = 0;
    uStack_260 = 0x240;
    local_258 = 0;
    uStack_250 = 0;
    uVar3 = ZwOpenKey(local_2a0,0x2000000,local_2a0 + 5);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_14001195a;
    local_2b0 = local_2a8;
    local_2b8 = 0x210;
    uVar3 = ZwQueryValueKey(local_2a0[0],local_2a0 + 3,1,local_248);
    uVar4 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_14001195a;
    if (((local_244 != 1) || (local_23c < 4)) ||
       (*(short *)(local_248 + (ulonglong)local_240 + (ulonglong)local_23c + -2) != 0)) {
      uVar4 = 0xc000090b;
      goto LAB_14001195a;
    }
    g_PackageRootLength = local_23c + 10;
    uVar2 = RtlStringCbPrintfW(&g_PackageRoot,0x104,L"\\??\\%ws\\",local_248 + local_240);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      g_PackageRootLength = 0;
      g_PackageRoot = 0;
      goto LAB_14001195a;
    }
  }
  uVar3 = (uint)*param_1 + g_PackageRootLength + 2;
  psVar1 = (short *)ExAllocatePool2(0x100,uVar3,0x58707041);
  if (psVar1 == (short *)0x0) {
    uVar4 = 0xc0000017;
  }
  else {
    uVar2 = RtlStringCbCopyW(psVar1,(ulonglong)uVar3,0x140009410);
    uVar4 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar2 = RtlStringCbCatNW(psVar1,(ulonglong)uVar3,*(longlong *)(param_1 + 4),
                               (ulonglong)*param_1);
      uVar4 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        *param_2 = psVar1;
        psVar1 = (short *)0x0;
      }
    }
  }
LAB_14001195a:
  if (local_2a0[0] != 0) {
    ZwClose();
  }
  if (psVar1 != (short *)0x0) {
    ExFreePoolWithTag(psVar1,0);
  }
  return uVar4;
}



===== FCPostCreate @ 140011af0 =====

undefined8
FCPostCreate(longlong param_1,longlong param_2,BCRYPT_KEY_HANDLE **param_3,ulonglong param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  BCRYPT_KEY_HANDLE *ppvVar5;
  char cVar6;
  char local_res18 [16];
  uint local_44;
  BCRYPT_KEY_HANDLE *local_40;
  BCRYPT_KEY_HANDLE *local_38;
  BCRYPT_KEY_HANDLE *local_30;
  
  local_38 = (BCRYPT_KEY_HANDLE *)0x0;
  local_40 = (BCRYPT_KEY_HANDLE *)0x0;
  iVar3 = 0;
  ppvVar5 = (BCRYPT_KEY_HANDLE *)0x0;
  local_30 = (BCRYPT_KEY_HANDLE *)0x0;
  local_44 = 1;
  bVar2 = false;
  cVar6 = '\0';
  local_res18[0] = '\0';
  if (param_3 != (BCRYPT_KEY_HANDLE **)0x0) {
    ppvVar5 = *param_3;
    local_44 = *(uint *)(param_3 + 1);
    cVar6 = *(char *)((longlong)param_3 + 0xc);
    local_30 = ppvVar5;
    ExFreeToNPagedLookasideList(&gPre2PostCreateContextList,param_3);
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if ((iVar1 < 0) || (iVar1 == 0x104)) {
    if ((iVar1 == -0x3fffffcc) && (cVar6 != '\0')) {
      *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
    }
    bVar2 = true;
  }
  else if ((param_4 & 1) == 0) {
    param_3 = &local_40;
    iVar3 = FltGetStreamContext(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x20));
    if (iVar3 < 0) {
      if (ppvVar5 == (BCRYPT_KEY_HANDLE *)0x0) {
        iVar3 = 0;
      }
      else {
        param_3 = (BCRYPT_KEY_HANDLE **)local_res18;
        iVar3 = FltIsDirectory(*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x18));
        if ((-1 < iVar3) && (local_res18[0] == '\0')) {
          param_3 = &local_38;
          iVar3 = FltGetVolumeContext(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10));
          if (-1 < iVar3) {
            param_3 = (BCRYPT_KEY_HANDLE **)0x28;
            iVar3 = FltAllocateContext(gFilterHandle,8,0x28,0x200,&local_40);
            if (-1 < iVar3) {
              *local_40 = (BCRYPT_KEY_HANDLE)0x0;
              local_40[1] = (BCRYPT_KEY_HANDLE)0x0;
              local_40[2] = (BCRYPT_KEY_HANDLE)0x0;
              local_40[3] = (BCRYPT_KEY_HANDLE)0x0;
              local_40[4] = (BCRYPT_KEY_HANDLE)0x0;
              local_40[3] = ppvVar5;
              param_3 = (BCRYPT_KEY_HANDLE **)(ulonglong)local_44;
              *(uint *)(local_40 + 4) = local_44;
              ppvVar5 = (BCRYPT_KEY_HANDLE *)0x0;
              local_30 = (BCRYPT_KEY_HANDLE *)0x0;
              iVar3 = FCpEncStreamStart(local_38 + 3,local_40[3],local_44,local_40);
              if (-1 < iVar3) {
                param_3 = (BCRYPT_KEY_HANDLE **)0x1;
                iVar3 = FltSetStreamContext(*(undefined8 *)(param_2 + 0x18),
                                            *(undefined8 *)(param_2 + 0x20),1,local_40,0);
                if (iVar3 == -0x3fe3fffe) {
                  iVar3 = 0;
                }
                else if (-1 < iVar3) {
                  FltReleaseContext(local_40);
                  local_40 = (BCRYPT_KEY_HANDLE *)0x0;
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_38 != (BCRYPT_KEY_HANDLE *)0x0) {
    FltReleaseContext();
    local_38 = (BCRYPT_KEY_HANDLE *)0x0;
  }
  if (local_40 != (BCRYPT_KEY_HANDLE *)0x0) {
    FltReleaseContext();
    local_40 = (BCRYPT_KEY_HANDLE *)0x0;
  }
  if (ppvVar5 != (BCRYPT_KEY_HANDLE *)0x0) {
    FCpFreeChamberId((short *)ppvVar5);
  }
  if ((!bVar2) && (iVar3 < 0)) {
    uVar4 = *(undefined8 *)(param_2 + 0x18);
    FltCancelFileOpen(uVar4,*(undefined8 *)(param_2 + 0x20));
    *(int *)(param_1 + 0x18) = iVar3;
    *(undefined8 *)(param_1 + 0x20) = 0;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(uVar4,&PostCreateFailure,param_3,iVar3);
    }
  }
  return 0;
}



===== StSecFree @ 140011df0 =====

void StSecFree(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0x70537453);
  }
  return;
}



===== FCInstanceSetup @ 140011e20 =====

undefined8 FCInstanceSetup(longlong param_1,undefined8 param_2,int param_3,int param_4)

{
  short sVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  NTSTATUS NVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  bool bVar12;
  bool bVar13;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar14;
  undefined4 local_58 [2];
  undefined8 *local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  short *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0;
  local_50 = (undefined8 *)0x0;
  uVar11 = 0xc01c000f;
  local_58[0] = 0;
  lVar6 = 0;
  local_40 = 0;
  lVar7 = 0;
  local_38 = 0;
  bVar13 = false;
  if ((param_3 != 8) ||
     ((((1 < param_4 - 2U && (param_4 != 0x16)) ||
       (lVar6 = ExAllocatePool2(0x100,0x248,0x70764346), local_40 = lVar6, lVar6 == 0)) ||
      (iVar3 = FltGetVolumeProperties(*(undefined8 *)(param_1 + 0x10),lVar6,0x248,local_58),
      iVar3 < 0)))) goto LAB_140012258;
  bVar12 = (*(uint *)(lVar6 + 4) & 1) == 0;
  if ((gFCFlags & 8) != 0) {
    lVar7 = ExAllocatePool2(0x100,0x58,0x69764346);
    local_38 = lVar7;
    if ((lVar7 == 0) ||
       (iVar3 = FltQueryVolumeInformation
                          (*(undefined8 *)(param_1 + 0x18),&local_28,lVar7,0x58,CONCAT44(uVar14,1)),
       iVar3 < 0)) goto LAB_140012258;
    if ((*(uint *)(lVar7 + 0xc) & 0xfffffffe) == 0xc) {
      iVar3 = _wcsnicmp((wchar_t *)(lVar7 + 0x12),L"SDCARD",(ulonglong)(*(uint *)(lVar7 + 0xc) >> 1)
                       );
      bVar13 = iVar3 == 0;
    }
  }
  cVar2 = FsRtlIsMobileOS();
  if (cVar2 == '\0') {
    iVar3 = FCpRetrieveAppPairingId(param_1);
    if (iVar3 < 0) {
joined_r0x000140011fd3:
      if (!bVar13) goto LAB_140012258;
    }
  }
  else if (bVar12) goto joined_r0x000140011fd3;
  uVar4 = 0x200;
  iVar3 = FltAllocateContext(*(undefined8 *)(param_1 + 8),1,0x38,0x200,&local_50);
  if (-1 < iVar3) {
    *local_50 = 0;
    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    if (0x200 < *(ushort *)(lVar6 + 0x10)) {
      uVar4 = (uint)*(ushort *)(lVar6 + 0x10);
    }
    *(uint *)(local_50 + 2) = uVar4;
    local_50[1] = 0;
    iVar3 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10),&local_48);
    if (-1 < iVar3) {
      iVar3 = RtlVolumeDeviceToDosName(local_48);
      if (iVar3 < 0) {
        local_30 = (short *)(lVar6 + 0x38);
        sVar1 = *local_30;
        if (sVar1 == 0) {
          local_30 = (short *)(lVar6 + 0x28);
          sVar1 = *local_30;
          if (sVar1 == 0) goto LAB_140012258;
        }
        uVar8 = ExAllocatePool2(0x40,sVar1 + 2,0x766e4346);
        local_50[1] = uVar8;
        if (local_50[1] == 0) goto LAB_140012258;
        *(undefined2 *)local_50 = 0;
        *(short *)((longlong)local_50 + 2) = sVar1 + 2;
        RtlCopyUnicodeString(local_50,local_30);
        RtlAppendUnicodeToString(local_50);
      }
      local_50[3] = 0;
      local_50[4] = 0;
      local_50[5] = 0;
      *(undefined4 *)(local_50 + 5) = *(undefined4 *)(local_50 + 2);
      *(undefined4 *)((longlong)local_50 + 0x2c) = 0x10;
      *(undefined1 *)(local_50 + 6) = 1;
      NVar5 = FCpEncVolumeStart((BCRYPT_ALG_HANDLE *)(local_50 + 3));
      if ((-1 < NVar5) &&
         ((iVar3 = FltSetVolumeContext(*(undefined8 *)(param_1 + 0x10),1,local_50,0),
          (iVar3 + 0x80000000U & 0x80000000) != 0 || (iVar3 == -0x3fe3fffe)))) {
        lVar9 = *(longlong *)(local_48 + 0x38);
        cVar2 = FsRtlIsMobileOS();
        if ((cVar2 == '\0') && ((*(uint *)(*(longlong *)(lVar9 + 8) + 0x30) & 0x20000) != 0)) {
          *(undefined1 *)((longlong)local_50 + 0x31) = 0;
        }
        else {
          *(undefined1 *)((longlong)local_50 + 0x31) = 1;
          lVar9 = *(longlong *)(lVar9 + 8);
          *(uint *)(lVar9 + 0x30) = *(uint *)(lVar9 + 0x30) | 0x20000;
        }
        if (((gFCFlags & 8) != 0) && (bVar12)) {
          lVar9 = IoGetAttachedDeviceReference(local_48);
          while (lVar9 != 0) {
            *(uint *)(lVar9 + 0x34) = *(uint *)(lVar9 + 0x34) | 1;
            lVar10 = IoGetLowerDeviceObject(lVar9);
            ObfDereferenceObject(lVar9);
            lVar9 = lVar10;
          }
        }
        if ((gFCFlags & 0x10) != 0) {
          *(uint *)(local_48 + 0x34) = *(uint *)(local_48 + 0x34) & 0xfffffeff;
        }
        uVar11 = 0;
      }
    }
  }
LAB_140012258:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x70764346);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x69764346);
  }
  if (local_50 != (undefined8 *)0x0) {
    FltReleaseContext();
  }
  if (local_48 != 0) {
    ObfDereferenceObject();
  }
  return uVar11;
}



===== FCpRetrieveAppPairingId @ 1400122f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FCpRetrieveAppPairingId(longlong param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined8 *local_100;
  undefined8 *local_f8;
  undefined8 local_f0;
  ulonglong local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  int local_a8 [2];
  undefined8 local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_128;
  local_80 = 0;
  local_a0 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0;
  bVar1 = false;
  local_78 = 0;
  uStack_70 = 0;
  uStack_50 = uStack_50 & 0xffffffff00000000;
  local_68 = (undefined8 *)0x0;
  uStack_60 = 0;
  local_90 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_88 = 0;
  local_a8[0] = 0;
  local_98 = 0;
  iVar2 = FltGetVolumeName(*(undefined8 *)(param_1 + 0x10),0,local_a8);
  if (iVar2 == -0x3fffffdd) {
    local_a8[0] = local_a8[0] + 0x5c;
    local_98 = ExAllocatePool2(0x100,local_a8[0],0x766e4346);
    if (local_98 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      local_a0._0_4_ = CONCAT22((undefined2)local_a8[0],(undefined2)local_a0);
      iVar2 = FltGetVolumeName(*(undefined8 *)(param_1 + 0x10),&local_a0,0);
      if ((-1 < iVar2) &&
         (iVar2 = RtlAppendUnicodeToString
                            (&local_a0,L"\\System Volume Information\\WPAppSettings.dat"),
         -1 < iVar2)) {
        local_68 = &local_a0;
        local_b8 = 0;
        local_c0 = 0;
        local_c8 = 0;
        local_d0 = 0x40;
        local_d8 = 1;
        local_e0 = 7;
        local_e8 = local_e8 & 0xffffffff00000000;
        local_f8 = &local_48;
        local_f0 = 0;
        local_100 = &local_78;
        local_108 = (undefined8 *)CONCAT44(local_108._4_4_,0x120089);
        local_78 = CONCAT44(local_78._4_4_,0x30);
        uStack_70 = 0;
        uStack_60 = CONCAT44(uStack_60._4_4_,0x240);
        local_58 = 0;
        uStack_50 = 0;
        iVar2 = FltCreateFileEx(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x18),
                                &local_88,&local_90);
        if (-1 < iVar2) {
          local_108 = &local_38;
          local_e8 = 0;
          local_f0 = 0;
          bVar1 = true;
          local_f8 = (undefined8 *)0x0;
          local_100 = (undefined8 *)((ulonglong)local_100 & 0xffffffff00000000);
          iVar2 = FltReadFile(*(undefined8 *)(param_1 + 0x18),local_90,&local_80,0x14);
          if ((-1 < iVar2) && ((int)local_38 != 0x14)) {
            iVar2 = -0x3ffffff3;
          }
        }
      }
    }
  }
  if (local_98 != 0) {
    ExFreePoolWithTag(local_98,0x766e4346);
    local_98 = 0;
  }
  if (local_90 != 0) {
    ObfDereferenceObject();
    local_90 = 0;
  }
  if (bVar1) {
    FltClose(local_88);
  }
  return iVar2;
}



===== FCpFreeChamberId @ 140012570 =====

void FCpFreeChamberId(short *param_1)

{
  bool bVar1;
  
  if ((((gFCFlags & 6) == 0) ||
      ((((bVar1 = FCpEqualChamberIds(param_1,L"MusicChamber"), !bVar1 &&
         (bVar1 = FCpEqualChamberIds(param_1,L"PicturesChamber"), !bVar1)) &&
        (bVar1 = FCpEqualChamberIds(param_1,L"VideosChamber"), !bVar1)) &&
       (bVar1 = FCpEqualChamberIds(param_1,L"{0b7992da-c5e6-41e3-b24f-55419b997a15}"), !bVar1)))) &&
     (param_1 != (short *)0x0)) {
    ExFreePoolWithTag(param_1,0x70537453);
  }
  return;
}



===== StSecpGetSecurityDescriptorPolicy @ 140012600 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong StSecpGetSecurityDescriptorPolicy(undefined8 param_1)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  short *psVar4;
  ulonglong uVar5;
  longlong lVar6;
  short *psVar7;
  short *psVar8;
  uint *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 auStack_328 [8];
  undefined1 auStack_320 [24];
  uint *local_308;
  uint *local_300;
  uint local_2f8 [2];
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  int local_2d8;
  undefined8 local_2d0;
  short *psStack_2c8;
  undefined8 local_2c0;
  wchar_t *local_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 *local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  ulonglong uStack_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined1 local_268 [12];
  ushort local_25c;
  short asStack_25a [273];
  ulonglong local_38;
  
  puVar14 = auStack_328;
  puVar13 = auStack_328;
  local_38 = __security_cookie ^ (ulonglong)auStack_328;
  local_2c0 = 0x260024;
  local_2b8 = L"SecurityDescriptor";
  local_2d8 = 0;
  local_2f8[0] = 0;
  local_290 = 0;
  psVar4 = (short *)0x0;
  uStack_288 = uStack_288 & 0xffffffff00000000;
  lVar6 = 0;
  local_2d0 = 0;
  psStack_2c8 = (short *)0x0;
  local_280 = 0;
  puVar9 = (uint *)0x0;
  local_278 = 0;
  uStack_270 = 0;
  psVar7 = (short *)0x0;
  local_2e0 = 0;
  psVar8 = (short *)0x0;
  local_2f0 = 0;
  uStack_2e8 = 0;
  local_2b0 = 0;
  uStack_2a8 = 0;
  local_2a0 = (undefined8 *)0x0;
  uStack_298 = 0;
  while( true ) {
    local_300 = local_2f8;
    local_308 = (uint *)CONCAT44(local_308._4_4_,0x222);
    uVar3 = ZwEnumerateKey(param_1,local_2d8,0,local_268);
    uVar12 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) break;
    psStack_2c8 = asStack_25a + 1;
    local_2d0._0_4_ = CONCAT22(local_25c,local_25c);
    if ((asStack_25a[1] == 0x3c) && (asStack_25a[local_25c >> 1] == 0x3e)) {
      if (psVar4 == (short *)0x0) {
        psVar4 = (short *)ExAllocatePool2(0x100,(ulonglong)local_25c + 2,0x70537453);
        if (psVar4 == (short *)0x0) {
          uVar12 = 0xc0000017;
          RtlFreeUnicodeString(&local_2f0);
          goto LAB_140012b3a;
        }
        uVar5 = RtlStringCbCopyNW(psVar4,(local_2d0 & 0xffff) + 2,psStack_2c8,local_2d0 & 0xffff);
        uVar12 = uVar5 & 0xffffffff;
        if (-1 < (int)uVar5) goto LAB_1400127b7;
      }
      else {
        uVar12 = 0xc000090b;
      }
      RtlFreeUnicodeString(&local_2f0);
      puVar14 = auStack_328;
      goto LAB_140012b26;
    }
    local_2a0 = &local_2d0;
    local_2b0 = CONCAT44(local_2b0._4_4_,0x30);
    uStack_298 = CONCAT44(uStack_298._4_4_,0x240);
    local_290 = 0;
    uStack_288 = 0;
    uStack_2a8 = param_1;
    uVar3 = ZwOpenKey(&local_2e0,0x20019);
    uVar12 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_140012d01;
    uVar5 = StSecpGetSecurityDescriptorPolicy(local_2e0);
    uVar12 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140012d01;
    ZwClose(local_2e0);
    local_2e0 = 0;
LAB_1400127b7:
    local_2d8 = local_2d8 + 1;
  }
  if (uVar3 == 0x8000001a) {
    if (psVar4 != (short *)0x0) {
      RtlInitUnicodeString(&local_2d0,psVar4);
      local_2a0 = &local_2d0;
      local_2b0 = CONCAT44(local_2b0._4_4_,0x30);
      uStack_298 = CONCAT44(uStack_298._4_4_,0x240);
      local_290 = 0;
      uStack_288 = 0;
      uStack_2a8 = param_1;
      uVar3 = ZwOpenKey(&local_2e0,0x20019,&local_2b0);
      uVar12 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar5 = StSecpGetSecurityDescriptorPolicy(local_2e0);
        uVar12 = uVar5 & 0xffffffff;
        if (-1 < (int)uVar5) goto LAB_140012879;
      }
      goto LAB_140012aac;
    }
LAB_140012879:
    local_300 = local_2f8;
    local_308 = (uint *)CONCAT44(local_308._4_4_,0x10);
    uVar3 = ZwQueryValueKey(param_1,&local_2c0,2,&local_278);
    uVar12 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      uVar12 = 0xc000090b;
LAB_140012d01:
      RtlFreeUnicodeString(&local_2f0);
      puVar14 = auStack_328;
      goto LAB_140012b21;
    }
    if (uVar3 != 0x80000005) {
      if (uVar3 != 0xc0000034) goto LAB_140012aac;
      uVar12 = 0;
      goto LAB_140012d01;
    }
    lVar6 = ExAllocatePool2(0x100,local_2f8[0],0x70537453);
    if (lVar6 == 0) {
      uVar12 = 0xc0000017;
      goto LAB_140012d01;
    }
    local_300 = local_2f8;
    local_308 = (uint *)CONCAT44(local_308._4_4_,local_2f8[0]);
    uVar3 = ZwQueryValueKey(param_1,&local_2c0,2,lVar6);
    uVar12 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_140012aac;
    psVar7 = (short *)ExAllocatePool2(0x100,*(undefined4 *)(lVar6 + 8),0x70537453);
    if (psVar7 != (short *)0x0) {
      uVar5 = RtlStringCbCopyW(psVar7,(ulonglong)*(uint *)(lVar6 + 8),lVar6 + 0xc);
      uVar12 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140012aac;
      RtlInitUnicodeString(&local_2c0,L"Debug");
      local_300 = local_2f8;
      local_308 = (uint *)CONCAT44(local_308._4_4_,0x10);
      uVar3 = ZwQueryValueKey(param_1,&local_2c0,2,&local_278);
      uVar12 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
LAB_1400129ce:
        uVar12 = 0xc000090b;
LAB_1400129d3:
        RtlFreeUnicodeString(&local_2f0);
        goto LAB_140012ac2;
      }
      if (uVar3 == 0x80000005) {
        ExFreePoolWithTag(lVar6,0x70537453);
        lVar6 = ExAllocatePool2(0x100,local_2f8[0],0x70537453);
        if (lVar6 != 0) {
          local_300 = local_2f8;
          local_308 = (uint *)CONCAT44(local_308._4_4_,local_2f8[0]);
          uVar3 = ZwQueryValueKey(param_1,&local_2c0,2,lVar6);
          uVar12 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            psVar8 = (short *)ExAllocatePool2(0x100,*(undefined4 *)(lVar6 + 8),0x70537453);
            if (psVar8 == (short *)0x0) {
              uVar12 = 0xc0000017;
              goto LAB_1400129d3;
            }
            uVar5 = RtlStringCbCopyW(psVar8,(ulonglong)*(uint *)(lVar6 + 8),lVar6 + 0xc);
            uVar12 = uVar5 & 0xffffffff;
            if (-1 < (int)uVar5) goto LAB_140012b8e;
          }
          goto LAB_140012aac;
        }
        uVar12 = 0xc0000017;
        goto LAB_1400129d3;
      }
      if (uVar3 != 0xc0000034) goto LAB_140012aac;
LAB_140012b8e:
      local_308 = local_2f8;
      uVar3 = ZwQueryKey(param_1,3,&local_280);
      uVar12 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) goto LAB_1400129ce;
      if (uVar3 != 0x80000005) goto LAB_140012aac;
      puVar9 = (uint *)ExAllocatePool2(0x100,(ulonglong)local_2f8[0] + 4,0x70537453);
      if (puVar9 == (uint *)0x0) {
        uVar12 = 0xc0000017;
        goto LAB_1400129d3;
      }
      local_308 = local_2f8;
      uVar3 = ZwQueryKey(param_1,3,puVar9,local_2f8[0]);
      uVar12 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) goto LAB_140012aac;
      *(undefined2 *)((longlong)puVar9 + (ulonglong)(*puVar9 >> 1) * 2 + 4) = 0x5c;
      *(undefined2 *)((longlong)puVar9 + (ulonglong)(*puVar9 >> 1) * 2 + 6) = 0;
      cVar2 = RtlCreateUnicodeString(&local_2f0,puVar9 + 0x25);
      if (cVar2 == '\0') {
        uVar12 = 0xc0000017;
        goto LAB_1400129d3;
      }
      puVar10 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x70537453);
      if (puVar10 == (undefined8 *)0x0) {
        uVar12 = 0xc0000017;
        goto LAB_1400129d3;
      }
      puVar10[4] = psVar7;
      puVar11 = &g_StSecSecurityDescriptorCacheListHead;
      puVar10[5] = psVar8;
      *(undefined4 *)(puVar10 + 2) = (undefined4)local_2f0;
      *(undefined4 *)((longlong)puVar10 + 0x14) = local_2f0._4_4_;
      *(undefined4 *)(puVar10 + 3) = (undefined4)uStack_2e8;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = uStack_2e8._4_4_;
      if ((undefined8 *)*DAT_1400096e8 != &g_StSecSecurityDescriptorCacheListHead) {
        puVar11 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        puVar10 = (undefined8 *)(*pcVar1)();
        puVar13 = auStack_320;
      }
      *puVar10 = puVar11;
      puVar10[1] = DAT_1400096e8;
      *DAT_1400096e8 = puVar10;
      *(undefined8 *)(puVar13 + 0x40) = 0;
      *(undefined8 *)(puVar13 + -8) = 0x140012ce8;
      DAT_1400096e8 = puVar10;
      RtlFreeUnicodeString(puVar13 + 0x38);
      goto LAB_140012aef;
    }
    uVar12 = 0xc0000017;
    RtlFreeUnicodeString(&local_2f0);
    puVar13 = auStack_328;
LAB_140012af4:
    *(undefined8 *)(puVar13 + -8) = 0x140012b03;
    ExFreePoolWithTag(lVar6,0x70537453);
    puVar14 = puVar13;
  }
  else {
LAB_140012aac:
    RtlFreeUnicodeString(&local_2f0);
    if (psVar7 != (short *)0x0) {
LAB_140012ac2:
      ExFreePoolWithTag(psVar7,0x70537453);
    }
    puVar13 = auStack_328;
    if (psVar8 != (short *)0x0) {
      ExFreePoolWithTag(psVar8,0x70537453);
      puVar13 = auStack_328;
    }
LAB_140012aef:
    puVar14 = puVar13;
    if (lVar6 != 0) goto LAB_140012af4;
  }
  if (puVar9 != (uint *)0x0) {
    *(undefined8 *)(puVar14 + -8) = 0x140012b1c;
    ExFreePoolWithTag(puVar9,0x70537453);
  }
LAB_140012b21:
  if (psVar4 != (short *)0x0) {
LAB_140012b26:
    *(undefined8 *)(puVar14 + -8) = 0x140012b35;
    ExFreePoolWithTag(psVar4,0x70537453);
  }
LAB_140012b3a:
  if (*(longlong *)(puVar14 + 0x48) != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x140012b4b;
    ZwClose();
  }
  *(undefined8 *)(puVar14 + -8) = 0x140012b61;
  return uVar12;
}



===== StSecpGetFolderPropertyPolicy @ 140012d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong StSecpGetFolderPropertyPolicy(undefined8 param_1)

{
  code *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  short *psVar7;
  uint *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int iVar15;
  undefined1 auStack_328 [8];
  undefined1 auStack_320 [24];
  uint *local_308;
  uint *local_300;
  uint local_2f8 [2];
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined8 local_2d8;
  wchar_t *local_2d0;
  undefined8 local_2c8;
  undefined1 *puStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 *local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  ulonglong uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278 [2];
  undefined1 local_268 [12];
  undefined2 local_25c;
  undefined1 local_258 [544];
  ulonglong local_38;
  
  puVar12 = auStack_328;
  puVar14 = auStack_328;
  puVar13 = auStack_328;
  local_38 = __security_cookie ^ (ulonglong)auStack_328;
  local_2d8 = 0x120010;
  local_2d0 = L"FolderId";
  local_2f8[0] = 0;
  local_2c8 = 0;
  puStack_2c0 = (undefined1 *)0x0;
  lVar6 = 0;
  local_278[0] = 0;
  local_298 = 0;
  local_288 = 0;
  uStack_280 = 0;
  puVar8 = (uint *)0x0;
  uStack_290 = uStack_290 & 0xffffffff00000000;
  psVar7 = (short *)0x0;
  local_2f0 = 0;
  uStack_2e8 = 0;
  iVar15 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = (undefined8 *)0x0;
  uStack_2a0 = 0;
  while( true ) {
    local_2e0 = 0;
    local_300 = local_2f8;
    local_308 = (uint *)CONCAT44(local_308._4_4_,0x222);
    uVar4 = ZwEnumerateKey(param_1,iVar15,0,local_268);
    uVar11 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) break;
    puStack_2c0 = local_258;
    local_2b8 = CONCAT44(local_2b8._4_4_,0x30);
    local_2c8._0_4_ = CONCAT22(local_25c,local_25c);
    local_2a8 = &local_2c8;
    uStack_2a0 = CONCAT44(uStack_2a0._4_4_,0x240);
    local_298 = 0;
    uStack_290 = 0;
    uStack_2b0 = param_1;
    uVar4 = ZwOpenKey(&local_2e0,0x20019);
    uVar11 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) goto LAB_140012ebd;
    uVar5 = StSecpGetFolderPropertyPolicy(local_2e0);
    uVar11 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140012ebd;
    ZwClose(local_2e0);
    iVar15 = iVar15 + 1;
  }
  if (uVar4 == 0x8000001a) {
    local_300 = local_2f8;
    local_308 = (uint *)CONCAT44(local_308._4_4_,0x10);
    uVar4 = ZwQueryValueKey(param_1,&local_2d8,2,&local_288);
    uVar11 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if (uVar4 != 0xc0000034) goto LAB_14001315b;
      uVar11 = 0;
    }
    else {
      if ((int)uStack_280 == 4) {
        bVar2 = uStack_280._4_1_;
        RtlInitUnicodeString(&local_2d8,L"ChamberId");
        local_300 = local_2f8;
        local_308 = (uint *)CONCAT44(local_308._4_4_,0x10);
        uVar4 = ZwQueryValueKey(param_1,&local_2d8,2,&local_288);
        uVar11 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          if (uVar4 != 0x80000005) goto LAB_14001315b;
          lVar6 = ExAllocatePool2(0x100,local_2f8[0],0x70537453);
          if (lVar6 == 0) {
            uVar11 = 0xc0000017;
            goto LAB_140012ebd;
          }
          local_300 = local_2f8;
          local_308 = (uint *)CONCAT44(local_308._4_4_,local_2f8[0]);
          uVar4 = ZwQueryValueKey(param_1,&local_2d8,2,lVar6);
          uVar11 = (ulonglong)uVar4;
          if ((int)uVar4 < 0) goto LAB_14001315b;
          psVar7 = (short *)ExAllocatePool2(0x100,*(undefined4 *)(lVar6 + 8),0x70537453);
          if (psVar7 != (short *)0x0) {
            uVar5 = RtlStringCbCopyW(psVar7,(ulonglong)*(uint *)(lVar6 + 8),lVar6 + 0xc);
            uVar11 = uVar5 & 0xffffffff;
            if ((int)uVar5 < 0) goto LAB_14001315b;
            local_308 = local_2f8;
            uVar4 = ZwQueryKey(param_1,3,local_278);
            uVar11 = (ulonglong)uVar4;
            if ((int)uVar4 < 0) {
              if (uVar4 != 0x80000005) goto LAB_14001315b;
              puVar8 = (uint *)ExAllocatePool2(0x100,(ulonglong)local_2f8[0] + 4,0x70537453);
              if (puVar8 == (uint *)0x0) {
                uVar11 = 0xc0000017;
              }
              else {
                local_308 = local_2f8;
                uVar4 = ZwQueryKey(param_1,3,puVar8,local_2f8[0]);
                uVar11 = (ulonglong)uVar4;
                if ((int)uVar4 < 0) goto LAB_14001315b;
                *(undefined2 *)((longlong)puVar8 + (ulonglong)(*puVar8 >> 1) * 2 + 4) = 0x5c;
                *(undefined2 *)((longlong)puVar8 + (ulonglong)(*puVar8 >> 1) * 2 + 6) = 0;
                cVar3 = RtlCreateUnicodeString(&local_2f0,(longlong)puVar8 + 0x8e);
                if (cVar3 == '\0') {
                  uVar11 = 0xc0000017;
                }
                else {
                  puVar9 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x70537453);
                  if (puVar9 != (undefined8 *)0x0) {
                    *(uint *)(puVar9 + 4) = (uint)bVar2;
                    puVar10 = &g_StSecFolderPropertyCacheListHead;
                    puVar9[5] = psVar7;
                    *(undefined4 *)(puVar9 + 2) = (undefined4)local_2f0;
                    *(undefined4 *)((longlong)puVar9 + 0x14) = local_2f0._4_4_;
                    *(undefined4 *)(puVar9 + 3) = (undefined4)uStack_2e8;
                    *(undefined4 *)((longlong)puVar9 + 0x1c) = uStack_2e8._4_4_;
                    if ((undefined8 *)*DAT_1400096f8 != &g_StSecFolderPropertyCacheListHead) {
                      puVar10 = (undefined8 *)0x3;
                      pcVar1 = (code *)swi(0x29);
                      puVar9 = (undefined8 *)(*pcVar1)();
                      puVar12 = auStack_320;
                    }
                    *puVar9 = puVar10;
                    puVar9[1] = DAT_1400096f8;
                    *DAT_1400096f8 = puVar9;
                    *(undefined8 *)(puVar12 + 0x40) = 0;
                    DAT_1400096f8 = puVar9;
                    goto LAB_140013138;
                  }
                  uVar11 = 0xc0000017;
                }
              }
            }
            else {
              uVar11 = 0xc000090b;
            }
            RtlFreeUnicodeString(&local_2f0);
            goto LAB_140013171;
          }
          uVar11 = 0xc0000017;
          puVar12 = auStack_328;
LAB_140013138:
          *(undefined8 *)(puVar12 + -8) = 0x140013144;
          RtlFreeUnicodeString(puVar12 + 0x38);
          puVar13 = puVar12;
          goto LAB_14001318a;
        }
      }
      uVar11 = 0xc000090b;
    }
LAB_140012ebd:
    RtlFreeUnicodeString(&local_2f0);
  }
  else {
LAB_14001315b:
    RtlFreeUnicodeString(&local_2f0);
    if (psVar7 != (short *)0x0) {
LAB_140013171:
      ExFreePoolWithTag(psVar7,0x70537453);
    }
    puVar14 = auStack_328;
    if (lVar6 != 0) {
LAB_14001318a:
      *(undefined8 *)(puVar13 + -8) = 0x140013199;
      ExFreePoolWithTag(lVar6,0x70537453);
      puVar14 = puVar13;
    }
    if (puVar8 != (uint *)0x0) {
      *(undefined8 *)(puVar14 + -8) = 0x1400131b2;
      ExFreePoolWithTag(puVar8,0x70537453);
    }
  }
  if (*(longlong *)(puVar14 + 0x48) != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x1400131c8;
    ZwClose();
  }
  *(undefined8 *)(puVar14 + -8) = 0x1400131de;
  return uVar11;
}



===== FCPreCreate @ 140013210 =====

undefined8 FCPreCreate(ulonglong *param_1,longlong param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  uint uVar12;
  ulonglong *puVar13;
  undefined *puVar14;
  longlong *plVar15;
  ulonglong **ppuVar16;
  undefined8 uVar17;
  undefined1 uVar18;
  int local_res20 [2];
  ulonglong *local_80;
  ulonglong *local_78;
  ulonglong *local_70;
  longlong *local_68;
  ulonglong local_60;
  wchar_t *pwStack_58;
  ulonglong *local_50;
  undefined8 *local_48;
  
  local_70 = (ulonglong *)0x0;
  local_60 = 0;
  pwStack_58 = (wchar_t *)0x0;
  local_78 = (ulonglong *)0x0;
  uVar17 = 0;
  local_68 = (longlong *)0x0;
  local_80 = (ulonglong *)0x0;
  local_res20[0] = 0;
  puVar11 = (undefined8 *)0x0;
  local_48 = (undefined8 *)0x0;
  bVar6 = false;
  bVar4 = false;
  uVar18 = 0;
  ppuVar16 = &local_70;
  iVar8 = FltGetVolumeContext(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10));
  if (-1 < iVar8) {
    lVar3 = *(longlong *)(param_2 + 0x20);
    if ((((*(uint *)(param_1[2] + 0x20) & 0x2000) == 0) &&
        (uVar1 = *(ushort *)(lVar3 + 0x58), 2 < uVar1)) &&
       (*(short *)(*(longlong *)(lVar3 + 0x60) + -2 + (ulonglong)(uVar1 >> 1) * 2) == 0x5c)) {
      *(ushort *)(lVar3 + 0x58) = uVar1 - 2;
    }
    ppuVar16 = &local_78;
    puVar13 = param_1;
    iVar8 = FltGetFileNameInformation(param_1,0x101);
    if (iVar8 < 0) {
      if (*(char *)((longlong)local_70 + 0x31) == '\0') {
        iVar8 = 0;
        goto LAB_1400135e7;
      }
      if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
        puVar14 = &GetFileNameInformationFailure;
        goto LAB_1400135df;
      }
    }
    else {
      puVar13 = local_78;
      iVar8 = FltParseFileNameInformation();
      if (iVar8 < 0) {
        if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
          puVar14 = &ParseFileNameInformationFailure;
          goto LAB_1400135df;
        }
      }
      else if (local_78[0xe] == 0) {
        uVar17 = 1;
      }
      else {
        puVar13 = local_78;
        uVar9 = FCpConstructFullPath((longlong)local_78,(short *)&local_60);
        iVar8 = (int)uVar9;
        if (-1 < iVar8) {
          bVar6 = true;
          bVar4 = true;
          ppuVar16 = &local_80;
          puVar13 = &local_60;
          uVar10 = FCpObtainSecurityInfo
                             ((longlong *)puVar13,&local_68,(longlong *)ppuVar16,local_res20);
          iVar8 = (int)uVar10;
          if (iVar8 < 0) {
            if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
              puVar14 = &ObtainSdAndChamberIdFailure;
              goto LAB_1400135df;
            }
            goto LAB_1400135e4;
          }
          if (*(char *)((longlong)local_70 + 0x31) == '\0') {
            iVar8 = 0;
          }
          else {
            uVar2 = *(uint *)(*(longlong *)(param_1[2] + 0x18) + 0x10);
            ppuVar16 = &local_50;
            puVar13 = param_1;
            plVar15 = local_68;
            iVar8 = FCpAccessCheck((longlong)param_1,local_68,(undefined4 *)ppuVar16);
            uVar10 = Feature_3473298746__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar10 == 0) {
LAB_140013459:
              if (-1 < iVar8) goto LAB_14001351b;
            }
            else if (-1 < iVar8) {
              if (((uVar2 >> 0x19 & 1) != 0) &&
                 (puVar13 = *(ulonglong **)(param_1[2] + 0x18), (uint)puVar13[2] != uVar2)) {
                puVar13 = param_1;
                FltSetCallbackDataDirty();
              }
              goto LAB_140013459;
            }
            if (iVar8 == -0x3fffffde) {
              uVar2 = *(uint *)(param_1[2] + 0x20);
              plVar15 = (longlong *)(ulonglong)uVar2;
              ppuVar16 = (ulonglong **)(ulonglong)(uVar2 & 0xffffff);
              uVar12 = uVar2 >> 0x18;
              puVar13 = (ulonglong *)(ulonglong)uVar12;
              if ((uVar12 - 3 & 0xfffffffd) == 0) {
                iVar8 = 4;
                if (uVar12 != 5) {
                  iVar8 = 1;
                }
                *(uint *)(param_1[2] + 0x20) = iVar8 << 0x18 | uVar2 & 0xffffff;
                ppuVar16 = &local_50;
                puVar13 = param_1;
                plVar15 = local_68;
                iVar8 = FCpAccessCheck((longlong)param_1,local_68,(undefined4 *)ppuVar16);
                if (iVar8 == 0) {
                  uVar18 = 1;
                  puVar13 = param_1;
                  FltSetCallbackDataDirty();
                }
              }
              else if ((uVar12 == 2) && ((uVar2 & 1) != 0)) {
                iVar8 = -0x3fffffcb;
                goto LAB_1400135e4;
              }
            }
            if (iVar8 < 0) {
              if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
                McTemplateK0zd_EtwWriteTransfer(puVar13,plVar15,ppuVar16,pwStack_58,(char)iVar8);
              }
              goto LAB_1400135e4;
            }
          }
LAB_14001351b:
          cVar7 = FsRtlIsMobileOS();
          iVar5 = local_res20[0];
          if (cVar7 == '\0') {
            if (local_res20[0] - 1U < 2) {
              lVar3 = *(longlong *)(*(longlong *)(param_1[2] + 0x18) + 8);
              *(uint *)(lVar3 + 0xc) = *(uint *)(lVar3 + 0xc) | 0x40000;
            }
            if (local_80 != (ulonglong *)0x0) {
              FCpFreeChamberId((short *)local_80);
              local_80 = (ulonglong *)0x0;
              *param_3 = 0;
              goto LAB_1400135e7;
            }
          }
          if (local_80 != (ulonglong *)0x0) {
            puVar13 = (ulonglong *)&gPre2PostCreateContextList;
            puVar11 = (undefined8 *)ExAllocateFromNPagedLookasideList();
            local_48 = puVar11;
            if (puVar11 == (undefined8 *)0x0) {
              iVar8 = -0x3fffff66;
              if ((Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_1400135e4;
              puVar14 = &AllocationFailure;
              iVar8 = -0x3fffff66;
              goto LAB_1400135df;
            }
            *puVar11 = local_80;
            *(int *)(puVar11 + 1) = iVar5;
            *(undefined1 *)((longlong)puVar11 + 0xc) = uVar18;
          }
          *param_3 = (longlong)puVar11;
          goto LAB_1400135e7;
        }
        if ((Microsoft_Windows_FileCryptEnableBits & 1) == 0) goto LAB_1400135e4;
        puVar14 = &ConstructFullPathFailure;
LAB_1400135df:
        McTemplateK0d_EtwWriteTransfer(puVar13,puVar14,ppuVar16,iVar8);
      }
    }
  }
LAB_1400135e4:
  bVar4 = bVar6;
LAB_1400135e7:
  if (local_70 != (ulonglong *)0x0) {
    FltReleaseContext();
  }
  if (local_78 != (ulonglong *)0x0) {
    FltReleaseFileNameInformation();
  }
  if (bVar4) {
    ExFreePoolWithTag(pwStack_58,0x666e4346);
    local_60 = local_60 & 0xffffffff00000000;
  }
  if (local_68 != (longlong *)0x0) {
    ExFreePoolWithTag(local_68,0x70537453);
  }
  if (iVar8 < 0) {
    puVar13 = local_80;
    if (local_80 != (ulonglong *)0x0) {
      FCpFreeChamberId((short *)local_80);
    }
    if (puVar11 != (undefined8 *)0x0) {
      puVar13 = (ulonglong *)&gPre2PostCreateContextList;
      ExFreeToNPagedLookasideList(&gPre2PostCreateContextList,puVar11);
    }
    *(int *)(param_1 + 3) = iVar8;
    param_1[4] = 0;
    uVar17 = 4;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(puVar13,&PreCreateFailure,ppuVar16,iVar8);
    }
  }
  return uVar17;
}



===== FCpAccessCheck @ 1400136d0 =====

int FCpAccessCheck(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined1 uVar9;
  uint uVar10;
  int local_res8 [2];
  undefined4 local_res20 [2];
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  local_res8[0] = 0;
  local_res20[0] = 0;
  uVar1 = *(uint *)(pbVar2 + 0x20);
  lVar3 = *(longlong *)(pbVar2 + 0x18);
  uVar8 = uVar1 >> 0x18;
  uVar10 = *(uint *)(lVar3 + 0x10) | 0x10000;
  if ((uVar1 >> 0xc & 1) == 0) {
    uVar10 = *(uint *)(lVar3 + 0x10);
  }
  if (uVar8 - 4 < 2) {
    uVar10 = uVar10 | 0x112;
  }
  else if (uVar8 - 2 < 2) {
    uVar10 = uVar10 | (uVar1 & 1) * 2 + 2;
  }
  else if (uVar8 == 0) {
    uVar10 = uVar10 | 0x10000;
  }
  uVar9 = *(undefined1 *)(param_1 + 0x50);
  if ((*pbVar2 & 1) != 0) {
    uVar9 = 1;
  }
  if ((gFCFlags & 0x10) == 0) {
    lVar4 = *(longlong *)(lVar3 + 8);
    uVar6 = IoGetFileObjectGenericMapping();
    cVar5 = SeAccessCheck(param_2,lVar4 + 0x20,0,uVar10,*(undefined4 *)(lVar4 + 0x14),0,uVar6,uVar9,
                          local_res20,local_res8);
    if (cVar5 != '\0') {
      *param_3 = local_res20[0];
      uVar7 = Feature_3473298746__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar7 != 0) && ((*(uint *)(lVar3 + 0x10) & 0x2000000) != 0)) {
        *(undefined4 *)(lVar3 + 0x10) = local_res20[0];
        *(undefined4 *)(*(longlong *)(lVar3 + 8) + 0x10) = local_res20[0];
      }
      return local_res8[0];
    }
    if (-1 < local_res8[0]) {
      return -0x3fffffde;
    }
  }
  else {
    local_res8[0] = 0;
  }
  return local_res8[0];
}



===== FCpPreRename$fin$0 @ 140013860 =====

void FCpPreRename_fin_0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  
  if (*(longlong *)(param_2 + 0x50) != 0) {
    FltReleaseContext();
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    FltReleaseFileNameInformation();
    *(undefined8 *)(param_2 + 0x58) = 0;
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    FltReleaseFileNameInformation();
    *(undefined8 *)(param_2 + 0x60) = 0;
  }
  if (*(longlong *)(param_2 + 0x68) == 0) {
    if (*(short **)(param_2 + 0x70) != (short *)0x0) {
      FCpFreeChamberId(*(short **)(param_2 + 0x70));
    }
  }
  else {
    FltReleaseContext();
    *(undefined8 *)(param_2 + 0x68) = 0;
  }
  psVar3 = *(short **)(param_2 + 0x78);
  if (psVar3 != (short *)0x0) {
    FCpFreeChamberId(psVar3);
  }
  if (*(char *)(param_2 + 0x44) != '\0') {
    psVar3 = *(short **)(param_2 + 0x88);
    ExFreePoolWithTag(psVar3,0x666e4346);
    *(undefined4 *)(param_2 + 0x80) = 0;
  }
  if (*(char *)(param_2 + 0x45) != '\0') {
    psVar3 = *(short **)(param_2 + 0x98);
    ExFreePoolWithTag(psVar3,0x666e4346);
    *(undefined4 *)(param_2 + 0x90) = 0;
  }
  iVar1 = *(int *)(param_2 + 0x40);
  if (iVar1 < 0) {
    lVar2 = *(longlong *)(param_2 + 0x140);
    *(int *)(lVar2 + 0x18) = iVar1;
    *(undefined8 *)(lVar2 + 0x20) = 0;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(psVar3,&PreRenameFailure,param_3,iVar1);
    }
  }
  return;
}



===== FCPostCreate$fin$0 @ 140013990 =====

void FCPostCreate_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x40) != 0) {
    FltReleaseContext();
    *(undefined8 *)(param_2 + 0x40) = 0;
  }
  if (*(longlong *)(param_2 + 0x38) != 0) {
    FltReleaseContext();
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  if (*(short **)(param_2 + 0x48) != (short *)0x0) {
    FCpFreeChamberId(*(short **)(param_2 + 0x48));
  }
  return;
}



===== FCInstanceSetup$fin$0 @ 1400139f0 =====

void FCInstanceSetup_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x48),0x70764346);
    *(undefined8 *)(param_2 + 0x48) = 0;
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0x69764346);
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  if (*(longlong *)(param_2 + 0x38) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== FCPreCreate$fin$0 @ 140013a80 =====

void FCPreCreate_fin_0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  
  if (*(longlong *)(param_2 + 0x48) != 0) {
    FltReleaseContext();
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    FltReleaseFileNameInformation();
  }
  if (*(char *)(param_2 + 0x34) != '\0') {
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x60),0x666e4346);
    *(undefined4 *)(param_2 + 0x58) = 0;
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0x70537453);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 < 0) {
    psVar3 = *(short **)(param_2 + 0x38);
    if (psVar3 != (short *)0x0) {
      FCpFreeChamberId(psVar3);
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      psVar3 = (short *)&gPre2PostCreateContextList;
      ExFreeToNPagedLookasideList();
    }
    lVar2 = *(longlong *)(param_2 + 0xc0);
    *(int *)(lVar2 + 0x18) = iVar1;
    *(undefined8 *)(lVar2 + 0x20) = 0;
    if ((Microsoft_Windows_FileCryptEnableBits & 2) != 0) {
      McTemplateK0d_EtwWriteTransfer(psVar3,&PreCreateFailure,param_3,iVar1);
    }
  }
  return;
}



===== FCpEncStreamStart$fin$0 @ 140013b5f =====

void FCpEncStreamStart_fin_0(undefined8 param_1,longlong param_2)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 0x50);
  if (puVar1 != (undefined1 *)0x0) {
    puVar3 = puVar1;
    for (uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x90) + 0x14); uVar2 != 0;
        uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    ExFreePoolWithTag(puVar1,0x72434346);
  }
  if (*(int *)(param_2 + 0x40) < 0) {
    FCpEncStreamCleanup(*(undefined8 **)(param_2 + 0xa8));
  }
  return;
}



===== FCReadDriverParameters @ 140014010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FCReadDriverParameters(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 *local_80;
  undefined4 local_78 [2];
  longlong local_70 [6];
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [12];
  int local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70[0] = 0;
  local_78[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0x30;
  local_70[4] = 0;
  uStack_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_70[5] = param_1;
  iVar1 = ZwOpenKey(local_70,0x20019,local_70 + 3);
  if (-1 < iVar1) {
    if (FcDebugTraceLevel == 0) {
      RtlInitUnicodeString(local_70 + 1,L"DebugTraceLevel");
      local_80 = local_78;
      local_88 = 0x14;
      iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,local_28);
      if (-1 < iVar1) {
        FcDebugTraceLevel = local_1c;
      }
    }
    RtlInitUnicodeString(local_70 + 1,L"EncryptMedia");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,local_28);
    if (-1 < iVar1) {
      if (local_1c == 0) {
        gFCFlags = gFCFlags & 0xfffffffd;
      }
      else {
        gFCFlags = gFCFlags | 2;
      }
    }
    RtlInitUnicodeString(local_70 + 1,L"EncryptAll");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,local_28);
    if (-1 < iVar1) {
      if (local_1c == 0) {
        gFCFlags = gFCFlags & 0xfffffffb;
      }
      else {
        gFCFlags = gFCFlags | 4;
      }
    }
    RtlInitUnicodeString(local_70 + 1,L"BypassAccessChecks");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,local_28);
    if (-1 < iVar1) {
      if (local_1c == 0) {
        gFCFlags = gFCFlags & 0xffffffef;
      }
      else {
        gFCFlags = gFCFlags | 0x10;
      }
    }
    RtlInitUnicodeString(local_70 + 1,L"FilterEmulatedExternalDrive");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,local_28);
    if (-1 < iVar1) {
      if (local_1c == 0) {
        gFCFlags = gFCFlags & 0xfffffff7;
      }
      else {
        gFCFlags = gFCFlags | 8;
      }
    }
    iVar1 = 0;
  }
  if (local_70[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== entry @ 1400142f0 =====

void entry(ushort *param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140014324 =====

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



===== DriverEntry @ 140014360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  ushort *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined4 local_170;
  undefined2 local_168;
  undefined4 local_158;
  uint local_154;
  uint local_150;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  wil_InitializeFeatureStaging();
  puVar9 = (undefined8 *)0x110;
  memset(&local_154,0,0x110);
  local_158 = 0x114;
  iVar7 = RtlGetVersion(&local_158);
  if ((-1 < iVar7) && ((6 < local_154 || ((local_154 == 6 && (1 < local_150)))))) {
    ExDefaultNonPagedPoolType = 0x200;
    ExDefaultMdlProtection = 0x40000000;
  }
  McGenEventRegister_EtwRegister();
  puVar8 = param_2;
  iVar7 = FCReadDriverParameters(param_2);
  bVar5 = false;
  if (-1 < iVar7) {
    uVar1 = *param_2;
    puVar8 = (ushort *)0x40;
    puVar9 = (undefined8 *)0x6e694346;
    DAT_140009718 = ExAllocatePool2(0x40,uVar1 + 2);
    if (DAT_140009718 == 0) {
      iVar7 = -0x3fffff66;
      goto LAB_140014597;
    }
    _DAT_140009712 = uVar1 + 2;
    RtlCopyUnicodeString(&gRegistryPath,param_2);
    uVar10 = ExDefaultNonPagedPoolType | 0x200;
    local_168 = 0;
    local_170 = 0x70704346;
    local_178 = 0x20;
    *(undefined2 *)(DAT_140009718 + (ulonglong)(*param_2 >> 1) * 2) = 0;
    ExInitializeNPagedLookasideList(&gPre2PostIoContextList,0,0,uVar10);
    local_168 = 0;
    local_170 = 0x70704346;
    local_178 = 0x10;
    ExInitializeNPagedLookasideList
              (&gPre2PostCreateContextList,0,0,ExDefaultNonPagedPoolType | 0x200);
    local_168 = 0;
    local_170 = 0x62734346;
    local_178 = 0x10000;
    bVar5 = true;
    ExInitializeNPagedLookasideList(&gShadowBufferList,0,0,ExDefaultNonPagedPoolType | 0x200);
    cVar6 = FsRtlIsMobileOS();
    if (cVar6 != '\0') {
      PTR_Callbacks_140009010 = &CallbacksMobile;
    }
    puVar9 = &gFilterHandle;
    iVar7 = FltRegisterFilter(param_1,&FilterRegistration);
    puVar8 = param_1;
    if (-1 < iVar7) {
      bVar4 = true;
      iVar7 = StSecInitialize((ulonglong)param_1);
      puVar8 = param_1;
      if (-1 < iVar7) {
        bVar3 = true;
        puVar8 = gFilterHandle;
        iVar7 = FltStartFiltering();
      }
    }
  }
  bVar2 = bVar5;
  if (-1 < iVar7) {
    return iVar7;
  }
LAB_140014597:
  if ((Microsoft_Windows_FileCryptEnableBits & 1) != 0) {
    McTemplateK0d_EtwWriteTransfer(puVar8,&DriverEntryFailure,puVar9,iVar7);
  }
  if (bVar2) {
    ExDeleteNPagedLookasideList(&gPre2PostIoContextList);
    ExDeleteNPagedLookasideList(&gPre2PostCreateContextList);
    ExDeleteNPagedLookasideList(&gShadowBufferList);
  }
  if (DAT_140009718 != 0) {
    ExFreePoolWithTag(DAT_140009718,0x6e694346);
  }
  if (bVar3) {
    StSecDeinitialize();
  }
  if (bVar4) {
    FltUnregisterFilter(gFilterHandle);
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
  return iVar7;
}



===== wil_InitializeFeatureStaging @ 1400146a8 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140014798 =====

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



===== FCReadDriverParameters$fin$0 @ 140014880 =====

void FCReadDriverParameters_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
  }
  return;
}


