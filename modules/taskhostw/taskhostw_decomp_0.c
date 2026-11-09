
===== _tlgEnableCallback @ 140001010 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== `dynamic_initializer_for_'g_strmgr'' @ 140001090 =====

void ATL::_dynamic_initializer_for__g_strmgr__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_strmgr__);
  return;
}



===== s_sync'' @ 1400010b0 =====

void `dynamic_initializer_for_'ShutdownMgr::s_sync__(void)

{
  LOCK();
  DAT_1400159a4 = 0;
  UNLOCK();
  atexit(`dynamic_atexit_destructor_for_'ShutdownMgr::s_sync__);
  return;
}



===== _Generic_object'' @ 1400010d0 =====

void `dynamic_initializer_for_'std::_Error_objects<int>::_Generic_object__(void)

{
  atexit(`dynamic_atexit_destructor_for_'std::_Error_objects<int>::_Generic_object__);
  return;
}



===== _Iostream_object'' @ 1400010f0 =====

void `dynamic_initializer_for_'std::_Error_objects<int>::_Iostream_object__(void)

{
  atexit(`dynamic_atexit_destructor_for_'std::_Error_objects<int>::_Iostream_object__);
  return;
}



===== _System_object'' @ 140001110 =====

void `dynamic_initializer_for_'std::_Error_objects<int>::_System_object__(void)

{
  atexit(`dynamic_atexit_destructor_for_'std::_Error_objects<int>::_System_object__);
  return;
}



===== wWinMain @ 140001130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __stdcall wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)

{
  undefined2 uVar1;
  code *pcVar2;
  char cVar3;
  ULONG UVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 *local_30;
  longlong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  puVar7 = auStack_68;
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  _DAT_140015970 = 1;
  _DAT_140015968 = 0;
  puVar6 = &WPP_MAIN_CB;
  WPP_MAIN_CB = 0;
  WPP_REGISTRATION_GUIDS = &WPP_ThisDir_CTLGUID_Regular;
  plVar8 = (longlong *)&WPP_REGISTRATION_GUIDS;
  WPP_GLOBAL_Control = (undefined *)&WPP_MAIN_CB;
  do {
    local_28 = *plVar8;
    local_30 = puVar6 + 1;
    local_38 = 0;
    local_48 = &local_28;
    plVar8 = plVar8 + 1;
    uStack_20 = 0;
    local_40 = 0;
    puVar6[4] = local_28;
    RegisterTraceGuidsW(WppControlCallback,puVar6,local_28,1);
    puVar6 = (undefined8 *)*puVar6;
  } while (puVar6 != (undefined8 *)0x0);
  local_28 = *(longlong *)(PTR_DAT_140015028 + -0x10);
  uStack_20 = *(undefined8 *)(PTR_DAT_140015028 + -8);
  if (DAT_140015040 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar7 = auStack_60;
  }
  _DAT_140015048 = 0;
  uRam0000000140015050 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x140001233;
  UVar4 = EventRegister((LPCGUID)(puVar7 + 0x40),_tlgEnableCallback,&DAT_140015020,
                        (PREGHANDLE)&DAT_140015040);
  if (UVar4 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140015028;
    *(undefined8 *)(puVar7 + -8) = 0x140001258;
    EventSetInformation(DAT_140015040,2,PTR_DAT_140015028,uVar1);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140001262;
  cVar3 = IsImmDisableIMEPresent();
  if (cVar3 != '\0') {
    *(undefined8 *)(puVar7 + -8) = 0x140001272;
    ImmDisableIME(0xffffffff);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000127f;
  uVar5 = UbpmTaskHostWaitForCommands(hInstance);
  puVar6 = (undefined8 *)WPP_GLOBAL_Control;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    for (; puVar6 != (undefined8 *)0x0; puVar6 = (undefined8 *)*puVar6) {
      if (puVar6[1] != 0) {
        *(undefined8 *)(puVar7 + -8) = 0x1400012d0;
        UnregisterTraceGuids();
        puVar6[1] = 0;
      }
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  *(undefined8 *)(puVar7 + -8) = 0x1400012a1;
  return (int)uVar5;
}



===== UbpmTaskHostWaitForCommands @ 140001300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400015a6) */
/* WARNING: Removing unreachable block (ram,0x0001400015b7) */
/* WARNING: Removing unreachable block (ram,0x0001400015dc) */
/* WARNING: Removing unreachable block (ram,0x0001400015e5) */
/* WARNING: Removing unreachable block (ram,0x00014000160a) */
/* WARNING: Removing unreachable block (ram,0x000140001613) */
/* WARNING: Removing unreachable block (ram,0x000140001638) */
/* WARNING: Removing unreachable block (ram,0x0001400017cd) */
/* WARNING: Removing unreachable block (ram,0x000140001645) */

ulonglong UbpmTaskHostWaitForCommands(HINSTANCE__ *param_1)

{
  uint uVar1;
  ulong uVar2;
  DWORD extraout_EAX;
  DWORD DVar3;
  undefined8 hEvent;
  CLIENT_CALL_RETURN CVar4;
  CLIENT_CALL_RETURN CVar5;
  ulonglong uVar6;
  undefined1 auStackY_128 [32];
  DWORD local_e0 [2];
  void *local_d8;
  longlong local_d0;
  undefined4 local_c8 [4];
  _RPC_ASYNC_STATE local_b8;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  longlong lStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d8 = (void *)0x0;
  local_d0 = 0;
  hEvent = (PFN_RPCNOTIFICATION_ROUTINE)0x0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  SetUnhandledExceptionFilter(UbpmpTaskHostUnhandledExceptionFilter);
  local_c8[0] = 1;
  NtSetInformationProcess(0xffffffffffffffff,0x36,local_c8,4);
  uVar1 = CoInitializeEx((LPVOID)0x0,0);
  if ((int)uVar1 < 0) {
    uVar6 = (ulonglong)(uVar1 & 0xffff);
  }
  else {
    uVar1 = InitializeComTasksLib(param_1);
    CVar4.Simple._4_4_ = 0;
    CVar4.Simple._0_4_ = uVar1;
    if (uVar1 == 0) {
      hEvent = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if ((PFN_RPCNOTIFICATION_ROUTINE)hEvent == (PFN_RPCNOTIFICATION_ROUTINE)0x0) {
        DVar3 = GetLastError();
        CVar4.Simple._4_4_ = 0;
        CVar4.Simple._0_4_ = DVar3;
      }
      else {
        uVar2 = UbpmpRpcBind(&local_d8);
        CVar4.Simple._4_4_ = 0;
        CVar4.Simple._0_4_ = uVar2;
        if ((uVar2 == 0) &&
           (CVar4 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,0,(void *)0x0),
           (int)CVar4.Simple == 0)) {
          CVar5 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,0,(void *)0x0);
          CVar4.Simple = CVar5.Simple & 0xffffffff;
          if ((int)CVar5.Simple == 0) {
            g_dwMainThreadId = GetCurrentThreadId();
LAB_140001462:
            while( true ) {
              local_e0[0] = 0;
              local_b8.Size = 0;
              local_b8.Signature = 0;
              local_b8.Lock = 0;
              local_b8.Flags = 0;
              local_b8.StubInfo = (void *)0x0;
              local_b8.UserInfo = (void *)0x0;
              local_b8.RuntimeInfo = (void *)0x0;
              local_b8.Event = RpcCallComplete;
              local_b8.NotificationType = RpcNotificationTypeNone;
              local_b8.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)0x0;
              local_b8.u.APC.hThread = (HANDLE)0x0;
              local_b8.u.IOC.dwCompletionKey = 0;
              local_b8.u.IOC.lpOverlapped = (LPOVERLAPPED)0x0;
              local_b8.Reserved[0] = 0;
              local_b8.Reserved[1] = 0;
              local_b8.Reserved[2] = 0;
              local_b8.Reserved[3] = 0;
              ResetEvent((HANDLE)hEvent);
              uVar1 = RpcAsyncInitializeHandle(&local_b8,0x70);
              if (uVar1 == 0) {
                local_b8.UserInfo = (void *)0x0;
                local_b8.NotificationType = RpcNotificationTypeEvent;
                local_b8.u.IOC.hIOPort = (HANDLE)hEvent;
                CVar4 = Ndr64AsyncClientCall
                                  ((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,2,(void *)0x0);
                extraout_EAX = (DWORD)CVar4.Simple;
                local_e0[0] = extraout_EAX;
                if (extraout_EAX == 0) {
                  local_e0[0] = extraout_EAX;
                  DVar3 = WaitForSingleObject((HANDLE)hEvent,0xffffffff);
                  if (DVar3 != 0) {
                    local_e0[0] = GetLastError();
                    DVar3 = RpcAsyncCancelCall(&local_b8,1);
                    if (DVar3 != 0) {
                      local_e0[0] = DVar3;
                    }
                    DVar3 = WaitForSingleObject(local_b8.u.IOC.hIOPort,0xffffffff);
                    if (DVar3 != 0) {
                      local_e0[0] = GetLastError();
                    }
                  }
                  uVar1 = RpcAsyncCompleteCall(&local_b8,local_e0);
                  if (uVar1 == 0) {
                  }
                  else {
                    local_e0[0] = uVar1;
                  }
                }
              }
              else {
                local_e0[0] = uVar1;
              }
              g_dwLastTaskResult = 0;
              CVar4.Simple._4_4_ = 0;
              CVar4.Simple._0_4_ = local_e0[0];
              g_ucLastTaskFlags = '\0';
              if (local_e0[0] == 0) break;
              if (local_e0[0] < 0x4d6) {
                if ((((local_e0[0] != 0x4d5) && (local_e0[0] != 0xe)) && (local_e0[0] != 0x102)) &&
                   (local_e0[0] != 0x3e5)) goto LAB_140001587;
              }
              else if ((local_e0[0] != 0x80010101) && (local_e0[0] != 0x80010109))
              goto LAB_140001587;
              Sleep(100);
            }
            if (sRam0000000000000000 == 1) {
              if (lRam0000000000000028 == 0) goto LAB_140001587;
              uVar1 = StopComTask((undefined8 *)0x28);
              CVar4.Simple._4_4_ = 0;
              CVar4.Simple._0_4_ = uVar1;
              if (uVar1 != 0x3c8d) goto LAB_140001587;
LAB_14000170e:
              if (uVar1 != 0) goto LAB_1400016f2;
LAB_140001712:
              local_48 = CONCAT44(local_48._4_4_,g_dwLastTaskResult);
            }
            else {
              if (sRam0000000000000000 != 2) {
                if (sRam0000000000000000 == 3) {
                  if (lRam0000000000000028 == 0) {
                    uVar1 = 6;
                    goto LAB_1400016f2;
                  }
                  uVar1 = StopComTask((undefined8 *)0x28);
                }
                else {
                  uVar1 = 0;
                  if (sRam0000000000000000 == 4) {
                    uVar1 = UbpmUtilsCloseWinApp(uRam0000000000000034);
                  }
                }
                goto LAB_14000170e;
              }
              uVar1 = StartComTask(uRam0000000000000008,uRam0000000000000010,uRam0000000000000018,
                                   uRam0000000000000030,uRam0000000000000038,&local_38);
              if (uVar1 == 0) {
                if ((local_38 == -1) && ((g_ucLastTaskFlags & 1) == 0)) {
                  g_ucLastTaskFlags = g_ucLastTaskFlags | 1;
                }
                goto LAB_140001712;
              }
LAB_1400016f2:
              local_48 = CONCAT44(local_48._4_4_,uVar1);
            }
            uStack_40 = uRam0000000000000020;
            if (uVar1 == 0) {
              lStack_30 = CONCAT71(lStack_30._1_7_,g_ucLastTaskFlags);
            }
            else {
              lStack_30 = (ulonglong)lStack_30._1_7_ << 8;
            }
            goto LAB_140001462;
          }
        }
      }
LAB_140001587:
      UninitializeComTasksLib();
    }
    CoUninitialize();
    if ((PFN_RPCNOTIFICATION_ROUTINE)hEvent != (PFN_RPCNOTIFICATION_ROUTINE)0x0) {
      CloseHandle((HANDLE)hEvent);
    }
    if (local_d0 != 0) {
      NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,1,(void *)0x0);
    }
    if (local_d8 != (void *)0x0) {
      RpcBindingFree(&local_d8);
    }
    uVar6 = CVar4.Simple & 0xffffffff;
  }
  return uVar6;
}



===== InitializeComTasksLib @ 140001900 =====

uint InitializeComTasksLib(HINSTANCE__ *param_1)

{
  uint uVar1;
  uint local_res18;
  
  local_res18 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10);
  }
  uVar1 = ComTaskMgrBase::Initialize(param_1);
  if ((int)uVar1 < 0) {
    local_res18 = uVar1 & 0xffff;
    if (local_res18 == 0) {
      local_res18 = 6;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,
               &WPP_fd76d537424c3f213087d14e42e29f74_Traceguids,local_res18);
    }
  }
  else {
    SetProcessShutdownParameters(0x7f,1);
  }
  return local_res18;
}



===== Initialize @ 140001a18 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static long __cdecl ComTaskMgrBase::Initialize(struct HINSTANCE__ * __ptr64) */

long __cdecl ComTaskMgrBase::Initialize(HINSTANCE__ *param_1)

{
  bool bVar1;
  char cVar2;
  long lVar3;
  ComTaskMgrBase *pCVar4;
  ComTaskMgrWnd *this;
  
  lVar3 = InitComSecurity();
  if (lVar3 < 0) {
    return lVar3;
  }
  lVar3 = ShutdownMgr::Initialize();
  if (lVar3 < 0) {
    return lVar3;
  }
  if ((*(int *)((longlong)ProcessEnvironmentBlock + 0x2c0) == 0) ||
     (cVar2 = IsCreateWindowExWPresent(), cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    pCVar4 = operator_new(8);
    if (pCVar4 != (ComTaskMgrBase *)0x0) {
      *(undefined ***)pCVar4 = &_vftable_;
    }
  }
  else {
    this = operator_new(0x60);
    pCVar4 = (ComTaskMgrBase *)0x0;
    if (this != (ComTaskMgrWnd *)0x0) {
      pCVar4 = (ComTaskMgrBase *)ComTaskMgrWnd::ComTaskMgrWnd(this);
    }
  }
  if (pCVar4 == (ComTaskMgrBase *)0x0) {
    lVar3 = -0x7ff8fff2;
  }
  if (lVar3 < 0) {
    if (pCVar4 != (ComTaskMgrBase *)0x0) {
      (**(code **)(*(longlong *)pCVar4 + 0x20))(pCVar4,1);
    }
  }
  else {
    s_pVirtualSingleton = pCVar4;
    lVar3 = (**(code **)(*(longlong *)pCVar4 + 0x28))(pCVar4,param_1);
  }
  return lVar3;
}



===== UbpmpRpcBind @ 140001b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl UbpmpRpcBind(void * __ptr64 * __ptr64) */

ulong __cdecl UbpmpRpcBind(void **param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStackY_b8 [32];
  RPC_BINDING_HANDLE local_58;
  RPC_WSTR local_50;
  PSID local_48;
  RPC_SECURITY_QOS local_40;
  undefined8 local_30;
  undefined8 uStack_28;
  PSID local_20;
  _SID_IDENTIFIER_AUTHORITY local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_18.Value[4] = '\0';
  local_18.Value[5] = '\x05';
  local_20 = (PSID)0x0;
  local_18.Value[0] = '\0';
  local_18.Value[1] = '\0';
  local_18.Value[2] = '\0';
  local_18.Value[3] = '\0';
  local_48 = (PSID)0x0;
  local_58 = (void *)0x0;
  local_50 = (RPC_WSTR)0x0;
  local_40.Version = 0;
  local_40.Capabilities = 0;
  local_40.IdentityTracking = 0;
  local_40.ImpersonationType = 0;
  local_30 = 0;
  uStack_28 = 0;
  DVar1 = RpcStringBindingComposeW
                    ((RPC_WSTR)0x0,(RPC_WSTR)L"ncalrpc",(RPC_WSTR)0x0,
                     (RPC_WSTR)L"ubpmtaskhostchannel",(RPC_WSTR)0x0,&local_50);
  if (DVar1 == 0) {
    DVar1 = RpcBindingFromStringBindingW(local_50,&local_58);
    RpcStringFreeW(&local_50);
    if (DVar1 == 0) {
      BVar2 = AllocateAndInitializeSid(&local_18,'\x01',0x12,0,0,0,0,0,0,0,&local_48);
      if (BVar2 == 0) {
        DVar1 = GetLastError();
      }
      else {
        local_20 = local_48;
        local_40.Version = 3;
        local_40.Capabilities = 1;
        local_40.IdentityTracking = 1;
        local_40.ImpersonationType = 3;
        DVar1 = RpcBindingSetAuthInfoExW
                          (local_58,(RPC_WSTR)0x0,6,10,(RPC_AUTH_IDENTITY_HANDLE)0x0,1,&local_40);
        FreeSid(local_48);
        if (DVar1 == 0) {
          *param_1 = local_58;
          return 0;
        }
      }
    }
  }
  if (local_58 != (void *)0x0) {
    RpcBindingFree(&local_58);
  }
  return DVar1;
}



===== UninitializeComTasksLib @ 140001cf0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint UninitializeComTasksLib(void)

{
  uint uVar1;
  uint local_res10;
  
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc);
  }
  uVar1 = 0;
  if (ComTaskMgrBase::s_pVirtualSingleton != (ComTaskMgrBase *)0x0) {
    uVar1 = (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 0x30))();
    if (ComTaskMgrBase::s_pVirtualSingleton != (ComTaskMgrBase *)0x0) {
      (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 0x20))
                (ComTaskMgrBase::s_pVirtualSingleton,1);
    }
    ComTaskMgrBase::s_pVirtualSingleton = (ComTaskMgrBase *)0x0;
  }
  if ((int)uVar1 < 0) {
    local_res10 = uVar1 & 0xffff;
    if (local_res10 == 0) {
      local_res10 = 6;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
               &WPP_fd76d537424c3f213087d14e42e29f74_Traceguids,local_res10);
    }
  }
  return local_res10;
}



===== StartComTask @ 140001e20 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint StartComTask(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined4 param_5,undefined8 *param_6)

{
  uint uVar1;
  uint local_24;
  
  local_24 = 0;
  uVar1 = (*(code *)**(undefined8 **)ComTaskMgrBase::s_pVirtualSingleton)
                    (ComTaskMgrBase::s_pVirtualSingleton,param_1,param_2,param_3,param_4,param_5,
                     param_6);
  if ((int)uVar1 < 0) {
    local_24 = uVar1 & 0xffff;
    if (local_24 == 0) {
      local_24 = 6;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,
                &WPP_fd76d537424c3f213087d14e42e29f74_Traceguids,*param_6,(char)local_24);
    }
  }
  return local_24;
}



===== StopComTask @ 140001f00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

uint StopComTask(undefined8 *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  uint local_res18;
  
  local_res18 = 0;
  uVar1 = *param_1;
  uVar2 = (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 8))
                    (ComTaskMgrBase::s_pVirtualSingleton,param_1);
  *param_1 = 0;
  if ((int)uVar2 < 0) {
    local_res18 = uVar2 & 0xffff;
    if (local_res18 == 0) {
      local_res18 = 6;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xf,
                &WPP_fd76d537424c3f213087d14e42e29f74_Traceguids,uVar1,(char)local_res18);
    }
  }
  return local_res18;
}



===== UBPM_MIDL_user_free @ 140001ff0 =====

void UBPM_MIDL_user_free(LPVOID param_1)

{
  HANDLE hHeap;
  
  if (param_1 != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,param_1);
  }
  return;
}



===== GetACE @ 140002030 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void * __ptr64 __cdecl ATL::CDacl::CAccessAce::GetACE(void)const __ptr64 */

void * __thiscall ATL::CDacl::CAccessAce::GetACE(CAccessAce *this)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  DWORD DVar4;
  errno_t eVar5;
  undefined1 *_Dst;
  
  _Dst = *(undefined1 **)(this + 0x88);
  if (_Dst == (undefined1 *)0x0) {
    uVar3 = (**(code **)(*(longlong *)this + 0x10))();
    _Dst = malloc((ulonglong)uVar3);
    if (_Dst == (undefined1 *)0x0) {
                    /* WARNING: Subroutine does not return */
      PrivateAtlThrow(-0x7ff8fff2);
    }
    memset(_Dst,0,(ulonglong)uVar3);
    *(CAccessAce *)(_Dst + 1) = this[0x84];
    lVar1 = *(longlong *)this;
    *(short *)(_Dst + 2) = (short)uVar3;
    uVar2 = (**(code **)(lVar1 + 0x18))(this);
    *_Dst = uVar2;
    *(undefined4 *)(_Dst + 4) = *(undefined4 *)(this + 0x80);
    DVar4 = GetLengthSid(this + 0x10);
    eVar5 = memcpy_s(_Dst + 8,(ulonglong)uVar3 - 8,this + 0x10,(ulonglong)DVar4);
    AtlCrtErrorCheck(eVar5);
    *(undefined1 **)(this + 0x88) = _Dst;
  }
  return _Dst;
}



===== GetLength @ 140002120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: unsigned int __cdecl ATL::CAcl::GetLength(void)const __ptr64 */

uint __thiscall ATL::CAcl::GetLength(CAcl *this)

{
  BOOL BVar1;
  _ACL *pAcl;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  pAcl = GetPACL(this);
  local_28 = 0;
  local_20 = 0;
  if (this[0x10] != (CAcl)0x0) {
    return 0;
  }
  BVar1 = GetAclInformation(pAcl,&local_28,0xc,AclSizeInformation);
  if (BVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    AtlThrowLastWin32();
  }
  return local_28._4_4_;
}



===== GetPACL @ 1400021b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: struct _ACL const * __ptr64 __cdecl ATL::CAcl::GetPACL(void)const __ptr64 */

_ACL * __thiscall ATL::CAcl::GetPACL(CAcl *this)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  DWORD nAceListLength;
  long lVar4;
  longlong *plVar5;
  PACL pAcl;
  LPVOID pAceList;
  uint uVar6;
  uint nAclLength;
  
  if ((*(longlong *)(this + 8) == 0) && (this[0x10] == (CAcl)0x0)) {
    nAclLength = 8;
    uVar1 = (**(code **)(*(longlong *)this + 8))();
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        plVar5 = (longlong *)(**(code **)(*(longlong *)this + 0x20))(this,uVar6);
        if (plVar5 != (longlong *)0x0) {
          iVar2 = (**(code **)(*plVar5 + 0x10))(plVar5);
          nAclLength = nAclLength + iVar2;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar1);
    }
    pAcl = malloc((ulonglong)nAclLength);
    *(PACL *)(this + 8) = pAcl;
    if (pAcl == (PACL)0x0) {
                    /* WARNING: Subroutine does not return */
      PrivateAtlThrow(-0x7ff8fff2);
    }
    BVar3 = InitializeAcl(pAcl,nAclLength,*(DWORD *)(this + 0x14));
    if (BVar3 == 0) {
      lVar4 = AtlHresultFromLastError();
      free(*(void **)(this + 8));
      *(undefined8 *)(this + 8) = 0;
                    /* WARNING: Subroutine does not return */
      PrivateAtlThrow(lVar4);
    }
    (**(code **)(*(longlong *)this + 0x28))(this);
    for (uVar6 = 0; uVar6 < uVar1; uVar6 = uVar6 + 1) {
      plVar5 = (longlong *)(**(code **)(*(longlong *)this + 0x20))(this,uVar6);
      if (plVar5 == (longlong *)0x0) {
LAB_14000232e:
        lVar4 = AtlHresultFromLastError();
        free(*(void **)(this + 8));
        *(undefined8 *)(this + 8) = 0;
                    /* WARNING: Subroutine does not return */
        PrivateAtlThrow(lVar4);
      }
      nAceListLength = (**(code **)(*plVar5 + 0x10))(plVar5);
      pAceList = (LPVOID)(**(code **)(*plVar5 + 8))(plVar5);
      BVar3 = AddAce(*(PACL *)(this + 8),*(DWORD *)(this + 0x14),0xffffffff,pAceList,nAceListLength)
      ;
      if (BVar3 == 0) goto LAB_14000232e;
    }
  }
  return *(_ACL **)(this + 8);
}



===== RemoveAllAces @ 140002360 =====

/* public: virtual void __cdecl ATL::CDacl::RemoveAllAces(void) __ptr64 */

void __thiscall ATL::CDacl::RemoveAllAces(CDacl *this)

{
  __uint64 in_RDX;
  int in_R8D;
  
  CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
  ::SetCount((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
              *)(this + 0x18),in_RDX,in_R8D);
  free(*(void **)(this + 8));
  *(undefined8 *)(this + 8) = 0;
  return;
}



===== `vector_deleting_destructor' @ 1400023a0 =====

/* public: virtual void * __ptr64 __cdecl ATL::CAcl::CAce::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall ATL::CAcl::CAce::_vector_deleting_destructor_(CAce *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  free(*(void **)(this + 0x88));
  CSid::~CSid((CSid *)(this + 8));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ~CDacl @ 140002400 =====

/* public: virtual __cdecl ATL::CDacl::~CDacl(void) __ptr64 */

void __thiscall ATL::CDacl::~CDacl(CDacl *this)

{
  __uint64 in_RDX;
  int in_R8D;
  
  *(undefined ***)this = &_vftable_;
  CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
  ::SetCount((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
              *)(this + 0x18),in_RDX,in_R8D);
  free(*(void **)(this + 8));
  *(undefined8 *)(this + 8) = 0;
  if (*(CAutoPtr<ATL::CDacl::CAccessAce> **)(this + 0x18) != (CAutoPtr<ATL::CDacl::CAccessAce> *)0x0
     ) {
    CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
    ::CallDestructors(*(CAutoPtr<ATL::CDacl::CAccessAce> **)(this + 0x18),*(__uint64 *)(this + 0x20)
                     );
    free(*(void **)(this + 0x18));
  }
  *(undefined ***)this = &CAcl::_vftable_;
                    /* WARNING: Could not recover jumptable at 0x00014000245a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(*(void **)(this + 8));
  return;
}



===== InitComSecurity @ 140002490 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl ComTaskMgrBase::InitComSecurity(void) */

long __cdecl ComTaskMgrBase::InitComSecurity(void)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  errno_t eVar6;
  BOOL BVar7;
  long lVar8;
  HRESULT HVar9;
  void *pvVar10;
  PACL pDacl;
  _ACL *_Src;
  __uint64 _Var11;
  ulong uVar12;
  CSid *pSid;
  uchar uVar13;
  DWORD *cbSid;
  undefined1 auStackY_1d8 [32];
  DWORD local_188 [2];
  undefined **local_180;
  PSECURITY_DESCRIPTOR local_178;
  PSID local_170;
  undefined **local_168;
  void *local_160;
  char local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined4 local_138;
  PACL local_130;
  CSid local_128 [8];
  undefined1 local_120 [68];
  char local_dc;
  CSid local_a8 [128];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_180 = &ATL::CSecurityDesc::_vftable_;
  local_178 = (PSECURITY_DESCRIPTOR)0x0;
  BVar7 = 1;
  ATL::CSid::CSid(local_128,&ATL::Sids::SecurityNTAuthority,'\x01',10);
  if (local_178 != (PSECURITY_DESCRIPTOR)0x0) {
    ATL::CSecurityDesc::MakeAbsolute((CSecurityDesc *)&local_180);
  }
  local_170 = (void *)0x0;
  if (local_178 == (PSECURITY_DESCRIPTOR)0x0) {
    local_178 = malloc(0x28);
    if (local_178 == (void *)0x0) goto LAB_140002a95;
    BVar2 = InitializeSecurityDescriptor(local_178,1);
    if (BVar2 == 0) {
      lVar8 = ATL::AtlHresultFromLastError();
      free(local_178);
      local_178 = (PSECURITY_DESCRIPTOR)0x0;
                    /* WARNING: Subroutine does not return */
      ATL::PrivateAtlThrow(lVar8);
    }
  }
  else {
    local_188[0] = 0;
    BVar2 = GetSecurityDescriptorOwner(local_178,&local_170,(LPBOOL)local_188);
    if (BVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      ATL::AtlThrowLastWin32();
    }
  }
  if (local_dc == '\0') {
LAB_140002a8a:
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(-0x7fffbffb);
  }
  BVar2 = IsValidSid(local_120);
  if (BVar2 == 0) goto LAB_140002a8a;
  DVar3 = GetLengthSid(local_120);
  pvVar10 = malloc((ulonglong)DVar3);
  if (pvVar10 == (void *)0x0) {
LAB_140002a95:
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(-0x7ff8fff2);
  }
  BVar2 = CopySid(DVar3,pvVar10,local_120);
  if (BVar2 == 0) {
LAB_140002a6c:
    lVar8 = ATL::AtlHresultFromLastError();
    free(pvVar10);
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(lVar8);
  }
  BVar2 = SetSecurityDescriptorOwner(local_178,pvVar10,0);
  if (BVar2 == 0) goto LAB_140002a6c;
  free(local_170);
  ATL::CSid::~CSid(local_128);
  ATL::CSid::CSid(local_128,&ATL::Sids::SecurityNTAuthority,'\x02');
  if (local_178 != (PSECURITY_DESCRIPTOR)0x0) {
    ATL::CSecurityDesc::MakeAbsolute((CSecurityDesc *)&local_180);
  }
  local_170 = (void *)0x0;
  if (local_178 == (PSECURITY_DESCRIPTOR)0x0) {
    ATL::CSecurityDesc::AllocateAndInitializeSecurityDescriptor((CSecurityDesc *)&local_180);
  }
  else {
    local_188[0] = 0;
    BVar2 = GetSecurityDescriptorGroup(local_178,&local_170,(LPBOOL)local_188);
    if (BVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      ATL::AtlThrowLastWin32();
    }
  }
  if (local_dc == '\0') {
LAB_140002a61:
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(-0x7fffbffb);
  }
  BVar2 = IsValidSid(local_120);
  if (BVar2 == 0) goto LAB_140002a61;
  DVar3 = GetLengthSid(local_120);
  pvVar10 = malloc((ulonglong)DVar3);
  if (pvVar10 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(-0x7ff8fff2);
  }
  BVar2 = CopySid(DVar3,pvVar10,local_120);
  if (BVar2 == 0) {
LAB_140002a42:
    lVar8 = ATL::AtlHresultFromLastError();
    free(pvVar10);
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(lVar8);
  }
  BVar2 = SetSecurityDescriptorGroup(local_178,pvVar10,0);
  if (BVar2 == 0) goto LAB_140002a42;
  free(local_170);
  ATL::CSid::~CSid(local_128);
  local_160 = (void *)0x0;
  local_158 = '\0';
  local_154 = 2;
  local_168 = &ATL::CDacl::_vftable_;
  local_150 = 0;
  uStack_148 = 0;
  local_140 = 0;
  local_138 = 0;
  uVar13 = '\n';
  uVar12 = 1;
  ATL::CSid::CSid(local_128,&ATL::Sids::SecurityNTAuthority,'\x01');
  ATL::CDacl::AddAllowedAce((CDacl *)&local_168,local_128,uVar12,uVar13);
  ATL::CSid::~CSid(local_128);
  uVar13 = '\x12';
  uVar12 = 1;
  ATL::CSid::CSid(local_128,&ATL::Sids::SecurityNTAuthority,'\x01');
  ATL::CDacl::AddAllowedAce((CDacl *)&local_168,local_128,uVar12,uVar13);
  ATL::CSid::~CSid(local_128);
  cVar1 = RtlIsMultiSessionSku();
  if (cVar1 == '\0') {
    local_188[0] = 0x44;
    cbSid = local_188;
    pSid = local_128;
    BVar2 = CreateWellKnownSid(WinBuiltinCryptoOperatorsSid|WinAccountSchemaAdminsSid,(PSID)0x0,pSid
                               ,cbSid);
    uVar13 = (uchar)cbSid;
    if (BVar2 != 0) {
      ATL::CSid::CSid(local_a8,(_SID *)local_128,(ushort *)pSid);
      ATL::CDacl::AddAllowedAce((CDacl *)&local_168,local_a8,(ulong)pSid,uVar13);
      ATL::CSid::~CSid(local_a8);
    }
  }
  if (local_178 != (PSECURITY_DESCRIPTOR)0x0) {
    ATL::CSecurityDesc::MakeAbsolute((CSecurityDesc *)&local_180);
  }
  local_130 = (PACL)0x0;
  if (local_178 == (PSECURITY_DESCRIPTOR)0x0) {
    ATL::CSecurityDesc::AllocateAndInitializeSecurityDescriptor((CSecurityDesc *)&local_180);
  }
  else {
    local_188[0] = 0;
    local_170 = (PSID)((ulonglong)local_170 & 0xffffffff00000000);
    BVar2 = GetSecurityDescriptorDacl(local_178,(LPBOOL)&local_170,&local_130,(LPBOOL)local_188);
    if (BVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      ATL::AtlThrowLastWin32();
    }
  }
  if (local_158 == '\0') {
    iVar4 = (*(code *)local_168[1])(&local_168);
    if (iVar4 != 0) {
      uVar5 = ATL::CAcl::GetLength((CAcl *)&local_168);
      pDacl = malloc((ulonglong)uVar5);
      if (pDacl == (PACL)0x0) {
                    /* WARNING: Subroutine does not return */
        ATL::PrivateAtlThrow(-0x7ff8fff2);
      }
      _Src = ATL::CAcl::GetPACL((CAcl *)&local_168);
      eVar6 = memcpy_s(pDacl,(ulonglong)uVar5,_Src,(ulonglong)uVar5);
      ATL::AtlCrtErrorCheck(eVar6);
      goto LAB_14000291f;
    }
  }
  pDacl = (PACL)0x0;
LAB_14000291f:
  if ((local_158 == '\0') && (pDacl == (PACL)0x0)) {
    BVar7 = 0;
  }
  BVar7 = SetSecurityDescriptorDacl(local_178,BVar7,pDacl,0);
  if (BVar7 == 0) {
    lVar8 = ATL::AtlHresultFromLastError();
    free(pDacl);
                    /* WARNING: Subroutine does not return */
    ATL::PrivateAtlThrow(lVar8);
  }
  free(local_130);
  iVar4 = 0;
  _Var11 = 0xffffffff;
  HVar9 = CoInitializeSecurity
                    (local_178,-1,(SOLE_AUTHENTICATION_SERVICE *)0x0,(void *)0x0,6,2,(void *)0x0,0,
                     (void *)0x0);
  local_168 = &ATL::CDacl::_vftable_;
  ATL::
  CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
  ::SetCount((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
              *)&local_150,_Var11,iVar4);
  free(local_160);
  local_160 = (void *)0x0;
  ATL::
  CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
  ::
  ~CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
            ((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
              *)&local_150);
  local_168 = &ATL::CAcl::_vftable_;
  free(local_160);
  local_180 = &ATL::CSecurityDesc::_vftable_;
  ATL::CSecurityDesc::Clear((CSecurityDesc *)&local_180);
  return HVar9;
}



===== ~CSid @ 140002ab0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual __cdecl ATL::CSid::~CSid(void) __ptr64 */

void __thiscall ATL::CSid::~CSid(CSid *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(this + 0x70);
  *(undefined ***)this = &_vftable_;
  LOCK();
  piVar1 = (int *)(lVar3 + -8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)(lVar3 + -0x18) + 8))();
  }
  lVar3 = *(longlong *)(this + 0x68);
  LOCK();
  piVar1 = (int *)(lVar3 + -8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)(lVar3 + -0x18) + 8))();
  }
  lVar3 = *(longlong *)(this + 0x60);
  LOCK();
  piVar1 = (int *)(lVar3 + -8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)(lVar3 + -0x18) + 8))();
  }
  lVar3 = *(longlong *)(this + 0x58);
  LOCK();
  piVar1 = (int *)(lVar3 + -8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)(lVar3 + -0x18) + 8))();
  }
  return;
}



===== SetCount @ 140002b70 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: bool __cdecl ATL::CAtlArray<class ATL::CAutoPtr<class ATL::CDacl::CAccessAce>,class
   ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce> >::SetCount(unsigned __int64,int)
   __ptr64 */

bool __thiscall
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::SetCount(CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
           *this,__uint64 param_1,int param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)this;
  if (lVar1 != 0) {
    uVar4 = 0;
    uVar2 = *(ulonglong *)(this + 8);
    if (uVar2 != 0) {
      do {
        puVar3 = *(undefined8 **)(lVar1 + uVar4 * 8);
        if (puVar3 != (undefined8 *)0x0) {
          (**(code **)*puVar3)(puVar3,1);
        }
        *(undefined8 *)(lVar1 + uVar4 * 8) = 0;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    free(*(void **)this);
    *(undefined8 *)this = 0;
  }
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  return true;
}



===== Clear @ 140002c10 =====

/* protected: virtual void __cdecl ATL::CSecurityDesc::Clear(void) __ptr64 */

void __thiscall ATL::CSecurityDesc::Clear(CSecurityDesc *this)

{
  BOOL BVar1;
  WORD local_res8 [4];
  DWORD local_res10 [2];
  BOOL local_res18 [2];
  PSID local_res20;
  PSID local_38;
  PACL local_30;
  PACL local_28 [2];
  
  if (*(PSECURITY_DESCRIPTOR *)(this + 8) != (PSECURITY_DESCRIPTOR)0x0) {
    local_res10[0] = 0;
    local_res8[0] = 0;
    BVar1 = GetSecurityDescriptorControl(*(PSECURITY_DESCRIPTOR *)(this + 8),local_res8,local_res10)
    ;
    if ((BVar1 != 0) && ((local_res8[0] & 0x8000) == 0)) {
      local_res20 = (void *)0x0;
      local_38 = (void *)0x0;
      local_30 = (PACL)0x0;
      local_28[0] = (PACL)0x0;
      local_res10[0] = 0;
      local_res18[0] = 0;
      GetSecurityDescriptorOwner
                (*(PSECURITY_DESCRIPTOR *)(this + 8),&local_res20,(LPBOOL)local_res10);
      free(local_res20);
      GetSecurityDescriptorGroup(*(PSECURITY_DESCRIPTOR *)(this + 8),&local_38,(LPBOOL)local_res10);
      free(local_38);
      GetSecurityDescriptorDacl
                (*(PSECURITY_DESCRIPTOR *)(this + 8),local_res18,&local_30,(LPBOOL)local_res10);
      if (local_res18[0] != 0) {
        free(local_30);
      }
      GetSecurityDescriptorSacl
                (*(PSECURITY_DESCRIPTOR *)(this + 8),local_res18,local_28,(LPBOOL)local_res10);
      if (local_res18[0] != 0) {
        free(local_28[0]);
      }
    }
    free(*(void **)(this + 8));
    *(undefined8 *)(this + 8) = 0;
  }
  return;
}



===== CSid @ 140002d60 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl ATL::CSid::CSid(struct _SID_IDENTIFIER_AUTHORITY const & __ptr64,unsigned
   char,...) __ptr64 */

CSid * __thiscall ATL::CSid::CSid(CSid *this,_SID_IDENTIFIER_AUTHORITY *param_1,uchar param_2,...)

{
  DWORD DVar1;
  DWORD DVar2;
  BOOL BVar3;
  long lVar4;
  longlong lVar5;
  PDWORD pDVar6;
  undefined8 in_R9;
  DWORD *pDVar7;
  byte local_res18 [8];
  undefined8 local_res20;
  undefined1 auStack_b8 [32];
  CSid *local_98;
  undefined1 local_88 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  *(undefined ***)this = &_vftable_;
  this[0x4c] = (CSid)0x0;
  *(undefined4 *)(this + 0x50) = 7;
  local_res18[0] = param_2;
  local_res20 = in_R9;
  local_98 = this;
  lVar5 = (**(code **)(g_strmgr + 0x18))(&g_strmgr);
  *(longlong *)(this + 0x58) = lVar5 + 0x18;
  lVar5 = (**(code **)(g_strmgr + 0x18))(&g_strmgr);
  *(longlong *)(this + 0x60) = lVar5 + 0x18;
  lVar5 = (**(code **)(g_strmgr + 0x18))(&g_strmgr);
  *(longlong *)(this + 0x68) = lVar5 + 0x18;
  lVar5 = (**(code **)(g_strmgr + 0x18))(&g_strmgr);
  *(longlong *)(this + 0x70) = lVar5 + 0x18;
  if (local_res18[0] != 0) {
    DVar2 = GetSidLengthRequired(local_res18[0]);
    if (DVar2 < 0x45) {
      BVar3 = InitializeSid(local_88,param_1,local_res18[0]);
      if (BVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        AtlThrowLastWin32();
      }
      DVar2 = 0;
      if (local_res18[0] != 0) {
        pDVar7 = (DWORD *)local_res18;
        do {
          pDVar7 = pDVar7 + 2;
          DVar1 = *pDVar7;
          pDVar6 = GetSidSubAuthority(local_88,DVar2);
          *pDVar6 = DVar1;
          DVar2 = DVar2 + 1;
        } while (DVar2 < local_res18[0]);
      }
      BVar3 = IsValidSid(local_88);
      if (BVar3 != 0) {
        DVar2 = GetLengthSid(local_88);
        if (DVar2 < 0x45) {
          this[0x4c] = (CSid)0x1;
          BVar3 = CopySid(DVar2,this + 8,local_88);
          if (BVar3 == 0) {
            lVar4 = AtlHresultFromLastError();
            this[0x4c] = (CSid)0x0;
                    /* WARNING: Subroutine does not return */
            PrivateAtlThrow(lVar4);
          }
          *(undefined4 *)(this + 0x50) = 8;
          return this;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7ff8ffa9);
}



===== AddAllowedAce @ 140002f50 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: bool __cdecl ATL::CDacl::AddAllowedAce(class ATL::CSid const & __ptr64,unsigned
   long,unsigned char) __ptr64 */

bool __thiscall ATL::CDacl::AddAllowedAce(CDacl *this,CSid *param_1,ulong param_2,uchar param_3)

{
  ulonglong uVar1;
  bool bVar2;
  BOOL BVar3;
  CAccessAce *this_00;
  longlong lVar4;
  undefined1 in_stack_ffffffffffffffc8;
  
  if ((param_1[0x4c] == (CSid)0x0) || (BVar3 = IsValidSid(param_1 + 8), BVar3 == 0)) {
    return false;
  }
  if (this[0x10] != (CDacl)0x0) {
    (**(code **)(*(longlong *)this + 0x10))(this);
    this[0x10] = (CDacl)0x0;
  }
  this_00 = operator_new(0x98);
  if (this_00 == (CAccessAce *)0x0) {
    lVar4 = 0;
  }
  else {
    lVar4 = CAccessAce::CAccessAce(this_00,param_1,param_2,param_3,(bool)in_stack_ffffffffffffffc8);
  }
  if ((lVar4 != 0) &&
     ((uVar1 = *(ulonglong *)(this + 0x20), uVar1 < *(ulonglong *)(this + 0x28) ||
      (bVar2 = CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
               ::GrowBuffer((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
                             *)(this + 0x18),uVar1 + 1), bVar2)))) {
    *(longlong *)(*(longlong *)(this + 0x18) + uVar1 * 8) = lVar4;
    *(longlong *)(this + 0x20) = *(longlong *)(this + 0x20) + 1;
    free(*(void **)(this + 8));
    *(undefined8 *)(this + 8) = 0;
    return true;
  }
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7ff8fff2);
}



===== ~CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_> @ 140003070 =====

/* public: __cdecl ATL::CAtlArray<class ATL::CAutoPtr<class ATL::CDacl::CAccessAce>,class
   ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce> >::~CAtlArray<class ATL::CAutoPtr<class
   ATL::CDacl::CAccessAce>,class ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce> >(void)
   __ptr64 */

void __thiscall
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::
~CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
          (CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
           *this)

{
  if (*(CAutoPtr<ATL::CDacl::CAccessAce> **)this != (CAutoPtr<ATL::CDacl::CAccessAce> *)0x0) {
    CallDestructors(*(CAutoPtr<ATL::CDacl::CAccessAce> **)this,*(__uint64 *)(this + 8));
    free(*(void **)this);
  }
  return;
}



===== AllocateAndInitializeSecurityDescriptor @ 1400030b0 =====

/* protected: void __cdecl ATL::CSecurityDesc::AllocateAndInitializeSecurityDescriptor(void) __ptr64
    */

void __thiscall ATL::CSecurityDesc::AllocateAndInitializeSecurityDescriptor(CSecurityDesc *this)

{
  BOOL BVar1;
  long lVar2;
  void *pSecurityDescriptor;
  
  pSecurityDescriptor = malloc(0x28);
  *(void **)(this + 8) = pSecurityDescriptor;
  if (pSecurityDescriptor == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8fff2);
  }
  BVar1 = InitializeSecurityDescriptor(pSecurityDescriptor,1);
  if (BVar1 == 0) {
    lVar2 = AtlHresultFromLastError();
    free(*(void **)(this + 8));
    *(undefined8 *)(this + 8) = 0;
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(lVar2);
  }
  return;
}



===== CAccessAce @ 140003140 =====

/* public: __cdecl ATL::CDacl::CAccessAce::CAccessAce(class ATL::CSid const & __ptr64,unsigned
   long,unsigned char,bool) __ptr64 */

CAccessAce * __thiscall
ATL::CDacl::CAccessAce::CAccessAce
          (CAccessAce *this,CSid *param_1,ulong param_2,uchar param_3,bool param_4)

{
  bool bVar1;
  DWORD nDestinationSidLength;
  BOOL BVar2;
  long lVar3;
  CStringData *pCVar4;
  
  *(undefined ***)this = &CAcl::CAce::_vftable_;
  *(undefined ***)(this + 8) = &CSid::_vftable_;
  this[0x54] = *(CAccessAce *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x50);
  pCVar4 = CSimpleStringT<unsigned_short,0>::CloneData
                     ((CStringData *)(*(longlong *)(param_1 + 0x58) + -0x18));
  *(CStringData **)(this + 0x60) = pCVar4 + 0x18;
  pCVar4 = CSimpleStringT<unsigned_short,0>::CloneData
                     ((CStringData *)(*(longlong *)(param_1 + 0x60) + -0x18));
  *(CStringData **)(this + 0x68) = pCVar4 + 0x18;
  pCVar4 = CSimpleStringT<unsigned_short,0>::CloneData
                     ((CStringData *)(*(longlong *)(param_1 + 0x68) + -0x18));
  *(CStringData **)(this + 0x70) = pCVar4 + 0x18;
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(this + 0x78));
  if (param_1[0x4c] != (CSid)0x0) {
    bVar1 = CSid::IsValid(param_1);
    if (!bVar1) {
                    /* WARNING: Subroutine does not return */
      PrivateAtlThrow(-0x7ff8ffa9);
    }
    nDestinationSidLength = GetLengthSid(param_1 + 8);
    BVar2 = CopySid(nDestinationSidLength,this + 0x10,param_1 + 8);
    if (BVar2 == 0) {
      lVar3 = AtlHresultFromLastError();
                    /* WARNING: Subroutine does not return */
      PrivateAtlThrow(lVar3);
    }
  }
  *(undefined4 *)(this + 0x80) = 0x200ffff;
  this[0x84] = (CAccessAce)0x0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined ***)this = &_vftable_;
  this[0x90] = (CAccessAce)0x1;
  return this;
}



===== CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_> @ 140003270 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void) __ptr64 */

CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_> *
__thiscall
ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
          (CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
           *this)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(g_strmgr + 0x18))(&g_strmgr);
  *(longlong *)this = lVar1 + 0x18;
  return this;
}



===== CloneData @ 1400032b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static struct ATL::CStringData * __ptr64 __cdecl ATL::CSimpleStringT<unsigned
   short,0>::CloneData(struct ATL::CStringData * __ptr64) */

CStringData * __cdecl ATL::CSimpleStringT<unsigned_short,0>::CloneData(CStringData *param_1)

{
  code *pcVar1;
  rsize_t _DstSize;
  undefined8 *puVar2;
  CStringData *pCVar3;
  
  puVar2 = (undefined8 *)(**(code **)(**(longlong **)param_1 + 0x20))();
  if ((-1 < *(int *)(param_1 + 0x10)) && (puVar2 == *(undefined8 **)param_1)) {
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
    return param_1;
  }
  pCVar3 = (CStringData *)(**(code **)*puVar2)(puVar2,*(undefined4 *)(param_1 + 8),2);
  if (pCVar3 == (CStringData *)0x0) {
    ThrowMemoryException();
    pcVar1 = (code *)swi(3);
    pCVar3 = (CStringData *)(*pcVar1)();
    return pCVar3;
  }
  *(undefined4 *)(pCVar3 + 8) = *(undefined4 *)(param_1 + 8);
  _DstSize = (longlong)(*(int *)(param_1 + 8) + 1) * 2;
  memcpy_s(pCVar3 + 0x18,_DstSize,param_1 + 0x18,_DstSize);
  return pCVar3;
}



===== IsValid @ 140003350 =====

/* public: bool __cdecl ATL::CSid::IsValid(void)const __ptr64 */

bool __thiscall ATL::CSid::IsValid(CSid *this)

{
  BOOL BVar1;
  bool bVar2;
  
  if (this[0x4c] == (CSid)0x0) {
    bVar2 = false;
  }
  else {
    BVar1 = IsValidSid(this + 8);
    bVar2 = BVar1 != 0;
  }
  return bVar2;
}



===== GrowBuffer @ 140003380 =====

/* private: bool __cdecl ATL::CAtlArray<class ATL::CAutoPtr<class ATL::CDacl::CAccessAce>,class
   ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce> >::GrowBuffer(unsigned __int64) __ptr64
    */

bool __thiscall
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::GrowBuffer(CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
             *this,__uint64 param_1)

{
  ulonglong uVar1;
  bool bVar2;
  errno_t eVar3;
  void *pvVar4;
  void *_Dst;
  ulonglong uVar5;
  
  uVar1 = *(ulonglong *)(this + 0x10);
  if (uVar1 < param_1) {
    pvVar4 = *(void **)this;
    uVar5 = (ulonglong)*(int *)(this + 0x18);
    if (pvVar4 == (void *)0x0) {
      if (param_1 < uVar5) {
        param_1 = uVar5;
      }
      pvVar4 = calloc(param_1,8);
      *(void **)this = pvVar4;
      if (pvVar4 != (void *)0x0) {
LAB_14000343a:
        *(__uint64 *)(this + 0x10) = param_1;
        goto LAB_14000343e;
      }
    }
    else {
      if (uVar5 == 0) {
        uVar5 = uVar1 >> 1;
        if (uVar1 >> 1 < param_1 - uVar1) {
          uVar5 = param_1 - uVar1;
        }
      }
      if (param_1 < uVar1 + uVar5) {
        param_1 = uVar1 + uVar5;
      }
      _Dst = calloc(param_1,8);
      if (_Dst != (void *)0x0) {
        eVar3 = memmove_s(_Dst,*(longlong *)(this + 8) << 3,pvVar4,*(longlong *)(this + 8) << 3);
        AtlCrtErrorCheck(eVar3);
        free(*(void **)this);
        *(void **)this = _Dst;
        goto LAB_14000343a;
      }
    }
    bVar2 = false;
  }
  else {
LAB_14000343e:
    bVar2 = true;
  }
  return bVar2;
}



===== AtlCrtErrorCheck @ 140003480 =====

/* int __cdecl ATL::AtlCrtErrorCheck(int) */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  if ((param_1 == 0x50) || (param_1 == 0)) {
    return param_1;
  }
  if (param_1 == 0xc) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8fff2);
  }
  if ((param_1 == 0x16) || (param_1 == 0x22)) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8ffa9);
  }
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7fffbffb);
}



===== StopComTask @ 1400034d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __cdecl ComTaskMgrBase::[ComTaskMgr]::StopComTask(void * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall ComTaskMgrBase::[ComTaskMgr]::StopComTask(_ComTaskMgr_ *this,void **param_1)

{
  int iVar1;
  long lVar2;
  bool bVar3;
  
  LOCK();
  UNLOCK();
  LOCK();
  _s_sync = _s_sync + 1;
  UNLOCK();
  LOCK();
  bVar3 = DAT_1400159a4 == 0;
  if (bVar3) {
    DAT_1400159a4 = 0;
  }
  UNLOCK();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  if (bVar3) {
    lVar2 = -0x7ff8fd7f;
  }
  else {
    lVar2 = ComTaskHost::Stop(*param_1);
  }
  LOCK();
  UNLOCK();
  LOCK();
  iVar1 = _s_sync + -1;
  UNLOCK();
  bVar3 = _s_sync == 1;
  _s_sync = iVar1;
  if (bVar3) {
    LOCK();
    if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
      _s_hEvent = (HANDLE)0xffffffffffffffff;
    }
    UNLOCK();
    SetEvent(_s_hEvent);
  }
  *param_1 = (void *)0x0;
  return lVar2;
}



===== Stop @ 140003580 =====

/* public: long __cdecl ComTaskHost::Stop(void) __ptr64 */

long __thiscall ComTaskHost::Stop(ComTaskHost *this)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  HANDLE hHandle;
  bool bVar5;
  DWORD local_res8 [4];
  HANDLE local_res18;
  
  DVar3 = 0;
  local_res8[0] = 0;
  local_res18 = (HANDLE)0x0;
  LOCK();
  bVar5 = *(int *)(this + 0x10) == 1;
  if (bVar5) {
    *(int *)(this + 0x10) = 8;
  }
  UNLOCK();
  if (!bVar5) {
    iVar2 = 5;
    LOCK();
    iVar1 = *(int *)(this + 0x10);
    if (iVar1 == 5) {
      *(int *)(this + 0x10) = 8;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
    if ((iVar2 != 4) && (iVar2 != 7)) {
      iVar2 = 2;
      LOCK();
      iVar1 = *(int *)(this + 0x10);
      if (iVar1 == 2) {
        *(int *)(this + 0x10) = 8;
      }
      else {
        iVar2 = iVar1;
      }
      UNLOCK();
      if ((iVar2 != 4) && (iVar2 != 7)) goto LAB_140003730;
    }
    ReleaseLifetimeRef(this,(ushort *)L"Stop");
    goto LAB_140003730;
  }
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,StopTaskThread,this,0,(LPDWORD)0x0);
  local_res18 = hHandle;
  if (hHandle == (HANDLE)0x0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar3) {
      DVar3 = 0x80004005;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x11,
                &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(char)DVar3);
    }
    WaitForTaskStartCompletion(this);
    ReleaseLifetimeRef(this,(ushort *)L"Stop");
LAB_1400036fd:
    if (-1 < (int)DVar3) goto LAB_140003730;
  }
  else {
    local_res8[0] = WaitForSingleObject(hHandle,0xffffffff);
    if (local_res8[0] == 0) {
      BVar4 = GetExitCodeThread(hHandle,local_res8);
      if (BVar4 != 0) {
        DVar3 = local_res8[0];
        goto LAB_1400036fd;
      }
      DVar3 = GetLastError();
      if (0 < (int)DVar3) goto LAB_1400036b9;
    }
    else {
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
LAB_1400036b9:
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
    }
    if (-1 < (int)DVar3) {
      DVar3 = 0x80004005;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x12,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(char)DVar3);
  }
LAB_140003730:
  if ((longlong)local_res18 - 1U < 0xfffffffffffffffe) {
    CloseHandle(local_res18);
  }
  return DVar3;
}



===== ShutdownTasksThreadProc @ 140003760 =====

/* private: static unsigned long __cdecl ComTaskMgrWnd::ShutdownTasksThreadProc(void * __ptr64) */

ulong __cdecl ComTaskMgrWnd::ShutdownTasksThreadProc(void *param_1)

{
  ShutdownTasksWorker((ComTaskMgrWnd *)ComTaskMgrBase::s_pVirtualSingleton);
  return 0;
}



===== WndProc @ 140003780 =====

/* private: static __int64 __cdecl ComTaskMgrWnd::WndProc(struct HWND__ * __ptr64,unsigned
   int,unsigned __int64,__int64) */

__int64 __cdecl
ComTaskMgrWnd::WndProc(HWND__ *param_1,uint param_2,__uint64 param_3,__int64 param_4)

{
  __int64 _Var1;
  
  switch(param_2) {
  case 2:
    PostQuitMessage(0);
  case 1:
  case 0xc:
    _Var1 = 0;
    break;
  case 0x11:
  case 0x16:
    Shutdown((ComTaskMgrWnd *)ComTaskMgrBase::s_pVirtualSingleton,(uint)(param_2 == 0x11));
  default:
    _Var1 = DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  return _Var1;
}



===== UninitSingleton @ 140003850 =====

/* private: virtual long __cdecl ComTaskMgrBase::UninitSingleton(void) __ptr64 */

long __thiscall ComTaskMgrBase::UninitSingleton(ComTaskMgrBase *this)

{
  WaitForShutdownGuards();
  return 0;
}



===== MsgPumpThreadProc @ 140003870 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: static unsigned long __cdecl ComTaskMgrWnd::MsgPumpThreadProc(void * __ptr64) */

ulong __cdecl ComTaskMgrWnd::MsgPumpThreadProc(void *param_1)

{
  bool bVar1;
  ComTaskMgrBase *this;
  long lVar2;
  DWORD DVar3;
  int iVar4;
  BOOL BVar5;
  __uint64 _Var6;
  ComTaskMgrBase *pCVar7;
  tagMSG local_68;
  tagMSG local_38;
  
  lVar2 = CreateWnd((ComTaskMgrWnd *)ComTaskMgrBase::s_pVirtualSingleton);
  pCVar7 = ComTaskMgrBase::s_pVirtualSingleton;
  *(long *)(ComTaskMgrBase::s_pVirtualSingleton + 0x20) = lVar2;
  SetEvent(*(HANDLE *)(pCVar7 + 0x28));
  if (lVar2 < 0) {
    return 0;
  }
  bVar1 = true;
  do {
    pCVar7 = ComTaskMgrBase::s_pVirtualSingleton + 0x38;
    DVar3 = MsgWaitForMultipleObjects(1,(HANDLE *)pCVar7,0,0xffffffff,0x1dff);
    if (DVar3 == 0) break;
    if (DVar3 == 1) {
      pCVar7 = (ComTaskMgrBase *)0x0;
      local_68.hwnd = (HWND)0x0;
      local_68.message = 0;
      local_68._12_4_ = 0;
      local_68.wParam = 0;
      local_68.lParam = 0;
      local_68.time = 0;
      local_68.pt.x = 0;
      local_68.pt.y = 0;
      local_68._44_4_ = 0;
      iVar4 = PeekMessageW(&local_68,(HWND)0x0,0,0,1);
      while (iVar4 != 0) {
        TranslateMessage(&local_68);
        DispatchMessageW(&local_68);
        if (local_68.message == 0x12) {
          bVar1 = false;
        }
        pCVar7 = (ComTaskMgrBase *)0x0;
        iVar4 = PeekMessageW(&local_68,(HWND)0x0,0,0,1);
      }
    }
    else if (DVar3 == 0xffffffff) break;
  } while (bVar1);
  this = ComTaskMgrBase::s_pVirtualSingleton;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),pCVar7,
              &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,ComTaskMgrBase::s_pVirtualSingleton,
              L"LateShutdown");
  }
  iVar4 = 1;
  LOCK();
  if (DAT_1400159a4 == 1) {
    DAT_1400159a4 = 0;
  }
  else {
    iVar4 = DAT_1400159a4;
  }
  UNLOCK();
  if (iVar4 != 0) {
    ShutdownMgr::Unguard();
  }
  LOCK();
  if (_s_hEvent == -1) {
    _s_hEvent = -1;
  }
  UNLOCK();
  if (DAT_1400159d8 == 0) {
    if (DAT_1400159d4 != 0) goto LAB_140003a7e;
  }
  else {
    if (DAT_1400159d4 != 0) goto LAB_140003a7e;
    if (*(longlong *)(this + 0x40) != 0) {
      while( true ) {
        iVar4 = ComTaskMgrBase::IsDebuggerBreakForTaskHangEnabled();
        DVar3 = 30000;
        if (iVar4 == 0) {
          DVar3 = 0xffffffff;
        }
        DVar3 = WaitForSingleObject(*(HANDLE *)(this + 0x40),DVar3);
        if (DVar3 == 0) goto LAB_140003a6c;
        if (DVar3 != 0x102) break;
        ComTaskMgrBase::DebuggerBreakForTaskHang(0);
      }
      GetLastError();
LAB_140003a6c:
      if ((longlong)*(HANDLE *)(this + 0x40) - 1U < 0xfffffffffffffffe) {
        CloseHandle(*(HANDLE *)(this + 0x40));
        *(undefined8 *)(this + 0x40) = 0;
      }
      goto LAB_140003a7e;
    }
  }
  _Var6 = CleanupSet::Size((CleanupSet *)(this + 0x48));
  if (_Var6 != 0) {
    ShutdownTasksWorker((ComTaskMgrWnd *)this);
  }
LAB_140003a7e:
  pCVar7 = ComTaskMgrBase::s_pVirtualSingleton;
  DAT_1400159d4 = 1;
  DestroyWindow(*(HWND *)(ComTaskMgrBase::s_pVirtualSingleton + 0x18));
  local_38.hwnd = (HWND)0x0;
  local_38.message = 0;
  local_38._12_4_ = 0;
  *(undefined8 *)(pCVar7 + 0x18) = 0;
  local_38.wParam = 0;
  local_38.lParam = 0;
  local_38.time = 0;
  local_38.pt.x = 0;
  local_38.pt.y = 0;
  local_38._44_4_ = 0;
  do {
    BVar5 = PeekMessageW(&local_38,(HWND)0x0,0,0,1);
  } while (BVar5 != 0);
  if (*(ushort *)(pCVar7 + 0x10) != 0) {
    UnregisterClassW((LPCWSTR)(ulonglong)*(ushort *)(pCVar7 + 0x10),*(HINSTANCE *)(pCVar7 + 8));
    *(undefined2 *)(pCVar7 + 0x10) = 0;
  }
  ComTaskMgrBase::WaitForShutdownGuards();
  return 0;
}



===== CreateWnd @ 140003b90 =====

/* private: long __cdecl ComTaskMgrWnd::CreateWnd(void) __ptr64 */

long __thiscall ComTaskMgrWnd::CreateWnd(ComTaskMgrWnd *this)

{
  ATOM AVar1;
  DWORD DVar2;
  HWND pHVar3;
  WNDCLASSW local_58;
  
  local_58.lpfnWndProc = WndProc;
  local_58.hInstance = *(HINSTANCE *)(this + 8);
  local_58.style = 0;
  local_58._4_4_ = 0;
  local_58.lpszClassName = L"COMTASKSWINDOWCLASS";
  local_58.cbClsExtra = 0;
  local_58.cbWndExtra = 0;
  local_58.hIcon = (HICON)0x0;
  local_58.hCursor = (HCURSOR)0x0;
  local_58.hbrBackground = (HBRUSH)0x0;
  local_58.lpszMenuName = (LPCWSTR)0x0;
  AVar1 = RegisterClassW(&local_58);
  *(ATOM *)(this + 0x10) = AVar1;
  if (AVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar2) {
      return DVar2;
    }
  }
  else {
    pHVar3 = CreateWindowExW(0,(LPCWSTR)(ulonglong)AVar1,L"Task Host Window",0,0,0,0,0,(HWND)0x0,
                             (HMENU)0x0,*(HINSTANCE *)(this + 8),(LPVOID)0x0);
    *(HWND *)(this + 0x18) = pHVar3;
    if (pHVar3 != (HWND)0x0) {
      return 0;
    }
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if (-1 < (int)DVar2) {
      DVar2 = 0x8007000e;
    }
  }
  if (*(ushort *)(this + 0x10) != 0) {
    UnregisterClassW((LPCWSTR)(ulonglong)*(ushort *)(this + 0x10),*(HINSTANCE *)(this + 8));
    *(undefined2 *)(this + 0x10) = 0;
  }
  return DVar2;
}



===== WaitForShutdownGuards @ 140003cd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: static long __cdecl ComTaskMgrBase::WaitForShutdownGuards(void) */

long __cdecl ComTaskMgrBase::WaitForShutdownGuards(void)

{
  code *pcVar1;
  HANDLE hHandle;
  int iVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  BOOL BVar5;
  long lVar6;
  bool bVar7;
  int local_res8 [2];
  DWORD local_res10 [2];
  
  iVar2 = 1;
  LOCK();
  if (DAT_1400159a4 == 1) {
    DAT_1400159a4 = 0;
  }
  else {
    iVar2 = DAT_1400159a4;
  }
  UNLOCK();
  if (iVar2 != 0) {
    ShutdownMgr::Unguard();
  }
  LOCK();
  if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
    _s_hEvent = (HANDLE)0xffffffffffffffff;
  }
  hHandle = _s_hEvent;
  UNLOCK();
  while( true ) {
    local_res8[0] = 0;
    local_res10[0] = 4;
    LVar3 = RegGetValueW((HKEY)0xffffffff80000002,
                         L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule",
                         L"EnableDebuggerBreakForTaskHang",0x10,(LPDWORD)0x0,local_res8,local_res10)
    ;
    if (LVar3 == 0) {
      bVar7 = local_res8[0] != 0;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
                 &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,LVar3);
      }
      bVar7 = false;
    }
    DVar4 = 20000;
    if (!bVar7) {
      DVar4 = 0xffffffff;
    }
    DVar4 = WaitForSingleObject(hHandle,DVar4);
    if (DVar4 == 0) break;
    if (DVar4 != 0x102) {
      DVar4 = GetLastError();
      if (0 < (int)DVar4) {
        DVar4 = DVar4 & 0xffff | 0x80070000;
      }
      if ((int)DVar4 < 0) {
        return DVar4;
      }
      return -0x7fffbffb;
    }
    BVar5 = IsDebuggerPresent();
    if ((BVar5 != 0) || (DAT_7ffe02d4 != '\0')) {
      DbgPrintEx(0x1c,0,
                 "\n================================================================================================\nWARNING: A possible task hung was detected for a COM-based scheduled task!\nThe likely culprit task is stuck on the same stack with %S.\nThis break is recoverable. If you let it go we will continue to wait on the task to complete.\n================================================================================================\n\n"
                 ,L"ComTaskHost::StartTaskWorker or ComTaskHost::StopTaskWorker");
      pcVar1 = (code *)swi(3);
      lVar6 = (*pcVar1)();
      return lVar6;
    }
  }
  return 0;
}



===== Shutdown @ 140003e60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: long __cdecl ComTaskMgrWnd::Shutdown(int) __ptr64 */

long __thiscall ComTaskMgrWnd::Shutdown(ComTaskMgrWnd *this,int param_1)

{
  long lVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  __uint64 _Var5;
  wchar_t *pwVar6;
  
  DVar4 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    pwVar6 = L"EarlyShutdown";
    if (param_1 == 0) {
      pwVar6 = L"LateShutdown";
    }
    WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),L"LateShutdown",
              &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,this,pwVar6);
  }
  iVar2 = 1;
  LOCK();
  if (DAT_1400159a4 == 1) {
    DAT_1400159a4 = 0;
  }
  else {
    iVar2 = DAT_1400159a4;
  }
  UNLOCK();
  if (iVar2 != 0) {
    ShutdownMgr::Unguard();
  }
  LOCK();
  if (_s_hEvent == -1) {
    _s_hEvent = -1;
  }
  UNLOCK();
  if (DAT_1400159d8 == 0) {
    if ((DAT_1400159d4 != 0) || (_Var5 = CleanupSet::Size((CleanupSet *)(this + 0x48)), _Var5 == 0))
    goto LAB_140003fa6;
    if (param_1 == 0) {
LAB_140003ef3:
      lVar1 = ShutdownTasksWorker(this);
      DAT_1400159d4 = 1;
      return lVar1;
    }
    DVar4 = CreateShutdownTasksThread(this);
LAB_140003faa:
    DAT_1400159d8 = 1;
  }
  else {
    if (DAT_1400159d4 == 0) {
      if (param_1 != 0) goto LAB_140003faa;
      if (*(longlong *)(this + 0x40) == 0) {
        _Var5 = CleanupSet::Size((CleanupSet *)(this + 0x48));
        if (_Var5 != 0) goto LAB_140003ef3;
      }
      else {
        while( true ) {
          iVar2 = ComTaskMgrBase::IsDebuggerBreakForTaskHangEnabled();
          DVar4 = 30000;
          if (iVar2 == 0) {
            DVar4 = 0xffffffff;
          }
          DVar3 = WaitForSingleObject(*(HANDLE *)(this + 0x40),DVar4);
          DVar4 = 0;
          if (DVar3 == 0) goto LAB_140003f72;
          if (DVar3 != 0x102) break;
          ComTaskMgrBase::DebuggerBreakForTaskHang(0);
        }
        DVar4 = GetLastError();
        if (0 < (int)DVar4) {
          DVar4 = DVar4 & 0xffff | 0x80070000;
        }
        if (-1 < (int)DVar4) {
          DVar4 = 0x80004005;
        }
LAB_140003f72:
        if ((longlong)*(HANDLE *)(this + 0x40) - 1U < 0xfffffffffffffffe) {
          CloseHandle(*(HANDLE *)(this + 0x40));
          *(undefined8 *)(this + 0x40) = 0;
        }
      }
    }
    else {
LAB_140003fa6:
      if (param_1 != 0) goto LAB_140003faa;
    }
    DAT_1400159d4 = 1;
  }
  return DVar4;
}



===== StartComTask @ 140004040 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __cdecl ComTaskMgrBase::[ComTaskMgr]::StartComTask(struct _GUID * __ptr64
   const,unsigned short * __ptr64,unsigned short * __ptr64,unsigned long,unsigned long,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall
ComTaskMgrBase::[ComTaskMgr]::StartComTask
          (_ComTaskMgr_ *this,_GUID *param_1,ushort *param_2,ushort *param_3,ulong param_4,
          ulong param_5,void **param_6)

{
  ComTaskHost *pCVar1;
  HANDLE hObject;
  code *pcVar2;
  undefined8 uVar3;
  ComTaskHost CVar4;
  int iVar5;
  BOOL BVar6;
  long lVar7;
  DWORD DVar8;
  ComTaskHost *this_00;
  undefined8 *puVar9;
  BSTR pOVar10;
  longlong lVar11;
  HANDLE pvVar12;
  longlong lVar13;
  ushort *puVar14;
  _GUID *p_Var15;
  char cVar16;
  bool bVar17;
  
  LOCK();
  UNLOCK();
  LOCK();
  _s_sync = _s_sync + 1;
  UNLOCK();
  LOCK();
  bVar17 = DAT_1400159a4 == 0;
  if (bVar17) {
    DAT_1400159a4 = 0;
  }
  UNLOCK();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  if (bVar17) {
    lVar7 = -0x7ff8fd7f;
    goto LAB_1400041a1;
  }
  p_Var15 = param_1;
  this_00 = operator_new(0x88);
  if (this_00 == (ComTaskHost *)0x0) {
    this_00 = (ComTaskHost *)0x0;
  }
  else {
    *(undefined ***)this_00 = &ComTaskHost::_vftable__for__ITaskHandlerStatus__;
    *(undefined ***)(this_00 + 8) = &ComTaskHost::_vftable__for__ITaskVariables__;
    cVar16 = '\x01';
    *(undefined4 *)(this_00 + 0x10) = 1;
    *(undefined4 *)(this_00 + 0x14) = 0;
    uVar3 = *(undefined8 *)param_1->Data4;
    *(undefined8 *)(this_00 + 0x18) = *(undefined8 *)param_1;
    *(undefined8 *)(this_00 + 0x20) = uVar3;
    puVar14 = (ushort *)0x18;
    puVar9 = operator_new(0x18);
    if (puVar9 == (undefined8 *)0x0) goto LAB_1400043b4;
    puVar9[1] = 0;
    *(undefined4 *)(puVar9 + 2) = 1;
    puVar14 = param_2;
    pOVar10 = SysAllocString((OLECHAR *)param_2);
    *puVar9 = pOVar10;
    if ((pOVar10 == (BSTR)0x0) && (param_2 != (ushort *)0x0)) {
      _com_raise_error((long)puVar14,(IErrorInfo *)p_Var15);
      goto LAB_1400043a5;
    }
LAB_140004120:
    *(undefined8 **)(this_00 + 0x28) = puVar9;
    if (puVar9 == (undefined8 *)0x0) {
      _com_raise_error((long)puVar14,(IErrorInfo *)p_Var15);
LAB_1400043ca:
      CVar4 = (ComTaskHost)0x1;
    }
    else {
      p_Var15 = (_GUID *)0x0;
      while (iVar5 = (int)p_Var15, iVar5 < 0xae) {
        lVar11 = *(longlong *)param_1 - *(longlong *)(&DAT_14000ed30 + (longlong)iVar5 * 0x10);
        if (lVar11 == 0) {
          lVar11 = *(longlong *)param_1->Data4 -
                   *(longlong *)(&DAT_14000ed38 + (longlong)iVar5 * 0x10);
        }
        if (lVar11 == 0) goto LAB_1400043ca;
        p_Var15 = (_GUID *)(ulonglong)(iVar5 + 1);
      }
      for (iVar5 = 0; iVar5 < 0x18; iVar5 = iVar5 + 1) {
        p_Var15 = (_GUID *)((longlong)iVar5 * 0x10);
        lVar11 = *(longlong *)param_1 - *(longlong *)(p_Var15 + 0x14000f81);
        if (lVar11 == 0) {
          lVar11 = *(longlong *)param_1->Data4 - *(longlong *)p_Var15[0x14000f81].Data4;
        }
        if (lVar11 == 0) break;
      }
      CVar4 = (ComTaskHost)0x0;
    }
    this_00[0x30] = CVar4;
    puVar14 = (ushort *)0x18;
    param_1 = operator_new(0x18);
    if (param_1 != (_GUID *)0x0) {
      param_1->Data4[0] = '\0';
      param_1->Data4[1] = '\0';
      param_1->Data4[2] = '\0';
      param_1->Data4[3] = '\0';
      param_1->Data4[4] = '\0';
      param_1->Data4[5] = '\0';
      param_1->Data4[6] = '\0';
      param_1->Data4[7] = '\0';
      param_1[1].Data1 = 1;
      puVar14 = param_3;
      pOVar10 = SysAllocString((OLECHAR *)param_3);
      *(BSTR *)param_1 = pOVar10;
      if (pOVar10 != (BSTR)0x0) goto LAB_1400041f0;
LAB_1400043a5:
      if (param_3 == (ushort *)0x0) goto LAB_1400041f0;
      _com_raise_error((long)puVar14,(IErrorInfo *)p_Var15);
LAB_1400043b4:
      puVar9 = (undefined8 *)0x0;
      goto LAB_140004120;
    }
    param_1 = (_GUID *)0x0;
LAB_1400041f0:
    *(_GUID **)(this_00 + 0x38) = param_1;
    if (param_1 == (_GUID *)0x0) {
      _com_raise_error((long)puVar14,(IErrorInfo *)p_Var15);
LAB_1400043de:
      WPP_SF_qd(*(undefined8 *)(puVar14 + 8),0xc,&WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids,
                this_00,cVar16);
    }
    else {
      *(ulong *)(this_00 + 0x40) = param_4;
      *(ulong *)(this_00 + 0x44) = param_5;
      *(undefined8 *)(this_00 + 0x48) = 0;
      LOCK();
      *(undefined8 *)(this_00 + 0x48) = 0;
      UNLOCK();
      *(undefined8 *)(this_00 + 0x50) = 0;
      LOCK();
      *(undefined8 *)(this_00 + 0x50) = 0;
      UNLOCK();
      *(undefined8 *)(this_00 + 0x58) = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)(this_00 + 0x60));
      LOCK();
      pCVar1 = this_00 + 0x14;
      iVar5 = *(int *)pCVar1;
      *(int *)pCVar1 = *(int *)pCVar1 + 1;
      UNLOCK();
      cVar16 = (char)iVar5 + '\x01';
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (puVar14 = (ushort *)WPP_GLOBAL_Control, (WPP_GLOBAL_Control[0x1c] & 4) != 0))
      goto LAB_1400043de;
    }
    (**(code **)(*(longlong *)s_pVirtualSingleton + 0x10))(s_pVirtualSingleton,this_00);
  }
  if (this_00 != (ComTaskHost *)0x0) {
    iVar5 = IsDebuggerBreakForTaskStartEnabled(param_2);
    if (iVar5 != 0) {
      BVar6 = IsDebuggerPresent();
      if ((BVar6 != 0) || (DAT_7ffe02d4 != '\0')) {
        DbgPrintEx(0x1c,0,
                   "\n\n======================================================================\nWARNING: This is not an error but a forced debug break enabled by setting the registry key\nHKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\EnableDebuggerBreakForTaskStart\nThis break is recoverable. If you let it go we will continue starting the task.\n======================================================================\n\n"
                  );
      }
      pcVar2 = (code *)swi(3);
      lVar7 = (*pcVar2)();
      return lVar7;
    }
    DVar8 = 0;
    (**(code **)(*(longlong *)this_00 + 8))(this_00);
    pvVar12 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,ComTaskHost::StartTaskThread,this_00,0,
                           (LPDWORD)0x0);
    LOCK();
    hObject = *(HANDLE *)(this_00 + 0x50);
    *(HANDLE *)(this_00 + 0x50) = pvVar12;
    UNLOCK();
    if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
      CloseHandle(hObject);
    }
    lVar13 = -1;
    LOCK();
    lVar11 = *(longlong *)(this_00 + 0x50);
    if (lVar11 == -1) {
      *(longlong *)(this_00 + 0x50) = -1;
    }
    else {
      lVar13 = lVar11;
    }
    UNLOCK();
    if (lVar13 == 0) {
      DVar8 = GetLastError();
      if (0 < (int)DVar8) {
        DVar8 = DVar8 & 0xffff | 0x80070000;
      }
      if (-1 < (int)DVar8) {
        DVar8 = 0x80004005;
      }
      (**(code **)(*(longlong *)this_00 + 0x10))(this_00);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
                  &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this_00,(char)DVar8);
      }
    }
    if (-1 < (int)DVar8) {
      *param_6 = this_00;
      LOCK();
      UNLOCK();
      LOCK();
      UNLOCK();
      if (_s_sync != 1) {
        _s_sync = _s_sync + -1;
        return DVar8;
      }
      LOCK();
      if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
        _s_hEvent = (HANDLE)0xffffffffffffffff;
      }
      UNLOCK();
      _s_sync = _s_sync + -1;
      SetEvent(_s_hEvent);
      return DVar8;
    }
    LOCK();
    UNLOCK();
    LOCK();
    iVar5 = _s_sync + -1;
    UNLOCK();
    bVar17 = _s_sync == 1;
    _s_sync = iVar5;
    if (bVar17) {
      LOCK();
      if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
        _s_hEvent = (HANDLE)0xffffffffffffffff;
      }
      UNLOCK();
      SetEvent(_s_hEvent);
    }
    ComTaskHost::ReleaseLifetimeRef(this_00,(ushort *)L"StartComTask");
    return DVar8;
  }
  lVar7 = -0x7ff8fff2;
LAB_1400041a1:
  LOCK();
  UNLOCK();
  ShutdownMgr::Unguard();
  return lVar7;
}



===== IsDebuggerBreakForTaskStartEnabled @ 1400044d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* protected: static int __cdecl ComTaskMgrBase::IsDebuggerBreakForTaskStartEnabled(unsigned short
   const * __ptr64) */

int __cdecl ComTaskMgrBase::IsDebuggerBreakForTaskStartEnabled(ushort *param_1)

{
  LSTATUS LVar1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined1 auStackY_278 [32];
  DWORD local_238 [4];
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_278;
  memset(local_228,0,0x20a);
  local_238[0] = 0x20a;
  LVar1 = RegGetValueW((HKEY)0xffffffff80000002,
                       L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule",
                       L"EnableDebuggerBreakForTaskStart",0x22,(LPDWORD)0x0,local_228,local_238);
  if (LVar1 == 0) {
    if (((param_1 == (ushort *)0x0) || (local_228[0] == L'\0')) || (*param_1 == 0)) {
      uVar3 = 1;
    }
    else {
      pwVar2 = wcsstr(local_228,(wchar_t *)param_1);
      uVar3 = (uint)(pwVar2 != (wchar_t *)0x0);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,
               &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,LVar1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== StopTaskWorker @ 1400045f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: long __cdecl ComTaskHost::StopTaskWorker(void) __ptr64 */

long __thiscall ComTaskHost::StopTaskWorker(ComTaskHost *this)

{
  longlong *plVar1;
  int nPriority;
  int iVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  longlong *plVar5;
  bool bVar6;
  int local_res10 [2];
  int local_res18;
  HANDLE local_28 [2];
  
  local_res10[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x13,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this);
  }
  iVar2 = WaitForTaskStartCompletion(this);
  if (-1 < iVar2) {
    iVar2 = *(int *)(this + 0x40);
    pvVar4 = GetCurrentThread();
    local_res18 = GetThreadPriority(pvVar4);
    if (local_res18 != 0x7fffffff) {
      pvVar4 = GetCurrentThread();
      BVar3 = SetThreadPriority(pvVar4,iVar2);
      if (BVar3 == 0) {
        local_res18 = 0x7fffffff;
      }
    }
    if (this[0x30] == (ComTaskHost)0x0) {
      ComCallAutoCancel::ComCallAutoCancel((ComCallAutoCancel *)local_28);
      plVar5 = (longlong *)0x0;
      LOCK();
      plVar1 = *(longlong **)(this + 0x48);
      if (plVar1 == (longlong *)0x0) {
        *(longlong *)(this + 0x48) = 0;
      }
      else {
        plVar5 = plVar1;
      }
      UNLOCK();
      iVar2 = (**(code **)(*plVar5 + 0x20))(plVar5,local_res10);
      if (local_28[0] != (HANDLE)0x0) {
        DeleteTimerQueueTimer((HANDLE)0x0,local_28[0],(HANDLE)0xffffffffffffffff);
        CoDisableCallCancellation((LPVOID)0x0);
      }
    }
    else {
      plVar5 = (longlong *)0x0;
      LOCK();
      plVar1 = *(longlong **)(this + 0x48);
      if (plVar1 == (longlong *)0x0) {
        *(longlong *)(this + 0x48) = 0;
      }
      else {
        plVar5 = plVar1;
      }
      UNLOCK();
      iVar2 = (**(code **)(*plVar5 + 0x20))(plVar5,local_res10);
    }
    nPriority = local_res18;
    if (local_res18 != 0x7fffffff) {
      pvVar4 = GetCurrentThread();
      SetThreadPriority(pvVar4,nPriority);
    }
    if (-1 < iVar2) {
      iVar2 = local_res10[0];
    }
  }
  if (iVar2 == -0x7ff8c373) {
    EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
    if (*(int *)(this + 0x58) == 0) {
      LOCK();
      bVar6 = *(int *)(this + 0x10) == 8;
      if (bVar6) {
        *(int *)(this + 0x10) = 1;
      }
      UNLOCK();
      if (!bVar6) {
        iVar2 = -0x7fff0001;
        LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
        goto LAB_1400046eb;
      }
    }
    else {
      iVar2 = *(int *)(this + 0x5c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
    if (iVar2 == -0x7ff8c373) goto LAB_140004777;
  }
LAB_1400046eb:
  ReleaseLifetimeRef(this,(ushort *)L"StopTaskWorker");
LAB_140004777:
  if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x14,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(char)iVar2);
  }
  return iVar2;
}



===== ReleaseLifetimeRef @ 140004850 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: unsigned long __cdecl ComTaskHost::ReleaseLifetimeRef(unsigned short const * __ptr64)
   __ptr64 */

ulong __thiscall ComTaskHost::ReleaseLifetimeRef(ComTaskHost *this,ushort *param_1)

{
  longlong *plVar1;
  ulong uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),param_1,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(wchar_t *)param_1);
  }
  LOCK();
  plVar1 = *(longlong **)(this + 0x48);
  *(longlong *)(this + 0x48) = 0;
  UNLOCK();
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 0x18))
            (ComTaskMgrBase::s_pVirtualSingleton,this);
  uVar2 = (**(code **)(*(longlong *)this + 0x10))(this);
  return uVar2;
}



===== Unguard @ 1400048e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* protected: static void __cdecl ShutdownMgr::Unguard(void) */

void __cdecl ShutdownMgr::Unguard(void)

{
  int iVar1;
  
  iVar1 = _s_sync;
  LOCK();
  _s_sync = _s_sync + -1;
  UNLOCK();
  if (iVar1 != 1) {
    return;
  }
  LOCK();
  if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
    _s_hEvent = (HANDLE)0xffffffffffffffff;
  }
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x000140004905. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetEvent(_s_hEvent);
  return;
}



===== WaitForTaskStartCompletion @ 140004920 =====

/* private: long __cdecl ComTaskHost::WaitForTaskStartCompletion(void) __ptr64 */

long __thiscall ComTaskHost::WaitForTaskStartCompletion(ComTaskHost *this)

{
  HANDLE pvVar1;
  uint uVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  uint local_res8 [2];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x15,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this);
  }
  pvVar4 = (HANDLE)0xffffffffffffffff;
  LOCK();
  pvVar1 = *(HANDLE *)(this + 0x50);
  if (pvVar1 == (HANDLE)0xffffffffffffffff) {
    *(longlong *)(this + 0x50) = -1;
  }
  else {
    pvVar4 = pvVar1;
  }
  UNLOCK();
  local_res8[0] = WaitForSingleObject(pvVar4,0xffffffff);
  if (local_res8[0] == 0) {
    pvVar4 = (HANDLE)0xffffffffffffffff;
    LOCK();
    pvVar1 = *(HANDLE *)(this + 0x50);
    if (pvVar1 == (HANDLE)0xffffffffffffffff) {
      *(longlong *)(this + 0x50) = -1;
    }
    else {
      pvVar4 = pvVar1;
    }
    UNLOCK();
    BVar3 = GetExitCodeThread(pvVar4,local_res8);
    if (BVar3 != 0) {
      uVar2 = local_res8[0];
      if (-1 < (int)local_res8[0]) {
        return local_res8[0];
      }
      goto LAB_1400049f2;
    }
    uVar2 = GetLastError();
  }
  else {
    uVar2 = GetLastError();
  }
  if (0 < (int)uVar2) {
    uVar2 = uVar2 & 0xffff | 0x80070000;
  }
  if (-1 < (int)uVar2) {
    uVar2 = 0x80004005;
  }
LAB_1400049f2:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x16,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(char)uVar2);
  }
  return uVar2;
}



===== Size @ 140004a3c =====

/* public: unsigned __int64 __cdecl ComTaskMgrWnd::CleanupSet::Size(void) __ptr64 */

__uint64 __thiscall ComTaskMgrWnd::CleanupSet::Size(CleanupSet *this)

{
  __uint64 _Var1;
  
  AcquireSRWLockExclusive((PSRWLOCK)this);
  _Var1 = *(__uint64 *)(this + 0x10);
  ReleaseSRWLockExclusive((PSRWLOCK)this);
  return _Var1;
}



===== IsDebuggerBreakForTaskHangEnabled @ 140004a80 =====

/* protected: static int __cdecl ComTaskMgrBase::IsDebuggerBreakForTaskHangEnabled(void) */

int __cdecl ComTaskMgrBase::IsDebuggerBreakForTaskHangEnabled(void)

{
  LSTATUS LVar1;
  uint uVar2;
  int local_res8 [2];
  DWORD local_res10 [6];
  
  local_res10[0] = 4;
  local_res8[0] = 0;
  LVar1 = RegGetValueW((HKEY)0xffffffff80000002,
                       L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule",
                       L"EnableDebuggerBreakForTaskHang",0x10,(LPDWORD)0x0,local_res8,local_res10);
  if (LVar1 == 0) {
    uVar2 = (uint)(local_res8[0] != 0);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
               &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,LVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== ComCallAutoCancel @ 140004b24 =====

/* public: __cdecl ComCallAutoCancel::ComCallAutoCancel(void) __ptr64 */

ComCallAutoCancel * __thiscall ComCallAutoCancel::ComCallAutoCancel(ComCallAutoCancel *this)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined2 uVar3;
  code *in_R8;
  
  *(undefined8 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  DVar1 = CoEnableCallCancellation((LPVOID)0x0);
  if ((int)DVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return this;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return this;
    }
    uVar3 = 10;
  }
  else {
    DVar1 = GetCurrentThreadId();
    in_R8 = TimerCallback;
    *(DWORD *)(this + 8) = DVar1;
    BVar2 = CreateTimerQueueTimer((PHANDLE)this,(HANDLE)0x0,TimerCallback,this,60000,0,8);
    if (BVar2 != 0) {
      return this;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return this;
    }
    if ((WPP_GLOBAL_Control[0x1c] & 1) == 0) {
      return this;
    }
    DVar1 = GetLastError();
    uVar3 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar3,in_R8,DVar1);
  return this;
}



===== ShutdownTasksWorker @ 140004c00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl ComTaskMgrWnd::ShutdownTasksWorker(void) __ptr64 */

long __thiscall ComTaskMgrWnd::ShutdownTasksWorker(ComTaskMgrWnd *this)

{
  ComTaskHost *this_00;
  int iVar1;
  BOOL BVar2;
  long lVar3;
  HMODULE hInstance;
  longlong lVar4;
  ushort *puVar5;
  undefined1 auStack_438 [32];
  WCHAR local_418 [512];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_438;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
             &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,this);
  }
  memset(local_418,0,0x400);
  hInstance = GetModuleHandleW((LPCWSTR)0x0);
  iVar1 = LoadStringW(hInstance,0xc9,local_418,0x200);
  if ((iVar1 == 0) ||
     (BVar2 = ShutdownBlockReasonCreate(*(HWND *)(this + 0x18),local_418), BVar2 == 0)) {
    GetLastError();
  }
  iVar1 = ComTaskMgrBase::WaitForShutdownGuards();
  if ((-1 < iVar1) && (iVar1 = CoInitializeEx((LPVOID)0x0,0), -1 < iVar1)) {
    while( true ) {
      AcquireSRWLockExclusive((PSRWLOCK)(this + 0x48));
      if (*(longlong *)(this + 0x58) == 0) break;
      this_00 = *(ComTaskHost **)(**(longlong **)(this + 0x50) + 0x20);
      ReleaseSRWLockExclusive((PSRWLOCK)(this + 0x48));
      if (this_00 == (ComTaskHost *)0x0) goto LAB_140004d86;
      lVar4 = (**(code **)(*(longlong *)this_00 + 0x30))(this_00);
      if (lVar4 != 0) {
        DestroyShutdownBlockMessage(this);
        puVar5 = (ushort *)(**(code **)(*(longlong *)this_00 + 0x30))(this_00);
        CreateShutdownBlockMessage(this,puVar5);
      }
      lVar3 = ComTaskHost::Shutdown(this_00);
      if ((iVar1 == 0) && (lVar3 < 0)) {
        iVar1 = lVar3;
      }
    }
    ReleaseSRWLockExclusive((PSRWLOCK)(this + 0x48));
LAB_140004d86:
    CoUninitialize();
    DestroyShutdownBlockMessage(this);
  }
  return iVar1;
}



===== DestroyShutdownBlockMessage @ 140004dd4 =====

/* private: long __cdecl ComTaskMgrWnd::DestroyShutdownBlockMessage(void)const __ptr64 */

long __thiscall ComTaskMgrWnd::DestroyShutdownBlockMessage(ComTaskMgrWnd *this)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = ShutdownBlockReasonDestroy(*(HWND *)(this + 0x18));
  if ((BVar1 == 0) && (DVar2 = GetLastError(), 0 < (int)DVar2)) {
    DVar2 = DVar2 & 0xffff | 0x80070000;
  }
  return DVar2;
}



===== CreateShutdownBlockMessage @ 140004e20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl ComTaskMgrWnd::CreateShutdownBlockMessage(unsigned short const *
   __ptr64)const __ptr64 */

long __thiscall ComTaskMgrWnd::CreateShutdownBlockMessage(ComTaskMgrWnd *this,ushort *param_1)

{
  WCHAR WVar1;
  int iVar2;
  DWORD DVar3;
  BOOL BVar4;
  HMODULE hInstance;
  longlong lVar5;
  WCHAR *pWVar6;
  WCHAR *pWVar7;
  __uint64 _Var8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_448 [32];
  WCHAR local_428 [512];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_448;
  memset(local_428,0,0x400);
  hInstance = GetModuleHandleW((LPCWSTR)0x0);
  _Var8 = 0xc9;
  iVar2 = LoadStringW(hInstance,0xc9,local_428,0x200);
  if (iVar2 != 0) {
    if (param_1 != (ushort *)0x0) {
      pWVar6 = local_428;
      lVar5 = 0x200;
      do {
        if (*pWVar6 == L'\0') break;
        pWVar6 = pWVar6 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      lVar9 = 0x7ffffffe;
      if (lVar5 != 0) {
        _Var8 = 0x200 - (0x200 - lVar5);
        pWVar6 = local_428 + (0x200 - lVar5);
        if (_Var8 != 0) {
          lVar5 = 0x7ffffffe;
          lVar10 = (longlong)L" (" - (longlong)pWVar6;
          do {
            if ((lVar5 == 0) || (WVar1 = *(WCHAR *)(lVar10 + (longlong)pWVar6), WVar1 == L'\0'))
            break;
            *pWVar6 = WVar1;
            lVar5 = lVar5 + -1;
            pWVar6 = pWVar6 + 1;
            _Var8 = _Var8 - 1;
          } while (_Var8 != 0);
        }
        pWVar7 = pWVar6 + -1;
        if (_Var8 != 0) {
          pWVar7 = pWVar6;
        }
        *pWVar7 = L'\0';
      }
      StringCchCatW((ushort *)local_428,_Var8,param_1);
      lVar5 = 0x200;
      pWVar6 = local_428;
      do {
        if (*pWVar6 == L'\0') break;
        pWVar6 = pWVar6 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      if (lVar5 != 0) {
        pWVar6 = local_428 + (0x200 - lVar5);
        lVar5 = 0x200 - (0x200 - lVar5);
        if (lVar5 != 0) {
          lVar10 = (longlong)L" )" - (longlong)pWVar6;
          do {
            if ((lVar9 == 0) || (WVar1 = *(WCHAR *)(lVar10 + (longlong)pWVar6), WVar1 == L'\0'))
            break;
            *pWVar6 = WVar1;
            lVar9 = lVar9 + -1;
            pWVar6 = pWVar6 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
        }
        pWVar7 = pWVar6 + -1;
        if (lVar5 != 0) {
          pWVar7 = pWVar6;
        }
        *pWVar7 = L'\0';
      }
    }
    BVar4 = ShutdownBlockReasonCreate(*(HWND *)(this + 0x18),local_428);
    if (BVar4 != 0) {
      return 0;
    }
  }
  DVar3 = GetLastError();
  if (0 < (int)DVar3) {
    DVar3 = DVar3 & 0xffff | 0x80070000;
  }
  return DVar3;
}



===== TaskCompleted @ 140005010 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */
/* public: virtual long __cdecl ComTaskHost::TaskCompleted(long) __ptr64 */

long __thiscall ComTaskHost::TaskCompleted(ComTaskHost *this,long param_1)

{
  longlong *plVar1;
  int iVar2;
  DWORD DVar3;
  CLIENT_CALL_RETURN CVar4;
  undefined4 in_register_00000014;
  undefined8 uVar5;
  uint uVar6;
  undefined *in_R8;
  bool bVar7;
  undefined1 uVar8;
  
  uVar5 = CONCAT44(in_register_00000014,param_1);
  uVar6 = 0;
  uVar8 = (undefined1)param_1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    uVar5 = 10;
    in_R8 = &WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids;
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
              &WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids,this,uVar8);
  }
  LOCK();
  UNLOCK();
  LOCK();
  _s_sync = _s_sync + 1;
  UNLOCK();
  LOCK();
  bVar7 = DAT_1400159a4 == 0;
  if (bVar7) {
    DAT_1400159a4 = 0;
  }
  UNLOCK();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  if (bVar7) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,
               &WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids,this);
    }
    goto LAB_1400051aa;
  }
  if (param_1 == -0x7ff8c373) {
    uVar6 = 0x80070057;
    goto LAB_1400051aa;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
  *(undefined4 *)(this + 0x58) = 1;
  *(long *)(this + 0x5c) = param_1;
  LOCK();
  bVar7 = *(int *)(this + 0x10) == 1;
  if (bVar7) {
    *(int *)(this + 0x10) = 5;
  }
  UNLOCK();
  if (bVar7) {
    uVar6 = 0;
    DVar3 = GetCurrentThreadId();
    if (DVar3 == g_dwMainThreadId) {
      g_dwLastTaskResult = 0;
      if (param_1 < 0) {
        g_dwLastTaskResult = param_1 & 0xffff;
      }
      g_ucLastTaskFlags = g_ucLastTaskFlags | 1;
    }
    else {
      in_R8 = (undefined *)0x0;
      uVar5 = 3;
      CVar4 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,3,(void *)0x0,
                             g_hStatusContext);
      uVar6 = (uint)CVar4.Simple;
      if (0 < (int)uVar6) {
        uVar6 = (ushort)CVar4.Simple | 0x80070000;
      }
    }
    if ((int)uVar6 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar5 = 0x18;
        WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x18,in_R8,this,uVar8,(char)uVar6);
      }
      LOCK();
      bVar7 = *(int *)(this + 0x10) == 5;
      if (bVar7) {
        *(int *)(this + 0x10) = 7;
      }
      UNLOCK();
      if (bVar7) goto LAB_14000520b;
    }
    else {
      LOCK();
      if (*(int *)(this + 0x10) == 5) {
        *(int *)(this + 0x10) = 6;
      }
      UNLOCK();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
      in_R8 = &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids;
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar5,
                &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,L"HandleFailedStart");
    }
    LOCK();
    plVar1 = *(longlong **)(this + 0x48);
    *(longlong *)(this + 0x48) = 0;
    UNLOCK();
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))();
    }
    (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 0x18))
              (ComTaskMgrBase::s_pVirtualSingleton,this);
    (**(code **)(*(longlong *)this + 0x10))(this);
    if (-1 < (int)uVar6) goto LAB_1400051aa;
  }
  else {
    uVar6 = 0x80004004;
LAB_14000520b:
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x19,in_R8,this,uVar8,(char)uVar6);
  }
LAB_1400051aa:
  LOCK();
  UNLOCK();
  LOCK();
  iVar2 = _s_sync + -1;
  UNLOCK();
  bVar7 = _s_sync == 1;
  _s_sync = iVar2;
  if (bVar7) {
    LOCK();
    if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
      _s_hEvent = (HANDLE)0xffffffffffffffff;
    }
    UNLOCK();
    SetEvent(_s_hEvent);
  }
  return uVar6;
}



===== `scalar_deleting_destructor' @ 140005350 =====

/* public: virtual void * __ptr64 __cdecl ComTaskMgrWnd::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ComTaskMgrWnd::_scalar_deleting_destructor_(ComTaskMgrWnd *this,uint param_1)

{
  ~ComTaskMgrWnd(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ~ComTaskMgrWnd @ 140005390 =====

/* public: virtual __cdecl ComTaskMgrWnd::~ComTaskMgrWnd(void) __ptr64 */

void __thiscall ComTaskMgrWnd::~ComTaskMgrWnd(ComTaskMgrWnd *this)

{
  *(undefined ***)this = &_vftable_;
  CleanupSet::~CleanupSet((CleanupSet *)(this + 0x48));
  *(undefined ***)this = &ComTaskMgrBase::_vftable_;
  return;
}



===== ~CleanupSet @ 1400053d0 =====

/* public: __cdecl ComTaskMgrWnd::CleanupSet::~CleanupSet(void) __ptr64 */

void __thiscall ComTaskMgrWnd::CleanupSet::~CleanupSet(CleanupSet *this)

{
  set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>
  *this_00;
  
  this_00 = (set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>
             *)(this + 8);
  ClearList<std::set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>_>
            (this_00);
  std::
  _Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
  ::clear((_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
           *)this_00);
  operator_delete(*(void **)this_00);
  return;
}



===== ClearList<std::set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>_> @ 140005408 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* void __cdecl ClearList<class std::set<class ComTaskHost * __ptr64,struct std::less<class
   ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost * __ptr64> > >(class std::set<class
   ComTaskHost * __ptr64,struct std::less<class ComTaskHost * __ptr64>,class std::allocator<class
   ComTaskHost * __ptr64> > & __ptr64) */

void __cdecl
ClearList<std::set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>_>
          (set<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>_>
           *param_1)

{
  longlong *plVar1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var3;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var4;
  
  if (*(longlong *)(param_1 + 8) != 0) {
    p_Var3 = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)**(undefined8 **)param_1;
    while (p_Var3 != *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)param_1) {
      plVar1 = *(longlong **)(p_Var3 + 0x20);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x28))(plVar1,1);
      }
      if (p_Var3[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
        if ((*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 0x10))[0x19] ==
            (_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64>)0x0) {
          p_Var3 = std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>::_Min
                             (*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)
                               (p_Var3 + 0x10));
        }
        else {
          p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 8);
          p_Var4 = p_Var3;
          while ((p_Var3 = p_Var2,
                 p_Var3[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0 &&
                 (p_Var4 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 0x10)))) {
            p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 8);
            p_Var4 = p_Var3;
          }
        }
      }
    }
    std::
    _Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
    ::clear((_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
             *)param_1);
  }
  return;
}



===== CleanupSetRemove @ 140005490 =====

/* public: virtual void __cdecl ComTaskMgrWnd::[ComTaskMgr]::CleanupSetRemove(class ComTaskHost *
   __ptr64) __ptr64 */

void __thiscall
ComTaskMgrWnd::[ComTaskMgr]::CleanupSetRemove(_ComTaskMgr_ *this,ComTaskHost *param_1)

{
  _ComTaskMgr_ *SRWLock;
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *local_res8;
  _ComTaskMgr_ *local_res10;
  undefined1 local_res18 [8];
  
  SRWLock = this + 0x48;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
             &WPP_70d3f6ab2bd730cad06006a8dcaaa1a7_Traceguids,param_1);
  }
  local_res10 = SRWLock;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  plVar6 = *(longlong **)(this + 0x50);
  plVar5 = (longlong *)plVar6[1];
  cVar1 = *(char *)((longlong)plVar5 + 0x19);
  plVar4 = plVar6;
  local_res8 = plVar6;
  plVar3 = plVar5;
  while (cVar1 == '\0') {
    if ((ComTaskHost *)plVar3[4] < param_1) {
      plVar2 = (longlong *)plVar3[2];
      plVar3 = local_res8;
    }
    else {
      if ((*(char *)((longlong)plVar4 + 0x19) != '\0') && (param_1 < (ComTaskHost *)plVar3[4])) {
        plVar4 = plVar3;
      }
      plVar2 = (longlong *)*plVar3;
    }
    local_res8 = plVar3;
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
    plVar5 = (longlong *)*plVar4;
  }
  cVar1 = *(char *)((longlong)plVar5 + 0x19);
  while (plVar3 = plVar5, cVar1 == '\0') {
    if (param_1 < (ComTaskHost *)plVar3[4]) {
      plVar5 = (longlong *)*plVar3;
    }
    else {
      plVar5 = (longlong *)plVar3[2];
      plVar3 = plVar4;
    }
    cVar1 = *(char *)((longlong)plVar5 + 0x19);
    plVar4 = plVar3;
  }
  if ((local_res8 == (longlong *)*plVar6) && (plVar4 == plVar6)) {
    std::
    _Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
    ::clear((_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
             *)(this + 0x50));
  }
  else {
    while (local_res8 != plVar4) {
      plVar6 = local_res8;
      std::
      _Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>,std::_Iterator_base0>
      ::operator++((_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>,std::_Iterator_base0>
                    *)&local_res8);
      std::
      _Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
      ::erase((_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
               *)(this + 0x50),local_res18,plVar6);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000140005545. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  return;
}



===== clear @ 1400055f0 =====

/* public: void __cdecl std::_Tree<class std::_Tset_traits<class ComTaskHost * __ptr64,struct
   std::less<class ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost * __ptr64>,0>
   >::clear(void) __ptr64 */

void __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::clear(_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
        *this)

{
  _Erase(this,*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8));
  *(longlong *)(*(longlong *)this + 8) = *(longlong *)this;
  *(undefined8 *)*(undefined8 *)this = *(undefined8 *)this;
  *(longlong *)(*(longlong *)this + 0x10) = *(longlong *)this;
  *(undefined8 *)(this + 8) = 0;
  return;
}



===== _Erase @ 140005630 =====

/* protected: void __cdecl std::_Tree<class std::_Tset_traits<class ComTaskHost * __ptr64,struct
   std::less<class ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost * __ptr64>,0>
   >::_Erase(struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64) __ptr64
    */

void __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::_Erase(_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
         *this,_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *param_1)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> _Var1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  
  _Var1 = param_1[0x19];
  while (_Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
    _Erase(this,*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(param_1 + 0x10));
    p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)param_1;
    operator_delete(param_1);
    param_1 = p_Var2;
    _Var1 = p_Var2[0x19];
  }
  return;
}



===== operator++ @ 140005690 =====

/* public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<class ComTaskHost * __ptr64> >,struct std::_Iterator_base0> & __ptr64
   __cdecl std::_Tree_unchecked_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<class ComTaskHost * __ptr64> >,struct
   std::_Iterator_base0>::operator++(void) __ptr64 */

_Tree_unchecked_const_iterator<class_std::_Tree_val<struct_std::_Tree_simple_types<class_ComTaskHost*___ptr64>_>,struct_std::_Iterator_base0>
* __thiscall
std::
_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>,std::_Iterator_base0>
::operator++(_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>,std::_Iterator_base0>
             *this)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> _Var1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var3;
  
  p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)this;
  if (p_Var2[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
    if ((*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)(p_Var2 + 0x10))[0x19] ==
        (_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var3 = _Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>::_Min
                         (*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)(p_Var2 + 0x10))
      ;
    }
    else {
      _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var2 + 8))[0x19];
      p_Var3 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var2 + 8);
      while ((_Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0 &&
             (p_Var2 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 0x10)))) {
        *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)this = p_Var3;
        _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 8))[0x19];
        p_Var2 = p_Var3;
        p_Var3 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 8);
      }
    }
    *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)this = p_Var3;
  }
  return (_Tree_unchecked_const_iterator<class_std::_Tree_val<struct_std::_Tree_simple_types<class_ComTaskHost*___ptr64>_>,struct_std::_Iterator_base0>
          *)this;
}



===== erase @ 1400056f0 =====

/* public: class std::_Tree_const_iterator<class std::_Tree_val<struct std::_Tree_simple_types<class
   ComTaskHost * __ptr64> > > __cdecl std::_Tree<class std::_Tset_traits<class ComTaskHost *
   __ptr64,struct std::less<class ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost *
   __ptr64>,0> >::erase(class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<class ComTaskHost * __ptr64> > >) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::erase(_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
        *this,undefined8 *param_2,_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *param_3)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> _Var1;
  undefined8 *puVar2;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var3;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var4;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var5;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var6;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var7;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var8;
  
  if (param_3[0x19] != (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
                    /* WARNING: Subroutine does not return */
    _Xout_of_range("invalid map/set<T> iterator");
  }
  p_Var6 = param_3 + 0x10;
  p_Var5 = param_3 + 8;
  if ((*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)(param_3 + 0x10))[0x19] ==
      (_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64>)0x0) {
    p_Var4 = _Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>::_Min
                       (*(_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> **)(param_3 + 0x10));
  }
  else {
    _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var5)[0x19];
    p_Var7 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var5;
    p_Var8 = param_3;
    while ((p_Var4 = p_Var7, _Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0 &&
           (p_Var8 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var4 + 0x10)))) {
      _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var4 + 8))[0x19];
      p_Var7 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var4 + 8);
      p_Var8 = p_Var4;
    }
  }
  p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)param_3;
  p_Var7 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var6;
  if (p_Var8[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
    if ((*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var6)[0x19] !=
        (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var7 = p_Var8;
      goto LAB_140005763;
    }
    p_Var7 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var4 + 0x10);
    if (p_Var4 == param_3) goto LAB_140005763;
    *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 8) = p_Var4;
    *(longlong *)p_Var4 = *(longlong *)param_3;
    if (p_Var4 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var6) {
      p_Var8 = p_Var4;
    }
    else {
      p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var4 + 8);
      if (p_Var7[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
        *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var7 + 8) = p_Var8;
      }
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8 = p_Var7;
      *(longlong *)(p_Var4 + 0x10) = *(longlong *)p_Var6;
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)p_Var6 + 8) = p_Var4;
    }
    if (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8) == param_3) {
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8) = p_Var4;
    }
    else {
      puVar2 = *(undefined8 **)p_Var5;
      if ((_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)*puVar2 == param_3) {
        *puVar2 = p_Var4;
      }
      else {
        puVar2[2] = p_Var4;
      }
    }
    *(longlong *)(p_Var4 + 8) = *(longlong *)p_Var5;
    _Var1 = p_Var4[0x18];
    p_Var4[0x18] = param_3[0x18];
    param_3[0x18] = _Var1;
  }
  else {
LAB_140005763:
    p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var5;
    if (p_Var7[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var7 + 8) = p_Var8;
    }
    if (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8) == param_3) {
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8) = p_Var7;
    }
    else if (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8 == param_3) {
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8 = p_Var7;
    }
    else {
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 0x10) = p_Var7;
    }
    if ((_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)**(undefined8 **)this == param_3) {
      if (p_Var7[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
        _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var7)[0x19];
        p_Var5 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var7;
        p_Var6 = p_Var7;
        while (p_Var3 = p_Var5, _Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
          p_Var5 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var3;
          _Var1 = p_Var5[0x19];
          p_Var6 = p_Var3;
        }
      }
      else {
        p_Var6 = p_Var8;
      }
      **(undefined8 **)this = p_Var6;
    }
    if (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 0x10) == param_3) {
      if (p_Var7[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
        _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var7 + 0x10))[0x19];
        p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var7 + 0x10);
        p_Var5 = p_Var7;
        while (p_Var3 = p_Var6, _Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
          p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var3 + 0x10);
          _Var1 = p_Var6[0x19];
          p_Var5 = p_Var3;
        }
      }
      else {
        p_Var5 = p_Var8;
      }
      *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 0x10) = p_Var5;
    }
  }
  if (param_3[0x18] != (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1) {
LAB_1400057c5:
    operator_delete(param_3);
    if (*(longlong *)(this + 8) != 0) {
      *(longlong *)(this + 8) = *(longlong *)(this + 8) + -1;
    }
    *param_2 = p_Var4;
    return param_2;
  }
LAB_14000591d:
  if ((p_Var7 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8)) ||
     (p_Var7[0x18] != (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1)) goto LAB_140005a49;
  p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8;
  p_Var5 = p_Var8;
  if (p_Var7 == p_Var6) {
    p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 0x10);
    if (p_Var6[0x18] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var6[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      p_Var8[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0;
      _Lrotate(this,p_Var8);
      p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 0x10);
    }
    if (p_Var6[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      if ((*(char *)(*(longlong *)p_Var6 + 0x18) != '\x01') ||
         (*(char *)(*(longlong *)(p_Var6 + 0x10) + 0x18) != '\x01')) {
        if (*(char *)(*(longlong *)(p_Var6 + 0x10) + 0x18) == '\x01') {
          *(undefined1 *)(*(longlong *)p_Var6 + 0x18) = 1;
          p_Var6[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0;
          _Rrotate(this,p_Var6);
          p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 0x10);
        }
        p_Var6[0x18] = p_Var8[0x18];
        p_Var8[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
        *(undefined1 *)(*(longlong *)(p_Var6 + 0x10) + 0x18) = 1;
        _Lrotate(this,p_Var8);
        goto LAB_140005a49;
      }
LAB_1400059fe:
      p_Var6[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0;
    }
  }
  else {
    if (p_Var6[0x18] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var6[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      p_Var8[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0;
      _Rrotate(this,p_Var8);
      p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8;
    }
    if (p_Var6[0x19] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      if ((*(char *)(*(longlong *)(p_Var6 + 0x10) + 0x18) == '\x01') &&
         (*(char *)(*(longlong *)p_Var6 + 0x18) == '\x01')) goto LAB_1400059fe;
      if (*(char *)(*(longlong *)p_Var6 + 0x18) == '\x01') {
        *(undefined1 *)(*(longlong *)(p_Var6 + 0x10) + 0x18) = 1;
        p_Var6[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0;
        _Lrotate(this,p_Var6);
        p_Var6 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var8;
      }
      p_Var6[0x18] = p_Var8[0x18];
      p_Var8[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      *(undefined1 *)(*(longlong *)p_Var6 + 0x18) = 1;
      _Rrotate(this,p_Var8);
LAB_140005a49:
      p_Var7[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      goto LAB_1400057c5;
    }
  }
  p_Var7 = p_Var5;
  p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 8);
  goto LAB_14000591d;
}



===== CleanupSetAdd @ 140005a70 =====

/* public: virtual void __cdecl ComTaskMgrWnd::[ComTaskMgr]::CleanupSetAdd(class ComTaskHost *
   __ptr64) __ptr64 */

void __thiscall ComTaskMgrWnd::[ComTaskMgr]::CleanupSetAdd(_ComTaskMgr_ *this,ComTaskHost *param_1)

{
  _ComTaskMgr_ *SRWLock;
  undefined8 in_R8;
  ComTaskHost *local_res8;
  _ComTaskMgr_ *local_res10;
  undefined1 local_18 [16];
  
  SRWLock = this + 0x48;
  local_res8 = param_1;
  local_res10 = SRWLock;
  AcquireSRWLockExclusive((PSRWLOCK)SRWLock);
  std::
  _Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
  ::_Insert_nohint<ComTaskHost*___ptr64_const&___ptr64,std::_Nil>
            ((_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
              *)(this + 0x50),local_18,in_R8,&local_res8,DAT_1400159c0);
                    /* WARNING: Could not recover jumptable at 0x000140005aba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive((PSRWLOCK)SRWLock);
  return;
}



===== _Insert_nohint<ComTaskHost*___ptr64_const&___ptr64,std::_Nil> @ 140005ad0 =====

/* protected: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<class ComTaskHost * __ptr64> > >,bool> __cdecl std::_Tree<class
   std::_Tset_traits<class ComTaskHost * __ptr64,struct std::less<class ComTaskHost * __ptr64>,class
   std::allocator<class ComTaskHost * __ptr64>,0> >::_Insert_nohint<class ComTaskHost * __ptr64
   const & __ptr64,struct std::_Nil>(bool,class ComTaskHost * __ptr64 const & __ptr64,struct
   std::_Nil) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::_Insert_nohint<ComTaskHost*___ptr64_const&___ptr64,std::_Nil>
          (_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
           *this,undefined8 *param_2,undefined8 param_3,ComTaskHost **param_4)

{
  char cVar1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  longlong *plVar3;
  longlong *plVar4;
  bool bVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var12;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var13;
  undefined1 local_res8 [8];
  
  puVar10 = *(undefined8 **)this;
  bVar5 = true;
  puVar11 = puVar10;
  if (*(char *)((longlong)puVar10[1] + 0x19) == '\0') {
    puVar7 = (undefined8 *)puVar10[1];
    do {
      puVar11 = puVar7;
      if ((ComTaskHost *)puVar11[4] <= *param_4) {
        puVar7 = (undefined8 *)puVar11[2];
      }
      else {
        puVar7 = (undefined8 *)*puVar11;
      }
      bVar5 = (ComTaskHost *)puVar11[4] > *param_4;
    } while (*(char *)((longlong)puVar7 + 0x19) == '\0');
  }
  puVar7 = puVar11;
  if (bVar5) {
    if (puVar11 == (undefined8 *)*puVar10) {
      puVar10 = (undefined8 *)
                _Insert_at<ComTaskHost*___ptr64_const&___ptr64,std::_Nil>
                          (this,local_res8,1,puVar11,param_4);
      *param_2 = *puVar10;
      *(undefined1 *)(param_2 + 1) = 1;
      return param_2;
    }
    if (*(char *)((longlong)puVar11 + 0x19) == '\0') {
      puVar7 = (undefined8 *)*puVar11;
      if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)puVar7[2] + 0x19);
        puVar10 = (undefined8 *)puVar7[2];
        while (cVar1 == '\0') {
          cVar1 = *(char *)((longlong)puVar10[2] + 0x19);
          puVar7 = puVar10;
          puVar10 = (undefined8 *)puVar10[2];
        }
      }
      else {
        cVar1 = *(char *)((longlong)puVar11[1] + 0x19);
        puVar10 = (undefined8 *)puVar11[1];
        puVar7 = puVar11;
        while ((puVar6 = puVar10, cVar1 == '\0' && (puVar7 == (undefined8 *)*puVar6))) {
          cVar1 = *(char *)((longlong)puVar6[1] + 0x19);
          puVar10 = (undefined8 *)puVar6[1];
          puVar7 = puVar6;
        }
        if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
          puVar7 = puVar6;
        }
      }
    }
    else {
      puVar7 = (undefined8 *)puVar11[2];
    }
  }
  if (*param_4 <= (ComTaskHost *)puVar7[4]) {
    *param_2 = puVar7;
    *(undefined1 *)(param_2 + 1) = 0;
    return param_2;
  }
  if (0x666666666666664 < *(ulonglong *)(this + 8)) {
                    /* WARNING: Subroutine does not return */
    _Xlength_error("map/set<T> too long");
  }
  p_Var8 = _Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>::
           _Buynode<ComTaskHost*___ptr64_const&___ptr64>
                     ((_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_> *)this,
                      param_4);
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
  *(undefined8 **)(p_Var8 + 8) = puVar11;
  if (puVar11 == *(undefined8 **)this) {
    (*(undefined8 **)this)[1] = p_Var8;
    **(undefined8 **)this = p_Var8;
    lVar9 = *(longlong *)this;
  }
  else {
    if (bVar5) {
      *puVar11 = p_Var8;
      if (puVar11 == (undefined8 *)**(undefined8 **)this) {
        **(undefined8 **)this = p_Var8;
      }
      goto LAB_140005b6b;
    }
    puVar11[2] = p_Var8;
    lVar9 = *(longlong *)this;
    if (puVar11 != *(undefined8 **)(lVar9 + 0x10)) goto LAB_140005b6b;
  }
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(lVar9 + 0x10) = p_Var8;
LAB_140005b6b:
  cVar1 = *(char *)(*(longlong *)(p_Var8 + 8) + 0x18);
  p_Var13 = p_Var8;
  while (cVar1 == '\0') {
    p_Var12 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var13 + 8);
    p_Var2 = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)**(undefined8 **)(p_Var12 + 8);
    if (p_Var12 == p_Var2) {
      lVar9 = (*(undefined8 **)(p_Var12 + 8))[2];
      if (*(char *)(lVar9 + 0x18) == '\0') {
        p_Var12[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
        *(undefined1 *)(lVar9 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var13 + 8) + 8) + 0x18) = 0;
        p_Var13 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)
                   (*(longlong *)(p_Var13 + 8) + 8);
      }
      else {
        if (p_Var13 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var12 + 0x10)) {
          _Lrotate(this,p_Var12);
          p_Var13 = p_Var12;
        }
        *(undefined1 *)(*(longlong *)(p_Var13 + 8) + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var13 + 8) + 8) + 0x18) = 0;
        _Rrotate(this,*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)
                       (*(longlong *)(p_Var13 + 8) + 8));
      }
    }
    else if (p_Var2[0x18] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var12[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      p_Var2[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var13 + 8) + 8) + 0x18) = 0;
      p_Var13 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)(p_Var13 + 8) + 8)
      ;
    }
    else {
      if (p_Var13 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var12) {
        _Rrotate(this,p_Var12);
        p_Var13 = p_Var12;
      }
      *(undefined1 *)(*(longlong *)(p_Var13 + 8) + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var13 + 8) + 8) + 0x18) = 0;
      lVar9 = *(longlong *)(*(longlong *)(p_Var13 + 8) + 8);
      plVar3 = *(longlong **)(lVar9 + 0x10);
      *(longlong *)(lVar9 + 0x10) = *plVar3;
      if (*(char *)(*plVar3 + 0x19) == '\0') {
        *(longlong *)(*plVar3 + 8) = lVar9;
      }
      plVar3[1] = *(longlong *)(lVar9 + 8);
      if (lVar9 == *(longlong *)(*(longlong *)this + 8)) {
        *(longlong **)(*(longlong *)this + 8) = plVar3;
      }
      else {
        plVar4 = *(longlong **)(lVar9 + 8);
        if (lVar9 == *plVar4) {
          *plVar4 = (longlong)plVar3;
        }
        else {
          plVar4[2] = (longlong)plVar3;
        }
      }
      *plVar3 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar3;
    }
    cVar1 = *(char *)(*(longlong *)(p_Var13 + 8) + 0x18);
  }
  *(undefined1 *)(*(longlong *)(*(longlong *)this + 8) + 0x18) = 1;
  *param_2 = p_Var8;
  *(undefined1 *)(param_2 + 1) = 1;
  return param_2;
}



===== _Insert_at<ComTaskHost*___ptr64_const&___ptr64,std::_Nil> @ 140005df0 =====

/* protected: class std::_Tree_const_iterator<class std::_Tree_val<struct
   std::_Tree_simple_types<class ComTaskHost * __ptr64> > > __cdecl std::_Tree<class
   std::_Tset_traits<class ComTaskHost * __ptr64,struct std::less<class ComTaskHost * __ptr64>,class
   std::allocator<class ComTaskHost * __ptr64>,0> >::_Insert_at<class ComTaskHost * __ptr64 const &
   __ptr64,struct std::_Nil>(bool,struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64>
   * __ptr64,class ComTaskHost * __ptr64 const & __ptr64,struct std::_Nil) __ptr64 */

undefined8 * __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::_Insert_at<ComTaskHost*___ptr64_const&___ptr64,std::_Nil>
          (_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
           *this,undefined8 *param_2,char param_3_00,undefined8 *param_3,ComTaskHost **param_5)

{
  char cVar1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  longlong *plVar3;
  longlong *plVar4;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var5;
  longlong lVar6;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var7;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var8;
  
  if (0x666666666666664 < *(ulonglong *)(this + 8)) {
                    /* WARNING: Subroutine does not return */
    _Xlength_error("map/set<T> too long");
  }
  p_Var5 = _Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>::
           _Buynode<ComTaskHost*___ptr64_const&___ptr64>
                     ((_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_> *)this,
                      param_5);
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
  *(undefined8 **)(p_Var5 + 8) = param_3;
  if (param_3 == *(undefined8 **)this) {
    (*(undefined8 **)this)[1] = p_Var5;
    **(undefined8 **)this = p_Var5;
    lVar6 = *(longlong *)this;
  }
  else {
    if (param_3_00 != '\0') {
      *param_3 = p_Var5;
      if (param_3 == (undefined8 *)**(longlong **)this) {
        **(longlong **)this = (longlong)p_Var5;
      }
      goto LAB_140005e60;
    }
    param_3[2] = p_Var5;
    lVar6 = *(longlong *)this;
    if (param_3 != *(undefined8 **)(lVar6 + 0x10)) goto LAB_140005e60;
  }
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(lVar6 + 0x10) = p_Var5;
LAB_140005e60:
  cVar1 = *(char *)(*(longlong *)(p_Var5 + 8) + 0x18);
  p_Var8 = p_Var5;
  while (cVar1 == '\0') {
    p_Var7 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var8 + 8);
    p_Var2 = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)**(undefined8 **)(p_Var7 + 8);
    if (p_Var7 == p_Var2) {
      lVar6 = (*(undefined8 **)(p_Var7 + 8))[2];
      if (*(char *)(lVar6 + 0x18) == '\0') {
        p_Var7[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
        *(undefined1 *)(lVar6 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
        p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)(p_Var8 + 8) + 8)
        ;
      }
      else {
        if (p_Var8 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var7 + 0x10)) {
          _Lrotate(this,p_Var7);
          p_Var8 = p_Var7;
        }
        *(undefined1 *)(*(longlong *)(p_Var8 + 8) + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
        _Rrotate(this,*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)
                       (*(longlong *)(p_Var8 + 8) + 8));
      }
    }
    else if (p_Var2[0x18] == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
      p_Var7[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      p_Var2[0x18] = (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x1;
      *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
      p_Var8 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)(p_Var8 + 8) + 8);
    }
    else {
      if (p_Var8 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var7) {
        _Rrotate(this,p_Var7);
        p_Var8 = p_Var7;
      }
      *(undefined1 *)(*(longlong *)(p_Var8 + 8) + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(*(longlong *)(p_Var8 + 8) + 8) + 0x18) = 0;
      lVar6 = *(longlong *)(*(longlong *)(p_Var8 + 8) + 8);
      plVar3 = *(longlong **)(lVar6 + 0x10);
      *(longlong *)(lVar6 + 0x10) = *plVar3;
      if (*(char *)(*plVar3 + 0x19) == '\0') {
        *(longlong *)(*plVar3 + 8) = lVar6;
      }
      plVar3[1] = *(longlong *)(lVar6 + 8);
      if (lVar6 == *(longlong *)(*(longlong *)this + 8)) {
        *(longlong **)(*(longlong *)this + 8) = plVar3;
      }
      else {
        plVar4 = *(longlong **)(lVar6 + 8);
        if (lVar6 == *plVar4) {
          *plVar4 = (longlong)plVar3;
        }
        else {
          plVar4[2] = (longlong)plVar3;
        }
      }
      *plVar3 = lVar6;
      *(longlong **)(lVar6 + 8) = plVar3;
    }
    cVar1 = *(char *)(*(longlong *)(p_Var8 + 8) + 0x18);
  }
  lVar6 = *(longlong *)(*(longlong *)this + 8);
  *param_2 = p_Var5;
  *(undefined1 *)(lVar6 + 0x18) = 1;
  return param_2;
}



===== _Buynode<ComTaskHost*___ptr64_const&___ptr64> @ 14000601c =====

/* public: struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64 __cdecl
   std::_Tree_buy<class ComTaskHost * __ptr64,class std::allocator<class ComTaskHost * __ptr64>
   >::_Buynode<class ComTaskHost * __ptr64 const & __ptr64>(class ComTaskHost * __ptr64 const &
   __ptr64) __ptr64 */

_Tree_node<ComTaskHost*___ptr64,void*___ptr64> * __thiscall
std::_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>::
_Buynode<ComTaskHost*___ptr64_const&___ptr64>
          (_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_> *this,
          ComTaskHost **param_1)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var1;
  
  p_Var1 = _Buynode0(this);
  *(undefined2 *)(p_Var1 + 0x18) = 0;
  *(ComTaskHost **)(p_Var1 + 0x20) = *param_1;
  return p_Var1;
}



===== _Buynode0 @ 140006048 =====

/* public: struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64 __cdecl
   std::_Tree_buy<class ComTaskHost * __ptr64,class std::allocator<class ComTaskHost * __ptr64>
   >::_Buynode0(void) __ptr64 */

_Tree_node<ComTaskHost*___ptr64,void*___ptr64> * __thiscall
std::_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>::_Buynode0
          (_Tree_buy<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_> *this)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var1;
  
  p_Var1 = operator_new(0x28);
  if (p_Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)0x0) {
                    /* WARNING: Subroutine does not return */
    _Xbad_alloc();
  }
  *(undefined8 *)p_Var1 = *(undefined8 *)this;
  *(undefined8 *)(p_Var1 + 8) = *(undefined8 *)this;
  *(undefined8 *)(p_Var1 + 0x10) = *(undefined8 *)this;
  return p_Var1;
}



===== HandleReportingState @ 1400060a0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Restarted to delay deadcode elimination for space: register */
/* private: long __cdecl ComTaskHost::HandleReportingState(long,enum ComTaskHost::StateType) __ptr64
    */

long __thiscall ComTaskHost::HandleReportingState(ComTaskHost *this,long param_1,StateType param_2)

{
  longlong *plVar1;
  DWORD DVar2;
  StateType SVar3;
  CLIENT_CALL_RETURN CVar4;
  undefined4 in_register_00000014;
  ulonglong uVar5;
  uint uVar6;
  undefined4 in_register_00000084;
  undefined *puVar7;
  bool bVar8;
  
  puVar7 = (undefined *)CONCAT44(in_register_00000084,param_2);
  uVar5 = CONCAT44(in_register_00000014,param_1);
  if (param_1 == -0x7ff8c373) {
    return -0x7ff8ffa9;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
  *(undefined4 *)(this + 0x58) = 1;
  *(long *)(this + 0x5c) = param_1;
  LOCK();
  bVar8 = *(int *)(this + 0x10) == 1;
  if (bVar8) {
    *(StateType *)(this + 0x10) = param_2;
  }
  UNLOCK();
  if (bVar8) {
    uVar6 = 0;
    DVar2 = GetCurrentThreadId();
    if (DVar2 == g_dwMainThreadId) {
      g_dwLastTaskResult = 0;
      if (param_1 < 0) {
        g_dwLastTaskResult = param_1 & 0xffff;
      }
      g_ucLastTaskFlags = g_ucLastTaskFlags | 1;
    }
    else {
      uVar5 = 3;
      puVar7 = (undefined *)0x0;
      CVar4 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000d118,3,(void *)0x0,
                             g_hStatusContext);
      uVar6 = (uint)CVar4.Simple;
      if (0 < (int)uVar6) {
        uVar6 = (ushort)CVar4.Simple | 0x80070000;
      }
    }
    if ((int)uVar6 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
        uVar5 = 0x18;
        WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x18,puVar7,this,(char)param_1,
                   (char)uVar6);
      }
      LOCK();
      SVar3 = *(StateType *)(this + 0x10);
      if (param_2 == SVar3) {
        *(StateType *)(this + 0x10) = param_2 + 2;
        SVar3 = param_2;
      }
      else {
      }
      UNLOCK();
      if (param_2 == SVar3) goto LAB_140006224;
    }
    else {
      uVar5 = (ulonglong)(param_2 + 1);
      LOCK();
      if (param_2 == *(StateType *)(this + 0x10)) {
        *(StateType *)(this + 0x10) = param_2 + 1;
      }
      UNLOCK();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
      puVar7 = &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids;
      WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),uVar5,
                &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,L"HandleFailedStart");
    }
    LOCK();
    plVar1 = *(longlong **)(this + 0x48);
    *(longlong *)(this + 0x48) = 0;
    UNLOCK();
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x10))(plVar1);
    }
    (**(code **)(*(longlong *)ComTaskMgrBase::s_pVirtualSingleton + 0x18))
              (ComTaskMgrBase::s_pVirtualSingleton,this);
    (**(code **)(*(longlong *)this + 0x10))(this);
    if (-1 < (int)uVar6) {
      return uVar6;
    }
  }
  else {
    uVar6 = 0x80004004;
LAB_140006224:
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x19,puVar7,this,(char)param_1,(char)uVar6
              );
  }
  return uVar6;
}



===== InitSingleton @ 140006300 =====

/* public: virtual long __cdecl ComTaskMgrWnd::InitSingleton(struct HINSTANCE__ * __ptr64) __ptr64
    */

long __thiscall ComTaskMgrWnd::InitSingleton(ComTaskMgrWnd *this,HINSTANCE__ *param_1)

{
  long lVar1;
  
  *(HINSTANCE__ **)(this + 8) = param_1;
  lVar1 = CreateMsgPumpThread(this);
  if (lVar1 < 0) {
    *(undefined8 *)(this + 8) = 0;
  }
  return lVar1;
}



===== CreateMsgPumpThread @ 140006330 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: long __cdecl ComTaskMgrWnd::CreateMsgPumpThread(void) __ptr64 */

long __thiscall ComTaskMgrWnd::CreateMsgPumpThread(ComTaskMgrWnd *this)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)(this + 0x38) = pvVar2;
  if (pvVar2 == (HANDLE)0x0) {
    DVar1 = GetLastError();
    if (0 < (int)DVar1) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
  else {
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)(this + 0x28) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,MsgPumpThreadProc,(LPVOID)0x0,0,
                            (LPDWORD)0x0);
      *(HANDLE *)(this + 0x30) = pvVar2;
      if (pvVar2 != (HANDLE)0x0) {
        WaitForSingleObject(*(HANDLE *)(this + 0x28),0xffffffff);
        DVar1 = *(DWORD *)(this + 0x20);
        goto LAB_1400063d9;
      }
    }
    DVar1 = GetLastError();
    if (0 < (int)DVar1) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
LAB_1400063d9:
  pvVar2 = *(HANDLE *)(this + 0x28);
  if ((longlong)pvVar2 - 1U < 0xfffffffffffffffe) {
    CloseHandle(pvVar2);
    *(undefined8 *)(this + 0x28) = 0;
  }
  if ((int)DVar1 < 0) {
    if (*(longlong *)(this + 0x30) == 0) {
      if ((longlong)*(HANDLE *)(this + 0x38) - 1U < 0xfffffffffffffffe) {
        CloseHandle(*(HANDLE *)(this + 0x38));
        *(undefined8 *)(this + 0x38) = 0;
      }
    }
    else {
      (**(code **)(*(longlong *)this + 0x30))(this);
    }
  }
  return DVar1;
}



===== UninitSingleton @ 1400064a0 =====

/* public: virtual long __cdecl ComTaskMgrWnd::UninitSingleton(void) __ptr64 */

long __thiscall ComTaskMgrWnd::UninitSingleton(ComTaskMgrWnd *this)

{
  ComTaskMgrWnd *pCVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  
  pCVar1 = this + 0x30;
  BVar3 = SetEvent(*(HANDLE *)(this + 0x38));
  if (BVar3 != 0) {
    WaitForSingleObject(*(HANDLE *)pCVar1,0xffffffff);
  }
  pvVar2 = *(HANDLE *)pCVar1;
  if ((pvVar2 != (HANDLE)0x0) && (pvVar2 != (HANDLE)0xffffffffffffffff)) {
    CloseHandle(pvVar2);
    *(undefined8 *)pCVar1 = 0;
  }
  pvVar2 = *(HANDLE *)(this + 0x38);
  if ((longlong)pvVar2 - 1U < 0xfffffffffffffffe) {
    CloseHandle(pvVar2);
    *(undefined8 *)(this + 0x38) = 0;
  }
  return 0;
}



===== __delayLoadHelper2 @ 140006560 =====

void __delayLoadHelper2(undefined8 param_1,undefined8 param_2)

{
  ResolveDelayLoadedAPI(&IMAGE_DOS_HEADER_140000000,param_1,0,DelayLoadFailureHook_exref,param_2,0);
  return;
}



===== PrepareAcesForACL @ 1400065b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: virtual void __cdecl ATL::CDacl::PrepareAcesForACL(void)const __ptr64 */

void __thiscall ATL::CDacl::PrepareAcesForACL(CDacl *this)

{
  CAccessAce **ppCVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  CAutoPtr<ATL::CDacl::CAccessAce> *pCVar5;
  CAutoPtr<ATL::CDacl::CAccessAce> *this_00;
  CAccessAce *pCVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  CAccessAce *local_38 [2];
  
  uVar9 = 1;
  uVar2 = *(ulonglong *)(this + 0x20);
  pCVar6 = (CAccessAce *)0x0;
  local_38[0] = (CAccessAce *)0x0;
  if (4 < uVar2) {
    uVar7 = 4;
    do {
      uVar9 = uVar7;
      uVar7 = uVar9 * 3 + 1;
    } while (uVar7 < uVar2);
    if (uVar9 == 0) goto LAB_140006718;
  }
  do {
    for (uVar7 = uVar9 - 1; uVar7 < uVar2; uVar7 = uVar7 + 1) {
      if (*(ulonglong *)(this + 0x20) <= uVar7) goto LAB_14000674f;
      ppCVar1 = (CAccessAce **)(*(longlong *)(this + 0x18) + uVar7 * 8);
      uVar3 = uVar7;
      if (pCVar6 == *ppCVar1) {
        if (local_38 != ppCVar1) goto LAB_140006652;
      }
      else {
        CAutoPtr<ATL::CDacl::CAccessAce>::Free((CAutoPtr<ATL::CDacl::CAccessAce> *)local_38);
        pCVar6 = *ppCVar1;
        local_38[0] = pCVar6;
LAB_140006652:
        *ppCVar1 = (CAccessAce *)0x0;
      }
      while (uVar9 <= uVar3) {
        uVar8 = uVar3 - uVar9;
        if (*(ulonglong *)(this + 0x20) <= uVar8) goto LAB_14000674f;
        iVar4 = CAccessAce::Order(*(CAccessAce **)(*(longlong *)(this + 0x18) + uVar8 * 8),pCVar6);
        if (iVar4 != -1) break;
        pCVar5 = CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
                 ::operator[]((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
                               *)(this + 0x18),uVar8);
        this_00 = CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
                  ::operator[]((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
                                *)(this + 0x18),uVar3);
        CAutoPtr<ATL::CDacl::CAccessAce>::operator=
                  (this_00,(CAutoPtr<class_ATL::CDacl::CAccessAce> *)pCVar5);
        uVar3 = uVar8;
      }
      if (*(ulonglong *)(this + 0x20) <= uVar3) {
LAB_14000674f:
                    /* WARNING: Subroutine does not return */
        PrivateAtlThrow(-0x7ff8ffa9);
      }
      pCVar5 = (CAutoPtr<ATL::CDacl::CAccessAce> *)(*(longlong *)(this + 0x18) + uVar3 * 8);
      if (*(CAccessAce **)pCVar5 == pCVar6) {
        if (pCVar5 != (CAutoPtr<ATL::CDacl::CAccessAce> *)local_38) goto LAB_1400066ec;
      }
      else {
        CAutoPtr<ATL::CDacl::CAccessAce>::Free(pCVar5);
        *(CAccessAce **)pCVar5 = pCVar6;
LAB_1400066ec:
        pCVar6 = (CAccessAce *)0x0;
        local_38[0] = (CAccessAce *)0x0;
      }
    }
    uVar9 = uVar9 / 3;
  } while (uVar9 != 0);
LAB_140006718:
  if (pCVar6 != (CAccessAce *)0x0) {
    (*(code *)**(undefined8 **)pCVar6)(pCVar6,1);
  }
  return;
}



===== operator= @ 140006760 =====

/* public: class ATL::CAutoPtr<class ATL::CDacl::CAccessAce> & __ptr64 __cdecl ATL::CAutoPtr<class
   ATL::CDacl::CAccessAce>::operator=(class ATL::CAutoPtr<class ATL::CDacl::CAccessAce> & __ptr64)
   __ptr64 */

CAutoPtr<class_ATL::CDacl::CAccessAce> * __thiscall
ATL::CAutoPtr<ATL::CDacl::CAccessAce>::operator=
          (CAutoPtr<ATL::CDacl::CAccessAce> *this,CAutoPtr<class_ATL::CDacl::CAccessAce> *param_1)

{
  undefined8 uVar1;
  
  if (*(longlong *)this == *(longlong *)param_1) {
    if (this != (CAutoPtr<ATL::CDacl::CAccessAce> *)param_1) {
      *(undefined8 *)param_1 = 0;
    }
  }
  else {
    Free(this);
    uVar1 = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)this = uVar1;
  }
  return (CAutoPtr<class_ATL::CDacl::CAccessAce> *)this;
}



===== Free @ 1400067b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl ATL::CAutoPtr<class ATL::CDacl::CAccessAce>::Free(void) __ptr64 */

void __thiscall ATL::CAutoPtr<ATL::CDacl::CAccessAce>::Free(CAutoPtr<ATL::CDacl::CAccessAce> *this)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)this;
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  *(undefined8 *)this = 0;
  return;
}



===== Order @ 1400067f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: static int __cdecl ATL::CDacl::CAccessAce::Order(class ATL::CDacl::CAccessAce const &
   __ptr64,class ATL::CDacl::CAccessAce const & __ptr64) */

int __cdecl ATL::CDacl::CAccessAce::Order(CAccessAce *param_1,CAccessAce *param_2)

{
  char cVar1;
  
  if (((byte)param_1[0x84] & 0x10) == 0) {
    if (((byte)param_2[0x84] & 0x10) != 0) {
      return 1;
    }
  }
  else if (((byte)param_2[0x84] & 0x10) == 0) {
    return -1;
  }
  if (param_1[0x90] == (CAccessAce)0x0) {
    if (param_2[0x90] != (CAccessAce)0x0) {
      return 1;
    }
  }
  else if (param_2[0x90] == (CAccessAce)0x0) {
    return -1;
  }
  cVar1 = (**(code **)(*(longlong *)param_1 + 0x20))();
  if ((cVar1 != '\0') &&
     (cVar1 = (**(code **)(*(longlong *)param_2 + 0x20))(param_2), cVar1 == '\0')) {
    return -1;
  }
  cVar1 = (**(code **)(*(longlong *)param_1 + 0x20))(param_1);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*(longlong *)param_2 + 0x20))(param_2);
    return (uint)(cVar1 != '\0');
  }
  return 0;
}



===== `scalar_deleting_destructor' @ 1400068c0 =====

/* public: virtual void * __ptr64 __cdecl ComTaskHost::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ComTaskHost::_scalar_deleting_destructor_(ComTaskHost *this,uint param_1)

{
  ~ComTaskHost(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ~ComTaskHost @ 140006900 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual __cdecl ComTaskHost::~ComTaskHost(void) __ptr64 */

void __thiscall ComTaskHost::~ComTaskHost(ComTaskHost *this)

{
  Data_t *pDVar1;
  int iVar2;
  HANDLE hObject;
  longlong *plVar3;
  Data_t *pDVar4;
  uint in_EDX;
  
  *(undefined ***)this = &_vftable__for__ITaskHandlerStatus__;
  *(undefined ***)(this + 8) = &_vftable__for__ITaskVariables__;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    in_EDX = 10;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x60));
  LOCK();
  hObject = *(HANDLE *)(this + 0x50);
  *(undefined8 *)(this + 0x50) = 0;
  UNLOCK();
  if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
    CloseHandle(hObject);
  }
  LOCK();
  plVar3 = *(longlong **)(this + 0x48);
  *(longlong *)(this + 0x48) = 0;
  UNLOCK();
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x10))();
  }
  pDVar4 = *(Data_t **)(this + 0x38);
  if (pDVar4 != (Data_t *)0x0) {
    LOCK();
    pDVar1 = pDVar4 + 0x10;
    iVar2 = *(int *)pDVar1;
    *(int *)pDVar1 = *(int *)pDVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      _bstr_t::Data_t::_scalar_deleting_destructor_(pDVar4,in_EDX);
    }
    *(undefined8 *)(this + 0x38) = 0;
  }
  pDVar4 = *(Data_t **)(this + 0x28);
  if (pDVar4 != (Data_t *)0x0) {
    LOCK();
    pDVar1 = pDVar4 + 0x10;
    iVar2 = *(int *)pDVar1;
    *(int *)pDVar1 = *(int *)pDVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      _bstr_t::Data_t::_scalar_deleting_destructor_(pDVar4,in_EDX);
    }
    *(undefined8 *)(this + 0x28) = 0;
  }
  return;
}



===== QueryInterface @ 140006a10 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual long __cdecl ComTaskHost::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall ComTaskHost::QueryInterface(ComTaskHost *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  ComTaskHost *pCVar2;
  
  if (param_2 == (void **)0x0) {
    return -0x7fffbffd;
  }
  *param_2 = (void *)0x0;
  lVar1 = 0x4ddc27a0eaec7a8f - *(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x8aa3016a72147586 - *(longlong *)param_1->Data4;
  }
  if (lVar1 != 0) {
    lVar1 = -*(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x46000000000000c0 - *(longlong *)param_1->Data4;
    }
    if (lVar1 != 0) {
      lVar1 = 0x4b8bd9663e4c9351 - *(longlong *)param_1;
      if (lVar1 == 0) {
        lVar1 = 0x701bb68bace87bb - *(longlong *)param_1->Data4;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
      pCVar2 = this + 8;
      if (this == (ComTaskHost *)0x0) {
        pCVar2 = (ComTaskHost *)0x0;
      }
      goto LAB_140006a47;
    }
  }
  pCVar2 = this;
LAB_140006a47:
  *param_2 = pCVar2;
  if (pCVar2 == (ComTaskHost *)0x0) {
    return -0x7fffbffe;
  }
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== StartTaskThread @ 140006ad0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: static unsigned long __cdecl ComTaskHost::StartTaskThread(void * __ptr64) */

ulong __cdecl ComTaskHost::StartTaskThread(void *param_1)

{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  
  LOCK();
  UNLOCK();
  LOCK();
  _s_sync = _s_sync + 1;
  UNLOCK();
  LOCK();
  bVar3 = DAT_1400159a4 == 0;
  if (bVar3) {
    DAT_1400159a4 = 0;
  }
  UNLOCK();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  if (bVar3) {
    uVar2 = 0x80070281;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
                &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,param_1,0x81);
    }
  }
  else {
    uVar2 = StartTaskWorker(param_1);
  }
  (**(code **)(*(longlong *)param_1 + 0x10))(param_1);
  LOCK();
  UNLOCK();
  LOCK();
  iVar1 = _s_sync + -1;
  UNLOCK();
  bVar3 = _s_sync == 1;
  _s_sync = iVar1;
  if (bVar3) {
    LOCK();
    if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
      _s_hEvent = (HANDLE)0xffffffffffffffff;
    }
    UNLOCK();
    SetEvent(_s_hEvent);
  }
  return uVar2;
}



===== StartTaskWorker @ 140006bc0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: long __cdecl ComTaskHost::StartTaskWorker(void) __ptr64 */

long __thiscall ComTaskHost::StartTaskWorker(ComTaskHost *this)

{
  ComTaskHost *ppv;
  int nPriority;
  HRESULT HVar1;
  BOOL BVar2;
  LPVOID pvVar3;
  HANDLE pvVar4;
  longlong *plVar5;
  undefined8 uVar6;
  int local_res8;
  longlong *local_res10;
  longlong *local_res18;
  HANDLE local_48 [2];
  
  local_res10 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xe,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this);
  }
  ppv = this + 0x48;
  HVar1 = CoCreateInstance((IID *)(this + 0x18),(LPUNKNOWN)0x0,(this[0x30] != (ComTaskHost)0x0) + 4,
                           (IID *)&_GUID_839d7762_5121_4009_9234_4f0d19394f04,(LPVOID *)ppv);
  if ((-1 < HVar1) &&
     (HVar1 = (*(code *)**(undefined8 **)this)
                        (this,&_GUID_00000000_0000_0000_c000_000000000046,&local_res10), -1 < HVar1)
     ) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
      if (*(undefined8 **)(this + 0x38) == (undefined8 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = **(undefined8 **)(this + 0x38);
      }
      pvVar3 = (LPVOID)0x0;
      LOCK();
      if (*(LPVOID *)ppv == (LPVOID)0x0) {
        *(LPVOID *)ppv = (LPVOID)0x0;
      }
      else {
        pvVar3 = *(LPVOID *)ppv;
      }
      UNLOCK();
      WPP_SF_qqqS(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),local_res10,uVar6,this,(char)pvVar3,
                  (char)local_res10,(wchar_t *)uVar6);
    }
    nPriority = *(int *)(this + 0x40);
    pvVar4 = GetCurrentThread();
    local_res8 = GetThreadPriority(pvVar4);
    if (local_res8 != 0x7fffffff) {
      pvVar4 = GetCurrentThread();
      BVar2 = SetThreadPriority(pvVar4,nPriority);
      if (BVar2 == 0) {
        local_res8 = 0x7fffffff;
      }
    }
    local_res18 = (longlong *)0x0;
    LOCK();
    plVar5 = *(longlong **)ppv;
    if (plVar5 == (longlong *)0x0) {
      *(LPVOID *)ppv = (LPVOID)0x0;
    }
    else {
      local_res18 = plVar5;
    }
    UNLOCK();
    if (plVar5 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 8))(local_res18);
    }
    if (this[0x30] == (ComTaskHost)0x0) {
      ComCallAutoCancel::ComCallAutoCancel((ComCallAutoCancel *)local_48);
      plVar5 = (longlong *)0x0;
      LOCK();
      if (*(longlong **)ppv == (longlong *)0x0) {
        *(LPVOID *)ppv = (LPVOID)0x0;
      }
      else {
        plVar5 = *(longlong **)ppv;
      }
      UNLOCK();
      if (*(undefined8 **)(this + 0x38) == (undefined8 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = **(undefined8 **)(this + 0x38);
      }
      HVar1 = (**(code **)(*plVar5 + 0x18))(plVar5,local_res10,uVar6);
      if (local_48[0] != (HANDLE)0x0) {
        DeleteTimerQueueTimer((HANDLE)0x0,local_48[0],(HANDLE)0xffffffffffffffff);
        CoDisableCallCancellation((LPVOID)0x0);
      }
    }
    else {
      plVar5 = (longlong *)0x0;
      LOCK();
      if (*(longlong **)ppv == (longlong *)0x0) {
        *(LPVOID *)ppv = (LPVOID)0x0;
      }
      else {
        plVar5 = *(longlong **)ppv;
      }
      UNLOCK();
      if (*(undefined8 **)(this + 0x38) == (undefined8 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = **(undefined8 **)(this + 0x38);
      }
      HVar1 = (**(code **)(*plVar5 + 0x18))(plVar5,local_res10,uVar6);
    }
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x10))();
    }
    if (local_res8 != 0x7fffffff) {
      pvVar4 = GetCurrentThread();
      SetThreadPriority(pvVar4,local_res8);
    }
    if (-1 < HVar1) {
      HVar1 = 0;
      goto LAB_140006e78;
    }
  }
  HandleReportingState(this,HVar1,2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x10,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this,(char)HVar1);
  }
LAB_140006e78:
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x10))();
  }
  return HVar1;
}



===== CallDestructors @ 140006eb0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static void __cdecl ATL::CAtlArray<class ATL::CAutoPtr<class
   ATL::CDacl::CAccessAce>,class ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce>
   >::CallDestructors(class ATL::CAutoPtr<class ATL::CDacl::CAccessAce> * __ptr64,unsigned __int64)
    */

void __cdecl
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::CallDestructors(CAutoPtr<ATL::CDacl::CAccessAce> *param_1,__uint64 param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      puVar1 = *(undefined8 **)(param_1 + uVar2 * 8);
      if (puVar1 != (undefined8 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      *(undefined8 *)(param_1 + uVar2 * 8) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}



===== operator[] @ 140006f20 =====

/* public: class ATL::CAutoPtr<class ATL::CDacl::CAccessAce> & __ptr64 __cdecl ATL::CAtlArray<class
   ATL::CAutoPtr<class ATL::CDacl::CAccessAce>,class ATL::CAutoPtrElementTraits<class
   ATL::CDacl::CAccessAce> >::operator[](unsigned __int64) __ptr64 */

CAutoPtr<ATL::CDacl::CAccessAce> * __thiscall
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::operator[](CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
             *this,__uint64 param_1)

{
  if (*(ulonglong *)(this + 8) <= param_1) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8ffa9);
  }
  return (CAutoPtr<ATL::CDacl::CAccessAce> *)(*(longlong *)this + param_1 * 8);
}



===== UbpmUtilsCloseWindowEnumProc @ 140006f50 =====

undefined8 UbpmUtilsCloseWindowEnumProc(HWND param_1,DWORD *param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_res10 [2];
  
  local_res10[0] = 0;
  DVar1 = GetWindowThreadProcessId(param_1,local_res10);
  if (local_res10[0] != *param_2) {
    return 1;
  }
  BVar2 = EnumThreadWindows(DVar1,UbpmUtilsThreadWindowEnumProc,(LPARAM)param_2);
  if (((BVar2 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    DVar1 = GetLastError();
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xb,
             &WPP_b5de2147bf0a3b90b1134be7790d5069_Traceguids,DVar1);
  }
  if ((char)param_2[1] == '\0') {
    BVar2 = IsWindow(param_1);
    if (BVar2 != 0) {
      PostMessageW(param_1,0x10,0,0);
      *(undefined1 *)(param_2 + 1) = 1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
                 &WPP_b5de2147bf0a3b90b1134be7790d5069_Traceguids,param_1);
      }
    }
  }
  return 1;
}



===== UBPM_MIDL_user_allocate @ 140007080 =====

void UBPM_MIDL_user_allocate(undefined4 param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = GetProcessHeap();
                    /* WARNING: Could not recover jumptable at 0x0001400070a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapAlloc(pvVar1,8,param_1);
  return;
}



===== ComTaskMgrWnd @ 1400070c0 =====

/* public: __cdecl ComTaskMgrWnd::ComTaskMgrWnd(void) __ptr64 */

ComTaskMgrWnd * __thiscall ComTaskMgrWnd::ComTaskMgrWnd(ComTaskMgrWnd *this)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var1;
  
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  p_Var1 = std::
           _Tree_alloc<0,std::_Tree_base_types<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>_>
           ::_Buyheadnode((_Tree_alloc<0,std::_Tree_base_types<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>_>
                           *)this);
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(this + 0x50) = p_Var1;
  InitializeSRWLock((PSRWLOCK)(this + 0x48));
  *(undefined8 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0x80004001;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  return this;
}



===== _Buyheadnode @ 140007150 =====

/* public: struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64 __cdecl
   std::_Tree_alloc<0,struct std::_Tree_base_types<class ComTaskHost * __ptr64,class
   std::allocator<class ComTaskHost * __ptr64> > >::_Buyheadnode(void) __ptr64 */

_Tree_node<ComTaskHost*___ptr64,void*___ptr64> * __thiscall
std::
_Tree_alloc<0,std::_Tree_base_types<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>_>::
_Buyheadnode(_Tree_alloc<0,std::_Tree_base_types<ComTaskHost*___ptr64,std::allocator<ComTaskHost*___ptr64>_>_>
             *this)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var1;
  
  p_Var1 = operator_new(0x28);
  if (p_Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)0x0) {
                    /* WARNING: Subroutine does not return */
    _Xbad_alloc();
  }
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var1 = p_Var1;
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var1 + 8) = p_Var1;
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(p_Var1 + 0x10) = p_Var1;
  *(undefined2 *)(p_Var1 + 0x18) = 0x101;
  return p_Var1;
}



===== MakeAbsolute @ 140007190 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl ATL::CSecurityDesc::MakeAbsolute(void) __ptr64 */

void __thiscall ATL::CSecurityDesc::MakeAbsolute(CSecurityDesc *this)

{
  BOOL BVar1;
  DWORD DVar2;
  long lVar3;
  void *pAbsoluteSecurityDescriptor;
  void *pOwner;
  void *pPrimaryGroup;
  PACL pDacl;
  PACL pSacl;
  WORD local_res8 [4];
  DWORD local_res10 [2];
  DWORD local_res18 [2];
  DWORD local_res20 [2];
  DWORD local_48;
  DWORD local_44 [3];
  
  if (*(PSECURITY_DESCRIPTOR *)(this + 8) == (PSECURITY_DESCRIPTOR)0x0) {
    return;
  }
  pSacl = (PACL)0x0;
  local_44[1] = 0;
  local_res8[0] = 0;
  BVar1 = GetSecurityDescriptorControl(*(PSECURITY_DESCRIPTOR *)(this + 8),local_res8,local_44 + 1);
  if (BVar1 != 0) {
    if ((local_res8[0] & 0x8000) == 0) {
      return;
    }
    local_res20[0] = 0;
    local_48 = 0;
    local_res10[0] = 0;
    local_res18[0] = 0;
    local_44[0] = 0;
    MakeAbsoluteSD(*(PSECURITY_DESCRIPTOR *)(this + 8),(PSECURITY_DESCRIPTOR)0x0,local_44,(PACL)0x0,
                   &local_48,(PACL)0x0,local_res20,(PSID)0x0,local_res18,(PSID)0x0,local_res10);
    DVar2 = GetLastError();
    if (DVar2 != 0x7a) {
                    /* WARNING: Subroutine does not return */
      AtlThrowLastWin32();
    }
    pAbsoluteSecurityDescriptor = malloc((ulonglong)local_44[0]);
    if (pAbsoluteSecurityDescriptor != (void *)0x0) {
      if (local_res18[0] == 0) {
        pOwner = (void *)0x0;
      }
      else {
        pOwner = malloc((ulonglong)local_res18[0]);
        if (pOwner == (void *)0x0) goto LAB_14000729e;
      }
      if (local_res10[0] == 0) {
        pPrimaryGroup = (void *)0x0;
      }
      else {
        pPrimaryGroup = malloc((ulonglong)local_res10[0]);
        if (pPrimaryGroup == (void *)0x0) goto LAB_14000729e;
      }
      if (local_48 == 0) {
        pDacl = (PACL)0x0;
      }
      else {
        pDacl = malloc((ulonglong)local_48);
        if (pDacl == (PACL)0x0) goto LAB_14000729e;
      }
      if ((local_res20[0] == 0) || (pSacl = malloc((ulonglong)local_res20[0]), pSacl != (PACL)0x0))
      {
        BVar1 = MakeAbsoluteSD(*(PSECURITY_DESCRIPTOR *)(this + 8),pAbsoluteSecurityDescriptor,
                               local_44,pDacl,&local_48,pSacl,local_res20,pOwner,local_res18,
                               pPrimaryGroup,local_res10);
        if (BVar1 == 0) {
          lVar3 = AtlHresultFromLastError();
          free(pAbsoluteSecurityDescriptor);
          free(pOwner);
          free(pPrimaryGroup);
          free(pDacl);
          free(pSacl);
                    /* WARNING: Subroutine does not return */
          PrivateAtlThrow(lVar3);
        }
        (**(code **)(*(longlong *)this + 8))(this);
        *(void **)(this + 8) = pAbsoluteSecurityDescriptor;
        return;
      }
    }
  }
LAB_14000729e:
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7fffbffb);
}



===== ~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_> @ 140007400 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void) __ptr64 */

void __thiscall
ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
          (CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
           *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)this;
  LOCK();
  piVar1 = (int *)(lVar3 + -8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)(lVar3 + -0x18) + 8))();
  }
  return;
}



===== Copy @ 140007440 =====

/* private: void __cdecl ATL::CSid::Copy(struct _SID const & __ptr64) __ptr64 */

void __thiscall ATL::CSid::Copy(CSid *this,_SID *param_1)

{
  BOOL BVar1;
  DWORD nDestinationSidLength;
  long lVar2;
  
  BVar1 = IsValidSid(param_1);
  if (BVar1 != 0) {
    nDestinationSidLength = GetLengthSid(param_1);
    if (nDestinationSidLength < 0x45) {
      this[0x4c] = (CSid)0x1;
      BVar1 = CopySid(nDestinationSidLength,this + 8,param_1);
      if (BVar1 == 0) {
        lVar2 = AtlHresultFromLastError();
        this[0x4c] = (CSid)0x0;
                    /* WARNING: Subroutine does not return */
        PrivateAtlThrow(lVar2);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7ff8ffa9);
}



===== ~AutoRef<ITaskHandler> @ 1400074d0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl wmi::AutoRef<struct ITaskHandler>::~AutoRef<struct ITaskHandler>(void) __ptr64 */

void __thiscall wmi::AutoRef<ITaskHandler>::~AutoRef<ITaskHandler>(AutoRef<ITaskHandler> *this)

{
  if (*(longlong **)this != (longlong *)0x0) {
    (**(code **)(**(longlong **)this + 0x10))();
  }
  *(undefined8 *)this = 0;
  return;
}



===== Release @ 140007510 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual unsigned long __cdecl ComTaskHost::Release(void) __ptr64 */

ulong __thiscall ComTaskHost::Release(ComTaskHost *this)

{
  ComTaskHost *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0x14;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xd,
              &WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids,this,(char)uVar3);
  }
  if ((uVar3 == 0) && (this != (ComTaskHost *)0x0)) {
    (**(code **)(*(longlong *)this + 0x28))(this,1);
  }
  return uVar3;
}



===== GetAce @ 1400075a0 =====

/* private: virtual class ATL::CAcl::CAce const * __ptr64 __cdecl ATL::CDacl::GetAce(unsigned
   int)const __ptr64 */

CAce * __thiscall ATL::CDacl::GetAce(CDacl *this,uint param_1)

{
  if (*(ulonglong *)(this + 0x20) <= (ulonglong)param_1) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8ffa9);
  }
  return *(CAce **)(*(longlong *)(this + 0x18) + (ulonglong)param_1 * 8);
}



===== ~InterlockedAutoRef<ITaskHandler> @ 1400075cc =====

/* public: __cdecl InterlockedAutoRef<struct ITaskHandler>::~InterlockedAutoRef<struct
   ITaskHandler>(void) __ptr64 */

void __thiscall
InterlockedAutoRef<ITaskHandler>::~InterlockedAutoRef<ITaskHandler>
          (InterlockedAutoRef<ITaskHandler> *this)

{
  ITaskHandler *in_RDX;
  
  operator=(this,in_RDX);
  return;
}



===== operator= @ 1400075f0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: class InterlockedAutoRef<struct ITaskHandler> & __ptr64 __cdecl InterlockedAutoRef<struct
   ITaskHandler>::operator=(struct ITaskHandler * __ptr64) __ptr64 */

InterlockedAutoRef<struct_ITaskHandler> * __thiscall
InterlockedAutoRef<ITaskHandler>::operator=
          (InterlockedAutoRef<ITaskHandler> *this,ITaskHandler *param_1)

{
  longlong *plVar1;
  
  LOCK();
  plVar1 = *(longlong **)this;
  *(undefined8 *)this = 0;
  UNLOCK();
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return (InterlockedAutoRef<struct_ITaskHandler> *)this;
}



===== ~AutoThreadPriority @ 140007620 =====

/* public: __cdecl AutoThreadPriority::~AutoThreadPriority(void) __ptr64 */

void __thiscall AutoThreadPriority::~AutoThreadPriority(AutoThreadPriority *this)

{
  int nPriority;
  HANDLE hThread;
  
  nPriority = *(int *)this;
  if (nPriority == 0x7fffffff) {
    return;
  }
  hThread = GetCurrentThread();
                    /* WARNING: Could not recover jumptable at 0x000140007646. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetThreadPriority(hThread,nPriority);
  return;
}



===== `scalar_deleting_destructor' @ 140007660 =====

/* private: void * __ptr64 __cdecl _bstr_t::Data_t::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall _bstr_t::Data_t::_scalar_deleting_destructor_(Data_t *this,uint param_1)

{
  if (*(BSTR *)this != (BSTR)0x0) {
    SysFreeString(*(BSTR *)this);
    *(undefined8 *)this = 0;
  }
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8));
    *(undefined8 *)(this + 8) = 0;
  }
  operator_delete(this);
  return this;
}



===== AddRef @ 1400076d0 =====

/* public: virtual unsigned long __cdecl ComTaskHost::AddRef(void) __ptr64 */

ulong __thiscall ComTaskHost::AddRef(ComTaskHost *this)

{
  ComTaskHost *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x14;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,
              &WPP_e3bcaed62523302f0a82482d58f13b85_Traceguids,this,(char)(iVar2 + 1U));
  }
  return iVar2 + 1U;
}



===== s_sync'' @ 140007730 =====

void `dynamic_atexit_destructor_for_'ShutdownMgr::s_sync__(void)

{
  ComTaskMgrBase::[ComTaskMgr]::CleanupSetAdd((_ComTaskMgr_ *)&ShutdownMgr::s_sync);
  return;
}



===== ~_bstr_t @ 140007750 =====

/* public: __cdecl _bstr_t::~_bstr_t(void) __ptr64 */

void __thiscall _bstr_t::~_bstr_t(_bstr_t *this)

{
  Data_t *pDVar1;
  int iVar2;
  Data_t *this_00;
  uint in_EDX;
  
  this_00 = *(Data_t **)this;
  if (this_00 != (Data_t *)0x0) {
    LOCK();
    pDVar1 = this_00 + 0x10;
    iVar2 = *(int *)pDVar1;
    *(int *)pDVar1 = *(int *)pDVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      Data_t::_scalar_deleting_destructor_(this_00,in_EDX);
    }
    *(undefined8 *)this = 0;
  }
  return;
}



===== ~InterlockedAutoHandle @ 140007790 =====

/* public: __cdecl InterlockedAutoHandle::~InterlockedAutoHandle(void) __ptr64 */

void __thiscall InterlockedAutoHandle::~InterlockedAutoHandle(InterlockedAutoHandle *this)

{
  HANDLE hObject;
  
  LOCK();
  hObject = *(HANDLE *)this;
  *(undefined8 *)this = 0;
  UNLOCK();
  if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
    CloseHandle(hObject);
  }
  return;
}



===== s_hEvent'' @ 1400077c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void `dynamic_atexit_destructor_for_'ShutdownMgr::s_hEvent__(void)

{
  HANDLE hObject;
  
  hObject = _s_hEvent;
  LOCK();
  _s_hEvent = (HANDLE)0x0;
  UNLOCK();
  if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
    CloseHandle(hObject);
  }
  return;
}



===== `scalar_deleting_destructor' @ 1400077f0 =====

/* protected: virtual void * __ptr64 __cdecl ComTaskMgrBase::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall ComTaskMgrBase::_scalar_deleting_destructor_(ComTaskMgrBase *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `dynamic_initializer_for_'g_strheap'' @ 140007830 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ATL::_dynamic_initializer_for__g_strheap__(void)

{
  DAT_1400159b0 = GetProcessHeap();
  DAT_1400159b8 = 0;
  _g_strheap = &CWin32Heap::_vftable_;
  atexit(_dynamic_atexit_destructor_for__g_strheap__);
  return;
}



===== ~ShutdownGuard @ 140007874 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __cdecl ShutdownGuard::~ShutdownGuard(void) __ptr64 */

void __thiscall ShutdownGuard::~ShutdownGuard(ShutdownGuard *this)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  *(undefined4 *)this = 0;
  UNLOCK();
  LOCK();
  iVar1 = _s_sync + -1;
  UNLOCK();
  bVar2 = _s_sync == 1;
  _s_sync = iVar1;
  if (bVar2) {
    LOCK();
    if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
      _s_hEvent = (HANDLE)0xffffffffffffffff;
    }
    UNLOCK();
    SetEvent(_s_hEvent);
  }
  return;
}



===== Release @ 1400078c0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl ATL::CStringData::Release(void) __ptr64 */

void __thiscall ATL::CStringData::Release(CStringData *this)

{
  CStringData *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x10;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if (iVar2 < 2) {
    (**(code **)(**(longlong **)this + 8))(*(longlong **)this,this);
    return;
  }
  return;
}



===== ~CWin32Heap @ 1400078f0 =====

/* public: virtual __cdecl ATL::CWin32Heap::~CWin32Heap(void) __ptr64 */

void __thiscall ATL::CWin32Heap::~CWin32Heap(CWin32Heap *this)

{
  *(undefined ***)this = &_vftable_;
  if ((this[0x10] == (CWin32Heap)0x0) || (*(HANDLE *)(this + 8) == (HANDLE)0x0)) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140007909. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HeapDestroy(*(HANDLE *)(this + 8));
  return;
}



===== `dynamic_atexit_destructor_for_'g_strmgr'' @ 140007920 =====

void ATL::_dynamic_atexit_destructor_for__g_strmgr__(void)

{
  g_strmgr = (undefined *)&CAtlStringMgr::_vftable_;
  return;
}



===== GetNilString @ 140007940 =====

/* public: virtual struct ATL::CStringData * __ptr64 __cdecl ATL::CAtlStringMgr::GetNilString(void)
   __ptr64 */

CStringData * __thiscall ATL::CAtlStringMgr::GetNilString(CAtlStringMgr *this)

{
  LOCK();
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + 1;
  UNLOCK();
  return (CStringData *)(this + 0x10);
}



===== ~AutoHandle @ 140007950 =====

/* public: __cdecl wmi::AutoHandle::~AutoHandle(void) __ptr64 */

void __thiscall wmi::AutoHandle::~AutoHandle(AutoHandle *this)

{
  Close(this);
  return;
}



===== Close @ 140007968 =====

/* public: void __cdecl wmi::AutoHandle::Close(void) __ptr64 */

void __thiscall wmi::AutoHandle::Close(AutoHandle *this)

{
  if ((longlong)*(HANDLE *)this - 1U < 0xfffffffffffffffe) {
    CloseHandle(*(HANDLE *)this);
    *(undefined8 *)this = 0;
  }
  return;
}



===== StringCchCatW @ 14000799c =====

/* long __cdecl StringCchCatW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64) */

long __cdecl StringCchCatW(ushort *param_1,__uint64 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  ushort *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar7 = 0x200;
  puVar3 = param_1;
  do {
    if (*puVar3 == 0) break;
    puVar3 = puVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar6 = -(ulonglong)(lVar7 != 0) & 0x200U - lVar7;
  uVar2 = ~-(uint)(lVar7 != 0) & 0x80070057;
  if (lVar7 != 0) {
    puVar3 = param_1 + uVar6;
    lVar7 = 0x200 - uVar6;
    if (lVar7 != 0) {
      lVar4 = 0x7ffffffe;
      lVar8 = (longlong)param_3 - (longlong)puVar3;
      do {
        if ((lVar4 == 0) || (uVar1 = *(ushort *)(lVar8 + (longlong)puVar3), uVar1 == 0)) break;
        *puVar3 = uVar1;
        lVar4 = lVar4 + -1;
        puVar3 = puVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    puVar5 = puVar3 + -1;
    if (lVar7 != 0) {
      puVar5 = puVar3;
    }
    *puVar5 = 0;
    uVar2 = ~-(uint)(lVar7 != 0) & 0x8007007a;
  }
  return uVar2;
}



===== Initialize @ 140007a44 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static long __cdecl ShutdownMgr::Initialize(void) */

long __cdecl ShutdownMgr::Initialize(void)

{
  ulonglong uVar1;
  HANDLE hObject;
  DWORD DVar2;
  HANDLE pvVar3;
  
  LOCK();
  _s_sync = 1;
  UNLOCK();
  LOCK();
  DAT_1400159a4 = 1;
  UNLOCK();
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  hObject = _s_hEvent;
  LOCK();
  UNLOCK();
  uVar1 = (longlong)_s_hEvent - 1;
  _s_hEvent = pvVar3;
  if (uVar1 < 0xfffffffffffffffe) {
    CloseHandle(hObject);
  }
  LOCK();
  if (_s_hEvent == (HANDLE)0xffffffffffffffff) {
    _s_hEvent = (HANDLE)0xffffffffffffffff;
  }
  UNLOCK();
  if (_s_hEvent == (HANDLE)0x0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



===== _Lrotate @ 140007ad0 =====

/* protected: void __cdecl std::_Tree<class std::_Tset_traits<class ComTaskHost * __ptr64,struct
   std::less<class ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost * __ptr64>,0>
   >::_Lrotate(struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64) __ptr64
    */

void __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::_Lrotate(_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
           *this,_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x10);
  *(longlong *)(param_1 + 0x10) = *plVar1;
  if (*(char *)(*plVar1 + 0x19) == '\0') {
    *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*plVar1 + 8) = param_1;
  }
  plVar1[1] = *(longlong *)(param_1 + 8);
  if (param_1 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8)) {
    *(longlong **)(*(longlong *)this + 8) = plVar1;
  }
  else {
    plVar2 = *(longlong **)(param_1 + 8);
    if (param_1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)*plVar2) {
      *plVar2 = (longlong)plVar1;
    }
    else {
      plVar2[2] = (longlong)plVar1;
    }
  }
  *plVar1 = (longlong)param_1;
  *(longlong **)(param_1 + 8) = plVar1;
  return;
}



===== IsObjectAce @ 140007b20 =====

/* public: virtual bool __cdecl ATL::CAcl::CAce::IsObjectAce(void)const __ptr64 */

bool __thiscall ATL::CAcl::CAce::IsObjectAce(CAce *this)

{
  return false;
}



===== UpdateStatus @ 140007b30 =====

/* public: virtual long __cdecl ComTaskHost::UpdateStatus(short,unsigned short * __ptr64) __ptr64 */

long __thiscall ComTaskHost::UpdateStatus(ComTaskHost *this,short param_1,ushort *param_2)

{
  return 0;
}



===== GetLength @ 140007b40 =====

/* public: virtual unsigned int __cdecl ATL::CDacl::CAccessAce::GetLength(void)const __ptr64 */

uint __thiscall ATL::CDacl::CAccessAce::GetLength(CAccessAce *this)

{
  DWORD DVar1;
  
  DVar1 = GetLengthSid(this + 0x10);
  return DVar1 + 8;
}



===== GetTaskName @ 140007b70 =====

/* public: virtual unsigned short const * __ptr64 __cdecl ComTaskHost::GetTaskName(void) __ptr64 */

ushort * __thiscall ComTaskHost::GetTaskName(ComTaskHost *this)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)0x0;
  if (*(undefined8 **)(this + 0x28) != (undefined8 *)0x0) {
    puVar1 = (ushort *)**(undefined8 **)(this + 0x28);
  }
  return puVar1;
}



===== `dynamic_atexit_destructor_for_'g_strheap'' @ 140007b90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ATL::_dynamic_atexit_destructor_for__g_strheap__(void)

{
  _g_strheap = &CWin32Heap::_vftable_;
  if ((DAT_1400159b8 != '\0') && (DAT_1400159b0 != (HANDLE)0x0)) {
    HeapDestroy(DAT_1400159b0);
  }
  return;
}



===== GetAceCount @ 140007bd0 =====

/* public: virtual unsigned int __cdecl ATL::CDacl::GetAceCount(void)const __ptr64 */

uint __thiscall ATL::CDacl::GetAceCount(CDacl *this)

{
  return *(uint *)(this + 0x20);
}



===== ~ComCallAutoCancel @ 140007bdc =====

/* public: __cdecl ComCallAutoCancel::~ComCallAutoCancel(void) __ptr64 */

void __thiscall ComCallAutoCancel::~ComCallAutoCancel(ComCallAutoCancel *this)

{
  if (*(HANDLE *)this != (HANDLE)0x0) {
    DeleteTimerQueueTimer((HANDLE)0x0,*(HANDLE *)this,(HANDLE)0xffffffffffffffff);
    CoDisableCallCancellation((LPVOID)0x0);
  }
  return;
}



===== s_hEvent'' @ 140007c20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void `dynamic_initializer_for_'ShutdownMgr::s_hEvent__(void)

{
  LOCK();
  _s_hEvent = 0;
  UNLOCK();
  atexit(`dynamic_atexit_destructor_for_'ShutdownMgr::s_hEvent__);
  return;
}



===== ~SrwLockExclusiveScope @ 140007c3c =====

/* public: __cdecl SrwLockExclusiveScope::~SrwLockExclusiveScope(void) __ptr64 */

void __thiscall SrwLockExclusiveScope::~SrwLockExclusiveScope(SrwLockExclusiveScope *this)

{
                    /* WARNING: Could not recover jumptable at 0x000140007c3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ReleaseSRWLockExclusive(*(PSRWLOCK *)this);
  return;
}



===== AceType @ 140007c60 =====

/* public: virtual unsigned char __cdecl ATL::CDacl::CAccessAce::AceType(void)const __ptr64 */

uchar __thiscall ATL::CDacl::CAccessAce::AceType(CAccessAce *this)

{
  return this[0x90] == (CAccessAce)0x0;
}



===== Clone @ 140007c80 =====

/* public: virtual struct ATL::IAtlStringMgr * __ptr64 __cdecl ATL::CAtlStringMgr::Clone(void)
   __ptr64 */

CAtlStringMgr * __thiscall ATL::CAtlStringMgr::Clone(CAtlStringMgr *this,IException *param_1)

{
  return this;
}



===== CleanupSetAdd @ 140007ca0 =====

/* public: virtual void __cdecl ComTaskMgrBase::[ComTaskMgr]::CleanupSetAdd(class ComTaskHost *
   __ptr64) __ptr64 */

void __thiscall ComTaskMgrBase::[ComTaskMgr]::CleanupSetAdd(_ComTaskMgr_ *this)

{
  return;
}



===== AtlThrowLastWin32 @ 140007cb0 =====

/* void __cdecl ATL::AtlThrowLastWin32(void) */

void __cdecl ATL::AtlThrowLastWin32(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(DVar1);
}



===== PrivateAtlThrow @ 140007cdc =====

/* void __cdecl ATL::PrivateAtlThrow(long) */

void __cdecl ATL::PrivateAtlThrow(long param_1)

{
  undefined **local_48;
  undefined1 local_40;
  char *local_38;
  undefined8 local_30;
  undefined8 local_28;
  long local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_40 = 0;
  local_48 = &wmi::GenericException::_vftable_;
  local_30 = 0;
  local_28 = 0;
  local_38 = "";
  local_1c = 0xffffffff;
  local_18 = 0xffffffff;
  local_20 = param_1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_48,(ThrowInfo *)&_TI3_AVGenericException_wmi__);
}



===== StopTaskThread @ 140007d30 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* private: static unsigned long __cdecl ComTaskHost::StopTaskThread(void * __ptr64) */

ulong __cdecl ComTaskHost::StopTaskThread(void *param_1)

{
  longlong *plVar1;
  int iVar2;
  ulong uVar3;
  BOOL BVar4;
  HANDLE pvVar5;
  longlong *plVar6;
  bool bVar7;
  ulong auStackX_10 [2];
  int iStackX_18;
  HANDLE apvStack_28 [2];
  
  auStackX_10[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x13,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,param_1);
  }
  uVar3 = WaitForTaskStartCompletion(param_1);
  if (-1 < (int)uVar3) {
    iVar2 = *(int *)((longlong)param_1 + 0x40);
    pvVar5 = GetCurrentThread();
    iStackX_18 = GetThreadPriority(pvVar5);
    if (iStackX_18 != 0x7fffffff) {
      pvVar5 = GetCurrentThread();
      BVar4 = SetThreadPriority(pvVar5,iVar2);
      if (BVar4 == 0) {
        iStackX_18 = 0x7fffffff;
      }
    }
    if (*(char *)((longlong)param_1 + 0x30) == '\0') {
      ComCallAutoCancel::ComCallAutoCancel((ComCallAutoCancel *)apvStack_28);
      plVar6 = (longlong *)0x0;
      LOCK();
      plVar1 = *(longlong **)((longlong)param_1 + 0x48);
      if (plVar1 == (longlong *)0x0) {
        *(longlong *)((longlong)param_1 + 0x48) = 0;
      }
      else {
        plVar6 = plVar1;
      }
      UNLOCK();
      uVar3 = (**(code **)(*plVar6 + 0x20))(plVar6,auStackX_10);
      if (apvStack_28[0] != (HANDLE)0x0) {
        DeleteTimerQueueTimer((HANDLE)0x0,apvStack_28[0],(HANDLE)0xffffffffffffffff);
        CoDisableCallCancellation((LPVOID)0x0);
      }
    }
    else {
      plVar6 = (longlong *)0x0;
      LOCK();
      plVar1 = *(longlong **)((longlong)param_1 + 0x48);
      if (plVar1 == (longlong *)0x0) {
        *(longlong *)((longlong)param_1 + 0x48) = 0;
      }
      else {
        plVar6 = plVar1;
      }
      UNLOCK();
      uVar3 = (**(code **)(*plVar6 + 0x20))(plVar6,auStackX_10);
    }
    iVar2 = iStackX_18;
    if (iStackX_18 != 0x7fffffff) {
      pvVar5 = GetCurrentThread();
      SetThreadPriority(pvVar5,iVar2);
    }
    if (-1 < (int)uVar3) {
      uVar3 = auStackX_10[0];
    }
  }
  if (uVar3 == 0x80073c8d) {
    EnterCriticalSection((LPCRITICAL_SECTION)((longlong)param_1 + 0x60));
    if (*(int *)((longlong)param_1 + 0x58) == 0) {
      LOCK();
      bVar7 = *(int *)((longlong)param_1 + 0x10) == 8;
      if (bVar7) {
        *(int *)((longlong)param_1 + 0x10) = 1;
      }
      UNLOCK();
      if (!bVar7) {
        uVar3 = 0x8000ffff;
        LeaveCriticalSection((LPCRITICAL_SECTION)((longlong)param_1 + 0x60));
        goto LAB_1400046eb;
      }
    }
    else {
      uVar3 = *(ulong *)((longlong)param_1 + 0x5c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)((longlong)param_1 + 0x60));
    if (uVar3 == 0x80073c8d) goto LAB_140004777;
  }
LAB_1400046eb:
  ReleaseLifetimeRef(param_1,(ushort *)L"StopTaskWorker");
LAB_140004777:
  if ((((int)uVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x14,
              &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,param_1,(char)uVar3);
  }
  return uVar3;
}



===== _Min @ 140007d3c =====

/* public: static struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64
   __cdecl std::_Tree_val<struct std::_Tree_simple_types<class ComTaskHost * __ptr64> >::_Min(struct
   std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64) */

_Tree_node<ComTaskHost*___ptr64,void*___ptr64> * __cdecl
std::_Tree_val<std::_Tree_simple_types<ComTaskHost*___ptr64>_>::_Min
          (_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> *param_1)

{
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> _Var1;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var2;
  _Tree_node<ComTaskHost*___ptr64,void*___ptr64> *p_Var3;
  
  _Var1 = (*(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)param_1)[0x19];
  p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)param_1;
  while (p_Var3 = p_Var2, _Var1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64>)0x0) {
    p_Var2 = *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)p_Var3;
    _Var1 = p_Var2[0x19];
    param_1 = (_Tree_node<class_ComTaskHost*___ptr64,void*___ptr64> *)p_Var3;
  }
  return (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)param_1;
}



===== Shutdown @ 140007d60 =====

/* public: long __cdecl ComTaskHost::Shutdown(void) __ptr64 */

long __thiscall ComTaskHost::Shutdown(ComTaskHost *this)

{
  int iVar1;
  int iVar2;
  long lVar3;
  bool bVar4;
  
  lVar3 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0x17,
             &WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,this);
  }
  iVar2 = 1;
  LOCK();
  iVar1 = *(int *)(this + 0x10);
  if (iVar1 == 1) {
    *(int *)(this + 0x10) = 9;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if (iVar1 == 1) {
    lVar3 = StopTaskWorker(this);
    bVar4 = lVar3 == -0x7ff8c373;
  }
  else {
    if (iVar2 == 4) goto LAB_140007dc8;
    bVar4 = iVar2 == 7;
  }
  if (!bVar4) {
    return lVar3;
  }
LAB_140007dc8:
  ReleaseLifetimeRef(this,(ushort *)L"Shutdown");
  return lVar3;
}



===== ~ComTaskMgrBase @ 140007dec =====

/* protected: virtual __cdecl ComTaskMgrBase::~ComTaskMgrBase(void) __ptr64 */

void __thiscall ComTaskMgrBase::~ComTaskMgrBase(ComTaskMgrBase *this)

{
  *(undefined ***)this = &_vftable_;
  return;
}



===== ~CSecurityDesc @ 140007e00 =====

/* public: virtual __cdecl ATL::CSecurityDesc::~CSecurityDesc(void) __ptr64 */

void __thiscall ATL::CSecurityDesc::~CSecurityDesc(CSecurityDesc *this)

{
  *(undefined ***)this = &_vftable_;
  Clear(this);
  return;
}



===== DebuggerBreakForTaskHang @ 140007e18 =====

/* protected: static void __cdecl ComTaskMgrBase::DebuggerBreakForTaskHang(int) */

void __cdecl ComTaskMgrBase::DebuggerBreakForTaskHang(int param_1)

{
  code *pcVar1;
  BOOL BVar2;
  wchar_t *pwVar3;
  
  BVar2 = IsDebuggerPresent();
  if ((BVar2 == 0) && (DAT_7ffe02d4 == '\0')) {
    return;
  }
  pwVar3 = L"ComTaskHost::StartTaskWorker or ComTaskHost::StopTaskWorker";
  if (param_1 == 0) {
    pwVar3 = L"ComTaskMgrWnd::ShutdownTasksThreadProc";
  }
  DbgPrintEx(0x1c,0,
             "\n================================================================================================\nWARNING: A possible task hung was detected for a COM-based scheduled task!\nThe likely culprit task is stuck on the same stack with %S.\nThis break is recoverable. If you let it go we will continue to wait on the task to complete.\n================================================================================================\n\n"
             ,pwVar3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AtlHresultFromLastError @ 140007e74 =====

/* long __cdecl ATL::AtlHresultFromLastError(void) */

long __cdecl ATL::AtlHresultFromLastError(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



===== pre_c_init @ 140007ea0 =====

/* WARNING: Removing unreachable block (ram,0x000140007ef8) */
/* WARNING: Removing unreachable block (ram,0x000140007eb2) */
/* WARNING: Removing unreachable block (ram,0x000140007f00) */

undefined8 pre_c_init(void)

{
  code *_Except;
  int iVar1;
  
  DAT_140015300 = 0;
  iVar1 = _get_image_app_type(2);
  __set_app_type(iVar1);
  __onexitend = 0xffffffffffffffff;
  __onexitbegin = 0xffffffffffffffff;
  *(undefined4 *)_fmode_exref = _fmode;
  _Except = _commode_exref;
  *(undefined4 *)_commode_exref = _commode;
  _wsetargv((_exception *)_Except);
  if (__defaultmatherr == 0) {
    __setusermatherr(_wsetargv);
  }
  return 0;
}



===== pre_cpp_init @ 140007f80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pre_cpp_init(void)

{
  _DAT_140015304 = _newmode;
  _DAT_1400152ec =
       __wgetmainargs(&DAT_1400152e8,&DAT_1400152f0,&DAT_1400152f8,_dowildcard,&DAT_140015304);
  return;
}



===== __wmainCRTStartup @ 140007fd0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

int __wmainCRTStartup(void)

{
  void *pvVar1;
  bool bVar2;
  bool bVar3;
  WCHAR WVar4;
  int iVar5;
  BOOL BVar6;
  void *pvVar7;
  WCHAR *lpCmdLine;
  longlong *plVar8;
  uint nShowCmd;
  bool bVar9;
  _STARTUPINFOW local_78;
  
  local_78._4_4_ = 0;
  memset(&local_78,0,100);
  bVar3 = false;
  GetStartupInfoW(&local_78);
  pvVar1 = StackBase;
  bVar2 = false;
  while( true ) {
    pvVar7 = (void *)0x0;
    LOCK();
    bVar9 = __native_startup_lock == (void *)0x0;
    if (bVar9) {
      __native_startup_lock = pvVar1;
    }
    else {
      pvVar7 = __native_startup_lock;
    }
    UNLOCK();
    if (bVar9) goto LAB_140008052;
    if (pvVar7 == pvVar1) break;
    Sleep(1000);
  }
  bVar2 = true;
LAB_140008052:
  if (__native_startup_state == 1) {
    _amsg_exit(0x1f);
  }
  else if (__native_startup_state == 0) {
    __native_startup_state = 1;
    iVar5 = 0;
    for (plVar8 = &__xi_a; plVar8 < &__xi_z; plVar8 = plVar8 + 1) {
      if (iVar5 != 0) {
        return 0xff;
      }
      if (*plVar8 != 0) {
        iVar5 = (*(code *)*plVar8)();
      }
    }
    if (iVar5 != 0) {
      return 0xff;
    }
  }
  else {
    DAT_1400152e4 = 1;
  }
  if (__native_startup_state == 1) {
    _initterm(&__xc_a,&__xc_z);
    __native_startup_state = 2;
  }
  if (!bVar2) {
    LOCK();
    __native_startup_lock = (void *)0x0;
    UNLOCK();
  }
  if ((__dyn_tls_init_callback != (code *)0x0) &&
     (BVar6 = _IsNonwritableInCurrentImage((PBYTE)&__dyn_tls_init_callback), BVar6 != 0)) {
    (*__dyn_tls_init_callback)(0,2);
  }
  lpCmdLine = *(WCHAR **)_wcmdln_exref;
  if (lpCmdLine == (WCHAR *)0x0) {
    iVar5 = 0xff;
  }
  else {
    while ((WVar4 = *lpCmdLine, 0x20 < (ushort)WVar4 || ((WVar4 != L'\0' && (bVar3))))) {
      if (WVar4 == L'\"') {
        bVar3 = !bVar3;
      }
      lpCmdLine = lpCmdLine + 1;
    }
    while ((ushort)(WVar4 + L'\xffff') < 0x20) {
      lpCmdLine = lpCmdLine + 1;
      WVar4 = *lpCmdLine;
    }
    nShowCmd = 10;
    if (((byte)local_78.dwFlags & 1) != 0) {
      nShowCmd = (uint)local_78.wShowWindow;
    }
    DAT_1400152e0 =
         wWinMain((HINSTANCE)&IMAGE_DOS_HEADER_140000000,(HINSTANCE)0x0,lpCmdLine,nShowCmd);
    if (DAT_140015300 == 0) {
                    /* WARNING: Subroutine does not return */
      exit(DAT_1400152e0);
    }
    iVar5 = DAT_1400152e0;
    if (DAT_1400152e4 == 0) {
      _cexit();
      iVar5 = DAT_1400152e0;
    }
  }
  return iVar5;
}



===== entry @ 140008250 =====

void entry(void)

{
  __security_init_cookie();
  __wmainCRTStartup();
  return;
}



===== __CxxUnhandledExceptionFilter @ 140008280 =====

/* long __cdecl __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS * __ptr64) */

long __cdecl __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *param_1)

{
  int iVar1;
  PEXCEPTION_RECORD pEVar2;
  
  pEVar2 = param_1->ExceptionRecord;
  if (((pEVar2->ExceptionCode == 0xe06d7363) && (pEVar2->NumberParameters == 4)) &&
     ((iVar1 = (int)pEVar2->ExceptionInformation[0], iVar1 + 0xe66cfae0U < 3 || (iVar1 == 0x1994000)
      ))) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  return 0;
}



===== __CxxSetUnhandledExceptionFilter @ 1400082c0 =====

undefined8 __CxxSetUnhandledExceptionFilter(void)

{
  SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}



===== _XcptFilter @ 1400082de =====

int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400082de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



===== RtlpImageNtHeader @ 1400082ec =====

int * RtlpImageNtHeader(short *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  if (((((longlong)param_1 - 1U < 0xfffffffffffffffe) && (*param_1 == 0x5a4d)) &&
      (-1 < *(int *)(param_1 + 0x1e))) &&
     ((*(uint *)(param_1 + 0x1e) < 0x10000000 &&
      (piVar1 = (int *)((longlong)*(int *)(param_1 + 0x1e) + (longlong)param_1), *piVar1 != 0x4550))
     )) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== _get_image_app_type @ 140008348 =====

undefined4 _get_image_app_type(undefined4 param_1)

{
  HMODULE pHVar1;
  int *piVar2;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((pHVar1 != (HMODULE)0x0) &&
     (piVar2 = RtlpImageNtHeader((short *)pHVar1), piVar2 != (int *)0x0)) {
    if ((short)piVar2[0x17] == 2) {
      return 2;
    }
    if ((short)piVar2[0x17] == 3) {
      param_1 = 1;
    }
  }
  return param_1;
}



===== _amsg_exit @ 140008394 =====

void __cdecl _amsg_exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140008394. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _amsg_exit(param_1);
  return;
}



===== _wsetargv @ 1400083a0 =====

int __cdecl _wsetargv(_exception *_Except)

{
  return 0;
}



===== _FindPESection @ 1400083b0 =====

PIMAGE_SECTION_HEADER __cdecl _FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  iVar1 = *(int *)(pImageBase + 0x3c);
  uVar3 = 0;
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase +
           (ulonglong)*(ushort *)(pImageBase + (longlong)iVar1 + 0x14) + 0x18 + (longlong)iVar1);
  if (*(ushort *)(pImageBase + (longlong)iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + (longlong)iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



===== _IsNonwritableInCurrentImage @ 140008400 =====

BOOL __cdecl _IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  uint uVar2;
  PIMAGE_SECTION_HEADER p_Var3;
  
  BVar1 = _ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_140000000);
  uVar2 = 0;
  if (BVar1 != 0) {
    p_Var3 = _FindPESection((PBYTE)&IMAGE_DOS_HEADER_140000000,(DWORD_PTR)(pTarget + -0x140000000));
    uVar2 = 0;
    if (p_Var3 != (PIMAGE_SECTION_HEADER)0x0) {
      uVar2 = ~(p_Var3->Characteristics >> 0x1f) & 1;
    }
  }
  return uVar2;
}



===== _ValidateImageBase @ 140008460 =====

BOOL __cdecl _ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (BOOL)((short)*(int *)((longlong)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) ==
                 0x20b);
  }
  return 0;
}



===== __security_init_cookie @ 140008494 =====

void __cdecl __security_init_cookie(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_res18;
  
  local_res18.dwLowDateTime = 0;
  local_res18.dwHighDateTime = 0;
  local_res10.QuadPart = 0;
  if (__security_cookie == 0x2b992ddfa232) {
    GetSystemTimeAsFileTime(&local_res18);
    local_res8 = local_res18;
    DVar1 = GetCurrentProcessId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetCurrentThreadId();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)local_res8 ^ (ulonglong)DVar1 << 0x18);
    DVar1 = GetTickCount();
    local_res8 = (_FILETIME)((ulonglong)DVar1 ^ (ulonglong)local_res8 ^ (ulonglong)&local_res8);
    QueryPerformanceCounter(&local_res10);
    __security_cookie =
         (local_res10.QuadPart << 0x20 ^ local_res10.QuadPart ^ (ulonglong)local_res8) &
         0xffffffffffff;
    if (__security_cookie == 0x2b992ddfa232) {
      __security_cookie = 0x2b992ddfa233;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== _initterm @ 140008573 =====

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008573. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



===== __C_specific_handler @ 14000857f =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000857f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== memset @ 140008596 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140008596. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== _onexit @ 1400085a4 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  _onexit_t p_Var1;
  longlong local_res10;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  local_res10 = __onexitbegin;
  if (__onexitbegin == -1) {
    p_Var1 = _onexit(_Func);
  }
  else {
    _lock(8);
    local_res10 = __onexitbegin;
    local_res18[0] = __onexitend;
    p_Var1 = (_onexit_t)__dllonexit(_Func,&local_res10,local_res18);
    __onexitbegin = local_res10;
    __onexitend = local_res18[0];
    _unlock(8);
  }
  return p_Var1;
}



===== atexit @ 14000863c =====

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



===== __raise_securityfailure @ 14000865c =====

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x000140008689. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}



===== __report_gsfailure @ 1400086a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  ulonglong local_38 [2];
  PVOID local_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_38[1] = 0;
  local_28 = (PVOID)0x0;
  local_38[0] = 0;
  RtlCaptureContext(&DAT_1400153c0);
  ControlPc = DAT_1400154b8;
  FunctionEntry = RtlLookupFunctionEntry(DAT_1400154b8,local_38,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
    DAT_1400154b8 = *DAT_140015458;
    DAT_140015458 = DAT_140015458 + 1;
  }
  else {
    RtlVirtualUnwind(0,local_38[0],ControlPc,FunctionEntry,(PCONTEXT)&DAT_1400153c0,&local_28,
                     local_38 + 1,(PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  _DAT_140015330 = DAT_1400154b8;
  _DAT_140015320 = 0xc0000409;
  _DAT_140015324 = 1;
  _DAT_140015338 = 3;
  DAT_140015340 = 2;
  DAT_140015348 = __security_cookie;
  DAT_140015350 = __security_cookie_complement;
  uStack_20 = __security_cookie;
  uStack_18 = __security_cookie_complement;
  _DAT_140015440 = _StackCookie;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_14000d288);
  return;
}



===== _lock @ 140008844 =====

void __cdecl _lock(int _File)

{
                    /* WARNING: Could not recover jumptable at 0x000140008844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _lock(_File);
  return;
}



===== _unlock @ 140008850 =====

void __cdecl _unlock(int _File)

{
                    /* WARNING: Could not recover jumptable at 0x000140008850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _unlock(_File);
  return;
}



===== __dllonexit @ 14000885c =====

void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000885c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



===== __tailMerge_ext_ms_win_imm_l1_1_0_dll @ 140008870 =====

void __tailMerge_ext_ms_win_imm_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_R9;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012db0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001400088e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,in_XMM2_Qa,in_R9);
  return;
}



===== DelayLoad_ImmDisableIME @ 1400088ef =====

void DelayLoad_ImmDisableIME
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_imm_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsImmDisableIMEPresent @ 140008904 =====

undefined1 IsImmDisableIMEPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_140015898 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_140015898 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_14000d298), -1 < iVar2)) {
      DAT_140015898 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== ApiSetQueryApiSetPresence @ 140008958 =====

void ApiSetQueryApiSetPresence(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140008958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ApiSetQueryApiSetPresence();
  return;
}



===== operator_new @ 140008964 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  int iVar1;
  void *pvVar2;
  
  do {
    pvVar2 = malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}



===== bad_alloc @ 14000899c =====

/* public: __cdecl std::bad_alloc::bad_alloc(class std::bad_alloc const & __ptr64) __ptr64 */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this,bad_alloc *param_1)

{
  exception::exception((exception *)this,(exception *)param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== bad_alloc @ 1400089c4 =====

/* public: __cdecl std::bad_alloc::bad_alloc(void) __ptr64 */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this)

{
  char *local_res8 [4];
  
  local_res8[0] = "bad allocation";
  exception::exception((exception *)this,local_res8,1);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== out_of_range @ 140008a0c =====

/* public: __cdecl std::out_of_range::out_of_range(class std::out_of_range const & __ptr64) __ptr64
    */

out_of_range * __thiscall std::out_of_range::out_of_range(out_of_range *this,logic_error *param_1)

{
  exception::exception((exception *)this,(exception *)param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== out_of_range @ 140008a34 =====

/* public: __cdecl std::out_of_range::out_of_range(char const * __ptr64) __ptr64 */

out_of_range * __thiscall std::out_of_range::out_of_range(out_of_range *this,char *param_1)

{
  char *local_res8 [4];
  
  local_res8[0] = param_1;
  exception::exception((exception *)this,local_res8);
  *(undefined ***)this = &_vftable_;
  return this;
}



===== ~bad_alloc @ 140008a6c =====

/* public: virtual __cdecl std::bad_alloc::~bad_alloc(void) __ptr64 */

void __thiscall std::bad_alloc::~bad_alloc(bad_alloc *this)

{
  *(undefined ***)this = &_vftable_;
  exception::~exception((exception *)this);
  return;
}



===== ~length_error @ 140008a84 =====

/* public: virtual __cdecl std::length_error::~length_error(void) __ptr64 */

void __thiscall std::length_error::~length_error(length_error *this)

{
                    /* WARNING: Could not recover jumptable at 0x00014000936c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  exception::~exception((exception *)this);
  return;
}



===== `vector_deleting_destructor' @ 140008a90 =====

/* public: virtual void * __ptr64 __cdecl std::error_category::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
std::error_category::_vector_deleting_destructor_(error_category *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140008ac0 =====

/* public: virtual void * __ptr64 __cdecl std::bad_alloc::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall std::bad_alloc::_scalar_deleting_destructor_(bad_alloc *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140008b00 =====

/* public: virtual void * __ptr64 __cdecl std::out_of_range::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall std::out_of_range::_vector_deleting_destructor_(out_of_range *this,uint param_1)

{
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== _Copy @ 140008b38 =====

/* public: void __cdecl std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Copy(unsigned __int64,unsigned __int64) __ptr64 */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Copy
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,__uint64 param_1,
          __uint64 param_2)

{
  ulonglong uVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *_Dst;
  ulonglong uVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar3;
  ulonglong uVar4;
  
  uVar4 = param_1 | 0xf;
  if (uVar4 == 0xffffffffffffffff) {
    uVar4 = param_1;
  }
  else {
    uVar1 = *(ulonglong *)(this + 0x18);
    uVar2 = uVar1 >> 1;
    if ((uVar4 / 3 < uVar2) && (uVar4 = uVar2 + uVar1, -uVar2 - 2 < uVar1)) {
      uVar4 = 0xfffffffffffffffe;
    }
  }
  _Dst = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0;
  if (uVar4 + 1 != 0) {
    _Dst = operator_new(uVar4 + 1);
    if (_Dst == (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0) {
                    /* WARNING: Subroutine does not return */
      _Xbad_alloc();
    }
  }
  if (param_2 != 0) {
    if (*(ulonglong *)(this + 0x18) < 0x10) {
      pbVar3 = this;
    }
    else {
      pbVar3 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    memcpy(_Dst,pbVar3,param_2);
  }
  if (0xf < *(ulonglong *)(this + 0x18)) {
    operator_delete(*(void **)this);
  }
  *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this = _Dst;
  *(ulonglong *)(this + 0x18) = uVar4;
  pbVar3 = this;
  if (0xf < uVar4) {
    pbVar3 = _Dst;
  }
  *(__uint64 *)(this + 0x10) = param_2;
  pbVar3[param_2] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  return;
}



===== _Tidy @ 140008c38 =====

/* public: void __cdecl std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Tidy(bool,unsigned __int64) __ptr64 */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,bool param_1,
          __uint64 param_2)

{
  void *_Src;
  
  if ((param_1) && (0xf < *(ulonglong *)(this + 0x18))) {
    _Src = *(void **)this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2);
    }
    operator_delete(_Src);
  }
  *(undefined8 *)(this + 0x18) = 0xf;
  *(__uint64 *)(this + 0x10) = param_2;
  this[param_2] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  return;
}



===== _Xbad_alloc @ 140008c98 =====

/* void __cdecl std::_Xbad_alloc(void) */

void __cdecl std::_Xbad_alloc(void)

{
  bad_alloc local_28 [40];
  
  bad_alloc::bad_alloc(local_28);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&_TI2_AVbad_alloc_std__);
}



===== _Xlen @ 140008cc0 =====

/* public: void __cdecl std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Xlen(void)const __ptr64 */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Xlen
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this)

{
                    /* WARNING: Subroutine does not return */
  _Xlength_error("string too long");
}



===== _Xlength_error @ 140008cd8 =====

/* void __cdecl std::_Xlength_error(char const * __ptr64) */

void __cdecl std::_Xlength_error(char *param_1)

{
  out_of_range local_28 [40];
  
  out_of_range::out_of_range(local_28,param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&_TI3_AVlength_error_std__);
}



===== _Xout_of_range @ 140008d04 =====

/* void __cdecl std::_Xout_of_range(char const * __ptr64) */

void __cdecl std::_Xout_of_range(char *param_1)

{
  out_of_range local_28 [40];
  
  out_of_range::out_of_range(local_28,param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&_TI3_AVout_of_range_std__);
}



===== _Xran @ 140008d30 =====

/* public: void __cdecl std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Xran(void)const __ptr64 */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Xran
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this)

{
                    /* WARNING: Subroutine does not return */
  _Xout_of_range("invalid string position");
}



===== assign @ 140008d48 =====

/* public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &
   __ptr64 __cdecl std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   const & __ptr64,unsigned __int64,unsigned __int64) __ptr64 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
          __uint64 param_2,__uint64 param_3)

{
  code *pcVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  ulonglong uVar4;
  
  if (param_2 <= *(ulonglong *)(param_1 + 0x10)) {
    uVar4 = *(ulonglong *)(param_1 + 0x10) - param_2;
    if (param_3 < uVar4) {
      uVar4 = param_3;
    }
    if (this != (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_1) {
      if (uVar4 == 0xffffffffffffffff) {
        _Xlen(this);
        pcVar1 = (code *)swi(3);
        pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (*pcVar1)();
        return pbVar3;
      }
      if (*(ulonglong *)(this + 0x18) < uVar4) {
        _Copy(this,uVar4,*(__uint64 *)(this + 0x10));
        if (uVar4 == 0) {
          return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 this;
        }
      }
      else if (uVar4 == 0) {
        if (*(ulonglong *)(this + 0x18) < 0x10) {
          pbVar2 = this;
        }
        else {
          pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
        }
        *(undefined8 *)(this + 0x10) = 0;
        *pbVar2 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
        return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
      }
      if (0xf < *(ulonglong *)(param_1 + 0x18)) {
        param_1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                   param_1;
      }
      if (*(ulonglong *)(this + 0x18) < 0x10) {
        pbVar2 = this;
      }
      else {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      memcpy(pbVar2,param_1 + param_2,uVar4);
      if (*(ulonglong *)(this + 0x18) < 0x10) {
        pbVar2 = this;
      }
      else {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      *(ulonglong *)(this + 0x10) = uVar4;
      pbVar2[uVar4] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
      return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
    }
    uVar4 = uVar4 + param_2;
    if (uVar4 <= *(ulonglong *)(this + 0x10)) {
      pbVar2 = this;
      if (0xf < *(ulonglong *)(this + 0x18)) {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      *(ulonglong *)(this + 0x10) = uVar4;
      pbVar2[uVar4] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
      erase(this,0,param_2);
      return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
    }
  }
  _Xran(this);
  pcVar1 = (code *)swi(3);
  pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
           (*pcVar1)();
  return pbVar3;
}



===== assign @ 140008e54 =====

/* public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &
   __ptr64 __cdecl std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const * __ptr64,unsigned __int64) __ptr64 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,char *param_1,
          __uint64 param_2)

{
  code *pcVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  
  if (param_1 != (char *)0x0) {
    if (*(ulonglong *)(this + 0x18) < 0x10) {
      pbVar2 = this;
    }
    else {
      pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    if (pbVar2 <= param_1) {
      pbVar2 = this;
      if (0xf < *(ulonglong *)(this + 0x18)) {
        pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      if (param_1 < pbVar2 + *(longlong *)(this + 0x10)) {
        if (*(ulonglong *)(this + 0x18) < 0x10) {
          pbVar2 = this;
        }
        else {
          pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
        }
        pbVar3 = assign(this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)this,(longlong)param_1 - (longlong)pbVar2,param_2);
        return pbVar3;
      }
    }
  }
  if (param_2 == 0xffffffffffffffff) {
    _Xlen(this);
    pcVar1 = (code *)swi(3);
    pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (*pcVar1)();
    return pbVar3;
  }
  if (*(ulonglong *)(this + 0x18) < param_2) {
    _Copy(this,param_2,*(__uint64 *)(this + 0x10));
    if (param_2 == 0) {
      return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
    }
  }
  else if (param_2 == 0) {
    if (*(ulonglong *)(this + 0x18) < 0x10) {
      pbVar2 = this;
    }
    else {
      pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    *(undefined8 *)(this + 0x10) = 0;
    *pbVar2 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
  }
  if (*(ulonglong *)(this + 0x18) < 0x10) {
    pbVar2 = this;
  }
  else {
    pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
  }
  memcpy(pbVar2,param_1,param_2);
  if (*(ulonglong *)(this + 0x18) < 0x10) {
    pbVar2 = this;
  }
  else {
    pbVar2 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
  }
  *(__uint64 *)(this + 0x10) = param_2;
  pbVar2[param_2] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



===== default_error_condition @ 140008f50 =====

/* public: virtual class std::error_condition __cdecl
   std::_System_error_category::default_error_condition(int)const __ptr64 */

int * __thiscall
std::_System_error_category::default_error_condition(_System_error_category *this,int param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined **ppuVar3;
  undefined4 in_register_00000014;
  int in_R8D;
  
  piVar1 = (int *)CONCAT44(in_register_00000014,param_1);
  pcVar2 = _Syserror_map(in_R8D);
  *piVar1 = in_R8D;
  ppuVar3 = &_Error_objects<int>::_Generic_object;
  if (pcVar2 == (char *)0x0) {
    ppuVar3 = &_Error_objects<int>::_System_object;
  }
  *(undefined ***)(piVar1 + 2) = ppuVar3;
  return piVar1;
}



===== default_error_condition @ 140008fa0 =====

/* public: virtual class std::error_condition __cdecl
   std::error_category::default_error_condition(int)const __ptr64 */

undefined8 __thiscall std::error_category::default_error_condition(error_category *this,int param_1)

{
  undefined4 in_register_00000014;
  undefined4 in_R8D;
  
  *(undefined4 *)CONCAT44(in_register_00000014,param_1) = in_R8D;
  *(error_category **)(CONCAT44(in_register_00000014,param_1) + 8) = this;
  return CONCAT44(in_register_00000014,param_1);
}



===== equivalent @ 140008fc0 =====

/* public: virtual bool __cdecl std::error_category::equivalent(class std::error_code const &
   __ptr64,int)const __ptr64 */

bool __thiscall
std::error_category::equivalent(error_category *this,error_code *param_1,int param_2)

{
  if ((this == *(error_category **)(param_1 + 8)) && (*(int *)param_1 == param_2)) {
    return true;
  }
  return false;
}



===== equivalent @ 140008fe0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual bool __cdecl std::error_category::equivalent(int,class std::error_condition const
   & __ptr64)const __ptr64 */

bool __thiscall
std::error_category::equivalent(error_category *this,int param_1,error_condition *param_2)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_18 [16];
  
  piVar2 = (int *)(**(code **)(*(longlong *)this + 0x18))(this,local_18,param_1);
  if ((*(longlong *)(piVar2 + 2) == *(longlong *)(param_2 + 8)) && (*piVar2 == *(int *)param_2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



===== erase @ 140009020 =====

/* public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &
   __ptr64 __cdecl std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::erase(unsigned __int64,unsigned __int64) __ptr64 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::erase
          (basic_string<char,std::char_traits<char>,std::allocator<char>_> *this,__uint64 param_1,
          __uint64 param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  longlong lVar5;
  
  uVar1 = *(ulonglong *)(this + 0x10);
  if (uVar1 < param_1) {
    _Xran(this);
    pcVar2 = (code *)swi(3);
    pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (*pcVar2)();
    return pbVar4;
  }
  if (param_2 < uVar1 - param_1) {
    if (param_2 != 0) {
      if (*(ulonglong *)(this + 0x18) < 0x10) {
        pbVar3 = this;
      }
      else {
        pbVar3 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      lVar5 = uVar1 - param_2;
      if (lVar5 - param_1 != 0) {
        memmove(pbVar3 + param_1,pbVar3 + param_1 + param_2,lVar5 - param_1);
      }
      if (*(ulonglong *)(this + 0x18) < 0x10) {
        pbVar3 = this;
      }
      else {
        pbVar3 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
      }
      *(longlong *)(this + 0x10) = lVar5;
      pbVar3[lVar5] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    }
  }
  else {
    if (*(ulonglong *)(this + 0x18) < 0x10) {
      pbVar3 = this;
    }
    else {
      pbVar3 = *(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)this;
    }
    *(__uint64 *)(this + 0x10) = param_1;
    pbVar3[param_1] = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



===== message @ 1400090c0 =====

/* public: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __cdecl std::_Generic_error_category::message(int)const __ptr64 */

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
std::_Generic_error_category::message(_Generic_error_category *this,int param_1)

{
  char *pcVar1;
  __uint64 _Var2;
  undefined4 in_register_00000014;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this_00;
  char *pcVar3;
  int in_R8D;
  
  this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
            CONCAT44(in_register_00000014,param_1);
  _Var2 = 0;
  pcVar1 = _Syserror_map(in_R8D);
  *(undefined8 *)(this_00 + 0x18) = 0xf;
  *(undefined8 *)(this_00 + 0x10) = 0;
  pcVar3 = "unknown error";
  if (pcVar1 != (char *)0x0) {
    pcVar3 = pcVar1;
  }
  *this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  if (*pcVar3 != '\0') {
    _Var2 = 0xffffffffffffffff;
    do {
      _Var2 = _Var2 + 1;
    } while (pcVar3[_Var2] != '\0');
  }
  basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign(this_00,pcVar3,_Var2);
  return this_00;
}



===== message @ 140009130 =====

/* public: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __cdecl std::_Iostream_error_category::message(int)const __ptr64 */

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
std::_Iostream_error_category::message(_Iostream_error_category *this,int param_1)

{
  char *pcVar1;
  __uint64 _Var2;
  undefined4 in_register_00000014;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this_00;
  char *pcVar3;
  int in_R8D;
  
  this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
            CONCAT44(in_register_00000014,param_1);
  _Var2 = 0;
  if (in_R8D == 1) {
    *(undefined8 *)(this_00 + 0x18) = 0xf;
    _Var2 = 0x15;
    *(undefined8 *)(this_00 + 0x10) = 0;
    *this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    pcVar3 = "iostream stream error";
  }
  else {
    pcVar1 = _Syserror_map(in_R8D);
    *(undefined8 *)(this_00 + 0x18) = 0xf;
    *(undefined8 *)(this_00 + 0x10) = 0;
    pcVar3 = "unknown error";
    if (pcVar1 != (char *)0x0) {
      pcVar3 = pcVar1;
    }
    *this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
    if (*pcVar3 != '\0') {
      _Var2 = 0xffffffffffffffff;
      do {
        _Var2 = _Var2 + 1;
      } while (pcVar3[_Var2] != '\0');
    }
  }
  basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign(this_00,pcVar3,_Var2);
  return this_00;
}



===== message @ 1400091c0 =====

/* public: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __cdecl std::_System_error_category::message(int)const __ptr64 */

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
std::_System_error_category::message(_System_error_category *this,int param_1)

{
  char *pcVar1;
  __uint64 _Var2;
  undefined4 in_register_00000014;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this_00;
  char *pcVar3;
  int in_R8D;
  
  this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
            CONCAT44(in_register_00000014,param_1);
  _Var2 = 0;
  pcVar1 = _Winerror_map(in_R8D);
  *(undefined8 *)(this_00 + 0x18) = 0xf;
  *(undefined8 *)(this_00 + 0x10) = 0;
  pcVar3 = "unknown error";
  if (pcVar1 != (char *)0x0) {
    pcVar3 = pcVar1;
  }
  *this_00 = (basic_string<char,std::char_traits<char>,std::allocator<char>_>)0x0;
  if (*pcVar3 != '\0') {
    _Var2 = 0xffffffffffffffff;
    do {
      _Var2 = _Var2 + 1;
    } while (pcVar3[_Var2] != '\0');
  }
  basic_string<char,std::char_traits<char>,std::allocator<char>_>::assign(this_00,pcVar3,_Var2);
  return this_00;
}



===== name @ 140009230 =====

/* public: virtual char const * __ptr64 __cdecl std::_Generic_error_category::name(void)const
   __ptr64 */

char * __thiscall std::_Generic_error_category::name(_Generic_error_category *this)

{
  return "generic";
}



===== name @ 140009240 =====

/* public: virtual char const * __ptr64 __cdecl std::_Iostream_error_category::name(void)const
   __ptr64 */

char * __thiscall std::_Iostream_error_category::name(_Iostream_error_category *this)

{
  return "iostream";
}



===== name @ 140009250 =====

/* public: virtual char const * __ptr64 __cdecl std::_System_error_category::name(void)const __ptr64
    */

char * __thiscall std::_System_error_category::name(_System_error_category *this)

{
  return "system";
}



===== _Syserror_map @ 140009260 =====

/* char const * __ptr64 __cdecl std::_Syserror_map(int) */

char * __cdecl std::_Syserror_map(int param_1)

{
  longlong *plVar1;
  int *piVar2;
  
  piVar2 = &DAT_14000d870;
  do {
    if (*piVar2 == param_1) {
      return *(char **)(piVar2 + 2);
    }
    plVar1 = (longlong *)(piVar2 + 6);
    piVar2 = piVar2 + 4;
  } while (*plVar1 != 0);
  return (char *)0x0;
}



===== _Winerror_map @ 140009290 =====

/* char const * __ptr64 __cdecl std::_Winerror_map(int) */

char * __cdecl std::_Winerror_map(int param_1)

{
  longlong *plVar1;
  int *piVar2;
  
  piVar2 = &DAT_14000d3c0;
  do {
    if (*piVar2 == param_1) {
      return *(char **)(piVar2 + 2);
    }
    plVar1 = (longlong *)(piVar2 + 6);
    piVar2 = piVar2 + 4;
  } while (*plVar1 != 0);
  return (char *)0x0;
}



===== __CxxFrameHandler4 @ 1400092be =====

void __CxxFrameHandler4(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400092be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __CxxFrameHandler4();
  return;
}



===== __std_terminate @ 1400092cc =====

void __std_terminate(void)

{
                    /* WARNING: Subroutine does not return */
  terminate();
}



===== `vector_deleting_destructor' @ 1400092e0 =====

/* public: virtual void * __ptr64 __cdecl type_info::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall type_info::_vector_deleting_destructor_(type_info *this,uint param_1)

{
  type_info::~type_info(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== operator_delete @ 140009316 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140009316. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}



===== _purecall @ 140009330 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140009330. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== _callnewh @ 14000933c =====

int __cdecl _callnewh(size_t _Size)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000933c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _callnewh(_Size);
  return iVar1;
}



===== exception @ 140009348 =====

/* public: __cdecl exception::exception(char const * __ptr64 const & __ptr64) __ptr64 */

void __thiscall exception::exception(exception *this,char **param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140009348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  exception(this,param_1);
  return;
}



===== exception @ 140009354 =====

/* public: __cdecl exception::exception(char const * __ptr64 const & __ptr64,int) __ptr64 */

void __thiscall exception::exception(exception *this,char **param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x000140009354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  exception(this,param_1,param_2);
  return;
}



===== exception @ 140009360 =====

/* public: __cdecl exception::exception(class exception const & __ptr64) __ptr64 */

void __thiscall exception::exception(exception *this,exception *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000140009360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  exception(this,param_1);
  return;
}



===== ~exception @ 14000936c =====

/* public: virtual __cdecl exception::~exception(void) __ptr64 */

void __thiscall exception::~exception(exception *this)

{
                    /* WARNING: Could not recover jumptable at 0x00014000936c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~exception(this);
  return;
}



===== what @ 140009380 =====

/* public: virtual char const * __ptr64 __cdecl exception::what(void)const __ptr64 */

char * __thiscall exception::what(exception *this)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140009380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = what(this);
  return pcVar1;
}



===== _CxxThrowException @ 14000938c =====

void __stdcall _CxxThrowException(void *pExceptionObject,ThrowInfo *pThrowInfo)

{
                    /* WARNING: Could not recover jumptable at 0x00014000938c. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  _CxxThrowException(pExceptionObject,pThrowInfo);
  return;
}



===== memcpy @ 1400093a4 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400093a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



===== memmove @ 1400093b0 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400093b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memmove(_Dst,_Src,_Size);
  return pvVar1;
}



===== __GSHandlerCheck @ 1400093bc =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400093e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)(*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0);
  }
  return uVar1;
}



===== __tailMerge_rpcrt4_dll @ 14000943b =====

void __tailMerge_rpcrt4_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_R9;
  undefined8 in_XMM2_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012dd0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001400094b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,in_XMM2_Qa,in_R9);
  return;
}



===== DelayLoad_RpcAsyncInitializeHandle @ 1400094ba =====

void DelayLoad_RpcAsyncInitializeHandle
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_api_ms_win_core_com_l1_1_0_dll @ 1400094c6 =====

void __tailMerge_api_ms_win_core_com_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012df0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000953d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,param_3,in_R9);
  return;
}



===== DelayLoad_CoUninitialize @ 140009545 =====

void DelayLoad_CoUninitialize
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcBindingFromStringBindingW @ 140009557 =====

void DelayLoad_RpcBindingFromStringBindingW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcStringBindingComposeW @ 140009569 =====

void DelayLoad_RpcStringBindingComposeW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcAsyncCompleteCall @ 14000957b =====

void DelayLoad_RpcAsyncCompleteCall
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcBindingSetAuthInfoExW @ 14000958d =====

void DelayLoad_RpcBindingSetAuthInfoExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcStringFreeW @ 14000959f =====

void DelayLoad_RpcStringFreeW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcAsyncCancelCall @ 1400095b1 =====

void DelayLoad_RpcAsyncCancelCall
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RpcBindingFree @ 1400095c3 =====

void DelayLoad_RpcBindingFree
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeEx @ 1400095d5 =====

void DelayLoad_CoInitializeEx
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_NdrClientCall3 @ 1400095e7 =====

void DelayLoad_NdrClientCall3
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ndr64AsyncClientCall @ 1400095f9 =====

void DelayLoad_Ndr64AsyncClientCall
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_rpcrt4_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoInitializeSecurity @ 14000960b =====

void DelayLoad_CoInitializeSecurity
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_oleaut32_dll @ 140009617 =====

void __tailMerge_oleaut32_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012e10,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000968e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_2 @ 140009696 =====

void DelayLoad_Ordinal_2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_oleaut32_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_Ordinal_6 @ 1400096a8 =====

void DelayLoad_Ordinal_6(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  __tailMerge_oleaut32_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoCreateInstance @ 1400096ba =====

void DelayLoad_CoCreateInstance
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoEnableCallCancellation @ 1400096cc =====

void DelayLoad_CoEnableCallCancellation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoDisableCallCancellation @ 1400096de =====

void DelayLoad_CoDisableCallCancellation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CoCancelCall @ 1400096f0 =====

void DelayLoad_CoCancelCall
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_api_ms_win_core_com_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_ntuser_misc_l1_1_0_dll @ 1400096fc =====

void __tailMerge_ext_ms_win_ntuser_misc_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012e30,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140009773. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,param_3,in_R9);
  return;
}



===== DelayLoad_ShutdownBlockReasonCreate @ 14000977b =====

void DelayLoad_ShutdownBlockReasonCreate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_misc_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_ShutdownBlockReasonDestroy @ 14000978d =====

void DelayLoad_ShutdownBlockReasonDestroy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_misc_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll @ 140009799 =====

void __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012e50,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140009810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_PostMessageW @ 140009818 =====

void DelayLoad_PostMessageW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DispatchMessageW @ 14000982a =====

void DelayLoad_DispatchMessageW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PeekMessageW @ 14000983c =====

void DelayLoad_PeekMessageW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_TranslateMessage @ 14000984e =====

void DelayLoad_TranslateMessage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_PostQuitMessage @ 140009860 =====

void DelayLoad_PostQuitMessage
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_message_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_ntuser_synch_l1_1_0_dll @ 14000986c =====

void __tailMerge_ext_ms_win_ntuser_synch_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012e70,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x0001400098e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,in_XMM1_Qa,param_3,in_R9);
  return;
}



===== DelayLoad_MsgWaitForMultipleObjects @ 1400098eb =====

void DelayLoad_MsgWaitForMultipleObjects
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_synch_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll @ 1400098f7 =====

void __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  undefined8 in_R9;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012e90,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x00014000996e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,in_R9);
  return;
}



===== DelayLoad_EnumThreadWindows @ 140009976 =====

void DelayLoad_EnumThreadWindows
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_IsWindow @ 140009988 =====

void DelayLoad_IsWindow(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_GetWindowThreadProcessId @ 14000999a =====

void DelayLoad_GetWindowThreadProcessId
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DefWindowProcW @ 1400099ac =====

void DelayLoad_DefWindowProcW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_CreateWindowExW @ 1400099be =====

void DelayLoad_CreateWindowExW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_DestroyWindow @ 1400099d0 =====

void DelayLoad_DestroyWindow
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_window_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsCreateWindowExWPresent @ 1400099e4 =====

undefined1 IsCreateWindowExWPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_140015910 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_140015910 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_14000dd68), -1 < iVar2)) {
      DAT_140015910 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== __tailMerge_ext_ms_win_ntuser_windowclass_l1_1_0_dll @ 140009a32 =====

void __tailMerge_ext_ms_win_ntuser_windowclass_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_R9;
  undefined8 in_XMM1_Qa;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012eb0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140009aa9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,in_XMM1_Qa,param_3,in_R9);
  return;
}



===== DelayLoad_UnregisterClassW @ 140009ab1 =====

void DelayLoad_UnregisterClassW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_windowclass_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== DelayLoad_RegisterClassW @ 140009ac3 =====

void DelayLoad_RegisterClassW
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_windowclass_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== __tailMerge_ext_ms_win_ntuser_windowstation_l1_1_0_dll @ 140009acf =====

void __tailMerge_ext_ms_win_ntuser_windowstation_l1_1_0_dll
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_RAX;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_RCX;
  
  UNRECOVERED_JUMPTABLE = (code *)__delayLoadHelper2(&ImgDelayDescr_140012ed0,in_RAX);
                    /* WARNING: Could not recover jumptable at 0x000140009b46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(in_RCX,param_2,param_3,param_4);
  return;
}



===== DelayLoad_EnumDesktopWindows @ 140009b4e =====

void DelayLoad_EnumDesktopWindows
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __tailMerge_ext_ms_win_ntuser_windowstation_l1_1_0_dll(param_1,param_2,param_3,param_4);
  return;
}



===== IsEnumDesktopWindowsPresent @ 140009b60 =====

undefined1 IsEnumDesktopWindowsPresent(void)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_140015940 == 1) {
    uVar1 = 1;
  }
  else {
    if ((DAT_140015940 != 2) && (iVar2 = ApiSetQueryApiSetPresence(&DAT_14000ddd8), -1 < iVar2)) {
      DAT_140015940 = 2;
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== WppControlCallback @ 140009bc0 =====

undefined8 WppControlCallback(int param_1,longlong param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *param_3 = 0;
  if (param_1 == 4) {
    uVar3 = GetTraceLoggerHandle(param_4);
    uVar1 = GetTraceEnableLevel(uVar3);
    uVar2 = GetTraceEnableFlags(uVar3);
  }
  else {
    if (param_1 != 5) {
      return 0x57;
    }
    uVar3 = 0;
    uVar2 = 0;
    uVar1 = 0;
  }
  if (((*(byte *)(param_2 + 0x1a) & 2) != 0) && (*(longlong *)(param_2 + 0x10) != 0)) {
    param_2 = *(longlong *)(param_2 + 0x10);
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  *(undefined8 *)(param_2 + 0x10) = uVar3;
  *(undefined1 *)(param_2 + 0x19) = uVar1;
  return 0;
}



===== UbpmUtilsCloseWinApp @ 140009c58 =====

/* unsigned long __cdecl UbpmUtilsCloseWinApp(unsigned long) */

ulong __cdecl UbpmUtilsCloseWinApp(ulong param_1)

{
  char cVar1;
  ulong local_res10;
  char local_res14;
  
  local_res14 = '\0';
  if ((param_1 == 0) ||
     (local_res10 = param_1, cVar1 = IsEnumDesktopWindowsPresent(), cVar1 == '\0')) {
    return 0x57;
  }
  EnumDesktopWindows((HDESK)0x0,UbpmUtilsCloseWindowEnumProc,(LPARAM)&local_res10);
  return ~-(uint)(local_res14 != '\0') & 0x2f6;
}



===== UbpmUtilsThreadWindowEnumProc @ 140009cb0 =====

undefined8 UbpmUtilsThreadWindowEnumProc(HWND param_1,DWORD *param_2)

{
  DWORD local_res10 [6];
  
  local_res10[0] = 0;
  GetWindowThreadProcessId(param_1,local_res10);
  if (local_res10[0] == *param_2) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((WPP_GLOBAL_Control[0x1c] & 4) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),10,
                &WPP_b5de2147bf0a3b90b1134be7790d5069_Traceguids,param_1,(char)local_res10[0]);
    }
    PostMessageW(param_1,0x111,0,7);
    PostMessageW(param_1,0x111,0,2);
    PostMessageW(param_1,0x10,0,0);
    *(undefined1 *)(param_2 + 1) = 1;
  }
  return 1;
}



===== UbpmpTaskHostUnhandledExceptionFilter @ 140009d90 =====

/* long __cdecl UbpmpTaskHostUnhandledExceptionFilter(struct _EXCEPTION_POINTERS * __ptr64) */

long __cdecl UbpmpTaskHostUnhandledExceptionFilter(_EXCEPTION_POINTERS *param_1)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140009d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = RtlUnhandledExceptionFilter();
  return lVar1;
}



===== WPP_SF_d @ 140009da4 =====

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 140009de8 =====

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qd @ 140009e2c =====

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_ @ 140009e80 =====

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  EtwTraceMessage(param_1,0x2b,&WPP_fd76d537424c3f213087d14e42e29f74_Traceguids,param_2,0);
  return;
}



===== CSid @ 140009eb4 =====

/* public: __cdecl ATL::CSid::CSid(struct _SID const * __ptr64,unsigned short const * __ptr64)
   __ptr64 */

CSid * __thiscall ATL::CSid::CSid(CSid *this,_SID *param_1,ushort *param_2)

{
  bool bVar1;
  
  *(undefined ***)this = &_vftable_;
  this[0x4c] = (CSid)0x0;
  *(undefined4 *)(this + 0x50) = 7;
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(this + 0x58));
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(this + 0x60));
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(this + 0x68));
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>::
  CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(this + 0x70));
  bVar1 = LoadAccount(this,param_1,param_2);
  if (!bVar1) {
                    /* WARNING: Subroutine does not return */
    AtlThrowLastWin32();
  }
  return this;
}



===== Exception @ 140009f30 =====

/* public: __cdecl wmi::Exception::Exception(class wmi::Exception const & __ptr64) __ptr64 */

Exception * __thiscall wmi::Exception::Exception(Exception *this,Exception *param_1)

{
  this[8] = param_1[8];
  return this;
}



===== ~GenericException @ 140009f44 =====

/* public: virtual __cdecl wmi::GenericException::~GenericException(void) __ptr64 */

void __thiscall wmi::GenericException::~GenericException(GenericException *this)

{
  *(undefined ***)this = &_vftable_;
                    /* WARNING: Could not recover jumptable at 0x000140009f52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(*(void **)(this + 0x18));
  return;
}



===== `scalar_deleting_destructor' @ 140009f70 =====

/* public: virtual void * __ptr64 __cdecl ATL::CAcl::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ATL::CAcl::_scalar_deleting_destructor_(CAcl *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  free(*(void **)(this + 8));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140009fd0 =====

/* public: virtual void * __ptr64 __cdecl ATL::CDacl::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ATL::CDacl::_scalar_deleting_destructor_(CDacl *this,uint param_1)

{
  ~CDacl(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000a010 =====

/* public: virtual void * __ptr64 __cdecl ATL::CSecurityDesc::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall ATL::CSecurityDesc::_vector_deleting_destructor_(CSecurityDesc *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  Clear(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000a060 =====

/* public: virtual void * __ptr64 __cdecl ATL::CSid::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall ATL::CSid::_vector_deleting_destructor_(CSid *this,uint param_1)

{
  ~CSid(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000a0a0 =====

/* public: virtual void * __ptr64 __cdecl wmi::GenericException::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wmi::GenericException::_scalar_deleting_destructor_(GenericException *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  free(*(void **)(this + 0x18));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== Clear @ 14000a0f4 =====

/* private: void __cdecl ATL::CSid::Clear(void) __ptr64 */

void __thiscall ATL::CSid::Clear(CSid *this)

{
  *(undefined4 *)(this + 0x50) = 7;
  CSimpleStringT<unsigned_short,0>::Empty((CSimpleStringT<unsigned_short,0> *)(this + 0x58));
  CSimpleStringT<unsigned_short,0>::Empty((CSimpleStringT<unsigned_short,0> *)(this + 0x60));
  CSimpleStringT<unsigned_short,0>::Empty((CSimpleStringT<unsigned_short,0> *)(this + 0x68));
  CSimpleStringT<unsigned_short,0>::Empty((CSimpleStringT<unsigned_short,0> *)(this + 0x70));
  this[0x4c] = (CSid)0x0;
  return;
}



===== CreateShutdownTasksThread @ 14000a13c =====

/* private: long __cdecl ComTaskMgrWnd::CreateShutdownTasksThread(void) __ptr64 */

long __thiscall ComTaskMgrWnd::CreateShutdownTasksThread(ComTaskMgrWnd *this)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  DVar1 = 0;
  pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,ShutdownTasksThreadProc,(LPVOID)0x0,0,
                        (LPDWORD)0x0);
  *(HANDLE *)(this + 0x40) = pvVar2;
  if ((pvVar2 == (HANDLE)0x0) && (DVar1 = GetLastError(), 0 < (int)DVar1)) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



===== Empty @ 14000a1a8 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: void __cdecl ATL::CSimpleStringT<unsigned short,0>::Empty(void) __ptr64 */

void __thiscall ATL::CSimpleStringT<unsigned_short,0>::Empty(CSimpleStringT<unsigned_short,0> *this)

{
  longlong *plVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)this;
  plVar1 = *(longlong **)(lVar2 + -0x18);
  if (*(int *)(lVar2 + -0x10) != 0) {
    if (*(int *)(lVar2 + -8) < 0) {
      SetLength(this,0);
    }
    else {
      CStringData::Release((CStringData *)(lVar2 + -0x18));
      lVar2 = (**(code **)(*plVar1 + 0x18))(plVar1);
      *(longlong *)this = lVar2 + 0x18;
    }
  }
  return;
}



===== GetErrorCode @ 14000a210 =====

/* public: virtual unsigned long __cdecl wmi::GenericException::GetErrorCode(void)const __ptr64 */

ulong __thiscall wmi::GenericException::GetErrorCode(GenericException *this)

{
  return *(ulong *)(this + 0x28);
}



===== GetErrorParam @ 14000a220 =====

/* public: virtual unsigned long __cdecl wmi::GenericException::GetErrorParam(void)const __ptr64 */

ulong __thiscall wmi::GenericException::GetErrorParam(GenericException *this)

{
  return *(ulong *)(this + 0x24);
}



===== GetFileName @ 14000a230 =====

/* public: virtual char const * __ptr64 __cdecl wmi::GenericException::GetFileName(void)const
   __ptr64 */

char * __thiscall wmi::GenericException::GetFileName(GenericException *this)

{
  return *(char **)(this + 0x10);
}



===== GetLineNumber @ 14000a240 =====

/* public: virtual int __cdecl wmi::GenericException::GetLineNumber(void)const __ptr64 */

int __thiscall wmi::GenericException::GetLineNumber(GenericException *this)

{
  return *(int *)(this + 0x30);
}



===== GetMessageId @ 14000a250 =====

/* public: virtual unsigned long __cdecl wmi::GenericException::GetMessageId(void)const __ptr64 */

ulong __thiscall wmi::GenericException::GetMessageId(GenericException *this)

{
  return *(ulong *)(this + 0x2c);
}



===== GetMessageParam @ 14000a260 =====

/* public: virtual unsigned short const * __ptr64 __cdecl
   wmi::GenericException::GetMessageParam(void)const __ptr64 */

ushort * __thiscall wmi::GenericException::GetMessageParam(GenericException *this)

{
  return *(ushort **)(this + 0x18);
}



===== InheritedObjectType @ 14000a270 =====

/* public: virtual struct _GUID __cdecl ATL::CAcl::CAce::InheritedObjectType(void)const __ptr64 */

_GUID * __thiscall ATL::CAcl::CAce::InheritedObjectType(CAce *this,_GUID *__return_storage_ptr__)

{
  __return_storage_ptr__->Data1 = 0;
  __return_storage_ptr__->Data2 = 0;
  __return_storage_ptr__->Data3 = 0;
  __return_storage_ptr__->Data4[0] = '\0';
  __return_storage_ptr__->Data4[1] = '\0';
  __return_storage_ptr__->Data4[2] = '\0';
  __return_storage_ptr__->Data4[3] = '\0';
  __return_storage_ptr__->Data4[4] = '\0';
  __return_storage_ptr__->Data4[5] = '\0';
  __return_storage_ptr__->Data4[6] = '\0';
  __return_storage_ptr__->Data4[7] = '\0';
  return __return_storage_ptr__;
}



===== LoadAccount @ 14000a288 =====

/* public: bool __cdecl ATL::CSid::LoadAccount(struct _SID const * __ptr64,unsigned short const *
   __ptr64) __ptr64 */

bool __thiscall ATL::CSid::LoadAccount(CSid *this,_SID *param_1,ushort *param_2)

{
  Clear(this);
  if (param_1 != (_SID *)0x0) {
    CSimpleStringT<unsigned_short,0>::Empty((CSimpleStringT<unsigned_short,0> *)(this + 0x70));
    Copy(this,param_1);
  }
  return param_1 != (_SID *)0x0;
}



===== RemoveAce @ 14000a2e0 =====

/* public: virtual void __cdecl ATL::CDacl::RemoveAce(unsigned int) __ptr64 */

void __thiscall ATL::CDacl::RemoveAce(CDacl *this,uint param_1)

{
  __uint64 in_R8;
  
  CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
  ::RemoveAt((CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
              *)(this + 0x18),(ulonglong)param_1,in_R8);
  return;
}



===== RemoveAt @ 14000a2f4 =====

/* public: void __cdecl ATL::CAtlArray<class ATL::CAutoPtr<class ATL::CDacl::CAccessAce>,class
   ATL::CAutoPtrElementTraits<class ATL::CDacl::CAccessAce> >::RemoveAt(unsigned __int64,unsigned
   __int64) __ptr64 */

void __thiscall
ATL::
CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
::RemoveAt(CAtlArray<ATL::CAutoPtr<ATL::CDacl::CAccessAce>,ATL::CAutoPtrElementTraits<ATL::CDacl::CAccessAce>_>
           *this,__uint64 param_1,__uint64 param_2)

{
  ulonglong uVar1;
  rsize_t _DstSize;
  ulonglong uVar2;
  errno_t eVar3;
  longlong lVar4;
  
  uVar1 = param_1 + 1;
  if (((uVar1 < param_1) || (uVar1 == 0)) || (uVar2 = *(ulonglong *)(this + 8), uVar2 < uVar1)) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8ffa9);
  }
  CallDestructors((CAutoPtr<ATL::CDacl::CAccessAce> *)(*(longlong *)this + param_1 * 8),1);
  lVar4 = uVar2 - uVar1;
  if (lVar4 != 0) {
    _DstSize = lVar4 * 8;
    eVar3 = memmove_s((void *)(*(longlong *)this + param_1 * 8),_DstSize,
                      (void *)(*(longlong *)this + uVar1 * 8),_DstSize);
    AtlCrtErrorCheck(eVar3);
  }
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + -1;
  return;
}



===== SetLength @ 14000a390 =====

/* private: void __cdecl ATL::CSimpleStringT<unsigned short,0>::SetLength(int) __ptr64 */

void __thiscall
ATL::CSimpleStringT<unsigned_short,0>::SetLength(CSimpleStringT<unsigned_short,0> *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)(*(longlong *)this + -0xc) < param_1)) {
                    /* WARNING: Subroutine does not return */
    PrivateAtlThrow(-0x7ff8ffa9);
  }
  *(int *)(*(longlong *)this + -0x10) = param_1;
  *(undefined2 *)(*(longlong *)this + (longlong)param_1 * 2) = 0;
  return;
}



===== ThrowMemoryException @ 14000a3c8 =====

/* protected: static void __cdecl ATL::CSimpleStringT<unsigned short,0>::ThrowMemoryException(void)
    */

void __cdecl ATL::CSimpleStringT<unsigned_short,0>::ThrowMemoryException(void)

{
                    /* WARNING: Subroutine does not return */
  PrivateAtlThrow(-0x7ff8fff2);
}



===== _Rrotate @ 14000a3e0 =====

/* protected: void __cdecl std::_Tree<class std::_Tset_traits<class ComTaskHost * __ptr64,struct
   std::less<class ComTaskHost * __ptr64>,class std::allocator<class ComTaskHost * __ptr64>,0>
   >::_Rrotate(struct std::_Tree_node<class ComTaskHost * __ptr64,void * __ptr64> * __ptr64) __ptr64
    */

void __thiscall
std::
_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
::_Rrotate(_Tree<std::_Tset_traits<ComTaskHost*___ptr64,std::less<ComTaskHost*___ptr64>,std::allocator<ComTaskHost*___ptr64>,0>_>
           *this,_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)param_1;
  *(undefined8 *)param_1 = *(undefined8 *)(lVar1 + 0x10);
  if (*(char *)(*(longlong *)(lVar1 + 0x10) + 0x19) == '\0') {
    *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)(lVar1 + 0x10) + 8) = param_1;
  }
  *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(param_1 + 8);
  if (param_1 == *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(*(longlong *)this + 8)) {
    *(longlong *)(*(longlong *)this + 8) = lVar1;
  }
  else {
    plVar2 = *(longlong **)(param_1 + 8);
    if (param_1 == (_Tree_node<ComTaskHost*___ptr64,void*___ptr64> *)plVar2[2]) {
      plVar2[2] = lVar1;
    }
    else {
      *plVar2 = lVar1;
    }
  }
  *(_Tree_node<ComTaskHost*___ptr64,void*___ptr64> **)(lVar1 + 0x10) = param_1;
  *(longlong *)(param_1 + 8) = lVar1;
  return;
}



===== WPP_SF_qS @ 14000a434 =====

void WPP_SF_qS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,param_3,0xb,&local_res20,8,param_5,lVar1,0);
  return;
}



===== AddRef`adjustor{8}' @ 14000a4c0 =====

/* [thunk]:public: virtual unsigned long __cdecl ComTaskHost::AddRef`adjustor{8}' (void) __ptr64 */

ulong __thiscall ComTaskHost::AddRef_adjustor_8__(ComTaskHost *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== QueryInterface`adjustor{8}' @ 14000a4d0 =====

/* [thunk]:public: virtual long __cdecl ComTaskHost::QueryInterface`adjustor{8}' (struct _GUID const
   & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
ComTaskHost::QueryInterface_adjustor_8__(ComTaskHost *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface(this + -8,param_1,param_2);
  return lVar1;
}



===== Release`adjustor{8}' @ 14000a4e0 =====

/* [thunk]:public: virtual unsigned long __cdecl ComTaskHost::Release`adjustor{8}' (void) __ptr64 */

ulong __thiscall ComTaskHost::Release_adjustor_8__(ComTaskHost *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== WPP_SF_qD @ 14000a4f0 =====

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qDD @ 14000a544 =====

void WPP_SF_qDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,param_2,&local_res20
                  ,8,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqqS @ 14000a5ac =====

void WPP_SF_qqqS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_7 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_1a6c4c03277a3f60c8ecdbf3dacca60d_Traceguids,0xf,&local_res20,8,
                  &param_5,8,&param_6,8,pwVar2,lVar1,0);
  return;
}



===== GetContext @ 14000a670 =====

/* public: virtual long __cdecl ComTaskHost::GetContext(unsigned short * __ptr64 * __ptr64) __ptr64
    */

long __thiscall ComTaskHost::GetContext(ComTaskHost *this,ushort **param_1)

{
  BSTR pOVar1;
  
  pOVar1 = SysAllocString(L"Context Text");
  *param_1 = (ushort *)pOVar1;
  return ~-(uint)(pOVar1 != (BSTR)0x0) & 0x8007000e;
}



===== GetInput @ 14000a6b0 =====

/* public: virtual long __cdecl ComTaskHost::GetInput(unsigned short * __ptr64 * __ptr64) __ptr64 */

long __thiscall ComTaskHost::GetInput(ComTaskHost *this,ushort **param_1)

{
  BSTR pOVar1;
  long lVar2;
  
  if (param_1 == (ushort **)0x0) {
    lVar2 = -0x7ff8ffa9;
  }
  else {
    pOVar1 = SysAllocString(L"Put in input");
    *param_1 = (ushort *)pOVar1;
    lVar2 = 0;
    if (pOVar1 == (BSTR)0x0) {
      lVar2 = -0x7ff8fff2;
    }
  }
  return lVar2;
}



===== SetOutput @ 14000a700 =====

/* public: virtual long __cdecl ComTaskHost::SetOutput(unsigned short * __ptr64) __ptr64 */

long __thiscall ComTaskHost::SetOutput(ComTaskHost *this,ushort *param_1)

{
  return -0x7fffbfff;
}



===== TimerCallback @ 14000a710 =====

/* private: static void __cdecl ComCallAutoCancel::TimerCallback(void * __ptr64,unsigned char) */

void __cdecl ComCallAutoCancel::TimerCallback(void *param_1,uchar param_2)

{
  HRESULT HVar1;
  undefined8 in_R8;
  
  HVar1 = CoCancelCall(*(DWORD *)((longlong)param_1 + 8),1);
  if (((HVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((WPP_GLOBAL_Control[0x1c] & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x10),0xc,in_R8,HVar1);
  }
  return;
}



===== WPP_SF_D @ 14000a764 =====

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  EtwTraceMessage(param_1,0x2b,&WPP_6ffeac87ef183cb2cd3b93702c60c5aa_Traceguids,param_2,local_res20,
                  4,0);
  return;
}



===== AtlMultiply<unsigned___int64> @ 14000a7ac =====

/* long __cdecl ATL::AtlMultiply<unsigned __int64>(unsigned __int64 * __ptr64,unsigned
   __int64,unsigned __int64) */

long __cdecl ATL::AtlMultiply<unsigned___int64>(__uint64 *param_1,__uint64 param_2,__uint64 param_3)

{
  if (param_2 == 0) {
    *param_1 = 0;
  }
  else {
    if (0xffffffffffffffff / param_2 < param_3) {
      return -0x7ff8ffa9;
    }
    *param_1 = param_2 * param_3;
  }
  return 0;
}



===== `vector_deleting_destructor' @ 14000a7e0 =====

/* public: virtual void * __ptr64 __cdecl ATL::CAtlStringMgr::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall ATL::CAtlStringMgr::_vector_deleting_destructor_(CAtlStringMgr *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000a820 =====

/* public: virtual void * __ptr64 __cdecl ATL::CWin32Heap::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall ATL::CWin32Heap::_scalar_deleting_destructor_(CWin32Heap *this,uint param_1)

{
  ~CWin32Heap(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== Allocate @ 14000a860 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual struct ATL::CStringData * __ptr64 __cdecl ATL::CAtlStringMgr::Allocate(int,int)
   __ptr64 */

CStringData * __thiscall ATL::CAtlStringMgr::Allocate(CAtlStringMgr *this,int param_1,int param_2)

{
  long lVar1;
  CStringData *pCVar2;
  uint uVar3;
  __uint64 local_res20;
  
  if ((((param_1 < 0) || (local_res20 = 0, 0x7fffffff - param_1 < 1)) ||
      (uVar3 = param_1 + 8U & 0xfffffff8, (int)uVar3 <= param_1)) ||
     (((lVar1 = AtlMultiply<unsigned___int64>(&local_res20,(longlong)(int)uVar3,(longlong)param_2),
       lVar1 < 0 || (0xffffffffffffffe7 < local_res20)) ||
      (pCVar2 = (CStringData *)
                (**(code **)**(undefined8 **)(this + 8))
                          (*(undefined8 **)(this + 8),local_res20 + 0x18),
      pCVar2 == (CStringData *)0x0)))) {
    return (CStringData *)0x0;
  }
  *(undefined4 *)(pCVar2 + 8) = 0;
  *(uint *)(pCVar2 + 0xc) = uVar3 - 1;
  *(CAtlStringMgr **)pCVar2 = this;
  *(undefined4 *)(pCVar2 + 0x10) = 1;
  return pCVar2;
}



===== Allocate @ 14000a8f0 =====

/* public: virtual void * __ptr64 __cdecl ATL::CWin32Heap::Allocate(unsigned __int64) __ptr64 */

void * __thiscall ATL::CWin32Heap::Allocate(CWin32Heap *this,__uint64 param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a8f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)HeapAlloc(*(undefined8 *)(this + 8),0,param_1);
  return pvVar1;
}



===== Free @ 14000a910 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void __cdecl ATL::CAtlStringMgr::Free(struct ATL::CStringData * __ptr64) __ptr64
    */

void __thiscall ATL::CAtlStringMgr::Free(CAtlStringMgr *this,CStringData *param_1)

{
  (**(code **)(**(longlong **)(this + 8) + 8))();
  return;
}



===== Free @ 14000a930 =====

/* public: virtual void __cdecl ATL::CWin32Heap::Free(void * __ptr64) __ptr64 */

void __thiscall ATL::CWin32Heap::Free(CWin32Heap *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    HeapFree(*(HANDLE *)(this + 8),0,param_1);
  }
  return;
}



===== GetSize @ 14000a960 =====

/* public: virtual unsigned __int64 __cdecl ATL::CWin32Heap::GetSize(void * __ptr64) __ptr64 */

__uint64 __thiscall ATL::CWin32Heap::GetSize(CWin32Heap *this,void *param_1)

{
  __uint64 _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a969. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = HeapSize(*(undefined8 *)(this + 8),0,param_1);
  return _Var1;
}



===== Reallocate @ 14000a980 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual struct ATL::CStringData * __ptr64 __cdecl ATL::CAtlStringMgr::Reallocate(struct
   ATL::CStringData * __ptr64,int,int) __ptr64 */

CStringData * __thiscall
ATL::CAtlStringMgr::Reallocate(CAtlStringMgr *this,CStringData *param_1,int param_2,int param_3)

{
  CStringData *pCVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((param_2 < 0) || (0x7fffffff - param_2 < 1)) ||
      (uVar3 = param_2 + 8U & 0xfffffff8, (int)uVar3 <= param_2)) ||
     (((0xffffffff < (ulonglong)uVar3 * (ulonglong)(uint)param_3 ||
       (uVar2 = (uint)((ulonglong)uVar3 * (ulonglong)(uint)param_3), 0xffffffe7 < uVar2)) ||
      (pCVar1 = (CStringData *)
                (**(code **)(**(longlong **)(this + 8) + 0x10))
                          (*(longlong **)(this + 8),param_1,uVar2 + 0x18),
      pCVar1 == (CStringData *)0x0)))) {
    return (CStringData *)0x0;
  }
  *(uint *)(pCVar1 + 0xc) = uVar3 - 1;
  return pCVar1;
}



===== Reallocate @ 14000aa00 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual void * __ptr64 __cdecl ATL::CWin32Heap::Reallocate(void * __ptr64,unsigned
   __int64) __ptr64 */

void * __thiscall ATL::CWin32Heap::Reallocate(CWin32Heap *this,void *param_1,__uint64 param_2)

{
  void *pvVar1;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = (void *)(*(code *)**(undefined8 **)this)(this,param_2);
    return pvVar1;
  }
  if (param_2 == 0) {
    (**(code **)(*(longlong *)this + 8))();
    return (void *)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000aa44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)HeapReAlloc(*(undefined8 *)(this + 8),0,param_1,param_2);
  return pvVar1;
}



===== _com_error @ 14000aa58 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: __cdecl _com_error::_com_error(class _com_error const & __ptr64) __ptr64 */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  longlong *plVar1;
  
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  plVar1 = *(longlong **)(param_1 + 0x10);
  *(undefined8 *)(this + 0x18) = 0;
  *(longlong **)(this + 0x10) = plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  return this;
}



===== ~_com_error @ 14000aaa0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */
/* public: virtual __cdecl _com_error::~_com_error(void) __ptr64 */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = &_vftable_;
  if (*(longlong **)(this + 0x10) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x10) + 0x10))();
  }
  if (*(HLOCAL *)(this + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0x18));
  }
  return;
}



===== `vector_deleting_destructor' @ 14000aaf0 =====

/* public: virtual void * __ptr64 __cdecl _com_error::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall _com_error::_vector_deleting_destructor_(_com_error *this,uint param_1)

{
  ~_com_error(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== _com_raise_error @ 14000ab30 =====

/* void __cdecl _com_raise_error(long,struct IErrorInfo * __ptr64) */

void __cdecl _com_raise_error(long param_1,IErrorInfo *param_2)

{
  undefined **local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_20 = 0x8007000e;
  local_28 = &_com_error::_vftable_;
  local_18 = 0;
  uStack_10 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_28,(ThrowInfo *)&_TI1_AV_com_error__);
}



===== __GSHandlerCheck_EH4 @ 14000ab6c =====

void __GSHandlerCheck_EH4(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_4 + 0x38);
  __GSHandlerCheckCommon(param_2,param_4);
  if ((*(uint *)(lVar1 + 4) & ((*(uint *)(param_1 + 4) & 0x66) != 0) + 1) != 0) {
    __CxxFrameHandler4(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __security_check_cookie @ 14000ac10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000ac50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000ac80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ac80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000acb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== InitializeComTasksLib$catch$0 @ 14000acc0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 InitializeComTasksLib_catch_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)**(undefined8 **)(param_2 + 0x20))();
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  *(uint *)(param_2 + 0x48) = uVar1;
  return 0;
}



===== InitializeComTasksLib$catch$1 @ 14000ad10 =====

undefined8 InitializeComTasksLib_catch_1(void)

{
  return 0;
}



===== InitializeComTasksLib$catch$2 @ 14000ad40 =====

undefined8 InitializeComTasksLib_catch_2(void)

{
  return 0;
}



===== InitializeComTasksLib$catch$3 @ 14000ad70 =====

undefined8 InitializeComTasksLib_catch_3(void)

{
  return 0;
}



===== InitializeComTasksLib$catch$4 @ 14000ada0 =====

undefined8 InitializeComTasksLib_catch_4(void)

{
  return 0;
}



===== InitializeComTasksLib$catch$5 @ 14000add0 =====

undefined8 InitializeComTasksLib_catch_5(void)

{
  return 0;
}



===== InitializeComTasksLib$catch$6 @ 14000ae00 =====

undefined8 InitializeComTasksLib_catch_6(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(*(longlong *)(param_2 + 0x28) + 8);
  return 0;
}



===== dtor$1 @ 14000ae2e =====

void `ComTaskMgrBase::Initialize'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ae35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(*(void **)(param_2 + 0x48));
  return;
}



===== catch$2 @ 14000ae47 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_2(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)**(undefined8 **)(param_2 + 0x20))();
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  *(uint *)(param_2 + 0x48) = uVar1;
  return 0;
}



===== catch$3 @ 14000ae89 =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_3(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = 0x8007000e;
  return 0;
}



===== catch$4 @ 14000aeb4 =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_4(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = 0x80070057;
  return 0;
}



===== catch$5 @ 14000aedf =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_5(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = 0x80070057;
  return 0;
}



===== catch$6 @ 14000af0a =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_6(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = 0x80070057;
  return 0;
}



===== catch$7 @ 14000af35 =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_7(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = 0x80004005;
  return 0;
}



===== catch$8 @ 14000af60 =====

undefined8 `ComTaskMgrBase::Initialize'::__l1::catch_8(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(*(longlong *)(param_2 + 0x28) + 8);
  return 0;
}



===== UninitializeComTasksLib$catch$0 @ 14000af90 =====

undefined8 UninitializeComTasksLib_catch_0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(*(longlong *)(param_2 + 0x20) + 8);
  return 0;
}



===== UninitializeComTasksLib$catch$1 @ 14000afc0 =====

undefined8 UninitializeComTasksLib_catch_1(void)

{
  return 0;
}



===== UninitializeComTasksLib$catch$2 @ 14000aff0 =====

undefined8 UninitializeComTasksLib_catch_2(void)

{
  return 0;
}



===== UninitializeComTasksLib$catch$3 @ 14000b020 =====

undefined8 UninitializeComTasksLib_catch_3(void)

{
  return 0;
}



===== UninitializeComTasksLib$catch$4 @ 14000b050 =====

undefined8 UninitializeComTasksLib_catch_4(void)

{
  return 0;
}



===== UninitializeComTasksLib$catch$5 @ 14000b080 =====

undefined8 UninitializeComTasksLib_catch_5(void)

{
  return 0;
}



===== UninitializeComTasksLib$catch$6 @ 14000b0b0 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 UninitializeComTasksLib_catch_6(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)**(undefined8 **)(param_2 + 0x28))();
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  *(uint *)(param_2 + 0x40) = uVar1;
  return 0;
}



===== StartComTask$catch$0 @ 14000b100 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 StartComTask_catch_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)**(undefined8 **)(param_2 + 0x48))();
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  *(uint *)(param_2 + 0x40) = uVar1;
  return 0;
}



===== StartComTask$catch$1 @ 14000b150 =====

undefined8 StartComTask_catch_1(void)

{
  return 0;
}



===== StartComTask$catch$2 @ 14000b180 =====

undefined8 StartComTask_catch_2(void)

{
  return 0;
}



===== StartComTask$catch$3 @ 14000b1b0 =====

undefined8 StartComTask_catch_3(void)

{
  return 0;
}



===== StartComTask$catch$4 @ 14000b1e0 =====

undefined8 StartComTask_catch_4(void)

{
  return 0;
}



===== StartComTask$catch$5 @ 14000b210 =====

undefined8 StartComTask_catch_5(void)

{
  return 0;
}



===== StartComTask$catch$6 @ 14000b240 =====

undefined8 StartComTask_catch_6(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(*(longlong *)(param_2 + 0x50) + 8);
  return 0;
}



===== StopComTask$catch$0 @ 14000b270 =====

/* WARNING: Function: _guard_dispatch_icall$thunk$10345483385596137414 replaced with injection:
   guard_dispatch_icall */

undefined8 StopComTask_catch_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)**(undefined8 **)(param_2 + 0x30))();
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  *(uint *)(param_2 + 0x58) = uVar1;
  return 0;
}



===== StopComTask$catch$1 @ 14000b2c0 =====

undefined8 StopComTask_catch_1(void)

{
  return 0;
}



===== StopComTask$catch$2 @ 14000b2f0 =====

undefined8 StopComTask_catch_2(void)

{
  return 0;
}



===== StopComTask$catch$3 @ 14000b320 =====

undefined8 StopComTask_catch_3(void)

{
  return 0;
}



===== StopComTask$catch$4 @ 14000b350 =====

undefined8 StopComTask_catch_4(void)

{
  return 0;
}



===== StopComTask$catch$5 @ 14000b380 =====

undefined8 StopComTask_catch_5(void)

{
  return 0;
}



===== StopComTask$catch$6 @ 14000b3b0 =====

undefined8 StopComTask_catch_6(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(*(longlong *)(param_2 + 0x38) + 8);
  return 0;
}



===== dtor$0 @ 14000b3e0 =====

void `ComTaskMgrBase::InitComSecurity'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ATL::CSecurityDesc::~CSecurityDesc((CSecurityDesc *)(param_2 + 0x58));
  return;
}



===== dtor$1 @ 14000b400 =====

void `ComTaskMgrBase::InitComSecurity'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  ATL::CSid::~CSid((CSid *)(param_2 + 0xb0));
  return;
}



===== dtor$3 @ 14000b420 =====

void `ComTaskMgrBase::InitComSecurity'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  ATL::CDacl::~CDacl((CDacl *)(param_2 + 0x70));
  return;
}



===== dtor$6 @ 14000b440 =====

void `ComTaskMgrBase::InitComSecurity'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
  ATL::CSid::~CSid((CSid *)(param_2 + 0x130));
  return;
}



===== dtor$0 @ 14000b460 =====

void `ATL::CSid::CSid'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x20) + 0x58));
  return;
}



===== dtor$1 @ 14000b480 =====

void `ATL::CSid::CSid'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x20) + 0x60));
  return;
}



===== dtor$2 @ 14000b4a0 =====

void `ATL::CSid::CSid'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x20) + 0x68));
  return;
}



===== dtor$3 @ 14000b4c0 =====

void `ATL::CSid::CSid'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x20) + 0x70));
  return;
}



===== dtor$0 @ 14000b4e0 =====

void `ATL::CDacl::AddAllowedAce'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ATL::CAutoPtr<ATL::CDacl::CAccessAce>::Free((CAutoPtr<ATL::CDacl::CAccessAce> *)(param_2 + 0x68));
  return;
}



===== dtor$1 @ 14000b500 =====

void `ATL::CDacl::AddAllowedAce'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b507. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(*(void **)(param_2 + 0x30));
  return;
}



===== catch$2 @ 14000b520 =====

undefined8 `ATL::CDacl::AddAllowedAce'::__l1::catch_2(void)

{
  return 0;
}



===== dtor$2 @ 14000b550 =====

void `ATL::CDacl::CAccessAce::CAccessAce'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x58));
  return;
}



===== dtor$3 @ 14000b570 =====

void `ATL::CDacl::CAccessAce::CAccessAce'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x60));
  return;
}



===== dtor$4 @ 14000b590 =====

void `ATL::CDacl::CAccessAce::CAccessAce'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x68));
  return;
}



===== dtor$5 @ 14000b5b0 =====

void `ATL::CDacl::CAccessAce::CAccessAce'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  ATL::CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
  ::~CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
            ((CStringT<unsigned_short,ATL::StrTraitATL<unsigned_short,ATL::ChTraitsCRT<unsigned_short>_>_>
              *)(*(longlong *)(param_2 + 0x30) + 0x70));
  return;
}



===== dtor$0 @ 14000b5d0 =====

void `ComTaskMgrBase::[ComTaskMgr]::StopComTask'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ShutdownGuard::~ShutdownGuard((ShutdownGuard *)(param_2 + 0x38));
  return;
}



===== dtor$0 @ 14000b5f0 =====

void `ComTaskHost::Stop'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wmi::AutoHandle::~AutoHandle((AutoHandle *)(param_2 + 0x60));
  return;
}



===== dtor$0 @ 14000b610 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ShutdownGuard::~ShutdownGuard((ShutdownGuard *)(param_2 + 0x30));
  return;
}



===== dtor$1 @ 14000b630 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b637. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(*(void **)(param_2 + 0x38));
  return;
}



===== dtor$2 @ 14000b650 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  _bstr_t::~_bstr_t((_bstr_t *)(*(longlong *)(param_2 + 0x38) + 0x28));
  return;
}



===== dtor$3 @ 14000b670 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  _bstr_t::~_bstr_t((_bstr_t *)(*(longlong *)(param_2 + 0x38) + 0x38));
  return;
}



===== dtor$4 @ 14000b690 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_4(undefined8 param_1,longlong param_2)

{
  InterlockedAutoRef<ITaskHandler>::~InterlockedAutoRef<ITaskHandler>
            ((InterlockedAutoRef<ITaskHandler> *)(*(longlong *)(param_2 + 0x38) + 0x48));
  return;
}



===== dtor$5 @ 14000b6b0 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_5(undefined8 param_1,longlong param_2)

{
  InterlockedAutoHandle::~InterlockedAutoHandle
            ((InterlockedAutoHandle *)(*(longlong *)(param_2 + 0x38) + 0x50));
  return;
}



===== dtor$6 @ 14000b6d0 =====

void `ComTaskMgrBase::[ComTaskMgr]::StartComTask'::__l1::dtor_6(undefined8 param_1,longlong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b6d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(*(void **)(param_2 + 0x40));
  return;
}



===== dtor$0 @ 14000b6f0 =====

void `ComTaskHost::StopTaskWorker'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  AutoThreadPriority::~AutoThreadPriority((AutoThreadPriority *)(param_2 + 0x70));
  return;
}



===== dtor$1 @ 14000b710 =====

void `ComTaskHost::StopTaskWorker'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  ComCallAutoCancel::~ComCallAutoCancel((ComCallAutoCancel *)(param_2 + 0x30));
  return;
}



===== dtor$0 @ 14000b730 =====

void `ComTaskHost::TaskCompleted'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ShutdownGuard::~ShutdownGuard((ShutdownGuard *)(param_2 + 0xa0));
  return;
}



===== dtor$0 @ 14000b750 =====

void `ComTaskMgrWnd::[ComTaskMgr]::CleanupSetRemove'::__l1::dtor_0
               (undefined8 param_1,longlong param_2)

{
  SrwLockExclusiveScope::~SrwLockExclusiveScope((SrwLockExclusiveScope *)(param_2 + 0x48));
  return;
}



===== dtor$0 @ 14000b762 =====

void `ComTaskMgrWnd::[ComTaskMgr]::CleanupSetAdd'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  SrwLockExclusiveScope::~SrwLockExclusiveScope((SrwLockExclusiveScope *)(param_2 + 0x58));
  return;
}



===== catch$0 @ 14000b780 =====

void `std::
     _Tree<std::_Tset_traits<ComTaskHost_*,std::less<ComTaskHost_*>,std::allocator<ComTaskHost_*>,0>_>
     ::_Insert_nohint<ComTaskHost_*_const_&,std::_Nil>'::__l1::catch_0(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 14000b79d =====

void `std::_Tree_buy<ComTaskHost_*,std::allocator<ComTaskHost_*>_>::_Buynode<ComTaskHost_*_const_&>'
     ::__l1::catch_0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x38));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 14000b7ca =====

void `std::_Tree_buy<ComTaskHost_*,std::allocator<ComTaskHost_*>_>::_Buynode0'::__l1::catch_0
               (undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x38));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== dtor$0 @ 14000b800 =====

void `ComTaskHost::StartTaskThread'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ShutdownGuard::~ShutdownGuard((ShutdownGuard *)(param_2 + 0x40));
  return;
}



===== dtor$0 @ 14000b820 =====

void `ComTaskHost::StartTaskWorker'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  wmi::AutoRef<ITaskHandler>::~AutoRef<ITaskHandler>((AutoRef<ITaskHandler> *)(param_2 + 0x98));
  return;
}



===== dtor$1 @ 14000b840 =====

void `ComTaskHost::StartTaskWorker'::__l1::dtor_1(undefined8 param_1,longlong param_2)

{
  AutoThreadPriority::~AutoThreadPriority((AutoThreadPriority *)(param_2 + 0x90));
  return;
}



===== dtor$2 @ 14000b860 =====

void `ComTaskHost::StartTaskWorker'::__l1::dtor_2(undefined8 param_1,longlong param_2)

{
  wmi::AutoRef<ITaskHandler>::~AutoRef<ITaskHandler>((AutoRef<ITaskHandler> *)(param_2 + 0xa0));
  return;
}



===== dtor$3 @ 14000b880 =====

void `ComTaskHost::StartTaskWorker'::__l1::dtor_3(undefined8 param_1,longlong param_2)

{
  ComCallAutoCancel::~ComCallAutoCancel((ComCallAutoCancel *)(param_2 + 0x40));
  return;
}



===== dtor$0 @ 14000b8a0 =====

void `ComTaskMgrWnd::ComTaskMgrWnd'::__l1::dtor_0(undefined8 param_1,longlong param_2)

{
  ComTaskMgrBase::~ComTaskMgrBase(*(ComTaskMgrBase **)(param_2 + 0x40));
  return;
}



===== catch$0 @ 14000b8c0 =====

void `std::_Tree_alloc<0,std::_Tree_base_types<ComTaskHost_*,std::allocator<ComTaskHost_*>_>_>::
     _Buyheadnode'::__l1::catch_0(undefined8 param_1,longlong param_2)

{
  operator_delete(*(void **)(param_2 + 0x30));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== __wmainCRTStartup$filt$0 @ 14000b8ed =====

void __wmainCRTStartup_filt_0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



===== _IsNonwritableInCurrentImage$filt$0 @ 14000b920 =====

bool _IsNonwritableInCurrentImage_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



===== _onexit$fin$0 @ 14000b946 =====

void _onexit_fin_0(void)

{
  _unlock(8);
  return;
}



===== catch$1 @ 14000b967 =====

undefined *
`std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Copy'::__l1::catch_1
          (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  void *pvVar2;
  __uint64 _Var3;
  
  lVar1 = *(longlong *)(param_2 + 0x68);
  *(longlong *)(param_2 + 0x68) = lVar1;
  pvVar2 = (void *)0x0;
  _Var3 = lVar1 + 1;
  if ((_Var3 != 0) && (pvVar2 = operator_new(_Var3), pvVar2 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  *(void **)(param_2 + 0x78) = pvVar2;
  return &DAT_140008bc1;
}



===== catch$0 @ 14000b9ab =====

void `std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Copy'::__l1::catch_0
               (undefined8 param_1,longlong param_2)

{
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            (*(basic_string<char,std::char_traits<char>,std::allocator<char>_> **)(param_2 + 0x60),
             true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== catch$0 @ 14000b9d6 =====

void `ATL::CSid::LoadAccount'::__l1::catch_0(undefined8 param_1,longlong param_2)

{
  ATL::CSid::Clear(*(CSid **)(param_2 + 0x30));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



===== _Generic_object'' @ 14000ba00 =====

void `dynamic_atexit_destructor_for_'std::_Error_objects<int>::_Generic_object__(void)

{
  std::_Error_objects<int>::_Generic_object = (undefined *)&std::error_category::_vftable_;
  return;
}



===== _Iostream_object'' @ 14000ba20 =====

void `dynamic_atexit_destructor_for_'std::_Error_objects<int>::_Iostream_object__(void)

{
  std::_Error_objects<int>::_Iostream_object = (undefined *)&std::error_category::_vftable_;
  return;
}



===== _System_object'' @ 14000ba40 =====

void `dynamic_atexit_destructor_for_'std::_Error_objects<int>::_System_object__(void)

{
  std::_Error_objects<int>::_System_object = (undefined *)&std::error_category::_vftable_;
  return;
}



===== _guard_dispatch_icall$thunk$10345483385596137414 @ 14000c010 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall_thunk_10345483385596137414(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}


