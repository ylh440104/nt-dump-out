
===== lldpProtReceiveNetBufferLists @ 140001010 =====

void lldpProtReceiveNetBufferLists
               (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
               byte param_5)

{
  ushort uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int *piVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  int *piVar9;
  
  puVar4 = param_2;
  do {
    if (puVar4 == (undefined8 *)0x0) {
      if ((param_5 & 2) == 0) {
        NdisReturnNetBufferLists(*(undefined8 *)(param_1 + 8),param_2,param_5 & 1);
      }
      return;
    }
    for (puVar2 = (undefined8 *)puVar4[1]; puVar2 != (undefined8 *)0x0;
        puVar2 = (undefined8 *)*puVar2) {
      for (lVar3 = *(longlong *)(param_1 + 0x78); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x28)) {
        piVar5 = (int *)NdisGetDataBuffer(puVar2,0x16,0,1,0);
        if ((piVar5 != (int *)0x0) &&
           ((uVar1 = *(ushort *)(piVar5 + 3), uVar1 == 0xcc88 ||
            ((((((ushort)(uVar1 >> 8 | uVar1 << 8) < 0x600 &&
                (*(char *)((longlong)piVar5 + 0xe) == -0x56)) &&
               (*(char *)((longlong)piVar5 + 0xf) == -0x56)) &&
              (((char)piVar5[4] == '\x03' && (*(char *)((longlong)piVar5 + 0x11) == '\0')))) &&
             ((*(char *)((longlong)piVar5 + 0x12) == '\0' &&
              ((*(char *)((longlong)piVar5 + 0x13) == '\0' && ((short)piVar5[5] == -0x3378))))))))))
        {
          iVar8 = *(int *)(lVar3 + 0x84);
          if (iVar8 == 1) {
LAB_14000115b:
            piVar9 = &LLDP_DEST_MAC_NEAREST_BRIDGE;
          }
          else if (iVar8 == 2) {
            piVar9 = &LLDP_DEST_MAC_NEAREST_NON_TPMR_BRIDGE;
          }
          else {
            if (iVar8 != 3) goto LAB_14000115b;
            piVar9 = &LLDP_DEST_MAC_NEAREST_CUSTOMER_BRIDGE;
          }
          iVar8 = *piVar5 - *piVar9;
          if (iVar8 == 0) {
            iVar8 = (uint)*(ushort *)(piVar5 + 1) - (uint)*(ushort *)(piVar9 + 1);
          }
          if (iVar8 == 0) {
            uVar6 = *(uint *)(lVar3 + 0xf8);
            uVar7 = (ulonglong)uVar6;
            if ((uVar6 != 0) && (uVar7 = (ulonglong)(uVar6 - 1), uVar6 - 1 != 0)) {
              uVar6 = uVar6 - 2;
              uVar7 = (ulonglong)uVar6;
              if ((uVar6 == 0) || (uVar6 == 1)) {
                lldpReceivePermittedPacket(lVar3,(ulonglong)puVar2,param_5 & 1);
                goto LAB_1400010a9;
              }
            }
            if (Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits < '\0') {
              McTemplateK0qqq_EtwWriteTransfer
                        (uVar7,0,piVar9,*(undefined4 *)(lVar3 + 0x80),
                         (char)*(undefined4 *)(puVar2 + 0xb),10);
            }
            LOCK();
            *(longlong *)(lVar3 + 0x378) = *(longlong *)(lVar3 + 0x378) + 1;
            UNLOCK();
          }
        }
LAB_1400010a9:
      }
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== lldpAddMedTlvs @ 140001220 =====

void lldpAddMedTlvs(longlong param_1,uint *param_2,ulonglong param_3)

{
  uint *_Dst;
  
  if (((2 < *param_2) && (0x67 < param_3)) &&
     (_Dst = (uint *)ExAllocatePool2(0x40,param_3 + 8,0x50444c4c), _Dst != (uint *)0x0)) {
    memmove(_Dst,param_2,param_3);
    *_Dst = *_Dst + 2;
    *(undefined1 *)((longlong)_Dst + param_3) = 3;
    *(undefined2 *)((longlong)_Dst + param_3 + 1) = 0x100;
    *(undefined2 *)((longlong)_Dst + param_3 + 3) = 0;
    _Dst[0x14] = 0;
    *(undefined2 *)(_Dst + 0x10) = 0x7f;
    *(undefined2 *)(_Dst + 0x11) = 0x1200;
    *(undefined4 *)((longlong)_Dst + 0x46) = 0x5010f;
    _Dst[0x13] = (uint)param_3;
    *(undefined2 *)((longlong)_Dst + param_3 + 5) = 0x100;
    *(undefined1 *)((longlong)_Dst + param_3 + 7) = 1;
    _Dst[0x19] = 0;
    *(undefined2 *)(_Dst + 0x15) = 0x7f;
    _Dst[0x18] = (uint)(param_3 + 5);
    *(undefined4 *)((longlong)_Dst + 0x5a) = 0x301bb;
    *(undefined2 *)(_Dst + 0x16) = 0x1200;
    lldpSetTlvs(param_1,_Dst,'\x01');
    ExFreePoolWithTag(_Dst,0x50444c4c);
  }
  return;
}



===== lldpSetTlvs @ 140001340 =====

undefined8 lldpSetTlvs(longlong param_1,uint *param_2,char param_3)

{
  int iVar1;
  ushort uVar2;
  longlong lVar3;
  char cVar4;
  undefined1 uVar5;
  ushort uVar6;
  int iVar7;
  ulonglong uVar8;
  ushort *puVar9;
  undefined8 uVar10;
  ushort *puVar11;
  ulonglong uVar12;
  int *piVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  undefined2 local_res20;
  undefined1 local_res22;
  
  local_res20 = 0;
  local_res22 = 0;
  uVar8 = lldpValidateTlvArray(param_2,param_3);
  if ((char)uVar8 == '\0') {
    return 0xc000000d;
  }
  if (*param_2 == 0) {
    return 0;
  }
  uVar10 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x3d0),&local_res20,0);
  uVar12 = (ulonglong)*param_2;
  piVar13 = (int *)(param_1 + 0x3d8);
  uVar8 = 0;
  uVar16 = 2;
  while (uVar15 = (uint)uVar8, uVar15 < (uint)uVar12) {
    iVar7 = lldpWireSizeOfTlv((short *)(param_2 + uVar8 * 5 + 1));
    if (iVar7 + uVar16 < uVar16) {
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res20);
      return 0xc0000095;
    }
    uVar16 = iVar7 + uVar16;
    uVar8 = (ulonglong)(uVar15 + 1);
  }
  puVar9 = (ushort *)((ulonglong)(uint)piVar13[1] + 0xc + (longlong)piVar13);
  for (puVar11 = (ushort *)(piVar13 + 3); puVar11 + 1 < puVar9;
      puVar11 = (ushort *)
                ((longlong)puVar11 + (ulonglong)(uVar2 & 1) * 0x100 + 2 + (ulonglong)bVar14)) {
    uVar2 = *puVar11;
    if ((uVar2 & 0xfe) == 0) break;
    for (uVar15 = 0; bVar14 = (byte)(uVar2 >> 8), uVar15 < (uint)uVar12; uVar15 = uVar15 + 1) {
      uVar6 = lldpTlvTypeMatch(puVar11,(ushort *)(param_2 + (ulonglong)uVar15 * 5 + 1));
      if ((char)uVar6 != '\0') goto LAB_14000149a;
    }
    uVar15 = (uVar2 & 1) * 0x100 + 2 + uVar16 + (uint)bVar14;
    if (uVar15 < uVar16) {
      uVar10 = 0xc0000095;
      goto LAB_140001647;
    }
    uVar16 = uVar15;
LAB_14000149a:
  }
  if (*(uint *)(param_1 + 0x8c) < uVar16) {
    uVar10 = 0xc000020e;
LAB_140001647:
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res20);
    return uVar10;
  }
  cVar4 = lldpMergeTlvsWithMib(piVar13,param_2);
  *(char *)(param_1 + 0x97) = cVar4;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res20);
  iVar7 = *(int *)(param_1 + 0x34);
  do {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x34);
    bVar17 = iVar7 == iVar1;
    if (bVar17) {
      *(int *)(param_1 + 0x34) = iVar7;
    }
    else {
      iVar7 = iVar1;
    }
    UNLOCK();
  } while (!bVar17);
  if ((iVar7 == 4) || (iVar7 == 5)) {
    iVar7 = *(int *)(param_1 + 0x130);
    do {
      LOCK();
      iVar1 = *(int *)(param_1 + 0x130);
      bVar17 = iVar7 == iVar1;
      if (bVar17) {
        *(int *)(param_1 + 0x130) = iVar7;
      }
      else {
        iVar7 = iVar1;
      }
      UNLOCK();
    } while (!bVar17);
    if (((iVar7 == 0) && (iVar7 = *(int *)(param_1 + 0xf8), iVar7 != 0)) &&
       ((iVar7 == 1 || ((iVar7 != 2 && (iVar7 == 3)))))) {
      iVar7 = *(int *)(param_1 + 0x36c);
      do {
        LOCK();
        iVar1 = *(int *)(param_1 + 0x36c);
        bVar17 = iVar7 == iVar1;
        if (bVar17) {
          *(int *)(param_1 + 0x36c) = iVar7;
        }
        else {
          iVar7 = iVar1;
        }
        UNLOCK();
      } while (!bVar17);
      if (iVar7 == 0) {
        uVar16 = *(uint *)(param_1 + 0x100);
      }
      else {
        uVar16 = *(uint *)(param_1 + 0x10c);
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x35c) = 1;
      UNLOCK();
      lldpSetPeriodicTimer
                (param_1 + 0x248,uVar16,(undefined *)CONCAT71((int7)((ulonglong)uVar10 >> 8),1));
      goto LAB_1400015c1;
    }
  }
  KeCancelTimer(param_1 + 0x248);
  LOCK();
  iVar7 = *(int *)(param_1 + 0x35c);
  *(int *)(param_1 + 0x35c) = 0;
  UNLOCK();
  if (iVar7 != 0) {
    lldpTxSendShutdownPacket(param_1);
  }
LAB_1400015c1:
  if ((cVar4 != '\0') && (*(longlong *)(param_1 + 0x58) != 0)) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
    *(undefined1 *)(param_1 + 0x50) = uVar5;
    for (lVar3 = *(longlong *)(param_1 + 0x58); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 8)) {
      LOCK();
      *(uint *)(lVar3 + 0x20) = *(uint *)(lVar3 + 0x20) | 1;
      UNLOCK();
    }
    KeReleaseSpinLock(param_1 + 0x48,*(undefined1 *)(param_1 + 0x50));
    LOCK();
    iVar7 = *(int *)(param_1 + 0x60);
    *(int *)(param_1 + 0x60) = 1;
    UNLOCK();
    if (iVar7 == 0) {
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x68),lldpDeliverChangeNotifications,1,param_1);
    }
  }
  return 0;
}



===== lldpWireSizeOfTlv @ 140001690 =====

int lldpWireSizeOfTlv(short *param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = param_1[4];
  if (uVar1 == 0xffff) {
    return 0;
  }
  iVar2 = uVar1 + 2;
  if (*param_1 == 0x7f) {
    iVar2 = uVar1 + 6;
  }
  return iVar2;
}



===== lldpMergeTlvsWithMib @ 1400016c0 =====

undefined1 lldpMergeTlvsWithMib(int *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ushort *puVar10;
  uint uVar11;
  ushort uVar12;
  ushort *puVar13;
  ushort *puVar14;
  ushort uVar15;
  ushort *_Dst;
  undefined1 local_res8;
  uint local_res18;
  
  _Dst = (ushort *)(param_1 + 3);
  puVar14 = (ushort *)((ulonglong)(uint)param_1[2] + (longlong)param_1);
  local_res18 = 0;
  local_res8 = 0;
  puVar10 = _Dst;
LAB_140001706:
  do {
    puVar7 = puVar10 + 1;
    if ((ushort *)((ulonglong)(uint)param_1[1] + 0xc + (longlong)param_1) <= puVar7) {
LAB_14000188e:
      uVar9 = 0;
      do {
        uVar3 = (uint)uVar9;
        if (*param_2 <= uVar3) {
          if (_Dst + 1 < puVar14) {
            *_Dst = *_Dst & 0xff01;
            *(undefined1 *)((longlong)_Dst + 1) = 0;
            *_Dst = *_Dst & 0xfffe;
            param_1[1] = ((int)_Dst - (int)param_1) + -10;
          }
          return local_res8;
        }
        uVar1 = (ushort)param_2[uVar9 * 5 + 3];
        if (uVar1 == 0xffff) {
          uVar8 = 0;
        }
        else if ((short)param_2[uVar9 * 5 + 1] == 0x7f) {
          uVar8 = (ulonglong)(uVar1 + 6);
        }
        else {
          uVar8 = (ulonglong)(uVar1 + 2);
        }
        puVar10 = _Dst;
        if (((0x1f < uVar3) || ((local_res18 >> (uVar3 & 0x1f) & 1) == 0)) &&
           (uVar11 = (uint)uVar8, uVar11 != 0)) {
          puVar10 = (ushort *)(uVar8 + (longlong)_Dst);
          if (puVar14 <= puVar10) {
            return local_res8;
          }
          if (1 < uVar11) {
            *_Dst = ((short)param_2[uVar9 * 5 + 1] * 2 ^ *_Dst) & 0xfe ^ *_Dst;
            *(char *)((longlong)_Dst + 1) = (char)(uVar11 - 2);
            *_Dst = ((ushort)(uVar11 - 2 >> 8) ^ *_Dst) & 1 ^ *_Dst;
            puVar7 = _Dst + 1;
            if ((short)param_2[uVar9 * 5 + 1] == 0x7f) {
              *puVar7 = (ushort)param_2[uVar9 * 5 + 2];
              *(undefined1 *)(_Dst + 2) = *(undefined1 *)((longlong)param_2 + uVar9 * 0x14 + 10);
              puVar7 = _Dst + 3;
              *(undefined1 *)((longlong)_Dst + 5) =
                   *(undefined1 *)((longlong)param_2 + uVar9 * 0x14 + 0xb);
            }
            if ((ushort *)((ulonglong)(ushort)param_2[uVar9 * 5 + 3] + (longlong)puVar7) <= puVar10)
            {
              memmove(puVar7,(void *)((ulonglong)param_2[uVar9 * 5 + 4] + (longlong)param_2),
                      (ulonglong)(ushort)param_2[uVar9 * 5 + 3]);
            }
          }
          local_res8 = 1;
          if ((short)param_2[uVar9 * 5 + 1] == 2) {
            *param_1 = ((int)puVar10 - (int)param_1) + -0xc;
          }
        }
        uVar9 = (ulonglong)(uVar3 + 1);
        _Dst = puVar10;
      } while( true );
    }
    uVar1 = *puVar10;
    uVar15 = uVar1 & 0xfe;
    if (uVar15 == 0) goto LAB_14000188e;
    iVar4 = (uVar1 & 1) * 0x100;
    uVar3 = (uint)(uVar1 >> 8) + iVar4;
    puVar13 = (ushort *)((ulonglong)uVar3 + 2 + (longlong)puVar10);
    uVar3 = uVar3 + 2;
    uVar9 = 0;
    while (uVar11 = (uint)uVar9, uVar11 < *param_2) {
      uVar12 = (ushort)param_2[uVar9 * 5 + 3];
      if (uVar12 == 0xffff) {
        uVar8 = 0;
        uVar12 = 0xffff;
      }
      else {
        uVar8 = (ulonglong)(uVar12 + 6);
        if ((short)param_2[uVar9 * 5 + 1] != 0x7f) {
          uVar8 = (ulonglong)(uVar12 + 2);
        }
      }
      uVar2 = uVar1 >> 1 & 0x7f;
      if (uVar2 == (ushort)param_2[uVar9 * 5 + 1]) {
        if (uVar2 == 0x7f) {
          iVar5 = (uint)*puVar7 - (uint)(ushort)param_2[uVar9 * 5 + 2];
          if (iVar5 == 0) {
            iVar5 = (uint)(byte)puVar10[2] - (uint)*(byte *)((longlong)param_2 + uVar9 * 0x14 + 10);
          }
          if ((iVar5 != 0) ||
             (*(char *)((longlong)puVar10 + 5) != *(char *)((longlong)param_2 + uVar9 * 0x14 + 0xb))
             ) goto LAB_1400017de;
        }
        if ((uVar12 == 0xffff) ||
           (((0x1f < uVar11 || (uVar11 = 1 << ((byte)uVar9 & 0x1f), (local_res18 & uVar11) != 0)) ||
            (uVar3 < (uint)uVar8)))) {
          local_res8 = 1;
          goto LAB_1400019c2;
        }
        uVar6 = iVar4 + (uint)(uVar1 >> 8);
        uVar3 = uVar6 - 4;
        if (uVar15 != 0xfe) {
          uVar3 = uVar6;
        }
        if (uVar3 == uVar12) {
          puVar10 = puVar10 + 3;
          if (uVar15 != 0xfe) {
            puVar10 = puVar7;
          }
          iVar4 = memcmp(puVar10,(void *)((ulonglong)param_2[uVar9 * 5 + 4] + (longlong)param_2),
                         (ulonglong)uVar3);
          if (iVar4 != 0) goto LAB_1400019d4;
        }
        else {
LAB_1400019d4:
          if (puVar14 <= (ushort *)(uVar8 + (longlong)_Dst)) {
            return local_res8;
          }
          lldpCopyTlvToMib(_Dst,(uint)uVar8,(longlong)param_2,uVar9);
          local_res8 = 1;
        }
        local_res18 = local_res18 | uVar11;
        _Dst = (ushort *)((longlong)_Dst + uVar8);
        puVar10 = puVar13;
        goto LAB_140001706;
      }
LAB_1400017de:
      uVar9 = (ulonglong)(uVar11 + 1);
    }
    puVar7 = (ushort *)((ulonglong)uVar3 + (longlong)_Dst);
    if (puVar14 <= puVar7) {
      return local_res8;
    }
    if (_Dst != puVar10) {
      memmove(_Dst,puVar10,(ulonglong)uVar3);
    }
    _Dst = puVar7;
LAB_1400019c2:
    puVar10 = puVar13;
  } while( true );
}



===== lldpProtStatus @ 140001ab0 =====

void lldpProtStatus(longlong param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  short *psVar2;
  undefined2 uVar3;
  undefined *puVar4;
  longlong lVar5;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0x40010024) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return;
    }
    uVar3 = 0x25;
    goto LAB_140001d5e;
  }
  if (iVar1 == 0x40010017) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
    }
    puVar4 = (undefined *)0x2;
  }
  else {
    if (iVar1 < 0x40010019) {
      if (iVar1 == 0x40010018) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return;
        }
        uVar3 = 0x24;
LAB_140001d5e:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
                &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
        return;
      }
      if (iVar1 != 0x40010004) {
        if (iVar1 == 0x40010005) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                    &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
          }
          lldpEnableAllPortsOnBinding(param_1,(undefined *)0x20,param_3);
          return;
        }
        if (iVar1 != 0x40010012) {
          return;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return;
        }
        uVar3 = 0x20;
        goto LAB_140001d5e;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
      }
      puVar4 = (undefined *)0x20;
      goto LAB_140001ba2;
    }
    if (iVar1 == 0x40010022) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return;
      }
      uVar3 = 0x22;
      goto LAB_140001d5e;
    }
    if (iVar1 != 0x40010023) {
      if (iVar1 != 0x400200b0) {
        return;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
      }
      if (*(uint *)(param_2 + 0x38) < 0x22) {
        return;
      }
      psVar2 = *(short **)(param_2 + 0x30);
      if (*psVar2 != 6) {
        return;
      }
      lVar5 = *(longlong *)(param_1 + 0x78);
      if (lVar5 == 0) {
        return;
      }
      do {
        lldpSetPortMacAddress(lVar5,(undefined4 *)(psVar2 + 1));
        lVar5 = *(longlong *)(lVar5 + 0x28);
      } while (lVar5 != 0);
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
    }
    puVar4 = (undefined *)0x10;
  }
  if (*(int *)(*(longlong *)(param_2 + 0x30) + 4) == 1) {
    lldpEnableAllPortsOnBinding(param_1,puVar4,param_3);
    return;
  }
LAB_140001ba2:
  lldpDisableAllPortsOnBinding(param_1,puVar4);
  return;
}



===== lldpEnableAllPortsOnBinding @ 140001d80 =====

void lldpEnableAllPortsOnBinding(longlong param_1,undefined *param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  code *pcVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  lVar6 = *(longlong *)(param_1 + 0x78);
  if (lVar6 != 0) {
    uVar7 = (uint)param_2;
    do {
      uVar4 = *(uint *)(lVar6 + 0x130);
      do {
        LOCK();
        uVar8 = *(uint *)(lVar6 + 0x130);
        bVar9 = uVar4 == uVar8;
        if (bVar9) {
          *(uint *)(lVar6 + 0x130) = uVar4 & ~uVar7;
        }
        else {
          uVar4 = uVar8;
        }
        UNLOCK();
      } while (!bVar9);
      uVar8 = ~uVar7 & uVar4;
      pcVar5 = (code *)param_2;
      if (uVar8 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids;
          param_2 = (code *)0xd;
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,
                    (uint)(ushort)((ulonglong)*(undefined8 *)(lVar6 + 0x78) >> 0x30),
                    (char)((ulonglong)*(undefined8 *)(lVar6 + 0x78) >> 0x18));
        }
        lldpEnableTxFastMode(lVar6,param_2,param_3);
        pcVar5 = (code *)param_2;
      }
      if ((uVar4 != uVar8) && (*(longlong *)(lVar6 + 0x58) != 0)) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x48);
        *(undefined1 *)(lVar6 + 0x50) = uVar3;
        for (lVar2 = *(longlong *)(lVar6 + 0x58); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {
          LOCK();
          *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) | 8;
          UNLOCK();
        }
        pcVar5 = (code *)(ulonglong)*(byte *)(lVar6 + 0x50);
        KeReleaseSpinLock(lVar6 + 0x48);
        LOCK();
        iVar1 = *(int *)(lVar6 + 0x60);
        *(int *)(lVar6 + 0x60) = 1;
        UNLOCK();
        if (iVar1 == 0) {
          LOCK();
          *(int *)(lVar6 + 0x30) = *(int *)(lVar6 + 0x30) + 1;
          UNLOCK();
          param_3 = (undefined *)0x1;
          pcVar5 = lldpDeliverChangeNotifications;
          IoQueueWorkItemEx(*(undefined8 *)(lVar6 + 0x68),lldpDeliverChangeNotifications,1,lVar6);
        }
      }
      lVar6 = *(longlong *)(lVar6 + 0x28);
      param_2 = pcVar5;
    } while (lVar6 != 0);
  }
  return;
}



===== lldpEnablePort @ 140001ed0 =====

void lldpEnablePort(longlong param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar4 = *(uint *)(param_1 + 0x130);
  do {
    uVar5 = uVar4 & ~param_2;
    uVar6 = (ulonglong)uVar5;
    LOCK();
    uVar7 = *(uint *)(param_1 + 0x130);
    bVar8 = uVar4 == uVar7;
    if (bVar8) {
      *(uint *)(param_1 + 0x130) = uVar5;
    }
    else {
      uVar4 = uVar7;
    }
    UNLOCK();
  } while (!bVar8);
  uVar7 = ~param_2 & uVar4;
  if (uVar7 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids;
      uVar6 = 0xd;
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,
                (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
                (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
    }
    lldpEnableTxFastMode(param_1,uVar6,param_3);
  }
  if ((uVar4 != uVar7) && (*(longlong *)(param_1 + 0x58) != 0)) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
    *(undefined1 *)(param_1 + 0x50) = uVar3;
    for (lVar2 = *(longlong *)(param_1 + 0x58); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {
      LOCK();
      *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) | 8;
      UNLOCK();
    }
    KeReleaseSpinLock(param_1 + 0x48,*(undefined1 *)(param_1 + 0x50));
    LOCK();
    iVar1 = *(int *)(param_1 + 0x60);
    *(int *)(param_1 + 0x60) = 1;
    UNLOCK();
    if (iVar1 == 0) {
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x68),lldpDeliverChangeNotifications,1,param_1);
    }
  }
  return;
}



===== lldpEnableTxFastMode @ 140001ff0 =====

void lldpEnableTxFastMode(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = *(undefined4 *)(param_1 + 0x110);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids;
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,
               (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
               (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18),(char)uVar2);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x36c) = uVar2;
  UNLOCK();
  iVar3 = *(int *)(param_1 + 0x34);
  do {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x34);
    bVar5 = iVar3 == iVar1;
    if (bVar5) {
      *(int *)(param_1 + 0x34) = iVar3;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
  } while (!bVar5);
  if ((iVar3 == 4) || (iVar3 == 5)) {
    iVar3 = *(int *)(param_1 + 0x130);
    do {
      LOCK();
      iVar1 = *(int *)(param_1 + 0x130);
      bVar5 = iVar3 == iVar1;
      if (bVar5) {
        *(int *)(param_1 + 0x130) = iVar3;
      }
      else {
        iVar3 = iVar1;
      }
      UNLOCK();
    } while (!bVar5);
    if (((iVar3 == 0) && (iVar3 = *(int *)(param_1 + 0xf8), iVar3 != 0)) &&
       ((iVar3 == 1 || ((iVar3 != 2 && (iVar3 == 3)))))) {
      iVar3 = *(int *)(param_1 + 0x36c);
      do {
        LOCK();
        iVar1 = *(int *)(param_1 + 0x36c);
        bVar5 = iVar3 == iVar1;
        if (bVar5) {
          *(int *)(param_1 + 0x36c) = iVar3;
        }
        else {
          iVar3 = iVar1;
        }
        UNLOCK();
      } while (!bVar5);
      if (iVar3 == 0) {
        uVar4 = *(uint *)(param_1 + 0x100);
      }
      else {
        uVar4 = *(uint *)(param_1 + 0x10c);
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x35c) = 1;
      UNLOCK();
      lldpSetPeriodicTimer
                (param_1 + 0x248,uVar4,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1));
      return;
    }
  }
  KeCancelTimer(param_1 + 0x248);
  LOCK();
  iVar3 = *(int *)(param_1 + 0x35c);
  *(int *)(param_1 + 0x35c) = 0;
  UNLOCK();
  if (iVar3 != 0) {
    lldpTxSendShutdownPacket(param_1);
  }
  return;
}



===== lldpDisableAllPortsOnBinding @ 140002140 =====

void lldpDisableAllPortsOnBinding(longlong param_1,undefined *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  code *pcVar7;
  bool bVar8;
  
  pcVar7 = (code *)param_2;
  for (lVar3 = *(longlong *)(param_1 + 0x78); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x28)) {
    uVar6 = *(uint *)(lVar3 + 0x130);
    do {
      LOCK();
      uVar1 = *(uint *)(lVar3 + 0x130);
      bVar8 = uVar6 == uVar1;
      if (bVar8) {
        *(uint *)(lVar3 + 0x130) = uVar6 | (uint)param_2;
      }
      else {
        uVar6 = uVar1;
      }
      UNLOCK();
    } while (!bVar8);
    if (uVar6 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        pcVar7 = (code *)0x0;
        WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,
                   (uint)(ushort)((ulonglong)*(undefined8 *)(lVar3 + 0x78) >> 0x30),
                   (char)((ulonglong)*(undefined8 *)(lVar3 + 0x78) >> 0x18),(char)param_2);
      }
      pcVar7 = (code *)CONCAT71((int7)((ulonglong)pcVar7 >> 8),1);
      lldpRecalculateTxTimer(lVar3,(ulonglong)pcVar7);
    }
    if ((uVar6 != (uVar6 | (uint)param_2)) && (*(longlong *)(lVar3 + 0x58) != 0)) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x48);
      *(undefined1 *)(lVar3 + 0x50) = uVar5;
      for (lVar4 = *(longlong *)(lVar3 + 0x58); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 8)) {
        LOCK();
        *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 8;
        UNLOCK();
      }
      pcVar7 = (code *)(ulonglong)*(byte *)(lVar3 + 0x50);
      KeReleaseSpinLock(lVar3 + 0x48,pcVar7);
      LOCK();
      iVar2 = *(int *)(lVar3 + 0x60);
      *(int *)(lVar3 + 0x60) = 1;
      UNLOCK();
      if (iVar2 == 0) {
        LOCK();
        *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
        UNLOCK();
        pcVar7 = lldpDeliverChangeNotifications;
        IoQueueWorkItemEx(*(undefined8 *)(lVar3 + 0x68),lldpDeliverChangeNotifications,1,lVar3);
      }
    }
  }
  return;
}



===== lldpTxTtr @ 140002290 =====

void lldpTxTtr(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined2 local_res10;
  undefined1 local_res12;
  
  iVar2 = *(int *)(param_2 + 0xf8);
  local_res10 = 0;
  local_res12 = 0;
  if ((iVar2 == 0) || ((iVar2 != 1 && ((iVar2 == 2 || (iVar2 != 3)))))) {
    lldpRecalculateTxTimer(param_2,CONCAT71((int7)((ulonglong)param_2 >> 8),1));
  }
  else {
    LOCK();
    piVar1 = (int *)(param_2 + 0x36c);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      lVar7 = 0;
      lldpRecalculateTxTimer(param_2,0);
    }
    else {
      lVar7 = param_2;
      if (iVar2 + -1 < -10000000) {
        LOCK();
        *(undefined4 *)(param_2 + 0x36c) = 0;
        UNLOCK();
      }
    }
    LOCK();
    iVar2 = *(int *)(param_2 + 0x98);
    *(int *)(param_2 + 0x98) = 1;
    UNLOCK();
    if (iVar2 != 1) {
      NdisAcquireRWLockRead(*(undefined8 *)(param_2 + 0x3d0),&local_res10,1);
      if (*(char *)(param_2 + 0x97) != '\0') {
        uVar5 = *(int *)(param_2 + 0x88) - *(int *)(param_2 + 0x8c);
        lVar7 = *(longlong *)(param_2 + 0xb0);
        lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xa0) + 8);
        iVar2 = *(int *)(param_2 + 0x3dc);
        *(undefined4 *)(lVar7 + 6) = *(undefined4 *)(param_2 + 0x90);
        *(undefined2 *)(lVar7 + 10) = *(undefined2 *)(param_2 + 0x94);
        memmove((void *)((ulonglong)uVar5 + lVar7),(void *)(param_2 + 0x3e4),
                (ulonglong)*(uint *)(param_2 + 0x3dc));
        *(uint *)(lVar3 + 0x18) = iVar2 + uVar5;
        *(undefined1 *)(param_2 + 0x97) = 0;
      }
      NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x3d0),&local_res10);
      lVar7 = *(longlong *)(param_2 + 0xa0);
      lVar3 = *(longlong *)(lVar7 + 8);
      lVar4 = *(longlong *)(lVar3 + 8);
      if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 0x20) != 0) {
        lVar6 = (ulonglong)*(uint *)(lVar4 + 0x2c) + (ulonglong)*(uint *)(lVar3 + 0x10) +
                *(longlong *)(lVar4 + 0x20);
        McTemplateK0qqbr1_EtwWriteTransfer
                  (lVar6,&LldpduTransmitted,lVar4,*(undefined4 *)(param_2 + 0x80),
                   *(undefined4 *)(lVar3 + 0x18),lVar6);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                  &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,
                  (uint)(ushort)((ulonglong)*(undefined8 *)(param_2 + 0x78) >> 0x30),
                  (char)((ulonglong)*(undefined8 *)(param_2 + 0x78) >> 0x18));
      }
      NdisSendNetBufferLists
                (*(undefined8 *)(*(longlong *)(param_2 + 0x18) + 8),lVar7,
                 *(undefined4 *)(param_2 + 4),1);
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,param_3,
               *(undefined8 *)(param_2 + 0xa0));
    }
  }
  return;
}



===== lldpRecalculateTxTimer @ 1400024d0 =====

void lldpRecalculateTxTimer(longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = *(int *)(param_1 + 0x34);
  do {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x34);
    bVar4 = iVar2 == iVar1;
    if (bVar4) {
      *(int *)(param_1 + 0x34) = iVar2;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar4);
  if ((iVar2 == 4) || (iVar2 == 5)) {
    iVar2 = *(int *)(param_1 + 0x130);
    do {
      LOCK();
      iVar1 = *(int *)(param_1 + 0x130);
      bVar4 = iVar2 == iVar1;
      if (bVar4) {
        *(int *)(param_1 + 0x130) = iVar2;
      }
      else {
        iVar2 = iVar1;
      }
      UNLOCK();
    } while (!bVar4);
    if (((iVar2 == 0) && (iVar2 = *(int *)(param_1 + 0xf8), iVar2 != 0)) &&
       ((iVar2 == 1 || ((iVar2 != 2 && (iVar2 == 3)))))) {
      iVar2 = *(int *)(param_1 + 0x36c);
      do {
        LOCK();
        iVar1 = *(int *)(param_1 + 0x36c);
        bVar4 = iVar2 == iVar1;
        if (bVar4) {
          *(int *)(param_1 + 0x36c) = iVar2;
        }
        else {
          iVar2 = iVar1;
        }
        UNLOCK();
      } while (!bVar4);
      if (iVar2 == 0) {
        uVar3 = *(uint *)(param_1 + 0x100);
      }
      else {
        uVar3 = *(uint *)(param_1 + 0x10c);
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x35c) = 1;
      UNLOCK();
      lldpSetPeriodicTimer(param_1 + 0x248,uVar3,(undefined *)(param_2 & 0xff));
      return;
    }
  }
  KeCancelTimer(param_1 + 0x248);
  LOCK();
  iVar2 = *(int *)(param_1 + 0x35c);
  *(int *)(param_1 + 0x35c) = 0;
  UNLOCK();
  if (iVar2 != 0) {
    lldpTxSendShutdownPacket(param_1);
  }
  return;
}



===== lldpSetPeriodicTimer @ 1400025b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lldpSetPeriodicTimer(longlong param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  
  cVar3 = (char)param_3;
  if (((0xfffd < param_2 - 1) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_3fbb6981ec7538c7b4b2c49461eb0c03_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_3fbb6981ec7538c7b4b2c49461eb0c03_Traceguids,param_2);
  }
  lVar2 = _DAT_fffff78000000014;
  if (cVar3 == '\0') {
    lVar4 = (ulonglong)param_2 * 10000000 + _DAT_fffff78000000014;
  }
  else {
    lVar4 = _DAT_fffff78000000014;
  }
  *(longlong *)(param_1 + 0x80) = lVar4;
  iVar1 = lldpGetToleranceForTime(param_2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_iidd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar2,param_3,lVar4,(char)lVar2,
                (char)param_2,(char)iVar1);
  }
  KeSetCoalescableTimer(param_1,*(undefined8 *)(param_1 + 0x80),param_2 * 1000,iVar1,param_1 + 0x40)
  ;
  return;
}



===== lldpGetToleranceForTime @ 1400026b0 =====

int lldpGetToleranceForTime(uint param_1)

{
  if (6000 < param_1) {
    return 300000;
  }
  if (param_1 < 0xb) {
    return param_1 * 200;
  }
  return (param_1 + 0x1e) * 0x32;
}



===== lldpTxSendShutdownPacket @ 1400026dc =====

void lldpTxSendShutdownPacket(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  bool bVar7;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  uVar6 = *(uint *)(param_1 + 0x130);
  do {
    LOCK();
    uVar2 = *(uint *)(param_1 + 0x130);
    bVar7 = uVar6 == uVar2;
    if (bVar7) {
      *(uint *)(param_1 + 0x130) = uVar6;
    }
    else {
      uVar6 = uVar2;
    }
    UNLOCK();
  } while (!bVar7);
  if ((uVar6 & 2) == 0) {
    piVar1 = (int *)(param_1 + 0xb8);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
    if (iVar3 != 1) {
      uVar5 = KfRaiseIrql();
      NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x3d0),&local_res8,1);
      puVar4 = *(undefined4 **)(param_1 + 0xd0);
      *puVar4 = *(undefined4 *)(param_1 + 0x90);
      *(undefined2 *)(puVar4 + 1) = *(undefined2 *)(param_1 + 0x94);
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res8);
      lldpTransmitNblOnPort(param_1,(longlong)piVar1);
      KeLowerIrql(uVar5);
    }
  }
  return;
}



===== lldpTransmitNblOnPort @ 1400027c0 =====

void lldpTransmitNblOnPort(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_2 + 8);
  lVar2 = *(longlong *)(lVar1 + 8);
  lVar3 = *(longlong *)(lVar2 + 8);
  if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 0x20) != 0) {
    McTemplateK0qqbr1_EtwWriteTransfer
              (lVar2,&LldpduTransmitted,lVar3,*(undefined4 *)(param_1 + 0x80),
               *(undefined4 *)(lVar2 + 0x18),
               (ulonglong)*(uint *)(lVar3 + 0x2c) + (ulonglong)*(uint *)(lVar2 + 0x10) +
               *(longlong *)(lVar3 + 0x20));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,
              (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
              (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
  }
  NdisSendNetBufferLists
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8),lVar1,*(undefined4 *)(param_1 + 4),1
            );
  return;
}



===== lldpTlvTypeMatch @ 140002890 =====

ushort lldpTlvTypeMatch(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *param_1 >> 1 & 0x7f;
  if (uVar1 == *param_2) {
    if (uVar1 != 0x7f) {
      return 1;
    }
    uVar1 = param_2[2];
    iVar2 = (uint)param_1[1] - (uint)uVar1;
    if (iVar2 == 0) {
      uVar1 = 0;
      iVar2 = (uint)(byte)param_1[2] - (uint)(byte)param_2[3];
    }
    if (iVar2 == 0) {
      return (ushort)(*(char *)((longlong)param_1 + 5) == *(char *)((longlong)param_2 + 7));
    }
  }
  return uVar1 & 0xff00;
}



===== lldpReceivePermittedPacket @ 1400028e0 =====

void lldpReceivePermittedPacket(longlong param_1,ulonglong param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined2 uVar9;
  
  bVar4 = false;
  LOCK();
  piVar1 = (int *)(param_1 + 0x398);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(int *)(param_2 + 0x58) = iVar2 + 1;
  lVar7 = 0;
  lVar6 = NdisGetDataBuffer(param_2,*(uint *)(param_2 + 0x18),0,1,0);
  *(longlong *)(param_2 + 0x50) = lVar6;
  if (lVar6 == 0) {
    lVar6 = param_1 + 0x3a0;
    param_3 = 1;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar6);
    lVar7 = *(longlong *)(param_1 + 0x3b8);
    *(undefined1 *)(param_1 + 0x3a8) = uVar5;
    if (lVar7 == 0) {
      lVar7 = ExAllocatePool2(0x40,*(undefined4 *)(param_1 + 0x88),0x50444c4c);
      *(longlong *)(param_1 + 0x3b8) = lVar7;
      if (lVar7 != 0) {
        *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(param_1 + 0x88);
        goto LAB_140002a04;
      }
      KeReleaseSpinLock(lVar6,*(undefined1 *)(param_1 + 0x3a8));
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar9 = 0x17;
LAB_140002ac2:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
      }
    }
    else {
LAB_140002a04:
      uVar3 = *(uint *)(param_2 + 0x18);
      if (*(uint *)(param_1 + 0x3b0) < uVar3) {
        KeReleaseSpinLock(lVar6,CONCAT31((int3)(uVar3 >> 8),*(undefined1 *)(param_1 + 0x3a8)));
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                    &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids,*(undefined4 *)(param_2 + 0x18)
                    ,(char)*(undefined4 *)(param_1 + 0x3b0));
        }
      }
      else {
        lVar8 = NdisGetDataBuffer(param_2,uVar3,lVar7,1,0);
        *(longlong *)(param_2 + 0x50) = lVar8;
        if (lVar8 != 0) {
          bVar4 = true;
          goto LAB_140002ae8;
        }
        KeReleaseSpinLock(lVar6,*(undefined1 *)(param_1 + 0x3a8));
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x19;
          goto LAB_140002ac2;
        }
      }
    }
    lldpDrop(param_1,param_2,1);
  }
  else {
LAB_140002ae8:
    lldpReceiveContiguousPacket(param_1,param_2,CONCAT71((int7)((ulonglong)lVar7 >> 8),param_3));
    if (bVar4) {
      KeReleaseSpinLock(param_1 + 0x3a0,*(undefined1 *)(param_1 + 0x3a8));
    }
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  return;
}



===== lldpReceiveContiguousPacket @ 140002b40 =====

void lldpReceiveContiguousPacket(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  uint local_res20 [2];
  uint local_38;
  uint local_34 [3];
  
  local_res10 = 0;
  local_res12 = 0;
  if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 0x40) != 0) {
    McTemplateK0qqqbr2_EtwWriteTransfer
              (param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x80),
               (char)*(undefined4 *)(param_2 + 0x58),*(undefined4 *)(param_2 + 0x18),
               *(undefined8 *)(param_2 + 0x50));
  }
  local_res20[0] = 0;
  local_38 = 0;
  local_34[0] = 0;
  lVar2 = *(longlong *)(param_2 + 0x50);
  uVar1 = *(ushort *)(lVar2 + 0xc);
  uVar3 = 0x16;
  if (0x5ff < (ushort)(uVar1 >> 8 | uVar1 << 8)) {
    uVar3 = 0xe;
  }
  LOCK();
  *(longlong *)(param_1 + 0x388) = *(longlong *)(param_1 + 0x388) + 1;
  UNLOCK();
  puVar5 = (undefined *)((ulonglong)uVar3 + *(longlong *)(param_2 + 0x50));
  uVar4 = lldpValidateLldpduData
                    (param_1,param_2,puVar5,*(int *)(param_2 + 0x18) - uVar3,(int *)local_34,
                     (int *)&local_38,local_res20);
  if ((char)uVar4 == '\0') {
    LOCK();
    *(longlong *)(param_1 + 0x380) = *(longlong *)(param_1 + 0x380) + 1;
    UNLOCK();
  }
  else {
    NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x3c0),&local_res10,(char)param_3 != '\0');
    lldpUpdateNeighbor(param_1,param_2,(int *)(lVar2 + 6),puVar5,local_34[0],local_38,local_res20[0]
                      );
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3c0),&local_res10);
  }
  return;
}



===== lldpValidateLldpduData @ 140002cb0 =====

ulonglong lldpValidateLldpduData
                    (longlong param_1,ulonglong param_2,undefined *param_3,uint param_4,int *param_5
                    ,int *param_6,uint *param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined2 uVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  undefined *puVar11;
  byte bVar12;
  int iVar13;
  char cVar14;
  byte bVar15;
  undefined1 uVar16;
  
  bVar9 = 0;
  bVar12 = 0;
  bVar15 = 0;
  cVar14 = '\0';
  iVar13 = 0;
  *param_5 = 0;
  uVar4 = (ulonglong)param_4;
  *param_6 = 0;
  *param_7 = 0;
  uVar5 = param_2;
  puVar11 = param_3;
LAB_140002d10:
  uVar2 = (uint)uVar4;
  puVar6 = WPP_GLOBAL_Control;
  if ((uVar2 == 0) || (cVar14 != '\0')) {
    if ((bVar9 == 0) || (((bVar12 == 0 || (bVar15 == 0)) || (cVar14 == '\0')))) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        uVar5 = (ulonglong)bVar15;
        puVar11 = (undefined *)(ulonglong)bVar12;
        WPP_SF_DDDD(puVar6,uVar5,puVar11,(uint)bVar9,bVar12,bVar15,cVar14);
      }
      uVar4 = 0;
      if (Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits < '\0') {
        uVar16 = 4;
LAB_140002f04:
        uVar4 = McTemplateK0qqq_EtwWriteTransfer
                          (puVar6,uVar5,puVar11,*(undefined4 *)(param_1 + 0x80),
                           (char)*(undefined4 *)(param_2 + 0x58),uVar16);
      }
LAB_140002ec3:
      LOCK();
      *(longlong *)(param_1 + 0x378) = *(longlong *)(param_1 + 0x378) + 1;
      UNLOCK();
      uVar4 = uVar4 & 0xffffffffffffff00;
    }
    else {
      uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
    }
    return uVar4;
  }
  if (uVar2 < 2) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002f71;
    uVar7 = 10;
LAB_140003112:
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
            &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
LAB_140002f71:
    uVar5 = lldpDrop(param_1,param_2,7);
    return uVar5 & 0xffffffffffffff00;
  }
  uVar1 = *(ushort *)(param_3 + (param_4 - uVar2));
  uVar5 = (ulonglong)uVar1;
  uVar10 = (uVar1 & 1) * 0x100 + (uint)(uVar1 >> 8);
  puVar11 = (undefined *)(ulonglong)uVar10;
  if ((uVar2 < 6) && (((byte)uVar1 & 0xfe) == 0xfe)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002f71;
    uVar7 = 0xb;
    goto LAB_140003112;
  }
  if (uVar2 - 2 < uVar10) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar11 = &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids;
      uVar5 = 0xc;
      WPP_SF_(puVar6,0xc,&WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
    }
    uVar4 = 0;
    if (-1 < Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits) goto LAB_140002ec3;
    uVar16 = 7;
    goto LAB_140002f04;
  }
  uVar3 = (uVar2 - 2) - uVar10;
  uVar4 = (ulonglong)uVar3;
  uVar8 = uVar1 >> 1 & 0x7f;
  uVar5 = (ulonglong)uVar8;
  if ((uVar1 >> 1 & 0x7f) == 0) {
    if (uVar10 == 0) {
      cVar14 = '\x01';
      *param_6 = param_4 - uVar3;
LAB_140002d88:
      iVar13 = iVar13 + 1;
      goto LAB_140002d10;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002faa;
    uVar7 = 0x13;
  }
  else {
    if (uVar8 == 1) {
      if (iVar13 != 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002f38;
        uVar7 = 0xd;
LAB_140003099:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
LAB_140002f38:
        uVar5 = lldpDrop(param_1,param_2,6);
        return uVar5 & 0xffffffffffffff00;
      }
      if (0xfe < uVar10 - 2) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002faa;
        uVar7 = 0xe;
        goto LAB_1400030bd;
      }
      bVar9 = 1;
      iVar13 = 1;
      uVar5 = 0;
      goto LAB_140002d10;
    }
    uVar8 = uVar8 - 2;
    uVar5 = (ulonglong)uVar8;
    if (uVar8 == 0) {
      if (iVar13 != 1) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002f38;
        uVar7 = 0xf;
        goto LAB_140003099;
      }
      if (0xfe < uVar10 - 2) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002faa;
        uVar7 = 0x10;
        goto LAB_1400030bd;
      }
      bVar12 = 1;
      *param_5 = param_4 - uVar3;
      iVar13 = 2;
      goto LAB_140002d10;
    }
    if (uVar8 != 1) goto LAB_140002d88;
    if (iVar13 != 2) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002f38;
      uVar7 = 0x11;
      goto LAB_140003099;
    }
    if (1 < uVar10) {
      bVar15 = 1;
      iVar13 = 3;
      *param_7 = (uint)(ushort)(*(ushort *)(param_3 + (ulonglong)(param_4 - uVar2) + 2) >> 8 |
                               *(ushort *)(param_3 + (ulonglong)(param_4 - uVar2) + 2) << 8);
      goto LAB_140002d10;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140002faa;
    uVar7 = 0x12;
  }
LAB_1400030bd:
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
          &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
LAB_140002faa:
  uVar5 = lldpDrop(param_1,param_2,5);
  return uVar5 & 0xffffffffffffff00;
}



===== lldpUpdateNeighbor @ 140003170 =====

void lldpUpdateNeighbor(longlong param_1,longlong param_2,int *param_3,undefined *param_4,
                       uint param_5,uint param_6,uint param_7)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined **ppuVar8;
  ulonglong uVar9;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (*(uint *)(param_1 + 0x8c) < param_6) {
    ppuVar8 = &WPP_GLOBAL_Control;
    puVar5 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      param_3 = (int *)&WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids;
      ppuVar8 = (undefined **)0x16;
      WPP_SF_DD(puVar5,0x16,&WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids,param_6,
                (char)*(uint *)(param_1 + 0x8c));
    }
    if ((char)Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits < '\0') {
      McTemplateK0qqq_EtwWriteTransfer
                (puVar5,ppuVar8,param_3,*(undefined4 *)(param_1 + 0x80),
                 (char)*(undefined4 *)(param_2 + 0x58),1);
    }
    LOCK();
    *(longlong *)(param_1 + 0x378) = *(longlong *)(param_1 + 0x378) + 1;
    UNLOCK();
    return;
  }
  KeQuerySystemTimePrecise(&local_res8);
  lVar7 = *(longlong *)(param_1 + 0x3c8);
  if (lVar7 == 0) {
    uVar4 = lldpAllocateNewNeighbor(param_1,param_3,param_4,param_5,param_6);
    if ((char)uVar4 == '\0') {
      lldpDrop(param_1,param_2,1);
      return;
    }
    uVar4 = 0;
    lldpQueueChangeNotificationEx(param_1,0,0x10);
    uVar9 = (ulonglong)param_7;
    puVar5 = (undefined *)CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    lldpSetTimer(param_1 + 0x138,param_7,'\x01');
    lldpEnableTxFastMode(param_1,uVar9,puVar5);
  }
  else {
    if (*(uint *)(lVar7 + 0xc) == param_5) {
      uVar9 = (ulonglong)param_5;
      iVar3 = memcmp((void *)(lVar7 + 0x18),param_4,uVar9);
      if (iVar3 == 0) {
        if (param_7 == 0) {
          lVar7 = param_1;
          lldpDeleteNeighborOnPort(param_1);
          bVar1 = true;
          if (*(longlong *)(param_1 + 0x58) != 0) {
            uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
            *(undefined1 *)(param_1 + 0x50) = uVar2;
            for (lVar7 = *(longlong *)(param_1 + 0x58); lVar7 != 0; lVar7 = *(longlong *)(lVar7 + 8)
                ) {
              LOCK();
              *(uint *)(lVar7 + 0x20) = *(uint *)(lVar7 + 0x20) | 0x40;
              UNLOCK();
            }
            lVar7 = param_1 + 0x48;
            KeReleaseSpinLock(lVar7,*(undefined1 *)(param_1 + 0x50));
            LOCK();
            iVar3 = *(int *)(param_1 + 0x60);
            *(int *)(param_1 + 0x60) = 1;
            UNLOCK();
            if (iVar3 == 0) {
              LOCK();
              *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
              UNLOCK();
              lVar7 = *(longlong *)(param_1 + 0x68);
              uVar9 = 1;
              IoQueueWorkItemEx(lVar7,lldpDeliverChangeNotifications,1,param_1);
            }
          }
          if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 2) != 0) {
            McTemplateK0qqbr1_EtwWriteTransfer
                      (lVar7,&RemoteMibShutdown,uVar9,*(undefined4 *)(param_1 + 0x80),param_5,
                       param_4);
          }
        }
        else {
          if ((*(uint *)(lVar7 + 0x10) == param_6) &&
             (iVar3 = memcmp((void *)(lVar7 + 0x18),param_4,(ulonglong)param_6), iVar3 == 0)) {
            bVar1 = false;
          }
          else {
            memmove((void *)(lVar7 + 0x18),param_4,(ulonglong)param_6);
            *(uint *)(lVar7 + 0x10) = param_6;
            bVar1 = true;
            uVar4 = 2;
            lVar6 = param_1;
            lldpQueueChangeNotificationEx(param_1,0,2);
            if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 4) != 0) {
              McTemplateK0qqbr1_EtwWriteTransfer
                        (lVar6,&RemoteMibChanged,uVar4,*(undefined4 *)(param_1 + 0x80),param_5,
                         param_4);
            }
          }
          iVar3 = *(int *)(lVar7 + 4) - *param_3;
          if (iVar3 == 0) {
            iVar3 = (uint)*(ushort *)(lVar7 + 8) - (uint)*(ushort *)(param_3 + 1);
          }
          if (iVar3 != 0) {
            *(int *)(lVar7 + 4) = *param_3;
            bVar1 = true;
            *(short *)(lVar7 + 8) = (short)param_3[1];
            lldpQueueChangeNotificationEx(param_1,0,8);
          }
          lldpSetTimer(param_1 + 0x138,param_7,'\x01');
        }
        *(undefined8 *)(param_1 + 0xe0) = local_res8;
        if (!bVar1) {
          return;
        }
        goto LAB_14000349a;
      }
    }
    uVar9 = (ulonglong)param_5;
    lVar7 = param_1;
    lldpSetTooManyNeighbors(param_1,param_4,uVar9,param_7);
    if ((char)Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits < '\0') {
      McTemplateK0qqq_EtwWriteTransfer
                (lVar7,param_4,uVar9,*(undefined4 *)(param_1 + 0x80),
                 (char)*(undefined4 *)(param_2 + 0x58),9);
    }
    LOCK();
    *(longlong *)(param_1 + 0x378) = *(longlong *)(param_1 + 0x378) + 1;
    UNLOCK();
  }
  *(undefined8 *)(param_1 + 0xe0) = local_res8;
LAB_14000349a:
  *(undefined8 *)(param_1 + 0xe8) = local_res8;
  return;
}



===== lldpSetTimer @ 1400034d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lldpSetTimer(longlong param_1,uint param_2,char param_3)

{
  longlong lVar1;
  int iVar2;
  
  if (((0xfffd < param_2 - 1) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_3fbb6981ec7538c7b4b2c49461eb0c03_Traceguids,param_2);
  }
  lVar1 = (ulonglong)param_2 * 10000000 + _DAT_fffff78000000014;
  if ((param_3 != '\0') || (*(longlong *)(param_1 + 0x80) < lVar1)) {
    if (param_2 < 0x1771) {
      if (param_2 < 0xb) {
        iVar2 = param_2 * 200;
      }
      else {
        iVar2 = (param_2 + 0x1e) * 0x32;
      }
    }
    else {
      iVar2 = 300000;
    }
    KeSetCoalescableTimer(param_1,lVar1,0,iVar2,param_1 + 0x40);
  }
  return;
}



===== lldpSetTooManyNeighbors @ 1400035b0 =====

void lldpSetTooManyNeighbors(longlong param_1,undefined *param_2,undefined8 param_3,uint param_4)

{
  longlong lVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  if (param_4 != 0) {
    puVar2 = (undefined *)(ulonglong)param_4;
    puVar3 = param_2;
    uVar4 = param_3;
    if (*(char *)(param_1 + 0xd8) == '\0') {
      *(undefined1 *)(param_1 + 0xd8) = 1;
      lldpQueueChangeNotificationEx(param_1,0,8);
      lVar1 = param_1 + 0x1c0;
      uVar4 = 0;
      lldpSetTimer(lVar1,param_4,'\0');
      puVar3 = puVar2;
      if ((DAT_14000b591 & 1) != 0) {
        puVar3 = &TooManyNeighborsBegin;
        McTemplateK0q_EtwWriteTransfer
                  (lVar1,&TooManyNeighborsBegin,uVar4,*(undefined4 *)(param_1 + 0x80));
      }
    }
    if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 8) != 0) {
      lVar1 = *(longlong *)(param_1 + 0x3c8);
      McTemplateK0qqbr1qbr3_EtwWriteTransfer
                (lVar1,puVar3,uVar4,*(undefined4 *)(param_1 + 0x80),*(undefined4 *)(lVar1 + 0xc),
                 lVar1 + 0x18,(int)param_3,param_2);
    }
  }
  return;
}



===== lldpDrop @ 140003674 =====

void lldpDrop(longlong param_1,longlong param_2,undefined8 param_3)

{
  if (Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits < '\0') {
    McTemplateK0qqq_EtwWriteTransfer
              (param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x80),
               (char)*(undefined4 *)(param_2 + 0x58),(char)param_3);
  }
  LOCK();
  *(longlong *)(param_1 + 0x378) = *(longlong *)(param_1 + 0x378) + 1;
  UNLOCK();
  return;
}



===== lldpFindAndReferencePort @ 1400036c0 =====

longlong lldpFindAndReferencePort(longlong *param_1)

{
  longlong lVar1;
  
  DAT_14000b520 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b518);
  lVar1 = DAT_14000b528;
  do {
    if (lVar1 == 0) {
LAB_140003713:
      KeReleaseSpinLock(&DAT_14000b518,DAT_14000b520);
      return lVar1;
    }
    if ((*(longlong *)(lVar1 + 0x78) == *param_1) && (*(int *)(lVar1 + 0x84) == (int)param_1[1])) {
      LOCK();
      *(int *)(lVar1 + 0x30) = *(int *)(lVar1 + 0x30) + 1;
      UNLOCK();
      goto LAB_140003713;
    }
    lVar1 = *(longlong *)(lVar1 + 0x20);
  } while( true );
}



===== lldpDisablePort @ 140003750 =====

void lldpDisablePort(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 uVar6;
  bool bVar7;
  
  uVar5 = *(uint *)(param_1 + 0x130);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x130);
    bVar7 = uVar5 == uVar1;
    if (bVar7) {
      *(uint *)(param_1 + 0x130) = uVar5 | (uint)param_2;
    }
    else {
      uVar5 = uVar1;
    }
    UNLOCK();
  } while (!bVar7);
  if (uVar5 == 0) {
    uVar6 = param_2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar6 = 0;
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,
                 (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
                 (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18),(char)param_2);
    }
    lldpRecalculateTxTimer(param_1,CONCAT71((int7)((ulonglong)uVar6 >> 8),1));
  }
  if ((uVar5 != (uVar5 | (uint)param_2)) && (*(longlong *)(param_1 + 0x58) != 0)) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
    *(undefined1 *)(param_1 + 0x50) = uVar4;
    for (lVar3 = *(longlong *)(param_1 + 0x58); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 8)) {
      LOCK();
      *(uint *)(lVar3 + 0x20) = *(uint *)(lVar3 + 0x20) | 8;
      UNLOCK();
    }
    KeReleaseSpinLock(param_1 + 0x48,*(undefined1 *)(param_1 + 0x50));
    LOCK();
    iVar2 = *(int *)(param_1 + 0x60);
    *(int *)(param_1 + 0x60) = 1;
    UNLOCK();
    if (iVar2 == 0) {
      LOCK();
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      UNLOCK();
      IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x68),lldpDeliverChangeNotifications,1,param_1);
    }
  }
  return;
}



===== lldpQueryTlvs @ 140003880 =====

int lldpQueryTlvs(longlong param_1,int param_2,ulonglong param_3,longlong param_4,size_t param_5,
                 ulonglong *param_6,uint *param_7)

{
  int iVar1;
  undefined2 local_res10;
  undefined1 local_res12;
  
  iVar1 = 0;
  local_res10 = 0;
  local_res12 = 0;
  if (param_2 == 1) {
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x3d0),&local_res10,0);
    lldpQueryMib(param_1 + 0x3d8,param_3,param_4,param_5,param_6,param_7);
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res10);
  }
  else {
    if (param_2 != 2) {
      return -0x3fffff10;
    }
    NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x3c0),&local_res10,0);
    if (*(longlong *)(param_1 + 0x3c8) == 0) {
      iVar1 = -0x3ffffddb;
    }
    else {
      lldpQueryMib(*(longlong *)(param_1 + 0x3c8) + 0xc,param_3,param_4,param_5,param_6,param_7);
    }
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3c0),&local_res10);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  if (param_5 < *param_6) {
    return -0x3fffffdd;
  }
  return 0;
}



===== lldpQueryMib @ 1400039d0 =====

void lldpQueryMib(longlong param_1,ulonglong param_2,longlong param_3,size_t param_4,
                 ulonglong *param_5,uint *param_6)

{
  uint uVar1;
  ushort uVar2;
  ulonglong uVar3;
  uint *_Dst;
  ushort *puVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ushort uVar8;
  ulonglong uVar9;
  ushort *_Src;
  uint *puVar10;
  
  puVar10 = (uint *)0x0;
  if (param_6 != (uint *)0x0) {
    if (param_4 == 0) goto LAB_140003a29;
    puVar10 = (uint *)(param_4 + (longlong)param_6);
    memset(param_6,0,param_4);
  }
  if (3 < param_4) {
    *param_6 = 0;
  }
LAB_140003a29:
  uVar5 = *(uint *)(param_1 + 4);
  puVar4 = (ushort *)(param_1 + 0xc);
  *param_5 = 4;
  if (param_1 + 0xeU < (ulonglong)uVar5 + 0xc + param_1) {
    do {
      uVar8 = *puVar4;
      uVar7 = (ulonglong)uVar8;
      uVar6 = (ulonglong)(uVar8 >> 8);
      uVar5 = (uint)(uVar8 >> 8);
      uVar8 = uVar8 & 0xfe;
      uVar9 = (ulonglong)uVar8;
      if (uVar8 == 0) {
        return;
      }
      if (param_2 == 0) {
LAB_140003aad:
        _Src = puVar4 + 1;
        uVar5 = ((uint)uVar7 & 1) * 0x100 + (uVar5 & 0xffff);
        if (uVar8 == 0xfe) {
          if (uVar5 < 4) goto LAB_140003b83;
          uVar5 = uVar5 - 4;
          _Src = puVar4 + 3;
        }
        uVar6 = (ulonglong)uVar5;
        *param_5 = *param_5 + (uVar6 + 3 & 0xfffffffffffffffc) + 0x14;
        if ((*param_5 <= param_4) &&
           (uVar1 = *param_6,
           (longlong)param_6 + (ulonglong)uVar1 * 0x14 + 6 <= param_4 + (longlong)param_6)) {
          *(short *)(param_6 + (ulonglong)uVar1 * 5 + 3) = (short)uVar5;
          *(ushort *)(param_6 + (ulonglong)uVar1 * 5 + 1) = (ushort)(uVar7 >> 1) & 0x7f;
          param_6[(ulonglong)uVar1 * 5 + 5] = 0;
          if ((*puVar4 & 0xfe) == 0xfe) {
            *(ushort *)(param_6 + (ulonglong)uVar1 * 5 + 2) = puVar4[1];
            *(char *)((longlong)param_6 + (ulonglong)uVar1 * 0x14 + 10) = (char)puVar4[2];
            *(undefined1 *)((longlong)param_6 + (ulonglong)uVar1 * 0x14 + 0xb) =
                 *(undefined1 *)((longlong)puVar4 + 5);
          }
          else {
            param_6[(ulonglong)uVar1 * 5 + 2] = 0;
          }
          _Dst = (uint *)((longlong)puVar10 - uVar6 & 0xfffffffffffffffc);
          if (param_6 + (ulonglong)uVar1 * 5 + 6 <= _Dst) {
            param_6[(ulonglong)uVar1 * 5 + 4] =
                 ((uint)((longlong)puVar10 - uVar6) & 0xfffffffc) - (int)param_6;
            memmove(_Dst,_Src,uVar6);
            *param_6 = *param_6 + 1;
            puVar10 = _Dst;
          }
        }
      }
      else {
        for (uVar3 = 0; uVar3 < param_2; uVar3 = (ulonglong)((int)uVar3 + 1)) {
          uVar2 = lldpTlvTypeMatch(puVar4,(ushort *)(param_3 + uVar3 * 8));
          uVar5 = (uint)uVar6;
          uVar8 = (ushort)uVar9;
          if ((char)uVar2 != '\0') goto LAB_140003aad;
        }
      }
LAB_140003b83:
      puVar4 = (ushort *)
               ((longlong)puVar4 + (ulonglong)(*puVar4 & 1) * 0x100 + 2 + (ulonglong)(*puVar4 >> 8))
      ;
    } while (puVar4 + 1 < (ushort *)((ulonglong)*(uint *)(param_1 + 4) + 0xc + param_1));
  }
  return;
}



===== lldpPreparePacket @ 140003be0 =====

undefined8 lldpPreparePacket(undefined4 *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  bVar1 = false;
  DAT_14000b560 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b558);
  if (DAT_14000b568 != '\0') {
    uVar6 = 0xc0000001;
    KeReleaseSpinLock(&DAT_14000b558,DAT_14000b560);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids);
    }
    goto LAB_140003d60;
  }
  LOCK();
  DAT_14000b550 = DAT_14000b550 + 1;
  UNLOCK();
  bVar1 = true;
  KeReleaseSpinLock(&DAT_14000b558,DAT_14000b560);
  *param_1 = 0;
  lVar2 = NdisAllocateMdl(DAT_14000b4d0,*(undefined8 *)(param_1 + 6),param_2);
  *(longlong *)(param_1 + 4) = lVar2;
  if (lVar2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0xb;
LAB_140003ce1:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
              &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids);
    }
  }
  else {
    lVar2 = NdisAllocateNetBufferAndNetBufferList(DAT_14000b570,0,0,lVar2,0,param_2);
    *(longlong *)(param_1 + 2) = lVar2;
    if (lVar2 != 0) {
      puVar5 = *(undefined4 **)(param_1 + 6);
      puVar3 = lldpMacAddressFromScope(param_3);
      *puVar5 = *puVar3;
      *(undefined2 *)(puVar5 + 1) = *(undefined2 *)(puVar3 + 1);
      *(undefined2 *)(puVar5 + 3) = 0xcc88;
      goto LAB_140003d60;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0xc;
      goto LAB_140003ce1;
    }
  }
  uVar6 = 0xc000009a;
LAB_140003d60:
  if ((*(longlong *)(param_1 + 2) == 0) && (bVar1)) {
    lldpDereferencePacketPool();
  }
  return uVar6;
}



===== lldpMacAddressFromScope @ 140003da0 =====

undefined4 * lldpMacAddressFromScope(int param_1)

{
  if (param_1 != 1) {
    if (param_1 == 2) {
      return &LLDP_DEST_MAC_NEAREST_NON_TPMR_BRIDGE;
    }
    if (param_1 == 3) {
      return &LLDP_DEST_MAC_NEAREST_CUSTOMER_BRIDGE;
    }
  }
  return &LLDP_DEST_MAC_NEAREST_BRIDGE;
}



===== lldpProtSendNetBufferListsComplete @ 140003dd0 =====

void lldpProtSendNetBufferListsComplete(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  if (param_2 != (undefined8 *)0x0) {
    do {
      lVar1 = param_2[8];
      puVar2 = (undefined8 *)*param_2;
      if (*(int *)((longlong)param_2 + 0x8c) == 0) {
        LOCK();
        *(longlong *)(lVar1 + 0x390) = *(longlong *)(lVar1 + 0x390) + 1;
        UNLOCK();
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,*(int *)((longlong)param_2 + 0x8c)
                );
      }
      *param_2 = 0;
      if (param_2 == *(undefined8 **)(lVar1 + 0xa0)) {
        lVar3 = 0x98;
LAB_140003e52:
        LOCK();
        *(undefined4 *)(lVar3 + lVar1) = 0;
        UNLOCK();
      }
      else if (param_2 == *(undefined8 **)(lVar1 + 0xc0)) {
        lVar3 = 0xb8;
        goto LAB_140003e52;
      }
      param_2 = puVar2;
    } while (puVar2 != (undefined8 *)0x0);
  }
  return;
}



===== RtlUnicodeStringPrintf @ 140003e90 =====

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
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    uVar5 = 0;
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



===== lldpQueueChangeNotificationEx @ 140003f50 =====

void lldpQueueChangeNotificationEx(longlong param_1,longlong param_2,uint param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  if (param_2 == 0) {
    if (*(longlong *)(param_1 + 0x58) == 0) {
      return;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
    *(undefined1 *)(param_1 + 0x50) = uVar3;
    for (lVar2 = *(longlong *)(param_1 + 0x58); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 8)) {
      LOCK();
      *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) | param_3;
      UNLOCK();
    }
    KeReleaseSpinLock(param_1 + 0x48,*(undefined1 *)(param_1 + 0x50));
  }
  else {
    LOCK();
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | param_3;
    UNLOCK();
  }
  LOCK();
  iVar1 = *(int *)(param_1 + 0x60);
  *(int *)(param_1 + 0x60) = 1;
  UNLOCK();
  if (iVar1 == 0) {
    LOCK();
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    UNLOCK();
    IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x68),lldpDeliverChangeNotifications,1,param_1);
  }
  return;
}



===== lldpPortStateIsVisibleToClients @ 140004000 =====

undefined1 lldpPortStateIsVisibleToClients(int param_1)

{
  if ((((param_1 == 5) || (param_1 == 3)) || (param_1 == 4)) || (param_1 == 6)) {
    return 1;
  }
  return 0;
}



===== lldpCopyTlvToMib @ 140004030 =====

void lldpCopyTlvToMib(ushort *param_1,uint param_2,longlong param_3,ulonglong param_4)

{
  longlong lVar1;
  ushort *_Dst;
  
  if (1 < param_2) {
    lVar1 = param_3 + (param_4 & 0xffffffff) * 0x14;
    *param_1 = (*(short *)(param_3 + 4 + (param_4 & 0xffffffff) * 0x14) * 2 ^ *param_1) & 0xfe ^
               *param_1;
    _Dst = param_1 + 1;
    *(char *)((longlong)param_1 + 1) = (char)(param_2 - 2);
    *param_1 = ((ushort)(param_2 - 2 >> 8) ^ *param_1) & 1 ^ *param_1;
    if (*(short *)(lVar1 + 4) == 0x7f) {
      *_Dst = *(ushort *)(lVar1 + 8);
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(lVar1 + 10);
      _Dst = param_1 + 3;
      *(undefined1 *)((longlong)param_1 + 5) = *(undefined1 *)(lVar1 + 0xb);
    }
    if ((ulonglong)*(ushort *)(lVar1 + 0xc) + (longlong)_Dst <=
        (longlong)param_1 + (ulonglong)param_2) {
      memmove(_Dst,(void *)((ulonglong)*(uint *)(lVar1 + 0x10) + param_3),
              (ulonglong)*(ushort *)(lVar1 + 0xc));
    }
  }
  return;
}



===== lldpEnumeratePorts @ 1400040f0 =====

uint lldpEnumeratePorts(longlong param_1,ulonglong param_2,ulonglong *param_3)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  *param_3 = 0;
  uVar5 = 0;
  DAT_14000b520 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b518);
  for (lVar2 = DAT_14000b528; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x20)) {
    iVar3 = *(int *)(lVar2 + 0x34);
    do {
      LOCK();
      iVar1 = *(int *)(lVar2 + 0x34);
      bVar6 = iVar3 == iVar1;
      if (bVar6) {
        *(int *)(lVar2 + 0x34) = iVar3;
      }
      else {
        iVar3 = iVar1;
      }
      UNLOCK();
    } while (!bVar6);
    if ((((iVar3 == 5) || (iVar3 == 3)) || (iVar3 == 4)) || (iVar3 == 6)) {
      uVar4 = (ulonglong)uVar5;
      if (uVar4 < param_2) {
        *(undefined8 *)(param_1 + uVar4 * 0x10) = *(undefined8 *)(lVar2 + 0x78);
        *(undefined4 *)(param_1 + 8 + uVar4 * 0x10) = *(undefined4 *)(lVar2 + 0x84);
        *(undefined4 *)(param_1 + 0xc + uVar4 * 0x10) = 0;
      }
      uVar5 = uVar5 + 1;
    }
  }
  KeReleaseSpinLock(&DAT_14000b518,DAT_14000b520);
  *param_3 = (ulonglong)uVar5;
  return -(uint)(param_2 < uVar5) & 0xc0000023;
}



===== lldpSetPortMacAddress @ 1400041f0 =====

void lldpSetPortMacAddress(longlong param_1,undefined4 *param_2)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x3d0),&local_res8,0);
  *(undefined4 *)(param_1 + 0x90) = *param_2;
  *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)(param_1 + 0x97) = 1;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res8);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(byte *)(param_2 + 1),
                    (ulonglong)*(byte *)((longlong)param_2 + 3),
                    (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
                    (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18),
                    *(undefined1 *)param_2,*(undefined1 *)((longlong)param_2 + 1),
                    *(undefined1 *)((longlong)param_2 + 2),*(byte *)((longlong)param_2 + 3),
                    *(byte *)(param_2 + 1),*(undefined1 *)((longlong)param_2 + 5));
  }
  return;
}



===== lldpDeliverSpecialUnbindNotifications @ 1400042dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lldpDeliverSpecialUnbindNotifications(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lldpAcquireInterLock(&DAT_14000b540,'\0');
  lldpAcquireInterLock((int *)(param_1 + 0x38),'\0');
  lVar3 = param_1 + 0x48;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3);
  do {
    lVar4 = *(longlong *)(param_1 + 0x58);
    *(undefined1 *)(param_1 + 0x50) = uVar2;
    while( true ) {
      if (lVar4 == 0) {
        KeReleaseSpinLock(lVar3,*(undefined1 *)(param_1 + 0x50));
        lldpReleaseInterLock((uint *)(param_1 + 0x38));
        DAT_14000b500 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4f8);
        for (lVar3 = DAT_14000b508; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 8)) {
          *(undefined1 *)(lVar3 + 0x19) = 0;
        }
        KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
        if (DAT_14000b540 == 0) {
          LOCK();
          DAT_14000b548 = 0;
          UNLOCK();
        }
        else {
          DAT_14000b540 = DAT_14000b540 + -1;
        }
        return;
      }
      lVar1 = *(longlong *)(lVar4 + 0x10);
      if (((*(char *)(lVar1 + 0x19) == '\0') &&
          (*(undefined1 *)(lVar1 + 0x19) = 1, (*(uint *)(lVar1 + 4) & 4) != 0)) &&
         (*(longlong *)(lVar1 + 0x40) != 0)) break;
      lVar4 = *(longlong *)(lVar4 + 8);
    }
    KeReleaseSpinLock(lVar3,*(undefined1 *)(param_1 + 0x50));
    (**(code **)(lVar1 + 0x40))(lVar4,*(undefined8 *)(lVar1 + 0x28),*(undefined8 *)(lVar4 + 0x28));
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3);
  } while( true );
}



===== lldpReleaseInterLock @ 140004428 =====

ulonglong lldpReleaseInterLock(uint *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (*param_1 == 0) {
    LOCK();
    uVar2 = *(ulonglong *)(param_1 + 2);
    *(ulonglong *)(param_1 + 2) = 0;
    UNLOCK();
    return uVar2;
  }
  uVar1 = *param_1 - 1;
  *param_1 = uVar1;
  return (ulonglong)uVar1;
}



===== lldpGetConfig @ 140004450 =====

undefined4 lldpGetConfig(longlong param_1,uint param_2)

{
  if (param_2 < 7) {
    return *(undefined4 *)(param_1 + 0xf8 + (longlong)(int)param_2 * 4);
  }
  return 0;
}



===== lldpCopyMibToNetBuffer @ 140004470 =====

void lldpCopyMibToNetBuffer(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar4 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x8c);
  iVar1 = *(int *)(param_1 + 0x3dc);
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 8) + 8);
  *(undefined4 *)(lVar2 + 6) = *(undefined4 *)(param_1 + 0x90);
  *(undefined2 *)(lVar2 + 10) = *(undefined2 *)(param_1 + 0x94);
  memmove((void *)((ulonglong)uVar4 + lVar2),(void *)(param_1 + 0x3e4),
          (ulonglong)*(uint *)(param_1 + 0x3dc));
  *(uint *)(lVar3 + 0x18) = iVar1 + uVar4;
  return;
}



===== lldpAddPortToDriver @ 1400044f0 =====

void lldpAddPortToDriver(longlong param_1)

{
  DAT_14000b520 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b518);
  *(longlong *)(param_1 + 0x20) = DAT_14000b528;
  DAT_14000b528 = param_1;
  KeReleaseSpinLock(&DAT_14000b518,DAT_14000b520);
  *(undefined1 *)(param_1 + 0x96) = 1;
  return;
}



===== lldpSetMibTtl @ 140004554 =====

void lldpSetMibTtl(longlong param_1,ushort param_2)

{
  ushort *puVar1;
  ulonglong uVar2;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x3d0),&local_res8,0);
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x3d8);
  *(ushort *)(uVar2 + 0x3e6 + param_1) = param_2 >> 8 | param_2 << 8;
  *(ushort *)(uVar2 + 0x3e4 + param_1) = *(ushort *)(uVar2 + 0x3e4 + param_1) & 0xff07 | 6;
  *(undefined1 *)(uVar2 + 0x3e5 + param_1) = 2;
  puVar1 = (ushort *)(uVar2 + 0x3e4 + param_1);
  *puVar1 = *puVar1 & 0xfffe;
  *(undefined1 *)(param_1 + 0x97) = 1;
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res8);
  return;
}



===== lldpCancelTimer @ 140004604 =====

void lldpCancelTimer(void)

{
  KeCancelTimer();
  return;
}



===== lldpRemovePortFromDriver @ 140004620 =====

void lldpRemovePortFromDriver(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  DAT_14000b520 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b518);
  lVar2 = DAT_14000b528;
  if (DAT_14000b528 == param_1) {
    DAT_14000b528 = *(longlong *)(param_1 + 0x20);
  }
  else {
    do {
      if (lVar2 == 0) goto LAB_140004673;
      plVar1 = (longlong *)(lVar2 + 0x20);
      lVar2 = *plVar1;
    } while (lVar2 != param_1);
    *plVar1 = *(longlong *)(param_1 + 0x20);
  }
LAB_140004673:
  KeReleaseSpinLock(&DAT_14000b518,DAT_14000b520);
  return;
}



===== lldpDeliverCreateNotifications @ 14000469c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lldpDeliverCreateNotifications(undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_1c = 0;
  local_28 = param_1;
  local_20 = param_2;
  lldpAcquireInterLock(&DAT_14000b530,'\0');
  do {
    DAT_14000b500 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4f8);
    lVar1 = DAT_14000b508;
    while( true ) {
      if (lVar1 == 0) {
        for (lVar1 = DAT_14000b508; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 8)) {
          *(undefined1 *)(lVar1 + 0x18) = 0;
        }
        KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
        if (DAT_14000b530 == 0) {
          LOCK();
          DAT_14000b538 = 0;
          UNLOCK();
        }
        else {
          DAT_14000b530 = DAT_14000b530 + -1;
        }
        return;
      }
      if (((*(char *)(lVar1 + 0x18) == '\0') &&
          (*(undefined1 *)(lVar1 + 0x18) = 1, (*(uint *)(lVar1 + 4) & 2) == 0)) &&
         (*(longlong *)(lVar1 + 0x38) != 0)) break;
      lVar1 = *(longlong *)(lVar1 + 8);
    }
    LOCK();
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    UNLOCK();
    KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
    (**(code **)(lVar1 + 0x38))(&local_28,*(undefined8 *)(lVar1 + 0x28));
    lldpDereferenceClient(lVar1);
  } while( true );
}



===== lldpRemoveBindingFromDriver @ 1400047b4 =====

void lldpRemoveBindingFromDriver(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  DAT_14000b4e8 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4e0);
  lVar2 = DAT_14000b4f0;
  if (DAT_14000b4f0 == param_1) {
    DAT_14000b4f0 = *(longlong *)(param_1 + 0x18);
  }
  else {
    do {
      if (lVar2 == 0) goto LAB_140004807;
      plVar1 = (longlong *)(lVar2 + 0x18);
      lVar2 = *plVar1;
    } while (lVar2 != param_1);
    *plVar1 = *(longlong *)(param_1 + 0x18);
  }
LAB_140004807:
  KeReleaseSpinLock(&DAT_14000b4e0,DAT_14000b4e8);
  return;
}



===== lldpTooManyNeighborsTimer @ 140004830 =====

void lldpTooManyNeighborsTimer(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x3c0),&local_res10,1);
  bVar3 = *(char *)(param_2 + 0xd8) != '\0';
  if (bVar3) {
    *(undefined1 *)(param_2 + 0xd8) = 0;
  }
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x3c0));
  if (bVar3) {
    uVar2 = 8;
    lVar1 = param_2;
    lldpQueueChangeNotificationEx(param_2,0,8);
    if ((DAT_14000b591 & 1) != 0) {
      McTemplateK0q_EtwWriteTransfer
                (lVar1,&TooManyNeighborsEnd,uVar2,*(undefined4 *)(param_2 + 0x80));
    }
  }
  return;
}



===== lldpReferencePort @ 1400048d4 =====

void lldpReferencePort(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  UNLOCK();
  return;
}



===== lldpProtOidRequestComplete @ 1400048e0 =====

void lldpProtOidRequestComplete(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0xdc) = param_3;
  KeSetEvent(*(undefined8 *)(param_2 + 0xe0),0,0);
  return;
}



===== lldpAddBindingToDriver @ 140004910 =====

void lldpAddBindingToDriver(longlong param_1)

{
  DAT_14000b4e8 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4e0);
  *(longlong *)(param_1 + 0x18) = DAT_14000b4f0;
  DAT_14000b4f0 = param_1;
  KeReleaseSpinLock(&DAT_14000b4e0,DAT_14000b4e8);
  *(undefined1 *)(param_1 + 0x20) = 1;
  return;
}



===== McTemplateK0qqqbr2_EtwWriteTransfer @ 140004970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqbr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined4 param_6,undefined8 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 4;
  local_58 = local_res20;
  local_1c = 0;
  local_48 = &param_5;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = param_6;
  local_40 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&LldpduReceived,param_3,5,local_68);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004a08 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000b008;
  uVar2 = 0;
  if (DAT_14000b008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000b008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(LLDP_ETW_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McGenEventRegister_EtwRegister @ 140004a6c =====

void McGenEventRegister_EtwRegister(void)

{
  if (LLDP_ETW_PROVIDER_Context == 0) {
    EtwRegister(&LLDP_ETW_PROVIDER,McGenControlCallbackV2,&LLDP_ETW_PROVIDER_Context,
                &LLDP_ETW_PROVIDER_Context);
  }
  return;
}



===== lldpRxInfoTtlTimer @ 140004ab0 =====

void lldpRxInfoTtlTimer(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  uVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  local_res10 = 0;
  local_res12 = 0;
  bVar2 = false;
  NdisAcquireRWLockWrite(*(undefined8 *)(param_2 + 0x3c0),&local_res10);
  lVar1 = *(longlong *)(param_2 + 0x3c8);
  if (lVar1 != 0) {
    if ((DAT_14000b591 & 1) != 0) {
      McTemplateK0qqbr1_EtwWriteTransfer
                (lVar1,&RemoteMibExpired,uVar3,*(undefined4 *)(param_2 + 0x80),
                 *(undefined4 *)(lVar1 + 0xc),lVar1 + 0x18);
    }
    lldpDeleteNeighborOnPort(param_2);
    bVar2 = true;
  }
  NdisReleaseRWLock(*(undefined8 *)(param_2 + 0x3c0));
  if (bVar2) {
    lldpQueueChangeNotificationEx(param_2,0,0x20);
    LOCK();
    *(longlong *)(param_2 + 0x370) = *(longlong *)(param_2 + 0x370) + 1;
    UNLOCK();
  }
  return;
}



===== WPP_SF_ @ 140004b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== lldpDeleteNeighborOnPort @ 140004b9c =====

void lldpDeleteNeighborOnPort(longlong param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x3c8);
  *(undefined8 *)(param_1 + 0x3c8) = 0;
  *puVar1 = 0;
  ExFreePoolWithTag(puVar1,0x50444c4c);
  KeCancelTimer(param_1 + 0x138);
  return;
}



===== __report_gsfailure @ 140004c00 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WPP_SF_D @ 140004c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== LldpSetDeviceDacl @ 140004c54 =====

int LldpSetDeviceDacl(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = ObOpenObjectByPointer(param_1,0x200,0,0x40000,0,0,local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140004d07;
    uVar2 = 0xb;
  }
  else {
    iVar1 = ZwSetSecurityObject(local_res10[0],4,&DAT_140009640);
    if (((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140004d07;
    uVar2 = 0xc;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_ea1b45b0a6943981c34a08d8d3c26e2c_Traceguids,iVar1);
LAB_140004d07:
  if (local_res10[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140004d2c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000ae5f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140004d54 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004eb0 =====

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



===== lldpClientFromHandle @ 140004f34 =====

int * lldpClientFromHandle(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (piVar1 = param_1, *param_1 != 0x63444c4c)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== lldpNmrProviderAttachClient @ 140004f50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
lldpNmrProviderAttachClient
          (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
          longlong *param_5,undefined8 *param_6,undefined8 *param_7)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined2 uVar5;
  
  if (((param_6 == (undefined8 *)0x0) || (param_7 == (undefined8 *)0x0)) ||
     (puVar2 = *(ushort **)(param_3 + 0x20), puVar2 == (ushort *)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar5 = 0xd;
  }
  else {
    uVar1 = *puVar2;
    if ((uVar1 & 0x7fff) != 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids,uVar1 & 0xffff7fff);
      }
      return 0xc0000058;
    }
    if (3 < puVar2[1]) {
      lVar4 = **(longlong **)(param_3 + 8) - _NPI_LLDP_INTERFACE_ID;
      if (lVar4 == 0) {
        lVar4 = (*(longlong **)(param_3 + 8))[1] - _DAT_14000b158;
      }
      if (lVar4 == 0) {
        puVar3 = lldpAllocateClient((byte)(uVar1 >> 0xf),param_1,param_5,param_4);
        if (puVar3 == (undefined4 *)0x0) {
          return 0xc000009a;
        }
        *param_6 = puVar3;
        *param_7 = &PTR_lldpNmrEnumerate_140009020;
        DAT_14000b500 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4f8);
        *(undefined4 **)(puVar3 + 2) = DAT_14000b508;
        DAT_14000b508 = puVar3;
        KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids);
      }
      return 0xc00002b9;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar5 = 0xf;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
          &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids);
  return 0xc000000d;
}



===== lldpNmrProviderCleanupBindingContext @ 140005130 =====

void lldpNmrProviderCleanupBindingContext(int *param_1)

{
  int *piVar1;
  
  piVar1 = lldpClientFromHandle(param_1);
  *(undefined1 *)piVar1 = 0;
  ExFreePoolWithTag(piVar1,0x50444c4c);
  return;
}



===== lldpNmrProviderDetachClient @ 140005160 =====

undefined8 lldpNmrProviderDetachClient(int *param_1)

{
  int *piVar1;
  
  piVar1 = lldpClientFromHandle(param_1);
  lldpBeginDetachClient((longlong)piVar1);
  return 0x103;
}



===== lldpOpenPortFromHandle @ 140005184 =====

int * lldpOpenPortFromHandle(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (piVar1 = param_1, *param_1 != 0x6f444c4c)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== lldpVerifyAddressIsNonpaged @ 1400051a0 =====

undefined8 lldpVerifyAddressIsNonpaged(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    uVar1 = CONCAT71((uint7)(uint3)(*(uint *)(param_1 + 4) >> 8),1);
  }
  else {
    uVar1 = MmIsNonPagedSystemAddressValid(param_2);
  }
  return uVar1;
}



===== FxStubDriverUnloadCommon @ 1400051cc =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14000b470,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140005210 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined *param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 140005244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *puVar4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2,param_3);
  }
  else {
    _DAT_14000b470 = 0x2080000;
    _DAT_14000b478 = &DAT_14000b260;
    RtlCopyUnicodeString(&DAT_14000b470);
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000b470,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000b468 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000b470);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b1d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1400053d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000b468 != (code *)0x0) && (DAT_14000b468 != FxStubDriverUnload)) {
    (*DAT_14000b468)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140005404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140005429) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x14000b1cf < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14000b1d8 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 140005564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b1d8 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_14000b1d8 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 140005620 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 140005668 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140005685) */
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
    if ((void **)0x14000b1ef < ppvVar2) break;
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



===== WPP_SF_SD @ 140005730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
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
            (param_1,0x2b,&WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,0x14,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF_SDD @ 1400057c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

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
            (param_1,0x2b,&WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,0x13,param_4,lVar1,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_s @ 140005860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

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
            (param_1,0x2b,&WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,0xe,param_4,lVar2,0);
  return;
}



===== WPP_SF_sDD @ 1400058cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_18 [6];
  
  local_18[0] = 0xff;
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
            (param_1,0x2b,&WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,0xd,param_4,lVar2,
             &param_5,4,local_18,4,0);
  return;
}



===== McGenControlCallbackV2 @ 140005970 =====

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



===== McGenEventUnregister_EtwUnregister @ 140005a80 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (LLDP_ETW_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    LLDP_ETW_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 140005ab4 =====

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



===== WppClassicProviderCallback @ 140005b00 =====

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



===== lldpMarkDriverUnloading @ 140005b34 =====

void lldpMarkDriverUnloading(void)

{
  DAT_14000b560 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b558);
  DAT_14000b568 = 1;
  KeReleaseSpinLock(&DAT_14000b558,DAT_14000b560);
  return;
}



===== WPP_SF_DD @ 140005b7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 140005bcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DDDDDDDD @ 140005c28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,0xf,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== lldpQueryPortStatus @ 140005cd0 =====

void lldpQueryPortStatus(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  int iVar4;
  bool bVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  iVar4 = *(int *)(param_1 + 0x130);
  do {
    LOCK();
    iVar1 = *(int *)(param_1 + 0x130);
    bVar5 = iVar4 == iVar1;
    if (bVar5) {
      *(int *)(param_1 + 0x130) = iVar4;
    }
    else {
      iVar4 = iVar1;
    }
    UNLOCK();
  } while (!bVar5);
  *(byte *)(param_2 + 0x10) =
       ((*(byte *)(param_1 + 0xd8) & 1) * '\x02' ^ *(byte *)(param_2 + 0x10) & 0xfd) & 0xc3 |
       ~((char)iVar4 * '\x02') & 0x20U | ~((char)iVar4 << 2) & 0x1cU;
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x3d0),&local_res8,0);
  *(undefined4 *)(param_2 + 0x11) = *(undefined4 *)(param_1 + 0x90);
  *(undefined2 *)(param_2 + 0x15) = *(undefined2 *)(param_1 + 0x94);
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3d0),&local_res8);
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x3c0),&local_res8,0);
  if (*(longlong *)(param_1 + 0x3c8) == 0) {
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xfe;
    uVar3 = 0;
    *(undefined4 *)(param_2 + 0x17) = 0;
  }
  else {
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 1;
    lVar2 = *(longlong *)(param_1 + 0x3c8);
    *(undefined4 *)(param_2 + 0x17) = *(undefined4 *)(lVar2 + 4);
    uVar3 = *(undefined2 *)(lVar2 + 8);
  }
  *(undefined2 *)(param_2 + 0x1b) = uVar3;
  *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 0xe0);
  *(undefined8 *)(param_2 + 0x28) = *(undefined8 *)(param_1 + 0xe8);
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x3c0),&local_res8);
  *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_1 + 0xf0);
  return;
}



===== WPP_SF_Dd @ 140005e18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids,0xc,local_res20,4,
             &param_5,4,0);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 140005e70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
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



===== McTemplateK0qqbr1_EtwWriteTransfer @ 140005ecc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqbr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_40 = 4;
  local_28 = param_6;
  local_20 = param_5;
  local_30 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0qqbr1qbr3_EtwWriteTransfer @ 140005f48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqbr1qbr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 4;
  local_68 = local_res20;
  local_3c = 0;
  local_58 = &param_5;
  local_48 = param_6;
  local_40 = param_5;
  local_38 = &param_7;
  local_28 = param_8;
  local_20 = param_7;
  local_1c = 0;
  local_50 = 4;
  local_30 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&TooManyNeighborsReceive,param_3,6,local_78);
  return;
}



===== McTemplateK0qqq_EtwWriteTransfer @ 140005ff4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_40 = 4;
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&LldpduDiscarded,param_3,4,local_58);
  return;
}



===== WPP_SF_DDDD @ 140006070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids,0x14,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== lldpAllocateNewNeighbor @ 1400060e0 =====

ulonglong lldpAllocateNewNeighbor
                    (longlong param_1,undefined4 *param_2,void *param_3,undefined4 param_4,
                    uint param_5)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  undefined4 *_Dst;
  ulonglong _Size;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,*(int *)(param_1 + 0x8c) + 0x19,0x50444c4c);
  if (puVar1 == (undefined4 *)0x0) {
    ppuVar2 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      ppuVar2 = (undefined **)
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                        &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids);
    }
    uVar3 = (ulonglong)ppuVar2 & 0xffffffffffffff00;
  }
  else {
    *(undefined8 *)(puVar1 + 1) = 0;
    *(undefined8 *)(puVar1 + 5) = 0;
    puVar1[4] = param_5;
    _Size = (ulonglong)param_5;
    *puVar1 = 0x6e444c4c;
    _Dst = puVar1 + 6;
    puVar1[3] = param_4;
    puVar1[5] = *(undefined4 *)(param_1 + 0x8c);
    memmove(_Dst,param_3,_Size);
    puVar1[1] = *param_2;
    uVar3 = (ulonglong)*(ushort *)(param_2 + 1);
    *(ushort *)(puVar1 + 2) = *(ushort *)(param_2 + 1);
    if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 2) != 0) {
      uVar3 = McTemplateK0qqbr1_EtwWriteTransfer
                        (_Dst,&RemoteMibAdded,_Size,*(undefined4 *)(param_1 + 0x80),param_4,param_3)
      ;
    }
    *(undefined4 **)(param_1 + 0x3c8) = puVar1;
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



===== WPP_SF_q @ 1400061f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,0x11,&local_res20,8,0);
  return;
}



===== _guard_check_icall @ 140006240 =====

void _guard_check_icall(void)

{
  return;
}



===== lldpBeginDetachClient @ 14000624c =====

void lldpBeginDetachClient(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  DAT_14000b500 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4f8);
  lVar2 = DAT_14000b508;
  if (DAT_14000b508 == param_1) {
    DAT_14000b508 = *(longlong *)(param_1 + 8);
  }
  else {
    do {
      plVar1 = (longlong *)(lVar2 + 8);
      lVar2 = *plVar1;
      if (lVar2 == 0) goto LAB_14000629f;
    } while (lVar2 != param_1);
    *plVar1 = *(longlong *)(param_1 + 8);
  }
LAB_14000629f:
  *(longlong *)(param_1 + 8) = DAT_14000b510;
  DAT_14000b510 = param_1;
  KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  lldpDereferenceClient(param_1);
  return;
}



===== lldpDereferenceClient @ 1400062e4 =====

void lldpDereferenceClient(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x10);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    LOCK();
    iVar3 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = 0;
    UNLOCK();
    if (iVar3 != 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x20);
      DAT_14000b500 = KeAcquireSpinLockRaiseToDpc(&DAT_14000b4f8);
      lVar5 = DAT_14000b510;
      if (DAT_14000b510 == param_1) {
        DAT_14000b510 = *(longlong *)(param_1 + 8);
      }
      else {
        do {
          plVar2 = (longlong *)(lVar5 + 8);
          lVar5 = *plVar2;
          if (lVar5 == 0) goto LAB_140006359;
        } while (lVar5 != param_1);
        *plVar2 = *(longlong *)(param_1 + 8);
      }
LAB_140006359:
      KeReleaseSpinLock(&DAT_14000b4f8,DAT_14000b500);
      *(undefined8 *)(param_1 + 0x20) = 0;
      NmrProviderDetachClientComplete(uVar4);
    }
  }
  return;
}



===== lldpReferenceClient @ 140006398 =====

void lldpReferenceClient(longlong param_1)

{
  LOCK();
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  UNLOCK();
  return;
}



===== lldpAttachOpenPort @ 1400063a4 =====

void lldpAttachOpenPort(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x48);
  *(undefined1 *)(lVar1 + 0x50) = uVar2;
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(lVar1 + 0x58);
  *(longlong *)(lVar1 + 0x58) = param_1;
  lldpQueueChangeNotificationEx(lVar1,param_1,0x40000000);
  KeReleaseSpinLock(lVar1 + 0x48,*(undefined1 *)(lVar1 + 0x50));
  return;
}



===== lldpDeliverChangeNotifications @ 140006420 =====

void lldpDeliverChangeNotifications(undefined8 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  
  if (param_2 == (undefined1 *)0x0) {
    return;
  }
  LOCK();
  *(undefined4 *)(param_2 + 0x60) = 0;
  UNLOCK();
  lldpAcquireInterLock((int *)(param_2 + 0x38),'\0');
  do {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x48);
    lVar2 = *(longlong *)(param_2 + 0x58);
    param_2[0x50] = uVar1;
    while( true ) {
      if (lVar2 == 0) {
        KeReleaseSpinLock(param_2 + 0x48,param_2[0x50]);
        lldpReleaseInterLock((uint *)(param_2 + 0x38));
        lldpDereferencePort(param_2);
        return;
      }
      if ((*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x30) != 0) && (*(int *)(lVar2 + 0x20) != 0))
      break;
      lVar2 = *(longlong *)(lVar2 + 8);
    }
    KeReleaseSpinLock(param_2 + 0x48,param_2[0x50]);
    lldpDeliverOneChangeNotification(lVar2);
  } while( true );
}



===== lldpDetachOpenPort @ 1400064dc =====

void lldpDetachOpenPort(undefined1 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x48);
  *(undefined1 *)(lVar2 + 0x50) = uVar3;
  puVar4 = *(undefined1 **)(lVar2 + 0x58);
  if (puVar4 == param_1) {
    *(undefined8 *)(lVar2 + 0x58) = *(undefined8 *)(param_1 + 8);
  }
  else {
    do {
      if (puVar4 == (undefined1 *)0x0) goto LAB_140006530;
      plVar1 = (longlong *)(puVar4 + 8);
      puVar4 = (undefined1 *)*plVar1;
    } while (puVar4 != param_1);
    *plVar1 = *(longlong *)(param_1 + 8);
  }
LAB_140006530:
  KeReleaseSpinLock(lVar2 + 0x48,*(undefined1 *)(lVar2 + 0x50));
  lldpAcquireInterLock((int *)(lVar2 + 0x38),'\x01');
  lldpReleaseInterLock((uint *)(lVar2 + 0x38));
  *(undefined8 *)(param_1 + 8) = 0;
  lldpDeleteOpenPort(param_1);
  return;
}



===== WPP_SF_iidd @ 14000657c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iidd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_3fbb6981ec7538c7b4b2c49461eb0c03_Traceguids,0xc,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== __GSHandlerCheck @ 1400065f8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000661c =====

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



===== __cpu_features_init @ 140006690 =====

/* WARNING: Removing unreachable block (ram,0x0001400066fa) */
/* WARNING: Removing unreachable block (ram,0x0001400066a9) */
/* WARNING: Removing unreachable block (ram,0x00014000669a) */

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



===== __security_check_cookie @ 140006760 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400067a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400067d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400067d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140006800 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140006860 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400068a3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140006914;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140006910:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140006914;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000690c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140006910;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000690c;
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
LAB_140006914:
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
LAB_1400068a3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140006980 =====

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



===== memset @ 140006c80 =====

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



===== __memset_repmovs @ 140006dc0 =====

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



===== __memset_query @ 140006e40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006ec0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007000 =====

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



===== __memset_spec_plain @ 140007080 =====

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



===== lldpInitializeControlDevice @ 14000e008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lldpInitializeControlDevice(void)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  undefined1 auStack_138 [32];
  undefined8 *local_118;
  undefined8 local_108;
  longlong local_100 [2];
  wchar_t *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined8 local_d8 [2];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_bb;
  code *local_a0;
  undefined4 local_78;
  wchar_t local_68 [24];
  wchar_t local_38 [20];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_138;
  local_108 = 0;
  memset(&local_c8,0,0x60);
  local_d8[0] = 0;
  builtin_wcsncpy(local_38,L"\\Device\\LLDPCTRL",0x11);
  builtin_wcsncpy(local_68,L"\\DosDevices\\LLDPCTRL",0x15);
  local_e0 = local_68;
  local_100[1] = 0x220020;
  local_e8 = 0x2a0028;
  local_f0 = local_38;
  local_100[0] = (**(code **)(WdfFunctions_01015 + 200))
                           (WdfDriverGlobals,lldpWdfDriver,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL);
  if (local_100[0] == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_ea1b45b0a6943981c34a08d8d3c26e2c_Traceguids);
    }
    iVar1 = -0x3fffff66;
    goto LAB_14000e3be;
  }
  (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_100[0],2);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_100[0],local_100 + 1);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
    uVar3 = 0xe;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x220))
                      (WdfDriverGlobals,local_100[0],&SDDL_DEVOBJ_KERNEL_ONLY);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,local_100,0,&local_108);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
        uVar3 = 0x10;
      }
      else {
        lVar2 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_108);
        if (lVar2 != 0) {
          iVar1 = LldpSetDeviceDacl(lVar2);
          if (iVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
            uVar3 = 0x11;
            goto LAB_14000e252;
          }
        }
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x280))(WdfDriverGlobals,local_108,&local_e8);
        if (iVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
          uVar3 = 0x12;
        }
        else {
          local_78 = 0xffffffff;
          local_118 = local_d8;
          local_a0 = lldpEvtIoDeviceControl;
          local_c8 = 0x60;
          local_c0 = 2;
          local_bb = 1;
          local_c4 = 2;
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_108,&local_c8,0);
          if (-1 < iVar1) {
            (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,local_108);
            goto LAB_14000e3be;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
          uVar3 = 0x13;
        }
      }
LAB_14000e252:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_ea1b45b0a6943981c34a08d8d3c26e2c_Traceguids,iVar1);
      goto LAB_14000e3be;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e3be;
    uVar3 = 0xf;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_ea1b45b0a6943981c34a08d8d3c26e2c_Traceguids);
LAB_14000e3be:
  if (local_100[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  return iVar1;
}



===== WppLoadTracingSupport @ 14000e408 =====

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



===== lldpInitializeInterLock @ 14000e54c =====

void lldpInitializeInterLock(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  return;
}



===== WppInitKm @ 14000e560 =====

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



===== lldpGetPortAdminConfig @ 14000e5f0 =====

void lldpGetPortAdminConfig(longlong param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  *param_2 = 1;
  *(undefined8 *)(param_2 + 2) = 0x2c;
  puVar4 = &DAT_14000b064;
  uVar3 = 0;
  do {
    uVar2 = lldpGetConfig(param_1,uVar3);
    uVar1 = *puVar4;
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 6;
    *(undefined4 *)((ulonglong)uVar1 + (longlong)param_2) = uVar2;
  } while (uVar3 < 7);
  return;
}



===== lldpDriverUnloadWdf @ 14000e640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lldpDriverUnloadWdf(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 uVar1;
  
  lldpMarkDriverUnloading();
  lldpNmrDeregisterProvider();
  lldpDereferencePacketPool();
  if (DAT_14000b4d0 != 0) {
    NdisDeregisterProtocolDriver();
    DAT_14000b4d0 = 0;
  }
  uVar1 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x3b0))();
  lldpUnloadDriverCore(uVar1,param_1,param_3);
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_UninitializeFeatureStaging @ 14000e6ac =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000e704 =====

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
      goto LAB_14000e761;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000e761;
    }
  }
  uVar1 = 0x206;
LAB_14000e761:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000e76c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
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
  plVar1 = (longlong *)&wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000e824 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000e85c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000e8de;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000e8de;
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
LAB_14000e8de:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000e930 =====

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
      plVar2 = (longlong *)&wil_details_featureDescriptors_a;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000e990 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000e9ac =====

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
  plVar2 = (longlong *)&wil_details_featureDescriptors_a;
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



===== lldpIoctlGetVersion @ 14000ea60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lldpIoctlGetVersion(undefined8 *param_1)

{
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)param_1 = 1;
  memset(&local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  *(undefined4 *)((longlong)param_1 + 4) = local_134;
  *(undefined4 *)(param_1 + 1) = local_130;
  *(undefined4 *)((longlong)param_1 + 0xc) = local_12c;
  return;
}



===== lldpIoctlQueryConfig @ 14000eaec =====

undefined8 lldpIoctlQueryConfig(longlong *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)lldpFindAndReferencePort(param_1);
  memset(param_2,0,0x48);
  if (puVar1 == (undefined1 *)0x0) {
    *param_2 = 0xc0000225;
  }
  else {
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(puVar1 + 0x78);
    param_2[4] = *(undefined4 *)(puVar1 + 0x84);
    lldpGetPortAdminConfig((longlong)puVar1,param_2 + 6);
    lldpDereferencePort(puVar1);
  }
  return 0;
}



===== lldpIoctlQueryCurrentStatus @ 14000eb54 =====

undefined8 lldpIoctlQueryCurrentStatus(longlong *param_1,void *param_2)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined1 *)lldpFindAndReferencePort(param_1);
  if (puVar1 == (undefined1 *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    memset(param_2,0,0x40);
    *(undefined8 *)((longlong)param_2 + 0x10) = 0x38;
    *(undefined4 *)((longlong)param_2 + 8) = 2;
    lldpQueryPortStatus((longlong)puVar1,(longlong)param_2 + 8);
    lldpDereferencePort(puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== lldpIoctlQueryStatistics @ 14000ebbc =====

undefined8 lldpIoctlQueryStatistics(longlong *param_1,undefined8 *param_2)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined1 *)lldpFindAndReferencePort(param_1);
  if (puVar1 == (undefined1 *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    *(undefined4 *)(param_2 + 1) = 1;
    param_2[2] = 0x28;
    *(int *)(param_2 + 3) = (int)*(undefined8 *)(puVar1 + 0x370);
    *(int *)((longlong)param_2 + 0x1c) = (int)*(undefined8 *)(puVar1 + 0x378);
    *(int *)(param_2 + 4) = (int)*(undefined8 *)(puVar1 + 0x380);
    *(int *)((longlong)param_2 + 0x24) = (int)*(undefined8 *)(puVar1 + 0x388);
    *(int *)(param_2 + 5) = (int)*(undefined8 *)(puVar1 + 0x390);
    lldpDereferencePort(puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== lldpProtSetOptions @ 14000ec40 =====

void lldpProtSetOptions(void)

{
  lldpInitializePacketPool();
  return;
}



===== lldpNmrClose @ 14000ec60 =====

void lldpNmrClose(int *param_1)

{
  int *piVar1;
  
  piVar1 = lldpOpenPortFromHandle(param_1);
  if (piVar1 != (int *)0x0) {
    lldpDetachOpenPort((undefined1 *)piVar1);
  }
  return;
}



===== lldpNmrDcnOidRequest @ 14000ec90 =====

ulonglong lldpNmrDcnOidRequest(int *param_1,undefined4 *param_2)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  puVar6 = param_2;
  piVar3 = lldpOpenPortFromHandle(param_1);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xc0000008;
  }
  else {
    uVar5 = lldpVerifyAddressIsNonpaged(*(longlong *)(piVar3 + 4),puVar6);
    if ((char)uVar5 == '\0') {
      uVar4 = 0xc000000d;
    }
    else {
      lVar1 = *(longlong *)(piVar3 + 6);
      lldpAcquireInterLock((int *)(lVar1 + 8),'\0');
      if (*(longlong *)(lVar1 + 0x18) == 0) {
        uVar4 = 0xc0000056;
      }
      else {
        iVar2 = lldpSendOidRequestAndWait(*(longlong *)(lVar1 + 0x18),param_2);
        uVar4 = 0xc00000bb;
        if (iVar2 != -0x3fffff45) {
          if (iVar2 == -0x3ffeffea) {
            uVar4 = 0xc0000023;
          }
          else {
            uVar4 = (ulonglong)(-(uint)(iVar2 != 0) & 0xc0000001);
          }
        }
      }
      lldpReleaseInterLock((uint *)(lVar1 + 8));
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}



===== lldpNmrDeregisterProvider @ 14000ed3c =====

void lldpNmrDeregisterProvider(void)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_14000b4d8 == 0) {
    return;
  }
  iVar1 = NmrDeregisterProvider();
  if (iVar1 == 0x103) {
    iVar1 = NmrWaitForProviderDeregisterComplete(DAT_14000b4d8);
    if (iVar1 == 0) {
      DAT_14000b4d8 = 0;
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      DAT_14000b4d8 = 0;
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      DAT_14000b4d8 = 0;
      return;
    }
    uVar2 = 0x12;
  }
  else {
    if (iVar1 == 0) {
      DAT_14000b4d8 = 0;
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      DAT_14000b4d8 = 0;
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      DAT_14000b4d8 = 0;
      return;
    }
    uVar2 = 0x13;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids,iVar1);
  DAT_14000b4d8 = 0;
  return;
}



===== lldpNmrEnumerate @ 14000edf0 =====

uint lldpNmrEnumerate(int *param_1,longlong param_2,ulonglong param_3,ulonglong *param_4)

{
  uint uVar1;
  int *piVar2;
  longlong lVar3;
  undefined8 uVar4;
  int *piVar5;
  longlong lVar6;
  ulonglong *puVar7;
  ulonglong local_18 [2];
  
  lVar6 = param_2;
  puVar7 = param_4;
  piVar2 = lldpClientFromHandle(param_1);
  local_18[0] = 0;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0xc0000008;
  }
  else {
    piVar5 = piVar2;
    lVar3 = lldpReferenceClient((longlong)piVar2);
    if ((*(uint *)(lVar3 + 4) & 2) == 0) {
      if (param_4 == (ulonglong *)0x0) {
        uVar1 = 0xc00000f2;
      }
      else if ((param_3 == 0) || (param_2 != 0)) {
        *puVar7 = 0;
        if ((param_2 != 0) &&
           (uVar4 = lldpVerifyAddressIsNonpaged((longlong)piVar5,lVar6), (char)uVar4 == '\0')) {
          return 0xc000000d;
        }
        uVar1 = lldpEnumeratePorts(param_2,param_3,local_18);
        *param_4 = local_18[0];
      }
      else {
        uVar1 = 0xc0000030;
      }
    }
    else {
      uVar1 = 0xc0000056;
    }
    lldpDereferenceClient((longlong)piVar2);
  }
  return uVar1;
}



===== lldpNmrOpen @ 14000eec0 =====

undefined8 lldpNmrOpen(int *param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  longlong *plVar6;
  
  uVar3 = 0;
  plVar6 = param_4;
  piVar2 = lldpClientFromHandle(param_1);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0xc0000008;
  }
  else {
    lVar4 = lldpReferenceClient((longlong)piVar2);
    if ((*(uint *)(lVar4 + 4) & 2) == 0) {
      if ((((param_4 == (longlong *)0x0) || (param_2 == (longlong *)0x0)) ||
          (*(int *)((longlong)param_2 + 0xc) != 0)) ||
         (((iVar1 = (int)param_2[1], iVar1 != 1 && (iVar1 != 2)) && (iVar1 != 3)))) {
        uVar3 = 0xc000000d;
      }
      else {
        *plVar6 = 0;
        puVar5 = (undefined1 *)lldpFindAndReferencePort(param_2);
        if (puVar5 == (undefined1 *)0x0) {
          uVar3 = 0xc0000225;
        }
        else {
          lVar4 = lldpOpenPort((longlong)puVar5,(longlong)piVar2,param_3);
          lldpDereferencePort(puVar5);
          if (lVar4 == 0) {
            uVar3 = 0xc000009a;
          }
          else {
            *param_4 = lVar4;
            lldpAttachOpenPort(lVar4);
          }
        }
      }
    }
    else {
      uVar3 = 0xc0000056;
    }
    lldpDereferenceClient((longlong)piVar2);
  }
  return uVar3;
}



===== lldpNmrQueryConfig @ 14000efb0 =====

undefined8 lldpNmrQueryConfig(int *param_1,int *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = lldpOpenPortFromHandle(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000008;
  }
  else if ((*param_2 == 1) && (0x2b < *(ulonglong *)(param_2 + 2))) {
    lldpGetPortAdminConfig(*(longlong *)(piVar1 + 6),param_2);
    uVar2 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids);
    }
    uVar2 = 0xc0000058;
  }
  return uVar2;
}



===== lldpNmrQueryStatistics @ 14000f020 =====

undefined8 lldpNmrQueryStatistics(int *param_1,int *param_2)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  
  piVar2 = lldpOpenPortFromHandle(param_1);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0xc0000008;
  }
  else if ((*param_2 == 1) && (0x23 < *(ulonglong *)(param_2 + 2))) {
    lVar1 = *(longlong *)(piVar2 + 6);
    param_2[4] = (int)*(undefined8 *)(lVar1 + 0x370);
    param_2[5] = (int)*(undefined8 *)(lVar1 + 0x378);
    param_2[6] = (int)*(undefined8 *)(lVar1 + 0x380);
    param_2[7] = (int)*(undefined8 *)(lVar1 + 0x388);
    param_2[8] = (int)*(undefined8 *)(lVar1 + 0x390);
    uVar3 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids);
    }
    uVar3 = 0xc0000058;
  }
  return uVar3;
}



===== lldpNmrQueryStatus @ 14000f0c0 =====

undefined8 lldpNmrQueryStatus(int *param_1,int *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = lldpOpenPortFromHandle(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000008;
  }
  else if ((*param_2 == 1) && (0x1c < *(ulonglong *)(param_2 + 2))) {
    lldpQueryPortStatus(*(longlong *)(piVar1 + 6),(longlong)param_2);
    uVar2 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids);
    }
    uVar2 = 0xc0000058;
  }
  return uVar2;
}



===== lldpNmrQueryTlvs @ 14000f130 =====

int lldpNmrQueryTlvs(int *param_1,int param_2,ulonglong param_3,longlong param_4,size_t param_5,
                    ulonglong *param_6,uint *param_7)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  ulonglong local_28 [2];
  
  piVar2 = lldpOpenPortFromHandle(param_1);
  local_28[0] = 0;
  if (piVar2 == (int *)0x0) {
    return -0x3ffffff8;
  }
  if (((param_4 == 0) ||
      (uVar3 = lldpVerifyAddressIsNonpaged(*(longlong *)(piVar2 + 4),param_4), (char)uVar3 != '\0'))
     && ((param_7 == (uint *)0x0 ||
         (uVar3 = lldpVerifyAddressIsNonpaged(*(longlong *)(piVar2 + 4),param_7),
         (char)uVar3 != '\0')))) {
    if (((param_3 == 0) || (param_4 != 0)) && ((param_5 == 0 || (param_7 != (uint *)0x0)))) {
      if ((param_2 == 1) || (param_2 == 2)) {
        iVar1 = lldpQueryTlvs(*(longlong *)(piVar2 + 6),param_2,param_3,param_4,param_5,local_28,
                              param_7);
        if (param_6 != (ulonglong *)0x0) {
          *param_6 = local_28[0];
        }
      }
      else {
        iVar1 = -0x3fffff10;
      }
    }
    else {
      iVar1 = -0x3fffffd0;
    }
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== lldpNmrSetConfig @ 14000f240 =====

void lldpNmrSetConfig(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = lldpOpenPortFromHandle(param_1);
  if (piVar1 != (int *)0x0) {
    lldpSetPortAdminConfig(*(longlong *)(piVar1 + 6),param_2);
  }
  return;
}



===== lldpNmrSetTlvs @ 14000f270 =====

undefined8 lldpNmrSetTlvs(int *param_1,uint *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  uint *puVar3;
  
  puVar3 = param_2;
  piVar1 = lldpOpenPortFromHandle(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000008;
  }
  else {
    uVar2 = lldpVerifyAddressIsNonpaged(*(longlong *)(piVar1 + 4),puVar3);
    if ((char)uVar2 == '\0') {
      uVar2 = 0xc000000d;
    }
    else {
      uVar2 = lldpSetTlvs(*(longlong *)(piVar1 + 6),param_2,'\0');
    }
  }
  return uVar2;
}



===== lldpWriteConfigToRegistry @ 14000f2c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int lldpWriteConfigToRegistry(longlong param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined1 auStack_148 [32];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_118 [2];
  ulonglong local_110;
  undefined1 *local_108;
  undefined1 local_f8 [208];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  local_108 = local_f8;
  local_110 = 0xcc0000;
  local_118[0] = param_3;
  uVar2 = lldpGetRegistryKeyName(param_1,(ushort *)&local_110);
  if ((char)uVar2 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids);
    }
    return -0x3fffffff;
  }
  *(undefined2 *)(local_108 + (local_110 >> 1 & 0x7fff) * 2) = 0;
  iVar1 = RtlCreateRegistryKey(1,local_f8);
  if (iVar1 == 0) {
    local_128 = local_118;
    local_120 = 4;
    iVar1 = RtlWriteRegistryValue(1,local_f8,(&lldpParameterRules)[(longlong)param_2 * 3]);
    if (iVar1 == 0) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0x17;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0x16;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,iVar1);
  return iVar1;
}



===== WppTraceCallback @ 14000f440 =====

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



===== lldpInitializePacketPool @ 14000f6c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 lldpInitializePacketPool(void)

{
  undefined4 uVar1;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = 0;
  local_28 = 0x100180;
  local_1c = 0;
  local_24 = 0x100;
  local_20 = 0x626e4c4c;
  DAT_14000b570 = NdisAllocateNetBufferListPool(DAT_14000b4d0,&local_28);
  if (DAT_14000b570 == 0) {
    uVar1 = 0xc000009a;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids,0xc000009a);
    }
  }
  else {
    DAT_14000b550 = 1;
  }
  return uVar1;
}



===== lldpUnloadDriverCore @ 14000f780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lldpUnloadDriverCore(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (5 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids);
  }
  DAT_14000b578 = 0;
  lVar1 = DAT_14000b580;
  if (DAT_14000b580 != 0) {
    ExFreePoolWithTag(DAT_14000b580,0x50444c4c);
    DAT_14000b580 = 0;
  }
  if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(lVar1,&LldpStopped,param_3);
  }
  McGenEventUnregister_EtwUnregister();
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (5 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids);
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      puVar2 = WPP_GLOBAL_Control;
      if (WPPTraceSuite == 4) {
        for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
          if (*(longlong *)(puVar2 + 0x38) != 0) {
            (*pfnEtwUnregister)();
            *(undefined8 *)(puVar2 + 0x38) = 0;
          }
        }
      }
      else if (WPPTraceSuite == 2) {
        IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
      }
      WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    }
  }
  lldpDriver = 0;
  return;
}



===== lldpBindingDereferenceRxPacketFilter @ 14000f89c =====

void lldpBindingDereferenceRxPacketFilter(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  ExAcquireFastMutex(param_1 + 0x38);
  piVar1 = (int *)(param_1 + 0x70);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (*(char *)(param_1 + 0x74) != '\0') {
      iVar2 = lldpSetMulticastGroup(param_1,'\0');
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x74) = 0;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids,iVar2);
      }
    }
    if (*(char *)(param_1 + 0x75) != '\0') {
      iVar2 = lldpSetPacketFilter(param_1,0);
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0x75) = 0;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids,iVar2);
      }
    }
  }
  ExReleaseFastMutex(param_1 + 0x38);
  return;
}



===== lldpSetMulticastGroup @ 14000f97c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lldpSetMulticastGroup(longlong param_1,char param_2)

{
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_f8;
  undefined4 *local_f0;
  undefined4 local_e8;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  memset(&local_118,0,0xf8);
  local_110 = 0;
  local_114 = 1;
  local_e8 = 6;
  local_f8 = 0x1010209 - (uint)(param_2 != '\0');
  local_f0 = &LLDP_DEST_MAC_NEAREST_BRIDGE;
  lldpSendOidRequestAndWait(param_1,&local_118);
  return;
}



===== lldpSetPacketFilter @ 14000fa18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lldpSetPacketFilter(longlong param_1,undefined4 param_2)

{
  undefined1 auStack_148 [32];
  undefined4 local_128 [4];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_f8;
  undefined4 *local_f0;
  undefined4 local_e8;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_128[0] = param_2;
  memset(&local_118,0,0xf8);
  local_110 = 0;
  local_f0 = local_128;
  local_114 = 1;
  local_f8 = 0x1010e;
  local_e8 = 4;
  lldpSendOidRequestAndWait(param_1,&local_118);
  return;
}



===== lldpAllocateClient @ 14000faa0 =====

undefined4 *
lldpAllocateClient(char param_1,undefined8 param_2,longlong *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 *_Dst;
  
  _Dst = (undefined4 *)ExAllocatePool2(0x40,0x48,0x50444c4c);
  if (_Dst == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_13a8bdc0f49f3ed2b737db04525c483d_Traceguids);
    }
    _Dst = (undefined4 *)0x0;
  }
  else {
    memset(_Dst,0,0x48);
    *_Dst = 0x63444c4c;
    _Dst[4] = 1;
    _Dst[5] = 1;
    *(undefined8 *)(_Dst + 8) = param_2;
    *(undefined8 *)(_Dst + 10) = param_4;
    _Dst[1] = -(uint)(param_1 != '\0') & 4;
    uVar1 = *(undefined4 *)((longlong)param_3 + 4);
    lVar3 = param_3[1];
    uVar2 = *(undefined4 *)((longlong)param_3 + 0xc);
    if (param_1 == '\0') {
      _Dst[0xc] = (int)*param_3;
      _Dst[0xd] = uVar1;
      _Dst[0xe] = (int)lVar3;
      _Dst[0xf] = uVar2;
    }
    else {
      _Dst[0xc] = (int)*param_3;
      _Dst[0xd] = uVar1;
      _Dst[0xe] = (int)lVar3;
      _Dst[0xf] = uVar2;
      *(longlong *)(_Dst + 0x10) = param_3[2];
    }
    if ((*param_3 != 0) && (iVar4 = MmIsDriverVerifyingByAddress(), iVar4 != 0)) {
      _Dst[1] = _Dst[1] | 1;
    }
  }
  return _Dst;
}



===== lldpDeleteOpenPort @ 14000fbac =====

void lldpDeleteOpenPort(undefined1 *param_1)

{
  lldpDereferencePort(*(undefined1 **)(param_1 + 0x18));
  *(undefined8 *)(param_1 + 0x18) = 0;
  lldpDereferenceClient(*(longlong *)(param_1 + 0x10));
  *(undefined8 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  ExFreePoolWithTag(param_1,0x50444c4c);
  return;
}



===== lldpDeliverOneChangeNotification @ 14000fbf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lldpDeliverOneChangeNotification(longlong param_1)

{
  undefined4 uVar1;
  
  LOCK();
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  (**(code **)(*(longlong *)(param_1 + 0x10) + 0x30))
            (param_1,uVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),
             *(undefined8 *)(param_1 + 0x28));
  return;
}



===== lldpOpenPort @ 14000fc24 =====

undefined8 lldpOpenPort(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x30,0x50444c4c);
  if (puVar1 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_044ea0c6c24b336fce62604a60a90133_Traceguids);
    }
    uVar2 = 0;
  }
  else {
    *(undefined8 *)(puVar1 + 1) = 0;
    puVar1[3] = 0;
    *(undefined8 *)(puVar1 + 8) = 0;
    *puVar1 = 0x6f444c4c;
    *(longlong *)(puVar1 + 6) = param_1;
    *(longlong *)(puVar1 + 4) = param_2;
    *(undefined8 *)(puVar1 + 10) = param_3;
    puVar1[8] = 0;
    lldpReferencePort(param_1);
    uVar2 = lldpReferenceClient(param_2);
  }
  return uVar2;
}



===== lldpEvtIoDeviceControl @ 14000fce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void lldpEvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4,
               uint param_5)

{
  longlong lVar1;
  uint *_Dst;
  uint uVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint *local_38;
  longlong *local_30;
  ulonglong local_28 [2];
  
  local_30 = (longlong *)0x0;
  local_38 = (uint *)0x0;
  if ((((param_5 == 0x126018) || (param_5 == 0x126008)) || (param_5 == 0x126010)) ||
     ((param_5 == 0x126014 || (param_5 == 0x12a00c)))) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0,&local_30,0);
    if (-1 < (int)uVar2) {
      if (param_5 != 0x126018) goto LAB_14000ff8c;
      goto LAB_14000fd82;
    }
    goto LAB_14000fe19;
  }
  param_4 = 0;
LAB_14000ff8c:
  if (param_5 < 0x126011) {
    if (((param_5 == 0x126010) || (param_5 == 0x122000)) ||
       ((param_5 == 0x126004 || (param_5 == 0x126008)))) goto LAB_14000fd82;
LAB_14000ffd5:
    param_3 = 0;
  }
  else {
    if ((param_5 != 0x126014) && (param_5 != 0x12a00c)) goto LAB_14000ffd5;
LAB_14000fd82:
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0,&local_38,0);
    if ((int)uVar2 < 0) goto LAB_14000fe19;
  }
  _Dst = local_38;
  if (param_5 == 0x12a00c) {
    if ((0x3f < param_4) && (3 < param_3)) {
      uVar2 = lldpIoctlSetConfig(local_30);
      *local_38 = 0;
      *local_38 = uVar2;
LAB_14000fdf1:
      param_3 = 4;
LAB_14000fdf6:
      uVar2 = 0;
LAB_14000fdf9:
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,param_3);
LAB_14000fe19:
      if (uVar2 == 0x103) {
        return;
      }
      goto LAB_14000fe21;
    }
  }
  else if (param_5 == 0x126010) {
    if ((0x17 < param_4) && (0xb < param_3)) {
      lVar1 = local_30[2];
      local_28[0] = 0;
      puVar3 = (undefined1 *)lldpFindAndReferencePort(local_30);
      if (puVar3 == (undefined1 *)0x0) {
        *_Dst = 0xc0000225;
        goto LAB_14000fdf1;
      }
      memset(_Dst,0,param_3);
      uVar2 = lldpQueryTlvs((longlong)puVar3,(int)lVar1,0,0,param_3 - 8,local_28,_Dst + 2);
      _Dst[1] = (uint)local_28[0];
      *_Dst = uVar2;
      lldpDereferencePort(puVar3);
      goto LAB_14000fdf6;
    }
  }
  else if (param_5 == 0x122000) {
    if (0xf < param_3) {
      lldpIoctlGetVersion((undefined8 *)local_38);
      param_3 = 0x10;
      goto LAB_14000fdf6;
    }
  }
  else if (param_5 == 0x126004) {
    if (0xf < param_3) {
      memset(local_38,0,param_3);
      uVar5 = param_3 - 0x10 >> 4;
      uVar2 = lldpEnumeratePorts((longlong)(_Dst + 4),uVar5,(ulonglong *)(_Dst + 2));
      *_Dst = uVar2;
      if (uVar2 == 0xc0000023) {
        uVar2 = 0;
      }
      else {
        uVar5 = (ulonglong)(uint)*(ulonglong *)(_Dst + 2);
      }
      param_3 = (ulonglong)(((int)uVar5 + 1) * 0x10);
LAB_14000ff71:
      if (-1 < (int)uVar2) goto LAB_14000fdf9;
      goto LAB_14000fe19;
    }
  }
  else {
    if (param_5 != 0x126008) {
      if (param_5 != 0x126014) {
        if (param_5 != 0x126018) {
          uVar2 = 0xc0000010;
          goto LAB_14000fe21;
        }
        if ((param_4 < 0x10) || (param_3 < 0x30)) goto LAB_140010003;
        uVar4 = lldpIoctlQueryStatistics(local_30,(undefined8 *)local_38);
        uVar2 = (uint)uVar4;
        if (uVar2 == 0) {
          param_3 = 0x30;
          goto LAB_14000fdf9;
        }
        goto LAB_14000fe19;
      }
      if ((param_4 < 0x10) || (param_3 < 0x40)) goto LAB_140010003;
      uVar4 = lldpIoctlQueryCurrentStatus(local_30,local_38);
      uVar2 = (uint)uVar4;
      if (uVar2 != 0) goto LAB_14000fe19;
      param_3 = 0x40;
      goto LAB_14000fdf9;
    }
    if ((0xf < param_4) && (0x47 < param_3)) {
      uVar4 = lldpIoctlQueryConfig(local_30,local_38);
      uVar2 = (uint)uVar4;
      param_3 = 0x48;
      goto LAB_14000ff71;
    }
  }
LAB_140010003:
  uVar2 = 0xc0000023;
LAB_14000fe21:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
  return;
}



===== lldpIoctlSetConfig @ 140010080 =====

int lldpIoctlSetConfig(longlong *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined1 *puVar7;
  longlong lVar8;
  char cVar9;
  ulonglong uVar10;
  uint uVar11;
  int iVar12;
  uint7 uVar14;
  undefined *puVar13;
  uint uVar15;
  
  puVar7 = (undefined1 *)lldpFindAndReferencePort(param_1);
  if (puVar7 == (undefined1 *)0x0) {
    return -0x3ffffddb;
  }
  bVar4 = false;
  if (((int)param_1[2] == 1) && (0x2b < (ulonglong)param_1[3])) {
    for (uVar10 = 0; (uint)uVar10 < 7; uVar10 = (ulonglong)((uint)uVar10 + 1)) {
      uVar11 = *(uint *)((ulonglong)(uint)(&DAT_14000b064)[uVar10 * 6] + 0x10 + (longlong)param_1);
      if ((uVar11 != 0xffffffff) &&
         ((uVar11 < (uint)(&DAT_14000b058)[uVar10 * 6] ||
          ((uint)(&DAT_14000b060)[uVar10 * 6] < uVar11)))) {
        iVar12 = -0x3ffffbd5;
        goto LAB_1400100cf;
      }
    }
    iVar12 = 0;
    uVar10 = 0;
    while (uVar11 = (uint)uVar10, uVar11 < 7) {
      uVar15 = *(uint *)((ulonglong)(uint)(&DAT_14000b064)[uVar10 * 6] + 0x10 + (longlong)param_1);
      if (uVar15 != 0xffffffff) {
        iVar12 = 0;
        if (*(char *)((longlong)param_1 + 0x3c) != '\0') {
          bVar4 = true;
        }
        lVar8 = (longlong)(int)uVar11;
        if (*(uint *)(puVar7 + lVar8 * 4 + 0xf8) == uVar15) {
          iVar12 = 0;
        }
        else {
          if ((uVar15 < (uint)(&DAT_14000b058)[lVar8 * 6]) ||
             ((uint)(&DAT_14000b060)[lVar8 * 6] < uVar15)) {
            iVar12 = -0x3ffffbd5;
LAB_1400102af:
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                       &WPP_7c33d10fb468381898e2799524a08bcc_Traceguids,iVar12);
            }
            break;
          }
          if (bVar4) {
            iVar12 = lldpWriteConfigToRegistry((longlong)puVar7,uVar11,uVar15);
            if (iVar12 != 0) {
              if (-1 < iVar12) goto LAB_140010190;
              goto LAB_1400102af;
            }
          }
          *(uint *)(puVar7 + lVar8 * 4 + 0xf8) = uVar15;
        }
      }
LAB_140010190:
      uVar10 = (ulonglong)(uVar11 + 1);
    }
    uVar11 = *(uint *)(puVar7 + 0x108);
    bVar4 = false;
    uVar15 = *(uint *)(puVar7 + 0x124);
    iVar6 = *(int *)(puVar7 + 0xf8);
    puVar13 = (undefined *)(ulonglong)*(uint *)(puVar7 + 0xfc);
    iVar2 = *(int *)(puVar7 + 0x114);
    uVar3 = *(uint *)(puVar7 + 0x11c);
    uVar10 = (ulonglong)uVar3;
    if (uVar11 != uVar15) {
      if (uVar15 < uVar11) {
        *(uint *)(puVar7 + 0x368) = *(int *)(puVar7 + 0x368) + (uVar11 - uVar15);
      }
      else if (uVar11 < uVar15) {
        if (*(int *)(puVar7 + 0x368) <= (int)uVar15) {
          uVar15 = *(uint *)(puVar7 + 0x368);
        }
        *(uint *)(puVar7 + 0x368) = uVar15;
      }
    }
    if ((((*(uint *)(puVar7 + 0x100) != uVar3) ||
         (*(int *)(puVar7 + 0x10c) != *(int *)(puVar7 + 0x128))) &&
        (bVar4 = true, *(uint *)(puVar7 + 0x100) != uVar3)) ||
       (*(uint *)(puVar7 + 0xfc) != *(uint *)(puVar7 + 0x118))) {
      lldpUpdateTxTtl((longlong)puVar7);
    }
    if (iVar6 != iVar2) {
      uVar14 = (uint7)((ulonglong)puVar13 >> 8);
      if ((iVar6 == 0) || ((iVar6 != 1 && ((iVar6 == 2 || (iVar6 != 3)))))) {
        puVar13 = (undefined *)((ulonglong)uVar14 << 8);
      }
      else {
        puVar13 = (undefined *)CONCAT71(uVar14,1);
      }
      uVar14 = (uint7)(uVar10 >> 8);
      if ((iVar2 == 0) || ((iVar2 != 1 && ((iVar2 == 2 || (iVar2 != 3)))))) {
        uVar10 = (ulonglong)uVar14 << 8;
      }
      else {
        uVar10 = CONCAT71(uVar14,1);
      }
      if (((iVar6 == 0) || (iVar6 == 1)) || ((iVar6 != 2 && (iVar6 != 3)))) {
        cVar9 = '\0';
      }
      else {
        cVar9 = '\x01';
      }
      if (((iVar2 == 0) || (iVar2 == 1)) || ((iVar2 != 2 && (iVar2 != 3)))) {
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      if ((char)puVar13 != (char)uVar10) {
        bVar4 = true;
      }
      if (cVar9 != cVar5) {
        lldpAdjustRxPacketFilters((longlong)puVar7);
      }
    }
    if (bVar4) {
      lldpEnableTxFastMode((longlong)puVar7,uVar10,puVar13);
    }
    iVar6 = memcmp(puVar7 + 0xf8,puVar7 + 0x114,0x1c);
    if (iVar6 != 0) {
      *(undefined8 *)(puVar7 + 0x114) = *(undefined8 *)(puVar7 + 0xf8);
      *(undefined8 *)(puVar7 + 0x11c) = *(undefined8 *)(puVar7 + 0x100);
      *(undefined8 *)(puVar7 + 0x124) = *(undefined8 *)(puVar7 + 0x108);
      *(undefined4 *)(puVar7 + 300) = *(undefined4 *)(puVar7 + 0x110);
      lldpQueueChangeNotificationEx((longlong)puVar7,0,4);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_7c33d10fb468381898e2799524a08bcc_Traceguids);
    }
    iVar12 = -0x3fffffa8;
  }
LAB_1400100cf:
  LOCK();
  piVar1 = (int *)(puVar7 + 0x30);
  iVar6 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar6 == 1) {
    lldpDeletePort(puVar7);
  }
  return iVar12;
}



===== lldpDereferencePort @ 140010440 =====

void lldpDereferencePort(undefined1 *param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x30);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    lldpDeletePort(param_1);
  }
  return;
}



===== lldpProtBindAdapter @ 140010470 =====

int lldpProtBindAdapter(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 local_res18 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined *local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_44 = 0;
  local_2c = 0;
  local_14 = 0;
  local_res18[0] = 0;
  if (*(ushort *)(param_3 + 0x68) == 6) {
    uVar5 = *(uint *)(param_3 + 0x8c);
    if (((uVar5 == 0) || (uVar5 == 0x13)) || (uVar5 == 0xe)) {
      puVar3 = lldpAllocateBinding(param_3);
      if (puVar3 == (undefined4 *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        for (lVar1 = *(longlong *)(puVar3 + 0x1e); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28))
        {
          LOCK();
          iVar2 = *(int *)(lVar1 + 0x34);
          *(int *)(lVar1 + 0x34) = 2;
          UNLOCK();
          if (((iVar2 == 5) || (iVar2 == 3)) || ((iVar2 == 4 || (iVar2 == 6)))) {
            lldpQueueChangeNotificationEx(lVar1,0,0x80000000);
          }
        }
        local_40 = *(undefined8 *)(param_3 + 0x10);
        local_38 = &DAT_14000923c;
        local_20 = &DAT_140009238;
        local_28 = local_res18;
        local_48 = 0x340187;
        local_30 = 1;
        local_18 = 1;
        iVar2 = NdisOpenAdapterEx(DAT_14000b4d0,puVar3,&local_48,param_2,puVar3 + 2);
        if (iVar2 != 0x103) {
          lldpProtOpenAdapterComplete((undefined1 *)puVar3,iVar2);
        }
      }
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff45;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3fffff45;
    }
    uVar4 = 0xc;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff45;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3fffff45;
    }
    uVar5 = (uint)*(ushort *)(param_3 + 0x68);
    uVar4 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_acd65dca497b3543092d0321cbce568c_Traceguids,uVar5);
  return -0x3fffff45;
}



===== lldpAllocateBinding @ 140010640 =====

undefined4 * lldpAllocateBinding(longlong param_1)

{
  undefined4 uVar1;
  undefined4 *_Dst;
  undefined4 *puVar2;
  int iVar3;
  
  _Dst = (undefined4 *)ExAllocatePool2(0x40,0x80,0x50444c4c);
  if (_Dst == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  memset(_Dst,0,0x80);
  *_Dst = 0x62444c4c;
  iVar3 = 1;
  _Dst[0xe] = 1;
  *(undefined8 *)(_Dst + 0x10) = 0;
  _Dst[0x12] = 0;
  KeInitializeEvent(_Dst + 0x14,1,0);
  uVar1 = *(undefined4 *)(param_1 + 0xd0);
  _Dst[9] = *(undefined4 *)(param_1 + 0xd4);
  _Dst[10] = uVar1;
  _Dst[0xb] = *(int *)(param_1 + 0x24) + 0xe;
  _Dst[0xc] = *(undefined4 *)(param_1 + 0x24);
  while( true ) {
    if (3 < iVar3) {
      lldpAddBindingToDriver((longlong)_Dst);
      return _Dst;
    }
    puVar2 = lldpAllocPort((longlong)_Dst,*(ushort **)(param_1 + 0x10),
                           *(undefined4 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xa8),iVar3);
    if (puVar2 == (undefined4 *)0x0) break;
    puVar2[1] = 0;
    lldpSetPortMacAddress((longlong)puVar2,(undefined4 *)(param_1 + 0x6a));
    iVar3 = iVar3 + 1;
    *(undefined8 *)(puVar2 + 10) = *(undefined8 *)(_Dst + 0x1e);
    *(undefined4 **)(_Dst + 0x1e) = puVar2;
  }
  lldpDetachAllPortsFromBinding((longlong)_Dst);
  lldpCleanupBinding((undefined1 *)_Dst);
  return (undefined4 *)0x0;
}



===== lldpAllocPort @ 140010780 =====

undefined4 *
lldpAllocPort(longlong param_1,ushort *param_2,undefined4 param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *_Dst;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  void *_Dst_00;
  ulonglong uVar7;
  uint uVar8;
  
  uVar8 = (uint)*param_2;
  uVar2 = uVar8;
  if (1 < *param_2) {
    do {
      if (*(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar2 >> 1) * 2) == 0x5c) break;
      uVar2 = uVar2 - 2;
    } while (1 < uVar2);
  }
  uVar8 = uVar8 - uVar2;
  lVar5 = *(longlong *)(param_2 + 4);
  _Dst = (undefined4 *)
         ExAllocatePool2(0x40,uVar8 + (*(int *)(param_1 + 0x2c) + 0x1f5) * 2 +
                              *(int *)(param_1 + 0x30),0x50444c4c);
  if (_Dst == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids);
    }
    return (undefined4 *)0x0;
  }
  memset(_Dst,0,1000);
  *_Dst = 0x70444c4c;
  *(longlong *)(_Dst + 6) = param_1;
  _Dst[0xc] = 1;
  KeInitializeTimer(_Dst + 0x4e);
  KeInitializeDpc(_Dst + 0x5e,lldpRxInfoTtlTimer,_Dst);
  *(undefined8 *)(_Dst + 0x6e) = 0;
  KeInitializeTimer(_Dst + 0x70);
  KeInitializeDpc(_Dst + 0x80,lldpTooManyNeighborsTimer,_Dst);
  *(undefined8 *)(_Dst + 0x90) = 0;
  KeInitializeTimer(_Dst + 0x92);
  KeInitializeDpc(_Dst + 0xa2,lldpTxTtr,_Dst);
  *(undefined8 *)(_Dst + 0xb2) = 0;
  KeInitializeTimer(_Dst + 0xb4);
  KeInitializeDpc(_Dst + 0xc4,_guard_check_icall,_Dst);
  *(undefined8 *)(_Dst + 0xd4) = 0;
  LOCK();
  iVar1 = _Dst[0xd];
  _Dst[0xd] = 1;
  UNLOCK();
  if ((((iVar1 == 5) || (iVar1 == 3)) || (iVar1 == 4)) || (iVar1 == 6)) {
    lldpQueueChangeNotificationEx((longlong)_Dst,0,0x80000000);
  }
  *(undefined8 *)(_Dst + 0x1e) = param_4;
  _Dst[0x21] = param_5;
  _Dst[0x4c] = 0x13;
  _Dst[0x20] = param_3;
  _Dst[0x22] = *(undefined4 *)(param_1 + 0x2c);
  _Dst[0x23] = *(undefined4 *)(param_1 + 0x30);
  _Dst[0xf8] = *(undefined4 *)(param_1 + 0x30);
  _Dst[0xf6] = 0;
  lVar6 = (ulonglong)*(uint *)(param_1 + 0x30) + 1000 + (longlong)_Dst;
  *(longlong *)(_Dst + 0x2c) = lVar6;
  lVar6 = (ulonglong)*(uint *)(param_1 + 0x2c) + lVar6;
  *(longlong *)(_Dst + 0x34) = lVar6;
  _Dst_00 = (void *)((ulonglong)*(uint *)(param_1 + 0x2c) + lVar6);
  *(void **)(_Dst + 0x1c) = _Dst_00;
  memmove(_Dst_00,(void *)(lVar5 + (ulonglong)(uVar2 >> 1) * 2),(ulonglong)uVar8);
  *(undefined2 *)(*(longlong *)(_Dst + 0x1c) + (ulonglong)(uVar8 >> 1) * 2) = 0;
  _Dst[2] = 0;
  *(undefined8 *)(_Dst + 4) = 0;
  _Dst[0xe] = 0;
  *(undefined8 *)(_Dst + 0x10) = 0;
  KeInitializeSpinLock(_Dst + 0x12);
  uVar2 = IoSizeofWorkItem();
  uVar7 = (ulonglong)uVar2;
  uVar3 = ExAllocatePool2(0x40,uVar7,0x50444c4c);
  *(ulonglong *)(_Dst + 0x1a) = uVar3;
  if (uVar3 == 0) {
    uVar3 = uVar7;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140010b82;
    uVar3 = 0xb;
  }
  else {
    IoInitializeWorkItem(DAT_14000b4c8);
    uVar4 = NdisAllocateRWLock(DAT_14000b4d0);
    *(undefined8 *)(_Dst + 0xf0) = uVar4;
    lVar5 = NdisAllocateRWLock(DAT_14000b4d0);
    *(longlong *)(_Dst + 0xf4) = lVar5;
    if ((*(longlong *)(_Dst + 0xf0) != 0) && (lVar5 != 0)) {
      KeQuerySystemTimePrecise(_Dst + 0x3c);
      uVar3 = (ulonglong)*(uint *)(param_1 + 0x2c);
      uVar4 = lldpPreparePacket(_Dst + 0x26,*(uint *)(param_1 + 0x2c),param_5);
      if ((int)uVar4 == 0) {
        *(undefined4 **)(*(longlong *)(_Dst + 0x28) + 0x40) = _Dst;
        uVar3 = (ulonglong)*(uint *)(param_1 + 0x2c);
        uVar4 = lldpPreparePacket(_Dst + 0x2e,*(uint *)(param_1 + 0x2c),param_5);
        if ((int)uVar4 == 0) {
          *(undefined4 **)(*(longlong *)(_Dst + 0x30) + 0x40) = _Dst;
          lldpInitializePortConfiguration((longlong)_Dst);
          lldpAddPortToDriver((longlong)_Dst);
          return _Dst;
        }
      }
      goto LAB_140010b82;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140010b82;
    uVar3 = 0xc;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar3,
          &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids);
LAB_140010b82:
  lldpDetachPortFromBinding((longlong)_Dst);
  lldpTransition((longlong)_Dst,uVar3,7);
  _Dst[0xc] = 0;
  lldpDeletePort((undefined1 *)_Dst);
  return (undefined4 *)0x0;
}



===== lldpDetachPortFromBinding @ 140010bd0 =====

void lldpDetachPortFromBinding(longlong param_1)

{
  void *pvVar1;
  bool bVar2;
  longlong local_res8 [2];
  
  if (*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10) != 0) {
    lldpDeliverSpecialUnbindNotifications(param_1);
  }
  pvVar1 = SystemReserved1[0xf];
  local_res8[0] = -10000;
  while( true ) {
    LOCK();
    bVar2 = *(longlong *)(param_1 + 0x10) == 0;
    if (bVar2) {
      *(longlong *)(param_1 + 0x10) = (longlong)pvVar1;
    }
    UNLOCK();
    if (bVar2) break;
    KeDelayExecutionThread(0,0,local_res8);
    if (-10000000 < local_res8[0]) {
      local_res8[0] = local_res8[0] * 2;
    }
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  lldpReleaseInterLock((uint *)(param_1 + 8));
  lldpCleanupPacket(param_1 + 0xb8);
  lldpCleanupPacket(param_1 + 0x98);
  return;
}



===== lldpCleanupPacket @ 140010c80 =====

void lldpCleanupPacket(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    NdisFreeNetBufferList();
    *(undefined8 *)(param_1 + 8) = 0;
    lldpDereferencePacketPool();
  }
  if (*(longlong *)(param_1 + 0x10) != 0) {
    NdisFreeMdl();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  return;
}



===== lldpDereferencePacketPool @ 140010cd8 =====

void lldpDereferencePacketPool(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = DAT_14000b550 + -1;
  UNLOCK();
  bVar2 = DAT_14000b550 == 1;
  DAT_14000b550 = iVar1;
  if ((bVar2) && (DAT_14000b570 != 0)) {
    NdisFreeNetBufferListPool();
    DAT_14000b570 = 0;
  }
  return;
}



===== lldpDeletePort @ 140010d18 =====

void lldpDeletePort(undefined1 *param_1)

{
  int iVar1;
  char cVar2;
  
  if (param_1[0x96] != '\0') {
    lldpRemovePortFromDriver((longlong)param_1);
    param_1[0x96] = 0;
  }
  lldpCancelTimer();
  lldpCancelTimer();
  lldpCancelTimer();
  lldpCancelTimer();
  KeFlushQueuedDpcs();
  LOCK();
  iVar1 = *(int *)(param_1 + 0x34);
  *(int *)(param_1 + 0x34) = 8;
  UNLOCK();
  cVar2 = lldpPortStateIsVisibleToClients(iVar1);
  if (cVar2 != '\0') {
    lldpQueueChangeNotificationEx((longlong)param_1,0,0x80000000);
  }
  if (*(longlong *)(param_1 + 0x3c8) != 0) {
    lldpDeleteNeighborOnPort((longlong)param_1);
    *(undefined8 *)(param_1 + 0x3c8) = 0;
  }
  if (*(longlong *)(param_1 + 0x3d0) != 0) {
    NdisFreeRWLock();
    *(undefined8 *)(param_1 + 0x3d0) = 0;
  }
  if (*(longlong *)(param_1 + 0x3c0) != 0) {
    NdisFreeRWLock();
    *(undefined8 *)(param_1 + 0x3c0) = 0;
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0x50444c4c);
  }
  if (*(longlong *)(param_1 + 0x3b8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x3b8),0x50444c4c);
    *(undefined8 *)(param_1 + 0x3b8) = 0;
    *(undefined4 *)(param_1 + 0x3b0) = 0;
  }
  *param_1 = 0;
  ExFreePoolWithTag(param_1,0x50444c4c);
  return;
}



===== lldpTransition @ 140010e60 =====

void lldpTransition(longlong param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  LOCK();
  iVar1 = *(int *)(param_1 + 0x34);
  *(int *)(param_1 + 0x34) = param_3;
  UNLOCK();
  if (((((iVar1 == 5) || (iVar1 == 3)) || (iVar1 == 4)) || (iVar1 == 6)) &&
     (((param_3 != 5 && (param_3 != 3)) && ((param_3 != 4 && (param_3 != 6)))))) {
    lldpQueueChangeNotificationEx(param_1,0,0x80000000);
  }
  return;
}



===== lldpProtUnbindAdapter @ 140010ec0 =====

undefined8 lldpProtUnbindAdapter(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  
  *(undefined8 *)(param_2 + 0x10) = param_1;
  lldpDetachAllPortsFromBinding((longlong)param_2);
  iVar1 = NdisCloseAdapterEx(*(undefined8 *)(param_2 + 8));
  if (iVar1 != 0x103) {
    *(undefined8 *)(param_2 + 8) = 0;
    lldpCleanupBinding(param_2);
  }
  return 0x103;
}



===== lldpDetachAllPortsFromBinding @ 140010f10 =====

void lldpDetachAllPortsFromBinding(longlong param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined1 *puVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  bool bVar7;
  longlong local_res8;
  
  puVar6 = *(undefined1 **)(param_1 + 0x78);
  if (puVar6 != (undefined1 *)0x0) {
    do {
      puVar4 = puVar6;
      plVar5 = (longlong *)(param_1 + 0x78);
      do {
        if (puVar4 == puVar6) {
          *plVar5 = *(longlong *)(puVar6 + 0x28);
          break;
        }
        plVar5 = (longlong *)(puVar4 + 0x28);
        puVar4 = *(undefined1 **)(puVar4 + 0x20);
      } while (puVar4 != (undefined1 *)0x0);
      if (*(longlong *)(*(longlong *)(puVar6 + 0x18) + 0x10) != 0) {
        lldpDeliverSpecialUnbindNotifications((longlong)puVar6);
      }
      pvVar3 = SystemReserved1[0xf];
      local_res8 = -10000;
      LOCK();
      bVar7 = *(longlong *)(puVar6 + 0x10) == 0;
      if (bVar7) {
        *(void **)(puVar6 + 0x10) = SystemReserved1[0xf];
      }
      UNLOCK();
      while (!bVar7) {
        KeDelayExecutionThread(0,0,&local_res8);
        if (-10000000 < local_res8) {
          local_res8 = local_res8 * 2;
        }
        LOCK();
        bVar7 = *(longlong *)(puVar6 + 0x10) == 0;
        if (bVar7) {
          *(void **)(puVar6 + 0x10) = pvVar3;
        }
        UNLOCK();
      }
      *(undefined8 *)(puVar6 + 0x18) = 0;
      lldpReleaseInterLock((uint *)(puVar6 + 8));
      if (*(longlong *)(puVar6 + 0xc0) != 0) {
        NdisFreeNetBufferList();
        *(undefined8 *)(puVar6 + 0xc0) = 0;
        LOCK();
        iVar2 = DAT_14000b550 + -1;
        UNLOCK();
        bVar7 = DAT_14000b550 == 1;
        DAT_14000b550 = iVar2;
        if ((bVar7) && (DAT_14000b570 != 0)) {
          NdisFreeNetBufferListPool();
          DAT_14000b570 = 0;
        }
      }
      if (*(longlong *)(puVar6 + 200) != 0) {
        NdisFreeMdl();
        *(undefined8 *)(puVar6 + 200) = 0;
      }
      if (*(longlong *)(puVar6 + 0xa0) != 0) {
        NdisFreeNetBufferList();
        *(undefined8 *)(puVar6 + 0xa0) = 0;
        LOCK();
        iVar2 = DAT_14000b550 + -1;
        UNLOCK();
        bVar7 = DAT_14000b550 == 1;
        DAT_14000b550 = iVar2;
        if ((bVar7) && (DAT_14000b570 != 0)) {
          NdisFreeNetBufferListPool();
          DAT_14000b570 = 0;
        }
      }
      if (*(longlong *)(puVar6 + 0xa8) != 0) {
        NdisFreeMdl();
        *(undefined8 *)(puVar6 + 0xa8) = 0;
      }
      LOCK();
      iVar2 = *(int *)(puVar6 + 0x34);
      *(int *)(puVar6 + 0x34) = 7;
      UNLOCK();
      if ((((iVar2 == 3) || (iVar2 == 4)) || (iVar2 == 5)) || (iVar2 == 6)) {
        lldpQueueChangeNotificationEx((longlong)puVar6,0,0x80000000);
      }
      if (puVar6[0x96] != '\0') {
        lldpRemovePortFromDriver((longlong)puVar6);
        puVar6[0x96] = 0;
      }
      LOCK();
      piVar1 = (int *)(puVar6 + 0x30);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        lldpDeletePort(puVar6);
      }
      puVar6 = *(undefined1 **)(param_1 + 0x78);
    } while (puVar6 != (undefined1 *)0x0);
  }
  return;
}



===== lldpProtCloseAdapterComplete @ 140011140 =====

void lldpProtCloseAdapterComplete(undefined1 *param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  lldpCleanupBinding(param_1);
  return;
}



===== lldpCleanupBinding @ 14001115c =====

void lldpCleanupBinding(undefined1 *param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    NdisCompleteUnbindAdapterEx();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (param_1[0x20] != '\0') {
    lldpRemoveBindingFromDriver((longlong)param_1);
    param_1[0x20] = 0;
  }
  *param_1 = 0;
  ExFreePoolWithTag(param_1,0x50444c4c);
  return;
}



===== lldpInitializePortConfiguration @ 1400111c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lldpInitializePortConfiguration(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined **ppuVar6;
  uint *puVar7;
  undefined8 *puVar8;
  undefined1 auStackY_1d8 [32];
  uint local_1a8 [2];
  ulonglong local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_178;
  undefined4 local_170;
  undefined *local_168;
  uint *local_160;
  undefined4 local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 local_108 [208];
  ulonglong local_38;
  
  uVar1 = DAT_14000b05c;
  local_38 = __security_cookie ^ (ulonglong)auStackY_1d8;
  puVar7 = (uint *)(param_1 + 0xf8);
  *puVar7 = DAT_14000b05c;
  ppuVar6 = &lldpParameterRules;
  *(uint *)(param_1 + 0x114) = uVar1;
  uVar2 = DAT_14000b074;
  *(undefined4 *)(param_1 + 0xfc) = DAT_14000b074;
  *(undefined4 *)(param_1 + 0x118) = uVar2;
  uVar2 = DAT_14000b08c;
  *(undefined4 *)(param_1 + 0x100) = DAT_14000b08c;
  *(undefined4 *)(param_1 + 0x11c) = uVar2;
  uVar2 = DAT_14000b0a4;
  *(undefined4 *)(param_1 + 0x104) = DAT_14000b0a4;
  *(undefined4 *)(param_1 + 0x120) = uVar2;
  uVar2 = DAT_14000b0bc;
  *(undefined4 *)(param_1 + 0x108) = DAT_14000b0bc;
  *(undefined4 *)(param_1 + 0x124) = uVar2;
  uVar2 = DAT_14000b0d4;
  *(undefined4 *)(param_1 + 0x10c) = DAT_14000b0d4;
  *(undefined4 *)(param_1 + 0x128) = uVar2;
  uVar2 = DAT_14000b0ec;
  *(undefined4 *)(param_1 + 0x110) = DAT_14000b0ec;
  *(undefined4 *)(param_1 + 300) = uVar2;
  do {
    local_198 = local_108;
    local_168 = *ppuVar6;
    local_160 = local_1a8;
    local_1a8[0] = 0;
    local_1a0 = 0xcc0000;
    local_178 = 0;
    local_170 = 0xb4;
    local_158 = 0;
    local_150 = 0;
    local_148 = 0;
    local_140 = 0;
    local_138 = 0;
    uStack_130 = 0;
    local_128 = 0;
    uStack_120 = 0;
    local_118 = 0;
    uStack_110 = 0;
    uVar4 = RtlUnicodeStringPrintf
                      ((ushort *)&local_1a0,L"Mslldp\\Parameters\\Agents\\%s-%u",
                       *(undefined8 *)(param_1 + 0x70),(ulonglong)*(uint *)(param_1 + 0x84));
    if ((int)uVar4 == 0) {
      local_190 = 0;
      uStack_188 = 0;
      *(undefined2 *)(local_198 + (local_1a0 >> 1 & 0x7fff) * 2) = 0;
      RtlInitUnicodeString(&local_190,L"RtlQueryRegistryValuesEx");
      pcVar5 = (code *)MmGetSystemRoutineAddress(&local_190);
      puVar8 = &local_178;
      if (pcVar5 == (code *)0x0) {
        pcVar5 = RtlQueryRegistryValues_exref;
      }
      iVar3 = (*pcVar5)(1,local_108);
      if (iVar3 == 0) {
        uVar1 = *(uint *)(ppuVar6 + 2);
        if (uVar1 < local_1a8[0]) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_SDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar1,puVar8,
                       (wchar_t *)*ppuVar6,(char)local_1a8[0],(char)uVar1);
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar1,puVar8,
                      (wchar_t *)*ppuVar6,(char)local_1a8[0]);
          }
          *puVar7 = local_1a8[0];
        }
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,(int)uVar4);
    }
    puVar7 = puVar7 + 1;
    ppuVar6 = ppuVar6 + 3;
  } while ((longlong)ppuVar6 < 0x14000b0f8);
  return;
}



===== lldpSetPortAdminConfig @ 140011460 =====

int lldpSetPortAdminConfig(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  longlong lVar8;
  char cVar9;
  ulonglong uVar10;
  uint uVar11;
  int unaff_ESI;
  uint7 uVar13;
  undefined *puVar12;
  uint uVar14;
  
  bVar4 = false;
  if ((*param_2 != 1) || (*(ulonglong *)(param_2 + 2) < 0x2c)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_ESI;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return unaff_ESI;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_7c33d10fb468381898e2799524a08bcc_Traceguids);
    return unaff_ESI;
  }
  for (uVar10 = 0; (uint)uVar10 < 7; uVar10 = (ulonglong)((uint)uVar10 + 1)) {
    uVar11 = *(uint *)((ulonglong)(uint)(&DAT_14000b064)[uVar10 * 6] + (longlong)param_2);
    if (uVar11 != 0xffffffff) {
      if (uVar11 < (uint)(&DAT_14000b058)[uVar10 * 6]) {
        return unaff_ESI;
      }
      if ((uint)(&DAT_14000b060)[uVar10 * 6] < uVar11) {
        return unaff_ESI;
      }
    }
  }
  uVar10 = 0;
  while (uVar11 = (uint)uVar10, uVar11 < 7) {
    uVar14 = *(uint *)((ulonglong)(uint)(&DAT_14000b064)[uVar10 * 6] + (longlong)param_2);
    if (uVar14 != 0xffffffff) {
      if ((char)param_2[0xb] != '\0') {
        bVar4 = true;
      }
      lVar8 = (longlong)(int)uVar11;
      lVar1 = param_1 + lVar8 * 4;
      if (*(uint *)(lVar1 + 0xf8) != uVar14) {
        if ((uVar14 < (uint)(&DAT_14000b058)[lVar8 * 6]) ||
           ((uint)(&DAT_14000b060)[lVar8 * 6] < uVar14)) {
          iVar7 = -0x3ffffbd5;
LAB_14001164e:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                     &WPP_7c33d10fb468381898e2799524a08bcc_Traceguids,iVar7);
          }
          break;
        }
        if (bVar4) {
          iVar7 = lldpWriteConfigToRegistry(param_1,uVar11,uVar14);
          if (iVar7 != 0) {
            if (-1 < iVar7) goto LAB_14001153c;
            goto LAB_14001164e;
          }
        }
        *(uint *)(lVar1 + 0xf8) = uVar14;
      }
    }
LAB_14001153c:
    uVar10 = (ulonglong)(uVar11 + 1);
  }
  uVar11 = *(uint *)(param_1 + 0x108);
  bVar5 = false;
  bVar4 = false;
  uVar14 = *(uint *)(param_1 + 0x124);
  iVar7 = *(int *)(param_1 + 0xf8);
  puVar12 = (undefined *)(ulonglong)*(uint *)(param_1 + 0xfc);
  iVar2 = *(int *)(param_1 + 0x114);
  uVar3 = *(uint *)(param_1 + 0x11c);
  uVar10 = (ulonglong)uVar3;
  if (uVar11 != uVar14) {
    if (uVar14 < uVar11) {
      *(uint *)(param_1 + 0x368) = *(int *)(param_1 + 0x368) + (uVar11 - uVar14);
    }
    else if (uVar11 < uVar14) {
      if (*(int *)(param_1 + 0x368) <= (int)uVar14) {
        uVar14 = *(uint *)(param_1 + 0x368);
      }
      *(uint *)(param_1 + 0x368) = uVar14;
    }
  }
  if ((*(uint *)(param_1 + 0x100) == uVar3) &&
     (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0x128))) {
LAB_14001159e:
    if (*(uint *)(param_1 + 0xfc) == *(uint *)(param_1 + 0x118)) goto LAB_1400115a3;
  }
  else {
    bVar5 = true;
    bVar4 = true;
    if (*(uint *)(param_1 + 0x100) == uVar3) goto LAB_14001159e;
  }
  lldpUpdateTxTtl(param_1);
LAB_1400115a3:
  if (iVar7 != iVar2) {
    uVar13 = (uint7)((ulonglong)puVar12 >> 8);
    if ((iVar7 == 0) || ((iVar7 != 1 && ((iVar7 == 2 || (iVar7 != 3)))))) {
      puVar12 = (undefined *)((ulonglong)uVar13 << 8);
    }
    else {
      puVar12 = (undefined *)CONCAT71(uVar13,1);
    }
    uVar13 = (uint7)(uVar10 >> 8);
    if ((iVar2 == 0) || ((iVar2 != 1 && ((iVar2 == 2 || (iVar2 != 3)))))) {
      uVar10 = (ulonglong)uVar13 << 8;
    }
    else {
      uVar10 = CONCAT71(uVar13,1);
    }
    if (((iVar7 == 0) || (iVar7 == 1)) || ((iVar7 != 2 && (iVar7 != 3)))) {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    if (((iVar2 == 0) || (iVar2 == 1)) || ((iVar2 != 2 && (iVar2 != 3)))) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    bVar4 = bVar5;
    if ((char)puVar12 != (char)uVar10) {
      bVar4 = true;
    }
    if (cVar9 != cVar6) {
      lldpAdjustRxPacketFilters(param_1);
    }
  }
  if (bVar4) {
    lldpEnableTxFastMode(param_1,uVar10,puVar12);
  }
  iVar7 = memcmp((void *)(param_1 + 0xf8),(void *)(param_1 + 0x114),0x1c);
  if (iVar7 != 0) {
    *(undefined8 *)(param_1 + 0x114) = *(undefined8 *)(param_1 + 0xf8);
    *(undefined8 *)(param_1 + 0x11c) = *(undefined8 *)(param_1 + 0x100);
    *(undefined8 *)(param_1 + 0x124) = *(undefined8 *)(param_1 + 0x108);
    *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x110);
    lldpQueueChangeNotificationEx(param_1,0,4);
  }
  return unaff_ESI;
}



===== lldpProtNetPnPEvent @ 1400117e0 =====

ulonglong lldpProtNetPnPEvent(longlong param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  
  iVar1 = *(int *)(param_2 + 8);
  uVar4 = 0;
  piVar2 = *(int **)(param_2 + 0x10);
  if (iVar1 == 6) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return 0;
    }
    uVar5 = 0x16;
  }
  else {
    if (iVar1 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
      }
      if (*piVar2 == 1) {
        lldpEnableAllPortsOnBinding(param_1,(undefined *)0x4,param_3);
        return 0;
      }
      lldpDisableAllPortsOnBinding(param_1,(undefined *)0x4);
      return 0;
    }
    if (iVar1 == 1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return 0;
      }
      uVar5 = 0x11;
    }
    else {
      switch(iVar1) {
      case 2:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x12;
        break;
      case 3:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x13;
        break;
      case 4:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x14;
        break;
      case 5:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x15;
        break;
      default:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_acd65dca497b3543092d0321cbce568c_Traceguids,iVar1);
        return 0;
      case 7:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x17;
        break;
      case 8:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                  &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
        }
        for (lVar3 = *(longlong *)(param_1 + 0x78); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x28))
        {
          LOCK();
          *(undefined4 *)(lVar3 + 0x34) = 6;
          UNLOCK();
          lldpDisablePort(lVar3,1);
          KeFlushQueuedDpcs();
          lldpWaitForTxCompletion(lVar3);
          LOCK();
          *(undefined4 *)(lVar3 + 0x34) = 3;
          UNLOCK();
        }
        return 0;
      case 9:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                  &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
        }
        uVar4 = lldpProtRestartBinding(param_1,(longlong)piVar2,param_3);
        uVar4 = uVar4 & 0xffffffff;
      case 10:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar4;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return uVar4;
        }
        uVar5 = 0x1a;
        break;
      case 0xb:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x1b;
        break;
      case 0xc:
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0x1c;
      }
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
          &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
  return uVar4;
}



===== lldpProtRestartBinding @ 140011b60 =====

undefined8 lldpProtRestartBinding(longlong param_1,longlong param_2,undefined *param_3)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    for (puVar2 = *(undefined8 **)(param_2 + 0x18); puVar2 != (undefined8 *)0x0;
        puVar2 = (undefined8 *)*puVar2) {
      if (*(int *)(puVar2 + 1) == 0x1021d) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
          WPP_SF_(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_acd65dca497b3543092d0321cbce568c_Traceguids);
        }
        uVar1 = *(undefined4 *)(puVar2 + 10);
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((longlong)puVar2 + 0x54);
        *(undefined4 *)(param_1 + 0x28) = uVar1;
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        param_3 = &WPP_acd65dca497b3543092d0321cbce568c_Traceguids;
        WPP_SF_D(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_acd65dca497b3543092d0321cbce568c_Traceguids,*(int *)(puVar2 + 1));
      }
    }
  }
  for (lVar3 = *(longlong *)(param_1 + 0x78); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x28)) {
    LOCK();
    *(undefined4 *)(lVar3 + 0x34) = 4;
    UNLOCK();
    lldpEnablePort(lVar3,1,param_3);
    LOCK();
    *(undefined4 *)(lVar3 + 0x34) = 5;
    UNLOCK();
  }
  return 0;
}



===== lldpWaitForTxCompletion @ 140011c50 =====

void lldpWaitForTxCompletion(longlong param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,
              (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
              (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
  }
  lldpWaitForValueToZero((int *)(param_1 + 0x98));
  lldpWaitForValueToZero((int *)(param_1 + 0xb8));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_546502ed7e6b3bd4e6d6388a8a9b5935_Traceguids,
              (uint)(ushort)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x30),
              (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
  }
  return;
}



===== lldpWaitForValueToZero @ 140011d10 =====

void lldpWaitForValueToZero(int *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  longlong local_res10 [3];
  
  local_res10[0] = -10000;
  iVar2 = *param_1;
  do {
    LOCK();
    iVar1 = *param_1;
    bVar3 = iVar2 == iVar1;
    if (bVar3) {
      *param_1 = iVar2;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  while (iVar2 != 0) {
    KeDelayExecutionThread(0,0,local_res10);
    if (-10000000 < local_res10[0]) {
      local_res10[0] = local_res10[0] * 2;
    }
    iVar2 = *param_1;
    do {
      LOCK();
      iVar1 = *param_1;
      bVar3 = iVar2 == iVar1;
      if (bVar3) {
        *param_1 = iVar2;
      }
      else {
        iVar2 = iVar1;
      }
      UNLOCK();
    } while (!bVar3);
  }
  return;
}



===== lldpActivatePort @ 140011d88 =====

void lldpActivatePort(longlong param_1)

{
  *(undefined8 *)(*(longlong *)(param_1 + 0xa0) + 0x78) =
       *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  *(undefined8 *)(*(longlong *)(param_1 + 0xc0) + 0x78) =
       *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  lldpInitializeLocalMib(param_1);
  lldpFlushConfigChanges(param_1,'\x01');
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_0ffa195ed41632c397cfac9730cd0bab_Traceguids,(uint)*(ushort *)(param_1 + 0x7e),
              (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x34) = 3;
  UNLOCK();
  lldpDeliverCreateNotifications(*(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x84));
  return;
}



===== lldpInitializeLocalMib @ 140011e30 =====

void lldpInitializeLocalMib(longlong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  void *_Src;
  ulonglong uVar7;
  ulonglong _Size;
  
  _Src = DAT_14000b580;
  uVar6 = DAT_14000b578;
  lVar4 = *(longlong *)(param_1 + 0xb0);
  _Size = (ulonglong)DAT_14000b578;
  *(undefined4 *)(param_1 + 0x3dc) = 0;
  uVar7 = (ulonglong)(uVar6 + 0x69);
  *(undefined4 *)(lVar4 + 0xe) = 3;
  *(undefined1 *)(lVar4 + 0x76) = 7;
  memmove((void *)(lVar4 + 0x77),_Src,_Size);
  *(undefined4 *)(lVar4 + 0x22) = 0;
  *(undefined2 *)(lVar4 + 0x12) = 1;
  *(undefined4 *)(lVar4 + 0x1e) = 0x68;
  *(short *)(lVar4 + 0x1a) = (short)uVar6 + 1;
  *(undefined1 *)(uVar7 + 0xe + lVar4) = 3;
  *(undefined4 *)(uVar7 + 0xf + lVar4) = *(undefined4 *)(param_1 + 0x90);
  *(undefined2 *)(uVar7 + 0x13 + lVar4) = *(undefined2 *)(param_1 + 0x94);
  *(undefined4 *)(lVar4 + 0x36) = 0;
  *(undefined2 *)(lVar4 + 0x26) = 2;
  *(undefined2 *)(lVar4 + 0x2e) = 7;
  *(uint *)(lVar4 + 0x32) = uVar6 + 0x69;
  *(undefined2 *)((ulonglong)(uVar6 + 0x70) + 0xe + lVar4) = 0;
  *(undefined4 *)(lVar4 + 0x4a) = 0;
  *(undefined2 *)(lVar4 + 0x42) = 2;
  *(undefined2 *)(lVar4 + 0x3a) = 3;
  *(uint *)(lVar4 + 0x46) = uVar6 + 0x70;
  lldpSetTlvs(param_1,(uint *)(lVar4 + 0xe),'\x01');
  iVar1 = *(int *)(param_1 + 0x88);
  iVar2 = *(int *)(param_1 + 0x8c);
  iVar3 = *(int *)(param_1 + 0x3dc);
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0xc0) + 8);
  lldpCopyMibToNetBuffer(param_1,param_1 + 0xb8);
  *(int *)(lVar5 + 0x18) = (iVar1 - iVar2) + iVar3;
  lldpAddMedTlvs(param_1,(uint *)(lVar4 + 0xe),(ulonglong)(uVar6 + 0x72));
  lldpUpdateTxTtl(param_1);
  return;
}



===== lldpUpdateTxTtl @ 140011f78 =====

void lldpUpdateTxTtl(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = lldpGetConfig(param_1,1);
  uVar3 = (ulonglong)uVar1;
  uVar1 = lldpGetConfig(param_1,2);
  if (((0xffffffff < uVar1 * uVar3) ||
      (uVar1 = (uint)(uVar1 * uVar3), uVar2 = uVar1 + 1, uVar2 < uVar1)) || (0xffff < uVar2)) {
    uVar2 = 0xffff;
  }
  lldpSetMibTtl(param_1,(ushort)uVar2);
  return;
}



===== lldpFlushConfigChanges @ 140011fd0 =====

void lldpFlushConfigChanges(longlong param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  char cVar9;
  ulonglong uVar10;
  uint7 uVar12;
  undefined *puVar11;
  uint uVar13;
  
  uVar1 = *(uint *)(param_1 + 0x108);
  iVar8 = *(int *)(param_1 + 0xf8);
  bVar5 = false;
  bVar4 = false;
  uVar13 = *(uint *)(param_1 + 0x124);
  puVar11 = (undefined *)(ulonglong)*(uint *)(param_1 + 0xfc);
  iVar2 = *(int *)(param_1 + 0x114);
  uVar3 = *(uint *)(param_1 + 0x11c);
  uVar10 = (ulonglong)uVar3;
  bVar6 = false;
  if (uVar1 != uVar13) {
    if (uVar13 < uVar1) {
      *(uint *)(param_1 + 0x368) = *(int *)(param_1 + 0x368) + (uVar1 - uVar13);
    }
    else if (uVar1 < uVar13) {
      if (*(int *)(param_1 + 0x368) <= (int)uVar13) {
        uVar13 = *(uint *)(param_1 + 0x368);
      }
      *(uint *)(param_1 + 0x368) = uVar13;
    }
  }
  if ((*(uint *)(param_1 + 0x100) == uVar3) &&
     (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0x128))) {
LAB_140012046:
    if (*(uint *)(param_1 + 0xfc) == *(uint *)(param_1 + 0x118)) goto LAB_14001204b;
  }
  else {
    bVar5 = true;
    bVar4 = true;
    if (*(uint *)(param_1 + 0x100) == uVar3) goto LAB_140012046;
  }
  lldpUpdateTxTtl(param_1);
LAB_14001204b:
  if (iVar8 != iVar2) {
    uVar12 = (uint7)((ulonglong)puVar11 >> 8);
    if ((iVar8 == 0) || ((iVar8 != 1 && ((iVar8 == 2 || (iVar8 != 3)))))) {
      puVar11 = (undefined *)((ulonglong)uVar12 << 8);
    }
    else {
      puVar11 = (undefined *)CONCAT71(uVar12,1);
    }
    uVar12 = (uint7)(uVar10 >> 8);
    if ((iVar2 == 0) || ((iVar2 != 1 && ((iVar2 == 2 || (iVar2 != 3)))))) {
      uVar10 = (ulonglong)uVar12 << 8;
    }
    else {
      uVar10 = CONCAT71(uVar12,1);
    }
    if (((iVar8 == 0) || (iVar8 == 1)) || ((iVar8 != 2 && (iVar8 != 3)))) {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    if (((iVar2 == 0) || (iVar2 == 1)) || ((iVar2 != 2 && (iVar2 != 3)))) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    bVar4 = bVar5;
    if ((char)puVar11 != (char)uVar10) {
      bVar4 = true;
    }
    if (cVar9 != cVar7) {
      lldpAdjustRxPacketFilters(param_1);
      bVar6 = true;
    }
  }
  if ((param_2 != '\0') && (!bVar6)) {
    lldpAdjustRxPacketFilters(param_1);
  }
  if (bVar4) {
    lldpEnableTxFastMode(param_1,uVar10,puVar11);
  }
  iVar8 = memcmp((void *)(param_1 + 0xf8),(void *)(param_1 + 0x114),0x1c);
  if (iVar8 != 0) {
    *(undefined8 *)(param_1 + 0x114) = *(undefined8 *)(param_1 + 0xf8);
    *(undefined8 *)(param_1 + 0x11c) = *(undefined8 *)(param_1 + 0x100);
    *(undefined8 *)(param_1 + 0x124) = *(undefined8 *)(param_1 + 0x108);
    *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x110);
    if (param_2 == '\0') {
      lldpQueueChangeNotificationEx(param_1,0,4);
    }
  }
  return;
}



===== lldpAdjustRxPacketFilters @ 1400121e8 =====

void lldpAdjustRxPacketFilters(longlong param_1)

{
  void *pvVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  longlong local_res10 [2];
  
  lVar3 = param_1;
  iVar2 = lldpGetConfig(param_1,0);
  if (((iVar2 == 0) || (iVar2 == 1)) || ((iVar2 != 2 && (iVar2 != 3)))) {
    LOCK();
    iVar2 = *(int *)(lVar3 + 0x358);
    *(int *)(lVar3 + 0x358) = 0;
    UNLOCK();
    if (iVar2 == 0) {
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids,(uint)*(ushort *)(param_1 + 0x7e),
                (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
    }
    lldpAcquireInterLock((int *)(param_1 + 8),'\0');
    if (*(longlong *)(param_1 + 0x18) != 0) {
      lldpBindingDereferenceRxPacketFilter(*(longlong *)(param_1 + 0x18));
    }
  }
  else {
    LOCK();
    iVar2 = *(int *)(lVar3 + 0x358);
    *(int *)(lVar3 + 0x358) = 1;
    UNLOCK();
    if (iVar2 != 0) {
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                &WPP_dc65fd90403c30e5e64868c1e34e4ed6_Traceguids,(uint)*(ushort *)(param_1 + 0x7e),
                (char)((ulonglong)*(undefined8 *)(param_1 + 0x78) >> 0x18));
    }
    pvVar1 = SystemReserved1[0xf];
    local_res10[0] = -10000;
    while( true ) {
      LOCK();
      bVar4 = *(longlong *)(param_1 + 0x10) == 0;
      if (bVar4) {
        *(longlong *)(param_1 + 0x10) = (longlong)pvVar1;
      }
      UNLOCK();
      if (bVar4) break;
      KeDelayExecutionThread(0,0,local_res10);
      if (-10000000 < local_res10[0]) {
        local_res10[0] = local_res10[0] * 2;
      }
    }
    if (*(longlong *)(param_1 + 0x18) != 0) {
      lldpBindingReferenceRxPacketFilter(*(longlong *)(param_1 + 0x18));
    }
  }
  lldpReleaseInterLock((uint *)(param_1 + 8));
  return;
}



===== lldpValidateTlvArray @ 140012360 =====

ulonglong lldpValidateTlvArray(uint *param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined **ppuVar4;
  undefined2 uVar5;
  uint uVar6;
  
  ppuVar4 = (undefined **)0x0;
  while( true ) {
    if (*param_1 <= (uint)ppuVar4) {
      return CONCAT71((int7)((ulonglong)ppuVar4 >> 8),1);
    }
    uVar1 = (ushort)param_1[(longlong)ppuVar4 * 5 + 1];
    uVar6 = (uint)uVar1;
    if ((((uVar1 != 3) && (uVar6 != 0)) && (uVar1 != 1)) && (uVar1 != 2)) break;
    if (param_2 == '\0') {
      ppuVar4 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140012555;
      uVar5 = 10;
      goto LAB_140012545;
    }
    if (uVar1 == 0) goto LAB_140012555;
LAB_140012469:
    if (param_1[(longlong)ppuVar4 * 5 + 5] != 0) {
      ppuVar4 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140012555;
      uVar5 = 0xe;
LAB_140012512:
      ppuVar4 = (undefined **)
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                        &WPP_8124ac20fb98338ccde253d27c7846b0_Traceguids);
      goto LAB_140012555;
    }
    lVar3 = (longlong)ppuVar4 * 5;
    uVar6 = param_1[(longlong)ppuVar4 * 5 + 4];
    if (uVar6 + (ushort)param_1[lVar3 + 3] < uVar6) {
      ppuVar4 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        ppuVar4 = (undefined **)
                  WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                            &WPP_8124ac20fb98338ccde253d27c7846b0_Traceguids,uVar6,
                            (char)param_1[lVar3 + 3]);
      }
      goto LAB_140012555;
    }
    ppuVar4 = (undefined **)(ulonglong)((uint)ppuVar4 + 1);
  }
  uVar2 = (ushort)param_1[(longlong)ppuVar4 * 5 + 3];
  uVar6 = (uint)uVar2;
  if (uVar1 == 0x7f) {
    if (0xfe02 < (ushort)(uVar2 - 0x1fc)) goto LAB_140012469;
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140012555;
    uVar5 = 0xb;
  }
  else {
    if (0xfdfe < (ushort)(uVar2 - 0x200)) {
      if (param_1[(longlong)ppuVar4 * 5 + 2] == 0) goto LAB_140012469;
      ppuVar4 = &WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140012555;
      uVar5 = 0xd;
      goto LAB_140012512;
    }
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140012555;
    uVar5 = 0xc;
  }
LAB_140012545:
  ppuVar4 = (undefined **)
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                     &WPP_8124ac20fb98338ccde253d27c7846b0_Traceguids,uVar6);
LAB_140012555:
  return (ulonglong)ppuVar4 & 0xffffffffffffff00;
}



===== lldpSendOidRequestAndWait @ 140012580 =====

int lldpSendOidRequestAndWait(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids,param_2[8]);
  }
  param_2[0x36] = 0x726f4c4c;
  puVar4 = (undefined *)0x0;
  *(undefined8 **)(param_2 + 0x38) = &local_28;
  param_2[0x37] = 0x103;
  KeInitializeEvent(&local_28,0);
  *param_2 = 0xec0196;
  param_2[3] = 5;
  *(longlong *)(param_2 + 4) = param_1;
  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 8);
  puVar3 = param_2;
  iVar1 = NdisOidRequest(*(undefined8 *)(param_1 + 8));
  if (iVar1 == 0x103) {
    puVar4 = (undefined *)0x0;
    puVar3 = (undefined4 *)0x0;
    iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
    if (iVar2 == 0) {
      iVar1 = param_2[0x37];
    }
    else {
      iVar1 = -0x3fffffff;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
        puVar4 = &WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids;
        puVar3 = (undefined4 *)0xb;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_b25973d62a3f3a7743895fe6376516fa_Traceguids,iVar2);
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar3,puVar4,param_2[8],(char)iVar1);
  }
  return iVar1;
}



===== lldpGetRegistryKeyName @ 1400126e0 =====

ulonglong lldpGetRegistryKeyName(longlong param_1,ushort *param_2)

{
  ulonglong uVar1;
  
  uVar1 = RtlUnicodeStringPrintf
                    (param_2,L"Mslldp\\Parameters\\Agents\\%s-%u",*(undefined8 *)(param_1 + 0x70),
                     (ulonglong)*(uint *)(param_1 + 0x84));
  if ((int)uVar1 == 0) {
    uVar1 = CONCAT71((int7)(uVar1 >> 8),1);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar1 = WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                       &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,(int)uVar1);
    }
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== lldpAcquireInterLock @ 140012748 =====

void lldpAcquireInterLock(int *param_1,char param_2)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  longlong local_res8;
  
  pvVar2 = SystemReserved1[0xf];
  local_res8 = -10000;
  while( true ) {
    pvVar3 = (void *)0x0;
    LOCK();
    pvVar1 = *(void **)(param_1 + 2);
    if (pvVar1 == (void *)0x0) {
      *(void **)(param_1 + 2) = pvVar2;
    }
    else {
      pvVar3 = pvVar1;
    }
    UNLOCK();
    if (pvVar1 == (void *)0x0) break;
    if ((param_2 != '\0') && (pvVar3 == pvVar2)) {
      *param_1 = *param_1 + 1;
      return;
    }
    KeDelayExecutionThread(0,0,&local_res8);
    if (-10000000 < local_res8) {
      local_res8 = local_res8 * 2;
    }
  }
  return;
}



===== lldpProtOpenAdapterComplete @ 1400127d0 =====

void lldpProtOpenAdapterComplete(undefined1 *param_1,int param_2)

{
  longlong lVar1;
  
  if (param_2 == 0) {
    for (lVar1 = *(longlong *)(param_1 + 0x78); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28)) {
      lldpActivatePort(lVar1);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_acd65dca497b3543092d0321cbce568c_Traceguids,param_2);
    }
    *(undefined8 *)(param_1 + 8) = 0;
    lldpDetachAllPortsFromBinding((longlong)param_1);
    lldpCleanupBinding(param_1);
  }
  return;
}



===== lldpBindingReferenceRxPacketFilter @ 14001284c =====

void lldpBindingReferenceRxPacketFilter(longlong param_1)

{
  int iVar1;
  
  ExAcquireFastMutex(param_1 + 0x38);
  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
  if (*(int *)(param_1 + 0x70) == 1) {
    iVar1 = lldpSetMulticastGroup(param_1,'\x01');
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0x74) = 1;
      iVar1 = lldpSetPacketFilter(param_1,2);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x75) = 1;
      }
    }
  }
  ExReleaseFastMutex(param_1 + 0x38);
  return;
}



===== lldpInitializeDriverCore @ 140013008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lldpInitializeDriverCore(undefined8 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar3 = (undefined *)0xc8;
  memset(&lldpDriver,0,200);
  _lldpDriver = 0x64444c4c;
  DAT_14000b488 = &WPP_ThisDir_CTLGUID_MSDCN;
  _WPP_MAIN_CB = 0;
  DAT_14000b490 = 0;
  _DAT_14000b4a0 = 0;
  _DAT_14000b4a8 = 1;
  DAT_14000b4c8 = param_1;
  WppLoadTracingSupport();
  _DAT_14000b4a0 = 0;
  WppInitKm();
  puVar2 = WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (5 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar3 = &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids;
    WPP_SF_(puVar2,0xc,&WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids);
  }
  McGenEventRegister_EtwRegister();
  if ((Microsoft_Windows_LinkLayerDiscoveryProtocolEnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer(puVar2,&LldpStarted,puVar3);
  }
  KeInitializeSpinLock(&DAT_14000b4e0);
  KeInitializeSpinLock(&DAT_14000b4f8);
  KeInitializeSpinLock(&DAT_14000b518);
  KeInitializeSpinLock(&DAT_14000b558);
  lldpInitializeInterLock(&DAT_14000b530);
  lldpInitializeInterLock(&DAT_14000b540);
  iVar1 = lldpLoadChassisId();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((iVar1 < 0 || (5 < (byte)WPP_GLOBAL_Control[0x29])))) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_ebdbdfea9df53e15e98b8def7894f066_Traceguids,iVar1);
  }
  return iVar1;
}



===== lldpLoadChassisId @ 140013178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int lldpLoadChassisId(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_f8;
  undefined8 uStack_f0;
  code *local_e8;
  undefined4 local_e0;
  wchar_t *local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_e8 = lldpReadComputerName;
  local_78 = lldpReadComputerName;
  local_e0 = 0x14;
  local_d8 = L"ChassisId";
  local_70 = 0x14;
  local_68 = L"ComputerName";
  local_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_58 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  RtlInitUnicodeString(&local_f8,L"RtlQueryRegistryValuesEx");
  pcVar3 = (code *)MmGetSystemRoutineAddress(&local_f8);
  if (pcVar3 == (code *)0x0) {
    pcVar3 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar3)(1,L"Mslldp\\Parameters",&local_e8,0,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    local_f8 = 0;
    uStack_f0 = 0;
    RtlInitUnicodeString(&local_f8,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_f8);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(2,L"ComputerName\\ComputerName",&local_78,0,0);
    if (((iVar2 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,iVar2);
    }
  }
  return iVar2;
}



===== __security_init_cookie @ 140013314 =====

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



===== DriverEntry @ 140013348 =====

int DriverEntry(undefined8 param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = param_2;
  wil_InitializeFeatureStaging();
  iVar1 = lldpInitializeDriverCore(param_1);
  if ((-1 < iVar1) && (iVar1 = lldpCreateDriverWdf(param_1,param_2), uVar2 = param_2, -1 < iVar1)) {
    iVar1 = lldpRegisterProtocol();
    if (iVar1 == 0) {
      iVar1 = lldpNmrRegisterProvider();
      uVar2 = param_2;
      if (iVar1 < 0) goto LAB_1400133a2;
      iVar1 = lldpInitializeControlDevice();
    }
    uVar2 = param_2;
    if (-1 < iVar1) {
      return iVar1;
    }
  }
LAB_1400133a2:
  if (lldpWdfDriver == 0) {
    wil_UninitializeFeatureStaging();
  }
  else {
    lldpDriverUnloadWdf(lldpWdfDriver,uVar2,param_3);
  }
  return iVar1;
}



===== lldpCreateDriverWdf @ 1400133d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int lldpCreateDriverWdf(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_64 = 0;
  local_60 = 0;
  local_50 = 1;
  local_38 = 0;
  local_58 = lldpDriverUnloadWdf;
  local_18 = 0;
  uStack_40 = 0;
  local_68 = 0x20;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0x38;
  uStack_30 = 0x100000002;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_48,&local_68,&lldpWdfDriver);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ea1b45b0a6943981c34a08d8d3c26e2c_Traceguids,iVar1);
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1400134c4 =====

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
    plVar3 = (longlong *)&wil_details_featureDescriptors_a;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400135b4 =====

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
  plVar3 = (longlong *)&wil_details_featureDescriptors_a;
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



===== lldpRegisterProtocol @ 14001369c =====

int lldpRegisterProtocol(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  wchar_t *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  local_80 = 2;
  local_70 = L"MsLldp";
  local_78 = 0xe000c;
  local_68 = lldpProtSetOptions;
  local_60 = lldpProtBindAdapter;
  local_58 = lldpProtUnbindAdapter;
  local_50 = lldpProtOpenAdapterComplete;
  local_48 = lldpProtCloseAdapterComplete;
  local_40 = lldpProtNetPnPEvent;
  local_30 = lldpProtOidRequestComplete;
  local_28 = lldpProtStatus;
  local_20 = lldpProtReceiveNetBufferLists;
  local_18 = lldpProtSendNetBufferListsComplete;
  local_88 = 0x800295;
  local_84 = 0xa5906;
  local_38 = 0;
  local_10 = 0;
  iVar1 = NdisRegisterProtocolDriver(&lldpDriver,&local_88,&DAT_14000b4d0);
  iVar2 = 0;
  if (((iVar1 != 0) && (iVar2 = iVar1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_acd65dca497b3543092d0321cbce568c_Traceguids,iVar1);
  }
  return iVar2;
}



===== lldpNmrRegisterProvider @ 1400137c0 =====

int lldpNmrRegisterProvider(void)

{
  int iVar1;
  
  iVar1 = NmrRegisterProvider(&DAT_140009070,&lldpDriver,&DAT_14000b4d8);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_7b2e41ea31413e6a6d3bdbc4c714aeb2_Traceguids,iVar1);
  }
  return iVar1;
}



===== lldpReadComputerName @ 140013840 =====

undefined8 lldpReadComputerName(undefined8 param_1,int param_2,char *param_3,uint param_4)

{
  int iVar1;
  undefined2 uVar2;
  uint *puVar3;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  if (1 < param_2 - 1U) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,param_2);
    }
    return 0xc0000122;
  }
  for (; 1 < param_4; param_4 = param_4 - 2) {
    if (*(short *)(param_3 + (((ulonglong)param_4 & 0xfffffffffffffffe) - 2)) != 0)
    goto LAB_1400138e3;
  }
  if (param_4 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000122;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000122;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids);
    return 0xc0000122;
  }
LAB_1400138e3:
  puVar3 = local_res10;
  iVar1 = RtlUnicodeToUTF8N(0,0,puVar3,param_3,param_4);
  if (iVar1 == 0) {
    if (0xff < local_res10[0]) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0;
      }
      WPP_SF_sDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_res10[0],puVar3,param_3
                 ,(char)local_res10[0]);
      return 0;
    }
    if (local_res10[0] == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0;
      }
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0,puVar3,param_3);
      return 0;
    }
    DAT_14000b578 = local_res10[0];
    DAT_14000b580 = ExAllocatePool2(0x40,(ulonglong)local_res10[0],0x50444c4c);
    if (DAT_14000b580 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids);
      return 0;
    }
    iVar1 = RtlUnicodeToUTF8N(DAT_14000b580,DAT_14000b578,local_res10,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140013a64;
    uVar2 = 0x10;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140013a64;
    uVar2 = 0xc;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_b3a834d394783de5fb279a081dc3c281_Traceguids,iVar1);
LAB_140013a64:
  DAT_14000b578 = 0;
  if (DAT_14000b580 != 0) {
    ExFreePoolWithTag(DAT_14000b580,0x50444c4c);
    DAT_14000b580 = 0;
  }
  return 0;
}


