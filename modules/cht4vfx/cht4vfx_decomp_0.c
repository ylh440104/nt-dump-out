
===== DllUnload @ 180001000 =====

undefined8 DllUnload(void)

{
                    /* 0x1000  1  DllUnload */
  return 0;
}



===== Vf_AllocVi @ 180001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined2
Vf_AllocVi(longlong param_1,ulonglong param_2,uint *param_3,undefined4 *param_4,undefined2 *param_5,
          undefined2 *param_6)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  
                    /* 0x1010  2  Vf_AllocVi */
  uVar5 = 0;
  lVar1 = *(longlong *)(param_1 + 8 + (param_2 & 0xffffffff) * 8);
  *(undefined2 *)(lVar1 + 8) = 0;
  uVar3 = t4vf_alloc_vi(param_1,*(char *)(lVar1 + 0x16));
  *(short *)(lVar1 + 8) = (short)uVar3;
  *param_3 = uVar3 & 0xffff;
  iVar4 = t4vf_port_init(param_1,(uint)*(byte *)(lVar1 + 0x16));
  if (iVar4 == 0) {
    *param_5 = *(undefined2 *)(lVar1 + 0xc);
    lVar2 = *(longlong *)(param_1 + 8 + (ulonglong)*(byte *)(lVar1 + 0x16) * 8);
    *param_4 = *(undefined4 *)(lVar2 + 0x20);
    *(undefined2 *)(param_4 + 1) = *(undefined2 *)(lVar2 + 0x24);
    *param_6 = 1;
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0x40000001,
                     "%s(): viid %#x Vi(%d) rss_size:%d mac:%02x:%02x:%02x:%02x:%02x:%02x",
                     &s_Vf_AllocVi,*(undefined2 *)(lVar1 + 8),0,*(undefined2 *)(lVar1 + 0xc),
                     *(undefined1 *)param_4,*(undefined1 *)((longlong)param_4 + 1),
                     *(undefined1 *)((longlong)param_4 + 2),*(undefined1 *)((longlong)param_4 + 3),
                     *(undefined1 *)(param_4 + 1),*(undefined1 *)((longlong)param_4 + 5));
    uVar5 = *(undefined2 *)(lVar1 + 8);
  }
  else {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_port_init failed error %d",&s_Vf_AllocVi,iVar4);
    t4vf_free_vi(param_1,*(ushort *)(lVar1 + 8));
    *(undefined2 *)(lVar1 + 8) = 0;
  }
  return uVar5;
}



===== Vf_Alloc_MacFilter @ 180001180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Alloc_MacFilter(longlong param_1,uint param_2,byte param_3,uint param_4,longlong param_5,
                      longlong param_6,ulonglong *param_7,char param_8)

{
  int iVar1;
  
                    /* 0x1180  3  Vf_Alloc_MacFilter */
  iVar1 = t4vf_alloc_mac_filt(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 < 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_alloc_mac_filt failed error %d","Vf_Alloc_MacFilter",iVar1);
  }
  return iVar1;
}



===== Vf_And_AdapterFlags @ 180001200 =====

void Vf_And_AdapterFlags(uint *param_1,uint param_2)

{
                    /* 0x1200  4  Vf_And_AdapterFlags */
  *param_1 = *param_1 & param_2;
  return;
}



===== Vf_Change_Mac @ 180001210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint Vf_Change_Mac(longlong param_1,ushort param_2,int param_3,undefined4 *param_4,char param_5,
                  char param_6)

{
  uint uVar1;
  
                    /* 0x1210  5  Vf_Change_Mac */
  uVar1 = t4vf_change_mac(param_1,(uint)param_2,param_3,param_4,param_5,param_6);
  if ((int)uVar1 < 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_change_mac failed error %d","Vf_Change_Mac",uVar1);
  }
  return uVar1;
}



===== Vf_Config_RssRange @ 180001280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Config_RssRange(longlong param_1,uint param_2,int param_3,int param_4,ushort *param_5,
                      int param_6)

{
  int iVar1;
  
                    /* 0x1280  6  Vf_Config_RssRange */
  iVar1 = t4vf_config_rss_range(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_config_rss_range failed error %d","Vf_Config_RssRange",iVar1);
  }
  return iVar1;
}



===== Vf_Config_ViRss @ 1800012f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Config_ViRss(longlong param_1,uint param_2,uint param_3,undefined2 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulonglong local_res8;
  
                    /* 0x12f0  7  Vf_Config_ViRss */
  uVar3 = param_3 & 0x10;
  local_res8 = (ulonglong)(uVar3 != 0);
  uVar2 = (uint)(uVar3 != 0);
  if ((param_3 & 8) != 0) {
    uVar2 = (uVar3 != 0) + 2;
    local_res8 = (ulonglong)uVar2;
  }
  local_res8 = local_res8 << 0x20;
  if ((param_3 & 4) != 0) {
    local_res8 = (ulonglong)uVar2 << 0x20 | 0x400000000;
  }
  uVar3 = uVar2 | 4;
  if ((param_3 & 4) == 0) {
    uVar3 = uVar2;
  }
  if ((param_3 & 2) != 0) {
    local_res8 = (ulonglong)uVar3 << 0x20 | 0x800000000;
  }
  uVar2 = uVar3 | 8;
  if ((param_3 & 2) == 0) {
    uVar2 = uVar3;
  }
  if ((param_3 & 1) != 0) {
    local_res8 = (ulonglong)uVar2 << 0x20 | 0x1000000000;
  }
  local_res8 = CONCAT62(local_res8._2_6_,param_4);
  iVar1 = t4vf_write_rss_vi_config(param_1,param_2,(ushort *)&local_res8);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_write_rss_vi_config failed error %d","Vf_Config_ViRss",iVar1);
  }
  return iVar1;
}



===== Vf_CreateAdapter @ 1800013e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void * Vf_CreateAdapter(undefined8 param_1,undefined8 *param_2)

{
  void *_Dst;
  undefined8 *_Dst_00;
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  
                    /* 0x13e0  8  Vf_CreateAdapter */
  VfLinkStateChange = *param_2;
  Vf_LogMessage = (code *)param_2[1];
  _Dst = (void *)ExAllocatePoolWithTag(ExDefaultNonPagedPoolType,0x280,0x31414656);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x280);
    plVar4 = (longlong *)((longlong)_Dst + 8);
    *(undefined8 *)((longlong)_Dst + 200) = param_1;
    *plVar4 = 0;
    *(undefined8 *)((longlong)_Dst + 0x10) = 0;
    *(undefined8 *)((longlong)_Dst + 0x18) = 0;
    *(undefined8 *)((longlong)_Dst + 0x20) = 0;
    iVar3 = 0;
    do {
      _Dst_00 = (undefined8 *)ExAllocatePoolWithTag(ExDefaultNonPagedPoolType,0x68,0x50494656);
      *(undefined8 **)((longlong)_Dst + (longlong)iVar3 * 8 + 8) = _Dst_00;
      if (_Dst_00 == (undefined8 *)0x0) {
        (*Vf_LogMessage)(*(undefined8 *)((longlong)_Dst + 200),0xc0000003,
                         "%s(): Memory allocation for port_info failed","Vf_CreateAdapter");
        uVar5 = 0;
        do {
          if (*plVar4 != 0) {
            lVar1 = 0;
            if (uVar5 < 4) {
              lVar1 = *plVar4;
            }
            ExFreePoolWithTag(lVar1,0);
          }
          uVar5 = uVar5 + 1;
          plVar4 = plVar4 + 1;
        } while ((int)uVar5 < 4);
        ExFreePoolWithTag(_Dst,0);
        return (void *)0x0;
      }
      memset(_Dst_00,0,0x68);
      uVar2 = (undefined1)iVar3;
      *(undefined1 *)((longlong)_Dst_00 + 0x11) = uVar2;
      *(undefined1 *)((longlong)_Dst_00 + 0x13) = uVar2;
      *(undefined1 *)((longlong)_Dst_00 + 0x16) = uVar2;
      *(undefined1 *)((longlong)_Dst_00 + 0x12) = uVar2;
      iVar3 = iVar3 + 1;
      *_Dst_00 = _Dst;
      *(undefined2 *)((longlong)_Dst_00 + 10) = 0xffff;
    } while (iVar3 < 4);
  }
  return _Dst;
}



===== Vf_CreateVi @ 180001530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Vf_CreateVi(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined1 auStackY_58 [32];
  undefined2 local_28 [2];
  undefined2 local_24 [2];
  undefined4 local_20 [2];
  ulonglong local_18;
  
                    /* 0x1530  9  Vf_CreateVi */
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  lVar1 = *(longlong *)(param_1 + 8 + (longlong)(int)param_2 * 8);
  Vf_AllocVi(param_1,param_2,(uint *)local_24,local_20,(undefined2 *)(lVar1 + 0xc),local_28);
  *(undefined2 *)(lVar1 + 8) = local_24[0];
  return;
}



===== Vf_DeAllocVi @ 180001590 =====

undefined4 Vf_DeAllocVi(longlong *param_1)

{
  undefined4 uVar1;
  longlong *plVar2;
  longlong lVar3;
  
  uVar1 = 0;
  lVar3 = 4;
  plVar2 = param_1;
  do {
    plVar2 = plVar2 + 1;
    if (*(ushort *)(*plVar2 + 8) != 0) {
      uVar1 = t4vf_free_vi((longlong)param_1,*(ushort *)(*plVar2 + 8));
    }
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return uVar1;
}



===== Vf_DestroyAdapter @ 1800015f0 =====

void Vf_DestroyAdapter(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  
                    /* 0x15f0  11  Vf_DestroyAdapter */
  if (param_1 != (longlong *)0x0) {
    uVar2 = 0;
    plVar3 = param_1;
    do {
      plVar3 = plVar3 + 1;
      if (*plVar3 != 0) {
        lVar1 = 0;
        if (uVar2 < 4) {
          lVar1 = *plVar3;
        }
        ExFreePoolWithTag(lVar1,0);
      }
      uVar2 = uVar2 + 1;
    } while ((longlong)uVar2 < 4);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== Vf_Enable_Vi @ 180001650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Enable_Vi(longlong param_1,ushort param_2,byte param_3,uint param_4)

{
  int iVar1;
  
                    /* 0x1650  12  Vf_Enable_Vi */
  iVar1 = t4vf_enable_vi(param_1,(uint)param_2,param_3,param_4);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_enable_vi failed error %d","Vf_Enable_Vi",iVar1);
  }
  return iVar1;
}



===== Vf_Free_MacFilter @ 1800016b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Free_MacFilter(longlong param_1,uint param_2,uint param_3,longlong param_4,char param_5)

{
  int iVar1;
  
                    /* 0x16b0  13  Vf_Free_MacFilter */
  iVar1 = t4vf_free_mac_filt(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 < 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_free_mac_filt failed error %d","Vf_Free_MacFilter",iVar1);
  }
  return iVar1;
}



===== Vf_GetAdapterCsr @ 180001710 =====

undefined8 Vf_GetAdapterCsr(longlong param_1)

{
                    /* 0x1710  14  Vf_GetAdapterCsr */
  return *(undefined8 *)(param_1 + 0x90);
}



===== Vf_GetAdapterCsrLen @ 180001720 =====

undefined4 Vf_GetAdapterCsrLen(longlong param_1)

{
                    /* 0x1720  15  Vf_GetAdapterCsrLen */
  return *(undefined4 *)(param_1 + 0x98);
}



===== Vf_GetLPort @ 180001730 =====

undefined8 Vf_GetLPort(longlong param_1,int param_2)

{
                    /* 0x1730  16  Vf_GetLPort */
  return CONCAT71((int7)(int3)((uint)param_2 >> 8),
                  *(undefined1 *)(*(longlong *)(param_1 + 8 + (longlong)param_2 * 8) + 0x16));
}



===== Vf_GetMacIndex @ 180001740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 Vf_GetMacIndex(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_78 [32];
  undefined8 local_48;
  int local_36;
  short local_32;
  int local_2e;
  short local_2a;
  int local_26;
  short local_22;
  int local_1e;
  ushort local_1a;
  ulonglong local_18;
  
                    /* 0x1740  17  Vf_GetMacIndex */
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  memset(&local_48,0,0x30);
  local_48._0_4_ = 0xc018;
  local_48._4_4_ = 0x3000000;
  uVar2 = 0xffffffff;
  iVar1 = t4vf_wr_mbox_core(param_1,&local_48,0x30,&local_48,'\x01');
  if (iVar1 == 0) {
    if ((local_36 == 0) && (local_32 == 0)) {
      if ((local_2e == 0) && (local_2a == 0)) {
        if ((local_26 == 0) && (local_22 == 0)) {
          local_1e = -local_1e;
          if (local_1e == 0) {
            local_1e = -(uint)local_1a;
          }
          uVar2 = 0xffffffff;
          if (local_1e != 0) {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== Vf_GetPfVfId @ 180001830 =====

void Vf_GetPfVfId(longlong param_1,ushort *param_2,ushort *param_3)

{
  uint uVar1;
  ushort uVar2;
  
                    /* 0x1830  18  Vf_GetPfVfId */
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x90) + 0x200);
  if (param_2 != (ushort *)0x0) {
    if (((byte)*(undefined4 *)(param_1 + 0x278) & 0xf0) == 0x60) {
      uVar2 = (ushort)(uVar1 >> 9);
    }
    else {
      uVar2 = (ushort)(uVar1 >> 8);
    }
    *param_2 = uVar2 & 7;
  }
  if (param_3 != (ushort *)0x0) {
    if (((byte)*(undefined4 *)(param_1 + 0x278) & 0xf0) == 0x60) {
      uVar2 = (ushort)uVar1 & 0xff;
    }
    else {
      uVar2 = (ushort)uVar1 & 0x7f;
    }
    *param_3 = uVar2;
  }
  return;
}



===== Vf_GetPortCount @ 180001890 =====

int Vf_GetPortCount(longlong param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint local_res8 [2];
  uint local_res10 [2];
  
                    /* 0x1890  19  Vf_GetPortCount */
  iVar4 = 0;
  local_res10[0] = 0x1010000;
  local_res8[0] = 0;
  iVar1 = t4vf_query_params(param_1,1,local_res10,local_res8);
  if (iVar1 == 0) {
    iVar3 = 0;
    iVar1 = 0;
    do {
      bVar2 = (byte)iVar1;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + (local_res8[0] >> (bVar2 & 0x1f) & 1);
    } while (iVar1 < 0x20);
    *(char *)(param_1 + 0x27c) = (char)iVar3;
    iVar1 = 0;
    do {
      bVar2 = (byte)iVar1;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + (local_res8[0] >> (bVar2 & 0x1f) & 1);
    } while (iVar1 < 0x20);
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}



===== Vf_GetTxChan @ 180001910 =====

undefined8 Vf_GetTxChan(longlong param_1,int param_2)

{
                    /* 0x1910  20  Vf_GetTxChan */
  return CONCAT71((int7)(int3)((uint)param_2 >> 8),
                  *(undefined1 *)(*(longlong *)(param_1 + 8 + (longlong)param_2 * 8) + 0x13));
}



===== Vf_GetViDetails @ 180001920 =====

undefined2
Vf_GetViDetails(longlong param_1,ulonglong param_2,uint *param_3,undefined8 *param_4,
               undefined2 *param_5,undefined2 *param_6)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
                    /* 0x1920  21  Vf_GetViDetails */
  lVar1 = *(longlong *)(param_1 + 8 + (param_2 & 0xffffffff) * 8);
  *param_3 = (uint)*(ushort *)(lVar1 + 8);
  puVar2 = (undefined4 *)*param_4;
  lVar3 = *(longlong *)(param_1 + 8 + (ulonglong)*(byte *)(lVar1 + 0x16) * 8);
  *puVar2 = *(undefined4 *)(lVar3 + 0x20);
  *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(lVar3 + 0x24);
  *param_5 = *(undefined2 *)(lVar1 + 0xc);
  *param_6 = 1;
  return *(undefined2 *)(lVar1 + 8);
}



===== Vf_GetViid @ 180001970 =====

undefined2 Vf_GetViid(longlong param_1,int param_2)

{
                    /* 0x1970  22  Vf_GetViid */
  return *(undefined2 *)(*(longlong *)(param_1 + 8 + (longlong)param_2 * 8) + 8);
}



===== Vf_Get_AdapterFlags @ 180001980 =====

undefined4 Vf_Get_AdapterFlags(undefined4 *param_1)

{
                    /* 0x1980  23  Vf_Get_AdapterFlags */
  return *param_1;
}



===== Vf_Get_AdapterParams @ 180001990 =====

undefined8 Vf_Get_AdapterParams(longlong param_1,uint param_2,void *param_3)

{
  undefined8 uVar1;
  
                    /* 0x1990  24  Vf_Get_AdapterParams */
  uVar1 = 0xffffffff;
  if (0x27 < param_2) {
    memcpy_s(param_3,0x28,(void *)(param_1 + 0x248),0x28);
    uVar1 = 0;
  }
  return uVar1;
}



===== Vf_Get_Bar2_Address @ 1800019c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Vf_Get_Bar2_Address(longlong param_1,int param_2,uint param_3,uint *param_4,
                             longlong *param_5)

{
  ulonglong uVar1;
  longlong local_res8;
  
                    /* 0x19c0  25  Vf_Get_Bar2_Address */
  uVar1 = t4vf_bar2_sge_qregs(param_1,param_3,param_2,&local_res8,param_4);
  if ((int)uVar1 == 0) {
    *param_5 = local_res8 + *(longlong *)(param_1 + 0xa0);
  }
  else {
    *(undefined4 *)param_5 = 0;
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0x80000002,
                     "%s(): t4vf_bar2_sge_qregs failed error %d","Vf_Get_Bar2_Address",
                     uVar1 & 0xffffffff);
  }
  return uVar1 & 0xffffffff;
}



===== Vf_Get_Closest_Threshold @ 180001a40 =====

uint Vf_Get_Closest_Threshold(longlong param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  
                    /* 0x1a40  26  Vf_Get_Closest_Threshold */
  uVar4 = 0;
  pbVar7 = (byte *)(param_1 + 0x34);
  uVar6 = 0;
  iVar5 = 0x7fffffff;
  do {
    iVar2 = param_2 - (uint)*pbVar7;
    iVar3 = (uint)*pbVar7 - param_2;
    if (-1 < iVar2) {
      iVar3 = iVar2;
    }
    uVar1 = uVar6;
    if (iVar5 <= iVar3) {
      iVar3 = iVar5;
      uVar1 = uVar4;
    }
    uVar4 = uVar1;
    iVar5 = iVar3;
    uVar6 = uVar6 + 1;
    pbVar7 = pbVar7 + 1;
  } while (uVar6 < 4);
  return uVar4;
}



===== Vf_Get_DevParams @ 180001a90 =====

void Vf_Get_DevParams(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0x1a90  27  Vf_Get_DevParams */
  *param_2 = *(undefined4 *)(param_1 + 0x1c0);
  *param_3 = *(undefined4 *)(param_1 + 0x1c4);
  return;
}



===== Vf_Get_OffloadParams @ 180001ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Vf_Get_OffloadParams(longlong param_1,void *param_2)

{
  int iVar1;
  undefined1 auStack_78 [32];
  uint local_58 [12];
  ulonglong local_28;
  
                    /* 0x1ab0  28  Vf_Get_OffloadParams */
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[6] = 0x20d0000;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[7] = 0x20e0000;
  local_58[8] = 0x21f0000;
  local_58[9] = 0x2100000;
  local_58[10] = 0x2110000;
  local_58[0xb] = 0x2120000;
  iVar1 = t4vf_query_params(param_1,6,local_58 + 6,local_58);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x108) = local_58[0];
    *(uint *)(param_1 + 0x10c) = (local_58[1] - local_58[0]) + 1;
    *(int *)(param_1 + 0x110) = local_58[2];
    *(uint *)(param_1 + 0x114) = (local_58[3] - local_58[2]) + 1;
    *(int *)(param_1 + 0x118) = local_58[4];
    local_58[6] = 0x2150000;
    *(uint *)(param_1 + 0x11c) = (local_58[5] - local_58[4]) + 1;
    local_58[7] = 0x2160000;
    local_58[8] = 0x2170000;
    local_58[9] = 0x2180000;
    local_58[10] = 0x2260000;
    local_58[0xb] = 0x2270000;
    iVar1 = t4vf_query_params(param_1,6,local_58 + 6,local_58);
    if (-1 < iVar1) {
      *(int *)(param_1 + 0x120) = local_58[0];
      *(uint *)(param_1 + 0x124) = (local_58[1] - local_58[0]) + 1;
      *(int *)(param_1 + 0x128) = local_58[2];
      *(uint *)(param_1 + 300) = (local_58[3] - local_58[2]) + 1;
      *(int *)(param_1 + 0x130) = local_58[4];
      local_58[6] = 0x2130000;
      *(uint *)(param_1 + 0x134) = (local_58[5] - local_58[4]) + 1;
      local_58[7] = 0x2140000;
      iVar1 = t4vf_query_params(param_1,2,local_58 + 6,local_58);
      if (-1 < iVar1) {
        *(int *)(param_1 + 0x138) = local_58[0];
        *(uint *)(param_1 + 0x13c) = (local_58[1] - local_58[0]) + 1;
      }
    }
  }
  if (iVar1 == 0) {
    memmove(param_2,(void *)(param_1 + 0xf8),0x58);
  }
  return iVar1;
}



===== Vf_Get_PortInfo @ 180001c70 =====

undefined8 Vf_Get_PortInfo(longlong param_1,int param_2)

{
                    /* 0x1c70  29  Vf_Get_PortInfo */
  return *(undefined8 *)(param_1 + 8 + (longlong)param_2 * 8);
}



===== Vf_Get_PortStats @ 180001c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Vf_Get_PortStats(longlong param_1,ulonglong *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x1c80  30  Vf_Get_PortStats */
  uVar1 = t4vf_get_port_stats(param_1,param_3,param_2);
  if ((int)uVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_get_port_stats failed error %d","Vf_Get_PortStats",(int)uVar1);
  }
  return uVar1 & 0xffffffff;
}



===== Vf_Get_SgePktShift @ 180001ce0 =====

uint Vf_Get_SgePktShift(longlong param_1)

{
                    /* 0x1ce0  31  Vf_Get_SgePktShift */
  return *(uint *)(param_1 + 0x1c8) >> 10 & 7;
}



===== Vf_InitAdapter @ 180001cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Vf_InitAdapter(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  
                    /* 0x1cf0  32  Vf_InitAdapter */
  iVar1 = t4vf_get_vfres(param_1);
  if (iVar1 == 0) {
    iVar1 = t4vf_fw_reset(param_1);
    if (iVar1 != 0) {
      pcVar2 = "%s(): t4vf_fw_reset failed error %d";
      goto LAB_180001d11;
    }
    iVar1 = t4vf_get_dev_params(param_1);
    if (iVar1 != 0) {
      pcVar2 = "%s(): t4vf_get_dev_params failed error %d";
      goto LAB_180001d11;
    }
    iVar1 = t4vf_get_vpd_params(param_1);
    if (iVar1 != 0) {
      pcVar2 = "%s(): t4vf_get_vpd_params failed error %d";
      goto LAB_180001d11;
    }
    iVar1 = t4vf_get_sge_params(param_1);
    if (iVar1 != 0) {
      pcVar2 = "%s(): t4vf_get_sge_params failed error %d";
      goto LAB_180001d11;
    }
    iVar1 = t4vf_get_rss_glb_config(param_1);
    if (iVar1 != 0) {
      pcVar2 = "%s(): t4vf_get_rss_glb_config failed error %d";
      goto LAB_180001d11;
    }
    iVar1 = *(int *)(param_1 + 0x240);
    if (iVar1 != 1) {
      pcVar2 = "%s(): unable to operate with global RSS mode %d";
      goto LAB_180001d11;
    }
    local_res10[0] = 0x2310000;
    local_res8[0] = 1;
    t4vf_set_params(param_1,1,(longlong)local_res10,local_res8);
    *(short *)(param_1 + 0x28) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (uint)*(ushort *)(param_1 + 0x232) * 1000) /
                *(uint *)(param_1 + 0x23c));
    *(short *)(param_1 + 0x2a) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (*(uint *)(param_1 + 0x230) & 0xffff) * 1000)
                / *(uint *)(param_1 + 0x23c));
    *(short *)(param_1 + 0x2c) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (uint)*(ushort *)(param_1 + 0x236) * 1000) /
                *(uint *)(param_1 + 0x23c));
    *(short *)(param_1 + 0x2e) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (*(uint *)(param_1 + 0x234) & 0xffff) * 1000)
                / *(uint *)(param_1 + 0x23c));
    *(short *)(param_1 + 0x30) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (uint)*(ushort *)(param_1 + 0x23a) * 1000) /
                *(uint *)(param_1 + 0x23c));
    *(short *)(param_1 + 0x32) =
         (short)(((*(uint *)(param_1 + 0x23c) >> 1) + (*(uint *)(param_1 + 0x238) & 0xffff) * 1000)
                / *(uint *)(param_1 + 0x23c));
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x22b) & 0x3f;
    *(byte *)(param_1 + 0x35) = *(byte *)(param_1 + 0x22a) & 0x3f;
    *(byte *)(param_1 + 0x36) = (byte)((uint)*(undefined4 *)(param_1 + 0x228) >> 8) & 0x3f;
    *(byte *)(param_1 + 0x37) = *(byte *)(param_1 + 0x228) & 0x3f;
    iVar1 = t4vf_get_vfres(param_1);
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x260) == 0) {
        pcVar2 = "%s(): no port access configured";
      }
      else {
        if (*(int *)(param_1 + 0x248) != 0) {
          return 0;
        }
        pcVar2 = "%s(): no virtual interfaces configured";
      }
      (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,pcVar2,"Vf_InitAdapter");
      return 0xc0000001;
    }
  }
  pcVar2 = "%s(): t4vf_get_vfres failed error %d";
LAB_180001d11:
  (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,pcVar2,"Vf_InitAdapter",iVar1);
  return 0xc0000001;
}



===== Vf_InitLinkConfig @ 180001f70 =====

void Vf_InitLinkConfig(longlong param_1,undefined4 param_2,undefined1 param_3,byte param_4)

{
                    /* 0x1f70  33  Vf_InitLinkConfig */
  *(uint *)(param_1 + 0x18) = (uint)param_4;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined1 *)(param_1 + 0x29) = param_3;
  return;
}



===== Vf_NicInq_Enable @ 180001f80 =====

void Vf_NicInq_Enable(longlong param_1,int param_2,uint param_3,uint param_4)

{
                    /* 0x1f80  34  Vf_NicInq_Enable */
  *(uint *)(*(longlong *)(param_1 + 0x90) + 4) = (param_2 << 4 | param_4) << 0xc | param_3;
  LOCK();
  UNLOCK();
  return;
}



===== Vf_Or_AdapterFlags @ 180001fa0 =====

void Vf_Or_AdapterFlags(uint *param_1,uint param_2)

{
                    /* 0x1fa0  35  Vf_Or_AdapterFlags */
  *param_1 = *param_1 | param_2;
  return;
}



===== Vf_PrepAdapter @ 180001fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Vf_PrepAdapter(longlong param_1,uint param_2)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  
                    /* 0x1fb0  36  Vf_PrepAdapter */
  *(undefined4 *)(param_1 + 0xb8) = 0;
  _Dst = (void *)ExAllocatePoolWithTag(ExDefaultNonPagedPoolType,0x500c,0x564d3454);
  *(void **)(param_1 + 0x150) = _Dst;
  if (_Dst == (void *)0x0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): mbox_log memory allocation failed","Vf_PrepAdapter");
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,0x500c);
    **(undefined4 **)(param_1 + 0x150) = 0x100;
    lVar1 = param_1 + 0xe0;
    *(undefined8 *)(param_1 + 0xd0) = 0;
    *(longlong *)(param_1 + 0xe8) = lVar1;
    *(longlong *)lVar1 = lVar1;
    uVar2 = t4vf_prep_adapter(param_1,(ulonglong)param_2);
    if ((int)uVar2 == 0) {
      return 0;
    }
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_prep_adapter failed error %d","Vf_PrepAdapter",(int)uVar2);
    uVar2 = 0xc0000001;
  }
  if (*(longlong *)(param_1 + 0x150) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x150),0x564d3454);
  }
  return uVar2;
}



===== Vf_Query_Params @ 1800020c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Query_Params(longlong param_1,uint param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  
                    /* 0x20c0  37  Vf_Query_Params */
  iVar1 = t4vf_query_params(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_query_params failed error %d","Vf_Query_Params",iVar1);
  }
  return iVar1;
}



===== Vf_Read_Mac @ 180002110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Vf_Read_Mac(longlong param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  undefined1 auStack_88 [32];
  undefined8 local_58;
  undefined4 local_46;
  undefined2 local_42;
  undefined4 local_3e;
  undefined2 local_3a;
  undefined4 local_36;
  undefined2 local_32;
  undefined4 local_2e;
  undefined2 local_2a;
  ulonglong local_28;
  
                    /* 0x2110  38  Vf_Read_Mac */
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  Vf_GetPortCount(param_1);
  memset(&local_58,0,0x30);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x90) + 0x200);
  uVar3 = (ushort)(uVar1 >> 9);
  if ((*(uint *)(param_1 + 0x278) & 0xf0) < 0x51) {
    uVar3 = (ushort)(uVar1 >> 8);
  }
  if ((uVar3 & 7) != 4) {
    param_3 = (uint)(uVar3 & 7);
  }
  local_58._0_4_ = 0xc018;
  local_58._4_4_ = 0x3000000;
  iVar2 = t4vf_wr_mbox_core(param_1,&local_58,0x30,&local_58,'\x01');
  if (iVar2 == 0) {
    if (param_3 == 0) {
      *param_2 = local_46;
      local_2a = local_42;
    }
    else if (param_3 == 1) {
      *param_2 = local_3e;
      local_2a = local_3a;
    }
    else if (param_3 == 2) {
      *param_2 = local_36;
      local_2a = local_32;
    }
    else {
      if (param_3 != 3) {
        return 0;
      }
      *param_2 = local_2e;
    }
    *(undefined2 *)(param_2 + 1) = local_2a;
  }
  return iVar2;
}



===== Vf_Read_Vlan @ 180002210 =====

undefined8 Vf_Read_Vlan(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  
                    /* 0x2210  39  Vf_Read_Vlan */
  uVar1 = t4vf_get_vf_vlan_acl(param_1);
  *param_2 = uVar1;
  return 0;
}



===== Vf_SetAdapterBar2 @ 180002230 =====

void Vf_SetAdapterBar2(longlong param_1,undefined8 param_2)

{
                    /* 0x2230  40  Vf_SetAdapterBar2 */
  *(undefined8 *)(param_1 + 0xa0) = param_2;
  return;
}



===== Vf_SetAdapterBusInterface @ 180002240 =====

void Vf_SetAdapterBusInterface(longlong param_1,undefined8 param_2)

{
                    /* 0x2240  41  Vf_SetAdapterBusInterface */
  *(undefined8 *)(param_1 + 0xb0) = param_2;
  return;
}



===== Vf_SetAdapterCsr @ 180002250 =====

void Vf_SetAdapterCsr(longlong param_1,undefined8 param_2,undefined4 param_3)

{
                    /* 0x2250  42  Vf_SetAdapterCsr */
  *(undefined8 *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  return;
}



===== Vf_SetAdapterPciHeader @ 180002260 =====

void Vf_SetAdapterPciHeader(longlong param_1,undefined8 param_2)

{
                    /* 0x2260  43  Vf_SetAdapterPciHeader */
  *(undefined8 *)(param_1 + 0x88) = param_2;
  return;
}



===== Vf_Set_Params @ 180002270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Set_Params(longlong param_1,uint param_2,longlong param_3,uint *param_4)

{
  int iVar1;
  
                    /* 0x2270  44  Vf_Set_Params */
  iVar1 = t4vf_set_params(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_set_params failed error %d","Vf_Set_Params",iVar1);
  }
  return iVar1;
}



===== Vf_Set_RxMode @ 1800022c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_Set_RxMode(longlong param_1,uint param_2,int param_3,uint param_4,uint param_5,uint param_6,
                 uint param_7,char param_8)

{
  int iVar1;
  
                    /* 0x22c0  45  Vf_Set_RxMode */
  iVar1 = t4vf_set_rxmode(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,
                     "%s(): t4vf_set_rxmode failed error %d","Vf_Set_RxMode",iVar1);
  }
  return iVar1;
}



===== Vf_UnPrepAdapter @ 180002340 =====

void Vf_UnPrepAdapter(longlong param_1)

{
                    /* 0x2340  46  Vf_UnPrepAdapter */
  if (*(longlong *)(param_1 + 0x150) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x150),0x564d3454);
  }
  return;
}



===== Vf_WriteMbox @ 180002360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int Vf_WriteMbox(longlong param_1,ulonglong *param_2,uint param_3,void *param_4)

{
  int iVar1;
  
                    /* 0x2360  47  Vf_WriteMbox */
  iVar1 = t4vf_wr_mbox_core(param_1,param_2,param_3,param_4,'\x01');
  if (iVar1 != 0) {
    (*Vf_LogMessage)(*(undefined8 *)(param_1 + 200),0xc0000003,"%s(): t4vf_wr_mbox failed error %d",
                     "Vf_WriteMbox",iVar1);
  }
  return iVar1;
}



===== Vf_hdl_fw_rpl @ 1800023c0 =====

undefined8 Vf_hdl_fw_rpl(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 *puVar5;
  int iVar6;
  
                    /* 0x23c0  48  Vf_hdl_fw_rpl */
  uVar1 = *param_2;
  if (((char)uVar1 == '\x1b') &&
     ((uVar4 = param_2[1] >> 8 & 0xff | (param_2[1] & 0xff) << 8, uVar4 == 3 || (uVar4 == 10)))) {
    iVar6 = 0;
    if (*(char *)((longlong)param_1 + 0x27c) != '\0') {
      uVar3 = 0;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        plVar2 = (longlong *)0x0;
        if (uVar3 < 4) {
          plVar2 = (longlong *)*puVar5;
        }
        if ((uint)*(byte *)((longlong)plVar2 + 0x11) == (uVar1 >> 0x18 & 0xf)) {
          t4vf_handle_get_port_info(plVar2,(longlong)param_2);
        }
        iVar6 = iVar6 + 1;
        uVar3 = uVar3 + 1;
      } while (iVar6 < (int)(uint)*(byte *)((longlong)param_1 + 0x27c));
    }
  }
  return 0;
}



===== Vf_ingressq_free @ 1800023d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Vf_ingressq_free(longlong param_1,uint param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined1 auStack_a8 [32];
  undefined8 uStack_78;
  ushort uStack_6e;
  ushort uStack_6c;
  ushort uStack_6a;
  int iStack_68;
  ulonglong uStack_38;
  
                    /* 0x23d0  49  Vf_ingressq_free */
  uStack_38 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(&uStack_78,0,0x40);
  uStack_6e = param_3 << 8 | param_3 >> 8;
  uStack_6c = param_4 << 8 | param_4 >> 8;
  uStack_6a = param_5 << 8 | param_5 >> 8;
  iStack_68 = (param_2 & 7) << 5;
  uStack_78._0_4_ = 0x9010;
  uStack_78._4_4_ = 0x4000040;
  t4vf_wr_mbox_core(param_1,&uStack_78,0x40,(void *)0x0,'\x01');
  return;
}



===== Vf_read_reg @ 1800023e0 =====

undefined4 Vf_read_reg(longlong param_1,uint param_2)

{
                    /* 0x23e0  50  Vf_read_reg */
  return *(undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x90));
}



===== Vf_read_reg64 @ 1800023f0 =====

undefined8 Vf_read_reg64(longlong param_1,uint param_2)

{
                    /* 0x23f0  51  Vf_read_reg64 */
  return *(undefined8 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x90));
}



===== Vf_wr_mbox_core @ 180002400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Vf_wr_mbox_core(longlong param_1,ulonglong *param_2,uint param_3,void *param_4,char param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  undefined1 *puVar9;
  ulonglong *puVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  longlong *plStack_b8;
  longlong *plStack_b0;
  uint uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  ulonglong uStack_98;
  void *pvStack_90;
  undefined8 uStack_88;
  ulonglong uStack_48;
  
                    /* 0x2400  52  Vf_wr_mbox_core */
  uStack_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  uStack_a0 = *(uint *)(param_1 + 0x278) & 0xf0;
  uVar11 = (uint)*param_2 & 0xff;
  uStack_a4 = 0x240;
  if (0x50 < uStack_a0) {
    uStack_a4 = 0x280;
  }
  uVar6 = param_3 & 0x8000000f;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
  }
  puVar9 = auStackY_e8;
  if ((uVar6 == 0) && (puVar9 = auStackY_e8, (int)param_3 < 0x41)) {
    uStack_a8 = uVar11;
    pvStack_90 = param_4;
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
    plVar1 = (longlong *)(param_1 + 0xe0);
    *(undefined1 *)(param_1 + 0xd8) = uVar5;
    plVar2 = *(longlong **)(param_1 + 0xe8);
    if ((longlong *)*plVar2 == plVar1) {
      *plVar2 = (longlong)&plStack_b8;
      *(longlong ***)(param_1 + 0xe8) = &plStack_b8;
      plStack_b8 = plVar1;
      plStack_b0 = plVar2;
      KeReleaseSpinLock(param_1 + 0xd0,*(undefined1 *)(param_1 + 0xd8));
      iVar13 = 0;
LAB_180004aa9:
      if ((longlong **)*plVar1 != &plStack_b8) goto code_r0x000180004ab6;
      lVar8 = *(longlong *)(param_1 + 0x90);
      for (iVar7 = 0; (uVar6 = *(uint *)(lVar8 + 0x300) & 3, uVar6 == 0 && (iVar7 < 3));
          iVar7 = iVar7 + 1) {
        lVar8 = *(longlong *)(param_1 + 0x90);
      }
      uVar12 = (undefined2)iVar13;
      if (uVar6 == 2) {
        if (uVar11 != 0x1a) {
          t4vf_record_mbox(param_1,(longlong)param_2,param_3,uVar12,0);
        }
        iVar13 = 0;
        uStack_98 = 0xff00000000;
        puVar10 = param_2;
        if (0 < (int)param_3) {
          do {
            uVar3 = *puVar10;
            *(ulonglong *)((ulonglong)(uStack_a4 + iVar13) + *(longlong *)(param_1 + 0x90)) =
                 (((uVar3 << 0x10 | uVar3 & 0xff00) << 0x10 | (ulonglong)((uint)uVar3 & 0xff0000))
                  << 0x10 | uVar3 & 0xff000000) << 8 |
                 ((longlong)uVar3 >> 0x10 & 0xff000000U | uVar3 & 0xff00000000) >> 8 | uVar3 >> 0x38
                 | (longlong)uVar3 >> 0x28 & 0xff00U;
            LOCK();
            UNLOCK();
            iVar13 = iVar13 + 8;
            puVar10 = puVar10 + 1;
          } while (iVar13 < (int)param_3);
        }
        *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 9;
        LOCK();
        UNLOCK();
        iVar13 = 0;
        do {
          if (param_5 == '\0') {
            KeStallExecutionProcessor(1000);
          }
          else {
            lVar8 = 0x14;
            do {
              KeStallExecutionProcessor(0x31);
              lVar8 = lVar8 + -1;
            } while (lVar8 != 0);
            uVar11 = uStack_a8;
          }
          lVar8 = param_1 + 0xd0;
          uVar6 = *(uint *)(*(longlong *)(param_1 + 0x90) + 0x300);
          if (((byte)uVar6 & 3) == 2) {
            if ((uVar6 & 8) == 0) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 0;
              LOCK();
              UNLOCK();
              goto LAB_180004d82;
            }
            puVar10 = &uStack_88;
            if (param_3 != 0) {
              uVar11 = uStack_a4;
              uVar6 = param_3;
              do {
                uVar3 = *(ulonglong *)((ulonglong)uVar11 + *(longlong *)(param_1 + 0x90));
                uVar11 = uVar11 + 8;
                *puVar10 = (((uVar3 << 0x10 | uVar3 & 0xff00) << 0x10 |
                            (ulonglong)((uint)uVar3 & 0xff0000)) << 0x10 | uVar3 & 0xff000000) << 8
                           | ((longlong)uVar3 >> 0x10 & 0xff000000U | uVar3 & uStack_98) >> 8 |
                           uVar3 >> 0x38 | (longlong)uVar3 >> 0x28 & 0xff00U;
                puVar10 = puVar10 + 1;
                uVar6 = uVar6 - 8;
              } while (uVar6 != 0);
              uVar11 = uStack_a8;
            }
            *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 0;
            LOCK();
            UNLOCK();
            uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
            *(undefined1 *)(param_1 + 0xd8) = uVar5;
            if (((longlong **)plStack_b8[1] != &plStack_b8) ||
               ((longlong **)*plStack_b0 != &plStack_b8)) goto LAB_180004f1f;
            *plStack_b0 = (longlong)plStack_b8;
            plStack_b8[1] = (longlong)plStack_b0;
            KeReleaseSpinLock(lVar8,CONCAT71((int7)((ulonglong)&plStack_b8 >> 8),
                                             *(undefined1 *)(param_1 + 0xd8)));
            if (uVar11 != 0x1a) {
              t4vf_record_mbox(param_1,(longlong)&uStack_88,param_3,uVar12,(short)iVar13 + 1);
            }
            if (pvStack_90 != (void *)0x0) {
              memmove(pvStack_90,&uStack_88,(longlong)(int)param_3);
            }
            iVar13 = -((uStack_88._4_4_ >> 8 & 0xff00U) >> 8);
            goto LAB_180004bff;
          }
LAB_180004d82:
          iVar13 = iVar13 + 1;
        } while (iVar13 < 10000);
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
        *(undefined1 *)(param_1 + 0xd8) = uVar5;
        if (((longlong **)plStack_b8[1] == &plStack_b8) && ((longlong **)*plStack_b0 == &plStack_b8)
           ) {
          *plStack_b0 = (longlong)plStack_b8;
          plStack_b8[1] = (longlong)plStack_b0;
          KeReleaseSpinLock(lVar8,CONCAT71((int7)((ulonglong)&plStack_b8 >> 8),
                                           *(undefined1 *)(param_1 + 0xd8)));
          iVar13 = -0x6e;
          goto LAB_180004be9;
        }
      }
      else {
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
        *(undefined1 *)(param_1 + 0xd8) = uVar5;
        if (((longlong **)plStack_b8[1] == &plStack_b8) && ((longlong **)*plStack_b0 == &plStack_b8)
           ) {
          *plStack_b0 = (longlong)plStack_b8;
          plStack_b8[1] = (longlong)plStack_b0;
          KeReleaseSpinLock(param_1 + 0xd0,
                            CONCAT71((int7)((ulonglong)&plStack_b8 >> 8),
                                     *(undefined1 *)(param_1 + 0xd8)));
          iVar13 = -0x6e;
          if (uVar6 == 1) {
            iVar13 = -0x10;
          }
LAB_180004be9:
          t4vf_record_mbox(param_1,(longlong)param_2,param_3,uVar12,(short)iVar13);
LAB_180004bff:
          puVar9 = auStackY_e8;
          goto LAB_180004f2b;
        }
      }
    }
    goto LAB_180004f1f;
  }
LAB_180004f26:
  iVar13 = -0x16;
LAB_180004f2b:
  *(undefined8 *)(puVar9 + -8) = 0x180004f37;
  return iVar13;
code_r0x000180004ab6:
  if (param_5 == '\0') {
    KeStallExecutionProcessor(1000);
  }
  else {
    lVar8 = 0x14;
    do {
      KeStallExecutionProcessor(0x31);
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    uVar11 = uStack_a8;
  }
  puVar9 = auStackY_e8;
  iVar13 = iVar13 + 1;
  if (20000 < iVar13) goto code_r0x000180004afe;
  goto LAB_180004aa9;
code_r0x000180004afe:
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
  *(undefined1 *)(param_1 + 0xd8) = uVar5;
  if (((longlong **)plStack_b8[1] == &plStack_b8) && ((longlong **)*plStack_b0 == &plStack_b8)) {
    *plStack_b0 = (longlong)plStack_b8;
    plStack_b8[1] = (longlong)plStack_b0;
    KeReleaseSpinLock(param_1 + 0xd0,*(undefined1 *)(param_1 + 0xd8));
    t4vf_record_mbox(param_1,(longlong)param_2,param_3,0xfff0,0);
    iVar13 = -0x10;
    goto LAB_180004f2b;
  }
LAB_180004f1f:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar9 = auStackY_e0;
  goto LAB_180004f26;
}



===== Vf_write_reg @ 180002410 =====

void Vf_write_reg(longlong param_1,uint param_2,undefined4 param_3)

{
                    /* 0x2410  53  Vf_write_reg */
  *(undefined4 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x90)) = param_3;
  LOCK();
  UNLOCK();
  return;
}



===== Vf_write_reg64 @ 180002430 =====

void Vf_write_reg64(longlong param_1,uint param_2,undefined8 param_3)

{
                    /* 0x2430  54  Vf_write_reg64 */
  *(undefined8 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x90)) = param_3;
  LOCK();
  UNLOCK();
  return;
}



===== fwcap_to_speed @ 180002444 =====

uint fwcap_to_speed(uint param_1)

{
  if ((param_1 >> 8 & 1) != 0) {
    return 400000;
  }
  if ((char)param_1 < '\0') {
    return 200000;
  }
  if ((param_1 & 0x40) != 0) {
    return 100000;
  }
  if ((param_1 & 0x20) != 0) {
    return 50000;
  }
  if ((param_1 & 0x10) != 0) {
    return 40000;
  }
  if ((param_1 & 8) != 0) {
    return 25000;
  }
  if ((param_1 & 4) != 0) {
    return 10000;
  }
  if ((param_1 & 2) == 0) {
    return -(uint)((param_1 & 1) != 0) & 100;
  }
  return 1000;
}



===== fwcaps16_to_caps32 @ 1800024a8 =====

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
  uVar2 = uVar1 | 0x200000;
  if ((param_1 & 0x200) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x400000;
  if ((param_1 & 0x400) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x800000;
  if ((param_1 & 0x800) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x1000000;
  if ((param_1 & 0x1000) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x40000;
  if ((param_1 & 0x4000) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x80000;
  if (-1 < (short)param_1) {
    uVar1 = uVar2;
  }
  return uVar1;
}



===== init_link_config @ 1800025b4 =====

void init_link_config(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = param_2;
  uVar2 = param_3 >> 0x16 & 2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[8] = 1;
  param_1[6] = 3;
  param_1[5] = 3;
  uVar1 = uVar2 | 4;
  if ((param_3 & 0x1000000) == 0) {
    uVar1 = uVar2;
  }
  param_1[7] = uVar1;
  param_1[9] = uVar1;
  if ((param_2 >> 0x14 & 1) != 0) {
    *(undefined1 *)(param_1 + 10) = 1;
    param_1[1] = param_3 & 0x100fff;
    param_1[5] = 7;
    return;
  }
  uVar1 = 0x100;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  if (((((param_3 & 0x100) == 0) && (uVar1 = 0x80, (param_3 & 0x80) == 0)) &&
      (uVar1 = 0x40, (param_3 & 0x40) == 0)) &&
     (((uVar1 = 0x20, (param_3 & 0x20) == 0 && (uVar1 = 0x10, (param_3 & 0x10) == 0)) &&
      (uVar1 = 8, (param_3 & 8) == 0)))) {
    if ((param_3 & 4) == 0) {
      if ((param_3 & 2) == 0) {
        uVar1 = param_3 & 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 4;
    }
  }
  param_1[3] = uVar1;
  return;
}



===== t4vf_alloc_mac_filt @ 180002684 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int t4vf_alloc_mac_filt(longlong param_1,uint param_2,byte param_3,uint param_4,longlong param_5,
                       longlong param_6,ulonglong *param_7,char param_8)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  uint3 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined2 *puVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  ushort *puVar16;
  ushort *puVar17;
  uint uVar18;
  int iVar19;
  undefined1 auStack_138 [32];
  undefined8 local_d8;
  undefined2 local_d0;
  undefined4 local_ce;
  undefined2 local_ca [25];
  undefined1 local_98 [8];
  ushort local_90 [28];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_138;
  uVar8 = (uint)param_3;
  iVar19 = 0;
  uVar5 = (uint)*(ushort *)(param_1 + 0x274);
  if (uVar5 < param_4) {
    return -0x16;
  }
  uVar11 = 0;
  uVar18 = param_4;
  if (param_4 != 0) {
    do {
      uVar13 = 7;
      if (uVar18 < 7) {
        uVar13 = (ulonglong)uVar18;
      }
      memset(&local_d8,0,0x40);
      iVar12 = (int)uVar13;
      uVar6 = (uVar8 | 0x15a) << 0x14 | param_2;
      lVar10 = (longlong)(int)uVar11;
      local_d8._0_4_ =
           uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
      uVar6 = (uint)(uVar13 * 8 + 0x17 >> 4);
      local_d8._4_4_ =
           (uVar6 | uVar8 << 0x1f) >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
           uVar6 << 0x18;
      if (iVar12 != 0) {
        puVar14 = (undefined8 *)(param_5 + lVar10 * 8);
        puVar9 = &local_d0;
        uVar15 = uVar13;
        do {
          puVar1 = (undefined4 *)*puVar14;
          *puVar9 = 0xff83;
          puVar14 = puVar14 + 1;
          *(undefined4 *)(puVar9 + 1) = *puVar1;
          puVar9[3] = *(undefined2 *)(puVar1 + 1);
          uVar15 = uVar15 - 1;
          puVar9 = puVar9 + 4;
        } while (uVar15 != 0);
      }
      iVar7 = t4vf_wr_mbox_core(param_1,&local_d8,0x40,local_98,param_8);
      if ((iVar7 != 0) && (iVar7 != -0xc)) break;
      puVar17 = local_90;
      if (iVar12 != 0) {
        puVar14 = (undefined8 *)(param_5 + lVar10 * 8);
        puVar16 = (ushort *)(param_6 + lVar10 * 2);
        do {
          uVar4 = (*puVar17 & 3) << 8 | *puVar17 >> 8;
          uVar8 = (uint)uVar4;
          if (param_6 != 0) {
            if (uVar5 <= uVar8) {
              uVar4 = 0xffff;
            }
            *puVar16 = uVar4;
          }
          if (uVar8 < uVar5) {
            iVar19 = iVar19 + 1;
          }
          else if (param_7 != (ulonglong *)0x0) {
            puVar2 = (undefined1 *)*puVar14;
            uVar3 = CONCAT21(CONCAT11(puVar2[3],puVar2[4]),puVar2[5]) ^
                    CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]);
            uVar3 = uVar3 ^ uVar3 >> 0xc;
            *param_7 = *param_7 | 1L << ((uint3)(uVar3 >> 6 ^ uVar3) & 0x3f);
          }
          puVar16 = puVar16 + 1;
          puVar14 = puVar14 + 1;
          puVar17 = puVar17 + 4;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      uVar8 = 0;
      uVar11 = uVar11 + iVar12;
      uVar18 = uVar18 - iVar12;
    } while (uVar11 < param_4);
    if ((iVar7 != 0) && (iVar7 != -0xc)) {
      return iVar7;
    }
  }
  return iVar19;
}



===== t4vf_alloc_vi @ 1800028f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4vf_alloc_vi(longlong param_1,char param_2)

{
  uint uVar1;
  undefined1 auStack_c8 [32];
  undefined1 local_98 [8];
  ushort local_90;
  undefined8 local_58;
  char local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(&local_58,0,0x40);
  local_48 = param_2 << 4;
  local_58._0_4_ = 0xb014;
  local_58._4_4_ = 0x4000080;
  uVar1 = t4vf_wr_mbox_core(param_1,&local_58,0x40,local_98,'\x01');
  if (uVar1 == 0) {
    uVar1 = (ushort)(local_90 << 8 | local_90 >> 8) & 0xfff;
  }
  return uVar1;
}



===== t4vf_bar2_sge_qregs @ 180002994 =====

undefined8
t4vf_bar2_sge_qregs(longlong param_1,uint param_2,int param_3,longlong *param_4,uint *param_5)

{
  char cVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((byte)*(undefined4 *)(param_1 + 0x278) & 0xf0) == 0x40) {
    uVar2 = 0xffffffea;
  }
  else {
    cVar1 = (char)*(undefined4 *)(param_1 + 0x1dc);
    uVar6 = 1 << (cVar1 + 10U & 0x1f);
    if (param_3 == 0) {
      bVar3 = (byte)*(undefined4 *)(param_1 + 0x1e0);
    }
    else {
      bVar3 = (byte)*(undefined4 *)(param_1 + 0x1e4);
    }
    uVar8 = (1 << (bVar3 & 0x1f)) - 1U & param_2;
    uVar7 = uVar8 << 7;
    lVar4 = (ulonglong)(param_2 >> (bVar3 & 0x3f)) << (cVar1 + 10U & 0x3f);
    if (uVar7 < uVar6) {
      lVar4 = lVar4 + (ulonglong)uVar7;
    }
    *param_4 = lVar4;
    uVar5 = 0;
    if (uVar6 <= uVar7) {
      uVar5 = uVar8;
    }
    *param_5 = uVar5;
    uVar2 = 0;
  }
  return uVar2;
}



===== t4vf_change_mac @ 180002a28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint t4vf_change_mac(longlong param_1,uint param_2,int param_3,undefined4 *param_4,char param_5,
                    char param_6)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  undefined1 auStack_d8 [32];
  undefined8 local_a8;
  ushort local_a0;
  undefined4 local_9e;
  undefined2 local_9a;
  undefined1 local_68 [8];
  ushort local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar1 = *(ushort *)(param_1 + 0x274);
  uVar3 = (ushort)param_3;
  if (param_3 < 0) {
    uVar3 = 0x3ff - (param_5 != '\0');
  }
  memset(&local_a8,0,0x40);
  local_a8._4_4_ = 0x1000000;
  local_a8._0_4_ =
       (param_2 | 0x15a00000) >> 0x18 | ((param_2 | 0x15a00000) & 0xff0000) >> 8 |
       (param_2 & 0xff00) << 8 | param_2 << 0x18;
  local_a0 = uVar3 << 8 | (ushort)(-(ushort)(param_6 != '\0') & 0xc00 | uVar3 | 0x8000) >> 8;
  local_9e = *param_4;
  local_9a = *(undefined2 *)(param_4 + 1);
  uVar2 = t4vf_wr_mbox_core(param_1,&local_a8,0x40,local_68,'\x01');
  if ((uVar2 == 0) && (uVar2 = (ushort)(local_60 << 8 | local_60 >> 8) & 0x3ff, uVar1 <= uVar2)) {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



===== t4vf_config_rss_range @ 180002b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_config_rss_range
              (longlong param_1,uint param_2,int param_3,int param_4,ushort *param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  undefined1 auStack_d8 [32];
  undefined8 local_98;
  ushort local_90;
  ushort local_8e;
  uint local_88 [12];
  ushort local_58 [4];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(&local_98,0,0x40);
  local_98._4_4_ = 0x4000000;
  local_98._0_4_ =
       (param_2 | 0x20a00000) >> 0x18 | ((param_2 | 0x20a00000) & 0xff0000) >> 8 |
       (param_2 & 0xff00) << 8 | param_2 << 0x18;
  puVar6 = param_5;
  do {
    if (param_4 < 1) {
      return 0;
    }
    puVar4 = local_88;
    iVar7 = 0;
    iVar3 = 0x20;
    if (param_4 < 0x20) {
      iVar3 = param_4;
    }
    param_4 = param_4 - iVar3;
    local_90 = (ushort)iVar3 << 8 | (ushort)iVar3 >> 8;
    local_8e = (ushort)param_3 << 8 | (ushort)param_3 >> 8;
    param_3 = param_3 + iVar3;
    while (0 < iVar3) {
      local_58[2] = 0;
      local_58[0] = 0;
      iVar1 = iVar3;
      if (3 < iVar3) {
        iVar1 = 3;
      }
      puVar8 = local_58;
      iVar3 = iVar3 - iVar1;
      local_58[1] = 0;
      while ((iVar1 != 0 && (iVar7 < 0x20))) {
        iVar7 = iVar7 + 1;
        puVar5 = puVar6 + 1;
        *puVar8 = *puVar6;
        puVar8 = puVar8 + 1;
        puVar6 = puVar5;
        if (param_5 + param_6 <= puVar5) {
          puVar6 = param_5;
        }
        iVar1 = iVar1 + -1;
      }
      uVar2 = ((uint)local_58[0] << 10 | (uint)local_58[1]) << 10;
      *puVar4 = ((uint)local_58[0] << 10 & 0x3fffff | (uint)local_58[1]) >> 0xe |
                (uVar2 & 0xff0000) >> 8 | ((uVar2 | local_58[2]) & 0xff00) << 8 |
                (uint)local_58[2] << 0x18;
      puVar4 = puVar4 + 1;
    }
    iVar3 = t4vf_wr_mbox_core(param_1,&local_98,0x40,(void *)0x0,'\x01');
  } while (iVar3 == 0);
  return iVar3;
}



===== t4vf_enable_vi @ 180002cb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4vf_enable_vi(longlong param_1,uint param_2,byte param_3,uint param_4)

{
  undefined1 auStack_58 [32];
  ulonglong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
  local_28[1] = 0;
  local_28[0] = CONCAT44((((uint)param_3 * 2 | param_4 & 0xff) & 3) << 6,
                         (param_2 | 0x17900000) >> 0x18 | ((param_2 | 0x17900000) & 0xff0000) >> 8 |
                         (param_2 & 0xff00) << 8 | param_2 << 0x18) | 0x100000000000000;
  t4vf_wr_mbox_core(param_1,local_28,0x10,(void *)0x0,'\x01');
  return;
}



===== t4vf_free_mac_filt @ 180002d1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_free_mac_filt(longlong param_1,uint param_2,uint param_3,longlong param_4,char param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined1 auStack_c8 [32];
  undefined8 local_88;
  ushort local_80;
  undefined4 local_7e;
  ushort local_7a [25];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar1 = *(ushort *)(param_1 + 0x274);
  iVar6 = 0;
  iVar8 = 0;
  if (uVar1 < param_3) {
    iVar8 = -0x16;
  }
  else {
    iVar9 = 0;
    if (0 < (int)param_3) {
      uVar14 = param_3;
      do {
        uVar11 = 7;
        if (uVar14 < 7) {
          uVar11 = (ulonglong)uVar14;
        }
        memset(&local_88,0,0x40);
        iVar10 = (int)uVar11;
        uVar5 = (uint)(uVar11 * 8 + 0x17 >> 4);
        local_88._4_4_ =
             uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
        if (0 < iVar10) {
          puVar12 = (undefined8 *)(param_4 + (longlong)iVar9 * 8);
          puVar7 = &local_80;
          uVar13 = uVar11;
          do {
            puVar3 = (undefined4 *)*puVar12;
            *puVar7 = 0xfd83;
            puVar12 = puVar12 + 1;
            *(undefined4 *)(puVar7 + 1) = *puVar3;
            puVar7[3] = *(ushort *)(puVar3 + 1);
            uVar13 = uVar13 - 1;
            puVar7 = puVar7 + 4;
          } while (uVar13 != 0);
        }
        local_88._0_4_ =
             (param_2 | 0x15a00000) >> 0x18 | ((param_2 | 0x15a00000) & 0xff0000) >> 8 |
             (param_2 & 0xff00) << 8 | param_2 << 0x18;
        iVar6 = t4vf_wr_mbox_core(param_1,&local_88,0x40,&local_88,param_5);
        if (iVar6 != 0) break;
        puVar7 = &local_80;
        if (iVar10 != 0) {
          do {
            uVar2 = *puVar7;
            puVar7 = puVar7 + 4;
            iVar4 = iVar8 + 1;
            if ((uint)uVar1 <= ((ushort)(uVar2 << 8 | uVar2 >> 8) & 0x3ff)) {
              iVar4 = iVar8;
            }
            iVar8 = iVar4;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        iVar9 = iVar9 + iVar10;
        uVar14 = uVar14 - iVar10;
      } while (iVar9 < (int)param_3);
    }
    if (iVar6 != 0) {
      iVar8 = iVar6;
    }
  }
  return iVar8;
}



===== t4vf_free_vi @ 180002e98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4vf_free_vi(longlong param_1,ushort param_2)

{
  undefined1 auStack_88 [32];
  undefined8 local_58;
  ushort local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(&local_58,0,0x40);
  local_50 = param_2 << 8 | param_2 >> 8;
  local_58._0_4_ = 0x9014;
  local_58._4_4_ = 0x4000040;
  t4vf_wr_mbox_core(param_1,&local_58,0x40,(void *)0x0,'\x01');
  return;
}



===== t4vf_fw_reset @ 180002f1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4vf_fw_reset(longlong param_1)

{
  undefined1 auStack_58 [32];
  ulonglong local_28 [5];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_58;
  local_28[1] = 0;
  local_28[0] = 0x100000000002003;
  t4vf_wr_mbox_core(param_1,local_28,0x10,(void *)0x0,'\x01');
  return;
}



===== t4vf_get_dev_params @ 180002f74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_dev_params(longlong param_1)

{
  int iVar1;
  undefined1 auStack_78 [32];
  uint local_58 [8];
  uint local_38;
  undefined4 local_34;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 0x10b0000;
  local_58[1] = 0x10c0000;
  iVar1 = t4vf_query_params(param_1,2,local_58,&local_38);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x1c0) = local_38;
    *(undefined4 *)(param_1 + 0x1c4) = local_34;
    iVar1 = 0;
  }
  return iVar1;
}



===== t4vf_get_port_stats @ 180002fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 t4vf_get_port_stats(longlong param_1,uint param_2,ulonglong *param_3)

{
  int iVar1;
  undefined4 extraout_var;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong *_Dst;
  undefined1 auStack_218 [32];
  ulonglong uStack_1e8;
  ulonglong uStack_1e0;
  ulonglong uStack_1d8;
  ulonglong uStack_1d0;
  ulonglong uStack_1c8;
  ulonglong uStack_1c0;
  ulonglong uStack_1b8;
  ulonglong uStack_1b0;
  ulonglong uStack_1a8;
  ulonglong uStack_1a0;
  ulonglong uStack_198;
  ulonglong uStack_190;
  ulonglong uStack_188;
  ulonglong uStack_180;
  ulonglong uStack_178;
  ulonglong uStack_170;
  uint auStack_168 [2];
  ushort uStack_160;
  undefined1 auStack_d8 [16];
  undefined1 auStack_c8 [128];
  ulonglong uStack_48;
  
  if (param_2 == 0) {
    *param_3 = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x180);
    param_3[1] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x188);
    param_3[2] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 400);
    param_3[3] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x198);
    param_3[4] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1a0);
    param_3[5] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1a8);
    param_3[6] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1b0);
    param_3[7] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1b8);
    param_3[8] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1c0);
    param_3[9] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1c8);
    param_3[10] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1d0);
    param_3[0xb] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1d8);
    param_3[0xc] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1e0);
    param_3[0xd] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1e8);
    param_3[0xe] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1f0);
    param_3[0xf] = *(ulonglong *)(*(longlong *)(param_1 + 0x90) + 0x1f8);
    return 0;
  }
  uStack_48 = __security_cookie ^ (ulonglong)auStack_218;
  lVar5 = 0;
  if (param_2 < 4) {
    lVar5 = *(longlong *)(param_1 + 8 + (longlong)(int)param_2 * 8);
  }
  uVar4 = 0x10;
  _Dst = &uStack_1e8;
  while( true ) {
    uVar3 = uVar4;
    if (6 < uVar4) {
      uVar3 = 6;
    }
    memset(auStack_168,0,0x90);
    auStack_168[1] = 0x4000000;
    auStack_168[0] =
         (*(ushort *)(lVar5 + 8) & 0xff00) << 8 | 0xc01a | (uint)*(ushort *)(lVar5 + 8) << 0x18;
    uVar2 = 0x10 - (short)uVar4;
    uStack_160 = uVar2 * 0x100 | (ushort)(uVar2 | (short)uVar3 << 0xc) >> 8;
    iVar1 = t4vf_wr_mbox_core(param_1,(ulonglong *)auStack_168,0x40,auStack_d8,'\0');
    if (iVar1 != 0) break;
    memmove(_Dst,auStack_c8,(ulonglong)uVar3 * 8);
    _Dst = _Dst + uVar3;
    uVar4 = uVar4 - uVar3;
    if (uVar4 == 0) {
      *param_3 = (((uStack_1e8 << 0x10 | uStack_1e8 & 0xff00) << 0x10 | uStack_1e8 & 0xff0000) <<
                  0x10 | uStack_1e8 & 0xff000000) << 8 |
                 ((longlong)uStack_1e8 >> 0x10 & 0xff000000U | uStack_1e8 & 0xff00000000) >> 8 |
                 uStack_1e8 >> 0x38 | (longlong)uStack_1e8 >> 0x28 & 0xff00U;
      param_3[1] = (((uStack_1e0 << 0x10 | uStack_1e0 & 0xff00) << 0x10 | uStack_1e0 & 0xff0000) <<
                    0x10 | uStack_1e0 & 0xff000000) << 8 |
                   ((longlong)uStack_1e0 >> 0x10 & 0xff000000U | uStack_1e0 & 0xff00000000) >> 8 |
                   uStack_1e0 >> 0x38 | (longlong)uStack_1e0 >> 0x28 & 0xff00U;
      param_3[2] = (((uStack_1d8 << 0x10 | uStack_1d8 & 0xff00) << 0x10 | uStack_1d8 & 0xff0000) <<
                    0x10 | uStack_1d8 & 0xff000000) << 8 |
                   ((longlong)uStack_1d8 >> 0x10 & 0xff000000U | uStack_1d8 & 0xff00000000) >> 8 |
                   uStack_1d8 >> 0x38 | (longlong)uStack_1d8 >> 0x28 & 0xff00U;
      param_3[3] = (((uStack_1d0 << 0x10 | uStack_1d0 & 0xff00) << 0x10 | uStack_1d0 & 0xff0000) <<
                    0x10 | uStack_1d0 & 0xff000000) << 8 |
                   ((longlong)uStack_1d0 >> 0x10 & 0xff000000U | uStack_1d0 & 0xff00000000) >> 8 |
                   uStack_1d0 >> 0x38 | (longlong)uStack_1d0 >> 0x28 & 0xff00U;
      param_3[4] = (((uStack_1c8 << 0x10 | uStack_1c8 & 0xff00) << 0x10 | uStack_1c8 & 0xff0000) <<
                    0x10 | uStack_1c8 & 0xff000000) << 8 |
                   ((longlong)uStack_1c8 >> 0x10 & 0xff000000U | uStack_1c8 & 0xff00000000) >> 8 |
                   uStack_1c8 >> 0x38 | (longlong)uStack_1c8 >> 0x28 & 0xff00U;
      param_3[5] = (((uStack_1c0 << 0x10 | uStack_1c0 & 0xff00) << 0x10 | uStack_1c0 & 0xff0000) <<
                    0x10 | uStack_1c0 & 0xff000000) << 8 |
                   ((longlong)uStack_1c0 >> 0x10 & 0xff000000U | uStack_1c0 & 0xff00000000) >> 8 |
                   uStack_1c0 >> 0x38 | (longlong)uStack_1c0 >> 0x28 & 0xff00U;
      param_3[6] = (((uStack_1b8 << 0x10 | uStack_1b8 & 0xff00) << 0x10 | uStack_1b8 & 0xff0000) <<
                    0x10 | uStack_1b8 & 0xff000000) << 8 |
                   ((longlong)uStack_1b8 >> 0x10 & 0xff000000U | uStack_1b8 & 0xff00000000) >> 8 |
                   uStack_1b8 >> 0x38 | (longlong)uStack_1b8 >> 0x28 & 0xff00U;
      param_3[7] = (((uStack_1b0 << 0x10 | uStack_1b0 & 0xff00) << 0x10 | uStack_1b0 & 0xff0000) <<
                    0x10 | uStack_1b0 & 0xff000000) << 8 |
                   ((longlong)uStack_1b0 >> 0x10 & 0xff000000U | uStack_1b0 & 0xff00000000) >> 8 |
                   uStack_1b0 >> 0x38 | (longlong)uStack_1b0 >> 0x28 & 0xff00U;
      param_3[8] = (((uStack_1a8 << 0x10 | uStack_1a8 & 0xff00) << 0x10 | uStack_1a8 & 0xff0000) <<
                    0x10 | uStack_1a8 & 0xff000000) << 8 |
                   ((longlong)uStack_1a8 >> 0x10 & 0xff000000U | uStack_1a8 & 0xff00000000) >> 8 |
                   uStack_1a8 >> 0x38 | (longlong)uStack_1a8 >> 0x28 & 0xff00U;
      param_3[9] = (((uStack_1a0 << 0x10 | uStack_1a0 & 0xff00) << 0x10 | uStack_1a0 & 0xff0000) <<
                    0x10 | uStack_1a0 & 0xff000000) << 8 |
                   ((longlong)uStack_1a0 >> 0x10 & 0xff000000U | uStack_1a0 & 0xff00000000) >> 8 |
                   uStack_1a0 >> 0x38 | (longlong)uStack_1a0 >> 0x28 & 0xff00U;
      param_3[10] = (((uStack_198 << 0x10 | uStack_198 & 0xff00) << 0x10 | uStack_198 & 0xff0000) <<
                     0x10 | uStack_198 & 0xff000000) << 8 |
                    ((longlong)uStack_198 >> 0x10 & 0xff000000U | uStack_198 & 0xff00000000) >> 8 |
                    uStack_198 >> 0x38 | (longlong)uStack_198 >> 0x28 & 0xff00U;
      param_3[0xb] = (((uStack_190 << 0x10 | uStack_190 & 0xff00) << 0x10 | uStack_190 & 0xff0000)
                      << 0x10 | uStack_190 & 0xff000000) << 8 |
                     ((longlong)uStack_190 >> 0x10 & 0xff000000U | uStack_190 & 0xff00000000) >> 8 |
                     uStack_190 >> 0x38 | (longlong)uStack_190 >> 0x28 & 0xff00U;
      param_3[0xc] = (((uStack_188 << 0x10 | uStack_188 & 0xff00) << 0x10 | uStack_188 & 0xff0000)
                      << 0x10 | uStack_188 & 0xff000000) << 8 |
                     ((longlong)uStack_188 >> 0x10 & 0xff000000U | uStack_188 & 0xff00000000) >> 8 |
                     uStack_188 >> 0x38 | (longlong)uStack_188 >> 0x28 & 0xff00U;
      param_3[0xd] = (((uStack_180 << 0x10 | uStack_180 & 0xff00) << 0x10 | uStack_180 & 0xff0000)
                      << 0x10 | uStack_180 & 0xff000000) << 8 |
                     ((longlong)uStack_180 >> 0x10 & 0xff000000U | uStack_180 & 0xff00000000) >> 8 |
                     uStack_180 >> 0x38 | (longlong)uStack_180 >> 0x28 & 0xff00U;
      param_3[0xe] = (((uStack_178 << 0x10 | uStack_178 & 0xff00) << 0x10 | uStack_178 & 0xff0000)
                      << 0x10 | uStack_178 & 0xff000000) << 8 |
                     ((longlong)uStack_178 >> 0x10 & 0xff000000U | uStack_178 & 0xff00000000) >> 8 |
                     uStack_178 >> 0x38 | (longlong)uStack_178 >> 0x28 & 0xff00U;
      param_3[0xf] = (((uStack_170 << 0x10 | uStack_170 & 0xff00) << 0x10 | uStack_170 & 0xff0000)
                      << 0x10 | uStack_170 & 0xff000000) << 8 |
                     ((longlong)uStack_170 >> 0x10 & 0xff000000U | uStack_170 & 0xff00000000) >> 8 |
                     uStack_170 >> 0x38 | (longlong)uStack_170 >> 0x28 & 0xff00U;
      return 0;
    }
  }
  return CONCAT44(extraout_var,iVar1);
}



===== t4vf_get_port_stats_fw @ 18000310c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_port_stats_fw(longlong param_1,uint param_2,ulonglong *param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong *_Dst;
  undefined1 auStack_218 [32];
  ulonglong local_1e8;
  ulonglong local_1e0;
  ulonglong local_1d8;
  ulonglong local_1d0;
  ulonglong local_1c8;
  ulonglong local_1c0;
  ulonglong local_1b8;
  ulonglong local_1b0;
  ulonglong local_1a8;
  ulonglong local_1a0;
  ulonglong local_198;
  ulonglong local_190;
  ulonglong local_188;
  ulonglong local_180;
  ulonglong local_178;
  ulonglong local_170;
  uint local_168 [2];
  ushort local_160;
  undefined1 local_d8 [16];
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_218;
  lVar5 = 0;
  if (param_2 < 4) {
    lVar5 = *(longlong *)(param_1 + 8 + (longlong)(int)param_2 * 8);
  }
  uVar4 = 0x10;
  _Dst = &local_1e8;
  while( true ) {
    uVar3 = uVar4;
    if (6 < uVar4) {
      uVar3 = 6;
    }
    memset(local_168,0,0x90);
    local_168[1] = 0x4000000;
    local_168[0] = (*(ushort *)(lVar5 + 8) & 0xff00) << 8 | 0xc01a |
                   (uint)*(ushort *)(lVar5 + 8) << 0x18;
    uVar2 = 0x10 - (short)uVar4;
    local_160 = uVar2 * 0x100 | (ushort)(uVar2 | (short)uVar3 << 0xc) >> 8;
    iVar1 = t4vf_wr_mbox_core(param_1,(ulonglong *)local_168,0x40,local_d8,'\0');
    if (iVar1 != 0) break;
    memmove(_Dst,local_c8,(ulonglong)uVar3 * 8);
    _Dst = _Dst + uVar3;
    uVar4 = uVar4 - uVar3;
    if (uVar4 == 0) {
      *param_3 = (((local_1e8 << 0x10 | local_1e8 & 0xff00) << 0x10 | local_1e8 & 0xff0000) << 0x10
                 | local_1e8 & 0xff000000) << 8 |
                 ((longlong)local_1e8 >> 0x10 & 0xff000000U | local_1e8 & 0xff00000000) >> 8 |
                 local_1e8 >> 0x38 | (longlong)local_1e8 >> 0x28 & 0xff00U;
      param_3[1] = (((local_1e0 << 0x10 | local_1e0 & 0xff00) << 0x10 | local_1e0 & 0xff0000) <<
                    0x10 | local_1e0 & 0xff000000) << 8 |
                   ((longlong)local_1e0 >> 0x10 & 0xff000000U | local_1e0 & 0xff00000000) >> 8 |
                   local_1e0 >> 0x38 | (longlong)local_1e0 >> 0x28 & 0xff00U;
      param_3[2] = (((local_1d8 << 0x10 | local_1d8 & 0xff00) << 0x10 | local_1d8 & 0xff0000) <<
                    0x10 | local_1d8 & 0xff000000) << 8 |
                   ((longlong)local_1d8 >> 0x10 & 0xff000000U | local_1d8 & 0xff00000000) >> 8 |
                   local_1d8 >> 0x38 | (longlong)local_1d8 >> 0x28 & 0xff00U;
      param_3[3] = (((local_1d0 << 0x10 | local_1d0 & 0xff00) << 0x10 | local_1d0 & 0xff0000) <<
                    0x10 | local_1d0 & 0xff000000) << 8 |
                   ((longlong)local_1d0 >> 0x10 & 0xff000000U | local_1d0 & 0xff00000000) >> 8 |
                   local_1d0 >> 0x38 | (longlong)local_1d0 >> 0x28 & 0xff00U;
      param_3[4] = (((local_1c8 << 0x10 | local_1c8 & 0xff00) << 0x10 | local_1c8 & 0xff0000) <<
                    0x10 | local_1c8 & 0xff000000) << 8 |
                   ((longlong)local_1c8 >> 0x10 & 0xff000000U | local_1c8 & 0xff00000000) >> 8 |
                   local_1c8 >> 0x38 | (longlong)local_1c8 >> 0x28 & 0xff00U;
      param_3[5] = (((local_1c0 << 0x10 | local_1c0 & 0xff00) << 0x10 | local_1c0 & 0xff0000) <<
                    0x10 | local_1c0 & 0xff000000) << 8 |
                   ((longlong)local_1c0 >> 0x10 & 0xff000000U | local_1c0 & 0xff00000000) >> 8 |
                   local_1c0 >> 0x38 | (longlong)local_1c0 >> 0x28 & 0xff00U;
      param_3[6] = (((local_1b8 << 0x10 | local_1b8 & 0xff00) << 0x10 | local_1b8 & 0xff0000) <<
                    0x10 | local_1b8 & 0xff000000) << 8 |
                   ((longlong)local_1b8 >> 0x10 & 0xff000000U | local_1b8 & 0xff00000000) >> 8 |
                   local_1b8 >> 0x38 | (longlong)local_1b8 >> 0x28 & 0xff00U;
      param_3[7] = (((local_1b0 << 0x10 | local_1b0 & 0xff00) << 0x10 | local_1b0 & 0xff0000) <<
                    0x10 | local_1b0 & 0xff000000) << 8 |
                   ((longlong)local_1b0 >> 0x10 & 0xff000000U | local_1b0 & 0xff00000000) >> 8 |
                   local_1b0 >> 0x38 | (longlong)local_1b0 >> 0x28 & 0xff00U;
      param_3[8] = (((local_1a8 << 0x10 | local_1a8 & 0xff00) << 0x10 | local_1a8 & 0xff0000) <<
                    0x10 | local_1a8 & 0xff000000) << 8 |
                   ((longlong)local_1a8 >> 0x10 & 0xff000000U | local_1a8 & 0xff00000000) >> 8 |
                   local_1a8 >> 0x38 | (longlong)local_1a8 >> 0x28 & 0xff00U;
      param_3[9] = (((local_1a0 << 0x10 | local_1a0 & 0xff00) << 0x10 | local_1a0 & 0xff0000) <<
                    0x10 | local_1a0 & 0xff000000) << 8 |
                   ((longlong)local_1a0 >> 0x10 & 0xff000000U | local_1a0 & 0xff00000000) >> 8 |
                   local_1a0 >> 0x38 | (longlong)local_1a0 >> 0x28 & 0xff00U;
      param_3[10] = (((local_198 << 0x10 | local_198 & 0xff00) << 0x10 | local_198 & 0xff0000) <<
                     0x10 | local_198 & 0xff000000) << 8 |
                    ((longlong)local_198 >> 0x10 & 0xff000000U | local_198 & 0xff00000000) >> 8 |
                    local_198 >> 0x38 | (longlong)local_198 >> 0x28 & 0xff00U;
      param_3[0xb] = (((local_190 << 0x10 | local_190 & 0xff00) << 0x10 | local_190 & 0xff0000) <<
                      0x10 | local_190 & 0xff000000) << 8 |
                     ((longlong)local_190 >> 0x10 & 0xff000000U | local_190 & 0xff00000000) >> 8 |
                     local_190 >> 0x38 | (longlong)local_190 >> 0x28 & 0xff00U;
      param_3[0xc] = (((local_188 << 0x10 | local_188 & 0xff00) << 0x10 | local_188 & 0xff0000) <<
                      0x10 | local_188 & 0xff000000) << 8 |
                     ((longlong)local_188 >> 0x10 & 0xff000000U | local_188 & 0xff00000000) >> 8 |
                     local_188 >> 0x38 | (longlong)local_188 >> 0x28 & 0xff00U;
      param_3[0xd] = (((local_180 << 0x10 | local_180 & 0xff00) << 0x10 | local_180 & 0xff0000) <<
                      0x10 | local_180 & 0xff000000) << 8 |
                     ((longlong)local_180 >> 0x10 & 0xff000000U | local_180 & 0xff00000000) >> 8 |
                     local_180 >> 0x38 | (longlong)local_180 >> 0x28 & 0xff00U;
      param_3[0xe] = (((local_178 << 0x10 | local_178 & 0xff00) << 0x10 | local_178 & 0xff0000) <<
                      0x10 | local_178 & 0xff000000) << 8 |
                     ((longlong)local_178 >> 0x10 & 0xff000000U | local_178 & 0xff00000000) >> 8 |
                     local_178 >> 0x38 | (longlong)local_178 >> 0x28 & 0xff00U;
      param_3[0xf] = (((local_170 << 0x10 | local_170 & 0xff00) << 0x10 | local_170 & 0xff0000) <<
                      0x10 | local_170 & 0xff000000) << 8 |
                     ((longlong)local_170 >> 0x10 & 0xff000000U | local_170 & 0xff00000000) >> 8 |
                     local_170 >> 0x38 | (longlong)local_170 >> 0x28 & 0xff00U;
      return 0;
    }
  }
  return iVar1;
}



===== t4vf_get_rss_glb_config @ 1800038b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_rss_glb_config(longlong param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_88 [32];
  undefined1 local_58 [8];
  uint local_50;
  uint local_4c;
  undefined8 local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(&local_38,0,0x20);
  local_38._0_4_ = 0xc022;
  local_38._4_4_ = 0x2000000;
  iVar1 = t4vf_wr_mbox_core(param_1,&local_38,0x20,local_58,'\x01');
  if (iVar1 == 0) {
    uVar2 = local_50 >> 4 & 0xf;
    *(uint *)(param_1 + 0x240) = uVar2;
    if (uVar2 == 1) {
      uVar2 = local_4c >> 0x10;
      uVar3 = (uVar2 & 0x400) >> 8;
      *(uint *)(param_1 + 0x244) =
           ((((local_4c & 0xff0000) >> 10 & 0x40 | (uVar2 & 0x8000) >> 8) >> 2 |
            (uVar2 & 0x4000) >> 8) >> 2 | (uVar2 & 0x2000) >> 8) >> 2 |
           ((((uVar2 & 0x200) >> 8) << 2 | uVar3) << 2 | (uVar2 & 0x800) >> 8) << 2 | uVar2 & 0x100
           | *(uint *)(param_1 + 0x244) & 0xfffffe00 | (uVar2 & 0x1000) >> 8;
      if (uVar3 != 0) {
        return 0;
      }
    }
    iVar1 = -0x16;
  }
  return iVar1;
}



===== t4vf_get_sge_params @ 1800039e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_sge_params(longlong param_1)

{
  uint uVar1;
  int iVar2;
  sbyte sVar3;
  uint uVar4;
  undefined1 auStack_78 [32];
  uint local_58 [8];
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 0x3001008;
  local_58[1] = 0x300100c;
  local_58[2] = 0x3001044;
  local_58[3] = 0x3001048;
  local_58[4] = 0x30010b8;
  local_58[5] = 0x30010bc;
  local_58[6] = 0x30010c0;
  iVar2 = t4vf_query_params(param_1,7,local_58,&local_38);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x1c8) = local_38;
    *(undefined4 *)(param_1 + 0x1d0) = local_34;
    *(undefined4 *)(param_1 + 0x1e8) = local_30;
    *(undefined4 *)(param_1 + 0x1ec) = local_2c;
    *(undefined4 *)(param_1 + 0x230) = local_28;
    *(undefined4 *)(param_1 + 0x234) = local_24;
    *(undefined4 *)(param_1 + 0x238) = local_20;
    if (((byte)*(undefined4 *)(param_1 + 0x278) & 0xf0) != 0x40) {
      local_58[0] = 0x3001124;
      iVar2 = t4vf_query_params(param_1,1,local_58,&local_38);
      if (iVar2 != 0) {
        return iVar2;
      }
      *(uint *)(param_1 + 0x1cc) = local_38;
    }
    local_58[0] = 0x30010a0;
    local_58[1] = 0x3001094;
    iVar2 = t4vf_query_params(param_1,2,local_58,&local_38);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x228) = local_38;
      *(undefined4 *)(param_1 + 0x22c) = local_34;
      if (((byte)*(undefined4 *)(param_1 + 0x278) & 0xf0) != 0x40) {
        local_58[0] = 0x3001014;
        local_58[1] = 0x30010f8;
        iVar2 = t4vf_query_params(param_1,2,local_58,&local_38);
        if (iVar2 != 0) {
          return iVar2;
        }
        *(uint *)(param_1 + 0x1d4) = local_38;
        *(undefined4 *)(param_1 + 0x1d8) = local_34;
        uVar1 = *(uint *)(*(longlong *)(param_1 + 0x90) + 0x200);
        uVar4 = uVar1 >> 9;
        if ((*(uint *)(param_1 + 0x278) & 0xf0) < 0x51) {
          uVar4 = uVar1 >> 8;
        }
        sVar3 = (sbyte)((uVar4 & 7) << 2);
        *(uint *)(param_1 + 0x1dc) = *(uint *)(param_1 + 0x1d0) >> sVar3 & 0xf;
        *(uint *)(param_1 + 0x1e0) = *(uint *)(param_1 + 0x1d4) >> sVar3 & 0xf;
        *(uint *)(param_1 + 0x1e4) = *(uint *)(param_1 + 0x1d8) >> sVar3 & 0xf;
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== t4vf_get_vf_vlan_acl @ 180003bd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ushort t4vf_get_vf_vlan_acl(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  undefined8 local_48;
  ushort local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  memset(&local_48,0,0x30);
  uVar1 = 0;
  local_48._0_4_ = 0xc019;
  local_48._4_4_ = 0x3000000;
  iVar2 = t4vf_wr_mbox_core(param_1,&local_48,0x30,&local_48,'\x01');
  if (iVar2 == 0) {
    uVar1 = local_38 << 8 | local_38 >> 8;
  }
  return uVar1;
}



===== t4vf_get_vfres @ 180003c58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_vfres(longlong param_1)

{
  int iVar1;
  undefined1 auStack_88 [32];
  undefined1 local_58 [8];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined8 local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(&local_38,0,0x20);
  local_38._0_4_ = 0xc009;
  local_38._4_4_ = 0x2000000;
  iVar1 = t4vf_wr_mbox_core(param_1,&local_38,0x20,local_58,'\x01');
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x254) = (local_50 & 0xff00 | (local_50 & 0xff) << 0x10) >> 0xc;
    *(uint *)(param_1 + 600) =
         (local_50 & 0xff0000 | local_50 >> 0x10) >> 8 | (local_50 & 0xf00) << 8;
    *(uint *)(param_1 + 0x24c) =
         (local_4c & 0xff0000 | local_4c >> 0x10) >> 8 | (local_4c & 0xf00) << 8;
    *(uint *)(param_1 + 0x260) = (local_4c & 0xff00) >> 0xc;
    *(uint *)(param_1 + 0x25c) = local_48 & 0xff;
    *(uint *)(param_1 + 0x248) = (local_48 & 0xff00) >> 8;
    *(uint *)(param_1 + 0x264) = (local_48 & 0xff0000 | local_48 >> 0x10) >> 8;
    *(uint *)(param_1 + 0x268) = local_44 & 0xff;
    *(uint *)(param_1 + 0x26c) = (local_44 & 0xff00) >> 8;
    *(uint *)(param_1 + 0x250) = (local_44 & 0xff0000 | local_44 >> 0x10) >> 8;
    iVar1 = 0;
  }
  return iVar1;
}



===== t4vf_get_vpd_params @ 180003ddc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_get_vpd_params(longlong param_1)

{
  int iVar1;
  undefined1 auStack_78 [32];
  uint local_58 [8];
  uint local_38 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 0x1000000;
  iVar1 = t4vf_query_params(param_1,1,local_58,local_38);
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x23c) = local_38[0];
    iVar1 = 0;
  }
  return iVar1;
}



===== t4vf_handle_fw_rpl @ 180003e34 =====

undefined8 t4vf_handle_fw_rpl(undefined8 *param_1,uint *param_2)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 *puVar5;
  int iVar6;
  
  uVar1 = *param_2;
  if (((char)uVar1 == '\x1b') &&
     ((uVar4 = param_2[1] >> 8 & 0xff | (param_2[1] & 0xff) << 8, uVar4 == 3 || (uVar4 == 10)))) {
    iVar6 = 0;
    if (*(char *)((longlong)param_1 + 0x27c) != '\0') {
      uVar3 = 0;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        plVar2 = (longlong *)0x0;
        if (uVar3 < 4) {
          plVar2 = (longlong *)*puVar5;
        }
        if ((uint)*(byte *)((longlong)plVar2 + 0x11) == (uVar1 >> 0x18 & 0xf)) {
          t4vf_handle_get_port_info(plVar2,(longlong)param_2);
        }
        iVar6 = iVar6 + 1;
        uVar3 = uVar3 + 1;
      } while (iVar6 < (int)(uint)*(byte *)((longlong)param_1 + 0x27c));
    }
  }
  return 0;
}



===== t4vf_handle_get_port_info @ 180003ee4 =====

void t4vf_handle_get_port_info(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  
  lVar1 = *param_1;
  uVar2 = *(uint *)(param_2 + 4) >> 8 & 0xff | (*(uint *)(param_2 + 4) & 0xff) << 8;
  if (uVar2 == 3) {
    uVar2 = *(uint *)(param_2 + 8);
    uVar9 = (ulonglong)((uVar2 & 0xff00) << 8 | uVar2 << 0x18);
    uVar6 = (uVar2 & 0xff) >> 7;
    bVar12 = (byte)(uVar2 >> 0x1d);
    bVar11 = (byte)(uVar2 >> 0x10) & 0x1f;
    uVar2 = uVar2 >> 0x18 & 0x1f;
    uVar13 = fwcaps16_to_caps32(*(ushort *)(param_2 + 0xc) << 8 | *(ushort *)(param_2 + 0xc) >> 8);
    uVar5 = fwcaps16_to_caps32(*(ushort *)(param_2 + 0xe) << 8 | *(ushort *)(param_2 + 0xe) >> 8);
    uVar10 = fwcaps16_to_caps32(*(ushort *)(param_2 + 0x16) << 8 | *(ushort *)(param_2 + 0x16) >> 8)
    ;
    uVar7 = (uint)(uVar9 >> 6) & 0x10000;
    uVar8 = uVar7 | 0x20000;
    if ((uVar9 & 0x800000) == 0) {
      uVar8 = uVar7;
    }
    uVar7 = uVar8 | 1;
    if ((uVar9 & 0x1000000) == 0) {
      uVar7 = uVar8;
    }
    uVar8 = uVar7 | 2;
    if ((uVar9 & 0x2000000) == 0) {
      uVar8 = uVar7;
    }
    uVar7 = uVar8 | 4;
    if ((uVar9 & 0x8000000) == 0) {
      uVar7 = uVar8;
    }
    uVar8 = uVar7 | 8;
    if ((uVar9 & 0x4000000) == 0) {
      uVar8 = uVar7;
    }
    uVar7 = uVar8 | 0x10;
    if ((uVar9 & 0x10000000) == 0) {
      uVar7 = uVar8;
    }
    if (((uint)uVar9 >> 0x1d & 1) != 0) {
      uVar7 = uVar7 | 0x40;
    }
  }
  else {
    if (uVar2 != 10) {
      return;
    }
    uVar8 = *(uint *)(param_2 + 8);
    uVar13 = *(uint *)(param_2 + 0x14);
    uVar5 = *(uint *)(param_2 + 0x18);
    uVar10 = *(uint *)(param_2 + 0x1c);
    uVar7 = *(uint *)(param_2 + 0x10);
    uVar3 = (uVar8 & 0xff0000) >> 8;
    bVar12 = (byte)((uVar8 & 0xff) >> 4) & 7;
    uVar6 = (uVar8 & 0xff) >> 7;
    uVar2 = (uVar3 & 0x1f00) >> 8;
    bVar11 = (byte)(((uVar3 | (uVar8 & 0xff00) << 8) & 0x1fe000) >> 0xd);
    uVar13 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18;
    uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    uVar10 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
    uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
  }
  uVar3 = uVar5 >> 0x16 & 2;
  uVar8 = uVar3 | 4;
  if ((uVar5 & 0x1000000) == 0) {
    uVar8 = uVar3;
  }
  uVar4 = uVar7 >> 0x10 & 1;
  uVar3 = uVar4 | 2;
  if ((uVar7 & 0x20000) == 0) {
    uVar3 = uVar4;
  }
  uVar7 = fwcap_to_speed(uVar7);
  if (uVar2 != *(byte *)(param_1 + 2)) {
    *(uint *)((longlong)param_1 + 0x54) = uVar8;
    *(byte *)((longlong)param_1 + 0xf) = bVar11;
    *(char *)(param_1 + 2) = (char)uVar2;
  }
  if ((((uVar6 == *(byte *)((longlong)param_1 + 0x61)) && (uVar7 == *(uint *)(param_1 + 9))) &&
      (uVar3 == *(uint *)(param_1 + 10))) && (uVar8 == *(uint *)((longlong)param_1 + 0x5c))) {
    return;
  }
  if ((uVar6 == 0) && (*(byte *)((longlong)param_1 + 0x61) != 0)) {
    *(byte *)((longlong)param_1 + 0x62) = bVar12;
  }
  *(uint *)(param_1 + 9) = uVar7;
  *(char *)((longlong)param_1 + 0x61) = (char)uVar6;
  *(uint *)(param_1 + 10) = uVar3;
  *(uint *)((longlong)param_1 + 0x5c) = uVar8;
  *(uint *)(param_1 + 7) = uVar13;
  *(uint *)(param_1 + 8) = uVar10;
  *(uint *)((longlong)param_1 + 0x3c) = uVar5 & 0x100fff;
  if ((uVar13 & 0x100000) != 0) {
    if ((uVar5 & 0x100000) != 0) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      goto LAB_180004115;
    }
    *(undefined4 *)((longlong)param_1 + 0x3c) = 0;
    uVar2 = fwcap_to_speed(uVar5);
    *(uint *)((longlong)param_1 + 0x44) = uVar2;
  }
  *(undefined1 *)(param_1 + 0xc) = 0;
LAB_180004115:
  t4vf_os_link_changed(lVar1,(uint)*(byte *)((longlong)param_1 + 0x12),uVar6);
  return;
}



===== t4vf_iq_free @ 180004144 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4vf_iq_free(longlong param_1,uint param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined1 auStack_a8 [32];
  undefined8 local_78;
  ushort local_6e;
  ushort local_6c;
  ushort local_6a;
  int local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(&local_78,0,0x40);
  local_6e = param_3 << 8 | param_3 >> 8;
  local_6c = param_4 << 8 | param_4 >> 8;
  local_6a = param_5 << 8 | param_5 >> 8;
  local_68 = (param_2 & 7) << 5;
  local_78._0_4_ = 0x9010;
  local_78._4_4_ = 0x4000040;
  t4vf_wr_mbox_core(param_1,&local_78,0x40,(void *)0x0,'\x01');
  return;
}



===== t4vf_os_link_changed @ 1800041e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void t4vf_os_link_changed(longlong param_1,int param_2,undefined4 param_3)

{
  (*VfLinkStateChange)
            (*(undefined8 *)(param_1 + 200),param_2,
             *(undefined4 *)(*(longlong *)(param_1 + 8 + (longlong)param_2 * 8) + 0x48),param_3);
  return;
}



===== t4vf_port_init @ 180004214 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_port_init(longlong param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  undefined1 auStack_118 [32];
  uint local_e8 [2];
  undefined1 local_e0 [8];
  uint local_d8;
  ushort local_d4;
  ushort local_d2;
  uint local_cc;
  uint local_c8;
  uint local_b8;
  uint local_b4;
  ushort local_b0;
  undefined1 local_78 [10];
  undefined1 local_6e [14];
  ushort local_60;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  lVar5 = 0;
  lVar4 = (longlong)(int)param_2;
  if (param_2 < 4) {
    lVar5 = *(longlong *)(param_1 + 8 + lVar4 * 8);
  }
  uVar8 = (uint)*(byte *)(param_1 + 0x27d);
  if (*(byte *)(param_1 + 0x27d) == 0) {
    local_e8[1] = 0x23a0000;
    local_e8[0] = 1;
    iVar1 = t4vf_set_params(param_1,1,(longlong)(local_e8 + 1),local_e8);
    uVar8 = 2 - (iVar1 != 0);
    *(char *)(param_1 + 0x27d) = (char)uVar8;
  }
  memset(&local_b8,0,0x40);
  local_b0 = *(ushort *)(lVar5 + 8) << 8 | *(ushort *)(lVar5 + 8) >> 8;
  local_b8 = 0xc014;
  local_b4 = 0x4000000;
  iVar1 = t4vf_wr_mbox_core(param_1,(ulonglong *)&local_b8,0x40,local_78,'\x01');
  if (iVar1 == 0) {
    *(ushort *)(lVar5 + 0xc) = (local_60 & 7) << 8 | local_60 >> 8;
    memcpy_s((void *)(*(longlong *)(param_1 + 8 + lVar4 * 8) + 0x20),6,local_6e,6);
    memcpy_s((void *)(*(longlong *)(param_1 + 8 + lVar4 * 8) + 0x2c),6,local_6e,6);
    if ((*(uint *)(param_1 + 0x268) & 4) != 0) {
      memset(&local_b8,0,0x20);
      local_b8 = (uint)*(byte *)(lVar5 + 0x11) << 0x18 | 0xc01b;
      iVar1 = 10;
      if (uVar8 == 1) {
        iVar1 = 3;
      }
      local_b4 = iVar1 << 8 | 0x2000000;
      iVar1 = t4vf_wr_mbox_core(param_1,(ulonglong *)&local_b8,0x20,local_e0,'\x01');
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = local_d8 & 0xff00;
      uVar3 = local_d8 >> 8 & 0xff00;
      if (uVar8 == 1) {
        bVar6 = (byte)(uVar3 >> 8) & 0x1f;
        bVar7 = 0xff;
        if ((uVar2 << 8 & 0x200000) != 0) {
          bVar7 = (byte)(uVar2 >> 8) & 0x1f;
        }
        uVar8 = fwcaps16_to_caps32(local_d4 << 8 | local_d4 >> 8);
        uVar2 = fwcaps16_to_caps32(local_d2 << 8 | local_d2 >> 8);
      }
      else {
        bVar6 = (byte)((uVar2 << 8 | uVar3) >> 0xd);
        bVar7 = 0xff;
        if ((local_d8 << 0x10 & 0x40000) != 0) {
          bVar7 = (byte)((local_d8 << 0x10 & 0xffffff | uVar2) >> 0xd) & 0x1f;
        }
        uVar8 = (local_cc & 0xff0000 | local_cc >> 0x10) >> 8 |
                (local_cc << 0x10 | local_cc & 0xff00) << 8;
        uVar2 = (local_c8 & 0xff0000 | local_c8 >> 0x10) >> 8 |
                (local_c8 << 0x10 | local_c8 & 0xff00) << 8;
      }
      *(byte *)(lVar5 + 0xf) = bVar6;
      *(byte *)(lVar5 + 0xe) = bVar7;
      *(undefined1 *)(lVar5 + 0x10) = 0;
      init_link_config((uint *)(lVar5 + 0x38),uVar8,uVar2);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== t4vf_prep_adapter @ 180004494 =====

undefined8 t4vf_prep_adapter(longlong param_1,ulonglong param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = t4vf_wait_dev_ready(param_1);
  uVar3 = 0;
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar4 = (uint)(param_2 >> 0xc) & 0xfffff;
  *(undefined1 *)(param_1 + 0x27c) = 1;
  *(undefined4 *)(param_1 + 0x260) = 1;
  *(undefined4 *)(param_1 + 0x23c) = 50000;
  *(undefined4 *)(param_1 + 0x278) = 0;
  if (uVar4 == 4) {
LAB_18000455a:
    *(undefined4 *)(param_1 + 0x270) = 0x4000;
    *(uint *)(param_1 + 0x278) = uVar3 | 0x40;
    uVar1 = 0x150;
  }
  else {
    if (uVar4 == 5) {
LAB_18000452f:
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x90) + 4);
      *(undefined4 *)(param_1 + 0x270) = 0x6000;
      uVar3 = uVar3 & 0xf | 0x50;
    }
    else {
      if (uVar4 != 6) {
        if (uVar4 == 10) {
          *(undefined4 *)(param_1 + 0x278) = 0x100;
          uVar3 = 0x100;
          goto LAB_18000455a;
        }
        if (uVar4 == 0xb) {
          *(undefined4 *)(param_1 + 0x278) = 0x100;
          goto LAB_18000452f;
        }
        if (uVar4 != 0xc) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x278) = 0x100;
      }
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x90) + 4);
      *(undefined4 *)(param_1 + 0x270) = 0;
      uVar3 = uVar3 & 0xf | 0x60;
    }
    *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | uVar3;
    uVar1 = 0x200;
  }
  *(undefined2 *)(param_1 + 0x274) = uVar1;
  return 0;
}



===== t4vf_query_params @ 180004588 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_query_params(longlong param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_e8 [32];
  undefined8 local_b8;
  uint local_b0 [14];
  undefined1 local_78 [12];
  uint local_6c [13];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  uVar4 = (ulonglong)param_2;
  if (param_2 < 8) {
    memset(&local_b8,0,0x40);
    local_b8._0_4_ = 0xc008;
    puVar3 = local_b0;
    uVar1 = (uint)(uVar4 * 8 + 0x17 >> 4);
    local_b8._4_4_ = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
    ;
    if (param_2 != 0) {
      uVar5 = uVar4;
      do {
        uVar1 = *param_3;
        param_3 = param_3 + 1;
        *puVar3 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        puVar3 = puVar3 + 2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    iVar2 = t4vf_wr_mbox_core(param_1,&local_b8,0x40,local_78,'\x01');
    if (param_2 != 0) {
      puVar3 = local_6c;
      do {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 2;
        *param_4 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        param_4 = param_4 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}



===== t4vf_record_mbox @ 180004668 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void t4vf_record_mbox(longlong param_1,longlong param_2,int param_3,undefined2 param_4,
                     undefined2 param_5)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  int iVar6;
  longlong lVar7;
  
  piVar1 = *(int **)(param_1 + 0x150);
  iVar6 = piVar1[1] + 1;
  puVar4 = (ulonglong *)(piVar1 + (ulonglong)(uint)piVar1[1] * 0x14 + 3);
  if (iVar6 == *piVar1) {
    iVar6 = 0;
  }
  piVar1[1] = iVar6;
  iVar3 = (int)(param_3 + (param_3 >> 0x1f & 7U)) >> 3;
  lVar7 = (longlong)iVar3;
  iVar6 = 0;
  if (0 < iVar3) {
    puVar5 = puVar4;
    do {
      uVar2 = *(ulonglong *)((param_2 - (longlong)puVar4) + (longlong)puVar5);
      *puVar5 = ((((ulonglong)((uint)uVar2 & 0xff00) | uVar2 << 0x10) << 0x10 |
                 (ulonglong)((uint)uVar2 & 0xff0000)) << 0x10 | uVar2 & 0xff000000) << 8 |
                ((longlong)uVar2 >> 0x10 & 0xff000000U | uVar2 & 0xff00000000) >> 8 | uVar2 >> 0x38
                | (ulonglong)((uint)((longlong)uVar2 >> 0x28) & 0xff00);
      puVar5 = puVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    iVar6 = iVar3;
    if (7 < iVar3) goto LAB_180004785;
  }
  memset(puVar4 + iVar6,0,(longlong)(8 - iVar6) << 3);
LAB_180004785:
  puVar4[8] = _DAT_fffff78000000320;
  *(int *)(puVar4 + 9) = piVar1[2];
  piVar1[2] = piVar1[2] + 1;
  *(undefined2 *)((longlong)puVar4 + 0x4c) = param_4;
  *(undefined2 *)((longlong)puVar4 + 0x4e) = param_5;
  return;
}



===== t4vf_set_params @ 1800047cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_set_params(longlong param_1,uint param_2,longlong param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_98 [32];
  undefined8 local_68;
  uint local_60 [14];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  uVar5 = (ulonglong)param_2;
  if (param_2 < 8) {
    memset(&local_68,0,0x40);
    local_68._0_4_ = 0xa008;
    uVar1 = (uint)(uVar5 * 8 + 0x17 >> 4);
    local_68._4_4_ = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
    ;
    if (param_2 != 0) {
      lVar4 = param_3 - (longlong)param_4;
      puVar3 = local_60;
      do {
        uVar1 = *(uint *)(lVar4 + (longlong)param_4);
        *puVar3 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        uVar1 = *param_4;
        param_4 = param_4 + 1;
        puVar3[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        uVar5 = uVar5 - 1;
        puVar3 = puVar3 + 2;
      } while (uVar5 != 0);
    }
    iVar2 = t4vf_wr_mbox_core(param_1,&local_68,0x40,(void *)0x0,'\x01');
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}



===== t4vf_set_rxmode @ 180004890 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void t4vf_set_rxmode(longlong param_1,uint param_2,int param_3,uint param_4,uint param_5,
                    uint param_6,uint param_7,char param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_58 [32];
  uint local_28;
  undefined4 uStack_24;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  iVar3 = 0xffff;
  if (-1 < param_3) {
    iVar3 = param_3;
  }
  _local_28 = CONCAT44(0x1000000,
                       (param_2 | 0x16a00000) >> 0x18 | ((param_2 | 0x16a00000) & 0xff0000) >> 8 |
                       (param_2 & 0xff00) << 8 | param_2 << 0x18);
  uVar5 = 3;
  if (-1 < (int)param_4) {
    uVar5 = param_4;
  }
  uVar1 = 3;
  if (-1 < (int)param_5) {
    uVar1 = param_5;
  }
  uVar2 = 3;
  if (-1 < (int)param_6) {
    uVar2 = param_6;
  }
  uVar4 = 3;
  if (-1 < (int)param_7) {
    uVar4 = param_7;
  }
  uVar4 = (((iVar3 << 2 | uVar5) << 2 | uVar1) << 2 | uVar2) << 2 | uVar4;
  uVar5 = uVar4 << 8;
  local_20 = (ulonglong)
             ((uVar4 & 0xffffff) >> 0x10 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8);
  t4vf_wr_mbox_core(param_1,(ulonglong *)&local_28,0x10,(void *)0x0,param_8);
  return;
}



===== t4vf_wait_dev_ready @ 180004960 =====

undefined8 t4vf_wait_dev_ready(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 0x90) + 0x200);
  if ((iVar1 == -1) || (iVar1 == -0x11111112)) {
    lVar2 = 10000;
    do {
      KeStallExecutionProcessor(0x31);
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    iVar1 = *(int *)(*(longlong *)(param_1 + 0x90) + 0x200);
    if ((iVar1 == -1) || (iVar1 == -0x11111112)) {
      return 0xfffffffb;
    }
  }
  return 0;
}



===== t4vf_wr_mbox_core @ 1800049cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_wr_mbox_core(longlong param_1,ulonglong *param_2,uint param_3,void *param_4,char param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  undefined1 *puVar9;
  ulonglong *puVar10;
  uint uVar11;
  undefined2 uVar12;
  int iVar13;
  undefined1 local_e8 [8];
  undefined1 auStackY_e0 [24];
  longlong *local_b8;
  longlong *local_b0;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  ulonglong local_98;
  void *local_90;
  undefined8 local_88;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_e8;
  local_a0 = *(uint *)(param_1 + 0x278) & 0xf0;
  uVar11 = (uint)*param_2 & 0xff;
  local_a4 = 0x240;
  if (0x50 < local_a0) {
    local_a4 = 0x280;
  }
  uVar6 = param_3 & 0x8000000f;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
  }
  puVar9 = local_e8;
  if ((uVar6 == 0) && (puVar9 = local_e8, (int)param_3 < 0x41)) {
    local_a8 = uVar11;
    local_90 = param_4;
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
    plVar1 = (longlong *)(param_1 + 0xe0);
    *(undefined1 *)(param_1 + 0xd8) = uVar5;
    plVar2 = *(longlong **)(param_1 + 0xe8);
    if ((longlong *)*plVar2 == plVar1) {
      *plVar2 = (longlong)&local_b8;
      *(longlong ***)(param_1 + 0xe8) = &local_b8;
      local_b8 = plVar1;
      local_b0 = plVar2;
      KeReleaseSpinLock(param_1 + 0xd0,*(undefined1 *)(param_1 + 0xd8));
      iVar13 = 0;
LAB_180004aa9:
      if ((longlong **)*plVar1 != &local_b8) goto code_r0x000180004ab6;
      lVar8 = *(longlong *)(param_1 + 0x90);
      for (iVar7 = 0; (uVar6 = *(uint *)(lVar8 + 0x300) & 3, uVar6 == 0 && (iVar7 < 3));
          iVar7 = iVar7 + 1) {
        lVar8 = *(longlong *)(param_1 + 0x90);
      }
      uVar12 = (undefined2)iVar13;
      if (uVar6 == 2) {
        if (uVar11 != 0x1a) {
          t4vf_record_mbox(param_1,(longlong)param_2,param_3,uVar12,0);
        }
        iVar13 = 0;
        local_98 = 0xff00000000;
        puVar10 = param_2;
        if (0 < (int)param_3) {
          do {
            uVar3 = *puVar10;
            *(ulonglong *)((ulonglong)(local_a4 + iVar13) + *(longlong *)(param_1 + 0x90)) =
                 (((uVar3 << 0x10 | uVar3 & 0xff00) << 0x10 | (ulonglong)((uint)uVar3 & 0xff0000))
                  << 0x10 | uVar3 & 0xff000000) << 8 |
                 ((longlong)uVar3 >> 0x10 & 0xff000000U | uVar3 & 0xff00000000) >> 8 | uVar3 >> 0x38
                 | (longlong)uVar3 >> 0x28 & 0xff00U;
            LOCK();
            UNLOCK();
            iVar13 = iVar13 + 8;
            puVar10 = puVar10 + 1;
          } while (iVar13 < (int)param_3);
        }
        *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 9;
        LOCK();
        UNLOCK();
        iVar13 = 0;
        do {
          if (param_5 == '\0') {
            KeStallExecutionProcessor(1000);
          }
          else {
            lVar8 = 0x14;
            do {
              KeStallExecutionProcessor(0x31);
              lVar8 = lVar8 + -1;
            } while (lVar8 != 0);
            uVar11 = local_a8;
          }
          lVar8 = param_1 + 0xd0;
          uVar6 = *(uint *)(*(longlong *)(param_1 + 0x90) + 0x300);
          if (((byte)uVar6 & 3) == 2) {
            if ((uVar6 & 8) == 0) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 0;
              LOCK();
              UNLOCK();
              goto LAB_180004d82;
            }
            puVar10 = &local_88;
            if (param_3 != 0) {
              uVar11 = local_a4;
              uVar6 = param_3;
              do {
                uVar3 = *(ulonglong *)((ulonglong)uVar11 + *(longlong *)(param_1 + 0x90));
                uVar11 = uVar11 + 8;
                *puVar10 = (((uVar3 << 0x10 | uVar3 & 0xff00) << 0x10 |
                            (ulonglong)((uint)uVar3 & 0xff0000)) << 0x10 | uVar3 & 0xff000000) << 8
                           | ((longlong)uVar3 >> 0x10 & 0xff000000U | uVar3 & local_98) >> 8 |
                           uVar3 >> 0x38 | (longlong)uVar3 >> 0x28 & 0xff00U;
                puVar10 = puVar10 + 1;
                uVar6 = uVar6 - 8;
              } while (uVar6 != 0);
              uVar11 = local_a8;
            }
            *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x300) = 0;
            LOCK();
            UNLOCK();
            uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
            *(undefined1 *)(param_1 + 0xd8) = uVar5;
            if (((longlong **)local_b8[1] != &local_b8) || ((longlong **)*local_b0 != &local_b8))
            goto LAB_180004f1f;
            *local_b0 = (longlong)local_b8;
            local_b8[1] = (longlong)local_b0;
            KeReleaseSpinLock(lVar8,CONCAT71((int7)((ulonglong)&local_b8 >> 8),
                                             *(undefined1 *)(param_1 + 0xd8)));
            if (uVar11 != 0x1a) {
              t4vf_record_mbox(param_1,(longlong)&local_88,param_3,uVar12,(short)iVar13 + 1);
            }
            if (local_90 != (void *)0x0) {
              memmove(local_90,&local_88,(longlong)(int)param_3);
            }
            iVar13 = -((local_88._4_4_ >> 8 & 0xff00U) >> 8);
            goto LAB_180004bff;
          }
LAB_180004d82:
          iVar13 = iVar13 + 1;
        } while (iVar13 < 10000);
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8);
        *(undefined1 *)(param_1 + 0xd8) = uVar5;
        if (((longlong **)local_b8[1] == &local_b8) && ((longlong **)*local_b0 == &local_b8)) {
          *local_b0 = (longlong)local_b8;
          local_b8[1] = (longlong)local_b0;
          KeReleaseSpinLock(lVar8,CONCAT71((int7)((ulonglong)&local_b8 >> 8),
                                           *(undefined1 *)(param_1 + 0xd8)));
          iVar13 = -0x6e;
          goto LAB_180004be9;
        }
      }
      else {
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
        *(undefined1 *)(param_1 + 0xd8) = uVar5;
        if (((longlong **)local_b8[1] == &local_b8) && ((longlong **)*local_b0 == &local_b8)) {
          *local_b0 = (longlong)local_b8;
          local_b8[1] = (longlong)local_b0;
          KeReleaseSpinLock(param_1 + 0xd0,
                            CONCAT71((int7)((ulonglong)&local_b8 >> 8),
                                     *(undefined1 *)(param_1 + 0xd8)));
          iVar13 = -0x6e;
          if (uVar6 == 1) {
            iVar13 = -0x10;
          }
LAB_180004be9:
          t4vf_record_mbox(param_1,(longlong)param_2,param_3,uVar12,(short)iVar13);
LAB_180004bff:
          puVar9 = local_e8;
          goto LAB_180004f2b;
        }
      }
    }
    goto LAB_180004f1f;
  }
LAB_180004f26:
  iVar13 = -0x16;
LAB_180004f2b:
  *(undefined8 *)(puVar9 + -8) = 0x180004f37;
  return iVar13;
code_r0x000180004ab6:
  if (param_5 == '\0') {
    KeStallExecutionProcessor(1000);
  }
  else {
    lVar8 = 0x14;
    do {
      KeStallExecutionProcessor(0x31);
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    uVar11 = local_a8;
  }
  puVar9 = local_e8;
  iVar13 = iVar13 + 1;
  if (20000 < iVar13) goto code_r0x000180004afe;
  goto LAB_180004aa9;
code_r0x000180004afe:
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xd0);
  *(undefined1 *)(param_1 + 0xd8) = uVar5;
  if (((longlong **)local_b8[1] == &local_b8) && ((longlong **)*local_b0 == &local_b8)) {
    *local_b0 = (longlong)local_b8;
    local_b8[1] = (longlong)local_b0;
    KeReleaseSpinLock(param_1 + 0xd0,*(undefined1 *)(param_1 + 0xd8));
    t4vf_record_mbox(param_1,(longlong)param_2,param_3,0xfff0,0);
    iVar13 = -0x10;
    goto LAB_180004f2b;
  }
LAB_180004f1f:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar9 = auStackY_e0;
  goto LAB_180004f26;
}



===== t4vf_write_rss_vi_config @ 180004f54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int t4vf_write_rss_vi_config(longlong param_1,uint param_2,ushort *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_98 [32];
  undefined1 local_68 [32];
  undefined8 local_48;
  uint local_3c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  memset(&local_48,0,0x20);
  local_48._4_4_ = 0x2000000;
  local_48._0_4_ =
       (param_2 | 0x23a00000) >> 0x18 | ((param_2 | 0x23a00000) & 0xff0000) >> 8 |
       (param_2 & 0xff00) << 8 | param_2 << 0x18;
  if (*(int *)(param_1 + 0x240) == 1) {
    uVar1 = *(uint *)(param_3 + 2);
    uVar3 = (uVar1 & 1) << 4;
    uVar4 = uVar3 | 8;
    if ((uVar1 & 2) == 0) {
      uVar4 = uVar3;
    }
    uVar3 = uVar4 | 4;
    if ((uVar1 & 4) == 0) {
      uVar3 = uVar4;
    }
    uVar4 = uVar3 | 2;
    if ((uVar1 & 8) == 0) {
      uVar4 = uVar3;
    }
    uVar3 = uVar4 | 1;
    if ((uVar1 & 0x10) == 0) {
      uVar3 = uVar4;
    }
    local_3c = ((uint)*param_3 | (*param_3 & 0xff) << 0x10) >> 8 | uVar3 << 0x18;
    iVar2 = t4vf_wr_mbox_core(param_1,&local_48,0x20,local_68,'\x01');
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}



===== __security_check_cookie @ 180005050 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 180005070 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 180005080 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 180005090 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180005090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar1 = memcpy_s(_Dst,_DstSize,_Src,_MaxCount);
  return eVar1;
}



===== __GSHandlerCheck @ 180005098 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1800050b8 =====

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



===== _guard_dispatch_icall @ 180005130 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180005130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 180005140 =====

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



===== memset @ 180005400 =====

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



===== DriverEntry @ 18000a000 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== entry @ 18000a010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 18000a03c =====

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


