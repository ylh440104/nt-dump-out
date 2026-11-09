
===== SecAllocateEtwDescriptors @ 140001000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong SecAllocateEtwDescriptors(uint param_1)

{
  longlong lVar1;
  
  if (0xf < param_1) {
    return 0;
  }
  _DAT_140005354 = _DAT_140005354 + 1;
  lVar1 = ExpInterlockedPopEntrySList(&DAT_140005340);
  if (lVar1 == 0) {
    _DAT_140005358 = _DAT_140005358 + 1;
    lVar1 = (*DAT_140005370)(DAT_140005364,DAT_14000536c,DAT_140005368);
  }
  return lVar1;
}



===== SecAuditWfpCallout @ 14000105c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecAuditWfpCallout(undefined8 param_1,undefined2 param_2,undefined8 param_3,short *param_4,
                       longlong param_5,undefined8 *param_6,undefined1 param_7,undefined1 param_8)

{
  short sVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined1 auStackY_1d8 [32];
  undefined2 local_148 [64];
  undefined2 local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  memset(local_148,0,0x80);
  memset(local_c8,0,0x80);
  cVar2 = EtwEventEnabled(DAT_140005328,param_1);
  if (cVar2 != '\0') {
    lVar10 = SecGetProtocolFromCallout(param_4);
    uVar4 = SecGetLocalPortFromCallout(param_4);
    uVar5 = SecGetRemotePortFromCallout(param_4);
    uVar6 = SecGetInterfaceIndexFromCallout(param_4);
    uVar11 = SecGetAddressFamilyFromCallout(param_4);
    uVar7 = SecGetDirectionFromCallout(param_4,param_5);
    if ((short)uVar11 == 2) {
      uVar8 = SecGetIpV4LocalAddressFromCallout(param_4);
      SecConvertIpV4AddressAndPortToSocketAddresss(uVar8,uVar4,local_c8);
      uVar8 = SecGetIpV4RemoteAddressFromCallout(param_4);
      SecConvertIpV4AddressAndPortToSocketAddresss(uVar8,uVar5,local_148);
    }
    else {
      if ((short)uVar11 != 0x17) {
        return;
      }
      puVar12 = (undefined8 *)SecGetIpV6LocalAddressFromCallout(param_4);
      SecConvertIpV6AddressAndPortToSocketAddresss(puVar12,uVar4,local_c8);
      puVar12 = (undefined8 *)SecGetIpV6RemoteAddressFromCallout(param_4);
      SecConvertIpV6AddressAndPortToSocketAddresss(puVar12,uVar5,local_148);
    }
    uVar9 = PsGetProcessId(param_3);
    sVar1 = *param_4;
    uVar11 = *param_6;
    uVar3 = PsGetProcessCreateTimeQuadPart(param_3);
    uVar13 = SecGetProcessStartKey();
    SecEtwWriteWfpCallout
              (param_1,param_2,uVar9,uVar13,uVar3,param_8,(char)uVar7,param_7,(char)uVar11,
               (char)sVar1,(char)uVar6,(char)lVar10,0x80,(longlong)local_c8,0x80,(longlong)local_148
              );
  }
  return;
}



===== SecEtwWriteWfpCallout @ 1400012a4 =====

void SecEtwWriteWfpCallout
               (undefined8 param_1,undefined2 param_2,undefined4 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined4 param_13,longlong param_14,undefined4 param_15,longlong param_16)

{
  longlong *plVar1;
  undefined2 local_res10 [4];
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  local_res20 = param_4;
  plVar1 = (longlong *)SecAllocateEtwDescriptors(0xf);
  if (plVar1 != (longlong *)0x0) {
    plVar1[1] = 2;
    *plVar1 = (longlong)local_res10;
    plVar1[3] = 4;
    plVar1[2] = (longlong)local_res18;
    plVar1[5] = 8;
    plVar1[4] = (longlong)&local_res20;
    plVar1[7] = 8;
    plVar1[6] = (longlong)&param_5;
    plVar1[8] = (longlong)&param_6;
    plVar1[9] = 4;
    plVar1[10] = (longlong)&param_7;
    plVar1[0xb] = 4;
    plVar1[0xc] = (longlong)&param_8;
    plVar1[0xd] = 4;
    plVar1[0xe] = (longlong)&param_9;
    plVar1[0xf] = 8;
    plVar1[0x10] = (longlong)&param_10;
    plVar1[0x11] = 2;
    plVar1[0x12] = (longlong)&param_11;
    plVar1[0x13] = 4;
    plVar1[0x14] = (longlong)&param_12;
    plVar1[0x15] = 1;
    plVar1[0x16] = (longlong)&param_13;
    plVar1[0x17] = 4;
    plVar1[0x18] = param_14;
    *(undefined4 *)(plVar1 + 0x19) = param_13;
    *(undefined4 *)((longlong)plVar1 + 0xcc) = 0;
    plVar1[0x1a] = (longlong)&param_15;
    plVar1[0x1b] = 4;
    plVar1[0x1c] = param_16;
    *(undefined4 *)(plVar1 + 0x1d) = param_15;
    *(undefined4 *)((longlong)plVar1 + 0xec) = 0;
    EtwWrite(DAT_140005328,param_1,0,0xf,plVar1);
    SecFreeEtwDescriptors((longlong)plVar1);
  }
  return;
}



===== SecFreeEtwDescriptors @ 140001444 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SecFreeEtwDescriptors(longlong param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    _DAT_14000535c = _DAT_14000535c + 1;
    uVar1 = ExQueryDepthSList(&DAT_140005340);
    if (uVar1 < DAT_140005350) {
      ExpInterlockedPushEntrySList(&DAT_140005340,param_1);
    }
    else {
      _DAT_140005360 = _DAT_140005360 + 1;
      (*DAT_140005378)(param_1);
    }
  }
  return;
}



===== SecALEClassifyRoutine @ 1400014b0 =====

void SecALEClassifyRoutine
               (short *param_1,longlong param_2,undefined8 param_3,undefined8 *param_4,
               undefined8 param_5,undefined4 *param_6)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined *puVar6;
  char cVar7;
  
  puVar2 = param_6;
  if (((param_6[6] & 1) != 0) && (uVar3 = SecGetFlagsFromCallout(param_1), (uVar3 & 1) == 0)) {
    uVar1 = param_4[6];
    if ((short)uVar1 == 0xa1) {
      iVar5 = (int)((ulonglong)uVar1 >> 0x20);
      if (iVar5 == 0x1001) {
        puVar6 = &Event_WfpCallout;
        cVar7 = '\x01';
      }
      else {
        if (iVar5 == 0x1002) {
          puVar6 = &Event_WfpCalloutExclusion;
        }
        else {
          if (iVar5 != 0x6004) goto LAB_140001593;
          puVar6 = &Event_WfpCalloutAudit;
        }
        cVar7 = '\0';
      }
      uVar4 = IoGetCurrentProcess();
      param_6._2_2_ = (undefined2)((ulonglong)uVar1 >> 0x10);
      SecAuditWfpCallout(puVar6,param_6._2_2_,uVar4,param_1,param_2,param_4,(byte)(uVar3 >> 2) & 1,
                         cVar7);
      if (cVar7 != '\0') {
        *puVar2 = 0x1001;
        goto LAB_1400015a0;
      }
    }
  }
LAB_140001593:
  *puVar2 = 0x1002;
  if ((*(byte *)((longlong)param_4 + 0x1a) & 1) == 0) {
    return;
  }
LAB_1400015a0:
  puVar2[6] = puVar2[6] & 0xfffffffe;
  return;
}



===== SecIsolationALEClassifyRoutine @ 1400015d0 =====

void SecIsolationALEClassifyRoutine(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 *in_stack_00000030;
  
  if (((param_1 == (short *)0x0) || (sVar1 = *param_1, sVar1 == 0x30)) ||
     (((sVar1 - 0x2cU & 0xfff9) == 0 && (sVar1 != 0x30)))) {
    in_stack_00000030[6] = in_stack_00000030[6] & 0xfffffffe;
    uVar2 = 0x1001;
  }
  else {
    uVar2 = 0x2006;
  }
  *in_stack_00000030 = uVar2;
  return;
}



===== SecCommonNotifyRoutine @ 140001610 =====

undefined8 SecCommonNotifyRoutine(void)

{
  return 0;
}



===== SecTaggingOutboundClassifyRoutine @ 140001620 =====

void SecTaggingOutboundClassifyRoutine
               (undefined2 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,int *param_6)

{
  int iVar1;
  
  iVar1 = FwpsNetBufferListAssociateContext0
                    (param_3,*param_1,DAT_1400053e8,DAT_1400053e8,&SEC_MDE_WFP_PROVIDER_KEY,
                     DAT_140005308,SecNetBufferListNotify,0);
  *param_6 = (iVar1 >> 0x1f & 0xffffeffbU) + 0x2006;
  return;
}



===== SecEthernetNativeOutboundClassifyRoutine @ 140001690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecEthernetNativeOutboundClassifyRoutine
               (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_58 [32];
  undefined8 *local_38;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = &local_28;
  local_28 = 0;
  iVar2 = FwpsNetBufferListRetrieveContext0(param_3,DAT_1400053e8,0,0);
  if (iVar2 < 0) {
    cVar1 = IsNativeFrameContainsIpPacket(param_1,param_3);
    uVar3 = 0x1001;
    if (cVar1 == '\0') {
      uVar3 = 0x2006;
    }
  }
  else {
    uVar3 = 0x2006;
  }
  *param_6 = uVar3;
  return;
}



===== SecNetBufferListNotify @ 140001730 =====

void SecNetBufferListNotify
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined2 param_4)

{
  if (param_3 != 0) {
    FwpsNetBufferListAssociateContext0
              (param_3,param_4,DAT_1400053e8,DAT_1400053e8,&SEC_MDE_WFP_PROVIDER_KEY,DAT_140005308,
               SecNetBufferListNotify,0);
  }
  return;
}



===== SecGetProcessStartKey @ 140001788 =====

void SecGetProcessStartKey(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = DAT_1400053d0;
  if ((DAT_1400053d0 == (code *)0x0) &&
     (UNRECOVERED_JUMPTABLE = DAT_1400053d8, DAT_1400053d8 == (code *)0x0)) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001400021e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== SecWfpIsValueGreater @ 1400017ac =====

undefined8 SecWfpIsValueGreater(int *param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  size_t _Size;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  iVar8 = *param_1;
  if (iVar8 != *(int *)(param_2 + 8)) {
    return 0xc000000d;
  }
  if (iVar8 < 8) {
    if (iVar8 != 7) {
      if (iVar8 == 1) {
        bVar9 = *(byte *)(param_1 + 2) < **(byte **)(param_2 + 0x18);
        bVar10 = *(byte *)(param_1 + 2) == **(byte **)(param_2 + 0x18);
      }
      else if (iVar8 == 2) {
        bVar9 = *(ushort *)(param_1 + 2) < **(ushort **)(param_2 + 0x18);
        bVar10 = *(ushort *)(param_1 + 2) == **(ushort **)(param_2 + 0x18);
      }
      else if (iVar8 == 3) {
        bVar9 = (uint)param_1[2] < **(uint **)(param_2 + 0x18);
        bVar10 = param_1[2] == **(uint **)(param_2 + 0x18);
      }
      else {
        if (iVar8 != 4) {
          if (iVar8 == 5) {
            cVar1 = **(char **)(param_2 + 0x18);
            cVar2 = (char)param_1[2];
            bVar11 = SBORROW1(cVar2,cVar1);
            bVar10 = (char)(cVar2 - cVar1) < '\0';
            bVar9 = cVar2 == cVar1;
          }
          else {
            if (iVar8 != 6) {
              return 0xc00000bb;
            }
            sVar3 = **(short **)(param_2 + 0x18);
            sVar4 = (short)param_1[2];
            bVar11 = SBORROW2(sVar4,sVar3);
            bVar10 = (short)(sVar4 - sVar3) < 0;
            bVar9 = sVar4 == sVar3;
          }
          goto LAB_1400018dd;
        }
        bVar9 = **(ulonglong **)(param_1 + 2) < **(ulonglong **)(param_2 + 0x18);
        bVar10 = **(ulonglong **)(param_1 + 2) == **(ulonglong **)(param_2 + 0x18);
      }
      bVar9 = !bVar9 && !bVar10;
      goto LAB_1400018e0;
    }
    iVar8 = **(int **)(param_2 + 0x18);
    iVar5 = param_1[2];
    bVar11 = SBORROW4(iVar5,iVar8);
    bVar10 = iVar5 - iVar8 < 0;
    bVar9 = iVar5 == iVar8;
  }
  else if (iVar8 == 8) {
    lVar6 = **(longlong **)(param_2 + 0x18);
    lVar7 = **(longlong **)(param_1 + 2);
    bVar11 = SBORROW8(lVar7,lVar6);
    bVar10 = lVar7 - lVar6 < 0;
    bVar9 = lVar7 == lVar6;
  }
  else {
    if (iVar8 == 0xb) {
      _Size = 0x10;
LAB_14000189c:
      iVar8 = memcmp(*(void **)(param_1 + 2),*(void **)(param_2 + 0x18),_Size);
    }
    else {
      if (iVar8 == 0xc) {
        bVar9 = SecWfpIsBlobGreater(*(uint **)(param_1 + 2),param_2);
        goto LAB_1400018e0;
      }
      if (iVar8 != 0x11) {
        if (iVar8 != 0x12) {
          return 0xc00000bb;
        }
        _Size = 6;
        goto LAB_14000189c;
      }
      iVar8 = wcscmp(*(wchar_t **)(param_1 + 2),*(wchar_t **)(param_2 + 0x18));
    }
    bVar11 = false;
    bVar10 = iVar8 < 0;
    bVar9 = iVar8 == 0;
  }
LAB_1400018dd:
  bVar9 = !bVar9 && bVar11 == bVar10;
LAB_1400018e0:
  *(bool *)param_3 = bVar9;
  return 0;
}



===== IN6_UNCANONICALIZE_SCOPE_ID @ 1400018f0 =====

void IN6_UNCANONICALIZE_SCOPE_ID(short *param_1,uint *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  
  if ((char)*param_1 == -1) {
    uVar2 = *(byte *)((longlong)param_1 + 1) & 0xf;
  }
  else {
    uVar1 = Ipv6UnicastAddressScope(param_1);
    uVar2 = (uint)uVar1;
  }
  if ((((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) &&
       ((param_1[3] == 0 && (param_1[4] == 0)))) &&
      ((param_1[5] == 0 && ((param_1[6] == 0 && (param_1[7] == 0x100)))))) || (uVar2 == 0xe)) {
    *param_2 = 0;
  }
  if (*param_2 >> 0x1c == uVar2) {
    *param_2 = *param_2 & 0xfffffff;
  }
  return;
}



===== Ipv6UnicastAddressScope @ 140001978 =====

undefined8 Ipv6UnicastAddressScope(short *param_1)

{
  undefined8 uVar1;
  short *psVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (((ulonglong)param_1 & 1) != 0) {
    local_18 = *(undefined8 *)param_1;
    uStack_10 = *(undefined8 *)(param_1 + 4);
  }
  psVar2 = (short *)&local_18;
  if (((ulonglong)param_1 & 1) == 0) {
    psVar2 = param_1;
  }
  if ((((char)*psVar2 == -2) && ((short)(*psVar2 & -0x4000) == -0x8000)) ||
     ((((*psVar2 == 0 &&
        ((((psVar2[1] == 0 && (psVar2[2] == 0)) && (psVar2[3] == 0)) &&
         ((psVar2[4] == 0 && (psVar2[5] == 0)))))) && (psVar2[6] == 0)) && (psVar2[7] == 0x100)))) {
    uVar1 = 2;
  }
  else if (((char)*psVar2 != -2) || (uVar1 = 5, (short)(*psVar2 & -0x4000) != -0x4000)) {
    uVar1 = 0xe;
  }
  return uVar1;
}



===== IsDot11FrameContainIpPacket @ 140001a18 =====

undefined8 IsDot11FrameContainIpPacket(undefined8 param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  puVar2 = (ushort *)NdisGetDataBuffer(param_1,2,0,1,0);
  uVar3 = 0;
  if (puVar2 != (ushort *)0x0) {
    uVar1 = *puVar2;
    uVar3 = CONCAT71((int7)((ulonglong)puVar2 >> 8),(char)uVar1) & 0xffffffffffffff0c;
    if ((((char)uVar3 == '\b') && ((uVar1 & 0xf0) == 0)) &&
       (uVar3 = 0x300, (uVar1 & 0x300) != 0x300)) {
      lVar4 = NdisGetDataBuffer(param_1,0x20,0,1,0);
      uVar3 = 0;
      if (lVar4 != 0) {
        uVar1 = *(ushort *)(lVar4 + 0x1e) >> 8 | *(ushort *)(lVar4 + 0x1e) << 8;
        uVar3 = (ulonglong)uVar1;
        if ((uVar1 == 0x800) || (uVar1 == 0x86dd)) {
          uVar5 = 1;
        }
      }
    }
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar5);
}



===== IsEthernetFrameContainsIpPacket @ 140001ab4 =====

undefined1 IsEthernetFrameContainsIpPacket(undefined8 param_1)

{
  ushort uVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  lVar2 = NdisGetDataBuffer(param_1,0xe,0,1,0);
  if (lVar2 != 0) {
    uVar1 = *(ushort *)(lVar2 + 0xc) >> 8 | *(ushort *)(lVar2 + 0xc) << 8;
    if (uVar1 < 0x601) {
      lVar2 = NdisGetDataBuffer(param_1,0x16,0,1,0);
      if (lVar2 == 0) {
        return 0;
      }
      if (*(char *)(lVar2 + 0xe) != -0x56) {
        return 0;
      }
      if (*(char *)(lVar2 + 0xf) != -0x56) {
        return 0;
      }
      if (*(char *)(lVar2 + 0x10) != '\x03') {
        return 0;
      }
      uVar1 = *(ushort *)(lVar2 + 0x14) >> 8 | *(ushort *)(lVar2 + 0x14) << 8;
    }
    if ((uVar1 == 0x800) || (uVar1 == 0x86dd)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}



===== IsNativeFrameContainsIpPacket @ 140001b54 =====

undefined1 IsNativeFrameContainsIpPacket(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 8) + 8);
  if (iVar1 == 0x10) {
    uVar3 = IsDot11FrameContainIpPacket(*(undefined8 *)(param_2 + 8));
    uVar2 = (undefined1)uVar3;
  }
  else {
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = IsEthernetFrameContainsIpPacket(*(undefined8 *)(param_2 + 8));
  }
  return uVar2;
}



===== SecConvertIpV4AddressAndPortToSocketAddresss @ 140001b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecConvertIpV4AddressAndPortToSocketAddresss(uint param_1,ushort param_2,undefined2 *param_3)

{
  param_3[1] = param_2 >> 8 | param_2 << 8;
  *param_3 = 2;
  *(uint *)(param_3 + 2) =
       param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
  *(undefined8 *)(param_3 + 4) = 0;
  return;
}



===== SecConvertIpV6AddressAndPortToSocketAddresss @ 140001bd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecConvertIpV6AddressAndPortToSocketAddresss
               (undefined8 *param_1,ushort param_2,undefined2 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auStack_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_38;
  param_3[1] = param_2 >> 8 | param_2 << 8;
  *param_3 = 0x17;
  *(undefined4 *)(param_3 + 2) = 0;
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *(uint *)(param_3 + 0xc) = 0;
  *(undefined8 *)(param_3 + 4) = uVar1;
  *(undefined8 *)(param_3 + 8) = uVar2;
  IN6_UNCANONICALIZE_SCOPE_ID(param_3 + 4,(uint *)(param_3 + 0xc));
  return;
}



===== SecGetAddressFamilyFromCallout @ 140001c2c =====

undefined8 SecGetAddressFamilyFromCallout(short *param_1)

{
  short sVar1;
  
  sVar1 = *param_1;
  if (sVar1 == 0x2c) {
    return 2;
  }
  if (sVar1 != 0x2e) {
    if (sVar1 == 0x30) {
      return 2;
    }
    if (sVar1 != 0x32) {
      return 0;
    }
  }
  return 0x17;
}



===== SecGetDirectionFromCallout @ 140001c5c =====

undefined4 SecGetDirectionFromCallout(short *param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 2;
  uVar1 = SecGetFlagsFromCallout(param_1);
  if ((uVar1 & 4) == 0) {
    if ((*param_1 - 0x2cU & 0xfffd) == 0) {
      uVar2 = 1;
    }
    else if ((*param_1 - 0x30U & 0xfffd) == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x8c);
  }
  return uVar2;
}



===== SecGetFlagsFromCallout @ 140001cbc =====

undefined4 SecGetFlagsFromCallout(short *param_1)

{
  short sVar1;
  longlong lVar2;
  
  sVar1 = *param_1;
  if ((sVar1 == 0x2c) || (sVar1 == 0x2e)) {
    lVar2 = 0xb8;
  }
  else {
    if ((sVar1 != 0x30) && (sVar1 != 0x32)) {
      return 0;
    }
    lVar2 = 200;
  }
  return *(undefined4 *)(lVar2 + *(longlong *)(param_1 + 4));
}



===== SecGetInterfaceIndexFromCallout @ 140001cf4 =====

undefined4 SecGetInterfaceIndexFromCallout(short *param_1)

{
  short sVar1;
  longlong lVar2;
  
  sVar1 = *param_1;
  if ((sVar1 == 0x2c) || (sVar1 == 0x2e)) {
    lVar2 = 0x108;
  }
  else {
    if ((sVar1 != 0x30) && (sVar1 != 0x32)) {
      return 0;
    }
    lVar2 = 0xf8;
  }
  return *(undefined4 *)(lVar2 + *(longlong *)(param_1 + 4));
}



===== SecGetIpV4LocalAddressFromCallout @ 140001d2c =====

undefined4 SecGetIpV4LocalAddressFromCallout(short *param_1)

{
  if ((*param_1 == 0x2c) || (*param_1 == 0x30)) {
    return *(undefined4 *)(*(longlong *)(param_1 + 4) + 0x28);
  }
  return 0;
}



===== SecGetIpV4RemoteAddressFromCallout @ 140001d48 =====

undefined4 SecGetIpV4RemoteAddressFromCallout(short *param_1)

{
  if ((*param_1 == 0x2c) || (*param_1 == 0x30)) {
    return *(undefined4 *)(*(longlong *)(param_1 + 4) + 0x68);
  }
  return 0;
}



===== SecGetIpV6LocalAddressFromCallout @ 140001d64 =====

undefined8 SecGetIpV6LocalAddressFromCallout(short *param_1)

{
  if ((*param_1 == 0x2e) || (*param_1 == 0x32)) {
    return *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x28);
  }
  return 0;
}



===== SecGetIpV6RemoteAddressFromCallout @ 140001d84 =====

undefined8 SecGetIpV6RemoteAddressFromCallout(short *param_1)

{
  if ((*param_1 == 0x2e) || (*param_1 == 0x32)) {
    return *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x68);
  }
  return 0;
}



===== SecGetLocalPortFromCallout @ 140001da4 =====

undefined2 SecGetLocalPortFromCallout(short *param_1)

{
  if ((*param_1 - 0x2cU & 0xfff9) == 0) {
    return *(undefined2 *)(*(longlong *)(param_1 + 4) + 0x48);
  }
  return 0;
}



===== SecGetProtocolFromCallout @ 140001dc4 =====

longlong SecGetProtocolFromCallout(short *param_1)

{
  if ((*param_1 - 0x2cU & 0xfff9) == 0) {
    return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 4) >> 8),
                    *(undefined1 *)(*(longlong *)(param_1 + 4) + 0x58));
  }
  return (ulonglong)(byte)((ushort)(*param_1 - 0x2cU) >> 8) << 8;
}



===== SecGetRemotePortFromCallout @ 140001de4 =====

undefined2 SecGetRemotePortFromCallout(short *param_1)

{
  if ((*param_1 - 0x2cU & 0xfff9) == 0) {
    return *(undefined2 *)(*(longlong *)(param_1 + 4) + 0x78);
  }
  return 0;
}



===== KclFindExportedRoutineByName @ 140001e04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong KclFindExportedRoutineByName(longlong param_1,char *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  char *_Str1;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_68 [32];
  char *local_48;
  longlong local_40;
  undefined4 local_38 [2];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  local_38[0] = 0;
  local_48 = param_2;
  local_40 = RtlImageDirectoryEntryToData(param_1,1,0,local_38);
  _Str1 = local_48;
  if (local_40 != 0) {
    uVar2 = *(uint *)(local_40 + 0x20);
    iVar7 = 0;
    uVar3 = *(uint *)(local_40 + 0x24);
    iVar5 = *(int *)(local_40 + 0x18) + -1;
    if (-1 < iVar5) {
      do {
        iVar6 = iVar7 + iVar5 >> 1;
        iVar4 = strcmp(_Str1,(char *)((ulonglong)
                                      *(uint *)((ulonglong)uVar2 + param_1 + (longlong)iVar6 * 4) +
                                     param_1));
        if (iVar4 < 0) {
          iVar5 = iVar6 + -1;
        }
        else {
          if (iVar4 < 1) break;
          iVar7 = iVar6 + 1;
        }
      } while (iVar7 <= iVar5);
      if ((iVar7 <= iVar5) &&
         (uVar1 = *(ushort *)((ulonglong)uVar3 + param_1 + (longlong)iVar6 * 2),
         (uint)uVar1 < *(uint *)(local_40 + 0x14))) {
        return (ulonglong)
               *(uint *)((ulonglong)*(uint *)(local_40 + 0x1c) + param_1 + (ulonglong)uVar1 * 4) +
               param_1;
      }
    }
  }
  return 0;
}



===== KclGetExportRoutineInModule @ 140001f00 =====

int KclGetExportRoutineInModule(char *param_1,char *param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong local_res20;
  
  local_res20 = 0;
  iVar1 = KclQuerySystemModuleBase(&local_res20,param_1);
  if (-1 < iVar1) {
    lVar2 = KclFindExportedRoutineByName(local_res20,param_2);
    *param_3 = lVar2;
    iVar1 = 0;
  }
  return iVar1;
}



===== __GSHandlerCheck @ 140001f48 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001f68 =====

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



===== wcscmp @ 140001fd0 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001fd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== ZwQueryInformationProcess @ 140001fdc =====

void ZwQueryInformationProcess(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001fdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ZwQueryInformationProcess();
  return;
}



===== ZwQuerySystemInformation @ 140001fe8 =====

void ZwQuerySystemInformation(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ZwQuerySystemInformation();
  return;
}



===== strcmp @ 140001ff4 =====

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001ff4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 140002000 =====

/* WARNING: Removing unreachable block (ram,0x00014000206a) */
/* WARNING: Removing unreachable block (ram,0x000140002019) */
/* WARNING: Removing unreachable block (ram,0x00014000200a) */

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



===== _guard_check_icall @ 1400020c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 1400020d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== FwpmBfeStateGet0 @ 1400020fd =====

void FwpmBfeStateGet0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400020fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmBfeStateGet0();
  return;
}



===== FwpmBfeStateSubscribeChanges0 @ 140002109 =====

void FwpmBfeStateSubscribeChanges0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002109. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmBfeStateSubscribeChanges0();
  return;
}



===== FwpmBfeStateUnsubscribeChanges0 @ 140002115 =====

void FwpmBfeStateUnsubscribeChanges0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002115. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmBfeStateUnsubscribeChanges0();
  return;
}



===== FwpmEngineOpen0 @ 140002121 =====

void FwpmEngineOpen0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002121. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmEngineOpen0();
  return;
}



===== FwpmEngineClose0 @ 14000212d =====

void FwpmEngineClose0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000212d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmEngineClose0();
  return;
}



===== FwpmCalloutAdd0 @ 140002139 =====

void FwpmCalloutAdd0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002139. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmCalloutAdd0();
  return;
}



===== FwpmCalloutDeleteByKey0 @ 140002145 =====

void FwpmCalloutDeleteByKey0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmCalloutDeleteByKey0();
  return;
}



===== FwpsCalloutRegister0 @ 140002151 =====

void FwpsCalloutRegister0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002151. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpsCalloutRegister0();
  return;
}



===== FwpsCalloutUnregisterByKey0 @ 14000215d =====

void FwpsCalloutUnregisterByKey0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000215d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpsCalloutUnregisterByKey0();
  return;
}



===== FwpsNetBufferListGetTagForContext0 @ 140002169 =====

void FwpsNetBufferListGetTagForContext0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002169. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpsNetBufferListGetTagForContext0();
  return;
}



===== FwpsNetBufferListAssociateContext0 @ 140002175 =====

void FwpsNetBufferListAssociateContext0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpsNetBufferListAssociateContext0();
  return;
}



===== FwpsNetBufferListRetrieveContext0 @ 140002181 =====

void FwpsNetBufferListRetrieveContext0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002181. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpsNetBufferListRetrieveContext0();
  return;
}



===== FltInitializePushLock @ 14000218d =====

void FltInitializePushLock(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000218d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FltInitializePushLock();
  return;
}



===== FltDeletePushLock @ 140002199 =====

void FltDeletePushLock(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002199. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FltDeletePushLock();
  return;
}



===== FltAcquirePushLockExclusiveEx @ 1400021a5 =====

void FltAcquirePushLockExclusiveEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400021a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FltAcquirePushLockExclusiveEx();
  return;
}



===== FltAcquirePushLockSharedEx @ 1400021b1 =====

void FltAcquirePushLockSharedEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400021b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FltAcquirePushLockSharedEx();
  return;
}



===== FltReleasePushLockEx @ 1400021bd =====

void FltReleasePushLockEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400021bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FltReleasePushLockEx();
  return;
}



===== _guard_dispatch_icall @ 1400021e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400021e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002200 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== __security_check_cookie @ 140002220 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== memset @ 140002240 =====

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



===== __memset_repmovs @ 140002380 =====

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



===== __memset_query @ 140002400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== memcmp @ 140002440 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140002483;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400024f4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400024f0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400024f4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400024ec:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400024f0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400024ec;
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
LAB_1400024f4:
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
LAB_140002483:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140002540 =====

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



===== SecAuditWfpFilterCondition @ 140007000 =====

void SecAuditWfpFilterCondition
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,longlong param_11,uint param_12)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined2 local_res20 [4];
  
  uVar1 = 0x400;
  if (param_12 < 0x400) {
    uVar1 = param_12;
  }
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  param_12 = uVar1;
  plVar2 = (longlong *)SecAllocateEtwDescriptors(0xb);
  if (plVar2 != (longlong *)0x0) {
    plVar2[1] = 4;
    *plVar2 = (longlong)local_res10;
    plVar2[3] = 4;
    plVar2[2] = (longlong)local_res18;
    plVar2[5] = 2;
    plVar2[4] = (longlong)local_res20;
    plVar2[6] = (longlong)&param_5;
    plVar2[7] = 8;
    plVar2[8] = (longlong)&param_6;
    plVar2[9] = 4;
    plVar2[10] = (longlong)&param_7;
    plVar2[0xb] = 4;
    plVar2[0xc] = (longlong)&param_8;
    plVar2[0xd] = 2;
    plVar2[0xe] = (longlong)&param_9;
    plVar2[0xf] = 4;
    plVar2[0x10] = (longlong)&param_10;
    plVar2[0x11] = 4;
    plVar2[0x12] = (longlong)&param_12;
    plVar2[0x13] = 4;
    *(uint *)(plVar2 + 0x15) = param_12;
    lVar3 = 0;
    if (param_12 != 0) {
      lVar3 = param_11;
    }
    plVar2[0x14] = lVar3;
    *(undefined4 *)((longlong)plVar2 + 0xac) = 0;
    EtwWrite(DAT_140005328,param_1,0,0xb,plVar2);
    SecFreeEtwDescriptors((longlong)plVar2);
  }
  return;
}



===== SecAuditWfpGuardBlock @ 140007140 =====

void SecAuditWfpGuardBlock
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               longlong param_13,uint param_14,undefined1 param_15)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined2 local_res20 [4];
  
  uVar1 = 0x400;
  if (param_14 < 0x400) {
    uVar1 = param_14;
  }
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  param_14 = uVar1;
  plVar2 = (longlong *)SecAllocateEtwDescriptors(0xe);
  if (plVar2 != (longlong *)0x0) {
    plVar2[1] = 4;
    *plVar2 = (longlong)local_res10;
    plVar2[3] = 4;
    plVar2[2] = (longlong)local_res18;
    plVar2[5] = 2;
    plVar2[4] = (longlong)local_res20;
    plVar2[6] = (longlong)&param_5;
    plVar2[7] = 4;
    plVar2[8] = (longlong)&param_6;
    plVar2[9] = 2;
    plVar2[10] = (longlong)&param_7;
    plVar2[0xb] = 4;
    plVar2[0xc] = (longlong)&param_8;
    plVar2[0xd] = 4;
    plVar2[0xe] = (longlong)&param_9;
    plVar2[0xf] = 4;
    plVar2[0x10] = (longlong)&param_10;
    plVar2[0x11] = 8;
    plVar2[0x12] = (longlong)&param_11;
    plVar2[0x13] = 2;
    plVar2[0x14] = (longlong)&param_12;
    plVar2[0x15] = 8;
    plVar2[0x16] = (longlong)&param_14;
    plVar2[0x17] = 4;
    *(uint *)(plVar2 + 0x19) = param_14;
    lVar3 = 0;
    if (param_14 != 0) {
      lVar3 = param_13;
    }
    plVar2[0x18] = lVar3;
    *(undefined4 *)((longlong)plVar2 + 0xcc) = 0;
    plVar2[0x1a] = (longlong)&param_15;
    plVar2[0x1b] = 4;
    EtwWrite(DAT_140005328,param_1,0,0xe,plVar2);
    SecFreeEtwDescriptors((longlong)plVar2);
  }
  return;
}



===== SecShutdownAuditing @ 1400072dc =====

void SecShutdownAuditing(void)

{
  if (DAT_140005328 != 0) {
    EtwUnregister();
    DAT_140005328 = 0;
  }
  if (DAT_140005330 != '\0') {
    ExDeleteNPagedLookasideList(&DAT_140005340);
    DAT_140005330 = '\0';
  }
  return;
}



===== SecAddWfpCallouts @ 14000732c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SecAddWfpCallouts(void)

{
  longlong lVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  undefined *puVar10;
  undefined **ppuVar11;
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined *local_78;
  undefined4 local_68;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  memset(&local_88,0,0x58);
  bVar3 = false;
  lVar8 = 0;
  puVar10 = (undefined *)0x0;
  lVar1 = *(longlong *)PsInitialSystemProcess_exref;
  lVar7 = IoGetCurrentProcess();
  bVar4 = false;
  if (lVar7 != lVar1) {
    if (DAT_140005326 == '\0') goto LAB_1400073de;
    lVar8 = PsReferencePrimaryToken(lVar1);
    if (lVar8 == 0) goto LAB_1400073de;
    local_98 = (undefined8 *)CONCAT44(local_98._4_4_,2);
    iVar5 = PsImpersonateClient(SystemReserved1[0xf],lVar8,0);
    if (iVar5 < 0) goto LAB_1400073de;
    bVar4 = true;
  }
  bVar3 = bVar4;
  puVar10 = &DAT_140003ac0;
LAB_1400073de:
  local_98 = &DAT_140005310;
  iVar5 = FwpmEngineOpen0(0,10,0);
  if (-1 < iVar5) {
    uVar9 = 0;
    ppuVar11 = &PTR_u_MsSecWfp_outbou_140005010;
    do {
      memset(&local_88,0,0x58);
      local_88 = *(undefined8 *)ppuVar11[-2];
      uStack_80 = *(undefined8 *)((longlong)ppuVar11[-2] + 8);
      local_78 = *ppuVar11;
      puVar2 = (undefined4 *)ppuVar11[-1];
      local_48 = *puVar2;
      uStack_44 = puVar2[1];
      uStack_40 = puVar2[2];
      uStack_3c = puVar2[3];
      local_68 = 0x10000;
      iVar6 = FwpmCalloutAdd0(DAT_140005310,&local_88,puVar10,0);
      iVar5 = 0;
      if (iVar6 != -0x3fddfff7) {
        iVar5 = iVar6;
      }
      if (iVar5 < 0) goto LAB_140007476;
      uVar9 = uVar9 + 1;
      ppuVar11 = ppuVar11 + 6;
    } while (uVar9 < 0xc);
    iVar5 = 0;
  }
LAB_140007476:
  if (lVar8 != 0) {
    PsDereferencePrimaryToken(lVar8);
  }
  if (bVar3) {
    PsRevertToSelf();
  }
  return iVar5;
}



===== SecBfeStateChangeCallback @ 1400074d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SecBfeStateChangeCallback(undefined8 param_1,int param_2)

{
  _DAT_140005320 = param_2;
  if (param_2 == 3) {
    SecAddWfpCallouts();
  }
  return;
}



===== SecRegisterWfpCallouts @ 1400074ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecRegisterWfpCallouts(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined *local_30;
  undefined *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = 0;
  ppuVar3 = &PTR_SecALEClassifyRoutine_140005018;
  do {
    uStack_38 = 0;
    local_20 = 0;
    local_48 = *(undefined8 *)ppuVar3[-3];
    uStack_40 = *(undefined8 *)((longlong)ppuVar3[-3] + 8);
    local_30 = *ppuVar3;
    local_28 = ppuVar3[1];
    iVar1 = FwpsCalloutRegister0(DAT_140005308,&local_48,0);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = uVar2 + 1;
    ppuVar3 = ppuVar3 + 6;
  } while (uVar2 < 0xc);
  return;
}



===== SecShutdownWfpCallouts @ 140007584 =====

void SecShutdownWfpCallouts(void)

{
  undefined **ppuVar1;
  longlong lVar2;
  undefined **ppuVar3;
  longlong lVar4;
  
  if (DAT_140005318 != 0) {
    FwpmBfeStateUnsubscribeChanges0();
    DAT_140005318 = 0;
  }
  ppuVar1 = &SecWfpCallouts;
  lVar4 = 0xc;
  if (DAT_140005310 != 0) {
    ppuVar3 = &SecWfpCallouts;
    lVar2 = 0xc;
    do {
      FwpmCalloutDeleteByKey0(DAT_140005310,*ppuVar3);
      ppuVar3 = ppuVar3 + 6;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    FwpmEngineClose0(DAT_140005310);
    DAT_140005310 = 0;
  }
  do {
    FwpsCalloutUnregisterByKey0(*ppuVar1);
    ppuVar1 = ppuVar1 + 6;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== DriverUnload @ 140007630 =====

void DriverUnload(void)

{
  SecShutdownWfpGuard();
  SecShutdownWfpCallouts();
  SecShutdownAuditing();
  SecDeleteDevice();
  SecDeleteGlobalData();
  return;
}



===== SecCreateDevice @ 140007654 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SecCreateDevice(longlong param_1)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined1 local_30;
  longlong *local_28;
  longlong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  *(code **)(param_1 + 0x70) = SecDeviceOpen;
  *(code **)(param_1 + 0x80) = SecDeviceClose;
  *(code **)(param_1 + 0xe0) = SecDeviceIoControl;
  *(code **)(param_1 + 0x68) = DriverUnload;
  local_28 = &DAT_140005308;
  local_30 = 0;
  local_38 = CONCAT44(local_38._4_4_,0x100);
  iVar1 = IoCreateDevice(param_1,0,&DAT_140003b20,0x22);
  if (-1 < iVar1) {
    local_28 = &local_18;
    local_30 = 0;
    local_38 = 0;
    iVar1 = ObOpenObjectByPointer(DAT_140005308,0x200,0,0x40000);
    if (-1 < iVar1) {
      iVar1 = ZwSetSecurityObject(local_18,0x84,&DAT_140003b90);
      if (-1 < iVar1) {
        iVar1 = IoCreateSymbolicLink(&DAT_140003b58,&DAT_140003b20);
        if (-1 < iVar1) {
          iVar1 = KclSetSymbolicLinkObjectSecurity(&DAT_140003b58,0x84,&DAT_140003b90);
        }
      }
    }
  }
  if (local_18 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== SecDeleteDevice @ 1400077ac =====

void SecDeleteDevice(void)

{
  if (DAT_140005308 != 0) {
    IoDeleteSymbolicLink(&DAT_140003b58);
    IoDeleteDevice(DAT_140005308);
    DAT_140005308 = 0;
  }
  return;
}



===== SecDeleteGlobalData @ 1400077f4 =====

void SecDeleteGlobalData(void)

{
  if (DAT_1400053c8 != 0) {
    ExFreePoolWithTag(DAT_1400053c8,0);
    DAT_1400053c8 = 0;
  }
  return;
}



===== SecDeviceClose @ 140007830 =====

undefined8 SecDeviceClose(undefined8 param_1,longlong param_2)

{
  DAT_1400053c0 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== SecDeviceIoControl @ 140007860 =====

int SecDeviceIoControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (iVar1 == 0x222004) {
    *(code **)(GlobalData + 0x68) = DriverUnload;
  }
  else if (iVar1 == 0x222008) {
    iVar2 = SecSetWfpGuardConfiguration
                      (*(uint **)(param_2 + 0x18),*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10));
  }
  else {
    iVar2 = -0x3ffffff3;
  }
  *(int *)(param_2 + 0x30) = iVar2;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== SecDeviceOpen @ 1400078e0 =====

undefined4 SecDeviceOpen(undefined8 param_1,longlong param_2)

{
  char cVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  cVar1 = KclIsWindowsBlueOrLater();
  if (cVar1 == '\0') {
LAB_14000790c:
    IoGetCurrentProcess();
    uVar3 = SecIsSenseService();
    if (((char)uVar3 != '\0') && (DAT_1400053c0 == 0)) {
      DAT_1400053c0 = IoGetCurrentProcess();
      goto LAB_140007940;
    }
  }
  else {
    bVar2 = KclIsProcessWindowsProtectedLight(0xffffffffffffffff);
    if (bVar2) goto LAB_14000790c;
  }
  uVar4 = 0xc0000022;
LAB_140007940:
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== SecInitializeGlobalData @ 14000796c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SecInitializeGlobalData(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  memset(&DAT_140005308,0,0xf8);
  GlobalData = param_1;
  DAT_140005324 = KclIsWindows7();
  DAT_140005325 = KclIsWindows8();
  DAT_140005326 = KclIsWindowsBlueOrLater();
  RtlInitUnicodeString(&local_28,L"PsGetProcessStartKey");
  DAT_1400053d0 = MmGetSystemRoutineAddress(&local_28);
  RtlInitUnicodeString(&local_28,L"EtwGetProcessStartKey");
  DAT_1400053d8 = MmGetSystemRoutineAddress(&local_28);
  RtlInitUnicodeString(&local_28,L"SeConvertSecurityDescriptorToStringSecurityDescriptor");
  DAT_1400053e0 = MmGetSystemRoutineAddress(&local_28);
  iVar1 = KclInitializeSenseServiceSid(0x73537753,&DAT_1400053c8);
  if (-1 < iVar1) {
    SecInitializeWfpGuardLock();
  }
  return iVar1;
}



===== SecSealDriver @ 140007a90 =====

void SecSealDriver(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x68) = 0;
  return;
}



===== SecIsSenseService @ 140007a9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SecIsSenseService(void)

{
  char cVar1;
  int iVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  undefined4 extraout_var_00;
  bool bVar4;
  undefined1 auStack_38 [32];
  char local_18 [8];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  bVar4 = false;
  local_18[0] = '\0';
  cVar1 = KclIsProcessLocalSystem();
  uVar3 = CONCAT71(extraout_var,cVar1);
  if (cVar1 != '\0') {
    iVar2 = KclCheckCurrentTokenMembership(DAT_1400053c8,local_18);
    uVar3 = CONCAT44(extraout_var_00,iVar2);
    if (-1 < iVar2) {
      bVar4 = local_18[0] != '\0';
      uVar3 = 0;
    }
  }
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),bVar4);
}



===== SecWfpGetSecurityDescriptorAsUnicodeString @ 140007afc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SecWfpGetSecurityDescriptorAsUnicodeString(longlong param_1,short *param_2)

{
  ulonglong uVar1;
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined8 local_28;
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_20[0] = 0;
  if ((param_1 == 0) || (param_2 == (short *)0x0)) {
    uVar1 = 0xc000000d;
  }
  else if (DAT_1400053e0 == 0) {
    uVar1 = 0xc0000225;
  }
  else {
    local_38 = local_20;
    uVar1 = (*(code *)DAT_1400053e0)(param_1,1,0xffffffff,&local_28);
    if (-1 < (int)uVar1) {
      *(undefined8 *)(param_2 + 4) = local_28;
      *param_2 = (short)local_20[0] * 2;
      param_2[1] = (short)local_20[0] * 2;
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}



===== SecWfpGetSidAsUnicodeString @ 140007ba0 =====

undefined8 SecWfpGetSidAsUnicodeString(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0xc000000d;
  }
                    /* WARNING: Could not recover jumptable at 0x000140007bb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = RtlConvertSidToUnicodeString(param_2,param_1,1);
  return uVar1;
}



===== SecInitializeWfpGuard @ 140007bcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SecInitializeWfpGuard(void)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined1 auStack_1d8 [32];
  undefined4 *local_1b8;
  code *local_1a8 [2];
  undefined4 local_198 [96];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1d8;
  local_1a8[0] = (code *)0x0;
  if (SecWfpGuardInitialized == '\0') {
    iVar1 = KclGetExportRoutineInModule
                      ("\\SystemRoot\\System32\\drivers\\NETIO.SYS","KfdRegisterLayerEventNotifyEx",
                       (longlong *)local_1a8);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_1a8[0] != (code *)0x0) {
      puVar3 = local_198;
      for (lVar2 = 0x5f; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar3 = 1;
        puVar3 = puVar3 + 1;
      }
      local_1b8 = local_198;
      iVar1 = (*local_1a8[0])(1,0,SecWfpShouldForbidFiltersAssignment);
      if (iVar1 < 0) {
        return iVar1;
      }
      SecWfpGuardInitialized = '\x01';
      return iVar1;
    }
  }
  return 0;
}



===== SecInitializeWfpGuardLock @ 140007c7c =====

void SecInitializeWfpGuardLock(void)

{
  FltInitializePushLock(&SecWfpGuardPolicyConfigLock);
  return;
}



===== SecIsPrefixMatch @ 140007c88 =====

bool SecIsPrefixMatch(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  if (((*param_2 != 0) && (uVar1 = *param_1, uVar1 != 0)) && (uVar1 <= *param_2)) {
    iVar2 = memcmp(*(void **)(param_2 + 2),*(void **)(param_1 + 2),(ulonglong)uVar1);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}



===== SecIsSidAllowedInSecurityDescriptor @ 140007cc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 SecIsSidAllowedInSecurityDescriptor(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  longlong local_38;
  char *local_30;
  char local_28 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = '\0';
  local_38 = 0;
  local_28[1] = 0;
  local_30 = (char *)0x0;
  iVar2 = RtlGetDaclSecurityDescriptor(param_1,local_28,&local_38,local_28 + 1);
  if (-1 < iVar2) {
    if ((local_28[0] == '\0') || (local_38 == 0)) {
      return 0;
    }
    uVar3 = 0;
    if (*(short *)(local_38 + 4) != 0) {
      do {
        iVar2 = RtlGetAce(local_38,uVar3,&local_30);
        if (((-1 < iVar2) && (*local_30 == '\0')) &&
           (cVar1 = RtlEqualSid(param_2,local_30 + 8), cVar1 != '\0')) {
          return 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(local_38 + 4));
    }
  }
  return 0;
}



===== SecIsSuffixMatch @ 140007d90 =====

bool SecIsSuffixMatch(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = false;
  uVar1 = *param_2;
  if (uVar1 != 0) {
    uVar2 = *param_1;
    if ((uVar2 != 0) && (uVar2 <= uVar1)) {
      iVar3 = memcmp((void *)((*(longlong *)(param_2 + 2) - (ulonglong)uVar2) + (ulonglong)uVar1),
                     *(void **)(param_1 + 2),(ulonglong)uVar2);
      bVar4 = iVar3 == 0;
    }
  }
  return bVar4;
}



===== SecSetWfpGuardConfiguration @ 140007dd8 =====

int SecSetWfpGuardConfiguration(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  void *_Dst;
  undefined8 *puVar4;
  void *_Dst_00;
  uint uVar5;
  ulonglong uVar6;
  uint *_Src;
  uint *puVar7;
  uint *_Src_00;
  uint uVar9;
  uint uVar8;
  uint local_res8;
  uint local_res18;
  void *local_res20;
  
  local_res20 = (void *)0x0;
  local_res18 = 0;
  iVar3 = 0;
  _Dst = (void *)0x0;
  uVar9 = 0;
  uVar8 = 0;
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_2 < 8)) {
LAB_14000801f:
    uVar8 = uVar9;
    iVar3 = -0x3ffffff3;
    goto LAB_140008024;
  }
  if (*param_1 == 0) {
LAB_140007fd1:
    FltAcquirePushLockExclusiveEx(&SecWfpGuardPolicyConfigLock,0);
    local_res20 = SecWfpGuardPolicyConfig;
    local_res18 = SecWfpGuardPolicyConfigCount;
    SecWfpGuardPolicyConfigCount = uVar8;
    SecWfpGuardPolicyConfig = _Dst;
    FltReleasePushLockEx(&SecWfpGuardPolicyConfigLock,0);
    _Dst = (void *)0x0;
    uVar8 = 0;
  }
  else {
    iVar3 = SecInitializeWfpGuard();
    uVar8 = 0;
    if (iVar3 < 0) goto LAB_140008024;
    uVar8 = *param_1;
    puVar1 = (uint *)((longlong)param_1 + (ulonglong)param_2);
    uVar5 = uVar8 * 0x38;
    _Src = (uint *)((ulonglong)param_1[1] + (longlong)param_1);
    if (((puVar1 <= param_1) || ((uint *)((ulonglong)uVar5 + (longlong)_Src) <= _Src)) ||
       ((_Src < param_1 || (puVar1 < (uint *)((ulonglong)uVar5 + (longlong)_Src)))))
    goto LAB_14000801f;
    uVar6 = (ulonglong)uVar8;
    _Dst = (void *)ExAllocatePoolWithTag(0x401,(ulonglong)uVar5,0x67477753);
    if (ExPoolZeroingNativelySupported == '\0') {
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,(ulonglong)uVar5);
        goto LAB_140007ec4;
      }
    }
    else if (_Dst != (void *)0x0) {
LAB_140007ec4:
      memmove(_Dst,_Src,(ulonglong)uVar5);
      if (uVar8 != 0) {
        puVar4 = (undefined8 *)((longlong)_Dst + 0x30);
        do {
          *puVar4 = 0;
          puVar4 = puVar4 + 7;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
        local_res8 = 0;
        puVar7 = _Src + 0xb;
        do {
          uVar5 = *puVar7;
          _Src_00 = (uint *)((ulonglong)puVar7[1] + (longlong)param_1);
          puVar2 = (uint *)((ulonglong)uVar5 + (longlong)_Src_00);
          uVar9 = uVar8;
          if (((puVar2 <= _Src_00) || (_Src_00 < param_1)) || (puVar1 < puVar2)) goto LAB_14000801f;
          _Dst_00 = (void *)ExAllocatePoolWithTag(0x401,uVar5,0x67477753);
          if ((ExPoolZeroingNativelySupported == '\0') && (_Dst_00 != (void *)0x0)) {
            memset(_Dst_00,0,(ulonglong)uVar5);
            *(void **)((longlong)_Dst + (4 - (longlong)_Src) + (longlong)puVar7) = _Dst_00;
          }
          else {
            *(void **)((longlong)_Dst + (4 - (longlong)_Src) + (longlong)puVar7) = _Dst_00;
            if (_Dst_00 == (void *)0x0) goto LAB_140007f88;
          }
          memmove(_Dst_00,_Src_00,(ulonglong)*puVar7);
          puVar7 = puVar7 + 0xe;
          local_res8 = local_res8 + 1;
        } while (local_res8 < uVar8);
      }
      goto LAB_140007fd1;
    }
LAB_140007f88:
    iVar3 = -0x3fffffe9;
  }
LAB_140008024:
  SecWfpFreeWfpGuardConfig((longlong)local_res20,local_res18);
  SecWfpFreeWfpGuardConfig((longlong)_Dst,uVar8);
  return iVar3;
}



===== SecShutdownWfpGuard @ 140008060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecShutdownWfpGuard(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStack_38 [32];
  code *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = (code *)0x0;
  if (SecWfpGuardInitialized != '\0') {
    iVar3 = KclGetExportRoutineInModule
                      ("\\SystemRoot\\System32\\drivers\\NETIO.SYS","KfdDeregisterLayerEventNotify",
                       (longlong *)&local_18);
    if ((-1 < iVar3) && (local_18 != (code *)0x0)) {
      (*local_18)(1,SecWfpShouldForbidFiltersAssignment);
      FltAcquirePushLockExclusiveEx(&SecWfpGuardPolicyConfigLock,0);
      lVar2 = SecWfpGuardPolicyConfig;
      uVar1 = SecWfpGuardPolicyConfigCount;
      SecWfpGuardPolicyConfig = 0;
      SecWfpGuardPolicyConfigCount = 0;
      FltReleasePushLockEx(&SecWfpGuardPolicyConfigLock,0);
      SecWfpFreeWfpGuardConfig(lVar2,uVar1);
      FltDeletePushLock(&SecWfpGuardPolicyConfigLock);
      SecWfpGuardInitialized = '\0';
    }
  }
  return;
}



===== SecWfpAcquireConditionValue @ 14000813c =====

void SecWfpAcquireConditionValue(int *param_1,ulonglong *param_2,ushort *param_3,ushort *param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong local_18 [2];
  
  *param_2 = 0;
  *(undefined4 *)(param_2 + 1) = 0;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_4[0] = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  if (*param_1 == 0xd) {
    if (*(longlong *)(param_1 + 2) == 0) {
      return;
    }
    uVar2 = SecWfpGetSidAsUnicodeString(*(longlong *)(param_1 + 2),(longlong)param_3);
    if ((int)uVar2 < 0) {
      return;
    }
    *param_2 = *(ulonglong *)(param_3 + 4);
    uVar1 = *param_3;
  }
  else {
    if (*param_1 != 0xe) {
      puVar4 = SecWfpGetConditionSimpleValueInfo(local_18,param_1);
      uVar3 = puVar4[1];
      *param_2 = *puVar4;
      param_2[1] = uVar3;
      return;
    }
    if (*(longlong *)(param_1 + 2) == 0) {
      return;
    }
    uVar3 = SecWfpGetSecurityDescriptorAsUnicodeString
                      (*(longlong *)(*(longlong *)(param_1 + 2) + 8),(short *)param_4);
    if ((int)uVar3 < 0) {
      return;
    }
    *param_2 = *(ulonglong *)(param_4 + 4);
    uVar1 = *param_4;
  }
  *(uint *)(param_2 + 1) = (uint)uVar1;
  return;
}



===== SecWfpAreSimpleTypesEqual @ 1400081ec =====

undefined8 SecWfpAreSimpleTypesEqual(int *param_1,longlong param_2,undefined1 *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  iVar2 = *param_1;
  if (iVar2 != *(int *)(param_2 + 8)) {
    return 0xc000000d;
  }
  if (0xff < iVar2) {
    return 0xc00000bb;
  }
  if (8 < iVar2) {
    if (iVar2 == 0xb) {
      lVar3 = **(longlong **)(param_1 + 2) - **(longlong **)(param_2 + 0x18);
      if (lVar3 == 0) {
        lVar3 = (*(longlong **)(param_1 + 2))[1] - (*(longlong **)(param_2 + 0x18))[1];
      }
      uVar4 = lVar3 == 0;
      goto LAB_14000834d;
    }
    if (iVar2 == 0xc) {
      uVar1 = **(uint **)(param_1 + 2);
      if (uVar1 != *(uint *)(param_2 + 0x14)) {
        uVar4 = 0;
        goto LAB_14000834d;
      }
      iVar2 = memcmp(*(void **)(*(uint **)(param_1 + 2) + 2),*(void **)(param_2 + 0x18),
                     (ulonglong)uVar1);
    }
    else {
      if (iVar2 == 0xd) {
        uVar4 = RtlEqualSid(*(undefined8 *)(param_1 + 2),*(undefined8 *)(param_2 + 0x18));
        goto LAB_14000834d;
      }
      if (iVar2 == 0xe) {
        return 0xc00000bb;
      }
      if (iVar2 != 0x11) {
        if (iVar2 != 0x12) {
          return 0xc00000bb;
        }
        iVar2 = **(int **)(param_1 + 2) - **(int **)(param_2 + 0x18);
        if (iVar2 == 0) {
          iVar2 = (uint)*(ushort *)(*(int **)(param_1 + 2) + 1) -
                  (uint)*(ushort *)(*(int **)(param_2 + 0x18) + 1);
        }
        uVar4 = iVar2 == 0;
        goto LAB_14000834d;
      }
      iVar2 = wcscmp(*(wchar_t **)(param_1 + 2),*(wchar_t **)(param_2 + 0x18));
    }
    uVar4 = iVar2 == 0;
    goto LAB_14000834d;
  }
  if (iVar2 == 8) {
LAB_140008286:
    uVar4 = **(longlong **)(param_1 + 2) == **(longlong **)(param_2 + 0x18);
  }
  else {
    if (iVar2 == 1) {
LAB_140008277:
      uVar4 = (char)param_1[2] == **(char **)(param_2 + 0x18);
      goto LAB_14000834d;
    }
    if (iVar2 == 2) {
LAB_140008266:
      uVar4 = (short)param_1[2] == **(short **)(param_2 + 0x18);
      goto LAB_14000834d;
    }
    if (iVar2 != 3) {
      if (iVar2 == 4) goto LAB_140008286;
      if (iVar2 == 5) goto LAB_140008277;
      if (iVar2 == 6) goto LAB_140008266;
      if (iVar2 != 7) {
        return 0xc00000bb;
      }
    }
    uVar4 = param_1[2] == **(int **)(param_2 + 0x18);
  }
LAB_14000834d:
  *param_3 = uVar4;
  return 0;
}



===== SecWfpAreValuesEqual @ 140008364 =====

ulonglong SecWfpAreValuesEqual(int *param_1,longlong param_2,undefined1 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 local_res8 [8];
  uint local_18 [2];
  undefined8 local_10;
  
  uVar2 = 0;
  local_res8[0] = 0;
  local_18[1] = 0;
  if ((*param_1 == 0xe) && (*(int *)(param_2 + 8) == 0xd)) {
    local_res8[0] =
         SecIsSidAllowedInSecurityDescriptor
                   (*(undefined8 *)(*(longlong *)(param_1 + 2) + 8),*(undefined8 *)(param_2 + 0x18))
    ;
  }
  else if ((*(int *)(param_2 + 4) == 0xb) || (*(int *)(param_2 + 4) == 0xc)) {
    if (*param_1 != 0xc) {
      return 0xc000000d;
    }
    local_18[0] = *(uint *)(param_2 + 0x14);
    local_10 = *(undefined8 *)(param_2 + 0x18);
    local_res8[0] = SecIsSuffixMatch(*(uint **)(param_1 + 2),local_18);
  }
  else {
    uVar1 = SecWfpAreSimpleTypesEqual(param_1,param_2,local_res8);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) {
      return uVar2;
    }
  }
  *param_3 = local_res8[0];
  return uVar2;
}



===== SecWfpAreValuesMatch @ 1400083fc =====

ulonglong SecWfpAreValuesMatch(longlong param_1,longlong param_2,char *param_3)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  if (*(int *)(param_2 + 4) != *(int *)(param_1 + 4)) {
    return 0xc00000bb;
  }
  uVar2 = SecWfpAreValuesEqual((int *)(param_1 + 8),param_2,local_res8);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
LAB_140008457:
    cVar3 = local_res8[0];
  }
  else {
    if (iVar1 != 10) {
      if (iVar1 == 0xb) goto LAB_140008457;
      cVar3 = '\0';
      if (iVar1 != 0xc) goto LAB_14000845b;
    }
    cVar3 = local_res8[0] == '\0';
  }
LAB_14000845b:
  *param_3 = cVar3;
  return uVar2;
}



===== SecWfpAuditFilterConditions @ 140008470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecWfpAuditFilterConditions(undefined4 *param_1,undefined2 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStackY_d8 [32];
  ulonglong local_78;
  undefined8 uStack_70;
  ushort local_68 [4];
  longlong local_60;
  ushort local_58 [4];
  longlong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (((*(int *)((longlong)param_3 + 0x1c) != 0) && (param_3[4] != 0)) &&
     (uVar4 = 0, *(int *)((longlong)param_3 + 0x1c) != 0)) {
    do {
      lVar2 = param_3[4];
      local_50 = 0;
      local_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_58[0] = 0;
      local_58[1] = 0;
      local_58[2] = 0;
      local_58[3] = 0;
      lVar1 = lVar2 + uVar4 * 0x18;
      local_68[0] = 0;
      local_68[1] = 0;
      local_68[2] = 0;
      local_68[3] = 0;
      SecWfpAcquireConditionValue((int *)(lVar1 + 8),&local_78,local_58,local_68);
      SecAuditWfpFilterCondition
                (&Event_WfpFilterCondition,*param_1,param_1[1],param_2,(char)*param_3,(char)uVar4,
                 (char)*(undefined4 *)((longlong)param_3 + 0x1c),
                 (char)*(undefined2 *)(lVar2 + uVar4 * 0x18),
                 (char)*(undefined4 *)(lVar2 + 4 + uVar4 * 0x18),(char)*(undefined4 *)(lVar1 + 8),
                 local_78,(uint)uStack_70);
      if (local_50 != 0) {
        RtlFreeUnicodeString(local_58);
      }
      if (local_60 != 0) {
        ExFreePoolWithTag(local_60,0);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)((longlong)param_3 + 0x1c));
  }
  return;
}



===== SecWfpAuditMatchedCondition @ 1400085cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SecWfpAuditMatchedCondition
               (undefined4 *param_1,undefined2 param_2,undefined8 *param_3,undefined2 *param_4,
               undefined1 param_5)

{
  undefined1 uVar1;
  undefined1 auStackY_108 [32];
  ulonglong local_88;
  undefined8 uStack_80;
  ushort local_78 [4];
  longlong local_70;
  ushort local_68 [4];
  longlong local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_108;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_70 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_60 = 0;
  uVar1 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (*(char *)((longlong)param_1 + 9) == '\x01') {
    uVar1 = 0;
    if (*(int *)(param_3 + 1) == 4) {
      if ((undefined8 *)param_3[2] != (undefined8 *)0x0) {
        uVar1 = (char)*(undefined8 *)param_3[2];
      }
    }
    else if (*(int *)(param_3 + 1) == 1) {
      uVar1 = *(undefined1 *)(param_3 + 2);
    }
    SecWfpAcquireConditionValue((int *)(param_4 + 4),&local_88,local_78,local_68);
  }
  SecAuditWfpGuardBlock
            (&Event_WfpWfpGuardBlock,*param_1,param_1[1],param_2,(char)*(undefined4 *)(param_3 + 5),
             (char)*param_4,(char)*(undefined4 *)(param_4 + 2),(char)*(undefined4 *)(param_4 + 4),
             (char)param_1[9],uVar1,(char)*(undefined2 *)(param_3 + 3),(char)*param_3,local_88,
             (uint)uStack_80,param_5);
  if (local_70 != 0) {
    RtlFreeUnicodeString(local_78);
  }
  if (local_60 != 0) {
    ExFreePoolWithTag(local_60,0);
  }
  return;
}



===== SecWfpEvaluateConditionComparison @ 14000871c =====

int SecWfpEvaluateConditionComparison(longlong param_1,longlong param_2,char *param_3)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  uint local_18 [2];
  undefined8 local_10;
  
  iVar5 = *(int *)(param_2 + 0xc);
  cVar1 = '\0';
  iVar4 = 0;
  if (6 < iVar5) {
    if (iVar5 == 7) {
      return -0x3ffffffe;
    }
    if (iVar5 == 8) {
      if ((*(int *)(param_1 + 8) == 0xc) && (*(int *)(param_2 + 8) == 0xc)) {
        local_18[0] = *(uint *)(param_2 + 0x14);
        local_10 = *(undefined8 *)(param_2 + 0x18);
        local_18[1] = 0;
        cVar1 = SecIsPrefixMatch(local_18,*(uint **)(param_1 + 0x10));
        goto LAB_140008823;
      }
    }
    else if (iVar5 == 9) {
      if ((*(int *)(param_1 + 8) == 0xc) && (*(int *)(param_2 + 8) == 0xc)) {
        local_18[0] = *(uint *)(param_2 + 0x14);
        local_10 = *(undefined8 *)(param_2 + 0x18);
        local_18[1] = 0;
        cVar1 = SecIsSuffixMatch(local_18,*(uint **)(param_1 + 0x10));
        goto LAB_140008823;
      }
    }
    else {
      if (iVar5 != 10) goto LAB_1400087f5;
      if ((*(int *)(param_1 + 8) == 0xe) && (*(int *)(param_2 + 8) == 0xd)) {
        cVar1 = SecIsSidAllowedInSecurityDescriptor
                          (*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8),
                           *(undefined8 *)(param_2 + 0x18));
        goto LAB_140008823;
      }
    }
    iVar4 = -0x3ffffff3;
LAB_140008823:
    *param_3 = cVar1;
    return iVar4;
  }
  if (iVar5 == 6) {
    if ((*(int *)(param_1 + 8) == 0x100) && (*(int *)(param_2 + 8) == 3)) {
      uVar3 = SecWfpIsIpV4MaskMatch(param_1 + 8,param_2,param_3);
      return (int)uVar3;
    }
    iVar5 = -0x3ffffff3;
    goto LAB_1400087d1;
  }
  if (iVar5 == 1) {
    *param_3 = '\x01';
    return 0;
  }
  if (iVar5 == 2) {
    uVar3 = SecWfpAreSimpleTypesEqual((int *)(param_1 + 8),param_2,param_3);
    return (int)uVar3;
  }
  if (iVar5 == 3) {
    uVar3 = SecWfpAreSimpleTypesEqual((int *)(param_1 + 8),param_2,param_3);
    iVar5 = (int)uVar3;
LAB_140008783:
    if (iVar5 < 0) {
      return iVar5;
    }
    *param_3 = *param_3 == '\0';
    return iVar5;
  }
  if (iVar5 == 4) {
    uVar2 = SecWfpIsValueInRange((int *)(param_1 + 8),param_2,param_3);
    return (int)uVar2;
  }
  if (iVar5 == 5) {
    uVar2 = SecWfpIsValueInRange((int *)(param_1 + 8),param_2,param_3);
    iVar5 = (int)uVar2;
    goto LAB_140008783;
  }
LAB_1400087f5:
  iVar5 = -0x3fffff45;
LAB_1400087d1:
  *param_3 = '\0';
  return iVar5;
}



===== SecWfpFreeWfpGuardConfig @ 1400088a0 =====

void SecWfpFreeWfpGuardConfig(longlong param_1,uint param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    plVar1 = (longlong *)(param_1 + 0x30);
    uVar2 = (ulonglong)param_2;
    do {
      if (*plVar1 != 0) {
        ExFreePoolWithTag(*plVar1,0x67477753);
        *plVar1 = 0;
      }
      plVar1 = plVar1 + 7;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    ExFreePoolWithTag(param_1,0x67477753);
  }
  return;
}



===== SecWfpGetConditionSimpleValueInfo @ 140008910 =====

ulonglong * SecWfpGetConditionSimpleValueInfo(ulonglong *param_1,int *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  
  iVar1 = *param_2;
  uVar5 = 0;
  param_1[1] = 0;
  *param_1 = 0;
  if (iVar1 < 0x13) {
    if (iVar1 == 0x12) {
      *param_1 = *(ulonglong *)(param_2 + 2);
      *(undefined4 *)(param_1 + 1) = 6;
      return param_1;
    }
    if (iVar1 < 8) {
      if (iVar1 == 7) {
LAB_1400089f4:
        *(undefined4 *)(param_1 + 1) = 4;
        *param_1 = (ulonglong)(param_2 + 2);
        return param_1;
      }
      if (iVar1 == 1) {
LAB_140008998:
        *(undefined4 *)(param_1 + 1) = 1;
        *param_1 = (ulonglong)(param_2 + 2);
        return param_1;
      }
      if (iVar1 == 2) {
LAB_140008967:
        *(undefined4 *)(param_1 + 1) = 2;
        *param_1 = (ulonglong)(param_2 + 2);
        return param_1;
      }
      if (iVar1 == 3) goto LAB_1400089f4;
      if (iVar1 != 4) {
        if (iVar1 == 5) goto LAB_140008998;
        if (iVar1 != 6) {
          return param_1;
        }
        goto LAB_140008967;
      }
    }
    else if (iVar1 != 8) {
      if (iVar1 == 9) goto LAB_1400089f4;
      if (iVar1 != 10) {
        if (iVar1 == 0xb) {
          *param_1 = *(ulonglong *)(param_2 + 2);
          *(undefined4 *)(param_1 + 1) = 0x10;
          return param_1;
        }
        if (iVar1 != 0xc) {
          return param_1;
        }
        puVar3 = *(undefined4 **)(param_2 + 2);
        if (puVar3 != (undefined4 *)0x0) {
          uVar5 = *puVar3;
          *param_1 = *(ulonglong *)(puVar3 + 2);
        }
        *(undefined4 *)(param_1 + 1) = uVar5;
        return param_1;
      }
    }
    uVar2 = *(ulonglong *)(param_2 + 2);
    uVar6 = -(ulonglong)(uVar2 != 0) & uVar2;
    uVar4 = -(uint)(uVar2 != 0) & 8;
  }
  else {
    if ((iVar1 != 0x100) && (iVar1 != 0x101)) {
      return param_1;
    }
    uVar2 = *(ulonglong *)(param_2 + 2);
    uVar6 = -(ulonglong)(uVar2 != 0) & uVar2;
    uVar4 = -(uint)(uVar2 != 0) & 4;
  }
  *param_1 = uVar6;
  *(uint *)(param_1 + 1) = uVar4;
  return param_1;
}



===== SecWfpIsBlobGreater @ 140008a4c =====

bool SecWfpIsBlobGreater(uint *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar1 = *param_1;
  uVar2 = *(uint *)(param_2 + 0x14);
  if (uVar1 == uVar2) {
    iVar4 = memcmp(*(void **)(param_1 + 2),*(void **)(param_2 + 0x18),(ulonglong)uVar1);
    bVar5 = 0 < iVar4;
  }
  else {
    uVar3 = uVar1;
    if (uVar2 <= uVar1) {
      uVar3 = uVar2;
    }
    iVar4 = memcmp(*(void **)(param_1 + 2),*(void **)(param_2 + 0x18),(ulonglong)uVar3);
    if (iVar4 < 1) {
      if (iVar4 == 0) {
        bVar5 = uVar1 < uVar2;
      }
      else {
        bVar5 = false;
      }
    }
    else {
      bVar5 = true;
    }
  }
  return bVar5;
}



===== SecWfpIsIpV4MaskMatch @ 140008aa4 =====

undefined8 SecWfpIsIpV4MaskMatch(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  
  if (((*(int *)(param_2 + 0xc) == 0) && (*(char *)(param_2 + 0x10) == '\0')) ||
     (*(int *)(param_2 + 8) != 3)) {
    return 0xc00000bb;
  }
  uVar1 = (*(uint **)(param_1 + 8))[1];
  *(bool *)param_3 = (**(uint **)(param_1 + 8) & uVar1) == (**(uint **)(param_2 + 0x18) & uVar1);
  return 0;
}



===== SecWfpIsValueInRange @ 140008ae4 =====

ulonglong SecWfpIsValueInRange(int *param_1,longlong param_2,undefined1 *param_3)

{
  int *piVar1;
  ulonglong uVar2;
  bool bVar3;
  char local_res10 [16];
  char local_res20 [8];
  
  bVar3 = false;
  local_res10[0] = '\0';
  local_res20[0] = '\0';
  if ((*(char *)(param_2 + 0x10) == '\0') || (*param_1 != 0x102)) {
    return 0xc00000bb;
  }
  piVar1 = *(int **)(param_1 + 2);
  if (*piVar1 != *(int *)(param_2 + 8)) {
    return 0xc00000bb;
  }
  if (piVar1[4] != *(int *)(param_2 + 8)) {
    return 0xc00000bb;
  }
  uVar2 = SecWfpAreValuesEqual(piVar1,param_2,local_res10);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res10[0] == '\0') {
    uVar2 = SecWfpAreValuesEqual((int *)(*(longlong *)(param_1 + 2) + 0x10),param_2,local_res10);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (local_res10[0] == '\0') {
      piVar1 = *(int **)(param_1 + 2);
      uVar2 = SecWfpIsValueGreater(piVar1,param_2,local_res20);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      if (local_res20[0] == '\0') {
        uVar2 = SecWfpIsValueGreater(piVar1 + 4,param_2,local_res20);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        bVar3 = local_res20[0] != '\0';
      }
      goto LAB_140008ba7;
    }
  }
  bVar3 = true;
LAB_140008ba7:
  *param_3 = bVar3;
  return uVar2;
}



===== SecWfpShouldEnforcePolicyOnFilterCondition @ 140008bc0 =====

bool SecWfpShouldEnforcePolicyOnFilterCondition(short param_1,undefined8 *param_2,short *param_3)

{
  short *psVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  bool bVar12;
  char local_res20 [8];
  
  puVar11 = (undefined4 *)0x0;
  bVar12 = false;
  uVar8 = 0;
  local_res20[0] = '\0';
  if (SecWfpGuardPolicyConfigCount != 0) {
    do {
      puVar9 = (undefined4 *)(uVar8 * 0x38 + SecWfpGuardPolicyConfig);
      puVar10 = puVar11;
      if ((*(short *)(puVar9 + 3) == -1) || (*(short *)(puVar9 + 3) == param_1)) {
        psVar1 = (short *)(puVar9 + 6);
        if (((*psVar1 == -1) || (*psVar1 == *param_3)) && (puVar9[4] == *(int *)(param_2 + 5))) {
          if (puVar9[9] == 0) {
            piVar2 = (int *)(param_3 + 4);
            iVar4 = *piVar2;
            if (iVar4 == 0x102) {
              uVar5 = SecWfpIsValueInRange(piVar2,(longlong)psVar1,local_res20);
              iVar4 = (int)uVar5;
            }
            else if (iVar4 == 0x100) {
              uVar6 = SecWfpIsIpV4MaskMatch((longlong)piVar2,(longlong)psVar1,local_res20);
              iVar4 = (int)uVar6;
            }
            else {
              if (iVar4 == 0x101) goto LAB_140008cdf;
              uVar5 = SecWfpAreValuesMatch((longlong)param_3,(longlong)psVar1,local_res20);
              iVar4 = (int)uVar5;
            }
          }
          else {
            iVar4 = SecWfpEvaluateConditionComparison
                              ((longlong)param_3,(longlong)psVar1,local_res20);
          }
          if ((-1 < iVar4) && (local_res20[0] != '\0')) {
            cVar3 = *(char *)(puVar9 + 2);
            bVar12 = cVar3 == '\0';
            SecWfpAuditMatchedCondition(puVar9,param_1,param_2,param_3,bVar12);
            puVar10 = puVar9;
            if (puVar11 != (undefined4 *)0x0) {
              puVar10 = puVar11;
            }
            if (cVar3 == '\0') break;
          }
        }
      }
LAB_140008cdf:
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
      puVar11 = puVar10;
    } while (uVar7 < SecWfpGuardPolicyConfigCount);
    if ((puVar10 != (undefined4 *)0x0) && (*(char *)((longlong)puVar10 + 10) == '\x01')) {
      SecWfpAuditFilterConditions(puVar10,param_1,param_2);
    }
  }
  return bVar12;
}



===== SecWfpShouldForbidFilterAssignment @ 140008d28 =====

ulonglong SecWfpShouldForbidFilterAssignment(short param_1,undefined8 *param_2)

{
  bool bVar1;
  ulonglong in_RAX;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(int *)((longlong)param_2 + 0x1c) != 0) {
    do {
      bVar1 = SecWfpShouldEnforcePolicyOnFilterCondition
                        (param_1,param_2,(short *)(param_2[4] + uVar3 * 0x18));
      in_RAX = CONCAT71(extraout_var,bVar1);
      if (bVar1) {
        return CONCAT71(extraout_var,1);
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)((longlong)param_2 + 0x1c));
  }
  return in_RAX & 0xffffffffffffff00;
}



===== SecWfpShouldForbidFiltersAssignment @ 140008d80 =====

undefined8
SecWfpShouldForbidFiltersAssignment
          (int param_1,short param_2,undefined8 param_3,uint param_4,undefined8 *param_5)

{
  ulonglong uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_1 == 1) {
    FltAcquirePushLockSharedEx(&SecWfpGuardPolicyConfigLock,0);
    if (((SecWfpGuardPolicyConfig != 0) && (SecWfpGuardPolicyConfigCount != 0)) &&
       (uVar3 = 0, param_4 != 0)) {
      do {
        uVar1 = SecWfpShouldForbidFilterAssignment(param_2,(undefined8 *)*param_5);
        if ((char)uVar1 != '\0') {
          uVar2 = 0xc0000022;
          break;
        }
        uVar3 = uVar3 + 1;
        param_5 = param_5 + 1;
      } while (uVar3 < param_4);
    }
    FltReleasePushLockEx(&SecWfpGuardPolicyConfigLock,0);
  }
  return uVar2;
}



===== KclCheckCurrentTokenMembership @ 140008e20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KclCheckCurrentTokenMembership(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined8 local_100;
  undefined *local_f8;
  undefined1 local_f0;
  int *local_e8;
  int *local_e0;
  int local_d8;
  int local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [96];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  local_d4 = 0;
  local_d8 = -0x3fffffde;
  memset(local_88,0,0x54);
  local_d0 = 0;
  uStack_c8 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  *param_2 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  SeCaptureSubjectContext(&local_a8);
  iVar1 = RtlCreateSecurityDescriptor(&local_d0,1);
  if (-1 < iVar1) {
    iVar1 = RtlSetOwnerSecurityDescriptor(&local_d0,param_1,0);
    if (-1 < iVar1) {
      iVar1 = RtlSetGroupSecurityDescriptor(&local_d0,param_1,0);
      if (-1 < iVar1) {
        iVar1 = RtlCreateAcl(local_88,0x54,2);
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce(local_88,2,1,param_1);
          if (-1 < iVar1) {
            iVar1 = RtlSetDaclSecurityDescriptor(&local_d0,1,local_88,0);
            if (-1 < iVar1) {
              local_f0 = ExGetPreviousMode();
              local_e0 = &local_d8;
              local_e8 = &local_d4;
              local_f8 = &RtlCheckTokenMembershipGenericMapping;
              local_100 = 0;
              local_108 = 0;
              SeAccessCheck(&local_d0,&local_a8,0,1);
              iVar1 = 0;
              if (local_d8 == 0) {
                if (local_d4 == 1) {
                  *param_2 = 1;
                  goto LAB_140008fe4;
                }
              }
              else if (local_d8 == -0x3fffffde) goto LAB_140008fe4;
              iVar1 = local_d8;
            }
          }
        }
      }
    }
  }
LAB_140008fe4:
  SeReleaseSubjectContext(&local_a8);
  return iVar1;
}



===== KclInitializeSenseServiceSid @ 140009018 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KclInitializeSenseServiceSid(undefined4 param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  undefined4 *puVar3;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_24 = 0x500;
  uVar1 = RtlLengthRequiredSid(6);
  _Dst = (void *)ExAllocatePoolWithTag(0x401,uVar1,param_1);
  if ((ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
    memset(_Dst,0,(ulonglong)uVar1);
  }
  else if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  iVar2 = RtlInitializeSid(_Dst,&local_28,6);
  if (iVar2 < 0) {
    ExFreePoolWithTag(_Dst,param_1);
  }
  else {
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,0);
    *puVar3 = 0x50;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,1);
    *puVar3 = 0x5ad48a85;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,2);
    *puVar3 = 0x18845fe2;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,3);
    *puVar3 = 0xa6c74771;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,4);
    *puVar3 = 0xb8b1dbc0;
    puVar3 = (undefined4 *)RtlSubAuthoritySid(_Dst,5);
    *puVar3 = 0x9b3616fc;
    *param_2 = _Dst;
  }
  return iVar2;
}



===== KclSetSymbolicLinkObjectSecurity @ 1400091a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KclSetSymbolicLinkObjectSecurity(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStack_78 [32];
  longlong local_58 [4];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 0;
  local_58[1] = 0x30;
  local_38 = 0x240;
  local_58[2] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_58[3] = param_1;
  iVar1 = ZwOpenSymbolicLinkObject(local_58,0x1f0000,local_58 + 1);
  if (-1 < iVar1) {
    iVar1 = ZwSetSecurityObject(local_58[0],param_2,param_3);
  }
  if (local_58[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== KclSetWmiObjectSecurity @ 140009260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KclSetWmiObjectSecurity(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined1 local_50;
  longlong *local_48;
  longlong local_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_30 = 0;
  local_38 = 0;
  iVar1 = IoWMIOpenBlock(param_1,0x40000,&local_30);
  if (-1 < iVar1) {
    local_48 = &local_38;
    local_50 = 0;
    local_58 = 0;
    ObOpenObjectByPointer(local_30,0x200,0,0x40000);
    iVar1 = ZwSetSecurityObject(local_38,param_2,param_3);
  }
  if (local_38 != 0) {
    ZwClose();
    local_38 = 0;
  }
  if (local_30 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== KclIsWindows7 @ 140009348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool KclIsWindows7(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12c [276];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_12c,0,0x110);
  local_138 = 0x11c;
  local_134 = 6;
  local_130 = 1;
  uVar2 = VerSetConditionMask(0,2,1);
  uVar2 = VerSetConditionMask(uVar2,1,1);
  iVar1 = RtlVerifyVersionInfo(&local_138,3,uVar2);
  return -1 < iVar1;
}



===== KclIsWindows8 @ 1400093f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool KclIsWindows8(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12c [276];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_12c,0,0x110);
  local_138 = 0x11c;
  local_130 = 2;
  local_134 = 6;
  uVar2 = VerSetConditionMask(0,2,1);
  uVar2 = VerSetConditionMask(uVar2,1,1);
  iVar1 = RtlVerifyVersionInfo(&local_138,3,uVar2);
  return -1 < iVar1;
}



===== KclIsWindowsBlueOrLater @ 140009494 =====

void KclIsWindowsBlueOrLater(void)

{
  KclVerifyWindowsVersion(6,3,0);
  return;
}



===== KclVerifyWindowsVersion @ 1400094a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool KclVerifyWindowsVersion(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  int local_14c;
  undefined4 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  memset(&local_158,0,0x11c);
  uVar3 = 3;
  uVar2 = VerSetConditionMask(0,2,3);
  uVar2 = VerSetConditionMask(uVar2,1,3);
  if (param_3 != 0) {
    uVar3 = 7;
    uVar2 = VerSetConditionMask(uVar2,4,3);
  }
  local_158 = 0x11c;
  local_44 = 0;
  local_154 = param_1;
  local_150 = param_2;
  local_14c = param_3;
  iVar1 = RtlVerifyVersionInfo(&local_158,uVar3,uVar2);
  return -1 < iVar1;
}



===== KclGetProtectionLevel @ 140009584 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 KclGetProtectionLevel(undefined8 param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined4 *local_28;
  undefined1 local_18 [4];
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_18[0] = 0;
  local_14 = 0;
  bVar1 = KclIsWindows7();
  if ((!bVar1) && (bVar1 = KclIsWindows8(), !bVar1)) {
    local_28 = &local_14;
    iVar2 = ZwQueryInformationProcess(param_1,0x3d,local_18);
    if (-1 < iVar2) {
      return local_18[0];
    }
  }
  return 0;
}



===== KclIsProcessLocalSystem @ 1400095fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 KclIsProcessLocalSystem(void)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_38 [32];
  undefined8 *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = (undefined8 *)0x0;
  uVar1 = 0;
  lVar3 = PsReferencePrimaryToken();
  iVar2 = SeQueryInformationToken(lVar3,1,&local_18);
  if (-1 < iVar2) {
    uVar1 = RtlEqualSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108),*local_18);
  }
  if (local_18 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_18,0);
    local_18 = (undefined8 *)0x0;
  }
  if (lVar3 != 0) {
    PsDereferencePrimaryToken(lVar3);
  }
  return uVar1;
}



===== KclIsProcessWindowsProtectedLight @ 1400096c8 =====

bool KclIsProcessWindowsProtectedLight(undefined8 param_1)

{
  char cVar1;
  
  cVar1 = KclGetProtectionLevel(param_1);
  return cVar1 == 'Q';
}



===== KclGetSystemModuleBase @ 1400096dc =====

undefined8 KclGetSystemModuleBase(undefined8 *param_1,uint *param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = param_2 + 2;
  uVar2 = 0;
  if (*param_2 != 0) {
    do {
      iVar1 = _stricmp((char *)(puVar3 + 10),param_3);
      if (iVar1 == 0) {
        *param_1 = *(undefined8 *)(puVar3 + 4);
        return 0;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x4a;
    } while (uVar2 < *param_2);
  }
  return 0xc0000225;
}



===== KclQueryModuleList @ 140009758 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KclQueryModuleList(undefined8 *param_1)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  undefined1 auStack_48 [32];
  uint local_28 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  _Dst = (void *)0x0;
  local_28[0] = 0;
  uVar2 = 0;
LAB_14000978e:
  do {
    iVar1 = ZwQuerySystemInformation(0xb,_Dst,uVar2,local_28);
    if (iVar1 < 0) {
      if (_Dst != (void *)0x0) {
        ExFreePoolWithTag(_Dst,0x6d6c6b53);
      }
      uVar2 = local_28[0];
      if (iVar1 != -0x3ffffffc) {
        return iVar1;
      }
      _Dst = (void *)ExAllocatePoolWithTag(0x401,local_28[0],0x6d6c6b53);
      if (ExPoolZeroingNativelySupported == '\0') {
        if (_Dst == (void *)0x0) {
          return -0x3fffff66;
        }
        memset(_Dst,0,(ulonglong)uVar2);
        goto LAB_14000978e;
      }
      if (_Dst == (void *)0x0) {
        return -0x3fffff66;
      }
    }
    if (iVar1 != -0x3ffffffc) {
      if (-1 < iVar1) {
        *param_1 = _Dst;
      }
      return iVar1;
    }
  } while( true );
}



===== KclQuerySystemModuleBase @ 140009854 =====

int KclQuerySystemModuleBase(undefined8 *param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (uint *)0x0;
  iVar1 = KclQueryModuleList(&local_res18);
  if (-1 < iVar1) {
    uVar2 = KclGetSystemModuleBase(&local_res20,local_res18,param_2);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      *param_1 = local_res20;
    }
  }
  if (local_res18 != (uint *)0x0) {
    ExFreePoolWithTag(local_res18,0x6d6c6b53);
  }
  return iVar1;
}



===== SecInitializeAuditing @ 14000a000 =====

int SecInitializeAuditing(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = EtwRegister(&Microsoft_Windows_SecWfp_Provider,0,0,&DAT_140005328);
  if (-1 < iVar1) {
    iVar1 = KclSetWmiObjectSecurity(&Microsoft_Windows_SecWfp_Provider,0x84,&DAT_140003630);
    if (-1 < iVar1) {
      uVar2 = 0;
      if (DAT_140005326 == '\x01') {
        uVar2 = 0x200;
      }
      ExInitializeNPagedLookasideList(&DAT_140005340,0,0,uVar2,0xf0,0x76457753,0);
      DAT_140005330 = 1;
    }
  }
  return iVar1;
}



===== SecInitializeWfpCallouts @ 14000a0a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SecInitializeWfpCallouts(void)

{
  int iVar1;
  
  iVar1 = SecRegisterWfpCallouts();
  if (-1 < iVar1) {
    DAT_1400053e8 = FwpsNetBufferListGetTagForContext0();
    iVar1 = FwpmBfeStateSubscribeChanges0(DAT_140005308,SecBfeStateChangeCallback,0,&DAT_140005318);
    if (-1 < iVar1) {
      _DAT_140005320 = FwpmBfeStateGet0();
      if (_DAT_140005320 == 3) {
        iVar1 = SecAddWfpCallouts();
      }
    }
  }
  return iVar1;
}



===== DriverEntry @ 14000a108 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DriverEntry(longlong param_1)

{
  int iVar1;
  code *pcVar2;
  undefined1 auStack_188 [48];
  undefined8 local_158;
  wchar_t *local_150;
  char local_148 [16];
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  if (*(int *)InitSafeBootMode_exref == 0) {
    local_148[0] = '\0';
    local_150 = L"NtQuerySystemInformation";
    local_158 = 0x320030;
    memset(local_134,0,0x110);
    local_138 = 0x114;
    RtlGetVersion(&local_138);
    pcVar2 = (code *)MmGetSystemRoutineAddress(&local_158);
    if (((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(0xe3,local_148,1), -1 < iVar1)) &&
       (local_148[0] != '\0')) {
      ExPoolZeroingNativelySupported = 1;
    }
    iVar1 = SecInitializeGlobalData(param_1);
    if (((-1 < iVar1) && (iVar1 = SecCreateDevice(param_1), -1 < iVar1)) &&
       ((iVar1 = SecInitializeAuditing(), -1 < iVar1 &&
        (iVar1 = SecInitializeWfpCallouts(), -1 < iVar1)))) {
      SecSealDriver(param_1);
      return iVar1;
    }
  }
  else {
    iVar1 = -0x3ffffca1;
  }
  DriverUnload();
  return iVar1;
}



===== entry @ 14000a250 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000a27c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140005280) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


