
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



===== _purecall @ 140001020 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== apply_policy_to_device @ 140001034 =====

/* private: void __cdecl ll_device_link::apply_policy_to_device(void) __ptr64 */

void __thiscall ll_device_link::apply_policy_to_device(ll_device_link *this)

{
  int iVar1;
  code *pcVar2;
  ushort uVar3;
  undefined8 in_RDX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined8 in_R8;
  StateMachineEngine *this_00;
  undefined8 uVar6;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  if (g_L1VHAddCriticalLoggingEnabled) {
    uVar6 = 0;
    if (*(longlong *)(this + 0x50) != 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xpq_EtwWriteTransfer
                (this,in_RDX,in_R8,uVar6,(char)*(undefined8 *)(this + 0x40),
                 (char)*(undefined4 *)(this + 0x4c));
    }
  }
  puVar4 = auStackY_38;
  puVar5 = auStackY_38;
  this_00 = *(StateMachineEngine **)(this + 0x40);
  if (this_00 == (StateMachineEngine *)0x0) {
    return;
  }
  iVar1 = *(int *)(this + 0x4c);
  if (iVar1 == 0) {
LAB_14000109f:
    uVar3 = 7;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) goto LAB_14000109f;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0x38);
      puVar4 = auStackY_30;
    }
    uVar3 = 6;
    puVar5 = puVar4;
  }
  *(undefined8 *)(puVar5 + -8) = 0x1400010ac;
  SmFx::StateMachineEngine::EnqueueEvent(this_00,uVar3);
  return;
}



===== get_mac_address @ 1400010bc =====

/* public: void __cdecl ll_device_link::get_mac_address(unsigned char * __ptr64)const __ptr64 */

void __thiscall ll_device_link::get_mac_address(ll_device_link *this,uchar *param_1)

{
  ll_device_link *plVar1;
  
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(plVar1,0);
  *(undefined4 *)param_1 = *(undefined4 *)(this + 4);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(this + 8);
  if (plVar1 != (ll_device_link *)0x0) {
    ExReleasePushLockSharedEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== on_device_notification @ 140001138 =====

/* private: void __cdecl ll_device_link::on_device_notification(enum ll_notification_kind,class
   ll_pnp_device * __ptr64) __ptr64 */

void __thiscall
ll_device_link::on_device_notification
          (ll_device_link *this,ll_notification_kind param_1,ll_pnp_device *param_2)

{
  ll_device_link *plVar1;
  ll_device_link lVar2;
  ll_pnp_device lVar3;
  int iVar4;
  undefined8 uVar5;
  ll_global *this_00;
  ll_pnp_device *plVar6;
  ll_pnp_device *plVar7;
  undefined8 uVar8;
  int local_44;
  int iStack_40;
  
  if ((((param_1 != 0) && (param_1 != 2)) && (param_1 != 4)) && (param_1 != 5)) {
    return;
  }
  plVar7 = param_2 + 0xb0;
  KeEnterCriticalRegion();
  plVar6 = plVar7;
  ExAcquirePushLockSharedEx();
  uVar5 = *(undefined8 *)(param_2 + 0x24);
  lVar2 = *(ll_device_link *)(param_2 + 0x20);
  lVar3 = param_2[0x1a];
  iVar4 = *(int *)(param_2 + 0x1c);
  if (plVar7 != (ll_pnp_device *)0x0) {
    ExReleasePushLockSharedEx();
    KeLeaveCriticalRegion();
    plVar6 = plVar7;
  }
  if (g_L1VHAddCriticalLoggingEnabled != false) {
    uVar8 = 0;
    if (*(longlong *)(this + 0x50) != 0) {
      uVar8 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xqpqttxx_EtwWriteTransfer
                (plVar6,uVar5,*(undefined8 *)(this + 0xc),uVar8,(char)param_1,(char)param_2,
                 (char)iVar4,lVar3,lVar2,(char)uVar5,(char)*(undefined8 *)(this + 0xc));
    }
  }
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1);
  if (*(ll_pnp_device **)(this + 0x40) == param_2) {
    if (iVar4 != *(int *)this) {
      set_linked_device(this,(ll_pnp_device *)0x0);
      this_00 = ll_global::get_instance();
      ll_notification_bus::request_reeunumeration
                ((ll_notification_bus *)this_00,(ll_notification_sink *)(this + 0x18));
    }
  }
  else if ((iVar4 == *(int *)this) && (lVar3 != (ll_pnp_device)0x0)) {
    if (g_L1VHBugFixes2505 != false) {
      param_2[0x18] = (ll_pnp_device)0x1;
    }
    set_linked_device(this,param_2);
  }
  if (*(ll_pnp_device **)(this + 0x40) == param_2) {
    if ((lVar2 != (ll_device_link)0x0) &&
       ((local_44 = (int)uVar5, *(int *)(this + 0xc) != local_44 ||
        (iStack_40 = (int)((ulonglong)uVar5 >> 0x20), *(int *)(this + 0x10) != iStack_40)))) {
      ll_vf::set_vf_goal_state(*(ll_vf **)(this + 0x50),0);
      *(undefined8 *)(this + 0xc) = uVar5;
    }
    this[10] = lVar2;
  }
  reevaluate_advertised_vf_state(this);
  if (plVar1 != (ll_device_link *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== on_notification @ 140001330 =====

/* private: static void __cdecl ll_device_link::on_notification(void * __ptr64,struct
   ll_notification_sink * __ptr64,enum ll_notification_kind,struct ll_notification_source * __ptr64)
    */

void __cdecl
ll_device_link::on_notification
          (void *param_1,ll_notification_sink *param_2,ll_notification_kind param_3,
          ll_notification_source *param_4)

{
  if (param_4 != (ll_notification_source *)0x0) {
    if (*(int *)(param_4 + 0x10) == 0) {
      on_policy_notification(param_1);
    }
    else if (*(int *)(param_4 + 0x10) == 1) {
      on_device_notification(param_1,param_3,*(ll_pnp_device **)(param_4 + 0x18));
    }
  }
  return;
}



===== on_policy_notification @ 140001368 =====

/* private: void __cdecl ll_device_link::on_policy_notification(void) __ptr64 */

void __thiscall ll_device_link::on_policy_notification(ll_device_link *this)

{
  ll_device_link *plVar1;
  ll_vf_role lVar2;
  ll_global *plVar3;
  ll_device_link *plVar4;
  undefined8 in_RDX;
  ll_device_link *plVar5;
  undefined8 in_R8;
  undefined8 uVar6;
  
  if (g_L1VHAddCriticalLoggingEnabled) {
    uVar6 = 0;
    if (*(longlong *)(this + 0x50) != 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xqq_EtwWriteTransfer
                (this,in_RDX,in_R8,uVar6,100,(char)*(undefined4 *)(this + 0x4c));
    }
  }
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  plVar3 = ll_global::get_instance();
  plVar5 = this + 4;
  lVar2 = ll_policy_table::get_role_for_mac_address
                    ((ll_policy_table *)(plVar3 + 0x60),(uchar *)plVar5);
  if (lVar2 != *(ll_vf_role *)(this + 0x4c)) {
    *(ll_vf_role *)(this + 0x4c) = lVar2;
    apply_policy_to_device(this);
    plVar4 = this;
    reevaluate_advertised_vf_state(this);
    if (g_L1VHAddCriticalLoggingEnabled != false) {
      uVar6 = 0;
      if (*(longlong *)(this + 0x50) != 0) {
        uVar6 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
      }
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        McTemplateK0xqq_EtwWriteTransfer
                  (plVar4,plVar5,in_R8,uVar6,200,(char)*(undefined4 *)(this + 0x4c));
      }
    }
  }
  if (plVar1 != (ll_device_link *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== reevaluate_advertised_vf_state @ 140001468 =====

/* private: void __cdecl ll_device_link::reevaluate_advertised_vf_state(void) __ptr64 */

void __thiscall ll_device_link::reevaluate_advertised_vf_state(ll_device_link *this)

{
  undefined8 in_RDX;
  ll_host_vf_state lVar1;
  undefined8 in_R8;
  undefined8 uVar2;
  
  lVar1 = 0;
  if (g_L1VHAddCriticalLoggingEnabled) {
    uVar2 = 0;
    if (*(longlong *)(this + 0x50) != 0) {
      uVar2 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xtq_EtwWriteTransfer
                ((ulonglong)(byte)this[10],in_RDX,in_R8,uVar2,this[10],
                 (char)*(undefined4 *)(this + 0x4c));
    }
  }
  if ((*(int *)(this + 0x4c) == 2) && (this[10] != (ll_device_link)0x0)) {
    lVar1 = *(ll_host_vf_state *)(this + 0x48);
  }
  ll_vf::set_vf_goal_state(*(ll_vf **)(this + 0x50),lVar1);
  return;
}



===== set_linked_device @ 1400014dc =====

/* private: void __cdecl ll_device_link::set_linked_device(class ll_pnp_device * __ptr64) __ptr64 */

void __thiscall ll_device_link::set_linked_device(ll_device_link *this,ll_pnp_device *param_1)

{
  StateMachineEngine *this_00;
  undefined8 in_R8;
  undefined8 uVar1;
  bool bVar2;
  
  if (g_L1VHAddCriticalLoggingEnabled) {
    uVar1 = 0;
    if (*(longlong *)(this + 0x50) != 0) {
      uVar1 = *(undefined8 *)(*(longlong *)(this + 0x50) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xpp_EtwWriteTransfer
                (this,param_1,in_R8,uVar1,(char)param_1,(char)*(undefined8 *)(this + 0x40));
    }
  }
  this_00 = *(StateMachineEngine **)(this + 0x40);
  if (param_1 != (ll_pnp_device *)this_00) {
    if (this_00 != (StateMachineEngine *)0x0) {
      SmFx::StateMachineEngine::EnqueueEvent(this_00,6);
      bVar2 = g_L1VHBugFixes2505 == false;
      *(undefined1 *)(*(longlong *)(this + 0x40) + 0x19) = 0;
      this[10] = (ll_device_link)0x0;
      if (bVar2) {
        *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18) = 0;
      }
      else {
        *(undefined8 *)(*(longlong *)(this + 0x40) + 0xa8) = 0;
      }
    }
    *(ll_pnp_device **)(this + 0x40) = param_1;
    if (param_1 != (ll_pnp_device *)0x0) {
      bVar2 = g_L1VHBugFixes2505 == false;
      param_1[0x19] = (ll_pnp_device)0x1;
      if (bVar2) {
        *(undefined1 *)(*(longlong *)(this + 0x40) + 0x18) = 1;
      }
      else {
        *(ll_device_link **)(*(longlong *)(this + 0x40) + 0xa8) = this;
      }
      apply_policy_to_device(this);
    }
  }
  return;
}



===== start @ 1400015a4 =====

/* public: void __cdecl ll_device_link::start(void) __ptr64 */

void __thiscall ll_device_link::start(ll_device_link *this)

{
  ll_global *plVar1;
  code *pcVar2;
  int iVar3;
  ll_global *plVar4;
  ll_global *plVar5;
  longlong *plVar6;
  ll_device_link *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar4 = ll_global::get_instance();
  plVar7 = this + 0x18;
  plVar1 = plVar4 + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  puVar8 = auStack_28;
  plVar5 = plVar4 + 0x38;
  plVar6 = *(longlong **)(plVar4 + 0x40);
  if ((ll_global *)*plVar6 != plVar5) {
    plVar6 = (longlong *)&DAT_00000003;
    pcVar2 = (code *)swi(0x29);
    plVar5 = (ll_global *)(*pcVar2)();
    puVar8 = auStack_20;
  }
  *(longlong **)(this + 0x20) = plVar6;
  *(ll_global **)plVar7 = plVar5;
  *plVar6 = (longlong)plVar7;
  *(ll_device_link **)(plVar5 + 8) = plVar7;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined8 *)(puVar8 + -8) = 0x140001614;
  iVar3 = KeResetEvent(plVar4 + 0x20);
  if (iVar3 != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x14000162c;
    ExQueueWorkItem(plVar4,1);
  }
  if (plVar1 != (ll_global *)0x0) {
    *(undefined8 *)(puVar8 + -8) = 0x140001642;
    ExReleasePushLockExclusiveEx(plVar1,0);
    *(undefined8 *)(puVar8 + -8) = 0x14000164e;
    KeLeaveCriticalRegion();
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 14000166c =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140013008;
  uVar2 = 0;
  if (DAT_140013008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140013008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(ll_etw_provider_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0xb6b6_EtwWriteTransfer @ 1400016d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xb6b6_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = param_5;
  local_28 = param_6;
  local_30 = 6;
  local_20 = 6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&mac_address_set,0,4,local_58);
  return;
}



===== McTemplateK0xpp_EtwWriteTransfer @ 140001758 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xpp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&linked_device_set,0,4,local_58);
  return;
}



===== McTemplateK0xpq_EtwWriteTransfer @ 1400017e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xpq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&device_policy,0,4,local_58);
  return;
}



===== McTemplateK0xqpqttxx_EtwWriteTransfer @ 140001864 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xqpqttxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined8 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = &local_res20;
  local_90 = 8;
  local_88 = &param_5;
  local_80 = 4;
  local_78 = &param_6;
  local_70 = 8;
  local_68 = &param_7;
  local_60 = 4;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_50 = 4;
  local_40 = 4;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&device_notification,0,9,local_a8);
  return;
}



===== McTemplateK0xqq_EtwWriteTransfer @ 140001940 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&policy_notification,0,4,local_58);
  return;
}



===== McTemplateK0xtq_EtwWriteTransfer @ 1400019c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xtq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&advertised_vf_state,0,4,local_58);
  return;
}



===== ~ll_device_table @ 140001a40 =====

/* public: __cdecl ll_device_table::~ll_device_table(void) __ptr64 */

void __thiscall ll_device_table::~ll_device_table(ll_device_table *this)

{
  ll_pnp_device *this_00;
  ll_device_table *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = *(ll_device_table **)this;
    if (plVar1 == this) {
      return;
    }
    if ((*(ll_device_table **)(plVar1 + 8) != this) ||
       (lVar2 = *(longlong *)plVar1, *(ll_device_table **)(lVar2 + 8) != plVar1)) break;
    this_00 = (ll_pnp_device *)(plVar1 + -8);
    *(longlong *)this = lVar2;
    *(ll_device_table **)(lVar2 + 8) = this;
    if (this_00 != (ll_pnp_device *)0x0) {
      ll_pnp_device::~ll_pnp_device(this_00);
      ExFreePoolWithTag(this_00,0x21766e6e);
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== find_device_by_symbolic_link_name @ 140001aac =====

/* private: class ll_pnp_device * __ptr64 __cdecl
   ll_device_table::find_device_by_symbolic_link_name(struct _UNICODE_STRING const * __ptr64)
   __ptr64 */

ll_pnp_device * __thiscall
ll_device_table::find_device_by_symbolic_link_name(ll_device_table *this,_UNICODE_STRING *param_1)

{
  ll_device_table *plVar1;
  char cVar2;
  
  plVar1 = *(ll_device_table **)this;
  while( true ) {
    if (plVar1 == this) {
      return (ll_pnp_device *)0x0;
    }
    if ((*(longlong *)(plVar1 + 0x60) != 0) &&
       (cVar2 = RtlEqualUnicodeString(*(longlong *)(plVar1 + 0x60),param_1,1), cVar2 != '\0'))
    break;
    plVar1 = *(ll_device_table **)plVar1;
  }
  return (ll_pnp_device *)(plVar1 + -8);
}



===== find_or_create_device_by_location_path @ 140001b1c =====

/* private: class ll_pnp_device * __ptr64 __cdecl
   ll_device_table::find_or_create_device_by_location_path(class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<wchar_t * __ptr64,void
   (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl pool_helpers<wchar_t *
   __ptr64,561409646>::free(wchar_t * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,wchar_t * __ptr64,wchar_t * __ptr64,0,std::nullptr_t> > > && __ptr64,void * __ptr64)
   __ptr64 */

ll_pnp_device * __thiscall
ll_device_table::find_or_create_device_by_location_path
          (ll_device_table *this,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  ll_device_table *plVar3;
  code *pcVar4;
  long lVar5;
  ll_pnp_device *plVar6;
  ll_pnp_device *plVar7;
  short *psVar8;
  longlong *plVar9;
  void *pvVar10;
  longlong lVar11;
  
  plVar3 = *(ll_device_table **)this;
  do {
    if (plVar3 == this) {
LAB_140001b77:
      pvVar10 = (void *)0xd0;
      plVar6 = (ll_pnp_device *)ExAllocatePool2(0x40,0xd0,0x21766e6e);
      if ((plVar6 != (ll_pnp_device *)0x0) &&
         (plVar6 = (ll_pnp_device *)ll_pnp_device::ll_pnp_device(plVar6,pvVar10),
         plVar6 != (ll_pnp_device *)0x0)) {
        lVar5 = ll_pnp_device::initialize(plVar6,param_1);
        if (lVar5 == 0) {
          plVar9 = *(longlong **)(this + 8);
          plVar7 = plVar6 + 8;
          if ((ll_device_table *)*plVar9 != this) {
            plVar9 = (longlong *)&DAT_00000003;
            pcVar4 = (code *)swi(0x29);
            plVar7 = (ll_pnp_device *)(*pcVar4)();
          }
          *(ll_device_table **)plVar7 = this;
          *(longlong **)(plVar7 + 8) = plVar9;
          *plVar9 = (longlong)plVar7;
          *(ll_pnp_device **)(this + 8) = plVar7;
          return plVar6;
        }
        ll_pnp_device::~ll_pnp_device(plVar6);
        ExFreePoolWithTag(plVar6,0x21766e6e);
      }
      return (ll_pnp_device *)0x0;
    }
    psVar8 = *(short **)(plVar3 + 0x58);
    lVar11 = *(longlong *)param_1 - (longlong)psVar8;
    do {
      sVar1 = *psVar8;
      sVar2 = *(short *)((longlong)psVar8 + lVar11);
      if (sVar1 != sVar2) break;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    if (sVar1 == sVar2) {
      if ((ll_pnp_device *)(plVar3 + -8) != (ll_pnp_device *)0x0) {
        return (ll_pnp_device *)(plVar3 + -8);
      }
      goto LAB_140001b77;
    }
    plVar3 = *(ll_device_table **)plVar3;
  } while( true );
}



===== notify_pci_proxy_device_up @ 140001c14 =====

/* public: void __cdecl ll_device_table::notify_pci_proxy_device_up(class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<wchar_t * __ptr64,void
   (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl pool_helpers<wchar_t *
   __ptr64,561409646>::free(wchar_t * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,wchar_t * __ptr64,wchar_t * __ptr64,0,std::nullptr_t> > > && __ptr64,unsigned
   long,struct _LUID,struct _UNICODE_STRING const * __ptr64) __ptr64 */

void __thiscall
ll_device_table::notify_pci_proxy_device_up
          (ll_device_table *this,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_1,void *param_3,undefined8 param_4)

{
  ll_device_table *plVar1;
  ll_pnp_device *plVar2;
  short sVar3;
  short sVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined4 uVar7;
  ll_device_table *plVar8;
  ll_device_table *this_00;
  undefined8 uVar9;
  ll_global *this_01;
  short *psVar10;
  undefined1 *puVar11;
  longlong lVar12;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [56];
  
  plVar1 = this + 0x10;
  uVar7 = SUB84(param_3,0);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  if (g_L1VHBugFixes2502 == false) {
    this_00 = (ll_device_table *)find_or_create_device_by_location_path(this,param_1,param_3);
  }
  else {
    for (plVar8 = *(ll_device_table **)this; plVar8 != this; plVar8 = *(ll_device_table **)plVar8) {
      this_00 = plVar8 + -8;
      psVar10 = *(short **)(plVar8 + 0x58);
      lVar12 = *(longlong *)param_1 - (longlong)psVar10;
      do {
        sVar3 = *psVar10;
        sVar4 = *(short *)((longlong)psVar10 + lVar12);
        if (sVar3 != sVar4) break;
        psVar10 = psVar10 + 1;
      } while (sVar4 != 0);
      if (sVar3 == sVar4) goto LAB_140001cb1;
    }
    this_00 = (ll_device_table *)0x0;
  }
LAB_140001cb1:
  puVar11 = auStack_58;
  if (this_00 != (ll_device_table *)0x0) {
    puVar11 = auStack_58;
    if ((g_L1VHBugFixes2502 != false) &&
       (puVar11 = auStack_58, *(ll_pnp_device *)(this_00 + 0x18) == (ll_pnp_device)0x0)) {
      plVar2 = (ll_pnp_device *)(this_00 + 8);
      lVar12 = *(longlong *)plVar2;
      if ((*(ll_pnp_device **)(lVar12 + 8) == plVar2) &&
         (plVar5 = *(longlong **)(this_00 + 0x10), (ll_pnp_device *)*plVar5 == plVar2)) {
        *plVar5 = lVar12;
        *(longlong **)(lVar12 + 8) = plVar5;
        ll_pnp_device::~ll_pnp_device((ll_pnp_device *)this_00);
        ExFreePoolWithTag(this_00,0x21766e6e);
        puVar11 = auStack_58;
        goto LAB_140001ded;
      }
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar11 = auStack_50;
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
      *(undefined8 *)(puVar11 + 0x30) = *(undefined8 *)param_1;
      *(undefined4 *)(puVar11 + 0x28) = uVar7;
      puVar11[0x20] = 1;
      *(undefined8 *)(puVar11 + -8) = 0x140001d35;
      McTemplateK0xuqz_EtwWriteTransfer();
    }
    if (g_L1VHBugFixes2509 != false) {
      *(undefined8 *)(puVar11 + -8) = 0x140001d47;
      uVar9 = KeQueryPerformanceCounter(0);
      *(undefined8 *)(this_00 + 200) = uVar9;
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        *(undefined8 *)(puVar11 + 0x20) = uVar9;
        *(undefined8 *)(puVar11 + -8) = 0x140001d6d;
        McTemplateK0xx_EtwWriteTransfer();
      }
    }
    *(undefined8 *)(puVar11 + -8) = 0x140001d7d;
    ll_pnp_device::update_symbolic_link
              ((ll_pnp_device *)this_00,*(_UNICODE_STRING **)(puVar11 + 0x80));
    plVar2 = (ll_pnp_device *)(this_00 + 0xb0);
    *(undefined8 *)(puVar11 + -8) = 0x140001d8b;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar11 + -8) = 0x140001d9c;
    ExAcquirePushLockExclusiveEx(plVar2,0);
    *(undefined8 *)(this_00 + 0x24) = param_4;
    *(ll_pnp_device *)(this_00 + 0x1a) = (ll_pnp_device)0x0;
    *(undefined4 *)(this_00 + 0x1c) = uVar7;
    *(undefined8 *)(puVar11 + -8) = 0x140001db2;
    this_01 = ll_global::get_instance();
    *(undefined8 *)(puVar11 + -8) = 0x140001dbe;
    ll_notification_bus::notify_source_updated
              ((ll_notification_bus *)this_01,(ll_notification_source *)(this_00 + 0x38));
    if (plVar2 != (ll_pnp_device *)0x0) {
      *(undefined8 *)(puVar11 + -8) = 0x140001dcf;
      ExReleasePushLockExclusiveEx(plVar2,0);
      *(undefined8 *)(puVar11 + -8) = 0x140001ddb;
      KeLeaveCriticalRegion();
    }
    *(undefined8 *)(puVar11 + -8) = 0x140001ded;
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this_00,3);
  }
LAB_140001ded:
  if (plVar1 != (ll_device_table *)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x140001dfe;
    ExReleasePushLockExclusiveEx(plVar1,0);
    *(undefined8 *)(puVar11 + -8) = 0x140001e0a;
    KeLeaveCriticalRegion();
  }
  return;
}



===== McTemplateK0xu_EtwWriteTransfer @ 140001e38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xu_EtwWriteTransfer
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
  local_20 = 1;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0xuqz_EtwWriteTransfer @ 140001ea8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xuqz_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 8;
  local_48 = &uStack0000000000000028;
  local_38 = &uStack0000000000000030;
  local_40 = 1;
  local_30 = 4;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  local_28 = in_stack_00000038;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000038,&device_arrival,0,5,local_68);
  return;
}



===== McTemplateK0xx_EtwWriteTransfer @ 140001f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xx_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &uStack0000000000000028;
  local_30 = 8;
  local_1c = 0;
  local_20 = 8;
  McGenEventWrite_EtwWriteTransfer(8,&vf_state_transition,0,3,local_48);
  return;
}



===== deinitialize @ 140001fe8 =====

/* public: void __cdecl ll_device_watcher::deinitialize(void) __ptr64 */

void __thiscall ll_device_watcher::deinitialize(ll_device_watcher *this)

{
  if (*(longlong *)(this + 8) != 0) {
    IoUnregisterPlugPlayNotificationEx();
    *(undefined8 *)(this + 8) = 0;
  }
  return;
}



===== initialize @ 140002018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: long __cdecl ll_device_watcher::initialize(struct _GUID const & __ptr64) __ptr64 */

long __thiscall ll_device_watcher::initialize(ll_device_watcher *this,_GUID *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  lVar1 = IoRegisterPlugPlayNotification(2,1,param_1,uVar2,on_pnp_notification,this,this + 8);
  return lVar1;
}



===== on_device_interface_down @ 140002090 =====

/* private: virtual void __cdecl ll_net_device_watcher::on_device_interface_down(struct
   _DEVICE_INTERFACE_CHANGE_NOTIFICATION const * __ptr64) __ptr64 */

void __thiscall
ll_net_device_watcher::on_device_interface_down
          (ll_net_device_watcher *this,_DEVICE_INTERFACE_CHANGE_NOTIFICATION *param_1)

{
  _UNICODE_STRING *p_Var1;
  ll_global *plVar2;
  ll_pnp_device *this_00;
  ll_device_table *this_01;
  
  plVar2 = ll_global::get_instance();
  p_Var1 = *(_UNICODE_STRING **)(param_1 + 0x28);
  this_01 = (ll_device_table *)(plVar2 + 0xb0);
  plVar2 = plVar2 + 0xc0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar2,0);
  this_00 = ll_device_table::find_device_by_symbolic_link_name(this_01,p_Var1);
  if (this_00 != (ll_pnp_device *)0x0) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
      McTemplateK0xu_EtwWriteTransfer(this_01,&device_removal,0,*(undefined8 *)(this_00 + 0xa0),0);
    }
    ll_pnp_device::notify_missing(this_00);
  }
  if (plVar2 != (ll_global *)0x0) {
    ExReleasePushLockExclusiveEx(plVar2,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== on_device_interface_down @ 140002150 =====

/* private: virtual void __cdecl ll_pci_proxy_device_watcher::on_device_interface_down(struct
   _DEVICE_INTERFACE_CHANGE_NOTIFICATION const * __ptr64) __ptr64 */

void __thiscall
ll_pci_proxy_device_watcher::on_device_interface_down
          (ll_pci_proxy_device_watcher *this,_DEVICE_INTERFACE_CHANGE_NOTIFICATION *param_1)

{
  _UNICODE_STRING *p_Var1;
  longlong lVar2;
  ll_global *plVar3;
  ll_pnp_device *this_00;
  ll_device_table *this_01;
  
  plVar3 = ll_global::get_instance();
  p_Var1 = *(_UNICODE_STRING **)(param_1 + 0x28);
  this_01 = (ll_device_table *)(plVar3 + 0xb0);
  plVar3 = plVar3 + 0xc0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar3,0);
  this_00 = ll_device_table::find_device_by_symbolic_link_name(this_01,p_Var1);
  if (this_00 != (ll_pnp_device *)0x0) {
    if (((g_L1VHBugFixes2505 != false) && (*(longlong *)(this_00 + 0xa8) != 0)) &&
       (lVar2 = *(longlong *)(*(longlong *)(this_00 + 0xa8) + 0x50),
       this_01 = (ll_device_table *)0x0, lVar2 != 0)) {
      this_01 = (ll_device_table *)(lVar2 + 0xbc0);
      ll_vmswitch_indications::indicate_switch_capabilities
                ((ll_vmswitch_indications *)this_01,0x40020040,0);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
      McTemplateK0xu_EtwWriteTransfer(this_01,&device_removal,0,*(undefined8 *)(this_00 + 0xa0),1);
    }
    ll_pnp_device::notify_missing(this_00);
  }
  if (plVar3 != (ll_global *)0x0) {
    ExReleasePushLockExclusiveEx(plVar3,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== on_device_interface_up @ 140002240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl ll_device_watcher::on_device_interface_up(struct
   _DEVICE_INTERFACE_CHANGE_NOTIFICATION const * __ptr64) __ptr64 */

void __thiscall
ll_device_watcher::on_device_interface_up
          (ll_device_watcher *this,_DEVICE_INTERFACE_CHANGE_NOTIFICATION *param_1)

{
  _DEVICE_OBJECT *p_Var1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  longlong lVar5;
  short *psVar6;
  longlong lVar7;
  ulong local_res10 [2];
  longlong local_res18;
  short *local_res20;
  longlong local_78 [6];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_78[5] = *(longlong *)(param_1 + 0x28);
  local_78[3] = 0x30;
  local_48 = 0x200;
  local_78[4] = 0;
  local_res18 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  iVar2 = ZwOpenFile(&local_res18,1,local_78 + 3,local_78 + 1,3,0x61);
  if (iVar2 == 0) {
    local_78[0] = 0;
    iVar2 = ObReferenceObjectByHandle
                      (local_res18,0,*(undefined8 *)IoFileObjectType_exref,0,local_78,0);
    if (iVar2 == 0) {
      p_Var1 = *(_DEVICE_OBJECT **)(local_78[0] + 8);
      local_res20 = (short *)0x0;
      lVar3 = ll_pnp_query_location_path
                        (p_Var1,(unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
                                 *)&local_res20);
      if (lVar3 == 0) {
        local_res10[0] = 0;
        lVar3 = ll_pnp_query_vpci_serial_number(p_Var1,local_res10);
        if (lVar3 == 0) {
          lVar4 = 0;
          if (*local_res20 != 0) {
            psVar6 = local_res20;
            do {
              lVar7 = 0;
              lVar5 = 0;
              while ((*(short *)(lVar5 + (longlong)psVar6) != 0 &&
                     ((*(short *)(&u__VPCI______ + lVar5) == 0x2e ||
                      (*(short *)(lVar5 + (longlong)psVar6) == *(short *)(&u__VPCI______ + lVar5))))
                     )) {
                lVar7 = lVar7 + 1;
                lVar5 = lVar7 * 2;
                if (*(short *)(&u__VPCI______ + lVar5) == 0) {
                  local_res20[lVar4 + 0xb] = 0;
                  goto LAB_14000237d;
                }
              }
              lVar4 = lVar4 + 1;
              psVar6 = local_res20 + lVar4;
            } while (*psVar6 != 0);
          }
LAB_14000237d:
          (*(code *)**(undefined8 **)this)(this,param_1,&local_res20,local_res10[0],local_res18);
        }
      }
      if (local_res20 != (short *)0x0) {
        ExFreePoolWithTag(local_res20,0x21766e6e);
      }
      ObfDereferenceObject(local_78[0]);
    }
  }
  if (local_res18 != 0) {
    ZwClose();
  }
  return;
}



===== on_device_interface_up @ 140002410 =====

/* private: virtual void __cdecl ll_net_device_watcher::on_device_interface_up(struct
   _DEVICE_INTERFACE_CHANGE_NOTIFICATION const * __ptr64,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<wchar_t * __ptr64,void
   (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl pool_helpers<wchar_t *
   __ptr64,561409646>::free(wchar_t * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,wchar_t * __ptr64,wchar_t * __ptr64,0,std::nullptr_t> > > && __ptr64,unsigned
   long,void * __ptr64) __ptr64 */

void __thiscall
ll_net_device_watcher::on_device_interface_up
          (ll_net_device_watcher *this,_DEVICE_INTERFACE_CHANGE_NOTIFICATION *param_1,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_2,ulong param_3,void *param_4)

{
  ll_global *plVar1;
  ll_pnp_device *plVar2;
  _UNICODE_STRING *p_Var3;
  ll_global *plVar4;
  ll_pnp_device *this_00;
  undefined8 uVar5;
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
  *puVar6;
  undefined8 local_res10;
  
  puVar6 = param_2;
  plVar4 = ll_global::get_instance();
  p_Var3 = *(_UNICODE_STRING **)(param_1 + 0x28);
  plVar1 = plVar4 + 0xc0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  this_00 = ll_device_table::find_or_create_device_by_location_path
                      ((ll_device_table *)(plVar4 + 0xb0),param_2,puVar6);
  if (this_00 != (ll_pnp_device *)0x0) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
      McTemplateK0xuqz_EtwWriteTransfer();
    }
    if (g_L1VHBugFixes2509 != false) {
      local_res10 = 0;
      uVar5 = KeQueryPerformanceCounter(&local_res10);
      *(undefined8 *)(this_00 + 0xc0) = local_res10;
      *(undefined8 *)(this_00 + 0xb8) = uVar5;
    }
    ll_pnp_device::update_symbolic_link(this_00,p_Var3);
    plVar2 = this_00 + 0xb0;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(plVar2,0);
    this_00[0x1a] = (ll_pnp_device)0x1;
    *(ulong *)(this_00 + 0x1c) = param_3;
    plVar4 = ll_global::get_instance();
    ll_notification_bus::notify_source_updated
              ((ll_notification_bus *)plVar4,(ll_notification_source *)(this_00 + 0x38));
    if (plVar2 != (ll_pnp_device *)0x0) {
      ExReleasePushLockExclusiveEx(plVar2,0);
      KeLeaveCriticalRegion();
    }
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this_00,2);
  }
  if (plVar1 != (ll_global *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== on_device_interface_up @ 140002590 =====

/* private: virtual void __cdecl ll_pci_proxy_device_watcher::on_device_interface_up(struct
   _DEVICE_INTERFACE_CHANGE_NOTIFICATION const * __ptr64,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<wchar_t * __ptr64,void
   (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl pool_helpers<wchar_t *
   __ptr64,561409646>::free(wchar_t * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,wchar_t * __ptr64,wchar_t * __ptr64,0,std::nullptr_t> > > && __ptr64,unsigned
   long,void * __ptr64) __ptr64 */

void __thiscall
ll_pci_proxy_device_watcher::on_device_interface_up
          (ll_pci_proxy_device_watcher *this,_DEVICE_INTERFACE_CHANGE_NOTIFICATION *param_1,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_2,ulong param_3,void *param_4)

{
  int iVar1;
  ll_global *plVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  iVar1 = ZwDeviceIoControlFile(param_4,0,0,0,&local_20,0x226064,0,0,&local_28,8);
  if (iVar1 == 0) {
    plVar2 = ll_global::get_instance();
    ll_device_table::notify_pci_proxy_device_up
              ((ll_device_table *)(plVar2 + 0xb0),param_2,param_3,local_28,
               *(undefined8 *)(param_1 + 0x28));
  }
  return;
}



===== on_pnp_notification @ 140002640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl ll_device_watcher::on_pnp_notification(void * __ptr64,void *
   __ptr64) */

long __cdecl ll_device_watcher::on_pnp_notification(void *param_1,void *param_2)

{
  void *pvVar1;
  void *pvVar2;
  undefined1 uVar3;
  
  if (g_L1VHBugFixes2502) {
    if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4004) &&
       (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) == 0)
      goto LAB_1400026d5;
      uVar3 = 1;
      pvVar1 = param_1;
      pvVar2 = param_2;
    }
    else {
      pvVar2 = (void *)0x11d046f0cb3a4005;
      pvVar1 = (void *)0x3f05139760008fb0;
      if ((*(longlong *)((longlong)param_1 + 4) != 0x11d046f0cb3a4005) ||
         ((*(longlong *)((longlong)param_1 + 0xc) != 0x3f05139760008fb0 ||
          ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) == 0))))
      goto LAB_1400026d5;
      uVar3 = 2;
    }
    McTemplateK0uj_EtwWriteTransfer(pvVar1,pvVar2,0x3f05139760008fb0,uVar3,(longlong)param_1 + 0x14)
    ;
  }
LAB_1400026d5:
  if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4004) &&
     (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
    on_device_interface_up(param_2,param_1);
  }
  else if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4005) &&
          (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
    (**(code **)(*(longlong *)param_2 + 8))(param_2,param_1);
  }
  return 0;
}



===== McTemplateK0uj_EtwWriteTransfer @ 140002720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uj_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
               undefined8 param_5)

{
  undefined1 local_res20 [8];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined1 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_30 = 1;
  local_28 = param_5;
  local_1c = 0;
  local_20 = 0x10;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&pnp_device_notification,0,3,local_48);
  return;
}



===== get_instance @ 1400027a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class ll_global & __ptr64 __cdecl ll_global::get_instance(void) */

ll_global * __cdecl ll_global::get_instance(void)

{
  ll_global *plVar1;
  
  plVar1 = (ll_global *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,*WdfDriverGlobals,PTR__WDF_ll_driver_TYPE_INFO_140013060);
  return plVar1;
}



===== on_query_active_vfs @ 1400027d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl ll_ioctl_handler::on_query_active_vfs(class ll_ioctl_request & __ptr64)
   __ptr64 */

long __thiscall
ll_ioctl_handler::on_query_active_vfs(ll_ioctl_handler *this,ll_ioctl_request *param_1)

{
  __uint64 _Var1;
  NNVDRV_QUERY_ACTIVE_VFS_OUT *pNVar2;
  int iVar3;
  ulonglong uVar4;
  ll_ioctl_handler *local_res8;
  __uint64 local_res10;
  NNVDRV_QUERY_ACTIVE_VFS_OUT *local_res18;
  
  local_res10 = 0;
  local_res8 = this;
  iVar3 = (**(code **)(WdfFunctions_01033 + 0x868))
                    (WdfDriverGlobals,*(undefined8 *)param_1,0x10,&local_res10,0);
  _Var1 = local_res10;
  if ((iVar3 == 0) && (local_res10 != 0)) {
    local_res8 = (ll_ioctl_handler *)0x0;
    local_res18 = (NNVDRV_QUERY_ACTIVE_VFS_OUT *)0x0;
    iVar3 = (**(code **)(WdfFunctions_01033 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)param_1,8,&local_res18,&local_res8);
    pNVar2 = local_res18;
    if ((iVar3 == 0) && (local_res18 != (NNVDRV_QUERY_ACTIVE_VFS_OUT *)0x0)) {
      uVar4 = 0;
      do {
        if (*(longlong *)(_Var1 + uVar4 * 8) != 0) {
          return -0x3ffffff3;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < 2);
      memset(local_res18,0,(size_t)local_res8);
      local_res10 = 0;
      ll_vf::enumerate_all_vfs(pNVar2,(__uint64)local_res8,&local_res10);
      (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,local_res10)
      ;
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== on_query_policy @ 1400028f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl ll_ioctl_handler::on_query_policy(class ll_ioctl_request & __ptr64) __ptr64
    */

long __thiscall ll_ioctl_handler::on_query_policy(ll_ioctl_handler *this,ll_ioctl_request *param_1)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  ll_global *plVar5;
  longlong lVar6;
  __uint64 _Var7;
  ushort *local_res8;
  int *local_res10;
  longlong local_res18;
  __uint64 local_res20;
  
  local_res8 = (ushort *)0x0;
  iVar3 = (**(code **)(WdfFunctions_01033 + 0x868))
                    (WdfDriverGlobals,*(undefined8 *)param_1,0x10,&local_res8,0);
  puVar1 = local_res8;
  if ((iVar3 == 0) && (local_res8 != (ushort *)0x0)) {
    local_res18 = 0;
    local_res10 = (int *)0x0;
    iVar3 = (**(code **)(WdfFunctions_01033 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)param_1,0x28,&local_res10,&local_res18);
    piVar2 = local_res10;
    if ((iVar3 == 0) && (local_res10 != (int *)0x0)) {
      if (((puVar1[1] != 0) || (*(int *)(puVar1 + 2) != 0)) || (*(longlong *)(puVar1 + 4) != 0)) {
        return -0x3ffffff3;
      }
      _Var7 = local_res18 - 8;
      local_res20 = 0;
      plVar5 = ll_global::get_instance();
      lVar4 = ll_policy_table::get_policy
                        ((ll_policy_table *)(plVar5 + 0x60),*puVar1,
                         (NNVDRV_POLICY_BLOB *)(piVar2 + 2),_Var7,&local_res20);
      if (lVar4 != 0) {
        return lVar4;
      }
      *piVar2 = (int)local_res20 + 8;
      if (_Var7 < local_res20) {
        lVar6 = 0x28;
      }
      else {
        lVar6 = local_res20 + 8;
      }
      (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,lVar6);
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== on_query_version @ 140002a3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl ll_ioctl_handler::on_query_version(class ll_ioctl_request & __ptr64)
   __ptr64 */

long __thiscall ll_ioctl_handler::on_query_version(ll_ioctl_handler *this,ll_ioctl_request *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong *local_res8;
  undefined8 *local_res10;
  
  local_res8 = (longlong *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01033 + 0x868))
                    (WdfDriverGlobals,*(undefined8 *)param_1,8,&local_res8,0);
  plVar1 = local_res8;
  if ((iVar2 == 0) && (local_res8 != (longlong *)0x0)) {
    local_res10 = (undefined8 *)0x0;
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)param_1,0x10,&local_res10,0);
    if ((iVar2 == 0) && (local_res10 != (undefined8 *)0x0)) {
      if (*plVar1 == 0) {
        *local_res10 = 0;
        local_res10[1] = 0;
        *(undefined4 *)local_res10 = 0x10000;
        (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,0x10);
        return 0;
      }
      return -0x3ffffff3;
    }
  }
  return -0x3fffffdd;
}



===== on_query_vf_state @ 140002b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl ll_ioctl_handler::on_query_vf_state(class ll_ioctl_request & __ptr64)
   __ptr64 */

long __thiscall
ll_ioctl_handler::on_query_vf_state(ll_ioctl_handler *this,ll_ioctl_request *param_1)

{
  undefined8 *puVar1;
  NNVDRV_QUERY_VF_STATE_OUT *pNVar2;
  int iVar3;
  ll_vf_role lVar4;
  longlong *plVar5;
  ll_global *plVar6;
  ulonglong uVar7;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined8 *local_78;
  NNVDRV_QUERY_VF_STATE_OUT *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_78 = (undefined8 *)0x0;
  local_88 = 0;
  iVar3 = (**(code **)(WdfFunctions_01033 + 0x868))
                    (WdfDriverGlobals,*(undefined8 *)param_1,0x38,&local_78);
  puVar1 = local_78;
  if ((iVar3 == 0) && (local_78 != (undefined8 *)0x0)) {
    local_70 = (NNVDRV_QUERY_VF_STATE_OUT *)0x0;
    local_88 = 0;
    iVar3 = (**(code **)(WdfFunctions_01033 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)param_1,0x230,&local_70);
    pNVar2 = local_70;
    if ((iVar3 == 0) && (local_70 != (NNVDRV_QUERY_VF_STATE_OUT *)0x0)) {
      uVar7 = 0;
      plVar5 = puVar1 + 5;
      do {
        if (*plVar5 != 0) {
          return -0x3ffffff3;
        }
        uVar7 = uVar7 + 1;
        plVar5 = plVar5 + 1;
      } while (uVar7 < 2);
      local_68 = *puVar1;
      uStack_60 = puVar1[1];
      local_38 = puVar1[4];
      uStack_30 = puVar1[5];
      local_48 = puVar1[2];
      uStack_40 = puVar1[3];
      local_28 = puVar1[6];
      local_58 = local_68;
      uStack_50 = uStack_60;
      memset(local_70,0,0x230);
      if ((short)local_68 == 6) {
        plVar6 = ll_global::get_instance();
        lVar4 = ll_policy_table::get_role_for_mac_address
                          ((ll_policy_table *)(plVar6 + 0x60),(uchar *)((longlong)&local_58 + 2));
        if (lVar4 == 0) {
          *(undefined4 *)pNVar2 = 1;
        }
        else if (lVar4 == 1) {
          *(undefined4 *)pNVar2 = 2;
        }
        else if (lVar4 == 2) {
          *(undefined4 *)pNVar2 = 3;
        }
        ll_vf::query_vf_state((uchar *)((longlong)&local_58 + 2),pNVar2);
      }
      (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,0x230);
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== on_set_policy @ 140002ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl ll_ioctl_handler::on_set_policy(class ll_ioctl_request & __ptr64) __ptr64
    */

long __thiscall ll_ioctl_handler::on_set_policy(ll_ioctl_handler *this,ll_ioctl_request *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  ulonglong uVar5;
  ll_global *plVar6;
  longlong local_res8;
  undefined8 *local_res10;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res8 = 0;
  iVar3 = (**(code **)(WdfFunctions_01033 + 0x868))
                    (WdfDriverGlobals,*(undefined8 *)param_1,0x30,&local_res8,local_res18);
  lVar1 = local_res8;
  if ((iVar3 == 0) && (local_res8 != 0)) {
    local_res10 = (undefined8 *)0x0;
    iVar3 = (**(code **)(WdfFunctions_01033 + 0x870))
                      (WdfDriverGlobals,*(undefined8 *)param_1,8,&local_res10,0);
    puVar2 = local_res10;
    if ((iVar3 == 0) && (local_res10 != (undefined8 *)0x0)) {
      uVar5 = 0;
      do {
        if (*(longlong *)(lVar1 + uVar5 * 8) != 0) {
          return -0x3ffffff3;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 2);
      plVar6 = ll_global::get_instance();
      lVar4 = ll_policy_table::set_policy
                        ((ll_policy_table *)(plVar6 + 0x60),(NNVDRV_POLICY_BLOB *)(lVar1 + 0x10),
                         local_res18[0] - 0x10);
      if (lVar4 == 0) {
        *puVar2 = 0;
        (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,8);
        return 0;
      }
      return lVar4;
    }
  }
  return -0x3fffffdd;
}



===== ~ll_netvsc_state @ 140002e04 =====

/* public: __cdecl ll_netvsc_state::~ll_netvsc_state(void) __ptr64 */

void __thiscall ll_netvsc_state::~ll_netvsc_state(ll_netvsc_state *this)

{
  code *pcVar1;
  int iVar2;
  
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,2);
  iVar2 = KeWaitForSingleObject(this + 0x160,0,0,0,0);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
  }
  return;
}



===== EvtLogEventEnqueue @ 140002e50 =====

/* private: void __cdecl ll_netvsc_state::EvtLogEventEnqueue(enum ll_netvsc_StateMachine<class
   ll_netvsc_state>::EventId) __ptr64 */

void __thiscall ll_netvsc_state::EvtLogEventEnqueue(ll_netvsc_state *this,EventId param_1)

{
  short *psVar1;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    psVar1 = &DAT_1400131f0;
    do {
      if (*psVar1 == (short)param_1) break;
      psVar1 = psVar1 + 8;
    } while (psVar1 != &DAT_1400132a0);
    McTemplateK0xus_EtwWriteTransfer();
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 140002eb0 =====

/* private: static void __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EvtLogEventEnqueueThunk(void *param_1,ushort param_2)

{
  undefined2 in_register_00000012;
  
  ll_netvsc_state::EvtLogEventEnqueue(param_1,CONCAT22(in_register_00000012,param_2));
  return;
}



===== EvtLogMachineException @ 140002ec8 =====

/* private: void __cdecl ll_vmswitch_indications::EvtLogMachineException(enum
   SmFx::MachineException,enum ll_vmswitch_StateMachine<class ll_vmswitch_indications>::EventId,enum
   ll_vmswitch_StateMachine<class ll_vmswitch_indications>::StateId) __ptr64 */

void __thiscall
ll_vmswitch_indications::EvtLogMachineException
          (ll_vmswitch_indications *this,MachineException param_1,EventId param_2,StateId param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(0x38);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== EvtLogMachineExceptionThunk @ 140002ee0 =====

/* private: static void __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EvtLogMachineExceptionThunk(void * __ptr64,enum SmFx::MachineException,unsigned
   short,unsigned short) */

void __cdecl
ll_device_StateMachine<ll_pnp_device>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  code *pcVar1;
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  
  ll_vmswitch_indications::EvtLogMachineException
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4));
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== EvtLogTransition @ 140002ef0 =====

/* private: void __cdecl ll_netvsc_state::EvtLogTransition(enum SmFx::TransitionType,enum
   ll_netvsc_StateMachine<class ll_netvsc_state>::StateId,enum ll_netvsc_StateMachine<class
   ll_netvsc_state>::EventId,enum ll_netvsc_StateMachine<class ll_netvsc_state>::StateId) __ptr64 */

void __thiscall
ll_netvsc_state::EvtLogTransition
          (ll_netvsc_state *this,TransitionType param_1,StateId param_2,EventId param_3,
          StateId param_4)

{
  short *psVar1;
  short *psVar2;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    psVar1 = &DAT_1400131f0;
    do {
      if (*psVar1 == (short)param_3) break;
      psVar1 = psVar1 + 8;
    } while (psVar1 != &DAT_1400132a0);
    psVar1 = &DAT_140013070;
    psVar2 = &DAT_140013070;
    do {
      if (*psVar2 == (undefined2)param_4) break;
      psVar2 = psVar2 + 8;
    } while (psVar2 != &DAT_1400131f0);
    do {
      if (*psVar1 == (short)param_2) break;
      psVar1 = psVar1 + 8;
    } while (psVar1 != &DAT_1400131f0);
    McTemplateK0xuusss_EtwWriteTransfer();
  }
  return;
}



===== EvtLogTransitionThunk @ 140002fc0 =====

/* private: static void __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined4 in_stack_ffffffffffffffe8;
  
  ll_netvsc_state::EvtLogTransition
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4),
             CONCAT22((short)((uint)in_stack_ffffffffffffffe8 >> 0x10),param_5));
  return;
}



===== EvtMachineDestroyed @ 140002fe0 =====

/* private: void __cdecl ll_netvsc_state::EvtMachineDestroyed(void) __ptr64 */

void __thiscall ll_netvsc_state::EvtMachineDestroyed(ll_netvsc_state *this)

{
  KeSetEvent(this + 0x160,0,0);
  return;
}



===== EvtMachineDestroyedThunk @ 140003010 =====

/* private: static void __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl ll_netvsc_StateMachine<ll_netvsc_state>::EvtMachineDestroyedThunk(void *param_1)

{
  ll_netvsc_state::EvtMachineDestroyed(param_1);
  return;
}



===== completing_bindEntry @ 140003030 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::completing_bindEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::completing_bindEntry(void *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x158);
  *(undefined4 *)(lVar1 + 0x18) = 0;
  KeSetEvent(lVar1,0,0);
  return 5;
}



===== event_from_oid_result @ 140003064 =====

/* private: static enum ll_netvsc_StateMachine<class ll_netvsc_state>::Event __cdecl
   ll_netvsc_state::event_from_oid_result(int) */

Event __cdecl ll_netvsc_state::event_from_oid_result(int param_1)

{
  undefined8 in_RAX;
  
  if ((param_1 == -0x3fffff45) || (param_1 == -0x3ffeffe9)) {
    return 4;
  }
  if (param_1 == 0) {
    return 5;
  }
  if (param_1 == 0x103) {
    return 6;
  }
  return (Event)CONCAT62((int6)((ulonglong)in_RAX >> 0x10),4 - (ushort)(param_1 != 0x10001));
}



===== failed_bindEntry @ 1400030b0 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::failed_bindEntry(void * __ptr64) */

ushort __cdecl ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::failed_bindEntry(void *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x158);
  *(undefined4 *)(lVar1 + 0x18) = 0xc0000001;
  KeSetEvent(lVar1,0,0);
  return 5;
}



===== falling_back_to_legacy_oidEntry @ 1400030f0 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::falling_back_to_legacy_oidEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::falling_back_to_legacy_oidEntry(void *param_1)

{
  *(undefined1 *)((longlong)param_1 + 0x178) = 1;
  return 5;
}



===== initialize @ 140003104 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl ll_netvsc_state::initialize(void) __ptr64 */

long __thiscall ll_netvsc_state::initialize(ll_netvsc_state *this)

{
  long lVar1;
  long lVar2;
  STATE_MACHINE_SPECIFICATION *local_58;
  ll_netvsc_state *local_50;
  undefined8 local_48;
  undefined8 local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
  local_40 = 0x21766e6e;
  local_16 = 0;
  local_12 = 0;
  local_58 = &ll_netvsc_StateMachine<ll_netvsc_state>::c_specification;
  local_50 = this;
  local_48 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  local_18 = 0x201;
  local_38 = ll_device_StateMachine<ll_pnp_device>::EvtLogMachineExceptionThunk;
  local_30 = ll_netvsc_StateMachine<ll_netvsc_state>::EvtLogEventEnqueueThunk;
  local_28 = ll_netvsc_StateMachine<ll_netvsc_state>::EvtLogTransitionThunk;
  local_20 = ll_netvsc_StateMachine<ll_netvsc_state>::EvtMachineDestroyedThunk;
  lVar1 = SmFx::StateMachineEngine::Initialize
                    ((StateMachineEngine *)this,(STATE_MACHINE_ENGINE_CONFIG *)&local_58);
  lVar2 = 0;
  if (lVar1 < 0) {
    lVar2 = lVar1;
  }
  return lVar2;
}



===== issue_oid_request @ 1400031b8 =====

/* private: enum ll_netvsc_StateMachine<class ll_netvsc_state>::Event __cdecl
   ll_netvsc_state::issue_oid_request(void) __ptr64 */

Event __thiscall ll_netvsc_state::issue_oid_request(ll_netvsc_state *this)

{
  code *pcVar1;
  int iVar2;
  Event EVar3;
  ll_netvsc_state *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    McTemplateK0xd_EtwWriteTransfer
              (this,&begin_issue_oid_request,this + 0x110,
               *(undefined8 *)(*(longlong *)(this + 8) + 0xdf8),(char)*(undefined4 *)(this + 0x38));
  }
  puVar5 = auStack_38;
  plVar4 = this + 0x18;
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(*(longlong *)(this + 8) + 0xe00);
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  if (((ulonglong)this & 7) != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
    puVar5 = auStack_30;
  }
  *(ll_netvsc_state **)(plVar4 + 0xd8) = this;
  *(uint *)(plVar4 + 0xd8) = *(uint *)(plVar4 + 0xd8) & 0xfffffffc;
  *(code **)(plVar4 + 0xe0) = oid_request_complete;
  *(undefined8 *)(puVar5 + -8) = 0x140003246;
  iVar2 = NdisFOidRequest();
  if (iVar2 != 0x103) {
    *(undefined8 *)(puVar5 + -8) = 0x14000325e;
    trace_oid_result(this,iVar2);
  }
  *(undefined8 *)(puVar5 + -8) = 0x140003265;
  EVar3 = event_from_oid_result(iVar2);
  return EVar3;
}



===== issuing_datapath_set_oid2Entry @ 140003280 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::issuing_datapath_set_oid2Entry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::issuing_datapath_set_oid2Entry(void *param_1)

{
  Event EVar1;
  
  EVar1 = ll_netvsc_state::set_datapath_enabled(param_1,false);
  return (ushort)EVar1;
}



===== issuing_datapath_set_oidEntry @ 1400032a0 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::issuing_datapath_set_oidEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::issuing_datapath_set_oidEntry(void *param_1)

{
  longlong lVar1;
  bool bVar2;
  Event EVar3;
  
  lVar1 = (longlong)param_1 + 0x180;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar1,0);
  bVar2 = *(bool *)((longlong)param_1 + 0x10);
  if (lVar1 != 0) {
    ExReleasePushLockSharedEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  EVar3 = ll_netvsc_state::set_datapath_enabled(param_1,bVar2);
  return (ushort)EVar3;
}



===== issuing_vf_query_oidEntry @ 140003320 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::issuing_vf_query_oidEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::issuing_vf_query_oidEntry(void *param_1)

{
  Event EVar1;
  undefined8 *puVar2;
  undefined8 local_f8;
  undefined8 local_e8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_18;
  
  if (*(char *)((longlong)param_1 + 0x178) == '\0') {
    local_f8 = 0x10703;
    puVar2 = (undefined8 *)((longlong)param_1 + 0x120);
    local_18 = 0;
    *puVar2 = 0;
    *(undefined4 *)((longlong)param_1 + 0x128) = 0;
    local_e8 = 0xc;
  }
  else {
    puVar2 = (undefined8 *)((longlong)param_1 + 300);
    local_f8 = 0x10702;
    local_e8 = 0x14;
    *puVar2 = 0;
    *(undefined8 *)((longlong)param_1 + 0x134) = 0;
    *(undefined4 *)((longlong)param_1 + 0x13c) = 0;
  }
  memset(&uStack_d0,0,0x80);
  local_30 = 0;
  local_28 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  *(undefined8 *)((longlong)param_1 + 0x18) = 0xf80296;
  *(undefined8 *)((longlong)param_1 + 0x20) = 0;
  *(undefined8 *)((longlong)param_1 + 0x28) = 0;
  *(undefined8 *)((longlong)param_1 + 0x30) = 0;
  *(undefined8 *)((longlong)param_1 + 0x38) = local_f8;
  *(undefined8 **)((longlong)param_1 + 0x40) = puVar2;
  *(undefined8 *)((longlong)param_1 + 0x48) = local_e8;
  *(undefined8 *)((longlong)param_1 + 0x50) = 0;
  *(undefined8 *)((longlong)param_1 + 0x58) = 0;
  *(undefined8 *)((longlong)param_1 + 0x60) = uStack_d0;
  *(undefined8 *)((longlong)param_1 + 0x68) = local_c8;
  *(undefined8 *)((longlong)param_1 + 0x70) = uStack_c0;
  *(undefined8 *)((longlong)param_1 + 0x78) = local_b8;
  *(undefined8 *)((longlong)param_1 + 0x80) = uStack_b0;
  *(undefined8 *)((longlong)param_1 + 0x88) = local_a8;
  *(undefined8 *)((longlong)param_1 + 0x90) = uStack_a0;
  *(undefined8 *)((longlong)param_1 + 0x98) = local_98;
  *(undefined8 *)((longlong)param_1 + 0xa0) = uStack_90;
  *(undefined8 *)((longlong)param_1 + 0xa8) = local_88;
  *(undefined8 *)((longlong)param_1 + 0xb0) = uStack_80;
  *(undefined8 *)((longlong)param_1 + 0xb8) = local_78;
  *(undefined8 *)((longlong)param_1 + 0xc0) = uStack_70;
  *(undefined8 *)((longlong)param_1 + 200) = local_68;
  *(undefined8 *)((longlong)param_1 + 0xd0) = uStack_60;
  *(undefined8 *)((longlong)param_1 + 0xd8) = uStack_58;
  *(undefined8 *)((longlong)param_1 + 0xe0) = 0;
  *(undefined8 *)((longlong)param_1 + 0xe8) = 0;
  *(undefined8 *)((longlong)param_1 + 0xf0) = 0;
  *(undefined8 *)((longlong)param_1 + 0xf8) = 0;
  *(undefined8 *)((longlong)param_1 + 0x100) = 0;
  *(undefined8 *)((longlong)param_1 + 0x108) = 0;
  EVar1 = ll_netvsc_state::issue_oid_request(param_1);
  return (ushort)EVar1;
}



===== nic_not_supportedEntry @ 1400034a0 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::nic_not_supportedEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::nic_not_supportedEntry(void *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x158);
  *(undefined4 *)(lVar1 + 0x18) = 0xc0010019;
  KeSetEvent(lVar1,0,0);
  return 5;
}



===== oid_request_complete @ 1400034e0 =====

/* private: static void __cdecl ll_netvsc_state::oid_request_complete(void * __ptr64,struct
   _NDIS_OID_REQUEST const * __ptr64,int) */

void __cdecl
ll_netvsc_state::oid_request_complete(void *param_1,_NDIS_OID_REQUEST *param_2,int param_3)

{
  code *pcVar1;
  Event EVar2;
  ll_netvsc_state *this;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = auStack_28;
  this = param_1;
  if ((_NDIS_OID_REQUEST *)((longlong)param_1 + 0x18) != param_2) {
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x140003502;
  trace_oid_result(this,param_3);
  *(undefined8 *)(puVar3 + -8) = 0x140003509;
  EVar2 = event_from_oid_result(param_3);
  *(undefined8 *)(puVar3 + -8) = 0x140003514;
  SmFx::StateMachineEngine::EnqueueEvent(param_1,(ushort)EVar2);
  return;
}



===== processing_vf_stateEntry @ 140003530 =====

/* public: static unsigned short __cdecl ll_netvsc_StateMachine<class
   ll_netvsc_state>::EntryFuncs::processing_vf_stateEntry(void * __ptr64) */

ushort __cdecl
ll_netvsc_StateMachine<ll_netvsc_state>::EntryFuncs::processing_vf_stateEntry(void *param_1)

{
  char cVar1;
  ll_vf *this;
  
  if (*(char *)((longlong)param_1 + 0x178) == '\0') {
    if (*(uint *)((longlong)param_1 + 0x4c) < 0xc) {
      return 4;
    }
    if (*(int *)((longlong)param_1 + 0x120) == 0) {
      return 4;
    }
    this = *(ll_vf **)((longlong)param_1 + 8);
    if (*(char *)((longlong)param_1 + 0x124) != '\0') {
      ll_vf::set_serial_number(this,*(ulong *)((longlong)param_1 + 0x128));
      cVar1 = *(char *)((longlong)param_1 + 0x125);
      goto LAB_14000359c;
    }
  }
  else {
    if (*(uint *)((longlong)param_1 + 0x4c) < 0x14) {
      return 4;
    }
    this = *(ll_vf **)((longlong)param_1 + 8);
    if (*(char *)((longlong)param_1 + 0x13c) != '\0') {
      ll_vf::set_serial_number(this,*(ulong *)((longlong)param_1 + 0x138));
      cVar1 = *(char *)((longlong)param_1 + 0x13d);
LAB_14000359c:
      ll_vf::set_vf_state(*(ll_vf **)((longlong)param_1 + 8),(cVar1 != '\0') + 1);
      return 5;
    }
  }
  ll_vf::set_vf_state(this,0);
  ll_vf::set_serial_number(*(ll_vf **)((longlong)param_1 + 8),0);
  return 5;
}



===== set_datapath_enabled @ 1400035d4 =====

/* private: enum ll_netvsc_StateMachine<class ll_netvsc_state>::Event __cdecl
   ll_netvsc_state::set_datapath_enabled(bool) __ptr64 */

Event __thiscall ll_netvsc_state::set_datapath_enabled(ll_netvsc_state *this,bool param_1)

{
  Event EVar1;
  ll_netvsc_state *plVar2;
  int local_110;
  undefined8 local_e8;
  undefined8 local_d8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  if (this[0x178] == (ll_netvsc_state)0x0) {
    plVar2 = this + 0x140;
    *(ulonglong *)plVar2 = (ulonglong)CONCAT14(param_1,1);
    local_e8 = 0x10705;
    local_d8 = 8;
  }
  else {
    plVar2 = this + 0x148;
    *(ulonglong *)plVar2 = 0xc0180;
    local_110 = (uint)param_1 << 0x10;
    *(int *)(this + 0x150) = local_110;
    *(undefined4 *)(this + 0x14c) = *(undefined4 *)(this + 0x130);
    *(undefined2 *)(this + 0x150) = *(undefined2 *)(this + 0x134);
    local_e8 = 0x10701;
    local_d8 = 0xc;
  }
  memset(&uStack_c0,0,0x80);
  local_20 = 0;
  local_18 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  *(undefined8 *)(this + 0x18) = 0x100f80296;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = local_e8;
  *(ll_netvsc_state **)(this + 0x40) = plVar2;
  *(undefined8 *)(this + 0x48) = local_d8;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = uStack_c0;
  *(undefined8 *)(this + 0x68) = local_b8;
  *(undefined8 *)(this + 0x70) = uStack_b0;
  *(undefined8 *)(this + 0x78) = local_a8;
  *(undefined8 *)(this + 0x80) = uStack_a0;
  *(undefined8 *)(this + 0x88) = local_98;
  *(undefined8 *)(this + 0x90) = uStack_90;
  *(undefined8 *)(this + 0x98) = local_88;
  *(undefined8 *)(this + 0xa0) = uStack_80;
  *(undefined8 *)(this + 0xa8) = local_78;
  *(undefined8 *)(this + 0xb0) = uStack_70;
  *(undefined8 *)(this + 0xb8) = local_68;
  *(undefined8 *)(this + 0xc0) = uStack_60;
  *(undefined8 *)(this + 200) = local_58;
  *(undefined8 *)(this + 0xd0) = uStack_50;
  *(undefined8 *)(this + 0xd8) = uStack_48;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  EVar1 = issue_oid_request(this);
  return EVar1;
}



===== trace_oid_result @ 140003798 =====

/* private: void __cdecl ll_netvsc_state::trace_oid_result(int) __ptr64 */

void __thiscall ll_netvsc_state::trace_oid_result(ll_netvsc_state *this,int param_1)

{
  code *pcVar1;
  Event EVar2;
  int iVar3;
  ll_netvsc_state *plVar4;
  undefined1 uVar5;
  undefined *puVar6;
  
  plVar4 = this;
  if (param_1 == 0) goto LAB_140003819;
  iVar3 = *(int *)(this + 0x38);
  uVar5 = 3;
  if (iVar3 == 0x10703) {
    EVar2 = event_from_oid_result(param_1);
    plVar4 = (ll_netvsc_state *)&DAT_00000004;
    if ((short)EVar2 != 4) goto LAB_1400037ea;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) == 0) goto LAB_140003819;
    puVar6 = &unsupported_issue_oid_request;
  }
  else {
LAB_1400037ea:
    uVar5 = (undefined1)iVar3;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) == 0)
    goto LAB_140003819;
    puVar6 = &fail_issue_oid_request;
  }
  McTemplateK0xqd_EtwWriteTransfer
            (plVar4,puVar6,this + 0x110,*(undefined8 *)(*(longlong *)(this + 8) + 0xdf8),uVar5,
             (char)param_1);
LAB_140003819:
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    McTemplateK0xqd_EtwWriteTransfer
              (plVar4,&end_issue_oid_request,this + 0x110,
               *(undefined8 *)(*(longlong *)(this + 8) + 0xdf8),(char)*(undefined4 *)(this + 0x38),
               (char)param_1);
  }
  iVar3 = EtwActivityIdControl(3,this + 0x110);
  if (iVar3 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x38);
  }
  return;
}



===== McTemplateK0xd_EtwWriteTransfer @ 140003884 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xd_EtwWriteTransfer
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



===== McTemplateK0xqd_EtwWriteTransfer @ 1400038f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xqd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_28 = &param_6;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0xus_EtwWriteTransfer @ 14000396c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xus_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  char *in_stack_00000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_40 = 8;
  local_38 = &uStack0000000000000028;
  local_30 = 1;
  if (in_stack_00000030 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000030[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  local_28 = in_stack_00000030;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000030,&state_machine_event_enqueued,0,4,local_58);
  return;
}



===== McTemplateK0xuusss_EtwWriteTransfer @ 140003a1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xuusss_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
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
  char *local_48;
  int local_40;
  undefined4 local_3c;
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
  lVar1 = -1;
  local_70 = 8;
  local_60 = 1;
  local_50 = 1;
  if (in_stack_00000038 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  if (in_stack_00000040 == (char *)0x0) {
    uVar3 = 5;
  }
  else {
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
  if (in_stack_00000048 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000048[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  local_48 = in_stack_00000038;
  local_38 = in_stack_00000040;
  local_28 = in_stack_00000048;
  McGenEventWrite_EtwWriteTransfer(uVar3,&state_machine_transition,0,7,local_88);
  return;
}



===== ~ll_notification_bus @ 140003b4c =====

/* public: __cdecl ll_notification_bus::~ll_notification_bus(void) __ptr64 */

void __thiscall ll_notification_bus::~ll_notification_bus(ll_notification_bus *this)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 uStack_40;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 auStack_18 [3];
  
  puVar3 = auStack_38;
  if (*(ll_notification_bus **)(this + 0x38) != this + 0x38) {
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
    puVar3 = auStack_30;
  }
  if (*(ll_notification_bus **)(this + 0x48) != this + 0x48) {
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
    puVar3 = puVar3 + 8;
  }
  *(undefined8 *)(puVar3 + 0x20) = 0;
  *(undefined8 *)(puVar3 + -8) = 0x140003b7f;
  iVar2 = KeWaitForSingleObject(this + 0x20,0,0,0);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
  }
  return;
}



===== deliver_events @ 140003b9c =====

/* private: void __cdecl ll_notification_bus::deliver_events(void) __ptr64 */

void __thiscall ll_notification_bus::deliver_events(ll_notification_bus *this)

{
  ll_notification_bus *plVar1;
  int iVar2;
  ll_notification_sink *plVar3;
  ll_notification_source *plVar4;
  ll_notification_kind lVar5;
  ll_notification_kind lVar6;
  
  plVar1 = this + 0x58;
LAB_140003bc8:
  do {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(plVar1,0);
    for (plVar3 = *(ll_notification_sink **)(this + 0x38);
        plVar3 != (ll_notification_sink *)(this + 0x38); plVar3 = *(ll_notification_sink **)plVar3)
    {
      if (*(int *)(plVar3 + 0x20) == 0) {
        *(undefined4 *)(plVar3 + 0x20) = 1;
        if (plVar1 != (ll_notification_bus *)0x0) {
          ExReleasePushLockExclusiveEx(plVar1,0);
          KeLeaveCriticalRegion();
        }
        lVar6 = 1;
        lVar5 = 0;
LAB_140003c83:
        deliver_events_to(this,plVar3,lVar5,lVar6);
        goto LAB_140003bc8;
      }
      if (*(int *)(plVar3 + 0x20) == 2) {
        *(undefined4 *)(plVar3 + 0x20) = 1;
        if (plVar1 != (ll_notification_bus *)0x0) {
          ExReleasePushLockExclusiveEx(plVar1,0);
          KeLeaveCriticalRegion();
        }
        lVar6 = 3;
        lVar5 = 2;
        goto LAB_140003c83;
      }
    }
    plVar4 = *(ll_notification_source **)(this + 0x48);
    while( true ) {
      if (plVar4 == (ll_notification_source *)(this + 0x48)) {
        KeSetEvent(this + 0x20,0,0);
        if (plVar1 != (ll_notification_bus *)0x0) {
          ExReleasePushLockExclusiveEx(plVar1,0);
          KeLeaveCriticalRegion();
        }
        return;
      }
      iVar2 = *(int *)(plVar4 + 0x20);
      if (iVar2 == 0) {
        *(undefined4 *)(plVar4 + 0x20) = 1;
        if (plVar1 != (ll_notification_bus *)0x0) {
          ExReleasePushLockExclusiveEx(plVar1,0);
          KeLeaveCriticalRegion();
        }
        lVar5 = 4;
        goto LAB_140003cc2;
      }
      if (iVar2 == 2) {
        *(undefined4 *)(plVar4 + 0x20) = 1;
        if (plVar1 != (ll_notification_bus *)0x0) {
          ExReleasePushLockExclusiveEx(plVar1,0);
          KeLeaveCriticalRegion();
        }
        lVar5 = 5;
        goto LAB_140003cc2;
      }
      if (iVar2 == 3) break;
      plVar4 = *(ll_notification_source **)plVar4;
    }
    *(undefined4 *)(plVar4 + 0x20) = 4;
    if (plVar1 != (ll_notification_bus *)0x0) {
      ExReleasePushLockExclusiveEx(plVar1,0);
      KeLeaveCriticalRegion();
    }
    lVar5 = 6;
LAB_140003cc2:
    deliver_events_from(this,plVar4,lVar5);
  } while( true );
}



===== deliver_events_from @ 140003d84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl ll_notification_bus::deliver_events_from(struct ll_notification_source *
   __ptr64,enum ll_notification_kind) __ptr64 */

void __thiscall
ll_notification_bus::deliver_events_from
          (ll_notification_bus *this,ll_notification_source *param_1,ll_notification_kind param_2)

{
  ll_notification_bus *plVar1;
  ll_notification_bus *plVar2;
  ll_notification_bus *plVar3;
  ll_notification_bus *plVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  ll_notification_bus *local_28;
  ll_notification_bus *local_20;
  
  plVar1 = this + 0x38;
  plVar2 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar2,0);
  puVar6 = auStack_58;
  plVar3 = *(ll_notification_bus **)plVar1;
  if (*(ll_notification_bus **)(plVar3 + 8) == plVar1) {
    *(ll_notification_bus ***)(plVar3 + 8) = &local_28;
    *(ll_notification_bus ***)plVar1 = &local_28;
    local_28 = plVar3;
    local_20 = plVar1;
    if (*(ll_notification_bus ***)(plVar3 + 8) == &local_28) {
      do {
        plVar3 = local_28;
        if (*(ll_notification_bus ***)local_20 != &local_28) break;
        *(ll_notification_bus **)local_20 = local_28;
        *(ll_notification_bus **)(local_28 + 8) = local_20;
        if (local_28 == plVar1) goto LAB_140003ec9;
        plVar4 = *(ll_notification_bus **)local_28;
        if (*(ll_notification_bus **)(plVar4 + 8) != local_28) break;
        *(ll_notification_bus ***)(plVar4 + 8) = &local_28;
        *(ll_notification_bus ***)local_28 = &local_28;
        local_20 = local_28;
        if (plVar2 != (ll_notification_bus *)0x0) {
          local_28 = plVar4;
          ExReleasePushLockExclusiveEx(plVar2,0);
          KeLeaveCriticalRegion();
          plVar4 = local_28;
        }
        local_28 = plVar4;
        (**(code **)(plVar3 + 0x10))(*(longlong *)(plVar3 + 0x18),plVar3,param_2,param_1);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(plVar2,0);
      } while (*(ll_notification_bus ***)(local_28 + 8) == &local_28);
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar6 = auStack_50;
LAB_140003ec9:
  if (plVar2 != (ll_notification_bus *)0x0) {
    *(undefined8 *)(puVar6 + -8) = 0x140003eda;
    ExReleasePushLockExclusiveEx(plVar2,0);
    *(undefined8 *)(puVar6 + -8) = 0x140003ee6;
    KeLeaveCriticalRegion();
  }
  return;
}



===== deliver_events_thunk @ 140003f10 =====

/* private: static void __cdecl ll_notification_bus::deliver_events_thunk(void * __ptr64) */

void __cdecl ll_notification_bus::deliver_events_thunk(void *param_1)

{
  deliver_events(param_1);
  return;
}



===== deliver_events_to @ 140003f28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl ll_notification_bus::deliver_events_to(struct ll_notification_sink *
   __ptr64,enum ll_notification_kind,enum ll_notification_kind) __ptr64 */

void __thiscall
ll_notification_bus::deliver_events_to
          (ll_notification_bus *this,ll_notification_sink *param_1,ll_notification_kind param_2,
          ll_notification_kind param_3)

{
  ll_notification_bus *plVar1;
  ll_notification_bus *plVar2;
  ll_notification_bus *plVar3;
  ll_notification_bus *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  ll_notification_bus *local_28;
  ll_notification_bus *local_20;
  
  plVar1 = this + 0x48;
  plVar2 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar2,0);
  puVar7 = auStack_58;
  plVar3 = *(ll_notification_bus **)plVar1;
  if (*(ll_notification_bus **)(plVar3 + 8) == plVar1) {
    *(ll_notification_bus ***)(plVar3 + 8) = &local_28;
    *(ll_notification_bus ***)plVar1 = &local_28;
    local_28 = plVar3;
    local_20 = plVar1;
    if (*(ll_notification_bus ***)(plVar3 + 8) == &local_28) {
      do {
        plVar3 = local_28;
        if (*(ll_notification_bus ***)local_20 != &local_28) break;
        *(ll_notification_bus **)local_20 = local_28;
        *(ll_notification_bus **)(local_28 + 8) = local_20;
        if (local_28 == plVar1) goto LAB_140004074;
        plVar4 = *(ll_notification_bus **)local_28;
        if (*(ll_notification_bus **)(plVar4 + 8) != local_28) break;
        *(ll_notification_bus ***)(plVar4 + 8) = &local_28;
        *(ll_notification_bus ***)local_28 = &local_28;
        local_20 = local_28;
        if (plVar2 != (ll_notification_bus *)0x0) {
          local_28 = plVar4;
          ExReleasePushLockExclusiveEx(plVar2,0);
          KeLeaveCriticalRegion();
          plVar4 = local_28;
        }
        local_28 = plVar4;
        (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x18),param_1,param_2,plVar3);
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(plVar2,0);
      } while (*(ll_notification_bus ***)(local_28 + 8) == &local_28);
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar7 = auStack_50;
LAB_140004074:
  if (plVar2 != (ll_notification_bus *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x140004085;
    ExReleasePushLockExclusiveEx(plVar2,0);
    *(undefined8 *)(puVar7 + -8) = 0x140004091;
    KeLeaveCriticalRegion();
  }
  pcVar6 = *(code **)(param_1 + 0x10);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(puVar7 + -8) = 0x1400040ac;
  (*pcVar6)(uVar5,param_1,param_3,0);
  return;
}



===== deregister_source @ 1400040d4 =====

/* public: void __cdecl ll_notification_bus::deregister_source(struct ll_notification_source *
   __ptr64) __ptr64 */

void __thiscall
ll_notification_bus::deregister_source(ll_notification_bus *this,ll_notification_source *param_1)

{
  ll_notification_bus *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  notify_source_state_change(this,param_1,3);
  puVar6 = auStack_38;
  while( true ) {
    if (plVar1 != (ll_notification_bus *)0x0) {
      ExReleasePushLockExclusiveEx(plVar1,0);
      KeLeaveCriticalRegion();
    }
    local_18 = 0;
    iVar5 = KeWaitForSingleObject(this + 0x20,0,0,0);
    if (iVar5 != 0) break;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(plVar1);
    if (*(int *)(param_1 + 0x20) == 4) {
LAB_14000418b:
      lVar2 = *(longlong *)param_1;
      if ((*(ll_notification_source **)(lVar2 + 8) != param_1) ||
         (plVar3 = *(longlong **)(param_1 + 8), (ll_notification_source *)*plVar3 != param_1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      if (plVar1 != (ll_notification_bus *)0x0) {
        *(undefined8 *)(puVar6 + -8) = 0x1400041b5;
        ExReleasePushLockExclusiveEx(plVar1,0);
        *(undefined8 *)(puVar6 + -8) = 0x1400041c1;
        KeLeaveCriticalRegion();
      }
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(7);
  puVar6 = auStack_30;
  goto LAB_14000418b;
}



===== notify_source_state_change @ 1400041e4 =====

/* private: void __cdecl ll_notification_bus::notify_source_state_change(struct
   ll_notification_source * __ptr64,enum ll_notification_source::registration_state) __ptr64 */

void __thiscall
ll_notification_bus::notify_source_state_change
          (ll_notification_bus *this,ll_notification_source *param_1,registration_state param_2)

{
  int iVar1;
  
  *(registration_state *)(param_1 + 0x20) = param_2;
  iVar1 = KeResetEvent(this + 0x20);
  if (iVar1 != 0) {
    ExQueueWorkItem(this,1);
  }
  return;
}



===== notify_source_updated @ 140004228 =====

/* public: void __cdecl ll_notification_bus::notify_source_updated(struct ll_notification_source *
   __ptr64) __ptr64 */

void __thiscall
ll_notification_bus::notify_source_updated
          (ll_notification_bus *this,ll_notification_source *param_1)

{
  ll_notification_bus *plVar1;
  
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  if (*(int *)(param_1 + 0x20) == 1) {
    notify_source_state_change(this,param_1,2);
  }
  if (plVar1 != (ll_notification_bus *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== register_source @ 1400042b0 =====

/* public: void __cdecl ll_notification_bus::register_source(struct ll_notification_source *
   __ptr64) __ptr64 */

void __thiscall
ll_notification_bus::register_source(ll_notification_bus *this,ll_notification_source *param_1)

{
  ll_notification_bus *plVar1;
  code *pcVar2;
  ll_notification_bus *plVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  puVar5 = auStack_28;
  plVar3 = this + 0x48;
  plVar4 = *(longlong **)(this + 0x50);
  if ((ll_notification_bus *)*plVar4 != plVar3) {
    pcVar2 = (code *)swi(0x29);
    plVar3 = (ll_notification_bus *)(*pcVar2)(3);
    puVar5 = auStack_20;
  }
  *(longlong **)(param_1 + 8) = plVar4;
  *(ll_notification_bus **)param_1 = plVar3;
  *plVar4 = (longlong)param_1;
  *(ll_notification_source **)(plVar3 + 8) = param_1;
  *(undefined8 *)(puVar5 + -8) = 0x140004316;
  notify_source_state_change(this,param_1,0);
  if (plVar1 != (ll_notification_bus *)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x140004327;
    ExReleasePushLockExclusiveEx(plVar1,0);
    *(undefined8 *)(puVar5 + -8) = 0x140004333;
    KeLeaveCriticalRegion();
  }
  return;
}



===== request_reeunumeration @ 140004350 =====

/* public: void __cdecl ll_notification_bus::request_reeunumeration(struct ll_notification_sink *
   __ptr64) __ptr64 */

void __thiscall
ll_notification_bus::request_reeunumeration(ll_notification_bus *this,ll_notification_sink *param_1)

{
  ll_notification_bus *plVar1;
  int iVar2;
  
  plVar1 = this + 0x58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  *(undefined4 *)(param_1 + 0x20) = 2;
  iVar2 = KeResetEvent(this + 0x20);
  if (iVar2 != 0) {
    ExQueueWorkItem(this,1);
  }
  if (plVar1 != (ll_notification_bus *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== ll_pnp_device @ 1400043f0 =====

/* private: __cdecl ll_pnp_device::ll_pnp_device(void * __ptr64) __ptr64 */

ll_pnp_device * __thiscall ll_pnp_device::ll_pnp_device(ll_pnp_device *this,void *param_1)

{
  longlong lVar1;
  ll_global *this_00;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  this[0x1a] = (ll_pnp_device)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x20] = (ll_pnp_device)0x0;
  *(undefined8 *)(this + 0x24) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 1;
  *(ll_pnp_device **)(this + 0x50) = this;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  KeInitializeEvent(this + 0x88,0,0);
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  LOCK();
  UNLOCK();
  lVar1 = DAT_140013708 + 1;
  DAT_140013708 = DAT_140013708 + 1;
  *(longlong *)(this + 0xa0) = lVar1;
  this_00 = ll_global::get_instance();
  ll_notification_bus::register_source
            ((ll_notification_bus *)this_00,(ll_notification_source *)(this + 0x38));
  return this;
}



===== ~ll_pnp_device @ 1400044dc =====

/* public: __cdecl ll_pnp_device::~ll_pnp_device(void) __ptr64 */

void __thiscall ll_pnp_device::~ll_pnp_device(ll_pnp_device *this)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  ll_global *this_00;
  undefined1 *puVar4;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  this_00 = ll_global::get_instance();
  ll_notification_bus::deregister_source
            ((ll_notification_bus *)this_00,(ll_notification_source *)(this + 0x38));
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,1);
  local_18 = 0;
  iVar3 = KeWaitForSingleObject(this + 0x88,0,0,0);
  puVar4 = auStack_38;
  if (iVar3 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(7);
    puVar4 = auStack_30;
  }
  lVar1 = *(longlong *)(this + 0x78);
  if (lVar1 != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x140004544;
    ExFreePoolWithTag(lVar1,0x21766e6e);
  }
  if (*(longlong *)(this + 0x70) != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x140004559;
    ZwClose();
  }
  lVar1 = *(longlong *)(this + 0x68);
  if (lVar1 != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x140004573;
    ExFreePoolWithTag(lVar1,0x21766e6e);
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (lVar1 != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x14000458d;
    ExFreePoolWithTag(lVar1,0x21766e6e);
  }
  return;
}



===== EvtLogEventEnqueue @ 1400045a0 =====

/* private: void __cdecl ll_pnp_device::EvtLogEventEnqueue(enum ll_device_StateMachine<class
   ll_pnp_device>::EventId) __ptr64 */

void __thiscall ll_pnp_device::EvtLogEventEnqueue(ll_pnp_device *this,EventId param_1)

{
  undefined **ppuVar1;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    ppuVar1 = (undefined **)&DAT_140013330;
    do {
      if (*(short *)ppuVar1 == (short)param_1) break;
      ppuVar1 = ppuVar1 + 2;
    } while (ppuVar1 != &PTR_LOOP_1400133b0);
    McTemplateK0xus_EtwWriteTransfer();
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 140004600 =====

/* private: static void __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
ll_device_StateMachine<ll_pnp_device>::EvtLogEventEnqueueThunk(void *param_1,ushort param_2)

{
  undefined2 in_register_00000012;
  
  ll_pnp_device::EvtLogEventEnqueue(param_1,CONCAT22(in_register_00000012,param_2));
  return;
}



===== EvtLogTransition @ 140004618 =====

/* private: void __cdecl ll_pnp_device::EvtLogTransition(enum SmFx::TransitionType,enum
   ll_device_StateMachine<class ll_pnp_device>::StateId,enum ll_device_StateMachine<class
   ll_pnp_device>::EventId,enum ll_device_StateMachine<class ll_pnp_device>::StateId) __ptr64 */

void __thiscall
ll_pnp_device::EvtLogTransition
          (ll_pnp_device *this,TransitionType param_1,StateId param_2,EventId param_3,
          StateId param_4)

{
  undefined **ppuVar1;
  short *psVar2;
  short *psVar3;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    ppuVar1 = (undefined **)&DAT_140013330;
    do {
      if (*(short *)ppuVar1 == (short)param_3) break;
      ppuVar1 = ppuVar1 + 2;
    } while (ppuVar1 != &PTR_LOOP_1400133b0);
    psVar2 = &DAT_1400132a0;
    psVar3 = &DAT_1400132a0;
    do {
      if (*psVar3 == (undefined2)param_4) break;
      psVar3 = psVar3 + 8;
    } while (psVar3 != (short *)&DAT_140013330);
    do {
      if (*psVar2 == (short)param_2) break;
      psVar2 = psVar2 + 8;
    } while (psVar2 != (short *)&DAT_140013330);
    McTemplateK0xuusss_EtwWriteTransfer();
  }
  return;
}



===== EvtLogTransitionThunk @ 1400046f0 =====

/* private: static void __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
ll_device_StateMachine<ll_pnp_device>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined4 in_stack_ffffffffffffffe8;
  
  ll_pnp_device::EvtLogTransition
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4),
             CONCAT22((short)((uint)in_stack_ffffffffffffffe8 >> 0x10),param_5));
  return;
}



===== EvtMachineDestroyed @ 140004710 =====

/* private: void __cdecl ll_pnp_device::EvtMachineDestroyed(void) __ptr64 */

void __thiscall ll_pnp_device::EvtMachineDestroyed(ll_pnp_device *this)

{
  KeSetEvent(this + 0x88,0,0);
  return;
}



===== EvtMachineDestroyedThunk @ 140004740 =====

/* private: static void __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl ll_device_StateMachine<ll_pnp_device>::EvtMachineDestroyedThunk(void *param_1)

{
  ll_pnp_device::EvtMachineDestroyed(param_1);
  return;
}



===== destroyingEntry @ 140004760 =====

/* public: static unsigned short __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EntryFuncs::destroyingEntry(void * __ptr64) */

ushort __cdecl ll_device_StateMachine<ll_pnp_device>::EntryFuncs::destroyingEntry(void *param_1)

{
  SmFx::StateMachineEngine::EnqueueEvent(param_1,5);
  return 0;
}



===== disabling_proxyEntry @ 140004780 =====

/* public: static unsigned short __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EntryFuncs::disabling_proxyEntry(void * __ptr64) */

ushort __cdecl
ll_device_StateMachine<ll_pnp_device>::EntryFuncs::disabling_proxyEntry(void *param_1)

{
  ll_vpci *this;
  long lVar1;
  
  this = (ll_vpci *)((longlong)param_1 + 0x70);
  lVar1 = ll_vpci::open(this);
  if (lVar1 == 0) {
    ll_vpci::set_pci_proxy_enabled(this,false);
    if (*(longlong *)this != 0) {
      ZwClose();
    }
    *(undefined8 *)this = 0;
  }
  return 8;
}



===== in_proxyEntry @ 1400047d0 =====

/* public: static unsigned short __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EntryFuncs::in_proxyEntry(void * __ptr64) */

ushort __cdecl ll_device_StateMachine<ll_pnp_device>::EntryFuncs::in_proxyEntry(void *param_1)

{
  longlong lVar1;
  ll_global *this;
  
  lVar1 = (longlong)param_1 + 0xb0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  if (*(char *)((longlong)param_1 + 0x20) == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x20) = 1;
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
    this = ll_global::get_instance();
    ll_notification_bus::notify_source_updated
              ((ll_notification_bus *)this,(ll_notification_source *)((longlong)param_1 + 0x38));
  }
  else if (lVar1 != 0) {
    ExReleasePushLockExclusiveEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return 0;
}



===== in_proxyStopTimer @ 140004890 =====

/* public: static enum SmFx::StopTimerResult __cdecl ll_device_StateMachine<class
   ll_pnp_device>::StopTimerOnExitDetails::in_proxyStopTimer(void * __ptr64) */

StopTimerResult __cdecl
ll_device_StateMachine<ll_pnp_device>::StopTimerOnExitDetails::in_proxyStopTimer(void *param_1)

{
  longlong lVar1;
  ll_global *this;
  
  lVar1 = (longlong)param_1 + 0xb0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  if (*(char *)((longlong)param_1 + 0x20) == '\0') {
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  else {
    *(undefined8 *)((longlong)param_1 + 0x24) = 0;
    *(undefined1 *)((longlong)param_1 + 0x20) = 0;
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
    this = ll_global::get_instance();
    ll_notification_bus::notify_source_updated
              ((ll_notification_bus *)this,(ll_notification_source *)((longlong)param_1 + 0x38));
  }
  return 1;
}



===== initialize @ 140004940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl ll_pnp_device::initialize(class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<wchar_t * __ptr64,void
   (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl pool_helpers<wchar_t *
   __ptr64,561409646>::free(wchar_t * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,wchar_t * __ptr64,wchar_t * __ptr64,0,std::nullptr_t> > > && __ptr64) __ptr64 */

long __thiscall
ll_pnp_device::initialize
          (ll_pnp_device *this,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_1)

{
  void *_Src;
  longlong lVar1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ll_pnp_device *plVar7;
  STATE_MACHINE_SPECIFICATION *local_78;
  ll_pnp_device *local_70;
  undefined8 local_68;
  undefined8 local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  undefined2 local_38;
  undefined4 local_36;
  undefined2 local_32;
  
  plVar7 = this + 0x60;
  if (plVar7 != (ll_pnp_device *)param_1) {
    lVar5 = *(longlong *)param_1;
    if (*(longlong *)plVar7 != 0) {
      ExFreePoolWithTag(*(longlong *)plVar7,0x21766e6e);
    }
    *(longlong *)plVar7 = lVar5;
    *(undefined8 *)param_1 = 0;
  }
  _Src = *(void **)plVar7;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)((longlong)_Src + lVar5 * 2) != 0);
  iVar2 = (int)lVar5 * 2;
  lVar6 = (longlong)(iVar2 + 4) + 2;
  if (lVar6 != *(longlong *)(this + 0x80)) {
    lVar4 = ExAllocatePool2(0x100,lVar6,0x21766e6e);
    if (lVar4 == 0) {
      return -0x3fffff66;
    }
    lVar1 = *(longlong *)(this + 0x78);
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0x21766e6e);
    }
    *(longlong *)(this + 0x78) = lVar4;
    *(longlong *)(this + 0x80) = lVar6;
  }
  plVar7 = this + 0x78;
  **(int **)plVar7 = iVar2 + 2;
  memmove((void *)(*(longlong *)plVar7 + 4),_Src,lVar5 * 2);
  local_60 = 0x21766e6e;
  local_36 = 0;
  local_32 = 0;
  *(undefined2 *)(*(longlong *)plVar7 + 4 + lVar5 * 2) = 0;
  local_78 = &ll_device_StateMachine<ll_pnp_device>::c_specification;
  local_70 = this;
  local_68 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  local_38 = 0x101;
  local_58 = ll_device_StateMachine<ll_pnp_device>::EvtLogMachineExceptionThunk;
  local_50 = ll_device_StateMachine<ll_pnp_device>::EvtLogEventEnqueueThunk;
  local_48 = ll_device_StateMachine<ll_pnp_device>::EvtLogTransitionThunk;
  local_40 = ll_device_StateMachine<ll_pnp_device>::EvtMachineDestroyedThunk;
  lVar3 = SmFx::StateMachineEngine::Initialize
                    ((StateMachineEngine *)this,(STATE_MACHINE_ENGINE_CONFIG *)&local_78);
  return lVar3;
}



===== notify_missing @ 140004ae4 =====

/* public: void __cdecl ll_pnp_device::notify_missing(void) __ptr64 */

void __thiscall ll_pnp_device::notify_missing(ll_pnp_device *this)

{
  ll_pnp_device *plVar1;
  
  plVar1 = this + 0xb0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  this[0x1a] = (ll_pnp_device)0x0;
  if (plVar1 != (ll_pnp_device *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,4);
  return;
}



===== requesting_proxyEntry @ 140004b60 =====

/* public: static unsigned short __cdecl ll_device_StateMachine<class
   ll_pnp_device>::EntryFuncs::requesting_proxyEntry(void * __ptr64) */

ushort __cdecl
ll_device_StateMachine<ll_pnp_device>::EntryFuncs::requesting_proxyEntry(void *param_1)

{
  ll_vpci *this;
  long lVar1;
  
  this = (ll_vpci *)((longlong)param_1 + 0x70);
  lVar1 = ll_vpci::open(this);
  if (lVar1 == 0) {
    ll_vpci::set_pci_proxy_enabled(this,true);
    if (*(longlong *)this != 0) {
      ZwClose();
    }
    *(undefined8 *)this = 0;
  }
  return 8;
}



===== update_symbolic_link @ 140004bac =====

/* public: bool __cdecl ll_pnp_device::update_symbolic_link(struct _UNICODE_STRING const * __ptr64)
   __ptr64 */

bool __thiscall ll_pnp_device::update_symbolic_link(ll_pnp_device *this,_UNICODE_STRING *param_1)

{
  ll_pnp_device *plVar1;
  char cVar2;
  undefined2 *puVar3;
  bool bVar4;
  ll_pnp_device local_18 [16];
  
  plVar1 = this + 0x68;
  bVar4 = true;
  if ((*(longlong *)plVar1 != 0) &&
     (cVar2 = RtlEqualUnicodeString(*(longlong *)plVar1,param_1,1), cVar2 != '\0')) {
    return true;
  }
  puVar3 = (undefined2 *)ExAllocatePool2(0x100,(ulonglong)*(ushort *)param_1 + 0x10,0x21766e6e);
  if (puVar3 == (undefined2 *)0x0) {
    bVar4 = false;
  }
  else {
    *puVar3 = *(undefined2 *)param_1;
    puVar3[1] = *(undefined2 *)param_1;
    *(undefined2 **)(puVar3 + 4) = puVar3 + 8;
    memmove(puVar3 + 8,*(void **)(param_1 + 8),(ulonglong)*(ushort *)param_1);
    if (plVar1 == local_18) {
      ExFreePoolWithTag(puVar3,0x21766e6e);
    }
    else {
      if (*(longlong *)plVar1 != 0) {
        ExFreePoolWithTag(*(longlong *)plVar1,0x21766e6e);
      }
      *(undefined2 **)plVar1 = puVar3;
    }
  }
  return bVar4;
}



===== ~ll_policy_table @ 140004c98 =====

/* public: __cdecl ll_policy_table::~ll_policy_table(void) __ptr64 */

void __thiscall ll_policy_table::~ll_policy_table(ll_policy_table *this)

{
  ll_global *this_00;
  
  this_00 = ll_global::get_instance();
  ll_notification_bus::deregister_source
            ((ll_notification_bus *)this_00,(ll_notification_source *)(this + 0x28));
  if (*(longlong *)(this + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x20),0x21766e6e);
    *(undefined8 *)(this + 0x20) = 0;
  }
  return;
}



===== get_policy @ 140004ce0 =====

/* public: long __cdecl ll_policy_table::get_policy(unsigned short,struct NNVDRV_POLICY_BLOB *
   __ptr64,unsigned __int64,unsigned __int64 * __ptr64)const __ptr64 */

long __thiscall
ll_policy_table::get_policy
          (ll_policy_table *this,ushort param_1,NNVDRV_POLICY_BLOB *param_2,__uint64 param_3,
          __uint64 *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  size_t _Size;
  NNVDRV_POLICY_BLOB *pNVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  *param_4 = 0;
  if (param_1 != 1) {
    return -0x3fffffa8;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(this);
  _Size = *(longlong *)(this + 0x10) * 0x30 + 0x20;
  *param_4 = _Size;
  uVar8 = 3;
  if (param_3 < _Size) {
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)(param_2 + 8) = 0;
    *(undefined8 *)(param_2 + 0x10) = 0;
    *(undefined8 *)(param_2 + 0x18) = 0;
  }
  else {
    memset(param_2,0,_Size);
    *(undefined4 *)(param_2 + 0xc) = 0x20;
    uVar12 = 0;
    if (*(longlong *)(this + 0x10) != 0) {
      lVar10 = 0;
      lVar11 = 0;
      do {
        pNVar9 = param_2 + (ulonglong)*(uint *)(param_2 + 0xc) + lVar11;
        iVar2 = *(int *)(lVar10 + *(longlong *)(this + 0x20));
        if (iVar2 == 0) {
          uVar5 = 1;
        }
        else if (iVar2 == 1) {
          uVar5 = 2;
        }
        else {
          if (iVar2 != 2) goto LAB_140004df9;
          uVar5 = 3;
        }
        *(undefined4 *)(pNVar9 + 0x24) = uVar5;
        uVar12 = uVar12 + 1;
        *pNVar9 = (NNVDRV_POLICY_BLOB)0x6;
        lVar11 = lVar11 + 0x30;
        lVar3 = *(longlong *)(this + 0x20);
        *(undefined4 *)(pNVar9 + 1) = *(undefined4 *)(lVar10 + 4 + lVar3);
        lVar1 = lVar10 + 8;
        lVar10 = lVar10 + 0xc;
        *(undefined2 *)(pNVar9 + 5) = *(undefined2 *)(lVar1 + lVar3);
      } while (uVar12 < *(ulonglong *)(this + 0x10));
    }
  }
  puVar6 = auStack_38;
  puVar7 = auStack_38;
  *(undefined4 *)param_2 = 1;
  iVar2 = *(int *)(this + 8);
  if (iVar2 == 0) {
    uVar8 = 1;
  }
  else {
    if (iVar2 != 1) {
      puVar7 = auStack_38;
      if (iVar2 == 2) goto LAB_140004e0a;
LAB_140004df9:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar6 = auStack_30;
    }
    uVar8 = 2;
    puVar7 = puVar6;
  }
LAB_140004e0a:
  *(undefined4 *)(param_2 + 4) = uVar8;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + 0x10);
  *(undefined8 *)(puVar7 + -8) = 0x140004e1f;
  ExReleasePushLockSharedEx(this,0);
  *(undefined8 *)(puVar7 + -8) = 0x140004e2b;
  KeLeaveCriticalRegion();
  return 0;
}



===== get_role_for_mac_address @ 140004e54 =====

/* public: enum ll_vf_role __cdecl ll_policy_table::get_role_for_mac_address(unsigned char const *
   __ptr64) __ptr64 */

ll_vf_role __thiscall
ll_policy_table::get_role_for_mac_address(ll_policy_table *this,uchar *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ll_vf_role lVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this,0);
  uVar3 = 0;
  if (*(ulonglong *)(this + 0x10) != 0) {
    lVar1 = *(longlong *)(this + 0x20);
    uVar2 = 0;
    do {
      if ((*(int *)(lVar1 + 4 + uVar2 * 0xc) == *(int *)param_1) &&
         (*(short *)(lVar1 + 8 + uVar2 * 0xc) == *(short *)(param_1 + 4))) {
        lVar4 = *(ll_vf_role *)(lVar1 + uVar2 * 0xc);
        goto LAB_140004eba;
      }
      uVar3 = uVar3 + 1;
      uVar2 = (ulonglong)uVar3;
    } while (uVar2 < *(ulonglong *)(this + 0x10));
  }
  lVar4 = *(ll_vf_role *)(this + 8);
LAB_140004eba:
  ExReleasePushLockExclusiveEx(this,0);
  KeLeaveCriticalRegion();
  return lVar4;
}



===== set_policy @ 140004ef8 =====

/* public: long __cdecl ll_policy_table::set_policy(struct NNVDRV_POLICY_BLOB const *
   __ptr64,unsigned __int64) __ptr64 */

long __thiscall
ll_policy_table::set_policy(ll_policy_table *this,NNVDRV_POLICY_BLOB *param_1,__uint64 param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  ll_global *this_00;
  NNVDRV_POLICY_BLOB *pNVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  if (*(short *)param_1 != 1) {
    return -0x3fffffa8;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) {
    uVar2 = *(uint *)(param_1 + 0xc);
    uVar10 = *(uint *)(param_1 + 8);
    if (((uVar2 == 0) == (uVar10 == 0)) && ((0x1f < uVar2 || ((uVar10 == 0 && (uVar2 == 0)))))) {
      if ((0xffffffff < (ulonglong)uVar10 * 0x30) ||
         (uVar9 = (uint)((ulonglong)uVar10 * 0x30), uVar5 = uVar2 + uVar9, uVar5 < uVar9)) {
        return -0x3fffff6b;
      }
      if (uVar5 <= param_2) {
        if (0x1000 < uVar10) {
          return -0x3ffffbd5;
        }
        uVar11 = 0;
        if (uVar10 != 0) {
          do {
            pNVar7 = param_1 + uVar11 * 0x30 + (ulonglong)uVar2;
            iVar1 = *(int *)(pNVar7 + 0x24);
            if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 3)) {
              return -0x3ffffff3;
            }
            if (*pNVar7 != (NNVDRV_POLICY_BLOB)0x6) {
              return -0x3ffffff3;
            }
            if (*(longlong *)(pNVar7 + 0x28) != 0) {
              return -0x3ffffff3;
            }
            uVar5 = (int)uVar11 + 1;
            uVar11 = (ulonglong)uVar5;
            for (uVar9 = uVar5; uVar9 < uVar10; uVar9 = uVar9 + 1) {
              lVar8 = (ulonglong)uVar9 * 0x30 + (ulonglong)uVar2;
              if (((param_1[lVar8] == (NNVDRV_POLICY_BLOB)0x6) &&
                  (*(int *)(pNVar7 + 1) == *(int *)(param_1 + lVar8 + 1))) &&
                 (*(short *)(pNVar7 + 5) == *(short *)(param_1 + lVar8 + 5))) {
                return -0x3ffffff3;
              }
            }
          } while (uVar5 < uVar10);
        }
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(this,0);
        if (*(ulonglong *)(this + 0x18) < (ulonglong)*(uint *)(param_1 + 8)) {
          lVar8 = ExAllocatePool2(0x100,(ulonglong)*(uint *)(param_1 + 8) * 0xc,0x21766e6e);
          if (lVar8 == 0) {
            ExReleasePushLockExclusiveEx(this,0);
            KeLeaveCriticalRegion();
            return -0x3fffff66;
          }
          if (*(longlong *)(this + 0x20) != 0) {
            ExFreePoolWithTag(*(longlong *)(this + 0x20),0x21766e6e);
          }
          *(longlong *)(this + 0x20) = lVar8;
          *(ulonglong *)(this + 0x18) = (ulonglong)*(uint *)(param_1 + 8);
        }
        iVar1 = *(int *)(param_1 + 4);
        if (iVar1 == 1) {
          uVar6 = 0;
        }
        else if (iVar1 == 2) {
          uVar6 = 1;
        }
        else {
          if (iVar1 != 3) {
LAB_14000519f:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(5);
            return -0x3fffff6b;
          }
          uVar6 = 2;
        }
        *(undefined4 *)(this + 8) = uVar6;
        uVar2 = 0;
        uVar11 = 0;
        if (*(int *)(param_1 + 8) != 0) {
          do {
            lVar8 = (ulonglong)*(uint *)(param_1 + 0xc) + uVar11 * 0x30;
            iVar1 = *(int *)(param_1 + lVar8 + 0x24);
            if (iVar1 == 1) {
              uVar6 = 0;
            }
            else if (iVar1 == 2) {
              uVar6 = 1;
            }
            else {
              if (iVar1 != 3) goto LAB_14000519f;
              uVar6 = 2;
            }
            uVar10 = (int)uVar11 + 1;
            *(undefined4 *)(*(longlong *)(this + 0x20) + uVar11 * 0xc) = uVar6;
            lVar3 = *(longlong *)(this + 0x20);
            *(undefined4 *)(lVar3 + 4 + uVar11 * 0xc) = *(undefined4 *)(param_1 + lVar8 + 1);
            *(undefined2 *)(lVar3 + 8 + uVar11 * 0xc) = *(undefined2 *)(param_1 + lVar8 + 5);
            uVar2 = *(uint *)(param_1 + 8);
            uVar11 = (ulonglong)uVar10;
          } while (uVar10 < uVar2);
        }
        *(ulonglong *)(this + 0x10) = (ulonglong)uVar2;
        ExReleasePushLockExclusiveEx(this,0);
        KeLeaveCriticalRegion();
        this_00 = ll_global::get_instance();
        ll_notification_bus::notify_source_updated
                  ((ll_notification_bus *)this_00,(ll_notification_source *)(this + 0x28));
        return 0;
      }
    }
  }
  return -0x3ffffff3;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l37::<lambda_12>_> @ 1400051c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l37::<lambda_12>_>
               (undefined8 *param_1,ll_vmswitch_oids *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  _NDIS_RECEIVE_FILTER_PARAMETERS *p_Var6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar9 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = EtwActivityIdControl(3,&local_38);
  puVar10 = auStack_68;
  if (iVar8 != 0) {
    uVar9 = 0x38;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar10 = auStack_60;
  }
  plVar1 = param_1 + 1;
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x14000524a;
    McTemplateK0xd_EtwWriteTransfer
              (uVar9,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  p_Var6 = *(_NDIS_RECEIVE_FILTER_PARAMETERS **)(*plVar3 + 0x28);
  *(undefined8 *)(puVar10 + -8) = 0x14000525e;
  iVar8 = ll_vmswitch_oids::on_oid_create_receive_filter
                    (param_2,p_Var6,(ll_etw_activity *)(puVar10 + 0x30));
  if (((iVar8 != 0) && (iVar8 != 0x103)) &&
     ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0)) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005297;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&fail_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x1400052c3;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&end_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  **(int **)param_1[2] = iVar8;
  *(undefined8 *)(puVar10 + -8) = 0x1400052d9;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l40::<lambda_13>_> @ 1400052f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l40::<lambda_13>_>
               (undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  ll_vf *this;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar8 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar7 = EtwActivityIdControl(3,&local_38);
  puVar9 = auStack_68;
  uVar10 = 0;
  if (iVar7 != 0) {
    uVar8 = 0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar9 = auStack_60;
  }
  plVar3 = (longlong *)*param_1;
  uVar1 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    *(undefined4 *)(puVar9 + 0x20) = uVar1;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar9 + -8) = 0x14000537a;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar9 + 0x30,uVar5,puVar9[0x20]);
  }
  uVar2 = *(uint *)(param_2 + 0xb78);
  this = *(ll_vf **)(*plVar3 + 0x28);
  if (((uVar2 == 0) || (*(int *)(this + 0xc) != *(int *)(param_2 + 0xb8c))) || (param_2 == -0xb80))
  {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar4 = *(longlong *)(param_2 + 3000);
      *(undefined4 *)(puVar9 + 0x28) = *(undefined4 *)(this + 0xc);
      puVar9[0x20] = 3;
      uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
      *(undefined8 *)(puVar9 + -8) = 0x1400053cf;
      McTemplateK0xud_EtwWriteTransfer
                (this,(ulonglong)uVar2,puVar9 + 0x30,uVar8,puVar9[0x20],puVar9[0x28]);
    }
    uVar10 = 0xc001001b;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar4 = param_1[1];
      *(undefined4 *)(puVar9 + 0x28) = 0xc001001b;
      *(undefined4 *)(puVar9 + 0x20) = uVar1;
      uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
      *(undefined8 *)(puVar9 + -8) = 0x140005401;
      McTemplateK0xqd_EtwWriteTransfer
                (this,&fail_handle_oid_request,puVar9 + 0x30,uVar8,puVar9[0x20],puVar9[0x28]);
    }
  }
  else {
    *(uint *)(param_2 + 0xb78) = uVar2 - 1;
    *(undefined8 *)(puVar9 + -8) = 0x14000541a;
    ExReleaseRundownProtection(param_2 + 0xbb0);
    this = *(ll_vf **)(param_2 + 3000);
    *(undefined8 *)(puVar9 + -8) = 0x14000542d;
    ll_vf::set_datapath_up(this,false);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    *(undefined4 *)(puVar9 + 0x28) = uVar10;
    *(undefined4 *)(puVar9 + 0x20) = uVar1;
    uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar9 + -8) = 0x14000545a;
    McTemplateK0xqd_EtwWriteTransfer
              (this,&end_handle_oid_request,puVar9 + 0x30,uVar8,puVar9[0x20],puVar9[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar10;
  *(undefined8 *)(puVar9 + -8) = 0x140005470;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l43::<lambda_14>_> @ 14000548c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l43::<lambda_14>_>
               (undefined8 *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  int *piVar8;
  ll_vf *this;
  int *piVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  int local_38 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  piVar9 = local_38;
  this = (ll_vf *)&DAT_00000003;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  iVar7 = EtwActivityIdControl();
  puVar10 = auStack_68;
  uVar11 = 0;
  if (iVar7 != 0) {
    this = (ll_vf *)0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar10 = auStack_60;
  }
  plVar3 = (longlong *)*param_1;
  uVar1 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    piVar9 = (int *)&begin_handle_oid_request;
    *(undefined4 *)(puVar10 + 0x20) = uVar1;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x14000550e;
    McTemplateK0xd_EtwWriteTransfer
              (this,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  lVar4 = *(longlong *)(*plVar3 + 0x28);
  if (((param_2[0x2de] == 0) || (*(int *)(lVar4 + 4) != param_2[0x2e3])) ||
     (param_2 == (int *)0xfffffffffffff480)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      *(undefined4 *)(puVar10 + 0x28) = *(undefined4 *)(lVar4 + 4);
      puVar10[0x20] = 3;
LAB_14000554e:
      uVar5 = *(undefined8 *)(*(longlong *)(param_2 + 0x2ee) + 0xdf8);
      *(undefined8 *)(puVar10 + -8) = 0x140005566;
      McTemplateK0xud_EtwWriteTransfer(this,piVar9,puVar10 + 0x30,uVar5,puVar10[0x20],puVar10[0x28])
      ;
    }
LAB_140005566:
    uVar11 = 0xc001001b;
  }
  else {
    uVar2 = *(uint *)(lVar4 + 0xc);
    this = (ll_vf *)(ulonglong)uVar2;
    piVar9 = (int *)0x0;
    if ((uVar2 != 0) &&
       (((*param_2 == 0 || (param_2[0x220] == 0)) ||
        ((uVar2 != param_2[0x225] || (piVar9 = param_2 + 0x222, piVar9 == (int *)0x0)))))) {
LAB_14000559b:
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
        *(int *)(puVar10 + 0x28) = (int)this;
        puVar10[0x20] = 2;
        goto LAB_14000554e;
      }
      goto LAB_140005566;
    }
    uVar2 = *(uint *)(lVar4 + 0x14);
    this = (ll_vf *)(ulonglong)uVar2;
    piVar8 = (int *)0x0;
    if ((uVar2 != 0) &&
       (((*param_2 == 0 || (param_2[0x220] == 0)) ||
        ((uVar2 != param_2[0x225] || (piVar8 = param_2 + 0x222, param_2 + 0x222 == (int *)0x0))))))
    goto LAB_14000559b;
    if (piVar9 == *(int **)(param_2 + 0x2e6)) {
      *(int **)(param_2 + 0x2e6) = piVar8;
      iVar7 = *(int *)(lVar4 + 0x14);
      this = *(ll_vf **)(param_2 + 0x2ee);
      *(undefined8 *)(puVar10 + -8) = 0x14000562e;
      ll_vf::set_datapath_up(this,iVar7 != 0);
      goto LAB_14000562e;
    }
    uVar11 = 0xc000000d;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
    lVar4 = param_1[1];
    *(undefined4 *)(puVar10 + 0x28) = uVar11;
    *(undefined4 *)(puVar10 + 0x20) = uVar1;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005615;
    McTemplateK0xqd_EtwWriteTransfer
              (this,&fail_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20],puVar10[0x28]);
  }
LAB_14000562e:
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    *(undefined4 *)(puVar10 + 0x28) = uVar11;
    *(undefined4 *)(puVar10 + 0x20) = uVar1;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x14000565b;
    McTemplateK0xqd_EtwWriteTransfer
              (this,&end_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20],puVar10[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar11;
  *(undefined8 *)(puVar10 + -8) = 0x140005671;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l46::<lambda_15>_> @ 140005690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l46::<lambda_15>_>
               (undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [40];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  uVar8 = 3;
  local_48 = 0;
  uStack_40 = 0;
  iVar7 = EtwActivityIdControl(3,&local_48);
  puVar11 = auStack_78;
  if (iVar7 != 0) {
    uVar8 = 0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar11 = auStack_70;
  }
  plVar2 = (longlong *)*param_1;
  uVar1 = *(undefined4 *)(*plVar2 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar10 = param_1[1];
    *(undefined4 *)(puVar11 + 0x20) = uVar1;
    uVar3 = *(undefined8 *)(lVar10 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x140005716;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar11 + 0x30,uVar3,puVar11[0x20]);
  }
  lVar4 = *plVar2;
  lVar10 = param_2 + 0xdf0;
  puVar5 = *(undefined4 **)(lVar4 + 0x28);
  *(undefined8 *)(puVar11 + -8) = 0x14000572b;
  KeEnterCriticalRegion();
  *(undefined8 *)(puVar11 + -8) = 0x14000573c;
  lVar9 = lVar10;
  ExAcquirePushLockSharedEx(lVar10,0);
  *puVar5 = 0xc0180;
  if (*(char *)(param_2 + 0xda2) == '\0') {
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_2 + 0xda4);
  }
  *(undefined8 *)(puVar5 + 1) = uVar8;
  if (lVar10 != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x140005771;
    ExReleasePushLockSharedEx(lVar10,0);
    *(undefined8 *)(puVar11 + -8) = 0x14000577d;
    KeLeaveCriticalRegion();
    lVar9 = lVar10;
  }
  *(undefined4 *)(lVar4 + 0x34) = 0xc;
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    *(undefined4 *)(puVar11 + 0x28) = 0;
    lVar10 = param_1[1];
    *(undefined4 *)(puVar11 + 0x20) = uVar1;
    uVar8 = *(undefined8 *)(lVar10 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x1400057b8;
    McTemplateK0xqd_EtwWriteTransfer
              (lVar9,&end_handle_oid_request,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
  }
  **(undefined4 **)param_1[2] = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1400057cf;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l7::<lambda_2>_> @ 1400057f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l7::<lambda_2>_>
               (undefined8 *param_1,ll_vmswitch_oids *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  _NDIS_NIC_SWITCH_PARAMETERS *p_Var6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar9 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = EtwActivityIdControl(3,&local_38);
  puVar10 = auStack_68;
  if (iVar8 != 0) {
    uVar9 = 0x38;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar10 = auStack_60;
  }
  plVar1 = param_1 + 1;
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005876;
    McTemplateK0xd_EtwWriteTransfer
              (uVar9,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  p_Var6 = *(_NDIS_NIC_SWITCH_PARAMETERS **)(*plVar3 + 0x28);
  *(undefined8 *)(puVar10 + -8) = 0x14000588a;
  iVar8 = ll_vmswitch_oids::on_oid_create_switch(param_2,p_Var6,(ll_etw_activity *)(puVar10 + 0x30))
  ;
  if (((iVar8 != 0) && (iVar8 != 0x103)) &&
     ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0)) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x1400058c3;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&fail_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x1400058ef;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&end_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  **(int **)param_1[2] = iVar8;
  *(undefined8 *)(puVar10 + -8) = 0x140005905;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l10::<lambda_3>_> @ 140005924 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l10::<lambda_3>_>
               (undefined8 *param_1,uint *param_2)

{
  undefined4 uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  uint *puVar7;
  undefined8 uVar8;
  uint *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined8 uStack_70;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 auStack_48 [2];
  undefined4 local_40 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar8 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar6 = EtwActivityIdControl(3,&local_38);
  puVar11 = auStack_68;
  uVar12 = 0;
  if (iVar6 != 0) {
    uVar8 = 0x38;
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)();
    puVar11 = auStack_60;
  }
  plVar2 = (longlong *)*param_1;
  uVar1 = *(undefined4 *)(*plVar2 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar3 = param_1[1];
    *(undefined4 *)(puVar11 + 0x20) = uVar1;
    uVar4 = *(undefined8 *)(lVar3 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x1400059a6;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar11 + 0x30,uVar4,puVar11[0x20]);
  }
  uVar10 = *param_2;
  puVar9 = *(uint **)(*plVar2 + 0x28);
  if (((uVar10 == 0) || (puVar9[2] != param_2[3])) || (puVar7 = param_2 + 2, puVar7 == (uint *)0x0))
  {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar3 = *(longlong *)(param_2 + 0x2ee);
      *(uint *)(puVar11 + 0x28) = puVar9[2];
      puVar11[0x20] = 0;
      uVar8 = *(undefined8 *)(lVar3 + 0xdf8);
      *(undefined8 *)(puVar11 + -8) = 0x1400059f1;
      McTemplateK0xud_EtwWriteTransfer
                (puVar9,(ulonglong)uVar10,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
    }
    uVar12 = 0xc001001b;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar3 = param_1[1];
      *(undefined4 *)(puVar11 + 0x28) = 0xc001001b;
      *(undefined4 *)(puVar11 + 0x20) = uVar1;
      uVar8 = *(undefined8 *)(lVar3 + 0xdf8);
      *(undefined8 *)(puVar11 + -8) = 0x140005a23;
      McTemplateK0xqd_EtwWriteTransfer
                (puVar9,&fail_handle_oid_request,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
    }
  }
  else {
    if (param_2[0x87] != 0) {
      pcVar5 = (code *)swi(0x2c);
      puVar7 = (uint *)(*pcVar5)();
      puVar11 = puVar11 + 8;
    }
    if (puVar7[0x21e] != 0) {
      pcVar5 = (code *)swi(0x2c);
      (*pcVar5)();
      puVar11 = puVar11 + 8;
    }
    puVar9 = param_2 + 0x2ec;
    *param_2 = uVar10 - 1;
    *(undefined8 *)(puVar11 + -8) = 0x140005a4c;
    ExReleaseRundownProtection();
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar3 = param_1[1];
    *(undefined4 *)(puVar11 + 0x28) = uVar12;
    *(undefined4 *)(puVar11 + 0x20) = uVar1;
    uVar8 = *(undefined8 *)(lVar3 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x140005a7e;
    McTemplateK0xqd_EtwWriteTransfer
              (puVar9,&end_handle_oid_request,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar12;
  *(undefined8 *)(puVar11 + -8) = 0x140005a94;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l13::<lambda_4>_> @ 140005ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l13::<lambda_4>_>
               (undefined8 *param_1,int *param_2)

{
  undefined4 uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar8 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar7 = EtwActivityIdControl(3,&local_38);
  puVar9 = auStack_68;
  uVar10 = 0;
  if (iVar7 != 0) {
    uVar8 = 0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar9 = auStack_60;
  }
  plVar2 = (longlong *)*param_1;
  uVar1 = *(undefined4 *)(*plVar2 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar3 = param_1[1];
    *(undefined4 *)(puVar9 + 0x20) = uVar1;
    uVar4 = *(undefined8 *)(lVar3 + 0xdf8);
    *(undefined8 *)(puVar9 + -8) = 0x140005b32;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar9 + 0x30,uVar4,puVar9[0x20]);
  }
  lVar3 = *(longlong *)(*plVar2 + 0x28);
  if (((*param_2 == 0) || (*(int *)(lVar3 + 0xc) != param_2[3])) ||
     (param_2 == (int *)0xfffffffffffffff8)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar5 = *(longlong *)(param_2 + 0x2ee);
      *(undefined4 *)(puVar9 + 0x28) = *(undefined4 *)(lVar3 + 0xc);
      puVar9[0x20] = 0;
      uVar4 = *(undefined8 *)(lVar5 + 0xdf8);
      *(undefined8 *)(puVar9 + -8) = 0x140005b7b;
      McTemplateK0xud_EtwWriteTransfer(uVar8,lVar3,puVar9 + 0x30,uVar4,puVar9[0x20],puVar9[0x28]);
    }
    uVar10 = 0xc001001b;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar3 = param_1[1];
      *(undefined4 *)(puVar9 + 0x28) = 0xc001001b;
      *(undefined4 *)(puVar9 + 0x20) = uVar1;
      uVar4 = *(undefined8 *)(lVar3 + 0xdf8);
      *(undefined8 *)(puVar9 + -8) = 0x140005bad;
      McTemplateK0xqd_EtwWriteTransfer
                (uVar8,&fail_handle_oid_request,puVar9 + 0x30,uVar4,puVar9[0x20],puVar9[0x28]);
    }
  }
  else if ((*(uint *)(lVar3 + 4) & 0x20000) != 0) {
    param_2[0x86] = *(int *)(lVar3 + 0x214);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar3 = param_1[1];
    *(undefined4 *)(puVar9 + 0x28) = uVar10;
    *(undefined4 *)(puVar9 + 0x20) = uVar1;
    uVar4 = *(undefined8 *)(lVar3 + 0xdf8);
    *(undefined8 *)(puVar9 + -8) = 0x140005bf2;
    McTemplateK0xqd_EtwWriteTransfer
              (uVar8,&end_handle_oid_request,puVar9 + 0x30,uVar4,puVar9[0x20],puVar9[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar10;
  *(undefined8 *)(puVar9 + -8) = 0x140005c08;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l16::<lambda_5>_> @ 140005c24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l16::<lambda_5>_>
               (undefined8 *param_1,ll_vmswitch_oids *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  _NDIS_NIC_SWITCH_VPORT_PARAMETERS *p_Var6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar9 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = EtwActivityIdControl(3,&local_38);
  puVar10 = auStack_68;
  if (iVar8 != 0) {
    uVar9 = 0x38;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar10 = auStack_60;
  }
  plVar1 = param_1 + 1;
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005caa;
    McTemplateK0xd_EtwWriteTransfer
              (uVar9,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  p_Var6 = *(_NDIS_NIC_SWITCH_VPORT_PARAMETERS **)(*plVar3 + 0x28);
  *(undefined8 *)(puVar10 + -8) = 0x140005cbe;
  iVar8 = ll_vmswitch_oids::on_oid_create_vport(param_2,p_Var6,(ll_etw_activity *)(puVar10 + 0x30));
  if (((iVar8 != 0) && (iVar8 != 0x103)) &&
     ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0)) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005cf7;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&fail_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005d23;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&end_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  **(int **)param_1[2] = iVar8;
  *(undefined8 *)(puVar10 + -8) = 0x140005d39;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l19::<lambda_6>_> @ 140005d58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l19::<lambda_6>_>
               (undefined8 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  puVar10 = &local_38;
  uVar8 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar7 = EtwActivityIdControl();
  puVar11 = auStack_68;
  uVar12 = 0;
  if (iVar7 != 0) {
    uVar8 = 0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar11 = auStack_60;
  }
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar9 = param_1[1];
    puVar10 = (undefined8 *)&begin_handle_oid_request;
    *(undefined4 *)(puVar11 + 0x20) = uVar2;
    uVar4 = *(undefined8 *)(lVar9 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x140005dda;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar11 + 0x30,uVar4,puVar11[0x20]);
  }
  lVar9 = *(longlong *)(*plVar3 + 0x28);
  if ((((*param_2 == 0) || (param_2[0x220] == 0)) || (*(int *)(lVar9 + 8) != param_2[0x225])) ||
     ((longlong *)(param_2 + 0x222) == (longlong *)0x0)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar5 = *(longlong *)(param_2 + 0x2ee);
      *(undefined4 *)(puVar11 + 0x28) = *(undefined4 *)(lVar9 + 8);
      puVar11[0x20] = 2;
      uVar8 = *(undefined8 *)(lVar5 + 0xdf8);
      *(undefined8 *)(puVar11 + -8) = 0x140005e3c;
      McTemplateK0xud_EtwWriteTransfer
                (lVar9,puVar10,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
    }
    uVar12 = 0xc001001b;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar5 = param_1[1];
      *(undefined4 *)(puVar11 + 0x28) = 0xc001001b;
      *(undefined4 *)(puVar11 + 0x20) = uVar2;
      uVar8 = *(undefined8 *)(lVar5 + 0xdf8);
      *(undefined8 *)(puVar11 + -8) = 0x140005e70;
      McTemplateK0xqd_EtwWriteTransfer
                (lVar9,&fail_handle_oid_request,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
    }
  }
  else {
    piVar1 = (int *)(*(longlong *)(param_2 + 0x222) + 0x878);
    *piVar1 = *piVar1 + -1;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar5 = param_1[1];
    *(undefined4 *)(puVar11 + 0x28) = uVar12;
    *(undefined4 *)(puVar11 + 0x20) = uVar2;
    uVar8 = *(undefined8 *)(lVar5 + 0xdf8);
    *(undefined8 *)(puVar11 + -8) = 0x140005e9d;
    McTemplateK0xqd_EtwWriteTransfer
              (lVar9,&end_handle_oid_request,puVar11 + 0x30,uVar8,puVar11[0x20],puVar11[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar12;
  *(undefined8 *)(puVar11 + -8) = 0x140005eb3;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l25::<lambda_8>_> @ 140005ed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l25::<lambda_8>_>
               (undefined8 *param_1,ll_vmswitch_oids *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  _NDIS_NIC_SWITCH_VF_PARAMETERS *p_Var6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uVar9 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar8 = EtwActivityIdControl(3,&local_38);
  puVar10 = auStack_68;
  if (iVar8 != 0) {
    uVar9 = 0x38;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar10 = auStack_60;
  }
  plVar1 = param_1 + 1;
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005f56;
    McTemplateK0xd_EtwWriteTransfer
              (uVar9,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  p_Var6 = *(_NDIS_NIC_SWITCH_VF_PARAMETERS **)(*plVar3 + 0x28);
  *(undefined8 *)(puVar10 + -8) = 0x140005f6a;
  iVar8 = ll_vmswitch_oids::on_oid_create_vf(param_2,p_Var6,(ll_etw_activity *)(puVar10 + 0x30));
  if (((iVar8 != 0) && (iVar8 != 0x103)) &&
     ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0)) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005fa3;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&fail_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = *plVar1;
    *(int *)(puVar10 + 0x28) = iVar8;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar9 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140005fcf;
    McTemplateK0xqd_EtwWriteTransfer
              (param_2,&end_handle_oid_request,puVar10 + 0x30,uVar9,puVar10[0x20],puVar10[0x28]);
  }
  **(int **)param_1[2] = iVar8;
  *(undefined8 *)(puVar10 + -8) = 0x140005fe5;
  return;
}



===== operator()<`ll_vf::issue_oid_request_inbound'::__l28::<lambda_9>_> @ 140006004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
     operator()<_ll_vf::issue_oid_request_inbound_::__l28::<lambda_9>_>
               (undefined8 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  StateMachineEngine *this;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  puVar9 = &local_38;
  uVar8 = 3;
  local_38 = 0;
  uStack_30 = 0;
  iVar7 = EtwActivityIdControl();
  puVar10 = auStack_68;
  uVar11 = 0;
  if (iVar7 != 0) {
    uVar8 = 0x38;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)();
    puVar10 = auStack_60;
  }
  plVar3 = (longlong *)*param_1;
  uVar2 = *(undefined4 *)(*plVar3 + 0x20);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    puVar9 = (undefined8 *)&begin_handle_oid_request;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar5 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140006086;
    McTemplateK0xd_EtwWriteTransfer
              (uVar8,&begin_handle_oid_request,puVar10 + 0x30,uVar5,puVar10[0x20]);
  }
  this = *(StateMachineEngine **)(*plVar3 + 0x28);
  if ((((*param_2 == 0) || (param_2[0x87] == 0)) ||
      (*(short *)(this + 8) != *(short *)((longlong)param_2 + 0x87a))) ||
     ((longlong *)(param_2 + 0x88) == (longlong *)0x0)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar4 = *(longlong *)(param_2 + 0x2ee);
      *(uint *)(puVar10 + 0x28) = (uint)*(ushort *)(this + 8);
      puVar10[0x20] = 1;
      uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
      *(undefined8 *)(puVar10 + -8) = 0x140006103;
      McTemplateK0xud_EtwWriteTransfer(this,puVar9,puVar10 + 0x30,uVar8,puVar10[0x20],puVar10[0x28])
      ;
    }
    uVar11 = 0xc001001b;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      lVar4 = param_1[1];
      *(undefined4 *)(puVar10 + 0x28) = 0xc001001b;
      *(undefined4 *)(puVar10 + 0x20) = uVar2;
      uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
      *(undefined8 *)(puVar10 + -8) = 0x140006137;
      McTemplateK0xqd_EtwWriteTransfer
                (this,&fail_handle_oid_request,puVar10 + 0x30,uVar8,puVar10[0x20],puVar10[0x28]);
    }
  }
  else {
    piVar1 = (int *)(*(longlong *)(param_2 + 0x88) + 0x214);
    *piVar1 = *piVar1 + -1;
    this = (StateMachineEngine *)(*(longlong *)(param_2 + 0x2ee) + 0xc10);
    *(undefined8 *)(puVar10 + -8) = 0x1400060d3;
    SmFx::StateMachineEngine::EnqueueEvent(this,10);
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    lVar4 = param_1[1];
    *(undefined4 *)(puVar10 + 0x28) = uVar11;
    *(undefined4 *)(puVar10 + 0x20) = uVar2;
    uVar8 = *(undefined8 *)(lVar4 + 0xdf8);
    *(undefined8 *)(puVar10 + -8) = 0x140006164;
    McTemplateK0xqd_EtwWriteTransfer
              (this,&end_handle_oid_request,puVar10 + 0x30,uVar8,puVar10[0x20],puVar10[0x28]);
  }
  **(undefined4 **)param_1[2] = uVar11;
  *(undefined8 *)(puVar10 + -8) = 0x14000617a;
  return;
}



===== enumerate_all_vfs @ 140006198 =====

/* public: static void __cdecl ll_vf::enumerate_all_vfs(struct NNVDRV_QUERY_ACTIVE_VFS_OUT *
   __ptr64,unsigned __int64,unsigned __int64 * __ptr64) */

void __cdecl
ll_vf::enumerate_all_vfs(NNVDRV_QUERY_ACTIVE_VFS_OUT *param_1,__uint64 param_2,__uint64 *param_3)

{
  undefined **ppuVar1;
  ulonglong uVar2;
  NNVDRV_QUERY_ACTIVE_VFS_OUT *pNVar3;
  longlong lVar4;
  
  *param_3 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&DAT_140013710,0);
  lVar4 = 0;
  for (ppuVar1 = (undefined **)PTR_LOOP_1400133b0; ppuVar1 != &PTR_LOOP_1400133b0;
      ppuVar1 = (undefined **)*ppuVar1) {
    lVar4 = lVar4 + 1;
  }
  *(int *)param_1 = (int)lVar4;
  uVar2 = lVar4 * 0x30 + 8;
  *param_3 = uVar2;
  if ((uVar2 <= param_2) && (lVar4 != 0)) {
    *(undefined4 *)(param_1 + 4) = 8;
    pNVar3 = param_1 + 8;
    for (ppuVar1 = (undefined **)PTR_LOOP_1400133b0; ppuVar1 != &PTR_LOOP_1400133b0;
        ppuVar1 = (undefined **)*ppuVar1) {
      *(undefined2 *)pNVar3 = 6;
      ll_device_link::get_mac_address((ll_device_link *)(ppuVar1 + -0xe),(uchar *)(pNVar3 + 2));
      pNVar3 = pNVar3 + 0x30;
    }
  }
  ExReleasePushLockSharedEx(&DAT_140013710,0);
  KeLeaveCriticalRegion();
  return;
}



===== initialize @ 140006284 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl ll_vf::initialize(void * __ptr64,unsigned __int64) __ptr64 */

long __thiscall ll_vf::initialize(ll_vf *this,void *param_1,__uint64 param_2)

{
  long lVar1;
  STATE_MACHINE_SPECIFICATION *local_58;
  StateMachineEngine *local_50;
  undefined8 local_48;
  undefined8 local_40;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
  *(__uint64 *)(this + 0xdf8) = param_2;
  *(void **)(this + 0xe00) = param_1;
  local_40 = 0x21766e6e;
  local_16 = 0;
  local_12 = 0;
  local_58 = &ll_vmswitch_StateMachine<ll_vmswitch_indications>::c_specification;
  local_50 = (StateMachineEngine *)(this + 0xbc0);
  local_48 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  local_18 = 0x101;
  local_38 = ll_device_StateMachine<ll_pnp_device>::EvtLogMachineExceptionThunk;
  local_30 = ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtLogEventEnqueueThunk;
  local_28 = ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtLogTransitionThunk;
  local_20 = ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtMachineDestroyedThunk;
  lVar1 = SmFx::StateMachineEngine::Initialize
                    ((StateMachineEngine *)(this + 0xbc0),(STATE_MACHINE_ENGINE_CONFIG *)&local_58);
  if ((lVar1 == 0) || (-1 < lVar1)) {
    ll_netvsc_state::initialize((ll_netvsc_state *)(this + 0xc10));
    lVar1 = 0;
  }
  return lVar1;
}



===== issue_oid_request_inbound @ 140006364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: enum ll_vf::propagation __cdecl ll_vf::issue_oid_request_inbound(struct _NDIS_OID_REQUEST
   * __ptr64,int * __ptr64) __ptr64 */

propagation __thiscall
ll_vf::issue_oid_request_inbound(ll_vf *this,_NDIS_OID_REQUEST *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  propagation pVar4;
  int iVar5;
  undefined8 uVar6;
  propagation pVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  bool bVar10;
  _NDIS_OID_REQUEST *local_res10 [2];
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  int *local_38;
  _NDIS_OID_REQUEST **local_30;
  ll_vf *plStack_28;
  int **local_20;
  ulonglong local_18;
  
  puVar9 = auStackY_68;
  puVar8 = auStackY_68;
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_30 = local_res10;
  *param_2 = -0x3ffeffe9;
  local_20 = &local_38;
  pVar4 = 1;
  uVar1 = *(uint *)(param_1 + 0x20);
  local_res10[0] = param_1;
  local_38 = param_2;
  plStack_28 = this;
  if (uVar1 < 0x10243) {
    if (uVar1 == 0x10242) {
LAB_1400064a3:
      bVar10 = *(int *)(param_1 + 4) == 1;
LAB_140006553:
      puVar9 = auStackY_68;
      if (!bVar10) goto LAB_1400065c5;
      pVar7 = (propagation)&local_30;
      uVar6 = 3;
      local_30 = (_NDIS_OID_REQUEST **)0x0;
      plStack_28 = (ll_vf *)0x0;
      iVar5 = EtwActivityIdControl();
      if (iVar5 == 0) {
        uVar2 = *(undefined4 *)(local_res10[0] + 0x20);
        if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
          McTemplateK0xd_EtwWriteTransfer
                    (uVar6,&begin_handle_oid_request,&local_30,*(undefined8 *)(this + 0xdf8),
                     (char)uVar2);
          if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
            McTemplateK0xqd_EtwWriteTransfer
                      (uVar6,&end_handle_oid_request,&local_30,*(undefined8 *)(this + 0xdf8),
                       (char)uVar2,0);
          }
        }
        *local_38 = 0;
      }
      else {
        param_1 = (_NDIS_OID_REQUEST *)0x38;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar9 = auStackY_60;
LAB_140006580:
        pVar4 = pVar7;
        puVar8 = puVar9;
        puVar9 = puVar8;
        if (*(propagation *)(param_1 + 4) != pVar4) goto LAB_1400065c5;
        *(undefined8 *)(puVar8 + -8) = 0x140006591;
        `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
        operator()<_ll_vf::issue_oid_request_inbound_::__l28::<lambda_9>_>(&local_30,(int *)this);
      }
    }
    else if (uVar1 == 0x10227) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 0xc) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l37::<lambda_12>_>
                (&local_30,(ll_vmswitch_oids *)this);
      puVar8 = auStackY_68;
    }
    else if (uVar1 == 0x10228) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 1) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l40::<lambda_13>_>(&local_30,(longlong)this);
      puVar8 = auStackY_68;
    }
    else if (uVar1 == 0x10230) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 1) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l43::<lambda_14>_>(&local_30,(int *)this);
      puVar8 = auStackY_68;
    }
    else if (uVar1 == 0x10237) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 0xc) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l7::<lambda_2>_>
                (&local_30,(ll_vmswitch_oids *)this);
      puVar8 = auStackY_68;
    }
    else if (uVar1 == 0x10238) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 1) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l13::<lambda_4>_>(&local_30,(int *)this);
      puVar8 = auStackY_68;
    }
    else if (uVar1 == 0x10239) {
      puVar9 = auStackY_68;
      if (*(int *)(param_1 + 4) != 1) goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l10::<lambda_3>_>(&local_30,(uint *)this);
      puVar8 = auStackY_68;
    }
    else {
      puVar9 = auStackY_68;
      if ((uVar1 != 0x10241) || (puVar9 = auStackY_68, *(int *)(param_1 + 4) != 0xc))
      goto LAB_1400065c5;
      `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
      operator()<_ll_vf::issue_oid_request_inbound_::__l16::<lambda_5>_>
                (&local_30,(ll_vmswitch_oids *)this);
      puVar8 = auStackY_68;
    }
  }
  else if (uVar1 == 0x10244) {
    if (*(int *)(param_1 + 4) != 1) goto LAB_1400065c5;
    `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
    operator()<_ll_vf::issue_oid_request_inbound_::__l19::<lambda_6>_>(&local_30,(int *)this);
    puVar8 = auStackY_68;
  }
  else if (uVar1 == 0x10245) {
    puVar9 = auStackY_68;
    if (*(int *)(param_1 + 4) != 0xc) goto LAB_1400065c5;
    `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
    operator()<_ll_vf::issue_oid_request_inbound_::__l25::<lambda_8>_>
              (&local_30,(ll_vmswitch_oids *)this);
    puVar8 = auStackY_68;
  }
  else {
    puVar9 = auStackY_68;
    pVar7 = 1;
    if (uVar1 == 0x10246) goto LAB_140006580;
    if (uVar1 == 0x10247) {
      bVar10 = *(int *)(param_1 + 4) == 0xc;
      goto LAB_140006553;
    }
    if (uVar1 == 0x10255) goto LAB_1400064a3;
    puVar9 = auStackY_68;
    if ((uVar1 != 0x10260) || (puVar9 = auStackY_68, *(int *)(param_1 + 4) != 0))
    goto LAB_1400065c5;
    `ll_vf::issue_oid_request_inbound'::__l2::<lambda_1>::
    operator()<_ll_vf::issue_oid_request_inbound_::__l46::<lambda_15>_>(&local_30,(longlong)this);
    puVar8 = auStackY_68;
  }
  pVar4 = 0;
  puVar9 = puVar8;
LAB_1400065c5:
  *(undefined8 *)(puVar9 + -8) = 0x1400065d1;
  return pVar4;
}



===== query_vf_state @ 1400065ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static void __cdecl ll_vf::query_vf_state(unsigned char const * __ptr64,struct
   NNVDRV_QUERY_VF_STATE_OUT * __ptr64) */

void __cdecl ll_vf::query_vf_state(uchar *param_1,NNVDRV_QUERY_VF_STATE_OUT *param_2)

{
  ll_device_link *this;
  undefined **ppuVar1;
  NNVDRV_QUERY_VF_STATE_OUT NVar2;
  NNVDRV_QUERY_VF_STATE_OUT NVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  int local_28;
  short local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&DAT_140013710,0);
  ppuVar4 = (undefined **)PTR_LOOP_1400133b0;
  do {
    if (ppuVar4 == &PTR_LOOP_1400133b0) {
LAB_1400067d8:
      ExReleasePushLockSharedEx(&DAT_140013710,0);
      KeLeaveCriticalRegion();
      return;
    }
    this = (ll_device_link *)(ppuVar4 + -0xe);
    local_28 = 0;
    local_24 = 0;
    ll_device_link::get_mac_address(this,(uchar *)&local_28);
    if ((*(int *)param_1 == local_28) && (*(short *)(param_1 + 4) == local_24)) {
      NVar3 = (NNVDRV_QUERY_VF_STATE_OUT)0x1;
      ppuVar1 = ppuVar4 + -3;
      param_2[4] = (NNVDRV_QUERY_VF_STATE_OUT)0x1;
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(ppuVar1,0);
      if (*(int *)this != 0) {
        param_2[0xb] = (NNVDRV_QUERY_VF_STATE_OUT)0x1;
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)this;
      }
      if (*(char *)((longlong)ppuVar4 + -0x66) != '\0') {
        param_2[0x10] = (NNVDRV_QUERY_VF_STATE_OUT)0x1;
        *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)((longlong)ppuVar4 + -100);
      }
      if (ppuVar4[-6] != (undefined *)0x0) {
        wcscpy_s((wchar_t *)(param_2 + 0x30),0x100,*(wchar_t **)(ppuVar4[-6] + 0x60));
      }
      if (ppuVar1 != (undefined **)0x0) {
        ExReleasePushLockSharedEx(ppuVar1,0);
        KeLeaveCriticalRegion();
      }
      ppuVar1 = ppuVar4 + -0xf;
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(ppuVar1,0);
      if (*(char *)(ppuVar4 + -0x10) == '\0') {
        param_2[5] = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xd4);
        param_2[6] = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xd3);
        NVar2 = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xb4);
      }
      else {
        param_2[5] = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xbc);
        param_2[6] = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xbb);
        NVar2 = *(NNVDRV_QUERY_VF_STATE_OUT *)((longlong)ppuVar4 + -0xa6);
      }
      param_2[7] = NVar2;
      if (ppuVar1 != (undefined **)0x0) {
        ExReleasePushLockSharedEx(ppuVar1,0);
        KeLeaveCriticalRegion();
      }
      param_2[8] = (NNVDRV_QUERY_VF_STATE_OUT)(*(int *)(ppuVar4 + -0x1c1) != 0);
      if ((*(int *)(ppuVar4 + -0x1c1) == 0) || (*(int *)((longlong)ppuVar4 + -0xbec) == 0)) {
        NVar2 = (NNVDRV_QUERY_VF_STATE_OUT)0x0;
      }
      else {
        NVar2 = (NNVDRV_QUERY_VF_STATE_OUT)0x1;
      }
      param_2[9] = NVar2;
      if ((*(int *)(ppuVar4 + -0x52) == 0) || (ppuVar4[-0x4e] == (undefined *)0x0)) {
        NVar3 = (NNVDRV_QUERY_VF_STATE_OUT)0x0;
      }
      param_2[10] = NVar3;
      goto LAB_1400067d8;
    }
    ppuVar4 = (undefined **)*ppuVar4;
  } while( true );
}



===== set_datapath_up @ 140006820 =====

/* public: void __cdecl ll_vf::set_datapath_up(bool) __ptr64 */

void __thiscall ll_vf::set_datapath_up(ll_vf *this,bool param_1)

{
  ll_vf *plVar1;
  
  plVar1 = this + 0xd90;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  this[0xc20] = (ll_vf)param_1;
  if (plVar1 != (ll_vf *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0xc10),1);
  return;
}



===== set_mac_address @ 1400068a8 =====

/* public: void __cdecl ll_vf::set_mac_address(unsigned char const * __ptr64) __ptr64 */

void __thiscall ll_vf::set_mac_address(ll_vf *this,uchar *param_1)

{
  ll_vf *plVar1;
  ll_vf *plVar2;
  ll_vf_role lVar3;
  ll_global *plVar4;
  undefined8 in_R8;
  undefined8 uVar5;
  
  if (g_L1VHAddCriticalLoggingEnabled) {
    uVar5 = 0;
    if (*(longlong *)(this + 0xde8) != 0) {
      uVar5 = *(undefined8 *)(*(longlong *)(this + 0xde8) + 0xdf8);
    }
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0xb6b6_EtwWriteTransfer(this,param_1,in_R8,uVar5,this + 0xd9c,param_1);
    }
  }
  plVar1 = this + 0xdf0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  plVar2 = this + 0xd9c;
  if ((*(int *)plVar2 != *(int *)param_1) || (*(short *)(this + 0xda0) != *(short *)(param_1 + 4)))
  {
    *(int *)plVar2 = *(int *)param_1;
    *(undefined2 *)(this + 0xda0) = *(undefined2 *)(param_1 + 4);
    plVar4 = ll_global::get_instance();
    lVar3 = ll_policy_table::get_role_for_mac_address
                      ((ll_policy_table *)(plVar4 + 0x60),(uchar *)plVar2);
    *(ll_vf_role *)(this + 0xde4) = lVar3;
    ll_device_link::apply_policy_to_device((ll_device_link *)(this + 0xd98));
    ll_device_link::reevaluate_advertised_vf_state((ll_device_link *)(this + 0xd98));
  }
  if (plVar1 != (ll_vf *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== set_serial_number @ 1400069a8 =====

/* public: void __cdecl ll_vf::set_serial_number(unsigned long) __ptr64 */

void __thiscall ll_vf::set_serial_number(ll_vf *this,ulong param_1)

{
  ll_vf *plVar1;
  ll_device_link *this_00;
  ll_global *this_01;
  
  this_00 = (ll_device_link *)(this + 0xd98);
  plVar1 = this + 0xdf0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1);
  if (*(ulong *)this_00 != param_1) {
    *(ulong *)this_00 = param_1;
    ll_device_link::set_linked_device(this_00,(ll_pnp_device *)0x0);
    if (param_1 != 0) {
      this_01 = ll_global::get_instance();
      ll_notification_bus::request_reeunumeration
                ((ll_notification_bus *)this_01,(ll_notification_sink *)(this + 0xdb0));
    }
    ll_device_link::reevaluate_advertised_vf_state(this_00);
  }
  if (plVar1 != (ll_vf *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== set_vf_goal_state @ 140006a48 =====

/* public: void __cdecl ll_vf::set_vf_goal_state(enum ll_host_vf_state) __ptr64 */

void __thiscall ll_vf::set_vf_goal_state(ll_vf *this,ll_host_vf_state param_1)

{
  ll_vf *plVar1;
  
  plVar1 = this + 0xc08;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  *(ll_host_vf_state *)(this + 0xbc8) = param_1;
  if (plVar1 != (ll_vf *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0xbc0),2);
  return;
}



===== set_vf_state @ 140006acc =====

/* public: void __cdecl ll_vf::set_vf_state(enum ll_host_vf_state) __ptr64 */

void __thiscall ll_vf::set_vf_state(ll_vf *this,ll_host_vf_state param_1)

{
  ll_vf *plVar1;
  
  plVar1 = this + 0xdf0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(plVar1,0);
  if (*(ll_host_vf_state *)(this + 0xde0) != param_1) {
    *(ll_host_vf_state *)(this + 0xde0) = param_1;
    ll_device_link::reevaluate_advertised_vf_state((ll_device_link *)(this + 0xd98));
  }
  if (plVar1 != (ll_vf *)0x0) {
    ExReleasePushLockExclusiveEx(plVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== start @ 140006b50 =====

/* public: int __cdecl ll_vf::start(void) __ptr64 */

int __thiscall ll_vf::start(ll_vf *this)

{
  code *pcVar1;
  int iVar2;
  ll_vf *plVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  undefined1 *puVar6;
  undefined8 uStack_70;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  ll_vf *local_18;
  
  local_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeInitializeEvent(&local_38,0,0);
  local_18 = this + 0xd68;
  local_20 = CONCAT44(local_20._4_4_,0x103);
  *(undefined8 **)local_18 = &local_38;
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0xc10),7);
  local_48 = 0;
  iVar2 = KeWaitForSingleObject(&local_38,0,0,0);
  puVar6 = auStack_68;
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
    puVar6 = auStack_60;
  }
  iVar2 = *(int *)(puVar6 + 0x48);
  **(undefined8 **)(puVar6 + 0x50) = 0;
  if (iVar2 == 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140006c02;
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0xbc0),8);
    *(undefined8 *)(puVar6 + -8) = 0x140006c0e;
    ll_device_link::start((ll_device_link *)(this + 0xd98));
    *(undefined8 *)(puVar6 + -8) = 0x140006c15;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar6 + -8) = 0x140006c2a;
    ExAcquirePushLockExclusiveEx(&DAT_140013710,0);
    ppuVar5 = &PTR_LOOP_1400133b0;
    plVar3 = this + 0xe08;
    puVar4 = PTR_LOOP_1400133b0;
    if (*(undefined ***)(PTR_LOOP_1400133b0 + 8) != &PTR_LOOP_1400133b0) {
      puVar4 = &DAT_00000003;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (ll_vf *)(*pcVar1)();
      puVar6 = puVar6 + 8;
    }
    *(undefined **)plVar3 = puVar4;
    *(undefined ***)(plVar3 + 8) = ppuVar5;
    *(ll_vf **)(puVar4 + 8) = plVar3;
    *(undefined8 *)(puVar6 + -8) = 0x140006c73;
    PTR_LOOP_1400133b0 = plVar3;
    ExReleasePushLockExclusiveEx(&DAT_140013710,0);
    *(undefined8 *)(puVar6 + -8) = 0x140006c7f;
    KeLeaveCriticalRegion();
    iVar2 = 0;
  }
  return iVar2;
}



===== stop @ 140006c98 =====

/* public: void __cdecl ll_vf::stop(void) __ptr64 */

void __thiscall ll_vf::stop(ll_vf *this)

{
  ll_vf *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  ll_global *plVar7;
  StateMachineEngine *this_00;
  undefined1 *puVar8;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined8 local_48 [5];
  longlong local_20 [3];
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140013710,0);
  plVar1 = this + 0xe08;
  lVar2 = *(longlong *)plVar1;
  if ((*(ll_vf **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(this + 0xe10), (ll_vf *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExReleasePushLockExclusiveEx(&DAT_140013710,0);
    KeLeaveCriticalRegion();
    plVar7 = ll_global::get_instance();
    puVar8 = auStack_68;
    this_00 = (StateMachineEngine *)(plVar7 + 0x58);
    do {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(this_00,0);
      iVar6 = KeReadStateEvent(plVar7 + 0x20);
      puVar5 = auStack_68;
      if (iVar6 != 0) goto LAB_140006d9b;
      if (this_00 != (StateMachineEngine *)0x0) {
        ExReleasePushLockExclusiveEx(this_00);
        KeLeaveCriticalRegion();
      }
      local_48[0] = 0;
      iVar6 = KeWaitForSingleObject(plVar7 + 0x20,0,0,0);
    } while (iVar6 == 0);
    while( true ) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(7);
      puVar5 = puVar8 + 8;
LAB_140006d9b:
      puVar8 = puVar5;
      plVar1 = this + 0xdb0;
      lVar2 = *(longlong *)plVar1;
      if ((*(ll_vf **)(lVar2 + 8) != plVar1) ||
         (plVar3 = *(longlong **)(this + 0xdb8), (ll_vf *)*plVar3 != plVar1)) break;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      if (this_00 != (StateMachineEngine *)0x0) {
        *(undefined8 *)(puVar8 + -8) = 0x140006dd4;
        ExReleasePushLockExclusiveEx(this_00,0);
        *(undefined8 *)(puVar8 + -8) = 0x140006de0;
        KeLeaveCriticalRegion();
      }
      this_00 = (StateMachineEngine *)(this + 0xbc0);
      plVar1 = this + 0xc08;
      *(undefined8 *)(puVar8 + -8) = 0x140006df7;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar8 + -8) = 0x140006e08;
      ExAcquirePushLockExclusiveEx(plVar1,0);
      this[0xbcc] = (ll_vf)0x1;
      if (plVar1 != (ll_vf *)0x0) {
        *(undefined8 *)(puVar8 + -8) = 0x140006e22;
        ExReleasePushLockExclusiveEx(plVar1,0);
        *(undefined8 *)(puVar8 + -8) = 0x140006e2e;
        KeLeaveCriticalRegion();
      }
      *(undefined8 *)(puVar8 + -8) = 0x140006e40;
      SmFx::StateMachineEngine::EnqueueEvent(this_00,2);
      *(undefined8 *)(puVar8 + 0x20) = 0;
      *(undefined8 *)(puVar8 + -8) = 0x140006e59;
      iVar6 = KeWaitForSingleObject(this + 0xbd0,0,0,0);
      if (iVar6 == 0) {
        this_00 = (StateMachineEngine *)(this + 0xbb0);
        *(undefined8 *)(puVar8 + -8) = 0x140006e77;
        ExWaitForRundownProtectionRelease(this_00);
        *(undefined8 *)(puVar8 + -8) = 0x140006e86;
        ExRundownCompleted(this_00);
        *(undefined8 *)(puVar8 + 0x48) = 0;
        *(undefined8 *)(puVar8 + 0x40) = 0;
        *(undefined8 *)(puVar8 + 0x30) = 0;
        *(undefined8 *)(puVar8 + 0x38) = 0;
        *(undefined8 *)(puVar8 + -8) = 0x140006eb1;
        KeInitializeEvent(puVar8 + 0x30,0);
        *(undefined4 *)(puVar8 + 0x48) = 0x103;
        *(ll_vf **)(puVar8 + 0x50) = this + 0xd68;
        *(undefined1 **)(this + 0xd68) = puVar8 + 0x30;
        *(undefined8 *)(puVar8 + -8) = 0x140006ee3;
        SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(this + 0xc10),8);
        *(undefined8 *)(puVar8 + 0x20) = 0;
        *(undefined8 *)(puVar8 + -8) = 0x140006efd;
        iVar6 = KeWaitForSingleObject(puVar8 + 0x30,0);
        if (iVar6 == 0) {
          **(undefined8 **)(puVar8 + 0x50) = 0;
          return;
        }
      }
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== McTemplateK0x_EtwWriteTransfer @ 140006f34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== on_oid_create_receive_filter @ 140006f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl ll_vmswitch_oids::on_oid_create_receive_filter(struct
   _NDIS_RECEIVE_FILTER_PARAMETERS * __ptr64,struct ll_etw_activity const & __ptr64) __ptr64 */

int __thiscall
ll_vmswitch_oids::on_oid_create_receive_filter
          (ll_vmswitch_oids *this,_NDIS_RECEIVE_FILTER_PARAMETERS *param_1,ll_etw_activity *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  ll_vmswitch_oids *plVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  ll_vmswitch_oids *plVar12;
  
  plVar12 = (ll_vmswitch_oids *)0x0;
  uVar10 = *(uint *)(param_1 + 0x28);
  if ((uVar10 == 0) ||
     ((((*(int *)this != 0 && (*(int *)(this + 0x880) != 0)) && (uVar10 == *(uint *)(this + 0x894)))
      && (plVar12 = this + 0x888, plVar12 != (ll_vmswitch_oids *)0x0)))) {
    if (*(int *)(this + 0xb78) == 0) {
      if (*(uint *)(param_1 + 0x18) < 2) {
        plVar8 = this + 0xbb0;
        cVar5 = ExAcquireRundownProtection();
        if (cVar5 == '\0') {
          if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
            McTemplateK0x_EtwWriteTransfer
                      (plVar8,&oid_while_detaching,param_2,
                       *(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8));
          }
          iVar6 = -0x3ffffe7c;
        }
        else {
          uVar3 = *(undefined8 *)(param_1 + 0xc);
          uVar4 = *(undefined8 *)(param_1 + 0x20);
          uVar10 = *(uint *)(param_1 + 0x18);
          *(undefined8 *)(this + 0xb80) = *(undefined8 *)(param_1 + 4);
          *(undefined8 *)(this + 0xb88) = uVar3;
          *(undefined8 *)(this + 0xb90) = uVar4;
          *(ll_vmswitch_oids **)(this + 0xb98) = plVar12;
          *(ulonglong *)(this + 0xba0) = (ulonglong)uVar10;
          *(undefined8 *)(this + 0xba8) = 0;
          uVar11 = 0;
          if (*(int *)(param_1 + 0x18) != 0) {
            do {
              uVar9 = (ulonglong)*(uint *)(param_1 + 0x14);
              uVar10 = (int)uVar11 + 1;
              lVar7 = *(uint *)(param_1 + 0x1c) * uVar11;
              uVar1 = *(undefined4 *)(param_1 + uVar9 + 8 + lVar7);
              uVar2 = *(undefined4 *)(param_1 + uVar9 + 0xc + lVar7);
              *(undefined4 *)(this + uVar11 * 0xc + 0xba4) =
                   *(undefined4 *)(param_1 + uVar9 + 4 + lVar7);
              *(undefined4 *)(this + uVar11 * 0xc + 0xba8) = uVar1;
              *(undefined4 *)(this + uVar11 * 0xc + 0xbac) = uVar2;
              uVar11 = (ulonglong)uVar10;
            } while (uVar10 < *(uint *)(param_1 + 0x18));
          }
          *(int *)(this + 0xb78) = *(int *)(this + 0xb78) + 1;
          ll_vf::set_datapath_up(*(ll_vf **)(this + 3000),*(int *)(param_1 + 0x28) != 0);
          iVar6 = 0;
        }
      }
      else {
        iVar6 = -0x3fffff45;
      }
    }
    else {
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
        McTemplateK0xu_EtwWriteTransfer
                  ((ulonglong)uVar10,&too_many_objects,param_2,
                   *(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),3);
      }
      iVar6 = -0x3ffeffe3;
    }
  }
  else {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xud_EtwWriteTransfer
                ((ulonglong)uVar10,param_1,param_2,
                 *(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),2,(char)uVar10);
    }
    iVar6 = -0x3ffeffe5;
  }
  return iVar6;
}



===== on_oid_create_switch @ 140007188 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl ll_vmswitch_oids::on_oid_create_switch(struct _NDIS_NIC_SWITCH_PARAMETERS *
   __ptr64,struct ll_etw_activity const & __ptr64) __ptr64 */

int __thiscall
ll_vmswitch_oids::on_oid_create_switch
          (ll_vmswitch_oids *this,_NDIS_NIC_SWITCH_PARAMETERS *param_1,ll_etw_activity *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  _NDIS_NIC_SWITCH_PARAMETERS *p_Var7;
  ll_vmswitch_oids *plVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined1 auStack_bd8 [32];
  undefined4 local_ba8;
  undefined4 local_ba4;
  undefined8 local_ba0 [64];
  undefined4 local_99c;
  undefined4 local_998;
  undefined4 local_994;
  undefined8 local_990;
  undefined4 local_988;
  undefined1 local_984 [516];
  undefined1 local_780 [516];
  undefined1 local_57c [516];
  undefined2 local_378;
  undefined8 local_376;
  undefined8 uStack_36e;
  undefined8 local_366;
  undefined8 uStack_35e;
  undefined8 local_356;
  undefined8 uStack_34e;
  undefined8 local_346;
  undefined8 uStack_33e;
  undefined2 local_336;
  undefined8 local_334;
  undefined4 local_32c;
  undefined8 local_328;
  undefined8 local_320;
  undefined1 local_318 [516];
  undefined8 local_114;
  undefined8 local_10c;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined1 local_e8;
  undefined2 local_e7;
  undefined1 local_e5;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_bd8;
  if (*(int *)this == 0) {
    plVar8 = this + 0xbb0;
    cVar5 = ExAcquireRundownProtection();
    if (cVar5 == '\0') {
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
        McTemplateK0x_EtwWriteTransfer
                  (plVar8,&oid_while_detaching,param_2,
                   *(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8));
      }
      iVar6 = -0x3ffffe7c;
    }
    else {
      local_ba8 = *(undefined4 *)(param_1 + 8);
      lVar11 = 4;
      local_ba4 = *(undefined4 *)(param_1 + 0xc);
      p_Var7 = param_1 + 0x10;
      puVar9 = local_ba0;
      do {
        uVar1 = *(undefined8 *)(p_Var7 + 8);
        uVar2 = *(undefined8 *)(p_Var7 + 0x10);
        uVar3 = *(undefined8 *)(p_Var7 + 0x18);
        *puVar9 = *(undefined8 *)p_Var7;
        puVar9[1] = uVar1;
        uVar1 = *(undefined8 *)(p_Var7 + 0x20);
        uVar4 = *(undefined8 *)(p_Var7 + 0x28);
        puVar9[2] = uVar2;
        puVar9[3] = uVar3;
        uVar2 = *(undefined8 *)(p_Var7 + 0x30);
        uVar3 = *(undefined8 *)(p_Var7 + 0x38);
        puVar9[4] = uVar1;
        puVar9[5] = uVar4;
        uVar1 = *(undefined8 *)(p_Var7 + 0x40);
        uVar4 = *(undefined8 *)(p_Var7 + 0x48);
        puVar9[6] = uVar2;
        puVar9[7] = uVar3;
        uVar2 = *(undefined8 *)(p_Var7 + 0x50);
        uVar3 = *(undefined8 *)(p_Var7 + 0x58);
        puVar9[8] = uVar1;
        puVar9[9] = uVar4;
        uVar1 = *(undefined8 *)(p_Var7 + 0x60);
        uVar4 = *(undefined8 *)(p_Var7 + 0x68);
        puVar9[10] = uVar2;
        puVar9[0xb] = uVar3;
        uVar2 = *(undefined8 *)(p_Var7 + 0x70);
        uVar3 = *(undefined8 *)(p_Var7 + 0x78);
        p_Var7 = p_Var7 + 0x80;
        puVar9[0xc] = uVar1;
        puVar9[0xd] = uVar4;
        puVar10 = puVar9 + 0x10;
        puVar9[0xe] = uVar2;
        puVar9[0xf] = uVar3;
        lVar11 = lVar11 + -1;
        puVar9 = puVar10;
      } while (lVar11 != 0);
      *(undefined4 *)puVar10 = *(undefined4 *)p_Var7;
      local_99c = *(undefined4 *)(param_1 + 0x224);
      local_998 = *(undefined4 *)(param_1 + 0x214);
      local_994 = 0;
      memset(&local_990,0,0x660);
      local_990 = 0;
      local_988 = 0;
      memset(local_984,0,0x204);
      memset(local_780,0,0x204);
      memset(local_57c,0,0x204);
      local_378 = 0;
      local_336 = 0;
      local_334 = 0;
      local_32c = 0;
      local_376 = 0;
      uStack_36e = 0;
      local_366 = 0;
      uStack_35e = 0;
      local_356 = 0;
      uStack_34e = 0;
      local_346 = 0;
      uStack_33e = 0;
      memset(&local_328,0,0x2f0);
      local_328 = 0;
      local_320 = 0;
      memset(local_318,0,0x204);
      local_114 = 0;
      local_104 = 0;
      local_e7 = 0;
      local_e5 = 0;
      local_10c = 0;
      local_100 = 0;
      uStack_f8 = 0;
      local_f0 = 0;
      memset(&local_e8,0,0xa8);
      local_40 = 0;
      memmove(this + 8,&local_ba8,0xb70);
      *(int *)this = *(int *)this + 1;
      iVar6 = 0;
    }
  }
  else {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xu_EtwWriteTransfer
                (this,&too_many_objects,param_2,*(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),
                 0);
    }
    iVar6 = -0x3ffeffe3;
  }
  return iVar6;
}



===== on_oid_create_vf @ 140007420 =====

/* public: int __cdecl ll_vmswitch_oids::on_oid_create_vf(struct _NDIS_NIC_SWITCH_VF_PARAMETERS *
   __ptr64,struct ll_etw_activity const & __ptr64) __ptr64 */

int __thiscall
ll_vmswitch_oids::on_oid_create_vf
          (ll_vmswitch_oids *this,_NDIS_NIC_SWITCH_VF_PARAMETERS *param_1,ll_etw_activity *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  _NDIS_NIC_SWITCH_VF_PARAMETERS *p_Var8;
  longlong lVar9;
  longlong lVar10;
  ll_vmswitch_oids *local_668;
  undefined4 local_660;
  undefined8 local_65c [64];
  undefined8 local_458 [64];
  undefined8 local_254 [64];
  undefined2 local_50;
  undefined8 local_4e;
  undefined8 uStack_46;
  undefined8 local_3e;
  undefined8 uStack_36;
  undefined8 local_2e;
  undefined8 uStack_26;
  undefined8 local_1e;
  undefined8 uStack_16;
  undefined2 local_e;
  undefined4 local_c;
  
  p_Var8 = param_1 + 8;
  if (((*(int *)this == 0) || (*(int *)p_Var8 != *(int *)(this + 0xc))) ||
     (local_668 = this + 8, local_668 == (ll_vmswitch_oids *)0x0)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xud_EtwWriteTransfer
                (this,p_Var8,param_2,*(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),0,
                 (char)*(int *)p_Var8);
    }
    iVar5 = -0x3ffeffe5;
  }
  else if (*(int *)(this + 0x21c) == 0) {
    if (*(short *)(param_1 + 0x618) == 6) {
      local_660 = *(undefined4 *)(param_1 + 4);
      lVar9 = 4;
      p_Var8 = param_1 + 0xc;
      lVar10 = 4;
      puVar7 = local_65c;
      do {
        uVar1 = *(undefined8 *)(p_Var8 + 8);
        uVar2 = *(undefined8 *)(p_Var8 + 0x10);
        uVar3 = *(undefined8 *)(p_Var8 + 0x18);
        *puVar7 = *(undefined8 *)p_Var8;
        puVar7[1] = uVar1;
        uVar1 = *(undefined8 *)(p_Var8 + 0x20);
        uVar4 = *(undefined8 *)(p_Var8 + 0x28);
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x30);
        uVar3 = *(undefined8 *)(p_Var8 + 0x38);
        puVar7[4] = uVar1;
        puVar7[5] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x40);
        uVar4 = *(undefined8 *)(p_Var8 + 0x48);
        puVar7[6] = uVar2;
        puVar7[7] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x50);
        uVar3 = *(undefined8 *)(p_Var8 + 0x58);
        puVar7[8] = uVar1;
        puVar7[9] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x60);
        uVar4 = *(undefined8 *)(p_Var8 + 0x68);
        puVar7[10] = uVar2;
        puVar7[0xb] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x70);
        uVar3 = *(undefined8 *)(p_Var8 + 0x78);
        p_Var8 = p_Var8 + 0x80;
        puVar7[0xc] = uVar1;
        puVar7[0xd] = uVar4;
        puVar6 = puVar7 + 0x10;
        puVar7[0xe] = uVar2;
        puVar7[0xf] = uVar3;
        lVar10 = lVar10 + -1;
        puVar7 = puVar6;
      } while (lVar10 != 0);
      lVar10 = 4;
      *(undefined4 *)puVar6 = *(undefined4 *)p_Var8;
      p_Var8 = param_1 + 0x210;
      puVar7 = local_458;
      do {
        uVar1 = *(undefined8 *)(p_Var8 + 8);
        uVar2 = *(undefined8 *)(p_Var8 + 0x10);
        uVar3 = *(undefined8 *)(p_Var8 + 0x18);
        *puVar7 = *(undefined8 *)p_Var8;
        puVar7[1] = uVar1;
        uVar1 = *(undefined8 *)(p_Var8 + 0x20);
        uVar4 = *(undefined8 *)(p_Var8 + 0x28);
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x30);
        uVar3 = *(undefined8 *)(p_Var8 + 0x38);
        puVar7[4] = uVar1;
        puVar7[5] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x40);
        uVar4 = *(undefined8 *)(p_Var8 + 0x48);
        puVar7[6] = uVar2;
        puVar7[7] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x50);
        uVar3 = *(undefined8 *)(p_Var8 + 0x58);
        puVar7[8] = uVar1;
        puVar7[9] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x60);
        uVar4 = *(undefined8 *)(p_Var8 + 0x68);
        puVar7[10] = uVar2;
        puVar7[0xb] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x70);
        uVar3 = *(undefined8 *)(p_Var8 + 0x78);
        p_Var8 = p_Var8 + 0x80;
        puVar7[0xc] = uVar1;
        puVar7[0xd] = uVar4;
        puVar6 = puVar7 + 0x10;
        puVar7[0xe] = uVar2;
        puVar7[0xf] = uVar3;
        lVar10 = lVar10 + -1;
        puVar7 = puVar6;
      } while (lVar10 != 0);
      *(undefined4 *)puVar6 = *(undefined4 *)p_Var8;
      p_Var8 = param_1 + 0x414;
      puVar7 = local_254;
      do {
        uVar1 = *(undefined8 *)(p_Var8 + 8);
        uVar2 = *(undefined8 *)(p_Var8 + 0x10);
        uVar3 = *(undefined8 *)(p_Var8 + 0x18);
        *puVar7 = *(undefined8 *)p_Var8;
        puVar7[1] = uVar1;
        uVar1 = *(undefined8 *)(p_Var8 + 0x20);
        uVar4 = *(undefined8 *)(p_Var8 + 0x28);
        puVar7[2] = uVar2;
        puVar7[3] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x30);
        uVar3 = *(undefined8 *)(p_Var8 + 0x38);
        puVar7[4] = uVar1;
        puVar7[5] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x40);
        uVar4 = *(undefined8 *)(p_Var8 + 0x48);
        puVar7[6] = uVar2;
        puVar7[7] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x50);
        uVar3 = *(undefined8 *)(p_Var8 + 0x58);
        puVar7[8] = uVar1;
        puVar7[9] = uVar4;
        uVar1 = *(undefined8 *)(p_Var8 + 0x60);
        uVar4 = *(undefined8 *)(p_Var8 + 0x68);
        puVar7[10] = uVar2;
        puVar7[0xb] = uVar3;
        uVar2 = *(undefined8 *)(p_Var8 + 0x70);
        uVar3 = *(undefined8 *)(p_Var8 + 0x78);
        p_Var8 = p_Var8 + 0x80;
        puVar7[0xc] = uVar1;
        puVar7[0xd] = uVar4;
        puVar6 = puVar7 + 0x10;
        puVar7[0xe] = uVar2;
        puVar7[0xf] = uVar3;
        lVar9 = lVar9 + -1;
        puVar7 = puVar6;
      } while (lVar9 != 0);
      *(undefined4 *)puVar6 = *(undefined4 *)p_Var8;
      local_c = *(undefined4 *)(param_1 + 0x65c);
      local_50 = 6;
      local_4e = 0;
      uStack_46 = 0;
      local_e = 0;
      local_3e = 0;
      uStack_36 = 0;
      local_2e = 0;
      uStack_26 = 0;
      local_1e = 0;
      uStack_16 = 0;
      memmove(this + 0x220,&local_668,0x660);
      uVar1 = *(undefined8 *)(param_1 + 0x622);
      *(undefined8 *)(this + 0x83a) = *(undefined8 *)(param_1 + 0x61a);
      *(undefined8 *)(this + 0x842) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x632);
      *(undefined8 *)(this + 0x84a) = *(undefined8 *)(param_1 + 0x62a);
      *(undefined8 *)(this + 0x852) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x642);
      *(undefined8 *)(this + 0x85a) = *(undefined8 *)(param_1 + 0x63a);
      *(undefined8 *)(this + 0x862) = uVar1;
      uVar1 = *(undefined8 *)(param_1 + 0x652);
      *(undefined8 *)(this + 0x86a) = *(undefined8 *)(param_1 + 0x64a);
      *(undefined8 *)(this + 0x872) = uVar1;
      *(undefined2 *)(param_1 + 0x65a) = *(undefined2 *)(this + 0x87a);
      *(int *)(this + 0x21c) = *(int *)(this + 0x21c) + 1;
      SmFx::StateMachineEngine::EnqueueEvent
                ((StateMachineEngine *)(*(longlong *)(this + 3000) + 0xc10),0xb);
      iVar5 = 0;
    }
    else {
      iVar5 = -0x3fffff45;
    }
  }
  else {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xu_EtwWriteTransfer
                (this,&too_many_objects,param_2,*(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),
                 1);
    }
    iVar5 = -0x3ffeffe3;
  }
  return iVar5;
}



===== on_oid_create_vport @ 1400076ec =====

/* public: int __cdecl ll_vmswitch_oids::on_oid_create_vport(struct
   _NDIS_NIC_SWITCH_VPORT_PARAMETERS * __ptr64,struct ll_etw_activity const & __ptr64) __ptr64 */

int __thiscall
ll_vmswitch_oids::on_oid_create_vport
          (ll_vmswitch_oids *this,_NDIS_NIC_SWITCH_VPORT_PARAMETERS *param_1,
          ll_etw_activity *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ll_vmswitch_oids *plVar5;
  ll_vmswitch_oids *plVar6;
  ll_vmswitch_oids *plVar7;
  ll_vmswitch_oids *plVar8;
  ll_vmswitch_oids **pplVar9;
  int iVar10;
  _NDIS_NIC_SWITCH_VPORT_PARAMETERS *p_Var11;
  ll_vmswitch_oids *plVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  ll_vmswitch_oids **pplVar15;
  ulonglong uVar16;
  longlong lVar17;
  longlong lVar18;
  ll_vmswitch_oids *local_2f8;
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined8 local_2e8 [64];
  undefined2 local_e4;
  undefined2 local_e2;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  if (((*(int *)this == 0) || (*(int *)(param_1 + 8) != *(int *)(this + 0xc))) ||
     (this + 8 == (ll_vmswitch_oids *)0x0)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xud_EtwWriteTransfer
                (this,param_1,param_2,*(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),0,
                 (char)*(int *)(param_1 + 8));
    }
    iVar10 = -0x3ffeffe5;
  }
  else if (*(int *)(this + 0x880) == 0) {
    uStack_2f0 = *(undefined4 *)(param_1 + 4);
    uStack_2ec = *(undefined4 *)(param_1 + 0xc);
    p_Var11 = param_1 + 0x10;
    local_2f8 = this + 8;
    puVar13 = local_2e8;
    lVar18 = 4;
    do {
      lVar17 = lVar18;
      uVar1 = *(undefined8 *)(p_Var11 + 8);
      uVar2 = *(undefined8 *)(p_Var11 + 0x10);
      uVar3 = *(undefined8 *)(p_Var11 + 0x18);
      *puVar13 = *(undefined8 *)p_Var11;
      puVar13[1] = uVar1;
      uVar1 = *(undefined8 *)(p_Var11 + 0x20);
      uVar4 = *(undefined8 *)(p_Var11 + 0x28);
      puVar13[2] = uVar2;
      puVar13[3] = uVar3;
      uVar2 = *(undefined8 *)(p_Var11 + 0x30);
      uVar3 = *(undefined8 *)(p_Var11 + 0x38);
      puVar13[4] = uVar1;
      puVar13[5] = uVar4;
      uVar1 = *(undefined8 *)(p_Var11 + 0x40);
      uVar4 = *(undefined8 *)(p_Var11 + 0x48);
      puVar13[6] = uVar2;
      puVar13[7] = uVar3;
      uVar2 = *(undefined8 *)(p_Var11 + 0x50);
      uVar3 = *(undefined8 *)(p_Var11 + 0x58);
      puVar13[8] = uVar1;
      puVar13[9] = uVar4;
      uVar1 = *(undefined8 *)(p_Var11 + 0x60);
      uVar4 = *(undefined8 *)(p_Var11 + 0x68);
      puVar13[10] = uVar2;
      puVar13[0xb] = uVar3;
      uVar2 = *(undefined8 *)(p_Var11 + 0x70);
      uVar3 = *(undefined8 *)(p_Var11 + 0x78);
      p_Var11 = p_Var11 + 0x80;
      puVar13[0xc] = uVar1;
      puVar13[0xd] = uVar4;
      puVar14 = puVar13 + 0x10;
      puVar13[0xe] = uVar2;
      puVar13[0xf] = uVar3;
      lVar18 = lVar17 + -1;
      puVar13 = puVar14;
    } while (lVar18 != 0);
    *(undefined4 *)puVar14 = *(undefined4 *)p_Var11;
    local_e4 = *(undefined2 *)(param_1 + 0x214);
    local_e2 = 0;
    local_e0 = *(undefined4 *)(param_1 + 0x218);
    local_dc = *(undefined4 *)(param_1 + 0x21c);
    local_d8 = *(undefined4 *)(param_1 + 0x220);
    local_d4 = 0;
    local_c0 = *(undefined4 *)(param_1 + 0x238);
    local_bc = 0;
    local_d0 = *(undefined8 *)(param_1 + 0x228);
    uStack_c8 = *(undefined8 *)(param_1 + 0x230);
    local_b8 = *(undefined8 *)(param_1 + 0x240);
    uStack_b0 = *(undefined8 *)(param_1 + 0x248);
    local_a8 = *(undefined8 *)(param_1 + 0x250);
    uStack_a0 = *(undefined8 *)(param_1 + 600);
    local_98 = *(undefined8 *)(param_1 + 0x260);
    uStack_90 = *(undefined8 *)(param_1 + 0x268);
    local_88 = *(undefined8 *)(param_1 + 0x270);
    uStack_80 = *(undefined8 *)(param_1 + 0x278);
    local_78 = *(undefined8 *)(param_1 + 0x280);
    uStack_70 = *(undefined8 *)(param_1 + 0x288);
    local_68 = *(undefined8 *)(param_1 + 0x290);
    uStack_60 = *(undefined8 *)(param_1 + 0x298);
    local_58 = *(undefined8 *)(param_1 + 0x2a0);
    uStack_50 = *(undefined8 *)(param_1 + 0x2a8);
    local_48 = *(undefined8 *)(param_1 + 0x2b0);
    uStack_40 = *(undefined8 *)(param_1 + 0x2b8);
    local_38 = *(undefined8 *)(param_1 + 0x2c0);
    uStack_30 = *(undefined8 *)(param_1 + 0x2c8);
    local_28 = *(undefined8 *)(param_1 + 0x2d0);
    uStack_20 = *(undefined8 *)(param_1 + 0x2d8);
    local_18 = *(undefined8 *)(param_1 + 0x2e0);
    uVar16 = (ulonglong)((int)lVar17 + 4);
    local_10 = *(undefined4 *)(param_1 + 0x2e8);
    local_c = 0;
    plVar8 = this + 0x888;
    pplVar9 = &local_2f8;
    do {
      pplVar15 = pplVar9;
      plVar12 = plVar8;
      plVar8 = pplVar15[1];
      plVar5 = pplVar15[2];
      plVar6 = pplVar15[3];
      *(ll_vmswitch_oids **)plVar12 = *pplVar15;
      *(ll_vmswitch_oids **)(plVar12 + 8) = plVar8;
      plVar8 = pplVar15[4];
      plVar7 = pplVar15[5];
      *(ll_vmswitch_oids **)(plVar12 + 0x10) = plVar5;
      *(ll_vmswitch_oids **)(plVar12 + 0x18) = plVar6;
      plVar5 = pplVar15[6];
      plVar6 = pplVar15[7];
      *(ll_vmswitch_oids **)(plVar12 + 0x20) = plVar8;
      *(ll_vmswitch_oids **)(plVar12 + 0x28) = plVar7;
      plVar8 = pplVar15[8];
      plVar7 = pplVar15[9];
      *(ll_vmswitch_oids **)(plVar12 + 0x30) = plVar5;
      *(ll_vmswitch_oids **)(plVar12 + 0x38) = plVar6;
      plVar5 = pplVar15[10];
      plVar6 = pplVar15[0xb];
      *(ll_vmswitch_oids **)(plVar12 + 0x40) = plVar8;
      *(ll_vmswitch_oids **)(plVar12 + 0x48) = plVar7;
      plVar8 = pplVar15[0xc];
      plVar7 = pplVar15[0xd];
      *(ll_vmswitch_oids **)(plVar12 + 0x50) = plVar5;
      *(ll_vmswitch_oids **)(plVar12 + 0x58) = plVar6;
      plVar5 = pplVar15[0xe];
      plVar6 = pplVar15[0xf];
      *(ll_vmswitch_oids **)(plVar12 + 0x60) = plVar8;
      *(ll_vmswitch_oids **)(plVar12 + 0x68) = plVar7;
      *(ll_vmswitch_oids **)(plVar12 + 0x70) = plVar5;
      *(ll_vmswitch_oids **)(plVar12 + 0x78) = plVar6;
      uVar16 = uVar16 - 1;
      plVar8 = plVar12 + 0x80;
      pplVar9 = pplVar15 + 0x10;
    } while (uVar16 != 0);
    plVar8 = pplVar15[0x11];
    plVar5 = pplVar15[0x12];
    plVar6 = pplVar15[0x13];
    *(ll_vmswitch_oids **)(plVar12 + 0x80) = pplVar15[0x10];
    *(ll_vmswitch_oids **)(plVar12 + 0x88) = plVar8;
    plVar8 = pplVar15[0x14];
    plVar7 = pplVar15[0x15];
    *(ll_vmswitch_oids **)(plVar12 + 0x90) = plVar5;
    *(ll_vmswitch_oids **)(plVar12 + 0x98) = plVar6;
    plVar5 = pplVar15[0x16];
    plVar6 = pplVar15[0x17];
    *(ll_vmswitch_oids **)(plVar12 + 0xa0) = plVar8;
    *(ll_vmswitch_oids **)(plVar12 + 0xa8) = plVar7;
    plVar8 = pplVar15[0x18];
    plVar7 = pplVar15[0x19];
    *(ll_vmswitch_oids **)(plVar12 + 0xb0) = plVar5;
    *(ll_vmswitch_oids **)(plVar12 + 0xb8) = plVar6;
    plVar5 = pplVar15[0x1a];
    plVar6 = pplVar15[0x1b];
    *(ll_vmswitch_oids **)(plVar12 + 0xc0) = plVar8;
    *(ll_vmswitch_oids **)(plVar12 + 200) = plVar7;
    plVar8 = pplVar15[0x1c];
    plVar7 = pplVar15[0x1d];
    *(ll_vmswitch_oids **)(plVar12 + 0xd0) = plVar5;
    *(ll_vmswitch_oids **)(plVar12 + 0xd8) = plVar6;
    *(ll_vmswitch_oids **)(plVar12 + 0xe0) = plVar8;
    *(ll_vmswitch_oids **)(plVar12 + 0xe8) = plVar7;
    *(undefined4 *)(this + 0x880) = 1;
    iVar10 = 0;
  }
  else {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xu_EtwWriteTransfer
                (this,&too_many_objects,param_2,*(undefined8 *)(*(longlong *)(this + 3000) + 0xdf8),
                 2);
    }
    iVar10 = -0x3ffeffe3;
  }
  return iVar10;
}



===== McTemplateK0xud_EtwWriteTransfer @ 140007998 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xud_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 1;
  local_28 = &param_6;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&object_not_found,param_3,4,local_58);
  return;
}



===== ~ll_vmswitch_indications @ 140007a1c =====

/* public: __cdecl ll_vmswitch_indications::~ll_vmswitch_indications(void) __ptr64 */

void __thiscall ll_vmswitch_indications::~ll_vmswitch_indications(ll_vmswitch_indications *this)

{
  code *pcVar1;
  int iVar2;
  
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,1);
  iVar2 = KeWaitForSingleObject(this + 0x28,0,0,0,0);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(7);
  }
  return;
}



===== EvtLogEventEnqueue @ 140007a68 =====

/* private: void __cdecl ll_vmswitch_indications::EvtLogEventEnqueue(enum
   ll_vmswitch_StateMachine<class ll_vmswitch_indications>::EventId) __ptr64 */

void __thiscall
ll_vmswitch_indications::EvtLogEventEnqueue(ll_vmswitch_indications *this,EventId param_1)

{
  _UNICODE_STRING *p_Var1;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    p_Var1 = (_UNICODE_STRING *)&DAT_1400134a0;
    do {
      if (*(short *)p_Var1 == (short)param_1) break;
      p_Var1 = p_Var1 + 0x10;
    } while (p_Var1 != &g_ErrorControlRegValueName);
    McTemplateK0xus_EtwWriteTransfer();
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 140007ad0 =====

/* private: static void __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtLogEventEnqueueThunk
          (void *param_1,ushort param_2)

{
  undefined2 in_register_00000012;
  
  ll_vmswitch_indications::EvtLogEventEnqueue(param_1,CONCAT22(in_register_00000012,param_2));
  return;
}



===== EvtLogTransition @ 140007ae8 =====

/* private: void __cdecl ll_vmswitch_indications::EvtLogTransition(enum SmFx::TransitionType,enum
   ll_vmswitch_StateMachine<class ll_vmswitch_indications>::StateId,enum
   ll_vmswitch_StateMachine<class ll_vmswitch_indications>::EventId,enum
   ll_vmswitch_StateMachine<class ll_vmswitch_indications>::StateId) __ptr64 */

void __thiscall
ll_vmswitch_indications::EvtLogTransition
          (ll_vmswitch_indications *this,TransitionType param_1,StateId param_2,EventId param_3,
          StateId param_4)

{
  _UNICODE_STRING *p_Var1;
  short *psVar2;
  short *psVar3;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    p_Var1 = (_UNICODE_STRING *)&DAT_1400134a0;
    do {
      if (*(short *)p_Var1 == (short)param_3) break;
      p_Var1 = p_Var1 + 0x10;
    } while (p_Var1 != &g_ErrorControlRegValueName);
    psVar2 = &DAT_1400133c0;
    psVar3 = &DAT_1400133c0;
    do {
      if (*psVar3 == (undefined2)param_4) break;
      psVar3 = psVar3 + 8;
    } while (psVar3 != &DAT_1400134a0);
    do {
      if (*psVar2 == (short)param_2) break;
      psVar2 = psVar2 + 8;
    } while (psVar2 != &DAT_1400134a0);
    McTemplateK0xuusss_EtwWriteTransfer();
  }
  return;
}



===== EvtLogTransitionThunk @ 140007bc0 =====

/* private: static void __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined4 in_stack_ffffffffffffffe8;
  
  ll_vmswitch_indications::EvtLogTransition
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4),
             CONCAT22((short)((uint)in_stack_ffffffffffffffe8 >> 0x10),param_5));
  return;
}



===== EvtMachineDestroyedThunk @ 140007be0 =====

/* private: static void __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EvtMachineDestroyedThunk(void *param_1)

{
  KeSetEvent((longlong)param_1 + 0x28,0,0);
  return;
}



===== advertise_null_capabilities @ 140007c08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ll_vmswitch_indications::advertise_null_capabilities(void) __ptr64 */

void __thiscall ll_vmswitch_indications::advertise_null_capabilities(ll_vmswitch_indications *this)

{
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  undefined8 local_190;
  undefined4 local_188;
  undefined8 local_184;
  undefined4 local_17c;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 *local_168;
  undefined8 local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined4 local_14c;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_118 = 0x540280;
  local_110 = 0;
  local_17c = 0;
  local_168 = &local_118;
  local_108 = 0;
  local_100 = 0;
  local_154 = 0;
  local_14c = 0;
  local_f8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_198 = 0x700198;
  local_190 = 0;
  local_188 = 0;
  local_184 = 0x40020010;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0x54;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  local_198 = 0x700198;
  local_17c = 0;
  local_168 = &local_118;
  local_190 = 0;
  local_188 = 0;
  local_154 = 0;
  local_14c = 0;
  local_184 = 0x40020020;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0x54;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  local_b8 = 0x840380;
  local_17c = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_198 = 0x700198;
  local_190 = 0;
  local_188 = 0;
  local_184 = 0x40020040;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0x84;
  local_154 = 0;
  local_14c = 0;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_168 = &local_b8;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  local_198 = 0x700198;
  local_17c = 0;
  local_190 = 0;
  local_188 = 0;
  local_154 = 0;
  local_14c = 0;
  local_184 = 0x40020050;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0x84;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_168 = &local_b8;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  local_128 = 0xc0180;
  local_17c = 0;
  local_168 = &local_128;
  local_120 = 0;
  local_198 = 0x700198;
  local_154 = 0;
  local_14c = 0;
  local_190 = 0;
  local_188 = 0;
  local_184 = 0x40020052;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0xc;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  local_198 = 0x700198;
  local_17c = 0;
  local_168 = &local_128;
  local_190 = 0;
  local_188 = 0;
  local_154 = 0;
  local_14c = 0;
  local_184 = 0x40020054;
  local_178 = 0;
  uStack_170 = 0;
  local_160 = 0xc;
  local_158 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_198,0);
  return;
}



===== advertising_initial_capabilitiesEntry @ 140007f60 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::advertising_initial_capabilitiesEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::advertising_initial_capabilitiesEntry
          (void *param_1)

{
  ll_vmswitch_indications::indicate_sriov_capabilities(param_1,0x40020054);
  ll_vmswitch_indications::indicate_sriov_capabilities(param_1,0x40020052);
  ll_vmswitch_indications::indicate_switch_capabilities(param_1,0x40020050,1);
  ll_vmswitch_indications::indicate_switch_capabilities(param_1,0x40020040,0);
  ll_vmswitch_indications::indicate_receive_filter_capabilities(param_1,0x40020020);
  ll_vmswitch_indications::indicate_receive_filter_capabilities(param_1,0x40020010);
  return 7;
}



===== advertising_vfEntry @ 140007fd0 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::advertising_vfEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::advertising_vfEntry(void *param_1)

{
  ll_vmswitch_indications::indicate_switch_capabilities(param_1,0x40020040,1);
  return 7;
}



===== bringing_down_datapathEntry @ 140008000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::bringing_down_datapathEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::bringing_down_datapathEntry
          (void *param_1)

{
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined1 local_20;
  undefined2 local_1f;
  undefined1 local_1d;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_28 = 1;
  local_1f = 0;
  local_1d = 0;
  local_7c = 0;
  local_68 = &local_28;
  local_20 = 0;
  local_90 = 0;
  local_88 = 0;
  local_58 = 0;
  local_54 = 0;
  local_4c = 0;
  local_98 = 0x700198;
  local_84 = 0x40052002;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0xc;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  ll_vmswitch_indications::indicate_status(param_1,(_NDIS_STATUS_INDICATION *)&local_98,0);
  return 7;
}



===== bringing_up_datapathEntry @ 1400080b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::bringing_up_datapathEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::bringing_up_datapathEntry
          (void *param_1)

{
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined1 local_20;
  undefined2 local_1f;
  undefined1 local_1d;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_28 = 1;
  local_1f = 0;
  local_1d = 0;
  local_7c = 0;
  local_68 = &local_28;
  local_90 = 0;
  local_88 = 0;
  local_58 = 0;
  local_54 = 0;
  local_4c = 0;
  local_20 = 1;
  local_98 = 0x700198;
  local_84 = 0x40052002;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0xc;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  ll_vmswitch_indications::indicate_status(param_1,(_NDIS_STATUS_INDICATION *)&local_98,0);
  return 7;
}



===== evaluate_goal_state @ 140008158 =====

/* private: enum ll_vmswitch_StateMachine<class ll_vmswitch_indications>::Event __cdecl
   ll_vmswitch_indications::evaluate_goal_state(void) __ptr64 */

Event __thiscall ll_vmswitch_indications::evaluate_goal_state(ll_vmswitch_indications *this)

{
  ll_vmswitch_indications *plVar1;
  int iVar2;
  code *pcVar3;
  Event EVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar1 = this + 0x48;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(plVar1,0);
  puVar5 = auStack_28;
  if (this[0xc] == (ll_vmswitch_indications)0x0) {
    iVar2 = *(int *)(this + 8);
    if (iVar2 == 0) {
      if (plVar1 != (ll_vmswitch_indications *)0x0) {
        ExReleasePushLockSharedEx(plVar1,0);
        KeLeaveCriticalRegion();
      }
      EVar4 = 4;
    }
    else if (iVar2 == 1) {
      if (plVar1 != (ll_vmswitch_indications *)0x0) {
        ExReleasePushLockSharedEx(plVar1,0);
        KeLeaveCriticalRegion();
      }
      EVar4 = 5;
    }
    else {
      if (iVar2 != 2) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(0x38);
        puVar5 = auStack_20;
      }
      if (plVar1 != (ll_vmswitch_indications *)0x0) {
        *(undefined8 *)(puVar5 + -8) = 0x1400081e1;
        ExReleasePushLockSharedEx(plVar1,0);
        *(undefined8 *)(puVar5 + -8) = 0x1400081ed;
        KeLeaveCriticalRegion();
      }
      EVar4 = 3;
    }
  }
  else {
    if (plVar1 != (ll_vmswitch_indications *)0x0) {
      ExReleasePushLockSharedEx(plVar1,0);
      KeLeaveCriticalRegion();
    }
    EVar4 = 6;
  }
  return EVar4;
}



===== evaluating_goal_state3Entry @ 140008260 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::evaluating_goal_state3Entry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::evaluating_goal_state3Entry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = ll_vmswitch_indications::evaluate_goal_state(param_1);
  return (ushort)EVar1;
}



===== indicate_receive_filter_capabilities @ 140008278 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ll_vmswitch_indications::indicate_receive_filter_capabilities(int) __ptr64
    */

void __thiscall
ll_vmswitch_indications::indicate_receive_filter_capabilities
          (ll_vmswitch_indications *this,int param_1)

{
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  int local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_108;
  local_b8 = &local_78;
  local_60 = 0x100000001;
  uStack_58 = 0x100000001;
  local_78 = 0x540280;
  local_70 = 0x19;
  local_68 = 0;
  local_64 = 3;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_e8 = 0x700198;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b0 = 0x54;
  local_a8 = 0;
  local_a4 = 0;
  local_9c = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_d4 = param_1;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_e8,1);
  return;
}



===== indicate_sriov_capabilities @ 140008348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ll_vmswitch_indications::indicate_sriov_capabilities(int) __ptr64 */

void __thiscall
ll_vmswitch_indications::indicate_sriov_capabilities(ll_vmswitch_indications *this,int param_1)

{
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  int local_84;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_28 = 0xc0180;
  local_68 = &local_28;
  local_20 = 3;
  local_98 = 0x700198;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0xc;
  local_58 = 0;
  local_54 = 0;
  local_4c = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_84 = param_1;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_98,1);
  return;
}



===== indicate_status @ 1400083e4 =====

/* private: void __cdecl ll_vmswitch_indications::indicate_status(struct _NDIS_STATUS_INDICATION *
   __ptr64,unsigned int) __ptr64 */

void __thiscall
ll_vmswitch_indications::indicate_status
          (ll_vmswitch_indications *this,_NDIS_STATUS_INDICATION *param_1,uint param_2)

{
  longlong lVar1;
  undefined4 in_register_00000084;
  
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 8) != 0) {
    McTemplateK0xdd_EtwWriteTransfer
              (this,param_1,CONCAT44(in_register_00000084,param_2),
               *(undefined8 *)(*(longlong *)(this + 0x40) + 0xdf8),
               (char)*(undefined4 *)(param_1 + 0x14),(char)param_2);
  }
  lVar1 = *(longlong *)(this + 0x40);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(lVar1 + 0xe00);
  NdisFIndicateStatus(*(undefined8 *)(lVar1 + 0xe00),param_1);
  return;
}



===== indicate_switch_capabilities @ 140008450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ll_vmswitch_indications::indicate_switch_capabilities(int,unsigned long)
   __ptr64 */

void __thiscall
ll_vmswitch_indications::indicate_switch_capabilities
          (ll_vmswitch_indications *this,int param_1,ulong param_2)

{
  undefined1 auStack_138 [32];
  undefined8 local_118;
  undefined8 local_110;
  undefined4 local_108;
  int local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  ulong local_78;
  uint local_74;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  uint local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  local_9c = param_2 + 1;
  local_a8 = 0x840380;
  local_e8 = &local_a8;
  local_a0 = 0;
  local_d4 = 0;
  local_cc = 0;
  local_98 = 1;
  local_94 = 1;
  local_8c = 0;
  local_88 = 0x40;
  local_84 = 1;
  local_80 = 2;
  local_70 = 0;
  local_68 = 0;
  local_64 = 1;
  local_5c = 0;
  local_54 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = 1;
  local_38 = 0;
  uStack_30 = 0;
  local_118 = 0x700198;
  local_110 = 0;
  local_108 = 0;
  local_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e0 = 0x84;
  local_d8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_104 = param_1;
  local_78 = param_2;
  local_74 = local_9c;
  local_4c = local_9c;
  indicate_status(this,(_NDIS_STATUS_INDICATION *)&local_118,local_9c);
  return;
}



===== revoking_initial_capabilitiesEntry @ 140008550 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::revoking_initial_capabilitiesEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::revoking_initial_capabilitiesEntry
          (void *param_1)

{
  ll_vmswitch_indications::advertise_null_capabilities(param_1);
  return 7;
}



===== revoking_vfEntry @ 140008570 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::revoking_vfEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::revoking_vfEntry(void *param_1)

{
  ll_vmswitch_indications::indicate_switch_capabilities(param_1,0x40020040,0);
  return 7;
}



===== waiting_for_destroyEntry @ 1400085a0 =====

/* public: static unsigned short __cdecl ll_vmswitch_StateMachine<class
   ll_vmswitch_indications>::EntryFuncs::waiting_for_destroyEntry(void * __ptr64) */

ushort __cdecl
ll_vmswitch_StateMachine<ll_vmswitch_indications>::EntryFuncs::waiting_for_destroyEntry
          (void *param_1)

{
  KeSetEvent((longlong)param_1 + 0x10,0,0);
  return 0;
}



===== McTemplateK0xdd_EtwWriteTransfer @ 1400085c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xdd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&indicated_status,0,4,local_58);
  return;
}



===== open @ 140008648 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl ll_vpci::open(void) __ptr64 */

long __thiscall ll_vpci::open(ll_vpci *this)

{
  long lVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 local_90;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  wchar_t local_38 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (*(longlong *)this == 0) {
    local_70 = 0;
    local_90 = 0x20;
    local_80 = local_38;
    builtin_wcsncpy(local_38,L"\\Device\\",8);
    local_68 = &local_88;
    *(undefined8 *)this = 0;
    local_98 = 0;
    local_88 = 0x20001e;
    local_78 = 0x30;
    local_48 = 0;
    uStack_40 = 0;
    local_60 = 0x240;
    local_58 = 0;
    uStack_50 = 0;
    builtin_wcsncpy(local_38 + 8,L"VPCIVSC",8);
    lVar1 = ZwOpenFile(0,3,&local_78,&local_48);
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



===== set_pci_proxy_enabled @ 140008704 =====

/* public: long __cdecl ll_vpci::set_pci_proxy_enabled(bool) __ptr64 */

long __thiscall ll_vpci::set_pci_proxy_enabled(ll_vpci *this,bool param_1)

{
  long lVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  lVar1 = ZwDeviceIoControlFile
                    (*(undefined8 *)this,0,0,0,&local_18,(param_1 ^ 1) * 4 + 0x220018,
                     *(undefined8 *)(this + 8),*(undefined4 *)(this + 0x10),0,0);
  return lVar1;
}



===== Feature_NVBugFixes2502__private_IsEnabledDeviceUsageNoInline @ 14000876c =====

ulonglong Feature_NVBugFixes2502__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_NVBugFixes2502__private_featureState;
  if ((Feature_NVBugFixes2502__private_featureState & 0x10) == 0) {
    uVar1 = Feature_NVBugFixes2502__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_NVBugFixes2502__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_NVBugFixes2502__private_IsEnabledFallback @ 1400087a4 =====

void Feature_NVBugFixes2502__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_NVBugFixes2502__private_descriptor);
  return;
}



===== Feature_NVBugFixes2505__private_IsEnabledDeviceUsageNoInline @ 1400087c0 =====

ulonglong Feature_NVBugFixes2505__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_NVBugFixes2505__private_featureState;
  if ((Feature_NVBugFixes2505__private_featureState & 0x10) == 0) {
    uVar1 = Feature_NVBugFixes2505__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_NVBugFixes2505__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_NVBugFixes2505__private_IsEnabledFallback @ 1400087f8 =====

void Feature_NVBugFixes2505__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_NVBugFixes2505__private_descriptor);
  return;
}



===== Feature_NVBugFixes2509__private_IsEnabledDeviceUsageNoInline @ 140008814 =====

ulonglong Feature_NVBugFixes2509__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_NVBugFixes2509__private_featureState;
  if (((uint)Feature_NVBugFixes2509__private_featureState & 0x10) == 0) {
    uVar1 = Feature_NVBugFixes2509__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_NVBugFixes2509__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_NVBugFixes2509__private_IsEnabledFallback @ 14000884c =====

void Feature_NVBugFixes2509__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_NVBugFixes2509__private_descriptor);
  return;
}



===== Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledDeviceUsageNoInline @ 140008868 =====

ulonglong Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_L1VH_AddCriticalLogging__private_featureState;
  if ((Feature_Servicing_L1VH_AddCriticalLogging__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_L1VH_AddCriticalLogging__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledFallback @ 1400088a0 =====

void Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_L1VH_AddCriticalLogging__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400088bc =====

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
LAB_140008abf:
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
LAB_140008997:
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
      if (param_3 == 4) goto LAB_140008abf;
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
        goto LAB_140008997;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140008ba8 =====

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
      goto LAB_140008c79;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140008c79;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140008c79;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140008c79;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140008c79;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140008c79;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140008c79;
    }
  }
  uVar3 = 0xff;
LAB_140008c79:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008cd0 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140008dc0 =====

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
LAB_140008e73:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140008ea1;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140008e73;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140008ea1:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000902c =====

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



===== wil_details_IsEnabledFallback @ 140009090 =====

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



===== evt_io_device_control @ 140009130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static void __cdecl ll_control_device::evt_io_device_control(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
ll_control_device::evt_io_device_control
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ll_ioctl_handler *this;
  ll_ioctl_request *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [48];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  plVar4 = (ll_ioctl_request *)&local_20;
  this = (ll_ioctl_handler *)&DAT_00000003;
  local_20 = 0;
  uStack_18 = 0;
  iVar2 = EtwActivityIdControl();
  puVar5 = auStack_58;
  if (iVar2 != 0) {
    this = (ll_ioctl_handler *)0x38;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
    puVar5 = auStack_50;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009190;
    McTemplateK0q_EtwWriteTransfer(this,plVar4,puVar5 + 0x38,*(undefined4 *)(puVar5 + 0x80));
  }
  *(undefined8 *)(puVar5 + -8) = 0x140009197;
  KeEnterCriticalRegion();
  *(WDFREQUEST__ **)(puVar5 + 0x30) = param_2;
  *(undefined8 *)(puVar5 + -8) = 0x1400091a6;
  ll_global::get_instance();
  iVar2 = *(int *)(puVar5 + 0x80);
  if (iVar2 == 0x220400) {
    plVar4 = (ll_ioctl_request *)(puVar5 + 0x30);
    *(undefined8 *)(puVar5 + -8) = 0x14000920d;
    lVar3 = ll_ioctl_handler::on_query_version(this,plVar4);
  }
  else if (iVar2 == 0x224440) {
    plVar4 = (ll_ioctl_request *)(puVar5 + 0x30);
    *(undefined8 *)(puVar5 + -8) = 0x140009201;
    lVar3 = ll_ioctl_handler::on_query_policy(this,plVar4);
  }
  else if (iVar2 == 0x224480) {
    plVar4 = (ll_ioctl_request *)(puVar5 + 0x30);
    *(undefined8 *)(puVar5 + -8) = 0x1400091f5;
    lVar3 = ll_ioctl_handler::on_query_active_vfs(this,plVar4);
  }
  else if (iVar2 == 0x224484) {
    plVar4 = (ll_ioctl_request *)(puVar5 + 0x30);
    *(undefined8 *)(puVar5 + -8) = 0x1400091e9;
    lVar3 = ll_ioctl_handler::on_query_vf_state(this,plVar4);
  }
  else if (iVar2 == 0x228444) {
    plVar4 = (ll_ioctl_request *)(puVar5 + 0x30);
    *(undefined8 *)(puVar5 + -8) = 0x1400091dd;
    lVar3 = ll_ioctl_handler::on_set_policy(this,plVar4);
  }
  else {
    lVar3 = -0x3ffffff0;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(long *)(puVar5 + 0x20) = lVar3;
    *(undefined8 *)(puVar5 + -8) = 0x14000922e;
    McTemplateK0qd_EtwWriteTransfer
              (this,plVar4,puVar5 + 0x38,*(undefined4 *)(puVar5 + 0x80),puVar5[0x20]);
  }
  pcVar1 = *(code **)(WdfFunctions_01033 + 0x838);
  *(undefined8 *)(puVar5 + -8) = 0x14000924e;
  (*pcVar1)(WdfDriverGlobals,param_2,lVar3);
  *(undefined8 *)(puVar5 + -8) = 0x140009255;
  KeLeaveCriticalRegion();
  *(undefined8 *)(puVar5 + -8) = 0x140009267;
  return;
}



===== initialize @ 14000927c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl ll_control_device::initialize(void) __ptr64 */

long __thiscall ll_control_device::initialize(ll_control_device *this)

{
  int iVar1;
  undefined1 auStack_188 [32];
  undefined8 *local_168;
  longlong local_158;
  undefined8 local_150;
  undefined8 local_148;
  wchar_t *local_140;
  undefined8 local_138;
  wchar_t *local_130;
  undefined8 local_128 [2];
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined1 local_10b;
  code *local_f0;
  undefined4 local_c8;
  wchar_t local_b8 [40];
  wchar_t local_68 [40];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  local_158 = (**(code **)(WdfFunctions_01033 + 200))
                        (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL);
  if (local_158 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    (**(code **)(WdfFunctions_01033 + 0x1e8))(WdfDriverGlobals,local_158,2);
    local_140 = local_b8;
    builtin_wcsncpy(local_b8,L"\\Device\\NestedNetworkVirtualizat",0x20);
    builtin_wcsncpy(local_b8 + 0x20,L"ion",4);
    local_148 = 0x480046;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x218))(WdfDriverGlobals,local_158,&local_148);
    if (iVar1 == 0) {
      local_150 = 0;
      iVar1 = (**(code **)(WdfFunctions_01033 + 600))(WdfDriverGlobals,&local_158,0,&local_150);
      if (iVar1 == 0) {
        local_130 = local_68;
        builtin_wcsncpy(local_68,L"\\DosDevices\\NestedNetworkVirtual",0x20);
        builtin_wcsncpy(local_68 + 0x20,L"ization",8);
        local_138 = 0x50004e;
        iVar1 = (**(code **)(WdfFunctions_01033 + 0x280))(WdfDriverGlobals,local_150,&local_138);
        if (iVar1 == 0) {
          memset(&local_118,0,0x60);
          if (WdfClientVersionHigherThanFramework == '\0') {
            local_118 = 0x60;
          }
          else if (WdfStructureCount < 0x22) {
            local_118 = 0xffffffff;
          }
          else {
            local_118 = *(undefined4 *)(WdfStructures + 0x108);
          }
          local_128[0] = 0;
          local_f0 = evt_io_device_control;
          local_168 = local_128;
          local_c8 = 0xffffffff;
          local_110 = 2;
          local_10b = 1;
          local_114 = 2;
          iVar1 = (**(code **)(WdfFunctions_01033 + 0x4c0))(WdfDriverGlobals,local_150,&local_118,0)
          ;
          if (iVar1 == 0) {
            (**(code **)(WdfFunctions_01033 + 0xd8))(WdfDriverGlobals,local_150);
            return 0;
          }
        }
      }
    }
    if (local_158 != 0) {
      (**(code **)(WdfFunctions_01033 + 0x1b0))(WdfDriverGlobals);
    }
  }
  return iVar1;
}



===== McTemplateK0q_EtwWriteTransfer @ 140009530 =====

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
  McGenEventWrite_EtwWriteTransfer(param_1,&begin_ioctl,param_3,2,local_38);
  return;
}



===== McTemplateK0qd_EtwWriteTransfer @ 140009594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,&end_ioctl,param_3,3,local_48);
  return;
}



===== <lambda_invoker_cdecl> @ 140009610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void `ll_driver::entry'::__l2::<lambda_4>::<lambda_invoker_cdecl>(undefined8 param_1)

{
  ll_notification_bus *this;
  
  this = (ll_notification_bus *)
         (**(code **)(WdfFunctions_01033 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_ll_driver_TYPE_INFO_140013060);
  *(undefined ***)(this + 0xd8) = &ll_device_watcher::_vftable_;
  ll_device_watcher::deinitialize((ll_device_watcher *)(this + 0xd8));
  *(undefined ***)(this + 200) = &ll_device_watcher::_vftable_;
  ll_device_watcher::deinitialize((ll_device_watcher *)(this + 200));
  ll_device_table::~ll_device_table((ll_device_table *)(this + 0xb0));
  ll_policy_table::~ll_policy_table((ll_policy_table *)(this + 0x60));
  ll_notification_bus::~ll_notification_bus(this);
  return;
}



===== ll_driver @ 140009698 =====

/* public: __cdecl ll_driver::ll_driver(void) __ptr64 */

ll_driver * __thiscall ll_driver::ll_driver(ll_driver *this)

{
  ll_driver *plVar1;
  ll_global *this_00;
  
  memset(this + 0x60,0,0x90);
  memset(this,0,0x60);
  *(ll_driver **)(this + 0x18) = this;
  *(code **)(this + 0x10) = ll_notification_bus::deliver_events_thunk;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  KeInitializeEvent(this + 0x20,0,1);
  plVar1 = this + 0x38;
  *(ll_driver **)plVar1 = plVar1;
  *(ll_driver **)(this + 0x40) = plVar1;
  plVar1 = this + 0x48;
  *(ll_driver **)plVar1 = plVar1;
  *(ll_driver **)(this + 0x50) = plVar1;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0x68) = 1;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  this_00 = ll_global::get_instance();
  ll_notification_bus::register_source
            ((ll_notification_bus *)this_00,(ll_notification_source *)(this + 0x88));
  *(undefined8 *)(this + 0xb8) = 0;
  plVar1 = this + 0xb0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(ll_driver **)plVar1 = plVar1;
  *(ll_driver **)(this + 0xb8) = plVar1;
  *(undefined ***)(this + 200) = &ll_net_device_watcher::_vftable_;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined ***)(this + 0xd8) = &ll_pci_proxy_device_watcher::_vftable_;
  *(undefined8 *)(this + 0xe0) = 0;
  this[0xe8] = (ll_driver)0x0;
  *(undefined8 *)(this + 0xf0) = 0;
  this[0xf8] = (ll_driver)0x0;
  return this;
}



===== entry @ 1400097e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl ll_driver::entry(struct _DRIVER_OBJECT * __ptr64,struct
   _UNICODE_STRING * __ptr64) */

long __cdecl ll_driver::entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  ll_driver *this;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [56];
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  code *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined8 local_6c;
  undefined4 local_64;
  code *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  iVar3 = wil_InitializeFeatureStaging();
  puVar6 = auStack_d8;
  if (iVar3 != 0) goto LAB_140009afa;
  uVar4 = Feature_Servicing_L1VH_AddCriticalLogging__private_IsEnabledDeviceUsageNoInline();
  g_L1VHAddCriticalLoggingEnabled = (int)uVar4 != 0;
  uVar4 = Feature_NVBugFixes2502__private_IsEnabledDeviceUsageNoInline();
  g_L1VHBugFixes2502 = (int)uVar4 != 0;
  uVar4 = Feature_NVBugFixes2505__private_IsEnabledDeviceUsageNoInline();
  g_L1VHBugFixes2505 = (int)uVar4 != 0;
  uVar4 = Feature_NVBugFixes2509__private_IsEnabledDeviceUsageNoInline();
  g_L1VHBugFixes2509 = (int)uVar4 != 0;
  if (g_L1VHBugFixes2502 == false) {
LAB_140009872:
    bVar2 = ll_is_l1vh_supported(param_1);
    if (bVar2) {
      McGenEventRegister_EtwRegister();
      uVar5 = 3;
      local_38 = 0;
      uStack_30 = 0;
      iVar3 = EtwActivityIdControl(3,&local_38);
      puVar6 = auStack_d8;
      if (iVar3 != 0) {
        uVar5 = 0x38;
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)();
        puVar6 = auStack_d0;
      }
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x14000990b;
        McTemplateK0_EtwWriteTransfer(uVar5,&begin_driver_entry,&local_38);
      }
      local_8c = 0;
      local_74 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_90 = 0x20;
      }
      else if (WdfStructureCount < 0x19) {
        local_90 = 0xffffffff;
      }
      else {
        local_90 = *(undefined4 *)(WdfStructures + 0xc0);
      }
      local_88 = 0;
      local_80 = evt_driver_unload;
      local_78 = 1;
      local_6c = 0;
      local_64 = 0;
      local_50 = 0;
      uStack_48 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_70 = 0x38;
      }
      else if (WdfStructureCount < 0x27) {
        local_70 = 0xffffffff;
      }
      else {
        local_70 = *(undefined4 *)(WdfStructures + 0x130);
      }
      local_40 = PTR__WDF_ll_driver_TYPE_INFO_140013060;
      *(undefined8 **)(puVar6 + 0x28) = &local_98;
      local_60 = `ll_driver::entry'::__l2::<lambda_4>::<lambda_invoker_cdecl>;
      local_58 = 1;
      local_54 = 1;
      local_98 = 0;
      pcVar1 = *(code **)(WdfFunctions_01033 + 0x3a0);
      *(undefined4 **)(puVar6 + 0x20) = &local_90;
      *(undefined8 *)(puVar6 + -8) = 0x1400099f9;
      this = WdfDriverGlobals;
      iVar3 = (*pcVar1)(WdfDriverGlobals,param_1,param_2,&local_70);
      if (iVar3 == 0) {
        pcVar1 = *(code **)(WdfFunctions_01033 + 0x650);
        *(undefined8 *)(puVar6 + -8) = 0x140009a24;
        this = (ll_driver *)
               (*pcVar1)(WdfDriverGlobals,local_98,PTR__WDF_ll_driver_TYPE_INFO_140013060);
        if (this != (ll_driver *)0x0) {
          *(undefined8 *)(puVar6 + -8) = 0x140009a3c;
          memset(this,0,0x100);
          *(undefined8 *)(puVar6 + -8) = 0x140009a44;
          ll_driver(this);
        }
        *(undefined8 *)(puVar6 + -8) = 0x140009a4c;
        iVar3 = initialize(this);
        if (iVar3 == 0) {
          if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
            *(undefined8 *)(puVar6 + -8) = 0x140009af8;
            McTemplateK0d_EtwWriteTransfer(this,&end_driver_entry,&local_38,0);
          }
          iVar3 = 0;
          goto LAB_140009afa;
        }
      }
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 2) != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x140009a72;
        McTemplateK0d_EtwWriteTransfer(this,&fail_driver_entry,&local_38,iVar3);
      }
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x140009a8e;
        McTemplateK0d_EtwWriteTransfer(this,&end_driver_entry,&local_38,iVar3);
      }
      *(undefined8 *)(puVar6 + -8) = 0x140009a93;
      McGenEventUnregister_EtwUnregister();
      goto LAB_140009a93;
    }
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    puVar6 = auStack_d8;
    iVar3 = -0x3fcaffe2;
  }
  else {
    uVar4 = set_registry_error_control_key();
    puVar6 = auStack_d8;
    iVar3 = (int)uVar4;
    if (iVar3 == 0) goto LAB_140009872;
LAB_140009a93:
    if (g_wil_details_featureChangeNotification != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140009aa6;
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140009ac5;
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
  }
  g_wil_details_isFeatureStagingInitialized = 0;
LAB_140009afa:
  *(undefined8 *)(puVar6 + -8) = 0x140009b06;
  return iVar3;
}



===== evt_driver_unload @ 140009b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static void __cdecl ll_driver::evt_driver_unload(struct WDFDRIVER__ * __ptr64) */

void __cdecl ll_driver::evt_driver_unload(WDFDRIVER__ *param_1)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ll_device_watcher *this;
  undefined1 *puVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar4 = 3;
  local_28 = 0;
  uStack_20 = 0;
  iVar2 = EtwActivityIdControl(3,&local_28);
  puVar5 = auStack_48;
  if (iVar2 != 0) {
    uVar4 = 0x38;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
    puVar5 = auStack_40;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009b8b;
    McTemplateK0_EtwWriteTransfer(uVar4,&begin_driver_unload,puVar5 + 0x20);
  }
  pcVar1 = *(code **)(WdfFunctions_01033 + 0x650);
  *(undefined8 *)(puVar5 + -8) = 0x140009baf;
  lVar3 = (*pcVar1)(WdfDriverGlobals,param_1,PTR__WDF_ll_driver_TYPE_INFO_140013060);
  if (*(longlong *)(lVar3 + 0xf0) != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009bc5;
    NdisFDeregisterFilterDriver();
    *(undefined8 *)(lVar3 + 0xf0) = 0;
  }
  *(undefined8 *)(puVar5 + -8) = 0x140009bde;
  ll_device_watcher::deinitialize((ll_device_watcher *)(lVar3 + 0xd8));
  this = (ll_device_watcher *)(lVar3 + 200);
  *(undefined8 *)(puVar5 + -8) = 0x140009bea;
  ll_device_watcher::deinitialize(this);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009c04;
    McTemplateK0_EtwWriteTransfer(this,&end_driver_unload,puVar5 + 0x20);
  }
  *(undefined8 *)(puVar5 + -8) = 0x140009c09;
  McGenEventUnregister_EtwUnregister();
  if (g_wil_details_featureChangeNotification != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009c1c;
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    *(undefined8 *)(puVar5 + -8) = 0x140009c3c;
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  *(undefined8 *)(puVar5 + -8) = 0x140009c5d;
  return;
}



===== initialize @ 140009c6c =====

/* private: long __cdecl ll_driver::initialize(void) __ptr64 */

long __thiscall ll_driver::initialize(ll_driver *this)

{
  ll_device_watcher *this_00;
  ll_device_watcher *this_01;
  ll_filter_driver *this_02;
  long lVar1;
  ll_filter_driver *this_03;
  
  this_00 = (ll_device_watcher *)(this + 200);
  lVar1 = ll_device_watcher::initialize(this_00,(_GUID *)&GUID_DEVINTERFACE_NET);
  if (lVar1 == 0) {
    this_01 = (ll_device_watcher *)(this + 0xd8);
    lVar1 = ll_device_watcher::initialize(this_01,(_GUID *)&GUID_DEVINTERFACE_VIRTUALIZABLE_DEVICE);
    if (lVar1 == 0) {
      this_02 = (ll_filter_driver *)(this + 0xf0);
      this_03 = this_02;
      lVar1 = ll_filter_driver::register_with_ndis(this_02);
      if (lVar1 == 0) {
        lVar1 = ll_control_device::initialize((ll_control_device *)this_03);
        if (lVar1 == 0) {
          lVar1 = load_persisted_policy(this);
          if (lVar1 == 0) {
            return 0;
          }
          if (*(longlong *)this_02 != 0) {
            NdisFDeregisterFilterDriver();
            *(undefined8 *)this_02 = 0;
          }
          ll_device_watcher::deinitialize(this_01);
          ll_device_watcher::deinitialize(this_00);
          return lVar1;
        }
        if (*(longlong *)this_02 != 0) {
          NdisFDeregisterFilterDriver();
          *(undefined8 *)this_02 = 0;
        }
      }
      ll_device_watcher::deinitialize(this_01);
      ll_device_watcher::deinitialize(this_00);
      return lVar1;
    }
    ll_device_watcher::deinitialize(this_00);
  }
  return lVar1;
}



===== load_persisted_policy @ 140009d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl ll_driver::load_persisted_policy(void) __ptr64 */

long __thiscall ll_driver::load_persisted_policy(ll_driver *this)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_188 [32];
  longlong *local_168;
  undefined4 *local_160;
  longlong local_158;
  undefined4 local_150 [2];
  undefined8 local_148;
  wchar_t *local_140;
  undefined1 local_128 [256];
  wchar_t local_28 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  local_158 = 0;
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  local_168 = &local_158;
  iVar1 = IoOpenDriverRegistryKey(uVar2,2,0x100001);
  if (iVar1 != 0) {
    if (local_158 == 0) {
      return iVar1;
    }
    ZwClose();
    return iVar1;
  }
  memset(local_128,0,0x100);
  puVar3 = (undefined1 *)0x0;
  local_150[0] = 0;
  builtin_wcsncpy(local_28,L"Policy",7);
  local_140 = local_28;
  local_160 = local_150;
  local_168._0_4_ = 0x100;
  local_148 = 0xe000c;
  iVar1 = ZwQueryValueKey(local_158,&local_148,2,local_128);
  if (iVar1 == -0x7ffffffb) {
    puVar3 = (undefined1 *)ExAllocatePool2(0x100,local_150[0],0x70766e6e);
    if (puVar3 == (undefined1 *)0x0) {
      if (local_158 != 0) {
        ZwClose();
      }
      return -0x3fffffe9;
    }
    local_160 = local_150;
    local_168._0_4_ = local_150[0];
    iVar1 = ZwQueryValueKey(local_158,&local_148,2,puVar3);
  }
  if (iVar1 == -0x3fffffcc) {
LAB_140009fb2:
    if (puVar3 != (undefined1 *)0x0) {
      ExFreePoolWithTag(puVar3,0);
    }
    if (local_158 != 0) {
      ZwClose();
    }
    iVar1 = 0;
  }
  else {
    if (iVar1 == 0) {
      puVar4 = local_128;
      if (puVar3 != (undefined1 *)0x0) {
        puVar4 = puVar3;
      }
      if (*(int *)(puVar4 + 4) != 3) {
        if (puVar3 != (undefined1 *)0x0) {
          ExFreePoolWithTag(puVar3,0);
        }
        if (local_158 != 0) {
          ZwClose();
        }
        return -0x3fffffdc;
      }
      iVar1 = ll_policy_table::set_policy
                        ((ll_policy_table *)(this + 0x60),(NNVDRV_POLICY_BLOB *)(puVar4 + 0xc),
                         (ulonglong)*(uint *)(puVar4 + 8));
      if (iVar1 == 0) goto LAB_140009fb2;
    }
    if (puVar3 != (undefined1 *)0x0) {
      ExFreePoolWithTag(puVar3,0);
    }
    if (local_158 != 0) {
      ZwClose();
    }
  }
  return iVar1;
}



===== set_registry_error_control_key @ 14000a00c =====

ulonglong set_registry_error_control_key(void)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 local_38;
  undefined8 local_30;
  _UNICODE_STRING *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_res10 = 0;
  local_20 = 0x240;
  local_res8[0] = 0;
  local_30 = 0;
  local_28 = &g_L1vhlwfRegistryPath;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = ZwOpenKey(&local_res10,3,&local_38);
  if (-1 < (int)uVar2) {
    uVar1 = ZwSetValueKey(local_res10,&g_ErrorControlRegValueName,0,4,local_res8,4);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_res10);
  }
  return uVar2;
}



===== McGenControlCallbackV2 @ 14000a0c0 =====

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



===== McGenEventRegister_EtwRegister @ 14000a1d0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (ll_etw_provider_Context == 0) {
    EtwRegister(&ll_etw_provider,McGenControlCallbackV2,&ll_etw_provider_Context,
                &ll_etw_provider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 14000a210 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (ll_etw_provider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    ll_etw_provider_Context = 0;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 14000a244 =====

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



===== McTemplateK0d_EtwWriteTransfer @ 14000a288 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0d_EtwWriteTransfer
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



===== wil_details_RecordCachedUsage @ 14000a2e4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 14000a430 =====

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



===== ~unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> @ 14000a4b4 =====

/* public: __cdecl wistd::unique_ptr<class ll_filter_module,struct wistd::default_delete<class
   ll_filter_module> >::~unique_ptr<class ll_filter_module,struct wistd::default_delete<class
   ll_filter_module> >(void) __ptr64 */

void __thiscall
wistd::unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>::
~unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>
          (unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> *this)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined8 uStack_30;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar1 != 0) {
    ll_device_link::set_linked_device((ll_device_link *)(lVar1 + 0xda8),(ll_pnp_device *)0x0);
    ll_netvsc_state::~ll_netvsc_state((ll_netvsc_state *)(lVar1 + 0xc20));
    ll_vmswitch_indications::~ll_vmswitch_indications((ll_vmswitch_indications *)(lVar1 + 0xbd0));
    puVar3 = auStack_28;
    if (*(int *)(lVar1 + 0x10) != 0) {
      pcVar2 = (code *)swi(0x2c);
      (*pcVar2)();
      puVar3 = auStack_20;
    }
    if (*(int *)(lVar1 + 0xb88) != 0) {
      pcVar2 = (code *)swi(0x2c);
      (*pcVar2)();
      puVar3 = puVar3 + 8;
    }
    *(undefined8 *)(puVar3 + -8) = 0x14000a50e;
    ExFreePoolWithTag(lVar1,0x21766e6e);
  }
  return;
}



===== attach_module @ 14000a520 =====

/* private: static int __cdecl ll_filter_driver_wrapper<class ll_filter_driver>::attach_module(void
   * __ptr64,void * __ptr64,struct _NDIS_FILTER_ATTACH_PARAMETERS * __ptr64) */

int __cdecl
ll_filter_driver_wrapper<ll_filter_driver>::attach_module
          (void *param_1,void *param_2,_NDIS_FILTER_ATTACH_PARAMETERS *param_3)

{
  int iVar1;
  
  iVar1 = ll_filter_driver::on_ndis_attach_filter(param_2,param_1,param_3);
  return iVar1;
}



===== on_ndis_attach_filter @ 14000a540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl ll_filter_driver::on_ndis_attach_filter(void * __ptr64,struct
   _NDIS_FILTER_ATTACH_PARAMETERS * __ptr64) __ptr64 */

int __thiscall
ll_filter_driver::on_ndis_attach_filter
          (ll_filter_driver *this,void *param_1,_NDIS_FILTER_ATTACH_PARAMETERS *param_2)

{
  ushort uVar1;
  ULONG64 UVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  NTSTATUS NVar6;
  ll_filter_module *this_00;
  ll_filter_module *this_01;
  ll_filter_module *plVar7;
  unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> *puVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [56];
  ll_filter_module *local_58 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  GUID local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = 0;
  uStack_40 = 0;
  iVar5 = EtwActivityIdControl(3,&local_48);
  puVar10 = auStack_98;
  if (iVar5 != 0) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(0x38);
    puVar10 = auStack_90;
  }
  UVar2 = ((NET_LUID *)(param_2 + 0x88))->Value;
  local_38.Data1 = 0;
  local_38.Data2 = 0;
  local_38.Data3 = 0;
  local_38.Data4[0] = '\0';
  local_38.Data4[1] = '\0';
  local_38.Data4[2] = '\0';
  local_38.Data4[3] = '\0';
  local_38.Data4[4] = '\0';
  local_38.Data4[5] = '\0';
  local_38.Data4[6] = '\0';
  local_38.Data4[7] = '\0';
  *(undefined8 *)(puVar10 + -8) = 0x14000a5b2;
  NVar6 = ConvertInterfaceLuidToGuid((NET_LUID *)(param_2 + 0x88),&local_38);
  if (NVar6 != 0) {
    iVar5 = -0x3ffffff3;
    goto LAB_14000a736;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    lVar3 = *(longlong *)(param_2 + 0x20);
    uVar1 = *(ushort *)(param_2 + 0x60);
    *(_NDIS_FILTER_ATTACH_PARAMETERS **)(puVar10 + 0x38) = param_2 + 0x62;
    *(uint *)(puVar10 + 0x30) = (uint)uVar1;
    *(undefined8 *)(puVar10 + 0x28) = *(undefined8 *)(lVar3 + 8);
    *(GUID **)(puVar10 + 0x20) = &local_38;
    *(undefined8 *)(puVar10 + -8) = 0x14000a601;
    McTemplateK0xjzqbr3_EtwWriteTransfer
              ((ulonglong)uVar1,lVar3,&local_48,UVar2,*(undefined8 *)(puVar10 + 0x20),
               *(wchar_t **)(puVar10 + 0x28),*(undefined4 *)(puVar10 + 0x30),
               *(undefined8 *)(puVar10 + 0x38));
  }
  plVar7 = (ll_filter_module *)0x40;
  *(undefined8 *)(puVar10 + -8) = 0x14000a618;
  this_00 = (ll_filter_module *)ExAllocatePool2(0x40,0xe28,0x21766e6e);
  if (this_00 == (ll_filter_module *)0x0) {
    local_58[0] = (ll_filter_module *)0x0;
LAB_14000a6e5:
    iVar5 = -0x3fffff66;
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 2) != 0) {
      *(undefined4 *)(puVar10 + 0x20) = 0xc000009a;
      *(undefined8 *)(puVar10 + -8) = 0x14000a70a;
      McTemplateK0xd_EtwWriteTransfer(plVar7,&fail_attach_adapter,&local_48,UVar2,puVar10[0x20]);
    }
    puVar8 = (unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> *)local_58;
    *(undefined8 *)(puVar10 + -8) = 0x14000a713;
    wistd::unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>::
    ~unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>(puVar8);
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) == 0) goto LAB_14000a736;
    *(undefined4 *)(puVar10 + 0x20) = 0;
  }
  else {
    *(undefined8 *)(puVar10 + -8) = 0x14000a634;
    this_01 = (ll_filter_module *)ll_filter_module::ll_filter_module(this_00,this,param_1);
    local_58[0] = this_01;
    plVar7 = this_00;
    if (this_01 == (ll_filter_module *)0x0) goto LAB_14000a6e5;
    *(undefined8 *)(puVar10 + -8) = 0x14000a64c;
    iVar5 = ll_filter_module::on_ndis_attach_filter(this_01,param_2);
    if (iVar5 == 0) {
      local_58[0] = (ll_filter_module *)0x0;
      puVar8 = (unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> *)local_58;
      *(undefined8 *)(puVar10 + -8) = 0x14000a6bc;
      wistd::unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>::
      ~unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>(puVar8);
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        *(undefined4 *)(puVar10 + 0x20) = 0;
        *(undefined8 *)(puVar10 + -8) = 0x14000a6dc;
        McTemplateK0xd_EtwWriteTransfer(puVar8,&end_attach_adapter,&local_48,UVar2,puVar10[0x20]);
      }
      iVar5 = 0;
      goto LAB_14000a736;
    }
    if (iVar5 == -0x3ffeffe7) {
      *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) | 1;
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
        puVar9 = &decline_attach_adapter;
        goto LAB_14000a682;
      }
    }
    else if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 2) != 0) {
      puVar9 = &fail_attach_adapter;
LAB_14000a682:
      *(int *)(puVar10 + 0x20) = iVar5;
      *(undefined8 *)(puVar10 + -8) = 0x14000a692;
      McTemplateK0xd_EtwWriteTransfer(this_01,puVar9,&local_48,UVar2,puVar10[0x20]);
    }
    puVar8 = (unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_> *)local_58;
    *(undefined8 *)(puVar10 + -8) = 0x14000a69b;
    wistd::unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>::
    ~unique_ptr<ll_filter_module,wistd::default_delete<ll_filter_module>_>(puVar8);
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) == 0) goto LAB_14000a736;
    *(int *)(puVar10 + 0x20) = iVar5;
  }
  *(undefined8 *)(puVar10 + -8) = 0x14000a734;
  McTemplateK0xd_EtwWriteTransfer(puVar8,&end_attach_adapter,&local_48,UVar2,puVar10[0x20]);
LAB_14000a736:
  *(undefined8 *)(puVar10 + -8) = 0x14000a742;
  return iVar5;
}



===== register_with_ndis @ 14000a764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl ll_filter_driver::register_with_ndis(void) __ptr64 */

long __thiscall ll_filter_driver::register_with_ndis(ll_filter_driver *this)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined8 local_d8;
  wchar_t *local_d0;
  undefined8 local_c8;
  wchar_t *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  code *local_60;
  code *local_58;
  undefined8 local_50;
  undefined8 local_48;
  code *local_40;
  code *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_f8 = 0xf0038b;
  local_f4 = 0x15906;
  local_e0 = L"Nested Network Virtualization";
  local_f0 = 0x16;
  local_d0 = L"{fe3ff76a-687d-4689-b87a-d1cee1b037ef}";
  local_c0 = L"l1vhlwf";
  local_a8 = ll_filter_driver_wrapper<ll_filter_driver>::attach_module;
  local_a0 = ll_filter_module_wrapper<ll_filter_module>::detach_module;
  local_98 = ll_filter_module_wrapper<ll_filter_module>::pause_datapath;
  local_90 = ll_filter_module_wrapper<ll_filter_module>::pause_datapath;
  local_60 = ll_filter_module_wrapper<ll_filter_module>::issue_oid_request;
  local_58 = ll_filter_module_wrapper<ll_filter_module>::complete_oid_request;
  local_38 = ll_filter_module_wrapper<ll_filter_module>::indicate_status;
  local_40 = ll_filter_module_wrapper<ll_filter_module>::notify_net_pnp_event;
  local_e8 = 0x3c003a;
  local_d8 = 0x4e004c;
  local_c8 = 0x10000e;
  local_b8 = 0;
  local_b0 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_50 = 0;
  local_48 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  iVar1 = NdisFRegisterFilterDriver(uVar2,this,&local_f8,this);
  return -(uint)(iVar1 != 0) & 0xc0000001;
}



===== McTemplateK0xjzqbr3_EtwWriteTransfer @ 14000a8cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xjzqbr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,wchar_t *param_6,undefined4 param_7,undefined8 param_8)

{
  longlong lVar1;
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = &local_res20;
  local_58 = param_5;
  local_60 = 8;
  local_50 = 0x10;
  if (param_6 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_38 = &param_7;
  local_3c = 0;
  local_28 = param_8;
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  local_20 = param_7;
  local_1c = 0;
  local_30 = 4;
  local_res20 = param_4;
  local_48 = param_6;
  McGenEventWrite_EtwWriteTransfer(param_6,&begin_attach_adapter,param_3,6,local_78);
  return;
}



===== allocated_receive_filter @ 14000a9a8 =====

/* public: __cdecl ll_vmswitch_oids::allocated_receive_filter::allocated_receive_filter(void)
   __ptr64 */

allocated_receive_filter * __thiscall
ll_vmswitch_oids::allocated_receive_filter::allocated_receive_filter(allocated_receive_filter *this)

{
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  return this;
}



===== allocated_switch @ 14000a9cc =====

/* public: __cdecl ll_vmswitch_oids::allocated_switch::allocated_switch(void) __ptr64 */

allocated_switch * __thiscall
ll_vmswitch_oids::allocated_switch::allocated_switch(allocated_switch *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  memset(this + 8,0,0x204);
  *(undefined4 *)(this + 0x20c) = 0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x214) = 0;
  allocated_vf::allocated_vf((allocated_vf *)(this + 0x218));
  *(undefined4 *)(this + 0x878) = 0;
  allocated_vport::allocated_vport((allocated_vport *)(this + 0x880));
  return this;
}



===== allocated_vf @ 14000aa34 =====

/* public: __cdecl ll_vmswitch_oids::allocated_vf::allocated_vf(void) __ptr64 */

allocated_vf * __thiscall ll_vmswitch_oids::allocated_vf::allocated_vf(allocated_vf *this)

{
  *(undefined8 *)this = 0;
  *(undefined4 *)(this + 8) = 0;
  memset(this + 0xc,0,0x204);
  memset(this + 0x210,0,0x204);
  memset(this + 0x414,0,0x204);
  *(undefined2 *)(this + 0x618) = 0;
  *(undefined8 *)(this + 0x61a) = 0;
  *(undefined8 *)(this + 0x622) = 0;
  *(undefined8 *)(this + 0x62a) = 0;
  *(undefined8 *)(this + 0x632) = 0;
  *(undefined8 *)(this + 0x63a) = 0;
  *(undefined8 *)(this + 0x642) = 0;
  *(undefined8 *)(this + 0x64a) = 0;
  *(undefined8 *)(this + 0x652) = 0;
  *(undefined2 *)(this + 0x65a) = 0;
  *(undefined4 *)(this + 0x65c) = 0;
  return this;
}



===== allocated_vport @ 14000aad4 =====

/* public: __cdecl ll_vmswitch_oids::allocated_vport::allocated_vport(void) __ptr64 */

allocated_vport * __thiscall
ll_vmswitch_oids::allocated_vport::allocated_vport(allocated_vport *this)

{
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  memset(this + 0x10,0,0x204);
  *(undefined2 *)(this + 0x214) = 0;
  *(undefined8 *)(this + 0x218) = 0;
  *(undefined4 *)(this + 0x220) = 0;
  *(undefined8 *)(this + 0x228) = 0;
  *(undefined8 *)(this + 0x230) = 0;
  *(undefined4 *)(this + 0x238) = 0;
  memset(this + 0x240,0,0xa8);
  *(undefined4 *)(this + 0x2e8) = 0;
  return this;
}



===== ll_filter_module @ 14000ab50 =====

/* public: __cdecl ll_filter_module::ll_filter_module(class ll_filter_driver * __ptr64,void *
   __ptr64) __ptr64 */

ll_filter_module * __thiscall
ll_filter_module::ll_filter_module(ll_filter_module *this,ll_filter_driver *param_1,void *param_2)

{
  ll_filter_module *plVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  *(ll_filter_driver **)this = param_1;
  *(void **)(this + 8) = param_2;
  memset(this + 0x14,0,0xe14);
  plVar1 = this + 0x10;
  *(undefined4 *)plVar1 = 0;
  ll_vmswitch_oids::allocated_switch::allocated_switch((allocated_switch *)(this + 0x18));
  *(undefined4 *)(this + 0xb88) = 0;
  ll_vmswitch_oids::allocated_receive_filter::allocated_receive_filter
            ((allocated_receive_filter *)(this + 0xb90));
  *(undefined8 *)(this + 0xbc0) = 0;
  ExInitializeRundownProtection();
  *(ll_filter_module **)(this + 0xbc8) = plVar1;
  *(undefined8 *)(this + 0xbd0) = 0;
  *(undefined4 *)(this + 0xbd8) = 0;
  this[0xbdc] = (ll_filter_module)0x0;
  *(undefined8 *)(this + 0xbe0) = 0;
  *(undefined8 *)(this + 0xbe8) = 0;
  *(undefined8 *)(this + 0xbf0) = 0;
  KeInitializeEvent(this + 0xbe0,0,0);
  *(undefined8 *)(this + 0xbf8) = 0;
  *(undefined8 *)(this + 0xc00) = 0;
  *(undefined8 *)(this + 0xc08) = 0;
  KeInitializeEvent(this + 0xbf8,0,0);
  *(ll_filter_module **)(this + 0xc10) = plVar1;
  *(undefined8 *)(this + 0xc18) = 0;
  *(undefined8 *)(this + 0xc20) = 0;
  *(ll_filter_module **)(this + 0xc28) = plVar1;
  this[0xc30] = (ll_filter_module)0x0;
  memset(this + 0xc38,0,0xf8);
  *(undefined8 *)(this + 0xd30) = 0;
  *(undefined8 *)(this + 0xd38) = 0;
  iVar3 = EtwActivityIdControl(3);
  puVar4 = auStack_28;
  if (iVar3 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(0x38);
    puVar4 = auStack_20;
  }
  *(undefined8 *)(this + 0xd40) = 0;
  *(undefined4 *)(this + 0xd48) = 0;
  *(undefined8 *)(this + 0xd4c) = 0;
  *(undefined8 *)(this + 0xd54) = 0;
  *(undefined4 *)(this + 0xd5c) = 0;
  *(undefined8 *)(this + 0xd60) = 0;
  *(undefined8 *)(this + 0xd68) = 0;
  *(undefined4 *)(this + 0xd70) = 0;
  *(undefined8 *)(this + 0xd78) = 0;
  *(undefined8 *)(this + 0xd80) = 0;
  *(undefined8 *)(this + 0xd88) = 0;
  *(undefined8 *)(this + 0xd90) = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14000acc8;
  KeInitializeEvent(this + 0xd80,0,0);
  this[0xd98] = (ll_filter_module)0x0;
  *(undefined8 *)(this + 0xda0) = 0;
  *(undefined8 *)(this + 0xda8) = 0;
  *(undefined2 *)(this + 0xdb0) = 0;
  this[0xdb2] = (ll_filter_module)0x0;
  *(undefined8 *)(this + 0xdb4) = 0;
  *(undefined8 *)(this + 0xdc0) = 0;
  *(undefined8 *)(this + 0xdc8) = 0;
  *(undefined8 *)(this + 0xde0) = 0;
  *(code **)(this + 0xdd0) = ll_device_link::on_notification;
  *(ll_filter_module **)(this + 0xdd8) = this + 0xda8;
  *(undefined8 *)(this + 0xe00) = 0;
  *(undefined8 *)(this + 0xde8) = 0;
  *(undefined8 *)(this + 0xdf0) = 0;
  *(ll_filter_module **)(this + 0xdf8) = plVar1;
  *(undefined8 *)(this + 0xe08) = 0;
  *(undefined8 *)(this + 0xe10) = 0;
  *(undefined8 *)(this + 0xe18) = 0;
  *(undefined8 *)(this + 0xe20) = 0;
  return this;
}



===== NdisFPassthroughOidRequest @ 14000ad50 =====

/* int __cdecl NdisFPassthroughOidRequest(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64,unsigned
   long) */

int __cdecl NdisFPassthroughOidRequest(void *param_1,_NDIS_OID_REQUEST *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  longlong local_res20;
  
  local_res20 = 0;
  iVar2 = NdisAllocateCloneOidRequest(param_1,param_2,0x21766e6e,&local_res20);
  if (iVar2 == 0) {
    *(undefined8 *)(local_res20 + 0xd8) = 0;
    *(undefined8 *)(local_res20 + 0xe0) = 0;
    *(undefined4 *)(local_res20 + 0xd8) = 3;
    *(_NDIS_OID_REQUEST **)(local_res20 + 0xe0) = param_2;
    iVar2 = NdisFOidRequest(param_1,local_res20);
    if (iVar2 != 0x103) {
      iVar1 = *(int *)(local_res20 + 4);
      if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
        *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(local_res20 + 0x34);
        *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(local_res20 + 0x38);
      }
      else if (iVar1 == 0xc) {
        *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(local_res20 + 0x34);
        *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(local_res20 + 0x40);
        *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(local_res20 + 0x44);
        *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(local_res20 + 0x3c);
      }
      NdisFreeCloneOidRequest(param_1);
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 != 0xc)) {
      *(undefined4 *)(param_2 + 0x34) = 0;
      *(undefined4 *)(param_2 + 0x38) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x40) = 0;
      *(undefined4 *)(param_2 + 0x44) = 0;
      *(undefined4 *)(param_2 + 0x3c) = 0;
    }
  }
  return iVar2;
}



===== complete_oid_request @ 14000ae70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl ll_filter_module_wrapper<class
   ll_filter_module>::complete_oid_request(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64,int) */

void __cdecl
ll_filter_module_wrapper<ll_filter_module>::complete_oid_request
          (void *param_1,_NDIS_OID_REQUEST *param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  uVar1 = *(undefined8 *)((longlong)param_1 + 8);
  iVar4 = (*(int *)(param_2 + 0xd8) << 0x1e) >> 0x1e;
  if (iVar4 == -1) {
    iVar4 = *(int *)(param_2 + 4);
    lVar2 = *(longlong *)(param_2 + 0xe0);
    if (((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    }
    else if (iVar4 == 0xc) {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_2 + 0x34);
      *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(lVar2 + 0x44) = *(undefined4 *)(param_2 + 0x44);
      *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
    }
    NdisFreeCloneOidRequest(uVar1);
    NdisFOidRequestComplete(uVar1,lVar2,param_3);
  }
  else if (iVar4 == 0) {
    (**(code **)(param_2 + 0xe0))(*(undefined8 *)(param_2 + 0xd8));
  }
  else {
    if (iVar4 != 1) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(5);
      puVar5 = auStack_20;
    }
    *(int *)(param_2 + 0xd8) = param_3;
    lVar2 = *(longlong *)(param_2 + 0xe0);
    if (lVar2 != 0) {
      *(undefined8 *)(puVar5 + -8) = 0x14000aec9;
      KeSetEvent(lVar2,0,0);
    }
  }
  return;
}



===== detach_module @ 14000af70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static void __cdecl ll_filter_module_wrapper<class ll_filter_module>::detach_module(void
   * __ptr64) */

void __cdecl ll_filter_module_wrapper<ll_filter_module>::detach_module(void *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined8 uStack_50;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = *(undefined8 *)((longlong)param_1 + 0xe08);
  uVar5 = 3;
  local_28 = 0;
  uStack_20 = 0;
  iVar4 = EtwActivityIdControl();
  puVar6 = auStack_48;
  if (iVar4 != 0) {
    uVar5 = 0x38;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar6 = auStack_40;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    uVar2 = *(undefined8 *)((longlong)param_1 + 0xe08);
    *(undefined8 *)(puVar6 + -8) = 0x14000afdd;
    McTemplateK0x_EtwWriteTransfer(uVar5,&begin_detach_from_adapter,puVar6 + 0x20,uVar2);
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000afeb;
  ll_device_link::set_linked_device
            ((ll_device_link *)((longlong)param_1 + 0xda8),(ll_pnp_device *)0x0);
  *(undefined8 *)(puVar6 + -8) = 0x14000aff7;
  ll_netvsc_state::~ll_netvsc_state((ll_netvsc_state *)((longlong)param_1 + 0xc20));
  *(undefined8 *)(puVar6 + -8) = 0x14000b003;
  ll_vmswitch_indications::~ll_vmswitch_indications
            ((ll_vmswitch_indications *)((longlong)param_1 + 0xbd0));
  if (*(int *)((longlong)param_1 + 0x10) != 0) {
    pcVar3 = (code *)swi(0x2c);
    (*pcVar3)();
    puVar6 = puVar6 + 8;
  }
  if (*(int *)((longlong)param_1 + 0xb88) != 0) {
    pcVar3 = (code *)swi(0x2c);
    (*pcVar3)();
    puVar6 = puVar6 + 8;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000b025;
  ExFreePoolWithTag(param_1,0x21766e6e);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x14000b047;
    McTemplateK0x_EtwWriteTransfer(param_1,&end_detach_from_adapter,puVar6 + 0x20,uVar1);
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000b054;
  return;
}



===== indicate_status @ 14000b070 =====

/* private: static void __cdecl ll_filter_module_wrapper<class
   ll_filter_module>::indicate_status(void * __ptr64,struct _NDIS_STATUS_INDICATION * __ptr64) */

void __cdecl
ll_filter_module_wrapper<ll_filter_module>::indicate_status
          (void *param_1,_NDIS_STATUS_INDICATION *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (((((iVar1 == 0x40020010) || (iVar1 == 0x40020020)) || (iVar1 == 0x40020040)) ||
      ((iVar1 == 0x40020050 || (iVar1 == 0x40020052)))) || (iVar1 == 0x40020054)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 0x10) != 0) {
      McTemplateK0xd_EtwWriteTransfer
                (param_1,&status_indication_dropped,0,*(undefined8 *)((longlong)param_1 + 0xe08),
                 (char)iVar1);
    }
  }
  else if (iVar1 == 0x400200b0) {
    if (*(int *)(param_2 + 0x38) == 6) {
      ll_vf::set_mac_address((ll_vf *)((longlong)param_1 + 0x10),*(uchar **)(param_2 + 0x30));
    }
  }
  else if ((iVar1 == 0x40052000) || (iVar1 == 0x40052001)) {
    if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
      McTemplateK0x_EtwWriteTransfer
                (param_1,&vf_state_changed,0,*(undefined8 *)((longlong)param_1 + 0xe08));
    }
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_1 + 0xc20),9);
  }
  else {
    NdisFIndicateStatus(*(undefined8 *)((longlong)param_1 + 8));
  }
  return;
}



===== issue_oid_request @ 14000b150 =====

/* private: static int __cdecl ll_filter_module_wrapper<class
   ll_filter_module>::issue_oid_request(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64) */

int __cdecl
ll_filter_module_wrapper<ll_filter_module>::issue_oid_request
          (void *param_1,_NDIS_OID_REQUEST *param_2)

{
  void *pvVar1;
  code *pcVar2;
  propagation pVar3;
  undefined1 *puVar4;
  ulong uVar5;
  int *piVar6;
  int local_res8 [2];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res8[0] = 0;
  piVar6 = local_res8;
  pVar3 = ll_vf::issue_oid_request_inbound((ll_vf *)((longlong)param_1 + 0x10),param_2,piVar6);
  uVar5 = (ulong)piVar6;
  puVar4 = auStack_28;
  if (pVar3 != 0) {
    if (pVar3 != 1) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0x38);
      puVar4 = auStack_20;
    }
    pvVar1 = *(void **)((longlong)param_1 + 8);
    *(undefined8 *)(puVar4 + -8) = 0x14000b18f;
    local_res8[0] = NdisFPassthroughOidRequest(pvVar1,param_2,uVar5);
  }
  return local_res8[0];
}



===== notify_net_pnp_event @ 14000b1b0 =====

/* private: static int __cdecl ll_filter_module_wrapper<class
   ll_filter_module>::notify_net_pnp_event(void * __ptr64,struct _NET_PNP_EVENT_NOTIFICATION *
   __ptr64) */

int __cdecl
ll_filter_module_wrapper<ll_filter_module>::notify_net_pnp_event
          (void *param_1,_NET_PNP_EVENT_NOTIFICATION *param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 8) == 0xf) {
    ll_filter_module::on_predetach(param_1);
  }
  iVar1 = NdisFNetPnPEvent(*(undefined8 *)((longlong)param_1 + 8),param_2);
  return iVar1;
}



===== on_ndis_attach_filter @ 14000b1f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: int __cdecl ll_filter_module::on_ndis_attach_filter(struct _NDIS_FILTER_ATTACH_PARAMETERS
   * __ptr64) __ptr64 */

int __thiscall
ll_filter_module::on_ndis_attach_filter
          (ll_filter_module *this,_NDIS_FILTER_ATTACH_PARAMETERS *param_1)

{
  ll_vf *this_00;
  __uint64 _Var1;
  code *pcVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  puVar6 = auStack_68;
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(int *)(param_1 + 0x48) == 0) && (*(short *)(param_1 + 0x60) == 6)) {
    _Var1 = *(__uint64 *)(param_1 + 0x88);
    this_00 = (ll_vf *)(this + 0x10);
    lVar3 = ll_vf::initialize(this_00,*(void **)(this + 8),_Var1);
    if (lVar3 == 0) {
      ll_vf::set_mac_address(this_00,(uchar *)(param_1 + 0x62));
      local_34 = 0;
      local_38 = 0x8018d;
      iVar4 = NdisFSetAttributes(*(undefined8 *)(this + 8),this,&local_38);
      puVar6 = auStack_68;
      if (iVar4 == 0) {
        iVar4 = ll_vf::start(this_00);
        puVar6 = auStack_68;
      }
    }
    else {
      uVar5 = 3;
      local_30 = 0;
      uStack_28 = 0;
      iVar4 = EtwActivityIdControl(3,&local_30);
      puVar6 = auStack_68;
      if (iVar4 != 0) {
        uVar5 = 0x38;
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)();
        puVar6 = auStack_60;
      }
      if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 4) != 0) {
        *(long *)(puVar6 + 0x20) = lVar3;
        *(undefined8 *)(puVar6 + -8) = 0x14000b298;
        McTemplateK0xd_EtwWriteTransfer(uVar5,&fail_vf_initialize,puVar6 + 0x38,_Var1,puVar6[0x20]);
      }
      iVar4 = -0x3fffffff;
    }
  }
  else {
    iVar4 = -0x3ffeffe7;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000b2f0;
  return iVar4;
}



===== on_predetach @ 14000b30c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ll_filter_module::on_predetach(void) __ptr64 */

void __thiscall ll_filter_module::on_predetach(ll_filter_module *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ll_vf *this_00;
  undefined1 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = *(undefined8 *)(this + 0xe08);
  uVar5 = 3;
  local_28 = 0;
  uStack_20 = 0;
  iVar4 = EtwActivityIdControl(3,&local_28);
  puVar6 = auStack_48;
  if (iVar4 != 0) {
    uVar5 = 0x38;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar6 = auStack_40;
  }
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    uVar2 = *(undefined8 *)(this + 0xe08);
    *(undefined8 *)(puVar6 + -8) = 0x14000b379;
    McTemplateK0x_EtwWriteTransfer(uVar5,&begin_predetach_from_adapter,puVar6 + 0x20,uVar2);
  }
  this_00 = (ll_vf *)(this + 0x10);
  *(undefined8 *)(puVar6 + -8) = 0x14000b382;
  ll_vf::stop(this_00);
  if ((Microsoft_Windows_Hyper_V_Hierarchical_NIC_SwitchEnableBits & 1) != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x14000b39f;
    McTemplateK0x_EtwWriteTransfer(this_00,&end_predetach_from_adapter,puVar6 + 0x20,uVar1);
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000b3ac;
  return;
}



===== pause_datapath @ 14000b3c0 =====

/* private: static int __cdecl ll_filter_module_wrapper<class ll_filter_module>::pause_datapath(void
   * __ptr64,struct _NDIS_FILTER_PAUSE_PARAMETERS * __ptr64) */

int __cdecl
ll_filter_module_wrapper<ll_filter_module>::pause_datapath
          (void *param_1,_NDIS_FILTER_PAUSE_PARAMETERS *param_2)

{
  return 0;
}



===== ll_is_l1vh_supported @ 14000b3cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b40a) */
/* bool __cdecl ll_is_l1vh_supported(struct _DRIVER_OBJECT * __ptr64) */

bool __cdecl ll_is_l1vh_supported(_DRIVER_OBJECT *param_1)

{
  ulonglong *puVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_b8 [32];
  longlong *local_98;
  undefined4 *local_90;
  longlong local_88;
  undefined4 local_80 [2];
  ulonglong local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  wchar_t local_50 [28];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_78 = 0;
  uStack_70 = (wchar_t *)0x0;
  uVar3 = HviIsHypervisorMicrosoftCompatible();
  iVar4 = 0x40000003;
  if ((char)uVar3 != '\0') {
    puVar1 = (ulonglong *)cpuid(0x40000003);
    local_78 = *puVar1;
    uStack_70 = (wchar_t *)CONCAT44((int)puVar1[1],*(undefined4 *)((longlong)puVar1 + 0xc));
  }
  if ((local_78 & 0x100000000000) == 0) {
    local_78 = 0;
    uStack_70 = (wchar_t *)0x0;
    uVar3 = HviIsHypervisorMicrosoftCompatible();
    if ((char)uVar3 != '\0') {
      if (iVar4 == 0) {
        puVar1 = (ulonglong *)cpuid_basic_info(0);
      }
      else if (iVar4 == 1) {
        puVar1 = (ulonglong *)cpuid_Version_info(1);
      }
      else if (iVar4 == 2) {
        puVar1 = (ulonglong *)cpuid_cache_tlb_info(2);
      }
      else if (iVar4 == 3) {
        puVar1 = (ulonglong *)cpuid_serial_info(3);
      }
      else if (iVar4 == 4) {
        puVar1 = (ulonglong *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (iVar4 == 5) {
        puVar1 = (ulonglong *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (iVar4 == 6) {
        puVar1 = (ulonglong *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (iVar4 == 7) {
        puVar1 = (ulonglong *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (iVar4 == 9) {
        puVar1 = (ulonglong *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (iVar4 == 10) {
        puVar1 = (ulonglong *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (iVar4 == 0xb) {
        puVar1 = (ulonglong *)cpuid_Extended_Topology_info(0xb);
      }
      else if (iVar4 == 0xd) {
        puVar1 = (ulonglong *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (iVar4 == 0xf) {
        puVar1 = (ulonglong *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (iVar4 == -0x7ffffffe) {
        puVar1 = (ulonglong *)cpuid_brand_part1_info(0x80000002);
      }
      else if (iVar4 == -0x7ffffffd) {
        puVar1 = (ulonglong *)cpuid_brand_part2_info(0x80000003);
      }
      else if (iVar4 == -0x7ffffffc) {
        puVar1 = (ulonglong *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar1 = (ulonglong *)cpuid(iVar4);
      }
      local_78 = *puVar1;
      uStack_70 = (wchar_t *)CONCAT44((int)puVar1[1],*(undefined4 *)((longlong)puVar1 + 0xc));
    }
    if ((local_78 & 0x100000000) == 0) goto LAB_14000b45f;
LAB_14000b530:
    bVar2 = true;
  }
  else {
LAB_14000b45f:
    local_88 = 0;
    local_98 = &local_88;
    iVar4 = IoOpenDriverRegistryKey(param_1,2,1);
    if (iVar4 == 0) {
      builtin_wcsncpy(local_50 + 0x10,L"rivileges",10);
      builtin_wcsncpy(local_50,L"IgnorePartitionP",0x10);
      uStack_70 = local_50;
      local_78 = 0x340032;
      local_80[0] = 0;
      local_58 = 0;
      local_90 = local_80;
      local_98 = (longlong *)CONCAT44(local_98._4_4_,0x14);
      local_68 = 0;
      uStack_60 = 0;
      iVar4 = ZwQueryValueKey(local_88,&local_78,2,&local_68);
      if ((((iVar4 == 0) && (local_68._4_4_ == 4)) && ((int)uStack_60 == 4)) &&
         (uStack_60._4_4_ != 0)) {
        if (local_88 != 0) {
          ZwClose();
        }
        goto LAB_14000b530;
      }
    }
    if (local_88 != 0) {
      ZwClose();
    }
    bVar2 = false;
  }
  return bVar2;
}



===== ll_pnp_query_location_path @ 14000b570 =====

/* long __cdecl ll_pnp_query_location_path(struct _DEVICE_OBJECT * __ptr64,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<wchar_t
   * __ptr64,void (__cdecl*)(wchar_t * __ptr64) noexcept,&public: static void __cdecl
   pool_helpers<wchar_t * __ptr64,561409646>::free(wchar_t * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,wchar_t * __ptr64,wchar_t *
   __ptr64,0,std::nullptr_t> > > & __ptr64) */

long __cdecl
ll_pnp_query_location_path
          (_DEVICE_OBJECT *param_1,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<wchar_t*___ptr64,void_(__cdecl*)(wchar_t*___ptr64)_noexcept,&public:_static_void___cdecl_pool_helpers<wchar_t*___ptr64,561409646>::free(wchar_t*___ptr64),wistd::integral_constant<unsigned___int64,0>,wchar_t*___ptr64,wchar_t*___ptr64,0,std::nullptr_t>_>_>
          *param_2)

{
  int iVar1;
  longlong lVar2;
  uint local_res18 [2];
  int local_res20 [2];
  
  local_res18[0] = 0;
  local_res20[0] = 0;
  iVar1 = IoGetDevicePropertyData
                    (param_1,&DEVPKEY_Device_LocationPaths,0,0,0,0,local_res18,local_res20);
  if (iVar1 != 0) {
    if (iVar1 != -0x3fffffdd) {
      return iVar1;
    }
    if (local_res18[0] < 0xfffe) {
      lVar2 = ExAllocatePool2(0x40,local_res18[0],0x21766e6e);
      if (lVar2 == 0) {
        return -0x3fffffe9;
      }
      iVar1 = IoGetDevicePropertyData
                        (param_1,&DEVPKEY_Device_LocationPaths,0,0,local_res18[0],lVar2,local_res18,
                         local_res20);
      if (iVar1 == 0) {
        if (local_res20[0] == 0x2012) {
          if ((local_res18[0] & 1) != 0) {
            iVar1 = -0x7ffffffe;
            goto LAB_14000b69f;
          }
          if ((1 < local_res18[0]) &&
             (*(short *)(lVar2 + -2 + (ulonglong)(local_res18[0] >> 1) * 2) == 0)) {
            if (*(longlong *)param_2 != 0) {
              ExFreePoolWithTag(*(longlong *)param_2,0x21766e6e);
            }
            *(longlong *)param_2 = lVar2;
            return 0;
          }
        }
        iVar1 = -0x3ffff6f5;
      }
LAB_14000b69f:
      ExFreePoolWithTag(lVar2,0x21766e6e);
      return iVar1;
    }
  }
  return -0x3fffffff;
}



===== ll_pnp_query_vpci_serial_number @ 14000b6d0 =====

/* long __cdecl ll_pnp_query_vpci_serial_number(struct _DEVICE_OBJECT * __ptr64,unsigned long *
   __ptr64) */

long __cdecl ll_pnp_query_vpci_serial_number(_DEVICE_OBJECT *param_1,ulong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *param_2 = 0;
  lVar3 = IoAllocateIrp((char)param_1[0x4c] + '\x01',0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(_DEVICE_OBJECT **)(lVar1 + -0x20) = param_1;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    local_18 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_VPCI_INTERFACE_STANDARD;
    *(undefined8 **)(lVar1 + -0x30) = &local_48;
    *(undefined4 *)(lVar1 + -0x38) = 0x10038;
    iVar2 = IoSynchronousCallDriver(param_1,lVar3);
    if (iVar2 == 0) {
      if ((ulong)local_18 == 0) {
        iVar2 = -0x3ffffddb;
      }
      else {
        *param_2 = (ulong)local_18;
        iVar2 = 0;
      }
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== FxStubDriverUnloadCommon @ 14000b7bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140013658 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140013658 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_140013658 == 0x78) {
      ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140013658 + 0x78);
    }
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000b82c:
      if (ppvVar1 == (void **)0x0) goto LAB_14000b885;
      if (ppvVar2 <= ppvVar1) goto LAB_14000b89d;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_140013540,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&DAT_140013540,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if (((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) ||
       ((ppvVar1 + 0xf <= ppvVar2 && (*(uint *)ppvVar1 == 0x78)))) goto LAB_14000b82c;
LAB_14000b885:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000b89d:
  WdfVersionUnbind(&DAT_140013960,&DAT_140013540,WdfDriverGlobals);
  return;
}



===== entry @ 14000b8d0 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000b904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FxDriverEntryWorker(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  int iVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    lVar1 = ll_driver::entry((_DRIVER_OBJECT *)0x0,param_2);
  }
  else {
    _DAT_140013960 = 0x2080000;
    _DAT_140013968 = &DAT_140013720;
    RtlCopyUnicodeString(&DAT_140013960);
    p_Var3 = param_1;
    lVar1 = WdfVersionBind(param_1,&DAT_140013960,&DAT_140013540,&WdfDriverGlobals);
    if (-1 < lVar1) {
      lVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < lVar1) && (lVar1 = FxStubInitTypes(), -1 < lVar1)) {
        lVar1 = ll_driver::entry(param_1,param_2);
        if (-1 < lVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140013928 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",lVar1,&DAT_140013960);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140013658 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_140013540,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return lVar1;
}



===== FxStubDriverUnload @ 14000ba90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140013928 != (code *)0x0) && (DAT_140013928 != FxStubDriverUnload)) {
    (*DAT_140013928)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000bac4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000bae9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001364f < ppvVar2) break;
    if ((((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) &&
        ((&__KMDF_CLASS_BIND_END < ppvVar2 + 0xf || (*(uint *)ppvVar2 != 0x78)))) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140013658 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_140013540,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&DAT_140013540,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((longlong)ppvVar2 + (ulonglong)*(uint *)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000bc58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000bc75) */
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
    if ((void **)0x14001366f < ppvVar2) break;
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



===== EnqueueEvent @ 14000bd20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::EnqueueEvent(unsigned short) __ptr64 */

void __thiscall SmFx::StateMachineEngine::EnqueueEvent(StateMachineEngine *this,ushort param_1)

{
  StateMachineEngineImpl *this_00;
  StateMachineEngineImpl SVar1;
  bool bVar2;
  undefined2 uVar3;
  bool bVar4;
  
  this_00 = *(StateMachineEngineImpl **)this;
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this_00 + 1000);
  this_00[0x3f1] = SVar1;
  if (*(int *)(this_00 + 0x3e0) == 5) {
    if (param_1 == *(ushort *)(this_00 + 0x370)) {
      if (*(code **)(this_00 + 0x3a0) != (code *)0x0) {
        if (param_1 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined2 *)
                   (*(longlong *)(*(longlong *)(this_00 + 0x378) + 0x10) + (ulonglong)param_1 * 4);
        }
        (**(code **)(this_00 + 0x3a0))(*(undefined8 *)(this_00 + 0x380),uVar3);
      }
      *(undefined2 *)(this_00 + 0x370) = 0;
      goto LAB_14000bdae;
    }
    bVar4 = false;
  }
  else {
    bVar4 = *(int *)(this_00 + 0x3e0) == 1;
  }
  bVar2 = StateMachineEngineImpl::EnqueueEventWithDisposition(this_00,param_1);
  if (!bVar2) {
    return;
  }
  if (!bVar4) {
    KeReleaseSpinLock(this_00 + 1000,this_00[0x3f1]);
    return;
  }
LAB_14000bdae:
  this_00[0x3d7] = SVar1;
  this_00[0x3d6] = (StateMachineEngineImpl)0x0;
  if ((byte)SVar1 < 2) {
    *(void **)(this_00 + 0x3d8) = SystemReserved1[0xf];
  }
  else {
    *(undefined4 *)(this_00 + 0x3d8) = SystemReserved1[0x12]._4_4_;
  }
  StateMachineEngineImpl::ProcessEventQueue(this_00);
  return;
}



===== Initialize @ 14000be3c =====

/* public: long __cdecl SmFx::StateMachineEngine::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::Initialize(StateMachineEngine *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  long lVar1;
  StateMachineEngineImpl *this_00;
  int iVar2;
  
  iVar2 = 0x78466d53;
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar2 = *(int *)(param_1 + 0x18);
  }
  this_00 = (StateMachineEngineImpl *)ExAllocatePool2(0x40,0x420,iVar2);
  if (this_00 == (StateMachineEngineImpl *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memset(this_00,0,0x420);
    *(undefined2 *)(this_00 + 0x3d5) = 0x101;
    this_00[0x3d7] = (StateMachineEngineImpl)0x2;
    *(undefined8 *)(this_00 + 0x408) = 0;
    *(undefined8 *)(this_00 + 0x410) = 0;
    *(StateMachineEngine **)(this_00 + 0x418) = this;
    *(StateMachineEngineImpl **)this = this_00;
    lVar1 = StateMachineEngineImpl::Initialize(this_00,param_1);
    if (lVar1 < 0) {
      StateMachineEngineImpl::Destroy(this_00);
      *(undefined8 *)this = 0;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== <lambda_invoker_cdecl> @ 14000bf00 =====

void <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>
               (StateMachineEngineImpl *param_1)

{
  StateMachineEngineImpl *pSVar1;
  int iVar2;
  StateMachineEngineImpl SVar3;
  EngineState EVar4;
  ulonglong uVar5;
  
  pSVar1 = param_1 + 1000;
  SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  param_1[0x3f1] = SVar3;
  iVar2 = *(int *)(param_1 + 0x3e0);
  *(undefined4 *)(param_1 + 0x3e0) = 2;
  KeReleaseSpinLock(pSVar1,param_1[0x3f1]);
  *(undefined2 *)(param_1 + 0x3d6) = 1;
  *(void **)(param_1 + 0x3d8) = SystemReserved1[0xf];
  if (iVar2 == 3) {
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3c0));
    uVar5 = Feature_SMST__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      *(undefined8 *)(param_1 + 0x3c0) = 0;
      *(undefined8 *)(param_1 + 0x3c8) = 0;
      EVar4 = SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
      SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
      param_1[0x3f1] = SVar3;
      if (EVar4 != 1) {
        SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(param_1,EVar4);
        return;
      }
      goto LAB_14000bff8;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
  }
  else {
    if (iVar2 != 4) {
      return;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3c0));
    *(undefined8 *)(param_1 + 0x3c0) = 0;
    *(undefined8 *)(param_1 + 0x3c8) = 0;
  }
  SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  param_1[0x3f1] = SVar3;
LAB_14000bff8:
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(param_1);
  return;
}



===== ~StateMachineEngineImpl @ 14000c014 =====

/* private: __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl
          (StateMachineEngineImpl *this)

{
  Worker *this_00;
  StateMachineEngineImpl SVar1;
  
  **(undefined8 **)(this + 0x418) = 0;
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
  this[0x3f1] = SVar1;
  *(undefined4 *)(this + 0x3e0) = 0;
  KeReleaseSpinLock(this + 1000,this[0x3f1]);
  this_00 = (Worker *)(this + 0x3f8);
  if (*(longlong *)this_00 != 0) {
    IoFreeWorkItem();
    *(undefined8 *)this_00 = 0;
    *(undefined8 *)(this + 0x400) = 0;
    *(undefined8 *)(this + 0x408) = 0;
    *(undefined8 *)(this + 0x410) = 0;
  }
  if (*(longlong *)(this + 0x368) != 0) {
    ExFreePool();
    *(undefined8 *)(this + 0x368) = 0;
  }
  this[0x3f0] = (StateMachineEngineImpl)0x0;
  Worker::~Worker(this_00);
  this[0x3f0] = (StateMachineEngineImpl)0x0;
  return;
}



===== AddEventToEventQueue @ 14000c0d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue(unsigned short) __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue
          (StateMachineEngineImpl *this,ushort param_1)

{
  bool bVar1;
  undefined2 uVar2;
  StateMachineEngineImpl SVar3;
  
  SVar3 = (StateMachineEngineImpl)((char)this[0x3d3] + 1U & 0xf);
  if (SVar3 == this[0x3d2]) {
    ReportExceptionWithLockHeld(this,2,param_1,0);
    bVar1 = false;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d3] * 2 + 0x340) = param_1;
    uVar2 = 0;
    this[0x3d3] = SVar3;
    if (*(code **)(this + 0x3a0) != (code *)0x0) {
      if (param_1 != 0) {
        uVar2 = *(undefined2 *)
                 (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_1 * 4);
      }
      (**(code **)(this + 0x3a0))(*(undefined8 *)(this + 0x380),uVar2);
    }
    bVar1 = true;
  }
  return bVar1;
}



===== Destroy @ 14000c160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(void) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(StateMachineEngineImpl *this)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(code **)(this + 0x3b0);
  uVar2 = *(undefined8 *)(this + 0x380);
  ~StateMachineEngineImpl(this);
  ExFreePool(this);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(uVar2);
  }
  return;
}



===== EnqueueEventWithDisposition @ 14000c1bc =====

/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition(unsigned short)
   __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition
          (StateMachineEngineImpl *this,ushort param_1)

{
  char cVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined6 in_register_00000012;
  ulonglong uVar4;
  undefined7 uVar5;
  StateMachineEngineImpl SVar6;
  
  uVar4 = CONCAT62(in_register_00000012,param_1);
  cVar1 = *(char *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + 2 + (ulonglong)param_1 * 4);
  if (cVar1 != '\x01') {
    uVar5 = (undefined7)(uVar4 >> 8);
    if (cVar1 == '\x02') {
      SVar6 = this[0x3d2];
      uVar4 = CONCAT71(uVar5,SVar6);
      bVar2 = false;
      if (SVar6 != this[0x3d3]) {
        do {
          if (*(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340) == param_1) {
            bVar2 = true;
          }
          else {
            uVar3 = (ulonglong)(byte)SVar6;
            SVar6 = (StateMachineEngineImpl)((char)SVar6 + 1U & 0xf);
            *(ushort *)(this + uVar3 * 2 + 0x340) = *(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340);
          }
          uVar4 = CONCAT71((int7)(uVar4 >> 8),(char)uVar4 + '\x01') & 0xffffffffffffff0f;
        } while (SUB81(uVar4,0) != this[0x3d3]);
        if (bVar2) {
          *(ushort *)(this + (ulonglong)((byte)((char)this[0x3d3] - 1) & 0xf) * 2 + 0x340) = param_1
          ;
          goto LAB_14000c282;
        }
      }
    }
    else {
      if (cVar1 != '\x03') {
LAB_14000c282:
        KeReleaseSpinLock(this + 1000,CONCAT71((int7)(uVar4 >> 8),this[0x3f1]));
        return false;
      }
      for (uVar4 = CONCAT71(uVar5,this[0x3d2]); SUB81(uVar4,0) != this[0x3d3];
          uVar4 = CONCAT71((int7)(uVar4 >> 8),(char)SUB81(uVar4,0) + '\x01') & 0xffffffffffffff0f) {
        if (*(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340) == param_1) goto LAB_14000c282;
      }
    }
  }
  bVar2 = AddEventToEventQueue(this,param_1);
  return bVar2;
}



===== ExecuteCurrentState @ 14000c2a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(void) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(StateMachineEngineImpl *this)

{
  ushort *puVar1;
  StateMachineEngineImpl SVar2;
  ushort uVar3;
  ushort uVar4;
  EngineState EVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  EVENT_ACTION *pEVar9;
  StateMachineEngineImpl SVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  do {
    uVar3 = 0;
    if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
      uVar3 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = *(longlong *)(this + 0x378);
    lVar11 = (ulonglong)uVar3 * 0x10 + *(longlong *)(lVar6 + 0x18);
    if ((*(byte *)(lVar11 + 4) & 1) == 0) {
      if (*(char *)(lVar11 + 3) == '\x01') {
        uVar12 = (ulonglong)*(ushort *)(lVar6 + 2);
      }
      else {
        uVar12 = 0;
      }
    }
    else {
      uVar3 = (*(code *)**(undefined8 **)(lVar11 + 8))(*(undefined8 *)(this + 0x380));
      lVar6 = *(longlong *)(this + 0x378);
      uVar12 = (ulonglong)uVar3;
    }
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (ulonglong)
               *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = uVar13 * 0x10 + *(longlong *)(lVar6 + 0x18);
    uVar3 = *(ushort *)(lVar6 + 4);
    if ((uVar3 & 0x20) != 0) {
      uVar4 = 1;
      uVar8 = 0;
      do {
        uVar7 = (ulonglong)((int)uVar8 + 1);
        if ((uVar3 & uVar4) != uVar4) {
          uVar7 = uVar8;
        }
        uVar4 = uVar4 * 2;
        uVar8 = uVar7;
      } while (uVar4 != 0x20);
      puVar1 = *(ushort **)(*(longlong *)(lVar6 + 8) + uVar7 * 8);
      if (puVar1 != (ushort *)0x0) {
        SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
        this[0x3f1] = SVar2;
        SVar2 = this[0x3d2];
        SVar10 = SVar2;
        if (SVar2 != this[0x3d3]) {
          do {
            lVar6 = 0;
            uVar3 = *(ushort *)(this + (ulonglong)(byte)SVar10 * 2 + 0x340);
            uVar4 = *puVar1;
            while (uVar4 != 0) {
              if (uVar4 == uVar3) {
                LogTransition(this,7,(ushort)uVar13,uVar3,0,(char)this[0x3d4] + 0xff);
                goto LAB_14000c40b;
              }
              lVar6 = lVar6 + 1;
              uVar4 = puVar1[lVar6];
            }
            uVar8 = (ulonglong)(byte)SVar2;
            SVar2 = (StateMachineEngineImpl)((char)SVar2 + 1U & 0xf);
            *(ushort *)(this + uVar8 * 2 + 0x340) = uVar3;
LAB_14000c40b:
            SVar10 = (StateMachineEngineImpl)((char)SVar10 + 1U & 0xf);
          } while (SVar10 != this[0x3d3]);
        }
        this[0x3d3] = SVar2;
        KeReleaseSpinLock(this + 1000,this[0x3f1]);
      }
    }
    if (*(char *)(lVar11 + 3) == '\x01') {
      local_38 = 0;
      uStack_30 = 0;
      FindActionForEvent(this,(ushort)uVar12,(EVENT_ACTION *)&local_38);
      pEVar9 = (EVENT_ACTION *)&local_38;
    }
    else {
      if (*(char *)(lVar11 + 3) != '\x03') {
        return 1;
      }
      local_48 = 6;
      local_40 = *(longlong *)(*(longlong *)(this + 0x378) + 8) +
                 (ulonglong)*(byte *)(lVar11 + 6) * 2;
      pEVar9 = (EVENT_ACTION *)&local_48;
    }
    EVar5 = ExecuteEventAction(this,pEVar9);
    if (EVar5 != 2) {
      return EVar5;
    }
  } while( true );
}



===== ExecuteEventAction @ 14000c4f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  byte bVar2;
  undefined8 uVar3;
  EngineState EVar4;
  MachineException MVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  undefined8 local_28;
  longlong lStack_20;
  
  iVar7 = *(int *)param_1;
  if (iVar7 == 1) {
    uVar8 = 0;
    if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
      uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    uVar6 = *(ushort *)(param_1 + 4);
    MVar5 = 1;
LAB_14000c8e9:
    ReportException(this,MVar5,uVar6,uVar8);
    return 1;
  }
  if (iVar7 == 2) {
    EVar4 = PopToStackDepth(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    EVar4 = ExitCurrentState(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    uVar8 = *(ushort *)(*(longlong *)(param_1 + 8) + 2);
    bVar2 = *(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 +
                     (ulonglong)uVar8 * 0x10);
    if ((((bVar2 & 2) == 0) || (this[0x3d6] != (StateMachineEngineImpl)0x0)) &&
       (((bVar2 & 1) == 0 || (this[0x3d7] == (StateMachineEngineImpl)0x0)))) {
      if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,1,uVar6,*(ushort *)(param_1 + 4),uVar8,(uchar)param_1[6]);
      *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = uVar8;
LAB_14000c8b0:
      this[0x3d5] = (StateMachineEngineImpl)0x0;
      return 2;
    }
    EVar4 = 3;
  }
  else {
    if (iVar7 != 3) {
      if (iVar7 == 4) {
        local_28 = *(undefined8 *)param_1;
        lStack_20 = *(longlong *)(param_1 + 8);
        do {
          EVar4 = PopToStackDepth(this,(EVENT_ACTION *)&local_28);
          if (EVar4 != 1) {
            return EVar4;
          }
          EVar4 = ExitCurrentState(this,(EVENT_ACTION *)&local_28);
          if (EVar4 != 1) {
            return EVar4;
          }
          SVar1 = this[0x3d4];
          if ((byte)SVar1 < 2) {
            uVar8 = 0;
            uVar6 = 0;
            if (SVar1 != (StateMachineEngineImpl)0x0) goto LAB_14000c66c;
          }
          else {
            uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
LAB_14000c66c:
            uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
          }
          LogTransition(this,3,uVar6,local_28._4_2_,uVar8,local_28._6_1_);
          *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = 0;
          SVar1 = this[0x3d4];
          this[0x3d4] = (StateMachineEngineImpl)((char)SVar1 + -1);
          this[0x3d5] = (StateMachineEngineImpl)0x0;
          FindActionForEvent(this,*(ushort *)(lStack_20 + 2),(EVENT_ACTION *)&local_28);
          if ((int)local_28 != 4) {
            if ((StateMachineEngineImpl)((char)SVar1 + -1) == (StateMachineEngineImpl)0x0) {
              return 1;
            }
            iVar7 = (int)local_28;
            if ((int)local_28 == 5) {
              iVar7 = 1;
            }
            local_28 = CONCAT44(local_28._4_4_,iVar7);
            EVar4 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
            return EVar4;
          }
        } while( true );
      }
      if (iVar7 == 5) {
        return 1;
      }
      if (iVar7 != 6) {
        return 1;
      }
      SVar1 = this[0x3d4];
      if (SVar1 == (StateMachineEngineImpl)0x0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
      }
      if (SVar1 != this[0x360]) {
        uVar6 = **(ushort **)(param_1 + 8);
        bVar2 = *(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 +
                         (ulonglong)uVar6 * 0x10);
        if ((((bVar2 & 2) != 0) && (this[0x3d6] == (StateMachineEngineImpl)0x0)) ||
           (((bVar2 & 1) != 0 && (this[0x3d7] != (StateMachineEngineImpl)0x0)))) {
          uVar3 = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
          *(undefined8 *)(this + 0x3c8) = uVar3;
          return 3;
        }
        LogTransition(this,5,uVar8,0,uVar6,(uchar)SVar1);
        *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)this[0x3d4] * 2) = uVar6;
        this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + '\x01');
        goto LAB_14000c8b0;
      }
      uVar6 = 0;
      MVar5 = 3;
      goto LAB_14000c8e9;
    }
    uVar8 = 0;
    if (*(longlong *)(*(longlong *)(param_1 + 8) + 8) == 0) {
      if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,6,uVar8,*(ushort *)(param_1 + 4),
                    *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                    (uchar)param_1[6]);
      return 1;
    }
    bVar2 = *(byte *)(*(longlong *)(param_1 + 8) + 2);
    if ((((bVar2 & 2) == 0) || (this[0x3d6] != (StateMachineEngineImpl)0x0)) &&
       (((bVar2 & 1) == 0 || (this[0x3d7] == (StateMachineEngineImpl)0x0)))) {
      if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,2,uVar8,*(ushort *)(param_1 + 4),
                    *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                    (uchar)param_1[6]);
      (**(code **)(*(longlong *)(param_1 + 8) + 8))(*(undefined8 *)(this + 0x380));
      return 1;
    }
    EVar4 = 4;
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x3c8) = uVar3;
  return EVar4;
}



===== ExitCurrentState @ 14000c914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  short *psVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ushort uVar8;
  
  if (this[0x3d5] == (StateMachineEngineImpl)0x0) {
    this[0x3d5] = (StateMachineEngineImpl)0x1;
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = (ulonglong)uVar5 * 0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
    uVar5 = *(ushort *)(lVar6 + 4);
    if ((uVar5 & 0x40) != 0) {
      uVar8 = 1;
      uVar7 = 0;
      do {
        uVar4 = (ulonglong)((int)uVar7 + 1);
        if ((uVar5 & uVar8) != uVar8) {
          uVar4 = uVar7;
        }
        uVar8 = uVar8 * 2;
        uVar7 = uVar4;
      } while (uVar8 != 0x40);
      psVar1 = *(short **)(*(longlong *)(lVar6 + 8) + uVar4 * 8);
      if (((psVar1 != (short *)0x0) && (*(short *)(param_1 + 4) != *psVar1)) &&
         (iVar3 = (**(code **)(psVar1 + 4))(*(undefined8 *)(this + 0x380)), iVar3 != 1)) {
        uVar2 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
        *(undefined8 *)(this + 0x3c8) = uVar2;
        *(short *)(this + 0x370) = *psVar1;
        return 5;
      }
    }
  }
  return 1;
}



===== FindActionForEvent @ 14000ca14 =====

/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent(unsigned short,struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION * __ptr64) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent
          (StateMachineEngineImpl *this,ushort param_1,EVENT_ACTION *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  StateMachineEngineImpl SVar7;
  uint uVar8;
  longlong lVar9;
  
  SVar7 = this[0x3d4];
  *(ushort *)(param_2 + 4) = param_1;
  if (SVar7 == (StateMachineEngineImpl)0x0) {
    *(undefined4 *)param_2 = 1;
    param_2[6] = (EVENT_ACTION)0xff;
  }
  else {
    do {
      SVar7 = (StateMachineEngineImpl)((char)SVar7 + -1);
      lVar9 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)SVar7 * 2) *
              0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
      param_2[6] = (EVENT_ACTION)0xff;
      uVar4 = *(ushort *)(lVar9 + 4);
      uVar6 = (ulonglong)(uVar4 & 1);
      if ((uVar4 & 2) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 2;
              goto LAB_14000cb9a;
            }
            uVar5 = (ulonglong)((int)uVar5 + 1);
            puVar2 = puVar1 + uVar5 * 2;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((uVar4 & 1) + 1);
      }
      if ((uVar4 & 4) != 0) {
        uVar8 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 3;
              goto LAB_14000cb9a;
            }
            uVar8 = uVar8 + 1;
            puVar2 = puVar1 + (ulonglong)uVar8 * 8;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 8) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        while (uVar3 != 0) {
          if (uVar3 == param_1) {
            *(undefined4 *)param_2 = 5;
            goto LAB_14000cb9e;
          }
          uVar5 = (ulonglong)((int)uVar5 + 1);
          uVar3 = puVar1[uVar5];
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 0x10) != 0) {
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar6 = 0;
        uVar4 = *puVar1;
        if (uVar4 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar4 == param_1) {
              *(undefined4 *)param_2 = 4;
LAB_14000cb9a:
              *(ushort **)(param_2 + 8) = puVar2;
LAB_14000cb9e:
              *(StateMachineEngineImpl *)(param_2 + 6) = SVar7;
              return;
            }
            uVar6 = (ulonglong)((int)uVar6 + 1);
            puVar2 = puVar1 + uVar6 * 2;
            uVar4 = *puVar2;
          } while (uVar4 != 0);
        }
      }
      *(undefined4 *)param_2 = 1;
    } while ((*(char *)(lVar9 + 3) != '\x01') && (SVar7 != (StateMachineEngineImpl)0x0));
  }
  return;
}



===== Initialize @ 14000cbc4 =====

/* private: long __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize
          (StateMachineEngineImpl *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  longlong lVar6;
  StateMachineEngineImpl SVar7;
  int iVar8;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x378) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x380) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x388) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x390) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x398) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x3a0) = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  uVar3 = *(undefined4 *)(param_1 + 0x38);
  uVar4 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x3ac) = uVar2;
  *(undefined4 *)(this + 0x3b0) = uVar3;
  *(undefined4 *)(this + 0x3b4) = uVar4;
  *(undefined8 *)(this + 0x3b8) = *(undefined8 *)(param_1 + 0x40);
  if (this[0x3f0] == (StateMachineEngineImpl)0x0) {
    KeInitializeSpinLock(this + 1000);
    this[0x3f0] = (StateMachineEngineImpl)0x1;
  }
  SVar7 = (StateMachineEngineImpl)0x10;
  if (this[0x3b9] != (StateMachineEngineImpl)0x0) {
    SVar7 = this[0x3b9];
  }
  this[0x360] = SVar7;
  iVar8 = 0x78466d53;
  if (*(int *)(this + 0x390) != 0) {
    iVar8 = *(int *)(this + 0x390);
  }
  lVar6 = ExAllocatePool2(0x40,(ulonglong)(byte)SVar7 * 2,iVar8);
  *(longlong *)(this + 0x368) = lVar6;
  if (lVar6 == 0) {
LAB_14000cc7d:
    lVar5 = -0x3fffff66;
  }
  else {
    if (this[0x3b8] != (StateMachineEngineImpl)0x0) {
      uVar1 = *(undefined8 *)(param_1 + 0x10);
      if (*(longlong *)(this + 0x3f8) != 0) {
        return -0x3ffffe7c;
      }
      lVar6 = IoAllocateWorkItem(uVar1);
      *(longlong *)(this + 0x3f8) = lVar6;
      if (lVar6 == 0) goto LAB_14000cc7d;
      *(undefined8 *)(this + 0x400) = uVar1;
      *(code **)(this + 0x408) = <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>;
      *(StateMachineEngineImpl **)(this + 0x410) = this;
    }
    InitiateFirstRun(this);
    lVar5 = 0;
  }
  return lVar5;
}



===== InitiateFirstRun @ 14000ccfc =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(StateMachineEngineImpl *this)

{
  StateMachineEngineImpl *pSVar1;
  StateMachineEngineImpl SVar2;
  EngineState EVar3;
  undefined4 local_18;
  undefined4 local_14;
  longlong local_10;
  
  pSVar1 = this + 1000;
  SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  this[0x3f1] = SVar2;
  *(undefined4 *)(this + 0x3e0) = 2;
  KeReleaseSpinLock(pSVar1,this[0x3f1]);
  this[0x3d7] = SVar2;
  this[0x3d6] = (StateMachineEngineImpl)0x0;
  if ((byte)SVar2 < 2) {
    *(void **)(this + 0x3d8) = SystemReserved1[0xf];
  }
  else {
    *(undefined4 *)(this + 0x3d8) = SystemReserved1[0x12]._4_4_;
  }
  local_14 = 0;
  local_18 = 6;
  local_10 = *(longlong *)(*(byte **)(this + 0x378) + 8) + (ulonglong)**(byte **)(this + 0x378) * 2;
  EVar3 = ExecuteEventAction(this,(EVENT_ACTION *)&local_18);
  if (EVar3 == 2) {
    EVar3 = ExecuteCurrentState(this);
  }
  SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  this[0x3f1] = SVar2;
  if (EVar3 == 1) {
    ProcessEventQueue(this);
  }
  else {
    UpdateEngineState(this,EVar3);
  }
  return;
}



===== LogTransition @ 14000cdf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition(enum
   SmFx::TransitionType,unsigned short,unsigned short,unsigned short,unsigned char) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition
          (StateMachineEngineImpl *this,TransitionType param_1,ushort param_2,ushort param_3,
          ushort param_4,uchar param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  *(TransitionType *)(this + (ulonglong)(byte)this[0x3d0] * 0xc) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 4) = param_3;
  if ((param_1 - 2 & 0xfffffffb) == 0) {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 6) = param_4;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 6) = param_2;
  }
  uVar1 = 0;
  this[(ulonglong)(byte)this[0x3d0] * 0xc + 8] = (StateMachineEngineImpl)param_5;
  this[0x3d0] = (StateMachineEngineImpl)((char)this[0x3d0] + 1U & 0x3f);
  if (*(code **)(this + 0x3a8) != (code *)0x0) {
    if (param_4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_4 * 0x10);
    }
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_3 * 4);
    }
    if (param_2 != 0) {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_2 * 0x10);
    }
    (**(code **)(this + 0x3a8))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2,uVar3);
  }
  return;
}



===== PopToStackDepth @ 14000cf24 =====

/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  EngineState EVar2;
  ushort uVar3;
  
  if ((byte)param_1[6] + 1 < (uint)(byte)this[0x3d4]) {
    do {
      EVar2 = ExitCurrentState(this,param_1);
      if (EVar2 != 1) {
        return EVar2;
      }
      SVar1 = this[0x3d4];
      if ((byte)SVar1 < 2) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
      }
      LogTransition(this,4,*(ushort *)
                            (*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2),
                    *(ushort *)(param_1 + 4),uVar3,(char)SVar1 - 1);
      *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = 0;
      this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + -1);
      this[0x3d5] = (StateMachineEngineImpl)0x0;
    } while ((byte)param_1[6] + 1 < (uint)(byte)this[0x3d4]);
  }
  return 1;
}



===== ProcessEventQueue @ 14000d004 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(StateMachineEngineImpl *this)

{
  ushort uVar1;
  short sVar2;
  StateMachineEngineImpl SVar3;
  EngineState EVar4;
  StateMachineEngineImpl SVar5;
  uint uVar6;
  ulonglong uVar7;
  bool bVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  bVar8 = *(int *)(this + 0x3e0) == 5;
  *(undefined4 *)(this + 0x3e0) = 2;
LAB_14000d041:
  do {
    if (!bVar8) {
      SVar3 = this[0x3d2];
      SVar5 = this[0x3d3];
      uVar7 = (ulonglong)(byte)SVar3;
      if (SVar3 != SVar5) {
        while( true ) {
          local_28 = 0;
          uStack_20 = 0;
          uVar1 = *(ushort *)(this + uVar7 * 2 + 0x340);
          FindActionForEvent(this,uVar1,(EVENT_ACTION *)&local_28);
          if ((int)local_28 != 5) break;
          uVar7 = (ulonglong)(byte)((char)SUB81(uVar7,0) + 1) & 0xffffffffffffff0f;
          if (SUB81(uVar7,0) == SVar5) goto LAB_14000d0aa;
        }
        if (SUB81(uVar7,0) != SVar3) {
          do {
            uVar6 = (int)uVar7 - 1;
            SVar5 = (StateMachineEngineImpl)((byte)uVar6 & 0xf);
            *(undefined2 *)(this + uVar7 * 2 + 0x340) =
                 *(undefined2 *)(this + ((ulonglong)uVar6 & 0xf) * 2 + 0x340);
            SVar3 = this[0x3d2];
            uVar7 = (ulonglong)(byte)SVar5;
          } while (SVar5 != SVar3);
        }
        this[0x3d2] = (StateMachineEngineImpl)((char)SVar3 + 1U & 0xf);
        if (uVar1 != 0) goto LAB_14000d12f;
      }
LAB_14000d0aa:
      EVar4 = 1;
      goto LAB_14000d0af;
    }
    local_28 = *(undefined8 *)(this + 0x3c0);
    uStack_20 = *(undefined8 *)(this + 0x3c8);
    bVar8 = false;
LAB_14000d12f:
    KeReleaseSpinLock(this + 1000,this[0x3f1]);
    EVar4 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
    if (EVar4 == 2) {
      EVar4 = ExecuteCurrentState(this);
    }
    if (EVar4 == 1) {
      EVar4 = 2;
    }
    SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
    this[0x3f1] = SVar3;
    if (EVar4 == 5) {
      SVar3 = this[0x3d2];
      bVar8 = false;
      sVar2 = *(short *)(this + 0x370);
      SVar5 = SVar3;
      if (SVar3 != this[0x3d3]) {
        do {
          *(undefined2 *)(this + (ulonglong)(byte)SVar5 * 2 + 0x340) =
               *(undefined2 *)(this + (ulonglong)(byte)SVar3 * 2 + 0x340);
          if ((bVar8) || (*(short *)(this + (ulonglong)(byte)SVar3 * 2 + 0x340) != sVar2)) {
            SVar5 = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf);
          }
          else {
            bVar8 = true;
          }
          SVar3 = (StateMachineEngineImpl)((char)SVar3 + 1U & 0xf);
        } while (SVar3 != this[0x3d3]);
      }
      this[0x3d3] = SVar5;
      if (!bVar8) goto LAB_14000d0af;
      *(undefined2 *)(this + 0x370) = 0;
      bVar8 = true;
      goto LAB_14000d041;
    }
    if (EVar4 != 2) {
LAB_14000d0af:
      UpdateEngineState(this,EVar4);
      return;
    }
  } while( true );
}



===== ReportException @ 14000d218 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  StateMachineEngineImpl SVar1;
  
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
  this[0x3f1] = SVar1;
  ReportExceptionWithLockHeld(this,param_1,param_2,param_3);
  return;
}



===== ReportExceptionWithLockHeld @ 14000d28c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  undefined4 in_register_00000014;
  undefined2 uVar1;
  undefined2 uVar2;
  
  *(MachineException *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x300) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x304) = param_2;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x306) = param_3;
  this[0x3d1] = (StateMachineEngineImpl)((char)this[0x3d1] + 1U & 7);
  KeReleaseSpinLock(this + 1000,
                    CONCAT71((int7)(CONCAT44(in_register_00000014,param_1) >> 8),this[0x3f1]));
  uVar2 = 0;
  if (*(code **)(this + 0x398) != (code *)0x0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_2 * 4);
    }
    if (param_3 != 0) {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_3 * 0x10);
    }
    (**(code **)(this + 0x398))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2);
  }
  return;
}



===== UpdateEngineState @ 14000d374 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(enum
   SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState
          (StateMachineEngineImpl *this,EngineState param_1)

{
  undefined4 in_register_00000014;
  undefined7 uVar1;
  short sVar2;
  
  uVar1 = (undefined7)(CONCAT44(in_register_00000014,param_1) >> 8);
  if (param_1 - 3 < 2) {
    *(EngineState *)(this + 0x3e0) = param_1;
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
    IoQueueWorkItem(*(undefined8 *)(this + 0x3f8),
                    <lambda_9395206af589ac42132775cb7e45a067>::<lambda_invoker_cdecl>,1,this + 0x3f8
                   );
  }
  else if (param_1 == 5) {
    *(undefined4 *)(this + 0x3e0) = 5;
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
  }
  else {
    *(EngineState *)(this + 0x3e0) = param_1;
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      sVar2 = 0;
    }
    else {
      sVar2 = *(short *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
    if (sVar2 == 0) {
      Destroy(this);
    }
  }
  return;
}



===== Feature_SMST__private_IsEnabledDeviceUsageNoInline @ 14000d45c =====

ulonglong Feature_SMST__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SMST__private_featureState;
  if ((Feature_SMST__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SMST__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SMST__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SMST__private_IsEnabledFallback @ 14000d494 =====

void Feature_SMST__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SMST__private_descriptor);
  return;
}



===== <lambda_invoker_cdecl> @ 14000d4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_9395206af589ac42132775cb7e45a067>::<lambda_invoker_cdecl>
               (undefined8 param_1,longlong param_2)

{
  (**(code **)(param_2 + 0x10))(*(undefined8 *)(param_2 + 0x18));
  return;
}



===== ~Worker @ 14000d4d0 =====

/* public: __cdecl SmFx::Worker::~Worker(void) __ptr64 */

void __thiscall SmFx::Worker::~Worker(Worker *this)

{
  if (*(longlong *)this != 0) {
    IoFreeWorkItem();
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
  }
  return;
}



===== HviIsAnyHypervisorPresent @ 14000d510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000d544) */
/* WARNING: Removing unreachable block (ram,0x00014000d533) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 14000d56c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000d599) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== _guard_check_icall @ 14000d5d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000d5e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000d60c =====

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



===== __cpu_features_init @ 14000d680 =====

/* WARNING: Removing unreachable block (ram,0x00014000d6ea) */
/* WARNING: Removing unreachable block (ram,0x00014000d699) */
/* WARNING: Removing unreachable block (ram,0x00014000d68a) */

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



===== __security_check_cookie @ 14000d750 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000d790 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000d7c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000d7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000d7f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000d840 =====

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



===== memset @ 14000db40 =====

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



===== __memset_repmovs @ 14000dc80 =====

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



===== __memset_query @ 14000dd00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000dd80 =====

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
      if (&DAT_00000003 < param_3) {
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
        if (param_3 != &DAT_00000001) {
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



===== __memset_spec_ermsb_repmovsb @ 14000dec0 =====

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



===== __memset_spec_plain @ 14000df40 =====

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
      if (&DAT_00000003 < param_3) {
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
        if (param_3 != &DAT_00000001) {
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



===== wil_details_EvaluateFeatureDependencies @ 140016008 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_NVBugFixes2509__private_descriptor;
  ppuVar2 = &Feature_NVBugFixes2509__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140016043;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_1400160bd:
  while( true ) {
    if (&UNK_140012b5f < ppuVar3) {
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
      if (&UNK_140012b5f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140016043:
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
      if (&UNK_140012b5f < ppuVar2) goto LAB_1400160bd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_1400160bd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400160f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140016194;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140016194;
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
LAB_140016194:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140016200 =====

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
      for (ppuVar2 = &Feature_NVBugFixes2509__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_140012b5f < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 140016280 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400162a0 =====

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
  for (ppuVar3 = &Feature_NVBugFixes2509__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001639d;
  }
LAB_1400163a6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001639d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400163a6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001636e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001636e;
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
    if (&UNK_140012b5f < ppuVar3) goto LAB_1400163a6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001639d;
}



===== __security_init_cookie @ 140017008 =====

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



===== wil_InitializeFeatureStaging @ 14001703c =====

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
    for (ppuVar3 = &Feature_NVBugFixes2509__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400170c3;
    }
LAB_1400170fd:
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
LAB_1400170c3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400170fd;
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
    goto LAB_1400170fd;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140012b5f < ppuVar3) goto LAB_1400170fd;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400170c3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140017150 =====

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
  ppuVar4 = &Feature_NVBugFixes2509__private_descriptor;
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
            if (&UNK_140012b5f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001723a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001723a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001723a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140012b5f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


