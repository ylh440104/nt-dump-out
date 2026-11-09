
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== RtlCopyFromUser @ 140001038 =====

/* WARNING: Removing unreachable block (ram,0x00014000105c) */

void RtlCopyFromUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_2,param_3,1);
    RtlCopyVolatileMemory(param_1,param_2,param_3);
  }
  return;
}



===== _guard_check_icall @ 1400010b0 =====

void _guard_check_icall(void)

{
  return;
}



===== ProbeForRead @ 1400010c6 =====

void ProbeForRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400010c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ProbeForRead();
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



===== ZtpValidateAddressBuffer @ 1400011a8 =====

undefined4 ZtpValidateAddressBuffer(uint *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  int iVar3;
  undefined2 uVar4;
  _SOCKADDR_INET *p_Var5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  if (param_1 == (uint *)0x0) {
    return 0xc000000d;
  }
  uVar6 = *param_1;
  uVar11 = 1;
  if (uVar6 == 1) {
    uVar6 = param_1[0x84];
    uVar9 = (ulonglong)uVar6;
    if (uVar6 == 0) {
      uVar8 = 0xc000000d;
      uVar7 = 0xc000000d;
      if ((DAT_14000e210 & 1) == 0) {
        return 0xc000000d;
      }
      uVar4 = 0xb;
    }
    else if (*(short *)((longlong)param_1 + 0x20e) == 0) {
      uVar1 = uVar9 * 0x28 + 0x218;
      if (uVar1 < 0x100000000) {
        if (uVar1 == (param_2 & 0xffffffff)) {
          uVar10 = 0;
          if (uVar6 == 0) {
            return 0;
          }
          p_Var5 = (_SOCKADDR_INET *)(param_1 + 0x88);
          while ((uVar2 = *(ushort *)p_Var5, uVar2 == 2 || (uVar2 == 0x17))) {
            iVar3 = ZtSockaddrInetIsMappedAddress(p_Var5);
            if (iVar3 != 0) {
              uVar8 = 0xc000000d;
              uVar7 = 0xc000000d;
              if ((DAT_14000e210 & (byte)uVar11) == 0) {
                return 0xc000000d;
              }
              uVar4 = 0x10;
              goto LAB_140001328;
            }
            if (((*(ulonglong *)(p_Var5 + -8) & 0xfffffffffffffff8) != 0) ||
               (((byte)*(ulonglong *)(p_Var5 + -8) & 3) == 3)) {
              if ((DAT_14000e210 & (byte)uVar11) == 0) {
                return 0xc000000d;
              }
              WPP_SF_di();
              return 0xc000000d;
            }
            uVar10 = uVar10 + (int)uVar11;
            p_Var5 = p_Var5 + 0x28;
            if ((uint)uVar9 <= uVar10) {
              return 0;
            }
          }
          if ((DAT_14000e210 & (byte)uVar11) == 0) {
            return 0xc000000d;
          }
          uVar6 = (uint)uVar2;
          uVar4 = 0xf;
          goto LAB_14000134d;
        }
        uVar8 = 0xc000000d;
        uVar7 = 0xc000000d;
        if ((DAT_14000e210 & 1) == 0) {
          return 0xc000000d;
        }
        uVar4 = 0xe;
      }
      else {
        uVar8 = 0xc0000095;
        uVar7 = 0xc0000095;
        if ((DAT_14000e210 & 1) == 0) {
          return 0xc0000095;
        }
        uVar4 = 0xd;
      }
    }
    else {
      uVar8 = 0xc000000d;
      uVar7 = 0xc000000d;
      if ((DAT_14000e210 & 1) == 0) {
        return 0xc000000d;
      }
      uVar4 = 0xc;
    }
LAB_140001328:
    WPP_SF_L(uVar4,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,uVar8);
  }
  else {
    if ((DAT_14000e210 & 1) == 0) {
      return 0xc000000d;
    }
    uVar4 = 10;
LAB_14000134d:
    uVar7 = 0xc000000d;
    WPP_SF_ll(uVar4,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0xc000000d,uVar6);
  }
  return uVar7;
}



===== ZtpValidateException @ 140001368 =====

undefined4 ZtpValidateException(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  uVar7 = 0;
  if (param_1 == (uint *)0x0) {
    return 0xc000000d;
  }
  uVar6 = *(ushort *)(param_1 + 1);
  uVar5 = (uint)uVar6;
  uVar8 = 2;
  if ((uVar6 != 2) && (uVar6 != 0x17)) {
    if ((DAT_14000e210 & 1) == 0) {
      return 0xc000000d;
    }
    uVar4 = 0x14;
    goto LAB_1400013bd;
  }
  if (*(short *)((longlong)param_1 + 6) == 0) {
    iVar3 = ZtSockaddrInetIsMappedAddress((_SOCKADDR_INET *)(param_1 + 1));
    if (iVar3 == 0) {
      uVar5 = *param_1;
      if (1 < uVar5 - 1) {
        if ((DAT_14000e210 & 1) == 0) {
          return 0xc000000d;
        }
        uVar4 = 0x17;
LAB_1400013bd:
        WPP_SF_ll(uVar4,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0xc000000d,uVar5);
        return 0xc000000d;
      }
      if ((uVar6 != (ushort)uVar8) && (uVar6 != 0x17)) {
        return 0xc000000d;
      }
      bVar2 = 0x20;
      if (uVar6 != (ushort)uVar8) {
        bVar2 = 0x80;
      }
      bVar1 = (byte)param_1[8];
      if (uVar5 == uVar8) {
        if (bVar2 < bVar1) {
          if ((DAT_14000e210 & 1) == 0) {
            return 0xc000000d;
          }
          uVar5 = (uint)bVar1;
          uVar4 = 0x18;
          goto LAB_1400013bd;
        }
      }
      else if (bVar1 != bVar2) {
        if ((DAT_14000e210 & 1) == 0) {
          return 0xc000000d;
        }
        uVar4 = 0x19;
        goto LAB_1400014d8;
      }
      if (*(short *)((longlong)param_1 + 0xa2) == (short)uVar7) {
        return uVar7;
      }
      if ((DAT_14000e210 & 1) == 0) {
        return 0xc000000d;
      }
      uVar4 = 0x1a;
    }
    else {
      if ((DAT_14000e210 & 1) == 0) {
        return 0xc000000d;
      }
      uVar4 = 0x16;
    }
  }
  else {
    if ((DAT_14000e210 & 1) == 0) {
      return 0xc000000d;
    }
    uVar4 = 0x15;
  }
LAB_1400014d8:
  WPP_SF_L(uVar4,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0xc000000d);
  return 0xc000000d;
}



===== ZtpValidateExceptionsBuffer @ 1400014f8 =====

int ZtpValidateExceptionsBuffer(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (param_1 == (int *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else if (*param_1 == 1) {
    uVar3 = (ulonglong)(uint)param_1[4] * 0xa4 + 0x14;
    if (uVar3 < 0x100000000) {
      if (uVar3 < 0xb8) {
        uVar3 = 0xb8;
      }
      if (uVar3 == param_2) {
        iVar1 = 0;
        uVar3 = 0;
        if (param_1[4] != 0) {
          do {
            iVar1 = ZtpValidateException((uint *)(param_1 + uVar3 * 0x29 + 5));
            if (iVar1 < 0) {
              return iVar1;
            }
            uVar2 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar2;
          } while (uVar2 < (uint)param_1[4]);
        }
      }
      else {
        iVar1 = -0x3ffffff3;
        if ((DAT_14000e210 & 1) != 0) {
          WPP_SF_dIL();
        }
      }
    }
    else {
      iVar1 = -0x3fffff6b;
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_L(0x1c,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0xc0000095);
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_ll(0x1b,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0xc000000d,*param_1);
    }
  }
  return iVar1;
}



===== ZtpValidateServiceNameMappingsBuffer @ 1400015fc =====

/* long __cdecl ZtpValidateServiceNameMappingsBuffer(struct _ZT_SERVICE_DATA_ARRAY const *
   __ptr64,unsigned long) */

long __cdecl ZtpValidateServiceNameMappingsBuffer(_ZT_SERVICE_DATA_ARRAY *param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  long lVar5;
  undefined4 uVar6;
  _ZT_SERVICE_DATA_ARRAY *p_Var7;
  
  if (param_1 == (_ZT_SERVICE_DATA_ARRAY *)0x0) {
    return -0x3ffffff3;
  }
  uVar1 = *(uint *)param_1;
  if (uVar1 == 0) {
    uVar6 = 0xc000000d;
    lVar5 = -0x3ffffff3;
    if ((DAT_14000e210 & 1) == 0) {
      return -0x3ffffff3;
    }
    uVar3 = 0x20;
  }
  else {
    uVar4 = (ulonglong)uVar1 * 0x208 + 8;
    if (uVar4 < 0x100000000) {
      if (uVar4 == param_2) {
        uVar2 = 0;
        if (uVar1 == 0) {
          return 0;
        }
        p_Var7 = param_1 + 0x20e;
        while (*(short *)p_Var7 == 0) {
          uVar2 = uVar2 + 1;
          p_Var7 = p_Var7 + 0x208;
          if (uVar1 <= uVar2) {
            return 0;
          }
        }
        uVar6 = 0xc000000d;
        lVar5 = -0x3ffffff3;
        if ((DAT_14000e210 & 1) == 0) {
          return -0x3ffffff3;
        }
        uVar3 = 0x23;
      }
      else {
        uVar6 = 0xc000000d;
        lVar5 = -0x3ffffff3;
        if ((DAT_14000e210 & 1) == 0) {
          return -0x3ffffff3;
        }
        uVar3 = 0x22;
      }
    }
    else {
      uVar6 = 0xc0000095;
      lVar5 = -0x3fffff6b;
      if ((DAT_14000e210 & 1) == 0) {
        return -0x3fffff6b;
      }
      uVar3 = 0x21;
    }
  }
  WPP_SF_L(uVar3,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,uVar6);
  return lVar5;
}



===== ZtCalloutConnectClassify @ 1400016e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ZtCalloutConnectClassify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER3_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
ZtCalloutConnectClassify
          (FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,void *param_3,
          void *param_4,FWPS_FILTER3_ *param_5,__uint64 param_6,FWPS_CLASSIFY_OUT0_ *param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  FWPS_INCOMING_METADATA_VALUES0_ *pFVar5;
  wchar_t **ppwVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_108 [32];
  byte local_b8;
  byte local_b7 [3];
  undefined2 local_b4 [2];
  undefined2 local_b0 [2];
  undefined4 local_ac;
  wchar_t *local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  FWPS_INCOMING_METADATA_VALUES0_ *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  short local_60 [16];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  bVar1 = false;
  if ((DAT_14000e210 & 1) != 0) {
    param_4 = param_2;
    WPP_SF_qqqqqiq(param_5,param_2,param_1,param_2);
  }
  local_b0[0] = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  local_60[8] = 0;
  local_60[9] = 0;
  local_60[10] = 0;
  local_60[0xb] = 0;
  local_60[0xc] = 0;
  local_60[0xd] = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_b4[0] = 0;
  local_b7[0] = 0;
  local_b8 = 0;
  local_98 = 0;
  local_ac = 0;
  local_a8 = (wchar_t *)0x0;
  local_88 = (FWPS_INCOMING_METADATA_VALUES0_ *)0x0;
  local_90 = 0;
  if (((byte)DAT_14000e204 & 1) != 0) {
    param_4 = &local_80;
    uVar4 = ZtpGetConnectionInfo
                      ((short *)param_1,(undefined8 *)local_60,local_b0,param_4,local_b4,local_b7,
                       &local_b8,&local_98,&local_ac);
    if (-1 < (int)uVar4) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF__SOCKADDR__SOCKADDR_ddddqD((ulonglong)local_b8,(ulonglong)local_b7[0],local_60);
      }
      param_4 = &local_90;
      ppwVar6 = &local_a8;
      pFVar5 = param_2;
      uVar4 = ZtpGetConnectionMetadata((uint *)param_2,ppwVar6,&local_88,param_4);
      if ((-1 < (int)uVar4) && ((DAT_14000e210 & 1) != 0)) {
        param_4 = local_88;
        WPP_SF_Sqi(pFVar5,ppwVar6,local_a8);
      }
    }
  }
  local_a8 = (wchar_t *)0x0;
  uStack_a0 = 0;
  if (g_dwUnicastLifetime != 0) {
    local_a8 = (wchar_t *)0x3;
    uStack_a0 = (ulonglong)g_dwUnicastLifetime;
    iVar2 = FwpsClassifyOptionSet0(param_2,2,&local_a8);
    if ((iVar2 < 0) && (((byte)DAT_14000e208 & 1) != 0)) {
      WPP_SF_L(0x1f,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,iVar2);
    }
  }
  uVar3 = ZtpAllowConnection((short *)param_1,(uint *)param_2);
  uVar8 = (ulonglong)uVar3;
  if ((uVar3 == 0) && (g_fAuditMode == 0)) {
    uVar7 = 0x1001;
    bVar1 = true;
  }
  else {
    uVar7 = 0x1002;
  }
  if ((DAT_14000e210 & 1) != 0) {
    param_4 = (void *)(ulonglong)(uint)g_fAuditMode;
    WPP_SF_ll(0x21,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,uVar3,g_fAuditMode);
  }
  *(undefined4 *)param_7 = uVar7;
  if (bVar1) {
    *(uint *)(param_7 + 0x18) = *(uint *)(param_7 + 0x18) & 0xfffffffe;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x22,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,uVar8,param_4);
  }
  return;
}



===== ZtServiceNamesStartModule @ 140001950 =====

/* long __cdecl ZtServiceNamesStartModule(void) */

long __cdecl ZtServiceNamesStartModule(void)

{
  return 0;
}



===== ZtpAllowConnection @ 14000195c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ZtpAllowConnection(short *param_1,uint *param_2)

{
  int iVar1;
  ZtNode *pZVar2;
  uint uVar3;
  undefined8 uVar4;
  ZT_LOOKUP_NODE_ADDRESS *pZVar5;
  ZtBucket *_Dst;
  longlong lVar6;
  ZtPidServiceNameMapper **ppZVar7;
  ZT_LOOKUP_NODE_ADDRESS *_Src;
  ZtNode *pZVar8;
  ulonglong _Size;
  short sVar9;
  undefined1 auStackY_368 [32];
  uint in_stack_fffffffffffffce8;
  byte local_2f8;
  undefined1 local_2f7 [3];
  ushort local_2f4 [2];
  ushort local_2f0 [2];
  uint local_2ec;
  _ZT_PERMIT_TYPE local_2e8;
  uint local_2e4;
  ZtBucket *local_2e0;
  ZtNode *local_2d8;
  __uint64 local_2d0;
  longlong local_2c8;
  ZtPidServiceNameMapper *local_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined4 local_2a8;
  undefined8 local_298;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined4 local_288;
  short local_278 [16];
  short local_258 [16];
  ZtBucket local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_368;
  local_2ec = 0;
  local_258[0] = 0;
  local_258[9] = 0;
  local_258[10] = 0;
  local_258[0xb] = 0;
  local_258[0xc] = 0;
  local_258[0xd] = 0;
  local_278[0] = 0;
  local_278[9] = 0;
  local_278[10] = 0;
  local_278[0xb] = 0;
  local_278[0xc] = 0;
  local_258[1] = 0;
  local_258[2] = 0;
  local_258[3] = 0;
  local_258[4] = 0;
  local_258[5] = 0;
  local_258[6] = 0;
  local_258[7] = 0;
  local_258[8] = 0;
  local_278[0xd] = 0;
  local_278[1] = 0;
  local_278[2] = 0;
  local_278[3] = 0;
  local_278[4] = 0;
  local_278[5] = 0;
  local_278[6] = 0;
  local_278[7] = 0;
  local_278[8] = 0;
  local_2f0[0] = 0;
  local_2f4[0] = 0;
  local_2f8 = 0;
  local_2f7[0] = 0;
  local_2c8 = 0;
  local_2e4 = 0;
  local_2d0 = 0;
  local_2c0 = (ZtPidServiceNameMapper *)0x0;
  local_2e8 = 0;
  memset(local_238,0,0x200);
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qq(0x1d,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,param_1,param_2);
  }
  uVar4 = ZtpGetConnectionInfo
                    (param_1,(undefined8 *)local_258,local_2f0,(undefined8 *)local_278,local_2f4,
                     &local_2f8,local_2f7,&local_2c8,&local_2e4);
  if ((int)uVar4 < 0) goto LAB_140001c58;
  sVar9 = 0;
  ppZVar7 = &local_2c0;
  uVar4 = ZtpGetConnectionMetadata(param_2,ppZVar7,(undefined8 *)0x0,&local_2d0);
  if ((int)uVar4 < 0) goto LAB_140001c58;
  local_2ec = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF__SOCKADDR_(sVar9 + 10,ppZVar7,local_278);
  }
  local_2e0 = (ZtBucket *)0x0;
  pZVar8 = (ZtNode *)0x0;
  local_2a8 = 0;
  local_2d8 = (ZtNode *)0x0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  uVar3 = ZtBuildLookupNodeAddrFromSockaddrInet
                    ((_SOCKADDR_INET *)local_278,(ZT_LOOKUP_NODE_ADDRESS *)&local_2b8);
  if ((int)uVar3 < 0) {
LAB_140001b94:
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_L(0xc,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,uVar3);
    }
  }
  else {
    local_288 = local_2a8;
    local_298._0_4_ = (ZtHashtable *)local_2b8;
    local_298._4_4_ = local_2b8._4_4_;
    uStack_290 = (undefined4)uStack_2b0;
    uStack_28c = uStack_2b0._4_4_;
    uVar3 = ZtHashtable::GetZtBucketFromAddress((ZtHashtable *)local_2b8,&local_298,&local_2e0);
    if ((int)uVar3 < 0) goto LAB_140001b94;
    _Src = (ZT_LOOKUP_NODE_ADDRESS *)&local_2b8;
    _Dst = local_2e0;
    ZtBucket::FindAddress(local_2e0,_Src,&local_2d8);
    pZVar8 = local_2d8;
    if (local_2d8 != (ZtNode *)0x0) {
      _Src = *(ZT_LOOKUP_NODE_ADDRESS **)(local_2d8 + 0x48);
      if (_Src == (ZT_LOOKUP_NODE_ADDRESS *)0x0) {
        uVar3 = 0xc000000d;
      }
      else {
        lVar6 = 0x100;
        pZVar5 = _Src;
        do {
          if (*(short *)pZVar5 == 0) break;
          pZVar5 = pZVar5 + 2;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        uVar3 = ~-(uint)(lVar6 != 0) & 0xc000000d;
        if (lVar6 != 0) {
          _Dst = local_238;
          _Size = -(ulonglong)(lVar6 != 0) & (0x100 - lVar6) * 2;
          memmove(_Dst,_Src,_Size);
          *(undefined2 *)(local_238 + _Size) = 0;
          local_2ec = 1;
          goto LAB_140001b74;
        }
      }
      goto LAB_140001b94;
    }
    local_2ec = 0;
LAB_140001b74:
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF__SOCKADDR_Sl(_Dst,_Src,local_278,(longlong)local_238);
      goto LAB_140001b94;
    }
  }
  pZVar2 = local_2d8;
  if (pZVar8 != (ZtNode *)0x0) {
    LOCK();
    iVar1 = *(int *)pZVar8;
    *(int *)pZVar8 = *(int *)pZVar8 + -1;
    UNLOCK();
    if ((iVar1 == 1) && (local_2d8 != (ZtNode *)0x0)) {
      ZtNode::~ZtNode(local_2d8);
      ExFreePoolWithTag(pZVar2,0x4e4c745a);
    }
  }
  if (-1 < (int)uVar3) {
    if (local_2ec == 0) {
      ZtpFastLookup(local_258,(ulonglong)local_2f0[0],(_SOCKADDR_INET *)local_278,local_2f4[0],
                    local_2f8,local_2c8,local_2f7[0],local_2d0,local_2e4,&local_2e8,
                    in_stack_fffffffffffffce8,(ushort *)local_238,&local_2ec);
    }
    else {
      local_2e8 = 3;
    }
  }
LAB_140001c58:
  ZtpLogConnectionClassification
            (local_2ec,local_258,local_2f0[0],local_278,local_2f4[0],local_2f8,local_2d0,local_2c0,
             local_2e8,(short *)local_238);
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x1e,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,local_2ec);
  }
  return local_2ec;
}



===== ZtpConnectionMatchesDhcp @ 140001cf4 =====

long ZtpConnectionMatchesDhcp
               (byte param_1,short *param_2,short param_3,_SOCKADDR_INET *param_4,short param_5,
               longlong param_6,uint *param_7)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  undefined *puVar6;
  int iVar7;
  int local_38;
  uint local_34 [3];
  
  local_38 = 0;
  local_34[0] = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dqdqdqq(0x11,1,(uint)param_1,param_2);
  }
  if (param_7 == (uint *)0x0) {
    lVar5 = -0x3ffffff3;
    goto LAB_140001ee7;
  }
  *param_7 = 0;
  lVar5 = 0;
  if ((((*param_2 == 2) && (param_3 == 0x44)) && (*(short *)param_4 == 2)) && (param_5 == 0x43)) {
    iVar7 = 1;
    if (*(int *)(param_4 + 4) != -1) goto LAB_140001e1f;
    bVar3 = true;
LAB_140001db7:
    bVar1 = false;
    bVar2 = bVar3;
LAB_140001dba:
    bVar3 = false;
  }
  else {
    iVar7 = 0;
LAB_140001e1f:
    bVar3 = false;
    bVar2 = false;
    if (((*param_2 != 0x17) || (param_3 != 0x222)) ||
       ((*(short *)param_4 != 0x17 || (param_5 != 0x223)))) goto LAB_140001db7;
    if ((((char)param_2[4] != -2) || ((*(byte *)((longlong)param_2 + 9) & 0xc0) != 0x80)) ||
       ((*(longlong *)(param_4 + 0x10) != 0x200010000000000 || (*(longlong *)(param_4 + 8) != 0x2ff)
        ))) {
      bVar1 = true;
      bVar2 = bVar3;
      goto LAB_140001dba;
    }
    bVar3 = true;
    bVar1 = true;
  }
  if ((param_1 != 0x11) || (((iVar7 == 0 && (!bVar1)) || (param_6 == 0)))) goto LAB_140001ee7;
  if ((!bVar2) && (!bVar3)) {
    lVar5 = ZtFastLookupFindDhcp(param_4,&local_38);
    if (lVar5 < 0) goto LAB_140001ee7;
    if (local_38 == 0) {
      lVar5 = -0x3ffffddb;
      goto LAB_140001ee7;
    }
  }
  puVar6 = &DAT_14000b800;
  if (g_fVelocityDnsBugFix2602 != 0) {
    puVar6 = &DAT_14000b6a0;
  }
  lVar5 = ZtpAccessCheck(puVar6,param_6,local_34);
  uVar4 = local_34[0];
  if (-1 < lVar5) {
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_lllll(puVar6,param_6,local_34[0],iVar7);
    }
    *param_7 = uVar4;
  }
LAB_140001ee7:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x13,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,lVar5);
  }
  return lVar5;
}



===== ZtpConnectionMatchesIcs @ 140001f2c =====

int ZtpConnectionMatchesIcs
              (byte param_1,short *param_2,short param_3,short *param_4,short param_5,
              longlong param_6,uint *param_7)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  uint *puVar4;
  short *psVar5;
  uint local_28 [4];
  
  local_28[0] = 0;
  psVar5 = param_4;
  if ((DAT_14000e210 & 1) != 0) {
    psVar5 = param_2;
    WPP_SF_dqdqdqq(0xe,param_2,(uint)param_1,param_2);
  }
  if (param_7 == (uint *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = 0;
    *param_7 = 0;
    if ((((*param_2 == 2) && (param_3 == 0x43)) && (*param_4 == 2)) && (param_5 == 0x44)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (((param_1 == 0x11) && (bVar1)) && (param_6 != 0)) {
      puVar3 = &DAT_14000b7a0;
      if (g_fVelocityDnsBugFix2602 != 0) {
        puVar3 = &DAT_14000b650;
      }
      puVar4 = local_28;
      iVar2 = ZtpAccessCheck(puVar3,param_6,puVar4);
      if (-1 < iVar2) {
        if ((DAT_14000e210 & 1) != 0) {
          WPP_SF_(0xf,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,puVar4,psVar5);
        }
        *param_7 = local_28[0];
      }
    }
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x10,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtpConnectionMatchesLocalMachineIp @ 140002080 =====

undefined4
ZtpConnectionMatchesLocalMachineIp(short *param_1,short *param_2,uint param_3,undefined4 *param_4)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  bool bVar6;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqq(param_1,param_2,param_1,param_2);
  }
  uVar4 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) || (param_4 == (undefined4 *)0x0)) {
    uVar4 = 0xc000000d;
    goto LAB_1400021a0;
  }
  sVar1 = *param_2;
  if (sVar1 == 0x17) {
    if (((((param_2[4] == 0) && (param_2[5] == 0)) &&
         ((param_2[6] == 0 && ((param_2[7] == 0 && (param_2[8] == 0)))))) && (param_2[9] == 0)) &&
       (param_2[10] == 0)) {
      bVar6 = param_2[0xb] == 0x100;
      goto LAB_14000212c;
    }
LAB_140002131:
    bVar2 = false;
  }
  else {
    bVar6 = (char)param_2[2] == '\x7f';
LAB_14000212c:
    bVar2 = true;
    if (!bVar6) goto LAB_140002131;
  }
  bVar6 = false;
  if (*param_1 == sVar1) {
    plVar5 = (longlong *)(param_2 + 4);
    if (sVar1 != 0x17) {
      plVar5 = (longlong *)(param_2 + 2);
    }
    if (*param_1 == 0x17) {
      if ((*(longlong *)(param_1 + 8) == plVar5[1]) && (*(longlong *)(param_1 + 4) == *plVar5)) {
        bVar6 = true;
      }
    }
    else {
      bVar6 = *(int *)(param_1 + 2) == (int)*plVar5;
    }
  }
  if (((param_3 & 1) == 0) || ((!bVar2 && (!bVar6)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *param_4 = uVar3;
LAB_1400021a0:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xd,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,uVar4);
  }
  return uVar4;
}



===== ZtpConnectionMatchesMdns @ 1400021e0 =====

int ZtpConnectionMatchesMdns
              (byte param_1,short *param_2,ushort param_3,short *param_4,short param_5,
              longlong param_6,uint *param_7)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar5;
  uint uVar4;
  uint local_res10 [2];
  ushort local_res18;
  
  local_res10[0] = 0;
  local_res18 = param_3;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dqdqdqq(0x1a,(ulonglong)param_3,(uint)param_1,param_2);
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = 0;
  }
  if (((param_2 == (short *)0x0) || (param_4 == (short *)0x0)) || (param_7 == (uint *)0x0)) {
    iVar2 = -0x3ffffff3;
    goto LAB_14000235f;
  }
  iVar2 = 0;
  if ((*param_2 == 2) && (*param_4 == 2)) {
    uVar5 = (uint)(*(int *)(param_4 + 2) == -0x4ffff20);
LAB_1400022dc:
    uVar4 = uVar5;
    bVar1 = false;
  }
  else {
    uVar5 = 0;
    uVar4 = 0;
    if (((*param_2 != 0x17) ||
        (((char)param_2[4] != -2 || ((*(byte *)((longlong)param_2 + 9) & 0xc0) != 0x80)))) ||
       ((*param_4 != 0x17 ||
        ((*(longlong *)(param_4 + 8) != -0x500000000000000 ||
         (bVar1 = true, *(longlong *)(param_4 + 4) != 0x2ff)))))) goto LAB_1400022dc;
  }
  if (((((param_1 == 0x11) && (local_res18 == 0x14e9)) && (param_5 == 0x14e9)) &&
      ((uVar4 != 0 || (bVar1)))) && (param_6 != 0)) {
    puVar3 = &DAT_14000b740;
    if (g_fVelocityDnsBugFix2602 != 0) {
      puVar3 = &DAT_14000b6f0;
    }
    iVar2 = ZtpAccessCheck(puVar3,param_6,local_res10);
    if (-1 < iVar2) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_lll(puVar3,param_6,local_res10[0],uVar4);
      }
      *param_7 = (uint)(local_res10[0] == 0);
    }
  }
LAB_14000235f:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x1c,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtpConnectionMatchesNd @ 1400023a0 =====

undefined4
ZtpConnectionMatchesNd
          (undefined8 param_1,undefined8 param_2,short *param_3,short *param_4,longlong param_5,
          undefined4 *param_6)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  char cVar5;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_ddqqiq(param_1,param_2,(uint)param_1 & 0xff,(uint)param_2 & 0xff);
  }
  uVar4 = 0;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (((param_3 == (short *)0x0) || (param_4 == (short *)0x0)) || (param_6 == (undefined4 *)0x0)) {
    uVar4 = 0xc000000d;
    goto LAB_140002509;
  }
  cVar5 = (char)param_2;
  if (cVar5 == -0x7b) {
    if (((((char)param_3[4] == -2) && ((*(byte *)((longlong)param_3 + 9) & 0xc0) == 0x80)) ||
        ((((param_3[4] == 0 &&
           ((((param_3[5] == 0 && (param_3[6] == 0)) && (param_3[7] == 0)) &&
            ((param_3[8] == 0 && (param_3[9] == 0)))))) && (param_3[10] == 0)) &&
         (param_3[0xb] == 0)))) &&
       ((*(longlong *)(param_4 + 8) == 0x200000000000000 && (*(longlong *)(param_4 + 4) == 0x2ff))))
    {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
LAB_1400024b4:
    uVar3 = 0;
LAB_1400024b6:
    bVar1 = false;
  }
  else {
    uVar2 = 0;
    if (cVar5 == -0x79) {
      if ((((char)param_4[4] != -2) || ((*(byte *)((longlong)param_4 + 9) & 0xc0) != 0x80)) &&
         ((*(longlong *)(param_4 + 4) != 0x2ff ||
          ((*(int *)(param_4 + 8) != 0x1000000 || ((char)param_4[10] != -1)))))) goto LAB_1400024b4;
      uVar3 = 1;
      goto LAB_1400024b6;
    }
    uVar3 = 0;
    if ((cVar5 != -0x78) ||
       ((((char)param_4[4] != -2 || ((*(byte *)((longlong)param_4 + 9) & 0xc0) != 0x80)) &&
        ((*(longlong *)(param_4 + 8) != 0x100000000000000 || (*(longlong *)(param_4 + 4) != 0x2ff)))
        ))) goto LAB_1400024b6;
    bVar1 = true;
  }
  if ((((param_5 == 4) && ((char)param_1 == ':')) && (*param_3 == 0x17)) && (*param_4 == 0x17)) {
    if ((((int)uVar2 != 0) || ((int)uVar3 != 0)) || (bVar1)) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_iddlll(uVar2,uVar3,4,0x3a);
      }
      *param_6 = 1;
    }
  }
LAB_140002509:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x16,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,uVar4);
  }
  return uVar4;
}



===== ZtpFastLookup @ 1400025e8 =====

ulonglong ZtpFastLookup(short *param_1,undefined8 param_2,_SOCKADDR_INET *param_3,ushort param_4,
                       byte param_5,longlong param_6,undefined1 param_7,longlong param_8,
                       uint param_9,_ZT_PERMIT_TYPE *param_10,uint param_11,ushort *param_12,
                       uint *param_13)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  short *psVar4;
  ulonglong uVar5;
  ushort uVar6;
  ulong uVar7;
  _ZT_PERMIT_TYPE _Var8;
  _ZT_PERMIT_TYPE *p_Var9;
  uint local_48;
  _ZT_PERMIT_TYPE local_44 [3];
  
  puVar1 = param_13;
  uVar6 = (ushort)param_2;
  uVar2 = (uint)param_4;
  local_44[0] = 0;
  param_11 = 0;
  local_48 = 0;
  if (param_13 != (uint *)0x0) {
    *param_13 = 0;
  }
  psVar4 = param_1;
  if (param_10 != (_ZT_PERMIT_TYPE *)0x0) {
    p_Var9 = param_10;
    for (lVar3 = 4; psVar4 = (short *)0x0, lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined1 *)p_Var9 = 0;
      p_Var9 = (_ZT_PERMIT_TYPE *)((longlong)p_Var9 + 1);
    }
  }
  if ((param_13 == (uint *)0x0) || (param_10 == (_ZT_PERMIT_TYPE *)0x0)) {
    return 0xc000000d;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dq(psVar4,param_2,uVar2,&local_48);
  }
  uVar7 = (ulong)param_2;
  local_48 = 0;
  if ((((uVar2 == 0x35) || (param_4 == 0x14e9)) || (param_4 == 0x89)) || (param_4 == 0x14eb)) {
    if ((DAT_14000e210 & 1) != 0) {
      uVar7 = 0x4000b488;
      WPP_SF_L(0x18,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,uVar2);
    }
    local_48 = (uint)(g_fAllowPlaintextDns == 0);
  }
  if ((DAT_14000e210 & 1) != 0) {
    uVar7 = 0x4000b488;
    WPP_SF_L(0x19,&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0);
  }
  uVar5 = 0;
  _Var8 = 0;
  if (local_48 != 0) goto LAB_140002885;
  uVar2 = ZtStaticLookupFindAddress(param_3,uVar7,param_12,(int *)&param_11,local_44);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    return uVar5;
  }
  if (param_11 == 0) {
    if (g_fBlockLocalIps == 0) {
      uVar2 = ZtpConnectionMatchesLocalMachineIp(param_1,(short *)param_3,param_9,&param_11);
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        return uVar5;
      }
      if (param_11 != 0) {
        _Var8 = 7;
        goto LAB_140002885;
      }
    }
    psVar4 = param_1;
    uVar2 = ZtpConnectionMatchesDhcp(param_5,param_1,uVar6,param_3,param_4,param_6,&param_11);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      return uVar5;
    }
    if (param_11 != 0) {
      _Var8 = 4;
      goto LAB_140002885;
    }
    if (g_fAllowIcsDhcpServer != 0) {
      psVar4 = param_1;
      uVar2 = ZtpConnectionMatchesIcs
                        (param_5,param_1,uVar6,(short *)param_3,param_4,param_6,&param_11);
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        return uVar5;
      }
      if (param_11 != 0) {
        _Var8 = 8;
        goto LAB_140002885;
      }
    }
    uVar2 = ZtpConnectionMatchesNd
                      (CONCAT71((int7)(uVar5 >> 8),param_5),
                       CONCAT71((int7)((ulonglong)psVar4 >> 8),param_7),param_1,(short *)param_3,
                       param_8,&param_11);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      return uVar5;
    }
    if (param_11 != 0) {
      _Var8 = 5;
      goto LAB_140002885;
    }
    if (g_fAllowMdns != 0) {
      uVar2 = ZtpConnectionMatchesMdns
                        (param_5,param_1,uVar6,(short *)param_3,param_4,param_6,&param_11);
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        return uVar5;
      }
      if (param_11 != 0) {
        local_44[0] = 6;
      }
      _Var8 = local_44[0];
      goto LAB_140002885;
    }
  }
  _Var8 = local_44[0];
LAB_140002885:
  *puVar1 = param_11;
  *param_10 = _Var8;
  return uVar5;
}



===== ZtpGetConnectionInfo @ 1400028b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ZtpGetConnectionInfo
          (short *param_1,undefined8 *param_2,undefined2 *param_3,undefined8 *param_4,
          undefined2 *param_5,undefined1 *param_6,undefined1 *param_7,undefined8 *param_8,
          undefined4 *param_9)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  short sVar10;
  int iVar11;
  longlong lVar12;
  longlong lVar13;
  undefined8 *puVar14;
  short *psVar15;
  ushort uVar16;
  undefined1 auStackY_178 [32];
  uint local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  short *local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  undefined2 *local_c8;
  undefined2 *local_c0;
  undefined8 local_b8;
  short local_98 [2];
  uint uStack_94;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_178;
  local_c0 = param_5;
  local_128 = 0;
  local_124 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_120 = 0;
  local_10c = 0;
  local_d0 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_88 = 0;
  local_80 = 0;
  local_68 = 0;
  local_60 = 0;
  local_108 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  _local_98 = 0;
  uStack_90 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_2 != (undefined8 *)0x0) {
    puVar14 = param_2;
    for (lVar12 = 0x1c; lVar12 != 0; lVar12 = lVar12 + -1) {
      *(undefined1 *)puVar14 = 0;
      puVar14 = (undefined8 *)((longlong)puVar14 + 1);
    }
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    puVar14 = param_4;
    for (lVar12 = 0x1c; lVar12 != 0; lVar12 = lVar12 + -1) {
      *(undefined1 *)puVar14 = 0;
      puVar14 = (undefined8 *)((longlong)puVar14 + 1);
    }
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = 0;
  }
  if (param_8 != (undefined8 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = 0;
  }
  if (param_1 == (short *)0x0) {
    return 0xc000000d;
  }
  sVar10 = *param_1;
  local_e0 = param_1;
  local_d8 = param_2;
  local_c8 = param_3;
  ZtpGetValueIndexesForLayer
            (sVar10,&local_128,&local_124,&local_11c,&local_118,&local_114,&local_110,&local_120,
             &local_10c);
  uVar16 = 2;
  if (sVar10 == 0xc) {
LAB_140002a53:
    sVar10 = 2;
  }
  else {
    if (sVar10 != 0xe) {
      if (sVar10 == 0x10) goto LAB_140002a53;
      if (sVar10 != 0x12) {
        if (sVar10 == 0x2c) goto LAB_140002a53;
        if (sVar10 != 0x2e) {
          if (sVar10 == 0x30) goto LAB_140002a53;
          if (sVar10 != 0x32) {
            sVar10 = 0;
            goto LAB_140002a57;
          }
        }
      }
    }
    sVar10 = 0x17;
  }
LAB_140002a57:
  local_100 = CONCAT62(local_100._2_6_,sVar10);
  _local_98 = CONCAT62(stack0xffffffffffffff6a,sVar10);
  lVar12 = *(longlong *)(local_e0 + 4);
  psVar15 = local_98;
  if (sVar10 == 2) {
    uVar6 = *(uint *)(lVar12 + 8 + (ulonglong)local_128 * 0x10);
    local_100 = CONCAT44(uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                         uVar6 << 0x18,(undefined4)local_100);
    uVar6 = *(uint *)(lVar12 + 8 + (ulonglong)local_124 * 0x10);
    _local_98 = CONCAT44(uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                         uVar6 << 0x18,local_98);
  }
  else {
    puVar14 = *(undefined8 **)(lVar12 + 8 + (ulonglong)local_128 * 0x10);
    uStack_f8 = *puVar14;
    local_f0 = puVar14[1];
    puVar14 = *(undefined8 **)(lVar12 + 8 + (ulonglong)local_124 * 0x10);
    uStack_90 = *puVar14;
    local_88 = puVar14[1];
    iVar11 = ZtSockaddrInetIsMappedAddress((_SOCKADDR_INET *)local_98);
    if (iVar11 != 0) {
      psVar15 = (short *)&local_78;
      for (lVar13 = 0x1c; lVar13 != 0; lVar13 = lVar13 + -1) {
        *(undefined1 *)psVar15 = 0;
        psVar15 = (short *)((longlong)psVar15 + 1);
      }
      local_68 = 0;
      local_b8 = CONCAT26((short)((ulonglong)local_88 >> 0x30),
                          CONCAT24((short)((ulonglong)local_88 >> 0x20),(uint)uVar16));
      local_60 = 0;
      local_78 = local_b8;
      uStack_70 = 0;
      psVar15 = (short *)&local_78;
    }
  }
  uVar4 = *(undefined2 *)(lVar12 + 8 + (ulonglong)local_11c * 0x10);
  uVar5 = *(undefined2 *)(lVar12 + 8 + (ulonglong)local_118 * 0x10);
  uVar2 = *(undefined1 *)(lVar12 + 8 + (ulonglong)local_114 * 0x10);
  uVar3 = *(undefined1 *)(lVar12 + 8 + (ulonglong)local_110 * 0x10);
  if (local_120 != 0xffffffff) {
    local_108 = *(undefined8 *)(*(longlong *)(lVar12 + 8 + (ulonglong)local_120 * 0x10) + 8);
  }
  uVar7 = *(undefined4 *)(lVar12 + 8 + (ulonglong)local_10c * 0x10);
  if (local_d8 != (undefined8 *)0x0) {
    *local_d8 = local_100;
    local_d8[1] = uStack_f8;
    local_d8[2] = local_f0;
    *(int *)(local_d8 + 3) = (int)local_d0;
  }
  if (param_4 != (undefined8 *)0x0) {
    uVar9 = *(undefined8 *)(psVar15 + 4);
    uVar8 = *(undefined4 *)(psVar15 + 0xc);
    uVar1 = *(undefined8 *)(psVar15 + 8);
    *param_4 = *(undefined8 *)psVar15;
    param_4[1] = uVar9;
    param_4[2] = uVar1;
    *(undefined4 *)(param_4 + 3) = uVar8;
  }
  if (local_c8 != (undefined2 *)0x0) {
    *local_c8 = uVar4;
  }
  if (local_c0 != (undefined2 *)0x0) {
    *local_c0 = uVar5;
  }
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = uVar2;
  }
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = uVar3;
  }
  if (param_8 != (undefined8 *)0x0) {
    *param_8 = local_108;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = uVar7;
  }
  return 0;
}



===== ZtpGetConnectionMetadata @ 140002c1c =====

undefined8
ZtpGetConnectionMetadata(uint *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  uVar2 = 0;
  uVar4 = 0;
  uVar3 = 0;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_1 == (uint *)0x0) {
    uVar5 = 0xc000000d;
  }
  else {
    uVar1 = *param_1;
    if ((uVar1 & 8) != 0) {
      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0xc) + 8);
    }
    if ((uVar1 & 0x10) != 0) {
      uVar4 = *(undefined8 *)(param_1 + 0xe);
    }
    if ((uVar1 & 0x20) != 0) {
      uVar3 = *(undefined8 *)(param_1 + 0x10);
    }
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = uVar2;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = uVar4;
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = uVar3;
    }
  }
  return uVar5;
}



===== ZtpGetValueIndexesForLayer @ 140002cac =====

void ZtpGetValueIndexesForLayer
               (short param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
               undefined4 *param_9)

{
  undefined4 uVar1;
  
  if ((param_1 - 0xcU & 0xfffd) == 0) {
    *param_3 = 2;
    *param_5 = 5;
    *param_6 = 0;
    *param_7 = 4;
    *param_8 = 0xffffffff;
    *param_9 = 9;
  }
  else {
    if ((param_1 - 0x10U & 0xfffd) != 0) {
      if ((param_1 - 0x2cU & 0xfffd) == 0) {
        *param_2 = 2;
        *param_3 = 6;
        *param_4 = 4;
        *param_5 = 7;
        *param_6 = 5;
        *param_8 = 1;
        *param_9 = 0xb;
        return;
      }
      if ((param_1 == 0x30) || (param_1 == 0x32)) {
        uVar1 = 4;
        *param_2 = 2;
        *param_3 = 6;
        *param_5 = 7;
        *param_6 = 5;
        *param_7 = 4;
        *param_8 = 1;
        *param_9 = 0xc;
      }
      else {
        uVar1 = 0xffffffff;
        *param_2 = 0xffffffff;
        *param_3 = 0xffffffff;
        *param_5 = 0xffffffff;
        *param_6 = 0xffffffff;
        *param_8 = 0xffffffff;
        *param_9 = 0xffffffff;
      }
      goto LAB_140002e17;
    }
    *param_3 = 3;
    *param_5 = 5;
    *param_6 = 0;
    *param_7 = 4;
    *param_8 = 0xffffffff;
    *param_9 = 10;
  }
  uVar1 = 4;
  *param_2 = 1;
LAB_140002e17:
  *param_4 = uVar1;
  return;
}



===== ZtpLogConnectionClassification @ 140002e24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long ZtpLogConnectionClassification
               (int param_1,undefined8 param_2,ushort param_3,short *param_4,ushort param_5,
               byte param_6,__uint64 param_7,ZtPidServiceNameMapper *param_8,undefined4 param_9,
               short *param_10)

{
  uchar uVar1;
  long lVar2;
  ZtPidServiceNameMapper *pZVar3;
  ushort *puVar4;
  short *psVar5;
  undefined1 auStack_2d8 [32];
  undefined8 local_2b8;
  uint local_2b0;
  undefined4 local_2a8;
  short *local_2a0;
  uint local_298;
  uint local_290;
  __uint64 local_288;
  ZtPidServiceNameMapper *local_280;
  ushort *local_278;
  short *local_270;
  ushort *local_268;
  int local_258;
  ushort local_254;
  short *local_250;
  ushort local_248 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2d8;
  lVar2 = 0;
  local_254 = param_3;
  local_250 = param_4;
  memset(local_248,0,0x200);
  local_258 = 0;
  puVar4 = (ushort *)0x0;
  psVar5 = (short *)0x0;
  if ((param_10 != (short *)0x0) && (*param_10 != 0)) {
    psVar5 = param_10;
  }
  local_2b8 = param_2;
  if (g_fVelocityDnsBugFix2602 != 0) {
    if (param_1 == 0) {
      if ((Microsoft_Windows_ZTDNSEnableBits & 2) == 0) goto LAB_140002fdf;
    }
    else if ((Microsoft_Windows_ZTDNSEnableBits & 1) == 0) goto LAB_140002f09;
    pZVar3 = param_8;
    uVar1 = ZtIsSystemBinary((ushort *)param_8,(ushort *)0x0);
    if (uVar1 != '\0') {
      lVar2 = ZtPidServiceNameMapper::LookupServiceName(pZVar3,param_7,&local_258,local_248);
      if (lVar2 < 0) {
        return lVar2;
      }
      puVar4 = local_248;
      if (local_258 == 0) {
        puVar4 = (ushort *)0x0;
      }
    }
  }
  if (param_1 == 0) {
LAB_140002fdf:
    local_278 = puVar4;
    if (g_fVelocityDnsBugFix2602 == 0) {
      if ((Microsoft_Windows_ZTDNSEnableBits & 2) == 0) {
        return lVar2;
      }
      pZVar3 = param_8;
      uVar1 = ZtEndsWith((ushort *)param_8,(ushort *)0x0);
      if (uVar1 != '\0') {
        lVar2 = ZtPidServiceNameMapper::LookupServiceName(pZVar3,param_7,&local_258,local_248);
        if (lVar2 < 0) {
          return lVar2;
        }
        local_278 = local_248;
        if (local_258 == 0) {
          local_278 = puVar4;
        }
      }
    }
    if ((Microsoft_Windows_ZTDNSEnableBits & 2) == 0) {
      return lVar2;
    }
    local_280 = param_8;
    local_2a8 = 0x1c;
    if (*local_250 != 0x17) {
      local_2a8 = 0x10;
    }
    local_288 = param_7;
    local_290 = (uint)param_6;
    local_298 = (uint)param_5;
    local_2a0 = local_250;
    local_2b0 = (uint)local_254;
    McTemplateK0qbr0qqbr3qqxzz_EtwWriteTransfer();
    return lVar2;
  }
LAB_140002f09:
  local_268 = puVar4;
  if (g_fVelocityDnsBugFix2602 == 0) {
    if ((Microsoft_Windows_ZTDNSEnableBits & 1) == 0) {
      return lVar2;
    }
    pZVar3 = param_8;
    uVar1 = ZtEndsWith((ushort *)param_8,(ushort *)0x0);
    if (uVar1 != '\0') {
      lVar2 = ZtPidServiceNameMapper::LookupServiceName(pZVar3,param_7,&local_258,local_248);
      if (lVar2 < 0) {
        return lVar2;
      }
      local_268 = local_248;
      if (local_258 == 0) {
        local_268 = puVar4;
      }
    }
  }
  if ((Microsoft_Windows_ZTDNSEnableBits & 1) != 0) {
    local_2a8 = 0x1c;
    if (*local_250 != 0x17) {
      local_2a8 = 0x10;
    }
    local_278 = (ushort *)CONCAT44(local_278._4_4_,param_9);
    local_280 = param_8;
    local_288 = param_7;
    local_290 = (uint)param_6;
    local_298 = (uint)param_5;
    local_2a0 = local_250;
    local_2b0 = (uint)local_254;
    local_270 = psVar5;
    McTemplateK0qbr0qqbr3qqxzqzz_EtwWriteTransfer();
  }
  return lVar2;
}



===== McGenEventWrite_EtwWriteTransfer @ 1400030d0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000e018;
  uVar2 = 0;
  if (DAT_14000e018 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000e018;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(ZTDNS_PROVIDER_ID_Context,param_2,&ZTDNS_PROVIDER_ID,0,param_4,param_5);
  return;
}



===== McTemplateK0qbr0qqbr3qqxzqzz_EtwWriteTransfer @ 140003138 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qbr0qqbr3qqxzqzz_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  wchar_t *in_stack_00000060;
  undefined1 uStack0000000000000068;
  wchar_t *in_stack_00000070;
  wchar_t *in_stack_00000078;
  undefined1 auStackY_118 [32];
  undefined8 local_e8 [2];
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_d8 = local_res20;
  local_b8 = &uStack0000000000000030;
  local_a8 = &uStack0000000000000038;
  local_88 = &uStack0000000000000048;
  local_78 = &uStack0000000000000050;
  local_68 = &uStack0000000000000058;
  lVar1 = -1;
  local_20 = 10;
  local_d0 = 4;
  local_bc = 0;
  local_b0 = 4;
  local_a0 = 4;
  local_8c = 0;
  local_80 = 4;
  local_70 = 4;
  local_60 = 8;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000060[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    in_stack_00000060 = L"NULL";
  }
  local_40 = 4;
  local_48 = &uStack0000000000000068;
  if (in_stack_00000070 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000070[lVar2] != L'\0');
    local_30 = (int)lVar2 * 2 + 2;
  }
  local_2c = 0;
  if (in_stack_00000070 == (wchar_t *)0x0) {
    in_stack_00000070 = L"NULL";
  }
  if (in_stack_00000078 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000078[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  if (in_stack_00000078 == (wchar_t *)0x0) {
    in_stack_00000078 = L"NULL";
  }
  local_1c = 0;
  local_58 = in_stack_00000060;
  local_38 = in_stack_00000070;
  local_28 = in_stack_00000078;
  McGenEventWrite_EtwWriteTransfer
            (in_stack_00000070,&ZTDNS_EVENT_CLASSIFY_PERMIT,in_stack_00000078,0xd,local_e8);
  return;
}



===== McTemplateK0qbr0qqbr3qqxzz_EtwWriteTransfer @ 1400032f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qbr0qqbr3qqxzz_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  wchar_t *in_stack_00000060;
  wchar_t *in_stack_00000068;
  undefined1 auStackY_f8 [32];
  undefined8 local_c8 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8 = local_res20;
  local_98 = &uStack0000000000000030;
  local_88 = &uStack0000000000000038;
  local_68 = &uStack0000000000000048;
  local_58 = &uStack0000000000000050;
  local_48 = &uStack0000000000000058;
  lVar1 = -1;
  local_20 = 10;
  local_b0 = 4;
  local_9c = 0;
  local_90 = 4;
  local_80 = 4;
  local_6c = 0;
  local_60 = 4;
  local_50 = 4;
  local_40 = 8;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000060[lVar2] != L'\0');
    local_30 = (int)lVar2 * 2 + 2;
  }
  local_2c = 0;
  if (in_stack_00000060 == (wchar_t *)0x0) {
    in_stack_00000060 = L"NULL";
  }
  if (in_stack_00000068 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000068[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  if (in_stack_00000068 == (wchar_t *)0x0) {
    in_stack_00000068 = L"NULL";
  }
  local_1c = 0;
  local_38 = in_stack_00000060;
  local_28 = in_stack_00000068;
  McGenEventWrite_EtwWriteTransfer
            (in_stack_00000068,&ZTDNS_EVENT_CLASSIFY_BLOCK,in_stack_00000060,0xb,local_c8);
  return;
}



===== ZtDeviceStartModule @ 140003450 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl ZtDeviceStartModule(void) */

long __cdecl ZtDeviceStartModule(void)

{
  _DRIVER_OBJECT *p_Var1;
  _DEVICE_OBJECT *p_Var2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  longlong lVar6;
  uint *puVar7;
  _FAST_IO_DISPATCH *p_Var8;
  _DEVICE_OBJECT *local_res8;
  longlong local_res10;
  undefined8 local_18;
  wchar_t *local_10;
  
  uVar5 = 1;
  puVar7 = &DAT_14000b168;
  do {
    if ((*puVar7 >> 2 & 0xfff) != uVar5) {
      return -0x3ffffe7d;
    }
    uVar5 = uVar5 + 1;
    puVar7 = puVar7 + 6;
  } while (uVar5 < 5);
  local_res8 = (_DEVICE_OBJECT *)0x0;
  local_res10 = 0;
  local_18 = 0x1c001a;
  p_Var8 = &g_ZtFastIoDispatchTable;
  for (lVar6 = 0xe0; p_Var1 = g_pZtDriverObject, lVar6 != 0; lVar6 = lVar6 + -1) {
    *p_Var8 = (_FAST_IO_DISPATCH)0x0;
    p_Var8 = p_Var8 + 1;
  }
  _DAT_14000e2a0 = ZtFastIoDeviceControl;
  _g_ZtFastIoDispatchTable = 0xe0;
  *(code **)(g_pZtDriverObject + 0x70) = ZtpCreate;
  *(code **)(p_Var1 + 0x80) = ZtpCleanup;
  *(code **)(p_Var1 + 0x100) = ZtpCleanup;
  *(code **)(p_Var1 + 0xe0) = ZtpDeviceControl;
  local_10 = L"\\Device\\ZTDNS";
  *(_FAST_IO_DISPATCH **)(p_Var1 + 0x50) = &g_ZtFastIoDispatchTable;
  iVar3 = IoCreateDevice(p_Var1,0,&local_18,0x12,0x100,0,&local_res8);
  if (iVar3 < 0) {
    if ((DAT_14000e210 & 1) == 0) goto LAB_1400035ed;
    uVar4 = 0x10;
  }
  else {
    iVar3 = ObOpenObjectByPointer(local_res8,0x240,0,0x2000000,0,0,&local_res10);
    if (iVar3 < 0) {
      if ((DAT_14000e210 & 1) == 0) goto LAB_1400035ed;
      uVar4 = 0x11;
    }
    else {
      iVar3 = NtSetSecurityObject(local_res10,4,&DAT_14000b530);
      p_Var2 = local_res8;
      if (-1 < iVar3) {
        local_res8 = (_DEVICE_OBJECT *)0x0;
        g_pZtDeviceObject = p_Var2;
        goto LAB_1400035ed;
      }
      if ((DAT_14000e210 & 1) == 0) goto LAB_1400035ed;
      uVar4 = 0x12;
    }
  }
  WPP_SF_L(uVar4,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,iVar3);
LAB_1400035ed:
  if (local_res10 != 0) {
    ZwClose();
    local_res10 = 0;
  }
  if (local_res8 != (_DEVICE_OBJECT *)0x0) {
    IoDeleteDevice();
  }
  return iVar3;
}



===== ZtDeviceStopModule @ 140003640 =====

/* void __cdecl ZtDeviceStopModule(void) */

void __cdecl ZtDeviceStopModule(void)

{
  IoDeleteDevice(g_pZtDeviceObject);
  g_pZtDeviceObject = (_DEVICE_OBJECT *)0x0;
  return;
}



===== ZtFastIoDeviceControl @ 140003670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl ZtFastIoDeviceControl(struct _FILE_OBJECT * __ptr64,unsigned char,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long,struct _IO_STATUS_BLOCK *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

uchar __cdecl
ZtFastIoDeviceControl
          (_FILE_OBJECT *param_1,uchar param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6,ulong param_7,_IO_STATUS_BLOCK *param_8,_DEVICE_OBJECT *param_9)

{
  code *pcVar1;
  undefined1 uVar2;
  uchar uVar3;
  uint uVar4;
  
  uVar4 = param_7 >> 2 & 0xfff;
  if (((uVar4 - 1 < 4) && (*(ulong *)(&DAT_14000b150 + (ulonglong)uVar4 * 0x18) == param_7)) &&
     (pcVar1 = *(code **)(&DAT_14000b160 + (ulonglong)uVar4 * 0x18), pcVar1 != (code *)0x0)) {
    uVar2 = ExGetPreviousMode();
    uVar3 = (*pcVar1)(param_1,param_3,param_4,param_5,param_6,param_8,uVar2);
  }
  else {
    uVar3 = '\0';
  }
  return uVar3;
}



===== ZtpCleanup @ 140003720 =====

undefined8 ZtpCleanup(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== ZtpCreate @ 140003750 =====

uint ZtpCreate(_DEVICE_OBJECT *param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qq(10,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,param_1,param_2);
  }
  if (((param_1 == g_pZtDeviceObject) &&
      (*(short *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x58) == 0)) &&
     (*(char *)(*(longlong *)(param_2 + 0xb8) + 0x13) == '\x02')) {
    cVar1 = PsIsCurrentThreadInServerSilo();
    if (cVar1 == '\0') {
      cVar1 = IoIs32bitProcess();
      uVar2 = -(uint)(cVar1 != '\0') & 0xc0000010;
    }
    else {
      uVar2 = 0xc0000010;
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xb,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,uVar2);
  }
  *(uint *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== ZtpDeviceControl @ 140003820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ZtpDeviceControl(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar4 = param_1;
  if ((DAT_14000e210 & 1) != 0) {
    uVar4 = 0xc;
    WPP_SF_qq(0xc,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,param_1,param_2);
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(uint *)(lVar2 + 0x18);
  uVar5 = uVar1 >> 2 & 0xfff;
  if ((uVar5 - 1 < 4) && (*(uint *)(&DAT_14000b150 + (ulonglong)uVar5 * 0x18) == uVar1)) {
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_Lqq(uVar4,(ulonglong)uVar1,uVar5,param_2);
    }
    uVar3 = (**(code **)(&DAT_14000b158 + (ulonglong)uVar5 * 0x18))(param_2,lVar2);
  }
  else {
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_L(0xe,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,uVar1);
    }
    uVar3 = 0xc0000010;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xf,&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,uVar3);
  }
  return uVar3;
}



===== ZtEtwRegisterModule @ 140003930 =====

/* long __cdecl ZtEtwRegisterModule(void) */

long __cdecl ZtEtwRegisterModule(void)

{
  McGenEventRegister_EtwRegister();
  return 0;
}



===== ZtEtwUnregisterModule @ 140003950 =====

/* void __cdecl ZtEtwUnregisterModule(void) */

void __cdecl ZtEtwUnregisterModule(void)

{
  McGenEventUnregister_EtwUnregister();
  return;
}



===== McGenControlCallbackV2 @ 140003970 =====

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



===== McGenEventRegister_EtwRegister @ 140003a80 =====

void McGenEventRegister_EtwRegister(void)

{
  if (ZTDNS_PROVIDER_ID_Context == 0) {
    EtwRegister(&ZTDNS_PROVIDER_ID,McGenControlCallbackV2,&ZTDNS_PROVIDER_ID_Context,
                &ZTDNS_PROVIDER_ID_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140003ac0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (ZTDNS_PROVIDER_ID_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    ZTDNS_PROVIDER_ID_Context = 0;
  }
  return uVar1;
}



===== ZtSetExceptionsFastIo @ 140003b00 =====

/* unsigned char __cdecl ZtSetExceptionsFastIo(struct _FILE_OBJECT * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64,unsigned long,struct _IO_STATUS_BLOCK * __ptr64,char) */

uchar __cdecl
ZtSetExceptionsFastIo
          (_FILE_OBJECT *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _IO_STATUS_BLOCK *param_6,char param_7)

{
  _FILE_OBJECT *p_Var1;
  uint uVar2;
  _FILE_OBJECT *p_Var3;
  _FILE_OBJECT *p_Var4;
  void *pvVar5;
  ulonglong uVar6;
  _POOL_EXTENDED_PARAMETER *p_Var7;
  _FILE_OBJECT *local_18;
  
  uVar2 = 0;
  p_Var1 = (_FILE_OBJECT *)(ulonglong)param_3;
  local_18 = (_FILE_OBJECT *)0x0;
  p_Var4 = param_1;
  pvVar5 = param_2;
  p_Var7 = param_4;
  if ((DAT_14000e210 & 1) != 0) {
    p_Var4 = (_FILE_OBJECT *)0x18;
    p_Var7 = param_2;
    WPP_SF_qqdqdqd(0x18,param_2,param_1,param_2);
  }
  if (g_fVelocityZtdns == 0) goto LAB_140003d19;
  if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    uVar2 = 0xc000000d;
    goto LAB_140003d19;
  }
  if ((DAT_14000e210 & 1) != 0) {
    p_Var4 = (_FILE_OBJECT *)0x1e;
    uVar6 = CONCAT71((int7)((ulonglong)pvVar5 >> 8),-(param_7 != '\0')) & 0xffffffffffffff0a;
    param_1 = p_Var1;
    p_Var7 = param_2;
    WPP_SF_PqLcq(0x1e,CONCAT71((int7)(uVar6 >> 8),(char)uVar6 + 'K'),p_Var1,param_2);
  }
  local_18 = (_FILE_OBJECT *)0x0;
  if (param_3 < 0xb8) {
    uVar2 = 0xc000000d;
  }
  else {
    p_Var7 = &ZtLowPriorityPool;
    param_1 = (_FILE_OBJECT *)0x4245745a;
    p_Var4 = (_FILE_OBJECT *)0x100;
    p_Var3 = (_FILE_OBJECT *)ExAllocatePool3(0x100,p_Var1,0x4245745a,&ZtLowPriorityPool,1);
    if (p_Var3 == (_FILE_OBJECT *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      p_Var7 = (_POOL_EXTENDED_PARAMETER *)CONCAT71((int7)((ulonglong)p_Var7 >> 8),param_7);
      param_1 = (_FILE_OBJECT *)0x8;
      uVar2 = ZtCaptureUserMemory(param_2,(__uint64)p_Var1,8,param_7,p_Var3);
      if (-1 < (int)uVar2) {
        p_Var4 = p_Var3;
        uVar2 = ZtpValidateExceptionsBuffer((int *)p_Var3,param_3);
        if (-1 < (int)uVar2) {
          local_18 = p_Var3;
          goto LAB_140003c61;
        }
      }
      ExFreePoolWithTag(p_Var3,0x4245745a);
      p_Var4 = p_Var3;
    }
  }
LAB_140003c61:
  if ((DAT_14000e210 & 1) != 0) {
    p_Var4 = (_FILE_OBJECT *)0x1f;
    param_1 = (_FILE_OBJECT *)(ulonglong)uVar2;
    WPP_SF_L(0x1f,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,uVar2);
  }
  if (-1 < (int)uVar2) {
    if (((byte)DAT_14000e204 & 1) != 0) {
      if (local_18 == (_FILE_OBJECT *)0x0) {
        if ((DAT_14000e210 & 1) != 0) {
          WPP_SF_(0xd,&WPP_20f1d79473f3345f82ae5a59350f1e6e_Traceguids,param_1,p_Var7);
        }
      }
      else {
        if ((DAT_14000e210 & 1) != 0) {
          WPP_SF_qdid(p_Var4,local_18,local_18,*(int *)local_18);
        }
        uVar2 = 0;
        if (*(int *)(local_18 + 0x10) != 0) {
          do {
            ZtPrintException((ushort *)L"Exception:",
                             (_ZT_EXCEPTION *)(local_18 + (ulonglong)uVar2 * 0xa4 + 0x14));
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)(local_18 + 0x10));
        }
      }
    }
    uVar2 = ZtStaticLookupSetStaticExceptions
                      ((_ZT_EXCEPTION *)(local_18 + 0x14),*(ulong *)(local_18 + 0x10));
  }
LAB_140003d19:
  *(undefined8 *)(param_6 + 8) = 0;
  *(uint *)param_6 = uVar2;
  if (local_18 != (_FILE_OBJECT *)0x0) {
    ExFreePoolWithTag(local_18,0x4245745a);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x19,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,uVar2);
  }
  return '\x01';
}



===== ZtSetGlobalPropertiesFastIo @ 140003d90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned char __cdecl ZtSetGlobalPropertiesFastIo(struct _FILE_OBJECT * __ptr64,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,struct _IO_STATUS_BLOCK * __ptr64,char) */

uchar __cdecl
ZtSetGlobalPropertiesFastIo
          (_FILE_OBJECT *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _IO_STATUS_BLOCK *param_6,char param_7)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  __uint64 *p_Var5;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  __uint64 local_48 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = 0;
  uStack_50 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqdqdqd(0xd,param_2,param_1,param_2);
  }
  if ((((param_2 == (void *)0x0) || (param_3 != 0x10)) || (param_4 == (void *)0x0)) ||
     (param_5 != 0x10)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    uVar3 = 4;
    lVar1 = ZtCaptureUserMemory(param_2,0x10,4,param_7,&local_58);
    if (-1 < lVar1) {
      iVar2 = 0x10;
      lVar1 = ZtTryProbeAlignment(param_4,0x10,uVar3,param_7);
      if (-1 < lVar1) {
        if ((DAT_14000e210 & 1) != 0) {
          iVar2 = 0x4000b5b0;
          WPP_SF_L(0xe,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,(uint)(byte)local_58);
          if ((DAT_14000e210 & 1) != 0) {
            iVar2 = 0x4000b5b0;
            WPP_SF_L(0xf,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,(uint)local_58._1_1_);
            if ((DAT_14000e210 & 1) != 0) {
              iVar2 = 0x4000b5b0;
              WPP_SF_L(0x10,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,(uint)local_58._2_1_);
              if ((DAT_14000e210 & 1) != 0) {
                iVar2 = 0x4000b5b0;
                WPP_SF_L(0x11,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,(uint)local_58._3_1_)
                ;
                if ((DAT_14000e210 & 1) != 0) {
                  iVar2 = 0x4000b5b0;
                  WPP_SF_L(0x12,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,
                           (uint)local_58._5_1_);
                  if ((DAT_14000e210 & 1) != 0) {
                    iVar2 = 0x4000b5b0;
                    WPP_SF_L(0x13,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,
                             (uint)local_58._6_1_);
                    if ((DAT_14000e210 & 1) != 0) {
                      iVar2 = 0x4000b5b0;
                      WPP_SF_L(0x14,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,
                               (ulong)uStack_50);
                      if ((DAT_14000e210 & 1) != 0) {
                        iVar2 = 0x4000b5b0;
                        WPP_SF_L(0x15,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,
                                 uStack_50._4_4_);
                        if ((DAT_14000e210 & 1) != 0) {
                          if (g_fZtdnsSelfhostBranch == 0) {
                            uVar4 = 0;
                          }
                          else {
                            uVar4 = (uint)local_58._4_1_;
                          }
                          iVar2 = 0x4000b5b0;
                          WPP_SF_L(0x16,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,uVar4);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        g_fEnableFilters = (int)((byte)local_58 != '\0');
        g_fPersistFilters = (int)(local_58._1_1_ != '\0');
        g_fAuditMode = (int)(local_58._2_1_ != '\0');
        g_fAllowMdns = (int)(local_58._3_1_ != '\0');
        g_fBlockLocalIps = (int)(local_58._5_1_ != '\0');
        g_fAllowIcsDhcpServer = (int)(local_58._6_1_ != '\0');
        g_dwUnicastLifetime = (ulong)uStack_50;
        _g_MaxRecordAge = uStack_50 >> 0x20;
        g_fAllowPlaintextDns = 0;
        if (g_fZtdnsSelfhostBranch != 0) {
          g_fAllowPlaintextDns = (int)(local_58._4_1_ != '\0');
        }
        p_Var5 = local_48;
        lVar1 = ZtWfpConfigureFilters(g_fEnableFilters,iVar2,p_Var5,local_48 + 1);
        if (-1 < lVar1) {
          lVar1 = ZtTryCopyUserMemory(param_4,local_48,(__uint64)p_Var5,param_7);
        }
      }
    }
  }
  *(undefined8 *)(param_6 + 8) = 0;
  *(long *)param_6 = lVar1;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x17,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,lVar1);
  }
  return '\x01';
}



===== ZtSetServiceNameMapFastIo @ 140004060 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned char __cdecl ZtSetServiceNameMapFastIo(struct _FILE_OBJECT * __ptr64,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,struct _IO_STATUS_BLOCK * __ptr64,char) */

uchar __cdecl
ZtSetServiceNameMapFastIo
          (_FILE_OBJECT *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _IO_STATUS_BLOCK *param_6,char param_7)

{
  _ZT_SERVICE_DATA_ARRAY *p_Var1;
  undefined1 uVar2;
  long lVar3;
  _ZT_SERVICE_DATA_ARRAY *p_Var4;
  _ZT_SERVICE_DATA_ARRAY *p_Var5;
  
  lVar3 = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqdqdqd(0x1a,param_2,param_1,param_2);
  }
  p_Var5 = (_ZT_SERVICE_DATA_ARRAY *)0x0;
  if (g_fVelocityZtdns == 0) goto LAB_1400041d2;
  if (param_2 == (void *)0x0) {
LAB_1400040d5:
    lVar3 = -0x3ffffff3;
  }
  else {
    p_Var4 = (_ZT_SERVICE_DATA_ARRAY *)0x0;
    if (param_3 != 0) {
      if (param_3 < 0x210) goto LAB_1400040d5;
      p_Var4 = (_ZT_SERVICE_DATA_ARRAY *)
               ExAllocatePool3(0x40,(ulonglong)param_3,0x4d53745a,&ZtLowPriorityPool,1);
      p_Var5 = p_Var4;
      if (p_Var4 == (_ZT_SERVICE_DATA_ARRAY *)0x0) {
        lVar3 = -0x3fffff66;
        goto LAB_1400041d2;
      }
      lVar3 = ZtCaptureUserMemory(param_2,(ulonglong)param_3,8,param_7,p_Var4);
      if (lVar3 < 0) goto LAB_1400041d2;
      lVar3 = ZtpValidateServiceNameMappingsBuffer(p_Var4,param_3);
      if (lVar3 < 0) goto LAB_1400041d2;
    }
    p_Var5 = (_ZT_SERVICE_DATA_ARRAY *)0x0;
    qsort(p_Var4 + 8,(ulonglong)*(uint *)p_Var4,0x208,CompareZtServiceData);
    uVar2 = ExAcquireSpinLockExclusive(&DAT_14000e398);
    p_Var1 = _g_ZtPidServiceNameMapper;
    _g_ZtPidServiceNameMapper = p_Var4;
    ExReleaseSpinLockExclusive(&DAT_14000e398,uVar2);
    if (p_Var1 != (_ZT_SERVICE_DATA_ARRAY *)0x0) {
      ExFreePoolWithTag(p_Var1,0x4d53745a);
    }
  }
LAB_1400041d2:
  *(undefined8 *)(param_6 + 8) = 0;
  *(long *)param_6 = lVar3;
  if (p_Var5 != (_ZT_SERVICE_DATA_ARRAY *)0x0) {
    ExFreePoolWithTag(p_Var5,0x4d53745a);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x1b,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,lVar3);
  }
  return '\x01';
}



===== ZtUpdateAddressesFastIo @ 140004240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl ZtUpdateAddressesFastIo(struct _FILE_OBJECT * __ptr64,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,struct _IO_STATUS_BLOCK * __ptr64,char) */

uchar __cdecl
ZtUpdateAddressesFastIo
          (_FILE_OBJECT *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5,
          _IO_STATUS_BLOCK *param_6,char param_7)

{
  long lVar1;
  long lVar2;
  _SOCKADDR_INET *p_Var3;
  _SOCKADDR_INET *this;
  void *pvVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStackY_458 [32];
  _SOCKADDR_INET *local_408;
  int local_400 [2];
  _SOCKADDR_INET local_3f8 [944];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_458;
  lVar1 = 0;
  local_408 = (_SOCKADDR_INET *)0x0;
  local_400[0] = 0;
  uVar7 = (ulonglong)param_3;
  this = (_SOCKADDR_INET *)param_1;
  pvVar4 = param_2;
  if ((DAT_14000e210 & 1) != 0) {
    this = (_SOCKADDR_INET *)0xa;
    WPP_SF_qqdqdqd(10,param_2,param_1,param_2);
  }
  if (g_fVelocityZtdns == 0) goto LAB_1400044c9;
  if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    lVar1 = -0x3ffffff3;
    goto LAB_1400044c9;
  }
  if ((DAT_14000e210 & 1) != 0) {
    this = (_SOCKADDR_INET *)0x12;
    uVar5 = CONCAT71((int7)((ulonglong)pvVar4 >> 8),-(param_7 != '\0')) & 0xffffffffffffff0a;
    WPP_SF_PqLcq(0x12,CONCAT71((int7)(uVar5 >> 8),(char)uVar5 + 'K'),uVar7,param_2);
  }
  local_408 = (_SOCKADDR_INET *)0x0;
  if (param_3 < 0x240) {
    lVar1 = -0x3ffffff3;
  }
  else {
    if (param_3 < 0x3a9) {
      p_Var3 = local_3f8;
LAB_140004333:
      lVar1 = ZtCaptureUserMemory(param_2,uVar7,8,param_7,p_Var3);
      this = param_2;
      if (-1 < lVar1) {
        this = p_Var3;
        lVar1 = ZtpValidateAddressBuffer((uint *)p_Var3,uVar7);
        if (-1 < lVar1) {
          local_408 = p_Var3;
          goto LAB_1400043c9;
        }
      }
    }
    else {
      this = (_SOCKADDR_INET *)0x40;
      p_Var3 = (_SOCKADDR_INET *)ExAllocatePool3(0x40,uVar7,0x4241745a,&ZtLowPriorityPool);
      if (p_Var3 != (_SOCKADDR_INET *)0x0) goto LAB_140004333;
      lVar1 = -0x3fffff66;
    }
    if ((p_Var3 != local_3f8) && (p_Var3 != (_SOCKADDR_INET *)0x0)) {
      ExFreePoolWithTag(p_Var3,0x4241745a);
      this = p_Var3;
    }
  }
LAB_1400043c9:
  if ((DAT_14000e210 & 1) != 0) {
    this = (_SOCKADDR_INET *)0x13;
    WPP_SF_L(0x13,&WPP_4327392b0550392b2e7831a46154911e_Traceguids,lVar1);
  }
  if ((-1 < lVar1) && (uVar7 = 0, *(int *)(local_408 + 0x210) != 0)) {
    do {
      p_Var3 = local_408 + uVar7 * 0x28 + 0x220;
      if ((DAT_14000e210 & 1) != 0) {
        this = (_SOCKADDR_INET *)&DAT_0000000b;
        WPP_SF__SOCKADDR_S(0xb,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,(short *)p_Var3,
                           (longlong)(local_408 + 0x10));
      }
      uVar5 = *(ulonglong *)(local_408 + uVar7 * 0x28 + 0x218);
      if ((uVar5 & 1) == 0) {
        if ((uVar5 & 2) == 0) {
          if ((uVar5 & 4) != 0) {
            ZtFastLookupAddDhcp(p_Var3);
            this = p_Var3;
          }
        }
        else {
          ZtLookupDeleteAddress(p_Var3,local_400);
          this = p_Var3;
        }
      }
      else {
        if ((DAT_14000e210 & 1) != 0) {
          this = (_SOCKADDR_INET *)0xd;
          WPP_SF__SOCKADDR_S(0xd,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,(short *)p_Var3,
                             (longlong)(local_408 + 0x10));
        }
        lVar2 = ZtLookup::AddAddress((ZtLookup *)this,p_Var3,(ushort *)(local_408 + 0x10));
        if ((DAT_14000e210 & 1) != 0) {
          this = (_SOCKADDR_INET *)0xe;
          WPP_SF_L(0xe,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,lVar2);
        }
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(local_408 + 0x210));
  }
LAB_1400044c9:
  *(undefined8 *)(param_6 + 8) = 0;
  *(long *)param_6 = lVar1;
  if ((local_3f8 != local_408) && (local_408 != (_SOCKADDR_INET *)0x0)) {
    ExFreePoolWithTag(local_408,0x4241745a);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xc,&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,lVar1);
  }
  return '\x01';
}



===== ZtFastLookupAddDhcp @ 140004548 =====

/* long __cdecl ZtFastLookupAddDhcp(union _SOCKADDR_INET const * __ptr64) */

long __cdecl ZtFastLookupAddDhcp(_SOCKADDR_INET *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined **ppuVar8;
  undefined2 uVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int local_res8 [2];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined4 local_18;
  
  local_res8[0] = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_q(0xe,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,param_1);
  }
  if (param_1 == (_SOCKADDR_INET *)0x0) {
    lVar6 = -0x3ffffff3;
    puVar13 = auStack_38;
  }
  else {
    lVar6 = ZtFastLookupFindDhcp(param_1,local_res8);
    puVar13 = auStack_38;
    if ((-1 < lVar6) && (puVar13 = auStack_38, local_res8[0] == 0)) {
      local_18 = 1;
      puVar7 = (undefined8 *)ExAllocatePool3(0x40,0x28,0x4441745a,&ZtLowPriorityPool);
      puVar13 = auStack_38;
      if (puVar7 == (undefined8 *)0x0) {
        lVar6 = -0x3fffff66;
      }
      else {
        uVar9 = 2;
        puVar7[1] = puVar7;
        *puVar7 = puVar7;
        if (*(short *)param_1 == 2) {
          *(undefined4 *)((longlong)puVar7 + 0x14) = *(undefined4 *)(param_1 + 4);
        }
        else {
          uVar2 = *(undefined4 *)(param_1 + 0xc);
          uVar3 = *(undefined4 *)(param_1 + 0x10);
          uVar4 = *(undefined4 *)(param_1 + 0x14);
          uVar9 = 0x17;
          *(undefined4 *)((longlong)puVar7 + 0x14) = *(undefined4 *)(param_1 + 8);
          *(undefined4 *)(puVar7 + 3) = uVar2;
          *(undefined4 *)((longlong)puVar7 + 0x1c) = uVar3;
          *(undefined4 *)(puVar7 + 4) = uVar4;
        }
        *(undefined2 *)(puVar7 + 2) = uVar9;
        uVar5 = ExAcquireSpinLockExclusive(&g_rwZtDhcpListLock);
        lVar6 = ZtFastLookupFindDhcpLocked(param_1,local_res8);
        puVar12 = auStack_38;
        puVar11 = puVar7;
        puVar13 = auStack_38;
        if ((-1 < lVar6) && (puVar13 = auStack_38, local_res8[0] == 0)) {
          ppuVar8 = &g_ZtDhcpAddressList;
          puVar10 = g_ZtDhcpAddressList;
          if (*(undefined ***)(g_ZtDhcpAddressList + 8) != &g_ZtDhcpAddressList) {
            puVar10 = (undefined *)0x3;
            pcVar1 = (code *)swi(0x29);
            ppuVar8 = (undefined **)(*pcVar1)();
            puVar12 = auStack_30;
          }
          *puVar7 = puVar10;
          puVar7[1] = ppuVar8;
          *(undefined8 **)(puVar10 + 8) = puVar7;
          puVar11 = (undefined8 *)0x0;
          puVar13 = puVar12;
          g_ZtDhcpAddressList = (undefined *)puVar7;
        }
        *(undefined8 *)(puVar13 + -8) = 0x140004687;
        ExReleaseSpinLockExclusive(&g_rwZtDhcpListLock,uVar5);
        if (puVar11 != (undefined8 *)0x0) {
          *(undefined8 *)(puVar13 + -8) = 0x1400046a0;
          ExFreePoolWithTag(puVar11,0x4441745a);
        }
      }
    }
  }
  if ((DAT_14000e210 & 1) != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1400046c2;
    WPP_SF_L(0xf,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,lVar6);
  }
  return lVar6;
}



===== ZtFastLookupFindDhcp @ 1400046e0 =====

/* long __cdecl ZtFastLookupFindDhcp(union _SOCKADDR_INET const * __ptr64,int * __ptr64) */

long __cdecl ZtFastLookupFindDhcp(_SOCKADDR_INET *param_1,int *param_2)

{
  undefined1 uVar1;
  long lVar2;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qq(0xc,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,param_1,param_2);
  }
  uVar1 = ExAcquireSpinLockShared(&g_rwZtDhcpListLock);
  lVar2 = ZtFastLookupFindDhcpLocked(param_1,param_2);
  ExReleaseSpinLockShared(&g_rwZtDhcpListLock,uVar1);
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xd,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,lVar2);
  }
  return lVar2;
}



===== ZtFastLookupFindDhcpLocked @ 140004784 =====

/* long __cdecl ZtFastLookupFindDhcpLocked(union _SOCKADDR_INET const * __ptr64,int * __ptr64) */

long __cdecl ZtFastLookupFindDhcpLocked(_SOCKADDR_INET *param_1,int *param_2)

{
  short sVar1;
  long lVar2;
  undefined **ppuVar3;
  bool bVar4;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qq(10,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,param_1,param_2);
  }
  lVar2 = 0;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if ((param_1 == (_SOCKADDR_INET *)0x0) || (param_2 == (int *)0x0)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    for (ppuVar3 = (undefined **)g_ZtDhcpAddressList; ppuVar3 != &g_ZtDhcpAddressList;
        ppuVar3 = (undefined **)*ppuVar3) {
      if ((ppuVar3 + 2 != (undefined **)0x0) &&
         (sVar1 = *(short *)param_1, sVar1 == *(short *)(ppuVar3 + 2))) {
        if (sVar1 == 2) {
          bVar4 = *(int *)(param_1 + 4) == *(int *)((longlong)ppuVar3 + 0x14);
        }
        else if (sVar1 == 0x17) {
          if ((*(longlong *)(param_1 + 0x10) == *(longlong *)((longlong)ppuVar3 + 0x1c)) &&
             (*(longlong *)(param_1 + 8) == *(longlong *)((longlong)ppuVar3 + 0x14))) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
        }
        else {
          bVar4 = *(int *)(param_1 + 8) == *(int *)((longlong)ppuVar3 + 0x14);
        }
        if (bVar4) {
          *param_2 = 1;
          break;
        }
      }
    }
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xb,&WPP_db5fd34779a43c9fa0bb3652b8b4f51e_Traceguids,lVar2);
  }
  return lVar2;
}



===== ZtDriverUnload @ 140004880 =====

/* void __cdecl ZtDriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl ZtDriverUnload(_DRIVER_OBJECT *param_1)

{
  ZtpDriverStopModules();
  if (g_fFeatureStagingInitialized != 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    g_fFeatureStagingInitialized = 0;
  }
  return;
}



===== ZtpDriverStopModules @ 1400048ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ZtpDriverStopModules(void)

{
  while (g_cZtModulesInitialized != 0) {
    g_cZtModulesInitialized = g_cZtModulesInitialized - 1;
    if ((code *)(&PTR_ZtWppStopModule_14000b1e0)[(ulonglong)g_cZtModulesInitialized * 3] !=
        (code *)0x0) {
      (*(code *)(&PTR_ZtWppStopModule_14000b1e0)[(ulonglong)g_cZtModulesInitialized * 3])();
    }
  }
  KeFlushQueuedDpcs();
  if (g_fVelocityDnsBugFix2602 == 0) {
    RtlFreeUnicodeString(&g_ZtRegistryPath);
  }
  return;
}



===== DriverEntry @ 140004954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(_DRIVER_OBJECT *param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  uint *puVar5;
  undefined **ppuVar6;
  undefined1 auStack_2d8 [32];
  longlong local_2b8 [2];
  undefined1 *local_2a8;
  undefined8 local_2a0;
  wchar_t *local_298;
  undefined8 local_290;
  ushort **local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 *local_270;
  undefined8 local_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined1 local_248 [528];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2d8;
  wil_InitializeFeatureStaging();
  g_fFeatureStagingInitialized = 1;
  uVar4 = Feature_4920_0542__private_IsEnabledDeviceUsageNoInline();
  g_fVelocityZtdns = (int)((int)uVar4 != 0);
  uVar4 = Feature_59369936__private_IsEnabledDeviceUsageNoInline();
  g_fZtdnsSelfhostBranch = 0;
  g_fVelocityDnsBugFix2602 = (int)((int)uVar4 != 0);
  if ((int)uVar4 == 0) {
    cVar1 = RtlCreateUnicodeString(&g_ZtRegistryPath,*(undefined8 *)(param_2 + 8));
    if (cVar1 == '\0') {
      iVar2 = -0x3fffff66;
      goto LAB_140004b64;
    }
  }
  else {
    local_2a0 = 0x260024;
    local_298 = L"\\Device\\BootDevice";
    local_280 = 0x30;
    local_268 = 0x240;
    local_2b8[0] = 0;
    memset(local_248,0,0x208);
    local_2a8 = local_248;
    local_2b8[1] = 0x1040000;
    local_290 = 0x1040000;
    local_288 = &g_wszZtDeviceRoot;
    local_270 = &local_2a0;
    local_278 = 0;
    local_260 = 0;
    uStack_258 = 0;
    iVar2 = ZwOpenSymbolicLinkObject(local_2b8,1,&local_280);
    if ((((-1 < iVar2) &&
         (iVar2 = ZwQuerySymbolicLinkObject(local_2b8[0],local_2b8 + 1,0), -1 < iVar2)) &&
        (iVar2 = RtlDowncaseUnicodeString(&local_290,local_2b8 + 1,0), -1 < iVar2)) &&
       ((DAT_14000e210 & 1) != 0)) {
      WPP_SF_S();
    }
    if (local_2b8[0] != 0) {
      ZwClose();
    }
    if (iVar2 < 0) goto LAB_140004b64;
  }
  uVar3 = 0;
  puVar5 = &DAT_14000b1d0;
  do {
    if (*puVar5 != uVar3) {
      iVar2 = -0x3ffffe7d;
      goto LAB_140004b64;
    }
    uVar3 = uVar3 + 1;
    puVar5 = puVar5 + 6;
    iVar2 = 0;
  } while (uVar3 < 6);
  ppuVar6 = &PTR_ZtWppStartModule_14000b1d8;
  uVar3 = 0;
  g_pZtDriverObject = param_1;
  do {
    if (((code *)*ppuVar6 != (code *)0x0) && (iVar2 = (*(code *)*ppuVar6)(), iVar2 < 0))
    goto LAB_140004b64;
    g_cZtModulesInitialized = g_cZtModulesInitialized + 1;
    uVar3 = uVar3 + 1;
    ppuVar6 = ppuVar6 + 3;
  } while (uVar3 < 6);
  *(code **)(param_1 + 0x68) = ZtDriverUnload;
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_140004b64:
  if (g_fFeatureStagingInitialized != 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    g_fFeatureStagingInitialized = 0;
  }
  ZtpDriverStopModules();
  return iVar2;
}



===== wil_details_RecordCachedUsage @ 140004bf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140004d40 =====

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



===== ZtSetExceptionsIoctl @ 140004dd0 =====

/* long __cdecl ZtSetExceptionsIoctl(struct _IRP * __ptr64,struct _IO_STACK_LOCATION * __ptr64) */

long __cdecl ZtSetExceptionsIoctl(_IRP *param_1,_IO_STACK_LOCATION *param_2)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqd(0xc,param_2,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_1,0);
  return -0x3ffffffe;
}



===== ZtSetGlobalPropertiesIoctl @ 140004e30 =====

/* long __cdecl ZtSetGlobalPropertiesIoctl(struct _IRP * __ptr64,struct _IO_STACK_LOCATION *
   __ptr64) */

long __cdecl ZtSetGlobalPropertiesIoctl(_IRP *param_1,_IO_STACK_LOCATION *param_2)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqd(0xb,param_2,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_1,0);
  return -0x3ffffffe;
}



===== ZtSetServiceNameMapIoctl @ 140004e90 =====

/* long __cdecl ZtSetServiceNameMapIoctl(struct _IRP * __ptr64,struct _IO_STACK_LOCATION * __ptr64)
    */

long __cdecl ZtSetServiceNameMapIoctl(_IRP *param_1,_IO_STACK_LOCATION *param_2)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqd(0xd,param_2,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_1,0);
  return -0x3ffffffe;
}



===== ZtUpdateAddressesIoctl @ 140004ef0 =====

/* long __cdecl ZtUpdateAddressesIoctl(struct _IRP * __ptr64,struct _IO_STACK_LOCATION * __ptr64) */

long __cdecl ZtUpdateAddressesIoctl(_IRP *param_1,_IO_STACK_LOCATION *param_2)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqd(10,param_2,param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x30) = 0xc0000002;
  IofCompleteRequest(param_1,0);
  return -0x3ffffffe;
}



===== ZtLookupDeleteAddress @ 140004f4c =====

/* long __cdecl ZtLookupDeleteAddress(union _SOCKADDR_INET const * __ptr64,int * __ptr64) */

long __cdecl ZtLookupDeleteAddress(_SOCKADDR_INET *param_1,int *param_2)

{
  int iVar1;
  ZtNode *pZVar2;
  long lVar3;
  ZtNode *pZVar4;
  ZtBucket *local_res8;
  ZtNode *local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF__SOCKADDR_(0xf,param_2,(short *)param_1);
  }
  local_res8 = (ZtBucket *)0x0;
  pZVar4 = (ZtNode *)0x0;
  local_48 = 0;
  local_res10 = (ZtNode *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  if (param_1 == (_SOCKADDR_INET *)0x0) {
    lVar3 = -0x3ffffff3;
  }
  else {
    lVar3 = ZtBuildLookupNodeAddrFromSockaddrInet(param_1,(ZT_LOOKUP_NODE_ADDRESS *)&local_58);
    if (-1 < lVar3) {
      local_28 = local_48;
      local_38._0_4_ = (ZtHashtable *)local_58;
      local_38._4_4_ = local_58._4_4_;
      uStack_30 = (undefined4)uStack_50;
      uStack_2c = uStack_50._4_4_;
      lVar3 = ZtHashtable::GetZtBucketFromAddress((ZtHashtable *)local_58,&local_38,&local_res8);
      if (-1 < lVar3) {
        ZtBucket::DeleteAddress(local_res8,(ZT_LOOKUP_NODE_ADDRESS *)&local_58,&local_res10);
        *param_2 = (uint)(local_res10 != (ZtNode *)0x0);
        pZVar4 = local_res10;
      }
    }
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x10,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,lVar3);
  }
  pZVar2 = local_res10;
  if (pZVar4 != (ZtNode *)0x0) {
    LOCK();
    iVar1 = *(int *)pZVar4;
    *(int *)pZVar4 = *(int *)pZVar4 + -1;
    UNLOCK();
    if ((iVar1 == 1) && (local_res10 != (ZtNode *)0x0)) {
      ZtNode::~ZtNode(local_res10);
      ExFreePoolWithTag(pZVar2,0x4e4c745a);
    }
  }
  return lVar3;
}



===== ZtLookupStartModule @ 140005070 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl ZtLookupStartModule(void) */

long __cdecl ZtLookupStartModule(void)

{
  undefined1 *puVar1;
  longlong lVar2;
  long lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined8 *puVar9;
  undefined8 in_R8;
  undefined8 in_R9;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x11,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,in_R8,in_R9);
  }
  DAT_14000e5f8 = 0x400;
  _g_ZtLookup = ExAllocatePool3(0x40,0xc000,0x4241745a,&ZtLowPriorityPool,1);
  lVar3 = 0;
  if (_g_ZtLookup == 0) {
    lVar3 = -0x3fffff66;
  }
  else {
    uVar7 = 0;
    if (DAT_14000e5f8 != 0) {
      do {
        lVar4 = uVar7 * 0x30 + _g_ZtLookup;
        *(undefined8 *)(lVar4 + 0x28) = 0x2000;
        KeInitializeSpinLock(lVar4);
        puVar1 = (undefined1 *)(lVar4 + 0x18);
        if (puVar1 != (undefined1 *)0x0) {
          puVar8 = puVar1;
          for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
          }
        }
        *(undefined1 **)(lVar4 + 0x20) = puVar1;
        *(undefined1 **)puVar1 = puVar1;
        puVar5 = (undefined8 *)(lVar4 + 8);
        if (puVar5 != (undefined8 *)0x0) {
          puVar9 = puVar5;
          for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
            *(undefined1 *)puVar9 = 0;
            puVar9 = (undefined8 *)((longlong)puVar9 + 1);
          }
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        *puVar5 = 0;
        *(undefined8 *)(lVar4 + 0x10) = 0;
      } while (uVar6 < DAT_14000e5f8);
    }
    DAT_14000e600 = 1;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x12,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,lVar3);
  }
  return lVar3;
}



===== ZtLookupStopModule @ 1400051a0 =====

/* void __cdecl ZtLookupStopModule(void) */

void __cdecl ZtLookupStopModule(void)

{
  undefined *puVar1;
  code *pcVar2;
  undefined *puVar3;
  _ZT_EXCEPTION *this;
  undefined1 *puVar4;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x13,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,in_R8,in_R9);
  }
  puVar4 = auStack_28;
  do {
    puVar3 = g_ZtDhcpAddressList;
    if ((undefined **)g_ZtDhcpAddressList == &g_ZtDhcpAddressList) {
LAB_14000520e:
      this = g_pStaticExceptions;
      if (g_pStaticExceptions != (_ZT_EXCEPTION *)0x0) {
        *(undefined8 *)(puVar4 + -8) = 0x140005228;
        ExFreePoolWithTag(g_pStaticExceptions,0x4245745a);
        this = g_pStaticExceptions;
      }
      g_pStaticExceptions = (_ZT_EXCEPTION *)0x0;
      g_cStaticExceptions = 0;
      if (DAT_14000e600 != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x140005247;
        ZtHashtable::Cleanup((ZtHashtable *)this);
        DAT_14000e600 = 0;
      }
      if ((DAT_14000e210 & 1) != 0) {
        *(undefined8 *)(puVar4 + -8) = 0x140005267;
        WPP_SF_(0x14,&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,in_R8,in_R9);
      }
      return;
    }
    if ((*(undefined ***)(g_ZtDhcpAddressList + 8) != &g_ZtDhcpAddressList) ||
       (puVar1 = *(undefined **)g_ZtDhcpAddressList,
       *(undefined **)(puVar1 + 8) != g_ZtDhcpAddressList)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar4 = auStack_20;
      goto LAB_14000520e;
    }
    g_ZtDhcpAddressList = puVar1;
    *(undefined ***)(puVar1 + 8) = &g_ZtDhcpAddressList;
    *(undefined **)(puVar3 + 8) = puVar3;
    *(undefined **)puVar3 = puVar3;
    ExFreePoolWithTag(puVar3,0x4441745a);
  } while( true );
}



===== ZtEndsWith @ 140005274 =====

/* unsigned char __cdecl ZtEndsWith(unsigned short const * __ptr64,unsigned short const * __ptr64)
    */

uchar __cdecl ZtEndsWith(ushort *param_1,ushort *param_2)

{
  ushort *puVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  bool bVar6;
  
  if (param_1 != (ushort *)0x0) {
    lVar5 = 0x100;
    puVar1 = param_1;
    do {
      if (*puVar1 == 0) break;
      puVar1 = puVar1 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    uVar4 = -(ulonglong)(lVar5 != 0) & 0x100U - lVar5;
    if (lVar5 != 0) goto LAB_1400052bb;
  }
  uVar4 = 0;
LAB_1400052bb:
  lVar5 = 0x100;
  pwVar2 = L"svchost.exe";
  do {
    if (*pwVar2 == L'\0') break;
    pwVar2 = pwVar2 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar3 = -(ulonglong)(lVar5 != 0) & -(ulonglong)(lVar5 != 0) & 0x100U - lVar5;
  if ((param_1 == (ushort *)0x0) || (uVar4 < uVar3)) {
    bVar6 = false;
  }
  else {
    lVar5 = RtlCompareMemory(param_1 + (uVar4 - uVar3),L"svchost.exe",uVar3 * 2);
    bVar6 = lVar5 == uVar3 * 2;
  }
  return bVar6;
}



===== ZtIsSystemBinary @ 140005330 =====

/* unsigned char __cdecl ZtIsSystemBinary(unsigned short const * __ptr64,unsigned short const *
   __ptr64) */

uchar __cdecl ZtIsSystemBinary(ushort *param_1,ushort *param_2)

{
  ushort **ppuVar1;
  ushort *puVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar7 = 0;
  uVar6 = 0;
  ppuVar1 = (ushort **)param_2;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_SS(param_1,param_2,(wchar_t *)param_1);
    ppuVar1 = (ushort **)param_2;
  }
  if (param_1 != (ushort *)0x0) {
    ppuVar1 = &g_wszZtDeviceRoot;
    lVar5 = 0x104;
    do {
      if (*(short *)ppuVar1 == 0) break;
      ppuVar1 = (ushort **)((longlong)ppuVar1 + 2);
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    uVar8 = -(ulonglong)(lVar5 != 0) & 0x104U - lVar5;
    if (lVar5 != 0) {
      lVar5 = 0x104;
      puVar2 = param_1;
      do {
        if (*puVar2 == 0) break;
        puVar2 = puVar2 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      if (lVar5 != 0) {
        ppuVar1 = (ushort **)0x104;
        pwVar3 = L"svchost.exe";
        do {
          if (*pwVar3 == L'\0') break;
          pwVar3 = pwVar3 + 1;
          ppuVar1 = (ushort **)((longlong)ppuVar1 + -1);
        } while (ppuVar1 != (ushort **)0x0);
        uVar7 = ~-(uint)(ppuVar1 != (ushort **)0x0) & 0xc000000d;
        uVar9 = -(ulonglong)(ppuVar1 != (ushort **)0x0) & 0x104U - (longlong)ppuVar1;
        if ((ppuVar1 != (ushort **)0x0) &&
           ((-(ulonglong)(lVar5 != 0) & 0x104U - lVar5) == uVar8 + 0x12 + uVar9)) {
          ppuVar1 = &g_wszZtDeviceRoot;
          lVar5 = RtlCompareMemory(param_1,&g_wszZtDeviceRoot,uVar8 * 2);
          if (lVar5 == uVar8 * 2) {
            pwVar3 = L"\\windows\\system32\\";
            lVar5 = RtlCompareMemory(param_1 + uVar8,L"\\windows\\system32\\",0x24);
            ppuVar1 = (ushort **)pwVar3;
            if (lVar5 == 0x24) {
              lVar5 = uVar9 * 2;
              pwVar3 = L"svchost.exe";
              lVar4 = RtlCompareMemory(param_1 + uVar8 + 0x12,L"svchost.exe",lVar5);
              ppuVar1 = (ushort **)pwVar3;
              if (lVar4 == lVar5) {
                uVar6 = 1;
              }
            }
          }
        }
        goto LAB_1400054b5;
      }
    }
    ppuVar1 = (ushort **)0x0;
    uVar7 = 0xc000000d;
  }
LAB_1400054b5:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_ld(0xd,ppuVar1,uVar6,uVar7);
  }
  return (uchar)uVar6;
}



===== ZtSockaddrInetIsMappedAddress @ 1400054f8 =====

/* int __cdecl ZtSockaddrInetIsMappedAddress(union _SOCKADDR_INET const * __ptr64) */

int __cdecl ZtSockaddrInetIsMappedAddress(_SOCKADDR_INET *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (((((param_1 != (_SOCKADDR_INET *)0x0) && (*(short *)param_1 == 0x17)) &&
       (*(short *)(param_1 + 8) == 0)) &&
      ((*(short *)(param_1 + 10) == 0 && (*(short *)(param_1 + 0xc) == 0)))) &&
     ((*(short *)(param_1 + 0xe) == 0 &&
      ((*(short *)(param_1 + 0x10) == 0 && (*(short *)(param_1 + 0x12) == -1)))))) {
    iVar1 = 1;
  }
  return iVar1;
}



===== ZtpAccessCheck @ 14000553c =====

int ZtpAccessCheck(undefined8 param_1,longlong param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if ((param_2 == 0) || (param_3 == (uint *)0x0)) {
    local_res10[0] = -0x3ffffff3;
  }
  else {
    local_res10[0] = 0;
    bVar1 = SeAccessCheckFromState
                      (param_1,param_2,0,0x20000,0,0,&DAT_14000b640,1,local_res18,local_res10);
    uVar2 = (uint)bVar1;
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_ld(10,param_2,uVar2,local_res10[0]);
    }
    if (((uVar2 != 0) || ((local_res10[0] + 0x80000000U & 0x80000000) != 0)) ||
       (local_res10[0] == -0x3fffffde)) {
      if ((g_fVelocityDnsBugFix2602 != 0) && (local_res10[0] == -0x3fffffde)) {
        local_res10[0] = 0;
      }
      *param_3 = uVar2;
    }
  }
  return local_res10[0];
}



===== ZtPrintException @ 140005620 =====

/* void __cdecl ZtPrintException(unsigned short * __ptr64,struct _ZT_EXCEPTION const * __ptr64) */

void __cdecl ZtPrintException(ushort *param_1,_ZT_EXCEPTION *param_2)

{
  undefined8 in_R9;
  
  if (((byte)DAT_14000e204 & 1) != 0) {
    if (param_2 == (_ZT_EXCEPTION *)0x0) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_(10,&WPP_20f1d79473f3345f82ae5a59350f1e6e_Traceguids,param_1,in_R9);
      }
    }
    else if (*(uint *)param_2 == 2) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_SLS_SOCKADDR_D
                  (param_2 + 4,param_2 + 0x24,(wchar_t *)param_1,2,(longlong)(param_2 + 0x24));
      }
    }
    else if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_SLS_SOCKADDR_
                (param_2 + 0x24,param_2,(wchar_t *)param_1,(ulonglong)*(uint *)param_2,
                 (longlong)(param_2 + 0x24));
    }
  }
  return;
}



===== CompareZtServiceData @ 1400056b0 =====

ulonglong CompareZtServiceData(ulonglong *param_1,ulonglong *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(*param_2 < *param_1);
}



===== LookupServiceName @ 1400056d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl ZtPidServiceNameMapper::LookupServiceName(unsigned __int64,int *
   __ptr64,unsigned short * __ptr64) __ptr64 */

long __thiscall
ZtPidServiceNameMapper::LookupServiceName
          (ZtPidServiceNameMapper *this,__uint64 param_1,int *param_2,ushort *param_3)

{
  ushort uVar1;
  undefined1 uVar2;
  void *pvVar3;
  ushort *puVar4;
  longlong lVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 auStackY_278 [32];
  __uint64 local_248;
  undefined1 local_240 [520];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_278;
  uVar6 = 0;
  memset(local_240,0,0x200);
  local_248 = param_1;
  uVar2 = ExAcquireSpinLockShared(&DAT_14000e398);
  if (_g_ZtPidServiceNameMapper != (uint *)0x0) {
    pvVar3 = bsearch(&local_248,_g_ZtPidServiceNameMapper + 2,(ulonglong)*_g_ZtPidServiceNameMapper,
                     0x208,CompareZtServiceData);
    if (pvVar3 != (void *)0x0) {
      lVar5 = 0x100;
      puVar7 = param_3;
      do {
        if ((lVar5 == -0x7ffffefe) ||
           (uVar1 = *(ushort *)((longlong)pvVar3 + (8 - (longlong)param_3) + (longlong)puVar7),
           uVar1 == 0)) break;
        *puVar7 = uVar1;
        puVar7 = puVar7 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      puVar4 = puVar7 + -1;
      if (lVar5 != 0) {
        puVar4 = puVar7;
      }
      *puVar4 = 0;
      uVar6 = ~-(uint)(lVar5 != 0) & 0x80000005;
      if (lVar5 != 0) {
        *param_2 = 1;
      }
    }
  }
  ExReleaseSpinLockShared(&DAT_14000e398,uVar2);
  return uVar6;
}



===== ZtServiceNamesStopModule @ 140005800 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl ZtServiceNamesStopModule(void) */

void __cdecl ZtServiceNamesStopModule(void)

{
  longlong lVar1;
  
  lVar1 = _g_ZtPidServiceNameMapper;
  _g_ZtPidServiceNameMapper = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x4d53745a);
  }
  _g_ZtPidServiceNameMapper = 0;
  return;
}



===== ZtStaticLookupFindAddress @ 140005840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ZtStaticLookupFindAddress(union _SOCKADDR_INET const * __ptr64,unsigned
   long,unsigned short * __ptr64,int * __ptr64,enum _ZT_PERMIT_TYPE * __ptr64) */

long __cdecl
ZtStaticLookupFindAddress
          (_SOCKADDR_INET *param_1,ulong param_2,ushort *param_3,int *param_4,
          _ZT_PERMIT_TYPE *param_5)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  int iVar6;
  _ZT_EXCEPTION *p_Var7;
  undefined1 *_Dst;
  longlong lVar8;
  undefined8 uVar9;
  _ZT_PERMIT_TYPE _Var10;
  long lVar11;
  _ZT_PERMIT_TYPE *p_Var12;
  undefined1 auStackY_128 [32];
  undefined1 local_f8 [4];
  undefined4 local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined8 local_e4;
  undefined4 local_dc;
  undefined1 local_d8;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  _Dst = local_f8;
  uVar9 = 0;
  memset(_Dst,0,0xa4);
  _Var10 = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF__SOCKADDR_dqq(_Dst,uVar9,(short *)param_1);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (_ZT_PERMIT_TYPE *)0x0) {
    p_Var12 = param_5;
    for (lVar8 = 4; lVar8 != 0; lVar8 = lVar8 + -1) {
      *(undefined1 *)p_Var12 = 0;
      p_Var12 = (_ZT_PERMIT_TYPE *)((longlong)p_Var12 + 1);
    }
  }
  if ((((param_1 == (_SOCKADDR_INET *)0x0) || (param_4 == (int *)0x0)) ||
      (param_5 == (_ZT_PERMIT_TYPE *)0x0)) ||
     ((sVar1 = *(short *)param_1, sVar1 != 2 && (sVar1 != 0x17)))) {
    lVar11 = -0x3ffffff3;
  }
  else {
    local_f4 = *(undefined4 *)param_1;
    uStack_f0 = *(undefined4 *)(param_1 + 4);
    uStack_ec = *(undefined4 *)(param_1 + 8);
    uStack_e8 = *(undefined4 *)(param_1 + 0xc);
    local_dc = *(undefined4 *)(param_1 + 0x18);
    local_e4 = *(undefined8 *)(param_1 + 0x10);
    lVar11 = 0;
    local_d8 = 0x20;
    if (sVar1 != 2) {
      local_d8 = 0x80;
    }
    uVar5 = ExAcquireSpinLockShared(&g_rwZtStaticExceptionsLock);
    if (g_pStaticExceptions != (_ZT_EXCEPTION *)0x0) {
      p_Var7 = bsearch(local_f8,g_pStaticExceptions,(ulonglong)g_cStaticExceptions,0xa4,
                       ZtpStaticLookupCompare);
      if (p_Var7 == (_ZT_EXCEPTION *)0x0) {
        iVar6 = 0;
      }
      else {
        ZtPrintException((ushort *)L"Allowed by static exception:",p_Var7);
        uVar9 = *(undefined8 *)(p_Var7 + 0x2c);
        *(undefined8 *)param_3 = *(undefined8 *)(p_Var7 + 0x24);
        *(undefined8 *)(param_3 + 4) = uVar9;
        uVar9 = *(undefined8 *)(p_Var7 + 0x3c);
        *(undefined8 *)(param_3 + 8) = *(undefined8 *)(p_Var7 + 0x34);
        *(undefined8 *)(param_3 + 0xc) = uVar9;
        uVar9 = *(undefined8 *)(p_Var7 + 0x4c);
        *(undefined8 *)(param_3 + 0x10) = *(undefined8 *)(p_Var7 + 0x44);
        *(undefined8 *)(param_3 + 0x14) = uVar9;
        uVar9 = *(undefined8 *)(p_Var7 + 0x5c);
        *(undefined8 *)(param_3 + 0x18) = *(undefined8 *)(p_Var7 + 0x54);
        *(undefined8 *)(param_3 + 0x1c) = uVar9;
        uVar9 = *(undefined8 *)(p_Var7 + 0x6c);
        *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(p_Var7 + 100);
        *(undefined8 *)(param_3 + 0x24) = uVar9;
        uVar9 = *(undefined8 *)(p_Var7 + 0x7c);
        *(undefined8 *)(param_3 + 0x28) = *(undefined8 *)(p_Var7 + 0x74);
        *(undefined8 *)(param_3 + 0x2c) = uVar9;
        uVar2 = *(undefined4 *)(p_Var7 + 0x88);
        uVar3 = *(undefined4 *)(p_Var7 + 0x8c);
        uVar4 = *(undefined4 *)(p_Var7 + 0x90);
        *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(p_Var7 + 0x84);
        *(undefined4 *)(param_3 + 0x32) = uVar2;
        *(undefined4 *)(param_3 + 0x34) = uVar3;
        *(undefined4 *)(param_3 + 0x36) = uVar4;
        uVar9 = *(undefined8 *)(p_Var7 + 0x9c);
        *(undefined8 *)(param_3 + 0x38) = *(undefined8 *)(p_Var7 + 0x94);
        *(undefined8 *)(param_3 + 0x3c) = uVar9;
        param_3[0x3f] = 0;
        iVar6 = *(int *)p_Var7;
        if (iVar6 == 1) {
          _Var10 = 1;
        }
        else if (iVar6 == 2) {
          _Var10 = 2;
        }
        else {
          _Var10 = 0;
          if ((DAT_14000e210 & 1) != 0) {
            WPP_SF_L(10,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,iVar6);
          }
        }
        iVar6 = 1;
      }
      *param_4 = iVar6;
      *param_5 = _Var10;
    }
    ExReleaseSpinLockShared(&g_rwZtStaticExceptionsLock,uVar5);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xc,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,lVar11);
  }
  return lVar11;
}



===== ZtStaticLookupSetStaticExceptions @ 140005a7c =====

/* long __cdecl ZtStaticLookupSetStaticExceptions(struct _ZT_EXCEPTION const * __ptr64,unsigned
   long) */

long __cdecl ZtStaticLookupSetStaticExceptions(_ZT_EXCEPTION *param_1,ulong param_2)

{
  undefined1 uVar1;
  uint uVar2;
  _ZT_EXCEPTION *p_Var3;
  undefined2 uVar4;
  _ZT_EXCEPTION *p_Var5;
  undefined4 in_register_00000014;
  int iVar6;
  ulonglong uVar7;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qd(param_1,CONCAT44(in_register_00000014,param_2),param_1,param_2);
  }
  p_Var5 = (_ZT_EXCEPTION *)0x0;
  if (param_1 == (_ZT_EXCEPTION *)0x0) {
    iVar6 = -0x3ffffff3;
LAB_140005bdd:
    if ((DAT_14000e210 & 1) != 0) {
      WPP_SF_L(0x10,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,iVar6);
    }
  }
  else {
    iVar6 = 0;
    if (param_2 == 0) goto LAB_140005bdd;
    uVar7 = 1;
    if (1 < param_2) {
      do {
        iVar6 = (int)uVar7;
        uVar2 = ZtpStaticLookupCompare
                          ((longlong)(param_1 + (ulonglong)(iVar6 - 1) * 0xa4),
                           (longlong)(param_1 + uVar7 * 0xa4));
        if (-1 < (int)uVar2) {
          if ((DAT_14000e210 & 1) != 0) {
            WPP_SF_ll(0xd,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,iVar6 + -1,iVar6);
          }
          ZtPrintException((ushort *)L"First exception:",param_1 + (ulonglong)(iVar6 - 1) * 0xa4);
          ZtPrintException((ushort *)L"Second exception:",param_1 + uVar7 * 0xa4);
          iVar6 = -0x3ffffff3;
          if ((DAT_14000e210 & 1) == 0) goto LAB_140005bf6;
          uVar4 = 0xe;
          goto LAB_140005bd2;
        }
        uVar7 = (ulonglong)(iVar6 + 1U);
      } while (iVar6 + 1U < param_2);
    }
    uVar7 = (ulonglong)param_2 * 0xa4;
    if (uVar7 < 0x100000000) {
      p_Var3 = (_ZT_EXCEPTION *)
               ExAllocatePool3(0x40,uVar7 & 0xffffffff,0x4245745a,&ZtLowPriorityPool,1);
      if (p_Var3 == (_ZT_EXCEPTION *)0x0) {
        iVar6 = -0x3fffff66;
      }
      else {
        iVar6 = 0;
        memmove(p_Var3,param_1,uVar7 & 0xffffffff);
        p_Var5 = p_Var3;
      }
      goto LAB_140005bdd;
    }
    iVar6 = -0x3fffff6b;
    if ((DAT_14000e210 & 1) != 0) {
      uVar4 = 0xf;
LAB_140005bd2:
      WPP_SF_L(uVar4,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,iVar6);
      goto LAB_140005bdd;
    }
  }
LAB_140005bf6:
  if (iVar6 < 0) {
    if (p_Var5 == (_ZT_EXCEPTION *)0x0) goto LAB_140005c59;
  }
  else {
    uVar1 = ExAcquireSpinLockExclusive(&g_rwZtStaticExceptionsLock);
    p_Var3 = g_pStaticExceptions;
    g_cStaticExceptions = param_2;
    g_pStaticExceptions = p_Var5;
    ExReleaseSpinLockExclusive(&g_rwZtStaticExceptionsLock,uVar1);
    if (p_Var3 == (_ZT_EXCEPTION *)0x0) goto LAB_140005c59;
    p_Var5 = p_Var3;
  }
  ExFreePoolWithTag(p_Var5,0x4245745a);
LAB_140005c59:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x12,&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,iVar6);
  }
  return iVar6;
}



===== ZtpStaticLookupCompare @ 140005ca0 =====

uint ZtpStaticLookupCompare(longlong param_1,longlong param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  ulonglong _Size;
  
  uVar1 = *(ushort *)(param_1 + 4);
  uVar5 = 0;
  uVar4 = (uint)uVar1;
  if (uVar1 == *(ushort *)(param_2 + 4)) {
    if (uVar4 == 2) {
      bVar2 = *(byte *)(param_1 + 0x20);
      if (*(byte *)(param_2 + 0x20) <= *(byte *)(param_1 + 0x20)) {
        bVar2 = *(byte *)(param_2 + 0x20);
      }
      uVar5 = *(uint *)(param_2 + 8);
      uVar3 = -1 << (((char)uVar1 + '\x1e') - bVar2 & 0x1f);
      uVar4 = *(uint *)(param_1 + 8);
      uVar4 = (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18) &
              uVar3;
      uVar3 = (uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18) &
              uVar3;
      if (uVar4 < uVar3) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar3 < uVar4);
      }
    }
    else if (uVar4 == 0x17) {
      bVar2 = *(byte *)(param_1 + 0x20);
      if (*(byte *)(param_2 + 0x20) <= *(byte *)(param_1 + 0x20)) {
        bVar2 = *(byte *)(param_2 + 0x20);
      }
      _Size = (ulonglong)(bVar2 >> 3);
      bVar6 = -1 << (((char)uVar1 + -0xf) - (bVar2 & 7) & 0x1f);
      uVar5 = memcmp((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),_Size);
      if ((uVar5 == 0) && ((bVar2 & 7) != 0)) {
        uVar5 = (uint)(*(byte *)(_Size + param_1 + 0xc) & bVar6) -
                (uint)(*(byte *)(_Size + param_2 + 0xc) & bVar6);
      }
    }
  }
  else {
    uVar5 = uVar4 - *(ushort *)(param_2 + 4);
  }
  return uVar5;
}



===== ZtCaptureUserMemory @ 140005dac =====

/* long __cdecl ZtCaptureUserMemory(void const * __ptr64,unsigned __int64,unsigned long,char,void *
   __ptr64) */

long __cdecl
ZtCaptureUserMemory(void *param_1,__uint64 param_2,ulong param_3,char param_4,void *param_5)

{
  long lVar1;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qPLdq(param_1,param_2,param_1,param_2);
  }
  lVar1 = 0;
  if (param_5 == (void *)0x0) {
    lVar1 = -0x3ffffff3;
  }
  else {
    ZtpProbeAlignment((ulonglong)param_1,param_2,param_3,param_4);
    if (param_4 == '\0') {
      RtlCopyVolatileMemory(param_5,param_1,param_2);
    }
    else {
      RtlCopyFromUser(param_5,param_1,param_2);
    }
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0xe,&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,lVar1);
  }
  return lVar1;
}



===== ZtTryCopyUserMemory @ 140005e9c =====

/* long __cdecl ZtTryCopyUserMemory(void * __ptr64,void const * __ptr64,unsigned __int64,char) */

long __cdecl ZtTryCopyUserMemory(void *param_1,void *param_2,__uint64 param_3,char param_4)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qqP(param_1,param_2,param_1,param_2);
  }
  if (param_4 == '\0') {
    RtlCopyVolatileMemory(param_1,param_2,0x10);
  }
  else {
    RtlCopyToUser(param_1,param_2,0x10);
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x11,&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,0);
  }
  return 0;
}



===== ZtTryProbeAlignment @ 140005f50 =====

/* long __cdecl ZtTryProbeAlignment(void * __ptr64,unsigned __int64,unsigned long,char) */

long __cdecl ZtTryProbeAlignment(void *param_1,__uint64 param_2,ulong param_3,char param_4)

{
  ZtpProbeAlignment((ulonglong)param_1,param_2,8,param_4);
  return 0;
}



===== ZtpProbeAlignment @ 140005f98 =====

void ZtpProbeAlignment(ulonglong param_1,longlong param_2,int param_3,char param_4)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_PqLc(param_1,param_2,param_2,param_1);
  }
  if (param_4 == '\0') {
    if ((param_2 != 0) && ((param_3 - 1 & param_1) != 0)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc00002c5);
    }
  }
  else if ((param_2 != 0) && ((param_1 & param_3 - 1) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  return;
}



===== Feature_4920_0542__private_IsEnabledDeviceUsageNoInline @ 140006044 =====

ulonglong Feature_4920_0542__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4920_0542__private_featureState;
  if ((Feature_4920_0542__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4920_0542__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4920_0542__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4920_0542__private_IsEnabledFallback @ 14000607c =====

void Feature_4920_0542__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4920_0542__private_descriptor);
  return;
}



===== Feature_59369936__private_IsEnabledDeviceUsageNoInline @ 140006098 =====

ulonglong Feature_59369936__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_59369936__private_featureState;
  if (((uint)Feature_59369936__private_featureState & 0x10) == 0) {
    uVar1 = Feature_59369936__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_59369936__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_59369936__private_IsEnabledFallback @ 1400060d0 =====

void Feature_59369936__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400060ec =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_1400062ef:
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar5 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar5 = uVar3 | uVar5 & 0xffffbfff;
      }
      uVar6 = uVar5 >> 5 & 0x1ff;
      uVar3 = uVar6 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 5 ^ uVar5) & 0x3fe0;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_1400061c7:
        uVar5 = 0;
        if (param_3 == 2) {
          uVar5 = 2;
        }
        else if (param_3 == 3) {
          uVar5 = 8;
        }
        else if (param_3 == 6) {
          uVar5 = 4;
        }
        else if (param_3 == 7) {
          uVar5 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar5 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar6 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar6 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar6;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_1400062ef;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar5 = param_3 - 0x140;
          if ((int)uVar5 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_1400061c7;
      }
    }
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar5 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar5 = uVar3 | uVar5 & 0xffbfffff;
      }
      uVar6 = uVar5 >> 0xf & 0x7f;
      uVar3 = uVar6 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 0xf ^ uVar5) & 0x3f8000;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1400063d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_1400064a9;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400064a9;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400064a9;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400064a9;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400064a9;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400064a9;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400064a9;
    }
  }
  uVar3 = 0xff;
LAB_1400064a9:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400065f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_1400066a3:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400066d1;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400066a3;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400066d1:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000685c =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_IsEnabledFallback @ 1400068c0 =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== ZtWfpConfigureFilters @ 140006954 =====

/* long __cdecl ZtWfpConfigureFilters(int,int,unsigned __int64 * __ptr64,unsigned __int64 * __ptr64)
    */

long __cdecl ZtWfpConfigureFilters(int param_1,int param_2,__uint64 *param_3,__uint64 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 in_register_0000000c;
  undefined *puVar3;
  undefined4 in_register_00000014;
  undefined *puVar4;
  uint *puVar5;
  __uint64 *p_Var6;
  __uint64 *p_Var7;
  bool bVar8;
  
  iVar1 = g_fPersistFilters;
  puVar4 = (undefined *)CONCAT44(in_register_00000014,param_2);
  puVar3 = (undefined *)CONCAT44(in_register_0000000c,param_1);
  iVar2 = 0;
  p_Var6 = param_3;
  p_Var7 = param_4;
  if ((DAT_14000e210 & 1) != 0) {
    puVar3 = (undefined *)0x1f;
    p_Var7 = (__uint64 *)(ulonglong)(uint)g_fPersistFilters;
    p_Var6 = (__uint64 *)(ulonglong)(uint)param_1;
    puVar4 = &WPP_267768d4b2dd3730666f29b270f9620e_Traceguids;
    WPP_SF_ll(0x1f,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,param_1,g_fPersistFilters);
  }
  LOCK();
  bVar8 = g_lConfigInProgress == 0;
  if (bVar8) {
    g_lConfigInProgress = 1;
  }
  UNLOCK();
  if (!bVar8) {
    iVar2 = -0x7fffffef;
    goto LAB_140006a71;
  }
  if (param_1 == 0) {
    ZtpWfpUnregisterCallouts(puVar3,puVar4,(ulonglong)p_Var6,p_Var7);
    if (iVar1 == 0) {
      iVar2 = ZtpWfpUninstallFilters((ulonglong)puVar3);
    }
  }
  else {
    iVar2 = ZtpWfpInstallFilters((ulonglong)puVar3,param_3,param_4);
    if (-1 < iVar2) {
      iVar2 = 0;
      puVar5 = (uint *)param_3;
      if ((DAT_14000e210 & 1) != 0) {
        puVar5 = (uint *)&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids;
        puVar3 = (undefined *)0x1d;
        param_4 = g_hWfpEngine;
        WPP_SF_q(0x1d,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,g_hWfpEngine);
      }
      if (g_uiCalloutIdV4 == 0) {
        puVar5 = &g_uiCalloutIdV4;
        puVar3 = &ZTDNS_CALLOUT_V4;
        iVar2 = ZtpWfpRegisterCallout((undefined4 *)&ZTDNS_CALLOUT_V4,&g_uiCalloutIdV4);
        if (-1 < iVar2) goto LAB_140006a16;
      }
      else {
LAB_140006a16:
        if (g_uiCalloutIdV6 == 0) {
          puVar5 = &g_uiCalloutIdV6;
          puVar3 = &ZTDNS_CALLOUT_V6;
          iVar2 = ZtpWfpRegisterCallout((undefined4 *)&ZTDNS_CALLOUT_V6,&g_uiCalloutIdV6);
        }
      }
      if (iVar2 != 0) {
        ZtpWfpUnregisterCallouts(puVar3,puVar5,(ulonglong)param_4,p_Var7);
      }
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_L(0x1e,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
      }
    }
  }
  LOCK();
  g_lConfigInProgress = 0;
  UNLOCK();
LAB_140006a71:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x20,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtWfpStartModule @ 140006ab0 =====

/* long __cdecl ZtWfpStartModule(void) */

long __cdecl ZtWfpStartModule(void)

{
  void *pvVar1;
  int iVar2;
  undefined8 in_R8;
  undefined8 in_R9;
  void *local_res8 [4];
  
  local_res8[0] = (void *)0x0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x21,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,in_R8,in_R9);
  }
  iVar2 = FwpmEngineOpen0(0,10,0,0,local_res8);
  pvVar1 = local_res8[0];
  if (iVar2 < 0) {
    if ((DAT_14000e210 & 1) == 0) {
      return iVar2;
    }
    WPP_SF_L(0x22,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  else {
    local_res8[0] = (void *)0x0;
    g_hWfpEngine = pvVar1;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x23,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtWfpStopModule @ 140006b60 =====

/* void __cdecl ZtWfpStopModule(void) */

void __cdecl ZtWfpStopModule(void)

{
  int in_EDX;
  undefined8 in_R8;
  undefined8 uVar1;
  undefined8 in_R9;
  undefined8 uVar2;
  
  if ((DAT_14000e210 & 1) != 0) {
    in_EDX = 0x4000bc00;
    WPP_SF_(0x24,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,in_R8,in_R9);
  }
  uVar2 = 0;
  uVar1 = 0;
  ZtWfpConfigureFilters(0,in_EDX,(__uint64 *)0x0,(__uint64 *)0x0);
  if (g_hWfpEngine != (void *)0x0) {
    FwpmEngineClose0();
    g_hWfpEngine = (void *)0x0;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x25,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,uVar1,uVar2);
  }
  return;
}



===== ZtpWfpAddBootFilter @ 140006bd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ZtpWfpAddBootFilter(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4
                       ,undefined4 *param_5)

{
  int iVar1;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_98;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  memset((void *)((longlong)&local_118 + 4),0,0xc4);
  local_118 = *param_4;
  uStack_110 = param_4[1];
  local_b8 = 0;
  local_a8 = 0;
  local_d8 = *param_5;
  uStack_d4 = param_5[1];
  uStack_d0 = param_5[2];
  uStack_cc = param_5[3];
  local_f8 = 2;
  local_c8 = 0xfdf154ce;
  uStack_c4 = 0x4a9800cd;
  uStack_c0 = 0xd56f7584;
  uStack_bc = 0x40f4b107;
  local_98 = 0x1001;
  local_108 = param_2;
  local_100 = param_3;
  iVar1 = FwpmFilterAdd0(param_1,&local_118,0,0);
  if ((iVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
    WPP_SF_L(0xe,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
  }
  return iVar1;
}



===== ZtpWfpAddCallout @ 140006cbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ZtpWfpAddCallout(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  memset((void *)((longlong)&local_98 + 4),0,0x54);
  local_98 = *param_5;
  uStack_90 = param_5[1];
  local_58 = *param_4;
  uStack_54 = param_4[1];
  uStack_50 = param_4[2];
  uStack_4c = param_4[3];
  local_78 = 0x10000;
  local_88 = param_2;
  local_80 = param_3;
  iVar1 = FwpmCalloutAdd0(param_1,&local_98,0,0);
  if ((iVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
    WPP_SF_L(0xc,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
  }
  return iVar1;
}



===== ZtpWfpAddCalloutFilter @ 140006d8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ZtpWfpAddCalloutFilter
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
              undefined8 *param_5,undefined4 *param_6,undefined8 param_7)

{
  int iVar1;
  undefined1 auStack_148 [32];
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_148;
  memset((void *)((longlong)&local_128 + 4),0,0xc4);
  local_128 = *param_4;
  uStack_120 = param_4[1];
  local_c8 = 0;
  local_b8 = 0;
  local_e8 = *param_5;
  uStack_e0 = param_5[1];
  local_108 = 1;
  local_a4 = *param_6;
  uStack_a0 = param_6[1];
  uStack_9c = param_6[2];
  uStack_98 = param_6[3];
  local_a8 = 0x5003;
  local_d8 = 0xfdf154ce;
  uStack_d4 = 0x4a9800cd;
  uStack_d0 = 0xd56f7584;
  uStack_cc = 0x40f4b107;
  local_118 = param_2;
  local_110 = param_3;
  iVar1 = FwpmFilterAdd0(param_1,&local_128,0,param_7);
  if ((iVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
    WPP_SF_L(0xd,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
  }
  return iVar1;
}



===== ZtpWfpAddSubLayer @ 140006e90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ZtpWfpAddSubLayer(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  wchar_t *local_58;
  wchar_t *local_50;
  undefined4 local_48;
  undefined2 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(&uStack_64,0,0x44);
  local_48 = 1;
  local_58 = L"ZTDNS Sub-Layer";
  local_50 = L"Sub-Layer for use by ZTDNS";
  local_28 = 0;
  local_68 = 0xfdf154ce;
  uStack_64 = 0x4a9800cd;
  uStack_60 = 0xd56f7584;
  uStack_5c = 0x40f4b107;
  iVar1 = FwpmSubLayerAdd0(param_1,&local_68,0);
  if ((iVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
    WPP_SF_L(0xb,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
  }
  return iVar1;
}



===== ZtpWfpFiltersInstalled @ 140006f54 =====

int ZtpWfpFiltersInstalled(longlong *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_qq(0x11,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,param_1,param_2);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  puVar2 = &ZTDNS_SUBLAYER;
  iVar1 = FwpmSubLayerGetByKey0(param_1,&ZTDNS_SUBLAYER,local_res10);
  if (iVar1 == -0x3fddfff9) {
    iVar1 = 0;
  }
  else if (-1 < iVar1) {
    *param_2 = 1;
  }
  if (local_res10[0] != 0) {
    param_1 = local_res10;
    FwpmFreeMemory0();
    local_res10[0] = 0;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dl(param_1,puVar2,iVar1,*param_2);
  }
  return iVar1;
}



===== ZtpWfpGetFilterIdByGuid @ 140007010 =====

int ZtpWfpGetFilterIdByGuid(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (param_3 == (undefined8 *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_3 = 0;
    iVar1 = FwpmFilterGetByKey0(param_1,param_2,local_res18);
    if (iVar1 < 0) {
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_L(10,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
      }
    }
    else {
      *param_3 = *(undefined8 *)(local_res18[0] + 0xb0);
      FwpmFreeMemory0(local_res18);
    }
  }
  return iVar1;
}



===== ZtpWfpInstallFilters @ 1400070a0 =====

int ZtpWfpInstallFilters(ulonglong param_1,undefined8 *param_2,undefined8 *param_3)

{
  void *pvVar1;
  int iVar2;
  ulonglong local_res8;
  
  pvVar1 = g_hWfpEngine;
  local_res8 = param_1 & 0xffffffff00000000;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_q(0x13,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,g_hWfpEngine);
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = FwpmTransactionBegin0(pvVar1,0);
    if (iVar2 < 0) {
      if ((DAT_14000e210 & 1) == 0) {
        return iVar2;
      }
      WPP_SF_L(0x14,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
    }
    else {
      iVar2 = ZtpWfpFiltersInstalled(pvVar1,(undefined4 *)&local_res8);
      if (-1 < iVar2) {
        if ((int)local_res8 == 0) {
          iVar2 = ZtpWfpAddSubLayer(pvVar1);
          if ((((-1 < iVar2) &&
               (iVar2 = ZtpWfpAddBootFilter(pvVar1,L"ZTDNS IPv4 Boot Filter",L"Blocks IPv4 traffic",
                                            (undefined8 *)&ZTDNS_BOOT_FILTER_V4,
                                            (undefined4 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V4),
               -1 < iVar2)) &&
              (iVar2 = ZtpWfpAddBootFilter(pvVar1,L"ZTDNS IPv6 Boot Filter",L"Blocks IPv6 traffic",
                                           (undefined8 *)&ZTDNS_BOOT_FILTER_V6,
                                           (undefined4 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V6),
              -1 < iVar2)) &&
             (((iVar2 = ZtpWfpAddCallout(pvVar1,L"ZTDNS IPv4 ALE Classify Callout",
                                         L"Intercepts IPv4 outbound connect attempts",
                                         (undefined4 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V4,
                                         (undefined8 *)&ZTDNS_CALLOUT_V4), -1 < iVar2 &&
               (iVar2 = ZtpWfpAddCallout(pvVar1,L"ZTDNS IPv6 ALE Classify Callout",
                                         L"Intercepts IPv6 outbound connect attempts",
                                         (undefined4 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V6,
                                         (undefined8 *)&ZTDNS_CALLOUT_V6), -1 < iVar2)) &&
              ((iVar2 = ZtpWfpAddCalloutFilter
                                  (pvVar1,L"ZTDNS IPv4 Callout Filter",
                                   L"Intercepts IPv4 outbound connect attempts",
                                   (undefined8 *)&ZTDNS_CALLOUT_FILTER_V4,
                                   (undefined8 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V4,
                                   (undefined4 *)&ZTDNS_CALLOUT_V4,param_2), -1 < iVar2 &&
               (iVar2 = ZtpWfpAddCalloutFilter
                                  (pvVar1,L"ZTDNS IPv6 Callout Filter",
                                   L"Intercepts IPv6 outbound connect attempts",
                                   (undefined8 *)&ZTDNS_CALLOUT_FILTER_V6,
                                   (undefined8 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V6,
                                   (undefined4 *)&ZTDNS_CALLOUT_V6,param_3), -1 < iVar2)))))) {
            iVar2 = FwpmTransactionCommit0(pvVar1);
            if (-1 < iVar2) goto LAB_140007330;
            if ((DAT_14000e210 & 1) != 0) {
              WPP_SF_L(0x15,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
            }
          }
        }
        else {
          iVar2 = ZtpWfpGetFilterIdByGuid(pvVar1,&ZTDNS_BOOT_FILTER_V4,param_2);
          if (-1 < iVar2) {
            iVar2 = ZtpWfpGetFilterIdByGuid(pvVar1,&ZTDNS_BOOT_FILTER_V6,param_3);
          }
        }
      }
      FwpmTransactionAbort0(pvVar1);
    }
  }
LAB_140007330:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x16,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtpWfpRegisterCallout @ 14000736c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ZtpWfpRegisterCallout(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 uStack_44;
  ulonglong uStack_3c;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_20 = 0;
  local_1c = 0;
  local_34 = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  local_48 = *param_1;
  uStack_44 = *(undefined8 *)(param_1 + 1);
  uStack_30 = 0x400016e0;
  uStack_2c = 1;
  uStack_28 = 0x40001950;
  uStack_24 = 1;
  uStack_3c = (ulonglong)(uint)param_1[3];
  iVar1 = FwpsCalloutRegister3(g_pZtDeviceObject,&local_48,param_2);
  if ((iVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
    WPP_SF_L(0xf,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar1);
  }
  return iVar1;
}



===== ZtpWfpUninstallFilters @ 140007420 =====

int ZtpWfpUninstallFilters(ulonglong param_1)

{
  void *pvVar1;
  int iVar2;
  ulonglong local_res8;
  
  pvVar1 = g_hWfpEngine;
  local_res8 = param_1 & 0xffffffff00000000;
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_q(0x17,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,g_hWfpEngine);
  }
  iVar2 = FwpmTransactionBegin0(pvVar1,0);
  if (iVar2 < 0) {
    if ((DAT_14000e210 & 1) == 0) {
      return iVar2;
    }
    WPP_SF_L(0x18,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  else {
    iVar2 = ZtpWfpFiltersInstalled(pvVar1,(undefined4 *)&local_res8);
    if ((((((-1 < iVar2) && ((int)local_res8 != 0)) &&
          (iVar2 = FwpmFilterDeleteByKey0(pvVar1,&ZTDNS_BOOT_FILTER_V4), -1 < iVar2)) &&
         ((iVar2 = FwpmFilterDeleteByKey0(pvVar1,&ZTDNS_BOOT_FILTER_V6), -1 < iVar2 &&
          (iVar2 = FwpmFilterDeleteByKey0(pvVar1,&ZTDNS_CALLOUT_FILTER_V4), -1 < iVar2)))) &&
        ((iVar2 = FwpmFilterDeleteByKey0(pvVar1,&ZTDNS_CALLOUT_FILTER_V6), -1 < iVar2 &&
         ((iVar2 = FwpmCalloutDeleteByKey0(pvVar1,&ZTDNS_CALLOUT_V4), -1 < iVar2 &&
          (iVar2 = FwpmCalloutDeleteByKey0(pvVar1,&ZTDNS_CALLOUT_V6), -1 < iVar2)))))) &&
       (iVar2 = FwpmSubLayerDeleteByKey0(pvVar1,&ZTDNS_SUBLAYER), -1 < iVar2)) {
      iVar2 = FwpmTransactionCommit0(pvVar1);
      if (-1 < iVar2) goto LAB_1400075c9;
      if ((DAT_14000e210 & 1) != 0) {
        WPP_SF_L(0x19,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
      }
    }
    FwpmTransactionAbort0(pvVar1);
  }
LAB_1400075c9:
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_L(0x1a,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,iVar2);
  }
  return iVar2;
}



===== ZtpWfpUnregisterCallouts @ 1400075fc =====

void ZtpWfpUnregisterCallouts
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x1b,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,param_3,param_4);
  }
  if (g_uiCalloutIdV4 != 0) {
    uVar1 = FwpsCalloutUnregisterById0();
    if (((int)uVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
      param_3 = (ulonglong)uVar1;
      WPP_SF_L(0x10,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,uVar1);
    }
    g_uiCalloutIdV4 = 0;
  }
  if (g_uiCalloutIdV6 != 0) {
    uVar1 = FwpsCalloutUnregisterById0();
    if (((int)uVar1 < 0) && ((DAT_14000e210 & 1) != 0)) {
      param_3 = (ulonglong)uVar1;
      WPP_SF_L(0x10,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,uVar1);
    }
    g_uiCalloutIdV6 = 0;
  }
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_(0x1c,&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,param_3,param_4);
  }
  return;
}



===== ZtWppStartModule @ 1400076c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl ZtWppStartModule(void) */

long __cdecl ZtWppStartModule(void)

{
  _g_rgFastWppLevelEnabledFlags = 0;
  _DAT_14000e208 = 0;
  _DAT_14000e210 = 0;
  if (FastWppSectionLocked != '\0') {
    FastWppSectionLocked = '\0';
    MmUnlockPagableImageSection(FastWppSectionHandle);
  }
  _WPP_MAIN_CB = 0;
  DAT_14000e348 = &WPP_ThisDir_CTLGUID_CtlGuid;
  DAT_14000e350 = 0;
  _DAT_14000e360 = 0;
  _DAT_14000e368 = 1;
  WppLoadTracingSupport();
  _DAT_14000e360 = 0;
  WppInitKm();
  return 0;
}



===== ZtWppStopModule @ 140007750 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl ZtWppStopModule(void) */

void __cdecl ZtWppStopModule(void)

{
  undefined8 in_RCX;
  undefined8 in_RDX;
  
  FastWppCallback(in_RCX,in_RDX,'\x01',0,0);
  WppCleanupKm();
  _g_rgFastWppLevelEnabledFlags = 0;
  _DAT_14000e208 = 0;
  _DAT_14000e210 = 0;
  if (FastWppSectionLocked != '\0') {
    FastWppSectionLocked = '\0';
    MmUnlockPagableImageSection(FastWppSectionHandle);
  }
  return;
}



===== FastWppCallback @ 1400077ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FastWppCallback(undefined8 param_1,undefined8 param_2,char param_3,undefined4 param_4,
                    byte param_5)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  
  if (param_3 == '\0') {
    _g_rgFastWppLevelEnabledFlags = 0;
    _DAT_14000e208 = 0;
    _DAT_14000e210 = 0;
    if (FastWppSectionLocked != '\0') {
      FastWppSectionLocked = '\0';
      MmUnlockPagableImageSection(FastWppSectionHandle);
    }
  }
  else {
    if (FastWppSectionLocked == '\0') {
      if (FastWppSectionHandle == (void *)0x0) {
        FastWppSectionHandle = (void *)MmLockPagableDataSection(FastWppPlaceholder);
        if (FastWppSectionHandle == (void *)0x0) {
          return;
        }
      }
      else {
        MmLockPagableSectionByHandle();
      }
      FastWppSectionLocked = '\x01';
    }
    uVar2 = 1;
    bVar4 = 5;
    if (param_5 < 6) {
      bVar4 = param_5;
    }
    uVar3 = uVar2;
    if (bVar4 == 0) goto LAB_14000783c;
    do {
      bVar1 = (char)uVar3 + 1;
      uVar2 = (ulonglong)bVar1;
      *(undefined4 *)(&g_rgFastWppLevelEnabledFlags + uVar3 * 4) = param_4;
      uVar3 = uVar2;
    } while (bVar1 <= bVar4);
    for (; (byte)uVar2 < 5; uVar2 = (ulonglong)(byte)((char)uVar2 + 1)) {
LAB_14000783c:
      *(undefined4 *)(&g_rgFastWppLevelEnabledFlags + uVar2 * 4) = 0;
    }
  }
  return;
}



===== FastWppTraceMessage @ 140007890 =====

void FastWppTraceMessage(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  WmiTraceMessageVa(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_1,param_2,&local_res18);
  return;
}



===== WppClassicProviderCallback @ 1400078e0 =====

void WppClassicProviderCallback
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,longlong param_4)

{
  byte bVar1;
  undefined8 uVar2;
  byte bVar3;
  undefined4 uVar4;
  
  bVar3 = (byte)param_2;
  if (bVar3 < 2) {
    uVar2 = 0;
    if (bVar3 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      bVar1 = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined4 *)(param_4 + 0x2c) = uVar4;
      bVar1 = *(byte *)((longlong)param_3 + 2);
      *(byte *)(param_4 + 0x29) = bVar1;
      uVar2 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar2;
    FastWppCallback(CONCAT71((int7)((ulonglong)param_1 >> 8),bVar1),param_2,bVar3,uVar4,bVar1);
  }
  return;
}



===== AddAddress @ 140007930 =====

/* public: void __cdecl ZtBucket::AddAddress(class ZtNode * __ptr64) __ptr64 */

void __thiscall ZtBucket::AddAddress(ZtBucket *this,ZtNode *param_1)

{
  ZtBucket *pZVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  ZtNode *pZVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  ZtNode *this_00;
  uchar local_res8 [8];
  uchar local_res10 [8];
  _RTL_BALANCED_NODE *local_res18;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
  local_res18 = (_RTL_BALANCED_NODE *)0x0;
  local_res10[0] = '\0';
  local_res8[0] = '\0';
  this_00 = (ZtNode *)0x0;
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  GetTreeInsertionParent
            (this,(ZT_LOOKUP_NODE_ADDRESS *)(param_1 + 0x30),&local_res18,local_res10,local_res8);
  if (local_res8[0] == '\0') {
    pZVar1 = this + 0x18;
    if ((*(uint *)(this + 0x28) <= *(uint *)(this + 0x2c)) && (*(ZtBucket **)pZVar1 != pZVar1)) {
      this_00 = (ZtNode *)(*(longlong *)pZVar1 + -0x20);
      DeleteAddressInternal(this,this_00);
      GetTreeInsertionParent
                (this,(ZT_LOOKUP_NODE_ADDRESS *)(param_1 + 0x30),&local_res18,local_res10,local_res8
                );
    }
    RtlRbInsertNodeEx(this + 8,local_res18,local_res10[0],param_1 + 8);
    puVar7 = auStackY_68;
    puVar6 = *(undefined8 **)(this + 0x20);
    pZVar5 = param_1 + 0x20;
    if ((ZtBucket *)*puVar6 != pZVar1) {
      puVar6 = (undefined8 *)0x3;
      pcVar3 = (code *)swi(0x29);
      pZVar5 = (ZtNode *)(*pcVar3)();
      puVar7 = auStackY_60;
    }
    *(ZtBucket **)pZVar5 = pZVar1;
    *(undefined8 **)(pZVar5 + 8) = puVar6;
    *puVar6 = pZVar5;
    *(ZtNode **)(this + 0x20) = pZVar5;
    LOCK();
    *(int *)param_1 = *(int *)param_1 + 1;
    UNLOCK();
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  }
  else {
    KeQuerySystemTimePrecise(local_res18 + 0x48);
    puVar7 = auStackY_68;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140007a39;
  KeReleaseSpinLock(this,uVar4);
  if (this_00 != (ZtNode *)0x0) {
    LOCK();
    iVar2 = *(int *)this_00;
    *(int *)this_00 = *(int *)this_00 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      *(undefined8 *)(puVar7 + -8) = 0x140007a57;
      ZtNode::~ZtNode(this_00);
      *(undefined8 *)(puVar7 + -8) = 0x140007a66;
      ExFreePoolWithTag(this_00,0x4e4c745a);
    }
  }
  return;
}



===== CleanupRbNode @ 140007a8c =====

/* void __cdecl CleanupRbNode(struct _RTL_BALANCED_NODE * __ptr64,void * __ptr64) */

void __cdecl CleanupRbNode(_RTL_BALANCED_NODE *param_1,void *param_2)

{
  ZtNode *this;
  _RTL_BALANCED_NODE *p_Var1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  this = (ZtNode *)(param_1 + -8);
  p_Var1 = param_1 + 0x18;
  lVar3 = *(longlong *)p_Var1;
  if ((*(_RTL_BALANCED_NODE **)(lVar3 + 8) != p_Var1) ||
     (plVar4 = *(longlong **)(param_1 + 0x20), (_RTL_BALANCED_NODE *)*plVar4 != p_Var1)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  *(int *)((longlong)param_2 + 0x2c) = *(int *)((longlong)param_2 + 0x2c) + -1;
  LOCK();
  iVar2 = *(int *)this;
  *(int *)this = *(int *)this + -1;
  UNLOCK();
  if ((iVar2 == 1) && (this != (ZtNode *)0x0)) {
    ZtNode::~ZtNode(this);
    ExFreePoolWithTag(this,0x4e4c745a);
  }
  return;
}



===== CmpLookupAddressNodes @ 140007af8 =====

/* long __cdecl CmpLookupAddressNodes(void * __ptr64,struct _RTL_BALANCED_NODE * __ptr64) */

long __cdecl CmpLookupAddressNodes(void *param_1,_RTL_BALANCED_NODE *param_2)

{
  uint uVar1;
  size_t _Size;
  bool bVar2;
  
  if (*(short *)(param_2 + 0x28) == *(short *)param_1) {
    _Size = 0x10;
    if (*(short *)param_1 != 0x17) {
      _Size = 4;
    }
    uVar1 = memcmp(param_2 + 0x2c,(void *)((longlong)param_1 + 4),_Size);
  }
  else {
    bVar2 = (byte)param_2[0x28] < (byte)*(_RTL_BALANCED_NODE *)param_1;
    if ((param_2[0x28] == *(_RTL_BALANCED_NODE *)param_1) &&
       (bVar2 = (byte)param_2[0x29] < (byte)*(_RTL_BALANCED_NODE *)((longlong)param_1 + 1),
       param_2[0x29] == *(_RTL_BALANCED_NODE *)((longlong)param_1 + 1))) {
      uVar1 = 0;
    }
    else {
      uVar1 = -(uint)bVar2 | 1;
    }
  }
  return uVar1;
}



===== DeleteAddress @ 140007b50 =====

/* public: void __cdecl ZtBucket::DeleteAddress(struct ZT_LOOKUP_NODE_ADDRESS * __ptr64,class ZtNode
   * __ptr64 * __ptr64) __ptr64 */

void __thiscall
ZtBucket::DeleteAddress(ZtBucket *this,ZT_LOOKUP_NODE_ADDRESS *param_1,ZtNode **param_2)

{
  ZtBucket ZVar1;
  undefined1 uVar2;
  long lVar3;
  _RTL_BALANCED_NODE *p_Var4;
  _RTL_BALANCED_NODE *p_Var5;
  
  if (param_2 != (ZtNode **)0x0) {
    *param_2 = (ZtNode *)0x0;
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  ZVar1 = this[0x10];
  p_Var5 = *(_RTL_BALANCED_NODE **)(this + 8);
  if (((byte)this[0x10] & 1) != 0) {
    if (p_Var5 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140007bf0;
    p_Var5 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var5 ^ (ulonglong)(this + 8));
  }
  while (p_Var5 != (_RTL_BALANCED_NODE *)0x0) {
    lVar3 = CmpLookupAddressNodes(param_1,p_Var5);
    if (lVar3 < 0) {
      p_Var4 = *(_RTL_BALANCED_NODE **)p_Var5;
    }
    else {
      if (lVar3 < 1) break;
      p_Var4 = *(_RTL_BALANCED_NODE **)(p_Var5 + 8);
    }
    if ((((byte)ZVar1 & 1) == 0) || (p_Var4 == (_RTL_BALANCED_NODE *)0x0)) {
      p_Var5 = p_Var4;
    }
    else {
      p_Var5 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var5 ^ (ulonglong)p_Var4);
    }
  }
  if (p_Var5 != (_RTL_BALANCED_NODE *)0x0) {
    DeleteAddressInternal(this,(ZtNode *)(p_Var5 + -8));
    *param_2 = (ZtNode *)(p_Var5 + -8);
  }
LAB_140007bf0:
  KeReleaseSpinLock(this,uVar2);
  return;
}



===== DeleteAddressInternal @ 140007c24 =====

/* private: void __cdecl ZtBucket::DeleteAddressInternal(class ZtNode * __ptr64) __ptr64 */

void __thiscall ZtBucket::DeleteAddressInternal(ZtBucket *this,ZtNode *param_1)

{
  ZtNode *pZVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  pZVar1 = param_1 + 0x20;
  lVar2 = *(longlong *)pZVar1;
  if ((*(ZtNode **)(lVar2 + 8) == pZVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x28), (ZtNode *)*plVar3 == pZVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    RtlRbRemoveNode(this + 8,param_1 + 8);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== FindAddress @ 140007c78 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl ZtBucket::FindAddress(struct ZT_LOOKUP_NODE_ADDRESS * __ptr64,class ZtNode *
   __ptr64 * __ptr64) __ptr64 */

void __thiscall
ZtBucket::FindAddress(ZtBucket *this,ZT_LOOKUP_NODE_ADDRESS *param_1,ZtNode **param_2)

{
  ZtBucket ZVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  long lVar6;
  _RTL_BALANCED_NODE *p_Var7;
  _RTL_BALANCED_NODE *p_Var8;
  ZtNode *pZVar9;
  undefined4 local_res8;
  undefined4 uStackX_c;
  
  if (param_2 != (ZtNode **)0x0) {
    *param_2 = (ZtNode *)0x0;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  ZVar1 = this[0x10];
  p_Var8 = *(_RTL_BALANCED_NODE **)(this + 8);
  if (((byte)this[0x10] & 1) != 0) {
    if (p_Var8 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140007d47;
    p_Var8 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var8 ^ (ulonglong)(this + 8));
  }
  while (p_Var8 != (_RTL_BALANCED_NODE *)0x0) {
    lVar6 = CmpLookupAddressNodes(param_1,p_Var8);
    if (lVar6 < 0) {
      p_Var7 = *(_RTL_BALANCED_NODE **)p_Var8;
    }
    else {
      if (lVar6 < 1) break;
      p_Var7 = *(_RTL_BALANCED_NODE **)(p_Var8 + 8);
    }
    if ((((byte)ZVar1 & 1) == 0) || (p_Var7 == (_RTL_BALANCED_NODE *)0x0)) {
      p_Var8 = p_Var7;
    }
    else {
      p_Var8 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var8 ^ (ulonglong)p_Var7);
    }
  }
  if (p_Var8 != (_RTL_BALANCED_NODE *)0x0) {
    local_res8 = 0;
    pZVar9 = (ZtNode *)(p_Var8 + -8);
    uStackX_c = 0;
    KeQuerySystemTimePrecise(&local_res8);
    if (CONCAT44(uStackX_c,local_res8) <= _g_MaxRecordAge * 10000000 + *(longlong *)(p_Var8 + 0x48))
    {
      LOCK();
      *(int *)pZVar9 = *(int *)pZVar9 + 1;
      UNLOCK();
      p_Var7 = p_Var8 + 0x18;
      lVar2 = *(longlong *)p_Var7;
      if ((*(_RTL_BALANCED_NODE **)(lVar2 + 8) == p_Var7) &&
         (plVar3 = *(longlong **)(p_Var8 + 0x20), (_RTL_BALANCED_NODE *)*plVar3 == p_Var7)) {
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        plVar3 = *(longlong **)(this + 0x20);
        if ((ZtBucket *)*plVar3 == this + 0x18) {
          *(ZtBucket **)p_Var7 = this + 0x18;
          *(longlong **)(p_Var8 + 0x20) = plVar3;
          *plVar3 = (longlong)p_Var7;
          *(_RTL_BALANCED_NODE **)(this + 0x20) = p_Var7;
          *param_2 = pZVar9;
          goto LAB_140007d47;
        }
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    DeleteAddressInternal(this,pZVar9);
  }
LAB_140007d47:
  KeReleaseSpinLock(this,uVar5);
  return;
}



===== GetTreeInsertionParent @ 140007dc0 =====

/* private: void __cdecl ZtBucket::GetTreeInsertionParent(struct ZT_LOOKUP_NODE_ADDRESS *
   __ptr64,struct _RTL_BALANCED_NODE * __ptr64 * __ptr64,unsigned char * __ptr64,unsigned char *
   __ptr64) __ptr64 */

void __thiscall
ZtBucket::GetTreeInsertionParent
          (ZtBucket *this,ZT_LOOKUP_NODE_ADDRESS *param_1,_RTL_BALANCED_NODE **param_2,
          uchar *param_3,uchar *param_4)

{
  long lVar1;
  _RTL_BALANCED_NODE *p_Var2;
  _RTL_BALANCED_NODE *p_Var3;
  
  if (param_2 != (_RTL_BALANCED_NODE **)0x0) {
    *param_2 = (_RTL_BALANCED_NODE *)0x0;
  }
  if (param_3 != (uchar *)0x0) {
    *param_3 = '\0';
  }
  if (param_4 != (uchar *)0x0) {
    *param_4 = '\0';
  }
  p_Var3 = *(_RTL_BALANCED_NODE **)(this + 8);
  if ((((byte)this[0x10] & 1) != 0) && (p_Var3 != (_RTL_BALANCED_NODE *)0x0)) {
    p_Var3 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var3 ^ (ulonglong)(this + 8));
  }
  *param_3 = '\0';
  *param_4 = '\0';
  if (p_Var3 != (_RTL_BALANCED_NODE *)0x0) {
    do {
      lVar1 = CmpLookupAddressNodes(param_1,p_Var3);
      if (lVar1 < 1) {
        if (-1 < lVar1) {
          *param_4 = '\x01';
          break;
        }
        p_Var2 = *(_RTL_BALANCED_NODE **)p_Var3;
        if (p_Var2 == (_RTL_BALANCED_NODE *)0x0) {
          *param_3 = '\0';
          break;
        }
      }
      else {
        p_Var2 = *(_RTL_BALANCED_NODE **)(p_Var3 + 8);
        if (p_Var2 == (_RTL_BALANCED_NODE *)0x0) goto code_r0x000140007e3a;
      }
      p_Var3 = p_Var2;
    } while( true );
  }
LAB_140007e56:
  *param_2 = p_Var3;
  return;
code_r0x000140007e3a:
  *param_3 = '\x01';
  goto LAB_140007e56;
}



===== AddAddress @ 140007e7c =====

/* public: long __cdecl ZtLookup::AddAddress(union _SOCKADDR_INET const * __ptr64,unsigned short *
   __ptr64) __ptr64 */

long __thiscall ZtLookup::AddAddress(ZtLookup *this,_SOCKADDR_INET *param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  ZtNode *this_00;
  ushort *puVar3;
  longlong lVar4;
  ulonglong _Size;
  ZtNode *pZVar5;
  void *_Dst;
  ZtLookup *local_res8;
  ZtBucket *local_res10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined8 local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  
  local_res10 = (ZtBucket *)0x0;
  if (param_1 == (_SOCKADDR_INET *)0x0) {
    return -0x3ffffff3;
  }
  local_res8 = this;
  this_00 = (ZtNode *)ExAllocatePool3(0x40,0x58,0x4e4c745a,&ZtLowPriorityPool,1);
  if (this_00 == (ZtNode *)0x0) {
    return -0x3fffffe9;
  }
  *(undefined4 *)this_00 = 1;
  if (this_00 + 0x30 != (ZtNode *)0x0) {
    pZVar5 = this_00 + 0x30;
    for (lVar4 = 0x14; lVar4 != 0; lVar4 = lVar4 + -1) {
      *pZVar5 = (ZtNode)0x0;
      pZVar5 = pZVar5 + 1;
    }
  }
  *(undefined8 *)(this_00 + 0x48) = 0;
  local_res8 = (ZtLookup *)0x0;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  _Dst = (void *)0x0;
  uVar2 = ZtBuildLookupNodeAddrFromSockaddrInet(param_1,(ZT_LOOKUP_NODE_ADDRESS *)&local_68);
  if ((int)uVar2 < 0) goto LAB_140008020;
  if (param_2 == (ushort *)0x0) {
LAB_140007fd2:
    *(void **)(this_00 + 0x48) = _Dst;
    *(undefined8 *)(this_00 + 0x30) = local_68;
    *(undefined8 *)(this_00 + 0x38) = uStack_60;
    *(undefined4 *)(this_00 + 0x40) = local_58;
    *(ZtLookup **)(this_00 + 0x50) = local_res8;
                    /* WARNING: Load size is inaccurate */
    local_48._0_4_ = *(ZtHashtable **)(this_00 + 0x30);
    local_48._4_4_ = *(undefined4 *)(this_00 + 0x34);
    uStack_40 = *(undefined4 *)(this_00 + 0x38);
    uStack_3c = *(undefined4 *)(this_00 + 0x3c);
    local_38 = *(undefined4 *)(this_00 + 0x40);
    uVar2 = ZtHashtable::GetZtBucketFromAddress((ZtHashtable *)local_48,&local_48,&local_res10);
    if (-1 < (int)uVar2) {
      ZtBucket::AddAddress(local_res10,this_00);
    }
  }
  else {
    lVar4 = 0x100;
    puVar3 = param_2;
    do {
      if (*puVar3 == 0) break;
      puVar3 = puVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      _Size = -(ulonglong)(lVar4 != 0) & (0x100 - lVar4) * 2;
      _Dst = (void *)ExAllocatePool3(0x40,_Size + 2,0x4e4e745a,&ZtLowPriorityPool,1);
      if (_Dst != (void *)0x0) {
        memmove(_Dst,param_2,_Size);
        *(undefined2 *)(_Size + (longlong)_Dst) = 0;
        KeQuerySystemTimePrecise(&local_res8);
        goto LAB_140007fd2;
      }
      uVar2 = 0xc000009a;
    }
  }
  if (this_00 == (ZtNode *)0x0) {
    return uVar2;
  }
LAB_140008020:
  LOCK();
  iVar1 = *(int *)this_00;
  *(int *)this_00 = *(int *)this_00 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    ZtNode::~ZtNode(this_00);
    ExFreePoolWithTag(this_00,0x4e4c745a);
  }
  return uVar2;
}



===== ~ZtNode @ 140008070 =====

/* private: __cdecl ZtNode::~ZtNode(void) __ptr64 */

void __thiscall ZtNode::~ZtNode(ZtNode *this)

{
  if (*(longlong *)(this + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x48),0x4e4e745a);
  }
  *(undefined8 *)(this + 0x48) = 0;
  return;
}



===== ZtBuildLookupNodeAddrFromSockaddrInet @ 1400080a8 =====

/* long __cdecl ZtBuildLookupNodeAddrFromSockaddrInet(union _SOCKADDR_INET const * __ptr64,struct
   ZT_LOOKUP_NODE_ADDRESS * __ptr64) */

long __cdecl
ZtBuildLookupNodeAddrFromSockaddrInet(_SOCKADDR_INET *param_1,ZT_LOOKUP_NODE_ADDRESS *param_2)

{
  short sVar1;
  undefined8 uVar2;
  longlong lVar3;
  ZT_LOOKUP_NODE_ADDRESS *pZVar4;
  long lVar5;
  
  lVar5 = 0;
  if (param_2 != (ZT_LOOKUP_NODE_ADDRESS *)0x0) {
    pZVar4 = param_2;
    for (lVar3 = 0x14; lVar3 != 0; lVar3 = lVar3 + -1) {
      *pZVar4 = (ZT_LOOKUP_NODE_ADDRESS)0x0;
      pZVar4 = pZVar4 + 1;
    }
  }
  if ((param_1 == (_SOCKADDR_INET *)0x0) ||
     ((sVar1 = *(short *)param_1, sVar1 != 2 && (sVar1 != 0x17)))) {
    lVar5 = -0x3ffffff3;
  }
  else {
    *(short *)param_2 = sVar1;
    if (*(short *)param_1 == 2) {
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
    }
    else {
      uVar2 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(param_2 + 0xc) = uVar2;
    }
  }
  return lVar5;
}



===== Cleanup @ 14000810c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl ZtHashtable::Cleanup(void) __ptr64 */

void __thiscall ZtHashtable::Cleanup(ZtHashtable *this)

{
  ulonglong *puVar1;
  byte bVar2;
  _RTL_BALANCED_NODE *p_Var3;
  _RTL_BALANCED_NODE *p_Var4;
  _RTL_BALANCED_NODE *p_Var5;
  uint uVar6;
  ulonglong uVar7;
  void *pvVar8;
  
  uVar7 = 0;
  if (DAT_14000e5f8 != 0) {
    do {
      pvVar8 = (void *)(uVar7 * 0x30 + _g_ZtLookup);
      puVar1 = (ulonglong *)((longlong)pvVar8 + 8);
      bVar2 = *(byte *)((longlong)pvVar8 + 0x10);
      p_Var3 = (_RTL_BALANCED_NODE *)*puVar1;
      if ((*(byte *)((longlong)pvVar8 + 0x10) & 1) == 0) {
LAB_140008157:
        if (p_Var3 != (_RTL_BALANCED_NODE *)0x0) {
LAB_14000815c:
          do {
            p_Var4 = *(_RTL_BALANCED_NODE **)p_Var3;
            if (p_Var4 == (_RTL_BALANCED_NODE *)0x0) {
              p_Var5 = p_Var3 + 8;
              p_Var4 = *(_RTL_BALANCED_NODE **)p_Var5;
              if (p_Var4 == (_RTL_BALANCED_NODE *)0x0) {
                p_Var4 = (_RTL_BALANCED_NODE *)(*(ulonglong *)(p_Var3 + 0x10) & 0xfffffffffffffffc);
                if (((bVar2 & 1) != 0) && (p_Var4 != (_RTL_BALANCED_NODE *)0x0)) {
                  p_Var4 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var4 ^ (ulonglong)p_Var3);
                }
                CleanupRbNode(p_Var3,pvVar8);
                if (p_Var4 != (_RTL_BALANCED_NODE *)0x0) {
                  p_Var3 = p_Var4;
                  goto LAB_14000815c;
                }
                break;
              }
            }
            else {
              p_Var5 = p_Var3;
            }
            if ((bVar2 & 1) != 0) {
              p_Var4 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var3 ^ (ulonglong)p_Var4);
            }
            *(ulonglong *)p_Var5 = 0;
            p_Var3 = p_Var4;
          } while( true );
        }
      }
      else if (p_Var3 != (_RTL_BALANCED_NODE *)0x0) {
        p_Var3 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var3 ^ (ulonglong)puVar1);
        goto LAB_140008157;
      }
      bVar2 = *(byte *)((longlong)pvVar8 + 0x10);
      *puVar1 = 0;
      *(undefined8 *)((longlong)pvVar8 + 0x10) = 0;
      if ((bVar2 & 1) != 0) {
        *(undefined1 *)((longlong)pvVar8 + 0x10) = 1;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < DAT_14000e5f8);
  }
  if (_g_ZtLookup != 0) {
    ExFreePoolWithTag(_g_ZtLookup,0x4241745a);
  }
  _g_ZtLookup = 0;
  return;
}



===== GetZtBucketFromAddress @ 140008218 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl ZtHashtable::GetZtBucketFromAddress(struct ZT_LOOKUP_NODE_ADDRESS,class
   ZtBucket * __ptr64 * __ptr64) __ptr64 */

long __thiscall
ZtHashtable::GetZtBucketFromAddress(undefined8 param_1,short *param_2,longlong *param_3)

{
  short sVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  short sStack_24;
  short sStack_22;
  short sStack_20;
  short sStack_1e;
  short sStack_1c;
  short sStack_1a;
  undefined4 local_18;
  
  lVar4 = 0;
  if (param_3 == (longlong *)0x0) {
    lVar4 = -0x3ffffff3;
  }
  else {
    sVar1 = *param_2;
    sStack_24 = (short)*(uint *)(param_2 + 2);
    sStack_22 = param_2[3];
    uVar2 = *(uint *)(param_2 + 2);
    sStack_20 = param_2[4];
    sStack_1e = param_2[5];
    sStack_1c = param_2[6];
    sStack_1a = param_2[7];
    local_18 = *(undefined4 *)(param_2 + 8);
    *param_3 = 0;
    uVar3 = 0;
    if (sVar1 == 2) {
      uVar5 = (*(int *)(&DAT_14000bce0 + ((ulonglong)uVar2 & 0xff) * 4) << 1 |
              (uint)(*(int *)(&DAT_14000bce0 + ((ulonglong)uVar2 & 0xff) * 4) < 0)) ^
              *(uint *)(&DAT_14000bce0 + ((ulonglong)(uVar2 >> 8) & 0xff) * 4);
      uVar5 = (uVar5 << 1 | (uint)((int)uVar5 < 0)) ^
              *(uint *)(&DAT_14000bce0 + (ulonglong)(uVar2 >> 0x10 & 0xff) * 4);
      uVar3 = (uVar5 << 1 | (uint)((int)uVar5 < 0)) ^
              *(uint *)(&DAT_14000bce0 + (ulonglong)(uVar2 >> 0x18) * 4);
    }
    else if (sVar1 == 0x17) {
      uVar3 = ZtComputeIp6Hash((in6_addr *)&sStack_24,(ulong)param_2);
    }
    *param_3 = (ulonglong)(DAT_14000e5f8 - 1U & uVar3) * 0x30 + _g_ZtLookup;
  }
  return lVar4;
}



===== ZtComputeIp6Hash @ 1400082e4 =====

/* unsigned long __cdecl ZtComputeIp6Hash(struct in6_addr const * __ptr64,unsigned long) */

ulong __cdecl ZtComputeIp6Hash(in6_addr *param_1,ulong param_2)

{
  uint uVar1;
  
  uVar1 = (*(int *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 2) & 0xff) * 4) << 1 |
          (uint)(*(int *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 2) & 0xff) * 4) < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 2) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + ((ulonglong)*(ushort *)param_1 & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)param_1 >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 6) & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 6) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + ((ulonglong)*(ushort *)(param_1 + 4) & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 4) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 10) & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 10) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + ((ulonglong)*(ushort *)(param_1 + 8) & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 8) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 0xe) & 0xff) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 0xe) >> 8) * 4);
  uVar1 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
          *(uint *)(&DAT_14000bce0 + ((ulonglong)*(ushort *)(param_1 + 0xc) & 0xff) * 4);
  return (uVar1 << 1 | (uint)((int)uVar1 < 0)) ^
         *(uint *)(&DAT_14000bce0 + (ulonglong)(*(ushort *)(param_1 + 0xc) >> 8) * 4);
}



===== __GSHandlerCheck @ 140008428 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000844c =====

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



===== __security_check_cookie @ 1400084c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlCopyVolatileMemory @ 1400084f0 =====

void * __cdecl RtlCopyVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 140008500 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 140008510 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 140008540 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140008540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140008570 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400085a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140008600 =====

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



===== memset @ 140008900 =====

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



===== __memset_repmovs @ 140008a40 =====

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



===== __memset_query @ 140008ac0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140008b40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140008c80 =====

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



===== __memset_spec_plain @ 140008d00 =====

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



===== memcmp @ 140008e20 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140008e63;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140008ed4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140008ed0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008ed4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140008ecc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008ed0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008ecc;
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
LAB_140008ed4:
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
LAB_140008e63:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== filt$0 @ 140008eed =====

undefined8 `ZtCaptureUserMemory'::__l1::filt_0(undefined8 *param_1)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dqd(0xd,(ulonglong)(*(uint *)*param_1 & 0xc0000000),*(undefined4 *)*param_1,
               *(undefined8 *)((undefined4 *)*param_1 + 4));
  }
  return 1;
}



===== filt$0 @ 140008f4e =====

undefined8 `ZtTryCopyUserMemory'::__l1::filt_0(undefined8 *param_1)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dqd(0x10,(ulonglong)(*(uint *)*param_1 & 0xc0000000),*(undefined4 *)*param_1,
               *(undefined8 *)((undefined4 *)*param_1 + 4));
  }
  return 1;
}



===== filt$0 @ 140008faf =====

undefined8 `ZtTryProbeAlignment'::__l1::filt_0(undefined8 *param_1)

{
  if ((DAT_14000e210 & 1) != 0) {
    WPP_SF_dqd(0xb,(ulonglong)(*(uint *)*param_1 & 0xc0000000),*(undefined4 *)*param_1,
               *(undefined8 *)((undefined4 *)*param_1 + 4));
  }
  return 1;
}



===== memset$thunk$772440563353939046 @ 14000a040 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== RtlCopyToUser @ 140011008 =====

/* WARNING: Removing unreachable block (ram,0x00014001102c) */

void RtlCopyToUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_1,param_3,1);
    RtlCopyVolatileMemory(param_1,param_2,param_3);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001106c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400110a7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140011121:
  while( true ) {
    if (&UNK_14000d037 < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_14000d037 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400110a7:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_14000d037 < ppuVar2) goto LAB_140011121;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140011121;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001115c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400111f8;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400111f8;
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
LAB_1400111f8:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140011260 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_14000d037 < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 1400112e0 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140011300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400113fd;
  }
LAB_140011406:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400113fd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140011406;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1400113ce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1400113ce;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000d037 < ppuVar3) goto LAB_140011406;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400113fd;
}



===== WppCleanupKm @ 14001142c =====

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



===== WppInitKm @ 1400114ac =====

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



===== WppLoadTracingSupport @ 14001153c =====

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
  MmGetSystemRoutineAddress(&local_18);
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



===== WppTraceCallback @ 140011680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined8 uVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  uint *puVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar7 = param_6;
  uVar5 = 0;
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
        uVar8 = (ulonglong)param_4[6];
        do {
          puVar7 = *(uint **)(param_5 + 8);
          if (((*puVar7 == param_4[6]) && (puVar7[1] == param_4[7])) &&
             ((puVar7[2] == param_4[8] && (puVar7[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
          }
          else {
            bVar13 = WPPTraceSuite == 2;
            uVar1 = *(undefined8 *)(param_4 + 2);
            *(undefined8 *)(param_5 + 0x18) = uVar1;
            if (bVar13) {
              iVar4 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
              if (iVar4 == 0) {
                *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
              }
              uVar8 = param_5 + 0x2c;
              puVar7 = (uint *)0x2;
              uVar5 = (*pfnWppQueryTraceInformation)();
            }
            else {
              uStack_34 = (undefined4)((ulonglong)uVar1 >> 0x20);
              *(undefined4 *)(param_5 + 0x2c) = uStack_34;
              uStack_36 = (undefined1)((ulonglong)uVar1 >> 0x10);
              *(undefined1 *)(param_5 + 0x29) = uStack_36;
            }
          }
          FastWppCallback(puVar7,uVar8,param_1 != 5,*(undefined4 *)(param_5 + 0x2c),
                          *(byte *)(param_5 + 0x29));
          return uVar5;
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
      puVar2 = *(ushort **)(param_5 + 0x20);
      lVar6 = param_5;
      do {
        lVar6 = *(longlong *)(lVar6 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar6 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar2 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar2 + 2 + uVar11;
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
      if (puVar2 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar2;
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar2 + 4),
                (ulonglong)*puVar2);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar1 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar1;
          *(undefined8 *)(puVar9 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar7 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== WPP_SF_PqLcq @ 140012008 =====

void WPP_SF_PqLcq(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_4327392b0550392b2e7831a46154911e_Traceguids,param_1,&local_res18,8);
  return;
}



===== WPP_SF_L @ 140012084 =====

void WPP_SF_L(undefined2 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  FastWppTraceMessage(param_2,param_1,local_res18,4);
  return;
}



===== WPP_SF_dIL @ 1400120b8 =====

void WPP_SF_dIL(void)

{
  undefined4 local_18 [6];
  
  local_18[0] = 0xc000000d;
  FastWppTraceMessage(&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0x1d,local_18,4);
  return;
}



===== WPP_SF_ll @ 140012114 =====

void WPP_SF_ll(undefined2 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(param_2,param_1,local_res18,4);
  return;
}



===== WPP_SF_di @ 140012158 =====

void WPP_SF_di(void)

{
  undefined4 local_18 [6];
  
  local_18[0] = 0xc000000d;
  FastWppTraceMessage(&WPP_4327392b0550392b2e7831a46154911e_Traceguids,0x11,local_18,4);
  return;
}



===== WPP_SF_ @ 1400121a8 =====

void WPP_SF_(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FastWppTraceMessage(param_2,param_1,0,param_4);
  return;
}



===== WPP_SF_Sqi @ 1400121cc =====

void WPP_SF_Sqi(undefined8 param_1,undefined8 param_2,wchar_t *param_3)

{
  longlong lVar1;
  
  if (param_3 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0xb,param_3,lVar1);
  return;
}



===== WPP_SF__SOCKADDR__SOCKADDR_ddddqD @ 140012250 =====

void WPP_SF__SOCKADDR__SOCKADDR_ddddqD(undefined8 param_1,undefined8 param_2,short *param_3)

{
  undefined *puVar1;
  
  puVar1 = &FastWppSockaddrInSize;
  if (param_3 != (short *)0x0) {
    if (*param_3 == 0x17) {
      puVar1 = &FastWppSockaddrIn6Size;
    }
    else {
      puVar1 = &FastWppSockaddrInSize;
    }
  }
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,10,puVar1,2);
  return;
}



===== WPP_SF_ddqqiq @ 1400123a0 =====

void WPP_SF_ddqqiq(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x14,local_res18,4);
  return;
}



===== WPP_SF_dq @ 140012420 =====

void WPP_SF_dq(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x17,local_res18,4);
  return;
}



===== WPP_SF_dqdqdqq @ 14001246c =====

void WPP_SF_dqdqdqq(undefined2 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,param_1,local_res18,4);
  return;
}



===== WPP_SF_iddlll @ 1400124f8 =====

void WPP_SF_iddlll(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_res18;
  undefined4 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x15,&local_res18,8);
  return;
}



===== WPP_SF_lll @ 140012578 =====

void WPP_SF_lll(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x1b,local_res18,4);
  return;
}



===== WPP_SF_lllll @ 1400125cc =====

void WPP_SF_lllll(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x12,local_res18,4);
  return;
}



===== WPP_SF_qq @ 140012638 =====

void WPP_SF_qq(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(param_2,param_1,&local_res18,8);
  return;
}



===== WPP_SF_qqq @ 14001267c =====

void WPP_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0xc,&local_res18,8);
  return;
}



===== WPP_SF_qqqqqiq @ 1400126d0 =====

void WPP_SF_qqqqqiq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_2ceec9b72b533d93955ab1623bc012ca_Traceguids,0x20,&local_res18,8);
  return;
}



===== WPP_SF_Lqq @ 140012758 =====

void WPP_SF_Lqq(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_98fe5ae3170b3db52e6af89f98829eac_Traceguids,0xd,local_res18,4);
  return;
}



===== WPP_SF__SOCKADDR_S @ 1400127ac =====

void WPP_SF__SOCKADDR_S(undefined2 param_1,undefined8 param_2,short *param_3,longlong param_4)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (param_4 != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
  }
  if ((param_3 == (short *)0x0) || (*param_3 != 0x17)) {
    puVar2 = &FastWppSockaddrInSize;
  }
  else {
    puVar2 = &FastWppSockaddrIn6Size;
  }
  FastWppTraceMessage(param_2,param_1,puVar2,2);
  return;
}



===== WPP_SF_qqdqdqd @ 14001285c =====

void WPP_SF_qqdqdqd(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_76b4745500423fbd3ac5006333d18d37_Traceguids,param_1,&local_res18,8);
  return;
}



===== WPP_SF_q @ 1400128e8 =====

void WPP_SF_q(undefined2 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_res18 [2];
  
  local_res18[0] = param_3;
  FastWppTraceMessage(param_2,param_1,local_res18,8);
  return;
}



===== WPP_SF_qqd @ 14001291c =====

void WPP_SF_qqd(undefined2 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_524ff22f836f3855664642cd3640ca57_Traceguids,param_1,&local_res18,8);
  return;
}



===== WPP_SF__SOCKADDR_ @ 140012974 =====

void WPP_SF__SOCKADDR_(undefined2 param_1,undefined8 param_2,short *param_3)

{
  undefined *puVar1;
  
  if ((param_3 == (short *)0x0) || (*param_3 != 0x17)) {
    puVar1 = &FastWppSockaddrInSize;
  }
  else {
    puVar1 = &FastWppSockaddrIn6Size;
  }
  FastWppTraceMessage(&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,param_1,puVar1,2);
  return;
}



===== WPP_SF__SOCKADDR_Sl @ 1400129e4 =====

void WPP_SF__SOCKADDR_Sl(undefined8 param_1,undefined8 param_2,short *param_3,longlong param_4)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (param_4 != 0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (*(short *)(param_4 + lVar1 * 2) != 0);
  }
  if ((param_3 == (short *)0x0) || (*param_3 != 0x17)) {
    puVar2 = &FastWppSockaddrInSize;
  }
  else {
    puVar2 = &FastWppSockaddrIn6Size;
  }
  FastWppTraceMessage(&WPP_990d492fc94a3fff1556bca344442c27_Traceguids,0xb,puVar2,2);
  return;
}



===== WPP_SF_S @ 140012aa8 =====

void WPP_SF_S(void)

{
  longlong lVar1;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(short *)((longlong)&g_wszZtDeviceRoot + lVar1 * 2) != 0);
  FastWppTraceMessage(&WPP_983ece47146f32202eceee1e8d2a9224_Traceguids,0xb,&g_wszZtDeviceRoot,
                      lVar1 * 2 + 2);
  return;
}



===== WPP_SF_SS @ 140012af0 =====

void WPP_SF_SS(undefined8 param_1,undefined8 param_2,wchar_t *param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (L"svchost.exe"[lVar2] != L'\0');
  if (param_3 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  FastWppTraceMessage(&WPP_983ece47146f32202eceee1e8d2a9224_Traceguids,0xc,param_3,lVar1);
  return;
}



===== WPP_SF_ld @ 140012b74 =====

void WPP_SF_ld(undefined2 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_983ece47146f32202eceee1e8d2a9224_Traceguids,param_1,local_res18,4);
  return;
}



===== WPP_SF_SLS_SOCKADDR_ @ 140012bbc =====

void WPP_SF_SLS_SOCKADDR_
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined8 param_4,
               longlong param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = -1;
  lVar3 = 10;
  if (param_5 != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
  }
  if (param_3 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    lVar3 = lVar1 * 2 + 2;
  }
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  FastWppTraceMessage(&WPP_20f1d79473f3345f82ae5a59350f1e6e_Traceguids,0xc,param_3,lVar3);
  return;
}



===== WPP_SF_SLS_SOCKADDR_D @ 140012ce0 =====

void WPP_SF_SLS_SOCKADDR_D
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined8 param_4,
               longlong param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = -1;
  lVar3 = 10;
  if (param_5 != 0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (*(short *)(param_5 + lVar2 * 2) != 0);
  }
  if (param_3 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_3[lVar1] != L'\0');
    lVar3 = lVar1 * 2 + 2;
  }
  if (param_3 == (wchar_t *)0x0) {
    param_3 = L"NULL";
  }
  FastWppTraceMessage(&WPP_20f1d79473f3345f82ae5a59350f1e6e_Traceguids,0xb,param_3,lVar3);
  return;
}



===== WPP_SF_qdid @ 140012e1c =====

void WPP_SF_qdid(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_res18;
  undefined4 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_20f1d79473f3345f82ae5a59350f1e6e_Traceguids,0xe,&local_res18,8);
  return;
}



===== WPP_SF__SOCKADDR_dqq @ 140012e7c =====

void WPP_SF__SOCKADDR_dqq(undefined8 param_1,undefined8 param_2,short *param_3)

{
  undefined *puVar1;
  
  if ((param_3 == (short *)0x0) || (*param_3 != 0x17)) {
    puVar1 = &FastWppSockaddrInSize;
  }
  else {
    puVar1 = &FastWppSockaddrIn6Size;
  }
  FastWppTraceMessage(&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,0xb,puVar1,2);
  return;
}



===== WPP_SF_qd @ 140012f38 =====

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_res18;
  undefined4 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_e42dfdb80a3a36af61a3397132d7c6fe_Traceguids,0x11,&local_res18,8);
  return;
}



===== WPP_SF_PqLc @ 140012f84 =====

void WPP_SF_PqLc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,10,&local_res18,8);
  return;
}



===== WPP_SF_dqd @ 140012fec =====

void WPP_SF_dqd(undefined2 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,param_1,local_res18,4);
  return;
}



===== WPP_SF_qPLdq @ 140013044 =====

void WPP_SF_qPLdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,0xc,&local_res18,8);
  return;
}



===== WPP_SF_qqP @ 1400130b0 =====

void WPP_SF_qqP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_f6254d2cab91391a859237ecacdfd871_Traceguids,0xf,&local_res18,8);
  return;
}



===== WPP_SF_dl @ 14001310c =====

void WPP_SF_dl(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res18 [2];
  undefined4 local_res20;
  
  local_res18[0] = param_3;
  local_res20 = param_4;
  FastWppTraceMessage(&WPP_267768d4b2dd3730666f29b270f9620e_Traceguids,0x12,local_res18,4);
  return;
}



===== FastWppPlaceholder @ 140013160 =====

void FastWppPlaceholder(void)

{
  return;
}



===== entry @ 140014010 =====

void entry(_DRIVER_OBJECT *param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140014044 =====

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



===== wil_InitializeFeatureStaging @ 140014078 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400140ff;
    }
LAB_140014139:
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_1400140ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140014139;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140014139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000d037 < ppuVar3) goto LAB_140014139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400140ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001418c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000d037 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140014276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140014276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140014276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000d037 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


