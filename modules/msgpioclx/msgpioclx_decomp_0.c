
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 140001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_14000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_14000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_14000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_14000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1400010c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1400010e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000114a) */
/* WARNING: Removing unreachable block (ram,0x0001400010f9) */
/* WARNING: Removing unreachable block (ram,0x0001400010ea) */

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



===== _vsnwprintf @ 1400011a8 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 1400011c8 =====

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



===== _vsnprintf @ 1400012c0 =====

int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnprintf_l @ 1400012e0 =====

int __cdecl
_vsnprintf_l(char *_DstBuf,size_t _MaxCount,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if (_Format == (char *)0x0) {
LAB_140001371:
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    if (_MaxCount == 0) {
LAB_140001327:
      local_38._cnt = (int)_MaxCount;
    }
    else {
      if (_DstBuf == (char *)0x0) goto LAB_140001371;
      local_38._cnt = 0x7fffffff;
      if (_MaxCount < 0x80000000) goto LAB_140001327;
    }
    local_38._flag = 0x42;
    local_38._ptr = _DstBuf;
    local_38._base = _DstBuf;
    iVar1 = _output_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (char *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = '\0';
      }
    }
  }
  return iVar1;
}



===== _flsbuf @ 1400013a0 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 1400013b0 =====

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
LAB_140001c74:
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
          uVar20 = (int)(char)(&s__null_)[(ushort)wVar18] & 0xf;
        }
        else {
          uVar20 = uVar8;
        }
        uVar11 = (uint)(ushort)wVar18;
        local_494 = (int)(char)(&__lookuptable)[(int)(local_494 + uVar20 * 8)] >> 4;
        uVar20 = uVar16;
        local_460 = pwVar21;
        if (local_494 == 0) {
LAB_140001b48:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_1400019f6:
          iVar6 = local_4a8;
LAB_1400019fe:
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
LAB_140001a99:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_140001b1c;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_140001b1c:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_140001a08;
                  }
                  local_494 = 0;
                  goto LAB_140001b48;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_140001b1c;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_140001a99;
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
              if (uVar11 == 0x74) goto LAB_140001a99;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_140001a99;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_140001541:
              uVar16 = uVar16 | 0x40;
LAB_140001544:
              uVar19 = 10;
              goto LAB_14000154f;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140001678:
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
LAB_140001601:
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
              if (uVar11 == 0x58) goto LAB_140001752;
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
                  if (puVar3[1] < uVar2) goto LAB_140001c74;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140001c74;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_140001678;
                if (uVar11 == 100) goto LAB_140001541;
              }
            }
LAB_14000188e:
            if (local_478 != 0) goto LAB_1400019fe;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_1400018dc;
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
LAB_1400018dc:
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
                  goto LAB_1400019d2;
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
LAB_1400019d2:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_1400019f6;
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
LAB_140001752:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_140001601;
                  if (wVar18 == L'u') goto LAB_140001544;
                  if (wVar18 != L'x') goto LAB_14000188e;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_14000154f:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_1400017c9;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1400017c9:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_1400017c9;
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
              goto LAB_14000188e;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_140001c74;
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
LAB_140001a08:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 140001cbc =====

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



===== write_multi_char @ 140001d10 =====

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



===== write_string @ 140001d68 =====

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



===== _output_l @ 140001ddc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int __cdecl _output_l(FILE *_File,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  char *pcVar1;
  byte bVar2;
  ushort uVar3;
  wchar_t _WCh;
  ushort *puVar4;
  int *piVar5;
  FILE *pFVar6;
  wchar_t *pwVar7;
  errno_t eVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  wchar_t *pwVar12;
  char cVar13;
  int iVar14;
  uint uVar15;
  wchar_t *pwVar16;
  int iVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  byte *pbVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  uint local_288;
  int local_284;
  byte local_280;
  char local_27f;
  int local_27c;
  int local_278;
  int local_274;
  int local_270;
  wchar_t *local_268;
  int local_260;
  undefined4 local_25c;
  FILE *local_258;
  int local_250 [2];
  wchar_t local_248 [255];
  undefined2 uStack_49;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_25c = 0;
  uVar22 = 0;
  local_270 = 0;
  uVar15 = 0;
  uVar21 = 0;
  local_288 = 0;
  local_260 = 0;
  pwVar16 = (wchar_t *)0x0;
  local_268 = (wchar_t *)_ArgList;
  local_258 = _File;
  memset(local_248,0,0x200);
  local_278 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (char *)0x0)) {
LAB_140002609:
    local_298 = 0;
    _guard_check_icall();
    return -1;
  }
  bVar2 = *_Format;
  iVar17 = 0;
  local_284 = 0;
  local_274 = 0;
  local_27c = 0;
  uVar11 = 0;
joined_r0x000140001e7e:
  if ((bVar2 == 0) || (pbVar20 = (byte *)(_Format + 1), iVar17 < 0)) {
    return iVar17;
  }
  uVar10 = 0;
  if ((byte)(bVar2 - 0x20) < 0x5b) {
    uVar23 = (int)(char)(&s__null_)[(char)bVar2] & 0xf;
  }
  else {
    uVar23 = uVar10;
  }
  iVar14 = (int)(char)bVar2;
  local_274 = (int)(char)(&__lookuptable)[(int)(local_274 + uVar23 * 8)] >> 4;
  if (local_274 == 0) {
LAB_1400024d6:
    local_278 = 0;
    write_char(bVar2,local_258,&local_284);
LAB_1400024ed:
    iVar17 = local_284;
  }
  else {
    if (local_274 == 1) {
      local_260 = 0;
      local_270 = 0;
      local_288 = 0;
      uVar15 = 0xffffffff;
      uVar21 = 0xffffffff;
      local_278 = 0;
      uVar22 = uVar10;
      goto LAB_1400024fa;
    }
    if (local_274 == 2) {
      if (bVar2 == 0x20) {
        uVar22 = uVar22 | 2;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x23) {
        uVar22 = uVar22 | 0x80;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x2b) {
        uVar22 = uVar22 | 1;
        uVar10 = uVar11;
      }
      else if (bVar2 == 0x2d) {
        uVar22 = uVar22 | 4;
        uVar10 = uVar11;
      }
      else {
        uVar10 = uVar11;
        if (bVar2 == 0x30) {
          uVar22 = uVar22 | 8;
        }
      }
      goto LAB_1400024fa;
    }
    if (local_274 == 3) {
      if (bVar2 == 0x2a) {
        iVar14 = *(int *)_ArgList;
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if (iVar14 < 0) {
          uVar22 = uVar22 | 4;
        }
        local_270 = -iVar14;
        if (-1 < iVar14) {
          local_270 = iVar14;
        }
        uVar10 = uVar11;
      }
      else {
        local_270 = iVar14 + (local_270 * 5 + -0x18) * 2;
        uVar10 = uVar11;
      }
      goto LAB_1400024fa;
    }
    if (local_274 == 4) {
      uVar21 = uVar10;
      uVar15 = uVar10;
      uVar10 = uVar11;
      goto LAB_1400024fa;
    }
    if (local_274 == 5) {
      if (bVar2 == 0x2a) {
        uVar21 = *(uint *)_ArgList;
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        uVar15 = uVar21;
        uVar10 = uVar11;
        if ((int)uVar21 < 0) {
          uVar21 = 0xffffffff;
          uVar15 = 0xffffffff;
        }
      }
      else {
        uVar21 = iVar14 + (uVar21 * 5 + -0x18) * 2;
        uVar15 = uVar21;
        uVar10 = uVar11;
      }
      goto LAB_1400024fa;
    }
    if (local_274 == 6) {
      if (bVar2 == 0x49) {
LAB_140002447:
        uVar23 = uVar22 | 0x8000;
        if (bVar2 == 0x49) {
          if (*pbVar20 == 0x36) {
            if (_Format[2] != 0x34) goto LAB_1400024b7;
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar23;
            uVar10 = uVar11;
          }
          else {
            if ((*pbVar20 != 0x33) || (_Format[2] != 0x32)) {
LAB_1400024b7:
              if ((byte)(*pbVar20 + 0xa8) < 0x21) {
                uVar22 = uVar23;
                uVar10 = uVar11;
                if ((0x120821001U >> ((ulonglong)(byte)(*pbVar20 + 0xa8) & 0x3f) & 1) != 0)
                goto LAB_1400024fa;
              }
              local_274 = 0;
              uVar22 = uVar23;
              goto LAB_1400024d6;
            }
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar22 & 0xffff7fff;
            uVar10 = uVar11;
          }
        }
        else {
          uVar22 = uVar23;
          uVar10 = uVar11;
          if (bVar2 != 0x6a) goto LAB_1400024b7;
        }
      }
      else if (bVar2 == 0x68) {
        uVar22 = uVar22 | 0x20;
        uVar10 = uVar11;
      }
      else {
        if (bVar2 == 0x6a) goto LAB_140002447;
        if (bVar2 == 0x6c) {
          bVar2 = *pbVar20;
          if (bVar2 == 0x6c) {
            pbVar20 = (byte *)(_Format + 2);
          }
          uVar10 = 0x1000;
          if (bVar2 != 0x6c) {
            uVar10 = 0x10;
          }
          uVar22 = uVar22 | uVar10;
          uVar10 = uVar11;
        }
        else {
          if (bVar2 == 0x74) goto LAB_140002447;
          if (bVar2 == 0x77) {
            uVar22 = uVar22 | 0x800;
            uVar10 = uVar11;
          }
          else {
            uVar10 = uVar11;
            if (bVar2 == 0x7a) goto LAB_140002447;
          }
        }
      }
      goto LAB_1400024fa;
    }
    uVar10 = uVar11;
    if (local_274 != 7) goto LAB_1400024fa;
    if (iVar14 < 0x6a) {
      if (iVar14 == 0x69) {
LAB_140001f5a:
        uVar22 = uVar22 | 0x40;
LAB_140001f5e:
        uVar19 = 10;
LAB_140001f69:
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 >> 0xf == 0) && ((uVar22 >> 0xc & 1) == 0)) {
          if ((uVar22 & 0x20) == 0) {
            if ((uVar22 & 0x40) != 0) {
              uVar9 = (ulonglong)*(int *)_ArgList;
              goto LAB_1400021bb;
            }
            uVar9 = (ulonglong)*(uint *)_ArgList;
          }
          else if ((uVar22 & 0x40) == 0) {
            uVar9 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
          }
          else {
            uVar9 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1400021bb:
            if ((longlong)uVar9 < 0) {
              uVar9 = -uVar9;
              uVar22 = uVar22 | 0x100;
            }
          }
        }
        else {
          uVar9 = *(ulonglong *)_ArgList;
          if ((uVar22 & 0x40) != 0) goto LAB_1400021bb;
        }
        uVar18 = uVar9 & 0xffffffff;
        if ((uVar22 & 0x9000) != 0) {
          uVar18 = uVar9;
        }
        if ((int)uVar21 < 0) {
          uVar15 = 1;
        }
        else {
          uVar22 = uVar22 & 0xfffffff7;
          if (0x200 < (int)uVar21) {
            uVar15 = 0x200;
          }
        }
        uVar11 = -(uint)(uVar18 != 0) & uVar11;
        pwVar12 = &uStack_49;
        for (; (uVar21 = uVar15 - 1, 0 < (int)uVar15 || (uVar18 != 0)); uVar18 = uVar18 / uVar19) {
          uVar15 = (int)(uVar18 % uVar19) + 0x30;
          cVar13 = (char)uVar15;
          if (0x39 < uVar15) {
            cVar13 = cVar13 + (char)local_25c;
          }
          *(char *)pwVar12 = cVar13;
          pwVar12 = (wchar_t *)((longlong)pwVar12 + -1);
          uVar15 = uVar21;
        }
        local_27c = (int)&uStack_49 - (int)pwVar12;
        pwVar16 = (wchar_t *)((longlong)pwVar12 + 1);
        if (((uVar22 >> 9 & 1) != 0) && ((local_27c == 0 || (*(char *)pwVar16 != '0')))) {
          local_27c = local_27c + 1;
          *(char *)pwVar12 = '0';
          pwVar16 = pwVar12;
        }
        uVar15 = uVar21;
        local_288 = uVar11;
      }
      else if (iVar14 == 0x43) {
        if ((uVar22 & 0x830) == 0) {
          uVar22 = uVar22 | 0x800;
        }
LAB_140002076:
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 & 0x810) == 0) {
          local_248[0]._0_1_ = (char)*(wchar_t *)_ArgList;
          local_27c = 1;
        }
        else {
          eVar8 = wctomb_s(&local_27c,(char *)local_248,0x200,*(wchar_t *)_ArgList);
          if (eVar8 != 0) {
            local_260 = 1;
          }
        }
        pwVar16 = local_248;
      }
      else if (iVar14 == 0x53) {
        if ((uVar22 & 0x830) == 0) {
          uVar22 = uVar22 | 0x800;
        }
LAB_14000201d:
        pwVar16 = *(wchar_t **)_ArgList;
        uVar10 = uVar21;
        if (uVar21 == 0xffffffff) {
          uVar10 = 0x7fffffff;
        }
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 & 0x810) == 0) {
          pwVar12 = L"渨汵⥬";
          pwVar7 = L"渨汵⥬";
          if (pwVar16 != (wchar_t *)0x0) {
            pwVar12 = pwVar16;
            pwVar7 = pwVar16;
          }
          for (; (pwVar16 = pwVar7, uVar10 != 0 && (uVar10 = uVar10 - 1, (char)*pwVar12 != '\0'));
              pwVar12 = (wchar_t *)((longlong)pwVar12 + 1)) {
            pwVar7 = pwVar16;
          }
          local_27c = (int)pwVar12 - (int)pwVar16;
        }
        else {
          if (pwVar16 == (wchar_t *)0x0) {
            pwVar16 = L"(null)";
          }
          local_278 = 1;
          for (pwVar12 = pwVar16; (uVar10 != 0 && (uVar10 = uVar10 - 1, *pwVar12 != L'\0'));
              pwVar12 = pwVar12 + 1) {
          }
          local_27c = (int)((longlong)pwVar12 - (longlong)pwVar16 >> 1);
        }
      }
      else {
        if (iVar14 == 0x58) goto LAB_140002151;
        if (iVar14 == 0x5a) {
          puVar4 = *(ushort **)_ArgList;
          local_268 = (wchar_t *)((longlong)_ArgList + 8);
          if ((puVar4 == (ushort *)0x0) ||
             (pwVar16 = *(wchar_t **)(puVar4 + 4), pwVar16 == (wchar_t *)0x0)) {
            pwVar16 = L"渨汵⥬";
            uVar19 = 0xffffffffffffffff;
            do {
              uVar9 = uVar19 + 1;
              pcVar1 = "null)" + uVar19;
              uVar19 = uVar9;
            } while (*pcVar1 != '\0');
          }
          else {
            uVar3 = *puVar4;
            if (puVar4[1] < uVar3) goto LAB_140002609;
            uVar9 = (ulonglong)(uint)uVar3;
            if ((uVar22 >> 0xb & 1) == 0) {
              local_278 = 0;
            }
            else {
              if (((~(uint)uVar3 & 1) == 0) || ((~(uint)pwVar16 & 1) == 0)) goto LAB_140002609;
              local_278 = 1;
              uVar9 = (ulonglong)(uVar3 >> 1);
            }
          }
          local_27c = (int)uVar9;
        }
        else {
          if (iVar14 == 99) goto LAB_140002076;
          if (iVar14 == 100) goto LAB_140001f5a;
        }
      }
LAB_140002284:
      if (local_260 == 0) {
        if ((uVar22 & 0x40) != 0) {
          if ((uVar22 >> 8 & 1) == 0) {
            if ((uVar22 & 1) == 0) {
              if ((uVar22 & 2) == 0) goto LAB_1400022cd;
              local_280 = 0x20;
            }
            else {
              local_280 = 0x2b;
            }
          }
          else {
            local_280 = 0x2d;
          }
          local_288 = 1;
        }
LAB_1400022cd:
        uVar11 = local_288;
        iVar17 = (local_270 - local_27c) - local_288;
        if ((uVar22 & 0xc) == 0) {
          write_multi_char(0x20,iVar17,local_258,&local_284);
        }
        write_string(&local_280,uVar11,local_258,&local_284);
        pFVar6 = local_258;
        if ((uVar22 & 0xc) == 8) {
          write_multi_char(0x30,iVar17,local_258,&local_284);
        }
        if ((local_278 == 0) || (local_27c < 1)) {
          write_string((byte *)pwVar16,local_27c,pFVar6,&local_284);
        }
        else {
          local_250[0] = 0;
          pwVar12 = pwVar16;
          iVar14 = local_27c;
          do {
            _WCh = *pwVar12;
            pwVar12 = pwVar12 + 1;
            iVar14 = iVar14 + -1;
            eVar8 = wctomb_s(local_250,(char *)((longlong)&uStack_49 + 1),6,_WCh);
            if ((eVar8 != 0) || (local_250[0] == 0)) {
              local_284 = -1;
              break;
            }
            write_string((byte *)((longlong)&uStack_49 + 1),local_250[0],local_258,&local_284);
          } while (iVar14 != 0);
        }
        if ((-1 < local_284) && ((uVar22 & 4) != 0)) {
          write_multi_char(0x20,iVar17,local_258,&local_284);
          uVar11 = local_288;
          goto LAB_1400024ed;
        }
        iVar17 = local_284;
        uVar11 = local_288;
      }
      goto LAB_1400024f5;
    }
    if (iVar14 != 0x6e) {
      if (iVar14 == 0x6f) {
        uVar19 = 8;
        if ((char)uVar22 < '\0') {
          uVar22 = uVar22 | 0x200;
        }
      }
      else {
        if (iVar14 == 0x70) {
          uVar15 = 0x10;
          uVar21 = 0x10;
          uVar22 = uVar22 | 0x8000;
LAB_140002151:
          local_25c = 7;
        }
        else {
          if (iVar14 == 0x73) goto LAB_14000201d;
          if (iVar14 == 0x75) goto LAB_140001f5e;
          if (iVar14 != 0x78) goto LAB_140002284;
          local_25c = 0x27;
        }
        if ((char)uVar22 < '\0') {
          local_27f = (char)local_25c + 'Q';
          local_280 = 0x30;
          uVar11 = 2;
        }
        uVar19 = 0x10;
      }
      goto LAB_140001f69;
    }
    local_268 = (wchar_t *)((longlong)_ArgList + 8);
    piVar5 = *(int **)_ArgList;
    iVar14 = _get_printf_count_output();
    if (iVar14 == 0) goto LAB_140002609;
    if ((uVar22 & 0x20) == 0) {
      *piVar5 = iVar17;
    }
    else {
      *(short *)piVar5 = (short)iVar17;
    }
    local_260 = 1;
  }
LAB_1400024f5:
  uVar10 = uVar11;
LAB_1400024fa:
  bVar2 = *pbVar20;
  _Format = (char *)pbVar20;
  _ArgList = (va_list)local_268;
  uVar11 = uVar10;
  goto joined_r0x000140001e7e;
}



===== write_char @ 140002654 =====

void write_char(byte param_1,FILE *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    piVar1 = &param_2->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = _flsbuf((int)(char)param_1,param_2);
    }
    else {
      *param_2->_ptr = param_1;
      param_2->_ptr = param_2->_ptr + 1;
      uVar2 = (uint)param_1;
    }
    if (uVar2 == 0xffffffff) {
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



===== write_multi_char @ 1400026a4 =====

void write_multi_char(byte param_1,int param_2,FILE *param_3,int *param_4)

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



===== write_string @ 1400026fc =====

void write_string(byte *param_1,int param_2,FILE *param_3,int *param_4)

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



===== _get_printf_count_output @ 140002770 =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_14001e2e0 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 140002790 =====

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



===== mbtowc @ 1400027dc =====

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



===== __GSHandlerCheck @ 140002830 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002854 =====

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



===== _wctomb_s_l @ 1400028bc =====

errno_t __cdecl
_wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale)

{
  int iVar1;
  int local_res10 [4];
  wchar_t local_res20 [4];
  
  if ((_MbCh == (char *)0x0) && (_SizeInBytes != 0)) {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = 0;
    }
  }
  else {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = -1;
    }
    local_res20[0] = _WCh;
    if (0x7fffffff < _SizeInBytes) {
      _guard_check_icall();
      return 0x16;
    }
    if (_MbCh == (char *)0x0) {
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = __mb_cur_max;
      }
    }
    else {
      local_res10[0] = 0;
      iVar1 = RtlUnicodeToMultiByteN(_MbCh,_SizeInBytes & 0xffffffff,local_res10,local_res20,2);
      if (iVar1 < 0) {
        return 0x2a;
      }
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = local_res10[0];
      }
    }
  }
  return 0;
}



===== wctomb_s @ 14000296c =====

errno_t __cdecl wctomb_s(int *_SizeConverted,char *_MbCh,rsize_t _SizeInBytes,wchar_t _WCh)

{
  errno_t eVar1;
  
  eVar1 = _wctomb_s_l(_SizeConverted,_MbCh,_SizeInBytes,_WCh,(_locale_t)0x0);
  return eVar1;
}



===== _flswbuf @ 140002988 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== RtlAnsiCharToUnicodeChar @ 140002999 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002999. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== RtlUnicodeToMultiByteN @ 1400029ab =====

void RtlUnicodeToMultiByteN(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400029ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnicodeToMultiByteN();
  return;
}



===== GpiopAcquireAcpiEventLock @ 1400029c0 =====

void GpiopAcquireAcpiEventLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
    uVar1 = KeGetCurrentIrql();
    *param_2 = uVar1;
    ExAcquireFastMutex(param_1 + 0x78);
  }
  else {
    uVar1 = KfRaiseIrql(*(undefined1 *)(param_1 + 6));
    *param_2 = uVar1;
    KeAcquireSpinLockAtDpcLevel(param_1 + 0xb0);
  }
  return;
}



===== GpiopEnableDisableAcpiEvents @ 140002a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
GpiopEnableDisableAcpiEvents(longlong param_1,byte param_2,char param_3,int param_4,int param_5)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  char *pcVar9;
  undefined8 uVar10;
  char *pcVar11;
  ulonglong uVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined2 uVar15;
  uint uVar16;
  undefined1 auStackY_198 [32];
  undefined *in_stack_fffffffffffffe88;
  char *in_stack_fffffffffffffe90;
  undefined1 uVar17;
  uint local_128;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined1 local_d8 [64];
  undefined4 local_98 [2];
  undefined4 local_90;
  undefined1 local_88;
  undefined4 local_84;
  uint local_80;
  undefined8 local_78;
  undefined2 local_70;
  uint local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  local_e8 = 0;
  local_e0 = 0;
  uVar12 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  memset(local_d8,0,0x40);
  bVar4 = false;
  uVar17 = (undefined1)param_1;
  if (param_2 != 0) {
    uVar12 = *(ulonglong *)(param_1 + 0x2c8);
    (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,uVar12,0);
    if (param_4 == 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_fffffffffffffe90 = "GpiopPrepareForAcpiEvents";
        uVar12 = CONCAT71((int7)(uVar12 >> 8),4);
        in_stack_fffffffffffffe88 = &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids;
        WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xb,0x29,
                           &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                           "GpiopPrepareForAcpiEvents",uVar17);
      }
      ExReInitializeRundownProtection(param_1 + 0x40);
    }
  }
  if (param_5 != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x100) = 1;
    UNLOCK();
    KeInitializeTimer(local_d8);
    KeInitializeDpc(&local_118,GpiopEnableDisableAcpiEventsWatchdog,param_1);
    uVar12 = (longlong)param_5 * -10000000;
    KeSetTimer(local_d8,uVar12,&local_118);
  }
  lVar3 = *(longlong *)(param_1 + 0x68);
  uVar8 = 0;
  local_128 = 0;
  if (*(int *)(lVar3 + 4) != 0) {
    do {
      uVar14 = 1;
      lVar13 = uVar8 * 0x20;
      cVar5 = *(char *)(lVar13 + 9 + lVar3);
      if (cVar5 == '\x02') {
        uVar1 = *(ushort *)(lVar13 + 0xc + lVar3);
        uVar16 = uVar1 & 1;
        uVar6 = *(uint *)(lVar13 + 0x18 + lVar3) & 10;
        if (uVar6 == 10) {
          uVar8 = 3;
        }
        else if (uVar6 == 8) {
          uVar8 = 4;
        }
        else if (uVar6 == 2) {
          uVar8 = 2;
        }
        else {
          uVar8 = (ulonglong)(uVar6 == 0);
        }
        if ((param_3 == '\0') || ((uVar1 & 0x20) == 0)) {
          uVar6 = *(uint *)(lVar13 + 0x10 + lVar3);
          uVar12 = 0;
          LOCK();
          *(uint *)(param_1 + 0x104) = uVar6;
          UNLOCK();
          if (param_4 - 1U < 2) {
            if (*(short *)(lVar13 + 0xe + lVar3) == 1) {
              if (param_2 == 0) {
                (**(code **)(HalPrivateDispatchTable_exref + 0x1e0))(uVar6);
                if (param_4 == 2) {
                  if (!bVar4) {
                    uVar12 = (ulonglong)uVar6;
                    uVar10 = GpiopWaitForCompletionOfMaskedEventingPin(param_1,uVar6);
                    if ((char)uVar10 == '\0') {
                      bVar4 = false;
                      goto LAB_140002e27;
                    }
                  }
                  bVar4 = true;
                }
              }
              else {
                (**(code **)(HalPrivateDispatchTable_exref + 0x1e8))();
              }
            }
LAB_140002e27:
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              pcVar11 = "disabled";
              uVar15 = 0x28;
              pcVar9 = "enabled";
              uVar12 = CONCAT71((int7)(uVar12 >> 8),4);
              goto LAB_140002d2c;
            }
          }
          else {
            sVar2 = *(short *)(lVar13 + 0xe + lVar3);
            if (param_2 == 0) {
              if (sVar2 == 1) {
                uVar14 = uVar8;
                uVar7 = GpioHalDisableInterrupt(uVar6,uVar16,(int)uVar8);
                goto LAB_140002ce9;
              }
LAB_140002cef:
              *(ushort *)(lVar13 + 0xe + lVar3) = (ushort)param_2;
              if (-1 < (int)uVar12) goto LAB_140002e27;
            }
            else {
              if (sVar2 != 0) goto LAB_140002cef;
              uVar14 = 0x60;
              memset(local_98,0,0x60);
              local_98[0] = 1;
              local_78 = 1;
              local_90 = 0;
              local_88 = 3;
              local_70 = 0;
              local_84 = (int)uVar8;
              local_80 = uVar16;
              local_58 = uVar6;
              uVar7 = HalEnableInterrupt(local_98);
LAB_140002ce9:
              uVar12 = (ulonglong)uVar7;
              if (-1 < (int)uVar7) goto LAB_140002cef;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              pcVar11 = "disable";
              uVar15 = 0x27;
              pcVar9 = "enable";
              uVar12 = CONCAT71((int7)(uVar12 >> 8),2);
LAB_140002d2c:
              if (param_2 == 0) {
                pcVar9 = pcVar11;
              }
              WPP_RECORDER_SF_ssDddD
                        (*(undefined8 *)(param_1 + 0x298),(byte)uVar12,uVar14,uVar15,
                         in_stack_fffffffffffffe88,in_stack_fffffffffffffe90,pcVar9,(char)uVar6,
                         (char)uVar16,(char)uVar8,(char)param_4);
            }
          }
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_fffffffffffffe90 = "GpiopEnableDisableAcpiEvents";
        in_stack_fffffffffffffe88 = &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids;
        WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar12,0xb,0x26,
                            &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                            "GpiopEnableDisableAcpiEvents",(char)local_128,cVar5);
      }
      local_128 = local_128 + 1;
      uVar8 = (ulonglong)local_128;
    } while (local_128 < *(uint *)(lVar3 + 4));
  }
  if (param_5 != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 0x100) = 2;
    UNLOCK();
  }
  if (param_2 == 0) {
    if (param_4 == 2) {
      if (bVar4) {
        KeFlushQueuedDpcs();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xb,0x2a,
                           &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                           "GpiopFlushPendingAcpiEvents",uVar17);
      }
      ExWaitForRundownProtectionRelease(param_1 + 0x40);
      ExRundownCompleted(param_1 + 0x40);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xb,0x2b,
                           &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                           "GpiopFlushPendingAcpiEvents",uVar17);
      }
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
  }
  if (param_5 != 0) {
    cVar5 = KeCancelTimer(local_d8);
    if (cVar5 == '\0') {
      KeFlushQueuedDpcs();
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x100) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 0x48) = 0;
    UNLOCK();
  }
  return 0;
}



===== GpiopEnableDisableAcpiEventsWatchdog @ 140002f90 =====

void GpiopEnableDisableAcpiEventsWatchdog(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = *(int *)(param_2 + 0x100);
  iVar3 = 0;
  do {
    LOCK();
    iVar1 = *(int *)(param_2 + 0x100);
    bVar4 = iVar2 == iVar1;
    if (bVar4) {
      *(int *)(param_2 + 0x100) = iVar2;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar4);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      iVar3 = *(int *)(param_2 + 0x104);
      do {
        LOCK();
        iVar1 = *(int *)(param_2 + 0x104);
        bVar4 = iVar3 == iVar1;
        if (bVar4) {
          *(int *)(param_2 + 0x104) = iVar3;
        }
        else {
          iVar3 = iVar1;
        }
        UNLOCK();
      } while (!bVar4);
    }
    else if (iVar2 == 2) {
      iVar3 = *(int *)(param_2 + 0x48);
      do {
        LOCK();
        iVar1 = *(int *)(param_2 + 0x48);
        bVar4 = iVar3 == iVar1;
        if (bVar4) {
          *(int *)(param_2 + 0x48) = iVar3;
        }
        else {
          iVar3 = iVar1;
        }
        UNLOCK();
      } while (!bVar4);
    }
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x138,9,param_2,iVar2,iVar3);
}



===== GpiopIsAcpiEventInterrupt @ 140003024 =====

undefined8 GpiopIsAcpiEventInterrupt(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x68);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar4 = 0;
    if (*(uint *)(lVar1 + 4) != 0) {
      piVar3 = (int *)(lVar1 + 0x10);
      while ((*(char *)((longlong)piVar3 + -7) != '\x02' || (param_2 != *piVar3))) {
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 8;
        if (*(uint *)(lVar1 + 4) <= uVar4) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== GpiopManageAcpiEventing @ 140003064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GpiopManageAcpiEventing(longlong param_1,int param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_res8;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined *local_20;
  
  local_res8 = 0;
  local_3c = 0;
  local_28 = 0;
  local_20 = PTR__WDF_EVENT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e138;
  local_30 = *(undefined8 *)(param_1 + 0x2c8);
  local_50 = 0x38;
  pcStack_60 = GpiopManageAcpiEventingWorkerWrapper;
  local_78 = 0;
  uStack_70 = 0;
  local_38 = 1;
  local_4c = 0;
  uStack_44 = 0;
  local_34 = 1;
  local_68 = 0x18;
  local_58 = 0;
  KeWaitForSingleObject(param_1 + 0x50,0,0,0,0);
  pbVar1 = (byte *)(param_1 + 0xfc);
  if (param_2 == 2) {
    if ((*pbVar1 & 2) != 0) {
      *pbVar1 = *pbVar1 & 0xfe;
    }
LAB_140003122:
    if ((*pbVar1 & 1) == 0) goto LAB_14000312e;
    param_3 = '\x01';
  }
  else {
    if (param_2 != 5) goto LAB_140003122;
LAB_14000312e:
    if (param_3 == '\0') {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_68,&local_50,&local_res8);
      if (iVar2 < 0) {
        param_3 = '\x01';
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,0xb,10,
                            &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)iVar2);
        }
      }
      else {
        puVar3 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res8,
                            PTR__WDF_EVENT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e138);
        if (puVar3 != (undefined8 *)0x0) goto LAB_1400031cd;
      }
    }
  }
  puVar3 = &local_78;
LAB_1400031cd:
  *puVar3 = 0;
  puVar3[1] = 0;
  *puVar3 = *(undefined8 *)(param_1 + 0x2c8);
  *(int *)(puVar3 + 1) = param_2;
  *(char *)((longlong)puVar3 + 0xc) = param_3;
  if (param_3 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res8);
  }
  else {
    GpiopManageAcpiEventingWorker(puVar3);
  }
  return 0;
}



===== GpiopManageAcpiEventingWorker @ 140003228 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopManageAcpiEventingWorker(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  
  cVar5 = '\0';
  bVar4 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*param_1);
  iVar1 = *(int *)(param_1 + 1);
  if (iVar1 == 5) {
LAB_14000329c:
    GpiopDestroyAcpiEventing(lVar2,cVar5);
    goto LAB_1400032a7;
  }
  if ((*(byte *)(lVar2 + 0xfc) & 1) != 0) goto LAB_1400032a7;
  if (iVar1 < 6) {
    if (iVar1 == 0) {
      iVar1 = GpiopInitiateAcpiEventing(lVar2);
    }
    else {
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          bVar4 = 1;
        }
        else if (iVar1 != 3) {
          if (iVar1 != 4) goto LAB_1400032a7;
          cVar5 = '\x01';
          goto LAB_14000329c;
        }
        iVar1 = 0;
        cVar5 = '\0';
        goto LAB_140003334;
      }
      iVar1 = GpiopAllocateAcpiEventResources(lVar2);
    }
  }
  else {
    if (iVar1 == 6) {
      bVar4 = 1;
LAB_140003328:
      iVar1 = 1;
      cVar5 = '\x01';
LAB_140003334:
      iVar6 = 0;
    }
    else {
      if (iVar1 == 7) goto LAB_140003328;
      if (iVar1 == 8) {
        iVar1 = 2;
        cVar5 = '\0';
        bVar4 = 1;
        goto LAB_140003334;
      }
      if (iVar1 != 9) goto LAB_1400032a7;
      cVar5 = '\0';
      iVar6 = 0x24e;
      iVar1 = 2;
      bVar4 = 0;
    }
    uVar3 = GpiopEnableDisableAcpiEvents(lVar2,bVar4,cVar5,iVar1,iVar6);
    iVar1 = (int)uVar3;
  }
  if (iVar1 < 0) {
    *(byte *)(lVar2 + 0xfc) = *(byte *)(lVar2 + 0xfc) | 1;
  }
LAB_1400032a7:
  KeSetEvent(lVar2 + 0x50,0,0);
  return;
}



===== GpiopManageAcpiEventingWorkerWrapper @ 140003360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopManageAcpiEventingWorkerWrapper(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_EVENT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e138)
  ;
  GpiopManageAcpiEventingWorker(puVar1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== GpiopPowerAcpiEventingCallback @ 1400033c0 =====

undefined8
GpiopPowerAcpiEventingCallback(undefined8 param_1,int *param_2,int param_3,longlong param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_3 == 4) {
    iVar1 = *param_2;
    if (*(int *)(param_4 + 0xf8) == iVar1) {
      uVar2 = 0;
    }
    else {
      *(int *)(param_4 + 0xf8) = iVar1;
      uVar2 = GpiopManageAcpiEventing(param_4,(iVar1 != 0) + 6,'\x01');
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== GpiopProcessAcpiEventsCommon @ 140003408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopProcessAcpiEventsCommon(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x390))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x2c8),0x45784347,0xa91,
             "onecore\\drivers\\gpio\\gpioclx\\sys\\acpievt.c");
  if ((GpioForceEmergencyWorker == '\0') &&
     (cVar1 = ExTryQueueWorkItem(lVar3 + 0x18,1), cVar1 != '\0')) {
    return;
  }
  GpioHubQueueEmergencyWorkItem((undefined8 *)(lVar3 + 0x18));
  return;
}



===== GpiopProcessAcpiEventsDpc @ 1400034d0 =====

void GpiopProcessAcpiEventsDpc(undefined8 param_1)

{
  GpiopProcessAcpiEventsCommon(param_1);
  return;
}



===== GpiopProcessAcpiEventsWorker @ 1400034f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpiopProcessAcpiEventsWorker(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  char *pcVar9;
  ushort uVar10;
  undefined1 auStackY_d8 [32];
  undefined8 *in_stack_ffffffffffffff48;
  undefined8 in_stack_ffffffffffffff50;
  undefined1 local_88 [4];
  char local_84 [4];
  undefined4 local_80;
  int local_7c;
  uint local_78;
  undefined8 local_70;
  undefined8 *puStack_68;
  int local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_40 = 0;
  local_38 = 0;
  local_60 = 0;
  local_70 = 0;
  puStack_68 = (undefined8 *)0x0;
  local_58 = 0;
  local_84[0] = 'L';
  local_84[1] = 'E';
  local_88[0] = 0;
  local_50 = (**(code **)(WdfFunctions_01015 + 0x150))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
  local_48 = 0;
  GpiopAcquireAcpiEventLock(param_1,local_88);
  do {
    uVar3 = RtlFindSetBitsAndClear(param_1 + 0xe0,1);
    if ((uVar3 == 0xffffffff) || ((short)uVar3 == -1)) {
      LOCK();
      *(undefined4 *)(param_1 + 0x38) = 0;
      UNLOCK();
      if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
        ExReleaseFastMutex(param_1 + 0x78);
      }
      else {
        KeReleaseSpinLockFromDpcLevel(param_1 + 0xb0);
        KeLowerIrql(local_88[0]);
      }
      ExReleaseRundownProtection(param_1 + 0x40);
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),0x45784347,0xbb0);
      return;
    }
    if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
      ExReleaseFastMutex(param_1 + 0x78);
    }
    else {
      KeReleaseSpinLockFromDpcLevel(param_1 + 0xb0);
      KeLowerIrql(local_88[0]);
    }
    pcVar9 = (char *)0x0;
    lVar6 = GpiopGetPinEntryFromPinNumberInternal(param_1,uVar3 & 0xffff,'\0');
    local_78 = *(uint *)(lVar6 + 0x100);
    local_7c = *(int *)(lVar6 + 0xec);
    if ((*(uint *)(lVar6 + 0xc0) & 0x40) == 0) {
      pcVar9 = "_%c%02X";
      in_stack_ffffffffffffff48 =
           (undefined8 *)
           (CONCAT44((int)((ulonglong)in_stack_ffffffffffffff48 >> 0x20),uVar3) & 0xffffffff0000ffff
           );
      RtlStringCbPrintfA((char *)&local_48,5,"_%c%02X",
                         (ulonglong)(uint)(int)local_84[*(int *)(lVar6 + 0xec)]);
      uVar7 = (undefined4)local_48;
    }
    else {
      uVar1 = (ulonglong)local_48 >> 0x20;
      local_48 = CONCAT44((uint)uVar1 & 0xffffff00,0x5456455f);
      uVar7 = 0x5456455f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_ssD(*(undefined8 *)(param_1 + 0x298),4,pcVar9,0x2d,in_stack_ffffffffffffff48,
                          in_stack_ffffffffffffff50,(char *)&local_48,(char)uVar3);
      uVar7 = (undefined4)local_48;
    }
    uVar4 = *(uint *)(lVar6 + 0xc0) & 0x40;
    if (uVar4 == 0) {
      local_40._0_4_ = 0x42696541;
    }
    else {
      local_40._0_4_ = 0x49696541;
      local_38 = uVar3 & 0xffff;
    }
    local_40 = CONCAT44(uVar7,(undefined4)local_40);
    puStack_68 = &local_40;
    local_70 = 1;
    local_5c = 0;
    local_60 = (-(uint)(uVar4 != 0) & 4) + 8;
    uVar10 = 0;
    LOCK();
    *(undefined4 *)(param_1 + 0x48) = uVar7;
    UNLOCK();
    do {
      uVar1 = ((ulonglong)uVar3 & 0xffffffff0000ffff) / (ulonglong)*(ushort *)(param_1 + 0x2d6);
      uVar2 = ((ulonglong)uVar3 & 0xffffffff0000ffff) % (ulonglong)*(ushort *)(param_1 + 0x2d6);
      local_80 = (undefined4)uVar2;
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        McTemplateK0zhh_EtwWriteTransfer
                  (uVar1,&EVENT_ACPI_EVENT_METHOD_START,
                   *(longlong *)(param_1 + 0x2e0) + 0x70 + uVar1 * 400,
                   *(wchar_t **)(param_1 + 0x300),(char)uVar1,(char)uVar2);
      }
      lVar6 = 0;
      in_stack_ffffffffffffff48 = &local_70;
      in_stack_ffffffffffffff50 = 0;
      uVar8 = WdfDriverGlobals;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x5d0))();
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        lVar6 = *(longlong *)(param_1 + 0x2e0) + 0x70 + uVar1 * 400;
        McTemplateK0h_EtwWriteTransfer
                  (uVar8,&EVENT_ACPI_EVENT_METHOD_COMPLETE,lVar6,(undefined2)local_80);
      }
      if ((iVar5 == -0x3fffffcc) || (iVar5 == -0x3ffffff2)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ssD(*(undefined8 *)(param_1 + 0x298),2,lVar6,0x2e,
                              in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,(char *)&local_48,
                              (char)iVar5);
        }
        break;
      }
      if (-1 < iVar5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ss(*(undefined8 *)(param_1 + 0x298));
        }
        break;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ssD(*(undefined8 *)(param_1 + 0x298),2,lVar6,0x2f,in_stack_ffffffffffffff48,
                            in_stack_ffffffffffffff50,(char *)&local_48,(char)iVar5);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 4);
    if (local_7c == 0) {
      GpiopUnmaskInterrupt(param_1,4,local_78);
    }
    GpiopAcquireAcpiEventLock(param_1,local_88);
  } while( true );
}



===== GpiopWaitForCompletionOfMaskedEventingPin @ 14000396c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopWaitForCompletionOfMaskedEventingPin(longlong param_1,int param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort local_res18 [4];
  longlong local_res20;
  
  local_res20 = 0;
  local_res18[0] = 0xffff;
  lVar3 = GpiopGetPinEntryFromVirq(param_1,param_2,&local_res20,(ushort *)0x0,local_res18);
  if (((GpioEmOverrideAttributes & 1) == 0) || (uVar4 = 0, lVar3 != 0)) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))
              (WdfDriverGlobals,*(undefined8 *)(local_res20 + 0x30),0);
    lVar2 = local_res20;
    *(void **)(local_res20 + 0x38) = SystemReserved1[0xf];
    uVar1 = *(undefined4 *)(lVar3 + 0xc0);
    *(undefined8 *)(local_res20 + 0x38) = 0;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x9d0))
                      (WdfDriverGlobals,*(undefined8 *)(local_res20 + 0x30));
    if ((char)uVar1 < '\0') {
      uVar5 = GpiopWaitForStateMachineCompletionOfDebouncedMaskedPin(lVar2,lVar3,local_res18[0]);
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003a48 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14001e088;
  uVar2 = 0;
  if (DAT_14001e088 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14001e088;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(GPIO_PROVIDER_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0h_EtwWriteTransfer @ 140003aac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0h_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined2 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_20 = 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0zhh_EtwWriteTransfer @ 140003b04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zhh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_3c = 0;
  local_38 = &param_5;
  local_30 = 2;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = &param_6;
  local_20 = 2;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,param_3,4,local_58);
  return;
}



===== RtlStringCbPrintfA @ 140003bac =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerA(param_1,param_2,(size_t *)0x0,param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar1;
}



===== WPP_RECORDER_SF_ @ 140003bf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 140003cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_qD @ 140003dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_s @ 140003ef8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,char *param_6)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sD @ 140004050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_sDD @ 1400041d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,0);
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
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sq @ 140004380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,8,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_sqD @ 140004508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,8,&param_8,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar2,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_ss @ 1400046c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ss(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,0x30,"GpiopProcessAcpiEventsWorker",
               0x1d,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,0xb,&WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,0x30,
                  "GpiopProcessAcpiEventsWorker",0x1d,in_stack_00000038,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_ssD @ 140004804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined8 param_6,char *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,param_4,
               "GpiopProcessAcpiEventsWorker",0x1d,pcVar3,lVar2,&param_8,4,0);
  }
  lVar2 = -1;
  if (param_7 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_7[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,0xb,&WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,param_4,
                  "GpiopProcessAcpiEventsWorker",0x1d,param_7,lVar1,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_ssDddD @ 140004980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssDddD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,char *param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,param_4,
               "GpiopEnableDisableAcpiEvents",0x1d,pcVar3,lVar2,&param_8,4,&param_9,4,&param_10,4,
               &param_11,4,0);
  }
  lVar2 = -1;
  if (param_7 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_7[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,0xb,&WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,param_4,
                  "GpiopEnableDisableAcpiEvents",0x1d,param_7,lVar1,&param_8,4,&param_9,4,&param_10,
                  4,&param_11,4,0);
  return;
}



===== GpioClxBankEvtProcessDeviceIoControl @ 140004b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxBankEvtProcessDeviceIoControl
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint local_18 [4];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  local_18[0] = 0;
  if (param_5 == 0x480000) {
    uVar4 = GpiopProcessReadPinsRequest(lVar3,uVar2,param_2,local_18);
    iVar1 = (int)uVar4;
  }
  else if (param_5 == 0x480004) {
    uVar4 = GpiopProcessWritePinsRequest(lVar3,uVar2,param_2,local_18);
    iVar1 = (int)uVar4;
  }
  else if (param_5 == 0x48000c) {
    iVar1 = GpiopProcessFastIoInterfaceRequest(lVar3,uVar2,param_2,local_18);
  }
  else {
    if (param_5 != 0x480010) {
      iVar1 = -0x3ffffff0;
      goto LAB_140004be0;
    }
    uVar4 = GpiopProcessFunctionConfigPinsCommitRequest(lVar3,uVar2,param_2,local_18);
    iVar1 = (int)uVar4;
  }
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar1,local_18[0]);
    return;
  }
LAB_140004be0:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== GpioClxEvtDeviceD0Entry @ 140004c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClxEvtDeviceD0Entry(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  LOCK();
  puVar2[0xb4] = 6;
  UNLOCK();
  iVar1 = (**(code **)(puVar2 + 0x5e))(puVar2 + 0x100,param_2 != 5,param_2);
  if (iVar1 < 0) {
    LOCK();
    puVar2[0xb4] = 7;
    UNLOCK();
    puVar2[0x51] = iVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(puVar2 + 0xa6),2,2,0xf,
                        &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)iVar1);
    }
    LOCK();
    puVar2[0x4b] = 1;
    UNLOCK();
    if (*(char *)(puVar2 + 0x50) != '\0') {
      PoFxReportDevicePoweredOn(*(undefined8 *)(puVar2 + 0x46));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(puVar2 + 0xa6),4,3,0x10,
                           &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                           "GpioClxEvtDeviceD0Entry",(char)puVar2);
      }
    }
  }
  else {
    LOCK();
    puVar2[0xb4] = 8;
    UNLOCK();
    LOCK();
    *puVar2 = 1;
    UNLOCK();
  }
  return iVar1;
}



===== GpioClxEvtDeviceD0Exit @ 140004dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClxEvtDeviceD0Exit(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  
  piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190)
  ;
  if (param_2 == 5) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x160))(WdfDriverGlobals,param_1);
    if ((iVar1 == 0x337) || (iVar1 == 0x8338)) {
      LOCK();
      piVar3[0x4b] = 1;
      UNLOCK();
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  iVar2 = 0;
  LOCK();
  iVar1 = piVar3[0xb4];
  piVar3[0xb4] = 9;
  UNLOCK();
  if (iVar1 == 8) {
    iVar2 = (**(code **)(piVar3 + 0x60))(piVar3 + 0x100,uVar4,param_2);
    if (iVar2 < 0) {
      LOCK();
      piVar3[0xb4] = 10;
      UNLOCK();
      piVar3[0x51] = iVar2;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(piVar3 + 0xa6),2,2,0x11,
                          &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)iVar2);
      }
      piVar3 = piVar3 + 0x4b;
      param_2 = 1;
      goto LAB_140004ee5;
    }
  }
  LOCK();
  piVar3[0xb4] = 0xb;
  UNLOCK();
LAB_140004ee5:
  LOCK();
  *piVar3 = param_2;
  UNLOCK();
  return iVar2;
}



===== GpioClxEvtDevicePostInterruptsEnabled @ 140004f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GpioClxEvtDevicePostInterruptsEnabled(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar2 = 0;
  cVar1 = *(char *)(lVar3 + 0x140);
  *(undefined1 *)(lVar3 + 0x140) = 0;
  if (cVar1 != '\0') {
    PoFxReportDevicePoweredOn(*(undefined8 *)(lVar3 + 0x118));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(lVar3 + 0x298),4,3,0x13,
                         &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                         "GpioClxEvtDevicePostInterruptsEnabled",(char)lVar3);
    }
  }
  if (((*(char *)(lVar3 + 0x130) != '\0') && (*(char *)(lVar3 + 0x141) != '\0')) &&
     (uVar6 = 0, *(short *)(lVar3 + 0x2d8) != 0)) {
    do {
      GpiopSetInterruptState
                (uVar6 * 400,*(longlong *)(uVar6 * 400 + *(longlong *)(lVar3 + 0x2e0)),'\0');
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(ushort *)(lVar3 + 0x2d8));
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  if (*(char *)(lVar4 + 0x130) == '\0') {
    uVar6 = 0;
    if (*(short *)(lVar4 + 0x2d8) != 0) {
      do {
        if (*(char *)(uVar6 * 400 + 0x158 + *(longlong *)(lVar4 + 0x2e0)) == '\x01') {
          (**(code **)(WdfFunctions_01015 + 0x4d0))
                    (WdfDriverGlobals,
                     *(undefined8 *)(uVar6 * 400 + 0x58 + *(longlong *)(lVar4 + 0x2e0)));
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(ushort *)(lVar4 + 0x2d8));
    }
  }
  else {
    *(undefined1 *)(lVar4 + 0x130) = 0;
  }
  if (cVar1 != '\0') {
    GpiopManageAcpiEventing(lVar3,8,'\x01');
  }
  if (((*(byte *)(lVar3 + 4) & 2) != 0) && (*(code **)(lVar3 + 0x280) != (code *)0x0)) {
    uVar2 = (**(code **)(lVar3 + 0x280))(lVar3 + 0x400);
  }
  return uVar2;
}



===== GpioClxEvtDevicePreInterruptsDisabled @ 1400050f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GpioClxEvtDevicePreInterruptsDisabled(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  
  puVar3 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190
                             );
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(puVar3 + 0xa6),4,2,0x12,
                       &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                       "GpioClxEvtDevicePreInterruptsDisabled",(char)puVar3);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x120));
  *(undefined1 *)(lVar4 + 0x128) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x120));
  uVar2 = 0;
  uVar5 = 0;
  if (*(short *)(lVar4 + 0x2d8) != 0) {
    do {
      (**(code **)(WdfFunctions_01015 + 0x4e0))
                (WdfDriverGlobals,
                 *(undefined8 *)((ulonglong)uVar5 * 400 + 0x58 + *(longlong *)(lVar4 + 0x2e0)));
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(lVar4 + 0x2d8));
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x120));
  *(undefined1 *)(lVar4 + 0x128) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x120));
  if (param_2 == 5) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1);
    LOCK();
    uVar5 = *puVar3;
    *puVar3 = -(uint)(iVar1 != 0) & 5;
    UNLOCK();
    if (iVar1 != 0) {
      GpiopManageAcpiEventing((longlong)puVar3,3,'\x01');
    }
    GpiopCleanupAllBanksInterruptIo((longlong)puVar3,iVar1 == 0);
    LOCK();
    *puVar3 = uVar5;
    UNLOCK();
  }
  if (((puVar3[1] & 2) != 0) && (*(code **)(puVar3 + 0x9e) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar3 + 0x9e))(puVar3 + 0x100);
  }
  return uVar2;
}



===== GpioClxEvtDeviceQueryStop @ 140005320 =====

undefined8 GpioClxEvtDeviceQueryStop(void)

{
  return 0xc0000001;
}



===== GpioClxEvtDeviceReleaseHardware @ 140005330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClxEvtDeviceReleaseHardware(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  (**(code **)(WdfFunctions_01015 + 0xd20))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x108),1);
  GpiopManageAcpiEventing(lVar2,4,'\x01');
  GpiopCleanupInterruptStormMitigation(lVar2);
  if (4 < *(int *)(lVar2 + 0x2d0)) {
    LOCK();
    *(undefined4 *)(lVar2 + 0x2d0) = 0;
    UNLOCK();
    iVar1 = (**(code **)(lVar2 + 0x170))(param_1,lVar2 + 0x400);
    if (iVar1 < 0) {
      LOCK();
      *(undefined4 *)(lVar2 + 0x2d0) = 1;
      UNLOCK();
      *(int *)(lVar2 + 0x144) = iVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(lVar2 + 0x298),2,2,0xe,
                        &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)iVar1);
      return iVar1;
    }
  }
  LOCK();
  *(undefined4 *)(lVar2 + 0x2d0) = 2;
  UNLOCK();
  return iVar1;
}



===== GpioClxEvtDeviceSelfManagedIoInit @ 140005450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClxEvtDeviceSelfManagedIoInit(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  uVar5 = 0;
  if (*(short *)(lVar2 + 0x2d8) != 0) {
    do {
      uVar4 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      lVar3 = uVar4 * 400 + *(longlong *)(lVar2 + 0x2e0);
      *(undefined4 *)(lVar3 + 0x15c) = 0;
      *(undefined1 *)(lVar3 + 0x158) = 1;
    } while (uVar5 < *(ushort *)(lVar2 + 0x2d8));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(lVar2 + 0x298),4,2,0x28,
                      &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                      "GpioClxEvtDeviceSelfManagedIoInit");
  }
  iVar1 = GpiopRegisterWithPowerFramework(lVar2);
  if (-1 < iVar1) {
    GpiopStartRuntimePowerManagement(lVar2);
    *(undefined1 *)(lVar2 + 0x2a0) = 1;
  }
  return iVar1;
}



===== GpioClxEvtProcessDeviceIoControl @ 140005540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtProcessDeviceIoControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  undefined4 local_18 [4];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  local_18[0] = 0;
  if ((param_5 == 0x480000) || (param_5 == 0x480004)) {
LAB_14000574e:
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if ((lVar5 == 0) ||
       (lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,lVar5,
                           PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), lVar5 == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x1c;
LAB_140005882:
        WPP_RECORDER_SF_q(*(undefined8 *)(lVar3 + 0x298),2,7,uVar6,
                          &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)param_2);
      }
    }
    else {
      uVar4 = *(uint *)(lVar5 + 100) & 8;
      if (param_5 == 0x480010) {
        if (uVar4 != 0) goto LAB_1400057f8;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1d;
          goto LAB_140005882;
        }
      }
      else {
        if (uVar4 == 0) {
LAB_1400057f8:
          if (*(ushort *)(lVar5 + 0x18) < *(ushort *)(lVar3 + 0x2d8)) {
            lVar5 = (ulonglong)*(ushort *)(lVar5 + 0x18) * 400 + *(longlong *)(lVar3 + 0x2e0);
          }
          else {
            lVar5 = 0;
          }
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                            (WdfDriverGlobals,param_2,*(undefined8 *)(lVar5 + 0x58));
          if (-1 < iVar1) {
            return;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1400058ac;
          uVar7 = (undefined1)*(undefined2 *)(lVar5 + 0x80);
          uVar6 = 0x1f;
          goto LAB_1400056a2;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1e;
          goto LAB_140005882;
        }
      }
    }
    iVar1 = -0x3fffff45;
  }
  else {
    if (param_5 == 0x480008) {
      iVar1 = GpiopProcessControllerSpecificFunctionIoctl(lVar3,uVar2,param_2,local_18);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar1,local_18[0]);
        return;
      }
      goto LAB_1400058ac;
    }
    if (param_5 != 0x48000c) {
      if (param_5 != 0x480010) {
        iVar1 = -0x3ffffff0;
        goto LAB_1400058ac;
      }
      goto LAB_14000574e;
    }
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if ((lVar5 == 0) ||
       (lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,lVar5,
                           PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), lVar5 == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(lVar3 + 0x298),2,7,0x20,
                          &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)param_2);
      }
      iVar1 = -0x3ffffff8;
      goto LAB_1400058ac;
    }
    if (*(ushort *)(lVar5 + 0x18) < *(ushort *)(lVar3 + 0x2d8)) {
      lVar5 = (ulonglong)*(ushort *)(lVar5 + 0x18) * 400 + *(longlong *)(lVar3 + 0x2e0);
    }
    else {
      lVar5 = 0;
    }
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(lVar5 + 0x58));
    if (-1 < iVar1) {
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400058ac;
    uVar7 = (undefined1)*(undefined2 *)(lVar5 + 0x80);
    uVar6 = 0x21;
LAB_1400056a2:
    WPP_RECORDER_SF_DD(*(undefined8 *)(lVar3 + 0x298),2,5,uVar6,
                       &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,uVar7,(char)iVar1);
  }
LAB_1400058ac:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== GpioClxWdmPreprocessPowerIrp @ 1400058f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxWdmPreprocessPowerIrp(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar2 + 0x10) == 0) {
    if (*(int *)(lVar2 + 0x18) == 1) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
      *(undefined1 *)(lVar2 + 0x140) = 1;
    }
  }
  else if ((*(int *)(lVar2 + 0x10) == 1) && (*(int *)(lVar2 + 0x18) - 2U < 3)) {
    piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_1,
                               PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
    iVar1 = 0;
    LOCK();
    if (*piVar3 == 0) {
      *piVar3 = 0;
    }
    else {
      iVar1 = *piVar3;
    }
    UNLOCK();
    if ((iVar1 == 1) &&
       ((((iVar1 = *(int *)(lVar2 + 0x20), iVar1 == 2 || (iVar1 == 3)) || (iVar1 == 4)) ||
        ((iVar1 == 5 || (iVar1 == 6)))))) {
      GpiopManageAcpiEventing((longlong)piVar3,9,'\x01');
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== GpioClxWdmPreprocessQueryDeviceRelationsIrp @ 140005a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxWdmPreprocessQueryDeviceRelationsIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) && (*(char *)(lVar1 + 0x2a0) != '\0')) {
    *(undefined1 *)(lVar1 + 0x2a0) = 0;
    GpiopManageAcpiEventing(lVar1,2,'\0');
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_DD @ 140005aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Dq @ 140005bd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140005d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== RtlUnicodeStringPrintf @ 140005dfc =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== WPP_RECORDER_SF_d @ 140005e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 140005f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined4 local_18 [4];
  
  uVar1 = GpioLogHandle;
  local_18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7a904fd07a903c99ae3b7ea3fe2bc9c4_Traceguids,0xb,&uStack0000000000000030,4,
               local_18,4,0);
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_7a904fd07a903c99ae3b7ea3fe2bc9c4_Traceguids,0xb,
                  &uStack0000000000000030,4,local_18,4,0);
  return;
}



===== GpioClxAcquireInterruptLock @ 140006060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxAcquireInterruptLock(longlong param_1,ulonglong param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  
  uVar4 = -(ulonglong)(param_1 != 0) & param_1 - 0x400U;
  if ((uVar4 == 0) || (*(int *)(uVar4 + 0x2c0) != 0x4f495047)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(GpioLogHandle,2,8,0x17,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                          "GpioClxAcquireInterruptLock",(char)param_1,(char)param_2);
    }
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,2,param_1,1,0);
  }
  if ((*(ushort *)(uVar4 + 0x2d8) <= (ushort)param_2) ||
     (plVar3 = (longlong *)((param_2 & 0xffff) * 400 + *(longlong *)(uVar4 + 0x2e0)),
     plVar3 == (longlong *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(uVar4 + 0x298),param_2,8,0x18,
                          &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                          "GpioClxAcquireInterruptLock",(char)param_2,
                          (char)*(ushort *)(uVar4 + 0x2d8));
    }
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,2,uVar4,2,
                 (longlong)(int)((uint)*(ushort *)(uVar4 + 0x2d8) << 0x10) | param_2 & 0xffff);
  }
  if ((*(uint *)(uVar4 + 0x314) & 1) == 0) {
    if ((void *)plVar3[7] != SystemReserved1[0xf]) {
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar3[6],0);
      plVar3[7] = (longlong)SystemReserved1[0xf];
      *(undefined1 *)(plVar3 + 8) = 1;
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000619f;
    uVar5 = 0x1a;
  }
  else {
    if ((void *)plVar3[4] != SystemReserved1[0xf]) {
      lVar2 = *plVar3;
      if (lVar2 == 0) {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar2 = plVar3[3];
      }
      else {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar1)(WdfDriverGlobals,lVar2);
      plVar3[4] = (longlong)SystemReserved1[0xf];
      *(undefined1 *)(plVar3 + 5) = 1;
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000619f;
    uVar5 = 0x19;
  }
  WPP_RECORDER_SF_sq(*(undefined8 *)(uVar4 + 0x298),2,8,uVar5,
                     &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,"GpioClxAcquireInterruptLock",
                     (char)uVar4);
LAB_14000619f:
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x138,2,uVar4,3,0);
}



===== GpioClxReleaseInterruptLock @ 140006300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxReleaseInterruptLock(longlong param_1,ulonglong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  uVar5 = param_2 & 0xffff;
  uVar4 = -(ulonglong)(param_1 != 0) & param_1 - 0x400U;
  uVar6 = (undefined1)uVar5;
  if ((uVar4 == 0) || (*(int *)(uVar4 + 0x2c0) != 0x4f495047)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(GpioLogHandle,2,8,0x1b,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                          "GpioClxReleaseInterruptLock",(char)param_1,uVar6);
    }
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,2,param_1,1,0);
  }
  if ((*(ushort *)(uVar4 + 0x2d8) <= (ushort)param_2) ||
     (plVar2 = (longlong *)(uVar5 * 400 + *(longlong *)(uVar4 + 0x2e0)), param_2 = 0,
     plVar2 == (longlong *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(uVar4 + 0x298),param_2,8,0x1c,
                          &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                          "GpioClxReleaseInterruptLock",uVar6,(char)*(ushort *)(uVar4 + 0x2d8));
    }
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,2,uVar4,2,(longlong)(int)((uint)*(ushort *)(uVar4 + 0x2d8) << 0x10) | uVar5);
  }
  if ((*(uint *)(uVar4 + 0x314) & 1) == 0) {
    if ((char)plVar2[8] != '\0') {
      *(undefined1 *)(plVar2 + 8) = 0;
      plVar2[7] = 0;
      lVar3 = plVar2[6];
      pcVar1 = *(code **)(WdfFunctions_01015 + 0x9d0);
LAB_140006496:
      (*pcVar1)(WdfDriverGlobals,lVar3);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(uVar4 + 0x298),plVar2,8,0x1e,
                          &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                          "GpioClxReleaseInterruptLock",uVar6,(char)*(undefined2 *)(uVar4 + 0x2d8));
    }
  }
  else {
    if ((char)plVar2[5] != '\0') {
      lVar3 = *plVar2;
      *(undefined1 *)(plVar2 + 5) = 0;
      plVar2[4] = 0;
      if (lVar3 == 0) {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar3 = plVar2[3];
      }
      else {
        pcVar1 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      goto LAB_140006496;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(uVar4 + 0x298),2,8,0x1d,
                         &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                         "GpioClxReleaseInterruptLock",(char)uVar4);
    }
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x138,2,uVar4,4,0);
}



===== WPP_RECORDER_SF_qqq @ 1400065ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,0);
  return;
}



===== GpioClnInvokeClearActiveInterrupts @ 140006698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpioClnInvokeClearActiveInterrupts(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStackY_78 [32];
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_48 = *(undefined2 *)(param_1 + 0x80);
  local_46 = 0;
  local_42 = 0;
  local_38 = 0;
  local_40 = param_2;
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0zhx_EtwWriteTransfer
              (param_1,&EVENT_CLEAR_ACTIVE_INTERRUPTS_START,param_1 + 0x70,
               *(wchar_t **)(lVar1 + 0x300),(char)local_48,(char)param_2);
  }
  lVar3 = lVar1 + 0x400;
  iVar2 = (**(code **)(lVar1 + 0x1c0))(lVar3,&local_48);
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0x_EtwWriteTransfer
              (lVar3,&EVENT_CLEAR_ACTIVE_INTERRUPTS_COMPLETE,param_1 + 0x70,param_2);
  }
  if ((iVar2 < 0) && ((*(uint *)(lVar1 + 0x314) & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,5,(longlong)iVar2,lVar1);
  }
  *param_3 = local_38;
  return iVar2;
}



===== GpioClnInvokeConnectPins @ 1400067b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GpioClnInvokeConnectPins
          (longlong param_1,undefined8 param_2,ushort param_3,undefined4 param_4,longlong param_5)

{
  code *pcVar1;
  undefined8 uVar2;
  ulonglong local_38;
  undefined8 uStack_30;
  uint local_28;
  undefined4 uStack_24;
  undefined8 uStack_20;
  longlong local_18;
  ulonglong uStack_10;
  
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x88) + 0x1c8);
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0xc00000bb;
  }
  else {
    uStack_20 = 0;
    _local_28 = CONCAT44(param_4,(uint)param_3);
    local_38 = (ulonglong)*(ushort *)(param_1 + 0x80);
    local_18 = 0;
    uStack_10 = 0;
    if (param_5 != 0) {
      uStack_20 = (ulonglong)*(ushort *)(param_5 + 0xc) << 0x10;
      uStack_20 = CONCAT71(uStack_20._1_7_,*(undefined1 *)(param_5 + 9));
      uStack_20 = (ulonglong)CONCAT24(*(undefined2 *)(param_5 + 10),(undefined4)uStack_20);
      if (*(ushort *)(param_5 + 0x15) != 0) {
        local_18 = (ulonglong)*(ushort *)(param_5 + 0x13) + param_5;
        uStack_10 = (ulonglong)*(ushort *)(param_5 + 0x15);
      }
    }
    uStack_30 = param_2;
    uVar2 = (*pcVar1)(*(longlong *)(param_1 + 0x88) + 0x400,&local_38);
  }
  return uVar2;
}



===== GpioClnInvokeCreateIoContext @ 14000686c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
GpioClnInvokeCreateIoContext
          (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x88);
  if (((*(byte *)(lVar1 + 4) & 2) != 0) && (*(code **)(lVar1 + 600) != (code *)0x0)) {
    uVar2 = (**(code **)(lVar1 + 600))
                      (lVar1 + 0x400,*(undefined2 *)(param_1 + 0x80),param_2,param_3,param_4,param_5
                      );
  }
  return uVar2;
}



===== GpioClnInvokeDeleteIoContext @ 1400068d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GpioClnInvokeDeleteIoContext(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((*(byte *)(param_1 + 4) & 2) != 0) && (*(longlong *)(param_1 + 600) != 0)) &&
     (*(code **)(param_1 + 0x260) != (code *)0x0)) {
    uVar1 = (**(code **)(param_1 + 0x260))(param_1 + 0x400);
  }
  return uVar1;
}



===== GpioClnInvokeDisableInterrupt @ 140006918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClnInvokeDisableInterrupt(longlong param_1,undefined2 param_2,char param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_res8._0_4_ = CONCAT22(param_2,*(undefined2 *)(param_1 + 0x80));
  uVar2 = (uint)local_res8;
  local_res8 = (ulonglong)(uint)local_res8;
  if (param_3 != '\0') {
    local_res8 = CONCAT44(1,uVar2);
  }
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0zhh_EtwWriteTransfer
              (param_1,&EVENT_DISABLE_INTERRUPT_START,param_1 + 0x70,*(wchar_t **)(lVar1 + 0x300),
               (char)*(undefined2 *)(param_1 + 0x80),(char)param_2);
  }
  lVar4 = lVar1 + 0x400;
  iVar3 = (**(code **)(lVar1 + 0x1a0))(lVar4,&local_res8);
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0h_EtwWriteTransfer(lVar4,&EVENT_DISABLE_INTERRUPT_COMPLETE,param_1 + 0x70,param_2);
  }
  if ((iVar3 < 0) && ((*(uint *)(lVar1 + 0x314) & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,5,(longlong)iVar3,lVar1,&local_res8);
  }
  return iVar3;
}



===== GpioClnInvokeMaskInterrupts @ 140006a0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpioClnInvokeMaskInterrupts(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStackY_78 [32];
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_48 = *(undefined2 *)(param_1 + 0x80);
  local_46 = 0;
  local_42 = 0;
  local_38 = 0;
  local_40 = param_2;
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0zhx_EtwWriteTransfer
              (param_1,&EVENT_MASK_INTERRUPTS_START,param_1 + 0x70,*(wchar_t **)(lVar1 + 0x300),
               (char)local_48,(char)param_2);
  }
  lVar3 = lVar1 + 0x400;
  iVar2 = (**(code **)(lVar1 + 0x1b0))(lVar3,&local_48);
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0x_EtwWriteTransfer(lVar3,&EVENT_MASK_INTERRUPTS_COMPLETE,param_1 + 0x70,param_2);
  }
  *param_3 = local_38;
  if ((iVar2 < 0) && ((*(uint *)(lVar1 + 0x314) & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,5,(longlong)iVar2,lVar1);
  }
  return iVar2;
}



===== GpioClnInvokeQueryEnabledInterrupts @ 140006b24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpioClnInvokeQueryEnabledInterrupts(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined2 local_38;
  undefined6 local_36;
  undefined2 uStack_30;
  undefined6 uStack_2e;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_38 = *(undefined2 *)(param_1 + 0x80);
  local_36 = 0;
  uStack_30 = 0;
  uStack_2e = 0;
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0zh_EtwWriteTransfer
              (param_1,&EVENT_QUERY_ENABLED_INTERRUPTS_START,param_1 + 0x70,
               *(wchar_t **)(lVar1 + 0x300),(char)local_38);
  }
  lVar3 = lVar1 + 0x400;
  iVar2 = (**(code **)(lVar1 + 0x210))(lVar3,&local_38);
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(lVar3,&EVENT_QUERY_ENABLED_INTERRUPTS_COMPLETE,param_1 + 0x70);
  }
  if ((iVar2 < 0) && ((*(uint *)(lVar1 + 0x314) & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,5,(longlong)iVar2,lVar1);
  }
  *param_2 = CONCAT62(uStack_2e,uStack_30);
  return iVar2;
}



===== GpioClnInvokeQueryInterruptBinding @ 140006c28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GpioClnInvokeQueryInterruptBinding
          (longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined2 *param_5)

{
  undefined8 uVar1;
  char *pcVar2;
  ulonglong uVar3;
  ushort uVar4;
  int iVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  
  uVar1 = 0xc0000002;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(code **)(param_1 + 400) != (code *)0x0) {
    local_48 = 0x3000000001;
    local_28 = (ulonglong)*(ushort *)(param_1 + 0x2d8);
    local_38 = param_2;
    uStack_30 = param_3;
    uVar1 = (**(code **)(param_1 + 400))(param_1 + 0x400,&local_48,param_5);
    if (((int)uVar1 != -0x3ffffffe) && ((int)uVar1 != -0x3fffff45)) {
      return uVar1;
    }
  }
  if (*(ushort *)(param_1 + 0x2d8) <= param_4) {
    *param_5 = 1;
    uVar4 = 0;
    (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_2);
    iVar5 = 0;
    if (*(short *)(param_1 + 0x2d8) != 0) {
      do {
        pcVar2 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,iVar5);
        if (*pcVar2 == '\x02') {
          uVar3 = (ulonglong)uVar4;
          uVar4 = uVar4 + 1;
          *(int *)(param_5 + uVar3 * 2 + 4) = iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (uVar4 < *(ushort *)(param_1 + 0x2d8));
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== GpioClnInvokeReadPins @ 140006d6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClnInvokeReadPins
              (longlong param_1,undefined8 param_2,uint param_3,undefined8 param_4,
              undefined8 param_5,ulonglong param_6,byte param_7)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  ulonglong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  ulonglong local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_10 = local_10 & 0xffffffffffff0000;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_40 = local_40 & 0xffffffffffff0000;
  pcVar2 = *(code **)(lVar1 + 0x1d8);
  puVar5 = (ulonglong *)0x0;
  if ((*(uint *)(lVar1 + 0x314) & 4) == 0) {
    if (pcVar2 == (code *)0x0) {
LAB_140006dd5:
      iVar3 = -0x3fffff45;
      goto LAB_140006e7c;
    }
    puVar5 = &local_38;
    local_10 = param_6;
    local_18 = (ulonglong)(param_7 & 1);
    puVar4 = &local_38;
    local_38 = (ulonglong)*(ushort *)(param_1 + 0x80);
    local_28 = (ulonglong)param_3;
    uStack_30 = param_2;
    uStack_20 = param_4;
  }
  else {
    if (pcVar2 == (code *)0x0) goto LAB_140006dd5;
    puVar5 = &local_58;
    puVar4 = &local_58;
    uStack_50 = param_5;
    local_40 = param_6;
    local_48 = (ulonglong)(param_7 & 1);
    local_58 = (ulonglong)*(ushort *)(param_1 + 0x80);
  }
  iVar3 = (*pcVar2)(lVar1 + 0x400,puVar4);
  if (-1 < iVar3) {
    return iVar3;
  }
LAB_140006e7c:
  if ((*(uint *)(lVar1 + 0x314) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,6,(longlong)iVar3,lVar1,puVar5);
  }
  return iVar3;
}



===== GpioClnInvokeWritePins @ 140006ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClnInvokeWritePins
              (longlong param_1,undefined8 param_2,uint param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,ulonglong param_7)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x88);
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_18 = local_18 & 0xffffffffffff0000;
  local_30 = 0;
  uStack_28 = 0;
  local_48 = local_48 & 0xffffffffffff0000;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar5 = (ulonglong *)0x0;
  pcVar2 = *(code **)(lVar1 + 0x1e0);
  if ((*(uint *)(lVar1 + 0x314) & 4) == 0) {
    if (pcVar2 == (code *)0x0) {
LAB_140006f36:
      iVar3 = -0x3fffff45;
      goto LAB_140006fc3;
    }
    puVar5 = &local_40;
    puVar4 = &local_40;
    local_18 = param_7;
    local_40 = (ulonglong)*(ushort *)(param_1 + 0x80);
    local_30 = (ulonglong)param_3;
    uStack_38 = param_2;
    uStack_28 = param_4;
  }
  else {
    if (pcVar2 == (code *)0x0) goto LAB_140006f36;
    puVar5 = &local_68;
    puVar4 = &local_68;
    uStack_60 = param_5;
    local_58 = param_6;
    local_48 = param_7;
    local_68 = (ulonglong)*(ushort *)(param_1 + 0x80);
  }
  local_20 = 0;
  uStack_50 = 0;
  iVar3 = (*pcVar2)(lVar1 + 0x400,puVar4);
  if (-1 < iVar3) {
    return iVar3;
  }
LAB_140006fc3:
  if ((*(uint *)(lVar1 + 0x314) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,6,(longlong)iVar3,lVar1,puVar5);
  }
  return iVar3;
}



===== McTemplateK0_EtwWriteTransfer @ 140007014 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0x_EtwWriteTransfer @ 140007058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0zh_EtwWriteTransfer @ 1400070b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zh_EtwWriteTransfer
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
  local_20 = 2;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0zhx_EtwWriteTransfer @ 14000714c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zhx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_3c = 0;
  local_38 = &param_5;
  local_30 = 2;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = &param_6;
  local_20 = 8;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,param_3,4,local_58);
  return;
}



===== McGenControlCallbackV2 @ 140007200 =====

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



===== McGenEventRegister_EtwRegister @ 140007310 =====

void McGenEventRegister_EtwRegister(void)

{
  if (GPIO_PROVIDER_Context == 0) {
    EtwRegister(&GPIO_PROVIDER,McGenControlCallbackV2,&GPIO_PROVIDER_Context,&GPIO_PROVIDER_Context)
    ;
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140007350 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (GPIO_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    GPIO_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== WppClassicProviderCallback @ 140007390 =====

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



===== wil_details_RecordCachedUsage @ 1400073ec =====

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



===== wil_details_RecordFeatureUsageReporting @ 140007540 =====

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



===== GpiopCheckEnabledInterrupts @ 1400075c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopCheckEnabledInterrupts(longlong *param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  byte bVar9;
  ulonglong uVar10;
  ulonglong local_res8;
  
  local_res8 = 0;
  if ((GpioCheckEnabledInterrupts != '\0') && (*(longlong *)(param_1[0x11] + 0x210) != 0)) {
    bVar2 = true;
    bVar9 = *(byte *)(param_1[0x11] + 0x314) & 1;
    if ((bVar9 == 0) || ((void *)param_1[9] == SystemReserved1[0xf])) {
      bVar2 = false;
    }
    else {
      lVar8 = *param_1;
      if (lVar8 == 0) {
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar8 = param_1[3];
      }
      else {
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar5)(WdfDriverGlobals,lVar8);
      param_1[4] = (longlong)SystemReserved1[0xf];
    }
    iVar3 = GpioClnInvokeQueryEnabledInterrupts((longlong)param_1,&local_res8);
    if (bVar2) {
      lVar8 = *param_1;
      param_1[4] = 0;
      if (lVar8 == 0) {
        lVar8 = param_1[3];
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e8);
      }
      else {
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar5)(WdfDriverGlobals,lVar8);
    }
    if (-1 < iVar3) {
      if (*(ushort *)(param_1 + 0x30) < 0x21) {
        uVar6 = 0;
        LOCK();
        uVar1 = *(uint *)(param_1 + 0x28);
        if (uVar1 == 0) {
          *(uint *)(param_1 + 0x28) = 0;
        }
        else {
          uVar6 = (ulonglong)uVar1;
        }
        UNLOCK();
      }
      else {
        uVar6 = 0;
        LOCK();
        uVar10 = param_1[0x28];
        if (uVar10 == 0) {
          param_1[0x28] = 0;
        }
        else {
          uVar6 = uVar10;
        }
        UNLOCK();
      }
      uVar10 = ~uVar6 & local_res8;
      if (bVar9 == 0) {
        if (*(ushort *)(param_1 + 0x30) < 0x21) {
          uVar4 = 0;
          LOCK();
          uVar1 = *(uint *)(param_1 + 0x1c);
          if (uVar1 == 0) {
            *(uint *)(param_1 + 0x1c) = 0;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
          uVar7 = (ulonglong)uVar4;
        }
        else {
          uVar7 = 0;
          LOCK();
          uVar6 = param_1[0x1c];
          if (uVar6 == 0) {
            param_1[0x1c] = 0;
          }
          else {
            uVar7 = uVar6;
          }
          UNLOCK();
        }
        uVar10 = uVar10 & ~uVar7;
      }
      if (uVar10 != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,8,param_1,uVar10 >> 0x20,uVar10 & 0xffffffff);
      }
    }
  }
  return;
}



===== GpiopCleanupAllBanksInterruptIo @ 140007764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopCleanupAllBanksInterruptIo(longlong param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  ushort uVar8;
  ushort uVar9;
  
  uVar9 = 0;
  if (*(short *)(param_1 + 0x2d8) != 0) {
    do {
      lVar7 = (ulonglong)uVar9 * 400 + *(longlong *)(param_1 + 0x2e0);
      lVar4 = *(longlong *)(lVar7 + 0x88);
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
      uVar8 = 0;
      *(void **)(lVar7 + 0x38) = SystemReserved1[0xf];
      if (*(short *)(lVar7 + 0x180) != 0) {
        do {
          lVar6 = GpiopGetPinEntryInternal(lVar7,uVar8,'\0');
          if ((lVar6 != 0) && ((*(uint *)(lVar6 + 0xc0) & 4) != 0)) {
            uVar1 = *(undefined4 *)(lVar6 + 0x100);
            uVar2 = *(undefined4 *)(lVar6 + 0xec);
            uVar3 = *(undefined4 *)(lVar6 + 0xf0);
            *(undefined8 *)(lVar7 + 0x38) = 0;
            (**(code **)(WdfFunctions_01015 + 0x9d0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
            GpioHalDisableInterrupt(uVar1,uVar2,uVar3);
            (**(code **)(WdfFunctions_01015 + 0x9c8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
            *(void **)(lVar7 + 0x38) = SystemReserved1[0xf];
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(lVar7 + 0x180));
      }
      while( true ) {
        plVar5 = *(longlong **)(lVar7 + 0x60);
        if (plVar5 == (longlong *)(lVar7 + 0x60)) break;
        *(undefined8 *)(lVar7 + 0x38) = 0;
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
        GpiopDisconnectGpioPins(lVar4,plVar5,param_2);
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
        *(void **)(lVar7 + 0x38) = SystemReserved1[0xf];
      }
      *(undefined8 *)(lVar7 + 0x38) = 0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(ushort *)(param_1 + 0x2d8));
  }
  return;
}



===== GpiopConnectFunctionConfigPinsLocked @ 140007968 =====

ulonglong GpiopConnectFunctionConfigPinsLocked
                    (longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined2 uVar12;
  longlong *plVar13;
  uint uVar14;
  uint uVar15;
  
  uVar14 = *(uint *)(param_3 + 0x28);
  uVar11 = (ulonglong)uVar14;
  uVar7 = 0;
  puVar3 = *(ushort **)(param_3 + 0x20);
  lVar4 = *(longlong *)(param_3 + 0x58);
  plVar13 = *(longlong **)(param_3 + 0x30);
  uVar10 = 0;
  uVar1 = *(ushort *)(lVar4 + 0xc);
  if (uVar14 != 0) {
    plVar6 = plVar13;
    puVar8 = puVar3;
    do {
      lVar5 = *plVar6;
      uVar2 = *puVar8;
      uVar15 = *(uint *)(lVar5 + 0xc0);
      if (((uVar15 & 5) != 0) || ((uVar15 & 2) != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000a126;
        }
        WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),lVar5,0xc,0x50,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                            "GpiopConnectFunctionConfigPinsLocked",
                            (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                            (char)*(undefined2 *)(param_2 + 0x80) + (char)uVar2,(char)uVar15);
        return 0xc000a126;
      }
      uVar9 = *(uint *)(lVar5 + 0xd0);
      if ((uVar9 == 0) && (((uVar1 & 1) != 0 || ((uVar15 & 8) != 0)))) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000a126;
        }
        uVar12 = 0x51;
        uVar10 = (uint)((byte)uVar1 & 1);
        uVar9 = (uint)*(ushort *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                (uint)*(ushort *)(param_2 + 0x80) + (uint)uVar2;
        uVar14 = uVar9;
LAB_140007b1b:
        WPP_RECORDER_SF_sDDD
                  (*(undefined8 *)(param_1 + 0x298),(ulonglong)uVar9,0xc,uVar12,
                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                   "GpiopConnectFunctionConfigPinsLocked",(char)uVar14,(char)uVar15,(char)uVar10);
        return 0xc000a126;
      }
      if (uVar9 != param_4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000a126;
        }
        uVar12 = 0x52;
        uVar14 = (uint)*(ushort *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                 (uint)*(ushort *)(param_2 + 0x80) + (uint)uVar2;
        uVar15 = param_4;
        uVar10 = uVar9;
        goto LAB_140007b1b;
      }
      puVar8 = puVar8 + 1;
      uVar10 = uVar10 + 1;
      plVar6 = plVar6 + 1;
    } while (uVar10 < uVar14);
    if ((uVar1 & 1) == 0) {
      do {
        lVar5 = *plVar13;
        if (*(int *)(lVar5 + 0xd0) == 0) {
          uVar10 = *(uint *)(lVar5 + 0xc0);
          *(uint *)(lVar5 + 0xc0) = uVar10 | 8;
          *(uint *)(lVar5 + 0x104) = (uint)*(ushort *)(lVar4 + 0xf);
          *(uint *)(lVar5 + 0xc0) = uVar10 | 0x208;
          if ((uVar10 & 4) == 0) {
            *(undefined8 *)(lVar5 + 0xec) = 0;
            *(undefined8 *)(lVar5 + 0xf8) = 0;
            LOCK();
            *(undefined4 *)(lVar5 + 0x100) = 0;
            UNLOCK();
            *(undefined4 *)(lVar5 + 0xd8) = 0;
            *(undefined2 *)(lVar5 + 0x108) = 0;
            *(undefined1 *)(lVar5 + 0xe8) = *(undefined1 *)(lVar4 + 0xe);
          }
        }
        *(int *)(lVar5 + 0xd0) = *(int *)(lVar5 + 0xd0) + 1;
        plVar13 = plVar13 + 1;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    else {
      do {
        lVar5 = *plVar13;
        if (*(int *)(lVar5 + 0xd0) == 0) {
          uVar10 = *(uint *)(lVar5 + 0xc0);
          *(uint *)(lVar5 + 0xc0) = uVar10 | 8;
          *(uint *)(lVar5 + 0x104) = (uint)*(ushort *)(lVar4 + 0xf);
          *(uint *)(lVar5 + 0xc0) = uVar10 & 0xfffffdff | 8;
          if ((uVar10 & 4) == 0) {
            *(undefined8 *)(lVar5 + 0xec) = 0;
            *(undefined8 *)(lVar5 + 0xf8) = 0;
            LOCK();
            *(undefined4 *)(lVar5 + 0x100) = 0;
            UNLOCK();
            *(undefined4 *)(lVar5 + 0xd8) = 0;
            *(undefined2 *)(lVar5 + 0x108) = 0;
            *(undefined1 *)(lVar5 + 0xe8) = *(undefined1 *)(lVar4 + 0xe);
          }
        }
        *(int *)(lVar5 + 0xd0) = *(int *)(lVar5 + 0xd0) + 1;
        plVar13 = plVar13 + 1;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
  }
  if (param_4 == 1) {
    uVar7 = GpioClnInvokeConnectFunctionConfigPins(param_2,puVar3,(ushort)uVar14,lVar4 + 8);
    uVar7 = uVar7 & 0xffffffff;
  }
  return uVar7;
}



===== GpiopConnectGpioPinsLocked @ 140007c80 =====

ulonglong GpiopConnectGpioPinsLocked
                    (longlong param_1,longlong param_2,longlong param_3,int param_4,
                    undefined8 *param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  byte bVar6;
  ulonglong uVar7;
  char cVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  ulonglong uVar13;
  byte bVar14;
  undefined2 uVar15;
  longlong *plVar16;
  uint uVar17;
  longlong *plVar18;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff80;
  uint local_58;
  undefined2 *local_48;
  longlong *local_40;
  
  lVar2 = *(longlong *)(param_3 + 0x58);
  local_48 = *(undefined2 **)(param_3 + 0x20);
  uVar1 = *(uint *)(param_3 + 0x28);
  uVar10 = (ulonglong)uVar1;
  iVar12 = 0;
  plVar18 = *(longlong **)(param_3 + 0x30);
  lVar3 = *(longlong *)(param_3 + 0x38);
  bVar6 = *(byte *)(lVar2 + 0xf) & 8;
  bVar14 = *(byte *)(lVar2 + 0xf) & 3;
  if (*(char *)(lVar2 + 0xc) != '\x01') {
    bVar14 = 0;
  }
  if (bVar14 == 1) {
    if (param_4 == 1) goto LAB_140007d73;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000a126;
    }
    uVar15 = 0x66;
  }
  else {
    if ((bVar14 != 2) || (param_4 == 2)) {
LAB_140007d73:
      uVar11 = 0;
      if (param_4 == 2) {
        *(uint *)(param_3 + 100) = *(uint *)(param_3 + 100) | 2;
      }
      local_58 = 0;
      if (uVar1 == 0) {
LAB_14000803c:
        *(int *)(param_3 + 0x40) = iVar12;
        if ((iVar12 != 0) && (param_4 == 1)) {
          uVar7 = GpioClnInvokeConnectPins(param_2,lVar3,(ushort)iVar12,1,lVar2 + 8);
          uVar11 = uVar7 & 0xffffffff;
          if ((int)uVar7 < 0) {
            return uVar11;
          }
        }
        *(int *)(param_3 + 0x1c) = param_4;
        if (uVar1 != 0) {
          plVar16 = plVar18;
          uVar7 = uVar10;
          do {
            lVar3 = *plVar16;
            if (param_4 == 1) {
              *(int *)(lVar3 + 200) = *(int *)(lVar3 + 200) + 1;
              uVar9 = *(uint *)(lVar3 + 0xc0) | 1;
            }
            else {
              *(int *)(lVar3 + 0xcc) = *(int *)(lVar3 + 0xcc) + 1;
              uVar9 = *(uint *)(lVar3 + 0xc0) | 2;
            }
            *(uint *)(lVar3 + 0xc0) = uVar9;
            uVar17 = uVar9 | 0x200;
            if (bVar6 != 0) {
              uVar17 = uVar9 & 0xfffffdff;
            }
            uVar9 = uVar17 | 0x400;
            if (bVar14 == 0) {
              uVar9 = uVar17 & 0xfffffbff;
            }
            *(uint *)(lVar3 + 0xc0) = uVar9;
            if (((uVar9 & 4) == 0) &&
               ((*(int *)(lVar3 + 200) == 1 || (*(int *)(lVar3 + 0xcc) == 1)))) {
              *(undefined8 *)(lVar3 + 0xec) = 0;
              *(undefined8 *)(lVar3 + 0xf8) = 0;
              LOCK();
              *(undefined4 *)(lVar3 + 0x100) = 0;
              UNLOCK();
              *(uint *)(lVar3 + 0xd8) = (uint)*(ushort *)(lVar2 + 0x14);
              *(undefined1 *)(lVar3 + 0xe8) = *(undefined1 *)(lVar2 + 0x11);
              *(undefined2 *)(lVar3 + 0x108) = *(undefined2 *)(lVar2 + 0x12);
            }
            plVar16 = plVar16 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if ((*(uint *)(param_3 + 100) & 2) == 0) {
          return uVar11;
        }
        if (uVar1 == 0) {
          return uVar11;
        }
        do {
          if (*(int *)(*plVar18 + 0xcc) == 1) {
            *(undefined1 *)(*plVar18 + 0xd4) = 0;
          }
          plVar18 = plVar18 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
        return uVar11;
      }
      uVar7 = 0;
      local_40 = plVar18;
      do {
        lVar4 = *local_40;
        bVar5 = false;
        uVar9 = *(uint *)(lVar4 + 0xc0);
        cVar8 = (char)*local_48;
        if ((uVar9 & 8) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000a126;
          }
          WPP_RECORDER_SF_sDDD
                    (*(undefined8 *)(param_1 + 0x298),0,7,0x68,
                     &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,"GpiopConnectGpioPinsLocked",
                     (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                     (char)*(undefined2 *)(param_2 + 0x80) + cVar8,
                     (char)*(undefined4 *)(lVar4 + 0xd0),(char)uVar9);
          return 0xc000a126;
        }
        uVar17 = uVar9 & 4;
        if (((uVar17 != 0) && (param_4 == 2)) && (GpioAllowInterruptOutput == '\0')) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000a126;
          }
          cVar8 = (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                  (char)*(undefined2 *)(param_2 + 0x80) + cVar8;
          uVar15 = 0x69;
LAB_140007f7d:
          WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),0,7,uVar15,
                              &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                              "GpiopConnectGpioPinsLocked",cVar8,(char)uVar9);
          return 0xc000a126;
        }
        if ((((uVar9 & 1) != 0) && (param_4 == 2)) &&
           ((uVar17 == 0 || (GpioAllowInterruptOutput == '\0')))) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000a126;
          }
          cVar8 = (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                  (char)*(undefined2 *)(param_2 + 0x80) + cVar8;
          uVar15 = 0x6a;
          goto LAB_140007f7d;
        }
        if (((uVar9 & 2) != 0) && (param_4 == 1)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000a126;
          }
          cVar8 = (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                  (char)*(undefined2 *)(param_2 + 0x80) + cVar8;
          uVar15 = 0x6b;
          goto LAB_140007f7d;
        }
        if (((uVar9 & 3) != 0) && (((uVar9 >> 9 & 1) != 0 || (bVar6 == 0)))) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000a126;
          }
          cVar8 = (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                  (char)*(undefined2 *)(param_2 + 0x80) + cVar8;
          uVar15 = 0x6c;
          goto LAB_140007f7d;
        }
        if (param_4 == 1) {
          if (((uVar9 & 1) != 0) && (*(int *)(lVar4 + 200) != 0)) {
            bVar5 = true;
          }
          if ((uVar17 != 0) || (bVar5)) goto LAB_140007e3e;
LAB_140007e8b:
          uVar13 = (ulonglong)((int)uVar7 + 1);
          *(undefined2 *)(lVar3 + uVar7 * 2) = *local_48;
        }
        else {
          if ((param_4 != 2) || (((uVar9 & 2) == 0 || (*(int *)(lVar4 + 0xcc) == 0))))
          goto LAB_140007e8b;
LAB_140007e3e:
          uVar13 = uVar7;
        }
        iVar12 = (int)uVar13;
        local_58 = local_58 + 1;
        local_48 = local_48 + 1;
        local_40 = local_40 + 1;
        if (uVar1 <= local_58) goto LAB_14000803c;
        uVar7 = uVar13;
      } while( true );
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000a126;
    }
    uVar15 = 0x67;
  }
  WPP_RECORDER_SF_sqid
            (*(undefined8 *)(param_1 + 0x298),param_2,1,uVar15,in_stack_ffffffffffffff78,
             in_stack_ffffffffffffff80,(char)param_1,(char)*param_5,(char)param_4);
  return 0xc000a126;
}



===== GpiopCreatePinEntry @ 140008194 =====

void GpiopCreatePinEntry(longlong param_1,ushort param_2)

{
  GpiopGetPinEntryInternal(param_1,param_2,'\x01');
  return;
}



===== GpiopCreatePinEntryFromPinNumber @ 1400081ac =====

void GpiopCreatePinEntryFromPinNumber(longlong param_1,uint param_2)

{
  GpiopGetPinEntryFromPinNumberInternal(param_1,param_2,'\x01');
  return;
}



===== GpiopDeferredDisableInterruptHandler @ 1400081c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopDeferredDisableInterruptHandler(longlong *param_1,char param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  char cVar12;
  bool bVar13;
  undefined8 in_stack_ffffffffffffffb8;
  
  bVar4 = false;
  iVar8 = 0;
  bVar5 = KeGetCurrentIrql();
  if (bVar5 < 2) {
    lVar3 = param_1[0x11];
    iVar6 = 0;
    LOCK();
    iVar1 = *(int *)(lVar3 + 0x2d0);
    if (iVar1 == 0) {
      *(int *)(lVar3 + 0x2d0) = 0;
    }
    else {
      iVar6 = iVar1;
    }
    UNLOCK();
    if (iVar6 == 8) {
      if (*(ushort *)(param_1 + 0x30) < 0x21) {
        uVar7 = 0;
        LOCK();
        uVar2 = *(uint *)(param_1 + 0x1c);
        if (uVar2 == 0) {
          *(uint *)(param_1 + 0x1c) = 0;
        }
        else {
          uVar7 = uVar2;
        }
        UNLOCK();
        uVar9 = (ulonglong)uVar7;
      }
      else {
        uVar9 = 0;
        LOCK();
        uVar11 = param_1[0x1c];
        if (uVar11 == 0) {
          param_1[0x1c] = 0;
        }
        else {
          uVar9 = uVar11;
        }
        UNLOCK();
      }
      if (uVar9 != 0) {
        bVar13 = (void *)param_1[9] != SystemReserved1[0xf];
        if ((param_2 == '\0') && (bVar13)) {
          (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6]);
          param_1[7] = (longlong)SystemReserved1[0xf];
        }
        if (*(ushort *)(param_1 + 0x30) < 0x21) {
          LOCK();
          uVar2 = *(uint *)(param_1 + 0x1c);
          *(uint *)(param_1 + 0x1c) = 0;
          UNLOCK();
          uVar11 = (ulonglong)uVar2;
        }
        else {
          LOCK();
          uVar11 = param_1[0x1c];
          param_1[0x1c] = 0;
          UNLOCK();
        }
        if (uVar11 != 0) {
          do {
            bVar5 = RtlFindLeastSignificantBit(uVar11);
            uVar11 = uVar11 & ~(1L << ((ulonglong)((int)(char)bVar5 & 0xffff) & 0x3f));
            lVar10 = GpiopGetPinEntryInternal((longlong)param_1,(short)(char)bVar5,'\0');
            if (((*(uint *)(lVar3 + 0x314) & 1) != 0) ||
               (cVar12 = '\x01', *(int *)(lVar10 + 0x90) < 1)) {
              cVar12 = '\0';
            }
            iVar8 = GpioClnInvokeDisableInterrupt((longlong)param_1,(short)(char)bVar5,cVar12);
            if (iVar8 < 0) {
              bVar4 = true;
              if (*(ushort *)(param_1 + 0x30) < 0x21) {
                LOCK();
                *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1 << (bVar5 & 0x1f);
                UNLOCK();
              }
              else {
                LOCK();
                param_1[0x1c] = param_1[0x1c] | 1L << (bVar5 & 0x3f);
                UNLOCK();
              }
            }
            GpiopCheckEnabledInterrupts(param_1);
          } while (uVar11 != 0);
          if (bVar4) {
            GpiopHandleDisableInterruptRequestFailure((longlong)param_1);
          }
        }
        if ((param_2 == '\0') && (bVar13)) {
          param_1[7] = 0;
          (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
        }
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sqd(*(undefined8 *)(lVar3 + 0x298),2,param_3,0x3b,in_stack_ffffffffffffffb8,
                            "GpiopDeferredDisableInterruptHandler",(char)lVar3,
                            (char)*(undefined4 *)(lVar3 + 0x2d0));
      }
      iVar8 = -0x3fffffff;
    }
  }
  return iVar8;
}



===== GpiopDeferredMaskRequestHandler @ 140008408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GpiopDeferredMaskRequestHandler(longlong *param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  code *pcVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  bool bVar13;
  ulonglong local_res8;
  undefined8 in_stack_ffffffffffffffa8;
  undefined1 uVar14;
  
  lVar10 = param_1[0x11];
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    uVar4 = 0;
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x16);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x16) = 0;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
    uVar6 = (ulonglong)uVar4;
  }
  else {
    uVar6 = 0;
    LOCK();
    uVar11 = param_1[0x16];
    if (uVar11 == 0) {
      param_1[0x16] = 0;
    }
    else {
      uVar6 = uVar11;
    }
    UNLOCK();
  }
  if (uVar6 == 0) {
    return 0;
  }
  uVar14 = SUB81(param_1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqi(*(undefined8 *)(lVar10 + 0x298),4,8,0x34,in_stack_ffffffffffffffa8,
                        "GpiopDeferredMaskRequestHandler",uVar14,(char)uVar6);
  }
  bVar3 = true;
  if ((*(uint *)(lVar10 + 0x314) & 1) == 0) {
    bVar2 = true;
    if ((void *)param_1[7] != SystemReserved1[0xf]) {
      bVar2 = true;
      goto LAB_1400084c6;
    }
  }
  else {
    bVar2 = false;
  }
  bVar3 = bVar2;
  bVar2 = false;
LAB_1400084c6:
  bVar13 = (void *)param_1[4] != SystemReserved1[0xf];
  if (bVar2) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6],0);
    param_1[7] = (longlong)SystemReserved1[0xf];
  }
  if (bVar13) {
    lVar8 = *param_1;
    if (lVar8 == 0) {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar8 = param_1[3];
    }
    else {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar7)(WdfDriverGlobals,lVar8);
    param_1[4] = (longlong)SystemReserved1[0xf];
  }
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x16);
    *(uint *)(param_1 + 0x16) = 0;
    UNLOCK();
    uVar11 = (ulonglong)uVar1;
  }
  else {
    LOCK();
    uVar11 = param_1[0x16];
    param_1[0x16] = 0;
    UNLOCK();
  }
  uVar11 = uVar11 & param_1[0x29];
  if (uVar11 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqi(*(undefined8 *)(lVar10 + 0x298),4,8,0x35,in_stack_ffffffffffffffa8,
                          "GpiopDeferredMaskRequestHandler",uVar14,(char)uVar11);
    }
    if (bVar3) {
      lVar8 = *param_1;
      param_1[4] = 0;
      if (lVar8 == 0) {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar8 = param_1[3];
      }
      else {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar7)(WdfDriverGlobals,lVar8);
    }
    puVar12 = &local_res8;
    local_res8 = 0;
    uVar9 = uVar11;
    iVar5 = GpioClnInvokeMaskInterrupts((longlong)param_1,uVar11,puVar12);
    uVar6 = local_res8;
    if ((iVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sqiiD
                (*(undefined8 *)(lVar10 + 0x298),uVar9,puVar12,0x36,in_stack_ffffffffffffffa8,
                 "GpiopDeferredMaskRequestHandler",uVar14,(char)uVar11,(char)local_res8,(char)iVar5)
      ;
    }
    local_res8 = uVar6 & uVar11;
    if (bVar3) {
      lVar10 = *param_1;
      if (lVar10 == 0) {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar10 = param_1[3];
      }
      else {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar7)(WdfDriverGlobals,lVar10);
      param_1[4] = (longlong)SystemReserved1[0xf];
    }
    GpiopHandleInterruptMaskRequestCompletion((longlong)param_1,uVar11,local_res8);
  }
  if (bVar13) {
    lVar10 = *param_1;
    param_1[4] = 0;
    if (lVar10 == 0) {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
      lVar10 = param_1[3];
    }
    else {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    (*pcVar7)(WdfDriverGlobals,lVar10);
  }
  if (bVar2) {
    param_1[7] = 0;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
  }
  return 0;
}



===== GpiopDeferredReconfigureRequestHandler @ 14000873c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 GpiopDeferredReconfigureRequestHandler(longlong *param_1)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  code *pcVar7;
  longlong lVar8;
  ulonglong uVar9;
  bool bVar10;
  
  uVar5 = 0;
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    uVar4 = 0;
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x20);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x20) = 0;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
    uVar6 = (ulonglong)uVar4;
  }
  else {
    uVar6 = 0;
    LOCK();
    uVar9 = param_1[0x20];
    if (uVar9 == 0) {
      param_1[0x20] = 0;
    }
    else {
      uVar6 = uVar9;
    }
    UNLOCK();
  }
  if (uVar6 != 0) {
    bVar10 = false;
    bVar2 = false;
    if ((~*(byte *)(param_1[0x11] + 0x314) & 1) == 0) {
      bVar10 = (void *)param_1[4] != SystemReserved1[0xf];
      if (bVar10) {
        lVar8 = *param_1;
        if (lVar8 == 0) {
          pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
          lVar8 = param_1[3];
        }
        else {
          pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
        }
        (*pcVar7)(WdfDriverGlobals,lVar8);
        param_1[4] = (longlong)SystemReserved1[0xf];
      }
    }
    else if ((void *)param_1[7] != SystemReserved1[0xf]) {
      bVar2 = true;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6],0);
      param_1[7] = (longlong)SystemReserved1[0xf];
    }
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = 0;
      UNLOCK();
      uVar9 = (ulonglong)uVar1;
    }
    else {
      LOCK();
      uVar9 = param_1[0x20];
      param_1[0x20] = 0;
      UNLOCK();
    }
    for (uVar9 = uVar9 & param_1[0x28]; uVar9 != 0;
        uVar9 = uVar9 & ~(1L << ((ulonglong)((int)cVar3 & 0xffff) & 0x3f))) {
      cVar3 = RtlFindLeastSignificantBit(uVar9);
      uVar6 = GpiopFlipPinPolarity((ulonglong)param_1,(short)cVar3);
      uVar5 = (undefined4)uVar6;
    }
    if (bVar10) {
      lVar8 = *param_1;
      param_1[4] = 0;
      if (lVar8 == 0) {
        lVar8 = param_1[3];
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
      }
      else {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar7)(WdfDriverGlobals,lVar8);
    }
    if (bVar2) {
      param_1[7] = 0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
    }
  }
  return uVar5;
}



===== GpiopDeferredStatusClearRequestHandler @ 140008914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopDeferredStatusClearRequestHandler(longlong *param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  bool bVar12;
  ulonglong local_res8;
  undefined8 in_stack_ffffffffffffffa8;
  
  iVar4 = 0;
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    uVar3 = 0;
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x1b);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x1b) = 0;
    }
    else {
      uVar3 = uVar1;
    }
    UNLOCK();
    uVar10 = (ulonglong)uVar3;
  }
  else {
    uVar10 = 0;
    LOCK();
    uVar6 = param_1[0x1b];
    if (uVar6 == 0) {
      param_1[0x1b] = 0;
    }
    else {
      uVar10 = uVar6;
    }
    UNLOCK();
  }
  if (uVar10 != 0) {
    lVar9 = param_1[0x11];
    bVar12 = false;
    bVar2 = false;
    if ((~*(byte *)(lVar9 + 0x314) & 1) == 0) {
      bVar12 = (void *)param_1[4] != SystemReserved1[0xf];
      if (bVar12) {
        lVar7 = *param_1;
        if (lVar7 == 0) {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e0);
          lVar7 = param_1[3];
        }
        else {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x480);
        }
        (*pcVar5)(WdfDriverGlobals,lVar7);
        param_1[4] = (longlong)SystemReserved1[0xf];
      }
    }
    else if ((void *)param_1[7] != SystemReserved1[0xf]) {
      bVar2 = true;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6],0);
      param_1[7] = (longlong)SystemReserved1[0xf];
    }
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x1b);
      *(uint *)(param_1 + 0x1b) = 0;
      UNLOCK();
      uVar6 = (ulonglong)uVar1;
    }
    else {
      LOCK();
      uVar6 = param_1[0x1b];
      param_1[0x1b] = 0;
      UNLOCK();
    }
    uVar6 = uVar6 & param_1[0x28];
    if (uVar6 != 0) {
      uVar10 = ~param_1[0x1a] & uVar6;
      uVar6 = uVar6 & ~uVar10;
      if (uVar6 != 0) {
        if (*(ushort *)(param_1 + 0x30) < 0x21) {
          LOCK();
          *(uint *)(param_1 + 0x1b) = *(uint *)(param_1 + 0x1b) | (uint)uVar6;
          UNLOCK();
        }
        else {
          LOCK();
          param_1[0x1b] = param_1[0x1b] | uVar6;
          UNLOCK();
        }
      }
      local_res8 = 0;
      uVar6 = 0;
      if (uVar10 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sqi(*(undefined8 *)(lVar9 + 0x298),4,8,0x39,in_stack_ffffffffffffffa8,
                              "GpiopDeferredStatusClearRequestHandler",(char)param_1,(char)uVar10);
        }
        puVar11 = &local_res8;
        uVar8 = uVar10;
        iVar4 = GpioClnInvokeClearActiveInterrupts((longlong)param_1,uVar10,puVar11);
        uVar6 = local_res8;
        if ((iVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_sqiiD
                    (*(undefined8 *)(lVar9 + 0x298),uVar8,puVar11,0x3a,in_stack_ffffffffffffffa8,
                     "GpiopDeferredStatusClearRequestHandler",(char)param_1,(char)uVar10,
                     (char)local_res8,(char)iVar4);
        }
      }
      GpiopHandleStatusClearRequestCompletion((longlong)param_1,uVar10,uVar6);
    }
    if (bVar12) {
      lVar9 = *param_1;
      param_1[4] = 0;
      if (lVar9 == 0) {
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar9 = param_1[3];
      }
      else {
        pcVar5 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar5)(WdfDriverGlobals,lVar9);
    }
    if (bVar2) {
      param_1[7] = 0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
    }
  }
  return iVar4;
}



===== GpiopDeferredUnmaskRequestHandler @ 140008bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GpiopDeferredUnmaskRequestHandler(longlong *param_1)

{
  uint uVar1;
  undefined2 uVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  code *pcVar10;
  longlong *plVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  bool bVar16;
  undefined *in_stack_ffffffffffffff58;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    uVar7 = 0;
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x17);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x17) = 0;
    }
    else {
      uVar7 = uVar1;
    }
    UNLOCK();
    uVar13 = (ulonglong)uVar7;
  }
  else {
    uVar13 = 0;
    LOCK();
    uVar14 = param_1[0x17];
    if (uVar14 == 0) {
      param_1[0x17] = 0;
    }
    else {
      uVar13 = uVar14;
    }
    UNLOCK();
  }
  if (uVar13 == 0) {
    return 0;
  }
  lVar12 = param_1[0x11];
  if ((*(uint *)(lVar12 + 0x314) & 1) == 0) {
    bVar4 = true;
    bVar5 = true;
    if ((void *)param_1[7] != SystemReserved1[0xf]) {
      bVar5 = true;
      goto LAB_140008c3e;
    }
  }
  else {
    bVar5 = false;
  }
  bVar4 = bVar5;
  bVar5 = false;
LAB_140008c3e:
  bVar16 = (void *)param_1[4] != SystemReserved1[0xf];
  if (bVar5) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6]);
    param_1[7] = (longlong)SystemReserved1[0xf];
  }
  if (bVar16) {
    lVar9 = *param_1;
    if (lVar9 == 0) {
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar9 = param_1[3];
    }
    else {
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar10)(WdfDriverGlobals,lVar9);
    param_1[4] = (longlong)SystemReserved1[0xf];
  }
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x17);
    *(uint *)(param_1 + 0x17) = 0;
    UNLOCK();
    uVar14 = (ulonglong)uVar1;
  }
  else {
    LOCK();
    uVar14 = param_1[0x17];
    param_1[0x17] = 0;
    UNLOCK();
  }
  uVar14 = uVar14 & ~param_1[0x29] & param_1[0x28];
  if (uVar14 != 0) {
    if (bVar4) {
      lVar9 = *param_1;
      param_1[4] = 0;
      if (lVar9 == 0) {
        pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar9 = param_1[3];
      }
      else {
        pcVar10 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar10)(WdfDriverGlobals,lVar9);
    }
    GpiopDeferredStatusClearRequestHandler(param_1);
    uVar15 = 0;
    uVar13 = uVar14;
    do {
      cVar6 = RtlFindLeastSignificantBit(uVar13);
      uVar13 = uVar13 & ~(1L << ((ulonglong)((int)cVar6 & 0xffff) & 0x3f));
      plVar11 = param_1;
      lVar9 = GpiopGetPinEntryInternal((longlong)param_1,(short)cVar6,'\0');
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffff58 = &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids;
        plVar11 = *(longlong **)(lVar12 + 0x298);
        WPP_RECORDER_SF_sqD(plVar11,4,8,0x37,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                            "GpiopDeferredUnmaskRequestHandler",(char)param_1,cVar6);
      }
      uVar2 = (undefined2)param_1[0x10];
      lVar3 = param_1[0x11];
      local_58 = 0;
      uStack_70 = *(undefined8 *)(lVar9 + 8);
      uStack_60 = 0;
      local_68 = (ulonglong)*(ushort *)(lVar9 + 0xd8) << 0x10;
      local_68 = CONCAT71(local_68._1_7_,*(undefined1 *)(lVar9 + 0xe8));
      local_78 = (ulonglong)CONCAT22((short)cVar6,uVar2);
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        in_stack_ffffffffffffff58 =
             (undefined *)CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff58 >> 0x10),uVar2);
        McTemplateK0zhh_EtwWriteTransfer
                  (plVar11,&EVENT_UNMASK_INTERRUPT_START,param_1 + 0xe,*(wchar_t **)(lVar3 + 0x300),
                   (char)param_1[0x10],cVar6);
      }
      lVar9 = lVar3 + 0x400;
      iVar8 = (**(code **)(lVar3 + 0x1a8))(lVar9,&local_78);
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        McTemplateK0h_EtwWriteTransfer
                  (lVar9,&EVENT_UNMASK_INTERRUPT_COMPLETE,param_1 + 0xe,(short)cVar6);
      }
      if (iVar8 < 0) {
        if ((*(uint *)(lVar3 + 0x314) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0x138,5,(longlong)iVar8,lVar3,&local_78);
        }
        uVar15 = uVar15 | 1L << ((ulonglong)((int)cVar6 & 0xffff) & 0x3f);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sqDD
                    (*(undefined8 *)(lVar12 + 0x298),2,8,0x38,in_stack_ffffffffffffff58,
                     "GpiopDeferredUnmaskRequestHandler",(char)param_1,cVar6,(char)iVar8);
        }
      }
    } while (uVar13 != 0);
    if (bVar4) {
      lVar12 = *param_1;
      if (lVar12 == 0) {
        pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar12 = param_1[3];
      }
      else {
        pcVar10 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar10)(WdfDriverGlobals,lVar12);
      param_1[4] = (longlong)SystemReserved1[0xf];
    }
    GpiopHandleInterruptUnmaskRequestCompletion((longlong)param_1,uVar14,uVar15);
  }
  if (bVar16) {
    lVar12 = *param_1;
    param_1[4] = 0;
    if (lVar12 == 0) {
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e8);
      lVar12 = param_1[3];
    }
    else {
      pcVar10 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    (*pcVar10)(WdfDriverGlobals,lVar12);
  }
  if (bVar5) {
    param_1[7] = 0;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
  }
  return 0;
}



===== GpiopDisableInterrupt @ 140009014 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopDisableInterrupt(longlong param_1,int param_2,char param_3)

{
  int *piVar1;
  uint uVar2;
  longlong *plVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong **pplVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong lVar12;
  ushort local_res20 [4];
  ushort *puVar13;
  undefined1 uVar14;
  ushort local_58 [4];
  longlong *local_50;
  longlong local_48;
  
  puVar13 = local_res20;
  local_58[0] = 0;
  pplVar9 = &local_50;
  local_50 = (longlong *)0x0;
  local_48 = 0;
  lVar12 = 0;
  local_res20[0] = 0;
  puVar5 = (undefined4 *)
           GpiopGetPinEntryFromVirq(param_1,param_2,(longlong *)pplVar9,local_58,puVar13);
  uVar14 = (undefined1)param_2;
  if (puVar5 == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,8,0x1c,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar14);
    }
    iVar4 = -0x3ffffff3;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDDD
                (*(undefined8 *)(param_1 + 0x298),4,pplVar9,0x1d,puVar13,(char)param_1,uVar14,
                 (char)local_58[0],(char)local_res20[0]);
    }
    plVar8 = local_50;
    if (param_3 == '\0') {
      GpiopFlushPendingPinInterruptActivities(local_50,(longlong)puVar5,local_res20[0]);
    }
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar8[6],0);
    local_50[7] = (longlong)SystemReserved1[0xf];
    lVar7 = *local_50;
    if (lVar7 == 0) {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar7 = local_50[3];
    }
    else {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar6)(WdfDriverGlobals,lVar7);
    plVar8 = local_50;
    local_50[4] = (longlong)SystemReserved1[0xf];
    LOCK();
    puVar5[0x31] = 0;
    UNLOCK();
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x1e) =
           *(uint *)(local_50 + 0x1e) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x1e] = local_50[0x1e] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x1a) =
           *(uint *)(local_50 + 0x1a) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x1a] = local_50[0x1a] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x1b) =
           *(uint *)(local_50 + 0x1b) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x1b] = local_50[0x1b] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x16) =
           *(uint *)(local_50 + 0x16) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x16] = local_50[0x16] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x17) =
           *(uint *)(local_50 + 0x17) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x17] = local_50[0x17] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x20) =
           *(uint *)(local_50 + 0x20) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x20] = local_50[0x20] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x21) =
           *(uint *)(local_50 + 0x21) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x21] = local_50[0x21] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x1e) =
           *(uint *)(local_50 + 0x1e) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x1e] = local_50[0x1e] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    if (*(ushort *)(local_50 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(local_50 + 0x1f) =
           *(uint *)(local_50 + 0x1f) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      local_50[0x1f] = local_50[0x1f] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    *(undefined1 *)((longlong)puVar5 + 0xb9) = 0;
    local_50[4] = 0;
    if (*local_50 == 0) {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
    }
    else {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    plVar11 = local_50;
    (*pcVar6)(WdfDriverGlobals);
    plVar3 = local_50;
    if (param_3 == '\0') {
      if (*(ushort *)(plVar8 + 0x30) < 0x21) {
        LOCK();
        *(uint *)(plVar8 + 0x1c) = *(uint *)(plVar8 + 0x1c) | 1 << ((byte)local_res20[0] & 0x1f);
        UNLOCK();
      }
      else {
        LOCK();
        plVar8[0x1c] = plVar8[0x1c] | 1L << ((byte)local_res20[0] & 0x3f);
        UNLOCK();
      }
      iVar4 = GpiopDeferredDisableInterruptHandler(local_50,'\x01',plVar11);
      plVar8 = plVar3;
    }
    else {
      iVar4 = 0;
    }
    plVar3 = local_50;
    if (*(ushort *)(plVar8 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(plVar8 + 0x28) = *(uint *)(plVar8 + 0x28) & ~(1 << ((byte)local_res20[0] & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      plVar8[0x28] = plVar8[0x28] & ~(1L << ((byte)local_res20[0] & 0x3f));
      UNLOCK();
    }
    puVar5[0x30] = puVar5[0x30] & 0xfffffc2b;
    LOCK();
    puVar5[0x40] = 0;
    UNLOCK();
    piVar1 = puVar5 + 0x32;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      puVar5[0x30] = puVar5[0x30] & 0xfffffffe;
    }
    uVar2 = puVar5[0x30];
    puVar5[0x30] = uVar2 & 0xffffff7f;
    *puVar5 = 1;
    if ((uVar2 >> 7 & 1) == 0) {
      lVar7 = 0;
    }
    else {
      local_48 = *(longlong *)(puVar5 + 6);
      lVar12 = *(longlong *)(puVar5 + 4);
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined8 *)(puVar5 + 6) = 0;
      lVar7 = *(longlong *)(puVar5 + 8);
      *(int *)(local_50 + 10) = (int)local_50[10] + -1;
    }
    local_50[7] = 0;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,local_50[6]);
    if (iVar4 < 0) {
      LOCK();
      *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) | 4;
      UNLOCK();
    }
    else {
      uVar10 = 0;
      PoFxIdleComponent(*(undefined8 *)(param_1 + 0x118),(short)plVar3[0x10],0);
      plVar11 = (longlong *)CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
      (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
    }
    if (lVar12 != 0) {
      if (*(longlong *)(lVar12 + 0x18) != 0) {
        plVar11 = (longlong *)CONCAT71((int7)((ulonglong)plVar11 >> 8),1);
        ExDeleteTimer(*(longlong *)(lVar12 + 0x18),1,plVar11,0);
      }
      ExFreePoolWithTag(lVar12,0x786c4347);
    }
    lVar12 = local_48;
    if (local_48 != 0) {
      if (*(longlong *)(local_48 + 0x20) != 0) {
        plVar11 = (longlong *)CONCAT71((int7)((ulonglong)plVar11 >> 8),1);
        ExDeleteTimer(*(longlong *)(local_48 + 0x20),1,plVar11,0);
      }
      ExFreePoolWithTag(lVar12,0x786c4347);
    }
    if (lVar7 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar7);
    }
    if (-1 < iVar4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar4;
      }
      WPP_RECORDER_SF_qDDD
                (*(undefined8 *)(param_1 + 0x298),4,plVar11,0x1f,puVar13,(char)param_1,uVar14,
                 (char)local_58[0],(char)local_res20[0]);
      return iVar4;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x1e,
                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar14,(char)iVar4);
  }
  return iVar4;
}



===== GpiopDisconnectFunctionConfigPinsLocked @ 1400095fc =====

void GpiopDisconnectFunctionConfigPinsLocked(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong uVar7;
  
  uVar2 = *(uint *)(param_2 + 0x28);
  uVar7 = (ulonglong)uVar2;
  uVar3 = *(undefined8 *)(param_2 + 0x20);
  plVar6 = *(longlong **)(param_2 + 0x30);
  if (*(ushort *)(param_2 + 0x18) < *(ushort *)(param_1 + 0x2d8)) {
    lVar5 = (ulonglong)*(ushort *)(param_2 + 0x18) * 400 + *(longlong *)(param_1 + 0x2e0);
  }
  else {
    lVar5 = 0;
  }
  if (uVar2 != 0) {
    do {
      lVar4 = *plVar6;
      plVar6 = plVar6 + 1;
      *(undefined4 *)(lVar4 + 0xd0) = 0;
      puVar1 = (uint *)(lVar4 + 0xc0);
      *puVar1 = *puVar1 & 0xfffffdf7;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  GpioClnInvokeDisconnectFunctionConfigPins(lVar5,uVar3,uVar2,0);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}



===== GpiopDisconnectGpioPins @ 140009678 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GpiopDisconnectGpioPins(longlong param_1,longlong *param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 *puVar8;
  longlong lVar9;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined1 uVar10;
  
  iVar1 = *(int *)((longlong)param_2 + 0x1c);
  uVar10 = (undefined1)iVar1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),4,7,0x6d,
                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)param_1,uVar10);
  }
  if (*(ushort *)(param_2 + 3) < *(ushort *)(param_1 + 0x2d8)) {
    lVar9 = (ulonglong)*(ushort *)(param_2 + 3) * 400 + *(longlong *)(param_1 + 0x2e0);
  }
  else {
    lVar9 = 0;
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x30),0);
  puVar8 = auStackY_58;
  *(void **)(lVar9 + 0x38) = SystemReserved1[0xf];
  plVar3 = (longlong *)*param_2;
  if (plVar3 != param_2) {
    if (((longlong *)plVar3[1] == param_2) &&
       (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 == param_2)) {
      *plVar4 = (longlong)plVar3;
      plVar3[1] = (longlong)plVar4;
      param_2[1] = (longlong)param_2;
      *param_2 = (longlong)param_2;
      puVar5 = (undefined2 *)param_2[4];
      uVar2 = *(uint *)(param_2 + 5);
      GpioUtilTracePrintPinNumbers(lVar9,puVar5,uVar2);
      if (((*(byte *)(param_1 + 4) & 2) != 0) &&
         ((*(longlong *)(param_1 + 600) != 0 && (*(code **)(param_1 + 0x260) != (code *)0x0)))) {
        (**(code **)(param_1 + 0x260))(param_1 + 0x400,param_2[9]);
      }
      param_2[9] = 0;
      if (iVar1 - 1U < 2) {
        GpiopDisconnectGpioPinsLocked(param_1,(longlong)param_2,param_3,'\0');
      }
      *(undefined8 *)(lVar9 + 0x38) = 0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x30));
      if (*(longlong *)(param_1 + 0x118) != 0) {
        PoFxIdleComponent(*(longlong *)(param_1 + 0x118),*(undefined2 *)(lVar9 + 0x80),0);
      }
      (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),1)
      ;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),4,7,0x6e,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                            "GpiopDisconnectGpioPins",(char)param_1,uVar10);
      }
      GpioUtilTracePrintPinNumbers(lVar9,puVar5,uVar2);
      if (param_2[6] != 0) {
        ExFreePoolWithTag(param_2[6],0x786c4347);
        param_2[6] = 0;
      }
      if (param_2[4] != 0) {
        ExFreePoolWithTag(param_2[4],0x786c4347);
        param_2[4] = 0;
        *(undefined4 *)(param_2 + 5) = 0;
      }
      if (param_2[7] != 0) {
        ExFreePoolWithTag(param_2[7],0x786c4347);
        param_2[7] = 0;
        *(undefined4 *)(param_2 + 8) = 0;
      }
      if (param_2[0xb] == 0) {
        return 0;
      }
      ExFreePoolWithTag(param_2[0xb],0x786c4347);
      param_2[0xb] = 0;
      return 0;
    }
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    puVar8 = auStackY_50;
  }
  uVar6 = *(undefined8 *)(lVar9 + 0x30);
  *(undefined8 *)(lVar9 + 0x38) = 0;
  pcVar7 = *(code **)(WdfFunctions_01015 + 0x9d0);
  *(undefined8 *)(puVar8 + -8) = 0x140009929;
  (*pcVar7)(WdfDriverGlobals,uVar6);
  return 0;
}



===== GpiopDisconnectGpioPinsLocked @ 140009954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDisconnectGpioPinsLocked(longlong param_1,longlong param_2,char param_3,char param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined2 *puVar13;
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  longlong local_40;
  int local_38;
  int local_34;
  uint local_30;
  undefined4 local_2c;
  
  iVar3 = *(int *)(param_2 + 0x1c);
  local_40 = *(longlong *)(param_2 + 0x38);
  uVar6 = *(uint *)(param_2 + 0x28);
  uVar7 = (ulonglong)uVar6;
  uVar12 = 0;
  puVar13 = *(undefined2 **)(param_2 + 0x20);
  plVar9 = *(longlong **)(param_2 + 0x30);
  if (*(ushort *)(param_2 + 0x18) < *(ushort *)(param_1 + 0x2d8)) {
    lVar10 = (ulonglong)*(ushort *)(param_2 + 0x18) * 400 + *(longlong *)(param_1 + 0x2e0);
  }
  else {
    lVar10 = 0;
  }
  local_30 = (uint)(param_4 != '\0');
  if (uVar6 != 0) {
    uVar8 = uVar7;
    plVar11 = plVar9;
    do {
      lVar4 = *plVar11;
      puVar1 = (uint *)(lVar4 + 0xc0);
      if (iVar3 == 1) {
        if (((*puVar1 & 1) == 0) || (*(uint *)(lVar4 + 200) < 2)) goto LAB_140009a0f;
      }
      else if (((iVar3 != 2) || ((*puVar1 & 2) == 0)) ||
              ((*(uint *)(lVar4 + 0xcc) < 2 && (*(char *)(lVar4 + 0xd4) != '\0')))) {
LAB_140009a0f:
        *(undefined2 *)(local_40 + uVar12 * 2) = *puVar13;
        if ((*puVar1 & 0x400) != 0) {
          local_30 = 1;
        }
        uVar12 = (ulonglong)((int)uVar12 + 1);
      }
      plVar11 = plVar11 + 1;
      puVar13 = puVar13 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
    local_38 = (int)uVar12;
    if ((local_38 != 0) && (param_3 == '\0')) {
      pcVar5 = *(code **)(*(longlong *)(lVar10 + 0x88) + 0x1d0);
      if (pcVar5 != (code *)0x0) {
        local_48 = *(undefined2 *)(lVar10 + 0x80);
        local_46 = 0;
        local_42 = 0;
        local_2c = 0;
        local_34 = iVar3;
        (*pcVar5)(*(longlong *)(lVar10 + 0x88) + 0x400,&local_48);
      }
    }
  }
  *(undefined4 *)(param_2 + 0x1c) = 0;
  if (uVar6 != 0) {
    do {
      lVar10 = *plVar9;
      if (iVar3 == 1) {
        piVar2 = (int *)(lVar10 + 200);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          *(uint *)(lVar10 + 0xc0) = *(uint *)(lVar10 + 0xc0) & 0xfffffffe;
        }
      }
      else {
        piVar2 = (int *)(lVar10 + 0xcc);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          *(uint *)(lVar10 + 0xc0) = *(uint *)(lVar10 + 0xc0) & 0xfffffffd;
          *(undefined1 *)(lVar10 + 0xd4) = 0;
        }
      }
      uVar6 = *(uint *)(lVar10 + 0xc0);
      if ((uVar6 & 3) == 0) {
        if ((uVar6 >> 9 & 1) != 0) {
          uVar6 = uVar6 & 0xfffffdff;
        }
        *(uint *)(lVar10 + 0xc0) = uVar6 & 0xfffffbff;
      }
      plVar9 = plVar9 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}



===== GpiopEnableInterrupt @ 140009b38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint GpiopEnableInterrupt
               (longlong param_1,uint param_2,int param_3,uint param_4,undefined8 param_5,
               ulonglong *param_6)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  code *pcVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  uint uVar13;
  int iVar14;
  undefined8 uVar15;
  longlong lVar16;
  longlong *plVar17;
  char *pcVar18;
  undefined8 uVar19;
  undefined2 uVar20;
  longlong lVar21;
  undefined8 in_stack_fffffffffffffeb8;
  longlong *plVar22;
  int *piVar23;
  undefined4 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  byte local_108;
  byte local_107;
  byte local_104;
  byte local_103;
  byte local_102;
  char local_101;
  uint local_100 [2];
  undefined8 local_f8;
  int local_f0;
  uint local_ec;
  longlong local_e8;
  undefined4 local_e0;
  longlong local_d8;
  int local_d0 [2];
  ulonglong local_c8;
  longlong local_c0;
  longlong local_b8;
  ulonglong local_b0;
  char *local_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  uVar15 = 0;
  uVar19 = 0x60;
  memset(&local_98,0,0x60);
  local_b0 = 0xffff;
  local_101 = '\0';
  lVar21 = 0;
  local_f0 = 0;
  lVar16 = 0;
  local_b8 = 0;
  local_f8 = (undefined8 *)((ulonglong)local_f8._4_4_ << 0x20);
  local_100[0] = 0;
  local_d8 = 0;
  local_107 = 0;
  local_104 = 0;
  local_ec = 0;
  local_e8 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_103 = 0;
  uVar25 = (undefined1)param_2;
  if (param_4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc00000bb;
    }
    uVar26 = 0;
    uVar20 = 10;
LAB_140009be7:
    uVar5 = 0xc00000bb;
    WPP_RECORDER_SF_Ddd(*(undefined8 *)(param_1 + 0x298),uVar15,uVar19,uVar20,
                        in_stack_fffffffffffffeb8,uVar25,(char)param_3,uVar26);
  }
  else {
    if ((param_3 == 0) && (param_4 == 3)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc00000bb;
      }
      uVar26 = 3;
      uVar20 = 0xb;
      param_3 = 0;
      goto LAB_140009be7;
    }
    plVar17 = &local_c0;
    uVar15 = CONCAT71((int7)((ulonglong)uVar19 >> 8),1);
    uVar5 = GpiopQueryResourceHubBiosDescriptor
                      (*(undefined8 *)(param_1 + 0x2c8),(longlong *)(param_1 + 0x110),uVar15,
                       (ulonglong)param_2,plVar17);
    lVar2 = local_c0;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0xc,
                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,(char)uVar5);
      }
    }
    else {
      uVar5 = *(uint *)(local_c0 + 4);
      uVar11 = (ulonglong)uVar5;
      if (uVar5 < 0x17) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar20 = 0xd;
LAB_140009cc4:
          WPP_RECORDER_SF_Ddd(*(undefined8 *)(param_1 + 0x298),uVar11,uVar15,uVar20,plVar17,uVar25,
                              (char)uVar11,0x17);
        }
      }
      else {
        pcVar18 = (char *)(local_c0 + 8);
        local_a8 = pcVar18;
        cVar4 = GpioUtilIsBiosGpioDescriptorValid(pcVar18,uVar5);
        if (cVar4 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar20 = 0xe;
            goto LAB_140009cc4;
          }
        }
        else {
          uVar11 = (ulonglong)*(ushort *)(lVar2 + 0x19) - (ulonglong)*(ushort *)(lVar2 + 0x16) >> 1;
          uVar1 = *(ushort *)(pcVar18 + *(ushort *)(lVar2 + 0x16));
          local_100[0] = (uint)*(ushort *)(lVar2 + 0x14);
          local_102 = *(byte *)(lVar2 + 0xf) & 8;
          if ((short)uVar11 == 1) {
            lVar2 = *(longlong *)(param_1 + 0x68);
            local_108 = 0;
            uVar26 = (undefined1)uVar1;
            if (lVar2 != 0) {
              uVar5 = 0;
              if (*(uint *)(lVar2 + 4) != 0) {
                puVar6 = (uint *)(lVar2 + 0x10);
                do {
                  if ((*(char *)((longlong)puVar6 + -7) == '\x02') && (param_2 == *puVar6)) {
                    local_108 = 1;
                    uVar5 = GpiopValidateEventMethodForPin(param_1,param_3,uVar1,&local_103);
                    if ((int)uVar5 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,8,0x10,
                                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                           (char)param_1,uVar26);
                      }
                      goto LAB_140009eea;
                    }
                    break;
                  }
                  uVar5 = uVar5 + 1;
                  puVar6 = puVar6 + 8;
                } while (uVar5 < *(uint *)(lVar2 + 4));
              }
            }
            uVar24 = (undefined4)((ulonglong)plVar17 >> 0x20);
            uVar11 = (ulonglong)uVar1 / (ulonglong)*(ushort *)(param_1 + 0x2d6);
            uVar8 = (ulonglong)uVar1 % (ulonglong)*(ushort *)(param_1 + 0x2d6);
            local_e0 = (undefined4)uVar8;
            if ((*(ushort *)(param_1 + 0x2d8) <= (ushort)uVar11) ||
               (plVar17 = (longlong *)(uVar11 * 400 + *(longlong *)(param_1 + 0x2e0)),
               plVar17 == (longlong *)0x0)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x11,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,uVar26);
              }
              uVar5 = 0xc000000d;
              lVar21 = local_d8;
              goto LAB_140009eea;
            }
            puVar7 = (undefined4 *)GpiopGetPinEntryInternal((longlong)plVar17,(ushort)uVar8,'\x01');
            if (puVar7 == (undefined4 *)0x0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x12,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,uVar26);
              }
              uVar5 = 0xc000000d;
LAB_140009ee2:
              lVar21 = local_d8;
            }
            else {
              uVar5 = GpiopQueryEmulatedActiveBothInitialPolarity
                                (*(undefined8 *)(param_1 + 0x2c8),(longlong *)(param_1 + 0x110),
                                 param_2,&local_ec);
              if (-1 < (int)uVar5) {
                if ((param_4 == 3) && ((*(uint *)(param_1 + 0x314) & 0x40) != 0)) {
                  if (local_ec == 0) {
                    local_ec = 2 - (*(char *)(puVar7 + 1) != '\0');
                  }
                  bVar10 = 1;
                  local_107 = 1;
                }
                else {
                  bVar10 = 0;
                }
                if (((*(uint *)(param_1 + 0x314) & 0x20) != 0) && (local_100[0] != 0)) {
                  plVar22 = &local_e8;
                  uVar5 = GpiopAllocateDebounceResources
                                    ((longlong)plVar17,(longlong)puVar7,(undefined2)local_e0,
                                     &local_d8,plVar22,&local_b8);
                  uVar24 = (undefined4)((ulonglong)plVar22 >> 0x20);
                  if ((int)uVar5 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_DDDd(*(undefined8 *)(param_1 + 0x298));
                    }
                    goto LAB_140009ee2;
                  }
                  local_c8 = (ulonglong)GpioGlobalNoiseIntervalOverride;
                  if ((GpioGlobalNoiseIntervalOverride == 0) &&
                     (local_c8 = 1000, (*(uint *)(param_1 + 0x314) & 1) != 0)) {
                    local_c8 = 500;
                  }
                  local_d0[0] = 0;
                  if (((*(byte *)(param_1 + 4) & 2) != 0) &&
                     (*(code **)(param_1 + 0x288) != (code *)0x0)) {
                    piVar23 = local_d0;
                    (**(code **)(param_1 + 0x288))
                              (param_1 + 0x400,uVar1,local_100,&local_c8,piVar23);
                    uVar24 = (undefined4)((ulonglong)piVar23 >> 0x20);
                    if (local_d0[0] == 1) {
                      local_f0 = 1;
                    }
                    else if (local_d0[0] == 2) {
                      local_f0 = 2;
                    }
                    else if (local_d0[0] == 3) {
                      local_f0 = 3;
                    }
                    else {
                      local_f0 = 0;
                    }
                  }
                  puVar12 = local_f8;
                  local_f8 = (undefined8 *)((ulonglong)local_f8 & 0xffffffff00000000);
                  puVar3 = local_f8;
                  uVar13 = *(uint *)(plVar17[0x11] + 0x314);
                  local_f8._4_4_ = SUB84(puVar12,4);
                  if (local_107 == 0) {
                    if (((param_4 != 3) && (*(longlong *)(plVar17[0x11] + 0x208) != 0)) &&
                       ((param_3 == 0 || (((uVar13 & 1) != 0 || ((uVar13 & 0x40) != 0)))))) {
                      local_f8 = (undefined8 *)CONCAT44(local_f8._4_4_,2);
                      puVar3 = local_f8;
                    }
                  }
                  else {
                    local_f8 = (undefined8 *)CONCAT44(local_f8._4_4_,1);
                    puVar3 = local_f8;
                  }
                  local_f8 = puVar3;
                  local_104 = 1;
                  bVar10 = local_107;
                }
                uVar15 = CONCAT44(uVar24,local_f0);
                GpiopDebounceInitializeContext
                          (*(byte *)(param_1 + 0x314) & 1,local_104,bVar10,(int)local_f8,local_f0,
                           (undefined4 *)&local_98);
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qDDDDDi(*(undefined8 *)(param_1 + 0x298));
                }
                if (local_108 != 0) {
                  PoFxActivateComponent(*(undefined8 *)(param_1 + 0x118),(short)plVar17[0x10],1);
                  local_101 = '\x01';
                }
                (**(code **)(WdfFunctions_01015 + 0x260))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),0);
                (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar17[6],0);
                plVar17[7] = (longlong)SystemReserved1[0xf];
                uVar8 = (ulonglong)(uint)puVar7[0x30];
                uVar27 = SUB81(puVar7,0);
                uVar11 = uVar8;
                if (((puVar7[0x30] & 2) != 0) && (GpioAllowInterruptOutput == '\0')) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_DDq(*(undefined8 *)(param_1 + 0x298),
                                        (undefined8 *)(param_1 + 0x298),uVar8,0x16,uVar15,uVar25,
                                        uVar26,uVar27);
                    uVar8 = (ulonglong)(uint)puVar7[0x30];
                  }
                  uVar5 = 0xc000000d;
                }
                uVar13 = (uint)uVar8;
                if ((uVar8 & 4) != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_DDq(*(undefined8 *)(param_1 + 0x298),(ulonglong)uVar1,uVar11,
                                        0x17,uVar15,uVar25,uVar26,uVar27);
                    uVar13 = puVar7[0x30];
                  }
                  uVar5 = 0xc000000d;
                }
                puVar12 = (undefined8 *)(param_1 + 0x298);
                uVar11 = (ulonglong)uVar13;
                if (((uVar13 & 3) != 0) &&
                   (((uVar13 >> 9 & 1) != 0 || (local_f8 = puVar12, local_102 == 0)))) {
                  local_f8 = (undefined8 *)(param_1 + 0x298);
                  uVar11 = (ulonglong)uVar13;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_DDq(*puVar12,(ulonglong)uVar1,uVar11,0x18,uVar15,uVar25,uVar26,
                                        uVar27);
                    uVar11 = (ulonglong)(uint)puVar7[0x30];
                  }
                  uVar5 = 0xc000000d;
                  puVar12 = local_f8;
                }
                if ((uVar11 & 8) == 0) {
                  if (-1 < (int)uVar5) {
                    *(undefined8 *)(puVar7 + 10) = local_98;
                    *(undefined8 *)(puVar7 + 0xc) = uStack_90;
                    *(undefined8 *)(puVar7 + 0xe) = local_88;
                    *(undefined8 *)(puVar7 + 0x10) = uStack_80;
                    bVar10 = (byte)local_e0;
                    local_f8 = (undefined8 *)(1L << (bVar10 & 0x3f));
                    *(undefined8 *)(puVar7 + 0x12) = local_78;
                    *(undefined8 *)(puVar7 + 0x14) = uStack_70;
                    uVar5 = 1 << (bVar10 & 0x1f);
                    *(undefined8 *)(puVar7 + 0x16) = local_68;
                    *(undefined8 *)(puVar7 + 0x18) = uStack_60;
                    puVar7[0x1a] = local_58;
                    puVar7[0x1b] = uStack_54;
                    puVar7[0x1c] = uStack_50;
                    puVar7[0x1d] = uStack_4c;
                    puVar7[0x1e] = local_48;
                    puVar7[0x1f] = uStack_44;
                    puVar7[0x20] = uStack_40;
                    puVar7[0x21] = uStack_3c;
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x1c) = *(uint *)(plVar17 + 0x1c) & ~uVar5;
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x1c] = plVar17[0x1c] & ~(ulonglong)local_f8;
                      UNLOCK();
                    }
                    lVar16 = *plVar17;
                    if (lVar16 == 0) {
                      pcVar9 = *(code **)(WdfFunctions_01015 + 0x9e0);
                      lVar16 = plVar17[3];
                    }
                    else {
                      pcVar9 = *(code **)(WdfFunctions_01015 + 0x480);
                    }
                    (*pcVar9)(WdfDriverGlobals,lVar16);
                    plVar17[4] = (longlong)SystemReserved1[0xf];
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x1a) = *(uint *)(plVar17 + 0x1a) & ~uVar5;
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x1a] = plVar17[0x1a] & ~(ulonglong)local_f8;
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x1b) = *(uint *)(plVar17 + 0x1b) & ~uVar5;
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x1b] = plVar17[0x1b] & ~(ulonglong)local_f8;
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x16) =
                           *(uint *)(plVar17 + 0x16) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x16] = plVar17[0x16] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x17) =
                           *(uint *)(plVar17 + 0x17) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x17] = plVar17[0x17] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x29) =
                           *(uint *)(plVar17 + 0x29) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x29] = plVar17[0x29] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x20) =
                           *(uint *)(plVar17 + 0x20) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x20] = plVar17[0x20] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x21) =
                           *(uint *)(plVar17 + 0x21) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x21] = plVar17[0x21] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x1e) =
                           *(uint *)(plVar17 + 0x1e) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x1e] = plVar17[0x1e] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x1f) =
                           *(uint *)(plVar17 + 0x1f) & ~(1 << (bVar10 & 0x1f));
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x1f] = plVar17[0x1f] & ~(1L << (bVar10 & 0x3f));
                      UNLOCK();
                    }
                    *(undefined1 *)((longlong)puVar7 + 0xb9) = 0;
                    lVar16 = *plVar17;
                    plVar17[4] = 0;
                    if (lVar16 == 0) {
                      pcVar9 = *(code **)(WdfFunctions_01015 + 0x9e8);
                      lVar16 = plVar17[3];
                    }
                    else {
                      pcVar9 = *(code **)(WdfFunctions_01015 + 0x488);
                    }
                    (*pcVar9)(WdfDriverGlobals,lVar16);
                    puVar7[0x32] = puVar7[0x32] + 1;
                    uVar13 = (uint)local_108 << 4 | puVar7[0x30] & 0xffffffef | 4;
                    *(undefined8 *)(puVar7 + 0x22) = 0;
                    puVar7[0x24] = 0;
                    uVar13 = ((uint)local_103 << 6 ^ uVar13) & 0x40 ^ uVar13;
                    uVar5 = (uint)local_107 << 8 | (uint)local_104 << 7 | uVar13 & 0xfffffe7f |
                            0x201;
                    if (local_102 != 0) {
                      uVar5 = (uint)local_107 << 8 | (uint)local_104 << 7 | uVar13 & 0xfffffc7f | 1;
                    }
                    puVar7[0x30] = uVar5;
                    iVar14 = 0;
                    if (local_107 == 0) {
                      iVar14 = param_3;
                    }
                    puVar7[0x3b] = param_3;
                    *(undefined8 *)(puVar7 + 0x3e) = param_5;
                    puVar7[0x3c] = param_4;
                    if (local_107 != 0) {
                      param_4 = local_ec;
                    }
                    puVar7[3] = param_4;
                    puVar7[2] = iVar14;
                    LOCK();
                    puVar7[0x40] = param_2;
                    UNLOCK();
                    local_f8 = (undefined8 *)CONCAT44(local_f8._4_4_,iVar14);
                    if (param_6 != (ulonglong *)0x0) {
                      LOCK();
                      local_b0 = *param_6;
                      *param_6 = (ulonglong)uVar1;
                      UNLOCK();
                    }
                    *(char *)(puVar7 + 0x3a) = local_a8[9];
                    puVar7[0x36] = local_100[0];
                    *(longlong *)(puVar7 + 4) = local_d8;
                    *(longlong *)(puVar7 + 6) = local_e8;
                    *(ulonglong *)(puVar7 + 0x38) = local_c8;
                    *(longlong *)(puVar7 + 8) = local_b8;
                    if (local_104 != 0) {
                      *(int *)(plVar17 + 10) = (int)plVar17[10] + 1;
                    }
                    LOCK();
                    puVar7[0x31] = 0;
                    UNLOCK();
                    if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                      LOCK();
                      *(uint *)(plVar17 + 0x28) = *(uint *)(plVar17 + 0x28) | 1 << (bVar10 & 0x1f);
                      UNLOCK();
                    }
                    else {
                      LOCK();
                      plVar17[0x28] = plVar17[0x28] | 1L << (bVar10 & 0x3f);
                      UNLOCK();
                    }
                    *puVar7 = 1;
                    uVar5 = GpioClnInvokeEnableInterrupt
                                      ((longlong)plVar17,(undefined2)local_e0,iVar14,param_4,
                                       (longlong)local_a8);
                    GpiopCheckEnabledInterrupts(plVar17);
                    if ((int)uVar5 < 0) {
                      puVar7[0x30] = puVar7[0x30] & 0xfffffc2b;
                      if (param_6 != (ulonglong *)0x0) {
                        LOCK();
                        *param_6 = local_b0;
                        UNLOCK();
                      }
                      LOCK();
                      puVar7[0x40] = 0;
                      UNLOCK();
                      piVar23 = puVar7 + 0x32;
                      *piVar23 = *piVar23 + -1;
                      *(undefined8 *)(puVar7 + 0x3b) = 0;
                      puVar7[3] = 0;
                      *(undefined8 *)(puVar7 + 0x3e) = 0;
                      if (*piVar23 == 0) {
                        puVar7[0x30] = puVar7[0x30] & 0xfffffffe;
                      }
                      *(undefined1 *)(puVar7 + 0x3a) = 0;
                      if (*(ushort *)(plVar17 + 0x30) < 0x21) {
                        LOCK();
                        *(uint *)(plVar17 + 0x28) =
                             *(uint *)(plVar17 + 0x28) & ~(1 << (bVar10 & 0x1f));
                        UNLOCK();
                      }
                      else {
                        LOCK();
                        plVar17[0x28] = plVar17[0x28] & ~(1L << (bVar10 & 0x3f));
                        UNLOCK();
                      }
                      puVar7[0x36] = 0;
                      *(undefined8 *)(puVar7 + 0x38) = 0;
                      if (local_104 != 0) {
                        *(undefined8 *)(puVar7 + 4) = 0;
                        *(undefined8 *)(puVar7 + 6) = 0;
                        *(undefined8 *)(puVar7 + 8) = 0;
                        *(int *)(plVar17 + 10) = (int)plVar17[10] + -1;
                      }
                    }
                  }
                }
                else {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_DDq(*puVar12,puVar12,uVar11,0x19,uVar15,uVar25,uVar26,uVar27);
                  }
                  uVar5 = 0xc000000d;
                }
                plVar17[7] = 0;
                (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar17[6]);
                if ((int)uVar5 < 0) {
                  (**(code **)(WdfFunctions_01015 + 0x260))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),1);
                }
                else {
                  PoFxActivateComponent(*(undefined8 *)(param_1 + 0x118),(short)plVar17[0x10],0);
                }
                if (local_101 != '\0') {
                  PoFxIdleComponent(*(undefined8 *)(param_1 + 0x118),(short)plVar17[0x10],0);
                }
                if (-1 < (int)uVar5) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_qDDDD(*(undefined8 *)(param_1 + 0x298));
                  }
                  goto LAB_140009fba;
                }
                goto LAB_140009ee2;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x13,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,
                                   (char)uVar5);
              }
            }
            lVar16 = local_e8;
            goto LAB_140009eea;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0xf,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,(char)uVar11)
            ;
          }
        }
      }
      uVar5 = 0xc0000001;
    }
  }
LAB_140009eea:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x1a,
                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar25,(char)uVar5);
  }
  if ((int)uVar5 < 0) {
    if (lVar21 != 0) {
      if (*(longlong *)(lVar21 + 0x18) != 0) {
        ExDeleteTimer(*(longlong *)(lVar21 + 0x18),1,0,0);
      }
      ExFreePoolWithTag(lVar21,0x786c4347);
    }
    if (lVar16 != 0) {
      if (*(longlong *)(lVar16 + 0x20) != 0) {
        ExDeleteTimer(*(longlong *)(lVar16 + 0x20),1,0,0);
      }
      ExFreePoolWithTag(lVar16,0x786c4347);
    }
    if (local_b8 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
  }
LAB_140009fba:
  if (local_c0 != 0) {
    ExFreePoolWithTag(local_c0,0x786c4347);
  }
  return uVar5;
}



===== GpiopFlipPinPolarity @ 14000aa7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GpiopFlipPinPolarity(ulonglong param_1,ushort param_2)

{
  undefined2 uVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStackY_b8 [32];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar7 = param_1;
  lVar5 = GpiopGetPinEntryInternal(param_1,param_2,'\0');
  uVar6 = *(uint *)(lVar5 + 8);
  if (((*(uint *)(lVar5 + 0xc0) & 0x100) == 0) && (*(int *)(lVar5 + 0xec) == 1)) {
    uVar7 = (ulonglong)(uVar6 != 1);
    uVar6 = (uint)(uVar6 != 1);
  }
  iVar9 = 5;
  uVar2 = *(uint *)(lVar5 + 0x2c);
  uVar10 = (*(int *)(lVar5 + 0xc) == 1) + 1;
  do {
    lVar3 = *(longlong *)(param_1 + 0x88);
    local_50 = 0;
    uStack_48 = 0;
    if (*(longlong *)(lVar3 + 0x208) == 0) {
      uVar8 = 0xc00000bb;
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0x80);
      local_50 = CONCAT44(uVar6,CONCAT22(param_2,uVar1));
      uStack_48 = (ulonglong)uVar10;
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        in_stack_ffffffffffffff68 =
             CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff68 >> 0x10),uVar1);
        McTemplateK0zhh_EtwWriteTransfer
                  (uVar7,&EVENT_RECONFIGURE_INTERRUPT_START,param_1 + 0x70,
                   *(wchar_t **)(lVar3 + 0x300),(char)uVar1,(char)param_2);
      }
      uVar7 = lVar3 + 0x400;
      iVar4 = (**(code **)(lVar3 + 0x208))(uVar7,&local_50);
      uVar8 = (ulonglong)iVar4;
      if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
        McTemplateK0h_EtwWriteTransfer
                  (uVar7,&EVENT_RECONFIGURE_INTERRUPT_COMPLETE,param_1 + 0x70,param_2);
      }
      if (-1 < iVar4) {
LAB_14000abe1:
        *(uint *)(lVar5 + 0xc) = uVar10;
        *(uint *)(lVar5 + 8) = uVar6;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sqDDD
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x298),4,8,0x3c,
                     in_stack_ffffffffffffff68,"GpiopFlipPinPolarity",(char)param_1,(char)param_2,
                     (char)uVar6,(char)uVar10);
        }
        break;
      }
      if ((uVar2 & 0xe) == 4) {
        if (-1 < iVar4) goto LAB_14000abe1;
      }
      else if ((*(uint *)(lVar3 + 0x314) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,5,uVar8,lVar3);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      if (-1 < (int)uVar8) break;
    }
    else {
      uVar7 = *(ulonglong *)(*(longlong *)(param_1 + 0x88) + 0x298);
      WPP_RECORDER_SF_sqDDDD(uVar7);
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  return uVar8 & 0xffffffff;
}



===== GpiopFlushPendingPinInterruptActivities @ 14000acc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopFlushPendingPinInterruptActivities(longlong *param_1,longlong param_2,ushort param_3)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 local_res8 [8];
  
  lVar1 = param_1[0x11];
  local_res8[0] = 0;
  lVar7 = 0;
  lVar8 = 0;
  lVar5 = 0;
  GpiopMaskInterrupt(lVar1,0,(ulonglong)*(uint *)(param_2 + 0x100));
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1[6],0);
  lVar4 = *param_1;
  param_1[7] = (longlong)SystemReserved1[0xf];
  if (lVar4 == 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e0);
    lVar4 = param_1[3];
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x480);
  }
  (*pcVar2)(WdfDriverGlobals,lVar4);
  param_1[4] = (longlong)SystemReserved1[0xf];
  uVar6 = 1L << ((byte)param_3 & 0x3f);
  uVar3 = 1 << ((byte)param_3 & 0x1f);
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    LOCK();
    *(uint *)(param_1 + 0x1e) = *(uint *)(param_1 + 0x1e) & ~uVar3;
    UNLOCK();
  }
  else {
    LOCK();
    param_1[0x1e] = param_1[0x1e] & ~uVar6;
    UNLOCK();
  }
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    LOCK();
    *(uint *)(param_1 + 0x1f) = *(uint *)(param_1 + 0x1f) & ~uVar3;
    UNLOCK();
  }
  else {
    uVar6 = ~uVar6;
    LOCK();
    param_1[0x1f] = param_1[0x1f] & uVar6;
    UNLOCK();
  }
  lVar4 = *(longlong *)(param_2 + 0x10);
  if (lVar4 != 0) {
    lVar8 = *(longlong *)(lVar4 + 0x18);
    lVar7 = *(longlong *)(lVar4 + 0x20);
  }
  if (*(longlong *)(param_2 + 0x18) != 0) {
    lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0x20);
  }
  lVar4 = *param_1;
  param_1[4] = 0;
  if (lVar4 == 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
    lVar4 = param_1[3];
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x488);
  }
  (*pcVar2)(WdfDriverGlobals,lVar4);
  if ((*(uint *)(param_2 + 0xc0) & 0x10) != 0) {
    GpiopAcquireAcpiEventLock(lVar1,local_res8);
    GpioUtilUpdatePinValue((longlong)param_1,param_3,uVar6,'\0');
    if ((*(uint *)(lVar1 + 0x314) & 1) == 0) {
      ExReleaseFastMutex(lVar1 + 0x78);
    }
    else {
      KeReleaseSpinLockFromDpcLevel(lVar1 + 0xb0);
      KeLowerIrql(local_res8[0]);
    }
  }
  param_1[7] = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1[6]);
  if (lVar8 != 0) {
    ExCancelTimer(lVar8,0);
  }
  if (lVar5 != 0) {
    ExCancelTimer(lVar5,0);
  }
  KeFlushQueuedDpcs();
  if (lVar7 != 0) {
    (**(code **)(WdfFunctions_01015 + 0xbf0))(WdfDriverGlobals,lVar7);
  }
  return;
}



===== GpiopGetBankEntry @ 14000af20 =====

longlong GpiopGetBankEntry(longlong param_1,ushort param_2)

{
  if (param_2 < *(ushort *)(param_1 + 0x2d8)) {
    return (ulonglong)param_2 * 400 + *(longlong *)(param_1 + 0x2e0);
  }
  return 0;
}



===== GpiopGetBankEntryFromVirq @ 14000af48 =====

longlong GpiopGetBankEntryFromVirq(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar6 = 0;
  if (*(short *)(param_1 + 0x2d8) != 0) {
    do {
      lVar5 = (ulonglong)uVar6 * 400 + *(longlong *)(param_1 + 0x2e0);
      lVar3 = 0;
      LOCK();
      lVar2 = *(longlong *)(lVar5 + 0x188);
      if (lVar2 == 0) {
        *(longlong *)(lVar5 + 0x188) = 0;
      }
      else {
        lVar3 = lVar2;
      }
      UNLOCK();
      if ((lVar2 != 0) && (uVar7 = 0, *(short *)(lVar5 + 0x180) != 0)) {
        do {
          lVar4 = 0;
          plVar1 = (longlong *)(lVar3 + (ulonglong)uVar7 * 8);
          LOCK();
          lVar2 = *plVar1;
          if (lVar2 == 0) {
            *plVar1 = 0;
          }
          else {
            lVar4 = lVar2;
          }
          UNLOCK();
          if ((lVar2 != 0) && (*(int *)(lVar4 + 0x100) == param_2)) {
            return lVar5;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar5 + 0x180));
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)(param_1 + 0x2d8));
  }
  return 0;
}



===== GpiopGetPinEntryFromPinNumberInternal @ 14000afe4 =====

longlong GpiopGetPinEntryFromPinNumberInternal(longlong param_1,uint param_2,char param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((ushort)param_2 < *(ushort *)(param_1 + 0x2d4)) {
    uVar1 = (ulonglong)(param_2 & 0xffff) / (ulonglong)*(ushort *)(param_1 + 0x2d6);
    lVar2 = 0;
    if (((ushort)uVar1 < *(ushort *)(param_1 + 0x2d8)) &&
       (lVar3 = uVar1 * 400 + *(longlong *)(param_1 + 0x2e0), lVar3 != 0)) {
      lVar2 = GpiopGetPinEntryInternal
                        (lVar3,(ushort)((ulonglong)(param_2 & 0xffff) %
                                       (ulonglong)*(ushort *)(param_1 + 0x2d6)),param_3);
    }
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}



===== GpiopGetPinEntryFromVirq @ 14000b054 =====

longlong GpiopGetPinEntryFromVirq
                   (longlong param_1,int param_2,longlong *param_3,ushort *param_4,ushort *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar7 = 0;
  if (*(short *)(param_1 + 0x2d8) != 0) {
    do {
      lVar5 = (ulonglong)uVar7 * 400 + *(longlong *)(param_1 + 0x2e0);
      lVar3 = 0;
      LOCK();
      lVar2 = *(longlong *)(lVar5 + 0x188);
      if (lVar2 == 0) {
        *(longlong *)(lVar5 + 0x188) = 0;
      }
      else {
        lVar3 = lVar2;
      }
      UNLOCK();
      if ((lVar2 != 0) && (uVar6 = 0, *(short *)(lVar5 + 0x180) != 0)) {
        do {
          lVar4 = 0;
          plVar1 = (longlong *)(lVar3 + (ulonglong)uVar6 * 8);
          LOCK();
          lVar2 = *plVar1;
          if (lVar2 == 0) {
            *plVar1 = 0;
          }
          else {
            lVar4 = lVar2;
          }
          UNLOCK();
          if ((lVar2 != 0) && (*(int *)(lVar4 + 0x100) == param_2)) {
            if (param_3 != (longlong *)0x0) {
              *param_3 = lVar5;
            }
            if (param_4 != (ushort *)0x0) {
              *param_4 = uVar7;
            }
            if (param_5 == (ushort *)0x0) {
              return lVar4;
            }
            *param_5 = uVar6;
            return lVar4;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(ushort *)(lVar5 + 0x180));
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(ushort *)(param_1 + 0x2d8));
  }
  return 0;
}



===== GpiopGetPinEntryInternal @ 14000b138 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong GpiopGetPinEntryInternal(longlong param_1,ushort param_2,char param_3)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  
  bVar3 = false;
  lVar5 = 0;
  if ((param_3 != '\0') && (*(void **)(param_1 + 0x38) != SystemReserved1[0xf])) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30),0);
    bVar3 = true;
    *(void **)(param_1 + 0x38) = SystemReserved1[0xf];
  }
  if (*(ushort *)(param_1 + 0x180) <= param_2) goto LAB_14000b2e5;
  lVar4 = 0;
  LOCK();
  lVar2 = *(longlong *)(param_1 + 0x188);
  if (lVar2 == 0) {
    *(longlong *)(param_1 + 0x188) = 0;
  }
  else {
    lVar4 = lVar2;
  }
  UNLOCK();
  if (lVar2 == 0) {
    if (param_3 == '\0') goto LAB_14000b2e5;
    iVar6 = (uint)*(ushort *)(param_1 + 0x180) << 3;
    lVar4 = ExAllocatePool2(0x40,iVar6,0x786c4347);
    if (lVar4 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x298),2,1,0xa6,
                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                           "GpiopGetPinEntryInternal",(char)iVar6);
      }
      goto LAB_14000b2e5;
    }
    LOCK();
    *(longlong *)(param_1 + 0x188) = lVar4;
    UNLOCK();
  }
  lVar5 = 0;
  plVar1 = (longlong *)(lVar4 + (ulonglong)param_2 * 8);
  LOCK();
  lVar2 = *plVar1;
  if (lVar2 == 0) {
    *plVar1 = 0;
  }
  else {
    lVar5 = lVar2;
  }
  UNLOCK();
  if ((lVar2 == 0) && (param_3 != '\0')) {
    lVar5 = ExAllocatePool2(0x40,0x110,0x786c4347);
    if (lVar5 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x298),2,1,0xa7,
                          &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                          "GpiopGetPinEntryInternal");
      }
    }
    else {
      LOCK();
      *(longlong *)(lVar4 + (ulonglong)param_2 * 8) = lVar5;
      UNLOCK();
    }
  }
LAB_14000b2e5:
  if (bVar3) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x30));
  }
  return lVar5;
}



===== GpiopIncrementMaskCount @ 14000b334 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopIncrementMaskCount(longlong *param_1,longlong param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  
  if ((void *)param_1[4] == SystemReserved1[0xf]) {
    bVar3 = false;
  }
  else {
    lVar6 = *param_1;
    bVar3 = true;
    if (lVar6 == 0) {
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar6 = param_1[3];
    }
    else {
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar4)(WdfDriverGlobals,lVar6);
    param_1[4] = (longlong)SystemReserved1[0xf];
  }
  LOCK();
  piVar1 = (int *)(param_2 + 0xc4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 + 1 == 1) {
    uVar5 = 1L << (param_3 & 0x3f);
    uVar7 = 1 << (param_3 & 0x1f);
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(param_1 + 0x17) = *(uint *)(param_1 + 0x17) & ~uVar7;
      UNLOCK();
    }
    else {
      LOCK();
      param_1[0x17] = param_1[0x17] & ~uVar5;
      UNLOCK();
    }
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(param_1 + 0x16) = *(uint *)(param_1 + 0x16) | uVar7;
      UNLOCK();
    }
    else {
      LOCK();
      param_1[0x16] = param_1[0x16] | uVar5;
      UNLOCK();
    }
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(param_1 + 0x29) = *(uint *)(param_1 + 0x29) | uVar7;
      UNLOCK();
    }
    else {
      LOCK();
      param_1[0x29] = param_1[0x29] | uVar5;
      UNLOCK();
    }
  }
  if (bVar3) {
    lVar6 = *param_1;
    param_1[4] = 0;
    if (lVar6 == 0) {
      lVar6 = param_1[3];
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x9e8);
    }
    else {
      pcVar4 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    (*pcVar4)(WdfDriverGlobals,lVar6);
  }
  return iVar2 + 1;
}



===== GpiopMaskInterrupt @ 14000b48c =====

int GpiopMaskInterrupt(longlong param_1,uint param_2,undefined8 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  void *pvVar6;
  ulonglong **ppuVar7;
  ulonglong *puVar8;
  ushort local_res8 [4];
  ushort local_res20 [4];
  undefined8 in_stack_ffffffffffffff88;
  ushort *puVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  ulonglong *local_48 [2];
  
  local_res20[0] = 0;
  iVar2 = 0;
  local_48[0] = (ulonglong *)0x0;
  local_res8[0] = 0;
  LOCK();
  iVar3 = *(int *)(param_1 + 0x2d0);
  if (iVar3 == 0) {
    *(int *)(param_1 + 0x2d0) = 0;
  }
  else {
    iVar2 = iVar3;
  }
  UNLOCK();
  uVar10 = (undefined1)param_1;
  if (iVar2 != 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqd(*(undefined8 *)(param_1 + 0x298),4,param_3,0x20,in_stack_ffffffffffffff88,
                          "GpiopMaskInterrupt",uVar10,(char)*(undefined4 *)(param_1 + 0x2d0));
    }
    return 0;
  }
  puVar9 = local_res8;
  ppuVar7 = local_48;
  lVar4 = GpiopGetPinEntryFromVirq(param_1,(int)param_3,(longlong *)ppuVar7,local_res20,puVar9);
  uVar11 = (undefined1)param_3;
  if (lVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,8,0x21,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar10,uVar11);
    }
  }
  else {
    puVar8 = (ulonglong *)(ulonglong)local_res8[0];
    bVar1 = (byte)local_res8[0];
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDDD
                (*(undefined8 *)(param_1 + 0x298),4,ppuVar7,0x22,puVar9,uVar10,uVar11,
                 (char)local_res20[0],bVar1);
    }
    if ((*(uint *)(lVar4 + 0xc0) & 4) != 0) {
      iVar3 = GpiopIncrementMaskCount((longlong *)local_48[0],lVar4,bVar1);
      pvVar6 = SystemReserved1[0xf];
      if (1 < iVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        WPP_RECORDER_SF_qDDd
                  (*(undefined8 *)(param_1 + 0x298),lVar4,puVar8,0x24,puVar9,uVar10,uVar11,bVar1,
                   (char)iVar3);
        return 0;
      }
      if (((param_2 & 2) == 0) && ((void *)local_48[0][9] != SystemReserved1[0xf])) {
        bVar1 = KeGetCurrentIrql();
        if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
          if (bVar1 == 0) goto LAB_14000b6a0;
        }
        else if (bVar1 <= *(byte *)(param_1 + 6)) {
LAB_14000b6a0:
          uVar5 = GpiopDeferredMaskRequestHandler((longlong *)local_48[0]);
          iVar3 = (int)uVar5;
          if (-1 < iVar3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar3;
            }
            WPP_RECORDER_SF_qDD(*(undefined8 *)(param_1 + 0x298),pvVar6,puVar8,0x27,puVar9,uVar10,
                                uVar11,(char)local_res8[0]);
            return iVar3;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar3;
          }
          WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x26,
                             &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar11,(char)uVar5);
          return iVar3;
        }
      }
      else if ((ushort)local_48[0][0x30] < 0x21) {
        LOCK();
        *(uint *)(local_48[0] + 0x1a) = (uint)local_48[0][0x1a] | 1 << ((byte)local_res8[0] & 0x1f);
        UNLOCK();
      }
      else {
        LOCK();
        local_48[0][0x1a] = local_48[0][0x1a] | 1L << ((byte)local_res8[0] & 0x3f);
        UNLOCK();
      }
      uVar5 = GpiopScheduleDeferredInterruptActivities(local_48[0],pvVar6,puVar8);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return (int)uVar5;
      }
      WPP_RECORDER_SF_qDDD
                (*(undefined8 *)(param_1 + 0x298),4,puVar8,0x25,puVar9,uVar10,uVar11,
                 (char)local_res8[0],(char)uVar5);
      return (int)uVar5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,8,0x23,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        (char)*(uint *)(lVar4 + 0xc0));
    }
  }
  return -0x3ffffff3;
}



===== GpiopQueryBankPowerInformation @ 14000b7b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopQueryBankPowerInformation(longlong param_1,ulonglong *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  short local_68 [4];
  ulonglong uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_48 = 0;
  uStack_60 = 0;
  local_68[0] = 0;
  local_68[1] = 0x28;
  local_68[2] = 0;
  local_68[3] = 0;
  local_58 = 0;
  uStack_50 = 0;
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x88) + 400);
  if (pcVar1 != (code *)0x0) {
    uStack_38 = 0;
    local_40 = 0x3000000000;
    uStack_28 = 0;
    local_30 = (ulonglong)*(ushort *)(param_1 + 0x80);
    local_20 = 0;
    uStack_18 = 0;
    iVar2 = (*pcVar1)(*(longlong *)(param_1 + 0x88) + 0x400,&local_40,local_68);
    if ((iVar2 != -0x3ffffffe) && (iVar2 != -0x3fffff45)) {
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        WPP_RECORDER_SF_sD(*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x298),2,1,0x8f,
                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                           "GpiopQueryBankPowerInformation",(char)iVar2);
        return iVar2;
      }
      goto LAB_14000b8b0;
    }
  }
  local_68[0] = 1;
  uStack_60 = uStack_60 & 0xfffffffffffffffe;
  iVar2 = 0;
LAB_14000b8b0:
  uVar3 = GpiopValidateClientBankPowerInformation(param_1,local_68);
  if ((char)uVar3 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(*(longlong *)(param_1 + 0x88) + 0x298),2,1,0x90,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        "GpiopQueryBankPowerInformation");
    }
    iVar2 = -0x3fffffff;
  }
  else {
    *param_2 = uStack_60;
    param_2[1] = local_58;
    param_2[2] = uStack_50;
    param_2[3] = local_48;
  }
  return iVar2;
}



===== GpiopReadPins @ 14000b944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopReadPins(longlong param_1,ulonglong param_2,ulonglong param_3,void *param_4,
                       uint param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  char cVar10;
  ulonglong uVar11;
  byte *pbVar12;
  ulonglong uVar13;
  byte bVar14;
  longlong *plVar15;
  bool bVar16;
  byte local_res10;
  ulonglong *in_stack_ffffffffffffff78;
  undefined1 uVar17;
  undefined1 uVar18;
  ulonglong local_48 [2];
  
  bVar14 = 0;
  bVar16 = false;
  uVar11 = param_3 & 0xffffffffffffff01;
  uVar17 = (undefined1)param_1;
  if ((1 < *(int *)(param_2 + 0x1c) - 1U) && ((*(uint *)(param_2 + 100) & 1) == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,7,0x73,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar17,
                         (char)*(int *)(param_2 + 0x1c));
    }
    return 0xc000a125;
  }
  pbVar3 = *(byte **)(param_2 + 0x20);
  uVar2 = *(uint *)(param_2 + 0x28);
  local_48[0] = 0;
  uVar18 = (undefined1)uVar2;
  if ((pbVar3 == (byte *)0x0) || (uVar2 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x298),1,uVar11,0x74,in_stack_ffffffffffffff78,
                          uVar17,(char)pbVar3,uVar18);
    }
    return 0xc0000008;
  }
  if (param_5 < uVar2) {
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000023;
    }
    WPP_RECORDER_SF_qddD
              (*(undefined8 *)(param_1 + 0x298),1,uVar11,0x75,in_stack_ffffffffffffff78,uVar17,
               (char)(param_5 >> 3),(char)(uVar2 + 7 >> 3),uVar18);
    return 0xc0000023;
  }
  if (*(ushort *)(param_2 + 0x18) < *(ushort *)(param_1 + 0x2d8)) {
    plVar15 = (longlong *)
              ((ulonglong)*(ushort *)(param_2 + 0x18) * 400 + *(longlong *)(param_1 + 0x2e0));
  }
  else {
    plVar15 = (longlong *)0x0;
  }
  cVar10 = (char)uVar11;
  if (cVar10 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff78 = (ulonglong *)&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids;
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x298),4,7,0x76,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar17);
    }
    uVar11 = (ulonglong)uVar2;
    GpioUtilTracePrintPinNumbers(plVar15,(undefined2 *)pbVar3,uVar2);
  }
  iVar4 = 0;
  LOCK();
  iVar1 = *(int *)(param_1 + 0x2d0);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x2d0) = 0;
  }
  else {
    iVar4 = iVar1;
  }
  UNLOCK();
  if (iVar4 != 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDd(*(undefined8 *)(param_1 + 0x298),2,uVar11,0x77,in_stack_ffffffffffffff78,
                          uVar17,uVar18,(char)*(undefined4 *)(param_1 + 0x2d0));
    }
    return 0xc0000001;
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar15[6],0);
  uVar11 = 1;
  plVar15[7] = (longlong)SystemReserved1[0xf];
  uVar5 = *(uint *)(param_2 + 100) & 1;
  if ((uVar5 == 0) && (*(int *)(param_2 + 0x1c) == 2)) {
    local_res10 = 1;
    bVar14 = 1;
    if ((*(uint *)(param_2 + 100) & 4) == 0) {
      uVar9 = 0xc000a125;
      goto LAB_14000bcd6;
    }
  }
  else {
    local_res10 = 0;
    if ((uVar5 != 0) && (*(int *)(param_2 + 0x1c) != 1)) {
      in_stack_ffffffffffffff78 =
           (ulonglong *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff78 >> 8),cVar10);
      uVar11 = param_2;
      uVar8 = GpiopSwitchDirectionPins(param_1,(longlong)plVar15,param_2,1,cVar10);
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) goto LAB_14000bcd6;
    }
  }
  if ((-1 < (char)*(undefined4 *)(param_1 + 0x314)) &&
     (local_res10 = bVar14, (*(uint *)(plVar15[0x11] + 0x314) & 1) != 0)) {
    lVar7 = *plVar15;
    if (lVar7 == 0) {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar7 = plVar15[3];
    }
    else {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar6)(WdfDriverGlobals,lVar7);
    plVar15[4] = (longlong)SystemReserved1[0xf];
  }
  uVar11 = (ulonglong)uVar2;
  in_stack_ffffffffffffff78 = local_48;
  uVar5 = GpioClnInvokeReadPins
                    ((longlong)plVar15,pbVar3,uVar2,param_4,in_stack_ffffffffffffff78,
                     *(ulonglong *)(param_2 + 0x48),local_res10);
  uVar9 = (ulonglong)uVar5;
  if ((-1 < (char)*(undefined4 *)(param_1 + 0x314)) && ((*(uint *)(plVar15[0x11] + 0x314) & 1) != 0)
     ) {
    lVar7 = *plVar15;
    plVar15[4] = 0;
    if (lVar7 == 0) {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
      lVar7 = plVar15[3];
    }
    else {
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    (*pcVar6)(WdfDriverGlobals,lVar7);
  }
  bVar16 = (int)uVar5 < 0;
LAB_14000bcd6:
  uVar8 = plVar15[6];
  plVar15[7] = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  if ((int)uVar9 < 0) {
    if (bVar16) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdDD(*(undefined8 *)(param_1 + 0x298));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,7,0x79,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)uVar9);
    }
  }
  else {
    if ((*(uint *)(plVar15[0x11] + 0x314) & 4) != 0) {
      uVar8 = 0;
      memset(param_4,0,(ulonglong)(uVar2 + 7 >> 3));
      uVar11 = 0;
      if (uVar2 != 0) {
        uVar13 = 0;
        pbVar12 = pbVar3;
        do {
          if ((local_48[0] >> ((ulonglong)*pbVar12 & 0x3f) & 1) != 0) {
            uVar8 = uVar13 >> 3;
            *(byte *)(uVar8 + (longlong)param_4) =
                 *(byte *)(uVar8 + (longlong)param_4) | (byte)(1 << ((uint)uVar11 & 7));
          }
          uVar5 = (uint)uVar11 + 1;
          uVar11 = (ulonglong)uVar5;
          uVar13 = uVar13 + 1;
          pbVar12 = pbVar12 + 2;
        } while (uVar5 < uVar2);
      }
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar2;
    }
    if (cVar10 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x298),uVar8,uVar11,0x7a,
                           in_stack_ffffffffffffff78,uVar17,(char)param_4);
      }
      GpioUtilTracePrintPinNumbers(plVar15,(undefined2 *)pbVar3,uVar2);
    }
  }
  return uVar9;
}



===== GpiopReconfigureInterrupts @ 14000be94 =====

int GpiopReconfigureInterrupts(ulonglong *param_1,short param_2,ulonglong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  byte bVar7;
  byte bVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar9 = 1;
  bVar7 = (byte)param_2;
  if (param_2 != -1) {
    if ((ushort)param_1[0x30] < 0x21) {
      LOCK();
      *(uint *)(param_1 + 0x20) = (uint)param_1[0x20] | 1 << (bVar7 & 0x1f);
      UNLOCK();
    }
    else {
      LOCK();
      param_1[0x20] = param_1[0x20] | 1L << (bVar7 & 0x3f);
      UNLOCK();
    }
  }
  if ((ushort)param_1[0x30] < 0x21) {
    uVar4 = 0;
    LOCK();
    uVar1 = (uint)param_1[0x20];
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x20) = 0;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
    uVar6 = (ulonglong)uVar4;
  }
  else {
    uVar6 = 0;
    LOCK();
    uVar2 = param_1[0x20];
    if (uVar2 == 0) {
      param_1[0x20] = 0;
    }
    else {
      uVar6 = uVar2;
    }
    UNLOCK();
  }
  if (uVar6 == 0) {
    return 0;
  }
  uVar2 = param_1[0x11];
  if (((*(uint *)(uVar2 + 0x314) & 1) == 0) && (cVar3 = KeGetCurrentIrql(), cVar3 != '\0')) {
    uVar9 = GpiopScheduleDeferredInterruptActivities(param_1,uVar9,param_3);
    iVar5 = (int)uVar9;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar5;
    }
    uVar10 = 0x3e;
  }
  else {
    iVar5 = GpiopDeferredReconfigureRequestHandler((longlong *)param_1);
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar5;
      }
      uVar10 = 0x3f;
      bVar8 = 2;
      goto LAB_14000bf98;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar5;
    }
    uVar10 = 0x40;
  }
  bVar8 = 4;
LAB_14000bf98:
  WPP_RECORDER_SF_sqDD
            (*(undefined8 *)(uVar2 + 0x298),bVar8,8,uVar10,in_stack_ffffffffffffffc8,
             "GpiopReconfigureInterrupts",(char)uVar2,bVar7,(char)iVar5);
  return iVar5;
}



===== GpiopRequestInterrupt @ 14000bfe4 =====

uint GpiopRequestInterrupt(longlong param_1,int param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  bool bVar9;
  ushort local_res20 [4];
  ushort *puVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  ushort local_28 [4];
  longlong local_20;
  
  puVar10 = local_res20;
  local_28[0] = 0;
  plVar8 = &local_20;
  local_20 = 0;
  local_res20[0] = 0;
  lVar3 = GpiopGetPinEntryFromVirq(param_1,param_2,plVar8,local_28,puVar10);
  uVar11 = (undefined1)param_1;
  uVar12 = (undefined1)param_2;
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,8,0x30,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar11,uVar12);
    }
  }
  else {
    puVar1 = (undefined8 *)(param_1 + 0x298);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDDD
                (*puVar1,4,plVar8,0x31,puVar10,uVar11,uVar12,(char)local_28[0],(char)local_res20[0])
      ;
    }
    if ((*(uint *)(lVar3 + 0xc0) & 4) != 0) {
      uVar6 = 1L << ((byte)local_res20[0] & 0x3f);
      uVar4 = *(ulonglong *)(local_20 + 200);
      do {
        LOCK();
        uVar2 = *(ulonglong *)(local_20 + 200);
        bVar9 = uVar4 == uVar2;
        if (bVar9) {
          *(ulonglong *)(local_20 + 200) = uVar4 | uVar6;
        }
        else {
          uVar4 = uVar2;
        }
        UNLOCK();
      } while (!bVar9);
      uVar6 = uVar6 & uVar4;
      if (uVar6 == 0) {
        uVar5 = *(undefined4 *)(local_20 + 0x130);
      }
      else {
        uVar5 = 0xffffffff;
      }
      *param_3 = uVar5;
      uVar7 = -(uint)(uVar6 != 0) & 0x128;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar7;
      }
      WPP_RECORDER_SF_qDD(*puVar1,-uVar6,local_20,0x33,puVar10,uVar11,uVar12,(byte)local_res20[0]);
      return uVar7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*puVar1,2,8,0x32,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        (char)*(uint *)(lVar3 + 0xc0));
    }
  }
  return 0xc000000d;
}



===== GpiopScheduleDebounceTimers @ 14000c1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopScheduleDebounceTimers(ulonglong *param_1)

{
  ulonglong uVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int iVar10;
  longlong lVar11;
  
  if ((ushort)param_1[0x30] < 0x21) {
    LOCK();
    uVar9 = param_1[0x1e];
    *(uint *)(param_1 + 0x1e) = 0;
    UNLOCK();
    uVar9 = (ulonglong)(uint)uVar9;
  }
  else {
    LOCK();
    uVar9 = param_1[0x1e];
    param_1[0x1e] = 0;
    UNLOCK();
  }
  if (uVar9 != 0) {
    uVar1 = param_1[0x11];
    if (((*(byte *)(uVar1 + 0x314) & 1) == 0) || ((void *)param_1[9] != SystemReserved1[0xf])) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    uVar9 = uVar9 & param_1[0x28];
    while (uVar9 != 0) {
      iVar10 = 0;
      lVar11 = 0;
      uVar7 = 0;
      cVar3 = RtlFindLeastSignificantBit(uVar9);
      uVar9 = uVar9 & ~(1L << ((ulonglong)((int)cVar3 & 0xffff) & 0x3f));
      if (bVar2) {
        uVar6 = *param_1;
        if (uVar6 == 0) {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e0);
          uVar6 = param_1[3];
        }
        else {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x480);
        }
        (*pcVar5)(WdfDriverGlobals,uVar6);
        param_1[4] = (ulonglong)SystemReserved1[0xf];
      }
      uVar8 = (ulonglong)((int)cVar3 & 0xffff);
      lVar4 = GpiopGetPinEntryInternal((longlong)param_1,(short)cVar3,'\0');
      uVar6 = (ulonglong)*(uint *)(lVar4 + 0xc0);
      if ((*(uint *)(lVar4 + 0xc0) & 4) != 0) {
        uVar6 = *(ulonglong *)(lVar4 + 0x10);
        iVar10 = *(int *)(lVar4 + 0xd8);
        lVar11 = *(longlong *)(uVar6 + 0x18);
        uVar7 = *(ulonglong *)(*(longlong *)(lVar4 + 0x18) + 0x20);
      }
      if (bVar2) {
        uVar8 = *param_1;
        param_1[4] = 0;
        if (uVar8 == 0) {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e8);
          uVar8 = param_1[3];
        }
        else {
          pcVar5 = *(code **)(WdfFunctions_01015 + 0x488);
        }
        uVar6 = WdfDriverGlobals;
        (*pcVar5)();
      }
      if (lVar11 != 0) {
        if (uVar7 != 0) {
          uVar8 = 0;
          ExCancelTimer();
          uVar6 = uVar7;
        }
        if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
          McTemplateK0zhhh_EtwWriteTransfer
                    (uVar6,uVar8,param_1 + 0xe,*(wchar_t **)(uVar1 + 0x300),(char)param_1[0x10],
                     cVar3,(char)iVar10);
        }
        ExSetTimer(lVar11,(ulonglong)(uint)(iVar10 * 10) * -10,0,0);
      }
    }
  }
  return;
}



===== GpiopScheduleNoiseFilterTimers @ 14000c394 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopScheduleNoiseFilterTimers(longlong *param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  code *pcVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  
  lVar8 = 0;
  if (*(ushort *)(param_1 + 0x30) < 0x21) {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x1f);
    *(uint *)(param_1 + 0x1f) = 0;
    UNLOCK();
    uVar10 = (ulonglong)uVar1;
  }
  else {
    LOCK();
    uVar10 = param_1[0x1f];
    param_1[0x1f] = 0;
    UNLOCK();
  }
  if (uVar10 != 0) {
    if ((void *)param_1[4] == SystemReserved1[0xf]) {
      bVar3 = false;
    }
    else {
      lVar11 = *param_1;
      bVar3 = true;
      if (lVar11 == 0) {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar11 = param_1[3];
      }
      else {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar7)(WdfDriverGlobals,lVar11);
      param_1[4] = (longlong)SystemReserved1[0xf];
    }
    uVar10 = uVar10 & param_1[0x28];
    while (uVar10 != 0) {
      lVar11 = 0;
      lVar9 = 0;
      cVar4 = RtlFindLeastSignificantBit(uVar10);
      uVar10 = uVar10 & ~(1L << ((ulonglong)((int)cVar4 & 0xffff) & 0x3f));
      lVar6 = GpiopGetPinEntryInternal((longlong)param_1,(short)cVar4,'\0');
      if ((*(uint *)(lVar6 + 0xc0) & 4) != 0) {
        lVar8 = *(longlong *)(lVar6 + 0x18);
        lVar11 = *(longlong *)(lVar6 + 0xe0);
        lVar9 = *(longlong *)(lVar8 + 0x20);
      }
      iVar5 = 0;
      LOCK();
      iVar2 = *(int *)(lVar6 + 0x30);
      if (iVar2 == 0) {
        *(int *)(lVar6 + 0x30) = 0;
      }
      else {
        iVar5 = iVar2;
      }
      UNLOCK();
      if (bVar3) {
        lVar6 = *param_1;
        param_1[4] = 0;
        if (lVar6 == 0) {
          lVar6 = param_1[3];
          pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
        }
        else {
          pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
        }
        (*pcVar7)(WdfDriverGlobals,lVar6);
      }
      if (lVar9 != 0) {
        *(int *)(lVar8 + 0x18) = iVar5;
        ExSetTimer(lVar9,lVar11 * -10,0,0);
        if (bVar3) {
          lVar11 = *param_1;
          if (lVar11 == 0) {
            pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
            lVar11 = param_1[3];
          }
          else {
            pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
          }
          (*pcVar7)(WdfDriverGlobals,lVar11);
          param_1[4] = (longlong)SystemReserved1[0xf];
        }
      }
    }
    if (bVar3) {
      lVar8 = *param_1;
      param_1[4] = 0;
      if (lVar8 == 0) {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar8 = param_1[3];
      }
      else {
        pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar7)(WdfDriverGlobals,lVar8);
    }
  }
  return;
}



===== GpiopServiceActiveBothInterrupts @ 14000c5a4 =====

void GpiopServiceActiveBothInterrupts(ulonglong *param_1)

{
  ulonglong uVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  
  if ((ushort)param_1[0x30] < 0x21) {
    LOCK();
    uVar4 = param_1[0x21];
    *(uint *)(param_1 + 0x21) = 0;
    UNLOCK();
    uVar4 = (ulonglong)(uint)uVar4;
  }
  else {
    LOCK();
    uVar4 = param_1[0x21];
    param_1[0x21] = 0;
    UNLOCK();
  }
  if (uVar4 != 0) {
    uVar1 = param_1[0x11];
    for (uVar4 = uVar4 & param_1[0x28]; uVar4 != 0;
        uVar4 = uVar4 & ~(1L << ((ulonglong)((int)cVar2 & 0xffff) & 0x3f))) {
      cVar2 = RtlFindLeastSignificantBit(uVar4);
      puVar5 = (ulonglong *)0x0;
      lVar3 = GpiopGetPinEntryInternal((longlong)param_1,(short)cVar2,'\0');
      GpiopReconfigureInterrupts(param_1,(short)cVar2,puVar5);
      GpiopUnmaskInterrupt(uVar1,0,*(uint *)(lVar3 + 0x100));
    }
  }
  return;
}



===== GpiopSwitchDirectionPins @ 14000c664 =====

ulonglong GpiopSwitchDirectionPins
                    (longlong param_1,longlong param_2,longlong param_3,int param_4,char param_5)

{
  uint *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 *puVar6;
  undefined8 in_stack_ffffffffffffffb0;
  
  puVar1 = (uint *)(param_3 + 0x28);
  puVar2 = (undefined8 *)(param_3 + 0x20);
  pcVar5 = "input";
  if (param_5 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar4 = "input";
      if (param_4 != 1) {
        pcVar4 = "output";
      }
      WPP_RECORDER_SF_ssqqD
                (*(undefined8 *)(param_1 + 0x298),"output",param_3,0x70,in_stack_ffffffffffffffa8,
                 in_stack_ffffffffffffffb0,pcVar4,(char)param_1,(char)*puVar2,(char)*puVar1);
    }
    GpioUtilTracePrintPinNumbers(param_2,(undefined2 *)*puVar2,*puVar1);
  }
  if (*(int *)(param_3 + 0x1c) != 0) {
    GpiopDisconnectGpioPinsLocked(param_1,param_3,'\0','\x01');
  }
  puVar6 = (undefined8 *)(param_3 + 0x50);
  uVar3 = GpiopConnectGpioPinsLocked(param_1,param_2,param_3,param_4,puVar6);
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_ssqqDD(*(undefined8 *)(param_1 + 0x298));
    }
  }
  else if ((param_5 == '\0') &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    if (param_4 != 1) {
      pcVar5 = "output";
    }
    WPP_RECORDER_SF_ssqqD
              (*(undefined8 *)(param_1 + 0x298),param_2,param_3,0x72,puVar6,
               in_stack_ffffffffffffffb0,pcVar5,(char)param_1,(char)*puVar2,(char)*puVar1);
  }
  return uVar3 & 0xffffffff;
}



===== GpiopUnmaskInterrupt @ 14000c800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopUnmaskInterrupt(longlong param_1,uint param_2,uint param_3)

{
  undefined8 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  ulonglong ******ppppppuVar6;
  byte bVar7;
  int iVar8;
  longlong lVar9;
  code *pcVar10;
  undefined8 uVar11;
  int iVar12;
  uint uVar13;
  ulonglong uVar14;
  ulonglong *****pppppuVar15;
  ulonglong ******ppppppuVar16;
  ulonglong ******ppppppuVar17;
  bool bVar18;
  ushort *puVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  ushort local_48 [2];
  ushort local_44 [2];
  ulonglong ******local_40;
  
  puVar19 = local_48;
  local_44[0] = 0;
  uVar14 = (ulonglong)param_3;
  local_40 = (ulonglong ******)0x0;
  local_48[0] = 0;
  ppppppuVar17 = (ulonglong ******)&local_40;
  lVar9 = GpiopGetPinEntryFromVirq(param_1,param_3,(longlong *)ppppppuVar17,local_44,puVar19);
  uVar20 = (undefined1)param_1;
  uVar21 = (undefined1)param_3;
  if (lVar9 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,8,0x28,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar20,uVar21);
    }
  }
  else {
    puVar1 = (undefined8 *)(param_1 + 0x298);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDD(*puVar1,uVar14,ppppppuVar17,0x29,puVar19,uVar20,uVar21,(char)local_48[0]);
    }
    if ((*(uint *)(lVar9 + 0xc0) & 4) != 0) {
      LOCK();
      bVar18 = *(int *)(lVar9 + 0xc4) == 0;
      if (bVar18) {
        *(int *)(lVar9 + 0xc4) = 0;
      }
      UNLOCK();
      if (bVar18) {
        return 0;
      }
      LOCK();
      piVar2 = (int *)(lVar9 + 0xc4);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      iVar12 = iVar8 + -1;
      if (iVar12 != 0 && 0 < iVar8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        WPP_RECORDER_SF_qDDd
                  (*puVar1,uVar14,ppppppuVar17,0x2b,puVar19,uVar20,uVar21,(char)local_48[0],
                   (char)iVar12);
        return 0;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x314);
      bVar18 = true;
      bVar7 = KeGetCurrentIrql();
      if ((~(byte)uVar3 & 1) == 0) {
        bVar4 = bVar7 <= *(byte *)(param_1 + 6);
      }
      else {
        bVar4 = true;
        if (bVar7 != 0) {
          bVar4 = false;
        }
      }
      if (local_40[4] == SystemReserved1[0xf]) {
        bVar5 = false;
      }
      else {
        pppppuVar15 = *local_40;
        if (pppppuVar15 == (ulonglong *****)0x0) {
          pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e0);
          pppppuVar15 = local_40[3];
        }
        else {
          pcVar10 = *(code **)(WdfFunctions_01015 + 0x480);
        }
        (*pcVar10)(WdfDriverGlobals,pppppuVar15);
        bVar5 = true;
        local_40[4] = SystemReserved1[0xf];
      }
      ppppppuVar6 = local_40;
      if ((param_2 & 4) != 0) {
        if (*(ushort *)(local_40 + 0x30) < 0x21) {
          LOCK();
          *(uint *)(local_40 + 0x1a) =
               *(uint *)(local_40 + 0x1a) & ~(1 << ((byte)local_48[0] & 0x1f));
          UNLOCK();
        }
        else {
          LOCK();
          local_40[0x1a] =
               (ulonglong *****)((ulonglong)local_40[0x1a] & ~(1L << ((byte)local_48[0] & 0x3f)));
          UNLOCK();
        }
      }
      iVar12 = 0;
      LOCK();
      iVar8 = *(int *)(lVar9 + 0xc4);
      if (iVar8 == 0) {
        *(int *)(lVar9 + 0xc4) = 0;
      }
      else {
        iVar12 = iVar8;
      }
      UNLOCK();
      ppppppuVar16 = local_40;
      if (iVar8 == 0) {
        if (*(ushort *)(local_40 + 0x30) < 0x21) {
          LOCK();
          *(uint *)(local_40 + 0x16) =
               *(uint *)(local_40 + 0x16) & ~(1 << ((byte)local_48[0] & 0x1f));
          UNLOCK();
        }
        else {
          LOCK();
          local_40[0x16] =
               (ulonglong *****)((ulonglong)local_40[0x16] & ~(1L << ((byte)local_48[0] & 0x3f)));
          UNLOCK();
        }
        if (*(ushort *)(local_40 + 0x30) < 0x21) {
          uVar13 = 1 << ((byte)local_48[0] & 0x1f);
          ppppppuVar16 = (ulonglong ******)(ulonglong)uVar13;
          LOCK();
          *(uint *)(local_40 + 0x17) = *(uint *)(local_40 + 0x17) | uVar13;
          UNLOCK();
        }
        else {
          ppppppuVar16 = (ulonglong ******)(1L << ((byte)local_48[0] & 0x3f));
          LOCK();
          local_40[0x17] = (ulonglong *****)((ulonglong)local_40[0x17] | (ulonglong)ppppppuVar16);
          UNLOCK();
        }
        if (*(ushort *)(local_40 + 0x30) < 0x21) {
          LOCK();
          *(uint *)(local_40 + 0x29) =
               *(uint *)(local_40 + 0x29) & ~(1 << ((byte)local_48[0] & 0x1f));
          UNLOCK();
        }
        else {
          LOCK();
          local_40[0x29] =
               (ulonglong *****)((ulonglong)local_40[0x29] & ~(1L << ((byte)local_48[0] & 0x3f)));
          UNLOCK();
        }
        bVar18 = false;
        ppppppuVar17 = local_40;
      }
      if (bVar5) {
        local_40[4] = (ulonglong *****)0x0;
        ppppppuVar16 = (ulonglong ******)*local_40;
        if (ppppppuVar16 == (ulonglong ******)0x0) {
          pcVar10 = *(code **)(WdfFunctions_01015 + 0x9e8);
          ppppppuVar16 = (ulonglong ******)local_40[3];
        }
        else {
          pcVar10 = *(code **)(WdfFunctions_01015 + 0x488);
        }
        (*pcVar10)(WdfDriverGlobals);
      }
      if (bVar18) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qDDd
                    (*(undefined8 *)(param_1 + 0x298),ppppppuVar16,ppppppuVar17,0x2c,puVar19,uVar20,
                     uVar21,(char)local_48[0],(char)iVar12);
        }
        return 0;
      }
      if (!bVar4) {
        uVar11 = GpiopScheduleDeferredInterruptActivities
                           ((ulonglong *)ppppppuVar6,ppppppuVar16,(ulonglong *)ppppppuVar17);
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return (int)uVar11;
        }
        WPP_RECORDER_SF_qDDD
                  (*(undefined8 *)(param_1 + 0x298),4,ppppppuVar17,0x2d,puVar19,uVar20,uVar21,
                   (char)local_48[0],(char)uVar11);
        return (int)uVar11;
      }
      uVar11 = GpiopDeferredUnmaskRequestHandler((longlong *)ppppppuVar6);
      iVar8 = (int)uVar11;
      if (-1 < iVar8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar8;
        }
        WPP_RECORDER_SF_qDD(*(undefined8 *)(param_1 + 0x298),ppppppuVar16,ppppppuVar17,0x2f,puVar19,
                            uVar20,uVar21,(char)local_48[0]);
        return iVar8;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar8;
      }
      WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x2e,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar21,(char)uVar11);
      return iVar8;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*puVar1,2,8,0x2a,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        (char)*(uint *)(lVar9 + 0xc0));
    }
  }
  return -0x3ffffff3;
}



===== GpiopWaitForStateMachineCompletionOfDebouncedMaskedPin @ 14000cc38 =====

void GpiopWaitForStateMachineCompletionOfDebouncedMaskedPin
               (longlong param_1,longlong param_2,undefined2 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong local_30;
  undefined2 local_28;
  undefined4 local_26;
  undefined2 local_22;
  longlong local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_26 = 0;
  local_22 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_30 = param_1;
  local_28 = param_3;
  local_20 = param_2;
  GpiopDebounceAcquireLock(param_1,&local_30);
  if ((*(int *)(param_2 + 0x28) == 1) ||
     ((*(int *)(param_2 + 0x28) - 0x16U < 2 && (4 < *(byte *)(param_2 + 0x7c))))) {
    GpiopDebounceReleaseLock(param_1,&local_30);
  }
  else {
    puVar2 = &local_48;
    KeInitializeEvent(puVar2,1,0);
    *(undefined8 **)(param_2 + 0x80) = &local_48;
    GpiopDebounceReleaseLock(puVar2,&local_30);
    lVar1 = local_30;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqDsD(*(undefined8 *)(*(longlong *)(local_30 + 0x88) + 0x298));
    }
    KeWaitForSingleObject(&local_48,0,0,0,0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqDs(*(undefined8 *)(*(longlong *)(lVar1 + 0x88) + 0x298));
    }
  }
  return;
}



===== GpiopWritePins @ 14000cda0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopWritePins(longlong param_1,longlong param_2,ulonglong param_3,byte param_4,
                        longlong param_5,uint param_6,uint *param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  bool bVar5;
  int iVar6;
  code *pcVar7;
  longlong lVar8;
  longlong *plVar9;
  uint uVar10;
  byte bVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  ushort *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined8 in_stack_ffffffffffffff88;
  undefined1 uVar17;
  undefined1 uVar18;
  ulonglong local_48;
  
  bVar11 = param_4 & 1;
  bVar5 = false;
  puVar4 = *(undefined2 **)(param_2 + 0x20);
  iVar2 = *(int *)(param_2 + 0x1c);
  uVar3 = *(uint *)(param_2 + 0x28);
  uVar17 = (undefined1)param_1;
  if ((iVar2 != 2) && ((*(uint *)(param_2 + 100) & 1) == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),2,7,0x7b,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar17,(char)iVar2);
    }
    return 0xc000a125;
  }
  uVar18 = (undefined1)uVar3;
  if ((puVar4 == (undefined2 *)0x0) || (uVar3 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqD(*(undefined8 *)(param_1 + 0x298),0,param_3,0x7c,in_stack_ffffffffffffff88,
                          uVar17,(char)puVar4,uVar18);
    }
    return 0xc0000008;
  }
  if (param_6 < uVar3) {
    if (param_7 != (uint *)0x0) {
      *param_7 = uVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000023;
    }
    WPP_RECORDER_SF_qddD
              (*(undefined8 *)(param_1 + 0x298),0,param_3,0x7d,in_stack_ffffffffffffff88,uVar17,
               (char)(param_6 >> 3),(char)(uVar3 + 7 >> 3),uVar18);
    return 0xc0000023;
  }
  if (*(ushort *)(param_2 + 0x18) < *(ushort *)(param_1 + 0x2d8)) {
    plVar9 = (longlong *)
             ((ulonglong)*(ushort *)(param_2 + 0x18) * 400 + *(longlong *)(param_1 + 0x2e0));
  }
  else {
    plVar9 = (longlong *)0x0;
  }
  if (bVar11 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x298),0,param_3,0x7e,in_stack_ffffffffffffff88,
                         uVar17,(char)param_3);
    }
    param_3 = (ulonglong)uVar3;
    GpioUtilTracePrintPinNumbers(plVar9,puVar4,uVar3);
  }
  iVar6 = 0;
  LOCK();
  iVar1 = *(int *)(param_1 + 0x2d0);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x2d0) = 0;
  }
  else {
    iVar6 = iVar1;
  }
  UNLOCK();
  if (iVar6 != 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDd(*(undefined8 *)(param_1 + 0x298),2,param_3,0x7f,in_stack_ffffffffffffff88,
                          uVar17,uVar18,(char)*(undefined4 *)(param_1 + 0x2d0));
    }
    return 0xc0000001;
  }
  uVar16 = 0;
  puVar14 = *(ushort **)(param_2 + 0x20);
  uVar15 = 0;
  local_48 = 0;
  if ((*(uint *)(plVar9[0x11] + 0x314) & 4) != 0) {
    uVar10 = 0;
    if (uVar3 != 0) {
      uVar13 = 0;
      do {
        if ((*(byte *)((uVar13 >> 3) + param_5) & '\x01' << ((byte)uVar10 & 7)) == 0) {
          uVar16 = uVar16 | 1L << ((ulonglong)*puVar14 & 0x3f);
        }
        else {
          uVar15 = uVar15 | 1L << ((ulonglong)*puVar14 & 0x3f);
        }
        uVar10 = uVar10 + 1;
        uVar13 = uVar13 + 1;
        puVar14 = puVar14 + 1;
      } while (uVar10 < uVar3);
      local_48 = uVar15;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar9[6],0);
  plVar9[7] = (longlong)SystemReserved1[0xf];
  if (iVar2 != 2) {
    uVar15 = GpiopSwitchDirectionPins(param_1,(longlong)plVar9,param_2,2,bVar11);
    uVar13 = uVar15 & 0xffffffff;
    if ((int)uVar15 < 0) goto LAB_14000d209;
  }
  if ((-1 < (char)*(undefined4 *)(param_1 + 0x314)) && ((*(uint *)(plVar9[0x11] + 0x314) & 1) != 0))
  {
    lVar8 = *plVar9;
    if (lVar8 == 0) {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar8 = plVar9[3];
    }
    else {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar7)(WdfDriverGlobals,lVar8);
    plVar9[4] = (longlong)SystemReserved1[0xf];
  }
  uVar10 = GpioClnInvokeWritePins
                     ((longlong)plVar9,*(undefined8 *)(param_2 + 0x20),uVar3,param_5,local_48,uVar16
                      ,*(ulonglong *)(param_2 + 0x48));
  uVar13 = (ulonglong)uVar10;
  if ((-1 < (char)*(undefined4 *)(param_1 + 0x314)) && ((*(uint *)(plVar9[0x11] + 0x314) & 1) != 0))
  {
    lVar8 = *plVar9;
    plVar9[4] = 0;
    if (lVar8 == 0) {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x9e8);
      lVar8 = plVar9[3];
    }
    else {
      pcVar7 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    (*pcVar7)(WdfDriverGlobals,lVar8);
  }
  if ((int)uVar10 < 0) {
    bVar5 = true;
  }
  else {
    *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) | 4;
    if ((*(uint *)(param_2 + 100) & 2) != 0) {
      puVar14 = *(ushort **)(param_2 + 0x38);
      uVar15 = 0;
      if (*(int *)(param_2 + 0x40) != 0) {
        local_48._0_4_ = 0;
        do {
          lVar8 = GpiopGetPinEntryInternal((longlong)plVar9,puVar14[(uint)local_48],'\0');
          if (*(char *)(lVar8 + 0xd4) == '\0') {
            puVar14[uVar15] = puVar14[(uint)local_48];
            uVar15 = (ulonglong)((int)uVar15 + 1);
          }
          local_48._0_4_ = (uint)local_48 + 1;
        } while ((uint)local_48 < *(uint *)(param_2 + 0x40));
        if ((int)uVar15 != 0) {
          uVar16 = GpioClnInvokeConnectPins
                             ((longlong)plVar9,puVar14,(ushort)uVar15,2,
                              -(ulonglong)(*(longlong *)(param_2 + 0x58) != 0) &
                              *(longlong *)(param_2 + 0x58) + 8U);
          uVar13 = uVar16 & 0xffffffff;
          if ((int)uVar16 < 0) goto LAB_14000d209;
        }
      }
      *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) & 0xfffffffd;
      if ((int)uVar15 != 0) {
        do {
          lVar8 = GpiopGetPinEntryInternal((longlong)plVar9,*puVar14,'\0');
          puVar14 = puVar14 + 1;
          *(undefined1 *)(lVar8 + 0xd4) = 1;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
      }
    }
  }
LAB_14000d209:
  plVar9[7] = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,plVar9[6]);
  if ((int)uVar13 < 0) {
    if (bVar5) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar13;
      }
      uVar12 = 0x80;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar13;
      }
      uVar12 = 0x81;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,7,uVar12,
                      &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)uVar13);
  }
  else {
    if (bVar11 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqqD(*(undefined8 *)(param_1 + 0x298));
      }
      GpioUtilTracePrintPinNumbers(plVar9,puVar4,uVar3);
    }
    *param_7 = uVar3;
  }
  return uVar13;
}



===== McTemplateK0zhhh_EtwWriteTransfer @ 14000d33c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zhhh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (param_4 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_4c = 0;
  local_48 = &param_5;
  local_40 = 2;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_30 = 2;
  local_38 = &param_6;
  local_28 = &param_7;
  local_20 = 2;
  local_58 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&EVENT_DEBOUNCE_TIMER_START,param_3,5,local_68);
  return;
}



===== WPP_RECORDER_SF_DDDd @ 14000d3fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x14,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x14,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_DDq @ 14000d508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_Ddd @ 14000d600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_iD @ 14000d6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x57,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x57,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 14000d7c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDD @ 14000d8b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDDD @ 14000d9d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x1b,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x1b,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDDDDi @ 14000db10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDDDi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,8,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,0);
  return;
}



===== WPP_RECORDER_SF_qDDd @ 14000dc84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qDd @ 14000dd98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qdDD @ 14000de98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x78,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x78,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 14000dfac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0x17;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qddD @ 14000e0a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qddD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qiD @ 14000e1c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x56,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x56,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qid @ 14000e2b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qid(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x5a,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x5a,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 14000e3a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqD @ 14000e478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqD @ 14000e570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x82,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x82,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sDDD @ 14000e684 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDD
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar1
               ,lVar3,&param_7,4,&param_8,4,&param_9,4,0);
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
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar2,&param_7,4,&param_8,4,&param_9,4,0
                 );
  return;
}



===== WPP_RECORDER_SF_sDii @ 14000e850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDii(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0xb5,
               "GpiopInitializeBankPowerInformation",0x24,&uStack0000000000000038,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0xb5,
                  "GpiopInitializeBankPowerInformation",0x24,&uStack0000000000000038,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 14000e978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(void)

{
  undefined8 uVar1;
  undefined2 in_R9W;
  undefined1 uStack0000000000000038;
  
  uVar1 = GpioLogHandle;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,in_R9W,
               "GpiopInitializeRegistryOptions",0x1f,&uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,in_R9W,
                  "GpiopInitializeRegistryOptions",0x1f,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_siD @ 14000ea58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_siD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,4,0);
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
  WppAutoLogTrace(param_1,2,param_3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,param_6
                  ,lVar2,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sqDD @ 14000ec04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDD
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,4,&param_9,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  param_6,lVar2,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sqDDD @ 14000ede0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDDD
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,4,&param_9,4,&param_10,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  param_6,lVar2,&param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sqDDDD @ 14000efe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x3d,"GpiopFlipPinPolarity",0x15,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x3d,
                  "GpiopFlipPinPolarity",0x15,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_sqd @ 14000f154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar3,lVar2,&param_7,8,
               &param_8,4,0);
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
  WppAutoLogTrace(param_1,param_2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,param_6
                  ,lVar1,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sqdd @ 14000f2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqdd
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,4,&param_9,4,0);
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
  WppAutoLogTrace(param_1,2,param_3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,param_6
                  ,lVar2,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sqi @ 14000f4a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqi(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,8,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  param_6,lVar2,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_sqid @ 14000f650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqid
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,"GpiopConnectGpioPinsLocked"
               ,0x1b,&param_7,8,&param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  "GpiopConnectGpioPinsLocked",0x1b,&param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sqiiD @ 14000f774 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqiiD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,pcVar1,lVar3,&param_7,8,
               &param_8,8,&param_9,8,&param_10,4,0);
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
  WppAutoLogTrace(param_1,2,8,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,param_6,lVar2
                  ,&param_7,8,&param_8,8,&param_9,8,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sqq @ 14000f93c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0xcc,
               "GpiopValidateRegistrationPacketPhase2",0x26,&uStack0000000000000038,8,
               &uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0xcc,
                  "GpiopValidateRegistrationPacketPhase2",0x26,&uStack0000000000000038,8,
                  &uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_ssqqD @ 14000fa3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssqqD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,char *param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (param_7 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_7[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,"GpiopSwitchDirectionPins",
               0x19,pcVar1,lVar3,&param_8,8,&param_9,8,&param_10,4,0);
  }
  lVar3 = -1;
  if (param_7 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_7[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  WppAutoLogTrace(param_1,4,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,param_4,
                  "GpiopSwitchDirectionPins",0x19,param_7,lVar2,&param_8,8,&param_9,8,&param_10,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_ssqqDD @ 14000fc0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssqqDD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x71,"GpiopSwitchDirectionPins",0x19
               ,pcVar1,lVar3,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,7,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,0x71,
                  "GpiopSwitchDirectionPins",0x19,in_stack_00000038,lVar2,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== GpioHubDisableInterrupt @ 14000fe10 =====

int GpioHubDisableInterrupt(undefined8 param_1,uint param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar4 = GpioHubpFindGpioEntry(1,(ushort *)(ulonglong)param_2,(undefined8 *)0x0);
  if (puVar4 == (undefined8 *)0x0) {
    iVar3 = -0x3fff5edf;
  }
  else {
    piVar6 = (int *)puVar4[0xc];
    bVar2 = false;
    lVar1 = *(longlong *)(piVar6 + 0x1a);
    if (lVar1 != 0) {
      uVar7 = 0;
      if (*(uint *)(lVar1 + 4) != 0) {
        puVar5 = (uint *)(lVar1 + 0x10);
        do {
          if ((*(char *)((longlong)puVar5 + -7) == '\x02') && (param_2 == *puVar5)) {
            bVar2 = true;
            break;
          }
          uVar7 = uVar7 + 1;
          puVar5 = puVar5 + 8;
        } while (uVar7 < *(uint *)(lVar1 + 4));
      }
    }
    iVar3 = 0;
    LOCK();
    if (*piVar6 == 0) {
      *piVar6 = 0;
    }
    else {
      iVar3 = *piVar6;
    }
    UNLOCK();
    if ((bVar2) || (iVar3 != 1)) {
      iVar3 = GpiopDisableInterrupt((longlong)piVar6,param_2,iVar3 == 0);
    }
    else {
      local_38 = 1;
      uStack_30 = (ulonglong)param_2;
      local_28 = 0;
      uStack_20 = 0;
      local_18 = 0;
      iVar3 = GpiopForwardInterruptRequestToQueue((longlong)piVar6,&local_38);
    }
    GpioHubpRemoveVirqListEntry(piVar6,(ulonglong)param_2);
    GpioHubpReleaseGpioEntryShared((longlong)puVar4,'\x01');
  }
  return iVar3;
}



===== GpioHubMaskInterrupt @ 14000ff00 =====

int GpioHubMaskInterrupt(undefined8 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = GpioHubpFindGpioEntry(1,(ushort *)(ulonglong)param_3,(undefined8 *)0x0);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fff5edf;
  }
  else {
    iVar1 = GpiopMaskInterrupt(puVar2[0xc],(param_2 & 1) * 2,(ulonglong)param_3);
    GpioHubpReleaseGpioEntryShared((longlong)puVar2,'\x01');
  }
  return iVar1;
}



===== GpioHubQueryLineInformation @ 14000ff70 =====

undefined8
GpioHubQueryLineInformation(undefined8 param_1,int param_2,short *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = GpioHubVirqList;
  while( true ) {
    if ((undefined8 **)puVar2 == &GpioHubVirqList) {
      return 0xc000000d;
    }
    if (*(int *)(puVar2 + 2) == param_2) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  if (puVar2 == (undefined8 *)0x0) {
    return 0xc000000d;
  }
  uVar1 = GpioClxQueryPinInformation
                    (*(longlong *)(puVar2[3] + 0x60),param_2,puVar2 + 4,param_3,param_4);
  return uVar1;
}



===== GpioHubQueueEmergencyWorkItem @ 14000ffc8 =====

void GpioHubQueueEmergencyWorkItem(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  puVar5 = auStack_28;
  puVar3 = &GpioHubEmergencyWorkQueue;
  puVar4 = DAT_14001e668;
  if ((undefined8 *)*DAT_14001e668 != &GpioHubEmergencyWorkQueue) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar5 = auStack_20;
  }
  param_1[1] = puVar4;
  *param_1 = puVar3;
  *puVar4 = param_1;
  *(undefined8 *)(puVar5 + -8) = 0x140010032;
  DAT_14001e668 = param_1;
  KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
  *(undefined8 *)(puVar5 + -8) = 0x140010041;
  KeLowerIrql(uVar2);
  *(undefined8 *)(puVar5 + -8) = 0x140010059;
  KeSetEvent(&GpioHubEmergencyWorkEvent,0,0);
  return;
}



===== GpioHubRequestInterrupt @ 140010070 =====

uint GpioHubRequestInterrupt(undefined8 param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  
  puVar2 = GpioHubpFindGpioEntry(1,(ushort *)(ulonglong)param_2,(undefined8 *)0x0);
  if (puVar2 == (undefined8 *)0x0) {
    uVar1 = 0xc000a121;
  }
  else {
    uVar1 = GpiopRequestInterrupt(puVar2[0xc],param_2,param_3);
    if (uVar1 == 0) {
      if (*param_3 == -1) {
        GpioHubpInsertReplayList((longlong)puVar2);
      }
    }
    else if (uVar1 == 0x128) {
      uVar1 = 0;
    }
    GpioHubpReleaseGpioEntryShared((longlong)puVar2,'\x01');
  }
  return uVar1;
}



===== GpioHubUnmaskInterrupt @ 140010100 =====

int GpioHubUnmaskInterrupt(undefined8 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = GpioHubpFindGpioEntry(1,(ushort *)(ulonglong)param_3,(undefined8 *)0x0);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fff5edf;
  }
  else {
    iVar1 = GpiopUnmaskInterrupt(puVar2[0xc],(param_2 & 2) * 2,param_3);
    GpioHubpReleaseGpioEntryShared((longlong)puVar2,'\x01');
  }
  return iVar1;
}



===== GpioHubpAcquireGpioEntryExclusive @ 14001016c =====

int GpioHubpAcquireGpioEntryExclusive(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  
  LOCK();
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  UNLOCK();
  KeWaitForSingleObject(param_1 + 0x18,0,0,0,0);
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  while( true ) {
    iVar3 = 1;
    LOCK();
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 1) {
      *(int *)(param_1 + 0x10) = 2;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if (iVar1 == 1) break;
    KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
    KeLowerIrql(uVar2);
    KeWaitForSingleObject(param_1 + 0x18,0,0,0,0);
    uVar2 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  }
  LOCK();
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  UNLOCK();
  *param_2 = uVar2;
  return iVar3;
}



===== GpioHubpAddGpioEntry @ 140010264 =====

void GpioHubpAddGpioEntry(longlong param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  puVar6 = auStack_28;
  puVar3 = &GpioHubList;
  puVar5 = (undefined8 *)(param_1 + 0x50);
  puVar4 = DAT_14001e648;
  if ((undefined8 *)*DAT_14001e648 != &GpioHubList) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar6 = auStack_20;
  }
  *(undefined8 **)(param_1 + 0x58) = puVar4;
  *puVar5 = puVar3;
  *puVar4 = puVar5;
  *(undefined8 *)(puVar6 + -8) = 0x1400102d2;
  DAT_14001e648 = puVar5;
  KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
  *(undefined8 *)(puVar6 + -8) = 0x1400102e1;
  KeLowerIrql(uVar2);
  return;
}



===== GpioHubpCreateHubDeviceObject @ 1400102f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioHubpCreateHubDeviceObject(undefined8 param_1)

{
  int iVar1;
  code *pcVar2;
  longlong lVar3;
  longlong local_res10 [3];
  
  local_res10[0] =
       (**(code **)(WdfFunctions_01015 + 200))
                 (WdfDriverGlobals,param_1,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL);
  if (local_res10[0] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(GpioLogHandle,2,1,0x1a,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                        "GpioHubpCreateHubDeviceObject");
    }
    iVar1 = -0x3fffffff;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_res10[0],2);
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,local_res10,0,&GpioHubDevice);
    if (-1 < iVar1) {
      pcVar2 = *(code **)(WdfFunctions_01015 + 0xd8);
      lVar3 = GpioHubDevice;
      goto LAB_14001043f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(GpioLogHandle,2,2,0x1b,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                         "GpioHubpCreateHubDeviceObject",(char)iVar1);
    }
  }
  if (local_res10[0] == 0) {
    return iVar1;
  }
  pcVar2 = *(code **)(WdfFunctions_01015 + 0x1b0);
  lVar3 = local_res10[0];
LAB_14001043f:
  (*pcVar2)(WdfDriverGlobals,lVar3);
  return iVar1;
}



===== GpioHubpCreateVirqMapping @ 14001045c =====

undefined8 GpioHubpCreateVirqMapping(uint param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined4 in_register_0000000c;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined1 auStack_38 [32];
  
  uVar9 = 0;
  bVar3 = false;
  uVar4 = KfRaiseIrql(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),0xf));
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  puVar5 = GpioHubVirqList;
  do {
    if ((undefined8 **)puVar5 == &GpioHubVirqList) {
LAB_1400104d7:
      KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
      KeLowerIrql(uVar4);
      if (!bVar3) {
        puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x786c4347);
        if (puVar5 == (undefined8 *)0x0) {
          uVar9 = 0xc000009a;
        }
        else {
          puVar5[3] = param_2;
          *(uint *)(puVar5 + 2) = param_1;
          LOCK();
          puVar5[4] = 0xffff;
          UNLOCK();
          uVar4 = KfRaiseIrql(0xf);
          KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
          puVar7 = auStack_38;
          puVar8 = auStack_38;
          for (puVar6 = GpioHubVirqList; (undefined8 **)puVar6 != &GpioHubVirqList;
              puVar6 = (undefined8 *)*puVar6) {
            if (param_1 < *(uint *)(puVar6 + 2)) goto LAB_14001058a;
          }
          puVar7 = auStack_38;
          if ((undefined8 **)*DAT_14001e6c8 == &GpioHubVirqList) {
            *puVar5 = &GpioHubVirqList;
            puVar5[1] = DAT_14001e6c8;
            *DAT_14001e6c8 = puVar5;
            DAT_14001e6c8 = puVar5;
          }
          else {
            do {
              pcVar2 = (code *)swi(0x29);
              puVar6 = (undefined8 *)(*pcVar2)(3);
              puVar7 = puVar7 + 8;
LAB_14001058a:
              puVar1 = (undefined8 *)puVar6[1];
            } while ((undefined8 *)*puVar1 != puVar6);
            *puVar5 = puVar6;
            puVar5[1] = puVar1;
            *puVar1 = puVar5;
            puVar6[1] = puVar5;
            puVar8 = puVar7;
          }
          if (param_3 != (undefined8 *)0x0) {
            *param_3 = puVar5;
          }
          *(undefined8 *)(puVar8 + -8) = 0x1400105ca;
          KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
          *(undefined8 *)(puVar8 + -8) = 0x1400105d9;
          KeLowerIrql(uVar4);
        }
      }
      return uVar9;
    }
    if (*(uint *)(puVar5 + 2) == param_1) {
      puVar5[3] = param_2;
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar5;
      }
      bVar3 = true;
      goto LAB_1400104d7;
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== GpioHubpDeleteGpioEntry @ 140010608 =====

undefined8 GpioHubpDeleteGpioEntry(longlong ****param_1)

{
  longlong ****pppplVar1;
  int iVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  longlong *******ppppppplVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 local_res8 [8];
  longlong *******local_18;
  undefined8 uStack_10;
  
  uVar8 = 0;
  local_18 = (longlong *******)0x0;
  uStack_10 = 0;
  local_res8[0] = 0;
  iVar7 = 0;
  LOCK();
  iVar2 = *(int *)((longlong)param_1 + 0x14);
  if (iVar2 == 0) {
    *(int *)((longlong)param_1 + 0x14) = 0;
  }
  else {
    iVar7 = iVar2;
  }
  UNLOCK();
  if (iVar7 < 1) {
    GpioHubpAcquireGpioEntryExclusive((longlong)param_1,local_res8);
    pppplVar1 = param_1 + 10;
    ppplVar3 = *pppplVar1;
    if (((longlong ****)ppplVar3[1] != pppplVar1) ||
       (ppplVar4 = param_1[0xb], (longlong ****)*ppplVar4 != pppplVar1)) {
LAB_140010707:
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      uVar8 = (*pcVar6)();
      return uVar8;
    }
    *ppplVar4 = (longlong **)ppplVar3;
    ppplVar3[1] = (longlong **)ppplVar4;
    GpioHubpRemoveVirqListEntryListLocked('\0',(ulonglong)param_1,(longlong)&local_18);
    LOCK();
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + -1;
    UNLOCK();
    KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
    KeLowerIrql(local_res8[0]);
    KeSetEvent(param_1 + 3,0,0);
    while( true ) {
      ExFreePoolWithTag(param_1,0x786c4347);
      if ((longlong ********)local_18 == &local_18) break;
      if (((longlong ********)local_18[1] != &local_18) ||
         (ppppppplVar5 = (longlong *******)*local_18, (longlong *******)ppppppplVar5[1] != local_18)
         ) goto LAB_140010707;
      ppppppplVar5[1] = (longlong ******)&local_18;
      param_1 = (longlong ****)local_18;
      local_18 = ppppppplVar5;
    }
  }
  else {
    uVar8 = 0xc0000001;
  }
  return uVar8;
}



===== GpioHubpEmergencyWorkerThread @ 140010720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpEmergencyWorkerThread(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined *local_18;
  undefined *local_10;
  
  local_18 = &GpioHubEmergencyWorkEvent;
  local_10 = &GpioHubEmergencyTerminateEvent;
  do {
    iVar4 = KeWaitForMultipleObjects(2,&local_18,1,0,0,0,0,&DAT_14001e580);
    if (iVar4 == 1) {
      PsTerminateSystemThread(0);
    }
    do {
      while( true ) {
        uVar3 = KfRaiseIrql(0xf);
        KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
        puVar5 = GpioHubEmergencyWorkQueue;
        if ((undefined8 **)GpioHubEmergencyWorkQueue == &GpioHubEmergencyWorkQueue) {
          puVar5 = (undefined8 *)0x0;
        }
        else {
          if (((undefined8 **)GpioHubEmergencyWorkQueue[1] != &GpioHubEmergencyWorkQueue) ||
             (puVar1 = (undefined8 *)*GpioHubEmergencyWorkQueue,
             (undefined8 *)puVar1[1] != GpioHubEmergencyWorkQueue)) {
            pcVar2 = (code *)swi(0x29);
            (*pcVar2)(3);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          GpioHubEmergencyWorkQueue = puVar1;
          puVar1[1] = &GpioHubEmergencyWorkQueue;
        }
        KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
        KeLowerIrql(uVar3);
        if (puVar5 == (undefined8 *)0x0) break;
        *puVar5 = 0;
        (*(code *)puVar5[2])(puVar5[3]);
      }
      iVar4 = KeResetEvent(&GpioHubEmergencyWorkEvent);
    } while (iVar4 != 0);
  } while( true );
}



===== GpioHubpFindGpioEntry @ 140010854 =====

undefined8 * GpioHubpFindGpioEntry(int param_1,ushort *param_2,undefined8 *param_3)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 in_register_0000000c;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)0x0;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  uVar2 = KfRaiseIrql(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),0xf));
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  if (param_1 == 1) {
    for (puVar4 = GpioHubVirqList; (undefined8 **)puVar4 != &GpioHubVirqList;
        puVar4 = (undefined8 *)*puVar4) {
      if (*(int *)(puVar4 + 2) == (int)param_2) {
        if (puVar4 != (undefined8 *)0x0) {
          puVar5 = (undefined8 *)puVar4[3];
        }
        goto LAB_14001091c;
      }
    }
    puVar4 = (undefined8 *)0x0;
LAB_14001091c:
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = puVar4;
    }
LAB_140010924:
    if (puVar5 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(puVar5 + 2) = *(int *)(puVar5 + 2) + 1;
      UNLOCK();
    }
  }
  else if ((param_1 == 2) && ((undefined8 **)GpioHubList != &GpioHubList)) {
    uVar1 = *param_2;
    puVar4 = GpioHubList;
    do {
      if ((*(ushort *)puVar4[-9] == uVar1) &&
         (iVar3 = memcmp(*(void **)((ushort *)puVar4[-9] + 4),*(void **)(param_2 + 4),
                         (ulonglong)uVar1), iVar3 == 0)) {
        puVar5 = puVar4 + -10;
        goto LAB_140010924;
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &GpioHubList);
  }
  KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
  KeLowerIrql(uVar2);
  if ((puVar5 == (undefined8 *)0x0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_di();
  }
  return puVar5;
}



===== GpioHubpInsertReplayList @ 1400109ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpInsertReplayList(longlong param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubSignalReplayListLock);
  puVar6 = auStack_28;
  puVar5 = (undefined8 *)(param_1 + 0x40);
  puVar7 = auStack_28;
  if ((undefined8 *)*puVar5 == puVar5) {
    puVar3 = &GpioHubInterruptReplayList;
    puVar4 = DAT_14001e658;
    if ((undefined8 *)*DAT_14001e658 != &GpioHubInterruptReplayList) {
      puVar4 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar3 = (undefined8 *)(*pcVar1)();
      puVar6 = auStack_20;
    }
    *puVar5 = puVar3;
    *(undefined8 **)(param_1 + 0x48) = puVar4;
    *puVar4 = puVar5;
    puVar7 = puVar6;
    DAT_14001e658 = puVar5;
  }
  if (GpioHubDpcRunning == '\0') {
    GpioHubDpcRunning = '\x01';
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x380);
    *(undefined8 *)(puVar7 + -8) = 0x140010a42;
    (*pcVar1)(WdfDriverGlobals,GpioHubDpc);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140010a50;
  KeReleaseSpinLockFromDpcLevel(&GpioHubSignalReplayListLock);
  *(undefined8 *)(puVar7 + -8) = 0x140010a5f;
  KeLowerIrql(uVar2);
  return;
}



===== GpioHubpInsertSignalList @ 140010a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpInsertSignalList(longlong param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubSignalReplayListLock);
  puVar6 = auStack_28;
  puVar3 = &GpioHubSignalList;
  puVar5 = (undefined8 *)(param_1 + 0x30);
  puVar4 = DAT_14001e6b8;
  if ((undefined8 *)*DAT_14001e6b8 != &GpioHubSignalList) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar6 = auStack_20;
  }
  bVar7 = GpioHubDpcRunning == '\0';
  *puVar5 = puVar3;
  *(undefined8 **)(param_1 + 0x38) = puVar4;
  *puVar4 = puVar5;
  DAT_14001e6b8 = puVar5;
  if (bVar7) {
    GpioHubDpcRunning = '\x01';
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x380);
    *(undefined8 *)(puVar6 + -8) = 0x140010b09;
    (*pcVar1)(WdfDriverGlobals,GpioHubDpc);
  }
  *(undefined8 *)(puVar6 + -8) = 0x140010b17;
  KeReleaseSpinLockFromDpcLevel(&GpioHubSignalReplayListLock);
  *(undefined8 *)(puVar6 + -8) = 0x140010b26;
  KeLowerIrql(uVar2);
  return;
}



===== GpioHubpIsSecondaryInterrupt @ 140010b40 =====

bool GpioHubpIsSecondaryInterrupt(uint param_1)

{
  if (param_1 < DAT_14001e604) {
    return false;
  }
  return param_1 < DAT_14001e604 + DAT_14001e608;
}



===== GpioHubpProcessSignalReplayList @ 140010b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpProcessSignalReplayList(void)

{
  undefined8 *puVar1;
  ulonglong *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar5 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubSignalReplayListLock);
  puVar7 = auStack_28;
  while (puVar4 = GpioHubSignalList, (undefined8 **)GpioHubSignalList != &GpioHubSignalList) {
    if (((undefined8 **)GpioHubSignalList[1] != &GpioHubSignalList) ||
       (puVar1 = (undefined8 *)*GpioHubSignalList, (undefined8 *)puVar1[1] != GpioHubSignalList))
    goto LAB_140010d15;
    GpioHubSignalList = puVar1;
    puVar1[1] = &GpioHubSignalList;
    KeReleaseSpinLockFromDpcLevel(&GpioHubSignalReplayListLock);
    KeLowerIrql(uVar5);
    puVar4[1] = puVar4;
    *puVar4 = puVar4;
    KeSetEvent(puVar4 + -3,0,0);
    uVar5 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(&GpioHubSignalReplayListLock);
  }
  while (puVar4 = GpioHubInterruptReplayList,
        (undefined8 **)GpioHubInterruptReplayList != &GpioHubInterruptReplayList) {
    if (((undefined8 **)GpioHubInterruptReplayList[1] != &GpioHubInterruptReplayList) ||
       (puVar1 = (undefined8 *)*GpioHubInterruptReplayList,
       (undefined8 *)puVar1[1] != GpioHubInterruptReplayList)) goto LAB_140010d15;
    GpioHubInterruptReplayList = puVar1;
    puVar1[1] = &GpioHubInterruptReplayList;
    KeReleaseSpinLockFromDpcLevel(&GpioHubSignalReplayListLock);
    KeLowerIrql(uVar5);
    puVar4[1] = puVar4;
    *puVar4 = puVar4;
    puVar2 = *(ulonglong **)(puVar4[4] + 0x2e0);
    uVar6 = puVar2[3];
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
    GpiopInterruptBankIsr(puVar2,uVar6);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar2[3]);
    uVar5 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(&GpioHubSignalReplayListLock);
  }
LAB_140010d1c:
  GpioHubDpcRunning = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140010d2d;
  KeReleaseSpinLockFromDpcLevel(&GpioHubSignalReplayListLock);
  *(undefined8 *)(puVar7 + -8) = 0x140010d3c;
  KeLowerIrql(uVar5);
  return;
LAB_140010d15:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar7 = auStack_20;
  goto LAB_140010d1c;
}



===== GpioHubpReleaseGpioEntryShared @ 140010d60 =====

void GpioHubpReleaseGpioEntryShared(longlong param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((param_2 != '\0') && (iVar2 == 2)) {
    iVar4 = 0;
    LOCK();
    iVar2 = *(int *)(param_1 + 0x14);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x14) = 0;
    }
    else {
      iVar4 = iVar2;
    }
    UNLOCK();
    if (iVar4 != 0) {
      bVar3 = KeGetCurrentIrql();
      if (bVar3 < 3) {
        KeSetEvent(param_1 + 0x18,0,0);
      }
      else {
        GpioHubpInsertSignalList(param_1);
      }
    }
  }
  return;
}



===== GpioHubpRemoveVirqListEntry @ 140010dc8 =====

void GpioHubpRemoveVirqListEntry(undefined8 param_1,ulonglong param_2)

{
  longlong ***ppplVar1;
  code *pcVar2;
  longlong ****pppplVar3;
  undefined1 uVar4;
  longlong ****local_18;
  undefined8 uStack_10;
  
  local_18 = (longlong ****)0x0;
  uStack_10 = 0;
  uVar4 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  GpioHubpRemoveVirqListEntryListLocked('\x01',param_2,(longlong)&local_18);
  KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
  KeLowerIrql(uVar4);
  pppplVar3 = local_18;
  if ((longlong *****)local_18 != &local_18) {
    ppplVar1 = *local_18;
    if (((longlong *****)local_18[1] != &local_18) || ((longlong ****)ppplVar1[1] != local_18)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    ppplVar1[1] = (longlong **)&local_18;
    local_18 = (longlong ****)ppplVar1;
    ExFreePoolWithTag(pppplVar3,0x786c4347);
  }
  return;
}



===== GpioHubpRemoveVirqListEntryListLocked @ 140010e8c =====

void GpioHubpRemoveVirqListEntryListLocked(char param_1,ulonglong param_2,longlong param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  *(longlong *)(param_3 + 8) = param_3;
  *(longlong *)param_3 = param_3;
  plVar1 = GpioHubVirqList;
  do {
    while( true ) {
      plVar5 = plVar1;
      if ((longlong **)plVar5 == &GpioHubVirqList) {
        return;
      }
      plVar1 = (longlong *)*plVar5;
      if (param_1 != '\0') break;
      if (plVar5[3] == param_2) {
        if (((longlong *)plVar1[1] != plVar5) ||
           (puVar2 = (undefined8 *)plVar5[1], (longlong *)*puVar2 != plVar5)) goto LAB_140010f3e;
        *puVar2 = plVar1;
        plVar1[1] = (longlong)puVar2;
        plVar3 = *(longlong **)(param_3 + 8);
        if (*plVar3 != param_3) goto LAB_140010f3e;
        *plVar5 = param_3;
        plVar5[1] = (longlong)plVar3;
        *plVar3 = (longlong)plVar5;
        *(longlong **)(param_3 + 8) = plVar5;
      }
    }
  } while (*(uint *)(plVar5 + 2) != param_2);
  plVar5[3] = 0;
  if (((longlong *)plVar1[1] == plVar5) &&
     (puVar2 = (undefined8 *)plVar5[1], (longlong *)*puVar2 == plVar5)) {
    *puVar2 = plVar1;
    plVar1[1] = (longlong)puVar2;
    plVar1 = *(longlong **)(param_3 + 8);
    if (*plVar1 == param_3) {
      *plVar5 = param_3;
      plVar5[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar5;
      *(longlong **)(param_3 + 8) = plVar5;
      return;
    }
  }
LAB_140010f3e:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== GpioHubpUninitialize @ 140010f4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpUninitialize(void)

{
  longlong ****pppplVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong ****pppplVar4;
  undefined1 *puVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong ****local_28;
  longlong ****local_20;
  longlong ****local_18;
  longlong ****local_10;
  
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  GpioHubpUnregisterSecondaryInterruptInterface();
  if (GpioHubResourceHubTarget != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,GpioHubResourceHubTarget);
    GpioHubResourceHubTarget = 0;
  }
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  local_20 = (longlong ****)&local_28;
  local_28 = (longlong ****)&local_28;
  uVar3 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(&GpioHubListSpinLock);
  pppplVar1 = local_10;
  if ((longlong ****)GpioHubList == &GpioHubList) {
LAB_1400110bb:
    pppplVar1 = local_20;
    if ((longlong ****)GpioHubVirqList == &GpioHubVirqList) {
LAB_14001115a:
      KeReleaseSpinLockFromDpcLevel(&GpioHubListSpinLock);
      KeLowerIrql(uVar3);
      while (pppplVar1 = local_28, (longlong *****)local_28 != &local_28) {
        if (((longlong *****)local_28[1] != &local_28) ||
           (pppplVar4 = (longlong ****)*local_28, (longlong ****)pppplVar4[1] != local_28))
        goto LAB_1400111fc;
        pppplVar4[1] = (longlong ***)&local_28;
        local_28 = pppplVar4;
        ExFreePoolWithTag(pppplVar1,0x786c4347);
      }
      while( true ) {
        puVar5 = auStack_48;
        if ((longlong *****)local_18 == &local_18) break;
        if (((longlong *****)local_18[1] != &local_18) ||
           (pppplVar1 = (longlong ****)*local_18, (longlong ****)pppplVar1[1] != local_18))
        goto LAB_1400111fc;
        pppplVar1[1] = (longlong ***)&local_18;
        pppplVar4 = local_18 + -10;
        local_18 = pppplVar1;
        ExFreePoolWithTag(pppplVar4,0x786c4347);
      }
      goto LAB_140011203;
    }
    if ((((longlong *****)local_28[1] == &local_28) && ((longlong *****)*local_20 == &local_28)) &&
       (((longlong ****)GpioHubVirqList[1] == &GpioHubVirqList &&
        ((longlong ****)*DAT_14001e6c8 == &GpioHubVirqList)))) {
      *local_20 = (longlong ***)&GpioHubVirqList;
      local_20 = DAT_14001e6c8;
      *DAT_14001e6c8 = (longlong ***)&local_28;
      DAT_14001e6c8 = pppplVar1;
      if (((longlong ****)GpioHubVirqList[1] == &GpioHubVirqList) &&
         ((longlong ****)*pppplVar1 == &GpioHubVirqList)) {
        *pppplVar1 = GpioHubVirqList;
        GpioHubVirqList[1] = (longlong **)pppplVar1;
        DAT_14001e6c8 = &GpioHubVirqList;
        GpioHubVirqList = (longlong ***)&GpioHubVirqList;
        goto LAB_14001115a;
      }
    }
  }
  else if (((((longlong *****)local_18[1] == &local_18) && ((longlong *****)*local_10 == &local_18))
           && ((longlong ****)GpioHubList[1] == &GpioHubList)) &&
          ((longlong ****)*DAT_14001e648 == &GpioHubList)) {
    *local_10 = (longlong ***)&GpioHubList;
    local_10 = DAT_14001e648;
    *DAT_14001e648 = (longlong ***)&local_18;
    DAT_14001e648 = pppplVar1;
    if (((longlong ****)GpioHubList[1] == &GpioHubList) &&
       ((longlong ****)*pppplVar1 == &GpioHubList)) {
      *pppplVar1 = GpioHubList;
      GpioHubList[1] = (longlong **)pppplVar1;
      DAT_14001e648 = &GpioHubList;
      GpioHubList = (longlong ***)&GpioHubList;
      goto LAB_1400110bb;
    }
  }
LAB_1400111fc:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar5 = auStack_40;
LAB_140011203:
  if (GpioHubDpc != 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
    *(undefined8 *)(puVar5 + -8) = 0x140011229;
    (*pcVar2)(WdfDriverGlobals);
    GpioHubDpc = 0;
  }
  GpioHubDevice = 0;
  return;
}



===== WPP_RECORDER_SF_DSD @ 14001124c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DSD(void)

{
  undefined8 uVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 in_R9W;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = GpioLogHandle;
  lVar5 = -1;
  lVar4 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000038[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,in_R9W,&uStack0000000000000030,4,
               pwVar3,lVar2,&uStack0000000000000040,4,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000038[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(uVar1,2,8,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,in_R9W,
                  &uStack0000000000000030,4,in_stack_00000038,lVar4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DSq @ 1400113c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DSq(void)

{
  undefined8 uVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000040;
  
  uVar1 = GpioLogHandle;
  lVar5 = -1;
  lVar4 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000038[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0xd,&uStack0000000000000030,4,pwVar3
               ,lVar2,&uStack0000000000000040,8,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000038[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(uVar1,4,8,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0xd,
                  &uStack0000000000000030,4,in_stack_00000038,lVar4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_di @ 14001154c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_di(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  uVar1 = GpioLogHandle;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0x1e,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(uVar1,2,8,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0x1e,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_sDSD @ 140011624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDSD(void)

{
  undefined8 uVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 in_R9W;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  uVar1 = GpioLogHandle;
  lVar5 = -1;
  lVar4 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000040[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,in_R9W,
               "GpioHubQueryPrimaryInterruptInformation",0x28,&uStack0000000000000038,4,pwVar3,lVar2
               ,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000040 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000040[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  WppAutoLogTrace(uVar1,2,8,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,in_R9W,
                  "GpioHubQueryPrimaryInterruptInformation",0x28,&uStack0000000000000038,4,
                  in_stack_00000040,lVar4,&uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sDSq @ 1400117d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDSq(void)

{
  undefined8 uVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uStack0000000000000038;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  uVar1 = GpioLogHandle;
  lVar5 = -1;
  lVar4 = 10;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000040[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000040;
    if (in_stack_00000040 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0x12,
               "GpioHubQueryPrimaryInterruptInformation",0x28,&uStack0000000000000038,4,pwVar3,lVar2
               ,&uStack0000000000000048,8,0);
  }
  if (in_stack_00000040 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000040[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  WppAutoLogTrace(uVar1,4,8,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,0x12,
                  "GpioHubQueryPrimaryInterruptInformation",0x28,&uStack0000000000000038,4,
                  in_stack_00000040,lVar4,&uStack0000000000000048,8,0);
  return;
}



===== GpiopDebounceInterruptEngine @ 14001198c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpiopDebounceInterruptEngine
              (ulonglong *param_1,ulonglong *param_2,int param_3,undefined8 *param_4,
              undefined1 *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  undefined1 uVar11;
  ulonglong *puVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = param_5;
  local_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_4 != (undefined8 *)0x0) {
    local_58 = *param_4;
    uStack_50 = param_4[1];
  }
  uVar11 = 1;
  if (((*param_1 & 0x100000000) == 0) || (param_3 - 4U < 2)) {
    bVar4 = true;
    GpiopDebounceAcquireLock(param_1,(longlong *)param_2);
  }
  else {
    bVar4 = false;
  }
  do {
    puVar12 = &local_60;
    puVar10 = param_1;
    iVar6 = GpiopDebounceStateMachineTransition
                      ((int *)param_1,param_3,(int *)puVar12,(undefined4 *)&local_78);
    if ((int)local_78 < 6) {
      if ((int)local_78 == 5) {
        if ((*param_1 & 0x100000000) == 0) {
          GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
        }
        puVar10 = (ulonglong *)*param_2;
        if (*(char *)((longlong)param_2 + 0x1c) == '\0') {
          puVar10 = (ulonglong *)puVar10[0x11];
          GpiopMaskInterrupt((longlong)puVar10,0,(ulonglong)(uint)param_1[0x1b]);
        }
        else {
          GpiopIncrementMaskCount((longlong *)puVar10,(longlong)(param_1 + -5),(byte)param_2[1]);
        }
LAB_140011c3e:
        local_60 = 1;
LAB_140011c42:
        if ((*param_1 & 0x100000000) == 0) {
          GpiopDebounceAcquireLock(puVar10,(longlong *)param_2);
        }
      }
      else if ((int)local_78 != 0) {
        if ((int)local_78 == 1) {
          uVar3 = *param_2;
          puVar10 = (ulonglong *)(ulonglong)(ushort)param_2[1];
          bVar5 = (byte)param_2[1];
          if (*(ushort *)(uVar3 + 0x180) < 0x21) {
            LOCK();
            *(uint *)(uVar3 + 0xe8) = *(uint *)(uVar3 + 0xe8) | 1 << (bVar5 & 0x1f);
            UNLOCK();
          }
          else {
            LOCK();
            *(ulonglong *)(uVar3 + 0xe8) = *(ulonglong *)(uVar3 + 0xe8) | 1L << (bVar5 & 0x3f);
            UNLOCK();
          }
          if (*(ushort *)(uVar3 + 0x180) < 0x21) {
            LOCK();
            *(uint *)(uVar3 + 0xf0) = *(uint *)(uVar3 + 0xf0) | 1 << (bVar5 & 0x1f);
            UNLOCK();
          }
          else {
            LOCK();
            *(ulonglong *)(uVar3 + 0xf0) = *(ulonglong *)(uVar3 + 0xf0) | 1L << (bVar5 & 0x3f);
            UNLOCK();
          }
          *(undefined1 *)((longlong)param_2 + 0x1d) = 1;
        }
        else if ((int)local_78 == 2) {
          uVar3 = *param_2;
          uVar9 = param_1[-2];
          uVar2 = param_2[1];
          puVar10 = (ulonglong *)(ulonglong)(ushort)uVar2;
          *(undefined8 *)(uVar9 + 0x30) = local_78;
          *(undefined8 *)(uVar9 + 0x38) = uStack_70;
          bVar5 = (byte)uVar2;
          if (*(ushort *)(uVar3 + 0x180) < 0x21) {
            LOCK();
            *(uint *)(uVar3 + 0xf8) = *(uint *)(uVar3 + 0xf8) | 1 << (bVar5 & 0x1f);
            UNLOCK();
          }
          else {
            LOCK();
            *(ulonglong *)(uVar3 + 0xf8) = *(ulonglong *)(uVar3 + 0xf8) | 1L << (bVar5 & 0x3f);
            UNLOCK();
          }
          *(undefined1 *)((longlong)param_2 + 0x1e) = 1;
        }
        else if ((int)local_78 == 3) {
          if ((*param_1 & 0x100000000) == 0) {
            GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
          }
          if ((((byte)*(undefined4 *)((longlong)param_1 + 4) & 0xe) == 2) &&
             (*(int *)((longlong)param_1 + 0xc4) == 1)) {
            *(undefined1 *)((longlong)param_2 + 0x1f) = 1;
          }
          else {
            GpiopInvokeTargetIsr(*param_2,1L << ((byte)param_2[1] & 0x3f));
          }
          puVar10 = param_2;
          GpiopServiceInterruptOnPin(param_2,7,2);
          *(undefined1 *)((longlong)param_1 + 0x91) = 1;
          if ((*param_1 & 0x100000000) == 0) {
            GpiopDebounceAcquireLock(puVar10,(longlong *)param_2);
          }
        }
        else {
          if ((int)local_78 != 4) goto LAB_140011d88;
          uVar3 = *param_2;
          puVar10 = (ulonglong *)(ulonglong)(ushort)param_2[1];
          bVar5 = (byte)param_2[1];
          if (*(ushort *)(uVar3 + 0x180) < 0x21) {
            uVar7 = *(uint *)(uVar3 + 0xf8);
            do {
              LOCK();
              uVar1 = *(uint *)(uVar3 + 0xf8);
              bVar13 = uVar7 == uVar1;
              if (bVar13) {
                *(uint *)(uVar3 + 0xf8) = uVar7 & ~(1 << (bVar5 & 0x1f));
              }
              else {
                uVar7 = uVar1;
              }
              UNLOCK();
            } while (!bVar13);
            uVar9 = (ulonglong)uVar7;
          }
          else {
            uVar9 = *(ulonglong *)(uVar3 + 0xf8);
            do {
              LOCK();
              uVar2 = *(ulonglong *)(uVar3 + 0xf8);
              bVar13 = uVar9 == uVar2;
              if (bVar13) {
                *(ulonglong *)(uVar3 + 0xf8) = uVar9 & ~(1L << (bVar5 & 0x3f));
              }
              else {
                uVar9 = uVar2;
              }
              UNLOCK();
            } while (!bVar13);
          }
          if (((uVar9 >> ((ulonglong)puVar10 & 0x3f) & 1) == 0) &&
             (bVar5 = KeGetCurrentIrql(), bVar5 < 3)) {
            puVar10 = *(ulonglong **)(param_1[-2] + 0x20);
            ExCancelTimer(puVar10,0);
          }
        }
LAB_140011bf7:
        local_60 = 1;
      }
    }
    else {
      if ((int)local_78 != 6) {
        if ((int)local_78 == 7) {
          if ((*param_1 & 0x100000000) == 0) {
            GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
          }
          puVar10 = (ulonglong *)*param_2;
          iVar8 = GpiopReconfigureInterrupts(puVar10,(short)param_2[1],puVar12);
          local_60 = CONCAT44(iVar8,1);
          goto LAB_140011c42;
        }
        if ((int)local_78 == 8) {
          if ((*param_1 & 0x100000000) == 0) {
            GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
          }
          if ((((param_1[0x13] & 0x100) != 0) || (*(char *)((longlong)param_1 + 0x91) == '\0')) &&
             ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0)) {
            McTemplateK0hq_EtwWriteTransfer
                      (puVar10,&EVENT_SPURIOUS_INTERRUPT_DETECTED,*param_2 + 0x70,(short)param_2[1],
                       (char)param_1[0x1b]);
          }
          *(undefined1 *)((longlong)param_1 + 0x91) = 0;
          puVar10 = param_2;
          GpiopServiceInterruptOnPin(param_2,7,3);
          goto LAB_140011c3e;
        }
        if ((int)local_78 == 9) {
          *(int *)((longlong)param_1 + 0xc) = (int)param_2[3];
          goto LAB_140011bf7;
        }
LAB_140011d88:
        iVar6 = -0x3fffffff;
        break;
      }
      if ((*param_1 & 0x100000000) == 0) {
        GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
      }
      uVar3 = *param_2;
      GpiopServiceInterruptOnPin(param_2,7,4);
      puVar10 = *(ulonglong **)(uVar3 + 0x88);
      iVar8 = GpiopUnmaskInterrupt((longlong)puVar10,0,(uint)param_1[0x1b]);
      local_60 = CONCAT44(iVar8,1);
      if ((*param_1 & 0x100000000) == 0) {
        GpiopDebounceAcquireLock(puVar10,(longlong *)param_2);
      }
    }
    local_58 = local_78;
    uStack_50 = uStack_70;
  } while (iVar6 == -0x3fffffea);
  if (((int)*param_1 != 1) &&
     ((1 < (int)*param_1 - 0x16U || (*(byte *)((longlong)param_1 + 0x54) < 5)))) {
    uVar11 = 0;
  }
  *local_68 = uVar11;
  if (bVar4) {
    GpiopDebounceReleaseLock(puVar10,(longlong *)param_2);
  }
  return iVar6;
}



===== GpiopDebounceSignalStateMachineCompletion @ 140011de8 =====

void GpiopDebounceSignalStateMachineCompletion(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = param_1;
  GpiopDebounceAcquireLock(param_1,param_2);
  lVar1 = *(longlong *)(param_1 + 0x58);
  *(undefined8 *)(param_1 + 0x58) = 0;
  GpiopDebounceReleaseLock(lVar2,param_2);
  if (lVar1 != 0) {
    KeSetEvent(lVar1,0,0);
  }
  return;
}



===== GpiopDebounceStateMachineTransition @ 140011e44 =====

undefined4
GpiopDebounceStateMachineTransition(int *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  bool bVar13;
  
  iVar7 = *param_1;
  uVar9 = (uint)param_1[1] >> 1 & 7;
  iVar11 = *param_3;
  iVar1 = param_3[1];
  iVar6 = iVar7;
  if ((char)param_3[3] != '\0') {
    iVar6 = 0xf;
  }
  uVar12 = 0;
  uVar8 = 0;
  iVar10 = -0x3fffffea;
  uVar4 = 0;
  do {
    iVar2 = iVar10;
    if (iVar6 < 0xd) {
      if (iVar6 == 0xc) {
LAB_140012125:
        iVar7 = 2;
        LOCK();
        param_1[2] = param_1[2] + 1;
        UNLOCK();
        if (iVar6 != 0xc) {
          if (iVar6 != 0xd) {
            iVar7 = *param_1;
LAB_1400121ac:
            uVar8 = 0xc0000001;
            bVar13 = iVar7 != 0;
            iVar7 = iVar6;
            iVar2 = -0x3fffffff;
            if (bVar13) {
              *param_1 = 1;
            }
            goto LAB_1400122c4;
          }
          iVar7 = 7;
        }
LAB_140012091:
      }
      else if (iVar6 < 7) {
        if (iVar6 != 6) {
          if (iVar6 != 0) {
            if (iVar6 == 1) {
              iVar7 = 0xc;
            }
            else {
              if (iVar6 == 2) goto LAB_140012297;
              if (iVar6 == 3) {
                if (iVar11 == 0) {
                  uVar12 = 1;
                  goto LAB_1400122a0;
                }
                iVar7 = iVar6;
                if (iVar11 == 1) {
                  if (uVar9 == 1) goto LAB_140011f35;
                  goto LAB_140011f3f;
                }
              }
              else if (iVar6 == 4) {
                iVar7 = 10 - (uint)(uVar9 != 1);
              }
              else {
                if (iVar6 != 5) goto LAB_1400121ac;
                uVar8 = 0;
                uVar12 = 2;
                uVar4 = 1;
                iVar7 = 6;
                iVar2 = 0;
              }
            }
            goto LAB_1400122c4;
          }
          goto LAB_1400121ac;
        }
        if (param_2 == 5) {
          iVar6 = 0xe;
        }
        else if (param_2 == 3) {
          iVar6 = 0xd;
        }
LAB_1400122c1:
        iVar11 = 0;
        iVar7 = iVar6;
      }
      else {
        if (iVar6 == 7) {
          if (iVar11 != 0) {
            iVar7 = iVar6;
            if (iVar11 != 1) goto LAB_1400122c4;
            iVar6 = 0x10;
            goto LAB_1400122c1;
          }
          uVar12 = 4;
        }
        else {
          if (iVar6 != 8) {
            if (iVar6 == 9) goto LAB_14001221e;
            if (iVar6 == 10) goto LAB_1400121f2;
            if (iVar6 != 0xb) goto LAB_1400121ac;
            if (param_2 == 3) {
              iVar7 = 6;
              goto LAB_140012091;
            }
            if (iVar11 != 1) {
              uVar4 = 1;
              goto LAB_140011f44;
            }
            iVar6 = 5;
            goto LAB_1400122c1;
          }
          if (iVar11 != 0) {
            iVar7 = iVar6;
            if (iVar11 == 1) {
              iVar11 = 0;
              if (param_2 == 3) {
LAB_140011f3f:
                iVar11 = 0;
                iVar6 = 4;
                goto LAB_140011f44;
              }
              iVar7 = (param_2 != 4) + 0x11;
            }
            goto LAB_1400122c4;
          }
          uVar12 = 3;
        }
LAB_1400122a0:
        uVar8 = 0xc0000016;
LAB_1400122a5:
        iVar7 = iVar6;
        iVar2 = 0;
      }
    }
    else if (iVar6 < 0x13) {
      if (iVar6 == 0x12) {
        uVar5 = param_1[1] & 0x10;
        iVar7 = (-(uint)(uVar5 != 0) & 0xffffffee) + 0x13;
        uVar3 = 0;
        if (uVar5 == 0) {
          uVar3 = uVar8;
        }
        uVar8 = uVar3;
        iVar2 = 0;
        if (uVar5 == 0) {
          iVar2 = iVar10;
        }
      }
      else {
        if (iVar6 == 0xd) goto LAB_140012125;
        if (iVar6 == 0xe) {
          if (iVar11 == 0) {
            uVar12 = 9;
            goto LAB_1400122a0;
          }
          iVar7 = iVar6;
          if (iVar11 == 1) {
            iVar11 = 0;
            iVar7 = 0;
            LOCK();
            iVar6 = param_1[2];
            if (iVar6 == 0) {
              param_1[2] = 0;
            }
            else {
              iVar7 = iVar6;
            }
            UNLOCK();
            if (iVar7 != param_1[3]) {
              iVar6 = *param_1;
              goto LAB_140011f44;
            }
LAB_140011f35:
            iVar11 = 0;
            iVar7 = 8;
          }
        }
        else if (iVar6 == 0xf) {
          iVar7 = 0;
          LOCK();
          iVar6 = param_1[2];
          if (iVar6 == 0) {
            param_1[2] = 0;
          }
          else {
            iVar7 = iVar6;
          }
          UNLOCK();
          if (param_3[5] != iVar7) {
            uVar8 = 0;
            iVar10 = 0;
          }
          iVar7 = *param_1;
          iVar2 = iVar10;
        }
        else {
          if (iVar6 != 0x10) {
            if (iVar6 == 0x11) {
              uVar9 = param_1[1];
              if ((uVar9 & 0x20) == 0) {
                uVar9 = uVar9 & 0xfffffff7 | 6;
              }
              else {
                uVar9 = uVar9 & 0xfffffff3 | 2;
              }
              param_1[1] = uVar9;
              iVar7 = 10;
              uVar9 = uVar9 >> 1 & 7;
              goto LAB_140012091;
            }
            goto LAB_1400121ac;
          }
          if (iVar11 == 0) {
            uVar12 = 8;
            goto LAB_1400122a0;
          }
          iVar7 = iVar6;
          if (iVar11 == 1) {
            iVar6 = 0x13;
            goto LAB_1400122c1;
          }
        }
      }
    }
    else if (iVar6 == 0x13) {
LAB_140012297:
      if (iVar11 == 0) {
        uVar12 = 5;
        goto LAB_1400122a0;
      }
      iVar7 = iVar6;
      if (iVar11 == 1) {
        bVar13 = iVar6 == 2;
        iVar6 = 0x14;
        if (bVar13) {
          iVar6 = 3;
        }
        goto LAB_1400122c1;
      }
    }
    else {
      if (iVar6 != 0x14) {
        if (iVar6 == 0x15) {
LAB_1400121f2:
          uVar12 = 6;
          if ((uVar9 != 1) && (iVar6 != 0x15)) {
            iVar6 = 0xb;
            uVar4 = 1;
            goto LAB_1400122a0;
          }
          iVar6 = 1;
        }
        else {
          if ((iVar6 != 0x16) && (iVar6 != 0x17)) goto LAB_1400121ac;
          if ((param_1[1] & 0x20U) == 0) {
            iVar7 = 0x14;
            if (iVar6 == 0x16) {
              iVar7 = 9;
            }
            goto LAB_140012091;
          }
          param_1[1] = param_1[1] & 0xffffffdf;
          if (*(byte *)(param_1 + 0x15) < 5) {
            uVar12 = 2;
          }
        }
LAB_140011f44:
        uVar8 = 0;
        goto LAB_1400122a5;
      }
LAB_14001221e:
      if (iVar11 == 0) {
        param_1[1] = param_1[1] & 0xffffffdf;
        uVar12 = 7;
        goto LAB_1400122a0;
      }
      iVar7 = iVar6;
      if (iVar11 == 1) {
        iVar11 = 0;
        if (iVar1 < 0) {
          *(char *)(param_1 + 0x15) = (char)param_1[0x15] + '\x01';
          uVar5 = param_1[1] | 0x20;
        }
        else {
          *(undefined1 *)(param_1 + 0x15) = 0;
          uVar5 = param_1[1] & 0xffffffdf;
        }
        param_1[1] = uVar5;
        if (iVar6 == 0x14) {
          iVar7 = (iVar1 >> 0x1f & 2U) + 0x15;
        }
        else if (iVar1 < 0) {
          iVar7 = 0x16;
          if (uVar9 == 2) {
            iVar7 = 8;
          }
        }
        else {
          iVar7 = 0x11;
          if (uVar9 != 2) {
            iVar7 = 10;
          }
        }
      }
    }
LAB_1400122c4:
    iVar10 = iVar2;
    param_1[(ulonglong)*(byte *)(param_1 + 4) + 5] = *param_1;
    param_1[(ulonglong)*(byte *)(param_1 + 4) + 0xd] = param_2;
    *param_1 = iVar7;
    *(byte *)(param_1 + 4) = (char)param_1[4] + 1U & 7;
    iVar6 = iVar7;
    if (iVar10 != -0x3fffffea) {
      iVar11 = 0;
      *param_4 = uVar12;
      *(undefined1 *)(param_4 + 1) = uVar4;
      param_4[2] = iVar7;
      LOCK();
      iVar6 = param_1[2];
      if (iVar6 == 0) {
        param_1[2] = 0;
      }
      else {
        iVar11 = iVar6;
      }
      UNLOCK();
      param_4[3] = iVar11;
      return uVar8;
    }
  } while( true );
}



===== GpioClxEvtDebounceNoiseFilterExpirationWorker @ 140012340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtDebounceNoiseFilterExpirationWorker(undefined8 param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong lVar6;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GPIO_DEBOUNCE_NOISE_TIMER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e070);
  plVar1 = (longlong *)*plVar4;
  lVar6 = *plVar1;
  if (lVar6 == 0) {
    lVar6 = plVar1[3];
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e0);
  }
  else {
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x480);
  }
  (*pcVar5)(WdfDriverGlobals,lVar6);
  plVar1[4] = (longlong)SystemReserved1[0xf];
  lVar3 = plVar4[1];
  puVar2 = (undefined8 *)plVar4[2];
  *(undefined1 *)(plVar4 + 3) = 0;
  lVar6 = *plVar1;
  plVar1[4] = 0;
  if (lVar6 == 0) {
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e8);
    lVar6 = plVar1[3];
  }
  else {
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x488);
  }
  (*pcVar5)(WdfDriverGlobals,lVar6);
  if ((char)lVar3 == '\0') {
    GpioClxEvtNoiseFilterTimerHandler(0,puVar2);
  }
  else {
    GpioClxEvtDebounceTimerHandler(0,puVar2);
  }
  return;
}



===== GpioClxEvtDebounceTimerHandler @ 140012440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtDebounceTimerHandler(undefined8 param_1,undefined8 *param_2)

{
  undefined2 uVar1;
  longlong *plVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  code *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  char local_res10 [8];
  longlong *local_58;
  undefined2 local_50;
  undefined4 local_4e;
  undefined2 local_4a;
  longlong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  plVar2 = (longlong *)*param_2;
  local_res10[0] = '\0';
  uVar7 = (ulonglong)*(uint *)(plVar2[0x11] + 0x314);
  if ((*(uint *)(plVar2[0x11] + 0x314) & 1) == 0) {
    bVar3 = true;
    cVar4 = KeGetCurrentIrql();
    if (cVar4 == '\x02') {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_2[4],
                         PTR__WDF_GPIO_DEBOUNCE_NOISE_TIMER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e070);
      lVar8 = *plVar2;
      if (lVar8 == 0) {
        lVar8 = plVar2[3];
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e0);
      }
      else {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar6)(WdfDriverGlobals,lVar8);
      plVar2[4] = (longlong)SystemReserved1[0xf];
      *(undefined1 *)(lVar5 + 8) = 1;
      *(undefined8 **)(lVar5 + 0x10) = param_2;
      if (*(char *)(lVar5 + 0x18) == '\0') {
        *(undefined1 *)(lVar5 + 0x18) = 1;
        (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,param_2[4]);
      }
      lVar8 = *plVar2;
      plVar2[4] = 0;
      if (lVar8 == 0) {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar8 = plVar2[3];
      }
      else {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      goto LAB_14001267d;
    }
  }
  else {
    bVar3 = false;
  }
  uVar1 = *(undefined2 *)(param_2 + 1);
  lVar8 = param_2[2];
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0h_EtwWriteTransfer(uVar7,&EVENT_DEBOUNCE_TIMER_COMPLETE,plVar2 + 0xe,uVar1);
  }
  local_4e = 0;
  local_4a = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_58 = plVar2;
  local_50 = uVar1;
  local_48 = lVar8;
  if (bVar3) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar2[6],0);
    plVar2[7] = (longlong)SystemReserved1[0xf];
  }
  if ((*(uint *)(lVar8 + 0xc0) & 4) != 0) {
    if (*(ushort *)(plVar2 + 0x30) < 0x21) {
      LOCK();
      *(uint *)(plVar2 + 0x1d) = *(uint *)(plVar2 + 0x1d) & ~(1 << ((byte)uVar1 & 0x1f));
      UNLOCK();
    }
    else {
      LOCK();
      plVar2[0x1d] = plVar2[0x1d] & ~(1L << ((byte)uVar1 & 0x3f));
      UNLOCK();
    }
    GpiopDebounceInterruptEngine
              ((ulonglong *)(lVar8 + 0x28),(ulonglong *)&local_58,4,(undefined8 *)0x0,local_res10);
    if (local_40._6_1_ != '\0') {
      GpiopScheduleNoiseFilterTimers(plVar2);
    }
  }
  if (local_res10[0] != '\0') {
    GpiopDebounceSignalStateMachineCompletion(lVar8 + 0x28,(longlong *)&local_58);
  }
  if (!bVar3) {
    return;
  }
  lVar8 = plVar2[6];
  plVar2[7] = 0;
  pcVar6 = *(code **)(WdfFunctions_01015 + 0x9d0);
LAB_14001267d:
  (*pcVar6)(WdfDriverGlobals,lVar8);
  return;
}



===== GpioClxEvtInterruptDpc @ 1400126b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpioClxEvtInterruptDpc(undefined8 param_1)

{
  uint uVar1;
  ulonglong *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110);
  puVar2 = (ulonglong *)*puVar3;
  if (((*(uint *)(puVar2[0x11] + 0x314) & 1) == 0) || ((char)puVar2[0x2b] == '\0')) {
    uVar4 = 0;
    LOCK();
    uVar1 = (uint)puVar2[0x15];
    if (uVar1 == 0) {
      *(uint *)(puVar2 + 0x15) = 1;
    }
    else {
      uVar4 = (ulonglong)uVar1;
    }
    UNLOCK();
    if (uVar1 == 0) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,puVar2[0x14]);
    }
  }
  else {
    uVar4 = GpiopIssueDeferredInterruptActivities
                      (puVar2,(ulonglong)*(uint *)(puVar2[0x11] + 0x314),(ulonglong *)0x1);
  }
  return uVar4;
}



===== GpioClxEvtInterruptIsr @ 140012740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GpioClxEvtInterruptIsr(ulonglong param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  
  puVar7 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110);
  uVar5 = _DAT_fffff78000000008;
  puVar3 = (ulonglong *)*puVar7;
  if ((*(char *)(puVar3[0x11] + 0x131) != '\0') && (*(char *)((longlong)puVar3 + 300) == '\0')) {
    param_1 = puVar3[0x22];
    if (puVar3[0x24] == 0) {
      puVar3[0x23] = 1;
      *(undefined1 *)((longlong)puVar3 + 300) = 0;
    }
    else {
      uVar4 = puVar3[0x23];
      uVar8 = _DAT_fffff78000000008 - puVar3[0x24];
      puVar3[0x23] = uVar4 + 1;
      if (uVar8 < 10000000) goto LAB_140012872;
      if (uVar4 + 1 < (ulonglong)GpioMaxInterruptsPerSecond) {
        *(undefined4 *)(puVar3 + 0x25) = 0;
      }
      else {
        uVar6 = (int)puVar3[0x25] + 1;
        *(uint *)(puVar3 + 0x25) = uVar6;
        if (0x1d < uVar6) {
          *(undefined1 *)((longlong)puVar3 + 300) = 1;
          LOCK();
          piVar1 = (int *)(param_1 + 0x10);
          iVar2 = *piVar1;
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          if (iVar2 == 0) {
            (**(code **)(WdfFunctions_01015 + 0x380))(WdfDriverGlobals);
          }
          param_1 = 0;
          (*DAT_14001e610)((int)puVar3[0x26]);
          *(undefined1 *)((longlong)puVar3 + 0x12d) = 1;
        }
      }
      puVar3[0x23] = 0;
    }
    puVar3[0x24] = uVar5;
  }
LAB_140012872:
  GpiopInterruptBankIsr(puVar3,param_1);
  return;
}



===== GpioClxEvtInterruptPassiveIsr @ 140012890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 GpioClxEvtInterruptPassiveIsr(undefined8 param_1)

{
  ulonglong *puVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110);
  puVar1 = (ulonglong *)*puVar3;
  uVar4 = puVar1[6];
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,uVar4,0);
  puVar1[7] = (ulonglong)SystemReserved1[0xf];
  uVar2 = GpiopServiceInterrupt(puVar1,uVar4);
  puVar1[7] = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar1[6]);
  return uVar2;
}



===== GpioClxEvtNoiseFilterTimerHandler @ 140012940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtNoiseFilterTimerHandler(undefined8 param_1,undefined8 *param_2)

{
  undefined2 uVar1;
  longlong *plVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  code *pcVar6;
  longlong lVar7;
  char local_res10 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  longlong *local_58;
  undefined2 local_50;
  undefined4 local_4e;
  undefined2 local_4a;
  longlong local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_34;
  
  plVar2 = (longlong *)*param_2;
  lVar7 = param_2[2];
  bVar3 = true;
  local_res10[0] = '\0';
  local_68 = 0;
  uStack_60 = 0;
  if ((*(uint *)(plVar2[0x11] + 0x314) & 1) == 0) {
    cVar4 = KeGetCurrentIrql();
    if (cVar4 == '\x02') {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_2[5],
                         PTR__WDF_GPIO_DEBOUNCE_NOISE_TIMER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e070);
      lVar7 = *plVar2;
      if (lVar7 == 0) {
        lVar7 = plVar2[3];
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e0);
      }
      else {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar6)(WdfDriverGlobals,lVar7);
      plVar2[4] = (longlong)SystemReserved1[0xf];
      *(undefined1 *)(lVar5 + 8) = 0;
      *(undefined8 **)(lVar5 + 0x10) = param_2;
      if (*(char *)(lVar5 + 0x18) == '\0') {
        *(undefined1 *)(lVar5 + 0x18) = 1;
        (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,param_2[5]);
      }
      lVar7 = *plVar2;
      plVar2[4] = 0;
      if (lVar7 == 0) {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar7 = plVar2[3];
      }
      else {
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      goto LAB_140012bba;
    }
  }
  else {
    bVar3 = false;
  }
  lVar5 = *plVar2;
  uVar1 = *(undefined2 *)(param_2 + 1);
  if (lVar5 == 0) {
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e0);
    lVar5 = plVar2[3];
  }
  else {
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x480);
  }
  (*pcVar6)(WdfDriverGlobals,lVar5);
  lVar5 = *plVar2;
  plVar2[4] = (longlong)SystemReserved1[0xf];
  local_68 = param_2[6];
  uStack_60 = param_2[7];
  plVar2[4] = 0;
  if (lVar5 == 0) {
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
    lVar5 = plVar2[3];
  }
  else {
    pcVar6 = *(code **)(WdfFunctions_01015 + 0x488);
  }
  (*pcVar6)(WdfDriverGlobals,lVar5);
  local_40 = *(undefined4 *)(param_2 + 3);
  local_4e = 0;
  local_4a = 0;
  local_3c = 0;
  local_34 = 0;
  local_58 = plVar2;
  local_50 = uVar1;
  local_48 = lVar7;
  if (bVar3) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,plVar2[6],0);
    plVar2[7] = (longlong)SystemReserved1[0xf];
  }
  if ((*(uint *)(lVar7 + 0xc0) & 4) != 0) {
    GpiopDebounceInterruptEngine
              ((ulonglong *)(lVar7 + 0x28),(ulonglong *)&local_58,5,&local_68,local_res10);
    if (local_3c._2_1_ != '\0') {
      GpiopScheduleNoiseFilterTimers(plVar2);
    }
  }
  if (local_res10[0] != '\0') {
    GpiopDebounceSignalStateMachineCompletion(lVar7 + 0x28,(longlong *)&local_58);
  }
  if (!bVar3) {
    return;
  }
  lVar7 = plVar2[6];
  plVar2[7] = 0;
  pcVar6 = *(code **)(WdfFunctions_01015 + 0x9d0);
LAB_140012bba:
  (*pcVar6)(WdfDriverGlobals,lVar7);
  return;
}



===== GpioClxQueryPinInformation @ 140012be4 =====

undefined8
GpioClxQueryPinInformation
          (longlong param_1,int param_2,undefined8 *param_3,short *param_4,undefined8 *param_5)

{
  longlong lVar1;
  short sVar2;
  
  sVar2 = (short)*param_3;
  if (sVar2 != -1) {
    lVar1 = GpiopGetPinEntryFromPinNumberInternal(param_1,(uint)*param_3 & 0xffff,'\0');
    if (param_2 == *(int *)(lVar1 + 0x100)) {
      *param_4 = sVar2;
      *param_5 = *(undefined8 *)(param_1 + 0x118);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),2,8,10,
                          &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,
                          "GpioClxQueryPinInformation",(char)param_1,(char)param_2);
    }
  }
  return 0xc000000d;
}



===== GpiopAllocateInterruptProcessingResources @ 140012cb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopAllocateInterruptProcessingResources(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong *plVar3;
  ushort uVar4;
  longlong lVar5;
  undefined8 local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined *local_30;
  
  local_40 = *(undefined8 *)(param_1 + 0x2c8);
  local_30 = PTR__WDF_GPIO_INTERRUPT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e048;
  uVar4 = 0;
  local_4c = 0;
  local_38 = 0;
  pcStack_70 = GpioClxEvtHandleInterruptWorker;
  local_5c = 0;
  uStack_54 = 0;
  local_60 = 0x38;
  local_48 = 1;
  local_44 = 1;
  local_78 = 0x18;
  local_68 = 0;
  if (*(short *)(param_1 + 0x2d8) != 0) {
    do {
      lVar5 = (ulonglong)uVar4 * 400 + *(longlong *)(param_1 + 0x2e0);
      puVar1 = (undefined8 *)(lVar5 + 0xa0);
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_78,&local_60,puVar1)
      ;
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,8,0xb,
                           &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,
                           "GpiopAllocateInterruptProcessingResources",(char)iVar2);
        return iVar2;
      }
      plVar3 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,*puVar1,
                          PTR__WDF_GPIO_INTERRUPT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e048);
      uVar4 = uVar4 + 1;
      *plVar3 = lVar5;
    } while (uVar4 < *(ushort *)(param_1 + 0x2d8));
  }
  return 0;
}



===== GpiopDebounceAcquireLock @ 140012e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDebounceAcquireLock(undefined8 param_1,longlong *param_2)

{
  code *pcVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)*param_2;
  if (lVar2 == 0) {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x9e0);
    lVar2 = ((longlong *)*param_2)[3];
  }
  else {
    pcVar1 = *(code **)(WdfFunctions_01015 + 0x480);
  }
  (*pcVar1)(WdfDriverGlobals,lVar2);
  *(void **)(*param_2 + 0x20) = SystemReserved1[0xf];
  return;
}



===== GpiopDebounceReleaseLock @ 140012e8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDebounceReleaseLock(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  
  plVar1 = (longlong *)*param_2;
  plVar1[4] = 0;
  lVar3 = *plVar1;
  if (lVar3 == 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
    lVar3 = plVar1[3];
  }
  else {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x488);
  }
  (*pcVar2)(WdfDriverGlobals,lVar3);
  return;
}



===== GpiopHandleDisableInterruptRequestFailure @ 140012edc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopHandleDisableInterruptRequestFailure(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  ulonglong in_RDX;
  ulonglong uVar8;
  ulonglong *in_R8;
  
  if (*(ushort *)(param_1 + 0x180) < 0x21) {
    uVar5 = 0;
    LOCK();
    uVar2 = *(uint *)(param_1 + 0xe0);
    if (uVar2 == 0) {
      *(uint *)(param_1 + 0xe0) = 0;
    }
    else {
      uVar5 = uVar2;
    }
    UNLOCK();
    uVar8 = (ulonglong)uVar5;
  }
  else {
    uVar8 = 0;
    LOCK();
    uVar3 = *(ulonglong *)(param_1 + 0xe0);
    if (uVar3 == 0) {
      *(ulonglong *)(param_1 + 0xe0) = 0;
    }
    else {
      uVar8 = uVar3;
    }
    UNLOCK();
  }
  while (uVar8 != 0) {
    cVar4 = RtlFindLeastSignificantBit(uVar8);
    in_RDX = (ulonglong)(uint)(int)cVar4;
    in_R8 = (ulonglong *)0x0;
    uVar8 = uVar8 & ~(1L << (in_RDX & 0x3f));
    lVar6 = GpiopGetPinEntryInternal(param_1,(short)cVar4,'\0');
    *(uint *)(lVar6 + 0x94) = *(uint *)(lVar6 + 0x94) | 4;
    iVar7 = *(int *)(lVar6 + 0x90);
    if (iVar7 != 0x7fffffff) {
      iVar7 = iVar7 + 1;
      *(int *)(lVar6 + 0x90) = iVar7;
    }
    if (((5 < iVar7) && (*(int *)(param_1 + 0x130) != -1)) &&
       (uVar2 = *(uint *)(*(longlong *)(param_1 + 0x88) + 0x148), in_RDX = (ulonglong)uVar2,
       (uVar2 & 0x20) == 0)) {
      in_RDX = 0;
      (*DAT_14001e610)();
      LOCK();
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x88) + 0x148);
      *puVar1 = *puVar1 | 0x21;
      UNLOCK();
    }
  }
  if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x148) & 0x20) == 0) {
    GpiopScheduleDeferredInterruptActivities((ulonglong *)param_1,in_RDX,in_R8);
  }
  return;
}



===== GpiopHandleInterruptMaskRequestCompletion @ 140012fd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopHandleInterruptMaskRequestCompletion(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x314) & 1) == 0) {
    for (uVar7 = ~param_3 & param_2; uVar7 != 0;
        uVar7 = uVar7 & ~(1L << ((ulonglong)((int)cVar3 & 0xffff) & 0x3f))) {
      cVar3 = RtlFindLeastSignificantBit(uVar7);
      lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar3,'\0');
      *(undefined4 *)(lVar4 + 0x88) = 0;
    }
    uVar7 = param_3 & *(ulonglong *)(param_1 + 0x148);
    if (uVar7 != 0) {
      if (*(ushort *)(param_1 + 0x180) < 0x21) {
        LOCK();
        *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | (uint)uVar7;
        UNLOCK();
      }
      else {
        LOCK();
        *(ulonglong *)(param_1 + 0xb0) = *(ulonglong *)(param_1 + 0xb0) | uVar7;
        UNLOCK();
      }
      do {
        cVar3 = RtlFindLeastSignificantBit(uVar7);
        uVar6 = (ulonglong)(uint)(int)cVar3;
        puVar8 = (ulonglong *)0x0;
        uVar7 = uVar7 & ~(1L << (uVar6 & 0x3f));
        lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar3,'\0');
        *(uint *)(lVar4 + 0x94) = *(uint *)(lVar4 + 0x94) | 1;
        iVar5 = *(int *)(lVar4 + 0x88);
        if (iVar5 != 0x7fffffff) {
          iVar5 = iVar5 + 1;
          *(int *)(lVar4 + 0x88) = iVar5;
        }
        if (((5 < iVar5) && (*(int *)(param_1 + 0x130) != -1)) &&
           (uVar2 = *(uint *)(*(longlong *)(param_1 + 0x88) + 0x148), uVar6 = (ulonglong)uVar2,
           (uVar2 & 8) == 0)) {
          uVar6 = 0;
          (*DAT_14001e610)();
          LOCK();
          puVar1 = (uint *)(*(longlong *)(param_1 + 0x88) + 0x148);
          *puVar1 = *puVar1 | 9;
          UNLOCK();
        }
      } while (uVar7 != 0);
      if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x148) & 8) == 0) {
        GpiopScheduleDeferredInterruptActivities((ulonglong *)param_1,uVar6,puVar8);
      }
    }
  }
  return;
}



===== GpiopHandleInterruptUnmaskRequestCompletion @ 140013124 =====

void GpiopHandleInterruptUnmaskRequestCompletion
               (longlong param_1,ulonglong param_2,ulonglong param_3)

{
  uint *puVar1;
  char cVar2;
  byte bVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x314) & 1) == 0) {
    for (uVar7 = ~param_3 & param_2; uVar7 != 0;
        uVar7 = uVar7 & ~(1L << ((ulonglong)((int)cVar2 & 0xffff) & 0x3f))) {
      cVar2 = RtlFindLeastSignificantBit(uVar7);
      lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar2,'\0');
      *(undefined4 *)(lVar4 + 0x88) = 0;
    }
    uVar7 = param_3 & ~*(ulonglong *)(param_1 + 0x148);
    if (uVar7 != 0) {
      if (*(ushort *)(param_1 + 0x180) < 0x21) {
        LOCK();
        *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | (uint)uVar7;
        UNLOCK();
      }
      else {
        LOCK();
        *(ulonglong *)(param_1 + 0xb8) = *(ulonglong *)(param_1 + 0xb8) | uVar7;
        UNLOCK();
      }
      do {
        bVar3 = RtlFindLeastSignificantBit(uVar7);
        puVar8 = (ulonglong *)0x0;
        uVar6 = (ulonglong)((int)(char)bVar3 & 0xffff);
        uVar7 = uVar7 & ~(1L << ((ulonglong)((int)(char)bVar3 & 0xffff) & 0x3f));
        lVar4 = GpiopGetPinEntryInternal(param_1,(short)(char)bVar3,'\0');
        *(uint *)(lVar4 + 0x94) = *(uint *)(lVar4 + 0x94) | 1;
        iVar5 = *(int *)(lVar4 + 0x88);
        if (iVar5 != 0x7fffffff) {
          iVar5 = iVar5 + 1;
          *(int *)(lVar4 + 0x88) = iVar5;
        }
        if (5 < iVar5) {
          LOCK();
          puVar1 = (uint *)(*(longlong *)(param_1 + 0x88) + 0x148);
          *puVar1 = *puVar1 | 2;
          UNLOCK();
          if (*(ushort *)(param_1 + 0x180) < 0x21) {
            LOCK();
            *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & ~(1 << (bVar3 & 0x1f));
            UNLOCK();
          }
          else {
            LOCK();
            *(ulonglong *)(param_1 + 0xb8) =
                 *(ulonglong *)(param_1 + 0xb8) & ~(1L << (bVar3 & 0x3f));
            UNLOCK();
          }
        }
      } while (uVar7 != 0);
      GpiopScheduleDeferredInterruptActivities((ulonglong *)param_1,uVar6,puVar8);
    }
  }
  return;
}



===== GpiopHandleStatusClearRequestCompletion @ 14001326c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopHandleStatusClearRequestCompletion(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  
  if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x314) & 1) == 0) {
    for (uVar6 = ~param_3 & param_2; uVar6 != 0;
        uVar6 = uVar6 & ~(1L << ((ulonglong)((int)cVar3 & 0xffff) & 0x3f))) {
      cVar3 = RtlFindLeastSignificantBit(uVar6);
      lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar3,'\0');
      *(undefined4 *)(lVar4 + 0x8c) = 0;
    }
    if (param_3 != 0) {
      if (*(ushort *)(param_1 + 0x180) < 0x21) {
        LOCK();
        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) | (uint)param_3;
        UNLOCK();
      }
      else {
        LOCK();
        *(ulonglong *)(param_1 + 0xd8) = *(ulonglong *)(param_1 + 0xd8) | param_3;
        UNLOCK();
      }
      do {
        cVar3 = RtlFindLeastSignificantBit(param_3);
        uVar6 = (ulonglong)(uint)(int)cVar3;
        puVar7 = (ulonglong *)0x0;
        param_3 = param_3 & ~(1L << (uVar6 & 0x3f));
        lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar3,'\0');
        if ((*(uint *)(lVar4 + 0xc0) & 4) != 0) {
          *(uint *)(lVar4 + 0x94) = *(uint *)(lVar4 + 0x94) | 2;
          iVar5 = *(int *)(lVar4 + 0x8c);
          if (iVar5 != 0x7fffffff) {
            iVar5 = iVar5 + 1;
            *(int *)(lVar4 + 0x8c) = iVar5;
          }
          if (((5 < iVar5) && (*(int *)(param_1 + 0x130) != -1)) &&
             (uVar2 = *(uint *)(*(longlong *)(param_1 + 0x88) + 0x148), uVar6 = (ulonglong)uVar2,
             (uVar2 & 0x10) == 0)) {
            uVar6 = 0;
            (*DAT_14001e610)();
            LOCK();
            puVar1 = (uint *)(*(longlong *)(param_1 + 0x88) + 0x148);
            *puVar1 = *puVar1 | 0x11;
            UNLOCK();
          }
        }
      } while (param_3 != 0);
      if ((*(uint *)(*(longlong *)(param_1 + 0x88) + 0x148) & 0x10) == 0) {
        GpiopScheduleDeferredInterruptActivities((ulonglong *)param_1,uVar6,puVar7);
      }
    }
  }
  return;
}



===== GpiopInterruptBankIsr @ 1400133c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 GpiopInterruptBankIsr(ulonglong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined1 uVar3;
  
  uVar1 = param_1[0x11];
  param_1[4] = (ulonglong)SystemReserved1[0xf];
  pcVar2 = *(code **)(param_1[0x11] + 0x1f8);
  if (pcVar2 != (code *)0x0) {
    param_2 = (ulonglong)(ushort)param_1[0x10];
    (*pcVar2)(param_1[0x11] + 0x400,param_2,param_1[0x28]);
  }
  if ((*(uint *)(uVar1 + 0x314) & 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = GpiopServiceInterrupt(param_1,param_2);
  }
  param_1[4] = 0;
  return uVar3;
}



===== GpiopInvokeTargetIsr @ 140013440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopInvokeTargetIsr(ulonglong param_1,ulonglong param_2)

{
  longlong lVar1;
  char cVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  bool bVar8;
  undefined1 local_res8 [8];
  uint local_res10;
  
  if (param_2 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x88);
    local_res8[0] = 0;
    do {
      cVar2 = RtlFindLeastSignificantBit(param_2);
      uVar7 = 0;
      param_2 = param_2 & ~(1L << ((ulonglong)((int)cVar2 & 0xffff) & 0x3f));
      lVar4 = GpiopGetPinEntryInternal(param_1,(short)cVar2,'\0');
      uVar6 = (ulonglong)*(uint *)(lVar4 + 0xc0);
      if ((*(uint *)(lVar4 + 0xc0) & 0x10) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = *(ulonglong *)(*(longlong *)(param_1 + 0x88) + 0x298);
          WPP_RECORDER_SF_sqD(uVar6,4,8,0xc,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,
                              "GpiopInvokeTargetIsr",(char)param_1,cVar2);
        }
        uVar7 = *(undefined8 *)(lVar4 + 0xf8);
        if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
          McTemplateK0hq_EtwWriteTransfer
                    (uVar6,&EVENT_INTERRUPT_INVOKE_DEVICE_ISR_START,param_1 + 0x70,(short)cVar2,
                     (char)*(undefined4 *)(lVar4 + 0x100));
        }
        local_res10 = 0;
        (*DAT_14001e620)(*(undefined4 *)(lVar4 + 0x100),uVar7);
        uVar5 = local_res10;
        if ((local_res10 == 0) || ((uVar5 = local_res10 - 1, uVar5 != 0 && (uVar5 != 1)))) {
          uVar6 = (ulonglong)(uVar5 >> 8) << 8;
        }
        else {
          uVar6 = (ulonglong)CONCAT31((int3)(uVar5 >> 8),1);
        }
        if (((*(uint *)(lVar4 + 0xc0) & 0x100) != 0) && ((char)uVar6 == '\0')) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sqD(*(undefined8 *)(lVar1 + 0x298),2,8,0xd,
                                &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,
                                "GpiopInvokeTargetIsr",(char)param_1,cVar2);
          }
          GpiopFlipPinPolarity(param_1,(short)cVar2);
          return;
        }
        if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
          McTemplateK0_EtwWriteTransfer
                    (uVar6,&EVENT_INTERRUPT_INVOKE_DEVICE_ISR_COMPLETE,param_1 + 0x70);
        }
      }
      else {
        GpiopAcquireAcpiEventLock(lVar1,local_res8);
        GpioUtilUpdatePinValue(param_1,(short)cVar2,uVar7,'\x01');
        if ((*(uint *)(lVar1 + 0x314) & 1) == 0) {
          ExReleaseFastMutex(lVar1 + 0x78);
        }
        else {
          KeReleaseSpinLockFromDpcLevel(lVar1 + 0xb0);
          KeLowerIrql(local_res8[0]);
        }
        if (*(int *)(lVar4 + 0xec) == 0) {
          GpiopMaskInterrupt(lVar1,2,(ulonglong)*(uint *)(lVar4 + 0x100));
        }
        bVar3 = KeGetCurrentIrql();
        LOCK();
        bVar8 = *(int *)(lVar1 + 0x38) == 0;
        if (bVar8) {
          *(int *)(lVar1 + 0x38) = 1;
        }
        UNLOCK();
        if (bVar8) {
          ExAcquireRundownProtection(lVar1 + 0x40);
          if (bVar3 < 2) {
            GpiopProcessAcpiEventsCommon(*(undefined8 *)(lVar1 + 0x10));
          }
          else {
            (**(code **)(WdfFunctions_01015 + 0x380))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10));
          }
        }
      }
    } while (param_2 != 0);
  }
  return;
}



===== GpiopIssueDeferredInterruptActivities @ 1400136f8 =====

void GpiopIssueDeferredInterruptActivities(ulonglong *param_1,undefined8 param_2,ulonglong *param_3)

{
  int iVar1;
  ulonglong *puVar2;
  
  LOCK();
  iVar1 = *(int *)((longlong)param_1 + 0xac);
  *(int *)((longlong)param_1 + 0xac) = 0;
  UNLOCK();
  if (iVar1 == 1) {
    if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
      param_3 = param_1 + 0xe;
      McTemplateK0zh_EtwWriteTransfer
                (param_1,&EVENT_DEFERRED_INTERRUPT_ACTIVITIES_START,param_3,
                 *(wchar_t **)(param_1[0x11] + 0x300),(char)param_1[0x10]);
    }
    GpiopScheduleDebounceTimers(param_1);
    GpiopDeferredReconfigureRequestHandler((longlong *)param_1);
    GpiopDeferredDisableInterruptHandler((longlong *)param_1,'\0',param_3);
    GpiopDeferredMaskRequestHandler((longlong *)param_1);
    GpiopDeferredStatusClearRequestHandler((longlong *)param_1);
    puVar2 = param_1;
    GpiopDeferredUnmaskRequestHandler((longlong *)param_1);
    if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
      McTemplateK0_EtwWriteTransfer
                (puVar2,&EVENT_DEFERRED_INTERRUPT_ACTIVITIES_COMPLETE,param_1 + 0xe);
    }
  }
  return;
}



===== GpiopScheduleDeferredInterruptActivities @ 1400137a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GpiopScheduleDeferredInterruptActivities(ulonglong *param_1,undefined8 param_2,ulonglong *param_3)

{
  byte bVar1;
  code *pcVar2;
  ulonglong uVar3;
  bool bVar4;
  
  LOCK();
  bVar4 = *(int *)((longlong)param_1 + 0xac) == 0;
  if (bVar4) {
    *(int *)((longlong)param_1 + 0xac) = 1;
  }
  UNLOCK();
  if (bVar4) {
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 3) {
      if (((void *)param_1[9] == SystemReserved1[0xf]) && (bVar1 == 0)) {
        GpiopIssueDeferredInterruptActivities
                  (param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),bVar1),param_3);
        return 0;
      }
      uVar3 = param_1[0x14];
      pcVar2 = *(code **)(WdfFunctions_01015 + 0xbe0);
    }
    else {
      uVar3 = *param_1;
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x470);
    }
    (*pcVar2)(WdfDriverGlobals,uVar3);
  }
  return 0;
}



===== GpiopServiceInterrupt @ 140013834 =====

undefined1 GpiopServiceInterrupt(ulonglong *param_1,undefined8 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  ulonglong *puVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  undefined1 uVar15;
  ulonglong uVar16;
  ulonglong *puVar17;
  ulonglong uVar18;
  uint uVar19;
  int local_res20;
  undefined8 in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff40;
  ulonglong local_90;
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong *local_70;
  ulonglong uStack_68;
  longlong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  
  bVar3 = false;
  local_80 = 0;
  puVar12 = param_1;
  KeGetCurrentIrql();
  bVar6 = false;
  local_90 = 0;
  uVar15 = 0;
  uVar14 = param_1[0x11];
  param_1[9] = (ulonglong)SystemReserved1[0xf];
  local_res20 = 5;
  bVar5 = false;
  local_78 = uVar14;
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    in_stack_ffffffffffffff40 =
         CONCAT44((int)((ulonglong)in_stack_ffffffffffffff40 >> 0x20),(int)param_1[0x26]);
    in_stack_ffffffffffffff38 =
         CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff38 >> 0x10),(short)param_1[0x10]);
    McTemplateK0zhq_EtwWriteTransfer
              (puVar12,param_2,param_1 + 0xe,*(wchar_t **)(uVar14 + 0x300),(char)param_1[0x10],
               (char)param_1[0x26]);
  }
  puVar17 = &local_80;
  puVar12 = &local_90;
  puVar13 = param_1;
  iVar8 = GpiopUpdateStatusAndMaskInformation((longlong *)param_1,puVar12,(longlong *)puVar17);
  if (-1 < iVar8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar13 = *(ulonglong **)(uVar14 + 0x298);
      WPP_RECORDER_SF_sqii(puVar13);
    }
    if ((local_90 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      puVar13 = *(ulonglong **)(uVar14 + 0x298);
      WPP_RECORDER_SF_si(puVar13,puVar12,puVar17,0x10,in_stack_ffffffffffffff38,
                         in_stack_ffffffffffffff40,(char)local_90);
    }
    LOCK();
    uVar16 = param_1[0x19];
    param_1[0x19] = 0;
    UNLOCK();
    if ((uVar16 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      puVar13 = *(ulonglong **)(uVar14 + 0x298);
      WPP_RECORDER_SF_si(puVar13,puVar12,puVar17,0x11,in_stack_ffffffffffffff38,
                         in_stack_ffffffffffffff40,(char)uVar16);
    }
    if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
      puVar17 = param_1 + 0xe;
      McTemplateK0xxxxx_EtwWriteTransfer
                (puVar13,puVar12,puVar17,param_1[0x28],(char)param_1[0x29],(char)param_1[0x18],
                 (char)local_90,(char)uVar16);
    }
    uVar2 = *(uint *)(uVar14 + 0x314);
    uVar14 = 0;
    bVar4 = false;
    uVar18 = 0;
LAB_140013a04:
    if (bVar3) {
LAB_140013a7a:
      if (uVar16 == 0) goto LAB_140013b59;
      cVar7 = RtlFindLeastSignificantBit(uVar16);
      uVar19 = (uint)cVar7;
    }
    else {
      cVar7 = RtlFindLeastSignificantBit(param_1[0x18]);
      uVar19 = (uint)cVar7;
      param_1[0x18] = param_1[0x18] & ~(1L << ((ulonglong)(uVar19 & 0xffff) & 0x3f));
      if (cVar7 == -1) {
        local_res20 = 6;
        bVar3 = true;
        if ((ushort)param_1[0x30] < 0x21) {
          uVar9 = 0;
          LOCK();
          uVar19 = (uint)param_1[0x28];
          if (uVar19 == 0) {
            *(uint *)(param_1 + 0x28) = 0;
          }
          else {
            uVar9 = uVar19;
          }
          UNLOCK();
          uVar10 = (ulonglong)uVar9;
        }
        else {
          uVar10 = 0;
          LOCK();
          uVar1 = param_1[0x28];
          if (uVar1 == 0) {
            param_1[0x28] = 0;
          }
          else {
            uVar10 = uVar1;
          }
          UNLOCK();
        }
        uVar16 = uVar16 & uVar10;
        goto LAB_140013a7a;
      }
    }
    lVar11 = GpiopGetPinEntryInternal((longlong)param_1,(ushort)uVar19,'\0');
    if (((*(int *)(lVar11 + 0xf0) != 3) || (bVar3)) || ((*(uint *)(lVar11 + 0xc0) & 0x100) != 0)) {
      uVar16 = uVar16 & ~(1L << ((ulonglong)(uVar19 & 0xffff) & 0x3f));
    }
    puVar17 = (ulonglong *)0x0;
    uStack_68 = (ulonglong)(ushort)uVar19;
    uStack_58 = 0x100000000;
    local_50 = 0;
    local_70 = param_1;
    local_60 = lVar11;
    GpiopServiceInterruptOnPin((ulonglong *)&local_70,local_res20,0);
    if (uStack_58._5_1_ != '\0') {
      bVar6 = true;
    }
    if (uStack_58._7_1_ != '\0') {
      uVar18 = uVar18 | 1L << ((ulonglong)(uVar19 & 0xffff) & 0x3f);
    }
    if (local_50._1_1_ != '\0') {
      uVar14 = uVar14 | 1L << ((ulonglong)(uVar19 & 0xffff) & 0x3f);
    }
    if ((*(byte *)(lVar11 + 0xc0) & 0x80) != 0) {
      bVar4 = true;
    }
    if ((char)local_50 != '\0') {
      bVar5 = true;
    }
    goto LAB_140013a04;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar13 = *(ulonglong **)(uVar14 + 0x298);
    WPP_RECORDER_SF_D(puVar13,2,8,0xe,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,(char)iVar8);
  }
  goto LAB_140013c13;
LAB_140013b59:
  local_88 = uVar18;
  GpiopDeferredMaskRequestHandler((longlong *)param_1);
  uVar16 = local_78;
  if ((uVar14 == 0) && (local_90 == 0)) {
LAB_140013bc7:
    if (bVar4) goto LAB_140013bd7;
    uVar15 = 0;
  }
  else {
    if ((uVar2 & 2) == 0) {
      if ((ushort)param_1[0x30] < 0x21) {
        LOCK();
        *(uint *)(param_1 + 0x1b) = (uint)param_1[0x1b] | (uint)uVar14;
        UNLOCK();
      }
      else {
        LOCK();
        param_1[0x1b] = param_1[0x1b] | uVar14;
        UNLOCK();
      }
      if ((ushort)param_1[0x30] < 0x21) {
        LOCK();
        *(uint *)(param_1 + 0x1b) = (uint)param_1[0x1b] | (uint)local_90;
        UNLOCK();
      }
      else {
        LOCK();
        param_1[0x1b] = param_1[0x1b] | local_90;
        UNLOCK();
      }
      GpiopDeferredStatusClearRequestHandler((longlong *)param_1);
    }
    if (uVar14 == 0) goto LAB_140013bc7;
LAB_140013bd7:
    uVar15 = 1;
  }
  if (bVar5) {
    GpiopServiceActiveBothInterrupts(param_1);
  }
  puVar13 = param_1;
  uVar14 = local_88;
  GpiopInvokeTargetIsr((ulonglong)param_1,local_88);
  if ((bVar6) || ((*(uint *)(uVar16 + 0x314) & 1) == 0)) {
    puVar13 = param_1;
    GpiopScheduleDeferredInterruptActivities(param_1,uVar14,puVar17);
  }
LAB_140013c13:
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar13,&EVENT_INTERRUPT_COMPLETE,param_1 + 0xe);
  }
  param_1[9] = 0;
  return uVar15;
}



===== GpiopServiceInterruptOnPin @ 140013c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopServiceInterruptOnPin(ulonglong *param_1,int param_2,uint param_3)

{
  int iVar1;
  ulonglong *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  code *pcVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  byte bVar19;
  ulonglong *puVar20;
  ulonglong uVar21;
  uint uVar22;
  ulonglong *puVar23;
  int iVar24;
  undefined1 local_res20 [8];
  int local_54;
  uint local_50;
  ulonglong local_48;
  
  puVar2 = (ulonglong *)*param_1;
  piVar3 = (int *)param_1[2];
  uVar22 = 0;
  local_res20[0] = 0;
  local_54 = 0;
  local_48 = puVar2[0x11];
  if (param_2 != 7) {
    param_3 = 0;
  }
  uVar21 = param_1[1];
  local_50 = *(uint *)(local_48 + 0x314);
  uVar4 = local_50 & 1;
  uVar5 = local_50 & 1;
  uVar6 = local_50 & 1;
  uVar7 = local_50 & 1;
  uVar8 = local_50 & 1;
  uVar9 = local_50 & 1;
  uVar10 = local_50 & 1;
  if ((local_50 & 1) == 0) {
    uVar16 = *puVar2;
    bVar11 = true;
    if (uVar16 == 0) {
      pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e0);
      uVar16 = puVar2[3];
    }
    else {
      pcVar15 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar15)(WdfDriverGlobals,uVar16);
    puVar2[4] = (ulonglong)SystemReserved1[0xf];
    uVar12 = local_50;
  }
  else {
    bVar11 = false;
    uVar12 = local_50;
  }
LAB_140013d1a:
  iVar24 = param_2;
  local_50 = GpiopServiceInterruptStateMachine
                       ((longlong)puVar2,piVar3,(ushort)uVar21,param_2,param_3,uVar22,&local_54);
  if (local_54 == 0) goto LAB_14001417e;
  bVar19 = (byte)uVar21;
  if (local_54 == 1) {
    if ((ushort)puVar2[0x30] < 0x21) {
      uVar17 = 0;
      LOCK();
      uVar22 = (uint)puVar2[0x1c];
      if (uVar22 == 0) {
        *(uint *)(puVar2 + 0x1c) = 0;
      }
      else {
        uVar17 = (ulonglong)uVar22;
      }
      UNLOCK();
    }
    else {
      uVar17 = 0;
      LOCK();
      uVar16 = puVar2[0x1c];
      if (uVar16 == 0) {
        puVar2[0x1c] = 0;
      }
      else {
        uVar17 = uVar16;
      }
      UNLOCK();
    }
    uVar16 = 1L << (bVar19 & 0x3f);
    if ((ushort)puVar2[0x30] < 0x21) {
      LOCK();
      if ((int)puVar2[0x16] == 0) {
        *(int *)(puVar2 + 0x16) = 0;
      }
      UNLOCK();
    }
    else {
      LOCK();
      if (puVar2[0x16] == 0) {
        puVar2[0x16] = 0;
      }
      UNLOCK();
    }
    iVar13 = 0;
    LOCK();
    iVar1 = piVar3[0x31];
    if (iVar1 == 0) {
      piVar3[0x31] = 0;
    }
    else {
      iVar13 = iVar1;
    }
    UNLOCK();
    bVar19 = 1;
    if (((0 < iVar13) || ((uVar17 & uVar16) != 0)) && (bVar19 = 0, iVar24 == 5)) {
      if ((ushort)puVar2[0x30] < 0x21) {
        uVar14 = 0;
        LOCK();
        uVar22 = (uint)puVar2[0x1d];
        if (uVar22 == 0) {
          *(int *)(puVar2 + 0x1d) = 0;
        }
        else {
          uVar14 = uVar22;
        }
        UNLOCK();
        uVar18 = (ulonglong)uVar14;
      }
      else {
        uVar18 = 0;
        LOCK();
        uVar17 = puVar2[0x1d];
        if (uVar17 == 0) {
          puVar2[0x1d] = 0;
        }
        else {
          uVar18 = uVar17;
        }
        UNLOCK();
      }
      if ((piVar3[0x3b] == 0) || ((uVar18 & uVar16) != 0)) {
        if (*(char *)((longlong)param_1 + 0x1c) == '\0') {
          if ((uVar12 & 2) == 0) {
            if ((ushort)puVar2[0x30] < 0x21) {
              LOCK();
              *(uint *)(puVar2 + 0x1b) = (uint)puVar2[0x1b] | (uint)uVar16;
              UNLOCK();
            }
            else {
              LOCK();
              puVar2[0x1b] = puVar2[0x1b] | uVar16;
              UNLOCK();
            }
            GpiopDeferredStatusClearRequestHandler((longlong *)puVar2);
            bVar19 = 0;
          }
        }
        else {
          *(undefined1 *)((longlong)param_1 + 0x21) = 1;
        }
      }
    }
    param_3 = 1;
    uVar22 = ~-(uint)bVar19 & 0xc0000001;
    goto LAB_14001417e;
  }
  if (local_54 == 2) {
    if ((uVar12 & 2) == 0) {
      uVar16 = 1L << (bVar19 & 0x3f);
      if ((ushort)puVar2[0x30] < 0x21) {
        LOCK();
        *(uint *)(puVar2 + 0x1b) = (uint)puVar2[0x1b] | (uint)uVar16;
        UNLOCK();
      }
      else {
        LOCK();
        puVar2[0x1b] = puVar2[0x1b] | uVar16;
        UNLOCK();
      }
    }
    if ((*(char *)((longlong)param_1 + 0x1c) == '\0') || ((char)piVar3[0x30] < '\0')) {
      if (uVar7 == 0) {
        uVar16 = *puVar2;
        puVar2[4] = 0;
        if (uVar16 == 0) {
          pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e8);
          uVar16 = puVar2[3];
        }
        else {
          pcVar15 = *(code **)(WdfFunctions_01015 + 0x488);
        }
        (*pcVar15)(WdfDriverGlobals,uVar16);
      }
      GpiopDeferredStatusClearRequestHandler((longlong *)puVar2);
LAB_140013de7:
      if (uVar8 == 0) {
        uVar16 = *puVar2;
        if (uVar16 == 0) {
          pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e0);
          uVar16 = puVar2[3];
        }
        else {
          pcVar15 = *(code **)(WdfFunctions_01015 + 0x480);
        }
        (*pcVar15)(WdfDriverGlobals,uVar16);
        puVar2[4] = (ulonglong)SystemReserved1[0xf];
      }
    }
    else {
      *(undefined1 *)((longlong)param_1 + 0x21) = 1;
    }
LAB_140013f2d:
    uVar22 = 0;
  }
  else {
    if (local_54 != 3) {
      if (local_54 == 4) {
        if (*(char *)((longlong)param_1 + 0x1c) == '\0') {
          GpiopMaskInterrupt(local_48,0,(ulonglong)(uint)piVar3[0x40]);
        }
        else {
          GpiopIncrementMaskCount((longlong *)puVar2,(longlong)piVar3,bVar19);
        }
        goto LAB_140013f2d;
      }
      if (local_54 == 5) {
        if ((ushort)puVar2[0x30] < 0x21) {
          LOCK();
          *(uint *)(puVar2 + 0x21) = (uint)puVar2[0x21] | 1 << (bVar19 & 0x1f);
          UNLOCK();
        }
        else {
          LOCK();
          puVar2[0x21] = puVar2[0x21] | 1L << (bVar19 & 0x3f);
          UNLOCK();
        }
        if (*(char *)((longlong)param_1 + 0x1c) == '\0') {
          if (uVar9 == 0) {
            uVar16 = *puVar2;
            puVar2[4] = 0;
            if (uVar16 == 0) {
              pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e8);
              uVar16 = puVar2[3];
            }
            else {
              pcVar15 = *(code **)(WdfFunctions_01015 + 0x488);
            }
            (*pcVar15)(WdfDriverGlobals,uVar16);
          }
          GpiopServiceActiveBothInterrupts(puVar2);
          if (uVar5 == 0) {
            uVar16 = *puVar2;
            if (uVar16 == 0) {
              pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e0);
              uVar16 = puVar2[3];
            }
            else {
              pcVar15 = *(code **)(WdfFunctions_01015 + 0x480);
            }
            (*pcVar15)(WdfDriverGlobals,uVar16);
            puVar2[4] = (ulonglong)SystemReserved1[0xf];
          }
        }
        else {
          *(undefined1 *)(param_1 + 4) = 1;
        }
        goto LAB_140013fee;
      }
      if (local_54 != 6) goto LAB_140014199;
      if ((piVar3[0x3b] == 0) || (*(char *)((longlong)param_1 + 0x1c) == '\0')) {
        if (uVar4 == 0) {
          uVar16 = *puVar2;
          puVar2[4] = 0;
          if (uVar16 == 0) {
            pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e8);
            uVar16 = puVar2[3];
          }
          else {
            pcVar15 = *(code **)(WdfFunctions_01015 + 0x488);
          }
          (*pcVar15)(WdfDriverGlobals,uVar16);
        }
        GpiopInvokeTargetIsr((ulonglong)puVar2,1L << (bVar19 & 0x3f));
        goto LAB_140013de7;
      }
      *(undefined1 *)((longlong)param_1 + 0x1f) = 1;
      goto LAB_140013f2d;
    }
    if (uVar10 == 0) {
      uVar16 = *puVar2;
      puVar2[4] = 0;
      if (uVar16 == 0) {
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e8);
        uVar16 = puVar2[3];
      }
      else {
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar15)(WdfDriverGlobals,uVar16);
    }
    puVar23 = (ulonglong *)0x3;
    puVar20 = param_1;
    uVar22 = GpiopDebounceInterruptEngine
                       ((ulonglong *)(piVar3 + 10),param_1,3,(undefined8 *)0x0,local_res20);
    if (uVar6 == 0) {
      puVar20 = (ulonglong *)*puVar2;
      if (puVar20 == (ulonglong *)0x0) {
        puVar20 = (ulonglong *)puVar2[3];
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e0);
      }
      else {
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar15)(WdfDriverGlobals);
      puVar2[4] = (ulonglong)SystemReserved1[0xf];
    }
    if (*(char *)((longlong)param_1 + 0x1c) == '\0') {
      GpiopScheduleDeferredInterruptActivities(puVar2,puVar20,puVar23);
    }
  }
LAB_140013fee:
  param_3 = 1;
LAB_14001417e:
  if (local_50 != 0xc0000016) {
LAB_140014199:
    if (bVar11) {
      uVar21 = *puVar2;
      puVar2[4] = 0;
      if (uVar21 == 0) {
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x9e8);
        uVar21 = puVar2[3];
      }
      else {
        pcVar15 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar15)(WdfDriverGlobals,uVar21);
    }
    return;
  }
  goto LAB_140013d1a;
}



===== GpiopServiceInterruptStateMachine @ 1400141f8 =====

undefined4
GpiopServiceInterruptStateMachine
          (longlong param_1,int *param_2,ushort param_3,int param_4,int param_5,int param_6,
          undefined4 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = *param_2;
  uVar5 = 0;
  uVar7 = 0;
  iVar4 = -0x3fffffea;
  do {
    if (iVar6 < 7) {
      if (iVar6 == 6) {
        if (param_5 == 0) {
          uVar5 = 4;
LAB_14001448a:
          uVar7 = 0xc0000016;
LAB_14001448d:
          iVar4 = 0;
        }
        else if (param_5 == 1) {
          param_5 = 0;
          iVar6 = 7;
        }
      }
      else if (iVar6 == 0) {
        uVar7 = 0xc0000001;
        iVar4 = -0x3fffffff;
      }
      else if (iVar6 == 1) {
        iVar6 = 0xc;
        if (param_4 != 7) {
          iVar6 = 2;
        }
      }
      else if (iVar6 == 2) {
        if (param_5 == 0) {
          uVar5 = 1;
          goto LAB_14001448a;
        }
        if (param_5 == 1) {
          param_5 = 0;
          if (param_6 == 0) {
            if (param_4 == 6) goto LAB_1400142ca;
            iVar6 = (-(uint)((param_2[0x30] & 400U) != 0) & 0xfffffffb) + 8;
          }
          else {
            iVar6 = 0xb;
          }
        }
      }
      else if (iVar6 == 3) {
        if (((char)param_2[0x30] < '\0') && (param_4 == 5)) {
          uVar5 = 3;
          goto LAB_140014446;
        }
LAB_1400142ca:
        iVar6 = 4;
      }
      else if (iVar6 == 4) {
        if ((param_2[0x3c] != 3) || ((param_2[0x30] & 0x100U) == 0)) {
          if (param_4 != 7) goto LAB_1400144ab;
          uVar5 = 0;
          goto LAB_1400144a0;
        }
        iVar6 = 6;
      }
      else {
        if (iVar6 != 5) goto LAB_14001439f;
        iVar6 = 8;
      }
    }
    else if (iVar6 == 7) {
      if (param_5 == 0) {
        uVar5 = 5;
        goto LAB_14001448a;
      }
      if (param_5 == 1) {
        param_5 = 0;
        if (param_4 == 7) {
LAB_1400144a0:
          iVar4 = 0;
          uVar7 = 0;
          iVar6 = 1;
        }
        else {
LAB_1400144ab:
          iVar6 = 5;
        }
      }
    }
    else if (iVar6 == 8) {
      if (((char)param_2[0x30] < '\0') && (param_4 != 6)) goto LAB_140014446;
      iVar6 = 9;
    }
    else {
      if (iVar6 != 9) {
        if (iVar6 == 10) {
          if ((param_4 - 5U & 0xfffffffd) == 0) {
            uVar5 = 2;
          }
        }
        else {
          if (iVar6 != 0xb) {
            if (iVar6 == 0xc) {
              if (param_5 == 4) {
                iVar6 = 10;
              }
              else if (param_5 == 2) {
                iVar6 = 4;
                if ((param_2[0xb] & 0xeU) == 6) {
                  iVar6 = 1;
                  uVar7 = 0;
                  iVar4 = 0;
                }
              }
              else {
                iVar6 = 1;
                uVar7 = 0;
                iVar4 = 0;
              }
              param_5 = 0;
            }
            else {
LAB_14001439f:
              iVar4 = -0x3fffffff;
              uVar7 = 0xc0000001;
            }
            goto LAB_1400144b1;
          }
          if (param_4 == 5) {
            if (*(ushort *)(param_1 + 0x180) < 0x21) {
              uVar3 = 0;
              LOCK();
              uVar1 = *(uint *)(param_1 + 0xe8);
              if (uVar1 == 0) {
                *(uint *)(param_1 + 0xe8) = 0;
              }
              else {
                uVar3 = (ulonglong)uVar1;
              }
              UNLOCK();
            }
            else {
              uVar3 = 0;
              LOCK();
              uVar2 = *(ulonglong *)(param_1 + 0xe8);
              if (uVar2 == 0) {
                *(ulonglong *)(param_1 + 0xe8) = 0;
              }
              else {
                uVar3 = uVar2;
              }
              UNLOCK();
            }
            if ((param_2[0x3b] == 0) || ((uVar3 >> ((ulonglong)param_3 & 0x3f) & 1) != 0)) {
              uVar5 = 2;
            }
          }
        }
LAB_140014446:
        iVar6 = 1;
        uVar7 = 0;
        goto LAB_14001448d;
      }
      if (param_5 == 0) {
        uVar5 = 6;
        goto LAB_14001448a;
      }
      if (param_5 == 1) {
        param_5 = 0;
        iVar6 = 10;
      }
    }
LAB_1400144b1:
    param_2[(ulonglong)*(byte *)(param_2 + 0x2e) + 0x26] = *param_2;
    *param_2 = iVar6;
    *(byte *)(param_2 + 0x2e) = (char)param_2[0x2e] + 1U & 7;
    if (iVar4 != -0x3fffffea) {
      *param_7 = uVar5;
      return uVar7;
    }
  } while( true );
}



===== GpiopSetInterruptState @ 140014510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopSetInterruptState(undefined8 param_1,longlong param_2,char param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  longlong local_10;
  
  if (param_2 != 0) {
    local_14 = 0;
    local_10 = (**(code **)(WdfFunctions_01015 + 0x4a0))(WdfDriverGlobals);
    if (local_10 != 0) {
      local_14 = 0;
      local_18 = 1;
      if (param_3 == '\0') {
        IoReportInterruptInactive(&local_18);
      }
      else {
        IoReportInterruptActive();
      }
    }
  }
  return;
}



===== GpiopUpdateStatusAndMaskInformation @ 140014584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpiopUpdateStatusAndMaskInformation(longlong *param_1,ulonglong *param_2,longlong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined1 auStackY_98 [32];
  undefined2 local_58;
  undefined4 local_56;
  undefined2 local_52;
  longlong local_50;
  longlong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  plVar7 = param_1;
  GpiopCheckEnabledInterrupts(param_1);
  local_58 = (undefined2)param_1[0x10];
  local_50 = param_1[0x28];
  lVar3 = param_1[0x11];
  local_56 = 0;
  local_52 = 0;
  local_48 = 0;
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0zh_EtwWriteTransfer
              (plVar7,&EVENT_QUERY_ACTIVE_INTERRUPTS_START,param_1 + 0xe,
               *(wchar_t **)(lVar3 + 0x300),(char)param_1[0x10]);
  }
  lVar8 = lVar3 + 0x400;
  iVar4 = (**(code **)(lVar3 + 0x1b8))(lVar8,&local_58);
  if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(lVar8,&EVENT_QUERY_ACTIVE_INTERRUPTS_COMPLETE,param_1 + 0xe);
  }
  if ((iVar4 < 0) && ((*(uint *)(lVar3 + 0x314) & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x138,5,(longlong)iVar4,lVar3);
  }
  param_1[0x18] = local_48;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1[0x11] + 0x298),2,8,0x12,
                         &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,
                         "GpiopUpdateStatusAndMaskInformation",(char)iVar4);
    }
  }
  else {
    *param_3 = local_48;
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      uVar5 = 0;
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x28);
      if (uVar1 == 0) {
        *(uint *)(param_1 + 0x28) = 0;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
      uVar6 = (ulonglong)uVar5;
    }
    else {
      uVar6 = 0;
      LOCK();
      uVar2 = param_1[0x28];
      if (uVar2 == 0) {
        param_1[0x28] = 0;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    }
    *param_2 = ~uVar6 & param_1[0x18];
    param_1[0x18] = param_1[0x18] & uVar6;
    if (*(ushort *)(param_1 + 0x30) < 0x21) {
      uVar5 = 0;
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x16);
      if (uVar1 == 0) {
        *(uint *)(param_1 + 0x16) = 0;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
      uVar6 = (ulonglong)uVar5;
    }
    else {
      uVar6 = 0;
      LOCK();
      uVar2 = param_1[0x16];
      if (uVar2 == 0) {
        param_1[0x16] = 0;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    }
    param_1[0x18] = param_1[0x18] & ~(param_1[0x29] & ~uVar6);
  }
  return iVar4;
}



===== McTemplateK0hq_EtwWriteTransfer @ 140014770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined1 param_5)

{
  undefined2 local_res20 [4];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined2 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 2;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0xxxxx_EtwWriteTransfer @ 1400147e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xxxxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = &local_res20;
  local_60 = 8;
  local_58 = &param_5;
  local_50 = 8;
  local_48 = &param_6;
  local_40 = 8;
  local_38 = &param_7;
  local_28 = &param_8;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EVENT_INTERRUPT_PIN_STATE,param_3,6,local_78);
  return;
}



===== McTemplateK0zhq_EtwWriteTransfer @ 14001488c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zhq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_3c = 0;
  local_38 = &param_5;
  local_30 = 2;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = &param_6;
  local_20 = 4;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",&EVENT_INTERRUPT_START,param_3,4,local_58);
  return;
}



===== WPP_RECORDER_SF_si @ 140014934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_si(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,param_4,"GpiopServiceInterrupt",0x16
               ,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,param_4,
                  "GpiopServiceInterrupt",0x16,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_sqDs @ 140014a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDs(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  char *in_stack_00000048;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000048 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000048[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0x13,"GpiopDebounceTracePin",0x16,
               &uStack0000000000000038,8,&uStack0000000000000040,4,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000048[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_1,4,8,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0x13,
                  "GpiopDebounceTracePin",0x16,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  in_stack_00000048,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sqDsD @ 140014bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDsD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  char *in_stack_00000048;
  undefined1 uStack0000000000000050;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000048 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000048[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0x14,"GpiopDebounceTracePin",0x16,
               &uStack0000000000000038,8,&uStack0000000000000040,4,pcVar1,lVar3,
               &uStack0000000000000050,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000048[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_1,4,8,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0x14,
                  "GpiopDebounceTracePin",0x16,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  in_stack_00000048,lVar2,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sqii @ 140014d78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqii(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0xf,"GpiopServiceInterrupt",0x16,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_ffc1a2236e7033073bc8abd1a9198f92_Traceguids,0xf,
                  "GpiopServiceInterrupt",0x16,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,0);
  return;
}



===== GpiopCleanupInterruptStormMitigation @ 140014e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopCleanupInterruptStormMitigation(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  ushort uVar6;
  uint uVar7;
  
  plVar5 = (longlong *)(param_1 + 0x2a8);
  uVar7 = 0;
  if (*(int *)(param_1 + 0x2a4) != 0) {
    do {
      lVar4 = *plVar5;
      uVar2 = (ulonglong)uVar7;
      lVar1 = *(longlong *)(lVar4 + 8 + uVar2 * 0x18);
      if (lVar1 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x388))(WdfDriverGlobals,lVar1,1);
        (**(code **)(WdfFunctions_01015 + 0x680))
                  (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8 + uVar2 * 0x18));
        *(undefined8 *)(lVar4 + 8 + uVar2 * 0x18) = 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x2a4));
  }
  if (*plVar5 != 0) {
    ExFreePoolWithTag(*plVar5,0x49784347);
    *plVar5 = 0;
  }
  if ((4 < *(int *)(param_1 + 0x2d0)) && (uVar6 = 0, *(short *)(param_1 + 0x2d8) != 0)) {
    do {
      plVar5 = (longlong *)((ulonglong)uVar6 * 400 + *(longlong *)(param_1 + 0x2e0));
      lVar4 = *plVar5;
      if (lVar4 == 0) {
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x9e0);
        lVar4 = plVar5[3];
      }
      else {
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x480);
      }
      (*pcVar3)(WdfDriverGlobals,lVar4);
      plVar5[4] = (longlong)SystemReserved1[0xf];
      if (*(char *)((longlong)plVar5 + 0x12d) != '\0') {
        (*DAT_14001e618)((int)plVar5[0x26],0);
        *(undefined1 *)((longlong)plVar5 + 0x12d) = 0;
      }
      lVar4 = *plVar5;
      plVar5[4] = 0;
      if (lVar4 == 0) {
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x9e8);
        lVar4 = plVar5[3];
      }
      else {
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x488);
      }
      (*pcVar3)(WdfDriverGlobals,lVar4);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)(param_1 + 0x2d8));
  }
  return;
}



===== GpiopMitigateInterruptStorm @ 140015050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopMitigateInterruptStorm(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x390))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x298),2,8,10,
                     &WPP_e8c49735b3fd342450375d7c2fbf8e8a_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x2b8))(WdfDriverGlobals,uVar1,2);
  return;
}



===== GpioFastIoInterfaceDereference @ 140015100 =====

void GpioFastIoInterfaceDereference(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -1;
  UNLOCK();
  return;
}



===== GpioFastIoInterfaceReference @ 140015110 =====

void GpioFastIoInterfaceReference(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  UNLOCK();
  return;
}



===== GpioProcessFastIoReadPins @ 140015120 =====

void GpioProcessFastIoReadPins(ulonglong *param_1)

{
  GpiopReadPins(*(longlong *)(*param_1 + 0x10),*param_1,1,(void *)param_1[1],(uint)param_1[2],
                (uint *)((longlong)param_1 + 0x14));
  return;
}



===== GpioProcessFastIoWritePins @ 140015160 =====

void GpioProcessFastIoWritePins(longlong *param_1)

{
  GpiopWritePins(*(longlong *)(*param_1 + 0x10),*param_1,0,1,param_1[1],*(uint *)(param_1 + 2),
                 (uint *)((longlong)param_1 + 0x14));
  return;
}



===== GpiopProcessFastIoInterfaceRequest @ 1400151a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpiopProcessFastIoInterfaceRequest
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_a8 [32];
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78 = (undefined8 *)0x0;
  local_70 = 0;
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_3,&local_68);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_3);
  if ((lVar2 == 0) ||
     (lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar2,
                         PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), lVar2 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x298),2,6,0x15,
                        &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)param_3);
    }
    return -0x3ffffff8;
  }
  if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x298),2,6,0x16,
                        &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)param_3);
    }
    return -0x3fffff45;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_3,0x38,&local_78);
  if (-1 < iVar1) {
    *local_78 = 0;
    local_78[1] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[6] = 0;
    *(undefined2 *)local_78 = 0x38;
    *(undefined2 *)((longlong)local_78 + 2) = 1;
    local_78[2] = GpioFastIoInterfaceReference;
    local_78[3] = GpioFastIoInterfaceDereference;
    local_78[5] = GpioProcessFastIoReadPins;
    local_78[6] = GpioProcessFastIoWritePins;
    local_78[4] = lVar2;
    *param_4 = 0x38;
    LOCK();
    *(int *)(lVar2 + 0x60) = *(int *)(lVar2 + 0x60) + 1;
    UNLOCK();
    return iVar1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return iVar1;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,6,0x17,
                    &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)iVar1);
  return iVar1;
}



===== GpiopProcessReadPinsRequest @ 14001540c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GpiopProcessReadPinsRequest
                    (longlong param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_a8 [32];
  uint local_78 [2];
  ulonglong local_70;
  void *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = (void *)0x0;
  local_70 = 0;
  local_78[0] = 0;
  local_40 = 0;
  uStack_58 = 0;
  local_60 = 0x28;
  local_50 = 0;
  uStack_48 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_3,&local_60);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_3);
  if ((lVar2 == 0) ||
     (uVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar2,
                         PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), uVar3 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x298),2,7,0x11,
                        &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)param_3);
    }
    return 0xc00000bb;
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_3,1,&local_68);
  if (-1 < (int)uVar1) {
    if (0x1fffffff < local_70) {
      local_70 = 0x1fffffff;
    }
    uVar3 = GpiopReadPins(param_1,uVar3,0,local_68,(int)local_70 << 3,local_78);
    *param_4 = local_78[0] + 7 >> 3;
    return uVar3 & 0xffffffff;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return (ulonglong)uVar1;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,7,0x12,
                    &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)uVar1);
  return (ulonglong)uVar1;
}



===== GpiopProcessWritePinsRequest @ 1400155f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GpiopProcessWritePinsRequest
                    (longlong param_1,undefined8 param_2,ulonglong param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_b8 [32];
  uint local_78 [2];
  ulonglong local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = 0;
  local_70 = 0;
  local_78[0] = 0;
  local_40 = 0;
  uStack_58 = 0;
  local_60 = 0x28;
  local_50 = 0;
  uStack_48 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_3,&local_60);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_3);
  if ((lVar2 == 0) ||
     (lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar2,
                         PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), lVar2 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x298),2,7,0x13,
                        &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)param_3);
    }
    return 0xc00000bb;
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_3,1);
  if (-1 < (int)uVar1) {
    if (0x1fffffff < local_70) {
      local_70 = 0x1fffffff;
    }
    uVar3 = GpiopWritePins(param_1,lVar2,param_3,0,local_68,(int)local_70 << 3,local_78);
    *param_4 = local_78[0] + 7 >> 3;
    return uVar3 & 0xffffffff;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return (ulonglong)uVar1;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,7,0x14,
                    &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,(char)uVar1);
  return (ulonglong)uVar1;
}



===== GpioClxBankActiveConditionCallback @ 140015800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxBankActiveConditionCallback(undefined8 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(lVar3 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar3 + 300) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if ((char)iVar2 == '\0') {
    *(undefined1 *)((ulonglong)param_2 * 400 + 0x158 + *(longlong *)(lVar3 + 0x2e0)) = 1;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x120));
    if (*(char *)(lVar3 + 0x128) == '\0') {
      (**(code **)(WdfFunctions_01015 + 0x4d0))
                (WdfDriverGlobals,
                 *(undefined8 *)(*(longlong *)(lVar3 + 0x2e0) + 0x58 + (ulonglong)param_2 * 400));
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x120));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(*(undefined8 *)(lVar3 + 0x298),4,3,10,
                          &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                          "GpioClxBankActiveConditionCallback",(char)lVar3,(char)param_2);
    }
  }
  return;
}



===== GpioClxBankIdleConditionCallback @ 140015940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxBankIdleConditionCallback(undefined8 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  uVar4 = (ulonglong)param_2;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(lVar3 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar3 + 300) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if ((char)iVar2 == '\0') {
    lVar5 = uVar4 * 400 + *(longlong *)(lVar3 + 0x2e0);
    *(undefined1 *)(lVar5 + 0x158) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x120));
    if (*(char *)(lVar3 + 0x128) == '\0') {
      (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x58),0,0);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x120));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(*(undefined8 *)(lVar3 + 0x298),4,3,0xb,
                          &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                          "GpioClxBankIdleConditionCallback",(char)lVar3,(char)param_2);
    }
    if (*(int *)(lVar5 + 0x160) == 1) {
      PoFxSetComponentLatency(*(undefined8 *)(lVar3 + 0x118),uVar4,*(undefined8 *)(lVar5 + 0x168));
      PoFxSetComponentResidency(*(undefined8 *)(lVar3 + 0x118),uVar4,*(undefined8 *)(lVar5 + 0x170))
      ;
    }
  }
  PoFxCompleteIdleCondition(*(undefined8 *)(lVar3 + 0x118),uVar4);
  return;
}



===== GpioClxBankIdleStateCallback @ 140015ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxBankIdleStateCallback(undefined8 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(lVar3 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar3 + 300) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if ((char)iVar2 == '\0') {
    GpiopProcessBankIdleStateTransition
              ((longlong *)((ulonglong)param_2 * 400 + *(longlong *)(lVar3 + 0x2e0)),param_3,0);
  }
  PoFxCompleteIdleState(*(undefined8 *)(lVar3 + 0x118),(ulonglong)param_2);
  return;
}



===== GpioClxCriticalTransitionCallback @ 140015b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxCriticalTransitionCallback(undefined8 param_1,uint param_2,char param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(lVar3 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar3 + 300) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if ((char)iVar2 == '\0') {
    GpiopProcessBankIdleStateTransition
              ((longlong *)((ulonglong)param_2 * 400 + *(longlong *)(lVar3 + 0x2e0)),
               (uint)(param_3 == '\0'),1);
  }
  return;
}



===== GpioClxDevicePowerNotRequiredCallback @ 140015be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxDevicePowerNotRequiredCallback(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(lVar3 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar3 + 300) = 0;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if ((char)iVar2 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0xdb8))
              (WdfDriverGlobals,param_1,0,0x21d,"onecore\\drivers\\gpio\\gpioclx\\sys\\power.c");
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(lVar3 + 0x298),4,3,0xe,
                         &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                         "GpioClxDevicePowerNotRequiredCallback",(char)lVar3);
    }
  }
  PoFxCompleteDevicePowerNotRequired(*(undefined8 *)(lVar3 + 0x118));
  return;
}



===== GpioClxDevicePowerRequiredCallback @ 140015cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxDevicePowerRequiredCallback(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x138));
  return;
}



===== GpiopDevicePowerD0TransitionWorker @ 140015d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDevicePowerD0TransitionWorker(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar6;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_GPIO_DEVICE_POWER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e1b8);
  lVar2 = *plVar5;
  iVar4 = 0;
  LOCK();
  iVar1 = *(int *)(lVar2 + 300);
  if (iVar1 == 0) {
    *(int *)(lVar2 + 300) = 0;
  }
  else {
    iVar4 = iVar1;
  }
  UNLOCK();
  if ((char)iVar4 == '\0') {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x2c8),1,0,CONCAT44(uVar6,0x19c),
                       "onecore\\drivers\\gpio\\gpioclx\\sys\\power.c");
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqD(*(undefined8 *)(lVar2 + 0x298),4,3,0xc,
                          &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                          "GpiopDevicePowerD0TransitionWorker",(char)lVar2,uVar3);
    }
  }
  PoFxReportDevicePoweredOn(*(undefined8 *)(lVar2 + 0x118));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(lVar2 + 0x298),4,3,0xd,
                       &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                       "GpiopDevicePowerD0TransitionWorker",(char)lVar2);
  }
  return;
}



===== GpiopInitializeDevicePowerWorker @ 140015e50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopInitializeDevicePowerWorker(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_20 = *(undefined8 *)(param_1 + 0x2c8);
  local_2c = 0;
  local_18 = 0;
  local_10 = PTR__WDF_GPIO_DEVICE_POWER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e1b8;
  pcStack_50 = GpiopDevicePowerD0TransitionWorker;
  local_3c = 0;
  uStack_34 = 0;
  local_40 = 0x38;
  local_28 = 1;
  local_24 = 1;
  local_58 = 0x18;
  local_48 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                    (WdfDriverGlobals,&local_58,&local_40,(undefined8 *)(param_1 + 0x138));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0x10,
                         &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                         "GpiopInitializeDevicePowerWorker",(char)iVar1);
    }
  }
  else {
    plVar2 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x138),
                        PTR__WDF_GPIO_DEVICE_POWER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e1b8);
    *plVar2 = param_1;
  }
  return iVar1;
}



===== GpiopInitializeDxIdlePowerPolicy @ 140015f8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopInitializeDxIdlePowerPolicy(longlong param_1)

{
  int iVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((*(uint *)(param_1 + 0x314) & 8) == 0) {
    iVar1 = 0;
  }
  else {
    local_1c = 0;
    local_38 = 0x24;
    local_28 = 2;
    local_2c = 0;
    if (*(int *)(param_1 + 0x310) != 0) {
      local_2c = *(int *)(param_1 + 0x310);
    }
    local_34 = 1;
    local_20 = 1;
    local_24 = 2;
    local_18 = 2;
    local_30 = 4;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x170))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),&local_38);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,2,0xf,
                         &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                         "GpiopInitializeDxIdlePowerPolicy",(char)iVar1);
    }
  }
  return iVar1;
}



===== GpiopProcessBankIdleStateTransition @ 14001609c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpiopProcessBankIdleStateTransition(longlong *param_1,int param_2,byte param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  bool bVar3;
  byte bVar4;
  code *pcVar5;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined2 uVar9;
  bool bVar10;
  undefined1 auStackY_b8 [32];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 in_stack_ffffffffffffff70;
  undefined8 local_68;
  uint local_60;
  ulonglong local_58;
  uint local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar2 = param_1[0x11];
  if (param_3 == 0) {
LAB_1400160ef:
    bVar3 = true;
  }
  else {
    bVar4 = KeGetCurrentIrql();
    bVar3 = false;
    if (bVar4 < 0xf) goto LAB_1400160ef;
  }
  lVar6 = param_1[0x11];
  if (((*(byte *)(lVar6 + 4) & 2) != 0) &&
     (puVar1 = (undefined8 *)(lVar6 + 0x268), (code *)*puVar1 != (code *)0x0)) {
    lVar6 = lVar6 + 0x400;
    (*(code *)*puVar1)(lVar6,(short)param_1[0x10],param_2);
  }
  if ((param_2 == 0) && (param_3 == 0)) {
    GpiopSetInterruptState(lVar6,*param_1,'\x01');
    GpiopSetInterruptState(lVar6,param_1[1],'\x01');
  }
  if (bVar3) {
    lVar6 = *param_1;
    if (lVar6 == 0) {
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e0);
      lVar6 = param_1[3];
    }
    else {
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x480);
    }
    (*pcVar5)(WdfDriverGlobals,lVar6);
    param_1[4] = (longlong)SystemReserved1[0xf];
  }
  bVar4 = *(byte *)(param_1 + 0x2a);
  uVar7 = (ulonglong)bVar4;
  bVar10 = true;
  if (param_2 == 1) {
    if (param_3 == 0) {
      if ((bVar4 != 0) || (*(char *)((longlong)param_1 + 0x151) != '\0')) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,3,0,uVar7);
      }
      *(undefined1 *)(param_1 + 0x2a) = 1;
LAB_14001621d:
      local_68 = 0;
      local_60 = local_60 & 0xffff0000;
      pcVar5 = *(code **)(param_1[0x11] + 0x1e8);
      if (pcVar5 != (code *)0x0) {
        local_60 = param_3 & 1;
        local_68 = CONCAT44(1,(uint)*(ushort *)(param_1 + 0x10));
        uVar7 = param_1[0x11] + 0x400;
        (*pcVar5)(uVar7,&local_68);
      }
    }
    else {
      if (*(char *)((longlong)param_1 + 0x151) != '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,3,param_3,uVar7);
      }
      bVar10 = bVar4 == 0;
      *(undefined1 *)((longlong)param_1 + 0x151) = 1;
      if (bVar4 == 0) goto LAB_14001621d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016392;
    uVar9 = 0x11;
  }
  else {
    if (param_3 == 0) {
      if ((bVar4 == 0) || (*(char *)((longlong)param_1 + 0x151) != '\0')) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,4,0,uVar7);
      }
      *(undefined1 *)(param_1 + 0x2a) = 0;
LAB_1400162ff:
      local_58 = 0;
      local_50 = local_50 & 0xffff0000;
      pcVar5 = *(code **)(param_1[0x11] + 0x1f0);
      if (pcVar5 != (code *)0x0) {
        local_50 = param_3 & 1;
        local_58 = (ulonglong)*(ushort *)(param_1 + 0x10);
        uVar7 = param_1[0x11] + 0x400;
        (*pcVar5)(uVar7,&local_58);
      }
    }
    else {
      if (*(char *)((longlong)param_1 + 0x151) == '\0') {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,4,param_3,uVar7);
      }
      bVar10 = bVar4 == 0;
      *(undefined1 *)((longlong)param_1 + 0x151) = 0;
      if (bVar4 == 0) goto LAB_1400162ff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016392;
    uVar9 = 0x12;
  }
  pcVar8 = "Ignored";
  uVar7 = *(ulonglong *)(lVar2 + 0x298);
  if (bVar10) {
    pcVar8 = "Called";
  }
  WPP_RECORDER_SF_ssqDd
            (uVar7,pcVar8,"Called",uVar9,in_stack_ffffffffffffff68,in_stack_ffffffffffffff70,pcVar8,
             (char)lVar2,(char)param_1[0x10],param_3);
LAB_140016392:
  *(int *)((longlong)param_1 + 0x15c) = param_2;
  if (bVar3) {
    lVar6 = *param_1;
    param_1[4] = 0;
    if (lVar6 == 0) {
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x9e8);
      lVar6 = param_1[3];
    }
    else {
      pcVar5 = *(code **)(WdfFunctions_01015 + 0x488);
    }
    uVar7 = WdfDriverGlobals;
    (*pcVar5)(WdfDriverGlobals,lVar6);
  }
  if ((param_2 == 1) && (param_3 == 0)) {
    GpiopSetInterruptState(uVar7,*param_1,'\0');
    GpiopSetInterruptState(uVar7,param_1[1],'\0');
  }
  lVar6 = param_1[0x11];
  if (((*(byte *)(lVar6 + 4) & 2) != 0) && (*(code **)(lVar6 + 0x270) != (code *)0x0)) {
    (**(code **)(lVar6 + 0x270))(lVar6 + 0x400,(short)param_1[0x10],param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqDd(*(undefined8 *)(lVar2 + 0x298));
  }
  return;
}



===== WPP_RECORDER_SF_sqDd @ 140016480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDd(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,0x13,
               "GpiopProcessBankIdleStateTransition",0x24,&uStack0000000000000038,8,
               &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,0x13,
                  "GpiopProcessBankIdleStateTransition",0x24,&uStack0000000000000038,8,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_ssqDd @ 1400165a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssqDd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,char *param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_7[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,param_4,
               "GpiopProcessBankIdleStateTransition",0x24,pcVar1,lVar3,&param_8,8,&param_9,4,
               &param_10,4,0);
  }
  lVar3 = -1;
  if (param_7 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_7[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  WppAutoLogTrace(param_1,4,3,&WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,param_4,
                  "GpiopProcessBankIdleStateTransition",0x24,param_7,lVar2,&param_8,8,&param_9,4,
                  &param_10,4,0);
  return;
}



===== GpioHalDisableInterrupt @ 140016774 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpioHalDisableInterrupt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_98 [32];
  undefined4 local_78 [2];
  undefined4 local_70;
  undefined1 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined8 local_58;
  undefined2 local_50;
  undefined4 local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  memset(local_78,0,0x60);
  local_68 = 3;
  local_78[0] = 1;
  local_58 = 1;
  local_70 = 0;
  local_50 = 0;
  local_64 = param_3;
  local_60 = param_2;
  local_38 = param_1;
  HalDisableInterrupt(local_78);
  return;
}



===== GpiopExAllocateTimerInternal @ 140016818 =====

void GpiopExAllocateTimerInternal(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  undefined2 local_res18;
  undefined2 local_res1a;
  
  local_res18 = 0xb;
  local_res1a = param_3;
  Ordinal_4(param_1,param_2,&local_res18,6);
  return;
}



===== GpiopGetBaseRegistrationBufferSize @ 140016850 =====

undefined8 GpiopGetBaseRegistrationBufferSize(void)

{
  return 0x70;
}



===== GpiopInitializeIdleStateBufferAndCount @ 140016860 =====

void GpiopInitializeIdleStateBufferAndCount
               (longlong param_1,uint param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined8 *)((ulonglong)param_2 * 0x20 + 0x68 + param_1) = param_3;
  *(undefined4 *)(((ulonglong)param_2 + 3) * 0x20 + param_1) = param_4;
  return;
}



===== GpiopInitializePrimaryDevice @ 140016880 =====

void GpiopInitializePrimaryDevice(undefined4 *param_1,undefined4 param_2)

{
  undefined8 in_stack_00000048;
  
  *(undefined8 *)(param_1 + 0xe) = 0;
  *param_1 = 1;
  param_1[2] = 1;
  *(code **)(param_1 + 8) = GpioClxBankIdleStateCallback;
  *(code **)(param_1 + 4) = GpioClxBankActiveConditionCallback;
  *(code **)(param_1 + 6) = GpioClxBankIdleConditionCallback;
  *(code **)(param_1 + 10) = GpioClxDevicePowerRequiredCallback;
  *(code **)(param_1 + 0xc) = GpioClxDevicePowerNotRequiredCallback;
  *(undefined8 *)(param_1 + 0x12) = in_stack_00000048;
  *(code **)(param_1 + 0x10) = GpioClxCriticalTransitionCallback;
  param_1[1] = param_2;
  return;
}



===== GpiopQueryEmOverrides @ 1400168e8 =====

uint GpiopQueryEmOverrides(void)

{
  int iVar1;
  uint uVar2;
  int local_res8 [2];
  
  uVar2 = 0;
  local_res8[0] = 1;
  iVar1 = EmClientQueryRuleState(&GPIO_EM_RULE_SOFT_FAIL_ACPI_EVENT_MASK_GUID,local_res8);
  if ((-1 < iVar1) && (uVar2 = 0, local_res8[0] == 2)) {
    uVar2 = 1;
  }
  iVar1 = EmClientQueryRuleState(&GPIO_EM_RULE_INTERRUPT_STORM_MITIGATION_GUID,local_res8);
  if ((-1 < iVar1) && (local_res8[0] == 2)) {
    uVar2 = uVar2 | 2;
  }
  return uVar2;
}



===== GpiopRegisterPrimaryDeviceInternal @ 14001695c =====

void GpiopRegisterPrimaryDeviceInternal(void)

{
  PoFxRegisterPrimaryDevice();
  return;
}



===== GpioUtilUpdatePinValue @ 140016978 =====

void GpioUtilUpdatePinValue(longlong param_1,ushort param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x88) + 0xe0;
  uVar2 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x88) + 0x2d6);
  if (param_4 == '\0') {
    if (param_2 == 0xffff) {
      RtlClearBits(lVar1,*(ushort *)(param_1 + 0x80) * uVar2,*(undefined2 *)(param_1 + 0x180));
    }
    else {
      RtlClearBit(lVar1,*(ushort *)(param_1 + 0x80) * uVar2 + (uint)param_2);
    }
  }
  else if (param_2 == 0xffff) {
    RtlSetBits(lVar1,*(ushort *)(param_1 + 0x80) * uVar2,*(undefined2 *)(param_1 + 0x180));
  }
  else {
    RtlSetBit(lVar1,*(ushort *)(param_1 + 0x80) * uVar2 + (uint)param_2);
  }
  return;
}



===== RtlStringCbPrintfExA @ 140016a2c =====

int RtlStringCbPrintfExA
              (char *param_1,ulonglong param_2,size_t *param_3,ulonglong *param_4,uint param_5,
              char *param_6,char param_7)

{
  undefined8 uVar1;
  int iVar2;
  size_t *psVar3;
  char *pcVar4;
  ulonglong uVar5;
  char *local_58;
  size_t local_50 [2];
  
  iVar2 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar2 = 0;
    if (0x7ffffffe < param_2 - 1) {
      iVar2 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (char *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (param_2 == 0) {
      return iVar2;
    }
    *param_1 = '\0';
    return iVar2;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (char *)0x0)) {
    param_6 = "";
  }
  iVar2 = 0;
  psVar3 = param_3;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      pcVar4 = param_1;
      uVar5 = param_2;
      if (*param_6 == '\0') goto LAB_140016b15;
      iVar2 = (-(uint)(param_1 != (char *)0x0) & 0xbffffff8) + 0xc000000d;
      local_58 = param_1;
      local_50[0] = param_2;
    }
    else {
      local_50[0] = 0;
      local_58 = (char *)0x0;
      psVar3 = local_50;
      uVar1 = RtlStringVPrintfWorkerA(param_1,param_2,psVar3,param_6,&param_7);
      iVar2 = (int)uVar1;
      uVar5 = param_2 - local_50[0];
      pcVar4 = param_1 + local_50[0];
      local_58 = pcVar4;
      local_50[0] = uVar5;
      if (-1 < iVar2) {
        if (((param_5 >> 9 & 1) != 0) && (1 < uVar5)) {
          memset(pcVar4 + 1,param_5 & 0xff,uVar5 - 1);
        }
        goto LAB_140016b15;
      }
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    local_58 = param_1;
    local_50[0] = param_2;
    if (param_2 != 0) {
      *param_1 = '\0';
      local_58 = param_1;
      local_50[0] = param_2;
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    RtlStringExHandleOtherFlagsA(param_1,param_2,psVar3,&local_58,local_50,param_5);
  }
  pcVar4 = local_58;
  uVar5 = local_50[0];
  if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x7ffffffb)) {
    return iVar2;
  }
LAB_140016b15:
  if (param_3 != (size_t *)0x0) {
    *param_3 = (size_t)pcVar4;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar5;
  }
  return iVar2;
}



===== WPP_RECORDER_SF_Ds @ 140016bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ds(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0x16,&uStack0000000000000030,4,
               pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,7,&WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0x16,
                  &uStack0000000000000030,4,in_stack_00000038,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sDDDD @ 140016d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0xe,
               "GpioUtilEnumerateNamespaceChildren",0x23,&uStack0000000000000038,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,0xb,&WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0xe,
                  "GpioUtilEnumerateNamespaceChildren",0x23,&uStack0000000000000038,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sSSD @ 140016e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSSD(void)

{
  undefined8 uVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  wchar_t *in_stack_00000038;
  undefined1 uStack0000000000000048;
  
  uVar1 = GpioLogHandle;
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000038[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0x11,"GpioUtilQueryRegistryFlags",
               0x1b,pwVar3,lVar2,L"Parameters",0x16,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000038[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(uVar1,2,1,&WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,0x11,
                  "GpioUtilQueryRegistryFlags",0x1b,in_stack_00000038,lVar4,L"Parameters",0x16,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sSSSD @ 140017018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sSSSD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,wchar_t *param_7,undefined8 param_8,
               wchar_t *param_9,undefined1 param_10)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  
  uVar1 = GpioLogHandle;
  lVar6 = -1;
  lVar5 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_9 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_9[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar7 = param_9;
    if (param_9 == (wchar_t *)0x0) {
      pwVar7 = L"NULL";
    }
    if (param_7 == (wchar_t *)0x0) {
      lVar3 = 10;
    }
    else {
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (param_7[lVar3] != L'\0');
      lVar3 = lVar3 * 2 + 2;
    }
    pwVar4 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,param_4,"GpioUtilQueryRegistryFlags"
               ,0x1b,pwVar4,lVar3,L"Parameters",0x16,pwVar7,lVar2,&param_10,4,0);
  }
  if (param_9 == (wchar_t *)0x0) {
    lVar2 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_9[lVar2] != L'\0');
    lVar2 = lVar2 * 2 + 2;
  }
  if (param_9 == (wchar_t *)0x0) {
    param_9 = L"NULL";
  }
  if (param_7 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (param_7[lVar6] != L'\0');
    lVar5 = lVar6 * 2 + 2;
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"NULL";
  }
  WppAutoLogTrace(uVar1,param_2,1,&WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,param_4,
                  "GpioUtilQueryRegistryFlags",0x1b,param_7,lVar5,L"Parameters",0x16,param_9,lVar2,
                  &param_10,4,0);
  return;
}



===== RtlStringExHandleOtherFlagsA @ 140017250 =====

undefined8
RtlStringExHandleOtherFlagsA
          (undefined1 *param_1,size_t param_2,undefined8 param_3,undefined8 *param_4,size_t *param_5
          ,uint param_6)

{
  if ((param_2 != 0) && ((param_6 & 0x1000) != 0)) {
    *param_4 = param_1;
    *param_5 = param_2;
    *param_1 = 0;
  }
  if ((param_6 & 0x400) != 0) {
    memset(param_1,param_6 & 0xff,param_2);
    if ((char)param_6 != '\0') {
      if (param_2 == 0) {
        return 0;
      }
      *param_5 = 1;
      *param_4 = param_1 + (param_2 - 1);
      param_1[param_2 - 1] = 0;
      goto LAB_1400172b7;
    }
    *param_4 = param_1;
    *param_5 = param_2;
  }
  if (param_2 == 0) {
    return 0;
  }
LAB_1400172b7:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = param_2;
    *param_1 = 0;
  }
  return 0;
}



===== RtlStringLengthWorkerA @ 14001730c =====

uint RtlStringLengthWorkerA(char *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != '\0')); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = param_2 - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlStringLengthWorkerW @ 140017350 =====

uint RtlStringLengthWorkerW(short *param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0x7fff;
  do {
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = 0x7fff - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlStringVPrintfWorkerA @ 140017398 =====

undefined8
RtlStringVPrintfWorkerA
          (char *param_1,longlong param_2,size_t *param_3,char *param_4,va_list param_5)

{
  int iVar1;
  ulonglong uVar2;
  size_t _Count;
  undefined8 uVar3;
  
  _Count = param_2 - 1;
  uVar3 = 0;
  iVar1 = _vsnprintf(param_1,_Count,param_4,param_5);
  if (-1 < iVar1) {
    uVar2 = (ulonglong)iVar1;
    if (uVar2 <= _Count) {
      if (uVar2 == _Count) {
        param_1[_Count] = '\0';
      }
      else {
        _Count = uVar2;
      }
      goto LAB_1400173ec;
    }
  }
  param_1[_Count] = '\0';
  uVar3 = 0x80000005;
LAB_1400173ec:
  if (param_3 != (size_t *)0x0) {
    *param_3 = _Count;
  }
  return uVar3;
}



===== RtlUnicodeStringInitWorker @ 140017414 =====

uint RtlUnicodeStringInitWorker(short *param_1,short *param_2)

{
  uint uVar1;
  longlong local_res18 [2];
  
  uVar1 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 != (short *)0x0) {
    local_res18[0] = 0;
    uVar1 = RtlStringLengthWorkerW(param_2,param_2,local_res18);
    if (-1 < (int)uVar1) {
      if (param_1 == (short *)0x0) {
        uVar1 = 0xc000000d;
      }
      else {
        *(short **)(param_1 + 4) = param_2;
        *param_1 = (short)local_res18[0] * 2;
        param_1[1] = (short)local_res18[0] * 2 + 2;
      }
    }
  }
  return uVar1;
}



===== FxStubDriverUnloadCommon @ 14001747c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001e2a8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14001e2a8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1400174d5:
      if (ppvVar1 == (void **)0x0) goto LAB_14001752b;
      if (ppvVar2 <= ppvVar1) goto LAB_140017543;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1400174d5;
LAB_14001752b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_140017543:
  WdfVersionUnbind(&DAT_14001e5e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140017580 =====

void entry(_WDF_BIND_INFO *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3,param_4);
  return;
}



===== FxDriverEntryWorker @ 1400175b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,longlong param_2,undefined8 param_3,
                             undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2,param_3,param_4);
  }
  else {
    _DAT_14001e5e0 = 0x2080000;
    _DAT_14001e5e8 = &DAT_14001e370;
    RtlCopyUnicodeString(&DAT_14001e5e0);
    puVar6 = &WdfDriverGlobals;
    puVar5 = &WdfBindInfo;
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_14001e5e0);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar3 = DriverEntry(param_1,param_2,puVar5,puVar6);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14001e578 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar3 & 0xffffffff,
                   &DAT_14001e5e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001e2a8 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
      uVar3 = (ulonglong)uVar1;
    }
  }
  return uVar3;
}



===== FxStubDriverUnload @ 140017740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14001e578 != (code *)0x0) && (DAT_14001e578 != FxStubDriverUnload)) {
    (*DAT_14001e578)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140017774 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140017799) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001e29f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14001e2a8 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1400178fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140017919) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001e2bf < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== __security_check_cookie @ 1400179d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140017a10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140017a40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140017a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140017a70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140017ac0 =====

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



===== memset @ 140017dc0 =====

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



===== __memset_repmovs @ 140017f00 =====

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



===== __memset_query @ 140017f80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140018000 =====

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



===== __memset_spec_ermsb_repmovsb @ 140018140 =====

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



===== __memset_spec_plain @ 1400181c0 =====

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



===== memcmp @ 1400182e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140018323;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140018394;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140018390:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140018394;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001838c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140018390;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001838c;
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
LAB_140018394:
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
LAB_140018323:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== GpiopAllocateAcpiEventResources @ 140023008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopAllocateAcpiEventResources(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  ulonglong local_40 [5];
  undefined8 uStack_18;
  undefined8 local_10;
  
  uVar1 = *(ushort *)(param_1 + 0x2d4);
  local_40[0] = (ulonglong)(uint)local_40[0];
  local_58 = (ulonglong)(uint)local_58;
  lVar3 = ExAllocatePool2(0x40,uVar1 + 0x1f >> 3 & 0x1ffffffc,0x786c4347);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,0xb,0x13,
                        &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                        "GpiopAllocateAcpiEventResources");
    }
    iVar2 = -0x3fffff66;
  }
  else {
    RtlInitializeBitMap(param_1 + 0xe0,lVar3,uVar1);
    local_48 = 0;
    local_58 = 0x18;
    pcStack_50 = GpiopProcessAcpiEventsDpc;
    local_10 = 0;
    local_40[2] = 0;
    local_40[3] = 0x100000001;
    local_40[4] = *(undefined8 *)(param_1 + 0x2c8);
    uStack_18 = 0;
    local_40[1] = 0;
    local_40[0] = 0x38;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x378))
                      (WdfDriverGlobals,&local_58,local_40,param_1 + 0x10);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,0xb,0x14,
                           &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                           "GpiopAllocateAcpiEventResources",(char)iVar2);
      }
    }
    else {
      *(undefined8 *)(param_1 + 0x18) = 0;
      *(byte *)(param_1 + 0xfc) = *(byte *)(param_1 + 0xfc) | 2;
      *(code **)(param_1 + 0x28) = GpiopProcessAcpiEventsWorker;
      *(longlong *)(param_1 + 0x30) = param_1;
    }
  }
  return iVar2;
}



===== GpiopBuildEdgeLevelPinList @ 1400231b8 =====

ulonglong GpiopBuildEdgeLevelPinList
                    (longlong param_1,longlong *param_2,undefined4 *param_3,undefined4 *param_4,
                    uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  longlong lVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  uint local_58;
  uint local_54;
  int local_50 [2];
  longlong local_48;
  longlong local_40;
  
  local_54 = 0;
  local_58 = 0;
  local_40 = 0;
  local_50[0] = 0;
  uVar2 = GpioUtilEnumerateNamespaceChildren(param_1,&local_40,local_50);
  lVar6 = local_40;
  iVar1 = local_50[0];
  uVar3 = (ulonglong)uVar2;
  uVar9 = (undefined1)param_1;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400234fa;
    uVar8 = 0x15;
  }
  else {
    if (local_40 == 0) goto LAB_140023311;
    if (local_50[0] == 0) {
      uVar3 = 0xc0140008;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400234fa;
      uVar8 = 0x18;
      uVar2 = 0xc0140008;
    }
    else {
      uVar2 = *(uint *)(local_40 + 4);
      pbVar5 = (byte *)(local_40 + 8);
      uVar7 = 1;
      if (1 < uVar2) {
        do {
          pbVar5 = pbVar5 + (ulonglong)*(uint *)(pbVar5 + 4) + 8;
          if ((((*pbVar5 & 1) == 0) && (4 < *(uint *)(pbVar5 + 4))) &&
             (*(int *)(pbVar5 + (ulonglong)(*(uint *)(pbVar5 + 4) - 5) + 8) == 0x5456455f)) break;
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
      }
      if (uVar7 == uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x17;
          goto LAB_1400232ee;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xc0) = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x16;
LAB_1400232ee:
          WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xb,uVar8,
                             &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                             "GpiopBuildEdgeLevelPinList",uVar9);
        }
      }
LAB_140023311:
      uVar3 = GpioUtilParseNamespaceEventPins(lVar6,iVar1,0,0,&local_54,0,0,&local_58);
      uVar7 = local_54;
      uVar2 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (((uVar2 + 0x80000000 & 0x80000000) != 0) || (uVar2 == 0xc0000023)) {
        uVar4 = (ulonglong)local_54;
        uVar3 = 0;
        if (local_58 + local_54 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),4,0xb,0x1e,
                              &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                              "GpiopBuildEdgeLevelPinList");
          }
          lVar6 = 0;
        }
        else {
          local_48 = ExAllocatePool2(0x100,(ulonglong)(local_58 + local_54) << 2,0x786c4347);
          if (local_48 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),2,0xb,0x1f,
                                 &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                                 "GpiopBuildEdgeLevelPinList",uVar9);
            }
            uVar3 = 0xc000009a;
            goto LAB_1400234fa;
          }
          if (uVar7 == 0) {
            lVar6 = local_48;
            if (local_58 == 0) goto LAB_1400234d3;
          }
          uVar4 = GpioUtilParseNamespaceEventPins
                            (local_40,local_50[0],local_48,uVar7,&local_54,local_48 + uVar4 * 4,
                             local_58,&local_58);
          uVar3 = uVar4 & 0xffffffff;
          if ((int)uVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),2,0xb,0x20,
                                  &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                                  "GpiopBuildEdgeLevelPinList",uVar9,(char)uVar4);
            }
            ExFreePoolWithTag(local_48,0x786c4347);
            goto LAB_1400234fa;
          }
          lVar6 = local_48;
          uVar7 = local_54;
        }
LAB_1400234d3:
        *param_2 = lVar6;
        *param_5 = uVar7;
        *param_6 = local_58;
        *param_3 = 0;
        *param_4 = 0;
        goto LAB_1400234fa;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400234fa;
      uVar8 = 0x1c;
    }
  }
  WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),2,0xb,uVar8,
                      &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,"GpiopBuildEdgeLevelPinList",
                      uVar9,(char)uVar2);
LAB_1400234fa:
  if (local_40 != 0) {
    ExFreePoolWithTag(local_40,0x786c4347);
  }
  return uVar3;
}



===== GpiopDestroyAcpiEventing @ 140023530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDestroyAcpiEventing(longlong param_1,char param_2)

{
  if (*(longlong *)(param_1 + 0xe8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0xe8),0x786c4347);
    *(undefined8 *)(param_1 + 0xe8) = 0;
  }
  if (*(longlong *)(param_1 + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 200),0x786c4347);
    *(undefined8 *)(param_1 + 200) = 0;
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    PoUnregisterPowerSettingCallback();
    *(undefined8 *)(param_1 + 0xf0) = 0;
  }
  if ((param_2 == '\0') && (*(longlong *)(param_1 + 0x68) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0x786c4347);
    *(undefined8 *)(param_1 + 0x68) = 0;
  }
  return;
}



===== GpiopInitiateAcpiEventing @ 140023608 =====

int GpiopInitiateAcpiEventing(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong lVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  iVar2 = GpioUtilEvaluateAcpiMethod
                    (*(undefined8 *)(param_1 + 0x2c8),0x4945415f,(int *)0x0,&local_res18,local_res8)
  ;
  lVar4 = local_res18;
  if (iVar2 == -0x3fffffcc) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),4,0xb,0xb,
                         &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)param_1,0x34);
    }
LAB_140023696:
    lVar4 = local_res18;
    lVar6 = 0;
  }
  else {
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,0xb,0xc,
                          &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)iVar2);
      }
      goto LAB_140023696;
    }
    if (local_res18 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffff;
      }
      uVar5 = 0xd;
LAB_1400236fa:
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x298),4,0xb,uVar5,
                       &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids);
      return -0x3fffffff;
    }
    iVar2 = GpiopParseEventInformation(param_1,local_res18,local_res8[0],&local_res20,local_res10);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,0xb,0xe,
                          &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)iVar2);
      }
      lVar6 = local_res20;
    }
    else {
      ExFreePoolWithTag(lVar4,0x786c4347);
      lVar6 = local_res20;
      lVar4 = 0;
      if (local_res20 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffffff;
        }
        uVar5 = 0xf;
        goto LAB_1400236fa;
      }
      uVar3 = GpiopBuildEdgeLevelPinList
                        (param_1,(longlong *)(param_1 + 200),(undefined4 *)(param_1 + 0xd0),
                         (undefined4 *)(param_1 + 0xd4),(uint *)(param_1 + 0xd8),
                         (uint *)(param_1 + 0xdc));
      uVar1 = local_res10[0];
      iVar2 = (int)uVar3;
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qD(*(undefined8 *)(param_1 + 0x298),4,0xb,0x10,
                             &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)param_1,
                             (char)uVar3);
        }
        goto LAB_14002392e;
      }
      iVar2 = GpiopValidateMethodsForEvents(param_1,lVar6,local_res10[0]);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,0xb,0x11,
                            &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)iVar2);
        }
        goto LAB_14002392e;
      }
      *(uint *)(param_1 + 0x70) = uVar1;
      *(longlong *)(param_1 + 0x68) = lVar6;
      iVar2 = PoRegisterPowerSettingCallback
                        (0,&GUID_PDC_IDLE_RESILIENCY_ENGAGED,GpiopPowerAcpiEventingCallback,param_1,
                         (undefined8 *)(param_1 + 0xf0));
      if (-1 < iVar2) {
        return iVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,0xb,0x12,
                          &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,(char)iVar2);
      }
      *(undefined8 *)(param_1 + 0xf0) = 0;
    }
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x786c4347);
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_14002392e:
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x786c4347);
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return iVar2;
}



===== GpiopParseEventInformation @ 140023968 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140023bae) */
/* WARNING: Removing unreachable block (ram,0x000140023b38) */
/* WARNING: Removing unreachable block (ram,0x000140023ba7) */
/* WARNING: Removing unreachable block (ram,0x000140023c35) */
/* WARNING: Removing unreachable block (ram,0x000140023c2c) */
/* WARNING: Removing unreachable block (ram,0x000140023b5f) */
/* WARNING: Removing unreachable block (ram,0x000140023b6f) */
/* WARNING: Removing unreachable block (ram,0x000140023b9d) */

int GpiopParseEventInformation
              (longlong param_1,longlong param_2,uint param_3,undefined8 *param_4,
              undefined4 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  
  if (param_3 < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3febfff1;
    }
    uVar3 = 0x22;
  }
  else {
    if (*(short *)(param_2 + 0xc) == 2) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c02c);
      if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x7ffffffb)) {
        return iVar1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),4,0xb,0x24,
                          &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                          "GpiopParseEventInformation");
      }
      *param_4 = 0;
      *param_5 = 0;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3febfff1;
    }
    uVar3 = 0x23;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,1,uVar3,
                    &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,"GpiopParseEventInformation");
  return -0x3febfff1;
}



===== GpiopValidateEventMethodForPin @ 140023c7c =====

uint GpiopValidateEventMethodForPin(longlong param_1,int param_2,ushort param_3,undefined1 *param_4)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(int *)(param_1 + 0xd0) + *(int *)(param_1 + 0xd8);
  if (param_2 == 1) {
    uVar5 = uVar4;
    uVar4 = 0;
  }
  else {
    uVar5 = *(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0xd4) + uVar4;
  }
  bVar1 = 0;
  if (uVar4 < uVar5) {
    puVar3 = (uint *)(*(longlong *)(param_1 + 200) + (ulonglong)uVar4 * 4);
    uVar2 = uVar4;
    do {
      if ((uint)param_3 == *puVar3) {
        *param_4 = 0;
        bVar1 = 1;
        if (param_2 == 1) {
          if (uVar2 - uVar4 < *(uint *)(param_1 + 0xd8)) goto LAB_140023d05;
        }
        else if ((param_2 != 0) || (uVar2 - uVar4 < *(uint *)(param_1 + 0xdc))) goto LAB_140023d05;
        goto LAB_140023d03;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < uVar5);
  }
  if ((*(char *)(param_1 + 0xc0) != '\0') && (*(char *)(param_1 + 0xc1) == '\0')) {
LAB_140023d03:
    bVar1 = 1;
    *param_4 = 1;
  }
LAB_140023d05:
  return ~-(uint)bVar1 & 0xc0000001;
}



===== GpiopValidateMethodsForEvents @ 140023d58 =====

undefined4 GpiopValidateMethodsForEvents(longlong param_1,longlong param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 0xc0000001;
  if ((7 < param_3) && (param_2 != 0)) {
    uVar2 = *(uint *)(param_2 + 4);
    uVar4 = (ulonglong)uVar2;
    if ((uVar2 != 0) && (uVar2 * 0x20 + 8 <= param_3)) {
      bVar3 = false;
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          cVar1 = *(char *)((ulonglong)uVar6 * 0x20 + 9 + param_2);
          if (cVar1 == '\x02') {
            bVar3 = true;
            *(undefined2 *)((ulonglong)uVar6 * 0x20 + 0xe + param_2) = 0;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar4,0xb,0x2c,
                                &WPP_98e0bcb7cc36391bac739c91f4727ee1_Traceguids,
                                "GpiopValidateMethodsForEvents",(char)uVar6,cVar1);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(param_2 + 4));
        uVar5 = 0xc0000001;
        if (bVar3) {
          uVar5 = 0;
        }
      }
    }
  }
  return uVar5;
}



===== GpioClxEvtDeviceContextCleanup @ 140023e50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtDeviceContextCleanup(longlong param_1)

{
  longlong lVar1;
  longlong ****pppplVar2;
  
  if (param_1 == GpioHubDevice) {
    GpioHubpUninitialize();
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar1 + 0x298),4,2,0x26,
                       &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids);
    }
    pppplVar2 = (longlong ****)GpioHubpFindGpioEntry(2,(ushort *)(lVar1 + 0x2f8),(undefined8 *)0x0);
    if (pppplVar2 != (longlong ****)0x0) {
      GpioHubpDeleteGpioEntry(pppplVar2);
    }
    GpiopDeleteDeviceExtension(lVar1);
    if (((*(byte *)(lVar1 + 4) & 2) != 0) && (*(code **)(lVar1 + 0x290) != (code *)0x0)) {
      (**(code **)(lVar1 + 0x290))(*(undefined8 *)(lVar1 + 0x2c8));
    }
  }
  return;
}



===== GpioClxEvtDeviceFileCreate @ 140023f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpioClxEvtDeviceFileCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  short *psVar8;
  undefined7 extraout_var;
  void *_Dst;
  undefined1 auStackY_c8 [32];
  byte local_88;
  byte local_87;
  byte local_86;
  char local_85;
  longlong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar1 = false;
  local_78 = 0;
  local_86 = 0;
  local_88 = 0;
  local_87 = 0;
  local_80 = 0;
  local_85 = '\0';
  local_70 = param_3;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  iVar4 = 0;
  LOCK();
  iVar5 = *(int *)(lVar7 + 300);
  if (iVar5 == 0) {
    *(int *)(lVar7 + 300) = 0;
  }
  else {
    iVar4 = iVar5;
  }
  UNLOCK();
  if ((char)iVar4 == '\0') {
    iVar5 = (**(code **)(WdfFunctions_01015 + 0xdb0))(WdfDriverGlobals,param_1,1,0);
    if (-1 < iVar5) {
      local_68 = CONCAT62(local_68._2_6_,0x28);
      bVar1 = true;
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
      psVar8 = (short *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_3);
      if ((psVar8 == (short *)0x0) || (*psVar8 == 0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = GpioUtilGetIdFromFileName(psVar8,&local_78);
        uVar2 = local_78;
        if (-1 < (int)uVar6) {
          uVar6 = GpiopQueryBankIdFromGsivOrConnectionId
                            (lVar7,0,local_78,&local_80,&local_88,&local_86);
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(lVar7 + 0x298),2,5,0x16,
                                &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)uVar6);
            }
          }
          else {
            cVar3 = GpioUtilGetOpenModeFromRequest((longlong)&local_68,local_88,&local_87);
            iVar5 = (int)CONCAT71(extraout_var,cVar3);
            if (iVar5 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(lVar7 + 0x298),2,5,
                                  (short)CONCAT71(extraout_var,cVar3) + 0x17,
                                  &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,0);
              }
              uVar6 = 0xc000000d;
            }
            else {
              PoFxActivateComponent
                        (*(undefined8 *)(lVar7 + 0x118),*(undefined2 *)(local_80 + 0x80),0);
              local_85 = '\x01';
              _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                                       (WdfDriverGlobals,local_70,
                                        PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160);
              memset(_Dst,0,0x68);
              uVar6 = ((uint)local_87 ^ *(uint *)((longlong)_Dst + 100)) & 1 ^
                      *(uint *)((longlong)_Dst + 100);
              *(uint *)((longlong)_Dst + 100) = uVar6;
              *(undefined2 *)((longlong)_Dst + 0x18) = *(undefined2 *)(local_80 + 0x80);
              *(longlong *)((longlong)_Dst + 0x10) = lVar7;
              *(int *)((longlong)_Dst + 0x1c) = iVar5;
              *(undefined8 *)((longlong)_Dst + 0x50) = uVar2;
              *(void **)((longlong)_Dst + 8) = _Dst;
              *(void **)_Dst = _Dst;
              *(uint *)((longlong)_Dst + 100) = ((uint)local_86 << 3 ^ uVar6) & 8 ^ uVar6;
              uVar6 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                                (WdfDriverGlobals,param_2,*(undefined8 *)(local_80 + 0x58));
              if (-1 < (int)uVar6) {
                return;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DD(*(undefined8 *)(lVar7 + 0x298),2,5,0x18,
                                   &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                                   (char)*(undefined2 *)(local_80 + 0x80),(char)uVar6);
              }
            }
          }
        }
      }
      goto LAB_1400242c0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(lVar7 + 0x298),2,5,0x15,
                        &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)iVar5);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar7 + 0x298),2,5,0x14,
                     &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids);
  }
  uVar6 = 0xc0000001;
LAB_1400242c0:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
  if (local_85 != '\0') {
    PoFxIdleComponent(*(undefined8 *)(lVar7 + 0x118),*(undefined2 *)(local_80 + 0x80),0);
  }
  if (bVar1) {
    (**(code **)(WdfFunctions_01015 + 0xdb8))(WdfDriverGlobals,param_1,0,0x4be);
  }
  return;
}



===== GpioClxEvtDevicePrepareHardware @ 140024370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpioClxEvtDevicePrepareHardware(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  LOCK();
  *(undefined4 *)(lVar2 + 0x2d0) = 3;
  UNLOCK();
  lVar4 = lVar2 + 0x400;
  uVar1 = (**(code **)(lVar2 + 0x168))(param_1,lVar4,param_2,param_3);
  uVar5 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dq(*(undefined8 *)(lVar2 + 0x298),lVar4,2,10,
                         &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)uVar1,(char)lVar2);
    }
  }
  else {
    uVar1 = GpiopQueryControllerInformation(lVar2);
    uVar5 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400244c2;
      uVar6 = 0xb;
    }
    else {
      uVar1 = GpiopInitializeDxIdlePowerPolicy(lVar2);
      uVar5 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400244c2;
        uVar6 = 0xc;
      }
      else {
        uVar3 = GpiopInitializeBanksAndInterrupts(lVar2,param_3,param_2);
        uVar5 = uVar3 & 0xffffffff;
        if (-1 < (int)uVar3) {
          GpiopManageAcpiEventing(lVar2,1,'\0');
          LOCK();
          *(undefined4 *)(lVar2 + 0x2d0) = 5;
          UNLOCK();
          return uVar5;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400244c2;
        uVar6 = 0xd;
      }
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(lVar2 + 0x298),2,2,uVar6,
                      &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)uVar5);
  }
LAB_1400244c2:
  LOCK();
  *(undefined4 *)(lVar2 + 0x2d0) = 4;
  UNLOCK();
  *(int *)(lVar2 + 0x144) = (int)uVar5;
  return uVar5;
}



===== GpioClxEvtDeviceSelfManagedIoFlush @ 140024510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtDeviceSelfManagedIoFlush(undefined8 param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  uVar3 = 0;
  if (*(short *)(lVar1 + 0x2d8) != 0) {
    do {
      (**(code **)(WdfFunctions_01015 + 0x520))
                (WdfDriverGlobals,*(undefined8 *)(uVar3 * 400 + 0x58 + *(longlong *)(lVar1 + 0x2e0))
                );
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(ushort *)(lVar1 + 0x2d8));
  }
  if (*(longlong *)(lVar1 + 0x118) != 0) {
    PoFxUnregisterDevice();
    *(undefined8 *)(lVar1 + 0x118) = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(lVar1 + 0x298),4,3,0x18,
                      &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                      "GpiopUnregisterWithPowerFramework");
  }
  return;
}



===== GpioClxEvtFileClose @ 140024610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined ** GpioClxEvtFileClose(undefined8 param_1)

{
  uint uVar1;
  short *psVar2;
  undefined **ppuVar3;
  longlong *plVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  undefined8 uVar7;
  
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  psVar2 = (short *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_1);
  ppuVar3 = (undefined **)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar7,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  ppuVar5 = ppuVar3;
  if ((psVar2 != (short *)0x0) && (*psVar2 != 0)) {
    plVar4 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    if (plVar4 == (longlong *)0x0) {
      ppuVar5 = &WPP_RECORDER_INITIALIZED;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        ppuVar5 = (undefined **)
                  WPP_RECORDER_SF_(ppuVar3[0x53],2,5,0x19,
                                   &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids);
      }
    }
    else if ((*(uint *)((longlong)plVar4 + 100) & 8) == 0) {
      uVar7 = GpiopDisconnectGpioPins((longlong)ppuVar3,plVar4,'\0');
      if (((int)uVar7 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_D(ppuVar3[0x53],2,5,0x1b,&WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                          (char)uVar7);
      }
      ppuVar5 = (undefined **)0x0;
      LOCK();
      uVar1 = *(uint *)(plVar4 + 0xc);
      if (uVar1 == 0) {
        *(uint *)(plVar4 + 0xc) = 0;
      }
      else {
        ppuVar5 = (undefined **)(ulonglong)uVar1;
      }
      UNLOCK();
      if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,0xb,ppuVar3,plVar4,0);
      }
    }
    else {
      ppuVar6 = (undefined **)GpiopDisconnectFunctionConfigPins((longlong)ppuVar3,plVar4);
      ppuVar5 = ppuVar6;
      if (((int)ppuVar6 < 0) &&
         (ppuVar5 = &WPP_RECORDER_INITIALIZED,
         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        ppuVar5 = (undefined **)
                  WPP_RECORDER_SF_D(ppuVar3[0x53],2,5,0x1a,
                                    &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)ppuVar6);
      }
    }
  }
  return ppuVar5;
}



===== GpioClxClassLibraryBindClient @ 1400247e0 =====

undefined8 GpioClxClassLibraryBindClient(longlong param_1)

{
  if (*(int *)(param_1 + 0x28) == 6) {
    if (*(int *)(param_1 + 0x14) == 0) {
      memmove(*(void **)(param_1 + 0x20),&GpioClxExports,0x30);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd();
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(GpioLogHandle,&DAT_14001a84c,1,10,
                      &WPP_7a904fd07a903c99ae3b7ea3fe2bc9c4_Traceguids,
                      (char)*(int *)(param_1 + 0x28));
  }
  return 0xc000000d;
}



===== GpioClxClassLibraryDeinitialize @ 140024890 =====

void GpioClxClassLibraryDeinitialize(void)

{
  return;
}



===== GpioClxClassLibraryInitialize @ 1400248a0 =====

undefined8 GpioClxClassLibraryInitialize(void)

{
  return 0;
}



===== GpiopClassLibraryCreate @ 1400248ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GpiopClassLibraryCreate(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 auStack_148 [48];
  longlong local_118;
  ushort local_110 [4];
  undefined1 *local_108;
  undefined1 local_f8 [208];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  local_108 = local_f8;
  local_110[0] = 0;
  local_110[1] = 200;
  local_110[2] = 0;
  local_110[3] = 0;
  bVar1 = false;
  local_118 = (**(code **)(WdfFunctions_01015 + 200))
                        (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
  if (local_118 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar5 = 0;
    do {
      uVar3 = RtlUnicodeStringPrintf(local_110,L"%s%d",L"\\Device\\MSGpioClassExt",(ulonglong)uVar5)
      ;
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_140024a0c;
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_118,local_110);
      uVar4 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_140024a0c;
      uVar2 = (**(code **)(WdfFunctions_01015 + 600))
                        (WdfDriverGlobals,&local_118,0,&GpioClxClassLibraryDevice);
      uVar5 = uVar5 + 1;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 == 0xc0000035);
    if (-1 < (int)uVar2) {
      bVar1 = true;
      (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,GpioClxClassLibraryDevice);
      uVar5 = WdfRegisterClassLibrary(&GpioClxClassLibraryInformation,param_2,local_110);
      uVar4 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        return uVar4;
      }
    }
  }
LAB_140024a0c:
  if (GpioClxClassLibraryDevice != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,GpioClxClassLibraryDevice);
    GpioClxClassLibraryDevice = 0;
  }
  if ((local_118 != 0) && (!bVar1)) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  return uVar4;
}



===== GpioClxProcessAddDevicePostDeviceCreate @ 140024aa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioClxProcessAddDevicePostDeviceCreate(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined1 auStackY_c8 [32];
  undefined8 local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48 [4];
  
  local_48[3] = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_48[2] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  puVar2 = GpiopFindClient(param_1);
  if (puVar2 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(GpioLogHandle,2,2,0xf,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids);
    }
    iVar1 = -0x3ffffff3;
  }
  else {
    if (puVar2[3] != 0) {
      ExFreePoolWithTag(puVar2[3],0x786c4347);
      puVar2[3] = 0;
    }
    local_58 = 0;
    local_68 = 0x38;
    local_48[0] = local_48[0] & 0xffffffffffffff00;
    local_48[2] = 0x200000002;
    uStack_50 = CONCAT44(0x10,(undefined4)uStack_50);
    uStack_50 = uStack_50 & 0xffffffffffffff00;
    uStack_60 = 0xc800002000;
    LOCK();
    UNLOCK();
    uVar7 = GpioLogHandleInstance + 1;
    GpioLogHandleInstance = GpioLogHandleInstance + 1;
    RtlStringCbPrintfA((char *)local_48,0x10,"GPIO_%d",(ulonglong)uVar7);
    puVar5 = WPP_GLOBAL_Control;
    iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_68,&local_88);
    if (iVar1 < 0) {
      local_88 = GpioLogHandle;
    }
    iVar1 = GpiopBuildDeviceExtension(puVar5,param_2,(longlong)puVar2,local_88);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar6 = 0x10;
      uVar4 = local_88;
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_2);
        (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals);
        WPP_RECORDER_SF_qqq(*(undefined8 *)(lVar3 + 0x298));
      }
      GpiopManageAcpiEventing(lVar3,0,'\0');
      iVar1 = GpiopSetupPrimaryDeviceIoQueue(lVar3);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar6 = 0x12;
      }
      else {
        iVar1 = GpiopSetupSelfIoTarget(param_2,lVar3);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar6 = 0x13;
        }
        else {
          iVar1 = GpiopQueryDeviceBiosName(param_2,lVar3);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar1;
            }
            uVar6 = 0x14;
          }
          else {
            local_80 = lVar3 + 0x2e8;
            local_78 = lVar3 + 0x2f8;
            local_70 = lVar3;
            uVar4 = GpioHubpRegisterGpioDevice(&local_80);
            iVar1 = (int)uVar4;
            if (-1 < iVar1) {
              return iVar1;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar1;
            }
            uVar6 = 0x15;
          }
        }
      }
      uVar4 = *(undefined8 *)(lVar3 + 0x298);
    }
    WPP_RECORDER_SF_D(uVar4,2,2,uVar6,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== GpioClxProcessAddDevicePreDeviceCreate @ 140024db0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpioClxProcessAddDevicePreDeviceCreate
                    (longlong param_1,longlong *param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  ulonglong *puVar8;
  undefined1 auStackY_1d8 [32];
  undefined8 local_190;
  wchar_t *local_188;
  undefined4 local_180;
  undefined4 local_17c;
  code *local_178;
  code *local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined4 local_15c;
  ulonglong local_158 [6];
  undefined *local_128;
  undefined4 local_118;
  undefined4 local_114;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_d8;
  code *local_d0;
  code *local_a8;
  wchar_t local_88 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1d8;
  builtin_wcsncpy(local_88,L"D:P(A;;GA;;;SY)(A;;GA;;;BA)(A;;G",0x20);
  local_17c = 0;
  local_114 = 0;
  local_158[0] = (ulonglong)(uint)local_158[0];
  local_188 = local_88;
  builtin_wcsncpy(local_88 + 0x20,L"A;;;UD)",8);
  local_190 = 0x50004e;
  puVar2 = GpiopFindClient(param_1);
  if (puVar2 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(GpioLogHandle,2,2,10,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids);
    }
    return 0xc000000d;
  }
  memset(&local_118,0,0x90);
  local_118 = 0x90;
  local_a8 = GpioClxEvtDeviceQueryStop;
  local_f0 = GpioClxEvtDevicePrepareHardware;
  local_e8 = GpioClxEvtDeviceReleaseHardware;
  local_110 = GpioClxEvtDeviceD0Entry;
  local_100 = GpioClxEvtDeviceD0Exit;
  local_f8 = GpioClxEvtDevicePreInterruptsDisabled;
  local_108 = GpioClxEvtDevicePostInterruptsEnabled;
  local_d0 = GpioClxEvtDeviceSelfManagedIoInit;
  local_d8 = GpioClxEvtDeviceSelfManagedIoFlush;
  if ((3 < *(ushort *)(puVar2 + 4)) && ((*(uint *)((longlong)puVar2 + 0x24) & 1) != 0)) {
    MmLockPagableDataSection(GpioClxEvtProcessWriteRequest);
    (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,param_2);
  }
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,&local_118);
  local_168 = 0;
  puVar8 = local_158;
  local_178 = GpioClxEvtDeviceFileCreate;
  puVar6 = &local_180;
  local_180 = 0x28;
  local_158[2] = 0;
  local_15c = 0x80000004;
  local_170 = GpioClxEvtFileClose;
  local_128 = PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160;
  local_158[1] = 0;
  local_160 = 2;
  local_158[4] = 0;
  local_158[5] = 0;
  local_158[0] = 0x38;
  local_158[3] = 0x400000001;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,param_2);
  plVar4 = puVar2 + 3;
  uVar3 = GpiopAssignTargetName(param_2,plVar4,puVar6,puVar8);
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar7 = 0xb;
  }
  else {
    plVar4 = param_2;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x220))(WdfDriverGlobals,param_2,&local_190);
    uVar5 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                        (WdfDriverGlobals,param_2,GpioClxWdmPreprocessPowerIrp,0x16);
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar3;
        }
        uVar7 = 0xd;
      }
      else {
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                          (WdfDriverGlobals,param_2,GpioClxWdmPreprocessQueryDeviceRelationsIrp,0x1b
                          );
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,param_2,2);
          *param_3 = 0;
          param_3[1] = 0;
          param_3[2] = 0;
          param_3[3] = 0;
          param_3[4] = 0;
          param_3[5] = 0;
          param_3[6] = 0;
          *(undefined4 *)((longlong)param_3 + 0x1c) = 1;
          *(undefined4 *)param_3 = 0x38;
          *(undefined4 *)(param_3 + 3) = 1;
          param_3[6] = PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190;
          param_3[1] = GpioClxEvtDeviceContextCleanup;
          *(undefined4 *)((longlong)param_3 + 0x1c) = 2;
          uVar3 = (ulonglong)(*(int *)(puVar2 + 5) + 0x400U);
          if (*(int *)(puVar2 + 5) + 0x400U < 0x440) {
            uVar3 = 0x440;
          }
          param_3[5] = uVar3;
          return 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar3;
        }
        uVar7 = 0xe;
      }
      WPP_RECORDER_SF_sD(GpioLogHandle,2,2,uVar7,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                         "GpioClxProcessAddDevicePreDeviceCreate",(char)uVar3);
      return uVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar7 = 0xc;
  }
  WPP_RECORDER_SF_Dq(GpioLogHandle,plVar4,2,uVar7,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                     (char)uVar5,(char)param_2);
  return uVar5;
}



===== GpioClxRegisterClient @ 140025230 =====

ulonglong GpioClxRegisterClient(longlong param_1,ushort *param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (((param_1 == 0) || (param_2 == (ushort *)0x0)) || (param_3 == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    uVar1 = GpiopCreateClient(param_1,param_2);
    uVar2 = uVar1 & 0xffffffff;
    if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(GpioLogHandle,2,1,0x16,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                        (char)uVar1);
    }
  }
  return uVar2;
}



===== GpioClxUnregisterClient @ 1400252a0 =====

undefined8 GpioClxUnregisterClient(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  
  uVar6 = 0xc0000225;
  ExAcquireFastMutex(&GpioClientGlobalListLock);
  plVar4 = GpioClientDriverList;
  do {
    plVar5 = (longlong *)0x0;
    if ((longlong **)plVar4 == &GpioClientDriverList) {
LAB_1400252ea:
      ExReleaseFastMutex(&GpioClientGlobalListLock);
      if (plVar5 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar5,0x786c4347);
      }
      return uVar6;
    }
    if (plVar4[2] == param_1) {
      plVar5 = plVar4;
      if (plVar4 != (longlong *)0x0) {
        lVar1 = *plVar4;
        if ((*(longlong **)(lVar1 + 8) != plVar4) ||
           (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 != plVar4)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          uVar6 = (*pcVar3)();
          return uVar6;
        }
        *plVar2 = lVar1;
        uVar6 = 0;
        *(longlong **)(lVar1 + 8) = plVar2;
      }
      goto LAB_1400252ea;
    }
    plVar4 = (longlong *)*plVar4;
  } while( true );
}



===== GpiopAssignTargetName @ 14002535c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopAssignTargetName
                    (undefined8 param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  ushort local_18 [4];
  longlong lStack_10;
  
  uVar3 = 0x32;
  lVar1 = ExAllocatePool2(0x40,0x32,0x786c4347);
  if (lVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(GpioLogHandle,uVar3,2,0x1f,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                        0x32);
    }
    uVar4 = 0xc000009a;
  }
  else {
    local_18[0] = 0;
    local_18[1] = 0x32;
    local_18[2] = 0;
    local_18[3] = 0;
    LOCK();
    UNLOCK();
    uVar5 = GpioInstanceNumber + 1;
    GpioInstanceNumber = GpioInstanceNumber + 1;
    lStack_10 = lVar1;
    uVar2 = RtlUnicodeStringPrintf(local_18,L"\\Device\\GPIO_%d",(ulonglong)uVar5,param_4);
    uVar4 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,param_1,local_18);
      uVar4 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        *param_2 = lVar1;
        return uVar4;
      }
    }
    ExFreePoolWithTag(lVar1,0x786c4347);
  }
  return uVar4;
}



===== GpiopOpenResourceHubTarget @ 140025470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopOpenResourceHubTarget(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  
  memset(&local_98,0,0x88);
  local_res8 = 0;
  local_c8 = 0;
  local_a8 = 0;
  uStack_d0 = 0;
  local_d8 = 0x38;
  uStack_b0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  uStack_c0 = 0x100000001;
  local_b8 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,&local_d8,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400255d1;
    uVar2 = 0x23;
  }
  else {
    RtlInitUnicodeString(&local_e8,L"\\Device\\RESOURCE_HUB");
    local_68 = (undefined4)local_e8;
    uStack_64 = local_e8._4_4_;
    uStack_60 = (undefined4)uStack_e0;
    uStack_5c = uStack_e0._4_4_;
    local_98 = 0x88;
    local_94 = 2;
    local_58 = 0x1f0000;
    local_48 = 0x40;
    local_4c = 1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_res8,&local_98);
    if (-1 < iVar1) {
      *param_2 = local_res8;
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400255d1;
    uVar2 = 0x24;
  }
  WPP_RECORDER_SF_D(GpioLogHandle,2,2,uVar2,&WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,
                    (char)iVar1);
LAB_1400255d1:
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== GpiopQueryDeviceBiosName @ 14002561c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopQueryDeviceBiosName(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  ushort uVar4;
  uint uVar5;
  undefined8 local_res18;
  undefined8 local_38;
  longlong lStack_30;
  uint local_28;
  undefined4 local_24;
  
  local_res18 = 0;
  local_28 = 0;
  local_38 = 0;
  lStack_30 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  uVar5 = 0x80;
  while( true ) {
    uVar4 = (ushort)uVar5;
    lVar3 = ExAllocatePool2(0x40,uVar5,0x786c4347);
    if (lVar3 == 0) {
      return -0x3fffff66;
    }
    local_24 = 0;
    local_38 = 1;
    lStack_30 = lVar3;
    local_28 = uVar5;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar2,0,0x32c024,0,&local_38,0,&local_res18);
    if (iVar1 != -0x3fffffdd) break;
    if (0x7fff < uVar4) {
      iVar1 = -0x3ffffdfa;
      goto LAB_140025727;
    }
    uVar5 = (uint)(ushort)(uVar4 * 2);
    ExFreePoolWithTag(lVar3,0x786c4347);
  }
  if (-1 < iVar1) {
    *(ushort *)(param_2 + 0x2fa) = uVar4;
    *(short *)(param_2 + 0x2f8) = (short)local_res18 + -2;
    *(longlong *)(param_2 + 0x300) = lVar3;
    return iVar1;
  }
LAB_140025727:
  ExFreePoolWithTag(lVar3,0x786c4347);
  return iVar1;
}



===== GpiopSetupPrimaryDeviceIoQueue @ 14002578c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopSetupPrimaryDeviceIoQueue(longlong param_1)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5b;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined4 local_18;
  
  local_res8 = 0;
  memset(&local_68,0,0x60);
  local_18 = 0xffffffff;
  local_50 = GpioClxEvtProcessWriteRequest;
  local_68 = 0x60;
  local_98 = 0;
  local_60 = 2;
  local_48 = GpioClxEvtProcessWriteRequest;
  uStack_a0 = 0;
  local_5b = 1;
  local_40 = GpioClxEvtProcessDeviceIoControl;
  local_38 = GpioClxEvtProcessInternalDeviceIoControl;
  local_78 = 0;
  local_64 = 2;
  local_88 = 0;
  uStack_80 = 0;
  local_a8 = 0x38;
  uStack_90 = 0x300000002;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),&local_68,&local_a8,
                     &local_res8);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,2,0x20,
                      &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== GpiopSetupSelfIoTarget @ 1400258bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopSetupSelfIoTarget(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_78;
  
  local_a8 = 0;
  local_c8 = 0;
  uStack_d0 = 0;
  local_d8 = 0x38;
  uStack_b0 = 0;
  uStack_c0 = 0x100000001;
  local_b8 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))
                    (WdfDriverGlobals,param_1,&local_d8,(undefined8 *)(param_2 + 0x108));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x21;
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals);
    memset(&local_98,0,0x88);
    local_98 = 0x88;
    local_94 = 1;
    local_78 = uVar2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x108),&local_98);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x22;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(param_2 + 0x298),2,2,uVar3,
                    &WPP_d5b056417c7538ee6e8937bc98488864_Traceguids,(char)iVar1);
  return iVar1;
}



===== GpioClnInvokeConnectFunctionConfigPins @ 140025a24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GpioClnInvokeConnectFunctionConfigPins
          (longlong param_1,undefined8 param_2,ushort param_3,longlong param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  ulonglong local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  longlong local_18;
  ulonglong uStack_10;
  
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x88) + 0x218);
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_38 = (ulonglong)*(ushort *)(param_1 + 0x80);
    local_28._0_4_ = (uint)param_3;
    local_28 = (ulonglong)CONCAT24(*(undefined2 *)(param_4 + 7),(uint)local_28);
    uStack_20 = (ulonglong)*(byte *)(param_4 + 6);
    local_18 = 0;
    uStack_10 = 0;
    if (*(ushort *)(param_4 + 0x10) != 0) {
      local_18 = (ulonglong)*(ushort *)(param_4 + 0xe) + param_4;
      uStack_10 = (ulonglong)*(ushort *)(param_4 + 0x10);
    }
    uStack_30 = param_2;
    uVar2 = (*pcVar1)(*(longlong *)(param_1 + 0x88) + 0x400,&local_38);
  }
  return uVar2;
}



===== GpioClnInvokeDisconnectFunctionConfigPins @ 140025acc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GpioClnInvokeDisconnectFunctionConfigPins
          (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined2 local_28;
  undefined4 local_26;
  undefined2 local_22;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x88) + 0x220);
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_28 = *(undefined2 *)(param_1 + 0x80);
    local_26 = 0;
    local_22 = 0;
    local_20 = param_2;
    local_18 = param_3;
    local_14 = param_4;
    uVar2 = (*pcVar1)(*(longlong *)(param_1 + 0x88) + 0x400,&local_28);
  }
  return uVar2;
}



===== GpioClnInvokeEnableInterrupt @ 140025b3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
GpioClnInvokeEnableInterrupt
          (longlong param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
          longlong param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x88);
  if (*(longlong *)(lVar1 + 0x198) == 0) {
    uVar2 = 0xc00000bb;
  }
  else {
    local_38 = *(undefined2 *)(param_1 + 0x80);
    local_34 = 0;
    local_18 = 0;
    local_28 = 0;
    lStack_20 = 0;
    if (param_5 != 0) {
      if ((*(uint *)(lVar1 + 0x314) & 0x20) == 0) {
        local_28 = (ulonglong)*(ushort *)(param_5 + 0xc) << 0x10;
      }
      local_28 = CONCAT71(local_28._1_7_,*(undefined1 *)(param_5 + 9));
      if (*(ushort *)(param_5 + 0x15) != 0) {
        lStack_20 = (ulonglong)*(ushort *)(param_5 + 0x13) + param_5;
        local_18 = (ulonglong)*(ushort *)(param_5 + 0x15);
      }
    }
    local_36 = param_2;
    local_30 = param_3;
    local_2c = param_4;
    if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
      McTemplateK0zhh_EtwWriteTransfer
                (param_5,&EVENT_ENABLE_INTERRUPT_START,param_1 + 0x70,*(wchar_t **)(lVar1 + 0x300),
                 (char)local_38,(char)param_2);
    }
    lVar3 = lVar1 + 0x400;
    uVar2 = (**(code **)(lVar1 + 0x198))(lVar3,&local_38);
    if ((Microsoft_Windows_GPIO_ClassExtensionEnableBits & 1) != 0) {
      McTemplateK0h_EtwWriteTransfer(lVar3,&EVENT_ENABLE_INTERRUPT_COMPLETE,param_1 + 0x70,param_2);
    }
  }
  return uVar2;
}



===== GpioClxEvtDriverUnload @ 140025c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  GpiopUninitialize();
  if (GpioClxClassLibraryDevice != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    GpioClxClassLibraryDevice = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(GpioLogHandle,4,1,0xe,&WPP_022c81e08a523bbb1bab82949e8d2f03_Traceguids);
  }
  if (GpioLogHandle != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    GpioLogHandle = 0;
  }
  WppCleanupKm(uVar1);
  McGenEventUnregister_EtwUnregister();
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



===== WppCleanupKm @ 140025d88 =====

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



===== WppInitKm @ 140025e38 =====

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



===== WppLoadTracingSupport @ 140025f14 =====

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



===== WppTraceCallback @ 140026060 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1400262e8 =====

/* WARNING: Removing unreachable block (ram,0x000140026310) */
/* WARNING: Removing unreachable block (ram,0x000140026320) */
/* WARNING: Removing unreachable block (ram,0x000140026325) */
/* WARNING: Removing unreachable block (ram,0x00014002632a) */
/* WARNING: Removing unreachable block (ram,0x000140026335) */
/* WARNING: Removing unreachable block (ram,0x00014002634a) */
/* WARNING: Removing unreachable block (ram,0x000140026340) */
/* WARNING: Removing unreachable block (ram,0x00014002635a) */
/* WARNING: Removing unreachable block (ram,0x000140026377) */
/* WARNING: Removing unreachable block (ram,0x000140026386) */
/* WARNING: Removing unreachable block (ram,0x00014002638b) */
/* WARNING: Removing unreachable block (ram,0x00014002637d) */
/* WARNING: Removing unreachable block (ram,0x00014002638d) */
/* WARNING: Removing unreachable block (ram,0x000140026392) */
/* WARNING: Removing unreachable block (ram,0x000140026382) */
/* WARNING: Removing unreachable block (ram,0x000140026315) */
/* WARNING: Removing unreachable block (ram,0x00014002631e) */
/* WARNING: Removing unreachable block (ram,0x00014002639d) */
/* WARNING: Removing unreachable block (ram,0x0001400263a2) */
/* WARNING: Removing unreachable block (ram,0x000140026394) */
/* WARNING: Removing unreachable block (ram,0x0001400263c5) */
/* WARNING: Removing unreachable block (ram,0x0001400263a4) */
/* WARNING: Removing unreachable block (ram,0x0001400263be) */
/* WARNING: Removing unreachable block (ram,0x0001400263c3) */
/* WARNING: Removing unreachable block (ram,0x0001400263b5) */
/* WARNING: Removing unreachable block (ram,0x0001400263ba) */
/* WARNING: Removing unreachable block (ram,0x000140026399) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400263d8 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_140026470;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140026470;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_140026470:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400264c0 =====

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
      for (plVar2 = &wil_details_featureDescriptors_a; plVar2 < &wil_details_featureDescriptors_a;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_14001d1c7 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140026540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_14002663d;
  }
LAB_140026646:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14002663d:
  if (plVar3 == (longlong *)0x0) goto LAB_140026646;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14002660e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14002660e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14001d1c7 < plVar3) goto LAB_140026646;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14002663d;
}



===== GpiopAllocateDebounceResources @ 14002666c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopAllocateDebounceResources
              (longlong param_1,longlong param_2,undefined2 param_3,longlong *param_4,
              undefined8 *param_5,longlong *param_6)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *_Dst;
  longlong lVar3;
  longlong lVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int iVar7;
  longlong local_a8 [2];
  code *pcStack_98;
  ulonglong local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined *local_58;
  
  lVar4 = *(longlong *)(param_1 + 0x88);
  local_a8[0] = 0;
  local_58 = (undefined *)((ulonglong)local_58 & 0xffffffff00000000);
  local_90 = local_90 & 0xffffffff00000000;
  plVar1 = (longlong *)0x0;
  local_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  lVar3 = 0;
  _Dst = (longlong *)0x0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  iVar7 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a8[1] = 0;
  pcStack_98 = (code *)0x0;
  if ((*(uint *)(lVar4 + 0x314) & 1) == 0) {
    uStack_70 = 0x100000001;
    uStack_84 = 0;
    uStack_80 = 0;
    uStack_7c = 0;
    local_78 = 0;
    uStack_74 = 0;
    uStack_60 = 0;
    local_88 = 0x38;
    local_68 = *(undefined8 *)(lVar4 + 0x2c8);
    local_58 = PTR__WDF_GPIO_DEBOUNCE_NOISE_TIMER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e070;
    pcStack_98 = GpioClxEvtDebounceNoiseFilterExpirationWorker;
    local_a8[1] = 0x18;
    local_90 = 0;
    iVar7 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,local_a8 + 1,&local_88,local_a8);
    if (-1 < iVar7) {
      plVar1 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_a8[0],
                          PTR__WDF_GPIO_DEBOUNCE_NOISE_TIMER_WORK_ITEM_CONTEXT_TYPE_INFO_14001e070);
      plVar1[1] = 0;
      plVar1[2] = 0;
      plVar1[3] = 0;
      *plVar1 = param_1;
      goto LAB_1400267ae;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x9c;
LAB_1400267f7:
      WPP_RECORDER_SF_sD(*(undefined8 *)(lVar4 + 0x298),2,8,uVar5,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopAllocateDebounceResources",(char)iVar7);
    }
  }
  else {
LAB_1400267ae:
    plVar1 = (longlong *)ExAllocatePool2(0x40);
    if (plVar1 == (longlong *)0x0) {
      iVar7 = -0x3fffffe9;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x9d;
        iVar7 = -0x3fffffe9;
        goto LAB_1400267f7;
      }
    }
    else {
      lVar2 = GpiopExAllocateTimerInternal(GpioClxEvtDebounceTimerHandler,plVar1,0);
      if (lVar2 == 0) {
        iVar7 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0x9e;
LAB_140026861:
          iVar7 = -0x3fffff66;
          uVar6 = 0x9a;
LAB_140026869:
          WPP_RECORDER_SF_sD(*(undefined8 *)(lVar4 + 0x298),2,8,uVar5,
                             &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                             "GpiopAllocateDebounceResources",uVar6);
        }
      }
      else {
        _Dst = (longlong *)ExAllocatePool2(0x40,0x40,0x786c4347);
        if (_Dst == (longlong *)0x0) {
          iVar7 = -0x3fffffe9;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar5 = 0x9f;
            uVar6 = 0x17;
            goto LAB_140026869;
          }
        }
        else {
          lVar3 = GpiopExAllocateTimerInternal(GpioClxEvtNoiseFilterTimerHandler,_Dst,1);
          if (lVar3 == 0) {
            iVar7 = -0x3fffff66;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar5 = 0xa0;
              goto LAB_140026861;
            }
          }
          else {
            *(undefined4 *)((longlong)plVar1 + 10) = 0;
            *(undefined2 *)((longlong)plVar1 + 0xe) = 0;
            plVar1[4] = 0;
            *(undefined2 *)(plVar1 + 1) = param_3;
            plVar1[2] = param_2;
            *plVar1 = param_1;
            plVar1[3] = lVar2;
            plVar1[4] = local_a8[0];
            memset(_Dst,0,0x40);
            _Dst[2] = param_2;
            *_Dst = param_1;
            *(undefined2 *)(_Dst + 1) = param_3;
            _Dst[4] = lVar3;
            _Dst[5] = local_a8[0];
            if (-1 < iVar7) {
              lVar4 = local_a8[0];
              goto LAB_140026a24;
            }
          }
        }
      }
      ExFreePoolWithTag(plVar1,0x786c4347);
      plVar1 = (longlong *)0x0;
      if (_Dst != (longlong *)0x0) {
        ExFreePoolWithTag(_Dst,0x786c4347);
      }
      if (lVar2 != 0) {
        ExDeleteTimer(lVar2,1,0,0);
      }
      if (lVar3 != 0) {
        ExDeleteTimer(lVar3,1,0,0);
      }
    }
  }
  _Dst = (longlong *)0x0;
  lVar4 = 0;
  if (local_a8[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_a8[0]);
    lVar4 = 0;
  }
LAB_140026a24:
  *param_4 = (longlong)plVar1;
  *param_5 = _Dst;
  *param_6 = lVar4;
  return iVar7;
}



===== GpiopBuildDeviceExtension @ 140026a58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopBuildDeviceExtension
              (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  void *_Dst;
  void *_Dst_00;
  undefined8 *puVar3;
  ushort uVar4;
  longlong local_res8;
  ulonglong local_78;
  void *pvStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = local_38 & 0xffffffff00000000;
  local_78 = 0;
  pvStack_70 = (void *)0x0;
  local_res8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,param_2,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  memset(_Dst,0,0x440);
  *(undefined4 *)((longlong)_Dst + 0x2c0) = 0x4f495047;
  *(undefined8 *)((longlong)_Dst + 0x2c8) = param_2;
  *(undefined8 *)((longlong)_Dst + 0x298) = param_4;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_res8);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x140))(WdfDriverGlobals,param_2,local_res8);
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res8,&local_78);
    }
  }
  if ((pvStack_70 == (void *)0x0) || (uVar1 = (ushort)local_78, (ushort)local_78 < 3)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)((longlong)_Dst + 0x298),2,1,0x95,
                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
    }
    iVar2 = -0x3fffffff;
  }
  else {
    uVar4 = (ushort)local_78 + 2;
    _Dst_00 = (void *)ExAllocatePool2(0x100,uVar4,0x786c4347);
    if (_Dst_00 == (void *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)((longlong)_Dst + 0x298),2,1,0x96,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
      }
      iVar2 = -0x3fffff66;
    }
    else {
      memmove(_Dst_00,pvStack_70,local_78 & 0xffff);
      puVar3 = &local_68;
      *(undefined2 *)((longlong)_Dst_00 + (ulonglong)(uVar4 >> 1) * 2 + -2) = 0;
      *(void **)((longlong)_Dst + 0x2f0) = _Dst_00;
      *(ushort *)((longlong)_Dst + 0x2e8) = uVar1;
      *(undefined1 *)((longlong)_Dst + 0x130) = 1;
      *(ushort *)((longlong)_Dst + 0x2ea) = uVar4;
      local_58 = 0;
      local_38 = 0;
      uStack_60 = 0;
      local_68 = 0x38;
      uStack_40 = 0;
      uStack_50 = 0x100000001;
      local_48 = param_2;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                        (WdfDriverGlobals,puVar3,(longlong)_Dst + 0x120);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)((longlong)_Dst + 0x298),puVar3,1,0x97,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)iVar2);
        }
      }
      else {
        iVar2 = GpiopInitializeDevicePowerWorker((longlong)_Dst);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)((longlong)_Dst + 0x298),2,1,0x98,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                               "GpiopBuildDeviceExtension",(char)iVar2);
          }
        }
        else {
          *(undefined4 *)((longlong)_Dst + 8) = 0xffffffff;
          *(undefined1 *)((longlong)_Dst + 6) = 3;
          memmove((undefined8 *)((longlong)_Dst + 0x150),(void *)(param_3 + 0x20),
                  (ulonglong)*(ushort *)(param_3 + 0x22));
          *(undefined8 *)((longlong)_Dst + 0x318) = *(undefined8 *)((longlong)_Dst + 0x150);
          *(undefined8 *)((longlong)_Dst + 800) = *(undefined8 *)((longlong)_Dst + 0x158);
          *(undefined8 *)((longlong)_Dst + 0x328) = *(undefined8 *)((longlong)_Dst + 0x160);
          *(undefined8 *)((longlong)_Dst + 0x330) = *(undefined8 *)((longlong)_Dst + 0x168);
          *(undefined8 *)((longlong)_Dst + 0x338) = *(undefined8 *)((longlong)_Dst + 0x170);
          *(undefined8 *)((longlong)_Dst + 0x340) = *(undefined8 *)((longlong)_Dst + 0x178);
          *(undefined8 *)((longlong)_Dst + 0x348) = *(undefined8 *)((longlong)_Dst + 0x180);
          *(undefined8 *)((longlong)_Dst + 0x350) = *(undefined8 *)((longlong)_Dst + 0x188);
          *(undefined8 *)((longlong)_Dst + 0x358) = *(undefined8 *)((longlong)_Dst + 400);
          *(undefined8 *)((longlong)_Dst + 0x360) = *(undefined8 *)((longlong)_Dst + 0x198);
          *(undefined8 *)((longlong)_Dst + 0x368) = *(undefined8 *)((longlong)_Dst + 0x1a0);
          *(undefined8 *)((longlong)_Dst + 0x370) = *(undefined8 *)((longlong)_Dst + 0x1a8);
          *(undefined8 *)((longlong)_Dst + 0x378) = *(undefined8 *)((longlong)_Dst + 0x1b0);
          *(undefined8 *)((longlong)_Dst + 0x380) = *(undefined8 *)((longlong)_Dst + 0x1b8);
          *(undefined8 *)((longlong)_Dst + 0x388) = *(undefined8 *)((longlong)_Dst + 0x1c0);
          *(undefined8 *)((longlong)_Dst + 0x390) = *(undefined8 *)((longlong)_Dst + 0x1c8);
          *(undefined8 *)((longlong)_Dst + 0x398) = *(undefined8 *)((longlong)_Dst + 0x1d0);
          *(undefined8 *)((longlong)_Dst + 0x3a0) = *(undefined8 *)((longlong)_Dst + 0x1d8);
          *(undefined8 *)((longlong)_Dst + 0x3a8) = *(undefined8 *)((longlong)_Dst + 0x1e0);
          *(undefined8 *)((longlong)_Dst + 0x3b0) = *(undefined8 *)((longlong)_Dst + 0x1e8);
          *(undefined8 *)((longlong)_Dst + 0x3b8) = *(undefined8 *)((longlong)_Dst + 0x1f0);
          *(undefined8 *)((longlong)_Dst + 0x3c0) = *(undefined8 *)((longlong)_Dst + 0x1f8);
          *(undefined4 *)((longlong)_Dst + 0x3c8) = *(undefined4 *)((longlong)_Dst + 0x200);
          *(undefined4 *)((longlong)_Dst + 0x3cc) = *(undefined4 *)((longlong)_Dst + 0x204);
          *(undefined4 *)((longlong)_Dst + 0x3d0) = *(undefined4 *)((longlong)_Dst + 0x208);
          *(undefined4 *)((longlong)_Dst + 0x3d4) = *(undefined4 *)((longlong)_Dst + 0x20c);
          *(undefined4 *)((longlong)_Dst + 0x3d8) = *(undefined4 *)((longlong)_Dst + 0x210);
          *(undefined4 *)((longlong)_Dst + 0x3dc) = *(undefined4 *)((longlong)_Dst + 0x214);
          *(undefined4 *)((longlong)_Dst + 0x3e0) = *(undefined4 *)((longlong)_Dst + 0x218);
          *(undefined4 *)((longlong)_Dst + 0x3e4) = *(undefined4 *)((longlong)_Dst + 0x21c);
          *(undefined8 *)((longlong)_Dst + 1000) = *(undefined8 *)((longlong)_Dst + 0x220);
          uVar1 = *(ushort *)((longlong)_Dst + 0x31a);
          if (0xd7 < uVar1) {
            uVar1 = 0xd8;
          }
          *(ushort *)((longlong)_Dst + 0x31a) = uVar1;
          if (*(int *)(param_3 + 0x24) < 0) {
            *(ushort *)((longlong)_Dst + 4) = *(ushort *)((longlong)_Dst + 4) | 2;
          }
          ExInitializeRundownProtection((longlong)_Dst + 0x40);
          KeInitializeEvent((longlong)_Dst + 0x50,1,1);
          *(undefined4 *)((longlong)_Dst + 0x78) = 1;
          *(undefined8 *)((longlong)_Dst + 0x80) = 0;
          *(undefined4 *)((longlong)_Dst + 0x88) = 0;
          KeInitializeEvent((longlong)_Dst + 0x90,1,0);
          KeInitializeSpinLock((longlong)_Dst + 0xb0);
        }
      }
    }
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar2;
}



===== GpiopBuildGpioBanks @ 140026ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopBuildGpioBanks(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  short sVar6;
  ushort uVar7;
  ulonglong uVar8;
  ushort uVar9;
  undefined1 auStackY_148 [32];
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined *local_c8;
  undefined4 local_b8;
  undefined8 local_b4;
  code *local_a8;
  code *local_90;
  code *local_88;
  code *local_70;
  ulonglong local_58;
  longlong lStack_50;
  longlong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  uVar9 = *(ushort *)(param_1 + 0x2d6);
  uVar2 = ((uint)*(ushort *)(param_1 + 0x2d4) + (uint)uVar9) - 1;
  if (uVar9 != 1) {
    uVar2 = ((int)uVar2 / (int)(uint)uVar9) * (uint)uVar9;
  }
  uVar4 = (ulonglong)(uVar2 & 0xffff) / (ulonglong)(uint)uVar9;
  uVar8 = 0x786c4347;
  *(short *)(param_1 + 0x2d8) = (short)uVar4;
  uVar2 = (int)uVar4 * 400;
  uVar4 = (ulonglong)uVar2;
  lVar3 = ExAllocatePool2(0x40);
  *(longlong *)(param_1 + 0x2e0) = lVar3;
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0x99,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,"GpiopBuildGpioBanks",
                         (char)uVar2);
    }
    uVar8 = 0xc000009a;
  }
  else {
    uVar9 = 0;
    if (*(short *)(param_1 + 0x2d8) != 0) {
      do {
        lVar3 = (ulonglong)uVar9 * 400 + *(longlong *)(param_1 + 0x2e0);
        *(ushort *)(lVar3 + 0x80) = uVar9;
        *(longlong *)(lVar3 + 0x88) = param_1;
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0,lVar3 + 0x30);
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return (ulonglong)uVar2;
          }
          WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,1,0x9a,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)uVar2);
          return (ulonglong)uVar2;
        }
        *(undefined4 *)(lVar3 + 0x130) = 0xffffffff;
        *(undefined2 *)(lVar3 + 0x98) = 0xffff;
        uVar4 = 0;
        *(undefined8 *)(lVar3 + 0x90) = 0xffffffffffffffff;
        *(undefined1 *)(lVar3 + 0x134) = 0;
        *(undefined8 *)(lVar3 + 0x138) = 0;
        local_58 = 0;
        lStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        if ((*(uint *)(*(longlong *)(lVar3 + 0x88) + 0x314) & 0x10) == 0) {
LAB_140027064:
          if ((local_58 & 1) == 0) {
            *(undefined4 *)(lVar3 + 0x160) = 0;
          }
          else {
            if (lStack_50 == 0) {
              lStack_50 = 10;
            }
            if (local_48 == 0) {
              local_48 = 10;
            }
            if ((lStack_50 == 0) || (local_48 == 0)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDii(*(undefined8 *)(*(longlong *)(lVar3 + 0x88) + 0x298));
              }
            }
            else {
              *(undefined4 *)(lVar3 + 0x160) = 1;
              *(longlong *)(lVar3 + 0x168) = lStack_50;
              *(longlong *)(lVar3 + 0x170) = local_48;
              *(undefined8 *)(lVar3 + 0x178) = uStack_40;
            }
          }
        }
        else {
          uVar2 = GpiopQueryBankPowerInformation(lVar3,&local_58);
          uVar4 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) goto LAB_140027064;
        }
        if ((int)uVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar4;
          }
          WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),2,1,0x9b,
                              &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,"GpiopBuildGpioBanks"
                              ,(char)param_1,(char)*(undefined2 *)(lVar3 + 0x80));
          return uVar4;
        }
        uVar7 = *(ushort *)(param_1 + 0x2d8);
        sVar6 = *(short *)(param_1 + 0x2d6);
        if ((int)(uVar7 - 1) <= (int)(uint)uVar9) {
          uVar7 = uVar7 - 1;
          sVar6 = *(short *)(param_1 + 0x2d4) - uVar7 * sVar6;
        }
        uVar8 = (ulonglong)uVar7;
        *(short *)(lVar3 + 0x180) = sVar6;
        lVar1 = lVar3 + 0x60;
        uVar4 = lVar3 + 0x70;
        LOCK();
        *(undefined8 *)(lVar3 + 0x188) = 0;
        UNLOCK();
        *(longlong *)(lVar3 + 0x68) = lVar1;
        *(longlong *)lVar1 = lVar1;
        EtwActivityIdControl(3);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(param_1 + 0x2d8));
    }
    uVar4 = GpiopQueryEmulatedActiveBothInitialPolarities(param_1,uVar4,uVar8);
    uVar8 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      memset(&local_b8,0,0x60);
      local_a8 = GpioClxBankEvtProcessIoDefault;
      local_90 = GpioClxBankEvtProcessDeviceIoControl;
      local_88 = GpioClxBankEvtProcessInternalIoControl;
      local_e8 = 0;
      local_70 = GpioClxBankEvtProcessIoCanceledOnQueue;
      local_b8 = 0x60;
      uVar9 = 0;
      uStack_f0 = 0;
      local_c8 = PTR__WDF_GPIO_BANK_QUEUE_CONTEXT_TYPE_INFO_14001e0e0;
      local_b4 = 1;
      local_d8 = 0;
      uStack_d0 = 0;
      local_f8 = 0x38;
      uStack_e0 = 0x300000002;
      if (*(short *)(param_1 + 0x2d8) != 0) {
        do {
          lVar3 = (ulonglong)uVar9 * 400 + *(longlong *)(param_1 + 0x2e0);
          uVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),&local_b8,&local_f8);
          if ((int)uVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return (ulonglong)uVar2;
            }
            WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,1,0xb6,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)uVar2,
                               (char)uVar9);
            return (ulonglong)uVar2;
          }
          plVar5 = (longlong *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x58),
                              PTR__WDF_GPIO_BANK_QUEUE_CONTEXT_TYPE_INFO_14001e0e0);
          uVar9 = uVar9 + 1;
          *plVar5 = lVar3;
        } while (uVar9 < *(ushort *)(param_1 + 0x2d8));
      }
      uVar8 = 0;
    }
  }
  return uVar8;
}



===== GpiopConnectFunctionConfigPinsReserve @ 140027398 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopConnectFunctionConfigPinsReserve(longlong param_1,longlong *param_2,undefined8 *param_3)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  ushort uVar11;
  longlong *plVar12;
  undefined8 uVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined2 uVar18;
  ushort *puVar19;
  undefined1 uVar20;
  longlong local_res18;
  ushort *local_res20;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined1 uVar21;
  ushort *local_50;
  longlong *local_48;
  
  local_res18 = 0;
  plVar7 = &local_res18;
  plVar12 = (longlong *)(param_1 + 0x110);
  iVar4 = GpiopQueryResourceHubBiosDescriptor
                    (*(undefined8 *)(param_1 + 0x2c8),plVar12,0,*param_3,plVar7);
  puVar17 = auStackY_a8;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(param_1 + 0x298),plVar12,0xc,0x41,plVar7,
                          "GpiopConnectFunctionConfigPinsReserve",(char)*param_3,(char)iVar4);
      puVar17 = auStackY_a8;
    }
    goto LAB_140027aad;
  }
  param_2[0xb] = local_res18;
  uVar14 = *(uint *)(local_res18 + 4);
  uVar21 = (undefined1)param_1;
  if (uVar14 < 0x12) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar18 = 0x42;
LAB_140027a7d:
      WPP_RECORDER_SF_sqdd
                (*(undefined8 *)(param_1 + 0x298),(ulonglong)uVar14,0xc,uVar18,plVar7,
                 "GpiopConnectFunctionConfigPinsReserve",uVar21,(char)uVar14,0x12);
    }
  }
  else {
    if (*(char *)(local_res18 + 8) == -0x73) {
      uVar11 = *(ushort *)(local_res18 + 0x11);
      if (uVar11 < uVar14) {
        uVar1 = *(ushort *)(local_res18 + 0x14);
        if (uVar1 < uVar14) {
          uVar2 = *(ushort *)(local_res18 + 0x16);
          if ((((uVar2 < uVar14 || uVar2 == uVar14) && (uVar11 < uVar1)) && (uVar1 < uVar2)) &&
             (((*(char *)(local_res18 + 0xb) != '\0' &&
               (uVar5 = (uint)uVar1 - (uint)uVar11, 1 < uVar5)) &&
              (((uVar5 & 1) == 0 && (((ulonglong)(uint)uVar2 - (ulonglong)uVar1) - 1 < 0x7fff))))))
          {
            puVar19 = (ushort *)(local_res18 + 8 + (ulonglong)uVar11);
            uVar15 = (ulonglong)uVar1 - (ulonglong)uVar11 >> 1;
            local_res20 = puVar19;
            uVar14 = (uint)uVar15;
            if (uVar14 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sqi(*(undefined8 *)(param_1 + 0x298),2,0xc,(short)uVar15 + 0x44,
                                    plVar7,"GpiopConnectFunctionConfigPinsReserve",uVar21,
                                    (char)*param_3);
              }
              goto LAB_140027aa8;
            }
            uVar20 = (undefined1)*puVar19;
            uVar9 = (ulonglong)*(ushort *)(param_1 + 0x2d6);
            uVar15 = *puVar19 / uVar9;
            uVar11 = (ushort)uVar15;
            lVar6 = GpiopGetBankEntry(param_1,uVar11);
            if (lVar6 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar15,0xc,0x45,
                                    &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                    "GpiopConnectFunctionConfigPinsReserve",uVar20,(char)uVar11);
              }
              puVar17 = auStackY_a8;
              iVar4 = -0x3ffffff3;
              goto LAB_140027aad;
            }
            uVar5 = 1;
            if (1 < uVar14) {
              do {
                uVar15 = (ulonglong)puVar19[uVar5] / (uVar9 & 0xffffffff);
                if (uVar11 != (ushort)uVar15) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sqDDD
                              (*(undefined8 *)(param_1 + 0x298),2,0xc,0x46,plVar7,
                               "GpiopConnectFunctionConfigPinsReserve",uVar21,(char)uVar11,
                               (char)uVar15,(char)puVar19[uVar5]);
                  }
                  puVar17 = auStackY_a8;
                  iVar4 = -0x3fffff45;
                  goto LAB_140027aad;
                }
                uVar5 = uVar5 + 1;
              } while (uVar5 < uVar14);
            }
            puVar19 = (ushort *)ExAllocatePool2(0x40,uVar14 * 2,0x786c4347);
            if (puVar19 == (ushort *)0x0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,0xc,0x47,
                                  &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                  "GpiopConnectFunctionConfigPinsReserve");
              }
              puVar17 = auStackY_a8;
              iVar4 = -0x3fffff66;
              goto LAB_140027aad;
            }
            plVar7 = (longlong *)ExAllocatePool2(0x40,uVar14 * 8,0x786c4347);
            if (plVar7 == (longlong *)0x0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,0xc,0x48,
                                  &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                  "GpiopConnectFunctionConfigPinsReserve");
              }
              puVar17 = auStackY_a8;
              iVar4 = -0x3fffff66;
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xc,0x49,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                   "GpiopConnectFunctionConfigPinsReserve",uVar21);
              }
              puVar16 = auStackY_a8;
              uVar15 = 0;
              if (uVar14 != 0) {
                lVar10 = (longlong)local_res20 - (longlong)puVar19;
                local_50 = puVar19;
                local_48 = plVar7;
                do {
                  uVar11 = *(ushort *)(lVar10 + (longlong)local_50) % *(ushort *)(param_1 + 0x2d6);
                  *local_50 = uVar11;
                  lVar8 = GpiopCreatePinEntry(lVar6,uVar11);
                  if (lVar8 == 0) goto LAB_1400278a1;
                  uVar5 = (int)uVar15 + 1;
                  uVar15 = (ulonglong)uVar5;
                  local_50 = local_50 + 1;
                  *local_48 = lVar8;
                  local_48 = local_48 + 1;
                } while (uVar5 < uVar14);
              }
              GpioUtilTracePrintPinNumbers(lVar6,puVar19,uVar14);
              *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
              param_2[4] = (longlong)puVar19;
              param_2[6] = (longlong)plVar7;
              *(uint *)(param_2 + 5) = uVar14;
              (**(code **)(WdfFunctions_01015 + 0x260))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),0);
              (**(code **)(WdfFunctions_01015 + 0x9c8))
                        (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x30),0);
              *(void **)(lVar6 + 0x38) = SystemReserved1[0xf];
              uVar9 = GpiopConnectFunctionConfigPinsLocked(param_1,lVar6,(longlong)param_2,0);
              iVar4 = (int)uVar9;
              if (iVar4 < 0) {
LAB_1400278fa:
                *(undefined8 *)(lVar6 + 0x38) = 0;
                (**(code **)(WdfFunctions_01015 + 0x9d0))
                          (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x30));
                if (-1 < iVar4) {
                  PoFxActivateComponent
                            (*(undefined8 *)(param_1 + 0x118),*(undefined2 *)(lVar6 + 0x80),0);
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xc,0x4b,
                                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                       "GpiopConnectFunctionConfigPinsReserve",uVar21);
                  }
                  GpioUtilTracePrintPinNumbers
                            (lVar6,(undefined2 *)param_2[4],*(uint *)(param_2 + 5));
                  return iVar4;
                }
                uVar13 = *(undefined8 *)(param_1 + 0x2c8);
                (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,uVar13,1);
                *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
                param_2[4] = 0;
                *(undefined4 *)(param_2 + 5) = 0;
                param_2[6] = 0;
                if (iVar4 == -0x3fff5eda) {
                  puVar17 = auStackY_a8;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar13,0xc,0x4c,
                                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                        "GpiopConnectFunctionConfigPinsReserve",
                                        (char)local_res20[uVar15],0x26);
                    puVar17 = auStackY_a8;
                  }
                }
                else {
                  puVar17 = auStackY_a8;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,0xc,0x4d,
                                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                       "GpiopConnectFunctionConfigPinsReserve",(char)uVar9);
                    puVar17 = auStackY_a8;
                  }
                }
              }
              else {
                plVar7 = *(longlong **)(lVar6 + 0x68);
                if (*plVar7 == lVar6 + 0x60) {
                  *param_2 = lVar6 + 0x60;
                  param_2[1] = (longlong)plVar7;
                  *plVar7 = (longlong)param_2;
                  *(longlong **)(lVar6 + 0x68) = param_2;
                  goto LAB_1400278fa;
                }
                pcVar3 = (code *)swi(0x29);
                (*pcVar3)(3);
                puVar16 = auStackY_a0;
LAB_1400278a1:
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  *(uint *)(puVar16 + 0x38) =
                       (uint)*(ushort *)(*(longlong *)(puVar16 + 200) + uVar15 * 2);
                  uVar13 = *(undefined8 *)(param_1 + 0x298);
                  *(longlong *)(puVar16 + 0x30) = param_1;
                  *(char **)(puVar16 + 0x28) = "GpiopConnectFunctionConfigPinsReserve";
                  *(undefined **)(puVar16 + 0x20) = &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids
                  ;
                  *(undefined8 *)(puVar16 + -8) = 0x1400278e2;
                  WPP_RECORDER_SF_sqD(uVar13,2,0xc,0x4a,*(undefined8 *)(puVar16 + 0x20),
                                      *(char **)(puVar16 + 0x28),puVar16[0x30],puVar16[0x38]);
                }
                iVar4 = -0x3fffff66;
                puVar17 = puVar16;
              }
              *(undefined8 *)(puVar17 + -8) = 0x140027a47;
              ExFreePoolWithTag(*(undefined8 *)(puVar17 + 0x50),0x786c4347);
            }
            *(undefined8 *)(puVar17 + -8) = 0x140027a60;
            ExFreePoolWithTag(*(undefined8 *)(puVar17 + 0xb0),0x786c4347);
            goto LAB_140027aad;
          }
        }
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar18 = 0x43;
      goto LAB_140027a7d;
    }
  }
LAB_140027aa8:
  puVar17 = auStackY_a8;
  iVar4 = -0x3fffffff;
LAB_140027aad:
  if (*(longlong *)(puVar17 + 0xc0) != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x140027ac6;
    ExFreePoolWithTag(*(longlong *)(puVar17 + 0xc0),0x786c4347);
    param_2[0xb] = 0;
  }
  return iVar4;
}



===== GpiopConnectGpioPins @ 140027af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopConnectGpioPins(longlong param_1,longlong *param_2,int param_3,undefined8 *param_4)

{
  code *pcVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  ushort *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  ushort uVar12;
  ulonglong uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  char *pcVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined2 uVar19;
  undefined1 uVar20;
  ulonglong uVar21;
  uint uVar22;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  undefined1 uVar23;
  uint local_84;
  ushort *local_80;
  longlong local_70 [2];
  ushort *local_60;
  longlong *local_58;
  longlong local_50;
  longlong *local_48;
  longlong local_40;
  
  local_70[1] = 0;
  local_70[0] = 0;
  local_50 = 0;
  if (1 < param_3 - 1U) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiD(*(undefined8 *)(param_1 + 0x298));
    }
    return -0x3ffffff3;
  }
  plVar11 = local_70;
  uVar17 = 0;
  iVar4 = GpiopQueryResourceHubBiosDescriptor
                    (*(undefined8 *)(param_1 + 0x2c8),(longlong *)(param_1 + 0x110),0,*param_4,
                     plVar11);
  lVar5 = local_70[0];
  puVar15 = auStackY_d8;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_iD(*(undefined8 *)(param_1 + 0x298));
      puVar15 = auStackY_d8;
    }
    goto LAB_1400282c0;
  }
  uVar22 = *(uint *)(local_70[0] + 4);
  uVar8 = (ulonglong)uVar22;
  uVar23 = (undefined1)param_1;
  if (uVar22 < 0x17) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar19 = 0x58;
LAB_140027bf6:
      WPP_RECORDER_SF_qdd(*(undefined8 *)(param_1 + 0x298),uVar8,uVar17,uVar19,plVar11,uVar23,
                          (char)uVar8);
    }
  }
  else {
    pcVar16 = (char *)(local_70[0] + 8);
    cVar3 = GpioUtilIsBiosGpioDescriptorValid(pcVar16,uVar22);
    if (cVar3 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar19 = 0x59;
        goto LAB_140027bf6;
      }
    }
    else {
      uVar8 = (ulonglong)*(ushort *)(lVar5 + 0x16);
      uVar13 = *(ushort *)(lVar5 + 0x19) - uVar8 >> 1;
      puVar6 = (ushort *)(pcVar16 + uVar8);
      local_60 = puVar6;
      if ((short)uVar13 != 0) {
        uVar20 = (undefined1)*puVar6;
        uVar21 = (ulonglong)*(ushort *)(param_1 + 0x2d6);
        uVar8 = *puVar6 / uVar21;
        lVar5 = GpiopGetBankEntry(param_1,(ushort)uVar8);
        if (lVar5 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DD(*(undefined8 *)(param_1 + 0x298),2,8,0x5b,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,uVar20,(char)uVar8);
          }
          puVar15 = auStackY_d8;
          iVar4 = -0x3ffffff3;
          goto LAB_1400282c0;
        }
        uVar10 = 1;
        uVar22 = (uint)uVar13 & 0xffff;
        if (1 < uVar22) {
          do {
            uVar2 = (ulonglong)puVar6[uVar10] / (uVar21 & 0xffffffff);
            if ((short)uVar8 != (short)uVar2) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qDDD
                          (*(undefined8 *)(param_1 + 0x298),2,uVar8,0x5c,plVar11,uVar23,(char)uVar8,
                           (char)uVar2,(char)puVar6[uVar10]);
              }
              puVar15 = auStackY_d8;
              iVar4 = -0x3fffff45;
              goto LAB_1400282c0;
            }
            uVar9 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar9;
          } while (uVar9 < uVar22);
        }
        puVar6 = (ushort *)ExAllocatePool2(0x40,uVar22 * 2,0x786c4347);
        if (puVar6 == (ushort *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x298),2,7,0x5d,
                             &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
          }
          puVar15 = auStackY_d8;
          iVar4 = -0x3fffff66;
          goto LAB_1400282c0;
        }
        local_58 = (longlong *)ExAllocatePool2(0x40,uVar22 * 8,0x786c4347);
        if (local_58 == (longlong *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x298),2,7,0x5e,
                             &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
          }
          puVar15 = auStackY_d8;
          iVar4 = -0x3fffff66;
        }
        else {
          local_50 = ExAllocatePool2(0x40,(uVar13 & 0xffff) * 2,0x786c4347);
          if (local_50 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x298),2,7,0x5f,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
            }
LAB_14002809e:
            puVar15 = auStackY_d8;
            iVar4 = -0x3fffff66;
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),4,7,0x60,
                                  &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                  "GpiopConnectGpioPins",uVar23,(char)param_3);
            }
            puVar15 = auStackY_d8;
            puVar14 = auStackY_d8;
            local_84 = 0;
            if ((uVar13 & 0xffff) != 0) {
              local_48 = local_58;
              local_40 = (longlong)local_60 - (longlong)puVar6;
              local_80 = puVar6;
              do {
                uVar12 = *(ushort *)(local_40 + (longlong)local_80) % *(ushort *)(param_1 + 0x2d6);
                *local_80 = uVar12;
                lVar7 = GpiopCreatePinEntry(lVar5,uVar12);
                if (lVar7 == 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sqD(*(undefined8 *)(param_1 + 0x298),2,7,0x61,
                                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                        "GpiopConnectGpioPins",uVar23,(char)local_60[local_84]);
                  }
                  goto LAB_14002809e;
                }
                local_80 = local_80 + 1;
                *local_48 = lVar7;
                local_48 = local_48 + 1;
                local_84 = local_84 + 1;
              } while (local_84 < uVar22);
            }
            GpioUtilTracePrintPinNumbers(lVar5,puVar6,uVar22);
            *(uint *)(param_2 + 5) = uVar22;
            *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
            param_2[4] = (longlong)puVar6;
            param_2[6] = (longlong)local_58;
            param_2[7] = local_50;
            param_2[0xb] = local_70[0];
            (**(code **)(WdfFunctions_01015 + 0x260))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),0);
            (**(code **)(WdfFunctions_01015 + 0x9c8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x30),0);
            *(void **)(lVar5 + 0x38) = SystemReserved1[0xf];
            iVar4 = GpioClnInvokeCreateIoContext(lVar5,puVar6,uVar22,param_3,local_70 + 1);
            if (-1 < iVar4) {
              uVar8 = GpiopConnectGpioPinsLocked(param_1,lVar5,(longlong)param_2,param_3,param_4);
              iVar4 = (int)uVar8;
              if (iVar4 < 0) {
                GpioClnInvokeDeleteIoContext(param_1);
                local_70[1] = 0;
                puVar15 = auStackY_d8;
              }
              else {
                lVar7 = lVar5 + 0x60;
                plVar11 = *(longlong **)(lVar5 + 0x68);
                if (*plVar11 != lVar7) {
                  plVar11 = (longlong *)0x3;
                  pcVar1 = (code *)swi(0x29);
                  lVar7 = (*pcVar1)();
                  puVar14 = auStackY_d0;
                }
                *param_2 = lVar7;
                param_2[1] = (longlong)plVar11;
                *plVar11 = (longlong)param_2;
                *(longlong **)(lVar7 + 8) = param_2;
                puVar15 = puVar14;
              }
            }
            *(longlong *)(puVar15 + 0x58) = param_1 + 0x298;
            uVar17 = *(undefined8 *)(lVar5 + 0x30);
            *(undefined8 *)(lVar5 + 0x38) = 0;
            pcVar1 = *(code **)(WdfFunctions_01015 + 0x9d0);
            *(undefined8 *)(puVar15 + -8) = 0x140028139;
            (*pcVar1)(WdfDriverGlobals,uVar17);
            if (-1 < iVar4) {
              uVar18 = 0;
              param_2[9] = *(longlong *)(puVar15 + 0x70);
              uVar19 = *(undefined2 *)(lVar5 + 0x80);
              uVar17 = *(undefined8 *)(param_1 + 0x118);
              *(undefined8 *)(puVar15 + -8) = 0x14002815f;
              PoFxActivateComponent(uVar17,uVar19);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar17 = *(undefined8 *)(param_1 + 0x298);
                *(undefined4 *)(puVar15 + 0x38) = 0;
                *(undefined4 *)(puVar15 + 0x30) = *(undefined4 *)(puVar15 + 0xf0);
                *(longlong *)(puVar15 + 0x28) = param_1;
                *(undefined8 *)(puVar15 + -8) = 0x140028195;
                WPP_RECORDER_SF_qDd(uVar17,4,uVar18,0x62,*(undefined8 *)(puVar15 + 0x20),
                                    puVar15[0x28],puVar15[0x30],puVar15[0x38]);
              }
              *(undefined8 *)(puVar15 + -8) = 0x1400281a5;
              GpioUtilTracePrintPinNumbers(lVar5,*(undefined2 **)(puVar15 + 0x60),uVar22);
              return iVar4;
            }
            uVar17 = *(undefined8 *)(param_1 + 0x2c8);
            pcVar1 = *(code **)(WdfFunctions_01015 + 0x260);
            *(undefined8 *)(puVar15 + -8) = 0x1400281ce;
            (*pcVar1)(WdfDriverGlobals,uVar17,1);
            *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
            param_2[4] = 0;
            *(undefined4 *)(param_2 + 5) = 0;
            param_2[6] = 0;
            param_2[7] = 0;
            param_2[0xb] = 0;
            if (puVar15[0x50] == '\0') {
              if (iVar4 == -0x3fff5eda) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  *(undefined4 *)(puVar15 + 0x30) = 0xc000a126;
                  *(uint *)(puVar15 + 0x28) =
                       (uint)*(ushort *)
                              (*(longlong *)(puVar15 + 0x78) +
                              (ulonglong)*(uint *)(puVar15 + 0x54) * 2);
                  *(undefined **)(puVar15 + 0x20) = &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids
                  ;
                  uVar17 = **(undefined8 **)(puVar15 + 0x58);
                  *(undefined8 *)(puVar15 + -8) = 0x140028244;
                  WPP_RECORDER_SF_DD(uVar17,2,7,100,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28],
                                     puVar15[0x30]);
                }
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar19 = 0x65;
                goto LAB_140028255;
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar19 = 99;
LAB_140028255:
              *(int *)(puVar15 + 0x28) = iVar4;
              *(undefined **)(puVar15 + 0x20) = &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids;
              uVar17 = **(undefined8 **)(puVar15 + 0x58);
              *(undefined8 *)(puVar15 + -8) = 0x140028270;
              WPP_RECORDER_SF_D(uVar17,2,7,uVar19,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28]);
            }
          }
          *(undefined8 *)(puVar15 + -8) = 0x140028284;
          ExFreePoolWithTag(*(undefined8 *)(puVar15 + 0x80),0x786c4347);
        }
        *(undefined8 *)(puVar15 + -8) = 0x14002829a;
        ExFreePoolWithTag(*(undefined8 *)(puVar15 + 0x60),0x786c4347);
        if (*(longlong *)(puVar15 + 0x88) != 0) {
          *(undefined8 *)(puVar15 + -8) = 0x1400282bb;
          ExFreePoolWithTag(*(longlong *)(puVar15 + 0x88),0x786c4347);
        }
        goto LAB_1400282c0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qid(*(undefined8 *)(param_1 + 0x298));
      }
    }
  }
  puVar15 = auStackY_d8;
  iVar4 = -0x3fffffff;
LAB_1400282c0:
  if (*(longlong *)(puVar15 + 0x68) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1400282d6;
    ExFreePoolWithTag(*(longlong *)(puVar15 + 0x68),0x786c4347);
  }
  return iVar4;
}



===== GpiopCreateClient @ 140028300 =====

undefined8 GpiopCreateClient(undefined8 param_1,ushort *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ushort uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  uVar2 = GpiopValidateRegistrationPacketPhase1(param_2);
  uVar7 = 0;
  if ((char)uVar2 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(GpioLogHandle,2,1,0x8d,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
    }
    uVar7 = 0xc000a124;
  }
  else {
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x168,0x786c4347);
    if (puVar3 == (undefined8 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(GpioLogHandle,2,1,0x8e,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids);
      }
      uVar7 = 0xc000009a;
    }
    else {
      puVar3[2] = param_1;
      uVar5 = param_2[1];
      if (*(int *)(param_2 + 2) < 0) {
        if (0x147 < uVar5) {
          uVar5 = 0x148;
        }
      }
      else if (0xd7 < uVar5) {
        uVar5 = 0xd8;
      }
      memmove(puVar3 + 4,param_2,(ulonglong)uVar5);
      *(ushort *)((longlong)puVar3 + 0x22) = uVar5;
      ExAcquireFastMutex(&GpioClientGlobalListLock);
      puVar6 = auStackY_38;
      puVar4 = &GpioClientDriverList;
      if ((undefined8 *)*DAT_14001e718 != &GpioClientDriverList) {
        puVar4 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        DAT_14001e718 = (undefined8 *)(*pcVar1)();
        puVar6 = auStackY_30;
      }
      *puVar3 = puVar4;
      puVar3[1] = DAT_14001e718;
      *DAT_14001e718 = puVar3;
      *(undefined8 *)(puVar6 + -8) = 0x140028450;
      DAT_14001e718 = puVar3;
      ExReleaseFastMutex(&GpioClientGlobalListLock);
    }
  }
  return uVar7;
}



===== GpiopDeleteDeviceExtension @ 140028474 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopDeleteDeviceExtension(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  ushort uVar7;
  
  if (*(longlong *)(param_1 + 0x108) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x108));
    *(undefined8 *)(param_1 + 0x108) = 0;
  }
  if (*(longlong *)(param_1 + 0x110) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x110));
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if (*(longlong *)(param_1 + 0x2f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x2f0),0x786c4347);
    *(undefined8 *)(param_1 + 0x2e8) = 0;
    *(undefined8 *)(param_1 + 0x2f0) = 0;
  }
  if (*(longlong *)(param_1 + 0x300) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x300),0x786c4347);
    *(undefined8 *)(param_1 + 0x2f8) = 0;
    *(undefined8 *)(param_1 + 0x300) = 0;
  }
  GpiopManageAcpiEventing(param_1,5,'\x01');
  if (*(longlong *)(param_1 + 0x2e0) != 0) {
    uVar7 = 0;
    if (*(short *)(param_1 + 0x2d8) != 0) {
      do {
        lVar6 = (ulonglong)uVar7 * 400 + *(longlong *)(param_1 + 0x2e0);
        lVar3 = 0;
        LOCK();
        lVar2 = *(longlong *)(lVar6 + 0x188);
        if (lVar2 == 0) {
          *(longlong *)(lVar6 + 0x188) = 0;
        }
        else {
          lVar3 = lVar2;
        }
        UNLOCK();
        if (lVar2 != 0) {
          uVar5 = 0;
          if (*(short *)(lVar6 + 0x180) != 0) {
            do {
              lVar4 = 0;
              plVar1 = (longlong *)(lVar3 + (ulonglong)uVar5 * 8);
              LOCK();
              lVar2 = *plVar1;
              if (lVar2 == 0) {
                *plVar1 = 0;
              }
              else {
                lVar4 = lVar2;
              }
              UNLOCK();
              if (lVar2 != 0) {
                ExFreePoolWithTag(lVar4,0x786c4347);
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < *(ushort *)(lVar6 + 0x180));
          }
          ExFreePoolWithTag(lVar3,0x786c4347);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(ushort *)(param_1 + 0x2d8));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x2e0),0x786c4347);
  }
  if ((*(longlong *)(param_1 + 0x298) != 0) && (*(longlong *)(param_1 + 0x298) != GpioLogHandle)) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
  }
  return;
}



===== GpiopDisconnectFunctionConfigPins @ 140028690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GpiopDisconnectFunctionConfigPins(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined2 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xc,0x53,
                       &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                       "GpiopDisconnectFunctionConfigPins",(char)param_1);
  }
  lVar7 = GpiopGetBankEntry(param_1,*(ushort *)(param_2 + 3));
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30),0);
  puVar8 = auStackY_58;
  *(void **)(lVar7 + 0x38) = SystemReserved1[0xf];
  plVar2 = (longlong *)*param_2;
  if (plVar2 != param_2) {
    if (((longlong *)plVar2[1] == param_2) &&
       (plVar3 = (longlong *)param_2[1], (longlong *)*plVar3 == param_2)) {
      *plVar3 = (longlong)plVar2;
      plVar2[1] = (longlong)plVar3;
      param_2[1] = (longlong)param_2;
      *param_2 = (longlong)param_2;
      puVar4 = (undefined2 *)param_2[4];
      uVar1 = *(uint *)(param_2 + 5);
      GpioUtilTracePrintPinNumbers(lVar7,puVar4,uVar1);
      GpiopDisconnectFunctionConfigPinsLocked(param_1,(longlong)param_2);
      *(undefined8 *)(lVar7 + 0x38) = 0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x30));
      PoFxIdleComponent(*(undefined8 *)(param_1 + 0x118),*(undefined2 *)(lVar7 + 0x80),0);
      (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),1)
      ;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,0xc,0x54,
                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                           "GpiopDisconnectFunctionConfigPins",(char)param_1);
      }
      GpioUtilTracePrintPinNumbers(lVar7,puVar4,uVar1);
      if (param_2[6] != 0) {
        ExFreePoolWithTag(param_2[6],0x786c4347);
        param_2[6] = 0;
      }
      if (param_2[4] != 0) {
        ExFreePoolWithTag(param_2[4],0x786c4347);
        param_2[4] = 0;
      }
      if (param_2[0xb] != 0) {
        ExFreePoolWithTag(param_2[0xb],0x786c4347);
        param_2[0xb] = 0;
      }
      *(undefined4 *)(param_2 + 5) = 0;
      return 0;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar8 = auStackY_50;
  }
  uVar5 = *(undefined8 *)(lVar7 + 0x30);
  *(undefined8 *)(lVar7 + 0x38) = 0;
  pcVar6 = *(code **)(WdfFunctions_01015 + 0x9d0);
  *(undefined8 *)(puVar8 + -8) = 0x1400288d6;
  (*pcVar6)(WdfDriverGlobals,uVar5);
  return 0;
}



===== GpiopFindClient @ 140028900 =====

undefined8 * GpiopFindClient(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  ExAcquireFastMutex(&GpioClientGlobalListLock);
  puVar2 = (undefined8 *)0x0;
  puVar1 = GpioClientDriverList;
  do {
    if ((undefined8 **)puVar1 == &GpioClientDriverList) {
LAB_140028945:
      ExReleaseFastMutex(&GpioClientGlobalListLock);
      return puVar2;
    }
    if (puVar1[2] == param_1) {
      puVar2 = puVar1;
      goto LAB_140028945;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== GpiopInitialize @ 140028970 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GpiopInitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((int)param_1 == 0) {
    _DAT_14001e730 = 0;
    _GpioClientGlobalListLock = 1;
    _DAT_14001e728 = 0;
    DAT_14001e718 = &GpioClientDriverList;
    GpioClientDriverList = &GpioClientDriverList;
    KeInitializeEvent(&DAT_14001e738,1,0);
    iVar1 = GpioHubpInitialize(0,param_2,param_3);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x8b;
  }
  else {
    GpioEmOverrideAttributes = GpiopQueryEmOverrides();
    GpiopInitializeRegistryOptions(param_1,param_3,param_4);
    GpiopInitializeInterruptRegistryOptions(param_3,param_4);
    iVar1 = GpioHubpInitialize(1,param_2,param_3);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x8c;
  }
  WPP_RECORDER_SF_D(GpioLogHandle,2,1,uVar2,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                    (char)iVar1);
  return iVar1;
}



===== GpiopInitializeBanksAndInterrupts @ 140028a88 =====

ulonglong GpiopInitializeBanksAndInterrupts(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  undefined2 uVar5;
  
  bVar4 = 0;
  if ((*(uint *)(param_1 + 0x314) & 1) == 0) goto LAB_140028adf;
  if (GpioInterruptStormMitigationMode != 0) {
    if (GpioInterruptStormMitigationMode == 1) {
      bVar4 = (byte)(GpioEmOverrideAttributes >> 1) & 1;
      goto LAB_140028adf;
    }
    if (GpioInterruptStormMitigationMode == 2) {
      bVar4 = 1;
      goto LAB_140028adf;
    }
  }
  bVar4 = 0;
LAB_140028adf:
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x30c);
  *(ushort *)(param_1 + 0x2d6) = (ushort)*(byte *)(param_1 + 0x30e);
  *(byte *)(param_1 + 0x131) = bVar4;
  uVar2 = GpiopBuildGpioBanks(param_1);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar5 = 0x92;
  }
  else {
    uVar1 = GpiopSetupBankInterrupts(param_1,param_2,param_3);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = GpiopAllocateInterruptProcessingResources(param_1);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        return uVar2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar2;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 0x298),2,2,0x94,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,(char)uVar1);
      return uVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar3;
    }
    uVar5 = 0x93;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,uVar5,
                     &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                     "GpiopInitializeBanksAndInterrupts",(char)uVar3);
  return uVar3;
}



===== GpiopInitializeRegistryOptions @ 140028bec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpiopInitializeRegistryOptions(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined1 auStackY_138 [32];
  int local_f8 [4];
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined8 local_d8;
  wchar_t *local_d0;
  undefined8 local_c8;
  wchar_t *local_c0;
  wchar_t local_b8 [24];
  wchar_t local_88 [24];
  wchar_t local_58 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_138;
  local_f8[0] = 0;
  builtin_wcsncpy(local_88 + 0x10,L"rker",5);
  builtin_wcsncpy(local_88,L"ForceEmergencyWo",0x10);
  local_e0 = local_88;
  local_e8 = 0x2a0028;
  builtin_wcsncpy(local_b8 + 0x10,L"rrupts",7);
  local_d0 = local_b8;
  builtin_wcsncpy(local_b8,L"CheckEnabledInte",0x10);
  builtin_wcsncpy(local_58 + 0x10,L"rride",6);
  local_c0 = local_58;
  local_d8 = 0x2e002c;
  local_c8 = 0x2c002a;
  builtin_wcsncpy(local_58,L"DebounceModelOve",0x10);
  iVar1 = GpioUtilQueryRegistryFlags(param_1,param_2,param_3,(longlong)&local_e8,local_f8);
  if (-1 < iVar1) {
    GpioForceEmergencyWorker = (undefined1)local_f8[0];
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sd();
    }
  }
  local_f8[1] = 0;
  iVar1 = GpioUtilQueryRegistryFlags(param_1,param_2,param_3,(longlong)&local_d8,local_f8 + 1);
  if (iVar1 < 0) {
    GpioCheckEnabledInterrupts = 0;
  }
  else {
    GpioCheckEnabledInterrupts = (undefined1)local_f8[1];
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd();
  }
  local_f8[2] = 0;
  iVar1 = GpioUtilQueryRegistryFlags(param_1,param_2,param_3,(longlong)&local_c8,local_f8 + 2);
  if (((-1 < iVar1) && ((uint)local_f8[2] < 4)) &&
     (GpioGlobalDebounceModelOverride = local_f8[2],
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_sd();
  }
  return;
}



===== GpiopQueryControllerInformation @ 140028dec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GpiopQueryControllerInformation(longlong param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = (**(code **)(param_1 + 0x188))(param_1 + 0x400,&local_28);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0x91,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopQueryControllerInformation",(char)iVar2);
    }
  }
  else {
    cVar1 = GpiopValidateClientControllerBasicInformation(param_1,(short *)&local_28);
    if (cVar1 == '\0') {
      iVar2 = -0x3fff5ede;
    }
    else {
      *(undefined8 *)(param_1 + 0x308) = local_28;
      *(undefined8 *)(param_1 + 0x310) = uStack_20;
      GpiopValidateRegistrationPacketPhase2(param_1);
    }
  }
  return iVar2;
}



===== GpiopQueryEmulatedActiveBothInitialPolarities @ 140028ec4 =====

ulonglong GpiopQueryEmulatedActiveBothInitialPolarities
                    (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  longlong lVar8;
  uint local_res8 [2];
  uint *local_res10;
  longlong local_res18;
  int *local_res20;
  
  local_res10 = (uint *)((ulonglong)local_res10 & 0xffffffff00000000);
  local_res18 = 0;
  local_res20 = (int *)0x0;
  if ((*(uint *)(param_1 + 0x314) & 0x40) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),4,8,0x83,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        "GpiopQueryEmulatedActiveBothInitialPolarities");
    }
    return 0;
  }
  local_res8[0] = local_res8[0] & 0xffffff00;
  uVar3 = GpioUtilIsDsmFunctionSupported
                    (*(undefined8 *)(param_1 + 0x2c8),param_2,param_3,(undefined1 *)local_res8);
  uVar6 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if ((int)uVar3 != -0x3fffffcc) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,8,0x85,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        "GpiopQueryEmulatedActiveBothInitialPolarities");
LAB_1400291aa:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,8,0x8a,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopQueryEmulatedActiveBothInitialPolarities",(char)uVar6);
      return uVar6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar7 = 0x84;
  }
  else {
    if ((char)local_res8[0] != '\0') {
      uVar3 = GpioUtilPrepareInputParametersForDsmMethod(1,param_2,&local_res20);
      uVar6 = uVar3 & 0xffffffff;
      lVar8 = 0;
      if (-1 < (int)uVar3) {
        uVar2 = GpioUtilEvaluateAcpiMethod
                          (*(undefined8 *)(param_1 + 0x2c8),local_res20[1],local_res20,&local_res18,
                           (undefined4 *)&local_res10);
        lVar8 = local_res18;
        uVar6 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,8,0x87,
                              &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                              "GpiopQueryEmulatedActiveBothInitialPolarities");
          }
          lVar8 = local_res18;
        }
        else {
          if (local_res18 == 0) {
            uVar5 = 1;
LAB_1400291fa:
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0x138,7,0,1,uVar5);
          }
          uVar5 = 4;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),4,8,0x88,
                               &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                               "GpiopQueryEmulatedActiveBothInitialPolarities",
                               (char)*(undefined4 *)(local_res18 + 8));
          }
          local_res8[0] = 0;
          if (*(int *)(lVar8 + 8) != 0) {
            do {
              if (*(short *)(lVar8 + 0xc + (ulonglong)local_res8[0] * 8) != 0) {
                uVar5 = 2;
                goto LAB_1400291fa;
              }
              local_res10 = (uint *)(lVar8 + 0x10 + (ulonglong)local_res8[0] * 8);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),4,8,0x89,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                   "GpiopQueryEmulatedActiveBothInitialPolarities",
                                   (char)*local_res10);
              }
              if (0xffff < *local_res10) {
                uVar5 = 3;
                goto LAB_1400291fa;
              }
              uVar1 = (ushort)*local_res10;
              if (uVar1 != 0xffff) {
                if (*(ushort *)(param_1 + 0x2d4) <= uVar1) goto LAB_1400291fa;
                lVar4 = GpiopCreatePinEntryFromPinNumber(param_1,(uint)uVar1);
                if (lVar4 == 0) {
                  uVar6 = 0xc000009a;
                  break;
                }
                *(undefined1 *)(lVar4 + 4) = 1;
              }
              local_res8[0] = local_res8[0] + 1;
            } while (local_res8[0] < *(uint *)(lVar8 + 8));
          }
        }
      }
      if (local_res20 != (int *)0x0) {
        ExFreePoolWithTag(local_res20,0x786c4347);
      }
      if (lVar8 != 0) {
        ExFreePoolWithTag(lVar8,0x786c4347);
      }
      if (-1 < (int)uVar6) {
        return uVar6;
      }
      goto LAB_1400291aa;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar7 = 0x86;
  }
  WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),4,8,uVar7,
                    &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                    "GpiopQueryEmulatedActiveBothInitialPolarities");
  return 0;
}



===== GpiopQueryEmulatedActiveBothInitialPolarity @ 14002927c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopQueryEmulatedActiveBothInitialPolarity
              (undefined8 param_1,longlong *param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 local_res10;
  undefined4 local_res14;
  undefined8 local_58;
  undefined8 local_50;
  ulonglong local_48;
  undefined8 *local_40;
  undefined8 local_38;
  ulonglong local_30;
  undefined4 *local_28;
  undefined8 local_20;
  
  local_50 = 0;
  local_30 = (ulonglong)(uint)local_30;
  local_48 = (ulonglong)(uint)local_48;
  if ((*param_2 == 0) && (iVar1 = GpiopOpenResourceHubTarget(param_1,param_2), iVar1 < 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_sD(GpioLogHandle,2,1,0xae,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                       "GpiopQueryEmulatedActiveBothInitialPolarity",(char)iVar1);
    return iVar1;
  }
  local_28 = &local_res10;
  local_res10 = 1;
  local_30 = 1;
  local_48 = 1;
  local_40 = &local_58;
  local_20 = 8;
  local_58 = 0;
  local_38 = 8;
  local_res14 = param_3;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,*param_2,0,0x2ac010,&local_30,&local_48,0,&local_50);
  if (-1 < iVar1) {
    if (local_58._4_1_ == '\x02') {
      *param_4 = 2;
    }
    else {
      *param_4 = (uint)(local_58._4_1_ == '\0');
    }
  }
  return iVar1;
}



===== GpiopResolveInterruptBinding @ 1400293d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopResolveInterruptBinding(longlong param_1,uint param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  short *_Dst;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  ushort uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  int local_res10;
  longlong local_48;
  
  uVar9 = 0;
  if (param_2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),4,1,0xb1,
                      &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                      "GpiopResolveInterruptBinding");
    return 0;
  }
  if (param_2 == 1) {
    pcVar13 = (char *)0x0;
    local_48 = 0;
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_3);
    uVar14 = 0;
    uVar12 = 0;
    if (uVar3 != 0) {
      do {
        uVar14 = uVar12;
        pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar14);
        if (*pcVar4 == '\x02') {
          local_48 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_4,uVar14);
          pcVar13 = pcVar4;
          break;
        }
        uVar14 = uVar14 + 1;
        uVar12 = uVar14;
      } while (uVar14 < uVar3);
    }
    if (*(short *)(param_1 + 0x2d8) == 0) {
      return 0;
    }
    do {
      lVar6 = uVar9 * 400 + *(longlong *)(param_1 + 0x2e0);
      *(uint *)(lVar6 + 0x10) = uVar14;
      GpiopSetInterruptInformationFromResources(lVar6,(longlong)pcVar13,local_48);
      uVar8 = (short)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 < *(ushort *)(param_1 + 0x2d8));
    return 0;
  }
  uVar12 = (uint)*(ushort *)(param_1 + 0x2d8) * 4 + 8;
  _Dst = (short *)ExAllocatePool2(0x100,uVar12,0x49784347);
  if (_Dst == (short *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,1,0xb2,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        "GpiopResolveInterruptBinding");
    }
    return -0x3fffff66;
  }
  memset(_Dst,0xff,(ulonglong)uVar12);
  *_Dst = 0;
  _Dst[1] = (short)uVar12;
  uVar10 = param_4;
  uVar5 = GpioClnInvokeQueryInterruptBinding(param_1,param_3,param_4,param_2,_Dst);
  local_res10 = (int)uVar5;
  if (local_res10 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0xb4,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopResolveInterruptBinding",(char)uVar5);
      goto LAB_140029759;
    }
  }
  else {
    cVar2 = GpiopValidateInterruptBindings(param_1,param_3,uVar10,_Dst,uVar12);
    if ((cVar2 == '\0') &&
       (local_res10 = -0x3fffffff,
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0xb3,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopResolveInterruptBinding",1);
    }
  }
  uVar8 = 0;
  if (-1 < local_res10) {
    for (; uVar8 < *(ushort *)(param_1 + 0x2d8); uVar8 = uVar8 + 1) {
      iVar1 = *(int *)(_Dst + (ulonglong)uVar8 * 2 + 4);
      if (iVar1 == 0xffff) {
        lVar6 = 0;
        lVar11 = 0;
      }
      else {
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,iVar1);
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_4,iVar1);
      }
      lVar7 = (ulonglong)uVar8 * 400 + *(longlong *)(param_1 + 0x2e0);
      *(int *)(lVar7 + 0x10) = iVar1;
      GpiopSetInterruptInformationFromResources(lVar7,lVar6,lVar11);
    }
  }
LAB_140029759:
  ExFreePoolWithTag(_Dst,0x49784347);
  return local_res10;
}



===== GpiopSetInterruptInformationFromResources @ 140029790 =====

undefined8
GpiopSetInterruptInformationFromResources(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  puVar1 = (undefined8 *)(param_1 + 0x90);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x130) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x98) = 0xffff;
    *puVar1 = 0xffffffffffffffff;
    uVar5 = 0;
    *(undefined1 *)(param_1 + 0x134) = 0;
  }
  else {
    iVar4 = *(int *)(param_3 + 8);
    uVar7 = 0;
    *(int *)(param_1 + 0x130) = iVar4;
    uVar5 = *(uint *)(*(longlong *)(param_1 + 0x88) + 0x2a4);
    if (uVar5 != 0) {
      do {
        piVar2 = (int *)(*(longlong *)(*(longlong *)(param_1 + 0x88) + 0x2a8) + uVar7 * 0x18);
        if (iVar4 == *piVar2) {
          *(int **)(param_1 + 0x110) = piVar2;
          break;
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < uVar5);
    }
    uVar3 = *(undefined1 *)(param_2 + 4);
    *(undefined1 *)(param_1 + 0x134) = uVar3;
    *(undefined1 *)(param_1 + 0x135) = uVar3;
    *puVar1 = 0;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined2 *)(param_1 + 0x98) = *(undefined2 *)(param_2 + 6);
    *puVar1 = *(undefined8 *)(param_2 + 0xc);
    uVar5 = *(ushort *)(param_2 + 2) & 1;
  }
  *(uint *)(param_1 + 0x138) = uVar5;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  return 0;
}



===== GpiopSetupBankInterrupts @ 14002985c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopSetupBankInterrupts(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined2 uVar11;
  byte bVar12;
  ushort uVar13;
  undefined4 uVar14;
  ulonglong uVar15;
  bool bVar16;
  ulonglong local_1d8;
  code *pcStack_1d0;
  undefined8 local_1c8;
  ulonglong local_1c0 [6];
  undefined *local_190;
  ulonglong local_188 [5];
  undefined8 uStack_160;
  undefined8 local_158;
  ulonglong local_150 [5];
  undefined8 uStack_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined4 local_108;
  code *local_100;
  code *local_f8;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_bc;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  code *local_90;
  undefined8 local_88;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_50;
  undefined4 local_4c;
  
  uVar8 = 0;
  local_1c0[0] = (ulonglong)(uint)local_1c0[0];
  local_150[0] = (ulonglong)(uint)local_150[0];
  uVar14 = 0xffffffff;
  local_114 = 0;
  bVar12 = 2;
  local_a4 = 0;
  uVar10 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals);
  if (uVar2 != 0) {
    do {
      pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,uVar8);
      if (*pcVar4 == '\x02') {
        bVar1 = pcVar4[4];
        uVar10 = uVar10 + 1;
        if (bVar12 < bVar1) {
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar8);
          uVar14 = *(undefined4 *)(lVar5 + 8);
          bVar12 = bVar1;
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar2);
  }
  *(undefined4 *)(param_1 + 8) = uVar14;
  uVar15 = 0;
  *(byte *)(param_1 + 6) = bVar12;
  local_188[0] = (ulonglong)(uint)local_188[0];
  local_1d8 = (ulonglong)(uint)local_1d8;
  if ((*(char *)(param_1 + 0x131) != '\0') && (uVar10 != 0)) {
    lVar5 = ExAllocatePool2(0x40,(ulonglong)uVar10 * 0x18,0x49784347);
    if (lVar5 == 0) {
      iVar3 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff66;
      }
      uVar11 = 0xa1;
      goto LAB_1400299a0;
    }
    *(uint *)(param_1 + 0x2a4) = uVar10;
    *(longlong *)(param_1 + 0x2a8) = lVar5;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_3);
    local_188[4] = *(undefined8 *)(param_1 + 0x2c8);
    local_158 = 0;
    local_188[2] = 0;
    local_188[3] = 0x100000001;
    pcStack_1d0 = GpiopMitigateInterruptStorm;
    local_1d8 = 0x18;
    uVar8 = 0;
    local_1c8 = 0;
    local_188[1] = 0;
    local_188[0] = 0x38;
    uStack_160 = 0;
    if (uVar2 != 0) {
      do {
        pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar8);
        if (*pcVar4 == '\x02') {
          *(undefined4 *)(lVar5 + uVar15 * 0x18) = *(undefined4 *)(pcVar4 + 8);
          (**(code **)(WdfFunctions_01015 + 0x378))
                    (WdfDriverGlobals,&local_1d8,local_188,lVar5 + (uVar15 * 3 + 1) * 8);
          uVar15 = (ulonglong)((int)uVar15 + 1);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar2);
    }
  }
  iVar3 = GpiopResolveInterruptBinding(param_1,uVar10,param_2,param_3);
  if (-1 < iVar3) {
    memset(&local_118,0,0x68);
    local_118 = 0x68;
    local_1c0[2] = 0;
    local_100 = GpioClxEvtInterruptIsr;
    local_150[2] = 0;
    local_108 = 2;
    local_f8 = GpioClxEvtInterruptDpc;
    local_190 = PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110;
    local_120 = 0;
    local_150[4] = *(undefined8 *)(param_1 + 0x2c8);
    local_1c0[1] = 0;
    local_1c0[0] = 0x38;
    local_150[1] = 0;
    local_150[0] = 0x38;
    uStack_128 = 0;
    local_bc = 2;
    local_1c0[4] = 0;
    local_1c0[5] = 0;
    local_1c0[3] = 0x100000001;
    local_150[3] = 0x100000001;
    memset(&local_a8,0,0x68);
    local_98 = 2;
    local_90 = GpioClxEvtInterruptPassiveIsr;
    local_4c = 2;
    bVar16 = true;
    local_a8 = 0x68;
    local_88 = 0;
    local_50 = 1;
    if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
      bVar16 = *(longlong *)(param_1 + 0x1f8) != 0;
    }
    uVar13 = 0;
    if (*(short *)(param_1 + 0x2d8) == 0) {
      return iVar3;
    }
    do {
      puVar7 = local_150;
      puVar9 = (undefined8 *)((ulonglong)uVar13 * 400 + *(longlong *)(param_1 + 0x2e0));
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,puVar7,puVar9 + 3);
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar3;
        }
        WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),puVar7,1,0xa3,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                            "GpiopSetupBankInterrupts",(char)uVar13,(char)iVar3);
        return iVar3;
      }
      if (*(int *)(puVar9 + 0x26) == -1) {
        local_d0 = 0;
        local_d8 = 0;
      }
      else {
        local_d0 = (**(code **)(WdfFunctions_01015 + 0x988))
                             (WdfDriverGlobals,param_2,*(undefined4 *)(puVar9 + 2));
        local_d8 = (**(code **)(WdfFunctions_01015 + 0x988))
                             (WdfDriverGlobals,param_3,*(undefined4 *)(puVar9 + 2));
        local_60 = local_d0;
        local_68 = local_d8;
        if (bVar16) {
          local_110 = puVar9[3];
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x468))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),&local_118,local_1c0,
                             puVar9);
          if (-1 < iVar3) {
            puVar6 = (undefined8 *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,*puVar9,
                                PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110);
            *puVar6 = puVar9;
            goto LAB_140029d1c;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar3;
          }
          uVar11 = 0xa4;
LAB_140029dbd:
          uVar2 = 2;
          goto LAB_1400299a8;
        }
LAB_140029d1c:
        if ((*(uint *)(param_1 + 0x314) & 1) == 0) {
          iVar3 = (**(code **)(WdfFunctions_01015 + 0x468))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),&local_a8,local_1c0,
                             puVar9 + 1);
          if (iVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar3;
            }
            uVar11 = 0xa5;
            goto LAB_140029dbd;
          }
          puVar6 = (undefined8 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,puVar9[1],
                              PTR__WDF_GPIO_INTERRUPT_OBJECT_CONTEXT_TYPE_INFO_14001e110);
          *puVar6 = puVar9;
        }
      }
      uVar13 = uVar13 + 1;
      if (*(ushort *)(param_1 + 0x2d8) <= uVar13) {
        return iVar3;
      }
    } while( true );
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return iVar3;
  }
  uVar11 = 0xa2;
LAB_1400299a0:
  uVar2 = 1;
LAB_1400299a8:
  WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,uVar2,uVar11,
                     &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,"GpiopSetupBankInterrupts",
                     (char)iVar3);
  return iVar3;
}



===== GpiopUninitialize @ 140029e54 =====

void GpiopUninitialize(void)

{
  if (GpioHubEmergencyThread != 0) {
    KeSetEvent(&GpioHubEmergencyTerminateEvent,0,0);
  }
  if (GpioHubDevice != 0) {
    GpioClxEvtDeviceContextCleanup(GpioHubDevice);
  }
  if (GpioHubEmergencyThread != 0) {
    KeWaitForSingleObject(GpioHubEmergencyThread,0,0,0,0);
    ObfDereferenceObject(GpioHubEmergencyThread);
  }
  return;
}



===== GpiopValidateClientBankPowerInformation @ 140029ed0 =====

undefined8 GpiopValidateClientBankPowerInformation(longlong param_1,short *param_2)

{
  ushort uVar1;
  undefined **in_RAX;
  longlong lVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  
  uVar3 = 1;
  if (*param_2 == 0) {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar2 = *(longlong *)(param_1 + 0x88);
      uVar4 = 0xb7;
      uVar3 = 1;
      uVar1 = 0;
LAB_140029f3f:
      in_RAX = (undefined **)
               WPP_RECORDER_SF_sDD(*(undefined8 *)(lVar2 + 0x298),param_2,1,uVar4,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                   "GpiopValidateClientBankPowerInformation",(char)uVar1,uVar3);
    }
  }
  else {
    uVar1 = param_2[1];
    param_2 = (short *)0x28;
    if (0x27 < uVar1) goto LAB_140029f6a;
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x28;
      lVar2 = *(longlong *)(param_1 + 0x88);
      uVar4 = 0xb8;
      goto LAB_140029f3f;
    }
  }
  uVar3 = 0;
LAB_140029f6a:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar3);
}



===== GpiopValidateClientControllerBasicInformation @ 140029f7c =====

undefined1 GpiopValidateClientControllerBasicInformation(longlong param_1,short *param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  if (*param_2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),param_2,1,0xb9,
                          &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                          "GpiopValidateClientControllerBasicInformation",0,1);
    }
  }
  else if ((ushort)param_2[1] < 0x10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),param_2,1,0xba,
                          &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                          "GpiopValidateClientControllerBasicInformation",(char)param_2[1],0x10);
    }
  }
  else {
    uVar2 = param_2[2];
    if (((uVar2 == 0) || (bVar1 = *(byte *)(param_2 + 3), bVar1 == 0)) || (uVar2 < bVar1)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),param_2,1,0xbb,
                            &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                            "GpiopValidateClientControllerBasicInformation",(char)uVar2,
                            (char)param_2[3]);
      }
    }
    else if (bVar1 < 0x41) {
      if (*(uint *)(param_2 + 6) < 0x100) {
        if (((byte)*(uint *)(param_2 + 6) & 0x11) != 0x10) {
          return 1;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar3 = 0xbe;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        uVar3 = 0xbd;
      }
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,1,uVar3,
                        &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                        "GpiopValidateClientControllerBasicInformation");
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,1,0xbc,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopValidateClientControllerBasicInformation",bVar1);
    }
  }
  return 0;
}



===== GpiopValidateControllerFunctionBankMappings @ 14002a18c =====

undefined1 GpiopValidateControllerFunctionBankMappings(longlong param_1,short *param_2)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  if (*param_2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar2 = *(undefined8 *)(param_1 + 0x298);
    uVar5 = 1;
    uVar3 = 0xc1;
    uVar4 = 0;
  }
  else {
    puVar1 = (ushort *)(param_2 + 1);
    param_2 = (short *)0x8;
    if (7 < *puVar1) {
      return 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar5 = 8;
    uVar3 = 0xc2;
    uVar4 = (undefined1)*puVar1;
    uVar2 = *(undefined8 *)(param_1 + 0x298);
  }
  WPP_RECORDER_SF_sDD(uVar2,param_2,1,uVar3,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                      "GpiopValidateControllerFunctionBankMappings",uVar4,uVar5);
  return 0;
}



===== GpiopValidateInterruptBindings @ 14002a238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
GpiopValidateInterruptBindings
          (longlong param_1,ulonglong param_2,undefined8 param_3,short *param_4,uint param_5)

{
  uint uVar1;
  char *pcVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined2 uVar5;
  
  if (*param_4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar5 = 0xbf;
    param_5 = 1;
    uVar1 = 0;
    uVar3 = param_2;
  }
  else {
    uVar3 = (ulonglong)param_5;
    uVar1 = (uint)(ushort)param_4[1];
    if (uVar1 <= param_5) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_2);
      uVar4 = 0;
      if (*(short *)(param_1 + 0x2d8) == 0) {
        return 1;
      }
      do {
        if (*(uint *)(param_4 + (ulonglong)uVar4 * 2 + 4) != 0xffff) {
          if (uVar1 <= *(uint *)(param_4 + (ulonglong)uVar4 * 2 + 4)) {
            return 0;
          }
          pcVar2 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2);
          if (*pcVar2 != '\x02') {
            return 0;
          }
        }
        uVar4 = uVar4 + 1;
        if (*(ushort *)(param_1 + 0x2d8) <= uVar4) {
          return 1;
        }
      } while( true );
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar5 = 0xc0;
  }
  WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar3,1,uVar5,
                      &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                      "GpiopValidateInterruptBindings",(char)uVar1,(char)param_5);
  return 0;
}



===== GpiopValidateRegistrationPacketPhase1 @ 14002a388 =====

undefined8 GpiopValidateRegistrationPacketPhase1(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined **in_RAX;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined8 in_stack_ffffffffffffffc8;
  
  uVar3 = 0;
  if (*param_1 == 0) {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_RAX = (undefined **)
               WPP_RECORDER_SF_sDD(GpioLogHandle,0,1,0xc3,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                   "GpiopValidateRegistrationPacketPhase1",0,1);
    }
    goto LAB_14002a63f;
  }
  uVar2 = *(uint *)(param_1 + 2);
  if ((3 < *param_1) &&
     (in_RAX = (undefined **)(ulonglong)(uVar2 & 0x7fffffff), 1 < (uVar2 & 0x7fffffff))) {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_RAX = (undefined **)
               WPP_RECORDER_SF_sD(GpioLogHandle,2,1,0xc4,
                                  &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                  "GpiopValidateRegistrationPacketPhase1",(char)uVar2);
    }
    goto LAB_14002a63f;
  }
  uVar1 = param_1[1];
  if (uVar1 < 0xb0) {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_RAX = (undefined **)
               WPP_RECORDER_SF_sDD(GpioLogHandle,(ulonglong)uVar1,1,0xc5,
                                   &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                   "GpiopValidateRegistrationPacketPhase1",0xb0,(char)uVar1);
    }
    goto LAB_14002a63f;
  }
  if ((((*(longlong *)(param_1 + 0xc) == 0) || (*(longlong *)(param_1 + 0x10) == 0)) ||
      (*(longlong *)(param_1 + 0x14) == 0)) ||
     ((*(longlong *)(param_1 + 0x18) == 0 || (*(longlong *)(param_1 + 0x1c) == 0)))) {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a63f;
    uVar4 = 0xc6;
  }
  else if ((*(longlong *)(param_1 + 0x24) == 0) ||
          (((*(longlong *)(param_1 + 0x28) != 0 && (*(longlong *)(param_1 + 0x30) != 0)) &&
           (*(longlong *)(param_1 + 0x34) != 0)))) {
    if (*(longlong *)(param_1 + 0x3c) == 0) {
LAB_14002a573:
      if ((int)uVar2 < 0) {
        if (uVar1 != 0x148) {
          in_RAX = &WPP_RECORDER_INITIALIZED;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_RAX = (undefined **)
                     WPP_RECORDER_SF_sqDD
                               (GpioLogHandle,2,1,0xca,in_stack_ffffffffffffffc8,
                                "GpiopValidateRegistrationPacketPhase1",(char)param_1,(char)uVar1,
                                0x48);
          }
          goto LAB_14002a63f;
        }
        if ((*(longlong *)(param_1 + 0x84) != 0) && (*(longlong *)(param_1 + 0x88) == 0)) {
          in_RAX = &WPP_RECORDER_INITIALIZED;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002a63f;
          uVar4 = 0xcb;
          goto LAB_14002a611;
        }
      }
      uVar3 = 1;
      goto LAB_14002a63f;
    }
    if (*(longlong *)(param_1 + 0x40) == 0) {
      in_RAX = &WPP_RECORDER_INITIALIZED;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a63f;
      uVar4 = 200;
    }
    else {
      if ((*(longlong *)(param_1 + 0x48) != 0) || (*(longlong *)(param_1 + 0x44) != 0))
      goto LAB_14002a573;
      in_RAX = &WPP_RECORDER_INITIALIZED;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a63f;
      uVar4 = 0xc9;
    }
  }
  else {
    in_RAX = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a63f;
    uVar4 = 199;
  }
LAB_14002a611:
  in_RAX = (undefined **)
           WPP_RECORDER_SF_sq(GpioLogHandle,2,1,uVar4,
                              &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                              "GpiopValidateRegistrationPacketPhase1",(char)param_1);
LAB_14002a63f:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar3);
}



===== GpiopValidateRegistrationPacketPhase2 @ 14002a650 =====

undefined1 GpiopValidateRegistrationPacketPhase2(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (((*(uint *)(param_1 + 0x314) & 0x40) == 0) || (*(longlong *)(param_1 + 0x208) != 0)) {
    uVar1 = 1;
    if (*(ushort *)(param_1 + 0x150) < 2) {
      if ((199 < *(ushort *)(param_1 + 0x152)) && (*(longlong *)(param_1 + 0x210) != 0)) {
        *(undefined8 *)(param_1 + 0x210) = 0;
      }
    }
    else if (2 < *(ushort *)(param_1 + 0x150)) {
      return 1;
    }
    if ((0xcf < *(ushort *)(param_1 + 0x152)) && (*(longlong *)(param_1 + 0x218) != 0)) {
      *(undefined8 *)(param_1 + 0x218) = 0;
    }
    if ((0xd7 < *(ushort *)(param_1 + 0x152)) && (*(longlong *)(param_1 + 0x220) != 0)) {
      *(undefined8 *)(param_1 + 0x220) = 0;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqq(*(undefined8 *)(param_1 + 0x298));
  }
  return uVar1;
}



===== GpioHubEnableInterrupt @ 14002a730 =====

uint GpioHubEnableInterrupt
               (undefined8 param_1,uint param_2,int param_3,uint param_4,undefined8 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong lVar5;
  ulonglong *puVar6;
  longlong local_58;
  ushort local_50 [4];
  longlong lStack_48;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  int local_30;
  uint local_2c;
  undefined8 local_28;
  ulonglong *local_20;
  
  local_58 = 0;
  plVar4 = &local_58;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  lStack_48 = 0;
  puVar2 = GpioHubpFindGpioEntry(1,(ushort *)(ulonglong)param_2,plVar4);
  if (puVar2 == (undefined8 *)0x0) {
    uVar1 = GpioHubpMapGsivToControllerName(param_2,(undefined8 *)local_50,plVar4);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DD(GpioLogHandle,2,8,10,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                           (char)param_2,(char)uVar1);
      }
      goto LAB_14002a8ff;
    }
    puVar2 = GpioHubpFindGpioEntry(2,local_50,(undefined8 *)0x0);
    if (puVar2 == (undefined8 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DSD();
      }
      uVar1 = 0xc000a121;
      goto LAB_14002a8ff;
    }
    local_58 = 0;
    uVar3 = GpioHubpCreateVirqMapping(param_2,puVar2,&local_58);
    uVar1 = (uint)uVar3;
    if (-1 < (int)uVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DSq();
      }
      goto LAB_14002a893;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DSD();
    }
  }
  else {
LAB_14002a893:
    lVar5 = puVar2[0xc];
    puVar6 = (ulonglong *)(local_58 + 0x20);
    uVar1 = param_2;
    uVar3 = GpiopIsAcpiEventInterrupt(lVar5,param_2);
    if ((char)uVar3 == '\0') {
      local_3c = 0;
      local_34 = 0;
      local_40 = 0;
      local_28 = param_5;
      local_38 = param_2;
      local_30 = param_3;
      local_2c = param_4;
      local_20 = puVar6;
      uVar1 = GpiopForwardInterruptRequestToQueue(lVar5,&local_40);
    }
    else {
      uVar1 = GpiopEnableInterrupt(lVar5,uVar1,param_3,param_4,param_5,puVar6);
    }
  }
  GpioHubpReleaseGpioEntryShared((longlong)puVar2,'\x01');
LAB_14002a8ff:
  if (lStack_48 != 0) {
    ExFreePoolWithTag(lStack_48,0x786c4347);
  }
  return uVar1;
}



===== GpioHubQueryPrimaryInterruptInformation @ 14002a940 =====

uint GpioHubQueryPrimaryInterruptInformation(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ulonglong *puVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  char cVar13;
  ushort *puVar14;
  undefined2 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  char local_res20;
  undefined1 local_78;
  undefined4 local_74;
  ulonglong local_70;
  ulonglong local_68;
  ushort local_60 [4];
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  uVar16 = 0;
  uVar17 = 0;
  uVar18 = 0;
  uVar19 = 0;
  local_74 = 0;
  local_res20 = '\0';
  local_70 = local_70 & 0xffffffff00000000;
  local_78 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  uStack_58 = 0;
  bVar6 = GpioHubpIsSecondaryInterrupt(param_2);
  if (!bVar6) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(GpioLogHandle,2,8,0xe,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                        (char)param_2);
    }
    return 0xc000000d;
  }
  bVar5 = false;
  bVar6 = false;
  do {
    local_68 = (ulonglong)param_2;
    uVar12 = 0;
    puVar14 = (ushort *)(ulonglong)param_2;
    puVar11 = GpioHubpFindGpioEntry(1,puVar14,(undefined8 *)0x0);
    if (puVar11 == (undefined8 *)0x0) {
      puVar14 = local_60;
      uVar8 = GpioHubpMapGsivToControllerName(param_2,(undefined8 *)puVar14,uVar12);
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDD(GpioLogHandle,puVar14,8,0xf,
                              &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                              "GpioHubQueryPrimaryInterruptInformation",(char)param_2,(char)uVar8);
        }
      }
      else {
        puVar11 = GpioHubpFindGpioEntry(2,local_60,(undefined8 *)0x0);
        if (puVar11 == (undefined8 *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
LAB_14002aa6a:
            WPP_RECORDER_SF_sDSD();
          }
        }
        else {
          uVar12 = GpioHubpCreateVirqMapping(param_2,puVar11,(undefined8 *)0x0);
          if ((int)uVar12 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
            goto LAB_14002aa6a;
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDSq();
          }
        }
        puVar14 = (ushort *)0x786c4347;
        ExFreePoolWithTag(uStack_58,0x786c4347);
        if (puVar11 != (undefined8 *)0x0) goto LAB_14002aac3;
        uVar8 = 0xc0000225;
      }
LAB_14002ac0c:
      cVar13 = local_res20;
      if ((!bVar6) && (local_res20 == '\0')) goto LAB_14002ac8e;
      break;
    }
LAB_14002aac3:
    lVar2 = puVar11[0xc];
    iVar9 = 0;
    local_70 = 0;
    LOCK();
    iVar10 = *(int *)(lVar2 + 0x2d0);
    if (iVar10 == 0) {
      *(int *)(lVar2 + 0x2d0) = 0;
    }
    else {
      iVar9 = iVar10;
    }
    UNLOCK();
    if (iVar9 < 5) {
LAB_14002ab2a:
      local_50 = 0xffffffffffffffff;
      param_2 = *(uint *)(lVar2 + 8);
      uVar19 = (undefined4)(uStack_48 >> 0x20);
      uStack_48 = uStack_48 & 0xffffffffffff0000;
      local_50._0_4_ = 0xffffffff;
      local_50._4_4_ = 0xffffffff;
      local_74 = 0;
      local_70 = local_70 & 0xffffffff00000000;
      uVar16 = (undefined4)local_50;
      uVar17 = local_50._4_4_;
      uVar18 = (undefined4)uStack_48;
    }
    else {
      puVar14 = (ushort *)0x0;
      iVar10 = GpiopQueryBankIdFromGsivOrConnectionId
                         (lVar2,1,local_68,(longlong *)&local_70,(byte *)0x0,(undefined1 *)0x0);
      if (iVar10 < 0) goto LAB_14002ab2a;
      puVar1 = (undefined8 *)(local_70 + 0x90);
      puVar3 = (undefined4 *)(local_70 + 0x94);
      local_50 = *puVar1;
      puVar4 = (ulonglong *)(local_70 + 0x98);
      uVar19 = *(undefined4 *)(local_70 + 0x9c);
      uStack_48 = *puVar4;
      local_74 = *(undefined4 *)(local_70 + 0x138);
      param_2 = *(uint *)(local_70 + 0x130);
      local_70 = CONCAT44(local_70._4_4_,*(undefined4 *)(local_70 + 0x13c));
      uVar16 = *(undefined4 *)puVar1;
      uVar17 = *puVar3;
      uVar18 = *(undefined4 *)puVar4;
    }
    local_78 = *(undefined1 *)(lVar2 + 6);
    uVar8 = 0;
    if (param_2 == 0xffffffff) {
      uVar8 = 0xc0000001;
    }
    else {
      bVar7 = GpioHubpIsSecondaryInterrupt(param_2);
      bVar6 = bVar5;
      if (!bVar7) {
        bVar6 = true;
        bVar5 = true;
      }
    }
    uVar12 = CONCAT71((int7)((ulonglong)puVar14 >> 8),1);
    GpioHubpReleaseGpioEntryShared((longlong)puVar11,'\x01');
    if ((int)uVar8 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dq(GpioLogHandle,uVar12,8,0x13,
                           &WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,(char)param_2,
                           (char)puVar11);
      }
      goto LAB_14002ac0c;
    }
    local_res20 = '\x01';
    cVar13 = '\x01';
  } while (!bVar6);
  param_3[8] = local_74;
  param_3[9] = (undefined4)local_70;
  *param_3 = 0x10028;
  param_3[1] = param_2;
  *(undefined1 *)(param_3 + 2) = local_78;
  param_3[4] = uVar16;
  param_3[5] = uVar17;
  param_3[6] = uVar18;
  param_3[7] = uVar19;
  if (bVar6) {
    uVar8 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar15 = 0x14;
  }
  else {
    if (cVar13 == '\0') {
LAB_14002ac8e:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar8;
      }
      WPP_RECORDER_SF_(GpioLogHandle,2,8,0x16,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids);
      return uVar8;
    }
    uVar8 = 0xc0000016;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000016;
    }
    uVar15 = 0x15;
  }
  WPP_RECORDER_SF_D(GpioLogHandle,4,8,uVar15,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                    (char)param_2);
  return uVar8;
}



===== GpioHubpInitialize @ 14002ace0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioHubpInitialize(int param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  ulonglong local_40 [5];
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_40[0] = (ulonglong)(uint)local_40[0];
  local_58 = (ulonglong)(uint)local_58;
  if (param_1 == 0) {
    DAT_14001e648 = &GpioHubList;
    GpioHubList = &GpioHubList;
    DAT_14001e6c8 = &GpioHubVirqList;
    GpioHubVirqList = &GpioHubVirqList;
    DAT_14001e6b8 = &GpioHubSignalList;
    GpioHubSignalList = &GpioHubSignalList;
    DAT_14001e658 = &GpioHubInterruptReplayList;
    GpioHubInterruptReplayList = &GpioHubInterruptReplayList;
    KeInitializeSpinLock(&GpioHubListSpinLock);
    KeInitializeSpinLock(&GpioHubSignalReplayListLock);
    GpioHubDpcRunning = 0;
    iVar1 = GpioHubpInitializeEmergencyServices();
  }
  else {
    iVar1 = GpioHubpCreateHubDeviceObject(param_3);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(GpioLogHandle,2,1,0x17,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                           "GpioHubpInitialize",(char)iVar1);
      }
    }
    else {
      GpioHubResourceHubTarget = 0;
      local_58 = 0x18;
      pcStack_50 = GpioHubpProcessSignalReplayList;
      local_10 = 0;
      local_40[2] = 0;
      local_48 = 0;
      uStack_18 = 0;
      local_40[4] = GpioHubDevice;
      local_40[1] = 0;
      local_40[0] = 0x38;
      local_40[3] = 0x100000001;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x378))
                        (WdfDriverGlobals,&local_58,local_40,&GpioHubDpc);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x18;
        uVar2 = 1;
      }
      else {
        iVar1 = GpioHubpInitializeSecondaryICInterface(param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x19;
        uVar2 = 2;
      }
      WPP_RECORDER_SF_D(GpioLogHandle,2,uVar2,uVar3,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids
                        ,(char)iVar1);
    }
  }
  return iVar1;
}



===== GpioHubpInitializeEmergencyServices @ 14002af04 =====

int GpioHubpInitializeEmergencyServices(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res10 = 0;
  local_34 = 0;
  KeInitializeEvent(&GpioHubEmergencyWorkEvent,0,0);
  KeInitializeEvent(&GpioHubEmergencyTerminateEvent,0,0);
  local_res8 = 0;
  local_30 = 0;
  local_28 = 0;
  DAT_14001e668 = &GpioHubEmergencyWorkQueue;
  GpioHubEmergencyWorkQueue = &GpioHubEmergencyWorkQueue;
  local_38 = 0x30;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = PsCreateSystemThread(&local_res8,0x1fffff,&local_38,0,0,GpioHubpEmergencyWorkerThread,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x21;
  }
  else {
    iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
    ZwClose(local_res8);
    if (-1 < iVar1) {
      GpioHubEmergencyThread = local_res10;
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x22;
  }
  WPP_RECORDER_SF_sD(GpioLogHandle,2,1,uVar2,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                     "GpioHubpInitializeEmergencyServices",(char)iVar1);
  return iVar1;
}



===== GpioHubpInitializeSecondaryICInterface @ 14002b094 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GpioHubpInitializeSecondaryICInterface(undefined8 param_1)

{
  int iVar1;
  undefined4 local_res10 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  
  _DAT_14001e630 = 0;
  _GpioHalSecondaryInformation = 0;
  _DAT_14001e608 = 0;
  local_res10[0] = 0x38;
  DAT_14001e610 = 0;
  DAT_14001e618 = 0;
  DAT_14001e620 = 0;
  DAT_14001e628 = 0;
  iVar1 = (**(code **)(HalDispatchTable_exref + 8))
                    (0x1c,0x38,&GpioHalSecondaryInformation,local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(GpioLogHandle,2,1,0x1c,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                         "GpioHubpInitializeSecondaryICInterface",(char)iVar1);
    }
  }
  else if (DAT_14001e608 != 0) {
    local_54 = (undefined2)_DAT_14001e608;
    local_60 = 0;
    local_52 = 0;
    local_68 = 0x10058;
    local_58 = DAT_14001e604;
    local_48 = GpioHubEnableInterrupt;
    local_40 = GpioHubDisableInterrupt;
    local_38 = GpioHubMaskInterrupt;
    local_30 = GpioHubUnmaskInterrupt;
    local_28 = GpioHubQueryPrimaryInterruptInformation;
    local_20 = GpioHubRequestInterrupt;
    local_18 = GpioHubQueryLineInformation;
    local_50 = param_1;
    iVar1 = (**(code **)(HalDispatchTable_exref + 0x10))(0xd,0x58,&local_68);
  }
  return iVar1;
}



===== GpioHubpMapGsivToControllerName @ 14002b200 =====

uint GpioHubpMapGsivToControllerName(uint param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar1 = GpiopQueryResourceHubBiosDescriptor
                    (GpioHubDevice,&GpioHubResourceHubTarget,
                     CONCAT71((int7)((ulonglong)param_3 >> 8),1),(ulonglong)param_1,local_res18);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b2aa;
    uVar2 = 0x1f;
  }
  else {
    uVar1 = GpioUtilGetResourceName(local_res18[0],param_2);
    if ((-1 < (int)uVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
    goto LAB_14002b2aa;
    uVar2 = 0x20;
  }
  WPP_RECORDER_SF_DD(GpioLogHandle,2,8,uVar2,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids,
                     (char)param_1,(char)uVar1);
LAB_14002b2aa:
  if (local_res18[0] != 0) {
    ExFreePoolWithTag(local_res18[0],0x786c4347);
  }
  return uVar1;
}



===== GpioHubpRegisterGpioDevice @ 14002b2e4 =====

undefined8 GpioHubpRegisterGpioDevice(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x68,0x786c4347);
  uVar3 = 0;
  if (puVar2 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(GpioLogHandle,2,1,0x1d,&WPP_646c6e91241e31ad53715435cd2a8152_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  else {
    puVar2[0xc] = param_1[2];
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    KeInitializeEvent(puVar2 + 3,1,1);
    puVar1 = puVar2 + 10;
    puVar2[0xb] = puVar1;
    *puVar1 = puVar1;
    puVar1 = puVar2 + 6;
    puVar2[7] = puVar1;
    *puVar1 = puVar1;
    puVar1 = puVar2 + 8;
    puVar2[9] = puVar1;
    *puVar1 = puVar1;
    GpioHubpAddGpioEntry((longlong)puVar2);
  }
  return uVar3;
}



===== GpioHubpUnregisterSecondaryInterruptInterface @ 14002b3c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioHubpUnregisterSecondaryInterruptInterface(void)

{
  if (DAT_14001e628 != (code *)0x0) {
    (*DAT_14001e628)();
  }
  return;
}



===== GpiopDebounceInitializeContext @ 14002b3e8 =====

void GpiopDebounceInitializeContext
               (byte param_1,char param_2,byte param_3,int param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  
  memset(param_6 + 1,0,0x5c);
  *param_6 = 1;
  uVar2 = ((uint)param_1 ^ param_6[1]) & 1 ^ param_6[1];
  if (param_2 == '\0') {
    iVar1 = 0;
  }
  else {
    if (param_4 == 1) {
      iVar1 = 3;
    }
    else {
      iVar1 = (param_4 == 2) + 1;
    }
    if (((param_5 != 0) ||
        (param_5 = GpioGlobalDebounceModelOverride, GpioGlobalDebounceModelOverride != 0)) &&
       ((iVar1 != 1 || (param_5 != 3)))) {
      iVar1 = param_5;
    }
  }
  uVar2 = (iVar1 * 2 ^ uVar2) & 0xe ^ uVar2;
  param_6[1] = ((uint)param_3 << 4 ^ uVar2) & 0x10 ^ uVar2;
  param_6[2] = 1;
  return;
}



===== GpioClxEvtHandleInterruptWorker @ 14002b4c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtHandleInterruptWorker(undefined8 param_1)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  ulonglong *puVar3;
  
  puVar3 = (ulonglong *)PTR__WDF_GPIO_INTERRUPT_WORK_ITEM_CONTEXT_TYPE_INFO_14001e048;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  puVar1 = (ulonglong *)*puVar2;
  LOCK();
  *(undefined4 *)(puVar1 + 0x15) = 0;
  UNLOCK();
  GpiopIssueDeferredInterruptActivities(puVar1,param_1,puVar3);
  return;
}



===== GpiopInitializeInterruptRegistryOptions @ 14002b504 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpiopInitializeInterruptRegistryOptions(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_f8 [32];
  int local_c8;
  int local_c4;
  undefined8 local_c0;
  wchar_t *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  wchar_t local_a0 [28];
  wchar_t local_68 [40];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_c4 = 0;
  local_c8 = 0;
  builtin_wcsncpy(local_68,L"InterruptStormMitigationOverride",0x21);
  local_b8 = local_68;
  builtin_wcsncpy(local_a0,L"MaxInterruptsPerSecond",0x17);
  local_a8 = local_a0;
  local_c0 = 0x420040;
  local_b0 = 0x2e002c;
  uVar2 = param_1;
  iVar1 = GpioUtilQueryRegistryFlags(param_1,param_1,param_2,(longlong)&local_c0,&local_c8);
  if (-1 < iVar1) {
    if (local_c8 == 0) {
      GpioInterruptStormMitigationMode = 0;
    }
    else if (local_c8 == 1) {
      GpioInterruptStormMitigationMode = 2;
    }
  }
  iVar1 = GpioUtilQueryRegistryFlags(uVar2,param_1,param_2,(longlong)&local_b0,&local_c4);
  if (-1 < iVar1) {
    GpioMaxInterruptsPerSecond = local_c4;
  }
  return;
}



===== GpiopRegisterWithPowerFramework @ 14002b64c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopRegisterWithPowerFramework(longlong param_1)

{
  ushort *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  ushort uVar9;
  longlong lVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  uint uVar14;
  short sVar15;
  uint uVar16;
  
  puVar1 = (ushort *)(param_1 + 0x2d8);
  uVar14 = (uint)*puVar1;
  lVar8 = param_1;
  uVar5 = GpiopGetBaseRegistrationBufferSize();
  iVar11 = 0;
  uVar9 = 0;
  uVar16 = uVar14 * 0x20 + -0x19 + (int)uVar5 & 0xfffffff8;
  if ((ushort)uVar14 != 0) {
    do {
      uVar6 = (ulonglong)uVar9;
      uVar9 = uVar9 + 1;
      iVar11 = iVar11 + 1 + *(int *)(uVar6 * 400 + 0x160 + *(longlong *)(lVar8 + 0x2e0));
    } while (uVar9 < (ushort)uVar14);
  }
  puVar7 = (undefined4 *)ExAllocatePool2(0x100,uVar16 + iVar11 * 0x18,0x786c4347);
  if (puVar7 == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,3,0x14,
                        &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                        "GpiopRegisterWithPowerFramework");
    }
    iVar11 = -0x3fffff66;
  }
  else {
    GpiopInitializePrimaryDevice(puVar7,(uint)*puVar1);
    uVar6 = 0;
    puVar12 = (undefined8 *)((ulonglong)uVar16 + (longlong)puVar7);
    if (*puVar1 != 0) {
      do {
        sVar15 = (short)uVar6;
        lVar10 = uVar6 * 400 + *(longlong *)(lVar8 + 0x2e0);
        GpiopInitializeIdleStateBufferAndCount
                  ((longlong)puVar7,(uint)uVar6,puVar12,*(int *)(lVar10 + 0x160) + 1);
        *puVar12 = 0;
        puVar12[1] = 0;
        *(undefined4 *)(puVar12 + 2) = 0;
        puVar13 = puVar12 + 3;
        if (*(int *)(lVar10 + 0x160) == 1) {
          uVar2 = *(undefined4 *)(lVar10 + 0x16c);
          uVar3 = *(undefined4 *)(lVar10 + 0x170);
          uVar4 = *(undefined4 *)(lVar10 + 0x174);
          *(undefined4 *)puVar13 = *(undefined4 *)(lVar10 + 0x168);
          *(undefined4 *)((longlong)puVar12 + 0x1c) = uVar2;
          *(undefined4 *)(puVar12 + 4) = uVar3;
          *(undefined4 *)((longlong)puVar12 + 0x24) = uVar4;
          puVar12[5] = *(undefined8 *)(lVar10 + 0x178);
          puVar13 = puVar12 + 6;
        }
        uVar6 = (ulonglong)(ushort)(sVar15 + 1U);
        puVar12 = puVar13;
      } while ((ushort)(sVar15 + 1U) < *(ushort *)(param_1 + 0x2d8));
    }
    (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
    iVar11 = GpiopRegisterPrimaryDeviceInternal();
    if ((iVar11 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,3,0x15,
                         &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                         "GpiopRegisterWithPowerFramework",(char)iVar11);
    }
    ExFreePoolWithTag(puVar7,0x786c4347);
  }
  return iVar11;
}



===== GpiopStartRuntimePowerManagement @ 14002b88c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopStartRuntimePowerManagement(longlong param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,3,0x16,
                       &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                       "GpiopStartRuntimePowerManagement",(char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0xdb0))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8),0,0,0x5bf,
             "onecore\\drivers\\gpio\\gpioclx\\sys\\power.c");
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),4,3,0x17,
                       &WPP_537c029ff2583a293d9fdee3d37c6e45_Traceguids,
                       "GpiopStartRuntimePowerManagement",(char)param_1);
  }
  PoFxStartDevicePowerManagement(*(undefined8 *)(param_1 + 0x118));
  return;
}



===== GpioUtilEnumerateNamespaceChildren @ 14002b98c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014002bae0) */
/* WARNING: Removing unreachable block (ram,0x00014002bae9) */
/* WARNING: Removing unreachable block (ram,0x00014002bb0c) */
/* WARNING: Removing unreachable block (ram,0x00014002bb25) */
/* WARNING: Removing unreachable block (ram,0x00014002bb60) */
/* WARNING: Removing unreachable block (ram,0x00014002bbbe) */
/* WARNING: Removing unreachable block (ram,0x00014002bbce) */
/* WARNING: Removing unreachable block (ram,0x00014002bc02) */
/* WARNING: Removing unreachable block (ram,0x00014002bc1b) */
/* WARNING: Removing unreachable block (ram,0x00014002bc29) */
/* WARNING: Removing unreachable block (ram,0x00014002bc2f) */
/* WARNING: Removing unreachable block (ram,0x00014002bc34) */
/* WARNING: Removing unreachable block (ram,0x00014002bc41) */
/* WARNING: Removing unreachable block (ram,0x00014002bc4a) */
/* WARNING: Removing unreachable block (ram,0x00014002bc5a) */
/* WARNING: Removing unreachable block (ram,0x00014002bc79) */

int GpioUtilEnumerateNamespaceChildren(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x2c8));
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c020);
  if (iVar1 == -0x7ffffffb) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(param_1 + 0x298),uVar2,0xb,0xb,
                 &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,
                 "GpioUtilEnumerateNamespaceChildren",0,0,0xf);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,0xb,10,
                       &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,
                       "GpioUtilEnumerateNamespaceChildren",(char)iVar1);
  }
  return -0x3febfff1;
}



===== GpioUtilEvaluateAcpiMethod @ 14002bd14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioUtilEvaluateAcpiMethod
              (undefined8 param_1,int param_2,int *param_3,longlong *param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  int local_res18 [4];
  longlong local_68 [3];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int *local_40;
  int local_38;
  undefined4 local_34;
  
  local_68[0] = 0;
  local_res18[0] = 0;
  local_res18[1] = 0;
  local_44 = 0;
  local_50 = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  if (param_3 == (int *)0x0) {
    if (param_2 == 0) {
      return -0x3fffff11;
    }
    param_3 = local_res18;
    local_res18[1] = param_2;
    local_res18[0] = 0x42696541;
  }
  else {
    iVar3 = *param_3;
    if (iVar3 != 0x42696541) {
      if (iVar3 == 0x43696541) {
        iVar3 = param_3[2];
      }
      else if (iVar3 == 0x49696541) {
        iVar3 = 0xc;
      }
      else {
        if (iVar3 != 0x53696541) {
          return -0x3fffff10;
        }
        iVar3 = param_3[2] + 0xf;
      }
      goto LAB_14002bd79;
    }
  }
  iVar3 = 8;
LAB_14002bd79:
  bVar4 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_44 = 0;
  local_34 = 0;
  uVar5 = 0x200;
  local_48 = 1;
  local_40 = param_3;
  local_38 = iVar3;
  while( true ) {
    lVar2 = ExAllocatePool2(0x100,uVar5,0x786c4347);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    local_4c = 0;
    local_68[1] = 1;
    local_68[2] = lVar2;
    local_50 = uVar5;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar1,0,0x32c004,&local_48,local_68 + 1,0,local_68);
    bVar4 = bVar4 + 1;
    if (iVar3 != -0x7ffffffb) break;
    uVar5 = *(undefined4 *)(lVar2 + 4);
    ExFreePoolWithTag(lVar2,0x786c4347);
    if (1 < bVar4) {
      return -0x7ffffffb;
    }
  }
  if (iVar3 < 0) {
    ExFreePoolWithTag(lVar2,0x786c4347);
    return iVar3;
  }
  if (local_68[0] == 0) {
    *param_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      return iVar3;
    }
    *param_5 = 0;
    return iVar3;
  }
  *param_4 = lVar2;
  if (param_5 == (undefined4 *)0x0) {
    return iVar3;
  }
  *param_5 = (int)local_68[0];
  return iVar3;
}



===== GpioUtilGetIdFromFileName @ 14002bf28 =====

uint GpioUtilGetIdFromFileName(short *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  short *psVar6;
  undefined8 local_res8;
  ushort local_28;
  undefined6 uStack_26;
  longlong lStack_20;
  undefined8 local_18;
  longlong lStack_10;
  
  sVar3 = *param_1;
  for (psVar6 = *(short **)(param_1 + 4); (sVar3 != 0 && (*psVar6 == 0x5c)); psVar6 = psVar6 + 1) {
    sVar3 = sVar3 + -2;
  }
  local_res8 = 0;
  _local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  lStack_10 = 0;
  uVar4 = RtlUnicodeStringInitWorker((short *)&local_28,psVar6);
  uVar1 = _local_28;
  if (-1 < (int)uVar4) {
    if (0x1f < local_28) {
      uVar5 = 0;
      do {
        sVar3 = *(short *)(lStack_20 + (ulonglong)uVar5 * 2);
        if (((9 < (ushort)(sVar3 - 0x30U)) && (5 < (ushort)(sVar3 - 0x61U))) &&
           (5 < (ushort)(sVar3 - 0x41U))) goto LAB_14002bf9a;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x10);
      sVar3 = *(short *)(lStack_20 + (ulonglong)uVar5 * 2);
      if ((sVar3 == 0x5c) || (sVar3 == 0)) {
        lStack_10 = lStack_20 + 0x10;
        _local_28 = CONCAT62((int6)((ulonglong)_local_28 >> 0x10),0x10);
        uVar2 = _local_28;
        uStack_26._0_2_ = SUB82(uVar1,2);
        local_18._0_4_ = CONCAT22((short)uStack_26 + -0x10,0x10);
        _local_28 = uVar2;
        uVar4 = RtlUnicodeStringToInteger(&local_28,0x10,(longlong)&local_res8 + 4);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        uVar4 = RtlUnicodeStringToInteger(&local_18,0x10,&local_res8);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        *param_2 = local_res8;
        return uVar4;
      }
    }
LAB_14002bf9a:
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== GpioUtilGetOpenModeFromRequest @ 14002c068 =====

char GpioUtilGetOpenModeFromRequest(longlong param_1,char param_2,undefined1 *param_3)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  
  lVar1 = *(longlong *)(param_1 + 8);
  cVar6 = '\0';
  *param_3 = 0;
  uVar5 = *(uint *)(lVar1 + 0x10);
  puVar2 = (uint *)IoGetFileObjectGenericMapping();
  uVar5 = ~uVar5;
  uVar3 = ~-(uint)((uVar5 & *puVar2) != 0) & 0x80000000;
  uVar4 = uVar3 | 0x40000000;
  if ((puVar2[1] & uVar5) != 0) {
    uVar4 = uVar3;
  }
  uVar3 = uVar4 | 0x20000000;
  if ((puVar2[2] & uVar5) != 0) {
    uVar3 = uVar4;
  }
  uVar4 = uVar3 | 0x10000000;
  if ((puVar2[3] & uVar5) != 0) {
    uVar4 = uVar3;
  }
  if ((uVar4 & 0x3fffffff) == 0) {
    uVar4 = uVar4 & 0xc0000000;
    cVar6 = uVar4 == 0x80000000;
    if (uVar4 == 0x40000000) {
      cVar6 = '\x02';
    }
    else if (uVar4 == 0xc0000000) {
      *param_3 = 1;
      cVar6 = (param_2 != '\x01') + '\x01';
    }
  }
  return cVar6;
}



===== GpioUtilGetResourceName @ 14002c134 =====

uint GpioUtilGetResourceName(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong local_res8;
  undefined8 local_18;
  char *pcStack_10;
  
  *param_2 = 0;
  param_2[1] = 0;
  local_18 = 0;
  pcStack_10 = (char *)0x0;
  if ((*(uint *)(param_1 + 4) < 0x10000) && (*(ushort *)(param_1 + 4) != 0)) {
    pcVar6 = (char *)(param_1 + 8);
    if (*pcVar6 != -0x74) {
      uVar3 = 0xc00000bb;
      goto LAB_14002c267;
    }
    cVar1 = GpioUtilIsBiosGpioDescriptorValid(pcVar6,(uint)*(ushort *)(param_1 + 4));
    if (cVar1 == '\0') {
      uVar3 = 0xc0000001;
      goto LAB_14002c267;
    }
    local_res8 = 0;
    uVar5 = (ulonglong)((uint)*(ushort *)(param_1 + 0x1b) - (uint)*(ushort *)(param_1 + 0x19));
    pcVar6 = pcVar6 + *(ushort *)(param_1 + 0x19);
    if ((pcVar6 == (char *)0x0) || (0x7fffffff < uVar5)) {
      uVar3 = 0xc000000d;
      goto LAB_14002c267;
    }
    uVar3 = RtlStringLengthWorkerA(pcVar6,uVar5,(longlong *)&local_res8);
    if ((int)uVar3 < 0) goto LAB_14002c267;
    if (local_res8 < 0x8000) {
      local_18 = CONCAT62(CONCAT42(local_18._4_4_,(short)local_res8),(short)local_res8);
      pcStack_10 = pcVar6;
      uVar2 = RtlxAnsiStringToUnicodeSize(&local_18);
      *(undefined2 *)((longlong)param_2 + 2) = uVar2;
      lVar4 = ExAllocatePool2(0x40,uVar2,0x786c4347);
      param_2[1] = lVar4;
      if (lVar4 == 0) {
        uVar3 = 0xc000009a;
        *(undefined2 *)((longlong)param_2 + 2) = 0;
      }
      else {
        uVar3 = RtlAnsiStringToUnicodeString(param_2,&local_18,0);
        if (-1 < (int)uVar3) {
          return uVar3;
        }
      }
      goto LAB_14002c267;
    }
  }
  uVar3 = 0xc0000206;
LAB_14002c267:
  if (param_2[1] != 0) {
    ExFreePoolWithTag(param_2[1],0x786c4347);
    *param_2 = 0;
    param_2[1] = 0;
  }
  return uVar3;
}



===== GpioUtilIsBiosGpioDescriptorValid @ 14002c2a0 =====

undefined1 GpioUtilIsBiosGpioDescriptorValid(char *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  
  uVar6 = 0;
  if ((0x16 < param_2) && (*param_1 == -0x74)) {
    uVar1 = *(ushort *)(param_1 + 0xe);
    if (uVar1 < param_2) {
      uVar2 = *(ushort *)(param_1 + 0x11);
      uVar4 = (uint)uVar2;
      if (uVar4 < param_2) {
        uVar3 = *(ushort *)(param_1 + 0x13);
        if ((((uVar3 <= param_2) && (uVar1 < uVar2)) && (uVar2 < uVar3)) &&
           (((param_1[3] != '\0' && ((byte)param_1[4] < 2)) &&
            ((uVar5 = uVar4 - uVar1, 1 < uVar5 && ((uVar5 & 1) == 0)))))) {
          uVar6 = 0;
          if (((ulonglong)uVar3 - (ulonglong)uVar4) - 1 < 0x7fff) {
            uVar6 = 1;
          }
        }
      }
    }
  }
  return uVar6;
}



===== GpioUtilIsDsmFunctionSupported @ 14002c334 =====

ulonglong GpioUtilIsDsmFunctionSupported
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined4 local_res18 [2];
  longlong local_res20;
  int *local_38 [2];
  
  local_res18[0] = 0;
  local_38[0] = (int *)0x0;
  local_res20 = 0;
  *param_4 = 0;
  uVar3 = GpioUtilPrepareInputParametersForDsmMethod(0,param_2,local_38);
  piVar1 = local_38[0];
  uVar5 = uVar3 & 0xffffffff;
  lVar4 = 0;
  if (-1 < (int)uVar3) {
    uVar2 = GpioUtilEvaluateAcpiMethod(param_1,local_38[0][1],local_38[0],&local_res20,local_res18);
    uVar5 = (ulonglong)uVar2;
    lVar4 = local_res20;
    if (-1 < (int)uVar2) {
      if ((local_res20 == 0) || (*(int *)(local_res20 + 8) != 1)) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,7,0,0,1);
      }
      if ((*(short *)(local_res20 + 0xc) != 2) || (*(short *)(local_res20 + 0xe) == 0)) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x138,7,0,0,2);
      }
      uVar5 = 0;
      if ((*(short *)(local_res20 + 0xe) != 0) && ((*(byte *)(local_res20 + 0x10) & 2) != 0)) {
        *param_4 = 1;
      }
    }
  }
  if (piVar1 != (int *)0x0) {
    ExFreePoolWithTag(piVar1,0x786c4347);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x786c4347);
  }
  return uVar5;
}



===== GpioUtilParseNamespaceEventPins @ 14002c470 =====

undefined8
GpioUtilParseNamespaceEventPins
          (longlong param_1,int param_2,longlong param_3,uint param_4,uint *param_5,longlong param_6
          ,uint param_7,uint *param_8)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  
  uVar9 = 0;
  *param_5 = 0;
  *param_8 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar9 = 0xc0140008;
  }
  else {
    uVar10 = 1;
    pbVar6 = (byte *)(param_1 + 8);
    if (1 < *(uint *)(param_1 + 4)) {
      do {
        pbVar6 = pbVar6 + (ulonglong)*(uint *)(pbVar6 + 4) + 8;
        if (((*pbVar6 & 1) == 0) && (4 < *(uint *)(pbVar6 + 4))) {
          uVar3 = *(uint *)(pbVar6 + 4) - 5;
          if ((pbVar6[(ulonglong)uVar3 + 8] == 0x5f) &&
             ((bVar1 = pbVar6[(ulonglong)uVar3 + 9], bVar1 == 0x45 || (bVar1 == 0x4c)))) {
            uVar8 = 0;
            pbVar7 = pbVar6 + (ulonglong)uVar3 + 10;
            uVar3 = 0;
            do {
              bVar2 = *pbVar7;
              iVar5 = (int)(char)bVar2;
              if ((byte)(bVar2 - 0x30) < 10) {
                uVar4 = iVar5 - 0x30;
              }
              else if ((byte)(bVar2 + 0xbf) < 6) {
                uVar4 = iVar5 - 0x37;
              }
              else {
                if (5 < (byte)(bVar2 + 0x9f)) goto LAB_14002c598;
                uVar4 = iVar5 - 0x57;
              }
              if (0xf < uVar4) goto LAB_14002c598;
              uVar3 = uVar3 + 1;
              uVar8 = uVar8 << 4 | uVar4;
              pbVar7 = pbVar7 + 1;
            } while (uVar3 < 2);
            if (bVar1 == 0x45) {
              if ((param_3 != 0) && (*param_5 < param_4)) {
                *(uint *)(param_3 + (ulonglong)*param_5 * 4) = uVar8;
              }
              *param_5 = *param_5 + 1;
            }
            else if (bVar1 == 0x4c) {
              if ((param_6 != 0) && (*param_8 < param_7)) {
                *(uint *)(param_6 + (ulonglong)*param_8 * 4) = uVar8;
              }
              *param_8 = *param_8 + 1;
            }
          }
        }
LAB_14002c598:
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(param_1 + 4));
      if ((param_4 < *param_5) || (param_7 < *param_8)) {
        uVar9 = 0xc0000023;
      }
    }
  }
  return uVar9;
}



===== GpioUtilPrepareInputParametersForDsmMethod @ 14002c5e0 =====

undefined8
GpioUtilPrepareInputParametersForDsmMethod
          (undefined4 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x3c,0x786c4347);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    puVar1[2] = 0x3c;
    *puVar1 = 0x43696541;
    puVar1[1] = 0x4d53445f;
    puVar1[3] = 4;
    puVar1[4] = 0x100002;
    memcpy_s(puVar1 + 5,0x10,&GPIO_CONTROLLER_DSM_GUID,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)puVar1 + 0x12);
    if (*(ushort *)((longlong)puVar1 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined8 *)((longlong)puVar1 + uVar3 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)puVar1 + uVar3 + 0x20) = param_1;
    *(undefined8 *)((longlong)puVar1 + uVar3 + 0x24) = 0x40003;
    uVar2 = 0;
    *param_3 = puVar1;
  }
  return uVar2;
}



===== GpioUtilQueryRegistryFlags @ 14002c6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpioUtilQueryRegistryFlags
              (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong local_res8;
  longlong *plVar6;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  plVar6 = &local_res8;
  local_res8 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,param_2,0x20019,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_sSSD();
    return iVar1;
  }
  lVar4 = param_4;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_res8,param_4,param_5);
  if (iVar1 < 0) {
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_14002c7ba;
    uVar5 = 0x12;
    bVar3 = 2;
    iVar2 = iVar1;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002c7ba;
    iVar2 = *param_5;
    uVar5 = 0x13;
    bVar3 = 4;
  }
  WPP_RECORDER_SF_sSSSD
            (&WPP_RECORDER_INITIALIZED,bVar3,lVar4,uVar5,plVar6,in_stack_ffffffffffffffd0,
             *(wchar_t **)(param_3 + 8),in_stack_ffffffffffffffe0,*(wchar_t **)(param_4 + 8),
             (char)iVar2);
LAB_14002c7ba:
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== GpioClxBankEvtProcessInternalIoControl @ 14002d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxBankEvtProcessInternalIoControl(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  int *local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_18 = (int *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_GPIO_BANK_QUEUE_CONTEXT_TYPE_INFO_14001e0e0)
  ;
  lVar1 = *plVar5;
  (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x28,&local_18,&local_10);
  iVar6 = *local_18;
  if (iVar6 == 0) {
    uVar2 = GpiopEnableInterrupt
                      (lVar4,local_18[2],local_18[4],local_18[5],*(undefined8 *)(local_18 + 6),
                       *(ulonglong **)(local_18 + 8));
LAB_14002d1a9:
    iVar6 = *local_18;
    if (-1 < (int)uVar2) {
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar2,0);
      goto LAB_14002d11b;
    }
  }
  else {
    if (iVar6 == 1) {
      uVar2 = GpiopDisableInterrupt(lVar4,local_18[2],'\0');
      goto LAB_14002d1a9;
    }
    if (iVar6 == 2) {
      uVar2 = GpiopMaskInterrupt(lVar4,local_18[1],(ulonglong)(uint)local_18[2]);
      goto LAB_14002d1a9;
    }
    if (iVar6 == 3) {
      uVar2 = GpiopUnmaskInterrupt(lVar4,local_18[1],local_18[2]);
      goto LAB_14002d1a9;
    }
    iVar6 = *local_18;
    uVar2 = 0xc00000bb;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
LAB_14002d11b:
  if (iVar6 == 0) {
    PoFxIdleComponent(*(undefined8 *)(lVar4 + 0x118),*(undefined2 *)(lVar1 + 0x80),0);
  }
  return;
}



===== GpioClxBankEvtProcessIoCanceledOnQueue @ 14002d1f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpioClxBankEvtProcessIoCanceledOnQueue(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 auStackY_b8 [32];
  int *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 0;
  local_78 = (int *)0x0;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar6,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  plVar8 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_GPIO_BANK_QUEUE_CONTEXT_TYPE_INFO_14001e0e0)
  ;
  uStack_60 = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  bVar2 = false;
  bVar3 = false;
  if (local_68._4_4_ == 0) {
    bVar2 = true;
    bVar3 = true;
  }
  else if ((local_68._4_4_ == 0xf) && ((int)uStack_50 == 0x480000)) {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x28,&local_78);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(lVar7 + 0x298),2,8,0x2a,
                           &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                           "GpioClxBankEvtProcessIoCanceledOnQueue",(char)iVar4);
      }
    }
    else if (*local_78 == 0) {
      bVar2 = true;
    }
  }
  lVar1 = *plVar8;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000120);
  if (bVar2) {
    PoFxIdleComponent(*(undefined8 *)(lVar7 + 0x118),*(undefined2 *)(lVar1 + 0x80),0);
  }
  if (bVar3) {
    iVar5 = 0;
    LOCK();
    iVar4 = *(int *)(lVar7 + 300);
    if (iVar4 == 0) {
      *(int *)(lVar7 + 300) = 0;
    }
    else {
      iVar5 = iVar4;
    }
    UNLOCK();
    if ((char)iVar5 == '\0') {
      (**(code **)(WdfFunctions_01015 + 0xdb8))
                (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x2c8),0,0xaf3);
    }
  }
  return;
}



===== GpioClxBankEvtProcessIoDefault @ 14002d450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpioClxBankEvtProcessIoDefault(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_GPIO_BANK_QUEUE_CONTEXT_TYPE_INFO_14001e0e0)
  ;
  lVar1 = *plVar5;
  local_18 = 0;
  uStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if ((lVar6 == 0) ||
     (plVar5 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,lVar6,
                          PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160),
     plVar5 == (longlong *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(lVar4 + 0x298),2,7,0x29,
                         &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                         "GpioClxBankEvtProcessIoDefault",(char)param_2);
    }
    iVar2 = -0x3fffff45;
  }
  else if ((*(uint *)((longlong)plVar5 + 100) & 8) == 0) {
    iVar2 = GpiopConnectGpioPins(lVar4,plVar5,*(int *)((longlong)plVar5 + 0x1c),plVar5 + 10);
  }
  else {
    iVar2 = GpiopConnectFunctionConfigPinsReserve(lVar4,plVar5,plVar5 + 10);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  PoFxIdleComponent(*(undefined8 *)(lVar4 + 0x118),*(undefined2 *)(lVar1 + 0x80),0);
  (**(code **)(WdfFunctions_01015 + 0xdb8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x2c8),0,0x959)
  ;
  return;
}



===== GpioClxEvtProcessInternalDeviceIoControl @ 14002d680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtProcessInternalDeviceIoControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong local_28;
  int *local_20;
  undefined8 local_18 [2];
  
  local_18[0] = 0;
  local_20 = (int *)0x0;
  lVar6 = 0;
  local_28 = 0;
  bVar1 = false;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_DEVICE_EXTENSION_TYPE_INFO_14001e190);
  if (param_5 == 0x480000) {
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,0x28,&local_20,local_18);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(lVar5 + 0x298),2,8,0x22,
                          &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,(char)iVar3);
      }
    }
    else {
      if (*local_20 == 0) {
        iVar3 = GpiopQueryBankIdFromGsivOrConnectionId
                          (lVar5,1,(ulonglong)(uint)local_20[2],&local_28,(byte *)0x0,
                           (undefined1 *)0x0);
        lVar6 = local_28;
        if (iVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(lVar5 + 0x298),2,8,0x24,
                               &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                               "GpioClxEvtProcessInternalDeviceIoControl",(char)iVar3);
          }
          lVar6 = local_28;
          goto LAB_14002d902;
        }
        PoFxActivateComponent(*(undefined8 *)(lVar5 + 0x118),*(undefined2 *)(local_28 + 0x80),0);
        bVar2 = true;
      }
      else {
        lVar6 = GpiopGetBankEntryFromVirq(lVar5,local_20[2]);
        bVar2 = false;
        if (lVar6 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(lVar5 + 0x298),2,8,0x23,
                               &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                               "GpioClxEvtProcessInternalDeviceIoControl",(char)local_20[2]);
          }
          iVar3 = -0x3ffffff3;
          goto LAB_14002d902;
        }
      }
      bVar1 = bVar2;
      uVar4 = param_2;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(lVar6 + 0x58));
      if (-1 < iVar3) {
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDD(*(undefined8 *)(lVar5 + 0x298),uVar4,5,0x25,
                            &WPP_f3487bd4cec038115b0e20ddd6fea826_Traceguids,
                            "GpioClxEvtProcessInternalDeviceIoControl",
                            (char)*(undefined2 *)(lVar6 + 0x80),(char)iVar3);
      }
    }
  }
  else {
    iVar3 = -0x3ffffff0;
  }
LAB_14002d902:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  if (bVar1) {
    PoFxIdleComponent(*(undefined8 *)(lVar5 + 0x118),*(undefined2 *)(lVar6 + 0x80),0);
  }
  return;
}



===== GpioClxEvtProcessWriteRequest @ 14002d970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpioClxEvtProcessWriteRequest(undefined8 param_1,undefined8 param_2)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  return;
}



===== GpiopConnectFunctionConfigPinsCommit @ 14002d9a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GpiopConnectFunctionConfigPinsCommit(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  
  puVar2 = *(undefined2 **)(param_2 + 0x20);
  uVar1 = *(uint *)(param_2 + 0x28);
  lVar3 = GpiopGetBankEntry(param_1,*(ushort *)(param_2 + 0x18));
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x30),0);
  *(void **)(lVar3 + 0x38) = SystemReserved1[0xf];
  uVar4 = GpiopConnectFunctionConfigPinsLocked(param_1,lVar3,param_2,1);
  *(undefined8 *)(lVar3 + 0x38) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x30));
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,0xc,0x4f,
                         &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopConnectFunctionConfigPinsCommit",(char)uVar4);
    }
  }
  else {
    ppuVar5 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar5 = *(undefined ***)(param_1 + 0x298);
      WPP_RECORDER_SF_sq(ppuVar5,4,0xc,0x4e,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopConnectFunctionConfigPinsCommit",(char)param_1);
    }
    GpioUtilTracePrintPinNumbersEx(ppuVar5,lVar3,puVar2,uVar1);
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0x786c4347);
      *(undefined8 *)(param_2 + 0x58) = 0;
    }
  }
  return uVar4 & 0xffffffff;
}



===== GpiopQueryBankIdFromGsivOrConnectionId @ 14002db1c =====

int GpiopQueryBankIdFromGsivOrConnectionId
              (longlong param_1,undefined1 param_2,undefined8 param_3,longlong *param_4,
              byte *param_5,undefined1 *param_6)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  longlong local_res8;
  longlong *plVar11;
  undefined1 uVar12;
  
  plVar11 = &local_res8;
  plVar5 = (longlong *)(param_1 + 0x110);
  local_res8 = 0;
  iVar3 = GpiopQueryResourceHubBiosDescriptor
                    (*(undefined8 *)(param_1 + 0x2c8),plVar5,
                     CONCAT71((int7)((ulonglong)param_3 >> 8),param_2),param_3,plVar11);
  lVar2 = local_res8;
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_siD(*(undefined8 *)(param_1 + 0x298),plVar5,8,0xa8,plVar11,
                          "GpiopQueryBankIdFromGsivOrConnectionId",(char)param_3,(char)iVar3);
    }
    goto LAB_14002ddb5;
  }
  uVar8 = *(uint *)(local_res8 + 4);
  if (*(char *)(local_res8 + 8) == -0x73) {
    if (uVar8 < 0x12) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0xa9;
        uVar12 = 0x12;
        uVar7 = 0xc;
LAB_14002dbea:
        WPP_RECORDER_SF_sqdd
                  (*(undefined8 *)(param_1 + 0x298),plVar5,uVar7,uVar10,plVar11,
                   "GpiopQueryBankIdFromGsivOrConnectionId",(char)param_1,(char)uVar8,uVar12);
      }
    }
    else {
      uVar6 = (ulonglong)*(ushort *)(local_res8 + 0x11);
      if ((short)(*(ushort *)(local_res8 + 0x14) - uVar6 >> 1) != 0) {
        if (param_5 != (byte *)0x0) {
          *param_5 = 0;
        }
        if (param_6 != (undefined1 *)0x0) {
          *param_6 = 1;
        }
LAB_14002dd35:
        uVar1 = *(ushort *)(uVar6 + 8 + local_res8);
        uVar12 = (undefined1)uVar1;
        uVar6 = (ulonglong)uVar1 / (ulonglong)*(ushort *)(param_1 + 0x2d6);
        uVar9 = (undefined1)uVar6;
        lVar4 = GpiopGetBankEntry(param_1,(ushort)uVar6);
        if (lVar4 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDD(*(undefined8 *)(param_1 + 0x298),uVar6,8,0xad,
                                &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                                "GpiopQueryBankIdFromGsivOrConnectionId",uVar12,uVar9);
          }
          iVar3 = -0x3ffffff3;
        }
        else {
          *param_4 = lVar4;
        }
        goto LAB_14002ddb5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0xaa;
        uVar8 = 0xc;
LAB_14002dc44:
        WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),2,uVar8,uVar10,
                           &WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                           "GpiopQueryBankIdFromGsivOrConnectionId",(char)param_1);
      }
    }
  }
  else if (uVar8 < 0x17) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0xab;
      uVar12 = 0x17;
      uVar7 = 8;
      goto LAB_14002dbea;
    }
  }
  else {
    uVar6 = (ulonglong)*(ushort *)(local_res8 + 0x16);
    if ((short)((ulonglong)*(ushort *)(local_res8 + 0x19) -
                (ulonglong)*(ushort *)(local_res8 + 0x16) >> 1) != 0) {
      if (param_5 != (byte *)0x0) {
        if (*(char *)(local_res8 + 0xc) == '\x01') {
          *param_5 = *(byte *)(local_res8 + 0xf) & 3;
        }
        else {
          *param_5 = 0;
        }
      }
      if (param_6 != (undefined1 *)0x0) {
        *param_6 = 0;
      }
      goto LAB_14002dd35;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0xac;
      uVar8 = 8;
      goto LAB_14002dc44;
    }
  }
  iVar3 = -0x3fffffff;
LAB_14002ddb5:
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x786c4347);
  }
  return iVar3;
}



===== GpiopQueryResourceHubBiosDescriptor @ 14002ddf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopQueryResourceHubBiosDescriptor
              (undefined8 param_1,longlong *param_2,undefined8 param_3,undefined8 param_4,
              longlong *param_5)

{
  int iVar1;
  longlong lVar2;
  
  if ((*param_2 == 0) && (iVar1 = GpiopOpenResourceHubTarget(param_1,param_2), iVar1 < 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(GpioLogHandle,2,1,0xb0,&WPP_c1662ee5f1eb325f6143f63e3c72e3f2_Traceguids,
                         "GpiopQueryResourceHubBiosDescriptor",(char)iVar1);
    }
  }
  else {
    iVar1 = 0x5f;
    while (lVar2 = ExAllocatePool2(0x40,iVar1,0x786c4347), lVar2 != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,*param_2,0,0x2ac000);
      if (iVar1 != -0x3fffffdd) {
        if (iVar1 < 0) {
          ExFreePoolWithTag(lVar2,0x786c4347);
          return iVar1;
        }
        *param_5 = lVar2;
        return iVar1;
      }
      iVar1 = *(int *)(lVar2 + 4) + 8;
      ExFreePoolWithTag(lVar2,0x786c4347);
    }
    iVar1 = -0x3fffff66;
  }
  return iVar1;
}



===== GpiopForwardInterruptRequestToQueue @ 14002dfe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GpiopForwardInterruptRequestToQueue(longlong param_1,undefined8 param_2)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = 1;
  local_18 = 0x28;
  local_20 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x5e0))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x108),0,0x480000,&local_28,0,0,0);
  return;
}



===== GpiopProcessControllerSpecificFunctionIoctl @ 14002e048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GpiopProcessControllerSpecificFunctionIoctl
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  char cVar1;
  longlong lVar2;
  short *psVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  undefined2 uVar7;
  ushort uVar8;
  undefined8 local_res10;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined2 uStack_7c;
  undefined2 uStack_7a;
  undefined6 uStack_78;
  undefined2 uStack_72;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_res10 = 0;
  local_98 = 0;
  local_88 = 0;
  local_90 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_3);
  if ((lVar5 == 0) ||
     (lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar5,
                         PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160),
     lVar5 = WdfFunctions_01015, lVar2 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),2,7,10,
                         &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,
                         "GpiopProcessControllerSpecificFunctionIoctl",(char)param_3);
    }
    return -0x3fffffff;
  }
  *param_4 = 0;
  iVar6 = (**(code **)(lVar5 + 0x868))(WdfDriverGlobals,param_3,0,&local_res10,&local_98);
  if (((iVar6 + 0x80000000U & 0x80000000) == 0) && (iVar6 != -0x3fffffdd)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    uVar7 = 0xb;
LAB_14002e13b:
    WPP_RECORDER_SF_sD(*(undefined8 *)(param_1 + 0x298),2,7,uVar7,
                       &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,
                       "GpiopProcessControllerSpecificFunctionIoctl",(char)iVar6);
    return iVar6;
  }
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_3,0,&local_88,&local_90);
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    uVar7 = 0xc;
    goto LAB_14002e13b;
  }
  iVar6 = *(ushort *)(param_1 + 0x2d8) + 8;
  psVar3 = (short *)ExAllocatePool2(0x100,iVar6,0x786c4347);
  if (psVar3 == (short *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,7,0xd,
                        &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,
                        "GpiopProcessControllerSpecificFunctionIoctl");
    }
    return -0x3fffff66;
  }
  psVar3[1] = (short)iVar6;
  iVar6 = -0x3ffffffe;
  local_80 = 0;
  uStack_7c = 0;
  uStack_7a = 0;
  uStack_78 = 0;
  uStack_72 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (*(code **)(param_1 + 400) != (code *)0x0) {
    uStack_7a = 0;
    uStack_78 = 0;
    uStack_7c = 0x30;
    local_70 = local_res10;
    uStack_68 = local_98;
    local_60 = local_90;
    uStack_72 = 0;
    uStack_58 = (ulonglong)*(ushort *)(param_1 + 0x2d8);
    local_80 = 2;
    iVar6 = (**(code **)(param_1 + 400))(param_1 + 0x400,&local_80,psVar3);
  }
  if (iVar6 < 0) {
    if ((iVar6 == -0x3ffffffe) || (iVar6 == -0x3fffff45)) {
      if (*(int *)(lVar2 + 0x28) == 0) {
        uVar8 = 0;
        if (*(short *)(param_1 + 0x2d8) != 0) {
          do {
            uVar4 = (ulonglong)uVar8;
            uVar8 = uVar8 + 1;
            *(undefined1 *)(uVar4 + 8 + (longlong)psVar3) = 1;
          } while (uVar8 < *(ushort *)(param_1 + 0x2d8));
        }
      }
      else {
        *(undefined1 *)((ulonglong)*(ushort *)(lVar2 + 0x18) + 8 + (longlong)psVar3) = 1;
      }
      goto LAB_14002e363;
    }
  }
  else {
    cVar1 = GpiopValidateControllerFunctionBankMappings(param_1,psVar3);
    if (cVar1 == '\0') {
      iVar6 = -0x3fffffff;
    }
    if (-1 < iVar6) {
LAB_14002e363:
      uVar8 = 0;
      if (*(short *)(param_1 + 0x2d8) != 0) {
        do {
          if (*(char *)((ulonglong)uVar8 + 8 + (longlong)psVar3) != '\0') {
            PoFxActivateComponent(*(undefined8 *)(param_1 + 0x118),uVar8,0);
            lVar5 = GpiopGetBankEntry(param_1,uVar8);
            (**(code **)(WdfFunctions_01015 + 0x9c8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x30));
            *(void **)(lVar5 + 0x38) = SystemReserved1[0xf];
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(param_1 + 0x2d8));
      }
      local_30 = 0;
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      if (*(code **)(param_1 + 0x200) == (code *)0x0) {
        iVar6 = -0x3fffff45;
      }
      else {
        local_50 = local_res10;
        uStack_48 = local_98;
        local_40 = local_88;
        uStack_38 = local_90;
        local_30 = 0;
        iVar6 = (**(code **)(param_1 + 0x200))(param_1 + 0x400,&local_50);
        *param_4 = (undefined4)local_30;
      }
      uVar8 = 0;
      if (*(short *)(param_1 + 0x2d8) != 0) {
        do {
          if (*(char *)((ulonglong)uVar8 + 8 + (longlong)psVar3) != '\0') {
            lVar5 = GpiopGetBankEntry(param_1,uVar8);
            *(undefined8 *)(lVar5 + 0x38) = 0;
            (**(code **)(WdfFunctions_01015 + 0x9d0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x30));
            PoFxIdleComponent(*(undefined8 *)(param_1 + 0x118),uVar8,0);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(param_1 + 0x2d8));
      }
      goto LAB_14002e4b3;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(param_1 + 0x298),2,7,0xe,
                      &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,
                      "GpiopProcessControllerSpecificFunctionIoctl");
  }
LAB_14002e4b3:
  ExFreePoolWithTag(psVar3,0x786c4347);
  return iVar6;
}



===== GpiopProcessFunctionConfigPinsCommitRequest @ 14002e538 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GpiopProcessFunctionConfigPinsCommitRequest
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_3,&local_48);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_3);
  if ((lVar1 != 0) &&
     (lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar1,
                         PTR__WDF_GPIO_FILE_OBJECT_CONTEXT_TYPE_INFO_14001e160), lVar1 != 0)) {
    uVar2 = GpiopConnectFunctionConfigPinsCommit(param_1,lVar1);
    *param_4 = 0;
    return uVar2;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x298),2,0xc,0xf,
                       &WPP_ad059711dd1d3ada8c6b7a8d7f4c7e2f_Traceguids,
                       "GpiopProcessFunctionConfigPinsCommitRequest",(char)param_3);
  }
  return 0xc00000bb;
}



===== GpioUtilTracePrintPinNumbers @ 14002e65c =====

void GpioUtilTracePrintPinNumbers(undefined8 param_1,undefined2 *param_2,uint param_3)

{
  GpioUtilTracePrintPinNumbersEx(param_1,param_1,param_2,param_3);
  return;
}



===== GpioUtilTracePrintPinNumbersEx @ 14002e67c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GpioUtilTracePrintPinNumbersEx
               (undefined8 param_1,longlong param_2,undefined2 *param_3,uint param_4)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined1 auStackY_118 [32];
  char *local_d8;
  ulonglong local_d0;
  char local_c8 [127];
  undefined1 local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar3 = 0;
  if ((param_4 == 0) || (param_3 == (undefined2 *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_D(*(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x298),4,7,0x14,
                      &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,(char)param_4);
    return;
  }
  if (param_4 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_DD(*(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x298),4,7,0x15,
                       &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,1,
                       (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                       (char)*(undefined2 *)(param_2 + 0x80) + (char)*param_3);
    return;
  }
  uVar7 = param_4 & 0xffff;
  local_d8 = local_c8;
  local_d0 = 0x7f;
  uVar4 = 0;
  local_49 = 0;
  if (uVar7 != 0) {
    puVar6 = param_3;
    do {
      pcVar2 = "%#x, ";
      if (param_4 - 1 <= uVar4) {
        pcVar2 = "%#x";
      }
      iVar1 = RtlStringCbPrintfExA
                        (local_d8,local_d0,(size_t *)&local_d8,&local_d0,0,pcVar2,
                         (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                         (char)*(undefined2 *)(param_2 + 0x80) + (char)*puVar6);
      if (iVar1 < 0) {
        goto LAB_14002e7e6;
      }
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar4 < uVar7);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return;
  }
  WPP_RECORDER_SF_Ds(*(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x298));
  return;
LAB_14002e7e6:
  if (uVar3 < param_4 - 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x17;
      goto LAB_14002e828;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar5 = 0x18;
LAB_14002e828:
    WPP_RECORDER_SF_D(*(undefined8 *)(*(longlong *)(param_2 + 0x88) + 0x298),4,7,uVar5,
                      &WPP_b8a194f19f663f5cfbb841313167cc31_Traceguids,
                      (char)*(undefined2 *)(*(longlong *)(param_2 + 0x88) + 0x2d6) *
                      (char)*(undefined2 *)(param_2 + 0x80) + (char)*param_3);
  }
  uVar3 = uVar3 + 1;
  param_3 = param_3 + 1;
  if (uVar7 <= uVar3) {
    return;
  }
  goto LAB_14002e7e6;
}



===== __security_init_cookie @ 14002f008 =====

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



===== DriverEntry @ 14002f03c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 auStackY_e8 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50 [5];
  
  local_50[3] = __security_cookie ^ (ulonglong)auStackY_e8;
  local_80 = 0;
  uStack_78 = 0;
  local_50[2] = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  wil_InitializeFeatureStaging();
  McGenEventRegister_EtwRegister();
  _WPP_MAIN_CB = 0;
  DAT_14001e768 = &WPP_ThisDir_CTLGUID_GpioTraceGuid;
  DAT_14001e770 = 0;
  _DAT_14001e780 = 0;
  _DAT_14001e788 = 1;
  _DAT_14001e7a0 = 0;
  _DAT_14001e7a8 = 0;
  WppLoadTracingSupport();
  _DAT_14001e780 = 0;
  WppInitKm(param_1,param_2);
  uStack_78 = 0x200000002;
  local_80 = CONCAT35(local_80._5_3_,0x10);
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_80);
  local_70 = 0x38;
  local_50[0] = local_50[0] & 0xffffffffffffff00;
  uStack_58 = CONCAT44(0x10,(undefined4)uStack_58);
  local_60 = 0;
  uStack_58 = uStack_58 & 0xffffffffffffff00;
  local_50[2] = 0x200000002;
  uStack_68 = 0xc800002000;
  RtlStringCbPrintfA((char *)local_50,0x10,"GPIO_Default",param_4);
  uVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_70);
  uVar4 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar1 = GpiopInitialize(0,param_1,0,param_2);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f1db;
      uVar5 = 10;
    }
    else {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar3 = 1;
        uVar1 = GpiopInitialize(1,param_1,0,param_2);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar4;
          }
          uVar5 = 0xc;
        }
        else {
          uVar2 = GpiopClassLibraryCreate(uVar3,param_2);
          uVar4 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            return uVar4;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar4;
          }
          uVar5 = 0xd;
        }
        WPP_RECORDER_SF_D(GpioLogHandle,2,1,uVar5,&WPP_022c81e08a523bbb1bab82949e8d2f03_Traceguids,
                          (char)uVar4);
        return uVar4;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f1db;
      uVar5 = 0xb;
    }
    WPP_RECORDER_SF_D(GpioLogHandle,2,1,uVar5,&WPP_022c81e08a523bbb1bab82949e8d2f03_Traceguids,
                      (char)uVar4);
  }
LAB_14002f1db:
  GpiopUninitialize();
  if (GpioLogHandle != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    GpioLogHandle = 0;
  }
  WppCleanupKm(param_1);
  McGenEventUnregister_EtwUnregister();
  return uVar4;
}



===== wil_InitializeFeatureStaging @ 14002f33c =====

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
    for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_14002f3c3;
    }
LAB_14002f3fd:
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
LAB_14002f3c3:
  if (plVar3 == (longlong *)0x0) goto LAB_14002f3fd;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_14002f3fd;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_14001d1c7 < plVar3) goto LAB_14002f3fd;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14002f3c3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002f450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_a <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14001d1c7 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14002f53a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14002f53a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14002f53a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14001d1c7 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


