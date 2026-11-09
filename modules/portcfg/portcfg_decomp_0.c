
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



===== _vsnwprintf @ 1c0001020 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 1c0001040 =====

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



===== _flsbuf @ 1c0001138 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 1c0001148 =====

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
LAB_1c0001a0c:
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
LAB_1c00018e0:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_1c000178e:
          iVar6 = local_4a8;
LAB_1c0001796:
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
LAB_1c0001831:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_1c00018b4;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_1c00018b4:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_1c00017a0;
                  }
                  local_494 = 0;
                  goto LAB_1c00018e0;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_1c00018b4;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_1c0001831;
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
              if (uVar11 == 0x74) goto LAB_1c0001831;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_1c0001831;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_1c00012d9:
              uVar16 = uVar16 | 0x40;
LAB_1c00012dc:
              uVar19 = 10;
              goto LAB_1c00012e7;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_1c0001410:
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
LAB_1c0001399:
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
              if (uVar11 == 0x58) goto LAB_1c00014ea;
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
                  if (puVar3[1] < uVar2) goto LAB_1c0001a0c;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_1c0001a0c;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_1c0001410;
                if (uVar11 == 100) goto LAB_1c00012d9;
              }
            }
LAB_1c0001626:
            if (local_478 != 0) goto LAB_1c0001796;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_1c0001674;
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
LAB_1c0001674:
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
                  goto LAB_1c000176a;
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
LAB_1c000176a:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_1c000178e;
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
LAB_1c00014ea:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_1c0001399;
                  if (wVar18 == L'u') goto LAB_1c00012dc;
                  if (wVar18 != L'x') goto LAB_1c0001626;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_1c00012e7:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_1c0001561;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1c0001561:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_1c0001561;
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
              goto LAB_1c0001626;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_1c0001a0c;
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
LAB_1c00017a0:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 1c0001a54 =====

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



===== write_multi_char @ 1c0001aa8 =====

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



===== write_string @ 1c0001b00 =====

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



===== _guard_check_icall @ 1c0001b80 =====

void _guard_check_icall(void)

{
  return;
}



===== _get_printf_count_output @ 1c0001b8c =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_1c0005140 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 1c0001bac =====

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



===== mbtowc @ 1c0001bf8 =====

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



===== __GSHandlerCheck @ 1c0001c4c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001c70 =====

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



===== _flswbuf @ 1c0001cd8 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 1c0001cf0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001d5a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001d09) */
/* WARNING: Removing unreachable block (ram,0x0001c0001cfa) */

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



===== RtlAnsiCharToUnicodeChar @ 1c0001db6 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001db6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== RtlUnicodeStringPrintf @ 1c0001dc8 =====

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



===== RtlStringCopyWorkerW @ 1c0001e64 =====

uint RtlStringCopyWorkerW
               (short *param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               longlong param_5)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = param_4 - (longlong)param_1;
  lVar3 = 0x10;
  do {
    if ((param_5 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
    *param_1 = sVar1;
    param_5 = param_5 + -1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  psVar2 = param_1 + -1;
  if (lVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== RtlStringValidateDestW @ 1c0001ec0 =====

undefined8 RtlStringValidateDestW(void)

{
  return 0;
}



===== FxStubDriverUnloadCommon @ 1c0001ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005118 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0005118 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0001f25:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0001f7b;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0001f93;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0001f25;
LAB_1c0001f7b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0001f93:
  WdfVersionUnbind(&DAT_1c0005370,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0001fd0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0002004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c0005370 = 0x2080000;
    _DAT_1c0005378 = &DAT_1c0005160;
    RtlCopyUnicodeString(&DAT_1c0005370);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_1c0005370,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar1 = DriverEntry(param_1,param_2);
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0005368 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar1,&DAT_1c0005370);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005118 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0002190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0005368 != (code *)0x0) && (DAT_1c0005368 != FxStubDriverUnload)) {
    (*DAT_1c0005368)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c00021c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00021e9) */
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
    if ((void **)0x1c000510f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0005118 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000234c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002369) */
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
    if ((void **)0x1c000512f < ppvVar2) break;
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



===== __security_check_cookie @ 1c0002420 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002460 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002490 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00024c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0002540 =====

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



===== __memset_repmovs @ 1c0002680 =====

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



===== __memset_query @ 1c0002700 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002780 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00028c0 =====

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



===== __memset_spec_plain @ 1c0002940 =====

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



===== memcpy @ 1c0002a80 =====

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



===== PortCfgAddDevice @ 1c0008010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PortCfgAddDevice(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res10;
  ulonglong local_res18 [2];
  ulonglong local_48 [6];
  undefined *local_18;
  
  local_res18[0] = 0;
  local_48[0] = (ulonglong)(uint)local_48[0];
  local_res10 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals);
  local_48[2] = 0;
  local_48[3] = 0x100000001;
  local_18 = PTR__WDF_PORTCFG_FILTER_EXTENSION_TYPE_INFO_1c0005018;
  local_48[1] = 0;
  local_48[0] = 0x38;
  local_48[4] = 0;
  local_48[5] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,local_48,local_res18);
  if (-1 < iVar1) {
    PortCfgConfigureDevice(local_res18[0]);
  }
  return;
}



===== PortCfgConfigureDevice @ 1c00080ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PortCfgConfigureDevice(ulonglong param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined1 auStack_d8 [32];
  ushort *local_b8;
  uint *local_b0;
  uint *local_a8;
  int *local_a0;
  byte local_98 [4];
  uint local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  undefined2 local_84 [2];
  uint local_80 [2];
  longlong local_78;
  ushort local_70 [4];
  undefined1 *puStack_68;
  longlong local_60 [3];
  undefined1 local_48 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  pbVar3 = (byte *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_PORTCFG_FILTER_EXTENSION_TYPE_INFO_1c0005018);
  local_b0 = (uint *)&local_78;
  local_78 = 0;
  local_60[0] = 0;
  local_98[0] = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  puStack_68 = (undefined1 *)0x0;
  local_90 = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_94 = 0;
  local_84[0] = 0;
  local_8c = 0;
  local_88 = 0;
  local_80[0] = 0;
  local_b8 = (ushort *)0x0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,param_1,1,0x2001f);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) goto LAB_1c000858a;
  RtlInitUnicodeString(local_60 + 1,L"PortName");
  puStack_68 = local_48;
  local_b8 = local_70;
  local_70[0] = 0;
  local_70[1] = 0x20;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x770))(WdfDriverGlobals,local_78,local_60 + 1,local_84)
  ;
  if (iVar1 < 0) {
    local_b0 = (uint *)local_60;
    local_b8 = (ushort *)0x0;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,param_1,2,0x20019);
    uVar4 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_1c000858a;
    RtlInitUnicodeString(local_60 + 1,L"PortSubClassOther");
    local_a8 = &local_90;
    local_b0 = &local_94;
    local_b8 = (ushort *)local_98;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,local_60[0],local_60 + 1,1);
    if ((((iVar1 < 0) || (local_90 != 3)) || (local_94 != 1)) || (local_98[0] == 0)) {
      RtlInitUnicodeString(local_60 + 1,L"PortSubClass");
      local_a8 = &local_90;
      local_b0 = &local_94;
      local_b8 = (ushort *)local_98;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,local_60[0],local_60 + 1,1)
      ;
      if (((iVar1 < 0) || (local_90 != 3)) || ((local_94 != 1 || (1 < local_98[0])))) {
        local_98[0] = 1;
      }
    }
    else {
      local_98[0] = 2;
    }
    *pbVar3 = local_98[0];
    if (local_98[0] == 0) {
      uVar2 = PortCfgGetParallelPortNumber(param_1,local_78,local_80);
    }
    else {
      if (local_98[0] != 1) goto LAB_1c0008587;
      uVar4 = PortCfgGetSerialPortNumber(param_1,local_78,local_80);
      uVar2 = (uint)uVar4;
    }
    uVar4 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_1c000858a;
    puStack_68 = local_48;
    *(uint *)(pbVar3 + 4) = local_80[0];
    local_70[0] = 0;
    local_70[1] = 0x20;
    uVar5 = RtlUnicodeStringPrintf
                      (local_70,L"%ws%u",(&PTR_u_LPT_1c0004000)[local_98[0]],(ulonglong)local_80[0])
    ;
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c000858a;
    RtlInitUnicodeString(local_60 + 1,L"PortName");
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7a0))(WdfDriverGlobals,local_78,local_60 + 1);
    uVar4 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_1c000858a;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    local_a0 = &local_88;
    local_a8 = &local_8c;
    local_b0 = (uint *)0x0;
    local_b8 = (ushort *)((ulonglong)local_b8 & 0xffffffff00000000);
    iVar1 = IoGetDevicePropertyData(uVar6,&DEVPKEY_Device_DriverDesc,0);
    if (((iVar1 == -0x3fffffdd) && (local_8c - 2 < 0xffdd)) && (local_88 == 0x12)) {
      local_94 = local_8c + 0x20;
      puVar7 = (uint *)ExAllocatePool2(0x100,local_94,0x67437450);
      if (puVar7 == (uint *)0x0) {
        uVar4 = 0xc000009a;
      }
      else {
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        local_a0 = &local_88;
        uVar9 = 0;
        local_a8 = &local_8c;
        local_b8 = (ushort *)CONCAT44(local_b8._4_4_,local_8c);
        local_b0 = puVar7;
        uVar2 = IoGetDevicePropertyData(uVar6,&DEVPKEY_Device_DriverDesc,0);
        uVar4 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          if (local_88 == 0x12) {
            local_70[0] = 0;
            local_70[1] = 0x20;
            puStack_68 = (undefined1 *)((longlong)puVar7 + ((ulonglong)(local_94 >> 1) - 0x11) * 2);
            uVar5 = RtlUnicodeStringPrintf(local_70,L" (%ws)",local_48,uVar9);
            uVar4 = uVar5 & 0xffffffff;
            if (-1 < (int)uVar5) {
              uVar6 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
              lVar8 = -1;
              do {
                lVar8 = lVar8 + 1;
              } while (*(short *)((longlong)puVar7 + lVar8 * 2) != 0);
              local_b0 = (uint *)CONCAT44(local_b0._4_4_,(int)lVar8 * 2 + 2);
              local_b8 = (ushort *)CONCAT44(local_b8._4_4_,0x12);
              local_a8 = puVar7;
              uVar2 = IoSetDevicePropertyData(uVar6,&DEVPKEY_Device_FriendlyName,0,0);
              uVar4 = (ulonglong)uVar2;
            }
          }
          else {
            uVar4 = 0xc0000024;
          }
        }
        ExFreePoolWithTag(puVar7,0);
      }
      goto LAB_1c000858a;
    }
  }
LAB_1c0008587:
  uVar4 = 0;
LAB_1c000858a:
  if (local_78 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_60[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return uVar4;
}



===== PortCfgGenerateParallelPortNumber @ 1c0008604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PortCfgGenerateParallelPortNumber(undefined8 param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  wchar_t *pwVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 local_58;
  undefined8 uStack_50;
  
  local_res20 = 0;
  local_res18[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar1 = false;
  uVar10 = 0;
  uVar8 = 0;
  RtlInitUnicodeString(&local_58,L"\\REGISTRY\\MACHINE\\HARDWARE\\DeviceMap\\PARALLEL PORTS");
  uVar11 = 0;
  iVar9 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,&local_58,0x20019,0,&local_res20);
  if (-1 < iVar9) {
    lVar4 = ExAllocatePool2(0x100,0x94,0x67437450);
    if (lVar4 == 0) {
      iVar9 = -0x3fffff66;
    }
    else {
      iVar9 = 0;
      iVar6 = 3;
      while( true ) {
        uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x740))(WdfDriverGlobals,local_res20);
        uVar11 = CONCAT44(uVar12,0x94);
        iVar2 = ZwEnumerateValueKey(uVar5,iVar9,1,lVar4,uVar11,local_res18);
        if (iVar2 < 0) break;
        if (((*(int *)(lVar4 + 4) == 1) && (1 < *(uint *)(lVar4 + 0xc))) &&
           (pwVar7 = (wchar_t *)((ulonglong)*(uint *)(lVar4 + 8) + lVar4),
           pwVar7[(ulonglong)(*(uint *)(lVar4 + 0xc) >> 1) - 1] == L'\0')) {
          _wcsupr(pwVar7);
          pwVar7 = wcsstr(pwVar7,L"LPT");
          if (pwVar7 != (wchar_t *)0x0) {
            uVar3 = wcstoul(pwVar7 + 3,(wchar_t **)0x0,10);
            if (uVar3 != 0) {
              if (uVar3 == 3) {
                bVar1 = true;
              }
              else if (!bVar1) goto LAB_1c00087ab;
              if (uVar10 < uVar3) {
                uVar10 = uVar3;
              }
              if (uVar3 < 4) {
                uVar8 = uVar8 | 1 << ((char)uVar3 - 1U & 0x1f);
              }
            }
          }
        }
LAB_1c00087ab:
        iVar9 = iVar9 + 1;
      }
      iVar9 = 0;
      if (iVar2 != -0x7fffffe6) {
        iVar9 = iVar2;
      }
      if (-1 < iVar9) {
        if (bVar1) {
          if (uVar8 < 7) {
            if ((uVar8 & 4) != 0) {
              iVar6 = 2 - (uint)((uVar8 & 2) != 0);
            }
          }
          else {
            iVar6 = uVar10 + 1;
          }
        }
        *param_2 = iVar6;
      }
      ExFreePoolWithTag(lVar4,0);
    }
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar9;
}



===== PortCfgGetParallelPortNumber @ 1c0008840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PortCfgGetParallelPortNumber(ulonglong param_1,undefined8 param_2,ulong *param_3)

{
  ulong uVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  undefined1 auStack_148 [32];
  int *local_128;
  wchar_t *local_120;
  uint *local_118;
  int *local_110;
  ushort local_108 [2];
  ulong local_104;
  undefined2 local_100 [2];
  uint local_fc;
  int local_f8;
  int local_f4;
  int local_f0 [4];
  wchar_t *local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  wchar_t local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  local_f0[1] = 0;
  local_f0[3] = 0;
  uVar1 = 0;
  local_f8 = 0;
  local_104 = 0;
  local_f4 = 0;
  local_100[0] = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_fc = 0;
  local_f0[0] = 0;
  local_108[0] = 0;
  RtlInitUnicodeString(&local_d8,L"DosDeviceName");
  local_e0 = local_c8;
  local_f0[2] = 0x800000;
  local_128 = local_f0 + 2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x770))(WdfDriverGlobals,param_2,&local_d8,local_100);
  if (iVar2 < 0) {
    RtlInitUnicodeString(&local_d8,L"FirmwareIdentified");
    local_118 = (uint *)&local_f8;
    local_120 = (wchar_t *)&local_f4;
    local_128 = local_f0 + 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,param_2,&local_d8,4);
    if (((iVar2 < 0) || (local_f8 != 4)) || (local_f4 != 4)) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
      local_110 = local_f0;
      local_118 = &local_fc;
      local_120 = local_c8;
      local_128 = (int *)CONCAT44(local_128._4_4_,0x80);
      iVar2 = IoGetDevicePropertyData(uVar4,&DEVPKEY_Device_EnumeratorName,0,0);
      if (((-1 < iVar2) && (local_f0[0] == 0x12)) &&
         ((2 < local_fc && (local_c8[(ulonglong)(local_fc >> 1) - 1] == L'\0')))) {
        pwVar3 = _wcsupr(local_c8);
        iVar2 = _wcsicmp(pwVar3,L"ACPI");
        uVar1 = (ulong)(iVar2 == 0);
        local_104 = uVar1;
      }
      iVar2 = 0;
      goto LAB_1c0008a8e;
    }
LAB_1c00089d6:
    uVar1 = 1;
  }
  else {
    _wcsupr(local_c8);
    pwVar3 = wcsstr(local_c8,L"LPT");
    if (pwVar3 != (wchar_t *)0x0) {
      uVar1 = wcstoul(pwVar3 + 3,(wchar_t **)0x0,10);
      local_104 = uVar1;
LAB_1c0008a8e:
      if (uVar1 != 0) goto LAB_1c0008b01;
    }
    iVar2 = PortCfgQueryResourcePortAddress(param_1,local_108);
    if (-1 < iVar2) {
      param_1 = (ulonglong)local_108[0];
      if ((ushort)(local_108[0] - 0x278) < 8) {
        uVar1 = 2;
        goto LAB_1c0008b01;
      }
      if (((ushort)(local_108[0] - 0x378) < 8) || (local_108[0] == 0x3bc)) goto LAB_1c00089d6;
    }
    iVar2 = PortCfgGenerateParallelPortNumber(param_1,(int *)&local_104);
    if (iVar2 < 0) {
      iVar2 = 0;
      uVar1 = 3;
    }
    else {
      uVar1 = local_104;
    }
  }
LAB_1c0008b01:
  *param_3 = uVar1;
  return iVar2;
}



===== PortCfgGetSerialPortNumber @ 1c0008b38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PortCfgGetSerialPortNumber(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte *pbVar8;
  ulonglong uVar9;
  longlong *plVar10;
  byte bVar11;
  undefined1 auStack_158 [32];
  int *local_138;
  wchar_t *local_130;
  uint *local_128;
  int *local_120;
  uint local_118;
  short local_114 [2];
  undefined2 local_110 [2];
  uint local_10c;
  uint local_108;
  int local_104;
  int local_100 [2];
  longlong *local_f8;
  int local_f0 [2];
  wchar_t *local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  wchar_t local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_158;
  local_100[1] = 0;
  local_f8 = (longlong *)0x0;
  uVar2 = 0;
  local_f0[1] = 0;
  local_118 = 0;
  local_108 = 0;
  local_104 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_110[0] = 0;
  local_10c = 0;
  local_100[0] = 0;
  local_114[0] = 0;
  RtlInitUnicodeString(&local_e0,L"DosDeviceName");
  local_e8 = local_c8;
  local_f0[0] = 0x800000;
  local_138 = local_f0;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x770))(WdfDriverGlobals,param_2,&local_e0,local_110);
  uVar9 = (ulonglong)uVar4;
  if ((int)uVar4 < 0) {
    RtlInitUnicodeString(&local_e0,L"FirmwareIdentified");
    local_128 = &local_108;
    local_130 = (wchar_t *)&local_104;
    local_138 = local_100 + 1;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,param_2,&local_e0,4);
    if (((-1 < iVar3) && (local_108 == 4)) && (local_104 == 4)) goto LAB_1c0008d9b;
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
    local_120 = local_100;
    local_128 = &local_10c;
    local_130 = local_c8;
    local_138 = (int *)CONCAT44(local_138._4_4_,0x80);
    iVar3 = IoGetDevicePropertyData(uVar7,&DEVPKEY_Device_EnumeratorName,0,0);
    if (((-1 < iVar3) && (local_100[0] == 0x12)) &&
       ((2 < local_10c && (local_c8[(ulonglong)(local_10c >> 1) - 1] == L'\0')))) {
      pwVar5 = _wcsupr(local_c8);
      iVar3 = _wcsicmp(pwVar5,L"ACPI");
      if (iVar3 == 0) {
        uVar9 = 0;
        goto LAB_1c0008d97;
      }
    }
LAB_1c0008e14:
    uVar9 = 0;
  }
  else {
    _wcsupr(local_c8);
    pwVar5 = wcsstr(local_c8,L"COM");
    if (pwVar5 != (wchar_t *)0x0) {
      uVar2 = wcstoul(pwVar5 + 3,(wchar_t **)0x0,10);
      local_118 = uVar2;
    }
LAB_1c0008d97:
    if (uVar2 == 0) {
LAB_1c0008d9b:
      uVar4 = PortCfgQueryResourcePortAddress(param_1,local_114);
      uVar9 = (ulonglong)uVar4;
      if ((int)uVar4 < 0) goto LAB_1c0008e14;
      if ((ushort)(local_114[0] - 0x3f8U) < 8) {
        uVar2 = 1;
      }
      else if ((ushort)(local_114[0] - 0x2f8U) < 8) {
        uVar2 = 2;
      }
      else if ((ushort)(local_114[0] - 1000U) < 8) {
        uVar2 = 3;
      }
      else {
        if (7 < (ushort)(local_114[0] - 0x2e8U)) goto LAB_1c0008e17;
        uVar2 = 4;
      }
      local_118 = uVar2;
    }
  }
LAB_1c0008e17:
  uVar6 = ComDbOpen((longlong *)&local_f8);
  plVar10 = local_f8;
  if ((int)uVar6 < 0) {
    plVar10 = (longlong *)0x0;
  }
  if (uVar2 == 0) {
    if (plVar10 == (longlong *)0x0) {
      uVar2 = 5;
    }
    else {
      uVar6 = ComDbClaimNextFreePort((longlong)plVar10,&local_118);
      uVar9 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) {
        uVar9 = 0;
        uVar2 = 5;
      }
      else {
        uVar2 = local_118;
      }
    }
  }
  else {
    if (plVar10 == (longlong *)0x0) goto LAB_1c0008edd;
    if (uVar2 < 0x1001) {
      uVar6 = ComDbAcquire((longlong)plVar10);
      if (-1 < (int)uVar6) {
        if ((uint)((int)plVar10[7] * 8) < uVar2) {
          uVar7 = ComDbResize((longlong)plVar10,(uVar2 & 0xfffffc00) + 0x400);
          if ((int)uVar7 < 0) goto LAB_1c0008ecb;
        }
        pbVar8 = (byte *)((ulonglong)(uVar2 - 1 >> 3) + plVar10[6]);
        bVar11 = '\x01' << ((byte)(uVar2 - 1) & 7);
        bVar1 = *pbVar8;
        if ((bVar11 & bVar1) == 0) {
          *pbVar8 = bVar1 | bVar11;
          ComDbRelease((longlong)plVar10,'\x01');
        }
      }
    }
  }
LAB_1c0008ecb:
  if (plVar10 != (longlong *)0x0) {
    ComDbRegisterDevicePort((longlong)plVar10,uVar2,param_1);
  }
LAB_1c0008edd:
  *param_3 = uVar2;
  if (plVar10 != (longlong *)0x0) {
    ComDbDestroy(plVar10);
  }
  return uVar9;
}



===== PortCfgQueryResourcePortAddress @ 1c0008f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PortCfgQueryResourcePortAddress(undefined8 param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  int *piVar5;
  longlong lVar6;
  int *piVar7;
  uint local_res10 [2];
  ulonglong local_res18;
  
  lVar6 = WdfFunctions_01015;
  local_res10[0] = 0;
  local_res18 = 0;
  *param_2 = 0;
  uVar4 = (**(code **)(lVar6 + 0x108))(WdfDriverGlobals,param_1);
  iVar2 = IoGetDeviceProperty(uVar4,4,0,0,local_res10);
  if (iVar2 < 0) {
    if (iVar2 == -0x3fffffdd) {
      piVar5 = (int *)ExAllocatePool2(0x100,local_res10[0],0x67437450);
      if (piVar5 == (int *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
        iVar2 = IoGetDeviceProperty(uVar4,4,local_res10[0],piVar5,local_res10);
        if (-1 < iVar2) {
          if ((local_res10[0] < 4) || (*piVar5 == 0)) {
            iVar2 = -0x3ffff6f5;
          }
          else {
            uVar1 = piVar5[4];
            piVar7 = piVar5 + 5;
            uVar3 = 0;
            if (uVar1 != 0) {
              do {
                if ((char)*piVar7 == '\x01') break;
                uVar3 = uVar3 + 1;
                piVar7 = piVar7 + 5;
              } while (uVar3 < uVar1);
            }
            if (uVar3 < uVar1) {
              lVar6 = RtlCmDecodeMemIoResource(piVar7,&local_res18);
              if ((lVar6 != 0) && (local_res18 < 0x10000)) {
                *param_2 = (short)local_res18;
              }
            }
            else {
              iVar2 = -0x3ffffddb;
            }
          }
        }
        ExFreePoolWithTag(piVar5,0);
      }
    }
  }
  else {
    iVar2 = -0x3fffff1b;
  }
  return iVar2;
}



===== ComDbAcquire @ 1c00090a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ComDbAcquire(longlong param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  int local_res8 [2];
  int local_res10 [2];
  undefined8 local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar3 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(longlong *)(param_1 + 8) != 0) {
    local_res18[0] = 0xffffffffffffd8f0;
    iVar1 = ZwWaitForSingleObject(*(longlong *)(param_1 + 8),0,local_res18);
    if (iVar1 < 0) goto LAB_1c00091da;
  }
  RtlInitUnicodeString(&local_28,L"ComDB");
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x758))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_28,0,0,local_res8,
                     local_res10);
  if (uVar2 != 0x80000005) {
    if ((int)uVar2 < 0) {
      return (ulonglong)uVar2;
    }
    return 0xc00000e5;
  }
  if (local_res8[0] != *(int *)(param_1 + 0x38)) {
    uVar3 = ComDbResize(param_1,local_res8[0] * 8);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffffff;
    }
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x758))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_28,local_res8[0],
                     *(undefined8 *)(param_1 + 0x30),local_res8,local_res10);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    return uVar3;
  }
  if (local_res10[0] != 3) {
    return 0xc000090b;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    ComDbRegisterChangeNotification(param_1);
  }
LAB_1c00091da:
  ComDbReclaimUnusedDevicePorts(param_1);
  return uVar3;
}



===== ComDbClaimNextFreePort @ 1c0009200 =====

ulonglong ComDbClaimNextFreePort(longlong param_1,uint *param_2)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (param_1 == 0) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = ComDbAcquire(param_1);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      pbVar5 = *(byte **)(param_1 + 0x30);
      uVar4 = 3;
      bVar1 = 4;
      pbVar6 = pbVar5 + *(uint *)(param_1 + 0x38);
      if (pbVar5 < pbVar6) {
        do {
          if ((bVar1 & *pbVar5) == 0) {
            bVar1 = *pbVar5 | bVar1;
            goto LAB_1c00092c9;
          }
          if ((char)bVar1 < '\0') {
            bVar1 = 1;
            pbVar5 = pbVar5 + 1;
          }
          else {
            bVar1 = bVar1 * '\x02';
          }
          uVar4 = uVar4 + 1;
        } while (pbVar5 < pbVar6);
        if (0xfff < uVar4) {
          return uVar3;
        }
      }
      else {
        uVar4 = 3;
      }
      uVar2 = ComDbResize(param_1,(uVar4 & 0xfffffc00) + 0x400);
      uVar3 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        pbVar5 = (byte *)((ulonglong)(uVar4 - 1 >> 3) + *(longlong *)(param_1 + 0x30));
        bVar1 = *pbVar5 | (byte)(1 << (uVar4 - 1 & 7));
LAB_1c00092c9:
        *pbVar5 = bVar1;
        *param_2 = uVar4;
        uVar4 = ComDbRelease(param_1,'\x01');
        uVar3 = (ulonglong)uVar4;
      }
    }
  }
  return uVar3;
}



===== ComDbDestroy @ 1c0009300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ComDbDestroy(longlong *param_1)

{
  if (*param_1 != 0) {
    ZwClose();
  }
  if (param_1[1] != 0) {
    ZwClose();
  }
  if (param_1[5] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (param_1[4] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (param_1[6] != 0) {
    ExFreePoolWithTag(param_1[6],0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== ComDbGetLastDeviceDeleteDate @ 1c00093b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ComDbGetLastDeviceDeleteDate(undefined8 param_1)

{
  int iVar1;
  int local_res10 [2];
  int local_res18 [2];
  longlong local_res20;
  longlong local_38 [4];
  
  local_38[0] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  RtlInitUnicodeString
            (local_38 + 1,L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class");
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,local_38 + 1,0x20019,0,local_38);
  if (-1 < iVar1) {
    iVar1 = RtlStringFromGUID(&GUID_DEVCLASS_PORTS,local_38 + 1);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                        (WdfDriverGlobals,local_38[0],local_38 + 1,0x20019,0,&local_res20);
      RtlFreeUnicodeString(local_38 + 1);
      if (-1 < iVar1) {
        RtlInitUnicodeString(local_38 + 1,L"LastDeleteDate");
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))
                          (WdfDriverGlobals,local_res20,local_38 + 1,8,param_1,local_res18,
                           local_res10);
        if ((-1 < iVar1) && ((local_res10[0] != 3 || (local_res18[0] != 8)))) {
          iVar1 = -0x3ffff6f5;
        }
      }
    }
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_38[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== ComDbOpen @ 1c0009560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ComDbOpen(longlong *param_1)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  byte *pbVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auStack_c8 [32];
  byte *local_a8;
  uint *local_a0;
  uint *local_98;
  longlong *local_90;
  uint local_78;
  uint local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  uint local_60 [2];
  byte local_58 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_74 = 0;
  local_78 = 0;
  local_60[0] = 0;
  local_70 = 0;
  uStack_68 = 0;
  plVar6 = (longlong *)ExAllocatePool2(0x100,0x40,0x67437450);
  if (plVar6 == (longlong *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    uVar10 = 0x110;
LAB_1c000963d:
    pbVar7 = (byte *)ExAllocatePool2(0x100,uVar10,0x67437450);
    if (pbVar7 != (byte *)0x0) {
      local_98 = &local_78;
      local_a0 = (uint *)CONCAT44(local_a0._4_4_,uVar10);
      local_a8 = pbVar7;
      uVar4 = RtlGetPersistedStateLocation
                        (L"ComNameArbiter",0,
                         L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\COM Name Arbiter"
                         ,0);
      uVar3 = local_78;
      uVar9 = (ulonglong)uVar4;
      if (uVar4 == 0x80000005) {
        if (uVar10 < local_78) goto code_r0x0001c0009622;
        uVar9 = 0xc00000e5;
        goto LAB_1c00099ba;
      }
      if ((int)uVar4 < 0) goto LAB_1c00099ba;
      RtlInitUnicodeString(&local_70,pbVar7);
      local_a0 = local_60;
      plVar1 = plVar6 + 4;
      local_98 = (uint *)0x0;
      local_a8 = (byte *)((ulonglong)local_a8 & 0xffffffff00000000);
      local_90 = plVar1;
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x730))(WdfDriverGlobals,0,&local_70,0x2001f);
      uVar9 = (ulonglong)uVar10;
      if ((int)uVar10 < 0) goto LAB_1c00099ba;
      RtlInitUnicodeString(&local_70,L"Devices");
      local_90 = plVar6 + 5;
      local_98 = (uint *)0x0;
      local_a0 = local_60;
      local_a8 = (byte *)((ulonglong)local_a8 & 0xffffffff00000000);
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x730))(WdfDriverGlobals,*plVar1,&local_70,0x2001f)
      ;
      uVar9 = (ulonglong)uVar10;
      if ((int)uVar10 < 0) goto LAB_1c00099ba;
      RtlInitUnicodeString(&local_70,L"ComDB");
      local_98 = &local_74;
      puVar2 = (uint *)(plVar6 + 7);
      local_a8 = (byte *)0x0;
      local_a0 = puVar2;
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,*plVar1,&local_70,0);
      if (uVar10 == 0xc0000034) {
        uVar8 = ComDbResize((longlong)plVar6,0x100);
        uVar9 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_1c00099ba;
        local_a0 = (uint *)plVar6[6];
        local_a8 = (byte *)CONCAT44(local_a8._4_4_,*puVar2);
        uVar10 = (**(code **)(WdfFunctions_01015 + 0x788))(WdfDriverGlobals,*plVar1,&local_70,3);
        uVar9 = (ulonglong)uVar10;
        if ((int)uVar10 < 0) goto LAB_1c00099ba;
      }
      else {
        if (uVar10 != 0x80000005) {
          if (-1 < (int)uVar10) {
            uVar10 = 0xc00000e5;
          }
          uVar9 = (ulonglong)uVar10;
          goto LAB_1c00099ba;
        }
        uVar8 = ComDbResize((longlong)plVar6,*puVar2 << 3);
        uVar9 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) goto LAB_1c00099ba;
        local_a8 = (byte *)plVar6[6];
        local_98 = &local_74;
        local_a0 = puVar2;
        uVar10 = (**(code **)(WdfFunctions_01015 + 0x758))
                           (WdfDriverGlobals,*plVar1,&local_70,*puVar2);
        uVar9 = (ulonglong)uVar10;
        if ((int)uVar10 < 0) goto LAB_1c00099ba;
        if (local_74 != 3) {
          uVar9 = 0xc000090b;
          goto LAB_1c00099ba;
        }
      }
      RtlInitUnicodeString(&local_70,L"ComDB Merge");
      local_98 = &local_74;
      local_a0 = &local_78;
      local_a8 = local_58;
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x758))(WdfDriverGlobals,*plVar1,&local_70,0x20);
      if ((iVar5 < 0) || (*puVar2 <= local_78)) {
        uVar9 = 0;
        goto LAB_1c0009996;
      }
      uVar9 = 0;
      if (local_78 != 0) {
        do {
          *(byte *)(uVar9 + plVar6[6]) = *(byte *)(uVar9 + plVar6[6]) | local_58[uVar9];
          uVar10 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar10;
        } while (uVar10 < local_78);
      }
      (**(code **)(WdfFunctions_01015 + 0x750))(WdfDriverGlobals,*plVar1,&local_70);
      RtlInitUnicodeString(&local_70,L"ComDB");
      local_a0 = (uint *)plVar6[6];
      local_a8 = (byte *)CONCAT44(local_a8._4_4_,*puVar2);
      uVar10 = (**(code **)(WdfFunctions_01015 + 0x788))(WdfDriverGlobals,*plVar1,&local_70,3);
      uVar9 = (ulonglong)uVar10;
      if (-1 < (int)uVar10) {
LAB_1c0009996:
        ComDbReclaimUnusedDevicePorts((longlong)plVar6);
        ComDbRegisterChangeNotification((longlong)plVar6);
        *param_1 = (longlong)plVar6;
        plVar6 = (longlong *)0x0;
      }
LAB_1c00099ba:
      if (pbVar7 != (byte *)0x0) {
        ExFreePoolWithTag(pbVar7,0);
      }
      if (plVar6 == (longlong *)0x0) {
        return uVar9;
      }
      goto LAB_1c000965c;
    }
    uVar9 = 0xc000009a;
LAB_1c000965c:
    ComDbDestroy(plVar6);
  }
  return uVar9;
code_r0x0001c0009622:
  ExFreePoolWithTag(pbVar7,0);
  uVar10 = uVar3;
  goto LAB_1c000963d;
}



===== ComDbReclaimUnusedDevicePorts @ 1c00099e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0009b96) */
/* WARNING: Removing unreachable block (ram,0x0001c0009dc5) */
/* WARNING: Removing unreachable block (ram,0x0001c0009bd1) */

int ComDbReclaimUnusedDevicePorts(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  wchar_t *pwVar12;
  longlong ****pppplVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  byte *pbVar16;
  undefined1 *puVar17;
  undefined8 uVar18;
  uint uVar19;
  undefined1 auStackY_118 [8];
  undefined1 auStackY_110 [24];
  longlong ****local_d0;
  longlong ****local_c8;
  int local_c0;
  int local_bc;
  longlong local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  longlong local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  longlong lStack_88;
  longlong local_80 [6];
  wchar_t local_50 [16];
  ulonglong local_30;
  
  puVar17 = auStackY_118;
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = (longlong ****)&local_d0;
  local_a8 = 0;
  local_d0 = (longlong ****)&local_d0;
  local_b8 = 0;
  iVar6 = 0;
  local_bc = 0;
  local_c0 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_90 = 0;
  lStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  if (param_1 == 0) {
    iVar6 = -0x3ffffff3;
  }
  else {
    RtlInitUnicodeString(&local_a0,L"LastReclaimTime");
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x758))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_a0,8);
    if (((iVar5 < 0) || (local_c0 != 3)) || (local_bc != 8)) {
      local_a8 = 0;
    }
    iVar5 = ComDbGetLastDeviceDeleteDate(&local_b8);
    if (iVar5 < 0) {
      iVar6 = NtQuerySystemInformation(3,local_80,0x30);
      puVar17 = auStackY_118;
      if (iVar6 < 0) goto LAB_1c0009eb7;
      local_b8 = local_80[0];
    }
    puVar17 = auStackY_118;
    if (local_a8 == local_b8) {
      iVar6 = 0;
    }
    else {
      lVar9 = ExAllocatePool2(0x100,0x834,0x67437450);
      puVar17 = auStackY_118;
      if (lVar9 != 0) {
        uVar10 = (**(code **)(WdfFunctions_01015 + 0x740))(WdfDriverGlobals);
        puVar17 = auStackY_118;
        uVar15 = 0;
        uVar19 = 0;
        while( true ) {
          uVar18 = 1;
          iVar5 = ZwEnumerateValueKey(uVar10,uVar15,1,lVar9);
          if (iVar5 == -0x7fffffe6) break;
          if (iVar5 == -0x7ffffffb) {
            iVar6 = -0x3fffff1b;
            break;
          }
          if (iVar5 < 0) {
            iVar6 = iVar5;
            break;
          }
          uVar14 = (ulonglong)(*(uint *)(lVar9 + 0x10) >> 1);
          uVar11 = RtlStringValidateDestW();
          if (((int)uVar11 < 0) || (0x7ffffffe < uVar14)) {
            local_50[0] = L'\0';
          }
          else {
            uVar7 = RtlStringCopyWorkerW(local_50,uVar15,uVar18,lVar9 + 0x14,uVar14);
            if (-1 < (int)uVar7) {
              _wcsupr(local_50);
              pwVar12 = wcsstr(local_50,L"COM");
              if ((((pwVar12 != (wchar_t *)0x0) &&
                   (uVar8 = wcstoul(pwVar12 + 3,(wchar_t **)0x0,10), uVar8 != 0)) &&
                  (*(int *)(lVar9 + 4) == 1)) && (*(int *)(lVar9 + 0xc) - 2U < 0xfffe)) {
                lStack_88 = (ulonglong)*(uint *)(lVar9 + 8) + lVar9;
                uVar4 = *(short *)(lVar9 + 0xc) - 2;
                local_90._0_4_ = CONCAT22(*(undefined2 *)(lVar9 + 0xc),uVar4);
                if ((*(short *)(lStack_88 + (ulonglong)(uVar4 >> 1) * 2) == 0) &&
                   (iVar5 = IoGetDeviceInterfacePropertyData
                                      (&local_90,&DEVPKEY_DeviceInterface_Enabled,0,0),
                   iVar5 == -0x3fffffcc)) {
                  if (uVar8 <= (uint)(*(int *)(param_1 + 0x38) * 8)) {
                    pbVar16 = (byte *)((ulonglong)(uVar8 - 1 >> 3) + *(longlong *)(param_1 + 0x30));
                    *pbVar16 = *pbVar16 & ~(byte)(1 << (uVar8 - 1 & 7));
                  }
                  uVar18 = 0x30;
                  uVar11 = 0x67437450;
                  pppplVar13 = (longlong ****)ExAllocatePool2(0x100);
                  if (pppplVar13 != (longlong ****)0x0) {
                    RtlStringCopyWorkerW
                              ((short *)(pppplVar13 + 2),uVar18,uVar11,(longlong)local_50,0x7ffffffe
                              );
                    if ((longlong *****)*local_c8 != &local_d0) goto LAB_1c0009e4a;
                    pppplVar13[1] = (longlong ***)local_c8;
                    *pppplVar13 = (longlong ***)&local_d0;
                    *local_c8 = (longlong ***)pppplVar13;
                    local_c8 = pppplVar13;
                  }
                }
              }
            }
          }
          uVar19 = uVar19 + 1;
          uVar15 = (ulonglong)uVar19;
        }
        do {
          pppplVar13 = local_d0;
          if ((longlong *****)local_d0 == &local_d0) goto LAB_1c0009e51;
          if (((longlong *****)local_d0[1] != &local_d0) ||
             (pppplVar2 = (longlong ****)*local_d0, (longlong ****)pppplVar2[1] != local_d0))
          goto LAB_1c0009e4a;
          pppplVar2[1] = (longlong ***)&local_d0;
          pppplVar1 = local_d0 + 2;
          local_d0 = pppplVar2;
          RtlInitUnicodeString(&local_a0,pppplVar1);
          (**(code **)(WdfFunctions_01015 + 0x750))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28),&local_a0);
          ExFreePoolWithTag(pppplVar13,0);
        } while( true );
      }
      iVar6 = -0x3fffff66;
    }
  }
  goto LAB_1c0009eb7;
LAB_1c0009e4a:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar17 = auStackY_110;
LAB_1c0009e51:
  *(undefined8 *)(puVar17 + -8) = 0x1c0009e63;
  RtlInitUnicodeString(&local_a0,L"LastReclaimTime");
  uVar10 = *(undefined8 *)(param_1 + 0x20);
  *(longlong **)(puVar17 + 0x28) = &local_b8;
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x788);
  *(undefined4 *)(puVar17 + 0x20) = 8;
  *(undefined8 *)(puVar17 + -8) = 0x1c0009ea1;
  (*pcVar3)(WdfDriverGlobals,uVar10,&local_a0,3);
  if (lVar9 != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x1c0009eb2;
    ExFreePoolWithTag(lVar9,0);
  }
LAB_1c0009eb7:
  *(undefined8 *)(puVar17 + -8) = 0x1c0009ec5;
  return iVar6;
}



===== ComDbRegisterChangeNotification @ 1c0009ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ComDbRegisterChangeNotification(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res8;
  ulonglong in_stack_ffffffffffffffc8;
  
  local_res8 = 0;
  if (*(longlong *)(param_1 + 8) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 8) = 0;
  }
  iVar1 = ZwCreateEvent(&local_res8,0x1f0003,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x740))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    iVar1 = ZwNotifyChangeKey(uVar2,local_res8,0,0,param_1 + 0x10,4,0,0,0,1);
    if (-1 < iVar1) {
      *(longlong *)(param_1 + 8) = local_res8;
      local_res8 = 0;
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== ComDbRegisterDevicePort @ 1c0009fe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ComDbRegisterDevicePort(longlong param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_58;
  ushort local_50 [4];
  undefined1 *local_48;
  undefined1 local_40 [32];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,param_3,&GUID_DEVINTERFACE_COMPORT,0);
    if (-1 < (int)uVar1) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0);
      if (-1 < (int)uVar1) {
        uVar2 = 0;
        local_68 = local_58;
        uVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                          (WdfDriverGlobals,param_3,&GUID_DEVINTERFACE_COMPORT);
        if (-1 < (int)uVar1) {
          local_48 = local_40;
          local_50[0] = 0;
          local_50[1] = 0x20;
          uVar1 = RtlUnicodeStringPrintf(local_50,L"COM%u",(ulonglong)param_2,uVar2);
          if (-1 < (int)uVar1) {
            uVar1 = (**(code **)(WdfFunctions_01015 + 0x7a8))
                              (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x28),local_50,local_58);
          }
        }
      }
    }
  }
  return uVar1;
}



===== ComDbRelease @ 1c000a128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ComDbRelease(longlong param_1,char param_2)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  iVar1 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (param_2 != '\0') {
    iVar1 = 0;
    if (*(longlong *)(param_1 + 0x30) != 0) {
      RtlInitUnicodeString(&local_18,L"ComDB");
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x788))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),&local_18,3,
                         *(undefined4 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x30));
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    if (*(longlong *)(param_1 + 8) != 0) {
      ComDbRegisterChangeNotification(param_1);
    }
  }
  return iVar1;
}



===== ComDbResize @ 1c000a1c4 =====

undefined8 ComDbResize(longlong param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  void *_Dst;
  undefined8 uVar3;
  uint uVar4;
  
  uVar4 = param_2 >> 3;
  uVar3 = 0;
  _Dst = (void *)ExAllocatePool2(0x100,uVar4,0x67437450);
  if (_Dst == (void *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    puVar1 = (uint *)(param_1 + 0x38);
    if (*(void **)(param_1 + 0x30) != (void *)0x0) {
      uVar2 = *puVar1;
      if (uVar4 < *puVar1) {
        *puVar1 = uVar4;
        uVar2 = uVar4;
      }
      memcpy(_Dst,*(void **)(param_1 + 0x30),(ulonglong)uVar2);
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x30),0);
    }
    *(void **)(param_1 + 0x30) = _Dst;
    *puVar1 = uVar4;
  }
  return uVar3;
}



===== __security_init_cookie @ 1c000b008 =====

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



===== DriverEntry @ 1c000b03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_res18 [2];
  undefined4 local_28;
  undefined4 local_24;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_24 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0x20;
  local_20 = PortCfgAddDevice;
  (**(code **)(WdfFunctions_01015 + 0x3a0))
            (WdfDriverGlobals,param_1,param_2,0,&local_28,local_res18);
  return;
}


