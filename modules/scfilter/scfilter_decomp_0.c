
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



===== _vsnwprintf @ 140001020 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 140001040 =====

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



===== _vsnprintf @ 140001138 =====

int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnprintf_l @ 140001158 =====

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
LAB_1400011e9:
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    if (_MaxCount == 0) {
LAB_14000119f:
      local_38._cnt = (int)_MaxCount;
    }
    else {
      if (_DstBuf == (char *)0x0) goto LAB_1400011e9;
      local_38._cnt = 0x7fffffff;
      if (_MaxCount < 0x80000000) goto LAB_14000119f;
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



===== _flsbuf @ 140001218 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 140001228 =====

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
LAB_140001aec:
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
LAB_1400019c0:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_14000186e:
          iVar6 = local_4a8;
LAB_140001876:
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
LAB_140001911:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_140001994;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_140001994:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_140001880;
                  }
                  local_494 = 0;
                  goto LAB_1400019c0;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_140001994;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_140001911;
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
              if (uVar11 == 0x74) goto LAB_140001911;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_140001911;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_1400013b9:
              uVar16 = uVar16 | 0x40;
LAB_1400013bc:
              uVar19 = 10;
              goto LAB_1400013c7;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_1400014f0:
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
LAB_140001479:
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
              if (uVar11 == 0x58) goto LAB_1400015ca;
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
                  if (puVar3[1] < uVar2) goto LAB_140001aec;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140001aec;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_1400014f0;
                if (uVar11 == 100) goto LAB_1400013b9;
              }
            }
LAB_140001706:
            if (local_478 != 0) goto LAB_140001876;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_140001754;
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
LAB_140001754:
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
                  goto LAB_14000184a;
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
LAB_14000184a:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_14000186e;
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
LAB_1400015ca:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_140001479;
                  if (wVar18 == L'u') goto LAB_1400013bc;
                  if (wVar18 != L'x') goto LAB_140001706;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_1400013c7:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_140001641;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_140001641:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_140001641;
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
              goto LAB_140001706;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_140001aec;
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
LAB_140001880:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 140001b34 =====

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



===== write_multi_char @ 140001b88 =====

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



===== write_string @ 140001be0 =====

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



===== _guard_check_icall @ 140001c60 =====

void _guard_check_icall(void)

{
  return;
}



===== _output_l @ 140001c6c =====

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
LAB_140002499:
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
joined_r0x000140001d0e:
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
LAB_140002366:
    local_278 = 0;
    write_char(bVar2,local_258,&local_284);
LAB_14000237d:
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
      goto LAB_14000238a;
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
      goto LAB_14000238a;
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
      goto LAB_14000238a;
    }
    if (local_274 == 4) {
      uVar21 = uVar10;
      uVar15 = uVar10;
      uVar10 = uVar11;
      goto LAB_14000238a;
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
      goto LAB_14000238a;
    }
    if (local_274 == 6) {
      if (bVar2 == 0x49) {
LAB_1400022d7:
        uVar23 = uVar22 | 0x8000;
        if (bVar2 == 0x49) {
          if (*pbVar20 == 0x36) {
            if (_Format[2] != 0x34) goto LAB_140002347;
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar23;
            uVar10 = uVar11;
          }
          else {
            if ((*pbVar20 != 0x33) || (_Format[2] != 0x32)) {
LAB_140002347:
              if ((byte)(*pbVar20 + 0xa8) < 0x21) {
                uVar22 = uVar23;
                uVar10 = uVar11;
                if ((0x120821001U >> ((ulonglong)(byte)(*pbVar20 + 0xa8) & 0x3f) & 1) != 0)
                goto LAB_14000238a;
              }
              local_274 = 0;
              uVar22 = uVar23;
              goto LAB_140002366;
            }
            pbVar20 = (byte *)(_Format + 3);
            uVar22 = uVar22 & 0xffff7fff;
            uVar10 = uVar11;
          }
        }
        else {
          uVar22 = uVar23;
          uVar10 = uVar11;
          if (bVar2 != 0x6a) goto LAB_140002347;
        }
      }
      else if (bVar2 == 0x68) {
        uVar22 = uVar22 | 0x20;
        uVar10 = uVar11;
      }
      else {
        if (bVar2 == 0x6a) goto LAB_1400022d7;
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
          if (bVar2 == 0x74) goto LAB_1400022d7;
          if (bVar2 == 0x77) {
            uVar22 = uVar22 | 0x800;
            uVar10 = uVar11;
          }
          else {
            uVar10 = uVar11;
            if (bVar2 == 0x7a) goto LAB_1400022d7;
          }
        }
      }
      goto LAB_14000238a;
    }
    uVar10 = uVar11;
    if (local_274 != 7) goto LAB_14000238a;
    if (iVar14 < 0x6a) {
      if (iVar14 == 0x69) {
LAB_140001dea:
        uVar22 = uVar22 | 0x40;
LAB_140001dee:
        uVar19 = 10;
LAB_140001df9:
        local_268 = (wchar_t *)((longlong)_ArgList + 8);
        if ((uVar22 >> 0xf == 0) && ((uVar22 >> 0xc & 1) == 0)) {
          if ((uVar22 & 0x20) == 0) {
            if ((uVar22 & 0x40) != 0) {
              uVar9 = (ulonglong)*(int *)_ArgList;
              goto LAB_14000204b;
            }
            uVar9 = (ulonglong)*(uint *)_ArgList;
          }
          else if ((uVar22 & 0x40) == 0) {
            uVar9 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
          }
          else {
            uVar9 = (ulonglong)*(wchar_t *)_ArgList;
LAB_14000204b:
            if ((longlong)uVar9 < 0) {
              uVar9 = -uVar9;
              uVar22 = uVar22 | 0x100;
            }
          }
        }
        else {
          uVar9 = *(ulonglong *)_ArgList;
          if ((uVar22 & 0x40) != 0) goto LAB_14000204b;
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
LAB_140001f06:
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
LAB_140001ead:
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
        if (iVar14 == 0x58) goto LAB_140001fe1;
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
            if (puVar4[1] < uVar3) goto LAB_140002499;
            uVar9 = (ulonglong)(uint)uVar3;
            if ((uVar22 >> 0xb & 1) == 0) {
              local_278 = 0;
            }
            else {
              if (((~(uint)uVar3 & 1) == 0) || ((~(uint)pwVar16 & 1) == 0)) goto LAB_140002499;
              local_278 = 1;
              uVar9 = (ulonglong)(uVar3 >> 1);
            }
          }
          local_27c = (int)uVar9;
        }
        else {
          if (iVar14 == 99) goto LAB_140001f06;
          if (iVar14 == 100) goto LAB_140001dea;
        }
      }
LAB_140002114:
      if (local_260 == 0) {
        if ((uVar22 & 0x40) != 0) {
          if ((uVar22 >> 8 & 1) == 0) {
            if ((uVar22 & 1) == 0) {
              if ((uVar22 & 2) == 0) goto LAB_14000215d;
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
LAB_14000215d:
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
          goto LAB_14000237d;
        }
        iVar17 = local_284;
        uVar11 = local_288;
      }
      goto LAB_140002385;
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
LAB_140001fe1:
          local_25c = 7;
        }
        else {
          if (iVar14 == 0x73) goto LAB_140001ead;
          if (iVar14 == 0x75) goto LAB_140001dee;
          if (iVar14 != 0x78) goto LAB_140002114;
          local_25c = 0x27;
        }
        if ((char)uVar22 < '\0') {
          local_27f = (char)local_25c + 'Q';
          local_280 = 0x30;
          uVar11 = 2;
        }
        uVar19 = 0x10;
      }
      goto LAB_140001df9;
    }
    local_268 = (wchar_t *)((longlong)_ArgList + 8);
    piVar5 = *(int **)_ArgList;
    iVar14 = _get_printf_count_output();
    if (iVar14 == 0) goto LAB_140002499;
    if ((uVar22 & 0x20) == 0) {
      *piVar5 = iVar17;
    }
    else {
      *(short *)piVar5 = (short)iVar17;
    }
    local_260 = 1;
  }
LAB_140002385:
  uVar10 = uVar11;
LAB_14000238a:
  bVar2 = *pbVar20;
  _Format = (char *)pbVar20;
  _ArgList = (va_list)local_268;
  uVar11 = uVar10;
  goto joined_r0x000140001d0e;
}



===== write_char @ 1400024e4 =====

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



===== write_multi_char @ 140002534 =====

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



===== write_string @ 14000258c =====

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



===== _get_printf_count_output @ 140002600 =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_14000a160 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 140002620 =====

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



===== mbtowc @ 14000266c =====

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



===== __GSHandlerCheck @ 1400026c0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400026e4 =====

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



===== _wctomb_s_l @ 140002758 =====

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



===== wctomb_s @ 140002808 =====

errno_t __cdecl wctomb_s(int *_SizeConverted,char *_MbCh,rsize_t _SizeInBytes,wchar_t _WCh)

{
  errno_t eVar1;
  
  eVar1 = _wctomb_s_l(_SizeConverted,_MbCh,_SizeInBytes,_WCh,(_locale_t)0x0);
  return eVar1;
}



===== _flswbuf @ 140002824 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 140002840 =====

/* WARNING: Removing unreachable block (ram,0x0001400028aa) */
/* WARNING: Removing unreachable block (ram,0x000140002859) */
/* WARNING: Removing unreachable block (ram,0x00014000284a) */

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



===== RtlAnsiCharToUnicodeChar @ 140002906 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002906. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== RtlUnicodeToMultiByteN @ 140002918 =====

void RtlUnicodeToMultiByteN(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnicodeToMultiByteN();
  return;
}



===== RtlStringCbPrintfA @ 14000292c =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  size_t _Count;
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



===== StringCbCatA @ 14000299c =====

HRESULT __stdcall StringCbCatA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar6 = 0x100;
  pcVar2 = &`WppTraceIndent'::__l2::szIndentPrefix;
  do {
    if (*pcVar2 == '\0') break;
    pcVar2 = pcVar2 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar5 = -(ulonglong)(lVar6 != 0) & 0x100U - lVar6;
  uVar1 = ~-(uint)(lVar6 != 0) & 0x80070057;
  if (lVar6 != 0) {
    pcVar2 = &`WppTraceIndent'::__l2::szIndentPrefix + uVar5;
    lVar6 = 0x100 - uVar5;
    if (lVar6 != 0) {
      lVar3 = 0x7ffffffe;
      lVar7 = (longlong)pszSrc - (longlong)pcVar2;
      do {
        if ((lVar3 == 0) || (pcVar2[lVar7] == '\0')) break;
        *pcVar2 = pcVar2[lVar7];
        lVar3 = lVar3 + -1;
        pcVar2 = pcVar2 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    pcVar4 = pcVar2 + -1;
    if (lVar6 != 0) {
      pcVar4 = pcVar2;
    }
    *pcVar4 = '\0';
    uVar1 = ~-(uint)(lVar6 != 0) & 0x8007007a;
  }
  return uVar1;
}



===== WPP_SF_s @ 140002a38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (WPP_pszIndent == (char *)0x0) {
    lVar2 = 5;
    pcVar3 = "NULL";
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (WPP_pszIndent[lVar1] != '\0');
    lVar2 = lVar2 + 2;
    pcVar3 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,pcVar3,lVar2,0);
  return;
}



===== WPP_SF_sl @ 140002a9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sl(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (WPP_pszIndent == (char *)0x0) {
    lVar2 = 5;
    pcVar3 = "NULL";
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (WPP_pszIndent[lVar1] != '\0');
    lVar2 = lVar2 + 2;
    pcVar3 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,pcVar3,lVar2,&param_5,4,0);
  return;
}



===== WPP_SF_sP @ 140002b14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (WPP_pszIndent == (char *)0x0) {
    lVar2 = 5;
    pcVar3 = "NULL";
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (WPP_pszIndent[lVar1] != '\0');
    lVar2 = lVar2 + 2;
    pcVar3 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_2,pcVar3,lVar2,
             &param_5,8,0);
  return;
}



===== WPP_SF_sqq @ 140002b94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (WPP_pszIndent == (char *)0x0) {
    lVar2 = 5;
    pcVar3 = "NULL";
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (WPP_pszIndent[lVar1] != '\0');
    lVar2 = lVar2 + 2;
    pcVar3 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,pcVar3,lVar2,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_sqs @ 140002c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  
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
  pcVar4 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  lVar1 = -1;
  if (WPP_pszIndent == (char *)0x0) {
    lVar3 = 5;
    pcVar5 = "NULL";
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (WPP_pszIndent[lVar1] != '\0');
    lVar3 = lVar3 + 2;
    pcVar5 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_2,pcVar5,lVar3,
             &param_5,8,pcVar4,lVar2,0);
  return;
}



===== WPP_SF_ss @ 140002ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ss(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *in_stack_00000028;
  
  if (in_stack_00000028 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000028[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  lVar2 = -1;
  if (WPP_pszIndent == (char *)0x0) {
    lVar1 = 5;
    pcVar4 = "NULL";
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (WPP_pszIndent[lVar2] != '\0');
    lVar1 = lVar1 + 2;
    pcVar4 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,0x26,pcVar4,lVar1,
             in_stack_00000028,lVar3,0);
  return;
}



===== WdfScFilter_EvtDeviceFileCreate @ 140002d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfScFilter_EvtDeviceFileCreate
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar2 = 0;
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  uVar4 = WdfDriverGlobals;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018
                     );
  WppTraceIndent(uVar4,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)param_1,param_3);
  }
  (**(code **)(WdfFunctions_01015 + 0x820))
            (WdfDriverGlobals,param_2,WdfScFilter_EvtFileCreateCompletionRoutine);
  (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
  uVar5 = 0;
  uVar4 = WdfDriverGlobals;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,*puVar3);
  if (cVar1 == '\0') {
    uVar4 = WdfDriverGlobals;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
    WppTraceIndent(uVar4,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar5,(char)uVar2);
    }
    uVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  }
  WppTraceIndent(uVar4,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar5,(char)uVar2);
  }
  return;
}



===== WdfScFilter_EvtFileClose @ 140002fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfScFilter_EvtFileClose
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined2 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  char *pcVar7;
  undefined8 *puVar8;
  char *pcVar9;
  
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  puVar3 = WdfDriverGlobals;
  pcVar9 = PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
  WppTraceIndent(puVar3,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar9 = &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids;
    WPP_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)uVar1,(char)param_1);
  }
  puVar3 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x58));
  puVar6 = *(undefined8 **)(lVar2 + 0x48);
  if (puVar6 != (undefined8 *)0x0) {
    puVar8 = (undefined8 *)0x0;
    do {
      puVar5 = puVar6;
      if (param_1 == puVar5[2]) {
        WppTraceIndent(puVar3,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar7 = "NULL";
          if (*(char *)(puVar5 + 4) != '\0') {
            pcVar7 = (char *)(puVar5 + 4);
          }
          WPP_SF_sqs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,pcVar9,param_4,(char)puVar5[2],
                     pcVar7);
        }
        puVar6 = puVar5;
        if (puVar8 == (undefined8 *)0x0) {
          *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(*(longlong *)(lVar2 + 0x48) + 0x88);
        }
        else {
          puVar8[0x11] = puVar5[0x11];
        }
        break;
      }
      WppTraceIndent(puVar3,(longlong *)0x2);
      puVar3 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        pcVar9 = "NULL";
        if (*(char *)(puVar5 + 4) != '\0') {
          pcVar9 = (char *)(puVar5 + 4);
        }
        WPP_SF_sqs(puVar3,0x1f,pcVar9,param_4,(char)puVar5[2],pcVar9);
      }
      puVar6 = (undefined8 *)puVar5[0x11];
      puVar8 = puVar5;
    } while (puVar6 != (undefined8 *)0x0);
  }
  puVar3 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x58));
  if (puVar6 == (undefined8 *)0x0) {
    WppTraceIndent(puVar3,(longlong *)0x2);
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sP(puVar3,0x20,pcVar9,param_4,(char)param_1);
    }
    WppTraceIndent(puVar3,(longlong *)0x1);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar4 = 0x21;
  }
  else {
    puVar3 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*puVar6);
    WppTraceIndent(puVar3,(longlong *)0x1);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
      return;
    }
    uVar4 = 0x22;
  }
  WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  return;
}



===== WdfScFilter_EvtFileCreateCompletionRoutine @ 140003290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfScFilter_EvtFileCreateCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  undefined8 **ppuVar10;
  longlong *local_res18 [2];
  longlong local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  longlong local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  iVar1 = *(int *)(param_3 + 8);
  local_78 = local_78 & 0xffffffff00000000;
  local_b0 = (undefined8 *)0x0;
  iVar3 = 0;
  local_res18[0] = (longlong *)0x0;
  local_b8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_40 = local_40 & 0xffffffff00000000;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  WppTraceIndent(0,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,lVar4);
  puVar7 = WdfDriverGlobals;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018);
  if (iVar1 < 0) goto LAB_140003644;
  ppuVar10 = &local_b0;
  lVar8 = lVar6;
  iVar3 = WdfScFilter_GetReaderSlotByFileObject(lVar6,lVar4,(char *)ppuVar10,param_4);
  puVar2 = local_b0;
  if (iVar3 < 0) {
    local_78 = 0;
    local_98 = 0;
    param_4 = 0x31504353;
    uStack_90 = 0x100000001;
    uStack_80 = 0;
    uStack_a0 = 0;
    local_a8 = 0x38;
    puVar7 = WdfDriverGlobals;
    local_88 = uVar5;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_a8,0x200,0x31504353,0x90,&local_b8,local_res18);
    if (iVar3 < 0) {
      WppTraceIndent(puVar7,(longlong *)0x2);
      puVar7 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x3a;
LAB_1400034b9:
        puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_sl(puVar7,uVar9,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)iVar3)
        ;
      }
    }
    else {
      memset(local_res18[0],0,0x90);
      *local_res18[0] = local_b8;
      local_res18[0][2] = lVar4;
      local_res18[0][3] = 0;
      *(undefined1 *)(local_res18[0] + 0x10) = 0;
      *(undefined1 *)((longlong)local_res18[0] + 0x81) = 0;
      local_40 = 0;
      local_60 = 0;
      uStack_48 = 0;
      local_50 = local_b8;
      uStack_68 = 0;
      local_70 = 0x38;
      uStack_58 = 0x100000001;
      puVar7 = WdfDriverGlobals;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                        (WdfDriverGlobals,&local_70,local_res18[0] + 1);
      if (iVar3 < 0) {
        WppTraceIndent(puVar7,(longlong *)0x2);
        puVar7 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x3b;
          goto LAB_1400034b9;
        }
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x58));
        local_res18[0][0x11] = *(longlong *)(lVar6 + 0x48);
        *(longlong **)(lVar6 + 0x48) = local_res18[0];
        local_b8 = 0;
        puVar7 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x58));
      }
    }
  }
  else {
    WppTraceIndent(lVar8,(longlong *)0x2);
    puVar7 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sP(puVar7,0x39,ppuVar10,param_4,(char)puVar2[2]);
    }
  }
  if (puVar2 != (undefined8 *)0x0) {
    param_4 = 0x2bf;
    puVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*puVar2,0,0x2bf,"ds\\security\\scard\\scpnp\\filter\\scfilter.c");
  }
LAB_140003644:
  if (local_b8 != 0) {
    puVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x680))();
  }
  if (((iVar3 < 0) &&
      (WppTraceIndent(puVar7,(longlong *)0x2),
      (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)iVar3);
  }
  uVar5 = *(undefined8 *)(param_3 + 0x10);
  puVar7 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar1);
  WppTraceIndent(puVar7,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar5,(char)iVar1);
  }
  return;
}



===== WdfScFilter_EvtIoCompletionRoutine @ 140003730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfScFilter_EvtIoCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  uint *puVar11;
  undefined8 *puVar12;
  undefined *puVar13;
  int iVar14;
  uint local_res18 [2];
  undefined8 *local_38 [2];
  
  iVar14 = *(int *)(param_3 + 8);
  puVar12 = (undefined8 *)0x0;
  local_res18[0] = 0;
  local_38[0] = (undefined8 *)0x0;
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x570))(WdfDriverGlobals,param_2);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  uVar7 = WdfDriverGlobals;
  puVar13 = PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  WppTraceIndent(uVar7,(longlong *)0x2);
  puVar8 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar13 = &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids;
    puVar8 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_sl(puVar8,0x2d,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,
              (char)*(undefined4 *)(param_3 + 0x18));
  }
  WppTraceIndent(puVar8,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar13 = &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids;
    WPP_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
               &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)uVar3,(char)lVar4);
  }
  if (*(int *)(param_3 + 0x18) == 0x310008) {
    WppTraceIndent(0,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar13 = &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids;
      WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,
                (char)*(undefined4 *)(lVar5 + 0x50));
    }
    if (*(int *)(lVar5 + 0x50) == 0x10100) {
      puVar11 = (uint *)(lVar5 + 8);
      uVar9 = 0;
      if (*(ulonglong *)(param_3 + 0x40) < 0x21) {
LAB_140003b56:
        WppTraceIndent(uVar9,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_sP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,puVar13,param_4,
                    (char)*(undefined8 *)(param_3 + 0x40));
        }
        uVar7 = WdfDriverGlobals;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x620))
                          (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x30),
                           *(undefined8 *)(param_3 + 0x38),puVar11,*(undefined8 *)(param_3 + 0x40));
        if (iVar2 < 0) {
          WppTraceIndent(uVar7,(longlong *)0x2);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                      &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,puVar11,(char)iVar2);
          }
          goto LAB_140003c62;
        }
        if (*(int *)(lVar5 + 0x50) != 0x7fff0001) goto LAB_140003c62;
        iVar14 = WdfScFilter_RecordReaderId(uVar7,lVar4,lVar5,(char *)(ulonglong)local_res18[0]);
        goto LAB_140003c32;
      }
      WppTraceIndent(0,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) goto LAB_140003c62;
      uVar10 = 0x30;
    }
    else {
      uVar6 = *(int *)(lVar5 + 0x50) - 0x10101;
      uVar9 = (ulonglong)uVar6;
      if (uVar6 == 0) {
        puVar11 = (uint *)(lVar5 + 0x28);
        if (*(ulonglong *)(param_3 + 0x40) < 0x21) goto LAB_140003b56;
        WppTraceIndent(0,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140003c62;
        uVar10 = 0x31;
      }
      else {
        if (uVar6 != 0x7ffdff00) goto LAB_140003c62;
        puVar11 = local_res18;
        if (*(ulonglong *)(param_3 + 0x40) < 5) goto LAB_140003b56;
        WppTraceIndent(0x7ffdff00,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140003c62;
        uVar10 = 0x32;
      }
    }
    WPP_SF_sP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,puVar13,param_4,
              (char)*(undefined8 *)(param_3 + 0x40));
  }
  else {
    if (*(int *)(param_3 + 0x18) != 0x31002c) goto LAB_140003c62;
    iVar2 = WdfScFilter_GetReaderSlotByFileObject(lVar5,lVar4,(char *)local_38,param_4);
    puVar12 = local_38[0];
    if (iVar2 < 0) {
      WppTraceIndent(lVar5,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                  &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)iVar2);
      }
      puVar12 = local_38[0];
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_38[0][1]);
      cVar1 = *(char *)(puVar12 + 0x10);
      if (cVar1 == '\0') {
        *(undefined1 *)((longlong)puVar12 + 0x81) = 0;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,puVar12[3],0,0x237,
                   "ds\\security\\scard\\scpnp\\filter\\scfilter.c");
        *(undefined1 *)(puVar12 + 0x10) = 0;
      }
      puVar12[3] = 0;
      uVar7 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar12[1]);
      if ((cVar1 != '\0') && (*(int *)(param_3 + 8) == -0x3ffffee0)) {
        WppTraceIndent(uVar7,(longlong *)0x2);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                   &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
        }
        iVar14 = 0;
      }
    }
LAB_140003c32:
    if (puVar12 != (undefined8 *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,*puVar12,0,600,"ds\\security\\scard\\scpnp\\filter\\scfilter.c");
    }
  }
LAB_140003c62:
  uVar7 = *(undefined8 *)(param_3 + 0x10);
  uVar3 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar14);
  WppTraceIndent(uVar3,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar7,(char)iVar14);
  }
  return;
}



===== WdfScFilter_EvtIoDeviceControl @ 140003cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140004197) */
/* WARNING: Removing unreachable block (ram,0x000140004229) */
/* WARNING: Removing unreachable block (ram,0x0001400042b1) */
/* WARNING: Removing unreachable block (ram,0x0001400042f9) */
/* WARNING: Removing unreachable block (ram,0x00014000433b) */
/* WARNING: Removing unreachable block (ram,0x000140004346) */
/* WARNING: Removing unreachable block (ram,0x000140004350) */
/* WARNING: Removing unreachable block (ram,0x000140004250) */
/* WARNING: Removing unreachable block (ram,0x000140004292) */
/* WARNING: Removing unreachable block (ram,0x00014000429d) */
/* WARNING: Removing unreachable block (ram,0x0001400042a7) */
/* WARNING: Removing unreachable block (ram,0x0001400041c8) */
/* WARNING: Removing unreachable block (ram,0x00014000420a) */
/* WARNING: Removing unreachable block (ram,0x000140004215) */
/* WARNING: Removing unreachable block (ram,0x00014000421f) */

void WdfScFilter_EvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  undefined8 *puVar11;
  undefined1 auStackY_c8 [32];
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_58 = 0;
  local_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_70 = (undefined8 *)0x0;
  local_68 = 0;
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  uVar7 = WdfDriverGlobals;
  puVar6 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4);
  WppTraceIndent(uVar7,(longlong *)0x2);
  puVar8 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar8 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_sl(puVar8,0x3f,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)param_5);
  }
  WppTraceIndent(puVar8,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
               &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)uVar4,(char)lVar5);
  }
  if (param_5 == 0x310008) {
    puVar6 = &local_68;
    uVar4 = 0;
    uVar7 = WdfDriverGlobals;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2);
    if (-1 < iVar3) {
      WppTraceIndent(uVar7,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_sP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,uVar4,puVar6,0);
      }
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0xc000000d,0);
      return;
    }
    WppTraceIndent(uVar7,(longlong *)0x2);
    puVar11 = (undefined8 *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar3);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return;
    }
    uVar10 = 0x43;
    goto LAB_140004499;
  }
  if (param_5 == 0x31002c) {
    puVar9 = puVar6;
    iVar3 = WdfScFilter_GetReaderSlotByFileObject((longlong)puVar6,lVar5,(char *)&local_70,param_4);
    puVar11 = local_70;
    if (iVar3 < 0) {
      WppTraceIndent(puVar9,(longlong *)0x2);
      puVar11 = (undefined8 *)0x0;
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar3);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return;
      }
      uVar10 = 0x41;
      goto LAB_140004499;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_70[1]);
    puVar11[3] = param_2;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar11[1]);
    (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,*puVar11,0,0x307);
    uVar7 = WdfDriverGlobals;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x5d8))(WdfDriverGlobals,*puVar6,param_2);
    if (iVar3 < 0) {
      WppTraceIndent(uVar7,(longlong *)0x2);
      puVar11 = (undefined8 *)0x0;
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar3);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return;
      }
      uVar10 = 0x42;
      goto LAB_140004499;
    }
    bVar1 = true;
    uVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_2,WdfScFilter_EvtIoCompletionRoutine,0);
    WppTraceIndent(uVar7,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar10 = 0x48;
      goto LAB_1400043b2;
    }
  }
  else {
    uVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x7d8))(WdfDriverGlobals,param_2);
    uStack_48 = 0;
    local_50 = 0x800000010;
    WppTraceIndent(uVar7,(longlong *)0x2);
    iVar3 = 0;
    bVar1 = false;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar10 = 0x49;
LAB_1400043b2:
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
    }
  }
  puVar11 = &local_50;
  if (bVar1) {
    puVar11 = (undefined8 *)0x0;
  }
  uVar7 = WdfDriverGlobals;
  cVar2 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,*puVar6);
  if (cVar2 == '\0') {
    uVar7 = WdfDriverGlobals;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
    WppTraceIndent(uVar7,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,puVar11,(char)iVar3);
    }
    uVar7 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
  }
  WppTraceIndent(uVar7,(longlong *)0x1);
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
    return;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
    return;
  }
  uVar10 = 0x4b;
LAB_140004499:
  WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
            &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,puVar11,(char)iVar3);
  return;
}



===== WdfScFilter_GetReaderSlotByFileObject @ 1400044d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WdfScFilter_GetReaderSlotByFileObject
          (longlong param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined8 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  uVar4 = 0;
  pcVar5 = param_3;
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar5 = &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids;
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  puVar1 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
  puVar2 = *(undefined8 **)(param_1 + 0x48);
  if (puVar2 != (undefined8 *)0x0) {
    do {
      if (param_2 == puVar2[2]) {
        WppTraceIndent(puVar1,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar3 = "NULL";
          if (*(char *)(puVar2 + 4) != '\0') {
            pcVar3 = (char *)(puVar2 + 4);
          }
          WPP_SF_sqs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,pcVar5,param_4,(char)puVar2[2],
                     pcVar3);
        }
        param_4 = 0x1c0;
        (**(code **)(WdfFunctions_01015 + 0x668))
                  (WdfDriverGlobals,*puVar2,0,0x1c0,"ds\\security\\scard\\scpnp\\filter\\scfilter.c"
                  );
        *(undefined8 **)param_3 = puVar2;
        goto LAB_1400045d2;
      }
      WppTraceIndent(puVar1,(longlong *)0x2);
      puVar1 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        pcVar5 = "NULL";
        if (*(char *)(puVar2 + 4) != '\0') {
          pcVar5 = (char *)(puVar2 + 4);
        }
        WPP_SF_sqs(puVar1,0x2a,pcVar5,param_4,(char)puVar2[2],pcVar5);
      }
      puVar2 = (undefined8 *)puVar2[0x11];
    } while (puVar2 != (undefined8 *)0x0);
  }
  uVar4 = 0x8000001a;
LAB_1400045d2:
  puVar1 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
  WppTraceIndent(puVar1,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)uVar4);
  }
  return uVar4;
}



===== WdfScFilter_RecordReaderId @ 1400046dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfScFilter_RecordReaderId(undefined8 param_1,longlong param_2,longlong param_3,char *param_4)

{
  char *pcVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar4 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar4,0x23,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  pcVar6 = (char *)(param_3 + 8);
  pcVar1 = (char *)(param_3 + 0x28);
  if ((*pcVar6 == '\0') && (*pcVar1 == '\0')) {
    WppTraceIndent(puVar4,(longlong *)0x2);
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_s(puVar4,0x24,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
    }
    iVar3 = -0x3ffffff3;
    goto LAB_1400048ed;
  }
  iVar3 = WdfScFilter_GetReaderSlotByFileObject(param_3,param_2,(char *)&local_res8,param_4);
  puVar2 = local_res8;
  if (iVar3 < 0) {
    WppTraceIndent(param_3,(longlong *)0x2);
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sl(puVar4,0x25,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)iVar3);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_res8[1]);
    pcVar5 = (char *)(puVar2 + 4);
    if (*pcVar6 == '\0') {
      pcVar6 = pcVar1;
LAB_14000483a:
      RtlStringCbPrintfA(pcVar5,0x60,"%s %d",pcVar6);
      param_4 = pcVar6;
    }
    else {
      if (*pcVar1 == '\0') goto LAB_14000483a;
      RtlStringCbPrintfA(pcVar5,0x60,"%s %s %d",pcVar6);
      param_4 = pcVar6;
    }
    WppTraceIndent(pcVar5,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
    }
    puVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar2[1]);
  }
  if (puVar2 != (undefined8 *)0x0) {
    param_4 = (char *)0x18c;
    puVar4 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*puVar2,0,0x18c,"ds\\security\\scard\\scpnp\\filter\\scfilter.c");
  }
LAB_1400048ed:
  WppTraceIndent(puVar4,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,(char)iVar3);
  }
  return iVar3;
}



===== WppClassicProviderCallback @ 140004950 =====

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



===== WppTraceIndent @ 140004984 =====

void WppTraceIndent(undefined8 param_1,longlong *param_2)

{
  int *piVar1;
  HRESULT HVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  STRSAFE_LPSTR pszDest;
  STRSAFE_LPSTR pszDest_00;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pszSrc;
  
  pszDest_00 = (STRSAFE_LPSTR)((ulonglong)param_2 & 0xffffffff);
  iVar7 = (int)param_2;
  if (`WppTraceIndent'::__l2::idxCurrentThread == 0xffffffff) {
    `WppTraceIndent'::__l2::ThreadTable = SystemReserved1[0xf];
    DAT_14000a198 = 0;
    `WppTraceIndent'::__l2::idxCurrentThread = 0;
LAB_140004a3f:
    lVar3 = (longlong)(int)`WppTraceIndent'::__l2::idxCurrentThread;
    if (iVar7 == 0) {
      (&DAT_14000a198)[lVar3 * 4] = (&DAT_14000a198)[lVar3 * 4] + 1;
    }
    iVar6 = (&DAT_14000a198)[lVar3 * 4];
  }
  else {
    if ((`WppTraceIndent'::__l2::idxCurrentThread == 0xfffffffe) ||
       ((&`WppTraceIndent'::__l2::ThreadTable)
        [(longlong)(int)`WppTraceIndent'::__l2::idxCurrentThread * 2] != SystemReserved1[0xf])) {
      uVar5 = 0xffffffff;
      param_2 = (longlong *)&`WppTraceIndent'::__l2::ThreadTable;
      uVar4 = 0;
      do {
        if ((void *)*param_2 == SystemReserved1[0xf]) {
          `WppTraceIndent'::__l2::idxCurrentThread = uVar4;
          break;
        }
        if ((uVar5 == 0xffffffff) && ((void *)*param_2 == (void *)0x0)) {
          uVar5 = uVar4;
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 2;
      } while (uVar4 < 0x20);
      if (uVar4 == 0x20) {
        if (uVar5 == 0xffffffff) {
          `WppTraceIndent'::__l2::idxCurrentThread = 0xfffffffe;
        }
        else {
          `WppTraceIndent'::__l2::idxCurrentThread = uVar5;
          (&`WppTraceIndent'::__l2::ThreadTable)[(longlong)(int)uVar5 * 2] = SystemReserved1[0xf];
          (&DAT_14000a198)[(longlong)(int)uVar5 * 4] = 0;
        }
      }
    }
    if (-1 < (int)`WppTraceIndent'::__l2::idxCurrentThread) goto LAB_140004a3f;
    iVar6 = 0;
  }
  `WppTraceIndent'::__l2::szIndentPrefix = 0;
  if ((((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) &&
     (iVar8 = 1, pszDest = WPP_GLOBAL_Control, 0 < iVar6)) {
    do {
      HVar2 = StringCbCatA(pszDest,(size_t)param_2,"..");
      if (HVar2 != 0) break;
      iVar8 = iVar8 + 1;
    } while (iVar8 <= iVar6);
  }
  if (iVar7 == 0) {
    pszSrc = ">";
  }
  else {
    uVar5 = iVar7 - 1;
    pszDest_00 = (STRSAFE_LPSTR)(ulonglong)uVar5;
    if (uVar5 == 0) {
      pszSrc = "<";
    }
    else {
      if (uVar5 != 1) goto LAB_140004abc;
      pszSrc = " ";
    }
  }
  StringCbCatA(pszDest_00,(size_t)param_2,pszSrc);
LAB_140004abc:
  lVar3 = (longlong)(int)`WppTraceIndent'::__l2::idxCurrentThread;
  if ((-1 < (int)`WppTraceIndent'::__l2::idxCurrentThread) && (iVar7 == 1)) {
    piVar1 = &DAT_14000a198 + lVar3 * 4;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (&`WppTraceIndent'::__l2::ThreadTable)[lVar3 * 2] = (void *)0x0;
    }
  }
  WPP_pszIndent = &`WppTraceIndent'::__l2::szIndentPrefix;
  return;
}



===== RtlUnicodeStringPrintf @ 140004b08 =====

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



===== WPP_SF_sS @ 140004ba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
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
  lVar2 = -1;
  if (WPP_pszIndent == (char *)0x0) {
    lVar3 = 5;
    pcVar4 = "NULL";
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (WPP_pszIndent[lVar2] != '\0');
    lVar3 = lVar3 + 2;
    pcVar4 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_2,pcVar4,lVar3,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_ssq @ 140004c58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ssq(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *in_stack_00000028;
  undefined1 uStack0000000000000030;
  
  if (in_stack_00000028 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000028[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  lVar2 = -1;
  if (WPP_pszIndent == (char *)0x0) {
    lVar1 = 5;
    pcVar4 = "NULL";
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (WPP_pszIndent[lVar2] != '\0');
    lVar1 = lVar1 + 2;
    pcVar4 = WPP_pszIndent;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,0x47,pcVar4,lVar1,
             in_stack_00000028,lVar3,&uStack0000000000000030,8,0);
  return;
}



===== WdfScFilter_EvtChildListIdentificationDescriptionCleanup @ 140004d20 =====

void WdfScFilter_EvtChildListIdentificationDescriptionCleanup
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar1 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar1,0x29,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_2 == 0) {
    WppTraceIndent(puVar1,(longlong *)0x2);
    uVar2 = 0xd;
    puVar1 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_s(puVar1,0x2a,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
    }
  }
  else {
    puVar1 = *(undefined **)(param_2 + 0x68);
    if (puVar1 != (undefined *)0x0) {
      ExFreePoolWithTag(puVar1,0);
      *(undefined8 *)(param_2 + 0x68) = 0;
    }
  }
  WppTraceIndent(puVar1,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,uVar2);
  }
  return;
}



===== WdfScFilter_EvtChildListIdentificationDescriptionCompare @ 140004e20 =====

bool WdfScFilter_EvtChildListIdentificationDescriptionCompare
               (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined *puVar3;
  wchar_t *_Str1;
  undefined2 uVar4;
  undefined1 uVar5;
  bool bVar6;
  
  uVar5 = 0;
  bVar6 = false;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar3 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar3,0x23,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_2 == 0) {
    WppTraceIndent(puVar3,(longlong *)0x2);
    uVar5 = 0xd;
    _Str1 = (wchar_t *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140004fa9;
    uVar4 = 0x24;
  }
  else if (param_3 == 0) {
    WppTraceIndent(puVar3,(longlong *)0x2);
    uVar5 = 0xd;
    _Str1 = (wchar_t *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140004fa9;
    uVar4 = 0x25;
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x68);
    if (lVar1 == 0) {
      WppTraceIndent(0,(longlong *)0x2);
      uVar5 = 0xd;
      _Str1 = (wchar_t *)WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_140004fa9;
      uVar4 = 0x26;
    }
    else {
      if (*(longlong *)(param_3 + 0x68) != 0) {
        _Str1 = (wchar_t *)(lVar1 + 0x300);
        iVar2 = wcsncmp(_Str1,(wchar_t *)(*(longlong *)(param_3 + 0x68) + 0x300),0x60);
        bVar6 = iVar2 == 0;
        goto LAB_140004fa9;
      }
      WppTraceIndent(lVar1,(longlong *)0x2);
      uVar5 = 0xd;
      _Str1 = (wchar_t *)WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_140004fa9;
      uVar4 = 0x27;
    }
  }
  uVar5 = 0xd;
  _Str1 = *(wchar_t **)(WPP_GLOBAL_Control + 0x18);
  WPP_SF_s(_Str1,uVar4,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
LAB_140004fa9:
  WppTraceIndent(_Str1,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,uVar5);
  }
  return bVar6;
}



===== WdfScFilter_EvtChildListIdentificationDescriptionDuplicate @ 140005010 =====

uint WdfScFilter_EvtChildListIdentificationDescriptionDuplicate
               (undefined8 param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  uint uVar11;
  longlong lVar12;
  
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar5 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar5,0x1c,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_2 == 0) {
    WppTraceIndent(puVar5,(longlong *)0x2);
    uVar11 = 0xc000000d;
    puVar8 = (undefined8 *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400052ac;
    uVar10 = 0x1d;
  }
  else if (param_3 == 0) {
    WppTraceIndent(puVar5,(longlong *)0x2);
    uVar11 = 0xc000000d;
    puVar8 = (undefined8 *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400052ac;
    uVar10 = 0x1e;
  }
  else {
    if (*(longlong *)(param_2 + 0x68) != 0) {
      uVar6 = 0x40;
      lVar2 = ExAllocatePool2(0x40,0x3c4,0x32504353);
      *(longlong *)(param_3 + 0x68) = lVar2;
      if (lVar2 == 0) {
        WppTraceIndent(uVar6,(longlong *)0x2);
        puVar8 = (undefined8 *)WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar8 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
          WPP_SF_s(puVar8,0x20,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
        }
        uVar11 = 0xc000009a;
      }
      else {
        pcVar7 = (char *)(param_3 + 4);
        lVar2 = 0x60;
        lVar12 = param_2 - (longlong)pcVar7;
        do {
          if ((lVar2 == -0x7fffff9e) || (pcVar7[lVar12 + 4] == '\0')) break;
          *pcVar7 = pcVar7[lVar12 + 4];
          pcVar7 = pcVar7 + 1;
          lVar2 = lVar2 + -1;
        } while (lVar2 != 0);
        pcVar3 = pcVar7 + -1;
        if (lVar2 != 0) {
          pcVar3 = pcVar7;
        }
        *pcVar3 = '\0';
        uVar11 = ~-(uint)(lVar2 != 0) & 0x80000005;
        if (lVar2 == 0) {
          WppTraceIndent(pcVar7,(longlong *)0x2);
          puVar8 = (undefined8 *)WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar8 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
            WPP_SF_sl(puVar8,0x21,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,5);
          }
        }
        else {
          lVar2 = 7;
          puVar1 = *(undefined8 **)(param_2 + 0x68);
          puVar8 = *(undefined8 **)(param_3 + 0x68);
          do {
            puVar9 = puVar8;
            puVar4 = puVar1;
            uVar6 = puVar4[1];
            *puVar9 = *puVar4;
            puVar9[1] = uVar6;
            uVar6 = puVar4[3];
            puVar9[2] = puVar4[2];
            puVar9[3] = uVar6;
            uVar6 = puVar4[5];
            puVar9[4] = puVar4[4];
            puVar9[5] = uVar6;
            uVar6 = puVar4[7];
            puVar9[6] = puVar4[6];
            puVar9[7] = uVar6;
            uVar6 = puVar4[9];
            puVar9[8] = puVar4[8];
            puVar9[9] = uVar6;
            uVar6 = puVar4[0xb];
            puVar9[10] = puVar4[10];
            puVar9[0xb] = uVar6;
            uVar6 = puVar4[0xd];
            puVar9[0xc] = puVar4[0xc];
            puVar9[0xd] = uVar6;
            puVar8 = puVar9 + 0x10;
            uVar6 = puVar4[0xf];
            puVar9[0xe] = puVar4[0xe];
            puVar9[0xf] = uVar6;
            lVar2 = lVar2 + -1;
            puVar1 = puVar4 + 0x10;
          } while (lVar2 != 0);
          uVar6 = puVar4[0x11];
          *puVar8 = puVar4[0x10];
          puVar9[0x11] = uVar6;
          uVar6 = puVar4[0x13];
          puVar9[0x12] = puVar4[0x12];
          puVar9[0x13] = uVar6;
          uVar6 = puVar4[0x15];
          puVar9[0x14] = puVar4[0x14];
          puVar9[0x15] = uVar6;
          uVar6 = puVar4[0x17];
          puVar9[0x16] = puVar4[0x16];
          puVar9[0x17] = uVar6;
          *(undefined4 *)(puVar9 + 0x18) = *(undefined4 *)(puVar4 + 0x18);
        }
      }
      goto LAB_1400052ac;
    }
    WppTraceIndent(puVar5,(longlong *)0x2);
    uVar11 = 0xc000000d;
    puVar8 = (undefined8 *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400052ac;
    uVar10 = 0x1f;
  }
  uVar11 = 0xc000000d;
  puVar8 = *(undefined8 **)(WPP_GLOBAL_Control + 0x18);
  WPP_SF_s(puVar8,uVar10,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
LAB_1400052ac:
  WppTraceIndent(puVar8,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar11);
  }
  return uVar11;
}



===== WdfScFilter_EvtIoDeviceControlForRawPdo @ 140005310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WdfScFilter_EvtIoDeviceControlForRawPdo
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t **param_4,
               int param_5)

{
  bool bVar1;
  bool bVar2;
  wchar_t *_Str2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined4 *_Dst;
  undefined *puVar10;
  wchar_t *pwVar11;
  wchar_t *pwVar12;
  char *pcVar13;
  undefined2 uVar14;
  longlong lVar15;
  undefined8 *puVar16;
  undefined *puVar17;
  undefined8 **ppuVar18;
  longlong lVar19;
  wchar_t *_Str2_00;
  undefined1 auStackY_128 [32];
  undefined8 *local_f0;
  wchar_t *local_e8;
  longlong local_e0;
  ulonglong local_d8;
  longlong local_d0;
  wchar_t *local_c8;
  longlong local_c0;
  undefined4 local_b8;
  char local_b4 [100];
  wchar_t *local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  _Dst = &local_b8;
  uVar5 = 0;
  memset(_Dst,0,0x70);
  local_c8 = (wchar_t *)0x0;
  local_d0 = 0;
  local_d8 = 0;
  local_c0 = 0;
  local_e8 = (wchar_t *)0x0;
  local_e0 = 0;
  local_f0 = (undefined8 *)0x0;
  WppTraceIndent(_Dst,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
             &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,uVar7);
  puVar10 = WdfDriverGlobals;
  puVar17 = PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018;
  lVar15 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar8);
  WppTraceIndent(puVar10,(longlong *)0x2);
  puVar10 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar17 = &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids;
    WPP_SF_sl(puVar10,0x4a,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)param_5);
  }
  WppTraceIndent(puVar10,(longlong *)0x2);
  puVar10 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar17 = &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids;
    WPP_SF_sqq(puVar10,0x4b,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar7,
               (char)uVar8);
  }
  if (param_5 == 0x310fa0) {
    param_4 = &local_c8;
    uVar7 = 0;
    puVar10 = WdfDriverGlobals;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2);
    _Str2 = local_c8;
    if ((int)uVar5 < 0) {
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x4c;
        goto LAB_1400060eb;
      }
      goto LAB_1400060fb;
    }
    if (local_d0 == 0x3c4) {
      local_c8[0x7f] = L'\0';
      local_c8[0xff] = L'\0';
      local_c8[0x17f] = L'\0';
      local_c8[0x1df] = L'\0';
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,uVar7,param_4,_Str2);
      }
      pwVar11 = L"SCFILTER\\CID_";
      iVar6 = wcsncmp(L"SCFILTER\\CID_",_Str2,0xd);
      if (iVar6 == 0) {
        pwVar12 = _Str2 + 0x80;
        if (pwVar12 == (wchar_t *)0x0) {
          uVar5 = 0xc000000d;
        }
        else {
          _Str2_00 = pwVar12;
          uVar5 = RtlStringLengthWorkerW(pwVar12,0x80,&local_c0);
          pwVar11 = pwVar12;
          if (-1 < (int)uVar5) {
            if (local_c0 != 0) {
              pwVar11 = L"SCFILTER\\CID_";
              iVar6 = wcsncmp(L"SCFILTER\\CID_",_Str2_00,0xd);
              if (iVar6 != 0) {
                WppTraceIndent(pwVar11,(longlong *)0x2);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar14 = 0x51;
                  goto LAB_140005844;
                }
                goto LAB_140005690;
              }
            }
            local_b8 = 0x70;
            uVar5 = WdfScFilter_GetReaderSlotByReaderId(lVar15,_Str2 + 0x180,&local_f0,param_4);
            puVar16 = local_f0;
            if ((int)uVar5 < 0) {
              WppTraceIndent(lVar15,(longlong *)0x2);
              puVar10 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar14 = 0x52;
                goto LAB_1400058b0;
              }
              goto LAB_1400058c4;
            }
            local_50 = _Str2;
            (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_f0[1]);
            lVar15 = 0x60;
            lVar19 = (longlong)puVar16 + (0x20 - (longlong)local_b4);
            pcVar13 = local_b4;
            do {
              if ((lVar15 == -0x7fffff9e) || (pcVar13[lVar19] == '\0')) break;
              *pcVar13 = pcVar13[lVar19];
              pcVar13 = pcVar13 + 1;
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
            pcVar9 = pcVar13 + -1;
            if (lVar15 != 0) {
              pcVar9 = pcVar13;
            }
            *pcVar9 = '\0';
            if (lVar15 == 0) {
              WppTraceIndent(pcVar13,(longlong *)0x2);
              uVar5 = 0x80000005;
              puVar10 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400059b0;
              uVar14 = 0x53;
              goto LAB_140005c6a;
            }
            (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar16[1]);
            uVar7 = uVar8;
            uVar5 = WdfScFilter_RemoveChildNodeByReaderName(uVar8,local_b4,lVar19,param_4);
            if ((int)uVar5 < 0) {
              WppTraceIndent(uVar7,(longlong *)0x2);
              puVar10 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar14 = 0x54;
LAB_140006009:
                puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
                WPP_SF_sl(puVar10,uVar14,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,
                          (char)uVar5);
              }
            }
            else {
              uVar7 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,uVar8);
              param_4 = (wchar_t **)0x0;
              puVar10 = WdfDriverGlobals;
              uVar5 = (**(code **)(WdfFunctions_01015 + 0x48))(WdfDriverGlobals,uVar7,&local_b8);
              if ((int)uVar5 < 0) {
                WppTraceIndent(puVar10,(longlong *)0x2);
                puVar10 = WPP_GLOBAL_Control;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar14 = 0x55;
                  goto LAB_140006009;
                }
              }
            }
            goto LAB_1400058c9;
          }
        }
        WppTraceIndent(pwVar11,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar14 = 0x50;
LAB_1400060eb:
          WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                    &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar5);
        }
        goto LAB_1400060fb;
      }
      WppTraceIndent(pwVar11,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x4f;
        goto LAB_140005844;
      }
    }
    else {
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x4d;
LAB_140005844:
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                 &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
      }
    }
LAB_140005690:
    uVar5 = 0xc000000d;
  }
  else if (param_5 == 0x310fa4) {
    param_4 = &local_e8;
    puVar10 = WdfDriverGlobals;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0xc0);
    if ((int)uVar5 < 0) {
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x56;
        goto LAB_1400060eb;
      }
      goto LAB_1400060fb;
    }
    if (local_e0 != 0xc0) {
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x57;
        goto LAB_140005844;
      }
      goto LAB_140005690;
    }
    ppuVar18 = &local_f0;
    local_e8[0x5f] = L'\0';
    uVar5 = WdfScFilter_GetReaderSlotByReaderId(lVar15,local_e8,ppuVar18,param_4);
    puVar16 = local_f0;
    if ((int)uVar5 < 0) {
      WppTraceIndent(lVar15,(longlong *)0x2);
      puVar10 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x58;
LAB_1400058b0:
        puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_sl(puVar10,uVar14,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,
                  (char)uVar5);
      }
LAB_1400058c4:
      puVar16 = local_f0;
      goto LAB_1400058c9;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_f0[1]);
    if (*(char *)((longlong)puVar16 + 0x81) == '\0') {
      uVar5 = WdfScFilter_RemoveChildNodeByReaderName(uVar8,(char *)(puVar16 + 4),ppuVar18,param_4);
      if (-1 < (int)uVar5) goto LAB_140005bf6;
      WppTraceIndent(uVar8,(longlong *)0x2);
      puVar10 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1400059b0;
      uVar14 = 0x59;
LAB_140005c6a:
      puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sl(puVar10,uVar14,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar5)
      ;
LAB_1400059b0:
      bVar1 = true;
    }
    else {
      uVar5 = 0x80000011;
      *(undefined1 *)((longlong)puVar16 + 0x81) = 0;
LAB_140005bf6:
      puVar10 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar16[1]);
LAB_1400058c9:
      bVar1 = false;
    }
    bVar2 = true;
LAB_1400058d5:
    if (puVar16 != (undefined8 *)0x0) {
      if (bVar1) {
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar16[1]);
      }
      param_4 = (wchar_t **)0x43d;
      puVar10 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,*puVar16,0);
    }
    if (!bVar2) goto LAB_14000611b;
  }
  else if (param_5 == 0x310fa8) {
    lVar19 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals);
    bVar3 = WdfScFilter_IsDeviceNodePresentInChildList(lVar19,uVar8,puVar17,param_4);
    if (bVar3 == 0) {
      WppTraceIndent(lVar19,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x5b;
LAB_140005579:
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,
                 &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
      }
LAB_140005589:
      uVar5 = 0xc0000225;
    }
    else {
      param_4 = &local_e8;
      puVar10 = WdfDriverGlobals;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0xc0);
      if (-1 < (int)uVar5) {
        if (local_e0 != 0xc0) {
          WppTraceIndent(puVar10,(longlong *)0x2);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar14 = 0x5d;
            goto LAB_140005844;
          }
          goto LAB_140005690;
        }
        local_e8[0x5f] = L'\0';
        uVar5 = WdfScFilter_GetReaderSlotByReaderId(lVar15,local_e8,&local_f0,param_4);
        puVar16 = local_f0;
        if ((int)uVar5 < 0) {
          WppTraceIndent(lVar15,(longlong *)0x2);
          puVar10 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar14 = 0x5e;
            goto LAB_1400058b0;
          }
          goto LAB_1400058c4;
        }
        puVar10 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,local_f0[1]);
        *(undefined1 *)((longlong)puVar16 + 0x81) = 1;
        lVar15 = puVar16[3];
        if (lVar15 == 0) {
          WppTraceIndent(puVar10,(longlong *)0x2);
          puVar10 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
            WPP_SF_s(puVar10,0x5f,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
          }
          uVar5 = 0xc0000225;
          goto LAB_1400059b0;
        }
        (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,lVar15,0);
        *(undefined1 *)(puVar16 + 0x10) = 1;
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar16[1]);
        bVar1 = false;
        puVar10 = WdfDriverGlobals;
        cVar4 = (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,lVar15);
        bVar2 = false;
        if (((cVar4 == '\0') &&
            (WppTraceIndent(puVar10,(longlong *)0x2),
            (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
                   &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
        }
        param_4 = (wchar_t **)0x0;
        puVar10 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar5);
        goto LAB_1400058d5;
      }
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x5c;
        goto LAB_1400060eb;
      }
    }
  }
  else if (param_5 == 0x310fac) {
    param_4 = &local_e8;
    puVar10 = WdfDriverGlobals;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0);
    if ((int)uVar5 < 0) {
      WppTraceIndent(puVar10,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x61;
        goto LAB_1400060eb;
      }
    }
    else {
      if (local_e8 == (wchar_t *)0x0) goto LAB_140005690;
      local_f0 = (undefined8 *)CONCAT44(local_f0._4_4_,(int)(local_d8 >> 1));
      uVar5 = WdfScFilter_GetReaderIdMultiString
                        (lVar15,(uint *)local_e8,(uint *)&local_f0,(longlong)param_4);
      if (-1 < (int)uVar5) {
        param_4 = (wchar_t **)(((ulonglong)local_f0 & 0xffffffff) * 2);
        puVar10 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,uVar5);
        goto LAB_14000611b;
      }
      WppTraceIndent(lVar15,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x62;
        goto LAB_1400060eb;
      }
    }
  }
  else if (param_5 == 0x310fb0) {
    uVar7 = uVar8;
    lVar15 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals);
    bVar3 = WdfScFilter_IsDeviceNodePresentInChildList(lVar15,uVar7,puVar17,param_4);
    if (bVar3 == 0) {
      WppTraceIndent(lVar15,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar14 = 0x5a;
        goto LAB_140005579;
      }
      goto LAB_140005589;
    }
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,uVar8);
    (**(code **)(WdfFunctions_01015 + 0x20))(WdfDriverGlobals,uVar7);
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,uVar8);
    (**(code **)(WdfFunctions_01015 + 0x28))(WdfDriverGlobals,uVar7);
  }
  else {
    WppTraceIndent(puVar10,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
               &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
    }
    uVar5 = 0xc0000010;
  }
LAB_1400060fb:
  puVar10 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar5);
LAB_14000611b:
  WppTraceIndent(puVar10,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar5);
  }
  return;
}



===== WdfScFilter_GetReaderIdMultiString @ 14000618c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WdfScFilter_GetReaderIdMultiString
               (longlong param_1,uint *param_2,uint *param_3,longlong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  longlong lVar13;
  uint *puVar14;
  uint local_res8;
  ulonglong local_res20;
  uint *local_78;
  undefined8 local_70;
  wchar_t *pwStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  uVar4 = 0;
  local_res8 = 1;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  pwStack_68 = (wchar_t *)0x0;
  puVar12 = param_3;
  WppTraceIndent(param_1,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar12 = (uint *)&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids;
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
  puVar10 = (uint *)0x0;
  for (lVar13 = *(longlong *)(param_1 + 0x48); (lVar13 != 0 && (*(char *)(lVar13 + 0x20) != '\0'));
      lVar13 = *(longlong *)(lVar13 + 0x88)) {
    puVar12 = (uint *)0x32504353;
    puVar14 = (uint *)ExAllocatePool2(0x40,0x68,0x32504353);
    if (puVar14 == (uint *)0x0) {
      uVar7 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
      WppTraceIndent(uVar7,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                 &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
      }
      uVar4 = 0xc000009a;
      goto LAB_1400065cf;
    }
    uVar7 = *(undefined8 *)(lVar13 + 0x28);
    lVar6 = -1;
    *(undefined8 *)puVar14 = *(undefined8 *)(lVar13 + 0x20);
    *(undefined8 *)(puVar14 + 2) = uVar7;
    uVar7 = *(undefined8 *)(lVar13 + 0x38);
    *(undefined8 *)(puVar14 + 4) = *(undefined8 *)(lVar13 + 0x30);
    *(undefined8 *)(puVar14 + 6) = uVar7;
    uVar7 = *(undefined8 *)(lVar13 + 0x48);
    *(undefined8 *)(puVar14 + 8) = *(undefined8 *)(lVar13 + 0x40);
    *(undefined8 *)(puVar14 + 10) = uVar7;
    uVar7 = *(undefined8 *)(lVar13 + 0x58);
    *(undefined8 *)(puVar14 + 0xc) = *(undefined8 *)(lVar13 + 0x50);
    *(undefined8 *)(puVar14 + 0xe) = uVar7;
    uVar1 = *(uint *)(lVar13 + 100);
    uVar2 = *(uint *)(lVar13 + 0x68);
    uVar3 = *(uint *)(lVar13 + 0x6c);
    puVar14[0x10] = *(uint *)(lVar13 + 0x60);
    puVar14[0x11] = uVar1;
    puVar14[0x12] = uVar2;
    puVar14[0x13] = uVar3;
    uVar7 = *(undefined8 *)(lVar13 + 0x78);
    *(undefined8 *)(puVar14 + 0x14) = *(undefined8 *)(lVar13 + 0x70);
    *(undefined8 *)(puVar14 + 0x16) = uVar7;
    do {
      lVar6 = lVar6 + 1;
    } while (*(char *)((longlong)puVar14 + lVar6) != '\0');
    *(uint **)(puVar14 + 0x18) = puVar10;
    local_res8 = local_res8 + 1 + (int)lVar6;
    puVar10 = puVar14;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  local_res20 = (ulonglong)*param_3;
  if (*param_3 < local_res8) {
    uVar4 = 0xc0000023;
LAB_1400065cf:
    memset(param_2,0,(ulonglong)*param_3 * 2);
  }
  else {
    puVar14 = param_2;
    if (puVar10 != (uint *)0x0) {
      local_78 = puVar10;
      do {
        RtlInitAnsiString(&local_60,local_78);
        uVar7 = CONCAT71((int7)((ulonglong)puVar12 >> 8),1);
        puVar8 = &local_70;
        uVar4 = RtlAnsiStringToUnicodeString(puVar8,&local_60);
        WppTraceIndent(puVar8,(longlong *)0x2);
        if ((int)uVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                      &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar4);
          }
          goto LAB_1400065cf;
        }
        puVar11 = (uint *)WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar11 = *(uint **)(WPP_GLOBAL_Control + 0x18);
          WPP_SF_sS(puVar11,0x3f,uVar7,param_4,pwStack_68);
        }
        if ((local_res20 == 0) || (0x7fff < local_res20)) {
          uVar4 = 0xc000000d;
LAB_14000654e:
          WppTraceIndent(puVar11,(longlong *)0x2);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                      &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar4);
          }
          goto LAB_1400065cf;
        }
        puVar11 = (uint *)(local_70 & 0xffff);
        if ((((((local_70 & 1) != 0) || ((local_70 & 0x10000) != 0)) ||
             (local_70._2_2_ < (ushort)local_70)) || (local_70._2_2_ == 0xffff)) ||
           ((pwStack_68 == (wchar_t *)0x0 &&
            ((param_4 = 0, (ushort)local_70 != 0 || (local_70._2_2_ != 0)))))) {
          uVar4 = 0xc000000d;
          *(undefined2 *)puVar14 = 0;
          goto LAB_14000654e;
        }
        puVar12 = (uint *)(((ushort)local_70 >> 1) - local_res20);
        lVar13 = 0;
        param_4 = (longlong)pwStack_68 - (longlong)puVar14;
        uVar9 = local_res20;
        puVar11 = puVar14;
        do {
          if ((undefined *)((longlong)puVar12 + uVar9) == (undefined *)0x0) break;
          lVar13 = lVar13 + 1;
          *(undefined2 *)puVar11 = *(undefined2 *)(param_4 + (longlong)puVar11);
          puVar11 = (uint *)((longlong)puVar11 + 2);
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        puVar5 = (uint *)((longlong)puVar11 + -2);
        if (uVar9 != 0) {
          puVar5 = puVar11;
        }
        *(undefined2 *)puVar5 = 0;
        lVar6 = lVar13 + -1;
        if (uVar9 != 0) {
          lVar6 = lVar13;
        }
        puVar11 = (uint *)((longlong)puVar14 + lVar6 * 2);
        uVar4 = ~-(uint)(uVar9 != 0) & 0x80000005;
        if ((-1 < (int)uVar4) || (uVar4 == 0x80000005)) {
          puVar14 = puVar11;
          local_res20 = local_res20 - lVar6;
        }
        if ((int)uVar4 < 0) goto LAB_14000654e;
        puVar14 = (uint *)((longlong)puVar14 + 2);
        local_res20 = local_res20 - 1;
        RtlFreeUnicodeString(&local_70);
        pwStack_68 = (wchar_t *)0x0;
        local_78 = *(uint **)(local_78 + 0x18);
      } while (local_78 != (uint *)0x0);
    }
    *param_3 = local_res8;
    *(undefined2 *)puVar14 = 0;
    param_2 = param_3;
  }
  if (pwStack_68 != (wchar_t *)0x0) {
    param_2 = (uint *)&local_70;
    RtlFreeUnicodeString();
  }
  while (puVar10 != (uint *)0x0) {
    puVar12 = *(uint **)(puVar10 + 0x18);
    ExFreePoolWithTag(puVar10,0x32504353);
    param_2 = puVar10;
    puVar10 = puVar12;
  }
  WppTraceIndent(param_2,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar4);
  }
  return uVar4;
}



===== WdfScFilter_GetReaderSlotByReaderId @ 140006664 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint WdfScFilter_GetReaderSlotByReaderId
               (longlong param_1,wchar_t *param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  char *pcVar9;
  undefined2 uVar10;
  longlong local_res10;
  undefined8 *local_res18;
  undefined8 local_58;
  wchar_t *pwStack_50;
  undefined8 local_48;
  char *pcStack_40;
  
  local_48 = 0;
  pcStack_40 = (char *)0x0;
  local_res18 = param_3;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar6 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_3 = (undefined8 *)&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids;
    WPP_SF_s(puVar6,0x42,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  WppTraceIndent(puVar6,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,param_3,param_4,param_2);
  }
  uVar4 = 0;
  local_58 = 0;
  pwStack_50 = (wchar_t *)0x0;
  if (param_2 == (wchar_t *)0x0) {
LAB_140006753:
    sVar2 = 0;
    if (-1 < (int)uVar4) {
      sVar3 = local_58._2_2_;
      goto LAB_1400067a6;
    }
    WppTraceIndent(0,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140006968;
    uVar10 = 0x44;
LAB_140006789:
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar4);
    goto LAB_140006968;
  }
  local_res10 = 0;
  uVar4 = RtlStringLengthWorkerW(param_2,0x7fff,&local_res10);
  if ((int)uVar4 < 0) goto LAB_140006753;
  sVar2 = (short)local_res10 * 2 + 2;
  local_58._0_4_ = CONCAT22(sVar2,(short)local_res10 * 2);
  sVar3 = sVar2;
  pwStack_50 = param_2;
LAB_1400067a6:
  uVar7 = 0x40;
  local_48._0_4_ = CONCAT22(sVar3,(undefined2)local_48);
  pcStack_40 = (char *)ExAllocatePool2(0x40,sVar2,0x32504353);
  if (pcStack_40 == (char *)0x0) {
    WppTraceIndent(uVar7,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
               &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
    }
    uVar4 = 0xc000009a;
    goto LAB_140006968;
  }
  puVar8 = &local_48;
  uVar4 = RtlUnicodeStringToAnsiString(puVar8,&local_58,0);
  if ((int)uVar4 < 0) {
    WppTraceIndent(puVar8,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140006968;
    uVar10 = 0x46;
    goto LAB_140006789;
  }
  pcVar9 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
  puVar8 = *(undefined8 **)(param_1 + 0x48);
  if (puVar8 == (undefined8 *)0x0) {
LAB_14000693e:
    uVar4 = 0x8000001a;
  }
  else {
    do {
      if (*(char *)(puVar8 + 4) != '\0') {
        WppTraceIndent(pcVar9,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_ssq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
        }
        pcVar9 = pcStack_40;
        iVar5 = strncmp(pcStack_40,(char *)(puVar8 + 4),0x60);
        if (iVar5 == 0) break;
      }
      puVar8 = (undefined8 *)puVar8[0x11];
    } while (puVar8 != (undefined8 *)0x0);
    puVar1 = local_res18;
    if (puVar8 == (undefined8 *)0x0) goto LAB_14000693e;
    param_4 = 0x315;
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*puVar8,0,0x315,"ds\\security\\scard\\scpnp\\filter\\scrawpdo.c");
    *puVar1 = puVar8;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x58));
LAB_140006968:
  pcVar9 = pcStack_40;
  if (pcStack_40 != (char *)0x0) {
    ExFreePoolWithTag(pcStack_40,0x32504353);
  }
  WppTraceIndent(pcVar9,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar4);
  }
  return uVar4;
}



===== WdfScFilter_IsDeviceNodePresentInChildList @ 1400069e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte WdfScFilter_IsDeviceNodePresentInChildList
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 *_Dst;
  undefined *puVar2;
  byte bVar3;
  undefined1 auStack_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 *puStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98 [28];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  local_a8 = 0;
  bVar3 = 0;
  local_d0 = local_d0 & 0xffffffff00000000;
  local_f8 = 0;
  _Dst = local_98;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_f0 = 0;
  puStack_e8 = (undefined4 *)0x0;
  local_e0 = 0;
  uStack_d8 = 0;
  memset(_Dst,0,0x70);
  WppTraceIndent(_Dst,(longlong *)0x0);
  puVar2 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar2,0x65,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_1 == 0) {
    WppTraceIndent(puVar2,(longlong *)0x2);
    uVar1 = 0xc000000d;
    puVar2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_s(puVar2,0x66,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
    }
  }
  else {
    local_c8 = 0x100000028;
    local_f0 = 0x28;
    puStack_e8 = local_98;
    local_d0 = 0;
    uStack_c0 = 0;
    local_b8 = 0;
    local_98[0] = 0x70;
    uStack_b0 = 0;
    local_a8 = 0;
    local_e0 = 0;
    uStack_d8 = 0;
    (**(code **)(WdfFunctions_01015 + 0x30))(WdfDriverGlobals,param_1,&local_c8);
    param_4 = &local_f8;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x38))(WdfDriverGlobals,param_1,&local_c8);
    puVar2 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x40))(WdfDriverGlobals,param_1,&local_c8);
    bVar3 = (byte)((uint)uVar1 >> 0x1f) ^ 1;
  }
  WppTraceIndent(puVar2,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar1);
  }
  return bVar3;
}



===== WdfScFilter_RemoveChildNodeByReaderName @ 140006bec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfScFilter_RemoveChildNodeByReaderName
              (undefined8 param_1,char *param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *_Dst;
  undefined *puVar3;
  undefined1 auStack_128 [32];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 *puStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  ulonglong local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98;
  char local_94 [108];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  local_f8 = 0;
  local_a8 = 0;
  local_d0 = local_d0 & 0xffffffff00000000;
  _Dst = &local_98;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_f0 = 0;
  puStack_e8 = (undefined4 *)0x0;
  local_e0 = 0;
  uStack_d8 = 0;
  memset(_Dst,0,0x70);
  WppTraceIndent(_Dst,(longlong *)0x0);
  puVar3 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar3,0x37,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_2 == (char *)0x0) {
    iVar1 = -0x3ffffff3;
    WppTraceIndent(puVar3,(longlong *)0x2);
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_s(puVar3,0x38,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
    }
  }
  else {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,param_1);
    local_c8 = 0x500000028;
    uStack_c0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_a8 = 0;
    (**(code **)(WdfFunctions_01015 + 0x30))(WdfDriverGlobals,uVar2,&local_c8);
    do {
      do {
        puStack_e8 = &local_98;
        local_d0 = 0;
        local_f0 = 0x28;
        local_e0 = 0;
        uStack_d8 = 0;
        memset(local_94,0,0x6c);
        local_98 = 0x70;
        param_4 = &local_f8;
        puVar3 = WdfDriverGlobals;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x38))(WdfDriverGlobals,uVar2,&local_c8);
        if (iVar1 == -0x7fffffe6) {
          iVar1 = 0;
LAB_140006ea1:
          puVar3 = WdfDriverGlobals;
          (**(code **)(WdfFunctions_01015 + 0x40))(WdfDriverGlobals,uVar2,&local_c8);
          goto LAB_140006ec0;
        }
        if (iVar1 < 0) {
          WppTraceIndent(puVar3,(longlong *)0x2);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                      &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)iVar1);
          }
          goto LAB_140006ea1;
        }
        iVar1 = strncmp(param_2,local_94,0x60);
      } while (iVar1 != 0);
      puVar3 = WdfDriverGlobals;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x50))(WdfDriverGlobals,uVar2,&local_98);
    } while (-1 < iVar1);
    WppTraceIndent(puVar3,(longlong *)0x2);
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sl(puVar3,0x3a,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)iVar1);
    }
  }
LAB_140006ec0:
  WppTraceIndent(puVar3,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)iVar1);
  }
  return iVar1;
}



===== RtlStringLengthWorkerW @ 140006f28 =====

uint RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  do {
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
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



===== FxStubDriverUnloadCommon @ 140006f6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000a128 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14000a128 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_140006fc5:
      if (ppvVar1 == (void **)0x0) goto LAB_14000701b;
      if (ppvVar2 <= ppvVar1) goto LAB_140007033;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_140006fc5;
LAB_14000701b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_140007033:
  WdfVersionUnbind(&DAT_14000a5d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140007070 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400070a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14000a5d0 = 0x2080000;
    _DAT_14000a5d8 = &DAT_14000a3c0;
    RtlCopyUnicodeString(&DAT_14000a5d0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000a5d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000a5c8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000a5d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000a128 != &__KMDF_CLASS_BIND_START) {
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
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 140007230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000a5c8 != (code *)0x0) && (DAT_14000a5c8 != FxStubDriverUnload)) {
    (*DAT_14000a5c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140007264 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140007289) */
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
    if ((void **)0x14000a11f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000a128 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1400073ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140007409) */
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
    if ((void **)0x14000a13f < ppvVar2) break;
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



===== __security_check_cookie @ 1400074c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007500 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007530 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007560 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1400075c0 =====

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



===== __memset_repmovs @ 140007700 =====

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



===== __memset_query @ 140007780 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007800 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007940 =====

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



===== __memset_spec_plain @ 1400079c0 =====

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



===== memcpy @ 140007b00 =====

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



===== WdfScFilter_EvtDeviceAdd @ 14000d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WdfScFilter_EvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined2 uVar7;
  undefined *puVar8;
  ulonglong uVar9;
  undefined **ppuVar10;
  undefined8 local_res10;
  undefined *local_res18;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined *local_168;
  undefined8 uStack_160;
  ulonglong local_158;
  undefined4 local_150;
  undefined4 local_14c;
  code *local_148;
  code *local_140;
  undefined8 local_138;
  undefined4 local_130;
  undefined4 local_12c;
  ulonglong local_128 [6];
  undefined *local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  code *local_d8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7b;
  code *local_60;
  undefined4 local_38;
  
  puVar5 = &local_88;
  local_res18 = (undefined *)0x0;
  local_128[0] = (ulonglong)(uint)local_128[0];
  local_188 = 0;
  uStack_180 = 0;
  local_158 = local_158 & 0xffffffff00000000;
  local_178 = 0;
  uStack_170 = 0;
  local_168 = (undefined *)0x0;
  uStack_160 = 0;
  local_res10 = param_2;
  memset(puVar5,0,0x60);
  local_14c = 0;
  WppTraceIndent(puVar5,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals,local_res10);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_res10,0x2a);
  memset(&local_e8,0,0x60);
  local_d8 = WdfScFilter_EvtDeviceListCreateSmartCardDeviceNode;
  local_e8 = 0x60;
  local_c0 = WdfScFilter_EvtChildListIdentificationDescriptionDuplicate;
  local_b0 = WdfScFilter_EvtChildListIdentificationDescriptionCompare;
  local_b8 = WdfScFilter_EvtChildListIdentificationDescriptionCleanup;
  local_e4 = 0x70;
  (**(code **)(WdfFunctions_01015 + 0x410))(WdfDriverGlobals,local_res10,&local_e8,0);
  local_138 = 0;
  local_f8 = PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018;
  local_148 = WdfScFilter_EvtDeviceFileCreate;
  local_128[2] = 0;
  local_140 = WdfScFilter_EvtFileClose;
  local_128[1] = 0;
  local_128[0] = 0x38;
  local_128[4] = 0;
  local_128[5] = 0;
  local_128[3] = 0x100000001;
  local_150 = 0x28;
  local_12c = 4;
  local_130 = 2;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_150,0);
  ppuVar10 = &local_res18;
  uVar3 = WdfDriverGlobals;
  uVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_res10,local_128);
  uVar9 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    WppTraceIndent(uVar3,(longlong *)0x2);
    puVar6 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000d40f;
    uVar7 = 0x10;
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res18,
                        PTR__WDF_SC_FILTER_DEVICE_CONTEXT_TYPE_INFO_14000a018);
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,local_res18);
    *puVar2 = uVar3;
    local_158 = 0;
    local_178 = 0;
    uStack_160 = 0;
    local_168 = local_res18;
    uStack_180 = 0;
    local_188 = 0x38;
    uStack_170 = 0x100000001;
    uVar3 = WdfDriverGlobals;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_188,puVar2 + 0xb);
    uVar9 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      WppTraceIndent(uVar3,(longlong *)0x2);
      puVar6 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14000d40f;
      uVar7 = 0x11;
    }
    else {
      puVar2[9] = 0;
      local_38 = 0xffffffff;
      puVar5 = &local_88;
      ppuVar10 = (undefined **)0x0;
      local_60 = WdfScFilter_EvtIoDeviceControl;
      local_88 = 0x60;
      local_80 = 2;
      local_7b = 1;
      local_84 = 2;
      uVar3 = WdfDriverGlobals;
      puVar8 = local_res18;
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))();
      uVar9 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        WppTraceIndent(uVar3,(longlong *)0x2);
        puVar6 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000d40f;
        uVar7 = 0x12;
      }
      else {
        ulInstanceNo._0_4_ = (int)ulInstanceNo + 1;
        puVar6 = local_res18;
        uVar4 = WdfScFilter_CreateRawPdo(local_res18,puVar8,puVar5,(ushort *)ppuVar10);
        uVar9 = uVar4 & 0xffffffff;
        if (-1 < (int)uVar4) goto LAB_14000d40f;
        WppTraceIndent(puVar6,(longlong *)0x2);
        puVar6 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000d40f;
        uVar7 = 0x13;
      }
    }
  }
  puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
  WPP_SF_sl(puVar6,uVar7,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,ppuVar10,(char)uVar9);
LAB_14000d40f:
  WppTraceIndent(puVar6,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,ppuVar10,(char)uVar9);
  }
  return uVar9;
}



===== WdfScFilter_EvtDriverUnload @ 14000d470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdfScFilter_EvtDriverUnload
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar1 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar1,0x15,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  WppTraceIndent(puVar1,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  uVar2 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
  WppTraceIndent(uVar2,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,param_4,0);
  }
  return;
}



===== WppCleanupKm @ 14000d564 =====

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



===== WppInitKm @ 14000d5e4 =====

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



===== WppLoadTracingSupport @ 14000d674 =====

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



===== WppTraceCallback @ 14000d7c0 =====

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



===== WdfScFilter_CreateDeviceNode @ 14000da48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WdfScFilter_CreateDeviceNode
              (longlong param_1,longlong param_2,longlong param_3,longlong *param_4,longlong param_5
              ,longlong *param_6,longlong param_7,longlong *param_8)

{
  longlong lVar1;
  int iVar2;
  undefined *puVar3;
  undefined2 uVar4;
  longlong *plVar5;
  longlong local_res8;
  longlong local_28 [2];
  
  local_28[0] = 0;
  plVar5 = param_4;
  local_res8 = param_1;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar3 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar3,10,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if ((((local_res8 == 0) || (param_8 == (longlong *)0x0)) ||
      ((param_2 == 0 || ((param_5 == 0 || (param_6 == (longlong *)0x0)))))) ||
     (param_4 == (longlong *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    *param_8 = 0;
    if ((param_7 == 0) ||
       (puVar3 = WdfDriverGlobals, iVar2 = (**(code **)(WdfFunctions_01015 + 0x220))(), -1 < iVar2))
    {
      puVar3 = WdfDriverGlobals;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_res8,param_2);
      if (iVar2 < 0) {
        WppTraceIndent(puVar3,(longlong *)0x2);
        puVar3 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0xc;
          goto LAB_14000db5c;
        }
      }
      else {
        puVar3 = WdfDriverGlobals;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_res8,param_2);
        if (iVar2 < 0) {
          WppTraceIndent(puVar3,(longlong *)0x2);
          puVar3 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0xd;
            goto LAB_14000db5c;
          }
        }
        else if ((param_3 == 0) ||
                (puVar3 = WdfDriverGlobals,
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x6b8))
                                  (WdfDriverGlobals,local_res8,param_3), -1 < iVar2)) {
          puVar3 = WdfDriverGlobals;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_res8,param_4);
          if (iVar2 < 0) {
            WppTraceIndent(puVar3,(longlong *)0x2);
            puVar3 = WPP_GLOBAL_Control;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar4 = 0xf;
              goto LAB_14000db5c;
            }
          }
          else {
            puVar3 = WdfDriverGlobals;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x6c0))
                              (WdfDriverGlobals,local_res8,param_5,param_6,0x409);
            if (iVar2 < 0) {
              WppTraceIndent(puVar3,(longlong *)0x2);
              puVar3 = WPP_GLOBAL_Control;
              plVar5 = param_6;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar4 = 0x10;
                goto LAB_14000db5c;
              }
            }
            else {
              (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_res8,0x409);
              plVar5 = local_28;
              puVar3 = WdfDriverGlobals;
              iVar2 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_res8,0);
              lVar1 = local_28[0];
              if (-1 < iVar2) {
                local_28[0] = 0;
                *param_8 = lVar1;
                goto LAB_14000de4c;
              }
              WppTraceIndent(puVar3,(longlong *)0x2);
              puVar3 = WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar4 = 0x11;
                goto LAB_14000db5c;
              }
            }
          }
        }
        else {
          WppTraceIndent(puVar3,(longlong *)0x2);
          puVar3 = WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            uVar4 = 0xe;
            goto LAB_14000db5c;
          }
        }
      }
    }
    else {
      WppTraceIndent(puVar3,(longlong *)0x2);
      puVar3 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar4 = 0xb;
LAB_14000db5c:
        puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_sl(puVar3,uVar4,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,plVar5,(char)iVar2);
      }
    }
  }
  if (local_28[0] != 0) {
    puVar3 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x680))();
  }
LAB_14000de4c:
  WppTraceIndent(puVar3,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,plVar5,(char)iVar2);
  }
  return iVar2;
}



===== WdfScFilter_CreateRawPdo @ 14000deac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WdfScFilter_CreateRawPdo
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 *_Dst;
  undefined *puVar5;
  ushort *puVar6;
  longlong lVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 auStackY_468 [32];
  longlong local_428;
  ushort local_420 [4];
  undefined1 *local_418;
  ushort local_410 [4];
  undefined1 *local_408;
  undefined8 local_400;
  wchar_t *local_3f8;
  longlong local_3f0;
  wchar_t *local_3e8;
  undefined8 local_3e0;
  wchar_t *local_3d8;
  undefined8 local_3d0;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined1 local_3bb;
  code *local_3a0;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined4 uStack_330;
  undefined4 uStack_32c;
  undefined4 local_328;
  undefined4 uStack_324;
  undefined4 local_320;
  wchar_t local_318 [16];
  wchar_t local_2f8 [56];
  wchar_t local_288 [40];
  undefined1 local_238 [256];
  undefined1 local_138 [256];
  ulonglong local_38;
  
  uVar2 = (uint)ulInstanceNo;
  local_38 = __security_cookie ^ (ulonglong)auStackY_468;
  local_428 = 0;
  _Dst = &local_3c8;
  lVar10 = 0;
  memset(_Dst,0,0x60);
  builtin_wcsncpy(local_2f8,L"{892EDE5E-BE49-443c-A0B3-005D74F2D69C}\\ScFilter",0x30);
  local_368 = 0;
  uStack_360 = 0;
  local_328 = 0;
  uStack_324 = 0;
  local_358 = 0;
  uStack_350 = 0;
  local_320 = 0;
  local_348 = 0;
  uStack_340 = 0;
  local_2f8[0x30] = 0;
  local_3d8 = local_2f8;
  local_338 = 0;
  uStack_330 = 0;
  uStack_32c = 0;
  builtin_wcsncpy(local_318,L"ScFilter",9);
  local_318[9] = L'\0';
  local_3e8 = local_318;
  local_408 = local_238;
  builtin_wcsncpy(local_288,L"D:P(A;;GA;;;SY)(A;;GA;;;BA)(A;;G",0x20);
  local_418 = local_138;
  local_3f8 = local_288;
  builtin_wcsncpy(local_288 + 0x20,L"A;;;LS)",8);
  local_3d0 = 0;
  local_3e0 = 0x620060;
  local_3f0 = 0x140012;
  local_410[0] = 0;
  local_410[1] = 0x100;
  local_410[2] = 0;
  local_410[3] = 0;
  local_420[0] = 0;
  local_420[1] = 0x100;
  local_420[2] = 0;
  local_420[3] = 0;
  local_400 = 0x50004e;
  WppTraceIndent(_Dst,(longlong *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  puVar5 = WdfDriverGlobals;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals,param_1);
  if (lVar3 == 0) {
    uVar9 = 0xc000009a;
    goto LAB_14000e4d1;
  }
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,lVar3,0x2a);
  puVar5 = WdfDriverGlobals;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x6d0))
                    (WdfDriverGlobals,lVar3,&GUID_DEVCLASS_SMARTCARDREADER);
  uVar9 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    WppTraceIndent(puVar5,(longlong *)0x2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar8 = 0x14;
LAB_14000e140:
      WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar9);
    }
LAB_14000e291:
    puVar5 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals,lVar3);
  }
  else {
    puVar6 = local_410;
    uVar4 = RtlUnicodeStringPrintf(puVar6,L"%02d",(ulonglong)uVar2,param_4);
    uVar9 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      WppTraceIndent(puVar6,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar8 = 0x15;
        goto LAB_14000e140;
      }
      goto LAB_14000e291;
    }
    puVar6 = local_420;
    uVar4 = RtlUnicodeStringPrintf(puVar6,L"Sc_Filter_%02d",(ulonglong)uVar2,param_4);
    uVar9 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      WppTraceIndent(puVar6,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar8 = 0x16;
        goto LAB_14000e140;
      }
      goto LAB_14000e291;
    }
    param_4 = local_410;
    lVar7 = lVar3;
    uVar1 = WdfScFilter_CreateDeviceNode
                      (lVar3,(longlong)&local_3e0,0,(longlong *)param_4,(longlong)local_420,
                       &local_3f0,(longlong)&local_400,&local_428);
    lVar10 = local_428;
    uVar9 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      WppTraceIndent(lVar7,(longlong *)0x2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                  &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar1);
      }
      lVar10 = local_428;
      goto LAB_14000e291;
    }
    local_3a0 = WdfScFilter_EvtIoDeviceControlForRawPdo;
    local_3c8 = 0x60;
    param_4 = (ushort *)0x0;
    local_3c0 = 2;
    local_3bb = 1;
    local_3c4 = 1;
    puVar5 = WdfDriverGlobals;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_428,&local_3c8);
    uVar9 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      WppTraceIndent(puVar5,(longlong *)0x2);
      puVar5 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar8 = 0x18;
LAB_14000e343:
        puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_sl(puVar5,uVar8,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar9)
        ;
      }
    }
    else {
      local_368 = 0x200000030;
      uStack_360 = 2;
      local_358 = 0x200000002;
      uStack_350 = 0x100000002;
      local_348 = 0x100000002;
      uStack_340 = CONCAT44(uVar2,uVar2);
      (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,lVar10,&local_368);
      local_338 = 0x20000001c;
      uStack_32c = 2;
      local_328 = 2;
      uStack_324 = 2;
      local_320 = 2;
      uStack_330 = 1;
      (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,lVar10,&local_338);
      param_4 = (ushort *)0x0;
      puVar5 = WdfDriverGlobals;
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                        (WdfDriverGlobals,lVar10,&GUID_DEVINTERFACE_SCFILTER);
      uVar9 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        WppTraceIndent(puVar5,(longlong *)0x2);
        puVar5 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x19;
          goto LAB_14000e343;
        }
      }
      else {
        puVar5 = WdfDriverGlobals;
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals,param_1,lVar10);
        uVar9 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          WppTraceIndent(puVar5,(longlong *)0x2);
          puVar5 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x1a;
            goto LAB_14000e343;
          }
        }
        else {
          lVar10 = 0;
        }
      }
    }
  }
  if (lVar10 != 0) {
    puVar5 = WdfDriverGlobals;
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar10);
  }
LAB_14000e4d1:
  WppTraceIndent(puVar5,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar9);
  }
  return uVar9;
}



===== WdfScFilter_EvtDeviceListCreateSmartCardDeviceNode @ 14000e550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong WdfScFilter_EvtDeviceListCreateSmartCardDeviceNode
                    (undefined8 param_1,longlong param_2,longlong param_3,ushort *param_4)

{
  short sVar1;
  ushort *puVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  undefined2 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ushort *puVar12;
  undefined1 auStackY_5f8 [32];
  undefined1 uVar13;
  ushort local_5b8 [4];
  undefined1 *local_5b0;
  longlong local_5a8;
  longlong local_5a0;
  ushort local_598 [4];
  undefined1 *local_590;
  ushort local_588 [4];
  undefined1 *local_580;
  ushort local_578 [4];
  undefined1 *local_570;
  longlong local_568;
  wchar_t *local_560;
  undefined8 local_558;
  undefined8 uStack_550;
  undefined8 local_548;
  ulonglong uStack_540;
  undefined8 local_538;
  undefined8 uStack_530;
  wchar_t local_528 [16];
  undefined1 local_508 [256];
  undefined1 local_408 [256];
  undefined1 local_308 [256];
  undefined1 local_208 [448];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_5f8;
  local_578[0] = 0;
  local_578[1] = 0x100;
  local_578[2] = 0;
  local_578[3] = 0;
  local_598[0] = 0;
  local_598[1] = 0x100;
  local_598[2] = 0;
  local_598[3] = 0;
  local_570 = local_508;
  local_5a8 = 0;
  local_590 = local_408;
  local_5a0 = 0;
  builtin_wcsncpy(local_528,L"ScFilter",9);
  local_528[9] = L'\0';
  uVar11 = 0;
  local_560 = local_528;
  local_568 = 0x140012;
  local_5b0 = local_208;
  local_558 = 0;
  uStack_550 = 0;
  local_580 = local_308;
  local_548 = 0;
  uStack_540 = 0;
  local_538 = 0;
  uStack_530 = 0;
  local_5b8[0] = 0;
  local_5b8[1] = 0x1c0;
  local_5b8[2] = 0;
  local_5b8[3] = 0;
  local_588[0] = 0;
  local_588[1] = 0x100;
  local_588[2] = 0;
  local_588[3] = 0;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar6 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar6,0x2c,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
  }
  if (param_2 == 0) {
    WppTraceIndent(puVar6,(longlong *)0x2);
    uVar10 = 0xc000000d;
    puVar7 = (ushort *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000eab5;
    uVar9 = 0x2d;
  }
  else {
    puVar2 = *(ushort **)(param_2 + 0x68);
    if (puVar2 != (ushort *)0x0) {
      puVar7 = local_578;
      uVar5 = RtlUnicodeStringPrintf(puVar7,L"%s",puVar2,param_4);
      uVar10 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) {
        WppTraceIndent(puVar7,(longlong *)0x2);
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            (uVar4 = *(uint *)(WPP_GLOBAL_Control + 0x2c), puVar7 = (ushort *)(ulonglong)uVar4,
            (uVar4 & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
        puVar7 = *(ushort **)(WPP_GLOBAL_Control + 0x18);
        uVar9 = 0x2f;
        uVar13 = (undefined1)uVar5;
      }
      else {
        puVar8 = puVar2 + 0x80;
        if (puVar8 == (ushort *)0x0) {
          uVar10 = 0xc000000d;
          uVar4 = 0xc000000d;
LAB_14000ea77:
          WppTraceIndent(puVar7,(longlong *)0x2);
          puVar7 = (ushort *)WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
          uVar9 = 0x30;
          uVar11 = (ulonglong)uVar4;
        }
        else {
          puVar12 = puVar8;
          uVar4 = RtlStringLengthWorkerW((short *)puVar8,0x80,&local_5a0);
          uVar10 = (ulonglong)uVar4;
          puVar7 = puVar8;
          if ((int)uVar4 < 0) goto LAB_14000ea77;
          if (local_5a0 == 0) {
            bVar3 = 0;
LAB_14000e801:
            puVar7 = local_588;
            uVar5 = RtlUnicodeStringPrintf(puVar7,L"%s",puVar2 + 0x100,param_4);
            uVar10 = uVar5 & 0xffffffff;
            if ((int)uVar5 < 0) {
              WppTraceIndent(puVar7,(longlong *)0x2);
              puVar7 = (ushort *)WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
              uVar9 = 0x32;
            }
            else {
              puVar7 = local_5b8;
              param_4 = puVar2;
              uVar5 = RtlUnicodeStringPrintf(puVar7,L"%S_%s",param_2 + 4,puVar2);
              uVar10 = uVar5 & 0xffffffff;
              if ((int)uVar5 < 0) {
                WppTraceIndent(puVar7,(longlong *)0x2);
                puVar7 = (ushort *)WPP_GLOBAL_Control;
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
                uVar9 = 0x33;
              }
              else {
                if (local_5b8[0] != 0) {
                  do {
                    sVar1 = *(short *)(local_5b0 + uVar11 * 2);
                    if (sVar1 == 0) break;
                    if ((sVar1 == 0x5c) || (sVar1 == 0x2c)) {
                      *(undefined2 *)(local_5b0 + uVar11 * 2) = 0x5f;
                    }
                    uVar4 = (int)uVar11 + 1;
                    uVar11 = (ulonglong)uVar4;
                  } while (uVar4 < local_5b8[0]);
                }
                param_4 = local_5b8;
                uVar4 = WdfScFilter_CreateDeviceNode
                                  (param_3,(longlong)local_578,
                                   -(ulonglong)bVar3 & (ulonglong)local_598,(longlong *)param_4,
                                   (longlong)local_588,&local_568,0,&local_5a8);
                uVar10 = (ulonglong)uVar4;
                if ((int)uVar4 < 0) {
                  WppTraceIndent(param_3,(longlong *)0x2);
                  puVar7 = (ushort *)WPP_GLOBAL_Control;
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
                  uVar9 = 0x34;
                }
                else {
                  uStack_530 = 0xffffffffffffffff;
                  local_558 = 0x200000030;
                  local_548 = 0x200000002;
                  uStack_550 = CONCAT44((uint)((char)puVar2[0x1e0] != '\0'),2);
                  local_538 = CONCAT44((uint)(*(char *)((longlong)puVar2 + 0x3c3) != '\0'),2);
                  uStack_540 = (ulonglong)
                               CONCAT14(*(char *)((longlong)puVar2 + 0x3c1) != '\0',
                                        (uint)((char)puVar2[0x1e1] != '\0'));
                  (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_5a8,&local_558);
                  param_4 = (ushort *)0x0;
                  puVar7 = WdfDriverGlobals;
                  uVar4 = (**(code **)(WdfFunctions_01015 + 0x268))
                                    (WdfDriverGlobals,local_5a8,&GUID_DEVINTERFACE_SMARTCARD);
                  uVar10 = (ulonglong)uVar4;
                  if ((((-1 < (int)uVar4) ||
                       (WppTraceIndent(puVar7,(longlong *)0x2),
                       puVar7 = (ushort *)WPP_GLOBAL_Control,
                       (undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
                  uVar9 = 0x35;
                }
              }
            }
          }
          else {
            puVar7 = local_598;
            bVar3 = 1;
            uVar5 = RtlUnicodeStringPrintf(puVar7,L"%s",puVar12,param_4);
            uVar10 = uVar5 & 0xffffffff;
            if (-1 < (int)uVar5) goto LAB_14000e801;
            WppTraceIndent(puVar7,(longlong *)0x2);
            puVar7 = (ushort *)WPP_GLOBAL_Control;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000eab5;
            uVar9 = 0x31;
          }
          uVar11 = uVar10;
        }
        uVar13 = (undefined1)uVar11;
        puVar7 = *(ushort **)(WPP_GLOBAL_Control + 0x18);
      }
      WPP_SF_sl(puVar7,uVar9,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,uVar13);
      goto LAB_14000eab5;
    }
    WppTraceIndent(puVar6,(longlong *)0x2);
    uVar10 = 0xc000000d;
    puVar7 = (ushort *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000eab5;
    uVar9 = 0x2e;
  }
  uVar10 = 0xc000000d;
  puVar7 = *(ushort **)(WPP_GLOBAL_Control + 0x18);
  WPP_SF_s(puVar7,uVar9,&WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids);
LAB_14000eab5:
  WppTraceIndent(puVar7,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
              &WPP_cff18c79dff73d1e5b3f47d31f5f8cdd_Traceguids,param_4,(char)uVar10);
  }
  return uVar10;
}



===== __security_init_cookie @ 14000f008 =====

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



===== DriverEntry @ 14000f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  ulonglong local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  local_28 = (ulonglong)(uint)local_28;
  WppTraceIndent(param_1,(longlong *)0x0);
  puVar2 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_s(puVar2,10,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  _DAT_14000a608 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14000a5e8 = &WPP_ThisDir_CTLGUID_ScFilterControlGuid;
  DAT_14000a5f0 = 0;
  _DAT_14000a600 = 0;
  WppLoadTracingSupport();
  _DAT_14000a600 = 0;
  WppInitKm();
  WppTraceIndent(puVar2,(longlong *)0x2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids);
  }
  local_28 = 0x20;
  local_20 = WdfScFilter_EvtDeviceAdd;
  local_10 = 0;
  local_18 = WdfScFilter_EvtDriverUnload;
  uVar3 = 0;
  puVar2 = WdfDriverGlobals;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_28,0);
  uVar4 = (undefined1)iVar1;
  if (iVar1 < 0) {
    WppTraceIndent(puVar2,(longlong *)0x2);
    puVar2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sl(puVar2,0xc,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar3,uVar4);
    }
    WppTraceIndent(puVar2,(longlong *)0x2);
    puVar2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_sl(puVar2,0xd,&WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar3,uVar4);
    }
    WppCleanupKm();
  }
  WppTraceIndent(puVar2,(longlong *)0x1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_5f2391a1d35e3afd6f60870017f92c7e_Traceguids,uVar3,uVar4);
  }
  return iVar1;
}


