
===== ProcessRxPacket @ 140001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessRxPacket(int *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined *puVar10;
  longlong *plVar11;
  int *piVar12;
  undefined1 *puVar13;
  int iVar14;
  longlong lVar15;
  char *pcVar16;
  bool bVar17;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar13 = auStack_58;
  iVar14 = 0;
  puVar8 = (undefined8 *)0x0;
  local_28 = 0;
  bVar6 = false;
  local_38 = 0;
  uStack_30 = 0;
  piVar12 = param_1;
  if ((char)param_1[0x50] != '\0') {
    puVar10 = &DAT_140012440;
    puVar8 = (undefined8 *)ExAllocateFromNPagedLookasideList();
    if (puVar8 == (undefined8 *)0x0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar16 = "Receive Packets will be dropped as Dgram allocation failed";
LAB_1400011c0:
        McTemplateK0s_EtwWriteTransfer(puVar10,&RasAgileVpnTraceError,&DAT_14000feb8,pcVar16);
      }
    }
    else {
      *(uint *)(puVar8 + 3) = *(uint *)(puVar8 + 3) | 2;
      puVar8[2] = param_2;
      puVar8[4] = param_1;
      *(undefined1 *)(puVar8 + 5) = 0;
      LOCK();
      *param_1 = *param_1 + 1;
      UNLOCK();
      LOCK();
      DAT_140012248 = DAT_140012248 + 1;
      UNLOCK();
      puVar10 = (undefined *)(ulonglong)(uint)param_1[0x5c];
      bVar17 = true;
      bVar6 = true;
      if (param_1[0x5c] == 0xffffffff) {
        puVar10 = (undefined *)(*(ulonglong *)(param_1 + 0x2a) % (ulonglong)DAT_1400165c0);
        param_1[0x5c] = (int)puVar10;
      }
      uVar1 = *(uint *)(param_2 + 0x1a);
      if ((param_1[0x5d] < 0x30d41) && (param_1[0x5f] < 0x2ab99)) {
        LOCK();
        param_1[0x5d] = param_1[0x5d] + 1;
        UNLOCK();
        LOCK();
        param_1[0x5f] = param_1[0x5f] + 1;
        UNLOCK();
        lVar15 = (ulonglong)(uVar1 + ((int)puVar10 - uVar1 / 3) * 3) * 0x40;
        KeAcquireInStackQueuedSpinLock(DAT_1400165c8 + 0x38 + lVar15,&local_38);
        plVar11 = (longlong *)(DAT_1400165c8 + 8 + lVar15);
        puVar2 = (undefined8 *)plVar11[1];
        plVar3 = (longlong *)*plVar11;
        if ((longlong *)*puVar2 == plVar11) {
          *puVar8 = plVar11;
          puVar8[1] = puVar2;
          *puVar2 = puVar8;
          plVar11[1] = (longlong)puVar8;
          if (plVar3 == plVar11) {
            NdisSetEvent(DAT_1400165c8 + 0x20 + lVar15);
          }
          KeReleaseInStackQueuedSpinLock(&local_38);
          puVar13 = auStack_58;
          goto LAB_140001161;
        }
        piVar12 = (int *)0x3;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar13 = auStack_50;
        bVar6 = bVar17;
        goto LAB_140001228;
      }
      bVar6 = bVar17;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar16 = "Dropping Receive packet as queue is full";
        goto LAB_1400011c0;
      }
    }
    puVar13 = auStack_58;
    iVar14 = -0x3fffff66;
    goto LAB_140001161;
  }
LAB_140001228:
  LOCK();
  *piVar12 = *piVar12 + 1;
  UNLOCK();
  LOCK();
  DAT_140012248 = DAT_140012248 + 1;
  UNLOCK();
  *(undefined8 *)(puVar13 + -8) = 0x140001239;
  uVar9 = AgileVpnCheckAdapterTunnelStates((longlong)piVar12,'\0');
  if ((int)uVar9 == 0) {
    *(undefined8 *)(puVar13 + -8) = 0x140001260;
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
    piVar12 = param_1 + 0xe;
    *(undefined1 *)(param_1 + 0x10) = uVar7;
    if ((param_1[0x35] & 0x20U) == 0) {
      param_1[4] = param_1[4] + 1;
      param_2[0xc] = param_1;
      iVar14 = param_1[0x10];
      *(undefined8 *)(puVar13 + -8) = 0x140001289;
      KeReleaseSpinLock(piVar12,(char)iVar14);
      uVar9 = *(undefined8 *)(param_1 + 0x12);
      *(undefined8 *)(puVar13 + -8) = 0x1400012a3;
      NdisMCoIndicateReceiveNetBufferLists(uVar9,param_2,1);
      LOCK();
      _agileVpnUlPackReceived = _agileVpnUlPackReceived + 1;
      UNLOCK();
      iVar14 = 0;
      goto LAB_140001161;
    }
    *(undefined8 *)(puVar13 + -8) = 0x1400012be;
    KeReleaseSpinLock(piVar12,uVar7);
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      pcVar16 = "Dropping Receive packet due to invalid tunnel State";
      goto LAB_1400012d3;
    }
  }
  else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    pcVar16 = "Dropping Receive packet due to invalid Adapter/Tunnel State";
LAB_1400012d3:
    *(undefined8 *)(puVar13 + -8) = 0x1400012e6;
    McTemplateK0s_EtwWriteTransfer(piVar12,&RasAgileVpnTraceError,&DAT_14000feb8,pcVar16);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1400012f1;
  AgileVpnCompleteNblsPreRecv(param_1,param_2);
  iVar14 = 0;
LAB_140001161:
  LOCK();
  iVar5 = DAT_140012248 + -1;
  UNLOCK();
  bVar17 = DAT_140012248 == 1;
  DAT_140012248 = iVar5;
  if (bVar17) {
    *(undefined8 *)(puVar13 + -8) = 0x1400011e8;
    (*DAT_140012250)(&DAT_140012248);
  }
  LOCK();
  iVar5 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    pcVar4 = *(code **)(param_1 + 2);
    *(undefined8 *)(puVar13 + -8) = 0x1400011f6;
    (*pcVar4)(param_1);
  }
  if (iVar14 < 0) {
    while (param_2 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*param_2;
      *param_2 = 0;
      *(undefined8 *)(puVar13 + -8) = 0x140001313;
      NetioDereferenceNetBufferList(param_2,0);
      param_2 = puVar2;
    }
    LOCK();
    _agileVpnUlPackReceivedError = _agileVpnUlPackReceivedError + 1;
    UNLOCK();
    if (puVar8 != (undefined8 *)0x0) {
      *(undefined8 *)(puVar13 + -8) = 0x14000133a;
      ExFreeToNPagedLookasideList(&DAT_140012440,puVar8);
    }
    if (bVar6) {
      *(undefined8 *)(puVar13 + -8) = 0x140001350;
      DereferenceRefCount(param_1);
      *(undefined8 *)(puVar13 + -8) = 0x14000135c;
      DereferenceRefCount(&DAT_140012248);
    }
  }
  return;
}



===== AgileVpnCheckAdapterTunnelStates @ 140001370 =====

undefined8 AgileVpnCheckAdapterTunnelStates(longlong param_1,char param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  if ((DAT_140014514 & 1) != 0) {
    KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
    return 0xc023002a;
  }
  if (param_2 != '\0') {
    LOCK();
    DAT_140012248 = DAT_140012248 + 1;
    UNLOCK();
  }
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
  *(undefined1 *)(param_1 + 0x40) = uVar1;
  if ((*(uint *)(param_1 + 0xd4) & 0x20) == 0) {
    KeReleaseSpinLock();
    uVar2 = 0;
  }
  else {
    KeReleaseSpinLock(param_1 + 0x38,uVar1);
    if (param_2 != '\0') {
      DereferenceRefCount(&DAT_140012248);
    }
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== DereferenceRefCount @ 140001470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DereferenceRefCount(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(param_1 + 2))();
  }
  return;
}



===== ApplyQoSAndTransmitPacket @ 1400014a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ApplyQoSAndTransmitPacket(longlong param_1,int *param_2)

{
  int iVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 *local_res20;
  undefined8 *local_28 [2];
  
  local_res20 = (undefined8 *)0x0;
  iVar4 = 0;
  local_28[0] = (undefined8 *)0x0;
  lVar6 = param_1;
  puVar5 = (undefined8 *)NdisAllocateCloneNetBufferList(param_1,DAT_140016810,DAT_140016818,0);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (lVar6,&RasAgileVpnTraceError,&DAT_14000feb8,"NdisAllocateCloneNetBufferList failed"
                );
    }
LAB_140001593:
    NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_2 + 0x12),param_1,0);
    LOCK();
    _agileVpnUlPackSentError = _agileVpnUlPackSentError + 1;
    UNLOCK();
  }
  else {
    if ((char)param_2[0x2c] != '\0') {
      WfpNblInfoClone(param_1,puVar5,0,0,1);
    }
    puVar5[0x1a] = (ulonglong)*(uint *)(param_1 + 0xd0);
    puVar5[3] = param_1;
    piVar3 = *(int **)(param_2 + 0x4c);
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar1 = *piVar3;
      if (iVar1 == 1) {
        *piVar3 = 1;
      }
      UNLOCK();
      if ((iVar1 == 1) && (*(longlong *)(*(longlong *)(param_2 + 0x4c) + 0x10) != 0)) {
        uVar8 = 0;
        puVar7 = puVar5;
        iVar4 = NdisAllocateNetBufferListContext(puVar5,0x10,0,0x63715641);
        if (iVar4 != 0) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0sx_EtwWriteTransfer
                      (puVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                       "ApplyQoSAndTransmitPacket: NdisAllocateNetBufferListContext for QoS context failed"
                       ,(char)iVar4);
          }
          if (-1 < iVar4) {
            return iVar4;
          }
          NdisFreeCloneNetBufferList(puVar5,0);
          goto LAB_140001593;
        }
        LOCK();
        *param_2 = *param_2 + 1;
        UNLOCK();
        LOCK();
        DAT_140012248 = DAT_140012248 + 1;
        UNLOCK();
        lVar6 = puVar5[2];
        uVar2 = *(ushort *)(lVar6 + 10);
        *(int **)((ulonglong)uVar2 + 0x10 + lVar6) = param_2;
        *(undefined1 *)((ulonglong)uVar2 + 0x18 + lVar6) = 1;
        BwcSendNbls(*(uint **)(*(longlong *)(param_2 + 0x4c) + 0x10),puVar5,uVar8,
                    (longlong *)&local_res20,local_28);
        if ((local_28[0] != (undefined8 *)0x0) &&
           (piVar3 = *(int **)(param_2 + 0x4c), piVar3 != (int *)0x0)) {
          LOCK();
          iVar1 = *piVar3;
          if (iVar1 == 1) {
            *piVar3 = 1;
          }
          UNLOCK();
          if ((iVar1 == 1) && (*(longlong *)(*(longlong *)(param_2 + 0x4c) + 0x10) != 0)) {
            DropNonConformantNbls(*(longlong *)(*(longlong *)(param_2 + 0x4c) + 0x10),local_28[0]);
            RasAgileVpnTraceNBL(local_28[0],1);
          }
        }
        puVar5 = local_res20;
      }
    }
    if (puVar5 != (undefined8 *)0x0) {
      while( true ) {
        puVar7 = (undefined8 *)*puVar5;
        *puVar5 = 0;
        piVar3 = *(int **)(param_2 + 0x4c);
        local_res20 = puVar7;
        if (piVar3 != (int *)0x0) {
          LOCK();
          iVar1 = *piVar3;
          if (iVar1 == 1) {
            *piVar3 = 1;
          }
          UNLOCK();
          if ((iVar1 == 1) && (*(longlong *)(*(longlong *)(param_2 + 0x4c) + 0x10) != 0)) {
            NdisFreeNetBufferListContext(puVar5,0x10);
            DereferenceRefCount(param_2);
            DereferenceRefCount(&DAT_140012248);
          }
        }
        LOCK();
        *param_2 = *param_2 + 1;
        UNLOCK();
        LOCK();
        DAT_140012248 = DAT_140012248 + 1;
        UNLOCK();
        TransmitPacket((longlong)puVar5,param_2);
        if (puVar7 == (undefined8 *)0x0) break;
        puVar5 = local_res20;
      }
    }
  }
  return iVar4;
}



===== AgileVpnMpCoRequest @ 140001750 =====

int AgileVpnMpCoRequest(longlong param_1,uint *param_2,longlong param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = SetInformation(param_3 + 0x34,param_2,*(int *)(param_3 + 0x20),
                             *(uint **)(param_3 + 0x28),*(uint *)(param_3 + 0x30),
                             (undefined4 *)(param_3 + 0x34),(undefined4 *)(param_3 + 0x38));
      return iVar1;
    }
    if (iVar1 != 2) {
      return -0x3fffff45;
    }
  }
  iVar1 = QueryInformation(param_1,(longlong)param_2,*(uint *)(param_3 + 0x20),
                           *(void **)(param_3 + 0x28),*(uint *)(param_3 + 0x30),
                           (uint *)(param_3 + 0x34),(uint *)(param_3 + 0x38));
  return iVar1;
}



===== QueryInformation @ 1400017e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
QueryInformation(longlong param_1,longlong param_2,uint param_3,void *param_4,uint param_5,
                uint *param_6,uint *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 *_Src;
  undefined1 auStack_78 [32];
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  _Src = (undefined8 *)local_58;
  local_50 = 0;
  local_48 = 0;
  uVar2 = 0;
  local_58[0] = 0;
  uVar1 = 4;
  if (param_3 == 0x4010285) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,
                 "QInfo(OID_IP_WAN_MINIPORT_DRIVER_STATS)");
    }
    if (param_2 == 0) {
      return 0xc0010015;
    }
    _Src = (undefined8 *)(param_2 + 0x160);
LAB_14000192d:
    uVar2 = 0;
    uVar1 = 0x10;
    goto LAB_14000186f;
  }
  if (0x4010105 < param_3) {
    if (param_3 < 0xfd010102) {
      if (param_3 != 0xfd010101) {
        if (param_3 == 0x4010180) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_WAN_CO_GET_INFO)");
          }
          _Src = (undefined8 *)(param_1 + 0x22c0);
        }
        else {
          if (param_3 == 0x4010182) {
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
              McTemplateK0s_EtwWriteTransfer
                        (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_WAN_CO_GET_INFO)");
            }
            if (param_2 == 0) {
              return 0xc0010015;
            }
            _Src = (undefined8 *)(param_2 + 0xb4);
            uVar1 = 0x20;
            goto LAB_14000186f;
          }
          if (param_3 != 0xfd010100) goto switchD_140001949_caseD_10102;
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_PNP_CAPABILITIES)");
          }
          _Src = &local_50;
        }
        goto LAB_14000192d;
      }
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        pcVar3 = "QInfo(OID_PNP_SET_POWER)";
        goto LAB_140001b85;
      }
    }
    else if (param_3 == 0xfd010102) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        pcVar3 = "QInfo(OID_PNP_QUERY_POWER)";
LAB_140001b85:
        McTemplateK0s_EtwWriteTransfer(param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,pcVar3);
      }
    }
    else {
      if (param_3 != 0xfd010106) goto switchD_140001949_caseD_10102;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        pcVar3 = "QInfo(OID_PNP_ENABLE_WAKE_UP)";
        goto LAB_140001b85;
      }
    }
    uVar2 = 0;
    uVar1 = 0;
    goto LAB_140001884;
  }
  if (param_3 == 0x4010105) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_WAN_MEDIUM_SUBTYPE)");
    }
    local_58[0] = 0xe;
    goto LAB_14000186f;
  }
  if (0x12 < param_3 - 0x10101) {
switchD_140001949_caseD_10102:
    uVar2 = 0xc00000bb;
    uVar1 = 0;
    goto LAB_14000186f;
  }
  pcVar3 = IMAGE_DOS_HEADER_140000000.e_magic +
           (&switchD_140001949::switchdataD_1400102f0)[param_3 - 0x10101];
  switch(param_3) {
  case 0x10101:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (pcVar3,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_GEN_SUPPORTED_LIST)");
    }
    _Src = (undefined8 *)&DAT_140012120;
    uVar1 = 0x50;
    break;
  default:
    goto switchD_140001949_caseD_10102;
  case 0x10103:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (pcVar3,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_GEN_MEDIA_SUPPORTED)");
    }
    local_58[0] = 0xc;
    break;
  case 0x10105:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      pcVar4 = "QInfo(OID_GEN_MAXIMUM_LOOKAHEAD)";
LAB_140001986:
      McTemplateK0s_EtwWriteTransfer(pcVar3,&RasAgileVpnTraceInfo,&DAT_14000d218,pcVar4);
    }
    goto LAB_140001999;
  case 0x10106:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      pcVar4 = "QInfo(OID_GEN_MAXIMUM_FRAME_SIZE)";
      goto LAB_140001986;
    }
    goto LAB_140001999;
  case 0x1010c:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (pcVar3,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_GEN_VENDOR_ID)");
    }
    local_58[0] = 0xffffffff;
    uVar1 = 3;
    break;
  case 0x10111:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      pcVar4 = "QInfo(OID_GEN_MAXIMUM_TOTAL_SIZE)";
      goto LAB_140001986;
    }
LAB_140001999:
    local_58[0] = 0x5c8;
    break;
  case 0x10113:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (pcVar3,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_GEN_MAC_OPTIONS)");
    }
    local_58[0] = 5;
  }
LAB_14000186f:
  if (param_5 < uVar1) {
    uVar2 = 0xc0010014;
  }
  else {
    if (uVar1 != 0) {
      memmove(param_4,_Src,(ulonglong)uVar1);
    }
LAB_140001884:
    *param_6 = uVar1;
  }
  *param_7 = uVar1;
  return uVar2;
}



===== SetInformation @ 140001be0 =====

int SetInformation(undefined8 param_1,uint *param_2,int param_3,uint *param_4,uint param_5,
                  undefined4 *param_6,undefined4 *param_7)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  if (param_3 == -0x2fefeff) {
    iVar2 = 0;
    *param_7 = 0;
    *param_6 = 0;
  }
  else if (param_3 == 0x4010181) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"QInfo(OID_WAN_CO_SET_LINK_INFO)");
    }
    if (param_5 < 0x20) {
      iVar2 = -0x3ffeffec;
    }
    else {
      if (param_2 == (uint *)0x0) {
        return -0x3ffeffeb;
      }
      uVar1 = *(undefined8 *)(param_4 + 2);
      uVar3 = 0x20;
      *(undefined8 *)(param_2 + 0x2d) = *(undefined8 *)param_4;
      *(undefined8 *)(param_2 + 0x2f) = uVar1;
      uVar1 = *(undefined8 *)(param_4 + 6);
      *(undefined8 *)(param_2 + 0x31) = *(undefined8 *)(param_4 + 4);
      *(undefined8 *)(param_2 + 0x33) = uVar1;
    }
    *param_6 = uVar3;
    *param_7 = 0x20;
  }
  else if (param_3 == 0x4010283) {
    iVar2 = HandleQoSOidRequest(param_2,param_4,param_5,param_6,param_7);
  }
  else if (param_3 == 0x4010284) {
    iVar2 = HandleAdapterIndexOidRequest((int *)param_2,(int *)param_4,param_5,param_6,param_7);
  }
  else {
    *param_7 = 0;
    *param_6 = 0;
    iVar2 = -0x3fffff45;
  }
  return iVar2;
}



===== NetioAdvanceNetBuffer @ 140001d10 =====

void NetioAdvanceNetBuffer(longlong param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 != 0) {
    uVar1 = *(int *)(param_1 + 0x10) + param_2;
    if (uVar1 < *(uint *)(*(longlong *)(param_1 + 8) + 0x28)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + param_2;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - param_2;
      *(uint *)(param_1 + 0x10) = uVar1;
    }
    else {
      NdisAdvanceNetBufferDataStart(param_1,param_2,0,0);
    }
  }
  return;
}



===== NetioGetDataBufferIfSafe @ 140001d60 =====

ulonglong NetioGetDataBufferIfSafe(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = *(longlong *)(param_1 + 8);
  if ((uint)(*(int *)(lVar2 + 0x28) - *(int *)(param_1 + 0x10)) < param_2) {
    uVar1 = 0;
  }
  else {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000000);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x10) + lVar2;
    uVar1 = 0;
    if ((uVar3 & 1) == 0) {
      uVar1 = uVar3;
    }
  }
  return uVar1;
}



===== AgileVpnCmOpenAf @ 140001de0 =====

undefined8
AgileVpnCmOpenAf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmOpenAf is called");
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  DAT_140012270 = param_3;
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  *param_4 = &DAT_140012240;
  return 0;
}



===== AgileVpnMpRestart @ 140001e70 =====

undefined8 AgileVpnMpRestart(void)

{
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  DAT_140014514 = DAT_140014514 & 0xfffffffe;
  DAT_140012250 = MiniportPauseComplete;
  LOCK();
  DAT_140012248 = 1;
  UNLOCK();
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  return 0;
}



===== AgileVpnMpPauseHandler @ 140001ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AgileVpnMpPauseHandler(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = DAT_140012248 + -1;
  UNLOCK();
  bVar2 = DAT_140012248 == 1;
  DAT_140012248 = iVar1;
  if (bVar2) {
    (*DAT_140012250)(&DAT_140012248);
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  DAT_140014514 = DAT_140014514 | 1;
  if (DAT_140012248 == 0) {
    KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  }
  else {
    KeReleaseSpinLock();
    KeWaitForSingleObject(&DAT_140012258,0,0,0,0);
    KeClearEvent(&DAT_140012258);
  }
  return 0;
}



===== BwcCreateTimerUnits @ 140001fb0 =====

ulonglong BwcCreateTimerUnits(void)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  bool bVar7;
  
  uVar6 = 0;
  uVar2 = 0;
  if (BwcTimerUnits == 0) {
    lVar1 = ExAllocatePool2(0x40,(ulonglong)BwcNumberOfProcessors * 0xc0,0x61747742);
    if (lVar1 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      while (uVar4 = (uint)uVar6, uVar4 < BwcNumberOfProcessors) {
        uVar3 = BwcInitializeTimerUnit((void *)(uVar6 * 0xc0 + lVar1),uVar4);
        uVar2 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) goto LAB_14000203c;
        uVar6 = (ulonglong)(uVar4 + 1);
      }
      LOCK();
      bVar7 = BwcTimerUnits == 0;
      if (bVar7) {
        BwcTimerUnits = lVar1;
      }
      UNLOCK();
      if (!bVar7) {
LAB_14000203c:
        if (uVar4 != 0) {
          lVar5 = lVar1;
          do {
            BwcUninitializeTimerUnit(lVar5);
            lVar5 = lVar5 + 0xc0;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        ExFreePoolWithTag(lVar1,0x61747742);
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== BwcInitializeTimerUnit @ 140002090 =====

undefined8 BwcInitializeTimerUnit(void *param_1,undefined4 param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_res18 [2];
  
  local_res18[0] = 0;
  lVar2 = ExAllocatePool2(0x42,0x638,0x77747742);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    cVar1 = RtlInitializeTimerWheel(lVar2,0x40,1,1,0);
    if (cVar1 == '\0') {
      ExFreePoolWithTag(lVar2,0x77747742);
      uVar3 = 0xc0000001;
    }
    else {
      memset(param_1,0,0xc0);
      *(undefined4 *)((longlong)param_1 + 0xac) = 1;
      KeInitializeDpc((longlong)param_1 + 0x20,BwcTimeoutHandler,param_1);
      KeGetProcessorNumberFromIndex(param_2,local_res18);
      KeSetTargetProcessorDpcEx((longlong)param_1 + 0x20,local_res18);
      KeInitializeTimerEx((longlong)param_1 + 0x60,0);
      KeInitializeSpinLock(param_1);
      *(undefined4 *)((longlong)param_1 + 8) = 0;
      *(longlong *)((longlong)param_1 + 0xa0) = lVar2;
      RtlSuspendTimerWheel(lVar2);
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== MiniportPauseComplete @ 1400021e0 =====

void MiniportPauseComplete(void)

{
  KeSetEvent(&DAT_140012258,0,0);
  return;
}



===== AgileVpnCmRequest @ 140002210 =====

undefined8
AgileVpnCmRequest(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (*(int *)(param_4 + 4) == 0) {
    uVar1 = QueryCmInformation(param_2,*(int *)(param_4 + 0x20),*(undefined4 **)(param_4 + 0x28),
                               *(uint *)(param_4 + 0x30),(uint *)(param_4 + 0x34),
                               (uint *)(param_4 + 0x38));
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== QueryCmInformation @ 140002260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
QueryCmInformation(longlong param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5,
                  uint *param_6)

{
  int iVar1;
  undefined8 *_Dst;
  uint uVar2;
  undefined8 *_Src;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStack_348 [32];
  undefined4 local_318 [2];
  longlong local_310;
  uint *local_308;
  undefined4 local_300;
  undefined4 uStack_2fc;
  undefined4 local_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined4 local_2d8 [2];
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined4 local_2b4;
  int local_2b0;
  int local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_25c;
  undefined4 local_1c4;
  undefined2 local_1ac [66];
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_c8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_348;
  local_308 = param_5;
  local_300 = 0;
  uStack_2fc = 0;
  local_2f8 = 0;
  local_310 = param_1;
  memset(local_2d8,0,0x1b0);
  _Dst = (undefined8 *)&local_128;
  memset(_Dst,0,0xf0);
  uVar2 = 0;
  _Src = (undefined8 *)local_318;
  local_318[0] = 0;
  local_2f0 = 0;
  uStack_2e8 = 0;
  local_2e0 = 0;
  uVar4 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (_Dst,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,"QueryCmInformation: OID",
               (char)param_2);
  }
  if (param_2 == -0x1ffeffe) {
    if (param_4 < 0x1b0) goto LAB_14000236d;
    local_2d8[0] = *param_3;
    local_2d0 = param_3[2];
    local_2cc = 0x1a8;
    local_2c8 = 0x1a8;
    local_2b4 = local_2d8[0];
    iVar1 = StrLenW(L"AgileVPN");
    uVar3 = (ulonglong)(iVar1 + 1U);
    if (0x40 < iVar1 + 1U) {
      uVar3 = 0x40;
    }
    memmove(local_1ac,L"AgileVPN",uVar3 * 2);
    local_1ac[uVar3] = 0;
    local_2b0 = (int)uVar3 * 2;
    _Src = (undefined8 *)local_2d8;
    local_2a8 = 3;
    local_2ac = (int)local_1ac - (int)&local_2d0;
    local_2a0 = 1;
    uVar2 = 0x1b0;
    local_29c = 8;
    local_298 = 1000000;
    local_294 = 0x102;
    local_25c = 1;
    local_1c4 = 0x10;
LAB_1400024f1:
    memmove(param_3,_Src,(ulonglong)uVar2);
  }
  else if (param_2 == -0x1ffefff) {
    uStack_2fc = 1;
    local_2f8 = 0;
    _Src = (undefined8 *)&local_300;
    local_300 = 0x30000;
    uVar2 = 0xc;
LAB_140002416:
    if (param_4 < uVar2) {
      uVar4 = 0xc0010014;
      goto LAB_140002509;
    }
    if (uVar2 != 0) goto LAB_1400024f1;
  }
  else {
    if (param_2 != -0x1ffeffd) {
      if (param_2 == -0x1ffeff9) {
        if (local_310 == 0) goto LAB_14000236d;
        uStack_2e8 = 0;
        local_2e0 = 0;
        local_2f0 = 0x100000001;
        _Src = &local_2f0;
        uVar2 = 0x18;
      }
      else {
        uVar4 = 0xc00000bb;
      }
      goto LAB_140002416;
    }
    if (0xef < param_4) {
      local_124 = param_3[1];
      _Src = (undefined8 *)&local_128;
      local_128 = *param_3;
      uVar2 = 0xf0;
      local_c8 = DAT_140014510;
      local_11c = 0xe4;
      local_118 = 0xe4;
      local_114 = 0xe4;
      local_110 = local_128;
      goto LAB_1400024f1;
    }
LAB_14000236d:
    uVar4 = 0xc0010015;
  }
  *local_308 = uVar2;
LAB_140002509:
  *param_6 = uVar2;
  return uVar4;
}



===== StrLenW @ 140002550 =====

int StrLenW(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != (short *)0x0) {
    sVar1 = *param_1;
    while (sVar1 != 0) {
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      sVar1 = *param_1;
    }
  }
  return iVar2;
}



===== NsiCliRegisterClient @ 140002580 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NsiCliRegisterClient(void)

{
  int iVar1;
  
  NsiCliTag = 0x736e5641;
  KeInitializeEvent(&NsiCliDriverUnloadEvent,0,0);
  _DAT_140012198 = _NsiGuid;
  uRam000000014001219c = uRam0000000140012114;
  uRam00000001400121a0 = uRam0000000140012118;
  uRam00000001400121a4 = uRam000000014001211c;
  iVar1 = NmrRegisterClient(&NsiCliNotify,0,&NsiCliHandle);
  if (iVar1 == 0) {
    LOCK();
    NsiCliDriverRefCount = NsiCliDriverRefCount + 1;
    UNLOCK();
  }
  return;
}



===== AgileVpnGetPacketsForProcessing @ 1400025f0 =====

void AgileVpnGetPacketsForProcessing(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  param_2[1] = (longlong)param_2;
  *param_2 = (longlong)param_2;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1 + 0x38,&local_28);
  plVar4 = (longlong *)(param_1 + 8);
  plVar1 = (longlong *)*plVar4;
  if (plVar1 == plVar4) {
LAB_14000268e:
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
    return;
  }
  if (((longlong *)plVar1[1] == plVar4) &&
     (plVar2 = *(longlong **)(param_1 + 0x10), (longlong *)*plVar2 == plVar4)) {
    *plVar2 = (longlong)plVar1;
    plVar1[1] = (longlong)plVar2;
    *(longlong **)(param_1 + 0x10) = plVar4;
    *plVar4 = (longlong)plVar4;
    plVar4 = (longlong *)param_2[1];
    if ((*(longlong **)(*param_2 + 8) == param_2) &&
       ((((longlong *)*plVar4 == param_2 && ((longlong *)*(longlong *)(*plVar1 + 8) == plVar1)) &&
        ((longlong *)*(longlong *)plVar1[1] == plVar1)))) {
      *plVar4 = (longlong)plVar1;
      param_2[1] = plVar1[1];
      *(longlong **)plVar1[1] = param_2;
      plVar1[1] = (longlong)plVar4;
      goto LAB_14000268e;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== GetCurrentProcessor @ 1400026b8 =====

uint GetCurrentProcessor(void)

{
  uint uVar1;
  
  uVar1 = KeGetCurrentProcessorNumberEx();
  return uVar1 & -(uint)(uVar1 < DAT_1400165c0);
}



===== ScheduleSystemWorkerThread @ 1400026e0 =====

void ScheduleSystemWorkerThread(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  PsCreateSystemThread(param_2,0x1fffff,&local_38,0,0,AgileVpnProcessPackets,param_2);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140002748 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140012098;
  uVar2 = 0;
  if (DAT_140012098 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140012098;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context,param_2,param_3,0,param_4,param_5
                  );
  return;
}



===== RasAgileVpnRegisterEtw @ 1400027b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong RasAgileVpnRegisterEtw(void)

{
  ulonglong uVar1;
  
  uVar1 = McGenEventRegister_EtwRegister();
  if (-1 < (int)uVar1) {
    uVar1 = 0;
    if (Microsoft_Windows_Networking_CorrelationHandle == 0) {
      uVar1 = EtwRegister(&Microsoft_Windows_Networking_CorrelationId,
                          Microsoft_Windows_Networking_Correlation_EtwEnableCallback,0,
                          &Microsoft_Windows_Networking_CorrelationHandle);
      if ((int)uVar1 != 0) {
        if ((int)uVar1 < 0) {
          McGenEventUnregister_EtwUnregister(&MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context);
          return uVar1 & 0xffffffff;
        }
        return uVar1;
      }
    }
    _Microsoft_Windows_Networking_ProviderId = 0x4ec1438eb5325cd6;
    uRam0000000140016d08 = 0xe470256ff41446aa;
  }
  return uVar1;
}



===== McGenEventRegister_EtwRegister @ 14000282c =====

void McGenEventRegister_EtwRegister(void)

{
  if (MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context == 0) {
    EtwRegister(&MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER,McGenControlCallbackV2,
                &MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context,
                &MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context);
  }
  return;
}



===== McTemplateK0sx_EtwWriteTransfer @ 14000286c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_2c = 0;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_20 = 8;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0s_EtwWriteTransfer @ 140002900 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0s_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_1c = 0;
  local_28 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",param_2,param_3,2,local_38);
  return;
}



===== __report_gsfailure @ 140002990 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScheduleWork @ 1400029a0 =====

undefined8 ScheduleWork(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = NdisAllocateIoWorkItem(DAT_140012240);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    NdisQueueIoWorkItem(lVar1,param_1,param_2);
    uVar2 = 0;
  }
  return uVar2;
}



===== _guard_check_icall @ 140002a00 =====

void _guard_check_icall(void)

{
  return;
}



===== AgileVpnMpCoActivateVc @ 140002a10 =====

undefined8 AgileVpnMpCoActivateVc(void)

{
  return 0;
}



===== AgileVpnMpHalt @ 140002a20 =====

void AgileVpnMpHalt(undefined8 param_1)

{
  bool bVar1;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer(param_1,&RasAgileVpnTraceInfo,&DAT_14000d218,"AgileVpnMpHalt:");
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  DAT_140012240 = 0;
  DAT_140014514 = DAT_140014514 | 3;
  bVar1 = DAT_140012248 != 0;
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  if (bVar1) {
    KeWaitForSingleObject(&DAT_140012258,0,0,0,0);
    KeClearEvent(&DAT_140012258);
  }
  return;
}



===== HandleAdapterIndexOidRequest @ 140002ad8 =====

int HandleAdapterIndexOidRequest
              (int *param_1,int *param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  
  iVar1 = 0;
  *param_5 = 8;
  if (param_3 < 8) {
    iVar1 = -0x3ffeffeb;
  }
  else {
    *param_4 = 8;
    if (param_1[0x51] == 0) {
      param_1[0x51] = *param_2;
      piVar3 = param_1;
      uVar2 = AddTunnelCbToAdapterIndexHashTable(param_1);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
          return iVar1;
        }
        McTemplateK0sx_EtwWriteTransfer
                  (piVar3,&RasAgileVpnTraceIntArgError,&DAT_14000d218,
                   "HandleAdapterIndexOidRequest: AddTunnelCbToAdapterIndexHashTable failed with Status %!STATUS!"
                   ,(char)uVar2);
        return iVar1;
      }
    }
    if (param_1[0x52] == 0) {
      param_1[0x52] = param_2[1];
    }
  }
  return iVar1;
}



===== AgileVpnCmCloseAf @ 140002b80 =====

undefined8 AgileVpnCmCloseAf(undefined8 param_1)

{
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmCloseAf is called");
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  DAT_140012270 = 0;
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  return 0;
}



===== AgileVpnCmCloseCall @ 140002bf0 =====

undefined8 AgileVpnCmCloseCall(int *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  bool bVar3;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmCloseCall:");
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
  uVar1 = param_1[0x35];
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  param_1[0x35] = uVar1 | 0x2000;
  bVar3 = (uVar1 & 0x10) == 0;
  if (bVar3) {
    param_1[0x35] = uVar1 | 0x2008;
  }
  KeReleaseSpinLock(param_1 + 0xe);
  if (bVar3) {
    InitiateConnectionCleanup(param_1,0);
  }
  return 0x103;
}



===== AgileVpnCmCreateVc @ 140002cb0 =====

undefined8 AgileVpnCmCreateVc(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong *plVar2;
  code *pcVar3;
  int *_Dst;
  longlong *plVar4;
  undefined *puVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar8 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmCreateVc is called");
  }
  puVar5 = &DAT_1400122c0;
  _Dst = (int *)ExAllocateFromNPagedLookasideList();
  if (_Dst == (int *)0x0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar5,&RasAgileVpnTraceError,&DAT_14000e170,"NdisMInitializeWrapper returns NULL")
      ;
    }
    uVar8 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x180);
    _Dst[0x5c] = -1;
    *(code **)(_Dst + 2) = CleanupTunnelCb;
    *(undefined8 *)(_Dst + 0x12) = param_2;
    KeInitializeSpinLock(_Dst + 0xe);
    KeInitializeSpinLock(_Dst + 0x40);
    *(undefined1 *)(_Dst + 0x50) = 0;
    piVar1 = _Dst + 6;
    _Dst[5] = 0x63545641;
    *(int **)(_Dst + 8) = piVar1;
    *(int **)piVar1 = piVar1;
    piVar1 = _Dst + 0x54;
    *(int **)(_Dst + 0x56) = piVar1;
    *(int **)piVar1 = piVar1;
    *param_3 = _Dst;
    LOCK();
    *_Dst = *_Dst + 1;
    UNLOCK();
    _Dst[0x35] = _Dst[0x35] | 1;
    plVar2 = (longlong *)(_Dst + 10);
    *(longlong **)(_Dst + 0xc) = plVar2;
    *plVar2 = (longlong)plVar2;
    DAT_1400144e8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144e0);
    puVar7 = auStack_28;
    lVar6 = *DAT_1400144d0;
    plVar4 = DAT_1400144d0;
    if (*(longlong **)(lVar6 + 8) != DAT_1400144d0) {
      lVar6 = 3;
      pcVar3 = (code *)swi(0x29);
      plVar4 = (longlong *)(*pcVar3)();
      puVar7 = auStack_20;
    }
    *plVar2 = lVar6;
    *(longlong **)(_Dst + 0xc) = plVar4;
    *(longlong **)(lVar6 + 8) = plVar2;
    *plVar4 = (longlong)plVar2;
    *(undefined8 *)(puVar7 + -8) = 0x140002e11;
    KeReleaseSpinLock(&DAT_1400144e0,DAT_1400144e8);
    piVar1 = _Dst + 0x44;
    *(int **)(_Dst + 0x46) = piVar1;
    *(int **)piVar1 = piVar1;
    piVar1 = _Dst + 0x48;
    *(int **)(_Dst + 0x4a) = piVar1;
    *(int **)piVar1 = piVar1;
  }
  return uVar8;
}



===== AgileVpnCmDeleteVc @ 140002e50 =====

undefined8 AgileVpnCmDeleteVc(int *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmDeleteVc is called");
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
  *(undefined1 *)(param_1 + 0x10) = uVar5;
  RemoveTunnelCbFromTunnelIdHashTable(param_1);
  RemoveTunnelCbFromAdapterIndexHashTable(param_1);
  param_1[0x35] = param_1[0x35] & 0xfffffffe;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  if (*(longlong *)(param_1 + 0x4c) != 0) {
    BwcDereferenceQoSPolicy(*(longlong *)(param_1 + 0x4c));
    param_1[0x4c] = 0;
    param_1[0x4d] = 0;
  }
  if (*(longlong *)(param_1 + 0x4e) != 0) {
    BwcDereferenceQoSPolicy(*(longlong *)(param_1 + 0x4e));
    param_1[0x4e] = 0;
    param_1[0x4f] = 0;
  }
  KeReleaseSpinLock(param_1 + 0xe,(char)param_1[0x10]);
  DAT_1400144e8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144e0);
  plVar1 = (longlong *)(param_1 + 10);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_1 + 0xc), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar6 = (*pcVar4)();
    return uVar6;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseSpinLock(&DAT_1400144e0,CONCAT71((int7)((ulonglong)plVar1 >> 8),DAT_1400144e8));
  if ((param_1[0x17] != 0) && ((char)param_1[0x16] == '\0')) {
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
    ScheduleWork(DeleteHostRoutePassive,param_1);
  }
  DereferenceRefCount(param_1);
  return 0;
}



===== AgileVpnCmDeregisterSap @ 140002f90 =====

undefined8 AgileVpnCmDeregisterSap(undefined8 param_1)

{
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmDeregisterSap: ");
  }
  ScheduleWork(AgileVpnCmDeregisterSapPassive,&DAT_140012240);
  return 0x103;
}



===== AgileVpnCmDeregisterSapPassive @ 140002fe0 =====

void AgileVpnCmDeregisterSapPassive(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmDeregisterSapPassive");
  }
  if (param_2 != 0) {
    NdisFreeIoWorkItem(param_2);
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  uVar1 = DAT_140012278;
  puVar2 = &DAT_1400144f0;
  DAT_140012278 = 0;
  DAT_140012284 = 0;
  DAT_140012280 = 0;
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  AgileVpnCleanUpWfpCallouts(puVar2);
  NdisCmDeregisterSapComplete(0,uVar1);
  return;
}



===== AgileVpnCmMakeCall @ 140003090 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AgileVpnCmMakeCall(int *param_1,uint *param_2,undefined8 param_3,undefined8 *param_4)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  code *pcVar7;
  undefined *puVar8;
  code *pcVar9;
  char *pcVar10;
  undefined1 auStack_98 [32];
  int local_68 [2];
  code *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmMakeCall: ");
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
  local_60 = (code *)0x0;
  *(undefined1 *)(param_1 + 0x10) = uVar4;
  bVar3 = true;
  uVar1 = *param_2;
  pcVar7 = (code *)(ulonglong)uVar1;
  local_68[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((uVar1 & 0x19) != 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (pcVar7,&RasAgileVpnTraceIntArgError,&DAT_14000e170,
                 "AgileVpnCmMakeCall: CallParameters flags are invalid Flags",(char)uVar1);
    }
    iVar6 = -0x3fffff45;
    goto LAB_140003373;
  }
  lVar2 = *(longlong *)(param_2 + 4);
  pcVar7 = (code *)(ulonglong)*(uint *)(lVar2 + 0x14);
  if (*(uint *)(lVar2 + 0x14) < 0x30) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      pcVar10 = "AgileVpnCmMakeCall: Media spcific param length is invalid: Length = ";
LAB_140003162:
      pcVar9 = pcVar7;
LAB_140003167:
      puVar8 = &RasAgileVpnTraceIntArgError;
LAB_14000316e:
      McTemplateK0sx_EtwWriteTransfer(pcVar7,puVar8,&DAT_14000e170,pcVar10,(char)pcVar9);
    }
  }
  else {
    pcVar7 = (code *)(ulonglong)*(ushort *)(lVar2 + 0x38);
    if (*(ushort *)(lVar2 + 0x38) < 0xb4) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        pcVar10 = "AgileVpnCmMakeCall: LineCallParams length is invalid: length ";
        puVar8 = &RasAgileVpnTraceIntArgInfo;
        pcVar9 = pcVar7;
        goto LAB_14000316e;
      }
    }
    else {
      pcVar7 = (code *)(*(longlong *)(lVar2 + 0x40) + 0x38 + lVar2);
      if ((*(uint *)(pcVar7 + 0x10) & 0xfffffeef) == 0) {
        pcVar9 = (code *)(ulonglong)*(uint *)(pcVar7 + 0x68);
        if (*(uint *)(pcVar7 + 0x68) < 0x28) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar10 = "AgileVpnCmMakeCall: LineCallParams ulDevSpecificSize is invalid: size";
            goto LAB_140003167;
          }
        }
        else {
          pcVar9 = pcVar7 + *(uint *)(pcVar7 + 0x6c);
          *(undefined8 *)(param_1 + 0x2a) = *(undefined8 *)(pcVar9 + 8);
          param_1[0x17] = *(int *)(pcVar9 + 4);
          *(undefined4 *)pcVar9 = 0x53415252;
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            McTemplateK0sx_EtwWriteTransfer
                      (pcVar7,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,
                       "AgileVpnCmMakeCall: TunnelId ",(char)*(undefined8 *)(param_1 + 0x2a));
          }
          *(code *)(param_1 + 0x2c) = pcVar9[0x20];
          pcVar7 = (code *)(ulonglong)*(ushort *)(lVar2 + 0x28);
          if (*(ushort *)(lVar2 + 0x28) < 0x83) {
            pcVar7 = (code *)(lVar2 + 0x28 + *(longlong *)(lVar2 + 0x30));
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
              McTemplateK0sz_EtwWriteTransfer();
            }
            iVar6 = RtlIpv6StringToAddressW(pcVar7,&local_60,&local_58);
            if ((iVar6 < 0) || (*(short *)local_60 != 0)) {
              iVar6 = RtlIpv4StringToAddressW(pcVar7,1,&local_60,local_68);
              if ((iVar6 < 0) || (pcVar7 = local_60, *(short *)local_60 != 0)) {
                if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
                  McTemplateK0s_EtwWriteTransfer
                            (pcVar7,&RasAgileVpnTraceError,&DAT_14000e170,
                             "AgileVpnCmMakeCall: Invalid Address");
                }
                goto LAB_140003373;
              }
              param_1[0x20] = local_68[0];
              uVar5 = 2;
            }
            else {
              uVar5 = 0x17;
              param_1[0x21] = (int)local_58;
              param_1[0x22] = local_58._4_4_;
              param_1[0x23] = (int)uStack_50;
              param_1[0x24] = uStack_50._4_4_;
            }
            *(undefined2 *)(param_1 + 0x1f) = uVar5;
            param_1[0x35] = param_1[0x35] | 0x800;
            *(uint **)(param_1 + 0x14) = param_2;
            *(undefined1 *)(param_1 + 0x16) = 0;
            KeReleaseSpinLock(param_1 + 0xe,(char)param_1[0x10]);
            bVar3 = false;
            LOCK();
            *param_1 = *param_1 + 1;
            UNLOCK();
            pcVar7 = AgileVpnMakeCallComplete;
            ScheduleWork(AgileVpnMakeCallComplete,param_1);
            iVar6 = 0x103;
            goto LAB_140003373;
          }
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar10 = "AgileVpnCmMakeCall: DestAddress length is invalid: length";
            goto LAB_140003162;
          }
        }
      }
      else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (pcVar7,&RasAgileVpnTraceError,&DAT_14000e170,
                   "AgileVpnCmMakeCall: LineCallParams ulMediaMode is invalid:");
      }
    }
  }
  iVar6 = -0x3ffeffeb;
LAB_140003373:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (pcVar7,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,"AgileVpnCmMakeCall: done:",
               (char)iVar6);
  }
  if (bVar3) {
    KeReleaseSpinLock(param_1 + 0xe,(char)param_1[0x10]);
  }
  return iVar6;
}



===== AgileVpnCmRegisterSap @ 1400033e0 =====

undefined8 AgileVpnCmRegisterSap(undefined8 param_1,int *param_2,longlong param_3)

{
  undefined8 uVar1;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmRegisterSap: ");
  }
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc();
  if (DAT_140012278 == 0) {
    if ((*param_2 == 0x8000) && (0xb < (uint)param_2[1])) {
      DAT_140012280 = param_2[2];
      DAT_140012284 = param_2[3];
      if (DAT_140012284 == -1) {
        DAT_140012284 = 0;
      }
    }
    DAT_140012278 = param_3;
    KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
    ScheduleWork(AgileVpnCmRegisterSapPassive,&DAT_140012240);
    uVar1 = 0x103;
  }
  else {
    KeReleaseSpinLock(&DAT_1400144f0);
    uVar1 = 0xc0010021;
  }
  return uVar1;
}



===== AgileVpnCmRegisterSapPassive @ 1400034c0 =====

void AgileVpnCmRegisterSapPassive(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmRegisterSapPassive is called"
              );
  }
  if (param_2 != 0) {
    NdisFreeIoWorkItem(param_2);
  }
  if (g_fPagesLocked == '\0') {
    MmLockPagableDataSection(AgileVpnCmActivateVcComplete);
    g_fPagesLocked = '\x01';
  }
  iVar2 = AgileVpnSetupWfpCallouts();
  puVar3 = &DAT_1400144f0;
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc();
  uVar1 = DAT_140012278;
  if (iVar2 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar3,&RasAgileVpnTraceError,&DAT_14000e170,"Setup of Callouts failed ");
    }
    DAT_140012278 = 0;
  }
  else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (puVar3,&RasAgileVpnTraceError,&DAT_14000e170,"Setup of Callouts suceeded");
  }
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  NdisCmRegisterSapComplete(iVar2,uVar1,&DAT_140012240);
  return;
}



===== AgileVpnMakeCallComplete @ 1400035f0 =====

void AgileVpnMakeCallComplete(int *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  int *piVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint local_res8 [2];
  int local_res10 [2];
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnMakeCallComplete: ");
  }
  if (param_2 != 0) {
    NdisFreeIoWorkItem(param_2);
  }
  if (g_fPagesLocked == '\0') {
    MmLockPagableDataSection(AgileVpnCmActivateVcComplete);
    g_fPagesLocked = '\x01';
  }
  piVar1 = param_1 + 0xe;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  *(undefined1 *)(param_1 + 0x10) = uVar3;
  if ((param_1[0x35] & 0x20U) == 0) {
    piVar7 = piVar1;
    KeReleaseSpinLock(piVar1,uVar3);
    uVar4 = AgileVpnSetupWfpCallouts();
    uVar9 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (piVar7,&RasAgileVpnTraceError,&DAT_14000e170,
                   "Setup of Callouts failed..Failing MakeCall ");
      }
    }
    else {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (piVar7,&RasAgileVpnTraceInfo,&DAT_14000e170,"Setup of Callouts succeeded");
      }
      uVar6 = AddTunnelCbToTunnelIdHashTable(param_1);
      uVar9 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        uVar6 = (ulonglong)(uint)param_1[0x17];
        iVar5 = NsiCliGetLinkSpeedAndMTUFromInterfaceIndex
                          (param_1[0x17],local_res8,local_res10,(short)param_1[0x1f] == 2);
        uVar9 = (ulonglong)iVar5;
        if (-1 < iVar5) {
          uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
          *(undefined1 *)(param_1 + 0x10) = uVar3;
          param_1[0x37] = local_res8[0];
          param_1[0x38] = local_res10[0] + -100;
          **(uint **)(*(longlong *)(param_1 + 0x14) + 8) = local_res8[0] >> 3;
          *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x14) + 8) + 8) = (uint)param_1[0x37] >> 3
          ;
          *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x14) + 8) + 0x18) = param_1[0x38];
          *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x14) + 8) + 0x20) =
               (uint)param_1[0x37] >> 3;
          *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x14) + 8) + 0x28) =
               (uint)param_1[0x37] >> 3;
          lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x14) + 8);
          *(int *)(lVar2 + 0x38) = param_1[0x38];
          KeReleaseSpinLock(piVar1,CONCAT71((int7)((ulonglong)lVar2 >> 8),(char)param_1[0x10]));
          uVar8 = *(undefined8 *)(param_1 + 0x12);
          uVar4 = NdisMCmActivateVc(uVar8,*(undefined8 *)(param_1 + 0x14));
          if (uVar4 != 0x103) {
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
              McTemplateK0sx_EtwWriteTransfer
                        (uVar8,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,
                         "AgileVpnMakeCallComplete: NdisMCmActivateVc:",(char)uVar4);
            }
            AgileVpnCmActivateVcComplete((ulonglong)uVar4,param_1);
          }
          goto LAB_14000371a;
        }
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (uVar6,&RasAgileVpnTraceIntArgError,&DAT_14000e170,
                     "AgileVpnMakeCallComplete:NsiCliGetLinkSpeedAndMTUFromInterfaceIndex failed:",
                     (char)iVar5);
        }
      }
    }
  }
  else {
    piVar7 = piVar1;
    KeReleaseSpinLock();
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar7,&RasAgileVpnTraceError,&DAT_14000e170,
                 "Tunnel is already in cleanup..Failing MakeCall ");
    }
    uVar9 = 0xc0000001;
  }
  NdisCmMakeCallComplete
            (uVar9 & 0xffffffff,*(undefined8 *)(param_1 + 0x12),0,0,*(undefined8 *)(param_1 + 0x14))
  ;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  param_1[0x35] = param_1[0x35] & 0xfffff7ff;
  *(undefined1 *)(param_1 + 0x10) = uVar3;
  KeReleaseSpinLock(piVar1,uVar3);
  InitiateConnectionCleanup(param_1,(int)uVar9);
LAB_14000371a:
  DereferenceRefCount(param_1);
  return;
}



===== CleanupTunnelCb @ 140003900 =====

void CleanupTunnelCb(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer(param_1,&RasAgileVpnTraceInfo,&DAT_14000e170,"CleanupTunnelCb: ")
    ;
  }
  plVar2 = *(longlong **)(param_1 + 0x110);
  while (plVar2 != (longlong *)(param_1 + 0x110)) {
    plVar1 = (longlong *)*plVar2;
    DeleteTSNode(plVar2);
    plVar2 = plVar1;
  }
  plVar2 = *(longlong **)(param_1 + 0x120);
  while (plVar2 != (longlong *)(param_1 + 0x120)) {
    plVar1 = (longlong *)*plVar2;
    DeleteTSNode(plVar2);
    plVar2 = plVar1;
  }
  ExFreeToNPagedLookasideList(&DAT_1400122c0,param_1);
  return;
}



===== DeleteCurrentTSTRList @ 1400039a0 =====

void DeleteCurrentTSTRList(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    ExFreeToNPagedLookasideList(&DAT_1400123c0);
  }
  lVar1 = *(longlong *)(param_1 + 0x30);
  while (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    ExFreeToNPagedLookasideList(&DAT_1400123c0);
  }
  return;
}



===== DeleteHostRoutePassive @ 140003a10 =====

void DeleteHostRoutePassive(int *param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  
  if (param_2 != 0) {
    NdisFreeIoWorkItem(param_2);
  }
  piVar1 = param_1 + 0xe;
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  uVar2 = param_1[0x35];
  *(undefined1 *)(param_1 + 0x10) = uVar3;
  KeReleaseSpinLock(piVar1,uVar3);
  if ((uVar2 >> 8 & 1) != 0) {
    NsiCliAddOrDeleteHostRouteToInterface((SOCKADDR_INET *)(param_1 + 0x1f),param_1[0x17],'\0');
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(piVar1);
  param_1[0x35] = param_1[0x35] & 0xfffffeff;
  *(undefined1 *)(param_1 + 0x10) = uVar3;
  KeReleaseSpinLock(piVar1,uVar3);
  DereferenceRefCount(param_1);
  return;
}



===== DeleteTSNode @ 140003ac4 =====

void DeleteTSNode(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = param_1 + -1;
  if (plVar1 != (longlong *)0x0) {
    DeleteCurrentTSTRList((longlong)plVar1);
    lVar2 = *param_1;
    if ((*(longlong **)(lVar2 + 8) != param_1) ||
       (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 != param_1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreeToNPagedLookasideList(&DAT_140012340,plVar1);
  }
  return;
}



===== InitiateConnectionCleanup @ 140003b2c =====

void InitiateConnectionCleanup(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int *piVar5;
  uint uVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_1 + 0x35);
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,
               "InitiateConnectionCleanup: called: cleanup State:",(char)*puVar7);
  }
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  piVar5 = param_1 + 0xe;
  uVar1 = KeAcquireSpinLockRaiseToDpc(piVar5);
  uVar2 = *puVar7;
  uVar6 = uVar2 | 0x20;
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  *puVar7 = uVar6;
  if ((uVar2 & 0xa00) == 0) {
    uVar3 = (ulonglong)CONCAT31((int3)(uVar2 >> 8),(char)uVar6) & 0xffffffffffffff0c;
    if ((char)uVar3 == '\x04') {
      *puVar7 = uVar2 & 0xfffffffb | 0x30;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (uVar3,&RasAgileVpnTraceInfo,&DAT_14000e170,
                   "InitiateConnectionCleanup: NdisMCmDispatchIncomingCloseCall: called");
      }
      KeReleaseSpinLock(piVar5,(char)param_1[0x10]);
      NdisCmDispatchIncomingCloseCall(param_2,*(undefined8 *)(param_1 + 0x12),0,0);
      uVar1 = KeAcquireSpinLockRaiseToDpc(piVar5);
      *puVar7 = *puVar7 & 0xffffffef;
      *(undefined1 *)(param_1 + 0x10) = uVar1;
      *(undefined1 *)(param_1 + 0x36) = 0;
      if ((*puVar7 & 0x2000) == 0) {
        KeReleaseSpinLock(piVar5);
      }
      else {
        KeReleaseSpinLock();
        InitiateConnectionCleanup(param_1,0);
      }
      DereferenceRefCount(param_1);
      goto LAB_140003c7f;
    }
    if (param_1[4] == 0) {
      if ((uVar2 & 0x1002) == 2) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (uVar3,&RasAgileVpnTraceInfo,&DAT_14000e170,
                     "InitiateConnectionCleanup: NdisMCmDeactivateVc: called");
        }
        *puVar7 = *puVar7 | 0x1000;
        KeReleaseSpinLock(piVar5,(char)param_1[0x10]);
        uVar2 = NdisMCmDeactivateVc(*(undefined8 *)(param_1 + 0x12));
        if (uVar2 != 0x103) {
          AgileVpnCmDeactivateVcComplete((ulonglong)uVar2,param_1);
        }
      }
      else {
        if ((uVar2 >> 0xd & 1) != 0) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (uVar3,&RasAgileVpnTraceInfo,&DAT_14000e170,
                       "InitiateConnectionCleanup: NdisMCmCloseCallComplete: called");
          }
          puVar7 = (uint *)(param_1 + 0x35);
          *puVar7 = *puVar7 & 0xffffdfff;
          if ((*puVar7 & 4) != 0) {
            DereferenceRefCount(param_1);
            *puVar7 = *puVar7 & 0xfffffffb;
            *(undefined1 *)(param_1 + 0x36) = 0;
          }
          KeReleaseSpinLock(piVar5,(char)param_1[0x10]);
          NdisCmCloseCallComplete(0,*(undefined8 *)(param_1 + 0x12),0);
          uVar1 = KeAcquireSpinLockRaiseToDpc(piVar5);
          *(undefined1 *)(param_1 + 0x10) = uVar1;
        }
        puVar7 = (uint *)(param_1 + 0x35);
        if ((char)param_1[0x16] != '\0') {
          FreeCallParams(*(longlong *)(param_1 + 0x14));
          param_1[0x14] = 0;
          param_1[0x15] = 0;
          if ((*puVar7 & 0x40) != 0) {
            uVar4 = *(undefined8 *)(param_1 + 0x12);
            *puVar7 = *puVar7 & 0xffffffbf;
            uVar1 = NdisMCmDeleteVc();
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
              McTemplateK0sx_EtwWriteTransfer
                        (uVar4,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,"NdisMCmDeleteVc: Status",
                         uVar1);
            }
            param_1[0x12] = 0;
            param_1[0x13] = 0;
          }
          if ((*puVar7 & 1) != 0) {
            KeReleaseSpinLock(param_1 + 0xe,(char)param_1[0x10]);
            AgileVpnCmDeleteVc(param_1);
            uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
            *(undefined1 *)(param_1 + 0x10) = uVar1;
          }
        }
        piVar5 = param_1 + 0xe;
        KeReleaseSpinLock(piVar5,(char)param_1[0x10]);
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (piVar5,&RasAgileVpnTraceInfo,&DAT_14000e170,"InitiateConnectionCleanup: done");
        }
      }
      goto LAB_140003c7f;
    }
    uVar6 = uVar2 | 0x4020;
    *puVar7 = uVar6;
  }
  KeReleaseSpinLock(piVar5,CONCAT31((int3)(uVar6 >> 8),uVar1));
LAB_140003c7f:
  DereferenceRefCount(param_1);
  return;
}



===== McTemplateK0sz_EtwWriteTransfer @ 140003e5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sz_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar3;
  longlong lVar2;
  longlong lVar4;
  ulonglong uVar5;
  wchar_t *in_stack_00000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar4 = -1;
  lVar3 = -1;
  do {
    lVar2 = lVar3 + 1;
    lVar1 = lVar3 + 1;
    lVar3 = lVar2;
  } while ("AgileVpnCmMakeCall: IPaddress "[lVar1] != '\0');
  local_30 = (int)lVar2 + 1;
  local_38 = "AgileVpnCmMakeCall: IPaddress ";
  local_2c = 0;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    uVar5 = 10;
  }
  else {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000028[lVar4] != L'\0');
    uVar5 = (ulonglong)((int)lVar4 * 2 + 2);
  }
  local_1c = 0;
  local_20 = (undefined4)uVar5;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_28 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(uVar5,&RasAgileVpnTraceIpAddress,&DAT_14000e170,3,local_48);
  return;
}



===== McTemplateK0xq_EtwWriteTransfer @ 140003f18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xq_EtwWriteTransfer
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
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== StringCchLengthW @ 140003f88 =====

HRESULT __stdcall StringCchLengthW(STRSAFE_PCNZWCH psz,size_t cchMax,size_t *pcchLength)

{
  uint uVar1;
  longlong lVar2;
  
  if (psz == (STRSAFE_PCNZWCH)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    lVar2 = 0x42;
    do {
      if (*psz == L'\0') break;
      psz = psz + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    uVar1 = ~-(uint)(lVar2 != 0) & 0x80070057;
    if (pcchLength != (size_t *)0x0) {
      if (lVar2 == 0) {
        *pcchLength = 0;
      }
      else {
        *pcchLength = 0x42 - lVar2;
      }
    }
    if (lVar2 != 0) {
      return uVar1;
    }
  }
  if (pcchLength != (size_t *)0x0) {
    *pcchLength = 0;
  }
  return uVar1;
}



===== AgileVpnCleanup @ 140003ff0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AgileVpnCleanup(undefined8 param_1,longlong param_2)

{
  LOCK();
  _DAT_140014518 = _DAT_140014518 + 1;
  UNLOCK();
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AgileVpnIoctlRequest @ 140004024 =====

uint AgileVpnIoctlRequest(uint *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint unaff_EBX;
  
  uVar2 = *(uint *)(param_2 + 0x18);
  uVar1 = *(uint *)(param_2 + 0x10);
  puVar3 = (uint *)(ulonglong)uVar1;
  if ((uVar2 & 0xffff0000) != 0x120000) {
    return unaff_EBX;
  }
  if (uVar2 == 0x128000) {
    puVar3 = param_1;
    uVar2 = AgileVpnCreateTunnel((longlong)param_1,uVar1);
LAB_140004113:
    if (uVar2 == 0x103) goto LAB_14000411f;
  }
  else {
    if (uVar2 == 0x128004) {
      puVar3 = param_1;
      uVar2 = AgileVpnInitiateUpdateClientTunnel((int *)param_1,uVar1);
      goto LAB_140004113;
    }
    if (uVar2 != 0x128008) {
      if (uVar2 == 0x12800c) {
        puVar3 = param_1;
        uVar2 = AgileVpnCompleteUpdateTunnelComplete((int *)param_1,uVar1);
      }
      else if (uVar2 == 0x128010) {
        puVar3 = param_1;
        uVar2 = AgileVpnNewIncomingConnection((int *)param_1,uVar1);
      }
      else if (uVar2 == 0x128014) {
        puVar3 = param_1;
        uVar2 = AgileVpnCloseTunnel((longlong)param_1,uVar1);
      }
      else if (uVar2 == 0x128018) {
        puVar3 = param_1;
        uVar2 = AgileVpnUpdateTunnelTS(param_1,uVar1,(undefined *)0x128018);
      }
      else {
        if (uVar2 != 0x12801c) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0sx_EtwWriteTransfer
                      (puVar3,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                       "AgileVpnIoctlRequest: Invalid function request",(char)uVar2);
          }
          uVar2 = 0xc0000010;
          goto LAB_14000411c;
        }
        puVar3 = param_1;
        uVar2 = AgileVpnUpdateConfiguredTS((int *)param_1,uVar1,(undefined *)0x12801c);
      }
      goto LAB_140004113;
    }
    uVar2 = 0;
  }
LAB_14000411c:
  param_1[0xc] = uVar2;
LAB_14000411f:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (puVar3,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnIoctlRequest: completed with",(char)uVar2);
  }
  return unaff_EBX;
}



===== GetStringFromAddr @ 140004160 =====

undefined8 GetStringFromAddr(undefined8 param_1,short param_2,undefined8 param_3)

{
  if (param_2 == 2) {
    RtlIpv4AddressToStringA();
  }
  else {
    RtlIpv6AddressToStringA(param_1,param_3);
  }
  return param_3;
}



===== IsAllowAllAddresses @ 14000419c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 IsAllowAllAddresses(undefined8 param_1,undefined8 param_2,short param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  if (param_3 == 2) {
    local_48 = 0xffffffff;
    lVar3 = 4;
    local_44 = (undefined1  [4])0x0;
    lVar1 = RtlCompareMemory(param_1,local_44,4);
    if ((lVar1 == 4) && (lVar1 = RtlCompareMemory(param_2,&local_48,4), lVar1 == 4)) {
      return 1;
    }
    lVar1 = RtlCompareMemory(param_1,&local_48,4);
    if (lVar1 != 4) {
      return 0;
    }
    puVar2 = (undefined8 *)local_44;
  }
  else {
    lVar3 = 0x10;
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0xffffffffffffffff;
    uStack_28 = 0xffffffffffffffff;
    lVar1 = RtlCompareMemory(0,&local_40,0x10);
    if ((lVar1 == 0x10) && (lVar1 = RtlCompareMemory(param_2,&local_30,0x10), lVar1 == 0x10)) {
      return 1;
    }
    lVar1 = RtlCompareMemory(param_1,&local_30,0x10);
    if (lVar1 != 0x10) {
      return 0;
    }
    puVar2 = &local_40;
  }
  lVar1 = RtlCompareMemory(param_2,puVar2,lVar3);
  if (lVar1 == lVar3) {
    return 1;
  }
  return 0;
}



===== IsAllowAllPorts @ 1400042e4 =====

undefined8 IsAllowAllPorts(short param_1,short param_2)

{
  if ((param_1 == 0) && (param_2 == -1)) {
    return 0xff01;
  }
  if (param_1 == -1) {
    return CONCAT71(0xff,param_2 == 0);
  }
  return 0xff00;
}



===== IsSapValid @ 140004310 =====

bool IsSapValid(void)

{
  bool bVar1;
  
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  bVar1 = DAT_140012278 != 0;
  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
  return bVar1;
}



===== McTemplateK0qqqqss_EtwWriteTransfer @ 140004370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqss_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  char *in_stack_00000048;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res20;
  local_68 = &uStack0000000000000028;
  local_58 = &uStack0000000000000030;
  local_48 = &uStack0000000000000038;
  uVar3 = 5;
  lVar1 = -1;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_20 = 5;
  if (in_stack_00000040 != (char *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000040[lVar2] != '\0');
    uVar3 = (ulonglong)((int)lVar2 + 1);
  }
  local_30 = (undefined4)uVar3;
  local_2c = 0;
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  if (in_stack_00000048 != (char *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000048[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  local_38 = in_stack_00000040;
  local_28 = in_stack_00000048;
  McGenEventWrite_EtwWriteTransfer(uVar3,&RasAgileVpnTraceTSInfo,&DAT_14000f3f8,7,local_88);
  return;
}



===== AddTunnelCbToAdapterIndexHashTable @ 14000447c =====

undefined8 AddTunnelCbToAdapterIndexHashTable(int *param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  uVar1 = param_1[0x51];
  uVar7 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f540,"AddTunnelCbToAdapterIndexHashTable:");
  }
  if (param_1[0x51] != 0) {
    DAT_140016590 = KeAcquireSpinLockRaiseToDpc(&DAT_140016588);
    puVar6 = auStack_38;
    plVar4 = (longlong *)(&DAT_140014588)[(ulonglong)(uVar1 & 0x1ff) * 2];
    for (plVar3 = plVar4; plVar3 != &DAT_140014588 + (ulonglong)(uVar1 & 0x1ff) * 2;
        plVar3 = (longlong *)*plVar3) {
      if (*(int *)((longlong)plVar3 + -0xc) == param_1[0x51]) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (plVar4,&RasAgileVpnTraceIntArgInfo,&DAT_14000f540,
                     "AddTunnelCbToTunnelIdHashTable: TunnelID %I64u: duplicate object found",
                     (char)param_1[0x51]);
        }
        puVar6 = auStack_38;
        uVar7 = 0xc000022a;
        goto LAB_140004567;
      }
    }
    lVar5 = *plVar4;
    plVar3 = (longlong *)(param_1 + 0x54);
    if (*(longlong **)(lVar5 + 8) != plVar4) {
      plVar4 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar2)();
      puVar6 = auStack_30;
    }
    *plVar3 = lVar5;
    plVar3[1] = (longlong)plVar4;
    *(longlong **)(lVar5 + 8) = plVar3;
    *plVar4 = (longlong)plVar3;
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
LAB_140004567:
    *(undefined8 *)(puVar6 + -8) = 0x14000457b;
    KeReleaseSpinLock(&DAT_140016588,DAT_140016590);
  }
  return uVar7;
}



===== FindTunnelCbFromAdapterIndex @ 14000459c =====

int * FindTunnelCbFromAdapterIndex(uint param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (param_1 != 0) {
    DAT_140016590 = KeAcquireSpinLockRaiseToDpc(&DAT_140016588);
    puVar2 = &DAT_140014588 + (ulonglong)(param_1 & 0x1ff) * 2;
    for (puVar1 = (undefined8 *)*puVar2; piVar3 = (int *)0x0, puVar1 != puVar2;
        puVar1 = (undefined8 *)*puVar1) {
      piVar3 = (int *)(puVar1 + -0x2a);
      if (*(uint *)((longlong)puVar1 + -0xc) == param_1) {
        LOCK();
        *piVar3 = *piVar3 + 1;
        UNLOCK();
        break;
      }
    }
    KeReleaseSpinLock(&DAT_140016588,CONCAT71((int7)((ulonglong)puVar2 >> 8),DAT_140016590));
  }
  return piVar3;
}



===== GetCompartmentIdFromTunnelId @ 140004630 =====

undefined8 GetCompartmentIdFromTunnelId(longlong param_1,int *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = (int *)FindTunnelCbFromTunnelId(param_1);
  *param_2 = 0;
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    *param_2 = piVar1[0x52];
    DereferenceRefCount(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== GetTunnelDataFromInterfaceIndex @ 140004670 =====

undefined8
GetTunnelDataFromInterfaceIndex
          (uint param_1,short param_2,undefined8 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined8 uVar2;
  
  piVar1 = FindTunnelCbFromAdapterIndex(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    if (param_2 == 2) {
      *param_5 = 4;
      param_5[1] = piVar1[0x20];
      *param_4 = 4;
      param_4[1] = piVar1[0x19];
      *param_3 = *(undefined8 *)(piVar1 + 0x2a);
      uVar2 = *(undefined8 *)(piVar1 + 0x3c);
    }
    else {
      *param_5 = 6;
      uVar2 = *(undefined8 *)(piVar1 + 0x23);
      *(undefined8 *)(param_5 + 1) = *(undefined8 *)(piVar1 + 0x21);
      *(undefined8 *)(param_5 + 3) = uVar2;
      *param_4 = 6;
      uVar2 = *(undefined8 *)(piVar1 + 0x1c);
      *(undefined8 *)(param_4 + 1) = *(undefined8 *)(piVar1 + 0x1a);
      *(undefined8 *)(param_4 + 3) = uVar2;
      *param_3 = *(undefined8 *)(piVar1 + 0x2a);
      uVar2 = *(undefined8 *)(piVar1 + 0x3e);
    }
    param_3[1] = uVar2;
    DereferenceRefCount(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== RemoveTunnelCbFromAdapterIndexHashTable @ 140004728 =====

undefined8 RemoveTunnelCbFromAdapterIndexHashTable(int *param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  uVar2 = param_1[0x51];
  uVar7 = 0xc0000034;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f540,
               "RemoveTunnelCbFromAdapterIndexHashTable:");
  }
  if (param_1[0x51] != 0) {
    DAT_140016590 = KeAcquireSpinLockRaiseToDpc(&DAT_140016588);
    for (puVar6 = (undefined8 *)(&DAT_140014588)[(ulonglong)(uVar2 & 0x1ff) * 2];
        puVar6 != &DAT_140014588 + (ulonglong)(uVar2 & 0x1ff) * 2; puVar6 = (undefined8 *)*puVar6) {
      if (*(int *)((longlong)puVar6 + -0xc) == param_1[0x51]) {
        plVar1 = (longlong *)(param_1 + 0x54);
        lVar3 = *plVar1;
        if ((*(longlong **)(lVar3 + 8) != plVar1) ||
           (plVar4 = *(longlong **)(param_1 + 0x56), (longlong *)*plVar4 != plVar1)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          uVar7 = (*pcVar5)();
          return uVar7;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        DereferenceRefCount(param_1);
        uVar7 = 0;
        break;
      }
    }
    KeReleaseSpinLock(&DAT_140016588,DAT_140016590);
  }
  return uVar7;
}



===== RemoveTunnelCbFromTunnelIdHashTable @ 140004820 =====

undefined8 RemoveTunnelCbFromTunnelIdHashTable(int *param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  uVar2 = param_1[0x2a];
  uVar7 = 0xc0000034;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f540,"RemoveTunnelCbFromTunnelIdHashTable:");
  }
  DAT_1400144c8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144c0);
  puVar6 = (undefined8 *)(&DAT_1400124c0)[(ulonglong)(uVar2 & 0x1ff) * 2];
  do {
    if (puVar6 == &DAT_1400124c0 + (ulonglong)(uVar2 & 0x1ff) * 2) {
LAB_1400048d3:
      KeReleaseSpinLock(&DAT_1400144c0,DAT_1400144c8);
      return uVar7;
    }
    if (puVar6[0x12] == *(longlong *)(param_1 + 0x2a)) {
      plVar1 = (longlong *)(param_1 + 6);
      lVar3 = *plVar1;
      if ((*(longlong **)(lVar3 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 8), (longlong *)*plVar4 != plVar1)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        uVar7 = (*pcVar5)();
        return uVar7;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      DereferenceRefCount(param_1);
      uVar7 = 0;
      goto LAB_1400048d3;
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== AgileVpnCleanUpWfpCallouts @ 14000490c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AgileVpnCleanUpWfpCallouts(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceError,&DAT_14000feb8,"Enter AgileVpnCleanUpWfpCallouts");
  }
  puVar5 = &DAT_140016858;
  iVar4 = KeWaitForSingleObject(&DAT_140016858,0,0,0,0);
  if (iVar4 == 0) {
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
    uVar3 = uRam0000000140016838;
    uVar2 = _DAT_140016830;
    uVar1 = WfpState;
    DAT_14001674c = 0;
    if ((DAT_140016748 & 4) != 0) {
      DAT_140016748 = DAT_140016748 & 0xfffffffb;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpmFilterDeleteById0(uVar1,uVar2);
      FwpmFilterDeleteById0(uVar1,uVar3);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      _DAT_140016830 = 0;
      uRam0000000140016838 = 0;
    }
    if ((DAT_140016748 & 2) != 0) {
      DAT_140016748 = DAT_140016748 & 0xfffffffd;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpiCalloutUnregisterAndDeleteByKey0(uVar1,&DAT_14000fed8);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
    }
    uVar3 = uRam0000000140016850;
    uVar2 = _DAT_140016848;
    if ((DAT_140016748 & 0x10) != 0) {
      DAT_140016748 = DAT_140016748 & 0xffffffef;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpmFilterDeleteById0(uVar1,uVar2);
      FwpmFilterDeleteById0(uVar1,uVar3);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      _DAT_140016848 = 0;
      uRam0000000140016850 = 0;
    }
    if ((DAT_140016748 & 8) != 0) {
      DAT_140016748 = DAT_140016748 & 0xfffffff7;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpiCalloutUnregisterAndDeleteByKey0(WfpState,&DAT_14000fec8);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
    }
    if ((char)DAT_140016748 < '\0') {
      DAT_140016748 = DAT_140016748 & 0xffffff7f;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpmSubLayerDeleteByKey0(uVar1,&SUBLAYER_KEY);
      FwpmProviderDeleteByKey0(uVar1,&PROVIDER_KEY);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
    }
    if ((DAT_140016748 & 1) != 0) {
      DAT_140016748 = DAT_140016748 & 0xfffffffe;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpmEngineClose0(uVar1);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      WfpState = 0;
    }
    uVar1 = DAT_140016750;
    if ((DAT_140016748 & 0x20) != 0) {
      DAT_140016748 = DAT_140016748 & 0xffffffdf;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpsInjectionHandleDestroy0(uVar1);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      DAT_140016750 = 0;
    }
    uVar1 = DAT_140016800;
    if ((DAT_140016748 & 0x40) != 0) {
      DAT_140016748 = DAT_140016748 & 0xffffffbf;
      KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
      FwpsInjectionHandleDestroy0(uVar1);
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      DAT_140016800 = 0;
    }
    KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
    puVar5 = &DAT_140016858;
    KeReleaseMutex(&DAT_140016858,0);
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "Exit AgileVpnCleanUpWfpCallouts";
    puVar6 = &RasAgileVpnTraceInfo;
  }
  else {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
      return;
    }
    pcVar7 = "Exit as KeWaitForMutexObject returned STATUS_ABANDONED_WAIT_0.";
    puVar6 = &RasAgileVpnTraceError;
  }
  McTemplateK0s_EtwWriteTransfer(puVar5,puVar6,&DAT_14000feb8,pcVar7);
  return;
}



===== IPsecDecryptCompleteCallback @ 140004d10 =====

void IPsecDecryptCompleteCallback(undefined8 param_1,undefined8 *param_2,int *param_3)

{
  if ((int)param_1 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (param_1,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                 "IPsecDecryptCompleteCallback: Packets will be droped-FwpsSignalIPsecDecryptCompleteIkeV2 fail:"
                 ,(char)param_1);
    }
  }
  else {
    *(undefined1 *)(param_3 + 0x50) = 0;
    ProcessRxPacket(param_3,param_2);
  }
  return;
}



===== ApplyQoSPoliciesOnTunnel @ 140004d64 =====

int ApplyQoSPoliciesOnTunnel(longlong param_1,uint *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 *_Dst;
  undefined8 uVar3;
  undefined *puVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong local_68 [8];
  
  iVar2 = 0;
  local_68[6] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_140010100,"ApplyQoSPoliciesOnTunnel called");
  }
  if ((*(longlong *)(param_1 + 0x130) == 0) && (*(longlong *)(param_1 + 0x138) == 0)) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_140014520);
    for (uVar6 = 0; (uint)uVar6 < *param_2; uVar6 = (ulonglong)((uint)uVar6 + 1)) {
      _Dst = BwcFindQoSPolicyFromPolicyIndex(param_2[uVar6 * 3 + 3]);
      if (_Dst == (undefined8 *)0x0) {
        puVar4 = &QoSPolicyList;
        _Dst = (undefined8 *)ExAllocateFromNPagedLookasideList();
        if (_Dst == (undefined8 *)0x0) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (puVar4,&RasAgileVpnTraceError,&DAT_140010100,
                       "ApplyQoSPoliciesOnTunnel: BwcAllocateQoSPolicy returned error");
          }
          iVar2 = -0x3fffff66;
          goto LAB_140004f6c;
        }
        local_68[uVar6] = (longlong)_Dst;
        memset(_Dst,0,0x50);
        *(undefined4 *)(_Dst + 3) = 0;
        _Dst[4] = BwcCleanupQoSPolicy;
        *(uint *)(_Dst + 1) = param_2[uVar6 * 3 + 2];
        *(uint *)((longlong)_Dst + 4) = param_2[uVar6 * 3 + 1];
        *(uint *)((longlong)_Dst + 0xc) = param_2[uVar6 * 3 + 3];
        KeInitializeSpinLock(_Dst + 5);
        *(undefined4 *)(_Dst + 7) = 0x70715641;
        LOCK();
        *(int *)(_Dst + 3) = *(int *)(_Dst + 3) + 1;
        UNLOCK();
        if (*(uint *)((longlong)_Dst + 4) != 0) {
          local_68[5] = 0;
          local_68[6] = 0;
          local_68[2] = 0;
          local_68[4] = (ulonglong)*(uint *)((longlong)_Dst + 4) << 10;
          iVar2 = BwcCreateFlow((longlong)(local_68 + 2),_Dst + 2);
          if (iVar2 < 0) goto LAB_140004f6c;
          *(undefined4 *)_Dst = 1;
        }
        uVar3 = BwcAddQoSPolicyToQoSPoliciesHashTable((longlong)_Dst);
        iVar2 = (int)uVar3;
      }
      else {
        LOCK();
        *(int *)(_Dst + 3) = *(int *)(_Dst + 3) + 1;
        UNLOCK();
        BwcDereferenceQoSPolicy((longlong)_Dst);
      }
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x38);
      *(undefined1 *)(param_1 + 0x40) = uVar1;
      if (param_2[uVar6 * 3 + 2] == 0) {
        *(undefined8 **)(param_1 + 0x130) = _Dst;
      }
      else if (param_2[uVar6 * 3 + 2] == 1) {
        *(undefined8 **)(param_1 + 0x138) = _Dst;
      }
      KeReleaseSpinLock(param_1 + 0x38);
    }
    if (iVar2 < 0) {
LAB_140004f6c:
      plVar5 = local_68;
      lVar7 = 2;
      do {
        if (*plVar5 != 0) {
          ExFreeToNPagedLookasideList(&QoSPolicyList);
        }
        plVar5 = plVar5 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    ExReleaseResourceLite(&DAT_140014520);
    KeLeaveCriticalRegion();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== DropNonConformantNbls @ 140004fe0 =====

void DropNonConformantNbls(undefined8 param_1,undefined8 *param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int *piVar4;
  
  if (param_2 != (undefined8 *)0x0) {
    do {
      puVar2 = (undefined8 *)*param_2;
      lVar3 = param_2[2];
      *param_2 = 0;
      uVar1 = *(ushort *)(lVar3 + 10);
      piVar4 = *(int **)((ulonglong)uVar1 + 0x10 + lVar3);
      DereferenceRefCount(piVar4);
      DereferenceRefCount(&DAT_140012248);
      NdisFreeNetBufferListContext(param_2,0x10);
      if (*(char *)((ulonglong)uVar1 + 0x18 + lVar3) == '\0') {
        NetioDereferenceNetBufferList(param_2,0);
        LOCK();
        piVar4[0x5a] = piVar4[0x5a] + 1;
        UNLOCK();
      }
      else {
        *(undefined4 *)(param_2[3] + 0x8c) = 0xc0000001;
        LOCK();
        piVar4[0x5b] = piVar4[0x5b] + 1;
        UNLOCK();
        NdisMCoSendNetBufferListsComplete(*(undefined8 *)(piVar4 + 0x12),param_2[3],0);
        NdisFreeCloneNetBufferList(param_2,0);
      }
      param_2 = puVar2;
    } while (puVar2 != (undefined8 *)0x0);
  }
  return;
}



===== HandleQoSOidRequest @ 1400050d0 =====

int HandleQoSOidRequest(uint *param_1,uint *param_2,uint param_3,undefined4 *param_4,
                       undefined4 *param_5)

{
  int iVar1;
  char *pcVar2;
  
  *param_5 = 0x1c;
  if ((param_3 < 0x1c) || (2 < *param_2)) {
    iVar1 = -0x3ffeffeb;
  }
  else {
    *param_4 = 0x1c;
    if (param_1 == (uint *)0x0) {
      iVar1 = UpdateQoSPolicies(param_2);
      if (iVar1 == 0) {
        return 0;
      }
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
        return iVar1;
      }
      pcVar2 = "HandleQoSOidRequest: UpdateQoSPolicies returned Error ";
    }
    else {
      iVar1 = ApplyQoSPoliciesOnTunnel((longlong)param_1,param_2);
      if (iVar1 == 0) {
        return 0;
      }
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
        return iVar1;
      }
      pcVar2 = "HandleQoSOidRequest: ApplyQoSPoliciesOnTunnel returned Error ";
      param_2 = param_1;
    }
    McTemplateK0sx_EtwWriteTransfer
              (param_2,&RasAgileVpnTraceIntArgError,&DAT_140010100,pcVar2,(char)iVar1);
  }
  return iVar1;
}



===== ProcessConformantNbls @ 140005170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessConformantNbls(undefined8 param_1,longlong *param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  
  if (param_2 != (longlong *)0x0) {
    do {
      plVar2 = (longlong *)*param_2;
      lVar3 = param_2[2];
      *param_2 = 0;
      piVar4 = *(int **)((ulonglong)*(ushort *)(lVar3 + 10) + 0x10 + lVar3);
      cVar1 = *(char *)((ulonglong)*(ushort *)(lVar3 + 10) + 0x18 + lVar3);
      NdisFreeNetBufferListContext(param_2,0x10);
      piVar7 = piVar4;
      uVar6 = AgileVpnCheckAdapterTunnelStates((longlong)piVar4,'\x01');
      if ((int)uVar6 == 0) {
        LOCK();
        *piVar4 = *piVar4 + 1;
        UNLOCK();
        LOCK();
        DAT_140012248 = DAT_140012248 + 1;
        UNLOCK();
        DereferenceRefCount(piVar4);
        DereferenceRefCount(&DAT_140012248);
        if (cVar1 == '\0') {
          iVar5 = FwpsSignalIPsecDecryptCompleteIkeV20(param_2,IPsecDecryptCompleteCallback,piVar4);
          if (iVar5 < 0) {
            *(undefined1 *)(piVar4 + 0x50) = 1;
            ProcessRxPacket(piVar4,param_2);
          }
          LOCK();
          _agileVpnUlPackReceivedPending = _agileVpnUlPackReceivedPending + 1;
          UNLOCK();
        }
        else {
          TransmitPacket((longlong)param_2,piVar4);
        }
      }
      else {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (piVar7,&RasAgileVpnTraceError,&DAT_140010100,
                     "ProcessConformantNbls: Packets will be droped as AgileVpnCheckAdapterTunnelStates failed"
                    );
        }
        if (cVar1 == '\0') {
          NetioDereferenceNetBufferList(param_2,0);
        }
        else {
          *(int *)(param_2[3] + 0x8c) = (int)uVar6;
          NdisMCoSendNetBufferListsComplete(*(undefined8 *)(piVar4 + 0x12),param_2[3],0);
          NdisFreeCloneNetBufferList(param_2,0);
        }
        DereferenceRefCount(piVar4);
        DereferenceRefCount(&DAT_140012248);
      }
      DereferenceRefCount(&DAT_140012248);
      param_2 = plVar2;
    } while (plVar2 != (longlong *)0x0);
  }
  return;
}



===== UpdateQoSPolicies @ 1400052f8 =====

int UpdateQoSPolicies(uint *param_1)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  
  iVar1 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_140010100,"UpdateQoSPolicies called");
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_140014520,1);
  uVar3 = 0;
  do {
    if (*param_1 <= (uint)uVar3) {
LAB_1400053bb:
      ExReleaseResourceLite(&DAT_140014520);
      KeLeaveCriticalRegion();
      return iVar1;
    }
    piVar2 = (int *)BwcFindQoSPolicyFromPolicyIndex(param_1[uVar3 * 3 + 3]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0;
      goto LAB_1400053bb;
    }
    iVar1 = BwcUpdateQoSPolicy(piVar2,param_1[uVar3 * 3 + 1]);
    BwcDereferenceQoSPolicy((longlong)piVar2);
    if (iVar1 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (piVar2,&RasAgileVpnTraceIntArgError,&DAT_140010100,
                   "UpdateQoSPolicies: BwcUpdateQoSPolicy returned error",(char)iVar1);
      }
      goto LAB_1400053bb;
    }
    uVar3 = (ulonglong)((uint)uVar3 + 1);
  } while( true );
}



===== McGenControlCallbackV2 @ 140005400 =====

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



===== McGenEventUnregister_EtwUnregister @ 140005510 =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== McTemplateK0sqssqqq_EtwWriteTransfer @ 140005544 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sqssqqq_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char *in_R9;
  undefined1 uStack0000000000000028;
  char *in_stack_00000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  char *local_88;
  int local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined8 local_70;
  char *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  lVar1 = -1;
  if (in_R9 == (char *)0x0) {
    local_80 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != '\0');
    local_80 = (int)lVar2 + 1;
  }
  local_7c = 0;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_70 = 4;
  local_78 = &uStack0000000000000028;
  if (in_stack_00000030 == (char *)0x0) {
    uVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    uVar3 = (ulonglong)((int)lVar2 + 1);
  }
  local_60 = (undefined4)uVar3;
  local_5c = 0;
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  if (in_stack_00000038 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_48 = &uStack0000000000000040;
  local_40 = 4;
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  local_38 = &uStack0000000000000048;
  local_28 = &uStack0000000000000050;
  local_30 = 4;
  local_20 = 4;
  local_88 = in_R9;
  local_68 = in_stack_00000030;
  local_58 = in_stack_00000038;
  McGenEventWrite_EtwWriteTransfer(uVar3,&RasAgileVpnTraceNBLDroppedError,&DAT_140010130,8,local_98)
  ;
  return;
}



===== RasAgileVpnTraceNBL @ 140005684 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RasAgileVpnTraceNBL(undefined8 *param_1,int param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_168 [32];
  int local_148;
  undefined1 *local_140;
  undefined1 *local_138;
  uint local_130;
  uint local_128;
  uint local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  uint local_f0;
  char local_e8 [32];
  undefined1 local_c8 [80];
  undefined1 local_78 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  local_f8 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    while (param_1 != (undefined8 *)0x0) {
      puVar3 = (ulonglong *)param_1[1];
      param_1 = (undefined8 *)*param_1;
      iVar4 = 0;
      uVar1 = GetPacketInfoFromNetBuffer((ulonglong)puVar3,(short *)&local_118);
      if (-1 < (int)uVar1) {
        for (; puVar3 != (ulonglong *)0x0; puVar3 = (ulonglong *)*puVar3) {
          iVar4 = iVar4 + 1;
        }
        GetStringFromAddr((longlong)&local_118 + 4,(short)local_118,local_78);
        uVar2 = local_118 & 0xffff;
        GetStringFromAddr((longlong)&local_108 + 4,(short)local_118,local_c8);
        if (param_2 == 1) {
          pcVar5 = "Qos";
        }
        else if (param_2 == 2) {
          pcVar5 = "TS Mismatch";
        }
        else {
          pcVar5 = "Unknown";
        }
        RtlStringCchCopyA(local_e8,uVar2,(longlong)pcVar5);
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          local_120 = local_f0 & 0xff;
          local_138 = local_c8;
          local_128 = (uint)local_f8._6_2_;
          local_130 = (uint)local_f8._4_2_;
          local_140 = local_78;
          local_148 = iVar4;
          McTemplateK0sqssqqq_EtwWriteTransfer();
        }
      }
    }
  }
  return;
}



===== RasAgileVpnUnRegisterEtw @ 1400057dc =====

void RasAgileVpnUnRegisterEtw(void)

{
  if (MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context != 0) {
    EtwUnregister(Microsoft_Windows_Networking_CorrelationHandle);
    Microsoft_Windows_Networking_CorrelationHandle = 0;
    McGenEventUnregister_EtwUnregister(&MICROSOFT_WINDOWS_RAS_AGILEVPN_PROVIDER_Context);
  }
  return;
}



===== RtlStringCchCopyA @ 140005820 =====

uint RtlStringCchCopyA(char *param_1,undefined8 param_2,longlong param_3)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = 0x19;
  lVar3 = param_3 - (longlong)param_1;
  do {
    if ((lVar2 == -0x7fffffe5) || (param_1[lVar3] == '\0')) break;
    *param_1 = param_1[lVar3];
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  pcVar1 = param_1 + -1;
  if (lVar2 != 0) {
    pcVar1 = param_1;
  }
  *pcVar1 = '\0';
  return ~-(uint)(lVar2 != 0) & 0x80000005;
}



===== BwcCleanupFlow @ 14000586c =====

void BwcCleanupFlow(uint *param_1)

{
  BwcUninitializeFlow(param_1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BwcCompleteNbls @ 140005898 =====

void BwcCompleteNbls(longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined8 *local_res20;
  undefined8 *local_38;
  undefined8 **local_30;
  
  local_res20 = (undefined8 *)0x0;
  local_res8 = 0;
  local_resa = 0;
  puVar7 = param_4;
  uVar4 = KeGetCurrentProcessorNumberEx(0);
  if (param_1 != 0) {
    if (param_2 == (undefined8 *)0x0) {
      param_2 = BwcVirtualLine;
    }
    puVar1 = param_2 + 1;
    uVar6 = QosLineNeedSignal((longlong)puVar1,uVar4);
    if ((char)uVar6 != '\0') {
      NdisAcquireRWLockWrite(*param_2,&local_res8,1);
      QosLineSignalExternalEvent((longlong)puVar1,uVar4);
      NdisReleaseRWLock(*param_2,&local_res8);
    }
    iVar5 = QosGetNblChainDataLength(param_3);
    LOCK();
    *(int *)(param_2 + 0x12) = *(int *)(param_2 + 0x12) + iVar5;
    UNLOCK();
    local_30 = &local_res20;
    puVar3 = param_3;
    param_3 = local_res20;
    while (puVar3 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar3;
      local_38 = (undefined8 *)0x0;
      *puVar3 = 0;
      local_res20 = param_3;
      QosTbcSendNetBufferListComplete
                (param_1 + 0x28,(longlong)puVar1,(longlong)puVar3,puVar7,(longlong *)&local_38);
      puVar3 = puVar2;
      param_3 = local_res20;
      if (local_38 != (undefined8 *)0x0) {
        BwcNblAppendNblsMoveLast(&local_30,local_38);
        param_3 = local_res20;
      }
    }
  }
  *param_4 = param_3;
  return;
}



===== BwcCreateFlow @ 1400059b8 =====

int BwcCreateFlow(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = (uint *)ExAllocatePool2(0x40,0x1f0,0x6d637742);
  if (puVar4 == (uint *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    puVar4[0x7a] = 2;
    LOCK();
    UNLOCK();
    uVar1 = (ulonglong)BwcNumberOfProcessors;
    uVar2 = (ulonglong)BwcTimerUnitAssignmentIndex;
    BwcTimerUnitAssignmentIndex = BwcTimerUnitAssignmentIndex + 1;
    *puVar4 = (uint)(uVar2 % uVar1);
    RtlInitializeTimerWheelEntry
              (*(undefined8 *)((uVar2 % uVar1) * 0xc0 + 0xa0 + BwcTimerUnits),puVar4 + 2,0,0);
    puVar4[0x74] = 0;
    KeInitializeSpinLock(puVar4 + 0x76);
    memset(puVar4 + 10,0,0x1a8);
    QosTbcFlowInitialize((longlong)(puVar4 + 10));
    iVar3 = BwcUpdateFlow(param_1,(longlong)puVar4);
    if (iVar3 < 0) {
      BwcUninitializeFlow(puVar4);
      ExFreePoolWithTag(puVar4,0);
      puVar4 = (uint *)0x0;
    }
    *param_2 = puVar4;
  }
  return iVar3;
}



===== BwcCreateLine @ 140005ae0 =====

undefined8 BwcCreateLine(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong lVar3;
  
  BwcVirtualLine = (longlong *)0x0;
  plVar2 = (longlong *)ExAllocatePool2(0x40,0x118);
  if (plVar2 != (longlong *)0x0) {
    *(undefined4 *)(plVar2 + 0x22) = 1;
    QosLineCreate(plVar2 + 1,param_2,-1);
    uVar1 = BwcMiniportHandle;
    plVar2[0x1f] = -1;
    plVar2[0x1e] = 0x28f5c28f5c28f5b;
    *(undefined4 *)(plVar2 + 0x1c) = 1;
    lVar3 = NdisAllocateRWLock(uVar1);
    *plVar2 = lVar3;
    if (lVar3 != 0) {
      *(undefined4 *)(plVar2 + 0x1c) = 2;
      BwcVirtualLine = plVar2;
      return 0;
    }
    BwcLineDereference(plVar2);
  }
  return 0xc000009a;
}



===== BwcDeinit @ 140005bb0 =====

void BwcDeinit(ulonglong param_1)

{
  QosTerminate();
  if (BwcVirtualLine != 0) {
    BwcDeleteLine(param_1);
    BwcVirtualLine = 0;
  }
  if (BwcDelayQueue != 0) {
    ExFreePoolWithTag(BwcDelayQueue,0x6d637742);
    BwcDelayQueue = 0;
  }
  BwcStopTimerWheel();
  if (BwcSendNblPoolHandle != 0) {
    NdisFreeNetBufferListPool();
    BwcSendNblPoolHandle = 0;
  }
  if (BwcNblLookasideListInitialized != '\0') {
    ExDeleteNPagedLookasideList(&BwcNblLookasideList);
    BwcNblLookasideListInitialized = '\0';
  }
  if (BwcGenericObjectHandle != 0) {
    NdisFreeGenericObject();
    BwcGenericObjectHandle = 0;
  }
  if (BwcQoSPolicylLookasideListInitialized != '\0') {
    ExDeleteNPagedLookasideList(&QoSPolicyList);
  }
  return;
}



===== BwcDeleteFlow @ 140005c88 =====

void BwcDeleteFlow(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined2 local_res8;
  undefined1 local_resa;
  uint local_28 [3];
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar3 = BwcVirtualLine;
  local_10 = 1;
  local_res8 = 0;
  local_resa = 0;
  uVar2 = param_1[0x5a];
  local_18 = 0;
  if (uVar2 - 1 < 10000) {
    local_1c = 0xffffffff;
    local_28[2] = -uVar2;
    local_28[1] = 0;
    local_28[0] = uVar2;
    NdisAcquireRWLockWrite(*BwcVirtualLine);
    QosLineUpdate(puVar3 + 1,(undefined8 *)0x0,0,local_28);
    NdisReleaseRWLock(*puVar3,&local_res8);
  }
  LOCK();
  puVar1 = param_1 + 0x7a;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  if (uVar2 == 2) {
    BwcCleanupFlow(param_1);
  }
  return;
}



===== BwcDeleteLine @ 140005d48 =====

void BwcDeleteLine(ulonglong param_1)

{
  longlong *plVar1;
  ulonglong local_res8 [4];
  
  plVar1 = BwcVirtualLine;
  local_res8[0] = param_1 & 0xffffffffff000000;
  NdisAcquireRWLockWrite(*BwcVirtualLine,local_res8,0);
  if ((int)plVar1[0x1c] == 2) {
    *(undefined4 *)(plVar1 + 0x1c) = 0;
    *(uint *)(plVar1 + 0x1b) = *(uint *)(plVar1 + 0x1b) | 1;
  }
  else {
    if ((int)plVar1[0x1c] == 0) {
      NdisReleaseRWLock(*plVar1,local_res8);
      return;
    }
    *(undefined4 *)(plVar1 + 0x1c) = 0;
  }
  NdisReleaseRWLock(*plVar1,local_res8);
  BwcLineDereference(plVar1);
  return;
}



===== BwcDereferenceFlow @ 140005de0 =====

void BwcDereferenceFlow(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  LOCK();
  puVar1 = param_1 + 0x7a;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 2;
  UNLOCK();
  if (uVar2 == 3) {
    BwcCleanupFlow(param_1);
  }
  return;
}



===== BwcDropNbls @ 140005e08 =====

void BwcDropNbls(longlong param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *local_res10;
  undefined8 local_res18;
  undefined8 *local_res20;
  
  local_res20 = &local_res18;
  local_res18 = 0;
  *param_4 = 0;
  if (param_2 == 0) {
    param_2 = BwcVirtualLine;
  }
  uVar2 = 0;
  if (param_3 != (undefined8 *)0x0) {
    puVar3 = param_4;
    do {
      puVar1 = (undefined8 *)*param_3;
      local_res10 = (undefined8 *)0x0;
      *param_3 = 0;
      QosTbcSendNetBufferListComplete
                (param_1 + 0x28,param_2 + 8,(longlong)param_3,puVar3,(longlong *)&local_res10);
      if (local_res10 != (undefined8 *)0x0) {
        BwcNblAppendNblsMoveLast(&local_res20,local_res10);
      }
      param_3 = puVar1;
    } while (puVar1 != (undefined8 *)0x0);
    uVar2 = local_res18;
  }
  *param_4 = uVar2;
  return;
}



===== BwcFlowDelay @ 140005e98 =====

void BwcFlowDelay(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = (ulonglong)param_2;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(uint *)(param_1 + 0x1ec) & 4) == 0) {
    uVar1 = RoReferenceEx((uint *)(param_1 + 0x1e8));
    if ((char)uVar1 != '\0') {
      *(uint *)(param_1 + 0x1ec) = *(uint *)(param_1 + 0x1ec) | 4;
      lVar3 = BwcDelayQueue;
      puVar4 = (undefined8 *)(param_1 + 0x20);
      lVar2 = (uVar5 & 0xffffffff) * 0x40;
      *puVar4 = 0;
      if (*(longlong *)(lVar2 + lVar3) == 0) {
        *(undefined8 **)(lVar2 + lVar3) = puVar4;
      }
      else {
        **(undefined8 **)(lVar2 + 8 + lVar3) = puVar4;
      }
      *(undefined8 **)(lVar2 + 8 + lVar3) = puVar4;
      if (*(int *)(lVar2 + 0x10 + lVar3) == 0) {
        uVar1 = QosTimerGetCurrentTime((uint)uVar5,'\0','\x01');
        lVar3 = (uVar5 & 0xffffffff) * 0xc0 + BwcTimerUnits;
        RtlAcquireWriteLockAtDpcLevel(lVar3);
        BwcSetTimer(lVar3,uVar1,uVar1 + 0xfa);
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
      }
    }
  }
  return;
}



===== BwcFlushDelay @ 140005f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BwcFlushDelay(uint param_1,undefined8 param_2,undefined8 param_3,ulonglong *param_4)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined2 *puVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined2 local_res8;
  undefined1 local_resa;
  ulonglong local_res10;
  undefined8 *local_res18;
  undefined8 *local_res20;
  ulonglong local_98;
  undefined8 *local_90;
  undefined8 *local_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  
  local_88 = (undefined8 *)0x0;
  local_58 = 0;
  puVar9 = (undefined8 *)0x0;
  local_res8 = 0;
  uVar10 = 0;
  local_resa = 0;
  puVar5 = (undefined8 *)((ulonglong)param_1 * 0x40 + BwcDelayQueue);
  local_78 = 0;
  uStack_70 = 0;
  local_98 = 0;
  local_68 = 0;
  uStack_60 = 0;
  puVar3 = (undefined8 *)*puVar5;
  *puVar5 = 0;
  puVar5[1] = 0;
  local_80 = QosTimerGetCurrentTime(param_1,'\0','\x01');
  while (puVar3 != (undefined8 *)0x0) {
    puVar5 = (undefined8 *)*puVar3;
    puVar1 = (uint *)(puVar3 + -4);
    local_90 = puVar5;
    uVar4 = KeAcquireSpinLockRaiseToDpc();
    *(uint *)((longlong)puVar3 + 0x1cc) = *(uint *)((longlong)puVar3 + 0x1cc) & 0xfffffffb;
    *(undefined1 *)(puVar3 + 0x38) = uVar4;
    local_res18 = (undefined8 *)0x0;
    local_res20 = (undefined8 *)0x0;
    local_res10 = local_res10 & 0xffffffff00000000;
    if ((*(byte *)(puVar3 + 0x39) & 1) == 0) {
      puVar5 = puVar3 + 1;
      if (*(int *)(puVar3 + 0x36) == 0) {
        puVar9 = BwcVirtualLine;
      }
      uVar6 = QosFlowNeedQueueFeedback((longlong)puVar5,local_80,&local_78);
      if (((char)uVar6 != '\0') && (puVar9 != (undefined8 *)0x0)) {
        NdisAcquireRWLockWrite(*puVar9,&local_res8,0);
        puVar2 = puVar9 + 1;
        uVar6 = (ulonglong)param_1;
        uVar7 = QosLineNeedSignal((longlong)puVar2,param_1);
        if ((char)uVar7 != '\0') {
          uVar6 = (ulonglong)param_1;
          QosLineSignalExternalEvent((longlong)puVar2,param_1);
        }
        QosLineQueryQueueFeedback((longlong)puVar2,uVar6,(uint *)&local_78);
        NdisReleaseRWLock(*puVar9,&local_res8);
        QosTbcAdjustSendWindow((longlong)puVar5,(longlong)&local_78);
      }
      param_4 = &local_res10;
      QosFlowProcessQueuedNetBufferLists((longlong)puVar5,param_1);
      if (local_res20 != (undefined8 *)0x0) {
        param_4 = &local_98;
        BwcDropNbls((longlong)puVar1,(longlong)puVar9,local_res20,param_4);
        uVar10 = local_98;
      }
      puVar5 = local_90;
    }
    puVar2 = local_res18;
    KeReleaseSpinLock(puVar3 + 0x37,*(undefined1 *)(puVar3 + 0x38));
    if (uVar10 != 0) {
      (*DropQueuedNonConformantNbls)(puVar1,uVar10);
    }
    if (puVar2 != (undefined8 *)0x0) {
      puVar3 = puVar9 + 1;
      puVar8 = (undefined2 *)(ulonglong)param_1;
      uVar7 = QosLineNeedSignal((longlong)puVar3,param_1);
      if ((char)uVar7 != '\0') {
        NdisAcquireRWLockWrite(*puVar9,&local_res8,1);
        QosLineSignalExternalEvent((longlong)puVar3,param_1);
        puVar8 = &local_res8;
        NdisReleaseRWLock(*puVar9);
      }
      QosLineSendNetBufferLists((longlong)puVar3,puVar8,puVar2,param_4,&local_88,&local_res20);
      param_4 = &local_res10;
      local_res10 = 0;
      BwcCompleteNbls((longlong)puVar1,puVar9,local_88,param_4);
      if (local_res10 != 0) {
        BwcSendProcessedNbls();
      }
    }
    BwcDereferenceFlow(puVar1);
    puVar3 = puVar5;
  }
  return;
}



===== BwcGetQoSParameters @ 1400061f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BwcGetQoSParameters(ulonglong param_1,ulonglong *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ushort *puVar5;
  ushort uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 *local_c0;
  undefined4 local_b8 [2];
  longlong local_b0 [5];
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  longlong *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_e8;
  local_b8[0] = 0;
  local_b0[0] = 0;
  local_84 = 0;
  local_6c = 0;
  local_48 = 0;
  lVar2 = 0;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  local_58 = 0;
  uStack_50 = 0;
  RtlInitUnicodeString
            (local_b0 + 3,
             L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\RemoteAccess\\Parameters");
  local_80 = 0;
  local_88 = 0x30;
  local_78 = local_b0 + 3;
  local_70 = 0x240;
  local_68 = 0;
  uStack_60 = 0;
  iVar1 = ZwOpenKey(local_b0,0x20019,&local_88);
  if (iVar1 < 0) goto LAB_140006446;
  RtlInitUnicodeString(local_b0 + 1,L"QosTokenSizeFactor");
  local_c0 = local_b8;
  local_c8 = 0x18;
  iVar1 = ZwQueryValueKey(local_b0[0],local_b0 + 1,2,&local_58);
  if (iVar1 < 0) {
LAB_14000630d:
    *param_3 = 4;
  }
  else {
    *param_3 = uStack_50._4_4_;
    if (uStack_50._4_4_ == 0) goto LAB_14000630d;
    if (0x14 < uStack_50._4_4_) {
      *param_3 = 0x14;
    }
  }
  RtlInitUnicodeString(local_b0 + 1,L"QosPeakRateFactor");
  local_c0 = local_b8;
  local_c8 = 0x18;
  iVar1 = ZwQueryValueKey(local_b0[0],local_b0 + 1,2,&local_58);
  if (iVar1 < 0) {
LAB_140006375:
    *param_4 = 4;
  }
  else {
    *param_4 = uStack_50._4_4_;
    if (uStack_50._4_4_ == 0) goto LAB_140006375;
    if (0x14 < uStack_50._4_4_) {
      *param_4 = 0x14;
    }
  }
  RtlInitUnicodeString(local_b0 + 1,L"QosQueueLengths");
  local_c0 = local_b8;
  local_c8 = 0;
  iVar1 = ZwQueryValueKey(local_b0[0],local_b0 + 1,1);
  if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
    lVar2 = ExAllocatePool2(0x40,local_b8[0],0x6d637742);
    if (lVar2 != 0) {
      local_c0 = local_b8;
      local_c8 = local_b8[0];
      iVar1 = ZwQueryValueKey(local_b0[0],local_b0 + 1,2,lVar2);
      if (-1 < iVar1) {
        puVar5 = (ushort *)(lVar2 + 0xc);
        uVar7 = 0;
        uVar8 = 0;
        do {
          uVar4 = 0;
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (puVar5[lVar3] != 0);
          if ((int)lVar3 == 0) break;
          for (; uVar6 = *puVar5, uVar6 != 0; puVar5 = puVar5 + 1) {
            if (uVar6 == 0x2d) {
              uVar8 = uVar4;
LAB_1400064c1:
              puVar5 = puVar5 + 1;
              uVar4 = 0;
              uVar6 = *puVar5;
            }
            else if (uVar6 == 0x3a) {
              uVar7 = uVar4;
              goto LAB_1400064c1;
            }
            if (9 < (ushort)(uVar6 - 0x30)) break;
            uVar4 = (ulonglong)uVar6 + (uVar4 * 5 + -0x18) * 2;
          }
          if ((uVar8 <= param_1) && (param_1 <= uVar7)) goto LAB_140006459;
          puVar5 = puVar5 + 1;
        } while( true );
      }
    }
  }
LAB_140006446:
  uVar4 = 250000;
  if (0x1400 < param_1) {
    uVar4 = 0x1e848;
  }
LAB_140006459:
  *param_2 = uVar4;
  if (local_b0[0] != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0x6d637742);
  }
  return 0;
}



===== BwcIndicateDelayQueueConsumerEnd @ 140006518 =====

void BwcIndicateDelayQueueConsumerEnd
               (uint param_1,undefined8 param_2,undefined8 param_3,ulonglong *param_4)

{
  int *piVar1;
  
  piVar1 = (int *)((ulonglong)param_1 * 0x40 + BwcDelayQueue + 0x10);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    BwcFlushDelay(param_1,param_2,param_3,param_4);
  }
  return;
}



===== BwcInit @ 140006540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BwcInit(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined4 local_40;
  undefined2 local_38;
  undefined4 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0xc000000d;
  }
  ProcessQueuedConformantNbls = ProcessConformantNbls;
  local_38 = 0;
  local_40 = 0x6d637742;
  DropQueuedNonConformantNbls = DropNonConformantNbls;
  local_48 = 0x38;
  BwcMiniportHandle = param_1;
  BwcDriverObject = param_2;
  ExInitializeNPagedLookasideList(&BwcNblLookasideList,0,0,0x200);
  BwcNblLookasideListInitialized = 1;
  uVar1 = KeQueryMaximumProcessorCountEx(0xffff);
  uVar3 = 0x40;
  BwcDelayQueue = ExAllocatePool2(0x40,(ulonglong)uVar1 << 6,0x6d637742);
  if (BwcDelayQueue == 0) {
    uVar6 = 0xc0000017;
  }
  else {
    uVar2 = BwcStartTimerWheel();
    uVar6 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar2 = QosInit();
      uVar6 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        BwcNblContextSize = (undefined2)local_28;
        uVar3 = NdisAllocateGenericObject(BwcDriverObject,0x6d637742,0);
        BwcGenericObjectHandle = uVar3;
        if (uVar3 != 0) {
          uStack_18 = 0x62737742;
          local_20 = CONCAT26(BwcNblContextSize,0x100180);
          BwcSendNblPoolHandle = NdisAllocateNetBufferListPool(uVar3,&local_20);
          if (BwcSendNblPoolHandle != 0) {
            uVar2 = BwcCreateLine(uVar3,0);
            uVar6 = uVar2 & 0xffffffff;
            NdisGetVersion();
            local_38 = 0;
            local_40 = 0x70717742;
            local_48 = 0x50;
            ExInitializeNPagedLookasideList(&QoSPolicyList,0,0,0x200);
            BwcQoSPolicylLookasideListInitialized = 1;
            NdisInitializeReadWriteLock(&QoSPoliciesHashTableRWLock);
            puVar4 = &QoSPoliciesHashListHead;
            lVar5 = 0x20;
            do {
              puVar4[1] = puVar4;
              *puVar4 = puVar4;
              puVar4 = puVar4 + 2;
              lVar5 = lVar5 + -1;
            } while (lVar5 != 0);
            uVar3 = 0;
            if (-1 < (int)uVar2) {
              return uVar6;
            }
            goto LAB_140006746;
          }
        }
        uVar6 = 0xc000009a;
      }
    }
  }
LAB_140006746:
  BwcDeinit(uVar3);
  return uVar6;
}



===== BwcLineDereference @ 140006780 =====

int BwcLineDereference(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
  LOCK();
  plVar1 = param_1 + 0x22;
  lVar2 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  iVar3 = (int)lVar2 + -1;
  if (iVar3 == 0) {
    if (*param_1 != 0) {
      NdisFreeRWLock();
    }
    ExFreePoolWithTag(param_1,0x6d637742);
  }
  return iVar3;
}



===== BwcNblAppendNblsMoveLast @ 1400067dc =====

void BwcNblAppendNblsMoveLast(undefined8 *param_1,undefined8 *param_2)

{
  *(undefined8 **)*param_1 = param_2;
  for (; param_2 != (undefined8 *)0x0; param_2 = (undefined8 *)*param_2) {
    *param_1 = param_2;
  }
  return;
}



===== BwcSendNbls @ 1400067f8 =====

void BwcSendNbls(uint *param_1,undefined8 *param_2,undefined8 param_3,longlong *param_4,
                undefined8 *param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined1 auVar4 [16];
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 uVar7;
  char cVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong lVar13;
  undefined2 *puVar14;
  uint uVar15;
  undefined8 *local_res8;
  undefined8 *local_res10;
  undefined2 local_res18;
  undefined1 local_res1a;
  longlong *local_res20;
  undefined8 **in_stack_ffffffffffffff08;
  uint *local_d8;
  undefined8 *local_d0;
  undefined8 *local_c8;
  longlong *local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  longlong local_a8;
  longlong local_a0;
  undefined8 **local_98;
  uint local_90 [10];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  puVar5 = BwcVirtualLine;
  local_res10 = (undefined8 *)0x0;
  local_90[8] = 0;
  local_58 = 0;
  local_res18 = 0;
  local_res1a = 0;
  local_c0 = &local_a8;
  local_res8 = (undefined8 *)0x0;
  local_98 = &local_b8;
  local_d0 = (undefined8 *)0x0;
  local_90[0] = 0;
  local_90[1] = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_c8 = (undefined8 *)0x0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[6] = 0;
  local_90[7] = 0;
  local_a8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_b8 = (undefined8 *)0x0;
  local_d8 = (uint *)0x0;
  local_b0 = 0;
  local_res20 = param_4;
  uVar9 = KeGetCurrentProcessorNumberEx(0);
  if (param_1 == (uint *)0x0) {
    BwcNblAppendNblsMoveLast(&local_c0,param_2);
  }
  else {
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x76);
    *(undefined1 *)(param_1 + 0x78) = uVar7;
    if (param_2 != (undefined8 *)0x0) {
      puVar1 = puVar5 + 1;
      do {
        local_res10 = (undefined8 *)0x0;
        local_res8 = (undefined8 *)0x0;
        puVar2 = (undefined8 *)*param_2;
        *param_2 = 0;
        uVar10 = QosTimerGetCurrentTime(uVar9,'\x01','\x01');
        if ((((param_1 != local_d8) && (local_d8 = param_1, *param_1 != uVar9)) &&
            (puVar3 = *(uint **)(param_1 + 0x22), puVar3 != param_1 + 0x22)) &&
           ((longlong)(*(longlong *)(puVar3 + 6) - uVar10) < 1)) {
          BwcFlowDelay((longlong)param_1,uVar9);
        }
        uVar11 = QosFlowNeedQueueFeedback((longlong)(param_1 + 10),uVar10,(undefined8 *)local_90);
        if ((char)uVar11 != '\0') {
          NdisAcquireRWLockWrite(*puVar5,&local_res18,0);
          uVar11 = (ulonglong)uVar9;
          uVar12 = QosLineNeedSignal((longlong)puVar1,uVar9);
          if ((char)uVar12 != '\0') {
            uVar11 = (ulonglong)uVar9;
            QosLineSignalExternalEvent((longlong)puVar1,uVar9);
          }
          QosLineQueryQueueFeedback((longlong)puVar1,uVar11,local_90);
          NdisReleaseRWLock(*puVar5,&local_res18);
          QosTbcAdjustSendWindow((longlong)(param_1 + 10),(longlong)local_90);
        }
        cVar8 = QosFlowSendNetBufferLists
                          (param_1 + 10,uVar9,puVar1,(ulonglong)param_2,
                           (int)in_stack_ffffffffffffff08,(ulonglong *)&local_res10,
                           (longlong *)&local_res8);
        if (cVar8 != '\0') {
          local_a0 = (ulonglong)*param_1 * 0xc0 + BwcTimerUnits;
          uVar11 = *(ulonglong *)(*(longlong *)(param_1 + 0x22) + 0x18);
          RtlAcquireWriteLockAtDpcLevel(local_a0);
          lVar6 = local_a0;
          BwcSetTimer(local_a0,uVar10,uVar11);
          puVar3 = param_1 + 2;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar11;
          lVar13 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar4,8);
          uVar15 = (uint)((uVar11 - lVar13 >> 1) + lVar13 >> 7);
          if ((param_1[7] == 0) || ((int)(uVar15 - param_1[7]) < 0)) {
            if (uVar15 == 0) {
              uVar15 = 1;
            }
            param_1[7] = uVar15;
            if (*(uint **)puVar3 == puVar3) {
              LOCK();
              param_1[0x7a] = param_1[0x7a] + 2;
              UNLOCK();
            }
            RtlIndicateTimerWheelEntryTimerStart(*(undefined8 *)(lVar6 + 0xa0),puVar3);
          }
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_68);
        }
        if (local_res8 != (undefined8 *)0x0) {
          BwcNblAppendNblsMoveLast(&local_98,local_res8);
        }
        if (local_res10 != (undefined8 *)0x0) {
          puVar14 = (undefined2 *)(ulonglong)uVar9;
          uVar12 = QosLineNeedSignal((longlong)puVar1,uVar9);
          if ((char)uVar12 != '\0') {
            NdisAcquireRWLockWrite(*puVar5,&local_res18,1);
            QosLineSignalExternalEvent((longlong)puVar1,uVar9);
            puVar14 = &local_res18;
            NdisReleaseRWLock(*puVar5);
          }
          in_stack_ffffffffffffff08 = &local_d0;
          QosLineSendNetBufferLists
                    ((longlong)puVar1,puVar14,local_res10,param_2,in_stack_ffffffffffffff08,
                     &local_res8);
          if (param_1[0x74] == 0) {
            BwcCompleteNbls((longlong)param_1,puVar5,local_d0,&local_c8);
            BwcNblAppendNblsMoveLast(&local_c0,local_c8);
          }
        }
        param_2 = puVar2;
      } while (puVar2 != (undefined8 *)0x0);
    }
    if (local_b8 != (undefined8 *)0x0) {
      BwcDropNbls((longlong)param_1,(longlong)puVar5,local_b8,&local_b0);
    }
    KeReleaseSpinLock(param_1 + 0x76,(char)param_1[0x78]);
    param_4 = local_res20;
  }
  *param_5 = local_b0;
  if (local_a8 != 0) {
    *param_4 = local_a8;
  }
  return;
}



===== BwcSendProcessedNbls @ 140006b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BwcSendProcessedNbls(void)

{
  (*ProcessQueuedConformantNbls)();
  return;
}



===== BwcSetTimer @ 140006ba4 =====

void BwcSetTimer(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  undefined1 auVar1 [16];
  char cVar2;
  longlong lVar3;
  
  if ((((*(uint *)(param_1 + 0xac) & 1) != 0) ||
      ((longlong)(*(longlong *)(param_1 + 0x18) - param_2) < 1)) ||
     ((longlong)(param_3 - *(longlong *)(param_1 + 0x18)) < 0)) {
    if (param_2 < param_3) {
      lVar3 = (param_2 - param_3) * 10;
    }
    else {
      lVar3 = 0;
    }
    *(ulonglong *)(param_1 + 0x18) = param_3;
    *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) & 0xfffffffe;
    KeSetTimerEx(param_1 + 0x60,lVar3,0,param_1 + 0x20);
  }
  cVar2 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_1 + 0xa0));
  if (cVar2 != '\0') {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_2;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
    RtlResumeTimerWheel(*(undefined8 *)(param_1 + 0xa0),lVar3 + (param_2 - lVar3 >> 1) >> 7);
  }
  return;
}



===== BwcStartTimerWheel @ 140006c68 =====

ulonglong BwcStartTimerWheel(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  BwcNumberOfProcessors = KeQueryActiveProcessorCountEx(0xffff);
  BwcTimerUnitAssignmentIndex = 0;
  BwcTimerUnits = 0;
  BwcTimerTable = ExAllocatePool2(0x40,(ulonglong)BwcNumberOfProcessors << 7,0x6d637742);
  if (BwcTimerTable == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    BwcTimerUnits = 0;
    DAT_140016f98 = BwcNumberOfProcessors;
    uVar1 = BwcCreateTimerUnits();
    uVar2 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      return uVar2;
    }
  }
  if (BwcTimerTable != 0) {
    ExFreePoolWithTag(BwcTimerTable,0x6d637742);
    BwcTimerTable = 0;
  }
  return uVar2;
}



===== BwcStopTimerWheel @ 140006d18 =====

void BwcStopTimerWheel(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (BwcTimerUnits != 0) {
    uVar2 = 0;
    if (BwcNumberOfProcessors != 0) {
      do {
        BwcUninitializeTimerUnit(uVar2 * 0xc0 + BwcTimerUnits);
        uVar1 = (int)uVar2 + 1;
        uVar2 = (ulonglong)uVar1;
      } while (uVar1 < BwcNumberOfProcessors);
    }
    ExFreePoolWithTag(BwcTimerUnits,0x61747742);
    BwcTimerUnits = 0;
  }
  if (BwcTimerTable != 0) {
    ExFreePoolWithTag(BwcTimerTable,0x6d637742);
    BwcTimerTable = 0;
  }
  return;
}



===== BwcTimeoutHandler @ 140006db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BwcTimeoutHandler(undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong *param_4)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined8 *puVar6;
  char cVar7;
  undefined1 uVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  int iVar15;
  longlong lVar16;
  undefined2 *puVar17;
  int iVar18;
  undefined8 *puVar19;
  ulonglong uVar20;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined4 local_b8 [2];
  undefined8 *local_b0;
  ulonglong local_a8;
  ulonglong local_a0;
  undefined8 *local_98;
  undefined8 *local_90;
  ulonglong local_88;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  uint local_50 [10];
  
  local_50[8] = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_68 = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res10 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_res12 = 0;
  uVar10 = KeGetCurrentProcessorNumberEx(0);
  puVar19 = (undefined8 *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  puVar12 = (undefined8 *)QosTimerGetCurrentTime(uVar10,'\x01','\x01');
  auVar4._8_8_ = 0;
  auVar4._0_8_ = puVar12;
  lVar16 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar4,8);
  local_98 = (undefined8 *)0x0;
  uVar20 = ((ulonglong)((longlong)puVar12 - lVar16) >> 1) + lVar16 >> 7;
  puVar13 = &local_78;
  local_b0 = (undefined8 *)0x0;
  piVar2 = (int *)((longlong)(ulonglong)uVar10 * 0x40 + 0x10 + BwcDelayQueue);
  *piVar2 = *piVar2 + 1;
  local_90 = (undefined8 *)0x0;
  local_a0 = 0;
  local_b8[0] = 0;
  local_a8 = uVar20;
  local_80 = puVar12;
  RtlAcquireWriteLockAtDpcLevel(param_2);
  uVar3 = *(uint *)(param_2 + 0xac);
  *(undefined8 **)(param_2 + 0x10) = puVar12;
  *(uint *)(param_2 + 0xac) = (~(uVar3 >> 1) ^ uVar3) & 1 ^ uVar3;
  cVar7 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_2 + 0xa0));
  if (cVar7 == '\0') {
    RtlUpdateCurrentTimerWheelTick(*(undefined8 *)(param_2 + 0xa0),uVar20 & 0xffffffff);
    puVar13 = (undefined8 *)RtlGetNextExpiredTimerWheelEntry(*(undefined8 *)(param_2 + 0xa0));
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
    if (puVar13 != (undefined8 *)0x0) {
      do {
        iVar11 = (int)uVar20;
        puVar1 = (uint *)(puVar13 + -1);
        local_60 = puVar13;
        uVar8 = KeAcquireSpinLockRaiseToDpc(puVar13 + 0x3a);
        *(undefined1 *)(puVar13 + 0x3b) = uVar8;
        puVar6 = BwcVirtualLine;
        *(undefined4 *)((longlong)puVar13 + 0x14) = 0;
        puVar12 = puVar13 + 4;
        uVar20 = QosFlowNeedQueueFeedback
                           ((longlong)puVar12,(longlong)local_80,(undefined8 *)local_50);
        if (((char)uVar20 != '\0') && (puVar6 != (undefined8 *)0x0)) {
          NdisAcquireRWLockWrite(*puVar6,&local_res10,1);
          puVar19 = puVar6 + 1;
          uVar20 = (ulonglong)uVar10;
          uVar14 = QosLineNeedSignal((longlong)puVar19,uVar10);
          if ((char)uVar14 != '\0') {
            uVar20 = (ulonglong)uVar10;
            QosLineSignalExternalEvent((longlong)puVar19,uVar10);
          }
          QosLineQueryQueueFeedback((longlong)puVar19,uVar20,local_50);
          NdisReleaseRWLock(*puVar6,&local_res10);
          QosTbcAdjustSendWindow((longlong)puVar12,(longlong)local_50);
          iVar11 = (int)local_a8;
        }
        param_4 = (ulonglong *)local_b8;
        bVar9 = QosFlowProcessQueuedNetBufferLists((longlong)puVar12,uVar10);
        if (bVar9) {
          auVar5._8_8_ = 0;
          auVar5._0_8_ = *(ulonglong *)(puVar13[0x10] + 0x18);
          lVar16 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar5,8);
          iVar18 = (int)((*(ulonglong *)(puVar13[0x10] + 0x18) - lVar16 >> 1) + lVar16 >> 7);
          iVar15 = iVar18 + 1;
          if (0 < iVar18 - iVar11) {
            iVar15 = iVar18;
          }
          if (iVar15 == 0) {
            iVar15 = 1;
          }
          *(int *)((longlong)puVar13 + 0x14) = iVar15;
        }
        RtlAcquireWriteLockAtDpcLevel(param_2);
        RtlReturnTimerWheelEntry(*(undefined8 *)(param_2 + 0xa0),puVar13);
        local_58 = (undefined8 *)*puVar13;
        puVar12 = (undefined8 *)RtlGetNextExpiredTimerWheelEntry(*(undefined8 *)(param_2 + 0xa0));
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
        puVar19 = local_b0;
        if (local_b0 != (undefined8 *)0x0) {
          param_4 = &local_a0;
          BwcDropNbls((longlong)puVar1,(longlong)puVar6,local_b0,param_4);
        }
        KeReleaseSpinLock(puVar13 + 0x3a,*(undefined1 *)(puVar13 + 0x3b));
        if (local_a0 != 0) {
          (*DropQueuedNonConformantNbls)(puVar1,local_a0);
        }
        puVar13 = local_98;
        if (local_98 != (undefined8 *)0x0) {
          puVar19 = puVar6 + 1;
          puVar17 = (undefined2 *)(ulonglong)uVar10;
          uVar14 = QosLineNeedSignal((longlong)puVar19,uVar10);
          if ((char)uVar14 != '\0') {
            NdisAcquireRWLockWrite(*puVar6,&local_res10,1);
            QosLineSignalExternalEvent((longlong)puVar19,uVar10);
            puVar17 = &local_res10;
            NdisReleaseRWLock(*puVar6);
          }
          QosLineSendNetBufferLists((longlong)puVar19,puVar17,puVar13,param_4,&local_90,&local_b0);
          param_4 = &local_88;
          local_88 = 0;
          puVar19 = local_90;
          BwcCompleteNbls((longlong)puVar1,puVar6,local_90,param_4);
          if (local_88 != 0) {
            BwcSendProcessedNbls();
          }
        }
        if (local_58 == local_60) {
          BwcDereferenceFlow(puVar1);
        }
        uVar20 = local_a8;
        puVar13 = puVar12;
      } while (puVar12 != (undefined8 *)0x0);
      puVar12 = local_80;
    }
    puVar13 = &local_78;
    RtlAcquireWriteLockAtDpcLevel(param_2);
  }
  iVar11 = RtlGetNextExpirationTimerWheelTick(*(undefined8 *)(param_2 + 0xa0));
  if (iVar11 == 0) {
    cVar7 = RtlIsTimerWheelSuspended(*(undefined8 *)(param_2 + 0xa0));
    puVar12 = puVar13;
    if (cVar7 == '\0') {
      RtlSuspendTimerWheel(*(undefined8 *)(param_2 + 0xa0));
      puVar12 = puVar13;
    }
    *(uint *)(param_2 + 0xac) = *(uint *)(param_2 + 0xac) | 1;
    KeCancelTimer(param_2 + 0x60);
  }
  else {
    puVar19 = (undefined8 *)((ulonglong)(uint)(iVar11 - (int)uVar20) * 0xfa + (longlong)puVar12);
    BwcSetTimer(param_2,(ulonglong)puVar12,(ulonglong)puVar19);
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
  BwcIndicateDelayQueueConsumerEnd(uVar10,puVar12,puVar19,param_4);
  return;
}



===== BwcUninitializeFlow @ 140007224 =====

void BwcUninitializeFlow(uint *param_1)

{
  undefined1 local_res8 [32];
  
  local_res8[0] = 0;
  RtlCleanupTimerWheelEntry
            (*(undefined8 *)((ulonglong)*param_1 * 0xc0 + 0xa0 + BwcTimerUnits),param_1 + 2,
             local_res8);
  return;
}



===== BwcUninitializeTimerUnit @ 140007268 =====

void BwcUninitializeTimerUnit(longlong param_1)

{
  if (*(longlong *)(param_1 + 0xa0) != 0) {
    RtlCleanupTimerWheel();
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xa0),0x77747742);
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  return;
}



===== BwcUpdateFlow @ 1400072b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int BwcUpdateFlow(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined2 *puVar12;
  uint *puVar13;
  undefined1 auStackY_138 [32];
  undefined2 local_f8;
  undefined1 local_f6;
  uint local_f4;
  uint local_f0 [2];
  undefined8 *local_e8;
  undefined8 *local_e0;
  undefined8 local_d8;
  undefined8 *local_d0;
  undefined8 local_c8;
  uint local_c0 [10];
  uint local_98 [8];
  ulonglong local_78;
  ulonglong local_70;
  ulonglong local_68;
  ulonglong local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_3c;
  ulonglong local_38;
  
  puVar4 = BwcVirtualLine;
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e0 = (undefined8 *)0x0;
  local_e8 = (undefined8 *)0x0;
  local_d0 = (undefined8 *)0x0;
  local_c8 = 0;
  local_d8 = 0;
  local_f0[1] = 0;
  local_f4 = 0;
  local_f0[0] = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[8] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  local_f8 = 0;
  local_f6 = 0;
  memset(&local_78,0,0x40);
  local_98[4] = 0;
  local_98[5] = 0;
  local_3c = 2;
  local_98[6] = 1;
  local_98[7] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  BwcGetQoSParameters(*(ulonglong *)(param_1 + 0x10) >> 10,&local_60,&local_f4,local_f0);
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x1d8);
  *(undefined1 *)(param_2 + 0x1e0) = uVar5;
  if (*(int *)(param_2 + 0x1d0) == 0) {
    local_70 = *(ulonglong *)(param_1 + 0x20);
    local_78 = *(ulonglong *)(param_1 + 0x10);
    if (local_70 == 0) {
      local_70 = local_f4 * local_78;
    }
    local_68 = *(ulonglong *)(param_1 + 0x18);
    local_70 = local_70 >> 3;
    if (local_68 == 0) {
      local_68 = local_f0[0] * local_78;
    }
    local_68 = local_68 >> 3;
    local_78 = local_78 >> 3;
    local_58 = 0xffffffff;
    local_54 = 1;
  }
  uVar6 = KeGetCurrentProcessorNumberEx(0);
  uVar11 = (ulonglong)uVar6;
  lVar8 = QosTimerGetCurrentTime(uVar6,'\x01','\x01');
  piVar1 = (int *)(param_2 + 0x28);
  uVar9 = QosFlowNeedQueueFeedback((longlong)piVar1,lVar8,(undefined8 *)local_c0);
  if ((char)uVar9 != '\0') {
    NdisAcquireRWLockWrite(*puVar4,&local_f8,1);
    puVar2 = puVar4 + 1;
    uVar10 = QosLineNeedSignal((longlong)puVar2,uVar6);
    if ((char)uVar10 != '\0') {
      uVar11 = (ulonglong)uVar6;
      QosLineSignalExternalEvent((longlong)puVar2,uVar6);
    }
    QosLineQueryQueueFeedback((longlong)puVar2,uVar11,local_c0);
    NdisReleaseRWLock(*puVar4,&local_f8);
    QosTbcAdjustSendWindow((longlong)piVar1,(longlong)local_c0);
  }
  puVar13 = local_98;
  iVar7 = QosFlowUpdate(piVar1,uVar6,(longlong *)&local_78,(int *)puVar13,local_f0 + 1,
                        (longlong *)&local_e0,(longlong *)&local_e8);
  if (iVar7 == 0x103) {
    NdisAcquireRWLockWrite(*puVar4);
    uVar9 = QosLineUpdate(puVar4 + 1,(undefined8 *)0x0,0,local_98);
    NdisReleaseRWLock(*puVar4,&local_f8);
    puVar13 = (uint *)(uVar9 & 0xffffffff);
    iVar7 = QosFlowUpdateComplete
                      (piVar1,uVar6,(longlong *)&local_78,(int)uVar9,local_f0 + 1,
                       (longlong *)&local_e0,(longlong *)&local_e8);
  }
  if (local_e8 != (undefined8 *)0x0) {
    puVar13 = (uint *)&local_d8;
    BwcDropNbls(param_2,(longlong)puVar4,local_e8,(undefined8 *)puVar13);
    (*DropQueuedNonConformantNbls)(param_2,local_d8);
  }
  puVar2 = local_e0;
  if (local_e0 != (undefined8 *)0x0) {
    puVar3 = puVar4 + 1;
    puVar12 = (undefined2 *)(ulonglong)uVar6;
    uVar10 = QosLineNeedSignal((longlong)puVar3,uVar6);
    if ((char)uVar10 != '\0') {
      NdisAcquireRWLockWrite(*puVar4,&local_f8,1);
      QosLineSignalExternalEvent((longlong)puVar3,uVar6);
      puVar12 = &local_f8;
      NdisReleaseRWLock(*puVar4);
    }
    QosLineSendNetBufferLists((longlong)puVar3,puVar12,puVar2,puVar13,&local_d0,&local_e8);
    BwcCompleteNbls(param_2,puVar4,local_d0,&local_c8);
    BwcSendProcessedNbls();
  }
  KeReleaseSpinLock(param_2 + 0x1d8,*(undefined1 *)(param_2 + 0x1e0));
  return iVar7;
}



===== BwcUpdateQoSPolicy @ 140007648 =====

int BwcUpdateQoSPolicy(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 local_res18 [2];
  undefined8 local_38;
  undefined8 local_30;
  longlong local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_30 = 0;
  iVar2 = 0;
  local_20 = 0;
  local_18 = 0;
  local_38 = 0;
  local_res18[0] = 0;
  local_28 = (ulonglong)param_2 << 10;
  uVar1 = param_1[1];
  if (param_2 == 0) {
    if (uVar1 != 0) {
      param_1[1] = 0;
      LOCK();
      *param_1 = *param_1 + -1;
      UNLOCK();
    }
  }
  else if (uVar1 == 0) {
    if (*(longlong *)(param_1 + 4) == 0) {
      iVar2 = BwcCreateFlow((longlong)&local_38,local_res18);
      if (iVar2 < 0) {
        return iVar2;
      }
      LOCK();
      *(undefined8 *)(param_1 + 4) = local_res18[0];
      UNLOCK();
    }
    else {
      iVar2 = BwcUpdateFlow((longlong)&local_38,*(longlong *)(param_1 + 4));
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    param_1[1] = param_2;
    LOCK();
    *param_1 = *param_1 + 1;
    UNLOCK();
  }
  else if ((param_2 != uVar1) &&
          (iVar2 = BwcUpdateFlow((longlong)&local_38,*(longlong *)(param_1 + 4)), -1 < iVar2)) {
    param_1[1] = param_2;
  }
  return iVar2;
}



===== RoReferenceEx @ 140007704 =====

ulonglong RoReferenceEx(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = *param_1;
    if ((uVar2 & 1) != 0) {
      return (ulonglong)(uVar2 & 0xffffff00);
    }
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 + 2;
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}



===== RtlAcquireWriteLockAtDpcLevel @ 140007724 =====

void RtlAcquireWriteLockAtDpcLevel(longlong param_1)

{
  KeAcquireInStackQueuedSpinLockAtDpcLevel();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== BwcAddQoSPolicyToQoSPoliciesHashTable @ 140007750 =====

undefined8 BwcAddQoSPolicyToQoSPoliciesHashTable(longlong param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined4 local_res8 [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar1 = *(uint *)(param_1 + 0xc);
  uVar7 = 0;
  local_res8[0] = 0;
  NdisAcquireReadWriteLock(&QoSPoliciesHashTableRWLock,1,local_res8);
  puVar6 = auStack_28;
  plVar4 = &QoSPoliciesHashListHead + (ulonglong)(uVar1 & 0x1f) * 2;
  plVar3 = (longlong *)*plVar4;
  do {
    if (plVar3 == plVar4) {
      lVar5 = *plVar4;
      plVar3 = (longlong *)(param_1 + 0x40);
      if (*(longlong **)(lVar5 + 8) != plVar4) {
        plVar4 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        plVar3 = (longlong *)(*pcVar2)();
        puVar6 = auStack_20;
      }
      *plVar3 = lVar5;
      plVar3[1] = (longlong)plVar4;
      *(longlong **)(lVar5 + 8) = plVar3;
      *plVar4 = (longlong)plVar3;
LAB_1400077d5:
      *(undefined8 *)(puVar6 + -8) = 0x1400077e8;
      NdisReleaseReadWriteLock(&QoSPoliciesHashTableRWLock,puVar6 + 0x30);
      return uVar7;
    }
    if (*(int *)((longlong)plVar3 + -0x34) == *(int *)(param_1 + 0xc)) {
      uVar7 = 0xc000022a;
      puVar6 = auStack_28;
      goto LAB_1400077d5;
    }
    plVar3 = (longlong *)*plVar3;
  } while( true );
}



===== BwcCleanupQoSPolicy @ 140007810 =====

void BwcCleanupQoSPolicy(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)
           (&QoSPoliciesHashListHead)[(ulonglong)(*(uint *)(param_1 + -0xc) & 0x1f) * 2];
  do {
    if (puVar5 == &QoSPoliciesHashListHead + (ulonglong)(*(uint *)(param_1 + -0xc) & 0x1f) * 2) {
LAB_14000785f:
      if (*(uint **)(param_1 + -8) != (uint *)0x0) {
        BwcDeleteFlow(*(uint **)(param_1 + -8));
      }
      ExFreeToNPagedLookasideList(&QoSPolicyList,param_1 + -0x18);
      return;
    }
    if (*(uint *)((longlong)puVar5 + -0x34) == *(uint *)(param_1 + -0xc)) {
      plVar1 = (longlong *)(param_1 + 0x28);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar3 = *(longlong **)(param_1 + 0x30), (longlong *)*plVar3 != plVar1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      goto LAB_14000785f;
    }
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== BwcDereferenceQoSPolicy @ 140007898 =====

void BwcDereferenceQoSPolicy(longlong param_1)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = 0;
  NdisAcquireReadWriteLock(&QoSPoliciesHashTableRWLock,1,local_res10);
  DereferenceRefCount((int *)(param_1 + 0x18));
  NdisReleaseReadWriteLock(&QoSPoliciesHashTableRWLock,local_res10);
  return;
}



===== BwcFindQoSPolicyFromPolicyIndex @ 1400078f4 =====

undefined8 * BwcFindQoSPolicyFromPolicyIndex(uint param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 local_res8 [2];
  
  puVar2 = (undefined8 *)0x0;
  local_res8[0] = 0;
  NdisAcquireReadWriteLock(&QoSPoliciesHashTableRWLock,0,local_res8);
  puVar1 = (undefined8 *)(&QoSPoliciesHashListHead)[(ulonglong)(param_1 & 0x1f) * 2];
  do {
    if (puVar1 == &QoSPoliciesHashListHead + (ulonglong)(param_1 & 0x1f) * 2) {
LAB_14000794d:
      NdisReleaseReadWriteLock(&QoSPoliciesHashTableRWLock,local_res8);
      return puVar2;
    }
    if (*(uint *)((longlong)puVar1 + -0x34) == param_1) {
      puVar2 = puVar1 + -8;
      LOCK();
      *(int *)(puVar1 + -5) = *(int *)(puVar1 + -5) + 1;
      UNLOCK();
      goto LAB_14000794d;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== FindGatewayForInterface @ 14000797c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS FindGatewayForInterface(SOCKADDR_INET *param_1,NET_IFINDEX param_2,undefined8 *param_3)

{
  ADDRESS_FAMILY Family;
  undefined8 uVar1;
  bool bVar2;
  NTSTATUS NVar3;
  PMIB_IPFORWARD_TABLE2 Memory;
  ULONG *pUVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStackY_118 [32];
  PMIB_IPFORWARD_TABLE2 local_d8;
  SOCKADDR_INET local_d0;
  _MIB_IPFORWARD_ROW2 local_a8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  Family = (param_1->Ipv4).sin_family;
  memset(&local_a8,0,0x68);
  local_d8 = (PMIB_IPFORWARD_TABLE2)0x0;
  local_d0._16_8_ = 0;
  local_d0.Ipv6.field4_0x18 = (_union_6653)0;
  local_d0._0_8_ = 0;
  local_d0.Ipv4.sin_zero[0] = '\0';
  local_d0.Ipv4.sin_zero[1] = '\0';
  local_d0.Ipv4.sin_zero[2] = '\0';
  local_d0.Ipv4.sin_zero[3] = '\0';
  local_d0.Ipv4.sin_zero[4] = '\0';
  local_d0.Ipv4.sin_zero[5] = '\0';
  local_d0.Ipv4.sin_zero[6] = '\0';
  local_d0.Ipv4.sin_zero[7] = '\0';
  NVar3 = GetBestRoute2((NET_LUID *)0x0,param_2,(SOCKADDR_INET *)0x0,param_1,0,&local_a8,&local_d0);
  if (NVar3 < 0) {
    NVar3 = GetIpForwardTable2(Family,&local_d8);
    if (-1 < NVar3) {
      uVar6 = 0;
      Memory = local_d8;
      while (uVar5 = (uint)uVar6, uVar5 < Memory->NumEntries) {
        if (Memory->Table[uVar6].InterfaceIndex == param_2) {
          pUVar4 = &Memory->Table[uVar6 - 1].Age;
          bVar2 = INETADDR_ISANY((short *)&Memory->Table[uVar6].DestinationPrefix);
          if (bVar2) {
            uVar1 = *(undefined8 *)(pUVar4 + 0xf);
            *param_3 = *(undefined8 *)(pUVar4 + 0xd);
            param_3[1] = uVar1;
            param_3[2] = *(undefined8 *)(pUVar4 + 0x11);
            *(ULONG *)(param_3 + 3) = pUVar4[0x13];
            break;
          }
          bVar2 = INETADDR_ISANY((short *)(pUVar4 + 0xd));
          if (!bVar2) {
            uVar1 = *(undefined8 *)(pUVar4 + 0xf);
            *param_3 = *(undefined8 *)(pUVar4 + 0xd);
            param_3[1] = uVar1;
            param_3[2] = *(undefined8 *)(pUVar4 + 0x11);
            *(ULONG *)(param_3 + 3) = pUVar4[0x13];
          }
        }
        uVar6 = (ulonglong)(uVar5 + 1);
      }
      goto LAB_140007a1b;
    }
  }
  else {
    *param_3 = local_a8.NextHop._0_8_;
    *(CHAR (*) [8])(param_3 + 1) = local_a8.NextHop.Ipv4.sin_zero;
    param_3[2] = local_a8.NextHop._16_8_;
    ((_union_6653 *)(param_3 + 3))->sin6_scope_id = (ULONG)local_a8.NextHop.Ipv6.field4_0x18;
  }
  Memory = local_d8;
LAB_140007a1b:
  if (Memory != (PMIB_IPFORWARD_TABLE2)0x0) {
    FreeMibTable(Memory);
  }
  return NVar3;
}



===== GetMTUFromInterface @ 140007ae4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetMTUFromInterface(NET_IFINDEX param_1,ADDRESS_FAMILY param_2,undefined4 *param_3)

{
  NTSTATUS NVar1;
  undefined1 auStack_f8 [32];
  _MIB_IPINTERFACE_ROW local_d8;
  undefined4 local_40;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d8._2_4_ = 0;
  local_d8._6_2_ = 0;
  memset(&local_d8,0,0xa2);
  *param_3 = 0;
  InitializeIpInterfaceEntry(&local_d8);
  local_d8.Family = param_2;
  local_d8.InterfaceIndex = param_1;
  NVar1 = GetIpInterfaceEntry(&local_d8);
  if (-1 < NVar1) {
    *param_3 = local_40;
  }
  return;
}



===== INETADDR_ISANY @ 140007b84 =====

bool INETADDR_ISANY(short *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*param_1 == 0x17) {
    if (((((param_1[4] == 0) && (param_1[5] == 0)) && (param_1[6] == 0)) &&
        ((param_1[7] == 0 && (param_1[8] == 0)))) &&
       ((param_1[9] == 0 && ((param_1[10] == 0 && (param_1[0xb] == 0)))))) {
      return true;
    }
  }
  else {
    bVar1 = *(int *)(param_1 + 2) == 0;
  }
  return bVar1;
}



===== INET_ADDR_EQUAL @ 140007bd0 =====

ulonglong INET_ADDR_EQUAL(short param_1,longlong *param_2,longlong *param_3)

{
  if (param_1 != 0x17) {
    return (ulonglong)CONCAT31((int3)((ulonglong)*param_3 >> 8),(int)*param_2 == (int)*param_3);
  }
  if ((param_2[1] == param_3[1]) && (*param_2 == *param_3)) {
    return CONCAT71((int7)((ulonglong)*param_3 >> 8),1);
  }
  return 0;
}



===== NsiCliAddOrDeleteHostRouteToInterface @ 140007c00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Enum "enum_6678": Some values do not have unique names */

void NsiCliAddOrDeleteHostRouteToInterface(SOCKADDR_INET *param_1,NET_IFINDEX param_2,char param_3)

{
  CHAR (*paCVar1) [8];
  undefined2 uVar2;
  longlong lVar3;
  undefined1 auStack_b8 [32];
  _MIB_IPFORWARD_ROW2 local_98;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  memset(&local_98,0,0x68);
  uVar2 = (param_1->Ipv4).sin_family;
  InitializeIpForwardEntry(&local_98);
  local_98.Metric = 1;
  local_98.ValidLifetime = 0xffffffff;
  local_98.PreferredLifetime = 0xffffffff;
  local_98.Protocol = MIB_IPPROTO_NETMGMT;
  local_98.Immortal = '\x01';
  local_98.InterfaceIndex = param_2;
  FindGatewayForInterface(param_1,param_2,(undefined8 *)&local_98.NextHop);
  lVar3 = 8;
  if ((param_1->Ipv4).sin_family != 0x17) {
    lVar3 = 4;
  }
  if (uVar2 == 0x17) {
    paCVar1 = (CHAR (*) [8])((longlong)&(param_1->Ipv6).sin6_addr.u + lVar3 + -8);
    local_98.DestinationPrefix.Prefix.Ipv4.sin_zero = *paCVar1;
    local_98.DestinationPrefix.Prefix._16_8_ = paCVar1[1];
  }
  else {
    local_98.DestinationPrefix.Prefix.Ipv4.sin_addr.S_un =
         *(IN_ADDR *)
          &(((IN_ADDR *)((longlong)&(param_1->Ipv6).sin6_addr.u + lVar3 + -8))->S_un).S_un_b;
    local_98.DestinationPrefix.PrefixLength = ' ';
    if (uVar2 == 2) goto LAB_140007cb6;
  }
  local_98.DestinationPrefix.PrefixLength = 0x80;
LAB_140007cb6:
  local_98.DestinationPrefix.Prefix.Ipv4.sin_family = uVar2;
  if (param_3 == '\0') {
    DeleteIpForwardEntry2(&local_98);
  }
  else {
    InternalCreateOrRefIpForwardEntry2(1,&local_98);
  }
  return;
}



===== NsiCliAttachProvider @ 140007d10 =====

int NsiCliAttachProvider(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,0x18,NsiCliTag);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar2 + 0x10) = param_1;
    iVar1 = NmrClientAttachProvider(param_1,lVar2,&NsiCliDispatch,lVar2,lVar2 + 8);
    if (iVar1 < 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  return iVar1;
}



===== NsiCliCleanupProviderContext @ 140007da0 =====

void NsiCliCleanupProviderContext(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== NsiCliDeregisterClient @ 140007dc0 =====

void NsiCliDeregisterClient(void)

{
  int iVar1;
  bool bVar2;
  
  if (NsiCliHandle != 0) {
    NmrDeregisterClient();
    NmrWaitForClientDeregisterComplete(NsiCliHandle);
    LOCK();
    iVar1 = NsiCliDriverRefCount + -1;
    UNLOCK();
    bVar2 = NsiCliDriverRefCount == 1;
    NsiCliDriverRefCount = iVar1;
    if (bVar2) {
      KeSetEvent(&NsiCliDriverUnloadEvent,0,0);
    }
    NsiCliHandle = 0;
    KeWaitForSingleObject(&NsiCliDriverUnloadEvent,0,0,0,0);
  }
  return;
}



===== NsiCliGetInterfaceSpeed @ 140007e4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NsiCliGetInterfaceSpeed(NET_IFINDEX param_1,undefined4 *param_2)

{
  NTSTATUS NVar1;
  undefined1 auStack_588 [32];
  _MIB_IF_ROW2 local_568;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_588;
  memset(&local_568,0,0x548);
  *param_2 = 0;
  local_568.InterfaceIndex = param_1;
  NVar1 = GetIfEntry2(&local_568);
  if (-1 < NVar1) {
    *param_2 = (undefined4)local_568.TransmitLinkSpeed;
  }
  return;
}



===== NsiCliGetLinkSpeedAndMTUFromAddress @ 140007ed0 =====

NTSTATUS NsiCliGetLinkSpeedAndMTUFromAddress
                   (ADDRESS_FAMILY *param_1,undefined4 *param_2,undefined4 *param_3)

{
  ADDRESS_FAMILY Family;
  uint uVar1;
  NTSTATUS NVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  PMIB_UNICASTIPADDRESS_TABLE Memory;
  longlong lVar7;
  PMIB_UNICASTIPADDRESS_TABLE local_res8;
  
  Family = *param_1;
  local_res8 = (PMIB_UNICASTIPADDRESS_TABLE)0x0;
  lVar5 = 4;
  if (Family != 2) {
    lVar5 = 8;
  }
  *param_2 = 0;
  *param_3 = 0;
  NVar2 = GetUnicastIpAddressTable(Family,&local_res8);
  Memory = local_res8;
  if (-1 < NVar2) {
    uVar1 = local_res8->NumEntries;
    NVar2 = -0x3ffffddb;
    for (uVar6 = 0; (uint)uVar6 < uVar1; uVar6 = (ulonglong)((int)uVar6 + 1)) {
      lVar7 = uVar6 * 0x50;
      lVar4 = 0xc;
      if (Family != 2) {
        lVar4 = 0x10;
      }
      uVar3 = INET_ADDR_EQUAL(Family,(longlong *)
                                     ((longlong)(&Memory->Table[uVar6].Address.Ipv6.sin6_addr + -1)
                                     + lVar4),(longlong *)(lVar5 + (longlong)param_1));
      if ((char)uVar3 != '\0') {
        NVar2 = NsiCliGetLinkSpeedAndMTUFromInterfaceIndex
                          (*(NET_IFINDEX *)
                            ((longlong)&(&Memory->Table[0].Address)[1].Ipv6.sin6_addr.u + lVar7 + 4)
                           ,param_2,param_3,Family == 2);
        Memory = local_res8;
        break;
      }
    }
  }
  if (Memory != (PMIB_UNICASTIPADDRESS_TABLE)0x0) {
    FreeMibTable(Memory);
  }
  return NVar2;
}



===== NsiCliGetLinkSpeedAndMTUFromInterfaceIndex @ 140007fc4 =====

void NsiCliGetLinkSpeedAndMTUFromInterfaceIndex
               (NET_IFINDEX param_1,undefined4 *param_2,undefined4 *param_3,char param_4)

{
  int iVar1;
  
  iVar1 = NsiCliGetInterfaceSpeed(param_1,param_2);
  if (-1 < iVar1) {
    GetMTUFromInterface(param_1,(-(ushort)(param_4 != '\0') & 0xffeb) + 0x17,param_3);
  }
  return;
}



===== QosLineAdjustSendWindow @ 140008014 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosLineAdjustSendWindow(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  longlong local_78;
  ulonglong local_70;
  ulonglong local_68;
  ulonglong local_60;
  longlong local_58;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = (ulonglong)*(uint *)(param_1 + 0x78);
  local_44 = 0;
  local_50 = 0;
  local_3c = 0;
  local_4c = 0;
  if (*(uint *)(param_1 + 0x78) == 0) {
    local_68 = 0x7fffffffffffffff;
    local_78 = 0x7fffffffffffffff;
    lVar4 = 0;
    uVar3 = 0x7fffffff;
    local_70 = 0x7fffffffffffffff;
    uVar5 = 0x7fffffffffffffff;
  }
  else if ((*(uint *)(param_1 + 0xd0) & 4) == 0) {
    *(uint *)(param_1 + 0xd0) = *(uint *)(param_1 + 0xd0) | 4;
    local_78 = 0;
    lVar4 = 0;
    uVar3 = local_68;
    local_70 = local_68;
    uVar5 = local_68;
  }
  else {
    LOCK();
    local_50 = *(int *)(param_1 + 0x84);
    *(int *)(param_1 + 0x84) = 0;
    UNLOCK();
    LOCK();
    local_4c = *(int *)(param_1 + 0x88);
    *(int *)(param_1 + 0x88) = 0;
    UNLOCK();
    lVar4 = (ulonglong)*(uint *)(param_1 + 0x8c) + ((longlong)local_50 - (longlong)local_4c);
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x78) - lVar4;
    lVar1 = (uVar3 - (longlong)*(int *)(param_1 + 200)) * 3;
    lVar1 = lVar1 + SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(lVar1),8);
    local_78 = (lVar1 >> 7) - (lVar1 >> 0x3f);
    lVar1 = uVar3 + SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816((longlong)uVar3),8);
    local_70 = (lVar1 >> 6) - (lVar1 >> 0x3f);
    local_68 = local_78 + local_70;
    uVar2 = *(longlong *)(param_1 + 0xb8) + local_68;
    if ((longlong)uVar2 < 1) {
      uVar2 = 0;
    }
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x7c);
    if ((longlong)uVar2 < (longlong)(ulonglong)*(uint *)(param_1 + 0x7c)) {
      uVar5 = uVar2;
    }
  }
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_88 = param_2;
    local_80 = uVar3;
    local_60 = uVar5;
    local_58 = param_1;
    local_48 = (int)lVar4;
    QosTraceEvent(6,&local_88);
  }
  *(int *)(param_1 + 0x8c) = (int)lVar4;
  *(int *)(param_1 + 200) = (int)uVar3;
  *(ulonglong *)(param_1 + 0xb8) = uVar5;
  return;
}



===== QosLineComputeBufferSizes @ 1400081c0 =====

void QosLineComputeBufferSizes(longlong param_1)

{
  undefined1 auVar1 [16];
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  
  uVar3 = *(ulonglong *)(param_1 + 8);
  iVar5 = 0;
  if (uVar3 == 0xffffffffffffffff) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(uint *)(param_1 + 0x74) * uVar3) / 1000000;
    if ((uVar3 < 0xc80001) || (uVar3 < 0x8000001)) {
      uVar2 = 0x32;
    }
    else {
      uVar2 = 0x17;
      iVar5 = 0xc;
    }
    if ((*(uint *)(param_1 + 0x68) - 0xb < 0x13) || (0x1d < *(uint *)(param_1 + 0x68))) {
      uVar2 = uVar2 + iVar5;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar2 * uVar6;
    lVar4 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
    iVar5 = (int)((uVar2 * uVar6 - lVar4 >> 1) + lVar4 >> 6);
  }
  *(int *)(param_1 + 0xcc) = (int)uVar6;
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x6c) * (uVar6 & 0xffffffff) * 2;
  *(int *)(param_1 + 0x78) = iVar5;
  if (0xfffffffe < uVar3) {
    uVar3 = 0xffffffff;
  }
  *(int *)(param_1 + 0x7c) = (int)uVar3;
  return;
}



===== QosLineCreate @ 140008278 =====

ulonglong QosLineCreate(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 local_res10;
  
  local_res10 = param_2;
  memset(param_1,0,0xd8);
  param_1[4] = BwcGenericObjectHandle;
  param_1[5] = BwcSendNblPoolHandle;
  uVar1 = KeGetCurrentProcessorNumberEx(0);
  uVar2 = QosTimerGetCurrentTime(uVar1,'\x01','\0');
  lVar3 = -1;
  if (param_3 != 0) {
    lVar3 = param_3;
  }
  QosLineUpdate(param_1,&local_res10,lVar3,(uint *)0x0);
  lVar3 = uVar2 - uVar2 % (ulonglong)*(uint *)((longlong)param_1 + 0x74);
  param_1[0x14] = lVar3;
  param_1[0x15] = lVar3;
  return uVar2 / *(uint *)((longlong)param_1 + 0x74);
}



===== QosLineNeedSignal @ 140008320 =====

undefined8 QosLineNeedSignal(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  lVar3 = QosTimerGetCurrentTime(param_2,'\0','\x01');
  lVar4 = *(longlong *)(param_1 + 0xa8) - lVar3;
  if ((lVar4 < 1) || (lVar4 = *(longlong *)(param_1 + 0xa0) - lVar3, lVar4 < 1)) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar5 = 0;
    if (iVar2 == 0) {
      uVar5 = 1;
    }
  }
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar5);
}



===== QosLineQueryQueueFeedback @ 140008394 =====

void QosLineQueryQueueFeedback(longlong param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + *param_3;
  uVar1 = *(uint *)(param_1 + 0x70);
  if (*(uint *)(param_1 + 0x70) <= *param_3) {
    uVar1 = *param_3;
  }
  *(uint *)(param_1 + 0x70) = uVar1;
  param_3[2] = *(uint *)(param_1 + 0x78);
  param_3[3] = *(uint *)(param_1 + 0x6c);
  *(undefined8 *)(param_3 + 6) = *(undefined8 *)(param_1 + 0xb0);
  param_3[5] = *(uint *)(param_1 + 0x74);
  *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_1 + 0xc0);
  param_3[4] = *(uint *)(param_1 + 0x70);
  return;
}



===== QosLineSendNetBufferLists @ 1400083ec =====

ulonglong QosLineSendNetBufferLists
                    (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                    undefined8 *param_5,undefined8 *param_6)

{
  int iVar1;
  
  iVar1 = QosGetNblChainDataLength(param_3);
  LOCK();
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + iVar1;
  UNLOCK();
  *param_5 = param_3;
  *param_6 = 0;
  return (ulonglong)param_6 & 0xffffffffffffff00;
}



===== QosLineSignalExternalEvent @ 140008428 =====

ulonglong QosLineSignalExternalEvent(longlong param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  lVar1 = QosTimerGetCurrentTime(param_2,'\0','\x01');
  if (*(longlong *)(param_1 + 0xa8) - lVar1 < 1) {
    QosLineAdjustSendWindow(param_1,lVar1);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x98);
    uVar2 = (ulonglong)*(uint *)(param_1 + 0x74);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x9c);
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(ulonglong *)(param_1 + 0xa8) = (uVar2 - (uVar2 + lVar1) % uVar2) + lVar1;
  }
  uVar2 = *(longlong *)(param_1 + 0xa0) - lVar1;
  if ((longlong)uVar2 < 1) {
    QosLineStartNextSendInterval(param_1,lVar1);
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x74);
    uVar2 = (uVar3 + lVar1) / uVar3;
    *(ulonglong *)(param_1 + 0xa0) = (uVar3 - (uVar3 + lVar1) % uVar3) + lVar1;
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x80) = 0;
  UNLOCK();
  return uVar2;
}



===== QosLineStartNextSendInterval @ 1400084fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosLineStartNextSendInterval(longlong param_1,undefined8 param_2)

{
  undefined1 auStack_88 [32];
  undefined8 local_68;
  longlong local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(&local_68,0,0x50);
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_58 = *(undefined4 *)(param_1 + 0x90);
    local_54 = *(undefined4 *)(param_1 + 0x94);
    local_50 = *(undefined4 *)(param_1 + 0xb8);
    local_68 = param_2;
    local_60 = param_1;
    QosTraceEvent(1,&local_68);
  }
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0xb8);
  return;
}



===== QosLineUpdate @ 1400085b0 =====

undefined8 QosLineUpdate(undefined8 *param_1,undefined8 *param_2,longlong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined4 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  uVar9 = 0;
  bVar3 = false;
  if (param_2 != (undefined8 *)0x0) {
    *param_1 = *param_2;
  }
  uVar11 = 1;
  if (param_4 != (uint *)0x0) {
    uVar10 = *(uint *)(param_1 + 0x1a);
    if (((uVar10 >> 1 ^ param_4[6]) & 1) != 0) {
      bVar3 = true;
      *(uint *)(param_1 + 0x1a) = (param_4[6] * 2 ^ uVar10) & 2 ^ uVar10;
    }
  }
  if ((param_3 != 0) && (param_3 != param_1[1])) {
    param_1[1] = param_3;
    bVar3 = true;
  }
  if (param_4 == (uint *)0x0) {
LAB_140008692:
    if (!bVar3) {
      return 0;
    }
  }
  else {
    if (*(longlong *)(param_4 + 4) - 1U < 0xfffffffffffffffe) {
      param_1[0xc] = *(longlong *)(param_4 + 4);
      bVar3 = true;
    }
    if (param_4[2] == 0) goto LAB_140008692;
    uVar10 = param_4[1];
    uVar1 = param_4[3];
    uVar2 = *param_4;
    uVar4 = *(uint *)(param_1 + 0xe);
    uVar6 = *(int *)((longlong)param_1 + 0x6c) + param_4[2];
    *(uint *)((longlong)param_1 + 0x6c) = uVar6;
    lVar8 = (ulonglong)*(uint *)(param_1 + 0xd) + (longlong)(int)uVar1;
    if (0xfffffffe < lVar8) {
      lVar8 = 0xffffffff;
    }
    *(int *)(param_1 + 0xd) = (int)lVar8;
    if (uVar4 == uVar2) {
      uVar4 = 0;
    }
    if (uVar4 <= uVar10) {
      uVar4 = uVar10;
    }
    *(uint *)(param_1 + 0xe) = uVar4;
    uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xcc) * (ulonglong)uVar6 * 2;
    if (0xfffffffe < uVar5) {
      uVar5 = 0xffffffff;
    }
    *(int *)((longlong)param_1 + 0x7c) = (int)uVar5;
  }
  if ((ulonglong)param_1[1] < 0xc80001) {
    uVar7 = 10000;
    uVar10 = 10000;
  }
  else {
    if ((ulonglong)param_1[1] < 0x8000001) {
      *(undefined4 *)((longlong)param_1 + 0x74) = 1000;
      uVar7 = 5000;
      uVar10 = 7000;
      goto LAB_1400086e0;
    }
    uVar7 = 500;
    uVar11 = 10;
    uVar10 = 0x30d4;
  }
  *(undefined4 *)((longlong)param_1 + 0x74) = uVar7;
LAB_1400086e0:
  if (*(uint *)(param_1 + 0xd) - 0xb < 0x13) {
    *(undefined4 *)((longlong)param_1 + 0x74) = uVar7;
  }
  else if (0x1d < *(uint *)(param_1 + 0xd)) {
    *(int *)((longlong)param_1 + 0x74) = (int)(uVar10 / uVar11);
  }
  QosLineComputeBufferSizes((longlong)param_1);
  lVar8 = param_1[0xc];
  if ((lVar8 != 0) && (lVar8 != param_1[1])) {
    uVar9 = ((ulonglong)*(uint *)((longlong)param_1 + 0x74) * lVar8) / 1000000;
  }
  param_1[0x18] = uVar9;
  return 0;
}



===== QosTraceEvent @ 140008754 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void QosTraceEvent(int param_1,undefined8 param_2)

{
  (**(code **)(QosgEtwDispatchTable + 8 + (longlong)param_1 * 8))(param_2);
  return;
}



===== QosFlowNeedQueueFeedback @ 14000877c =====

ulonglong QosFlowNeedQueueFeedback(longlong param_1,longlong param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[4] = 0;
  param_3[3] = 0x7fffffffffffffff;
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x140);
  *(uint *)param_3 = *(uint *)(param_1 + 0x140);
  if (*(int *)(param_1 + 0x140) != 0) {
    uVar1 = QosTbcAdjustBytesSent(param_1,param_2);
    uVar2 = (undefined1)uVar1;
  }
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== QosFlowProcessQueuedNetBufferLists @ 1400087cc =====

bool QosFlowProcessQueuedNetBufferLists(longlong param_1,uint param_2)

{
  bool bVar1;
  longlong lVar2;
  
  bVar1 = QosTbcProcessQueuedNetBufferLists(param_1,param_2);
  if (!bVar1) {
    lVar2 = QosTimerGetCurrentTime(param_2,'\0','\x01');
    *(longlong *)(param_1 + 0x108) = lVar2;
  }
  return bVar1;
}



===== QosFlowSendNetBufferLists @ 140008830 =====

void QosFlowSendNetBufferLists
               (undefined4 *param_1,uint param_2,undefined8 *param_3,ulonglong param_4,int param_5,
               ulonglong *param_6,longlong *param_7)

{
  longlong *plVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong *puVar6;
  longlong **in_stack_ffffffffffffffb8;
  
  param_5 = 0;
  lVar4 = QosTimerGetCurrentTime(param_2,'\0','\x01');
  plVar5 = param_7;
  puVar6 = param_6;
  plVar1 = *(longlong **)(param_1 + 0x18);
  param_6 = (ulonglong *)0x0;
  param_7 = (longlong *)0x0;
  if (plVar1 == (longlong *)(param_1 + 0x18)) {
    if ((*(int *)*QosgEtwDispatchTable == 1) && (0 < lVar4 - *(longlong *)(param_1 + 0x42))) {
      in_stack_ffffffffffffffb8 =
           (longlong **)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000);
      QosTraceFlowSendQueue((longlong)param_1,0,lVar4,lVar4 - *(longlong *)(param_1 + 0x42),0,0,0);
    }
  }
  else if (plVar1[3] - lVar4 < 1) {
    in_stack_ffffffffffffffb8 = &param_7;
    QosTbcProcessQueuedNetBufferLists((longlong)param_1,param_2);
    if (param_6 != (ulonglong *)0x0) {
      puVar6 = param_6;
    }
    if (param_7 != (longlong *)0x0) {
      plVar5 = param_7;
    }
  }
  param_1[8] = param_1[8] + 1;
  uVar3 = QosGetNetBufferCount(param_4,&param_5);
  *(ulonglong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + (ulonglong)(uint)param_5;
  param_1[2] = param_1[2] + uVar3;
  cVar2 = QosTbcSendNetBufferList
                    (param_1,param_2,param_3,param_4,uVar3,param_5,
                     (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,puVar6,plVar5);
  if (cVar2 == '\0') {
    *(longlong *)(param_1 + 0x42) = lVar4;
  }
  return;
}



===== QosFlowUpdate @ 1400089b0 =====

int QosFlowUpdate(int *param_1,uint param_2,longlong *param_3,int *param_4,undefined4 *param_5,
                 longlong *param_6,longlong *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = (int)param_3[7];
  iVar3 = 1;
  *(uint *)((longlong)param_3 + 0x3c) = *(uint *)((longlong)param_3 + 0x3c) | 1;
  if (iVar2 != -1) {
    iVar1 = param_1[0x50];
    iVar4 = iVar2 - iVar1;
    if (iVar4 != iVar2) {
      iVar3 = (iVar4 != -iVar1) - 1;
    }
    if (iVar4 != 0) {
      *param_4 = iVar1;
      param_4[1] = iVar2;
      param_4[2] = iVar4;
      param_4[3] = iVar3;
      return 0x103;
    }
  }
  iVar2 = QosFlowUpdateComplete(param_1,param_2,param_3,0,param_5,param_6,param_7);
  return iVar2;
}



===== QosFlowUpdateComplete @ 140008a60 =====

int QosFlowUpdateComplete
              (int *param_1,uint param_2,longlong *param_3,int param_4,undefined4 *param_5,
              longlong *param_6,longlong *param_7)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  int local_res20 [2];
  ulonglong in_stack_ffffffffffffffc8;
  
  local_res20[0] = 0;
  if (-1 < param_4) {
    uVar2 = param_1[0x68];
    if (((uVar2 ^ *(uint *)((longlong)param_3 + 0x3c)) & 2) != 0) {
      param_1[0x68] = (uVar2 ^ *(uint *)((longlong)param_3 + 0x3c)) & 2 ^ uVar2;
    }
    if (((((char)param_3[6] == (char)param_1[0x14]) &&
         (*(char *)((longlong)param_3 + 0x31) == *(char *)((longlong)param_1 + 0x51))) &&
        (*(char *)((longlong)param_3 + 0x32) == *(char *)((longlong)param_1 + 0x52))) &&
       (((*(char *)((longlong)param_3 + 0x33) == *(char *)((longlong)param_1 + 0x53) &&
         (*(char *)((longlong)param_3 + 0x34) == (char)param_1[0x15])) &&
        (*(char *)((longlong)param_3 + 0x35) == *(char *)((longlong)param_1 + 0x55))))) {
      local_res20[0] = *param_1;
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
      *param_1 = *param_1 + 1;
    }
    param_1[10] = *(int *)((longlong)param_3 + 0x24);
    *(longlong *)(param_1 + 0x14) = param_3[6];
    QosUtilSetTokenSpec((longlong *)(param_1 + 0xe),param_3,*(longlong *)(param_1 + 0x10) == 0);
    uVar2 = KeGetCurrentProcessorNumberEx(0);
    lVar3 = QosTimerGetCurrentTime(uVar2,'\0','\x01');
    *(longlong *)(param_1 + 0xc) = lVar3;
    QosTbcFlowUpdate(param_1,param_2,param_3,(int *)(-(ulonglong)bVar1 & (ulonglong)local_res20),
                     in_stack_ffffffffffffffc8,param_5,param_6,param_7);
  }
  *(uint *)((longlong)param_3 + 0x3c) = *(uint *)((longlong)param_3 + 0x3c) & 0xfffffffe;
  return param_4;
}



===== QosInit @ 140008ba4 =====

ulonglong QosInit(void)

{
  uint uVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 *in_R9;
  bool bVar5;
  
  QosgInitializedModules = 0;
  QosgNblCadLookasideList = &BwcNblLookasideList;
  uVar1 = KeQueryTimeIncrement();
  QosgLastSendBoundary = 0;
  QosgBoundaryPeriod = uVar1 / 10;
  QosgRandomValue = KeQueryPerformanceCounter(0);
  bVar5 = BwcEtwDispatchTable == (undefined *)0x0;
  *in_R9 = 0x70;
  if (bVar5) {
LAB_140008c0c:
    uVar4 = 0xc000000d;
  }
  else {
    for (ppuVar2 = &PTR__guard_check_icall_140012008; (longlong)ppuVar2 < 0x140012040;
        ppuVar2 = ppuVar2 + 1) {
      if (*ppuVar2 == (undefined *)0x0) goto LAB_140008c0c;
    }
    QosgInitializedModules = QosgInitializedModules | 1;
    QosgEtwDispatchTable = &BwcEtwDispatchTable;
    uVar3 = QosTimerInitialize();
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      QosgInitializedModules = QosgInitializedModules | 2;
      goto LAB_140008c16;
    }
  }
  QosTerminate();
LAB_140008c16:
  return uVar4 & 0xffffffff;
}



===== QosTerminate @ 140008c70 =====

void QosTerminate(void)

{
  if (((QosgInitializedModules & 2) != 0) && (QosgTimerTable != 0)) {
    QosgTimerTable = 0;
  }
  if ((QosgInitializedModules & 1) != 0) {
    QosgEtwDispatchTable = 0;
  }
  return;
}



===== QosTimerConvertPerformanceCounterToMicroseconds @ 140008ca0 =====

void QosTimerConvertPerformanceCounterToMicroseconds(longlong *param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong local_res8;
  
  local_res8 = 0;
  uVar3 = KeQueryPerformanceCounter(&local_res8);
  uVar5 = (uVar3 >> 0x20) * 1000000;
  bVar1 = *(byte *)(param_1 + 0xe);
  lVar4 = ((uVar5 % local_res8 << 0x20) + (uVar3 & 0xffffffff) * 1000000) / local_res8 +
          (uVar5 / local_res8 << 0x20);
  if (bVar1 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = bVar1 - 1;
  }
  uVar5 = (ulonglong)(uVar2 & 0xff);
  if (param_1[uVar5 + 8] - lVar4 < 1) {
    param_1[(ulonglong)bVar1 + 2] = uVar3;
    param_1[(ulonglong)bVar1 + 5] = local_res8;
    param_1[(ulonglong)bVar1 + 8] = lVar4;
  }
  else {
    param_1[(ulonglong)bVar1 + 2] = param_1[uVar5 + 2];
    param_1[(ulonglong)bVar1 + 5] = param_1[uVar5 + 5];
    param_1[(ulonglong)bVar1 + 8] = param_1[uVar5 + 8];
    lVar4 = param_1[uVar5 + 8];
  }
  param_1[(ulonglong)bVar1 + 0xb] = param_2;
  param_1[1] = param_2;
  *param_1 = lVar4;
  *(byte *)(param_1 + 0xe) = (byte)((char)param_1[0xe] + 1U) % 3;
  return;
}



===== QosTimerGetCurrentTime @ 140008d9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong QosTimerGetCurrentTime(uint param_1,char param_2,char param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined4 in_register_0000000c;
  longlong *plVar3;
  
  uVar2 = 0;
  if (param_3 == '\0') {
    uVar2 = KfRaiseIrql(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),2));
    param_1 = KeGetCurrentProcessorNumberEx(0);
  }
  plVar3 = (longlong *)((ulonglong)param_1 * 0x80 + *QosgTimerTable);
  if ((param_2 != '\0') || (_DAT_fffff78000000008 != plVar3[1])) {
    QosTimerConvertPerformanceCounterToMicroseconds(plVar3,_DAT_fffff78000000008);
  }
  lVar1 = *plVar3;
  if (param_3 == '\0') {
    KeLowerIrql(uVar2);
  }
  return lVar1;
}



===== QosTimerInitialize @ 140008e48 =====

undefined8 QosTimerInitialize(void)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = 0;
  if ((DAT_140016f98 == 0) || (BwcTimerTable == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar3 = 0;
    QosgTimerTable = &BwcTimerTable;
    if (DAT_140016f98 != 0) {
      do {
        memset((void *)(uVar3 * 0x80 + *QosgTimerTable),0,0x80);
        QosTimerGetCurrentTime((uint)uVar3,'\x01','\x01');
        uVar2 = (uint)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < DAT_140016f98);
    }
  }
  return uVar1;
}



===== QosTraceFlowConformance @ 140008ecc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTraceFlowConformance(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  memset(&local_78,0,0x50);
  local_70 = *(undefined8 *)(param_1 + 0x70);
  local_60 = *(undefined8 *)(param_1 + 0x88);
  uStack_58 = *(undefined8 *)(param_1 + 0x90);
  local_50 = *(undefined8 *)(param_1 + 0x98);
  local_68 = *(undefined8 *)(param_1 + 0x78);
  local_40 = *(undefined4 *)(param_1 + 0x80);
  local_78 = param_2;
  local_48 = param_1;
  local_3c = param_3;
  QosTraceEvent(2,&local_78);
  return;
}



===== QosTraceFlowSendQueue @ 140008f74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTraceFlowSendQueue
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  longlong *plVar1;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  plVar1 = *(longlong **)(param_1 + 0x60);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (plVar1 == (longlong *)(param_1 + 0x60)) {
    local_58 = 0;
  }
  else {
    local_58 = plVar1[3];
  }
  local_48 = param_5;
  local_44 = param_6;
  local_40 = param_7;
  local_68 = param_3;
  local_60 = param_4;
  local_50 = param_1;
  local_3c = param_2;
  QosTraceEvent(3,&local_68);
  return;
}



===== QosGetNblChainDataLength @ 140009008 =====

int QosGetNblChainDataLength(undefined8 *param_1)

{
  int iVar1;
  int local_res8 [8];
  
  local_res8[0] = 0;
  iVar1 = 0;
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    QosGetNetBufferCount((longlong)param_1,local_res8);
    iVar1 = iVar1 + local_res8[0];
  }
  return iVar1;
}



===== QosGetNetBufferCount @ 140009048 =====

int QosGetNetBufferCount(longlong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  for (puVar3 = *(undefined8 **)(param_1 + 8); puVar3 != (undefined8 *)0x0;
      puVar3 = (undefined8 *)*puVar3) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + *(int *)(puVar3 + 3);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar2;
  }
  return iVar1;
}



===== QosNblCadDisassemble @ 140009070 =====

undefined8
QosNblCadDisassemble
          (longlong param_1,undefined8 *param_2,uint param_3,int param_4,undefined8 param_5,
          longlong *param_6,char param_7)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  longlong *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar2 = QosgNblCadLookasideList;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  uVar13 = 0;
  puVar10 = param_2;
  puVar5 = (undefined8 *)ExAllocateFromNPagedLookasideList(uVar2);
  if (puVar5 == (undefined8 *)0x0) {
LAB_1400091f9:
    while( true ) {
      uVar13 = 0xc000009a;
      if ((undefined8 *)*param_6 == (undefined8 *)0x0) break;
      puVar5 = QosNblChainRemove(param_6,puVar10,(undefined8 *)*param_6);
      NdisFreeNetBufferList(puVar5);
    }
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    KeInitializeSpinLock(puVar5 + 2);
    puVar10 = puVar5 + 4;
    iVar9 = 0;
    puVar5[5] = puVar10;
    *puVar10 = puVar10;
    puVar5[3] = param_1;
    iVar3 = QosGetNetBufferCount(param_1,(int *)0x0);
    puVar12 = auStack_78;
    uVar16 = iVar9 + 1;
    if ((iVar3 - param_3 != 0) && (uVar16 = param_4 + 1, param_4 == -1)) {
      uVar16 = (iVar3 - param_3) + 1;
    }
    for (uVar4 = 0; uVar4 < uVar16; uVar4 = uVar4 + 1) {
      plVar6 = (longlong *)NdisAllocateNetBufferList(param_2[5],0x70);
      local_58 = plVar6;
      if (plVar6 == (longlong *)0x0) {
        ExFreeToNPagedLookasideList(QosgNblCadLookasideList);
        puVar10 = puVar5;
        goto LAB_1400091f9;
      }
      NdisCopySendNetBufferListInfo(plVar6);
      plVar6[0xf] = param_2[4];
      lVar11 = (ulonglong)*(ushort *)(plVar6[2] + 10) + plVar6[2];
      memset((void *)(lVar11 + 0x10),0,0x70);
      plVar6 = (longlong *)param_6[1];
      *(undefined4 *)(lVar11 + 0x38) = 0;
      *(undefined8 **)(lVar11 + 0x30) = param_2;
      *(longlong **)(lVar11 + 0x28) = local_58;
      *(undefined8 **)(lVar11 + 0x20) = puVar5;
      QosNblChainInsert(param_6,plVar6,local_58);
    }
    plVar6 = (longlong *)*param_6;
    puVar14 = (undefined8 *)0x0;
    plVar6[1] = *(longlong *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = 0;
    puVar8 = (undefined8 *)plVar6[1];
    if (param_3 != 0) {
      uVar7 = (ulonglong)param_3;
      do {
        puVar14 = puVar8;
        puVar8 = (undefined8 *)*puVar14;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *puVar14 = 0;
    puVar14 = (undefined8 *)*plVar6;
    if (puVar14 == (undefined8 *)0x0) {
      *(undefined8 **)(param_1 + 8) = puVar8;
    }
    else if (param_4 == 1) {
      puVar14[1] = puVar8;
    }
    else {
      while (puVar8 != (undefined8 *)0x0) {
        puVar15 = (undefined8 *)*puVar8;
        puVar14[1] = puVar8;
        *puVar8 = 0;
        puVar14 = (undefined8 *)*puVar14;
        puVar8 = puVar15;
      }
    }
    LOCK();
    *(int *)(puVar5 + 6) = *(int *)(puVar5 + 6) + (int)param_6[2];
    UNLOCK();
    if (param_7 == '\0') {
      KeAcquireInStackQueuedSpinLock(puVar5 + 2,&local_50);
    }
    else {
      KeAcquireInStackQueuedSpinLockAtDpcLevel();
    }
    for (puVar8 = (undefined8 *)*param_6; puVar8 != (undefined8 *)0x0;
        puVar8 = (undefined8 *)*puVar8) {
      puVar14 = (undefined8 *)puVar5[5];
      puVar15 = (undefined8 *)((ulonglong)*(ushort *)(puVar8[2] + 10) + 0x10 + puVar8[2]);
      if ((undefined8 *)*puVar14 != puVar10) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        puVar12 = auStack_70;
        goto LAB_14000930e;
      }
      *puVar15 = puVar10;
      puVar15[1] = puVar14;
      *puVar14 = puVar15;
      puVar5[5] = puVar15;
    }
    if (param_7 == '\0') {
LAB_14000930e:
      *(undefined8 *)(puVar12 + -8) = 0x140009315;
      KeReleaseInStackQueuedSpinLock();
    }
    else {
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
    }
  }
  return uVar13;
}



===== QosNblCadReassemble @ 14000933c =====

void QosNblCadReassemble(longlong param_1,char param_2)

{
  longlong ****pppplVar1;
  undefined8 uVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong ****local_38;
  longlong ****local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = (longlong ****)0x0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == '\0') {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x10,&local_28);
  }
  else {
    KeAcquireInStackQueuedSpinLockAtDpcLevel();
  }
  pppplVar1 = (longlong ****)(param_1 + 0x20);
  local_38 = (longlong ****)*pppplVar1;
  if (local_38 == pppplVar1) {
    local_30 = (longlong ****)&local_38;
    local_38 = (longlong ****)&local_38;
  }
  else {
    local_30 = *(longlong *****)(param_1 + 0x28);
    local_38[1] = (longlong ***)&local_38;
    *local_30 = (longlong ***)&local_38;
    *(longlong *****)(param_1 + 0x28) = pppplVar1;
    *pppplVar1 = (longlong ***)pppplVar1;
  }
  if (param_2 == '\0') {
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  else {
    KeReleaseInStackQueuedSpinLockFromDpcLevel();
  }
  uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8) = 0;
  puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x18) + 8);
  do {
    if ((longlong *****)local_38 == &local_38) {
LAB_14000946e:
      *puVar7 = uVar2;
      return;
    }
    if (((longlong *****)local_38[1] != &local_38) ||
       (pppplVar1 = (longlong ****)*local_38, (longlong ****)pppplVar1[1] != local_38)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      goto LAB_14000946e;
    }
    pppplVar1[1] = (longlong ***)&local_38;
    ppplVar3 = local_38[3];
    *puVar7 = ppplVar3[1];
    ppplVar3[1] = (longlong **)0x0;
    puVar6 = (undefined8 *)*puVar7;
    while (puVar5 = puVar6, puVar5 != (undefined8 *)0x0) {
      puVar7 = puVar5;
      puVar6 = (undefined8 *)*puVar5;
    }
    local_38 = pppplVar1;
    NdisFreeNetBufferList();
  } while( true );
}



===== QosNblChainInsert @ 140009488 =====

longlong * QosNblChainInsert(longlong *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  
  if (param_2 == (longlong *)0x0) {
    lVar1 = *param_1;
    *param_1 = (longlong)param_3;
  }
  else {
    lVar1 = *param_2;
    *param_2 = (longlong)param_3;
  }
  *param_3 = lVar1;
  if (lVar1 == 0) {
    param_1[1] = (longlong)param_3;
  }
  *(int *)(param_1 + 2) = (int)param_1[2] + 1;
  return param_3;
}



===== QosNblChainRemove @ 1400094b8 =====

undefined8 * QosNblChainRemove(undefined8 *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = *param_3;
  *param_3 = 0;
  *param_1 = uVar1;
  if ((undefined8 *)param_1[1] == param_3) {
    param_1[1] = 0;
  }
  *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + -1;
  return param_3;
}



===== QosAssignSlot @ 1400094dc =====

ulonglong QosAssignSlot(uint param_1,uint param_2,uint param_3,longlong param_4,uint *param_5,
                       uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = *param_6;
  if (*param_6 == 0) {
    uVar2 = *param_5;
    *param_6 = param_2;
    uVar2 = QosSelectSlot(uVar2 + 1,0,param_3,param_4);
    *param_5 = uVar2;
    uVar2 = param_2;
  }
  uVar1 = *param_5;
  uVar3 = (ulonglong)uVar1;
  if (uVar2 < param_1) {
    *param_6 = param_2 - (param_1 - uVar2) % param_2;
    uVar2 = QosSelectSlot(uVar1 + 1,(param_1 - uVar2) / param_2,param_3,param_4);
    *param_5 = uVar2;
  }
  else {
    *param_6 = uVar2 - param_1;
  }
  return uVar3 & 0xffffffff;
}



===== QosConstructNetBufferListToSend @ 14000956c =====

ulonglong QosConstructNetBufferListToSend
                    (undefined8 *param_1,longlong param_2,longlong param_3,uint param_4,
                    undefined8 param_5,int param_6,char param_7,longlong *param_8,longlong *param_9)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  uVar7 = 0;
  *param_8 = 0;
  *param_9 = 0;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  if (*(longlong *)(param_2 + 0x78) == param_1[4]) {
    lVar2 = *(longlong *)(param_2 + 0x10);
    if (*(int *)((ulonglong)*(ushort *)(lVar2 + 10) + 0x38 + lVar2) == 0) {
      *(undefined8 *)((ulonglong)*(ushort *)(lVar2 + 10) + 0x58 + lVar2) =
           *(undefined8 *)(param_3 + 0x10);
      if (param_4 == 0) {
        *param_9 = param_2;
      }
      else {
        *param_8 = param_2;
      }
      goto LAB_140009694;
    }
  }
  uVar6 = 1;
  if (param_4 != 0) {
    uVar6 = param_4;
  }
  uVar3 = QosNblCadDisassemble
                    (param_2,param_1,uVar6,param_6,in_stack_ffffffffffffffb8,(longlong *)&local_28,
                     param_7);
  uVar7 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if (param_4 != 0) {
    puVar4 = QosNblChainRemove(&local_28,param_1,local_28);
    *param_8 = (longlong)puVar4;
    lVar2 = puVar4[2];
    uVar1 = *(ushort *)(lVar2 + 10);
    lVar5 = lVar2 + 0x40 + (ulonglong)uVar1;
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
    *(undefined8 *)((ulonglong)uVar1 + 0x58 + lVar2) = *(undefined8 *)(param_3 + 0x10);
  }
  *param_9 = (longlong)local_28;
  for (; uVar3 = (ulonglong)param_4, local_28 != (undefined8 *)0x0;
      local_28 = (undefined8 *)*local_28) {
    lVar2 = local_28[2];
    uVar1 = *(ushort *)(lVar2 + 10);
    lVar5 = lVar2 + 0x40 + (ulonglong)uVar1;
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
    param_4 = param_4 + 1;
    *(undefined8 *)((ulonglong)uVar1 + 0x58 + lVar2) =
         *(undefined8 *)(uVar3 * 0x20 + 0x10 + param_3);
  }
LAB_140009694:
  return uVar7 & 0xffffffff;
}



===== QosSelectSlot @ 1400096b4 =====

uint QosSelectSlot(uint param_1,int param_2,uint param_3,longlong param_4)

{
  uint uVar1;
  char *pcVar2;
  
  for (; param_1 < param_3; param_1 = param_1 + 1) {
    pcVar2 = (char *)((ulonglong)param_1 + param_4);
    if (param_4 != 0) {
      do {
        if (*pcVar2 != '\0') break;
        param_1 = param_1 + 1;
        pcVar2 = pcVar2 + 1;
      } while (param_1 < param_3);
      if (param_3 <= param_1) break;
    }
    if (param_2 == 0) {
      return param_1;
    }
    param_2 = param_2 + -1;
  }
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_3 - 1;
  }
  return uVar1;
}



===== QosTbcAdjustBytesSent @ 140009700 =====

ulonglong QosTbcAdjustBytesSent(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x110) - param_2;
  if (lVar3 < 1) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x150);
    if (*(uint *)(param_1 + 0x150) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (ulonglong)(param_2 - *(longlong *)(param_1 + 0x110)) / uVar5;
    }
    *(ulonglong *)(param_1 + 0x180) = uVar4;
    *(ulonglong *)(param_1 + 0x110) = (uVar5 - (uVar5 + param_2) % uVar5) + param_2;
    uVar1 = *(uint *)(param_1 + 0x1a0);
    *(uint *)(param_1 + 0x1a0) = uVar1 | 1;
    if ((uVar1 & 4) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x154);
      *(uint *)(param_1 + 0x1a0) = uVar1 | 5;
    }
    else {
      uVar5 = QosTbcSmoothBytesRequested(param_1,uVar4);
      uVar2 = (undefined4)uVar5;
    }
    *(undefined4 *)(param_1 + 0x158) = uVar2;
    QosTbcSampleMaxBytesRequested(param_1,uVar4);
    lVar3 = QosTbcEndRcEpisode(param_1);
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  return CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(param_1 + 0x1a0)) &
         0xffffffffffffff01;
}



===== QosTbcAdjustSendWindow @ 1400097cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTbcAdjustSendWindow(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStack_98 [32];
  longlong local_78;
  undefined8 local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xfffffffe;
  uVar1 = *(uint *)(param_1 + 0x140);
  local_4c = 0;
  uVar3 = *(uint *)(param_2 + 0x14);
  uVar6 = *(uint *)(param_2 + 0xc);
  if (*(uint *)(param_2 + 0xc) <= uVar1) {
    uVar6 = uVar1;
  }
  if (*(uint *)(param_1 + 0x150) != uVar3) {
    if (uVar3 < 100) {
      uVar3 = 100;
    }
    *(uint *)(param_1 + 0x150) = uVar3;
    *(longlong *)(param_1 + 0x120) =
         (longlong)((ulonglong)*(uint *)(param_2 + 8) * (ulonglong)uVar1) /
         (longlong)(ulonglong)uVar6;
    QosTbcTuneParameters(param_1);
  }
  if (*(uint *)(param_1 + 0x144) != uVar6) {
    *(uint *)(param_1 + 0x144) = uVar6;
    QosTbcTuneParameters(param_1);
  }
  uVar1 = *(uint *)(param_2 + 0x10);
  if (*(uint *)(param_1 + 0x148) != uVar1) {
    uVar3 = *(uint *)(param_1 + 0x140);
    if (*(uint *)(param_1 + 0x140) <= uVar1) {
      uVar3 = uVar1;
    }
    *(uint *)(param_1 + 0x148) = uVar3;
    QosTbcTuneParameters(param_1);
  }
  if (*(longlong *)(param_2 + 0x18) == 0x7fffffffffffffff) {
    *(undefined4 *)(param_1 + 0x140) = 0;
    lVar4 = 0;
    local_50 = 0;
  }
  else {
    local_50 = *(uint *)(param_1 + 0x140);
    lVar4 = (longlong)((ulonglong)local_50 * *(longlong *)(param_2 + 0x18)) /
            (longlong)(ulonglong)uVar6;
    lVar2 = *(longlong *)(param_2 + 0x20);
    if ((0 < lVar2) && (lVar2 <= lVar4)) {
      lVar4 = lVar2;
    }
    if (*(int *)(param_1 + 0x174) != 0) {
      *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + -1;
    }
  }
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_78 = *(longlong *)(param_1 + 0x110) - (ulonglong)*(uint *)(param_1 + 0x150);
    local_60 = *(undefined4 *)(param_1 + 0x128);
    local_5c = *(undefined4 *)(param_1 + 300);
    local_58 = (undefined4)lVar4;
    local_54 = (local_50 * *(int *)(param_2 + 8)) / uVar6;
    local_48 = (ulonglong)*(uint *)(param_1 + 0x158);
    local_68 = param_1;
    uVar5 = QosTbcComputeDropRate(param_1);
    local_34 = *(undefined4 *)(param_1 + 0x19c);
    local_40 = (undefined4)uVar5;
    local_70 = *(undefined8 *)(param_1 + 0x180);
    if ((*(uint *)(param_1 + 0x1a0) & 8) == 0) {
      local_3c = 0;
      local_38 = 0;
      local_30 = 0;
    }
    else {
      local_3c = *(undefined4 *)(param_1 + 0x188);
      local_38 = *(undefined4 *)(param_1 + 0x194);
      local_30 = *(undefined4 *)(param_1 + 400);
    }
    local_2c = *(undefined4 *)(param_1 + 0x15c);
    QosTraceEvent(0,&local_78);
  }
  *(longlong *)(param_1 + 0x130) =
       *(longlong *)(param_1 + 0x130) + (ulonglong)*(uint *)(param_1 + 0x128);
  *(longlong *)(param_1 + 0x138) =
       *(longlong *)(param_1 + 0x138) + (ulonglong)*(uint *)(param_1 + 300);
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(longlong *)(param_1 + 0x118) = lVar4;
  return;
}



===== QosTbcComputeDropRate @ 140009a00 =====

ulonglong QosTbcComputeDropRate(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x140) != 0) {
    uVar1 = QosTbcSmoothBytesRequested(param_1,0);
    if ((int)uVar1 != 0) {
      lVar2 = (*(longlong *)(param_1 + 0x118) * 0x7fffffff) / (longlong)(uVar1 & 0xffffffff);
      if (0x7fffffff < lVar2) {
        lVar2 = 0x7fffffff;
      }
      lVar3 = 0;
      if (-1 < lVar2) {
        lVar3 = lVar2;
      }
      uVar4 = 0x7fffffff - lVar3;
    }
  }
  return uVar4 & 0xffffffff;
}



===== QosTbcComputeNbsToDrop @ 140009a64 =====

undefined4 QosTbcComputeNbsToDrop(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0x14c) == 1) {
    if ((longlong)(ulonglong)*(uint *)(param_1 + 0x128) <= *(longlong *)(param_1 + 0x118)) {
      param_2 = 0;
    }
    uVar5 = param_2;
  }
  else {
    uVar3 = QosTbcComputeDropRate(param_1);
    if (((uint)uVar3 != 0) && (*(int *)(param_1 + 0x174) == 0)) {
      uVar1 = *(uint *)(param_1 + 0x19c);
      uVar2 = *(uint *)(param_1 + 0x17c);
      if (0xe < uVar1) {
        uVar4 = uVar1 - 1;
        if (0x1f < uVar4) {
          uVar4 = 0x1f;
        }
        uVar2 = uVar2 / (uint)(1 << ((byte)uVar4 & 0x1f));
      }
      if (uVar2 < (uint)uVar3) {
        if ((((*(uint *)(param_1 + 0x1a0) & 8) == 0) && (uVar1 != 0x1f)) &&
           ((*(longlong *)(param_1 + 0x120) * 3) / 4 <= *(longlong *)(param_1 + 0x118))) {
          *(longlong *)(param_1 + 0x188) = *(longlong *)(param_1 + 0x118);
          *(undefined8 *)(param_1 + 0x194) = 0;
          *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xffffffef | 0x28;
        }
        uVar5 = 1;
        *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x178);
      }
    }
  }
  return uVar5;
}



===== QosTbcDropNbl @ 140009b58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void QosTbcDropNbl(longlong param_1,longlong *param_2,longlong param_3,int param_4,int param_5,
                  int param_6)

{
  undefined4 uVar1;
  undefined1 auStack_a8 [32];
  longlong local_88;
  int local_80;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(&local_88,0,0x50);
  if (*(int *)*QosgEtwDispatchTable == 1) {
    local_80 = param_6;
    local_88 = param_3;
    QosTraceEvent(4,&local_88);
  }
  uVar1 = 0xc000009a;
  if (1 < param_6 - 2U) {
    uVar1 = 0xc0000120;
  }
  *(undefined4 *)(param_3 + 0x8c) = uVar1;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_4;
  if (param_5 == param_4) {
    *param_2 = param_3;
  }
  return;
}



===== QosTbcEndRcEpisode @ 140009c0c =====

void QosTbcEndRcEpisode(longlong param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x1a0);
  if ((uVar3 & 8) != 0) {
    if ((uVar3 & 0x20) != 0) {
      iVar1 = *(int *)(param_1 + 0x15c);
      *(undefined4 *)(param_1 + 0x15c) = 0;
      *(undefined4 *)(param_1 + 0x164) = 0;
      *(undefined4 *)(param_1 + 0x160) = 0;
      uVar3 = uVar3 & 0xffffffdf;
      *(uint *)(param_1 + 400) = (uint)(iVar1 * 3) >> 2;
      *(uint *)(param_1 + 0x1a0) = uVar3;
    }
    *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
    if ((*(int *)(param_1 + 0x174) != 0) && ((uVar3 & 0x10) == 0)) {
      *(undefined4 *)(param_1 + 0x198) = 0;
      uVar3 = uVar3 | 0x10;
      *(uint *)(param_1 + 0x1a0) = uVar3;
    }
    if ((uVar3 & 0x10) != 0) {
      cVar2 = QosTbcEndRcMonitoring(param_1);
      if (cVar2 != '\0') {
        *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xfffffff7;
      }
    }
  }
  return;
}



===== QosTbcEndRcMonitoring @ 140009ca0 =====

char QosTbcEndRcMonitoring(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  char cVar4;
  
  cVar4 = '\0';
  if ((*(uint *)(param_1 + 0x1a0) & 0x10) != 0) {
    uVar3 = *(int *)(param_1 + 0x198) + 1;
    uVar2 = 10000 / (ulonglong)*(uint *)(param_1 + 0x150);
    *(uint *)(param_1 + 0x198) = uVar3;
    if ((uint)uVar2 < 0xb) {
      uVar2 = 10;
    }
    uVar1 = (ulonglong)uVar3 % uVar2;
    if ((int)uVar1 == 0) {
      if (*(uint *)(param_1 + 400) < *(uint *)(param_1 + 0x15c)) {
        if ((uint)uVar2 < *(uint *)(param_1 + 0x194)) {
          *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + 1;
        }
        *(undefined4 *)(param_1 + 0x174) = 0;
        cVar4 = '\0';
        uVar3 = 0x1f;
        if (*(uint *)(param_1 + 0x19c) < 0x1f) {
          uVar3 = *(uint *)(param_1 + 0x19c);
        }
        *(uint *)(param_1 + 0x19c) = uVar3;
        if (uVar3 == 0x1f) {
          cVar4 = '\x01';
        }
      }
      else {
        cVar4 = (char)uVar1 + '\x01';
      }
      *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) & 0xffffffef;
    }
  }
  return cVar4;
}



===== QosTbcFlowInitialize @ 140009d5c =====

undefined8 QosTbcFlowInitialize(longlong param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = KeGetCurrentProcessorNumberEx(0);
  uVar4 = QosTimerGetCurrentTime(uVar3,'\x01','\x01');
  lVar1 = param_1 + 0x60;
  *(longlong *)(param_1 + 0x68) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined4 *)(param_1 + 0x14c) = 0xffffffff;
  *(ulonglong *)(param_1 + 0x108) = uVar4;
  *(ulonglong *)(param_1 + 0x110) = uVar4;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = uVar4;
  *(undefined4 *)(param_1 + 0x150) = 100;
  *(ulonglong *)(param_1 + 0x100) = uVar4 / 600;
  *(undefined4 *)(param_1 + 0x19c) = 1;
  *(undefined8 *)(param_1 + 0xf0) = 250000000;
  return SUB168(ZEXT816(0x6d3a06d3a06d3a07) * auVar2,0);
}



===== QosTbcFlowUpdate @ 140009de8 =====

void QosTbcFlowUpdate(undefined4 *param_1,uint param_2,longlong *param_3,int *param_4,
                     ulonglong param_5,undefined4 *param_6,longlong *param_7,longlong *param_8)

{
  longlong ****pppplVar1;
  code *pcVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  longlong *plVar9;
  undefined1 uVar10;
  longlong ***ppplVar11;
  longlong ****pppplVar12;
  int local_res20 [2];
  uint in_stack_ffffffffffffff6c;
  longlong *local_78;
  longlong ****local_70;
  longlong ****local_68;
  longlong local_60;
  longlong *plStack_58;
  undefined8 local_50;
  longlong local_48;
  longlong *plStack_40;
  undefined8 local_38;
  
  param_5 = 0;
  local_68 = (longlong ****)&local_70;
  local_78 = (longlong *)0x0;
  local_res20[0] = 0;
  local_70 = (longlong ****)&local_70;
  local_50 = 0;
  local_60 = 0;
  plStack_58 = (longlong *)0x0;
  local_38 = 0;
  uVar10 = 1;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  uVar7 = QosTimerGetCurrentTime(param_2,'\x01','\x01');
  if (param_4 != (int *)0x0) {
    pppplVar1 = *(longlong *****)(param_1 + 0x1a);
    while (pppplVar12 = pppplVar1, pppplVar12 != (longlong ****)(param_1 + 0x18)) {
      pppplVar1 = (longlong ****)pppplVar12[1];
      if (*(int *)(pppplVar12 + 2) != *param_4) break;
      ppplVar11 = *pppplVar12;
      if (((longlong ****)ppplVar11[1] != pppplVar12) || ((longlong ****)*pppplVar1 != pppplVar12))
      goto LAB_14000a118;
      *pppplVar1 = ppplVar11;
      ppplVar11[1] = (longlong **)pppplVar1;
      if ((longlong *****)local_70[1] != &local_70) goto LAB_14000a118;
      *pppplVar12 = (longlong ***)local_70;
      pppplVar12[1] = (longlong ***)&local_70;
      local_70[1] = (longlong ***)pppplVar12;
      local_70 = pppplVar12;
    }
    if ((longlong *****)local_70 != &local_70) {
      param_1[0x20] = *(undefined4 *)(local_70 + 4);
      *(longlong ****)(param_1 + 0x1c) = local_70[5];
      *(longlong ****)(param_1 + 0x1e) = local_70[6];
      *(longlong ****)(param_1 + 0x22) = local_70[7];
      *(longlong ****)(param_1 + 0x38) = local_70[3];
      if (*(int *)*QosgEtwDispatchTable == 1) {
        QosTraceFlowConformance((longlong)param_1,uVar7,0);
      }
    }
  }
  param_1[0x16] = *(undefined4 *)((longlong)param_3 + 0x24);
  if (*(ulonglong *)(param_1 + 0x1c) < uVar7) {
    plVar9 = (longlong *)(param_1 + 0x22);
    QosUtilComputeTokenSpec(plVar9,uVar7 - *(ulonglong *)(param_1 + 0x1c));
    puVar3 = QosgEtwDispatchTable;
    param_1[0x20] = (int)*plVar9;
    *(ulonglong *)(param_1 + 0x1c) = uVar7;
    if (*(int *)*puVar3 == 1) {
      QosTraceFlowConformance((longlong)param_1,uVar7,1);
    }
  }
  QosUtilSetTokenSpec((longlong *)(param_1 + 0x22),param_3,*(longlong *)(param_1 + 0x24) == 0);
  if (*(int *)*QosgEtwDispatchTable == 1) {
    QosTraceFlowConformance((longlong)param_1,uVar7,2);
  }
  *(longlong *)(param_1 + 0x28) = param_3[2];
  iVar4 = 0;
  if ((int)param_3[4] != -1) {
    iVar4 = (int)param_3[4];
  }
  param_1[0x2a] = iVar4;
  iVar4 = param_1[0x16];
  if ((iVar4 == 3) || (*(longlong *)(param_1 + 0x26) == -1)) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  *(undefined1 *)((longlong)param_1 + 0x5d) = uVar8;
  if ((iVar4 != 1) && ((param_3[2] == -1 || (iVar4 == 3)))) {
    uVar10 = 0;
  }
  *(undefined1 *)(param_1 + 0x17) = uVar10;
  param_1[0x35] = (int)param_3[5];
  param_1[0x36] = *(undefined4 *)((longlong)param_3 + 0x2c);
  if (param_3[3] != 0) {
    *(longlong *)(param_1 + 0x3c) = param_3[3];
  }
  uVar6 = *(uint *)(param_3 + 7);
  if (uVar6 != 0xffffffff) {
    param_1[0x50] = uVar6;
    param_1[0x53] = 2;
    uVar5 = uVar6;
    if (uVar6 <= (uint)param_1[0x51]) {
      uVar5 = param_1[0x51];
    }
    param_1[0x51] = uVar5;
    if (uVar6 <= (uint)param_1[0x52]) {
      uVar6 = param_1[0x52];
    }
    param_1[0x52] = uVar6;
    QosTbcTuneParameters((longlong)param_1);
  }
  while ((longlong *****)local_70 != &local_70) {
    param_5 = 0;
    local_78 = (longlong *)0x0;
    if (((longlong *****)local_70[1] != &local_70) ||
       (pppplVar1 = (longlong ****)*local_70, (longlong ****)pppplVar1[1] != local_70))
    goto LAB_14000a118;
    pppplVar1[1] = (longlong ***)&local_70;
    ppplVar11 = local_70[-3];
    pppplVar12 = local_70;
    local_70 = pppplVar1;
    uVar6 = QosGetNetBufferCount((longlong)ppplVar11,local_res20);
    QosTbcSendNetBufferList
              (param_1,param_2,pppplVar12[-2],(ulonglong)ppplVar11,uVar6,local_res20[0],
               (ulonglong)in_stack_ffffffffffffff6c << 0x20,&param_5,(longlong *)&local_78);
    if (param_5 != 0) {
      QosNblChainInsert(&local_60,plStack_58,(longlong *)param_5);
    }
    if (local_78 != (longlong *)0x0) {
      QosNblChainInsert(&local_48,plStack_40,local_78);
    }
  }
LAB_14000a11f:
  *param_7 = local_60;
  *param_8 = local_48;
  *param_6 = (undefined4)local_50;
  return;
LAB_14000a118:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  goto LAB_14000a11f;
}



===== QosTbcFrontalSpread @ 14000a164 =====

void QosTbcFrontalSpread(ulonglong param_1,ulonglong param_2,uint param_3,uint param_4,
                        ulonglong *param_5,uint *param_6,longlong param_7,uint param_8,int *param_9)

{
  ulonglong *puVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  ulonglong local_res8;
  
  piVar2 = param_9;
  puVar1 = param_5;
  uVar7 = (ulonglong)param_4;
  uVar3 = *param_5;
  if (uVar3 < param_1) {
    uVar5 = uVar3 + param_4;
    *param_6 = param_3;
    uVar3 = param_1;
    if (param_1 < uVar5) {
      uVar3 = uVar5;
    }
    *param_5 = uVar3;
  }
  if (param_2 <= uVar3) {
    param_2 = ((ulonglong)QosgBoundaryPeriod -
              ((QosgBoundaryPeriod - param_2) + uVar3) % (ulonglong)QosgBoundaryPeriod) + uVar3;
  }
  param_5._0_4_ = 0;
  local_res8 = (param_2 - uVar3) / uVar7;
  *param_9 = 0;
  if (param_8 != 0) {
    puVar6 = (ulonglong *)(param_7 + 0x10);
    uVar5 = uVar3;
    param_9 = (int *)(ulonglong)param_8;
    do {
      if (param_2 <= *puVar6) {
        if (uVar3 < param_2) {
          uVar3 = uVar7 + uVar3;
          *param_6 = param_3;
          if (uVar3 <= param_2) {
            uVar3 = param_2;
          }
          *puVar1 = uVar3;
        }
        param_2 = param_2 + QosgBoundaryPeriod;
        local_res8 = (param_2 - uVar3) / uVar7;
        param_5._0_4_ = 0;
        uVar5 = uVar3;
      }
      uVar3 = QosAssignSlot(*(uint *)((longlong)puVar6 + 0xc),param_3,(uint)local_res8,0,
                            (uint *)&param_5,param_6);
      uVar4 = (int)uVar3 * param_4 + uVar5;
      uVar3 = param_4 * (int)param_5 + uVar5;
      *puVar1 = uVar3;
      *puVar6 = uVar4;
      if (uVar4 == param_1) {
        *piVar2 = *piVar2 + 1;
      }
      puVar6 = puVar6 + 4;
      param_9 = (int *)((longlong)param_9 + -1);
    } while (param_9 != (int *)0x0);
  }
  return;
}



===== QosTbcProcessQueuedNetBufferLists @ 14000a2ec =====

/* WARNING: Removing unreachable block (ram,0x00014000a390) */

bool QosTbcProcessQueuedNetBufferLists(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  int iVar15;
  int local_res8;
  longlong *in_stack_00000030;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  uint local_68;
  int local_64;
  int local_60;
  longlong local_58;
  longlong *plStack_50;
  undefined8 local_48;
  
  local_res8 = 0;
  *in_stack_00000030 = 0;
  local_68 = 0;
  uVar11 = QosTimerGetCurrentTime(param_2,'\0','\x01');
  local_48 = 0;
  local_58 = 0;
  plStack_50 = (longlong *)0x0;
  if ((QosgLastSendBoundary == 0) ||
     (uVar12 = QosgBoundaryPeriod + QosgLastSendBoundary, uVar12 <= uVar11)) {
    uVar12 = QosgBoundaryPeriod + uVar11;
    bVar9 = true;
    QosgLastSendBoundary = uVar11;
  }
  else {
    bVar9 = false;
  }
  LOCK();
  UNLOCK();
  if ((bVar9) && (*(uint *)(param_1 + 0xd4) != 0)) {
    QosTbcRandomSpread(*(uint *)(param_1 + 0xd4),*(uint *)(param_1 + 0xd8),
                       (undefined8 *)(param_1 + 0x60),uVar11,uVar12);
  }
  iVar15 = 0;
  plVar14 = *(longlong **)(param_1 + 0x60);
  do {
    puVar13 = auStackY_b8;
    if (plVar14 == (longlong *)(param_1 + 0x60)) {
LAB_14000a553:
      puVar6 = *(undefined8 **)(puVar13 + 0xe8);
      iVar10 = *(int *)(puVar13 + 0x44);
      *puVar6 = 0;
      plVar14 = *(longlong **)(param_1 + 0x60);
      iVar2 = *(int *)(puVar13 + 0x40);
      *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + iVar15;
      *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + iVar2;
      LOCK();
      *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar10;
      UNLOCK();
      LOCK();
      *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + *(int *)(puVar13 + 0x48);
      UNLOCK();
      plVar3 = *(longlong **)(puVar13 + 0xd0);
      puVar7 = *(undefined8 **)(puVar13 + 0xd8);
      *plVar3 = *(longlong *)(puVar13 + 0x60);
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = *(undefined8 *)(puVar13 + 0x68);
      }
      **(undefined4 **)(puVar13 + 0xe0) = *(undefined4 *)(puVar13 + 0x4c);
      if (*(undefined8 **)(puVar13 + 0xf0) != (undefined8 *)0x0) {
        **(undefined8 **)(puVar13 + 0xf0) = *puVar6;
      }
      lVar4 = *plVar3;
      if (lVar4 != 0) {
        LOCK();
        piVar1 = (int *)(*(longlong *)(lVar4 + 0x60) + 0x30);
        *piVar1 = *piVar1 + local_res8;
        UNLOCK();
      }
      if (*(int *)*QosgEtwDispatchTable == 1) {
        *(undefined4 *)(puVar13 + 0x30) = 0;
        *(int *)(puVar13 + 0x28) = iVar15;
        *(undefined4 *)(puVar13 + 0x20) = 0;
        *(undefined8 *)(puVar13 + -8) = 0x14000a61a;
        QosTraceFlowSendQueue
                  (param_1,2,uVar11,0,*(undefined4 *)(puVar13 + 0x20),
                   *(undefined4 *)(puVar13 + 0x28),*(undefined4 *)(puVar13 + 0x30));
      }
      return plVar14 != (longlong *)(param_1 + 0x60);
    }
    plVar3 = (longlong *)*plVar14;
    local_64 = QosGetNetBufferCount(plVar14[-3],(int *)&local_68);
    uVar12 = (ulonglong)local_68;
    local_60 = iVar15 + local_68;
    puVar13 = auStackY_b8;
    if (0xfa < (longlong)(plVar14[3] - uVar11)) {
LAB_14000a54b:
      local_res8 = *(int *)(puVar13 + 0xc0);
      goto LAB_14000a553;
    }
    if (*(int *)(param_1 + 0x140) == 0) {
LAB_14000a4e3:
      lVar4 = *plVar14;
      if ((*(longlong **)(lVar4 + 8) != plVar14) ||
         (plVar5 = (longlong *)plVar14[1], (longlong *)*plVar5 != plVar14)) goto LAB_14000a53e;
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      iVar15 = local_60;
      iVar10 = local_64;
      QosNblChainInsert(&local_58,plStack_50,(longlong *)plVar14[-3]);
      *(longlong *)(param_1 + 0x18) = *(longlong *)(param_1 + 0x18) + uVar12;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar10;
      local_res8 = local_res8 + -1;
      plVar14 = plVar3;
    }
    else {
      if (*(char *)((longlong)plVar14 + -3) == '\0') {
        *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + local_68;
      }
      iVar10 = QosTbcComputeNbsToDrop(param_1,1);
      if (iVar10 == 0) {
        iVar10 = 1;
      }
      else {
        iVar10 = 0;
        if (*(int *)(param_1 + 0x14c) == 1) {
          iVar10 = 2;
        }
      }
      if (iVar10 != 0) {
        puVar13 = auStackY_b8;
        if (iVar10 != 1) goto LAB_14000a54b;
        goto LAB_14000a4e3;
      }
      lVar4 = *plVar14;
      if ((*(longlong **)(lVar4 + 8) != plVar14) ||
         (plVar5 = (longlong *)plVar14[1], (longlong *)*plVar5 != plVar14)) {
LAB_14000a53e:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar13 = auStackY_b0;
        goto LAB_14000a54b;
      }
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      QosTbcDropNbl(param_1,in_stack_00000030,plVar14[-3],local_64,local_64,7);
      in_stack_00000030 = (longlong *)plVar14[-3];
      plVar14 = plVar3;
    }
  } while( true );
}



===== QosTbcRandomSpread @ 14000a640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
QosTbcRandomSpread(uint param_1,uint param_2,undefined8 *param_3,ulonglong param_4,ulonglong param_5
                  )

{
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  byte *pbVar11;
  longlong lVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined1 uVar15;
  undefined8 *puVar16;
  undefined1 auStackY_118 [32];
  uint local_e8;
  uint local_e4;
  uint local_e0;
  ulonglong local_d8;
  byte local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar6 = QosgBoundaryPeriod / param_2;
  if (uVar6 < 0x41) {
    for (puVar13 = (undefined8 *)*param_3; (puVar13 != param_3 && ((ulonglong)puVar13[3] < param_4))
        ; puVar13 = (undefined8 *)*puVar13) {
    }
    uVar14 = 0;
    local_c8[0] = 1;
    local_c8[1] = 1;
    local_c8[2] = 1;
    local_c8[3] = 1;
    local_c8[4] = 1;
    local_c8[5] = 1;
    local_c8[6] = 1;
    local_c8[7] = 1;
    local_c8[8] = 1;
    local_c8[9] = 1;
    local_c8[10] = 1;
    local_c8[0xb] = 1;
    local_c8[0xc] = 1;
    local_c8[0xd] = 1;
    local_c8[0xe] = 1;
    local_c8[0xf] = 1;
    bVar5 = false;
    uVar10 = 0;
    local_c8[0x10] = 1;
    local_c8[0x11] = 1;
    local_c8[0x12] = 1;
    local_c8[0x13] = 1;
    local_c8[0x14] = 1;
    local_c8[0x15] = 1;
    local_c8[0x16] = 1;
    local_c8[0x17] = 1;
    local_c8[0x18] = 1;
    local_c8[0x19] = 1;
    local_c8[0x1a] = 1;
    local_c8[0x1b] = 1;
    local_c8[0x1c] = 1;
    local_c8[0x1d] = 1;
    local_c8[0x1e] = 1;
    local_c8[0x1f] = 1;
    local_c8[0x20] = 1;
    local_c8[0x21] = 1;
    local_c8[0x22] = 1;
    local_c8[0x23] = 1;
    local_c8[0x24] = 1;
    local_c8[0x25] = 1;
    local_c8[0x26] = 1;
    local_c8[0x27] = 1;
    local_c8[0x28] = 1;
    local_c8[0x29] = 1;
    local_c8[0x2a] = 1;
    local_c8[0x2b] = 1;
    local_c8[0x2c] = 1;
    local_c8[0x2d] = 1;
    local_c8[0x2e] = 1;
    local_c8[0x2f] = 1;
    local_e4 = 0;
    local_c8[0x30] = 1;
    local_c8[0x31] = 1;
    local_c8[0x32] = 1;
    local_c8[0x33] = 1;
    local_c8[0x34] = 1;
    local_c8[0x35] = 1;
    local_c8[0x36] = 1;
    local_c8[0x37] = 1;
    local_c8[0x38] = 1;
    local_c8[0x39] = 1;
    local_c8[0x3a] = 1;
    local_c8[0x3b] = 1;
    local_c8[0x3c] = 1;
    local_c8[0x3d] = 1;
    local_c8[0x3e] = 1;
    local_c8[0x3f] = 1;
    puVar16 = puVar13;
    local_e8 = param_1;
    local_e0 = param_2;
    local_d8 = param_4;
    while (puVar16 != param_3) {
      puVar3 = (undefined8 *)*puVar16;
      if (param_5 <= (ulonglong)puVar16[3]) {
        bVar5 = true;
        break;
      }
      uVar8 = QosAssignSlot(*(uint *)(*(longlong *)(puVar16[-3] + 8) + 0x18),param_1,0x40,
                            (longlong)local_c8,&local_e4,&local_e8);
      uVar10 = (int)uVar8 + 1;
      puVar16 = puVar3;
    }
    if (uVar6 <= uVar10) {
      bVar5 = true;
      uVar10 = uVar6;
    }
    if (bVar5) {
      memset(local_c8,0,0x40);
      uVar7 = 0;
      pbVar11 = local_c8 + 0x40;
      uVar15 = 1;
      do {
        *pbVar11 = (byte)uVar7;
        uVar7 = uVar7 + 1;
        pbVar11 = pbVar11 + 1;
      } while (uVar7 < 0x40);
      if (uVar10 != 0) {
        pbVar11 = local_c8 + 0x40;
        do {
          uVar8 = (ulonglong)QosgRandomValue * 0x7fffffed + 0x7fffffc3;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar8;
          lVar12 = SUB168(ZEXT816(0x200000005) * auVar4,8);
          QosgRandomValue = (int)uVar8 + (int)((uVar8 - lVar12 >> 1) + lVar12 >> 0x1e) * -0x7fffffff
          ;
          bVar1 = *pbVar11;
          uVar8 = (ulonglong)(QosgRandomValue % (uVar6 - uVar14) + uVar14);
          uVar14 = uVar14 + 1;
          bVar2 = local_c8[uVar8 + 0x40];
          *pbVar11 = bVar2;
          pbVar11 = pbVar11 + 1;
          local_c8[uVar8 + 0x40] = bVar1;
          local_c8[bVar2] = 1;
        } while (uVar14 < uVar10);
      }
      local_e8 = param_1;
      local_e4 = QosSelectSlot(0,0,uVar10,(longlong)local_c8);
      uVar8 = local_d8;
      uVar10 = local_e0;
      if (puVar13 != param_3) {
        do {
          puVar16 = (undefined8 *)*puVar13;
          if (param_5 <= (ulonglong)puVar13[3]) break;
          uVar9 = QosAssignSlot(*(uint *)(*(longlong *)(puVar13[-3] + 8) + 0x18),param_1,uVar6,
                                (longlong)local_c8,&local_e4,&local_e8);
          puVar13[3] = (int)uVar9 * uVar10 + uVar8;
          puVar13 = puVar16;
        } while (puVar16 != param_3);
        uVar15 = 1;
      }
      return uVar15;
    }
  }
  return 0;
}



===== QosTbcSampleMaxBytesRequested @ 14000a898 =====

int QosTbcSampleMaxBytesRequested(longlong param_1,ulonglong param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = 10000 / (ulonglong)*(uint *)(param_1 + 0x150);
  if ((uint)uVar5 < 0xb) {
    uVar5 = 10;
  }
  uVar4 = uVar5;
  if (param_2 < uVar5) {
    uVar4 = param_2;
  }
  uVar2 = (int)uVar4 + *(int *)(param_1 + 0x164) + 1;
  *(uint *)(param_1 + 0x164) = uVar2;
  if ((uint)uVar5 <= uVar2) {
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(int *)(param_1 + 0x164) = (int)((ulonglong)uVar2 % uVar5);
  }
  iVar1 = *(int *)(param_1 + 0x15c);
  iVar3 = iVar1 * 7;
  if ((uint)(iVar1 * 0x19) / 100 <= *(uint *)(param_1 + 0x154)) {
    *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    iVar3 = (int)(*(uint *)(param_1 + 0x154) - iVar1) / *(int *)(param_1 + 0x160) + iVar1;
    *(int *)(param_1 + 0x15c) = iVar3;
  }
  return iVar3;
}



===== QosTbcSendNetBufferList @ 14000a940 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
QosTbcSendNetBufferList
          (undefined4 *param_1,uint param_2,undefined8 *param_3,ulonglong param_4,uint param_5,
          int param_6,undefined8 param_7,ulonglong *param_8,longlong *param_9)

{
  uint *puVar1;
  int *piVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  ulonglong *_Dst;
  ulonglong uVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined8 *puVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  longlong *plVar22;
  uint uVar23;
  bool bVar24;
  undefined1 auStackY_1f8 [8];
  undefined1 auStackY_1f0 [24];
  ulonglong *in_stack_fffffffffffffe28;
  uint local_1a4;
  uint local_1a0;
  uint local_19c;
  longlong *local_198;
  ulonglong local_190;
  undefined4 local_188;
  int local_184;
  ulonglong local_180;
  ulonglong local_178;
  undefined8 *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  longlong *local_150;
  ulonglong local_148;
  ulonglong *local_140;
  ulonglong local_138;
  undefined8 uStack_130;
  ulonglong local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  ulonglong local_f8 [20];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1f8;
  uVar21 = (ulonglong)param_5;
  local_140 = param_8;
  local_198 = param_9;
  local_148 = 0;
  local_150 = (longlong *)0x0;
  local_19c = 0;
  local_184 = 0;
  local_168 = 0;
  local_188 = 0;
  local_110 = 0;
  local_158 = 0;
  *(undefined8 **)(param_4 + 0x60) = param_3;
  local_120 = 0;
  uStack_118 = 0;
  local_190 = param_4;
  local_170 = param_3;
  if (param_5 < 6) {
    _Dst = local_f8;
LAB_14000a9e7:
    puVar16 = auStackY_1f8;
    memset(_Dst,0,uVar21 << 5);
    uVar8 = 0;
    for (puVar19 = *(undefined8 **)(param_4 + 8); puVar19 != (undefined8 *)0x0;
        puVar19 = (undefined8 *)*puVar19) {
      lVar14 = uVar8 * 0x20;
      uVar8 = (ulonglong)((int)uVar8 + 1);
      *(undefined4 *)(lVar14 + 0x1c + (longlong)_Dst) = *(undefined4 *)(puVar19 + 3);
    }
    uVar8 = QosTimerGetCurrentTime(param_2,'\0','\x01');
    local_180 = 0;
    LOCK();
    bVar24 = QosgLastSendBoundary == 0;
    if (bVar24) {
      QosgLastSendBoundary = uVar8;
    }
    else {
      local_180 = QosgLastSendBoundary;
    }
    UNLOCK();
    if (bVar24) {
      local_180 = uVar8;
    }
    else if (uVar8 < local_180) {
      uVar8 = local_180;
    }
    uVar11 = (ulonglong)QosgBoundaryPeriod;
    local_178 = (uVar11 - ((uVar11 - local_180) + uVar8) % uVar11) + uVar8;
    if (*(char *)((longlong)param_1 + 0x5d) == '\0') {
      if (*(int *)*QosgEtwDispatchTable == 1) {
        QosTraceFlowConformance((longlong)param_1,uVar8,3);
      }
      local_138 = *(ulonglong *)(param_1 + 0x22);
      uStack_130 = *(undefined8 *)(param_1 + 0x24);
      uVar11 = *(ulonglong *)(param_1 + 0x1c);
      local_128 = *(ulonglong *)(param_1 + 0x26);
      if (uVar11 < uVar8) {
        QosUtilComputeTokenSpec((longlong *)&local_138,uVar8 - uVar11);
        param_1[0x20] = param_1[0x22];
        *_Dst = uVar8;
        uVar11 = uVar8;
      }
      else {
        *_Dst = uVar11;
        local_138 = (ulonglong)(uint)param_1[0x20];
      }
      uVar20 = 0;
      uVar23 = 0;
      uVar17 = (uint)local_138;
      for (puVar19 = *(undefined8 **)(param_4 + 8); puVar19 != (undefined8 *)0x0;
          puVar19 = (undefined8 *)*puVar19) {
        uVar18 = *(uint *)(puVar19 + 3);
        if (uVar17 < uVar18) {
          uVar12 = ((ulonglong)(uVar18 - uVar17) * 1000000) / local_128 + uVar11;
          _Dst[uVar20 * 4] = uVar12;
          if ((uVar12 == uVar11) && (uVar11 == uVar8)) {
            uVar23 = uVar23 + 1;
          }
          uVar17 = 0;
        }
        else {
          uVar23 = uVar23 + 1;
          _Dst[uVar20 * 4] = uVar11;
          uVar17 = uVar17 - uVar18;
          uVar12 = uVar11;
        }
        uVar20 = (ulonglong)((int)uVar20 + 1);
        uVar11 = uVar12;
      }
      iVar6 = param_5 - uVar23;
      param_1[0x2b] = param_1[0x2b] + iVar6;
      LOCK();
      *(int *)((longlong)local_170 + 0x54) = *(int *)((longlong)local_170 + 0x54) + iVar6;
      UNLOCK();
      QosUpdateGenerationOverQuota
                (uVar8,iVar6 != 0,(ulonglong *)(param_1 + 0x3e),(ulonglong *)(param_1 + 0x40));
      if ((param_1[0x16] != 2) || (param_5 <= uVar23)) {
        local_160 = *(undefined8 *)(param_1 + 0x26);
        local_120 = *(undefined8 *)(param_1 + 0x22);
        uStack_118 = *(undefined8 *)(param_1 + 0x24);
        local_168 = *(undefined8 *)(param_1 + 0x1c);
        local_188 = param_1[0x20];
        local_158 = *(undefined8 *)(param_1 + 0x1e);
        *(ulonglong *)(param_1 + 0x1c) = _Dst[(ulonglong)(param_5 - 1) * 4];
        *(ulonglong *)(param_1 + 0x22) = local_138;
        *(undefined8 *)(param_1 + 0x24) = uStack_130;
        *(ulonglong *)(param_1 + 0x26) = local_128;
        *(ulonglong *)(param_1 + 0x22) = (ulonglong)uVar17;
        puVar19 = QosgEtwDispatchTable;
        param_1[0x20] = uVar17;
        local_110 = local_160;
        local_108 = local_120;
        uStack_100 = uStack_118;
        if (*(int *)*puVar19 == 1) {
          QosTraceFlowConformance((longlong)param_1,uVar8,4);
        }
        goto LAB_14000acb5;
      }
      iVar6 = 0;
LAB_14000abf9:
      QosTbcDropNbl((longlong)param_1,local_198,param_4,param_5,param_5,iVar6);
    }
    else {
      if (param_5 != 0) {
        puVar9 = _Dst;
        uVar11 = uVar21;
        do {
          *puVar9 = uVar8;
          puVar9 = puVar9 + 4;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      local_160 = local_110;
      local_108 = local_120;
      uStack_100 = uStack_118;
LAB_14000acb5:
      uVar11 = (ulonglong)param_5;
      if (*(longlong *)(param_1 + 0x28) == -1) {
        if (param_5 == 0) goto LAB_14000ad37;
        puVar9 = _Dst + 2;
        do {
          puVar9[-1] = puVar9[-2];
          *puVar9 = puVar9[-2];
          puVar9 = puVar9 + 4;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
        local_1a0 = 0;
LAB_14000ad44:
        local_1a0 = 0;
        uVar17 = 0;
        puVar9 = _Dst + 2;
        do {
          uVar11 = *puVar9;
          if (uVar11 < local_178) {
            uVar17 = uVar17 + 1;
            local_1a0 = local_1a0 + *(int *)((longlong)puVar9 + 0xc);
            uVar11 = uVar8;
          }
          else {
            uVar11 = uVar11 - (uVar11 - local_180) % (ulonglong)QosgBoundaryPeriod;
          }
          *puVar9 = uVar11;
          uVar21 = uVar21 - 1;
          puVar9 = puVar9 + 4;
        } while (uVar21 != 0);
      }
      else {
        uVar20 = *(ulonglong *)(param_1 + 0x1e);
        if (uVar20 < uVar8) {
          uVar20 = uVar8;
        }
        _Dst[1] = uVar20;
        uVar12 = *(ulonglong *)(param_1 + 0x28);
        if (param_5 != 0) {
          puVar9 = _Dst + 2;
          do {
            puVar9[-1] = uVar20;
            uVar10 = uVar20;
            if (uVar20 <= puVar9[-2]) {
              uVar10 = puVar9[-2];
            }
            *puVar9 = uVar10;
            puVar1 = (uint *)((longlong)puVar9 + 0xc);
            puVar9 = puVar9 + 4;
            uVar20 = uVar20 + ((ulonglong)*puVar1 * 1000000) / uVar12;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        *(ulonglong *)(param_1 + 0x1e) =
             ((ulonglong)*(uint *)((ulonglong)(param_5 - 1) * 0x20 + 0x1c + (longlong)_Dst) *
             1000000) / *(ulonglong *)(param_1 + 0x28) + _Dst[(ulonglong)(param_5 - 1) * 4 + 1];
LAB_14000ad37:
        uVar17 = 0;
        local_1a0 = 0;
        if (param_5 != 0) goto LAB_14000ad44;
      }
      if (param_1[0x50] == 0) {
        local_1a4 = uVar17;
LAB_14000ae8f:
        local_190 = *(ulonglong *)(param_1 + 0x38);
        local_1a0 = param_1[0x3a];
        if (param_1[0x35] != 0) {
          in_stack_fffffffffffffe28 = &local_190;
          QosTbcFrontalSpread(uVar8,local_178,param_1[0x35],param_1[0x36],in_stack_fffffffffffffe28,
                              &local_1a0,(longlong)_Dst,param_5,(int *)&local_1a4);
          uVar17 = local_1a4;
        }
        puVar19 = local_170;
        iVar6 = 1;
        if (((param_1[0x16] == 1) && (uVar8 < _Dst[(ulonglong)(param_5 - 1) * 4 + 2])) &&
           (*(ulonglong *)(param_1 + 0x3c) < _Dst[(ulonglong)(param_5 - 1) * 4 + 2] - uVar8)) {
          QosTbcDropNbl((longlong)param_1,local_198,param_4,param_5,param_5,1);
          if (_Dst != local_f8) {
            ExFreePoolWithTag(_Dst,0);
          }
          *(undefined8 *)(param_1 + 0x1c) = local_168;
          *(undefined8 *)(param_1 + 0x22) = local_108;
          *(undefined8 *)(param_1 + 0x24) = uStack_100;
          param_1[0x20] = local_188;
          *(undefined8 *)(param_1 + 0x26) = local_160;
          *(undefined8 *)(param_1 + 0x1e) = local_158;
          goto LAB_14000b238;
        }
        if ((*(char *)(param_1 + 0x17) != '\0') && (uVar17 != param_5)) {
          uVar11 = QosConstructNetBufferListToSend
                             (local_170,param_4,(longlong)_Dst,uVar17,in_stack_fffffffffffffe28,
                              -(uint)(param_1[0x16] != 2),'\0',(longlong *)&local_148,
                              (longlong *)&local_150);
          uVar21 = local_178;
          if (-1 < (int)uVar11) {
            uVar23 = param_1[0x34] + uVar17;
            param_1[0x34] = uVar23;
            if ((uint)param_1[0x2c] < uVar23) {
              param_1[0x2c] = uVar23;
            }
            LOCK();
            piVar2 = (int *)(puVar19 + 6);
            iVar6 = *piVar2;
            *piVar2 = *piVar2 + uVar17;
            UNLOCK();
            if (*(uint *)(puVar19 + 0xb) < iVar6 + local_1a4) {
              LOCK();
              if (*(uint *)(puVar19 + 0xb) == *(uint *)(puVar19 + 0xb)) {
                *(uint *)(puVar19 + 0xb) = iVar6 + local_1a4;
              }
              UNLOCK();
            }
            iVar6 = 0;
            *(ulonglong *)(param_1 + 0x38) = local_190;
            param_1[0x3a] = local_1a0;
            if (local_150 != (longlong *)0x0) {
              plVar15 = local_150;
              plVar22 = local_150;
              iVar6 = 0;
              do {
                plVar13 = local_198;
                lVar14 = plVar15[2];
                uVar11 = (ulonglong)*(ushort *)(lVar14 + 10);
                *(undefined4 *)(uVar11 + 0x60 + lVar14) = param_1[0x20];
                *(undefined8 *)(uVar11 + 0x68 + lVar14) = *(undefined8 *)(param_1 + 0x1c);
                *(undefined8 *)(uVar11 + 0x70 + lVar14) = *(undefined8 *)(param_1 + 0x1e);
                *(undefined8 *)(uVar11 + 0x78 + lVar14) = *(undefined8 *)(param_1 + 0x22);
                *(undefined4 *)(uVar11 + 0x50 + lVar14) = *param_1;
                plVar3 = (longlong *)*plVar15;
                *plVar15 = 0;
                plVar15[0xc] = (longlong)puVar19;
                bVar24 = *(ulonglong *)(uVar11 + 0x58 + lVar14) < uVar21;
                *(bool *)(uVar11 + 0x3d + lVar14) = bVar24;
                if (((!bVar24) || (param_1[0x50] == 0)) || (param_1[0x53] != 2)) {
                  plVar15 = *(longlong **)(param_1 + 0x1a);
                  plVar13 = (longlong *)(lVar14 + 0x40 + uVar11);
                  if ((undefined4 *)*plVar15 != param_1 + 0x18) {
                    pcVar4 = (code *)swi(0x29);
                    (*pcVar4)(3);
                    puVar16 = auStackY_1f0;
                    goto LAB_14000b154;
                  }
                  plVar13[1] = (longlong)plVar15;
                  *plVar13 = (longlong)(param_1 + 0x18);
                  *plVar15 = (longlong)plVar13;
                  *(longlong **)(param_1 + 0x1a) = plVar13;
                  QosGetNetBufferCount((longlong)plVar22,&local_184);
                  iVar6 = iVar6 + local_184;
                }
                else {
                  local_198 = plVar15;
                  *plVar13 = (longlong)plVar15;
                }
                plVar15 = plVar3;
              } while (plVar3 != (longlong *)0x0);
            }
            if (local_148 == 0) {
LAB_14000b154:
              uVar17 = *(uint *)(puVar16 + 0x5c);
            }
            else {
              param_1[0x31] = param_1[0x31] + 1;
              uVar21 = local_148;
              iVar7 = QosGetNetBufferCount(local_148,(int *)&local_19c);
              param_1[3] = param_1[3] + iVar7;
              *(ulonglong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + (ulonglong)local_19c;
              param_1[0x4a] = param_1[0x4a] + local_19c;
              *(undefined8 **)(uVar21 + 0x60) = puVar19;
              *local_140 = uVar21;
              puVar16 = auStackY_1f8;
              uVar17 = local_19c;
            }
            if (*(int *)*QosgEtwDispatchTable == 1) {
              *(int *)(puVar16 + 0x30) = iVar6;
              *(uint *)(puVar16 + 0x28) = uVar17;
              *(int *)(puVar16 + 0x20) = param_6;
              *(undefined8 *)(puVar16 + -8) = 0x14000b18c;
              QosTraceFlowSendQueue
                        ((longlong)param_1,1,uVar8,0,*(undefined4 *)(puVar16 + 0x20),
                         *(undefined4 *)(puVar16 + 0x28),*(undefined4 *)(puVar16 + 0x30));
            }
            if (_Dst != local_f8) {
              *(undefined8 *)(puVar16 + -8) = 0x14000b1a1;
              ExFreePoolWithTag(_Dst,0);
            }
            uVar5 = puVar16[0x50];
            goto LAB_14000b23a;
          }
          iVar6 = 3;
          goto LAB_14000abf9;
        }
        param_1[0x2f] = param_1[0x2f] + 1;
        param_1[0x2e] = param_1[0x2e] + 1;
        param_1[0x31] = param_1[0x31] + 1;
        iVar7 = QosGetNetBufferCount(param_4,(int *)&local_19c);
        param_1[3] = param_1[3] + iVar7;
        *(ulonglong *)(param_1 + 6) = *(longlong *)(param_1 + 6) + (ulonglong)local_19c;
        param_1[0x4a] = param_1[0x4a] + local_19c;
        if (*(int *)*QosgEtwDispatchTable == iVar6) {
          QosTraceFlowSendQueue((longlong)param_1,iVar6,uVar8,0,local_19c,local_19c,0);
        }
        *(undefined8 **)(param_4 + 0x60) = local_170;
        *local_140 = param_4;
      }
      else {
        param_1[0x55] = param_1[0x55] + local_1a0;
        if (uVar17 == 0) {
          iVar6 = 0;
          uVar18 = 0;
          uVar23 = 0;
LAB_14000ae40:
          local_1a4 = uVar18;
        }
        else {
          if ((param_1[0x68] & 2) != 0) {
            iVar6 = QosTbcComputeNbsToDrop((longlong)param_1,1);
            uVar23 = iVar6 * param_5;
            iVar6 = (1 - iVar6) * param_6;
            uVar18 = param_5 - uVar23;
            goto LAB_14000ae40;
          }
          uVar23 = QosTbcComputeNbsToDrop((longlong)param_1,uVar17);
          uVar18 = 0;
          iVar6 = 0;
          local_1a4 = 0;
          if (uVar17 != uVar23) {
            do {
              uVar21 = (ulonglong)uVar18;
              uVar18 = uVar18 + 1;
              iVar6 = iVar6 + *(int *)(uVar21 * 0x20 + 0x1c + (longlong)_Dst);
            } while (uVar18 < uVar17 - uVar23);
            goto LAB_14000ae40;
          }
        }
        uVar17 = local_1a4;
        if (param_1[0x53] == 1) {
LAB_14000ae8a:
          param_4 = local_190;
          goto LAB_14000ae8f;
        }
        if (uVar23 != 0) {
          in_stack_fffffffffffffe28 =
               (ulonglong *)CONCAT44((int)((ulonglong)in_stack_fffffffffffffe28 >> 0x20),uVar23);
          QosTbcDropNbl((longlong)param_1,local_198,local_190,param_5,uVar23,7);
        }
        param_1[0x4b] = param_1[0x4b] + (local_1a0 - iVar6);
        if (uVar23 != param_5) goto LAB_14000ae8a;
      }
    }
    if (_Dst != local_f8) {
      ExFreePoolWithTag(_Dst,0);
    }
  }
  else {
    _Dst = (ulonglong *)ExAllocatePool2(0x40,uVar21 << 5,0x74626e51);
    if (_Dst != (ulonglong *)0x0) goto LAB_14000a9e7;
    QosTbcDropNbl((longlong)param_1,local_198,param_4,param_5,param_5,2);
  }
LAB_14000b238:
  puVar16 = auStackY_1f8;
  uVar5 = 0;
LAB_14000b23a:
  *(undefined8 *)(puVar16 + -8) = 0x14000b249;
  return uVar5;
}



===== QosTbcSendNetBufferListComplete @ 14000b264 =====

undefined8
QosTbcSendNetBufferListComplete
          (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,longlong *param_5)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  if (*(longlong *)(param_3 + 0x78) == *(longlong *)(param_2 + 0x20)) {
    lVar3 = *(longlong *)(param_3 + 0x10);
    uVar4 = (ulonglong)*(ushort *)(lVar3 + 10);
    if (*(int *)(uVar4 + 0x38 + lVar3) == 0) {
      *(undefined1 *)(uVar4 + 0x3c + lVar3) = 1;
      param_3 = 0;
      lVar3 = *(longlong *)(uVar4 + 0x20 + lVar3);
      LOCK();
      piVar1 = (int *)(lVar3 + 0x30);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        QosNblCadReassemble(lVar3,'\0');
        param_3 = *(longlong *)(lVar3 + 0x18);
        ExFreeToNPagedLookasideList(QosgNblCadLookasideList,lVar3);
      }
      uVar5 = 1;
    }
  }
  if (param_3 != 0) {
    LOCK();
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    UNLOCK();
  }
  *param_5 = param_3;
  return uVar5;
}



===== QosTbcSmoothBytesRequested @ 14000b304 =====

ulonglong QosTbcSmoothBytesRequested(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x16c);
  uVar2 = (longlong)
          (((ulonglong)*(uint *)(param_1 + 0x154) - (ulonglong)*(uint *)(param_1 + 0x158)) *
          (ulonglong)*(uint *)(param_1 + 0x168)) / (longlong)uVar1 +
          (ulonglong)*(uint *)(param_1 + 0x158);
  if (param_2 != 0) {
    if (uVar1 <= param_2) {
      param_2 = uVar1;
    }
    uVar1 = ((longlong)(*(uint *)(param_1 + 0x168) * uVar2) / (longlong)uVar1) * param_2;
    if ((longlong)uVar2 <= (longlong)uVar1) {
      uVar1 = uVar2;
    }
    uVar2 = uVar2 - uVar1;
  }
  return uVar2 & 0xffffffff;
}



===== QosTbcTuneParameters @ 14000b364 =====

void QosTbcTuneParameters(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  
  uVar5 = 0;
  uVar4 = 1;
  uVar3 = (uint)(10000 / (ulonglong)*(uint *)(param_1 + 0x150));
  if (uVar3 < 0xb) {
    uVar3 = 10;
  }
  uVar1 = *(uint *)(param_1 + 0x140);
  if (((uVar1 != 0) && (*(uint *)(param_1 + 0x148) != 0)) && (*(uint *)(param_1 + 0x144) != 0)) {
    uVar2 = ((ulonglong)uVar1 * 0x3fffffff) / (ulonglong)*(uint *)(param_1 + 0x148);
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    uVar6 = 0x7fffffff;
    if (uVar2 < 0x7fffffff) {
      uVar6 = uVar2;
    }
    uVar5 = (undefined4)uVar6;
    uVar2 = ((ulonglong)uVar1 * 10) / (ulonglong)*(uint *)(param_1 + 0x144);
    if ((1 < uVar2) && (uVar4 = uVar2, 0xfffffffe < uVar2)) {
      uVar4 = 0xffffffff;
    }
  }
  *(uint *)(param_1 + 0x16c) = uVar3;
  *(undefined4 *)(param_1 + 0x17c) = uVar5;
  *(int *)(param_1 + 0x178) = (int)uVar4;
  *(undefined4 *)(param_1 + 0x170) = 0x14;
  *(undefined4 *)(param_1 + 0x168) = 2;
  return;
}



===== QosUpdateGenerationOverQuota @ 14000b430 =====

undefined8
QosUpdateGenerationOverQuota(ulonglong param_1,byte param_2,ulonglong *param_3,ulonglong *param_4)

{
  undefined1 auVar1 [16];
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = *param_3;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  uVar2 = param_1 / 600000 - *param_4;
  if (uVar2 != 0) {
    if (uVar2 < 0x40) {
      uVar3 = uVar3 << ((byte)uVar2 & 0x3f);
    }
    else {
      uVar3 = 0;
    }
    *param_4 = param_1 / 600000;
  }
  *param_3 = param_2 | uVar3;
  return SUB168(ZEXT816(0xdfb23b0979b4b02f) * auVar1,0);
}



===== QosUtilComputeTokenSpec @ 14000b470 =====

void QosUtilComputeTokenSpec(longlong *param_1,longlong param_2)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  longlong lVar3;
  ulonglong uVar4;
  
  if (param_1[2] == -1) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_1[2] * param_2;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar4;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
    uVar4 = (uVar4 - lVar3 >> 1) + lVar3 >> 9;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar4;
    lVar3 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar2,8);
    uVar4 = (uVar4 - lVar3 >> 1) + lVar3 >> 9;
  }
  lVar3 = *param_1 + uVar4;
  if ((lVar3 < *param_1) || (*param_1 = lVar3, param_1[1] < lVar3)) {
    *param_1 = param_1[1];
  }
  return;
}



===== QosUtilSetTokenSpec @ 14000b4d8 =====

void QosUtilSetTokenSpec(longlong *param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  
  lVar1 = param_2[1];
  if (param_3 == '\0') {
    if (lVar1 == -1) {
      lVar1 = 0x7fffffffffffffff;
    }
    param_1[1] = lVar1;
    if (lVar1 < *param_1) {
      *param_1 = lVar1;
    }
  }
  else if (lVar1 == -1) {
    *param_1 = 0;
    param_1[1] = 0x7fffffffffffffff;
  }
  else {
    *param_1 = lVar1;
    param_1[1] = param_2[1];
  }
  param_1[2] = *param_2;
  return;
}



===== Microsoft_Windows_Networking_Correlation_EtwEnableCallback @ 14000b540 =====

void Microsoft_Windows_Networking_Correlation_EtwEnableCallback
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  LOCK();
  Microsoft_Windows_Networking_CorrelationEnabled = param_2;
  UNLOCK();
  LOCK();
  Microsoft_Windows_Networking_CorrelationTraceActivityPayload = (uint)(param_4 >> 3) & 1;
  UNLOCK();
  return;
}



===== __GSHandlerCheck @ 14000b568 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000b58c =====

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



===== __chkstk @ 14000b5f2 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b5f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 14000b610 =====

/* WARNING: Removing unreachable block (ram,0x00014000b67a) */
/* WARNING: Removing unreachable block (ram,0x00014000b629) */
/* WARNING: Removing unreachable block (ram,0x00014000b61a) */

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



===== __security_check_cookie @ 14000b6e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000b720 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000b750 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000b780 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000b800 =====

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



===== memset @ 14000bb00 =====

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



===== __memset_repmovs @ 14000bc40 =====

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



===== __memset_query @ 14000bcc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000bd40 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000be80 =====

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



===== __memset_spec_plain @ 14000bf00 =====

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



===== AgileVpnUnload @ 14001b010 =====

void AgileVpnUnload(undefined8 param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 2) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceAdminInfo,&DAT_14000d238,
               "Driver Unload for AgileVPN is called");
  }
  NsiCliDeregisterClient();
  if (DAT_140012218 != 0) {
    NdisDeregisterDeviceEx();
    DAT_140012210 = 0;
    DAT_140012218 = 0;
  }
  uVar3 = 0;
  if (DAT_1400165c0 * 3 != 0) {
    do {
      lVar4 = (ulonglong)uVar3 * 0x40;
      iVar1 = ObReferenceObjectByHandle(*(undefined8 *)(lVar4 + DAT_1400165c8),0,0,0,local_res10,0);
      if (iVar1 == 0) {
        NdisSetEvent(DAT_1400165c8 + 0x20 + lVar4);
        KeWaitForSingleObject(local_res10[0]);
        ObfDereferenceObject(local_res10[0]);
      }
      ZwClose(*(undefined8 *)(lVar4 + DAT_1400165c8));
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(DAT_1400165c0 * 3));
  }
  NdisFreeMemoryWithTagPriority(DAT_140012240,DAT_1400165c8,0x69775641);
  ExDeleteResourceLite(&DAT_140014520);
  ExDeleteNPagedLookasideList(&DAT_1400122c0);
  ExDeleteNPagedLookasideList(&DAT_140012340);
  ExDeleteNPagedLookasideList(&DAT_1400123c0);
  puVar2 = &DAT_140012440;
  ExDeleteNPagedLookasideList();
  AgileVpnCleanUpWfpCallouts(puVar2);
  AgileVpnFreeWfpCallouts();
  BwcDeinit((ulonglong)puVar2);
  NdisMDeregisterMiniportDriver(DAT_140012240);
  RasAgileVpnUnRegisterEtw();
  return;
}



===== AgileVpnDevicePnPEventNotify @ 14001b1f0 =====

void AgileVpnDevicePnPEventNotify(void)

{
  return;
}



===== AgileVpnMpSetOptions @ 14001b200 =====

int AgileVpnMpSetOptions(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  code *local_10;
  
  local_d4 = 0;
  local_d8 = 0x380191;
  local_94 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_d0 = AgileVpnMpCoActivateVc;
  local_c8 = AgileVpnMpCoActivateVc;
  local_c0 = AgileVpnMpCoActivateVc;
  local_b8 = AgileVpnMpCoActivateVc;
  local_b0 = AgileVpnCoSendNetBufferLists;
  local_a8 = AgileVpnMpCoRequest;
  uVar2 = param_1;
  iVar1 = NdisSetOptionalHandlers(0,&local_d8);
  if (-1 < iVar1) {
    local_98 = 0x9001a5;
    local_90 = AgileVpnCmCreateVc;
    local_88 = AgileVpnCmDeleteVc;
    local_80 = AgileVpnCmOpenAf;
    local_78 = AgileVpnCmCloseAf;
    local_70 = AgileVpnCmRegisterSap;
    local_68 = AgileVpnCmDeregisterSap;
    local_60 = AgileVpnCmMakeCall;
    local_58 = AgileVpnCmCloseCall;
    local_50 = AgileVpnCmIncomingCallComplete;
    local_38 = AgileVpnCmActivateVcComplete;
    local_30 = AgileVpnCmDeactivateVcComplete;
    local_28 = CallOutNotify;
    local_20 = AgileVpnCmRequest;
    local_18 = _guard_check_icall;
    local_10 = _guard_check_icall;
    iVar1 = NdisSetOptionalHandlers(param_1,&local_98);
    uVar2 = param_1;
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (uVar2,&RasAgileVpnTraceIntArgError,&DAT_14000d218,
               "NdisSetOptionalHandlers for(NDIS_MINIPORT_CO_CHARACTERISTICS) failed with",
               (char)iVar1);
  }
  return iVar1;
}



===== BuildCallParams @ 14001b39c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong BuildCallParams(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  NTSTATUS NVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  short *psVar9;
  undefined1 auStack_f8 [32];
  size_t local_d8;
  uint local_d0 [2];
  wchar_t local_c8 [72];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d0[0] = 0;
  local_d8 = local_d8 & 0xffffffff00000000;
  lVar5 = ExAllocatePool2(0x40,0x338,0x70635641);
  lVar8 = 0;
  if (lVar5 != 0) {
    *(uint **)(lVar5 + 8) = (uint *)(lVar5 + 0x18);
    *(longlong *)(lVar5 + 0x10) = lVar5 + 0x68;
    puVar1 = (undefined4 *)(lVar5 + 0xa8);
    NVar3 = NsiCliGetLinkSpeedAndMTUFromAddress
                      ((ADDRESS_FAMILY *)(param_1 + 0x60),local_d0,(undefined4 *)&local_d8);
    if (NVar3 < 0) {
      ExFreePool(lVar5);
      lVar8 = 0;
    }
    else {
      uVar6 = local_d0[0] >> 3;
      *(uint *)(lVar5 + 0x18) = uVar6;
      *(uint *)(lVar5 + 0x20) = uVar6;
      *(int *)(lVar5 + 0x30) = (int)local_d8 + -100;
      *(int *)(lVar5 + 0x50) = (int)local_d8 + -100;
      *(uint *)(lVar5 + 0x38) = uVar6;
      *(uint *)(lVar5 + 0x40) = uVar6;
      *(undefined4 *)(lVar5 + 0x90) = 0x2900290;
      *(int *)(lVar5 + 0x70) = (int)local_d8;
      *(ulonglong *)(lVar5 + 0x98) = (ulonglong)(((int)puVar1 - ((int)lVar5 + 0x80)) - 0x10);
      *(undefined4 *)(lVar5 + 0x7c) = 0x2b0;
      *puVar1 = 0x290;
      *(uint *)(lVar5 + 0xac) = (uint)*(ushort *)(lVar5 + 0x90);
      *(uint *)(lVar5 + 0xb0) = (uint)*(ushort *)(lVar5 + 0x90);
      *(undefined4 *)(lVar5 + 0xb8) = DAT_140012280;
      *(undefined4 *)(lVar5 + 0xbc) = DAT_140012284;
      *(undefined4 *)(lVar5 + 0x1c8) = 0x28;
      *(undefined4 *)(lVar5 + 0x1cc) = 0x158;
      *(undefined4 *)(lVar5 + 0xc0) = 8;
      *(undefined8 *)(lVar5 + 0x208) = *(undefined8 *)(param_1 + 0xa8);
      uVar2 = *(undefined8 *)(param_1 + 0xa0);
      *(undefined8 *)(lVar5 + 0x210) = *(undefined8 *)(param_1 + 0x98);
      *(undefined8 *)(lVar5 + 0x218) = uVar2;
      uVar6 = *(int *)(lVar5 + 0x1cc) + *(int *)(lVar5 + 0x1c8) + 7 & 0xfffffff8;
      *(uint *)(lVar5 + 0x11c) = uVar6;
      psVar9 = (short *)((ulonglong)uVar6 + (longlong)puVar1);
      memset(local_c8,0,0x84);
      local_d8 = 0;
      pwVar7 = local_c8;
      if (*(short *)(param_1 + 0x7c) == 2) {
        RtlIpv4AddressToStringW(param_1 + 0x80);
      }
      else {
        RtlIpv6AddressToStringW(param_1 + 0x84);
      }
      StringCchLengthW(local_c8,(size_t)pwVar7,&local_d8);
      memmove(psVar9,local_c8,local_d8 * 2 + 2);
      iVar4 = StrLenW(psVar9);
      *(undefined4 *)(lVar5 + 0x114) = 8;
      uVar6 = *(int *)(lVar5 + 0x11c) + 0x8fU & 0xfffffff8;
      *(uint *)(lVar5 + 0x130) = uVar6;
      *(int *)(lVar5 + 0x118) = iVar4 * 2 + 2;
      psVar9 = (short *)((ulonglong)uVar6 + (longlong)puVar1);
      memset(local_c8,0,0x84);
      local_d8 = 0;
      pwVar7 = local_c8;
      if (*(ADDRESS_FAMILY *)(param_1 + 0x60) == 2) {
        RtlIpv4AddressToStringW(param_1 + 100);
      }
      else {
        RtlIpv6AddressToStringW(param_1 + 0x68);
      }
      StringCchLengthW(local_c8,(size_t)pwVar7,&local_d8);
      memmove(psVar9,local_c8,local_d8 * 2 + 2);
      iVar4 = StrLenW(psVar9);
      *(undefined4 *)(lVar5 + 0x128) = 8;
      *(int *)(lVar5 + 300) = iVar4 * 2 + 2;
      lVar8 = lVar5;
    }
  }
  return lVar8;
}



===== AgileVpnCreate @ 14001b680 =====

undefined8 AgileVpnCreate(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AgileVpnIoctl @ 14001b6b0 =====

int AgileVpnIoctl(undefined8 param_1,uint *param_2)

{
  short sVar1;
  char *pcVar2;
  char cVar3;
  int extraout_EAX;
  uint uVar4;
  int iVar5;
  
  pcVar2 = *(char **)(param_2 + 0x2e);
  uVar4 = *(uint *)(pcVar2 + 0x18);
  sVar1 = *(short *)(pcVar2 + 0x1a);
  cVar3 = IoIs32bitProcess(param_2);
  if (cVar3 == '\0') {
    if (((*pcVar2 == '\x0e') && (sVar1 == 0x12)) && ((uVar4 & 3) == 0)) {
      param_2[0xc] = 0;
      uVar4 = AgileVpnIoctlRequest(param_2,(longlong)pcVar2);
      param_2 = (uint *)(ulonglong)uVar4;
      iVar5 = extraout_EAX;
      if (extraout_EAX == 0x103) {
        return 0x103;
      }
      goto LAB_14001b720;
    }
    param_2[0xe] = 0;
    param_2[0xf] = 0;
  }
  iVar5 = -0x3fffff45;
  param_2[0xc] = 0xc00000bb;
LAB_14001b720:
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== AgileVpnIrpStub @ 14001b750 =====

undefined8 AgileVpnIrpStub(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== AgileVpnFreeWfpCallouts @ 14001b784 =====

undefined8 AgileVpnFreeWfpCallouts(void)

{
  if (DAT_140016818 != 0) {
    NdisFreeNetBufferListPool();
    DAT_140016818 = 0;
  }
  if (DAT_140016808 != 0) {
    NdisFreeNetBufferListPool();
    DAT_140016808 = 0;
  }
  if (DAT_140016810 != 0) {
    NdisFreeNetBufferListPool();
    DAT_140016810 = 0;
  }
  ExDeleteNPagedLookasideList(&DAT_140016780);
  return 0;
}



===== AgileVpnInitializeWfpCallouts @ 14001b80c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 AgileVpnInitializeWfpCallouts(undefined8 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined4 local_50;
  undefined2 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_2c = 0;
  uVar1 = 0;
  KeInitializeSpinLock(&DAT_140016820);
  _DAT_140016840 = 1;
  local_38 = 0x100180;
  local_34 = 0x100;
  local_30 = 0x63705641;
  DAT_140016810 = NdisAllocateNetBufferListPool(param_1,&local_38);
  if (DAT_140016810 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    local_30 = 0x774e5641;
    DAT_140016808 = NdisAllocateNetBufferListPool(param_1,&local_38);
    if (DAT_140016808 == 0) {
      uVar1 = 0xc000009a;
      NdisFreeNetBufferListPool(DAT_140016810);
      DAT_140016810 = 0;
    }
    else {
      local_28 = 0xc0180;
      local_24 = 0x64705641;
      DAT_140016818 = NdisAllocateNetBufferPool(param_1,&local_28);
      if (DAT_140016818 == 0) {
        uVar1 = 0xc000009a;
        NdisFreeNetBufferListPool(DAT_140016810);
        DAT_140016810 = 0;
        NdisFreeNetBufferListPool(DAT_140016808);
        DAT_140016808 = 0;
      }
      else {
        NdisGetVersion();
        local_48 = 0;
        local_50 = 0x63735641;
        local_58 = 0x18;
        ExInitializeNPagedLookasideList(&DAT_140016780,0,0,0x200);
        KeInitializeMutex(&DAT_140016858,0);
      }
    }
  }
  return uVar1;
}



===== DriverEntry @ 14001b9d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 auStack_268 [32];
  ulonglong local_228;
  undefined8 *local_220;
  undefined8 *local_218;
  code **local_210;
  undefined8 local_208;
  undefined *local_200;
  ulonglong local_1f8;
  code *local_1f0;
  code *pcStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined8 local_1b0;
  code *local_1a8;
  code *local_1a0;
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  undefined8 local_178;
  code *local_170;
  code *local_168;
  code *local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  code *local_148;
  code *local_140;
  code *local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  local_1b0 = 0;
  local_178 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_1f0 = (code *)0x0;
  pcStack_1e8 = (code *)0x0;
  lVar8 = param_1;
  RasAgileVpnRegisterEtw();
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 2) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (lVar8,&RasAgileVpnTraceAdminInfo,&DAT_14000d238,"Driver Entry for AgileVPN is called"
              );
  }
  iVar4 = NsiCliRegisterClient();
  if (iVar4 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
      return iVar4;
    }
    McTemplateK0sx_EtwWriteTransfer
              (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,
               "NsiCliRegisterClient returns Error",(char)iVar4);
    return iVar4;
  }
  KeInitializeSpinLock(&DAT_1400144f0);
  KeInitializeSpinLock(&DAT_1400144c0);
  KeInitializeSpinLock(&DAT_1400144e0);
  ExInitializeResourceLite(&DAT_140014520);
  puVar6 = &DAT_1400124c0;
  lVar8 = 0x200;
  do {
    puVar6[1] = puVar6;
    *puVar6 = puVar6;
    puVar6 = puVar6 + 2;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  _DAT_1400144d8 = &DAT_1400144d0;
  DAT_1400144d0 = &DAT_1400144d0;
  KeInitializeSpinLock(&DAT_140016588);
  puVar6 = &DAT_140014588;
  lVar8 = 0x200;
  do {
    puVar6[1] = puVar6;
    *puVar6 = puVar6;
    puVar6 = puVar6 + 2;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  NdisGetVersion();
  ExInitializeNPagedLookasideList(&DAT_1400122c0,0,0,0x200);
  NdisGetVersion();
  ExInitializeNPagedLookasideList(&DAT_140012340,0,0,0x200);
  NdisGetVersion();
  ExInitializeNPagedLookasideList(&DAT_1400123c0,0,0,0x200);
  NdisGetVersion();
  ExInitializeNPagedLookasideList(&DAT_140012440,0,0,0x200);
  local_198 = AgileVpnMpHalt;
  local_1b8 = 0x98028a;
  local_1a0 = AgileVpnMpInit;
  local_1b4 = 0x11e06;
  local_190 = AgileVpnUnload;
  DAT_140012248 = 0;
  local_170 = AgileVpnMpSendNetBufferLists;
  local_160 = AgileVpnMpSendNetBufferLists;
  local_1a8 = AgileVpnMpSetOptions;
  local_188 = AgileVpnMpPauseHandler;
  local_180 = AgileVpnMpRestart;
  local_168 = AgileVpnReturnNetBufferLists;
  local_148 = AgileVpnDevicePnPEventNotify;
  local_140 = _guard_check_icall;
  local_138 = _guard_check_icall;
  DAT_140012250 = MiniportPauseComplete;
  Globals = param_1;
  KeInitializeEvent(&DAT_140012258,0,1);
  lVar8 = Globals;
  iVar4 = NdisMRegisterMiniportDriver(Globals,param_2,&DAT_140012208,&local_1b8);
  if (iVar4 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,
                 "DriverEntry: NdisMRegisterMiniport returns Error",(char)iVar4);
    }
    NsiCliDeregisterClient();
    ExDeleteResourceLite(&DAT_140014520);
    ExDeleteNPagedLookasideList(&DAT_1400122c0);
    ExDeleteNPagedLookasideList(&DAT_140012340);
    ExDeleteNPagedLookasideList(&DAT_1400123c0);
    RasAgileVpnUnRegisterEtw();
    return iVar4;
  }
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  DAT_1400165c0 = KeQueryActiveProcessorCountEx(0xffff);
  lVar8 = DAT_140012240;
  DAT_1400165c8 =
       (void *)NdisAllocateMemoryWithTagPriority(DAT_140012240,DAT_1400165c0 * 0xc0,0x69775641,0x10)
  ;
  if (DAT_1400165c8 == (void *)0x0) {
    iVar4 = -0x3fffff66;
    iVar5 = -0x3fffff66;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,
                 "DriverEntry: NdisAllocateMemoryWithTagPriority for WorkerThreadContext failed.",
                 0x9a);
      NsiCliDeregisterClient();
      ExDeleteResourceLite(&DAT_140014520);
      ExDeleteNPagedLookasideList(&DAT_1400122c0);
      ExDeleteNPagedLookasideList(&DAT_140012340);
      ExDeleteNPagedLookasideList(&DAT_1400123c0);
      goto LAB_14001c2f8;
    }
  }
  else {
    bVar1 = false;
    memset(DAT_1400165c8,0,(ulonglong)(uint)(DAT_1400165c0 * 3) << 6);
    for (uVar10 = 0; uVar10 < (uint)(DAT_1400165c0 * 3); uVar10 = uVar10 + 1) {
      lVar9 = (ulonglong)uVar10 * 0x40;
      *(uint *)(lVar9 + 0x18 + (longlong)DAT_1400165c8) = uVar10 / 3;
      NdisInitializeEvent((longlong)DAT_1400165c8 + lVar9 + 0x20);
      lVar8 = (longlong)DAT_1400165c8 + lVar9 + 8;
      *(longlong *)(lVar8 + 8) = lVar8;
      *(longlong *)lVar8 = lVar8;
      lVar8 = (longlong)DAT_1400165c8 + lVar9 + 0x38;
      KeInitializeSpinLock();
      iVar4 = ScheduleSystemWorkerThread(lVar8,(void *)((longlong)DAT_1400165c8 + lVar9));
      if (iVar4 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,
                     "DriverEntry: ScheduleSystemWorkerThread returns Error",(char)iVar4);
        }
        NsiCliDeregisterClient();
        ExDeleteResourceLite(&DAT_140014520);
        ExDeleteNPagedLookasideList(&DAT_1400122c0);
        ExDeleteNPagedLookasideList(&DAT_140012340);
        ExDeleteNPagedLookasideList(&DAT_1400123c0);
        goto LAB_14001c2d8;
      }
    }
    local_228 = local_228 & 0xffffffff;
    local_208 = 0;
    local_1f8 = local_1f8 & 0xffffffff00000000;
    local_1e0 = 0;
    uStack_1d8 = 0;
    local_1d0 = 0;
    uStack_1c8 = 0;
    RtlInitUnicodeString(&local_1e0,L"\\Device\\AgileVPN");
    RtlInitUnicodeString(&local_1d0,L"\\DosDevices\\AgileVPN");
    local_110 = AgileVpnIrpStub;
    local_108 = AgileVpnIrpStub;
    local_100 = AgileVpnIrpStub;
    local_f8 = AgileVpnIrpStub;
    local_f0 = AgileVpnIrpStub;
    local_e8 = AgileVpnIrpStub;
    local_e0 = AgileVpnIrpStub;
    local_d8 = AgileVpnIrpStub;
    local_d0 = AgileVpnIrpStub;
    local_c8 = AgileVpnIrpStub;
    local_c0 = AgileVpnIrpStub;
    local_b8 = AgileVpnIrpStub;
    local_b0 = AgileVpnIrpStub;
    local_a0 = AgileVpnIrpStub;
    local_98 = AgileVpnIrpStub;
    local_90 = AgileVpnIrpStub;
    local_80 = AgileVpnIrpStub;
    local_78 = AgileVpnIrpStub;
    local_70 = AgileVpnIrpStub;
    local_68 = AgileVpnIrpStub;
    local_60 = AgileVpnIrpStub;
    local_58 = AgileVpnIrpStub;
    local_50 = AgileVpnIrpStub;
    local_48 = AgileVpnIrpStub;
    local_40 = AgileVpnIrpStub;
    local_118 = AgileVpnCreate;
    local_a8 = AgileVpnIoctl;
    local_88 = AgileVpnCleanup;
    local_220 = &local_1e0;
    local_218 = &local_1d0;
    local_210 = &local_118;
    local_200 = &SDDL_AGILEVPN_DEVICE;
    local_228 = 0x380185;
    local_208 = 0;
    local_1f8 = 0;
    lVar8 = DAT_140012240;
    iVar4 = NdisRegisterDeviceEx(DAT_140012240,&local_228,&DAT_140012210,&DAT_140012218);
    if (iVar4 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,
                   "DriverEntry: NdisRegisterDeviceEx returns Error:",(char)iVar4);
      }
      DAT_140012210 = 0;
      DAT_140012218 = 0;
    }
    else {
      bVar1 = true;
      *(uint *)(DAT_140012210 + 0x30) = *(uint *)(DAT_140012210 + 0x30) | 4;
    }
    bVar3 = true;
    bVar2 = false;
    lVar8 = DAT_140012240;
    iVar5 = AgileVpnInitializeWfpCallouts(DAT_140012240);
    if (iVar5 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar11 = "DriverEntry: AgileVpnInitializeWfpCallouts returns Error:";
LAB_14001c235:
        bVar3 = true;
        McTemplateK0sx_EtwWriteTransfer
                  (lVar8,&RasAgileVpnTraceIntArgError,&DAT_14000d238,pcVar11,(char)iVar5);
      }
    }
    else {
      bVar3 = true;
      bVar2 = true;
      _agileVpnUlPackSent = 0;
      _agileVpnUlPackSentError = 0;
      _agileVpnUlPackSentComplete = 0;
      _agileVpnUlPackReceivedError = 0;
      _agileVpnUlPackReceived = 0;
      _agileVpnUlPackReceivedPending = 0;
      _agileVpnUlPackReceivedComplete = 0;
      lVar8 = DAT_140012240;
      uVar7 = BwcInit(DAT_140012240,param_1);
      iVar5 = (int)uVar7;
      if (-1 < iVar5) {
        local_1f0 = GetCompartmentIdFromTunnelId;
        pcStack_1e8 = GetTunnelDataFromInterfaceIndex;
        AgileVPNDispatchTableInit(&local_1f0);
        return iVar5;
      }
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar11 = "DriverEntry: BwcQosInit returned Error:";
        goto LAB_14001c235;
      }
    }
  }
  iVar4 = iVar5;
  NsiCliDeregisterClient();
  if ((bVar1) && (DAT_140012218 != 0)) {
    NdisDeregisterDeviceEx();
    DAT_140012210 = 0;
    DAT_140012218 = 0;
  }
  ExDeleteResourceLite(&DAT_140014520);
  ExDeleteNPagedLookasideList(&DAT_1400122c0);
  ExDeleteNPagedLookasideList(&DAT_140012340);
  ExDeleteNPagedLookasideList(&DAT_1400123c0);
  if (bVar2) {
    AgileVpnFreeWfpCallouts();
  }
  if (bVar3) {
LAB_14001c2d8:
    NdisFreeMemoryWithTagPriority(DAT_140012240,DAT_1400165c8,0x69775641);
  }
LAB_14001c2f8:
  NdisMDeregisterMiniportDriver(DAT_140012240);
  RasAgileVpnUnRegisterEtw();
  return iVar4;
}



===== AgileVpnMpInit @ 14001c380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AgileVpnMpInit(undefined8 param_1)

{
  int iVar1;
  undefined4 *_Dst;
  undefined8 uVar2;
  char *pcVar3;
  undefined1 auStack_1a8 [32];
  undefined4 local_178;
  undefined4 local_174;
  undefined8 *local_170;
  undefined4 local_168;
  undefined8 local_164;
  undefined4 local_15c;
  undefined4 local_158 [2];
  undefined8 local_150;
  undefined4 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 local_108;
  undefined4 local_104;
  undefined2 local_fc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined4 local_9c;
  undefined4 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_78 = 0x801;
  local_74 = 6;
  _Dst = local_158;
  local_174 = 0;
  local_15c = 0;
  local_70 = 0x1e;
  memset(_Dst,0,0xe0);
  local_44 = 0;
  local_64 = 0;
  uStack_5c = 0;
  local_34 = 0;
  local_54 = 0;
  uStack_4c = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer(_Dst,&RasAgileVpnTraceInfo,&DAT_14000d218,"AgileVpnMpInit:");
  }
  DAT_140014510 = 30000;
  local_168 = 0x20;
  local_170 = &DAT_140012240;
  local_178 = 0x20029e;
  local_164 = 0x10;
  uVar2 = param_1;
  iVar1 = NdisMSetMiniportAttributes(param_1,&local_178);
  if (iVar1 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
      return iVar1;
    }
    pcVar3 = "MpInit: NdisMSetMiniportAttributes (RegistrationAttributes) returns Error";
  }
  else {
    local_80 = &local_68;
    local_158[0] = 0xe0029f;
    local_150 = 0xc;
    local_a4 = 0x83;
    local_148 = 0x5c8;
    local_140 = 0xffffffffffffffff;
    local_130 = 0xffffffffffffffff;
    local_138 = 0xffffffffffffffff;
    local_128 = 0xffffffffffffffff;
    local_120 = 0;
    local_118 = 0x5c8;
    local_68 = 0x3c0280;
    local_40 = 0;
    local_38 = 0;
    local_108 = 5;
    local_104 = 1;
    local_fc = 0;
    local_b8 = 0;
    local_b0 = 3;
    local_a8 = 1;
    local_a2 = 0;
    local_9c = 0;
    uVar2 = param_1;
    iVar1 = NdisMSetMiniportAttributes(param_1,local_158);
    if (-1 < iVar1) {
      _DAT_140014508 = 0x10000000;
      _DAT_140014500 = 0x5dc;
      _DAT_140014504 = 0x20;
      DAT_140012240 = param_1;
      iVar1 = NdisMCmRegisterAddressFamilyEx(param_1,&local_78);
      if (iVar1 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (param_1,&RasAgileVpnTraceIntArgError,&DAT_14000d218,
                     "MpInit: NdisMCmRegisterAddressFamilyEx returns Error",(char)iVar1);
        }
      }
      else {
        DAT_140014514 = DAT_140014514 & 0xfffffffc;
      }
      return iVar1;
    }
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
      return iVar1;
    }
    pcVar3 = "MpInit: NdisMSetMiniportAttributes (General) returns Error";
  }
  McTemplateK0sx_EtwWriteTransfer
            (uVar2,&RasAgileVpnTraceIntArgError,&DAT_14000d218,pcVar3,(char)iVar1);
  return iVar1;
}



===== AgileVpnProcessPackets @ 14001d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AgileVpnProcessPackets(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong ****pppplVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  code *pcVar6;
  longlong ****pppplVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  longlong ***ppplVar10;
  undefined1 *puVar11;
  char *pcVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [24];
  undefined4 local_88;
  longlong ****local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  local_88 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_80 = (longlong ****)0x0;
  uStack_78 = 0;
  LOCK();
  _DAT_1400165d0 = _DAT_1400165d0 + 1;
  UNLOCK();
  KeGetProcessorNumberFromIndex(*(undefined4 *)(param_1 + 0x18),&local_88);
  local_58 = 1L << (local_88._2_1_ & 0x3f);
  uStack_50 = CONCAT62(uStack_50._2_6_,(undefined2)local_88);
  KeSetSystemGroupAffinityThread(&local_58,&local_48);
  puVar11 = auStack_a8;
  do {
    NdisWaitEvent(param_1 + 0x20,0);
    uVar8 = KfRaiseIrql(2);
    AgileVpnGetPacketsForProcessing(param_1,(longlong *)&local_80);
    if ((longlong *****)local_80 == &local_80) {
LAB_14001d39c:
      *(undefined8 *)(puVar11 + -8) = 0x14001d3a6;
      KeLowerIrql(uVar8);
      *(undefined8 *)(puVar11 + -8) = 0x14001d3b6;
      KeRevertToUserGroupAffinityThread(&local_48);
      LOCK();
      _DAT_1400165d0 = _DAT_1400165d0 + -1;
      UNLOCK();
      *(undefined8 *)(puVar11 + -8) = 0x14001d3cb;
      PsTerminateSystemThread(0);
      *(undefined8 *)(puVar11 + -8) = 0x14001d3dc;
      return;
    }
    uVar13 = 0;
    while ((longlong *****)local_80 != &local_80) {
      uVar13 = uVar13 + 1;
      if (0x19 < uVar13) {
        KeLowerIrql(uVar8);
        uVar8 = KfRaiseIrql(2);
        uVar13 = 0;
      }
      pppplVar7 = local_80;
      if (((longlong *****)local_80[1] != &local_80) ||
         (pppplVar3 = (longlong ****)*local_80, (longlong ****)pppplVar3[1] != local_80)) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar11 = auStack_a0;
        goto LAB_14001d39c;
      }
      pppplVar3[1] = (longlong ***)&local_80;
      LOCK();
      *(int *)((longlong)local_80[4] + 0x174) = *(int *)((longlong)local_80[4] + 0x174) + -1;
      UNLOCK();
      if (*(char *)(local_80 + 5) == '\0') {
        LOCK();
        piVar1 = (int *)((longlong)local_80[4] + 0x17c);
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        ppplVar4 = local_80[2];
        ppplVar5 = local_80[4];
        local_80 = pppplVar3;
        DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
        ppplVar10 = (longlong ***)&DAT_1400144f0;
        if ((DAT_140014514 & 1) == 0) {
          KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
          ppplVar10 = ppplVar5 + 7;
          uVar9 = KeAcquireSpinLockRaiseToDpc(ppplVar10);
          *(undefined1 *)(ppplVar5 + 8) = uVar9;
          if ((*(uint *)((longlong)ppplVar5 + 0xd4) & 0x20) != 0) goto LAB_14001d24e;
          KeReleaseSpinLock(ppplVar10,
                            CONCAT31((int3)(*(uint *)((longlong)ppplVar5 + 0xd4) >> 8),uVar9));
          uVar9 = KeAcquireSpinLockRaiseToDpc(ppplVar10);
          *(undefined1 *)(ppplVar5 + 8) = uVar9;
          if ((*(uint *)((longlong)ppplVar5 + 0xd4) & 0x20) != 0) {
            KeReleaseSpinLock(ppplVar10,uVar9);
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
              pcVar12 = "Dropping Receive packet due to invalid tunnel State";
              goto LAB_14001d2f8;
            }
            goto LAB_14001d30b;
          }
          *(int *)(ppplVar5 + 2) = *(int *)(ppplVar5 + 2) + 1;
          ppplVar4[0xc] = (longlong **)ppplVar5;
          KeReleaseSpinLock(ppplVar10,*(undefined1 *)(ppplVar5 + 8));
          NdisMCoIndicateReceiveNetBufferLists(ppplVar5[9],ppplVar4,1);
          LOCK();
          _agileVpnUlPackReceived = _agileVpnUlPackReceived + 1;
          UNLOCK();
        }
        else {
LAB_14001d24e:
          KeReleaseSpinLock();
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar12 = "Dropping Receive packet due to invalid Adapter/Tunnel State";
LAB_14001d2f8:
            McTemplateK0s_EtwWriteTransfer(ppplVar10,&RasAgileVpnTraceError,&DAT_14000d218,pcVar12);
          }
LAB_14001d30b:
          AgileVpnCompleteNblsPreRecv((int *)ppplVar5,ppplVar4);
        }
        ExFreeToNPagedLookasideList(&DAT_140012440,pppplVar7);
      }
      else {
        LOCK();
        ppplVar10 = local_80[4] + 0x2f;
        *(int *)ppplVar10 = *(int *)ppplVar10 + -1;
        UNLOCK();
        ppplVar10 = local_80[2];
        local_80 = pppplVar3;
        while (ppplVar10 != (longlong ***)0x0) {
          ppplVar4 = (longlong ***)*ppplVar10;
          *ppplVar10 = (longlong **)0x0;
          ApplyQoSAndTransmitPacket((longlong)ppplVar10,(int *)pppplVar7[4]);
          ppplVar10 = ppplVar4;
        }
        ppplVar10 = pppplVar7[4];
        LOCK();
        iVar2 = *(int *)ppplVar10;
        *(int *)ppplVar10 = *(int *)ppplVar10 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (*(code *)ppplVar10[1])();
        }
        ExFreeToNPagedLookasideList(&DAT_140012440,pppplVar7);
        LOCK();
        iVar2 = DAT_140012248 + -1;
        UNLOCK();
        bVar14 = DAT_140012248 == 1;
        DAT_140012248 = iVar2;
        if (bVar14) {
          (*DAT_140012250)(&DAT_140012248);
        }
      }
    }
    local_70 = 0;
    uStack_68 = 0;
    local_60 = 0;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1 + 0x38);
    if (*(longlong **)(param_1 + 8) == (longlong *)(param_1 + 8)) {
      NdisResetEvent(param_1 + 0x20);
    }
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_70);
    KeLowerIrql(uVar8);
  } while( true );
}



===== FindMatchingTs @ 14001d404 =====

undefined1 FindMatchingTs(undefined8 *param_1,undefined8 *param_2,short *param_3,char param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  short *psVar3;
  
  puVar2 = (undefined8 *)*param_1;
  do {
    if (puVar2 == param_1) {
      return 0;
    }
    psVar3 = (short *)puVar2[4];
    while( true ) {
      if (psVar3 == (short *)0x0) goto LAB_14001d47d;
      uVar1 = MatchFilter(psVar3,param_3,param_4);
      if ((char)uVar1 != '\0') break;
      psVar3 = *(short **)(psVar3 + 0x18);
    }
    for (psVar3 = (short *)puVar2[5]; psVar3 != (short *)0x0; psVar3 = *(short **)(psVar3 + 0x18)) {
      uVar1 = MatchFilter(psVar3,param_3,param_4 == '\0');
      if ((char)uVar1 != '\0') {
        *param_2 = puVar2[-1];
        return 1;
      }
    }
LAB_14001d47d:
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== AgileVpnMpSendNetBufferLists @ 14001d4c0 =====

void AgileVpnMpSendNetBufferLists(void)

{
  return;
}



===== AgileVpnCmActivateVcComplete @ 14001d4d0 =====

void AgileVpnCmActivateVcComplete(ulonglong param_1,int *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,"AgileVpnCmActivateVcComplete: ",
               (char)param_1);
  }
  if ((int)param_1 < 0) {
    if ((char)param_2[0x16] == '\0') {
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xe);
      param_2[0x35] = param_2[0x35] & 0xfffff7ff;
      *(undefined1 *)(param_2 + 0x10) = uVar1;
      KeReleaseSpinLock(param_2 + 0xe,uVar1);
      NdisCmMakeCallComplete
                (param_1 & 0xffffffff,*(undefined8 *)(param_2 + 0x12),0,0,
                 *(undefined8 *)(param_2 + 0x14));
    }
    InitiateConnectionCleanup(param_2,(int)param_1);
    piVar2 = param_2;
  }
  else {
    LOCK();
    *param_2 = *param_2 + 1;
    UNLOCK();
    piVar3 = param_2 + 0xe;
    uVar1 = KeAcquireSpinLockRaiseToDpc(piVar3);
    param_2[0x35] = param_2[0x35] | 2;
    *(undefined1 *)(param_2 + 0x10) = uVar1;
    KeReleaseSpinLock(piVar3,uVar1);
    if ((char)param_2[0x16] == '\0') {
      uVar1 = KeAcquireSpinLockRaiseToDpc(piVar3);
      param_2[0x35] = param_2[0x35] & 0xfffff7ff;
      *(undefined1 *)(param_2 + 0x10) = uVar1;
      KeReleaseSpinLock(piVar3,uVar1);
      NdisCmMakeCallComplete(0,*(undefined8 *)(param_2 + 0x12),0,0,*(undefined8 *)(param_2 + 0x14));
      uVar1 = KeAcquireSpinLockRaiseToDpc(piVar3);
      param_2[0x35] = param_2[0x35] | 4;
      param_2[0x14] = 0;
      param_2[0x15] = 0;
      *(undefined1 *)(param_2 + 0x10) = uVar1;
      *(undefined1 *)(param_2 + 0x36) = 1;
      piVar2 = piVar3;
      KeReleaseSpinLock(piVar3,uVar1);
      LOCK();
      *param_2 = *param_2 + 1;
      UNLOCK();
      if ((char)param_2[0x16] == '\0') goto LAB_14001d66c;
    }
    uVar1 = KeAcquireSpinLockRaiseToDpc(piVar3);
    *(undefined1 *)(param_2 + 0x10) = uVar1;
    FreeCallParams(*(longlong *)(param_2 + 0x14));
    param_2[0x14] = 0;
    param_2[0x15] = 0;
    KeReleaseSpinLock(piVar3,(char)param_2[0x10]);
    piVar2 = piVar3;
  }
LAB_14001d66c:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (piVar2,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmActivateVcComplete: done");
  }
  return;
}



===== AgileVpnCmDeactivateVcComplete @ 14001d6b0 =====

void AgileVpnCmDeactivateVcComplete(ulonglong param_1,int *param_2)

{
  undefined1 uVar1;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceIntArgInfo,&DAT_14000e170,"AgileVpnCmDeactivateVcComplete: "
               ,(char)param_1);
  }
  DereferenceRefCount(param_2);
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xe);
  param_2[0x35] = param_2[0x35] & 0xfffffffd;
  *(undefined1 *)(param_2 + 0x10) = uVar1;
  KeReleaseSpinLock(param_2 + 0xe,uVar1);
  InitiateConnectionCleanup(param_2,(int)param_1);
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_2,&RasAgileVpnTraceInfo,&DAT_14000e170,"AgileVpnCmDeactivateVcComplete: done");
  }
  return;
}



===== AgileVpnCmIncomingCallComplete @ 14001d770 =====

void AgileVpnCmIncomingCallComplete(int param_1,int *param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int *piVar5;
  
  piVar1 = param_2 + 0xe;
  piVar5 = piVar1;
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  lVar3 = *(longlong *)(param_2 + 0x3a);
  param_2[0x3a] = 0;
  param_2[0x3b] = 0;
  param_2[0x35] = param_2[0x35] & 0xfffffdff;
  *(undefined1 *)(param_2 + 0x10) = uVar4;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0xq_EtwWriteTransfer
              (piVar5,&RasAgileVpnTraceIncomingCallComplete,&DAT_14000e170,
               *(undefined8 *)(param_2 + 0x2a),(char)param_1);
  }
  if (lVar3 != 0) {
    LOCK();
    lVar2 = *(longlong *)(lVar3 + 0x68);
    *(longlong *)(lVar3 + 0x68) = 0;
    UNLOCK();
    if (lVar2 != 0) {
      if (param_1 == 0) {
        if ((param_2[0x35] & 0x20U) == 0) {
          *(undefined1 *)(param_2 + 0x36) = 1;
          param_2[0x35] = param_2[0x35] | 4;
          KeReleaseSpinLock(piVar1,(char)param_2[0x10]);
          NdisCmDispatchCallConnected(*(undefined8 *)(param_2 + 0x12));
          LOCK();
          *param_2 = *param_2 + 1;
          UNLOCK();
        }
        else {
          KeReleaseSpinLock();
          NdisCmDispatchIncomingCloseCall(0,*(undefined8 *)(param_2 + 0x12),0,0);
        }
      }
      else {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (piVar5,&RasAgileVpnTraceError,&DAT_14000e170,
                     "AgileVpnCmIncomingCallComplete: Closing call. ");
        }
        KeReleaseSpinLock(piVar1,(char)param_2[0x10]);
        InitiateConnectionCleanup(param_2,param_1);
      }
      *(int *)(lVar3 + 0x30) = param_1;
      IofCompleteRequest(lVar3,2);
      return;
    }
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (piVar5,&RasAgileVpnTraceError,&DAT_14000e170,
               "AgileVpnCmIncomingCallComplete: Incoming call IRP is NULL. Closing call. ");
  }
  KeReleaseSpinLock(piVar1,(char)param_2[0x10]);
  if (param_1 == 0) {
    NdisCmDispatchIncomingCloseCall(0,*(undefined8 *)(param_2 + 0x12),0,0);
  }
  else {
    InitiateConnectionCleanup(param_2,param_1);
  }
  return;
}



===== CallOutNotify @ 14001d930 =====

undefined8 CallOutNotify(void)

{
  return 0;
}



===== FreeCallParams @ 14001d93c =====

void FreeCallParams(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePool();
  }
  return;
}



===== AgileVpnCloseTunnel @ 14001d960 =====

int AgileVpnCloseTunnel(longlong param_1,uint param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined1 uVar3;
  int *piVar4;
  longlong lVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = 0;
  lVar5 = param_1;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"AgileVpnCloseTunnel: is called");
  }
  if (param_2 < 0x60) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (lVar5,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnCloseTunnel: Input Buffer Length is not sufficient");
    }
    return -0x3fffffdd;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  plVar2 = *(longlong **)(param_1 + 0x18);
  lVar5 = *plVar2;
  piVar4 = (int *)FindTunnelCbFromTunnelId(lVar5);
  if (piVar4 == (int *)0x0) {
    iVar7 = -0x3fffffcc;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) == 0) {
      return -0x3fffffcc;
    }
    McTemplateK0sx_EtwWriteTransfer
              (lVar5,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnCloseTunnel: Could not found Tunnel Id from the list of TUNNELCB\'s. TunnelID:"
               ,(char)*plVar2);
  }
  else {
    piVar1 = piVar4 + 0xe;
    piVar6 = piVar1;
    uVar3 = KeAcquireSpinLockRaiseToDpc();
    *(undefined1 *)(piVar4 + 0x10) = uVar3;
    if (((byte)piVar4[0x35] & 0x24) != 4) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (piVar6,&RasAgileVpnTraceError,&DAT_14000f3f8,
                   "AgileVpnCloseTunnel: Tunnel is going down and not accepting these IOCTLS");
      }
      KeReleaseSpinLock(piVar1,(char)piVar4[0x10]);
      DereferenceRefCount(piVar4);
      return -0x3fffff45;
    }
    KeReleaseSpinLock(piVar1,uVar3);
    InitiateConnectionCleanup(piVar4,0xc000013c);
    DereferenceRefCount(piVar4);
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              ((longlong)iVar7,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnCloseTunnel: is exited with Status",(char)iVar7);
  }
  return iVar7;
}



===== AgileVpnCompleteUpdateTunnelComplete @ 14001dae8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AgileVpnCompleteUpdateTunnelComplete(int *param_1,uint param_2)

{
  char cVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  ulonglong uVar11;
  undefined1 auStack_e8 [32];
  int local_b8;
  int local_b4 [3];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined4 local_94;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_e8;
  iVar7 = 0;
  piVar8 = param_1;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
               "AgileVpnCompleteUpdateTunnelComplete: is called");
  }
  if (param_2 < 0x60) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar8,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
                 "AgileVpnCompleteUpdateTunnelComplete: Input Buffer Length is not sufficient");
    }
    return -0x3fffffdd;
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  plVar2 = *(longlong **)(param_1 + 6);
  if ((char)plVar2[1] == '\0') {
    cVar1 = *(char *)((longlong)plVar2 + 9);
  }
  else {
    cVar1 = *(char *)((longlong)plVar2 + 0x2c);
  }
  if (cVar1 == '\0') {
    iVar7 = -0x3ffffff3;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar8,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnCompleteUpdateTunnelComplete: Some of the fields in AGILEVPN_TNNEL_INFO are not set"
                );
    }
    goto LAB_14001ddd5;
  }
  piVar9 = (int *)*plVar2;
  piVar8 = (int *)FindTunnelCbFromTunnelId((longlong)piVar9);
  if (piVar8 == (int *)0x0) {
    iVar7 = -0x3fffffcc;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) == 0) {
      return -0x3fffffcc;
    }
    McTemplateK0sx_EtwWriteTransfer
              (piVar9,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnCompleteUpdateTunnelComplete: Could not found Tunnel Id from the list of TUNNELCB\'s. TunnelID:"
               ,(char)*plVar2);
    piVar8 = piVar9;
    goto LAB_14001ddd5;
  }
  piVar9 = piVar8 + 0xe;
  piVar10 = piVar9;
  uVar6 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(piVar8 + 0x10) = uVar6;
  if (((byte)piVar8[0x35] & 0x24) != 4) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar10,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnCompleteUpdateTunnelComplete: Tunnel is going down and not accepting these IOCTLS"
                );
    }
    KeReleaseSpinLock(piVar9,(char)piVar8[0x10]);
    DereferenceRefCount(piVar8);
    return -0x3fffff45;
  }
  KeReleaseSpinLock(piVar9);
  if ((char)plVar2[1] == '\0') {
    local_30 = 0;
    memset(local_a8,0,0x70);
    local_b8 = 0;
    local_b4[0] = 0;
    uVar11 = (ulonglong)*(uint *)((longlong)plVar2 + 0xc);
    iVar7 = NsiCliGetLinkSpeedAndMTUFromInterfaceIndex
                      (*(uint *)((longlong)plVar2 + 0xc),&local_b8,local_b4,(short)piVar8[0x1f] == 2
                      );
    if (-1 < iVar7) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar9);
      piVar8[0x37] = local_b8;
      *(undefined1 *)(piVar8 + 0x10) = uVar6;
      piVar8[0x38] = local_b4[0] + -100;
      KeReleaseSpinLock(piVar9,uVar6);
      local_38 = *(undefined4 *)((longlong)plVar2 + 0xc);
      local_34 = (uint)piVar8[0x37] >> 3;
      local_28 = piVar8[0x38];
      local_78 = &local_38;
      local_2c = 0x20;
      local_a8[0] = 0x700198;
      local_a0 = DAT_140012240;
      local_94 = 0x40010025;
      local_70 = 0x14;
      local_30 = local_34;
      NdisMCoIndicateStatusEx(DAT_140012240,*(undefined8 *)(piVar8 + 0x12),local_a8);
      goto LAB_14001dd5f;
    }
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (uVar11,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                 "AgileVpnCompleteUpdateTunnelComplete: NsiCliGetLinkSpeedAndMTUFromInterfaceIndex: failed with Status"
                 ,(char)iVar7);
    }
  }
  else {
LAB_14001dd5f:
    uVar6 = KeAcquireSpinLockRaiseToDpc(piVar9);
    *(undefined1 *)(piVar8 + 0x10) = uVar6;
    if (*(char *)((longlong)plVar2 + 9) != '\0') {
      iVar3 = *(int *)((longlong)plVar2 + 0x14);
      lVar5 = plVar2[3];
      iVar4 = *(int *)((longlong)plVar2 + 0x1c);
      piVar8[0x18] = (int)plVar2[2];
      piVar8[0x19] = iVar3;
      piVar8[0x1a] = (int)lVar5;
      piVar8[0x1b] = iVar4;
      *(longlong *)(piVar8 + 0x1c) = plVar2[4];
      piVar8[0x1e] = (int)plVar2[5];
    }
    if (*(char *)((longlong)plVar2 + 0x2c) != '\0') {
      iVar3 = *(int *)((longlong)plVar2 + 0x34);
      lVar5 = plVar2[7];
      iVar4 = *(int *)((longlong)plVar2 + 0x3c);
      piVar8[0x1f] = (int)plVar2[6];
      piVar8[0x20] = iVar3;
      piVar8[0x21] = (int)lVar5;
      piVar8[0x22] = iVar4;
      *(longlong *)(piVar8 + 0x23) = plVar2[8];
      piVar8[0x25] = (int)plVar2[9];
    }
    piVar8[0x35] = piVar8[0x35] & 0xfffffbff;
    KeReleaseSpinLock(piVar8 + 0xe,uVar6);
  }
  DereferenceRefCount(piVar8);
LAB_14001ddd5:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (piVar8,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnCompleteUpdateTunnelComplete: is exited with Status",(char)iVar7);
  }
  return iVar7;
}



===== AgileVpnCreateTunnel @ 14001de70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AgileVpnCreateTunnel(longlong param_1,uint param_2)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  int *piVar8;
  int *piVar9;
  SOCKADDR_INET *pSVar10;
  undefined1 auStack_d8 [32];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined4 local_94;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_d8;
  iVar5 = 0;
  lVar7 = param_1;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"AgileVpnCreateTunnel: is called");
  }
  if (param_2 < 0x60) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (lVar7,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnCreateTunnel: Input Buffer Length is not sufficient");
    }
    iVar5 = -0x3fffffdd;
  }
  else {
    *(undefined8 *)(param_1 + 0x38) = 0;
    plVar1 = *(longlong **)(param_1 + 0x18);
    piVar8 = (int *)*plVar1;
    piVar6 = (int *)FindTunnelCbFromTunnelId((longlong)piVar8);
    if (piVar6 == (int *)0x0) {
      iVar5 = -0x3fffffcc;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (piVar8,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                   "AgileVpnCreateTunnel: Could not found Tunnel Id from the list of TUNNELCB\'s. TunnelID:"
                   ,(char)*plVar1);
      }
    }
    else {
      piVar8 = piVar6 + 0xe;
      piVar9 = piVar8;
      uVar4 = KeAcquireSpinLockRaiseToDpc();
      *(undefined1 *)(piVar6 + 0x10) = uVar4;
      if (((byte)piVar6[0x35] & 0x24) != 4) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (piVar9,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
                     "AgileVpnCreateTunnel: Tunnel is going down and not accepting these IOCTLS");
        }
        KeReleaseSpinLock(piVar8,(char)piVar6[0x10]);
        DereferenceRefCount(piVar6);
        return -0x3fffff45;
      }
      piVar9 = piVar8;
      KeReleaseSpinLock(piVar8,uVar4);
      if ((*(char *)((longlong)plVar1 + 9) == '\0') || (*(char *)((longlong)plVar1 + 0x2c) == '\0'))
      {
        iVar5 = -0x3ffffff3;
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    (piVar9,&RasAgileVpnTraceError,&DAT_14000f3f8,
                     "AgileVpnCreateTunnel: Some of the fields in AGILEVPN_TNNEL_INFO are not set");
        }
      }
      else {
        uVar4 = KeAcquireSpinLockRaiseToDpc(piVar8);
        *(undefined1 *)(piVar6 + 0x10) = uVar4;
        piVar9 = piVar6 + 0x1f;
        iVar2 = *(int *)((longlong)plVar1 + 0x14);
        lVar7 = plVar1[3];
        iVar3 = *(int *)((longlong)plVar1 + 0x1c);
        piVar6[0x18] = (int)plVar1[2];
        piVar6[0x19] = iVar2;
        piVar6[0x1a] = (int)lVar7;
        piVar6[0x1b] = iVar3;
        *(longlong *)(piVar6 + 0x1c) = plVar1[4];
        piVar6[0x1e] = (int)plVar1[5];
        lVar7 = RtlCompareMemory(piVar9,plVar1 + 6,0x1c);
        if (lVar7 == 0x1c) {
          KeReleaseSpinLock(piVar8,(char)piVar6[0x10]);
          if ((char)piVar6[0x16] == '\0') {
            pSVar10 = (SOCKADDR_INET *)(piVar6 + 0x1f);
            iVar5 = NsiCliAddOrDeleteHostRouteToInterface(pSVar10,piVar6[0x17],'\x01');
            if (iVar5 < 0) {
              if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
                McTemplateK0sx_EtwWriteTransfer
                          (pSVar10,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                           "AgileVpnCreateTunnel: AddHostSpecificRoute: failed with Status",
                           (char)iVar5);
              }
            }
            else {
              uVar4 = KeAcquireSpinLockRaiseToDpc(piVar8);
              piVar6[0x35] = piVar6[0x35] | 0x100;
              *(undefined1 *)(piVar6 + 0x10) = uVar4;
              KeReleaseSpinLock(piVar8);
              memset(local_a8,0,0x70);
              local_38 = *(undefined4 *)((longlong)plVar1 + 0xc);
              local_34 = (uint)piVar6[0x37] >> 3;
              local_28 = piVar6[0x38];
              local_78 = &local_38;
              local_2c = 0x20;
              local_a8[0] = 0x700198;
              local_a0 = DAT_140012240;
              local_94 = 0x40010025;
              local_70 = 0x14;
              local_30 = local_34;
              NdisMCoIndicateStatusEx(DAT_140012240,*(undefined8 *)(piVar6 + 0x12),local_a8);
            }
          }
        }
        else {
          iVar5 = -0x3ffffff3;
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (piVar9,&RasAgileVpnTraceError,&DAT_14000f3f8,
                       "AgileVpnCreateTunnel: Remote Outer IP address did not match with the earlier Remote Ip address coming from new call indication "
                      );
          }
          KeReleaseSpinLock(piVar8,(char)piVar6[0x10]);
        }
      }
      piVar8 = piVar6;
      DereferenceRefCount(piVar6);
      if (iVar5 < 0) {
        InitiateConnectionCleanup(piVar6,iVar5);
        piVar8 = piVar6;
      }
    }
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (piVar8,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                 "AgileVpnCreateTunnel: is exited with",(char)iVar5);
    }
  }
  return iVar5;
}



===== AgileVpnInitiateUpdateClientTunnel @ 14001e20c =====

int AgileVpnInitiateUpdateClientTunnel(int *param_1,uint param_2)

{
  NET_IFINDEX NVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  SOCKADDR_INET *pSVar10;
  
  piVar8 = param_1;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
               "AgileVpnInitiateUpdateClientTunnel: is called");
  }
  if (param_2 < 0x60) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar8,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnInitiateUpdateClientTunnel: Input Buffer Length is not sufficient");
    }
    return -0x3fffffdd;
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  plVar2 = *(longlong **)(param_1 + 6);
  if (((char)plVar2[1] == '\0') && (*(int *)((longlong)plVar2 + 0xc) != 0)) {
    piVar9 = (int *)*plVar2;
    piVar8 = (int *)FindTunnelCbFromTunnelId((longlong)piVar9);
    if (piVar8 == (int *)0x0) {
      iVar7 = -0x3fffffcc;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) == 0) {
        return -0x3fffffcc;
      }
      McTemplateK0sx_EtwWriteTransfer
                (piVar9,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                 "AgileVpnInitiateUpdateClientTunnel: Could not found Tunnel Id from the list of TUNNELCB\'s. TunnelID:"
                 ,(char)*plVar2);
      piVar8 = piVar9;
    }
    else {
      piVar9 = piVar8 + 0xe;
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar9);
      *(undefined1 *)(piVar8 + 0x10) = uVar6;
      if ((char)((ulonglong)(uint)piVar8[0x35] & 0xffffffffffffff24) != '\x04') {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0s_EtwWriteTransfer
                    ((ulonglong)(uint)piVar8[0x35] & 0xffffffffffffff24,&RasAgileVpnTraceError,
                     &DAT_14000f3f8,
                     "AgileVpnInitiateUpdateClientTunnel: Tunnel is going down and not accepting these IOCTLS"
                    );
        }
        KeReleaseSpinLock(piVar9,(char)piVar8[0x10]);
        DereferenceRefCount(piVar8);
        return -0x3fffff45;
      }
      NVar1 = piVar8[0x17];
      piVar8[0x17] = *(int *)((longlong)plVar2 + 0xc);
      KeReleaseSpinLock(piVar9,uVar6);
      uVar6 = KeAcquireSpinLockRaiseToDpc(piVar9);
      piVar8[0x35] = piVar8[0x35] & 0xfffffeff;
      *(undefined1 *)(piVar8 + 0x10) = uVar6;
      KeReleaseSpinLock(piVar9,uVar6);
      pSVar10 = (SOCKADDR_INET *)(piVar8 + 0x1f);
      iVar7 = NsiCliAddOrDeleteHostRouteToInterface(pSVar10,NVar1,'\0');
      if ((iVar7 < 0) && ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0)) {
        McTemplateK0sx_EtwWriteTransfer
                  (pSVar10,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                   "AgileVpnInitiateUpdateClientTunnel: DeleteHostSpecificRoute: failed with Status"
                   ,(char)iVar7);
      }
      pSVar10 = (SOCKADDR_INET *)(plVar2 + 6);
      iVar7 = NsiCliAddOrDeleteHostRouteToInterface
                        (pSVar10,*(NET_IFINDEX *)((longlong)plVar2 + 0xc),'\x01');
      if (iVar7 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (pSVar10,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                     "AgileVpnInitiateUpdateClientTunnel: AddHostSpecificRoute: failed with Status",
                     (char)iVar7);
        }
      }
      else {
        uVar6 = KeAcquireSpinLockRaiseToDpc(piVar9);
        piVar8[0x35] = piVar8[0x35] | 0x500;
        *(undefined1 *)(piVar8 + 0x10) = uVar6;
        if (*(char *)((longlong)plVar2 + 9) != '\0') {
          iVar3 = *(int *)((longlong)plVar2 + 0x14);
          lVar5 = plVar2[3];
          iVar4 = *(int *)((longlong)plVar2 + 0x1c);
          piVar8[0x18] = (int)plVar2[2];
          piVar8[0x19] = iVar3;
          piVar8[0x1a] = (int)lVar5;
          piVar8[0x1b] = iVar4;
          *(longlong *)(piVar8 + 0x1c) = plVar2[4];
          piVar8[0x1e] = (int)plVar2[5];
        }
        if (*(char *)((longlong)plVar2 + 0x2c) != '\0') {
          iVar3 = *(int *)((longlong)plVar2 + 0x34);
          lVar5 = plVar2[7];
          iVar4 = *(int *)((longlong)plVar2 + 0x3c);
          piVar8[0x1f] = (int)plVar2[6];
          piVar8[0x20] = iVar3;
          piVar8[0x21] = (int)lVar5;
          piVar8[0x22] = iVar4;
          *(longlong *)(piVar8 + 0x23) = plVar2[8];
          piVar8[0x25] = (int)plVar2[9];
        }
        KeReleaseSpinLock(piVar9,uVar6);
      }
      DereferenceRefCount(piVar8);
    }
  }
  else {
    iVar7 = -0x3ffffff3;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar8,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnInitiateUpdateClientTunnel: Some of the fields in AGILEVPN_TNNEL_INFO are not set"
                );
    }
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (piVar8,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnInitiateUpdateClientTunnel: is exited with Status",(char)iVar7);
  }
  return iVar7;
}



===== AgileVpnNewIncomingConnection @ 14001e4f8 =====

uint AgileVpnNewIncomingConnection(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  undefined1 uVar9;
  uint uVar10;
  int *piVar11;
  undefined8 uVar12;
  longlong lVar13;
  int *piVar14;
  undefined *puVar15;
  int *piVar16;
  char *pcVar17;
  int *local_res20;
  
  piVar14 = (int *)0x0;
  piVar11 = param_1;
  bVar8 = IsSapValid();
  if (!bVar8) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar11,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnNewIncomingConnection: Invalid SAP");
    }
    return 0xc0010020;
  }
  if (param_2 < 0x60) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (piVar11,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "AgileVpnNewIncomingConnection: Input Buffer Length is not sufficient");
    }
    return 0xc0000023;
  }
  plVar5 = *(longlong **)(param_1 + 6);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (piVar11,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnNewIncomingConnection: is called with ID ",(char)*plVar5);
  }
  if ((((char)plVar5[1] == '\0') || (*(char *)((longlong)plVar5 + 0x2c) == '\0')) ||
     (*(char *)((longlong)plVar5 + 9) == '\0')) {
    uVar10 = 0xc000000d;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_14001e74e;
    McTemplateK0s_EtwWriteTransfer
              (piVar11,&RasAgileVpnTraceError,&DAT_14000f3f8,
               "AgileVpnNewIncomingConnection: Few fields in AGILEVPN_TUNNEL_INFO are not set");
    uVar10 = 0xc000000d;
  }
  else {
    piVar11 = (int *)FindTunnelCbFromTunnelId(*plVar5);
    local_res20 = piVar11;
    if (piVar11 != (int *)0x0) {
      uVar10 = 0xc000022a;
      DereferenceRefCount(piVar11);
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (piVar11,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                   "AgileVpnCreateTunnel: Already a new incoming connection exists for the tunnelId"
                   ,(char)*plVar5);
      }
      goto LAB_14001e74e;
    }
    piVar11 = (int *)0x0;
    uVar12 = AgileVpnCmCreateVc(0,0,&local_res20);
    piVar14 = local_res20;
    if ((int)(uint)uVar12 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (piVar11,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,
                   "AgileVpnNewIncomingConnection: AgileVpnCmCreateVc: failed",(char)uVar12);
      }
      piVar14 = local_res20;
      uVar10 = (uint)uVar12;
    }
    else {
      piVar11 = local_res20 + 0xe;
      piVar1 = local_res20 + 0x10;
      uVar9 = KeAcquireSpinLockRaiseToDpc(piVar11);
      *(undefined1 *)piVar1 = uVar9;
      *(longlong *)(piVar14 + 0x2a) = *plVar5;
      uVar12 = *(undefined8 *)((longlong)plVar5 + 0x54);
      *(undefined8 *)(piVar14 + 0x26) = *(undefined8 *)((longlong)plVar5 + 0x4c);
      *(undefined8 *)(piVar14 + 0x28) = uVar12;
      *(undefined1 *)(piVar14 + 0x16) = 1;
      lVar13 = plVar5[7];
      *(longlong *)(piVar14 + 0x1f) = plVar5[6];
      *(longlong *)(piVar14 + 0x21) = lVar13;
      *(longlong *)(piVar14 + 0x23) = plVar5[8];
      piVar14[0x25] = (int)plVar5[9];
      iVar6 = *(int *)((longlong)plVar5 + 0x14);
      lVar13 = plVar5[3];
      iVar7 = *(int *)((longlong)plVar5 + 0x1c);
      piVar14[0x18] = (int)plVar5[2];
      piVar14[0x19] = iVar6;
      piVar14[0x1a] = (int)lVar13;
      piVar14[0x1b] = iVar7;
      *(longlong *)(piVar14 + 0x1c) = plVar5[4];
      piVar14[0x1e] = (int)plVar5[5];
      KeReleaseSpinLock(piVar11,(char)*piVar1);
      piVar16 = piVar14;
      uVar12 = AddTunnelCbToTunnelIdHashTable(piVar14);
      uVar10 = (uint)uVar12;
      if ((int)uVar10 < 0) {
        piVar11 = piVar16;
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          pcVar17 = 
          "AgileVpnNewIncomingConnection: AddTunnelCbToTunnelIdHashTable failed with Status";
LAB_14001e725:
          McTemplateK0sx_EtwWriteTransfer
                    (piVar16,&RasAgileVpnTraceIntArgError,&DAT_14000f3f8,pcVar17,(char)uVar10);
          piVar11 = piVar16;
        }
        goto LAB_14001e739;
      }
      puVar15 = &DAT_1400144f0;
      DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc();
      if (DAT_140012270 == 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          pcVar17 = "Globals.Adapter.NdisAfHandle NULL";
LAB_14001eb60:
          McTemplateK0s_EtwWriteTransfer(puVar15,&RasAgileVpnTraceInfo,&DAT_14000f3f8,pcVar17);
        }
        if (DAT_140012240 == 0) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            pcVar17 = "Globals.Adapter.MiniportAdapterHandle NULL";
            goto LAB_14001eb97;
          }
        }
        else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          pcVar17 = "Globals.Adapter.MiniportAdapterHandle NOTNULL";
LAB_14001eb97:
          McTemplateK0s_EtwWriteTransfer(puVar15,&RasAgileVpnTraceInfo,&DAT_14000f3f8,pcVar17);
        }
LAB_14001e9f8:
        piVar11 = (int *)&DAT_1400144f0;
        KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          puVar15 = &RasAgileVpnTraceError;
LAB_14001ea14:
          McTemplateK0s_EtwWriteTransfer
                    (piVar11,puVar15,&DAT_14000f3f8,
                     "AgileVpnNewIncomingConnection: Invalid SAP State");
        }
LAB_14001ea23:
        uVar10 = 0xc0010020;
      }
      else {
        if (DAT_140012240 == 0) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
            pcVar17 = "Globals.Adapter.NdisAfHandle NOTNULL";
            puVar15 = (undefined *)0x0;
            goto LAB_14001eb60;
          }
          goto LAB_14001e9f8;
        }
        piVar2 = piVar14 + 0x12;
        uVar10 = NdisMCmCreateVc(DAT_140012240,DAT_140012270,piVar14,piVar2);
        piVar16 = (int *)&DAT_1400144f0;
        KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
        if ((int)uVar10 < 0) {
          piVar11 = piVar16;
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar17 = "AgileVpnNewIncomingConnection: NdisMCmCreateVc failed with Status";
            goto LAB_14001e725;
          }
        }
        else {
          uVar9 = KeAcquireSpinLockRaiseToDpc(piVar11);
          puVar3 = (uint *)(piVar14 + 0x35);
          *(undefined1 *)piVar1 = uVar9;
          *puVar3 = *puVar3 | 0x40;
          KeReleaseSpinLock(piVar11,(char)*piVar1);
          piVar16 = piVar14;
          lVar13 = BuildCallParams((longlong)piVar14);
          if (lVar13 != 0) {
            uVar9 = KeAcquireSpinLockRaiseToDpc(piVar11);
            *(undefined1 *)piVar1 = uVar9;
            *(longlong *)(piVar14 + 0x14) = lVar13;
            piVar14[0x37] = **(int **)(lVar13 + 8);
            piVar14[0x38] = *(int *)(*(longlong *)(lVar13 + 8) + 0x18);
            *(int **)(piVar14 + 0x3a) = param_1;
            KeReleaseSpinLock(piVar11,(char)*piVar1);
            puVar15 = &DAT_1400144f0;
            DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc();
            if (DAT_140012270 == 0) {
              if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
                pcVar17 = "Globals.Adapter.NdisAfHandle NULL";
LAB_14001eace:
                McTemplateK0s_EtwWriteTransfer(puVar15,&RasAgileVpnTraceInfo,&DAT_14000f3f8,pcVar17)
                ;
              }
              if (DAT_140012240 == 0) {
                if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
                  pcVar17 = "Globals.Adapter.MiniportAdapterHandle NULL";
                  goto LAB_14001eb05;
                }
              }
              else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
                pcVar17 = "Globals.Adapter.MiniportAdapterHandle NOTNULL";
LAB_14001eb05:
                McTemplateK0s_EtwWriteTransfer(puVar15,&RasAgileVpnTraceInfo,&DAT_14000f3f8,pcVar17)
                ;
              }
            }
            else {
              if (DAT_140012240 != 0) {
                puVar15 = &DAT_1400144f0;
                KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
                piVar16 = local_res20;
                LOCK();
                *(code **)(param_1 + 0x1a) = CancelIncomingCallIrp;
                UNLOCK();
                if ((char)param_1[0x11] == '\0') {
                  *(byte *)(*(longlong *)(param_1 + 0x2e) + 3) =
                       *(byte *)(*(longlong *)(param_1 + 0x2e) + 3) | 1;
                }
                else {
                  LOCK();
                  lVar4 = *(longlong *)(param_1 + 0x1a);
                  *(longlong *)(param_1 + 0x1a) = 0;
                  UNLOCK();
                  if (lVar4 != 0) {
                    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
                      McTemplateK0s_EtwWriteTransfer
                                (puVar15,&RasAgileVpnTraceError,&DAT_14000f3f8,
                                 "AgileVpnNewIncomingConnection: Dispatch IRP cancelled");
                    }
                    param_1[0xe] = 0;
                    param_1[0xf] = 0;
                    uVar10 = 0xc0000120;
                    param_1[0xc] = -0x3ffffee0;
                    uVar9 = KeAcquireSpinLockRaiseToDpc(piVar11);
                    *(undefined1 *)piVar1 = uVar9;
                    piVar14[0x3a] = 0;
                    piVar14[0x3b] = 0;
                    KeReleaseSpinLock(piVar11,(char)*piVar1);
                    piVar14 = local_res20;
                    goto LAB_14001e739;
                  }
                }
                *(int **)(param_1 + 0x1e) = local_res20;
                DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
                piVar14 = piVar16;
                if (DAT_140012278 != (int *)0x0) {
                  KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
                  uVar9 = KeAcquireSpinLockRaiseToDpc(piVar11);
                  *(undefined1 *)piVar1 = uVar9;
                  *puVar3 = *puVar3 | 0x200;
                  KeReleaseSpinLock(piVar11,(char)*piVar1);
                  piVar11 = DAT_140012278;
                  uVar10 = NdisCmDispatchIncomingCall(DAT_140012278,*(undefined8 *)piVar2,lVar13);
                  if (uVar10 != 0x103) {
                    piVar11 = (int *)(ulonglong)uVar10;
                    AgileVpnCmIncomingCallComplete(uVar10,piVar16);
                    uVar10 = 0x103;
                  }
                  goto LAB_14001e74e;
                }
                goto LAB_14001e9f8;
              }
              if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
                pcVar17 = "Globals.Adapter.NdisAfHandle NOTNULL";
                goto LAB_14001eace;
              }
            }
            piVar11 = (int *)&DAT_1400144f0;
            KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
              puVar15 = &RasAgileVpnTraceInfo;
              goto LAB_14001ea14;
            }
            goto LAB_14001ea23;
          }
          piVar11 = piVar16;
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (piVar16,&RasAgileVpnTraceError,&DAT_14000f3f8,
                       "AgileVpnNewIncomingConnection: BuildCallParams failed");
            piVar11 = piVar16;
          }
          uVar10 = 0xc0000001;
        }
      }
LAB_14001e739:
    }
  }
  if (piVar14 != (int *)0x0) {
    InitiateConnectionCleanup(piVar14,uVar10);
    piVar11 = piVar14;
  }
LAB_14001e74e:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (piVar11,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnNewIncomingConnection: is exited with",(char)uVar10);
  }
  if (-1 < (int)uVar10) {
    uVar10 = 0x103;
  }
  return uVar10;
}



===== AgileVpnUpdateConfiguredTS @ 14001ebe4 =====

int AgileVpnUpdateConfiguredTS(int *param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  int *piVar2;
  int *local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res20 = (int *)0x0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    param_3 = &DAT_14000f3f8;
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"AgileVpnUpdateConfiguredTS: is called")
    ;
  }
  iVar1 = UpdateTunnelTSHelper((longlong)param_1,param_2,param_3,local_18,&local_res20);
  piVar2 = local_res20;
  if (iVar1 == 0) {
    if (*(char *)(local_18[0] + 8) == '\0') {
      param_1 = local_res20;
      iVar1 = UpdateConfiguredTSInfo((longlong)local_res20,(uint *)(local_18[0] + 0x10));
    }
    else {
      iVar1 = -0x3ffffff3;
    }
  }
  if (piVar2 != (int *)0x0) {
    DereferenceRefCount(piVar2);
    param_1 = piVar2;
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnUpdateConfiguredTS: is exited with Status ",(char)iVar1);
  }
  return iVar1;
}



===== AgileVpnUpdateTunnelTS @ 14001ecb4 =====

int AgileVpnUpdateTunnelTS(uint *param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  uint *puVar2;
  uint *local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res20 = (uint *)0x0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    param_3 = &DAT_14000f3f8;
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"AgileVpnUpdateTunnelTS: is called");
  }
  iVar1 = UpdateTunnelTSHelper((longlong)param_1,param_2,param_3,local_18,&local_res20);
  puVar2 = local_res20;
  if (iVar1 == 0) {
    param_1 = local_res20;
    iVar1 = UpdateTSInfo(local_res20,(uint *)(local_18[0] + 0x10),*(byte *)(local_18[0] + 8));
  }
  if (puVar2 != (uint *)0x0) {
    DereferenceRefCount((int *)puVar2);
    param_1 = puVar2;
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "AgileVpnUpdateTunnelTS: is exited with Status ",(char)iVar1);
  }
  return iVar1;
}



===== CancelIncomingCallIrp @ 14001ed80 =====

void CancelIncomingCallIrp(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"CancelIncomingCallIrp: is called");
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  piVar1 = *(int **)(param_2 + 0x78);
  if (piVar1 != (int *)0x0) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 0xe);
    piVar1[0x3a] = 0;
    piVar1[0x3b] = 0;
    *(undefined1 *)(piVar1 + 0x10) = uVar2;
    KeReleaseSpinLock(piVar1 + 0xe,uVar2);
    InitiateConnectionCleanup(piVar1,0xc0000120);
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,2);
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (param_2,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
               "CancelIncomingCallIrp: is exited with",0);
  }
  return;
}



===== IsFiltersMatched @ 14001ee60 =====

undefined1 IsFiltersMatched(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  while( true ) {
    if (param_1 == 0) {
      return 1;
    }
    if (param_2 == 0) break;
    lVar1 = RtlCompareMemory(param_1,param_2,0x2c);
    if (lVar1 != 0x2c) {
      return 0;
    }
    param_1 = *(longlong *)(param_1 + 0x30);
    param_2 = *(longlong *)(param_2 + 0x30);
  }
  return 1;
}



===== PrintTSInfo @ 14001eec8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PrintTSInfo(short *param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStack_108 [32];
  uint local_e8;
  uint local_e0;
  uint local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined2 local_b8;
  undefined8 local_b6;
  undefined8 uStack_ae;
  undefined8 local_a6;
  undefined8 uStack_9e;
  undefined8 local_96;
  undefined8 uStack_8e;
  undefined8 local_86;
  undefined4 local_7e;
  undefined2 local_7a;
  undefined1 local_78;
  undefined2 local_68;
  undefined8 local_66;
  undefined8 uStack_5e;
  undefined8 local_56;
  undefined8 uStack_4e;
  undefined8 local_46;
  undefined8 uStack_3e;
  undefined8 local_36;
  undefined4 local_2e;
  undefined2 local_2a;
  undefined1 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_108;
  local_36 = 0;
  local_2e = 0;
  local_68 = 0;
  local_66 = 0;
  uStack_5e = 0;
  local_2a = 0;
  local_56 = 0;
  uStack_4e = 0;
  local_28 = 0;
  local_46 = 0;
  uStack_3e = 0;
  local_b8 = 0;
  local_b6 = 0;
  uStack_ae = 0;
  local_86 = 0;
  local_a6 = 0;
  uStack_9e = 0;
  local_7e = 0;
  local_96 = 0;
  uStack_8e = 0;
  local_7a = 0;
  local_78 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (0,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"Traffic Selector--------------");
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      uVar1 = GetStringFromAddr(param_1 + 10,*param_1,&local_b8);
      local_d0 = GetStringFromAddr(param_1 + 2,*param_1,&local_68);
      uVar2 = (ulonglong)*(byte *)(param_1 + 0x15);
      local_d8 = (uint)*(byte *)(param_1 + 0x15);
      local_e0 = (uint)(ushort)param_1[0x14];
      local_e8 = (uint)(ushort)param_1[0x13];
      local_c8 = uVar1;
      McTemplateK0qqqqss_EtwWriteTransfer();
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (uVar2,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"Traffic Selector---------------");
      }
    }
  }
  return;
}



===== RemoveDormantTSNodes @ 14001f000 =====

void RemoveDormantTSNodes(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  
  plVar6 = (longlong *)*param_1;
  do {
    if (plVar6 == param_1) {
      return;
    }
    plVar1 = plVar6 + -1;
    if (((((char)plVar6[2] != '\0') &&
         (*(int *)((longlong)plVar6 + 0x14) == *(int *)(param_2 + 0x1c))) &&
        ((int)plVar6[3] == *(int *)(param_2 + 0x20))) &&
       (cVar4 = IsFiltersMatched(plVar6[4],*(longlong *)(param_2 + 0x28)), cVar4 != '\0')) {
      lVar5 = plVar6[5];
      cVar4 = IsFiltersMatched(lVar5,*(longlong *)(param_2 + 0x30));
      if (cVar4 != '\0') {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (lVar5,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                     "Dormant TS ID is beeing removed. TSID:",(char)*plVar1);
        }
        DeleteCurrentTSTRList((longlong)plVar1);
        lVar5 = *plVar6;
        if ((*(longlong **)(lVar5 + 8) == plVar6) &&
           (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 == plVar6)) {
          *plVar2 = lVar5;
          *(longlong **)(lVar5 + 8) = plVar2;
          ExFreeToNPagedLookasideList(&DAT_140012340,plVar1);
          return;
        }
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
    plVar6 = (longlong *)*plVar6;
  } while( true );
}



===== TSInputValidationHelper @ 14001f0f0 =====

undefined4 TSInputValidationHelper(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  if (0xffffffff < (ulonglong)param_1[4] * 0x2c) {
    return 0xc000000d;
  }
  uVar1 = (uint)((ulonglong)param_1[4] * 0x2c);
  uVar2 = param_1[5] + uVar1;
  if (uVar2 < uVar1) {
    iVar3 = -0x3fffff6b;
LAB_14001f169:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_14001f18c;
    pcVar4 = "TSInputValidationHelper: Invalid TSI Parameter";
  }
  else {
    iVar3 = 0;
    if ((param_1[5] < 0x20) || (*param_1 < uVar2)) goto LAB_14001f169;
    if (0xffffffff < (ulonglong)param_1[6] * 0x2c) {
      return 0xc000000d;
    }
    uVar1 = (uint)((ulonglong)param_1[6] * 0x2c);
    uVar2 = param_1[7] + uVar1;
    if (uVar2 < uVar1) {
      iVar3 = -0x3fffff6b;
    }
    else if ((0x1f < param_1[7]) && (uVar2 <= *param_1)) {
      return 0;
    }
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_14001f18c;
    pcVar4 = "TSInputValidationHelper: Invalid TSR Parameter";
  }
  McTemplateK0s_EtwWriteTransfer(param_1,&RasAgileVpnTraceError,&DAT_14000f3f8,pcVar4);
LAB_14001f18c:
  if (iVar3 == 0) {
    return 0;
  }
  return 0xc000000d;
}



===== UpdateConfiguredTSInfo @ 14001f1a4 =====

int UpdateConfiguredTSInfo(longlong param_1,uint *param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  uint *puVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined1 *puVar9;
  uint *local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined1 local_28;
  undefined1 local_27 [7];
  longlong local_20;
  
  local_20 = 0;
  local_27[0] = 0;
  local_28 = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  puVar6 = param_2;
  local_res10 = param_2;
  iVar3 = TSInputValidationHelper(param_2);
  if (iVar3 == 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0xq_EtwWriteTransfer
                (puVar6,&RasAgileVpnTraceUpdateTs,&DAT_14000f3f8,*(undefined8 *)(param_2 + 2),1);
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
    *(undefined1 *)(param_1 + 0x108) = uVar2;
    plVar7 = &local_20;
    uVar4 = UpdateTSListHelper(plVar7,(longlong *)&local_res10,local_27,&local_28,local_res20,
                               local_res18);
    puVar9 = auStackY_58;
    iVar3 = (int)uVar4;
    if (iVar3 == 0) {
      plVar7 = (longlong *)(param_1 + 0x120);
      lVar8 = *plVar7;
      plVar5 = (longlong *)(local_20 + 8);
      if (*(longlong **)(lVar8 + 8) != plVar7) {
        plVar7 = (longlong *)0x3;
        pcVar1 = (code *)swi(0x29);
        plVar5 = (longlong *)(*pcVar1)();
        puVar9 = auStackY_50;
      }
      *plVar5 = lVar8;
      plVar5[1] = (longlong)plVar7;
      *(longlong **)(lVar8 + 8) = plVar5;
      *plVar7 = (longlong)plVar5;
    }
    else {
      puVar9 = auStackY_58;
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (plVar7,&RasAgileVpnTraceError,&DAT_14000f3f8,
                   "UpdateTSInfo: TS list update helper failed");
        puVar9 = auStackY_58;
      }
    }
    uVar2 = *(undefined1 *)(param_1 + 0x108);
    *(undefined8 *)(puVar9 + -8) = 0x14001f2b8;
    KeReleaseSpinLock(param_1 + 0x100,uVar2);
  }
  return iVar3;
}



===== UpdateTSInfo @ 14001f2d4 =====

int UpdateTSInfo(uint *param_1,uint *param_2,byte param_3)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined1 *puVar11;
  char *pcVar12;
  char cVar13;
  ulonglong uVar14;
  uint *local_res10;
  char local_res18 [8];
  char local_res20 [8];
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  char local_58;
  char local_57;
  char local_56;
  uint *local_50;
  uint *local_48;
  
  uVar14 = (ulonglong)param_3;
  local_56 = '\0';
  puVar9 = (uint *)0x0;
  local_50 = (uint *)0x0;
  local_res18[0] = '\0';
  local_res20[0] = '\0';
  local_58 = '\0';
  local_57 = '\0';
  puVar8 = param_1;
  local_res10 = param_2;
  if ((param_3 == 0) && (puVar8 = param_2, iVar5 = TSInputValidationHelper(param_2), iVar5 != 0)) {
    return iVar5;
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0xq_EtwWriteTransfer
              (puVar8,&RasAgileVpnTraceUpdateTs,&DAT_14000f3f8,*(undefined8 *)(param_2 + 2),param_3)
    ;
  }
  local_48 = param_1 + 0x40;
  uVar4 = KeAcquireSpinLockRaiseToDpc(local_48);
  puVar11 = auStackY_88;
  puVar8 = param_1 + 0x44;
  *(undefined1 *)(param_1 + 0x42) = uVar4;
  for (puVar10 = *(uint **)puVar8; puVar10 != puVar8; puVar10 = *(uint **)puVar10) {
    puVar9 = puVar10 + -2;
    local_50 = puVar9;
    if (*(longlong *)puVar9 == *(longlong *)(param_2 + 2)) {
      cVar13 = '\x01';
      goto LAB_14001f3a4;
    }
  }
  cVar13 = local_56;
LAB_14001f3a4:
  if (param_3 == 0) {
    uVar14 = 0;
    if (cVar13 != '\0') {
      DeleteCurrentTSTRList((longlong)puVar9);
      lVar7 = *(longlong *)puVar10;
      if ((*(uint **)(lVar7 + 8) != puVar10) ||
         (plVar1 = *(longlong **)(puVar10 + 2), (uint *)*plVar1 != puVar10)) goto LAB_14001f4fe;
      *plVar1 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar1;
      ExFreeToNPagedLookasideList(&DAT_140012340,puVar9);
    }
    uVar6 = UpdateTSListHelper(&local_50,(longlong *)&local_res10,local_res18,local_res20,&local_58,
                               &local_57);
    puVar9 = local_50;
    iVar5 = (int)uVar6;
    if (iVar5 != 0) {
      puVar9 = param_1 + 0x40;
      KeReleaseSpinLock(puVar9,(char)param_1[0x42]);
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
        return iVar5;
      }
      pcVar12 = "UpdateTSInfo: TS list update helper failed";
LAB_14001f3db:
      McTemplateK0s_EtwWriteTransfer(puVar9,&RasAgileVpnTraceError,&DAT_14000f3f8,pcVar12);
      return iVar5;
    }
    puVar10 = puVar8;
    RemoveDormantTSNodes((longlong *)puVar8,(longlong)local_50);
    puVar11 = auStackY_88;
    lVar7 = *(longlong *)puVar8;
    puVar9 = puVar9 + 2;
    if (*(uint **)(lVar7 + 8) != puVar8) goto LAB_14001f4fe;
  }
  else {
    if (cVar13 == '\0') {
      iVar5 = -0x3fffffcc;
      puVar9 = local_48;
      KeReleaseSpinLock(local_48,uVar4);
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
        return -0x3fffffcc;
      }
      pcVar12 = "UpdateTSInfo: Delete object not found";
      goto LAB_14001f3db;
    }
    puVar10 = puVar9 + 2;
    *(undefined1 *)(puVar9 + 6) = 1;
    lVar7 = *(longlong *)puVar10;
    if ((*(uint **)(lVar7 + 8) == puVar10) &&
       (plVar1 = *(longlong **)(puVar9 + 4), (uint *)*plVar1 == puVar10)) {
      *plVar1 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar1;
      plVar1 = *(longlong **)(param_1 + 0x46);
      if ((uint *)*plVar1 == puVar8) {
        *(uint **)puVar10 = puVar8;
        *(longlong **)(puVar9 + 4) = plVar1;
        *plVar1 = (longlong)puVar10;
        *(uint **)(param_1 + 0x46) = puVar10;
        goto LAB_14001f5f2;
      }
    }
LAB_14001f4fe:
    puVar10 = (uint *)0x3;
    pcVar2 = (code *)swi(0x29);
    lVar7 = (*pcVar2)();
    puVar11 = auStackY_80;
  }
  *(longlong *)puVar9 = lVar7;
  *(uint **)(puVar9 + 2) = puVar8;
  *(uint **)(lVar7 + 8) = puVar9;
  *(uint **)puVar8 = puVar9;
  cVar13 = (char)uVar14;
  if ((local_res18[0] == cVar13) || (local_res20[0] == cVar13)) {
    *(ulonglong *)(param_1 + 0x3c) = uVar14;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      *(undefined8 *)(puVar11 + -8) = 0x14001f584;
      McTemplateK0s_EtwWriteTransfer
                (puVar10,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
                 "UpdateTSInfo: Removing TS ID optimization for all-traffic (for IPv4)");
    }
  }
  else {
    puVar10 = *(uint **)(param_2 + 2);
    *(uint **)(param_1 + 0x3c) = puVar10;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      *(uint **)(puVar11 + 0x20) = puVar10;
      *(undefined8 *)(puVar11 + -8) = 0x14001f555;
      McTemplateK0sx_EtwWriteTransfer
                (puVar10,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                 "UpdateTSInfo: Caching TS ID (for IPv4)(Optimization for ANY set of filters):",
                 puVar11[0x20]);
    }
  }
  if ((local_58 == cVar13) || (local_57 == cVar13)) {
    *(ulonglong *)(param_1 + 0x3e) = uVar14;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      *(undefined8 *)(puVar11 + -8) = 0x14001f5f2;
      McTemplateK0s_EtwWriteTransfer
                (puVar10,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
                 "UpdateTSInfo: Removing TS ID optimization for all-traffic (for IPv6)");
    }
  }
  else {
    *(undefined8 *)(param_1 + 0x3e) = *(undefined8 *)(param_2 + 2);
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      *(undefined8 *)(puVar11 + 0x20) = *(undefined8 *)(param_1 + 0x3c);
      *(undefined8 *)(puVar11 + -8) = 0x14001f5c6;
      McTemplateK0sx_EtwWriteTransfer
                (puVar10,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                 "UpdateTSInfo: Caching TS ID (for IPv6)(Optimization for ANY set of filters):",
                 puVar11[0x20]);
    }
  }
LAB_14001f5f2:
  uVar3 = param_1[0x42];
  *(undefined8 *)(puVar11 + -8) = 0x14001f606;
  KeReleaseSpinLock(param_1 + 0x40,(char)uVar3);
  return 0;
}



===== UpdateTSListHelper @ 14001f630 =====

undefined8
UpdateTSListHelper(undefined8 *param_1,longlong *param_2,undefined1 *param_3,undefined1 *param_4,
                  undefined1 *param_5,undefined1 *param_6)

{
  undefined8 *puVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  longlong *plVar5;
  ushort *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  ushort *puVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  ushort *puVar12;
  undefined8 uVar13;
  uint uVar14;
  longlong lVar15;
  
  puVar11 = &DAT_140012340;
  uVar13 = 0;
  plVar5 = (longlong *)ExAllocateFromNPagedLookasideList();
  if (plVar5 == (longlong *)0x0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar11,&RasAgileVpnTraceError,&DAT_14000f3f8,
                 "UpdateTSListHelper: NdisAllocateFromNPagedLookasideList returned NULL");
    }
    uVar13 = 0xc000009a;
  }
  else {
    *plVar5 = 0;
    puVar12 = *(ushort **)(*param_2 + 8);
    *plVar5 = (longlong)puVar12;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar12,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"UpdateTSListHelper: TSI LIST........"
                );
    }
    lVar7 = *param_2;
    lVar15 = (ulonglong)*(uint *)(lVar7 + 0x14) + lVar7;
    *(undefined4 *)((longlong)plVar5 + 0x1c) = *(undefined4 *)(lVar7 + 0x10);
    puVar9 = (ushort *)0x0;
    for (uVar14 = 0; uVar14 < *(uint *)(*param_2 + 0x10); uVar14 = uVar14 + 1) {
      puVar11 = &DAT_1400123c0;
      puVar6 = (ushort *)ExAllocateFromNPagedLookasideList();
      if (puVar6 == (ushort *)0x0) goto LAB_14001f920;
      lVar7 = (ulonglong)uVar14 * 0x2c;
      uVar8 = ((undefined8 *)(lVar7 + lVar15))[1];
      *(undefined8 *)puVar6 = *(undefined8 *)(lVar7 + lVar15);
      *(undefined8 *)(puVar6 + 4) = uVar8;
      puVar1 = (undefined8 *)(lVar7 + 0x10 + lVar15);
      uVar8 = puVar1[1];
      *(undefined8 *)(puVar6 + 8) = *puVar1;
      *(undefined8 *)(puVar6 + 0xc) = uVar8;
      *(undefined8 *)(puVar6 + 0x10) = *(undefined8 *)(lVar7 + 0x20 + lVar15);
      *(undefined4 *)(puVar6 + 0x14) = *(undefined4 *)(lVar7 + 0x28 + lVar15);
      if (puVar9 == (ushort *)0x0) {
        plVar5[5] = (longlong)puVar6;
      }
      else {
        *(ushort **)(puVar9 + 0x18) = puVar6;
      }
      puVar6[0x18] = 0;
      puVar6[0x19] = 0;
      puVar6[0x1a] = 0;
      puVar6[0x1b] = 0;
      PrintTSInfo((short *)puVar6);
      uVar8 = IsAllowAllPorts(puVar6[0x13],puVar6[0x14]);
      if ((char)uVar8 != '\0') {
        *(undefined1 *)((longlong)puVar6 + 0x25) = 1;
      }
      puVar12 = puVar6 + 2;
      cVar4 = IsAllowAllAddresses(puVar12,puVar6 + 10,*puVar6);
      if (cVar4 != '\0') {
        *(undefined1 *)(puVar6 + 0x12) = 1;
      }
      if ((((char)puVar6[0x12] != '\0') && (*(char *)((longlong)puVar6 + 0x25) != '\0')) &&
         ((char)puVar6[0x15] == '\0')) {
        uVar2 = *puVar6;
        puVar12 = (ushort *)(ulonglong)uVar2;
        puVar10 = param_3;
        if (uVar2 != 2) {
          puVar10 = param_5;
        }
        bVar3 = Microsoft_Windows_Ras_AgileVpnEnableBits & 8;
        *puVar10 = 1;
        if (bVar3 != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (puVar12,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                     "UpdateTSListHelper: TSI filter: ANY to ANY for Address family",(char)uVar2);
        }
      }
      puVar9 = puVar6;
    }
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar12,&RasAgileVpnTraceInfo,&DAT_14000f3f8,
                 "UpdateTSListHelper: TSR LIST..............");
    }
    lVar7 = *param_2;
    lVar15 = (ulonglong)*(uint *)(lVar7 + 0x1c) + lVar7;
    *(undefined4 *)(plVar5 + 4) = *(undefined4 *)(lVar7 + 0x18);
    puVar12 = (ushort *)0x0;
    for (uVar14 = 0; uVar14 < *(uint *)(*param_2 + 0x18); uVar14 = uVar14 + 1) {
      puVar11 = &DAT_1400123c0;
      puVar9 = (ushort *)ExAllocateFromNPagedLookasideList();
      if (puVar9 == (ushort *)0x0) goto LAB_14001f920;
      lVar7 = (ulonglong)uVar14 * 0x2c;
      uVar8 = ((undefined8 *)(lVar7 + lVar15))[1];
      *(undefined8 *)puVar9 = *(undefined8 *)(lVar7 + lVar15);
      *(undefined8 *)(puVar9 + 4) = uVar8;
      puVar1 = (undefined8 *)(lVar7 + 0x10 + lVar15);
      uVar8 = puVar1[1];
      *(undefined8 *)(puVar9 + 8) = *puVar1;
      *(undefined8 *)(puVar9 + 0xc) = uVar8;
      *(undefined8 *)(puVar9 + 0x10) = *(undefined8 *)(lVar7 + 0x20 + lVar15);
      *(undefined4 *)(puVar9 + 0x14) = *(undefined4 *)(lVar7 + 0x28 + lVar15);
      if (puVar12 == (ushort *)0x0) {
        plVar5[6] = (longlong)puVar9;
      }
      else {
        *(ushort **)(puVar12 + 0x18) = puVar9;
      }
      puVar9[0x18] = 0;
      puVar9[0x19] = 0;
      puVar9[0x1a] = 0;
      puVar9[0x1b] = 0;
      PrintTSInfo((short *)puVar9);
      uVar8 = IsAllowAllPorts(puVar9[0x13],puVar9[0x14]);
      if ((char)uVar8 != '\0') {
        *(undefined1 *)((longlong)puVar9 + 0x25) = 1;
      }
      cVar4 = IsAllowAllAddresses(puVar9 + 2,puVar9 + 10,*puVar9);
      if (cVar4 != '\0') {
        *(undefined1 *)(puVar9 + 0x12) = 1;
      }
      if ((((char)puVar9[0x12] != '\0') && (*(char *)((longlong)puVar9 + 0x25) != '\0')) &&
         ((char)puVar9[0x15] == '\0')) {
        uVar2 = *puVar9;
        puVar10 = param_4;
        if (uVar2 != 2) {
          puVar10 = param_6;
        }
        bVar3 = Microsoft_Windows_Ras_AgileVpnEnableBits & 8;
        *puVar10 = 1;
        if (bVar3 != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    ((ulonglong)uVar2,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                     "UpdateTSListHelper: TSR filter: ANY to ANY for Address family",(char)uVar2);
        }
      }
      puVar12 = puVar9;
    }
  }
LAB_14001f964:
  *param_1 = plVar5;
  return uVar13;
LAB_14001f920:
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (puVar11,&RasAgileVpnTraceError,&DAT_14000f3f8,
               "UpdateTSListHelper: NdisAllocateFromNPagedLookasideList returns NULL");
  }
  uVar13 = 0xc000009a;
  DeleteCurrentTSTRList((longlong)plVar5);
  ExFreeToNPagedLookasideList(&DAT_140012340,plVar5);
  plVar5 = (longlong *)0x0;
  goto LAB_14001f964;
}



===== UpdateTunnelTSHelper @ 14001f98c =====

int UpdateTunnelTSHelper
              (longlong param_1,uint param_2,undefined8 param_3,longlong *param_4,
              undefined8 *param_5)

{
  longlong *plVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  
  lVar5 = param_1;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f3f8,"UpdateTunnelTSHelper: is called");
  }
  if (0x2f < param_2) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    plVar1 = *(longlong **)(param_1 + 0x18);
    uVar3 = (int)plVar1[2] + 0x10;
    if ((0xf < uVar3) && (iVar7 = 0, uVar3 <= param_2)) {
      lVar5 = *plVar1;
      puVar4 = FindTunnelCbFromTunnelId(lVar5);
      if (puVar4 == (undefined8 *)0x0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) == 0) {
          return -0x3fffffcc;
        }
        McTemplateK0sx_EtwWriteTransfer
                  (lVar5,&RasAgileVpnTraceIntArgInfo,&DAT_14000f3f8,
                   "UpdateTunnelTSHelper: Could not found Tunnel Id from the list of TUNNELCB\'s. TunnelID:"
                   ,(char)*plVar1);
        return -0x3fffffcc;
      }
      puVar6 = puVar4 + 7;
      uVar2 = KeAcquireSpinLockRaiseToDpc();
      *(undefined1 *)(puVar4 + 8) = uVar2;
      if (((*(uint *)((longlong)puVar4 + 0xd4) & 0x20) != 0) &&
         (iVar7 = -0x3fffff45, (Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0)) {
        McTemplateK0s_EtwWriteTransfer
                  (puVar6,&RasAgileVpnTraceError,&DAT_14000f3f8,
                   "UpdateTunnelTSHelper: Tunnel is going down and not accepting these IOCTLS");
      }
      KeReleaseSpinLock(puVar4 + 7,*(undefined1 *)(puVar4 + 8));
      if (iVar7 == 0) {
        *param_4 = (longlong)plVar1;
        *param_5 = puVar4;
        return 0;
      }
      return iVar7;
    }
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (lVar5,&RasAgileVpnTraceError,&DAT_14000f3f8,
               "UpdateTunnelTSHelper: Input Buffer Length is not sufficient");
  }
  return -0x3fffffdd;
}



===== AddTunnelCbToTunnelIdHashTable @ 14001faf0 =====

undefined8 AddTunnelCbToTunnelIdHashTable(int *param_1)

{
  uint uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  uVar1 = param_1[0x2a];
  uVar7 = 0;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (param_1,&RasAgileVpnTraceInfo,&DAT_14000f540,"AddTunnelCbToTunnelIdHashTable:");
  }
  DAT_1400144c8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144c0);
  puVar6 = auStack_38;
  plVar4 = (longlong *)(&DAT_1400124c0)[(ulonglong)(uVar1 & 0x1ff) * 2];
  plVar3 = plVar4;
  do {
    if (plVar3 == &DAT_1400124c0 + (ulonglong)(uVar1 & 0x1ff) * 2) {
      lVar5 = *plVar4;
      plVar3 = (longlong *)(param_1 + 6);
      if (*(longlong **)(lVar5 + 8) != plVar4) {
        plVar4 = (longlong *)0x3;
        pcVar2 = (code *)swi(0x29);
        plVar3 = (longlong *)(*pcVar2)();
        puVar6 = auStack_30;
      }
      *plVar3 = lVar5;
      plVar3[1] = (longlong)plVar4;
      *(longlong **)(lVar5 + 8) = plVar3;
      *plVar4 = (longlong)plVar3;
      LOCK();
      *param_1 = *param_1 + 1;
      UNLOCK();
LAB_14001fbd1:
      *(undefined8 *)(puVar6 + -8) = 0x14001fbe5;
      KeReleaseSpinLock(&DAT_1400144c0,DAT_1400144c8);
      return uVar7;
    }
    if (plVar3[0x12] == *(longlong *)(param_1 + 0x2a)) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (plVar4,&RasAgileVpnTraceIntArgInfo,&DAT_14000f540,
                   "AddTunnelCbToTunnelIdHashTable: duplicate object found: TunnelID",
                   (char)*(longlong *)(param_1 + 0x2a));
      }
      puVar6 = auStack_38;
      uVar7 = 0xc000022a;
      goto LAB_14001fbd1;
    }
    plVar3 = (longlong *)*plVar3;
  } while( true );
}



===== AgileVpnSetupWfpCallouts @ 14001fc04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AgileVpnSetupWfpCallouts(void)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *_Dst;
  undefined *puVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined1 auStack_2e8 [32];
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined4 local_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 local_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  code *pcStack_268;
  code *local_260;
  undefined8 uStack_258;
  undefined8 local_248;
  undefined8 uStack_240;
  wchar_t *local_238;
  wchar_t *local_230;
  undefined8 local_228;
  undefined *local_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined8 local_1f8;
  undefined8 local_1e8 [2];
  wchar_t *local_1d8;
  wchar_t *local_1d0;
  undefined4 local_1c8;
  undefined *local_1c0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined4 local_188;
  undefined *local_180;
  undefined4 local_178;
  undefined8 *local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined8 *local_150;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  wchar_t *local_108;
  wchar_t *local_100;
  undefined4 local_f8;
  undefined8 local_f4;
  undefined8 local_ec;
  undefined8 local_e4;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  wchar_t *local_c8;
  undefined4 local_b8;
  undefined *local_b0;
  undefined2 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined1 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 local_48;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2e8;
  iVar5 = 0;
  memset(local_1e8,0,200);
  local_280 = 0;
  uStack_278 = 0;
  local_270 = 0;
  pcStack_268 = (code *)0x0;
  local_260 = (code *)0x0;
  uStack_258 = 0;
  memset(&local_248,0,0x58);
  local_2b0 = 0;
  local_2a8 = 0;
  memset(&local_d8,0,0x48);
  _Dst = &local_118;
  memset(_Dst,0,0x40);
  bVar2 = false;
  bVar1 = false;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0s_EtwWriteTransfer
              (_Dst,&RasAgileVpnTraceInfo,&DAT_14000feb8,"Enter AgileVpnSetupWfpCallouts");
  }
  puVar6 = &DAT_140016858;
  iVar4 = KeWaitForSingleObject(&DAT_140016858,0,0,0);
  if (iVar4 != 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar6,&RasAgileVpnTraceError,&DAT_14000feb8,
                 "Exit as KeWaitForMutexObject returned STATUS_ABANDONED_WAIT_0.");
    }
    return -0x3fffffff;
  }
  puVar6 = &DAT_140016820;
  DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
  if (DAT_14001674c != '\0') {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar6,&RasAgileVpnTraceInfo,&DAT_14000feb8,
                 "Bailing on registration in progress/done");
    }
    goto LAB_140020770;
  }
  DAT_14001674c = '\x01';
  iVar5 = 0;
  if ((DAT_140016748 & 1) == 0) {
    DAT_140016748 = DAT_140016748 | 1;
    KeReleaseSpinLock(&DAT_140016820);
    iVar5 = FwpmEngineOpen0(0,10,0,0);
    puVar6 = &DAT_140016820;
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
    if (iVar5 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (puVar6,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,"FwpmEngineOpen fails with",
                   (char)iVar5);
      }
      DAT_140016748 = DAT_140016748 & 0xfffffffe;
      goto LAB_140020770;
    }
    WfpState = 0;
  }
  uVar3 = WfpState;
  if (-1 < (char)DAT_140016748) {
    DAT_140016748 = DAT_140016748 | 0x80;
    KeReleaseSpinLock(&DAT_140016820);
    uVar7 = uVar3;
    iVar5 = FwpmTransactionBegin0(uVar3,0);
    if (iVar5 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar8 = "FwpmTransactionBegin fails with";
LAB_14001fe7f:
        McTemplateK0sx_EtwWriteTransfer
                  (uVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,pcVar8,(char)iVar5);
      }
    }
    else {
      local_108 = L"Microsoft Corporation";
      local_f4 = 0;
      local_100 = L"Microsoft Windows VPN Reconnect Provider";
      local_ec = 0;
      local_e4 = 0;
      local_dc = 0;
      local_118 = _PROVIDER_KEY;
      uStack_114 = uRam0000000140012184;
      uStack_110 = uRam0000000140012188;
      uStack_10c = uRam000000014001218c;
      local_f8 = 1;
      iVar5 = FwpmProviderAdd0(uVar3,&local_118,0);
      uVar7 = 0x80000000;
      if (((iVar5 + 0x80000000U & 0x80000000) == 0) && (iVar5 != -0x3fddfff7)) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          pcVar8 = "FwpmProviderAdd fails with";
          goto LAB_14001fe7f;
        }
      }
      else {
        local_b8 = 1;
        local_c8 = L"VPN Reconnect Sublayer";
        local_98 = 2;
        local_b0 = &PROVIDER_KEY;
        local_d8 = _SUBLAYER_KEY;
        uStack_d4 = uRam0000000140012174;
        uStack_d0 = uRam0000000140012178;
        uStack_cc = uRam000000014001217c;
        iVar5 = FwpmSubLayerAdd0(uVar3,&local_d8,0);
        uVar7 = 0x80000000;
        if (((iVar5 + 0x80000000U & 0x80000000) == 0) && (iVar5 != -0x3fddfff7)) {
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar8 = "FwpmSubLayerAdd fails with";
            goto LAB_14001fe7f;
          }
        }
        else {
          uVar7 = uVar3;
          iVar5 = FwpmTransactionCommit0();
          if (-1 < iVar5) {
            iVar5 = 0;
            DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
            goto LAB_140020027;
          }
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            pcVar8 = "FwpmTransactionCommit fails with";
            goto LAB_14001fe7f;
          }
        }
      }
    }
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
    DAT_140016748 = DAT_140016748 & 0xffffff7f;
    goto LAB_140020770;
  }
LAB_140020027:
  if ((DAT_140016748 & 2) == 0) {
    DAT_140016748 = DAT_140016748 | 2;
    KeReleaseSpinLock(&DAT_140016820);
    pcStack_268 = CallOutClassify;
    local_270 = 0x20;
    local_260 = CallOutNotify;
    uStack_258 = 0;
    local_238 = L"VPN Reconnect IPv4 Callout";
    local_280 = 0x48c50dec26471d37;
    uStack_278 = 0x9198c56f0d58a684;
    local_230 = L"VPN Reconnect Callout for IP-in-IP Framing";
    local_248 = 0x48c50dec26471d37;
    uStack_240 = 0x9198c56f0d58a684;
    local_220 = &PROVIDER_KEY;
    local_208 = 0x5926dfc8;
    uStack_204 = 0x4426e3cf;
    uStack_200 = 0x39dc83a2;
    uStack_1fc = 0x9d0f5d3f;
    iVar5 = FwpiCalloutRegisterAndAddWithoutDevice0(uVar3,&local_280,&local_248,0);
    puVar6 = &DAT_140016820;
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
    if (-1 < iVar5) goto LAB_14002011e;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (puVar6,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                 "FwpiCalloutRegisterAndAddWithoutDevice0 (IPv4) fails with error",(char)iVar5);
    }
    DAT_140016748 = DAT_140016748 & 0xfffffffd;
  }
  else {
LAB_14002011e:
    if ((DAT_140016748 & 4) == 0) {
      DAT_140016748 = DAT_140016748 | 4;
      KeReleaseSpinLock(&DAT_140016820);
      memset(&local_88,0,0x50);
      local_1d8 = L"VPN Reconnect Filter";
      local_88 = 0x4f9a623e3971ef2b;
      uStack_80 = 0xa7b906b8796eb18c;
      local_1d0 = L"VPN Reconnect IPv4 Callout Filter";
      local_60 = 0x4f9a623e3971ef2b;
      uStack_58 = 0xa7b906b8796eb18c;
      local_78 = 0;
      local_1c0 = &PROVIDER_KEY;
      local_180 = &DAT_140016840;
      local_170 = &local_88;
      local_1a8 = 0x4426e3cf5926dfc8;
      uStack_1a0 = 0x9d0f5d3f39dc83a2;
      local_198 = CONCAT44(uRam0000000140012174,_SUBLAYER_KEY);
      uStack_190 = CONCAT44(uRam000000014001217c,uRam0000000140012178);
      local_70 = 1;
      local_68 = 4;
      local_50 = 0;
      local_48 = 1;
      local_40 = 0x29;
      local_164 = 0x26471d37;
      uStack_160 = 0x48c50dec;
      uStack_15c = 0xd58a684;
      uStack_158 = 0x9198c56f;
      local_1c8 = 0;
      local_188 = 4;
      local_178 = 1;
      local_168 = 0x4005;
      local_150 = &DAT_140012240;
      uVar7 = uVar3;
      iVar5 = FwpmFilterAdd0(uVar3,local_1e8,0,&local_2a0);
      if (iVar5 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (uVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "FwpmFilterAddfails (IPv4) with error",(char)iVar5);
        }
      }
      else {
        local_170 = &local_60;
        local_1c8 = 0;
        uVar7 = uVar3;
        iVar5 = FwpmFilterAdd0(uVar3,local_1e8,0,&uStack_298);
        if (-1 < iVar5) {
          DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
          bVar2 = true;
          _DAT_140016830 = local_2a0;
          uRam0000000140016834 = uStack_29c;
          uRam0000000140016838 = uStack_298;
          uRam000000014001683c = uStack_294;
          goto LAB_140020316;
        }
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (uVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "FwpmFilterAddfails (IPv4) with error",(char)iVar5);
        }
        FwpmFilterDeleteById0(uVar3,CONCAT44(uStack_29c,local_2a0));
      }
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      DAT_140016748 = DAT_140016748 & 0xfffffffb;
    }
  }
LAB_140020316:
  if ((DAT_140016748 & 8) == 0) {
    DAT_140016748 = DAT_140016748 | 8;
    KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
    local_270 = 0x20;
    local_228 = 0;
    local_1f8 = 0;
    local_218 = 0;
    uStack_210 = 0;
    pcStack_268 = CallOutClassify;
    uStack_258 = 0;
    local_260 = CallOutNotify;
    local_238 = L"VPN Reconnect IPv6 Callout";
    local_280 = 0x45b8f734f839cdb6;
    uStack_278 = 0x50fbfa5b737c4c8e;
    local_230 = L"VPN Reconnect Callout for IP-in-IP Framing";
    local_248 = 0x45b8f734f839cdb6;
    uStack_240 = 0x50fbfa5b737c4c8e;
    local_220 = &PROVIDER_KEY;
    local_208 = 0x634a869f;
    uStack_204 = 0x4b90fc23;
    uStack_200 = 0x62bfc1b0;
    uStack_1fc = 0x6fae360a;
    iVar5 = FwpiCalloutRegisterAndAddWithoutDevice0(uVar3,&local_280,&local_248,0);
    puVar6 = &DAT_140016820;
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
    if (-1 < iVar5) goto LAB_140020423;
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (puVar6,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                 "FwpiCalloutRegisterAndAddWithoutDevice0 (IPv6) fails with error",(char)iVar5);
    }
    DAT_140016748 = DAT_140016748 & 0xfffffff7;
  }
  else {
LAB_140020423:
    if ((DAT_140016748 & 0x10) == 0) {
      DAT_140016748 = DAT_140016748 | 0x10;
      KeReleaseSpinLock(&DAT_140016820);
      memset(&local_88,0,0x50);
      local_78 = 0;
      local_70 = 1;
      local_68 = 4;
      local_88 = 0x4f9a623e3971ef2b;
      uStack_80 = 0xa7b906b8796eb18c;
      local_50 = 0;
      local_60 = 0x4f9a623e3971ef2b;
      uStack_58 = 0xa7b906b8796eb18c;
      local_48 = 1;
      local_40 = 0x29;
      memset(local_1e8,0,200);
      local_1d8 = L"VPN Reconnect Filter";
      local_1a8 = 0x4b90fc23634a869f;
      uStack_1a0 = 0x6fae360a62bfc1b0;
      local_198 = CONCAT44(uRam0000000140012174,_SUBLAYER_KEY);
      uStack_190 = CONCAT44(uRam000000014001217c,uRam0000000140012178);
      local_1d0 = L"VPN Reconnect IPv6 Callout Filter";
      local_1c8 = 0;
      local_1c0 = &PROVIDER_KEY;
      local_180 = &DAT_140016840;
      local_170 = &local_88;
      local_150 = &DAT_140012240;
      local_188 = 4;
      local_178 = 1;
      local_168 = 0x4005;
      local_164 = 0xf839cdb6;
      uStack_160 = 0x45b8f734;
      uStack_15c = 0x737c4c8e;
      uStack_158 = 0x50fbfa5b;
      uVar7 = WfpState;
      iVar5 = FwpmFilterAdd0(WfpState,local_1e8,0,&local_290);
      if (iVar5 < 0) {
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (uVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "FwpmFilterAddfails (IPv6) with error",(char)iVar5);
        }
      }
      else {
        local_170 = &local_60;
        local_1c8 = 0;
        uVar7 = WfpState;
        iVar5 = FwpmFilterAdd0(WfpState,local_1e8,0,&uStack_288);
        if (-1 < iVar5) {
          DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
          bVar2 = true;
          _DAT_140016848 = local_290;
          uRam000000014001684c = uStack_28c;
          uRam0000000140016850 = uStack_288;
          uRam0000000140016854 = uStack_284;
          goto LAB_140020636;
        }
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (uVar7,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "FwpmFilterAddfails (IPv6) with error",(char)iVar5);
        }
        FwpmFilterDeleteById0(uVar3,CONCAT44(uStack_28c,local_290));
      }
      DAT_140016828 = KeAcquireSpinLockRaiseToDpc(&DAT_140016820);
      DAT_140016748 = DAT_140016748 & 0xffffffef;
    }
  }
LAB_140020636:
  if ((DAT_140016748 & 0x20) == 0) {
    DAT_140016748 = DAT_140016748 | 0x20;
    KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
    iVar5 = FwpsInjectionHandleCreate0(2,4,&local_2b0);
    puVar6 = &DAT_140016820;
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
    if (iVar5 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (puVar6,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                   "FwpsInjectionHandleCreate (IPv4) with error",(char)iVar5);
      }
      DAT_140016748 = DAT_140016748 & 0xffffffdf;
    }
    else {
      bVar1 = true;
      DAT_140016750 = local_2b0;
    }
  }
  if ((DAT_140016748 & 0x40) == 0) {
    DAT_140016748 = DAT_140016748 | 0x40;
    KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
    iVar5 = FwpsInjectionHandleCreate0(0x17,4,&local_2a8);
    puVar6 = &DAT_140016820;
    DAT_140016828 = KeAcquireSpinLockRaiseToDpc();
    if (iVar5 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0sx_EtwWriteTransfer
                  (puVar6,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                   "FwpsInjectionHandleCreate (IPv6) with error",(char)iVar5);
      }
      DAT_140016748 = DAT_140016748 & 0xffffffbf;
    }
    else {
      bVar1 = true;
      DAT_140016800 = local_2a8;
    }
  }
LAB_140020770:
  KeReleaseSpinLock(&DAT_140016820,DAT_140016828);
  puVar6 = &DAT_140016858;
  KeReleaseMutex(&DAT_140016858,0);
  if ((iVar5 < 0) && ((!bVar1 || (!bVar2)))) {
    AgileVpnCleanUpWfpCallouts(puVar6);
  }
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 8) != 0) {
    McTemplateK0sx_EtwWriteTransfer
              (puVar6,&RasAgileVpnTraceIntArgInfo,&DAT_14000feb8,"Exit with Status",(char)iVar5);
  }
  return iVar5;
}



===== UpdateIpv6OuterHeader @ 140020810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong UpdateIpv6OuterHeader(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  short local_78 [2];
  uint local_74;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  uStack_48 = *param_3;
  local_40 = param_3[1];
  local_70 = 0;
  uVar8 = 0;
  local_78[0] = 0;
  uVar6 = 0x60000000;
  uStack_58 = *param_2;
  local_50 = param_2[1];
  local_74 = 0;
  local_60 = 0x8029000000000000;
  puVar5 = param_1;
  local_68 = param_1;
  while( true ) {
    if (param_1 == (undefined8 *)0x0) {
      return uVar8;
    }
    uVar4 = GetPacketInfo(param_1[1],local_78,&local_74);
    uVar8 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) break;
    local_88 = (undefined8 *)0x0;
    uVar3 = NdisRetreatNetBufferListDataStart(param_1,0x28,0,0);
    uVar8 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) break;
    plVar7 = (longlong *)param_1[1];
    if (plVar7 != (longlong *)0x0) {
      uVar3 = (local_74 & 0x3f) << 0x16;
      do {
        uVar2 = (short)plVar7[3] - 0x28;
        uVar1 = 0x29;
        if (local_78[0] == 2) {
          uVar1 = 4;
        }
        uVar6 = uVar6 & 0xf03fffff | uVar3;
        local_60 = CONCAT44(CONCAT13(local_60._7_1_,CONCAT12(uVar1,uVar2 >> 8 | uVar2 * 0x100)),
                            uVar6 >> 0x18 | (uVar3 & 0xff0000) >> 8);
        puVar5 = (undefined8 *)NetioGetDataBufferIfSafe((longlong)plVar7,0x28);
        if (puVar5 == (undefined8 *)0x0) {
          local_88 = &local_70;
          RtlCopyBufferToMdl(&local_60,plVar7[1],(int)plVar7[2]);
        }
        else {
          *puVar5 = local_60;
          puVar5[1] = uStack_58;
          puVar5[2] = local_50;
          puVar5[3] = uStack_48;
          puVar5[4] = local_40;
        }
        plVar7 = (longlong *)*plVar7;
      } while (plVar7 != (longlong *)0x0);
      puVar5 = local_68;
    }
    param_1 = (undefined8 *)*param_1;
  }
  for (; puVar5 != param_1; puVar5 = (undefined8 *)*puVar5) {
    NdisAdvanceNetBufferListDataStart(puVar5,0x28,1,0);
  }
  return uVar8;
}



===== TransmitPacket @ 1400209f0 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400213f2) */
/* WARNING: Removing unreachable block (ram,0x0001400213f7) */
/* WARNING: Removing unreachable block (ram,0x00014002140c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TransmitPacket(longlong param_1,int *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  ulonglong uVar11;
  int *piVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  longlong lVar15;
  short *psVar16;
  uint *puVar17;
  uint uVar18;
  undefined *puVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  int *piVar22;
  undefined8 *puVar23;
  short sVar24;
  ulonglong uVar25;
  char *pcVar26;
  byte bVar27;
  longlong *plVar28;
  bool bVar29;
  undefined1 auStack_11a8 [32];
  undefined8 *local_1158;
  longlong local_1150;
  short local_1148;
  longlong local_1138 [2];
  undefined8 local_1128;
  int *local_1120;
  undefined8 *local_1118;
  undefined8 *local_1110;
  undefined8 *local_1108;
  int local_1100;
  uint uStack_10fc;
  int iStack_10f8;
  int iStack_10f4;
  undefined8 local_10f0;
  int local_10e8;
  undefined8 local_10e0;
  undefined8 uStack_10d8;
  undefined8 local_10d0;
  int local_10c8;
  undefined8 local_10c0;
  undefined8 uStack_10b8;
  uint local_10b0;
  undefined8 local_10a8;
  undefined8 uStack_10a0;
  undefined8 local_1098;
  longlong lStack_1090;
  undefined8 local_1088;
  undefined8 uStack_1080;
  undefined8 local_1078;
  undefined8 uStack_1070;
  undefined8 local_1068;
  undefined4 local_1060;
  undefined8 local_1058;
  undefined8 uStack_1050;
  byte local_1048 [2048];
  undefined8 local_848 [256];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x140020a12;
  local_48 = __security_cookie ^ (ulonglong)auStack_11a8;
  puVar2 = *(undefined8 **)(param_1 + 0x18);
  local_1158 = (undefined8 *)0x0;
  local_1098 = 0;
  lStack_1090 = 0;
  puVar14 = (undefined8 *)0x0;
  local_10a8 = 0;
  uStack_10a0 = 0;
  uVar25 = 0xc0000001;
  local_1120 = param_2;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xe);
  *(undefined1 *)(param_2 + 0x10) = uVar5;
  piVar22 = param_2 + 0xe;
  if ((param_2[0x35] & 0x20U) == 0) {
    if (((uint)param_2[0x35] >> 10 & 1) == 0) {
      local_10e0 = *(undefined8 *)(param_2 + 0x18);
      uStack_10d8 = *(undefined8 *)(param_2 + 0x1a);
      local_10c8 = param_2[0x1e];
      local_10d0 = *(undefined8 *)(param_2 + 0x1c);
      local_1100 = param_2[0x1f];
      uStack_10fc = param_2[0x20];
      iStack_10f8 = param_2[0x21];
      iStack_10f4 = param_2[0x22];
      local_10e8 = param_2[0x25];
      local_10f0 = *(undefined8 *)(param_2 + 0x23);
      KeReleaseSpinLock();
      pbVar10 = local_1048;
      uVar25 = 0xc023000f;
      lVar15 = puVar2[1];
      memset(pbVar10,0,0x800);
      uVar4 = uStack_10fc;
      uVar9 = *(uint *)(lVar15 + 0x18);
      if (((uVar9 < 0x14) ||
          (pbVar10 = (byte *)NdisGetDataBuffer(lVar15,0x14,local_1048,4), pbVar10 == (byte *)0x0))
         || ((*pbVar10 & 0xf0) != 0x40)) {
        if (((0x27 < uVar9) &&
            (pbVar10 = (byte *)NdisGetDataBuffer(lVar15,0x28,local_1048,4), pbVar10 != (byte *)0x0))
           && (((byte)*(undefined4 *)pbVar10 & 0xf0) == 0x60)) {
          sVar24 = 0x17;
          uVar9 = 0;
          local_10a8 = *(undefined8 *)(pbVar10 + 0x18);
          uStack_10a0 = *(undefined8 *)(pbVar10 + 0x20);
          local_1058 = CONCAT44(iStack_10f4,iStack_10f8);
          uStack_1050 = local_10f0;
          do {
            uVar18 = *(uint *)(local_1048 + (ulonglong)(uVar9 * 2) * 2 + -0x10);
            uVar1 = *(uint *)(local_1048 + (ulonglong)(uVar9 * 2) * 2 + -0x60);
            if ((uVar18 >> 0x18 | (uVar18 & 0xff0000) >> 8 | (uVar18 & 0xff00) << 8 | uVar18 << 0x18
                ) != (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                     uVar1 << 0x18)) goto LAB_140020b56;
            uVar9 = uVar9 + 1;
          } while (uVar9 < 4);
          goto LAB_140021085;
        }
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (pbVar10,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "TransmitPacket:GetPacketIPInfo failed with",0xf);
        }
      }
      else {
        uVar9 = *(uint *)(pbVar10 + 0x10);
        sVar24 = 2;
        local_10a8 = CONCAT44(local_10a8._4_4_,uVar9);
        uVar18 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        pbVar10 = (byte *)(ulonglong)uVar18;
        if (uVar18 == (uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 |
                      uVar9 << 0x18)) {
LAB_140021085:
          if (param_2[0x52] == 1) {
            if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
              McTemplateK0s_EtwWriteTransfer
                        (pbVar10,&RasAgileVpnTraceError,&DAT_14000feb8,
                         "Dropping IKEv2 invalid packet when outerdestination and innerdetination are same for tunnel in default compartment."
                        );
            }
            uVar25 = 0xc023000f;
            goto LAB_140021016;
          }
        }
LAB_140020b56:
        piVar22 = param_2 + 0x40;
        uVar5 = KeAcquireSpinLockRaiseToDpc(piVar22);
        *(undefined1 *)(param_2 + 0x42) = uVar5;
        if (sVar24 == 2) {
          local_1150 = *(longlong *)(param_2 + 0x3c);
        }
        else {
          local_1150 = *(longlong *)(param_2 + 0x3e);
        }
        local_1138[0] = local_1150;
        KeReleaseSpinLock(piVar22);
        if (local_1150 == 0) {
          local_1068 = 0;
          local_1060 = 0;
          local_1088 = 0;
          uStack_1080 = 0;
          local_1078 = 0;
          uStack_1070 = 0;
          uVar11 = GetPacketInfoFromNetBuffer(puVar2[1],(short *)&local_1088);
          uVar25 = uVar11 & 0xffffffff;
          if (-1 < (int)uVar11) {
            uVar5 = KeAcquireSpinLockRaiseToDpc(piVar22);
            *(undefined1 *)(param_2 + 0x42) = uVar5;
            for (piVar12 = *(int **)(param_2 + 0x44); piVar12 != param_2 + 0x44;
                piVar12 = *(int **)piVar12) {
              for (psVar16 = *(short **)(piVar12 + 8); psVar16 != (short *)0x0;
                  psVar16 = *(short **)(psVar16 + 0x18)) {
                uVar13 = MatchFilter(psVar16,(short *)&local_1088,'\x01');
                if ((char)uVar13 != '\0') {
                  psVar16 = *(short **)(piVar12 + 10);
                  goto LAB_1400211f2;
                }
              }
LAB_14002121a:
            }
            cVar6 = FindMatchingTs((undefined8 *)(param_2 + 0x48),local_1138,(short *)&local_1088,
                                   '\x01');
            KeReleaseSpinLock(piVar22);
            if (cVar6 != '\0') {
              local_1150 = local_1138[0];
              goto LAB_140020ce7;
            }
            RasAgileVpnTraceNBL(puVar2,2);
            uVar25 = 0xc023000f;
          }
        }
        else {
LAB_140020ce7:
          uVar13 = DAT_140016808;
          iVar8 = FwpsAllocateNetBufferAndNetBufferList0(DAT_140016808,0,0,0);
          uVar25 = (ulonglong)iVar8;
          if (-1 < iVar8) {
            puVar19 = &DAT_140016780;
            puVar14 = (undefined8 *)ExAllocateFromNPagedLookasideList();
            local_1118 = puVar14;
            if (puVar14 == (undefined8 *)0x0) {
              if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
                McTemplateK0s_EtwWriteTransfer
                          (puVar19,&RasAgileVpnTraceError,&DAT_14000feb8,
                           "ALLOCATE_SEND_CONTEXT failed");
              }
              goto LAB_140020f2a;
            }
            puVar14[1] = param_1;
            *puVar14 = param_2;
            puVar14[2] = uRam0000000000000008;
            uRam0000000000000008 = *(undefined8 *)(param_1 + 8);
            if ((char)param_2[0x2c] != '\0') {
              WfpNblInfoClone(param_1,0,1,0);
            }
            puVar21 = DAT_140016800;
            puVar20 = local_1158;
            if ((short)param_2[0x1f] == 2) {
              uVar25 = 0;
              local_10b0 = uVar4;
              local_10c0 = 0x45;
              uStack_10b8 = CONCAT44(local_10e0._4_4_,0x4ff);
              local_1108 = DAT_140016750;
              local_1110 = (undefined8 *)0x0;
              local_1128 = 0;
              for (puVar21 = local_1158; puVar21 != (undefined8 *)0x0;
                  puVar21 = (undefined8 *)*puVar21) {
                puVar23 = (undefined8 *)puVar21[1];
                puVar20 = local_848;
                uVar25 = 0xc023000f;
                memset(puVar20,0,0x800);
                uVar9 = *(uint *)(puVar23 + 3);
                if (((uVar9 < 0x14) ||
                    (puVar20 = puVar23, pbVar10 = (byte *)NdisGetDataBuffer(puVar23,0x14,local_848),
                    pbVar10 == (byte *)0x0)) ||
                   (puVar20 = (undefined8 *)(ulonglong)(*pbVar10 & 0xf0), (*pbVar10 & 0xf0) != 0x40)
                   ) {
                  puVar3 = local_1110;
                  if (((uVar9 < 0x28) ||
                      (puVar17 = (uint *)NdisGetDataBuffer(puVar23,0x28,local_848),
                      puVar20 = puVar23, puVar3 = local_1110, puVar17 == (uint *)0x0)) ||
                     (((byte)*puVar17 & 0xf0) != 0x60)) goto joined_r0x000140020e8d;
                  bVar27 = (byte)(*puVar17 >> 0x16) & 0x3f;
                  local_1148 = 0x17;
                }
                else {
                  local_1148 = 2;
                  bVar27 = pbVar10[1] >> 2;
                }
                puVar20 = puVar21;
                uVar9 = NdisRetreatNetBufferListDataStart(puVar21,0x14,0);
                uVar25 = (ulonglong)uVar9;
                puVar3 = local_1110;
                if ((int)uVar9 < 0) goto joined_r0x000140020e8d;
                plVar28 = (longlong *)puVar21[1];
                if (plVar28 != (longlong *)0x0) {
                  do {
                    uVar5 = 0x29;
                    if (local_1148 == 2) {
                      uVar5 = 4;
                    }
                    uStack_10b8._0_2_ = CONCAT11(uVar5,(undefined1)uStack_10b8);
                    bVar7 = local_10c0._1_1_ & 3;
                    local_10c0 = CONCAT62(CONCAT42(local_10c0._4_4_,
                                                   *(ushort *)(plVar28 + 3) >> 8 |
                                                   *(ushort *)(plVar28 + 3) << 8),
                                          CONCAT11(bVar7 | bVar27 << 2,(undefined1)local_10c0));
                    lVar15 = plVar28[1];
                    uVar9 = *(uint *)(plVar28 + 2);
                    if (*(int *)(lVar15 + 0x28) - uVar9 < 0x14) {
LAB_1400210b1:
                      puVar20 = &local_10c0;
                      RtlCopyBufferToMdl(puVar20,plVar28[1],uVar9);
                    }
                    else {
                      if ((*(byte *)(lVar15 + 10) & 5) == 0) {
                        lVar15 = MmMapLockedPagesSpecifyCache(lVar15,0,1);
                      }
                      else {
                        lVar15 = *(longlong *)(lVar15 + 0x18);
                      }
                      uVar9 = *(uint *)(plVar28 + 2);
                      puVar20 = (undefined8 *)(lVar15 + (ulonglong)uVar9);
                      if ((((ulonglong)puVar20 & 1) != 0) || (puVar20 == (undefined8 *)0x0))
                      goto LAB_1400210b1;
                      *(undefined4 *)puVar20 = (undefined4)local_10c0;
                      *(undefined4 *)((longlong)puVar20 + 4) = local_10c0._4_4_;
                      *(undefined4 *)(puVar20 + 1) = (undefined4)uStack_10b8;
                      *(undefined4 *)((longlong)puVar20 + 0xc) = uStack_10b8._4_4_;
                      *(uint *)(puVar20 + 2) = local_10b0;
                    }
                    plVar28 = (longlong *)*plVar28;
                  } while (plVar28 != (longlong *)0x0);
                  param_2 = local_1120;
                  puVar14 = local_1118;
                }
              }
              goto LAB_140020e93;
            }
            uVar25 = UpdateIpv6OuterHeader
                               ((undefined8 *)0x0,&uStack_10d8,(undefined8 *)&iStack_10f8);
            uVar25 = uVar25 & 0xffffffff;
            goto LAB_140020ea2;
          }
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0sx_EtwWriteTransfer
                      (uVar13,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                       "FwpsAllocateNetBufferAndNetBufferList failed with the status",(char)iVar8);
          }
        }
      }
    }
    else {
      KeReleaseSpinLock();
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (piVar22,&RasAgileVpnTraceError,&DAT_14000feb8,
                   "TransmitPacket: mobike in progress dropping packet");
      }
      *(undefined4 *)((longlong)puVar2 + 0x8c) = 0;
    }
  }
  else {
    KeReleaseSpinLock();
    uVar25 = 0xc000009a;
  }
  goto LAB_140021016;
LAB_1400211f2:
  if (psVar16 == (short *)0x0) goto LAB_14002121a;
  uVar13 = MatchFilter(psVar16,(short *)&local_1088,'\0');
  if ((char)uVar13 != '\0') {
    local_1150 = *(longlong *)(piVar12 + -2);
    local_1138[0] = local_1150;
    KeReleaseSpinLock(piVar22);
    goto LAB_140020ce7;
  }
  psVar16 = *(short **)(psVar16 + 0x18);
  goto LAB_1400211f2;
joined_r0x000140020e8d:
  for (; puVar3 != puVar21; puVar3 = (undefined8 *)*puVar3) {
    puVar20 = puVar3;
    NdisAdvanceNetBufferListDataStart(puVar3,0x14,1);
  }
LAB_140020e93:
  puVar21 = local_1108;
LAB_140020ea2:
  if ((int)uVar25 < 0) {
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0sx_EtwWriteTransfer
                (puVar20,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                 "Update Outer Header failed with the status",(char)uVar25);
    }
  }
  else {
    lStack_1090 = local_1150;
    local_1098 = *(undefined8 *)(param_2 + 0x2a);
    iVar8 = FwpsVirtualIfTunnelInfoSet0(0,&local_1098);
    uVar25 = (ulonglong)iVar8;
    if (iVar8 < 0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar26 = "FwpsVirtualIfTunnelInfoSet0 failed with the status";
LAB_1400213bf:
        McTemplateK0sx_EtwWriteTransfer
                  (local_1158,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,pcVar26,(char)uVar25);
      }
    }
    else {
      LOCK();
      _agileVpnUlPackSent = _agileVpnUlPackSent + 1;
      UNLOCK();
      iVar8 = FwpsInjectNetworkSendAsync0(puVar21,0,0,1);
      uVar25 = (ulonglong)iVar8;
      if (-1 < iVar8) goto LAB_140020f2a;
      LOCK();
      _agileVpnUlPackSentComplete = _agileVpnUlPackSentComplete + 1;
      UNLOCK();
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar26 = "FwpsInjectNetworkSendAsync failed with the status";
        local_1158 = puVar21;
        goto LAB_1400213bf;
      }
    }
  }
LAB_140021016:
  if (puVar14 != (undefined8 *)0x0) {
    ExFreeToNPagedLookasideList(&DAT_140016780,puVar14);
  }
  NdisFreeCloneNetBufferList(param_1,0);
  NdisMCoSendNetBufferListsComplete(*(undefined8 *)(param_2 + 0x12),puVar2,0);
  LOCK();
  param_2[0x59] = param_2[0x59] + 1;
  UNLOCK();
  DereferenceRefCount(param_2);
  LOCK();
  iVar8 = DAT_140012248 + -1;
  UNLOCK();
  bVar29 = DAT_140012248 == 1;
  DAT_140012248 = iVar8;
  if (bVar29) {
    (*DAT_140012250)(&DAT_140012248);
  }
  LOCK();
  _agileVpnUlPackSentError = _agileVpnUlPackSentError + 1;
  UNLOCK();
LAB_140020f2a:
  return uVar25 & 0xffffffff;
}



===== CallOutClassify @ 140021450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CallOutClassify(undefined8 param_1,undefined *param_2,undefined8 *param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  byte *pbVar7;
  ulonglong uVar8;
  int *piVar9;
  short *psVar10;
  undefined8 uVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  undefined4 *puVar14;
  undefined1 *_Dst;
  longlong lVar15;
  undefined1 *puVar16;
  longlong *plVar17;
  int *piVar18;
  int *piVar19;
  undefined4 *in_stack_00000038;
  undefined1 auStackY_908 [32];
  longlong *local_8d0;
  undefined8 *local_8b0;
  longlong *local_8a8;
  longlong *local_8a0;
  undefined8 *local_898;
  longlong local_890;
  undefined8 uStack_888;
  undefined8 local_880;
  undefined8 uStack_878;
  undefined8 local_870;
  undefined8 uStack_868;
  undefined8 local_860;
  undefined4 local_858;
  undefined1 local_848 [2048];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_908;
  plVar17 = (longlong *)0x0;
  local_8d0 = (longlong *)0x0;
  local_8a0 = (longlong *)0x0;
  piVar18 = (int *)0x0;
  local_8a8 = (longlong *)0x0;
  local_8b0 = (undefined8 *)0x0;
  bVar4 = false;
  local_890 = 0;
  uStack_888 = 0;
  local_898 = param_3;
  iVar6 = FwpsVirtualIfTunnelInfoGet0(param_2,&local_890);
  lVar15 = local_890;
  if ((iVar6 < 0) || (local_890 == 0)) {
LAB_140021862:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (param_2,&RasAgileVpnTraceError,&DAT_14000feb8,"Got an invalid Packet");
    }
    if (piVar18 == (int *)0x0) goto LAB_140021881;
  }
  else {
    DAT_1400144c8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144c0);
    for (puVar13 = (undefined8 *)(&DAT_1400124c0)[(ulonglong)((uint)lVar15 & 0x1ff) * 2];
        puVar13 != &DAT_1400124c0 + (ulonglong)((uint)lVar15 & 0x1ff) * 2;
        puVar13 = (undefined8 *)*puVar13) {
      if (puVar13[0x12] == lVar15) {
        piVar18 = (int *)(puVar13 + -3);
        LOCK();
        *(int *)(puVar13 + -3) = *(int *)(puVar13 + -3) + 1;
        UNLOCK();
        break;
      }
    }
    param_2 = &DAT_1400144c0;
    KeReleaseSpinLock(&DAT_1400144c0,DAT_1400144c8);
    if (piVar18 == (int *)0x0) goto LAB_140021862;
    bVar4 = true;
    DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
    puVar14 = (undefined4 *)&DAT_1400144f0;
    if ((DAT_140014514 & 1) == 0) {
      LOCK();
      DAT_140012248 = DAT_140012248 + 1;
      UNLOCK();
      KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
      uVar5 = KeAcquireSpinLockRaiseToDpc(piVar18 + 0xe);
      *(undefined1 *)(piVar18 + 0x10) = uVar5;
      if ((piVar18[0x35] & 0x20U) != 0) {
        KeReleaseSpinLock(piVar18 + 0xe);
        puVar14 = &DAT_140012248;
        DereferenceRefCount(&DAT_140012248);
        iVar6 = -0x3fffff66;
        goto LAB_1400219da;
      }
      KeReleaseSpinLock();
      uVar8 = 0;
      plVar17 = (longlong *)0x0;
      for (puVar13 = local_898; iVar6 = (int)uVar8, puVar13 != (undefined8 *)0x0;
          puVar13 = (undefined8 *)*puVar13) {
        puVar16 = (undefined1 *)puVar13[1];
        _Dst = local_848;
        iVar6 = -0x3fdcfff1;
        memset(_Dst,0,0x800);
        uVar3 = *(uint *)(puVar16 + 0x18);
        if (uVar3 < 0x14) {
LAB_140021805:
          if (0x27 < uVar3) {
            puVar14 = (undefined4 *)NdisGetDataBuffer(puVar16,0x28);
            _Dst = puVar16;
            if ((puVar14 != (undefined4 *)0x0) && (((byte)*puVar14 & 0xf0) == 0x60)) {
              uVar5 = KeAcquireSpinLockRaiseToDpc(piVar18 + 0x40);
              lVar15 = *(longlong *)(piVar18 + 0x3e);
              goto LAB_140021688;
            }
          }
          if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
            McTemplateK0s_EtwWriteTransfer
                      (_Dst,&RasAgileVpnTraceError,&DAT_14000feb8,"Invalid Inner packet received");
          }
          goto LAB_1400217ea;
        }
        _Dst = puVar16;
        pbVar7 = (byte *)NdisGetDataBuffer(puVar16,0x14);
        if ((pbVar7 == (byte *)0x0) || ((*pbVar7 & 0xf0) != 0x40)) goto LAB_140021805;
        uVar5 = KeAcquireSpinLockRaiseToDpc(piVar18 + 0x40);
        lVar15 = *(longlong *)(piVar18 + 0x3c);
LAB_140021688:
        piVar19 = piVar18 + 0x40;
        uVar8 = 0;
        *(undefined1 *)(piVar18 + 0x42) = uVar5;
        if (lVar15 == 0) {
          KeReleaseSpinLock();
          local_880 = 0;
          uStack_878 = 0;
          local_860 = 0;
          local_870 = 0;
          uStack_868 = 0;
          local_858 = 0;
          uVar8 = GetPacketInfoFromNetBuffer(puVar13[1],(short *)&local_880);
          iVar6 = (int)uVar8;
          uVar8 = uVar8 & 0xffffffff;
          if (-1 < iVar6) {
            uVar5 = KeAcquireSpinLockRaiseToDpc(piVar19);
            *(undefined1 *)(piVar18 + 0x42) = uVar5;
            for (piVar9 = *(int **)(piVar18 + 0x44); piVar9 != piVar18 + 0x44;
                piVar9 = *(int **)piVar9) {
              for (psVar10 = *(short **)(piVar9 + 8); psVar10 != (short *)0x0;
                  psVar10 = *(short **)(psVar10 + 0x18)) {
                uVar11 = MatchFilter(psVar10,(short *)&local_880,'\0');
                if ((char)uVar11 != '\0') {
                  psVar10 = *(short **)(piVar9 + 10);
                  goto LAB_140021a51;
                }
              }
LAB_140021a7a:
            }
            KeReleaseSpinLock(piVar19,uVar5);
            RasAgileVpnTraceNBL(puVar13,2);
            iVar6 = -0x3fdcfff1;
          }
          goto LAB_1400217ea;
        }
        KeReleaseSpinLock(piVar19,uVar5);
LAB_1400218fc:
        plVar12 = (longlong *)NetioAllocateAndReferenceCloneNetBufferList(puVar13,0);
        if (plVar12 == (longlong *)0x0) {
          iVar6 = -0x3fffff66;
          goto LAB_1400217ea;
        }
        plVar12[0x1a] = (ulonglong)*(uint *)(puVar13 + 0x1a);
        if (plVar17 == (longlong *)0x0) {
          local_8d0 = plVar12;
        }
        else {
          *plVar17 = (longlong)plVar12;
        }
        plVar12[0xf] = *(longlong *)(piVar18 + 0x12);
        *plVar12 = 0;
        plVar17 = plVar12;
        local_8a0 = plVar12;
      }
      piVar19 = *(int **)(piVar18 + 0x4e);
      if (piVar19 == (int *)0x0) {
LAB_140021768:
        local_8a8 = local_8d0;
LAB_140021772:
        plVar17 = local_8a8;
        if (local_8a8 != (longlong *)0x0) {
          do {
            plVar12 = (longlong *)*plVar17;
            *plVar17 = 0;
            piVar19 = *(int **)(piVar18 + 0x4e);
            if (piVar19 != (int *)0x0) {
              LOCK();
              iVar6 = *piVar19;
              if (iVar6 == 1) {
                *piVar19 = 1;
              }
              UNLOCK();
              if ((iVar6 == 1) && (*(longlong *)(*(longlong *)(piVar18 + 0x4e) + 0x10) != 0)) {
                NdisFreeNetBufferListContext(plVar17,0x10);
                DereferenceRefCount(piVar18);
                DereferenceRefCount(&DAT_140012248);
              }
            }
            LOCK();
            *piVar18 = *piVar18 + 1;
            UNLOCK();
            LOCK();
            DAT_140012248 = DAT_140012248 + 1;
            UNLOCK();
            iVar6 = FwpsSignalIPsecDecryptCompleteIkeV20
                              (plVar17,IPsecDecryptCompleteCallback,piVar18);
            if (iVar6 < 0) {
              *(undefined1 *)(piVar18 + 0x50) = 1;
              iVar6 = 0;
              ProcessRxPacket(piVar18,plVar17);
            }
            LOCK();
            _agileVpnUlPackReceivedPending = _agileVpnUlPackReceivedPending + 1;
            UNLOCK();
            plVar17 = plVar12;
          } while (plVar12 != (longlong *)0x0);
        }
      }
      else {
        LOCK();
        iVar1 = *piVar19;
        if (iVar1 == 1) {
          *piVar19 = 1;
        }
        UNLOCK();
        if ((iVar1 != 1) || (*(longlong *)(*(longlong *)(piVar18 + 0x4e) + 0x10) == 0))
        goto LAB_140021768;
        uVar11 = 0;
        plVar17 = local_8d0;
        iVar6 = NdisAllocateNetBufferListContext(local_8d0,0x10,0,0x63715641);
        if (iVar6 == 0) {
          LOCK();
          *piVar18 = *piVar18 + 1;
          UNLOCK();
          LOCK();
          DAT_140012248 = DAT_140012248 + 1;
          UNLOCK();
          lVar15 = local_8d0[2];
          uVar2 = *(ushort *)(lVar15 + 10);
          *(int **)((ulonglong)uVar2 + 0x10 + lVar15) = piVar18;
          *(undefined1 *)((ulonglong)uVar2 + 0x18 + lVar15) = 0;
          BwcSendNbls(*(uint **)(*(longlong *)(piVar18 + 0x4e) + 0x10),local_8d0,uVar11,
                      (longlong *)&local_8a8,&local_8b0);
          if ((local_8b0 != (undefined8 *)0x0) &&
             (piVar19 = *(int **)(piVar18 + 0x4e), piVar19 != (int *)0x0)) {
            LOCK();
            iVar1 = *piVar19;
            if (iVar1 == 1) {
              *piVar19 = 1;
            }
            UNLOCK();
            if ((iVar1 == 1) && (*(longlong *)(*(longlong *)(piVar18 + 0x4e) + 0x10) != 0)) {
              DropNonConformantNbls(*(longlong *)(*(longlong *)(piVar18 + 0x4e) + 0x10),local_8b0);
              RasAgileVpnTraceNBL(local_8b0,1);
            }
          }
          goto LAB_140021772;
        }
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
          McTemplateK0sx_EtwWriteTransfer
                    (plVar17,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
                     "CallOutClassify: NdisAllocateNetBufferListContext for QoS context failed",
                     (char)iVar6);
        }
      }
LAB_1400217ea:
      LOCK();
      UNLOCK();
      plVar17 = local_8d0;
      bVar4 = true;
      if (DAT_140012248 == 1) {
        DAT_140012248 = DAT_140012248 + -1;
        (*DAT_140012250)(&DAT_140012248);
      }
      else {
        DAT_140012248 = DAT_140012248 + -1;
      }
    }
    else {
      KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
      iVar6 = -0x3fdcffd6;
LAB_1400219da:
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (puVar14,&RasAgileVpnTraceError,&DAT_14000feb8,
                   "CallOutClassify: Packets will be droped as AgileVpnCheckAdapterTunnelStates failed"
                  );
      }
    }
  }
  LOCK();
  iVar1 = *piVar18;
  *piVar18 = *piVar18 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(piVar18 + 2))(piVar18);
  }
LAB_140021881:
  *(undefined8 *)(in_stack_00000038 + 2) = 0;
  if (bVar4) {
    in_stack_00000038[7] = in_stack_00000038[7] | 1;
    *in_stack_00000038 = 0x1001;
    in_stack_00000038[6] = in_stack_00000038[6] & 0xfffffffe;
    puVar13 = local_898;
    if (-1 < iVar6) {
      return;
    }
    for (; puVar13 != (undefined8 *)0x0; puVar13 = (undefined8 *)*puVar13) {
      *(int *)((longlong)puVar13 + 0x8c) = iVar6;
    }
  }
  else {
    *in_stack_00000038 = 0x1002;
    in_stack_00000038[6] = in_stack_00000038[6] & 1;
    if (-1 < iVar6) {
      return;
    }
  }
  while (plVar17 != (longlong *)0x0) {
    plVar12 = (longlong *)*plVar17;
    *plVar17 = 0;
    NetioDereferenceNetBufferList(plVar17,0);
    LOCK();
    piVar18[0x58] = piVar18[0x58] + 1;
    UNLOCK();
    plVar17 = plVar12;
  }
  LOCK();
  _agileVpnUlPackReceivedError = _agileVpnUlPackReceivedError + 1;
  UNLOCK();
  return;
LAB_140021a51:
  if (psVar10 == (short *)0x0) goto LAB_140021a7a;
  uVar11 = MatchFilter(psVar10,(short *)&local_880,'\x01');
  if ((char)uVar11 != '\0') {
    KeReleaseSpinLock(piVar19,uVar5);
    plVar17 = local_8a0;
    goto LAB_1400218fc;
  }
  psVar10 = *(short **)(psVar10 + 0x18);
  goto LAB_140021a51;
}



===== GetPacketInfoFromNetBuffer @ 140021cb0 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetPacketInfoFromNetBuffer(ulonglong param_1,short *param_2)

{
  byte *pbVar1;
  short *psVar2;
  short *psVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte bVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  ushort *puVar11;
  longlong lVar12;
  uint uVar13;
  ulonglong uVar14;
  int iVar15;
  uint uVar16;
  char *pcVar17;
  undefined8 uVar18;
  undefined1 auStack_1088 [32];
  undefined1 local_1048 [2048];
  undefined1 local_848 [2048];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x140021cca;
  local_48 = __security_cookie ^ (ulonglong)auStack_1088;
  memset(local_1048,0,0x800);
  uVar4 = *(uint *)(param_1 + 0x18);
  pbVar1 = (byte *)(param_2 + 0x14);
  psVar2 = param_2 + 10;
  psVar3 = param_2 + 2;
  memset(local_848,0,0x800);
  if (((uVar4 < 0x14) ||
      (pbVar9 = (byte *)NdisGetDataBuffer(param_1,0x14,local_848,4), pbVar9 == (byte *)0x0)) ||
     ((*pbVar9 & 0xf0) != 0x40)) {
    if (uVar4 < 0x28) {
LAB_140021ed1:
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) {
        return 0xc023000f;
      }
      McTemplateK0sx_EtwWriteTransfer
                (0xffffffffc023000f,&RasAgileVpnTraceIntArgError,&DAT_14000d190,
                 "Got an invalid Packet: GetPacketIPInfo retuned Status",0xf);
      return 0xc023000f;
    }
    uVar16 = 0x28;
    puVar10 = (undefined4 *)NdisGetDataBuffer(param_1,0x28,local_848,4);
    if ((puVar10 == (undefined4 *)0x0) || (((byte)*puVar10 & 0xf0) != 0x60)) goto LAB_140021ed1;
    if (param_2 != (short *)0x0) {
      *param_2 = 0x17;
    }
    if (psVar3 != (short *)0x0) {
      uVar5 = puVar10[3];
      uVar6 = puVar10[4];
      uVar7 = puVar10[5];
      *(undefined4 *)psVar3 = puVar10[2];
      *(undefined4 *)(param_2 + 4) = uVar5;
      *(undefined4 *)(param_2 + 6) = uVar6;
      *(undefined4 *)(param_2 + 8) = uVar7;
    }
    if (psVar2 != (short *)0x0) {
      uVar5 = puVar10[7];
      uVar6 = puVar10[8];
      uVar7 = puVar10[9];
      *(undefined4 *)psVar2 = puVar10[6];
      *(undefined4 *)(param_2 + 0xc) = uVar5;
      *(undefined4 *)(param_2 + 0xe) = uVar6;
      *(undefined4 *)(param_2 + 0x10) = uVar7;
    }
    if (pbVar1 != (byte *)0x0) {
      *pbVar1 = *(byte *)((longlong)puVar10 + 6);
    }
LAB_140021dab:
    uVar13 = *(int *)(param_1 + 0x10) + uVar16;
    if (uVar13 < *(uint *)(*(longlong *)(param_1 + 8) + 0x28)) {
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + uVar16;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar16;
      *(uint *)(param_1 + 0x10) = uVar13;
    }
    else {
      NdisAdvanceNetBufferDataStart(param_1,uVar16,0,0);
    }
  }
  else {
    if (param_2 != (short *)0x0) {
      *param_2 = 2;
    }
    if (psVar3 != (short *)0x0) {
      *(undefined4 *)psVar3 = *(undefined4 *)(pbVar9 + 0xc);
    }
    if (psVar2 != (short *)0x0) {
      *(undefined4 *)psVar2 = *(undefined4 *)(pbVar9 + 0x10);
    }
    if (pbVar1 != (byte *)0x0) {
      *pbVar1 = pbVar9[9];
    }
    uVar16 = (uint)(byte)((*pbVar9 & 0xf) << 2);
    if ((*pbVar9 & 0xf) != 0) goto LAB_140021dab;
  }
  uVar18 = 0;
  if (*param_2 != 2) {
    bVar8 = *pbVar1;
    while ((uVar14 = 0x1000080000000001, bVar8 < 0x3d &&
           ((0x1000080000000001U >> ((ulonglong)bVar8 & 0x3f) & 1) != 0))) {
      if (uVar4 < uVar16 + 2) {
        uVar18 = 0xc023000f;
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_140021e51;
        pcVar17 = "Got an invalid length Packet: ";
        goto LAB_140021f5c;
      }
      uVar14 = param_1;
      pbVar9 = (byte *)NdisGetDataBuffer(param_1,2,local_1048);
      if (pbVar9 == (byte *)0x0) {
LAB_140022078:
        uVar18 = 0xc023000f;
        if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_140021e51;
        pcVar17 = "Got an invalid Packet Extensions: ";
        goto LAB_140021f5c;
      }
      uVar14 = (ulonglong)pbVar9[1];
      iVar15 = (uint)pbVar9[1] * 8 + 8;
      uVar13 = iVar15 + uVar16;
      if (uVar4 < uVar13) goto LAB_140022078;
      NetioAdvanceNetBuffer(param_1,iVar15);
      bVar8 = *pbVar9;
      *pbVar1 = bVar8;
      uVar16 = uVar13;
    }
  }
  bVar8 = *pbVar1;
  if (bVar8 == 6) {
    if (uVar4 < uVar16 + 0x14) {
      uVar18 = 0xc023000f;
      goto LAB_140021e51;
    }
    puVar11 = (ushort *)NdisGetDataBuffer(param_1,0x14,local_1048);
    uVar14 = 0;
    if (puVar11 != (ushort *)0x0) {
LAB_140021e3a:
      param_2[0x12] = *puVar11 >> 8 | *puVar11 << 8;
      param_2[0x13] = puVar11[1] >> 8 | puVar11[1] << 8;
      goto LAB_140021e51;
    }
  }
  else {
    if (bVar8 != 1) {
      if (bVar8 == 0x11) {
        if (uVar4 < uVar16 + 8) {
          uVar18 = 0xc023000f;
          goto LAB_140021e51;
        }
        puVar11 = (ushort *)NdisGetDataBuffer(param_1,8,local_1048);
        if (puVar11 != (ushort *)0x0) goto LAB_140021e3a;
        uVar14 = 0;
        goto joined_r0x000140021f4f;
      }
      if (bVar8 != 0x3a) goto LAB_140021e51;
    }
    if (uVar4 < uVar16 + 4) {
      uVar18 = 0xc023000f;
      goto LAB_140021e51;
    }
    uVar14 = param_1;
    lVar12 = NdisGetDataBuffer(param_1,4,local_1048);
    if (lVar12 != 0) goto LAB_140021e51;
  }
joined_r0x000140021f4f:
  uVar18 = 0xc023000f;
  if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
    pcVar17 = "Got an invalid TCP Packet : ";
LAB_140021f5c:
    uVar18 = 0xc023000f;
    McTemplateK0s_EtwWriteTransfer(uVar14,&RasAgileVpnTraceError,&DAT_14000d190,pcVar17);
  }
LAB_140021e51:
  if (uVar16 != 0) {
    if (*(uint *)(param_1 + 0x10) < uVar16) {
      NdisRetreatNetBufferDataStart(param_1,uVar16,0,NetioAllocateMdl_exref);
      return uVar18;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - uVar16;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar16;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) - uVar16;
  }
  return uVar18;
}



===== MatchFilter @ 140022130 =====

undefined8 MatchFilter(short *param_1,short *param_2,char param_3)

{
  uint *puVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  
  sVar2 = *param_1;
  if (*param_2 == sVar2) {
    if (param_3 == '\0') {
      uVar7 = param_2[0x13];
    }
    else {
      uVar7 = param_2[0x12];
    }
    lVar5 = 4;
    if (param_3 == '\0') {
      lVar5 = 0x14;
    }
    puVar1 = (uint *)(lVar5 + (longlong)param_2);
    if (((*(char *)((longlong)param_1 + 0x25) != '\0') ||
        (((ushort)param_1[0x13] <= uVar7 && (uVar7 <= (ushort)param_1[0x14])))) &&
       (((char)param_1[0x15] == '\0' || ((char)param_1[0x15] == (char)param_2[0x14])))) {
      if ((char)param_1[0x12] == '\0') {
        uVar6 = 0;
        if (sVar2 == 2) {
          uVar8 = *puVar1;
          uVar3 = *(uint *)(param_1 + 2);
          param_2 = (short *)(ulonglong)
                             (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                             uVar3 << 0x18);
          lVar5 = (ulonglong)
                  (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18)
                  - (longlong)param_2;
LAB_14002219f:
          if (lVar5 < 0) {
LAB_140022264:
            return (ulonglong)param_2 & 0xffffffffffffff00;
          }
          if (sVar2 == 2) {
            uVar6 = *(uint *)(param_1 + 10);
            uVar8 = *puVar1;
            lVar5 = (ulonglong)
                    (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18
                    ) - (ulonglong)
                        (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                        uVar6 << 0x18);
LAB_1400221ca:
            if (lVar5 < 1) goto LAB_1400221d3;
            goto LAB_140022264;
          }
        }
        else {
          uVar8 = 0;
          do {
            param_2 = (short *)(ulonglong)(uVar8 * 2);
            uVar3 = *(uint *)(param_1 + (longlong)(param_2 + 1));
            uVar4 = *(uint *)((longlong)puVar1 + (longlong)param_2 * 2);
            lVar5 = (ulonglong)
                    (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18
                    ) - (ulonglong)
                        (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                        uVar3 << 0x18);
            if (lVar5 != 0) goto LAB_14002219f;
            uVar8 = uVar8 + 1;
          } while (uVar8 < 4);
        }
        do {
          param_2 = (short *)(ulonglong)(uVar6 * 2);
          uVar8 = *(uint *)(param_1 + (longlong)(param_2 + 5));
          uVar3 = *(uint *)((longlong)puVar1 + (longlong)param_2 * 2);
          lVar5 = (ulonglong)
                  (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18)
                  - (ulonglong)
                    (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18
                    );
          if (lVar5 != 0) goto LAB_1400221ca;
          uVar6 = uVar6 + 1;
        } while (uVar6 < 4);
      }
LAB_1400221d3:
      return CONCAT71((int7)((ulonglong)param_2 >> 8),1);
    }
  }
  return (ulonglong)param_2 & 0xffffffffffffff00;
}



===== AgileVpnReturnNetBufferLists @ 140022280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AgileVpnReturnNetBufferLists(undefined8 param_1,undefined8 *param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined1 uVar5;
  bool bVar6;
  
  if (param_2 != (undefined8 *)0x0) {
    do {
      puVar3 = (undefined8 *)*param_2;
      piVar4 = (int *)param_2[0xc];
      *param_2 = 0;
      NetioDereferenceNetBufferList(param_2,param_3 & 1);
      uVar5 = KeAcquireSpinLockRaiseToDpc(piVar4 + 0xe);
      piVar1 = piVar4 + 4;
      *piVar1 = *piVar1 + -1;
      *(undefined1 *)(piVar4 + 0x10) = uVar5;
      if ((*piVar1 == 0) && ((piVar4[0x35] & 0x4000U) != 0)) {
        KeReleaseSpinLock(piVar4 + 0xe,uVar5);
        InitiateConnectionCleanup(piVar4,0xc000013c);
      }
      else {
        KeReleaseSpinLock(piVar4 + 0xe,uVar5);
      }
      LOCK();
      iVar2 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(piVar4 + 2))(piVar4);
      }
      LOCK();
      iVar2 = DAT_140012248 + -1;
      UNLOCK();
      bVar6 = DAT_140012248 == 1;
      DAT_140012248 = iVar2;
      if (bVar6) {
        (*DAT_140012250)(&DAT_140012248);
      }
      LOCK();
      _agileVpnUlPackReceivedComplete = _agileVpnUlPackReceivedComplete + 1;
      UNLOCK();
      param_2 = puVar3;
    } while (puVar3 != (undefined8 *)0x0);
  }
  return;
}



===== AgileVpnCoSendNetBufferLists @ 1400223b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AgileVpnCoSendNetBufferLists(int *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  int *piVar5;
  undefined8 *puVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  char *pcVar17;
  int iVar18;
  bool bVar19;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  puVar11 = (undefined8 *)0x0;
  bVar8 = false;
  bVar19 = false;
  DAT_1400144f8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144f0);
  puVar12 = (undefined4 *)&DAT_1400144f0;
  puVar6 = param_2;
  if ((DAT_140014514 & 1) == 0) {
    LOCK();
    DAT_140012248 = DAT_140012248 + 1;
    UNLOCK();
    KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xe);
    *(undefined1 *)(param_1 + 0x10) = uVar9;
    if ((param_1[0x35] & 0x20U) != 0) {
      KeReleaseSpinLock(param_1 + 0xe,uVar9);
      puVar12 = &DAT_140012248;
      DereferenceRefCount(&DAT_140012248);
      iVar18 = -0x3fffff66;
      goto LAB_1400226c5;
    }
    KeReleaseSpinLock();
    bVar8 = true;
    if ((char)param_1[0x50] == '\0') {
      while (puVar15 = auStack_58, param_2 != (undefined8 *)0x0) {
        puVar6 = (undefined8 *)*param_2;
        *param_2 = 0;
        ApplyQoSAndTransmitPacket((longlong)param_2,param_1);
        param_2 = puVar6;
      }
      goto LAB_140022583;
    }
    puVar13 = &DAT_140012440;
    puVar11 = (undefined8 *)ExAllocateFromNPagedLookasideList();
    puVar15 = auStack_58;
    puVar16 = auStack_58;
    if (puVar11 == (undefined8 *)0x0) {
      if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
        pcVar17 = "Send Packets will be dropped as Dgram allocation failed";
        goto LAB_140022711;
      }
    }
    else {
      *(uint *)(puVar11 + 3) = *(uint *)(puVar11 + 3) | 1;
      puVar11[2] = param_2;
      puVar11[4] = param_1;
      *(undefined1 *)(puVar11 + 5) = 1;
      LOCK();
      *param_1 = *param_1 + 1;
      UNLOCK();
      LOCK();
      DAT_140012248 = DAT_140012248 + 1;
      UNLOCK();
      bVar19 = true;
      uVar10 = GetCurrentProcessor();
      puVar15 = auStack_58;
      puVar16 = auStack_58;
      puVar13 = (undefined *)(ulonglong)uVar10;
      uVar1 = *(uint *)(param_2 + 0x1a);
      if ((param_1[0x5d] < 0x30d41) && (param_1[0x5f] < 0x2ab99)) {
        LOCK();
        param_1[0x5d] = param_1[0x5d] + 1;
        UNLOCK();
        LOCK();
        param_1[0x5e] = param_1[0x5e] + 1;
        UNLOCK();
        param_1 = (int *)((ulonglong)(uVar1 + (uVar10 - uVar1 / 3) * 3) * 0x40);
        KeAcquireInStackQueuedSpinLock(DAT_1400165c8 + 0x38 + (longlong)param_1,&local_38);
        plVar14 = (longlong *)(DAT_1400165c8 + 8 + (longlong)param_1);
        puVar2 = (undefined8 *)plVar14[1];
        plVar3 = (longlong *)*plVar14;
        if ((longlong *)*puVar2 == plVar14) {
          *puVar11 = plVar14;
          puVar11[1] = puVar2;
          *puVar2 = puVar11;
          plVar14[1] = (longlong)puVar11;
          if (plVar3 == plVar14) {
            NdisSetEvent(DAT_1400165c8 + 0x20 + (longlong)param_1);
          }
          KeReleaseInStackQueuedSpinLock(&local_38);
          puVar15 = auStack_58;
          goto LAB_140022583;
        }
        puVar13 = (undefined *)0x3;
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)();
        puVar16 = auStack_50;
      }
      else if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) == 0) goto LAB_1400225c6;
      pcVar17 = "Dropping send packet as queue is full";
LAB_140022711:
      *(undefined8 *)(puVar16 + -8) = 0x140022724;
      McTemplateK0s_EtwWriteTransfer(puVar13,&RasAgileVpnTraceError,&DAT_14000d218,pcVar17);
      puVar15 = puVar16;
    }
LAB_1400225c6:
    iVar18 = -0x3fffff66;
  }
  else {
    KeReleaseSpinLock(&DAT_1400144f0,DAT_1400144f8);
    iVar18 = -0x3fdcffd6;
LAB_1400226c5:
    if ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (puVar12,&RasAgileVpnTraceError,&DAT_14000d218,
                 "AgileVpnCoSendNetBufferLists: Packets will be droped as AgileVpnCheckAdapterTunnelStates failed"
                );
    }
    puVar15 = auStack_58;
    if (-1 < iVar18) {
      return;
    }
  }
  for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
    *(int *)((longlong)puVar6 + 0x8c) = iVar18;
  }
  LOCK();
  _agileVpnUlPackSentError = _agileVpnUlPackSentError + 1;
  UNLOCK();
  uVar4 = *(undefined8 *)(param_1 + 0x12);
  *(undefined8 *)(puVar15 + -8) = 0x1400225fb;
  NdisMCoSendNetBufferListsComplete(uVar4,param_2,0);
  if (bVar19) {
    *(undefined8 *)(puVar15 + -8) = 0x140022611;
    DereferenceRefCount(&DAT_140012248);
    piVar5 = (int *)puVar11[4];
    *(undefined8 *)(puVar15 + -8) = 0x14002261a;
    DereferenceRefCount(piVar5);
  }
  if (puVar11 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x140022630;
    ExFreeToNPagedLookasideList(&DAT_140012440,puVar11);
  }
  if (!bVar8) {
    return;
  }
LAB_140022583:
  LOCK();
  iVar18 = DAT_140012248 + -1;
  UNLOCK();
  bVar19 = DAT_140012248 == 1;
  DAT_140012248 = iVar18;
  if (bVar19) {
    *(undefined8 *)(puVar15 + -8) = 0x140022669;
    (*DAT_140012250)(&DAT_140012248);
  }
  return;
}



===== SendComplete @ 140022730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SendComplete(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  
  piVar2 = (int *)*param_1;
  lVar3 = param_1[1];
  iVar1 = *(int *)(param_2 + 0x8c);
  if ((iVar1 < 0) && ((Microsoft_Windows_Ras_AgileVpnEnableBits & 4) != 0)) {
    McTemplateK0sx_EtwWriteTransfer
              ((longlong)iVar1,&RasAgileVpnTraceIntArgError,&DAT_14000feb8,
               "SendComplete: failed with Error",(char)iVar1);
  }
  uVar4 = 0x14;
  if ((short)piVar2[0x1f] != 2) {
    uVar4 = 0x28;
  }
  NdisAdvanceNetBufferListDataStart(param_2,uVar4,1,0);
  *(undefined8 *)(param_2 + 8) = param_1[2];
  ExFreeToNPagedLookasideList(&DAT_140016780,param_1);
  FwpsFreeNetBufferList0(param_2);
  uVar4 = *(undefined8 *)(lVar3 + 0x18);
  NdisFreeCloneNetBufferList(lVar3,0);
  NdisMCoSendNetBufferListsComplete(*(undefined8 *)(piVar2 + 0x12),uVar4,0);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    (**(code **)(piVar2 + 2))(piVar2);
  }
  LOCK();
  iVar1 = DAT_140012248 + -1;
  UNLOCK();
  bVar5 = DAT_140012248 == 1;
  DAT_140012248 = iVar1;
  if (bVar5) {
    (*DAT_140012250)(&DAT_140012248);
  }
  LOCK();
  _agileVpnUlPackSentComplete = _agileVpnUlPackSentComplete + 1;
  UNLOCK();
  return;
}



===== GetPacketInfo @ 140022880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetPacketInfo(longlong param_1,undefined2 *param_2,uint *param_3)

{
  uint uVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined1 auStack_858 [32];
  undefined4 local_838;
  undefined1 local_828 [2048];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_858;
  memset(local_828,0,0x800);
  uVar1 = *(uint *)(param_1 + 0x18);
  if (0x13 < uVar1) {
    local_838 = 0;
    pbVar2 = (byte *)NdisGetDataBuffer(param_1,0x14,local_828);
    if ((pbVar2 != (byte *)0x0) && ((*pbVar2 & 0xf0) == 0x40)) {
      *param_2 = 2;
      *(byte *)param_3 = pbVar2[1] >> 2;
      return 0;
    }
  }
  if (0x27 < uVar1) {
    local_838 = 0;
    puVar3 = (uint *)NdisGetDataBuffer(param_1,0x28,local_828);
    if ((puVar3 != (uint *)0x0) && (((byte)*puVar3 & 0xf0) == 0x60)) {
      *param_2 = 0x17;
      *param_3 = *puVar3 >> 0x16 & 0x3f;
      return 0;
    }
  }
  return 0xc023000f;
}



===== FindTunnelCbFromTunnelId @ 140022990 =====

undefined8 * FindTunnelCbFromTunnelId(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)0x0;
  DAT_1400144c8 = KeAcquireSpinLockRaiseToDpc(&DAT_1400144c0);
  puVar1 = (undefined8 *)(&DAT_1400124c0)[(ulonglong)((uint)param_1 & 0x1ff) * 2];
  do {
    if (puVar1 == &DAT_1400124c0 + (ulonglong)((uint)param_1 & 0x1ff) * 2) {
LAB_1400229e9:
      KeReleaseSpinLock(&DAT_1400144c0,DAT_1400144c8);
      return puVar2;
    }
    if (puVar1[0x12] == param_1) {
      puVar2 = puVar1 + -3;
      LOCK();
      *(int *)(puVar1 + -3) = *(int *)(puVar1 + -3) + 1;
      UNLOCK();
      goto LAB_1400229e9;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== AgileVpnCompleteNblsPreRecv @ 140022a20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AgileVpnCompleteNblsPreRecv(int *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  while (param_2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_2;
    *param_2 = 0;
    NetioDereferenceNetBufferList(param_2,0);
    param_2 = puVar1;
  }
  DereferenceRefCount(param_1);
  DereferenceRefCount(&DAT_140012248);
  LOCK();
  _agileVpnUlPackReceivedError = _agileVpnUlPackReceivedError + 1;
  UNLOCK();
  return;
}



===== entry @ 140023010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140023044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  char cVar2;
  char *pcVar3;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    pcVar3 = (char *)(*pcVar1)(6);
    cVar2 = (char)pcVar3;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
    *pcVar3 = *pcVar3 + cVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


