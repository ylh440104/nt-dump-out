
===== connection_notification @ 140001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::connection_information && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,connection_information *param_1)

{
  connection_notification *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  connection_notification *pcVar4;
  connection_information *pcVar5;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar2 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = uVar2;
  lVar3 = 2;
  pcVar1 = this + 0x10;
  do {
    pcVar5 = param_1;
    pcVar4 = pcVar1;
    uVar2 = *(undefined8 *)(pcVar5 + 8);
    *(undefined8 *)pcVar4 = *(undefined8 *)pcVar5;
    *(undefined8 *)(pcVar4 + 8) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x18);
    *(undefined8 *)(pcVar4 + 0x10) = *(undefined8 *)(pcVar5 + 0x10);
    *(undefined8 *)(pcVar4 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x28);
    *(undefined8 *)(pcVar4 + 0x20) = *(undefined8 *)(pcVar5 + 0x20);
    *(undefined8 *)(pcVar4 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x38);
    *(undefined8 *)(pcVar4 + 0x30) = *(undefined8 *)(pcVar5 + 0x30);
    *(undefined8 *)(pcVar4 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x48);
    *(undefined8 *)(pcVar4 + 0x40) = *(undefined8 *)(pcVar5 + 0x40);
    *(undefined8 *)(pcVar4 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x58);
    *(undefined8 *)(pcVar4 + 0x50) = *(undefined8 *)(pcVar5 + 0x50);
    *(undefined8 *)(pcVar4 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x68);
    *(undefined8 *)(pcVar4 + 0x60) = *(undefined8 *)(pcVar5 + 0x60);
    *(undefined8 *)(pcVar4 + 0x68) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x78);
    *(undefined8 *)(pcVar4 + 0x70) = *(undefined8 *)(pcVar5 + 0x70);
    *(undefined8 *)(pcVar4 + 0x78) = uVar2;
    lVar3 = lVar3 + -1;
    pcVar1 = pcVar4 + 0x80;
    param_1 = pcVar5 + 0x80;
  } while (lVar3 != 0);
  uVar2 = *(undefined8 *)(pcVar5 + 0x88);
  *(undefined8 *)(pcVar4 + 0x80) = *(undefined8 *)(pcVar5 + 0x80);
  *(undefined8 *)(pcVar4 + 0x88) = uVar2;
  uVar2 = *(undefined8 *)(pcVar5 + 0x98);
  *(undefined8 *)(pcVar4 + 0x90) = *(undefined8 *)(pcVar5 + 0x90);
  *(undefined8 *)(pcVar4 + 0x98) = uVar2;
  *(undefined8 *)(pcVar4 + 0xa0) = *(undefined8 *)(pcVar5 + 0xa0);
  *(undefined2 *)(pcVar4 + 0xa8) = *(undefined2 *)(pcVar5 + 0xa8);
  return this;
}



===== connection_notification @ 1400010d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::stream_segment && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,stream_segment *param_1)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar1 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)this = uVar1;
  *(undefined8 *)(this + 8) = 1;
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x18) = uVar1;
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x18);
  *(undefined2 *)(this + 0x2c) = *(undefined2 *)(param_1 + 0x1c);
  return this;
}



===== connection_notification @ 140001154 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::connection_close && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,connection_close *param_1)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar1 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)this = uVar1;
  *(undefined8 *)(this + 8) = 3;
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x28) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x38) = uVar1;
  *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_1 + 0x30);
  return this;
}



===== connection_notification @ 1400011d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::port_open && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,port_open *param_1)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar1 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)(this + 8) = 4;
  *(undefined8 *)this = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x28) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x38) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(this + 0x48) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(this + 0x50) = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(this + 0x58) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(this + 0x60) = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(this + 0x68) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(this + 0x70) = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(this + 0x78) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x78);
  *(undefined8 *)(this + 0x80) = *(undefined8 *)(param_1 + 0x70);
  *(undefined8 *)(this + 0x88) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x88);
  *(undefined8 *)(this + 0x90) = *(undefined8 *)(param_1 + 0x80);
  *(undefined8 *)(this + 0x98) = uVar1;
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0x90);
  this[0xa4] = *(connection_notification *)(param_1 + 0x94);
  return this;
}



===== connection_notification @ 1400012a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::auth_connect && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,auth_connect *param_1)

{
  connection_notification *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  connection_notification *pcVar4;
  auth_connect *paVar5;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar2 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)(this + 8) = 5;
  *(undefined8 *)this = uVar2;
  lVar3 = 2;
  pcVar1 = this + 0x10;
  do {
    paVar5 = param_1;
    pcVar4 = pcVar1;
    uVar2 = *(undefined8 *)(paVar5 + 8);
    *(undefined8 *)pcVar4 = *(undefined8 *)paVar5;
    *(undefined8 *)(pcVar4 + 8) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x18);
    *(undefined8 *)(pcVar4 + 0x10) = *(undefined8 *)(paVar5 + 0x10);
    *(undefined8 *)(pcVar4 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x28);
    *(undefined8 *)(pcVar4 + 0x20) = *(undefined8 *)(paVar5 + 0x20);
    *(undefined8 *)(pcVar4 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x38);
    *(undefined8 *)(pcVar4 + 0x30) = *(undefined8 *)(paVar5 + 0x30);
    *(undefined8 *)(pcVar4 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x48);
    *(undefined8 *)(pcVar4 + 0x40) = *(undefined8 *)(paVar5 + 0x40);
    *(undefined8 *)(pcVar4 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x58);
    *(undefined8 *)(pcVar4 + 0x50) = *(undefined8 *)(paVar5 + 0x50);
    *(undefined8 *)(pcVar4 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x68);
    *(undefined8 *)(pcVar4 + 0x60) = *(undefined8 *)(paVar5 + 0x60);
    *(undefined8 *)(pcVar4 + 0x68) = uVar2;
    uVar2 = *(undefined8 *)(paVar5 + 0x78);
    *(undefined8 *)(pcVar4 + 0x70) = *(undefined8 *)(paVar5 + 0x70);
    *(undefined8 *)(pcVar4 + 0x78) = uVar2;
    lVar3 = lVar3 + -1;
    pcVar1 = pcVar4 + 0x80;
    param_1 = paVar5 + 0x80;
  } while (lVar3 != 0);
  uVar2 = *(undefined8 *)(paVar5 + 0x88);
  *(undefined8 *)(pcVar4 + 0x80) = *(undefined8 *)(paVar5 + 0x80);
  *(undefined8 *)(pcVar4 + 0x88) = uVar2;
  *(undefined4 *)(pcVar4 + 0x90) = *(undefined4 *)(paVar5 + 0x90);
  pcVar4[0x94] = *(connection_notification *)(paVar5 + 0x94);
  return this;
}



===== connection_notification @ 14000136c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::connection_aborted && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,connection_aborted *param_1)

{
  connection_notification *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  connection_notification *pcVar4;
  connection_aborted *pcVar5;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar2 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)(this + 8) = 6;
  *(undefined8 *)this = uVar2;
  lVar3 = 2;
  pcVar1 = this + 0x10;
  do {
    pcVar5 = param_1;
    pcVar4 = pcVar1;
    uVar2 = *(undefined8 *)(pcVar5 + 8);
    *(undefined8 *)pcVar4 = *(undefined8 *)pcVar5;
    *(undefined8 *)(pcVar4 + 8) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x18);
    *(undefined8 *)(pcVar4 + 0x10) = *(undefined8 *)(pcVar5 + 0x10);
    *(undefined8 *)(pcVar4 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x28);
    *(undefined8 *)(pcVar4 + 0x20) = *(undefined8 *)(pcVar5 + 0x20);
    *(undefined8 *)(pcVar4 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x38);
    *(undefined8 *)(pcVar4 + 0x30) = *(undefined8 *)(pcVar5 + 0x30);
    *(undefined8 *)(pcVar4 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x48);
    *(undefined8 *)(pcVar4 + 0x40) = *(undefined8 *)(pcVar5 + 0x40);
    *(undefined8 *)(pcVar4 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x58);
    *(undefined8 *)(pcVar4 + 0x50) = *(undefined8 *)(pcVar5 + 0x50);
    *(undefined8 *)(pcVar4 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x68);
    *(undefined8 *)(pcVar4 + 0x60) = *(undefined8 *)(pcVar5 + 0x60);
    *(undefined8 *)(pcVar4 + 0x68) = uVar2;
    uVar2 = *(undefined8 *)(pcVar5 + 0x78);
    *(undefined8 *)(pcVar4 + 0x70) = *(undefined8 *)(pcVar5 + 0x70);
    *(undefined8 *)(pcVar4 + 0x78) = uVar2;
    lVar3 = lVar3 + -1;
    pcVar1 = pcVar4 + 0x80;
    param_1 = pcVar5 + 0x80;
  } while (lVar3 != 0);
  uVar2 = *(undefined8 *)(pcVar5 + 0x88);
  *(undefined8 *)(pcVar4 + 0x80) = *(undefined8 *)(pcVar5 + 0x80);
  *(undefined8 *)(pcVar4 + 0x88) = uVar2;
  *(undefined4 *)(pcVar4 + 0x90) = *(undefined4 *)(pcVar5 + 0x90);
  pcVar4[0x94] = *(connection_notification *)(pcVar5 + 0x94);
  return this;
}



===== connection_notification @ 140001434 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl network_filtering::connection_notification::connection_notification(struct
   network_filtering::volume_update && __ptr64) __ptr64 */

connection_notification * __thiscall
network_filtering::connection_notification::connection_notification
          (connection_notification *this,volume_update *param_1)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_18 = 0;
  uVar1 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)this = uVar1;
  *(undefined8 *)(this + 8) = 7;
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x10) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x28) = uVar1;
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x20);
  return this;
}



===== clone_udp_nbl @ 1400014b0 =====

/* public: __cdecl net_buffer_list::clone_udp_nbl(struct _NET_BUFFER_LIST * __ptr64,struct cmsghdr *
   __ptr64,void * __ptr64,bool) __ptr64 */

undefined8 __thiscall
net_buffer_list::clone_udp_nbl
          (net_buffer_list *this,_NET_BUFFER_LIST *param_1,cmsghdr *param_2,void *param_3,
          bool param_4)

{
  uint uVar1;
  net_buffer_list *_Src;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  net_buffer_list *pnVar6;
  ulonglong _Size;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong in_stack_ffffffffffffffb8;
  
  pnVar6 = (net_buffer_list *)0x0;
  if (*(longlong *)(this + 8) == 1) {
    pnVar6 = this + 0x10;
  }
  if (pnVar6 == (net_buffer_list *)0x0) {
LAB_140001634:
    uVar4 = 0xc0000017;
  }
  else {
    if (*(uint *)(pnVar6 + 0x88) != 0) {
      memmove(this + *(longlong *)(this + 0xb0) * 8 + (ulonglong)*(uint *)(this + 0xac) + 0xc0,
              param_2,(ulonglong)*(uint *)(pnVar6 + 0x88));
    }
    uVar1 = *(uint *)(this + 0xac);
    pnVar6 = this + 0xc0;
    uVar7 = 0;
    plVar8 = (longlong *)0x0;
    for (puVar5 = *(undefined8 **)(param_1 + 8); puVar5 != (undefined8 *)0x0;
        puVar5 = (undefined8 *)*puVar5) {
      _Size = (ulonglong)*(uint *)(puVar5 + 3);
      if (*(uint *)(puVar5 + 3) != 0) {
        _Src = (net_buffer_list *)
               NdisGetDataBuffer(puVar5,_Size,pnVar6,1,
                                 in_stack_ffffffffffffffb8 & 0xffffffff00000000);
        if (_Src != pnVar6) {
          if (_Src == (net_buffer_list *)0x0) goto LAB_140001634;
          memmove(pnVar6,_Src,_Size);
        }
      }
      in_stack_ffffffffffffffb8 = 0;
      lVar2 = IoAllocateMdl(pnVar6,_Size,0,0,0);
      *(longlong *)(this + uVar7 * 8 + (ulonglong)uVar1 + 0xc0) = lVar2;
      uVar7 = (ulonglong)((int)uVar7 + 1);
      if (lVar2 == 0) goto LAB_140001634;
      MmBuildMdlForNonPagedPool(lVar2);
      pnVar6 = pnVar6 + _Size;
      if (plVar8 == (longlong *)0x0) {
        in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffff00000000;
        FwpsAllocateNetBufferAndNetBufferList0();
        if (*(longlong *)this == 0) goto LAB_140001634;
        plVar3 = *(longlong **)(*(longlong *)this + 8);
      }
      else {
        plVar3 = (longlong *)NdisAllocateNetBuffer(param_3,lVar2);
        if (plVar3 == (longlong *)0x0) goto LAB_140001634;
        *plVar8 = (longlong)plVar3;
      }
      plVar8 = plVar3;
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== net_buffer_list @ 140001658 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl net_buffer_list::net_buffer_list(struct reinjection_meta_data) __ptr64 */

net_buffer_list * __thiscall
net_buffer_list::net_buffer_list(net_buffer_list *this,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  net_buffer_list *pnVar10;
  size_t _Size;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  lVar5 = *param_2;
  lVar6 = param_2[1];
  lVar7 = param_2[2];
  lVar8 = param_2[3];
  *(undefined8 *)this = 0;
  *(longlong *)(this + 8) = lVar5;
  *(longlong *)(this + 0x10) = lVar6;
  local_18 = 0;
  lVar5 = param_2[4];
  lVar6 = param_2[5];
  *(longlong *)(this + 0x18) = lVar7;
  *(longlong *)(this + 0x20) = lVar8;
  lVar7 = param_2[6];
  lVar8 = param_2[7];
  *(longlong *)(this + 0x28) = lVar5;
  *(longlong *)(this + 0x30) = lVar6;
  lVar5 = param_2[8];
  lVar6 = param_2[9];
  *(longlong *)(this + 0x38) = lVar7;
  *(longlong *)(this + 0x40) = lVar8;
  lVar7 = param_2[10];
  lVar8 = param_2[0xb];
  *(longlong *)(this + 0x48) = lVar5;
  *(longlong *)(this + 0x50) = lVar6;
  lVar5 = param_2[0xc];
  lVar6 = param_2[0xd];
  *(longlong *)(this + 0x58) = lVar7;
  *(longlong *)(this + 0x60) = lVar8;
  lVar7 = param_2[0x10];
  lVar8 = param_2[0x11];
  *(longlong *)(this + 0x68) = lVar5;
  *(longlong *)(this + 0x70) = lVar6;
  lVar5 = param_2[0xf];
  *(longlong *)(this + 0x78) = param_2[0xe];
  *(longlong *)(this + 0x80) = lVar5;
  lVar5 = param_2[0x12];
  uVar1 = *(undefined4 *)((longlong)param_2 + 0x94);
  lVar6 = param_2[0x13];
  uVar2 = *(undefined4 *)((longlong)param_2 + 0x9c);
  *(longlong *)(this + 0x88) = lVar7;
  *(longlong *)(this + 0x90) = lVar8;
  lVar7 = param_2[0x14];
  uVar3 = *(undefined4 *)((longlong)param_2 + 0xa4);
  lVar8 = param_2[0x15];
  uVar4 = *(undefined4 *)((longlong)param_2 + 0xac);
  *(int *)(this + 0x98) = (int)lVar5;
  *(undefined4 *)(this + 0x9c) = uVar1;
  *(int *)(this + 0xa0) = (int)lVar6;
  *(undefined4 *)(this + 0xa4) = uVar2;
  *(int *)(this + 0xa8) = (int)lVar7;
  *(undefined4 *)(this + 0xac) = uVar3;
  *(int *)(this + 0xb0) = (int)lVar8;
  *(undefined4 *)(this + 0xb4) = uVar4;
  uVar9 = KeQueryInterruptTimePrecise(&local_18);
  *(undefined8 *)(this + 0xb8) = uVar9;
  _Size = (ulonglong)*(uint *)(this + 0xac) + *(longlong *)(this + 0xb0) * 8;
  pnVar10 = (net_buffer_list *)0x0;
  if (*(longlong *)(this + 8) == 1) {
    pnVar10 = this + 0x10;
  }
  if (pnVar10 != (net_buffer_list *)0x0) {
    _Size = _Size + *(uint *)(pnVar10 + 0x88);
  }
  memset(this + 0xc0,0,_Size);
  return this;
}



===== ~net_buffer_list @ 140001758 =====

/* public: __cdecl net_buffer_list::~net_buffer_list(void) __ptr64 */

void __thiscall net_buffer_list::~net_buffer_list(net_buffer_list *this)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (*(longlong *)this != 0) {
    FwpsFreeNetBufferList0();
  }
  uVar1 = *(uint *)(this + 0xac);
  uVar2 = 0;
  if (*(longlong *)(this + 0xb0) != 0) {
    do {
      if (*(longlong *)(this + uVar2 * 8 + (ulonglong)uVar1 + 0xc0) != 0) {
        IoFreeMdl();
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ulonglong *)(this + 0xb0));
  }
  return;
}



===== WPP_SF_l @ 1400017c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_l(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_18 [2];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = local_18;
  local_28 = 0;
  local_30 = 4;
  local_18[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WppClassicProviderCallback @ 140001830 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hMpTeEventProviderProv @ 140001860 =====

void _tlgDefineProvider_annotation__Tlgg_hMpTeEventProviderProv(void)

{
  return;
}



===== <lambda_invoker_cdecl> @ 140001870 =====

undefined8
<lambda_61d4af8ef1711536e00056b4c5ac14f8>::<lambda_invoker_cdecl>(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = IoGetRequestorProcessId(param_2);
  *(undefined4 *)(lVar1 + 0x108) = uVar2;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== <lambda_invoker_cdecl> @ 1400018d0 =====

undefined8
<lambda_232e68d14d6adad7442257a881ea395f>::<lambda_invoker_cdecl>(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1f0);
  *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x1f0) = 0;
  if (lVar1 != 0) {
    wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
    ::
    ~wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
              ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                *)(lVar1 + 0xb0));
    implementation::
    stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
    ~stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
              ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *)
               (lVar1 + 0x18));
    ExFreePoolWithTag(lVar1,0x666e6477);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== <lambda_invoker_cdecl> @ 140001950 =====

undefined8
<lambda_a3286718b1279327f4c7fb65275b0eb3>::<lambda_invoker_cdecl>(longlong param_1,longlong param_2)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x108) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== mj_device_control<_DEVICE_OBJECT_*> @ 140001984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
    ::mj_device_control<_DEVICE_OBJECT_*>(longlong param_1,_DRIVER_OBJECT *param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_78 [32];
  longlong local_58;
  longlong *local_50;
  longlong local_48;
  longlong **local_40;
  longlong *local_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (param_3 == 0x226005) {
    local_58 = *(longlong *)param_2;
    *(undefined8 *)param_2 = 0;
    local_38 = *(longlong **)(param_1 + 8);
    local_50 = &local_58;
    local_40 = &local_38;
    local_48 = lVar2;
    iVar1 = <lambda_5d2e64d17421fe7c2438746c2610e24e>::operator()
                      (&local_50,param_2,(stream_settings *)0x0);
LAB_140001bc8:
    *(int *)(local_58 + 0x30) = iVar1;
    *(undefined8 *)(local_58 + 0x38) = 0;
    IofCompleteRequest(local_58,0);
    local_58 = 0;
  }
  else {
    if (param_3 == 0x226009) {
      local_58 = *(longlong *)param_2;
      local_38 = &local_58;
      *(undefined8 *)param_2 = 0;
      local_30 = lVar2;
      iVar1 = invoke<<lambda_4eccc180bbb91a8dcaf4e5c84fb42260>_>(&local_38);
      goto LAB_140001bc8;
    }
    if (param_3 != 0x226011) {
      if (param_3 == 0x226015) {
        local_58 = *(longlong *)param_2;
        *(undefined8 *)param_2 = 0;
        iVar1 = set_ip_address_exclusions(lVar2,&local_58);
        if (*(longlong *)param_2 == 0) {
          return iVar1;
        }
        *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000120;
        lVar2 = *(longlong *)param_2;
      }
      else {
        if (param_3 == 0x226019) {
          local_58 = *(longlong *)param_2;
          local_38 = &local_58;
          *(undefined8 *)param_2 = 0;
          local_30 = lVar2;
          iVar1 = invoke<<lambda_138ae38aa7c7d99cf235087d414160ee>_>(&local_38);
          goto LAB_140001bc8;
        }
        if (param_3 == 0x22601d) {
          lVar2 = *(longlong *)param_2;
          *(undefined8 *)param_2 = 0;
          lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1f0);
          *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x1f0) = 0;
          if (lVar3 != 0) {
            wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
            ::
            ~wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                      ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                        *)(lVar3 + 0xb0));
            implementation::
            stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
            ~stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                      ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                        *)(lVar3 + 0x18));
            ExFreePoolWithTag(lVar3,0x666e6477);
          }
          *(undefined4 *)(lVar2 + 0x30) = 0;
          *(undefined8 *)(lVar2 + 0x38) = 0;
          IofCompleteRequest(lVar2,0);
          if (*(longlong *)param_2 != 0) {
            *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000120;
            *(undefined8 *)(*(longlong *)param_2 + 0x38) = 0;
            IofCompleteRequest(*(undefined8 *)param_2,0);
            *(undefined8 *)param_2 = 0;
          }
          return 0;
        }
        lVar3 = *(longlong *)param_2;
        if (param_3 == 0x22a00e) {
          *(undefined8 *)param_2 = 0;
          if (*(longlong *)(lVar2 + 0x1f0) == 0) goto LAB_140001a32;
          local_58 = lVar3;
          iVar1 = stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                  ::get_connection_notification<implementation::irp>
                            ((stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                              *)(*(longlong *)(lVar2 + 0x1f0) + 8),&local_58);
          goto LAB_140001bef;
        }
        iVar1 = -0x3ffffff0;
        *(undefined4 *)(lVar3 + 0x30) = 0xc0000010;
        lVar2 = *(longlong *)param_2;
      }
      *(undefined8 *)(lVar2 + 0x38) = 0;
      goto LAB_140001c05;
    }
    lVar3 = *(longlong *)param_2;
    *(undefined8 *)param_2 = 0;
    local_58 = lVar3;
    if (*(longlong *)(lVar2 + 0x1f0) == 0) {
LAB_140001a32:
      iVar1 = -0x3ffffff3;
    }
    else {
      iVar1 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
              ::inject_stream_segment<implementation::irp>
                        ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                          *)(*(longlong *)(lVar2 + 0x1f0) + 0xb0),
                         (irp<implementation::irp> *)&local_58);
      lVar3 = local_58;
    }
    *(int *)(lVar3 + 0x30) = iVar1;
    *(undefined8 *)(lVar3 + 0x38) = 0;
    IofCompleteRequest(lVar3,0);
  }
LAB_140001bef:
  if (*(longlong *)param_2 == 0) {
    return iVar1;
  }
  *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000120;
  *(undefined8 *)(*(longlong *)param_2 + 0x38) = 0;
LAB_140001c05:
  IofCompleteRequest(*(undefined8 *)param_2,0);
  *(undefined8 *)param_2 = 0;
  return iVar1;
}



===== operator() @ 140001c40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int <lambda_5d2e64d17421fe7c2438746c2610e24e>::operator()
              (undefined8 *param_1,_DRIVER_OBJECT *param_2,stream_settings *param_3)

{
  registration *this;
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  wfp_registration *this_00;
  
  if (*(uint *)(*(longlong *)(*(longlong *)*param_1 + 0xb8) + 0x10) < 0xf) {
    return -0x3fffffdd;
  }
  puVar2 = *(undefined4 **)(*(longlong *)*param_1 + 0x18);
  *(undefined4 *)(param_1[1] + 0x40) = *puVar2;
  *(undefined4 *)(param_1[1] + 0x44) = puVar2[1];
  *(undefined1 *)(param_1[1] + 0x49) = *(undefined1 *)(puVar2 + 2);
  *(undefined1 *)(param_1[1] + 0x4a) = *(undefined1 *)((longlong)puVar2 + 10);
  *(undefined1 *)(param_1[1] + 0x48) = *(undefined1 *)((longlong)puVar2 + 9);
  *(undefined1 *)(param_1[1] + 0x4b) = 0;
  if (*(longlong *)(param_1[1] + 0x1f0) == 0) {
    param_3 = (stream_settings *)0x666e6477;
    param_2 = (_DRIVER_OBJECT *)0x238;
    piVar5 = (int *)ExAllocatePoolWithTag(0x600);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      if ((char)ExPoolZeroingNativelySupported == '\0') {
        memset(piVar5,0,0x238);
      }
      lVar3 = param_1[1];
      param_2 = *(_DRIVER_OBJECT **)param_1[2];
      param_3 = (stream_settings *)(lVar3 + 0x40);
      piVar5 = driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
               ::network_stream_filter::
               network_stream_filter<_DRIVER_OBJECT_*,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
                         (piVar5,param_2,param_3,(stream_settings *)(lVar3 + 0x44),
                          (bool *)(lVar3 + 0x49),(bool *)(lVar3 + 0x48),(bool *)(lVar3 + 0x4a),
                          (bool *)(lVar3 + 0x4b),
                          (running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                           *)(lVar3 + 0x50),
                          (excluded_addresses<implementation::avl_table> *)(lVar3 + 0x110),
                          *(bool *)((longlong)puVar2 + 0xb),*(bool *)(puVar2 + 3),
                          *(bool *)((longlong)puVar2 + 0xd),*(bool *)((longlong)puVar2 + 0xe));
    }
    *(int **)(param_1[1] + 0x1f0) = piVar5;
    lVar3 = param_1[1];
    piVar5 = *(int **)(lVar3 + 0x1f0);
    if (piVar5 == (int *)0x0) {
      return -0x3fffffe9;
    }
    iVar1 = *piVar5;
    *(undefined1 *)(piVar5 + 1) = 1;
    if (iVar1 < 0) {
      lVar4 = *(longlong *)(lVar3 + 0x1f0);
      if (lVar4 != 0) {
        wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
        ::
        ~wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                  ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                    *)(lVar4 + 0xb0));
        implementation::
        stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
        ~stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                  ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                    *)(lVar4 + 0x18));
        ExFreePoolWithTag(lVar4,0x666e6477);
      }
      *(undefined8 *)(lVar3 + 0x1f0) = 0;
      return iVar1;
    }
  }
  lVar3 = *(longlong *)(param_1[1] + 0x1f0);
  this = (registration *)(lVar3 + 0x1a8);
  if (**(char **)(lVar3 + 0xd0) == '\0') {
    if (*(int *)(lVar3 + 0x1f0) != 0) {
      FwpsCalloutUnregisterById0();
      this_00 = (wfp_registration *)(ulonglong)*(uint *)(lVar3 + 0x1ec);
      FwpsCalloutUnregisterById0();
      *(undefined8 *)(lVar3 + 0x1ec) = 0;
      wfp_registration::unregister_resource_assignment(this_00);
    }
  }
  else {
    implementation::wfp_callout::registration::register_resource_assignment_callouts
              (this,(_func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
                     *)param_2,(_func_void_ushort_uint___uint64 *)param_3);
  }
  if (**(char **)(lVar3 + 0xe0) == '\0') {
    if (*(int *)(lVar3 + 0x1f8) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(lVar3 + 500));
      *(undefined8 *)(lVar3 + 500) = 0;
      wfp_registration::unregister_auth_connect((wfp_registration *)(lVar3 + 0x1b8));
    }
  }
  else {
    implementation::wfp_callout::registration::register_auth_connect_callouts
              (this,(_func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
                     *)param_2,(_func_void_ushort_uint___uint64 *)param_3);
  }
  if (**(char **)(lVar3 + 200) != '\0') {
    implementation::wfp_callout::registration::register_datagram_callouts
              (this,(_func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
                     *)param_2,(_func_void_ushort_uint___uint64 *)param_3);
  }
  if ((*(char *)(lVar3 + 0x232) == '\0') &&
     ((**(char **)(lVar3 + 0xc0) == '\x02' || (**(char **)(lVar3 + 200) == '\x02')))) {
    implementation::wfp_callout::registration::register_transport_callouts
              (this,(_func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
                     *)param_2,(_func_void_ushort_uint___uint64 *)param_3);
  }
  return 0;
}



===== invoke<<lambda_4eccc180bbb91a8dcaf4e5c84fb42260>_> @ 140001f18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int invoke<<lambda_4eccc180bbb91a8dcaf4e5c84fb42260>_>(undefined8 *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_88 [32];
  undefined1 *local_68;
  undefined4 local_58;
  undefined1 local_54;
  ulonglong local_50;
  undefined4 local_48 [2];
  int local_40;
  undefined1 uStack_3c;
  undefined3 uStack_3b;
  longlong lStack_38;
  undefined1 local_30 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  uVar5 = *(uint *)(*(longlong *)(*(longlong *)*param_1 + 0xb8) + 0x10);
  if (7 < uVar5) {
    puVar6 = *(undefined1 **)(*(longlong *)*param_1 + 0x18);
    uVar2 = (ulonglong)*(uint *)(puVar6 + 4) * 2 + 8;
    if ((7 < uVar2) && (uVar2 <= uVar5)) {
      local_50 = (ulonglong)(uint)local_50;
      local_68 = puVar6 + 4;
      _local_40 = 0;
      lStack_38 = 0;
      shared_ptr<path_list<implementation::path_list>_>::
      shared_ptr<path_list<implementation::path_list>_><bool_const&___ptr64,wchar_t_const_(&___ptr64)[0],unsigned_int_const&___ptr64>
                ((shared_ptr<path_list<implementation::path_list>_> *)&local_40,(ulonglong)uVar5,
                 puVar6 + 1,puVar6 + 8);
      lVar8 = lStack_38;
      iVar3 = local_40;
      _local_40 = CONCAT14(1,local_40);
      if (local_40 < 0) {
        shared_ptr<path_list<implementation::path_list>_>::
        ~shared_ptr<path_list<implementation::path_list>_>
                  ((shared_ptr<path_list<implementation::path_list>_> *)&local_40);
        return iVar3;
      }
      lVar7 = param_1[1];
      lStack_38 = 0;
      uVar4 = *puVar6;
      local_58 = 0xc000000d;
      local_54 = 0;
      local_50 = lVar8;
      KeAcquireInStackQueuedSpinLock(lVar7 + 0x58,local_30);
      *(undefined1 *)(lVar7 + 0x60) = uVar4;
      swap<shared_ptr<path_list<implementation::path_list>_>_>
                ((shared_ptr<path_list<implementation::path_list>_> *)(lVar7 + 0x68),
                 (shared_ptr<path_list<implementation::path_list>_> *)&local_58);
      KeReleaseInStackQueuedSpinLock(local_30);
      local_48[0] = 0;
      ExNotifyCallback(*(undefined8 *)(lVar7 + 0xf0),local_48,0);
      shared_ptr<path_list<implementation::path_list>_>::
      ~shared_ptr<path_list<implementation::path_list>_>
                ((shared_ptr<path_list<implementation::path_list>_> *)&local_58);
      lVar8 = lStack_38;
      if (lStack_38 != 0) {
        LOCK();
        piVar1 = (int *)(lStack_38 + 0x30);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if ((iVar3 == 1) && (lStack_38 != 0)) {
          if (*(longlong *)(lStack_38 + 0x20) != 0) {
            ExFreePoolWithTag(*(longlong *)(lStack_38 + 0x20),0x666e6477);
          }
          lVar7 = *(longlong *)(lVar8 + 0x18);
          if (lVar7 != 0) {
            ExFreePoolWithTag(lVar7,0x666e6477);
          }
          ExFreePoolWithTag(lVar8,0x666e6477);
        }
      }
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== invoke<<lambda_138ae38aa7c7d99cf235087d414160ee>_> @ 1400020cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int invoke<<lambda_138ae38aa7c7d99cf235087d414160ee>_>(undefined8 *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined1 local_58 [8];
  undefined4 local_50;
  undefined1 local_4c;
  ulonglong local_48;
  undefined4 local_40 [2];
  int local_38;
  undefined1 uStack_34;
  undefined3 uStack_33;
  longlong lStack_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  uVar4 = *(uint *)(*(longlong *)(*(longlong *)*param_1 + 0xb8) + 0x10);
  if (3 < uVar4) {
    local_68 = *(uint **)(*(longlong *)*param_1 + 0x18);
    uVar2 = (ulonglong)*local_68 * 2 + 4;
    if ((3 < uVar2) && (uVar2 <= uVar4)) {
      local_48 = (ulonglong)(uint)local_48;
      local_58[0] = 0;
      _local_38 = 0;
      lStack_30 = 0;
      shared_ptr<path_list<implementation::path_list>_>::
      shared_ptr<path_list<implementation::path_list>_><bool_const&___ptr64,wchar_t_const_(&___ptr64)[0],unsigned_int_const&___ptr64>
                ((shared_ptr<path_list<implementation::path_list>_> *)&local_38,uVar2,local_58,
                 local_68 + 1);
      iVar3 = local_38;
      _local_38 = CONCAT14(1,local_38);
      if (local_38 < 0) {
        shared_ptr<path_list<implementation::path_list>_>::
        ~shared_ptr<path_list<implementation::path_list>_>
                  ((shared_ptr<path_list<implementation::path_list>_> *)&local_38);
        return iVar3;
      }
      lVar5 = param_1[1];
      local_50 = 0xc000000d;
      local_4c = 0;
      local_48 = lStack_30;
      lStack_30 = 0;
      KeAcquireInStackQueuedSpinLock(lVar5 + 0x58,local_28);
      swap<shared_ptr<path_list<implementation::path_list>_>_>
                ((shared_ptr<path_list<implementation::path_list>_> *)(lVar5 + 0x78),
                 (shared_ptr<path_list<implementation::path_list>_> *)&local_50);
      KeReleaseInStackQueuedSpinLock(local_28);
      local_40[0] = 0;
      ExNotifyCallback(*(undefined8 *)(lVar5 + 0xf0),local_40,0);
      shared_ptr<path_list<implementation::path_list>_>::
      ~shared_ptr<path_list<implementation::path_list>_>
                ((shared_ptr<path_list<implementation::path_list>_> *)&local_50);
      lVar5 = lStack_30;
      if (lStack_30 != 0) {
        LOCK();
        piVar1 = (int *)(lStack_30 + 0x30);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if ((iVar3 == 1) && (lStack_30 != 0)) {
          if (*(longlong *)(lStack_30 + 0x20) != 0) {
            ExFreePoolWithTag(*(longlong *)(lStack_30 + 0x20),0x666e6477);
          }
          lVar6 = *(longlong *)(lVar5 + 0x18);
          if (lVar6 != 0) {
            ExFreePoolWithTag(lVar6,0x666e6477);
          }
          ExFreePoolWithTag(lVar5,0x666e6477);
        }
      }
      return 0;
    }
  }
  return -0x3fffffdd;
}



===== set_ip_address_exclusions @ 140002274 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
::set_ip_address_exclusions(longlong param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong *puVar2;
  __uint64 _Var3;
  longlong lVar4;
  undefined4 uVar5;
  undefined1 auStack_58 [32];
  undefined1 local_38 [12];
  undefined4 local_2c;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = *(uint *)(*(longlong *)(*param_2 + 0xb8) + 0x10);
  if (7 < uVar1) {
    puVar2 = *(ulonglong **)(*param_2 + 0x18);
    if ((*puVar2 < 0x200000000000000) && (*puVar2 * 0x80 + 8 <= (ulonglong)uVar1)) {
      _Var3 = *puVar2;
      local_2c = 0;
      KeAcquireInStackQueuedSpinLock(param_1 + 0x118,local_38);
      while( true ) {
        lVar4 = RtlEnumerateGenericTableAvl(param_1 + 0x120,1);
        if (lVar4 == 0) break;
        RtlDeleteElementGenericTableAvl(param_1 + 0x120,lVar4);
      }
      while( true ) {
        lVar4 = RtlEnumerateGenericTableAvl(param_1 + 0x188,1);
        if (lVar4 == 0) break;
        RtlDeleteElementGenericTableAvl(param_1 + 0x188,lVar4);
      }
      excluded_addresses<implementation::avl_table>::reload
                ((excluded_addresses<implementation::avl_table> *)(param_1 + 0x110),
                 (sockaddr_storage *)(puVar2 + 1),_Var3);
      KeReleaseInStackQueuedSpinLock(local_38);
      uVar5 = 0;
      goto LAB_140002392;
    }
  }
  uVar5 = 0xc0000023;
LAB_140002392:
  *(undefined4 *)(*param_2 + 0x30) = uVar5;
  *(undefined8 *)(*param_2 + 0x38) = 0;
  IofCompleteRequest(*param_2,0);
  *param_2 = 0;
  return uVar5;
}



===== get_connection_notification<implementation::irp> @ 1400023e0 =====

/* public: auto __cdecl stream_handler<class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> > >::get_connection_notification<class implementation::irp>(class
   irp<class implementation::irp>) __ptr64 */

undefined4 __thiscall
stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
::get_connection_notification<implementation::irp>
          (stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
           *this,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong local_18 [2];
  
  lVar1 = *param_2;
  if (*(uint *)(*(longlong *)(lVar1 + 8) + 0x28) < 0x13a) {
    if (lVar1 != 0) {
      *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
      *(undefined8 *)(*param_2 + 0x38) = 0;
      IofCompleteRequest(*param_2,0);
      *param_2 = 0;
    }
    uVar2 = 0xc0000023;
  }
  else {
    *param_2 = 0;
    if (*(uint *)(*(longlong *)(lVar1 + 8) + 0x28) < 0x13a) {
      if (lVar1 != 0) {
        *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
        *(undefined8 *)(lVar1 + 0x38) = 0;
        IofCompleteRequest(lVar1,0);
      }
      uVar2 = 0xc0000023;
    }
    else {
      local_18[0] = lVar1;
      uVar2 = implementation::
              stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
              get_connection_notification
                        ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                          *)(this + 0x10),local_18);
    }
    if (*param_2 != 0) {
      *(undefined4 *)(*param_2 + 0x30) = 0xc0000120;
      *(undefined8 *)(*param_2 + 0x38) = 0;
      IofCompleteRequest(*param_2,0);
      *param_2 = 0;
    }
  }
  return uVar2;
}



===== get_connection_notification @ 1400024cc =====

/* public: __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::get_connection_notification(class irp<class
   implementation::irp>) __ptr64 */

undefined8 __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
get_connection_notification
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this,
          irp<implementation::irp> *param_2)

{
  queue<implementation::queue,network_filtering::connection_notification> *this_00;
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_48;
  longlong lStack_40;
  longlong local_38 [2];
  
  local_48 = 0;
  lStack_40 = 0;
  cVar2 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_2,0,(irp_buffer<network_filtering::connection_notification> *)&local_48);
  if (cVar2 == '\0') {
    *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000023;
    *(undefined8 *)(*(longlong *)param_2 + 0x38) = 0;
    IofCompleteRequest(*(undefined8 *)param_2,0);
    uVar4 = 0xc0000023;
    *(undefined8 *)param_2 = 0;
  }
  else {
    this_00 = (queue<implementation::queue,network_filtering::connection_notification> *)(this + 8);
    local_48 = 0;
    lStack_40 = 0;
    queue<implementation::queue,network_filtering::connection_notification>::pop_front(this_00);
    lVar1 = *(longlong *)param_2;
    *(undefined8 *)param_2 = 0;
    if (lStack_40 == 0) {
      IoCsqInsertIrp(this + 0x58,lVar1,0);
      local_48 = 0;
      lStack_40 = 0;
      queue<implementation::queue,network_filtering::connection_notification>::pop_front(this_00);
      lVar1 = lStack_40;
      if (lStack_40 != 0) {
        lVar3 = IoCsqRemoveNextIrp(this + 0x58,0);
        local_48 = CONCAT35(local_48._5_3_,0xc000000d);
        lStack_40 = lVar1;
        if (lVar3 == 0) {
          queue<implementation::queue,network_filtering::connection_notification>::push_front
                    (this_00,&local_48);
        }
        else {
          local_38[0] = lVar3;
          complete_irp(this,local_38,&local_48);
        }
      }
      if (*(longlong *)param_2 != 0) {
        *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000120;
        *(undefined8 *)(*(longlong *)param_2 + 0x38) = 0;
        IofCompleteRequest(*(undefined8 *)param_2,0);
        *(undefined8 *)param_2 = 0;
      }
      uVar4 = 0x103;
    }
    else {
      local_48 = CONCAT35(local_48._5_3_,0xc000000d);
      local_38[0] = lVar1;
      complete_irp(this,local_38,&local_48);
      if (*(longlong *)param_2 != 0) {
        *(undefined4 *)(*(longlong *)param_2 + 0x30) = 0xc0000120;
        *(undefined8 *)(*(longlong *)param_2 + 0x38) = 0;
        IofCompleteRequest(*(undefined8 *)param_2,0);
        *(undefined8 *)param_2 = 0;
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== output_buffer<network_filtering::connection_notification> @ 14000267c =====

/* public: auto __cdecl irp<class implementation::irp>::output_buffer<struct
   network_filtering::connection_notification>(unsigned __int64,struct irp_buffer<struct
   network_filtering::connection_notification> & __ptr64) __ptr64 */

ulonglong __thiscall
irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
          (irp<implementation::irp> *this,__uint64 param_1,
          irp_buffer<network_filtering::connection_notification> *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(*(longlong *)this + 8);
  uVar1 = *(uint *)(lVar2 + 0x28);
  if ((ulonglong)uVar1 < param_1 + 0x13a) {
    uVar4 = param_1 + 0x13a & 0xffffffffffffff00;
  }
  else {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      uVar3 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      uVar3 = *(undefined8 *)(lVar2 + 0x18);
    }
    *(undefined8 *)param_2 = uVar3;
    *(ulonglong *)(param_2 + 8) = (ulonglong)uVar1;
    uVar4 = (ulonglong)(*(longlong *)param_2 != 0);
  }
  return uVar4;
}



===== <lambda_invoker_cdecl> @ 140002700 =====

void <lambda_51f4c9b3ed17c868c2b4c5b1fddc973c>::<lambda_invoker_cdecl>
               (longlong param_1,longlong param_2)

{
  longlong local_18 [3];
  
  local_18[0] = param_2;
  driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
  ::mj_device_control<_DEVICE_OBJECT_*>
            (param_1,(_DRIVER_OBJECT *)local_18,*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18));
  return;
}



===== <lambda_invoker_cdecl> @ 140002730 =====

void <lambda_e25fcd0e3f24cd4b7b87a2fb5312e9cb>::<lambda_invoker_cdecl>(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  excluded_addresses<implementation::avl_table>::~excluded_addresses<implementation::avl_table>
            ((excluded_addresses<implementation::avl_table> *)(lVar1 + 0x110));
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  ::
  ~running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
            ((running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
              *)(lVar1 + 0x50));
  if (-1 < *(int *)(lVar1 + 0x28)) {
    IoDeleteSymbolicLink(lVar1 + 0x30);
  }
  if (*(longlong *)(lVar1 + 0x20) != 0) {
    WppCleanupKm();
    IoDeleteDevice(*(undefined8 *)(lVar1 + 0x20));
  }
  return;
}



===== ~running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_> @ 140002790 =====

/* public: __cdecl running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list>
   >::~running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> >(void) __ptr64 */

void __thiscall
running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
::
~running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
          (running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
           *this)

{
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  *prVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (*(longlong *)(this + 0xb0) != 0) {
    MpUnregisterCallback(*(longlong *)(this + 0xb0));
  }
  if (*(longlong *)(this + 0xa8) != 0) {
    MpReleaseCallback(*(longlong *)(this + 0xa8));
  }
  if (*(longlong *)(this + 0xa0) != 0) {
    MpReleaseCallback(*(longlong *)(this + 0xa0));
  }
  prVar1 = this + 0x38;
  while( true ) {
    iVar3 = RtlNumberGenericTableElementsAvl(prVar1);
    if (iVar3 == 0) break;
    uVar2 = RtlEnumerateGenericTableAvl(prVar1,1);
    RtlDeleteElementGenericTableAvl(prVar1,uVar2);
  }
  shared_ptr<path_list<implementation::path_list>_>::
  ~shared_ptr<path_list<implementation::path_list>_>
            ((shared_ptr<path_list<implementation::path_list>_> *)(this + 0x28));
  shared_ptr<path_list<implementation::path_list>_>::
  ~shared_ptr<path_list<implementation::path_list>_>
            ((shared_ptr<path_list<implementation::path_list>_> *)(this + 0x18));
  return;
}



===== ~stream_handler<implementation::irp,implementation::queue,implementation::csqueue> @ 140002828 =====

/* public: __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::~stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue>(void) __ptr64 */

void __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
~stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this)

{
  longlong lVar1;
  longlong local_10;
  
  while (*(stream_handler<implementation::irp,implementation::queue,implementation::csqueue> **)
          (this + 0x40) != this + 0x40) {
    lVar1 = IoCsqRemoveNextIrp(this + 0x58,0);
    if (lVar1 != 0) {
      *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
      *(undefined8 *)(lVar1 + 0x38) = 0;
      IofCompleteRequest(lVar1);
    }
  }
  while (*(int *)(this + 0x20) != 0) {
    queue<implementation::queue,network_filtering::connection_notification>::pop_front
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
              );
    if (local_10 != 0) {
      ExFreePoolWithTag(local_10,0x666e6477);
    }
  }
  return;
}



===== DriverEntry @ 1400028c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined1 auStackY_f8 [32];
  undefined8 local_a8;
  wchar_t *pwStack_a0;
  longlong local_98;
  undefined8 local_90;
  undefined8 local_88;
  wchar_t *pwStack_80;
  longlong local_78 [2];
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_88 = 0x220020;
  local_78[0] = 0;
  pwStack_80 = L"\\Device\\wdnisdrv";
  iVar1 = WdmlibIoCreateDeviceSecure
                    (param_1,0x1f8,&local_88,0x22,0x100,1,&SDDL_DEVOBJ_KERNEL_ONLY,0,local_78);
  if (-1 < iVar1) {
    _WPP_MAIN_CB = 0;
    DAT_1400132b8 = &WPP_ThisDir_CTLGUID_WdNisDrv;
    DAT_1400132c0 = 0;
    _DAT_1400132d0 = 0;
    _DAT_1400132d8 = 1;
    WppLoadTracingSupport();
    _DAT_1400132d0 = 0;
    WppInitKm();
    local_68 = 0x90040001;
    local_64 = 0;
    local_5c = 0;
    local_58 = 0x14;
    local_54 = 0x300002;
    local_50 = 1;
    local_4c = 0x280000;
    local_48 = 0x10000000;
    local_44 = 0x601;
    local_40 = 0x5000000;
    local_3c = 0x50;
    local_38 = 0xdaad9cd1;
    local_34 = 0x9325bef4;
    local_30 = 0xf375cf76;
    local_2c = 0xb48e3ffd;
    local_28 = 0x19a8d2ec;
    local_90 = 0;
    iVar1 = ObOpenObjectByPointer(local_78[0],0x200,0,0x40000);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_588b30db54ec304e19be80df608af16a_Traceguids,iVar1);
      }
    }
    else {
      iVar1 = ZwSetSecurityObject(local_90,4,&local_68);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_588b30db54ec304e19be80df608af16a_Traceguids,iVar1);
        }
        ZwClose(local_90);
      }
      else {
        ZwClose(local_90);
        local_98 = local_78[0];
        local_78[0] = 0;
        local_a8 = local_88;
        pwStack_a0 = pwStack_80;
        iVar1 = driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
                ::create_in_device_extension<_DRIVER_OBJECT,_anonymous_namespace_::device_object>
                          (param_1,&local_a8);
      }
    }
  }
  if (local_78[0] != 0) {
    WppCleanupKm();
    IoDeleteDevice(local_78[0]);
  }
  return iVar1;
}



===== create_in_device_extension<_DRIVER_OBJECT,`anonymous_namespace'::device_object> @ 140002b58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
    ::create_in_device_extension<_DRIVER_OBJECT,_anonymous_namespace_::device_object>
              (longlong param_1,undefined8 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = param_2[2];
  local_38 = *param_2;
  uStack_30 = param_2[1];
  piVar2 = *(int **)(local_28 + 0x40);
  param_2[2] = 0;
  piVar2 = driver<_anonymous_namespace_::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_><_DRIVER_OBJECT,_anonymous_namespace_::device_object>
                     (piVar2,param_1,(int *)&local_38);
  iVar1 = *piVar2;
  *(undefined1 *)(piVar2 + 1) = 1;
  if (iVar1 < 0) {
    excluded_addresses<implementation::avl_table>::~excluded_addresses<implementation::avl_table>
              ((excluded_addresses<implementation::avl_table> *)(piVar2 + 0x44));
    running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
    ::
    ~running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
              ((running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                *)(piVar2 + 0x14));
    if (-1 < piVar2[10]) {
      IoDeleteSymbolicLink(piVar2 + 0xc);
    }
    if (*(longlong *)(piVar2 + 8) != 0) {
      WppCleanupKm();
      IoDeleteDevice(*(undefined8 *)(piVar2 + 8));
    }
    if (param_2[2] != 0) {
      WppCleanupKm();
      IoDeleteDevice(param_2[2]);
    }
  }
  else {
    if (param_2[2] != 0) {
      WppCleanupKm();
      IoDeleteDevice(param_2[2]);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== network_stream_filter<_DRIVER_OBJECT_*,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_> @ 140002c5c =====

int * driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
      ::network_stream_filter::
      network_stream_filter<_DRIVER_OBJECT_*,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
                (int *param_1,_DRIVER_OBJECT *param_2,stream_settings *param_3,
                stream_settings *param_4,bool *param_5,bool *param_6,bool *param_7,bool *param_8,
                running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                *param_9,excluded_addresses<implementation::avl_table> *param_10,bool param_11,
                bool param_12,bool param_13,bool param_14)

{
  stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
  *psVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  psVar1 = (stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
            *)(param_1 + 2);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = -0x3ffffff3;
  *(undefined4 *)psVar1 = 0xc000000d;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[4] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 7) = 0;
  KeInitializeSpinLock(param_1 + 8);
  param_1[0xe] = 0;
  piVar2 = param_1 + 0x16;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  piVar4 = param_1 + 10;
  *(int **)(param_1 + 0xc) = piVar4;
  *(int **)piVar4 = piVar4;
  param_1[0x12] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 0x13) = 0;
  param_1[0x14] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(int **)(param_1 + 0x18) = piVar2;
  *(int **)piVar2 = piVar2;
  KeInitializeSpinLock(param_1 + 0x1a);
  iVar3 = IoCsqInitialize(param_1 + 0x1c,
                          <lambda_5593ee50ecb8e35d6e56e15f73f8f802>::<lambda_invoker_cdecl>,
                          <lambda_f22a1144f06c5e87ab6e9654c303aa32>::<lambda_invoker_cdecl>,
                          <lambda_8d1e6fa018bd9e8302854441ecddfb77>::<lambda_invoker_cdecl>,
                          <lambda_b2738bab5f9d8fd10492fe3d6529319a>::<lambda_invoker_cdecl>,
                          <lambda_1fe26a0b29263d33bf0f2ea388257860>::<lambda_invoker_cdecl>,
                          <lambda_40d900456e4918bba8049c046de406bc>::<lambda_invoker_cdecl>);
  param_1[0x14] = iVar3;
  param_1[0x12] = iVar3;
  *(undefined1 *)(param_1 + 0x15) = 1;
  param_1[6] = iVar3;
  *(undefined1 *)(param_1 + 0x13) = 1;
  param_1[4] = iVar3;
  *(undefined1 *)(param_1 + 7) = 1;
  *(int *)psVar1 = iVar3;
  *(undefined1 *)(param_1 + 5) = 1;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  ::
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_><_DRIVER_OBJECT*___ptr64>
            ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
              *)(param_1 + 0x2c),param_2,psVar1,param_3,param_4,param_5,param_6,param_7,param_8,
             param_9,param_10,param_11,param_12,param_13,param_14);
  *(undefined1 *)(param_1 + 3) = 1;
  *param_1 = *(int *)psVar1;
  if (-1 < *(int *)psVar1) {
    *(undefined1 *)(param_1 + 0x2d) = 1;
    *param_1 = param_1[0x2c];
  }
  return param_1;
}



===== shared_ptr<path_list<implementation::path_list>_><bool_const&___ptr64,wchar_t_const_(&___ptr64)[0],unsigned_int_const&___ptr64> @ 140002e44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl shared_ptr<class path_list<class implementation::path_list> >::shared_ptr<class
   path_list<class implementation::path_list> ><bool const & __ptr64,wchar_t const (&
   __ptr64)[0],unsigned int const & __ptr64>(struct in_place_t,bool const & __ptr64,wchar_t const (&
   __ptr64)[0],unsigned int const & __ptr64) __ptr64 */

shared_ptr<path_list<implementation::path_list>_> * __thiscall
shared_ptr<path_list<implementation::path_list>_>::
shared_ptr<path_list<implementation::path_list>_><bool_const&___ptr64,wchar_t_const_(&___ptr64)[0],unsigned_int_const&___ptr64>
          (shared_ptr<path_list<implementation::path_list>_> *this,undefined8 param_2,
          undefined8 param_3,wchar_t *param_4,uint *param_5)

{
  int iVar1;
  undefined1 auStack_58 [32];
  int **local_38;
  undefined1 local_30;
  int *local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  this[4] = (shared_ptr<path_list<implementation::path_list>_>)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined4 *)this = 0xc000000d;
  local_28 = (int *)ExAllocatePoolWithTag(0x600,0x38,0x666e6477);
  if (local_28 == (int *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    if ((char)ExPoolZeroingNativelySupported == '\0') {
      local_28[0] = 0;
      local_28[1] = 0;
      local_28[2] = 0;
      local_28[3] = 0;
      local_28[4] = 0;
      local_28[5] = 0;
      local_28[6] = 0;
      local_28[7] = 0;
      local_28[8] = 0;
      local_28[9] = 0;
      local_28[10] = 0;
      local_28[0xb] = 0;
      local_28[0xc] = 0;
      local_28[0xd] = 0;
    }
    *local_28 = -0x3ffffff3;
    *(undefined1 *)(local_28 + 1) = 0;
    path_list<implementation::path_list>::path_list<implementation::path_list>
              ((path_list<implementation::path_list> *)(local_28 + 2),*(bool *)param_3,param_4,
               (ulonglong)*param_5);
    *local_28 = local_28[2];
    local_38 = &local_28;
    local_28[0xc] = 1;
    *(undefined1 *)(local_28 + 3) = 1;
    iVar1 = *local_28;
    local_30 = 1;
    *(undefined1 *)(local_28 + 1) = 1;
    if (iVar1 < 0) {
      `auto___cdecl_scope_exit<<lambda_117755146cfb628ec8e28b6b05fe2077>_>(<lambda_117755146cfb628ec8e28b6b05fe2077>)'
      ::__l2::scope_exit::~scope_exit((scope_exit *)&local_38);
    }
    else {
      *(int **)(this + 8) = local_28;
      local_30 = 0;
      `auto___cdecl_scope_exit<<lambda_117755146cfb628ec8e28b6b05fe2077>_>(<lambda_117755146cfb628ec8e28b6b05fe2077>)'
      ::__l2::scope_exit::~scope_exit((scope_exit *)&local_38);
      iVar1 = 0;
    }
  }
  *(int *)this = iVar1;
  return this;
}



===== ~scope_exit @ 140002f6c =====

/* public: __cdecl `auto __cdecl scope_exit<class <lambda_117755146cfb628ec8e28b6b05fe2077> >(class
   <lambda_117755146cfb628ec8e28b6b05fe2077>)'::`2'::scope_exit::~scope_exit(void) __ptr64 */

void __thiscall
`auto___cdecl_scope_exit<<lambda_117755146cfb628ec8e28b6b05fe2077>_>(<lambda_117755146cfb628ec8e28b6b05fe2077>)'
::__l2::scope_exit::~scope_exit(scope_exit *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  if ((this[8] != (scope_exit)0x0) && (lVar3 = **(longlong **)this, lVar3 != 0)) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x30);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(lVar3 + 0x20) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0x666e6477);
      }
      if (*(longlong *)(lVar3 + 0x18) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0x666e6477);
      }
      ExFreePoolWithTag(lVar3,0x666e6477);
    }
  }
  return;
}



===== inject_stream_segment<implementation::irp> @ 140002fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::inject_stream_segment<class implementation::irp>(class irp<class implementation::irp> &
   __ptr64) __ptr64 */

long __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::inject_stream_segment<implementation::irp>
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,irp<implementation::irp> *param_1)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  flow_context *this_00;
  void *pvVar7;
  _func_void_void_ptr__NET_BUFFER_LIST_ptr_uchar *in_R9;
  undefined1 auStack_208 [32];
  longlong local_1e8;
  undefined2 uStack_1e0;
  undefined2 uStack_1de;
  undefined2 uStack_1dc;
  undefined2 uStack_1da;
  undefined8 local_1d8;
  longlong local_1c8;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  undefined8 local_1b8;
  undefined8 local_1a8;
  longlong lStack_1a0;
  ulonglong local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  uint uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 local_f0 [24];
  undefined8 local_d8;
  longlong lStack_d0;
  ulonglong uStack_c8;
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
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  uint local_34;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_208;
  uVar2 = *(uint *)(*(longlong *)(*(longlong *)param_1 + 0xb8) + 0x10);
  if (uVar2 < 0x1e) {
    return -0x3fffffdd;
  }
  lVar5 = *(longlong *)(*(longlong *)param_1 + 0x18);
  uVar6 = (ulonglong)*(uint *)(lVar5 + 0x1a) + 0x1e;
  if (uVar6 < 0x1e) {
    return -0x3fffffdd;
  }
  if (uVar2 < uVar6) {
    return -0x3fffffdd;
  }
  uStack_1dc = 0;
  uStack_1da = 0;
  this_00 = (flow_context *)0x0;
  KeAcquireInStackQueuedSpinLock(this + 0x50,local_f0);
  local_1e8 = *(longlong *)(lVar5 + 8);
  uStack_1e0 = 0;
  uStack_1de = 0;
  uStack_1dc = 0;
  uStack_1da = 0;
  local_1d8 = 0;
  uStack_1c0 = 0;
  uStack_1bc = 0;
  local_1b8 = 0;
  local_1c8 = local_1e8;
  lVar4 = RtlLookupElementGenericTableAvl(this + 0x60,&local_1c8);
  if (lVar4 != 0) {
    this_00 = *(flow_context **)(lVar4 + 0x10);
    LOCK();
    *(int *)this_00 = *(int *)this_00 + 1;
    UNLOCK();
  }
  KeReleaseInStackQueuedSpinLock(local_f0);
  if (this_00 == (flow_context *)0x0) {
    LOG_WARNING_UINT64(L"Flow context not found on reinjection. Connection id: ",
                       *(__uint64 *)(lVar5 + 8));
    return -0x3ffffddb;
  }
  KeAcquireInStackQueuedSpinLock(this_00 + 0x1f0,local_f0);
  *(void **)(this_00 + 0x200) = SystemReserved1[0xf];
  if (this_00[0x1f8] != (flow_context)0x0) {
    lVar3 = 0;
    goto LAB_140003323;
  }
  if ((*(byte *)(lVar5 + 0x16) & 0x20) != 0) {
    this_00[0x209] = (flow_context)0x1;
  }
  bVar1 = *(byte *)(lVar5 + 0x16);
  if ((bVar1 & 0x40) == 0) {
    if (*(int *)((queue<implementation::queue,net_buffer_list> *)
                 (this_00 + (-(ulonglong)((bVar1 & 1) != 0) & 0xffffffffffffffd8) + 0x1c8) + 0x18)
        == 0) {
      LOG_ERROR(L"Service requested a sync reinjection but traffic queue is empty");
      lVar3 = -0x3ffffddb;
      goto LAB_140003323;
    }
    this_00[0x208] = (flow_context)0x1;
    lVar5 = queue<implementation::queue,net_buffer_list>::pop_front
                      ((queue<implementation::queue,net_buffer_list> *)
                       (this_00 + (-(ulonglong)((bVar1 & 1) != 0) & 0xffffffffffffffd8) + 0x1c8));
    pvVar7 = *(void **)(lVar5 + 8);
    *(undefined8 *)(lVar5 + 8) = 0;
    lVar5 = CONCAT26(uStack_1da,CONCAT24(uStack_1dc,CONCAT22(uStack_1de,uStack_1e0)));
    if (lVar5 != 0) {
      net_buffer_list::~net_buffer_list((net_buffer_list *)(lVar5 + 0x10));
      lVar5 = CONCAT26(uStack_1da,CONCAT24(uStack_1dc,CONCAT22(uStack_1de,uStack_1e0)));
      if (lVar5 != 0) {
        ExFreePoolWithTag(lVar5,0x666e6477);
      }
    }
  }
  else {
    if ((*(short *)(lVar5 + 0x10) != 0x14) && (*(short *)(lVar5 + 0x10) != 0x16)) {
      LOG_ERROR(L"Custom UDP content is not supported");
      lVar3 = -0x3fffff45;
      goto LAB_140003323;
    }
    LOG_WARNING_UINT64(L"Sending custom content on flow",*(__uint64 *)(this_00 + 8));
    local_1c8 = *(longlong *)(lVar5 + 8);
    uStack_104 = *(uint *)(lVar5 + 0x1a);
    local_30 = 1;
    uStack_1c0 = *(uint *)(lVar5 + 0x12);
    local_d8 = 0;
    uStack_1bc = 0;
    local_198 = (ulonglong)uStack_1c0;
    local_38 = CONCAT22(*(undefined2 *)(lVar5 + 0x16),*(undefined2 *)(lVar5 + 0x10));
    local_1a8 = 0;
    uStack_190 = uStack_c0;
    local_188 = local_b8;
    uStack_180 = uStack_b0;
    local_178 = local_a8;
    uStack_170 = uStack_a0;
    local_168 = local_98;
    uStack_160 = uStack_90;
    local_158 = local_88;
    uStack_150 = uStack_80;
    local_148 = local_78;
    uStack_140 = uStack_70;
    local_138 = local_68;
    uStack_130 = uStack_60;
    local_128 = uStack_58;
    uStack_120 = uStack_50;
    local_118 = uStack_48;
    uStack_114 = uStack_44;
    uStack_110 = uStack_40;
    uStack_10c = uStack_3c;
    local_108 = local_38;
    uStack_100 = 1;
    uStack_fc = 0;
    lStack_1a0 = local_1c8;
    lStack_d0 = local_1c8;
    uStack_c8 = local_198;
    local_34 = uStack_104;
    lVar4 = queue<implementation::queue,net_buffer_list>::create_element<reinjection_meta_data>
                      (&local_1e8,(ulonglong)uStack_104 + 8,&local_1a8);
    pvVar7 = *(void **)(lVar4 + 8);
    *(undefined8 *)(lVar4 + 8) = 0;
    lVar4 = CONCAT26(uStack_1da,CONCAT24(uStack_1dc,CONCAT22(uStack_1de,uStack_1e0)));
    if (lVar4 != 0) {
      net_buffer_list::~net_buffer_list((net_buffer_list *)(lVar4 + 0x10));
      lVar4 = CONCAT26(uStack_1da,CONCAT24(uStack_1dc,CONCAT22(uStack_1de,uStack_1e0)));
      if (lVar4 != 0) {
        ExFreePoolWithTag(lVar4,0x666e6477);
      }
    }
    if (pvVar7 == (void *)0x0) {
      lVar3 = -0x3fffffe9;
      goto LAB_140003323;
    }
    local_1c8 = lVar5;
    net_buffer_list::clone_tcp_data<<lambda_220cd7f263e4bda15c83388f3615e84a>_>
              ((net_buffer_list *)((longlong)pvVar7 + 0x10),
               (<lambda_220cd7f263e4bda15c83388f3615e84a> *)&local_1c8,*(void **)(this + 0x170));
  }
  lVar3 = implementation::wfp_callout::inject_stream_segment
                    ((wfp_callout *)(this + 0x158),(net_buffer_list *)((longlong)pvVar7 + 0x10),
                     pvVar7,in_R9);
LAB_140003323:
  *(undefined8 *)(this_00 + 0x200) = 0;
  KeReleaseInStackQueuedSpinLock(local_f0);
  flow_context::release(this_00);
  return lVar3;
}



===== create_element<reinjection_meta_data> @ 140003390 =====

/* public: static auto __cdecl queue<class implementation::queue,class
   net_buffer_list>::create_element<struct reinjection_meta_data>(unsigned __int64,struct
   reinjection_meta_data) */

undefined4 * __cdecl
queue<implementation::queue,net_buffer_list>::create_element<reinjection_meta_data>
          (undefined4 *param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *_Dst;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
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
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar6 = *param_3;
  uVar7 = param_3[1];
  uVar8 = param_3[2];
  uVar9 = param_3[3];
  *param_1 = 0xc000000d;
  uVar5 = 0;
  uVar10 = param_3[4];
  uVar11 = param_3[5];
  *(undefined1 *)(param_1 + 1) = 0;
  uVar12 = param_3[6];
  uVar13 = param_3[7];
  uVar14 = param_3[8];
  uVar15 = param_3[9];
  uVar16 = param_3[10];
  uVar17 = param_3[0xb];
  uVar18 = param_3[0xc];
  uVar19 = param_3[0xd];
  uVar22 = param_3[0x10];
  uVar23 = param_3[0x11];
  uVar20 = param_3[0xe];
  uVar21 = param_3[0xf];
  uVar24 = *(undefined4 *)(param_3 + 0x12);
  uVar1 = *(undefined4 *)((longlong)param_3 + 0x94);
  uVar25 = *(undefined4 *)(param_3 + 0x13);
  uVar2 = *(undefined4 *)((longlong)param_3 + 0x9c);
  uVar26 = *(undefined4 *)(param_3 + 0x14);
  uVar3 = *(undefined4 *)((longlong)param_3 + 0xa4);
  uVar27 = *(undefined4 *)(param_3 + 0x15);
  uVar4 = *(undefined4 *)((longlong)param_3 + 0xac);
  _Dst = (void *)ExAllocatePoolWithTag
                           (0x600,param_2 + 0xd0U,0x666e6477,param_4,uVar6,uVar7,uVar8,uVar9,uVar10,
                            uVar11,uVar12,uVar13,uVar14,uVar15,uVar16,uVar17,uVar18,uVar19,uVar20,
                            uVar21,uVar22,uVar23,uVar24,uVar25,uVar26,uVar27);
  if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
    memset(_Dst,0,param_2 + 0xd0U);
  }
  *(void **)(param_1 + 2) = _Dst;
  if (_Dst == (void *)0x0) {
    uVar5 = 0xc0000017;
  }
  else {
    memset(_Dst,0,0xd0);
    local_b8 = uVar6;
    uStack_b0 = uVar7;
    local_a8 = uVar8;
    uStack_a0 = uVar9;
    local_98 = uVar10;
    uStack_90 = uVar11;
    local_88 = uVar12;
    uStack_80 = uVar13;
    local_78 = uVar14;
    uStack_70 = uVar15;
    local_68 = uVar16;
    uStack_60 = uVar17;
    local_58 = uVar18;
    uStack_50 = uVar19;
    local_48 = uVar20;
    uStack_40 = uVar21;
    local_38 = uVar22;
    uStack_30 = uVar23;
    local_28 = uVar24;
    uStack_24 = uVar1;
    uStack_20 = uVar25;
    uStack_1c = uVar2;
    local_18 = uVar26;
    uStack_14 = uVar3;
    uStack_10 = uVar27;
    uStack_c = uVar4;
    net_buffer_list::net_buffer_list
              ((net_buffer_list *)(*(longlong *)(param_1 + 2) + 0x10),&local_b8);
  }
  *param_1 = uVar5;
  return param_1;
}



===== clone_tcp_data<<lambda_220cd7f263e4bda15c83388f3615e84a>_> @ 140003530 =====

/* public: auto __cdecl net_buffer_list::clone_tcp_data<class
   <lambda_220cd7f263e4bda15c83388f3615e84a> >(class <lambda_220cd7f263e4bda15c83388f3615e84a> const
   & __ptr64,void * __ptr64) __ptr64 */

undefined8 __thiscall
net_buffer_list::clone_tcp_data<<lambda_220cd7f263e4bda15c83388f3615e84a>_>
          (net_buffer_list *this,<lambda_220cd7f263e4bda15c83388f3615e84a> *param_1,void *param_2)

{
  uint uVar1;
  net_buffer_list *pnVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  pnVar2 = (net_buffer_list *)0x0;
  if (*(longlong *)(this + 8) == 0) {
    pnVar2 = this + 0x10;
  }
  if (pnVar2 != (net_buffer_list *)0x0) {
    uVar1 = *(uint *)(this + 0xac);
    if (uVar1 == 0) {
      return 0;
    }
    uVar4 = 0;
    lVar3 = IoAllocateMdl(this + 0xc0,uVar1,0,0,0);
    *(longlong *)(this + (ulonglong)uVar1 + 0xc0) = lVar3;
    if (lVar3 != 0) {
      MmBuildMdlForNonPagedPool(lVar3);
      FwpsAllocateNetBufferAndNetBufferList0
                (param_2,0,0,*(undefined8 *)(this + (ulonglong)uVar1 + 0xc0),
                 uVar4 & 0xffffffff00000000,*(undefined4 *)(this + 0xac),this);
      if (*(longlong *)this != 0) {
        memmove(this + 0xc0,(void *)(*(longlong *)param_1 + 0x1e),
                (ulonglong)*(uint *)(*(longlong *)param_1 + 0x1a));
        return 0;
      }
    }
  }
  return 0xc0000017;
}



===== driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_><_DRIVER_OBJECT,`anonymous_namespace'::device_object> @ 140003630 =====

int * driver<`anonymous_namespace'::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_>
      ::
      driver<_anonymous_namespace_::driver_impl,implementation::irp,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>,path_list<implementation::path_list>,excluded_addresses<implementation::avl_table>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>_><_DRIVER_OBJECT,_anonymous_namespace_::device_object>
                (int *param_1,longlong param_2,int *param_3)

{
  uint *puVar1;
  int *piVar2;
  longlong *plVar3;
  int *piVar4;
  excluded_addresses<implementation::avl_table> *this;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  wchar_t *pwVar11;
  
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = -0x3ffffff3;
  uVar10 = *(undefined8 *)(param_3 + 4);
  iVar7 = *param_3;
  iVar8 = param_3[1];
  iVar5 = param_3[2];
  iVar6 = param_3[3];
  param_3[4] = 0;
  param_3[5] = 0;
  param_1[2] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined8 *)(param_1 + 8) = uVar10;
  param_1[4] = iVar7;
  param_1[5] = iVar8;
  param_1[6] = iVar5;
  param_1[7] = iVar6;
  param_1[10] = -0x3ffffff3;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined2 *)((longlong)param_1 + 0x32) = 0x1a;
  *(undefined2 *)(param_1 + 0xc) = 0x18;
  param_1[0xd] = 0;
  *(wchar_t **)(param_1 + 0xe) = L"\\??\\wdnisdrv";
  iVar7 = IoCreateSymbolicLink();
  param_1[10] = iVar7;
  *(undefined1 *)(param_1 + 0xb) = 1;
  param_1[2] = iVar7;
  if (-1 < iVar7) {
    *(code **)(param_2 + 0x70) = <lambda_61d4af8ef1711536e00056b4c5ac14f8>::<lambda_invoker_cdecl>;
    *(code **)(param_2 + 0x100) = <lambda_232e68d14d6adad7442257a881ea395f>::<lambda_invoker_cdecl>;
    *(code **)(param_2 + 0x80) = <lambda_a3286718b1279327f4c7fb65275b0eb3>::<lambda_invoker_cdecl>;
    *(code **)(param_2 + 0xe0) = <lambda_51f4c9b3ed17c868c2b4c5b1fddc973c>::<lambda_invoker_cdecl>;
    *(code **)(param_2 + 0x68) = <lambda_e25fcd0e3f24cd4b7b87a2fb5312e9cb>::<lambda_invoker_cdecl>;
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xffffff7f | 4;
    puVar1 = (uint *)(*(longlong *)(param_2 + 8) + 0x30);
    *puVar1 = *puVar1 | 0x2004;
    puVar1 = (uint *)(*(longlong *)(param_2 + 8) + 0x30);
    *puVar1 = *puVar1 & 0xffffff7f;
    param_1[2] = 0;
  }
  piVar2 = param_1 + 0x14;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *piVar2 = -0x3ffffff3;
  *(undefined1 *)(param_1 + 0x15) = 0;
  KeInitializeSpinLock(param_1 + 0x16);
  *(undefined1 *)(param_1 + 0x18) = 0;
  shared_ptr<path_list<implementation::path_list>_>::
  shared_ptr<path_list<implementation::path_list>_><>
            ((shared_ptr<path_list<implementation::path_list>_> *)(param_1 + 0x1a));
  shared_ptr<path_list<implementation::path_list>_>::
  shared_ptr<path_list<implementation::path_list>_><>
            ((shared_ptr<path_list<implementation::path_list>_> *)(param_1 + 0x1e));
  RtlInitializeGenericTableAvl
            (param_1 + 0x22,
             <lambda_33aa60316530382419a9baeda44eab07>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_cfa8db44f37c8b0967490b6e38287a87>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,0);
  iVar7 = param_1[0x1a];
  piVar4 = param_1 + 0x3c;
  piVar4[0] = 0;
  piVar4[1] = 0;
  plVar3 = (longlong *)(param_1 + 0x3e);
  *plVar3 = 0;
  *(longlong *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 1;
  *piVar2 = iVar7;
  param_1[0x42] = 0;
  if (-1 < iVar7) {
    *(undefined1 *)(param_1 + 0x1f) = 1;
    *piVar2 = param_1[0x1e];
    if (-1 < param_1[0x1e]) {
      uVar10 = MpCreateCallback((longlong)piVar4);
      iVar7 = (int)uVar10;
      if (-1 < (int)uVar10) {
        pwVar11 = L"\\Callback\\WdProcessNotificationCallback";
        uVar10 = MpCreateCallback((longlong)plVar3);
        iVar7 = (int)uVar10;
        if (-1 < (int)uVar10) {
          iVar8 = MpRegisterCallback(*plVar3,pwVar11,piVar2,(longlong *)(param_1 + 0x40));
          iVar7 = 0;
          if (iVar8 < 0) {
            iVar7 = iVar8;
          }
        }
      }
      if (-1 < iVar7) {
        iVar7 = 0;
      }
      *piVar2 = iVar7;
    }
  }
  this = (excluded_addresses<implementation::avl_table> *)(param_1 + 0x44);
  *(undefined4 *)this = 0xc000000d;
  *(undefined1 *)(param_1 + 0x45) = 0;
  KeInitializeSpinLock(param_1 + 0x46);
  RtlInitializeGenericTableAvl
            (param_1 + 0x48,
             <lambda_3b984229c8035a49320dff25fe1ee415>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_cfa8db44f37c8b0967490b6e38287a87>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,0);
  RtlInitializeGenericTableAvl
            (param_1 + 0x62,
             <lambda_47c094fdbd6b34749e4ef95a8029e4a8>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_cfa8db44f37c8b0967490b6e38287a87>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,0);
  lVar9 = excluded_addresses<implementation::avl_table>::reload(this,(sockaddr_storage *)0x0,0);
  *(long *)this = lVar9;
  *(undefined1 *)(param_1 + 3) = 1;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  *param_1 = param_1[2];
  if (-1 < param_1[2]) {
    *(undefined1 *)(param_1 + 0x15) = 1;
    *param_1 = *piVar2;
    if (-1 < *piVar2) {
      *(undefined1 *)(param_1 + 0x45) = 1;
      *param_1 = *(int *)this;
    }
  }
  if (*(longlong *)(param_3 + 4) != 0) {
    WppCleanupKm();
    IoDeleteDevice(*(undefined8 *)(param_3 + 4));
  }
  return param_1;
}



===== pop_front @ 140003914 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class queue_element<struct network_filtering::connection_notification,class
   implementation::queue<struct network_filtering::connection_notification>::element_impl> __cdecl
   queue<class implementation::queue,struct
   network_filtering::connection_notification>::pop_front(void) __ptr64 */

void __thiscall
queue<implementation::queue,network_filtering::connection_notification>::pop_front
          (queue<implementation::queue,network_filtering::connection_notification> *this)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *in_RDX;
  queue<implementation::queue,network_filtering::connection_notification> *pqVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [48];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  KeAcquireInStackQueuedSpinLock();
  puVar5 = auStack_48;
  pqVar4 = this + 8;
  if (*(queue<implementation::queue,network_filtering::connection_notification> **)pqVar4 != pqVar4)
  {
    LOCK();
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
    UNLOCK();
    plVar7 = *(longlong **)pqVar4;
    if (((queue<implementation::queue,network_filtering::connection_notification> *)plVar7[1] ==
         pqVar4) && (lVar1 = *plVar7, *(longlong **)(lVar1 + 8) == plVar7)) {
      *(longlong *)pqVar4 = lVar1;
      *(queue<implementation::queue,network_filtering::connection_notification> **)(lVar1 + 8) =
           pqVar4;
      lVar1 = plVar7[3];
      if (lVar1 == 1) {
        uVar6 = (ulonglong)(*(uint *)((longlong)plVar7 + 0x3a) - 0x10c);
        if (*(uint *)((longlong)plVar7 + 0x3a) < 0x10d) {
          uVar6 = 0;
        }
      }
      else if (lVar1 == 6) {
        uVar3 = *(int *)((longlong)plVar7 + 0x131) * 2;
        uVar6 = 0;
        if (0x15 < uVar3) {
          uVar6 = (ulonglong)(uVar3 - 0x15);
        }
      }
      else if (lVar1 == 0) {
        uVar6 = (ulonglong)(uint)(*(int *)((longlong)plVar7 + 0x146) * 2);
      }
      else {
        uVar6 = 0;
      }
      *(ulonglong *)(this + 0x20) = (*(longlong *)(this + 0x20) - uVar6) + -0x10;
      puVar5 = auStack_48;
      goto LAB_1400039e3;
    }
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    puVar5 = auStack_40;
  }
  plVar7 = (longlong *)0x0;
LAB_1400039e3:
  *in_RDX = 0xc000000d;
  *(undefined1 *)(in_RDX + 1) = 0;
  *(longlong **)(in_RDX + 2) = plVar7;
  *(undefined8 *)(puVar5 + -8) = 0x140003a0b;
  KeReleaseInStackQueuedSpinLock(puVar5 + 0x20);
  *(undefined8 *)(puVar5 + -8) = 0x140003a20;
  return;
}



===== push_front @ 140003a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl queue<class implementation::queue,struct
   network_filtering::connection_notification>::push_front(class queue_element<struct
   network_filtering::connection_notification,class implementation::queue<struct
   network_filtering::connection_notification>::element_impl>) __ptr64 */

void __thiscall
queue<implementation::queue,network_filtering::connection_notification>::push_front
          (queue<implementation::queue,network_filtering::connection_notification> *this,
          longlong param_2)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  queue<implementation::queue,network_filtering::connection_notification> *pqVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  KeAcquireInStackQueuedSpinLock(this,local_28);
  puVar6 = auStack_48;
  plVar7 = *(longlong **)(param_2 + 8);
  pqVar5 = this + 8;
  *(undefined8 *)(param_2 + 8) = 0;
  LOCK();
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  UNLOCK();
  lVar3 = plVar7[3];
  if (lVar3 == 1) {
    uVar4 = (ulonglong)(*(uint *)((longlong)plVar7 + 0x3a) - 0x10c);
    if (*(uint *)((longlong)plVar7 + 0x3a) < 0x10d) {
      uVar4 = 0;
    }
  }
  else if (lVar3 == 6) {
    uVar2 = *(int *)((longlong)plVar7 + 0x131) * 2;
    uVar4 = 0;
    if (0x15 < uVar2) {
      uVar4 = (ulonglong)(uVar2 - 0x15);
    }
  }
  else if (lVar3 == 0) {
    uVar4 = (ulonglong)(uint)(*(int *)((longlong)plVar7 + 0x146) * 2);
  }
  else {
    uVar4 = 0;
  }
  *(ulonglong *)(this + 0x20) = *(longlong *)(this + 0x20) + 0x10 + uVar4;
  lVar3 = *(longlong *)pqVar5;
  if (*(queue<implementation::queue,network_filtering::connection_notification> **)(lVar3 + 8) !=
      pqVar5) {
    pcVar1 = (code *)swi(0x29);
    lVar3 = (*pcVar1)(3);
    puVar6 = auStack_40;
  }
  *plVar7 = lVar3;
  plVar7[1] = (longlong)pqVar5;
  *(longlong **)(lVar3 + 8) = plVar7;
  *(longlong **)pqVar5 = plVar7;
  *(undefined8 *)(puVar6 + -8) = 0x140003afb;
  KeReleaseInStackQueuedSpinLock(puVar6 + 0x20);
  lVar3 = *(longlong *)(param_2 + 8);
  if (lVar3 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140003b15;
    ExFreePoolWithTag(lVar3,0x666e6477);
  }
  *(undefined8 *)(puVar6 + -8) = 0x140003b27;
  return;
}



===== ~shared_ptr<path_list<implementation::path_list>_> @ 140003b38 =====

/* public: __cdecl shared_ptr<class path_list<class implementation::path_list> >::~shared_ptr<class
   path_list<class implementation::path_list> >(void) __ptr64 */

void __thiscall
shared_ptr<path_list<implementation::path_list>_>::
~shared_ptr<path_list<implementation::path_list>_>
          (shared_ptr<path_list<implementation::path_list>_> *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(this + 8);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x30);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(lVar3 + 0x20) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0x666e6477);
      }
      if (*(longlong *)(lVar3 + 0x18) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0x666e6477);
      }
      ExFreePoolWithTag(lVar3,0x666e6477);
    }
  }
  return;
}



===== ~wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_> @ 140003ba4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl wfp_callout<class implementation::wfp_callout,class implementation::event,class
   implementation::avl_table,class implementation::queue,class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> >,class running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> >,class
   excluded_addresses<class implementation::avl_table> >::~wfp_callout<class
   implementation::wfp_callout,class implementation::event,class implementation::avl_table,class
   implementation::queue,class stream_handler<class implementation::stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue> >,class
   running_processes<class implementation::running_processes,class implementation::avl_table,class
   path_list<class implementation::path_list> >,class excluded_addresses<class
   implementation::avl_table> >(void) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::
~wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  __uint64 *p_Var4;
  undefined8 uVar5;
  wfp_registration *this_00;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  *pwVar6;
  undefined8 in_R8;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  __uint64 local_68;
  __uint64 _Stack_60;
  flow_context *local_58;
  flow_context *local_38;
  undefined1 local_30 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if (-1 < *(int *)this) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,in_R8,
               L"WFP callout destruction started");
    }
    if (*(int *)(this + 0x128) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x124));
      *(undefined8 *)(this + 0x124) = 0;
    }
    if (*(int *)(this + 0x140) != 0) {
      FwpsCalloutUnregisterById0();
      this_00 = (wfp_registration *)(ulonglong)*(uint *)(this + 0x13c);
      FwpsCalloutUnregisterById0();
      *(undefined8 *)(this + 0x13c) = 0;
      wfp_registration::unregister_resource_assignment(this_00);
    }
    if (*(int *)(this + 0x148) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x144));
      *(undefined8 *)(this + 0x144) = 0;
      wfp_registration::unregister_auth_connect((wfp_registration *)(this + 0x108));
    }
    KeAcquireInStackQueuedSpinLock(this + 0x50,local_30);
    this[0x58] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                  )0x1;
    while (p_Var4 = (__uint64 *)RtlEnumerateGenericTableAvl(this + 0x60,1),
          p_Var4 != (__uint64 *)0x0) {
      local_68 = *p_Var4;
      _Stack_60 = p_Var4[1];
      local_38 = (flow_context *)p_Var4[2];
      RtlDeleteElementGenericTableAvl(this + 0x60,p_Var4);
      LOG_VERBOSE_UINT64(L"Removing contexts for flow id",local_68);
      local_58 = local_38;
      remove_contexts<unique_lock<spin_lock>_>(this,&local_68,1);
      flow_context::release(local_38);
    }
    KeReleaseInStackQueuedSpinLock(local_30);
    pwVar6 = this + 0xe8;
    LOG_VERBOSE_UINT64(L"Shared ptr remaining refs",(longlong)*(int *)(*(longlong *)pwVar6 + 0x18));
    lVar2 = *(longlong *)pwVar6;
    if (lVar2 != 0) {
      LOCK();
      piVar1 = (int *)(lVar2 + 0x18);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        KeSetEvent(*(undefined8 *)(lVar2 + 0x10),0,0);
        ExFreePoolWithTag(lVar2,0x666e6477);
      }
    }
    *(longlong *)pwVar6 = 0;
    local_78 = 0;
    KeWaitForSingleObject(this + 200,0,0,0);
    _current = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                *)0x0;
  }
  implementation::wfp_callout::~wfp_callout((wfp_callout *)(this + 0x158));
  implementation::wfp_callout::registration::~registration((registration *)(this + 0xf8));
  lVar2 = *(longlong *)(this + 0xe8);
  if (lVar2 != 0) {
    LOCK();
    piVar1 = (int *)(lVar2 + 0x18);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      KeSetEvent(*(undefined8 *)(lVar2 + 0x10),0,0);
      ExFreePoolWithTag(lVar2,0x666e6477);
    }
  }
  pwVar6 = this + 0x60;
  while (iVar3 = RtlNumberGenericTableElementsAvl(pwVar6), iVar3 != 0) {
    uVar5 = RtlEnumerateGenericTableAvl(pwVar6,1);
    RtlDeleteElementGenericTableAvl(pwVar6,uVar5);
  }
  return;
}



===== ~excluded_addresses<implementation::avl_table> @ 140003eac =====

/* public: __cdecl excluded_addresses<class implementation::avl_table>::~excluded_addresses<class
   implementation::avl_table>(void) __ptr64 */

void __thiscall
excluded_addresses<implementation::avl_table>::~excluded_addresses<implementation::avl_table>
          (excluded_addresses<implementation::avl_table> *this)

{
  excluded_addresses<implementation::avl_table> *peVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  excluded_addresses<implementation::avl_table> *peVar5;
  
  peVar1 = this + 0x10;
  while( true ) {
    lVar4 = RtlEnumerateGenericTableAvl(peVar1,1);
    if (lVar4 == 0) break;
    RtlDeleteElementGenericTableAvl(peVar1,lVar4);
  }
  peVar5 = this + 0x78;
  while( true ) {
    lVar4 = RtlEnumerateGenericTableAvl(peVar5,1);
    if (lVar4 == 0) break;
    RtlDeleteElementGenericTableAvl(peVar5,lVar4);
  }
  while (iVar3 = RtlNumberGenericTableElementsAvl(peVar5), iVar3 != 0) {
    uVar2 = RtlEnumerateGenericTableAvl(peVar5,1);
    RtlDeleteElementGenericTableAvl(peVar5,uVar2);
  }
  while (iVar3 = RtlNumberGenericTableElementsAvl(peVar1), iVar3 != 0) {
    uVar2 = RtlEnumerateGenericTableAvl(peVar1,1);
    RtlDeleteElementGenericTableAvl(peVar1,uVar2);
  }
  return;
}



===== complete_irp @ 140003f94 =====

/* private: void __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp(class irp<class
   implementation::irp>,class queue_element<struct network_filtering::connection_notification,class
   implementation::queue<struct network_filtering::connection_notification>::element_impl>) __ptr64
    */

void __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp(stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this
            ,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined8 local_38;
  undefined8 local_30;
  longlong local_28 [2];
  
  lVar1 = *(longlong *)(param_3 + 8);
  local_38 = *param_2;
  *param_2 = 0;
  local_28[0] = param_3;
  bVar2 = complete_irp<<lambda_96fdd2ae48791c3fb7f632cc059d6327>_const&___ptr64>
                    (&local_38,lVar1 + 0x10,local_28);
  if (!bVar2) {
    local_30 = *(undefined8 *)(param_3 + 8);
    local_38 = CONCAT44(CONCAT31(local_38._5_3_,bVar2),0xc000000d);
    *(undefined8 *)(param_3 + 8) = 0;
    queue<implementation::queue,network_filtering::connection_notification>::push_front
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
               ,&local_38);
  }
  if (*param_2 != 0) {
    *(undefined4 *)(*param_2 + 0x30) = 0xc0000120;
    *(undefined8 *)(*param_2 + 0x38) = 0;
    IofCompleteRequest(*param_2,0);
    *param_2 = 0;
  }
  if (*(longlong *)(param_3 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_3 + 8),0x666e6477);
  }
  return;
}



===== operator() @ 140004054 =====

/* public: __cdecl <lambda_96fdd2ae48791c3fb7f632cc059d6327>::operator()(void * __ptr64)const
   __ptr64 */

undefined8 __thiscall
<lambda_96fdd2ae48791c3fb7f632cc059d6327>::operator()
          (<lambda_96fdd2ae48791c3fb7f632cc059d6327> *this,void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  void *_Src;
  longlong lVar3;
  size_t _Size;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)this + 8) + 0x18);
  lVar2 = *(longlong *)(*(longlong *)this + 8) + 0x20;
  lVar3 = 0;
  if (lVar1 == 1) {
    lVar3 = lVar2;
  }
  if (lVar3 == 0) {
    lVar3 = 0;
    if (lVar1 == 0) {
      lVar3 = lVar2;
    }
    if (lVar3 == 0) {
      lVar3 = 0;
      if (lVar1 == 6) {
        lVar3 = lVar2;
      }
      if (lVar3 == 0) {
        return 0;
      }
      _Size = (ulonglong)*(uint *)(lVar3 + 0x111) * 2;
      _Src = (void *)(lVar3 + 0x115);
    }
    else {
      _Size = (ulonglong)*(uint *)(lVar3 + 0x126) * 2;
      _Src = (void *)(lVar3 + 0x12a);
    }
  }
  else {
    _Size = (size_t)*(uint *)(lVar3 + 0x1a);
    _Src = (void *)(lVar3 + 0x1e);
  }
  memmove(param_1,_Src,_Size);
  return 0;
}



===== wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_><_DRIVER_OBJECT*___ptr64> @ 1400040d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl wfp_callout<class implementation::wfp_callout,class implementation::event,class
   implementation::avl_table,class implementation::queue,class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> >,class running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> >,class
   excluded_addresses<class implementation::avl_table> >::wfp_callout<class
   implementation::wfp_callout,class implementation::event,class implementation::avl_table,class
   implementation::queue,class stream_handler<class implementation::stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue> >,class
   running_processes<class implementation::running_processes,class implementation::avl_table,class
   path_list<class implementation::path_list> >,class excluded_addresses<class
   implementation::avl_table> ><struct _DRIVER_OBJECT * __ptr64>(struct _DRIVER_OBJECT *
   __ptr64,class stream_handler<class stream_handler<class implementation::stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue> > > &
   __ptr64,struct network_filtering::stream_settings & __ptr64,struct
   network_filtering::stream_settings & __ptr64,bool & __ptr64,bool & __ptr64,bool & __ptr64,bool &
   __ptr64,class running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> > & __ptr64,class
   excluded_addresses<class implementation::avl_table> & __ptr64,bool,bool,bool,bool) __ptr64 */

wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
* __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_><_DRIVER_OBJECT*___ptr64>
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,_DRIVER_OBJECT *param_1,
          stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
          *param_2,stream_settings *param_3,stream_settings *param_4,bool *param_5,bool *param_6,
          bool *param_7,bool *param_8,
          running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
          *param_9,excluded_addresses<implementation::avl_table> *param_10,bool param_11,
          bool param_12,bool param_13,bool param_14)

{
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  *pwVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  code **local_88;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  *local_80;
  _DRIVER_OBJECT **local_78;
  code **local_70;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  **local_68;
  code *local_60;
  _DRIVER_OBJECT *local_58;
  code *local_50;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  *local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  *(stream_settings **)(this + 0x18) = param_4;
  *(bool **)(this + 0x20) = param_5;
  *(bool **)(this + 0x28) = param_6;
  *(bool **)(this + 0x30) = param_7;
  *(bool **)(this + 0x38) = param_8;
  *(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
    **)(this + 0x40) = param_9;
  *(excluded_addresses<implementation::avl_table> **)(this + 0x48) = param_10;
  *(undefined4 *)this = 0xc000000d;
  this[4] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
             )0x0;
  *(stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
    **)(this + 8) = param_2;
  *(stream_settings **)(this + 0x10) = param_3;
  KeInitializeSpinLock(this + 0x50);
  this[0x58] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                )0x0;
  local_98 = 0;
  RtlInitializeGenericTableAvl
            (this + 0x60,
             <lambda_85fdb50fb359fd473c1c9c369bb5230d>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_cfa8db44f37c8b0967490b6e38287a87>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>,
             <lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::
             <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>);
  KeInitializeEvent(this + 200,0,0);
  pwVar1 = this + 0xf8;
  this[0xe4] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                )0x0;
  *(undefined8 *)(this + 0xe8) = 0;
  local_48 = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
              *)stream_delete;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xf0) = 0xc000000d;
  local_50 = stream_classify;
  this[0xf4] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                )0x0;
  local_60 = flow_established_classify;
  *(int *)pwVar1 = -0x3ffffff3;
  this[0xfc] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                )0x0;
  *(_DRIVER_OBJECT **)(this + 0x100) = param_1;
  local_58 = param_1;
  wfp_registration::wfp_registration((wfp_registration *)(this + 0x108));
  this[0x14c] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )param_11;
  *(undefined8 *)(this + 0x114) = 0;
  *(undefined8 *)(this + 0x11c) = 0;
  *(undefined8 *)(this + 0x124) = 0;
  *(undefined8 *)(this + 300) = 0;
  *(undefined8 *)(this + 0x134) = 0;
  *(undefined8 *)(this + 0x13c) = 0;
  *(undefined8 *)(this + 0x144) = 0;
  this[0x14d] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )param_12;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids);
  }
  local_88 = &local_60;
  this[0x10c] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )0x1;
  local_78 = &local_58;
  local_70 = &local_50;
  local_68 = &local_48;
  *(int *)pwVar1 = *(int *)(this + 0x108);
  local_80 = pwVar1;
  if (-1 < *(int *)(this + 0x108)) {
    iVar3 = <lambda_ecf22fe8f4e9fd5c743167dca6cf98ce>::operator()(&local_88);
    *(int *)pwVar1 = iVar3;
  }
  *(int *)(this + 0xf0) = *(int *)pwVar1;
  this[0xfc] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                )0x1;
  this[0x150] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )0x0;
  *(undefined4 *)(this + 0x158) = 0xc000000d;
  this[0x15c] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )0x0;
  *(undefined4 *)(this + 0x160) = 0xc000000d;
  this[0x164] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )0x0;
  lVar5 = NdisAllocateGenericObject(param_1,0x646e6477,0);
  *(longlong *)(this + 0x168) = lVar5;
  if (lVar5 != 0) {
    local_48 = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                *)0x10000100180;
    uStack_40 = 0x626e6477;
    lVar5 = NdisAllocateNetBufferListPool(*(undefined8 *)(this + 0x168),&local_48);
    *(longlong *)(this + 0x170) = lVar5;
    if (lVar5 != 0) {
      iVar3 = 0;
      goto LAB_14000435c;
    }
    NdisFreeGenericObject(*(undefined8 *)(this + 0x168));
  }
  iVar3 = -0x3fffffe9;
LAB_14000435c:
  *(int *)(this + 0x160) = iVar3;
  this[0x164] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )0x1;
  *(int *)(this + 0x158) = iVar3;
  if (-1 < iVar3) {
    uVar4 = FwpsInjectionHandleCreate0(0,3,this + 0x178);
    *(undefined4 *)(this + 0x158) = uVar4;
  }
  this[0x181] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )param_13;
  this[0x182] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )param_14;
  piVar2 = *(int **)(this + 8);
  this[0x180] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 )param_12;
  *(undefined1 *)(piVar2 + 1) = 1;
  iVar3 = *piVar2;
  *(int *)this = iVar3;
  if (-1 < iVar3) {
    this[0x15c] = (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                   )0x1;
    *(int *)this = *(int *)(this + 0x158);
    if (-1 < *(int *)(this + 0x158)) {
      local_48 = this;
      uVar4 = <lambda_c130f0f3a2885f5cd90f6186502765b9>::operator()
                        ((<lambda_c130f0f3a2885f5cd90f6186502765b9> *)&local_48);
      *(undefined4 *)this = uVar4;
    }
  }
  return this;
}



===== operator() @ 140004414 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl <lambda_c130f0f3a2885f5cd90f6186502765b9>::operator()(void) __ptr64 */

int __thiscall
<lambda_c130f0f3a2885f5cd90f6186502765b9>::operator()
          (<lambda_c130f0f3a2885f5cd90f6186502765b9> *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  int iVar6;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  int *piStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)this;
  local_28 = 0;
  piStack_20 = (int *)0x0;
  piVar5 = (int *)ExAllocatePoolWithTag(0x600,0x20,0x666e6477);
  if (piVar5 == (int *)0x0) {
    iVar6 = -0x3fffffe9;
  }
  else {
    if ((char)ExPoolZeroingNativelySupported == '\0') {
      piVar5[0] = 0;
      piVar5[1] = 0;
      piVar5[2] = 0;
      piVar5[3] = 0;
      piVar5[4] = 0;
      piVar5[5] = 0;
      piVar5[6] = 0;
      piVar5[7] = 0;
    }
    *piVar5 = -0x3ffffff3;
    *(undefined1 *)(piVar5 + 3) = 0;
    *(longlong *)(piVar5 + 4) = lVar3 + 200;
    *(undefined1 *)(piVar5 + 1) = 0;
    piVar5[2] = 0;
    piVar5[6] = 1;
    *(undefined1 *)(piVar5 + 3) = 1;
    iVar6 = piVar5[2];
    *piVar5 = iVar6;
    *(undefined1 *)(piVar5 + 1) = 1;
    if (iVar6 < 0) {
      LOCK();
      piVar1 = piVar5 + 6;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(*(undefined8 *)(piVar5 + 4),0,0);
        ExFreePoolWithTag(piVar5,0x666e6477);
      }
    }
    else {
      iVar6 = 0;
      piStack_20 = piVar5;
    }
  }
  local_28._0_5_ = CONCAT14(1,iVar6);
  if (-1 < iVar6) {
    iVar6 = *(int *)(*(longlong *)this + 0xf0);
    *(undefined1 *)(*(longlong *)this + 0xf4) = 1;
    if (-1 < iVar6) {
      lVar3 = *(longlong *)this;
      lVar4 = *(longlong *)(lVar3 + 0xe8);
      if (lVar4 != 0) {
        LOCK();
        piVar5 = (int *)(lVar4 + 0x18);
        iVar6 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (iVar6 == 1) {
          KeSetEvent(*(undefined8 *)(lVar4 + 0x10),0,0);
          ExFreePoolWithTag(lVar4,0x666e6477);
        }
        *(undefined8 *)(lVar3 + 0xe8) = 0;
      }
      *(int **)(lVar3 + 0xe8) = piStack_20;
      if (piStack_20 != (int *)0x0) {
        LOCK();
        piStack_20[6] = piStack_20[6] + 1;
        UNLOCK();
      }
      wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
      ::_current = *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                     **)this;
      iVar6 = 0;
    }
  }
  piVar5 = piStack_20;
  if (piStack_20 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_20 + 6;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 == 1) && (piStack_20 != (int *)0x0)) {
      KeSetEvent(*(undefined8 *)(piStack_20 + 4),0,0);
      ExFreePoolWithTag(piVar5,0x666e6477);
    }
  }
  return iVar6;
}



===== remove_contexts<unique_lock<spin_lock>_> @ 1400045f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::remove_contexts<class unique_lock<struct spin_lock> >(struct wfp_callout<class
   implementation::wfp_callout,class implementation::event,class implementation::avl_table,class
   implementation::queue,class stream_handler<class implementation::stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue> >,class
   running_processes<class implementation::running_processes,class implementation::avl_table,class
   path_list<class implementation::path_list> >,class excluded_addresses<class
   implementation::avl_table> >::flow_descriptor,bool,class unique_lock<struct spin_lock> const &
   __ptr64) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::remove_contexts<unique_lock<spin_lock>_>
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,__uint64 *param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  __uint64 _Var3;
  longlong lVar4;
  bool bVar5;
  undefined1 auStackY_58 [32];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  if (this[0x58] !=
      (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
       )0x0) {
    if (param_3 == '\0') {
      return;
    }
    KeAcquireInStackQueuedSpinLock(param_2[2] + 0x128,local_28);
    *(undefined8 *)(param_2[2] + 0x120) = 0;
    KeReleaseInStackQueuedSpinLock(local_28);
    if (this[0x181] !=
        (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
         )0x0) {
      reinject_pending_traffic(this,(flow_context *)param_2[2]);
    }
  }
  bVar5 = implementation::wfp_callout::registration::remove_contexts
                    ((registration *)(this + 0xf8),*param_2,SUB81(param_2[1],0),
                     *(bool *)((longlong)param_2 + 9),*(char *)(param_2[2] + 0x10) != '\x02',true);
  if (!bVar5) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_SqI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
    }
    _Var3 = param_2[2];
    lVar4 = *(longlong *)(_Var3 + 0x138);
    if (lVar4 != 0) {
      LOCK();
      piVar1 = (int *)(lVar4 + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(*(undefined8 *)(lVar4 + 0x10),0,0);
        ExFreePoolWithTag(lVar4,0x666e6477);
      }
    }
    *(undefined8 *)(_Var3 + 0x138) = 0;
  }
  return;
}



===== swap<shared_ptr<path_list<implementation::path_list>_>_> @ 140004750 =====

/* void __cdecl swap<class shared_ptr<class path_list<class implementation::path_list> > >(class
   shared_ptr<class path_list<class implementation::path_list> > & __ptr64,class shared_ptr<class
   path_list<class implementation::path_list> > & __ptr64) */

void __cdecl
swap<shared_ptr<path_list<implementation::path_list>_>_>
          (shared_ptr<path_list<implementation::path_list>_> *param_1,
          shared_ptr<path_list<implementation::path_list>_> *param_2)

{
  longlong lVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uStack_10 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = 0;
  lVar1 = *(longlong *)(param_2 + 8);
  local_18 = 0xc000000d;
  *(longlong *)(param_1 + 8) = lVar1;
  if (lVar1 != 0) {
    LOCK();
    *(int *)(lVar1 + 0x30) = *(int *)(lVar1 + 0x30) + 1;
    UNLOCK();
  }
  shared_ptr<path_list<implementation::path_list>_>::operator=
            (param_2,(shared_ptr<class_path_list<class_implementation::path_list>_> *)&local_18);
  shared_ptr<path_list<implementation::path_list>_>::
  ~shared_ptr<path_list<implementation::path_list>_>
            ((shared_ptr<path_list<implementation::path_list>_> *)&local_18);
  return;
}



===== complete_irp<<lambda_96fdd2ae48791c3fb7f632cc059d6327>_const&___ptr64> @ 1400047ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static bool __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp<class
   <lambda_96fdd2ae48791c3fb7f632cc059d6327> const & __ptr64>(class irp<class
   implementation::irp>,struct network_filtering::connection_notification const & __ptr64,class
   <lambda_96fdd2ae48791c3fb7f632cc059d6327> const & __ptr64) */

bool __cdecl
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp<<lambda_96fdd2ae48791c3fb7f632cc059d6327>_const&___ptr64>
          (irp<implementation::irp> *param_1,undefined8 *param_2,
          <lambda_96fdd2ae48791c3fb7f632cc059d6327> *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char cVar8;
  bool bVar9;
  int iVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  connection_notification *pcVar15;
  __uint64 _Var16;
  connection_notification *pcVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  uint uVar20;
  connection_notification *pcVar21;
  undefined1 auStack_1d8 [32];
  connection_notification *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined1 uStack_e4;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1d8;
  bVar9 = true;
  lVar11 = param_2[1];
  if (lVar11 == 1) {
    iVar10 = *(uint *)((longlong)param_2 + 0x2a) - 0x10c;
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      iVar10 = 0;
    }
  }
  else if (lVar11 == 6) {
    uVar20 = *(int *)((longlong)param_2 + 0x121) * 2;
    iVar10 = 0;
    if (0x15 < uVar20) {
      iVar10 = uVar20 - 0x15;
    }
  }
  else if (lVar11 == 0) {
    iVar10 = *(int *)((longlong)param_2 + 0x136) * 2;
  }
  else {
    iVar10 = 0;
  }
  uVar20 = iVar10 + 0x13a;
  puVar19 = param_2 + 2;
  local_1b8 = (connection_notification *)0x0;
  uStack_1b0 = 0;
  if (lVar11 == 1) {
    _Var16 = (__uint64)(*(uint *)((longlong)param_2 + 0x2a) - 0x10c);
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      _Var16 = 0;
    }
  }
  else if (lVar11 == 6) {
    uVar2 = *(int *)((longlong)param_2 + 0x121) * 2;
    _Var16 = 0;
    if (0x15 < uVar2) {
      _Var16 = (__uint64)(uVar2 - 0x15);
    }
  }
  else if (lVar11 == 0) {
    _Var16 = (__uint64)(uint)(*(int *)((longlong)param_2 + 0x136) * 2);
  }
  else {
    _Var16 = 0;
  }
  cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_1,_Var16,
                     (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
  pcVar21 = local_1b8;
  if (cVar8 == '\0') {
    cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                      (param_1,0,
                       (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
    if (cVar8 == '\0') {
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
    }
    else {
      local_48 = 0;
      uVar13 = KeQueryInterruptTimePrecise(&local_48);
      *(undefined8 *)local_1b8 = uVar13;
      *(undefined8 *)(local_1b8 + 8) = 2;
      *(uint *)(local_1b8 + 0x10) = uVar20;
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0x13a;
    }
    IofCompleteRequest(*(undefined8 *)param_1,0);
    bVar9 = false;
    goto LAB_140004d71;
  }
  local_48 = (ulonglong)uVar20;
  memset(local_1b8,0,(ulonglong)uVar20);
  lVar11 = param_2[1];
  puVar12 = (undefined8 *)0x0;
  if (lVar11 == 0) {
    puVar12 = puVar19;
  }
  if (puVar12 == (undefined8 *)0x0) {
    puVar12 = (undefined8 *)0x0;
    if (lVar11 == 1) {
      puVar12 = puVar19;
    }
    if (puVar12 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0x0;
      if (lVar11 == 3) {
        puVar12 = puVar19;
      }
      if (puVar12 == (undefined8 *)0x0) {
        puVar12 = (undefined8 *)0x0;
        if (lVar11 == 4) {
          puVar12 = puVar19;
        }
        if (puVar12 == (undefined8 *)0x0) {
          puVar12 = (undefined8 *)0x0;
          if (lVar11 == 5) {
            puVar12 = puVar19;
          }
          if (puVar12 == (undefined8 *)0x0) {
            puVar12 = (undefined8 *)0x0;
            if (lVar11 == 6) {
              puVar12 = puVar19;
            }
            if (puVar12 == (undefined8 *)0x0) {
              puVar12 = (undefined8 *)0x0;
              if (lVar11 == 7) {
                puVar12 = puVar19;
              }
              if (puVar12 == (undefined8 *)0x0) {
                lVar11 = 2;
                pcVar17 = pcVar21;
                do {
                  puVar19 = param_2;
                  pcVar15 = pcVar17;
                  uVar13 = puVar19[1];
                  *(undefined8 *)pcVar15 = *puVar19;
                  *(undefined8 *)(pcVar15 + 8) = uVar13;
                  uVar13 = puVar19[3];
                  *(undefined8 *)(pcVar15 + 0x10) = puVar19[2];
                  *(undefined8 *)(pcVar15 + 0x18) = uVar13;
                  uVar13 = puVar19[5];
                  *(undefined8 *)(pcVar15 + 0x20) = puVar19[4];
                  *(undefined8 *)(pcVar15 + 0x28) = uVar13;
                  uVar13 = puVar19[7];
                  *(undefined8 *)(pcVar15 + 0x30) = puVar19[6];
                  *(undefined8 *)(pcVar15 + 0x38) = uVar13;
                  uVar13 = puVar19[9];
                  *(undefined8 *)(pcVar15 + 0x40) = puVar19[8];
                  *(undefined8 *)(pcVar15 + 0x48) = uVar13;
                  uVar13 = puVar19[0xb];
                  *(undefined8 *)(pcVar15 + 0x50) = puVar19[10];
                  *(undefined8 *)(pcVar15 + 0x58) = uVar13;
                  uVar13 = puVar19[0xd];
                  *(undefined8 *)(pcVar15 + 0x60) = puVar19[0xc];
                  *(undefined8 *)(pcVar15 + 0x68) = uVar13;
                  uVar13 = puVar19[0xf];
                  *(undefined8 *)(pcVar15 + 0x70) = puVar19[0xe];
                  *(undefined8 *)(pcVar15 + 0x78) = uVar13;
                  lVar11 = lVar11 + -1;
                  pcVar17 = pcVar15 + 0x80;
                  param_2 = puVar19 + 0x10;
                } while (lVar11 != 0);
                uVar13 = puVar19[0x11];
                *(undefined8 *)(pcVar15 + 0x80) = puVar19[0x10];
                *(undefined8 *)(pcVar15 + 0x88) = uVar13;
                uVar13 = puVar19[0x13];
                *(undefined8 *)(pcVar15 + 0x90) = puVar19[0x12];
                *(undefined8 *)(pcVar15 + 0x98) = uVar13;
                uVar1 = *(undefined4 *)((longlong)puVar19 + 0xa4);
                uVar3 = *(undefined4 *)(puVar19 + 0x15);
                uVar4 = *(undefined4 *)((longlong)puVar19 + 0xac);
                *(undefined4 *)(pcVar15 + 0xa0) = *(undefined4 *)(puVar19 + 0x14);
                *(undefined4 *)(pcVar15 + 0xa4) = uVar1;
                *(undefined4 *)(pcVar15 + 0xa8) = uVar3;
                *(undefined4 *)(pcVar15 + 0xac) = uVar4;
                *(undefined8 *)(pcVar15 + 0xb0) = puVar19[0x16];
                *(undefined2 *)(pcVar15 + 0xb8) = *(undefined2 *)(puVar19 + 0x17);
              }
              else {
                local_1b8 = (connection_notification *)*puVar19;
                uStack_1b0 = param_2[3];
                local_1a8 = param_2[4];
                uStack_1a0 = param_2[5];
                local_198 = param_2[6];
                network_filtering::connection_notification::connection_notification
                          (pcVar21,(volume_update *)&local_1b8);
              }
            }
            else {
              lVar11 = 2;
              puVar12 = &local_178;
              do {
                puVar18 = puVar19;
                puVar14 = puVar12;
                uVar13 = puVar18[1];
                uVar5 = puVar18[2];
                uVar6 = puVar18[3];
                *puVar14 = *puVar18;
                puVar14[1] = uVar13;
                uVar13 = puVar18[4];
                uVar7 = puVar18[5];
                puVar14[2] = uVar5;
                puVar14[3] = uVar6;
                uVar5 = puVar18[6];
                uVar6 = puVar18[7];
                puVar14[4] = uVar13;
                puVar14[5] = uVar7;
                uVar13 = puVar18[8];
                uVar7 = puVar18[9];
                puVar14[6] = uVar5;
                puVar14[7] = uVar6;
                uVar5 = puVar18[10];
                uVar6 = puVar18[0xb];
                puVar14[8] = uVar13;
                puVar14[9] = uVar7;
                uVar13 = puVar18[0xc];
                uVar7 = puVar18[0xd];
                puVar14[10] = uVar5;
                puVar14[0xb] = uVar6;
                uVar5 = puVar18[0xe];
                uVar6 = puVar18[0xf];
                puVar14[0xc] = uVar13;
                puVar14[0xd] = uVar7;
                puVar14[0xe] = uVar5;
                puVar14[0xf] = uVar6;
                lVar11 = lVar11 + -1;
                puVar12 = puVar14 + 0x10;
                puVar19 = puVar18 + 0x10;
              } while (lVar11 != 0);
              uVar1 = *(undefined4 *)(puVar18 + 0x12);
              uVar13 = puVar18[0x11];
              puVar14[0x10] = puVar18[0x10];
              puVar14[0x11] = uVar13;
              *(undefined4 *)(puVar14 + 0x12) = uVar1;
              *(undefined1 *)((longlong)puVar14 + 0x94) = *(undefined1 *)((longlong)puVar18 + 0x94);
              network_filtering::connection_notification::connection_notification
                        (pcVar21,(connection_aborted *)&local_178);
            }
          }
          else {
            lVar11 = 2;
            puVar12 = &local_178;
            do {
              puVar18 = puVar19;
              puVar14 = puVar12;
              uVar13 = puVar18[1];
              uVar5 = puVar18[2];
              uVar6 = puVar18[3];
              *puVar14 = *puVar18;
              puVar14[1] = uVar13;
              uVar13 = puVar18[4];
              uVar7 = puVar18[5];
              puVar14[2] = uVar5;
              puVar14[3] = uVar6;
              uVar5 = puVar18[6];
              uVar6 = puVar18[7];
              puVar14[4] = uVar13;
              puVar14[5] = uVar7;
              uVar13 = puVar18[8];
              uVar7 = puVar18[9];
              puVar14[6] = uVar5;
              puVar14[7] = uVar6;
              uVar5 = puVar18[10];
              uVar6 = puVar18[0xb];
              puVar14[8] = uVar13;
              puVar14[9] = uVar7;
              uVar13 = puVar18[0xc];
              uVar7 = puVar18[0xd];
              puVar14[10] = uVar5;
              puVar14[0xb] = uVar6;
              uVar5 = puVar18[0xe];
              uVar6 = puVar18[0xf];
              puVar14[0xc] = uVar13;
              puVar14[0xd] = uVar7;
              puVar14[0xe] = uVar5;
              puVar14[0xf] = uVar6;
              lVar11 = lVar11 + -1;
              puVar12 = puVar14 + 0x10;
              puVar19 = puVar18 + 0x10;
            } while (lVar11 != 0);
            uVar1 = *(undefined4 *)(puVar18 + 0x12);
            uVar13 = puVar18[0x11];
            puVar14[0x10] = puVar18[0x10];
            puVar14[0x11] = uVar13;
            *(undefined4 *)(puVar14 + 0x12) = uVar1;
            *(undefined1 *)((longlong)puVar14 + 0x94) = *(undefined1 *)((longlong)puVar18 + 0x94);
            network_filtering::connection_notification::connection_notification
                      (pcVar21,(auth_connect *)&local_178);
          }
        }
        else {
          local_178 = *puVar19;
          uStack_170 = param_2[3];
          local_168 = param_2[4];
          uStack_160 = param_2[5];
          local_e8 = *(undefined4 *)(param_2 + 0x14);
          local_158 = param_2[6];
          uStack_150 = param_2[7];
          local_148 = param_2[8];
          uStack_140 = param_2[9];
          local_138 = param_2[10];
          uStack_130 = param_2[0xb];
          local_128 = param_2[0xc];
          uStack_120 = param_2[0xd];
          local_118 = param_2[0xe];
          uStack_110 = param_2[0xf];
          local_f8 = param_2[0x12];
          uStack_f0 = param_2[0x13];
          local_108 = param_2[0x10];
          uStack_100 = param_2[0x11];
          uStack_e4 = *(undefined1 *)((longlong)param_2 + 0xa4);
          network_filtering::connection_notification::connection_notification
                    (pcVar21,(port_open *)&local_178);
        }
      }
      else {
        local_1b8 = (connection_notification *)*puVar19;
        uStack_1b0 = param_2[3];
        local_1a8 = param_2[4];
        uStack_1a0 = param_2[5];
        local_198 = param_2[6];
        uStack_190 = param_2[7];
        local_188 = param_2[8];
        network_filtering::connection_notification::connection_notification
                  (pcVar21,(connection_close *)&local_1b8);
      }
    }
    else {
      local_1b8 = (connection_notification *)*puVar19;
      uStack_1b0 = param_2[3];
      local_1a8 = param_2[4];
      uStack_1a0 = CONCAT26(uStack_1a0._6_2_,*(undefined6 *)(param_2 + 5));
      network_filtering::connection_notification::connection_notification
                (pcVar21,(stream_segment *)&local_1b8);
    }
  }
  else {
    lVar11 = 2;
    puVar12 = &local_178;
    do {
      puVar18 = puVar19;
      puVar14 = puVar12;
      uVar13 = puVar18[1];
      uVar5 = puVar18[2];
      uVar6 = puVar18[3];
      *puVar14 = *puVar18;
      puVar14[1] = uVar13;
      uVar13 = puVar18[4];
      uVar7 = puVar18[5];
      puVar14[2] = uVar5;
      puVar14[3] = uVar6;
      uVar5 = puVar18[6];
      uVar6 = puVar18[7];
      puVar14[4] = uVar13;
      puVar14[5] = uVar7;
      uVar13 = puVar18[8];
      uVar7 = puVar18[9];
      puVar14[6] = uVar5;
      puVar14[7] = uVar6;
      uVar5 = puVar18[10];
      uVar6 = puVar18[0xb];
      puVar14[8] = uVar13;
      puVar14[9] = uVar7;
      uVar13 = puVar18[0xc];
      uVar7 = puVar18[0xd];
      puVar14[10] = uVar5;
      puVar14[0xb] = uVar6;
      uVar5 = puVar18[0xe];
      uVar6 = puVar18[0xf];
      puVar14[0xc] = uVar13;
      puVar14[0xd] = uVar7;
      puVar14[0xe] = uVar5;
      puVar14[0xf] = uVar6;
      lVar11 = lVar11 + -1;
      puVar12 = puVar14 + 0x10;
      puVar19 = puVar18 + 0x10;
    } while (lVar11 != 0);
    uVar13 = puVar18[0x14];
    uVar5 = puVar18[0x11];
    uVar6 = puVar18[0x12];
    uVar7 = puVar18[0x13];
    puVar14[0x10] = puVar18[0x10];
    puVar14[0x11] = uVar5;
    puVar14[0x12] = uVar6;
    puVar14[0x13] = uVar7;
    puVar14[0x14] = uVar13;
    *(undefined2 *)(puVar14 + 0x15) = *(undefined2 *)(puVar18 + 0x15);
    network_filtering::connection_notification::connection_notification
              (pcVar21,(connection_information *)&local_178);
  }
  lVar11 = *(longlong *)(pcVar21 + 8);
  pcVar21 = pcVar21 + 0x10;
  pcVar17 = (connection_notification *)0x0;
  if (lVar11 == 1) {
    pcVar17 = pcVar21;
  }
  if (pcVar17 == (connection_notification *)0x0) {
    pcVar17 = (connection_notification *)0x0;
    if (lVar11 == 0) {
      pcVar17 = pcVar21;
    }
    if (pcVar17 != (connection_notification *)0x0) {
      pcVar17 = pcVar17 + 0x12a;
      goto LAB_140004c8c;
    }
    pcVar17 = (connection_notification *)0x0;
    if (lVar11 == 6) {
      pcVar17 = pcVar21;
    }
    if (pcVar17 != (connection_notification *)0x0) {
      pcVar17 = pcVar17 + 0x115;
      goto LAB_140004c8c;
    }
  }
  else {
    pcVar17 = pcVar17 + 0x1e;
LAB_140004c8c:
    iVar10 = <lambda_96fdd2ae48791c3fb7f632cc059d6327>::operator()(param_3,pcVar17);
    if (iVar10 != 0) {
      LOG_WARNING(L"Failed to write stream data into IRP");
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
      IofCompleteRequest(*(undefined8 *)param_1,0);
      bVar9 = false;
      goto LAB_140004d71;
    }
  }
  *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
  *(ulonglong *)(*(longlong *)param_1 + 0x38) = local_48;
  IofCompleteRequest(*(undefined8 *)param_1,0);
LAB_140004d71:
  *(undefined8 *)param_1 = 0;
  return bVar9;
}



===== release @ 140004da0 =====

/* public: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_context::release(void) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::flow_context::release(flow_context *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  LOCK();
  iVar2 = *(int *)this;
  *(int *)this = *(int *)this + -1;
  UNLOCK();
  if (iVar2 == 1) {
    lVar3 = *(longlong *)(this + 0x138);
    if (lVar3 != 0) {
      LOCK();
      *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + 1;
      UNLOCK();
    }
    if (this != (flow_context *)0x0) {
      ~flow_context(this);
      ExFreePoolWithTag(this,0x666e6477);
    }
    if (lVar3 != 0) {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        KeSetEvent(*(undefined8 *)(lVar3 + 0x10),0,0);
        ExFreePoolWithTag(lVar3,0x666e6477);
      }
    }
  }
  return;
}



===== pop_front @ 140004e38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class queue_element<class net_buffer_list,class implementation::queue<class
   net_buffer_list>::element_impl> __cdecl queue<class implementation::queue,class
   net_buffer_list>::pop_front(void) __ptr64 */

void __thiscall
queue<implementation::queue,net_buffer_list>::pop_front
          (queue<implementation::queue,net_buffer_list> *this)

{
  code *pcVar1;
  longlong *plVar2;
  uint *puVar3;
  undefined4 *in_RDX;
  longlong *plVar4;
  queue<implementation::queue,net_buffer_list> *pqVar5;
  undefined1 *puVar6;
  longlong lVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  KeAcquireInStackQueuedSpinLock(this,local_28);
  puVar6 = auStack_48;
  pqVar5 = this + 8;
  if (*(queue<implementation::queue,net_buffer_list> **)pqVar5 != pqVar5) {
    LOCK();
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
    UNLOCK();
    plVar4 = *(longlong **)pqVar5;
    if (((queue<implementation::queue,net_buffer_list> *)plVar4[1] == pqVar5) &&
       (lVar7 = *plVar4, *(longlong **)(lVar7 + 8) == plVar4)) {
      *(longlong *)pqVar5 = lVar7;
      *(queue<implementation::queue,net_buffer_list> **)(lVar7 + 8) = pqVar5;
      lVar7 = (ulonglong)*(uint *)((longlong)plVar4 + 0xbc) + plVar4[0x18] * 8;
      plVar2 = (longlong *)0x0;
      if (plVar4[3] == 1) {
        plVar2 = plVar4 + 4;
      }
      if (plVar2 != (longlong *)0x0) {
        puVar3 = (uint *)&DAT_00000088;
        if (plVar4[3] == 1) {
          puVar3 = (uint *)(plVar4 + 0x15);
        }
        lVar7 = lVar7 + (ulonglong)*puVar3;
      }
      *(longlong *)(this + 0x20) = (*(longlong *)(this + 0x20) - lVar7) + -0x10;
      puVar6 = auStack_48;
      goto LAB_140004ef1;
    }
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(3);
    puVar6 = auStack_40;
  }
  plVar4 = (longlong *)0x0;
LAB_140004ef1:
  *in_RDX = 0xc000000d;
  *(undefined1 *)(in_RDX + 1) = 0;
  *(longlong **)(in_RDX + 2) = plVar4;
  *(undefined8 *)(puVar6 + -8) = 0x140004f19;
  KeReleaseInStackQueuedSpinLock(puVar6 + 0x20);
  *(undefined8 *)(puVar6 + -8) = 0x140004f2e;
  return;
}



===== transport_delete @ 140004f40 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::transport_delete(unsigned short,unsigned int,unsigned __int64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::transport_delete(ushort param_1,uint param_2,__uint64 param_3)

{
  LOG_VERBOSE_UINT64(L"Transport delete, flow id",*(__uint64 *)(param_3 + 8));
  flow_context::release((flow_context *)param_3);
  return;
}



===== stream_delete @ 140004f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::stream_delete(unsigned short,unsigned int,unsigned __int64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::stream_delete(ushort param_1,uint param_2,__uint64 param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
  *this;
  ushort uVar8;
  __uint64 _Var9;
  uint in_R9D;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  longlong local_58 [2];
  longlong local_48;
  undefined1 local_40 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 0;
  _Var9 = param_3;
  KeAcquireInStackQueuedSpinLock(param_3 + 0x128,local_40);
  uVar8 = (ushort)_Var9;
  this = *(wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           **)(param_3 + 0x120);
  if (this == (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               *)0x0) {
    local_58[0] = 0;
    plVar6 = local_58;
    bVar4 = false;
    bVar3 = true;
    lVar7 = 0;
  }
  else {
    lVar7 = *(longlong *)(this + 0xe8);
    if (lVar7 != 0) {
      LOCK();
      *(int *)(lVar7 + 0x18) = *(int *)(lVar7 + 0x18) + 1;
      UNLOCK();
      this = *(wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               **)(param_3 + 0x120);
    }
    bVar4 = true;
    bVar3 = false;
    plVar6 = &local_48;
    local_48 = lVar7;
  }
  *plVar6 = 0;
  lVar5 = local_58[0];
  if (bVar3) {
    if (local_58[0] != 0) {
      LOCK();
      piVar1 = (int *)(local_58[0] + 0x18);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        uVar8 = 0;
        KeSetEvent(*(undefined8 *)(local_58[0] + 0x10),0);
        ExFreePoolWithTag(lVar5,0x666e6477);
      }
    }
  }
  lVar5 = local_48;
  if ((bVar4) && (local_48 != 0)) {
    LOCK();
    piVar1 = (int *)(local_48 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      uVar8 = 0;
      KeSetEvent(*(undefined8 *)(local_48 + 0x10),0);
      ExFreePoolWithTag(lVar5,0x666e6477);
    }
  }
  KeReleaseInStackQueuedSpinLock(local_40);
  if (this != (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               *)0x0) {
    stream_delete_(this,(flow_context *)param_3,uVar8,in_R9D);
  }
  LOG_VERBOSE_UINT64(L"Stream delete, flow id",*(__uint64 *)(param_3 + 8));
  flow_context::release((flow_context *)param_3);
  if (lVar7 != 0) {
    LOCK();
    piVar1 = (int *)(lVar7 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(*(undefined8 *)(lVar7 + 0x10),0,0);
      ExFreePoolWithTag(lVar7,0x666e6477);
    }
  }
  return;
}



===== auth_connect_classify @ 140005130 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::auth_connect_classify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER2_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::auth_connect_classify
          (FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,void *param_3,
          void *param_4,FWPS_FILTER2_ *param_5,__uint64 param_6,FWPS_CLASSIFY_OUT0_ *param_7)

{
  if (_current !=
      (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
       *)0x0) {
    auth_connect_classify_
              ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                *)param_1,param_1,param_2,param_7);
  }
  return;
}



===== resource_assignment_classify @ 140005160 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::resource_assignment_classify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER2_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::resource_assignment_classify
          (FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,void *param_3,
          void *param_4,FWPS_FILTER2_ *param_5,__uint64 param_6,FWPS_CLASSIFY_OUT0_ *param_7)

{
  if (_current !=
      (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
       *)0x0) {
    resource_assignment_classify_
              ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                *)param_1,param_1,param_2,param_7);
  }
  return;
}



===== stream_classify @ 140005190 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::stream_classify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER2_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::stream_classify(FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,
                 void *param_3,void *param_4,FWPS_FILTER2_ *param_5,__uint64 param_6,
                 FWPS_CLASSIFY_OUT0_ *param_7)

{
  stream_classify_((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                    *)param_1,param_1,param_2,param_3,param_5,param_6,param_7);
  return;
}



===== transport_classify @ 1400051a0 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::transport_classify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER2_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::transport_classify
          (FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,void *param_3,
          void *param_4,FWPS_FILTER2_ *param_5,__uint64 param_6,FWPS_CLASSIFY_OUT0_ *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  
  pwVar3 = _current;
  if (_current !=
      (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
       *)0x0) {
    uVar1 = *(uint *)(*(longlong *)(_current + 8) + 0x30);
    uVar2 = *(ulonglong *)(*(longlong *)(_current + 8) + 0x38);
    if ((uVar1 < 0x2711) && (uVar2 < 0x6400001)) {
      if ((uVar1 < 5000) && (uVar2 < 0x3200000)) {
        _current[0x150] =
             (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
              )0x0;
      }
    }
    else {
      uVar5 = uVar2;
      if (uVar2 < 0x6400001) {
        uVar5 = (longlong)(int)uVar1;
      }
      pwVar4 = L"Stream Handler Queue Allocation at maximum";
      if (uVar2 < 0x6400001) {
        pwVar4 = L"Stream Handler Queue Length at maximum";
      }
      LOG_WARNING_UINT64(pwVar4,uVar5);
      pwVar3[0x150] =
           (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
            )0x1;
    }
    if ((pwVar3[0x150] ==
         (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
          )0x0) || (*(char *)(param_6 + 0x1f8) != '\0')) {
      *(longlong *)(param_6 + 0x178) = *(longlong *)(param_6 + 0x178) + 1;
      *(undefined4 *)param_7 = 0x1002;
    }
    else {
      LOG_WARNING(L"Drop TCP packet");
      *(longlong *)(param_6 + 0x180) = *(longlong *)(param_6 + 0x180) + 1;
      *(uint *)(param_7 + 0x18) = *(uint *)(param_7 + 0x18) & 0xfffffffe;
      *(uint *)(param_7 + 0x1c) = *(uint *)(param_7 + 0x1c) | 1;
      *(undefined4 *)param_7 = 0x1001;
    }
  }
  return;
}



===== injection_complete @ 140005280 =====

/* public: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::injection_complete(void * __ptr64,struct _NET_BUFFER_LIST * __ptr64,unsigned char) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::injection_complete(void *param_1,_NET_BUFFER_LIST *param_2,uchar param_3)

{
  if (param_1 != (void *)0x0) {
    net_buffer_list::~net_buffer_list((net_buffer_list *)((longlong)param_1 + 0x10));
    ExFreePoolWithTag(param_1,0x666e6477);
  }
  return;
}



===== reload @ 1400052b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl excluded_addresses<class implementation::avl_table>::reload(struct
   sockaddr_storage const * __ptr64,unsigned __int64) __ptr64 */

long __thiscall
excluded_addresses<implementation::avl_table>::reload
          (excluded_addresses<implementation::avl_table> *this,sockaddr_storage *param_1,
          __uint64 param_2)

{
  sockaddr_storage *psVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined1 auStack_78 [48];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char local_38 [8];
  undefined4 local_30 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  uVar6 = 0;
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      lVar3 = uVar2 * 0x80;
      local_38[0] = '\0';
      if (*(short *)(param_1 + lVar3) == 2) {
        local_30[0] = *(undefined4 *)(param_1 + lVar3 + 4);
        puVar4 = (undefined4 *)RtlInsertElementGenericTableAvl(this + 0x10,local_30,4);
        if ((puVar4 != (undefined4 *)0x0) && (local_38[0] == '\0')) {
          *puVar4 = local_30[0];
        }
      }
      else {
        psVar1 = param_1 + lVar3 + 8;
        local_48 = *(undefined4 *)psVar1;
        uStack_44 = *(undefined4 *)(psVar1 + 4);
        uStack_40 = *(undefined4 *)(psVar1 + 8);
        uStack_3c = *(undefined4 *)(psVar1 + 0xc);
        puVar5 = (undefined8 *)RtlInsertElementGenericTableAvl(this + 0x78,&local_48,0x10,local_38);
        if ((puVar5 != (undefined8 *)0x0) && (local_38[0] == '\0')) {
          *puVar5 = CONCAT44(uStack_44,local_48);
          puVar5[1] = CONCAT44(uStack_3c,uStack_40);
        }
      }
      uVar6 = uVar6 + 1;
      uVar2 = (ulonglong)uVar6;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== ~flow_context @ 1400053a8 =====

/* public: __cdecl wfp_callout<class implementation::wfp_callout,class implementation::event,class
   implementation::avl_table,class implementation::queue,class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> >,class running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> >,class
   excluded_addresses<class implementation::avl_table> >::flow_context::~flow_context(void) __ptr64
    */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::flow_context::~flow_context(flow_context *this)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong local_10;
  
  while (*(int *)(this + 0x1e0) != 0) {
    queue<implementation::queue,net_buffer_list>::pop_front
              ((queue<implementation::queue,net_buffer_list> *)(this + 0x1c8));
    if (local_10 != 0) {
      net_buffer_list::~net_buffer_list((net_buffer_list *)(local_10 + 0x10));
      ExFreePoolWithTag(local_10,0x666e6477);
    }
  }
  while (*(int *)(this + 0x1b8) != 0) {
    queue<implementation::queue,net_buffer_list>::pop_front
              ((queue<implementation::queue,net_buffer_list> *)(this + 0x1a0));
    if (local_10 != 0) {
      net_buffer_list::~net_buffer_list((net_buffer_list *)(local_10 + 0x10));
      ExFreePoolWithTag(local_10,0x666e6477);
    }
  }
  lVar3 = *(longlong *)(this + 400);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x20);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(lVar3 + 0x10) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x10),0x666e6477);
      }
      ExFreePoolWithTag(lVar3,0x666e6477);
    }
  }
  lVar3 = *(longlong *)(this + 0x138);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(*(undefined8 *)(lVar3 + 0x10),0,0);
      ExFreePoolWithTag(lVar3,0x666e6477);
    }
  }
  return;
}



===== shared_ptr<path_list<implementation::path_list>_><> @ 1400054dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl shared_ptr<class path_list<class implementation::path_list> >::shared_ptr<class
   path_list<class implementation::path_list> ><>(struct in_place_t) __ptr64 */

shared_ptr<path_list<implementation::path_list>_> * __thiscall
shared_ptr<path_list<implementation::path_list>_>::
shared_ptr<path_list<implementation::path_list>_><>
          (shared_ptr<path_list<implementation::path_list>_> *this)

{
  int iVar1;
  undefined1 auStack_48 [32];
  int **local_28;
  undefined1 local_20;
  int *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  this[4] = (shared_ptr<path_list<implementation::path_list>_>)0x0;
  *(undefined4 *)this = 0xc000000d;
  *(undefined8 *)(this + 8) = 0;
  local_18 = (int *)ExAllocatePoolWithTag(0x600,0x38,0x666e6477);
  if (local_18 == (int *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    if ((char)ExPoolZeroingNativelySupported == '\0') {
      local_18[0] = 0;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      local_18[4] = 0;
      local_18[5] = 0;
      local_18[6] = 0;
      local_18[7] = 0;
      local_18[8] = 0;
      local_18[9] = 0;
      local_18[10] = 0;
      local_18[0xb] = 0;
      local_18[0xc] = 0;
      local_18[0xd] = 0;
    }
    *local_18 = -0x3ffffff3;
    *(undefined1 *)(local_18 + 1) = 0;
    *(undefined1 *)(local_18 + 3) = 0;
    *(undefined1 *)((longlong)local_18 + 0x11) = 0;
    local_18[6] = 0;
    local_18[7] = 0;
    local_18[8] = 0;
    local_18[9] = 0;
    local_18[10] = 0;
    local_18[0xb] = 0;
    local_18[2] = 0;
    *local_18 = local_18[2];
    local_28 = &local_18;
    local_18[0xc] = 1;
    *(undefined1 *)(local_18 + 3) = 1;
    iVar1 = *local_18;
    *(undefined1 *)(local_18 + 1) = 1;
    local_20 = 1;
    if (iVar1 < 0) {
      `auto___cdecl_scope_exit<<lambda_117755146cfb628ec8e28b6b05fe2077>_>(<lambda_117755146cfb628ec8e28b6b05fe2077>)'
      ::__l2::scope_exit::~scope_exit((scope_exit *)&local_28);
    }
    else {
      *(int **)(this + 8) = local_18;
      local_20 = 0;
      `auto___cdecl_scope_exit<<lambda_117755146cfb628ec8e28b6b05fe2077>_>(<lambda_117755146cfb628ec8e28b6b05fe2077>)'
      ::__l2::scope_exit::~scope_exit((scope_exit *)&local_28);
      iVar1 = 0;
    }
  }
  *(int *)this = iVar1;
  return this;
}



===== operator= @ 1400055e8 =====

/* public: class shared_ptr<class path_list<class implementation::path_list> > & __ptr64 __cdecl
   shared_ptr<class path_list<class implementation::path_list> >::operator=(class shared_ptr<class
   path_list<class implementation::path_list> > const & __ptr64) __ptr64 */

shared_ptr<class_path_list<class_implementation::path_list>_> * __thiscall
shared_ptr<path_list<implementation::path_list>_>::operator=
          (shared_ptr<path_list<implementation::path_list>_> *this,
          shared_ptr<class_path_list<class_implementation::path_list>_> *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(this + 8);
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0x30);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(longlong *)(lVar3 + 0x20) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0x666e6477);
      }
      if (*(longlong *)(lVar3 + 0x18) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0x666e6477);
      }
      ExFreePoolWithTag(lVar3,0x666e6477);
    }
    *(undefined8 *)(this + 8) = 0;
  }
  lVar3 = *(longlong *)(param_1 + 8);
  *(longlong *)(this + 8) = lVar3;
  if (lVar3 != 0) {
    LOCK();
    *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
    UNLOCK();
  }
  return (shared_ptr<class_path_list<class_implementation::path_list>_> *)this;
}



===== stream_delete_ @ 140005688 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::stream_delete_(struct wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_context * __ptr64,unsigned short,unsigned int) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::stream_delete_(wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 *this,flow_context *param_1,ushort param_2,uint param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  undefined6 in_register_00000082;
  undefined1 auStack_208 [32];
  undefined8 local_1e8;
  undefined2 uStack_1e0;
  undefined2 uStack_1de;
  undefined2 uStack_1dc;
  undefined2 uStack_1da;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined8 local_188;
  connection_notification local_178 [320];
  undefined1 local_38 [24];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_208;
  local_1d0 = *(undefined8 *)(param_1 + 8);
  lVar1 = *(longlong *)(this + 8);
  local_1c8 = *(undefined8 *)(param_1 + 0x140);
  local_1c0 = *(undefined8 *)(param_1 + 0x148);
  local_1b8 = *(undefined8 *)(param_1 + 0x178);
  local_1b0 = *(undefined8 *)(param_1 + 0x180);
  local_1a8 = *(undefined8 *)(param_1 + 0x168);
  local_1a0 = *(undefined8 *)(param_1 + 0x170);
  network_filtering::connection_notification::connection_notification
            (local_178,(connection_close *)&local_1d0);
  implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
  ::enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_>
            ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *)
             (lVar1 + 0x10),local_178,
             (<lambda_1da06d3c8846a479bc1e63eaf264472e> *)CONCAT62(in_register_00000082,param_2));
  KeAcquireInStackQueuedSpinLock(this + 0x50,local_38);
  if (this[0x58] ==
      (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
       )0x0) {
    uVar2 = *(undefined8 *)(param_1 + 8);
    uStack_1e0 = 0;
    uStack_1de = 0;
    uStack_1dc = 0;
    uStack_1da = 0;
    local_1e8._0_4_ = (undefined4)uVar2;
    local_1e8._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_1d8 = 0;
    local_198 = (undefined4)local_1e8;
    uStack_194 = local_1e8._4_4_;
    uStack_190 = 0;
    uStack_18c = 0;
    local_188 = 0;
    local_1e8 = uVar2;
    cVar3 = RtlDeleteElementGenericTableAvl(this + 0x60,&local_198);
    if (cVar3 != '\0') {
      LOG_VERBOSE_UINT64(L"Removed from active flows, flow id",*(__uint64 *)(param_1 + 8));
      flow_context::release((flow_context *)param_1);
    }
  }
  KeReleaseInStackQueuedSpinLock(local_38);
  return;
}



===== auth_connect_classify_ @ 1400057e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::auth_connect_classify_(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) __ptr64 */

long __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::auth_connect_classify_
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,
          FWPS_CLASSIFY_OUT0_ *param_3)

{
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar1;
  int iVar2;
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  *this_00;
  undefined1 auStackY_208 [32];
  undefined1 local_1c8 [32];
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
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
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  pwVar1 = _current;
  local_28 = __security_cookie ^ (ulonglong)auStackY_208;
  *(undefined4 *)param_3 = 0x1002;
  if ((((*(short *)param_1 == 0x30) || (*(short *)param_1 == 0x32)) &&
      (*(uint *)(*(longlong *)(pwVar1 + 8) + 0x30) < 20000)) &&
     ((*(ulonglong *)(*(longlong *)(pwVar1 + 8) + 0x38) < 0xc800000 &&
      (pwVar1[0x58] ==
       (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
        )0x0)))) {
    this_00 = *(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                **)(pwVar1 + 0x40);
    running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
    ::lookup(this_00,(uint)local_1c8,SUB41(*(undefined4 *)(param_2 + 0x40),0));
    to_sockaddr((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 *)this_00,(FWPS_INCOMING_VALUES0_ *)&local_a8,(int)param_1,2,4,2);
    to_sockaddr((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 *)this_00,(FWPS_INCOMING_VALUES0_ *)&local_128,(int)param_1,6,7,6);
    local_1a8 = local_128;
    uStack_1a0 = uStack_120;
    local_198 = local_118;
    uStack_190 = uStack_110;
    local_188 = local_108;
    uStack_180 = uStack_100;
    local_178 = local_f8;
    uStack_170 = uStack_f0;
    local_168 = local_e8;
    uStack_160 = uStack_e0;
    local_158 = local_d8;
    uStack_150 = uStack_d0;
    local_128 = local_a8;
    uStack_120 = uStack_a0;
    local_118 = local_98;
    uStack_110 = uStack_90;
    local_108 = local_88;
    uStack_100 = uStack_80;
    local_f8 = local_78;
    uStack_f0 = uStack_70;
    local_e8 = local_68;
    uStack_e0 = uStack_60;
    local_d8 = local_58;
    uStack_d0 = uStack_50;
    local_c8 = local_48;
    uStack_c4 = uStack_44;
    uStack_c0 = uStack_40;
    uStack_bc = uStack_3c;
    local_b8 = local_38;
    uStack_b4 = uStack_34;
    uStack_b0 = uStack_30;
    uStack_ac = uStack_2c;
    iVar2 = stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
            ::queue_auth_connect
                      (*(stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                         **)(pwVar1 + 8),&local_128,&local_1a8,*(undefined4 *)(param_2 + 0x40));
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  return 0;
}



===== queue_auth_connect @ 1400059b0 =====

/* public: __cdecl stream_handler<class stream_handler<class implementation::stream_handler<class
   implementation::irp,class implementation::queue,class implementation::csqueue> >
   >::queue_auth_connect(struct sockaddr_storage,struct sockaddr_storage,unsigned int,unsigned
   __int64,bool,unsigned int) __ptr64 */

void __thiscall
stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
::queue_auth_connect
          (stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
           *this,undefined8 *param_2,<lambda_1da06d3c8846a479bc1e63eaf264472e> *param_3,
          undefined4 param_4,undefined8 param_5,undefined1 param_6,undefined4 param_7)

{
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined4 local_208;
  undefined8 local_204;
  undefined1 local_1fc;
  undefined4 local_1fb;
  undefined4 local_1f7;
  connection_notification local_1e8 [480];
  
  local_308 = *param_2;
  uStack_300 = param_2[1];
  local_2f8 = param_2[2];
  uStack_2f0 = param_2[3];
  local_2e8 = param_2[4];
  uStack_2e0 = param_2[5];
  local_2d8 = param_2[6];
  uStack_2d0 = param_2[7];
  local_2c8 = param_2[8];
  uStack_2c0 = param_2[9];
  local_2b8 = param_2[10];
  uStack_2b0 = param_2[0xb];
  local_2a8 = param_2[0xc];
  uStack_2a0 = param_2[0xd];
  local_298 = param_2[0xe];
  uStack_290 = param_2[0xf];
  local_288 = *(undefined8 *)param_3;
  uStack_280 = *(undefined8 *)(param_3 + 8);
  local_278 = *(undefined8 *)(param_3 + 0x10);
  uStack_270 = *(undefined8 *)(param_3 + 0x18);
  local_268 = *(undefined8 *)(param_3 + 0x20);
  uStack_260 = *(undefined8 *)(param_3 + 0x28);
  local_258 = *(undefined8 *)(param_3 + 0x30);
  uStack_250 = *(undefined8 *)(param_3 + 0x38);
  local_248 = *(undefined8 *)(param_3 + 0x40);
  uStack_240 = *(undefined8 *)(param_3 + 0x48);
  local_238 = *(undefined8 *)(param_3 + 0x50);
  uStack_230 = *(undefined8 *)(param_3 + 0x58);
  local_228 = *(undefined8 *)(param_3 + 0x60);
  uStack_220 = *(undefined8 *)(param_3 + 0x68);
  local_218 = *(undefined8 *)(param_3 + 0x70);
  uStack_210 = *(undefined8 *)(param_3 + 0x78);
  local_204 = param_5;
  local_1fc = param_6;
  local_1fb = 0;
  local_1f7 = param_7;
  local_208 = param_4;
  network_filtering::connection_notification::connection_notification
            (local_1e8,(auth_connect *)&local_308);
  implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
  ::enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_>
            ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *)
             (this + 0x10),local_1e8,param_3);
  return;
}



===== resource_assignment_classify_ @ 140005b24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::resource_assignment_classify_(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) __ptr64 */

long __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::resource_assignment_classify_
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,
          FWPS_CLASSIFY_OUT0_ *param_3)

{
  longlong lVar1;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar2;
  long lVar3;
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  *this_00;
  FWPS_INCOMING_VALUES0_ *pFVar4;
  <lambda_1da06d3c8846a479bc1e63eaf264472e> *p<Var5;
  undefined1 auStackY_2f8 [32];
  undefined1 local_2b8;
  undefined1 local_2b7;
  undefined8 local_2b0;
  port_open local_298 [8];
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined4 local_218;
  undefined8 local_214;
  undefined1 local_20c;
  undefined4 local_20b;
  uint local_207;
  connection_notification local_1f8 [320];
  short local_b8 [4];
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
  ulonglong local_38;
  
  pwVar2 = _current;
  local_38 = __security_cookie ^ (ulonglong)auStackY_2f8;
  *(undefined4 *)param_3 = 0x1002;
  if ((((*(short *)param_1 == 0x24) || (*(short *)param_1 == 0x26)) &&
      (**(char **)(pwVar2 + 0x20) != '\0')) &&
     (((*(uint *)(*(longlong *)(pwVar2 + 8) + 0x30) < 20000 &&
       (*(ulonglong *)(*(longlong *)(pwVar2 + 8) + 0x38) < 0xc800000)) &&
      (pwVar2[0x58] ==
       (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
        )0x0)))) {
    this_00 = *(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                **)(pwVar2 + 0x40);
    running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
    ::lookup(this_00,(uint)&local_2b8,SUB41(*(undefined4 *)(param_2 + 0x40),0));
    pFVar4 = param_1;
    to_sockaddr((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                 *)this_00,(FWPS_INCOMING_VALUES0_ *)local_b8,(int)param_1,2,4,2);
    if (local_b8[0] == 0) {
      return -0x3fffffff;
    }
    local_218 = *(undefined4 *)(param_2 + 0x40);
    p<Var5 = (<lambda_1da06d3c8846a479bc1e63eaf264472e> *)
             CONCAT71((int7)((ulonglong)pFVar4 >> 8),local_2b7);
    lVar1 = *(longlong *)(pwVar2 + 8);
    uStack_290 = uStack_b0;
    local_288 = local_a8;
    uStack_280 = uStack_a0;
    local_278 = local_98;
    uStack_270 = uStack_90;
    local_268 = local_88;
    uStack_260 = uStack_80;
    local_214 = local_2b0;
    local_258 = local_78;
    uStack_250 = uStack_70;
    local_248 = local_68;
    uStack_240 = uStack_60;
    local_207 = (uint)*(byte *)(*(longlong *)(param_1 + 8) + 0x58);
    local_20b = 0;
    local_238 = local_58;
    uStack_230 = uStack_50;
    local_228 = local_48;
    uStack_220 = uStack_40;
    local_20c = local_2b7;
    network_filtering::connection_notification::connection_notification(local_1f8,local_298);
    lVar3 = implementation::
            stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
            enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_>
                      ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                        *)(lVar1 + 0x10),local_1f8,p<Var5);
    if (lVar3 < 0) {
      return lVar3;
    }
  }
  return 0;
}



===== stream_classify_ @ 140005ccc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::stream_classify_(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,struct FWPS_FILTER2_ const *
   __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::stream_classify_(wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                   *this,FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,
                  void *param_3,FWPS_FILTER2_ *param_4,__uint64 param_5,FWPS_CLASSIFY_OUT0_ *param_6
                  )

{
  int *piVar1;
  ulonglong *puVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  uint *puVar6;
  ulonglong uVar7;
  stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
  *psVar8;
  undefined8 uVar9;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *this_00;
  __uint64 _Var10;
  FWPS_CLASSIFY_OUT0_ *pFVar11;
  ushort uVar12;
  longlong lVar13;
  int iVar14;
  undefined4 uVar15;
  byte bVar16;
  undefined8 *puVar17;
  wchar_t *pwVar18;
  byte bVar19;
  ulonglong uVar20;
  byte bVar21;
  byte bVar22;
  undefined1 uVar23;
  bool bVar24;
  undefined1 auStack_2b8 [40];
  undefined1 local_290;
  undefined4 local_288;
  undefined8 *local_280;
  undefined8 local_278;
  undefined8 uStack_270;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_268;
  undefined4 local_258;
  undefined4 uStack_254;
  uint uStack_250;
  undefined4 uStack_24c;
  __uint64 local_248;
  __uint64 local_238;
  ulonglong *puStack_230;
  longlong *local_228;
  char *pcStack_220;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_218;
  ushort *puStack_210;
  char *local_208;
  FWPS_INCOMING_METADATA_VALUES0_ **ppFStack_200;
  FWPS_FILTER2_ **local_1f8;
  FWPS_INCOMING_VALUES0_ **ppFStack_1f0;
  void **local_1e8;
  undefined4 *puStack_1e0;
  void **local_1d8;
  undefined2 *puStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  void *local_138;
  FWPS_INCOMING_METADATA_VALUES0_ *local_130;
  void *local_128;
  FWPS_INCOMING_VALUES0_ *local_120;
  char local_118;
  char local_117 [3];
  ushort local_114 [2];
  undefined2 local_110 [2];
  undefined4 local_10c;
  longlong local_108;
  undefined1 local_100 [24];
  ulonglong local_e8;
  
  pFVar11 = param_6;
  _Var10 = param_5;
  this_00 = _current;
  local_e8 = __security_cookie ^ (ulonglong)auStack_2b8;
  local_108 = 0;
  local_138 = (void *)0x0;
  local_128 = (void *)0x0;
  local_10c = 0;
  local_110[0] = 0;
  sVar4 = *(short *)param_1;
  local_130 = param_2;
  local_120 = param_1;
  if ((sVar4 == 0x14) || (sVar4 == 0x18)) {
    uVar23 = 1;
    if (sVar4 != 0x14) goto LAB_140005dbc;
LAB_140005e65:
    local_118 = '\x01';
    puVar6 = *(uint **)param_3;
    local_108 = *(longlong *)(puVar6 + 0xc);
    uVar5 = *puVar6;
    bVar22 = (byte)*puVar6 & 1;
    if (bVar22 == 0) {
      bVar16 = (byte)(uVar5 >> 0x13);
      bVar19 = (byte)(uVar5 >> 0x11);
      bVar21 = (byte)(uVar5 >> 0x12);
    }
    else {
      bVar16 = (byte)(uVar5 >> 2);
      bVar19 = (byte)(uVar5 >> 1);
      bVar21 = (byte)(uVar5 >> 4);
    }
    bVar22 = (((bVar16 & 1) * '\x02' ^ bVar19 & 1) * '\x02' ^ bVar21 & 1) * '\x02' ^ bVar22;
    local_114[0] = (ushort)bVar22;
    local_138 = param_3;
LAB_140005ec4:
    puVar2 = (ulonglong *)(_Var10 + (((ulonglong)(bVar22 & 1) ^ 1) + 0x28) * 8);
    *puVar2 = *puVar2 + local_108;
    if ((*(byte *)(_Var10 + 0x13) & 0x10) != 0) {
      if ((bVar22 & 1) == 0) {
        *(longlong *)(_Var10 + 0x158) = *(longlong *)(_Var10 + 0x158) + local_108;
      }
      else {
        *(longlong *)(_Var10 + 0x150) = *(longlong *)(_Var10 + 0x150) + local_108;
      }
    }
    if (((*(byte *)(_Var10 + 0x13) & 8) != 0) && (*(char *)(_Var10 + 0x1f8) == '\0')) {
      make_flow_async_if_necessary
                ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                  *)this_00,(flow_context *)_Var10);
      bVar22 = (byte)local_114[0];
    }
    if (((*(char *)(_Var10 + 0x10) != '\x02') || (((bVar22 & 1) != 0 && (local_118 == '\0')))) ||
       (local_117[0] = '\0', *(char *)(_Var10 + 0x1f8) != '\0')) {
      local_117[0] = '\x01';
    }
    if ((*(byte *)(_Var10 + 0x13) & 8) != 0) {
      local_114[0] = CONCAT11(local_114[0]._1_1_,local_117[0] << 4 | bVar22 & 0xef);
    }
    local_228 = &local_108;
    local_238 = _Var10;
    pcStack_220 = local_117;
    puStack_210 = local_114;
    local_208 = &local_118;
    ppFStack_200 = &local_130;
    local_1f8 = &param_4;
    ppFStack_1f0 = &local_120;
    local_1e8 = &local_138;
    puStack_1e0 = &local_10c;
    local_1d8 = &local_128;
    puStack_1d0 = local_110;
    local_218 = this_00;
    puStack_230 = puVar2;
    iVar14 = <lambda_fb45a7d5b4d02516ee1d4a1bc73328fe>::operator()
                       ((<lambda_fb45a7d5b4d02516ee1d4a1bc73328fe> *)&local_238);
    uVar7 = *(ulonglong *)(*(longlong *)(this_00 + 8) + 0x38);
    uVar20 = (ulonglong)*(int *)(*(longlong *)(this_00 + 8) + 0x30);
    if (*(char *)(_Var10 + 0x10) == '\x02') {
      if (*(char *)(_Var10 + 0x1f8) == '\0') {
        if (((iVar14 < 0) || (100000 < uVar20)) || (0x3e800000 < uVar7)) {
          if (uVar7 < 0x3e800001) {
            if (100000 < uVar20) {
              pwVar18 = L"Stream Handler Queue Length is unrecoverable!! Aborting flow!! Streams";
              goto code_r0x000140006056;
            }
          }
          else {
            pwVar18 = L"Stream Handler Queue Allocation is unrecoverable!! Aborting flow!! Bytes";
            uVar20 = uVar7;
code_r0x000140006056:
            LOG_ERROR_UINT64(pwVar18,uVar20);
          }
          FwpsFlowAbort0(*(undefined8 *)(local_130 + 0x20));
          if (*(char *)(_Var10 + 0x198) == '\0') {
            running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
            ::lookup(*(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                       **)(this_00 + 0x40),(uint)&local_258,SUB41(*(undefined4 *)(_Var10 + 0x118),0)
                    );
            uStack_270 = *(longlong *)(_Var10 + 400);
            psVar8 = *(stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                       **)(this_00 + 8);
            local_278 = CONCAT35(local_278._5_3_,0xc000000d);
            if (uStack_270 != 0) {
              LOCK();
              *(int *)(uStack_270 + 0x20) = *(int *)(uStack_270 + 0x20) + 1;
              UNLOCK();
            }
            local_280 = &local_278;
            local_238 = *(__uint64 *)(_Var10 + 0x98);
            puStack_230 = *(ulonglong **)(_Var10 + 0xa0);
            local_228 = *(longlong **)(_Var10 + 0xa8);
            pcStack_220 = *(char **)(_Var10 + 0xb0);
            local_218 = *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                          **)(_Var10 + 0xb8);
            puStack_210 = *(ushort **)(_Var10 + 0xc0);
            local_268 = this_00;
            local_288 = *(undefined4 *)(*(longlong *)(_Var10 + 400) + 0x18);
            local_208 = *(char **)(_Var10 + 200);
            ppFStack_200 = *(FWPS_INCOMING_METADATA_VALUES0_ ***)(_Var10 + 0xd0);
            local_1f8 = *(FWPS_FILTER2_ ***)(_Var10 + 0xd8);
            ppFStack_1f0 = *(FWPS_INCOMING_VALUES0_ ***)(_Var10 + 0xe0);
            local_290 = local_258._1_1_;
            local_1e8 = *(void ***)(_Var10 + 0xe8);
            puStack_1e0 = *(undefined4 **)(_Var10 + 0xf0);
            local_1d8 = *(void ***)(_Var10 + 0xf8);
            puStack_1d0 = *(undefined2 **)(_Var10 + 0x100);
            local_1c8 = *(undefined8 *)(_Var10 + 0x108);
            uStack_1c0 = *(undefined8 *)(_Var10 + 0x110);
            local_1b8 = *(undefined4 *)(_Var10 + 0x18);
            uStack_1b4 = *(undefined4 *)(_Var10 + 0x1c);
            uStack_1b0 = *(undefined4 *)(_Var10 + 0x20);
            uStack_1ac = *(undefined4 *)(_Var10 + 0x24);
            local_1a8 = *(undefined4 *)(_Var10 + 0x28);
            uStack_1a4 = *(undefined4 *)(_Var10 + 0x2c);
            uStack_1a0 = *(undefined4 *)(_Var10 + 0x30);
            uStack_19c = *(undefined4 *)(_Var10 + 0x34);
            local_198 = *(undefined4 *)(_Var10 + 0x38);
            uStack_194 = *(undefined4 *)(_Var10 + 0x3c);
            uStack_190 = *(undefined4 *)(_Var10 + 0x40);
            uStack_18c = *(undefined4 *)(_Var10 + 0x44);
            local_188 = *(undefined4 *)(_Var10 + 0x48);
            uStack_184 = *(undefined4 *)(_Var10 + 0x4c);
            uStack_180 = *(undefined4 *)(_Var10 + 0x50);
            uStack_17c = *(undefined4 *)(_Var10 + 0x54);
            local_178 = *(undefined8 *)(_Var10 + 0x58);
            uStack_170 = *(undefined8 *)(_Var10 + 0x60);
            local_168 = *(undefined8 *)(_Var10 + 0x68);
            uStack_160 = *(undefined8 *)(_Var10 + 0x70);
            local_158 = *(undefined8 *)(_Var10 + 0x78);
            uStack_150 = *(undefined8 *)(_Var10 + 0x80);
            local_148 = *(undefined8 *)(_Var10 + 0x88);
            uStack_140 = *(undefined8 *)(_Var10 + 0x90);
            iVar14 = stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                     ::queue_connection_aborted<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_>
                               (psVar8,&local_1b8,&local_238,*(undefined4 *)(_Var10 + 0x118));
            lVar13 = uStack_270;
            if (uStack_270 != 0) {
              LOCK();
              piVar1 = (int *)(uStack_270 + 0x20);
              iVar3 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar3 == 1) {
                if (*(longlong *)(uStack_270 + 0x10) != 0) {
                  ExFreePoolWithTag(*(longlong *)(uStack_270 + 0x10),0x666e6477);
                }
                ExFreePoolWithTag(lVar13,0x666e6477);
              }
            }
            if (iVar14 < 0) {
              LOG_ERROR_UINT64(L"Failed to queue connection_aborted message",(longlong)iVar14);
            }
            else {
              *(undefined1 *)(_Var10 + 0x198) = 1;
            }
          }
        }
      }
      else {
LAB_140006239:
        if (((iVar14 < 0) || (10000 < uVar20)) || (0x6400000 < uVar7)) goto LAB_140006259;
      }
    }
    else {
      if (((*(short *)(_Var10 + 0x11) == 0) || ((short *)(_Var10 + 0x11) == (short *)0x0)) ||
         (*puVar2 < (ulonglong)*(ushort *)(_Var10 + 0x11))) goto LAB_140006239;
LAB_140006259:
      KeAcquireInStackQueuedSpinLock(this_00 + 0x50,local_100);
      if (uVar7 < 0x6400001) {
        if (10000 < uVar20) {
          pwVar18 = L"Stream Handler Queue Length at Max, removing contexts! Streams";
          goto code_r0x00014000629b;
        }
      }
      else {
        pwVar18 = L"Stream Handler Queue Allocation at Max! removing contexts";
        uVar20 = uVar7;
code_r0x00014000629b:
        LOG_WARNING_UINT64(pwVar18,uVar20);
      }
      local_268 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                   *)_Var10;
      uVar9 = *(undefined8 *)(local_130 + 0x20);
      uStack_270._0_2_ = CONCAT11(local_118,uVar23);
      uVar12 = (ushort)uStack_270;
      uStack_270 = (ulonglong)(ushort)uStack_270;
      uVar7 = uStack_270;
      local_278._0_4_ = (undefined4)uVar9;
      local_278._4_4_ = (undefined4)((ulonglong)uVar9 >> 0x20);
      uStack_270._0_4_ = (uint)uVar12;
      local_248 = _Var10;
      local_258 = (undefined4)local_278;
      uStack_254 = local_278._4_4_;
      uStack_250 = (uint)uStack_270;
      uStack_24c = 0;
      local_278 = uVar9;
      uStack_270 = uVar7;
      remove_contexts<unique_lock<spin_lock>_>
                ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                  *)this_00,&local_258,0);
      KeReleaseInStackQueuedSpinLock(local_100);
    }
    if (local_138 != (void *)0x0) {
      *(undefined4 *)((longlong)local_138 + 0x20) = 0;
    }
    if (local_117[0] == '\0') {
      if (local_138 != (void *)0x0) {
        *(longlong *)((longlong)local_138 + 0x18) = local_108;
      }
      *(uint *)(pFVar11 + 0x18) = *(uint *)(pFVar11 + 0x18) & 0xfffffffe;
      uVar15 = 0x1001;
      *(uint *)(pFVar11 + 0x1c) = *(uint *)(pFVar11 + 0x1c) | 1;
      goto LAB_140006357;
    }
    if (local_138 != (void *)0x0) {
      *(undefined8 *)((longlong)local_138 + 0x18) = 0;
    }
  }
  else {
    uVar23 = 0;
LAB_140005dbc:
    if (sVar4 == 0x16) goto LAB_140005e65;
    local_118 = '\0';
    for (puVar17 = *(undefined8 **)((longlong)param_3 + 8); puVar17 != (undefined8 *)0x0;
        puVar17 = (undefined8 *)*puVar17) {
      local_108 = local_108 + (ulonglong)*(uint *)(puVar17 + 3);
    }
    bVar24 = *(int *)(*(longlong *)(param_1 + 8) + 0x98) == 1;
    local_114[0] = (ushort)bVar24;
    if (((!bVar24) && (local_110[0] = 8, (*(uint *)param_2 & 0x10000) != 0)) &&
       (*(longlong *)(param_2 + 0x80) != 0)) {
      local_10c = *(undefined4 *)(param_2 + 0x88);
    }
    local_128 = param_3;
    iVar14 = FwpsQueryPacketInjectionState0(*(undefined8 *)(_current + 0x178),param_3,0);
    if ((iVar14 - 1U & 0xfffffffd) != 0) {
      bVar22 = (byte)local_114[0];
      goto LAB_140005ec4;
    }
  }
  uVar15 = 0x1002;
LAB_140006357:
  *(undefined4 *)pFVar11 = uVar15;
  return;
}



===== operator() @ 1400063c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl <lambda_fb45a7d5b4d02516ee1d4a1bc73328fe>::operator()(void)const __ptr64 */

long __thiscall
<lambda_fb45a7d5b4d02516ee1d4a1bc73328fe>::operator()
          (<lambda_fb45a7d5b4d02516ee1d4a1bc73328fe> *this)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  byte *pbVar7;
  uint *puVar8;
  undefined8 uVar9;
  bool bVar10;
  ulonglong uVar11;
  long lVar12;
  int iVar13;
  longlong lVar14;
  longlong *plVar15;
  uint uVar16;
  queue<implementation::queue,net_buffer_list> *pqVar17;
  <lambda_1da06d3c8846a479bc1e63eaf264472e> *p<Var18;
  undefined1 auStack_2b8 [32];
  undefined1 in_stack_fffffffffffffd68;
  undefined8 local_288;
  longlong local_280;
  undefined8 local_278;
  undefined8 local_268;
  undefined8 uStack_260;
  ulonglong local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  ulonglong uStack_1e0;
  ulonglong local_1d8;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  uint uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined8 local_1b8;
  ulonglong uStack_1b0;
  longlong local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  ulonglong uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  ulonglong uStack_f0;
  ulonglong uStack_e8;
  undefined8 uStack_e0;
  undefined4 local_d8;
  uint local_d4;
  undefined8 local_d0;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  lVar14 = *(longlong *)this;
  if ((((*(byte *)(lVar14 + 0x13) & 0x10) != 0) &&
      (0x4000 < (ulonglong)(**(longlong **)(this + 8) - **(longlong **)(this + 0x10)))) &&
     (**(char **)(this + 0x18) != '\0')) {
    if ((*(ulonglong *)(lVar14 + 0x150) < 0x19000) && (*(ulonglong *)(lVar14 + 0x158) < 0x19000)) {
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    local_1b8 = 0;
    lVar14 = KeQueryInterruptTimePrecise(&local_1b8);
    if ((bVar10) || (100000000 < (ulonglong)(lVar14 - *(longlong *)(*(longlong *)this + 0x160)))) {
      *(longlong *)(*(longlong *)this + 0x160) = lVar14;
      lVar14 = *(longlong *)this;
      p<Var18 = *(<lambda_1da06d3c8846a479bc1e63eaf264472e> **)(lVar14 + 0x150);
      local_190 = *(undefined8 *)(lVar14 + 0x158);
      *(undefined8 *)(lVar14 + 0x150) = 0;
      *(undefined8 *)(*(longlong *)this + 0x158) = 0;
      lVar14 = *(longlong *)this;
      lVar6 = *(longlong *)(*(longlong *)(this + 0x20) + 8);
      local_1a8 = *(longlong *)(lVar14 + 0x140);
      local_1a0 = *(undefined8 *)(lVar14 + 0x148);
      local_188 = *(undefined8 *)(lVar14 + 8);
      local_198 = p<Var18;
      network_filtering::connection_notification::connection_notification
                ((connection_notification *)&local_178,(volume_update *)&local_1a8);
      lVar12 = implementation::
               stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
               enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_>
                         ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                           *)(lVar6 + 0x10),(connection_notification *)&local_178,p<Var18);
      return lVar12;
    }
    return 0;
  }
  if (**(char **)(this + 0x18) != '\0') goto LAB_14000675d;
  pbVar7 = *(byte **)(this + 0x28);
  pqVar17 = (queue<implementation::queue,net_buffer_list> *)
            (lVar14 + 0x1c8 + (-(ulonglong)((*pbVar7 & 1) != 0) & 0xffffffffffffffd8));
  puVar8 = (uint *)**(undefined8 **)(this + 0x38);
  if (**(char **)(this + 0x30) == '\0') {
    uStack_260 = *(undefined8 *)(lVar14 + 0x98);
    local_258 = *(ulonglong *)(lVar14 + 0xa0);
    uStack_250 = *(undefined8 *)(lVar14 + 0xa8);
    local_248 = *(undefined8 *)(lVar14 + 0xb0);
    uStack_240 = *(undefined8 *)(lVar14 + 0xb8);
    local_238 = *(undefined8 *)(lVar14 + 0xc0);
    uStack_230 = *(undefined8 *)(lVar14 + 200);
    local_228 = *(undefined8 *)(lVar14 + 0xd0);
    uStack_220 = *(undefined8 *)(lVar14 + 0xd8);
    local_218 = *(undefined8 *)(lVar14 + 0xe0);
    uStack_210 = *(undefined8 *)(lVar14 + 0xe8);
    local_208 = *(undefined8 *)(lVar14 + 0xf0);
    uStack_200 = *(undefined8 *)(lVar14 + 0xf8);
    local_1f8 = *(undefined8 *)(lVar14 + 0x100);
    uStack_1f0 = *(undefined8 *)(lVar14 + 0x108);
    uStack_f8 = *(undefined8 *)(lVar14 + 0x110);
    if ((*puVar8 & 0x800) == 0) {
      local_1e8 = (ulonglong)puVar8[0x1e];
    }
    else {
      local_1e8 = CONCAT44(puVar8[0x14],puVar8[0x1e]);
    }
    local_178 = 1;
    lVar14 = 0;
    uVar5 = **(uint **)(this + 0x58);
    uVar9 = *(undefined8 *)(puVar8 + 0x1c);
    uStack_1e0 = (ulonglong)uVar5;
    uStack_f0 = local_1e8;
    uStack_e8 = uStack_1e0;
    local_d0 = 0;
    uVar16 = 0;
    local_d8 = CONCAT22(*(undefined2 *)pbVar7,*(undefined2 *)**(undefined8 **)(this + 0x48));
    local_d4 = 0;
    plVar15 = *(longlong **)(**(longlong **)(this + 0x60) + 8);
    if (plVar15 != (longlong *)0x0) {
      do {
        uVar16 = uVar16 + (int)plVar15[3];
        lVar14 = lVar14 + 1;
        plVar15 = (longlong *)*plVar15;
      } while (plVar15 != (longlong *)0x0);
      local_d4 = uVar16;
      local_d0 = lVar14;
    }
    local_1b8 = 0;
    uStack_1b0 = 0;
    local_268 = 1;
    uStack_e0._0_4_ = (undefined4)uVar9;
    uStack_e0._4_4_ = (undefined4)((ulonglong)uVar9 >> 0x20);
    uStack_1e0 = local_1e8;
    local_1d8 = (ulonglong)uVar5;
    uStack_1d0 = (undefined4)uStack_e0;
    uStack_1cc = uStack_e0._4_4_;
    local_1c8 = local_d8;
    uStack_1c4 = local_d4;
    uStack_1c0 = (undefined4)local_d0;
    uStack_1bc = local_d0._4_4_;
    local_1e8 = uStack_f8;
    uStack_170 = uStack_260;
    uStack_168 = local_258;
    uStack_160 = uStack_250;
    uStack_158 = local_248;
    uStack_150 = uStack_240;
    local_148 = local_238;
    uStack_140 = uStack_230;
    local_138 = local_228;
    uStack_130 = uStack_220;
    local_128 = local_218;
    uStack_120 = uStack_210;
    local_118 = local_208;
    uStack_110 = uStack_200;
    local_108 = local_1f8;
    uStack_100 = uStack_1f0;
    uStack_e0 = uVar9;
    queue<implementation::queue,net_buffer_list>::create_element<reinjection_meta_data>
              (&local_1b8,(ulonglong)local_d4 + local_d0 * 8 + (ulonglong)uVar5,&local_268);
    if (uStack_1b0 == 0) {
      return -0x3fffffe9;
    }
    iVar13 = net_buffer_list::clone_udp_nbl
                       ((net_buffer_list *)(uStack_1b0 + 0x10),
                        (_NET_BUFFER_LIST *)**(undefined8 **)(this + 0x60),
                        *(cmsghdr **)(**(longlong **)(this + 0x38) + 0x80),
                        *(void **)(*(longlong *)(this + 0x20) + 0x170),
                        (bool)in_stack_fffffffffffffd68);
    if (iVar13 < 0) goto LAB_1400067d2;
    goto LAB_14000670a;
  }
  uStack_260 = *(undefined8 *)(puVar8 + 8);
  local_178 = 0;
  local_d0 = 1;
  uStack_1b0 = (ulonglong)*(uint *)(**(longlong **)(this + 0x40) + 0x2c);
  local_258 = uStack_1b0;
  uStack_168 = uStack_1b0;
  local_d8 = CONCAT22(*(undefined2 *)pbVar7,*(undefined2 *)**(undefined8 **)(this + 0x48));
  uStack_1c4 = **(uint **)(this + 0x10);
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_268 = 0;
  uStack_250 = uStack_160;
  local_248 = uStack_158;
  uStack_240 = uStack_150;
  local_238 = local_148;
  uStack_230 = uStack_140;
  local_228 = local_138;
  uStack_220 = uStack_130;
  local_218 = local_128;
  uStack_210 = uStack_120;
  local_208 = local_118;
  uStack_200 = uStack_110;
  local_1f8 = local_108;
  uStack_1f0 = uStack_100;
  local_1e8 = uStack_f8;
  uStack_1e0 = uStack_f0;
  local_1d8 = uStack_e8;
  uStack_1d0 = (undefined4)uStack_e0;
  uStack_1cc = uStack_e0._4_4_;
  local_1c8 = local_d8;
  uStack_1c0 = 1;
  uStack_1bc = 0;
  uStack_170 = uStack_260;
  local_d4 = uStack_1c4;
  queue<implementation::queue,net_buffer_list>::create_element<reinjection_meta_data>
            (&local_1b8,(ulonglong)uStack_1c4 + 8,&local_268);
  local_1b8._0_5_ = CONCAT14(1,(int)local_1b8);
  if ((int)local_1b8 < 0) {
LAB_1400067d2:
    if ((uStack_1b0 != 0) &&
       (net_buffer_list::~net_buffer_list((net_buffer_list *)(uStack_1b0 + 0x10)), uStack_1b0 != 0))
    {
      ExFreePoolWithTag(uStack_1b0,0x666e6477);
    }
    return -0x3fffffe9;
  }
  local_288 = *(undefined8 *)(this + 0x50);
  local_280 = *(longlong *)(this + 0x10);
  iVar13 = net_buffer_list::clone_tcp_data<<lambda_4e6f6bad4917d83e51eafa8c8b801f57>_>
                     ((net_buffer_list *)(uStack_1b0 + 0x10),
                      (<lambda_4e6f6bad4917d83e51eafa8c8b801f57> *)&local_288,
                      *(void **)(*(longlong *)(this + 0x20) + 0x170));
  if (iVar13 < 0) goto LAB_1400067d2;
  if (*(char *)(*(longlong *)(this + 0x20) + 0x181) == '\0') {
LAB_14000670a:
    local_280 = uStack_1b0;
    uVar11 = (ulonglong)local_288 >> 0x20;
    local_288 = CONCAT44((uint)uVar11 & 0xffffff00,0xc000000d);
    uStack_1b0 = 0;
    queue<implementation::queue,net_buffer_list>::push_back(pqVar17,&local_288);
  }
  else {
    lVar14 = *(longlong *)this;
    if (*(void **)(lVar14 + 0x200) == SystemReserved1[0xf]) {
      pbVar7 = *(byte **)(this + 0x28);
      if (*(char *)(lVar14 + 0x1f8) == '\0') goto LAB_14000670a;
      **(undefined1 **)(this + 0x18) = 1;
      *pbVar7 = *pbVar7 | 0x10;
    }
    else {
      KeAcquireInStackQueuedSpinLock(lVar14 + 0x1f0,&local_1a8);
      pbVar7 = *(byte **)(this + 0x28);
      if (*(char *)(*(longlong *)this + 0x1f8) == '\0') {
        local_280 = uStack_1b0;
        local_288 = CONCAT35(local_288._5_3_,0xc000000d);
        uStack_1b0 = 0;
        queue<implementation::queue,net_buffer_list>::push_back(pqVar17,&local_288);
      }
      else {
        **(undefined1 **)(this + 0x18) = 1;
        *pbVar7 = *pbVar7 | 0x10;
      }
      KeReleaseInStackQueuedSpinLock(&local_1a8);
    }
  }
  if ((uStack_1b0 != 0) &&
     (net_buffer_list::~net_buffer_list((net_buffer_list *)(uStack_1b0 + 0x10)), uStack_1b0 != 0)) {
    ExFreePoolWithTag(uStack_1b0,0x666e6477);
  }
LAB_14000675d:
  local_288 = *(undefined8 *)(this + 0x50);
  local_280 = *(longlong *)(this + 0x20);
  lVar14 = *(longlong *)this;
  local_278 = *(undefined8 *)(this + 0x60);
  uVar9 = **(undefined8 **)(this + 0x10);
  uVar1 = **(undefined2 **)(this + 0x68);
  uVar2 = **(ushort **)(this + 0x28);
  uVar4 = *(undefined4 *)(**(longlong **)(this + 0x40) + 0x2c);
  uVar3 = *(undefined2 *)**(undefined8 **)(this + 0x48);
  local_1a0 = *(undefined8 *)(**(longlong **)(this + 0x38) + 0x20);
  if ((uVar2 & 1) == 0) {
    local_1a8 = *(longlong *)(lVar14 + 0x170);
    *(longlong *)(lVar14 + 0x170) = local_1a8 + 1;
  }
  else {
    local_1a8 = *(longlong *)(lVar14 + 0x168);
    *(longlong *)(lVar14 + 0x168) = local_1a8 + 1;
  }
  lVar14 = *(longlong *)(local_280 + 8);
  local_198 = (<lambda_1da06d3c8846a479bc1e63eaf264472e> *)CONCAT26(uVar2,CONCAT42(uVar4,uVar3));
  local_190._0_6_ = CONCAT42((int)uVar9,uVar1);
  network_filtering::connection_notification::connection_notification
            ((connection_notification *)&local_178,(stream_segment *)&local_1a8);
  lVar12 = implementation::
           stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
           enqueue<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_>
                     ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
                       *)(lVar14 + 0x10),(connection_notification *)&local_178,
                      (<lambda_c0181479a74cc14d1ba9a1f0223edc1b> *)&local_288);
  return lVar12;
}



===== clone_tcp_data<<lambda_4e6f6bad4917d83e51eafa8c8b801f57>_> @ 140006aa4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: auto __cdecl net_buffer_list::clone_tcp_data<class
   <lambda_4e6f6bad4917d83e51eafa8c8b801f57> >(class <lambda_4e6f6bad4917d83e51eafa8c8b801f57> const
   & __ptr64,void * __ptr64) __ptr64 */

undefined8 __thiscall
net_buffer_list::clone_tcp_data<<lambda_4e6f6bad4917d83e51eafa8c8b801f57>_>
          (net_buffer_list *this,<lambda_4e6f6bad4917d83e51eafa8c8b801f57> *param_1,void *param_2)

{
  uint uVar1;
  net_buffer_list *pnVar2;
  longlong lVar3;
  undefined1 auStack_78 [32];
  ulonglong local_58;
  ulonglong local_50;
  net_buffer_list *local_48;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  pnVar2 = (net_buffer_list *)0x0;
  if (*(longlong *)(this + 8) == 0) {
    pnVar2 = this + 0x10;
  }
  if (pnVar2 != (net_buffer_list *)0x0) {
    uVar1 = *(uint *)(this + 0xac);
    if (uVar1 == 0) {
      return 0;
    }
    local_58 = 0;
    lVar3 = IoAllocateMdl(this + 0xc0,uVar1,0,0);
    *(longlong *)(this + (ulonglong)uVar1 + 0xc0) = lVar3;
    if (lVar3 != 0) {
      MmBuildMdlForNonPagedPool(lVar3);
      local_50 = (ulonglong)*(uint *)(this + 0xac);
      local_58 = local_58 & 0xffffffff00000000;
      local_48 = this;
      FwpsAllocateNetBufferAndNetBufferList0
                (param_2,0,0,*(undefined8 *)(this + (ulonglong)uVar1 + 0xc0));
      if (*(longlong *)this != 0) {
        local_38 = 0;
        FwpsCopyStreamDataToBuffer0
                  (*(undefined8 *)**(undefined8 **)param_1,this + 0xc0,
                   **(undefined4 **)(param_1 + 8),&local_38);
        return 0;
      }
    }
  }
  return 0xc0000017;
}



===== operator() @ 140006bbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl <lambda_c0181479a74cc14d1ba9a1f0223edc1b>::operator()(void * __ptr64)const
   __ptr64 */

undefined8 __thiscall
<lambda_c0181479a74cc14d1ba9a1f0223edc1b>::operator()
          (<lambda_c0181479a74cc14d1ba9a1f0223edc1b> *this,void *param_1)

{
  uint uVar1;
  longlong lVar2;
  void *_Src;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  uVar3 = 0;
  if ((longlong *)**(longlong **)this == (longlong *)0x0) {
    for (puVar4 = *(undefined8 **)(**(longlong **)(this + 0x10) + 8); puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)*puVar4) {
      uVar1 = *(uint *)(puVar4 + 3);
      if (uVar1 != 0) {
        local_38 = 0;
        _Src = (void *)NdisGetDataBuffer(puVar4,(ulonglong)uVar1,param_1,1);
        if (_Src != param_1) {
          if (_Src == (void *)0x0) {
            uVar3 = 0xc0000017;
            break;
          }
          memmove(param_1,_Src,(ulonglong)uVar1);
        }
      }
      param_1 = (void *)((longlong)param_1 + (ulonglong)uVar1);
    }
  }
  else {
    lVar2 = *(longlong *)**(longlong **)this;
    local_28 = 0;
    FwpsCopyStreamDataToBuffer0(lVar2,param_1,*(undefined8 *)(lVar2 + 0x30),&local_28);
    uVar3 = 0;
  }
  return uVar3;
}



===== queue_connection_aborted<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_> @ 140006c84 =====

/* public: auto __cdecl stream_handler<class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> > >::queue_connection_aborted<class
   <lambda_85692b8abb5e0bd6bf541223f0c9278b> >(struct sockaddr_storage,struct
   sockaddr_storage,unsigned int,unsigned __int64,bool,unsigned int,class
   <lambda_85692b8abb5e0bd6bf541223f0c9278b> const & __ptr64) __ptr64 */

void __thiscall
stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
::queue_connection_aborted<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_>
          (stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
           *this,undefined8 *param_2,undefined8 *param_3,undefined4 param_4,undefined8 param_5,
          undefined1 param_6,undefined4 param_7,<lambda_85692b8abb5e0bd6bf541223f0c9278b> *param_8)

{
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined4 local_208;
  undefined8 local_204;
  undefined1 local_1fc;
  undefined4 local_1fb;
  undefined4 local_1f7;
  connection_notification local_1e8 [480];
  
  local_308 = *param_2;
  uStack_300 = param_2[1];
  local_2f8 = param_2[2];
  uStack_2f0 = param_2[3];
  local_2e8 = param_2[4];
  uStack_2e0 = param_2[5];
  local_2d8 = param_2[6];
  uStack_2d0 = param_2[7];
  local_2c8 = param_2[8];
  uStack_2c0 = param_2[9];
  local_2b8 = param_2[10];
  uStack_2b0 = param_2[0xb];
  local_2a8 = param_2[0xc];
  uStack_2a0 = param_2[0xd];
  local_298 = param_2[0xe];
  uStack_290 = param_2[0xf];
  local_288 = *param_3;
  uStack_280 = param_3[1];
  local_278 = param_3[2];
  uStack_270 = param_3[3];
  local_268 = param_3[4];
  uStack_260 = param_3[5];
  local_258 = param_3[6];
  uStack_250 = param_3[7];
  local_248 = param_3[8];
  uStack_240 = param_3[9];
  local_238 = param_3[10];
  uStack_230 = param_3[0xb];
  local_228 = param_3[0xc];
  uStack_220 = param_3[0xd];
  local_218 = param_3[0xe];
  uStack_210 = param_3[0xf];
  local_204 = param_5;
  local_1fc = param_6;
  local_1fb = 0;
  local_1f7 = param_7;
  local_208 = param_4;
  network_filtering::connection_notification::connection_notification
            (local_1e8,(connection_aborted *)&local_308);
  implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
  ::enqueue<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_>
            ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *)
             (this + 0x10),local_1e8,param_8);
  return;
}



===== flow_established_classify @ 140006e00 =====

/* private: static void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_established_classify(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64,void * __ptr64,void const * __ptr64,struct
   FWPS_FILTER2_ const * __ptr64,unsigned __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64) */

void __cdecl
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::flow_established_classify
          (FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2,void *param_3,
          void *param_4,FWPS_FILTER2_ *param_5,__uint64 param_6,FWPS_CLASSIFY_OUT0_ *param_7)

{
  if (_current !=
      (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
       *)0x0) {
    flow_established_classify_
              ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                *)_current,param_1,param_2);
  }
  return;
}



===== reinject_pending_traffic @ 140006e24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::reinject_pending_traffic(struct wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_context * __ptr64) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::reinject_pending_traffic
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,flow_context *param_1)

{
  flow_context *pfVar1;
  void *pvVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  queue<implementation::queue,net_buffer_list> *this_00;
  ulonglong uVar6;
  undefined8 in_R8;
  wchar_t *in_R9;
  ulonglong uVar7;
  undefined1 auStack_c8 [32];
  longlong local_88;
  longlong local_78;
  undefined1 local_68 [24];
  undefined1 local_50 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  bVar4 = false;
  bVar3 = false;
  if (((*(void **)(param_1 + 0x200) != SystemReserved1[0xf]) &&
      (param_1[0x20a] != (flow_context)0x0)) && (param_1[0x10] == (flow_context)0x2)) {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x1f0,local_50);
    *(void **)(param_1 + 0x200) = SystemReserved1[0xf];
    if (param_1[0x1f8] == (flow_context)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        in_R9 = L"Go async on flow";
        WPP_SF_SI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,in_R8,L"Go async on flow",
                  (char)*(undefined8 *)(param_1 + 8));
      }
      while ((*(int *)(param_1 + 0x1b8) != 0 || (*(int *)(param_1 + 0x1e0) != 0))) {
        if (*(int *)(param_1 + 0x1e0) == 0) {
LAB_140006fb8:
          bVar3 = true;
          this_00 = (queue<implementation::queue,net_buffer_list> *)(param_1 + 0x1a0);
        }
        else {
          if (*(int *)(param_1 + 0x1b8) != 0) {
            KeAcquireInStackQueuedSpinLock(param_1 + 0x1a0,local_68);
            pfVar1 = *(flow_context **)(param_1 + 0x1a8);
            if (pfVar1 == param_1 + 0x1a8) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(ulonglong *)(pfVar1 + 200);
            }
            KeReleaseInStackQueuedSpinLock(local_68);
            KeAcquireInStackQueuedSpinLock(param_1 + 0x1c8,local_68);
            pfVar1 = *(flow_context **)(param_1 + 0x1d0);
            if (pfVar1 == param_1 + 0x1d0) {
              uVar6 = 0;
            }
            else {
              uVar6 = *(ulonglong *)(pfVar1 + 200);
            }
            KeReleaseInStackQueuedSpinLock(local_68);
            if (uVar7 < uVar6) goto LAB_140006fb8;
          }
          bVar4 = true;
          this_00 = (queue<implementation::queue,net_buffer_list> *)(param_1 + 0x1c8);
        }
        lVar5 = queue<implementation::queue,net_buffer_list>::pop_front(this_00);
        pvVar2 = *(void **)(lVar5 + 8);
        *(undefined8 *)(lVar5 + 8) = 0;
        if (bVar3) {
          bVar3 = false;
          if (local_88 != 0) {
            net_buffer_list::~net_buffer_list((net_buffer_list *)(local_88 + 0x10));
            if (local_88 != 0) {
              ExFreePoolWithTag(local_88,0x666e6477);
            }
          }
        }
        if (bVar4) {
          bVar4 = false;
          if (local_78 != 0) {
            net_buffer_list::~net_buffer_list((net_buffer_list *)(local_78 + 0x10));
            if (local_78 != 0) {
              ExFreePoolWithTag(local_78,0x666e6477);
            }
          }
        }
        implementation::wfp_callout::inject_stream_segment
                  ((wfp_callout *)(this + 0x158),(net_buffer_list *)((longlong)pvVar2 + 0x10),pvVar2
                   ,(_func_void_void_ptr__NET_BUFFER_LIST_ptr_uchar *)in_R9);
      }
      param_1[0x1f8] = (flow_context)0x1;
    }
    *(undefined8 *)(param_1 + 0x200) = 0;
    KeReleaseInStackQueuedSpinLock(local_50);
  }
  return;
}



===== process_notification_callback @ 1400070a0 =====

/* private: static void __cdecl running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list>
   >::process_notification_callback(void * __ptr64,void * __ptr64,void * __ptr64) */

void __cdecl
running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
::process_notification_callback(void *param_1,void *param_2,void *param_3)

{
  process_state pVar1;
  __uint64 local_res10 [3];
  
  local_res10[0] = 0;
  MpGetProcessCreationTimeById(*(longlong *)param_2,local_res10);
  pVar1 = 2;
  if (*(int *)((longlong)param_2 + 0x18) != 2) {
    pVar1 = (process_state)(*(char *)((longlong)param_2 + 0x1c) != '\0');
  }
  process_state_changed
            (param_1,*(uint *)param_2,local_res10[0],*(_UNICODE_STRING **)((longlong)param_2 + 0x10)
             ,pVar1,*(char *)((longlong)param_2 + 0x1d) != '\0');
  return;
}



===== path_list<implementation::path_list> @ 140007108 =====

/* public: __cdecl path_list<class implementation::path_list>::path_list<class
   implementation::path_list>(bool,wchar_t const * __ptr64,unsigned __int64) __ptr64 */

path_list<implementation::path_list> * __thiscall
path_list<implementation::path_list>::path_list<implementation::path_list>
          (path_list<implementation::path_list> *this,bool param_1,wchar_t *param_2,__uint64 param_3
          )

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  int iVar3;
  undefined2 uVar4;
  size_t sVar5;
  void *_Dst;
  ulonglong *_Dst_00;
  ulonglong *puVar6;
  undefined4 uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar7 = 0;
  *(undefined4 *)this = 0xc000000d;
  this[4] = (path_list<implementation::path_list>)0x0;
  this[9] = (path_list<implementation::path_list>)param_1;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  if (param_3 == 0) goto LAB_14000729f;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_3;
  sVar5 = SUB168(ZEXT816(2) * auVar1,0);
  if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
    sVar5 = 0xffffffffffffffff;
  }
  _Dst = (void *)ExAllocatePoolWithTag(0x600,sVar5,0x666e6477);
  if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
    memset(_Dst,0,sVar5);
    *(void **)(this + 0x10) = _Dst;
LAB_14000719e:
    iVar8 = 1;
    uVar10 = 0;
    if (param_3 != 0) {
      uVar9 = 0;
      do {
        uVar4 = RtlDowncaseUnicodeChar(param_2[uVar9]);
        *(undefined2 *)(*(longlong *)(this + 0x10) + uVar9 * 2) = uVar4;
        iVar3 = iVar8 + 1;
        if (*(short *)(*(longlong *)(this + 0x10) + uVar9 * 2) != 0x3b) {
          iVar3 = iVar8;
        }
        iVar8 = iVar3;
        uVar10 = uVar10 + 1;
        uVar9 = (ulonglong)uVar10;
      } while (uVar9 < param_3);
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = (longlong)iVar8;
    sVar5 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      sVar5 = 0xffffffffffffffff;
    }
    _Dst_00 = (ulonglong *)ExAllocatePoolWithTag(0x600,sVar5,0x666e6477);
    if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst_00 != (ulonglong *)0x0)) {
      memset(_Dst_00,0,sVar5);
      *(ulonglong **)(this + 0x18) = _Dst_00;
    }
    else {
      *(ulonglong **)(this + 0x18) = _Dst_00;
      if (_Dst_00 == (ulonglong *)0x0) goto LAB_14000724e;
    }
    puVar6 = _Dst_00 + iVar8;
    uVar9 = 0;
    *(ulonglong **)(this + 0x20) = puVar6;
    if (param_3 != 0) {
      do {
        if (_Dst_00 == puVar6) goto LAB_14000729f;
        if (*(short *)(*(longlong *)(this + 0x10) + uVar9 * 2) == 0x3b) {
          *_Dst_00 = uVar9;
          _Dst_00 = _Dst_00 + 1;
          puVar6 = *(ulonglong **)(this + 0x20);
        }
        uVar9 = (ulonglong)((int)uVar9 + 1);
      } while (uVar9 < param_3);
    }
    if (_Dst_00 != puVar6) {
      *_Dst_00 = param_3;
    }
  }
  else {
    *(void **)(this + 0x10) = _Dst;
    if (_Dst != (void *)0x0) goto LAB_14000719e;
LAB_14000724e:
    uVar7 = 0xc0000017;
  }
LAB_14000729f:
  *(undefined4 *)this = uVar7;
  return this;
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 1400072c0 =====

/* private: static auto __cdecl
   <lambda_85fdb50fb359fd473c1c9c369bb5230d>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64,void * __ptr64) */

int __cdecl
<lambda_85fdb50fb359fd473c1c9c369bb5230d>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  if (*(ulonglong *)param_2 < *(ulonglong *)param_3) {
    return 0;
  }
  return 2 - (uint)(*(ulonglong *)param_3 < *(ulonglong *)param_2);
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 1400072e0 =====

/* private: static auto __cdecl
   <lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64) */

void __cdecl
<lambda_d4a1ac2e305b976de6c1fcbd04b895aa>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    ExFreePoolWithTag(param_2,0x666e6477);
  }
  return;
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 140007310 =====

/* private: static auto __cdecl
   <lambda_47c094fdbd6b34749e4ef95a8029e4a8>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64,void * __ptr64) */

char __cdecl
<lambda_47c094fdbd6b34749e4ef95a8029e4a8>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  int iVar1;
  char cVar2;
  
  iVar1 = memcmp(param_2,param_3,0x10);
  cVar2 = '\0';
  if (-1 < iVar1) {
    iVar1 = memcmp(param_3,param_2,0x10);
    cVar2 = (-1 < iVar1) + '\x01';
  }
  return cVar2;
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 140007370 =====

/* private: static auto __cdecl
   <lambda_3b984229c8035a49320dff25fe1ee415>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64,void * __ptr64) */

char __cdecl
<lambda_3b984229c8035a49320dff25fe1ee415>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  int iVar1;
  char cVar2;
  
  iVar1 = memcmp(param_2,param_3,4);
  cVar2 = '\0';
  if (-1 < iVar1) {
    iVar1 = memcmp(param_3,param_2,4);
    cVar2 = (-1 < iVar1) + '\x01';
  }
  return cVar2;
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 1400073d0 =====

/* private: static auto __cdecl
   <lambda_33aa60316530382419a9baeda44eab07>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,void * __ptr64,void * __ptr64) */

int __cdecl
<lambda_33aa60316530382419a9baeda44eab07>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  if (*(uint *)param_2 < *(uint *)param_3) {
    return 0;
  }
  return 2 - (uint)(*(uint *)param_3 < *(uint *)param_2);
}



===== push_back @ 1400073e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl queue<class implementation::queue,class net_buffer_list>::push_back(class
   queue_element<class net_buffer_list,class implementation::queue<class
   net_buffer_list>::element_impl>) __ptr64 */

void __thiscall
queue<implementation::queue,net_buffer_list>::push_back
          (queue<implementation::queue,net_buffer_list> *this,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  uint *puVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  KeAcquireInStackQueuedSpinLock(this,local_28);
  puVar6 = auStack_48;
  puVar7 = *(undefined8 **)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  LOCK();
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  UNLOCK();
  lVar5 = (ulonglong)*(uint *)((longlong)puVar7 + 0xbc) + puVar7[0x18] * 8;
  puVar3 = (undefined8 *)0x0;
  if (puVar7[3] == 1) {
    puVar3 = puVar7 + 4;
  }
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = (uint *)&DAT_00000088;
    if (puVar7[3] == 1) {
      puVar4 = (uint *)(puVar7 + 0x15);
    }
    lVar5 = lVar5 + (ulonglong)*puVar4;
  }
  *(longlong *)(this + 0x20) = *(longlong *)(this + 0x20) + 0x10 + lVar5;
  plVar2 = *(longlong **)(this + 0x10);
  if ((queue<implementation::queue,net_buffer_list> *)*plVar2 != this + 8) {
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)(3);
    puVar6 = auStack_40;
  }
  *puVar7 = this + 8;
  puVar7[1] = plVar2;
  *plVar2 = (longlong)puVar7;
  *(undefined8 **)(this + 0x10) = puVar7;
  *(undefined8 *)(puVar6 + -8) = 0x1400074a3;
  KeReleaseInStackQueuedSpinLock(puVar6 + 0x20);
  lVar5 = *(longlong *)(param_2 + 8);
  if (lVar5 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x1400074ba;
    net_buffer_list::~net_buffer_list((net_buffer_list *)(lVar5 + 0x10));
    lVar5 = *(longlong *)(param_2 + 8);
    if (lVar5 != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1400074cf;
      ExFreePoolWithTag(lVar5,0x666e6477);
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x1400074e1;
  return;
}



===== flow_established_classify_ @ 1400074f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* private: long __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_established_classify_(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct
   FWPS_INCOMING_METADATA_VALUES0_ const * __ptr64) __ptr64 */

long __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::flow_established_classify_
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,FWPS_INCOMING_VALUES0_ *param_1,FWPS_INCOMING_METADATA_VALUES0_ *param_2)

{
  flow_context *pfVar1;
  int *piVar2;
  char cVar3;
  short sVar4;
  uint *puVar5;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar6;
  undefined1 auVar7 [8];
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [8];
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  int iVar24;
  longlong lVar25;
  longlong lVar26;
  flow_context *this_00;
  shared_ptr_impl *this_01;
  int *piVar27;
  undefined8 *puVar28;
  ulonglong uVar29;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwVar30;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  **_Buf1;
  longlong lVar31;
  wchar_t *pwVar32;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  **ppwVar33;
  longlong lVar34;
  byte bVar35;
  undefined1 uVar36;
  size_t _Size;
  longlong lVar37;
  ulonglong uVar38;
  undefined2 uVar39;
  undefined2 uVar40;
  undefined1 uVar41;
  undefined2 uVar42;
  int *piVar43;
  uint uVar44;
  undefined1 auStackY_348 [32];
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_2b8;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  char local_2a8 [16];
  char local_298;
  FWPS_INCOMING_METADATA_VALUES0_ *local_290;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_288;
  char cStack_280;
  flow_context fStack_27f;
  undefined2 uStack_27e;
  undefined2 uStack_27c;
  undefined2 uStack_27a;
  flow_context *local_278;
  flow_context *local_270;
  undefined4 local_267;
  undefined2 local_263;
  undefined1 local_261;
  flow_context local_260 [8];
  int local_258 [2];
  flow_context local_250 [8];
  char local_248 [8];
  uint local_240 [2];
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_238;
  undefined8 uStack_230;
  flow_context *local_228;
  flow_context *local_220;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_218;
  char *local_210;
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *local_208 [2];
  undefined1 local_1f8 [8];
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined1 local_178 [8];
  wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
  *pwStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 local_f8 [24];
  ulonglong local_e0;
  
  pwVar6 = _current;
  local_e0 = __security_cookie ^ (ulonglong)auStackY_348;
  piVar43 = (int *)0x0;
  local_240[0] = *(uint *)param_2 & 8;
  if ((*(short *)param_1 != 0x34) && (*(short *)param_1 != 0x36)) {
    return 0;
  }
  local_290 = param_2;
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  ::lookup(*(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
             **)(_current + 0x40),(uint)local_2a8,SUB41(*(undefined4 *)(param_2 + 0x40),0));
  if (local_298 != '\0') {
    return 0;
  }
  uVar38 = *(ulonglong *)(*(longlong *)(pwVar6 + 8) + 0x38);
  uVar29 = (ulonglong)*(int *)(*(longlong *)(pwVar6 + 8) + 0x30);
  if (uVar29 < 20000) {
    if (uVar38 < 0xc800000) {
      pwVar30 = pwVar6 + 0x50;
      KeAcquireInStackQueuedSpinLock(pwVar30,local_f8);
      if ((pwVar6[0x58] ==
           (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
            )0x0) && (lVar26 = *(longlong *)(param_1 + 8), (*(uint *)(lVar26 + 0xf8) & 4) == 0)) {
        to_sockaddr((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                     *)pwVar30,(FWPS_INCOMING_VALUES0_ *)local_178,(int)param_1,2,4,2);
        to_sockaddr((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                     *)pwVar30,(FWPS_INCOMING_VALUES0_ *)local_1f8,(int)param_1,6,7,6);
        cVar3 = *(char *)(lVar26 + 0x58);
        _Size = 0x10;
        local_260[0] = (flow_context)(cVar3 == '\x06');
        lVar25 = 0x10;
        if (cVar3 != '\x06') {
          lVar25 = 0x18;
        }
        uVar44 = **(uint **)(pwVar6 + lVar25);
        bVar35 = (byte)(uVar44 >> 0x18);
        if (*(int *)(lVar26 + 200) == 1) {
          bVar35 = bVar35 >> 1;
        }
        else {
          bVar35 = bVar35 >> 2;
        }
        if (local_178._0_2_ == 2) {
          _Size = 4;
          ppwVar33 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                      **)(local_1f8 + 4);
          _Buf1 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                   **)(local_178 + 4);
        }
        else {
          ppwVar33 = &pwStack_1f0;
          _Buf1 = &pwStack_170;
        }
        iVar24 = memcmp(_Buf1,ppwVar33,_Size);
        if (((uVar44 >> 0x18 & 1) != 0) || (iVar24 != 0)) {
          lVar26 = *(longlong *)(pwVar6 + 0x48);
          KeAcquireInStackQueuedSpinLock(lVar26 + 8,&local_238);
          if (local_1f8._0_2_ == 2) {
            lVar26 = lVar26 + 0x10;
            local_258[0] = local_1f8._4_4_;
            ppwVar33 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                        **)local_258;
          }
          else {
            lVar26 = lVar26 + 0x78;
            ppwVar33 = &local_2b8;
            local_2b8 = pwStack_1f0;
            uStack_2b0 = (undefined4)local_1e8;
            uStack_2ac = local_1e8._4_4_;
          }
          lVar26 = RtlLookupElementGenericTableAvl(lVar26,ppwVar33);
          KeReleaseInStackQueuedSpinLock(&local_238);
          if (((lVar26 == 0) && ((bVar35 & 1) != 0)) && ((char)uVar44 != '\0')) {
            if (local_2a8[0] != '\0') {
              local_258[0] = 1;
              uVar44 = 1;
            }
            this_00 = (flow_context *)ExAllocatePoolWithTag(0x600,0x210,0x666e6477);
            if (this_00 == (flow_context *)0x0) {
              iVar24 = -0x3fffffe9;
            }
            else {
              if ((char)ExPoolZeroingNativelySupported == '\0') {
                memset(this_00,0,0x210);
              }
              uVar23 = uStack_110;
              uVar22 = local_118;
              uVar21 = uStack_120;
              uVar20 = local_128;
              uVar19 = uStack_130;
              uVar18 = local_138;
              uVar17 = uStack_140;
              uVar16 = local_148;
              uVar15 = uStack_150;
              uVar14 = local_158;
              uVar13 = uStack_160;
              uVar12 = local_168;
              pwVar11 = pwStack_170;
              auVar10 = local_178;
              uVar9 = uStack_1e0;
              uVar8 = local_1e8;
              pwVar30 = pwStack_1f0;
              auVar7 = local_1f8;
              *(undefined4 *)this_00 = 1;
              *(undefined4 *)(this_00 + 4) = 0;
              *(undefined8 *)(this_00 + 8) = *(undefined8 *)(local_290 + 0x20);
              *(uint *)(this_00 + 0x10) = uVar44;
              *(undefined4 *)(this_00 + 0x14) = 0;
              *(undefined1 (*) [8])(this_00 + 0x98) = local_1f8;
              *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                **)(this_00 + 0xa0) = pwStack_1f0;
              *(undefined1 (*) [8])(this_00 + 0x18) = local_178;
              *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                **)(this_00 + 0x20) = pwStack_170;
              *(undefined8 *)(this_00 + 0xa8) = local_1e8;
              *(undefined8 *)(this_00 + 0xb0) = uStack_1e0;
              *(undefined8 *)(this_00 + 0xb8) = local_1d8;
              *(undefined8 *)(this_00 + 0xc0) = uStack_1d0;
              *(undefined8 *)(this_00 + 200) = local_1c8;
              *(undefined8 *)(this_00 + 0xd0) = uStack_1c0;
              *(undefined8 *)(this_00 + 0xd8) = local_1b8;
              *(undefined8 *)(this_00 + 0xe0) = uStack_1b0;
              *(undefined8 *)(this_00 + 0x28) = local_168;
              *(undefined8 *)(this_00 + 0x30) = uStack_160;
              *(undefined8 *)(this_00 + 0x38) = local_158;
              *(undefined8 *)(this_00 + 0x40) = uStack_150;
              *(undefined8 *)(this_00 + 0xe8) = local_1a8;
              *(undefined8 *)(this_00 + 0xf0) = uStack_1a0;
              *(undefined8 *)(this_00 + 0x48) = local_148;
              *(undefined8 *)(this_00 + 0x50) = uStack_140;
              *(undefined8 *)(this_00 + 0x58) = local_138;
              *(undefined8 *)(this_00 + 0x60) = uStack_130;
              *(undefined8 *)(this_00 + 0xf8) = local_198;
              *(undefined8 *)(this_00 + 0x100) = uStack_190;
              *(undefined8 *)(this_00 + 0x68) = local_128;
              *(undefined8 *)(this_00 + 0x70) = uStack_120;
              *(undefined8 *)(this_00 + 0x78) = local_118;
              *(undefined8 *)(this_00 + 0x80) = uStack_110;
              *(undefined4 *)(this_00 + 0x108) = local_188;
              *(undefined4 *)(this_00 + 0x10c) = uStack_184;
              *(undefined4 *)(this_00 + 0x110) = uStack_180;
              *(undefined4 *)(this_00 + 0x114) = uStack_17c;
              *(ulonglong *)(this_00 + 0x88) = CONCAT44(uStack_104,local_108);
              *(ulonglong *)(this_00 + 0x90) = CONCAT44(uStack_fc,uStack_100);
              *(undefined4 *)(this_00 + 0x118) = *(undefined4 *)(local_290 + 0x40);
              *(undefined4 *)(this_00 + 0x11c) = 0;
              *(undefined8 *)(this_00 + 0x120) = 0;
              KeInitializeSpinLock(this_00 + 0x128);
              this_00[0x134] = (flow_context)0x0;
              *(undefined8 *)(this_00 + 0x138) = 0;
              *(undefined4 *)(this_00 + 0x130) = 0;
              *(undefined8 *)(this_00 + 0x140) = 0;
              *(undefined8 *)(this_00 + 0x148) = 0;
              *(undefined8 *)(this_00 + 0x150) = 0;
              *(undefined8 *)(this_00 + 0x158) = 0;
              *(undefined8 *)(this_00 + 0x160) = 0;
              *(undefined8 *)(this_00 + 0x168) = 0;
              *(undefined8 *)(this_00 + 0x170) = 0;
              *(undefined8 *)(this_00 + 0x178) = 0;
              *(undefined8 *)(this_00 + 0x180) = 0;
              this_00[0x18c] = (flow_context)0x0;
              *(undefined8 *)(this_00 + 400) = 0;
              *(undefined4 *)(this_00 + 0x188) = 0;
              this_00[0x198] = (flow_context)0x0;
              *(undefined4 *)(this_00 + 0x199) = 0;
              *(undefined2 *)(this_00 + 0x19d) = 0;
              this_00[0x19f] = (flow_context)0x0;
              *(undefined8 *)(this_00 + 0x1a0) = 0;
              *(undefined8 *)(this_00 + 0x1a8) = 0;
              *(undefined8 *)(this_00 + 0x1b0) = 0;
              *(undefined8 *)(this_00 + 0x1b8) = 0;
              *(undefined8 *)(this_00 + 0x1c0) = 0;
              KeInitializeSpinLock(this_00 + 0x1a0);
              pfVar1 = this_00 + 0x1a8;
              *(undefined4 *)(this_00 + 0x1b8) = 0;
              *(undefined8 *)(this_00 + 0x1c0) = 0;
              *(flow_context **)(this_00 + 0x1b0) = pfVar1;
              *(flow_context **)pfVar1 = pfVar1;
              *(undefined8 *)(this_00 + 0x1c8) = 0;
              *(undefined8 *)(this_00 + 0x1d0) = 0;
              *(undefined8 *)(this_00 + 0x1d8) = 0;
              *(undefined8 *)(this_00 + 0x1e0) = 0;
              *(undefined8 *)(this_00 + 0x1e8) = 0;
              KeInitializeSpinLock(this_00 + 0x1c8);
              pfVar1 = this_00 + 0x1d0;
              *(undefined4 *)(this_00 + 0x1e0) = 0;
              *(undefined8 *)(this_00 + 0x1e8) = 0;
              *(flow_context **)(this_00 + 0x1d8) = pfVar1;
              *(flow_context **)pfVar1 = pfVar1;
              KeInitializeSpinLock(this_00 + 0x1f0);
              this_00[0x1f8] = (flow_context)0x0;
              *(undefined4 *)(this_00 + 0x1f9) = 0;
              *(undefined2 *)(this_00 + 0x1fd) = 0;
              this_00[0x1ff] = (flow_context)0x0;
              *(undefined8 *)(this_00 + 0x200) = 0;
              *(undefined2 *)(this_00 + 0x208) = 0;
              this_00[0x20a] = (flow_context)0x0;
              *(undefined4 *)(this_00 + 0x20b) = 0;
              this_00[0x20f] = (flow_context)0x0;
              if (local_240[0] != 0) {
                local_208[0] = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                                *)0x0;
                local_258[0] = (**(uint **)(local_290 + 0x30) >> 1) - 1;
                this_01 = (shared_ptr_impl *)ExAllocatePoolWithTag(0x600,0x28,0x666e6477);
                if (this_01 != (shared_ptr_impl *)0x0) {
                  if ((char)ExPoolZeroingNativelySupported == '\0') {
                    *(undefined8 *)this_01 = 0;
                    *(undefined8 *)(this_01 + 8) = 0;
                    *(undefined8 *)(this_01 + 0x10) = 0;
                    *(undefined8 *)(this_01 + 0x18) = 0;
                    *(undefined8 *)(this_01 + 0x20) = 0;
                  }
                  piVar27 = (int *)shared_ptr<kwstring>::shared_ptr_impl::
                                   shared_ptr_impl<std::nullptr_t,unsigned_int>
                                             (this_01,(std__nullptr_t *)local_208,(uint *)local_258)
                  ;
                  if (piVar27 != (int *)0x0) {
                    *(undefined1 *)(piVar27 + 1) = 1;
                    if (*piVar27 < 0) {
                      LOCK();
                      piVar2 = piVar27 + 8;
                      iVar24 = *piVar2;
                      *piVar2 = *piVar2 + -1;
                      UNLOCK();
                      if (iVar24 == 1) {
                        if (*(longlong *)(piVar27 + 4) != 0) {
                          ExFreePoolWithTag(*(longlong *)(piVar27 + 4),0x666e6477);
                        }
                        ExFreePoolWithTag(piVar27,0x666e6477);
                      }
                    }
                    else {
                      piVar43 = piVar27;
                    }
                  }
                }
                lVar26 = *(longlong *)(this_00 + 400);
                if (lVar26 != 0) {
                  LOCK();
                  piVar27 = (int *)(lVar26 + 0x20);
                  iVar24 = *piVar27;
                  *piVar27 = *piVar27 + -1;
                  UNLOCK();
                  if (iVar24 == 1) {
                    if (*(longlong *)(lVar26 + 0x10) != 0) {
                      ExFreePoolWithTag(*(longlong *)(lVar26 + 0x10),0x666e6477);
                    }
                    ExFreePoolWithTag(lVar26,0x666e6477);
                  }
                }
                *(int **)(this_00 + 400) = piVar43;
                if (piVar43 != (int *)0x0) {
                  LOCK();
                  piVar43[8] = piVar43[8] + 1;
                  UNLOCK();
                  LOCK();
                  piVar27 = piVar43 + 8;
                  iVar24 = *piVar27;
                  *piVar27 = *piVar27 + -1;
                  UNLOCK();
                  if (iVar24 == 1) {
                    if (*(longlong *)(piVar43 + 4) != 0) {
                      ExFreePoolWithTag(*(longlong *)(piVar43 + 4),0x666e6477);
                    }
                    ExFreePoolWithTag(piVar43,0x666e6477);
                  }
                }
                iVar24 = *(int *)(this_00 + 0x188);
                this_00[0x18c] = (flow_context)0x1;
                if (iVar24 < 0) goto LAB_140008009;
                puVar5 = *(uint **)(local_290 + 0x30);
                if (puVar5 != (uint *)0x0) {
                  memmove(*(void **)(*(longlong *)(this_00 + 400) + 0x10),*(void **)(puVar5 + 2),
                          (ulonglong)*puVar5 - 2);
                }
              }
              fStack_27f = local_260[0];
              this_00[0x20a] = local_260[0];
              cStack_280 = *(short *)param_1 == 0x34;
              local_260[0] = (flow_context)0x0;
              local_288 = *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                            **)(local_290 + 0x20);
              uStack_27e = 0;
              uStack_27c = 0;
              uStack_27a = 0;
              local_2b8 = pwVar6 + 0x60;
              uStack_230 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                            **)(ulonglong)CONCAT11(fStack_27f,cStack_280);
              local_278 = this_00;
              local_238 = local_288;
              local_228 = this_00;
              puVar28 = (undefined8 *)
                        RtlInsertElementGenericTableAvl(local_2b8,&local_238,0x18,local_260);
              local_267 = 0;
              local_263 = 0;
              local_261 = 0;
              if (puVar28 == (undefined8 *)0x0) {
                iVar24 = -0x3fffffe9;
              }
              else {
                if (local_260[0] == (flow_context)0x0) {
                  *puVar28 = local_238;
                  puVar28[1] = uStack_230;
                  puVar28[2] = local_228;
                }
                LOCK();
                *(int *)this_00 = *(int *)this_00 + 1;
                UNLOCK();
                local_260[0] = (flow_context)((char)uVar44 != '\x02');
                local_248[0] = cStack_280;
                local_258[0] = (int)CONCAT71((int7)((ulonglong)puVar28 >> 8),local_260[0]);
                uVar41 = 0x16;
                lVar25 = 300;
                local_250[0] = fStack_27f;
                uVar42 = 0x1a;
                local_208[0] = local_288;
                local_238 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                             *)local_260;
                uStack_230 = local_208;
                local_228 = (flow_context *)&local_270;
                local_220 = local_250;
                local_218 = pwVar6 + 0xf8;
                lVar26 = 0x134;
                if (cStack_280 == '\0') {
                  lVar26 = 0x138;
                  uVar40 = 0x12;
                  lVar31 = 0x130;
                  uVar36 = 0x1a;
                  uVar39 = 0xe;
                  lVar34 = 0x120;
                  lVar37 = 0x118;
                }
                else {
                  uVar40 = 0x10;
                  lVar31 = 300;
                  uVar39 = 0xc;
                  uVar41 = 0x14;
                  lVar37 = 0x114;
                  uVar36 = 0x18;
                  lVar34 = 0x11c;
                }
                uVar38 = (ulonglong)*(uint *)(pwVar6 + lVar37);
                local_270 = this_00;
                local_210 = local_248;
                iVar24 = <lambda_33181a0f4f6c07f5fc5dd0cd4df2a99c>::
                         operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int>
                                   (&local_238,uVar40,*(uint *)(pwVar6 + lVar37),uVar39,
                                    (char)*(undefined4 *)(pwVar6 + lVar34),uVar41,
                                    (char)*(undefined4 *)(pwVar6 + lVar31),uVar36,
                                    (char)*(undefined4 *)(pwVar6 + lVar26));
                if (-1 < iVar24) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
                    WPP_SF_SII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,uVar38,
                               L"Associated flow id",(char)local_288,(char)uVar44 != '\x02');
                  }
                  uStack_230 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                                **)local_240;
                  local_228 = (flow_context *)&local_290;
                  local_238 = pwVar6;
                  sVar4 = *(short *)param_1;
                  if (cVar3 == '\x06') {
                    if (sVar4 != 0x34) {
                      lVar25 = 0x130;
                    }
                  }
                  else {
                    lVar25 = 0x138;
                    if (sVar4 == 0x34) {
                      lVar25 = 0x134;
                    }
                  }
                  local_158 = local_1d8;
                  uStack_150 = uStack_1d0;
                  local_148 = local_1c8;
                  uStack_140 = uStack_1c0;
                  uVar39 = 0x18;
                  if (cVar3 == '\x06') {
                    uVar39 = 0x14;
                  }
                  local_138 = local_1b8;
                  uStack_130 = uStack_1b0;
                  if (cVar3 == '\x06') {
                    uVar42 = 0x16;
                  }
                  local_128 = local_1a8;
                  uStack_120 = uStack_1a0;
                  if (sVar4 == 0x34) {
                    uVar42 = uVar39;
                  }
                  local_118 = local_198;
                  uStack_110 = uStack_190;
                  local_178 = auVar7;
                  pwStack_170 = pwVar30;
                  local_168 = uVar8;
                  uStack_160 = uVar9;
                  local_108 = local_188;
                  uStack_104 = uStack_184;
                  uStack_100 = uStack_180;
                  uStack_fc = uStack_17c;
                  local_1f8 = auVar10;
                  pwStack_1f0 = pwVar11;
                  local_1e8 = uVar12;
                  uStack_1e0 = uVar13;
                  local_1d8 = uVar14;
                  uStack_1d0 = uVar15;
                  local_1c8 = uVar16;
                  uStack_1c0 = uVar17;
                  local_1b8 = uVar18;
                  uStack_1b0 = uVar19;
                  local_1a8 = uVar20;
                  uStack_1a0 = uVar21;
                  local_198 = uVar22;
                  uStack_190 = uVar23;
                  iVar24 = stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                           ::queue_connection_open<<lambda_b84f72b39e47e318c302fe174996c70b>_>
                                     (*(stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
                                        **)(pwVar6 + 8),local_288,uVar42,
                                      *(undefined4 *)(pwVar6 + lVar25));
                  pfVar1 = local_278;
                  if (-1 < iVar24) {
                    *(wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                      **)(local_278 + 0x120) = pwVar6;
                    lVar26 = *(longlong *)(local_278 + 0x138);
                    if (lVar26 != 0) {
                      LOCK();
                      piVar43 = (int *)(lVar26 + 0x18);
                      iVar24 = *piVar43;
                      *piVar43 = *piVar43 + -1;
                      UNLOCK();
                      if (iVar24 == 1) {
                        KeSetEvent(*(undefined8 *)(lVar26 + 0x10),0,0);
                        ExFreePoolWithTag(lVar26,0x666e6477);
                      }
                      *(undefined8 *)(pfVar1 + 0x138) = 0;
                    }
                    lVar26 = *(longlong *)(pwVar6 + 0xe8);
                    *(longlong *)(pfVar1 + 0x138) = lVar26;
                    if (lVar26 != 0) {
                      LOCK();
                      *(int *)(lVar26 + 0x18) = *(int *)(lVar26 + 0x18) + 1;
                      UNLOCK();
                    }
                    flow_context::release(this_00);
                    goto LAB_140007fe0;
                  }
                  local_238 = local_288;
                  uStack_230 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                                **)CONCAT44(CONCAT22(uStack_27a,uStack_27c),
                                            CONCAT22(uStack_27e,CONCAT11(fStack_27f,cStack_280)));
                  local_228 = local_278;
                  remove_contexts<unique_lock<spin_lock>_>
                            ((wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                              *)pwVar6,&local_238,0);
                }
                local_238 = local_288;
                uStack_230 = (wfp_callout<class_implementation::wfp_callout,class_implementation::event,class_implementation::avl_table,class_implementation::queue,class_stream_handler<class_implementation::stream_handler<class_implementation::irp,class_implementation::queue,class_implementation::csqueue>_>,class_running_processes<class_implementation::running_processes,class_implementation::avl_table,class_path_list<class_implementation::path_list>_>,class_excluded_addresses<class_implementation::avl_table>_>
                              **)CONCAT44(CONCAT22(uStack_27a,uStack_27c),
                                          CONCAT22(uStack_27e,CONCAT11(fStack_27f,cStack_280)));
                local_228 = local_278;
                RtlDeleteElementGenericTableAvl(local_2b8,&local_238);
                flow_context::release(this_00);
              }
              flow_context::release(this_00);
            }
LAB_140008009:
            KeReleaseInStackQueuedSpinLock(local_f8);
            return iVar24;
          }
        }
      }
LAB_140007fe0:
      KeReleaseInStackQueuedSpinLock(local_f8);
      return 0;
    }
  }
  else if (uVar38 < 0xc800000) {
    pwVar32 = L"Stream Handler Queue Length critical! Streams";
    goto LAB_14000803f;
  }
  pwVar32 = L"Stream Handler Queue Allocation critical! Bytes";
  uVar29 = uVar38;
LAB_14000803f:
  LOG_WARNING_UINT64(pwVar32,uVar29);
  return 0;
}



===== queue_connection_open<<lambda_b84f72b39e47e318c302fe174996c70b>_> @ 1400080ac =====

/* public: auto __cdecl stream_handler<class stream_handler<class
   implementation::stream_handler<class implementation::irp,class implementation::queue,class
   implementation::csqueue> > >::queue_connection_open<class
   <lambda_b84f72b39e47e318c302fe174996c70b> >(unsigned __int64,unsigned short,unsigned int,enum
   IPPROTO,bool,bool,bool,struct sockaddr_storage,struct sockaddr_storage,unsigned int,unsigned
   __int64,unsigned int,class <lambda_b84f72b39e47e318c302fe174996c70b> const & __ptr64,bool)
   __ptr64 */

void __thiscall
stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
::queue_connection_open<<lambda_b84f72b39e47e318c302fe174996c70b>_>
          (stream_handler<stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>_>
           *this,undefined8 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
          undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 *param_9,
          undefined8 *param_10,undefined4 param_11,undefined8 param_12,undefined4 param_13,
          <lambda_b84f72b39e47e318c302fe174996c70b> *param_14,undefined1 param_15)

{
  undefined8 local_318;
  undefined2 local_310;
  undefined4 local_30e;
  undefined4 local_30a;
  undefined1 local_306;
  undefined1 local_305;
  undefined1 local_304;
  undefined8 local_303;
  undefined8 uStack_2fb;
  undefined8 local_2f3;
  undefined8 uStack_2eb;
  undefined8 local_2e3;
  undefined8 uStack_2db;
  undefined8 local_2d3;
  undefined8 uStack_2cb;
  undefined8 local_2c3;
  undefined8 uStack_2bb;
  undefined8 local_2b3;
  undefined8 uStack_2ab;
  undefined8 local_2a3;
  undefined8 uStack_29b;
  undefined8 local_293;
  undefined8 uStack_28b;
  undefined8 local_283;
  undefined8 uStack_27b;
  undefined8 local_273;
  undefined8 uStack_26b;
  undefined8 local_263;
  undefined8 uStack_25b;
  undefined8 local_253;
  undefined8 uStack_24b;
  undefined8 local_243;
  undefined8 uStack_23b;
  undefined8 local_233;
  undefined8 uStack_22b;
  undefined8 local_223;
  undefined8 uStack_21b;
  undefined8 local_213;
  undefined8 uStack_20b;
  undefined4 local_203;
  undefined8 local_1ff;
  undefined1 local_1f7;
  undefined4 local_1f6;
  undefined4 local_1f2;
  connection_notification local_1e8 [480];
  
  local_203 = param_11;
  local_283 = *param_10;
  uStack_27b = param_10[1];
  local_273 = param_10[2];
  uStack_26b = param_10[3];
  local_263 = param_10[4];
  uStack_25b = param_10[5];
  local_253 = param_10[6];
  uStack_24b = param_10[7];
  local_243 = param_10[8];
  uStack_23b = param_10[9];
  local_233 = param_10[10];
  uStack_22b = param_10[0xb];
  local_223 = param_10[0xc];
  uStack_21b = param_10[0xd];
  local_213 = param_10[0xe];
  uStack_20b = param_10[0xf];
  local_1ff = param_12;
  local_303 = *param_9;
  uStack_2fb = param_9[1];
  local_2f3 = param_9[2];
  uStack_2eb = param_9[3];
  local_2e3 = param_9[4];
  uStack_2db = param_9[5];
  local_2d3 = param_9[6];
  uStack_2cb = param_9[7];
  local_2c3 = param_9[8];
  uStack_2bb = param_9[9];
  local_2b3 = param_9[10];
  uStack_2ab = param_9[0xb];
  local_2a3 = param_9[0xc];
  uStack_29b = param_9[0xd];
  local_293 = param_9[0xe];
  uStack_28b = param_9[0xf];
  local_30a = param_4;
  local_306 = param_5;
  local_305 = param_6;
  local_304 = param_7;
  local_1f2 = param_13;
  local_1f7 = param_15;
  local_1f6 = 0;
  local_318 = param_1;
  local_310 = param_2;
  local_30e = param_3;
  network_filtering::connection_notification::connection_notification
            (local_1e8,(connection_information *)&local_318);
  implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>
  ::enqueue<<lambda_b84f72b39e47e318c302fe174996c70b>_>
            ((stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *)
             (this + 0x10),local_1e8,param_14);
  return;
}



===== to_sockaddr @ 14000827c =====

/* private: struct sockaddr_storage __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::to_sockaddr(struct FWPS_INCOMING_VALUES0_ const * __ptr64,int,int,int,int) __ptr64 */

FWPS_INCOMING_VALUES0_ * __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::to_sockaddr(wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
              *this,FWPS_INCOMING_VALUES0_ *param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined4 in_register_00000084;
  short *psVar6;
  int in_stack_00000038;
  
  psVar6 = (short *)CONCAT44(in_register_00000084,param_2);
  memset(param_1,0,0x80);
  sVar1 = *psVar6;
  if (sVar1 != 0x34) {
    if ((sVar1 != 0x24) && (sVar1 != 0x30)) {
      if (sVar1 != 0x36) {
        if (sVar1 == 0x26) {
          if (*(int *)(*(longlong *)(psVar6 + 4) + (longlong)param_5 * 0x10) == 0) {
            return param_1;
          }
          if (*(int *)(*(longlong *)(psVar6 + 4) + (longlong)in_stack_00000038 * 0x10) == 0) {
            return param_1;
          }
        }
        else if (sVar1 != 0x32) {
          return param_1;
        }
      }
      *(undefined2 *)param_1 = 0x17;
      puVar4 = *(undefined8 **)(*(longlong *)(psVar6 + 4) + 8 + (longlong)param_5 * 0x10);
      uVar5 = puVar4[1];
      *(undefined8 *)(param_1 + 8) = *puVar4;
      *(undefined8 *)(param_1 + 0x10) = uVar5;
      goto LAB_14000836b;
    }
    if ((*(int *)(*(longlong *)(psVar6 + 4) + (longlong)param_3 * 0x10) == 0) ||
       (*(int *)(*(longlong *)(psVar6 + 4) + (longlong)param_4 * 0x10) == 0)) {
      *(undefined2 *)param_1 = 0;
      return param_1;
    }
  }
  *(undefined2 *)param_1 = 2;
  uVar3 = *(uint *)(*(longlong *)(psVar6 + 4) + 8 + (longlong)param_3 * 0x10);
  *(uint *)(param_1 + 4) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  in_stack_00000038 = param_4;
LAB_14000836b:
  uVar2 = *(ushort *)(*(longlong *)(psVar6 + 4) + 8 + (longlong)in_stack_00000038 * 0x10);
  *(ushort *)(param_1 + 2) = uVar2 >> 8 | uVar2 << 8;
  return param_1;
}



===== make_flow_async_if_necessary @ 140008394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::make_flow_async_if_necessary(struct wfp_callout<class implementation::wfp_callout,class
   implementation::event,class implementation::avl_table,class implementation::queue,class
   stream_handler<class implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue> >,class running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >,class excluded_addresses<class implementation::avl_table>
   >::flow_context * __ptr64) __ptr64 */

void __thiscall
wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
::make_flow_async_if_necessary
          (wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
           *this,flow_context *param_1)

{
  flow_context *pfVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined1 local_40 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  if ((*(void **)(param_1 + 0x200) != SystemReserved1[0xf]) &&
     ((param_1[0x208] != (flow_context)0x0 || (0x63fffff < *(ulonglong *)(param_1 + 0x1e8))))) {
    if (param_1[0x209] == (flow_context)0x0) {
      if ((*(ulonglong *)(param_1 + 0x140) < 0x100001) &&
         (*(ulonglong *)(param_1 + 0x148) < 0x100001)) {
        return;
      }
      local_48 = 0;
      lVar2 = KeQueryInterruptTimePrecise(&local_48);
      KeAcquireInStackQueuedSpinLock(param_1 + 0x1a0,local_40);
      pfVar1 = *(flow_context **)(param_1 + 0x1a8);
      if (pfVar1 == param_1 + 0x1a8) {
        lVar3 = 0;
      }
      else {
        lVar3 = *(longlong *)(pfVar1 + 200);
      }
      KeReleaseInStackQueuedSpinLock(local_40);
      if ((lVar3 == 0) ||
         (((ulonglong)(lVar2 - lVar3) < 0xc351 && (*(ulonglong *)(param_1 + 0x1c0) < 0x100001)))) {
        KeAcquireInStackQueuedSpinLock(param_1 + 0x1c8,local_40);
        pfVar1 = *(flow_context **)(param_1 + 0x1d0);
        if (pfVar1 == param_1 + 0x1d0) {
          lVar3 = 0;
        }
        else {
          lVar3 = *(longlong *)(pfVar1 + 200);
        }
        KeReleaseInStackQueuedSpinLock(local_40);
        if (lVar3 == 0) {
          return;
        }
        if (((ulonglong)(lVar2 - lVar3) < 0xc351) && (*(ulonglong *)(param_1 + 0x1e8) < 0x100001)) {
          return;
        }
      }
    }
    reinject_pending_traffic(this,param_1);
  }
  return;
}



===== process_state_changed @ 140008524 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list>
   >::process_state_changed(unsigned int,unsigned __int64,struct _UNICODE_STRING const *
   __ptr64,enum running_processes<class implementation::running_processes,class
   implementation::avl_table,class path_list<class implementation::path_list> >::process_state,bool)
   __ptr64 */

void __thiscall
running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
::process_state_changed
          (running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
           *this,uint param_1,__uint64 param_2,_UNICODE_STRING *param_3,process_state param_4,
          bool param_5)

{
  running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
  *prVar1;
  int iVar2;
  longlong lVar3;
  __uint64 _Var4;
  undefined1 uVar5;
  uint *puVar6;
  longlong lVar7;
  int *piVar8;
  undefined1 auStack_d8 [32];
  uint local_b8;
  __uint64 local_b0;
  char local_a0 [8];
  uint local_98;
  uint uStack_94;
  undefined8 uStack_90;
  ulonglong uStack_88;
  uint local_78 [2];
  undefined8 uStack_70;
  char local_68;
  undefined1 uStack_67;
  bool bStack_66;
  undefined1 uStack_65;
  undefined4 uStack_64;
  uint local_60 [6];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  prVar1 = this + 8;
  local_b8 = param_1;
  local_b0 = param_2;
  local_98 = param_1;
  if (param_4 == 2) {
    KeAcquireInStackQueuedSpinLock(prVar1,local_78);
    uStack_88 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    RtlDeleteElementGenericTableAvl(this + 0x38,&local_98);
    puVar6 = local_78;
  }
  else {
    if (param_3 != (_UNICODE_STRING *)0x0) {
      KeAcquireInStackQueuedSpinLock(prVar1,&local_98);
      lVar7 = *(longlong *)(this + 0x20);
      if (lVar7 != 0) {
        LOCK();
        *(int *)(lVar7 + 0x30) = *(int *)(lVar7 + 0x30) + 1;
        UNLOCK();
      }
      KeReleaseInStackQueuedSpinLock(&local_98);
      local_a0[0] = path_list<implementation::path_list>::contains
                              ((path_list<implementation::path_list> *)(lVar7 + 8),
                               *(wchar_t **)(param_3 + 8),
                               *(wchar_t **)(param_3 + 8) + (*(ushort *)param_3 >> 1));
      KeAcquireInStackQueuedSpinLock(prVar1,&local_98);
      lVar3 = *(longlong *)(this + 0x30);
      if (lVar3 == 0) {
        piVar8 = (int *)0x30;
      }
      else {
        piVar8 = (int *)(lVar3 + 0x30);
        LOCK();
        *piVar8 = *piVar8 + 1;
        UNLOCK();
      }
      KeReleaseInStackQueuedSpinLock(&local_98);
      uVar5 = path_list<implementation::path_list>::contains
                        ((path_list<implementation::path_list> *)(lVar3 + 8),
                         *(wchar_t **)(param_3 + 8),
                         *(wchar_t **)(param_3 + 8) + (*(ushort *)param_3 >> 1));
      KeAcquireInStackQueuedSpinLock(prVar1,local_60);
      local_78[0] = local_b8;
      uStack_67 = param_4 == 1;
      local_78[1] = 0;
      uStack_70 = local_b0;
      _Var4 = uStack_70;
      uStack_70._4_4_ = (uint)(local_b0 >> 0x20);
      local_68 = local_a0[0];
      bStack_66 = param_5;
      uStack_64 = 0;
      uStack_88 = (ulonglong)CONCAT13(uVar5,CONCAT12(param_5,CONCAT11(uStack_67,local_a0[0])));
      local_98 = local_b8;
      uStack_94 = 0;
      uStack_90._0_4_ = (uint)local_b0;
      uStack_90._4_4_ = uStack_70._4_4_;
      local_a0[0] = '\0';
      uStack_70 = _Var4;
      uStack_65 = uVar5;
      puVar6 = (uint *)RtlInsertElementGenericTableAvl(this + 0x38,&local_98,0x18,local_a0);
      if ((puVar6 != (uint *)0x0) && (local_a0[0] == '\0')) {
        *puVar6 = local_98;
        puVar6[1] = uStack_94;
        puVar6[2] = (uint)uStack_90;
        puVar6[3] = uStack_90._4_4_;
        *(ulonglong *)(puVar6 + 4) = uStack_88;
      }
      KeReleaseInStackQueuedSpinLock(local_60);
      if (lVar3 != 0) {
        LOCK();
        iVar2 = *piVar8;
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          if (*(longlong *)(lVar3 + 0x20) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar3 + 0x20),0x666e6477);
          }
          if (*(longlong *)(lVar3 + 0x18) != 0) {
            ExFreePoolWithTag(*(longlong *)(lVar3 + 0x18),0x666e6477);
          }
          ExFreePoolWithTag(lVar3,0x666e6477);
        }
      }
      if (lVar7 == 0) {
        return;
      }
      LOCK();
      piVar8 = (int *)(lVar7 + 0x30);
      iVar2 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        return;
      }
      if (*(longlong *)(lVar7 + 0x20) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x20),0x666e6477);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x18),0x666e6477);
      }
      ExFreePoolWithTag(lVar7,0x666e6477);
      return;
    }
    KeAcquireInStackQueuedSpinLock(prVar1,local_60);
    uStack_88 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    lVar7 = RtlLookupElementGenericTableAvl(this + 0x38,&local_98);
    if (lVar7 != 0) {
      *(bool *)(lVar7 + 0x11) = param_4 == 1;
      *(bool *)(lVar7 + 0x12) = param_5;
    }
    puVar6 = local_60;
  }
  KeReleaseInStackQueuedSpinLock(puVar6);
  return;
}



===== contains @ 140008838 =====

/* public: __cdecl path_list<class implementation::path_list>::contains(wchar_t const * __ptr64
   const,wchar_t const * __ptr64 const) __ptr64 */

ulonglong __thiscall
path_list<implementation::path_list>::contains
          (path_list<implementation::path_list> *this,wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  longlong lVar2;
  short sVar3;
  uint uVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  path_list<implementation::path_list> *ppVar7;
  wchar_t *pwVar8;
  path_list<implementation::path_list> *ppVar9;
  path_list<implementation::path_list> *ppVar10;
  path_list<implementation::path_list> *ppVar11;
  longlong *plVar12;
  
  plVar12 = *(longlong **)(this + 0x18);
  ppVar9 = *(path_list<implementation::path_list> **)(this + 0x10);
  pwVar5 = param_2;
  ppVar7 = this;
  if (plVar12 != *(longlong **)(this + 0x20)) {
    ppVar7 = ppVar9;
    do {
      ppVar10 = ppVar7 + *plVar12 * 2;
      if (*(short *)(ppVar10 + -2) == 0x5c) {
        ppVar10 = ppVar10 + -2;
      }
      pwVar5 = (wchar_t *)((longlong)ppVar10 - (longlong)ppVar9 >> 1);
      pwVar8 = param_1;
      ppVar11 = ppVar9;
      if ((longlong)pwVar5 <= (longlong)param_2 - (longlong)param_1 >> 1) {
        do {
          if (ppVar11 == ppVar10) {
            if ((pwVar8 == param_2) || (*pwVar8 == L'\\')) goto LAB_14000899d;
            break;
          }
          wVar1 = *pwVar8;
          pwVar8 = pwVar8 + 1;
          sVar3 = *(short *)ppVar11;
          ppVar11 = ppVar11 + 2;
          sVar3 = RtlDowncaseUnicodeChar(sVar3);
          ppVar7 = (path_list<implementation::path_list> *)(ulonglong)(ushort)wVar1;
          pwVar5 = (wchar_t *)RtlDowncaseUnicodeChar(ppVar7);
        } while ((short)pwVar5 == sVar3);
      }
      pwVar8 = param_2 + -1;
      pwVar5 = (wchar_t *)((longlong)pwVar8 - (longlong)(param_1 + -1) & 0xfffffffffffffffe);
      if ((longlong)((ulonglong)(ppVar10 + (-2 - (longlong)(ppVar9 + -2))) & 0xfffffffffffffffe) <=
          (longlong)pwVar5) {
        do {
          ppVar10 = ppVar10 + -2;
          if (ppVar10 == ppVar9 + -2) {
            if ((pwVar8 == param_1 + -1) || (*pwVar8 == L'\\')) goto LAB_14000899d;
            break;
          }
          wVar1 = *pwVar8;
          pwVar8 = pwVar8 + -1;
          sVar3 = RtlDowncaseUnicodeChar(*(short *)ppVar10);
          ppVar7 = (path_list<implementation::path_list> *)(ulonglong)(ushort)wVar1;
          pwVar5 = (wchar_t *)RtlDowncaseUnicodeChar(ppVar7);
        } while ((short)pwVar5 == sVar3);
      }
      lVar2 = *plVar12;
      plVar12 = plVar12 + 1;
      ppVar7 = *(path_list<implementation::path_list> **)(this + 0x10);
      ppVar9 = ppVar7 + (lVar2 + 1) * 2;
    } while (plVar12 != *(longlong **)(this + 0x20));
  }
  uVar4 = (uint)pwVar5 & 0xffffff00;
LAB_1400089a3:
  uVar6 = (ulonglong)uVar4;
  if (this[9] != (path_list<implementation::path_list>)0x0) {
    uVar6 = (CONCAT71((int7)((ulonglong)ppVar7 >> 8),(char)uVar4) ^ 1) & 0xffffffff;
  }
  return uVar6;
LAB_14000899d:
  uVar4 = (uint)CONCAT71((int7)((ulonglong)pwVar5 >> 8),1);
  goto LAB_1400089a3;
}



===== lookup @ 1400089c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: struct process_info __cdecl running_processes<class
   implementation::running_processes,class implementation::avl_table,class path_list<class
   implementation::path_list> >::lookup(unsigned int,bool)const __ptr64 */

char * __thiscall
running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
::lookup(running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
         *this,uint param_1,bool param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 in_register_00000014;
  char *pcVar5;
  undefined3 in_register_00000081;
  int iVar6;
  char in_R9B;
  undefined1 auStack_88 [32];
  int local_68 [8];
  undefined1 local_48 [24];
  ulonglong local_30;
  
  iVar6 = CONCAT31(in_register_00000081,param_2);
  pcVar5 = (char *)CONCAT44(in_register_00000014,param_1);
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  if ((iVar6 == *(int *)(this + 0xb8)) || (iVar2 = PsGetProcessId(), iVar6 == iVar2)) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5[4] = '\0';
    pcVar5[5] = '\0';
    pcVar5[6] = '\0';
    pcVar5[7] = '\0';
    pcVar5[8] = '\0';
    pcVar5[9] = '\0';
    pcVar5[10] = '\0';
    pcVar5[0xb] = '\0';
    pcVar5[0xc] = '\0';
    pcVar5[0xd] = '\0';
    pcVar5[0xe] = '\0';
    pcVar5[0xf] = '\0';
    pcVar5[0x10] = '\x01';
    pcVar5[0x11] = '\0';
    pcVar5[0x12] = '\0';
    pcVar5[0x13] = '\0';
    pcVar5[0x14] = '\0';
    pcVar5[0x15] = '\0';
    pcVar5[0x16] = '\0';
    pcVar5[0x17] = '\0';
    return pcVar5;
  }
  KeAcquireInStackQueuedSpinLock(this + 8,local_48);
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[0] = iVar6;
  lVar3 = RtlLookupElementGenericTableAvl(this + 0x38,local_68);
  uVar4 = 0;
  if (lVar3 == 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5[4] = '\0';
    pcVar5[5] = '\0';
    pcVar5[6] = '\0';
    pcVar5[7] = '\0';
  }
  else {
    if (((this[0x10] !=
          (running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
           )0x0) || (in_R9B == '\0')) || (cVar1 = '\x01', *(char *)(lVar3 + 0x13) == '\0')) {
      cVar1 = '\0';
    }
    if ((*(char *)(lVar3 + 0x10) == '\0') || (cVar1 != '\0')) {
      if (((*(char *)(lVar3 + 0x11) == '\0') ||
          (this[0x10] ==
           (running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
            )0x0)) && ((*(char *)(lVar3 + 0x12) == '\0' || (*(char *)(lVar3 + 0x11) == '\0')))) {
        *pcVar5 = cVar1;
        pcVar5[1] = *(char *)(lVar3 + 0x11);
        pcVar5[2] = '\0';
        pcVar5[3] = '\0';
        pcVar5[4] = '\0';
        pcVar5[5] = '\0';
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        uVar4 = *(undefined8 *)(lVar3 + 8);
        pcVar5[0x10] = '\0';
      }
      else {
        *pcVar5 = '\0';
        pcVar5[1] = *(char *)(lVar3 + 0x11);
        pcVar5[2] = '\0';
        pcVar5[3] = '\0';
        pcVar5[4] = '\0';
        pcVar5[5] = '\0';
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        uVar4 = *(undefined8 *)(lVar3 + 8);
        pcVar5[0x10] = '\x01';
      }
      *(undefined8 *)(pcVar5 + 8) = uVar4;
      goto LAB_140008aae;
    }
    *pcVar5 = '\0';
    pcVar5[1] = *(char *)(lVar3 + 0x11);
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5[4] = '\0';
    pcVar5[5] = '\0';
    pcVar5[6] = '\0';
    pcVar5[7] = '\0';
    uVar4 = *(undefined8 *)(lVar3 + 8);
  }
  *(undefined8 *)(pcVar5 + 8) = uVar4;
  pcVar5[0x10] = '\x01';
LAB_140008aae:
  pcVar5[0x11] = '\0';
  pcVar5[0x12] = '\0';
  pcVar5[0x13] = '\0';
  pcVar5[0x14] = '\0';
  pcVar5[0x15] = '\0';
  pcVar5[0x16] = '\0';
  pcVar5[0x17] = '\0';
  KeReleaseInStackQueuedSpinLock(local_48);
  return pcVar5;
}



===== enqueue<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_> @ 140008b6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::enqueue<class
   <lambda_85692b8abb5e0bd6bf541223f0c9278b> >(struct network_filtering::connection_notification
   const & __ptr64,class <lambda_85692b8abb5e0bd6bf541223f0c9278b> const & __ptr64) __ptr64 */

long __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
enqueue<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_>
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this,
          connection_notification *param_1,<lambda_85692b8abb5e0bd6bf541223f0c9278b> *param_2)

{
  stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *psVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  connection_notification *pcVar16;
  bool bVar17;
  longlong lVar18;
  connection_notification *pcVar19;
  undefined8 *puVar20;
  void *_Dst;
  int iVar21;
  undefined8 *puVar22;
  longlong lVar23;
  void *_Src;
  undefined8 *puVar24;
  longlong lVar25;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  longlong lStack_2d0;
  undefined8 local_2c8 [40];
  undefined8 local_188 [40];
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  psVar1 = this + 0x58;
  local_48 = IoCsqRemoveNextIrp(psVar1,0);
  if (local_48 == 0) {
    bVar17 = false;
  }
  else {
    bVar17 = complete_irp<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_const&___ptr64>
                       (&local_48,param_1,param_2);
  }
  if (bVar17 != false) {
    return 0;
  }
  lVar25 = 2;
  local_48 = 0;
  lStack_40 = 0;
  lVar18 = 2;
  pcVar16 = param_1;
  puVar15 = local_2c8;
  do {
    puVar22 = puVar15;
    pcVar19 = pcVar16;
    uVar2 = *(undefined8 *)(pcVar19 + 8);
    uVar11 = *(undefined8 *)(pcVar19 + 0x10);
    uVar12 = *(undefined8 *)(pcVar19 + 0x18);
    *puVar22 = *(undefined8 *)pcVar19;
    puVar22[1] = uVar2;
    uVar2 = *(undefined8 *)(pcVar19 + 0x20);
    uVar13 = *(undefined8 *)(pcVar19 + 0x28);
    puVar22[2] = uVar11;
    puVar22[3] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x30);
    uVar12 = *(undefined8 *)(pcVar19 + 0x38);
    puVar22[4] = uVar2;
    puVar22[5] = uVar13;
    uVar2 = *(undefined8 *)(pcVar19 + 0x40);
    uVar13 = *(undefined8 *)(pcVar19 + 0x48);
    puVar22[6] = uVar11;
    puVar22[7] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x50);
    uVar12 = *(undefined8 *)(pcVar19 + 0x58);
    puVar22[8] = uVar2;
    puVar22[9] = uVar13;
    uVar2 = *(undefined8 *)(pcVar19 + 0x60);
    uVar13 = *(undefined8 *)(pcVar19 + 0x68);
    puVar22[10] = uVar11;
    puVar22[0xb] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x70);
    uVar12 = *(undefined8 *)(pcVar19 + 0x78);
    puVar22[0xc] = uVar2;
    puVar22[0xd] = uVar13;
    puVar22[0xe] = uVar11;
    puVar22[0xf] = uVar12;
    lVar18 = lVar18 + -1;
    pcVar16 = pcVar19 + 0x80;
    puVar15 = puVar22 + 0x10;
  } while (lVar18 != 0);
  uVar2 = *(undefined8 *)(pcVar19 + 0xb0);
  uVar11 = *(undefined8 *)(pcVar19 + 0x88);
  uVar12 = *(undefined8 *)(pcVar19 + 0x90);
  uVar13 = *(undefined8 *)(pcVar19 + 0x98);
  puVar22[0x10] = *(undefined8 *)(pcVar19 + 0x80);
  puVar22[0x11] = uVar11;
  uVar11 = *(undefined8 *)(pcVar19 + 0xa0);
  uVar14 = *(undefined8 *)(pcVar19 + 0xa8);
  puVar22[0x12] = uVar12;
  puVar22[0x13] = uVar13;
  puVar22[0x14] = uVar11;
  puVar22[0x15] = uVar14;
  puVar22[0x16] = uVar2;
  *(undefined2 *)(puVar22 + 0x17) = *(undefined2 *)(pcVar19 + 0xb8);
  lVar18 = *(longlong *)(param_1 + 8);
  if (lVar18 == 1) {
    iVar21 = *(uint *)(param_1 + 0x2a) - 0x10c;
    if (*(uint *)(param_1 + 0x2a) < 0x10d) {
      iVar21 = 0;
    }
  }
  else if (lVar18 == 6) {
    iVar21 = 0;
    if (0x15 < (uint)(*(int *)(param_1 + 0x121) * 2)) {
      iVar21 = *(int *)(param_1 + 0x121) * 2 - 0x15;
    }
  }
  else if (lVar18 == 0) {
    iVar21 = *(int *)(param_1 + 0x136) * 2;
  }
  else {
    iVar21 = 0;
  }
  puVar15 = local_188;
  puVar22 = local_2c8;
  do {
    puVar24 = puVar22;
    puVar20 = puVar15;
    uVar2 = puVar24[1];
    uVar11 = puVar24[2];
    uVar12 = puVar24[3];
    *puVar20 = *puVar24;
    puVar20[1] = uVar2;
    uVar2 = puVar24[4];
    uVar13 = puVar24[5];
    puVar20[2] = uVar11;
    puVar20[3] = uVar12;
    uVar11 = puVar24[6];
    uVar12 = puVar24[7];
    puVar20[4] = uVar2;
    puVar20[5] = uVar13;
    uVar2 = puVar24[8];
    uVar13 = puVar24[9];
    puVar20[6] = uVar11;
    puVar20[7] = uVar12;
    uVar11 = puVar24[10];
    uVar12 = puVar24[0xb];
    puVar20[8] = uVar2;
    puVar20[9] = uVar13;
    uVar2 = puVar24[0xc];
    uVar13 = puVar24[0xd];
    puVar20[10] = uVar11;
    puVar20[0xb] = uVar12;
    uVar11 = puVar24[0xe];
    uVar12 = puVar24[0xf];
    puVar20[0xc] = uVar2;
    puVar20[0xd] = uVar13;
    puVar20[0xe] = uVar11;
    puVar20[0xf] = uVar12;
    lVar25 = lVar25 + -1;
    puVar15 = puVar20 + 0x10;
    puVar22 = puVar24 + 0x10;
  } while (lVar25 != 0);
  uVar11 = puVar24[0x11];
  uVar2 = puVar24[0x16];
  uVar3 = *(undefined4 *)(puVar24 + 0x12);
  uVar4 = *(undefined4 *)((longlong)puVar24 + 0x94);
  uVar5 = *(undefined4 *)(puVar24 + 0x13);
  uVar6 = *(undefined4 *)((longlong)puVar24 + 0x9c);
  puVar20[0x10] = puVar24[0x10];
  puVar20[0x11] = uVar11;
  uVar7 = *(undefined4 *)(puVar24 + 0x14);
  uVar8 = *(undefined4 *)((longlong)puVar24 + 0xa4);
  uVar9 = *(undefined4 *)(puVar24 + 0x15);
  uVar10 = *(undefined4 *)((longlong)puVar24 + 0xac);
  *(undefined4 *)(puVar20 + 0x12) = uVar3;
  *(undefined4 *)((longlong)puVar20 + 0x94) = uVar4;
  *(undefined4 *)(puVar20 + 0x13) = uVar5;
  *(undefined4 *)((longlong)puVar20 + 0x9c) = uVar6;
  *(undefined4 *)(puVar20 + 0x14) = uVar7;
  *(undefined4 *)((longlong)puVar20 + 0xa4) = uVar8;
  *(undefined4 *)(puVar20 + 0x15) = uVar9;
  *(undefined4 *)((longlong)puVar20 + 0xac) = uVar10;
  puVar20[0x16] = uVar2;
  *(undefined2 *)(puVar20 + 0x17) = *(undefined2 *)(puVar24 + 0x17);
  queue<implementation::queue,network_filtering::connection_notification>::
  create_element<network_filtering::connection_notification>(&local_48,iVar21,local_188);
  if (lStack_40 == 0) {
    return -0x3fffffe9;
  }
  lVar18 = *(longlong *)(lStack_40 + 0x18);
  lVar23 = lStack_40 + 0x20;
  lVar25 = 0;
  if (lVar18 == 1) {
    lVar25 = lVar23;
  }
  if (lVar25 == 0) {
    lVar25 = 0;
    if (lVar18 == 0) {
      lVar25 = lVar23;
    }
    if (lVar25 == 0) {
      lVar25 = 0;
      if (lVar18 == 6) {
        lVar25 = lVar23;
      }
      if (lVar25 == 0) goto LAB_140008de5;
      lVar18 = *(longlong *)(param_2 + 8);
      _Src = *(void **)(lVar18 + 0x10);
      if (_Src == (void *)0x0) goto LAB_140008de5;
      _Dst = (void *)(lVar25 + 0x115);
    }
    else {
      lVar18 = *(longlong *)(param_2 + 8);
      _Src = *(void **)(lVar18 + 0x10);
      if (_Src == (void *)0x0) goto LAB_140008de5;
      _Dst = (void *)(lVar25 + 0x12a);
    }
  }
  else {
    lVar18 = *(longlong *)(param_2 + 8);
    _Src = *(void **)(lVar18 + 0x10);
    if (_Src == (void *)0x0) goto LAB_140008de5;
    _Dst = (void *)(lVar25 + 0x1e);
  }
  memmove(_Dst,_Src,(ulonglong)*(uint *)(lVar18 + 0x18) * 2);
LAB_140008de5:
  lStack_2d0 = lStack_40;
  local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
  lStack_40 = 0;
  queue<implementation::queue,network_filtering::connection_notification>::push_back
            ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8),
             &local_2d8);
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x666e6477);
  }
  lVar18 = IoCsqRemoveNextIrp(psVar1,0);
  if (lVar18 != 0) {
    local_2d8 = 0;
    lStack_2d0 = 0;
    queue<implementation::queue,network_filtering::connection_notification>::pop_front
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
              );
    if (lStack_2d0 == 0) {
      IoCsqInsertIrp(psVar1,lVar18,0);
    }
    else {
      local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
      local_48 = lVar18;
      complete_irp(this,&local_48,&local_2d8);
    }
  }
  return 0;
}



===== create_element<network_filtering::connection_notification> @ 140008ee0 =====

/* public: static auto __cdecl queue<class implementation::queue,struct
   network_filtering::connection_notification>::create_element<struct
   network_filtering::connection_notification>(unsigned __int64,struct
   network_filtering::connection_notification) */

undefined4 * __cdecl
queue<implementation::queue,network_filtering::connection_notification>::
create_element<network_filtering::connection_notification>
          (undefined4 *param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  longlong lVar14;
  void *_Dst;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined4 uVar17;
  longlong lVar18;
  undefined8 *puVar19;
  undefined8 local_158 [40];
  
  lVar18 = 2;
  lVar14 = 2;
  puVar13 = local_158;
  do {
    puVar15 = puVar13;
    puVar19 = param_3;
    uVar1 = puVar19[1];
    uVar10 = puVar19[2];
    uVar11 = puVar19[3];
    *puVar15 = *puVar19;
    puVar15[1] = uVar1;
    uVar1 = puVar19[4];
    uVar12 = puVar19[5];
    puVar15[2] = uVar10;
    puVar15[3] = uVar11;
    uVar10 = puVar19[6];
    uVar11 = puVar19[7];
    puVar15[4] = uVar1;
    puVar15[5] = uVar12;
    uVar1 = puVar19[8];
    uVar12 = puVar19[9];
    puVar15[6] = uVar10;
    puVar15[7] = uVar11;
    uVar10 = puVar19[10];
    uVar11 = puVar19[0xb];
    puVar15[8] = uVar1;
    puVar15[9] = uVar12;
    uVar1 = puVar19[0xc];
    uVar12 = puVar19[0xd];
    puVar15[10] = uVar10;
    puVar15[0xb] = uVar11;
    uVar10 = puVar19[0xe];
    uVar11 = puVar19[0xf];
    puVar15[0xc] = uVar1;
    puVar15[0xd] = uVar12;
    puVar15[0xe] = uVar10;
    puVar15[0xf] = uVar11;
    lVar14 = lVar14 + -1;
    param_3 = puVar19 + 0x10;
    puVar13 = puVar15 + 0x10;
  } while (lVar14 != 0);
  uVar10 = puVar19[0x10];
  uVar11 = puVar19[0x11];
  uVar1 = puVar19[0x16];
  uVar2 = *(undefined4 *)(puVar19 + 0x12);
  uVar3 = *(undefined4 *)((longlong)puVar19 + 0x94);
  uVar4 = *(undefined4 *)(puVar19 + 0x13);
  uVar5 = *(undefined4 *)((longlong)puVar19 + 0x9c);
  *param_1 = 0xc000000d;
  uVar17 = 0;
  puVar15[0x10] = uVar10;
  puVar15[0x11] = uVar11;
  *(undefined1 *)(param_1 + 1) = 0;
  uVar6 = *(undefined4 *)(puVar19 + 0x14);
  uVar7 = *(undefined4 *)((longlong)puVar19 + 0xa4);
  uVar8 = *(undefined4 *)(puVar19 + 0x15);
  uVar9 = *(undefined4 *)((longlong)puVar19 + 0xac);
  *(undefined4 *)(puVar15 + 0x12) = uVar2;
  *(undefined4 *)((longlong)puVar15 + 0x94) = uVar3;
  *(undefined4 *)(puVar15 + 0x13) = uVar4;
  *(undefined4 *)((longlong)puVar15 + 0x9c) = uVar5;
  *(undefined4 *)(puVar15 + 0x14) = uVar6;
  *(undefined4 *)((longlong)puVar15 + 0xa4) = uVar7;
  *(undefined4 *)(puVar15 + 0x15) = uVar8;
  *(undefined4 *)((longlong)puVar15 + 0xac) = uVar9;
  puVar15[0x16] = uVar1;
  *(undefined2 *)(puVar15 + 0x17) = *(undefined2 *)(puVar19 + 0x17);
  _Dst = (void *)ExAllocatePoolWithTag(0x600,param_2 + 0x150U,0x666e6477);
  if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
    memset(_Dst,0,param_2 + 0x150U);
  }
  *(void **)(param_1 + 2) = _Dst;
  if (_Dst == (void *)0x0) {
    uVar17 = 0xc0000017;
  }
  else {
    memset(_Dst,0,0x150);
    puVar13 = (undefined8 *)(*(longlong *)(param_1 + 2) + 0x10);
    puVar19 = local_158;
    do {
      puVar16 = puVar19;
      puVar15 = puVar13;
      uVar1 = puVar16[1];
      *puVar15 = *puVar16;
      puVar15[1] = uVar1;
      uVar1 = puVar16[3];
      puVar15[2] = puVar16[2];
      puVar15[3] = uVar1;
      uVar1 = puVar16[5];
      puVar15[4] = puVar16[4];
      puVar15[5] = uVar1;
      uVar1 = puVar16[7];
      puVar15[6] = puVar16[6];
      puVar15[7] = uVar1;
      uVar1 = puVar16[9];
      puVar15[8] = puVar16[8];
      puVar15[9] = uVar1;
      uVar1 = puVar16[0xb];
      puVar15[10] = puVar16[10];
      puVar15[0xb] = uVar1;
      uVar1 = puVar16[0xd];
      puVar15[0xc] = puVar16[0xc];
      puVar15[0xd] = uVar1;
      uVar1 = puVar16[0xf];
      puVar15[0xe] = puVar16[0xe];
      puVar15[0xf] = uVar1;
      lVar18 = lVar18 + -1;
      puVar13 = puVar15 + 0x10;
      puVar19 = puVar16 + 0x10;
    } while (lVar18 != 0);
    uVar1 = puVar16[0x11];
    puVar15[0x10] = puVar16[0x10];
    puVar15[0x11] = uVar1;
    uVar1 = puVar16[0x13];
    puVar15[0x12] = puVar16[0x12];
    puVar15[0x13] = uVar1;
    uVar1 = puVar16[0x15];
    puVar15[0x14] = puVar16[0x14];
    puVar15[0x15] = uVar1;
    puVar15[0x16] = puVar16[0x16];
    *(undefined2 *)(puVar15 + 0x17) = *(undefined2 *)(puVar16 + 0x17);
  }
  *param_1 = uVar17;
  return param_1;
}



===== enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_> @ 1400090a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::enqueue<class
   <lambda_1da06d3c8846a479bc1e63eaf264472e> >(struct network_filtering::connection_notification
   const & __ptr64,class <lambda_1da06d3c8846a479bc1e63eaf264472e> const & __ptr64) __ptr64 */

long __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
enqueue<<lambda_1da06d3c8846a479bc1e63eaf264472e>_>
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this,
          connection_notification *param_1,<lambda_1da06d3c8846a479bc1e63eaf264472e> *param_2)

{
  stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *psVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  connection_notification *pcVar16;
  bool bVar17;
  longlong lVar18;
  connection_notification *pcVar19;
  undefined8 *puVar20;
  int iVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  longlong lVar24;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  longlong lStack_2d0;
  undefined8 local_2c8 [40];
  undefined8 local_188 [40];
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  psVar1 = this + 0x58;
  local_48 = IoCsqRemoveNextIrp(psVar1,0);
  if (local_48 == 0) {
    bVar17 = false;
  }
  else {
    bVar17 = complete_irp<<lambda_ff11d2d004c4581af83f1d145ca8d99c>_const&___ptr64>
                       (&local_48,param_1);
  }
  if (bVar17 == false) {
    lVar24 = 2;
    local_48 = 0;
    lStack_40 = 0;
    lVar18 = 2;
    pcVar16 = param_1;
    puVar15 = local_2c8;
    do {
      puVar22 = puVar15;
      pcVar19 = pcVar16;
      uVar2 = *(undefined8 *)(pcVar19 + 8);
      uVar11 = *(undefined8 *)(pcVar19 + 0x10);
      uVar12 = *(undefined8 *)(pcVar19 + 0x18);
      *puVar22 = *(undefined8 *)pcVar19;
      puVar22[1] = uVar2;
      uVar2 = *(undefined8 *)(pcVar19 + 0x20);
      uVar13 = *(undefined8 *)(pcVar19 + 0x28);
      puVar22[2] = uVar11;
      puVar22[3] = uVar12;
      uVar11 = *(undefined8 *)(pcVar19 + 0x30);
      uVar12 = *(undefined8 *)(pcVar19 + 0x38);
      puVar22[4] = uVar2;
      puVar22[5] = uVar13;
      uVar2 = *(undefined8 *)(pcVar19 + 0x40);
      uVar13 = *(undefined8 *)(pcVar19 + 0x48);
      puVar22[6] = uVar11;
      puVar22[7] = uVar12;
      uVar11 = *(undefined8 *)(pcVar19 + 0x50);
      uVar12 = *(undefined8 *)(pcVar19 + 0x58);
      puVar22[8] = uVar2;
      puVar22[9] = uVar13;
      uVar2 = *(undefined8 *)(pcVar19 + 0x60);
      uVar13 = *(undefined8 *)(pcVar19 + 0x68);
      puVar22[10] = uVar11;
      puVar22[0xb] = uVar12;
      uVar11 = *(undefined8 *)(pcVar19 + 0x70);
      uVar12 = *(undefined8 *)(pcVar19 + 0x78);
      puVar22[0xc] = uVar2;
      puVar22[0xd] = uVar13;
      puVar22[0xe] = uVar11;
      puVar22[0xf] = uVar12;
      lVar18 = lVar18 + -1;
      pcVar16 = pcVar19 + 0x80;
      puVar15 = puVar22 + 0x10;
    } while (lVar18 != 0);
    uVar2 = *(undefined8 *)(pcVar19 + 0xb0);
    uVar11 = *(undefined8 *)(pcVar19 + 0x88);
    uVar12 = *(undefined8 *)(pcVar19 + 0x90);
    uVar13 = *(undefined8 *)(pcVar19 + 0x98);
    puVar22[0x10] = *(undefined8 *)(pcVar19 + 0x80);
    puVar22[0x11] = uVar11;
    uVar11 = *(undefined8 *)(pcVar19 + 0xa0);
    uVar14 = *(undefined8 *)(pcVar19 + 0xa8);
    puVar22[0x12] = uVar12;
    puVar22[0x13] = uVar13;
    puVar22[0x14] = uVar11;
    puVar22[0x15] = uVar14;
    puVar22[0x16] = uVar2;
    *(undefined2 *)(puVar22 + 0x17) = *(undefined2 *)(pcVar19 + 0xb8);
    lVar18 = *(longlong *)(param_1 + 8);
    if (lVar18 == 1) {
      iVar21 = *(uint *)(param_1 + 0x2a) - 0x10c;
      if (*(uint *)(param_1 + 0x2a) < 0x10d) {
        iVar21 = 0;
      }
    }
    else if (lVar18 == 6) {
      iVar21 = 0;
      if (0x15 < (uint)(*(int *)(param_1 + 0x121) * 2)) {
        iVar21 = *(int *)(param_1 + 0x121) * 2 - 0x15;
      }
    }
    else if (lVar18 == 0) {
      iVar21 = *(int *)(param_1 + 0x136) * 2;
    }
    else {
      iVar21 = 0;
    }
    puVar15 = local_188;
    puVar22 = local_2c8;
    do {
      puVar23 = puVar22;
      puVar20 = puVar15;
      uVar2 = puVar23[1];
      uVar11 = puVar23[2];
      uVar12 = puVar23[3];
      *puVar20 = *puVar23;
      puVar20[1] = uVar2;
      uVar2 = puVar23[4];
      uVar13 = puVar23[5];
      puVar20[2] = uVar11;
      puVar20[3] = uVar12;
      uVar11 = puVar23[6];
      uVar12 = puVar23[7];
      puVar20[4] = uVar2;
      puVar20[5] = uVar13;
      uVar2 = puVar23[8];
      uVar13 = puVar23[9];
      puVar20[6] = uVar11;
      puVar20[7] = uVar12;
      uVar11 = puVar23[10];
      uVar12 = puVar23[0xb];
      puVar20[8] = uVar2;
      puVar20[9] = uVar13;
      uVar2 = puVar23[0xc];
      uVar13 = puVar23[0xd];
      puVar20[10] = uVar11;
      puVar20[0xb] = uVar12;
      uVar11 = puVar23[0xe];
      uVar12 = puVar23[0xf];
      puVar20[0xc] = uVar2;
      puVar20[0xd] = uVar13;
      puVar20[0xe] = uVar11;
      puVar20[0xf] = uVar12;
      lVar24 = lVar24 + -1;
      puVar15 = puVar20 + 0x10;
      puVar22 = puVar23 + 0x10;
    } while (lVar24 != 0);
    uVar11 = puVar23[0x11];
    uVar2 = puVar23[0x16];
    uVar3 = *(undefined4 *)(puVar23 + 0x12);
    uVar4 = *(undefined4 *)((longlong)puVar23 + 0x94);
    uVar5 = *(undefined4 *)(puVar23 + 0x13);
    uVar6 = *(undefined4 *)((longlong)puVar23 + 0x9c);
    puVar20[0x10] = puVar23[0x10];
    puVar20[0x11] = uVar11;
    uVar7 = *(undefined4 *)(puVar23 + 0x14);
    uVar8 = *(undefined4 *)((longlong)puVar23 + 0xa4);
    uVar9 = *(undefined4 *)(puVar23 + 0x15);
    uVar10 = *(undefined4 *)((longlong)puVar23 + 0xac);
    *(undefined4 *)(puVar20 + 0x12) = uVar3;
    *(undefined4 *)((longlong)puVar20 + 0x94) = uVar4;
    *(undefined4 *)(puVar20 + 0x13) = uVar5;
    *(undefined4 *)((longlong)puVar20 + 0x9c) = uVar6;
    *(undefined4 *)(puVar20 + 0x14) = uVar7;
    *(undefined4 *)((longlong)puVar20 + 0xa4) = uVar8;
    *(undefined4 *)(puVar20 + 0x15) = uVar9;
    *(undefined4 *)((longlong)puVar20 + 0xac) = uVar10;
    puVar20[0x16] = uVar2;
    *(undefined2 *)(puVar20 + 0x17) = *(undefined2 *)(puVar23 + 0x17);
    queue<implementation::queue,network_filtering::connection_notification>::
    create_element<network_filtering::connection_notification>(&local_48,iVar21,local_188);
    if (lStack_40 == 0) {
      return -0x3fffffe9;
    }
    local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
    lStack_2d0 = lStack_40;
    lStack_40 = 0;
    queue<implementation::queue,network_filtering::connection_notification>::push_back
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
               ,&local_2d8);
    if (lStack_40 != 0) {
      ExFreePoolWithTag(lStack_40,0x666e6477);
    }
    lVar18 = IoCsqRemoveNextIrp(psVar1,0);
    if (lVar18 != 0) {
      local_2d8 = 0;
      lStack_2d0 = 0;
      queue<implementation::queue,network_filtering::connection_notification>::pop_front
                ((queue<implementation::queue,network_filtering::connection_notification> *)
                 (this + 8));
      if (lStack_2d0 == 0) {
        IoCsqInsertIrp(psVar1,lVar18,0);
      }
      else {
        local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
        local_48 = lVar18;
        complete_irp(this,&local_48,&local_2d8);
      }
    }
  }
  return 0;
}



===== <lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64> @ 140009390 =====

/* private: static void * __ptr64 __cdecl
   <lambda_cfa8db44f37c8b0967490b6e38287a87>::<lambda_invoker_cdecl><struct _RTL_AVL_TABLE *
   __ptr64>(struct _RTL_AVL_TABLE * __ptr64,unsigned long) */

void * __cdecl
<lambda_cfa8db44f37c8b0967490b6e38287a87>::<lambda_invoker_cdecl><_RTL_AVL_TABLE*___ptr64>
          (_RTL_AVL_TABLE *param_1,ulong param_2)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePoolWithTag(0x600,param_2,0x666e6477);
  if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
    memset(_Dst,0,(ulonglong)param_2);
  }
  return _Dst;
}



===== enqueue<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_> @ 1400093e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::enqueue<class
   <lambda_c0181479a74cc14d1ba9a1f0223edc1b> >(struct network_filtering::connection_notification
   const & __ptr64,class <lambda_c0181479a74cc14d1ba9a1f0223edc1b> const & __ptr64) __ptr64 */

long __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
enqueue<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_>
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this,
          connection_notification *param_1,<lambda_c0181479a74cc14d1ba9a1f0223edc1b> *param_2)

{
  stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *psVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  connection_notification *pcVar16;
  bool bVar17;
  int iVar18;
  longlong lVar19;
  connection_notification *pcVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  void *pvVar23;
  longlong lVar24;
  undefined8 *puVar25;
  longlong lVar26;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  longlong lStack_2d0;
  undefined8 local_2c8 [40];
  undefined8 local_188 [40];
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  psVar1 = this + 0x58;
  local_48 = IoCsqRemoveNextIrp(psVar1,0);
  if (local_48 == 0) {
    bVar17 = false;
  }
  else {
    bVar17 = complete_irp<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_const&___ptr64>
                       (&local_48,param_1,param_2);
  }
  if (bVar17 != false) {
    return 0;
  }
  lVar26 = 2;
  local_48 = 0;
  lStack_40 = 0;
  lVar19 = 2;
  pcVar16 = param_1;
  puVar15 = local_2c8;
  do {
    puVar22 = puVar15;
    pcVar20 = pcVar16;
    uVar2 = *(undefined8 *)(pcVar20 + 8);
    uVar11 = *(undefined8 *)(pcVar20 + 0x10);
    uVar12 = *(undefined8 *)(pcVar20 + 0x18);
    *puVar22 = *(undefined8 *)pcVar20;
    puVar22[1] = uVar2;
    uVar2 = *(undefined8 *)(pcVar20 + 0x20);
    uVar13 = *(undefined8 *)(pcVar20 + 0x28);
    puVar22[2] = uVar11;
    puVar22[3] = uVar12;
    uVar11 = *(undefined8 *)(pcVar20 + 0x30);
    uVar12 = *(undefined8 *)(pcVar20 + 0x38);
    puVar22[4] = uVar2;
    puVar22[5] = uVar13;
    uVar2 = *(undefined8 *)(pcVar20 + 0x40);
    uVar13 = *(undefined8 *)(pcVar20 + 0x48);
    puVar22[6] = uVar11;
    puVar22[7] = uVar12;
    uVar11 = *(undefined8 *)(pcVar20 + 0x50);
    uVar12 = *(undefined8 *)(pcVar20 + 0x58);
    puVar22[8] = uVar2;
    puVar22[9] = uVar13;
    uVar2 = *(undefined8 *)(pcVar20 + 0x60);
    uVar13 = *(undefined8 *)(pcVar20 + 0x68);
    puVar22[10] = uVar11;
    puVar22[0xb] = uVar12;
    uVar11 = *(undefined8 *)(pcVar20 + 0x70);
    uVar12 = *(undefined8 *)(pcVar20 + 0x78);
    puVar22[0xc] = uVar2;
    puVar22[0xd] = uVar13;
    puVar22[0xe] = uVar11;
    puVar22[0xf] = uVar12;
    lVar19 = lVar19 + -1;
    pcVar16 = pcVar20 + 0x80;
    puVar15 = puVar22 + 0x10;
  } while (lVar19 != 0);
  uVar2 = *(undefined8 *)(pcVar20 + 0xb0);
  uVar11 = *(undefined8 *)(pcVar20 + 0x88);
  uVar12 = *(undefined8 *)(pcVar20 + 0x90);
  uVar13 = *(undefined8 *)(pcVar20 + 0x98);
  puVar22[0x10] = *(undefined8 *)(pcVar20 + 0x80);
  puVar22[0x11] = uVar11;
  uVar11 = *(undefined8 *)(pcVar20 + 0xa0);
  uVar14 = *(undefined8 *)(pcVar20 + 0xa8);
  puVar22[0x12] = uVar12;
  puVar22[0x13] = uVar13;
  puVar22[0x14] = uVar11;
  puVar22[0x15] = uVar14;
  puVar22[0x16] = uVar2;
  *(undefined2 *)(puVar22 + 0x17) = *(undefined2 *)(pcVar20 + 0xb8);
  lVar19 = *(longlong *)(param_1 + 8);
  if (lVar19 == 1) {
    iVar18 = *(uint *)(param_1 + 0x2a) - 0x10c;
    if (*(uint *)(param_1 + 0x2a) < 0x10d) {
      iVar18 = 0;
    }
  }
  else if (lVar19 == 6) {
    iVar18 = 0;
    if (0x15 < (uint)(*(int *)(param_1 + 0x121) * 2)) {
      iVar18 = *(int *)(param_1 + 0x121) * 2 - 0x15;
    }
  }
  else if (lVar19 == 0) {
    iVar18 = *(int *)(param_1 + 0x136) * 2;
  }
  else {
    iVar18 = 0;
  }
  puVar15 = local_188;
  puVar22 = local_2c8;
  do {
    puVar25 = puVar22;
    puVar21 = puVar15;
    uVar2 = puVar25[1];
    uVar11 = puVar25[2];
    uVar12 = puVar25[3];
    *puVar21 = *puVar25;
    puVar21[1] = uVar2;
    uVar2 = puVar25[4];
    uVar13 = puVar25[5];
    puVar21[2] = uVar11;
    puVar21[3] = uVar12;
    uVar11 = puVar25[6];
    uVar12 = puVar25[7];
    puVar21[4] = uVar2;
    puVar21[5] = uVar13;
    uVar2 = puVar25[8];
    uVar13 = puVar25[9];
    puVar21[6] = uVar11;
    puVar21[7] = uVar12;
    uVar11 = puVar25[10];
    uVar12 = puVar25[0xb];
    puVar21[8] = uVar2;
    puVar21[9] = uVar13;
    uVar2 = puVar25[0xc];
    uVar13 = puVar25[0xd];
    puVar21[10] = uVar11;
    puVar21[0xb] = uVar12;
    uVar11 = puVar25[0xe];
    uVar12 = puVar25[0xf];
    puVar21[0xc] = uVar2;
    puVar21[0xd] = uVar13;
    puVar21[0xe] = uVar11;
    puVar21[0xf] = uVar12;
    lVar26 = lVar26 + -1;
    puVar15 = puVar21 + 0x10;
    puVar22 = puVar25 + 0x10;
  } while (lVar26 != 0);
  uVar11 = puVar25[0x11];
  uVar2 = puVar25[0x16];
  uVar3 = *(undefined4 *)(puVar25 + 0x12);
  uVar4 = *(undefined4 *)((longlong)puVar25 + 0x94);
  uVar5 = *(undefined4 *)(puVar25 + 0x13);
  uVar6 = *(undefined4 *)((longlong)puVar25 + 0x9c);
  puVar21[0x10] = puVar25[0x10];
  puVar21[0x11] = uVar11;
  uVar7 = *(undefined4 *)(puVar25 + 0x14);
  uVar8 = *(undefined4 *)((longlong)puVar25 + 0xa4);
  uVar9 = *(undefined4 *)(puVar25 + 0x15);
  uVar10 = *(undefined4 *)((longlong)puVar25 + 0xac);
  *(undefined4 *)(puVar21 + 0x12) = uVar3;
  *(undefined4 *)((longlong)puVar21 + 0x94) = uVar4;
  *(undefined4 *)(puVar21 + 0x13) = uVar5;
  *(undefined4 *)((longlong)puVar21 + 0x9c) = uVar6;
  *(undefined4 *)(puVar21 + 0x14) = uVar7;
  *(undefined4 *)((longlong)puVar21 + 0xa4) = uVar8;
  *(undefined4 *)(puVar21 + 0x15) = uVar9;
  *(undefined4 *)((longlong)puVar21 + 0xac) = uVar10;
  puVar21[0x16] = uVar2;
  *(undefined2 *)(puVar21 + 0x17) = *(undefined2 *)(puVar25 + 0x17);
  queue<implementation::queue,network_filtering::connection_notification>::
  create_element<network_filtering::connection_notification>(&local_48,iVar18,local_188);
  if (lStack_40 == 0) {
    return -0x3fffffe9;
  }
  lVar26 = *(longlong *)(lStack_40 + 0x18);
  lVar19 = lStack_40 + 0x20;
  lVar24 = 0;
  if (lVar26 == 1) {
    lVar24 = lVar19;
  }
  if (lVar24 == 0) {
    lVar24 = 0;
    if (lVar26 == 0) {
      lVar24 = lVar19;
    }
    if (lVar24 == 0) {
      lVar24 = 0;
      if (lVar26 == 6) {
        lVar24 = lVar19;
      }
      lStack_2d0 = lStack_40;
      if (lVar24 == 0) goto LAB_140009641;
      pvVar23 = (void *)(lVar24 + 0x115);
    }
    else {
      pvVar23 = (void *)(lVar24 + 0x12a);
    }
  }
  else {
    pvVar23 = (void *)(lVar24 + 0x1e);
  }
  iVar18 = <lambda_c0181479a74cc14d1ba9a1f0223edc1b>::operator()(param_2,pvVar23);
  lStack_2d0 = lStack_40;
  if (iVar18 != 0) {
    if (lStack_40 != 0) {
      ExFreePoolWithTag(lStack_40,0x666e6477);
    }
    return -0x3fffffe9;
  }
LAB_140009641:
  local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
  lStack_40 = 0;
  queue<implementation::queue,network_filtering::connection_notification>::push_back
            ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8),
             &local_2d8);
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x666e6477);
  }
  lVar19 = IoCsqRemoveNextIrp(psVar1,0);
  if (lVar19 != 0) {
    local_2d8 = 0;
    lStack_2d0 = 0;
    queue<implementation::queue,network_filtering::connection_notification>::pop_front
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
              );
    if (lStack_2d0 == 0) {
      IoCsqInsertIrp(psVar1,lVar19,0);
    }
    else {
      local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
      local_48 = lVar19;
      complete_irp(this,&local_48,&local_2d8);
    }
  }
  return 0;
}



===== complete_irp<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_const&___ptr64> @ 140009748 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static bool __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp<class
   <lambda_85692b8abb5e0bd6bf541223f0c9278b> const & __ptr64>(class irp<class
   implementation::irp>,struct network_filtering::connection_notification const & __ptr64,class
   <lambda_85692b8abb5e0bd6bf541223f0c9278b> const & __ptr64) */

bool __cdecl
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp<<lambda_85692b8abb5e0bd6bf541223f0c9278b>_const&___ptr64>
          (irp<implementation::irp> *param_1,undefined8 *param_2,longlong param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  connection_notification *pcVar11;
  connection_notification *pcVar12;
  int iVar13;
  __uint64 _Var14;
  void *_Src;
  undefined8 *puVar15;
  undefined8 *puVar16;
  bool bVar17;
  uint uVar18;
  connection_notification *pcVar19;
  undefined1 auStack_1d8 [32];
  connection_notification *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined1 uStack_e4;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1d8;
  lVar7 = param_2[1];
  bVar17 = true;
  if (lVar7 == 1) {
    iVar13 = *(uint *)((longlong)param_2 + 0x2a) - 0x10c;
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      iVar13 = 0;
    }
  }
  else if (lVar7 == 6) {
    uVar18 = *(int *)((longlong)param_2 + 0x121) * 2;
    iVar13 = 0;
    if (0x15 < uVar18) {
      iVar13 = uVar18 - 0x15;
    }
  }
  else if (lVar7 == 0) {
    iVar13 = *(int *)((longlong)param_2 + 0x136) * 2;
  }
  else {
    iVar13 = 0;
  }
  uVar18 = iVar13 + 0x13a;
  puVar16 = param_2 + 2;
  local_1b8 = (connection_notification *)0x0;
  uStack_1b0 = 0;
  if (lVar7 == 1) {
    _Var14 = (__uint64)(*(uint *)((longlong)param_2 + 0x2a) - 0x10c);
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      _Var14 = 0;
    }
  }
  else if (lVar7 == 6) {
    uVar2 = *(int *)((longlong)param_2 + 0x121) * 2;
    _Var14 = 0;
    if (0x15 < uVar2) {
      _Var14 = (__uint64)(uVar2 - 0x15);
    }
  }
  else if (lVar7 == 0) {
    _Var14 = (__uint64)(uint)(*(int *)((longlong)param_2 + 0x136) * 2);
  }
  else {
    _Var14 = 0;
  }
  cVar6 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_1,_Var14,
                     (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
  pcVar19 = local_1b8;
  if (cVar6 == '\0') {
    cVar6 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                      (param_1,0,
                       (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
    if (cVar6 == '\0') {
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
    }
    else {
      local_48 = 0;
      uVar9 = KeQueryInterruptTimePrecise(&local_48);
      *(undefined8 *)local_1b8 = uVar9;
      *(undefined8 *)(local_1b8 + 8) = 2;
      *(uint *)(local_1b8 + 0x10) = uVar18;
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0x13a;
    }
    IofCompleteRequest(*(undefined8 *)param_1,0);
    bVar17 = false;
    goto LAB_140009ced;
  }
  local_48 = (ulonglong)uVar18;
  memset(local_1b8,0,(ulonglong)uVar18);
  lVar7 = param_2[1];
  puVar8 = (undefined8 *)0x0;
  if (lVar7 == 0) {
    puVar8 = puVar16;
  }
  if (puVar8 == (undefined8 *)0x0) {
    puVar8 = (undefined8 *)0x0;
    if (lVar7 == 1) {
      puVar8 = puVar16;
    }
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)0x0;
      if (lVar7 == 3) {
        puVar8 = puVar16;
      }
      if (puVar8 == (undefined8 *)0x0) {
        puVar8 = (undefined8 *)0x0;
        if (lVar7 == 4) {
          puVar8 = puVar16;
        }
        if (puVar8 == (undefined8 *)0x0) {
          puVar8 = (undefined8 *)0x0;
          if (lVar7 == 5) {
            puVar8 = puVar16;
          }
          if (puVar8 == (undefined8 *)0x0) {
            puVar8 = (undefined8 *)0x0;
            if (lVar7 == 6) {
              puVar8 = puVar16;
            }
            if (puVar8 == (undefined8 *)0x0) {
              puVar8 = (undefined8 *)0x0;
              if (lVar7 == 7) {
                puVar8 = puVar16;
              }
              if (puVar8 == (undefined8 *)0x0) {
                lVar7 = 2;
                pcVar12 = pcVar19;
                do {
                  puVar16 = param_2;
                  pcVar11 = pcVar12;
                  uVar9 = puVar16[1];
                  *(undefined8 *)pcVar11 = *puVar16;
                  *(undefined8 *)(pcVar11 + 8) = uVar9;
                  uVar9 = puVar16[3];
                  *(undefined8 *)(pcVar11 + 0x10) = puVar16[2];
                  *(undefined8 *)(pcVar11 + 0x18) = uVar9;
                  uVar9 = puVar16[5];
                  *(undefined8 *)(pcVar11 + 0x20) = puVar16[4];
                  *(undefined8 *)(pcVar11 + 0x28) = uVar9;
                  uVar9 = puVar16[7];
                  *(undefined8 *)(pcVar11 + 0x30) = puVar16[6];
                  *(undefined8 *)(pcVar11 + 0x38) = uVar9;
                  uVar9 = puVar16[9];
                  *(undefined8 *)(pcVar11 + 0x40) = puVar16[8];
                  *(undefined8 *)(pcVar11 + 0x48) = uVar9;
                  uVar9 = puVar16[0xb];
                  *(undefined8 *)(pcVar11 + 0x50) = puVar16[10];
                  *(undefined8 *)(pcVar11 + 0x58) = uVar9;
                  uVar9 = puVar16[0xd];
                  *(undefined8 *)(pcVar11 + 0x60) = puVar16[0xc];
                  *(undefined8 *)(pcVar11 + 0x68) = uVar9;
                  uVar9 = puVar16[0xf];
                  *(undefined8 *)(pcVar11 + 0x70) = puVar16[0xe];
                  *(undefined8 *)(pcVar11 + 0x78) = uVar9;
                  lVar7 = lVar7 + -1;
                  pcVar12 = pcVar11 + 0x80;
                  param_2 = puVar16 + 0x10;
                } while (lVar7 != 0);
                uVar9 = puVar16[0x11];
                *(undefined8 *)(pcVar11 + 0x80) = puVar16[0x10];
                *(undefined8 *)(pcVar11 + 0x88) = uVar9;
                uVar9 = puVar16[0x13];
                *(undefined8 *)(pcVar11 + 0x90) = puVar16[0x12];
                *(undefined8 *)(pcVar11 + 0x98) = uVar9;
                uVar9 = puVar16[0x15];
                *(undefined8 *)(pcVar11 + 0xa0) = puVar16[0x14];
                *(undefined8 *)(pcVar11 + 0xa8) = uVar9;
                *(undefined8 *)(pcVar11 + 0xb0) = puVar16[0x16];
                *(undefined2 *)(pcVar11 + 0xb8) = *(undefined2 *)(puVar16 + 0x17);
              }
              else {
                local_1b8 = (connection_notification *)*puVar16;
                uStack_1b0 = param_2[3];
                local_1a8 = param_2[4];
                uStack_1a0 = param_2[5];
                local_198 = param_2[6];
                network_filtering::connection_notification::connection_notification
                          (pcVar19,(volume_update *)&local_1b8);
              }
            }
            else {
              lVar7 = 2;
              puVar8 = &local_178;
              do {
                puVar15 = puVar16;
                puVar10 = puVar8;
                uVar9 = puVar15[1];
                uVar3 = puVar15[2];
                uVar4 = puVar15[3];
                *puVar10 = *puVar15;
                puVar10[1] = uVar9;
                uVar9 = puVar15[4];
                uVar5 = puVar15[5];
                puVar10[2] = uVar3;
                puVar10[3] = uVar4;
                uVar3 = puVar15[6];
                uVar4 = puVar15[7];
                puVar10[4] = uVar9;
                puVar10[5] = uVar5;
                uVar9 = puVar15[8];
                uVar5 = puVar15[9];
                puVar10[6] = uVar3;
                puVar10[7] = uVar4;
                uVar3 = puVar15[10];
                uVar4 = puVar15[0xb];
                puVar10[8] = uVar9;
                puVar10[9] = uVar5;
                uVar9 = puVar15[0xc];
                uVar5 = puVar15[0xd];
                puVar10[10] = uVar3;
                puVar10[0xb] = uVar4;
                uVar3 = puVar15[0xe];
                uVar4 = puVar15[0xf];
                puVar10[0xc] = uVar9;
                puVar10[0xd] = uVar5;
                puVar10[0xe] = uVar3;
                puVar10[0xf] = uVar4;
                lVar7 = lVar7 + -1;
                puVar8 = puVar10 + 0x10;
                puVar16 = puVar15 + 0x10;
              } while (lVar7 != 0);
              uVar1 = *(undefined4 *)(puVar15 + 0x12);
              uVar9 = puVar15[0x11];
              puVar10[0x10] = puVar15[0x10];
              puVar10[0x11] = uVar9;
              *(undefined4 *)(puVar10 + 0x12) = uVar1;
              *(undefined1 *)((longlong)puVar10 + 0x94) = *(undefined1 *)((longlong)puVar15 + 0x94);
              network_filtering::connection_notification::connection_notification
                        (pcVar19,(connection_aborted *)&local_178);
            }
          }
          else {
            lVar7 = 2;
            puVar8 = &local_178;
            do {
              puVar15 = puVar16;
              puVar10 = puVar8;
              uVar9 = puVar15[1];
              uVar3 = puVar15[2];
              uVar4 = puVar15[3];
              *puVar10 = *puVar15;
              puVar10[1] = uVar9;
              uVar9 = puVar15[4];
              uVar5 = puVar15[5];
              puVar10[2] = uVar3;
              puVar10[3] = uVar4;
              uVar3 = puVar15[6];
              uVar4 = puVar15[7];
              puVar10[4] = uVar9;
              puVar10[5] = uVar5;
              uVar9 = puVar15[8];
              uVar5 = puVar15[9];
              puVar10[6] = uVar3;
              puVar10[7] = uVar4;
              uVar3 = puVar15[10];
              uVar4 = puVar15[0xb];
              puVar10[8] = uVar9;
              puVar10[9] = uVar5;
              uVar9 = puVar15[0xc];
              uVar5 = puVar15[0xd];
              puVar10[10] = uVar3;
              puVar10[0xb] = uVar4;
              uVar3 = puVar15[0xe];
              uVar4 = puVar15[0xf];
              puVar10[0xc] = uVar9;
              puVar10[0xd] = uVar5;
              puVar10[0xe] = uVar3;
              puVar10[0xf] = uVar4;
              lVar7 = lVar7 + -1;
              puVar8 = puVar10 + 0x10;
              puVar16 = puVar15 + 0x10;
            } while (lVar7 != 0);
            uVar1 = *(undefined4 *)(puVar15 + 0x12);
            uVar9 = puVar15[0x11];
            puVar10[0x10] = puVar15[0x10];
            puVar10[0x11] = uVar9;
            *(undefined4 *)(puVar10 + 0x12) = uVar1;
            *(undefined1 *)((longlong)puVar10 + 0x94) = *(undefined1 *)((longlong)puVar15 + 0x94);
            network_filtering::connection_notification::connection_notification
                      (pcVar19,(auth_connect *)&local_178);
          }
        }
        else {
          local_178 = *puVar16;
          uStack_170 = param_2[3];
          local_168 = param_2[4];
          uStack_160 = param_2[5];
          local_e8 = *(undefined4 *)(param_2 + 0x14);
          local_158 = param_2[6];
          uStack_150 = param_2[7];
          local_148 = param_2[8];
          uStack_140 = param_2[9];
          local_138 = param_2[10];
          uStack_130 = param_2[0xb];
          local_128 = param_2[0xc];
          uStack_120 = param_2[0xd];
          local_118 = param_2[0xe];
          uStack_110 = param_2[0xf];
          local_f8 = param_2[0x12];
          uStack_f0 = param_2[0x13];
          local_108 = param_2[0x10];
          uStack_100 = param_2[0x11];
          uStack_e4 = *(undefined1 *)((longlong)param_2 + 0xa4);
          network_filtering::connection_notification::connection_notification
                    (pcVar19,(port_open *)&local_178);
        }
      }
      else {
        local_1b8 = (connection_notification *)*puVar16;
        uStack_1b0 = param_2[3];
        local_1a8 = param_2[4];
        uStack_1a0 = param_2[5];
        local_198 = param_2[6];
        uStack_190 = param_2[7];
        local_188 = param_2[8];
        network_filtering::connection_notification::connection_notification
                  (pcVar19,(connection_close *)&local_1b8);
      }
    }
    else {
      local_1b8 = (connection_notification *)*puVar16;
      uStack_1b0 = param_2[3];
      local_1a8 = param_2[4];
      uStack_1a0 = CONCAT26(uStack_1a0._6_2_,*(undefined6 *)(param_2 + 5));
      network_filtering::connection_notification::connection_notification
                (pcVar19,(stream_segment *)&local_1b8);
    }
  }
  else {
    lVar7 = 2;
    puVar8 = &local_178;
    do {
      puVar15 = puVar16;
      puVar10 = puVar8;
      uVar9 = puVar15[1];
      uVar3 = puVar15[2];
      uVar4 = puVar15[3];
      *puVar10 = *puVar15;
      puVar10[1] = uVar9;
      uVar9 = puVar15[4];
      uVar5 = puVar15[5];
      puVar10[2] = uVar3;
      puVar10[3] = uVar4;
      uVar3 = puVar15[6];
      uVar4 = puVar15[7];
      puVar10[4] = uVar9;
      puVar10[5] = uVar5;
      uVar9 = puVar15[8];
      uVar5 = puVar15[9];
      puVar10[6] = uVar3;
      puVar10[7] = uVar4;
      uVar3 = puVar15[10];
      uVar4 = puVar15[0xb];
      puVar10[8] = uVar9;
      puVar10[9] = uVar5;
      uVar9 = puVar15[0xc];
      uVar5 = puVar15[0xd];
      puVar10[10] = uVar3;
      puVar10[0xb] = uVar4;
      uVar3 = puVar15[0xe];
      uVar4 = puVar15[0xf];
      puVar10[0xc] = uVar9;
      puVar10[0xd] = uVar5;
      puVar10[0xe] = uVar3;
      puVar10[0xf] = uVar4;
      lVar7 = lVar7 + -1;
      puVar8 = puVar10 + 0x10;
      puVar16 = puVar15 + 0x10;
    } while (lVar7 != 0);
    uVar9 = puVar15[0x14];
    uVar3 = puVar15[0x11];
    uVar4 = puVar15[0x12];
    uVar5 = puVar15[0x13];
    puVar10[0x10] = puVar15[0x10];
    puVar10[0x11] = uVar3;
    puVar10[0x12] = uVar4;
    puVar10[0x13] = uVar5;
    puVar10[0x14] = uVar9;
    *(undefined2 *)(puVar10 + 0x15) = *(undefined2 *)(puVar15 + 0x15);
    network_filtering::connection_notification::connection_notification
              (pcVar19,(connection_information *)&local_178);
  }
  lVar7 = *(longlong *)(pcVar19 + 8);
  pcVar19 = pcVar19 + 0x10;
  pcVar12 = (connection_notification *)0x0;
  if (lVar7 == 1) {
    pcVar12 = pcVar19;
  }
  if (pcVar12 == (connection_notification *)0x0) {
    pcVar12 = (connection_notification *)0x0;
    if (lVar7 == 0) {
      pcVar12 = pcVar19;
    }
    if (pcVar12 == (connection_notification *)0x0) {
      pcVar12 = (connection_notification *)0x0;
      if (lVar7 == 6) {
        pcVar12 = pcVar19;
      }
      if (pcVar12 != (connection_notification *)0x0) {
        lVar7 = *(longlong *)(param_3 + 8);
        _Src = *(void **)(lVar7 + 0x10);
        if (_Src != (void *)0x0) {
          pcVar12 = pcVar12 + 0x115;
          goto LAB_140009c40;
        }
      }
    }
    else {
      lVar7 = *(longlong *)(param_3 + 8);
      _Src = *(void **)(lVar7 + 0x10);
      if (_Src != (void *)0x0) {
        pcVar12 = pcVar12 + 0x12a;
        goto LAB_140009c40;
      }
    }
  }
  else {
    lVar7 = *(longlong *)(param_3 + 8);
    _Src = *(void **)(lVar7 + 0x10);
    if (_Src != (void *)0x0) {
      pcVar12 = pcVar12 + 0x1e;
LAB_140009c40:
      memmove(pcVar12,_Src,(ulonglong)*(uint *)(lVar7 + 0x18) * 2);
    }
  }
  *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
  *(ulonglong *)(*(longlong *)param_1 + 0x38) = local_48;
  IofCompleteRequest(*(undefined8 *)param_1,0);
LAB_140009ced:
  *(undefined8 *)param_1 = 0;
  return bVar17;
}



===== shared_ptr_impl<std::nullptr_t,unsigned_int> @ 140009d20 =====

/* public: __cdecl shared_ptr<class
   kwstring>::shared_ptr_impl::shared_ptr_impl<std::nullptr_t,unsigned int>(std::nullptr_t &&
   __ptr64,unsigned int && __ptr64) __ptr64 */

shared_ptr_impl * __thiscall
shared_ptr<kwstring>::shared_ptr_impl::shared_ptr_impl<std::nullptr_t,unsigned_int>
          (shared_ptr_impl *this,std__nullptr_t *param_1,uint *param_2)

{
  uint uVar1;
  void *_Src;
  undefined1 auVar2 [16];
  size_t _Size;
  void *_Dst;
  undefined4 uVar3;
  
  uVar3 = 0;
  *(undefined4 *)this = 0xc000000d;
  this[4] = (shared_ptr_impl)0x0;
  uVar1 = *param_2;
  _Src = *(void **)param_1;
  *(undefined4 *)(this + 8) = 0xc000000d;
  this[0xc] = (shared_ptr_impl)0x0;
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 0x18) = uVar1;
  if (uVar1 == 0) {
    _Dst = (void *)0x0;
  }
  else {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = CONCAT44(0,uVar1);
    _Size = SUB168(ZEXT816(2) * auVar2,0);
    if (SUB168(ZEXT816(2) * auVar2,8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x600,_Size,0x666e6477);
    if (((char)ExPoolZeroingNativelySupported == '\0') && (_Dst != (void *)0x0)) {
      memset(_Dst,0,_Size);
      *(void **)(this + 0x10) = _Dst;
    }
    else {
      *(void **)(this + 0x10) = _Dst;
      if (_Dst == (void *)0x0) {
        uVar3 = 0xc0000017;
        goto LAB_140009dd9;
      }
    }
  }
  if (_Src != (void *)0x0) {
    memmove(_Dst,_Src,CONCAT44(0,uVar1) * 2);
  }
LAB_140009dd9:
  *(undefined4 *)(this + 8) = uVar3;
  *(undefined4 *)this = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 0x20) = 1;
  this[0xc] = (shared_ptr_impl)0x1;
  return this;
}



===== enqueue<<lambda_b84f72b39e47e318c302fe174996c70b>_> @ 140009e0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::enqueue<class
   <lambda_b84f72b39e47e318c302fe174996c70b> >(struct network_filtering::connection_notification
   const & __ptr64,class <lambda_b84f72b39e47e318c302fe174996c70b> const & __ptr64) __ptr64 */

long __thiscall
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
enqueue<<lambda_b84f72b39e47e318c302fe174996c70b>_>
          (stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *this,
          connection_notification *param_1,<lambda_b84f72b39e47e318c302fe174996c70b> *param_2)

{
  stream_handler<implementation::irp,implementation::queue,implementation::csqueue> *psVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  connection_notification *pcVar16;
  bool bVar17;
  longlong lVar18;
  connection_notification *pcVar19;
  undefined8 *puVar20;
  longlong lVar21;
  void *_Dst;
  int iVar22;
  undefined8 *puVar23;
  uint *puVar24;
  undefined8 *puVar25;
  longlong lVar26;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  longlong lStack_2d0;
  undefined8 local_2c8 [40];
  undefined8 local_188 [40];
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  psVar1 = this + 0x58;
  local_48 = IoCsqRemoveNextIrp(psVar1,0);
  if (local_48 == 0) {
    bVar17 = false;
  }
  else {
    bVar17 = complete_irp<<lambda_b84f72b39e47e318c302fe174996c70b>_const&___ptr64>
                       (&local_48,param_1,param_2);
  }
  if (bVar17 != false) {
    return 0;
  }
  lVar18 = 2;
  local_48 = 0;
  lStack_40 = 0;
  pcVar16 = param_1;
  puVar15 = local_2c8;
  do {
    puVar23 = puVar15;
    pcVar19 = pcVar16;
    uVar2 = *(undefined8 *)(pcVar19 + 8);
    uVar11 = *(undefined8 *)(pcVar19 + 0x10);
    uVar12 = *(undefined8 *)(pcVar19 + 0x18);
    *puVar23 = *(undefined8 *)pcVar19;
    puVar23[1] = uVar2;
    uVar2 = *(undefined8 *)(pcVar19 + 0x20);
    uVar13 = *(undefined8 *)(pcVar19 + 0x28);
    puVar23[2] = uVar11;
    puVar23[3] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x30);
    uVar12 = *(undefined8 *)(pcVar19 + 0x38);
    puVar23[4] = uVar2;
    puVar23[5] = uVar13;
    uVar2 = *(undefined8 *)(pcVar19 + 0x40);
    uVar13 = *(undefined8 *)(pcVar19 + 0x48);
    puVar23[6] = uVar11;
    puVar23[7] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x50);
    uVar12 = *(undefined8 *)(pcVar19 + 0x58);
    puVar23[8] = uVar2;
    puVar23[9] = uVar13;
    uVar2 = *(undefined8 *)(pcVar19 + 0x60);
    uVar13 = *(undefined8 *)(pcVar19 + 0x68);
    puVar23[10] = uVar11;
    puVar23[0xb] = uVar12;
    uVar11 = *(undefined8 *)(pcVar19 + 0x70);
    uVar12 = *(undefined8 *)(pcVar19 + 0x78);
    puVar23[0xc] = uVar2;
    puVar23[0xd] = uVar13;
    puVar23[0xe] = uVar11;
    puVar23[0xf] = uVar12;
    lVar18 = lVar18 + -1;
    pcVar16 = pcVar19 + 0x80;
    puVar15 = puVar23 + 0x10;
  } while (lVar18 != 0);
  uVar2 = *(undefined8 *)(pcVar19 + 0xb0);
  uVar11 = *(undefined8 *)(pcVar19 + 0x88);
  uVar12 = *(undefined8 *)(pcVar19 + 0x90);
  uVar13 = *(undefined8 *)(pcVar19 + 0x98);
  puVar23[0x10] = *(undefined8 *)(pcVar19 + 0x80);
  puVar23[0x11] = uVar11;
  uVar11 = *(undefined8 *)(pcVar19 + 0xa0);
  uVar14 = *(undefined8 *)(pcVar19 + 0xa8);
  puVar23[0x12] = uVar12;
  puVar23[0x13] = uVar13;
  puVar23[0x14] = uVar11;
  puVar23[0x15] = uVar14;
  puVar23[0x16] = uVar2;
  *(undefined2 *)(puVar23 + 0x17) = *(undefined2 *)(pcVar19 + 0xb8);
  lVar18 = *(longlong *)(param_1 + 8);
  if (lVar18 == 1) {
    iVar22 = *(uint *)(param_1 + 0x2a) - 0x10c;
    if (*(uint *)(param_1 + 0x2a) < 0x10d) {
      iVar22 = 0;
    }
  }
  else if (lVar18 == 6) {
    iVar22 = 0;
    if (0x15 < (uint)(*(int *)(param_1 + 0x121) * 2)) {
      iVar22 = *(int *)(param_1 + 0x121) * 2 - 0x15;
    }
  }
  else if (lVar18 == 0) {
    iVar22 = *(int *)(param_1 + 0x136) * 2;
  }
  else {
    iVar22 = 0;
  }
  lVar18 = 2;
  puVar15 = local_188;
  puVar23 = local_2c8;
  do {
    puVar25 = puVar23;
    puVar20 = puVar15;
    uVar2 = puVar25[1];
    uVar11 = puVar25[2];
    uVar12 = puVar25[3];
    *puVar20 = *puVar25;
    puVar20[1] = uVar2;
    uVar2 = puVar25[4];
    uVar13 = puVar25[5];
    puVar20[2] = uVar11;
    puVar20[3] = uVar12;
    uVar11 = puVar25[6];
    uVar12 = puVar25[7];
    puVar20[4] = uVar2;
    puVar20[5] = uVar13;
    uVar2 = puVar25[8];
    uVar13 = puVar25[9];
    puVar20[6] = uVar11;
    puVar20[7] = uVar12;
    uVar11 = puVar25[10];
    uVar12 = puVar25[0xb];
    puVar20[8] = uVar2;
    puVar20[9] = uVar13;
    uVar2 = puVar25[0xc];
    uVar13 = puVar25[0xd];
    puVar20[10] = uVar11;
    puVar20[0xb] = uVar12;
    uVar11 = puVar25[0xe];
    uVar12 = puVar25[0xf];
    puVar20[0xc] = uVar2;
    puVar20[0xd] = uVar13;
    puVar20[0xe] = uVar11;
    puVar20[0xf] = uVar12;
    lVar18 = lVar18 + -1;
    puVar15 = puVar20 + 0x10;
    puVar23 = puVar25 + 0x10;
  } while (lVar18 != 0);
  uVar11 = puVar25[0x11];
  uVar2 = puVar25[0x16];
  uVar3 = *(undefined4 *)(puVar25 + 0x12);
  uVar4 = *(undefined4 *)((longlong)puVar25 + 0x94);
  uVar5 = *(undefined4 *)(puVar25 + 0x13);
  uVar6 = *(undefined4 *)((longlong)puVar25 + 0x9c);
  puVar20[0x10] = puVar25[0x10];
  puVar20[0x11] = uVar11;
  uVar7 = *(undefined4 *)(puVar25 + 0x14);
  uVar8 = *(undefined4 *)((longlong)puVar25 + 0xa4);
  uVar9 = *(undefined4 *)(puVar25 + 0x15);
  uVar10 = *(undefined4 *)((longlong)puVar25 + 0xac);
  *(undefined4 *)(puVar20 + 0x12) = uVar3;
  *(undefined4 *)((longlong)puVar20 + 0x94) = uVar4;
  *(undefined4 *)(puVar20 + 0x13) = uVar5;
  *(undefined4 *)((longlong)puVar20 + 0x9c) = uVar6;
  *(undefined4 *)(puVar20 + 0x14) = uVar7;
  *(undefined4 *)((longlong)puVar20 + 0xa4) = uVar8;
  *(undefined4 *)(puVar20 + 0x15) = uVar9;
  *(undefined4 *)((longlong)puVar20 + 0xac) = uVar10;
  puVar20[0x16] = uVar2;
  *(undefined2 *)(puVar20 + 0x17) = *(undefined2 *)(puVar25 + 0x17);
  queue<implementation::queue,network_filtering::connection_notification>::
  create_element<network_filtering::connection_notification>(&local_48,iVar22,local_188);
  if (lStack_40 == 0) {
    return -0x3fffffe9;
  }
  lVar18 = *(longlong *)(lStack_40 + 0x18);
  lVar21 = lStack_40 + 0x20;
  lVar26 = 0;
  if (lVar18 == 1) {
    lVar26 = lVar21;
  }
  if (lVar26 == 0) {
    lVar26 = 0;
    if (lVar18 == 0) {
      lVar26 = lVar21;
    }
    if (lVar26 == 0) {
      lVar26 = 0;
      if (lVar18 == 6) {
        lVar26 = lVar21;
      }
      if (((lVar26 == 0) || (**(int **)(param_2 + 8) == 0)) ||
         (puVar24 = *(uint **)(**(longlong **)(param_2 + 0x10) + 0x30), puVar24 == (uint *)0x0))
      goto LAB_14000a0b2;
      _Dst = (void *)(lVar26 + 0x115);
    }
    else {
      if ((**(int **)(param_2 + 8) == 0) ||
         (puVar24 = *(uint **)(**(longlong **)(param_2 + 0x10) + 0x30), puVar24 == (uint *)0x0))
      goto LAB_14000a0b2;
      _Dst = (void *)(lVar26 + 0x12a);
    }
  }
  else {
    if ((**(int **)(param_2 + 8) == 0) ||
       (puVar24 = *(uint **)(**(longlong **)(param_2 + 0x10) + 0x30), puVar24 == (uint *)0x0))
    goto LAB_14000a0b2;
    _Dst = (void *)(lVar26 + 0x1e);
  }
  memmove(_Dst,*(void **)(puVar24 + 2),(ulonglong)*puVar24 - 2);
LAB_14000a0b2:
  lStack_2d0 = lStack_40;
  local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
  lStack_40 = 0;
  queue<implementation::queue,network_filtering::connection_notification>::push_back
            ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8),
             &local_2d8);
  if (lStack_40 != 0) {
    ExFreePoolWithTag(lStack_40,0x666e6477);
  }
  lVar18 = IoCsqRemoveNextIrp(psVar1,0);
  if (lVar18 != 0) {
    local_2d8 = 0;
    lStack_2d0 = 0;
    queue<implementation::queue,network_filtering::connection_notification>::pop_front
              ((queue<implementation::queue,network_filtering::connection_notification> *)(this + 8)
              );
    if (lStack_2d0 == 0) {
      IoCsqInsertIrp(psVar1,lVar18,0);
    }
    else {
      local_2d8 = CONCAT35(local_2d8._5_3_,0xc000000d);
      local_48 = lVar18;
      complete_irp(this,&local_48,&local_2d8);
    }
  }
  return 0;
}



===== complete_irp<<lambda_ff11d2d004c4581af83f1d145ca8d99c>_const&___ptr64> @ 14000a1ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static bool __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp<class
   <lambda_ff11d2d004c4581af83f1d145ca8d99c> const & __ptr64>(class irp<class
   implementation::irp>,struct network_filtering::connection_notification const & __ptr64,class
   <lambda_ff11d2d004c4581af83f1d145ca8d99c> const & __ptr64) */

bool __cdecl
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp<<lambda_ff11d2d004c4581af83f1d145ca8d99c>_const&___ptr64>
          (irp<implementation::irp> *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  connection_notification *this;
  char cVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  int iVar13;
  __uint64 _Var14;
  undefined8 *puVar15;
  uint uVar16;
  connection_notification *pcVar17;
  bool bVar18;
  undefined8 *puVar19;
  undefined1 auStack_1d8 [32];
  connection_notification *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined1 uStack_e4;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1d8;
  lVar9 = param_2[1];
  bVar18 = true;
  if (lVar9 == 1) {
    iVar13 = *(uint *)((longlong)param_2 + 0x2a) - 0x10c;
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      iVar13 = 0;
    }
  }
  else if (lVar9 == 6) {
    uVar16 = *(int *)((longlong)param_2 + 0x121) * 2;
    iVar13 = 0;
    if (0x15 < uVar16) {
      iVar13 = uVar16 - 0x15;
    }
  }
  else if (lVar9 == 0) {
    iVar13 = *(int *)((longlong)param_2 + 0x136) * 2;
  }
  else {
    iVar13 = 0;
  }
  uVar16 = iVar13 + 0x13a;
  puVar19 = param_2 + 2;
  local_1b8 = (connection_notification *)0x0;
  uStack_1b0 = 0;
  if (lVar9 == 1) {
    _Var14 = (__uint64)(*(uint *)((longlong)param_2 + 0x2a) - 0x10c);
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      _Var14 = 0;
    }
  }
  else if (lVar9 == 6) {
    uVar2 = *(int *)((longlong)param_2 + 0x121) * 2;
    _Var14 = 0;
    if (0x15 < uVar2) {
      _Var14 = (__uint64)(uVar2 - 0x15);
    }
  }
  else if (lVar9 == 0) {
    _Var14 = (__uint64)(uint)(*(int *)((longlong)param_2 + 0x136) * 2);
  }
  else {
    _Var14 = 0;
  }
  cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_1,_Var14,
                     (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
  this = local_1b8;
  if (cVar8 == '\0') {
    cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                      (param_1,0,
                       (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
    if (cVar8 == '\0') {
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
    }
    else {
      local_48 = 0;
      uVar11 = KeQueryInterruptTimePrecise(&local_48);
      *(undefined8 *)local_1b8 = uVar11;
      *(undefined8 *)(local_1b8 + 8) = 2;
      *(uint *)(local_1b8 + 0x10) = uVar16;
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0x13a;
    }
    IofCompleteRequest(*(undefined8 *)param_1,0);
    bVar18 = false;
  }
  else {
    memset(local_1b8,0,(ulonglong)uVar16);
    lVar9 = param_2[1];
    puVar10 = (undefined8 *)0x0;
    if (lVar9 == 0) {
      puVar10 = puVar19;
    }
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0x0;
      if (lVar9 == 1) {
        puVar10 = puVar19;
      }
      if (puVar10 == (undefined8 *)0x0) {
        puVar10 = (undefined8 *)0x0;
        if (lVar9 == 3) {
          puVar10 = puVar19;
        }
        if (puVar10 == (undefined8 *)0x0) {
          puVar10 = (undefined8 *)0x0;
          if (lVar9 == 4) {
            puVar10 = puVar19;
          }
          if (puVar10 == (undefined8 *)0x0) {
            puVar10 = (undefined8 *)0x0;
            if (lVar9 == 5) {
              puVar10 = puVar19;
            }
            if (puVar10 == (undefined8 *)0x0) {
              puVar10 = (undefined8 *)0x0;
              if (lVar9 == 6) {
                puVar10 = puVar19;
              }
              if (puVar10 == (undefined8 *)0x0) {
                puVar10 = (undefined8 *)0x0;
                if (lVar9 == 7) {
                  puVar10 = puVar19;
                }
                if (puVar10 == (undefined8 *)0x0) {
                  lVar9 = 2;
                  do {
                    puVar19 = param_2;
                    pcVar17 = this;
                    uVar11 = puVar19[1];
                    *(undefined8 *)pcVar17 = *puVar19;
                    *(undefined8 *)(pcVar17 + 8) = uVar11;
                    uVar11 = puVar19[3];
                    *(undefined8 *)(pcVar17 + 0x10) = puVar19[2];
                    *(undefined8 *)(pcVar17 + 0x18) = uVar11;
                    uVar11 = puVar19[5];
                    *(undefined8 *)(pcVar17 + 0x20) = puVar19[4];
                    *(undefined8 *)(pcVar17 + 0x28) = uVar11;
                    uVar11 = puVar19[7];
                    *(undefined8 *)(pcVar17 + 0x30) = puVar19[6];
                    *(undefined8 *)(pcVar17 + 0x38) = uVar11;
                    uVar11 = puVar19[9];
                    *(undefined8 *)(pcVar17 + 0x40) = puVar19[8];
                    *(undefined8 *)(pcVar17 + 0x48) = uVar11;
                    uVar11 = puVar19[0xb];
                    *(undefined8 *)(pcVar17 + 0x50) = puVar19[10];
                    *(undefined8 *)(pcVar17 + 0x58) = uVar11;
                    uVar11 = puVar19[0xd];
                    *(undefined8 *)(pcVar17 + 0x60) = puVar19[0xc];
                    *(undefined8 *)(pcVar17 + 0x68) = uVar11;
                    uVar11 = puVar19[0xf];
                    *(undefined8 *)(pcVar17 + 0x70) = puVar19[0xe];
                    *(undefined8 *)(pcVar17 + 0x78) = uVar11;
                    lVar9 = lVar9 + -1;
                    this = pcVar17 + 0x80;
                    param_2 = puVar19 + 0x10;
                  } while (lVar9 != 0);
                  uVar11 = puVar19[0x11];
                  *(undefined8 *)(pcVar17 + 0x80) = puVar19[0x10];
                  *(undefined8 *)(pcVar17 + 0x88) = uVar11;
                  uVar11 = puVar19[0x13];
                  *(undefined8 *)(pcVar17 + 0x90) = puVar19[0x12];
                  *(undefined8 *)(pcVar17 + 0x98) = uVar11;
                  uVar1 = *(undefined4 *)((longlong)puVar19 + 0xa4);
                  uVar3 = *(undefined4 *)(puVar19 + 0x15);
                  uVar4 = *(undefined4 *)((longlong)puVar19 + 0xac);
                  *(undefined4 *)(pcVar17 + 0xa0) = *(undefined4 *)(puVar19 + 0x14);
                  *(undefined4 *)(pcVar17 + 0xa4) = uVar1;
                  *(undefined4 *)(pcVar17 + 0xa8) = uVar3;
                  *(undefined4 *)(pcVar17 + 0xac) = uVar4;
                  *(undefined8 *)(pcVar17 + 0xb0) = puVar19[0x16];
                  *(undefined2 *)(pcVar17 + 0xb8) = *(undefined2 *)(puVar19 + 0x17);
                }
                else {
                  local_1b8 = (connection_notification *)*puVar19;
                  uStack_1b0 = param_2[3];
                  local_1a8 = param_2[4];
                  uStack_1a0 = param_2[5];
                  local_198 = param_2[6];
                  network_filtering::connection_notification::connection_notification
                            (this,(volume_update *)&local_1b8);
                }
              }
              else {
                lVar9 = 2;
                puVar10 = &local_178;
                do {
                  puVar15 = puVar19;
                  puVar12 = puVar10;
                  uVar11 = puVar15[1];
                  uVar5 = puVar15[2];
                  uVar6 = puVar15[3];
                  *puVar12 = *puVar15;
                  puVar12[1] = uVar11;
                  uVar11 = puVar15[4];
                  uVar7 = puVar15[5];
                  puVar12[2] = uVar5;
                  puVar12[3] = uVar6;
                  uVar5 = puVar15[6];
                  uVar6 = puVar15[7];
                  puVar12[4] = uVar11;
                  puVar12[5] = uVar7;
                  uVar11 = puVar15[8];
                  uVar7 = puVar15[9];
                  puVar12[6] = uVar5;
                  puVar12[7] = uVar6;
                  uVar5 = puVar15[10];
                  uVar6 = puVar15[0xb];
                  puVar12[8] = uVar11;
                  puVar12[9] = uVar7;
                  uVar11 = puVar15[0xc];
                  uVar7 = puVar15[0xd];
                  puVar12[10] = uVar5;
                  puVar12[0xb] = uVar6;
                  uVar5 = puVar15[0xe];
                  uVar6 = puVar15[0xf];
                  puVar12[0xc] = uVar11;
                  puVar12[0xd] = uVar7;
                  puVar12[0xe] = uVar5;
                  puVar12[0xf] = uVar6;
                  lVar9 = lVar9 + -1;
                  puVar10 = puVar12 + 0x10;
                  puVar19 = puVar15 + 0x10;
                } while (lVar9 != 0);
                uVar1 = *(undefined4 *)(puVar15 + 0x12);
                uVar11 = puVar15[0x11];
                puVar12[0x10] = puVar15[0x10];
                puVar12[0x11] = uVar11;
                *(undefined4 *)(puVar12 + 0x12) = uVar1;
                *(undefined1 *)((longlong)puVar12 + 0x94) =
                     *(undefined1 *)((longlong)puVar15 + 0x94);
                network_filtering::connection_notification::connection_notification
                          (this,(connection_aborted *)&local_178);
              }
            }
            else {
              lVar9 = 2;
              puVar10 = &local_178;
              do {
                puVar15 = puVar19;
                puVar12 = puVar10;
                uVar11 = puVar15[1];
                uVar5 = puVar15[2];
                uVar6 = puVar15[3];
                *puVar12 = *puVar15;
                puVar12[1] = uVar11;
                uVar11 = puVar15[4];
                uVar7 = puVar15[5];
                puVar12[2] = uVar5;
                puVar12[3] = uVar6;
                uVar5 = puVar15[6];
                uVar6 = puVar15[7];
                puVar12[4] = uVar11;
                puVar12[5] = uVar7;
                uVar11 = puVar15[8];
                uVar7 = puVar15[9];
                puVar12[6] = uVar5;
                puVar12[7] = uVar6;
                uVar5 = puVar15[10];
                uVar6 = puVar15[0xb];
                puVar12[8] = uVar11;
                puVar12[9] = uVar7;
                uVar11 = puVar15[0xc];
                uVar7 = puVar15[0xd];
                puVar12[10] = uVar5;
                puVar12[0xb] = uVar6;
                uVar5 = puVar15[0xe];
                uVar6 = puVar15[0xf];
                puVar12[0xc] = uVar11;
                puVar12[0xd] = uVar7;
                puVar12[0xe] = uVar5;
                puVar12[0xf] = uVar6;
                lVar9 = lVar9 + -1;
                puVar10 = puVar12 + 0x10;
                puVar19 = puVar15 + 0x10;
              } while (lVar9 != 0);
              uVar1 = *(undefined4 *)(puVar15 + 0x12);
              uVar11 = puVar15[0x11];
              puVar12[0x10] = puVar15[0x10];
              puVar12[0x11] = uVar11;
              *(undefined4 *)(puVar12 + 0x12) = uVar1;
              *(undefined1 *)((longlong)puVar12 + 0x94) = *(undefined1 *)((longlong)puVar15 + 0x94);
              network_filtering::connection_notification::connection_notification
                        (this,(auth_connect *)&local_178);
            }
          }
          else {
            local_178 = *puVar19;
            uStack_170 = param_2[3];
            local_168 = param_2[4];
            uStack_160 = param_2[5];
            local_e8 = *(undefined4 *)(param_2 + 0x14);
            local_158 = param_2[6];
            uStack_150 = param_2[7];
            local_148 = param_2[8];
            uStack_140 = param_2[9];
            local_138 = param_2[10];
            uStack_130 = param_2[0xb];
            local_128 = param_2[0xc];
            uStack_120 = param_2[0xd];
            local_118 = param_2[0xe];
            uStack_110 = param_2[0xf];
            local_f8 = param_2[0x12];
            uStack_f0 = param_2[0x13];
            local_108 = param_2[0x10];
            uStack_100 = param_2[0x11];
            uStack_e4 = *(undefined1 *)((longlong)param_2 + 0xa4);
            network_filtering::connection_notification::connection_notification
                      (this,(port_open *)&local_178);
          }
        }
        else {
          local_1b8 = (connection_notification *)*puVar19;
          uStack_1b0 = param_2[3];
          local_1a8 = param_2[4];
          uStack_1a0 = param_2[5];
          local_198 = param_2[6];
          uStack_190 = param_2[7];
          local_188 = param_2[8];
          network_filtering::connection_notification::connection_notification
                    (this,(connection_close *)&local_1b8);
        }
      }
      else {
        local_1b8 = (connection_notification *)*puVar19;
        uStack_1b0 = param_2[3];
        local_1a8 = param_2[4];
        uStack_1a0 = CONCAT26(uStack_1a0._6_2_,*(undefined6 *)(param_2 + 5));
        network_filtering::connection_notification::connection_notification
                  (this,(stream_segment *)&local_1b8);
      }
    }
    else {
      lVar9 = 2;
      puVar10 = &local_178;
      do {
        puVar15 = puVar19;
        puVar12 = puVar10;
        uVar11 = puVar15[1];
        uVar5 = puVar15[2];
        uVar6 = puVar15[3];
        *puVar12 = *puVar15;
        puVar12[1] = uVar11;
        uVar11 = puVar15[4];
        uVar7 = puVar15[5];
        puVar12[2] = uVar5;
        puVar12[3] = uVar6;
        uVar5 = puVar15[6];
        uVar6 = puVar15[7];
        puVar12[4] = uVar11;
        puVar12[5] = uVar7;
        uVar11 = puVar15[8];
        uVar7 = puVar15[9];
        puVar12[6] = uVar5;
        puVar12[7] = uVar6;
        uVar5 = puVar15[10];
        uVar6 = puVar15[0xb];
        puVar12[8] = uVar11;
        puVar12[9] = uVar7;
        uVar11 = puVar15[0xc];
        uVar7 = puVar15[0xd];
        puVar12[10] = uVar5;
        puVar12[0xb] = uVar6;
        uVar5 = puVar15[0xe];
        uVar6 = puVar15[0xf];
        puVar12[0xc] = uVar11;
        puVar12[0xd] = uVar7;
        puVar12[0xe] = uVar5;
        puVar12[0xf] = uVar6;
        lVar9 = lVar9 + -1;
        puVar10 = puVar12 + 0x10;
        puVar19 = puVar15 + 0x10;
      } while (lVar9 != 0);
      uVar11 = puVar15[0x14];
      uVar5 = puVar15[0x11];
      uVar6 = puVar15[0x12];
      uVar7 = puVar15[0x13];
      puVar12[0x10] = puVar15[0x10];
      puVar12[0x11] = uVar5;
      puVar12[0x12] = uVar6;
      puVar12[0x13] = uVar7;
      puVar12[0x14] = uVar11;
      *(undefined2 *)(puVar12 + 0x15) = *(undefined2 *)(puVar15 + 0x15);
      network_filtering::connection_notification::connection_notification
                (this,(connection_information *)&local_178);
    }
    *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
    *(ulonglong *)(*(longlong *)param_1 + 0x38) = (ulonglong)uVar16;
    IofCompleteRequest(*(undefined8 *)param_1,0);
  }
  *(undefined8 *)param_1 = 0;
  return bVar18;
}



===== <lambda_invoker_cdecl> @ 14000a700 =====

/* private: static __cdecl <lambda_5593ee50ecb8e35d6e56e15f73f8f802>::<lambda_invoker_cdecl>(struct
   _IO_CSQ * __ptr64,struct _IRP * __ptr64) */

void __cdecl
<lambda_5593ee50ecb8e35d6e56e15f73f8f802>::<lambda_invoker_cdecl>(_IO_CSQ *param_1,_IRP *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  _IO_CSQ *p_Var3;
  _IRP *p_Var4;
  
  plVar2 = *(longlong **)(param_1 + -0x10);
  p_Var3 = param_1 + -0x18;
  p_Var4 = param_2 + 0xa8;
  if ((_IO_CSQ *)*plVar2 != p_Var3) {
    p_Var3 = (_IO_CSQ *)0x3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *(_IO_CSQ **)p_Var4 = p_Var3;
  *(longlong **)(p_Var4 + 8) = plVar2;
  *plVar2 = (longlong)p_Var4;
  *(_IRP **)(p_Var3 + 8) = p_Var4;
  return;
}



===== <lambda_invoker_cdecl> @ 14000a730 =====

/* private: static __cdecl <lambda_f22a1144f06c5e87ab6e9654c303aa32>::<lambda_invoker_cdecl>(struct
   _IO_CSQ * __ptr64,struct _IRP * __ptr64) */

void __cdecl
<lambda_f22a1144f06c5e87ab6e9654c303aa32>::<lambda_invoker_cdecl>(_IO_CSQ *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  _IRP *p_Var4;
  
  p_Var4 = param_2 + 0xa8;
  lVar1 = *(longlong *)p_Var4;
  if ((*(_IRP **)(lVar1 + 8) == p_Var4) &&
     (plVar2 = *(longlong **)(param_2 + 0xb0), (_IRP *)*plVar2 == p_Var4)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== <lambda_invoker_cdecl> @ 14000a760 =====

/* private: static struct _IRP * __ptr64 __cdecl
   <lambda_8d1e6fa018bd9e8302854441ecddfb77>::<lambda_invoker_cdecl>(struct _IO_CSQ * __ptr64,struct
   _IRP * __ptr64,void * __ptr64) */

_IRP * __cdecl
<lambda_8d1e6fa018bd9e8302854441ecddfb77>::<lambda_invoker_cdecl>
          (_IO_CSQ *param_1,_IRP *param_2,void *param_3)

{
  _IRP *p_Var1;
  _IO_CSQ *p_Var2;
  
  if (param_2 == (_IRP *)0x0) {
    p_Var2 = *(_IO_CSQ **)(param_1 + -0x18);
  }
  else {
    p_Var2 = *(_IO_CSQ **)(param_2 + 0xa8);
  }
  p_Var1 = (_IRP *)(p_Var2 + -0xa8);
  if (p_Var2 == param_1 + -0x18) {
    p_Var1 = (_IRP *)0x0;
  }
  return p_Var1;
}



===== <lambda_invoker_cdecl> @ 14000a790 =====

/* private: static __cdecl <lambda_b2738bab5f9d8fd10492fe3d6529319a>::<lambda_invoker_cdecl>(struct
   _IO_CSQ * __ptr64,unsigned char * __ptr64) */

void __cdecl
<lambda_b2738bab5f9d8fd10492fe3d6529319a>::<lambda_invoker_cdecl>(_IO_CSQ *param_1,uchar *param_2)

{
  uchar uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + -8);
  *param_2 = uVar1;
  return;
}



===== <lambda_invoker_cdecl> @ 14000a7c0 =====

/* private: static __cdecl <lambda_1fe26a0b29263d33bf0f2ea388257860>::<lambda_invoker_cdecl>(struct
   _IO_CSQ * __ptr64,unsigned char) */

void __cdecl
<lambda_1fe26a0b29263d33bf0f2ea388257860>::<lambda_invoker_cdecl>(_IO_CSQ *param_1,uchar param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00014000a7c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeReleaseSpinLock(param_1 + -8);
  return;
}



===== <lambda_invoker_cdecl> @ 14000a7d0 =====

/* private: static __cdecl <lambda_40d900456e4918bba8049c046de406bc>::<lambda_invoker_cdecl>(struct
   _IO_CSQ * __ptr64,struct _IRP * __ptr64) */

void __cdecl
<lambda_40d900456e4918bba8049c046de406bc>::<lambda_invoker_cdecl>(_IO_CSQ *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  *(undefined8 *)(param_2 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x00014000a7e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCompleteRequest(param_2,0);
  return;
}



===== push_back @ 14000a7f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl queue<class implementation::queue,struct
   network_filtering::connection_notification>::push_back(class queue_element<struct
   network_filtering::connection_notification,class implementation::queue<struct
   network_filtering::connection_notification>::element_impl>) __ptr64 */

void __thiscall
queue<implementation::queue,network_filtering::connection_notification>::push_back
          (queue<implementation::queue,network_filtering::connection_notification> *this,
          longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  KeAcquireInStackQueuedSpinLock(this,local_28);
  puVar6 = auStack_48;
  puVar7 = *(undefined8 **)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  LOCK();
  *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  UNLOCK();
  lVar1 = puVar7[3];
  if (lVar1 == 1) {
    uVar5 = (ulonglong)(*(uint *)((longlong)puVar7 + 0x3a) - 0x10c);
    if (*(uint *)((longlong)puVar7 + 0x3a) < 0x10d) {
      uVar5 = 0;
    }
  }
  else if (lVar1 == 6) {
    uVar3 = *(int *)((longlong)puVar7 + 0x131) * 2;
    uVar5 = 0;
    if (0x15 < uVar3) {
      uVar5 = (ulonglong)(uVar3 - 0x15);
    }
  }
  else if (lVar1 == 0) {
    uVar5 = (ulonglong)(uint)(*(int *)((longlong)puVar7 + 0x146) * 2);
  }
  else {
    uVar5 = 0;
  }
  *(ulonglong *)(this + 0x20) = *(longlong *)(this + 0x20) + 0x10 + uVar5;
  plVar4 = *(longlong **)(this + 0x10);
  if ((queue<implementation::queue,network_filtering::connection_notification> *)*plVar4 != this + 8
     ) {
    pcVar2 = (code *)swi(0x29);
    plVar4 = (longlong *)(*pcVar2)(3);
    puVar6 = auStack_40;
  }
  *puVar7 = this + 8;
  puVar7[1] = plVar4;
  *plVar4 = (longlong)puVar7;
  *(undefined8 **)(this + 0x10) = puVar7;
  *(undefined8 *)(puVar6 + -8) = 0x14000a8bf;
  KeReleaseInStackQueuedSpinLock(puVar6 + 0x20);
  lVar1 = *(longlong *)(param_2 + 8);
  if (lVar1 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x14000a8d9;
    ExFreePoolWithTag(lVar1,0x666e6477);
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000a8eb;
  return;
}



===== complete_irp<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_const&___ptr64> @ 14000a8fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static bool __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp<class
   <lambda_c0181479a74cc14d1ba9a1f0223edc1b> const & __ptr64>(class irp<class
   implementation::irp>,struct network_filtering::connection_notification const & __ptr64,class
   <lambda_c0181479a74cc14d1ba9a1f0223edc1b> const & __ptr64) */

bool __cdecl
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp<<lambda_c0181479a74cc14d1ba9a1f0223edc1b>_const&___ptr64>
          (irp<implementation::irp> *param_1,undefined8 *param_2,
          <lambda_c0181479a74cc14d1ba9a1f0223edc1b> *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char cVar8;
  bool bVar9;
  int iVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  connection_notification *pcVar15;
  __uint64 _Var16;
  connection_notification *pcVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  uint uVar20;
  connection_notification *pcVar21;
  undefined1 auStack_1d8 [32];
  connection_notification *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined1 uStack_e4;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1d8;
  bVar9 = true;
  lVar11 = param_2[1];
  if (lVar11 == 1) {
    iVar10 = *(uint *)((longlong)param_2 + 0x2a) - 0x10c;
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      iVar10 = 0;
    }
  }
  else if (lVar11 == 6) {
    uVar20 = *(int *)((longlong)param_2 + 0x121) * 2;
    iVar10 = 0;
    if (0x15 < uVar20) {
      iVar10 = uVar20 - 0x15;
    }
  }
  else if (lVar11 == 0) {
    iVar10 = *(int *)((longlong)param_2 + 0x136) * 2;
  }
  else {
    iVar10 = 0;
  }
  uVar20 = iVar10 + 0x13a;
  puVar19 = param_2 + 2;
  local_1b8 = (connection_notification *)0x0;
  uStack_1b0 = 0;
  if (lVar11 == 1) {
    _Var16 = (__uint64)(*(uint *)((longlong)param_2 + 0x2a) - 0x10c);
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      _Var16 = 0;
    }
  }
  else if (lVar11 == 6) {
    uVar2 = *(int *)((longlong)param_2 + 0x121) * 2;
    _Var16 = 0;
    if (0x15 < uVar2) {
      _Var16 = (__uint64)(uVar2 - 0x15);
    }
  }
  else if (lVar11 == 0) {
    _Var16 = (__uint64)(uint)(*(int *)((longlong)param_2 + 0x136) * 2);
  }
  else {
    _Var16 = 0;
  }
  cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_1,_Var16,
                     (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
  pcVar21 = local_1b8;
  if (cVar8 == '\0') {
    cVar8 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                      (param_1,0,
                       (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
    if (cVar8 == '\0') {
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
    }
    else {
      local_48 = 0;
      uVar13 = KeQueryInterruptTimePrecise(&local_48);
      *(undefined8 *)local_1b8 = uVar13;
      *(undefined8 *)(local_1b8 + 8) = 2;
      *(uint *)(local_1b8 + 0x10) = uVar20;
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0x13a;
    }
    IofCompleteRequest(*(undefined8 *)param_1,0);
    bVar9 = false;
    goto LAB_14000aec1;
  }
  local_48 = (ulonglong)uVar20;
  memset(local_1b8,0,(ulonglong)uVar20);
  lVar11 = param_2[1];
  puVar12 = (undefined8 *)0x0;
  if (lVar11 == 0) {
    puVar12 = puVar19;
  }
  if (puVar12 == (undefined8 *)0x0) {
    puVar12 = (undefined8 *)0x0;
    if (lVar11 == 1) {
      puVar12 = puVar19;
    }
    if (puVar12 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0x0;
      if (lVar11 == 3) {
        puVar12 = puVar19;
      }
      if (puVar12 == (undefined8 *)0x0) {
        puVar12 = (undefined8 *)0x0;
        if (lVar11 == 4) {
          puVar12 = puVar19;
        }
        if (puVar12 == (undefined8 *)0x0) {
          puVar12 = (undefined8 *)0x0;
          if (lVar11 == 5) {
            puVar12 = puVar19;
          }
          if (puVar12 == (undefined8 *)0x0) {
            puVar12 = (undefined8 *)0x0;
            if (lVar11 == 6) {
              puVar12 = puVar19;
            }
            if (puVar12 == (undefined8 *)0x0) {
              puVar12 = (undefined8 *)0x0;
              if (lVar11 == 7) {
                puVar12 = puVar19;
              }
              if (puVar12 == (undefined8 *)0x0) {
                lVar11 = 2;
                pcVar17 = pcVar21;
                do {
                  puVar19 = param_2;
                  pcVar15 = pcVar17;
                  uVar13 = puVar19[1];
                  *(undefined8 *)pcVar15 = *puVar19;
                  *(undefined8 *)(pcVar15 + 8) = uVar13;
                  uVar13 = puVar19[3];
                  *(undefined8 *)(pcVar15 + 0x10) = puVar19[2];
                  *(undefined8 *)(pcVar15 + 0x18) = uVar13;
                  uVar13 = puVar19[5];
                  *(undefined8 *)(pcVar15 + 0x20) = puVar19[4];
                  *(undefined8 *)(pcVar15 + 0x28) = uVar13;
                  uVar13 = puVar19[7];
                  *(undefined8 *)(pcVar15 + 0x30) = puVar19[6];
                  *(undefined8 *)(pcVar15 + 0x38) = uVar13;
                  uVar13 = puVar19[9];
                  *(undefined8 *)(pcVar15 + 0x40) = puVar19[8];
                  *(undefined8 *)(pcVar15 + 0x48) = uVar13;
                  uVar13 = puVar19[0xb];
                  *(undefined8 *)(pcVar15 + 0x50) = puVar19[10];
                  *(undefined8 *)(pcVar15 + 0x58) = uVar13;
                  uVar13 = puVar19[0xd];
                  *(undefined8 *)(pcVar15 + 0x60) = puVar19[0xc];
                  *(undefined8 *)(pcVar15 + 0x68) = uVar13;
                  uVar13 = puVar19[0xf];
                  *(undefined8 *)(pcVar15 + 0x70) = puVar19[0xe];
                  *(undefined8 *)(pcVar15 + 0x78) = uVar13;
                  lVar11 = lVar11 + -1;
                  pcVar17 = pcVar15 + 0x80;
                  param_2 = puVar19 + 0x10;
                } while (lVar11 != 0);
                uVar13 = puVar19[0x11];
                *(undefined8 *)(pcVar15 + 0x80) = puVar19[0x10];
                *(undefined8 *)(pcVar15 + 0x88) = uVar13;
                uVar13 = puVar19[0x13];
                *(undefined8 *)(pcVar15 + 0x90) = puVar19[0x12];
                *(undefined8 *)(pcVar15 + 0x98) = uVar13;
                uVar1 = *(undefined4 *)((longlong)puVar19 + 0xa4);
                uVar3 = *(undefined4 *)(puVar19 + 0x15);
                uVar4 = *(undefined4 *)((longlong)puVar19 + 0xac);
                *(undefined4 *)(pcVar15 + 0xa0) = *(undefined4 *)(puVar19 + 0x14);
                *(undefined4 *)(pcVar15 + 0xa4) = uVar1;
                *(undefined4 *)(pcVar15 + 0xa8) = uVar3;
                *(undefined4 *)(pcVar15 + 0xac) = uVar4;
                *(undefined8 *)(pcVar15 + 0xb0) = puVar19[0x16];
                *(undefined2 *)(pcVar15 + 0xb8) = *(undefined2 *)(puVar19 + 0x17);
              }
              else {
                local_1b8 = (connection_notification *)*puVar19;
                uStack_1b0 = param_2[3];
                local_1a8 = param_2[4];
                uStack_1a0 = param_2[5];
                local_198 = param_2[6];
                network_filtering::connection_notification::connection_notification
                          (pcVar21,(volume_update *)&local_1b8);
              }
            }
            else {
              lVar11 = 2;
              puVar12 = &local_178;
              do {
                puVar18 = puVar19;
                puVar14 = puVar12;
                uVar13 = puVar18[1];
                uVar5 = puVar18[2];
                uVar6 = puVar18[3];
                *puVar14 = *puVar18;
                puVar14[1] = uVar13;
                uVar13 = puVar18[4];
                uVar7 = puVar18[5];
                puVar14[2] = uVar5;
                puVar14[3] = uVar6;
                uVar5 = puVar18[6];
                uVar6 = puVar18[7];
                puVar14[4] = uVar13;
                puVar14[5] = uVar7;
                uVar13 = puVar18[8];
                uVar7 = puVar18[9];
                puVar14[6] = uVar5;
                puVar14[7] = uVar6;
                uVar5 = puVar18[10];
                uVar6 = puVar18[0xb];
                puVar14[8] = uVar13;
                puVar14[9] = uVar7;
                uVar13 = puVar18[0xc];
                uVar7 = puVar18[0xd];
                puVar14[10] = uVar5;
                puVar14[0xb] = uVar6;
                uVar5 = puVar18[0xe];
                uVar6 = puVar18[0xf];
                puVar14[0xc] = uVar13;
                puVar14[0xd] = uVar7;
                puVar14[0xe] = uVar5;
                puVar14[0xf] = uVar6;
                lVar11 = lVar11 + -1;
                puVar12 = puVar14 + 0x10;
                puVar19 = puVar18 + 0x10;
              } while (lVar11 != 0);
              uVar1 = *(undefined4 *)(puVar18 + 0x12);
              uVar13 = puVar18[0x11];
              puVar14[0x10] = puVar18[0x10];
              puVar14[0x11] = uVar13;
              *(undefined4 *)(puVar14 + 0x12) = uVar1;
              *(undefined1 *)((longlong)puVar14 + 0x94) = *(undefined1 *)((longlong)puVar18 + 0x94);
              network_filtering::connection_notification::connection_notification
                        (pcVar21,(connection_aborted *)&local_178);
            }
          }
          else {
            lVar11 = 2;
            puVar12 = &local_178;
            do {
              puVar18 = puVar19;
              puVar14 = puVar12;
              uVar13 = puVar18[1];
              uVar5 = puVar18[2];
              uVar6 = puVar18[3];
              *puVar14 = *puVar18;
              puVar14[1] = uVar13;
              uVar13 = puVar18[4];
              uVar7 = puVar18[5];
              puVar14[2] = uVar5;
              puVar14[3] = uVar6;
              uVar5 = puVar18[6];
              uVar6 = puVar18[7];
              puVar14[4] = uVar13;
              puVar14[5] = uVar7;
              uVar13 = puVar18[8];
              uVar7 = puVar18[9];
              puVar14[6] = uVar5;
              puVar14[7] = uVar6;
              uVar5 = puVar18[10];
              uVar6 = puVar18[0xb];
              puVar14[8] = uVar13;
              puVar14[9] = uVar7;
              uVar13 = puVar18[0xc];
              uVar7 = puVar18[0xd];
              puVar14[10] = uVar5;
              puVar14[0xb] = uVar6;
              uVar5 = puVar18[0xe];
              uVar6 = puVar18[0xf];
              puVar14[0xc] = uVar13;
              puVar14[0xd] = uVar7;
              puVar14[0xe] = uVar5;
              puVar14[0xf] = uVar6;
              lVar11 = lVar11 + -1;
              puVar12 = puVar14 + 0x10;
              puVar19 = puVar18 + 0x10;
            } while (lVar11 != 0);
            uVar1 = *(undefined4 *)(puVar18 + 0x12);
            uVar13 = puVar18[0x11];
            puVar14[0x10] = puVar18[0x10];
            puVar14[0x11] = uVar13;
            *(undefined4 *)(puVar14 + 0x12) = uVar1;
            *(undefined1 *)((longlong)puVar14 + 0x94) = *(undefined1 *)((longlong)puVar18 + 0x94);
            network_filtering::connection_notification::connection_notification
                      (pcVar21,(auth_connect *)&local_178);
          }
        }
        else {
          local_178 = *puVar19;
          uStack_170 = param_2[3];
          local_168 = param_2[4];
          uStack_160 = param_2[5];
          local_e8 = *(undefined4 *)(param_2 + 0x14);
          local_158 = param_2[6];
          uStack_150 = param_2[7];
          local_148 = param_2[8];
          uStack_140 = param_2[9];
          local_138 = param_2[10];
          uStack_130 = param_2[0xb];
          local_128 = param_2[0xc];
          uStack_120 = param_2[0xd];
          local_118 = param_2[0xe];
          uStack_110 = param_2[0xf];
          local_f8 = param_2[0x12];
          uStack_f0 = param_2[0x13];
          local_108 = param_2[0x10];
          uStack_100 = param_2[0x11];
          uStack_e4 = *(undefined1 *)((longlong)param_2 + 0xa4);
          network_filtering::connection_notification::connection_notification
                    (pcVar21,(port_open *)&local_178);
        }
      }
      else {
        local_1b8 = (connection_notification *)*puVar19;
        uStack_1b0 = param_2[3];
        local_1a8 = param_2[4];
        uStack_1a0 = param_2[5];
        local_198 = param_2[6];
        uStack_190 = param_2[7];
        local_188 = param_2[8];
        network_filtering::connection_notification::connection_notification
                  (pcVar21,(connection_close *)&local_1b8);
      }
    }
    else {
      local_1b8 = (connection_notification *)*puVar19;
      uStack_1b0 = param_2[3];
      local_1a8 = param_2[4];
      uStack_1a0 = CONCAT26(uStack_1a0._6_2_,*(undefined6 *)(param_2 + 5));
      network_filtering::connection_notification::connection_notification
                (pcVar21,(stream_segment *)&local_1b8);
    }
  }
  else {
    lVar11 = 2;
    puVar12 = &local_178;
    do {
      puVar18 = puVar19;
      puVar14 = puVar12;
      uVar13 = puVar18[1];
      uVar5 = puVar18[2];
      uVar6 = puVar18[3];
      *puVar14 = *puVar18;
      puVar14[1] = uVar13;
      uVar13 = puVar18[4];
      uVar7 = puVar18[5];
      puVar14[2] = uVar5;
      puVar14[3] = uVar6;
      uVar5 = puVar18[6];
      uVar6 = puVar18[7];
      puVar14[4] = uVar13;
      puVar14[5] = uVar7;
      uVar13 = puVar18[8];
      uVar7 = puVar18[9];
      puVar14[6] = uVar5;
      puVar14[7] = uVar6;
      uVar5 = puVar18[10];
      uVar6 = puVar18[0xb];
      puVar14[8] = uVar13;
      puVar14[9] = uVar7;
      uVar13 = puVar18[0xc];
      uVar7 = puVar18[0xd];
      puVar14[10] = uVar5;
      puVar14[0xb] = uVar6;
      uVar5 = puVar18[0xe];
      uVar6 = puVar18[0xf];
      puVar14[0xc] = uVar13;
      puVar14[0xd] = uVar7;
      puVar14[0xe] = uVar5;
      puVar14[0xf] = uVar6;
      lVar11 = lVar11 + -1;
      puVar12 = puVar14 + 0x10;
      puVar19 = puVar18 + 0x10;
    } while (lVar11 != 0);
    uVar13 = puVar18[0x14];
    uVar5 = puVar18[0x11];
    uVar6 = puVar18[0x12];
    uVar7 = puVar18[0x13];
    puVar14[0x10] = puVar18[0x10];
    puVar14[0x11] = uVar5;
    puVar14[0x12] = uVar6;
    puVar14[0x13] = uVar7;
    puVar14[0x14] = uVar13;
    *(undefined2 *)(puVar14 + 0x15) = *(undefined2 *)(puVar18 + 0x15);
    network_filtering::connection_notification::connection_notification
              (pcVar21,(connection_information *)&local_178);
  }
  lVar11 = *(longlong *)(pcVar21 + 8);
  pcVar21 = pcVar21 + 0x10;
  pcVar17 = (connection_notification *)0x0;
  if (lVar11 == 1) {
    pcVar17 = pcVar21;
  }
  if (pcVar17 == (connection_notification *)0x0) {
    pcVar17 = (connection_notification *)0x0;
    if (lVar11 == 0) {
      pcVar17 = pcVar21;
    }
    if (pcVar17 != (connection_notification *)0x0) {
      pcVar17 = pcVar17 + 0x12a;
      goto LAB_14000addc;
    }
    pcVar17 = (connection_notification *)0x0;
    if (lVar11 == 6) {
      pcVar17 = pcVar21;
    }
    if (pcVar17 != (connection_notification *)0x0) {
      pcVar17 = pcVar17 + 0x115;
      goto LAB_14000addc;
    }
  }
  else {
    pcVar17 = pcVar17 + 0x1e;
LAB_14000addc:
    iVar10 = <lambda_c0181479a74cc14d1ba9a1f0223edc1b>::operator()(param_3,pcVar17);
    if (iVar10 != 0) {
      LOG_WARNING(L"Failed to write stream data into IRP");
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
      IofCompleteRequest(*(undefined8 *)param_1,0);
      bVar9 = false;
      goto LAB_14000aec1;
    }
  }
  *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
  *(ulonglong *)(*(longlong *)param_1 + 0x38) = local_48;
  IofCompleteRequest(*(undefined8 *)param_1,0);
LAB_14000aec1:
  *(undefined8 *)param_1 = 0;
  return bVar9;
}



===== complete_irp<<lambda_b84f72b39e47e318c302fe174996c70b>_const&___ptr64> @ 14000aef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static bool __cdecl implementation::stream_handler<class implementation::irp,class
   implementation::queue,class implementation::csqueue>::complete_irp<class
   <lambda_b84f72b39e47e318c302fe174996c70b> const & __ptr64>(class irp<class
   implementation::irp>,struct network_filtering::connection_notification const & __ptr64,class
   <lambda_b84f72b39e47e318c302fe174996c70b> const & __ptr64) */

bool __cdecl
implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>::
complete_irp<<lambda_b84f72b39e47e318c302fe174996c70b>_const&___ptr64>
          (irp<implementation::irp> *param_1,undefined8 *param_2,longlong param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  bool bVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  connection_notification *pcVar11;
  connection_notification *pcVar12;
  int iVar13;
  __uint64 _Var14;
  longlong lVar15;
  uint *puVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  uint uVar19;
  connection_notification *pcVar20;
  undefined1 auStack_1d8 [32];
  connection_notification *local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined1 uStack_e4;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1d8;
  lVar15 = param_2[1];
  if (lVar15 == 1) {
    iVar13 = *(uint *)((longlong)param_2 + 0x2a) - 0x10c;
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      iVar13 = 0;
    }
  }
  else if (lVar15 == 6) {
    uVar19 = *(int *)((longlong)param_2 + 0x121) * 2;
    iVar13 = 0;
    if (0x15 < uVar19) {
      iVar13 = uVar19 - 0x15;
    }
  }
  else if (lVar15 == 0) {
    iVar13 = *(int *)((longlong)param_2 + 0x136) * 2;
  }
  else {
    iVar13 = 0;
  }
  uVar19 = iVar13 + 0x13a;
  puVar18 = param_2 + 2;
  local_1b8 = (connection_notification *)0x0;
  uStack_1b0 = 0;
  if (lVar15 == 1) {
    _Var14 = (__uint64)(*(uint *)((longlong)param_2 + 0x2a) - 0x10c);
    if (*(uint *)((longlong)param_2 + 0x2a) < 0x10d) {
      _Var14 = 0;
    }
  }
  else if (lVar15 == 6) {
    uVar2 = *(int *)((longlong)param_2 + 0x121) * 2;
    _Var14 = 0;
    if (0x15 < uVar2) {
      _Var14 = (__uint64)(uVar2 - 0x15);
    }
  }
  else if (lVar15 == 0) {
    _Var14 = (__uint64)(uint)(*(int *)((longlong)param_2 + 0x136) * 2);
  }
  else {
    _Var14 = 0;
  }
  cVar6 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                    (param_1,_Var14,
                     (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
  pcVar20 = local_1b8;
  if (cVar6 == '\0') {
    cVar6 = irp<implementation::irp>::output_buffer<network_filtering::connection_notification>
                      (param_1,0,
                       (irp_buffer<network_filtering::connection_notification> *)&local_1b8);
    if (cVar6 == '\0') {
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc0000023;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
    }
    else {
      local_48 = 0;
      uVar9 = KeQueryInterruptTimePrecise(&local_48);
      *(undefined8 *)local_1b8 = uVar9;
      *(undefined8 *)(local_1b8 + 8) = 2;
      *(uint *)(local_1b8 + 0x10) = uVar19;
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
      *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0x13a;
    }
    IofCompleteRequest(*(undefined8 *)param_1,0);
    bVar7 = false;
    goto LAB_14000b4cf;
  }
  local_48 = (ulonglong)uVar19;
  memset(local_1b8,0,(ulonglong)uVar19);
  lVar15 = param_2[1];
  puVar8 = (undefined8 *)0x0;
  if (lVar15 == 0) {
    puVar8 = puVar18;
  }
  if (puVar8 == (undefined8 *)0x0) {
    puVar8 = (undefined8 *)0x0;
    if (lVar15 == 1) {
      puVar8 = puVar18;
    }
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)0x0;
      if (lVar15 == 3) {
        puVar8 = puVar18;
      }
      if (puVar8 == (undefined8 *)0x0) {
        puVar8 = (undefined8 *)0x0;
        if (lVar15 == 4) {
          puVar8 = puVar18;
        }
        if (puVar8 == (undefined8 *)0x0) {
          puVar8 = (undefined8 *)0x0;
          if (lVar15 == 5) {
            puVar8 = puVar18;
          }
          if (puVar8 == (undefined8 *)0x0) {
            puVar8 = (undefined8 *)0x0;
            if (lVar15 == 6) {
              puVar8 = puVar18;
            }
            if (puVar8 == (undefined8 *)0x0) {
              puVar8 = (undefined8 *)0x0;
              if (lVar15 == 7) {
                puVar8 = puVar18;
              }
              if (puVar8 == (undefined8 *)0x0) {
                lVar15 = 2;
                pcVar12 = pcVar20;
                do {
                  puVar18 = param_2;
                  pcVar11 = pcVar12;
                  uVar9 = puVar18[1];
                  *(undefined8 *)pcVar11 = *puVar18;
                  *(undefined8 *)(pcVar11 + 8) = uVar9;
                  uVar9 = puVar18[3];
                  *(undefined8 *)(pcVar11 + 0x10) = puVar18[2];
                  *(undefined8 *)(pcVar11 + 0x18) = uVar9;
                  uVar9 = puVar18[5];
                  *(undefined8 *)(pcVar11 + 0x20) = puVar18[4];
                  *(undefined8 *)(pcVar11 + 0x28) = uVar9;
                  uVar9 = puVar18[7];
                  *(undefined8 *)(pcVar11 + 0x30) = puVar18[6];
                  *(undefined8 *)(pcVar11 + 0x38) = uVar9;
                  uVar9 = puVar18[9];
                  *(undefined8 *)(pcVar11 + 0x40) = puVar18[8];
                  *(undefined8 *)(pcVar11 + 0x48) = uVar9;
                  uVar9 = puVar18[0xb];
                  *(undefined8 *)(pcVar11 + 0x50) = puVar18[10];
                  *(undefined8 *)(pcVar11 + 0x58) = uVar9;
                  uVar9 = puVar18[0xd];
                  *(undefined8 *)(pcVar11 + 0x60) = puVar18[0xc];
                  *(undefined8 *)(pcVar11 + 0x68) = uVar9;
                  uVar9 = puVar18[0xf];
                  *(undefined8 *)(pcVar11 + 0x70) = puVar18[0xe];
                  *(undefined8 *)(pcVar11 + 0x78) = uVar9;
                  lVar15 = lVar15 + -1;
                  pcVar12 = pcVar11 + 0x80;
                  param_2 = puVar18 + 0x10;
                } while (lVar15 != 0);
                uVar9 = puVar18[0x11];
                *(undefined8 *)(pcVar11 + 0x80) = puVar18[0x10];
                *(undefined8 *)(pcVar11 + 0x88) = uVar9;
                uVar9 = puVar18[0x13];
                *(undefined8 *)(pcVar11 + 0x90) = puVar18[0x12];
                *(undefined8 *)(pcVar11 + 0x98) = uVar9;
                uVar9 = puVar18[0x15];
                *(undefined8 *)(pcVar11 + 0xa0) = puVar18[0x14];
                *(undefined8 *)(pcVar11 + 0xa8) = uVar9;
                *(undefined8 *)(pcVar11 + 0xb0) = puVar18[0x16];
                *(undefined2 *)(pcVar11 + 0xb8) = *(undefined2 *)(puVar18 + 0x17);
              }
              else {
                local_1b8 = (connection_notification *)*puVar18;
                uStack_1b0 = param_2[3];
                local_1a8 = param_2[4];
                uStack_1a0 = param_2[5];
                local_198 = param_2[6];
                network_filtering::connection_notification::connection_notification
                          (pcVar20,(volume_update *)&local_1b8);
              }
            }
            else {
              lVar15 = 2;
              puVar8 = &local_178;
              do {
                puVar17 = puVar18;
                puVar10 = puVar8;
                uVar9 = puVar17[1];
                uVar3 = puVar17[2];
                uVar4 = puVar17[3];
                *puVar10 = *puVar17;
                puVar10[1] = uVar9;
                uVar9 = puVar17[4];
                uVar5 = puVar17[5];
                puVar10[2] = uVar3;
                puVar10[3] = uVar4;
                uVar3 = puVar17[6];
                uVar4 = puVar17[7];
                puVar10[4] = uVar9;
                puVar10[5] = uVar5;
                uVar9 = puVar17[8];
                uVar5 = puVar17[9];
                puVar10[6] = uVar3;
                puVar10[7] = uVar4;
                uVar3 = puVar17[10];
                uVar4 = puVar17[0xb];
                puVar10[8] = uVar9;
                puVar10[9] = uVar5;
                uVar9 = puVar17[0xc];
                uVar5 = puVar17[0xd];
                puVar10[10] = uVar3;
                puVar10[0xb] = uVar4;
                uVar3 = puVar17[0xe];
                uVar4 = puVar17[0xf];
                puVar10[0xc] = uVar9;
                puVar10[0xd] = uVar5;
                puVar10[0xe] = uVar3;
                puVar10[0xf] = uVar4;
                lVar15 = lVar15 + -1;
                puVar8 = puVar10 + 0x10;
                puVar18 = puVar17 + 0x10;
              } while (lVar15 != 0);
              uVar1 = *(undefined4 *)(puVar17 + 0x12);
              uVar9 = puVar17[0x11];
              puVar10[0x10] = puVar17[0x10];
              puVar10[0x11] = uVar9;
              *(undefined4 *)(puVar10 + 0x12) = uVar1;
              *(undefined1 *)((longlong)puVar10 + 0x94) = *(undefined1 *)((longlong)puVar17 + 0x94);
              network_filtering::connection_notification::connection_notification
                        (pcVar20,(connection_aborted *)&local_178);
            }
          }
          else {
            lVar15 = 2;
            puVar8 = &local_178;
            do {
              puVar17 = puVar18;
              puVar10 = puVar8;
              uVar9 = puVar17[1];
              uVar3 = puVar17[2];
              uVar4 = puVar17[3];
              *puVar10 = *puVar17;
              puVar10[1] = uVar9;
              uVar9 = puVar17[4];
              uVar5 = puVar17[5];
              puVar10[2] = uVar3;
              puVar10[3] = uVar4;
              uVar3 = puVar17[6];
              uVar4 = puVar17[7];
              puVar10[4] = uVar9;
              puVar10[5] = uVar5;
              uVar9 = puVar17[8];
              uVar5 = puVar17[9];
              puVar10[6] = uVar3;
              puVar10[7] = uVar4;
              uVar3 = puVar17[10];
              uVar4 = puVar17[0xb];
              puVar10[8] = uVar9;
              puVar10[9] = uVar5;
              uVar9 = puVar17[0xc];
              uVar5 = puVar17[0xd];
              puVar10[10] = uVar3;
              puVar10[0xb] = uVar4;
              uVar3 = puVar17[0xe];
              uVar4 = puVar17[0xf];
              puVar10[0xc] = uVar9;
              puVar10[0xd] = uVar5;
              puVar10[0xe] = uVar3;
              puVar10[0xf] = uVar4;
              lVar15 = lVar15 + -1;
              puVar8 = puVar10 + 0x10;
              puVar18 = puVar17 + 0x10;
            } while (lVar15 != 0);
            uVar1 = *(undefined4 *)(puVar17 + 0x12);
            uVar9 = puVar17[0x11];
            puVar10[0x10] = puVar17[0x10];
            puVar10[0x11] = uVar9;
            *(undefined4 *)(puVar10 + 0x12) = uVar1;
            *(undefined1 *)((longlong)puVar10 + 0x94) = *(undefined1 *)((longlong)puVar17 + 0x94);
            network_filtering::connection_notification::connection_notification
                      (pcVar20,(auth_connect *)&local_178);
          }
        }
        else {
          local_178 = *puVar18;
          uStack_170 = param_2[3];
          local_168 = param_2[4];
          uStack_160 = param_2[5];
          local_158 = param_2[6];
          uStack_150 = param_2[7];
          local_148 = param_2[8];
          uStack_140 = param_2[9];
          local_138 = param_2[10];
          uStack_130 = param_2[0xb];
          local_128 = param_2[0xc];
          uStack_120 = param_2[0xd];
          local_118 = param_2[0xe];
          uStack_110 = param_2[0xf];
          local_108 = param_2[0x10];
          uStack_100 = param_2[0x11];
          local_e8 = *(undefined4 *)(param_2 + 0x14);
          local_f8 = param_2[0x12];
          uStack_f0 = param_2[0x13];
          uStack_e4 = *(undefined1 *)((longlong)param_2 + 0xa4);
          network_filtering::connection_notification::connection_notification
                    (pcVar20,(port_open *)&local_178);
        }
      }
      else {
        local_1b8 = (connection_notification *)*puVar18;
        uStack_1b0 = param_2[3];
        local_1a8 = param_2[4];
        uStack_1a0 = param_2[5];
        local_198 = param_2[6];
        uStack_190 = param_2[7];
        local_188 = param_2[8];
        network_filtering::connection_notification::connection_notification
                  (pcVar20,(connection_close *)&local_1b8);
      }
    }
    else {
      local_1b8 = (connection_notification *)*puVar18;
      uStack_1b0 = param_2[3];
      local_1a8 = param_2[4];
      uStack_1a0 = CONCAT26(uStack_1a0._6_2_,*(undefined6 *)(param_2 + 5));
      network_filtering::connection_notification::connection_notification
                (pcVar20,(stream_segment *)&local_1b8);
    }
  }
  else {
    lVar15 = 2;
    puVar8 = &local_178;
    do {
      puVar17 = puVar18;
      puVar10 = puVar8;
      uVar9 = puVar17[1];
      uVar3 = puVar17[2];
      uVar4 = puVar17[3];
      *puVar10 = *puVar17;
      puVar10[1] = uVar9;
      uVar9 = puVar17[4];
      uVar5 = puVar17[5];
      puVar10[2] = uVar3;
      puVar10[3] = uVar4;
      uVar3 = puVar17[6];
      uVar4 = puVar17[7];
      puVar10[4] = uVar9;
      puVar10[5] = uVar5;
      uVar9 = puVar17[8];
      uVar5 = puVar17[9];
      puVar10[6] = uVar3;
      puVar10[7] = uVar4;
      uVar3 = puVar17[10];
      uVar4 = puVar17[0xb];
      puVar10[8] = uVar9;
      puVar10[9] = uVar5;
      uVar9 = puVar17[0xc];
      uVar5 = puVar17[0xd];
      puVar10[10] = uVar3;
      puVar10[0xb] = uVar4;
      uVar3 = puVar17[0xe];
      uVar4 = puVar17[0xf];
      puVar10[0xc] = uVar9;
      puVar10[0xd] = uVar5;
      puVar10[0xe] = uVar3;
      puVar10[0xf] = uVar4;
      lVar15 = lVar15 + -1;
      puVar8 = puVar10 + 0x10;
      puVar18 = puVar17 + 0x10;
    } while (lVar15 != 0);
    uVar9 = puVar17[0x14];
    uVar3 = puVar17[0x11];
    uVar4 = puVar17[0x12];
    uVar5 = puVar17[0x13];
    puVar10[0x10] = puVar17[0x10];
    puVar10[0x11] = uVar3;
    puVar10[0x12] = uVar4;
    puVar10[0x13] = uVar5;
    puVar10[0x14] = uVar9;
    *(undefined2 *)(puVar10 + 0x15) = *(undefined2 *)(puVar17 + 0x15);
    network_filtering::connection_notification::connection_notification
              (pcVar20,(connection_information *)&local_178);
  }
  lVar15 = *(longlong *)(pcVar20 + 8);
  pcVar20 = pcVar20 + 0x10;
  pcVar12 = (connection_notification *)0x0;
  if (lVar15 == 1) {
    pcVar12 = pcVar20;
  }
  if (pcVar12 == (connection_notification *)0x0) {
    pcVar12 = (connection_notification *)0x0;
    if (lVar15 == 0) {
      pcVar12 = pcVar20;
    }
    if (pcVar12 == (connection_notification *)0x0) {
      pcVar12 = (connection_notification *)0x0;
      if (lVar15 == 6) {
        pcVar12 = pcVar20;
      }
      if (((pcVar12 != (connection_notification *)0x0) && (**(int **)(param_3 + 8) != 0)) &&
         (puVar16 = *(uint **)(**(longlong **)(param_3 + 0x10) + 0x30), puVar16 != (uint *)0x0)) {
        pcVar12 = pcVar12 + 0x115;
        goto LAB_14000b419;
      }
    }
    else if ((**(int **)(param_3 + 8) != 0) &&
            (puVar16 = *(uint **)(**(longlong **)(param_3 + 0x10) + 0x30), puVar16 != (uint *)0x0))
    {
      pcVar12 = pcVar12 + 0x12a;
LAB_14000b419:
      memmove(pcVar12,*(void **)(puVar16 + 2),(ulonglong)*puVar16 - 2);
    }
  }
  else if ((**(int **)(param_3 + 8) != 0) &&
          (puVar16 = *(uint **)(**(longlong **)(param_3 + 0x10) + 0x30), puVar16 != (uint *)0x0)) {
    pcVar12 = pcVar12 + 0x1e;
    goto LAB_14000b419;
  }
  *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0;
  *(ulonglong *)(*(longlong *)param_1 + 0x38) = local_48;
  IofCompleteRequest(*(undefined8 *)param_1,0);
  bVar7 = true;
LAB_14000b4cf:
  *(undefined8 *)param_1 = 0;
  return bVar7;
}



===== WPP_SF_ @ 14000b500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== get_os_level_flags @ 14000b52c =====

/* private: unsigned int __cdecl implementation::wfp_callout::registration::get_os_level_flags(void)
   __ptr64 */

uint __thiscall implementation::wfp_callout::registration::get_os_level_flags(registration *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this[0x54] != (registration)0x0) {
    uVar1 = 0x200;
    LOG_WARNING(L"Setting URO flag on WFP callout config");
  }
  if (this[0x55] != (registration)0x0) {
    uVar1 = uVar1 | 0x100;
    LOG_WARNING(L"Setting USO flag on WFP callout config");
  }
  return uVar1;
}



===== operator() @ 14000b578 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int <lambda_ecf22fe8f4e9fd5c743167dca6cf98ce>::operator()(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48;
  undefined4 local_44;
  undefined8 local_40;
  code *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_44 = 0;
  local_30 = 0;
  local_38 = <lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
             <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>;
  local_58 = 0x47f68bfdf762e452;
  uStack_50 = 0xdc018b888d362594;
  local_40 = *(undefined8 *)*param_1;
  local_48 = implementation::wfp_callout::registration::get_os_level_flags
                       ((registration *)param_1[1]);
  iVar4 = FwpsCalloutRegister2
                    (*(undefined8 *)(*(longlong *)param_1[2] + 8),&local_58,param_1[1] + 0x2c);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar4);
    }
    return iVar4;
  }
  lVar1 = param_1[1];
  local_58 = 0x4edd289131114833;
  uStack_50 = 0x91a49a54f82feca8;
  iVar4 = FwpsCalloutRegister2(*(undefined8 *)(*(longlong *)param_1[2] + 8),&local_58,lVar1 + 0x30);
  if (iVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar4);
    }
  }
  else {
    lVar2 = param_1[1];
    local_58 = 0x4ba7d80cd67b238d;
    uStack_50 = 0xa74f46830c4adf96;
    local_40 = *(undefined8 *)param_1[3];
    local_30 = *(undefined8 *)param_1[4];
    local_48 = 1;
    iVar4 = FwpsCalloutRegister2
                      (*(undefined8 *)(*(longlong *)param_1[2] + 8),&local_58,lVar2 + 0x34);
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar4);
      }
    }
    else {
      lVar3 = param_1[1];
      local_58 = 0x4bb8fd3a36d4cf95;
      uStack_50 = 0x7f234937dbffa990;
      iVar4 = FwpsCalloutRegister2
                        (*(undefined8 *)(*(longlong *)param_1[2] + 8),&local_58,lVar3 + 0x38);
      if (-1 < iVar4) {
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar4);
      }
      FwpsCalloutUnregisterById0(*(undefined4 *)(lVar3 + 0x34));
    }
    FwpsCalloutUnregisterById0(*(undefined4 *)(lVar2 + 0x30));
  }
  FwpsCalloutUnregisterById0(*(undefined4 *)(lVar1 + 0x2c));
  return iVar4;
}



===== <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*> @ 14000b830 =====

undefined8
<lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
<lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>(void)

{
  return 0;
}



===== ~registration @ 14000b834 =====

/* public: __cdecl implementation::wfp_callout::registration::~registration(void) __ptr64 */

void __thiscall implementation::wfp_callout::registration::~registration(registration *this)

{
  wfp_registration *this_00;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids);
  }
  if (-1 < *(int *)this) {
    if (*(int *)(this + 0x20) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x1c));
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x28));
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x24));
    }
    if (*(int *)(this + 0x40) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x3c));
    }
    FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x38));
    FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x34));
    if (*(int *)(this + 0x48) != 0) {
      FwpsCalloutUnregisterById0();
      this_00 = (wfp_registration *)(ulonglong)*(uint *)(this + 0x44);
      FwpsCalloutUnregisterById0();
      *(undefined8 *)(this + 0x44) = 0;
      wfp_registration::unregister_resource_assignment(this_00);
    }
    if (*(int *)(this + 0x50) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x4c));
      *(undefined8 *)(this + 0x4c) = 0;
      wfp_registration::unregister_auth_connect((wfp_registration *)(this + 0x10));
    }
    if (*(int *)(this + 0x30) != 0) {
      FwpsCalloutUnregisterById0();
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x2c));
      *(undefined8 *)(this + 0x2c) = 0;
    }
  }
  wfp_registration::~wfp_registration((wfp_registration *)(this + 0x10));
  return;
}



===== register_resource_assignment_callouts @ 14000b994 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl
   implementation::wfp_callout::registration::register_resource_assignment_callouts(void
   (__cdecl*)(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct FWPS_INCOMING_METADATA_VALUES0_
   const * __ptr64,void * __ptr64,void const * __ptr64,struct FWPS_FILTER2_ const * __ptr64,unsigned
   __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64),void (__cdecl*)(unsigned short,unsigned
   int,unsigned __int64)) __ptr64 */

long __thiscall
implementation::wfp_callout::registration::register_resource_assignment_callouts
          (registration *this,
          _func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
          *param_1,_func_void_ushort_uint___uint64 *param_2)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(int *)(this + 0x48) != 0) {
    return 0;
  }
  lVar1 = wfp_registration::add_resource_assignment_filters((wfp_registration *)(this + 0x10));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x10;
  }
  else {
    local_28 = <lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
               <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>;
    local_38 = 0;
    local_30 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::resource_assignment_classify;
    local_20 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::stream_delete;
    local_48 = 0x58d7275b;
    uStack_44 = 0x4b6c2fd2;
    uStack_40 = 0x3303ab9;
    uStack_3c = 0x7e7d577e;
    lVar1 = FwpsCalloutRegister2(*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x44)
    ;
    if (-1 < lVar1) {
      local_48 = 0xced78e5f;
      uStack_44 = 0x485a1dd1;
      uStack_40 = 0x447e359d;
      uStack_3c = 0x4d789dcc;
      iVar2 = FwpsCalloutRegister2
                        (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x48);
      if (-1 < iVar2) {
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
      }
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x44));
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x11;
  }
  WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,lVar1);
  return lVar1;
}



===== register_datagram_callouts @ 14000bb44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl implementation::wfp_callout::registration::register_datagram_callouts(void
   (__cdecl*)(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct FWPS_INCOMING_METADATA_VALUES0_
   const * __ptr64,void * __ptr64,void const * __ptr64,struct FWPS_FILTER2_ const * __ptr64,unsigned
   __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64),void (__cdecl*)(unsigned short,unsigned
   int,unsigned __int64)) __ptr64 */

long __thiscall
implementation::wfp_callout::registration::register_datagram_callouts
          (registration *this,
          _func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
          *param_1,_func_void_ushort_uint___uint64 *param_2)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint local_38;
  undefined4 local_34;
  code *local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(int *)(this + 0x40) != 0) {
    return 0;
  }
  lVar1 = wfp_registration::add_datagram_filters((wfp_registration *)(this + 0x10));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x13;
  }
  else {
    local_34 = 0;
    local_28 = <lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
               <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>;
    local_30 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::stream_classify;
    local_20 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::stream_delete;
    local_38 = get_os_level_flags(this);
    local_38 = local_38 | 1;
    local_48 = 0xb2d11c73;
    uStack_44 = 0x47d1b4ef;
    uStack_40 = 0xe65865b6;
    uStack_3c = 0xe29fba;
    lVar1 = FwpsCalloutRegister2(*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x3c)
    ;
    if (-1 < lVar1) {
      local_48 = 0x80cece9d;
      uStack_44 = 0x46720b53;
      uStack_40 = 0x244543ac;
      uStack_3c = 0x53036c41;
      iVar2 = FwpsCalloutRegister2
                        (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x40);
      if (-1 < iVar2) {
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
      }
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x3c));
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x14;
  }
  WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,lVar1);
  return lVar1;
}



===== register_transport_callouts @ 14000bd04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl implementation::wfp_callout::registration::register_transport_callouts(void
   (__cdecl*)(struct FWPS_INCOMING_VALUES0_ const * __ptr64,struct FWPS_INCOMING_METADATA_VALUES0_
   const * __ptr64,void * __ptr64,void const * __ptr64,struct FWPS_FILTER2_ const * __ptr64,unsigned
   __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64),void (__cdecl*)(unsigned short,unsigned
   int,unsigned __int64)) __ptr64 */

long __thiscall
implementation::wfp_callout::registration::register_transport_callouts
          (registration *this,
          _func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
          *param_1,_func_void_ushort_uint___uint64 *param_2)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint local_58;
  undefined4 local_54;
  code *local_50;
  code *local_48;
  code *local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  if (*(int *)(this + 0x20) != 0) {
    return 0;
  }
  lVar1 = wfp_registration::add_transport_filters((wfp_registration *)(this + 0x10));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x16;
  }
  else {
    local_54 = 0;
    local_48 = <lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
               <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>;
    local_50 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::transport_classify;
    local_40 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::transport_delete;
    local_58 = get_os_level_flags(this);
    local_58 = local_58 | 1;
    local_68 = 0xbcecbaeb;
    uStack_64 = 0x41962757;
    uStack_60 = 0x7e05aeaf;
    uStack_5c = 0x31ed51bb;
    lVar1 = FwpsCalloutRegister2(*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_68,this + 0x24)
    ;
    if (-1 < lVar1) {
      local_68 = 0xe516b0c7;
      uStack_64 = 0x48cf9085;
      uStack_60 = 0xd1cb1185;
      uStack_5c = 0x2220dbd1;
      iVar2 = FwpsCalloutRegister2
                        (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_68,this + 0x28);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
        }
      }
      else {
        local_68 = 0x652075a2;
        uStack_64 = 0x4f4ac01a;
        uStack_60 = 0x4fbaeb99;
        uStack_5c = 0xa0c5a0f8;
        iVar2 = FwpsCalloutRegister2
                          (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_68,this + 0x1c);
        if (iVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
          }
        }
        else {
          local_68 = 0x823911ad;
          uStack_64 = 0x484e7954;
          uStack_60 = 0xd7050daa;
          uStack_5c = 0xa7859417;
          iVar2 = FwpsCalloutRegister2
                            (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_68,this + 0x20);
          if (-1 < iVar2) {
            return 0;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
          }
          FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x1c));
        }
        FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x28));
      }
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x24));
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x17;
  }
  WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,lVar1);
  return lVar1;
}



===== register_auth_connect_callouts @ 14000bfd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl
   implementation::wfp_callout::registration::register_auth_connect_callouts(void (__cdecl*)(struct
   FWPS_INCOMING_VALUES0_ const * __ptr64,struct FWPS_INCOMING_METADATA_VALUES0_ const *
   __ptr64,void * __ptr64,void const * __ptr64,struct FWPS_FILTER2_ const * __ptr64,unsigned
   __int64,struct FWPS_CLASSIFY_OUT0_ * __ptr64),void (__cdecl*)(unsigned short,unsigned
   int,unsigned __int64)) __ptr64 */

long __thiscall
implementation::wfp_callout::registration::register_auth_connect_callouts
          (registration *this,
          _func_void_FWPS_INCOMING_VALUES0__ptr_FWPS_INCOMING_METADATA_VALUES0__ptr_void_ptr_void_ptr_FWPS_FILTER2__ptr___uint64_FWPS_CLASSIFY_OUT0__ptr
          *param_1,_func_void_ushort_uint___uint64 *param_2)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint local_38;
  undefined4 local_34;
  code *local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(int *)(this + 0x50) != 0) {
    return 0;
  }
  lVar1 = wfp_registration::add_auth_connect_filters((wfp_registration *)(this + 0x10));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x1b;
  }
  else {
    local_34 = 0;
    local_28 = <lambda_81c8f8a9c58f14a90d2e37b925c94de2>::
               <lambda_invoker_cdecl><enum_FWPS_CALLOUT_NOTIFY_TYPE_,_GUID_const_*,FWPS_FILTER2__*>;
    local_30 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::auth_connect_classify;
    local_20 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
               ::stream_delete;
    local_38 = get_os_level_flags(this);
    local_48 = 0xdc9992c9;
    uStack_44 = 0x4264e32d;
    uStack_40 = 0xf056baab;
    uStack_3c = 0xf5d58ca4;
    lVar1 = FwpsCalloutRegister2(*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x4c)
    ;
    if (-1 < lVar1) {
      local_48 = 0x8b4706d8;
      uStack_44 = 0x4aeacae8;
      uStack_40 = 0x49cf7ebc;
      uStack_3c = 0x8f68227d;
      iVar2 = FwpsCalloutRegister2
                        (*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_48,this + 0x50);
      if (-1 < iVar2) {
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
      }
      FwpsCalloutUnregisterById0(*(undefined4 *)(this + 0x4c));
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return lVar1;
    }
    uVar3 = 0x1c;
  }
  WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,lVar1);
  return lVar1;
}



===== operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int> @ 14000c194 =====

int <lambda_33181a0f4f6c07f5fc5dd0cd4df2a99c>::
    operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int>
              (undefined8 *param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
              undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
              undefined1 param_9)

{
  int iVar1;
  undefined2 local_res10 [4];
  undefined4 local_res18 [2];
  undefined2 local_res20 [4];
  undefined8 local_78;
  undefined4 *local_70;
  undefined8 local_68;
  undefined2 *local_60;
  undefined8 local_58;
  undefined1 *local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined1 *local_30;
  undefined1 *local_28;
  undefined1 *local_20;
  
  local_78 = *param_1;
  local_70 = local_res18;
  local_68 = param_1[1];
  local_60 = local_res10;
  local_58 = param_1[2];
  local_50 = &param_5;
  local_48 = local_res20;
  local_40 = param_1[3];
  local_38 = &param_7;
  local_30 = &param_6;
  local_28 = &param_9;
  local_20 = &param_8;
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  local_res20[0] = param_4;
  iVar1 = <lambda_e1106df6daeb56a1e8b4208386f1fe8d>::operator()(&local_78);
  if (iVar1 < 0) {
    implementation::wfp_callout::registration::remove_contexts
              ((registration *)param_1[4],*(__uint64 *)param_1[1],*(bool *)param_1[5],
               *(bool *)param_1[3],*(bool *)*param_1,false);
  }
  return iVar1;
}



===== operator() @ 14000c260 =====

int <lambda_e1106df6daeb56a1e8b4208386f1fe8d>::operator()(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (*(char *)*param_1 == '\0') {
    puVar1 = param_1 + 4;
    if (*(int *)param_1[1] != 0) {
      iVar2 = FwpsFlowAssociateContext0
                        (*(undefined8 *)param_1[2],*(undefined2 *)param_1[3],*(int *)param_1[1],
                         *(undefined8 *)*puVar1);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                   &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
        }
        return iVar2;
      }
      LOCK();
      **(int **)*puVar1 = **(int **)*puVar1 + 1;
      UNLOCK();
    }
    if (*(int *)param_1[5] != 0) {
      iVar2 = FwpsFlowAssociateContext0
                        (*(undefined8 *)param_1[2],*(undefined2 *)param_1[6],*(int *)param_1[5],
                         *(undefined8 *)*puVar1);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                   &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
        }
        return iVar2;
      }
      LOCK();
      **(int **)*puVar1 = **(int **)*puVar1 + 1;
      UNLOCK();
    }
  }
  if (*(char *)param_1[7] == '\0') {
    if (*(int *)param_1[10] == 0) {
      return 0;
    }
    iVar2 = FwpsFlowAssociateContext0
                      (*(undefined8 *)param_1[2],*(undefined2 *)param_1[0xb],*(int *)param_1[10],
                       *(undefined8 *)param_1[4]);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar2;
      }
      uVar3 = 0x21;
      goto LAB_14000c436;
    }
  }
  else {
    if (*(int *)param_1[8] == 0) {
      return 0;
    }
    iVar2 = FwpsFlowAssociateContext0
                      (*(undefined8 *)param_1[2],*(undefined2 *)param_1[9],*(int *)param_1[8],
                       *(undefined8 *)param_1[4]);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar2;
      }
      uVar3 = 0x20;
LAB_14000c436:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar2);
      return iVar2;
    }
  }
  LOCK();
  **(int **)param_1[4] = **(int **)param_1[4] + 1;
  UNLOCK();
  return 0;
}



===== remove_contexts @ 14000c470 =====

/* public: bool __cdecl implementation::wfp_callout::registration::remove_contexts(unsigned
   __int64,bool,bool,bool,bool) __ptr64 */

bool __thiscall
implementation::wfp_callout::registration::remove_contexts
          (registration *this,__uint64 param_1,bool param_2,bool param_3,bool param_4,bool param_5)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined2 uVar4;
  __uint64 local_res10 [2];
  undefined1 local_res20 [8];
  undefined2 uVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  bool *local_28;
  __uint64 *local_20;
  bool *local_18;
  undefined1 *local_10;
  
  local_28 = &param_5;
  local_20 = local_res10;
  local_18 = &param_4;
  local_10 = local_res20;
  if (param_2) {
    iVar8 = *(int *)(this + 0x3c);
    uVar2 = 0x10;
    iVar3 = *(int *)(this + 0x1c);
    iVar6 = *(int *)(this + 0x34);
    uVar7 = 0x18;
    uVar4 = 0xc;
    iVar1 = *(int *)(this + 0x24);
    uVar5 = 0x14;
  }
  else {
    iVar8 = *(int *)(this + 0x40);
    uVar2 = 0x12;
    iVar3 = *(int *)(this + 0x20);
    iVar6 = *(int *)(this + 0x38);
    uVar7 = 0x1a;
    uVar4 = 0xe;
    iVar1 = *(int *)(this + 0x28);
    uVar5 = 0x16;
  }
  local_res10[0] = param_1;
  local_res20[0] = param_3;
  uVar2 = <lambda_e4cef09c5240325eae3844eaf94b4c0e>::
          operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int>
                    (&local_28,uVar2,iVar3,uVar4,iVar1,uVar5,iVar6,uVar7,iVar8);
  return SUB81(uVar2,0);
}



===== operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int> @ 14000c518 =====

undefined8
<lambda_e4cef09c5240325eae3844eaf94b4c0e>::
operator()<unsigned_int,unsigned_int,unsigned_int,unsigned_int>
          (undefined8 *param_1,undefined8 param_2,int param_3,undefined2 param_4,int param_5,
          undefined2 param_6,int param_7,undefined2 param_8,int param_9)

{
  int iVar1;
  undefined4 extraout_var;
  char *pcVar2;
  bool bVar3;
  int local_res8 [2];
  undefined1 local_18 [8];
  undefined8 local_10;
  
  bVar3 = true;
  local_18[0] = *(undefined1 *)*param_1;
  local_10 = *(undefined8 *)param_1[1];
  if (*(char *)param_1[2] == '\0') {
    if (param_3 != 0) {
      local_res8[0] = FwpsFlowRemoveContext0();
      iVar1 = <lambda_de0e317a67583642479d901af916b56b>::operator()<long>
                        ((longlong)local_18,local_res8);
      bVar3 = iVar1 == 0;
    }
    if (param_5 != 0) {
      local_res8[0] = FwpsFlowRemoveContext0(*(undefined8 *)param_1[1],param_4);
      iVar1 = <lambda_de0e317a67583642479d901af916b56b>::operator()<long>
                        ((longlong)local_18,local_res8);
      if ((iVar1 == 0) && (bVar3 != false)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
    }
  }
  pcVar2 = (char *)param_1[3];
  if (*pcVar2 == '\0') {
    if (param_9 == 0) goto LAB_14000c60f;
    param_6 = param_8;
  }
  else if (param_7 == 0) goto LAB_14000c60f;
  local_res8[0] = FwpsFlowRemoveContext0(*(undefined8 *)param_1[1],param_6);
  iVar1 = <lambda_de0e317a67583642479d901af916b56b>::operator()<long>((longlong)local_18,local_res8)
  ;
  pcVar2 = (char *)CONCAT44(extraout_var,iVar1);
  if ((iVar1 == 0) && (bVar3 != false)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
LAB_14000c60f:
  return CONCAT71((int7)((ulonglong)pcVar2 >> 8),bVar3);
}



===== operator()<long> @ 14000c628 =====

int <lambda_de0e317a67583642479d901af916b56b>::operator()<long>(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((iVar1 != 0) && (iVar1 != 0x103)) {
    if ((iVar1 != -0x3fffffff) && (iVar1 != -0x3ffffddb)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_SII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,(longlong)iVar1,
                   L"Failed to remove context for flow id",(char)*(undefined8 *)(param_1 + 8),
                   (char)iVar1);
      }
      return *param_2;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_SII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,(longlong)iVar1,
                 L"Suppressing error code when removing context on flow id",
                 (char)*(undefined8 *)(param_1 + 8),(char)iVar1);
    }
  }
  return 0;
}



===== ~wfp_callout @ 14000c6e8 =====

/* public: __cdecl implementation::wfp_callout::~wfp_callout(void) __ptr64 */

void __thiscall implementation::wfp_callout::~wfp_callout(wfp_callout *this)

{
  if (-1 < *(int *)this) {
    FwpsInjectionHandleDestroy0(*(undefined8 *)(this + 0x20));
  }
  if (-1 < *(int *)(this + 8)) {
    NdisFreeNetBufferListPool(*(undefined8 *)(this + 0x18));
    NdisFreeGenericObject(*(undefined8 *)(this + 0x10));
  }
  return;
}



===== inject_stream_segment @ 14000c73c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl implementation::wfp_callout::inject_stream_segment(class net_buffer_list *
   __ptr64,void * __ptr64,void (__cdecl*)(void * __ptr64,struct _NET_BUFFER_LIST * __ptr64,unsigned
   char)) __ptr64 */

long __thiscall
implementation::wfp_callout::inject_stream_segment
          (wfp_callout *this,net_buffer_list *param_1,void *param_2,
          _func_void_void_ptr__NET_BUFFER_LIST_ptr_uchar *param_3)

{
  int iVar1;
  net_buffer_list *pnVar2;
  undefined1 auStack_138 [32];
  net_buffer_list ***local_118;
  short local_110;
  undefined4 local_108;
  undefined8 local_100;
  code *local_f8;
  void *local_f0;
  void *local_e8;
  code *local_e0;
  net_buffer_list *local_d8;
  net_buffer_list **local_d0;
  undefined8 local_c8;
  net_buffer_list *pnStack_c0;
  undefined8 uStack_b8;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
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
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_138;
  local_d0 = &local_d8;
  local_c8 = &local_e0;
  pnStack_c0 = (net_buffer_list *)&local_e8;
  local_e0 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
             ::injection_complete;
  local_e8 = param_2;
  local_d8 = param_1;
  uStack_b8 = this;
  if ((*(short *)(param_1 + 0xa8) - 0x14U & 0xfffd) == 0) {
    iVar1 = <lambda_7fc82d5586000dcbd53e7eaa067eda8b>::operator()(&local_d0);
  }
  else {
    if (((*(short *)(param_1 + 0xa8) - 0x18U & 0xfffd) == 0) && (((byte)param_1[0xaa] & 1) == 0)) {
      pnVar2 = (net_buffer_list *)0x0;
      if (*(longlong *)(param_1 + 8) == 1) {
        pnVar2 = param_1 + 0x10;
      }
      if (pnVar2 != (net_buffer_list *)0x0) {
        local_a8 = *(undefined4 *)pnVar2;
        uStack_a4 = *(undefined4 *)(pnVar2 + 4);
        uStack_a0 = *(undefined4 *)(pnVar2 + 8);
        uStack_9c = *(undefined4 *)(pnVar2 + 0xc);
        uStack_b8._4_4_ = 0;
        local_88 = *(undefined8 *)(pnVar2 + 0x20);
        uStack_80 = *(undefined8 *)(pnVar2 + 0x28);
        local_c8._4_4_ = 0;
        pnStack_c0 = (net_buffer_list *)0x0;
        uStack_b8._0_4_ = 0;
        local_98 = *(undefined8 *)(pnVar2 + 0x10);
        uStack_90 = *(undefined8 *)(pnVar2 + 0x18);
        local_110 = (short)local_a8;
        local_68 = *(undefined8 *)(pnVar2 + 0x40);
        uStack_60 = *(undefined8 *)(pnVar2 + 0x48);
        local_d0 = (net_buffer_list **)&uStack_a4;
        if (local_110 != 2) {
          local_d0 = (net_buffer_list **)&uStack_a0;
        }
        local_78 = *(undefined8 *)(pnVar2 + 0x30);
        uStack_70 = *(undefined8 *)(pnVar2 + 0x38);
        local_c8._0_4_ = *(undefined4 *)(pnVar2 + 0x80);
        local_58 = *(undefined8 *)(pnVar2 + 0x50);
        uStack_50 = *(undefined8 *)(pnVar2 + 0x58);
        local_38 = *(undefined4 *)(pnVar2 + 0x70);
        uStack_34 = *(undefined4 *)(pnVar2 + 0x74);
        uStack_30 = *(undefined4 *)(pnVar2 + 0x78);
        uStack_2c = *(undefined4 *)(pnVar2 + 0x7c);
        local_48 = *(undefined4 *)(pnVar2 + 0x60);
        uStack_44 = *(undefined4 *)(pnVar2 + 100);
        uStack_40 = *(undefined4 *)(pnVar2 + 0x68);
        uStack_3c = *(undefined4 *)(pnVar2 + 0x6c);
        if (*(int *)(pnVar2 + 0x88) != 0) {
          pnStack_c0 = param_1 + (*(longlong *)(param_1 + 0xb0) + 0x18) * 8 +
                                 (ulonglong)*(uint *)(param_1 + 0xac);
          uStack_b8._0_4_ = *(int *)(pnVar2 + 0x88);
        }
        local_100 = *(undefined8 *)param_1;
        local_f8 = wfp_callout<implementation::wfp_callout,implementation::event,implementation::avl_table,implementation::queue,stream_handler<implementation::stream_handler<implementation::irp,implementation::queue,implementation::csqueue>_>,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>,excluded_addresses<implementation::avl_table>_>
                   ::injection_complete;
        local_108 = *(undefined4 *)(pnVar2 + 0x84);
        local_118 = &local_d0;
        local_f0 = param_2;
        iVar1 = FwpsInjectTransportSendAsync0
                          (*(undefined8 *)(this + 0x20),0,*(undefined8 *)(pnVar2 + 0x90),0);
        if (iVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                     &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar1);
          }
          (*local_e0)(local_e8,0,0);
        }
        else {
          iVar1 = 0;
        }
        return iVar1;
      }
      LOG_ERROR(L"UDP packet did not have UDP metadata");
      (*local_e0)(local_e8,*(undefined8 *)local_d8,0);
    }
    iVar1 = -0x3fffff45;
  }
  return iVar1;
}



===== operator() @ 14000c988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int <lambda_7fc82d5586000dcbd53e7eaa067eda8b>::operator()(undefined8 *param_1)

{
  byte bVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  longlong *plVar11;
  
  plVar2 = *(longlong **)*param_1;
  plVar11 = (longlong *)0x0;
  if (plVar2[1] == 0) {
    plVar11 = plVar2 + 2;
  }
  if (plVar11 == (longlong *)0x0) {
    LOG_ERROR(L"TCP packet did not have TCP metadata");
    (**(code **)param_1[1])(*(undefined8 *)param_1[2],**(undefined8 **)*param_1,0);
    return -0x3fffff45;
  }
  bVar1 = *(byte *)((longlong)plVar2 + 0xaa);
  puVar3 = (undefined8 *)param_1[1];
  puVar4 = (undefined8 *)param_1[2];
  bVar6 = bVar1 & 1;
  lVar5 = *plVar2;
  if ((bVar1 & 8) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (-(uint)(bVar6 != 0) & 0xfff80004) + 0x80000;
  }
  if ((bVar1 & 4) == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (-(uint)(bVar6 != 0) & 0xfffe0002) + 0x20000;
  }
  if ((bVar1 & 2) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (-(uint)(bVar6 != 0) & 0xfffc0010) + 0x40000;
  }
  iVar8 = FwpsStreamInjectAsync0
                    (*(undefined8 *)(param_1[3] + 0x20),0,0,*plVar11,(int)plVar11[1],
                     (short)plVar2[0x15],
                     (-(uint)(bVar6 != 0) & 0xffff0001) + 0x10000 | uVar9 | uVar10 | uVar7,lVar5,
                     *(undefined4 *)((longlong)plVar2 + 0xac),*puVar3,*puVar4);
  if (iVar8 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_61eec568dee03013a294ae0b421df2f9_Traceguids,iVar8);
    }
  }
  else {
    iVar8 = 0;
    if (lVar5 != 0) {
      return 0;
    }
  }
  (*(code *)*puVar3)(*puVar4,0,0);
  return iVar8;
}



===== unregister_auth_connect_filters_and_callouts @ 14000cb50 =====

void `anonymous_namespace'::unregister_auth_connect_filters_and_callouts(undefined8 param_1)

{
  FwpsCalloutUnregisterByKey0(&DAT_140011828);
  FwpsCalloutUnregisterByKey0(&DAT_140011818);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011728);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011828);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011718);
                    /* WARNING: Could not recover jumptable at 0x00014000cbd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011818);
  return;
}



===== cleanup_filter_state @ 14000cbdc =====

void `anonymous_namespace'::cleanup_filter_state
               (undefined8 param_1,char param_2,char param_3,char param_4,char param_5)

{
  if (param_2 != '\0') {
    if (param_4 != '\0') {
      FwpsCalloutUnregisterByKey0(&DAT_1400118e8);
      FwpsCalloutUnregisterByKey0(&DAT_1400118d8);
      FwpsCalloutUnregisterByKey0(&DAT_1400118c8);
      FwpsCalloutUnregisterByKey0(&DAT_1400118b8);
    }
    FwpmFilterDeleteByKey0(param_1,&DAT_1400117e8);
    FwpmCalloutDeleteByKey0(param_1,&DAT_1400118e8);
    FwpmFilterDeleteByKey0(param_1,&DAT_1400117d8);
    FwpmCalloutDeleteByKey0(param_1,&DAT_1400118d8);
    FwpmFilterDeleteByKey0(param_1,&DAT_1400117c8);
    FwpmCalloutDeleteByKey0(param_1,&DAT_1400118c8);
    FwpmFilterDeleteByKey0(param_1,&DAT_1400117b8);
    FwpmCalloutDeleteByKey0(param_1,&DAT_1400118b8);
  }
  if (param_3 != '\0') {
    if (param_4 != '\0') {
      FwpsCalloutUnregisterByKey0(&DAT_140011868);
      FwpsCalloutUnregisterByKey0(&DAT_140011858);
    }
    FwpmFilterDeleteByKey0(param_1,&DAT_1400117a8);
    FwpmCalloutDeleteByKey0(param_1,&DAT_140011868);
    FwpmFilterDeleteByKey0(param_1,&DAT_140011798);
    FwpmCalloutDeleteByKey0(param_1,&DAT_140011858);
  }
  if (param_4 != '\0') {
    FwpsCalloutUnregisterByKey0(&DAT_140011888);
    FwpsCalloutUnregisterByKey0(&DAT_140011878);
    FwpsCalloutUnregisterByKey0(&DAT_1400118a8);
    FwpsCalloutUnregisterByKey0(&DAT_140011898);
    FwpsCalloutUnregisterByKey0(&DAT_140011848);
    FwpsCalloutUnregisterByKey0(&DAT_140011838);
  }
  FwpmFilterDeleteByKey0(param_1,&DAT_140011788);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011888);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011778);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011878);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011768);
  FwpmCalloutDeleteByKey0(param_1,&DAT_1400118a8);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011758);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011898);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011748);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011848);
  FwpmFilterDeleteByKey0(param_1,&DAT_140011738);
  FwpmCalloutDeleteByKey0(param_1,&DAT_140011838);
  if (param_5 != '\0') {
    unregister_auth_connect_filters_and_callouts(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x00014000cf30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FwpmSubLayerDeleteByKey0(param_1,&DAT_1400117f8);
  return;
}



===== add_filter_and_callout @ 14000cf3c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong `anonymous_namespace'::add_filter_and_callout
                    (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4,
                    undefined8 *param_5,char param_6,undefined8 param_7,undefined4 param_8)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined4 local_148;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined8 uStack_dc;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  memset(&local_168,0,200);
  if (param_6 == '\0') {
    local_e8 = 0x6004;
  }
  else {
    local_148 = 0x10;
    local_e8 = 0x5003;
  }
  uVar1 = *param_3;
  uVar2 = param_3[1];
  local_f8 = param_8;
  local_f0 = param_7;
  uStack_150 = L"windefend";
  local_118 = 0x4ab41b8c3c1cd879;
  uStack_110 = 0xf36e1729d15e838f;
  local_108 = 0;
  local_168 = *param_4;
  uStack_160 = param_4[1];
  uVar3 = *param_5;
  uVar4 = param_5[1];
  local_158 = param_2;
  local_128 = uVar1;
  uStack_120 = uVar2;
  local_e4 = uVar3;
  uStack_dc = uVar4;
  memset(&local_98,0,0x58);
  local_88 = (undefined4)local_158;
  uStack_84 = local_158._4_4_;
  uStack_80 = (undefined4)uStack_150;
  uStack_7c = uStack_150._4_4_;
  local_98 = uVar3;
  uStack_90 = uVar4;
  local_58 = uVar1;
  uStack_50 = uVar2;
  uVar5 = FwpmCalloutAdd0(param_1,&local_98,0,0);
  if (uVar5 == 0xc0220009) {
    FwpmCalloutDeleteByKey0(param_1,&local_98);
    uVar5 = FwpmCalloutAdd0(param_1,&local_98,0,0);
  }
  if ((int)uVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,uVar5);
    }
    uVar6 = (ulonglong)uVar5;
  }
  else {
    uVar6 = FwpmFilterAdd0(param_1,&local_168,0,0);
    if ((int)uVar6 == -0x3fddfff7) {
      FwpmFilterDeleteByKey0(param_1,&local_168);
      uVar6 = FwpmFilterAdd0(param_1,&local_168,0,0);
    }
  }
  return uVar6;
}



===== wfp_registration @ 14000d13c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl wfp_registration::wfp_registration(void) __ptr64 */

wfp_registration * __thiscall wfp_registration::wfp_registration(wfp_registration *this)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 *local_78;
  undefined8 local_70;
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  *(undefined4 *)this = 0xc000000d;
  this[4] = (wfp_registration)0x0;
  *(undefined4 *)(this + 8) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_9456cab779fc32de960f7c43b068d803_Traceguids);
  }
  memset(local_68,0,0x48);
  local_88 = &local_70;
  local_70 = 0;
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
    goto LAB_14000d2d6;
  }
  iVar1 = FwpmTransactionBegin0(local_70,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0xe;
code_r0x00014000d2ac:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    local_78 = &local_70;
    uVar2 = <lambda_15df1943b3f9ad6a4b1461d747638c6d>::operator()(&local_78);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      FwpmTransactionAbort0(local_70);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar3 = 0x13;
        goto code_r0x00014000d2ac;
      }
    }
    else {
      iVar1 = FwpmTransactionCommit0();
    }
  }
  FwpmEngineClose0(local_70);
LAB_14000d2d6:
  *(int *)this = iVar1;
  return this;
}



===== operator() @ 14000d304 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong <lambda_15df1943b3f9ad6a4b1461d747638c6d>::operator()(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined1 auStackY_168 [32];
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  wchar_t *local_108;
  undefined2 local_d8;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_168;
  memset(&local_118,0,0x48);
  puVar1 = (undefined8 *)*param_1;
  local_108 = L"windefend";
  local_d8 = 0x1000;
  local_118 = 0x3c1cd879;
  uStack_114 = 0x4ab41b8c;
  uStack_110 = 0xd15e838f;
  uStack_10c = 0xf36e1729;
  uVar3 = FwpmSubLayerAdd0(*puVar1,&local_118,0);
  if (uVar3 == 0xc0220009) {
    uVar2 = *puVar1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_9456cab779fc32de960f7c43b068d803_Traceguids);
    }
    `anonymous_namespace'::cleanup_filter_state(uVar2,'\x01','\x01','\x01','\x01');
    uVar3 = FwpmSubLayerAdd0(*puVar1,&local_118,0);
  }
  uVar5 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar5;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return uVar5;
    }
    uVar6 = 0xf;
  }
  else {
    uVar4 = `anonymous_namespace'::add_filter_and_callout
                      (*(undefined8 *)*param_1,L"windefend_stream_v4",
                       (undefined8 *)&FWPM_LAYER_STREAM_V4,(undefined8 *)&DAT_140011788,
                       (undefined8 *)&DAT_140011888,'\x01',0,0);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar5;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar5;
      }
      uVar6 = 0x10;
    }
    else {
      uVar4 = `anonymous_namespace'::add_filter_and_callout
                        (*(undefined8 *)*param_1,L"windefend_stream_v6",
                         (undefined8 *)&FWPM_LAYER_STREAM_V6,(undefined8 *)&DAT_140011778,
                         (undefined8 *)&DAT_140011878,'\x01',0,0);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar5;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return uVar5;
        }
        uVar6 = 0x11;
      }
      else {
        local_b8 = 0;
        local_c8 = 0x44d6ca978784c146;
        uStack_c0 = 0xf7cb4018fb19d19f;
        local_90 = 0;
        local_b0 = 3;
        uStack_a8 = 0;
        local_68 = 0;
        local_40 = 0;
        local_a0 = 0x44d6ca978784c146;
        uStack_98 = 0xf7cb4018fb19d19f;
        local_88 = 3;
        uStack_80 = 1;
        local_78 = 0x4f9a623e3971ef2b;
        uStack_70 = 0xa7b906b8796eb18c;
        local_60 = 1;
        uStack_58 = 6;
        local_50 = 0x4f9a623e3971ef2b;
        uStack_48 = 0xa7b906b8796eb18c;
        local_38 = 1;
        uStack_30 = 0x11;
        uVar4 = `anonymous_namespace'::add_filter_and_callout
                          (*(undefined8 *)*param_1,L"windefend_flow_established_v4",
                           (undefined8 *)&FWPM_LAYER_ALE_FLOW_ESTABLISHED_V4,
                           (undefined8 *)&DAT_140011768,(undefined8 *)&DAT_1400118a8,'\0',&local_c8,
                           4);
        uVar5 = uVar4 & 0xffffffff;
        if (-1 < (int)uVar4) {
          uVar5 = `anonymous_namespace'::add_filter_and_callout
                            (*(undefined8 *)*param_1,L"windefend_flow_established_v6",
                             (undefined8 *)&FWPM_LAYER_ALE_FLOW_ESTABLISHED_V6,
                             (undefined8 *)&DAT_140011758,(undefined8 *)&DAT_140011898,'\0',
                             &local_c8,4);
          return uVar5;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar5;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return uVar5;
        }
        uVar6 = 0x12;
      }
    }
  }
  WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,(int)uVar5);
  return uVar5;
}



===== ~wfp_registration @ 14000d670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl wfp_registration::~wfp_registration(void) __ptr64 */

void __thiscall wfp_registration::~wfp_registration(wfp_registration *this)

{
  int iVar1;
  undefined1 auStack_a8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_9456cab779fc32de960f7c43b068d803_Traceguids);
  }
  memset(local_68,0,0x48);
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    FwpmTransactionBegin0(0,0);
    `anonymous_namespace'::cleanup_filter_state(0,(char)this[9],(char)this[8],'\0',(char)this[10]);
    FwpmTransactionCommit0(0);
    FwpmEngineClose0(0);
  }
  return;
}



===== add_datagram_filters @ 14000d7ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::add_datagram_filters(void) __ptr64 */

long __thiscall wfp_registration::add_datagram_filters(wfp_registration *this)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_68,0,0x48);
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    return iVar1;
  }
  iVar1 = FwpmTransactionBegin0(0,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
    goto LAB_14000d9d6;
  }
  uVar2 = `anonymous_namespace'::add_filter_and_callout
                    (0,L"windefend_datagram_v4",(undefined8 *)&FWPM_LAYER_DATAGRAM_DATA_V4,
                     (undefined8 *)&DAT_1400117a8,(undefined8 *)&DAT_140011868,'\x01',0,0);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x18;
code_r0x00014000d98e:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    uVar2 = `anonymous_namespace'::add_filter_and_callout
                      (0,L"windefend_datagram_v6",(undefined8 *)&FWPM_LAYER_DATAGRAM_DATA_V6,
                       (undefined8 *)&DAT_140011798,(undefined8 *)&DAT_140011858,'\x01',0,0);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      iVar1 = FwpmTransactionCommit0(0);
      if (-1 < iVar1) {
        this[8] = (wfp_registration)0x1;
      }
      goto LAB_14000d9d6;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x19;
      goto code_r0x00014000d98e;
    }
  }
  FwpmTransactionAbort0(0);
LAB_14000d9d6:
  FwpmEngineClose0(0);
  return iVar1;
}



===== add_transport_filters @ 14000da0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::add_transport_filters(void) __ptr64 */

long __thiscall wfp_registration::add_transport_filters(wfp_registration *this)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_68,0,0x48);
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    return iVar1;
  }
  iVar1 = FwpmTransactionBegin0(0,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
    goto LAB_14000dd17;
  }
  uVar2 = `anonymous_namespace'::add_filter_and_callout
                    (0,L"windefend_outbound_transport_v4",
                     (undefined8 *)&FWPM_LAYER_OUTBOUND_TRANSPORT_V4,(undefined8 *)&DAT_1400117e8,
                     (undefined8 *)&DAT_1400118e8,'\x01',0,0);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x1c;
code_r0x00014000dcd1:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    uVar2 = `anonymous_namespace'::add_filter_and_callout
                      (0,L"windefend_outbound_transport_v6",
                       (undefined8 *)&FWPM_LAYER_OUTBOUND_TRANSPORT_V6,(undefined8 *)&DAT_1400117d8,
                       (undefined8 *)&DAT_1400118d8,'\x01',0,0);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        uVar3 = 0x1d;
        goto code_r0x00014000dcd1;
      }
    }
    else {
      uVar2 = `anonymous_namespace'::add_filter_and_callout
                        (0,L"windefend_inbound_transport_v4",
                         (undefined8 *)&FWPM_LAYER_INBOUND_TRANSPORT_V4,(undefined8 *)&DAT_1400117c8
                         ,(undefined8 *)&DAT_1400118c8,'\x01',0,0);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar3 = 0x1e;
          goto code_r0x00014000dcd1;
        }
      }
      else {
        uVar2 = `anonymous_namespace'::add_filter_and_callout
                          (0,L"windefend_inbound_transport_v6",
                           (undefined8 *)&FWPM_LAYER_INBOUND_TRANSPORT_V6,
                           (undefined8 *)&DAT_1400117b8,(undefined8 *)&DAT_1400118b8,'\x01',0,0);
        iVar1 = (int)uVar2;
        if (-1 < iVar1) {
          iVar1 = FwpmTransactionCommit0(0);
          if (-1 < iVar1) {
            this[9] = (wfp_registration)0x1;
          }
          goto LAB_14000dd17;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          uVar3 = 0x1f;
          goto code_r0x00014000dcd1;
        }
      }
    }
  }
  FwpmTransactionAbort0(0);
LAB_14000dd17:
  FwpmEngineClose0(0);
  return iVar1;
}



===== add_auth_connect_filters @ 14000dd4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::add_auth_connect_filters(void) __ptr64 */

long __thiscall wfp_registration::add_auth_connect_filters(wfp_registration *this)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_68,0,0x48);
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    return iVar1;
  }
  iVar1 = FwpmTransactionBegin0(0,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
    goto LAB_14000df76;
  }
  uVar2 = `anonymous_namespace'::add_filter_and_callout
                    (0,L"windefend_auth_connect_v4",(undefined8 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V4,
                     (undefined8 *)&DAT_140011728,(undefined8 *)&DAT_140011828,'\0',0,0);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x22;
code_r0x00014000df2e:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    uVar2 = `anonymous_namespace'::add_filter_and_callout
                      (0,L"windefend_auth_connect_v6",(undefined8 *)&FWPM_LAYER_ALE_AUTH_CONNECT_V6,
                       (undefined8 *)&DAT_140011718,(undefined8 *)&DAT_140011818,'\0',0,0);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      iVar1 = FwpmTransactionCommit0(0);
      if (-1 < iVar1) {
        this[10] = (wfp_registration)0x1;
      }
      goto LAB_14000df76;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x23;
      goto code_r0x00014000df2e;
    }
  }
  FwpmTransactionAbort0(0);
LAB_14000df76:
  FwpmEngineClose0(0);
  return iVar1;
}



===== unregister_auth_connect @ 14000dfac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::unregister_auth_connect(void) __ptr64 */

long __thiscall wfp_registration::unregister_auth_connect(wfp_registration *this)

{
  int iVar1;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_78 [2];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(local_68,0,0x48);
  local_88 = local_78;
  local_78[0] = 0;
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    iVar1 = FwpmTransactionBegin0(local_78[0],0);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                 &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
      }
    }
    else {
      `anonymous_namespace'::unregister_auth_connect_filters_and_callouts(local_78[0]);
      this[10] = (wfp_registration)0x0;
      FwpmTransactionCommit0(local_78[0]);
      iVar1 = 0;
    }
    FwpmEngineClose0(local_78[0]);
  }
  return iVar1;
}



===== add_resource_assignment_filters @ 14000e100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::add_resource_assignment_filters(void) __ptr64 */

long __thiscall wfp_registration::add_resource_assignment_filters(wfp_registration *this)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 auStackY_b8 [32];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_68,0,0x48);
  iVar1 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    return iVar1;
  }
  iVar1 = FwpmTransactionBegin0(0,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
    goto LAB_14000e32a;
  }
  uVar2 = `anonymous_namespace'::add_filter_and_callout
                    (0,L"windefend_resource_assignment_v4",
                     (undefined8 *)&FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V4,
                     (undefined8 *)&DAT_140011748,(undefined8 *)&DAT_140011848,'\0',0,0);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x28;
code_r0x00014000e2e2:
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar1);
    }
  }
  else {
    uVar2 = `anonymous_namespace'::add_filter_and_callout
                      (0,L"windefend_resource_assignment_v6",
                       (undefined8 *)&FWPM_LAYER_ALE_RESOURCE_ASSIGNMENT_V6,
                       (undefined8 *)&DAT_140011738,(undefined8 *)&DAT_140011838,'\0',0,0);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      iVar1 = FwpmTransactionCommit0(0);
      if (-1 < iVar1) {
        this[0xb] = (wfp_registration)0x1;
      }
      goto LAB_14000e32a;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      uVar3 = 0x29;
      goto code_r0x00014000e2e2;
    }
  }
  FwpmTransactionAbort0(0);
LAB_14000e32a:
  FwpmEngineClose0(0);
  return iVar1;
}



===== unregister_resource_assignment @ 14000e360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl wfp_registration::unregister_resource_assignment(void) __ptr64 */

long __thiscall wfp_registration::unregister_resource_assignment(wfp_registration *this)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_78 [2];
  undefined1 local_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_9456cab779fc32de960f7c43b068d803_Traceguids);
  }
  memset(local_68,0,0x48);
  local_88 = local_78;
  local_78[0] = 0;
  iVar2 = FwpmEngineOpen0(0,0xffffffff,0,local_68);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_l(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_9456cab779fc32de960f7c43b068d803_Traceguids,iVar2);
    }
  }
  else {
    FwpmTransactionBegin0(local_78[0],0);
    uVar1 = local_78[0];
    FwpsCalloutUnregisterByKey0(&DAT_140011848);
    FwpsCalloutUnregisterByKey0(&DAT_140011838);
    FwpmFilterDeleteByKey0(uVar1,&DAT_140011748);
    FwpmCalloutDeleteByKey0(uVar1,&DAT_140011848);
    FwpmFilterDeleteByKey0(uVar1,&DAT_140011738);
    FwpmCalloutDeleteByKey0(uVar1,&DAT_140011838);
    FwpmTransactionCommit0(local_78[0]);
    FwpmEngineClose0(local_78[0]);
    iVar2 = 0;
  }
  return iVar2;
}



===== WPP_SF_S @ 14000e504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  wchar_t *pwVar2;
  
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
  pwVar2 = L"NULL";
  if (param_4 != (wchar_t *)0x0) {
    pwVar2 = param_4;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01024f31d60d3748ddb985f871aa1cf7_Traceguids,param_2,pwVar2,lVar1,0);
  return;
}



===== WPP_SF_SI @ 14000e578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SI(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  wchar_t *pwVar2;
  
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
  pwVar2 = L"NULL";
  if (param_4 != (wchar_t *)0x0) {
    pwVar2 = param_4;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01024f31d60d3748ddb985f871aa1cf7_Traceguids,param_2,pwVar2,lVar1,
             &param_5,8,0);
  return;
}



===== WPP_SF_SII @ 14000e600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_SII(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  
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
  pwVar2 = L"NULL";
  if (param_4 != (wchar_t *)0x0) {
    pwVar2 = param_4;
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_01024f31d60d3748ddb985f871aa1cf7_Traceguids,param_2,pwVar2,lVar1,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_SqI @ 14000e698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WPP_SF_SqI(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 auStack_88 [32];
  wchar_t *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_48 = &uStack0000000000000030;
  local_38 = 0;
  local_40 = 8;
  local_58 = local_28;
  local_50 = 8;
  local_60 = 0x3c;
  local_68 = L"Failed to remove flow context";
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_01024f31d60d3748ddb985f871aa1cf7_Traceguids);
  return;
}



===== LOG_WARNING @ 14000e728 =====

/* void __cdecl LOG_WARNING(wchar_t const * __ptr64) */

void __cdecl LOG_WARNING(wchar_t *param_1)

{
  undefined8 in_R8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,in_R8,param_1);
  }
  return;
}



===== LOG_ERROR @ 14000e760 =====

/* void __cdecl LOG_ERROR(wchar_t const * __ptr64) */

void __cdecl LOG_ERROR(wchar_t *param_1)

{
  undefined8 in_R8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,in_R8,param_1);
  }
  return;
}



===== LOG_VERBOSE_UINT64 @ 14000e798 =====

/* void __cdecl LOG_VERBOSE_UINT64(wchar_t const * __ptr64,unsigned __int64) */

void __cdecl LOG_VERBOSE_UINT64(wchar_t *param_1,__uint64 param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_SI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_2,param_1,(char)param_2);
  }
  return;
}



===== LOG_WARNING_UINT64 @ 14000e7d8 =====

/* void __cdecl LOG_WARNING_UINT64(wchar_t const * __ptr64,unsigned __int64) */

void __cdecl LOG_WARNING_UINT64(wchar_t *param_1,__uint64 param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_SI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_2,param_1,(char)param_2);
  }
  return;
}



===== LOG_ERROR_UINT64 @ 14000e818 =====

/* void __cdecl LOG_ERROR_UINT64(wchar_t const * __ptr64,unsigned __int64) */

void __cdecl LOG_ERROR_UINT64(wchar_t *param_1,__uint64 param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_SI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,param_2,param_1,(char)param_2);
  }
  return;
}



===== __report_gsfailure @ 14000e860 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __cpu_features_init @ 14000e890 =====

/* WARNING: Removing unreachable block (ram,0x00014000e8fa) */
/* WARNING: Removing unreachable block (ram,0x00014000e8a9) */
/* WARNING: Removing unreachable block (ram,0x00014000e89a) */

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



===== __GSHandlerCheck @ 14000e948 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000e968 =====

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



===== WdmlibRtlInitUnicodeStringEx @ 14000e9c8 =====

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



===== _snwprintf @ 14000ea10 =====

int __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ea10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _snwprintf(_Dest,_Count,_Format);
  return iVar1;
}



===== _wcsnicmp @ 14000ea1c =====

int __cdecl _wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ea1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _wcsnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== wcschr @ 14000ea28 =====

wchar_t * __cdecl wcschr(wchar_t *_Str,wchar_t _Ch)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000ea28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pwVar1 = wcschr(_Str,_Ch);
  return pwVar1;
}



===== _guard_check_icall @ 14000ea40 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 14000ea60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000ea90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000eab0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000eab0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000ead0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 14000eb00 =====

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



===== __memset_repmovs @ 14000ec40 =====

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



===== __memset_query @ 14000ecc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== memmove @ 14000ed00 =====

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



===== memcmp @ 14000efc0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000f003;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000f074;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000f070:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000f074;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000f06c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000f070;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000f06c;
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
LAB_14000f074:
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
LAB_14000f003:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== WppLoadTracingSupport @ 140015000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WppLoadTracingSupport(void)

{
  undefined1 auStack_58 [48];
  uint local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = 0;
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_20,L"PsGetVersion");
  pfnWppGetVersion = MmGetSystemRoutineAddress(&local_20);
  RtlInitUnicodeString(&local_20,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_20);
  RtlInitUnicodeString(&local_20,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_20);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != 0) {
    (*(code *)pfnWppGetVersion)(local_28,0,0,0);
  }
  if (5 < local_28[0]) {
    RtlInitUnicodeString(&local_20,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_20);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_20,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_20);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 140015160 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
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
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_50 = 0;
      local_4c = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar10 = *(uint **)(param_5 + 8);
          if (((*puVar10 == param_4[6]) && (puVar10[1] == param_4[7])) &&
             ((puVar10[2] == param_4[8] && (puVar10[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar12 = WPPTraceSuite != 2;
          uVar1 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar1;
          if (bVar12) {
            local_58._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = local_58._4_4_;
            local_58._2_1_ = (undefined1)((ulonglong)uVar1 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = local_58._2_1_;
            return 0;
          }
          local_68 = param_4;
          local_58 = uVar1;
          iVar4 = (*pfnWppQueryTraceInformation)(3,&local_50,4,&local_4c);
          if (iVar4 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_50;
          }
          local_68 = param_4;
          uVar5 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&local_4c);
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
      puVar2 = *(ushort **)(param_5 + 0x20);
      uVar11 = 0;
      lVar6 = param_5;
      do {
        lVar6 = *(longlong *)(lVar6 + 0x10);
        uVar11 = uVar11 + 1;
      } while (lVar6 != 0);
      if (0x3f < uVar11) {
        return 0xc000000d;
      }
      uVar8 = uVar11 * 0x20 + 0x18;
      if (puVar2 == (ushort *)0x0) {
        uVar9 = uVar8;
        uVar8 = 0;
      }
      else {
        uVar9 = uVar8 + *puVar2 + 2;
      }
      if (param_3 < uVar9) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar9;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar9;
      param_4[2] = uVar8;
      param_4[4] = uVar11;
      if (puVar2 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar8 + (longlong)param_4) = *puVar2;
        memmove((void *)((ulonglong)uVar8 + 2 + (longlong)param_4),*(void **)(puVar2 + 4),
                (ulonglong)*puVar2);
      }
      if (uVar11 != 0) {
        uVar7 = (ulonglong)uVar11;
        puVar10 = param_4 + 10;
        do {
          uVar1 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar10 = 0x81000;
          *(undefined8 *)(puVar10 + -4) = uVar1;
          *(undefined8 *)(puVar10 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar7 = uVar7 - 1;
          puVar10 = puVar10 + 8;
        } while (uVar7 != 0);
      }
      *param_6 = uVar9;
      return 0;
    }
  }
  return 0xc0000010;
}



===== WppInitKm @ 1400153e4 =====

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
      return;
    }
    if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppCleanupKm @ 140015478 =====

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



===== MpCreateCallback @ 1400154f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MpCreateCallback(longlong param_1)

{
  undefined8 uVar1;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_54 = 0;
  local_3c = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    RtlInitUnicodeString(&local_28);
    local_58 = 0x30;
    local_48 = &local_28;
    local_50 = 0;
    local_40 = 0x210;
    local_38 = 0;
    uStack_30 = 0;
    uVar1 = ExCreateCallback(param_1,&local_58,1);
  }
  return uVar1;
}



===== MpReleaseCallback @ 1400155a0 =====

void MpReleaseCallback(longlong param_1)

{
  if (param_1 != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== MpRegisterCallback @ 1400155bc =====

undefined4
MpRegisterCallback(longlong param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_4 == (longlong *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else {
    lVar1 = ExRegisterCallback(param_1,running_processes<implementation::running_processes,implementation::avl_table,path_list<implementation::path_list>_>
                                       ::process_notification_callback);
    *param_4 = lVar1;
    uVar2 = 0;
    if (lVar1 == 0) {
      uVar2 = 0xc0000001;
    }
  }
  return uVar2;
}



===== MpUnregisterCallback @ 14001560c =====

void MpUnregisterCallback(longlong param_1)

{
  if (param_1 != 0) {
    ExUnregisterCallback();
  }
  return;
}



===== MpGetProcessCreationTimeById @ 140015628 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MpGetProcessCreationTimeById(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    *param_2 = 0;
    if (param_1 != 0) {
      local_18 = 0;
      uVar1 = PsLookupProcessByProcessId(param_1,&local_18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar1 = PsGetProcessCreateTimeQuadPart(local_18);
      *param_2 = uVar1;
      ObfDereferenceObject(local_18);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== WdmlibInit @ 1400156b8 =====

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
  PfnIoValidateDeviceIoControlAccess = MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = 1;
  return;
}



===== WdmlibIoCreateDeviceSecure @ 140015744 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9)

{
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1400157e0 =====

ulonglong IoDevObjCreateDeviceSecure
                    (longlong param_1,undefined4 param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,longlong param_8,
                    undefined8 *param_9)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  puVar1 = param_9;
  local_res18 = 0;
  local_48 = 0;
  *param_9 = 0;
  local_30 = 0;
  param_9 = (undefined8 *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  if (param_8 == 0) {
    PpRegStateInitEmptyCreationSettings(&local_58);
  }
  else {
    uVar3 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_58);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if ((local_58 & 2) == 0) {
    uVar3 = SeSddlSecurityDescriptorFromSDDL(param_7,1,&local_res18);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) goto LAB_14001594a;
    PpRegStateLoadSecurityDescriptor(local_res18,(undefined4 *)&local_58);
    if (param_8 != 0) {
      PpRegStateInitEmptyCreationSettings(&local_40);
      PpRegStateLoadSecurityDescriptor(local_res18,(undefined4 *)&local_40);
      uVar3 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_40);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14001594a;
    }
  }
  if (((uint)local_58 & 1) != 0) {
    param_4 = local_58._4_4_;
  }
  if (((uint)local_58 & 4) != 0) {
    param_5 = (undefined4)local_48;
  }
  if (((uint)local_58 & 8) != 0) {
    param_6 = local_48._4_1_;
  }
  uVar2 = IoCreateDevice(param_1,param_2,param_3,param_4,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar3 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_58);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar1 = param_9;
    }
  }
LAB_14001594a:
  PpRegStateFreeStackCreationSettings((uint *)&local_58);
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 140015970 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  uint local_res20 [2];
  undefined8 local_28 [2];
  
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_28[0] = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      SeSetSecurityAccessMask((byte)local_res18[0],local_res20);
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,local_res20[0],*(undefined8 *)IoDeviceObjectType_exref,0,
                         local_28);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_28[0],local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_28[0]);
      }
    }
  }
  return uVar2;
}



===== SeSetSecurityAccessMask @ 140015a30 =====

void SeSetSecurityAccessMask(byte param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  *param_2 = 0;
  if ((param_1 & 3) != 0) {
    uVar1 = 0x80000;
    *param_2 = 0x80000;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x40000;
    *param_2 = uVar1;
  }
  if ((param_1 & 8) != 0) {
    *param_2 = uVar1 | 0x1000000;
  }
  return;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 140015a58 =====

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
  *param_2 = 0;
  *param_3 = 0;
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



===== PiRegStateOpenClassKey @ 140015b4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (uint *param_1,undefined4 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  int local_a8;
  undefined8 local_a0;
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  *param_5 = 0;
  local_a0 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_2;
  local_a8 = param_3;
  uVar2 = CmRegUtilOpenExistingWstrKey(0,0x140010560,0x20019,&local_b0);
  if (-1 < (int)uVar2) {
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",*param_1,
               (uint)(ushort)param_1[1],(uint)*(ushort *)((longlong)param_1 + 6),
               (uint)(byte)param_1[2],(uint)*(byte *)((longlong)param_1 + 9),
               (uint)*(byte *)((longlong)param_1 + 10),(uint)*(byte *)((longlong)param_1 + 0xb),
               (uint)(byte)param_1[3],(uint)*(byte *)((longlong)param_1 + 0xd),
               (uint)*(byte *)((longlong)param_1 + 0xe),(uint)*(byte *)((longlong)param_1 + 0xf));
    local_4c = 0;
    if (local_a8 == 0) {
      uVar1 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,local_b4,&local_a0);
      local_b8 = 2;
    }
    else {
      uVar1 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,local_b4,0,0,&local_b8,&local_a0);
    }
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_b0);
    if ((-1 < (int)uVar1) && (*param_5 = local_a0, param_4 != (undefined4 *)0x0)) {
      *param_4 = local_b8;
    }
  }
  return uVar2;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 140015cdc =====

ulonglong PiRegStateReadStackCreationSettingsFromKey(undefined8 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_48 [2];
  
  puVar1 = param_2 + 1;
  puVar2 = param_2 + 4;
  *param_2 = 0;
  puVar3 = param_2 + 5;
  param_2[2] = 0;
  param_2[3] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_48[0] = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  uVar4 = CmRegUtilWstrValueGetFullBuffer(param_1,0x1400104e8,3,0,local_48);
  if ((int)uVar4 < 0) {
    uVar6 = (ulonglong)uVar4;
    if (uVar4 == 0xc0000034) {
      uVar6 = 0;
    }
  }
  else {
    uVar4 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_48[0] + 8) + local_48[0],0,1,1,&local_res20);
    uVar6 = (ulonglong)uVar4;
  }
  if (local_48[0] != 0) {
    ExFreePoolWithTag(local_48[0],0);
  }
  if (-1 < (int)uVar6) {
    if (local_res20 != 0) {
      uVar5 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,local_res18);
      uVar6 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140015e5f;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar4 = CmRegUtilWstrValueGetDword(param_1,0x140010500,0,puVar1);
    uVar6 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if (uVar4 != 0xc0000034) goto LAB_140015e5f;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar4 = CmRegUtilWstrValueGetDword(param_1,0x140010518,0,puVar2);
    uVar6 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if (uVar4 != 0xc0000034) goto LAB_140015e5f;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar4 = CmRegUtilWstrValueGetDword(param_1,0x140010548,0,puVar3);
    uVar6 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      *param_2 = *param_2 | 8;
      return uVar6;
    }
    if (uVar4 == 0xc0000034) {
      return 0;
    }
  }
LAB_140015e5f:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  *param_2 = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  return uVar6;
}



===== PpRegStateFreeStackCreationSettings @ 140015ea4 =====

void PpRegStateFreeStackCreationSettings(uint *param_1)

{
  if ((*param_1 & 2) != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 2),0);
  }
  return;
}



===== PpRegStateInitEmptyCreationSettings @ 140015ec8 =====

void PpRegStateInitEmptyCreationSettings(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



===== PpRegStateLoadSecurityDescriptor @ 140015ed8 =====

void PpRegStateLoadSecurityDescriptor(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 2;
  *(undefined8 *)(param_2 + 2) = param_1;
  return;
}



===== PpRegStateReadCreateClassCreationSettings @ 140015ee4 =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort *puVar4;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18[0] = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,0xf003f,1,local_res18,&local_res20);
  uVar3 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140010488,0x20019,local_18);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18[0],param_3);
    uVar2 = uVar2 & 0xffffffff;
    uVar3 = local_18[0];
  }
  else {
    puVar4 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar4 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar1 = CmRegUtilWstrValueSetUcString(local_res20,0x1400104a0,puVar4);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        local_res18[0] = 0x31;
        uVar1 = CmRegUtilWstrValueSetWstrString(uVar3,0x1400104b0,(longlong)local_res18);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar3,0x1400104d0,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
        }
      }
    }
  }
  ZwClose(uVar3);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 140016020 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined8 param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  local_res18 = (undefined *)0x0;
  local_18[0] = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,0xf003f,0,(undefined4 *)0x0,&local_res20);
  if (-1 < (int)uVar4) {
    puVar5 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,1,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar5 = (undefined *)0x0;
    }
    local_res18 = puVar5;
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,0x140010488,0xf003f,0,puVar5,(undefined4 *)0x0,local_18);
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar2 = CmRegUtilWstrValueSetFullBuffer
                        (local_18[0],0x1400104e8,3,*(undefined8 *)(param_2 + 8),uVar3);
      ZwClose(local_18[0]);
    }
    uVar4 = (ulonglong)uVar2;
  }
  return uVar4;
}



===== SeSddlSecurityDescriptorFromSDDL @ 14001616c =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,int param_2,longlong *param_3)

{
  ulonglong uVar1;
  short *_Dst;
  
  uVar1 = (ulonglong)*param_1 + 2;
  if ((param_1[1] == uVar1) && ((*(short **)(param_1 + 4))[*param_1 >> 1] == 0)) {
    uVar1 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),param_2,param_3);
    return uVar1;
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar1,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar1 = SepSddlSecurityDescriptorFromSDDLString(_Dst,param_2,param_3);
    uVar1 = uVar1 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar1;
}



===== SepSddlAddAceToAcl @ 14001624c =====

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



===== SepSddlDaclFromSDDLString @ 140016344 =====

int SepSddlDaclFromSDDLString(short *param_1,int param_2,uint *param_3,longlong *param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  short *psVar3;
  uint uVar4;
  longlong local_res8;
  short *local_res18;
  
  *param_4 = 0;
  *param_3 = 0;
  local_res8 = 0;
  local_res18 = (short *)0x0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  pwVar2 = param_1 + 2;
  uVar4 = -(uint)(param_2 != 0) & 8;
  if (*pwVar2 == L'P') {
    pwVar2 = param_1 + 3;
    uVar4 = (-(uint)(param_2 != 0) & 8) + 0x1000;
  }
  iVar1 = SepSddlGetAclForString(pwVar2,&local_res8,&local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
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



===== SepSddlGetAclForString @ 140016430 =====

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
  void *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  short *local_res8;
  uint local_res10 [2];
  uint local_res18 [2];
  wchar_t *local_res20;
  longlong local_58 [3];
  
  *param_2 = 0;
  local_res10[0] = 0;
  iVar5 = 0;
  local_res20 = (wchar_t *)0x0;
  local_58[0] = 0;
  uVar14 = 0;
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
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar14 = uVar14 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar13 = uVar14 / 5;
  if ((uVar14 != uVar13 * 5) || ((uVar14 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar13 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0;
        *(undefined1 *)*param_2 = 2;
        *(undefined1 *)(*param_2 + 1) = 0;
        *(undefined2 *)(*param_2 + 2) = 8;
        *(undefined2 *)(*param_2 + 4) = 0;
        *(undefined2 *)(*param_2 + 6) = 0;
        return 0;
      }
    }
    else {
      uVar14 = uVar13 * 0x30 + 8;
      if (0xffff < uVar14) {
        uVar14 = 0xffff;
      }
      _Dst = (void *)ExAllocatePoolWithTag(1,uVar14,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (void *)0x0) {
        local_res18[0] = 8;
        memset(_Dst,0,(ulonglong)uVar14);
        uVar12 = 0;
        *(undefined1 *)*param_2 = 2;
        *(undefined1 *)(*param_2 + 1) = 0;
        *(short *)(*param_2 + 2) = (short)uVar14;
        *(undefined2 *)(*param_2 + 4) = 0;
        *(undefined2 *)(*param_2 + 6) = 0;
        uVar14 = 8;
        if (uVar13 != 0) {
          do {
            uVar14 = 0;
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
LAB_1400167be:
              iVar5 = -0x3ffffff3;
LAB_1400167c1:
              lVar7 = *param_2;
              goto LAB_1400167a6;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1400167be;
            do {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            } while (wVar1 == L' ');
            while (wVar1 != L';') {
              while (wVar1 == L' ') {
                pwVar6 = pwVar6 + 1;
                wVar1 = *pwVar6;
              }
              uVar9 = SepSddlLookupAccessMaskInTable(pwVar6,local_res10,(longlong *)&local_res20);
              if ((int)uVar9 == 0) {
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_res20,(uint *)&local_res8);
                if (local_res20 == pwVar6) goto LAB_1400167be;
                uVar14 = (uint)local_res8;
              }
              else {
                local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar14 | local_res10[0]);
                uVar14 = uVar14 | local_res10[0];
              }
              pwVar6 = local_res20;
              wVar1 = *local_res20;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1400167c1;
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
            if (iVar5 != 0) goto LAB_1400167c1;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            uVar9 = SepSddlGetSidForString(pwVar6,local_58,(longlong *)&local_res8);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar11 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_14001672d:
              iVar5 = -0x3fffff89;
              goto LAB_1400167c1;
            }
            for (; *psVar11 == 0x20; psVar11 = psVar11 + 1) {
            }
            if (*psVar11 != 0x29) goto LAB_14001672d;
            param_1 = psVar11 + 1;
            if (local_58[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res18,0,0,uVar14,uVar13 - uVar12,local_58[0])
              ;
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1400167c1;
            }
            if (*param_1 == L'(') {
              param_1 = psVar11 + 2;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar13);
          uVar14 = local_res18[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar14;
          return 0;
        }
LAB_1400167a6:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1400167e8 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_1400130c4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1400130bc + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      uVar6 = (&DAT_1400130c4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (*(int *)(&DAT_1400130b8 + uVar7 * 0x18) == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_140016878;
      }
      else {
LAB_140016878:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1400130b0 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_14001688d;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_14001688d:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlLookupAccessMaskInTable @ 1400168b0 =====

undefined8 SepSddlLookupAccessMaskInTable(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &PTR_u_RC_140013200;
  uVar2 = 0;
  do {
    iVar1 = _wcsnicmp(param_1,(wchar_t *)*ppuVar3,(ulonglong)*(uint *)(ppuVar3 + 1));
    if (iVar1 == 0) {
      *param_2 = (&DAT_14001320c)[(ulonglong)uVar2 * 4];
      *param_3 = (longlong)(param_1 + (uint)(&DAT_140013208)[(ulonglong)uVar2 * 4]);
      return 1;
    }
    uVar2 = uVar2 + 1;
    ppuVar3 = ppuVar3 + 2;
  } while (uVar2 < 8);
  *param_2 = 0;
  *param_3 = (longlong)param_1;
  return 0;
}



===== SepSddlParseWideStringUlong @ 14001693c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  *param_3 = 0;
  *param_2 = param_1;
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1400169bf:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_14001699d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1400169bf;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_14001699d:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140016a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,int param_2,longlong *param_3)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  code *pcVar4;
  ulonglong uVar5;
  void *_Dst;
  uint local_res20 [2];
  uint local_68 [2];
  longlong local_60 [3];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_60[1] = 0;
  local_60[2] = 0;
  RtlInitUnicodeString(local_60 + 1,L"SeConvertStringSecurityDescriptorToSecurityDescriptor");
  pcVar4 = (code *)MmGetSystemRoutineAddress(local_60 + 1);
  if (pcVar4 != (code *)0x0) {
    uVar5 = (*pcVar4)(param_1,1,param_3);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    if (param_2 == 0) {
      return uVar5;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar5;
  }
  local_68[0] = 0;
  local_res20[0] = 0;
  local_60[0] = 0;
  *param_3 = 0;
  _Dst = (void *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = SepSddlDaclFromSDDLString(param_1,param_2,local_68,local_60);
  lVar2 = local_60[0];
  if (-1 < (int)uVar3) {
    RtlCreateSecurityDescriptor(&local_48,1);
    RtlSetDaclSecurityDescriptor(&local_48,1,lVar2,0);
    uVar1 = local_48._2_2_ | (ushort)local_68[0];
    local_48._0_4_ = CONCAT22(uVar1,(undefined2)local_48);
    RtlAbsoluteToSelfRelativeSD(&local_48,0,local_res20);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res20[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res20[0]);
      uVar3 = RtlAbsoluteToSelfRelativeSD(&local_48,_Dst,local_res20);
      if (-1 < (int)uVar3) {
        ExFreePoolWithTag(lVar2,0);
        *param_3 = (longlong)_Dst;
        goto LAB_140016b95;
      }
    }
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140016b95:
  return (ulonglong)uVar3;
}



===== CmRegUtilCreateUcKey @ 140016bf4 =====

int CmRegUtilCreateUcKey
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
              undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res10 [3];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res10,param_3,&local_38,0,0,param_4,local_res8);
  if (iVar1 < 0) {
    local_res10[0] = 0;
    local_res8[0] = 0;
  }
  *param_7 = local_res10[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_res8[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 140016c94 =====

void CmRegUtilCreateWstrKey
               (undefined8 param_1,longlong param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [8];
  
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
    CmRegUtilCreateUcKey(param_1,local_18,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



===== CmRegUtilOpenExistingUcKey @ 140016d0c =====

void CmRegUtilOpenExistingUcKey
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8 = 0;
  *param_4 = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwOpenKey(&local_res8,param_3,&local_38);
  if (-1 < iVar1) {
    *param_4 = local_res8;
  }
  return;
}



===== CmRegUtilOpenExistingWstrKey @ 140016d7c =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  short local_18 [8];
  
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
    CmRegUtilOpenExistingUcKey(param_1,local_18,param_3,param_4);
  }
  return;
}



===== CmRegUtilUcValueGetDword @ 140016dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilUcValueGetDword
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 *local_30;
  undefined4 local_28 [2];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28[0] = 0;
  local_30 = local_28;
  local_38 = 0x10;
  uVar1 = ZwQueryValueKey(param_1,param_2,2,local_20);
  if (-1 < (int)uVar1) {
    if (local_1c == 4) {
      param_3 = local_14;
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  *param_4 = param_3;
  return uVar1;
}



===== CmRegUtilUcValueGetFullBuffer @ 140016e50 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,int param_3,int param_4,undefined8 *param_5)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  *param_5 = 0;
  uVar1 = *param_2 + 0x1f & 0xfffffff8;
  uVar3 = uVar1 + param_4;
  if (uVar3 < uVar1) {
    return -0x3fffff6b;
  }
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar3,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar3);
  iVar2 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar3,local_res20);
  if (iVar2 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar2 != -0x7ffffffb) && (iVar2 != -0x3fffffdd)) {
      return iVar2;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar2 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar2 < 0) goto LAB_140016f98;
  }
  if ((param_3 == 0) || (*(int *)((longlong)_Dst + 4) == param_3)) {
    *param_5 = _Dst;
    return 0;
  }
  iVar2 = -0x3fffffdc;
LAB_140016f98:
  ExFreePoolWithTag(_Dst,0);
  return iVar2;
}



===== CmRegUtilUcValueSetUcString @ 140016fdc =====

ulonglong CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 local_18;
  void *pvStack_10;
  
  uVar1 = *param_3;
  local_18 = 0;
  pvStack_10 = (void *)0x0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    uVar3 = CmpRegUtilAllocateUnicodeString((undefined2 *)&local_18,uVar1);
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      local_18 = CONCAT62(local_18._2_6_,*param_3);
      memmove(pvStack_10,*(void **)(param_3 + 4),(ulonglong)*param_3);
      *(undefined2 *)((longlong)pvStack_10 + (ulonglong)((ushort)local_18 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,pvStack_10,(ushort)local_18 + 2);
      uVar4 = (ulonglong)uVar2;
      RtlFreeUnicodeString(&local_18);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(0,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
    uVar4 = (ulonglong)uVar2;
  }
  return uVar4;
}



===== CmRegUtilWstrValueGetDword @ 1400170f0 =====

void CmRegUtilWstrValueGetDword
               (undefined8 param_1,longlong param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  short local_18 [8];
  
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
    CmRegUtilUcValueGetDword(param_1,local_18,param_3,param_4);
  }
  return;
}



===== CmRegUtilWstrValueGetFullBuffer @ 140017144 =====

void CmRegUtilWstrValueGetFullBuffer
               (undefined8 param_1,longlong param_2,int param_3,int param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  ushort local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilUcValueGetFullBuffer(param_1,local_18,param_3,param_4,param_5);
  }
  return;
}



===== CmRegUtilWstrValueSetFullBuffer @ 1400171a0 =====

void CmRegUtilWstrValueSetFullBuffer
               (undefined8 param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5)

{
  undefined8 uVar1;
  short local_18 [8];
  
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
    ZwSetValueKey(param_1,local_18,0,param_3,param_4,param_5);
  }
  return;
}



===== CmRegUtilWstrValueSetUcString @ 140017208 =====

void CmRegUtilWstrValueSetUcString(undefined8 param_1,longlong param_2,ushort *param_3)

{
  undefined8 uVar1;
  short local_18 [8];
  
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
    CmRegUtilUcValueSetUcString(param_1,local_18,param_3);
  }
  return;
}



===== CmRegUtilWstrValueSetWstrString @ 14001724c =====

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



===== CmpRegUtilAllocateUnicodeString @ 1400172ac =====

undefined8 CmpRegUtilAllocateUnicodeString(undefined2 *param_1,ushort param_2)

{
  void *_Dst;
  undefined8 uVar1;
  
  param_1[1] = param_2 + 2;
  *param_1 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(1,(ulonglong)param_2 + 2,0x63557050);
  *(void **)(param_1 + 4) = _Dst;
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)param_2 + 2);
    uVar1 = 0;
  }
  return uVar1;
}



===== entry @ 140018000 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001802c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140013000) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


