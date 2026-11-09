
===== ChidmpFindAdapter @ 140001000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ChidmpFindAdapter(undefined8 *param_1)

{
  ulonglong uVar1;
  char *pcVar2;
  longlong in_stack_00000030;
  
  *param_1 = &gdmpDevExtension;
  DAT_140018200 = *(longlong *)(in_stack_00000030 + 0x40);
  DAT_140018238 = param_1;
  *(undefined4 *)(in_stack_00000030 + 0xc0) = 0x8000;
  _DAT_140017e18 = *(undefined8 *)(DAT_140018200 + 0x468);
  DAT_140017e10 = *(undefined8 *)(DAT_140018200 + 0x460);
  DAT_140017e0c = *(undefined4 *)(in_stack_00000030 + 4);
  DAT_140017e20 = *(undefined4 *)(in_stack_00000030 + 100);
  DAT_14001809c = 0;
  DAT_1400180a0 = 0;
  DAT_140018210 = 0;
  DAT_14001820c = 0;
  _DAT_140018208 = 0;
  DAT_1400180a4 = 0xffffc2;
  *(undefined4 *)(in_stack_00000030 + 0x1c) = 0;
  *(undefined2 *)(in_stack_00000030 + 0x48) = 1;
  *(undefined1 *)(in_stack_00000030 + 0x61) = 1;
  *(undefined2 *)(in_stack_00000030 + 0x92) = 0x101;
  *(undefined2 *)(in_stack_00000030 + 0x51) = 0x101;
  *(undefined1 *)(in_stack_00000030 + 0x53) = 1;
  *(undefined1 *)(in_stack_00000030 + 0x57) = 1;
  *(undefined2 *)(in_stack_00000030 + 0x5a) = 0x101;
  *(undefined4 *)(in_stack_00000030 + 0x30) = 3;
  *(undefined4 *)(in_stack_00000030 + 8) = 5;
  *(undefined1 *)(in_stack_00000030 + 0x59) = 2;
  *(undefined4 *)(in_stack_00000030 + 0x94) = 1;
  *(undefined1 *)(in_stack_00000030 + 0xc4) = 1;
  uVar1 = ChidumpSetupDma(param_1,in_stack_00000030);
  if ((char)uVar1 == '\0') {
    uVar1 = BusInit();
    if ((int)uVar1 == 0) {
      return 1;
    }
    pcVar2 = "HW Init Failed!!\n";
  }
  else {
    pcVar2 = "ChidmpFindAdapter: Failed to setup DMA!!\n";
  }
  DbgPrint(pcVar2);
  return 2;
}



===== ChidumpAdapterControl @ 140001130 =====

undefined8 ChidumpAdapterControl(undefined8 param_1,int param_2,longlong param_3)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 5) = 0x101;
    *(undefined1 *)(param_3 + 4) = 1;
  }
  else if ((param_2 != 1) && (param_2 != 2)) {
    return 1;
  }
  return 0;
}



===== ChidumpInitialize @ 140001160 =====

undefined8 ChidumpInitialize(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *param_1;
  uVar2 = func_init();
  if ((int)uVar2 != 0) {
    DbgPrint("func_init failed\n");
  }
  *(undefined8 *)(lVar1 + 0x420) = 0;
  *(undefined8 *)(lVar1 + 0x428) = 0;
  *(undefined2 *)(lVar1 + 0x432) = 0;
  uVar2 = dump_target_login();
  if ((int)uVar2 != 0) {
    uVar2 = DbgPrint("dump_target_login failed\n");
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ChidumpPhysFindAdapter @ 1400011c0 =====

void ChidumpPhysFindAdapter(undefined8 *param_1)

{
  ChidmpFindAdapter(param_1);
  return;
}



===== ChidumpResetBus @ 1400011f0 =====

undefined1 ChidumpResetBus(void)

{
  return 1;
}



===== ChidumpSetupDma @ 1400011f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ChidumpSetupDma(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  uint local_res18 [4];
  
  local_res18[0] = 0;
  memset(&DAT_1400180a8,0,0x58);
  DAT_1400180b0 = (void *)StorPortGetUncachedExtension(param_1,param_2,0xf000);
  if (DAT_1400180b0 != (void *)0x0) {
    DbgPrint("size of uncached extension = %d\n",0xf000);
    _DAT_1400180a8 = StorPortGetPhysicalAddress(param_1,0,DAT_1400180b0,local_res18);
    if (_DAT_1400180a8 != 0) {
      DbgPrint("Mapped length = %d\n");
      _DAT_1400180f8 = (ulonglong)local_res18[0];
      memset(DAT_1400180b0,0,_DAT_1400180f8);
      DAT_1400180d0 = DAT_1400180b0;
      _DAT_1400180cc = DAT_1400180ac;
      DAT_1400180c8 = DAT_1400180a8;
      page_align_dmabuf();
      _DAT_1400180c0 = DAT_1400180d0;
      _DAT_1400180bc = _DAT_1400180cc;
      _DAT_1400180b8 = DAT_1400180c8;
      uVar1 = DbgPrint("\nDMABLE MEM POOL------\n origvirtaddress = 0x%lx\n, origphyaddress.low = 0x%lx origphyaddress.high = 0x%lx\nalignedvirtaddress = 0x%lx\n, alignedphyaddress.low = 0x%lx alignedphyaddress.high = 0x%lx\ncurvirtaddress = 0x%lx\n, curphyaddress.low = 0x%lx curphyaddress.high = 0x%lx\n"
                       ,DAT_1400180b0,_DAT_1400180a8 & 0xffffffff,DAT_1400180ac,DAT_1400180d0,
                       DAT_1400180c8,_DAT_1400180cc,DAT_1400180d0,DAT_1400180c8,_DAT_1400180cc);
      return uVar1 & 0xffffffffffffff00;
    }
  }
  return 1;
}



===== ChidumpStartIo @ 140001340 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ChidumpStartIo(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  cVar5 = *(char *)(param_2 + 2);
  *(undefined1 *)(param_2 + 3) = 4;
  if (cVar5 != '\0') {
    if (cVar5 == '\a') {
      DbgPrint("SRB SHUTDOWN\n");
      iscsi_send_scsicmd(2,0);
      get_resp(0,0x42);
      DbgPrint();
      dump_close_conn_wr();
      uVar2 = get_resp(0,0);
      pcVar3 = "Closed the dump mode tcp conn!\n";
      if ((char)uVar2 == '\0') {
        pcVar3 = "Failed to close Dump mode tcp conn!!!\n";
      }
      DbgPrint(pcVar3);
      *(undefined1 *)(param_2 + 3) = 1;
    }
    else {
      DbgPrint("\n\nUnhandled Srb function 0x%x\n",cVar5);
      *(undefined1 *)(param_2 + 3) = 6;
    }
    goto LAB_140001605;
  }
  cVar5 = *(char *)(param_2 + 0x48);
  if (((cVar5 == '\0') || (cVar5 == '\x12')) || (cVar5 == '\x1a')) goto LAB_1400015e1;
  if (cVar5 == '\x1b') {
    cVar5 = '\x1b';
    pcVar3 = "\n\nSTART_STOP_UNIT SCSI command 0x%x!!\n";
LAB_1400015e8:
    DbgPrint(pcVar3,cVar5);
  }
  else {
    if (cVar5 == '%') {
LAB_1400015e1:
      pcVar3 = "\n\ncommand %02x received\n";
      goto LAB_1400015e8;
    }
    if (cVar5 != '(') {
      if (cVar5 == '*') {
        cVar5 = '\0';
        iscsi_send_writecmd(1,param_2,0,0xe00);
        do {
          cVar4 = '\0';
          DAT_140017e44 = '\0';
          _DAT_140018232 = _DAT_140018232 & 0xff00;
          get_resp(param_2,0x42);
          if (DAT_140017e44 == '\0') {
            if (DAT_140017e45 == '\0') {
              DbgPrint("Did\'nt get R2T\n");
              _DAT_140018232 = 0;
              DAT_140018220 = 0;
              DAT_140018228 = 0;
              dump_target_login();
              *(undefined2 *)(param_2 + 3) = 0x404;
            }
            else {
              DAT_140017e45 = '\0';
            }
            break;
          }
          iVar8 = 0;
          uVar6 = 0;
          uVar1 = DAT_140017e34;
          if (DAT_14001808c < DAT_140017e34) {
            uVar1 = DAT_14001808c;
          }
          while (uVar1 != 0) {
            uVar7 = uVar1;
            if (DAT_140018088 < uVar1) {
              uVar7 = DAT_140018088;
            }
            if (uVar1 - uVar7 == 0) {
              cVar4 = '\x01';
            }
            while( true ) {
              iscsi_send_dataoutpdu
                        (param_2,DAT_140017e30 + iVar8,uVar7,DAT_140017e38,DAT_140017e3c,uVar6,cVar4
                        );
              if (cVar4 != '\0') {
                _DAT_140018232 = CONCAT11(DAT_140018233,1);
              }
              uVar2 = get_resp(param_2,0xc3);
              if ((char)uVar2 != '\0') break;
              KeStallExecutionProcessor(2000);
              if (cVar5 == '2') {
                DbgPrint("Failed to send dataout!! aborting!!\n");
                goto LAB_14000156d;
              }
              cVar5 = cVar5 + '\x01';
            }
            iVar8 = iVar8 + uVar7;
            cVar5 = '\0';
            uVar6 = uVar6 + 1;
            uVar1 = uVar1 - uVar7;
          }
LAB_14000156d:
        } while (DAT_140017e44 != '\0');
        goto LAB_140001605;
      }
      if ((cVar5 != '5') && (cVar5 != -0x60)) {
        pcVar3 = "\n\nUnhandled SCSI command 0x%x!!\n";
        goto LAB_1400015e8;
      }
      goto LAB_1400015e1;
    }
    DbgPrint("\n\nREAD SCSI command!!\n");
  }
  iscsi_send_scsicmd(1,param_2);
  get_resp(param_2,0x42);
LAB_140001605:
  uVar2 = StorPortNotification(0,param_1,param_2);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== DriverEntry @ 140001634 =====

void DriverEntry(longlong param_1,longlong param_2)

{
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  undefined8 local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined2 local_7c;
  code *local_60;
  
  if ((param_1 == 0) && (param_2 == 0)) {
    DbgPrint("IN DUMP MODE!\n");
  }
  memset(&local_d8,0,0xd0);
  local_c0 = 0;
  local_94 = 0;
  local_90 = 0;
  local_b8 = ChidumpPhysFindAdapter;
  local_d4 = 5;
  local_d0 = ChidumpInitialize;
  local_d8 = 0xd0;
  local_c8 = ChidumpStartIo;
  local_60 = ChidumpAdapterControl;
  local_b0 = ChidumpResetBus;
  local_98 = 8;
  local_8c = 1;
  local_80 = 0x1010102;
  local_7c = 0x101;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== page_align_dmabuf @ 14000170c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void page_align_dmabuf(void)

{
  if ((DAT_1400180d0 & 0xfff) != 0) {
    DAT_1400180d0 = (DAT_1400180d0 & 0xfffffffffffff000) + 0x1000;
  }
  if ((_DAT_1400180c8 & 0xfff) != 0) {
    _DAT_1400180c8 = (_DAT_1400180c8 & 0xfffffffffffff000) + 0x1000;
  }
  DbgPrint("\nAfter Aligning : virt addr = 0x%lx, physaddr.low = 0x%llx physaddr.high = 0x%lx\n",
           DAT_1400180d0,_DAT_1400180c8 & 0xffffffff,(longlong)_DAT_1400180c8 >> 0x20);
  return;
}



===== update_pool_ptr @ 140001764 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void update_pool_ptr(uint param_1)

{
  ulonglong uVar1;
  
  uVar1 = DAT_1400180d0 + param_1;
  if (uVar1 < (ulonglong)(DAT_1400180b0 + _DAT_1400180f8)) {
    _DAT_1400180c8 = _DAT_1400180c8 + (ulonglong)param_1;
    DAT_1400180d0 = uVar1;
    DbgPrint("dma_mem_alloc: curvirtaddr = 0x%x curphysaddr = 0x%x, size = 0x%x\n",uVar1,
             _DAT_1400180c8,param_1);
    return;
  }
  DbgPrint("dma_mem_alloc failed!! out of pool region!!\n");
  return;
}



===== DbgDmp @ 1400017bc =====

void DbgDmp(longlong param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  if (0 < param_2) {
    lVar2 = 0;
    uVar3 = 1;
    do {
      DbgPrint(&s__02x_,*(undefined1 *)(lVar2 + param_1));
      uVar1 = uVar3 & 0x80000007;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;
      }
      if ((uVar1 == 0) && (lVar2 != 0)) {
        DbgPrint(&s__);
      }
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + 1;
    } while (lVar2 < param_2);
  }
  DbgPrint(&s__);
  return;
}



===== RtlStringCchPrintfA @ 140001840 =====

int RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  size_t _Count;
  int iVar1;
  int iVar2;
  undefined8 local_res20;
  
  iVar2 = 0;
  if (0x7ffffffe < param_2 - 1U) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  else {
    _Count = param_2 - 1;
    iVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      iVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  return iVar2;
}



===== chap_calc_md5_digest @ 1400018b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void chap_calc_md5_digest
               (undefined1 param_1,undefined8 *param_2,undefined8 *param_3,uint param_4,
               undefined8 *param_5)

{
  ulonglong uVar1;
  undefined1 auStack_c8 [32];
  undefined1 local_a8 [16];
  uint local_98 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8[0] = param_1;
  crypto_md5_init(local_98);
  crypto_md5_update(local_98,(undefined8 *)local_a8,1);
  uVar1 = 0xffffffffffffffff;
  do {
    uVar1 = uVar1 + 1;
  } while (*(char *)((longlong)param_2 + uVar1) != '\0');
  crypto_md5_update(local_98,param_2,uVar1);
  crypto_md5_update(local_98,param_3,(ulonglong)param_4);
  crypto_md5_finish(local_98,param_5);
  return;
}



===== decode_base64_string @ 14000195c =====

ulonglong decode_base64_string(char *param_1,longlong param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte local_res8 [8];
  
  uVar12 = 0;
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    pcVar3 = param_1;
    pcVar2 = (char *)((ulonglong)param_1 & 0xffffffff);
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      pcVar2 = pcVar3;
      cVar1 = *pcVar3;
    }
    uVar6 = 0;
    uVar11 = (int)pcVar2 - (int)param_1;
    if ((uVar11 != 0) && (param_2 != 0)) {
      if ((uVar11 & 3) != 0) {
        return 0xffffffe6;
      }
      if (param_1[uVar11 - 1] == '=') {
        cVar1 = param_1[uVar11 - 2];
        uVar11 = uVar11 - ((cVar1 == '=') + 1);
        uVar6 = uVar11 & 3;
        if (uVar6 == 2) {
          if (cVar1 != '=') {
            return 0xffffffef;
          }
        }
        else {
          if (uVar6 != 3) {
            return 0xffffffef;
          }
          if (cVar1 == '=') {
            return 0xffffffef;
          }
        }
        uVar11 = uVar11 - uVar6;
      }
      uVar7 = 0;
      uVar9 = 0;
      if (uVar11 != 0) {
        do {
          uVar5 = 0;
          pbVar13 = local_res8;
          do {
            cVar1 = param_1[uVar7];
            if (cVar1 == '=') {
              return 0xffffffe6;
            }
            if (cVar1 == '/') {
              bVar4 = 0x3f;
            }
            else if (cVar1 == '+') {
              bVar4 = 0x3e;
            }
            else {
              bVar4 = cVar1 + 0xbf;
              if (0x19 < bVar4) {
                if ((byte)(cVar1 + 0x9fU) < 0x1a) {
                  bVar4 = cVar1 + 0xb9;
                }
                else if ((byte)(cVar1 - 0x30U) < 10) {
                  bVar4 = cVar1 + 4;
                }
                else {
                  bVar4 = 0xff;
                }
              }
              if ((char)bVar4 < '\0') {
                return 0xffffffe6;
              }
              if (bVar4 == 0x40) {
                return 0xffffffe6;
              }
            }
            *pbVar13 = bVar4;
            uVar5 = uVar5 + 1;
            pbVar13 = pbVar13 + 1;
            uVar7 = uVar7 + 1;
          } while (uVar5 < 4);
          iVar8 = (int)uVar9;
          *(byte *)(uVar9 + param_2) = local_res8[1] >> 4 & 3 | local_res8[0] << 2;
          *(byte *)((ulonglong)(iVar8 + 1) + param_2) =
               local_res8[2] >> 2 & 0xf | local_res8[1] << 4;
          *(byte *)((ulonglong)(iVar8 + 2) + param_2) = local_res8[3] & 0x3f | local_res8[2] << 6;
          uVar9 = (ulonglong)(iVar8 + 3);
        } while (uVar7 < uVar11);
      }
      uVar10 = uVar9;
      if (uVar6 != 0) {
        pbVar13 = local_res8;
        do {
          cVar1 = param_1[uVar7];
          if (cVar1 == '=') {
            return 0xffffffe6;
          }
          if (cVar1 == '/') {
            bVar4 = 0x3f;
          }
          else if (cVar1 == '+') {
            bVar4 = 0x3e;
          }
          else {
            bVar4 = cVar1 + 0xbf;
            if (0x19 < bVar4) {
              if ((byte)(cVar1 + 0x9fU) < 0x1a) {
                bVar4 = cVar1 + 0xb9;
              }
              else if ((byte)(cVar1 - 0x30U) < 10) {
                bVar4 = cVar1 + 4;
              }
              else {
                bVar4 = 0xff;
              }
            }
            if ((char)bVar4 < '\0') {
              return 0xffffffe6;
            }
            if (bVar4 == 0x40) {
              return 0xffffffe6;
            }
          }
          *pbVar13 = bVar4;
          uVar12 = uVar12 + 1;
          pbVar13 = pbVar13 + 1;
          uVar7 = uVar7 + 1;
        } while (uVar12 < uVar6);
        uVar10 = (ulonglong)((int)uVar9 + 1);
        *(byte *)(uVar9 + param_2) = local_res8[1] >> 4 & 3 | local_res8[0] << 2;
        if (uVar6 == 3) {
          *(byte *)(uVar10 + param_2) = local_res8[2] >> 2 & 0xf | local_res8[1] << 4;
          uVar10 = (ulonglong)((int)uVar9 + 2);
        }
      }
      return uVar10;
    }
  }
  return 0xffffffdf;
}



===== decode_encoded_chal @ 140001ba0 =====

ulonglong decode_encoded_chal(char *param_1,undefined8 *param_2,undefined1 *param_3,uint *param_4)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (param_1[lVar6] != '\0');
  uVar5 = (int)lVar6 - 2;
  if (*param_1 == '0') {
    if ((param_1[1] + 0xa8U & 0xdf) == 0) {
      *param_3 = 1;
      uVar5 = ((int)lVar6 + -3) / 2 + 1;
      pbVar2 = mem_alloc(uVar5);
      if (pbVar2 == (byte *)0x0) {
        return 0xffffffea;
      }
      uVar1 = decode_hex_str(param_1 + 2,pbVar2,uVar5);
      if ((int)uVar1 < 0) {
        uVar4 = (ulonglong)uVar1;
LAB_140001c7e:
        mem_free((longlong)pbVar2);
        return uVar4 & 0xffffffff;
      }
    }
    else {
      if (((param_1[1] + 0xbeU & 0xdf) != 0) || (*param_3 = 2, (uVar5 & 3) != 0))
      goto LAB_140001c8a;
      uVar5 = ((int)(uVar5 + ((int)uVar5 >> 0x1f & 3U)) >> 2) * 3;
      pbVar2 = mem_alloc(uVar5);
      if (pbVar2 == (byte *)0x0) {
        return 0xffffffea;
      }
      uVar3 = decode_base64_string(param_1 + 2,(longlong)pbVar2);
      uVar4 = (ulonglong)(int)uVar3;
      if ((int)uVar3 < 0) goto LAB_140001c7e;
      pbVar2[uVar4] = 0;
    }
    *param_2 = pbVar2;
    uVar4 = 0;
    *param_4 = uVar5;
  }
  else {
LAB_140001c8a:
    uVar4 = 0xffffffef;
  }
  return uVar4;
}



===== decode_hex_str @ 140001cac =====

int decode_hex_str(char *param_1,byte *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  byte bVar7;
  longlong lVar8;
  uint uVar9;
  byte *pbVar10;
  
  lVar8 = 0;
  if (param_1 == (char *)0x0) {
    uVar9 = 0;
  }
  else {
    cVar1 = *param_1;
    pcVar5 = param_1;
    pcVar3 = (char *)((ulonglong)param_1 & 0xffffffff);
    while (cVar1 != '\0') {
      pcVar5 = pcVar5 + 1;
      pcVar3 = pcVar5;
      cVar1 = *pcVar5;
    }
    uVar9 = (int)pcVar3 - (int)param_1;
    if ((uVar9 != 0) && (param_2 != (byte *)0x0)) {
      iVar4 = (int)(uVar9 + 1) / 2;
      if (param_3 < iVar4) {
        DbgPrint("hex string tlen %d < tolen %d.\n",iVar4);
      }
      if ((uVar9 & 1) != 0) {
        DbgPrint(&s_hex_string_length_odd__d__,uVar9);
        cVar1 = *param_1;
        bVar7 = cVar1 - 0x30;
        if (9 < bVar7) {
          if ((byte)(cVar1 + 0xbfU) < 6) {
            bVar7 = cVar1 - 0x37;
          }
          else {
            if (5 < (byte)(cVar1 + 0x9fU)) {
LAB_140001dc1:
              DbgPrint("bad hex char %c.\n",(int)cVar1);
              return -0x1a;
            }
            bVar7 = cVar1 + 0xa9;
          }
        }
        *param_2 = bVar7;
        lVar8 = 1;
      }
      if (lVar8 < (int)uVar9) {
        pcVar5 = param_1 + lVar8 + 1;
        pbVar10 = param_2 + lVar8;
        do {
          cVar6 = pcVar5[-1];
          cVar2 = *pcVar5;
          if (9 < (byte)(cVar6 - 0x30U)) {
            if ((byte)(cVar6 + 0xbfU) < 6) {
              cVar6 = cVar6 + -0x37;
            }
            else {
              cVar1 = cVar6;
              if (5 < (byte)(cVar6 + 0x9fU)) goto LAB_140001dc1;
              cVar6 = cVar6 + -0x57;
            }
          }
          bVar7 = cVar2 - 0x30;
          if (9 < bVar7) {
            if ((byte)(cVar2 + 0xbfU) < 6) {
              bVar7 = cVar2 - 0x37;
            }
            else {
              cVar1 = cVar2;
              if (5 < (byte)(cVar2 + 0x9fU)) goto LAB_140001dc1;
              bVar7 = cVar2 + 0xa9;
            }
          }
          pcVar5 = pcVar5 + 2;
          *pbVar10 = cVar6 << 4 | bVar7;
          pbVar10 = pbVar10 + 1;
        } while ((longlong)(pcVar5 + (-1 - (longlong)param_1)) < (longlong)(int)uVar9);
      }
      return iVar4;
    }
  }
  DbgPrint("hex string 0x%p (%d), 0x%p (%d).\n",param_1,uVar9,param_2,param_3);
  return -0x21;
}



===== encode_base64_string @ 140001e28 =====

uint encode_base64_string(longlong param_1,uint param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    return 0xffffffdf;
  }
  uVar5 = 0;
  uVar3 = (param_2 / 3) * 3;
  uVar6 = uVar7;
  if (uVar3 != 0) {
    do {
      uVar7 = uVar6 + 3;
      *(char *)((ulonglong)uVar5 + param_3) =
           s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[*(byte *)((ulonglong)uVar6 + param_1) >> 2];
      *(char *)((ulonglong)(uVar5 + 1) + param_3) =
           s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000
           [(ulonglong)(*(byte *)((ulonglong)uVar6 + param_1) & 3) << 4 |
            (ulonglong)(*(byte *)((ulonglong)(uVar6 + 1) + param_1) >> 4)];
      *(char *)((ulonglong)(uVar5 + 2) + param_3) =
           s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000
           [(ulonglong)(*(byte *)((ulonglong)(uVar6 + 1) + param_1) & 0xf) << 2 |
            (ulonglong)(*(byte *)((ulonglong)(uVar6 + 2) + param_1) >> 6)];
      *(char *)((ulonglong)(uVar5 + 3) + param_3) =
           s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000
           [*(byte *)((ulonglong)(uVar6 + 2) + param_1) & 0x3f];
      uVar5 = uVar5 + 4;
      uVar6 = uVar7;
    } while (uVar7 < uVar3);
  }
  if (param_2 % 3 == 1) {
    bVar1 = *(byte *)((ulonglong)uVar7 + param_1);
    *(char *)((ulonglong)uVar5 + param_3) = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[bVar1 >> 2]
    ;
    cVar4 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[0x40];
    *(char *)((ulonglong)(uVar5 + 1) + param_3) =
         s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[(bVar1 & 3) << 4];
    *(char *)((ulonglong)(uVar5 + 2) + param_3) = cVar4;
  }
  else {
    if (param_2 % 3 != 2) {
      return uVar5;
    }
    bVar1 = *(byte *)((ulonglong)uVar7 + param_1);
    bVar2 = *(byte *)((ulonglong)(uVar7 + 1) + param_1);
    *(char *)((ulonglong)uVar5 + param_3) = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[bVar1 >> 2]
    ;
    *(char *)((ulonglong)(uVar5 + 1) + param_3) =
         s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000
         [(ulonglong)((bVar1 & 3) << 4) | (ulonglong)(bVar2 >> 4)];
    *(char *)((ulonglong)(uVar5 + 2) + param_3) =
         s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[(bVar2 & 0xf) << 2];
    cVar4 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_140012000[0x40];
  }
  *(char *)((ulonglong)(uVar5 + 3) + param_3) = cVar4;
  return uVar5 + 4;
}



===== encode_challenge @ 140001fcc =====

int encode_challenge(undefined1 *param_1,byte *param_2,uint param_3,char param_4)

{
  uint uVar1;
  
  *param_1 = 0x30;
  if (param_4 == '\x01') {
    param_1[1] = 0x78;
    uVar1 = encode_hex_string(param_2,param_3,(longlong)(param_1 + 2));
  }
  else {
    if (param_4 != '\x02') {
      return -0x1a;
    }
    param_1[1] = 0x62;
    uVar1 = encode_base64_string((longlong)param_2,param_3,(longlong)(param_1 + 2));
  }
  return uVar1 + 2;
}



===== encode_hex_string @ 14000201c =====

int encode_hex_string(byte *param_1,uint param_2,longlong param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  char *pcVar5;
  ulonglong uVar6;
  int iVar7;
  ulonglong uVar8;
  
  iVar7 = 0;
  uVar6 = 0;
  if (param_2 != 0) {
    uVar8 = (ulonglong)param_2;
    do {
      pcVar5 = (char *)(uVar6 + param_3);
      RtlStringCchPrintfA(pcVar5,0x7fffffff,"%02x",(ulonglong)*param_1);
      iVar1 = 0;
      if (pcVar5 == (char *)0x0) {
        uVar4 = 0xc000000d;
      }
      else {
        lVar3 = 0x7fffffff;
        do {
          if (*pcVar5 == '\0') break;
          pcVar5 = pcVar5 + 1;
          lVar3 = lVar3 + -1;
        } while (lVar3 != 0);
        uVar4 = ~-(uint)(lVar3 != 0) & 0xc000000d;
        if (lVar3 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0x7fffffff - (int)lVar3;
        }
      }
      iVar2 = 0;
      if (-1 < (int)uVar4) {
        iVar2 = iVar1;
      }
      param_1 = param_1 + 1;
      iVar7 = iVar7 + iVar2;
      uVar6 = (ulonglong)((int)uVar6 + 2);
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return iVar7;
}



===== get_keyval_string @ 1400020e0 =====

int get_keyval_string(uint param_1,char *param_2,undefined1 *param_3,undefined8 *param_4)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  rsize_t _DstSize;
  ulonglong uVar6;
  
  cVar3 = *param_2;
  _DstSize = 0;
  while (((uVar5 = (uint)_DstSize, cVar3 != '\0' && (cVar3 != '=')) && (uVar5 < param_1))) {
    _DstSize = (rsize_t)(uVar5 + 1);
    cVar3 = param_2[_DstSize];
  }
  if (param_2[_DstSize] == '=') {
    memcpy_s(param_3,_DstSize,param_2,_DstSize);
    param_3[_DstSize] = 0;
    uVar5 = uVar5 + 1;
    uVar6 = (ulonglong)uVar5;
    *param_4 = param_2 + uVar6;
    cVar3 = param_2[uVar6];
    while ((cVar3 != '\0' && (uVar5 = (uint)uVar6, uVar5 < param_1))) {
      uVar5 = uVar5 + 1;
      uVar6 = (ulonglong)uVar5;
      cVar3 = param_2[uVar6];
    }
    uVar2 = uVar5 - 1;
    if (uVar5 != param_1) {
      uVar2 = uVar5;
    }
    if (param_2[uVar2] == '\0') {
      return uVar2 + 1;
    }
    uVar1 = *param_3;
    pcVar4 = "key-value pair %s, not terminated with NULL.\n";
  }
  else {
    uVar1 = *param_3;
    pcVar4 = "key-value pair %s, missing \"=\".\n";
  }
  DbgPrint(pcVar4,uVar1);
  return 0;
}



===== get_random_bytes @ 1400021a0 =====

void get_random_bytes(char *param_1,uint param_2)

{
  char cVar1;
  ulonglong uVar2;
  
  cVar1 = KeQueryTimeIncrement();
  if (0 < (int)param_2) {
    uVar2 = (ulonglong)param_2;
    do {
      *param_1 = cVar1;
      param_1 = param_1 + 1;
      cVar1 = cVar1 + '\x01';
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== init_iscsi_params @ 1400021d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_iscsi_params(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 in_R9;
  
  memset(&DAT_140017e48,0,0x254);
  RtlStringCchPrintfA(&DAT_140017e60,0x7fffffff,"No",in_R9);
  RtlStringCchPrintfA(&DAT_140017e64,0x7fffffff,"No",in_R9);
  pcVar1 = "CRC32C";
  pcVar2 = "CRC32C";
  if (*(char *)(DAT_140018200 + 0x45d) == '\0') {
    pcVar2 = "None";
  }
  RtlStringCchPrintfA(&DAT_140017e68,0x7fffffff,pcVar2,in_R9);
  if (*(char *)(DAT_140018200 + 0x45e) == '\0') {
    pcVar1 = "None";
  }
  RtlStringCchPrintfA(&DAT_140017e77,0x7fffffff,pcVar1,in_R9);
  RtlStringCchPrintfA(&DAT_140017e58,0x7fffffff,"8192",in_R9);
  RtlStringCchPrintfA(&DAT_140017e50,0x7fffffff,"16384",in_R9);
  RtlStringCchPrintfA(&DAT_140017e48,0x7fffffff,"8192",in_R9);
  page_align_dmabuf();
  DAT_1400180d8 = DAT_1400180d0;
  DAT_1400180e0 = _DAT_1400180c8;
  _DAT_1400180c8 = _DAT_1400180c8 + 0x1000;
  DAT_1400180d0 = DAT_1400180d0 + 0x1000;
  return;
}



===== iscsi_login_secure @ 140002304 =====

undefined8 iscsi_login_secure(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  gdmpDevExtension = 0;
  iscsi_send_login_secure();
  get_resp(0,0x42);
  if (gdmpDevExtension == 1) {
    iscsi_send_login_secure();
    get_resp(0,0x42);
    if (gdmpDevExtension == 2) {
      iscsi_send_login_secure();
      get_resp(0,0x42);
      if (gdmpDevExtension == 4) {
        uVar1 = DbgPrint("secured login completed!!\n");
        return uVar1 & 0xffffffffffffff00;
      }
      pcVar3 = "statemachine broke at AUTH_INITIATOR_RESPONSE\n";
    }
    else {
      pcVar3 = "statemachine broke at AUTH_INITIATOR_CHALLENGE\n";
    }
  }
  else {
    pcVar3 = "statemachine broke at AUTH_INITIATOR_NONE\n";
  }
  uVar2 = DbgPrint(pcVar3);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== iscsi_send_dataoutpdu @ 140002394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iscsi_send_dataoutpdu
               (longlong param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               char param_7)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 auStackY_398 [32];
  undefined4 local_358 [4];
  uint local_348 [4];
  undefined8 local_338;
  uint local_330;
  undefined8 local_320;
  uint local_318;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_398;
  uVar3 = 0;
  local_358[0] = 0;
  if ((param_1 != 0) && (DAT_1400180d8 != (void *)0x0)) {
    memset(DAT_1400180d8,0,0x1000);
    uVar2 = setup_iscsi_dataout_cmd(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    uVar1 = (uint)uVar2;
    local_348[0] = 2;
    local_338 = DAT_1400180e0;
    local_330 = uVar1;
    if ((uVar2 & 3) != 0) {
      local_330 = (uVar1 - (uVar1 & 3)) + 4;
    }
    local_320 = StorPortGetPhysicalAddress
                          (DAT_140018238,param_1,(ulonglong)param_2 + *(longlong *)(param_1 + 0x18),
                           local_358);
    uVar3 = param_3 + uVar1;
    local_318 = param_3;
    if ((param_3 & 3) != 0) {
      local_318 = (param_3 - (param_3 & 3)) + 4;
    }
    DAT_140018210 = DAT_140018210 + param_3 + uVar1;
  }
  dump_send_ofld_wr(uVar3,local_348);
  return;
}



===== iscsi_send_login_secure @ 1400024c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iscsi_send_login_secure(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_R9;
  undefined1 auStack_348 [32];
  uint local_328 [4];
  undefined8 local_318;
  uint local_310;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_348;
  uVar3 = 0;
  uVar4 = 0x1000;
  memset(DAT_1400180d8,0,0x1000);
  uVar2 = setup_login_pdu('\x01',uVar3,uVar4,in_R9);
  uVar1 = (uint)uVar2;
  local_328[0] = 1;
  local_310 = uVar1;
  if ((uVar2 & 3) != 0) {
    local_310 = (uVar1 - (uVar1 & 3)) + 4;
  }
  local_318 = DAT_1400180e0;
  dump_send_ofld_wr(uVar1,local_328);
  return;
}



===== iscsi_send_scsicmd @ 140002550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iscsi_send_scsicmd(int param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auStack_348 [32];
  uint local_328 [4];
  undefined8 local_318;
  uint local_310;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_348;
  uVar3 = 0;
  uVar1 = 0;
  if (param_1 == 0) {
    if (DAT_140018200 == -0x11c) {
      RtlStringCchPrintfA((char *)0x0,0x7fffffff,"iqn.2004-05.com.chelsio.dumper",0);
    }
    uVar4 = 0;
    uVar5 = 0x1000;
    memset(DAT_1400180d8,0,0x1000);
    uVar2 = setup_login_pdu('\0',uVar4,uVar5,uVar3);
    uVar1 = (uint)uVar2;
LAB_140002690:
    local_310 = uVar1;
    if ((uVar1 & 3) != 0) {
      local_310 = (uVar1 - (uVar1 & 3)) + 4;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 0) {
      return;
    }
    if (DAT_1400180d8 == (void *)0x0) {
      return;
    }
    memset(DAT_1400180d8,0,0x1000);
    uVar2 = setup_iscsi_scsi_cmd(param_2,0,0);
    DAT_14001809c = DAT_14001809c + 1;
    uVar1 = (uint)uVar2;
    DAT_1400180a0 = DAT_1400180a0 + 1;
    DAT_1400180a4 = DAT_1400180a4 + 1;
    local_310 = uVar1;
    if ((uVar2 & 3) != 0) {
      local_310 = (uVar1 - (uVar1 & 3)) + 4;
    }
    DAT_140018210 = DAT_140018210 + uVar1;
  }
  else {
    if (param_1 == 2) {
      memset(DAT_1400180d8,0,0x1000);
      uVar3 = setup_logout_pdu();
      uVar1 = (uint)uVar3;
      goto LAB_140002690;
    }
    if (param_1 != 3) goto LAB_1400026bc;
    memset(DAT_1400180d8,0,0x1000);
    uVar2 = setup_nopout_pdu();
    uVar1 = (uint)uVar2;
    local_310 = uVar1;
    if ((uVar2 & 3) != 0) {
      local_310 = (uVar1 - (uVar1 & 3)) + 4;
    }
  }
  local_318 = DAT_1400180e0;
  local_328[0] = 1;
LAB_1400026bc:
  dump_send_ofld_wr(uVar1,local_328);
  return;
}



===== iscsi_send_writecmd @ 1400026ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iscsi_send_writecmd(undefined8 param_1,longlong param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  uint uVar2;
  undefined1 auStack_368 [32];
  undefined4 local_348 [4];
  uint local_338 [4];
  undefined8 local_328;
  uint local_320;
  undefined8 local_310;
  uint local_308;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_368;
  uVar2 = 0;
  if ((param_2 != 0) && (DAT_1400180d8 != (void *)0x0)) {
    memset(DAT_1400180d8,0,0x1000);
    uVar1 = setup_iscsi_scsi_cmd(param_2,(ulonglong)param_3,param_4);
    uVar2 = (uint)uVar1;
    DAT_14001809c = DAT_14001809c + 1;
    DAT_1400180a0 = DAT_1400180a0 + 1;
    DAT_1400180a4 = DAT_1400180a4 + 1;
    local_338[0] = 1;
    local_320 = uVar2;
    if ((uVar1 & 3) != 0) {
      local_320 = (uVar2 - (uVar2 & 3)) + 4;
    }
    DAT_140018210 = DAT_140018210 + uVar2;
    local_328 = DAT_1400180e0;
    if (DAT_140018094 != '\0') {
      local_348[0] = 0;
      local_310 = StorPortGetPhysicalAddress
                            (DAT_140018238,param_2,*(undefined8 *)(param_2 + 0x18),local_348);
      local_338[0] = 2;
      local_308 = param_4;
      if ((param_4 & 3) != 0) {
        local_308 = (param_4 - (param_4 & 3)) + 4;
      }
      uVar2 = uVar2 + param_4;
      DAT_140018210 = DAT_140018210 + *(int *)(param_2 + 0x10);
    }
  }
  dump_send_ofld_wr(uVar2,local_338);
  return;
}



===== processNonDdpIscsiPdu @ 14000281c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void processNonDdpIscsiPdu
               (longlong param_1,byte *param_2,undefined8 param_3,void *param_4,uint param_5)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  char *pcVar8;
  byte bVar9;
  ulonglong _DstSize;
  void *pvVar10;
  undefined1 auStack_158 [32];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_158;
  bVar9 = *param_2;
  if ((0x3f < (bVar9 & 0x3f)) || ((0xf006007f00000000U >> ((ulonglong)bVar9 & 0x3f) & 1) == 0)) {
    DbgPrint("We received a non target opcode!!\n");
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  bVar9 = bVar9 & 0x3f;
  if (bVar9 == 0x20) {
    DbgDmp((longlong)param_2,(int)param_3);
    DAT_140017e40 = *(undefined4 *)(param_2 + 0x14);
    iscsi_send_scsicmd(3,0);
    return;
  }
  if (bVar9 == 0x21) {
    bVar9 = param_2[3];
    if (bVar9 == 0) {
      if (param_1 != 0) {
        *(undefined1 *)(param_1 + 3) = 1;
      }
    }
    else {
      DbgPrint("status = 0x%x Failure!!\n",bVar9);
      if (param_1 != 0) {
        *(undefined1 *)(param_1 + 3) = 4;
      }
    }
    DAT_140017e45 = 1;
LAB_140002a3a:
    *(byte *)(param_1 + 4) = bVar9;
  }
  else {
    if (bVar9 == 0x23) {
      sVar1 = *(short *)(param_2 + 0x24);
      pvVar10 = param_4;
      DbgPrint("ISCSI LOGIN RESP got !!! status = %d\n",sVar1);
      if (sVar1 == 0) {
        DbgPrint(&s_iscsi_login_response__>_);
        if (gdmpDevExtension == 4) {
          process_login_keys((longlong)param_4,param_5,param_3,pvVar10);
        }
        if (DAT_140017e04 == 0) {
          return;
        }
        DAT_1400180a0 = DAT_1400180a0 + 1;
        if (gdmpDevExtension == 0) {
          gdmpDevExtension = 1;
          return;
        }
        if (gdmpDevExtension == 1) {
          process_login_keys_auth((longlong)param_4,param_5,param_3,pvVar10);
          process_challenge(&DAT_140017e87,DAT_140017e86);
          gdmpDevExtension = 2;
          return;
        }
        if (gdmpDevExtension != 2) {
          return;
        }
        if (DAT_140017e04 == 2) {
          uVar7 = srch_kvpair(param_5,(longlong)param_4,"CHAP_N",local_138);
          if ((int)uVar7 != 0) {
            return;
          }
          uVar7 = srch_kvpair(param_5,(longlong)param_4,"CHAP_R",local_138);
          if ((int)uVar7 != 0) {
            return;
          }
        }
        gdmpDevExtension = 4;
        return;
      }
      pcVar8 = "Login Failed!!!!\n";
    }
    else {
      if (bVar9 == 0x25) {
        bVar9 = param_2[3];
        DbgPrint("ISCSI_OPCODE_SCSI_DATA_IN got!! status = %d\n",bVar9);
        if (bVar9 == 0) {
          DbgPrint("scsi response ->\n");
          if (param_1 == 0) {
            return;
          }
          _DstSize = (ulonglong)param_5;
          if (*(uint *)(param_1 + 0x10) < param_5) {
            DbgPrint("more data received!! pldlen = %d expected len = %d",_DstSize);
            *(uint *)(param_1 + 0x10) = param_5;
          }
          else {
            DbgPrint("copied response data.. resp payload len = 0x%x\n",_DstSize);
            memcpy_s(*(void **)(param_1 + 0x18),_DstSize,param_4,_DstSize);
            *(undefined1 *)(param_1 + 3) = 1;
          }
        }
        else {
          if (param_1 == 0) {
            return;
          }
          *(undefined1 *)(param_1 + 3) = 4;
        }
        goto LAB_140002a3a;
      }
      if (bVar9 == 0x26) {
        sVar1 = *(short *)(param_2 + 0x24);
        DbgPrint("ISCSI LOGOUT RESP got !!! status = %d\n",sVar1);
        if (sVar1 == 0) {
          return;
        }
        pcVar8 = "Logout Failed!!!!\n";
      }
      else {
        if (bVar9 == 0x31) {
          if (param_1 == 0) {
            DAT_00000003 = 4;
            return;
          }
          uVar2 = *(uint *)(param_2 + 0x28);
          uVar3 = *(uint *)(param_2 + 0x10);
          uVar4 = *(uint *)(param_2 + 0x14);
          uVar5 = *(uint *)(param_2 + 0x2c);
          DAT_140017e44 = 1;
          DAT_140017e30 =
               (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8;
          DAT_140017e34 =
               uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
          DAT_140017e3c =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          DAT_140017e38 =
               uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
          *(undefined1 *)(param_1 + 3) = 1;
          return;
        }
        if (bVar9 != 0x32) {
          if (bVar9 == 0x3f) {
            DbgPrint("ISCSI REJECT Received !! reason 0x%x\n",param_2[2]);
            DbgPrint("REJECT PDU is --\n");
            DbgDmp((longlong)param_2,(int)param_3);
            return;
          }
          return;
        }
        DbgPrint("ISCSI Async message.. doing logout!!\n");
        iscsi_send_scsicmd(2,0);
        DbgPrint("Closed the Dumpmode iscsi session\n");
        dump_close_conn_wr();
        pcVar8 = "Closed the dump mode tcp connection\n";
      }
    }
    DbgPrint(pcVar8);
  }
  return;
}



===== process_challenge @ 140002bb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void process_challenge(char *param_1,undefined1 param_2)

{
  undefined1 auStackY_158 [32];
  char local_128 [4];
  uint local_124;
  undefined8 *local_120;
  byte local_118 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  local_120 = (undefined8 *)0x0;
  local_128[0] = '\0';
  local_124 = 0;
  decode_encoded_chal(param_1,&local_120,local_128,&local_124);
  chap_calc_md5_digest
            (param_2,(undefined8 *)(DAT_140018200 + 0x31c),local_120,local_124,
             (undefined8 *)local_118);
  encode_challenge(&DAT_140017f87,local_118,0x10,local_128[0]);
  return;
}



===== process_iscsi_pdu @ 140002c58 =====

undefined8 process_iscsi_pdu(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  uint uVar3;
  void *pvVar4;
  
  if (DAT_140018228 == 0) {
    if (((*(uint *)(param_1 + 0x14) & 0xffffff) >> 8 & 1) != 0) {
      if ((char)(*(uint *)(param_1 + 0x14) >> 0x18) == '\0') {
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      return 0;
    }
    uVar3 = 0;
    pvVar4 = (void *)0x0;
  }
  else {
    uVar3 = (uint)(byte)*(ushort *)(DAT_140018228 + 6) << 8 |
            (uint)(*(ushort *)(DAT_140018228 + 6) >> 8);
    pvVar4 = (void *)(DAT_140018228 + 0x10);
  }
  processNonDdpIscsiPdu
            (param_2,(byte *)(DAT_140018220 + 0x10),
             (ulonglong)
             ((uint)(byte)*(ushort *)(DAT_140018220 + 6) << 8 |
             (uint)(*(ushort *)(DAT_140018220 + 6) >> 8)),pvVar4,uVar3);
  return 0;
}



===== process_login_keys @ 140002cd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void process_login_keys(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  ulonglong uVar4;
  char *pcVar5;
  undefined *puVar6;
  ulonglong uVar7;
  undefined1 auStack_1a8 [32];
  char local_188 [64];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  RtlStringCchPrintfA(local_188,0x3f,"HeaderDigest",param_4);
  pcVar5 = local_148;
  uVar3 = srch_kvpair(param_2,param_1,local_188,pcVar5);
  if ((int)uVar3 != 0) {
    RtlStringCchPrintfA(local_148,0xff,"None",pcVar5);
  }
  puVar6 = &DAT_140017e68;
  DbgPrint(&s__s__Tgt____s_Ini____s_,local_188,local_148);
  DAT_140018096 = *(undefined1 *)(DAT_140018200 + 0x45d);
  RtlStringCchPrintfA(local_188,0x3f,"DataDigest",puVar6);
  pcVar5 = local_148;
  uVar3 = srch_kvpair(param_2,param_1,local_188,pcVar5);
  if ((int)uVar3 != 0) {
    RtlStringCchPrintfA(local_148,0xff,"None",pcVar5);
  }
  puVar6 = &DAT_140017e77;
  DbgPrint(&s__s__Tgt____s_Ini____s_,local_188,local_148);
  DAT_140018097 = *(undefined1 *)(DAT_140018200 + 0x45e);
  RtlStringCchPrintfA(local_188,0x3f,"MaxRecvDataSegmentLength",puVar6);
  uVar3 = srch_kvpair(param_2,param_1,local_188,local_148);
  if ((int)uVar3 == 0) {
    uVar1 = strtoul(local_148,(char **)0x0,10);
    uVar4 = CONCAT44(extraout_var,uVar1);
  }
  else {
    uVar4 = 0x2000;
  }
  uVar1 = strtoul(&DAT_140017e48,(char **)0x0,10);
  uVar7 = CONCAT44(extraout_var_00,uVar1);
  DbgPrint("%s: Tgt = %d Ini = %d\n",local_188,uVar4);
  DAT_140018088 = (uint)uVar4;
  if (CONCAT44(extraout_var_00,uVar1) < uVar4) {
    DAT_140018088 = uVar1;
  }
  if ((DAT_140018088 & 0x1ff) != 0) {
    DAT_140018088 = DAT_140018088 & 0xfffffe00;
  }
  RtlStringCchPrintfA(local_188,0x3f,"FirstBurstLength",uVar7);
  uVar3 = srch_kvpair(param_2,param_1,local_188,local_148);
  if ((int)uVar3 == 0) {
    uVar1 = strtoul(local_148,(char **)0x0,10);
    uVar4 = CONCAT44(extraout_var_01,uVar1);
  }
  else {
    uVar4 = 0x10000;
  }
  uVar1 = strtoul(&DAT_140017e58,(char **)0x0,10);
  uVar7 = CONCAT44(extraout_var_02,uVar1);
  DbgPrint("%s: Tgt = %d Ini = %d\n",local_188,uVar4);
  _DAT_140018090 = (ulong)uVar4;
  if (CONCAT44(extraout_var_02,uVar1) < uVar4) {
    _DAT_140018090 = uVar1;
  }
  RtlStringCchPrintfA(local_188,0x3f,"MaxBurstLength",uVar7);
  uVar3 = srch_kvpair(param_2,param_1,local_188,local_148);
  if ((int)uVar3 == 0) {
    uVar1 = strtoul(local_148,(char **)0x0,10);
    uVar4 = CONCAT44(extraout_var_03,uVar1);
  }
  else {
    uVar4 = 0x40000;
  }
  uVar1 = strtoul(&DAT_140017e50,(char **)0x0,10);
  uVar7 = CONCAT44(extraout_var_04,uVar1);
  DbgPrint("%s: Tgt = %d Ini = %d\n",local_188,uVar4);
  DAT_14001808c = (ulong)uVar4;
  if (CONCAT44(extraout_var_04,uVar1) < uVar4) {
    DAT_14001808c = uVar1;
  }
  RtlStringCchPrintfA(local_188,0x3f,"ImmediateData",uVar7);
  pcVar5 = local_148;
  uVar3 = srch_kvpair(param_2,param_1,local_188,pcVar5);
  if ((int)uVar3 != 0) {
    RtlStringCchPrintfA(local_148,0xff,"Yes",pcVar5);
  }
  puVar6 = &DAT_140017e60;
  DbgPrint(&s__s__Tgt____s_Ini____s_,local_188,local_148);
  iVar2 = strcmp(local_148,"Yes");
  if (iVar2 == 0) {
    iVar2 = strcmp(&DAT_140017e60,"Yes");
    DAT_140018094 = 1;
    if (iVar2 == 0) goto LAB_140003016;
  }
  DAT_140018094 = 0;
LAB_140003016:
  RtlStringCchPrintfA(local_188,0x3f,"InitialR2T",puVar6);
  pcVar5 = local_148;
  uVar3 = srch_kvpair(param_2,param_1,local_188,pcVar5);
  if ((int)uVar3 != 0) {
    RtlStringCchPrintfA(local_148,0xff,"Yes",pcVar5);
  }
  DbgPrint(&s__s__Tgt____s_Ini____s_,local_188,local_148,&DAT_140017e64);
  iVar2 = strcmp(local_148,"Yes");
  DAT_140018095 = iVar2 == 0;
  return;
}



===== process_login_keys_auth @ 1400030b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void process_login_keys_auth(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulong uVar2;
  undefined8 uVar3;
  rsize_t rVar4;
  rsize_t _DstSize;
  char *pcVar5;
  undefined1 auStack_178 [32];
  char local_158 [64];
  char local_118 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  RtlStringCchPrintfA(local_158,0x3f,"CHAP_I",param_4);
  pcVar5 = local_118;
  srch_kvpair(param_2,param_1,local_158,pcVar5);
  uVar2 = strtoul(local_118,(char **)0x0,10);
  DAT_140017e86 = (undefined1)uVar2;
  RtlStringCchPrintfA(local_158,0x3f,"CHAP_C",pcVar5);
  pcVar5 = local_118;
  uVar3 = srch_kvpair(param_2,param_1,local_158,pcVar5);
  if ((int)uVar3 != 0) {
    RtlStringCchPrintfA(local_118,0x7fffffff,"None",pcVar5);
  }
  rVar4 = 0xffffffffffffffff;
  do {
    _DstSize = rVar4 + 1;
    lVar1 = rVar4 + 1;
    rVar4 = _DstSize;
  } while (local_118[lVar1] != '\0');
  memcpy_s(&DAT_140017e87,_DstSize,local_118,_DstSize);
  return;
}



===== setup_iscsi_dataout_cmd @ 1400031a0 =====

undefined8
setup_iscsi_dataout_cmd
          (undefined8 param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
          char param_7)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_1400180d8;
  memset(DAT_1400180d8,0,0x1000);
  *puVar2 = 5;
  puVar2[1] = -(param_7 != '\0') & 0x80;
  *(uint *)(puVar2 + 0x10) =
       param_5 >> 0x18 | (param_5 & 0xff0000) >> 8 | (param_5 & 0xff00) << 8 | param_5 << 0x18;
  puVar2[4] = 0;
  *(undefined8 *)(puVar2 + 8) = 0;
  *(uint *)(puVar2 + 0x14) =
       param_4 >> 0x18 | (param_4 & 0xff0000) >> 8 | (param_4 & 0xff00) << 8 | param_4 << 0x18;
  uVar3 = DAT_14001809c & 0xff00;
  uVar5 = DAT_14001809c << 0x10;
  uVar4 = DAT_14001809c >> 8;
  uVar1 = DAT_14001809c >> 0x18;
  *(uint *)(puVar2 + 4) =
       param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 | param_3 << 0x18;
  *(uint *)(puVar2 + 0x24) =
       param_6 >> 0x18 | (param_6 & 0xff0000) >> 8 | (param_6 & 0xff00) << 8 | param_6 << 0x18;
  *(uint *)(puVar2 + 0x1c) = (uVar5 | uVar3) << 8 | uVar4 & 0xff00 | uVar1;
  *(uint *)(puVar2 + 0x28) =
       param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
  *(undefined4 *)(puVar2 + 0x30) = 0;
  return 0x30;
}



===== setup_iscsi_scsi_cmd @ 14000325c =====

undefined8 setup_iscsi_scsi_cmd(longlong param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  
  puVar2 = DAT_1400180d8;
  memset(DAT_1400180d8,0,0x1000);
  puVar2[1] = puVar2[1] | 0xc0;
  *(undefined8 *)(puVar2 + 8) = 0;
  puVar2[4] = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  *puVar2 = 1;
  *(uint *)(puVar2 + 0x10) =
       (DAT_1400180a4 << 0x10 | DAT_1400180a4 & 0xff00) << 8 | DAT_1400180a4 >> 8 & 0xff00 |
       DAT_1400180a4 >> 0x18;
  uVar1 = *(uint *)(param_1 + 0x10);
  *(uint *)(puVar2 + 0x14) =
       (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
  *(uint *)(puVar2 + 0x18) =
       (DAT_14001809c << 0x10 | DAT_14001809c & 0xff00) << 8 | DAT_14001809c >> 8 & 0xff00 |
       DAT_14001809c >> 0x18;
  *(uint *)(puVar2 + 0x1c) =
       (DAT_1400180a0 << 0x10 | DAT_1400180a0 & 0xff00) << 8 | DAT_1400180a0 >> 8 & 0xff00 |
       DAT_1400180a0 >> 0x18;
  memcpy_s(puVar2 + 0x20,0x10,(void *)(param_1 + 0x48),0x10);
  if ((*(char *)(param_1 + 0x48) == '*') && (puVar2[1] = 0xa0, DAT_140018094 != '\0')) {
    *(uint *)(puVar2 + 4) =
         param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 | param_3 << 0x18;
  }
  return 0x30;
}



===== setup_login_pdu @ 140003388 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong setup_login_pdu(char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 *puVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  undefined *puVar9;
  ulonglong uVar10;
  undefined1 auStack_258 [32];
  uint local_238 [4];
  undefined2 local_228;
  undefined1 local_226 [254];
  char local_128 [256];
  ulonglong local_28;
  
  puVar1 = DAT_1400180d8;
  local_28 = __security_cookie ^ (ulonglong)auStack_258;
  memset(DAT_1400180d8,0,0x1000);
  lVar7 = 0;
  *puVar1 = 0x43;
  if (param_1 == '\0') {
    puVar1[1] = puVar1[1] | 0x87;
  }
  else if (gdmpDevExtension == 2) {
    puVar1[1] = 0x81;
  }
  *(undefined2 *)(puVar1 + 2) = 0;
  puVar1[4] = 0;
  *(undefined8 *)(puVar1 + 8) = 0x3401436ebe87;
  uVar10 = 0x30;
  *(undefined2 *)(puVar1 + 0xe) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  *(undefined2 *)(puVar1 + 0x14) = 0;
  *(uint *)(puVar1 + 0x18) =
       (DAT_14001809c << 0x10 | DAT_14001809c & 0xff00) << 8 | DAT_14001809c >> 8 & 0xff00 |
       DAT_14001809c >> 0x18;
  *(uint *)(puVar1 + 0x1c) =
       (DAT_1400180a0 << 0x10 | DAT_1400180a0 & 0xff00) << 8 | DAT_1400180a0 >> 8 & 0xff00 |
       DAT_1400180a0 >> 0x18;
  if (param_1 == '\0') {
    pcVar8 = puVar1 + 0x30;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"HeaderDigest=%s",&DAT_140017e68);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar2 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        lVar2 = 0x7fffffff - lVar2;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    pcVar8 = puVar1 + lVar5 + 0x31;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"DataDigest=%s",&DAT_140017e77);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar4 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
      if (lVar4 != 0) {
        lVar2 = 0x7fffffff - lVar4;
      }
    }
    lVar4 = 0;
    if (-1 < (int)uVar3) {
      lVar4 = lVar2;
    }
    lVar4 = lVar5 + 0x32 + lVar4;
    if (DAT_140017e04 == 0) {
      pcVar8 = puVar1 + lVar4;
      RtlStringCchPrintfA(pcVar8,0x7fffffff,"TargetName=%s",DAT_140018200 + 0x1c);
      lVar2 = 0;
      if (pcVar8 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar5 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
        if (lVar5 != 0) {
          lVar2 = 0x7fffffff - lVar5;
        }
      }
      lVar5 = 0;
      if (-1 < (int)uVar3) {
        lVar5 = lVar2;
      }
      lVar6 = DAT_140018200 + 0x11c;
      lVar4 = lVar4 + lVar5 + 1;
      pcVar8 = puVar1 + lVar4;
      RtlStringCchPrintfA(pcVar8,0x7fffffff,"InitiatorName=%s",lVar6);
      lVar2 = 0;
      if (pcVar8 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar5 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
        if (lVar5 != 0) {
          lVar2 = 0x7fffffff - lVar5;
        }
      }
      lVar5 = 0;
      if (-1 < (int)uVar3) {
        lVar5 = lVar2;
      }
      lVar4 = lVar4 + lVar5 + 1;
      pcVar8 = puVar1 + lVar4;
      RtlStringCchPrintfA(pcVar8,0x7fffffff,"InitiatorAlias=iscsi_ibft1",lVar6);
      lVar2 = 0;
      if (pcVar8 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar5 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
        uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
        if (lVar5 != 0) {
          lVar2 = 0x7fffffff - lVar5;
        }
      }
      lVar5 = 0;
      if (-1 < (int)uVar3) {
        lVar5 = lVar2;
      }
      lVar4 = lVar4 + 1 + lVar5;
    }
    pcVar8 = puVar1 + lVar4;
    puVar9 = &DAT_140017e48;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"MaxRecvDataSegmentLength=%s",&DAT_140017e48);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"OFMarker=No",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"IFMarker=No",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"MaxConnections=1",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    puVar9 = &DAT_140017e64;
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"InitialR2T=%s",&DAT_140017e64);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"MaxOutstandingR2T=1",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"ImmediateData=%s",&DAT_140017e60);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"FirstBurstLength=%s",&DAT_140017e58);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    puVar9 = &DAT_140017e50;
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = lVar4 + lVar5 + 1;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"MaxBurstLength=%s",&DAT_140017e50);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar5 = lVar4 + 1 + lVar5;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"DefaultTime2Wait=2",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar4 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
      if (lVar4 != 0) {
        lVar2 = 0x7fffffff - lVar4;
      }
    }
    lVar4 = 0;
    if (-1 < (int)uVar3) {
      lVar4 = lVar2;
    }
    lVar4 = lVar5 + 1 + lVar4;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"DefaultTime2Retain=20",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar5 = lVar4 + 1 + lVar5;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"DataPDUInOrder=Yes",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar4 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
      if (lVar4 != 0) {
        lVar2 = 0x7fffffff - lVar4;
      }
    }
    lVar4 = 0;
    if (-1 < (int)uVar3) {
      lVar4 = lVar2;
    }
    lVar4 = lVar5 + 1 + lVar4;
    pcVar8 = puVar1 + lVar4;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"DataSequenceInOrder=Yes",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar5 = lVar4 + 1 + lVar5;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"ErrorRecoveryLevel=0",puVar9);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar4 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
      if (lVar4 != 0) {
        lVar2 = 0x7fffffff - lVar4;
      }
    }
    lVar4 = 0;
    if (-1 < (int)uVar3) {
      lVar4 = lVar2;
    }
    uVar10 = lVar4 + 1 + lVar5;
    if (DAT_140017e04 == 0) {
      pcVar8 = puVar1 + uVar10;
      RtlStringCchPrintfA(pcVar8,0x7fffffff,"SessionType=Normal",puVar9);
      lVar2 = 0;
      if (pcVar8 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar2 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar2 = lVar2 + -1;
        } while (lVar2 != 0);
        uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
        if (lVar2 == 0) {
          lVar2 = 0;
        }
        else {
          lVar2 = 0x7fffffff - lVar2;
        }
      }
      if (-1 < (int)uVar3) {
        lVar7 = lVar2;
      }
      uVar10 = uVar10 + 1 + lVar7;
    }
    goto LAB_140004040;
  }
  if (gdmpDevExtension == 0) {
    pcVar8 = puVar1 + 0x30;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"TargetName=%s",DAT_140018200 + 0x1c);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar2 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        lVar2 = 0x7fffffff - lVar2;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar4 = DAT_140018200 + 0x11c;
    pcVar8 = puVar1 + lVar5 + 0x31;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"InitiatorName=%s",lVar4);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar6 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      uVar3 = ~-(uint)(lVar6 != 0) & 0xc000000d;
      if (lVar6 != 0) {
        lVar2 = 0x7fffffff - lVar6;
      }
    }
    lVar6 = 0;
    if (-1 < (int)uVar3) {
      lVar6 = lVar2;
    }
    lVar5 = lVar5 + lVar6 + 0x32;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"InitiatorAlias=iscsi_ibft1",lVar4);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar6 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      uVar3 = ~-(uint)(lVar6 != 0) & 0xc000000d;
      if (lVar6 != 0) {
        lVar2 = 0x7fffffff - lVar6;
      }
    }
    lVar6 = 0;
    if (-1 < (int)uVar3) {
      lVar6 = lVar2;
    }
    lVar5 = lVar5 + lVar6 + 1;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"AuthMethod=CHAP",lVar4);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar6 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      uVar3 = ~-(uint)(lVar6 != 0) & 0xc000000d;
      if (lVar6 != 0) {
        lVar2 = 0x7fffffff - lVar6;
      }
    }
    lVar6 = 0;
    if (-1 < (int)uVar3) {
      lVar6 = lVar2;
    }
    lVar5 = lVar5 + lVar6 + 1;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"SessionType=Normal",lVar4);
    if (pcVar8 != (char *)0x0) {
      lVar2 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      goto LAB_1400038b9;
    }
LAB_1400038d7:
    uVar3 = 0xc000000d;
    lVar2 = 0;
  }
  else {
    if (gdmpDevExtension == 1) {
      pcVar8 = puVar1 + 0x30;
      RtlStringCchPrintfA(pcVar8,0x7fffffff,"CHAP_A=5,7",param_4);
      lVar2 = 0;
      if (pcVar8 == (char *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar2 = 0x7fffffff;
        do {
          if (*pcVar8 == '\0') break;
          pcVar8 = pcVar8 + 1;
          lVar2 = lVar2 + -1;
        } while (lVar2 != 0);
        uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
        if (lVar2 == 0) {
          lVar2 = 0;
        }
        else {
          lVar2 = 0x7fffffff - lVar2;
        }
      }
      if (-1 < (int)uVar3) {
        lVar7 = lVar2;
      }
      uVar10 = lVar7 + 0x31;
      goto LAB_140004040;
    }
    if (gdmpDevExtension != 2) goto LAB_140004040;
    pcVar8 = puVar1 + 0x30;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"CHAP_N=%s",DAT_140018200 + 0x21c);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar2 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        lVar2 = 0x7fffffff - lVar2;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    pcVar8 = puVar1 + lVar5 + 0x31;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"CHAP_R=%s",&DAT_140017f87);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar4 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
      if (lVar4 != 0) {
        lVar2 = 0x7fffffff - lVar4;
      }
    }
    lVar4 = 0;
    if (-1 < (int)uVar3) {
      lVar4 = lVar2;
    }
    uVar10 = lVar4 + 0x32 + lVar5;
    if (DAT_140017e04 != 2) goto LAB_140004040;
    local_238[0] = 0;
    memset(local_128,0,0x100);
    memset(&local_228,0,0x100);
    get_random_bytes((char *)local_238,1);
    get_random_bytes(local_128,0x10);
    local_228 = 0x6230;
    encode_base64_string((longlong)local_128,0x10,(longlong)local_226);
    pcVar8 = puVar1 + uVar10;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"CHAP_I=%d",(ulonglong)local_238[0]);
    lVar2 = 0;
    if (pcVar8 == (char *)0x0) {
      uVar3 = 0xc000000d;
    }
    else {
      lVar5 = 0x7fffffff;
      do {
        if (*pcVar8 == '\0') break;
        pcVar8 = pcVar8 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar3 = ~-(uint)(lVar5 != 0) & 0xc000000d;
      if (lVar5 != 0) {
        lVar2 = 0x7fffffff - lVar5;
      }
    }
    lVar5 = 0;
    if (-1 < (int)uVar3) {
      lVar5 = lVar2;
    }
    lVar5 = lVar5 + uVar10 + 1;
    pcVar8 = puVar1 + lVar5;
    RtlStringCchPrintfA(pcVar8,0x7fffffff,"CHAP_C=%s",&local_228);
    if (pcVar8 == (char *)0x0) goto LAB_1400038d7;
    lVar2 = 0x7fffffff;
    do {
      if (*pcVar8 == '\0') break;
      pcVar8 = pcVar8 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
LAB_1400038b9:
    uVar3 = ~-(uint)(lVar2 != 0) & 0xc000000d;
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    else {
      lVar2 = 0x7fffffff - lVar2;
    }
  }
  if (-1 < (int)uVar3) {
    lVar7 = lVar2;
  }
  uVar10 = lVar7 + 1 + lVar5;
LAB_140004040:
  DbgPrint("DataSegmentLength = %d\n",uVar10 - 0x30);
  uVar3 = (int)uVar10 - 0x30;
  *(uint *)(puVar1 + 4) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 * 0x1000000;
  return uVar10 & 0xffffffff;
}



===== setup_logout_pdu @ 140004090 =====

undefined8 setup_logout_pdu(void)

{
  uint uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_1400180d8;
  memset(DAT_1400180d8,0,0x1000);
  *puVar2 = 0x8046;
  *(undefined4 *)(puVar2 + 2) = 0;
  uVar5 = DAT_1400180a4 << 0x10;
  uVar3 = DAT_1400180a4 & 0xff00;
  uVar4 = DAT_1400180a4 >> 8;
  uVar1 = DAT_1400180a4 >> 0x18;
  puVar2[10] = 0;
  *(uint *)(puVar2 + 8) = (uVar5 | uVar3) << 8 | uVar4 & 0xff00 | uVar1;
  *(uint *)(puVar2 + 0xc) =
       (DAT_14001809c << 0x10 | DAT_14001809c & 0xff00) << 8 | DAT_14001809c >> 8 & 0xff00 |
       DAT_14001809c >> 0x18;
  *(uint *)(puVar2 + 0xe) =
       (DAT_1400180a0 << 0x10 | DAT_1400180a0 & 0xff00) << 8 | DAT_1400180a0 >> 8 & 0xff00 |
       DAT_1400180a0 >> 0x18;
  return 0x30;
}



===== setup_nopout_pdu @ 14000414c =====

undefined8 setup_nopout_pdu(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_1400180d8;
  memset(DAT_1400180d8,0,0x1000);
  *(undefined4 *)(puVar1 + 8) = 0xffffffff;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined8 *)(puVar1 + 4) = 0;
  *puVar1 = 0x8040;
  *(uint *)(puVar1 + 10) =
       (DAT_140017e40 << 0x10 | DAT_140017e40 & 0xff00) << 8 | DAT_140017e40 >> 8 & 0xff00 |
       DAT_140017e40 >> 0x18;
  *(uint *)(puVar1 + 0xc) =
       (DAT_14001809c << 0x10 | DAT_14001809c & 0xff00) << 8 | DAT_14001809c >> 8 & 0xff00 |
       DAT_14001809c >> 0x18;
  *(uint *)(puVar1 + 0xe) =
       (DAT_1400180a0 << 0x10 | DAT_1400180a0 & 0xff00) << 8 | DAT_1400180a0 >> 8 & 0xff00 |
       DAT_1400180a0 >> 0x18;
  return 0x30;
}



===== srch_kvpair @ 140004208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 srch_kvpair(uint param_1,longlong param_2,char *param_3,char *param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  char local_70 [64];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  uVar6 = 0;
  local_78 = 0;
  if (param_1 != 0) {
    do {
      memset(local_70,0,0x3f);
      iVar3 = get_keyval_string(param_1 - (int)uVar6,(char *)(uVar6 + param_2),local_70,&local_78);
      if (iVar3 == 0) {
        return 1;
      }
      uVar5 = (int)uVar6 + iVar3;
      uVar6 = (ulonglong)uVar5;
      pcVar4 = param_3;
      do {
        cVar1 = *pcVar4;
        cVar2 = pcVar4[(longlong)(local_70 + -(longlong)param_3)];
        if (cVar1 != cVar2) break;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) {
        RtlStringCchPrintfA(param_4,0x7fffffff,"%s",local_78);
        return 0;
      }
    } while (uVar5 < param_1);
  }
  DbgPrint(&s_Could_not_find_the_key__s_,param_3);
  return 1;
}



===== crypto_md5_finish @ 1400042d8 =====

void crypto_md5_finish(uint *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  size_t _Size;
  uint uVar6;
  
  uVar4 = *param_1 >> 3 & 0x3f;
  uVar6 = -uVar4 + 0x3f;
  puVar3 = param_1 + 6;
  *(undefined1 *)((longlong)param_1 + (ulonglong)uVar4 + 0x18) = 0x80;
  puVar2 = (uint *)((longlong)param_1 + (ulonglong)uVar4 + 0x19);
  if (uVar6 < 8) {
    memset(puVar2,0,(ulonglong)uVar6);
    iVar5 = 0x10;
    puVar2 = puVar3;
    do {
      *puVar2 = *puVar2;
      puVar2 = puVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    crypto_md5_transform((int *)(param_1 + 2),(int *)puVar3);
    _Size = 0x38;
    puVar2 = puVar3;
  }
  else {
    _Size = (size_t)(-uVar4 + 0x37);
  }
  memset(puVar2,0,_Size);
  iVar5 = 0xe;
  puVar2 = puVar3;
  do {
    *puVar2 = *puVar2;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1[0x14] = *param_1;
  param_1[0x15] = param_1[1];
  crypto_md5_transform((int *)(param_1 + 2),(int *)puVar3);
  iVar5 = 4;
  puVar3 = param_1 + 2;
  do {
    *puVar3 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar1 = *(undefined8 *)(param_1 + 4);
  *param_2 = *(undefined8 *)(param_1 + 2);
  param_2[1] = uVar1;
  return;
}



===== crypto_md5_init @ 14000440c =====

void crypto_md5_init(void *param_1)

{
  memset(param_1,0,0x58);
  *(undefined4 *)((longlong)param_1 + 8) = 0x67452301;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0xefcdab89;
  *(undefined4 *)((longlong)param_1 + 0x10) = 0x98badcfe;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0x10325476;
  return;
}



===== crypto_md5_transform @ 140004444 =====

void crypto_md5_transform(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  iVar4 = *param_2;
  iVar5 = param_2[5];
  uVar20 = *param_1 + -0x28955b88 + ((uVar3 ^ uVar2) & uVar1 ^ uVar3) + iVar4;
  iVar6 = param_2[1];
  uVar20 = (uVar20 * 0x80 | uVar20 >> 0x19) + uVar1;
  iVar7 = param_2[2];
  uVar21 = uVar3 + 0xe8c7b756 + ((uVar2 ^ uVar1) & uVar20 ^ uVar2) + iVar6;
  uVar21 = (uVar21 * 0x1000 | uVar21 >> 0x14) + uVar20;
  iVar8 = param_2[3];
  uVar22 = uVar2 + 0x242070db + ((uVar1 ^ uVar20) & uVar21 ^ uVar1) + iVar7;
  uVar22 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar21;
  iVar9 = param_2[4];
  uVar23 = uVar1 + 0xc1bdceee + ((uVar21 ^ uVar20) & uVar22 ^ uVar20) + iVar8;
  uVar23 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar22;
  uVar20 = uVar20 + 0xf57c0faf + ((uVar21 ^ uVar22) & uVar23 ^ uVar21) + iVar9;
  iVar10 = param_2[6];
  uVar24 = (uVar20 * 0x80 | uVar20 >> 0x19) + uVar23;
  uVar20 = uVar21 + 0x4787c62a + ((uVar22 ^ uVar23) & uVar24 ^ uVar22) + iVar5;
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar24;
  iVar11 = param_2[7];
  uVar21 = uVar22 + 0xa8304613 + ((uVar23 ^ uVar24) & uVar20 ^ uVar23) + iVar10;
  iVar12 = param_2[8];
  iVar13 = param_2[10];
  iVar14 = param_2[0xc];
  iVar15 = param_2[0xd];
  iVar16 = param_2[0xe];
  uVar21 = (uVar21 >> 0xf | uVar21 * 0x20000) + uVar20;
  iVar17 = param_2[9];
  uVar22 = uVar23 + 0xfd469501 + ((uVar20 ^ uVar24) & uVar21 ^ uVar24) + iVar11;
  uVar22 = (uVar22 >> 10 | uVar22 * 0x400000) + uVar21;
  uVar23 = uVar24 + 0x698098d8 + ((uVar20 ^ uVar21) & uVar22 ^ uVar20) + iVar12;
  uVar24 = (uVar23 * 0x80 | uVar23 >> 0x19) + uVar22;
  uVar20 = uVar20 + 0x8b44f7af + ((uVar21 ^ uVar22) & uVar24 ^ uVar21) + iVar17;
  iVar18 = param_2[0xb];
  uVar23 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar24;
  uVar20 = (uVar21 - 0xa44f) + ((uVar22 ^ uVar24) & uVar23 ^ uVar22) + iVar13;
  uVar20 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar23;
  uVar21 = uVar22 + 0x895cd7be + ((uVar23 ^ uVar24) & uVar20 ^ uVar24) + iVar18;
  uVar21 = (uVar21 >> 10 | uVar21 * 0x400000) + uVar20;
  uVar22 = uVar24 + 0x6b901122 + ((uVar23 ^ uVar20) & uVar21 ^ uVar23) + iVar14;
  uVar22 = (uVar22 * 0x80 | uVar22 >> 0x19) + uVar21;
  uVar23 = ((uVar20 ^ uVar21) & uVar22 ^ uVar20) + 0xfd987193 + iVar15 + uVar23;
  uVar23 = (uVar23 * 0x1000 | uVar23 >> 0x14) + uVar22;
  iVar19 = param_2[0xf];
  uVar20 = uVar20 + 0xa679438e + ((uVar21 ^ uVar22) & uVar23 ^ uVar21) + iVar16;
  uVar24 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar23;
  uVar21 = ((uVar23 ^ uVar22) & uVar24 ^ uVar22) + 0x49b40821 + iVar19 + uVar21;
  uVar20 = (uVar21 >> 10 | uVar21 * 0x400000) + uVar24;
  uVar22 = uVar22 + ((uVar24 ^ uVar20) & uVar23 ^ uVar24) + 0xf61e2562 + iVar6;
  uVar21 = (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar20;
  uVar23 = uVar23 + ((uVar20 ^ uVar21) & uVar24 ^ uVar20) + 0xc040b340 + iVar10;
  uVar22 = (uVar23 * 0x200 | uVar23 >> 0x17) + uVar21;
  uVar24 = uVar24 + ((uVar22 ^ uVar21) & uVar20 ^ uVar21) + 0x265e5a51 + iVar18;
  uVar23 = (uVar24 * 0x4000 | uVar24 >> 0x12) + uVar22;
  uVar20 = uVar20 + 0xe9b6c7aa + ((uVar22 ^ uVar23) & uVar21 ^ uVar22) + iVar4;
  uVar24 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar23;
  uVar20 = uVar21 + 0xd62f105d + ((uVar23 ^ uVar24) & uVar22 ^ uVar23) + iVar5;
  uVar20 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar24;
  uVar21 = uVar22 + 0x2441453 + ((uVar24 ^ uVar20) & uVar23 ^ uVar24) + iVar13;
  uVar21 = (uVar21 * 0x200 | uVar21 >> 0x17) + uVar20;
  uVar22 = uVar23 + 0xd8a1e681 + ((uVar21 ^ uVar20) & uVar24 ^ uVar20) + iVar19;
  uVar22 = (uVar22 * 0x4000 | uVar22 >> 0x12) + uVar21;
  uVar23 = uVar24 + 0xe7d3fbc8 + ((uVar21 ^ uVar22) & uVar20 ^ uVar21) + iVar9;
  uVar23 = (uVar23 >> 0xc | uVar23 * 0x100000) + uVar22;
  uVar20 = uVar20 + 0x21e1cde6 + ((uVar22 ^ uVar23) & uVar21 ^ uVar22) + iVar17;
  uVar24 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar23;
  uVar20 = uVar21 + 0xc33707d6 + ((uVar23 ^ uVar24) & uVar22 ^ uVar23) + iVar16;
  uVar20 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar24;
  uVar21 = uVar22 + 0xf4d50d87 + ((uVar20 ^ uVar24) & uVar23 ^ uVar24) + iVar8;
  uVar21 = (uVar21 * 0x4000 | uVar21 >> 0x12) + uVar20;
  uVar22 = uVar23 + 0x455a14ed + ((uVar20 ^ uVar21) & uVar24 ^ uVar20) + iVar12;
  uVar25 = (uVar22 >> 0xc | uVar22 * 0x100000) + uVar21;
  uVar22 = uVar24 + 0xa9e3e905 + ((uVar21 ^ uVar25) & uVar20 ^ uVar21) + iVar15;
  uVar22 = (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar25;
  uVar20 = uVar20 + 0xfcefa3f8 + ((uVar25 ^ uVar22) & uVar21 ^ uVar25) + iVar7;
  uVar23 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar22;
  uVar20 = uVar21 + 0x676f02d9 + ((uVar23 ^ uVar22) & uVar25 ^ uVar22) + iVar11;
  uVar24 = (uVar20 * 0x4000 | uVar20 >> 0x12) + uVar23;
  uVar20 = uVar25 + 0x8d2a4c8a + ((uVar23 ^ uVar24) & uVar22 ^ uVar23) + iVar14;
  uVar20 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar24;
  uVar22 = uVar22 + ((uVar23 ^ uVar24 ^ uVar20) - 0x5c6be) + iVar5;
  uVar21 = (uVar22 * 0x10 | uVar22 >> 0x1c) + uVar20;
  uVar23 = uVar23 + (uVar24 ^ uVar20 ^ uVar21) + 0x8771f681 + iVar12;
  uVar22 = (uVar23 * 0x800 | uVar23 >> 0x15) + uVar21;
  uVar24 = uVar24 + (uVar22 ^ uVar20 ^ uVar21) + 0x6d9d6122 + iVar18;
  uVar23 = (uVar24 * 0x10000 | uVar24 >> 0x10) + uVar22;
  uVar20 = uVar20 + 0xfde5380c + (uVar22 ^ uVar23 ^ uVar21) + iVar16;
  uVar24 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar20 = uVar21 + 0xa4beea44 + (uVar22 ^ uVar23 ^ uVar24) + iVar6;
  uVar20 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar24;
  uVar21 = uVar22 + 0x4bdecfa9 + (uVar23 ^ uVar24 ^ uVar20) + iVar9;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar20;
  uVar22 = uVar23 + 0xf6bb4b60 + (uVar21 ^ uVar24 ^ uVar20) + iVar11;
  uVar23 = (uVar22 * 0x10000 | uVar22 >> 0x10) + uVar21;
  uVar22 = uVar24 + 0xbebfbc70 + (uVar21 ^ uVar23 ^ uVar20) + iVar13;
  uVar24 = (uVar22 >> 9 | uVar22 * 0x800000) + uVar23;
  uVar20 = uVar20 + 0x289b7ec6 + (uVar21 ^ uVar23 ^ uVar24) + iVar15;
  uVar25 = (uVar20 * 0x10 | uVar20 >> 0x1c) + uVar24;
  uVar21 = uVar21 + (uVar23 ^ uVar24 ^ uVar25) + 0xeaa127fa + iVar4;
  uVar22 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar25;
  uVar23 = uVar23 + (uVar22 ^ uVar24 ^ uVar25) + 0xd4ef3085 + iVar8;
  uVar23 = (uVar23 * 0x10000 | uVar23 >> 0x10) + uVar22;
  uVar20 = uVar24 + 0x4881d05 + (uVar22 ^ uVar23 ^ uVar25) + iVar10;
  uVar21 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar25 = (uVar22 ^ uVar23 ^ uVar21) + iVar17 + -0x262b2fc7 + uVar25;
  uVar24 = (uVar25 * 0x10 | uVar25 >> 0x1c) + uVar21;
  uVar20 = uVar22 + 0xe6db99e5 + (uVar23 ^ uVar21 ^ uVar24) + iVar14;
  uVar20 = (uVar20 * 0x800 | uVar20 >> 0x15) + uVar24;
  uVar22 = uVar23 + 0x1fa27cf8 + (uVar20 ^ uVar21 ^ uVar24) + iVar19;
  uVar22 = (uVar22 * 0x10000 | uVar22 >> 0x10) + uVar20;
  uVar21 = uVar21 + 0xc4ac5665 + (uVar20 ^ uVar22 ^ uVar24) + iVar7;
  uVar23 = (uVar21 >> 9 | uVar21 * 0x800000) + uVar22;
  uVar21 = uVar24 + 0xf4292244 + ((~uVar20 | uVar23) ^ uVar22) + iVar4;
  uVar21 = (uVar21 * 0x40 | uVar21 >> 0x1a) + uVar23;
  uVar20 = uVar20 + 0x432aff97 + ((~uVar22 | uVar21) ^ uVar23) + iVar11;
  uVar24 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar21;
  uVar20 = uVar22 + 0xab9423a7 + ((~uVar23 | uVar24) ^ uVar21) + iVar16;
  uVar20 = (uVar20 * 0x8000 | uVar20 >> 0x11) + uVar24;
  uVar22 = uVar23 + 0xfc93a039 + ((~uVar21 | uVar20) ^ uVar24) + iVar5;
  uVar22 = (uVar22 >> 0xb | uVar22 * 0x200000) + uVar20;
  uVar21 = uVar21 + 0x655b59c3 + ((~uVar24 | uVar22) ^ uVar20) + iVar14;
  uVar23 = (uVar21 * 0x40 | uVar21 >> 0x1a) + uVar22;
  uVar21 = uVar24 + 0x8f0ccc92 + ((~uVar20 | uVar23) ^ uVar22) + iVar8;
  uVar21 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar23;
  uVar20 = (uVar20 - 0x100b83) + ((~uVar22 | uVar21) ^ uVar23) + iVar13;
  uVar24 = (uVar20 * 0x8000 | uVar20 >> 0x11) + uVar21;
  uVar20 = uVar22 + 0x85845dd1 + ((~uVar23 | uVar24) ^ uVar21) + iVar6;
  uVar20 = (uVar20 >> 0xb | uVar20 * 0x200000) + uVar24;
  uVar23 = ((~uVar21 | uVar20) ^ uVar24) + 0x6fa87e4f + iVar12 + uVar23;
  uVar22 = (uVar23 * 0x40 | uVar23 >> 0x1a) + uVar20;
  uVar21 = uVar21 + 0xfe2ce6e0 + ((~uVar24 | uVar22) ^ uVar20) + iVar19;
  uVar23 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar22;
  uVar21 = uVar24 + 0xa3014314 + ((~uVar20 | uVar23) ^ uVar22) + iVar10;
  uVar21 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar23;
  uVar20 = uVar20 + 0x4e0811a1 + ((~uVar22 | uVar21) ^ uVar23) + iVar15;
  uVar20 = (uVar20 >> 0xb | uVar20 * 0x200000) + uVar21;
  uVar22 = uVar22 + 0xf7537e82 + ((~uVar23 | uVar20) ^ uVar21) + iVar9;
  uVar24 = (uVar22 * 0x40 | uVar22 >> 0x1a) + uVar20;
  uVar23 = ((~uVar21 | uVar24) ^ uVar20) + 0xbd3af235 + iVar18 + uVar23;
  uVar22 = (uVar23 * 0x400 | uVar23 >> 0x16) + uVar24;
  uVar21 = uVar21 + ((~uVar20 | uVar22) ^ uVar24) + 0x2ad7d2bb + iVar7;
  uVar21 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar22;
  *param_1 = *param_1 + uVar24;
  uVar20 = ((~uVar24 | uVar21) ^ uVar22) + 0xeb86d391 + iVar17 + uVar20;
  param_1[1] = uVar1 + (uVar20 >> 0xb | uVar20 * 0x200000) + uVar21;
  param_1[2] = uVar2 + uVar21;
  param_1[3] = uVar3 + uVar22;
  return;
}



===== crypto_md5_update @ 140004c64 =====

void crypto_md5_update(uint *param_1,undefined8 *param_2,ulonglong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  ulonglong _Size;
  ulonglong uVar8;
  int iVar9;
  
  _Size = param_3 & 0xffffffff;
  uVar4 = *param_1;
  uVar6 = param_1[1];
  uVar1 = (uint)param_3;
  uVar3 = uVar4 + uVar1 * 8;
  *param_1 = uVar3;
  if (uVar3 < uVar4) {
    uVar6 = uVar6 + 1;
    param_1[1] = uVar6;
  }
  param_1[1] = ((uint)(param_3 >> 0x1d) & 7) + uVar6;
  uVar4 = uVar4 >> 3 & 0x3f;
  if (uVar4 != 0) {
    uVar6 = 0x40 - uVar4;
    puVar5 = (uint *)((ulonglong)uVar4 + 0x18 + (longlong)param_1);
    if (uVar1 < uVar6) goto LAB_140004dae;
    memmove(puVar5,param_2,(ulonglong)uVar6);
    iVar9 = 0x10;
    puVar5 = param_1 + 6;
    do {
      *puVar5 = *puVar5;
      puVar5 = puVar5 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    crypto_md5_transform((int *)(param_1 + 2),(int *)(param_1 + 6));
    param_2 = (undefined8 *)((longlong)param_2 + (ulonglong)uVar6);
    _Size = (ulonglong)(uVar1 - uVar6);
  }
  puVar5 = param_1 + 6;
  uVar4 = (uint)_Size;
  if (0x3f < uVar4) {
    uVar8 = _Size >> 6;
    do {
      uVar2 = param_2[1];
      iVar9 = 0x10;
      *(undefined8 *)puVar5 = *param_2;
      *(undefined8 *)(param_1 + 8) = uVar2;
      uVar2 = param_2[3];
      *(undefined8 *)(param_1 + 10) = param_2[2];
      *(undefined8 *)(param_1 + 0xc) = uVar2;
      uVar2 = param_2[5];
      *(undefined8 *)(param_1 + 0xe) = param_2[4];
      *(undefined8 *)(param_1 + 0x10) = uVar2;
      uVar2 = param_2[7];
      *(undefined8 *)(param_1 + 0x12) = param_2[6];
      *(undefined8 *)(param_1 + 0x14) = uVar2;
      puVar7 = puVar5;
      do {
        *puVar7 = *puVar7;
        puVar7 = puVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      crypto_md5_transform((int *)(param_1 + 2),(int *)puVar5);
      param_2 = param_2 + 8;
      uVar4 = (int)_Size - 0x40;
      _Size = (ulonglong)uVar4;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  _Size = (ulonglong)uVar4;
LAB_140004dae:
  memmove(puVar5,param_2,_Size);
  return;
}



===== __security_check_cookie @ 140004df0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 140004e10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
                    /* WARNING: Could not recover jumptable at 0x000140004e17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortInitialize @ 140004e17 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004e17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetPhysicalAddress @ 140004e1d =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004e1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 140004e23 =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004e23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortNotification @ 140004e29 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004e29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== __GSHandlerCheck @ 140004e30 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140004e50 =====

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



===== DbgPrint @ 140004eb0 =====

void DbgPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140004eb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DbgPrint();
  return;
}



===== _vsnprintf @ 140004eb6 =====

int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140004eb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _vsnprintf(_Dest,_Count,_Format,_Args);
  return iVar1;
}



===== memcpy_s @ 140004ebc =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140004ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar1 = memcpy_s(_Dst,_DstSize,_Src,_MaxCount);
  return eVar1;
}



===== strcmp @ 140004ec2 =====

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140004ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



===== pl_perr_intr_handler @ 140004ed0 =====

void pl_perr_intr_handler(undefined8 param_1)

{
  t4_handle_intr_status(param_1,0x19404,(uint *)&DAT_140017470);
  return;
}



===== _guard_check_icall @ 140004ef0 =====

void _guard_check_icall(void)

{
  return;
}



===== BusInit @ 140004ef4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BusInit(void)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  byte bVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined1 local_148 [32];
  uint *puVar18;
  uint local_f8;
  ushort local_f4 [2];
  uint local_f0;
  uint local_ec;
  uint local_e8;
  undefined2 local_e4 [2];
  uint local_e0 [2];
  undefined1 local_d8 [48];
  byte local_a8 [4];
  uint local_a4;
  uint local_84;
  uint local_7c;
  uint local_78 [8];
  uint local_58 [8];
  undefined4 local_38;
  undefined2 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_148;
  uVar16 = 0xc0000001;
  memset(local_d8,0,0x30);
  puVar6 = mem_alloc(0x4e8);
  if (puVar6 == (uint *)0x0) {
    DbgPrint("Failed to alloc mem for adapter\n");
  }
  else {
    DAT_140018218 = puVar6;
    uVar7 = getPciCfgInfo();
    if ((char)uVar7 != '\0') {
      DbgPrint("could\'nt find a Chelsio Device!!\n");
      return 0xc000000e;
    }
    local_f8 = *(uint *)(DAT_140017e10 + 0x19400);
    t4_os_pci_read_cfg2(puVar6,2,local_f4);
    uVar3 = t4_get_chip_type((longlong)puVar6,(uint)(local_f4[0] >> 0xc));
    uVar3 = uVar3 & 0xf0;
    bVar10 = (byte)(local_f8 >> 9);
    if (uVar3 < 0x51) {
      bVar10 = (byte)(local_f8 >> 8);
    }
    DAT_140018231 = bVar10 & 7;
    uVar15 = local_f8 >> 9;
    if (uVar3 < 0x51) {
      uVar15 = local_f8 >> 8;
    }
    puVar6[0x12f] = uVar15 & 7;
    DAT_140018230 = DAT_140018231;
    puVar6[0x12e] = (uint)DAT_140018231;
    uVar8 = t4_prep_master_pf((longlong)puVar6,(ulonglong)(local_f8 >> 8),(ulonglong)uVar3,
                              (ulonglong)(uVar15 & 7));
    iVar5 = DAT_140017e18;
    uVar3 = (uint)uVar8;
    if (uVar3 == 0) {
      if ((((byte)puVar6[0x74] & 0xf0) != 0x40) &&
         (0x20 < 1 << ((byte)(*(uint *)(DAT_140017e10 + 0x1010) >>
                             ((byte)(puVar6[0x12f] << 2) & 0x1f)) & 0xf))) {
        DbgPrint("Incorrect SGE EGRESS QUEUES_PER_PAGE configuration, continuing in debug mode\n");
      }
      if (((byte)puVar6[0x74] & 0xf0) == 0x40) {
        uVar3 = iVar5 + 0x1b800;
        uVar15 = iVar5 + 0x28000;
        uVar17 = iVar5 + 0x30000;
        uVar13 = 0x10000;
        pcVar12 = "T4 memwin setup\n";
      }
      else {
        uVar3 = 0x1b800;
        pcVar12 = "T5 memwin setup\n";
        uVar13 = 0x20000;
        uVar15 = 0x28000;
        uVar17 = 0x60000;
      }
      DbgPrint(pcVar12);
      uVar4 = 0x800;
      iVar5 = 1;
      do {
        iVar11 = iVar5;
        uVar4 = uVar4 >> 1;
        iVar5 = iVar11 + 1;
      } while (uVar4 != 1);
      *(uint *)(DAT_140017e10 + 0x3068) = iVar11 - 10U | uVar3;
      LOCK();
      UNLOCK();
      uVar3 = 0x8000;
      iVar5 = 1;
      do {
        iVar11 = iVar5;
        uVar3 = uVar3 >> 1;
        iVar5 = iVar11 + 1;
      } while (uVar3 != 1);
      *(uint *)(DAT_140017e10 + 0x3070) = iVar11 - 10U | uVar15;
      LOCK();
      UNLOCK();
      iVar5 = 1;
      do {
        iVar11 = iVar5;
        uVar13 = uVar13 >> 1;
        iVar5 = iVar11 + 1;
      } while (uVar13 != 1);
      *(uint *)(DAT_140017e10 + 0x3078) = iVar11 - 10U | uVar17;
      LOCK();
      UNLOCK();
      uVar3 = t4_fw_hello(puVar6,(uint)DAT_140018230,(uint)DAT_140018230,1,local_e0);
      if ((int)uVar3 < 0) {
        pcVar12 = "BusInit: Could not contact firmware %d";
      }
      else {
        if (uVar3 == DAT_140018230) {
          *puVar6 = *puVar6 | 0x80;
        }
        puVar18 = local_78;
        local_78[0] = 0x10d0000;
        iVar5 = t4_query_params_rw(puVar6,(uint)DAT_140018230,puVar6[0x12f],0,1,puVar18,local_58,0,1
                                  );
        if (iVar5 < 0) {
          DbgPrint("No Config File support..todo\n");
          pcVar2 = (code *)swi(3);
          uVar8 = (*pcVar2)();
          return uVar8;
        }
        uVar3 = t4_fw_reset(puVar6,(uint)DAT_140018230,3);
        if ((int)uVar3 < 0) {
          pcVar12 = "BusInit: Firmware reset failed %d";
        }
        else {
          iVar5 = NicLoadCfgFile(&local_ec,(int *)&local_f0);
          if (iVar5 < 0) {
            local_ec = 4;
            uVar3 = (-(uint)(puVar6[0x3f] < 0x200000) & 0xffe0ffe4) + 0x1f0000;
            local_f0 = uVar3;
            DbgPrint("BusInit: Error loading config file %d\n",iVar5);
            uVar15 = 4;
          }
          else {
            uVar3 = local_f0;
            uVar15 = local_ec;
          }
          DbgPrint("adapter cfgfile maddr = 0x%x\n");
          memset(local_a8,0,0x30);
          local_a8[0] = 7;
          local_a8[1] = 0xc0;
          local_a8[2] = 0;
          local_a8[3] = 0;
          local_a4 = (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | uVar15 & 0xf7 | 0x3000008;
          uVar7 = CONCAT71((int7)((ulonglong)puVar18 >> 8),1);
          iVar5 = t4_wr_mbox_meat_timeout
                            (puVar6,(uint)DAT_140018230,local_a8,0x30,local_a8,uVar7,10000);
          if (iVar5 < 0) {
            DbgPrint("Error in parsing cfg file %d\n",iVar5);
          }
          if (((local_7c & 0xff0000 | local_7c >> 0x10) >> 8 |
              (local_7c << 0x10 | local_7c & 0xff00) << 8) !=
              ((local_84 & 0xff0000 | local_84 >> 0x10) >> 8 |
              (local_84 << 0x10 | local_84 & 0xff00) << 8)) {
            DbgPrint(" Configuration File checksum mismatch: [fini] csum=%#x, computed csum=%#x\n");
          }
          local_a8[0] = 7;
          local_a8[1] = 0xa0;
          local_a8[2] = 0;
          local_a8[3] = 0;
          local_a4 = 0x3000000;
          iVar5 = t4_wr_mbox_meat_timeout
                            (puVar6,(uint)DAT_140018230,local_a8,0x30,(void *)0x0,
                             CONCAT71((int7)((ulonglong)uVar7 >> 8),1),10000);
          if (iVar5 < 0) {
            DbgPrint("Error using config file %d\n",iVar5);
          }
          t4_fixup_host_params_compat((longlong)puVar6,0x1000,0x40,0x42);
          *(undefined4 *)(DAT_140017e10 + 0x1054) = 0x600;
          LOCK();
          UNLOCK();
          *(uint *)(DAT_140017e10 + 0x1008) = *(uint *)(DAT_140017e10 + 0x1008) & 0xffffe3ff | 0x800
          ;
          LOCK();
          UNLOCK();
          uVar3 = t4_fw_initialize(puVar6,(uint)DAT_140018230);
          if ((int)uVar3 < 0) {
            pcVar12 = "BusInit: t4_fw_initialize error %d\n";
          }
          else {
            SgeInit((longlong)puVar6);
            local_f8 = 0x1010000;
            uVar3 = t4_query_params_rw(puVar6,(uint)DAT_140018230,(uint)DAT_140018231,0,1,&local_f8,
                                       &local_e8,0,1);
            if (((int)uVar3 < 0) || (local_e8 == 0)) {
              pcVar12 = "BusInit: t4_query_params error %d\n";
            }
            else {
              *(char *)((longlong)puVar6 + 0x1c9) = (char)local_e8;
              iVar5 = 0;
              uVar3 = local_e8;
              do {
                iVar5 = iVar5 + (uVar3 & 1);
                uVar3 = uVar3 >> 1;
              } while (uVar3 != 0);
              *(char *)(puVar6 + 0x72) = (char)iVar5;
              DbgPrint(" BusInit: Port Vector:0x%08X NumPorts:%d\n",local_e8 & 0xff);
              local_f8 = *(uint *)(DAT_140017e10 + 0x7d90);
              puVar6[4] = local_f8 >> 0x10 & 0xff;
              puVar6[5] = local_f8 & 0xff;
              t4_read_mtu_tbl(puVar6,(ushort *)(puVar6 + 0x47),(byte *)0x0);
              t4_load_mtus(puVar6,(ushort *)(puVar6 + 0x47),(longlong)(puVar6 + 0x4f),
                           (ushort *)(puVar6 + 0x5f));
              iVar5 = 0;
              if ((char)puVar6[0x75] != '\0') {
                do {
                  *(short *)((longlong)puVar6 + (longlong)iVar5 * 2 + 0x1c) = (short)iVar5;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < (int)(uint)(byte)puVar6[0x75]);
              }
              iVar5 = 0;
              if ((char)puVar6[0x72] != '\0') {
                do {
                  (puVar6 + (longlong)iVar5 * 2 + 0x82)[0] = 0;
                  (puVar6 + (longlong)iVar5 * 2 + 0x82)[1] = 0;
                  puVar9 = mem_alloc(0x68);
                  *(undefined8 **)(puVar6 + (longlong)iVar5 * 2 + 0x82) = puVar9;
                  *(char *)((longlong)puVar9 + 0x11) = (char)iVar5;
                  iVar5 = iVar5 + 1;
                  *puVar9 = puVar6;
                  *(undefined2 *)((longlong)puVar9 + 10) = 0xffff;
                } while (iVar5 < (int)(uint)(byte)puVar6[0x72]);
              }
              uVar3 = t4_port_init((longlong)puVar6,(uint)DAT_140018230,(uint)DAT_140018231,0);
              if ((int)uVar3 < 0) {
                pcVar12 = "BusInit: t4_port_init error %d\n";
              }
              else {
                uVar3 = 0;
                if ((char)puVar6[0x72] != '\0') {
                  do {
                    lVar14 = 0;
                    if (uVar3 < 4) {
                      lVar14 = *(longlong *)(puVar6 + (longlong)(int)uVar3 * 2 + 0x82);
                    }
                    if (*(ushort *)(lVar14 + 8) != 0) {
                      t4_free_vi(puVar6,(uint)DAT_140018230,(uint)DAT_140018231,0,
                                 *(ushort *)(lVar14 + 8));
                      *(undefined2 *)(lVar14 + 8) = 0;
                    }
                    uVar3 = uVar3 + 1;
                  } while ((int)uVar3 < (int)(uint)(byte)puVar6[0x72]);
                }
                lVar14 = 0;
                if (*(uint *)(DAT_140018200 + 0xc) < 4) {
                  lVar14 = *(longlong *)
                            (puVar6 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
                }
                cVar1 = *(char *)(DAT_140018200 + 0xc);
                *(char *)(lVar14 + 0x12) = cVar1;
                uVar3 = t4_alloc_vi_func(puVar6,(uint)DAT_140018230,cVar1,(uint)DAT_140018231,0,1,
                                         &local_38,(uint *)local_e4,3,0);
                if (-1 < (int)uVar3) {
                  bVar10 = *(byte *)(lVar14 + 0x12);
                  uVar16 = 0;
                  *(short *)(lVar14 + 8) = (short)uVar3;
                  *(undefined2 *)(lVar14 + 0xc) = local_e4[0];
                  *(undefined4 *)(lVar14 + 0x4e) = *(undefined4 *)(lVar14 + 0x48);
                  *(undefined2 *)(lVar14 + 0x52) = *(undefined2 *)(lVar14 + 0x4c);
                  lVar14 = *(longlong *)(puVar6 + (ulonglong)bVar10 * 2 + 0x82);
                  *(undefined4 *)(lVar14 + 0x48) = local_38;
                  *(undefined2 *)(lVar14 + 0x4c) = local_34;
                  lVar14 = *(longlong *)(puVar6 + (ulonglong)bVar10 * 2 + 0x82);
                  *(undefined4 *)(lVar14 + 0x54) = local_38;
                  *(undefined2 *)(lVar14 + 0x58) = local_34;
                  *puVar6 = *puVar6 | 0x10;
                  goto LAB_1400056be;
                }
                pcVar12 = "BusInit: t4_alloc_vi_func error %d\n";
              }
            }
          }
        }
      }
    }
    else {
      pcVar12 = "T4 prep adapter failed err %d";
    }
    DbgPrint(pcVar12,uVar3);
  }
LAB_1400056be:
  return (ulonglong)uVar16;
}



===== CH_ALERT @ 1400056f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CH_ALERT(undefined8 param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_138 [32];
  char local_118 [255];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_118,0,0x100);
  uVar1 = _vsnprintf(local_118,0xff,param_2,(va_list)&local_res18);
  if ((-1 < (int)uVar1) && (uVar1 < 0x100)) {
    if (uVar1 == 0xff) {
      local_19 = 0;
    }
    DbgPrint(" *** CH_ALERT *** %s\n",local_118);
  }
  return;
}



===== CH_ERR @ 140005794 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CH_ERR(undefined8 param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_138 [32];
  char local_118 [255];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_118,0,0x100);
  uVar1 = _vsnprintf(local_118,0xff,param_2,(va_list)&local_res18);
  if ((-1 < (int)uVar1) && (uVar1 < 0x100)) {
    if (uVar1 == 0xff) {
      local_19 = 0;
    }
    DbgPrint(&s______CH_ERROR______s_,local_118);
  }
  return;
}



===== CH_WARN @ 140005838 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CH_WARN(undefined8 param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_138 [32];
  char local_118 [255];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_118,0,0x100);
  uVar1 = _vsnprintf(local_118,0xff,param_2,(va_list)&local_res18);
  if ((-1 < (int)uVar1) && (uVar1 < 0x100)) {
    if (uVar1 == 0xff) {
      local_19 = 0;
    }
    DbgPrint(&s______CH_WARN______s_,local_118);
  }
  return;
}



===== CH_WARN_RATELIMIT @ 1400058dc =====

void CH_WARN_RATELIMIT(void)

{
  return;
}



===== NicLoadCfgFile @ 1400058e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int NicLoadCfgFile(uint *param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStackY_e8 [32];
  uint local_98 [2];
  int *local_90;
  byte local_88;
  byte local_87;
  uint local_68 [8];
  ulonglong local_48;
  
  puVar1 = DAT_140018218;
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  pcVar5 = (char *)0x0;
  uVar6 = 0;
  iVar7 = 0;
  uVar3 = DAT_140018218[0x74];
  if (uVar3 == 5) {
    pcVar5 = s___Chelsio_T6_SMB_direct_configur_14001a000 + 0x4640;
    uVar3 = DAT_140022eb0;
  }
  else if ((uVar3 == 6) || (uVar3 == 0xc)) {
    pcVar5 = s___Chelsio_T6_SMB_direct_configur_14001a000;
    uVar3 = ram0x000140022eac;
  }
  else {
    uVar3 = local_98[0];
  }
  local_90 = param_2;
  DbgPrint("%s: Loading BuiltIn T5/T6 Cfg file\n","NicLoadCfgFile");
  if (uVar3 < 0x10000) {
    local_68[0] = 0x10d0000;
    iVar2 = t4_query_params_rw(puVar1,(uint)DAT_140018230,(uint)DAT_140018231,0,1,local_68,
                               (uint *)&local_88,0,1);
    if ((iVar2 == 0) && (pcVar5 != (char *)0x0)) {
      uVar6 = (uint)local_87;
      iVar7 = (uint)local_88 * 0x10000;
      uVar4 = uVar3 & 3;
      iVar2 = t4_memory_rw_mtype((longlong)puVar1,0,(uint)local_87,iVar7,uVar3 & 0xfffffffc,
                                 (undefined4 *)pcVar5,0);
      if ((iVar2 == 0) && (uVar4 != 0)) {
        local_98[0] = *(uint *)(pcVar5 + ((ulonglong)uVar3 & 0xfffffffffffffffc));
        if (uVar4 < 4) {
          memset((void *)((longlong)local_98 + (ulonglong)uVar4),0,4 - (ulonglong)uVar4);
        }
        iVar2 = t4_memory_rw_mtype((longlong)puVar1,0,(uint)local_87,(uVar3 & 0xfffffffc) + iVar7,4,
                                   local_98,0);
      }
    }
  }
  else {
    iVar2 = -0xc;
  }
  *param_1 = uVar6;
  *local_90 = iVar7;
  if (-1 < iVar2) {
    DbgPrint("%s: Successfully configured using Firmware Configuration File \"Firmware Default\" \n"
             ,"NicLoadCfgFile");
  }
  return iVar2;
}



===== SgeInit @ 140005ad4 =====

ulonglong SgeInit(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *(uint *)(DAT_140017e10 + 0x1008);
  *(uint *)(param_1 + 0x240) = uVar1 >> 10 & 7;
  *(int *)(param_1 + 0x244) = 1 << ((byte)(uVar1 >> 4) & 7) + 5;
  *(uint *)(param_1 + 0x23c) = (-(uint)((uVar1 & 0x20000) != 0) & 0x40) + 0x40;
  uVar2 = SgeInitSoft(param_1);
  if ((int)uVar2 != 0) {
    DbgPrint("SgeInitSoft failed\n");
  }
  *(uint *)(param_1 + 0x248) = (*(uint *)(DAT_140017e10 + 0x1094) >> 8 & 0x3f) * 2 + 1;
  *(uint *)(param_1 + 0x24c) = (*(uint *)(param_1 + 0x58) / 1000) * 1000000;
  *(undefined2 *)(param_1 + 0x250) = 0;
  return uVar2 & 0xffffffff;
}



===== SgeInitSoft @ 140005b90 =====

undefined8 SgeInitSoft(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  
  if ((*(uint *)(DAT_140017e10 + 0x1008) >> 0x12 & 1) == 0) {
    DbgPrint(" NicSgeInitSoft: bad SGE CPL MODE\n");
    return 1;
  }
  uVar1 = *(uint *)(DAT_140017e10 + 0x1044);
  uVar7 = *(uint *)(DAT_140017e10 + 0x1048);
  uVar8 = (ulonglong)uVar7;
  uVar2 = *(uint *)(DAT_140017e10 + 0x104c);
  uVar3 = *(uint *)(DAT_140017e10 + 0x1050);
  if (uVar1 == 0x1000) {
    if (uVar7 != 0) {
      if ((uVar7 < 0x1001) || ((uVar7 & uVar7 - 1) != 0)) goto LAB_140005d96;
      iVar5 = 1;
      while (uVar7 != 1) {
        uVar8 = uVar8 >> 1;
        iVar5 = iVar5 + 1;
        uVar7 = (uint)uVar8;
      }
      *(int *)(param_1 + 0x238) = iVar5 + -0xd;
    }
    if ((0x5ff < uVar2) && (0x233f < uVar3)) {
      uVar7 = *(uint *)(DAT_140017e10 + 0x10b8);
      uVar2 = *(uint *)(DAT_140017e10 + 0x10bc);
      uVar3 = *(uint *)(DAT_140017e10 + 0x10c0);
      *(short *)(param_1 + 0x228) =
           (short)(((uVar7 >> 0x10) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      *(short *)(param_1 + 0x22a) =
           (short)(((uVar7 & 0xffff) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      *(short *)(param_1 + 0x22c) =
           (short)(((uVar2 >> 0x10) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      *(short *)(param_1 + 0x22e) =
           (short)(((uVar2 & 0xffff) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      *(short *)(param_1 + 0x230) =
           (short)(((uVar3 >> 0x10) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      *(short *)(param_1 + 0x232) =
           (short)(((uVar3 & 0xffff) * 1000 + (*(uint *)(param_1 + 0x58) >> 1)) /
                  *(uint *)(param_1 + 0x58));
      uVar4 = *(undefined4 *)(DAT_140017e10 + 0x10a0);
      *(byte *)(param_1 + 0x234) = (byte)((uint)uVar4 >> 0x18) & 0x3f;
      *(byte *)(param_1 + 0x235) = (byte)((uint)uVar4 >> 0x10) & 0x3f;
      *(byte *)(param_1 + 0x237) = (byte)uVar4 & 0x3f;
      *(byte *)(param_1 + 0x236) = (byte)((uint)uVar4 >> 8) & 0x3f;
      return 0;
    }
    uVar8 = (ulonglong)uVar3;
    pcVar6 = " SgeInitSoft: bad SGE FL MTU sizes [%d, %d]\n";
    uVar1 = uVar2;
  }
  else {
LAB_140005d96:
    pcVar6 = " SgeInitSoft: bad SGE FL page buffer sizes [%d, %d]\n";
  }
  DbgPrint(pcVar6,uVar1,uVar8);
  return 1;
}



===== alloc_fl_buffers @ 140005db0 =====

undefined8 alloc_fl_buffers(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong local_res10;
  ulonglong *local_res18;
  
  local_res10 = 0;
  local_res18 = &local_res10;
  lVar1 = *(longlong *)(param_2 + 8);
  uVar4 = 0;
  if (param_2[4] != 0) {
    do {
      dma_alloc_unalgn(*(undefined8 **)(*(longlong *)(param_2 + 0x12) + uVar4 * 8),&local_res18,
                       param_2[6]);
      if (local_res10 == 0) {
        DbgPrint("Failed to alloc fl buffer %d\n",uVar4);
        return 1;
      }
      uVar2 = *(byte *)(param_2 + 0x14) | local_res10;
      *(ulonglong *)(lVar1 + uVar4 * 8) =
           (((local_res10 & 0xff000000000000 | local_res10 >> 0x10) >> 0x10 |
            local_res10 & 0xff0000000000) >> 0x10 | local_res10 & 0xff00000000) >> 8 |
           (((uVar2 << 0x10 | (ulonglong)((uint)uVar2 & 0xff00)) << 0x10 |
            (ulonglong)((uint)uVar2 & 0xff0000)) << 0x10 | local_res10 & 0xff000000) << 8;
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      local_res10 = uVar2;
    } while (uVar3 < (uint)param_2[4]);
  }
  *param_2 = 0;
  *(uint *)(DAT_140017e10 + 0x1b000) =
       param_2[4] - 8 >> 3 | param_2[3] << 0xf | *(uint *)(param_1 + 0x1dc);
  LOCK();
  UNLOCK();
  return 0;
}



===== alloc_ring @ 140005f00 =====

void * alloc_ring(undefined8 *param_1,int param_2,int param_3,int param_4,undefined8 param_5,
                 undefined8 *param_6,int param_7)

{
  void *_Dst;
  void *_Dst_00;
  uint uVar1;
  
  _Dst_00 = (void *)0x0;
  uVar1 = param_3 * param_2 + param_7;
  _Dst = (void *)dma_alloc(param_1,&param_5,uVar1);
  if (_Dst == (void *)0x0) {
LAB_140005f3d:
    _Dst = (void *)0x0;
  }
  else {
    if (param_4 != 0) {
      _Dst_00 = mem_alloc(param_2 * param_4);
      if (_Dst_00 == (void *)0x0) {
        DbgPrint("Failed to alloc mem for ring\n");
        goto LAB_140005f3d;
      }
      memset(_Dst_00,0,(ulonglong)(uint)(param_2 * param_4));
    }
    if (param_6 != (undefined8 *)0x0) {
      *param_6 = _Dst_00;
    }
    memset(_Dst,0,(ulonglong)uVar1);
  }
  return _Dst;
}



===== build_ctrl_txq @ 140005fac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 build_ctrl_txq(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 auStackY_88 [32];
  ulonglong uVar6;
  uint local_48 [2];
  uint local_40;
  ulonglong local_28;
  
  puVar2 = DAT_140018218;
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar5 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar5 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  uVar1 = *param_1;
  pvVar4 = alloc_ring((undefined8 *)(param_1 + 0xe),uVar1,0x40,8,param_1 + 0xc,
                      (undefined8 *)(param_1 + 8),0x40);
  *(void **)(param_1 + 10) = pvVar4;
  if (pvVar4 == (void *)0x0) {
    DbgPrint("Failed to alloc ctrl txq ring\n");
  }
  else {
    uVar6 = *(ulonglong *)(param_1 + 0xc);
    prepare_fw_eq_ctrl_cmd(lVar5,puVar2[0x12f],local_48,param_2,uVar1 + 1,uVar6);
    iVar3 = t4_wr_mbox_meat_timeout
                      (puVar2,(uint)DAT_140018230,(byte *)local_48,0x20,local_48,
                       CONCAT71((int7)(uVar6 >> 8),1),10000);
    if (-1 < iVar3) {
      param_1[1] = 0;
      param_1[3] = 0;
      param_1[2] = 0;
      param_1[5] = 0;
      param_1[4] = 0;
      *(ulonglong *)(param_1 + 0x14) = (ulonglong)*param_1 * 0x40 + *(longlong *)(param_1 + 10);
      param_1[6] = (local_40 & 0xff0000 | local_40 >> 0x10) >> 8 | (local_40 & 0xf00) << 8;
      return 0;
    }
    DbgPrint("Failed to send mbox command ret = %d!!\n",iVar3);
  }
  return 1;
}



===== build_eth_txq @ 140006120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 build_eth_txq(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 auStackY_98 [32];
  ulonglong uVar6;
  uint local_58 [2];
  uint local_50;
  ulonglong local_28;
  
  puVar2 = DAT_140018218;
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar5 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar5 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  uVar1 = *param_1;
  pvVar4 = alloc_ring((undefined8 *)(param_1 + 0xe),uVar1,0x40,8,param_1 + 0xc,
                      (undefined8 *)(param_1 + 8),0x40);
  *(void **)(param_1 + 10) = pvVar4;
  if (pvVar4 == (void *)0x0) {
    DbgPrint("Failed to alloc eth txq ring\n");
  }
  else {
    uVar6 = *(ulonglong *)(param_1 + 0xc);
    prepare_fw_eq_eth_cmd(lVar5,puVar2[0x12f],local_58,param_2,uVar1 + 1,uVar6);
    iVar3 = t4_wr_mbox_meat_timeout
                      (puVar2,(uint)DAT_140018230,(byte *)local_58,0x30,local_58,
                       CONCAT71((int7)(uVar6 >> 8),1),10000);
    if (-1 < iVar3) {
      param_1[1] = 0;
      param_1[3] = 0;
      param_1[2] = 0;
      param_1[5] = 0;
      param_1[4] = 0;
      *(ulonglong *)(param_1 + 0x14) = (ulonglong)*param_1 * 0x40 + *(longlong *)(param_1 + 10);
      param_1[6] = (local_50 & 0xff0000 | local_50 >> 0x10) >> 8 | (local_50 & 0xf00) << 8;
      return 0;
    }
    DbgPrint("Failed to send mbox command ret = %d!!\n",iVar3);
  }
  return 1;
}



===== build_ofld_txq @ 14000629c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 build_ofld_txq(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 auStackY_88 [32];
  ulonglong uVar6;
  uint local_48 [2];
  uint local_40;
  ulonglong local_28;
  
  puVar2 = DAT_140018218;
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar5 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar5 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  uVar1 = *param_1;
  pvVar4 = alloc_ring((undefined8 *)(param_1 + 0xe),uVar1,0x40,8,param_1 + 0xc,
                      (undefined8 *)(param_1 + 8),0x40);
  *(void **)(param_1 + 10) = pvVar4;
  if (pvVar4 == (void *)0x0) {
    DbgPrint("Failed to alloc ofld txq ring\n");
  }
  else {
    uVar6 = *(ulonglong *)(param_1 + 0xc);
    prepare_fw_eq_ofld_cmd(lVar5,puVar2[0x12f],local_48,param_2,uVar1 + 1,uVar6);
    iVar3 = t4_wr_mbox_meat_timeout
                      (puVar2,(uint)DAT_140018230,(byte *)local_48,0x20,local_48,
                       CONCAT71((int7)(uVar6 >> 8),1),10000);
    if (-1 < iVar3) {
      param_1[1] = 0;
      param_1[3] = 0;
      param_1[2] = 0;
      param_1[5] = 0;
      param_1[4] = 0;
      *(ulonglong *)(param_1 + 0x14) = (ulonglong)*param_1 * 0x40 + *(longlong *)(param_1 + 10);
      param_1[6] = (local_40 & 0xff0000 | local_40 >> 0x10) >> 8 | (local_40 & 0xf00) << 8;
      return 0;
    }
    DbgPrint("Failed to send mbox command ret = %d!!\n",iVar3);
  }
  return 1;
}



===== build_rxq @ 140006410 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
build_rxq(undefined8 *param_1,char param_2,char param_3,undefined8 param_4,char param_5,
         undefined8 *param_6,undefined4 *param_7,undefined4 param_8)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 auStackY_f8 [32];
  uint in_stack_ffffffffffffff3c;
  undefined4 in_stack_ffffffffffffff64;
  undefined4 *local_80;
  uint local_78 [2];
  ushort local_70;
  ushort local_6e;
  ushort local_6c;
  ulonglong local_38;
  
  puVar1 = DAT_140018218;
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar11 = 0;
  lVar12 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar12 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82)
    ;
  }
  uVar10 = *(int *)((longlong)param_1 + 0x44) + 0xfU & 0xfffffff0;
  *(uint *)((longlong)param_1 + 0x44) = uVar10;
  pvVar4 = alloc_ring(param_1 + 5,uVar10,*(int *)(param_1 + 8),0,param_1 + 4,(undefined8 *)0x0,0);
  param_1[3] = pvVar4;
  if (pvVar4 == (void *)0x0) {
    return 1;
  }
  if (param_7 != (undefined4 *)0x0) {
    local_80 = param_7 + 10;
    uVar10 = param_7[4] + 7 & 0xfffffff8;
    param_7[4] = uVar10;
    lVar5 = dma_alloc((undefined8 *)(param_7 + 0xc),&local_80,uVar10 * 8 + 0x40);
    *(longlong *)(param_7 + 8) = lVar5;
    if (lVar5 == 0) {
      pcVar8 = "Failed to alloc fl dma ring\n";
LAB_1400064ff:
      DbgPrint(pcVar8);
    }
    else {
      pvVar4 = mem_alloc(param_7[4] << 3);
      *(void **)(param_7 + 0x12) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        pcVar8 = "Failed to alloc dma hdl ring\n";
        goto LAB_1400064ff;
      }
      if (param_7[4] != 0) {
        lVar5 = 0;
        do {
          pvVar4 = mem_alloc(0x18);
          *(void **)(lVar5 + *(longlong *)(param_7 + 0x12)) = pvVar4;
          if (*(longlong *)(lVar5 + *(longlong *)(param_7 + 0x12)) == 0) {
            DbgPrint("Failed to alloc dma handle for entry %d\n",uVar11);
            break;
          }
          uVar11 = uVar11 + 1;
          lVar5 = lVar5 + 8;
        } while (uVar11 < (uint)param_7[4]);
      }
    }
    if (*(longlong *)(param_7 + 8) == 0) {
      return 1;
    }
    uVar11 = ((uint)param_7[4] >> 3) + 1;
  }
  if (param_6 == (undefined8 *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar7 = param_6[1];
    uVar10 = (uint)*(ushort *)((longlong)param_6 + 0xc);
    param_1[9] = *param_6;
    param_1[10] = uVar7;
    param_1[0xb] = param_6[2];
  }
  if (param_7 == (undefined4 *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(ulonglong *)(param_7 + 10);
  }
  prepare_fw_iq_cmd(local_78,(uint)DAT_140018231,lVar12,(longlong)param_1,uVar11,uVar6,
                    (ulonglong)in_stack_ffffffffffffff3c << 0x20,0,param_2,param_3,param_5,
                    CONCAT44(in_stack_ffffffffffffff64,param_8),uVar10,puVar1[0x74]);
  iVar3 = t4_wr_mbox_meat_timeout
                    (puVar1,(uint)DAT_140018230,(byte *)local_78,0x40,local_78,
                     CONCAT71((int7)(uVar6 >> 8),1),10000);
  if (iVar3 < 0) {
    DbgPrint("Failed to send mbox command ret = %d!!\n",iVar3);
LAB_140006655:
    uVar7 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 1) = 0;
    *(int *)((longlong)param_1 + 0x44) = *(int *)((longlong)param_1 + 0x44) + -1;
    *param_1 = param_1[3];
    *(undefined1 *)((longlong)param_1 + 0xe) = *(undefined1 *)((longlong)param_1 + 0xd);
    uVar2 = local_70 << 8 | local_70 >> 8;
    uVar9 = local_6e << 8 | local_6e >> 8;
    *(undefined1 *)((longlong)param_1 + 0xc) = 1;
    *(ushort *)((longlong)param_1 + 0x14) = uVar9;
    *(ushort *)((longlong)param_1 + 0x16) = uVar2;
    if (param_7 != (undefined4 *)0x0) {
      param_7[1] = 0;
      param_7[3] = (local_6c & 0xff) << 8 | (uint)(local_6c >> 8);
      uVar7 = alloc_fl_buffers((longlong)puVar1,param_7);
      if ((int)uVar7 != 0) {
        DbgPrint("Failed to alloc fl buffers\n");
        goto LAB_140006655;
      }
      DbgPrint("fl0cntxt = 0x%x\n",param_7[3]);
      uVar2 = *(ushort *)((longlong)param_1 + 0x16);
      uVar9 = *(ushort *)((longlong)param_1 + 0x14);
    }
    DbgPrint("Created iq: cntxtid = 0x%x, abs_id = 0x%x, msi_idx = 0x%x\n",uVar9,uVar2,uVar10);
    uVar7 = 0;
  }
  return uVar7;
}



===== change_mac @ 140006734 =====

bool change_mac(void)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar2 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  uVar1 = t4_add_mac(DAT_140018218,(uint)DAT_140018230,(uint)*(ushort *)(lVar2 + 8),-1,
                     (undefined4 *)(lVar2 + 0x48),'\x01','\x01','\0');
  if ((int)uVar1 < 0) {
    DbgPrint("t4_change_mac failed\n");
  }
  return (int)uVar1 < 0;
}



===== dma_alloc @ 1400067ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dma_alloc(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  *(uint *)(param_1 + 2) = param_3;
  page_align_dmabuf();
  _Dst = DAT_1400180d0;
  *param_1 = DAT_1400180d0;
  if (_Dst == (void *)0x0) {
    DbgPrint("Failed to allocate DMA buffer\n");
    uVar1 = 0;
  }
  else {
    param_1[1] = _DAT_1400180c8;
    memset(_Dst,0,(ulonglong)*(uint *)(param_1 + 2));
    uVar1 = *param_1;
    *(undefined8 *)*param_2 = param_1[1];
    update_pool_ptr(param_3);
  }
  return uVar1;
}



===== dma_alloc_unalgn @ 140006838 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dma_alloc_unalgn(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  *(uint *)(param_1 + 2) = param_3;
  _Dst = DAT_1400180d0;
  *param_1 = DAT_1400180d0;
  if (_Dst == (void *)0x0) {
    DbgPrint("Failed to allocate DMA buffer\n");
    uVar1 = 0;
  }
  else {
    param_1[1] = _DAT_1400180c8;
    memset(_Dst,0,(ulonglong)param_3);
    uVar1 = *param_1;
    *(undefined8 *)*param_2 = param_1[1];
    update_pool_ptr(param_3);
  }
  return uVar1;
}



===== dump_add_l2t_entry @ 1400068c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_add_l2t_entry(longlong param_1,undefined4 *param_2,ushort param_3,byte param_4,
                       uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined4 *local_230;
  undefined4 local_228;
  undefined4 local_218;
  undefined4 local_214;
  undefined8 local_210;
  uint local_208;
  ushort local_204;
  ushort local_202;
  ushort local_200;
  undefined4 local_1fe;
  undefined2 local_1fa;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  local_210 = 0;
  local_230 = &local_218;
  local_228 = 0x20;
  local_218 = 0x10000005;
  uVar1 = *param_5;
  uVar2 = (uint)*(ushort *)(param_1 + 0x276) << 0xe;
  uVar3 = uVar2 | uVar1;
  local_214 = 0x2000040;
  local_208 = (((uint)*(ushort *)(param_1 + 0x276) << 0xe | uVar1) & 0xff0000 |
              (uVar2 | uVar1 | 0x12000000) >> 0x10) >> 8 | (uVar3 << 0x10 | uVar3 & 0xff00) << 8;
  local_238 = 0;
  local_204 = *(ushort *)(DAT_140018200 + 0xc) & 0xff;
  local_1fe = *param_2;
  local_200 = ((ushort)(param_4 & 7) | param_3 << 3) << 5 | param_3 >> 8 & 0xf;
  local_202 = (ushort)(uVar1 >> 8) & 0xff | (short)uVar1 << 8;
  local_1fa = *(undefined2 *)(param_2 + 1);
  t4_cntl_tx(param_1,(longlong)&local_238);
  return;
}



===== dump_close_conn_wr @ 140006a18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_close_conn_wr(void)

{
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined4 *local_230;
  undefined4 local_228;
  undefined4 local_218;
  uint local_214;
  undefined8 local_210;
  uint local_208;
  undefined4 local_204;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  local_230 = &local_218;
  local_228 = 0x18;
  local_238 = 0;
  local_214 = (DAT_14001820c & 0xff | 0x200) << 0x10 | DAT_14001820c >> 0x10 & 0xff |
              DAT_14001820c & 0xff00;
  local_218 = 0x8000005;
  local_208 = (DAT_14001820c << 0x10 | DAT_14001820c & 0xff00) << 8 | DAT_14001820c >> 8 & 0xff00 |
              DAT_14001820c >> 0x18 | 8;
  local_210 = 0;
  local_204 = 0;
  t4_ofld_tx(DAT_140018218,&local_238);
  return;
}



===== dump_configure_l2t @ 140006ae0 =====

void dump_configure_l2t(longlong param_1,ushort param_2,byte param_3,uint param_4)

{
  int iVar1;
  char *pcVar2;
  uint local_res20 [2];
  
  local_res20[0] = param_4;
  iVar1 = dump_add_l2t_entry(param_1,(undefined4 *)(DAT_140018200 + 0x456),param_2,param_3,
                             local_res20);
  pcVar2 = "Failed to add l2t entry\n";
  if (iVar1 == 0) {
    pcVar2 = "configured l2t entry\n";
  }
  DbgPrint(pcVar2);
  return;
}



===== dump_configure_toe @ 140006b30 =====

void dump_configure_toe(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  longlong lVar3;
  
  lVar3 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar3 = *(longlong *)(param_1 + 0x208 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 8);
  }
  *(uint *)(DAT_140017e10 + 0x7d48) = *(uint *)(DAT_140017e10 + 0x7d48) & 0xefffffff;
  LOCK();
  UNLOCK();
  iVar1 = dump_write_smt_entry(param_1,(undefined4 *)(lVar3 + 0x48),1);
  pcVar2 = "Failed to write smt entry\n";
  if (iVar1 == 0) {
    pcVar2 = "configured smt entry\n";
  }
  DbgPrint(pcVar2);
  return;
}



===== dump_open_tcp_conn @ 140006ba4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_open_tcp_conn(longlong param_1,ushort param_2,uint param_3,uint param_4,ushort param_5)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong *puVar10;
  uint *puVar11;
  undefined1 auStack_298 [32];
  ushort local_278;
  ushort local_276;
  uint local_274;
  uint local_270;
  ulonglong *local_268;
  uint *local_260;
  undefined8 local_258;
  undefined4 *local_250;
  undefined4 local_248;
  undefined4 local_238;
  uint local_234;
  undefined8 local_230;
  uint local_228;
  ushort local_224;
  ushort local_222;
  undefined4 local_220;
  undefined4 local_21c;
  ulonglong local_218;
  uint local_210;
  uint local_20c;
  ulonglong local_208 [58];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_298;
  lVar4 = 0;
  if ((uint)DAT_140018200[3] < 4) {
    lVar4 = *(longlong *)(param_1 + 0x208 + (longlong)(int)DAT_140018200[3] * 8);
  }
  uVar9 = *(ushort *)(lVar4 + 8) & 0x7f;
  uVar5 = *(int *)(param_1 + 0x1d0) >> 4 & 0xf;
  local_276 = *(ushort *)(DAT_140018200 + 2);
  if (uVar5 < 6) {
    uVar9 = uVar9 * 2;
  }
  local_278 = param_2;
  local_274 = param_4;
  local_270 = param_3;
  uVar1 = select_ntuple(param_1,param_5);
  local_250 = &local_238;
  uVar2 = (uint)*(byte *)(lVar4 + 0x14) << 0x1a | DAT_140018200[3] << 0x17;
  uVar6 = (uint)*(ushort *)(param_1 + 0x276);
  uVar3 = uVar2 | uVar6;
  local_230 = 0;
  if (uVar5 == 4) {
    puVar10 = (ulonglong *)0x30;
    local_238 = 0x20000005;
    local_248 = 0x30;
    local_234 = 0x3000000;
    local_268 = (ulonglong *)0x30;
    puVar11 = (uint *)0x2c;
    local_260 = (uint *)0x2c;
  }
  else {
    local_234 = 0x4000000;
    local_268 = local_208;
    local_260 = &local_20c;
    if (uVar5 == 5) {
      puVar10 = (ulonglong *)0x30;
      local_248 = 0x38;
      local_238 = 0x28000005;
      puVar11 = (uint *)0x2c;
    }
    else {
      local_248 = 0x40;
      puVar10 = local_208;
      local_238 = 0x30000005;
      puVar11 = &local_20c;
    }
  }
  local_234 = local_234 | 0x40;
  uVar7 = local_274 | (uint)*(ushort *)(param_1 + 0x276) << 0xe;
  local_228 = ((uVar7 | 0x3000000) >> 0x10 | uVar7 & 0xff0000) >> 8 |
              (uVar7 & 0xff00 | uVar7 << 0x10) << 8;
  local_224 = local_278 << 8 | local_278 >> 8;
  local_222 = local_276 << 8 | local_276 >> 8;
  local_220 = *DAT_140018200;
  local_21c = DAT_140018200[1];
  uVar7 = DAT_140018200[3];
  uVar8 = (ulonglong)(uVar7 << 2) | 0x89c0000000100200;
  local_218 = ((((((uVar8 << 0x10 | (ulonglong)((uint)uVar8 & 0xff00)) << 4 |
                  (ulonglong)(uVar9 & 0xf)) << 0xc | (ulonglong)((uVar7 & 0x3fc000) << 2)) << 4 |
                ((ulonglong)local_270 << 8 | (ulonglong)uVar9) & 0xff0) << 8 |
               (ulonglong)local_270 & 0xff0) << 4 | (ulonglong)((uVar7 & 0xffc00000) << 2)) << 8 |
              (((ulonglong)local_270 | 0x89c0000) & 0xff000 |
              ((ulonglong)(local_270 >> 8) & 0xff000 | 0x100000000089000) >> 8) >> 4;
  uVar9 = (uint)uVar1;
  if (uVar5 == 4) {
    local_20c = uVar2 >> 0x18 | ((uVar3 | 0x500400) & 0xff0000) >> 8 |
                ((uVar3 | 0x500400) & 0xff00) << 8 | uVar6 << 0x18;
    local_210 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
  }
  else if (uVar5 == 5) {
    *local_268 = (uVar1 >> 0x10 & 0xff0000 | uVar1 & 0xff000000) >> 0x10 |
                 ((uVar1 & 0xff) << 0x10 | (ulonglong)(uVar9 & 0xff00)) << 0x10 | uVar1 & 0xff0000;
    uVar3 = uVar3 | 0x80100400;
    *local_260 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar6 << 0x18;
  }
  else if ((uVar5 == 6) || (uVar5 == 0xc)) {
    uVar3 = uVar3 | 0x80100400;
    *puVar10 = (uVar1 >> 0x10 & 0xff0000 | uVar1 & 0xff000000) >> 0x10 |
               ((uVar1 & 0xff) << 0x10 | (ulonglong)(uVar9 & 0xff00)) << 0x10 | uVar1 & 0xff0000;
    *puVar11 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar6 << 0x18;
  }
  local_258 = 0;
  t4_cntl_tx(param_1,(longlong)&local_258);
  return;
}



===== dump_send_flowc_wr @ 140006f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_send_flowc_wr(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined4 *local_230;
  undefined4 local_228;
  undefined4 local_218;
  uint local_214;
  undefined1 local_210;
  undefined1 uStack_20f;
  undefined2 uStack_20e;
  int local_20c;
  undefined1 local_208;
  uint local_204;
  undefined1 local_200;
  uint local_1fc;
  undefined1 local_1f8;
  int local_1f4;
  undefined1 local_1f0;
  uint local_1ec;
  undefined1 local_1e8;
  uint local_1e4;
  undefined1 local_1e0;
  undefined4 local_1dc;
  undefined1 local_1d8;
  undefined4 local_1d4;
  undefined1 local_1d0;
  undefined4 local_1cc;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  lVar2 = 0;
  uVar1 = *(uint *)(DAT_140018200 + 0xc);
  if (uVar1 < 4) {
    lVar2 = *(longlong *)(param_1 + 0x208 + (longlong)(int)uVar1 * 8);
  }
  local_230 = &local_218;
  local_218 = 0x900200a;
  local_210 = 0;
  local_214 = DAT_14001820c >> 0x10 & 0xbf | (DAT_14001820c & 0xff) << 0x10 | DAT_14001820c & 0xff00
              | 0x5000040;
  local_208 = 1;
  local_20c = (*(ushort *)(lVar2 + 8) & 0x700) << 8;
  local_200 = 2;
  local_1f8 = 3;
  local_1f4 = ((uint)*(ushort *)(param_1 + 0x276) << 0x10 | *(ushort *)(param_1 + 0x276) & 0xff00)
              << 8;
  local_1f0 = 4;
  local_1e8 = 5;
  local_1ec = (DAT_140018210 << 0x10 | DAT_140018210 & 0xff00) << 8 | DAT_140018210 >> 8 & 0xff00 |
              DAT_140018210 >> 0x18;
  local_1e0 = 6;
  local_1dc = 0x200;
  local_1e4 = (DAT_140018214 << 0x10 | DAT_140018214 & 0xff00) << 8 | DAT_140018214 >> 8 & 0xff00 |
              DAT_140018214 >> 0x18;
  local_1d8 = 7;
  local_204 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  lVar2 = 0;
  local_1d4 = 0x8000000;
  local_1d0 = 8;
  local_1cc = 0x3f0000;
  local_1fc = local_204;
  do {
    (&uStack_20e)[lVar2 * 4] = 0;
    (&uStack_20f)[lVar2 * 8] = 0;
    lVar2 = lVar2 + 1;
  } while (lVar2 < 9);
  local_238 = 0;
  local_228 = 0x50;
  t4_ofld_tx(param_1,&local_238);
  return;
}



===== dump_send_garp @ 1400070ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_send_garp(longlong param_1,ushort param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auStack_258 [32];
  longlong local_238;
  undefined4 *local_230;
  undefined8 local_228;
  undefined4 local_218;
  undefined2 local_214;
  undefined4 local_212;
  undefined2 local_20e;
  undefined4 local_20c;
  undefined4 local_208;
  ushort local_204;
  undefined4 local_202;
  undefined2 local_1fe;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined2 local_1f4;
  undefined4 local_1f2;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  lVar2 = 0;
  if ((uint)DAT_140018200[3] < 4) {
    lVar2 = *(longlong *)(param_1 + 0x208 + (longlong)(int)DAT_140018200[3] * 8);
  }
  local_238 = 0;
  local_228 = 0;
  memset(&local_218,0,0x200);
  uVar1 = local_228;
  local_230 = &local_218;
  local_228 = CONCAT44(local_228._4_4_,0x2a);
  if (DAT_140018200[5] != 0) {
    local_228._6_2_ = SUB82(uVar1,6);
    local_228._0_6_ = CONCAT24(*(undefined2 *)(DAT_140018200 + 6),0x2a);
  }
  memset(&local_218,0,0x2a);
  local_204 = param_2 << 8 | param_2 >> 8;
  local_218 = *(undefined4 *)((longlong)DAT_140018200 + 0x456);
  local_214 = *(undefined2 *)((longlong)DAT_140018200 + 0x45a);
  local_212 = *(undefined4 *)(lVar2 + 0x54);
  local_20e = *(undefined2 *)(lVar2 + 0x58);
  local_20c = 0x1000608;
  local_208 = 0x4060008;
  local_202 = *(undefined4 *)(lVar2 + 0x54);
  local_1fe = *(undefined2 *)(lVar2 + 0x58);
  local_1fc = *DAT_140018200;
  local_1f8 = *(undefined4 *)((longlong)DAT_140018200 + 0x456);
  local_1f4 = *(undefined2 *)((longlong)DAT_140018200 + 0x45a);
  local_1f2 = *DAT_140018200;
  t4_tun_tx(param_1,&local_238);
  return;
}



===== dump_send_ofld_wr @ 140007240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_send_ofld_wr(uint param_1,uint *param_2)

{
  uint uVar1;
  byte bVar2;
  undefined1 auStack_258 [32];
  uint *local_238;
  undefined4 *local_230;
  undefined4 local_228;
  undefined4 local_218;
  uint local_214;
  uint local_210;
  uint local_20c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  local_230 = &local_218;
  local_228 = 0x10;
  local_218 = 0x200b;
  uVar1 = (uint)((ulonglong)((((*param_2 - 1) * 3 >> 1) + (*param_2 - 1 & 1)) * 8 + 0x10) + 0x1f >>
                4);
  local_214 = ((DAT_14001820c << 8 | uVar1) & 0xff00 | uVar1 << 0x10) << 8 |
              (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | DAT_14001820c >> 0x10 & 0xbf |
              DAT_14001820c & 0xff00 | 0x40;
  bVar2 = DAT_140018096 != '\0';
  if ((bool)bVar2) {
    param_1 = param_1 + 4;
  }
  if ((DAT_140018097 != '\0') && (1 < *param_2)) {
    bVar2 = bVar2 | 2;
    param_1 = param_1 + 4;
  }
  local_20c = (uint)bVar2 << 0x1e | 0x480000;
  if ((param_1 & 3) != 0) {
    param_1 = (param_1 - (param_1 & 3)) + 4;
  }
  local_210 = param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 |
              param_1 << 0x18;
  local_238 = param_2;
  t4_ofld_tx(DAT_140018218,&local_238);
  return;
}



===== dump_set_tcb_field @ 14000737c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_set_tcb_field(ushort param_1,ulonglong param_2,ulonglong param_3)

{
  undefined1 auStack_268 [32];
  undefined8 local_248;
  undefined4 *local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined8 local_220;
  uint local_218;
  ushort local_214;
  ushort local_212;
  ulonglong local_210;
  ulonglong local_208;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_268;
  local_240 = &local_228;
  local_248 = 0;
  local_220 = 0;
  local_212 = param_1 << 8 | param_1 >> 8;
  local_238 = 0x28;
  local_224 = (DAT_14001820c & 0xff | 0x300) << 0x10 | DAT_14001820c >> 0x10 & 0xff |
              DAT_14001820c & 0xff00;
  local_228 = 0x18000005;
  local_218 = (DAT_14001820c << 0x10 | DAT_14001820c & 0xff00) << 8 | DAT_14001820c >> 8 & 0xff00 |
              DAT_14001820c >> 0x18 | 5;
  local_214 = *(ushort *)(DAT_140018218 + 0x276) << 8 | *(ushort *)(DAT_140018218 + 0x276) >> 8;
  local_210 = (((param_2 & 0xff000000000000 | param_2 >> 0x10) >> 0x10 | param_2 & 0xff0000000000)
               >> 0x10 | param_2 & 0xff00000000) >> 8 |
              (((param_2 & 0xff00 | param_2 << 0x10) << 0x10 | param_2 & 0xff0000) << 0x10 |
              param_2 & 0xff000000) << 8;
  local_208 = (((param_3 & 0xff000000000000 | param_3 >> 0x10) >> 0x10 | param_3 & 0xff0000000000)
               >> 0x10 | param_3 & 0xff00000000) >> 8 |
              (((param_3 & 0xff00 | param_3 << 0x10) << 0x10 | param_3 & 0xff0000) << 0x10 |
              param_3 & 0xff000000) << 8;
  t4_ofld_tx(DAT_140018218,&local_248);
  return;
}



===== dump_t4_intr @ 140007584 =====

bool dump_t4_intr(longlong param_1,uint param_2)

{
  longlong lVar1;
  bool bVar2;
  undefined7 extraout_var;
  
  lVar1 = DAT_140018218;
  bVar2 = dump_t4_process_iq_nopack(param_1,param_2);
  dump_t4_tx_done((uint *)(lVar1 + 0x318));
  dump_t4_tx_done((uint *)(lVar1 + 0x378));
  return (int)CONCAT71(extraout_var,bVar2) != 0;
}



===== dump_t4_process_iq_nopack @ 1400075c4 =====

bool dump_t4_process_iq_nopack(longlong param_1,uint param_2)

{
  byte bVar1;
  longlong lVar2;
  bool bVar3;
  undefined7 extraout_var;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  char *pcVar10;
  bool bVar11;
  
  lVar2 = DAT_140018218;
  uVar5 = 0;
  iVar6 = 0;
  pcVar10 = (char *)0x0;
  bVar11 = false;
  pcVar8 = *(char **)(DAT_140018218 + 0x260);
  bVar1 = pcVar8[(ulonglong)*(uint *)(DAT_140018218 + 0x2a0) - 8];
  if (*(char *)(DAT_140018218 + 0x26c) == (char)-((char)bVar1 >> 7)) {
    do {
      uVar7 = uVar5;
      puVar9 = (undefined8 *)0x0;
      if ((bVar1 >> 4 & 3) == 0) {
        puVar9 = *(undefined8 **)
                  (*(longlong *)(lVar2 + 0x308) + (ulonglong)*(uint *)(lVar2 + 0x2c4) * 8);
        iVar6 = iVar6 + 1;
        *(uint *)(lVar2 + 0x2c4) = (*(uint *)(lVar2 + 0x2c4) + 1) % *(uint *)(lVar2 + 0x2d0);
      }
      else if ((((bVar1 >> 4 & 3) == 1) && (pcVar10 = pcVar8, *pcVar8 == -0x40)) &&
              (pcVar8[9] == '\x04')) {
        pcVar10 = pcVar8 + 0x10;
      }
      bVar3 = t4_ofld_rx_pkts((longlong)pcVar10,puVar9,param_1,param_2);
      if (((int)CONCAT71(extraout_var,bVar3) != 0) && (bVar11 = true, DAT_140018232 != '\0')) {
        uVar5 = (*(int *)(lVar2 + 0x268) + 1U) % *(uint *)(lVar2 + 0x2a4);
        *(uint *)(lVar2 + 0x268) = uVar5;
        if (uVar5 == 0) {
          *(byte *)(lVar2 + 0x26c) = *(byte *)(lVar2 + 0x26c) ^ 1;
          *(undefined8 *)(lVar2 + 0x260) = *(undefined8 *)(lVar2 + 0x278);
        }
        else {
          *(longlong *)(lVar2 + 0x260) =
               *(longlong *)(lVar2 + 0x260) + (ulonglong)*(uint *)(lVar2 + 0x2a0);
        }
        break;
      }
      uVar5 = (*(int *)(lVar2 + 0x268) + 1U) % *(uint *)(lVar2 + 0x2a4);
      *(uint *)(lVar2 + 0x268) = uVar5;
      if (uVar5 == 0) {
        pcVar8 = *(char **)(lVar2 + 0x278);
        *(byte *)(lVar2 + 0x26c) = *(byte *)(lVar2 + 0x26c) ^ 1;
        *(char **)(lVar2 + 0x260) = pcVar8;
      }
      else {
        *(longlong *)(lVar2 + 0x260) =
             *(longlong *)(lVar2 + 0x260) + (ulonglong)*(uint *)(lVar2 + 0x2a0);
        pcVar8 = *(char **)(lVar2 + 0x260);
      }
      bVar1 = pcVar8[(ulonglong)*(uint *)(lVar2 + 0x2a0) - 8];
      uVar5 = uVar7 + 1;
    } while (*(char *)(lVar2 + 0x26c) == (char)-((char)bVar1 >> 7));
    uVar5 = uVar7 + 1;
    if (iVar6 != 0) {
      iVar4 = *(int *)(lVar2 + 0x2c0);
      if (7 < (uint)(iVar4 + iVar6)) {
        *(uint *)(DAT_140017e10 + 0x1b000) =
             *(int *)(lVar2 + 0x2cc) << 0xf | (uint)(iVar4 + iVar6) >> 3 | *(uint *)(lVar2 + 0x1dc);
        LOCK();
        UNLOCK();
        iVar4 = *(int *)(lVar2 + 0x2c0);
      }
      *(uint *)(lVar2 + 0x2c0) = iVar4 + iVar6 & 7;
    }
  }
  bVar1 = *(byte *)(lVar2 + 0x26e);
  *(undefined1 *)(lVar2 + 0x26e) = *(undefined1 *)(lVar2 + 0x26d);
  *(uint *)(DAT_140017e10 + 0x1b004) =
       ((uint)*(ushort *)(lVar2 + 0x274) << 4 | (uint)bVar1) << 0xc | uVar5;
  LOCK();
  UNLOCK();
  if (param_2 == 0) {
    bVar11 = uVar5 != 0;
  }
  return bVar11;
}



===== dump_t4_tx_done @ 1400077dc =====

ulonglong dump_t4_tx_done(uint *param_1)

{
  uint uVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_res10 [6];
  
  uVar1 = t4_reclaim_tx_entries((int *)param_1,(int *)local_res10);
  uVar2 = CONCAT44(extraout_var,uVar1);
  if (uVar1 != 0) {
    uVar3 = (ulonglong)uVar1;
    do {
      if (*(int *)(*(longlong *)(param_1 + 8) + (ulonglong)local_res10[0] * 4) != 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 8) + (ulonglong)local_res10[0] * 4) = 0;
      }
      uVar2 = (ulonglong)(local_res10[0] + 1) / (ulonglong)*param_1;
      local_res10[0] = (local_res10[0] + 1) % *param_1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return uVar2;
}



===== dump_target_login @ 140007820 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dump_target_login(void)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar2 = DAT_140018218;
  iVar7 = 0;
  uVar6 = 0xcb4;
  uVar5 = 0xfff;
  if (*(int *)(DAT_140018200 + 0x14) != 0) {
    uVar5 = *(ushort *)(DAT_140018200 + 0x18);
    DbgPrint("vlanid = %d\n",uVar5);
  }
  DbgPrint(&s_hdigest____d_ddigest____d_,*(undefined1 *)(DAT_140018200 + 0x45d));
  init_iscsi_params();
  DAT_140018210 = 0;
  _DAT_140018208 = 0;
  DAT_14001820c = 0;
  dump_configure_toe(lVar2);
  dump_configure_l2t(lVar2,uVar5,0,1);
  get_resp(0,0x23);
  while( true ) {
    lVar9 = 2;
    do {
      lVar8 = lVar9;
      dump_send_garp(lVar2,1);
      dump_send_garp(lVar2,2);
      lVar9 = lVar8 + -1;
    } while (lVar9 != 0);
    iVar1 = (int)lVar8;
    dump_open_tcp_conn(lVar2,uVar6,1,iVar1 + 1,uVar5);
    uVar4 = get_resp(0,iVar1 + 0x3f);
    if ((char)uVar4 != '\0') break;
    if (iVar7 == 5) {
      return 1;
    }
    iVar7 = iVar7 + 1;
    uVar6 = uVar6 + 1;
  }
  DbgPrint("Established TCP Conn with srcport = %d\n",uVar6);
  DbgPrint(&s_dump_connection_tid____d_);
  dump_send_flowc_wr(lVar2);
  get_resp(0,0);
  DAT_140017e04 = *(int *)(DAT_140018200 + 0x10);
  DbgPrint("auth type = %d\n");
  if (DAT_140017e04 == 0) {
    gdmpDevExtension = 4;
  }
  else {
    uVar4 = iscsi_login_secure();
    if ((char)uVar4 != '\0') {
      DbgPrint("Failed login authentication!!");
      return 1;
    }
  }
  KeStallExecutionProcessor();
  iscsi_send_scsicmd(0,0);
  get_resp(0,0x42);
  uVar3 = (uint)(DAT_140018096 != '\0');
  if (DAT_140018097 != '\0') {
    uVar3 = uVar3 | 2;
  }
  dump_set_tcb_field(0,0x330,(ulonglong)(uVar3 << 4));
  get_resp(0,0x3a);
  return 0;
}



===== dump_write_smt_entry @ 140007a10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void dump_write_smt_entry(longlong param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  undefined4 *local_230;
  undefined4 local_228;
  undefined4 local_218;
  undefined4 local_214;
  undefined8 local_210;
  uint local_208;
  uint local_204;
  ushort local_200;
  undefined4 local_1fe;
  undefined2 local_1fa;
  ushort local_1f8;
  undefined4 local_1f6;
  undefined2 local_1f2;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  uVar1 = *(uint *)(DAT_140018200 + 0xc);
  local_210 = 0;
  local_230 = &local_218;
  local_238 = 0;
  local_228 = 0x28;
  local_218 = 0x18000005;
  local_208 = ((uVar1 | 0x14000000) >> 0x10 | uVar1 & 0xff0000) >> 8 |
              (uVar1 & 0xff00 | uVar1 << 0x10) << 8;
  local_214 = 0x3000040;
  local_204 = ((param_3 & 0xfff) << 4 | (param_3 & 0xf) << 0x14) >> 8;
  local_200 = *(ushort *)(param_1 + 0x4bc) & 0xff;
  local_1fe = *param_2;
  local_1fa = *(undefined2 *)(param_2 + 1);
  local_1f6 = *param_2;
  local_1f2 = *(undefined2 *)(param_2 + 1);
  local_1f8 = local_200;
  t4_cntl_tx(param_1,(longlong)&local_238);
  return;
}



===== enable_vi @ 140007b18 =====

bool enable_vi(void)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar2 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  iVar1 = t4_enable_vi_params(DAT_140018218,(uint)DAT_140018230,(uint)*(ushort *)(lVar2 + 8),'\x01',
                              '\x01','\0');
  if (iVar1 < 0) {
    DbgPrint("enable_vi failed\n");
  }
  return iVar1 < 0;
}



===== filter_field_shift @ 140007b7c =====

int filter_field_shift(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar3 = 1;
  if (1 < param_2) {
    do {
      uVar2 = uVar3 & param_1;
      if (uVar2 < 0x21) {
        if (uVar2 == 0x20) {
LAB_140007bb5:
          iVar1 = iVar1 + 8;
        }
        else if (uVar2 == 1) {
LAB_140007bde:
          iVar1 = iVar1 + 1;
        }
        else if (uVar2 == 2) {
LAB_140007bbf:
          iVar1 = iVar1 + 3;
        }
        else if ((uVar2 == 4) || (uVar2 == 8)) {
          iVar1 = iVar1 + 0x11;
        }
        else if (uVar2 == 0x10) goto LAB_140007bb5;
      }
      else if (uVar2 == 0x40) {
        iVar1 = iVar1 + 0x10;
      }
      else if (uVar2 == 0x80) {
        iVar1 = iVar1 + 9;
      }
      else {
        if (uVar2 == 0x100) goto LAB_140007bbf;
        if (uVar2 == 0x200) goto LAB_140007bde;
      }
      uVar3 = uVar3 * 2;
    } while (uVar3 < param_2);
  }
  return iVar1;
}



===== fls @ 140007bf4 =====

int fls(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = param_1 << 0x10;
  if ((param_1 & 0xffff0000) != 0) {
    uVar2 = param_1;
  }
  uVar3 = -(uint)((param_1 & 0xffff0000) != 0) & 0x10;
  iVar4 = uVar3 + 0x10;
  if ((uVar2 & 0xff000000) == 0) {
    uVar2 = uVar2 << 8;
    iVar4 = uVar3 + 8;
  }
  iVar1 = iVar4 + -4;
  uVar3 = uVar2 << 4;
  if ((uVar2 & 0xf0000000) != 0) {
    iVar1 = iVar4;
    uVar3 = uVar2;
  }
  iVar4 = iVar1 + -2;
  if ((uVar3 & 0xc0000000) != 0) {
    iVar4 = iVar1;
  }
  uVar2 = uVar3 << 2;
  if ((uVar3 & 0xc0000000) != 0) {
    uVar2 = uVar3;
  }
  iVar1 = iVar4 + -1;
  if ((int)uVar2 < 0) {
    iVar1 = iVar4;
  }
  return iVar1;
}



===== func_init @ 140007c6c =====

undefined8 func_init(void)

{
  bool bVar1;
  undefined8 uVar2;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  
  uVar2 = setup_Qs();
  if ((int)uVar2 == 0) {
    LOCK();
    UNLOCK();
    *(uint *)(DAT_140017e10 + 0x1b004) =
         ((uint)*(ushort *)(DAT_140018218 + 0x274) << 4 | (uint)*(byte *)(DAT_140018218 + 0x26d)) <<
         0xc;
    LOCK();
    UNLOCK();
    bVar1 = pause_tx_rx();
    if ((((int)CONCAT71(extraout_var,bVar1) == 0) &&
        (bVar1 = set_rxmode(), (int)CONCAT71(extraout_var_00,bVar1) == 0)) &&
       (bVar1 = change_mac(), (int)CONCAT71(extraout_var_01,bVar1) == 0)) {
      bVar1 = enable_vi();
      if ((int)CONCAT71(extraout_var_02,bVar1) == 0) {
        return CONCAT71(extraout_var_02,bVar1);
      }
    }
  }
  DbgPrint("func_init failed");
  return 1;
}



===== fw_asrt @ 140007cec =====

void fw_asrt(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  CH_ALERT(param_1,"FW assertion at %.16s:%u, val0 %#x, val1 %#x\n",param_2 + 0x18,
           (ulonglong)
           ((uVar1 << 0x10 | uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8));
  return;
}



===== fwcap_to_fwspeed @ 140007da0 =====

uint fwcap_to_fwspeed(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0x100;
  if ((((((param_1 & 0x100) == 0) && (uVar1 = 0x80, (param_1 & 0x80) == 0)) &&
       (uVar1 = 0x40, (param_1 & 0x40) == 0)) &&
      ((uVar1 = 0x20, (param_1 & 0x20) == 0 && (uVar1 = 0x10, (param_1 & 0x10) == 0)))) &&
     ((uVar1 = 8, (param_1 & 8) == 0 &&
      ((uVar1 = 4, (param_1 & 4) == 0 && (uVar1 = 2, (param_1 & 2) == 0)))))) {
    uVar1 = param_1 & 1;
  }
  return uVar1;
}



===== fwcaps16_to_caps32 @ 140007df0 =====

uint fwcaps16_to_caps32(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 1 | 2;
  if ((param_1 & 2) == 0) {
    uVar2 = param_1 & 1;
  }
  uVar1 = uVar2 | 8;
  if ((param_1 & 4) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 4;
  if ((param_1 & 8) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x10;
  if ((param_1 & 0x10) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x40;
  if ((param_1 & 0x20) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x10000;
  if ((param_1 & 0x40) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x20000;
  if ((param_1 & 0x80) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x100000;
  if ((param_1 & 0x100) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x10000000;
  if ((param_1 & 0x2000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x200000;
  if ((param_1 & 0x200) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x400000;
  if ((param_1 & 0x400) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x800000;
  if ((param_1 & 0x800) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x1000000;
  if ((param_1 & 0x1000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x40000;
  if ((param_1 & 0x4000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x80000;
  if (-1 < (short)param_1) {
    uVar2 = uVar1;
  }
  return uVar2;
}



===== fwcaps32_to_caps16 @ 140007f14 =====

ushort fwcaps32_to_caps16(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = (ushort)param_1 & 1;
  uVar2 = uVar1 | 2;
  if ((param_1 & 2) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 8;
  if ((param_1 & 4) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 4;
  if ((param_1 & 8) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x10;
  if ((param_1 & 0x10) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x20;
  if ((param_1 & 0x40) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x40;
  if ((param_1 & 0x10000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x80;
  if ((param_1 & 0x20000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x4000;
  if ((param_1 & 0x40000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x8000;
  if ((param_1 & 0x80000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x100;
  if ((param_1 & 0x100000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x2000;
  if ((param_1 & 0x10000000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x200;
  if ((param_1 & 0x200000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x400;
  if ((param_1 & 0x400000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x800;
  if ((param_1 & 0x800000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x1000;
  if ((param_1 & 0x1000000) == 0) {
    uVar2 = uVar1;
  }
  return uVar2;
}



===== getPciCfgInfo @ 140008068 =====

undefined8 getPciCfgInfo(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    StorPortGetBusData(DAT_140018238,4,iVar3,DAT_140017e20,&DAT_140018100,0x100);
    uVar1 = DbgPrint("vid = 0x%x\n",DAT_140018100);
    if (DAT_140018100 == 0x1425) {
      uVar2 = DbgPrint("Found a Chelsio Device!!\n");
      DAT_140017e0c = iVar3;
      return uVar2 & 0xffffffffffffff00;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== get_resp @ 1400080e8 =====

undefined8 get_resp(longlong param_1,uint param_2)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  bVar1 = dump_t4_intr(param_1,param_2);
  uVar2 = extraout_var;
  if (!bVar1) {
    do {
      while( true ) {
        bVar1 = dump_t4_intr(param_1,param_2);
        uVar2 = extraout_var_00;
        if (bVar1) goto LAB_140008178;
        if (param_2 != 0x40) break;
        KeStallExecutionProcessor(1000);
        bVar5 = iVar3 == 19999;
        uVar2 = extraout_var_01;
LAB_14000819b:
        iVar3 = iVar3 + 1;
        if (bVar5) goto LAB_140008178;
      }
      if ((param_2 == 0x32) || (param_2 == 0x2d)) {
        bVar5 = iVar3 == 99;
        goto LAB_14000819b;
      }
      iVar4 = iVar4 + 1;
      KeStallExecutionProcessor(2000);
    } while (iVar4 != 15000);
    DbgPrint("Did\'nt get the response! Expecting Storport to resend this IO!!\n");
    uVar2 = extraout_var_02;
    if (param_1 != 0) {
      *(undefined1 *)(param_1 + 3) = 5;
    }
  }
LAB_140008178:
  return CONCAT71(uVar2,bVar1);
}



===== init_cong_ctrl @ 1400081a4 =====

void init_cong_ctrl(undefined2 *param_1,undefined2 *param_2)

{
  param_1[0x1f] = 500;
  *(undefined4 *)(param_1 + 7) = 0x10001;
  *(undefined4 *)(param_1 + 5) = 0x10001;
  *(undefined4 *)(param_1 + 3) = 0x10001;
  *(undefined4 *)(param_1 + 1) = 0x10001;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 9) = 0x30002;
  *(undefined4 *)(param_1 + 0xb) = 0x50004;
  *(undefined4 *)(param_1 + 0xd) = 0x70006;
  *(undefined4 *)(param_1 + 0xf) = 0x90008;
  *(undefined4 *)(param_1 + 0x11) = 0xe000a;
  *(undefined4 *)(param_1 + 0x13) = 0x150011;
  *(undefined4 *)(param_1 + 0x15) = 0x1e0019;
  *(undefined4 *)(param_1 + 0x17) = 0x2d0023;
  *(undefined4 *)(param_1 + 0x19) = 0x50003c;
  *(undefined4 *)(param_1 + 0x1b) = 0xc80064;
  *(undefined4 *)(param_1 + 0x1d) = 0x190012c;
  param_2[0x11] = 4;
  *(undefined8 *)(param_2 + 5) = 0;
  *(undefined8 *)(param_2 + 1) = 0;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 9) = 0x10001;
  *(undefined4 *)(param_2 + 0xb) = 0x20002;
  *(undefined4 *)(param_2 + 0xf) = 0x30003;
  *(undefined4 *)(param_2 + 0xd) = 0x30003;
  *(undefined4 *)(param_2 + 0x14) = 0x40004;
  *(undefined4 *)(param_2 + 0x12) = 0x40004;
  *(undefined4 *)(param_2 + 0x1a) = 0x50005;
  *(undefined4 *)(param_2 + 0x18) = 0x50005;
  *(undefined4 *)(param_2 + 0x16) = 0x50005;
  *(undefined4 *)(param_2 + 0x1c) = 0x60006;
  *(undefined4 *)(param_2 + 0x1e) = 0x70007;
  return;
}



===== init_link_config @ 1400082a4 =====

void init_link_config(uint *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  bVar1 = (byte)(param_3 >> 0x16) & 2;
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined2 *)(param_1 + 8) = 0x303;
  *(undefined1 *)((longlong)param_1 + 0x22) = 1;
  bVar3 = bVar1 | 4;
  if ((param_3 & 0x1000000) == 0) {
    bVar3 = bVar1;
  }
  *(byte *)((longlong)param_1 + 0x23) = bVar3;
  bVar5 = (param_2 >> 0x14 & 1) == 0;
  if (bVar5) {
    uVar4 = fwcap_to_fwspeed(param_3);
    param_1[6] = uVar4;
    uVar4 = 0;
  }
  else {
    *(undefined1 *)(param_1 + 8) = 7;
    uVar4 = param_2 & 0x100fff;
  }
  param_1[2] = uVar4;
  *(bool *)(param_1 + 9) = !bVar5;
  uVar2 = fwcaps32_to_caps16(*param_1);
  *(ushort *)(param_1 + 4) = uVar2;
  uVar2 = fwcaps32_to_caps16(param_1[2]);
  *(ushort *)((longlong)param_1 + 0x12) = uVar2;
  uVar2 = fwcaps32_to_caps16(param_1[3]);
  *(ushort *)(param_1 + 5) = uVar2;
  uVar2 = fwcaps32_to_caps16(param_1[6]);
  *(ushort *)((longlong)param_1 + 0x16) = uVar2;
  return;
}



===== mem_alloc @ 140008360 =====

void * mem_alloc(uint param_1)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePoolWithTag(ExDefaultNonPagedPoolType,param_1,0x62766973);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,(ulonglong)param_1);
  }
  return _Dst;
}



===== mem_free @ 1400083a4 =====

void mem_free(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0x62766973);
  }
  return;
}



===== pause_tx_rx @ 1400083c0 =====

bool pause_tx_rx(void)

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  
  puVar1 = DAT_140018218;
  lVar3 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar3 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  *(byte *)(lVar3 + 0x3c) = *(byte *)(lVar3 + 0x3c) | 3;
  iVar2 = t4_link_l1cfg_core(puVar1,(uint)DAT_140018230,(uint)*(byte *)(lVar3 + 0x12),
                             (uint *)(lVar3 + 0x1c),1,10000);
  if (iVar2 < 0) {
    DbgPrint(&s_t4_link_l1cfg_failed_ret__d_,iVar2);
  }
  return iVar2 < 0;
}



===== place_sgl @ 140008430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void place_sgl(uint *param_1,undefined8 *param_2,longlong param_3,uint *param_4)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_288 [32];
  undefined8 *local_268;
  longlong local_260;
  uint *local_258;
  uint local_248 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_288;
  uVar6 = *param_4;
  puVar5 = local_248;
  if (param_2 <= *(undefined8 **)(param_3 + 0x50)) {
    puVar5 = param_1;
  }
  *puVar5 = ((uVar6 | 0x82ffffff) >> 0x10 | uVar6 & 0xff0000) >> 8 |
            (uVar6 & 0xff00 | uVar6 << 0x10) << 8;
  uVar4 = param_4[6];
  puVar5[1] = (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8;
  uVar7 = *(ulonglong *)(param_4 + 4);
  *(ulonglong *)(puVar5 + 2) =
       (((uVar7 << 0x10 | uVar7 & 0xff00) << 0x10 | uVar7 & 0xff0000) << 0x10 | uVar7 & 0xff000000)
       << 8 | (((uVar7 & 0xff000000000000 | uVar7 >> 0x10) >> 0x10 | uVar7 & 0xff0000000000) >> 0x10
              | uVar7 & 0xff00000000) >> 8;
  uVar6 = uVar6 - 1;
  if (uVar6 != 0) {
    puVar5 = puVar5 + 4;
    uVar7 = 1;
    if (1 < uVar6) {
      uVar3 = (ulonglong)(uVar6 >> 1);
      do {
        uVar4 = param_4[uVar7 * 6 + 6];
        *puVar5 = (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8;
        uVar4 = param_4[uVar7 * 6 + 0xc];
        puVar5[1] = (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8;
        uVar1 = *(ulonglong *)(param_4 + uVar7 * 6 + 4);
        *(ulonglong *)(puVar5 + 2) =
             (((uVar1 << 0x10 | uVar1 & 0xff00) << 0x10 | uVar1 & 0xff0000) << 0x10 |
             uVar1 & 0xff000000) << 8 |
             (((uVar1 & 0xff000000000000 | uVar1 >> 0x10) >> 0x10 | uVar1 & 0xff0000000000) >> 0x10
             | uVar1 & 0xff00000000) >> 8;
        uVar1 = *(ulonglong *)(param_4 + uVar7 * 6 + 10);
        uVar6 = uVar6 - 2;
        uVar7 = (ulonglong)(byte)((char)uVar7 + 2);
        *(ulonglong *)(puVar5 + 4) =
             (((uVar1 << 0x10 | uVar1 & 0xff00) << 0x10 | uVar1 & 0xff0000) << 0x10 |
             uVar1 & 0xff000000) << 8 |
             (((uVar1 & 0xff000000000000 | uVar1 >> 0x10) >> 0x10 | uVar1 & 0xff0000000000) >> 0x10
             | uVar1 & 0xff00000000) >> 8;
        puVar5 = puVar5 + 6;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    if (uVar6 != 0) {
      uVar6 = param_4[uVar7 * 6 + 6];
      puVar5[1] = 0;
      *puVar5 = (uVar6 << 0x10 | uVar6 & 0xff00) << 8 | (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8;
      uVar7 = *(ulonglong *)(param_4 + uVar7 * 6 + 4);
      *(ulonglong *)(puVar5 + 2) =
           (((uVar7 << 0x10 | uVar7 & 0xff00) << 0x10 | uVar7 & 0xff0000) << 0x10 |
           uVar7 & 0xff000000) << 8 |
           (((uVar7 & 0xff000000000000 | uVar7 >> 0x10) >> 0x10 | uVar7 & 0xff0000000000) >> 0x10 |
           uVar7 & 0xff00000000) >> 8;
    }
    if (*(undefined8 **)(param_3 + 0x50) < param_2) {
      iVar2 = (int)*(undefined8 **)(param_3 + 0x50);
      uVar4 = (int)param_2 - iVar2;
      uVar6 = iVar2 - (int)param_1;
      local_268 = param_2;
      local_260 = param_3;
      local_258 = param_1;
      memmove(param_1,local_248,(ulonglong)uVar6);
      memmove(*(void **)(param_3 + 0x28),(void *)((longlong)local_248 + (ulonglong)uVar6),
              (ulonglong)uVar4);
      param_2 = (undefined8 *)((ulonglong)uVar4 + *(longlong *)(param_3 + 0x28));
    }
    if (((ulonglong)param_2 & 8) != 0) {
      *param_2 = 0;
    }
  }
  return;
}



===== prepare_fw_eq_ctrl_cmd @ 140008840 =====

void prepare_fw_eq_ctrl_cmd
               (longlong param_1,uint param_2,uint *param_3,uint param_4,uint param_5,
               ulonglong param_6)

{
  uint uVar1;
  
  memset(param_3,0,0x20);
  param_3[3] = 0;
  param_3[1] = 0x2000090;
  *param_3 = (param_2 & 0xec0000 | 0xb013ffff) >> 0x10 | (param_2 & 0xff) << 0x10 | param_2 & 0x4f00
  ;
  param_3[2] = param_4 >> 4 & 0xff | (param_4 & 0xf) << 0xc;
  uVar1 = (uint)*(byte *)(param_1 + 0x11) << 0x10 | param_4;
  param_3[4] = (uVar1 & 0xdf0000 | uVar1 >> 0x10) >> 8 |
               (param_4 & 0xff00 | param_4 << 0x10 | 0x20) << 8;
  param_3[5] = (param_5 & 0xc70000 | param_5 >> 0x10 | 0x380100) >> 8 |
               (param_5 & 0xff00 | param_5 << 0x10) << 8;
  *(ulonglong *)(param_3 + 6) =
       (((param_6 & 0xff000000000000 | param_6 >> 0x10) >> 0x10 | param_6 & 0xff0000000000) >> 0x10
       | param_6 & 0xff00000000) >> 8 |
       (((param_6 & 0xff00 | param_6 << 0x10) << 0x10 | (ulonglong)((uint)param_6 & 0xff0000)) <<
        0x10 | param_6 & 0xff000000) << 8;
  return;
}



===== prepare_fw_eq_eth_cmd @ 1400089c0 =====

void prepare_fw_eq_eth_cmd
               (longlong param_1,uint param_2,uint *param_3,uint param_4,uint param_5,
               ulonglong param_6)

{
  uint uVar1;
  
  memset(param_3,0,0x30);
  param_3[1] = 0x3000090;
  *param_3 = (param_2 & 0xed0000 | 0xb012ffff) >> 0x10 | (param_2 & 0xff) << 0x10 | param_2 & 0x4f00
  ;
  param_3[8] = (uint)(uint3)(CONCAT12((char)*(undefined2 *)(param_1 + 8),
                                      *(undefined2 *)(param_1 + 8)) >> 8);
  uVar1 = (uint)*(byte *)(param_1 + 0x11) << 0x10 | param_4;
  param_3[4] = (uVar1 & 0xdf0000 | uVar1 >> 0x10) >> 8 |
               (param_4 & 0xff00 | param_4 << 0x10 | 0x20) << 8;
  param_3[5] = (param_5 & 0xcf0000 | param_5 >> 0x10 | 0x300100) >> 8 |
               (param_5 & 0xff00 | param_5 << 0x10) << 8;
  *(ulonglong *)(param_3 + 6) =
       (((param_6 & 0xff000000000000 | param_6 >> 0x10) >> 0x10 | param_6 & 0xff0000000000) >> 0x10
       | param_6 & 0xff00000000) >> 8 |
       (((param_6 & 0xff00 | param_6 << 0x10) << 0x10 | (ulonglong)((uint)param_6 & 0xff0000)) <<
        0x10 | param_6 & 0xff000000) << 8;
  return;
}



===== prepare_fw_eq_ofld_cmd @ 140008b38 =====

void prepare_fw_eq_ofld_cmd
               (longlong param_1,uint param_2,uint *param_3,uint param_4,uint param_5,
               ulonglong param_6)

{
  uint uVar1;
  
  memset(param_3,0,0x20);
  param_3[1] = 0x2000090;
  *param_3 = (param_2 & 0xde0000 | 0xb021ffff) >> 0x10 | (param_2 & 0xff) << 0x10 | param_2 & 0x4f00
  ;
  uVar1 = (uint)*(byte *)(param_1 + 0x11) << 0x10 | param_4;
  param_3[4] = (uVar1 & 0xdf0000 | uVar1 >> 0x10) >> 8 |
               (param_4 & 0xff00 | param_4 << 0x10 | 0x20) << 8;
  param_3[5] = (param_5 & 0xc70000 | param_5 >> 0x10 | 0x380100) >> 8 |
               (param_5 & 0xff00 | param_5 << 0x10) << 8;
  *(ulonglong *)(param_3 + 6) =
       (((param_6 & 0xff000000000000 | param_6 >> 0x10) >> 0x10 | param_6 & 0xff0000000000) >> 0x10
       | param_6 & 0xff00000000) >> 8 |
       (((param_6 & 0xff00 | param_6 << 0x10) << 0x10 | (ulonglong)((uint)param_6 & 0xff0000)) <<
        0x10 | param_6 & 0xff000000) << 8;
  return;
}



===== prepare_fw_iq_cmd @ 140008ca0 =====

void prepare_fw_iq_cmd(uint *param_1,uint param_2,longlong param_3,longlong param_4,int param_5,
                      ulonglong param_6,undefined8 param_7,undefined8 param_8,char param_9,
                      char param_10,char param_11,undefined8 param_12,uint param_13,uint param_14)

{
  ulonglong uVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  
  memset(param_1,0,0x40);
  DbgPrint("prepare_fw_iq_cmd: fwevtq = 0x%x, intridx = 0x%x\n",(int)param_9,param_13);
  param_1[1] = 0x4000090;
  *param_1 = (param_2 & 0xef0000 | 0xb010ffff) >> 0x10 | (param_2 & 0xff) << 0x10 | param_2 & 0x4f00
  ;
  uVar5 = ~param_13;
  if (-1 < (int)param_13) {
    uVar5 = param_13;
  }
  sVar7 = -1;
  sVar6 = -1;
  param_1[4] = ((param_13 >> 0x1f) << 0xf | uVar5 & 0xef00 | uVar5 << 0x10 | 0x1000) << 8 |
               ((*(ushort *)(param_3 + 8) & 0xff) << 0x10 | uVar5 & 0xff0000 |
               (((int)param_9 << 0xc | (uint)*(ushort *)(param_3 + 8)) << 0x10 | uVar5) >> 0x10) >>
               8;
  uVar5 = *(uint *)(param_4 + 0x40);
  if (uVar5 != 0) {
    iVar2 = 0x1f;
    if (uVar5 != 0) {
      for (; uVar5 >> iVar2 == 0; iVar2 = iVar2 + -1) {
      }
    }
    sVar6 = (short)iVar2;
    if (uVar5 != 0) {
      iVar2 = 0x1f;
      if (uVar5 != 0) {
        for (; uVar5 >> iVar2 == 0; iVar2 = iVar2 + -1) {
        }
      }
      sVar7 = (short)iVar2;
    }
  }
  *(ushort *)(param_1 + 5) =
       (*(byte *)(param_3 + 0x11) & 0xb) << 4 | (ushort)(*(byte *)(param_4 + 0xf) >> 4) |
       ((ushort)*(byte *)(param_4 + 0xf) << 4 | sVar7 - 4U) << 8 |
       (ushort)(sVar6 - 4U | 0x4000) >> 8;
  *(ushort *)((longlong)param_1 + 0x16) =
       *(ushort *)(param_4 + 0x44) << 8 | *(ushort *)(param_4 + 0x44) >> 8;
  uVar1 = *(ulonglong *)(param_4 + 0x20);
  *(ulonglong *)(param_1 + 6) =
       (((uVar1 & 0xff000000000000 | uVar1 >> 0x10) >> 0x10 | uVar1 & 0xff0000000000) >> 0x10 |
       uVar1 & 0xff00000000) >> 8 |
       (((uVar1 << 0x10 | uVar1 & 0xff00) << 0x10 | uVar1 & 0xff0000) << 0x10 | uVar1 & 0xff000000)
       << 8;
  if (param_5 != 0) {
    uVar4 = (-(uint)(param_11 != '\0') & 2) + 4;
    uVar5 = uVar4 | 0x4000000;
    if (param_10 == '\0') {
      uVar5 = uVar4;
    }
    uVar3 = 0x2001;
    param_1[8] = uVar5 >> 0x18 | uVar5 << 0x18;
    if ((param_14 & 0xf0) < 0x51) {
      uVar3 = 0x3001;
    }
    *(undefined2 *)(param_1 + 9) = uVar3;
    *(ushort *)((longlong)param_1 + 0x26) = (ushort)param_5 << 8 | (ushort)param_5 >> 8;
    *(ulonglong *)(param_1 + 10) =
         (((param_6 & 0xff000000000000 | param_6 >> 0x10) >> 0x10 | param_6 & 0xff0000000000) >>
          0x10 | param_6 & 0xff00000000) >> 8 |
         (((param_6 & 0xff00 | param_6 << 0x10) << 0x10 | param_6 & 0xff0000) << 0x10 |
         param_6 & 0xff000000) << 8;
  }
  return;
}



===== select_ntuple @ 140008f58 =====

ulonglong select_ntuple(longlong param_1,ushort param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  uVar9 = 0;
  lVar8 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar8 = *(longlong *)(param_1 + 0x208 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 8);
  }
  *(undefined4 *)(DAT_140017e10 + 0x7e40) = 0x140;
  LOCK();
  UNLOCK();
  uVar2 = *(uint *)(DAT_140017e10 + 0x7e44);
  *(undefined4 *)(DAT_140017e10 + 0x7e40) = 0x141;
  LOCK();
  UNLOCK();
  uVar3 = *(uint *)(DAT_140017e10 + 0x7e44);
  iVar4 = filter_field_shift(uVar2,8);
  iVar5 = filter_field_shift(uVar2,4);
  iVar6 = filter_field_shift(uVar2,2);
  iVar7 = filter_field_shift(uVar2,0x20);
  if ((uVar3 & 0x800) == 0) {
    iVar5 = -1;
  }
  if ((-1 < iVar4) && (*(int *)(DAT_140018200 + 0x14) != 0)) {
    uVar9 = (ulonglong)((param_2 | 0x10000) << ((byte)iVar4 & 0x1f));
  }
  if (-1 < iVar6) {
    uVar9 = uVar9 | (ulonglong)*(uint *)(DAT_140018200 + 0xc) << ((byte)iVar6 & 0x3f);
  }
  if (-1 < iVar7) {
    uVar9 = uVar9 | 6L << ((byte)iVar7 & 0x3f);
  }
  if (-1 < iVar5) {
    uVar1 = *(ushort *)(lVar8 + 8);
    uVar9 = uVar9 | (ulonglong)((uVar1 & 0x80) << 9 | uVar1 >> 1 & 0x380 | uVar1 & 0x7f) <<
                    ((byte)iVar5 & 0x3f);
  }
  return uVar9;
}



===== set_rxmode @ 1400090c8 =====

bool set_rxmode(void)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar2 = *(longlong *)(DAT_140018218 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 2 + 0x82);
  }
  iVar1 = t4_set_rxmode(DAT_140018218,(uint)DAT_140018230,(uint)*(ushort *)(lVar2 + 8),0x5ee,0,1,1,1
                        ,1);
  if (iVar1 < 0) {
    DbgPrint("t4_set_rxmode failed\n");
  }
  return iVar1 < 0;
}



===== setup_Qs @ 140009148 =====

undefined8 setup_Qs(void)

{
  longlong lVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 *puVar4;
  
  lVar1 = DAT_140018218;
  puVar4 = (undefined8 *)(DAT_140018200 + 0x420);
  *(undefined1 *)(DAT_140018218 + 0x26d) = 0xd;
  *(undefined1 *)(lVar1 + 0x26f) = 0;
  *(undefined4 *)(lVar1 + 0x2a0) = 0x40;
  *(undefined4 *)(lVar1 + 0x2a4) = 0x30;
  *(undefined4 *)(lVar1 + 0x2d0) = 0x10;
  *(undefined4 *)(lVar1 + 0x2d8) = 0x600;
  *(undefined1 *)(lVar1 + 0x310) = 4;
  uVar2 = build_rxq((undefined8 *)(lVar1 + 0x260),'\0','\0',0,'\0',puVar4,
                    (undefined4 *)(lVar1 + 0x2c0),0);
  if ((int)uVar2 == 0) {
    DbgPrint("Creating ofld txQ\n");
    *(uint *)(lVar1 + 0x318) = 0x30;
    uVar2 = build_ofld_txq((uint *)(lVar1 + 0x318),(uint)*(ushort *)(lVar1 + 0x274));
    if ((int)uVar2 == 0) {
      DbgPrint("Creating ctrl txQ\n");
      *(uint *)(lVar1 + 0x378) = 0x30;
      uVar2 = build_ctrl_txq((uint *)(lVar1 + 0x378),(uint)*(ushort *)(lVar1 + 0x274));
      if ((int)uVar2 == 0) {
        DbgPrint("Creating eth txQ\n");
        *(uint *)(lVar1 + 0x3d8) = 0x30;
        uVar2 = build_eth_txq((uint *)(lVar1 + 0x3d8),(uint)*(ushort *)(lVar1 + 0x274));
        if ((int)uVar2 == 0) {
          return 0;
        }
        pcVar3 = "alloc-txq ethq failed!!\n";
      }
      else {
        pcVar3 = "alloc-txq ctrlq failed!!\n";
      }
    }
    else {
      pcVar3 = "alloc-txq ofldq failed!!\n";
    }
  }
  else {
    pcVar3 = "build_rxq: ofldrxq: failed!!\n";
  }
  DbgPrint(pcVar3);
  return 1;
}



===== sf1_read @ 14000928c =====

undefined8 sf1_read(undefined8 param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 4) {
    if (*(int *)(DAT_140017e10 + 0x193fc) < 0) {
      uVar1 = 0xfffffff0;
    }
    else {
      *(uint *)(DAT_140017e10 + 0x193fc) = (param_4 * 2 | param_3) << 3 | param_2 * 2 - 2U;
      LOCK();
      UNLOCK();
      uVar1 = t4_wait_op_done_val(param_1,0x193fc,0x80000000,0,10,5,(uint *)0x0);
      if ((int)uVar1 == 0) {
        *param_5 = *(undefined4 *)(DAT_140017e10 + 0x193f8);
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



===== sf1_write @ 14000932c =====

undefined8 sf1_write(undefined8 param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 4) {
    if (*(int *)(DAT_140017e10 + 0x193fc) < 0) {
      uVar1 = 0xfffffff0;
    }
    else {
      *(undefined4 *)(DAT_140017e10 + 0x193f8) = param_5;
      LOCK();
      UNLOCK();
      *(uint *)(DAT_140017e10 + 0x193fc) = (param_4 * 2 | param_3) << 3 | 1 | param_2 * 2 - 2U;
      LOCK();
      UNLOCK();
      uVar1 = t4_wait_op_done_val(param_1,0x193fc,0x80000000,0,10,5,(uint *)0x0);
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



===== strtoul @ 1400093d0 =====

ulong __cdecl strtoul(char *_Str,char **_EndPtr,int _Radix)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  ulong uVar6;
  longlong lVar7;
  bool bVar8;
  
  lVar7 = 0;
  uVar6 = 0;
  bVar8 = false;
  bVar1 = *_Str;
  pbVar5 = (byte *)_Str;
  while (iVar2 = isspace((uint)bVar1), iVar2 != 0) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  if (_Radix == 0) {
    if (*pbVar5 == 0x30) {
      bVar1 = pbVar5[1];
      bVar8 = bVar1 != 0x78;
      pbVar5 = pbVar5 + (ulonglong)(bVar1 == 0x78) + 1;
      _Radix = 0x10;
      if (bVar1 != 0x78) {
        _Radix = 8;
      }
    }
    else {
      _Radix = 10;
    }
  }
  else if (((_Radix == 0x10) && (*pbVar5 == 0x30)) && (pbVar5[1] == 0x78)) {
    pbVar5 = pbVar5 + 2;
  }
  uVar3 = (int)(char)*pbVar5 - 0x30;
  uVar4 = (ulonglong)uVar3;
  if (_Radix == 8) {
    if (uVar3 < 8) {
      bVar8 = true;
      do {
        pbVar5 = pbVar5 + 1;
        lVar7 = uVar4 + lVar7 * 8;
        uVar6 = (ulong)lVar7;
        uVar4 = (ulonglong)((int)(char)*pbVar5 - 0x30U);
      } while ((int)(char)*pbVar5 - 0x30U < 8);
    }
  }
  else if (_Radix == 10) {
    if (uVar3 < 10) {
      bVar8 = true;
      do {
        pbVar5 = pbVar5 + 1;
        lVar7 = uVar4 + lVar7 * 10;
        uVar6 = (ulong)lVar7;
        uVar4 = (ulonglong)((int)(char)*pbVar5 - 0x30U);
      } while ((int)(char)*pbVar5 - 0x30U < 10);
    }
  }
  else if (_Radix == 0x10) {
    while (uVar3 < 0x4b) {
      uVar6 = (ulong)lVar7;
      if (0xf < (uint)(int)(char)(&DAT_140017d80)[uVar4]) break;
      pbVar5 = pbVar5 + 1;
      bVar8 = true;
      lVar7 = lVar7 * 0x10 + (ulonglong)(uint)(int)(char)(&DAT_140017d80)[uVar4];
      uVar6 = (ulong)lVar7;
      uVar3 = (int)(char)*pbVar5 - 0x30;
      uVar4 = (ulonglong)uVar3;
    }
  }
  else {
    while (uVar3 < 0x4b) {
      uVar6 = (ulong)lVar7;
      if ((uint)_Radix <= (uint)(int)(char)(&DAT_140017d80)[uVar4]) break;
      pbVar5 = pbVar5 + 1;
      bVar8 = true;
      lVar7 = (ulonglong)(uint)(int)(char)(&DAT_140017d80)[uVar4] + _Radix * lVar7;
      uVar6 = (ulong)lVar7;
      uVar3 = (int)(char)*pbVar5 - 0x30;
      uVar4 = (ulonglong)uVar3;
    }
  }
  if (!bVar8) {
    pbVar5 = (byte *)_Str;
  }
  if (_EndPtr != (char **)0x0) {
    *_EndPtr = (char *)pbVar5;
  }
  return uVar6;
}



===== t4_add_mac @ 14000954c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4_add_mac(uint *param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5,char param_6
               ,char param_7,char param_8)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  undefined1 auStackY_a8 [32];
  undefined7 in_stack_ffffffffffffff81;
  uint local_68;
  uint local_64;
  ushort local_60;
  undefined4 local_5e;
  undefined2 local_5a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar1 = param_1[0x78];
  uVar3 = (ushort)param_4;
  if (param_4 < 0) {
    uVar3 = 0x3ff - (param_6 != '\0');
  }
  memset(&local_68,0,0x40);
  local_68 = (param_3 & 0x5f0000 | param_3 >> 0x10 | 0xa01500) >> 8 |
             (param_3 << 0x10 | param_3 & 0xff00) * 0x100;
  local_64 = -(uint)(param_8 != '\0') & 0x40 | 0x1000000;
  local_60 = (uVar3 | 0x80ff) >> 8 | -(ushort)(param_7 != '\0') & 0xc | uVar3 << 8;
  local_5e = *param_5;
  local_5a = *(undefined2 *)(param_5 + 1);
  uVar2 = t4_wr_mbox_meat_timeout
                    (param_1,param_2,(byte *)&local_68,0x40,&local_68,
                     CONCAT71(in_stack_ffffffffffffff81,1),10000);
  if ((uVar2 == 0) && (uVar2 = (local_60 & 3) << 8 | (uint)(local_60 >> 8), (ushort)uVar1 <= uVar2))
  {
    return 0xfffffff4;
  }
  return uVar2;
}



===== t4_alloc_vi_func @ 1400096a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4_alloc_vi_func(uint *param_1,uint param_2,char param_3,uint param_4,uint param_5,int param_6,
                     undefined4 *param_7,uint *param_8,ushort param_9,short param_10)

{
  uint uVar1;
  undefined1 auStackY_c8 [32];
  undefined7 in_stack_ffffffffffffff61;
  uint local_88 [2];
  ushort local_80;
  undefined4 local_7e;
  undefined2 local_7a;
  char local_78;
  char local_77;
  undefined4 local_76;
  undefined2 local_72;
  ushort local_70;
  undefined4 local_6e;
  undefined2 local_6a;
  undefined4 local_66;
  undefined2 local_62;
  undefined4 local_5e;
  undefined2 local_5a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  memset(local_88,0,0x40);
  local_78 = param_3 << 4;
  local_88[1] = 0x4000080;
  local_88[0] = ((param_4 & 0xeb0000 | param_5 >> 8 | 0xb014ffff) >> 8 | param_5 & 0x4f0000) >> 8 |
                ((param_4 << 8 | param_5) & 0xff00 | param_5 << 0x10) << 8 | param_4 & 0x4f00;
  local_80 = ((param_10 << 3 | param_9) & 0xf) << 4;
  local_77 = (char)param_6 + -1;
  if (param_8 == (uint *)0x0) {
    local_70 = 0x800;
  }
  uVar1 = t4_wr_mbox_meat_timeout
                    (param_1,param_2,(byte *)local_88,0x40,local_88,
                     CONCAT71(in_stack_ffffffffffffff61,1),10000);
  if (uVar1 != 0) {
    return uVar1;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_7e;
    *(undefined2 *)(param_7 + 1) = local_7a;
    if (param_6 != 2) {
      if (param_6 != 3) {
        if (param_6 != 4) {
          if (param_6 != 5) goto LAB_14000980d;
          param_7[6] = local_5e;
          *(undefined2 *)(param_7 + 7) = local_5a;
        }
        *(undefined4 *)((longlong)param_7 + 0x12) = local_66;
        *(undefined2 *)((longlong)param_7 + 0x16) = local_62;
      }
      param_7[3] = local_6e;
      *(undefined2 *)(param_7 + 4) = local_6a;
    }
    *(undefined4 *)((longlong)param_7 + 6) = local_76;
    *(undefined2 *)((longlong)param_7 + 10) = local_72;
  }
LAB_14000980d:
  if (param_8 != (uint *)0x0) {
    *param_8 = (local_70 & 7) << 8 | (uint)(local_70 >> 8);
  }
  return (local_80 & 0xf) << 8 | (uint)(local_80 >> 8);
}



===== t4_cntl_tx @ 140009858 =====

undefined8 t4_cntl_tx(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  void *_Dst;
  uint uVar6;
  uint uVar7;
  
  lVar2 = *(longlong *)(param_2 + 8);
  puVar1 = (uint *)(param_1 + 0x378);
  uVar6 = *(uint *)(param_2 + 0x10);
  dump_t4_tx_done(puVar1);
  if ((*(uint *)(param_2 + 0x10) < 0x201) && (*(longlong *)(param_2 + 8) != 0)) {
    uVar3 = *puVar1;
    uVar5 = *(uint *)(param_2 + 0x10) + 0x3f >> 6;
    if (7 < uVar3 - *(int *)(param_1 + 0x37c)) {
      uVar4 = *(uint *)(param_1 + 900);
      uVar7 = 0;
      _Dst = (void *)((ulonglong)uVar4 * 0x40 + *(longlong *)(param_1 + 0x3a0));
      if (uVar5 != 0) {
        do {
          uVar3 = 0x40;
          if (uVar6 < 0x40) {
            uVar3 = uVar6;
          }
          memmove(_Dst,(void *)((ulonglong)(uVar7 << 6) + lVar2),(ulonglong)uVar3);
          uVar6 = uVar6 - uVar3;
          if (uVar6 == 0) {
            if (((ulonglong)uVar3 + (longlong)_Dst & 8) != 0) {
              *(undefined8 *)((ulonglong)uVar3 + (longlong)_Dst) = 0;
            }
            uVar3 = *puVar1;
            uVar4 = (uVar4 + 1) % uVar3;
            break;
          }
          uVar3 = *puVar1;
          uVar4 = (uVar4 + 1) % uVar3;
          if (uVar4 == 0) {
            _Dst = *(void **)(param_1 + 0x3a0);
          }
          else {
            _Dst = (void *)((longlong)_Dst + 0x40);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar5);
      }
      *(int *)(*(longlong *)(param_1 + 0x398) +
              ((ulonglong)(*(int *)(param_1 + 900) + -1 + uVar5) % (ulonglong)uVar3) * 4) =
           (int)param_2;
      *(int *)(param_1 + 0x37c) = *(int *)(param_1 + 0x37c) + uVar5;
      *(uint *)(param_1 + 900) = uVar4;
      *(uint *)(DAT_140017e10 + 0x1b000) = *(int *)(param_1 + 0x390) << 0xf | uVar5;
      LOCK();
      UNLOCK();
      return 0;
    }
  }
  return 1;
}



===== t4_enable_vi_params @ 14000999c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_enable_vi_params(uint *param_1,uint param_2,uint param_3,char param_4,char param_5,
                        char param_6)

{
  undefined1 auStackY_68 [32];
  uint7 in_stack_ffffffffffffffc1;
  ulonglong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStackY_68;
  local_28[1] = 0;
  local_28[0] = CONCAT44((((param_4 * 2 | (int)param_5) << 2 | (int)param_6) & 0xfU) << 4,
                         (param_3 & 0x6f0000 | param_3 >> 0x10 | 0x901700) >> 8 |
                         (param_3 & 0xff00 | param_3 << 0x10) << 8) | 0x100000000000000;
  t4_wr_mbox_meat_timeout
            (param_1,param_2,(byte *)local_28,0x10,(void *)0x0,
             (ulonglong)in_stack_ffffffffffffffc1 << 8,10000);
  return;
}



===== t4_fixup_host_params_compat @ 140009a5c =====

undefined8 t4_fixup_host_params_compat(longlong param_1,uint param_2,uint param_3,byte param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined7 extraout_var;
  ushort local_res10 [4];
  
  iVar2 = fls(param_2);
  uVar5 = iVar2 - 0xb;
  uVar6 = param_3;
  if (param_3 < 0x20) {
    uVar6 = 0x20;
  }
  iVar3 = fls(uVar6);
  *(uint *)(DAT_140017e10 + 0x100c) =
       ((((((uVar5 << 4 | uVar5) << 4 | uVar5) << 4 | uVar5) << 4 | uVar5) << 4 | uVar5) << 4 |
       uVar5) << 4 | uVar5;
  LOCK();
  UNLOCK();
  if ((((byte)*(undefined4 *)(param_1 + 0x1d0) & 0xf0) == 0x40) || ((param_4 & 0xf0) == 0x40)) {
    *(uint *)(DAT_140017e10 + 0x1008) =
         (iVar3 + -6) * 0x10 | -(uint)(0x40 < param_3) & 0x20000 |
         *(uint *)(DAT_140017e10 + 0x1008) & 0xfffdff8f;
    LOCK();
    UNLOCK();
  }
  else {
    bVar1 = t4_os_find_pci_capability(param_1,0x10);
    iVar3 = 1;
    iVar4 = (int)CONCAT71(extraout_var,bVar1);
    if (iVar4 != 0) {
      t4_os_pci_read_cfg2(param_1,iVar4 + 8,local_res10);
      uVar5 = 1 << ((byte)(local_res10[0] >> 5) & 7) + 7;
      if (uVar6 < uVar5) {
        uVar6 = uVar5;
      }
    }
    if (uVar6 < 0x11) {
      iVar3 = 0;
      uVar6 = 0x10;
    }
    else if (uVar6 == 0x20) {
      uVar6 = 0x40;
    }
    else {
      iVar3 = fls(uVar6);
      iVar3 = iVar3 + -6;
    }
    *(uint *)(DAT_140017e10 + 0x1008) =
         -(uint)(0x40 < param_3) & 0x20000 | *(uint *)(DAT_140017e10 + 0x1008) & 0xfffdff8f;
    LOCK();
    UNLOCK();
    *(uint *)(DAT_140017e10 + 0x1124) =
         iVar3 << 0x10 | *(uint *)(DAT_140017e10 + 0x1124) & 0xfff8ffff;
    LOCK();
    UNLOCK();
  }
  *(uint *)(DAT_140017e10 + 0x1044) = param_2;
  LOCK();
  UNLOCK();
  *(uint *)(DAT_140017e10 + 0x104c) = *(int *)(DAT_140017e10 + 0x104c) + -1 + uVar6 & ~(uVar6 - 1);
  LOCK();
  UNLOCK();
  *(uint *)(DAT_140017e10 + 0x1050) = *(int *)(DAT_140017e10 + 0x1050) + -1 + uVar6 & ~(uVar6 - 1);
  LOCK();
  UNLOCK();
  *(int *)(DAT_140017e10 + 0x19178) = iVar2 + -0xd;
  LOCK();
  UNLOCK();
  return 0;
}



===== t4_free_vi @ 140009cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_free_vi(uint *param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

{
  undefined1 auStackY_a8 [32];
  undefined7 in_stack_ffffffffffffff81;
  uint local_68 [2];
  ushort local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  memset(local_68,0,0x40);
  local_68[1] = 0x4000040;
  local_60 = param_5 << 8 | param_5 >> 8;
  local_68[0] = ((param_3 & 0xeb0000 | param_4 >> 8 | 0x9014ffff) >> 8 | param_4 & 0x6f0000) >> 8 |
                ((param_3 << 8 | param_4) & 0xff00 | param_4 << 0x10) << 8 | param_3 & 0x6f00;
  t4_wr_mbox_meat_timeout
            (param_1,param_2,(byte *)local_68,0x40,local_68,CONCAT71(in_stack_ffffffffffffff81,1),
             10000);
  return;
}



===== t4_fw_hello @ 140009db4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4_fw_hello(uint *param_1,uint param_2,uint param_3,int param_4,uint *param_5)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  undefined8 uVar10;
  undefined1 auStackY_98 [32];
  undefined7 in_stack_ffffffffffffff91;
  byte local_58 [8];
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = 0;
  if (param_4 == 2) {
    uVar2 = 0x10000000;
  }
  uVar4 = 0xf;
  if (param_4 == 2) {
    uVar4 = param_2;
  }
  iVar8 = 3;
  while( true ) {
    while( true ) {
      pbVar9 = local_58;
      uVar10 = 0x10;
      uVar5 = (ulonglong)param_2;
      local_58[0] = 4;
      local_58[1] = 0xa0;
      local_58[2] = 0;
      local_58[3] = 0;
      local_58[4] = 0;
      local_58[5] = 0;
      local_58[6] = 0;
      local_58[7] = 1;
      local_50 = (ulonglong)
                 ((~-(uint)(param_4 != 0) & 0x20000000 | uVar2) >> 0x18 |
                  (uVar4 | param_3 >> 4) & 0xff | (param_3 & 0xf) << 0xc | 0x100);
      uVar3 = t4_wr_mbox_meat_timeout
                        (param_1,param_2,pbVar9,0x10,local_58,CONCAT71(in_stack_ffffffffffffff91,1),
                         10000);
      if (uVar3 == 0) break;
      if (((uVar3 != 0xfffffff0) && (uVar3 != 0xffffff92)) ||
         (bVar1 = iVar8 < 1, iVar8 = iVar8 + -1, bVar1)) {
        if (*(int *)(DAT_140017e10 + 0x30b8) < 0) {
          t4_report_fw_error(param_1,uVar5,pbVar9,uVar10);
        }
        return uVar3;
      }
    }
    uVar3 = (uint)local_50 << 0x10;
    uVar6 = (uVar3 & 0xf0000) >> 0x10;
    if (param_5 != (uint *)0x0) {
      if ((int)(((uint)local_50 & 0xff00 | uVar3) << 8) < 0) {
        *param_5 = 2;
      }
      else {
        *param_5 = (uVar3 & 0x400000) >> 0x16;
      }
    }
    if ((uVar3 & 0xc00000) != 0) break;
    if (uVar6 == param_2) {
      return uVar6;
    }
    iVar7 = 30000;
    do {
      KeStallExecutionProcessor(50000);
      iVar7 = iVar7 + -0x32;
      uVar3 = *(uint *)(DAT_140017e10 + 0x30b8);
      if ((uVar3 & 0xc0000000) != 0) {
        if (param_5 != (uint *)0x0) {
          if ((int)uVar3 < 0) {
            *param_5 = 2;
          }
          else if ((uVar3 >> 0x1e & 1) != 0) {
            *param_5 = 1;
          }
        }
        if (uVar6 != 7) {
          return uVar6;
        }
        if ((uVar3 >> 0xf & 1) == 0) {
          return 7;
        }
        return uVar3 >> 0xc & 7;
      }
    } while (0 < iVar7);
    bVar1 = iVar8 < 1;
    iVar8 = iVar8 + -1;
    if (bVar1) {
      return 0xffffff92;
    }
  }
  return uVar6;
}



===== t4_fw_initialize @ 140009f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_fw_initialize(uint *param_1,uint param_2)

{
  undefined1 auStackY_68 [32];
  undefined7 in_stack_ffffffffffffffc1;
  byte local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28[8] = 0;
  local_28[9] = 0;
  local_28[10] = 0;
  local_28[0xb] = 0;
  local_28[0xc] = 0;
  local_28[0xd] = 0;
  local_28[0xe] = 0;
  local_28[0xf] = 0;
  local_28[0] = 6;
  local_28[1] = 0xa0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 1;
  t4_wr_mbox_meat_timeout
            (param_1,param_2,local_28,0x10,(void *)0x0,CONCAT71(in_stack_ffffffffffffffc1,1),10000);
  return;
}



===== t4_fw_reset @ 140009ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_fw_reset(uint *param_1,uint param_2,uint param_3)

{
  undefined1 auStackY_68 [32];
  undefined7 in_stack_ffffffffffffffc1;
  byte local_28 [8];
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28[0] = 3;
  local_28[1] = 0xa0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 1;
  local_20 = (ulonglong)
             (param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
             param_3 << 0x18);
  t4_wr_mbox_meat_timeout
            (param_1,param_2,local_28,0x10,(void *)0x0,CONCAT71(in_stack_ffffffffffffffc1,1),10000);
  return;
}



===== t4_get_chip_type @ 14000a058 =====

uint t4_get_chip_type(longlong param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = 0;
  uVar2 = *(uint *)(DAT_140017e10 + 0x1943c) & 0xf;
  if (param_2 == 4) {
LAB_14000a0c8:
    uVar3 = (ulonglong)(uVar2 | 0x40);
  }
  else {
    if (param_2 == 5) {
LAB_14000a0bc:
      uVar3 = (ulonglong)(uVar2 | 0x50);
      goto LAB_14000a0cc;
    }
    if (param_2 != 6) {
      if (param_2 == 10) {
        uVar1 = 0x100;
        goto LAB_14000a0c8;
      }
      if (param_2 == 0xb) {
        uVar1 = 0x100;
        goto LAB_14000a0bc;
      }
      if (param_2 != 0xc) {
        CH_ERR(param_1,"Device %d is not supported\n",(ulonglong)*(ushort *)(param_1 + 0xe2),
               (ulonglong)uVar2);
        return 0xffffffea;
      }
      uVar1 = 0x100;
    }
    uVar3 = (ulonglong)(uVar2 | 0x60);
  }
LAB_14000a0cc:
  uVar1 = uVar1 | (uint)uVar3;
  if (uVar1 == 0x41) {
    CH_ALERT(param_1,"T4 rev 1 chip is no longer supported\n",0x41,uVar3);
    return 0xffffffea;
  }
  return uVar1;
}



===== t4_get_flash_params @ 14000a0ec =====

int t4_get_flash_params(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint local_res10 [2];
  
  uVar6 = 0;
  uVar7 = 0;
  local_res10[0] = 0;
  uVar3 = sf1_write(param_1,1,1,0,0x9f);
  iVar2 = (int)uVar3;
  if (iVar2 == 0) {
    uVar7 = 1;
    uVar3 = sf1_read(param_1,3,0,1,local_res10);
    iVar2 = (int)uVar3;
  }
  uVar1 = local_res10[0];
  *(undefined4 *)(DAT_140017e10 + 0x193fc) = 0;
  LOCK();
  UNLOCK();
  if (iVar2 < 0) {
    return iVar2;
  }
  puVar4 = &DAT_140015828;
  do {
    if (*puVar4 == local_res10[0]) {
      uVar5 = *(uint *)(uVar6 * 8 + 0x14001582c);
      goto LAB_14000a246;
    }
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar5;
    puVar4 = puVar4 + 2;
  } while (uVar5 == 0);
  uVar5 = local_res10[0] & 0xff;
  if (uVar5 == 0x20) {
    uVar5 = local_res10[0] >> 0x10 & 0xff;
    if (uVar5 == 0x14) {
      uVar5 = 0x100000;
      goto LAB_14000a246;
    }
    if (uVar5 == 0x15) {
      uVar5 = 0x200000;
      goto LAB_14000a246;
    }
    if (uVar5 != 0x16) {
      if (uVar5 == 0x17) goto LAB_14000a1ae;
      if (uVar5 == 0x18) goto LAB_14000a1a4;
      if (uVar5 == 0x19) goto LAB_14000a1d1;
      if (uVar5 == 0x20) goto LAB_14000a1ca;
      if (uVar5 == 0x21) {
        uVar5 = 0x8000000;
        goto LAB_14000a246;
      }
      if (uVar5 == 0x22) {
        uVar5 = 0x10000000;
        goto LAB_14000a246;
      }
      goto LAB_14000a20d;
    }
  }
  else {
    if (uVar5 == 0x9d) {
      uVar5 = local_res10[0] >> 0x10 & 0xff;
      if (uVar5 == 0x16) {
LAB_14000a1d1:
        uVar5 = 0x2000000;
        goto LAB_14000a246;
      }
      if (uVar5 == 0x17) {
LAB_14000a1ca:
        uVar5 = 0x4000000;
        goto LAB_14000a246;
      }
    }
    else if ((uVar5 == 0xc2) || (uVar5 == 0xef)) {
      uVar5 = local_res10[0] >> 0x10 & 0xff;
      if (uVar5 == 0x17) {
LAB_14000a1ae:
        uVar5 = 0x800000;
        goto LAB_14000a246;
      }
      if (uVar5 == 0x18) {
LAB_14000a1a4:
        uVar5 = 0x1000000;
        goto LAB_14000a246;
      }
    }
LAB_14000a20d:
    CH_WARN(param_1,"Unknown Flash Part, ID = %#x, assuming 4MB\n",(ulonglong)local_res10[0],uVar7);
  }
  uVar5 = 0x400000;
LAB_14000a246:
  *(uint *)(param_1 + 0xfc) = uVar5;
  *(uint *)(param_1 + 0x100) = uVar5 >> 0x10;
  if (*(uint *)(param_1 + 0xfc) < 0x200000) {
    CH_WARN(param_1,"WARNING: Flash Part ID %#x, size %#x < %#x\n",(ulonglong)uVar1,
            (ulonglong)*(uint *)(param_1 + 0xfc));
  }
  return 0;
}



===== t4_get_tp_e2c_map @ 14000a294 =====

uint t4_get_tp_e2c_map(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint local_res10 [2];
  uint local_res18 [4];
  
  local_res10[0] = 0;
  uVar2 = 1 << ((byte)*(undefined4 *)(DAT_140017e10 + 0x9000) & 3);
  if (param_2 < uVar2) {
    local_res18[0] = 0x11f0000;
    iVar1 = t4_query_params_rw(param_1,param_1[0x12e],param_1[0x12f],0,1,local_res18,local_res10,0,0
                              );
    if (iVar1 == 0) {
      return local_res10[0] >> ((byte)(param_2 << 3) & 0x1f) & 0xff;
    }
  }
  else {
    CH_WARN(param_1,"TP E2C Channel Port Index %d >= Nports %d\n",(ulonglong)param_2,
            (ulonglong)uVar2);
  }
  return 0;
}



===== t4_handle_intr_status @ 14000a334 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int t4_handle_intr_status(undefined8 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = 0;
  uVar4 = 0;
  uVar5 = *(uint *)((ulonglong)param_2 + DAT_140017e10);
  uVar1 = *param_3;
  if (uVar1 != 0) {
    puVar2 = param_3 + 2;
    do {
      uVar1 = uVar1 & uVar5;
      if (uVar1 != 0) {
        if (*(short *)((longlong)puVar2 + 10) == 0) {
          if (*(longlong *)puVar2 != 0) {
            CH_WARN_RATELIMIT();
          }
        }
        else {
          iVar3 = iVar3 + 1;
          CH_ALERT(param_1,"%s (0x%x)\n",*(longlong *)puVar2,(ulonglong)uVar1);
        }
        if (*(code **)(puVar2 + 4) != (code *)0x0) {
          (**(code **)(puVar2 + 4))(param_1);
        }
        uVar4 = uVar4 | puVar2[-2];
      }
      uVar1 = puVar2[6];
      puVar2 = puVar2 + 8;
    } while (uVar1 != 0);
  }
  uVar5 = uVar5 & uVar4;
  if (uVar5 != 0) {
    *(uint *)((ulonglong)param_2 + DAT_140017e10) = uVar5;
    LOCK();
    UNLOCK();
  }
  return iVar3;
}



===== t4_init_portinfo_viid @ 14000a408 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4_init_portinfo_viid
               (undefined8 *param_1,uint param_2,uint param_3,uint param_4,uint param_5,
               undefined4 *param_6,char param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  ushort uVar7;
  byte bVar8;
  uint *puVar9;
  undefined1 auStackY_d8 [32];
  uint *in_stack_ffffffffffffff50;
  uint local_88 [4];
  undefined4 *local_78;
  uint local_70;
  uint local_6c;
  uint local_68;
  ushort local_64;
  ushort local_62;
  uint local_5c;
  uint local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_d8;
  cVar1 = (char)param_3;
  local_78 = param_6;
  puVar9 = (uint *)*param_1;
  uVar6 = (uint)*(byte *)((longlong)puVar9 + 0x1f9);
  local_88[2] = param_4;
  if (*(byte *)((longlong)puVar9 + 0x1f9) == 0) {
    in_stack_ffffffffffffff50 = local_88;
    local_88[0] = 0x23a0000;
    local_88[1] = 1;
    iVar2 = t4_set_params_timeout
                      (puVar9,param_2,param_4,param_5,1,(longlong)in_stack_ffffffffffffff50,
                       local_88 + 1,10000);
    uVar6 = 2 - (iVar2 != 0);
    *(char *)((longlong)puVar9 + 0x1f9) = (char)uVar6;
    puVar9 = (uint *)*param_1;
  }
  memset(&local_70,0,0x20);
  local_70 = (param_3 & 0x3f0000 | param_3 >> 0x10 | 0xc01b00) >> 8 |
             (param_3 << 0x10 | param_3 & 0xff00) << 8;
  iVar2 = 10;
  if (uVar6 == 1) {
    iVar2 = 3;
  }
  local_6c = iVar2 << 8 | 0x2000000;
  uVar3 = t4_wr_mbox_meat_timeout
                    (puVar9,param_2,(byte *)&local_70,0x20,&local_70,
                     CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff50 >> 8),1),10000);
  uVar7 = 0;
  if (uVar3 == 0) {
    uVar3 = local_68 & 0xff00;
    uVar4 = local_68 >> 8 & 0xff00;
    if (uVar6 == 1) {
      bVar5 = (byte)(uVar4 >> 8) & 0x1f;
      bVar8 = 0xff;
      if ((uVar3 << 8 & 0x200000) != 0) {
        bVar8 = (byte)(uVar3 >> 8) & 0x1f;
      }
      uVar7 = 0;
      uVar6 = fwcaps16_to_caps32(local_64 << 8 | local_64 >> 8);
      uVar3 = fwcaps16_to_caps32(local_62 << 8 | local_62 >> 8);
    }
    else {
      bVar5 = (byte)((uVar3 << 8 | uVar4) >> 0xd);
      bVar8 = 0xff;
      if ((local_68 << 0x10 & 0x40000) != 0) {
        bVar8 = (byte)((local_68 << 0x10 & 0xffffff | uVar3) >> 0xd) & 0x1f;
      }
      uVar6 = (local_5c & 0xff0000 | local_5c >> 0x10) >> 8 |
              (local_5c << 0x10 | local_5c & 0xff00) << 8;
      uVar3 = (local_58 & 0xff0000 | local_58 >> 0x10) >> 8 |
              (local_58 << 0x10 | local_58 & 0xff00) << 8;
    }
    if (param_7 != (char)uVar7) {
      uVar4 = t4_alloc_vi_func((uint *)*param_1,param_2,cVar1,local_88[2],param_5,1,local_78,
                               local_88,uVar7,uVar7);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      *(short *)(param_1 + 1) = (short)uVar4;
      *(undefined2 *)((longlong)param_1 + 0xc) = (undefined2)local_88[0];
    }
    *(char *)((longlong)param_1 + 0x12) = cVar1;
    *(char *)((longlong)param_1 + 0x15) = cVar1;
    *(char *)((longlong)param_1 + 0x13) = cVar1;
    uVar4 = t4_get_tp_e2c_map((uint *)*param_1,param_3);
    *(char *)((longlong)param_1 + 0x14) = (char)uVar4;
    *(byte *)((longlong)param_1 + 0xf) = bVar5;
    *(byte *)((longlong)param_1 + 0xe) = bVar8;
    *(undefined1 *)(param_1 + 2) = 0;
    init_link_config((uint *)((longlong)param_1 + 0x1c),uVar6,uVar3);
    uVar3 = 0;
  }
  return uVar3;
}



===== t4_link_l1cfg_core @ 14000a6a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4_link_l1cfg_core(uint *param_1,uint param_2,uint param_3,uint *param_4,undefined1 param_5,
                      uint param_6)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auStackY_b8 [32];
  undefined7 in_stack_ffffffffffffff71;
  uint local_78;
  uint local_74;
  uint local_70;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar12 = *param_4;
  cVar1 = *(char *)((longlong)param_1 + 0x1f9);
  uVar5 = fwcaps16_to_caps32(*(ushort *)((longlong)param_4 + 0x12));
  param_4[2] = uVar5;
  uVar6 = fwcaps16_to_caps32(*(ushort *)((longlong)param_4 + 0x16));
  bVar2 = (byte)param_4[8];
  param_4[6] = uVar6;
  uVar9 = (bVar2 & 1) << 0x10;
  uVar11 = uVar9 | 0x20000;
  if ((bVar2 & 2) == 0) {
    uVar11 = uVar9;
  }
  uVar9 = uVar11 | 0x10000000;
  if ((bVar2 & 4) != 0) {
    uVar9 = uVar11;
  }
  if ((*(byte *)((longlong)param_4 + 0x22) & 1) == 0) {
    bVar10 = *(byte *)((longlong)param_4 + 0x22);
  }
  else {
    bVar3 = (byte)(param_4[1] >> 0x16) & 2;
    bVar10 = bVar3 | 4;
    if ((param_4[1] & 0x1000000) == 0) {
      bVar10 = bVar3;
    }
  }
  uVar8 = (bVar10 & 2) << 0x16;
  uVar11 = uVar8 | 0x1000000;
  if ((bVar10 & 4) == 0) {
    uVar11 = uVar8;
  }
  if ((uVar12 >> 0x14 & 1) == 0) {
    if ((char)param_4[9] == '\x01') {
      return -0x16;
    }
    *(byte *)((longlong)param_4 + 0x23) = bVar10;
    uVar9 = uVar5 | uVar11 | uVar9;
    *(byte *)((longlong)param_4 + 0x21) = bVar2 & 0xfb;
  }
  else {
    if ((char)param_4[9] == '\0') {
      *(byte *)((longlong)param_4 + 0x23) = bVar10;
      *(byte *)((longlong)param_4 + 0x21) = bVar2 & 0xfb;
      uVar5 = uVar6;
    }
    uVar9 = uVar5 | uVar11 | uVar9 | uVar12 & 0x200000;
  }
  if ((~uVar12 & uVar9 & 0xefffffff) != 0) {
    CH_ERR(param_1,"Requested Port Capabilities %#x exceed Physical Port Capabilities %#x\n",
           (ulonglong)uVar9,(ulonglong)uVar12);
    return -0x16;
  }
  memset(&local_78,0,0x20);
  uVar12 = 0xff00;
  local_78 = (param_3 & 0x6f0000 | param_3 >> 0x10 | 0x901b00) >> 8 |
             (param_3 << 0x10 | param_3 & 0xff00) << 8;
  iVar7 = 9;
  if (cVar1 == '\x01') {
    iVar7 = 1;
  }
  local_74 = iVar7 << 8 | 0x2000000;
  if (cVar1 == '\x01') {
    uVar4 = fwcaps32_to_caps16(uVar9);
    local_70 = ((uint)uVar4 << 0x10 | uVar4 & uVar12) << 8;
  }
  else {
    local_70 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
  }
  iVar7 = t4_wr_mbox_meat_timeout
                    (param_1,param_2,(byte *)&local_78,0x20,(void *)0x0,
                     CONCAT71(in_stack_ffffffffffffff71,param_5),param_6);
  if (iVar7 == 0) {
    return 0;
  }
  CH_ERR(param_1,"Requested Port Capabilities %#x rejected, error %d\n",(ulonglong)uVar9,
         (ulonglong)(uint)-iVar7);
  return iVar7;
}



===== t4_load_mtus @ 14000a8f8 =====

void t4_load_mtus(undefined8 param_1,ushort *param_2,longlong param_3,ushort *param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  do {
    uVar1 = *param_2;
    uVar2 = fls((uint)uVar1);
    if (((uint)uVar1 & (1 << ((byte)uVar2 & 0x1f)) >> 2) == 0) {
      uVar2 = uVar2 - 1;
    }
    *(uint *)(DAT_140017e10 + 0x7de4) = (uVar7 << 8 | uVar2) << 0x10 | (uint)uVar1;
    LOCK();
    UNLOCK();
    uVar2 = 0;
    puVar6 = &DAT_1400178b0;
    puVar5 = param_4;
    do {
      uVar3 = ((uint)*(ushort *)((param_3 - (longlong)param_4) + (longlong)puVar5) * (uVar1 - 0x28))
              / *puVar6;
      uVar4 = 2;
      if (2 < uVar3) {
        uVar4 = uVar3;
      }
      *(uint *)(DAT_140017e10 + 0x7ddc) =
           (uVar7 << 5 | uVar2) << 0x10 | (uint)*puVar5 << 0xd | uVar4;
      LOCK();
      UNLOCK();
      uVar2 = uVar2 + 1;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar2 < 0x20);
    uVar7 = uVar7 + 1;
    param_2 = param_2 + 1;
  } while (uVar7 < 0x10);
  return;
}



===== t4_memory_rw_addr @ 14000a9f0 =====

undefined8
t4_memory_rw_addr(longlong param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5,
                 int param_6)

{
  byte bVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 local_res18 [4];
  
  if (((param_3 & 3) == 0) && (((ulonglong)param_5 & 3) == 0)) {
    uVar4 = param_4 & 3;
    uVar3 = *(uint *)((ulonglong)(param_2 * 8 + 0x3068) + DAT_140017e10);
    if (uVar3 == 0xffffffff) {
      CH_WARN(param_1,"Unable to read PCI-E Memory Window Base[%d]\n",(ulonglong)param_2,
              (ulonglong)param_2);
      uVar2 = 0xfffffffa;
    }
    else {
      iVar6 = 1 << ((char)uVar3 + 10U & 0x1f);
      uVar3 = uVar3 & 0xfffffc00;
      bVar1 = (byte)*(undefined4 *)(param_1 + 0x1d0);
      if ((bVar1 & 0xf0) == 0x40) {
        uVar3 = uVar3 - *(int *)(param_1 + 0x4c0);
      }
      if ((bVar1 & 0xf0) == 0x40) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x4bc);
      }
      uVar10 = (ulonglong)(param_2 * 8 + 0x306c);
      uVar9 = -iVar6 & param_3;
      iVar7 = param_3 - uVar9;
      *(uint *)(uVar10 + DAT_140017e10) = uVar9 | uVar5;
      LOCK();
      UNLOCK();
      if (param_4 - uVar4 != 0) {
        uVar11 = (ulonglong)(((param_4 - uVar4) - 1 >> 2) + 1);
        puVar8 = param_5;
        do {
          param_5 = puVar8 + 1;
          if (param_6 == 1) {
            *puVar8 = *(undefined4 *)((ulonglong)(iVar7 + uVar3) + DAT_140017e10);
          }
          else {
            *(undefined4 *)((ulonglong)(iVar7 + uVar3) + DAT_140017e10) = *puVar8;
            LOCK();
            UNLOCK();
          }
          iVar7 = iVar7 + 4;
          if (iVar7 == iVar6) {
            uVar9 = uVar9 + iVar6;
            iVar7 = 0;
            *(uint *)(uVar10 + DAT_140017e10) = uVar9 | uVar5;
            LOCK();
            UNLOCK();
          }
          uVar11 = uVar11 - 1;
          puVar8 = param_5;
        } while (uVar11 != 0);
      }
      if (uVar4 != 0) {
        if (param_6 == 1) {
          local_res18[0] = *(undefined4 *)((ulonglong)(uVar3 + iVar7) + DAT_140017e10);
          memmove((void *)((ulonglong)uVar4 + (longlong)param_5),
                  (void *)((longlong)local_res18 + (ulonglong)uVar4),4 - (ulonglong)uVar4);
        }
        else {
          local_res18[0] = *param_5;
          memset((void *)((longlong)local_res18 + (ulonglong)uVar4),0,4 - (ulonglong)uVar4);
          *(undefined4 *)((ulonglong)(uVar3 + iVar7) + DAT_140017e10) = local_res18[0];
          LOCK();
          UNLOCK();
        }
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



===== t4_memory_rw_mtype @ 14000abd0 =====

void t4_memory_rw_mtype(longlong param_1,uint param_2,int param_3,int param_4,uint param_5,
                       undefined4 *param_6,int param_7)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_140017e10 + 0x77c0);
  if (param_3 == 4) {
    iVar1 = iVar1 << 0x15;
  }
  else {
    if (param_3 == 3) {
      iVar1 = *(int *)(DAT_140017e10 + 0x77c8) + iVar1 * 2;
    }
    else {
      iVar1 = iVar1 * param_3;
    }
    iVar1 = iVar1 << 0x14;
  }
  t4_memory_rw_addr(param_1,param_2,iVar1 + param_4,param_5,param_6,param_7);
  return;
}



===== t4_ofld_rx_pkts @ 14000ac34 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool t4_ofld_rx_pkts(longlong param_1,undefined8 *param_2,longlong param_3,uint param_4)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  bVar9 = false;
  if (param_2 == (undefined8 *)0x0) {
    puVar5 = (uint *)(param_1 + 8);
  }
  else {
    puVar5 = (uint *)*param_2;
  }
  uVar3 = *puVar5;
  uVar6 = uVar3 & 0xff;
  uVar4 = uVar3 & 0xff;
  if (uVar6 < 0x3b) {
    if (uVar6 == 0x3a) {
      pcVar2 = "CPL_SET_TCB_RPL got!!\n";
    }
    else if (uVar4 == 0x22) {
      pcVar2 = "CPL_GET_TCB_RPL got!!\n";
    }
    else if (uVar4 == 0x23) {
      pcVar2 = "CPL_L2T_WRITE_RPL got!!\n";
    }
    else {
      if (uVar4 == 0x25) {
        DbgPrint("CPL_ACT_OPEN_RPL: atid = 0x%x status = %d\n",
                 puVar5[1] >> 0x10 & 0xff | puVar5[1] & 0x3f00,*(undefined1 *)((longlong)puVar5 + 7)
                );
        goto LAB_14000ae8c;
      }
      if (uVar4 == 0x26) {
        pcVar2 = "CPL_PEER_CLOSE got!!\n";
      }
      else {
        if (uVar4 != 0x32) {
          if (uVar4 != 0x33) goto LAB_14000ad47;
          goto LAB_14000aca6;
        }
        pcVar2 = "CPL_CLOSE_CON_RPL got!!\n";
      }
    }
    DbgPrint(pcVar2);
  }
  else {
    if (uVar6 == 0x40) {
      uVar6 = puVar5[4];
      uVar1 = puVar5[5];
      uVar7 = (puVar5[2] >> 0x10 | puVar5[2] & 0xffff00ff) >> 8 & 0x3fff;
      uVar8 = (uVar6 << 0x10 | uVar6 & 0xff00) << 8 | (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8;
      uVar6 = (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
      uVar3 = (uVar3 & 0xff00) << 8 | uVar3 >> 0x18 | uVar3 >> 8 & 0xff00;
      DbgPrint("CPL_ACT_ESTABLISH: tid = 0x%x atid 0x%x sendseq = 0x%x rcvseq = 0x%x\n",uVar3,uVar7,
               uVar8,uVar6);
      if (DAT_140018233 == '\0') {
        DAT_140018233 = '\x01';
        _DAT_140018208 = uVar7;
        DAT_14001820c = uVar3;
        DAT_140018210 = uVar8;
        DAT_140018214 = uVar6;
      }
      goto LAB_14000ae8c;
    }
    if ((uVar6 == 0x42) || (uVar6 == 0x49)) {
      process_iscsi_pdu((longlong)puVar5,param_3);
      bVar9 = param_4 == 0x42;
      DAT_140018220 = (uint *)0x0;
      DAT_140018228 = (uint *)0x0;
      goto LAB_14000ae8c;
    }
    if (uVar6 != 0xb2) {
      if (uVar6 == 0xc3) {
        if ((char)puVar5[1] == '\0') {
          if (param_4 == 0xc3) {
            return false;
          }
          return false;
        }
        goto LAB_14000ae8c;
      }
LAB_14000ad47:
      DbgPrint("new cpl 0x%x",uVar4);
      goto LAB_14000ae8c;
    }
LAB_14000aca6:
    if (DAT_140018220 == (uint *)0x0) {
      DAT_140018220 = puVar5;
    }
    else if (DAT_140018228 == (uint *)0x0) {
      DAT_140018228 = puVar5;
    }
  }
LAB_14000ae8c:
  if (uVar4 == param_4) {
    bVar9 = true;
  }
  return bVar9;
}



===== t4_ofld_tx @ 14000aeb4 =====

undefined8 t4_ofld_tx(longlong param_1,undefined8 *param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint local_res8;
  uint local_res10;
  
  lVar2 = param_2[1];
  puVar1 = (uint *)(param_1 + 0x318);
  uVar10 = *(uint *)(param_2 + 2);
  dump_t4_tx_done(puVar1);
  if (param_2[1] != 0) {
    uVar3 = *puVar1;
    if (uVar3 - *(int *)(param_1 + 0x31c) < 8) {
      DbgPrint("ofld q is full\n");
    }
    else {
      uVar5 = *(uint *)(param_1 + 0x324);
      uVar8 = (ulonglong)uVar5;
      if ((int *)*param_2 == (int *)0x0) {
        if (*(uint *)(param_2 + 2) < 0x81) {
          uVar9 = 0;
          pvVar7 = (void *)(uVar8 * 0x40 + *(longlong *)(param_1 + 0x340));
          uVar6 = *(uint *)(param_2 + 2) + 0x3f >> 6;
          if (uVar6 != 0) {
            local_res8 = uVar10;
            do {
              uVar10 = 0x40;
              if (local_res8 < 0x40) {
                uVar10 = local_res8;
              }
              memmove(pvVar7,(void *)((ulonglong)(uVar9 << 6) + lVar2),(ulonglong)uVar10);
              local_res8 = local_res8 - uVar10;
              if (local_res8 == 0) {
                if (((ulonglong)uVar10 + (longlong)pvVar7 & 8) != 0) {
                  *(undefined8 *)((ulonglong)uVar10 + (longlong)pvVar7) = 0;
                }
                uVar3 = *puVar1;
                uVar5 = ((int)uVar8 + 1U) % uVar3;
                break;
              }
              uVar3 = *puVar1;
              uVar8 = (ulonglong)((int)uVar8 + 1) % (ulonglong)uVar3;
              uVar5 = (uint)uVar8;
              if (uVar5 == 0) {
                pvVar7 = *(void **)(param_1 + 0x340);
              }
              else {
                pvVar7 = (void *)((longlong)pvVar7 + 0x40);
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar6);
          }
          *(int *)(*(longlong *)(param_1 + 0x338) +
                  ((ulonglong)(*(int *)(param_1 + 0x324) + -1 + uVar6) % (ulonglong)uVar3) * 4) =
               (int)param_2;
          *(int *)(param_1 + 0x31c) = *(int *)(param_1 + 0x31c) + uVar6;
LAB_14000b13f:
          *(uint *)(param_1 + 0x324) = uVar5;
          *(uint *)(DAT_140017e10 + 0x1b000) = *(int *)(param_1 + 0x330) << 0xf | uVar6;
          LOCK();
          UNLOCK();
          return 0;
        }
      }
      else {
        local_res10 = 0;
        uVar3 = *(int *)*param_2 - 1;
        uVar9 = (uVar3 & 1) + 2 + (uVar3 * 3 >> 1);
        uVar3 = *(int *)(param_2 + 2) + 7U >> 3;
        uVar5 = uVar3 + 7 >> 3;
        uVar6 = uVar3 + 7 + uVar9 >> 3;
        if (uVar6 < 9) {
          pvVar7 = (void *)(uVar8 * 0x40 + *(longlong *)(param_1 + 0x340));
          local_res8 = 0;
          if (uVar5 != 0) {
            do {
              uVar3 = 0x40;
              if (uVar10 < 0x40) {
                uVar3 = uVar10;
              }
              memmove(pvVar7,(void *)((ulonglong)(local_res8 << 6) + lVar2),(ulonglong)uVar3);
              uVar10 = uVar10 - uVar3;
              if (uVar10 == 0) {
                if (uVar3 < 0x40) {
                  local_res10 = uVar3;
                }
                else {
                  uVar8 = (ulonglong)((int)uVar8 + 1) % (ulonglong)*puVar1;
                }
                break;
              }
              uVar8 = (ulonglong)((int)uVar8 + 1) % (ulonglong)*puVar1;
              if ((int)uVar8 == 0) {
                pvVar7 = *(void **)(param_1 + 0x340);
              }
              else {
                pvVar7 = (void *)((longlong)pvVar7 + 0x40);
              }
              local_res8 = local_res8 + 1;
            } while (local_res8 < uVar5);
          }
          puVar4 = (uint *)(uVar8 * 0x40 + (ulonglong)local_res10 + *(longlong *)(param_1 + 0x340));
          place_sgl(puVar4,(undefined8 *)(puVar4 + (ulonglong)uVar9 * 2),(longlong)puVar1,
                    (uint *)*param_2);
          *(int *)(*(longlong *)(param_1 + 0x338) +
                  ((ulonglong)(*(int *)(param_1 + 0x324) + -1 + uVar6) % (ulonglong)*puVar1) * 4) =
               (int)param_2;
          *(int *)(param_1 + 0x31c) = *(int *)(param_1 + 0x31c) + uVar6;
          uVar5 = (*(int *)(param_1 + 0x324) + uVar6) % *puVar1;
          goto LAB_14000b13f;
        }
      }
    }
  }
  return 1;
}



===== t4_os_find_pci_capability @ 14000b16c =====

byte t4_os_find_pci_capability(undefined8 param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte local_res18 [8];
  byte local_res20 [8];
  ushort local_28 [8];
  
  local_28[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  iVar2 = 0x30;
  t4_os_pci_read_cfg2(param_1,6,local_28);
  if ((local_28[0] & 0x10) != 0) {
    t4_os_pci_read_cfg1(param_1,0x34,local_res18);
    while (iVar2 = iVar2 + -1, 0x3f < local_res18[0]) {
      bVar1 = local_res18[0] & 0xfc;
      local_res18[0] = bVar1;
      t4_os_pci_read_cfg1(param_1,(uint)bVar1,local_res20);
      if (local_res20[0] == 0xff) {
        return 0;
      }
      if (local_res20[0] == param_2) {
        return bVar1;
      }
      t4_os_pci_read_cfg1(param_1,bVar1 + 1,local_res18);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 0;
}



===== t4_os_pci_read_cfg1 @ 14000b218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_os_pci_read_cfg1(undefined8 param_1,int param_2,undefined1 *param_3)

{
  undefined1 auStack_148 [32];
  undefined1 *local_128;
  undefined4 local_120;
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_128 = local_118;
  local_120 = 0x100;
  StorPortGetBusData(DAT_140018238,4,DAT_140017e0c,DAT_140017e20);
  *param_3 = local_118[param_2];
  return;
}



===== t4_os_pci_read_cfg2 @ 14000b298 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_os_pci_read_cfg2(undefined8 param_1,int param_2,undefined2 *param_3)

{
  undefined1 auStack_148 [32];
  undefined2 *local_128;
  undefined4 local_120;
  undefined2 local_118 [128];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  local_128 = local_118;
  local_120 = 0x100;
  StorPortGetBusData(DAT_140018238,4,DAT_140017e0c,DAT_140017e20);
  *param_3 = *(undefined2 *)((longlong)local_118 + (longlong)param_2);
  return;
}



===== t4_port_init @ 14000b318 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4_port_init(longlong param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  int iVar7;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar4 = 0;
  iVar7 = 0;
  if (*(char *)(param_1 + 0x1c8) != '\0') {
    uVar5 = 0;
    plVar6 = (longlong *)(param_1 + 0x208);
    do {
      puVar3 = (undefined8 *)0x0;
      if (uVar5 < 4) {
        puVar3 = (undefined8 *)*plVar6;
      }
      for (; (*(byte *)(param_1 + 0x1c9) >> (uVar4 & 0x1f) & 1) == 0; uVar4 = uVar4 + 1) {
      }
      uVar2 = t4_init_portinfo_viid(puVar3,param_2,uVar4,param_3,param_4,&local_48,'\x01');
      if (uVar2 != 0) {
        return uVar2;
      }
      lVar1 = *plVar6;
      uVar4 = uVar4 + 1;
      iVar7 = iVar7 + 1;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(lVar1 + 0x48) = local_48;
      *(undefined2 *)(lVar1 + 0x4c) = local_44;
      lVar1 = *plVar6;
      plVar6 = plVar6 + 1;
      *(undefined4 *)(lVar1 + 0x54) = local_48;
      *(undefined2 *)(lVar1 + 0x58) = local_44;
    } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x1c8));
  }
  return 0;
}



===== t4_prep_master_pf @ 14000b3fc =====

ulonglong t4_prep_master_pf(longlong param_1,undefined8 param_2,undefined8 param_3,
                           undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = t4_prep_pf(param_1,param_2,param_3,param_4);
  if (-1 < (int)uVar2) {
    uVar1 = t4_get_flash_params(param_1);
    if ((int)uVar1 < 0) {
      CH_ERR(param_1,"Unable to retrieve Flash parameters ret = %d\n",(ulonglong)-uVar1,param_4);
      uVar2 = (ulonglong)uVar1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== t4_prep_pf @ 14000b448 =====

undefined8 t4_prep_pf(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ushort *puVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  int iVar6;
  ushort local_res10 [4];
  
  uVar5 = t4_wait_dev_ready(param_1,param_2,param_3,param_4);
  if (-1 < (int)uVar5) {
    bVar2 = t4_os_find_pci_capability(param_1,0x10);
    iVar6 = (int)CONCAT71(extraout_var,bVar2);
    if (iVar6 != 0) {
      t4_os_pci_read_cfg2(param_1,iVar6 + 0x12,local_res10);
      *(ushort *)(param_1 + 0xe8) = local_res10[0] & 0xf;
      *(byte *)(param_1 + 0xea) = (byte)(local_res10[0] >> 4) & 0x3f;
    }
    puVar1 = (ushort *)(param_1 + 0xe2);
    t4_os_pci_read_cfg2(param_1,2,puVar1);
    t4_os_pci_read_cfg2(param_1,0,(undefined2 *)(param_1 + 0xe0));
    uVar4 = t4_get_chip_type(param_1,(uint)(*puVar1 >> 0xc));
    *(uint *)(param_1 + 0x1d0) = uVar4;
    if (((byte)uVar4 & 0xf0) == 0x40) {
      *(undefined4 *)(param_1 + 0x1dc) = 0x4000;
      uVar3 = 0x150;
      *(undefined4 *)(param_1 + 0x1d8) = 0x800080;
      *(undefined2 *)(param_1 + 0x1d4) = 0x504;
      *(undefined1 *)(param_1 + 0x1d6) = 2;
    }
    else {
      if ((uVar4 & 0xf0) == 0x50) {
        *(undefined4 *)(param_1 + 0x1dc) = 0x6000;
        *(undefined4 *)(param_1 + 0x1d8) = 0x800080;
        *(undefined2 *)(param_1 + 0x1d4) = 0x504;
        *(undefined1 *)(param_1 + 0x1d6) = 2;
      }
      else {
        if ((uVar4 & 0xf0) != 0x60) {
          CH_ERR(param_1,"Device %d is not supported\n",(ulonglong)*puVar1,param_4);
          return 0xffffffea;
        }
        *(undefined4 *)(param_1 + 0x1dc) = 0;
        *(undefined4 *)(param_1 + 0x1d8) = 0x1000100;
        *(undefined2 *)(param_1 + 0x1d4) = 0x702;
        *(undefined1 *)(param_1 + 0x1d6) = 3;
      }
      uVar3 = 0x200;
    }
    *(undefined2 *)(param_1 + 0x1e0) = uVar3;
    bVar2 = t4_os_find_pci_capability(param_1,3);
    *(int *)(param_1 + 0xe4) = (int)CONCAT71(extraout_var_00,bVar2);
    *(uint *)(param_1 + 0x1c4) =
         (-(uint)((*(uint *)(param_1 + 0x1d0) & 0x100) != 0) & 0x800) + 0x800;
    init_cong_ctrl((undefined2 *)(param_1 + 0x13c),(undefined2 *)(param_1 + 0x17c));
    *(undefined2 *)(param_1 + 0x1c8) = 0x101;
    *(undefined4 *)(param_1 + 0x58) = 50000;
    bVar2 = t4_os_find_pci_capability(param_1,0x10);
    iVar6 = (int)CONCAT71(extraout_var_01,bVar2);
    if (iVar6 != 0) {
      iVar6 = iVar6 + 0x28;
      t4_os_pci_read_cfg2(param_1,iVar6,local_res10);
      local_res10[0] = local_res10[0] & 0xfffd | 0xd;
      StorPortSetBusDataByOffset(DAT_140018238,4,DAT_140017e0c,0,local_res10,iVar6,2);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== t4_query_params_rw @ 14000b668 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4_query_params_rw(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5,
                      uint *param_6,uint *param_7,int param_8,undefined1 param_9)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined1 auStackY_c8 [32];
  undefined7 in_stack_ffffffffffffff61;
  uint local_88 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  puVar4 = local_88;
  if (param_5 < 8) {
    memset(local_88,0,0x40);
    local_88[1] = 0x4000000;
    local_88[0] = ((param_3 & 0xf70000 | param_4 >> 8 | 0xc008ffff) >> 8 | param_4 & 0x3f0000) >> 8
                  | ((param_3 << 8 | param_4) & 0xff00 | param_4 << 0x10) << 8 | param_3 & 0x3f00;
    if (param_5 != 0) {
      uVar5 = (ulonglong)param_5;
      puVar3 = param_7;
      do {
        puVar4 = puVar4 + 2;
        uVar1 = *param_6;
        param_6 = param_6 + 4;
        *puVar4 = (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
        if (param_8 != 0) {
          uVar1 = *puVar3;
          puVar4[1] = (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 |
                      (uVar1 << 0x10 | uVar1 & 0xff00) << 8;
        }
        puVar3 = puVar3 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    iVar2 = t4_wr_mbox_meat_timeout
                      (param_1,param_2,(byte *)local_88,0x40,local_88,
                       CONCAT71(in_stack_ffffffffffffff61,param_9),10000);
    puVar4 = local_88 + 3;
    if (param_5 != 0) {
      uVar5 = (ulonglong)param_5;
      do {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 2;
        *param_7 = (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
        param_7 = param_7 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}



===== t4_read_mtu_tbl @ 14000b84c =====

void t4_read_mtu_tbl(undefined8 param_1,ushort *param_2,byte *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 0;
  pbVar3 = param_3;
  do {
    *(uint *)(DAT_140017e10 + 0x7de4) = uVar2 | 0xff000000;
    LOCK();
    UNLOCK();
    uVar1 = *(undefined4 *)(DAT_140017e10 + 0x7de4);
    *param_2 = (ushort)uVar1 & 0x3fff;
    if (param_3 != (byte *)0x0) {
      *pbVar3 = (byte)((uint)uVar1 >> 0x10) & 0xf;
    }
    uVar2 = uVar2 + 1;
    param_2 = param_2 + 1;
    pbVar3 = pbVar3 + 1;
  } while ((int)uVar2 < 0x10);
  return;
}



===== t4_reclaim_tx_entries @ 14000b8ac =====

int t4_reclaim_tx_entries(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = (uint)(byte)*(ushort *)(*(longlong *)(param_1 + 0x14) + 4) << 8 |
          (uint)(*(ushort *)(*(longlong *)(param_1 + 0x14) + 4) >> 8);
  *param_2 = param_1[2];
  uVar1 = param_1[2];
  if (uVar1 != uVar3) {
    if (uVar3 < uVar1) {
      iVar2 = *param_1 - uVar1;
    }
    else {
      iVar2 = -uVar1;
    }
    iVar2 = iVar2 + uVar3;
    param_1[1] = param_1[1] - iVar2;
    param_1[2] = uVar3;
  }
  return iVar2;
}



===== t4_report_fw_error @ 14000b8f4 =====

void t4_report_fw_error(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if ((int)*(uint *)(DAT_140017e10 + 0x30b8) < 0) {
    CH_ERR(param_1,"Firmware reports adapter error: %s\n",
           (&PTR_s_Crash_140012060)[*(uint *)(DAT_140017e10 + 0x30b8) >> 0x18 & 7],param_4);
    *param_1 = *param_1 & 0xffffffef;
  }
  return;
}



===== t4_set_params_timeout @ 14000b93c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4_set_params_timeout
              (uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5,longlong param_6,
              uint *param_7,uint param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  undefined1 auStackY_b8 [32];
  undefined7 in_stack_ffffffffffffff71;
  uint local_78 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar5 = local_78;
  if (param_5 < 8) {
    memset(local_78,0,0x40);
    local_78[1] = 0x4000000;
    local_78[0] = ((param_3 & 0xf70000 | param_4 >> 8 | 0xa008ffff) >> 8 | param_4 & 0x5f0000) >> 8
                  | ((param_3 << 8 | param_4) & 0xff00 | param_4 << 0x10) << 8 | param_3 & 0x5f00;
    if (param_5 != 0) {
      lVar4 = param_6 - (longlong)param_7;
      do {
        puVar5 = puVar5 + 2;
        uVar1 = *(uint *)(lVar4 + (longlong)param_7);
        uVar2 = *param_7;
        param_7 = param_7 + 4;
        *puVar5 = (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 << 0x10 | uVar1 & 0xff00) << 8;
        puVar5[1] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8;
        param_5 = param_5 - 1;
      } while (param_5 != 0);
    }
    iVar3 = t4_wr_mbox_meat_timeout
                      (param_1,param_2,(byte *)local_78,0x40,(void *)0x0,
                       CONCAT71(in_stack_ffffffffffffff71,1),param_8);
  }
  else {
    iVar3 = -0x16;
  }
  return iVar3;
}



===== t4_set_rxmode @ 14000bab8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4_set_rxmode(uint *param_1,uint param_2,uint param_3,int param_4,uint param_5,uint param_6,
                  uint param_7,uint param_8,undefined1 param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStackY_78 [32];
  undefined7 in_stack_ffffffffffffffb1;
  uint local_38;
  undefined4 uStack_34;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  iVar1 = 0xffff;
  if (-1 < param_4) {
    iVar1 = param_4;
  }
  uVar2 = 3;
  if (-1 < (int)param_5) {
    uVar2 = param_5;
  }
  uVar4 = 3;
  if (-1 < (int)param_6) {
    uVar4 = param_6;
  }
  uVar5 = 3;
  if (-1 < (int)param_7) {
    uVar5 = param_7;
  }
  uVar3 = 3;
  if (-1 < (int)param_8) {
    uVar3 = param_8;
  }
  _local_38 = CONCAT44(0x1000000,
                       (param_3 & 0x5f0000 | param_3 >> 0x10 | 0xa01600) >> 8 |
                       (param_3 << 0x10 | param_3 & 0xff00) << 8);
  local_30 = (ulonglong)
             (((((((iVar1 << 2 | uVar2) << 2 | uVar4) << 2 | uVar5) << 2 | uVar3) & 0xffffff) >> 8 |
              (((((iVar1 << 2 | uVar2) << 2 | uVar4) << 2 | uVar5) << 2 | uVar3) & 0xff00) << 8) >>
              8 | ((((uVar2 & 3) << 2 | uVar4 & 0xf) << 2 | uVar5 & 0x3f) << 2 | uVar3 & 0xff) <<
                  0x10);
  t4_wr_mbox_meat_timeout
            (param_1,param_2,(byte *)&local_38,0x10,(void *)0x0,
             CONCAT71(in_stack_ffffffffffffffb1,param_9),10000);
  return;
}



===== t4_tun_tx @ 14000bc24 =====

undefined8 t4_tun_tx(longlong param_1,longlong *param_2)

{
  uint *_Dst;
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  void *pvVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  
  puVar1 = (uint *)(param_1 + 0x3d8);
  lVar10 = 0;
  if (*(uint *)(DAT_140018200 + 0xc) < 4) {
    lVar10 = *(longlong *)(param_1 + 0x208 + (longlong)(int)*(uint *)(DAT_140018200 + 0xc) * 8);
  }
  pvVar7 = (void *)param_2[1];
  bVar4 = false;
  uVar9 = 0;
  dump_t4_tx_done(puVar1);
  if ((param_2[1] == 0) && (*param_2 == 0)) {
    return 1;
  }
  uVar8 = *(uint *)(param_2 + 2);
  if (uVar8 < 6) {
    return 1;
  }
  if (uVar8 < 0x61) {
    bVar4 = true;
    uVar11 = (ulonglong)uVar8 + 0x27 >> 3;
  }
  else {
    uVar14 = (*(int *)*param_2 - 1U & 1) + 6 + ((*(int *)*param_2 - 1U) * 3 >> 1);
    uVar11 = (ulonglong)uVar14;
    if (0x40 < uVar14) {
      pcVar6 = "ethpkt exceeds max wr length!!\n";
      goto LAB_14000bce1;
    }
  }
  uVar14 = (int)uVar11 + 7U >> 3;
  if (uVar14 <= *puVar1 - *(int *)(param_1 + 0x3dc)) {
    uVar3 = *(uint *)(param_1 + 0x3e4);
    uVar8 = uVar8 + 0x1f;
    if (!bVar4) {
      uVar8 = 0x1f;
    }
    puVar12 = (uint *)((ulonglong)uVar3 * 0x40 + *(longlong *)(param_1 + 0x400));
    puVar12[2] = 0;
    puVar12[3] = 0;
    uVar5 = (int)uVar11 + 1;
    *puVar12 = ((uVar8 & 0xfffffff0 | 0x8000000) >> 0x10 | uVar8 & 0xff0000) >> 8 |
               ((uVar8 & 0xfffffff0) << 0x10 | uVar8 & 0xff00) << 8;
    puVar12[1] = (uVar5 | 0x80000001) >> 0x19 | (uVar5 & 0x1fe0000) >> 9 |
                 ((uVar5 & 0x1fe00) >> 1) << 8 | ((uVar5 | 0x80000001) >> 1) << 0x18;
    if (*(ushort *)((longlong)param_2 + 0x14) != 0) {
      uVar9 = (ulonglong)*(ushort *)((longlong)param_2 + 0x14) << 0x2c | 0x1000000000000000;
    }
    uVar8 = *(uint *)(param_1 + 0x4bc);
    bVar2 = *(byte *)(lVar10 + 0x11);
    *(undefined2 *)(puVar12 + 5) = 0;
    _Dst = puVar12 + 8;
    puVar12[4] = ((uint)bVar2 << 0x10 | 0xee00) >> 8 | uVar8 >> 0x10 & 0xff | (uVar8 & 0xff) << 0x10
                 | uVar8 & 0xff00;
    *(ushort *)((longlong)puVar12 + 0x16) =
         (ushort)*(byte *)((longlong)param_2 + 0x11) | (short)param_2[2] << 8;
    *(ulonglong *)(puVar12 + 6) =
         ((uVar9 & 0xff000000000000 | (uVar9 | 0xc000000000000000) >> 0x10) >> 0x10 |
         uVar9 & 0xff0000000000) >> 0x18;
    puVar12 = puVar12 + uVar11 * 2;
    if (bVar4) {
      if (*(uint **)(param_1 + 0x428) < puVar12) {
        iVar13 = (int)*(uint **)(param_1 + 0x428);
        uVar8 = iVar13 - (int)_Dst;
        memmove(_Dst,pvVar7,(ulonglong)uVar8);
        memmove(*(void **)(param_1 + 0x400),(void *)((longlong)pvVar7 + (ulonglong)uVar8),
                (ulonglong)((int)param_2[2] - uVar8));
        pvVar7 = (void *)((ulonglong)((int)param_2[2] - uVar8) * 0x40 +
                         *(longlong *)(param_1 + 0x400));
        uVar8 = uVar8 + (((int)puVar12 - (int)param_2[2]) - iVar13);
      }
      else {
        memmove(_Dst,pvVar7,(ulonglong)*(uint *)(param_2 + 2));
        uVar8 = ((int)puVar12 - *(uint *)(param_2 + 2)) - (int)_Dst;
        pvVar7 = (void *)((ulonglong)*(uint *)(param_2 + 2) + (longlong)_Dst);
      }
      memset(pvVar7,0,(ulonglong)uVar8);
    }
    else {
      place_sgl(_Dst,(undefined8 *)puVar12,(longlong)puVar1,(uint *)*param_2);
    }
    *(int *)(*(longlong *)(param_1 + 0x3f8) +
            ((ulonglong)((uVar3 - 1) + uVar14) % (ulonglong)*puVar1) * 4) = (int)param_2;
    *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + uVar14;
    *(uint *)(param_1 + 0x3e4) = (*(int *)(param_1 + 0x3e4) + uVar14) % *puVar1;
    *(uint *)(DAT_140017e10 + 0x1b000) = *(int *)(param_1 + 0x3f0) << 0xf | uVar14;
    LOCK();
    UNLOCK();
    return 0;
  }
  pcVar6 = "tun tx q is full!!!\n";
LAB_14000bce1:
  DbgPrint(pcVar6);
  return 1;
}



===== t4_wait_dev_ready @ 14000bef4 =====

undefined8
t4_wait_dev_ready(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  
  if ((*(int *)(DAT_140017e10 + 0x19400) == -1) ||
     (*(int *)(DAT_140017e10 + 0x19400) == -0x11111112)) {
    KeStallExecutionProcessor(500000);
    uVar1 = *(uint *)(DAT_140017e10 + 0x19400);
    if ((uVar1 == 0xffffffff) || (uVar1 == 0xeeeeeeee)) {
      CH_ERR(param_1,"Device didn\'t become ready for access, whoami = %#x\n",(ulonglong)uVar1,
             param_4);
      return 0xfffffffb;
    }
  }
  return 0;
}



===== t4_wait_op_done_val @ 14000bf60 =====

undefined8
t4_wait_op_done_val(undefined8 param_1,uint param_2,uint param_3,uint param_4,int param_5,
                   int param_6,uint *param_7)

{
  uint uVar1;
  
  uVar1 = *(uint *)((ulonglong)param_2 + DAT_140017e10);
  if (((param_3 & uVar1) != 0) != param_4) {
    do {
      param_5 = param_5 + -1;
      if (param_5 == 0) {
        return 0xfffffff5;
      }
      if (param_6 != 0) {
        KeStallExecutionProcessor(param_6);
      }
      uVar1 = *(uint *)((ulonglong)param_2 + DAT_140017e10);
    } while (((param_3 & uVar1) != 0) != param_4);
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = uVar1;
  }
  return 0;
}



===== t4_wr_mbox_meat_timeout @ 14000bff8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4_wr_mbox_meat_timeout
              (uint *param_1,uint param_2,byte *param_3,uint param_4,void *param_5,
              undefined8 param_6,uint param_7)

{
  longlong lVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  byte *pbVar9;
  uint uVar10;
  ulonglong *puVar11;
  undefined1 local_128 [32];
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  ulonglong local_b8;
  uint *local_b0;
  byte *local_a8;
  void *local_98;
  undefined8 local_88;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_128;
  local_98 = param_5;
  iVar3 = param_2 * 0x400;
  local_c4 = iVar3 + 0x1e240;
  uVar7 = (ulonglong)local_c4;
  if (((param_4 & 0xf) == 0) && ((int)param_4 < 0x41)) {
    uVar8 = (ulonglong)(iVar3 + 0x1e280);
    iVar4 = 0;
    do {
      uVar10 = *(uint *)(uVar8 + DAT_140017e10);
      uVar6 = uVar10 & 3;
      if (uVar6 != 0) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    local_c8 = param_2;
    local_c0 = param_4;
    local_b8 = uVar8;
    local_b0 = param_1;
    local_a8 = param_3;
    if (uVar6 == 2) {
      if ((uVar10 & 8) != 0) {
        local_d8 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e278) + 4 + DAT_140017e10),
                            *(undefined4 *)((ulonglong)(iVar3 + 0x1e278) + DAT_140017e10));
        local_e0 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e270) + 4 + DAT_140017e10),
                            *(undefined4 *)((ulonglong)(iVar3 + 0x1e270) + DAT_140017e10));
        local_e8 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e268) + 4 + DAT_140017e10),
                            *(undefined4 *)((ulonglong)(iVar3 + 0x1e268) + DAT_140017e10));
        local_f0 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e260) + 4 + DAT_140017e10),
                            *(undefined4 *)((ulonglong)(iVar3 + 0x1e260) + DAT_140017e10));
        local_f8 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e258) + 4 + DAT_140017e10),
                            *(undefined4 *)((ulonglong)(iVar3 + 0x1e258) + DAT_140017e10));
        local_100 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e250) + 4 + DAT_140017e10),
                             *(undefined4 *)((ulonglong)(iVar3 + 0x1e250) + DAT_140017e10));
        local_108 = CONCAT44(*(undefined4 *)((ulonglong)(iVar3 + 0x1e248) + 4 + DAT_140017e10),
                             *(undefined4 *)((ulonglong)(iVar3 + 0x1e248) + DAT_140017e10));
        CH_ERR(param_1,"found VALID command in mbox %u: %llx %llx %llx %llx %llx %llx %llx %llx\n",
               (ulonglong)param_2,
               CONCAT44(*(undefined4 *)(uVar7 + 4 + DAT_140017e10),
                        *(undefined4 *)(uVar7 + DAT_140017e10)));
      }
      pbVar2 = local_a8;
      iVar3 = 0;
      pbVar9 = local_a8;
      if (0 < (int)param_4) {
        do {
          lVar1 = *(longlong *)pbVar9;
          uVar10 = (uint)((ulonglong)lVar1 >> 0x18);
          *(uint *)((ulonglong)(iVar3 + local_c4) + DAT_140017e10) =
               ((uint)((ulonglong)lVar1 >> 0x20) & 0xff0000 |
               (uint)(ushort)((ulonglong)lVar1 >> 0x30)) >> 8 | uVar10 & 0xff0000 |
               (uint)((ulonglong)lVar1 >> 8) & 0xff000000;
          LOCK();
          UNLOCK();
          *(uint *)((ulonglong)(iVar3 + local_c4) + 4 + DAT_140017e10) =
               (uint)(((lVar1 << 0x10 | (ulonglong)((uint)lVar1 & 0xff00)) << 0x10) >> 8) |
               ((uint)lVar1 & 0xff0000) >> 8 | uVar10 & 0xff;
          LOCK();
          UNLOCK();
          iVar3 = iVar3 + 8;
          pbVar9 = pbVar9 + 8;
        } while (iVar3 < (int)param_4);
        param_1 = local_b0;
        uVar8 = local_b8;
        param_2 = local_c8;
      }
      *(undefined4 *)(uVar8 + DAT_140017e10) = 9;
      LOCK();
      UNLOCK();
      for (iVar3 = 0;
          (iVar4 = *(int *)(DAT_140017e10 + 0x30b8), -1 < iVar4 &&
          (iVar3 < (int)((param_7 ^ (int)param_7 >> 0x1f) - ((int)param_7 >> 0x1f))));
          iVar3 = iVar3 + 1) {
        KeStallExecutionProcessor(1000);
        uVar10 = *(uint *)(uVar8 + DAT_140017e10);
        if ((uVar10 != 0xeeeeeeee) && (((byte)uVar10 & 3) == 2)) {
          if ((uVar10 & 8) != 0) {
            iVar3 = (int)(param_4 + ((int)param_4 >> 0x1f & 7U)) >> 3;
            if (iVar3 != 0) {
              puVar11 = &local_88;
              uVar10 = local_c4;
              do {
                uVar7 = (ulonglong)uVar10;
                uVar10 = uVar10 + 8;
                *puVar11 = ((((ulonglong)*(uint *)(uVar7 + 4 + DAT_140017e10) << 0x10 |
                             ((ulonglong)*(uint *)(uVar7 + 4 + DAT_140017e10) & 0xff0000) << 0x20)
                             >> 0x10 |
                            ((ulonglong)*(uint *)(uVar7 + 4 + DAT_140017e10) & 0xff00) << 0x20) >>
                            0x10 | ((ulonglong)*(uint *)(uVar7 + 4 + DAT_140017e10) & 0xff) << 0x20)
                           >> 8 | ((((ulonglong)*(uint *)(uVar7 + DAT_140017e10) << 0x10 |
                                    (ulonglong)(*(uint *)(uVar7 + DAT_140017e10) & 0xff00)) << 0x10
                                   | (ulonglong)(*(uint *)(uVar7 + DAT_140017e10) & 0xff0000)) <<
                                   0x10 | (ulonglong)*(uint *)(uVar7 + DAT_140017e10) & 0xff000000)
                                  << 8;
                puVar11 = puVar11 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
              param_1 = local_b0;
              uVar8 = local_b8;
              param_4 = local_c0;
            }
            *(undefined4 *)(uVar8 + DAT_140017e10) = 0;
            LOCK();
            UNLOCK();
            uVar10 = ((uint3)((uint7)(undefined7)local_88 >> 0x20) & 0xff0000) >> 8 |
                     (uint)((uint7)(undefined7)local_88 >> 0x18) & 0xff0000 |
                     (uint)((uint7)(undefined7)local_88 >> 8) & 0xff000000 | (uint)local_88._7_1_;
            if ((char)(undefined7)local_88 == -0x7f) {
              fw_asrt(param_1,(longlong)&local_88);
              uVar10 = 0x500;
            }
            else if (local_98 != (void *)0x0) {
              memmove(local_98,&local_88,(longlong)(int)param_4);
            }
            return -((int)uVar10 >> 8 & 0xffU);
          }
          *(undefined4 *)(uVar8 + DAT_140017e10) = 0;
          LOCK();
          UNLOCK();
        }
      }
      uVar7 = (ulonglong)*pbVar2;
      pcVar5 = "command %#x in mailbox %d timed out\n";
      uVar8 = (ulonglong)param_2;
      CH_ERR(param_1,"command %#x in mailbox %d timed out\n",uVar7,uVar8);
      t4_report_fw_error(param_1,pcVar5,uVar7,uVar8);
      iVar3 = (iVar4 >> 0x1f & 0x68U) - 0x6e;
    }
    else {
      t4_report_fw_error(param_1,(ulonglong)uVar10,param_3,uVar7);
      iVar3 = -0x6e;
      if (uVar6 == 1) {
        iVar3 = -0x10;
      }
    }
  }
  else {
    iVar3 = -0x16;
  }
  return iVar3;
}



===== StorPortGetBusData @ 14000c650 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000c650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortSetBusDataByOffset @ 14000c656 =====

void StorPortSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000c656. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetBusDataByOffset();
  return;
}



===== memcmp @ 14000c670 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000c6b3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000c724;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000c720:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000c724;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000c71c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000c720;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000c71c;
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
LAB_14000c724:
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
LAB_14000c6b3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== isspace @ 14000c737 =====

int __cdecl isspace(int _C)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000c737. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = isspace(_C);
  return iVar1;
}



===== _guard_dispatch_icall @ 14000c750 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000c750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 14000c780 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (_Size < 0x4f) {
    uVar4 = _Size & 0xfffffffffffffff8;
    do {
      *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
      uVar4 = uVar4 - 8;
    } while (uVar4 != 0);
    if ((_Size & 7) != 0) {
      *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
    }
    return _Dst;
  }
  *(longlong *)_Dst = lVar3;
  *(longlong *)((longlong)_Dst + 8) = lVar3;
  plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
  uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
  uVar5 = uVar4 >> 7;
  plVar2 = plVar1;
  if (uVar5 != 0) {
    do {
      *plVar2 = lVar3;
      plVar2[1] = lVar3;
      plVar2[2] = lVar3;
      plVar2[3] = lVar3;
      plVar1 = plVar2 + 0x10;
      plVar2[4] = lVar3;
      plVar2[5] = lVar3;
      plVar2[6] = lVar3;
      plVar2[7] = lVar3;
      uVar5 = uVar5 - 1;
      plVar2[8] = lVar3;
      plVar2[9] = lVar3;
      plVar2[10] = lVar3;
      plVar2[0xb] = lVar3;
      plVar2[0xc] = lVar3;
      plVar2[0xd] = lVar3;
      plVar2[0xe] = lVar3;
      plVar2[0xf] = lVar3;
      plVar2 = plVar1;
    } while (uVar5 != 0);
    uVar4 = uVar4 & 0x7f;
  }
  for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
    plVar1 = plVar1 + 2;
  }
  if ((uVar4 & 0xf) != 0) {
    plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
  }
  return _Dst;
}



===== memmove @ 14000c880 =====

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



===== entry @ 140023000 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002302c =====

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


