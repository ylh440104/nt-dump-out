
===== Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const_*,void_const_*,_GUID_const_*,_GUID_const_*,unsigned_int,_EVENT_DATA_DESCRIPTOR_*),&_tlgWriteTransfer_EtwWriteTransfer,_GUID_const_*,_GUID_const_*>
::
Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapSz<unsigned_short> *param_6,
          _tlgWrapSz<unsigned_short> *param_7,_tlgWrapperByVal<4> *param_8,
          _tlgWrapperByVal<4> *param_9,_tlgWrapperByVal<4> *param_10)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_c8 [32];
  _EVENT_DATA_DESCRIPTOR local_98 [2];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<4> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_28 = param_10;
  lVar3 = -1;
  local_38 = param_9;
  local_60 = 2;
  local_48 = param_8;
  local_20 = 4;
  local_30 = 4;
  local_40 = 4;
  local_58 = param_7->Psz;
  if (local_58 == (wchar_t *)0x0) {
    local_58 = L"";
    local_50 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_4c = 0;
  local_68 = param_6->Psz;
  if (local_68 == (wchar_t *)0x0) {
    local_68 = L"";
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_68[lVar3] != L'\0');
    local_60 = (int)lVar3 * 2 + 2;
  }
  local_78 = param_5;
  local_70 = 8;
  local_5c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer
                    (&_Tlgg_TelemetryProviderProv,param_2,(_GUID *)0x0,(_GUID *)0x0,8,local_98);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001118 =====

long __cdecl
_tlgWriteTransfer_EtwWriteTransfer
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,uint param_5,
          _EVENT_DATA_DESCRIPTOR *param_6)

{
  long lVar1;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*(byte *)param_2 << 0x18;
  local_14 = (uint)*(ushort *)((longlong)param_2 + 1);
  local_10 = *(undefined8 *)((longlong)param_2 + 3);
  param_6->Ptr = (ulong64)param_1->ProviderMetadataPtr;
  param_6->Size = (uint)*param_1->ProviderMetadataPtr;
  param_6[1].Ptr = (ulong64)((longlong)param_2 + 0xb);
  (param_6->field2_0xc).Reserved = 2;
  param_6[1].Size = (uint)*(ushort *)((longlong)param_2 + 0xb);
  param_6[1].field2_0xc.Reserved = 1;
  lVar1 = EtwWriteTransfer(param_1->RegHandle,&local_18,param_3,param_4,param_5,param_6);
  return lVar1;
}



===== LibraryLinkInClient @ 1400011c0 =====

long __cdecl
LibraryLinkInClient(_LIBRARY_MODULE *param_1,_DRIVER_OBJECT *param_2,_UNICODE_STRING *param_3,
                   _WDF_BIND_INFO *param_4,void *param_5,_CLIENT_MODULE **param_6)

{
  _LIST_ENTRY *p_Var1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  _CLIENT_MODULE *p_Var5;
  _LIST_ENTRY *p_Var6;
  uchar uVar7;
  uchar uVar8;
  _WDF_BIND_INFO *p_Var9;
  ulong in_stack_ffffffffffffffb0;
  
  *param_6 = (_CLIENT_MODULE *)0x0;
  p_Var9 = param_4;
  p_Var5 = (_CLIENT_MODULE *)ExAllocatePool2(0x40,0x58,0x614c7846);
  if (p_Var5 == (_CLIENT_MODULE *)0x0) {
    uVar4 = 0xc000009a;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar7 = '\0';
    }
    else {
      uVar7 = '\x01';
    }
    if ((uVar7 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 p_Var9,'\x04',in_stack_ffffffffffffffb0,0x11,
                 WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,0xc000009a);
    }
LAB_140001498:
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar7 = '\0';
    }
    else {
      uVar7 = '\x01';
    }
    if ((uVar7 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 p_Var9,'\x04',in_stack_ffffffffffffffb0,0x14,
                 WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids);
    }
  }
  else {
    (p_Var5->LibraryListEntry).Blink = (_LIST_ENTRY *)p_Var5;
    p_Var9 = (_WDF_BIND_INFO *)&p_Var5->ImageName;
    (p_Var5->LibraryListEntry).Flink = (_LIST_ENTRY *)p_Var5;
    p_Var6 = &p_Var5->ClassListHead;
    (p_Var5->ClassListHead).Blink = p_Var6;
    p_Var6->Flink = p_Var6;
    p_Var5->Context = param_5;
    p_Var5->Globals = (void **)0x0;
    p_Var5->ImageAddress = (void *)0x0;
    p_Var5->ImageSize = 0;
    p_Var5->Info = param_4;
    lVar3 = GetImageName(param_3,param_2,0x634c7846,(_UNICODE_STRING *)p_Var9);
    if (lVar3 < 0) {
      (p_Var5->ImageName).Length = 0;
      (p_Var5->ImageName).MaximumLength = 0;
      *(undefined4 *)&(p_Var5->ImageName).field_0x4 = 0;
      (p_Var5->ImageName).Buffer = (wchar_t *)0x0;
    }
    if ((p_Var5->ImageName).Buffer != (wchar_t *)0x0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 5)) {
        uVar7 = '\0';
      }
      else {
        uVar7 = '\x01';
      }
      if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
         ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
        uVar8 = '\0';
      }
      else {
        uVar8 = '\x01';
      }
      if ((uVar7 != '\0') || (uVar8 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_Z
                  ((WPP_GLOBAL_Control->Control).Logger,uVar7,uVar8,p_Var9,'\x05',
                   in_stack_ffffffffffffffb0,0x12,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,
                   &p_Var5->ImageName);
      }
      uVar4 = GetImageBase(&p_Var5->ImageName,&p_Var5->ImageAddress,&p_Var5->ImageSize);
      if ((int)uVar4 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar7 = '\0';
        }
        else {
          uVar7 = '\x01';
        }
        if ((uVar7 != '\0') ||
           (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_D
                    ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                     WPP_RECORDER_INITIALIZED !=
                     (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,p_Var9,'\x04',
                     in_stack_ffffffffffffffb0,0x13,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,
                     uVar4);
        }
        ClientCleanupAndFree(p_Var5);
        goto LAB_140001498;
      }
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&param_1->ClientsListLock,1);
    p_Var1 = (param_1->ClientsListHead).Flink;
    p_Var6 = &param_1->ClientsListHead;
    if (p_Var1->Blink != p_Var6) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      lVar3 = (*pcVar2)();
      return lVar3;
    }
    (p_Var5->LibraryListEntry).Flink = p_Var1;
    (p_Var5->LibraryListEntry).Blink = p_Var6;
    p_Var1->Blink = (_LIST_ENTRY *)p_Var5;
    p_Var6->Flink = (_LIST_ENTRY *)p_Var5;
    ExReleaseResourceLite(&param_1->ClientsListLock);
    KeLeaveCriticalRegion();
    *param_6 = p_Var5;
    uVar4 = 0;
  }
  return uVar4;
}



===== GetImageBase @ 140001500 =====

long __cdecl GetImageBase(_UNICODE_STRING *param_1,void **param_2,ulong *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uchar uVar4;
  ulong uVar5;
  char *pcVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  size_t _MaxCount;
  WPP_PROJECT_CONTROL_BLOCK *in_R9;
  char *pcVar10;
  bool bVar11;
  ulong local_res20 [2];
  ulong in_stack_ffffffffffffff80;
  ushort uVar12;
  ulong local_58 [2];
  undefined8 *local_50;
  ulonglong local_48;
  char *local_40;
  
  uVar7 = 0;
  *param_2 = (void *)0x0;
  *param_3 = 0;
  local_48 = 0;
  local_40 = (char *)0x0;
  uVar1 = RtlUnicodeStringToAnsiString(&local_48);
  if (((int)uVar1 < 0) || (local_40 == (char *)0x0)) {
    if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
       ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0 ||
        ((WPP_GLOBAL_Control->Control).Level < 4)))) {
      uVar4 = '\0';
    }
    else {
      uVar4 = '\x01';
    }
    if ((uVar4 == '\0') &&
       (WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      return uVar1;
    }
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,uVar4,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffff80,0x56,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
    return uVar1;
  }
  local_40[local_48 & 0xffff] = '\0';
  if (local_40 != (char *)0x0) {
    _MaxCount = 0xffffffffffffffff;
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (local_40[lVar3] != '\0');
    if (lVar3 != 0) {
      for (pcVar10 = local_40 + lVar3; local_40 <= pcVar10; pcVar10 = pcVar10 + -1) {
        if (*pcVar10 == '\\') {
          pcVar10 = pcVar10 + 1;
          goto LAB_1400015af;
        }
      }
      pcVar10 = local_40;
LAB_1400015af:
      if (pcVar10 != (char *)0x0) {
        do {
          _MaxCount = _MaxCount + 1;
        } while (pcVar10[_MaxCount] != '\0');
        pcVar6 = local_40;
        if (_MaxCount != 0) {
          for (; uVar7 < 10; uVar7 = uVar7 + 1) {
            local_58[0] = 0;
            local_res20[0] = 0;
            uVar1 = AuxKlibQueryModuleInformation(local_res20,(ulong)pcVar6,(void *)0x0);
            if (((int)uVar1 < 0) || (local_res20[0] == 0)) {
              if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                 ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0 ||
                  ((WPP_GLOBAL_Control->Control).Level < 4)))) {
                uVar4 = '\0';
              }
              else {
                uVar4 = '\x01';
              }
              bVar11 = WPP_RECORDER_INITIALIZED !=
                       (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
              if ((uVar4 != '\0') || (bVar11)) {
                uVar12 = 0x57;
LAB_14000188e:
                WPP_RECORDER_AND_TRACE_SF_D
                          ((WPP_GLOBAL_Control->Control).Logger,uVar4,bVar11,in_R9,'\x04',
                           in_stack_ffffffffffffff80,uVar12,
                           WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
              }
              break;
            }
            local_58[0] = uVar7 * 0x110 + local_res20[0];
            if (local_58[0] < local_res20[0]) {
              local_58[0] = 0xffffffff;
              if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
                 ((WPP_GLOBAL_Control->Control).Level < 4)) {
                uVar4 = '\0';
              }
              else {
                uVar4 = '\x01';
              }
              in_R9 = WPP_GLOBAL_Control;
              if ((uVar4 != '\0') ||
                 (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED
                 )) {
                WPP_RECORDER_AND_TRACE_SF_D
                          ((WPP_GLOBAL_Control->Control).Logger,uVar4,
                           WPP_RECORDER_INITIALIZED !=
                           (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control
                           ,'\x04',in_stack_ffffffffffffff80,0x58,
                           WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0xc0000095);
              }
            }
            else {
              local_res20[0] = local_58[0];
            }
            uVar5 = local_res20[0];
            local_50 = (undefined8 *)ExAllocatePool2(0x100,local_res20[0],0x334c7846);
            if (local_50 == (undefined8 *)0x0) {
              uVar1 = 0xc000009a;
              if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
                 ((WPP_GLOBAL_Control->Control).Level < 4)) {
                uVar4 = '\0';
              }
              else {
                uVar4 = '\x01';
              }
              bVar11 = WPP_RECORDER_INITIALIZED !=
                       (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
              if ((uVar4 != '\0') || (bVar11)) {
                uVar1 = 0xc000009a;
                uVar12 = 0x59;
                goto LAB_14000188e;
              }
              break;
            }
            local_58[0] = local_res20[0];
            uVar1 = AuxKlibQueryModuleInformation(local_58,uVar5,local_50);
            if (uVar1 != 0xc0000023) {
              if (-1 < (int)uVar1) {
                puVar9 = (undefined8 *)((ulonglong)local_58[0] + (longlong)local_50);
                local_res20[0] = local_58[0];
                puVar8 = local_50;
                goto LAB_1400016a0;
              }
              if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
                 ((WPP_GLOBAL_Control->Control).Level < 4)) {
                uVar4 = '\0';
              }
              else {
                uVar4 = '\x01';
              }
              if ((uVar4 != '\0') ||
                 (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED
                 )) {
                WPP_RECORDER_AND_TRACE_SF_D
                          ((WPP_GLOBAL_Control->Control).Logger,uVar4,
                           WPP_RECORDER_INITIALIZED !=
                           (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                           in_stack_ffffffffffffff80,0x5a,
                           WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
              }
              goto LAB_1400016e8;
            }
            pcVar6 = (char *)0x0;
            ExFreePoolWithTag(local_50);
          }
          goto LAB_1400016fe;
        }
      }
    }
  }
  uVar1 = 0xc0000034;
LAB_1400016fe:
  if (local_40 == (char *)0x0) {
    return uVar1;
  }
  RtlFreeAnsiString(&local_48);
  return uVar1;
LAB_1400016a0:
  if (puVar9 <= puVar8) goto LAB_1400016e8;
  if ((*(ushort *)((longlong)puVar8 + 0xc) < 0x100) &&
     (iVar2 = _strnicmp((char *)((ulonglong)*(ushort *)((longlong)puVar8 + 0xc) + 0xe +
                                (longlong)puVar8),pcVar10,_MaxCount), iVar2 == 0)) {
    *param_2 = (void *)*puVar8;
    *param_3 = *(ulong *)(puVar8 + 1);
    goto LAB_1400016e8;
  }
  puVar8 = puVar8 + 0x22;
  goto LAB_1400016a0;
LAB_1400016e8:
  ExFreePoolWithTag(local_50,0);
  goto LAB_1400016fe;
}



===== ClassLinkInClient @ 140001960 =====

long __cdecl
ClassLinkInClient(_CLASS_MODULE *param_1,_WDF_CLASS_BIND_INFO *param_2,_WDF_BIND_INFO *param_3,
                 _CLASS_CLIENT_MODULE *param_4)

{
  _LIST_ENTRY *p_Var1;
  _LIBRARY_MODULE *p_Var2;
  _LIST_ENTRY *p_Var3;
  ulong64 uVar4;
  code *pcVar5;
  _LIST_ENTRY *p_Var6;
  uchar uVar7;
  undefined1 *puVar8;
  _CLIENT_MODULE *p_Var9;
  undefined1 uVar10;
  undefined7 uVar11;
  _CLASS_CLIENT_MODULE *p_Var12;
  _tlgWrapperByVal<4> local_res8 [2];
  _tlgWrapperByVal<4> local_res10 [4];
  _tlgWrapperByVal<4> local_res20 [2];
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  _tlgWrapSz<unsigned_short> local_48;
  _tlgWrapSz<unsigned_short> local_40;
  _tlgWrapperByVal<8> local_38 [2];
  
  uVar10 = SUB81(param_3,0);
  uVar11 = (undefined7)((ulonglong)param_3 >> 8);
  param_4->Class = param_1;
  param_4->ClientClassBindInfo = param_2;
  p_Var2 = param_1->Library;
  p_Var12 = param_4;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&p_Var2->ClientsListLock);
  puVar8 = auStackY_98;
  p_Var6 = &param_1->Library->ClientsListHead;
  p_Var9 = (_CLIENT_MODULE *)p_Var6->Flink;
  do {
    if (p_Var9 == (_CLIENT_MODULE *)p_Var6) {
LAB_140001b49:
      p_Var2 = param_1->Library;
      *(undefined8 *)(puVar8 + -8) = 0x140001b5b;
      ExReleaseResourceLite(&p_Var2->ClientsListLock);
      *(undefined8 *)(puVar8 + -8) = 0x140001b67;
      KeLeaveCriticalRegion();
LAB_140001b6c:
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar7 = '\0';
      }
      else {
        uVar7 = '\x01';
      }
      if ((uVar7 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar4 = (WPP_GLOBAL_Control->Control).Logger;
        *(_WDF_BIND_INFO **)(puVar8 + 0x40) = param_3;
        *(undefined8 *)(puVar8 + -8) = 0x140001bbb;
        WPP_RECORDER_AND_TRACE_SF_qD
                  (uVar4,uVar7,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,p_Var12,puVar8[0x20],
                   *(ulong *)(puVar8 + 0x28),*(ushort *)(puVar8 + 0x30),*(_GUID **)(puVar8 + 0x38),
                   *(void **)(puVar8 + 0x40),*(uint *)(puVar8 + 0x48));
      }
      return -0x3ffffe7c;
    }
    if (p_Var9->Info == param_3) {
      p_Var6 = &p_Var9->ClassListHead;
      param_4->Client = p_Var9;
      p_Var3 = (p_Var9->ClassListHead).Blink;
      p_Var1 = &param_4->ClassLinkage;
      if (p_Var3->Flink == p_Var6) {
        p_Var1->Flink = p_Var6;
        (param_4->ClassLinkage).Blink = p_Var3;
        p_Var3->Flink = p_Var1;
        (p_Var9->ClassListHead).Blink = p_Var1;
        if (((5 < _Tlgg_TelemetryProviderProv.LevelPlus1) &&
            ((_Tlgg_TelemetryProviderProv.KeywordAny & 0x200000000000) != 0)) &&
           ((_Tlgg_TelemetryProviderProv.KeywordAll & 0x200000000000) ==
            _Tlgg_TelemetryProviderProv.KeywordAll)) {
          local_res8[0].Value = (param_2->Version).Build;
          local_res10[0].Value = (param_2->Version).Minor;
          local_res20[0].Value = (param_2->Version).Major;
          local_48.Psz = (p_Var9->ImageName).Buffer;
          local_40.Psz = (param_1->ImageName).Buffer;
          local_38[0].Value = 0x1000800;
          _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const_*,void_const_*,_GUID_const_*,_GUID_const_*,unsigned_int,_EVENT_DATA_DESCRIPTOR_*),&_tlgWriteTransfer_EtwWriteTransfer,_GUID_const_*,_GUID_const_*>
          ::
          Write<_tlgWrapperByVal<8>,_tlgWrapSz<unsigned_short>,_tlgWrapSz<unsigned_short>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>_>
                    ((_tlgProvider_t *)p_Var6,&_rdata_zETW1._tlgChannel,
                     (_GUID *)CONCAT71(uVar11,uVar10),(_GUID *)p_Var12,local_38,&local_40,&local_48,
                     local_res20,local_res10,local_res8);
        }
        ExReleaseResourceLite(&param_1->Library->ClientsListLock);
        KeLeaveCriticalRegion();
        puVar8 = auStackY_98;
        if (p_Var9 == (_CLIENT_MODULE *)0x0) goto LAB_140001b6c;
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(param_1);
        p_Var6 = (param_1->ClientsListHead).Blink;
        if (p_Var6->Flink == &param_1->ClientsListHead) {
          (param_4->ClientLinkage).Blink = p_Var6;
          (param_4->ClientLinkage).Flink = &param_1->ClientsListHead;
          p_Var6->Flink = &param_4->ClientLinkage;
          (param_1->ClientsListHead).Blink = &param_4->ClientLinkage;
          ExReleaseResourceLite(param_1);
          KeLeaveCriticalRegion();
          return 0;
        }
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar8 = auStackY_90;
      goto LAB_140001b49;
    }
    p_Var9 = (_CLIENT_MODULE *)(p_Var9->LibraryListEntry).Flink;
  } while( true );
}



===== ClassOpen @ 140001be0 =====

long __cdecl ClassOpen(_CLASS_MODULE *param_1)

{
  int iVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  if ((param_1->ControlDeviceName).Buffer == (wchar_t *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = IoGetDeviceObjectPointer
                      (&param_1->ControlDeviceName,1,&param_1->ClassFileObject,local_res8);
    if (-1 < iVar1) {
      param_1->ClassDriverObject = *(_DRIVER_OBJECT **)(local_res8[0] + 8);
    }
  }
  return iVar1;
}



===== WdfVersionBindClass @ 140001c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WdfVersionBindClass(_WDF_BIND_INFO *param_1,void **param_2,_WDF_CLASS_BIND_INFO *param_3)

{
  _CLASS_MODULE *p_Var1;
  long lVar2;
  uint uVar3;
  _CLASS_CLIENT_MODULE *p_Var4;
  _LIST_ENTRY *p_Var5;
  uchar uVar6;
  _WDF_CLASS_BIND_INFO *p_Var7;
  void **ppvVar8;
  uint7 uVar10;
  _WDF_BIND_INFO *p_Var9;
  uchar uVar11;
  wchar_t *in_R9;
  _CLASS_CLIENT_MODULE *p_Var12;
  bool bVar13;
  _CLASS_MODULE *local_res18;
  uchar in_stack_ffffffffffffffa8;
  ulong in_stack_ffffffffffffffb0;
  ushort in_stack_ffffffffffffffb8;
  ushort uVar14;
  _GUID *in_stack_ffffffffffffffc0;
  
                    /* 0x1c50  8  WdfVersionBindClass */
  local_res18 = (_CLASS_MODULE *)0x0;
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 5)) {
    uVar6 = '\0';
  }
  else {
    uVar6 = '\x01';
  }
  if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
     ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
    uVar11 = '\0';
  }
  else {
    uVar11 = '\x01';
  }
  if ((uVar6 != '\0') || (uVar11 != '\0')) {
    in_stack_ffffffffffffffc0 = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
    in_stack_ffffffffffffffb8 = 0x3e;
    in_stack_ffffffffffffffa8 = '\x05';
    WPP_RECORDER_AND_TRACE_SF_
              ((WPP_GLOBAL_Control->Control).Logger,uVar6,uVar11,in_R9,'\x05',
               in_stack_ffffffffffffffb0,0x3e,WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
  }
  if ((param_3 != (_WDF_CLASS_BIND_INFO *)0x0) &&
     (in_R9 = param_3->ClassName, in_R9 != (wchar_t *)0x0)) {
    if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
       ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0 ||
        ((WPP_GLOBAL_Control->Control).Level < 4)))) {
      uVar6 = '\0';
    }
    else {
      uVar6 = '\x01';
    }
    if ((uVar6 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_S
                ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8
                 ,in_stack_ffffffffffffffc0,in_R9);
    }
  }
  p_Var4 = (_CLASS_CLIENT_MODULE *)ExAllocatePool2(0x40,0x38,0x684c7846);
  if (p_Var4 == (_CLASS_CLIENT_MODULE *)0x0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar6 = '\0';
    }
    else {
      uVar6 = '\x01';
    }
    if ((uVar6 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffb0,0x40,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
    }
    return -0x3fffff66;
  }
  (p_Var4->ClientLinkage).Blink = (_LIST_ENTRY *)p_Var4;
  (p_Var4->ClientLinkage).Flink = (_LIST_ENTRY *)p_Var4;
  p_Var5 = &p_Var4->ClassLinkage;
  (p_Var4->ClassLinkage).Blink = p_Var5;
  p_Var5->Flink = p_Var5;
  lVar2 = ReferenceClassVersion(param_3,param_1,&local_res18);
  p_Var1 = local_res18;
  if (lVar2 < 0) {
    ExFreePoolWithTag(p_Var4,0);
    return lVar2;
  }
  p_Var7 = param_3;
  p_Var12 = p_Var4;
  uVar3 = ClassLinkInClient(local_res18,param_3,param_1,p_Var4);
  if ((int)uVar3 < 0) {
    uVar10 = (uint7)((ulonglong)p_Var7 >> 8);
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      p_Var9 = (_WDF_BIND_INFO *)((ulonglong)uVar10 << 8);
    }
    else {
      p_Var9 = (_WDF_BIND_INFO *)CONCAT71(uVar10,1);
    }
    bVar13 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if (((char)p_Var9 != '\0') || (bVar13)) {
      uVar14 = 0x41;
LAB_140001e71:
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,(uchar)p_Var9,bVar13,p_Var12,'\x04',
                 in_stack_ffffffffffffffb0,uVar14,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                 uVar3);
    }
  }
  else {
    p_Var4 = (_CLASS_CLIENT_MODULE *)0x0;
    ppvVar8 = param_2;
    uVar3 = (*p_Var1->ClassLibraryInfo->ClassLibraryBindClient)(param_3,param_2);
    if (-1 < (int)uVar3) goto LAB_140001ea5;
    uVar10 = (uint7)((ulonglong)ppvVar8 >> 8);
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      p_Var9 = (_WDF_BIND_INFO *)((ulonglong)uVar10 << 8);
    }
    else {
      p_Var9 = (_WDF_BIND_INFO *)CONCAT71(uVar10,1);
    }
    bVar13 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if (((char)p_Var9 != '\0') || (bVar13)) {
      uVar14 = 0x42;
      goto LAB_140001e71;
    }
  }
  if (p_Var1 != (_CLASS_MODULE *)0x0) {
    DereferenceClassVersion(param_3,p_Var9,param_2);
  }
  if (p_Var4 != (_CLASS_CLIENT_MODULE *)0x0) {
    ExFreePoolWithTag(p_Var4);
  }
LAB_140001ea5:
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar6 = '\0';
  }
  else {
    uVar6 = '\x01';
  }
  if ((uVar6 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,uVar6,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               p_Var12,'\x04',in_stack_ffffffffffffffb0,0x43,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar3);
  }
  return uVar3;
}



===== ReferenceClassVersion @ 140001f70 =====

long __cdecl
ReferenceClassVersion(_WDF_CLASS_BIND_INFO *param_1,_WDF_BIND_INFO *param_2,_CLASS_MODULE **param_3)

{
  _LIBRARY_MODULE *p_Var1;
  ulong64 uVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  _LIBRARY_MODULE *p_Var6;
  uint uVar7;
  _CLASS_MODULE *p_Var8;
  _LIST_ENTRY *p_Var9;
  _LIST_ENTRY *p_Var10;
  uchar uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  _LIST_ENTRY *p_Var14;
  _CLASS_MODULE **in_R9;
  bool bVar15;
  _LIBRARY_MODULE *local_res18;
  _CLASS_MODULE *local_res20;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  uchar in_stack_ffffffffffffff78;
  ulong in_stack_ffffffffffffff80;
  ushort in_stack_ffffffffffffff88;
  _GUID *in_stack_ffffffffffffff90;
  uint in_stack_ffffffffffffffb0;
  _UNICODE_STRING local_48;
  
  *param_3 = (_CLASS_MODULE *)0x0;
  local_res18 = (_LIBRARY_MODULE *)0x0;
  local_48.Length = 0;
  local_48.MaximumLength = 0;
  local_48._4_4_ = 0;
  local_48.Buffer = (wchar_t *)0x0;
  bVar15 = false;
  bVar4 = false;
  uVar7 = GetClassServicePath(param_1,param_2,&local_48);
  if ((int)uVar7 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar11 = '\0';
    }
    else {
      uVar11 = '\x01';
    }
    if ((uVar11 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar11,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffff80,0x31,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar7);
    }
    FxAutoString::~FxAutoString((FxAutoString *)&local_48);
    return uVar7;
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(0x14000d240,1);
  p_Var8 = FindClassByServiceNameLocked(&local_48,&local_res18);
  puVar13 = auStackY_a8;
  if (local_res18 == (_LIBRARY_MODULE *)0x0) {
    local_res18 = param_2->Module;
  }
  p_Var6 = local_res18;
  p_Var1 = param_2->Module;
  local_res20 = p_Var8;
  if (local_res18 != p_Var1) {
    uVar7 = 0xc0000059;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar11 = '\0';
    }
    else {
      uVar11 = '\x01';
    }
    if ((uVar11 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_SqqD
                ((WPP_GLOBAL_Control->Control).Logger,uVar11,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,
                 in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,param_1->ClassName,local_res18,
                 p_Var1,in_stack_ffffffffffffffb0);
    }
    p_Var8 = (_CLASS_MODULE *)0x0;
    ExReleaseResourceLite(0x14000d240);
    KeLeaveCriticalRegion();
    puVar13 = auStackY_a8;
    goto LAB_14000239a;
  }
  if (p_Var8 == (_CLASS_MODULE *)0x0) {
    in_R9 = &local_res20;
    uVar7 = ClassCreate((_WDF_CLASS_LIBRARY_INFO *)0x0,local_res18,&local_48,in_R9);
    p_Var8 = local_res20;
    puVar12 = auStackY_a8;
    puVar13 = auStackY_a8;
    if (-1 < (int)uVar7) {
      p_Var14 = &p_Var6->ClassListHead;
      p_Var9 = &local_res20->LibraryLinkage;
      p_Var10 = p_Var14->Flink;
      if (p_Var10->Blink != p_Var14) {
        p_Var10 = (_LIST_ENTRY *)0x3;
        pcVar3 = (code *)swi(0x29);
        p_Var9 = (_LIST_ENTRY *)(*pcVar3)();
        puVar12 = auStackY_a0;
      }
      p_Var9->Flink = p_Var10;
      bVar15 = true;
      p_Var9->Blink = p_Var14;
      p_Var10->Blink = p_Var9;
      p_Var14->Flink = p_Var9;
      puVar13 = puVar12;
    }
  }
  else {
    bVar4 = true;
  }
  if (p_Var8 != (_CLASS_MODULE *)0x0) {
    p_Var8->ClassRefCount = p_Var8->ClassRefCount + 1;
  }
  *(undefined8 *)(puVar13 + -8) = 0x140002197;
  ExReleaseResourceLite(0x14000d240);
  *(undefined8 *)(puVar13 + -8) = 0x1400021a3;
  KeLeaveCriticalRegion();
  bVar5 = bVar15;
  if (bVar4) {
    *(undefined8 *)(puVar13 + -8) = 0x1400021b9;
    ClassLoaderLock(p_Var8);
    bVar5 = true;
    if (p_Var8->ClassLibraryInfo != (_WDF_CLASS_LIBRARY_INFO *)0x0) goto LAB_1400021cd;
    p_Var8->ClassRefCount = p_Var8->ClassRefCount + 1;
LAB_1400021d6:
    *(undefined8 *)(puVar13 + -8) = 0x1400021e2;
    uVar7 = ZwLoadDriver(puVar13 + 0x60);
    if ((int)uVar7 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      bVar15 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((bVar4) || (bVar15)) {
        *(uint *)(puVar13 + 0x48) = uVar7;
        *(undefined1 **)(puVar13 + 0x40) = puVar13 + 0x60;
        *(_GUID **)(puVar13 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar13 + 0x30) = 0x33;
        puVar13[0x20] = 2;
LAB_140002353:
        uVar2 = (WPP_GLOBAL_Control->Control).Logger;
        *(undefined8 *)(puVar13 + -8) = 0x14000235c;
        WPP_RECORDER_AND_TRACE_SF_ZD
                  (uVar2,bVar4,bVar15,in_R9,puVar13[0x20],*(ulong *)(puVar13 + 0x28),
                   *(ushort *)(puVar13 + 0x30),*(_GUID **)(puVar13 + 0x38),
                   *(_UNICODE_STRING **)(puVar13 + 0x40),*(uint *)(puVar13 + 0x48));
      }
LAB_14000235c:
      *(undefined8 *)(puVar13 + -8) = 0x140002364;
      ClassReleaseReference(p_Var8);
      goto LAB_140002364;
    }
    if (p_Var8->ClassLibraryInfo == (_WDF_CLASS_LIBRARY_INFO *)0x0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar11 = '\0';
      }
      else {
        uVar11 = '\x01';
      }
      if ((uVar11 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar2 = (WPP_GLOBAL_Control->Control).Logger;
        *(undefined1 **)(puVar13 + 0x40) = puVar13 + 0x60;
        *(_GUID **)(puVar13 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar13 + 0x30) = 0x34;
        puVar13[0x20] = 4;
        *(undefined8 *)(puVar13 + -8) = 0x1400022d2;
        WPP_RECORDER_AND_TRACE_SF_Z
                  (uVar2,uVar11,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,puVar13[0x20],
                   *(ulong *)(puVar13 + 0x28),*(ushort *)(puVar13 + 0x30),
                   *(_GUID **)(puVar13 + 0x38),*(_UNICODE_STRING **)(puVar13 + 0x40));
      }
      uVar7 = 0xc000035f;
      goto LAB_14000235c;
    }
    *(undefined8 *)(puVar13 + -8) = 0x1400022e4;
    uVar7 = ClassOpen(p_Var8);
    if ((int)uVar7 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      bVar15 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((bVar4 != false) || (bVar15)) {
        *(uint *)(puVar13 + 0x48) = uVar7;
        *(_UNICODE_STRING **)(puVar13 + 0x40) = &p_Var8->ControlDeviceName;
        *(_GUID **)(puVar13 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar13 + 0x30) = 0x35;
        puVar13[0x20] = 4;
        goto LAB_140002353;
      }
      goto LAB_14000235c;
    }
LAB_140002368:
    param_1->ClassModule = p_Var8;
    p_Var8->ClientRefCount = p_Var8->ClientRefCount + 1;
    *param_3 = p_Var8;
  }
  else {
LAB_1400021cd:
    if (bVar15) goto LAB_1400021d6;
LAB_140002364:
    if (-1 < (int)uVar7) goto LAB_140002368;
  }
  if (bVar5) {
    p_Var8->LoaderThread = (_KTHREAD *)0x0;
    *(undefined8 *)(puVar13 + -8) = 0x140002395;
    KeSetEvent(&p_Var8->LoaderEvent,0,0);
  }
LAB_14000239a:
  if (p_Var8 != (_CLASS_MODULE *)0x0) {
    *(undefined8 *)(puVar13 + -8) = 0x1400023a7;
    ClassReleaseReference(p_Var8);
  }
  if (*(longlong *)(puVar13 + 0x68) != 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1400023ba;
    ExFreePoolWithTag(*(longlong *)(puVar13 + 0x68),0);
  }
  return uVar7;
}



===== GetClassServicePath @ 1400023e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400026cb) */

long __cdecl
GetClassServicePath(_WDF_CLASS_BIND_INFO *param_1,_WDF_BIND_INFO *param_2,_UNICODE_STRING *param_3)

{
  ulong *puVar1;
  _WDF_CLASS_BIND_INFO *p_Var2;
  uint uVar3;
  wchar_t *pwVar4;
  uchar uVar5;
  longlong lVar6;
  _KEY_VALUE_PARTIAL_INFORMATION *p_Var7;
  longlong lVar8;
  _GUID *in_R9;
  void *pvVar9;
  bool bVar10;
  undefined1 auStackY_158 [32];
  ulong in_stack_fffffffffffffed0;
  ushort uVar11;
  _GUID *p_Var12;
  _UNICODE_STRING local_108;
  undefined8 local_f8;
  uchar *puStack_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  longlong local_e0;
  _UNICODE_STRING *local_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  _UNICODE_STRING local_a0;
  void *local_90;
  _UNICODE_STRING local_88;
  _UNICODE_STRING local_78;
  _WDF_CLASS_BIND_INFO *local_68;
  _WDF_BIND_INFO *local_60;
  wchar_t local_58 [12];
  ulonglong local_40;
  
  local_a0.Buffer = local_58;
  local_40 = __security_cookie ^ (ulonglong)auStackY_158;
  local_78.Length = 0xe;
  local_78.MaximumLength = 0x10;
  local_78._4_4_ = 0;
  local_f8 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
  local_78.Buffer = L"Service";
  local_b8 = 0;
  local_88.Buffer = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Wdf\\Kmdf";
  local_b0 = 0;
  local_d8 = &local_88;
  local_a8 = 0;
  p_Var7 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
  local_90 = (void *)0x0;
  param_3->Length = 0;
  param_3->MaximumLength = 0;
  *(undefined4 *)&param_3->field_0x4 = 0;
  param_3->Buffer = (wchar_t *)0x0;
  pvVar9 = (void *)0x0;
  local_e0 = 0;
  local_e8 = 0x30;
  uStack_e4 = 0;
  local_108.Length = 0;
  local_108.MaximumLength = 0;
  local_108._4_4_ = 0;
  local_108.Buffer = (wchar_t *)0x0;
  local_d0 = 0x240;
  uStack_cc = 0;
  local_88.Length = 0x76;
  local_88.MaximumLength = 0x78;
  local_88._4_4_ = 0;
  local_a0.Length = 0;
  local_a0.MaximumLength = 0x16;
  local_a0._4_4_ = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_68 = param_1;
  local_60 = param_2;
  uVar3 = ZwOpenKey(&local_b8,1,&local_e8);
  lVar6 = -1;
  if (-1 < (int)uVar3) {
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (param_1->ClassName[lVar8] != L'\0');
    uVar11 = ((short)lVar8 + 10) * 2;
    local_108.Buffer = (wchar_t *)ExAllocatePool2(0x100,uVar11,0x624c7846);
    if (local_108.Buffer == (wchar_t *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      local_108.MaximumLength = uVar11;
      uVar3 = RtlUnicodeStringPrintf(&local_108,L"%s\\Versions");
      if (-1 < (int)uVar3) {
        local_e0 = local_b8;
        local_d8 = &local_108;
        local_e8 = 0x30;
        local_d0 = 0x240;
        local_c8 = 0;
        uStack_c0 = 0;
        uVar3 = ZwOpenKey(&local_b0,1,&local_e8);
        if (-1 < (int)uVar3) {
          uVar3 = RtlIntegerToUnicodeString((param_1->Version).Major,10,&local_a0);
          if (-1 < (int)uVar3) {
            local_e0 = local_b0;
            local_d8 = &local_a0;
            local_e8 = 0x30;
            local_d0 = 0x240;
            local_c8 = 0;
            uStack_c0 = 0;
            uVar3 = ZwOpenKey(&local_a8,1,&local_e8);
            if (-1 < (int)uVar3) {
              uVar3 = RtlIntegerToUnicodeString((param_2->Version).Major,10,&local_a0);
              if (-1 < (int)uVar3) {
                local_e0 = local_a8;
                local_d8 = &local_a0;
                local_e8 = 0x30;
                local_d0 = 0x240;
                local_c8 = 0;
                uStack_c0 = 0;
                uVar3 = ZwOpenKey(&local_90,1,&local_e8);
                pvVar9 = local_90;
              }
            }
          }
        }
      }
    }
  }
  if (local_b8 != 0) {
    ZwClose();
  }
  if (local_b0 != 0) {
    ZwClose();
  }
  if (local_a8 != 0) {
    ZwClose();
  }
  if (local_108.Buffer != (wchar_t *)0x0) {
    ExFreePoolWithTag(local_108.Buffer);
    local_108.Length = 0;
    local_108.MaximumLength = 0;
    local_108._4_4_ = 0;
    local_108.Buffer = (wchar_t *)0x0;
  }
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar5 = '\0';
    }
    else {
      uVar5 = '\x01';
    }
    bVar10 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if ((uVar5 != '\0') || (bVar10)) {
      p_Var12 = WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids;
      uVar11 = 0x12;
LAB_14000295c:
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar5,bVar10,in_R9,'\x04',
                 in_stack_fffffffffffffed0,uVar11,p_Var12,uVar3);
    }
  }
  else {
    uVar3 = FxLdrQueryData(pvVar9,&local_78,0x674c7846,(_KEY_VALUE_PARTIAL_INFORMATION **)&local_f8)
    ;
    p_Var7 = local_f8;
    in_R9 = WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids;
    if ((int)uVar3 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if ((bVar10 != false) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        p_Var12 = WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids;
        uVar11 = 0x11;
        goto LAB_1400028ed;
      }
    }
    else {
      puVar1 = &local_f8->Type;
      local_f8 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
      puStack_f0 = (uchar *)0x0;
      if (*puVar1 - 1 < 2) {
        uVar3 = p_Var7->DataLength;
        if (uVar3 - 1 < 0xffff) {
          uVar11 = (ushort)uVar3;
          puStack_f0 = p_Var7->Data;
          local_f8 = (_KEY_VALUE_PARTIAL_INFORMATION *)(ulonglong)CONCAT22(uVar11,uVar11);
          if ((1 < uVar11) &&
             (*(short *)(p_Var7->Data + (ulonglong)((uVar3 & 0xffff) >> 1) * 2 + -2) == 0)) {
            uVar3 = (uint)(ushort)(uVar11 - 2);
            local_f8 = (_KEY_VALUE_PARTIAL_INFORMATION *)(ulonglong)CONCAT22(uVar11,uVar11 - 2);
          }
          uVar11 = (short)uVar3 + 0x6a;
          pwVar4 = (wchar_t *)ExAllocatePool2(0x100,uVar11,0x304c7846);
          if (pwVar4 != (wchar_t *)0x0) {
            param_3->MaximumLength = uVar11;
            param_3->Length = 0;
            param_3->Buffer = pwVar4;
            uVar3 = RtlUnicodeStringPrintf
                              (param_3,
                               L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%wZ");
            if ((int)uVar3 < 0) {
              ExFreePoolWithTag(pwVar4,0);
              param_3->Length = 0;
              param_3->MaximumLength = 0;
              *(undefined4 *)&param_3->field_0x4 = 0;
              param_3->Buffer = (wchar_t *)0x0;
            }
            goto LAB_1400028fb;
          }
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 4)) {
            uVar5 = '\0';
          }
          else {
            uVar5 = '\x01';
          }
          bVar10 = WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
          if ((uVar5 != '\0') || (bVar10)) {
            uVar3 = 0xc000009a;
            p_Var12 = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
            uVar11 = 0x26;
            goto LAB_14000295c;
          }
          goto LAB_14000296a;
        }
        uVar3 = 0xc000000d;
      }
      else {
        uVar3 = 0xc0000024;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if ((bVar10) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        p_Var12 = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        uVar11 = 0x25;
LAB_1400028ed:
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,bVar10,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                   WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,'\x04',in_stack_fffffffffffffed0,
                   uVar11,p_Var12,uVar3);
      }
    }
LAB_1400028fb:
    if (-1 < (int)uVar3) goto LAB_140002a4b;
  }
LAB_14000296a:
  p_Var2 = local_68;
  do {
    lVar6 = lVar6 + 1;
  } while (local_68->ClassName[lVar6] != L'\0');
  uVar11 = ((short)lVar6 + 0x4a) * 2;
  pwVar4 = (wchar_t *)ExAllocatePool2(0x100,uVar11,0x394c7846);
  param_3->Buffer = pwVar4;
  if (pwVar4 == (wchar_t *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    param_3->MaximumLength = uVar11;
    in_R9 = (_GUID *)(ulonglong)(p_Var2->Version).Major;
    uVar3 = RtlUnicodeStringPrintf
                      (param_3,
                       L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%ws%02d%02d");
    if (-1 < (int)uVar3) goto LAB_140002a4b;
    ExFreePoolWithTag(param_3->Buffer);
    param_3->Length = 0;
    param_3->MaximumLength = 0;
    *(undefined4 *)&param_3->field_0x4 = 0;
    param_3->Buffer = (wchar_t *)0x0;
  }
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar5 = '\0';
  }
  else {
    uVar5 = '\x01';
  }
  if ((uVar5 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,uVar5,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_fffffffffffffed0,0x13,
               WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,uVar3);
  }
LAB_140002a4b:
  if (pvVar9 != (void *)0x0) {
    ZwClose(pvVar9);
  }
  if (p_Var7 != (_KEY_VALUE_PARTIAL_INFORMATION *)0x0) {
    ExFreePoolWithTag(p_Var7,0);
  }
  return uVar3;
}



===== ReferenceVersion @ 140002ab0 =====

long __cdecl ReferenceVersion(_WDF_BIND_INFO *param_1,_LIBRARY_MODULE **param_2)

{
  ulong64 uVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  _LIBRARY_MODULE *p_Var7;
  _LIST_ENTRY *p_Var8;
  _LIST_ENTRY *p_Var9;
  uchar uVar10;
  _LIST_ENTRY *p_Var11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  void *in_R9;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  ulong in_stack_ffffffffffffffa0;
  _UNICODE_STRING local_38;
  
  *param_2 = (_LIBRARY_MODULE *)0x0;
  bVar4 = false;
  local_38.Length = 0;
  local_38.MaximumLength = 0;
  local_38._4_4_ = 0;
  local_38.Buffer = (wchar_t *)0x0;
  uVar6 = GetVersionServicePath(param_1,&local_38);
  if ((int)uVar6 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar10 = '\0';
    }
    else {
      uVar10 = '\x01';
    }
    if ((uVar10 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar10,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffa0,0x2e,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar6);
    }
    if (local_38.Buffer == (wchar_t *)0x0) {
      return uVar6;
    }
    ExFreePoolWithTag(local_38.Buffer,0);
    return uVar6;
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(0x14000d240);
  p_Var7 = FindModuleByServiceNameLocked(&local_38);
  puVar12 = auStackY_88;
  if (p_Var7 == (_LIBRARY_MODULE *)0x0) {
    p_Var7 = LibraryCreate((_WDF_LIBRARY_INFO *)0x0,&local_38);
    puVar12 = auStackY_88;
    puVar13 = auStackY_88;
    if (p_Var7 == (_LIBRARY_MODULE *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      p_Var11 = &WdfLdrGlobals.LoadedModuleList;
      p_Var8 = &p_Var7->LibraryListEntry;
      p_Var9 = WdfLdrGlobals.LoadedModuleList.Flink;
      if ((WdfLdrGlobals.LoadedModuleList.Flink)->Blink != &WdfLdrGlobals.LoadedModuleList) {
        p_Var9 = (_LIST_ENTRY *)0x3;
        pcVar2 = (code *)swi(0x29);
        p_Var8 = (_LIST_ENTRY *)(*pcVar2)();
        puVar13 = auStackY_80;
      }
      p_Var8->Flink = p_Var9;
      bVar4 = true;
      p_Var8->Blink = p_Var11;
      p_Var9->Blink = p_Var8;
      puVar12 = puVar13;
      WdfLdrGlobals.LoadedModuleList.Flink = p_Var8;
    }
    bVar3 = false;
    if (p_Var7 != (_LIBRARY_MODULE *)0x0) goto LAB_140002b98;
    *(undefined8 *)(puVar12 + -8) = 0x140002cc6;
    ExReleaseResourceLite(0x14000d240);
    *(undefined8 *)(puVar12 + -8) = 0x140002cd2;
    KeLeaveCriticalRegion();
    bVar5 = bVar4;
LAB_140002bc6:
    if (bVar4) goto LAB_140002c5e;
    if ((int)uVar6 < 0) goto LAB_140002bdd;
LAB_140002bd3:
    param_1->Module = p_Var7;
    p_Var7->ClientRefCount = p_Var7->ClientRefCount + 1;
    *param_2 = p_Var7;
  }
  else {
    bVar3 = true;
LAB_140002b98:
    p_Var7->LibraryRefCount = p_Var7->LibraryRefCount + 1;
    *(undefined8 *)(puVar12 + -8) = 0x140002ba8;
    ExReleaseResourceLite(0x14000d240);
    *(undefined8 *)(puVar12 + -8) = 0x140002bb4;
    KeLeaveCriticalRegion();
    bVar5 = bVar4;
    if (!bVar3) goto LAB_140002bc6;
    *(undefined8 *)(puVar12 + -8) = 0x140002c4f;
    LibraryLoaderLock(p_Var7);
    bVar5 = true;
    if (p_Var7->LibraryInfo != (_WDF_LIBRARY_INFO *)0x0) goto LAB_140002bc6;
    p_Var7->LibraryRefCount = p_Var7->LibraryRefCount + 1;
LAB_140002c5e:
    *(undefined8 *)(puVar12 + -8) = 0x140002c6a;
    uVar6 = ZwLoadDriver(puVar12 + 0x50);
    if ((int)uVar6 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) {
        uVar10 = '\0';
      }
      else {
        uVar10 = '\x01';
      }
      if ((uVar10 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar1 = (WPP_GLOBAL_Control->Control).Logger;
        *(uint *)(puVar12 + 0x48) = uVar6;
        *(undefined1 **)(puVar12 + 0x40) = puVar12 + 0x50;
        *(_GUID **)(puVar12 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar12 + 0x30) = 0x2f;
        puVar12[0x20] = 2;
        *(undefined8 *)(puVar12 + -8) = 0x140002dcd;
        WPP_RECORDER_AND_TRACE_SF_ZD
                  (uVar1,uVar10,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,puVar12[0x20],
                   *(ulong *)(puVar12 + 0x28),*(ushort *)(puVar12 + 0x30),
                   *(_GUID **)(puVar12 + 0x38),*(_UNICODE_STRING **)(puVar12 + 0x40),
                   *(uint *)(puVar12 + 0x48));
      }
    }
    else {
      if (p_Var7->LibraryInfo != (_WDF_LIBRARY_INFO *)0x0) goto LAB_140002bd3;
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar10 = '\0';
      }
      else {
        uVar10 = '\x01';
      }
      if ((uVar10 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar1 = (WPP_GLOBAL_Control->Control).Logger;
        *(undefined1 **)(puVar12 + 0x40) = puVar12 + 0x50;
        *(_GUID **)(puVar12 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar12 + 0x30) = 0x30;
        puVar12[0x20] = 4;
        *(undefined8 *)(puVar12 + -8) = 0x140002e45;
        WPP_RECORDER_AND_TRACE_SF_Z
                  (uVar1,uVar10,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,puVar12[0x20],
                   *(ulong *)(puVar12 + 0x28),*(ushort *)(puVar12 + 0x30),
                   *(_GUID **)(puVar12 + 0x38),*(_UNICODE_STRING **)(puVar12 + 0x40));
      }
      uVar6 = 0xc000035f;
    }
    *(undefined8 *)(puVar12 + -8) = 0x140002e52;
    LibraryReleaseReference(p_Var7);
  }
LAB_140002bdd:
  if (bVar5) {
    p_Var7->LoaderThread = (_KTHREAD *)0x0;
    *(undefined8 *)(puVar12 + -8) = 0x140002c36;
    KeSetEvent(&p_Var7->LoaderEvent,0,0);
  }
  if (p_Var7 != (_LIBRARY_MODULE *)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x140002c45;
    LibraryReleaseReference(p_Var7);
  }
  if (*(longlong *)(puVar12 + 0x58) != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140002bfa;
    ExFreePoolWithTag(*(longlong *)(puVar12 + 0x58),0);
  }
  return uVar6;
}



===== GetVersionServicePath @ 140002e60 =====

long __cdecl GetVersionServicePath(_WDF_BIND_INFO *param_1,_UNICODE_STRING *param_2)

{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  wchar_t *pwVar4;
  uchar uVar5;
  undefined1 auVar6 [8];
  uchar uVar7;
  WPP_PROJECT_CONTROL_BLOCK *pWVar8;
  void *local_res18;
  undefined1 local_res20 [8];
  ulong in_stack_ffffffffffffff80;
  ushort uVar9;
  _UNICODE_STRING local_48;
  
  local_48.Length = 0xe;
  local_48.MaximumLength = 0x10;
  local_48._4_4_ = 0;
  local_48.Buffer = L"Service";
  local_res18 = (void *)0x0;
  auVar6 = (undefined1  [8])0x0;
  local_res20 = (undefined1  [8])0x0;
  uVar3 = GetVersionRegistryHandle(param_1,&local_res18);
  pvVar2 = local_res18;
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar5 = '\0';
    }
    else {
      uVar5 = '\x01';
    }
    pWVar8 = WPP_GLOBAL_Control;
    if ((uVar5 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar5,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',in_stack_ffffffffffffff80,0x28,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar3);
    }
  }
  else {
    pWVar8 = (WPP_PROJECT_CONTROL_BLOCK *)local_res20;
    uVar3 = FxLdrQueryData(local_res18,&local_48,0x344c7846,
                           (_KEY_VALUE_PARTIAL_INFORMATION **)pWVar8);
    auVar6 = local_res20;
    if ((int)uVar3 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1 != false) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar9 = 0x27;
        goto LAB_1400031a5;
      }
    }
    else {
      if (*(int *)((longlong)local_res20 + 4) - 1U < 2) {
        uVar3 = *(uint *)((longlong)local_res20 + 8);
        if (uVar3 - 1 < 0xffff) {
          if ((1 < (ushort)uVar3) &&
             (*(short *)((longlong)local_res20 + (ulonglong)((uVar3 & 0xffff) >> 1) * 2 + 10) == 0))
          {
            uVar3 = (uint)(ushort)((ushort)uVar3 - 2);
          }
          uVar9 = (short)uVar3 + 0x6a;
          pwVar4 = (wchar_t *)ExAllocatePool2(0x100,uVar9,0x384c7846);
          if (pwVar4 != (wchar_t *)0x0) {
            param_2->MaximumLength = uVar9;
            param_2->Length = 0;
            param_2->Buffer = pwVar4;
            uVar3 = RtlUnicodeStringPrintf
                              (param_2,
                               L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%wZ");
            if ((int)uVar3 < 0) {
              ExFreePoolWithTag(pwVar4);
              param_2->Length = 0;
              param_2->MaximumLength = 0;
              *(undefined4 *)&param_2->field_0x4 = 0;
              param_2->Buffer = (wchar_t *)0x0;
            }
            goto LAB_140002fc4;
          }
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 4)) {
            uVar5 = '\0';
          }
          else {
            uVar5 = '\x01';
          }
          if ((uVar5 != '\0') ||
             (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_D
                      ((WPP_GLOBAL_Control->Control).Logger,uVar5,
                       WPP_RECORDER_INITIALIZED !=
                       (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,pWVar8,'\x04',
                       in_stack_ffffffffffffff80,0x26,
                       WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0xc000009a);
          }
          goto LAB_140002fc8;
        }
        uVar3 = 0xc000000d;
      }
      else {
        uVar3 = 0xc0000024;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar9 = 0x25;
LAB_1400031a5:
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,pWVar8,'\x04',
                   in_stack_ffffffffffffff80,uVar9,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar3);
      }
    }
LAB_140002fc4:
    if (-1 < (int)uVar3) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 5)) {
        uVar5 = '\0';
      }
      else {
        uVar5 = '\x01';
      }
      if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
         ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
        uVar7 = '\0';
      }
      else {
        uVar7 = '\x01';
      }
      if ((uVar5 != '\0') || (uVar7 != '\0')) {
        WPP_RECORDER_AND_TRACE_SF_Z
                  ((WPP_GLOBAL_Control->Control).Logger,uVar5,uVar7,pWVar8,'\x05',
                   in_stack_ffffffffffffff80,0x29,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   param_2);
      }
      goto LAB_140002fdd;
    }
  }
LAB_140002fc8:
  uVar3 = GetDefaultServiceName(param_1,param_2);
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar5 = '\0';
    }
    else {
      uVar5 = '\x01';
    }
    if ((uVar5 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar5,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 pWVar8,'\x04',in_stack_ffffffffffffff80,0x2a,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar3);
    }
  }
LAB_140002fdd:
  if (pvVar2 != (void *)0x0) {
    ZwClose(pvVar2);
  }
  if (auVar6 != (undefined1  [8])0x0) {
    ExFreePoolWithTag(auVar6,0);
  }
  return uVar3;
}



===== FindModuleByServiceNameLocked @ 1400032e0 =====

_LIBRARY_MODULE * __cdecl FindModuleByServiceNameLocked(_UNICODE_STRING *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  wchar_t *_Str1;
  wchar_t *_Str2;
  uchar uVar6;
  ulong64 uVar7;
  _LIST_ENTRY *p_Var8;
  _LIBRARY_MODULE *p_Var9;
  ulong64 *puVar10;
  void *in_R9;
  wchar_t *pwVar11;
  uchar in_stack_ffffffffffffffb8;
  ulong in_stack_ffffffffffffffc0;
  int in_stack_ffffffffffffffd8;
  
  _Str1 = (wchar_t *)ExAllocatePool2(0x40,0x202,0x644c7846);
  if (_Str1 == (wchar_t *)0x0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar6 = '\0';
    }
    else {
      uVar6 = '\x01';
    }
    if ((uVar6 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x2b,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,in_stack_ffffffffffffffd8);
    }
    p_Var9 = (_LIBRARY_MODULE *)0x0;
  }
  else {
    puVar10 = (ulong64 *)0x644c7846;
    _Str2 = (wchar_t *)ExAllocatePool2(0x40);
    if (_Str2 == (wchar_t *)0x0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar6 = '\0';
      }
      else {
        uVar6 = '\x01';
      }
      if ((uVar6 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_d
                  ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,
                   in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x2c,
                   WPP_f35a5499df3a35f353983bcad3180794_Traceguids,in_stack_ffffffffffffffd8);
      }
      ExFreePoolWithTag(_Str1,0x644c7846);
      p_Var9 = (_LIBRARY_MODULE *)0x0;
    }
    else {
      *_Str2 = L'\0';
      if (1 < param_1->Length) {
        pwVar2 = param_1->Buffer;
        uVar3 = param_1->Length >> 1;
        pwVar11 = pwVar2 + ((ulonglong)uVar3 - 1);
        wVar1 = pwVar2[(ulonglong)uVar3 - 1];
        while (wVar1 != L'\\') {
          if (pwVar11 == pwVar2) goto LAB_140003376;
          pwVar11 = pwVar11 + -1;
          wVar1 = *pwVar11;
        }
        if ((pwVar11 != pwVar2) && (*pwVar11 == L'\\')) {
          uVar7 = (longlong)((longlong)pwVar2 + ((ulonglong)uVar3 * 2 - (longlong)(pwVar11 + 1))) >>
                  1;
          if ((0x7ffffffe < uVar7) ||
             (lVar4 = RtlStringCopyWorkerW(_Str2,uVar7,puVar10,pwVar11 + 1,uVar7), lVar4 < 0)) {
            *_Str2 = L'\0';
          }
        }
      }
LAB_140003376:
      for (p_Var8 = WdfLdrGlobals.LoadedModuleList.Flink; p_Var8 != &WdfLdrGlobals.LoadedModuleList;
          p_Var8 = p_Var8->Flink) {
        p_Var9 = (_LIBRARY_MODULE *)&p_Var8[-1].Blink;
        GetNameFromUnicodePath((_UNICODE_STRING *)&p_Var8[1].Blink,_Str1,(ulong)puVar10);
        iVar5 = _wcsicmp(_Str1,_Str2);
        if (iVar5 == 0) {
          ExFreePoolWithTag(_Str1,0x644c7846);
          goto LAB_1400033a4;
        }
      }
      ExFreePoolWithTag(_Str1,0x644c7846);
      p_Var9 = (_LIBRARY_MODULE *)0x0;
LAB_1400033a4:
      ExFreePoolWithTag(_Str2,0x644c7846);
    }
  }
  return p_Var9;
}



===== GetVersionRegistryHandle @ 140003550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl GetVersionRegistryHandle(_WDF_BIND_INFO *param_1,void **param_2)

{
  uint uVar1;
  uchar uVar2;
  uchar uVar3;
  void *in_R9;
  bool bVar4;
  undefined1 auStackY_2f8 [32];
  ulong in_stack_fffffffffffffd30;
  ushort uVar5;
  _UNICODE_STRING local_2a8;
  longlong local_298;
  void *local_290;
  undefined4 local_288;
  undefined4 uStack_284;
  longlong lStack_280;
  _UNICODE_STRING *local_278;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined8 local_268;
  undefined8 uStack_260;
  wchar_t local_258 [264];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_2a8.Buffer = local_258;
  local_298 = 0;
  local_290 = (void *)0x0;
  local_288 = 0;
  uStack_284 = 0;
  lStack_280 = 0;
  local_2a8.Length = 0;
  local_2a8.MaximumLength = 0x208;
  local_2a8._4_4_ = 0;
  local_278 = (_UNICODE_STRING *)0x0;
  uStack_270 = 0;
  uStack_26c = 0;
  local_268 = 0;
  uStack_260 = 0;
  uVar1 = RtlUnicodeStringPrintf
                    (&local_2a8,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Wdf\\Kmdf\\%s\\Versions"
                    );
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_fffffffffffffd30,0x1d,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
    }
    goto LAB_1400036e5;
  }
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 5)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
     ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
    uVar3 = '\0';
  }
  else {
    uVar3 = '\x01';
  }
  if ((uVar2 != '\0') || (uVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_Z
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,uVar3,in_R9,'\x05',
               in_stack_fffffffffffffd30,0x1e,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
               &local_2a8);
  }
  local_278 = &local_2a8;
  local_288 = 0x30;
  lStack_280 = 0;
  uStack_270 = 0x240;
  local_268 = 0;
  uStack_260 = 0;
  uVar1 = ZwOpenKey(&local_298,1,&local_288);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    bVar4 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if ((uVar2 == '\0') && (!bVar4)) goto LAB_1400036e5;
    uVar5 = 0x1f;
  }
  else {
    uVar1 = RtlIntegerToUnicodeString((param_1->Version).Major,10,&local_2a8);
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      if ((uVar2 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                   in_stack_fffffffffffffd30,0x20,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar1);
      }
      goto LAB_1400036e5;
    }
    lStack_280 = local_298;
    local_278 = &local_2a8;
    local_288 = 0x30;
    uStack_270 = 0x240;
    local_268 = 0;
    uStack_260 = 0;
    uVar1 = ZwOpenKey(&local_290,0x20019,&local_288);
    if (-1 < (int)uVar1) goto LAB_1400036e5;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    bVar4 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if ((uVar2 == '\0') && (!bVar4)) goto LAB_1400036e5;
    uVar5 = 0x21;
  }
  WPP_RECORDER_AND_TRACE_SF_ZD
            ((WPP_GLOBAL_Control->Control).Logger,uVar2,bVar4,in_R9,'\x04',in_stack_fffffffffffffd30
             ,uVar5,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,&local_2a8,uVar1);
LAB_1400036e5:
  *param_2 = local_290;
  if (local_298 != 0) {
    ZwClose();
  }
  return uVar1;
}



===== RtlUnicodeStringPrintf @ 140003930 =====

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,wchar_t *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  ulonglong uVar6;
  char local_res18 [16];
  
  uVar1 = param_1->Length;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1->MaximumLength, (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((param_1->Buffer != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    lVar5 = 0;
    uVar6 = (ulonglong)(param_1->MaximumLength >> 1);
    iVar3 = _vsnwprintf(param_1->Buffer,uVar6,param_2,local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, uVar6 < (ulonglong)(longlong)iVar3)) {
      lVar5 = -0x7ffffffb;
      uVar4 = uVar6;
    }
    param_1->Length = (short)uVar4 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== FxLdrQueryData @ 1400039e0 =====

long __cdecl
FxLdrQueryData(void *param_1,_UNICODE_STRING *param_2,ulong param_3,
              _KEY_VALUE_PARTIAL_INFORMATION **param_4)

{
  uint uVar1;
  _KEY_VALUE_PARTIAL_INFORMATION *p_Var2;
  uchar uVar3;
  uint local_res20 [2];
  ulong uVar4;
  
  local_res20[0] = 0;
  *param_4 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
  while( true ) {
    uVar4 = (ulong)local_res20;
    uVar1 = ZwQueryValueKey(param_1,param_2,2,0,0);
    if (uVar1 != 0xc0000023) {
      if ((int)uVar1 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar3 = '\0';
        }
        else {
          uVar3 = '\x01';
        }
        if ((uVar3 != '\0') ||
           (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_D
                    ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                     WPP_RECORDER_INITIALIZED !=
                     (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,
                     '\x04',uVar4,0x52,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
        }
      }
      return uVar1;
    }
    uVar1 = local_res20[0] + 0xc;
    if (uVar1 < local_res20[0]) {
      local_res20[0] = 0xffffffff;
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      else {
        uVar3 = '\x01';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   uVar4,0x53,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_2,0xc0000095);
      }
      return -0x3fffff6b;
    }
    local_res20[0] = uVar1;
    p_Var2 = (_KEY_VALUE_PARTIAL_INFORMATION *)ExAllocatePool2(0x100,uVar1,param_3);
    if (p_Var2 == (_KEY_VALUE_PARTIAL_INFORMATION *)0x0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      else {
        uVar3 = '\x01';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   uVar4,0x54,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0xc000009a);
      }
      return -0x3fffff66;
    }
    uVar4 = (ulong)local_res20;
    uVar1 = ZwQueryValueKey(param_1,param_2,2,p_Var2,local_res20[0]);
    if (-1 < (int)uVar1) break;
    ExFreePoolWithTag(p_Var2);
    if (uVar1 != 0xc0000023) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      else {
        uVar3 = '\x01';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   uVar4,0x55,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_2,uVar1);
      }
      return uVar1;
    }
  }
  *param_4 = p_Var2;
  return uVar1;
}



===== GetDefaultServiceName @ 140003d00 =====

long __cdecl GetDefaultServiceName(_WDF_BIND_INFO *param_1,_UNICODE_STRING *param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  uchar uVar3;
  void *in_R9;
  ulong in_stack_ffffffffffffffd0;
  
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x78,0x364c7846);
  if (pwVar2 == (wchar_t *)0x0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar3 = '\0';
    }
    else {
      uVar3 = '\x01';
    }
    if ((uVar3 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffd0,0x22,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0xc000009a);
    }
    uVar1 = 0xc000009a;
  }
  else {
    param_2->Length = 0;
    param_2->MaximumLength = 0x78;
    *(undefined4 *)&param_2->field_0x4 = 0;
    param_2->Buffer = pwVar2;
    uVar1 = RtlUnicodeStringPrintf
                      (param_2,
                       L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Wdf%02d000");
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      else {
        uVar3 = '\x01';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffd0,0x23,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar1);
      }
      ExFreePoolWithTag(pwVar2,0);
      param_2->Length = 0;
      param_2->MaximumLength = 0;
      *(undefined4 *)&param_2->field_0x4 = 0;
      param_2->Buffer = (wchar_t *)0x0;
    }
    else {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      else {
        uVar3 = '\x01';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_Z
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                   in_stack_ffffffffffffffd0,0x24,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   param_2);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== FindClassByServiceNameLocked @ 140003ef0 =====

_CLASS_MODULE * __cdecl
FindClassByServiceNameLocked(_UNICODE_STRING *param_1,_LIBRARY_MODULE **param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  wchar_t *_Str1;
  wchar_t *_Str2;
  uchar uVar6;
  ulong64 uVar7;
  _CLASS_MODULE *p_Var8;
  _LIST_ENTRY *p_Var9;
  ulong64 *puVar10;
  void *in_R9;
  wchar_t *pwVar11;
  _LIST_ENTRY *p_Var12;
  uchar in_stack_ffffffffffffffa8;
  ulong in_stack_ffffffffffffffb0;
  int in_stack_ffffffffffffffc8;
  
  p_Var8 = (_CLASS_MODULE *)0x0;
  _Str1 = (wchar_t *)ExAllocatePool2(0x40,0x202,0x644c7846);
  if (_Str1 == (wchar_t *)0x0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar6 = '\0';
    }
    else {
      uVar6 = '\x01';
    }
    if ((uVar6 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0x14,
                 WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,in_stack_ffffffffffffffc8);
    }
  }
  else {
    puVar10 = (ulong64 *)0x644c7846;
    _Str2 = (wchar_t *)ExAllocatePool2(0x40);
    if (_Str2 == (wchar_t *)0x0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar6 = '\0';
      }
      else {
        uVar6 = '\x01';
      }
      if ((uVar6 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_d
                  ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,
                   in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0x15,
                   WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,in_stack_ffffffffffffffc8);
      }
      ExFreePoolWithTag(_Str1,0x644c7846);
    }
    else {
      *_Str2 = L'\0';
      if (1 < param_1->Length) {
        pwVar2 = param_1->Buffer;
        uVar3 = param_1->Length >> 1;
        pwVar11 = pwVar2 + ((ulonglong)uVar3 - 1);
        wVar1 = pwVar2[(ulonglong)uVar3 - 1];
        while (wVar1 != L'\\') {
          if (pwVar11 == pwVar2) goto LAB_14000409d;
          pwVar11 = pwVar11 + -1;
          wVar1 = *pwVar11;
        }
        if ((pwVar11 != pwVar2) && (*pwVar11 == L'\\')) {
          uVar7 = (longlong)((longlong)pwVar2 + ((ulonglong)uVar3 * 2 - (longlong)(pwVar11 + 1))) >>
                  1;
          if ((0x7ffffffe < uVar7) ||
             (lVar4 = RtlStringCopyWorkerW(_Str2,uVar7,puVar10,pwVar11 + 1,uVar7), lVar4 < 0)) {
            *_Str2 = L'\0';
          }
        }
      }
LAB_14000409d:
      for (p_Var9 = WdfLdrGlobals.LoadedModuleList.Flink; p_Var9 != &WdfLdrGlobals.LoadedModuleList;
          p_Var9 = p_Var9->Flink) {
        for (p_Var12 = p_Var9[0x10].Blink; p_Var12 != (_LIST_ENTRY *)&p_Var9[0x10].Blink;
            p_Var12 = p_Var12->Flink) {
          GetNameFromUnicodePath((_UNICODE_STRING *)(p_Var12 + 1),_Str1,(ulong)puVar10);
          iVar5 = _wcsicmp(_Str1,_Str2);
          if (iVar5 == 0) {
            if (param_2 != (_LIBRARY_MODULE **)0x0) {
              *param_2 = (_LIBRARY_MODULE *)&p_Var9[-1].Blink;
            }
            p_Var8 = (_CLASS_MODULE *)&p_Var12[-8].Blink;
            goto LAB_140004121;
          }
        }
      }
      if (param_2 != (_LIBRARY_MODULE **)0x0) {
        *param_2 = (_LIBRARY_MODULE *)0x0;
      }
LAB_140004121:
      ExFreePoolWithTag(_Str1,0x644c7846);
      ExFreePoolWithTag(_Str2,0x644c7846);
    }
  }
  return p_Var8;
}



===== RtlStringCopyWorkerW @ 140004180 =====

long __cdecl
RtlStringCopyWorkerW
          (wchar_t *param_1,ulong64 param_2,ulong64 *param_3,wchar_t *param_4,ulong64 param_5)

{
  wchar_t wVar1;
  long lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = 0x101;
  lVar5 = (longlong)param_4 - (longlong)param_1;
  do {
    if ((param_5 == 0) || (wVar1 = *(wchar_t *)(lVar5 + (longlong)param_1), wVar1 == L'\0')) break;
    *param_1 = wVar1;
    param_5 = param_5 - 1;
    param_1 = param_1 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  pwVar3 = param_1 + -1;
  if (lVar4 != 0) {
    pwVar3 = param_1;
  }
  lVar2 = -0x7ffffffb;
  if (lVar4 != 0) {
    lVar2 = 0;
  }
  *pwVar3 = L'\0';
  return lVar2;
}



===== DereferenceVersion @ 1400041e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl DereferenceVersion(_WDF_BIND_INFO *param_1,void **param_2)

{
  _LIBRARY_MODULE *p_Var1;
  _CLIENT_MODULE *p_Var2;
  _LIST_ENTRY *p_Var3;
  ulong64 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  uint uVar7;
  uchar uVar8;
  _CLIENT_MODULE *p_Var9;
  undefined1 *puVar10;
  WPP_PROJECT_CONTROL_BLOCK *in_R9;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  ulong in_stack_ffffffffffffffc0;
  
  p_Var1 = param_1->Module;
  if (param_2 != (void **)0x0) {
    uVar7 = (*p_Var1->LibraryInfo->LibraryUnregisterClient)(param_1,param_2);
    if ((int)uVar7 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar8 = '\0';
      }
      else {
        uVar8 = '\x01';
      }
      in_R9 = WPP_GLOBAL_Control;
      if ((uVar8 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar8,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffc0,0x36,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar7);
      }
    }
  }
  puVar10 = auStackY_68;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&p_Var1->ClientsListLock);
  p_Var9 = (_CLIENT_MODULE *)(p_Var1->ClientsListHead).Flink;
  do {
    puVar6 = auStackY_68;
    if (p_Var9 == (_CLIENT_MODULE *)&p_Var1->ClientsListHead) {
LAB_1400043c5:
      puVar10 = puVar6;
      *(undefined8 *)(puVar10 + -8) = 0x1400043d0;
      ExReleaseResourceLite(&p_Var1->ClientsListLock);
      *(undefined8 *)(puVar10 + -8) = 0x1400043dc;
      KeLeaveCriticalRegion();
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar8 = '\0';
      }
      else {
        uVar8 = '\x01';
      }
      if ((uVar8 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar4 = (WPP_GLOBAL_Control->Control).Logger;
        *(_WDF_BIND_INFO **)(puVar10 + 0x48) = param_1;
        *(_LIBRARY_MODULE **)(puVar10 + 0x40) = p_Var1;
        *(undefined8 *)(puVar10 + -8) = 0x140004427;
        WPP_RECORDER_AND_TRACE_SF_qq
                  (uVar4,uVar8,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,puVar10[0x20],
                   *(ulong *)(puVar10 + 0x28),*(ushort *)(puVar10 + 0x30),
                   *(_GUID **)(puVar10 + 0x38),*(void **)(puVar10 + 0x40),*(void **)(puVar10 + 0x48)
                  );
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar8 = '\0';
      }
      else {
        uVar8 = '\x01';
      }
      if ((uVar8 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        uVar4 = (WPP_GLOBAL_Control->Control).Logger;
        *(undefined4 *)(puVar10 + 0x40) = 0xc0000001;
        *(_GUID **)(puVar10 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
        *(undefined2 *)(puVar10 + 0x30) = 0x37;
        puVar10[0x20] = 4;
        *(undefined8 *)(puVar10 + -8) = 0x140004480;
        WPP_RECORDER_AND_TRACE_SF_D
                  (uVar4,uVar8,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,puVar10[0x20],
                   *(ulong *)(puVar10 + 0x28),*(ushort *)(puVar10 + 0x30),
                   *(_GUID **)(puVar10 + 0x38),*(uint *)(puVar10 + 0x40));
      }
LAB_1400042c0:
      *(undefined8 *)(puVar10 + -8) = 0x1400042c7;
      KeEnterCriticalRegion();
      *(undefined8 *)(puVar10 + -8) = 0x1400042dc;
      ExAcquireResourceExclusiveLite(0x14000d240,1);
      p_Var1->LibraryRefCount = p_Var1->LibraryRefCount + 1;
      *(undefined8 *)(puVar10 + -8) = 0x1400042f1;
      ExReleaseResourceLite(0x14000d240);
      *(undefined8 *)(puVar10 + -8) = 0x1400042fd;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar10 + -8) = 0x14000430a;
      LibraryLoaderLock(p_Var1);
      *(undefined8 *)(puVar10 + -8) = 0x140004312;
      LibraryReleaseClientReferenceLocked(p_Var1);
      p_Var1->LoaderThread = (_KTHREAD *)0x0;
      *(undefined8 *)(puVar10 + -8) = 0x14000432e;
      KeSetEvent(&p_Var1->LoaderEvent,0,0);
      *(undefined8 *)(puVar10 + -8) = 0x14000433b;
      LibraryReleaseReference(p_Var1);
      param_1->Module = (_LIBRARY_MODULE *)0x0;
      return 0;
    }
    p_Var2 = (_CLIENT_MODULE *)(p_Var9->LibraryListEntry).Flink;
    if (p_Var9->Info == param_1) {
      if (((_CLIENT_MODULE *)(p_Var2->LibraryListEntry).Blink == p_Var9) &&
         (p_Var3 = (p_Var9->LibraryListEntry).Blink, (_CLIENT_MODULE *)p_Var3->Flink == p_Var9)) {
        p_Var3->Flink = (_LIST_ENTRY *)p_Var2;
        (p_Var2->LibraryListEntry).Blink = p_Var3;
        (p_Var9->LibraryListEntry).Blink = &p_Var9->LibraryListEntry;
        (p_Var9->LibraryListEntry).Flink = &p_Var9->LibraryListEntry;
        ExReleaseResourceLite(&p_Var1->ClientsListLock);
        KeLeaveCriticalRegion();
        ClientCleanupAndFree(p_Var9);
        goto LAB_1400042c0;
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStackY_60;
      goto LAB_1400043c5;
    }
    p_Var9 = p_Var2;
  } while( true );
}



===== ClientCleanupAndFree @ 140004490 =====

void __cdecl ClientCleanupAndFree(_CLIENT_MODULE *param_1)

{
  uchar uVar1;
  void *in_R9;
  ulong in_stack_ffffffffffffffd0;
  
  if ((param_1->ImageName).Buffer != (wchar_t *)0x0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar1 = '\0';
    }
    else {
      uVar1 = '\x01';
    }
    if ((uVar1 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Z
                ((WPP_GLOBAL_Control->Control).Logger,uVar1,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffd0,0x10,
                 WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,&param_1->ImageName);
    }
    ExFreePoolWithTag((param_1->ImageName).Buffer,0);
    (param_1->ImageName).Length = 0;
    (param_1->ImageName).MaximumLength = 0;
    *(undefined4 *)&(param_1->ImageName).field_0x4 = 0;
    (param_1->ImageName).Buffer = (wchar_t *)0x0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== LibraryLoaderLock @ 140004560 =====

void __cdecl LibraryLoaderLock(_LIBRARY_MODULE *param_1)

{
  int iVar1;
  uchar uVar2;
  undefined8 uVar3;
  ulong in_stack_ffffffffffffffc0;
  ushort in_stack_ffffffffffffffc8;
  
  uVar3 = 8;
  iVar1 = KeWaitForSingleObject(&param_1->LoaderEvent,0,0,0);
  while (iVar1 == 0x102) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qZ
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 g_IfrLog,(uchar)uVar3,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                 WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,SystemReserved1[0xf],
                 &param_1->Service);
    }
    uVar3 = 8;
    iVar1 = KeWaitForSingleObject(&param_1->LoaderEvent,0,0,0);
  }
  param_1->LoaderThread = SystemReserved1[0xf];
  return;
}



===== LibraryReleaseReference @ 1400046a0 =====

void __cdecl LibraryReleaseReference(_LIBRARY_MODULE *param_1)

{
  _LIST_ENTRY *p_Var1;
  _LIST_ENTRY *p_Var2;
  _LIST_ENTRY *p_Var3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(0x14000d240,1);
  puVar5 = auStack_28;
  param_1->LibraryRefCount = param_1->LibraryRefCount + -1;
  if (param_1->LibraryRefCount == 0) {
    p_Var2 = (param_1->LibraryListEntry).Flink;
    p_Var1 = &param_1->LibraryListEntry;
    if (p_Var2 != p_Var1) {
      if ((p_Var2->Blink != p_Var1) ||
         (p_Var3 = (param_1->LibraryListEntry).Blink, p_Var3->Flink != p_Var1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar5 = auStack_20;
        goto LAB_140004729;
      }
      p_Var3->Flink = p_Var2;
      p_Var2->Blink = p_Var3;
      (param_1->LibraryListEntry).Blink = p_Var1;
      p_Var1->Flink = p_Var1;
    }
    ExReleaseResourceLite(0x14000d240);
    KeLeaveCriticalRegion();
    LibraryCleanupAndFree(param_1);
  }
  else {
LAB_140004729:
    *(undefined8 *)(puVar5 + -8) = 0x140004737;
    ExReleaseResourceLite(0x14000d240);
    *(undefined8 *)(puVar5 + -8) = 0x140004743;
    KeLeaveCriticalRegion();
  }
  return;
}



===== LibraryReleaseClientReferenceLocked @ 140004760 =====

void __cdecl LibraryReleaseClientReferenceLocked(_LIBRARY_MODULE *param_1)

{
  int iVar1;
  uchar uVar2;
  void *in_R9;
  uchar in_stack_ffffffffffffffc8;
  ulong in_stack_ffffffffffffffd0;
  ushort in_stack_ffffffffffffffd8;
  
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((uVar2 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffd8 = 10;
    in_stack_ffffffffffffffc8 = '\x04';
    WPP_RECORDER_AND_TRACE_SF_Z
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffffd0,10,
               WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,&param_1->Service);
  }
  iVar1 = param_1->ClientRefCount + -1;
  param_1->ClientRefCount = iVar1;
  if (iVar1 == 0) {
    LibraryUnload(param_1);
  }
  else {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Zd
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                 in_stack_ffffffffffffffd8,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,
                 &param_1->Service,iVar1);
    }
  }
  return;
}



===== GetNameFromUnicodePath @ 140004870 =====

void __cdecl GetNameFromUnicodePath(_UNICODE_STRING *param_1,wchar_t *param_2,ulong param_3)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  long lVar4;
  ulong64 *puVar5;
  wchar_t *pwVar6;
  wchar_t wVar7;
  
  wVar7 = L'\0';
  *param_2 = L'\0';
  if (1 < param_1->Length) {
    pwVar2 = param_1->Buffer;
    uVar3 = param_1->Length >> 1;
    pwVar6 = pwVar2 + ((ulonglong)uVar3 - 1);
    wVar1 = pwVar2[(ulonglong)uVar3 - 1];
    while (wVar1 != L'\\') {
      if (pwVar6 == pwVar2) {
        return;
      }
      pwVar6 = pwVar6 + -1;
      wVar1 = *pwVar6;
    }
    if ((pwVar6 != pwVar2) && (*pwVar6 == L'\\')) {
      puVar5 = (ulong64 *)
               ((longlong)((longlong)pwVar2 + ((ulonglong)uVar3 * 2 - (longlong)(pwVar6 + 1))) >> 1)
      ;
      if (((ulong64 *)0x7ffffffe < puVar5) ||
         (wVar7 = L'\0',
         lVar4 = RtlStringCopyWorkerW(param_2,(ulong64)param_2,puVar5,pwVar6 + 1,(ulong64)puVar5),
         lVar4 < 0)) {
        *param_2 = wVar7;
      }
    }
  }
  return;
}



===== RtlUnicodeStringCopy @ 140004900 =====

long __cdecl RtlUnicodeStringCopy(_UNICODE_STRING *param_1,_UNICODE_STRING *param_2)

{
  ushort uVar1;
  ushort uVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  long lVar5;
  ulonglong uVar6;
  short sVar7;
  longlong lVar8;
  
  uVar1 = param_1->Length;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1->MaximumLength, (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((param_1->Buffer != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    sVar7 = 0;
    uVar1 = param_2->Length;
    uVar6 = (ulonglong)(param_1->MaximumLength >> 1);
    if (((((uVar1 & 1) == 0) && (uVar2 = param_2->MaximumLength, (uVar2 & 1) == 0)) &&
        ((uVar2 != 0xffff && (uVar1 <= uVar2)))) &&
       ((param_2->Buffer != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
      pwVar3 = param_2->Buffer;
      lVar5 = 0;
      uVar4 = (ulonglong)(uVar1 >> 1);
      sVar7 = 0;
      if (uVar6 != 0) {
        lVar8 = (longlong)param_1->Buffer - (longlong)pwVar3;
        do {
          if (uVar4 == 0) goto LAB_1400049b8;
          uVar4 = uVar4 - 1;
          *(wchar_t *)(lVar8 + (longlong)pwVar3) = *pwVar3;
          sVar7 = sVar7 + 1;
          pwVar3 = pwVar3 + 1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      lVar5 = 0;
      if (uVar4 != 0) {
        lVar5 = -0x7ffffffb;
      }
    }
    else {
      lVar5 = -0x3ffffff3;
    }
LAB_1400049b8:
    param_1->Length = sVar7 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== GetNameFromPath @ 140004a00 =====

void __cdecl GetNameFromPath(_UNICODE_STRING *param_1,_UNICODE_STRING *param_2)

{
  bool bVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  
  if (param_1->Length < 2) {
    param_2->Length = 0;
    param_2->MaximumLength = 0;
    *(undefined4 *)&param_2->field_0x4 = 0;
    param_2->Buffer = (wchar_t *)0x0;
    return;
  }
  pwVar2 = (wchar_t *)((longlong)param_1->Buffer + ((ulonglong)(uint)param_1->Length - 2));
  param_2->Buffer = pwVar2;
  bVar1 = false;
  uVar3 = 2;
  do {
    param_2->Length = uVar3;
    if (pwVar2 < param_1->Buffer) {
LAB_140004a5e:
      if (!bVar1) {
        uVar3 = uVar3 - 2;
        param_2->Length = uVar3;
        param_2->Buffer = pwVar2 + 1;
      }
LAB_140004a66:
      param_2->MaximumLength = uVar3;
      return;
    }
    if (*pwVar2 == L'\\') {
      pwVar2 = pwVar2 + 1;
      uVar3 = uVar3 - 2;
      param_2->Buffer = pwVar2;
      bVar1 = true;
      param_2->Length = uVar3;
      if (uVar3 == 2) {
        uVar3 = 0;
        param_2->Length = 0;
        param_2->Buffer = (wchar_t *)0x0;
        goto LAB_140004a66;
      }
      goto LAB_140004a5e;
    }
    pwVar2 = pwVar2 + -1;
    param_2->Buffer = pwVar2;
    uVar3 = uVar3 + 2;
  } while( true );
}



===== DereferenceClassVersion @ 140004aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
DereferenceClassVersion(_WDF_CLASS_BIND_INFO *param_1,_WDF_BIND_INFO *param_2,void **param_3)

{
  _CLASS_MODULE *p_Var1;
  _func___cdecl_void__WDF_CLASS_BIND_INFO_ptr_void_ptr_ptr *p_Var2;
  
  p_Var1 = param_1->ClassModule;
  if (p_Var1 != (_CLASS_MODULE *)0x0) {
    p_Var2 = p_Var1->ClassLibraryInfo->ClassLibraryUnbindClient;
    if (p_Var2 != (_func___cdecl_void__WDF_CLASS_BIND_INFO_ptr_void_ptr_ptr *)0x0) {
      (*p_Var2)(param_1,param_3);
    }
    ClassUnlinkClient(p_Var1,param_1);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(0x14000d240,1);
    p_Var1->ClassRefCount = p_Var1->ClassRefCount + 1;
    ExReleaseResourceLite(0x14000d240);
    KeLeaveCriticalRegion();
    ClassLoaderLock(p_Var1);
    ClassReleaseClientReferenceLocked(p_Var1);
    p_Var1->LoaderThread = (_KTHREAD *)0x0;
    KeSetEvent(&p_Var1->LoaderEvent,0,0);
    ClassReleaseReference(p_Var1);
    param_1->ClassModule = (void *)0x0;
  }
  return;
}



===== ClassReleaseClientReferenceLocked @ 140004b80 =====

void __cdecl ClassReleaseClientReferenceLocked(_CLASS_MODULE *param_1)

{
  int iVar1;
  uchar uVar2;
  void *in_R9;
  uchar in_stack_ffffffffffffffc8;
  ulong in_stack_ffffffffffffffd0;
  ushort in_stack_ffffffffffffffd8;
  
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((uVar2 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    in_stack_ffffffffffffffd8 = 10;
    in_stack_ffffffffffffffc8 = '\x04';
    WPP_RECORDER_AND_TRACE_SF_Z
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffffd0,10,
               WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,&param_1->Service);
  }
  iVar1 = param_1->ClientRefCount + -1;
  param_1->ClientRefCount = iVar1;
  if (iVar1 == 0) {
    ClassUnload(param_1);
  }
  else {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Zd
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                 in_stack_ffffffffffffffd8,WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,
                 &param_1->Service,iVar1);
    }
  }
  return;
}



===== ClassLoaderLock @ 140004c90 =====

void __cdecl ClassLoaderLock(_CLASS_MODULE *param_1)

{
  int iVar1;
  uchar uVar2;
  undefined8 uVar3;
  ulong in_stack_ffffffffffffffc0;
  ushort in_stack_ffffffffffffffc8;
  
  uVar3 = 8;
  iVar1 = KeWaitForSingleObject(&param_1->LoaderEvent,0,0,0);
  while (iVar1 == 0x102) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qZ
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 g_IfrLog,(uchar)uVar3,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                 WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,SystemReserved1[0xf],
                 &param_1->Service);
    }
    uVar3 = 8;
    iVar1 = KeWaitForSingleObject(&param_1->LoaderEvent,0,0,0);
  }
  param_1->LoaderThread = SystemReserved1[0xf];
  return;
}



===== ClassUnlinkClient @ 140004dd0 =====

void __cdecl ClassUnlinkClient(_CLASS_MODULE *param_1,_WDF_CLASS_BIND_INFO *param_2)

{
  _LIST_ENTRY *p_Var1;
  _LIST_ENTRY *p_Var2;
  _LIBRARY_MODULE *p_Var3;
  _LIST_ENTRY *p_Var4;
  code *pcVar5;
  undefined1 *puVar6;
  _LIST_ENTRY *p_Var7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(param_1,1);
  puVar6 = auStack_28;
  p_Var7 = (param_1->ClientsListHead).Flink;
  do {
    if (p_Var7 == &param_1->ClientsListHead) {
LAB_140004ef7:
      *(undefined8 *)(puVar6 + -8) = 0x140004f01;
      ExReleaseResourceLite(param_1);
      *(undefined8 *)(puVar6 + -8) = 0x140004f0d;
      KeLeaveCriticalRegion();
      return;
    }
    p_Var1 = p_Var7->Flink;
    if ((_WDF_CLASS_BIND_INFO *)p_Var7[3].Flink == param_2) {
      if ((p_Var1->Blink == p_Var7) && (p_Var2 = p_Var7->Blink, p_Var2->Flink == p_Var7)) {
        p_Var2->Flink = p_Var1;
        p_Var1->Blink = p_Var2;
        p_Var7->Blink = p_Var7;
        p_Var7->Flink = p_Var7;
        ExReleaseResourceLite(param_1);
        KeLeaveCriticalRegion();
        p_Var3 = param_1->Library;
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(&p_Var3->ClientsListLock,1);
        p_Var2 = p_Var7[1].Flink;
        p_Var1 = p_Var7 + 1;
        if ((p_Var2->Blink == p_Var1) && (p_Var4 = p_Var7[1].Blink, p_Var4->Flink == p_Var1)) {
          p_Var4->Flink = p_Var2;
          p_Var2->Blink = p_Var4;
          p_Var7[1].Blink = p_Var1;
          p_Var1->Flink = p_Var1;
          ExReleaseResourceLite(&param_1->Library->ClientsListLock);
          KeLeaveCriticalRegion();
          ExFreePoolWithTag(p_Var7,0);
          return;
        }
      }
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_140004ef7;
    }
    p_Var7 = p_Var1;
  } while( true );
}



===== ClassReleaseReference @ 140004f30 =====

void __cdecl ClassReleaseReference(_CLASS_MODULE *param_1)

{
  _LIST_ENTRY *p_Var1;
  long *plVar2;
  _LIST_ENTRY *p_Var3;
  _LIST_ENTRY *p_Var4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(0x14000d240,1);
  puVar6 = auStack_28;
  plVar2 = &param_1->ClassRefCount;
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    p_Var3 = (param_1->LibraryLinkage).Flink;
    p_Var1 = &param_1->LibraryLinkage;
    if (p_Var3 != p_Var1) {
      if ((p_Var3->Blink != p_Var1) ||
         (p_Var4 = (param_1->LibraryLinkage).Blink, p_Var4->Flink != p_Var1)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar6 = auStack_20;
        goto LAB_140004fc2;
      }
      p_Var4->Flink = p_Var3;
      p_Var3->Blink = p_Var4;
      (param_1->LibraryLinkage).Blink = p_Var1;
      p_Var1->Flink = p_Var1;
    }
    ExReleaseResourceLite(0x14000d240);
    KeLeaveCriticalRegion();
    ClassCleanupAndFree(param_1);
  }
  else {
LAB_140004fc2:
    *(undefined8 *)(puVar6 + -8) = 0x140004fd0;
    ExReleaseResourceLite(0x14000d240);
    *(undefined8 *)(puVar6 + -8) = 0x140004fdc;
    KeLeaveCriticalRegion();
  }
  return;
}



===== ~FxAutoString @ 140004ff0 =====

void __thiscall FxAutoString::~FxAutoString(FxAutoString *this)

{
  wchar_t *pwVar1;
  
  pwVar1 = (this->m_UnicodeString).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (this->m_UnicodeString).Length = 0;
    (this->m_UnicodeString).MaximumLength = 0;
    *(undefined4 *)&(this->m_UnicodeString).field_0x4 = 0;
    (this->m_UnicodeString).Buffer = (wchar_t *)0x0;
  }
  return;
}



===== FxLdrAcquireLoadedModuleLock @ 140005030 =====

void __cdecl FxLdrAcquireLoadedModuleLock(void)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(0x14000d240,1);
  return;
}



===== FxLdrReleaseLoadedModuleLock @ 140005070 =====

void __cdecl FxLdrReleaseLoadedModuleLock(void)

{
  ExReleaseResourceLite(0x14000d240);
  KeLeaveCriticalRegion();
  return;
}



===== LibraryAcquireClientLock @ 1400050a0 =====

void __cdecl LibraryAcquireClientLock(_LIBRARY_MODULE *param_1)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&param_1->ClientsListLock,1);
  return;
}



===== LibraryLoaderUnlock @ 1400050e0 =====

void __cdecl LibraryLoaderUnlock(_LIBRARY_MODULE *param_1)

{
  param_1->LoaderThread = (_KTHREAD *)0x0;
  KeSetEvent(&param_1->LoaderEvent,0,0);
  return;
}



===== LibraryReleaseClientLock @ 140005120 =====

void __cdecl LibraryReleaseClientLock(_LIBRARY_MODULE *param_1)

{
  ExReleaseResourceLite(&param_1->ClientsListLock);
  KeLeaveCriticalRegion();
  return;
}



===== LibraryAddReferenceLocked @ 140005150 =====

void __cdecl LibraryAddReferenceLocked(_LIBRARY_MODULE *param_1)

{
  param_1->LibraryRefCount = param_1->LibraryRefCount + 1;
  return;
}



===== ClassLibraryCopyInfo @ 140005160 =====

void __cdecl ClassLibraryCopyInfo(_CLASS_MODULE *param_1,_WDF_CLASS_LIBRARY_INFO *param_2)

{
  ulong uVar1;
  
  param_1->ClassLibraryInfo = param_2;
  uVar1 = (param_2->Version).Minor;
  (param_1->Version).Major = (param_2->Version).Major;
  (param_1->Version).Minor = uVar1;
  (param_1->Version).Build = (param_2->Version).Build;
  return;
}



===== ClassAddReferenceLocked @ 140005190 =====

void __cdecl ClassAddReferenceLocked(_CLASS_MODULE *param_1)

{
  param_1->ClassRefCount = param_1->ClassRefCount + 1;
  return;
}



===== LibraryCopyInfo @ 1400051a0 =====

void __cdecl LibraryCopyInfo(_LIBRARY_MODULE *param_1,_WDF_LIBRARY_INFO *param_2)

{
  ulong uVar1;
  
  param_1->LibraryInfo = param_2;
  uVar1 = (param_2->Version).Minor;
  (param_1->Version).Major = (param_2->Version).Major;
  (param_1->Version).Minor = uVar1;
  (param_1->Version).Build = (param_2->Version).Build;
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Z @ 1400051c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_Z
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,_UNICODE_STRING *param_9)

{
  RECORDER_LOG__ *pRVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  
  pRVar1 = g_IfrLog;
  pwVar2 = L"NULL";
  uVar3 = 8;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    if ((param_9 != (_UNICODE_STRING *)0x0) && (uVar3 = param_9->Length, param_9->Length != 0)) {
      pwVar2 = param_9->Buffer;
    }
    if (param_9 == (_UNICODE_STRING *)0x0) {
      param_9 = (_UNICODE_STRING *)L"\b";
    }
    WppAutoLogTrace(pRVar1,param_5,1,param_8,param_7,param_9,2,pwVar2,uVar3,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Zd @ 140005310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_Zd
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,_UNICODE_STRING *param_9,int param_10)

{
  RECORDER_LOG__ *pRVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  
  pRVar1 = g_IfrLog;
  pwVar2 = L"NULL";
  uVar3 = 8;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,0xb);
  }
  if (param_3 != '\0') {
    if ((param_9 != (_UNICODE_STRING *)0x0) && (uVar3 = param_9->Length, param_9->Length != 0)) {
      pwVar2 = param_9->Buffer;
    }
    if (param_9 == (_UNICODE_STRING *)0x0) {
      param_9 = (_UNICODE_STRING *)L"\b";
    }
    WppAutoLogTrace(pRVar1,4,1,param_8,0xb,param_9,2,pwVar2,uVar3,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_D @ 14000547c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_D
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,uint param_9)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = g_IfrLog;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,param_5,1,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_S @ 140005534 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_S
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,wchar_t *param_9)

{
  RECORDER_LOG__ *pRVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  pRVar1 = g_IfrLog;
  lVar4 = -1;
  lVar3 = 10;
  if (param_2 != '\0') {
    if (param_9 != (wchar_t *)0x0) {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_9[lVar2] != L'\0');
    }
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x3f);
  }
  if (param_3 != '\0') {
    if (param_9 != (wchar_t *)0x0) {
      do {
        lVar4 = lVar4 + 1;
      } while (param_9[lVar4] != L'\0');
      lVar3 = lVar4 * 2 + 2;
    }
    if (param_9 == (wchar_t *)0x0) {
      param_9 = L"NULL";
    }
    WppAutoLogTrace(pRVar1,4,1,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x3f,param_9,lVar3,0)
    ;
  }
  return;
}



===== ClassCleanupAndFree @ 140005660 =====

void __cdecl ClassCleanupAndFree(_CLASS_MODULE *param_1)

{
  wchar_t *pwVar1;
  
  ClassClose(param_1);
  pwVar1 = (param_1->Service).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (param_1->Service).Length = 0;
    (param_1->Service).MaximumLength = 0;
    *(undefined4 *)&(param_1->Service).field_0x4 = 0;
    (param_1->Service).Buffer = (wchar_t *)0x0;
  }
  pwVar1 = (param_1->ImageName).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (param_1->ImageName).Length = 0;
    (param_1->ImageName).MaximumLength = 0;
    *(undefined4 *)&(param_1->ImageName).field_0x4 = 0;
    (param_1->ImageName).Buffer = (wchar_t *)0x0;
  }
  pwVar1 = (param_1->ControlDeviceName).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (param_1->ControlDeviceName).Length = 0;
    (param_1->ControlDeviceName).MaximumLength = 0;
    *(undefined4 *)&(param_1->ControlDeviceName).field_0x4 = 0;
    (param_1->ControlDeviceName).Buffer = (wchar_t *)0x0;
  }
  ExDeleteResourceLite(param_1);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== ClassClose @ 140005710 =====

void __cdecl ClassClose(_CLASS_MODULE *param_1)

{
  if (param_1->ClassFileObject != (_FILE_OBJECT *)0x0) {
    ObfDereferenceObject();
    param_1->ClassFileObject = (_FILE_OBJECT *)0x0;
    param_1->ClassDriverObject = (_DRIVER_OBJECT *)0x0;
  }
  return;
}



===== LibraryUnload @ 140005750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl LibraryUnload(_LIBRARY_MODULE *param_1)

{
  uint uVar1;
  uchar uVar2;
  WPP_PROJECT_CONTROL_BLOCK *in_R9;
  ulong in_stack_ffffffffffffffd0;
  
  if (param_1->IsBootDriver != '\x01') {
    if (param_1->LibraryInfo != (_WDF_LIBRARY_INFO *)0x0) {
      uVar1 = (*param_1->LibraryInfo->LibraryDecommission)();
      if ((int)uVar1 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar2 = '\0';
        }
        else {
          uVar2 = '\x01';
        }
        in_R9 = WPP_GLOBAL_Control;
        if ((uVar2 != '\0') ||
           (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_D
                    ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                     WPP_RECORDER_INITIALIZED !=
                     (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,
                     '\x04',in_stack_ffffffffffffffd0,0xd,
                     WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,uVar1);
        }
      }
      param_1->LibraryInfo = (_WDF_LIBRARY_INFO *)0x0;
    }
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Z
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffd0,0xe,
                 WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,&param_1->Service);
    }
    LibraryClose(param_1);
    uVar1 = ZwUnloadDriver(&param_1->Service);
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      if ((uVar2 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffd0,0xf,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,
                   &param_1->Service,uVar1);
      }
    }
    LibraryReleaseReference(param_1);
  }
  return;
}



===== ClassUnload @ 140005900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl ClassUnload(_CLASS_MODULE *param_1)

{
  uint uVar1;
  uchar uVar2;
  _func___cdecl_void *in_R9;
  ulong in_stack_ffffffffffffffd0;
  
  if (param_1->IsBootDriver != '\x01') {
    if ((param_1->ClassLibraryInfo != (_WDF_CLASS_LIBRARY_INFO *)0x0) &&
       (in_R9 = param_1->ClassLibraryInfo->ClassLibraryDeinitialize,
       in_R9 != (_func___cdecl_void *)0x0)) {
      if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
         ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0 ||
          ((WPP_GLOBAL_Control->Control).Level < 4)))) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      if ((uVar2 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_q
                  ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                   in_stack_ffffffffffffffd0,0xd,WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,
                   in_R9);
      }
      (*param_1->ClassLibraryInfo->ClassLibraryDeinitialize)();
      param_1->ClassLibraryInfo = (_WDF_CLASS_LIBRARY_INFO *)0x0;
    }
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Z
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffd0,0xe,
                 WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,&param_1->Service);
    }
    ClassClose(param_1);
    uVar1 = ZwUnloadDriver(&param_1->Service);
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      if ((uVar2 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffd0,0xf,WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,
                   &param_1->Service,uVar1);
      }
    }
    ClassReleaseReference(param_1);
  }
  return;
}



===== ClassLoaderUnlock @ 140005ac0 =====

void __cdecl ClassLoaderUnlock(_CLASS_MODULE *param_1)

{
  param_1->LoaderThread = (_KTHREAD *)0x0;
  KeSetEvent(&param_1->LoaderEvent,0,0);
  return;
}



===== __report_gsfailure @ 140005b00 =====

void __cdecl __report_gsfailure(ulong64 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,param_1,__security_cookie,__security_cookie_complement,0);
}



===== _vsnwprintf @ 140005b34 =====

int __cdecl _vsnwprintf(wchar_t *param_1,ulong64 param_2,wchar_t *param_3,char *param_4)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(param_1,param_2,param_3,(localeinfo_struct *)0x0,param_4);
  return iVar1;
}



===== _vsnwprintf_l @ 140005b54 =====

int __cdecl
_vsnwprintf_l(wchar_t *param_1,ulong64 param_2,wchar_t *param_3,localeinfo_struct *param_4,
             char *param_5)

{
  int iVar1;
  _iobuf local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if ((param_3 == (wchar_t *)0x0) || ((param_2 != 0 && (param_1 == (wchar_t *)0x0)))) {
    _invalid_parameter((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    if (param_2 < 0x40000000) {
      local_38._cnt = (int)param_2 * 2;
    }
    else {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = (char *)param_1;
    local_38._base = (char *)param_1;
    iVar1 = _woutput_l(&local_38,param_3,param_4,param_5);
    if (param_1 != (wchar_t *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
        local_38._ptr = (char *)((longlong)local_38._ptr + 1);
      }
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = 0;
      }
    }
  }
  return iVar1;
}



===== _flsbuf @ 140005c4c =====

int __cdecl _flsbuf(int param_1,_iobuf *param_2)

{
  param_2->_flag = param_2->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 140005c5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _woutput_l(_iobuf *param_1,wchar_t *param_2,localeinfo_struct *param_3,char *param_4)

{
  char *pcVar1;
  wchar_t wVar2;
  ushort uVar3;
  ushort *puVar4;
  int *piVar5;
  wchar_t *pwVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  wchar_t *pwVar10;
  char cVar11;
  uint uVar12;
  wchar_t *pwVar13;
  uint uVar14;
  _iobuf *p_Var15;
  uint uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  uint uVar19;
  wchar_t *pwVar20;
  int iVar21;
  undefined1 auStackY_4d8 [32];
  int local_4a8;
  uint local_4a4;
  uint local_4a0;
  wchar_t local_49c [2];
  int local_498;
  int local_494;
  char local_490 [4];
  wchar_t local_48c;
  short local_48a;
  uint local_488;
  wchar_t *local_480;
  int local_478;
  _iobuf *local_470;
  undefined4 local_468;
  wchar_t *local_460;
  wchar_t local_448 [255];
  undefined2 local_249;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_4d8;
  local_468 = 0;
  uVar16 = 0;
  local_488 = 0;
  uVar12 = 0;
  uVar14 = 0;
  local_4a0 = 0;
  pwVar13 = (wchar_t *)0x0;
  local_4a4 = 0;
  local_478 = 0;
  local_480 = (wchar_t *)param_4;
  local_470 = param_1;
  memset();
  local_49c[0] = L'\0';
  local_498 = 0;
  if ((param_1 == (_iobuf *)0x0) || (param_2 == (wchar_t *)0x0)) {
LAB_140006520:
    _invalid_parameter((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    iVar7 = -1;
  }
  else {
    wVar2 = *param_2;
    iVar7 = 0;
    local_4a8 = 0;
    uVar18 = 0;
    local_494 = 0;
    if (wVar2 != L'\0') {
      do {
        pwVar20 = param_2 + 1;
        if (iVar7 < 0) break;
        uVar9 = 0;
        if ((ushort)(wVar2 + L'￠') < 0x5b) {
          uVar19 = (int)(char)(&s__null_)[(ushort)wVar2] & 0xf;
        }
        else {
          uVar19 = uVar9;
        }
        local_494 = (int)(char)(&__lookuptable)[(int)(local_494 + uVar19 * 8)] >> 4;
        uVar19 = uVar16;
        local_460 = pwVar20;
        if (local_494 == 0) {
LAB_1400063f4:
          local_498 = 1;
          write_char(wVar2,local_470,&local_4a8);
          uVar16 = uVar19;
LAB_1400062a2:
          iVar7 = local_4a8;
LAB_1400062aa:
        }
        else if (local_494 == 1) {
          uVar12 = 0xffffffff;
          uVar14 = 0xffffffff;
          local_478 = 0;
          local_4a0 = 0xffffffff;
          local_488 = 0;
          local_4a4 = 0;
          local_498 = 0;
          uVar16 = uVar9;
        }
        else if (local_494 == 2) {
          if (wVar2 == L' ') {
            uVar16 = uVar16 | 2;
          }
          else if (wVar2 == L'#') {
            uVar16 = uVar16 | 0x80;
          }
          else if (wVar2 == L'+') {
            uVar16 = uVar16 | 1;
          }
          else if (wVar2 == L'-') {
            uVar16 = uVar16 | 4;
          }
          else if (wVar2 == L'0') {
            uVar16 = uVar16 | 8;
          }
        }
        else if (local_494 == 3) {
          if (wVar2 == L'*') {
            uVar9 = *(uint *)param_4;
            local_480 = (wchar_t *)((longlong)param_4 + 8);
            if ((int)uVar9 < 0) {
              uVar16 = uVar16 | 4;
            }
            local_488 = -uVar9;
            if (-1 < (int)uVar9) {
              local_488 = uVar9;
            }
          }
          else {
            local_488 = (uint)(ushort)wVar2 + (local_488 * 5 + -0x18) * 2;
          }
        }
        else if (local_494 == 4) {
          local_4a0 = 0;
          uVar14 = uVar9;
          uVar12 = uVar9;
        }
        else if (local_494 == 5) {
          if (wVar2 == L'*') {
            local_4a0 = *(uint *)param_4;
            local_480 = (wchar_t *)((longlong)param_4 + 8);
            uVar14 = local_4a0;
            uVar12 = local_4a0;
            if ((int)local_4a0 < 0) {
              local_4a0 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar12 = 0xffffffff;
            }
          }
          else {
            local_4a0 = (uint)(ushort)wVar2 + (uVar14 * 5 + -0x18) * 2;
            uVar14 = local_4a0;
            uVar12 = local_4a0;
          }
        }
        else if (local_494 == 6) {
          if (wVar2 == L'I') {
LAB_140006345:
            uVar19 = uVar16 | 0x8000;
            if (wVar2 == L'I') {
              if (*pwVar20 == L'6') {
                if (param_2[2] != L'4') goto LAB_1400063c8;
                pwVar20 = param_2 + 3;
                uVar16 = uVar19;
              }
              else {
                if ((*pwVar20 != L'3') || (param_2[2] != L'2')) {
LAB_1400063c8:
                  if ((ushort)(*pwVar20 + L'ﾨ') < 0x21) {
                    uVar16 = uVar19;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar20 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_1400062b4;
                  }
                  local_494 = 0;
                  goto LAB_1400063f4;
                }
                pwVar20 = param_2 + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar19;
              if (wVar2 != L'j') goto LAB_1400063c8;
            }
          }
          else if (wVar2 == L'h') {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (wVar2 == L'j') goto LAB_140006345;
            if (wVar2 == L'l') {
              if (*pwVar20 == L'l') {
                pwVar20 = param_2 + 2;
                uVar16 = uVar16 | 0x1000;
              }
              else {
                uVar16 = uVar16 | 0x10;
              }
            }
            else {
              if (wVar2 == L't') goto LAB_140006345;
              if (wVar2 == L'w') {
                uVar16 = uVar16 | 0x800;
              }
              else if (wVar2 == L'z') goto LAB_140006345;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar2 < 0x6a) {
            if (wVar2 == L'i') {
LAB_140005ded:
              uVar16 = uVar16 | 0x40;
LAB_140005df0:
              uVar18 = 10;
              goto LAB_140005dfb;
            }
            if (wVar2 == L'C') {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140005f24:
              local_49c[0] = *(wchar_t *)param_4;
              local_480 = (wchar_t *)((longlong)param_4 + 8);
              local_498 = 1;
              if ((uVar16 & 0x20) == 0) {
                local_448[0] = local_49c[0];
              }
              else {
                local_490[0] = (char)local_49c[0];
                local_490[1] = 0;
                iVar21 = mbtowc(local_448,local_490,(longlong)__mb_cur_max);
                if (iVar21 < 0) {
                  local_478 = 1;
                }
              }
              pwVar13 = local_448;
              uVar18 = 1;
            }
            else if (wVar2 == L'S') {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140005ead:
              pwVar13 = *(wchar_t **)param_4;
              uVar9 = uVar14;
              if (uVar14 == 0xffffffff) {
                uVar9 = 0x7fffffff;
              }
              local_480 = (wchar_t *)((longlong)param_4 + 8);
              if ((uVar16 & 0x20) == 0) {
                local_498 = 1;
                pwVar10 = L"(null)";
                pwVar6 = L"(null)";
                if (pwVar13 != (wchar_t *)0x0) {
                  pwVar10 = pwVar13;
                  pwVar6 = pwVar13;
                }
                for (; (pwVar13 = pwVar6, uVar9 != 0 && (uVar9 = uVar9 - 1, *pwVar10 != L'\0'));
                    pwVar10 = pwVar10 + 1) {
                  pwVar6 = pwVar13;
                }
                uVar18 = (longlong)pwVar10 - (longlong)pwVar13 >> 1 & 0xffffffff;
              }
              else {
                if (pwVar13 == (wchar_t *)0x0) {
                  pwVar13 = L"渨汵⥬";
                }
                pwVar10 = pwVar13;
                uVar18 = 0;
                if (0 < (int)uVar9) {
                  do {
                    if ((char)*pwVar10 == '\0') break;
                    pwVar10 = (wchar_t *)((longlong)pwVar10 + 1);
                    uVar19 = (int)uVar18 + 1;
                    uVar18 = (ulonglong)uVar19;
                  } while ((int)uVar19 < (int)uVar9);
                }
              }
            }
            else {
              if (wVar2 == L'X') goto LAB_140005ffe;
              if (wVar2 == L'Z') {
                puVar4 = *(ushort **)param_4;
                local_480 = (wchar_t *)((longlong)param_4 + 8);
                if ((puVar4 == (ushort *)0x0) ||
                   (pwVar13 = *(wchar_t **)(puVar4 + 4), pwVar13 == (wchar_t *)0x0)) {
                  pwVar13 = L"渨汵⥬";
                  uVar8 = 0xffffffffffffffff;
                  do {
                    uVar18 = uVar8 + 1;
                    pcVar1 = "null)" + uVar8;
                    uVar8 = uVar18;
                  } while (*pcVar1 != '\0');
                }
                else {
                  uVar3 = *puVar4;
                  if (puVar4[1] < uVar3) goto LAB_140006520;
                  uVar18 = (ulonglong)(uint)uVar3;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar3 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140006520;
                    uVar18 = (ulonglong)(uVar3 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (wVar2 == L'c') goto LAB_140005f24;
                if (wVar2 == L'd') goto LAB_140005ded;
              }
            }
LAB_14000613a:
            if (local_478 != 0) goto LAB_1400062aa;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_140006188;
                  local_48c = L' ';
                }
                else {
                  local_48c = L'+';
                }
              }
              else {
                local_48c = L'-';
              }
              local_4a4 = 1;
            }
LAB_140006188:
            uVar14 = local_4a4;
            iVar7 = (int)uVar18;
            iVar21 = (local_488 - iVar7) - local_4a4;
            if ((uVar16 & 0xc) == 0) {
              write_multi_char(L' ',iVar21,local_470,&local_4a8);
            }
            write_string(&local_48c,uVar14,local_470,&local_4a8);
            p_Var15 = local_470;
            if ((uVar16 & 0xc) == 8) {
              write_multi_char(L'0',iVar21,local_470,&local_4a8);
            }
            if ((local_498 == 0) && (0 < iVar7)) {
              uVar8 = uVar18 & 0xffffffff;
              pwVar20 = pwVar13;
              do {
                iVar7 = mbtowc(local_49c,(char *)pwVar20,(longlong)__mb_cur_max);
                uVar14 = (int)uVar8 - ((iVar7 == 2) + 1);
                uVar8 = (ulonglong)uVar14;
                if (iVar7 < 1) {
                  local_4a8 = -1;
                  p_Var15 = local_470;
                  pwVar20 = local_460;
                  goto LAB_14000627e;
                }
                write_char(local_49c[0],local_470,&local_4a8);
                pwVar20 = (wchar_t *)((longlong)pwVar20 + (longlong)iVar7);
              } while (0 < (int)uVar14);
              p_Var15 = local_470;
              pwVar20 = local_460;
            }
            else {
              write_string(pwVar13,iVar7,p_Var15,&local_4a8);
            }
LAB_14000627e:
            iVar7 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar21,p_Var15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_1400062a2;
            }
          }
          else {
            if (wVar2 != L'n') {
              if (wVar2 == L'o') {
                uVar18 = 8;
                if ((char)uVar16 < '\0') {
                  uVar16 = uVar16 | 0x200;
                }
              }
              else {
                if (wVar2 == L'p') {
                  uVar12 = 0x10;
                  uVar14 = 0x10;
                  uVar16 = uVar16 | 0x8000;
LAB_140005ffe:
                  local_468 = 7;
                }
                else {
                  if (wVar2 == L's') goto LAB_140005ead;
                  if (wVar2 == L'u') goto LAB_140005df0;
                  if (wVar2 != L'x') goto LAB_14000613a;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar18 = 0x10;
              }
LAB_140005dfb:
              local_480 = (wchar_t *)((longlong)param_4 + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar8 = (ulonglong)(int)*(uint *)param_4;
                    goto LAB_140006075;
                  }
                  uVar8 = (ulonglong)*(uint *)param_4;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar8 = (ulonglong)(ushort)*(wchar_t *)param_4;
                }
                else {
                  uVar8 = (ulonglong)*(wchar_t *)param_4;
LAB_140006075:
                  if ((longlong)uVar8 < 0) {
                    uVar8 = -uVar8;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar8 = *(ulonglong *)param_4;
                if ((uVar16 & 0x40) != 0) goto LAB_140006075;
              }
              uVar17 = uVar8 & 0xffffffff;
              if ((uVar16 & 0x9000) != 0) {
                uVar17 = uVar8;
              }
              if ((int)uVar14 < 0) {
                uVar12 = 1;
              }
              else {
                uVar16 = uVar16 & 0xfffffff7;
                if (0x200 < (int)uVar14) {
                  uVar12 = 0x200;
                }
              }
              local_4a4 = -(uint)(uVar17 != 0) & local_4a4;
              pwVar10 = &local_249;
              for (; (uVar14 = uVar12 - 1, 0 < (int)uVar12 || (uVar17 != 0));
                  uVar17 = uVar17 / uVar18) {
                uVar12 = (int)(uVar17 % uVar18) + 0x30;
                cVar11 = (char)uVar12;
                if (0x39 < uVar12) {
                  cVar11 = cVar11 + (char)local_468;
                }
                *(char *)pwVar10 = cVar11;
                pwVar10 = (wchar_t *)((longlong)pwVar10 + -1);
                uVar12 = uVar14;
              }
              uVar12 = (int)&local_249 - (int)pwVar10;
              uVar18 = (ulonglong)uVar12;
              pwVar13 = (wchar_t *)((longlong)pwVar10 + 1);
              if (((uVar16 >> 9 & 1) != 0) && ((uVar12 == 0 || (*(char *)pwVar13 != '0')))) {
                uVar18 = (ulonglong)(uVar12 + 1);
                *(char *)pwVar10 = '0';
                pwVar13 = pwVar10;
              }
              uVar12 = uVar14;
              local_4a0 = uVar14;
              goto LAB_14000613a;
            }
            piVar5 = *(int **)param_4;
            local_480 = (wchar_t *)((longlong)param_4 + 8);
            iVar21 = _get_printf_count_output();
            if (iVar21 == 0) goto LAB_140006520;
            if ((uVar16 & 0x20) == 0) {
              *piVar5 = iVar7;
            }
            else {
              *(short *)piVar5 = (short)iVar7;
            }
            local_478 = 1;
          }
          uVar14 = local_4a0;
          uVar12 = local_4a0;
        }
LAB_1400062b4:
        wVar2 = *pwVar20;
        param_2 = pwVar20;
        param_4 = (char *)local_480;
      } while (wVar2 != L'\0');
    }
  }
  return iVar7;
}



===== write_char @ 140006568 =====

void __cdecl write_char(wchar_t param_1,_iobuf *param_2,int *param_3)

{
  ushort uVar1;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    uVar1 = _fputwc_nolock(param_1,param_2);
    if ((uVar1 == 0xffff) && ((param_2->_flag & 0x20U) != 0)) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 1400065bc =====

void __cdecl write_multi_char(wchar_t param_1,int param_2,_iobuf *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 140006614 =====

void __cdecl write_string(wchar_t *param_1,int param_2,_iobuf *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    do {
      if (param_2 < 1) {
        return;
      }
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
    } while (*param_4 != -1);
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _invalid_parameter @ 140006690 =====

void __cdecl
_invalid_parameter(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,ulong64 param_5)

{
  return;
}



===== _get_printf_count_output @ 14000669c =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(__enable_percent_n == (__security_cookie | 1));
}



===== _fputwc_nolock @ 1400066bc =====

ushort __cdecl _fputwc_nolock(wchar_t param_1,_iobuf *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (_iobuf *)0x0) {
    _invalid_parameter((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    param_1 = L'\xffff';
  }
  else {
    piVar1 = &param_2->_cnt;
    *piVar1 = *piVar1 + -2;
    if (*piVar1 < 0) {
      iVar2 = _flswbuf((uint)(ushort)param_1,param_2);
      param_1 = (wchar_t)iVar2;
    }
    else {
      *(wchar_t *)param_2->_ptr = param_1;
      param_2->_ptr = param_2->_ptr + 2;
    }
  }
  return param_1;
}



===== mbtowc @ 140006708 =====

int __cdecl mbtowc(wchar_t *param_1,char *param_2,ulong64 param_3)

{
  wchar_t wVar1;
  char *local_res10 [3];
  
  local_res10[0]._0_4_ = 0;
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    if (*param_2 == '\0') {
      if (param_1 != (wchar_t *)0x0) {
        *param_1 = L'\0';
      }
    }
    else {
      local_res10[0] = param_2;
      wVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *param_1 = wVar1;
      local_res10[0]._0_4_ = (int)local_res10[0] - (int)param_2;
    }
  }
  return (int)local_res10[0];
}



===== __GSHandlerCheck @ 14000675c =====

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck(_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
                _DISPATCHER_CONTEXT *param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,param_4->HandlerData);
  return ExceptionContinueSearch;
}



===== __GSHandlerCheckCommon @ 140006780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl
__GSHandlerCheckCommon(void *param_1,_DISPATCHER_CONTEXT *param_2,_GS_HANDLER_DATA *param_3)

{
  return;
}



===== _flswbuf @ 1400067e8 =====

int __cdecl _flswbuf(int param_1,_iobuf *param_2)

{
  param_2->_flag = param_2->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 140006800 =====

/* WARNING: Removing unreachable block (ram,0x00014000686a) */
/* WARNING: Removing unreachable block (ram,0x000140006819) */
/* WARNING: Removing unreachable block (ram,0x00014000680a) */

int __cdecl __cpu_features_init(void)

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
  __isa_info.info = bVar7 | 1;
  return 0;
}



===== __C_specific_handler @ 1400068c6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400068c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== RtlAnsiCharToUnicodeChar @ 1400068d8 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400068d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== FindModuleByClientServiceNameLocked @ 1400068ec =====

long __cdecl
FindModuleByClientServiceNameLocked
          (_UNICODE_STRING *param_1,_DRIVER_OBJECT *param_2,_LIBRARY_MODULE **param_3)

{
  _LIST_ENTRY *p_Var1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uchar uVar5;
  _LIST_ENTRY *p_Var6;
  _LIBRARY_MODULE *p_Var7;
  _UNICODE_STRING *p_Var8;
  _LIST_ENTRY *p_Var9;
  ulong in_stack_ffffffffffffffa0;
  _UNICODE_STRING local_38;
  
  p_Var8 = &local_38;
  p_Var7 = (_LIBRARY_MODULE *)0x0;
  *param_3 = (_LIBRARY_MODULE *)0x0;
  local_38.Length = 0;
  local_38.MaximumLength = 0;
  local_38._4_4_ = 0;
  local_38.Buffer = (wchar_t *)0x0;
  uVar3 = GetImageName(param_1,param_2,0x634c7846,p_Var8);
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (uVar5 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar5 = '\0';
    }
    if ((uVar5 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,uVar5,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 p_Var8,'\x04',in_stack_ffffffffffffffa0,0x2d,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_1,uVar3);
    }
    local_38.Buffer = (wchar_t *)0x0;
  }
  else {
    uVar3 = 0xc0000183;
    p_Var9 = WdfLdrGlobals.LoadedModuleList.Flink;
    if (WdfLdrGlobals.LoadedModuleList.Flink != &WdfLdrGlobals.LoadedModuleList) {
      do {
        if (-1 < (int)uVar3) goto LAB_140006a23;
        p_Var7 = (_LIBRARY_MODULE *)&p_Var9[-1].Blink;
        LibraryAcquireClientLock(p_Var7);
        p_Var1 = p_Var9 + 6;
        p_Var6 = p_Var1->Flink;
        if (p_Var6 != p_Var1) {
          uVar2 = local_38.Length;
          do {
            if (*(ushort *)&p_Var6[3].Flink == uVar2) {
              iVar4 = wcsncmp((wchar_t *)p_Var6[3].Blink,local_38.Buffer,(ulonglong)(uVar2 >> 1));
              if (iVar4 == 0) {
                uVar3 = 0;
                break;
              }
              uVar2 = local_38.Length;
            }
            p_Var6 = p_Var6->Flink;
          } while (p_Var6 != p_Var1);
        }
        LibraryReleaseClientLock(p_Var7);
        p_Var9 = p_Var9->Flink;
      } while (p_Var9 != &WdfLdrGlobals.LoadedModuleList);
      if (-1 < (int)uVar3) {
LAB_140006a23:
        *param_3 = p_Var7;
      }
    }
  }
  if (local_38.Buffer != (wchar_t *)0x0) {
    ExFreePoolWithTag(local_38.Buffer,0);
  }
  return uVar3;
}



===== FxLdrQueryUlong @ 140006a64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl FxLdrQueryUlong(void *param_1,_UNICODE_STRING *param_2,ulong *param_3)

{
  uint uVar1;
  uchar uVar2;
  undefined1 auStackY_88 [32];
  ulong uVar3;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38[0] = 0;
  local_20 = 0;
  uVar3 = (ulong)local_38;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = ZwQueryValueKey(0,(char)param_2,2,&local_30);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (uVar2 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',uVar3,0xb,WPP_f35a5499df3a35f353983bcad3180794_Traceguids
                 ,uVar1);
    }
  }
  else if ((local_30._4_4_ == 4) && ((int)uStack_28 == 4)) {
    *param_3 = uStack_28._4_4_;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000206;
  }
  return uVar1;
}



===== GetClassNameAndBase @ 140006b70 =====

long __cdecl
GetClassNameAndBase(_CLASS_MODULE *param_1,_UNICODE_STRING *param_2,_DRIVER_OBJECT *param_3)

{
  _UNICODE_STRING *p_Var1;
  uint uVar2;
  uchar uVar3;
  ulong in_stack_ffffffffffffffd0;
  
  p_Var1 = &param_1->ImageName;
  uVar2 = GetImageName(param_2,param_3,0x694c7846,p_Var1);
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (uVar3 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar3 = '\0';
    }
    if ((uVar3 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',in_stack_ffffffffffffffd0,0x4b,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_2,uVar2);
    }
  }
  else {
    uVar2 = GetImageBase(p_Var1,&param_1->ImageAddress,&param_1->ImageSize);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (uVar3 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffd0,0x4c,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   p_Var1,uVar2);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== GetDriverObjectFromDeviceName @ 140006cc4 =====

_DRIVER_OBJECT * __cdecl GetDriverObjectFromDeviceName(_UNICODE_STRING *param_1)

{
  _DRIVER_OBJECT *p_Var1;
  bool bVar2;
  uint uVar3;
  longlong local_res8;
  undefined8 local_res10;
  ulong in_stack_ffffffffffffffd0;
  
  local_res10 = 0;
  local_res8 = 0;
  if (param_1 != (_UNICODE_STRING *)0x0) {
    bVar2 = true;
    uVar3 = IoGetDeviceObjectPointer(param_1,1,&local_res10,&local_res8);
    if (-1 < (int)uVar3) {
      p_Var1 = *(_DRIVER_OBJECT **)(local_res8 + 8);
      ObfDereferenceObject(local_res10);
      return p_Var1;
    }
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      bVar2 = false;
    }
    if ((bVar2) ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,bVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',in_stack_ffffffffffffffd0,0x44,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_1,uVar3);
    }
  }
  return (_DRIVER_OBJECT *)0x0;
}



===== GetImageName @ 140006da4 =====

long __cdecl
GetImageName(_UNICODE_STRING *param_1,_DRIVER_OBJECT *param_2,ulong param_3,_UNICODE_STRING *param_4
            )

{
  wchar_t wVar1;
  uint uVar2;
  wchar_t *pwVar3;
  uchar uVar4;
  uchar uVar5;
  wchar_t *pwVar6;
  _UNICODE_STRING *p_Var7;
  bool bVar8;
  wchar_t *local_res10;
  ulong in_stack_ffffffffffffff40;
  ushort uVar9;
  void *local_98;
  _UNICODE_STRING local_90;
  _UNICODE_STRING local_80;
  _UNICODE_STRING local_70;
  undefined8 local_60;
  undefined8 uStack_58;
  _UNICODE_STRING *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_80.Length = 0x12;
  local_80.MaximumLength = 0x14;
  local_80._4_4_ = 0;
  local_98 = (void *)0x0;
  local_res10 = (wchar_t *)0x0;
  local_80.Buffer = L"ImagePath";
  uVar5 = '\x01';
  pwVar6 = (wchar_t *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (_UNICODE_STRING *)0x0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_90.Length = 0;
  local_90.MaximumLength = 0;
  local_90._4_4_ = 0;
  local_90.Buffer = (wchar_t *)0x0;
  local_70.Length = 0;
  local_70.MaximumLength = 0;
  local_70._4_4_ = 0;
  local_70.Buffer = (wchar_t *)0x0;
  if (param_2 == (_DRIVER_OBJECT *)0x0) {
    local_60 = 0x30;
    uStack_58 = 0;
    uStack_48 = 0x240;
    param_4->Length = 0;
    param_4->MaximumLength = 0;
    *(undefined4 *)&param_4->field_0x4 = 0;
    param_4->Buffer = (wchar_t *)0x0;
    local_40 = 0;
    uStack_38 = 0;
    local_50 = param_1;
    uVar2 = ZwOpenKey(&local_98,1,&local_60);
    if ((int)uVar2 < 0) goto LAB_1400071d2;
    p_Var7 = (_UNICODE_STRING *)&local_res10;
    uVar2 = FxLdrQueryData(local_98,&local_80,0x314c7846,(_KEY_VALUE_PARTIAL_INFORMATION **)p_Var7);
    pwVar6 = local_res10;
    if ((int)uVar2 < 0) goto LAB_1400071d2;
    if (*(int *)(local_res10 + 2) - 1U < 2) {
      if (*(int *)(local_res10 + 4) - 1U < 0xffff) {
        local_90.Buffer = local_res10 + 6;
        wVar1 = local_res10[4];
        local_90.MaximumLength = wVar1;
        local_90.Length = wVar1;
        if ((1 < (ushort)wVar1) && (local_res10[(ulonglong)((ushort)wVar1 >> 1) + 5] == L'\0')) {
          local_90.Length = wVar1 + L'\xfffe';
        }
        goto LAB_140006fc3;
      }
      uVar2 = 0xc000000d;
    }
    else {
      uVar2 = 0xc0000024;
    }
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar5 = '\0';
    }
    bVar8 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
    if ((uVar5 == '\0') && (!bVar8)) goto LAB_1400071d2;
    uVar9 = 0x18;
  }
  else {
    p_Var7 = param_4;
    uVar2 = IoQueryFullDriverPath(param_2,&local_90);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar5 = '\0';
      }
      if ((uVar5 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar5,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffff40,0x17,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   param_1,uVar2);
      }
      goto LAB_1400071d2;
    }
    pwVar6 = local_90.Buffer;
LAB_140006fc3:
    GetNameFromPath(&local_90,&local_70);
    if (local_70.Length == 0) {
      uVar2 = 0xc000000d;
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar5 = '\0';
      }
      bVar8 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((uVar5 == '\0') && (!bVar8)) goto LAB_1400071d2;
      uVar2 = 0xc000000d;
      uVar9 = 0x19;
    }
    else {
      uVar9 = local_70.Length + 2;
      if (uVar9 < local_70.Length) {
        uVar2 = 0xc0000095;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar5 = '\0';
        }
        bVar8 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
        if ((uVar5 == '\0') && (!bVar8)) goto LAB_1400071d2;
        uVar2 = 0xc0000095;
        uVar9 = 0x1a;
      }
      else {
        pwVar3 = (wchar_t *)ExAllocatePool2(0x40,uVar9,param_3);
        param_4->Buffer = pwVar3;
        if (pwVar3 != (wchar_t *)0x0) {
          param_4->Length = 0;
          param_4->MaximumLength = uVar9;
          uVar2 = RtlUnicodeStringCopy(param_4,&local_70);
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             (uVar4 = '\x01', (WPP_GLOBAL_Control->Control).Level < 5)) {
            uVar4 = '\0';
          }
          if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)
             || ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
            uVar5 = '\0';
          }
          if ((uVar4 != '\0') || (uVar5 != '\0')) {
            WPP_RECORDER_AND_TRACE_SF_Z
                      ((WPP_GLOBAL_Control->Control).Logger,uVar4,uVar5,p_Var7,'\x05',
                       in_stack_ffffffffffffff40,0x1c,
                       WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_4);
          }
          goto LAB_1400071d2;
        }
        uVar2 = 0xc000009a;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar5 = '\0';
        }
        bVar8 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
        if ((uVar5 == '\0') && (!bVar8)) goto LAB_1400071d2;
        uVar2 = 0xc000009a;
        uVar9 = 0x1b;
      }
    }
  }
  WPP_RECORDER_AND_TRACE_SF_D
            ((WPP_GLOBAL_Control->Control).Logger,uVar5,bVar8,p_Var7,'\x04',
             in_stack_ffffffffffffff40,uVar9,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar2);
LAB_1400071d2:
  if (local_98 != (void *)0x0) {
    ZwClose();
  }
  if (pwVar6 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar6,0);
  }
  return uVar2;
}



===== GetLibraryNameAndBase @ 140007228 =====

long __cdecl
GetLibraryNameAndBase(_LIBRARY_MODULE *param_1,_UNICODE_STRING *param_2,_DRIVER_OBJECT *param_3)

{
  _UNICODE_STRING *p_Var1;
  uint uVar2;
  uchar uVar3;
  ulong in_stack_ffffffffffffffd0;
  
  p_Var1 = &param_1->ImageName;
  uVar2 = GetImageName(param_2,param_3,0x324c7846,p_Var1);
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (uVar3 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar3 = '\0';
    }
    if ((uVar3 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',in_stack_ffffffffffffffd0,0x45,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_2,uVar2);
    }
  }
  else {
    uVar2 = GetImageBase(p_Var1,&param_1->ImageAddress,&param_1->ImageSize);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (uVar3 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar3 = '\0';
      }
      if ((uVar3 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar3,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_ffffffffffffffd0,0x46,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   p_Var1,uVar2);
      }
    }
  }
  return uVar2;
}



===== InitializeWppRecorder @ 140007374 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl InitializeWppRecorder(_UNICODE_STRING *param_1)

{
  bool bVar1;
  uint uVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined1 auStackY_a8 [32];
  ulong in_stack_ffffffffffffff80;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  WPP_MAIN_CB[0].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  local_18 = 0;
  WPP_MAIN_CB[0].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)0x0;
  bVar1 = true;
  WPP_MAIN_CB[0].Control.ControlGuid = &WPP_ThisDir_CTLGUID_WdfLdr;
  WPP_MAIN_CB[0].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[0].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2f] = '\0';
  local_48 = 0;
  uStack_40 = 0;
  WPP_MAIN_CB[0].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  WPP_MAIN_CB[0].Control.AutoLogContext = (void *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  WPP_MAIN_CB[0].ReserveSpace[0x48] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x49] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x4a] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x4b] = '\0';
  p_Var3 = (_DRIVER_OBJECT *)param_1;
  WppLoadTracingSupport();
  WPP_MAIN_CB[0].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WppInitKm(p_Var3,param_1);
  local_48 = 0x38;
  local_28 = local_28 & 0xffffffffffffff00;
  uStack_30 = CONCAT44(0x10,(undefined4)uStack_30);
  local_38 = 0;
  uStack_30 = uStack_30 & 0xffffffffffffff00;
  uStack_40 = 0x40000000800;
  local_18 = 0x200000001;
  uVar2 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_48,&g_IfrLog);
  if ((int)uVar2 < 0) {
    g_IfrLog = (RECORDER_LOG__ *)imp_WppRecorderLogGetDefault();
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) {
      bVar1 = false;
    }
    if ((bVar1) ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_D
                ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x02',in_stack_ffffffffffffff80,0x11,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar2);
    }
  }
  else {
    uStack_50 = 0x200000002;
    local_58 = 0x10;
    imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_58);
  }
  return;
}



===== WdfLdrDriverEntryFailureNotify @ 140007540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl WdfLdrDriverEntryFailureNotify(_WDF_BIND_INFO *param_1,void **param_2)

{
  _WDF_LIBRARY_INFO *p_Var1;
  _func___cdecl_long__WDF_BIND_INFO_ptr_void_ptr_ptr *p_Var2;
  long lVar3;
  
  lVar3 = -0x3ffffff3;
  if ((((param_2 != (void **)0x0) && (param_1 != (_WDF_BIND_INFO *)0x0)) &&
      (param_1->Module != (_LIBRARY_MODULE *)0x0)) &&
     ((p_Var1 = param_1->Module->LibraryInfo, p_Var1 != (_WDF_LIBRARY_INFO *)0x0 &&
      (p_Var2 = p_Var1->LibraryUnregisterClient,
      p_Var2 != (_func___cdecl_long__WDF_BIND_INFO_ptr_void_ptr_ptr *)0x0)))) {
    lVar3 = (*p_Var2)((_WDF_BIND_INFO *)0x7fffffffffffefff,param_2);
  }
  return lVar3;
}



===== WdfLdrOpenRegistryDiagnosticsHandle @ 140007590 =====

long __cdecl WdfLdrOpenRegistryDiagnosticsHandle(void **param_1)

{
  bool bVar1;
  uint uVar2;
  ulong in_stack_ffffffffffffff90;
  _UNICODE_STRING local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  _UNICODE_STRING *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  *param_1 = (void *)0x0;
  local_30 = 0;
  bVar1 = true;
  local_48.Buffer =
       L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Wdf\\Kmdf\\Diagnostics";
  local_28 = &local_48;
  local_48.Length = 0x8e;
  local_48.MaximumLength = 0x90;
  local_48._4_4_ = 0;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = ZwOpenKey(0,1,&local_38);
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      bVar1 = false;
    }
    if ((bVar1) ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_GLOBAL_Control,'\x04',in_stack_ffffffffffffff90,10,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,&local_48,uVar2);
    }
  }
  return uVar2;
}



===== WdfLdrUnload @ 1400076a0 =====

void __cdecl WdfLdrUnload(_DRIVER_OBJECT *param_1)

{
  DllUnload();
  return;
}



===== DllInitialize @ 1400076c0 =====

long __cdecl DllInitialize(_UNICODE_STRING *param_1)

{
  long lVar1;
  
                    /* 0x76c0  1  DllInitialize */
  __security_init_cookie();
  lVar1 = FxDllInitialize(param_1);
  return lVar1;
}



===== DllUnload @ 1400076f0 =====

long __cdecl DllUnload(void)

{
  _LIST_ENTRY **pp_Var1;
  _LIST_ENTRY *p_Var2;
  _LIST_ENTRY *p_Var3;
  code *pcVar4;
  bool bVar5;
  ulong64 uVar6;
  WPP_PROJECT_CONTROL_BLOCK *pWVar7;
  uchar uVar8;
  undefined1 *puVar9;
  void *in_R9;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  ulong in_stack_ffffffffffffffb0;
  _LIST_ENTRY local_28;
  
                    /* 0x76f0  2  DllUnload */
  bVar5 = true;
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar8 = '\0';
  }
  else {
    uVar8 = '\x01';
  }
  if ((uVar8 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              ((WPP_GLOBAL_Control->Control).Logger,uVar8,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffffb0,0x14,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
  }
  uVar6 = _Tlgg_TelemetryProviderProv.RegHandle;
  if (alreadyExecuted != 0) {
    return 0;
  }
  _Tlgg_TelemetryProviderProv.RegHandle = 0;
  _Tlgg_TelemetryProviderProv.LevelPlus1 = 0;
  alreadyExecuted = 1;
  EtwUnregister(uVar6);
  puVar9 = auStackY_78;
  local_28.Blink = &local_28;
  local_28.Flink = &local_28;
  while (p_Var3 = WdfLdrGlobals.LoadedModuleList.Flink,
        WdfLdrGlobals.LoadedModuleList.Flink != &WdfLdrGlobals.LoadedModuleList) {
    if ((((WdfLdrGlobals.LoadedModuleList.Flink)->Blink != &WdfLdrGlobals.LoadedModuleList) ||
        (p_Var2 = (WdfLdrGlobals.LoadedModuleList.Flink)->Flink,
        p_Var2->Blink != WdfLdrGlobals.LoadedModuleList.Flink)) ||
       (WdfLdrGlobals.LoadedModuleList.Flink = p_Var2,
       p_Var2->Blink = &WdfLdrGlobals.LoadedModuleList, (local_28.Blink)->Flink != &local_28))
    goto LAB_1400078b7;
    p_Var3->Blink = local_28.Blink;
    p_Var3->Flink = &local_28;
    (local_28.Blink)->Flink = p_Var3;
    local_28.Blink = p_Var3;
  }
  while (local_28.Flink != &local_28) {
    if (((local_28.Flink)->Blink != &local_28) ||
       (p_Var3 = (local_28.Flink)->Flink, p_Var3->Blink != local_28.Flink)) goto LAB_1400078b7;
    p_Var3->Blink = &local_28;
    pp_Var1 = &local_28.Flink[-1].Blink;
    (local_28.Flink)->Blink = local_28.Flink;
    (local_28.Flink)->Flink = local_28.Flink;
    local_28.Flink = p_Var3;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar8 = '\0';
    }
    else {
      uVar8 = '\x01';
    }
    if ((uVar8 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                ((WPP_GLOBAL_Control->Control).Logger,uVar8,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffb0,0x15,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,pp_Var1);
    }
    LibraryUnloadClasses((_LIBRARY_MODULE *)pp_Var1);
    LibraryUnload((_LIBRARY_MODULE *)pp_Var1);
  }
LAB_1400078be:
  *(undefined8 *)(puVar9 + -8) = 0x1400078cc;
  ExDeleteResourceLite(0x14000d240);
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    bVar5 = false;
  }
  if ((bVar5) ||
     (pWVar7 = WPP_GLOBAL_Control,
     WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    pWVar7 = (WPP_PROJECT_CONTROL_BLOCK *)(WPP_GLOBAL_Control->Control).Logger;
    *(_GUID **)(puVar9 + 0x38) = WPP_f35a5499df3a35f353983bcad3180794_Traceguids;
    *(undefined2 *)(puVar9 + 0x30) = 0x16;
    puVar9[0x20] = 4;
    *(undefined8 *)(puVar9 + -8) = 0x14000791c;
    WPP_RECORDER_AND_TRACE_SF_
              ((ulong64)pWVar7,bVar5,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,puVar9[0x20],*(ulong *)(puVar9 + 0x28),*(ushort *)(puVar9 + 0x30),
               *(_GUID **)(puVar9 + 0x38));
  }
  *(undefined8 *)(puVar9 + -8) = 0x140007921;
  WppCleanupKm((_DRIVER_OBJECT *)&pWVar7->Control);
  return 0;
LAB_1400078b7:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar9 = auStackY_70;
  goto LAB_1400078be;
}



===== DriverEntry @ 140007944 =====

long __cdecl DriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  
  param_1->DriverUnload = WdfLdrUnload;
  lVar1 = FxDllInitialize(param_2);
  return lVar1;
}



===== FxDllInitialize @ 140007968 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl FxDllInitialize(_UNICODE_STRING *param_1)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  _DRIVER_OBJECT *p_Var4;
  _func___cdecl_void__GUID_ptr_ulong_uchar_ulong64_ulong64__EVENT_FILTER_DESCRIPTOR_ptr_void_ptr
  *p_Var5;
  void *pvVar6;
  void *in_R9;
  undefined1 auStackY_1a8 [32];
  uchar in_stack_fffffffffffffe78;
  ulong in_stack_fffffffffffffe80;
  ushort in_stack_fffffffffffffe88;
  _GUID *in_stack_fffffffffffffe90;
  ulong local_158 [2];
  _UNICODE_STRING local_150;
  undefined4 local_138 [72];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1a8;
  uVar3 = 0;
  local_150.Length = 0x14;
  local_150.MaximumLength = 0x16;
  local_150._4_4_ = 0;
  local_158[0] = 0;
  local_150.Buffer = L"DbgPrintOn";
  if (alreadyExecuted == 0) {
    bVar1 = true;
    p_Var5 = (_func___cdecl_void__GUID_ptr_ulong_uchar_ulong64_ulong64__EVENT_FILTER_DESCRIPTOR_ptr_void_ptr
              *)0x0;
    pvVar6 = (void *)0x110;
    alreadyExecuted = 1;
    memset();
    local_138[0] = 0x114;
    RtlGetVersion(local_138);
    InitializeWppRecorder(param_1);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation((_tlgProvider_t *)param_1,p_Var5,pvVar6);
    WdfLdrGlobals.LoadedModuleList.Blink = &WdfLdrGlobals.LoadedModuleList;
    WdfLdrGlobals.LoadedModuleList.Flink = &WdfLdrGlobals.LoadedModuleList;
    ExInitializeResourceLite(0x14000d240);
    lVar2 = WdfLdrDiagnosticsValueByNameAsULONG(&local_150,local_158);
    if ((-1 < lVar2) && (local_158[0] != 0)) {
      WdfLdrDiags.field0_0x0 = (_WDFLDR_DIAGS_u_0)((uint)WdfLdrDiags.field0_0x0 | 1);
    }
    uVar3 = AuxKlibInitialize();
    if ((int)uVar3 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar1 = false;
      }
      if ((bVar1) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,WPP_GLOBAL_Control,'\x04',
                   in_stack_fffffffffffffe80,0x12,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar3);
      }
      p_Var4 = (_DRIVER_OBJECT *)_Tlgg_TelemetryProviderProv.RegHandle;
      _Tlgg_TelemetryProviderProv.RegHandle = 0;
      _Tlgg_TelemetryProviderProv.LevelPlus1 = 0;
      EtwUnregister();
      WppCleanupKm(p_Var4);
    }
    else {
      WdfLdrGlobals.OsVersion.dwOSVersionInfoSize = 0x11c;
      RtlGetVersion(&WdfLdrGlobals);
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        bVar1 = false;
      }
      if ((bVar1 != false) ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_dd
                  ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,
                   in_stack_fffffffffffffe78,in_stack_fffffffffffffe80,in_stack_fffffffffffffe88,
                   in_stack_fffffffffffffe90,WdfLdrGlobals.OsVersion.dwMajorVersion,
                   WdfLdrGlobals.OsVersion.dwMinorVersion);
      }
    }
  }
  return uVar3;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 140007b84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = g_IfrLog;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,param_5,1,param_8,param_7,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_SqqD @ 140007c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_SqqD
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,wchar_t *param_9,void *param_10,void *param_11,uint param_12
          )

{
  RECORDER_LOG__ *pRVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_28 [4];
  
  pRVar1 = g_IfrLog;
  lVar4 = -1;
  local_28[0] = 0xc0000059;
  lVar3 = 10;
  if (param_2 != '\0') {
    if (param_9 != (wchar_t *)0x0) {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_9[lVar2] != L'\0');
    }
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x32);
  }
  if (param_3 != '\0') {
    if (param_9 != (wchar_t *)0x0) {
      do {
        lVar4 = lVar4 + 1;
      } while (param_9[lVar4] != L'\0');
      lVar3 = lVar4 * 2 + 2;
    }
    if (param_9 == (wchar_t *)0x0) {
      param_9 = L"NULL";
    }
    WppAutoLogTrace(pRVar1,4,1,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x32,param_9,lVar3,
                    &param_10,8,&param_11,8,local_28,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ZD @ 140007dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_ZD
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,_UNICODE_STRING *param_9,uint param_10)

{
  RECORDER_LOG__ *pRVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  
  pRVar1 = g_IfrLog;
  pwVar2 = L"NULL";
  uVar3 = 8;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    if ((param_9 != (_UNICODE_STRING *)0x0) && (uVar3 = param_9->Length, param_9->Length != 0)) {
      pwVar2 = param_9->Buffer;
    }
    if (param_9 == (_UNICODE_STRING *)0x0) {
      param_9 = (_UNICODE_STRING *)L"\b";
    }
    WppAutoLogTrace(pRVar1,param_5,1,param_8,param_7,param_9,2,pwVar2,uVar3,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 140007f3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_d
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,int param_9)

{
  RECORDER_LOG__ *pRVar1;
  undefined4 local_18 [4];
  
  pRVar1 = g_IfrLog;
  local_18[0] = 0x202;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,4,1,param_8,param_7,local_18,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_dd @ 140007ff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_dd
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,int param_9,int param_10)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = g_IfrLog;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x13);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,4,1,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,0x13,&param_9,4,
                    &param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 1400080c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_q
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,void *param_9)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = g_IfrLog;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,param_5,1,param_8,param_7,&param_9,8,0);
  }
  return;
}



===== WdfLdrDiagnosticsValueByNameAsULONG @ 140008180 =====

long __cdecl WdfLdrDiagnosticsValueByNameAsULONG(_UNICODE_STRING *param_1,ulong *param_2)

{
  char cVar1;
  uint uVar2;
  ulong64 uVar3;
  uchar uVar4;
  void *in_R9;
  bool bVar5;
  void *local_res8;
  ulong in_stack_ffffffffffffffc0;
  ushort uVar6;
  ulong uVar7;
  
                    /* 0x8180  3  WdfLdrDiagnosticsValueByNameAsULONG */
  if ((param_1 == (_UNICODE_STRING *)0x0) || (param_2 == (ulong *)0x0)) {
    if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
       ((uVar4 = '\x01', ((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0 ||
        ((WPP_GLOBAL_Control->Control).Level < 4)))) {
      uVar4 = '\0';
    }
    if ((uVar4 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                ((WPP_GLOBAL_Control->Control).Logger,uVar4,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffc0,0xc,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
    }
    return -0x3ffffff3;
  }
  *param_2 = 0;
  local_res8 = (void *)0x0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    uVar2 = WdfLdrOpenRegistryDiagnosticsHandle(&local_res8);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar4 = '\0';
      }
      else {
        uVar4 = '\x01';
      }
      bVar5 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((uVar4 == '\0') && (!bVar5)) goto LAB_140008319;
      uVar3 = (WPP_GLOBAL_Control->Control).Logger;
      uVar6 = 0xe;
      uVar7 = uVar2;
    }
    else {
      uVar2 = FxLdrQueryUlong(local_res8,param_1,param_2);
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar4 = '\0';
      }
      else {
        uVar4 = '\x01';
      }
      bVar5 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((uVar4 == '\0') && (!bVar5)) goto LAB_140008319;
      uVar7 = *param_2;
      uVar3 = (WPP_GLOBAL_Control->Control).Logger;
      uVar6 = 0xf;
    }
    WPP_RECORDER_AND_TRACE_SF_D
              (uVar3,uVar4,bVar5,in_R9,'\x04',in_stack_ffffffffffffffc0,uVar6,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar7);
  }
  else {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar4 = '\0';
    }
    else {
      uVar4 = '\x01';
    }
    if ((uVar4 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                ((WPP_GLOBAL_Control->Control).Logger,uVar4,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffc0,0xd,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
    }
    uVar2 = 0xc000000d;
  }
LAB_140008319:
  bVar5 = true;
  if (local_res8 != (void *)0x0) {
    ZwClose();
  }
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    bVar5 = false;
  }
  if ((bVar5) ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,bVar5,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffffc0,0x10,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar2);
  }
  return uVar2;
}



===== WdfLdrQueryInterface @ 140008410 =====

long __cdecl WdfLdrQueryInterface(_WDF_INTERFACE_HEADER *param_1)

{
  longlong lVar1;
  code *pcVar2;
  
                    /* 0x8410  4  WdfLdrQueryInterface */
  if ((param_1 != (_WDF_INTERFACE_HEADER *)0x0) && (param_1->InterfaceType != (_GUID *)0x0)) {
    lVar1 = RtlCompareMemory(param_1->InterfaceType,&GUID_WDF_LOADER_INTERFACE_STANDARD,0x10);
    if (lVar1 == 0x10) {
      if (param_1->InterfaceSize == 0x30) {
        param_1[1].InterfaceType = (_GUID *)WdfRegisterLibrary;
        *(code **)&param_1[1].InterfaceSize = WdfVersionBind;
        param_1[2].InterfaceType = (_GUID *)WdfVersionUnbind;
        *(code **)&param_1[2].InterfaceSize = WdfLdrDiagnosticsValueByNameAsULONG;
        return 0;
      }
    }
    else {
      lVar1 = RtlCompareMemory(param_1->InterfaceType,&GUID_WDF_LOADER_INTERFACE_DIAGNOSTIC,0x10);
      if (lVar1 == 0x10) {
        if (param_1->InterfaceSize == 0x18) {
          pcVar2 = WdfLdrDiagnosticsValueByNameAsULONG;
LAB_140008526:
          param_1[1].InterfaceType = (_GUID *)pcVar2;
          return 0;
        }
      }
      else {
        lVar1 = RtlCompareMemory(param_1->InterfaceType,&GUID_WDF_LOADER_INTERFACE_CLASS_BIND,0x10);
        if (lVar1 == 0x10) {
          if (param_1->InterfaceSize == 0x20) {
            param_1[1].InterfaceType = (_GUID *)WdfVersionBindClass;
            *(code **)&param_1[1].InterfaceSize = WdfVersionUnbindClass;
            return 0;
          }
        }
        else {
          lVar1 = RtlCompareMemory(param_1->InterfaceType,
                                   &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE,0x10);
          if (lVar1 != 0x10) {
            return -0x3ffffd47;
          }
          if (param_1->InterfaceSize == 0x18) {
            pcVar2 = WdfLdrDriverEntryFailureNotify;
            goto LAB_140008526;
          }
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== WdfVersionUnbindClass @ 140008560 =====

void __cdecl
WdfVersionUnbindClass(_WDF_BIND_INFO *param_1,void **param_2,_WDF_CLASS_BIND_INFO *param_3)

{
                    /* 0x8560  10  WdfVersionUnbindClass */
  DereferenceClassVersion(param_3,(_WDF_BIND_INFO *)param_2,param_2);
  return;
}



===== WppClassicProviderCallback @ 140008580 =====

void __cdecl WppClassicProviderCallback(_GUID *param_1,uchar param_2,void *param_3,void *param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == '\0') {
      *(undefined1 *)((longlong)param_4 + 0x29) = 0;
      *(undefined4 *)((longlong)param_4 + 0x2c) = 0;
      *(undefined8 *)((longlong)param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)((longlong)param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)((longlong)param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *(undefined8 *)param_3;
      *(undefined8 *)((longlong)param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== LibraryAddToClassListLocked @ 1400085dc =====

void __cdecl LibraryAddToClassListLocked(_LIBRARY_MODULE *param_1,_CLASS_MODULE *param_2)

{
  code *pcVar1;
  _LIST_ENTRY *p_Var2;
  _LIST_ENTRY *p_Var3;
  _LIST_ENTRY *p_Var4;
  
  p_Var3 = &param_1->ClassListHead;
  p_Var4 = &param_2->LibraryLinkage;
  p_Var2 = p_Var3->Flink;
  if (p_Var2->Blink != p_Var3) {
    p_Var3 = (_LIST_ENTRY *)0x3;
    pcVar1 = (code *)swi(0x29);
    p_Var2 = (_LIST_ENTRY *)(*pcVar1)();
  }
  p_Var4->Flink = p_Var2;
  p_Var4->Blink = p_Var3;
  p_Var2->Blink = p_Var4;
  p_Var3->Flink = p_Var4;
  return;
}



===== LibraryAddToLibraryListLocked @ 140008610 =====

void __cdecl LibraryAddToLibraryListLocked(_LIBRARY_MODULE *param_1)

{
  code *pcVar1;
  _LIST_ENTRY *p_Var2;
  _LIST_ENTRY *p_Var3;
  
  p_Var3 = &WdfLdrGlobals.LoadedModuleList;
  p_Var2 = &param_1->LibraryListEntry;
  if ((WdfLdrGlobals.LoadedModuleList.Flink)->Blink != &WdfLdrGlobals.LoadedModuleList) {
    p_Var2 = (_LIST_ENTRY *)0x3;
    pcVar1 = (code *)swi(0x29);
    WdfLdrGlobals.LoadedModuleList.Flink = (_LIST_ENTRY *)(*pcVar1)();
  }
  p_Var2->Flink = WdfLdrGlobals.LoadedModuleList.Flink;
  p_Var2->Blink = p_Var3;
  (WdfLdrGlobals.LoadedModuleList.Flink)->Blink = p_Var2;
  WdfLdrGlobals.LoadedModuleList.Flink = p_Var2;
  return;
}



===== LibraryCleanupAndFree @ 14000864c =====

void __cdecl LibraryCleanupAndFree(_LIBRARY_MODULE *param_1)

{
  wchar_t *pwVar1;
  
  LibraryClose(param_1);
  pwVar1 = (param_1->Service).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (param_1->Service).Length = 0;
    (param_1->Service).MaximumLength = 0;
    *(undefined4 *)&(param_1->Service).field_0x4 = 0;
    (param_1->Service).Buffer = (wchar_t *)0x0;
  }
  pwVar1 = (param_1->ImageName).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar1,0);
    (param_1->ImageName).Length = 0;
    (param_1->ImageName).MaximumLength = 0;
    *(undefined4 *)&(param_1->ImageName).field_0x4 = 0;
    (param_1->ImageName).Buffer = (wchar_t *)0x0;
  }
  ExDeleteResourceLite(&param_1->ClientsListLock);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== LibraryClose @ 1400086c4 =====

void __cdecl LibraryClose(_LIBRARY_MODULE *param_1)

{
  if (param_1->LibraryFileObject != (_FILE_OBJECT *)0x0) {
    ObfDereferenceObject();
    param_1->LibraryFileObject = (_FILE_OBJECT *)0x0;
    param_1->LibraryDriverObject = (_DRIVER_OBJECT *)0x0;
  }
  return;
}



===== LibraryCreate @ 1400086fc =====

_LIBRARY_MODULE * __cdecl LibraryCreate(_WDF_LIBRARY_INFO *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  _LIBRARY_MODULE *p_Var2;
  
  p_Var2 = (_LIBRARY_MODULE *)ExAllocatePool2(0x40,0x120,0x374c7846);
  if ((p_Var2 != (_LIBRARY_MODULE *)0x0) &&
     (lVar1 = LibraryModuleInit(p_Var2,param_1,param_2), lVar1 < 0)) {
    LibraryCleanupAndFree(p_Var2);
    p_Var2 = (_LIBRARY_MODULE *)0x0;
  }
  return p_Var2;
}



===== LibraryModuleInit @ 14000876c =====

long __cdecl
LibraryModuleInit(_LIBRARY_MODULE *param_1,_WDF_LIBRARY_INFO *param_2,_UNICODE_STRING *param_3)

{
  _LIST_ENTRY *p_Var1;
  ulong uVar2;
  wchar_t *pwVar3;
  long lVar4;
  
  p_Var1 = &param_1->LibraryListEntry;
  param_1->LibraryRefCount = 1;
  (param_1->LibraryListEntry).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  param_1->LoaderThread = SystemReserved1[0xf];
  lVar4 = 0;
  KeInitializeEvent(&param_1->LoaderEvent,1,0);
  if (param_2 != (_WDF_LIBRARY_INFO *)0x0) {
    param_1->ImplicitlyLoaded = '\x01';
    param_1->LibraryInfo = param_2;
    uVar2 = (param_2->Version).Minor;
    (param_1->Version).Major = (param_2->Version).Major;
    (param_1->Version).Minor = uVar2;
    (param_1->Version).Build = (param_2->Version).Build;
  }
  p_Var1 = &param_1->ClientsListHead;
  (param_1->ClientsListHead).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  ExInitializeResourceLite(&param_1->ClientsListLock);
  p_Var1 = &param_1->ClassListHead;
  (param_1->ClassListHead).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x100,param_3->MaximumLength,0x354c7846);
  (param_1->Service).Buffer = pwVar3;
  if (pwVar3 == (wchar_t *)0x0) {
    lVar4 = -0x3fffff66;
  }
  else {
    (param_1->Service).MaximumLength = param_3->MaximumLength;
    RtlCopyUnicodeString(&param_1->Service,param_3);
  }
  return lVar4;
}



===== LibraryOpen @ 140008878 =====

long __cdecl LibraryOpen(_LIBRARY_MODULE *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  iVar1 = 0;
  if (param_2 != (_UNICODE_STRING *)0x0) {
    iVar1 = IoGetDeviceObjectPointer(param_2,1,&param_1->LibraryFileObject,local_res10);
    if (-1 < iVar1) {
      param_1->LibraryDriverObject = *(_DRIVER_OBJECT **)(local_res10[0] + 8);
    }
  }
  return iVar1;
}



===== LibraryUnloadClasses @ 1400088cc =====

void __cdecl LibraryUnloadClasses(_LIBRARY_MODULE *param_1)

{
  _LIST_ENTRY **pp_Var1;
  _LIST_ENTRY *p_Var2;
  _LIST_ENTRY *p_Var3;
  code *pcVar4;
  _LIST_ENTRY *p_Var5;
  uchar uVar6;
  void *in_R9;
  uchar in_stack_ffffffffffffffb8;
  ulong in_stack_ffffffffffffffc0;
  ushort in_stack_ffffffffffffffc8;
  _GUID *in_stack_ffffffffffffffd0;
  _LIST_ENTRY local_18;
  
  p_Var5 = &param_1->ClassListHead;
  local_18.Flink = &local_18;
  local_18.Blink = &local_18;
  while (p_Var2 = p_Var5->Flink, p_Var2 != p_Var5) {
    if ((p_Var2->Blink != p_Var5) || (p_Var3 = p_Var2->Flink, p_Var3->Blink != p_Var2))
    goto LAB_1400089ee;
    p_Var5->Flink = p_Var3;
    p_Var3->Blink = p_Var5;
    if ((local_18.Blink)->Flink != &local_18) goto LAB_1400089ee;
    p_Var2->Blink = local_18.Blink;
    p_Var2->Flink = &local_18;
    (local_18.Blink)->Flink = p_Var2;
    local_18.Blink = p_Var2;
  }
  while( true ) {
    p_Var5 = local_18.Flink;
    if (local_18.Flink == &local_18) {
      return;
    }
    if (((local_18.Flink)->Blink != &local_18) ||
       (p_Var2 = (local_18.Flink)->Flink, p_Var2->Blink != local_18.Flink)) break;
    p_Var2->Blink = &local_18;
    pp_Var1 = &local_18.Flink[-8].Blink;
    (local_18.Flink)->Blink = local_18.Flink;
    (local_18.Flink)->Flink = local_18.Flink;
    local_18.Flink = p_Var2;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar6 = '\0';
    }
    else {
      uVar6 = '\x01';
    }
    if ((uVar6 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Zq
                ((WPP_GLOBAL_Control->Control).Logger,uVar6,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8
                 ,in_stack_ffffffffffffffd0,(_UNICODE_STRING *)(p_Var5 + 1),pp_Var1);
    }
    ClassUnload((_CLASS_MODULE *)pp_Var1);
    ClassReleaseReference((_CLASS_MODULE *)pp_Var1);
  }
LAB_1400089ee:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Zq @ 140008a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_Zq
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,_UNICODE_STRING *param_9,void *param_10)

{
  RECORDER_LOG__ *pRVar1;
  ushort uVar2;
  wchar_t *pwVar3;
  
  pRVar1 = g_IfrLog;
  pwVar3 = L"NULL";
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,0x16);
  }
  if (param_3 != '\0') {
    if (param_9 == (_UNICODE_STRING *)0x0) {
      uVar2 = 8;
    }
    else {
      uVar2 = param_9->Length;
      if (param_9->Length != 0) {
        pwVar3 = param_9->Buffer;
      }
    }
    if (param_9 == (_UNICODE_STRING *)0x0) {
      param_9 = (_UNICODE_STRING *)L"\b";
    }
    WppAutoLogTrace(pRVar1,4,1,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,0x16,param_9,2,pwVar3
                    ,uVar2,&param_10,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qZ @ 140008b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_qZ
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,void *param_9,_UNICODE_STRING *param_10)

{
  ushort uVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  pwVar2 = (wchar_t *)param_10;
  pwVar3 = L"NULL";
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,0xc);
  }
  if (param_3 != '\0') {
    if ((_UNICODE_STRING *)pwVar2 == (_UNICODE_STRING *)0x0) {
      uVar1 = 8;
    }
    else {
      uVar1 = ((_UNICODE_STRING *)pwVar2)->Length;
      if (((_UNICODE_STRING *)pwVar2)->Length != 0) {
        pwVar3 = ((_UNICODE_STRING *)pwVar2)->Buffer;
      }
    }
    if ((_UNICODE_STRING *)pwVar2 == (_UNICODE_STRING *)0x0) {
      pwVar2 = L"\b";
    }
    WppAutoLogTrace(param_4,4,1,param_8,0xc,&param_9,8,pwVar2,2,pwVar3,uVar1,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140008cd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_qq
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,void *param_9,void *param_10)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = g_IfrLog;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,0x15);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,4,1,WPP_826fa21cbbb23b6842a63b909f3407fa_Traceguids,0x15,&param_9,8,
                    &param_10,8,0);
  }
  return;
}



===== ClassCreate @ 140008da8 =====

long __cdecl
ClassCreate(_WDF_CLASS_LIBRARY_INFO *param_1,_LIBRARY_MODULE *param_2,_UNICODE_STRING *param_3,
           _CLASS_MODULE **param_4)

{
  long lVar1;
  _CLASS_MODULE *p_Var2;
  
  *param_4 = (_CLASS_MODULE *)0x0;
  p_Var2 = (_CLASS_MODULE *)ExAllocatePool2(0x40,0x128,0x644c7846);
  if (p_Var2 == (_CLASS_MODULE *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    lVar1 = ClassModuleInit(p_Var2,param_1,param_2,param_3);
    if (lVar1 < 0) {
      ClassCleanupAndFree(p_Var2);
    }
    else {
      *param_4 = p_Var2;
    }
  }
  return lVar1;
}



===== ClassModuleInit @ 140008e44 =====

long __cdecl
ClassModuleInit(_CLASS_MODULE *param_1,_WDF_CLASS_LIBRARY_INFO *param_2,_LIBRARY_MODULE *param_3,
               _UNICODE_STRING *param_4)

{
  _LIST_ENTRY *p_Var1;
  ulong uVar2;
  wchar_t *pwVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_2 != (_WDF_CLASS_LIBRARY_INFO *)0x0) {
    param_1->ImplicitlyLoaded = '\x01';
    param_1->ClassLibraryInfo = param_2;
    uVar2 = (param_2->Version).Minor;
    (param_1->Version).Major = (param_2->Version).Major;
    (param_1->Version).Minor = uVar2;
    (param_1->Version).Build = (param_2->Version).Build;
  }
  param_1->Library = param_3;
  param_1->ClassRefCount = 1;
  param_1->LoaderThread = SystemReserved1[0xf];
  KeInitializeEvent(&param_1->LoaderEvent,1,0);
  ExInitializeResourceLite(param_1);
  p_Var1 = &param_1->ClientsListHead;
  (param_1->ClientsListHead).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  p_Var1 = &param_1->LibraryLinkage;
  (param_1->LibraryLinkage).Blink = p_Var1;
  p_Var1->Flink = p_Var1;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x100,param_4->MaximumLength,0x654c7846);
  (param_1->Service).Buffer = pwVar3;
  if (pwVar3 == (wchar_t *)0x0) {
    lVar4 = -0x3fffff66;
  }
  else {
    (param_1->Service).MaximumLength = param_4->MaximumLength;
    RtlCopyUnicodeString(&param_1->Service,param_4);
  }
  return lVar4;
}



===== WPP_RECORDER_AND_TRACE_SF_qD @ 140008f4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_RECORDER_AND_TRACE_SF_qD
          (ulong64 param_1,uchar param_2,uchar param_3,void *param_4,uchar param_5,ulong param_6,
          ushort param_7,_GUID *param_8,void *param_9,uint param_10)

{
  RECORDER_LOG__ *pRVar1;
  undefined4 local_18 [4];
  
  pRVar1 = g_IfrLog;
  local_18[0] = 0xc0000184;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,0x10);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(pRVar1,4,1,WPP_f678c93d87ef308401ed114fc35e3b31_Traceguids,0x10,&param_9,8,
                    local_18,4,0);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_TelemetryProviderProv @ 140009028 =====

void __cdecl _tlgDefineProvider_annotation__Tlgg_TelemetryProviderProv(void)

{
  return;
}



===== __GSHandlerCheck_SEH @ 140009038 =====

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck_SEH
          (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,_DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  EXCEPTION_DISPOSITION EVar3;
  
  puVar2 = param_4->HandlerData;
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,param_4,(_GS_HANDLER_DATA *)(puVar2 + (ulonglong)uVar1 * 4 + 1));
  EVar3 = ExceptionContinueSearch;
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    EVar3 = __C_specific_handler
                      ((_EXCEPTION_RECORD *)param_1,param_2,(_CONTEXT *)param_3,
                       (_DISPATCHER_CONTEXT *)param_4);
  }
  return EVar3;
}



===== __security_check_cookie @ 1400090d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(void)

{
  ulong64 in_RCX;
  
  if ((in_RCX != __security_cookie) || ((short)(in_RCX >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(in_RCX);
  }
  return;
}



===== _guard_dispatch_icall @ 140009110 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall_nop replaced with injection: guard_dispatch_icall */

void __cdecl _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall_nop @ 140009140 =====

/* WARNING: This is an inlined function */

void __cdecl _guard_dispatch_icall_nop(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140009140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140009170 =====

/* WARNING: Function: _guard_dispatch_icall_nop replaced with injection: guard_dispatch_icall */

void __cdecl _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 1400091c0 =====

void __cdecl memset(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 *in_R8;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  longlong extraout_XMM0_Qa;
  longlong lVar9;
  longlong extraout_XMM0_Qb;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar6 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar6) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar6) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    if (((__isa_info.info & 2) != 0) && ((undefined1 *)0x31f < in_R8)) {
      lVar9 = lVar4;
      if ((__isa_info.info & 1) == 0) {
        __memset_query();
        lVar4 = extraout_XMM0_Qa;
        lVar9 = extraout_XMM0_Qb;
      }
      *in_RCX = lVar4;
      in_RCX[1] = lVar9;
      in_RCX[2] = lVar4;
      in_RCX[3] = lVar9;
      in_RCX[4] = lVar4;
      in_RCX[5] = lVar9;
      in_RCX[6] = lVar4;
      in_RCX[7] = lVar9;
      puVar5 = (undefined1 *)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0);
      for (puVar7 = (undefined1 *)
                    ((longlong)in_RCX +
                    ((longlong)in_R8 - (longlong)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0)));
          puVar7 != (undefined1 *)0x0; puVar7 = puVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return;
    }
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
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
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar6 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar6);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== __memset_repmovs @ 140009300 =====

void __cdecl __memset_repmovs(void)

{
  undefined1 *in_RCX;
  undefined1 *puVar1;
  longlong in_R8;
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
  
  if ((__isa_info.info & 1) == 0) {
    __memset_query();
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
  *in_RCX = in_XMM0_Ba;
  in_RCX[1] = in_XMM0_Bb;
  in_RCX[2] = in_XMM0_Bc;
  in_RCX[3] = in_XMM0_Bd;
  in_RCX[4] = in_XMM0_Be;
  in_RCX[5] = in_XMM0_Bf;
  in_RCX[6] = in_XMM0_Bg;
  in_RCX[7] = in_XMM0_Bh;
  in_RCX[8] = in_XMM0_Bi;
  in_RCX[9] = in_XMM0_Bj;
  in_RCX[10] = in_XMM0_Bk;
  in_RCX[0xb] = in_XMM0_Bl;
  in_RCX[0xc] = in_XMM0_Bm;
  in_RCX[0xd] = in_XMM0_Bn;
  in_RCX[0xe] = in_XMM0_Bo;
  in_RCX[0xf] = in_XMM0_Bp;
  in_RCX[0x10] = in_XMM0_Ba;
  in_RCX[0x11] = in_XMM0_Bb;
  in_RCX[0x12] = in_XMM0_Bc;
  in_RCX[0x13] = in_XMM0_Bd;
  in_RCX[0x14] = in_XMM0_Be;
  in_RCX[0x15] = in_XMM0_Bf;
  in_RCX[0x16] = in_XMM0_Bg;
  in_RCX[0x17] = in_XMM0_Bh;
  in_RCX[0x18] = in_XMM0_Bi;
  in_RCX[0x19] = in_XMM0_Bj;
  in_RCX[0x1a] = in_XMM0_Bk;
  in_RCX[0x1b] = in_XMM0_Bl;
  in_RCX[0x1c] = in_XMM0_Bm;
  in_RCX[0x1d] = in_XMM0_Bn;
  in_RCX[0x1e] = in_XMM0_Bo;
  in_RCX[0x1f] = in_XMM0_Bp;
  in_RCX[0x20] = in_XMM0_Ba;
  in_RCX[0x21] = in_XMM0_Bb;
  in_RCX[0x22] = in_XMM0_Bc;
  in_RCX[0x23] = in_XMM0_Bd;
  in_RCX[0x24] = in_XMM0_Be;
  in_RCX[0x25] = in_XMM0_Bf;
  in_RCX[0x26] = in_XMM0_Bg;
  in_RCX[0x27] = in_XMM0_Bh;
  in_RCX[0x28] = in_XMM0_Bi;
  in_RCX[0x29] = in_XMM0_Bj;
  in_RCX[0x2a] = in_XMM0_Bk;
  in_RCX[0x2b] = in_XMM0_Bl;
  in_RCX[0x2c] = in_XMM0_Bm;
  in_RCX[0x2d] = in_XMM0_Bn;
  in_RCX[0x2e] = in_XMM0_Bo;
  in_RCX[0x2f] = in_XMM0_Bp;
  in_RCX[0x30] = in_XMM0_Ba;
  in_RCX[0x31] = in_XMM0_Bb;
  in_RCX[0x32] = in_XMM0_Bc;
  in_RCX[0x33] = in_XMM0_Bd;
  in_RCX[0x34] = in_XMM0_Be;
  in_RCX[0x35] = in_XMM0_Bf;
  in_RCX[0x36] = in_XMM0_Bg;
  in_RCX[0x37] = in_XMM0_Bh;
  in_RCX[0x38] = in_XMM0_Bi;
  in_RCX[0x39] = in_XMM0_Bj;
  in_RCX[0x3a] = in_XMM0_Bk;
  in_RCX[0x3b] = in_XMM0_Bl;
  in_RCX[0x3c] = in_XMM0_Bm;
  in_RCX[0x3d] = in_XMM0_Bn;
  in_RCX[0x3e] = in_XMM0_Bo;
  in_RCX[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = in_RCX + (in_R8 - (longlong)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return;
}



===== __memset_query @ 140009380 =====

void __cdecl __memset_query(void)

{
  __cpu_features_init();
  return;
}



===== __memset_spec_ermsb @ 140009400 =====

void __cdecl __memset_spec_ermsb(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 *in_R8;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar6 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar6) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar6) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    if ((undefined1 *)0x31f < in_R8) {
      *in_RCX = lVar4;
      in_RCX[1] = lVar4;
      in_RCX[2] = lVar4;
      in_RCX[3] = lVar4;
      in_RCX[4] = lVar4;
      in_RCX[5] = lVar4;
      in_RCX[6] = lVar4;
      in_RCX[7] = lVar4;
      puVar5 = (undefined1 *)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0);
      for (puVar7 = (undefined1 *)
                    ((longlong)in_RCX +
                    ((longlong)in_R8 - (longlong)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0)));
          puVar7 != (undefined1 *)0x0; puVar7 = puVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return;
    }
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
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
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar6 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar6);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== __memset_spec_ermsb_repmovsb @ 140009540 =====

void __cdecl __memset_spec_ermsb_repmovsb(void)

{
  undefined1 *in_RCX;
  undefined1 *puVar1;
  longlong in_R8;
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
  
  *in_RCX = in_XMM0_Ba;
  in_RCX[1] = in_XMM0_Bb;
  in_RCX[2] = in_XMM0_Bc;
  in_RCX[3] = in_XMM0_Bd;
  in_RCX[4] = in_XMM0_Be;
  in_RCX[5] = in_XMM0_Bf;
  in_RCX[6] = in_XMM0_Bg;
  in_RCX[7] = in_XMM0_Bh;
  in_RCX[8] = in_XMM0_Bi;
  in_RCX[9] = in_XMM0_Bj;
  in_RCX[10] = in_XMM0_Bk;
  in_RCX[0xb] = in_XMM0_Bl;
  in_RCX[0xc] = in_XMM0_Bm;
  in_RCX[0xd] = in_XMM0_Bn;
  in_RCX[0xe] = in_XMM0_Bo;
  in_RCX[0xf] = in_XMM0_Bp;
  in_RCX[0x10] = in_XMM0_Ba;
  in_RCX[0x11] = in_XMM0_Bb;
  in_RCX[0x12] = in_XMM0_Bc;
  in_RCX[0x13] = in_XMM0_Bd;
  in_RCX[0x14] = in_XMM0_Be;
  in_RCX[0x15] = in_XMM0_Bf;
  in_RCX[0x16] = in_XMM0_Bg;
  in_RCX[0x17] = in_XMM0_Bh;
  in_RCX[0x18] = in_XMM0_Bi;
  in_RCX[0x19] = in_XMM0_Bj;
  in_RCX[0x1a] = in_XMM0_Bk;
  in_RCX[0x1b] = in_XMM0_Bl;
  in_RCX[0x1c] = in_XMM0_Bm;
  in_RCX[0x1d] = in_XMM0_Bn;
  in_RCX[0x1e] = in_XMM0_Bo;
  in_RCX[0x1f] = in_XMM0_Bp;
  in_RCX[0x20] = in_XMM0_Ba;
  in_RCX[0x21] = in_XMM0_Bb;
  in_RCX[0x22] = in_XMM0_Bc;
  in_RCX[0x23] = in_XMM0_Bd;
  in_RCX[0x24] = in_XMM0_Be;
  in_RCX[0x25] = in_XMM0_Bf;
  in_RCX[0x26] = in_XMM0_Bg;
  in_RCX[0x27] = in_XMM0_Bh;
  in_RCX[0x28] = in_XMM0_Bi;
  in_RCX[0x29] = in_XMM0_Bj;
  in_RCX[0x2a] = in_XMM0_Bk;
  in_RCX[0x2b] = in_XMM0_Bl;
  in_RCX[0x2c] = in_XMM0_Bm;
  in_RCX[0x2d] = in_XMM0_Bn;
  in_RCX[0x2e] = in_XMM0_Bo;
  in_RCX[0x2f] = in_XMM0_Bp;
  in_RCX[0x30] = in_XMM0_Ba;
  in_RCX[0x31] = in_XMM0_Bb;
  in_RCX[0x32] = in_XMM0_Bc;
  in_RCX[0x33] = in_XMM0_Bd;
  in_RCX[0x34] = in_XMM0_Be;
  in_RCX[0x35] = in_XMM0_Bf;
  in_RCX[0x36] = in_XMM0_Bg;
  in_RCX[0x37] = in_XMM0_Bh;
  in_RCX[0x38] = in_XMM0_Bi;
  in_RCX[0x39] = in_XMM0_Bj;
  in_RCX[0x3a] = in_XMM0_Bk;
  in_RCX[0x3b] = in_XMM0_Bl;
  in_RCX[0x3c] = in_XMM0_Bm;
  in_RCX[0x3d] = in_XMM0_Bn;
  in_RCX[0x3e] = in_XMM0_Bo;
  in_RCX[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = in_RCX + (in_R8 - (longlong)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return;
}



===== __memset_spec_plain @ 1400095c0 =====

void __cdecl __memset_spec_plain(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *in_R8;
  ulonglong uVar5;
  longlong *plVar6;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar5 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar5) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar5) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar6 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar5 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
      do {
        *plVar2 = lVar4;
        plVar2[1] = lVar4;
        plVar2[2] = lVar4;
        plVar2[3] = lVar4;
        uVar5 = uVar5 - 1;
        plVar2[4] = lVar4;
        plVar2[5] = lVar4;
        plVar2[6] = lVar4;
        plVar2[7] = lVar4;
        plVar2 = plVar2 + 8;
      } while (uVar5 != 0);
      *plVar6 = lVar4;
      plVar6[1] = lVar4;
      plVar6[2] = lVar4;
      plVar6[3] = lVar4;
      plVar6[4] = lVar4;
      plVar6[5] = lVar4;
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar5 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar5);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar5);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== memcpy @ 140009700 =====

void __cdecl memcpy(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *in_RCX;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined8 *in_RDX;
  longlong lVar14;
  ulonglong in_R8;
  undefined1 *puVar15;
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
  
  if (in_R8 < 8) {
    if (in_R8 != 0) {
      puVar9 = in_RCX;
      if (in_RDX < in_RCX) {
        puVar15 = (undefined1 *)((longlong)in_RCX + in_R8);
        do {
          puVar2 = puVar15 + ((longlong)in_RDX - (longlong)in_RCX) + -1;
          puVar15 = puVar15 + -1;
          in_R8 = in_R8 - 1;
          *puVar15 = *puVar2;
        } while (in_R8 != 0);
        return;
      }
      do {
        in_R8 = in_R8 - 1;
        *(undefined1 *)puVar9 =
             *(undefined1 *)((longlong)puVar9 + ((longlong)in_RDX - (longlong)in_RCX));
        puVar9 = (undefined8 *)((longlong)puVar9 + 1);
      } while (in_R8 != 0);
    }
    return;
  }
  if (in_R8 < 0x11) {
    uVar3 = *(undefined8 *)((longlong)in_RDX + (in_R8 - 8));
    *in_RCX = *in_RDX;
    *(undefined8 *)((longlong)in_RCX + (in_R8 - 8)) = uVar3;
    return;
  }
  if (in_R8 < 0x21) {
    uVar3 = in_RDX[1];
    puVar9 = (undefined8 *)((longlong)in_RDX + (in_R8 - 0x10));
    uVar4 = *puVar9;
    uVar5 = puVar9[1];
    *in_RCX = *in_RDX;
    in_RCX[1] = uVar3;
    puVar9 = (undefined8 *)((longlong)in_RCX + (in_R8 - 0x10));
    *puVar9 = uVar4;
    puVar9[1] = uVar5;
    return;
  }
  lVar14 = (longlong)in_RDX - (longlong)in_RCX;
  if ((in_RDX < in_RCX) && (in_RCX < (undefined8 *)((longlong)in_RDX + in_R8))) {
    puVar13 = (undefined4 *)((longlong)in_RCX + lVar14 + (in_R8 - 0x10));
    uVar18 = puVar13[1];
    uVar20 = puVar13[2];
    uVar22 = puVar13[3];
    puVar11 = (undefined4 *)((longlong)in_RCX + (in_R8 - 0x10));
    uVar16 = in_R8 - 0x10;
    puVar12 = puVar11;
    uVar19 = *puVar13;
    uVar21 = uVar18;
    uVar23 = uVar20;
    uVar25 = uVar22;
    if (((ulonglong)puVar11 & 0xf) != 0) {
      puVar12 = (undefined4 *)((ulonglong)puVar11 & 0xfffffffffffffff0);
      puVar1 = (undefined4 *)((longlong)puVar12 + lVar14);
      uVar19 = *puVar1;
      uVar21 = puVar1[1];
      uVar23 = puVar1[2];
      uVar25 = puVar1[3];
      *puVar11 = *puVar13;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 0xc)) = uVar18;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 8)) = uVar20;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 4)) = uVar22;
      uVar16 = (longlong)puVar12 - (longlong)in_RCX;
    }
    uVar17 = uVar16 >> 6;
    if (uVar17 != 0) {
      uVar16 = uVar16 & 0x3f;
      puVar13 = puVar12;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x10);
        uVar3 = *puVar9;
        uVar4 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x20);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x30);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar12 = (undefined4 *)((longlong)puVar13 + lVar14 + -0x40);
        uVar19 = *puVar12;
        uVar21 = puVar12[1];
        uVar23 = puVar12[2];
        uVar25 = puVar12[3];
        *puVar13 = uVar18;
        puVar13[1] = uVar20;
        puVar13[2] = uVar22;
        puVar13[3] = uVar24;
        puVar12 = puVar13 + -0x10;
        uVar17 = uVar17 - 1;
        *(undefined8 *)(puVar13 + -4) = uVar3;
        *(undefined8 *)(puVar13 + -2) = uVar4;
        *(undefined8 *)(puVar13 + -8) = uVar5;
        *(undefined8 *)(puVar13 + -6) = uVar6;
        *(undefined8 *)(puVar13 + -0xc) = uVar7;
        *(undefined8 *)(puVar13 + -10) = uVar8;
        puVar13 = puVar12;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
      *puVar12 = uVar19;
      puVar12[1] = uVar21;
      puVar12[2] = uVar23;
      puVar12[3] = uVar25;
      puVar13 = (undefined4 *)((longlong)puVar12 + lVar14 + -0x10);
      uVar19 = *puVar13;
      uVar21 = puVar13[1];
      uVar23 = puVar13[2];
      uVar25 = puVar13[3];
      puVar12 = puVar12 + -4;
    }
    if ((uVar16 & 0xf) != 0) {
      puVar9 = (undefined8 *)((longlong)puVar12 - (uVar16 & 0xf));
      uVar3 = ((undefined8 *)((longlong)puVar9 + lVar14))[1];
      *puVar9 = *(undefined8 *)((longlong)puVar9 + lVar14);
      puVar9[1] = uVar3;
    }
    *puVar12 = uVar19;
    puVar12[1] = uVar21;
    puVar12[2] = uVar23;
    puVar12[3] = uVar25;
    return;
  }
  puVar13 = (undefined4 *)((longlong)in_RCX + lVar14);
  uVar18 = puVar13[1];
  uVar20 = puVar13[2];
  uVar22 = puVar13[3];
  puVar9 = in_RCX + 2;
  uVar19 = *puVar13;
  uVar21 = uVar18;
  uVar23 = uVar20;
  uVar25 = uVar22;
  if (((ulonglong)puVar9 & 0xf) != 0) {
    puVar12 = (undefined4 *)(((ulonglong)puVar9 & 0xfffffffffffffff0) + lVar14);
    uVar19 = *puVar12;
    uVar21 = puVar12[1];
    uVar23 = puVar12[2];
    uVar25 = puVar12[3];
    *(undefined4 *)in_RCX = *puVar13;
    *(undefined4 *)((longlong)in_RCX + 4) = uVar18;
    *(undefined4 *)(in_RCX + 1) = uVar20;
    *(undefined4 *)((longlong)in_RCX + 0xc) = uVar22;
    puVar9 = (undefined8 *)(((ulonglong)puVar9 & 0xfffffffffffffff0) + 0x10);
  }
  puVar15 = (undefined1 *)((longlong)in_RCX + (in_R8 - (longlong)puVar9));
  uVar16 = (ulonglong)puVar15 >> 6;
  if (uVar16 != 0) {
    if (uVar16 < 0x1001) {
      puVar15 = (undefined1 *)((ulonglong)puVar15 & 0x3f);
      puVar10 = puVar9;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar10 + lVar14);
        uVar4 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x20);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar13 = (undefined4 *)((longlong)puVar10 + lVar14 + 0x30);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *(undefined4 *)(puVar10 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar10 + -0xc) = uVar20;
        *(undefined4 *)(puVar10 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar10 + -4) = uVar24;
        puVar9 = puVar10 + 8;
        uVar16 = uVar16 - 1;
        *puVar10 = uVar3;
        puVar10[1] = uVar4;
        puVar10[2] = uVar5;
        puVar10[3] = uVar6;
        puVar10[4] = uVar7;
        puVar10[5] = uVar8;
        puVar10 = puVar9;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar16 != 0);
    }
    else {
      uVar16 = (ulonglong)puVar15 >> 6;
      puVar15 = (undefined1 *)((ulonglong)puVar15 & 0x3f);
      puVar10 = puVar9;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar10 + lVar14);
        uVar4 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x20);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar13 = (undefined4 *)((longlong)puVar10 + lVar14 + 0x30);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *(undefined4 *)(puVar10 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar10 + -0xc) = uVar20;
        *(undefined4 *)(puVar10 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar10 + -4) = uVar24;
        puVar9 = puVar10 + 8;
        uVar16 = uVar16 - 1;
        *puVar10 = uVar3;
        puVar10[1] = uVar4;
        puVar10[2] = uVar5;
        puVar10[3] = uVar6;
        puVar10[4] = uVar7;
        puVar10[5] = uVar8;
        puVar10 = puVar9;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar16 != 0);
    }
  }
  for (uVar16 = (ulonglong)puVar15 >> 4; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)(puVar9 + -2) = uVar19;
    *(undefined4 *)((longlong)puVar9 + -0xc) = uVar21;
    *(undefined4 *)(puVar9 + -1) = uVar23;
    *(undefined4 *)((longlong)puVar9 + -4) = uVar25;
    puVar13 = (undefined4 *)((longlong)puVar9 + lVar14);
    uVar19 = *puVar13;
    uVar21 = puVar13[1];
    uVar23 = puVar13[2];
    uVar25 = puVar13[3];
    puVar9 = puVar9 + 2;
  }
  if (((ulonglong)puVar15 & 0xf) != 0) {
    puVar10 = (undefined8 *)((longlong)puVar9 + (((ulonglong)puVar15 & 0xf) - 0x10));
    uVar3 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
    *puVar10 = *(undefined8 *)((longlong)puVar10 + lVar14);
    puVar10[1] = uVar3;
  }
  *(undefined4 *)(puVar9 + -2) = uVar19;
  *(undefined4 *)((longlong)puVar9 + -0xc) = uVar21;
  *(undefined4 *)(puVar9 + -1) = uVar23;
  *(undefined4 *)((longlong)puVar9 + -4) = uVar25;
  return;
}



===== _tlgEnableCallback @ 140010010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
_tlgEnableCallback(_GUID *param_1,ulong param_2,uchar param_3,ulong64 param_4,ulong64 param_5,
                  _EVENT_FILTER_DESCRIPTOR *param_6,void *param_7)

{
  int iVar1;
  
  if (param_7 != (void *)0x0) {
    if (param_2 == 0) {
      *(undefined4 *)param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == '\0') {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *(int *)param_7 = iVar1;
      *(ulong64 *)((longlong)param_7 + 0x10) = param_4;
      *(ulong64 *)((longlong)param_7 + 0x18) = param_5;
    }
    if (*(code **)((longlong)param_7 + 0x28) != (code *)0x0) {
      (**(code **)((longlong)param_7 + 0x28))(param_1);
    }
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14001008c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl
TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
          (_tlgProvider_t *param_1,
          _func___cdecl_void__GUID_ptr_ulong_uchar_ulong64_ulong64__EVENT_FILTER_DESCRIPTOR_ptr_void_ptr
          *param_2,void *param_3)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(_Tlgg_TelemetryProviderProv.ProviderMetadataPtr + -8);
  uStack_24 = *(undefined4 *)(_Tlgg_TelemetryProviderProv.ProviderMetadataPtr + -6);
  uStack_20 = *(undefined4 *)(_Tlgg_TelemetryProviderProv.ProviderMetadataPtr + -4);
  uStack_1c = *(undefined4 *)(_Tlgg_TelemetryProviderProv.ProviderMetadataPtr + -2);
  if (_Tlgg_TelemetryProviderProv.RegHandle != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _Tlgg_TelemetryProviderProv.EnableCallback =
       (_func___cdecl_void__GUID_ptr_ulong_uchar_ulong64_ulong64__EVENT_FILTER_DESCRIPTOR_ptr_void_ptr
        *)0x0;
  _Tlgg_TelemetryProviderProv.CallbackContext = (void *)0x0;
  *(undefined8 *)(puVar4 + -8) = 0x1400100ef;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&_Tlgg_TelemetryProviderProv,0x14000d030);
  if (iVar3 == 0) {
    uVar1 = *_Tlgg_TelemetryProviderProv.ProviderMetadataPtr;
    *(undefined8 *)(puVar4 + -8) = 0x140010116;
    EtwSetInformation(_Tlgg_TelemetryProviderProv.RegHandle,2,
                      _Tlgg_TelemetryProviderProv.ProviderMetadataPtr,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001012a;
  return iVar3;
}



===== WdfRegisterLibrary @ 140010140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WdfRegisterLibrary(_WDF_LIBRARY_INFO *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  _DRIVER_OBJECT *p_Var4;
  _LIBRARY_MODULE *p_Var5;
  _LIBRARY_MODULE *p_Var6;
  uchar uVar7;
  ulong in_stack_ffffffffffffffb0;
  
                    /* 0x10140  6  WdfRegisterLibrary */
  FxLdrAcquireLoadedModuleLock();
  p_Var4 = GetDriverObjectFromDeviceName(param_3);
  p_Var5 = FindModuleByServiceNameLocked(param_2);
  bVar1 = true;
  if (p_Var5 == (_LIBRARY_MODULE *)0x0) {
    p_Var6 = LibraryCreate(param_1,param_2);
    if (p_Var6 == (_LIBRARY_MODULE *)0x0) {
      uVar3 = 0xc000009a;
LAB_140010411:
      FxLdrReleaseLoadedModuleLock();
      return uVar3;
    }
    p_Var6->IsBootDriver = '\x01';
    uVar3 = GetLibraryNameAndBase(p_Var6,param_2,p_Var4);
    if ((int)uVar3 < 0) {
      LibraryCleanupAndFree(p_Var6);
      goto LAB_140010411;
    }
    LibraryAddToLibraryListLocked(p_Var6);
    bVar2 = true;
LAB_1400101f4:
    LibraryAddReferenceLocked(p_Var6);
  }
  else {
    p_Var6 = p_Var5;
    LibraryCopyInfo(p_Var5,param_1);
    p_Var6->IsBootDriver = '\0';
    uVar3 = GetLibraryNameAndBase(p_Var6,param_2,p_Var4);
    p_Var6 = (_LIBRARY_MODULE *)0x0;
    if (-1 < (int)uVar3) {
      p_Var6 = p_Var5;
    }
    bVar2 = false;
    if (p_Var6 != (_LIBRARY_MODULE *)0x0) goto LAB_1400101f4;
  }
  FxLdrReleaseLoadedModuleLock();
  if (-1 < (int)uVar3) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar7 = '\0';
    }
    else {
      uVar7 = '\x01';
    }
    if ((uVar7 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,'\x04',in_stack_ffffffffffffffb0,
                 0x47,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,p_Var6);
    }
    uVar3 = LibraryOpen(p_Var6,param_3);
    if ((int)uVar3 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar7 = '\0';
      }
      else {
        uVar7 = '\x01';
      }
      if ((uVar7 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                   WPP_f35a5499df3a35f353983bcad3180794_Traceguids,'\x04',in_stack_ffffffffffffffb0,
                   0x48,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_3,uVar3);
      }
    }
    else {
      uVar3 = (*p_Var6->LibraryInfo->LibraryCommission)();
      if ((int)uVar3 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 4)) {
          uVar7 = '\0';
        }
        else {
          uVar7 = '\x01';
        }
        if ((uVar7 != '\0') ||
           (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_D
                    ((WPP_GLOBAL_Control->Control).Logger,uVar7,
                     WPP_RECORDER_INITIALIZED !=
                     (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                     WPP_f35a5499df3a35f353983bcad3180794_Traceguids,'\x04',
                     in_stack_ffffffffffffffb0,0x49,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                     uVar3);
        }
      }
    }
  }
  if (p_Var6 == (_LIBRARY_MODULE *)0x0) {
    return uVar3;
  }
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      bVar1 = false;
    }
    if ((bVar1) ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,bVar1,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,'\x04',in_stack_ffffffffffffffb0,
                 0x4a,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_3,uVar3);
    }
    p_Var6->LibraryInfo = (_WDF_LIBRARY_INFO *)0x0;
    LibraryClose(p_Var6);
    if (!bVar2) goto LAB_140010402;
    LibraryReleaseReference(p_Var6);
  }
  else if (!bVar2) goto LAB_140010402;
  LibraryLoaderUnlock(p_Var6);
LAB_140010402:
  LibraryReleaseReference(p_Var6);
  return uVar3;
}



===== WppCleanupKm @ 140010438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppCleanupKm(_DRIVER_OBJECT *param_1)

{
  WPP_PROJECT_CONTROL_BLOCK *pWVar1;
  
  if (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
    pWVar1 = (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control->Control;
    if (WPPTraceSuite == WppTraceServer08) {
      for (; pWVar1 != (WPP_PROJECT_CONTROL_BLOCK *)0x0;
          pWVar1 = (WPP_PROJECT_CONTROL_BLOCK *)(pWVar1->Control).Next) {
        if ((pWVar1->Control).RegHandle != 0) {
          (*pfnEtwUnregister)((pWVar1->Control).RegHandle);
          (pWVar1->Control).RegHandle = 0;
        }
      }
    }
    else if (WPPTraceSuite == WppTraceWinXP) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,0);
    WPP_GLOBAL_Control = (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1400104dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppInitKm(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  _func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
  *p_Var1;
  WPP_PROJECT_CONTROL_BLOCK *pWVar2;
  
  if (WPP_GLOBAL_Control != WPP_MAIN_CB) {
    WPP_GLOBAL_Control = WPP_MAIN_CB;
    if (WPPTraceSuite == WppTraceServer08) {
      pWVar2 = WPP_MAIN_CB;
      do {
        p_Var1 = pfnEtwRegisterClassicProvider;
        (pWVar2->Control).RegHandle = 0;
        (*p_Var1)((pWVar2->Control).ControlGuid,0,WppClassicProviderCallback,pWVar2,
                  &(pWVar2->Control).RegHandle);
        pWVar2 = (WPP_PROJECT_CONTROL_BLOCK *)(pWVar2->Control).Next;
      } while (pWVar2 != (WPP_PROJECT_CONTROL_BLOCK *)0x0);
    }
    else if (WPPTraceSuite == WppTraceWinXP) {
      WPP_MAIN_CB[0].Control.Callback = WppTraceCallback;
      IoWMIRegistrationControl(WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,0,param_2);
    WPP_RECORDER_INITIALIZED = WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1400105a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppLoadTracingSupport(void)

{
  ulong local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion =
       (_func___cdecl_uchar_ulong_ptr_ulong_ptr_ulong_ptr__UNICODE_STRING_ptr *)
       MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage =
       (_func___cdecl_long_ulong64_ulong__GUID_ptr_ushort *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation =
       (_func___cdecl_long__TRACE_INFORMATION_CLASS_void_ptr_ulong_ulong_ptr_void_ptr *)
       MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = WppTraceWinXP;
  if (pfnWppGetVersion !=
      (_func___cdecl_uchar_ulong_ptr_ulong_ptr_ulong_ptr__UNICODE_STRING_ptr *)0x0) {
    (*pfnWppGetVersion)(local_res8,(ulong *)0x0,(ulong *)0x0,(_UNICODE_STRING *)0x0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider =
         (_func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
          *)MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider !=
        (_func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
         *)0x0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = (_func___cdecl_long_ulong64 *)MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = WppTraceServer08;
    }
  }
  return;
}



===== WppTraceCallback @ 1400106f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WppTraceCallback(uchar param_1,void *param_2,ulong param_3,void *param_4,void *param_5,
                ulong *param_6)

{
  int *piVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  ulong *puVar5;
  long lVar6;
  void *pvVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar5 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == '\x05') ||
       ((((param_1 != '\0' && (param_1 != '\x01')) && (param_1 != '\x02')) &&
        ((param_1 != '\x03' && (param_1 == '\x04')))))) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != (void *)0x0) {
        if (param_3 < 0x30) {
          return -0x3ffffff3;
        }
        do {
          piVar1 = *(int **)((longlong)param_5 + 8);
          if (((*piVar1 == *(int *)((longlong)param_4 + 0x18)) &&
              (piVar1[1] == *(int *)((longlong)param_4 + 0x1c))) &&
             ((piVar1[2] == *(int *)((longlong)param_4 + 0x20) &&
              (piVar1[3] == *(int *)((longlong)param_4 + 0x24))))) break;
          param_5 = *(void **)((longlong)param_5 + 0x10);
        } while (param_5 != (void *)0x0);
        if (param_5 != (void *)0x0) {
          if (param_1 == '\x05') {
            *(undefined4 *)((longlong)param_5 + 0x2c) = 0;
            *(undefined8 *)((longlong)param_5 + 0x18) = 0;
            *(undefined1 *)((longlong)param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != WppTraceWinXP;
          uVar2 = *(undefined8 *)((longlong)param_4 + 8);
          *(undefined8 *)((longlong)param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)((longlong)param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)((longlong)param_5 + 0x29) = uStack_36;
            return 0;
          }
          lVar6 = (*pfnWppQueryTraceInformation)
                            (TraceEnableLevelClass,local_res8,4,(ulong *)&param_6,param_4);
          if (lVar6 == 0) {
            *(undefined1 *)((longlong)param_5 + 0x29) = (undefined1)local_res8[0];
          }
          lVar6 = (*pfnWppQueryTraceInformation)
                            (TraceEnableFlagsClass,(void *)((longlong)param_5 + 0x2c),4,
                             (ulong *)&param_6,param_4);
          return lVar6;
        }
      }
      return -0x3ffffd6b;
    }
  }
  else {
    if (param_1 == '\x06') {
      return 0;
    }
    if (param_1 == '\a') {
      return 0;
    }
    if (param_1 == '\b') {
      uVar10 = 0;
      puVar3 = *(ushort **)((longlong)param_5 + 0x20);
      pvVar7 = param_5;
      do {
        pvVar7 = *(void **)((longlong)pvVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (pvVar7 != (void *)0x0);
      if (0x3f < uVar10) {
        return -0x3ffffff3;
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
          return -0x3fffffdd;
        }
        *(uint *)param_4 = uVar12;
        *param_6 = 4;
        return -0x3fffffdd;
      }
      memset();
      *(uint *)param_4 = uVar12;
      *(uint *)((longlong)param_4 + 8) = uVar11;
      *(uint *)((longlong)param_4 + 0x10) = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memcpy();
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = (undefined4 *)((longlong)param_4 + 0x28);
        do {
          uVar2 = **(undefined8 **)((longlong)param_5 + 8);
          uVar4 = (*(undefined8 **)((longlong)param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)((longlong)param_5 + 0x29) = 0;
          *(undefined4 *)((longlong)param_5 + 0x2c) = 0;
          param_5 = *(void **)((longlong)param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar5 = uVar12;
      return 0;
    }
  }
  return -0x3ffffff0;
}



===== AuxKlibInitialize @ 140010978 =====

long __cdecl AuxKlibInitialize(void)

{
  long lVar1;
  uint local_res8 [8];
  
  lVar1 = 0;
  local_res8[0] = 0;
  if (AuxpInitState == 0) {
    PsGetVersion(local_res8,0,0,0);
    if (local_res8[0] < 5) {
      lVar1 = -0x3fffff45;
    }
    else {
      AuxpKlibFns.QueryModuleInformationPtr =
           (_func___cdecl_long_ulong_ptr_ulong_void_ptr *)
           MmGetSystemRoutineAddress(&QueryModuleInfoName);
      LOCK();
      AuxpInitState = 1;
      UNLOCK();
    }
  }
  return lVar1;
}



===== WdfVersionBind @ 1400109f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WdfVersionBind(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2,_WDF_BIND_INFO *param_3,
              void ***param_4)

{
  uint uVar1;
  uchar uVar2;
  uchar uVar3;
  _WDF_BIND_INFO *p_Var4;
  bool bVar5;
  undefined8 *local_res20;
  ulong in_stack_ffffffffffffff70;
  _CLIENT_MODULE **pp_Var6;
  ushort uVar7;
  _LIBRARY_MODULE *local_68;
  _CLIENT_MODULE *local_60;
  _UNICODE_STRING local_58;
  undefined8 local_48;
  _UNICODE_STRING *local_40;
  _DRIVER_OBJECT *p_Stack_38;
  
                    /* 0x109f0  7  WdfVersionBind */
  local_48 = 0x18;
  local_res20 = (undefined8 *)0x0;
  local_68 = (_LIBRARY_MODULE *)0x0;
  local_40 = (_UNICODE_STRING *)0x0;
  p_Stack_38 = (_DRIVER_OBJECT *)0x0;
  local_58.Length = 0;
  local_58.MaximumLength = 0;
  local_58._4_4_ = 0;
  local_58.Buffer = (wchar_t *)0x0;
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 5)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
     ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
    uVar3 = '\0';
  }
  else {
    uVar3 = '\x01';
  }
  p_Var4 = (_WDF_BIND_INFO *)param_4;
  if ((uVar2 != '\0') || (uVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,uVar3,param_4,'\x05',
               in_stack_ffffffffffffff70,0x38,WPP_f35a5499df3a35f353983bcad3180794_Traceguids);
  }
  GetNameFromPath(param_2,&local_58);
  if (local_58.Length != 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar2 = '\0';
    }
    else {
      uVar2 = '\x01';
    }
    if ((uVar2 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_Z
                ((WPP_GLOBAL_Control->Control).Logger,uVar2,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 p_Var4,'\x04',in_stack_ffffffffffffff70,0x39,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,&local_58);
    }
  }
  local_60 = (_CLIENT_MODULE *)0x0;
  if (((param_4 == (void ***)0x0) || (param_3 == (_WDF_BIND_INFO *)0x0)) ||
     (param_3->FuncTable == (_func___cdecl_void **)0x0)) {
    return -0x3ffffff3;
  }
  *param_4 = (void **)0x0;
  uVar1 = ReferenceVersion(param_3,&local_68);
  if (-1 < (int)uVar1) {
    pp_Var6 = &local_60;
    p_Var4 = param_3;
    uVar1 = LibraryLinkInClient(param_3->Module,param_1,param_2,param_3,local_res20,pp_Var6);
    in_stack_ffffffffffffff70 = (ulong)pp_Var6;
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      bVar5 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((uVar2 != '\0') || (bVar5)) {
        uVar7 = 0x3a;
LAB_140010d26:
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar2,bVar5,p_Var4,'\x04',
                   in_stack_ffffffffffffff70,uVar7,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar1);
      }
    }
    else {
      local_res20 = &local_48;
      local_40 = param_2;
      p_Stack_38 = param_1;
      uVar1 = (*local_68->LibraryInfo->LibraryRegisterClient)(param_3,param_4,&local_res20);
      if (-1 < (int)uVar1) {
        local_60->Globals = *param_4;
        local_60->Context = local_res20;
        goto LAB_140010b65;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar2 = '\0';
      }
      else {
        uVar2 = '\x01';
      }
      bVar5 = WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED;
      if ((uVar2 != '\0') || (bVar5)) {
        uVar7 = 0x3b;
        goto LAB_140010d26;
      }
    }
  }
  if (local_68 != (_LIBRARY_MODULE *)0x0) {
    WdfVersionUnbind(param_2,param_3,*param_4);
  }
LAB_140010b65:
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((uVar2 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               p_Var4,'\x04',in_stack_ffffffffffffff70,0x3c,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
  }
  return uVar1;
}



===== AuxKlibQueryModuleInformation @ 140010d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl AuxKlibQueryModuleInformation(ulong *param_1,ulong param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined1 auStack_188 [32];
  undefined4 local_168 [2];
  uint *local_160;
  uint local_158 [76];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  uVar11 = 0;
  local_168[0] = 0;
  local_158[1] = 0;
  memset();
  if (AuxpInitState == 1) {
    if (AuxpKlibFns.QueryModuleInformationPtr == (_func___cdecl_long_ulong_ptr_ulong_void_ptr *)0x0)
    {
      uVar5 = -(uint)(((ulonglong)param_3 & 7) != 0) & 0xc00000f1;
      if (((ulonglong)param_3 & 7) == 0) {
        puVar7 = local_158;
        uVar12 = 0x130;
        while (uVar5 = ZwQuerySystemInformation(0xb,puVar7,uVar12,local_168), (int)uVar5 < 0) {
          if (uVar5 != 0xc0000004) goto LAB_140010e62;
          if (puVar7 != local_158) {
            ExFreePoolWithTag(puVar7,0);
          }
          puVar7 = (uint *)ExAllocatePoolWithQuotaTag(0x409,local_168[0],0x4b787541);
          if (puVar7 == (uint *)0x0) {
            return -0x3fffff66;
          }
          local_160 = puVar7;
          uVar12 = local_168[0];
        }
        uVar1 = *puVar7;
        if ((ulonglong)uVar1 * 0x110 < 0x100000000) {
          if (param_3 != (void *)0x0) {
            if (*param_1 < uVar1 * 0x110) {
              uVar5 = 0xc0000023;
            }
            else if (uVar1 != 0) {
              do {
                puVar9 = (undefined8 *)(uVar11 * 0x110 + (longlong)param_3);
                *puVar9 = *(undefined8 *)(puVar7 + uVar11 * 0x4a + 6);
                *(uint *)(puVar9 + 1) = puVar7[uVar11 * 0x4a + 8];
                *(undefined2 *)((longlong)puVar9 + 0xc) =
                     *(undefined2 *)((longlong)puVar7 + uVar11 * 0x128 + 0x2e);
                puVar8 = puVar7 + uVar11 * 0x4a + 0xc;
                lVar6 = 2;
                puVar9 = (undefined8 *)((longlong)puVar9 + 0xe);
                do {
                  uVar4 = *(undefined8 *)(puVar8 + 2);
                  *puVar9 = *(undefined8 *)puVar8;
                  puVar9[1] = uVar4;
                  uVar4 = *(undefined8 *)(puVar8 + 6);
                  puVar9[2] = *(undefined8 *)(puVar8 + 4);
                  puVar9[3] = uVar4;
                  uVar4 = *(undefined8 *)(puVar8 + 10);
                  puVar9[4] = *(undefined8 *)(puVar8 + 8);
                  puVar9[5] = uVar4;
                  uVar4 = *(undefined8 *)(puVar8 + 0xe);
                  puVar9[6] = *(undefined8 *)(puVar8 + 0xc);
                  puVar9[7] = uVar4;
                  uVar4 = *(undefined8 *)(puVar8 + 0x12);
                  puVar9[8] = *(undefined8 *)(puVar8 + 0x10);
                  puVar9[9] = uVar4;
                  uVar4 = *(undefined8 *)(puVar8 + 0x16);
                  puVar9[10] = *(undefined8 *)(puVar8 + 0x14);
                  puVar9[0xb] = uVar4;
                  uVar10 = puVar8[0x19];
                  uVar2 = puVar8[0x1a];
                  uVar3 = puVar8[0x1b];
                  *(uint *)(puVar9 + 0xc) = puVar8[0x18];
                  *(uint *)((longlong)puVar9 + 100) = uVar10;
                  *(uint *)(puVar9 + 0xd) = uVar2;
                  *(uint *)((longlong)puVar9 + 0x6c) = uVar3;
                  uVar4 = *(undefined8 *)(puVar8 + 0x1e);
                  puVar9[0xe] = *(undefined8 *)(puVar8 + 0x1c);
                  puVar9[0xf] = uVar4;
                  puVar8 = puVar8 + 0x20;
                  lVar6 = lVar6 + -1;
                  puVar9 = puVar9 + 0x10;
                } while (lVar6 != 0);
                uVar10 = (int)uVar11 + 1;
                uVar11 = (ulonglong)uVar10;
              } while (uVar10 < *puVar7);
            }
          }
          *param_1 = uVar1 * 0x110;
        }
        else {
          uVar5 = 0xc0000095;
        }
LAB_140010e62:
        if (puVar7 != local_158) {
          ExFreePoolWithTag(puVar7,0);
        }
      }
    }
    else {
      uVar5 = (*AuxpKlibFns.QueryModuleInformationPtr)(param_1,0x110,param_3);
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  return uVar5;
}



===== WdfVersionUnbind @ 140010fc0 =====

long __cdecl WdfVersionUnbind(_UNICODE_STRING *param_1,_WDF_BIND_INFO *param_2,void **param_3)

{
  uint uVar1;
  uchar uVar2;
  void *in_R9;
  ulong in_stack_ffffffffffffffd0;
  
                    /* 0x10fc0  9  WdfVersionUnbind */
  uVar1 = DereferenceVersion(param_2,param_3);
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 4)) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\x01';
  }
  if ((uVar2 != '\0') ||
     (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_D
              ((WPP_GLOBAL_Control->Control).Logger,uVar2,
               WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
               in_R9,'\x04',in_stack_ffffffffffffffd0,0x3d,
               WPP_f35a5499df3a35f353983bcad3180794_Traceguids,uVar1);
  }
  return uVar1;
}



===== WdfRegisterClassLibrary @ 140011050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WdfRegisterClassLibrary
          (_WDF_CLASS_LIBRARY_INFO *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3)

{
  _func___cdecl_long *p_Var1;
  bool bVar2;
  bool bVar3;
  _LIBRARY_MODULE *p_Var4;
  uint uVar5;
  _CLASS_MODULE *p_Var6;
  _DRIVER_OBJECT *p_Var7;
  _CLASS_MODULE *p_Var8;
  uchar uVar9;
  uchar uVar10;
  _CLASS_MODULE **in_R9;
  _LIBRARY_MODULE *local_res20;
  ulong in_stack_ffffffffffffffa0;
  _CLASS_MODULE *local_38 [2];
  
                    /* 0x11050  5  WdfRegisterClassLibrary */
  local_res20 = (_LIBRARY_MODULE *)0x0;
  bVar3 = false;
  bVar2 = false;
  FxLdrAcquireLoadedModuleLock();
  p_Var6 = FindClassByServiceNameLocked(param_2,&local_res20);
  local_38[0] = p_Var6;
  p_Var7 = GetDriverObjectFromDeviceName(param_3);
  if (p_Var6 == (_CLASS_MODULE *)0x0) {
    uVar5 = FindModuleByClientServiceNameLocked(param_2,p_Var7,&local_res20);
    p_Var4 = local_res20;
    if ((int)uVar5 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar9 = '\0';
      }
      else {
        uVar9 = '\x01';
      }
      if ((uVar9 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_ZD
                  ((WPP_GLOBAL_Control->Control).Logger,uVar9,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                   in_stack_ffffffffffffffa0,0x4d,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   param_2,uVar5);
      }
      p_Var6 = (_CLASS_MODULE *)0x0;
    }
    else {
      in_R9 = local_38;
      uVar5 = ClassCreate(param_1,local_res20,param_2,in_R9);
      p_Var6 = local_38[0];
      if (-1 < (int)uVar5) {
        local_38[0]->IsBootDriver = '\x01';
        uVar5 = GetClassNameAndBase(local_38[0],param_2,p_Var7);
        if ((int)uVar5 < 0) {
          ClassCleanupAndFree(p_Var6);
          p_Var6 = (_CLASS_MODULE *)0x0;
          bVar2 = bVar3;
          goto LAB_1400111d9;
        }
        LibraryAddToClassListLocked(p_Var4,p_Var6);
        bVar3 = true;
      }
LAB_1400111be:
      bVar2 = bVar3;
      if (p_Var6 != (_CLASS_MODULE *)0x0) {
        ClassAddReferenceLocked(p_Var6);
      }
    }
  }
  else {
    p_Var8 = p_Var6;
    ClassLibraryCopyInfo(p_Var6,param_1);
    p_Var6->IsBootDriver = '\0';
    uVar5 = GetClassNameAndBase(p_Var8,param_2,p_Var7);
    if (-1 < (int)uVar5) goto LAB_1400111be;
    p_Var6 = (_CLASS_MODULE *)0x0;
    bVar2 = bVar3;
  }
LAB_1400111d9:
  FxLdrReleaseLoadedModuleLock();
  if (p_Var6 == (_CLASS_MODULE *)0x0) {
    return uVar5;
  }
  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
      (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
     ((WPP_GLOBAL_Control->Control).Level < 5)) {
    uVar9 = '\0';
  }
  else {
    uVar9 = '\x01';
  }
  if ((WPP_RECORDER_INITIALIZED == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED) ||
     ((WPP_GLOBAL_Control->Control).AutoLogVerboseEnabled == 0)) {
    uVar10 = '\0';
  }
  else {
    uVar10 = '\x01';
  }
  if ((uVar9 != '\0') || (uVar10 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              ((WPP_GLOBAL_Control->Control).Logger,uVar9,uVar10,in_R9,'\x05',
               in_stack_ffffffffffffffa0,0x4e,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,p_Var6
              );
  }
  if ((param_3 == (_UNICODE_STRING *)0x0) ||
     (uVar5 = RtlDuplicateUnicodeString(0,param_3,&p_Var6->ControlDeviceName), -1 < (int)uVar5)) {
    p_Var1 = p_Var6->ClassLibraryInfo->ClassLibraryInitialize;
    if ((p_Var1 != (_func___cdecl_long *)0x0) && (uVar5 = (*p_Var1)(), (int)uVar5 < 0)) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 4)) {
        uVar9 = '\0';
      }
      else {
        uVar9 = '\x01';
      }
      if ((uVar9 != '\0') ||
         (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_D
                  ((WPP_GLOBAL_Control->Control).Logger,uVar9,
                   WPP_RECORDER_INITIALIZED !=
                   (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,in_R9,'\x04',
                   in_stack_ffffffffffffffa0,0x50,WPP_f35a5499df3a35f353983bcad3180794_Traceguids,
                   uVar5);
      }
      goto LAB_14001134f;
    }
    if ((int)uVar5 < 0) goto LAB_14001134f;
    if (!bVar2) goto LAB_1400113cc;
  }
  else {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar9 = '\0';
    }
    else {
      uVar9 = '\x01';
    }
    if ((uVar9 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,uVar9,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffa0,0x4f,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_3,uVar5);
    }
LAB_14001134f:
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 4)) {
      uVar9 = '\0';
    }
    else {
      uVar9 = '\x01';
    }
    if ((uVar9 != '\0') ||
       (WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_ZD
                ((WPP_GLOBAL_Control->Control).Logger,uVar9,
                 WPP_RECORDER_INITIALIZED != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_RECORDER_INITIALIZED,
                 in_R9,'\x04',in_stack_ffffffffffffffa0,0x51,
                 WPP_f35a5499df3a35f353983bcad3180794_Traceguids,param_3,uVar5);
    }
    p_Var6->ClassLibraryInfo = (_WDF_CLASS_LIBRARY_INFO *)0x0;
    if (!bVar2) goto LAB_1400113cc;
    ClassReleaseReference(p_Var6);
  }
  ClassLoaderUnlock(p_Var6);
LAB_1400113cc:
  ClassReleaseReference(p_Var6);
  return uVar5;
}



===== AuxKlibQueryModuleInformation$filt$0 @ 140011400 =====

bool AuxKlibQueryModuleInformation_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff66;
}



===== GsDriverEntry @ 140013010 =====

long __cdecl GsDriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  
  __security_init_cookie();
  lVar1 = DriverEntry(param_1,param_2);
  return lVar1;
}



===== __security_init_cookie @ 140013044 =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x14000d080) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


