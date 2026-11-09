
===== RdpBusDeferIrpCompletion @ 140001010 =====

/* long __cdecl RdpBusDeferIrpCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void
   * __ptr64) */

long __cdecl RdpBusDeferIrpCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  KeSetEvent(param_3,1);
  return -0x3fffffea;
}



===== RDPBUS_PrepareForReparse @ 140001040 =====

/* long __cdecl RDPBUS_PrepareForReparse(struct _FILE_OBJECT * __ptr64) */

long __cdecl RDPBUS_PrepareForReparse(_FILE_OBJECT *param_1)

{
  int iVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  ushort *_Src;
  longlong lVar5;
  ushort *_Size;
  _FILE_OBJECT *p_Var6;
  longlong lVar7;
  bool bVar8;
  uint local_res8 [2];
  longlong local_res10;
  _FILE_OBJECT *local_res18;
  ushort local_58;
  short sStack_56;
  undefined4 uStack_54;
  short *psStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar2 = 0;
  p_Var6 = param_1 + 0x58;
  *(undefined8 *)(param_1 + 0x18) = 0;
  local_48 = 0;
  uStack_40 = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  uStack_54 = *(undefined4 *)(param_1 + 0x5c);
  psStack_50 = *(short **)(param_1 + 0x60);
  local_res10 = 0;
  local_res8[0] = 0;
  local_58 = (ushort)*(undefined4 *)p_Var6;
  sStack_56 = (short)((uint)*(undefined4 *)p_Var6 >> 0x10);
  if (((1 < local_58) && (1 < (ushort)((ulonglong)*(undefined8 *)p_Var6 >> 0x10))) &&
     (*psStack_50 == 0x5c)) {
    psStack_50 = psStack_50 + 1;
    local_58 = local_58 - 2;
    sStack_56 = sStack_56 + -2;
  }
  _Size = &local_58;
  _Src = (ushort *)&DAT_140004150;
  local_res18 = p_Var6;
  iVar1 = IoRegisterDeviceInterface(RDPDYN_PDO);
  if (iVar1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    _Size = (ushort *)&local_res10;
    _Src = (ushort *)0xf003f;
    iVar1 = IoOpenDeviceInterfaceRegistryKey(&local_48);
    RtlFreeUnicodeString(&local_48);
    if (iVar1 != 0) goto LAB_1400011b8;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    RtlInitUnicodeString(&local_58,L"Client Device Name");
    _Src = &local_58;
    _Size = (ushort *)0x2;
    iVar1 = ZwQueryValueKey(local_res10);
  }
  else {
LAB_1400011b8:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Size = (ushort *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
      _Src = (ushort *)0xe;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar1);
    }
    local_res10 = 0;
  }
  if (iVar1 == -0x3fffffdd) {
    _Src = (ushort *)(ulonglong)local_res8[0];
    _Size = (ushort *)0x42706472;
    lVar2 = ExAllocatePool2(0x40);
    if (lVar2 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        _Src = (ushort *)0xf;
        _Size = (ushort *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      iVar1 = -0x3fffff66;
      goto LAB_14000124c;
    }
LAB_1400012ec:
    _Src = &local_58;
    _Size = (ushort *)0x2;
    iVar1 = ZwQueryValueKey(local_res10,_Src,2,lVar2,local_res8[0],local_res8);
    if (iVar1 != 0) goto LAB_14000124c;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (*(short *)(lVar2 + 0xc + lVar7 * 2) != 0);
    lVar7 = lVar7 * 2;
    bVar8 = *(short *)(lVar2 + 0xc) == 0x5c;
    lVar5 = lVar7 + 0x1a;
    if (!bVar8) {
      lVar5 = lVar7 + 0x1c;
    }
    _Src = (ushort *)(lVar5 + 2);
    _Size = (ushort *)0x42706472;
    pwVar3 = (wchar_t *)ExAllocatePool2(0x40);
    if (pwVar3 == (wchar_t *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        _Src = (ushort *)0x11;
        _Size = (ushort *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      iVar1 = -0x3fffff66;
      p_Var6 = local_res18;
      goto LAB_14000124c;
    }
    builtin_wcsncpy(pwVar3,L"\\Device\\RdpDr",0xd);
    if (bVar8) {
      lVar4 = 0x1a;
    }
    else {
      pwVar3[0xd] = L'\\';
      lVar4 = 0x1c;
    }
    _Size = (ushort *)(lVar7 + 2);
    _Src = (ushort *)(lVar2 + 0xc);
    memmove((void *)((longlong)pwVar3 + lVar4),_Src,(size_t)_Size);
    ExFreePool(*(undefined8 *)(param_1 + 0x60));
    p_Var6 = param_1 + 0x58;
    *(short *)(param_1 + 0x5a) = (short)lVar5;
    *(short *)p_Var6 = (short)lVar5;
    iVar1 = 0x104;
    *(wchar_t **)(param_1 + 0x60) = pwVar3;
  }
  else {
    if (iVar1 == 0) goto LAB_1400012ec;
LAB_14000124c:
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140001294;
    if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
      _Size = (ushort *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
      _Src = (ushort *)0x12;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar1);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),_Src,_Size,(wchar_t *)p_Var6);
  }
LAB_140001294:
  if (local_res10 != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ExFreePool(lVar2);
  }
  return iVar1;
}



===== RdpBusDispatch @ 140001450 =====

/* long __cdecl RdpBusDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl RdpBusDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined2 uVar8;
  byte *pbVar9;
  byte local_res8 [8];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  pbVar1 = *(byte **)(param_2 + 0xb8);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,(uint)*pbVar1);
  }
  if (*(undefined8 **)(param_1 + 0x40) == (undefined8 *)0x0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
    return -0x3fffffff;
  }
  uVar2 = **(undefined8 **)(param_1 + 0x40);
  switch(*pbVar1) {
  case 0:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    if (*(longlong *)(*(longlong *)(pbVar1 + 0x30) + 0x60) == 0) {
      lVar7 = 0;
    }
    else {
      pbVar9 = local_res8;
      local_res8[0] = 0;
      iVar5 = IsCallerAllowedAccess((longlong)param_2,(char *)pbVar1,pbVar9);
      if ((iVar5 < 0) || (local_res8[0] == 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)local_res8[0],pbVar9,iVar5
                    ,local_res8[0]);
        }
        lVar7 = -0x3fffffde;
      }
      else {
        lVar7 = RDPBUS_PrepareForReparse(*(_FILE_OBJECT **)(pbVar1 + 0x30));
      }
    }
    *(long *)(param_2 + 0x30) = lVar7;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    lVar7 = *(long *)(param_2 + 0x30);
    break;
  default:
    goto switchD_1400014f6_caseD_1;
  case 2:
  case 0x12:
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    lVar7 = 0;
    break;
  case 3:
  case 4:
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    lVar7 = -0x3fffff45;
    break;
  case 0xe:
    if ((((param_2[0x40] == (_IRP)0x0) &&
         (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x220804)) &&
        (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x19)) &&
       (puVar3 = *(undefined8 **)(param_2 + 0x18), puVar3 != (undefined8 *)0x0)) {
      uVar2 = *puVar3;
      if (RDPDYN_PDO == (_DEVICE_OBJECT *)0x0) {
        uVar6 = 0xc0000001;
      }
      else {
        local_38 = 0;
        uStack_30 = 0;
        RtlInitUnicodeString(&local_38,puVar3[1]);
        uVar6 = IoRegisterDeviceInterface(RDPDYN_PDO,&DAT_140004150,&local_38,uVar2);
      }
      *(undefined4 *)(puVar3 + 2) = uVar6;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      lVar7 = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x30) = 0xc00000ef;
      IofCompleteRequest(param_2,0);
      lVar7 = -0x3fffff11;
    }
    break;
  case 0x16:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    if (pbVar1[1] == 2) {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    PoStartNextPowerIrp(param_2);
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    lVar7 = PoCallDriver(uVar2,param_2);
    break;
  case 0x1b:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
    }
    switch(pbVar1[1]) {
    case 0:
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      CleanUpExistingPorts();
      KeInitializeEvent(&local_38,0,0);
      puVar3 = *(undefined8 **)(param_2 + 0xb8);
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
      *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
      *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar4 + -0x10) = RdpBusDeferIrpCompletion;
      *(undefined8 **)(lVar4 + -8) = &local_38;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      iVar5 = IofCallDriver(uVar2,param_2);
      if (iVar5 == 0x103) {
        KeWaitForSingleObject(&local_38,5,0,0,0);
        iVar5 = *(int *)(param_2 + 0x30);
      }
      *(int *)(param_2 + 0x30) = iVar5;
      IofCompleteRequest(param_2,0);
      return iVar5;
    case 1:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      goto LAB_140001a8a;
    case 2:
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      *(undefined4 *)(param_2 + 0x30) = 0;
      lVar7 = IofCallDriver(uVar2,param_2);
      IoDetachDevice(uVar2);
      IoDeleteDevice(param_1);
      return lVar7;
    case 3:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x29;
LAB_1400019d2:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      goto LAB_1400019e2;
    case 4:
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140001a8a;
      uVar8 = 0x1c;
      goto LAB_140001a4b;
    case 5:
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140001a8a;
      uVar8 = 0x26;
LAB_140001a4b:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
              &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
LAB_140001a8a:
      *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
      IofCompleteRequest(param_2,0);
      return -0x3fffffff;
    case 6:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x28;
        goto LAB_1400019d2;
      }
LAB_1400019e2:
      *(undefined4 *)(param_2 + 0x30) = 0;
      break;
    case 7:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      iVar5 = *(int *)(pbVar1 + 8);
      if (iVar5 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x21;
          goto LAB_1400018da;
        }
      }
      else {
        if (iVar5 != 1) {
          if (iVar5 == 2) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x22;
              goto LAB_1400019d2;
            }
          }
          else {
            if (iVar5 != 3) {
              if (iVar5 == 4) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar8 = 0x24;
                  goto LAB_1400018da;
                }
              }
              else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar8 = 0x25;
                goto LAB_1400018da;
              }
              break;
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x23;
              goto LAB_1400019d2;
            }
          }
          goto LAB_1400019e2;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x20;
          goto LAB_1400018da;
        }
      }
      break;
    default:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                 &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,(uint)pbVar1[1]);
      }
      break;
    case 9:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1d;
LAB_1400018da:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      break;
    case 0xd:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x2a;
        goto LAB_1400018da;
      }
      break;
    case 0x13:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1e;
        goto LAB_1400018da;
      }
      break;
    case 0x14:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x2b;
        goto LAB_1400018da;
      }
      break;
    case 0x15:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x2c;
        goto LAB_1400018da;
      }
    }
switchD_1400014f6_caseD_1:
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    lVar7 = IofCallDriver(uVar2,param_2);
  }
  return lVar7;
}



===== __report_gsfailure @ 140001bd0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CleanUpExistingPorts @ 140001be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CleanUpExistingPorts(void) */

long __cdecl CleanUpExistingPorts(void)

{
  wchar_t *pwVar1;
  int iVar2;
  longlong lVar3;
  _DEVICE_OBJECT *p_Var4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auStack_1c8 [32];
  wchar_t *local_1a8;
  undefined4 *local_1a0;
  longlong local_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined4 local_180 [2];
  wchar_t *local_178;
  wchar_t local_170 [20];
  undefined1 local_148 [272];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_178 = (wchar_t *)0x0;
  local_198 = 0;
  local_180[0] = 0;
  local_190 = 0;
  uStack_188 = 0;
  if (RDPDYN_PDO == (_DEVICE_OBJECT *)0x0) {
    iVar2 = -0x3fffffff;
  }
  else {
    plVar5 = (longlong *)0x1;
    p_Var4 = RDPDYN_PDO;
    iVar2 = IoGetDeviceInterfaces(&DAT_140004150,RDPDYN_PDO,1,&local_178);
    if (iVar2 == 0) {
      if (local_178 == (wchar_t *)0x0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
          return 0;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
        return 0;
      }
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (local_178[lVar6] != L'\0');
      iVar2 = (int)lVar6;
      pwVar1 = local_178;
      do {
        if (iVar2 == 0) {
          ExFreePool(local_178);
          return 0;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_S(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),p_Var4,plVar5,pwVar1);
        }
        RtlInitUnicodeString(&local_190,pwVar1);
        plVar5 = &local_198;
        p_Var4 = (_DEVICE_OBJECT *)0xf003f;
        iVar2 = IoOpenDeviceInterfaceRegistryKey(&local_190);
        if (iVar2 == 0) {
          RtlInitUnicodeString(&local_190,L"Port Description");
          builtin_wcsncpy(local_170,L"Inactive TS Port",0x11);
          lVar3 = -1;
          do {
            lVar3 = lVar3 + 1;
          } while (local_170[lVar3] != L'\0');
          local_1a0 = (undefined4 *)CONCAT44(local_1a0._4_4_,(int)lVar3 * 2 + 2);
          local_1a8 = local_170;
          ZwSetValueKey(local_198,&local_190,0,1);
          RtlInitUnicodeString(&local_190,L"recyclable");
          local_1a0 = local_180;
          plVar5 = (longlong *)0x0;
          local_1a8 = (wchar_t *)CONCAT44(local_1a8._4_4_,0x110);
          p_Var4 = (_DEVICE_OBJECT *)&local_190;
          iVar2 = ZwQueryValueKey(local_198,p_Var4,0,local_148);
          if (iVar2 != 0) goto LAB_140001e1a;
          RtlInitUnicodeString(&local_190,L"Port Number");
          p_Var4 = (_DEVICE_OBJECT *)&local_190;
          ZwDeleteValueKey(local_198);
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            plVar5 = (longlong *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
            p_Var4 = (_DEVICE_OBJECT *)0x2f;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                     &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar2);
          }
          local_198 = 0;
LAB_140001e1a:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            plVar5 = (longlong *)&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids;
            p_Var4 = (_DEVICE_OBJECT *)0x30;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                    &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
          }
        }
        if (local_198 != 0) {
          ZwClose();
        }
        iVar2 = (int)lVar6;
        lVar6 = -1;
        pwVar1 = pwVar1 + (iVar2 + 1);
        do {
          lVar6 = lVar6 + 1;
        } while (pwVar1[lVar6] != L'\0');
        iVar2 = (int)lVar6;
      } while( true );
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
             &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar2);
  }
  return iVar2;
}



===== RdpBusPnPAddDevice @ 140001f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl RdpBusPnPAddDevice(struct _DRIVER_OBJECT * __ptr64,struct _DEVICE_OBJECT * __ptr64)
    */

long __cdecl RdpBusPnPAddDevice(_DRIVER_OBJECT *param_1,_DEVICE_OBJECT *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  undefined1 auStack_a8 [48];
  longlong *local_78;
  undefined4 *local_70;
  longlong *local_68;
  longlong local_58 [5];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58[0] = 0;
  local_30 = 0xa3e32dba;
  local_2c = 0x4f17ba89;
  local_28 = 0x12d8683;
  local_24 = 0xccd4fb27;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  RtlInitUnicodeString(local_58 + 3,L"\\Device\\RdpBus");
  pwVar4 = L"D:P(A;;GA;;;SY)";
  RtlInitUnicodeString(local_58 + 1);
  local_68 = local_58;
  local_70 = &local_30;
  local_78 = local_58 + 1;
  iVar2 = WdmlibIoCreateDeviceSecure(param_1,pwVar4,local_58 + 3);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar2);
    }
  }
  else {
    *(uint *)(local_58[0] + 0x30) = *(uint *)(local_58[0] + 0x30) | 4;
    plVar1 = *(longlong **)(local_58[0] + 0x40);
    *plVar1 = 0;
    lVar3 = IoAttachDeviceToDeviceStack(local_58[0],param_2);
    *plVar1 = lVar3;
    if (lVar3 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids);
      }
      *(uint *)(local_58[0] + 0x30) = *(uint *)(local_58[0] + 0x30) & 0xffffff7f;
      IoDeleteDevice(local_58[0]);
    }
    else {
      RDPDYN_PDO = param_2;
      *(uint *)(local_58[0] + 0x30) = *(uint *)(local_58[0] + 0x30) & 0xffffff7f;
    }
  }
  return iVar2;
}



===== WPP_SF_ @ 1400020d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1400020fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_Dd @ 140002140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,0x18,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_S @ 140002198 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

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
            (param_1,0x2b,&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,0x2e,param_4,lVar1,0);
  return;
}



===== WPP_SF_Z @ 14000220c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000223b;
    }
  }
  pwVar2 = L"NULL";
LAB_14000223b:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,0x13,param_4,2,pwVar2,
             wVar1,0);
  return;
}



===== WPP_SF_q @ 140002290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,0xb,&local_res20,8,0);
  return;
}



===== WppClassicProviderCallback @ 1400022e0 =====

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



===== WPP_SF_L @ 140002314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_123d8930722f3adf616e261d5bce6365_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 14000235c =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== _guard_check_icall @ 1400023c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400023d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400023fc =====

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



===== __cpu_features_init @ 140002470 =====

/* WARNING: Removing unreachable block (ram,0x0001400024da) */
/* WARNING: Removing unreachable block (ram,0x000140002489) */
/* WARNING: Removing unreachable block (ram,0x00014000247a) */

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



===== __security_check_cookie @ 140002540 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002580 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400025b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400025b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400025e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002640 =====

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



===== memset @ 140002940 =====

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



===== __memset_repmovs @ 140002a80 =====

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



===== __memset_query @ 140002b00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002b80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002cc0 =====

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



===== __memset_spec_plain @ 140002d40 =====

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



===== RdpBusUnload @ 140008010 =====

void RdpBusUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1);
  }
  if (RdpBusAdminSecurityDescriptor != (void *)0x0) {
    ExFreePoolWithTag(RdpBusAdminSecurityDescriptor,0x42706472);
    RdpBusAdminSecurityDescriptor = (void *)0x0;
  }
  WppCleanupKm();
  return;
}



===== WppCleanupKm @ 140008070 =====

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



===== WppInitKm @ 1400080f0 =====

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



===== WppLoadTracingSupport @ 140008180 =====

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



===== WppTraceCallback @ 1400082d0 =====

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



===== InitializeRdpBusSecurity @ 140008558 =====

int InitializeRdpBusSecurity(void)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0x10000000;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
  }
  uVar2 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x110);
  uVar3 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
  iVar4 = RtlLengthSid(uVar2);
  iVar5 = RtlLengthSid(uVar3);
  iVar4 = iVar5 + 0x48 + iVar4;
  RdpBusAdminSecurityDescriptor = (void *)ExAllocatePool2(0x100,iVar4,0x42706472);
  if (RdpBusAdminSecurityDescriptor == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
    }
    return -0x3fffffe9;
  }
  lVar1 = (longlong)RdpBusAdminSecurityDescriptor + 0x28;
  iVar5 = RtlCreateSecurityDescriptor(RdpBusAdminSecurityDescriptor,1);
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000879d;
    uVar7 = 0xc;
  }
  else {
    iVar5 = RtlCreateAcl(lVar1,iVar4 + -0x28,2);
    if (iVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000879d;
      uVar7 = 0xd;
    }
    else {
      uVar6 = IoGetFileObjectGenericMapping();
      RtlMapGenericMask(local_res8,uVar6);
      iVar5 = RtlAddAccessAllowedAce(lVar1,2,local_res8[0],uVar3);
      if (iVar5 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000879d;
        uVar7 = 0xe;
      }
      else {
        iVar5 = RtlAddAccessAllowedAce(lVar1,2,local_res8[0],uVar2);
        if (iVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000879d;
          uVar7 = 0xf;
        }
        else {
          iVar5 = RtlSetDaclSecurityDescriptor(RdpBusAdminSecurityDescriptor,1,lVar1,0);
          if (-1 < iVar5) {
            return 0;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000879d;
          uVar7 = 0x10;
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
           &WPP_123d8930722f3adf616e261d5bce6365_Traceguids,iVar5);
LAB_14000879d:
  if (RdpBusAdminSecurityDescriptor != (void *)0x0) {
    ExFreePoolWithTag(RdpBusAdminSecurityDescriptor,0x42706472);
    RdpBusAdminSecurityDescriptor = (void *)0x0;
  }
  return iVar5;
}



===== InitializeServiceSid @ 1400087e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitializeServiceSid(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_14 = 0x500;
  local_18 = 0;
  RtlInitializeSid(param_1,&local_18,6);
  uVar1 = *param_2;
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,0);
  *puVar2 = uVar1;
  uVar1 = param_2[1];
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,1);
  *puVar2 = uVar1;
  uVar1 = param_2[2];
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,2);
  *puVar2 = uVar1;
  uVar1 = param_2[3];
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,3);
  *puVar2 = uVar1;
  uVar1 = param_2[4];
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,4);
  *puVar2 = uVar1;
  uVar1 = param_2[5];
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,5);
  *puVar2 = uVar1;
  return;
}



===== IsCallerAllowedAccess @ 1400088e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IsCallerAllowedAccess(longlong param_1,char *param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  char local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = '\0';
  if (param_3 == (undefined1 *)0x0) {
    return -0x3ffffff3;
  }
  *param_3 = 0;
  iVar2 = IsSpoolerServiceProcess(local_48);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_123d8930722f3adf616e261d5bce6365_Traceguids,iVar2);
    }
    return iVar2;
  }
  if (local_48[0] == '\0') {
    cVar1 = IsCallerPrivileged(param_1,param_2);
    if (cVar1 == '\0') {
      local_30 = 0x3a18871;
      local_2c = 2;
      local_28 = 0xc0000022;
      RtlLogUnexpectedCodepath(&local_30);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return 0;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
      return 0;
    }
    local_38 = 0;
    local_40 = 0x3a18871;
    local_3c = 1;
    RtlLogUnexpectedCodepath(&local_40);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400089f3;
    uVar3 = 0x13;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400089f3;
    uVar3 = 0x12;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
LAB_1400089f3:
  *param_3 = 1;
  return 0;
}



===== IsCallerPrivileged @ 140008a78 =====

char IsCallerPrivileged(longlong param_1,char *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  longlong lVar5;
  undefined4 local_res8 [4];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  longlong local_38 [2];
  
  local_38[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_res8[0] = 0x10000000;
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\0';
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return '\0';
    }
    uVar4 = 0x1d;
  }
  else if (*param_2 == '\0') {
    if (RdpBusAdminSecurityDescriptor == (void *)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\0';
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return '\0';
      }
      uVar4 = 0x1f;
    }
    else {
      if (*(longlong *)(param_2 + 8) != 0) {
        lVar5 = *(longlong *)(*(longlong *)(param_2 + 8) + 8);
        uVar2 = IoGetFileObjectGenericMapping();
        RtlMapGenericMask(local_res8,uVar2);
        lVar5 = lVar5 + 0x20;
        SeLockSubjectContext(lVar5);
        uVar3 = 1;
        if ((param_2[2] & 1U) == 0) {
          uVar3 = *(undefined1 *)(param_1 + 0x40);
        }
        cVar1 = SeAccessCheck(RdpBusAdminSecurityDescriptor,lVar5,1,local_res8[0],0,local_38,uVar2,
                              uVar3,local_res20,local_res18);
        if (local_38[0] != 0) {
          SeFreePrivileges();
        }
        SeUnlockSubjectContext(lVar5);
        if (cVar1 == '\0') {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return '\0';
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
            return '\0';
          }
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_123d8930722f3adf616e261d5bce6365_Traceguids,local_res18[0]);
          return '\0';
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return cVar1;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return cVar1;
        }
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
        return cVar1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return '\0';
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return '\0';
      }
      uVar4 = 0x20;
    }
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return '\0';
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return '\0';
    }
    uVar4 = 0x1e;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
          &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
  return '\0';
}



===== IsSpoolerServiceProcess @ 140008cbc =====

int IsSpoolerServiceProcess(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined2 uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint *local_res8;
  longlong *local_res10;
  longlong local_res18;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  local_res8 = (uint *)0x0;
  lVar6 = 0;
  local_res10 = (longlong *)0x0;
  if (param_1 == (char *)0x0) {
    return -0x3ffffff3;
  }
  *param_1 = '\0';
  uVar4 = IoGetCurrentProcess();
  lVar5 = PsReferencePrimaryToken(uVar4);
  if (lVar5 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
    }
    return -0x3fffffff;
  }
  uVar2 = RtlLengthRequiredSid(6);
  uVar4 = 0x42706472;
  local_res18 = ExAllocatePool2(0x100,uVar2);
  if (local_res18 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = 0x16;
LAB_140008da6:
      WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar4,uVar2);
    }
LAB_140008db2:
    iVar3 = -0x3fffff66;
  }
  else {
    local_58 = 0x50;
    local_54 = 0xeb83221f;
    local_50 = 0x63a193e8;
    local_4c = 0x546b16cf;
    local_48 = 0xe04e4c2b;
    local_44 = 0xea46a3ca;
    InitializeServiceSid(local_res18,&local_58);
    uVar4 = 0x42706472;
    lVar6 = ExAllocatePool2(0x100,uVar2);
    if (lVar6 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar7 = 0x17;
        goto LAB_140008da6;
      }
      goto LAB_140008db2;
    }
    local_58 = 99;
    local_54 = 0xce5dbac;
    local_50 = 0x76f17ec4;
    local_4c = 0xe5f30edb;
    local_48 = 0x8f58c130;
    local_44 = 0x9c65577d;
    InitializeServiceSid(lVar6,&local_58);
    iVar3 = SeQueryInformationToken(lVar5,2,&local_res8);
    if (iVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_123d8930722f3adf616e261d5bce6365_Traceguids,iVar3);
      }
    }
    else if (local_res8 == (uint *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
      }
      iVar3 = -0x3fffffff;
    }
    else {
      uVar9 = 0;
      if (*local_res8 != 0) {
        do {
          if ((local_res8[uVar9 * 4 + 4] & 4) != 0) {
            cVar1 = RtlEqualSid(*(undefined8 *)(local_res8 + uVar9 * 4 + 2),local_res18);
            if (cVar1 != '\0') {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_140008fde;
              uVar7 = 0x1a;
              goto LAB_140008fce;
            }
            cVar1 = RtlEqualSid(*(undefined8 *)(local_res8 + uVar9 * 4 + 2),lVar6);
            if (cVar1 != '\0') {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                        &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
              }
              *param_1 = '\x01';
              break;
            }
          }
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
        } while (uVar8 < *local_res8);
      }
      if ((*param_1 == '\0') && (iVar3 = SeQueryInformationToken(lVar5,5,&local_res10), -1 < iVar3))
      {
        if (local_res10 == (longlong *)0x0) goto LAB_140008ff8;
        if ((*local_res10 != 0) && (cVar1 = RtlEqualSid(*local_res10,lVar6), cVar1 != '\0')) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = 0x1c;
LAB_140008fce:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                    &WPP_123d8930722f3adf616e261d5bce6365_Traceguids);
          }
LAB_140008fde:
          *param_1 = '\x01';
        }
      }
    }
  }
  if (local_res10 != (longlong *)0x0) {
    ExFreePoolWithTag(local_res10,0);
  }
LAB_140008ff8:
  if (local_res8 != (uint *)0x0) {
    ExFreePoolWithTag(local_res8,0);
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x42706472);
  }
  if (local_res18 != 0) {
    ExFreePoolWithTag(local_res18,0x42706472);
  }
  PsDereferencePrimaryToken(lVar5);
  return iVar3;
}



===== WdmlibInit @ 1400090d0 =====

void WdmlibInit(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
  PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
  if (PfnIoCreateDeviceSecure == (code *)0x0) {
    PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
  }
  RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
  MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = 1;
  return;
}



===== WdmlibIoCreateDeviceSecure @ 14000915c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,8,param_3,0x100,0,0,in_stack_00000038,in_stack_00000040,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1400091e0 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,uint *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (uint *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140009340;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (uint *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140009340;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_140009340:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 140009374 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 140009464 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 140009544 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 140009644 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 140009730 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  short *local_res8;
  uint local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_res18[0] = 0;
  iVar5 = 0;
  local_58 = (wchar_t *)0x0;
  local_50[0] = 0;
  uVar15 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar3 = false;
  bVar2 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar15 = uVar15 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar11 = uVar15 / 5;
  local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11);
  if ((uVar15 != uVar11 * 5) || ((uVar15 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar11 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar15 = uVar11 * 0x30 + 8;
      if (0xffff < uVar15) {
        uVar15 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar15,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar15);
        *_Dst = 2;
        _Dst[1] = (short)uVar15;
        *(undefined4 *)(_Dst + 2) = 0;
        uVar15 = (uint)local_res8;
        for (local_res10 = 0; uVar11 = 0, local_res10 < uVar15; local_res10 = local_res10 + 1) {
          local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
          for (; *param_1 == L' '; param_1 = param_1 + 1) {
          }
          if (*param_1 == L'(') {
            do {
              param_1 = param_1 + 1;
            } while (*param_1 == L' ');
          }
          iVar4 = _wcsnicmp(param_1,L"A",1);
          if (iVar4 != 0) {
LAB_140009a54:
            iVar5 = -0x3ffffff3;
LAB_140009a56:
            lVar7 = *param_2;
            goto LAB_140009a62;
          }
          for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          if (*pwVar6 != L';') goto LAB_140009a54;
          do {
            pwVar6 = pwVar6 + 1;
          } while (*pwVar6 == L' ');
          while (wVar1 = *pwVar6, wVar1 != L';') {
            while (wVar1 == L' ') {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            }
            uVar9 = SepSddlLookupAccessMaskInTable(pwVar6,local_res18,(longlong *)&local_58);
            if ((int)uVar9 == 0) {
              SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
              if (local_58 == pwVar6) goto LAB_140009a54;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar6 = local_58;
          }
          pwVar6 = pwVar6 + 1;
          if (iVar5 != 0) goto LAB_140009a56;
          lVar7 = 2;
          do {
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') {
              iVar5 = -0x3ffffff3;
            }
            pwVar6 = pwVar6 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
          if (iVar5 != 0) goto LAB_140009a56;
          for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          local_res8 = (short *)0x0;
          ppsVar13 = &local_res8;
          uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
          iVar5 = (int)uVar9;
          if (iVar5 != 0) break;
          psVar12 = local_res8;
          if (local_res8 == (short *)0x0) {
LAB_1400099ee:
            iVar5 = -0x3fffff89;
            goto LAB_140009a56;
          }
          for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
          }
          if (*psVar12 != 0x29) goto LAB_1400099ee;
          param_1 = psVar12 + 1;
          if (local_50[0] != 0) {
            uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar11,
                                       uVar15 - local_res10,local_50[0]);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) goto LAB_140009a56;
          }
          if (*param_1 == L'(') {
            param_1 = psVar12 + 2;
          }
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(undefined2 *)(lVar7 + 2) = (undefined2)local_res20[0];
          return 0;
        }
LAB_140009a62:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140009aa0 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  do {
    if (0xd < uVar6) {
      uVar4 = 0xc0000073;
LAB_140009b48:
      *param_2 = uVar5;
      return uVar4;
    }
    uVar3 = (ulonglong)uVar6;
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1400050dc + uVar3 * 0x18),
                      (ulonglong)*(uint *)(&DAT_1400050e4 + uVar3 * 0x18));
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1400050d8 + uVar3 * 0x18);
      uVar6 = *(uint *)(&DAT_1400050e4 + uVar3 * 0x18);
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto code_r0x000140009b2d;
      }
      else {
code_r0x000140009b2d:
        uVar5 = *(undefined8 *)
                 (*(longlong *)(&DAT_1400050d0 + uVar3 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar4 = 0;
      goto LAB_140009b48;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 140009b74 =====

undefined8 SepSddlLookupAccessMaskInTable(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  while( true ) {
    if (7 < uVar2) {
      *param_2 = 0;
      *param_3 = (longlong)param_1;
      return 0;
    }
    uVar3 = (ulonglong)uVar2;
    iVar1 = _wcsnicmp(param_1,(wchar_t *)(&PTR_u_RC_140005010)[uVar3 * 2],
                      (ulonglong)*(uint *)(&DAT_140005018 + uVar3 * 2));
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = *(undefined4 *)((longlong)&DAT_140005018 + uVar3 * 0x10 + 4);
  *param_3 = (longlong)(param_1 + *(uint *)(&DAT_140005018 + uVar3 * 2));
  return 1;
}



===== SepSddlParseWideStringUlong @ 140009c0c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *param_1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_140009c79:
      iVar6 = 10;
      goto LAB_140009c50;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140009c79;
  iVar6 = 0x10;
LAB_140009c50:
  uVar7 = 0;
  for (puVar4 = param_1; uVar1 = *puVar4, uVar1 != 0; puVar4 = puVar4 + 1) {
    if ((ushort)(uVar1 - 0x30) < 10) {
      iVar2 = uVar1 - 0x30;
    }
    else {
      if (iVar6 != 0x10) break;
      if ((ushort)(uVar1 - 0x41) < 6) {
        iVar2 = uVar1 - 0x37;
      }
      else {
        if (5 < (ushort)(uVar1 - 0x61)) break;
        iVar2 = uVar1 - 0x57;
      }
    }
    uVar5 = iVar6 * uVar7 + iVar2;
    if (uVar5 < uVar7) goto LAB_140009cbd;
    uVar7 = uVar5;
  }
  if (puVar4 == param_1) {
LAB_140009cbd:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140009ce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_140009e29;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140009e29:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 140009e88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (uint *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140004580,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar3 = (ulonglong)*param_1;
    pwVar5 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar4 = 2;
    }
    else {
      uVar2 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar5,uVar3,0,&local_b8,local_a8);
      uVar4 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar4;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 14000a024 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x140004500);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14000a1a3;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140004518,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14000a1a3;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140004530,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14000a1a3;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140004560,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_14000a1a3:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 14000a1e8 =====

ulonglong PpRegStateReadCreateClassCreationSettings(uint *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1400044a0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1400044b8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400044c8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400044e8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 14000a34c =====

ulonglong PpRegStateUpdateStackCreationSettings(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,0x1400044a0,uVar7,uVar8,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = (ulonglong)uVar2;
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x140004500);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar2 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar3);
        uVar4 = (ulonglong)uVar2;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 14000a4b4 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateUcKey @ 14000a5b0 =====

int CmRegUtilCreateUcKey
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined8 local_res8 [3];
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res20[0] = 0;
  local_res8[0] = 0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,0xf003f,&local_38,0,0,0,local_res20);
  if (iVar1 < 0) {
    local_res8[0] = 0;
    local_res20[0] = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_res20[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 14000a658 =====

void CmRegUtilCreateWstrKey
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [12];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilCreateUcKey(param_1,local_18,param_3,param_1,param_5,param_6,param_7);
  }
  return;
}



===== CmRegUtilOpenExistingWstrKey @ 14000a6b8 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 14000a74c =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_14000a884;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_14000a884:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 14000a8c8 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 14000aa14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 14000aab8 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== entry @ 14000b010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000b044 =====

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



===== DriverEntry @ 14000b078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  _DAT_140005318 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1400052f8 = &WPP_ThisDir_CTLGUID_CtlGuid;
  DAT_140005300 = 0;
  _DAT_140005310 = 0;
  WppLoadTracingSupport();
  _DAT_140005310 = 0;
  WppInitKm();
  *(code **)(param_1 + 0x68) = RdpBusUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = RdpBusPnPAddDevice;
  puVar3 = (undefined8 *)(param_1 + 0x70);
  for (lVar2 = 0x1c; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = RdpBusDispatch;
    puVar3 = puVar3 + 1;
  }
  iVar1 = InitializeRdpBusSecurity();
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_c9b756bfe0fc31ebef23ca63033f9a50_Traceguids,iVar1);
    }
    WppCleanupKm();
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


