
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0001030 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c0007008;
  uVar2 = 0;
  if (DAT_1c0007008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c0007008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(UevAgentDriver_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0hzr0q_EtwWriteTransfer @ 1c0001094 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,undefined1 param_6)

{
  ushort local_res20 [4];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 2;
  local_48 = local_res20;
  local_2c = 0;
  local_38 = param_5;
  local_30 = (uint)param_4 * 2;
  local_20 = 4;
  local_28 = &param_6;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,&ProcessStart2,param_3,4,local_58);
  return;
}



===== DbgTrace @ 1c000111c =====

void DbgTrace(undefined8 param_1,char *param_2,undefined8 param_3)

{
  if ((uint)param_1 <= g_DebugLevel) {
    if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 0x20) != 0) {
      McTemplateK0s_EtwWriteTransfer(param_1,&Trace_Verbose,param_3,param_2);
    }
    DbgPrintEx(0x4d,2,param_2);
  }
  return;
}



===== DbgTraceErr @ 1c000116c =====

void DbgTraceErr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 4) != 0) {
    McTemplateK0s_EtwWriteTransfer(param_1,&Trace_Error,param_3,(char *)param_1);
  }
  DbgPrintEx(0x4d,2,param_1);
  return;
}



===== DbgTraceFrmt @ 1c00011b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DbgTraceFrmt(uint param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  char *_Dest;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_248 [48];
  char local_218 [511];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_248;
  if (param_1 <= g_DebugLevel) {
    _Dest = local_218;
    local_res18 = param_3;
    local_res20 = param_4;
    uVar1 = _vsnprintf(_Dest,0x1ff,param_2,(va_list)&local_res18);
    if (((int)uVar1 < 0) || (0x1ff < uVar1)) {
      local_19 = 0;
      if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 4) != 0) {
        McTemplateK0s_EtwWriteTransfer
                  (_Dest,&Trace_Error,param_2,
                   "StringCchPrintfA() in DbgTraceFrmt() failed: Insufficient buffer");
      }
    }
    else {
      if (uVar1 == 0x1ff) {
        local_19 = 0;
      }
      if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 0x20) != 0) {
        McTemplateK0s_EtwWriteTransfer(_Dest,&Trace_Verbose,param_2,local_218);
      }
      DbgPrintEx(0x4d,2,local_218);
    }
  }
  return;
}



===== DbgTraceFrmtErr @ 1c0001294 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DbgTraceFrmtErr(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  char *_Dest;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_248 [48];
  char local_218 [511];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_248;
  _Dest = local_218;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = _vsnprintf(_Dest,0x1ff,param_1,(va_list)&local_res10);
  if (((int)uVar1 < 0) || (0x1ff < uVar1)) {
    local_19 = 0;
    if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer
                (_Dest,&Trace_Error,param_1,
                 "StringCchPrintfA() in DbgTraceFrmtErr() failed: Insufficient buffer");
    }
  }
  else {
    if (uVar1 == 0x1ff) {
      local_19 = 0;
    }
    if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 4) != 0) {
      McTemplateK0s_EtwWriteTransfer(_Dest,&Trace_Error,param_1,local_218);
    }
    DbgPrintEx(0x4d,2,local_218);
  }
  return;
}



===== McGenControlCallbackV2 @ 1c0001370 =====

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



===== McGenEventRegister_EtwRegister @ 1c0001480 =====

void McGenEventRegister_EtwRegister(void)

{
  if (UevAgentDriver_Context == 0) {
    EtwRegister(&UevAgentDriver,McGenControlCallbackV2,&UevAgentDriver_Context,
                &UevAgentDriver_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c00014c0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (UevAgentDriver_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    UevAgentDriver_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 1c00014f4 =====

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



===== McTemplateK0s_EtwWriteTransfer @ 1c0001538 =====

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



===== AllocateGenericBuffer @ 1c00015b4 =====

uint AllocateGenericBuffer
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 param_4)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  longlong *plVar4;
  
  pcVar2 = "UevFilter.AllocateGenericBuffer: Entry\n";
  plVar4 = param_3;
  DbgTrace(3,"UevFilter.AllocateGenericBuffer: Entry\n",param_3);
  if (param_3 == (longlong *)0x0) {
    DbgTraceErr("UevFilter.AllocateGenericBuffer: Invalid parameter specified\n",pcVar2,plVar4);
    uVar3 = 0xc000000d;
  }
  else {
    lVar1 = ExAllocatePool2(0x100,param_2,0x66766575);
    *param_3 = lVar1;
    uVar3 = ~-(uint)(lVar1 != 0) & 0xc000009a;
  }
  DbgTraceFrmt(3,"UevFilter.AllocateGenericBuffer: Exit, status = 0x%X\n",(ulonglong)uVar3,param_4);
  return uVar3;
}



===== FreeGenericBuffer @ 1c0001640 =====

void FreeGenericBuffer(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  
  pcVar1 = "UevFilter.FreeGenericBuffer: Entry\n";
  DbgTrace(3,"UevFilter.FreeGenericBuffer: Entry\n",param_3);
  if (param_1 == 0) {
    DbgTraceErr("UevFilter.FreeGenericBuffer: Invalid parameter specified\n",pcVar1,param_3);
  }
  else {
    ExFreePoolWithTag(param_1,0x66766575);
  }
  DbgTrace(3,"UevFilter.FreeGenericBuffer: Exit\n",param_3);
  return;
}



===== IsProcessListedUnderRegistryKey @ 1c00016a0 =====

byte IsProcessListedUnderRegistryKey
               (short *param_1,short *param_2,undefined8 *param_3,undefined8 param_4)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  char *pcVar7;
  byte bVar8;
  ushort uVar9;
  longlong local_res18 [2];
  ulonglong local_68;
  void *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  bVar8 = 0;
  local_68 = 0;
  local_60 = (void *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (ulonglong *)0x0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_res18[0] = 0;
  pcVar7 = "UevFilter.IsMonitoredProcess: Entry\n";
  DbgTrace(2,"UevFilter.IsMonitoredProcess: Entry\n",param_3);
  if (param_1 == (short *)0x0) {
    pcVar5 = "UevFilter.IsMonitoredProcess: Invalid parameter: pProcessName parameter is NULL.\n";
  }
  else {
    if (param_2 != (short *)0x0) {
      sVar1 = *param_1;
      sVar2 = *param_2;
      uVar6 = 3;
      DbgTrace(3,"UevFilter.AllocateGenericUnicodeString: Entry\n",param_3);
      uVar9 = sVar1 + sVar2 + 2;
      local_68 = (ulonglong)CONCAT42((int)(local_68 >> 0x20),uVar9) << 0x10;
      uVar3 = AllocateGenericBuffer(uVar6,(ulonglong)uVar9,(longlong *)&local_60,param_4);
      if (-1 < (int)uVar3) {
        memset(local_60,0,local_68 >> 0x10 & 0xffff);
      }
      param_3 = (undefined8 *)(ulonglong)uVar3;
      DbgTraceFrmt(3,"UevFilter.AllocateGenericUnicodeString: Exit, status = 0x%X\n",param_3,param_4
                  );
      if ((int)uVar3 < 0) {
        DbgTraceFrmtErr("UevFilter.IsMonitoredProcess: Failed to allocate buffer, status = 0x%X\n",
                        (ulonglong)uVar3,param_3,param_4);
      }
      else {
        RtlCopyUnicodeString(&local_68,param_2);
        RtlAppendUnicodeStringToString(&local_68,param_1);
        local_58 = CONCAT44(local_58._4_4_,0x30);
        uStack_50 = 0;
        uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
        local_48 = &local_68;
        local_38 = 0;
        uStack_30 = 0;
        param_3 = &local_58;
        iVar4 = ZwOpenKey(local_res18,0x20019);
        if (iVar4 < 0) {
          local_res18[0] = 0;
        }
        else {
          bVar8 = 1;
        }
      }
      goto LAB_1c0001817;
    }
    pcVar5 = "UevFilter.IsMonitoredProcess: Invalid parameter: pRegistryKey parameter is NULL.\n";
  }
  DbgTraceErr(pcVar5,pcVar7,param_3);
LAB_1c0001817:
  if (local_60 != (void *)0x0) {
    pcVar7 = "UevFilter.FreeGenericUnicodeString: Entry\n";
    DbgTrace(3,"UevFilter.FreeGenericUnicodeString: Entry\n",param_3);
    if (local_60 == (void *)0x0) {
      DbgTraceErr("UevFilter.FreeGenericUnicodeString: Invalid parameter specified\n",pcVar7,param_3
                 );
    }
    else {
      FreeGenericBuffer((longlong)local_60,pcVar7,param_3);
      local_60 = (void *)0x0;
    }
    DbgTrace(3,"UevFilter.FreeGenericUnicodeString: Exit\n",param_3);
  }
  if (local_res18[0] != 0) {
    ZwClose();
  }
  DbgTraceFrmt(2,"UevFilter.IsMonitoredProcess: Exit, retValue = 0x%X\n",(ulonglong)bVar8,param_4);
  return bVar8;
}



===== _guard_check_icall @ 1c00018c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00018d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00018fc =====

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



===== __cpu_features_init @ 1c0001970 =====

/* WARNING: Removing unreachable block (ram,0x0001c00019da) */
/* WARNING: Removing unreachable block (ram,0x0001c0001989) */
/* WARNING: Removing unreachable block (ram,0x0001c000197a) */

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



===== __security_check_cookie @ 1c0001a40 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001a80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001ab0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001ab0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001ae0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1c0001b40 =====

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



===== __memset_repmovs @ 1c0001c80 =====

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



===== __memset_query @ 1c0001d00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0001d80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0001ec0 =====

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



===== __memset_spec_plain @ 1c0001f40 =====

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



===== IsProcessListedUnderRegistryKey$fin$0 @ 1c000203d =====

void IsProcessListedUnderRegistryKey_fin_0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char *pcVar1;
  
  if (*(longlong *)(param_2 + 0x28) != 0) {
    pcVar1 = "UevFilter.FreeGenericUnicodeString: Entry\n";
    DbgTrace(3,"UevFilter.FreeGenericUnicodeString: Entry\n",param_3);
    if (*(longlong *)(param_2 + 0x28) == 0) {
      DbgTraceErr("UevFilter.FreeGenericUnicodeString: Invalid parameter specified\n",pcVar1,param_3
                 );
    }
    else {
      FreeGenericBuffer(*(longlong *)(param_2 + 0x28),pcVar1,param_3);
      *(undefined8 *)(param_2 + 0x28) = 0;
    }
    DbgTrace(3,"UevFilter.FreeGenericUnicodeString: Exit\n",param_3);
  }
  if (*(longlong *)(param_2 + 0xa0) != 0) {
    ZwClose();
  }
  return;
}



===== ComPortClose @ 1c000a008 =====

void ComPortClose(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 local_res8 [4];
  
  DbgTrace(2,"UevFilter.ComPortClose: Entry\n",param_3);
  if (pServerPort != 0) {
    FltCloseCommunicationPort();
    pServerPort = 0;
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&comPortResource,1);
  if (clientPortConnected != '\0') {
    clientPortRefCount = clientPortRefCount + -1;
    clientPortConnected = '\0';
    if (clientPortRefCount == 0) {
      DbgTrace(2,"UevFilter.ComPort: Closing client port\n",param_3);
      FltCloseClientPort(g_pFilter,&pClientPort);
      pClientPort = 0;
    }
  }
  ExReleaseResourceLite(&comPortResource);
  KeLeaveCriticalRegion();
  while (pClientPort != 0) {
    local_res8[0] = 0xfffffffffff0bdc0;
    param_3 = local_res8;
    KeDelayExecutionThread(1);
  }
  DbgTrace(2,"UevFilter.ComportClose: Exit\n",param_3);
  return;
}



===== ComPortCreate @ 1c000a110 =====

uint ComPortCreate(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  uint uVar1;
  char *pcVar2;
  longlong local_res8 [4];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 *local_30;
  undefined8 uStack_28;
  longlong local_20;
  ulonglong local_18;
  
  local_50 = 0;
  uStack_48 = 0;
  local_res8[0] = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = (undefined8 *)0x0;
  uStack_28 = 0;
  local_20 = 0;
  local_18 = local_18 & 0xffffffff00000000;
  DbgTrace(2,"UevFilter.ComPortCreate: Entry\n",param_3);
  uVar1 = FltBuildDefaultSecurityDescriptor(local_res8,0x1f0001);
  if ((int)uVar1 < 0) {
    pcVar2 = "UevFilter.ComPortCreate: Failed building security descriptor, error = 0x%X\n";
  }
  else {
    RtlInitUnicodeString(&local_50,L"\\UevConnectCreateNotifyPort");
    local_40 = CONCAT44(local_40._4_4_,0x30);
    uStack_38 = 0;
    uStack_28 = CONCAT44(uStack_28._4_4_,0x240);
    local_30 = &local_50;
    local_20 = local_res8[0];
    local_18 = 0;
    param_4 = 0;
    param_3 = &local_40;
    uVar1 = FltCreateCommunicationPort
                      (g_pFilter,&pServerPort,param_3,0,PortConnectHandler,PortDisconnectHandler,0,
                       10,uVar1);
    if (-1 < (int)uVar1) goto LAB_1c000a22a;
    pcVar2 = "UevFilter.ComPortCreate: Failed creating communication port, error = 0x%X\n";
  }
  DbgTraceFrmtErr(pcVar2,(ulonglong)uVar1,param_3,param_4);
LAB_1c000a22a:
  if (local_res8[0] != 0) {
    FltFreeSecurityDescriptor();
  }
  DbgTraceFrmt(2,"UevFilter.ComPortCreate: Exit, retStatus = 0x%X\n",(ulonglong)uVar1,param_4);
  return uVar1;
}



===== ComPortInit @ 1c000a26c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ComPortInit(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 **ppuVar3;
  uint local_res8 [2];
  char local_28 [16];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  DbgTrace(2,"UevFilter.ComPortInit: Entry\n",param_3);
  uVar1 = ExInitializeResourceLite(&comPortResource);
  if ((int)uVar1 < 0) {
    DbgTraceFrmtErr("UevFilter.ComPortInit: Failed resourse initialization, status = 0x%X\n",
                    (ulonglong)uVar1,param_3,param_4);
  }
  else {
    RtlInitUnicodeString
              (&local_18,L"\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\UEV\\Agent\\Configuration");
    RtlInitUnicodeString(local_28,L"FilterSendMsgTimeout");
    ppuVar3 = (undefined8 **)local_res8;
    uVar2 = ReadRegistryDword((longlong)&local_18,local_28,ppuVar3,param_4);
    if ((int)uVar2 < 0) {
      DbgTrace(2,"UevFilter.ComPortInit: Send message timeout not configured, using default value\n"
               ,ppuVar3);
      uVar2 = 10000;
    }
    else {
      uVar2 = local_res8[0];
    }
    if (uVar2 == 0) {
      DbgTrace(2,"UevFilter.ComPortInit: Setting send message to not timeout\n",ppuVar3);
      pSendMsgTimeout = (undefined *)0x0;
    }
    else {
      DbgTraceFrmt(2,"UevFilter.ComPortInit: Setting send message timeout to 0x%X ms\n",
                   (ulonglong)uVar2,param_4);
      _sendMsgTimeout = (ulonglong)(uVar2 + 500) * -10000;
      pSendMsgTimeout = &sendMsgTimeout;
    }
  }
  DbgTraceFrmt(2,"UevFilter.ComPortInit: Exit, retStatus = 0x%X\n",(ulonglong)uVar1,param_4);
  return uVar1;
}



===== ComPortSendMsg @ 1c000a3a8 =====

uint ComPortSendMsg(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  pcVar2 = "UevFilter.ComPortSendMsg: Entry\n";
  lVar3 = param_3;
  uVar4 = param_4;
  DbgTrace(2,"UevFilter.ComPortSendMsg: Entry\n",param_3);
  if ((param_1 == 0) || (param_3 == 0)) {
    DbgTraceErr("UevFilter.ComPortSendMsg: Invalid parameter specified\n",pcVar2,lVar3);
    uVar1 = 0xc000000d;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&comPortResource,1);
    if (clientPortConnected == '\0') {
      uVar1 = 0xc0000037;
    }
    else {
      clientPortRefCount = clientPortRefCount + 1;
      ExReleaseResourceLite(&comPortResource);
      KeLeaveCriticalRegion();
      uVar4 = 8;
      uVar1 = FltSendMessage(g_pFilter,&pClientPort,param_1,8,param_3,param_4,pSendMsgTimeout);
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&comPortResource,1);
      clientPortRefCount = clientPortRefCount + -1;
      if (clientPortRefCount == 0) {
        DbgTrace(2,"UevFilter.ComPort: Closing client port\n",param_1);
        FltCloseClientPort(g_pFilter,&pClientPort);
        pClientPort = 0;
      }
    }
    ExReleaseResourceLite(&comPortResource);
    KeLeaveCriticalRegion();
  }
  DbgTraceFrmt(2,"UevFilter.ComPortSendMsg: Exit, retStatus = 0x%X\n",(ulonglong)uVar1,uVar4);
  return uVar1;
}



===== IsClientSessionValid @ 1c000a53c =====

byte IsClientSessionValid(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  char *pcVar2;
  ulonglong uVar3;
  byte bVar4;
  uint *puVar5;
  longlong *plVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  longlong local_res18 [2];
  
  bVar4 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  DbgTrace(2,"UevFilter.IsClientSessionValid: Entry\n",param_3);
  plVar6 = local_res18;
  puVar5 = (uint *)0x200;
  uVar1 = ZwOpenProcessTokenEx(0xffffffffffffffff,0x80000000);
  if ((int)uVar1 < 0) {
    uVar3 = (ulonglong)uVar1;
    pcVar2 = "UevFilter.IsClientSessionValid: Failed to open process token, status = 0x%X\n";
  }
  else {
    plVar6 = (longlong *)0x4;
    puVar5 = local_res10;
    uVar1 = ZwQueryInformationToken(local_res18[0],0xc,puVar5,4,local_res8);
    if ((int)uVar1 < 0) {
      uVar3 = (ulonglong)uVar1;
      pcVar2 = "UevFilter.IsClientSessionValid: Failed to get session id, status = 0x%X\n";
    }
    else {
      uVar3 = (ulonglong)local_res8[0];
      if (local_res8[0] == 4) {
        uVar3 = (ulonglong)local_res10[0];
        if (local_res10[0] == 0) {
          bVar4 = 1;
          goto LAB_1c000a5f9;
        }
        pcVar2 = "UevFilter.IsClientSessionValid: Unexpected session id, id = 0x%X\n";
      }
      else {
        pcVar2 = "UevFilter.IsClientSessionValid: Unexpected returned length, length = 0x%X\n";
      }
    }
  }
  DbgTraceFrmtErr(pcVar2,uVar3,puVar5,plVar6);
LAB_1c000a5f9:
  if (local_res18[0] != 0) {
    ZwClose();
  }
  DbgTraceFrmt(2,"UevFilter.IsClientSessionValid: Exit, retValue = 0x%X\n",(ulonglong)bVar4,plVar6);
  return bVar4;
}



===== PortConnectHandler @ 1c000a640 =====

uint PortConnectHandler(longlong param_1,undefined8 param_2,int *param_3,undefined8 param_4,
                       longlong *param_5)

{
  byte bVar1;
  undefined *puVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  
  iVar8 = (int)param_4;
  uVar6 = 0xc0000022;
  pcVar4 = "UevFilter.PortConnectHandler: Entry\n";
  piVar7 = param_3;
  DbgTrace(2,"UevFilter.PortConnectHandler: Entry\n",param_3);
  if (((param_3 == (int *)0x0) || (iVar8 != 4)) || (param_5 == (longlong *)0x0)) {
    pcVar3 = "UevFilter.PortConnectHandler: Invalid parameter\n";
  }
  else {
    if (*param_3 == 1) {
      KeEnterCriticalRegion();
      uVar5 = CONCAT71((int7)((ulonglong)pcVar4 >> 8),1);
      puVar2 = &comPortResource;
      ExAcquireResourceExclusiveLite();
      if ((pServerPort != 0) && (pClientPort == 0)) {
        bVar1 = IsClientSessionValid(puVar2,uVar5,piVar7);
        if (bVar1 != 0) {
          clientPortRefCount = 1;
          clientPortConnected = 1;
          pClientPort = param_1;
          *param_5 = param_1;
          uVar6 = 0;
        }
      }
      ExReleaseResourceLite(&comPortResource);
      KeLeaveCriticalRegion();
      goto LAB_1c000a730;
    }
    pcVar3 = "UevFilter.PortConnectHandler: Invalid connection type\n";
  }
  DbgTraceErr(pcVar3,pcVar4,piVar7);
  uVar6 = 0xc000000d;
LAB_1c000a730:
  DbgTraceFrmt(2,"UevFilter.PortConnectHandler: Exit, retStatus = 0%X\n",(ulonglong)uVar6,param_4);
  return uVar6;
}



===== PortDisconnectHandler @ 1c000a770 =====

void PortDisconnectHandler(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  DbgTrace(2,"UevFilter.PortDisconnectHandler: Entry\n",param_3);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&comPortResource,1);
  if ((clientPortConnected != '\0') && (pClientPort == param_1)) {
    clientPortConnected = '\0';
    clientPortRefCount = clientPortRefCount + -1;
    if (clientPortRefCount == 0) {
      DbgTrace(2,"UevFilter.ComPort: Closing client port\n",param_3);
      FltCloseClientPort(g_pFilter,&pClientPort);
      pClientPort = 0;
    }
  }
  ExReleaseResourceLite(&comPortResource);
  KeLeaveCriticalRegion();
  DbgTrace(2,"UevFilter.PortDisconnectHandler: Exit\n",param_3);
  return;
}



===== AddFilterHashTableEntry @ 1c000a848 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint AddFilterHashTableEntry
               (undefined8 *param_1,undefined8 param_2,undefined8 **param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 **ppuVar6;
  undefined8 *local_res8;
  
  puVar1 = DAT_1c0007128;
  uVar5 = 2;
  ppuVar6 = param_3;
  local_res8 = param_1;
  DbgTrace(2,"UevFilter.AddHandleHashTableEntry: Entry\n",param_3);
  if (puVar1 == (undefined8 *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    local_res8 = (undefined8 *)0x0;
    ppuVar6 = &local_res8;
    uVar3 = AllocateGenericBuffer(uVar5,0x18,(longlong *)ppuVar6,param_4);
    puVar2 = local_res8;
    if (-1 < (int)uVar3) {
      local_res8[1] = param_2;
      local_res8[2] = param_3;
      uVar4 = (*(code *)*puVar1)(param_2);
      *puVar2 = puVar1[(ulonglong)uVar4 + 3];
      puVar1[(ulonglong)uVar4 + 3] = puVar2;
    }
  }
  DbgTrace(2,"UevFilter.AddHandleHashTableEntry: Exit\n",ppuVar6);
  return uVar3;
}



===== AllocateFilterHashTable @ 1c000a8f8 =====

uint AllocateFilterHashTable
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar2 = 2;
  DbgTrace(2,"UevFilter.AllocateFilterHashTable: Entry\n",param_3);
  puVar3 = &DAT_1c0007128;
  uVar1 = AllocateGenericBuffer(uVar2,0x5ea0,(longlong *)&DAT_1c0007128,param_4);
  if (-1 < (int)uVar1) {
    puVar3 = (undefined8 *)0x5ea0;
    memset(DAT_1c0007128,0,0x5ea0);
    *(undefined4 *)(DAT_1c0007128 + 2) = 0x3f1;
    *DAT_1c0007128 = GenerateSessionTableHash;
    DAT_1c0007128[1] = FreeHashTableEntry;
  }
  DbgTrace(2,"UevFilter.AllocateFilterHashTable: Exit\n",puVar3);
  return uVar1;
}



===== FindKeyInFilterHashTable @ 1c000a98c =====

char FindKeyInFilterHashTable(longlong param_1,longlong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  char cVar2;
  longlong *plVar3;
  longlong local_res8;
  
  puVar1 = DAT_1c0007128;
  cVar2 = '\0';
  plVar3 = param_3;
  local_res8 = param_1;
  DbgTrace(2,"UevFilter.FindKeyInFilterHashTable: Entry\n",param_3);
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  if (puVar1 != (undefined8 *)0x0) {
    local_res8 = 0;
    plVar3 = &local_res8;
    cVar2 = FindTableEntryInFilterHashTable(puVar1,param_2,plVar3,(undefined8 *)0x0);
    if (((cVar2 != '\0') && (local_res8 != 0)) && (param_3 != (longlong *)0x0)) {
      *param_3 = *(longlong *)(local_res8 + 0x10);
    }
  }
  DbgTrace(2,"UevFilter.FindKeyInFilterHashTable: Exit\n",plVar3);
  return cVar2;
}



===== FindTableEntryInFilterHashTable @ 1c000aa3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
FindTableEntryInFilterHashTable
          (undefined8 *param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  uVar4 = 0;
  puVar6 = param_3;
  DbgTrace(2,"UevFilter.FindTableEntryInFilterHashTable: Entry\n",param_3);
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  uVar2 = (*(code *)*param_1)(param_2);
  puVar1 = (undefined8 *)param_1[(ulonglong)uVar2 + 3];
  puVar5 = (undefined8 *)0x0;
  do {
    puVar3 = puVar1;
    if (puVar3 == (undefined8 *)0x0) {
LAB_1c000aabc:
      DbgTrace(2,"UevFilter.FindTableEntryInFilterHashTable: Exit\n",puVar6);
      return uVar4;
    }
    if (param_2 == puVar3[1]) {
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar3;
      }
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = puVar5;
      }
      uVar4 = 1;
      goto LAB_1c000aabc;
    }
    puVar1 = (undefined8 *)*puVar3;
    puVar5 = puVar3;
  } while( true );
}



===== FreeFilterHashTable @ 1c000aaf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeFilterHashTable(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  
  lVar2 = DAT_1c0007128;
  pcVar3 = "UevFilter.FreeHandleHashTable: Entry\n";
  DbgTrace(2,"UevFilter.FreeHandleHashTable: Entry\n",param_3);
  if (lVar2 != 0) {
    uVar5 = 0;
    if (*(int *)(lVar2 + 0x10) != 0) {
      do {
        puVar6 = *(undefined8 **)(lVar2 + 0x18 + uVar5 * 8);
        while (puVar6 != (undefined8 *)0x0) {
          puVar1 = (undefined8 *)*puVar6;
          pcVar3 = (char *)puVar6[2];
          if (pcVar3 != (char *)0x0) {
            (**(code **)(lVar2 + 8))(lVar2);
          }
          FreeGenericBuffer((longlong)puVar6,pcVar3,param_3);
          puVar6 = puVar1;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *(uint *)(lVar2 + 0x10));
    }
    FreeGenericBuffer(lVar2,pcVar3,param_3);
  }
  DbgTrace(2,"UevFilter.FreeHandleHashTable: Exit\n",param_3);
  return;
}



===== RemoveFilterHashTableEntry @ 1c000ab94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 RemoveFilterHashTableEntry(undefined8 *param_1,longlong param_2,undefined8 **param_3)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined8 **ppuVar5;
  undefined8 *local_res8;
  undefined8 *local_res18;
  
  puVar1 = DAT_1c0007128;
  uVar4 = 0;
  ppuVar5 = param_3;
  local_res8 = param_1;
  DbgTrace(2,"UevFilter.RemoveHandleFromHashTable: Entry\n",param_3);
  if (param_3 != (undefined8 **)0x0) {
    *param_3 = (undefined8 *)0x0;
  }
  if (puVar1 != (undefined8 *)0x0) {
    local_res8 = (undefined8 *)0x0;
    local_res18 = (undefined8 *)0x0;
    uVar3 = (*(code *)*puVar1)(param_2);
    ppuVar5 = &local_res8;
    cVar2 = FindTableEntryInFilterHashTable(puVar1,param_2,ppuVar5,&local_res18);
    if ((cVar2 != '\0') && (local_res8 != (undefined8 *)0x0)) {
      if (local_res18 == (undefined8 *)0x0) {
        puVar1[(ulonglong)uVar3 + 3] = 0;
      }
      else {
        *local_res18 = *local_res8;
      }
      if (param_3 != (undefined8 **)0x0) {
        *param_3 = (undefined8 *)local_res8[2];
      }
      FreeGenericBuffer((longlong)local_res8,local_res18,ppuVar5);
      uVar4 = 1;
    }
  }
  DbgTrace(2,"UevFilter.RemoveHandleFromHashTable: Exit\n",ppuVar5);
  return uVar4;
}



===== HookProcessNotify @ 1c000ac68 =====

uint HookProcessNotify(char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  
  DbgTrace(2,"UevFilter.HookProcessNotify: Entry\n",param_3);
  uVar1 = PsSetCreateProcessNotifyRoutineEx(ProcessNotification,param_1 == '\0');
  DbgTraceFrmt(2,"UevFilter.HookProcessNotify: Exit, retStatus = 0x%X\n",(ulonglong)uVar1,param_4);
  return uVar1;
}



===== ProcessCreateNotification @ 1c000acc0 =====

void ProcessCreateNotification(undefined4 param_1,longlong param_2,ushort *param_3,short *param_4)

{
  byte bVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  char *pcVar5;
  undefined4 local_res10 [2];
  ushort local_res18 [4];
  undefined4 local_res20;
  undefined4 local_res24;
  ushort local_28 [4];
  undefined8 uStack_20;
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uStack_20 = 0;
  DbgTrace(2,"UevFilter.ProcessCreateNotification: Entry\n",param_3);
  if (param_2 != 0) {
    puVar3 = *(ushort **)(param_2 + 0x30);
    puVar4 = local_28;
    uVar2 = GetFileNameFromPath(puVar3,puVar4,param_3,param_4);
    if ((int)uVar2 < 0) {
      DbgTraceFrmtErr("UevFilter.ProcessCreateNotification: Failed to obtain the process name, status = 0x%X\n"
                      ,(ulonglong)uVar2,param_3,param_4);
    }
    else {
      if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 0x10) != 0) {
        param_4 = (short *)(ulonglong)(local_28[0] >> 1);
        McTemplateK0hzr0q_EtwWriteTransfer
                  (puVar3,puVar4,param_3,local_28[0] >> 1,uStack_20,(char)param_1);
      }
      param_3 = local_28;
      DbgTraceFrmt(2,"UevFilter.ProcessCreateNotification: Process name = %wZ\n",param_3,param_4);
      bVar1 = IsProcessListedUnderRegistryKey
                        ((short *)local_28,(short *)&DAT_1c0007058,(undefined8 *)param_3,param_4);
      if (bVar1 == 0) {
        bVar1 = IsProcessListedUnderRegistryKey
                          ((short *)local_28,(short *)&DAT_1c0007048,(undefined8 *)param_3,param_4);
        if (bVar1 == 0) goto LAB_1c000ade1;
      }
      DbgTrace(2,"UevFilter.IsRestrictedProcess: Entry\n",param_3);
      bVar1 = RtlEqualUnicodeString(local_28,&DAT_1c0007068,1);
      pcVar5 = "UevFilter.IsRestrictedProcess: Exit, retValue = 0x%X\n";
      param_3 = (ushort *)(ulonglong)bVar1;
      DbgTraceFrmt(2,"UevFilter.IsRestrictedProcess: Exit, retValue = 0x%X\n",param_3,param_4);
      if (bVar1 == 0) {
        local_res18[0] = 0;
        local_res18[1] = 0;
        param_3 = local_res18;
        local_res10[0] = 4;
        local_res20 = 1;
        local_res24 = param_1;
        ComPortSendMsg((longlong)&local_res20,pcVar5,(longlong)param_3,local_res10);
      }
    }
  }
LAB_1c000ade1:
  DbgTrace(2,"UevFilter.ProcessCreateDestroyNotification: Exit\n",param_3);
  return;
}



===== ProcessNotification @ 1c000ae10 =====

void ProcessNotification(undefined8 param_1,longlong param_2,ushort *param_3,short *param_4)

{
  ushort *puVar1;
  
  puVar1 = param_3;
  DbgTrace(2,"UevFilter.ProcessNotification: Entry\n",param_3);
  if (param_3 != (ushort *)0x0) {
    ProcessCreateNotification((int)param_2,(longlong)param_3,puVar1,param_4);
    SendProcessEventMessage(param_2,param_3,puVar1,param_4);
  }
  DbgTrace(2,"UevFilter.ProcessNotification: Exit\n",puVar1);
  return;
}



===== FreeHashTableEntry @ 1c000ae70 =====

void FreeHashTableEntry(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char *pcVar1;
  
  pcVar1 = "UevFilter.FreeSessionTableEntry: Entry\n";
  DbgTrace(2,"UevFilter.FreeSessionTableEntry: Entry\n",param_3);
  if (param_2 != 0) {
    FreeGenericBuffer(param_2,pcVar1,param_3);
  }
  DbgTrace(2,"UevFilter.FreeSessionTableEntry: Exit\n",param_3);
  return;
}



===== GenerateSessionTableHash @ 1c000aec0 =====

uint GenerateSessionTableHash(uint param_1)

{
  return param_1 % 0x3f1;
}



===== GetSessionIdFromProcessId @ 1c000aee4 =====

uint GetSessionIdFromProcessId(longlong param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  longlong *plVar4;
  undefined4 local_res8 [4];
  longlong local_res18;
  longlong local_res20;
  longlong local_58 [2];
  uint local_48 [12];
  
  local_res18 = 0;
  local_res20 = 0;
  local_48[7] = 0;
  local_48[1] = 0;
  DbgTrace(2,"UevFilter.GetSessionIdFromProcessId: Entry\n",param_3);
  local_48[2] = 0;
  local_48[3] = 0;
  plVar4 = local_58;
  local_48[4] = 0;
  local_48[5] = 0;
  puVar3 = local_48;
  local_58[1] = 0;
  local_48[0] = 0x30;
  local_48[6] = 0x200;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_58[0] = param_1;
  uVar1 = ZwOpenProcess(&local_res18,0x80000000);
  if ((int)uVar1 < 0) {
    pcVar2 = "UevFilter.GetSessionIdFromProcessId: Failed to open process handle. Error = 0x%0X.\n";
  }
  else {
    plVar4 = &local_res20;
    puVar3 = (uint *)0x200;
    uVar1 = ZwOpenProcessTokenEx(local_res18,0x80000000);
    if ((int)uVar1 < 0) {
      pcVar2 = "UevFilter.GetSessionIdFromProcessId: Failed to open process token. Error = 0x%0X.\n"
      ;
    }
    else {
      local_res8[0] = 0;
      plVar4 = (longlong *)0x4;
      puVar3 = param_2;
      uVar1 = ZwQueryInformationToken(local_res20,0xc,param_2,4,local_res8);
      if (-1 < (int)uVar1) {
        DbgTraceFrmt(2,"UevFilter.GetSessionIdFromProcessId: Session ID = %d.\n",(ulonglong)*param_2
                     ,plVar4);
        goto LAB_1c000aff0;
      }
      pcVar2 = "UevFilter.GetSessionIdFromProcessId: Failed to get session ID. Error = 0x%0X.\n";
    }
  }
  DbgTraceFrmtErr(pcVar2,(ulonglong)uVar1,puVar3,plVar4);
LAB_1c000aff0:
  if (local_res18 != 0) {
    ZwClose();
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  DbgTraceFrmt(2,"UevFilter.GetSessionIdFromProcessId: Exit. Error = 0x%0X.\n",(ulonglong)uVar1,
               plVar4);
  return uVar1;
}



===== IsSupportedVersion @ 1c000b040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IsSupportedVersion(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                            undefined8 param_4)

{
  char extraout_var;
  undefined8 uVar1;
  char *pcVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  DbgTrace(2,"UevFilter.IsSupportedVersion: Entry\n",param_3);
  memset(local_128,0,0x10c);
  local_138 = 0x114;
  local_134 = 6;
  local_130 = 2;
  local_12c = 0x23f0;
  uVar1 = VerSetConditionMask(0,2,3);
  uVar1 = VerSetConditionMask(uVar1,1,3);
  uVar1 = VerSetConditionMask(uVar1,4,3);
  RtlVerifyVersionInfo(&local_138,7,uVar1);
  pcVar2 = "true";
  if ((char)-(extraout_var >> 7) == '\x01') {
    pcVar2 = "false";
  }
  uVar1 = DbgTraceFrmt(2,"UevFilter.IsSupportedVersion: Exit, supported = %s.\n",pcVar2,param_4);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),-(extraout_var >> 7)) ^ 1;
}



===== PortConnectHandler @ 1c000b150 =====

uint PortConnectHandler(undefined8 **param_1,undefined8 param_2,undefined8 param_3,
                       undefined8 param_4,ulonglong *param_5)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint local_res8 [2];
  
  pcVar5 = "UevFilter.PortConnectHandler: Entry\n";
  DbgTrace(2,"UevFilter.PortConnectHandler: Entry\n",param_3);
  if ((param_1 == (undefined8 **)0x0) || (param_5 == (ulonglong *)0x0)) {
    DbgTraceErr("UevFilter.PortConnectHandler: Invalid parameter.\n",pcVar5,param_3);
    uVar2 = 0xc000000d;
  }
  else {
    local_res8[0] = 0;
    lVar3 = PsGetCurrentProcessId();
    uVar2 = GetSessionIdFromProcessId(lVar3,local_res8,param_3);
    if ((int)uVar2 < 0) {
      DbgTraceFrmtErr("UevFilter.PortConnectHandler: Failed to get session ID. Error = 0x%0X.\n",
                      (ulonglong)uVar2,param_3,param_4);
    }
    if (-1 < (int)uVar2) {
      puVar4 = (undefined8 *)&DAT_1c0007150;
      KeAcquireGuardedMutex();
      uVar2 = local_res8[0];
      if (DAT_1c0007128 == 0) {
        uVar2 = 0xc0000037;
      }
      else {
        uVar6 = (ulonglong)local_res8[0];
        uVar7 = 0;
        cVar1 = FindKeyInFilterHashTable((longlong)puVar4,uVar6,(longlong *)0x0);
        if (cVar1 == '\0') {
          uVar2 = AddFilterHashTableEntry(puVar4,(ulonglong)uVar2,param_1,param_4);
          if (-1 < (int)uVar2) {
            *param_5 = uVar6;
          }
        }
        else {
          DbgTraceFrmtErr("UevFilter.PortConnectHandler: Session ID %d already exists in table.\n",
                          (ulonglong)local_res8[0],uVar7,param_4);
          uVar2 = 0xc0000048;
        }
      }
      KeReleaseGuardedMutex(&DAT_1c0007150);
    }
  }
  DbgTraceFrmt(2,"UevFilter.PortConnectHandler: Exit. Error = 0%0X\n",(ulonglong)uVar2,param_4);
  return uVar2;
}



===== PortDisconnectHandler @ 1c000b290 =====

void PortDisconnectHandler(longlong param_1,undefined8 param_2,undefined8 **param_3)

{
  char cVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined8 *local_res8;
  
  DbgTrace(2,"UevFilter.PortDisconnectHandler: Entry\n",param_3);
  bVar3 = false;
  if (param_1 != 0) {
    local_res8 = (undefined8 *)0x0;
    puVar2 = (undefined8 *)&DAT_1c0007150;
    KeAcquireGuardedMutex();
    if (DAT_1c0007128 != 0) {
      param_3 = &local_res8;
      cVar1 = RemoveFilterHashTableEntry(puVar2,param_1,param_3);
      if (cVar1 != '\0') {
        bVar3 = local_res8 != (undefined8 *)0x0;
      }
    }
    KeReleaseGuardedMutex(&DAT_1c0007150);
    if (bVar3) {
      FltCloseClientPort(g_pFilter,&local_res8);
    }
  }
  DbgTrace(2,"UevFilter.PortDisconnectHandler: Exit\n",param_3);
  return;
}



===== ProcessEventUninitialize @ 1c000b354 =====

void ProcessEventUninitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  
  DbgTrace(2,"UevFilter.ProcessEventUninitialize: Entry\n",param_3);
  if (DAT_1c0007138 == '\x01') {
    KeAcquireGuardedMutex(&DAT_1c0007150);
    DbgTrace(2,"UevFilter.CloseProcessEventCompletionPort: Entry\n",param_3);
    if (DAT_1c0007130 != 0) {
      FltCloseCommunicationPort();
      DAT_1c0007130 = 0;
    }
    pcVar2 = "UevFilter.CloseProcessEventCompletionPort: Exit\n";
    uVar1 = 2;
    DbgTrace(2,"UevFilter.CloseProcessEventCompletionPort: Exit\n",param_3);
    if (DAT_1c0007128 != 0) {
      FreeFilterHashTable(uVar1,pcVar2,param_3);
      DAT_1c0007128 = 0;
    }
    KeReleaseGuardedMutex(&DAT_1c0007150);
    DAT_1c0007138 = '\0';
  }
  DbgTrace(2,"UevFilter.ProcessEventUninitialize: Exit\n",param_3);
  return;
}



===== SendProcessEventMessage @ 1c000b41c =====

uint SendProcessEventMessage
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20;
  undefined4 uStackX_24;
  longlong local_20 [3];
  
  local_res10[0] = 0;
  if (DAT_1c0007138 == '\0') {
    uVar2 = 0;
  }
  else {
    DbgTrace(2,"UevFilter.SendProcessEventMessage: Entry\n",param_3);
    uVar2 = GetSessionIdFromProcessId(param_1,local_res10,param_3);
    if ((int)uVar2 < 0) {
      DbgTraceFrmtErr("UevFilter.SendProcessEventMessage: Failed to get session ID. Error = 0x%0X.\n"
                      ,(ulonglong)uVar2,param_3,param_4);
    }
    if ((-1 < (int)uVar2) && (local_res10[0] != 0)) {
      puVar3 = &DAT_1c0007150;
      KeAcquireGuardedMutex();
      if (DAT_1c0007128 == 0) {
        uVar2 = 0xc0000037;
      }
      else {
        local_20[0] = 0;
        cVar1 = FindKeyInFilterHashTable((longlong)puVar3,(ulonglong)local_res10[0],local_20);
        if ((cVar1 != '\0') && (local_20[0] != 0)) {
          local_res18[0] = 0;
          local_20[1] = 0xfffffffffff0bdc0;
          _local_res20 = CONCAT44((int)param_1,2);
          param_4 = 8;
          puVar4 = &local_res20;
          uVar2 = FltSendMessage(g_pFilter,local_20,puVar4,8,0,local_res18,local_20 + 1);
          if ((int)uVar2 < 0) {
            DbgTraceFrmtErr("UevFilter.SendProcessEventMessage: Failed to send message. Error = 0x%0X.\n"
                            ,(ulonglong)uVar2,puVar4,param_4);
          }
          else {
            DbgTraceFrmt(1,"UevFilter.SendProcessEventMessage: Process %d has started.\n",param_1,
                         param_4);
          }
        }
      }
      KeReleaseGuardedMutex(&DAT_1c0007150);
    }
    DbgTraceFrmt(2,"UevFilter.SendProcessEventMessage: Exit, retStatus = 0x%0X.\n",(ulonglong)uVar2,
                 param_4);
  }
  return uVar2;
}



===== DriverUnload @ 1c000b5b0 =====

undefined8
DriverUnload(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  
  pcVar2 = "UevFilter.DriverUnload: Entry\n";
  uVar1 = 1;
  DbgTrace(1,"UevFilter.DriverUnload: Entry\n",param_3);
  if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 0x10) != 0) {
    pcVar2 = "e";
    McTemplateK0_EtwWriteTransfer(uVar1,&DriverUnloaded,param_3);
  }
  UnInitializeDriver(uVar1,pcVar2,param_3,param_4);
  DbgTrace(1,"UevFilter.DriverUnload: Exit\n",param_3);
  McGenEventUnregister_EtwUnregister();
  return 0;
}



===== UnInitializeDriver @ 1c000b604 =====

void UnInitializeDriver(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4
                       )

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  pcVar3 = "UevFilter.UnInitializeDriver: Entry\n";
  uVar2 = 1;
  DbgTrace(1,"UevFilter.UnInitializeDriver: Entry\n",param_3);
  if (processEventPortCreated != '\0') {
    ProcessEventUninitialize(uVar2,pcVar3,param_3);
    processEventPortCreated = '\0';
  }
  if (processNotifyHooked != '\0') {
    DbgTrace(2,"UevFilter.HookProcessNotify: Entry\n",param_3);
    uVar1 = PsSetCreateProcessNotifyRoutineEx(ProcessNotification,1);
    pcVar3 = "UevFilter.HookProcessNotify: Exit, retStatus = 0x%X\n";
    uVar2 = 2;
    param_3 = (undefined8 *)(ulonglong)uVar1;
    DbgTraceFrmt(2,"UevFilter.HookProcessNotify: Exit, retStatus = 0x%X\n",param_3,param_4);
    processNotifyHooked = '\0';
  }
  if (portCreated != '\0') {
    ComPortClose(uVar2,pcVar3,param_3);
    portCreated = '\0';
  }
  if (filterRegistered != '\0') {
    FltUnregisterFilter(g_pFilter);
    filterRegistered = '\0';
  }
  if (comPortInitialized != '\0') {
    DbgTrace(2,"UevFilter.ComPortUnInit: Entry\n",param_3);
    uVar1 = ExDeleteResourceLite(&comPortResource);
    if ((int)uVar1 < 0) {
      DbgTraceFrmtErr("UevFilter.ComPortUnInit: Failed resourse deletion, status = 0x%X\n",
                      (ulonglong)uVar1,param_3,param_4);
    }
    DbgTrace(2,"UevFilter.ComPortUnInit: Exit\n",param_3);
    comPortInitialized = '\0';
  }
  DbgTrace(1,"UevFilter.UnInitializeDriver: Exit\n",param_3);
  return;
}



===== GetDebugLevel @ 1c000b724 =====

void GetDebugLevel(void)

{
  uint uVar1;
  longlong *in_R9;
  
  uVar1 = ReadRegistryDword(0x1c0004080," ",(undefined8 **)&g_DebugLevel,in_R9);
  if ((int)uVar1 < 0) {
    g_DebugLevel = 1;
  }
  return;
}



===== GetFileNameFromPath @ 1c000b75c =====

uint GetFileNameFromPath(ushort *param_1,ushort *param_2,undefined8 param_3,short *param_4)

{
  int iVar1;
  ushort uVar2;
  char *pcVar3;
  uint uVar4;
  longlong lVar5;
  
  pcVar3 = "UevFilter.GetFileNameFromPath: Entry\n";
  uVar4 = 0xc0000001;
  DbgTrace(2,"UevFilter.GetFileNameFromPath: Entry\n",param_3);
  if ((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) {
    uVar2 = *param_1;
    pcVar3 = (char *)(ulonglong)uVar2;
    if (uVar2 != 0) {
      iVar1 = (uVar2 >> 1) - 1;
      if (iVar1 < 0) {
LAB_1c000b806:
        param_2[1] = uVar2;
        *param_2 = uVar2;
        *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + 4);
      }
      else {
        lVar5 = (ulonglong)(uVar2 >> 1) - 1;
        param_4 = (short *)(*(longlong *)(param_1 + 4) + lVar5 * 2);
        do {
          if (*param_4 == 0x5c) break;
          iVar1 = iVar1 + -1;
          param_4 = param_4 + -1;
          lVar5 = lVar5 + -1;
        } while (-1 < lVar5);
        if (iVar1 < 0) goto LAB_1c000b806;
        if (uVar2 < 3) {
          DbgTraceErr("UevFilter.GetFileNameFromPath: Invalid file name.\n",pcVar3,lVar5);
          goto LAB_1c000b82b;
        }
        lVar5 = (longlong)(iVar1 + 1) * 2;
        uVar2 = uVar2 - (short)lVar5;
        param_2[1] = uVar2;
        *param_2 = uVar2;
        *(longlong *)(param_2 + 4) = lVar5 + *(longlong *)(param_1 + 4);
      }
      uVar4 = 0;
      goto LAB_1c000b82b;
    }
  }
  DbgTraceErr("UevFilter.GetFileNameFromPath: Invalid parameter specified\n",pcVar3,param_3);
  uVar4 = 0xc000000d;
LAB_1c000b82b:
  DbgTraceFrmt(2,"UevFilter.GetProcessNameFromPath: Exit, retStatus = 0x%X\n",(ulonglong)uVar4,
               param_4);
  return uVar4;
}



===== ReadRegistryDword @ 1c000b85c =====

uint ReadRegistryDword(longlong param_1,char *param_2,undefined8 **param_3,longlong *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined8 **ppuVar5;
  longlong local_res8;
  
  local_res8 = 0;
  pcVar4 = "UevFilter.ReadRegistryDword: Entry\n";
  ppuVar5 = param_3;
  DbgTrace(2,"UevFilter.ReadRegistryDword: Entry\n",param_3);
  if (((param_1 == 0) || (param_2 == (char *)0x0)) || (param_3 == (undefined8 **)0x0)) {
    DbgTraceErr("UevFilter.ReadRegistryDword: Invalid parameter specified\n",pcVar4,ppuVar5);
    uVar3 = 0xc000000d;
  }
  else {
    *(undefined4 *)param_3 = 0;
    param_4 = &local_res8;
    uVar3 = ReadRegistryValue(param_1,param_2,ppuVar5,param_4);
    if (-1 < (int)uVar3) {
      uVar1 = *(uint *)(local_res8 + 8);
      uVar2 = *(uint *)((ulonglong)uVar1 + local_res8);
      *(uint *)param_3 = uVar2;
      FreeGenericBuffer(local_res8,(ulonglong)uVar1,(ulonglong)uVar2);
    }
  }
  DbgTraceFrmt(2,"UevFilter.ReadRegistryDword: Exit, status = 0x%X\n",(ulonglong)uVar3,param_4);
  return uVar3;
}



===== ReadRegistryValue @ 1c000b908 =====

uint ReadRegistryValue(longlong param_1,char *param_2,undefined8 **param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  undefined8 *puVar5;
  longlong local_60;
  undefined8 *local_58;
  undefined8 *local_50;
  undefined8 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  
  local_60 = 0;
  local_50 = (undefined8 *)0x0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = uStack_28 & 0xffffffff00000000;
  local_58 = (undefined8 *)0x0;
  pcVar4 = "UevFilter.ReadRegistryValue: Entry\n";
  puVar5 = param_4;
  DbgTrace(2,"UevFilter.ReadRegistryValue: Entry\n",param_3);
  if (((param_1 == 0) || (param_2 == (char *)0x0)) || (param_4 == (undefined8 *)0x0)) {
    DbgTraceErr("UevFilter.ReadRegistryValue: Invalid parameter specified\n",pcVar4,param_3);
    uVar2 = 0xc000000d;
  }
  else {
    *param_4 = 0;
    local_50 = (undefined8 *)CONCAT44(local_50._4_4_,0x30);
    uStack_48 = 0;
    uStack_38 = CONCAT44(uStack_38._4_4_,0x240);
    local_30 = 0;
    uStack_28 = 0;
    param_3 = &local_50;
    pcVar4 = (char *)0x20019;
    local_40 = param_1;
    uVar2 = ZwOpenKey(&local_60);
    if (-1 < (int)uVar2) {
      puVar5 = (undefined8 *)0x0;
      param_3 = (undefined8 **)0x1;
      lVar3 = local_60;
      pcVar4 = param_2;
      uVar2 = ZwQueryValueKey();
      if ((uVar2 == 0xc0000023) || (uVar2 == 0x80000005)) {
        pcVar4 = (char *)0x0;
        param_3 = &local_58;
        uVar2 = AllocateGenericBuffer(lVar3,0,(longlong *)param_3,puVar5);
        puVar1 = local_58;
        if (-1 < (int)uVar2) {
          param_3 = (undefined8 **)0x1;
          puVar5 = local_58;
          uVar2 = ZwQueryValueKey(local_60);
          pcVar4 = param_2;
          if ((-1 < (int)uVar2) && (*(int *)((longlong)puVar1 + 4) != 4)) {
            uVar2 = 0xc0000001;
          }
        }
      }
    }
  }
  if (local_60 != 0) {
    ZwClose();
  }
  if (local_58 != (undefined8 *)0x0) {
    if ((int)uVar2 < 0) {
      FreeGenericBuffer((longlong)local_58,pcVar4,param_3);
    }
    else {
      *param_4 = local_58;
    }
  }
  DbgTraceFrmt(2,"UevFilter.ReadRegistryValue: Exit, status = 0x%X\n",(ulonglong)uVar2,puVar5);
  return uVar2;
}



===== ComPortCreate$fin$0 @ 1c000bb00 =====

void ComPortCreate_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0xa0) != 0) {
    FltFreeSecurityDescriptor();
  }
  return;
}



===== ComPortSendMsg$fin$0 @ 1c000bb2f =====

void ComPortSendMsg_fin_0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&comPortResource,1);
  clientPortRefCount = clientPortRefCount + -1;
  if (clientPortRefCount == 0) {
    DbgTrace(2,"UevFilter.ComPort: Closing client port\n",param_3);
    FltCloseClientPort(g_pFilter,&pClientPort);
    pClientPort = 0;
  }
  return;
}



===== ComPortSendMsg$fin$1 @ 1c000bb9c =====

void ComPortSendMsg_fin_1(void)

{
  ExReleaseResourceLite(&comPortResource);
  KeLeaveCriticalRegion();
  return;
}



===== IsClientSessionValid$fin$0 @ 1c000bbd2 =====

void IsClientSessionValid_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ZwClose();
  }
  return;
}



===== PortConnectHandler$fin$0 @ 1c000bbfe =====

void PortConnectHandler_fin_0(void)

{
  ExReleaseResourceLite(&comPortResource);
  KeLeaveCriticalRegion();
  return;
}



===== PortConnectHandler$fin$0 @ 1c000bc34 =====

void PortConnectHandler_fin_0(void)

{
  KeReleaseGuardedMutex(&DAT_1c0007150);
  return;
}



===== ProcessEventUninitialize$fin$0 @ 1c000bc5e =====

void ProcessEventUninitialize_fin_0(void)

{
  KeReleaseGuardedMutex(&DAT_1c0007150);
  DAT_1c0007138 = 0;
  return;
}



===== SendProcessEventMessage$fin$0 @ 1c000bc8e =====

void SendProcessEventMessage_fin_0(void)

{
  KeReleaseGuardedMutex(&DAT_1c0007150);
  return;
}



===== ReadRegistryValue$fin$0 @ 1c000bcb8 =====

void ReadRegistryValue_fin_0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (lVar1 != 0) {
    if (*(int *)(param_2 + 0x30) < 0) {
      FreeGenericBuffer(lVar1,lVar2,param_3);
    }
    else {
      **(longlong **)(param_2 + 0xb8) = lVar1;
    }
  }
  return;
}



===== entry @ 1c000c010 =====

void entry(undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 1c000c044 =====

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



===== CreateProcessEventCompletionPort @ 1c000c078 =====

uint CreateProcessEventCompletionPort
               (undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  longlong lVar1;
  uint uVar2;
  char *pcVar3;
  wchar_t *pwVar4;
  undefined8 *puVar5;
  longlong local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  longlong local_18;
  undefined8 local_10;
  
  local_res8 = 0;
  pcVar3 = "UevFilter.CreateProcessEventCompletionPort: Entry\n";
  DbgTrace(2,"UevFilter.CreateProcessEventCompletionPort: Entry\n",param_3);
  uVar2 = GetCompletionPortSecurityDescriptor(&local_res8,pcVar3,param_3,param_4);
  lVar1 = local_res8;
  if ((int)uVar2 < 0) {
    pcVar3 = 
    "UevFilter.CreateProcessEventCompletionPort: Failed building security descriptor. Error = 0x%0X.\n"
    ;
  }
  else {
    pwVar4 = L"\\UevProcessEventPort";
    local_1c = 0;
    puVar5 = &local_48;
    local_34 = 0;
    local_48 = 0;
    uStack_40 = 0;
    RtlInitUnicodeString();
    local_30 = 0;
    local_28 = &local_48;
    local_10 = 0;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = lVar1;
    GetMaxConnections(puVar5,pwVar4,param_3,(longlong *)param_4);
    param_3 = (longlong *)&local_38;
    puVar5 = &DAT_1c0007130;
    param_4 = (uint *)0x0;
    uVar2 = FltCreateCommunicationPort(g_pFilter);
    if (-1 < (int)uVar2) goto LAB_1c000c16b;
    pcVar3 = 
    "UevFilter.CreateProcessEventCompletionPort: Failed creating communication port. Error = 0x%0X.\n"
    ;
  }
  puVar5 = (undefined8 *)(ulonglong)uVar2;
  DbgTraceFrmtErr(pcVar3,puVar5,param_3,param_4);
LAB_1c000c16b:
  if (lVar1 != 0) {
    FreeGenericBuffer(lVar1,puVar5,param_3);
  }
  DbgTraceFrmt(2,"UevFilter.CreateProcessEventCompletionPort: Exit. Error = 0x%0X.\n",
               (ulonglong)uVar2,param_4);
  return uVar2;
}



===== GetCompletionPortSecurityDescriptor @ 1c000c1ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint GetCompletionPortSecurityDescriptor
               (longlong *param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  uint *puVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  undefined1 auStack_88 [32];
  uint local_68 [2];
  uint local_60 [2];
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = 0;
  pcVar6 = "UevFilter.GetCompletionPortSecurityDescriptor: Entry\n";
  local_48 = 0;
  local_38 = 0;
  uVar2 = 0;
  local_60[0] = 0x11;
  local_60[1] = 0x1f0001;
  local_50 = 0x1a;
  local_4c = 0x1f0001;
  local_40 = 0x16;
  uVar10 = 8;
  local_3c = 0x1f0001;
  DbgTrace(2,"UevFilter.GetCompletionPortSecurityDescriptor: Entry\n",param_3);
  *param_1 = 0;
  plVar8 = &local_58;
  uVar13 = 0;
  do {
    if ((int)uVar2 < 0) goto LAB_1c000c43b;
    uVar1 = *(uint *)(plVar8 + -1);
    local_68[0] = 0;
    DbgTrace(2,"UevFilter.LookupWellKnownSid: Entry\n",param_3);
    if (plVar8 == (longlong *)0x0) {
      uVar2 = 0xc000000d;
      goto LAB_1c000c2e0;
    }
    *plVar8 = 0;
    param_4 = local_68;
    plVar9 = (longlong *)0x0;
    uVar4 = (ulonglong)uVar1;
    uVar2 = SecLookupWellKnownSid(uVar4,0);
    if (uVar2 == 0xc0000023) {
      plVar9 = plVar8;
      uVar2 = AllocateGenericBuffer(uVar4,(ulonglong)local_68[0],plVar8,param_4);
      if ((int)uVar2 < 0) {
        pcVar6 = "UevFilter.LookupWellKnownSid: Failed to allocate buffer for SID. Error = 0x%0X.\n"
        ;
        goto LAB_1c000c2d4;
      }
LAB_1c000c2a7:
      if (*plVar8 != 0) {
        plVar9 = (longlong *)(ulonglong)local_68[0];
        param_4 = local_68;
        uVar2 = SecLookupWellKnownSid(uVar1);
        if ((int)uVar2 < 0) {
          pcVar6 = "UevFilter.LookupWellKnownSid: Failed to get well known SID. Error = 0x%0X.\n";
          goto LAB_1c000c2d4;
        }
      }
    }
    else {
      if (-1 < (int)uVar2) goto LAB_1c000c2a7;
      pcVar6 = "UevFilter.LookupWellKnownSid: Failed to get SID size. Error = 0x%0X.\n";
LAB_1c000c2d4:
      DbgTraceFrmtErr(pcVar6,(ulonglong)uVar2,plVar9,param_4);
    }
LAB_1c000c2e0:
    param_3 = (longlong *)(ulonglong)uVar2;
    pcVar6 = "UevFilter.LookupWellKnownSid: Exit. Error = 0x%0X.\n";
    DbgTraceFrmt(2,"UevFilter.LookupWellKnownSid: Exit. Error = 0x%0X.\n",param_3,param_4);
    if ((int)uVar2 < 0) {
      pcVar6 = (char *)(ulonglong)uVar2;
      pcVar5 = 
      "UevFilter.GetCompletionPortSecurityDescriptor: Failed to get WinAuthenticatedUserSid. Error = 0x%0X.\n"
      ;
      DbgTraceFrmtErr("UevFilter.GetCompletionPortSecurityDescriptor: Failed to get WinAuthenticatedUserSid. Error = 0x%0X.\n"
                      ,pcVar6,param_3,param_4);
    }
    else {
      pcVar5 = (char *)*plVar8;
      iVar3 = RtlLengthSid();
      uVar10 = uVar10 + 8 + iVar3;
    }
    uVar13 = uVar13 + 1;
    plVar8 = plVar8 + 2;
  } while (uVar13 < 3);
  if (-1 < (int)uVar2) {
    plVar8 = param_1;
    uVar2 = AllocateGenericBuffer(pcVar5,(ulonglong)uVar10 + 0x28,param_1,param_4);
    if ((int)uVar2 < 0) {
      pcVar5 = 
      "UevFilter.GetCompletionPortSecurityDescriptor: Failed to allocate memory for descriptor. Error = 0x%0X.\n"
      ;
    }
    else {
      plVar8 = (longlong *)((ulonglong)uVar10 + 0x28);
      memset((void *)*param_1,0,(size_t)plVar8);
      uVar2 = RtlCreateSecurityDescriptor(*param_1,1);
      if ((int)uVar2 < 0) {
        pcVar5 = 
        "UevFilter.GetCompletionPortSecurityDescriptor: Failed to create descriptor. Error = 0x%0X.\n"
        ;
      }
      else {
        param_3 = (longlong *)0x2;
        plVar8 = (longlong *)(*param_1 + 0x28);
        pcVar6 = (char *)(ulonglong)uVar10;
        uVar2 = RtlCreateAcl(plVar8);
        if ((int)uVar2 < 0) {
          pcVar5 = 
          "UevFilter.GetCompletionPortSecurityDescriptor: Failed to create new ACL. Error = 0x%0X.\n"
          ;
          plVar8 = param_3;
        }
        else {
          if (plVar8 == (longlong *)0x0) goto LAB_1c000c44c;
          uVar10 = 0;
          puVar7 = local_60 + 1;
          do {
            if ((int)uVar2 < 0) goto LAB_1c000c43b;
            param_4 = *(uint **)(puVar7 + 1);
            pcVar6 = (char *)0x2;
            param_3 = (longlong *)(ulonglong)*puVar7;
            uVar2 = RtlAddAccessAllowedAce(plVar8);
            if ((int)uVar2 < 0) {
              pcVar6 = (char *)(ulonglong)uVar2;
              DbgTraceFrmtErr("UevFilter.GetCompletionPortSecurityDescriptor: Failed to add ACE to ACL. Error = 0x%0X.\n"
                              ,pcVar6,param_3,param_4);
            }
            uVar10 = uVar10 + 1;
            puVar7 = puVar7 + 4;
          } while (uVar10 < 3);
          if ((int)uVar2 < 0) goto LAB_1c000c43b;
          param_4 = (uint *)0x0;
          pcVar6 = (char *)CONCAT71((int7)((ulonglong)pcVar6 >> 8),1);
          uVar2 = RtlSetDaclSecurityDescriptor(*param_1);
          param_3 = plVar8;
          if (-1 < (int)uVar2) goto LAB_1c000c44c;
          pcVar5 = 
          "UevFilter.GetCompletionPortSecurityDescriptor: Failed to set DACL. Error = 0x%0X.\n";
        }
      }
    }
    pcVar6 = (char *)(ulonglong)uVar2;
    DbgTraceFrmtErr(pcVar5,pcVar6,plVar8,param_4);
    param_3 = plVar8;
  }
LAB_1c000c43b:
  if (*param_1 != 0) {
    FreeGenericBuffer(*param_1,pcVar6,param_3);
    *param_1 = 0;
  }
LAB_1c000c44c:
  plVar8 = &local_58;
  lVar12 = 3;
  do {
    lVar11 = lVar12;
    if (*plVar8 != 0) {
      FreeGenericBuffer(*plVar8,pcVar6,param_3);
    }
    plVar8 = plVar8 + 2;
    lVar12 = lVar11 + -1;
  } while (lVar12 != 0);
  DbgTraceFrmt((int)lVar11 + 1,
               "UevFilter.GetCompletionPortSecurityDescriptor: Exit. Error = 0x%0X.\n",
               (ulonglong)uVar2,param_4);
  return uVar2;
}



===== GetMaxConnections @ 1c000c4b0 =====

uint GetMaxConnections(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  undefined8 **ppuVar2;
  uint local_res8 [8];
  char local_28 [16];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  DbgTrace(2,"UevFilter.GetMaxConnections: Entry\n",param_3);
  RtlInitUnicodeString
            (&local_18,L"\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\UEV\\Agent\\Configuration");
  RtlInitUnicodeString(local_28,L"MaxProcessEventConnections");
  ppuVar2 = (undefined8 **)local_res8;
  uVar1 = ReadRegistryDword((longlong)&local_18,local_28,ppuVar2,param_4);
  if ((int)uVar1 < 0) {
    DbgTrace(2,"UevFilter.GetMaxConnections: Max connections not configured, using default value\n",
             ppuVar2);
    uVar1 = 0x800;
  }
  else {
    uVar1 = local_res8[0];
  }
  DbgTraceFrmt(2,"UevFilter.GetMaxConnections: Exit, maxConnections = %d\n",(ulonglong)uVar1,param_4
              );
  return uVar1;
}



===== ProcessEventInitialize @ 1c000c564 =====

uint ProcessEventInitialize(undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  char *pcVar5;
  
  pcVar5 = "UevFilter.ProcessEventInitialize: Entry\n";
  uVar3 = 2;
  DbgTrace(2,"UevFilter.ProcessEventInitialize: Entry\n",param_3);
  uVar2 = IsSupportedVersion(uVar3,pcVar5,param_3,param_4);
  if ((char)uVar2 == '\0') {
    DbgTraceFrmt(2,"UevFilter.ProcessEventInitialize: OS version is not supported.",param_3,param_4)
    ;
    uVar1 = 0;
  }
  else {
    puVar4 = &DAT_1c0007150;
    DAT_1c0007138 = 1;
    KeInitializeGuardedMutex();
    uVar1 = AllocateFilterHashTable(puVar4,pcVar5,param_3,param_4);
    if ((int)uVar1 < 0) {
      DbgTraceFrmtErr("UevFilter.ProcessEventInitialize: Failed to allocate a hash table. Status = 0x%0X.\n"
                      ,(ulonglong)uVar1,param_3,param_4);
    }
    else {
      uVar1 = CreateProcessEventCompletionPort(puVar4,pcVar5,param_3,param_4);
      if ((int)uVar1 < 0) {
        uVar2 = (ulonglong)uVar1;
        pcVar5 = 
        "UevFilter.ProcessEventInitialize: Failed to allocate completion port. Status = 0x%0X.\n";
        DbgTraceFrmtErr("UevFilter.ProcessEventInitialize: Failed to allocate completion port. Status = 0x%0X.\n"
                        ,uVar2,param_3,param_4);
        FreeFilterHashTable(pcVar5,uVar2,param_3);
        DAT_1c0007128 = 0;
      }
    }
  }
  DbgTraceFrmt(2,"UevFilter.ProcessEventInitialize: Exit, status = 0x%0X.\n",(ulonglong)uVar1,
               param_4);
  return uVar1;
}



===== DriverEntry @ 1c000c618 =====

uint DriverEntry(undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined *puVar4;
  
  pcVar3 = "UevFilter.DriverEntry: Entry\n";
  uVar2 = 1;
  DbgTrace(1,"UevFilter.DriverEntry: Entry\n",param_3);
  McGenEventRegister_EtwRegister();
  GetDebugLevel();
  uVar1 = ComPortInit(uVar2,pcVar3,param_3,(longlong *)param_4);
  if ((int)uVar1 < 0) {
    pcVar3 = "UevFilter.DriverEntry: ComPort initialization failed, status = 0x%X\n";
  }
  else {
    comPortInitialized = 1;
    g_pFilter = 0;
    param_3 = &g_pFilter;
    puVar4 = &FilterRegistration;
    uVar1 = FltRegisterFilter();
    if (((int)uVar1 < 0) && ((uVar1 != 0xc01c0011 || (g_pFilter == 0)))) {
      pcVar3 = "UevFilter.DriverEntry: Filter registration failed, status = 0x%X\n";
    }
    else {
      filterRegistered = 1;
      uVar1 = ComPortCreate(param_1,puVar4,param_3,param_4);
      if ((int)uVar1 < 0) {
        pcVar3 = "UevFilter.DriverEntry: Communication Port creation failed, status = 0x%X\n";
      }
      else {
        portCreated = 1;
        pcVar3 = (char *)CONCAT71((int7)((ulonglong)param_1 >> 8),1);
        uVar1 = HookProcessNotify('\x01',puVar4,param_3,param_4);
        if ((int)uVar1 < 0) {
          pcVar3 = "UevFilter.DriverEntry: Hook process notify failed, status = 0x%X\n";
        }
        else {
          processNotifyHooked = 1;
          uVar1 = ProcessEventInitialize(pcVar3,puVar4,param_3,param_4);
          if (-1 < (int)uVar1) {
            processEventPortCreated = 1;
            if ((Microsoft_User_Experience_Virtualization_Agent_DriverEnableBits & 0x10) != 0) {
              puVar4 = &DriverLoaded;
              McTemplateK0_EtwWriteTransfer(pcVar3,&DriverLoaded,param_3);
            }
            goto LAB_1c000c73e;
          }
          pcVar3 = "UevFilter.DriverEntry: Failed to create process event port. status = 0x%X\n";
        }
      }
    }
  }
  puVar4 = (undefined *)(ulonglong)uVar1;
  DbgTraceFrmtErr(pcVar3,puVar4,param_3,param_4);
LAB_1c000c73e:
  if ((int)uVar1 < 0) {
    UnInitializeDriver(pcVar3,puVar4,param_3,param_4);
  }
  DbgTrace(1,"UevFilter.DriverEntry: Exit\n",param_3);
  if ((int)uVar1 < 0) {
    McGenEventUnregister_EtwUnregister();
  }
  return uVar1;
}



===== DriverEntry$fin$0 @ 1c000c775 =====

void DriverEntry_fin_0(undefined8 param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  if (*(int *)(param_2 + 0x20) < 0) {
    UnInitializeDriver(param_1,param_2,param_3,param_4);
  }
  return;
}


