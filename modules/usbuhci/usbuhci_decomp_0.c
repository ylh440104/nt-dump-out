
===== UhciInterruptService @ 140001010 =====

ulonglong UhciInterruptService(longlong param_1)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  ushort uVar11;
  longlong lVar12;
  
  sVar3 = (short)*(undefined8 *)(param_1 + 8);
  uVar4 = in(sVar3 + 2);
  if (((uVar4 == 0xffff) || (uVar11 = uVar4 & 0x3f, uVar11 == 0)) ||
     (((uVar4 & 0x1f) == 0 && (0x1f < uVar11)))) {
    return 0xff00;
  }
  LOCK();
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | (uint)uVar11;
  UNLOCK();
  uVar5 = in(sVar3 + 4);
  if (((uVar4 & 0x18) == 0) && (((uVar4 & 7) == 0 || ((uVar5 & 0xf) == 0)))) {
    bVar10 = 0;
  }
  else {
    bVar10 = 1;
  }
  out(sVar3 + 2,uVar11);
  if (bVar10 != 0) {
    out(sVar3 + 4,0);
  }
  uVar9 = 0;
  if ((uVar4 & 0x18) == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uVar11 >> 3 & 1);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + (uVar11 >> 4 & 1);
  }
  if ((uVar4 & 1) != 0) {
    uVar11 = in((short)*(undefined8 *)(param_1 + 8) + 6);
    if ((((uint)uVar11 ^ *(uint *)(param_1 + 0x44)) >> 10 & 1) != 0) {
      *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) + 0x400;
    }
    if ((**(uint **)(param_1 + 0x98) & 1) == 0) {
      for (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x90) + 0x18); lVar12 != 0;
          lVar12 = *(longlong *)(lVar12 + 0x18)) {
        if ((*(uint *)(lVar12 + 4) & 1) == 0) goto LAB_1400010c6;
      }
      **(uint **)(param_1 + 0x98) = **(uint **)(param_1 + 0x98) | 1;
    }
  }
LAB_1400010c6:
  if ((uVar4 & 0x10) == 0) {
    if (((uVar4 & 1) != 0) && (*(int *)(param_1 + 0x3c) != 0)) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x4c);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        uVar7 = UhciGet32BitFrameNumber(param_1);
        uVar8 = *(uint *)(param_1 + 0x48);
        if ((uVar7 - uVar8) - 0x400 < 0x7fffffff) {
          lVar12 = 0;
          do {
            while (uVar9 == 0) {
              lVar12 = lVar12 + 4;
              **(undefined4 **)(param_1 + 0x78) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x298) + 0x10);
              uVar9 = 1;
            }
            if ((uVar9 & 0x1f) == 0) {
              *(undefined4 *)(lVar12 + *(longlong *)(param_1 + 0x78)) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x2b0) + 0x10);
            }
            else {
              *(uint *)(lVar12 + *(longlong *)(param_1 + 0x78)) =
                   *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar9 & 0x1f) + 0x1f) * 8)
                            + 8) | 2;
            }
            uVar9 = uVar9 + 1;
            lVar12 = lVar12 + 4;
          } while (uVar9 < 0x400);
        }
        else {
          while (uVar9 = uVar8 & 0x3ff, uVar9 != (uVar7 & 0x3ff)) {
            if (uVar9 == 0) {
              **(undefined4 **)(param_1 + 0x78) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x298) + 0x10);
            }
            else if ((uVar8 & 0x1f) == 0) {
              *(undefined4 *)((ulonglong)uVar9 * 4 + *(longlong *)(param_1 + 0x78)) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x2b0) + 0x10);
            }
            else {
              *(uint *)((ulonglong)uVar9 * 4 + *(longlong *)(param_1 + 0x78)) =
                   *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar8 & 0x1f) + 0x1f) * 8)
                            + 8) | 2;
            }
            uVar8 = uVar9 + 1;
          }
        }
        *(uint *)(param_1 + 0x48) = uVar7;
      }
      LOCK();
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
      UNLOCK();
    }
  }
  else {
    LOCK();
    piVar1 = (int *)(param_1 + 0x4c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      uVar6 = UhciGet32BitFrameNumber(param_1);
      lVar12 = 0;
      do {
        while (uVar9 == 0) {
          lVar12 = lVar12 + 4;
          **(undefined4 **)(param_1 + 0x78) = *(undefined4 *)(*(longlong *)(param_1 + 0x298) + 0x10)
          ;
          uVar9 = 1;
        }
        if ((uVar9 & 0x1f) == 0) {
          *(undefined4 *)(lVar12 + *(longlong *)(param_1 + 0x78)) =
               *(undefined4 *)(*(longlong *)(param_1 + 0x2b0) + 0x10);
        }
        else {
          *(uint *)(lVar12 + *(longlong *)(param_1 + 0x78)) =
               *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar9 & 0x1f) + 0x1f) * 8) + 8)
               | 2;
        }
        uVar9 = uVar9 + 1;
        lVar12 = lVar12 + 4;
      } while (uVar9 < 0x400);
      *(undefined4 *)(param_1 + 0x48) = uVar6;
    }
    LOCK();
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    UNLOCK();
    uVar9 = *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar9 + 1;
    if (uVar9 < 0x10) {
      uVar4 = in(sVar3);
      out(sVar3,uVar4 | 1);
    }
  }
  return (ulonglong)bVar10;
}



===== UhciPollController @ 140001390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciPollController(longlong param_1)

{
  undefined8 uVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  
  bVar2 = false;
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    UhciCleanOutIsoch(param_1,'\0');
    UhciUpdateCounter(param_1);
  }
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar4 = 0;
  lVar5 = 1;
  do {
    uVar3 = in(((short)uVar4 + 8) * 2 + (short)uVar1);
    if ((uVar3 & 0x80a) == 0) {
      if (bVar2) goto LAB_140001440;
    }
    else {
      (*DAT_14000b260)(param_1,0x10000001,0x6863705f,lVar5,uVar3,0);
      bVar2 = true;
LAB_140001440:
      (*DAT_14000b240)(param_1);
    }
    uVar4 = uVar4 + 1;
    lVar5 = lVar5 + 1;
    if (1 < uVar4) {
      return;
    }
  } while( true );
}



===== UhciIsochTransfer @ 140001460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UhciIsochTransfer(longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4,
                 longlong param_5)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  void *_Src;
  int *piVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  uint local_res10;
  uint local_68;
  int local_64;
  int local_60;
  undefined1 *local_50;
  
  uVar13 = 0;
  uVar4 = *(ushort *)(param_2 + 10) & 0x80;
  local_res10 = 0;
  uVar3 = 0x69;
  if (uVar4 == 0) {
    uVar3 = 0xe1;
  }
  local_50 = (undefined1 *)0x0;
  local_60 = -0x7ffffd00;
  if ((*(int *)(param_1 + 0x2b8) == 0) &&
     (uVar10 = *(uint *)(param_5 + 4),
     uVar10 <= (uint)(*(int *)(param_2 + 0x78) - *(int *)(param_2 + 0x80)))) {
    uVar11 = 0;
    if (uVar10 != 0) {
      piVar12 = (int *)(param_5 + 0x24);
      uVar14 = (ulonglong)uVar10;
      do {
        iVar9 = *piVar12;
        piVar12 = piVar12 + 0xe;
        uVar10 = uVar11 + 1;
        if (iVar9 != 2) {
          uVar10 = uVar11;
        }
        uVar11 = uVar10;
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
    }
    if (uVar11 <= (uint)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x98))) {
      UhciCleanOutIsoch(param_1,'\0');
      LOCK();
      *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + 1;
      UNLOCK();
      if (*(int *)(param_2 + 0x1c) == 0) {
        LOCK();
        piVar12 = (int *)(param_1 + 0x3c);
        iVar9 = *piVar12;
        *piVar12 = *piVar12 + 1;
        UNLOCK();
        if (iVar9 == 0) {
          uVar6 = UhciGet32BitFrameNumber(param_1);
          *(undefined4 *)(param_1 + 0x48) = uVar6;
        }
      }
      *param_4 = 0x72743031;
      param_4[2] = 0;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[3] = param_2;
      param_4[1] = param_3;
      param_4[4] = param_5;
      (*DAT_14000b260)(param_1,0x10000001,0x5473695f,param_2,param_3,*(undefined4 *)(param_5 + 0x18)
                      );
      uVar14 = 0;
      local_68 = 0;
      if (*(int *)(param_5 + 4) != 0) {
        do {
          lVar1 = uVar14 * 0x38 + param_5;
          local_64 = *(int *)(lVar1 + 0x30);
          if (*(int *)(param_1 + 0x2b8) == 0) {
            uVar5 = in((short)*(undefined8 *)(param_1 + 8) + 6);
            uVar10 = ((*(uint *)(param_1 + 0x44) ^ uVar5 & 0x7ff) & 0x400) +
                     *(uint *)(param_1 + 0x44) | uVar5 & 0x7ff;
            *(uint *)(param_1 + 700) = uVar10;
          }
          else {
            *(int *)(param_1 + 700) = *(int *)(param_1 + 700) + 1;
            uVar10 = *(uint *)(param_1 + 700);
          }
          uVar10 = *(int *)(lVar1 + 0x18) - uVar10;
          if (uVar10 - 1 < 0x7fffffff) {
            local_60 = 0;
            if (0x7ffffffe < (*(int *)(param_1 + 0x48) - *(int *)(lVar1 + 0x18)) + 0x3ffU) {
              local_60 = 0x40000000;
            }
LAB_14000161e:
            uVar10 = *(uint *)(lVar1 + 0x28);
            if (*(int *)(lVar1 + 0x24) == 1) {
              bVar2 = false;
            }
            else {
              uVar10 = uVar10 + *(int *)(lVar1 + 0x38);
              uVar8 = 0;
              uVar11 = *(uint *)(param_2 + 0x94);
              while (uVar8 < *(uint *)(param_2 + 0x90)) {
                local_50 = (undefined1 *)((ulonglong)uVar11 * 0x420 + *(longlong *)(param_2 + 0x88))
                ;
                if ((*(uint *)(local_50 + 0x414) & 1) == 0) {
                  LOCK();
                  *(uint *)(local_50 + 0x414) = *(uint *)(local_50 + 0x414) | 1;
                  UNLOCK();
                  (*DAT_14000b260)(param_1,0x10000001,0x4244695f,local_50,0,0);
                  *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + 1;
                  *(uint *)(param_2 + 0x94) = uVar11;
                  goto LAB_1400018fe;
                }
                uVar11 = uVar11 + 1;
                uVar8 = uVar8 + 1;
                if (*(uint *)(param_2 + 0x90) <= uVar11) {
                  uVar11 = 0;
                }
              }
              (*DAT_14000b290)(param_1);
              local_50 = &DAT_deadfacedeadface;
LAB_1400018fe:
              _Src = (void *)(*(longlong *)(param_5 + 8) + (ulonglong)local_res10);
              *(uint *)(local_50 + 0x418) = uVar10;
              *(void **)(local_50 + 0x408) = _Src;
              if (uVar4 == 0) {
                memmove(local_50,_Src,(ulonglong)uVar10);
              }
              local_64 = *(int *)(local_50 + 0x400);
              bVar2 = true;
            }
            *(int *)((longlong)param_4 + 4) = *(int *)((longlong)param_4 + 4) + 1;
            uVar8 = 0;
            uVar11 = *(uint *)(param_2 + 0x7c);
            while (uVar8 < *(uint *)(param_2 + 0x78)) {
              piVar12 = (int *)((ulonglong)uVar11 * 0x80 + *(longlong *)(param_2 + 0x70));
              if ((piVar12[10] & 1U) == 0) {
                LOCK();
                piVar12[10] = piVar12[10] | 1;
                UNLOCK();
                (*DAT_14000b260)(param_1,0x10000001,0x4454615f,piVar12,0,0);
                *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
                *(uint *)(param_2 + 0x7c) = uVar11;
                goto LAB_1400016ac;
              }
              uVar11 = uVar11 + 1;
              uVar8 = uVar8 + 1;
              if (*(uint *)(param_2 + 0x78) <= uVar11) {
                uVar11 = 0;
              }
            }
            (*DAT_14000b290)(param_1);
            piVar12 = (int *)&DAT_deadfacedeadface;
LAB_1400016ac:
            piVar12[10] = piVar12[10] | 2;
            *(undefined8 **)(piVar12 + 6) = param_4;
            *piVar12 = 0;
            piVar12[1] = 0;
            uVar11 = 0;
            if (*(int *)(param_4[3] + 0x10) == 0) {
              uVar11 = 0x4000000;
            }
            piVar12[1] = piVar12[1] & 0xfbffffffU | uVar11;
            piVar12[1] = piVar12[1] | 0x800000;
            piVar12[2] = 0;
            piVar12[1] = piVar12[1] | 0x18000000;
            uVar11 = (*(ushort *)(param_4[3] + 10) & 0xf) << 0xf;
            piVar12[2] = uVar11;
            uVar5 = *(ushort *)(param_4[3] + 8);
            piVar12[0xc] = 0;
            piVar12[0xd] = 0;
            piVar12[2] = (uVar5 & 0x7f) << 8 | uVar11;
            iVar9 = 0x7ff;
            *(undefined1 *)(piVar12 + 2) = uVar3;
            if (uVar10 != 0) {
              iVar9 = uVar10 - 1;
            }
            piVar12[2] = piVar12[2] & 0x17ffffU | iVar9 << 0x15;
            piVar12[1] = piVar12[1] | 0x2000000;
            piVar12[1] = piVar12[1] & 0xdfffffff;
            piVar12[1] = piVar12[1] | 0x7ff;
            *(longlong *)(piVar12 + 8) = lVar1 + 0x10;
            piVar12[1] = piVar12[1] & 0xe7ffffff;
            piVar12[3] = local_64;
            if (bVar2) {
              LOCK();
              piVar12[10] = piVar12[10] | 0x20;
              UNLOCK();
              *(undefined1 **)(piVar12 + 0xe) = local_50;
            }
            uVar11 = 0;
            if (*(uint *)(param_5 + 4) <= local_68 + 1) {
              uVar11 = 0x1000000;
            }
            piVar12[1] = uVar11 | piVar12[1] & 0xfeffffffU;
            if (local_60 == 0) {
              (*DAT_14000b260)(param_1,0x10000001,0x3169715f,piVar12,0,*(undefined4 *)(lVar1 + 0x18)
                              );
              piVar12[10] = piVar12[10] | 0x40;
              LOCK();
              if (*piVar12 == 0) {
                *piVar12 = *(int *)(*(longlong *)(param_1 + 0x78) +
                                   (ulonglong)(*(uint *)(lVar1 + 0x18) & 0x3ff) * 4);
              }
              UNLOCK();
              *(int *)(*(longlong *)(param_1 + 0x78) +
                      (ulonglong)(*(uint *)(lVar1 + 0x18) & 0x3ff) * 4) = piVar12[4];
            }
          }
          else {
            if (uVar10 < 0x400) {
              local_60 = 0;
              goto LAB_14000161e;
            }
            local_60 = -0x3ffff600;
            uVar10 = *(int *)(lVar1 + 0x28) + *(int *)(lVar1 + 0x38);
            *(undefined4 *)(lVar1 + 0x20) = 0xc0000a00;
            uVar6 = *(undefined4 *)(lVar1 + 0x18);
            uVar7 = UhciGet32BitFrameNumber(param_1);
            (*DAT_14000b260)(param_1,0x10000001,0x4653425f,uVar7,uVar6,uVar14);
          }
          local_res10 = local_res10 + uVar10;
          local_68 = local_68 + 1;
          uVar14 = (ulonglong)local_68;
        } while (local_68 < *(uint *)(param_5 + 4));
      }
      if (*(int *)((longlong)param_4 + 4) == 0) {
        LOCK();
        *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + -1;
        UNLOCK();
        if (*(int *)(param_2 + 0x1c) == 0) {
          LOCK();
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
          UNLOCK();
        }
        (*DAT_14000b260)(param_1,0x10000001,0x7470635f,(longlong)local_60,param_4,
                         *(undefined4 *)((longlong)param_4 + 0x14));
        (*DAT_14000b248)(param_1,param_2);
        uVar13 = 5;
      }
      return uVar13;
    }
  }
  return 1;
}



===== UhciPollIsochEndpoint @ 140001aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciPollIsochEndpoint(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  (*DAT_14000b260)(param_1,0x10000001,0x4569505f,param_2,0,0);
  UhciCleanOutIsoch(param_1,'\0');
  uVar6 = 0;
  if (*(int *)(param_2 + 0x78) != 0) {
    do {
      piVar5 = (int *)((ulonglong)uVar6 * 0x80 + *(longlong *)(param_2 + 0x70));
      uVar1 = piVar5[10];
      if ((uVar1 & 2) != 0) {
        lVar3 = *(longlong *)(piVar5 + 8);
        if (((*(int *)(param_1 + 0x48) - *(int *)(lVar3 + 8)) - 1U < 0x7fffffff) ||
           ((*(int *)(lVar3 + 8) - *(int *)(param_1 + 0x48)) - 0x401U < 0x7fffffff)) {
          piVar5[10] = uVar1 | 8;
        }
        else if ((uVar1 & 0x40) == 0) {
          iVar4 = UhciGet32BitFrameNumber(param_1);
          iVar2 = *(int *)(lVar3 + 8);
          if ((iVar2 - iVar4) - 1U < 0x7fffffff) {
            if ((*(int *)(param_1 + 0x48) - iVar2) + 0x3ffU < 0x7fffffff) {
LAB_140001baf:
              (*DAT_14000b260)(param_1,0x10000001,0x3269715f,piVar5,0,iVar2);
              piVar5[10] = piVar5[10] | 0x40;
              LOCK();
              if (*piVar5 == 0) {
                *piVar5 = *(int *)(*(longlong *)(param_1 + 0x78) +
                                  (ulonglong)(*(uint *)(lVar3 + 8) & 0x3ff) * 4);
              }
              UNLOCK();
              *(int *)(*(longlong *)(param_1 + 0x78) + (ulonglong)(*(uint *)(lVar3 + 8) & 0x3ff) * 4
                      ) = piVar5[4];
            }
          }
          else if ((uint)(iVar2 - iVar4) < 0x400) goto LAB_140001baf;
        }
        if ((piVar5[10] & 8U) != 0) {
          UhciProcessDoneIsochTd(param_1,piVar5);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_2 + 0x78));
  }
  return;
}



===== UhciProcessDoneIsochTd @ 140001c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciProcessDoneIsochTd(longlong param_1,undefined4 *param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  void *_Src;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  
  lVar2 = *(longlong *)(param_2 + 6);
  *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + -1;
  lVar3 = *(longlong *)(param_2 + 8);
  lVar4 = *(longlong *)(lVar2 + 8);
  lVar5 = *(longlong *)(lVar2 + 0x18);
  piVar1 = (int *)(lVar3 + 0x10);
  if ((param_2[10] & 0x40) == 0) {
    iVar8 = -0x3ffff600;
  }
  else if (((uint)param_2[1] >> 0x17 & 1) == 0) {
    uVar7 = UhciGetErrorFromTD(param_1,(longlong)param_2);
    iVar8 = (int)uVar7;
  }
  else {
    iVar8 = -0x3ffffff1;
  }
  *piVar1 = iVar8;
  (*DAT_14000b260)(param_1,0x10000001,0x7469445f,lVar2,(longlong)iVar8,param_2);
  if ((param_2[1] & 0x7ff) == 0x7ff) {
    iVar8 = 0;
  }
  else {
    iVar8 = (param_2[1] & 0x7ff) + 1;
  }
  *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + iVar8;
  *(int *)(lVar3 + 4) = iVar8;
  if (((char)param_2[2] == 'i') && ((param_2[10] & 0x20) != 0)) {
    _Src = *(void **)(param_2 + 0xe);
    memmove(*(void **)((longlong)_Src + 0x408),_Src,(ulonglong)*(uint *)((longlong)_Src + 0x418));
    (*DAT_14000b298)(param_1,lVar4,*(undefined8 *)((longlong)_Src + 0x408),
                     *(undefined4 *)((longlong)_Src + 0x418));
  }
  if ((param_2[10] & 0x20) != 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x4244665f,*(undefined8 *)(param_2 + 0xe),lVar5,0);
    *(int *)(lVar5 + 0x98) = *(int *)(lVar5 + 0x98) + -1;
    if (*(int *)(lVar5 + 0x1c) == 0) {
      *(undefined4 *)(*(longlong *)(param_2 + 0xe) + 0x414) = 0;
    }
    else {
      *(undefined4 *)(*(longlong *)(param_2 + 0xe) + 0x54) = 0;
    }
  }
  *(int *)(lVar5 + 0x80) = *(int *)(lVar5 + 0x80) + -1;
  *param_2 = 0xbadf00d;
  (*DAT_14000b260)(param_1,0x10000001,0x4454665f,param_2,lVar5,0);
  param_2[10] = 0;
  *(undefined1 **)(param_2 + 6) = &DAT_deadfacedeadface;
  if (*(int *)(lVar2 + 4) == 0) {
    LOCK();
    *(int *)(lVar5 + 0x58) = *(int *)(lVar5 + 0x58) + -1;
    UNLOCK();
    if (*(int *)(lVar5 + 0x1c) == 0) {
      LOCK();
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
      UNLOCK();
    }
    (*DAT_14000b260)(param_1,0x10000001,0x7469635f,(longlong)*piVar1,lVar2,
                     *(undefined4 *)(lVar2 + 0x14));
    uVar6 = UhciGet32BitFrameNumber(param_1);
    *(undefined4 *)(lVar4 + 0x10) = uVar6;
    (*DAT_14000b258)(param_1,lVar5,lVar4,*(undefined8 *)(lVar2 + 0x20));
  }
  return;
}



===== UhciPollEndpoint @ 140001e60 =====

void UhciPollEndpoint(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 != 3) {
    if (iVar1 == 0) {
      UhciPollIsochEndpoint(param_1,param_2);
      return;
    }
    if ((iVar1 != 1) && (iVar1 != 2)) {
      return;
    }
  }
  UhciPollAsyncEndpoint(param_1,param_2,0);
  return;
}



===== UhciPollAsyncEndpoint @ 140001ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciPollAsyncEndpoint(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  uint *puVar4;
  longlong lVar5;
  code *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  undefined4 *puVar12;
  
  if (param_3 == 0) {
    plVar1 = (longlong *)(param_2 + 0xc0);
    while (plVar3 = (longlong *)*plVar1, plVar3 != plVar1) {
      if (((longlong *)plVar3[1] != plVar1) ||
         (lVar2 = *plVar3, (longlong *)*(longlong *)(lVar2 + 8) != plVar3)) goto LAB_1400026e7;
      *plVar1 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar1;
      (*DAT_14000b260)(param_1,0x10000001,0x3461435f,(longlong)*(int *)(plVar3 + -3),plVar3 + -5,
                       *(undefined4 *)((longlong)plVar3 + -0x14));
      (*DAT_14000b250)(param_1,param_2,plVar3[-4],*(undefined4 *)(plVar3 + -3),
                       *(undefined4 *)((longlong)plVar3 + -0x14));
    }
  }
  if ((*(uint *)(param_2 + 4) & 1) != 0) {
    return;
  }
  lVar2 = *(longlong *)(param_2 + 0x50);
  do {
    uVar9 = *(uint *)(lVar2 + 4) & 0xfffffff8;
    if (uVar9 == 0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)(*DAT_14000b268)(uVar9,param_1,param_2);
    }
    (*DAT_14000b260)(param_1,0x10000001,0x6474635f,uVar9,puVar7,param_2);
    for (puVar12 = *(undefined4 **)(param_2 + 0x68);
        (puVar12 != puVar7 && (puVar12 != (undefined4 *)0x0));
        puVar12 = *(undefined4 **)(puVar12 + 0xc)) {
      LOCK();
      puVar12[10] = puVar12[10] | 8;
      UNLOCK();
      plVar3 = *(longlong **)(param_2 + 0xb0);
      plVar1 = (longlong *)(puVar12 + 0x10);
      if (*plVar3 != param_2 + 0xa8) goto LAB_1400026e7;
      *plVar1 = param_2 + 0xa8;
      *(longlong **)(puVar12 + 0x12) = plVar3;
      *plVar3 = (longlong)plVar1;
      *(longlong **)(param_2 + 0xb0) = plVar1;
      if ((*(longlong *)(puVar12 + 0xc) != 0) &&
         ((*(uint *)(*(longlong *)(puVar12 + 0xc) + 4) >> 0x17 & 1) != 0)) {
        lVar10 = *(longlong *)(puVar12 + 0xc);
        if (uVar9 == 0) {
          *(longlong *)(param_2 + 0x68) = lVar10;
          (*DAT_14000b260)(param_1,0x10000001,0x796c445f,lVar10,0,lVar2);
          if (lVar10 == 0) goto LAB_14000269b;
          *(longlong *)(param_2 + 0x68) = lVar10;
          if ((*(uint *)(param_2 + 4) & 1) != 0) goto LAB_1400026ab;
          uVar9 = *(uint *)(lVar10 + 0x10) & 0xfffffffc;
          goto LAB_1400026b0;
        }
        if (uVar9 != *(uint *)(lVar10 + 0x10)) {
          (*DAT_14000b260)(param_1,0x10000001,0x7245515f,uVar9,*(uint *)(lVar10 + 0x10),lVar10);
        }
      }
    }
    *(undefined4 **)(param_2 + 0x68) = puVar7;
    lVar10 = 0;
    if (puVar7 == (undefined4 *)0x0) {
LAB_14000269b:
      *(undefined8 *)(param_2 + 0x60) = 0;
      *(undefined8 *)(param_2 + 0x68) = 0;
LAB_1400026ab:
      uVar9 = 1;
LAB_1400026b0:
      (*DAT_14000b260)(param_1,0x10000001,0x7471735f,lVar10,param_2,0);
      *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar9;
      goto LAB_140001f8c;
    }
    (*DAT_14000b260)(param_1,0x10000001,0x4454635f,puVar7,uVar9,*(undefined8 *)(puVar7 + 6));
    if (((uint)puVar7[1] >> 0x17 & 1) != 0) goto LAB_140001f8c;
    if ((((((char)puVar7[2] == 'i') && (((uint)puVar7[1] >> 0x16 & 1) != 0)) &&
         (((uint)puVar7[1] >> 0x14 & 1) == 0)) &&
        ((((uint)puVar7[1] >> 0x13 & 1) == 0 && (((uint)puVar7[1] >> 0x12 & 1) != 0)))) &&
       ((((uint)puVar7[1] >> 0x11 & 1) == 0 && ((puVar7[10] & 0x800) == 0)))) {
      LOCK();
      puVar7[10] = puVar7[10] | 0x800;
      UNLOCK();
      puVar7[1] = puVar7[1] | 0x18000000;
      puVar7[1] = puVar7[1] & 0xffbfffff;
      puVar7[1] = puVar7[1] & 0xfffbffff;
      puVar7[1] = puVar7[1] | 0x800000;
      goto LAB_140001f8c;
    }
    if (((((uint)puVar7[1] >> 0x16 & 1) != 0) || (((uint)puVar7[1] >> 0x15 & 1) != 0)) ||
       ((((uint)puVar7[1] >> 0x14 & 1) != 0 ||
        ((((uint)puVar7[1] >> 0x12 & 1) != 0 || (((uint)puVar7[1] >> 0x11 & 1) != 0)))))) {
      LOCK();
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
      UNLOCK();
      (*DAT_14000b260)(param_1,0x10000001,0x5472655f,lVar2,puVar7,puVar7[1]);
      lVar5 = *(longlong *)(*(longlong *)(puVar7 + 6) + 8);
      LOCK();
      puVar7[10] = puVar7[10] | 8;
      UNLOCK();
      lVar10 = param_2 + 0xa8;
      plVar3 = *(longlong **)(param_2 + 0xb0);
      plVar1 = (longlong *)(puVar7 + 0x10);
      if (*plVar3 != lVar10) goto LAB_1400026e7;
      *plVar1 = lVar10;
      *(longlong **)(puVar7 + 0x12) = plVar3;
      *plVar3 = (longlong)plVar1;
      *(longlong **)(param_2 + 0xb0) = plVar1;
      goto joined_r0x00014000246c;
    }
    if ((puVar7[1] & 0x7ff) == 0x7ff) {
      uVar11 = 0;
    }
    else {
      uVar11 = (puVar7[1] & 0x7ff) + 1;
    }
    uVar8 = 0;
    if ((uint)puVar7[2] >> 0x15 != 0x7ff) {
      uVar8 = ((uint)puVar7[2] >> 0x15) + 1;
    }
    if (uVar11 < uVar8) {
      puVar4 = *(uint **)(*(longlong *)(puVar7 + 6) + 8);
      (*DAT_14000b260)(param_1,0x10000001,0x5068735f,lVar2,puVar7,puVar7[1]);
      LOCK();
      puVar7[10] = puVar7[10] | 8;
      UNLOCK();
      lVar10 = param_2 + 0xa8;
      plVar3 = *(longlong **)(param_2 + 0xb0);
      plVar1 = (longlong *)(puVar7 + 0x10);
      if (*plVar3 != lVar10) goto LAB_1400026e7;
      *plVar1 = lVar10;
      *(longlong **)(puVar7 + 0x12) = plVar3;
      *plVar3 = (longlong)plVar1;
      *(longlong **)(param_2 + 0xb0) = plVar1;
      goto LAB_140002224;
    }
    (*DAT_14000b260)(param_1,0x10000001,0x546f6e5f,lVar2,puVar7,puVar12);
    if (uVar9 != (*(uint *)(lVar2 + 4) & 0xfffffff8)) goto LAB_140001f8c;
    KeStallExecutionProcessor(0x14);
    uVar11 = *(uint *)(lVar2 + 4) & 0xfffffff8;
    (*DAT_14000b260)(param_1,0x10000001,0x54436e5f,lVar2,uVar9,uVar11);
  } while (uVar9 != uVar11);
  LOCK();
  puVar7[10] = puVar7[10] | 8;
  UNLOCK();
  plVar3 = *(longlong **)(param_2 + 0xb0);
  plVar1 = (longlong *)(puVar7 + 0x10);
  if (*plVar3 != param_2 + 0xa8) goto LAB_1400026e7;
  *(longlong **)(puVar7 + 0x12) = plVar3;
  *plVar1 = param_2 + 0xa8;
  *plVar3 = (longlong)plVar1;
  *(longlong **)(param_2 + 0xb0) = plVar1;
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(puVar7 + 0xc);
  *(undefined4 *)(lVar2 + 4) = *puVar7;
  (*DAT_14000b260)(param_1,0x10000001,0x2b756e5f,lVar2,puVar7,puVar12);
  goto LAB_140001f8c;
joined_r0x00014000246c:
  if ((puVar12 == (undefined4 *)0x0) ||
     (*(int *)(*(longlong *)(*(longlong *)(puVar12 + 6) + 8) + 8) != *(int *)(lVar5 + 8)))
  goto LAB_140002472;
  if ((puVar12[10] & 8) == 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x546b735f,lVar2,0,puVar12);
    LOCK();
    puVar12[10] = puVar12[10] | 0x18;
    UNLOCK();
    plVar3 = *(longlong **)(param_2 + 0xb0);
    plVar1 = (longlong *)(puVar12 + 0x10);
    if (*plVar3 != lVar10) goto LAB_1400026e7;
    *plVar1 = lVar10;
    *(longlong **)(puVar12 + 0x12) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(param_2 + 0xb0) = plVar1;
  }
  puVar12 = *(undefined4 **)(puVar12 + 0xc);
  goto joined_r0x00014000246c;
LAB_140002472:
  if (*(int *)(param_2 + 0x1c) != 1) {
    UhciFixDataToggle(param_1,param_2,(longlong)puVar12,(uint)puVar7[2] >> 0x13 & 1);
  }
  goto LAB_14000231f;
LAB_140002224:
  if (((puVar12 == (undefined4 *)0x0) ||
      (*(uint *)(*(longlong *)(*(longlong *)(puVar12 + 6) + 8) + 8) != puVar4[2])) ||
     ((((uint)puVar12[10] >> 10 & 1) != 0 && ((*puVar4 & 2) != 0)))) goto LAB_1400022a8;
  if ((puVar12[10] & 8) == 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x546b735f,lVar2,0,puVar12);
    LOCK();
    puVar12[10] = puVar12[10] | 0x18;
    UNLOCK();
    plVar3 = *(longlong **)(param_2 + 0xb0);
    plVar1 = (longlong *)(puVar12 + 0x10);
    if (*plVar3 != lVar10) goto LAB_1400026e7;
    *plVar1 = lVar10;
    *(longlong **)(puVar12 + 0x12) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(param_2 + 0xb0) = plVar1;
  }
  puVar12 = *(undefined4 **)(puVar12 + 0xc);
  goto LAB_140002224;
LAB_1400022a8:
  if ((*(int *)(param_2 + 0x1c) != 1) && (*(longlong *)(puVar7 + 0xc) != 0)) {
    uVar9 = *(uint *)(*(longlong *)(puVar7 + 0xc) + 8) >> 0x13 & 1;
    (*DAT_14000b260)(param_1,0x10000001,0x7464465f,param_2,uVar9,0);
    for (puVar7 = puVar12; puVar7 != (undefined4 *)0x0; puVar7 = *(undefined4 **)(puVar7 + 0xc)) {
      uVar11 = uVar9 << 0x13;
      uVar9 = uVar9 ^ 1;
      puVar7[2] = puVar7[2] & 0xfff7ffff | uVar11;
    }
    *(uint *)(param_2 + 0xa0) = uVar9;
  }
  if ((*puVar4 & 2) == 0) {
    LOCK();
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
    UNLOCK();
  }
LAB_14000231f:
  if (puVar12 == (undefined4 *)0x0) {
    *(undefined8 *)(param_2 + 0x60) = 0;
    *(undefined8 *)(param_2 + 0x68) = 0;
LAB_140002330:
    uVar9 = 1;
  }
  else {
    *(undefined4 **)(param_2 + 0x68) = puVar12;
    if ((*(uint *)(param_2 + 4) & 1) != 0) goto LAB_140002330;
    uVar9 = puVar12[4] & 0xfffffffc;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x7471735f,puVar12,param_2,0);
  *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar9;
LAB_140001f8c:
  plVar1 = (longlong *)(param_2 + 0xa8);
  while( true ) {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      if (((*(uint *)(param_2 + 4) & 4) != 0) && ((*(uint *)(param_2 + 4) & 1) != 0)) {
        (*DAT_14000b260)(param_1,0x10000001,0x486c635f,lVar2,0,0);
        UhciSetEndpointStatus(param_1,param_2,0);
      }
      return;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar10 = *plVar3, (longlong *)*(longlong *)(lVar10 + 8) != plVar3)) break;
    *plVar1 = lVar10;
    *(longlong **)(lVar10 + 8) = plVar1;
    if (((byte)*(undefined4 *)(plVar3 + -3) & 10) == 10) {
      UhciProcessDoneAsyncTd(param_1,(undefined4 *)(plVar3 + -8),param_3);
    }
  }
LAB_1400026e7:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== UhciProcessDoneAsyncTd @ 140002700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciProcessDoneAsyncTd(longlong param_1,undefined4 *param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  void *_Src;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong *plVar8;
  int iVar9;
  longlong lVar10;
  
  lVar1 = *(longlong *)(param_2 + 6);
  lVar10 = 0;
  iVar5 = 0;
  *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + -1;
  uVar2 = *(undefined8 *)(lVar1 + 8);
  lVar3 = *(longlong *)(lVar1 + 0x18);
  if ((param_2[10] & 0x10) != 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x64744b5f,lVar1,0,param_2);
    goto LAB_14000276e;
  }
  if ((*(uint *)(lVar3 + 4) & 1) == 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x6474445f,lVar1,0,param_2);
LAB_1400028b4:
    if ((param_2[1] & 0x7ff) == 0x7ff) goto LAB_1400029d1;
    iVar9 = (param_2[1] & 0x7ff) + 1;
  }
  else {
    uVar6 = UhciGetErrorFromTD(param_1,(longlong)param_2);
    iVar5 = (int)uVar6;
    lVar10 = (longlong)iVar5;
    (*DAT_14000b260)(param_1,0x10000001,0x6474445f,lVar1,lVar10,param_2);
    if (iVar5 == 0) goto LAB_1400028b4;
LAB_1400029d1:
    iVar9 = 0;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x6e6c745f,iVar9,0,0);
  if ((char)param_2[2] != '-') {
    (*DAT_14000b260)(param_1,0x10000001,0x7464495f,param_2,lVar1,iVar9);
    *(int *)(lVar1 + 0x14) = *(int *)(lVar1 + 0x14) + iVar9;
  }
  if (((char)param_2[2] == 'i') && ((param_2[10] & 0x20) != 0)) {
    _Src = *(void **)(param_2 + 0xe);
    memmove(*(void **)((longlong)_Src + 0x48),_Src,(ulonglong)*(uint *)((longlong)_Src + 0x58));
    (*DAT_14000b298)(param_1,uVar2,*(undefined8 *)((longlong)_Src + 0x48),
                     *(undefined4 *)((longlong)_Src + 0x58));
  }
  if (iVar5 != 0) {
    *(int *)(lVar1 + 0x10) = iVar5;
    (*DAT_14000b260)(param_1,0x10000001,0x5245745f,lVar10,0,0);
  }
LAB_14000276e:
  if ((param_2[10] & 0x20) != 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x4244665f,*(undefined8 *)(param_2 + 0xe),lVar3,0);
    *(int *)(lVar3 + 0x98) = *(int *)(lVar3 + 0x98) + -1;
    if (*(int *)(lVar3 + 0x1c) == 0) {
      *(undefined4 *)(*(longlong *)(param_2 + 0xe) + 0x414) = 0;
    }
    else {
      *(undefined4 *)(*(longlong *)(param_2 + 0xe) + 0x54) = 0;
    }
  }
  *(int *)(lVar3 + 0x80) = *(int *)(lVar3 + 0x80) + -1;
  *param_2 = 0xbadf00d;
  (*DAT_14000b260)(param_1,0x10000001,0x4454665f,param_2,lVar3,0);
  param_2[10] = 0;
  *(undefined1 **)(param_2 + 6) = &DAT_deadfacedeadface;
  if (*(int *)(lVar1 + 4) == 0) {
    if (param_3 == lVar1) {
      (*DAT_14000b260)(param_1,0x10000001,0x3161435f,(longlong)*(int *)(lVar1 + 0x10),lVar1,
                       *(undefined4 *)(lVar1 + 0x14));
    }
    else {
      LOCK();
      *(int *)(lVar3 + 0x58) = *(int *)(lVar3 + 0x58) + -1;
      UNLOCK();
      if (param_3 == 0) {
        if (*(int *)(lVar3 + 0x1c) == 0) {
          LOCK();
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
          UNLOCK();
        }
        (*DAT_14000b260)(param_1,0x10000001,0x3261435f,(longlong)*(int *)(lVar1 + 0x10),lVar1,
                         *(undefined4 *)(lVar1 + 0x14));
        (*DAT_14000b250)(param_1,lVar3,uVar2,*(undefined4 *)(lVar1 + 0x10),
                         *(undefined4 *)(lVar1 + 0x14));
      }
      else {
        if (*(int *)(lVar3 + 0x1c) == 0) {
          LOCK();
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
          UNLOCK();
        }
        (*DAT_14000b260)(param_1,0x10000001,0x3361435f,(longlong)*(int *)(lVar1 + 0x10),lVar1,
                         *(undefined4 *)(lVar1 + 0x14));
        plVar8 = (longlong *)(lVar1 + 0x28);
        plVar7 = *(longlong **)(lVar3 + 200);
        if (*plVar7 != lVar3 + 0xc0) {
          pcVar4 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar4)(3);
        }
        *plVar8 = lVar3 + 0xc0;
        *(longlong **)(lVar1 + 0x30) = plVar7;
        *plVar7 = (longlong)plVar8;
        *(longlong **)(lVar3 + 200) = plVar8;
      }
    }
  }
  return;
}



===== UhciGetErrorFromTD @ 140002ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciGetErrorFromTD(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(uint *)(param_2 + 4) & 0x7e0000) == 0) {
    if ((*(uint *)(param_2 + 4) & 0x7ff) == 0x7ff) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(uint *)(param_2 + 4) & 0x7ff) + 1;
    }
    uVar4 = *(uint *)(param_2 + 8) >> 0x15;
    uVar3 = 0;
    if (uVar4 != 0x7ff) {
      uVar3 = uVar4 + 1;
    }
    if ((uVar1 < uVar3) && ((*(uint *)(param_2 + 4) >> 0x19 & 1) == 0)) {
      (*DAT_14000b260)(param_1,0x10000001,0x5468735f,0,0,0);
      uVar2 = 0x80000900;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (((*(uint *)(param_2 + 4) >> 0x16 & 1) != 0) && ((*(uint *)(param_2 + 4) >> 0x14 & 1) != 0))
    {
      (*DAT_14000b260)(param_1,0x10000001,0x6c62625f,0,0,0);
      return 0xc000000c;
    }
    if (((*(uint *)(param_2 + 4) >> 0x12 & 1) == 0) || ((*(uint *)(param_2 + 4) >> 0x16 & 1) == 0))
    {
      if (((*(uint *)(param_2 + 4) >> 0x12 & 1) == 0) || ((*(uint *)(param_2 + 4) & 0x7ff) == 0x7ff)
         ) {
        if (((*(uint *)(param_2 + 4) >> 0x12 & 1) == 0) ||
           ((*(uint *)(param_2 + 4) & 0x7ff) != 0x7ff)) {
          if ((*(uint *)(param_2 + 4) >> 0x15 & 1) == 0) {
            if ((*(uint *)(param_2 + 4) >> 0x16 & 1) == 0) {
              (*DAT_14000b260)(param_1,0x10000001,0x456e695f,0,0,0);
              uVar2 = 0x80000800;
            }
            else {
              (*DAT_14000b260)(param_1,0x10000001,0x6c74735f,0,0,0);
              uVar2 = 0xc0000004;
            }
          }
          else {
            (*DAT_14000b260)(param_1,0x10000001,0x6f74645f);
            uVar2 = 0xc0000008;
          }
        }
        else {
          (*DAT_14000b260)(param_1,0x10000001,0x6472635f,0,0,0);
          uVar2 = 0xc0000005;
        }
      }
      else {
        (*DAT_14000b260)(param_1,0x10000001,0x6372635f,0,0,0);
        uVar2 = 0xc0000001;
      }
    }
    else {
      (*DAT_14000b260)(param_1,0x10000001,0x726e645f,0,0,0);
      uVar2 = 0xc0000005;
    }
  }
  return uVar2;
}



===== UhciGet32BitFrameNumber @ 140002d10 =====

void UhciGet32BitFrameNumber(longlong param_1)

{
  ushort uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x2b8) == 0) {
    uVar1 = in((short)*(undefined8 *)(param_1 + 8) + 6);
    uVar2 = ((*(uint *)(param_1 + 0x44) ^ uVar1 & 0x7ff) & 0x400) + *(uint *)(param_1 + 0x44) |
            uVar1 & 0x7ff;
  }
  else {
    uVar2 = *(int *)(param_1 + 700) + 1;
  }
  *(uint *)(param_1 + 700) = uVar2;
  return;
}



===== UhciCleanOutIsoch @ 140002d60 =====

void UhciCleanOutIsoch(longlong param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x4c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 != 0) {
    LOCK();
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    UNLOCK();
    return;
  }
  uVar4 = UhciGet32BitFrameNumber(param_1);
  uVar5 = *(uint *)(param_1 + 0x48);
  if (((uVar4 - uVar5) - 0x400 < 0x7fffffff) || (param_2 != '\0')) {
    uVar5 = 0;
    lVar6 = 0;
    do {
      while (uVar5 == 0) {
        lVar6 = lVar6 + 4;
        **(undefined4 **)(param_1 + 0x78) = *(undefined4 *)(*(longlong *)(param_1 + 0x298) + 0x10);
        uVar5 = 1;
      }
      if ((uVar5 & 0x1f) == 0) {
        *(undefined4 *)(lVar6 + *(longlong *)(param_1 + 0x78)) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x2b0) + 0x10);
      }
      else {
        *(uint *)(lVar6 + *(longlong *)(param_1 + 0x78)) =
             *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar5 & 0x1f) + 0x1f) * 8) + 8) |
             2;
      }
      uVar5 = uVar5 + 1;
      lVar6 = lVar6 + 4;
    } while (uVar5 < 0x400);
  }
  else {
    while (uVar3 = uVar5 & 0x3ff, uVar3 != (uVar4 & 0x3ff)) {
      if (uVar3 == 0) {
        **(undefined4 **)(param_1 + 0x78) = *(undefined4 *)(*(longlong *)(param_1 + 0x298) + 0x10);
      }
      else if ((uVar5 & 0x1f) == 0) {
        *(undefined4 *)((ulonglong)uVar3 * 4 + *(longlong *)(param_1 + 0x78)) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x2b0) + 0x10);
      }
      else {
        *(uint *)((ulonglong)uVar3 * 4 + *(longlong *)(param_1 + 0x78)) =
             *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar5 & 0x1f) + 0x1f) * 8) + 8) |
             2;
      }
      uVar5 = uVar3 + 1;
    }
  }
  *(uint *)(param_1 + 0x48) = uVar4;
  LOCK();
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
  UNLOCK();
  return;
}



===== UhciUpdateCounter @ 140002ed0 =====

void UhciUpdateCounter(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = in((short)*(undefined8 *)(param_1 + 8) + 6);
  if ((((uint)uVar1 ^ *(uint *)(param_1 + 0x44)) >> 10 & 1) == 0) {
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) + 0x400;
  return;
}



===== UhciSubmitTransfer @ 140002f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong UhciSubmitTransfer(longlong param_1,longlong param_2,byte *param_3,undefined8 *param_4,
                            longlong param_5)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  int *piVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  longlong local_res8;
  undefined4 *local_38 [2];
  
  if (*(int *)(param_1 + 0x2b8) != 0) {
    return 1;
  }
  LOCK();
  *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + 1;
  UNLOCK();
  uVar11 = 1;
  if (*(int *)(param_2 + 0x1c) == 0) {
    LOCK();
    piVar8 = (int *)(param_1 + 0x3c);
    iVar10 = *piVar8;
    *piVar8 = *piVar8 + 1;
    UNLOCK();
    if (iVar10 == 0) {
      uVar6 = UhciGet32BitFrameNumber(param_1);
      *(undefined4 *)(param_1 + 0x48) = uVar6;
    }
  }
  uVar7 = 0;
  *param_4 = 0x72743031;
  param_4[2] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[3] = param_2;
  param_4[1] = param_3;
  iVar10 = *(int *)(param_2 + 0x1c);
  if (iVar10 != 2) {
    if (iVar10 == 1) {
      uVar7 = UhciControlTransfer(param_1,param_2,param_3,(longlong)param_4,param_5);
      return uVar7 & 0xffffffff;
    }
    if (iVar10 != 3) {
      return 0;
    }
  }
  uVar1 = *(ushort *)(param_2 + 0xc);
  (*DAT_14000b260)(param_1,0x10000001,0x5449425f,param_2,param_3,param_4);
  uVar2 = *(uint *)(param_5 + 0x18);
  uVar9 = (ulonglong)uVar2;
  iVar10 = 0;
  if (uVar2 != 0) {
    piVar8 = (int *)(param_5 + 0x30);
    do {
      iVar10 = iVar10 + *piVar8;
      piVar8 = piVar8 + 6;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    if (iVar10 != 0) {
      uVar5 = ((uVar1 - 1) + iVar10) / (uint)uVar1;
      goto LAB_140002fd7;
    }
  }
  uVar5 = 1;
LAB_140002fd7:
  if (((uint)(*(int *)(param_2 + 0x78) - *(int *)(param_2 + 0x80)) < uVar5) ||
     (((1 < uVar2 && (*(uint *)(param_5 + 0x30) % (uint)uVar1 != 0)) &&
      ((uint)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x98)) < iVar10 + 0xfffU >> 0xc)))) {
    LOCK();
    *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + -1;
    UNLOCK();
    if (*(int *)(param_2 + 0x1c) == 0) {
      LOCK();
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
      UNLOCK();
    }
    uVar7 = 1;
  }
  else {
    local_res8 = 0;
    local_38[0] = (undefined4 *)0x0;
    UhciMapAsyncTransferToTds(param_1,param_2,(longlong)param_4,&local_res8,local_38,param_5);
    puVar12 = local_38[0];
    lVar3 = local_res8;
    local_38[0][1] = local_38[0][1] | 0x1000000;
    *(undefined8 *)(local_38[0] + 0xc) = 0;
    *local_38[0] = 1;
    (*DAT_14000b260)(param_1,0x10000001,0x6c61545f,*(undefined4 *)((longlong)param_4 + 4),
                     *(undefined4 *)(local_res8 + 0x10),local_res8);
    if (*(longlong *)(param_2 + 0x68) == 0) {
      *(longlong *)(param_2 + 0x68) = lVar3;
      if ((*(uint *)(param_2 + 4) & 1) == 0) {
        uVar11 = *(uint *)(lVar3 + 0x10) & 0xfffffffc;
      }
      (*DAT_14000b260)(param_1,0x10000001,0x7471735f,lVar3,param_2,0);
      *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar11;
    }
    else {
      uVar11 = *(uint *)(lVar3 + 0x10);
      *(longlong *)(*(longlong *)(param_2 + 0x60) + 0x30) = lVar3;
      **(undefined4 **)(param_2 + 0x60) = *(undefined4 *)(lVar3 + 0x10);
      lVar3 = *(longlong *)(param_2 + 0x50);
      KeStallExecutionProcessor(0x14);
      (*DAT_14000b260)(param_1,0x10000001,0x6171745f,local_res8,*(uint *)(lVar3 + 4) & 0xfffffff8,
                       *(uint *)(local_res8 + 4) >> 0x17 & 1);
      lVar4 = *(longlong *)(param_2 + 0x60);
      (*DAT_14000b260)(param_1,0x10000001,0x6474745f,lVar4,*(undefined4 *)(lVar4 + 0x10),
                       *(uint *)(lVar4 + 4) >> 0x17 & 1);
      if ((((*(uint *)(*(longlong *)(param_2 + 0x60) + 4) >> 0x17 & 1) == 0) &&
          ((*(uint *)(lVar3 + 4) & 0xfffffff8) == 0)) &&
         ((*(uint *)(local_res8 + 4) >> 0x17 & 1) != 0)) {
        *(uint *)(lVar3 + 4) = uVar11 & 0xfffffffc;
        (*DAT_14000b260)(param_1,0x10000001,0x6b6c6e5f,local_res8,param_2,
                         *(undefined8 *)(param_2 + 0x68));
      }
      puVar12 = local_38[0];
    }
    if (*(int *)(param_2 + 0x1c) == 2) {
      **(uint **)(param_1 + 0x98) = **(uint **)(param_1 + 0x98) & 0xfffffffe;
    }
    *(undefined4 **)(param_2 + 0x60) = puVar12;
  }
  return uVar7;
}



===== UhciControlTransfer @ 1400032e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UhciControlTransfer(longlong param_1,longlong param_2,byte *param_3,longlong param_4,
                   longlong param_5)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  longlong local_38;
  uint *local_30;
  
  local_30 = (uint *)0x0;
  local_38 = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x5254435f,param_2,param_3,param_4);
  if (*(uint *)(param_2 + 0x58) < 2) {
    *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 1;
    uVar6 = 0;
    uVar7 = *(uint *)(param_2 + 0x7c);
    while (uVar6 < *(uint *)(param_2 + 0x78)) {
      puVar9 = (uint *)((ulonglong)uVar7 * 0x80 + *(longlong *)(param_2 + 0x70));
      if ((puVar9[10] & 1) == 0) {
        LOCK();
        puVar9[10] = puVar9[10] | 1;
        UNLOCK();
        (*DAT_14000b260)(param_1,0x10000001,0x4454615f,puVar9,0,0);
        *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
        *(uint *)(param_2 + 0x7c) = uVar7;
        goto LAB_1400033bd;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 1;
      if (*(uint *)(param_2 + 0x78) <= uVar7) {
        uVar7 = 0;
      }
    }
    (*DAT_14000b290)(param_1);
    puVar9 = (uint *)&DAT_deadfacedeadface;
LAB_1400033bd:
    puVar9[10] = puVar9[10] | 2;
    *(longlong *)(puVar9 + 6) = param_4;
    *puVar9 = 0;
    puVar9[1] = 0;
    uVar7 = 0;
    if (*(int *)(*(longlong *)(param_4 + 0x18) + 0x10) == 0) {
      uVar7 = 0x4000000;
    }
    puVar9[1] = puVar9[1] & 0xfbffffff | uVar7;
    puVar9[1] = puVar9[1] | 0x800000;
    puVar9[2] = 0;
    puVar9[1] = puVar9[1] | 0x18000000;
    uVar7 = (*(ushort *)(*(longlong *)(param_4 + 0x18) + 10) & 0xf) << 0xf;
    puVar9[2] = uVar7;
    uVar1 = *(ushort *)(*(longlong *)(param_4 + 0x18) + 8);
    puVar9[0xc] = 0;
    puVar9[0xd] = 0;
    puVar9[2] = (uVar1 & 0x7f) << 8 | uVar7;
    uVar6 = 0;
    uVar7 = *(uint *)(param_2 + 0x94);
    while (uVar6 < *(uint *)(param_2 + 0x90)) {
      puVar8 = (undefined8 *)((ulonglong)uVar7 * 0x60 + *(longlong *)(param_2 + 0x88));
      if ((*(uint *)((longlong)puVar8 + 0x54) & 1) == 0) {
        LOCK();
        *(uint *)((longlong)puVar8 + 0x54) = *(uint *)((longlong)puVar8 + 0x54) | 1;
        UNLOCK();
        (*DAT_14000b260)(param_1,0x10000001,0x4244615f,puVar8,0,0);
        *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + 1;
        *(uint *)(param_2 + 0x94) = uVar7;
        goto LAB_140003486;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 1;
      if (*(uint *)(param_2 + 0x90) <= uVar7) {
        uVar7 = 0;
      }
    }
    (*DAT_14000b290)(param_1);
    puVar8 = (undefined8 *)&DAT_deadfacedeadface;
LAB_140003486:
    *(undefined8 **)(puVar9 + 0xe) = puVar8;
    *puVar8 = *(undefined8 *)(param_3 + 0x14);
    puVar9[3] = *(uint *)(puVar8 + 8);
    LOCK();
    puVar9[10] = puVar9[10] | 0x20;
    UNLOCK();
    puVar9[2] = puVar9[2] & 0x1fffff | 0xe00000;
    *(undefined1 *)(puVar9 + 2) = 0x2d;
    puVar9[2] = puVar9[2] & 0xfff7ffff;
    (*DAT_14000b260)(param_1,0x10000001,0x7465735f,puVar9,(longlong)*(int *)(param_3 + 0x14),
                     (longlong)*(int *)(param_3 + 0x18));
    *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 1;
    uVar6 = 0;
    uVar7 = *(uint *)(param_2 + 0x7c);
    while (uVar6 < *(uint *)(param_2 + 0x78)) {
      puVar10 = (undefined4 *)((ulonglong)uVar7 * 0x80 + *(longlong *)(param_2 + 0x70));
      if ((puVar10[10] & 1) == 0) {
        LOCK();
        puVar10[10] = puVar10[10] | 1;
        UNLOCK();
        (*DAT_14000b260)(param_1,0x10000001,0x4454615f,puVar10,0,0);
        *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
        *(uint *)(param_2 + 0x7c) = uVar7;
        goto LAB_140003550;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 1;
      if (*(uint *)(param_2 + 0x78) <= uVar7) {
        uVar7 = 0;
      }
    }
    (*DAT_14000b290)(param_1);
    puVar10 = (undefined4 *)&DAT_deadfacedeadface;
LAB_140003550:
    puVar10[10] = puVar10[10] | 2;
    *(longlong *)(puVar10 + 6) = param_4;
    *puVar10 = 0;
    puVar10[1] = 0;
    uVar7 = 0;
    if (*(int *)(*(longlong *)(param_4 + 0x18) + 0x10) == 0) {
      uVar7 = 0x4000000;
    }
    puVar10[1] = puVar10[1] & 0xfbffffff | uVar7;
    puVar10[1] = puVar10[1] | 0x800000;
    puVar10[2] = 0;
    puVar10[1] = puVar10[1] | 0x18000000;
    local_38 = 0;
    local_30 = (uint *)0x0;
    uVar7 = (*(ushort *)(*(longlong *)(param_4 + 0x18) + 10) & 0xf) << 0xf;
    puVar10[2] = uVar7;
    puVar10[2] = (*(ushort *)(*(longlong *)(param_4 + 0x18) + 8) & 0x7f) << 8 | uVar7;
    *(undefined8 *)(puVar10 + 0xc) = 0;
    UhciMapAsyncTransferToTds(param_1,param_2,param_4,&local_38,&local_30,param_5);
    if ((local_38 == 0) || (local_30 == (uint *)0x0)) {
      uVar7 = puVar10[4];
      *(undefined4 **)(puVar9 + 0xc) = puVar10;
      *puVar9 = uVar7 & 0xfffffff8;
    }
    else {
      uVar7 = *(uint *)(local_38 + 0x10);
      *(longlong *)(puVar9 + 0xc) = local_38;
      *puVar9 = uVar7 & 0xfffffff8;
      *local_30 = puVar10[4] & 0xfffffff8;
      *(undefined4 **)(local_30 + 0xc) = puVar10;
    }
    puVar10[2] = puVar10[2] | 0xffe80000;
    puVar10[3] = 0;
    puVar10[1] = puVar10[1] | 0x1000000;
    LOCK();
    puVar10[10] = puVar10[10] | 0x400;
    UNLOCK();
    uVar7 = 1;
    uVar4 = 0xe1;
    if ((*param_3 & 1) == 0) {
      uVar4 = 0x69;
    }
    *(undefined1 *)(puVar10 + 2) = uVar4;
    *(undefined8 *)(puVar10 + 0xc) = 0;
    *puVar10 = 1;
    (*DAT_14000b260)(param_1,0x10000001,0x6c61545f,*(undefined4 *)(param_4 + 4),puVar9[4],puVar9);
    if (*(longlong *)(param_2 + 0x68) == 0) {
      *(uint **)(param_2 + 0x68) = puVar9;
      if ((*(uint *)(param_2 + 4) & 1) == 0) {
        uVar7 = puVar9[4] & 0xfffffffc;
      }
      (*DAT_14000b260)(param_1,0x10000001,0x7471735f,puVar9,param_2,0);
      *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar7;
    }
    else {
      uVar7 = puVar9[4];
      *(uint **)(*(longlong *)(param_2 + 0x60) + 0x30) = puVar9;
      **(uint **)(param_2 + 0x60) = puVar9[4];
      lVar2 = *(longlong *)(param_2 + 0x50);
      KeStallExecutionProcessor(0x14);
      (*DAT_14000b260)(param_1,0x10000001,0x6171745f,puVar9,*(uint *)(lVar2 + 4) & 0xfffffff8,
                       puVar9[1] >> 0x17 & 1);
      lVar3 = *(longlong *)(param_2 + 0x60);
      (*DAT_14000b260)(param_1,0x10000001,0x6474745f,lVar3,*(undefined4 *)(lVar3 + 0x10),
                       *(uint *)(lVar3 + 4) >> 0x17 & 1);
      if ((((*(uint *)(*(longlong *)(param_2 + 0x60) + 4) >> 0x17 & 1) == 0) &&
          ((*(uint *)(lVar2 + 4) & 0xfffffff8) == 0)) && ((puVar9[1] >> 0x17 & 1) != 0)) {
        *(uint *)(lVar2 + 4) = uVar7 & 0xfffffffc;
        (*DAT_14000b260)(param_1,0x10000001,0x6b6c6e5f,puVar9,param_2,
                         *(undefined8 *)(param_2 + 0x68));
      }
    }
    if (*(int *)(param_2 + 0x1c) == 2) {
      **(uint **)(param_1 + 0x98) = **(uint **)(param_1 + 0x98) & 0xfffffffe;
    }
    *(undefined4 **)(param_2 + 0x60) = puVar10;
    uVar5 = 0;
  }
  else {
    LOCK();
    *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + -1;
    UNLOCK();
    if (*(int *)(param_2 + 0x1c) == 0) {
      LOCK();
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
      UNLOCK();
    }
    uVar5 = 1;
  }
  return uVar5;
}



===== UhciMapAsyncTransferToTds @ 1400038c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint UhciMapAsyncTransferToTds
               (undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4,
               undefined8 *param_5,longlong param_6)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  void *_Src;
  ulonglong uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char cVar16;
  int local_74;
  uint local_70;
  uint local_6c;
  uint *local_60;
  undefined1 *local_58;
  
  local_74 = 0;
  uVar1 = *(ushort *)(param_2 + 0xc);
  local_70 = 0;
  local_58 = (undefined1 *)0x0;
  local_60 = (uint *)0x0;
  bVar5 = false;
  if ((*(int *)(param_6 + 0x18) == 0) && (*(int *)(param_2 + 0x1c) != 1)) {
    bVar4 = true;
    bVar6 = true;
  }
  else {
    bVar4 = false;
    bVar6 = false;
    if (*(int *)(param_2 + 0x1c) == 1) {
      uVar8 = 1;
      bVar3 = (byte)**(undefined4 **)(param_3 + 8) & 1;
      bVar6 = false;
      goto LAB_140003941;
    }
  }
  uVar8 = *(uint *)(param_2 + 0xa0);
  bVar3 = *(byte *)(param_2 + 10) & 0x80;
LAB_140003941:
  uVar14 = 0;
  cVar16 = 'i';
  local_6c = uVar8;
  if (bVar3 == 0) {
    cVar16 = -0x1f;
  }
  do {
    if ((*(uint *)(param_6 + 0x18) <= uVar14) && (!bVar4)) {
      *(uint *)(param_2 + 0xa0) = uVar8;
      *param_5 = local_60;
      return local_70;
    }
    uVar11 = (ulonglong)uVar14;
    (*DAT_14000b260)(param_1,0x10000001,0x6367735f,*(uint *)(param_6 + 0x18),uVar11,0);
    uVar15 = *(uint *)(param_6 + 0x20 + uVar11 * 0x18);
    uVar13 = *(uint *)(param_6 + 0x30 + uVar11 * 0x18);
    (*DAT_14000b260)(param_1,0x10000001,0x5867735f,uVar13,uVar11,uVar15);
    if (bVar5) {
      uVar15 = uVar15 + local_74;
      uVar13 = uVar13 - local_74;
    }
    local_74 = 0;
    bVar5 = false;
    while ((uVar13 != 0 || (bVar6))) {
      bVar6 = false;
      (*DAT_14000b260)(param_1,0x10000001,0x3167735f,uVar13,0,0);
      if (uVar13 < uVar1) {
        if (uVar14 + 1 < *(uint *)(param_6 + 0x18)) {
          (*DAT_14000b260)(param_1,0x10000001,0x3267735f,uVar13,0,0);
          bVar5 = true;
          local_74 = *(int *)(param_6 + ((ulonglong)(uVar14 + 1) + 2) * 0x18);
          uVar8 = local_74 + uVar13;
          if (uVar1 <= uVar8) {
            local_74 = uVar1 - uVar13;
            uVar8 = (uint)uVar1;
          }
          local_58 = UhciAllocDb(param_1,param_2,'\0');
          _Src = (void *)(*(longlong *)(param_6 + 0x10) + (ulonglong)local_70);
          *(void **)(local_58 + 0x48) = _Src;
          if ((uVar8 < 0x41) && (*(uint *)(local_58 + 0x58) = uVar8, cVar16 == -0x1f)) {
            memmove(local_58,_Src,(ulonglong)uVar8);
          }
          uVar15 = *(uint *)(local_58 + 0x40);
          uVar10 = 0;
        }
        else {
          (*DAT_14000b260)(param_1,0x10000001,0x3367735f,uVar13,0,0);
          uVar10 = 0;
          uVar8 = uVar13;
        }
      }
      else {
        (*DAT_14000b260)(param_1,0x10000001,0x3467735f,uVar13,0,0);
        uVar10 = uVar13 - uVar1;
        uVar8 = (uint)uVar1;
      }
      uVar13 = uVar10;
      uVar9 = 0;
      *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
      uVar10 = *(uint *)(param_2 + 0x7c);
      while (uVar9 < *(uint *)(param_2 + 0x78)) {
        puVar12 = (uint *)((ulonglong)uVar10 * 0x80 + *(longlong *)(param_2 + 0x70));
        if ((puVar12[10] & 1) == 0) {
          LOCK();
          puVar12[10] = puVar12[10] | 1;
          UNLOCK();
          (*DAT_14000b260)(param_1,0x10000001,0x4454615f,puVar12,0,0);
          *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + 1;
          *(uint *)(param_2 + 0x7c) = uVar10;
          goto LAB_140003b33;
        }
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 + 1;
        if (*(uint *)(param_2 + 0x78) <= uVar10) {
          uVar10 = 0;
        }
      }
      (*DAT_14000b290)(param_1);
      puVar12 = (uint *)&DAT_deadfacedeadface;
LAB_140003b33:
      puVar12[10] = puVar12[10] | 2;
      *(longlong *)(puVar12 + 6) = param_3;
      *puVar12 = 0;
      puVar12[1] = 0;
      uVar10 = 0;
      if (*(int *)(*(longlong *)(param_3 + 0x18) + 0x10) == 0) {
        uVar10 = 0x4000000;
      }
      puVar12[1] = puVar12[1] & 0xfbffffff | uVar10;
      puVar12[1] = puVar12[1] | 0x800000;
      puVar12[2] = 0;
      puVar12[1] = puVar12[1] | 0x18000000;
      uVar10 = (*(ushort *)(*(longlong *)(param_3 + 0x18) + 10) & 0xf) << 0xf;
      puVar12[2] = uVar10;
      uVar2 = *(ushort *)(*(longlong *)(param_3 + 0x18) + 8);
      iVar7 = 0x7ff;
      puVar12[0xc] = 0;
      puVar12[0xd] = 0;
      puVar12[2] = (uVar2 & 0x7f) << 8 | uVar10;
      *(char *)(puVar12 + 2) = cVar16;
      if (uVar8 != 0) {
        iVar7 = uVar8 - 1;
      }
      uVar10 = puVar12[2] & 0x1fffff | iVar7 << 0x15;
      puVar12[2] = (local_6c << 0x13 ^ uVar10) & 0x80000 ^ uVar10;
      puVar12[1] = puVar12[1] | 0x20000000;
      puVar12[3] = uVar15;
      puVar12[1] = puVar12[1] | 0x7ff;
      if (bVar5) {
        LOCK();
        puVar12[10] = puVar12[10] | 0x20;
        UNLOCK();
        *(undefined1 **)(puVar12 + 0xe) = local_58;
      }
      local_70 = local_70 + uVar8;
      uVar15 = uVar15 + uVar8;
      if (local_60 == (uint *)0x0) {
        *param_4 = puVar12;
      }
      else {
        uVar8 = puVar12[4];
        *(uint **)(local_60 + 0xc) = puVar12;
        *local_60 = uVar8 & 0xfffffff8;
      }
      uVar8 = (uint)(local_6c == 0);
      local_6c = uVar8;
      local_60 = puVar12;
    }
    uVar14 = uVar14 + 1;
    bVar4 = false;
  } while( true );
}



===== UhciInterruptDpcEx @ 140003da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 UhciInterruptDpcEx(longlong param_1,char param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  uint *puVar7;
  undefined4 local_res10 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  LOCK();
  uVar3 = *(uint *)(param_1 + 0x6c);
  *(uint *)(param_1 + 0x6c) = 0;
  UNLOCK();
  uVar6 = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x7064695f,uVar3,0,0);
  if ((uVar3 & 3) != 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x5045695f,uVar3,0,0);
    (*DAT_14000b248)(param_1,0);
  }
  sVar5 = (short)uVar1;
  if ((uVar3 & 4) == 0) {
    uVar4 = 0;
    local_res10[0] = 0;
    do {
      puVar7 = (uint *)(param_1 + 0x68);
      uVar2 = in((uVar4 + 8) * 2 + sVar5);
      if (((uVar2 & 0x1040) == 0x1040) && ((*puVar7 >> (uVar4 & 0x1f) & 1) == 0)) {
        (*DAT_14000b260)(param_1,0x10000001,0x6773725f,uVar4 + 1,uVar2,param_1);
        uVar3 = 1 << ((byte)uVar4 & 0x1f);
        *puVar7 = *puVar7 | uVar3;
        puVar7 = (uint *)(param_1 + 100);
        *puVar7 = *puVar7 & ~uVar3;
        if (*puVar7 == 0) {
          *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) =
               *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) & 0xfeffffff;
        }
        local_res10[0] = CONCAT22(local_res10[0]._2_2_,uVar4 + 1);
        (*DAT_14000b270)(param_1,0x14,local_res10,4,UhciRHClearFeaturePortSuspendComplete);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 2);
  }
  else {
    (*DAT_14000b260)(param_1,0x10000001,0x5245695f,uVar3,0,0);
    uVar6 = 1;
  }
  if (param_2 != '\0') {
    (*DAT_14000b260)(param_1,0x10000001,0x4545695f,0,0,0);
    out(sVar5 + 4,*(undefined2 *)(param_1 + 0x38));
  }
  return uVar6;
}



===== UhciGetEndpointStatus @ 140003fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint UhciGetEndpointStatus(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 4) & 1;
  sVar3 = (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar3);
  uVar2 = in(sVar3 + 2);
  if (((uVar1 != 0xffff) && ((uVar2 & 0x20) != 0)) && ((uVar1 & 1) == 0)) {
    uVar4 = 0x65;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x7365675f,param_2,uVar4,0);
  return uVar4;
}



===== UhciCheckController @ 140004050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciCheckController(longlong param_1)

{
  short sVar1;
  
  sVar1 = in((short)*(undefined8 *)(param_1 + 8) + 2);
  if (((sVar1 == -1) || (0xf < *(uint *)(param_1 + 0x10))) && (*(int *)(param_1 + 0x2b8) == 0)) {
    *(undefined4 *)(param_1 + 0x2b8) = 1;
    (*DAT_14000b288)(param_1,2);
  }
  return;
}



===== UhciFixDataToggle @ 1400040b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciFixDataToggle(undefined8 param_1,longlong param_2,longlong param_3,uint param_4)

{
  (*DAT_14000b260)(param_1,0x10000001,0x7464465f,param_2,param_4,0);
  if (param_3 == 0) {
    *(uint *)(param_2 + 0xa0) = param_4;
  }
  else {
    do {
      *(uint *)(param_3 + 8) =
           (param_4 << 0x13 ^ *(uint *)(param_3 + 8)) & 0x80000 ^ *(uint *)(param_3 + 8);
      param_3 = *(longlong *)(param_3 + 0x30);
      param_4 = (uint)(param_4 == 0);
    } while (param_3 != 0);
    *(uint *)(param_2 + 0xa0) = param_4;
  }
  return;
}



===== UhciAllocDb @ 140004150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 * UhciAllocDb(undefined8 param_1,longlong param_2,char param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x94);
  uVar1 = 0;
  do {
    if (*(uint *)(param_2 + 0x90) <= uVar1) {
      (*DAT_14000b290)();
      return &DAT_deadfacedeadface;
    }
    if (param_3 == '\0') {
      puVar2 = (undefined1 *)((ulonglong)uVar3 * 0x60 + *(longlong *)(param_2 + 0x88));
      if ((*(uint *)(puVar2 + 0x54) & 1) == 0) {
        LOCK();
        *(uint *)(puVar2 + 0x54) = *(uint *)(puVar2 + 0x54) | 1;
        UNLOCK();
        (*DAT_14000b260)(param_1,0x10000001,0x4244615f,puVar2,0,0);
        *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + 1;
        *(uint *)(param_2 + 0x94) = uVar3;
        return puVar2;
      }
    }
    else {
      puVar2 = (undefined1 *)((ulonglong)uVar3 * 0x420 + *(longlong *)(param_2 + 0x88));
      if ((*(uint *)(puVar2 + 0x414) & 1) == 0) {
        LOCK();
        *(uint *)(puVar2 + 0x414) = *(uint *)(puVar2 + 0x414) | 1;
        UNLOCK();
        (*DAT_14000b260)(param_1,0x10000001,0x4244695f,puVar2,0,0);
        *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + 1;
        *(uint *)(param_2 + 0x94) = uVar3;
        return puVar2;
      }
    }
    uVar3 = uVar3 + 1;
    uVar1 = uVar1 + 1;
    if (*(uint *)(param_2 + 0x90) <= uVar3) {
      uVar3 = 0;
    }
  } while( true );
}



===== UhciResumeController @ 140004290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UhciResumeController(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  uint *puVar6;
  byte *pbVar7;
  undefined *puVar8;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  int local_98;
  undefined2 local_94 [6];
  undefined8 local_88;
  undefined8 uStack_80;
  int *local_78;
  undefined8 uStack_70;
  undefined2 *local_68;
  undefined8 uStack_60;
  longlong local_58;
  undefined8 uStack_50;
  longlong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = &local_88;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = (int *)0x0;
  uStack_70 = 0;
  local_68 = (undefined2 *)0x0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_DISPATCH,0,1);
  LOCK();
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
  UNLOCK();
  puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE;
  local_98 = 0;
  sVar4 = (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar4);
  if (uVar1 == 0xffff) {
    local_98 = 7;
    puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE_ERROR_1;
  }
  else if ((uVar1 & 8) == 0) {
    local_98 = 7;
    puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE_ERROR_2;
  }
  else {
    uVar5 = 0;
    puVar6 = (uint *)(param_1 + 0x30);
    do {
      uVar1 = in(((short)uVar5 + 8) * 2 + sVar4);
      *puVar6 = (uint)uVar1;
      if ((uVar1 >> 0xb & 1) != 0) {
        local_98 = 7;
        puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE_ERROR_5;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < 2);
    if (local_98 == 0) {
      sVar3 = sVar4 + 6;
      out(sVar3,*(undefined2 *)(param_1 + 0x1e));
      out(sVar4 + 8,*(undefined4 *)(param_1 + 0x20));
      uVar1 = in(sVar4);
      out(sVar4,uVar1 | 0x10);
      (*DAT_14000b280)(param_1,0x14);
      uVar1 = in(sVar4);
      out(sVar4,uVar1 & 0xffe7);
      uVar5 = 0;
      uVar1 = in(sVar4);
      if ((uVar1 & 0x10) != 0) {
        do {
          if (9 < uVar5) break;
          KeStallExecutionProcessor(0x32);
          uVar1 = in(sVar4);
          uVar5 = uVar5 + 1;
        } while ((uVar1 & 0x10) != 0);
        if ((uVar1 & 0x10) != 0) {
          local_98 = 7;
          puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE_ERROR_3;
          goto LAB_140004516;
        }
      }
      out(sVar4,*(ushort *)(param_1 + 0x1c) | 1);
      uVar1 = in(sVar3);
      (*DAT_14000b280)(param_1,5);
      uVar2 = in(sVar3);
      if (((uVar2 ^ uVar1) & 0x7ff) == 0) {
        local_98 = 7;
        puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_RESUME_COMPLETE_ERROR_4;
      }
      else {
        if ((*(uint *)(param_1 + 4) & 4) != 0) {
          uVar5 = 0;
          do {
            sVar3 = ((short)uVar5 + 8) * 2 + sVar4;
            uVar1 = in(sVar3);
            if (((byte)uVar1 & 5) != 5) {
              out(sVar3,uVar1 & 0xeff5);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < 2);
        }
        if ((*(uint *)(param_1 + 4) & 8) != 0) {
          uVar5 = 0;
          pbVar7 = (byte *)(param_1 + 0x28);
          do {
            uVar1 = in(((short)uVar5 + 8) * 2 + sVar4);
            if (((((byte)uVar1 ^ *pbVar7) & 1) != 0) && ((uVar1 & 2) == 0)) {
              *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 1 << ((byte)uVar5 & 0x1f);
            }
            uVar5 = uVar5 + 1;
            pbVar7 = pbVar7 + 4;
          } while (uVar5 < 2);
        }
      }
    }
  }
LAB_140004516:
  local_88 = 0;
  local_94[0] = 2;
  local_78 = &local_98;
  uStack_60 = 2;
  local_68 = local_94;
  local_a8 = &local_88;
  local_58 = param_1 + 0x28;
  local_48 = param_1 + 0x30;
  uStack_80 = 0;
  uStack_70 = 4;
  uStack_50 = 8;
  uStack_40 = 8;
  (*DAT_14000b400)(param_1,puVar8,0,5);
  return local_98;
}



===== __report_gsfailure @ 1400045c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== DriverEntry @ 1400045d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(longlong param_1,undefined8 param_2)

{
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  _DAT_14000b2d0 = 0;
  _DAT_14000b470 = UhciPreStartController;
  _DAT_14000b0c8 = UhciStartController;
  _DAT_14000b0d0 = UhciStopController;
  _DAT_14000b140 = UhciEnableInterrupts;
  _DAT_14000b148 = UhciDisableInterrupts;
  _DAT_14000b0e8 = UhciInterruptService;
  _DAT_14000b0f0 = UhciInterruptDpc;
  _DAT_14000b0d8 = UhciSuspendController;
  _DAT_14000b0e0 = UhciResumeController;
  _DAT_14000b1f8 = _guard_check_icall;
  _DAT_14000b200 = _guard_check_icall;
  _DAT_14000b178 = UhciRHGetRootHubData;
  _DAT_14000b180 = UhciRHGetStatus;
  _DAT_14000b190 = UhciRHGetHubStatus;
  _DAT_14000b188 = UhciRHGetPortStatus;
  _DAT_14000b198 = UhciRHSetFeaturePortReset;
  _DAT_14000b1a8 = UhciRHSetFeaturePortEnable;
  _DAT_14000b1a0 = UhciRHSetFeaturePortPower;
  _DAT_14000b1b0 = UhciRHSetFeaturePortSuspend;
  _DAT_14000b1c8 = UhciRHClearFeaturePortSuspend;
  _DAT_14000b1b8 = UhciRHClearFeaturePortEnable;
  _DAT_14000b1c0 = UhciRHSetFeaturePortPower;
  _DAT_14000b1d8 = UhciRHClearFeaturePortConnectChange;
  _DAT_14000b1e0 = UhciRHClearFeaturePortResetChange;
  _DAT_14000b1d0 = UhciRHClearFeaturePortEnableChange;
  _DAT_14000b1e8 = UhciRHClearFeaturePortSuspendChange;
  _DAT_14000b1f0 = UhciRHClearFeaturePortOvercurrentChange;
  _DAT_14000b168 = UhciSetEndpointStatus;
  _DAT_14000b160 = UhciGetEndpointStatus;
  _DAT_14000b158 = UhciSetEndpointDataToggle;
  _DAT_14000b0a8 = UhciOpenEndpoint;
  _DAT_14000b0b0 = UhciPokeEndpoint;
  _DAT_14000b0b8 = UhciQueryEndpointRequirements;
  _DAT_14000b090 = 0x2c0;
  _DAT_14000b094 = 0xd0;
  _DAT_14000b098 = 0x38;
  _DAT_14000b0a4 = 0x2500;
  _DAT_14000b0c0 = UhciCloseEndpoint;
  _DAT_14000b084 = 0x2c3;
  _DAT_14000b120 = UhciPollEndpoint;
  _RegistrationPacket = 2;
  _DAT_14000b118 = UhciSetEndpointState;
  _DAT_14000b088 = 12000;
  _DAT_14000b110 = UhciGetEndpointState;
  _DAT_14000b130 = UhciGet32BitFrameNumber;
  _DAT_14000b150 = UhciPollController;
  _DAT_14000b128 = UhciCheckController;
  _DAT_14000b138 = UhciInterruptNextSOF;
  _DAT_14000b0f8 = UhciSubmitTransfer;
  _DAT_14000b100 = UhciIsochTransfer;
  _DAT_14000b108 = UhciAbortTransfer;
  _DAT_14000b208 = UhciStartSendOnePacket;
  _DAT_14000b210 = UhciEndSendOnePacket;
  _DAT_14000b218 = UhciPassThru;
  _DAT_14000b2a8 = UhciFlushInterrupts;
  _DAT_14000b318 = UhciInterruptDpcEx;
  _DAT_14000b3d8 = UhciHaltController;
  _DAT_14000b3c0 = UhciDbgFreeEndpointEndpoint;
  *(undefined8 *)(param_1 + 0x68) = 0;
  USBPORT_RegisterUSBPortDriver(param_1,500,&RegistrationPacket,param_2);
  return;
}



===== UhciAbortTransfer @ 140004990 =====

void UhciAbortTransfer(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  
  LOCK();
  *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + -1;
  UNLOCK();
  if (*(int *)(param_2 + 0x1c) == 0) {
    LOCK();
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    UNLOCK();
  }
  iVar1 = *(int *)(param_2 + 0x1c);
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
    UhciAbortAsyncTransfer(param_1,param_2,param_3,param_4);
  }
  else {
    UhciAbortIsochTransfer(param_1,param_2,(longlong)param_3);
  }
  return;
}



===== UhciCloseEndpoint @ 1400049e0 =====

void UhciCloseEndpoint(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0xb8) = 5;
  return;
}



===== UhciDbgFreeEndpointEndpoint @ 140004a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciDbgFreeEndpointEndpoint(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  (*DAT_14000b260)(param_1,0x10000001,0x4662645f,param_2,0,0);
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 != 0) {
    if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 3)) {
      (*DAT_14000b290)(param_1);
      return;
    }
    **(undefined4 **)(param_2 + 0x50) = 0xffffffff;
  }
  return;
}



===== UhciEndSendOnePacket @ 140004a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UhciEndSendOnePacket
          (longlong param_1,undefined8 param_2,void *param_3,uint *param_4,undefined4 *param_5,
          undefined8 param_6,undefined8 param_7,int *param_8)

{
  bool bVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  uint *puVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar7 = 0;
  uVar6 = 0;
  bVar1 = false;
  puVar5 = *(uint **)(param_5 + 2);
  (*DAT_14000b260)(param_1,0x10000001,0x4573735f,puVar5,0,0);
  do {
    iVar4 = (int)uVar6;
    if (bVar1) {
LAB_140004b8c:
      if (*param_8 != -0x3fff0000) {
        LOCK();
        **(undefined4 **)(param_1 + 0x88) = *param_5;
        UNLOCK();
      }
      if (((puVar5[1] >> 0x17 & 1) == 0) || (*param_8 == -0x3fff0000)) {
        if (((char)puVar5[2] == 'i') &&
           (((uVar7 != 0 && (uVar7 <= *param_4)) && (*(void **)(param_5 + 4) != (void *)0x0)))) {
          memmove(param_3,*(void **)(param_5 + 4),(ulonglong)uVar7);
        }
        *param_4 = uVar7;
        (*DAT_14000b260)(param_1,0x10000001,0x5873735f,puVar5,uVar7,0);
        uVar3 = 0;
        *param_8 = iVar4;
      }
      else {
        *param_8 = -0x3fff0000;
LAB_140004b80:
        uVar3 = 1;
      }
      return uVar3;
    }
    if ((puVar5[1] >> 0x17 & 1) != 0) {
      if (((puVar5[2] & 0x78000) == 0) && (*param_8 == 0)) goto LAB_140004b80;
      iVar4 = -0x3fff0000;
      goto LAB_140004b8c;
    }
    uVar2 = UhciGetErrorFromTD(param_1,(longlong)puVar5);
    uVar6 = uVar2 & 0xffffffff;
    if ((int)uVar2 == -0x7ffff700) {
      if ((puVar5[1] & 0x7ff) == 0x7ff) {
        iVar4 = 0;
      }
      else {
        iVar4 = (puVar5[1] & 0x7ff) + 1;
      }
      uVar7 = uVar7 + iVar4;
      uVar6 = 0;
LAB_140004b6a:
      bVar1 = true;
    }
    else {
      if ((int)uVar2 != 0) {
        if ((puVar5[1] & 0x7ff) == 0x7ff) {
          iVar4 = 0;
        }
        else {
          iVar4 = (puVar5[1] & 0x7ff) + 1;
        }
        uVar7 = uVar7 + iVar4;
        goto LAB_140004b6a;
      }
      if ((puVar5[1] & 0x7ff) == 0x7ff) {
        iVar4 = 0;
      }
      else {
        iVar4 = (puVar5[1] & 0x7ff) + 1;
      }
      uVar7 = uVar7 + iVar4;
      if ((*puVar5 & 1) != 0) goto LAB_140004b6a;
      puVar5 = puVar5 + 4;
    }
  } while( true );
}



===== UhciGetEndpointState @ 140004c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UhciGetEndpointState(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 3;
  if (*(int *)(param_2 + 0x1c) == 0) {
    iVar2 = *(int *)(param_2 + 0xb8);
  }
  else {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0x50) + 0x10);
    if ((uVar1 & 1) == 0) {
      iVar2 = (-(uint)((uVar1 & 2) != 0) & 2) + 2;
    }
  }
  (*DAT_14000b260)(param_1,0x10000001,0x7365675f,param_2,0,(longlong)iVar2);
  return iVar2;
}



===== UhciGetIdleStatus @ 140004ca4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 UhciGetIdleStatus(longlong param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x3173695f,param_2,param_3,0);
  if ((param_2 < 4) || (param_3 == (uint *)0x0)) {
    uVar1 = 5;
  }
  else {
    uVar2 = ~(*(uint *)(param_1 + 4) >> 1) & 1;
    *param_3 = uVar2;
    uVar1 = 0;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x5873695f,uVar2,uVar1,0);
  return uVar1;
}



===== UhciHaltController @ 140004d50 =====

ushort UhciHaltController(longlong param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)*(undefined8 *)(param_1 + 8);
  uVar1 = in(uVar2);
  out(uVar2,uVar1 & 0xfffe);
  return uVar1 & 0xfffe;
}



===== UhciInitializeHardware @ 140004d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciInitializeHardware(longlong param_1)

{
  undefined8 uVar1;
  short sVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint local_res8 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  if (*(int *)(param_1 + 0x40) == 0x108) {
    local_res8[0] = local_res8[0] & 0xffffff00;
    (*DAT_14000b278)(param_1,1,local_res8,0x42,1);
    local_res8[0] = local_res8[0] | 7;
    (*DAT_14000b278)(param_1,0,local_res8,0x42,1);
  }
  if (*(int *)(param_1 + 0x40) < 0xff) {
    local_res8[0] = 0;
    (*DAT_14000b278)(param_1,1,local_res8,0x40,4);
    local_res8[0] = local_res8[0] | 0x40;
    (*DAT_14000b278)(param_1,0,local_res8,0x40,4);
  }
  sVar2 = (short)uVar1;
  uVar3 = in(sVar2 + 0xc);
  *(undefined1 *)(param_1 + 0x2a0) = uVar3;
  (*DAT_14000b280)(param_1,0x14);
  uVar4 = in(sVar2);
  (*DAT_14000b260)(param_1,0x10000001,0x7365725f,uVar4,0,0);
  out(sVar2,4);
  (*DAT_14000b280)(param_1,0x14);
  out(sVar2,0);
  out(sVar2,0x80);
  out(sVar2 + 0xc,*(undefined1 *)(param_1 + 0x2a0));
  *(ushort *)(param_1 + 0x38) = *(ushort *)(param_1 + 0x38) | 0xf;
  return 0;
}



===== UhciInitializeSchedule @ 140004ee8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 UhciInitializeSchedule(longlong param_1,uint *param_2,uint param_3)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  char *pcVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined8 *puVar16;
  ulonglong uVar17;
  undefined1 auStack_a8 [32];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  pcVar4 = local_88;
  puVar16 = (undefined8 *)(param_1 + 0xa0);
  local_88[0x30] = '\x10';
  local_88[0x31] = '\x11';
  local_88[0x32] = '\x12';
  local_88[0x33] = '\x13';
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\x01';
  local_88[4] = '\x02';
  local_88[5] = '\x01';
  local_88[6] = '\x02';
  local_88[7] = '\x03';
  local_88[8] = '\x04';
  local_88[9] = '\x05';
  local_88[10] = '\x06';
  local_88[0xb] = '\x03';
  local_88[0xc] = '\x04';
  local_88[0xd] = '\x05';
  local_88[0xe] = '\x06';
  local_88[0xf] = '\a';
  local_88[0x20] = '\x10';
  local_88[0x21] = '\x11';
  local_88[0x22] = '\x12';
  local_88[0x23] = '\x13';
  local_88[0x24] = '\x14';
  local_88[0x25] = '\x15';
  local_88[0x26] = '\x16';
  local_88[0x27] = '\x17';
  local_88[0x28] = '\x18';
  local_88[0x29] = '\x19';
  local_88[0x2a] = '\x1a';
  local_88[0x2b] = '\x1b';
  local_88[0x2c] = '\x1c';
  local_88[0x2d] = '\x1d';
  local_88[0x2e] = '\x1e';
  local_88[0x2f] = '\x0f';
  lVar11 = 8;
  local_88[0x34] = '\x14';
  local_88[0x35] = '\x15';
  local_88[0x36] = '\x16';
  local_88[0x37] = '\x17';
  local_88[0x10] = '\b';
  local_88[0x11] = '\t';
  local_88[0x12] = '\n';
  local_88[0x13] = '\v';
  local_88[0x14] = '\f';
  local_88[0x15] = '\r';
  local_88[0x16] = '\x0e';
  local_88[0x17] = '\a';
  local_88[0x18] = '\b';
  local_88[0x19] = '\t';
  local_88[0x1a] = '\n';
  local_88[0x1b] = '\v';
  local_88[0x1c] = '\f';
  local_88[0x1d] = '\r';
  local_88[0x1e] = '\x0e';
  local_88[0x1f] = '\x0f';
  local_88[0x38] = '\x18';
  local_88[0x39] = '\x19';
  local_88[0x3a] = '\x1a';
  local_88[0x3b] = '\x1b';
  local_88[0x3c] = '\x1c';
  local_88[0x3d] = '\x1d';
  local_88[0x3e] = 0x1e;
  lVar10 = 0x3f;
  do {
    lVar8 = lVar10;
    puVar5 = param_2;
    memset(puVar5,0,0x40);
    cVar1 = *pcVar4;
    puVar5[2] = param_3;
    puVar5[1] = puVar5[1] | 1;
    puVar5[3] = 0x71693031;
    *puVar16 = puVar5;
    UhciSetNextQh(param_1,puVar5,*(longlong *)(param_1 + 0xa0 + (longlong)cVar1 * 8));
    param_2 = puVar5 + 0x10;
    param_3 = param_3 + 0x40;
    puVar16 = puVar16 + 1;
    pcVar4 = pcVar4 + 1;
    lVar10 = lVar8 + -1;
  } while (lVar10 != 0);
  iVar14 = (int)lVar8;
  uVar15 = iVar14 + 0x3f;
  uVar17 = (ulonglong)uVar15;
  memset(param_2,0,uVar17);
  puVar5[0x12] = param_3;
  puVar5[0x11] = puVar5[0x11] | 1;
  puVar5[0x13] = 0x71613031;
  UhciSetNextQh(param_1,*(uint **)(param_1 + 0xa0),(longlong)param_2);
  *(uint **)(param_1 + 0x88) = param_2;
  puVar5 = (uint *)((longlong)param_2 + uVar17);
  uVar12 = param_3 + uVar15;
  memset(puVar5,0,(ulonglong)uVar15);
  puVar5[2] = uVar12;
  puVar5[3] = 0x71623031;
  *puVar5 = uVar12 | 3;
  UhciSetNextQh(param_1,param_2,(longlong)puVar5);
  *(uint **)(param_1 + 0x90) = puVar5;
  uVar9 = iVar14 + 1;
  *(uint **)(param_1 + 0x98) = puVar5;
  uVar3 = 0;
  piVar6 = (int *)((longlong)puVar5 + uVar17);
  iVar13 = uVar12 + uVar15;
  uVar12 = iVar14 + 0x7f;
  uVar17 = (ulonglong)uVar12;
  lVar10 = 0;
  piVar6[4] = iVar13;
  piVar6[2] = -0x1f8000;
  *piVar6 = iVar13;
  *(undefined1 *)(piVar6 + 2) = 0xe1;
  piVar6[10] = uVar9;
  piVar6[3] = 0xbadf00d;
  piVar6[1] = 0;
  piVar6[1] = piVar6[1] & 0xff7fffff;
  piVar6[1] = piVar6[1] & 0xe7ffffff;
  piVar6[1] = piVar6[1] & 0xfeffffff;
  piVar6[1] = piVar6[1] | 0x2000000;
  piVar6[0xc] = 0;
  piVar6[0xd] = 0;
  puVar5 = (uint *)((longlong)piVar6 + uVar17);
  *(int *)(*(longlong *)(param_1 + 0x90) + 4) = piVar6[4];
  uVar15 = 0;
  do {
    uVar7 = uVar15 + 1;
    *(uint *)(lVar10 + *(longlong *)(param_1 + 0x78)) =
         *(uint *)(*(longlong *)(param_1 + 0xa0 + (ulonglong)((uVar15 & 0x1f) + 0x1f) * 8) + 8) |
         uVar9;
    lVar10 = lVar10 + 4;
    uVar15 = uVar7;
  } while (uVar7 < 0x400);
  memset(puVar5,0,uVar17);
  puVar5[4] = iVar13 + uVar12;
  puVar5[5] = 0x64746c72;
  puVar5[1] = puVar5[1] & 0xff7fffff;
  lVar8 = 0;
  puVar5[1] = puVar5[1] | 0x1000000;
  uVar15 = *(uint *)(*(longlong *)(param_1 + 0x198) + 8);
  puVar5[3] = 0xbadf00d;
  *puVar5 = uVar15 | uVar9;
  *(undefined1 *)(puVar5 + 2) = 0x69;
  *(uint **)(param_1 + 0x298) = puVar5;
  lVar10 = (longlong)puVar5 + uVar17;
  iVar14 = iVar13 + uVar12 + uVar12;
  *(longlong *)(param_1 + 0x2a8) = lVar10;
  do {
    lVar2 = *(longlong *)(param_1 + 0x2a8);
    *(int *)(lVar8 + 0x10 + lVar2) = iVar14;
    *(undefined8 *)(lVar8 + 0x14 + lVar2) = 0x64746f73;
    iVar14 = iVar14 + uVar12;
    *(uint *)(lVar8 + 4 + lVar2) = *(uint *)(lVar8 + 4 + lVar2) & 0xff7fffff;
    *(uint *)(lVar8 + 4 + lVar2) = *(uint *)(lVar8 + 4 + lVar2) | 0x1000000;
    uVar15 = *(uint *)(*(longlong *)(param_1 + 0x198) + 8);
    *(undefined4 *)(lVar8 + 0xc + lVar2) = 0xbadf00d;
    *(uint *)(lVar8 + lVar2) = uVar15 | uVar9;
    lVar8 = lVar8 + uVar17;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  puVar5 = (uint *)(lVar10 + 0x400);
  memset(puVar5,0,uVar17);
  *(int *)(lVar10 + 0x410) = iVar14;
  *(undefined4 *)(lVar10 + 0x414) = 0x64746572;
  *(uint *)(lVar10 + 0x404) = *(uint *)(lVar10 + 0x404) & 0xff7fffff;
  *(uint *)(lVar10 + 0x404) = *(uint *)(lVar10 + 0x404) & 0xfeffffff;
  uVar12 = *(uint *)(*(longlong *)(param_1 + 0x198) + 8);
  *(undefined4 *)(lVar10 + 0x40c) = 0xbadf00d;
  *puVar5 = uVar12 | uVar9;
  *(undefined1 *)(lVar10 + 0x408) = 0x69;
  *(uint **)(param_1 + 0x2b0) = puVar5;
  do {
    iVar14 = uVar3 + 1;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x78) + (ulonglong)(uint)(iVar14 * 0x20) * 4) =
         *(undefined4 *)(lVar10 + 0x410);
  } while (uVar3 < 0x1f);
  return 0;
}



===== UhciOpenEndpoint @ 140005240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciOpenEndpoint(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *_Dst;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  longlong lVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int local_res10 [2];
  
  uVar6 = 0x10000001;
  local_res10[0] = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x43706f5f,0,0,param_2);
  *param_3 = 0x70653031;
  puVar1 = param_3 + 0x2a;
  uVar2 = param_2[1];
  *(undefined8 *)(param_3 + 2) = *param_2;
  *(undefined8 *)(param_3 + 4) = uVar2;
  uVar2 = param_2[3];
  *(undefined8 *)(param_3 + 6) = param_2[2];
  *(undefined8 *)(param_3 + 8) = uVar2;
  uVar2 = param_2[5];
  *(undefined8 *)(param_3 + 10) = param_2[4];
  *(undefined8 *)(param_3 + 0xc) = uVar2;
  uVar2 = param_2[7];
  *(undefined8 *)(param_3 + 0xe) = param_2[6];
  *(undefined8 *)(param_3 + 0x10) = uVar2;
  *(undefined8 *)(param_3 + 0x12) = param_2[8];
  param_3[1] = 0;
  param_3[0x16] = 0;
  *(undefined4 **)(param_3 + 0x2c) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_3 + 0x30;
  *(undefined4 **)(param_3 + 0x32) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  param_3[0x28] = 0;
  if (*(uint *)((longlong)param_2 + 0x14) < 2) {
    LOCK();
    param_3[1] = param_3[1] | 4;
    UNLOCK();
  }
  iVar9 = *(int *)((longlong)param_2 + 0x2c);
  lVar8 = param_2[4];
  iVar7 = *(int *)(param_2 + 5);
  if (*(int *)((longlong)param_2 + 0x14) != 0) {
    *(longlong *)(param_3 + 0x14) = lVar8;
    *(int *)(lVar8 + 8) = iVar7;
    *(uint *)(lVar8 + 4) = *(uint *)(lVar8 + 4) | 1;
    iVar7 = iVar7 + 0x40;
    *(undefined4 **)(lVar8 + 0x28) = param_3;
    *(undefined4 *)(lVar8 + 0xc) = 0x68713031;
    *(longlong *)(lVar8 + 0x20) = lVar8;
    *(longlong *)(lVar8 + 0x18) = lVar8;
    lVar8 = lVar8 + 0x40;
    iVar9 = iVar9 + -0x40;
  }
  *(longlong *)(param_3 + 0x22) = lVar8;
  param_3[0x26] = 0;
  iVar11 = *(int *)((longlong)param_2 + 0x14);
  if (iVar11 == 0) {
    UhciQueryIsoRequirements(param_1,uVar6,local_res10,param_3 + 0x24);
  }
  else if (iVar11 == 1) {
    UhciQueryControlRequirements(param_1,(longlong)param_2,local_res10,param_3 + 0x24);
  }
  else if (iVar11 == 2) {
    UhciQueryBulkRequirements(param_1,(longlong)param_2,local_res10,param_3 + 0x24);
  }
  else {
    if (iVar11 != 3) {
      return 6;
    }
    UhciQueryInterruptRequirements(param_1,(longlong)param_2,local_res10,param_3 + 0x24);
  }
  puVar10 = param_3 + 0x24;
  iVar11 = (-(uint)(*(int *)((longlong)param_2 + 0x14) != 0) & 0xfffffc40) + 0x420;
  memset(*(void **)(param_3 + 0x22),0,(ulonglong)(iVar11 * *puVar10));
  uVar5 = 0;
  if (*puVar10 != 0) {
    do {
      if (*(int *)((longlong)param_2 + 0x14) == 0) {
        lVar4 = (ulonglong)uVar5 * 0x420;
        *(int *)(lVar4 + 0x400 + *(longlong *)(param_3 + 0x22)) = iVar7;
        *(undefined4 *)(lVar4 + 0x410 + *(longlong *)(param_3 + 0x22)) = 0x69643031;
      }
      else {
        lVar4 = (ulonglong)uVar5 * 0x60;
        *(int *)(lVar4 + 0x40 + *(longlong *)(param_3 + 0x22)) = iVar7;
        *(undefined4 *)(lVar4 + 0x50 + *(longlong *)(param_3 + 0x22)) = 0x62643031;
      }
      iVar7 = iVar7 + iVar11;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar10);
  }
  param_3[0x20] = 0;
  uVar5 = iVar9 - iVar11 * *puVar10 >> 7;
  param_3[0x1e] = uVar5;
  _Dst = (void *)((ulonglong)(iVar11 * *puVar10) + lVar8);
  *(void **)(param_3 + 0x1c) = _Dst;
  memset(_Dst,0,(ulonglong)uVar5 << 7);
  uVar5 = 0;
  if (param_3[0x1e] != 0) {
    do {
      uVar3 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      lVar8 = uVar3 * 0x80 + *(longlong *)(param_3 + 0x1c);
      *(int *)(lVar8 + 0x10) = iVar7;
      iVar7 = iVar7 + 0x80;
      *(undefined4 *)(lVar8 + 0x14) = 0x64743031;
      *(undefined1 **)(lVar8 + 0x18) = &DAT_deadfacedeadface;
    } while (uVar5 < (uint)param_3[0x1e]);
  }
  *(undefined8 *)(param_3 + 0x18) = 0;
  *(undefined8 *)(param_3 + 0x1a) = 0;
  return 0;
}



===== UhciPassThru @ 1400054f0 =====

undefined4 UhciPassThru(longlong param_1,longlong *param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *param_2 + -0x4b0a0e27e1b9c71c;
  if (lVar2 == 0) {
    lVar2 = param_2[1] + 0x122cd06396de7c7d;
  }
  if (lVar2 == 0) {
    uVar1 = UhciGetIdleStatus(param_1,param_3,param_4);
  }
  else {
    uVar1 = 6;
  }
  return uVar1;
}



===== UhciPokeEndpoint @ 140005540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciPokeEndpoint(undefined4 param_1,undefined8 *param_2,longlong param_3)

{
  undefined8 uVar1;
  
  (*DAT_14000b260)(param_1,0x10000001,0x6b6f505f,param_3,param_2,0);
  uVar1 = param_2[1];
  *(undefined8 *)(param_3 + 8) = *param_2;
  *(undefined8 *)(param_3 + 0x10) = uVar1;
  uVar1 = param_2[3];
  *(undefined8 *)(param_3 + 0x18) = param_2[2];
  *(undefined8 *)(param_3 + 0x20) = uVar1;
  uVar1 = param_2[5];
  *(undefined8 *)(param_3 + 0x28) = param_2[4];
  *(undefined8 *)(param_3 + 0x30) = uVar1;
  uVar1 = param_2[7];
  *(undefined8 *)(param_3 + 0x38) = param_2[6];
  *(undefined8 *)(param_3 + 0x40) = uVar1;
  *(undefined8 *)(param_3 + 0x48) = param_2[8];
  return 0;
}



===== UhciPreStartController @ 1400055c0 =====

undefined8 UhciPreStartController(void)

{
  return 0xc0000002;
}



===== UhciQueryBulkRequirements @ 1400055d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UhciQueryBulkRequirements(undefined8 param_1,longlong param_2,int *param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0x2000 / (ulonglong)*(ushort *)(param_2 + 4);
  iVar3 = (int)uVar1;
  *param_4 = 3;
  pcVar2 = DAT_14000b260;
  iVar4 = iVar3 * 0x80 + 0x160;
  *param_3 = iVar3;
  (*pcVar2)(param_1,0x10000001,0x4265515f,iVar4,uVar1,3);
  return iVar4;
}



===== UhciQueryControlRequirements @ 140005634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UhciQueryControlRequirements(undefined8 param_1,longlong param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_2 + 0x34);
  iVar4 = uVar1 / *(ushort *)(param_2 + 4) + 2;
  *param_3 = iVar4;
  iVar3 = (uVar1 + 0xfff >> 0xc) + 1;
  *param_4 = iVar3;
  iVar2 = iVar4 * 0x80 + iVar3 * 0x60 + 0x40;
  (*DAT_14000b260)(param_1,0x10000001,0x4365515f,iVar2,iVar4,iVar3);
  return iVar2;
}



===== UhciQueryEndpointRequirements @ 1400056c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciQueryEndpointRequirements(undefined8 param_1,longlong param_2,int *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint local_res10 [2];
  int local_res18 [4];
  
  iVar1 = *(int *)(param_2 + 0x34);
  local_res18[0] = 0;
  local_res10[0] = 0;
  param_3[1] = iVar1;
  uVar2 = 0x10000001;
  (*DAT_14000b260)(param_1,0x10000001,0x7065515f,iVar1,(longlong)*(int *)(param_2 + 0x14),0);
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0) {
    uVar2 = UhciQueryIsoRequirements(param_1,uVar2,local_res18,local_res10);
    iVar1 = (int)uVar2;
    param_3[1] = 0x10000;
  }
  else if (iVar1 == 1) {
    iVar1 = UhciQueryControlRequirements(param_1,param_2,local_res18,(int *)local_res10);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        *param_3 = 0;
        param_3[1] = 0;
        return 6;
      }
      iVar1 = UhciQueryInterruptRequirements(param_1,param_2,local_res18,local_res10);
      *param_3 = iVar1;
      param_3[1] = (uint)*(ushort *)(param_2 + 4) << 3;
      goto LAB_1400057a2;
    }
    iVar1 = UhciQueryBulkRequirements(param_1,param_2,local_res18,local_res10);
    param_3[1] = 0x1000;
  }
  *param_3 = iVar1;
LAB_1400057a2:
  (*DAT_14000b260)(param_1,0x10000001,0x5245515f,local_res18[0],local_res10[0],iVar1);
  return 0;
}



===== UhciQueryInterruptRequirements @ 1400057e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UhciQueryInterruptRequirements
              (undefined8 param_1,longlong param_2,undefined4 *param_3,uint *param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_2 + 4);
  *param_3 = 0x10;
  uVar2 = (uint)uVar1 * 0x10 + 0x1ffe >> 0xc;
  *param_4 = uVar2;
  iVar3 = (uVar2 + 0x16) * 0x60;
  (*DAT_14000b260)(param_1,0x10000001,0x4965515f,iVar3,0x10,uVar2);
  return iVar3;
}



===== UhciQueryIsoRequirements @ 140005848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UhciQueryIsoRequirements
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  
  *param_4 = 0x10;
  pcVar1 = DAT_14000b260;
  *param_3 = 0x200;
  (*pcVar1)(param_1,0x10000001,0x4965515f,0x14200,0x200,0x10);
  return 0x14200;
}



===== UhciSetEndpointDataToggle @ 1400058a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciSetEndpointDataToggle(undefined8 param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  
  if (1 < *(uint *)(param_2 + 0x1c)) {
    for (lVar1 = *(longlong *)(param_2 + 0x68); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x30)) {
      *(uint *)(lVar1 + 8) =
           (param_3 << 0x13 ^ *(uint *)(lVar1 + 8)) & 0x80000 ^ *(uint *)(lVar1 + 8);
      param_3 = (uint)(param_3 == 0);
    }
    *(uint *)(param_2 + 0xa0) = param_3;
    (*DAT_14000b260)(param_1,0x10000001,0x6774735f,param_2,0,param_3);
  }
  return;
}



===== UhciSetEndpointState @ 140005920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciSetEndpointState(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  
  (*DAT_14000b260)(param_1,0x10000001,0x7365735f,param_2,0,(longlong)param_3);
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 0) {
    (*DAT_14000b260)(param_1,0x10000001,0x7369535f,param_2,(longlong)param_3,0);
  }
  else if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
    UhciSetAsyncEndpointState(param_1,param_2,param_3);
  }
  else {
    (*DAT_14000b290)(param_1);
  }
  *(int *)(param_2 + 0xb8) = param_3;
  return;
}



===== UhciSetEndpointStatus @ 1400059f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciSetEndpointStatus(undefined8 param_1,longlong param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  
  (*DAT_14000b260)(param_1,0x10000001,0x7465735f,param_2,(longlong)param_3,0);
  if ((param_3 == 0) && (uVar1 = 1, (*(uint *)(param_2 + 4) & 1) != 0)) {
    LOCK();
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffe;
    UNLOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    if (lVar2 == 0) {
      *(undefined8 *)(param_2 + 0x60) = 0;
      lVar2 = 0;
      *(undefined8 *)(param_2 + 0x68) = 0;
    }
    else {
      *(longlong *)(param_2 + 0x68) = lVar2;
      if ((*(uint *)(param_2 + 4) & 1) == 0) {
        uVar1 = *(uint *)(lVar2 + 0x10) & 0xfffffffc;
      }
    }
    (*DAT_14000b260)(param_1,0x10000001,0x7471735f,lVar2,param_2,0);
    *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar1;
  }
  return;
}



===== UhciSetNextQh @ 140005ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciSetNextQh(undefined8 param_1,uint *param_2,longlong param_3)

{
  (*DAT_14000b260)(param_1,0x10000001,0x516e735f,0,param_2,param_3);
  *(uint **)(param_3 + 0x20) = param_2;
  *param_2 = *(uint *)(param_3 + 8) | 2;
  *(longlong *)(param_2 + 6) = param_3;
  LOCK();
  *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | 1;
  UNLOCK();
  return;
}



===== UhciStartController @ 140005b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UhciStartController(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  longlong lVar2;
  short sVar3;
  ushort uVar4;
  undefined8 uVar5;
  uint uVar6;
  short sVar7;
  undefined *puVar8;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined8 local_70;
  int local_58 [2];
  undefined8 local_50;
  undefined8 uStack_48;
  int *local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_78 = &local_50;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (int *)0x0;
  uStack_38 = 0;
  (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_DISPATCH,0,1);
  puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_COMPLETE;
  LOCK();
  param_1[1] = param_1[1] & 0xfffffffd;
  UNLOCK();
  if (((byte)*param_2 & 5) == 5 || ((byte)*param_2 & 6) == 6) {
    *param_1 = 0x69636875;
    iVar1 = param_2[1];
    param_1[0x10] = iVar1;
    *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 10);
    if ((((iVar1 == 0xc9) || (iVar1 == 0xfb)) || (iVar1 == 0xfc)) ||
       (((iVar1 == 0xfd || (iVar1 == 0xfe)) || (iVar1 == 0x108)))) {
      LOCK();
      param_1[1] = param_1[1] | 4;
      UNLOCK();
    }
    LOCK();
    param_1[1] = param_1[1] | 8;
    UNLOCK();
    uVar5 = UhciStopBIOS((longlong)param_1,(longlong)param_2);
    local_58[0] = (int)uVar5;
    if (local_58[0] == 0) {
      uVar5 = UhciInitializeHardware((longlong)param_1);
      local_58[0] = (int)uVar5;
      if (local_58[0] == 0) {
        lVar2 = *(longlong *)(param_2 + 0xe);
        iVar1 = param_2[0x10];
        *(longlong *)(param_1 + 0x1e) = lVar2;
        param_1[0x20] = iVar1;
        uVar5 = UhciInitializeSchedule((longlong)param_1,(uint *)(lVar2 + 0x1000),iVar1 + 0x1000);
        local_58[0] = (int)uVar5;
        if (local_58[0] == 0) {
          param_1[0x13] = 0;
          local_70 = 0;
          local_78 = (undefined8 *)0x0;
          sVar3 = (short)*(undefined8 *)(param_1 + 2);
          out(sVar3 + 8,param_1[0x20]);
          uVar4 = in(sVar3);
          (*DAT_14000b260)(param_1,0x10000001,0x6e75725f,uVar4);
          out(sVar3,uVar4 | 1);
          uVar6 = 0;
          do {
            sVar7 = ((short)uVar6 + 8) * 2 + sVar3;
            uVar6 = uVar6 + 1;
            uVar4 = in(sVar7);
            out(sVar7,uVar4 & 0xeffd);
          } while (uVar6 < 2);
          **(undefined4 **)(param_1 + 0x1e) = *(undefined4 *)(*(longlong *)(param_1 + 0xa6) + 0x10);
        }
        else {
          puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_COMPLETE_ERROR_4;
        }
      }
      else {
        puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_COMPLETE_ERROR_3;
      }
    }
    else {
      puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_COMPLETE_ERROR_2;
    }
  }
  else {
    local_58[0] = 4;
    puVar8 = &USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_START_COMPLETE_ERROR_1;
  }
  local_50 = 0;
  local_40 = local_58;
  uStack_48 = 0;
  local_78 = &local_50;
  uStack_38 = 4;
  (*DAT_14000b400)(param_1,puVar8,0,2);
  return local_58[0];
}



===== UhciStartSendOnePacket @ 140005d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
UhciStartSendOnePacket
          (longlong param_1,byte *param_2,void *param_3,uint *param_4,uint *param_5,int param_6,
          uint param_7,undefined4 *param_8)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *_Dst;
  uint *puVar10;
  
  uVar6 = *param_4;
  if (uVar6 == 0) {
    uVar7 = 1;
  }
  else {
    uVar2 = uVar6 / *(ushort *)(param_2 + 2);
    uVar7 = uVar2 + 1;
    if (uVar6 <= *(ushort *)(param_2 + 2) * uVar2) {
      uVar7 = uVar2;
    }
  }
  if (param_7 < uVar6 + 0x28 + uVar7 * 0x10) {
    uVar4 = 2;
  }
  else {
    (*DAT_14000b260)(param_1,0x10000001,0x5373735f,param_6,0,param_5);
    uVar6 = param_6 + 0x20;
    puVar9 = param_5 + 8;
    puVar10 = puVar9 + (ulonglong)uVar7 * 4;
    uVar7 = uVar6 + uVar7 * 0x10;
    if (*param_4 == 0) {
      _Dst = (uint *)0x0;
      uVar2 = 0;
    }
    else {
      _Dst = puVar10 + 2;
      uVar2 = uVar7 + 8;
      memmove(_Dst,param_3,(ulonglong)*param_4);
    }
    (*DAT_14000b260)(param_1,0x10000001,0x4473735f,param_3,*param_4,0);
    puVar10[0] = 0;
    puVar10[1] = 0;
    *puVar10 = 1;
    puVar10[1] = uVar6;
    puVar10[1] = puVar10[1] & 0xfffffffe;
    puVar10[1] = puVar10[1] & 0xfffffffd;
    puVar10[1] = puVar10[1] & 0xfffffffb;
    *(uint **)(param_5 + 4) = _Dst;
    *(uint **)(param_5 + 2) = puVar9;
    param_7 = *(uint *)(param_2 + 0x10);
    uVar8 = *param_4;
    (*DAT_14000b260)(param_1,0x10000001,0x3273735f,puVar9,param_5,puVar10);
    (*DAT_14000b260)(param_1,0x10000001,0x3373735f,uVar2,_Dst,*param_4);
    while( true ) {
      uVar6 = uVar6 + 0x10;
      puVar9[0] = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[1] = puVar9[1] | 0x800000;
      puVar9[1] = puVar9[1] & 0xfeffffff;
      puVar9[1] = puVar9[1] & 0xfdffffff;
      uVar5 = 0;
      if (*(int *)(param_2 + 0xc) == 0) {
        uVar5 = 0x4000000;
      }
      puVar9[1] = puVar9[1] & 0xfbffffff | uVar5;
      puVar9[1] = puVar9[1] | 0x18000000;
      puVar9[1] = puVar9[1] | 0x20000000;
      uVar5 = ((uint)*param_2 << 8 ^ puVar9[2]) & 0x7f00 ^ puVar9[2];
      puVar9[2] = uVar5;
      uVar5 = ((uint)param_2[1] << 0xf ^ uVar5) & 0x78000 ^ uVar5;
      uVar5 = (param_7 << 0x13 ^ uVar5) & 0x80000 ^ uVar5;
      puVar9[2] = uVar5;
      uVar1 = *(ushort *)(param_2 + 2);
      if ((int)uVar8 < (int)(uint)uVar1) {
        iVar3 = 0x7ff;
        if (uVar8 != 0) {
          iVar3 = uVar8 - 1;
        }
      }
      else if (uVar1 == 0) {
        iVar3 = 0x7ff;
      }
      else {
        iVar3 = uVar1 - 1;
      }
      puVar9[2] = uVar5 & 0x1fffff | iVar3 << 0x15;
      iVar3 = *(int *)(param_2 + 8);
      if (iVar3 == 0) {
        (*DAT_14000b260)(param_1,0x10000001,0x5573735f,0,0,0);
        *(undefined1 *)(puVar9 + 2) = 0x2d;
      }
      else if (iVar3 == 1) {
        (*DAT_14000b260)(param_1,0x10000001,0x4973735f,0,0,0);
        *(undefined1 *)(puVar9 + 2) = 0x69;
      }
      else if (iVar3 == 2) {
        (*DAT_14000b260)(param_1,0x10000001,0x4f73735f,0,0,0);
        *(undefined1 *)(puVar9 + 2) = 0xe1;
      }
      puVar9[3] = uVar2;
      *puVar9 = uVar6 & 0xfffffffd | 4;
      if ((int)uVar8 <= (int)(uint)*(ushort *)(param_2 + 2)) break;
      *puVar9 = uVar6 & 0xfffffffc | 4;
      puVar9 = puVar9 + 4;
      uVar8 = uVar8 - *(ushort *)(param_2 + 2);
      uVar2 = uVar2 + *(ushort *)(param_2 + 2);
      param_7 = (uint)(param_7 == 0);
    }
    *puVar9 = uVar6 & 0xfffffffd | 5;
    LOCK();
    uVar6 = **(uint **)(param_1 + 0x88);
    **(uint **)(param_1 + 0x88) = uVar7 & 0xfffffff2 | 2;
    UNLOCK();
    *param_5 = uVar6;
    *param_8 = 0;
    uVar4 = 0;
  }
  return uVar4;
}



===== UhciStopController @ 140006150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UhciStopController(longlong param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar1 = *(undefined8 *)(param_1 + 8);
  local_48 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_STOP_DISPATCH,0,1);
  local_40 = 0;
  local_48 = (undefined8 *)0x0;
  uVar3 = (undefined2)uVar1;
  uVar2 = in(uVar3);
  if (uVar2 == 0xffff) {
    (*DAT_14000b260)(param_1,0x10000001,0x4777685f);
  }
  else {
    (*DAT_14000b260)(param_1,0x10000001,0x7074735f,uVar2);
    if ((uVar2 & 4) != 0) {
      uVar2 = uVar2 & 0xfffb;
      out(uVar3,uVar2);
    }
    out(uVar3,uVar2 | 2);
    do {
      uVar2 = in(uVar3);
      if ((uVar2 & 2) == 0) break;
    } while (_DAT_fffff78000000014 < _DAT_fffff78000000014 + 100000);
    local_48 = &local_28;
    local_28 = 0;
    uStack_20 = 0;
    (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_STOP_COMPLETE,0,1);
  }
  return;
}



===== UhciSuspendController @ 1400062a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UhciSuspendController(longlong param_1)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint *puVar6;
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = &local_48;
  local_48 = 0;
  uStack_40 = 0;
  (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_SUSPEND_DISPATCH,0,1);
  LOCK();
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  UNLOCK();
  sVar1 = (short)*(undefined8 *)(param_1 + 8);
  uVar5 = in(sVar1 + 8);
  puVar6 = (uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x20) = uVar5 & 0xfffff000;
  uVar3 = in(sVar1 + 6);
  *(ushort *)(param_1 + 0x1e) = uVar3 & 0x7ff;
  uVar5 = 0;
  do {
    sVar2 = (short)uVar5;
    uVar5 = uVar5 + 1;
    uVar3 = in((sVar2 + 8) * 2 + sVar1);
    *puVar6 = (uint)uVar3;
    puVar6 = puVar6 + 1;
  } while (uVar5 < 2);
  uVar5 = 0;
  uVar3 = in(sVar1);
  *(ushort *)(param_1 + 0x1c) = uVar3;
  out(sVar1,uVar3 & 0xfffe);
  do {
    uVar4 = in(sVar1 + 2);
    if ((uVar4 & 0x20) != 0) break;
    (*DAT_14000b280)(param_1,1);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 10);
  if ((uVar4 & 0x20) == 0) {
    out(sVar1,uVar3 & 0xfffe | 4);
    (*DAT_14000b280)(param_1,10);
    out(sVar1,uVar3 & 0xfffa);
    out(sVar1 + 4,*(undefined2 *)(param_1 + 0x38));
  }
  uVar3 = in(sVar1);
  local_58 = &local_48;
  out(sVar1,uVar3 & 0xffef | 8);
  local_48 = 0;
  uStack_40 = 0;
  (*DAT_14000b400)(param_1,&USBPORT_ETW_EVENT_HC_UHCI_MINIPORT_SUSPEND_COMPLETE,0,1);
  return;
}



===== UhciRHClearFeaturePortConnectChange @ 140006460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHClearFeaturePortConnectChange(longlong param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar2);
  (*DAT_14000b260)(param_1,0x10000001,0x6363705f,uVar1,0,param_2);
  if ((uVar1 & 2) != 0) {
    out(sVar2,uVar1 & 0xfff7 | 2);
  }
  *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) & ~(1 << ((char)param_2 - 1U & 0x1f));
  return 0;
}



===== UhciRHClearFeaturePortEnable @ 140006500 =====

void UhciRHClearFeaturePortEnable(longlong param_1,short param_2)

{
  UhciRHPortEnable(param_1,param_2,0);
  return;
}



===== UhciRHClearFeaturePortEnableChange @ 140006520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHClearFeaturePortEnableChange(longlong param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  
  (*DAT_14000b260)(param_1,0x10000001,0x6570635f,param_2,0,0);
  sVar2 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar2);
  out(sVar2,uVar1 & 0xfffd | 8);
  return 0;
}



===== UhciRHClearFeaturePortOvercurrentChange @ 140006590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHClearFeaturePortOvercurrentChange(longlong param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  
  if (*(int *)(param_1 + 0x40) == 0xc9) {
    sVar2 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
    uVar1 = in(sVar2);
    (*DAT_14000b260)(param_1,0x10000001,0x764f635f,uVar1,0,param_2);
    if ((uVar1 & 0x800) != 0) {
      out(sVar2,uVar1 & 0xfff5 | 0x800);
    }
  }
  return 0;
}



===== UhciRHSetFeaturePortPower @ 140006620 =====

undefined8 UhciRHSetFeaturePortPower(void)

{
  return 0;
}



===== UhciRHClearFeaturePortResetChange @ 140006630 =====

undefined8 UhciRHClearFeaturePortResetChange(longlong param_1,char param_2)

{
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & ~(1 << (param_2 - 1U & 0x1f));
  return 0;
}



===== UhciRHClearFeaturePortSuspend @ 140006650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHClearFeaturePortSuspend(longlong param_1,short param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort uVar3;
  uint uVar4;
  short sVar5;
  short local_res10 [4];
  
  local_res10[0] = 0;
  local_res10[1] = 0;
  uVar2 = *(undefined8 *)(param_1 + 8);
  uVar4 = 1 << ((char)param_2 - 1U & 0x1f);
  puVar1 = (uint *)(param_1 + 100);
  *puVar1 = *puVar1 & ~uVar4;
  if (*puVar1 == 0) {
    *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) =
         *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) & 0xfeffffff;
  }
  sVar5 = (param_2 + 7) * 2 + (short)uVar2;
  uVar3 = in(sVar5);
  (*DAT_14000b260)(param_1,0x10000001,0x7370725f,uVar3,0,param_2);
  if ((*(uint *)(param_1 + 4) & 4) == 0) {
    if ((uVar3 & 0x40) == 0) {
      *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | uVar4;
      uVar3 = uVar3 & 0xfff5 | 0x40;
      out(sVar5,uVar3);
    }
    local_res10[0] = param_2;
    (*DAT_14000b270)(param_1,0x14,local_res10,4,UhciRHClearFeaturePortSuspendComplete);
  }
  else {
    (*DAT_14000b260)(param_1,0x10000001,0x6f70725f,uVar3,0,param_2);
  }
  (*DAT_14000b260)(param_1,0x10000001,0x7365725f,uVar3,0,param_2);
  return 0;
}



===== UhciRHClearFeaturePortSuspendChange @ 1400067b0 =====

undefined8 UhciRHClearFeaturePortSuspendChange(longlong param_1,char param_2)

{
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & ~(1 << (param_2 - 1U & 0x1f));
  return 0;
}



===== UhciRHClearFeaturePortSuspendComplete @ 1400067d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciRHClearFeaturePortSuspendComplete(longlong param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  short sVar4;
  
  sVar1 = *param_2;
  sVar4 = (sVar1 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar2 = in(sVar4);
  (*DAT_14000b260)(param_1,0x10000001,0x5372705f,uVar2,*(undefined4 *)(param_1 + 0x58),sVar1);
  out(sVar4,uVar2 & 0xefb5);
  uVar3 = 1 << ((char)sVar1 - 1U & 0x1f);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | uVar3;
  *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & ~uVar3;
  (*DAT_14000b240)(param_1,sVar4);
  return;
}



===== UhciRHGetHubStatus @ 140006880 =====

undefined8 UhciRHGetHubStatus(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}



===== UhciRHGetPortStatus @ 140006890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHGetPortStatus(longlong param_1,short param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = in((param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8));
  *param_3 = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x3170505f,param_2,uVar1,0);
  uVar3 = (*param_3 ^ (uint)uVar1) & 1 ^ *param_3;
  uVar3 = (uVar1 >> 1 ^ uVar3) & 2 ^ uVar3;
  uVar2 = uVar3 | 4;
  if ((uVar1 & 0x1004) != 0x1004) {
    uVar2 = uVar3 & 0xfffffffb;
  }
  *param_3 = uVar2;
  if (*(int *)(param_1 + 0x40) == 0xc9) {
    uVar2 = (uVar1 >> 7 ^ uVar2) & 8 ^ uVar2;
    uVar2 = ((uint)uVar1 << 8 ^ uVar2) & 0x80000 ^ uVar2;
    uVar2 = ((ushort)~uVar1 >> 2 ^ uVar2) & 0x100 ^ uVar2;
  }
  else {
    uVar2 = uVar2 & 0xfff7fff7 | 0x100;
  }
  uVar2 = ((uVar1 & 0x100) * 2 ^ ((uVar1 >> 5 ^ uVar2) & 0x10 ^ uVar2) & 0xfffffdff) & 0xfffffbff;
  uVar2 = ((uint)uVar1 << 0xf ^ uVar2) & 0x10000 ^ uVar2;
  *param_3 = uVar2;
  uVar3 = 1 << ((char)param_2 - 1U & 0x1f);
  if ((*(uint *)(param_1 + 0x60) & uVar3) != 0) {
    uVar2 = uVar2 | 0x10000;
    *param_3 = uVar2;
  }
  if ((*(uint *)(param_1 + 0x50) & uVar3) == 0) {
    uVar2 = uVar2 ^ ((uint)uVar1 << 0xe ^ uVar2) & 0x20000;
  }
  else {
    uVar2 = uVar2 & 0xfffcffff;
  }
  *param_3 = uVar2;
  if ((*(uint *)(param_1 + 0x58) & uVar3) != 0) {
    uVar2 = uVar2 | 0x40000;
    *param_3 = uVar2;
  }
  if ((*(uint *)(param_1 + 0x54) & uVar3) != 0) {
    uVar2 = uVar2 | 0x100000;
    *param_3 = uVar2;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x7370675f,param_2,uVar2,uVar1);
  return 0;
}



===== UhciRHGetRootHubData @ 140006a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciRHGetRootHubData(longlong param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  
  *(undefined2 *)(param_2 + 1) = 3;
  *param_2 = 2;
  uVar1 = 0xb;
  if (*(int *)(param_1 + 0x40) != 0xc9) {
    uVar1 = 0x1b;
  }
  *(undefined2 *)(param_2 + 1) = uVar1;
  *(undefined2 *)((longlong)param_2 + 6) = 0;
  *(undefined8 *)(param_2 + 2) = 1;
  (*DAT_14000b260)(param_1,0x10000001,0x6275685f,2,*(undefined2 *)(param_1 + 0x70),0);
  return;
}



===== UhciRHGetStatus @ 140006ac0 =====

undefined8 UhciRHGetStatus(undefined8 param_1,undefined2 *param_2)

{
  *param_2 = 1;
  return 0;
}



===== UhciRHPortEnable @ 140006ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHPortEnable(longlong param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar2);
  (*DAT_14000b260)(param_1,0x10000001,0x6570735f,uVar1,0,param_2);
  out(sVar2,uVar1 & 0xfff1 | (param_3 & 1) << 2);
  return 0;
}



===== UhciRHPortResetComplete @ 140006b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciRHPortResetComplete(longlong param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  
  sVar1 = *param_2;
  sVar5 = (sVar1 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar2 = in(sVar5);
  (*DAT_14000b260)(param_1,0x10000001,0x4372705f,uVar2,*(undefined4 *)(param_1 + 0x54),sVar1);
  out(sVar5,uVar2 & 0xfdf5);
  do {
    sVar3 = in((short)*(undefined8 *)(param_1 + 8) + 2);
    if (sVar3 == -1) {
      return;
    }
    uVar2 = in(sVar5);
  } while ((uVar2 >> 9 & 1) != 0);
  iVar7 = 0;
  do {
    KeStallExecutionProcessor(0x32,sVar5);
    uVar2 = in(sVar5);
    (*DAT_14000b260)(param_1,0x10000001,0x7872705f,uVar2,*(undefined4 *)(param_1 + 0x54),sVar1);
    if ((uVar2 & 4) != 0) break;
    uVar2 = uVar2 | 4;
    iVar7 = iVar7 + 1;
    out(sVar5,uVar2);
  } while (iVar7 < 10);
  (*DAT_14000b260)(param_1,0x10000001,0x3172705f,uVar2,*(undefined4 *)(param_1 + 0x54),sVar1);
  out(sVar5,uVar2 & 0xfffd | 8);
  if (*(int *)(param_1 + 0x40) - 0xfaU < 5) {
    *(undefined1 *)(param_2 + 1) = 1;
    UhciViaRHSetFeaturePortResetSuspend(param_1,param_2);
  }
  else {
    uVar4 = in(sVar5);
    (*DAT_14000b260)(param_1,0x10000001,0x3272705f,uVar4,*(undefined4 *)(param_1 + 0x54),sVar1);
    uVar6 = 1 << ((char)sVar1 - 1U & 0x1f);
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~uVar6;
    if (((byte)uVar4 & 7) == 5) {
      *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | uVar6;
      (*DAT_14000b240)(param_1);
    }
  }
  return;
}



===== UhciRHSetFeaturePortEnable @ 140006d50 =====

void UhciRHSetFeaturePortEnable(longlong param_1,short param_2)

{
  UhciRHPortEnable(param_1,param_2,1);
  return;
}



===== UhciRHSetFeaturePortReset @ 140006d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHSetFeaturePortReset(longlong param_1,ushort param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  uint local_res8 [2];
  ushort local_res10;
  
  iVar5 = 3;
  sVar6 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar6);
  local_res8[0] = (uint)param_2;
  local_res10 = param_2;
  (*DAT_14000b260)(param_1,0x10000001,0x7270735f,0,uVar1,param_2);
  if (((*(uint *)(param_1 + 4) & 4) == 0) && ((uVar1 & 0x1001) == 0x1001)) {
    do {
      (*DAT_14000b260)(param_1,0x10000001,0x3172705f,param_2,uVar1,0);
      out(sVar6,uVar1 & 0xefb5);
      uVar1 = in(sVar6);
      (*DAT_14000b260)(param_1,0x10000001,0x3272705f,param_2,uVar1,0);
      if ((uVar1 >> 0xc & 1) != 0) {
        KeStallExecutionProcessor(0x32);
        iVar5 = iVar5 + -1;
        uVar1 = in(sVar6);
        (*DAT_14000b260)(param_1,0x10000001,0x3372705f,param_2,uVar1,0);
      }
    } while (((uVar1 >> 0xc & 1) != 0) && (0 < iVar5));
    param_2 = local_res10;
  }
  uVar4 = 1 << ((char)param_2 - 1U & 0x1f);
  if ((uVar4 & *(uint *)(param_1 + 0x50)) == 0) {
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | uVar4;
    if (*(int *)(param_1 + 0x40) - 0xfaU < 5) {
      uVar3 = (undefined2)*(undefined8 *)(param_1 + 8);
      uVar1 = in(uVar3);
      out(uVar3,uVar1 & 0xfffe);
      (*DAT_14000b270)(param_1,0x14,local_res8,4,UhciViaRHSetFeaturePortResetSuspend);
    }
    else {
      UhciRHSetFeaturePortResetWorker(param_1,(short *)local_res8);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== UhciRHSetFeaturePortResetWorker @ 140006f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciRHSetFeaturePortResetWorker(longlong param_1,short *param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
  sVar1 = *param_2;
  sVar3 = (sVar1 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar2 = in(sVar3);
  (*DAT_14000b260)(param_1,0x10000001,0x7772705f,uVar2,0,sVar1);
  (*DAT_14000b260)(param_1,0x10000001,0x73686e5f,uVar2,0,sVar1);
  out(sVar3,uVar2 & 0xfff5 | 0x200);
  (*DAT_14000b270)(param_1,10,param_2,4,UhciRHPortResetComplete);
  return;
}



===== UhciRHSetFeaturePortSuspend @ 140007060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciRHSetFeaturePortSuspend(longlong param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  
  sVar2 = (param_2 + 7) * 2 + (short)*(undefined8 *)(param_1 + 8);
  uVar1 = in(sVar2);
  (*DAT_14000b260)(param_1,0x10000001,0x7370735f,uVar1,0,param_2);
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 1 << ((char)param_2 - 1U & 0x1f);
  *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) =
       *(uint *)(*(longlong *)(param_1 + 0x2b0) + 4) | 0x1000000;
  if ((uVar1 & 0x1000) == 0) {
    if ((*(uint *)(param_1 + 4) & 4) == 0) {
      uVar1 = uVar1 & 0xfff5 | 0x1000;
      out(sVar2,uVar1);
    }
    else {
      (*DAT_14000b260)(param_1,0x10000001,0x6f70735f,uVar1,0,param_2);
    }
    (*DAT_14000b260)(param_1,0x10000001,0x7375735f,uVar1,0,param_2);
  }
  return 0;
}



===== UhciViaRHPortResetComplete @ 140007180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciViaRHPortResetComplete(longlong param_1,undefined2 *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar2 = (undefined2)*(ulonglong *)(param_1 + 8);
  uVar1 = in(uVar2);
  out(uVar2,uVar1 & 0xffef | 1);
  uVar3 = 1 << ((char)*param_2 - 1U & 0x1f);
  *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | uVar3;
  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~uVar3;
  (*DAT_14000b240)(param_1,*(ulonglong *)(param_1 + 8) & 0xffff);
  return;
}



===== UhciViaRHSetFeaturePortResetResume @ 1400071e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciViaRHSetFeaturePortResetResume(longlong param_1,longlong param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)*(undefined8 *)(param_1 + 8);
  uVar1 = in(uVar3);
  pcVar2 = UhciViaRHPortResetComplete;
  out(uVar3,uVar1 & 0xfff7 | 0x10);
  if (*(char *)(param_2 + 2) == '\0') {
    pcVar2 = UhciRHSetFeaturePortResetWorker;
  }
  (*DAT_14000b270)(param_1,0x14,param_2,4,pcVar2);
  return;
}



===== UhciViaRHSetFeaturePortResetSuspend @ 140007250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciViaRHSetFeaturePortResetSuspend(longlong param_1,undefined8 param_2)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = (short)*(undefined8 *)(param_1 + 8);
  in(sVar1 + 2);
  uVar2 = in(sVar1);
  out(sVar1,uVar2 & 0xffef | 8);
  (*DAT_14000b270)(param_1,0x14,param_2,4,UhciViaRHSetFeaturePortResetResume);
  return;
}



===== UhciAbortAsyncTransfer @ 1400072b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciAbortAsyncTransfer(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  longlong lVar1;
  uint *puVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  uint *puVar6;
  longlong *plVar7;
  uint *puVar8;
  uint uVar9;
  uint *local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0x50);
  (*DAT_14000b260)(param_1,0x10000001,0x7461415f,lVar1,param_3,*(undefined8 *)(param_2 + 0x68));
  UhciPollAsyncEndpoint(param_1,param_2,(longlong)param_3);
  uVar5 = *(uint *)(lVar1 + 4) & 0xfffffff8;
  if (uVar5 != 0) {
    (*DAT_14000b268)(uVar5,param_1,param_2);
  }
  puVar2 = *(uint **)(param_2 + 0x68);
  if (puVar2 != (uint *)0x0) {
    local_res10 = (uint *)0x0;
    puVar6 = puVar2;
    while (puVar8 = puVar6, puVar8 != (uint *)0x0) {
      if (*(longlong **)(puVar8 + 6) == param_3) {
        uVar5 = 1;
        uVar9 = puVar8[2] >> 0x13 & 1;
        puVar6 = puVar8;
        goto LAB_140007385;
      }
      local_res10 = puVar8;
      puVar6 = *(uint **)(puVar8 + 0xc);
    }
  }
  goto LAB_140007516;
  while( true ) {
    (*DAT_14000b260)(param_1,0x10000001,0x5462615f,lVar1,puVar6[1],puVar6);
    if ((puVar6[1] >> 0x17 & 1) == 0) {
      uVar9 = puVar6[2];
      UhciProcessDoneAsyncTd(param_1,puVar6,(longlong)param_3);
      uVar9 = ~(uVar9 >> 0x13) & 1;
    }
    else {
      if ((puVar6[10] & 0x20) != 0) {
        (*DAT_14000b260)(param_1,0x10000001,0x4244665f,*(undefined8 *)(puVar6 + 0xe),param_2,0);
        *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + -1;
        if (*(int *)(param_2 + 0x1c) == 0) {
          *(undefined4 *)(*(longlong *)(puVar6 + 0xe) + 0x414) = 0;
        }
        else {
          *(undefined4 *)(*(longlong *)(puVar6 + 0xe) + 0x54) = 0;
        }
      }
      *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + -1;
      *puVar6 = 0xbadf00d;
      (*DAT_14000b260)(param_1,0x10000001,0x4454665f,puVar6,param_2,0);
      puVar6[10] = 0;
      *(undefined1 **)(puVar6 + 6) = &DAT_deadfacedeadface;
    }
    puVar6 = *(uint **)(puVar6 + 0xc);
    if (puVar6 == (uint *)0x0) break;
LAB_140007385:
    if (*(longlong **)(puVar6 + 6) != param_3) break;
  }
  UhciFixDataToggle(param_1,param_2,(longlong)puVar6,uVar9);
  if (puVar8 == puVar2) {
    if (puVar6 == (uint *)0x0) {
      *(undefined8 *)(param_2 + 0x60) = 0;
      *(undefined8 *)(param_2 + 0x68) = 0;
    }
    else {
      *(uint **)(param_2 + 0x68) = puVar6;
      if ((*(uint *)(param_2 + 4) & 1) == 0) {
        uVar5 = puVar6[4] & 0xfffffffc;
      }
    }
    (*DAT_14000b260)(param_1,0x10000001,0x7471735f,puVar6,param_2,0);
    *(uint *)(*(longlong *)(param_2 + 0x50) + 4) = uVar5;
  }
  else if (puVar6 == (uint *)0x0) {
    *(uint **)(param_2 + 0x60) = local_res10;
    local_res10[0xc] = 0;
    local_res10[0xd] = 0;
    *local_res10 = 1;
  }
  else {
    uVar5 = puVar6[4];
    *(uint **)(local_res10 + 0xc) = puVar6;
    *local_res10 = uVar5 & 0xfffffff8;
  }
LAB_140007516:
  *param_4 = *(undefined4 *)((longlong)param_3 + 0x14);
  plVar7 = *(longlong **)(param_2 + 0xc0);
  while( true ) {
    if (plVar7 == (longlong *)(param_2 + 0xc0)) {
      return;
    }
    if (plVar7 + -5 == param_3) break;
    plVar7 = (longlong *)*plVar7;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x3561435f,plVar7[1],plVar7 + -5,*plVar7);
  lVar1 = *plVar7;
  if ((*(longlong **)(lVar1 + 8) == plVar7) &&
     (plVar3 = (longlong *)plVar7[1], (longlong *)*plVar3 == plVar7)) {
    *plVar3 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar3;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== UhciInsertQh @ 1400075ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciInsertQh(longlong param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  (*DAT_14000b260)(param_1,0x10000001,0x6e69415f,0,param_2,param_3);
  lVar2 = *(longlong *)(param_2 + 6);
  *param_3 = *param_2;
  *(longlong *)(param_3 + 6) = lVar2;
  *(uint **)(param_3 + 8) = param_2;
  if (lVar2 == 0) {
    *(uint **)(param_1 + 0x98) = param_3;
  }
  else {
    *(uint **)(lVar2 + 0x20) = param_3;
  }
  uVar1 = param_3[2];
  *(uint **)(param_2 + 6) = param_3;
  *param_2 = uVar1 | 2;
  LOCK();
  param_3[4] = param_3[4] | 1;
  UNLOCK();
  return;
}



===== UhciSetAsyncEndpointState @ 140007634 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciSetAsyncEndpointState(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  (*DAT_14000b260)(param_1,0x10000001,0x7361535f,param_2,(longlong)param_3,0);
  puVar2 = *(uint **)(param_2 + 0x50);
  iVar1 = *(int *)(param_2 + 0x1c);
  if (param_3 != 2) {
    if (param_3 == 3) {
      if (iVar1 == 1) {
        puVar3 = *(uint **)(param_1 + 0x88);
      }
      else if (iVar1 == 2) {
        puVar3 = *(uint **)(param_1 + 0x90);
      }
      else {
        if (iVar1 != 3) {
          return;
        }
        puVar3 = *(uint **)(param_1 + 0xa0 +
                           (ulonglong)
                           ((uint)*(byte *)(param_2 + 0xe) + *(int *)(param_2 + 0x18) + -1) * 8);
      }
      UhciInsertQh(param_1,puVar3,puVar2);
      return;
    }
    if (param_3 != 4) {
      return;
    }
    puVar2[4] = puVar2[4] | 2;
  }
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
    UhciUnlinkQh(param_1,puVar2);
  }
  return;
}



===== UhciUnlinkQh @ 140007704 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciUnlinkQh(longlong param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 6);
  puVar1 = *(undefined4 **)(param_2 + 8);
  if (*(undefined4 **)(param_1 + 0x98) == param_2) {
    *(undefined4 **)(param_1 + 0x98) = puVar1;
  }
  (*DAT_14000b260)(param_1,0x10000001,0x6b6c555f,param_2,puVar1,lVar2);
  *puVar1 = *param_2;
  *(longlong *)(puVar1 + 6) = lVar2;
  if (lVar2 != 0) {
    *(undefined4 **)(lVar2 + 0x20) = puVar1;
  }
  *(undefined4 **)(param_2 + 8) = param_2;
  *(undefined4 **)(param_2 + 6) = param_2;
  if ((*(int *)(*(longlong *)(param_2 + 10) + 0x1c) == 2) &&
     ((**(uint **)(param_1 + 0x98) & 1) == 0)) {
    for (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x90) + 0x18); lVar2 != 0;
        lVar2 = *(longlong *)(lVar2 + 0x18)) {
      if ((*(uint *)(lVar2 + 4) & 1) == 0) goto LAB_1400077b2;
    }
    **(uint **)(param_1 + 0x98) = **(uint **)(param_1 + 0x98) | 1;
  }
LAB_1400077b2:
  LOCK();
  param_2[4] = param_2[4] & 0xfffffffe;
  UNLOCK();
  return;
}



===== UhciAbortIsochTransfer @ 1400077d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciAbortIsochTransfer(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  (*DAT_14000b260)(param_1,0x10000001,0x7469415f,param_2,param_3,0);
  UhciCleanOutIsoch(param_1,'\0');
  uVar3 = 0;
  if (*(int *)(param_2 + 0x78) != 0) {
    do {
      puVar1 = (undefined4 *)(uVar3 * 0x80 + *(longlong *)(param_2 + 0x70));
      if (*(longlong *)(puVar1 + 6) == param_3) {
        if ((puVar1[10] & 0x20) != 0) {
          (*DAT_14000b260)(param_1,0x10000001,0x4244665f,*(undefined8 *)(puVar1 + 0xe),param_2,0);
          *(int *)(param_2 + 0x98) = *(int *)(param_2 + 0x98) + -1;
          if (*(int *)(param_2 + 0x1c) == 0) {
            *(undefined4 *)(*(longlong *)(puVar1 + 0xe) + 0x414) = 0;
          }
          else {
            *(undefined4 *)(*(longlong *)(puVar1 + 0xe) + 0x54) = 0;
          }
        }
        *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + -1;
        *puVar1 = 0xbadf00d;
        (*DAT_14000b260)(param_1,0x10000001,0x4454665f,puVar1,param_2,0);
        puVar1[10] = 0;
        *(undefined1 **)(puVar1 + 6) = &DAT_deadfacedeadface;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_2 + 0x78));
  }
  return;
}



===== UhciStopBIOS @ 140007904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 UhciStopBIOS(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  short sVar3;
  ushort local_res8 [4];
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  local_res8[0] = 0;
  (*DAT_14000b278)(param_1,1,local_res8,0xc0,2);
  UhciDisableInterrupts(param_1);
  sVar3 = (short)uVar1;
  uVar2 = in(sVar3);
  out((short)*(undefined8 *)(param_1 + 8),uVar2 & 0xffba);
  sVar3 = sVar3 + 2;
  uVar2 = in(sVar3);
  do {
    if ((uVar2 & 0x20) != 0) break;
    uVar2 = in(sVar3);
  } while (_DAT_fffff78000000014 < _DAT_fffff78000000014 + 1000000);
  out(sVar3,0xff);
  if ((local_res8[0] & 0xbf) != 0) {
    *(undefined1 *)(param_2 + 0x44) = 1;
    (*DAT_14000b278)(param_1,CONCAT71((uint7)(byte)((ushort)sVar3 >> 8),1),local_res8,0xc0,2);
    local_res8[0] = 0;
    (*DAT_14000b278)(param_1,0,local_res8,0xc0,2);
  }
  return 0;
}



===== UhciDisableInterrupts @ 140007a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciDisableInterrupts(longlong param_1)

{
  undefined8 uVar1;
  short sVar2;
  ushort local_res8 [4];
  undefined4 uVar3;
  
  uVar3 = 0;
  local_res8[0] = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x6e49445f,0,0,0);
  uVar1 = 0;
  sVar2 = (short)*(undefined8 *)(param_1 + 8) + 4;
  out(sVar2,0);
  if (*(int *)(param_1 + 0x40) != 0xcb) {
    (*DAT_14000b278)(param_1,CONCAT71((int7)(CONCAT62((int6)((ulonglong)*(undefined8 *)(param_1 + 8)
                                                            >> 0x10),sVar2) >> 8),1),local_res8,0xc0
                     ,CONCAT44(uVar3,2));
    (*DAT_14000b260)(param_1,0x10000001,0x67656c5f,0,local_res8[0],0);
    local_res8[0] = local_res8[0] & 0xdfff;
    uVar1 = (*DAT_14000b278)(param_1,0,local_res8,0xc0,2);
  }
  return uVar1;
}



===== UhciEnableInterrupts @ 140007b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined2 UhciEnableInterrupts(longlong param_1)

{
  undefined8 uVar1;
  ushort local_res8 [4];
  undefined4 uVar2;
  
  uVar2 = 0;
  local_res8[0] = 0;
  (*DAT_14000b260)(param_1,0x10000001,0x6e49455f,0,0,0);
  uVar1 = *(undefined8 *)(param_1 + 8);
  (*DAT_14000b278)(param_1,1,local_res8,0xc0,CONCAT44(uVar2,2));
  (*DAT_14000b260)(param_1,0x10000001,0x67656c5f,0,local_res8[0],0);
  local_res8[0] = local_res8[0] | 0x2000;
  (*DAT_14000b278)(param_1,0,local_res8,0xc0,2);
  out((short)uVar1 + 4,*(undefined2 *)(param_1 + 0x38));
  return *(undefined2 *)(param_1 + 0x38);
}



===== UhciFlushInterrupts @ 140007c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UhciFlushInterrupts(longlong param_1)

{
  (*DAT_14000b260)(param_1,0x10000001,0x6e49465f,0,0,0);
  out((short)*(undefined8 *)(param_1 + 8) + 2,0xffff);
  return 0xffff;
}



===== UhciInterruptDpc @ 140007c50 =====

void UhciInterruptDpc(longlong param_1,char param_2)

{
  UhciInterruptDpcEx(param_1,param_2);
  return;
}



===== UhciInterruptNextSOF @ 140007c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UhciInterruptNextSOF(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  int *piVar6;
  longlong lVar7;
  int iVar8;
  
  iVar3 = UhciGet32BitFrameNumber(param_1);
  uVar4 = 0;
  lVar7 = 8;
  do {
    if (7 < (uint)uVar4) {
LAB_140007d49:
      lVar5 = 0;
      do {
        lVar2 = *(longlong *)(param_1 + 0x2a8);
        iVar1 = *(int *)(lVar5 + 0x18 + lVar2);
        if ((iVar1 != 0) &&
           (((iVar3 - iVar1) - 1U < 0x7fffffff || ((iVar1 - iVar3) - 0x401U < 0x7fffffff)))) {
          *(undefined4 *)(lVar5 + 0x18 + lVar2) = 0;
          *(undefined4 *)(lVar5 + 0x28 + lVar2) = 0;
        }
        lVar5 = lVar5 + 0x80;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      return;
    }
    iVar8 = iVar3 + 2;
    piVar6 = (int *)(uVar4 * 0x80 + *(longlong *)(param_1 + 0x2a8));
    iVar1 = piVar6[6];
    if (iVar1 == iVar8) goto LAB_140007d49;
    if ((((iVar3 - iVar1) - 1U < 0x7fffffff) || ((iVar1 - iVar3) - 0x401U < 0x7fffffff)) ||
       ((iVar1 == 0 && ((piVar6[10] & 0x40U) == 0)))) {
      piVar6[6] = iVar8;
      (*DAT_14000b260)(param_1,0x10000001,0x464f535f,piVar6,iVar8,iVar3);
      *piVar6 = 0;
      piVar6[10] = piVar6[10] | 0x40;
      LOCK();
      if (*piVar6 == 0) {
        *piVar6 = *(int *)(*(longlong *)(param_1 + 0x78) + ((ulonglong)(uint)piVar6[6] & 0x3ff) * 4)
        ;
      }
      UNLOCK();
      *(int *)(*(longlong *)(param_1 + 0x78) + ((ulonglong)(uint)piVar6[6] & 0x3ff) * 4) = piVar6[4]
      ;
      goto LAB_140007d49;
    }
    uVar4 = (ulonglong)((uint)uVar4 + 1);
  } while( true );
}



===== _guard_check_icall @ 140007db0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140007dc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140007dec =====

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



===== __cpu_features_init @ 140007e60 =====

/* WARNING: Removing unreachable block (ram,0x000140007eca) */
/* WARNING: Removing unreachable block (ram,0x000140007e79) */
/* WARNING: Removing unreachable block (ram,0x000140007e6a) */

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



===== __security_check_cookie @ 140007f30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007f70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007fa0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007fa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007fd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140008040 =====

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



===== memset @ 140008340 =====

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



===== __memset_repmovs @ 140008480 =====

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



===== __memset_query @ 140008500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140008580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400086c0 =====

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



===== __memset_spec_plain @ 140008740 =====

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



===== entry @ 14000e010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000e044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  char in_DL;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar2 = (code *)swi(0x29);
    pbVar5 = (byte *)(*pcVar2)(6);
    bVar3 = (byte)pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + in_DL + CARRY1(bVar1,bVar3);
    bVar1 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    uVar4 = (int)pbVar5 + *(int *)pbVar5 + (uint)CARRY1(bVar1,bVar3);
    pcVar6 = (char *)(ulonglong)uVar4;
    pcVar6[0x14] = pcVar6[0x14] + (char)(uVar4 >> 8);
    *pcVar6 = *pcVar6 + (char)uVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


