
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_140013048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140013048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140013060,&local_18,0,0,param_5,param_6);
  return;
}



===== operator_delete @ 140001120 =====

/* void __cdecl operator delete(void * __ptr64,struct std::nothrow_t const & __ptr64) */

void __cdecl operator_delete(void *param_1,nothrow_t *param_2)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0x646d4370);
  }
  return;
}



===== _HeadUnlinkNode @ 140001148 =====

/* public: void __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_HeadUnlinkNode(struct utl::_TreeNode<struct
   utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<void * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64) __ptr64 */

void __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_HeadUnlinkNode(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                  *this,_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                        *param_1)

{
  ulonglong *puVar1;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var2;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var3;
  ulonglong uVar4;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var5;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *this_00;
  byte bVar6;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var7;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var8;
  byte bVar9;
  char cVar10;
  bool bVar11;
  bool bVar12;
  
  p_Var7 = *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             **)(param_1 + 0x10);
  this_00 = (_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             *)(*(ulonglong *)param_1 & 0xfffffffffffffffe);
  bVar11 = p_Var7 != (_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                      *)&_TreeSentinel;
  bVar12 = false;
  cVar10 = (*(void ***)(param_1 + 8) != &_TreeSentinel) + bVar11;
  if (cVar10 == '\0') {
    if (this == (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)this_00) {
      *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)this = this;
      *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 8) = this;
      *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 0x10) = this;
      return;
    }
    if (*(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
          **)(this + 8) == param_1) {
      p_Var3 = _Traverse((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                          *)param_1,false);
      *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 8) = p_Var3;
    }
    else if (*(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(this + 0x10) == param_1) {
      p_Var3 = _Traverse((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                          *)param_1,true);
      *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 0x10) = p_Var3;
    }
    bVar12 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(this_00 + 0x10) == param_1;
    *(void ***)(this_00 + (ulonglong)bVar12 * 8 + 8) = &_TreeSentinel;
    if ((~(byte)*param_1 & 1) != 0) {
      return;
    }
  }
  else {
    if (cVar10 == '\x01') {
      uVar4 = (ulonglong)bVar11;
      p_Var7 = *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 **)(param_1 + uVar4 * 8 + 8);
      if (*(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
            **)(this + uVar4 * 8 + 8) == param_1) {
        p_Var3 = _Traverse((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                            *)param_1,bVar11);
        *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
          **)(this + uVar4 * 8 + 8) = p_Var3;
      }
      _ReplaceChild((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                     *)this_00,param_1,p_Var7);
      *(undefined8 *)p_Var7 = *(undefined8 *)param_1;
      return;
    }
    p_Var2 = *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(p_Var7 + 8);
    if (*(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
          **)(p_Var7 + 8) ==
        (_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
         *)&_TreeSentinel) {
      if ((((byte)*p_Var7 & 1) == 0) || (cVar10 = '\x01', (**(byte **)(p_Var7 + 0x10) & 1) == 0)) {
        cVar10 = '\0';
      }
      *(ulonglong *)p_Var7 = *(ulonglong *)param_1;
      puVar1 = *(ulonglong **)(param_1 + 8);
      *(ulonglong **)(p_Var7 + 8) = puVar1;
      *puVar1 = (ulonglong)((uint)*puVar1 & 1) | (ulonglong)p_Var7;
      **(ulonglong **)(p_Var7 + 0x10) = (ulonglong)p_Var7 | 1;
      _ReplaceChild((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                     *)this_00,param_1,p_Var7);
      if (cVar10 == '\0') {
        return;
      }
      bVar12 = true;
      this_00 = p_Var7;
    }
    else {
      do {
        p_Var8 = p_Var7;
        p_Var7 = p_Var2;
        p_Var2 = *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                   **)(p_Var7 + 8);
      } while (*(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 **)(p_Var7 + 8) !=
               (_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                *)&_TreeSentinel);
      if ((((byte)*p_Var7 & 1) == 0) || (cVar10 = '\x01', (**(byte **)(p_Var7 + 0x10) & 1) == 0)) {
        cVar10 = '\0';
      }
      puVar1 = *(ulonglong **)(p_Var7 + 0x10);
      *(ulonglong **)(p_Var8 + 8) = puVar1;
      *puVar1 = (ulonglong)p_Var8 | 1;
      *(undefined8 *)p_Var7 = *(undefined8 *)param_1;
      puVar1 = *(ulonglong **)(param_1 + 8);
      *(ulonglong **)(p_Var7 + 8) = puVar1;
      *puVar1 = (ulonglong)((uint)*puVar1 & 1) | (ulonglong)p_Var7;
      puVar1 = *(ulonglong **)(param_1 + 0x10);
      *(ulonglong **)(p_Var7 + 0x10) = puVar1;
      *puVar1 = (ulonglong)((uint)*puVar1 & 1) | (ulonglong)p_Var7;
      _ReplaceChild((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                     *)this_00,param_1,p_Var7);
      this_00 = p_Var8;
      if (cVar10 == '\0') {
        return;
      }
    }
  }
  while( true ) {
    uVar4 = (ulonglong)bVar12;
    if ((~**(byte **)(this_00 + (uVar4 ^ 1) * 8 + 8) & 1) != 0) {
      _NodeRotate((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                   *)this_00,bVar12,false,true);
    }
    p_Var5 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(this_00 + (uVar4 ^ 1) * 8 + 8);
    if ((~**(byte **)(p_Var5 + (uVar4 ^ 1) * 8 + 8) & 1) != 0) break;
    if ((~**(byte **)(p_Var5 + (ulonglong)bVar12 * 8 + 8) & 1) != 0) {
      bVar6 = 1;
      _NodeRotateNonRoot(p_Var5,(bool)(bVar12 ^ 1),true,true);
      bVar9 = (byte)*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                      *)this_00 & bVar6;
      goto LAB_1400013d5;
    }
    *(ulonglong *)p_Var5 = *(ulonglong *)p_Var5 & 0xfffffffffffffffe;
    uVar4 = *(ulonglong *)this_00;
    if ((~(byte)uVar4 & 1) != 0) {
      *(ulonglong *)this_00 = uVar4 | 1;
      return;
    }
    p_Var5 = (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              *)(uVar4 & 0xfffffffffffffffe);
    if (this == p_Var5) {
      return;
    }
    bVar12 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(p_Var5 + 0x10) ==
             (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              *)this_00;
    this_00 = (_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               *)p_Var5;
  }
  bVar6 = true;
  **(ulonglong **)(p_Var5 + ((ulonglong)bVar12 ^ 1) * 8 + 8) =
       **(ulonglong **)(p_Var5 + ((ulonglong)bVar12 ^ 1) * 8 + 8) | 1;
  bVar9 = (byte)*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                  *)this_00 & 1;
LAB_1400013d5:
  _NodeRotate((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               *)this_00,bVar12,(bool)bVar6,(bool)bVar9);
  return;
}



===== UnregisterReadQueue @ 140001404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UnregisterReadQueue(struct
   WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UnregisterReadQueue
          (AvrcpTransportDevice *this,WDFFILEOBJECT__ *param_1)

{
  AvrcpTransportDevice *pAVar1;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *this_00;
  undefined8 uVar2;
  undefined1 uVar3;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var4;
  AvrcpTransportDeviceReadQueue *this_01;
  longlong lVar5;
  longlong lVar6;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *this_02;
  longlong local_38 [2];
  AvrcpTransportDevice *local_28;
  undefined1 uStack_20;
  undefined4 uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  
  pAVar1 = this + 0x8a0;
  lVar6 = 0;
  this_00 = (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             *)(this + 0x8a8);
  local_38[0] = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar2 = _uStack_20;
  _uStack_20 = CONCAT41(uStack_1f,uVar3);
  uStack_1b = SUB82(uVar2,5);
  uStack_19 = SUB81(uVar2,7);
  local_28 = pAVar1;
  if (*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 0x8b8) != this_00) {
    p_Var4 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)this_00;
    this_02 = this_00;
    do {
      if (*(WDFFILEOBJECT__ **)(p_Var4 + 0x18) < param_1) {
        lVar5 = 0x10;
      }
      else {
        lVar5 = 8;
        this_02 = p_Var4;
      }
      p_Var4 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 **)(p_Var4 + lVar5);
    } while (p_Var4 != (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                        *)&utl::_TreeSentinel);
    if ((this_02 != this_00) && (*(WDFFILEOBJECT__ **)(this_02 + 0x18) <= param_1)) {
      if ((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
           *)local_38 != this_02 + 0x20) {
        wil::details::
        unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        ::reset(local_38);
        *(longlong *)(this_02 + 0x20) = 0;
        lVar6 = local_38[0];
      }
      utl::
      _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      ::_Traverse(this_02,true);
      p_Var4 = this_02;
      utl::
      _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      ::_HeadUnlinkNode(this_00,(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                                 *)this_02);
      *(longlong *)(this + 0x8c0) = *(longlong *)(this + 0x8c0) + -1;
      wil::details::
      unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                  *)(this_02 + 0x20));
      operator_delete(this_02,(nothrow_t *)p_Var4);
    }
  }
  if (pAVar1 != (AvrcpTransportDevice *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
  }
  this_01 = (AvrcpTransportDeviceReadQueue *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar6,
                       PTR__WDF_AvrcpTransportDeviceReadQueue_TYPE_INFO_14000f0a8);
  AvrcpTransportDeviceReadQueue::Purge(this_01);
  if (lVar6 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar6);
  }
  return;
}



===== Purge @ 140001570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::Purge(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::Purge
          (AvrcpTransportDeviceReadQueue *this)

{
  AvrcpTransportDeviceReadQueue *pAVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  AvrcpTransportDeviceReadQueue *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x47,
               in_stack_ffffffffffffffd0,(char)this);
  }
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(this + 0x18),0,0);
  pAVar1 = this + 0x20;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar2 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar3);
  uStack_b = SUB82(uVar2,5);
  uStack_9 = SUB81(uVar2,7);
  local_18 = pAVar1;
  while( true ) {
    local_res8 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals);
    if (local_res8 == 0) break;
    (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(this + 0x28));
    wil::details::
    unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                *)&local_res8);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x48,
               in_stack_ffffffffffffffd0,(char)this);
  }
  if (pAVar1 != (AvrcpTransportDeviceReadQueue *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== OnConnectRequested @ 140001740 =====

/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnConnectRequested(void
   * __ptr64,int) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnConnectRequested
          (void *param_1,int param_2)

{
  if (param_2 == 0) {
    StartDisconnect(param_1);
  }
  else {
    StartConnect(param_1);
  }
  return 0;
}



===== ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_> @ 140001764 =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<unsigned
   __int64 * __ptr64,void __cdecl(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),&public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct wil::details::kspin_lock_saved_irql,unsigned __int64 *
   __ptr64,0,std::nullptr_t> >::~unique_storage<struct wil::details::resource_policy<unsigned
   __int64 * __ptr64,void __cdecl(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),&public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct wil::details::kspin_lock_saved_irql,unsigned __int64 *
   __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
           *this)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (*(longlong *)this != 0) {
    local_18 = *(undefined8 *)this;
    uStack_10 = *(undefined8 *)(this + 8);
    kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== StartDisconnect @ 140001790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::StartDisconnect(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::StartDisconnect
          (AvrcpTransportDeviceService *this)

{
  AvrcpTransportDeviceService *pAVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  char cVar6;
  char cVar7;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  AvrcpTransportDeviceService *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x43,
               in_stack_ffffffffffffffd0,(char)this);
  }
  pAVar1 = this + 0x38;
  uVar5 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar4 = _uStack_10;
  iVar2 = *(int *)(this + 0x48);
  _uStack_10 = CONCAT41(uStack_f,uVar5);
  uStack_b = SUB82(uVar4,5);
  uStack_9 = SUB81(uVar4,7);
  local_18 = pAVar1;
  if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  if (iVar2 == 0) {
    lVar3 = *(longlong *)(this + 0x108);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
    if (*(longlong *)(this + 0x110) != 0) {
      BtaMpmUpdateConnectionStatus();
    }
    if (lVar3 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    }
  }
  else {
    DisconnectChannel(this,(void *)0x0);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x44,
               in_stack_ffffffffffffffd0,(char)this);
  }
  return;
}



===== GetReadiness @ 140001970 =====

/* public: bool __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::GetReadiness(void)const
   __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::GetReadiness
          (AutoConnectionAdvisor *this)

{
  undefined8 uVar1;
  undefined1 uVar2;
  bool bVar3;
  AutoConnectionAdvisor *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  uVar1 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar2);
  uStack_b = SUB82(uVar1,5);
  uStack_9 = SUB81(uVar1,7);
  if ((this[8] == (AutoConnectionAdvisor)0x0) || (this[9] == (AutoConnectionAdvisor)0x0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  local_18 = this;
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  return bVar3;
}



===== ProcessChannelEvent @ 1400019e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::ProcessChannelEvent(struct
   BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT const & __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::ProcessChannelEvent
          (AvrcpTransportDeviceReadQueue *this,BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *param_1)

{
  AvrcpTransportDeviceReadQueue *pAVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  undefined8 local_res8;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar8;
  AvrcpTransportDeviceReadQueue *local_48;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  undefined2 uStack_3b;
  undefined1 uStack_39;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  uVar8 = SUB81(this,0);
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x4b,
               in_stack_ffffffffffffffa0,uVar8);
  }
  pAVar1 = this + 0x20;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar2 = _uStack_40;
  _uStack_40 = CONCAT41(uStack_3f,uVar3);
  uStack_3b = SUB82(uVar2,5);
  uStack_39 = SUB81(uVar2,7);
  local_48 = pAVar1;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals);
  if (iVar4 < 0) {
    if (iVar4 == -0x7fffffe6) {
      while( true ) {
        uVar5 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals);
        if (uVar5 < *(ushort *)(this + 0x10)) break;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_dq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,0x4c,
                     in_stack_ffffffffffffffa0,(char)*(ushort *)(this + 0x10),uVar8);
        }
        local_res20 = (**(code **)(WdfFunctions_01015 + 0x98))
                                (WdfDriverGlobals,*(undefined8 *)(this + 0x28));
        (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(this + 0x28),0);
        wil::details::
        unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
        ::
        ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                  ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                    *)&local_res20);
      }
      local_res8 = 0;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x638))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x30),&local_res8);
      if (((-1 < iVar4) &&
          (iVar4 = (**(code **)(WdfFunctions_01015 + 0x628))
                             (WdfDriverGlobals,local_res8,0,param_1,0x11), -1 < iVar4)) &&
         (iVar4 = (**(code **)(WdfFunctions_01015 + 0x78))
                            (WdfDriverGlobals,*(undefined8 *)(this + 0x28),local_res8), -1 < iVar4))
      {
        local_res8 = 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_dq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffff90,0x4d,
                   in_stack_ffffffffffffffa0,(char)iVar4,uVar8);
      }
      wil::details::
      unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                  *)&local_res8);
    }
    else if (iVar4 == -0x3fdffdfd) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,0x4e,
                   in_stack_ffffffffffffffa0,uVar8);
      }
    }
  }
  else {
    local_res8 = 0;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,0,&local_res8);
    if (-1 < iVar4) {
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,local_res8,0,param_1,0x11);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))
              (WdfDriverGlobals,0,iVar4,((longlong)iVar4 >> 0x3f & 0xffffffffffffffefU) + 0x11);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x4f,
               in_stack_ffffffffffffffa0,uVar8);
  }
  if (pAVar1 != (AvrcpTransportDeviceReadQueue *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
  }
  return;
}



===== ControlBrbCompletionWorkItem @ 140001e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ControlBrbCompletionWorkItem(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
ControlBrbCompletionWorkItem(WDFWORKITEM__ *param_1)

{
  AvrcpTransportDeviceService *this;
  undefined8 *puVar1;
  _BRB *p_Var2;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_CONTROL_BRB_WORKITEM_CONTEXT_TYPE_INFO_14000f120);
  this = (AvrcpTransportDeviceService *)puVar1[1];
  local_50 = 0;
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_58 = 0x48;
  local_54 = 0xff;
  (**(code **)(WdfFunctions_01015 + 0x828))(WdfDriverGlobals,*puVar1,&local_58);
  p_Var2 = (_BRB *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,uStack_40,0);
  OnControlBrbCompleted(this,p_Var2,(long)local_50);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*puVar1);
  return;
}



===== ReportChannelStateEvent @ 140001f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ReportChannelStateEvent(unsigned
   short,unsigned short,bool) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ReportChannelStateEvent
          (AvrcpTransportDeviceService *this,ushort param_1,ushort param_2,bool param_3)

{
  AvrcpTransportDevice *this_00;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  ushort local_1c;
  ushort local_1a;
  undefined1 local_18;
  
  local_20 = 0;
  local_24 = (*(int *)(this + 0x18) == 1) + 1;
  local_28 = 1;
  local_1c = param_1;
  local_1a = param_2;
  local_18 = param_3;
  this_00 = (AvrcpTransportDevice *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*(undefined8 *)(this + 8),
                       PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  AvrcpTransportDevice::DistributeChannelEvent
            (this_00,(BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)&local_28);
  return;
}



===== OnControlBrbCompleted @ 140001fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnControlBrbCompleted(struct
   _BRB * __ptr64,long) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnControlBrbCompleted
          (AvrcpTransportDeviceService *this,_BRB *param_1,long param_2)

{
  AvrcpTransportDeviceService *pAVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  AvrcpTransportDevice *this_00;
  char cVar6;
  long lVar7;
  undefined8 uVar8;
  AvrcpTransportDeviceService AVar9;
  char cVar10;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar11;
  undefined8 local_48;
  longlong lStack_40;
  byte local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  uVar11 = SUB81(this,0);
  if ((cVar6 != '\0') || (cVar10 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar10,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x33,
               in_stack_ffffffffffffffa0,uVar11);
  }
  if ((ushort)(*(short *)(param_1 + 0x16) - 0x212U) < 2) {
    if (param_2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar6 = '\0';
      }
      else {
        cVar6 = '\x01';
      }
      if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_dq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffff90,0x36,
                   in_stack_ffffffffffffffa0,(char)param_2,uVar11);
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0x38);
      lVar3 = lStack_40;
      lStack_40._0_5_ = CONCAT41(lStack_40._1_4_,uVar5);
      lStack_40._5_2_ = SUB82(lVar3,5);
      lStack_40._7_1_ = SUB81(lVar3,7);
      *(undefined4 *)(this + 0x48) = 0;
      local_48 = this + 0x38;
      KeSetEvent(this + 0x50,0,0);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        uVar8 = 0x200;
      }
      else {
        uVar8 = 0x201;
      }
      if (((char)uVar8 != '\0') ||
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)uVar8,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffff90,0x34,
                   in_stack_ffffffffffffffa0,uVar11);
      }
      pAVar1 = this + 0x38;
      uVar5 = KeAcquireSpinLockRaiseToDpc(pAVar1);
      lVar3 = lStack_40;
      lVar7 = (long)uVar8;
      *(undefined4 *)(this + 0x48) = 1;
      lStack_40._0_5_ = CONCAT41(lStack_40._1_4_,uVar5);
      lStack_40._5_2_ = SUB82(lVar3,5);
      lStack_40._7_1_ = SUB81(lVar3,7);
      *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_1 + 0x70);
      uVar4 = *(undefined8 *)(param_1 + 0x180);
      *(undefined8 *)(this + 0x68) = *(undefined8 *)(param_1 + 0x178);
      *(undefined8 *)(this + 0x70) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 400);
      *(undefined8 *)(this + 0x78) = *(undefined8 *)(param_1 + 0x188);
      *(undefined8 *)(this + 0x80) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x1a0);
      *(undefined8 *)(this + 0x88) = *(undefined8 *)(param_1 + 0x198);
      *(undefined8 *)(this + 0x90) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x1b0);
      *(undefined8 *)(this + 0x98) = *(undefined8 *)(param_1 + 0x1a8);
      *(undefined8 *)(this + 0xa0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x1c0);
      *(undefined8 *)(this + 0xa8) = *(undefined8 *)(param_1 + 0x1b8);
      *(undefined8 *)(this + 0xb0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x128);
      *(undefined8 *)(this + 0xb8) = *(undefined8 *)(param_1 + 0x120);
      *(undefined8 *)(this + 0xc0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x138);
      *(undefined8 *)(this + 200) = *(undefined8 *)(param_1 + 0x130);
      *(undefined8 *)(this + 0xd0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x148);
      *(undefined8 *)(this + 0xd8) = *(undefined8 *)(param_1 + 0x140);
      *(undefined8 *)(this + 0xe0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x158);
      *(undefined8 *)(this + 0xe8) = *(undefined8 *)(param_1 + 0x150);
      *(undefined8 *)(this + 0xf0) = uVar4;
      uVar4 = *(undefined8 *)(param_1 + 0x168);
      *(undefined8 *)(this + 0xf8) = *(undefined8 *)(param_1 + 0x160);
      *(undefined8 *)(this + 0x100) = uVar4;
      local_48 = pAVar1;
      if ((*(int *)(this + 0x18) == 1) && (param_1[0xcc] == (_BRB)0x3)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 3)
            ))) {
          lVar7 = (int)((ulonglong)uVar8 >> 8) << 8;
        }
        else {
          lVar7 = (long)CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
        }
        if (((char)lVar7 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_AND_TRACE_SF_q
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar7,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffff90,0x35,
                     in_stack_ffffffffffffffa0,uVar11);
        }
      }
      wil::details::kernel_event_t<0>::set((kernel_event_t<0> *)(this + 0x50),lVar7);
    }
    if (this + 0x38 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    lVar3 = *(longlong *)(this + 0x108);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,lVar3,0);
    if (*(longlong *)(this + 0x110) != 0) {
      BtaMpmUpdateConnectionStatus
                (*(longlong *)(this + 0x110),(uint)~param_2 >> 0x1f,
                 *(short *)(param_1 + 0x16) == 0x212);
    }
    if (lVar3 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,lVar3);
    }
    local_38 = (byte)((uint)param_2 >> 0x1f) ^ 1;
    iVar2 = *(int *)(this + 0x18);
    lStack_40 = (ulonglong)
                CONCAT22(*(undefined2 *)(param_1 + 0x124),*(undefined2 *)(param_1 + 0x17c)) << 0x20;
  }
  else {
    if (*(short *)(param_1 + 0x16) != 0x104) goto LAB_1400021fd;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_dq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffff90,0x37,
                 in_stack_ffffffffffffffa0,(char)param_2,uVar11);
    }
    pAVar1 = this + 0x38;
    AVar9 = (AvrcpTransportDeviceService)0x0;
    uVar5 = KeAcquireSpinLockRaiseToDpc(pAVar1);
    lVar3 = lStack_40;
    lStack_40._0_5_ = CONCAT41(lStack_40._1_4_,uVar5);
    lStack_40._5_2_ = SUB82(lVar3,5);
    lStack_40._7_1_ = SUB81(lVar3,7);
    *(undefined4 *)(this + 0x48) = 0;
    *(undefined8 *)(this + 0x40) = 0;
    if (-1 < param_2) {
      AVar9 = this[0x4c];
    }
    this[0x4c] = (AvrcpTransportDeviceService)0x0;
    local_48 = pAVar1;
    KeSetEvent(this + 0x50,0,0);
    if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    lVar3 = *(longlong *)(this + 0x108);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,lVar3,0);
    if (*(longlong *)(this + 0x110) != 0) {
      BtaMpmUpdateConnectionStatus(*(longlong *)(this + 0x110),0,AVar9);
    }
    if (lVar3 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,lVar3);
    }
    iVar2 = *(int *)(this + 0x18);
    lStack_40 = 0;
    local_38 = 0;
  }
  local_48 = (AvrcpTransportDeviceService *)CONCAT44((iVar2 == 1) + 1,1);
  this_00 = (AvrcpTransportDevice *)
            (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  AvrcpTransportDevice::DistributeChannelEvent
            (this_00,(BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)&local_48);
LAB_1400021fd:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar10 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar10,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x38,
               in_stack_ffffffffffffffa0,uVar11);
  }
  return;
}



===== DistributeChannelEvent @ 140002660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::DistributeChannelEvent(struct
   BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT const & __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::DistributeChannelEvent
          (AvrcpTransportDevice *this,BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *param_1)

{
  BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *pBVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *this_00;
  AvrcpTransportDeviceReadQueue *this_01;
  uint7 uVar8;
  BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *pBVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar9;
  char cVar10;
  undefined8 *local_res8;
  BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *local_res10;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar11;
  AvrcpTransportDevice *local_48;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  undefined2 uStack_3b;
  undefined1 uStack_39;
  
  uVar8 = (uint7)((ulonglong)param_1 >> 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    pBVar5 = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)((ulonglong)uVar8 << 8);
  }
  else {
    pBVar5 = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)CONCAT71(uVar8,1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  uVar11 = SUB81(this,0);
  local_res10 = param_1;
  if (((char)pBVar5 != '\0') || (cVar10 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)pBVar5,cVar10,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x54,
               in_stack_ffffffffffffffa0,uVar11);
  }
  utl::
  forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
  ::
  forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
            ((forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
              *)&local_res8);
  uVar3 = KeAcquireSpinLockRaiseToDpc(this + 0x8a0);
  uVar2 = _uStack_40;
  this_00 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              **)(this + 0x8b8);
  _uStack_40 = CONCAT41(uStack_3f,uVar3);
  uStack_3b = SUB82(uVar2,5);
  uStack_39 = SUB81(uVar2,7);
  puVar9 = local_res8;
  local_48 = this + 0x8a0;
  for (; pBVar1 = local_res10,
      this_00 !=
      (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
       *)(this + 0x8a8);
      this_00 = (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)utl::
                   _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                   ::_Traverse(this_00,true)) {
    lVar7 = *(longlong *)(this_00 + 0x20);
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,lVar7,0,0x5a7,
               "onecore\\drivers\\bluetooth\\legacy\\avrcptransport\\lib\\avrcptransportdevice.cpp")
    ;
    lVar6 = 0;
    puVar4 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar4 != (undefined8 *)0x0) {
      puVar4[1] = lVar7;
      puVar4[2] = 0;
      lVar7 = 0;
      *puVar4 = puVar9;
      puVar9 = puVar4;
    }
    if (lVar7 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar7,0,0x1977,
                 "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
      lVar6 = lVar7;
    }
    if (puVar4 == (undefined8 *)0x0) {
      uVar8 = (uint7)((ulonglong)lVar6 >> 8);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        lVar6 = (ulonglong)uVar8 << 8;
      }
      else {
        lVar6 = CONCAT71(uVar8,1);
      }
      if (((char)lVar6 != '\0') ||
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffff90,0x55,
                   in_stack_ffffffffffffffa0,uVar11);
      }
    }
    pBVar5 = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
  }
  if (this != (AvrcpTransportDevice *)0xfffffffffffff760) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
  }
  for (puVar4 = puVar9; puVar4 != (undefined8 *)0xffffffffffffffff; puVar4 = (undefined8 *)*puVar4)
  {
    pBVar5 = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_EVENT *)0x0;
    if (puVar4[1] != 0) {
      this_01 = (AvrcpTransportDeviceReadQueue *)
                (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      pBVar5 = pBVar1;
      AvrcpTransportDeviceReadQueue::ProcessChannelEvent(this_01,pBVar1);
    }
  }
  uVar8 = (uint7)((ulonglong)pBVar5 >> 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    lVar7 = (ulonglong)uVar8 << 8;
  }
  else {
    lVar7 = CONCAT71(uVar8,1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if (((char)lVar7 != '\0') || (cVar10 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar7,cVar10,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x56,
               in_stack_ffffffffffffffa0,uVar11);
  }
  while (puVar9 != (undefined8 *)0xffffffffffffffff) {
    puVar4 = (undefined8 *)*puVar9;
    wil::unique_wdf_object_reference<void*___ptr64>::_scalar_deleting_destructor_
              ((unique_wdf_object_reference<void*___ptr64> *)(puVar9 + 1),(uint)lVar7);
    lVar7 = 0x646d4370;
    ExFreePoolWithTag(puVar9);
    puVar9 = puVar4;
  }
  return;
}



===== `scalar_deleting_destructor' @ 1400029b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void * __ptr64 __cdecl wil::unique_wdf_object_reference<void * __ptr64>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
wil::unique_wdf_object_reference<void*___ptr64>::_scalar_deleting_destructor_
          (unique_wdf_object_reference<void*___ptr64> *this,uint param_1)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)this,*(undefined8 *)(this + 8),0x1977,
               "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
  }
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  return this;
}



===== _Traverse @ 140002a18 =====

/* public: struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64 __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_Traverse(bool) __ptr64 */

_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
* __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_Traverse(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
            *this,bool param_1)

{
  code *pcVar1;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var2;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var3;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var4;
  ulonglong uVar5;
  byte bVar6;
  void **ppvVar7;
  bool bVar8;
  
  uVar5 = (ulonglong)param_1;
  ppvVar7 = &_TreeSentinel;
  bVar6 = !param_1;
  p_Var2 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             **)(this + uVar5 * 8 + 8);
  if (p_Var2 != (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)&_TreeSentinel) {
    if (this == (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)p_Var2) {
      pcVar1 = (code *)swi(0x2c);
      p_Var2 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                *)(*pcVar1)();
    }
    for (p_Var3 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                    **)(p_Var2 + (ulonglong)bVar6 * 8 + 8);
        p_Var3 != (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                   *)ppvVar7;
        p_Var3 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                   **)(p_Var3 + (ulonglong)bVar6 * 8 + 8)) {
      p_Var2 = p_Var3;
    }
    return p_Var2;
  }
  p_Var3 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
            *)(*(ulonglong *)this & 0xfffffffffffffffe);
  p_Var2 = p_Var3;
  if ((((*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
           **)(p_Var3 + uVar5 * 8 + 8) == this) &&
       (*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
          **)p_Var3 != this)) &&
      (p_Var2 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)((ulonglong)
                    *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                      **)p_Var3 & 0xfffffffffffffffe),
      *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(p_Var2 + uVar5 * 8 + 8) == p_Var3)) &&
     (p_Var4 = p_Var2,
     *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
       **)p_Var2 != p_Var3)) {
    do {
      p_Var2 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                *)(*(ulonglong *)p_Var4 & 0xfffffffffffffffe);
      bVar8 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                **)(p_Var2 + uVar5 * 8 + 8) == p_Var4;
      p_Var4 = p_Var2;
    } while (bVar8);
  }
  return p_Var2;
}



===== ProcessReadChannelEventRequest @ 140002aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelEventRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelEventRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  AvrcpTransportDevice *pAVar1;
  AvrcpTransportDevice *pAVar2;
  bool bVar3;
  undefined1 uVar4;
  long lVar5;
  void *pvVar6;
  longlong lVar7;
  AvrcpTransportDeviceReadQueue *this_00;
  longlong *plVar8;
  AvrcpTransportDevice *pAVar9;
  char cVar10;
  char cVar11;
  AvrcpTransportDevice *pAVar12;
  WDFMEMORY__ *pWVar13;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uStack_4f;
  undefined2 uStack_4b;
  undefined1 uStack_49;
  longlong local_48;
  undefined8 uStack_40;
  AvrcpTransportDevice *local_38;
  undefined8 uStack_30;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar11 = '\0';
  }
  else {
    cVar11 = '\x01';
  }
  if ((cVar10 != '\0') || (cVar11 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar11,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff80,0x7f,
               in_stack_ffffffffffffff90,(char)this);
  }
  pAVar1 = this + 0x8a0;
  local_48 = 0;
  uStack_40 = 0;
  *param_4 = 0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  pAVar2 = this + 0x8a8;
  pvVar6 = (void *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  if (*(AvrcpTransportDevice **)(this + 0x8b8) != pAVar2) {
    pAVar9 = *(AvrcpTransportDevice **)pAVar2;
    pAVar12 = pAVar2;
    do {
      if (*(void **)(pAVar9 + 0x18) < pvVar6) {
        lVar7 = 0x10;
      }
      else {
        lVar7 = 8;
        pAVar12 = pAVar9;
      }
      pAVar9 = *(AvrcpTransportDevice **)(pAVar9 + lVar7);
    } while (pAVar9 != (AvrcpTransportDevice *)&utl::_TreeSentinel);
    if ((pAVar12 != pAVar2) && (*(void **)(pAVar12 + 0x18) <= pvVar6)) {
      plVar8 = (longlong *)
               wil::wdf_object_reference_increment<void*___ptr64>
                         (&local_38,*(void **)(pAVar12 + 0x20),(long)pAVar12,(char *)0x879);
      if (&local_48 != plVar8) {
        wil::unique_wdf_object_reference<void*___ptr64>::reset
                  ((unique_wdf_object_reference<void*___ptr64> *)&local_48,(void *)*plVar8,
                   (void *)plVar8[1]);
        *plVar8 = 0;
        plVar8[1] = 0;
      }
      wil::unique_wdf_object_reference<void*___ptr64>::reset
                ((unique_wdf_object_reference<void*___ptr64> *)&local_38,(void *)0x0,(void *)0x0);
    }
  }
  if (pAVar1 != (AvrcpTransportDevice *)0x0) {
    uStack_30 = CONCAT17(uStack_49,CONCAT25(uStack_4b,CONCAT41(uStack_4f,uVar4)));
    local_38 = pAVar1;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
  }
  lVar7 = local_48;
  if (local_48 == 0) {
    lVar5 = -0x3ffffff0;
  }
  else {
    pWVar13 = (WDFMEMORY__ *)PTR__WDF_AvrcpTransportDeviceReadQueue_TYPE_INFO_14000f0a8;
    this_00 = (AvrcpTransportDeviceReadQueue *)
              (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_48);
    lVar5 = AvrcpTransportDeviceReadQueue::ProcessReadChannelEventRequest
                      (this_00,param_1,pWVar13,param_3,param_4);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar3)) {
    cVar10 = '\0';
  }
  else {
    cVar10 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar11 = '\0';
  }
  else {
    cVar11 = '\x01';
  }
  if ((cVar10 != '\0') || (cVar11 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar10,cVar11,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff80,0x80,
               in_stack_ffffffffffffff90,(char)this,(char)lVar5);
  }
  if (lVar7 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,lVar7,uStack_40,0x1977,
               "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
  }
  return lVar5;
}



===== ProcessReadChannelEventRequest @ 140002de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::ProcessReadChannelEventRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::
ProcessReadChannelEventRequest
          (AvrcpTransportDeviceReadQueue *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  AvrcpTransportDeviceReadQueue *pAVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  char cVar7;
  char cVar8;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  AvrcpTransportDeviceReadQueue *local_38;
  undefined1 uStack_30;
  undefined4 uStack_2f;
  undefined2 uStack_2b;
  undefined1 uStack_29;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x49,
               in_stack_ffffffffffffffb0,(char)this);
  }
  pAVar1 = this + 0x20;
  iVar4 = 0;
  bVar2 = false;
  *param_4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar6 = _uStack_30;
  _uStack_30 = CONCAT41(uStack_2f,uVar3);
  uStack_2b = SUB82(uVar6,5);
  uStack_29 = SUB81(uVar6,7);
  local_38 = pAVar1;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,*(undefined8 *)(this + 0x28));
  if (lVar5 == 0) {
    bVar2 = true;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x88))(WdfDriverGlobals,*(undefined8 *)(this + 0x28));
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_3);
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x620))(WdfDriverGlobals,lVar5,0,uVar6,0x11);
    if (-1 < iVar4) {
      *param_4 = 0x11;
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar5);
  }
  if (pAVar1 != (AvrcpTransportDeviceReadQueue *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
  }
  if (bVar2) {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_1);
    if (iVar4 < 0) goto LAB_140002ee1;
    iVar4 = 0x103;
LAB_140002f80:
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
LAB_1400030bd:
      bVar2 = true;
      goto LAB_140002ef5;
    }
  }
  else {
    if (-1 < iVar4) goto LAB_140002f80;
LAB_140002ee1:
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    goto LAB_1400030bd;
  }
  bVar2 = false;
LAB_140002ef5:
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar2)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xff,in_stack_ffffffffffffffa0,0x4a,
               in_stack_ffffffffffffffb0,(char)this,(char)iVar4);
  }
  return iVar4;
}



===== AdvisePnpDeviceReady @ 140003100 =====

/* public: enum
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::ConnectionAction __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::AdvisePnpDeviceReady(bool)
   __ptr64 */

ConnectionAction __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::AdvisePnpDeviceReady
          (AutoConnectionAdvisor *this,bool param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ConnectionAction CVar5;
  AutoConnectionAdvisor *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  uVar1 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar2);
  uStack_b = SUB82(uVar1,5);
  uStack_9 = SUB81(uVar1,7);
  if ((this[8] == (AutoConnectionAdvisor)0x0) || (this[9] == (AutoConnectionAdvisor)0x0)) {
    bVar4 = 0;
  }
  else {
    bVar4 = 1;
  }
  this[8] = (AutoConnectionAdvisor)param_1;
  if ((param_1) && (this[9] != (AutoConnectionAdvisor)0x0)) {
    bVar3 = 1;
  }
  else {
    bVar3 = 0;
  }
  if (bVar3 == bVar4) {
    CVar5 = 0;
  }
  else {
    CVar5 = (bVar3 ^ 1) + 1;
  }
  local_18 = this;
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  return CVar5;
}



===== StartConnect @ 1400031a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::StartConnect(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::StartConnect
          (AvrcpTransportDeviceService *this)

{
  AvrcpTransportDeviceService *pAVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  bool bVar6;
  char cVar7;
  char cVar8;
  unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
  local_res8 [8];
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  AvrcpTransportDeviceService *local_28;
  undefined1 uStack_20;
  undefined4 uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x41,
               in_stack_ffffffffffffffc0,(char)this);
  }
  pAVar1 = this + 0x38;
  uVar5 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar4 = _uStack_20;
  iVar2 = *(int *)(this + 0x48);
  _uStack_20 = CONCAT41(uStack_1f,uVar5);
  uStack_1b = SUB82(uVar4,5);
  uStack_19 = SUB81(uVar4,7);
  local_28 = pAVar1;
  if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
  }
  if (iVar2 == 1) {
    lVar3 = *(longlong *)(this + 0x108);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
    if (*(longlong *)(this + 0x110) != 0) {
      BtaMpmUpdateConnectionStatus();
    }
    if (lVar3 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    }
  }
  else {
    bVar6 = AutoConnectionAdvisor::GetReadiness((AutoConnectionAdvisor *)(this + 0x28));
    if (bVar6) {
      ConnectChannel(this,(void *)0x0);
    }
    else {
      wil::details::unique_wdf_wait_lock_storage::acquire
                ((unique_wdf_wait_lock_storage *)(this + 0x108));
      if (*(longlong *)(this + 0x110) != 0) {
        BtaMpmUpdateConnectionStatus();
      }
      wil::details::
      unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
                (local_res8);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x42,
               in_stack_ffffffffffffffc0,(char)this);
  }
  return;
}



===== AdviseWin32ServiceReady @ 140003430 =====

/* public: enum
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::ConnectionAction __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::AdviseWin32ServiceReady(bool)
   __ptr64 */

ConnectionAction __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AutoConnectionAdvisor::AdviseWin32ServiceReady
          (AutoConnectionAdvisor *this,bool param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ConnectionAction CVar5;
  AutoConnectionAdvisor *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  uVar1 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar2);
  uStack_b = SUB82(uVar1,5);
  uStack_9 = SUB81(uVar1,7);
  if ((this[8] == (AutoConnectionAdvisor)0x0) || (this[9] == (AutoConnectionAdvisor)0x0)) {
    bVar4 = 0;
    this[9] = (AutoConnectionAdvisor)param_1;
    bVar3 = 0;
    if (this[8] != (AutoConnectionAdvisor)0x0) goto LAB_140003488;
  }
  else {
    this[9] = (AutoConnectionAdvisor)param_1;
    bVar3 = 1;
LAB_140003488:
    bVar4 = bVar3;
    if (param_1) {
      bVar3 = 1;
      goto LAB_14000348f;
    }
  }
  bVar3 = 0;
LAB_14000348f:
  if (bVar3 == bVar4) {
    CVar5 = 0;
  }
  else {
    CVar5 = (bVar3 ^ 1) + 1;
  }
  local_18 = this;
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  return CVar5;
}



===== GetChannelHandle @ 1400034e0 =====

/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::GetChannelHandle(void
   * __ptr64 * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::GetChannelHandle
          (AvrcpTransportDeviceService *this,void **param_1)

{
  AvrcpTransportDeviceService *pAVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  long lVar4;
  AvrcpTransportDeviceService *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  pAVar1 = this + 0x38;
  lVar4 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar2 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar3);
  uStack_b = SUB82(uVar2,5);
  uStack_9 = SUB81(uVar2,7);
  if (*(int *)(this + 0x48) - 2U < 2) {
    lVar4 = -0x7fffffef;
  }
  else if (*(int *)(this + 0x48) == 0) {
    lVar4 = -0x3fffff63;
  }
  *param_1 = *(void **)(this + 0x40);
  if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
    local_18 = pAVar1;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return lVar4;
}



===== Release @ 140003590 =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(*(undefined8 *)param_1,param_1[8]);
  return;
}



===== ConnectChannel @ 1400035c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ConnectChannel(void *
   __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ConnectChannel
          (AvrcpTransportDeviceService *this,void *param_1)

{
  AvrcpTransportDeviceService *pAVar1;
  undefined1 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  char cVar6;
  long lVar7;
  _BRB *p_Var8;
  char cVar9;
  unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
  local_res8 [8];
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar10;
  AvrcpTransportDeviceService *local_38;
  undefined1 uStack_30;
  undefined4 uStack_2f;
  undefined2 uStack_2b;
  undefined1 uStack_29;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\x01';
  }
  uVar10 = SUB81(this,0);
  if ((cVar6 != '\0') || (cVar9 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x23,
               in_stack_ffffffffffffffb0,uVar10);
  }
  pAVar1 = this + 0x38;
  uVar2 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar4 = _uStack_30;
  _uStack_30 = CONCAT41(uStack_2f,uVar2);
  uStack_2b = SUB82(uVar4,5);
  uStack_29 = SUB81(uVar4,7);
  local_38 = pAVar1;
  if (*(int *)(this + 0x48) == 0) {
    *(undefined4 *)(this + 0x48) = 3;
    KeClearEvent(this + 0x50);
    if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
    if (param_1 == (void *)0x0) {
      (**(code **)(this + 0x150))(*(undefined8 *)(this + 0x160),0x212);
      uVar5 = 0x1b;
      if (*(int *)(this + 0x18) != 1) {
        uVar5 = 0x17;
      }
      *(undefined2 *)(*(longlong *)(this + 0x160) + 0x78) = uVar5;
    }
    else {
      (**(code **)(this + 0x150))(*(undefined8 *)(this + 0x160),0x213);
      *(void **)(*(longlong *)(this + 0x160) + 0x70) = param_1;
      *(undefined2 *)(*(longlong *)(this + 0x160) + 0x78) = 0;
    }
    *(undefined8 *)(*(longlong *)(this + 0x160) + 0x80) = *(undefined8 *)(this + 0x10);
    *(undefined4 *)(*(longlong *)(this + 0x160) + 0x7c) = 0;
    *(code **)(*(longlong *)(this + 0x160) + 0x108) = ChannelIndicationCallback;
    *(AvrcpTransportDeviceService **)(*(longlong *)(this + 0x160) + 0x110) = this;
    *(undefined4 *)(*(longlong *)(this + 0x160) + 0x100) = 1;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    *(undefined8 *)(*(longlong *)(this + 0x160) + 0x118) = uVar4;
    *(undefined1 *)(*(longlong *)(this + 0x160) + 0x1d0) = 10;
    *(undefined4 *)(*(longlong *)(this + 0x160) + 0x88) = 0x40;
    *(undefined4 *)(*(longlong *)(this + 0x160) + 200) = 3;
    *(undefined1 *)(*(longlong *)(this + 0x160) + 0xcc) = 0;
    *(undefined1 *)(*(longlong *)(this + 0x160) + 0xce) = 0x10;
    *(undefined2 *)(*(longlong *)(this + 0x160) + 0xd3) = 0xffff;
    *(undefined1 *)(*(longlong *)(this + 0x160) + 0xcd) = 0x3f;
    p_Var8 = *(_BRB **)(this + 0x160);
    lVar3 = SubmitControlBrbAsync(this,p_Var8);
    if (lVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        lVar7 = (int)((ulonglong)p_Var8 >> 8) << 8;
      }
      else {
        lVar7 = (long)CONCAT71((int7)((ulonglong)p_Var8 >> 8),1);
      }
      if (((char)lVar7 != '\0') ||
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_dq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar7,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffffa0,0x25,
                   in_stack_ffffffffffffffb0,(char)lVar3,uVar10);
      }
      uVar2 = KeAcquireSpinLockRaiseToDpc(pAVar1);
      _uStack_30 = CONCAT71(_uStack_2f,uVar2);
      *(undefined4 *)(this + 0x48) = 0;
      local_38 = pAVar1;
      wil::details::kernel_event_t<0>::set((kernel_event_t<0> *)(this + 0x50),lVar7);
      wil::details::
      unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                  *)&local_38);
      wil::details::unique_wdf_wait_lock_storage::acquire
                ((unique_wdf_wait_lock_storage *)(this + 0x108));
      if (*(longlong *)(this + 0x110) != 0) {
        BtaMpmUpdateConnectionStatus();
      }
      wil::details::
      unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
                (local_res8);
      ReportChannelStateEvent(this,0,0,false);
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    if ((cVar6 != '\0') || (cVar9 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x26,
                 in_stack_ffffffffffffffb0,uVar10);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffa0,0x24,
                 in_stack_ffffffffffffffb0,uVar10);
    }
    if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
  }
  return;
}



===== SubmitControlBrbAsync @ 140003a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitControlBrbAsync(struct
   _BRB * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitControlBrbAsync
          (AvrcpTransportDeviceService *this,_BRB *param_1)

{
  bool bVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  undefined8 local_res8;
  longlong local_res18;
  undefined8 in_stack_ffffffffffffff30;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 local_98;
  undefined8 local_94;
  undefined8 uStack_8c;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff30,0x2d,
               in_stack_ffffffffffffff40,(char)this);
  }
  local_78 = *(undefined8 *)this;
  local_94 = 0;
  uStack_8c = 0;
  local_84 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_98 = 0x38;
  local_80 = 1;
  local_7c = 1;
  local_res18 = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_98,uVar5,&local_res18);
  if (iVar4 < 0) {
LAB_140003b59:
    if (local_res18 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    if (-1 < iVar4) goto LAB_140003c3a;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    goto LAB_140003de6;
  }
  else {
    local_40 = local_res18;
    local_5c = 0;
    uStack_54 = 0;
    local_4c = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_60 = 0x38;
    local_48 = 1;
    local_44 = 1;
    local_res8 = 0;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x608))
                      (WdfDriverGlobals,&local_60,param_1,*(undefined4 *)(param_1 + 0x10),
                       &local_res8);
    lVar2 = local_res18;
    uVar5 = local_res8;
    if (iVar4 < 0) goto LAB_140003b59;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    in_stack_ffffffffffffff40 = 0;
    in_stack_ffffffffffffff30 = 0;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,uVar6,lVar2,0x410003,uVar5,0,0,0,0,0);
    if (iVar4 < 0) goto LAB_140003b59;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,local_res18,ControlBrbCompletionRoutine,this);
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    cVar3 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_res18,uVar5,0);
    if ((cVar3 == '\0') &&
       (iVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals), iVar4 < 0))
    goto LAB_140003b59;
LAB_140003c3a:
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
LAB_140003de6:
      bVar1 = true;
      goto LAB_140003b98;
    }
  }
  bVar1 = false;
LAB_140003b98:
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xff,in_stack_ffffffffffffff30,0x2e,
               in_stack_ffffffffffffff40,(char)this,(char)iVar4);
  }
  return iVar4;
}



===== WPP_RECORDER_AND_TRACE_SF_dq @ 140003e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_dq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,&param_9,4,
               &param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,
                    &param_9,4,&param_10,8,0);
  }
  return;
}



===== DisconnectChannel @ 140003f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::DisconnectChannel(void
   * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::DisconnectChannel
          (AvrcpTransportDeviceService *this,void *param_1)

{
  AvrcpTransportDeviceService *pAVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  long lVar4;
  char cVar5;
  long lVar6;
  _BRB *p_Var7;
  void *pvVar8;
  char cVar9;
  unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
  local_res8 [8];
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar10;
  AvrcpTransportDeviceService *local_38;
  undefined1 uStack_30;
  undefined4 uStack_2f;
  undefined2 uStack_2b;
  undefined1 uStack_29;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\x01';
  }
  uVar10 = SUB81(this,0);
  if ((cVar5 != '\0') || (cVar9 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x27,
               in_stack_ffffffffffffffb0,uVar10);
  }
  pAVar1 = this + 0x38;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar2 = _uStack_30;
  _uStack_30 = CONCAT41(uStack_2f,uVar3);
  uStack_2b = SUB82(uVar2,5);
  uStack_29 = SUB81(uVar2,7);
  local_38 = pAVar1;
  if (*(int *)(this + 0x48) == 1) {
    *(undefined4 *)(this + 0x48) = 2;
    KeClearEvent(this + 0x50);
    pvVar8 = param_1;
    if (param_1 == (void *)0x0) {
      pvVar8 = *(void **)(this + 0x40);
    }
    this[0x4c] = (AvrcpTransportDeviceService)(param_1 == (void *)0x0);
    if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
    (**(code **)(this + 0x150))(*(undefined8 *)(this + 0x168),0x104);
    *(undefined8 *)(*(longlong *)(this + 0x168) + 0x70) = *(undefined8 *)(this + 0x10);
    *(void **)(*(longlong *)(this + 0x168) + 0x78) = pvVar8;
    p_Var7 = *(_BRB **)(this + 0x168);
    lVar4 = SubmitControlBrbAsync(this,p_Var7);
    if (lVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        lVar6 = (int)((ulonglong)p_Var7 >> 8) << 8;
      }
      else {
        lVar6 = (long)CONCAT71((int7)((ulonglong)p_Var7 >> 8),1);
      }
      if (((char)lVar6 != '\0') ||
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_dq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(char)lVar6,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffffa0,0x29,
                   in_stack_ffffffffffffffb0,(char)lVar4,uVar10);
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar1);
      _uStack_30 = CONCAT71(_uStack_2f,uVar3);
      *(undefined4 *)(this + 0x48) = 0;
      local_38 = pAVar1;
      wil::details::kernel_event_t<0>::set((kernel_event_t<0> *)(this + 0x50),lVar6);
      wil::details::
      unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                  *)&local_38);
      wil::details::unique_wdf_wait_lock_storage::acquire
                ((unique_wdf_wait_lock_storage *)(this + 0x108));
      if (*(longlong *)(this + 0x110) != 0) {
        BtaMpmUpdateConnectionStatus();
      }
      wil::details::
      unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
                (local_res8);
      ReportChannelStateEvent(this,0,0,false);
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar9 = '\0';
    }
    else {
      cVar9 = '\x01';
    }
    if ((cVar5 != '\0') || (cVar9 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar9,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x2a,
                 in_stack_ffffffffffffffb0,uVar10);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffa0,0x28,
                 in_stack_ffffffffffffffb0,uVar10);
    }
    if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
  }
  return;
}



===== set @ 140004254 =====

/* public: bool __cdecl wil::details::kernel_event_t<0>::set(long) __ptr64 */

bool __thiscall wil::details::kernel_event_t<0>::set(kernel_event_t<0> *this,long param_1)

{
  int iVar1;
  
  iVar1 = KeSetEvent(this,0,0);
  return iVar1 != 0;
}



===== RegisterReadQueue @ 140004280 =====

/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::RegisterReadQueue(struct
   WDFFILEOBJECT__ * __ptr64,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > && __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::RegisterReadQueue
          (AvrcpTransportDevice *this,WDFFILEOBJECT__ *param_1,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>
          *param_2)

{
  AvrcpTransportDevice *pAVar1;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  long lVar7;
  WDFFILEOBJECT__ *pWVar8;
  undefined8 *puVar9;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var10;
  _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
  *this_00;
  _PairMapTag *p_Var11;
  _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
  *this_01;
  WDFFILEOBJECT__ *local_res8;
  WDFFILEOBJECT__ *local_res10;
  undefined8 uStack_50;
  AvrcpTransportDevice *local_48;
  undefined8 uStack_40;
  _PairMapTag local_38 [32];
  
  pAVar1 = this + 0x8a0;
  local_res10 = param_1;
  uVar6 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  this_01 = (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
             *)(this + 0x8a8);
  uStack_50 = CONCAT71(uStack_50._1_7_,uVar6);
  uVar5 = uStack_50;
  uStack_40 = uStack_50;
  local_48 = pAVar1;
  if (*(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
        **)(this + 0x8b8) == this_01) {
    pWVar8 = (WDFFILEOBJECT__ *)ExAllocatePool2(0x40,0x28,0x646d4370);
    if (pWVar8 == (WDFFILEOBJECT__ *)0x0) goto LAB_1400043cf;
    *(WDFFILEOBJECT__ **)(pWVar8 + 0x18) = param_1;
    *(ulonglong *)(pWVar8 + 0x20) = *(ulonglong *)param_2;
    *(undefined8 *)param_2 = 0;
    *(ulonglong *)pWVar8 = (ulonglong)this_01 | 1;
    *(void ***)(pWVar8 + 8) = &utl::_TreeSentinel;
    *(void ***)(pWVar8 + 0x10) = &utl::_TreeSentinel;
    bVar4 = true;
    *(WDFFILEOBJECT__ **)this_01 = pWVar8;
    *(WDFFILEOBJECT__ **)(this + 0x8b0) = pWVar8;
    *(WDFFILEOBJECT__ **)(this + 0x8b8) = pWVar8;
    *(longlong *)(this + 0x8c0) = *(longlong *)(this + 0x8c0) + 1;
  }
  else {
    local_res8 = (WDFFILEOBJECT__ *)0x0;
    p_Var11 = local_38;
    this_00 = this_01;
    puVar9 = (undefined8 *)
             utl::
             _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
             ::_FindInsertionPointUniqueUpper
                       (this_01,(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                                 **)p_Var11,&local_res8);
    p_Var2 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              *)*puVar9;
    uVar3 = puVar9[1];
    pWVar8 = local_res8;
    if (local_res8 == (WDFFILEOBJECT__ *)0x0) {
      p_Var10 = utl::
                _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
                ::
                _NewNodeConstruct<utl::_PairMapTag,WDFFILEOBJECT__*___ptr64_const&___ptr64,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>
                          (this_00,p_Var11,&local_res10,param_2);
      if (p_Var10 ==
          (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
           *)0x0) goto LAB_140004375;
      uStack_50._0_1_ = SUB81(uVar3,0);
      utl::
      _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      ::_HeadInsertNode((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                         *)this_01,p_Var2,uStack_50._0_1_,p_Var10);
      *(longlong *)(this + 0x8c0) = *(longlong *)(this + 0x8c0) + 1;
      bVar4 = true;
      goto LAB_14000433f;
    }
LAB_1400043cf:
    bVar4 = false;
  }
  if (pWVar8 == (WDFFILEOBJECT__ *)0x0) {
LAB_140004375:
    if (pAVar1 != (AvrcpTransportDevice *)0x0) {
      uStack_40 = uStack_50;
      local_48 = pAVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    return -0x3fffff66;
  }
LAB_14000433f:
  if (bVar4) {
    if (pAVar1 != (AvrcpTransportDevice *)0x0) {
      uStack_40 = uVar5;
      local_48 = pAVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    lVar7 = 0;
  }
  else {
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                *)&local_48);
    lVar7 = -0x3ffff8e8;
  }
  return lVar7;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 140004428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,&param_9,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,
                    &param_9,8,0);
  }
  return;
}



===== RequestConnect @ 1400044e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RequestConnect(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RequestConnect
          (AvrcpTransportDeviceService *this)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(this + 0x108);
  lVar2 = -0x3ffffe7c;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,lVar1,0);
  if (*(longlong *)(this + 0x110) != 0) {
    lVar2 = BtaMpmConnectionRequest(*(longlong *)(this + 0x110),1);
  }
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,lVar1);
  }
  return lVar2;
}



===== ControlBrbCompletionRoutine @ 140004580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ControlBrbCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64,void * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
ControlBrbCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  WDFREQUEST__ *local_res8;
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  WDFREQUEST__ *local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_2c = 0;
  local_res8 = (WDFREQUEST__ *)0x0;
  local_3c = 0;
  uStack_34 = 0;
  local_18 = 0;
  local_40 = 0x38;
  local_28 = 1;
  local_24 = 1;
  local_10 = PTR__WDF_CONTROL_BRB_WORKITEM_CONTEXT_TYPE_INFO_14000f120;
  local_58 = 0x18;
  pcStack_50 = ControlBrbCompletionWorkItem;
  local_48 = 0;
  local_20 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                    (WdfDriverGlobals,&local_58,&local_40,&local_res8);
  if (iVar1 < 0) {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x680);
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF_CONTROL_BRB_WORKITEM_CONTEXT_TYPE_INFO_14000f120);
    *puVar2 = param_1;
    puVar2[1] = param_4;
    pcVar3 = *(code **)(WdfFunctions_01015 + 0xbe0);
    param_1 = local_res8;
  }
  (*pcVar3)(WdfDriverGlobals,param_1);
  return;
}



===== invoke<void_(__cdecl*)(wil::details::kspin_lock_saved_irql_const&___ptr64),wil::details::kspin_lock_saved_irql&___ptr64> @ 1400046a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl wistd::invoke<void (__cdecl*)(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),struct wil::details::kspin_lock_saved_irql & __ptr64>(void (__cdecl*&& __ptr64)(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wil::details::kspin_lock_saved_irql &
   __ptr64) */

void __cdecl
wistd::
invoke<void_(__cdecl*)(wil::details::kspin_lock_saved_irql_const&___ptr64),wil::details::kspin_lock_saved_irql&___ptr64>
          (void____cdecl______ptr64__wil__details__kspin_lock_saved_irql_const____ptr64_ *param_1,
          kspin_lock_saved_irql *param_2)

{
  (**(code **)param_1)(param_2);
  return;
}



===== reset @ 1400046c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl wil::unique_wdf_object_reference<void * __ptr64>::reset(void * __ptr64,void
   * __ptr64) __ptr64 */

void __thiscall
wil::unique_wdf_object_reference<void*___ptr64>::reset
          (unique_wdf_object_reference<void*___ptr64> *this,void *param_1,void *param_2)

{
  if (*(longlong *)this == 0) {
    *(void **)this = param_1;
    *(void **)(this + 8) = param_2;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)this,*(undefined8 *)(this + 8),0x1977,
               "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
    *(void **)this = param_1;
    *(void **)(this + 8) = param_2;
  }
  return;
}



===== ChannelIndicationCallback @ 140004740 =====

/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ChannelIndicationCallback(void
   * __ptr64,enum _INDICATION_CODE,struct _INDICATION_PARAMETERS_ENHANCED * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ChannelIndicationCallback
          (void *param_1,_INDICATION_CODE param_2,_INDICATION_PARAMETERS_ENHANCED *param_3)

{
  OnChannelIndication(param_1,param_2,param_3);
  return;
}



===== OnChannelIndication @ 140004760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnChannelIndication(enum
   _INDICATION_CODE,struct _INDICATION_PARAMETERS_ENHANCED * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnChannelIndication
          (AvrcpTransportDeviceService *this,_INDICATION_CODE param_1,
          _INDICATION_PARAMETERS_ENHANCED *param_2)

{
  AvrcpTransportDevice *pAVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x3f,
               in_stack_ffffffffffffffe0,(char)this);
  }
  if (param_1 == 0) {
    pAVar1 = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDevice::AcquireIndicationReference(pAVar1);
  }
  else if (param_1 == 1) {
    pAVar1 = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDevice::ReleaseIndicationReference(pAVar1);
  }
  else if (param_1 == 3) {
    DisconnectChannel(this,*(void **)param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x40,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== OnConnectionlessIndication @ 1400048f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnConnectionlessIndication(enum
   _INDICATION_CODE,struct _INDICATION_PARAMETERS * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
OnConnectionlessIndication
          (AvrcpTransportDeviceService *this,_INDICATION_CODE param_1,
          _INDICATION_PARAMETERS *param_2)

{
  AvrcpTransportDevice *pAVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x3d,
               in_stack_ffffffffffffffe0,(char)this);
  }
  if (param_1 == 0) {
    pAVar1 = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDevice::AcquireIndicationReference(pAVar1);
  }
  else if (param_1 == 1) {
    pAVar1 = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDevice::ReleaseIndicationReference(pAVar1);
  }
  else if (param_1 == 2) {
    ConnectChannel(this,*(void **)param_2);
  }
  else if ((param_1 == 9) && (*(longlong *)(param_2 + 8) == *(longlong *)(this + 0x10))) {
    DisconnectChannel(this,(void *)0x0);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x3e,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== RtlStringCchPrintfW @ 140004a90 =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  size_t _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = 0;
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = 0;
      return 0;
    }
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== EvtObjectContextDestroyThunk @ 140004b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFDEVICE__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  if (lVar1 != 0) {
    utl::
    _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
    ::clear((_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
             *)(lVar1 + 0x8a8));
  }
  return;
}



===== clear @ 140004b68 =====

/* public: void __cdecl utl::_Tree<struct WDFFILEOBJECT__ * __ptr64,struct utl::pair<struct
   WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > >,struct utl::less<struct WDFFILEOBJECT__ *
   __ptr64>,class utl::allocator<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > >,0>::clear(void) __ptr64 */

void __thiscall
utl::
_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
::clear(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
        *this)

{
  _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
  *p_Var1;
  nothrow_t *in_RDX;
  _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
  *p_Var2;
  _Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
  *p_Var3;
  
  p_Var3 = *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
             **)(this + 0x10);
  if (p_Var3 == this) {
    return;
  }
  do {
    p_Var1 = *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
               **)(p_Var3 + 8);
    if (p_Var1 == (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
                   *)&_TreeSentinel) {
      while (p_Var1 = *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
                        **)(p_Var3 + 0x10), p_Var2 = p_Var3,
            p_Var1 == (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
                       *)&_TreeSentinel) {
        do {
          p_Var3 = (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
                    *)((ulonglong)*(void **)p_Var2 & 0xfffffffffffffffe);
          wil::details::
          unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
          ::
          ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                    ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                      *)(p_Var2 + 0x20));
          operator_delete(p_Var2,in_RDX);
          if (p_Var3 == this) {
            *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
              **)this = this;
            *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
              **)(this + 8) = this;
            *(_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
              **)(this + 0x10) = this;
            *(undefined8 *)(this + 0x18) = 0;
            return;
          }
          p_Var2 = p_Var3;
        } while (*(void ***)(p_Var3 + 8) == &_TreeSentinel);
        *(void ***)(p_Var3 + 8) = &_TreeSentinel;
      }
    }
    p_Var3 = p_Var1;
  } while( true );
}



===== EvtObjectContextDestroyThunk @ 140004c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<void * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<void*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_AvrcpTransportDeviceReadQueue_TYPE_INFO_14000f0a8);
  if (lVar1 != 0) {
    wil::details::
    unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                *)(lVar1 + 0x30));
    wil::details::
    unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
                *)(lVar1 + 0x28));
  }
  return;
}



===== acquire @ 140004c60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct WDFWAITLOCK__ * __ptr64,void (__cdecl*)(struct WDFWAITLOCK__
   * __ptr64),&void __cdecl WdfWaitLockRelease(struct WDFWAITLOCK__ * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct WDFWAITLOCK__ * __ptr64,struct WDFWAITLOCK__
   * __ptr64,0,std::nullptr_t> > > __cdecl wil::details::unique_wdf_wait_lock_storage::acquire(void)
   __ptr64 */

void __thiscall
wil::details::unique_wdf_wait_lock_storage::acquire(unique_wdf_wait_lock_storage *this)

{
  undefined8 uVar1;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)this;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,uVar1,0);
  *in_RDX = uVar1;
  return;
}



===== _NewNodeConstruct<utl::_PairMapTag,WDFFILEOBJECT__*___ptr64_const&___ptr64,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_> @ 140004cb0 =====

/* private: struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64 __cdecl utl::_Tree<struct WDFFILEOBJECT__ * __ptr64,struct utl::pair<struct
   WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > >,struct utl::less<struct WDFFILEOBJECT__ *
   __ptr64>,class utl::allocator<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > >,0>::_NewNodeConstruct<struct utl::_PairMapTag,struct WDFFILEOBJECT__ * __ptr64 const &
   __ptr64,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > >(struct utl::_PairMapTag && __ptr64,struct
   WDFFILEOBJECT__ * __ptr64 const & __ptr64,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<void * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   && __ptr64) __ptr64 */

_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
* __thiscall
utl::
_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
::
_NewNodeConstruct<utl::_PairMapTag,WDFFILEOBJECT__*___ptr64_const&___ptr64,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>
          (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
           *this,_PairMapTag *param_1,WDFFILEOBJECT__ **param_2,
          unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>
          *param_3)

{
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var1;
  
  p_Var1 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
            *)ExAllocatePool2(0x40,0x28,0x646d4370);
  if (p_Var1 != (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)0x0) {
    *(WDFFILEOBJECT__ **)(p_Var1 + 0x18) = *param_2;
    *(undefined8 *)(p_Var1 + 0x20) = *(undefined8 *)param_3;
    *(undefined8 *)param_3 = 0;
  }
  return p_Var1;
}



===== wdf_object_reference_increment<void*___ptr64> @ 140004d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* class wil::unique_wdf_object_reference<void * __ptr64> __cdecl
   wil::wdf_object_reference_increment<void * __ptr64>(void * __ptr64,void * __ptr64,long,char const
   * __ptr64) */

void * __cdecl
wil::wdf_object_reference_increment<void*___ptr64>
          (void *param_1,void *param_2,long param_3,char *param_4)

{
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_2,0,param_4,
             "onecore\\drivers\\bluetooth\\legacy\\avrcptransport\\lib\\avrcptransportdevice.cpp");
  *(undefined8 *)((longlong)param_1 + 8) = 0;
  *(void **)param_1 = param_2;
  return param_1;
}



===== EvtObjectContextCleanupThunk @ 140004d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>::EvtObjectContextCleanupThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFDEVICE__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>
::EvtObjectContextCleanupThunk(void *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  return;
}



===== reset @ 140004da0 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl BtaMpmUnregister(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::reset(void * __ptr64) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
        *this,void *param_1)

{
  if (*(longlong *)this != 0) {
    BtaMpmUnregister();
  }
  *(void **)this = param_1;
  return;
}



===== entry @ 140004de0 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140004e14 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FxDriverEntryWorker(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  _DRIVER_OBJECT *p_Var2;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    lVar1 = DriverEntry((_DRIVER_OBJECT *)0x0,param_2);
  }
  else {
    _DAT_14000f4c0 = 0x2080000;
    _DAT_14000f4c8 = &DAT_14000f230;
    RtlCopyUnicodeString(&DAT_14000f4c0);
    p_Var2 = param_1;
    lVar1 = WdfVersionBind(param_1,&DAT_14000f4c0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < lVar1) {
      lVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var2);
      if ((-1 < lVar1) && (lVar1 = FxStubInitTypes(), -1 < lVar1)) {
        lVar1 = DriverEntry(param_1,param_2);
        if (-1 < lVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000f438 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",lVar1,&DAT_14000f4c0);
        FxStubDriverEntryFailure();
      }
      FxStubDriverUnloadCommon();
    }
  }
  return lVar1;
}



===== attach_to_smart_pointer<wistd::unique_ptr<unsigned_short_[0],wistd::default_delete<unsigned_short_[0]>_>,void> @ 140004f38 =====

/* void __cdecl wil::attach_to_smart_pointer<class wistd::unique_ptr<unsigned short [0],struct
   wistd::default_delete<unsigned short [0]> >,void>(class wistd::unique_ptr<unsigned short
   [0],struct wistd::default_delete<unsigned short [0]> > & __ptr64,unsigned short * __ptr64) */

void __cdecl
wil::
attach_to_smart_pointer<wistd::unique_ptr<unsigned_short_[0],wistd::default_delete<unsigned_short_[0]>_>,void>
          (unique_ptr<unsigned_short_[0],wistd::default_delete<unsigned_short_[0]>_> *param_1,
          ushort *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)param_1;
  *(ushort **)param_1 = param_2;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x646d4370);
  }
  return;
}



===== wait_for_single_object @ 140004f70 =====

/* private: bool __cdecl wil::details::kernel_event_t<0>::wait_for_single_object(union
   _LARGE_INTEGER * __ptr64) __ptr64 */

bool __thiscall
wil::details::kernel_event_t<0>::wait_for_single_object
          (kernel_event_t<0> *this,_LARGE_INTEGER *param_1)

{
  int iVar1;
  
  iVar1 = KeWaitForSingleObject(this,0,0,0,param_1);
  return iVar1 == 0;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 140004fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,0);
  }
  return;
}



===== reset @ 140005024 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::reset(void * __ptr64) __ptr64 */

void __cdecl
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::reset(void *param_1)

{
  undefined8 in_RDX;
  
  if (*(longlong *)param_1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  *(undefined8 *)param_1 = in_RDX;
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_DD @ 14000506c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_DD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined8 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,param_9,0x10,
               &param_10,4,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,
                    param_9,0x10,&param_10,4,&param_11,4,0);
  }
  return;
}



===== OnMediaStatusChanged @ 140005170 =====

/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnMediaStatusChanged(void
   * __ptr64,int) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnMediaStatusChanged
          (void *param_1,int param_2)

{
  return 0;
}



===== AvrcpTransportDeviceReadQueue @ 14000517c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::AvrcpTransportDeviceReadQueue(struct
   WDFDEVICE__ * __ptr64,struct BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG const & __ptr64)
   __ptr64 */

AvrcpTransportDeviceReadQueue * __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::
AvrcpTransportDeviceReadQueue
          (AvrcpTransportDeviceReadQueue *this,WDFDEVICE__ *param_1,
          BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG *param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,this);
  *(undefined8 *)this = uVar1;
  *(WDFDEVICE__ **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = *(undefined2 *)param_2;
  KeInitializeSpinLock(this + 0x20);
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  return this;
}



===== FxStubDriverUnload @ 140005200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000f438 != (code *)0x0) && (DAT_14000f438 != FxStubDriverUnload)) {
    (*DAT_14000f438)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== AvrcpTransportDevice @ 140005240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::AvrcpTransportDevice(void)
   __ptr64 */

AvrcpTransportDevice * __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::AvrcpTransportDevice
          (AvrcpTransportDevice *this)

{
  AvrcpTransportDevice *pAVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals);
  *(undefined8 *)this = uVar2;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  memset(this + 0x18,0,0x730);
  memset(this + 0x748,0,0x110);
  KeInitializeSpinLock(this + 0x858);
  KeInitializeEvent(this + 0x860,0,1);
  *(undefined8 *)(this + 0x878) = 0;
  this[0x880] = (AvrcpTransportDevice)0x0;
  KeInitializeSpinLock(this + 0x8a0);
  pAVar1 = this + 0x8a8;
  *(AvrcpTransportDevice **)pAVar1 = pAVar1;
  *(AvrcpTransportDevice **)(this + 0x8b0) = pAVar1;
  *(AvrcpTransportDevice **)(this + 0x8b8) = pAVar1;
  *(undefined8 *)(this + 0x8c0) = 0;
  return this;
}



===== AvrcpTransportDeviceService @ 140005320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::AvrcpTransportDeviceService(struct
   WDFDEVICE__ * __ptr64,unsigned __int64,enum
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceServiceType) __ptr64 */

AvrcpTransportDeviceService * __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
AvrcpTransportDeviceService
          (AvrcpTransportDeviceService *this,WDFDEVICE__ *param_1,__uint64 param_2,
          AvrcpTransportDeviceServiceType param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  AvrcpTransportDeviceService *pAVar3;
  
  pAVar3 = this;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals);
  uVar2 = SUB81(pAVar3,0);
  *(__uint64 *)(this + 0x10) = param_2;
  *(undefined8 *)this = uVar1;
  *(undefined8 *)(this + 0x20) = 0;
  *(WDFDEVICE__ **)(this + 8) = param_1;
  *(AvrcpTransportDeviceServiceType *)(this + 0x18) = param_3;
  KeInitializeSpinLock(this + 0x28);
  *(undefined2 *)(this + 0x30) = 0;
  KeInitializeSpinLock(this + 0x38);
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  this[0x4c] = (AvrcpTransportDeviceService)0x0;
  wil::details::kernel_event_t<0>::kernel_event_t<0>((kernel_event_t<0> *)(this + 0x50),(bool)uVar2)
  ;
  memset(this + 0x68,0,0x50);
  memset(this + 0xb8,0,0x50);
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)(this + 0x110) = 0;
  memset(this + 0x118,0,0x48);
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  KeInitializeSpinLock(this + 0x170);
  *(undefined8 *)(this + 0x178) = 0xffffffffffffffff;
  *(undefined8 *)(this + 0x180) = 0xffffffffffffffff;
  *(undefined8 *)(this + 0x188) = 0xffffffffffffffff;
  return this;
}



===== ~AvrcpTransportDeviceService @ 14000544c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::~AvrcpTransportDeviceService(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
~AvrcpTransportDeviceService(AvrcpTransportDeviceService *this)

{
  code *pcVar1;
  
  wil::details::
  unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::reset((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *)(this + 0x110),(void *)0x0);
  if (*(longlong *)(this + 0x168) != 0) {
    pcVar1 = *(code **)(this + 0x140);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
    *(undefined8 *)(this + 0x168) = 0;
  }
  if (*(longlong *)(this + 0x160) != 0) {
    pcVar1 = *(code **)(this + 0x140);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
    *(undefined8 *)(this + 0x160) = 0;
  }
  if (*(code **)(this + 0x130) != (code *)0x0) {
    (**(code **)(this + 0x130))(*(undefined8 *)(this + 0x120));
  }
  utl::
  vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
  ::_Uninit((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
             *)(this + 0x178));
  wil::details::
  unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x110));
  wil::details::
  unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
              *)(this + 0x108));
  return;
}



===== ClientBrbCompletionRoutine @ 140005510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ClientBrbCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64,void * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
ClientBrbCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x610))
                    (WdfDriverGlobals,*(undefined8 *)(param_3 + 0x18),0);
  iVar4 = *(int *)(param_3 + 8);
  if (((-1 < iVar4) && (iVar4 = *(int *)(lVar2 + 0x1c), -1 < iVar4)) &&
     (*(char *)(lVar2 + 0x20) != '\0')) {
    iVar4 = -0x3fffffff;
  }
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    UntrackSentRequest(param_4,param_1);
  }
  if (iVar4 < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(lVar2 + 0x84);
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar4,uVar1);
  (**(code **)((longlong)param_4 + 0x140))(lVar2);
  return;
}



===== Stop @ 1400055e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Stop(void) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Stop
          (AvrcpTransportDeviceService *this)

{
  AvrcpTransportDeviceService *pAVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  char cVar7;
  longlong lVar8;
  char cVar9;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  AvrcpTransportDeviceService local_38 [16];
  AvrcpTransportDeviceService *local_28;
  undefined1 uStack_20;
  undefined4 uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar9 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x13,
               in_stack_ffffffffffffffb0,(char)this);
  }
  pAVar1 = this + 0x28;
  uVar5 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar4 = _uStack_20;
  _uStack_20 = CONCAT41(uStack_1f,uVar5);
  uStack_1b = SUB82(uVar4,5);
  uStack_19 = SUB81(uVar4,7);
  this[0x30] = (AvrcpTransportDeviceService)0x0;
  local_28 = pAVar1;
  if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
  }
  UnregisterServer(this);
  KeWaitForSingleObject(this + 0x50,0,0,0,0);
  StartDisconnect(this);
  KeWaitForSingleObject(this + 0x50,0,0,0,0);
  uVar6 = Feature_3736307001__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    lVar2 = *(longlong *)(this + 0x108);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
    if (*(longlong *)(this + 0x110) != 0) {
      BtaMpmUnregister();
    }
    *(undefined8 *)(this + 0x110) = 0;
    if (lVar2 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    }
  }
  else {
    lVar8 = 0;
    lVar2 = *(longlong *)(this + 0x108);
    pAVar1 = this + 0x110;
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
    if (local_38 != pAVar1) {
      lVar8 = *(longlong *)pAVar1;
      *(undefined8 *)pAVar1 = 0;
    }
    if (lVar2 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    }
    if (lVar8 != 0) {
      BtaMpmUnregister(lVar8);
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar3)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\x01';
  }
  if ((cVar7 != '\0') || (cVar9 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,cVar9,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x14,
               in_stack_ffffffffffffffb0,(char)this,0);
  }
  return 0;
}



===== SubmitClientBrbAsync @ 140005890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitClientBrbAsync(struct
   _BRB * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitClientBrbAsync
          (AvrcpTransportDeviceService *this,_BRB *param_1,WDFREQUEST__ *param_2)

{
  vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
  *this_00;
  undefined8 *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  __uint64 _Var9;
  WDFREQUEST__ *pWVar10;
  AvrcpTransportDeviceService *pAVar11;
  char cVar12;
  ulonglong uVar13;
  WDFREQUEST__ **ppWVar14;
  bool bVar15;
  undefined8 local_res18 [2];
  char *pcVar16;
  undefined8 in_stack_ffffffffffffff30;
  undefined8 in_stack_ffffffffffffff40;
  undefined1 uVar17;
  WDFREQUEST__ *local_98;
  AvrcpTransportDeviceService *local_90;
  AvrcpTransportDeviceService *local_88;
  undefined1 uStack_80;
  undefined4 uStack_7f;
  undefined2 uStack_7b;
  undefined1 uStack_79;
  undefined4 local_78;
  undefined8 local_74;
  undefined8 uStack_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  WDFREQUEST__ *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar12 = '\0';
  }
  else {
    cVar12 = '\x01';
  }
  uVar17 = SUB81(this,0);
  if ((cVar4 != '\0') || (cVar12 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar12,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff30,0x31,
               in_stack_ffffffffffffff40,uVar17);
  }
  local_78 = 0x38;
  local_60 = 1;
  local_74 = 0;
  uStack_6c = 0;
  local_64 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_5c = 1;
  local_res18[0] = 0;
  local_58 = param_2;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x608))
                    (WdfDriverGlobals,&local_78,param_1,*(undefined4 *)(param_1 + 0x10),local_res18)
  ;
  uVar8 = local_res18[0];
  if (iVar5 < 0) {
LAB_140005cbb:
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
      bVar15 = (byte)WPP_GLOBAL_Control[0x29] < 2;
LAB_140005ccd:
      if (!bVar15) {
        bVar15 = true;
        goto LAB_140005cd5;
      }
    }
  }
  else {
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    in_stack_ffffffffffffff40 = 0;
    in_stack_ffffffffffffff30 = 0;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x5f8))
                      (WdfDriverGlobals,uVar6,param_2,0x410003,uVar8,0,0,0,0,0);
    if (iVar5 < 0) goto LAB_140005cbb;
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_2,ClientBrbCompletionRoutine,this);
    uVar7 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 != 0) {
      pcVar16 = "onecore\\drivers\\bluetooth\\legacy\\avrcptransport\\lib\\avrcptransportdevice.cpp"
      ;
      (**(code **)(WdfFunctions_01015 + 0x668))(WdfDriverGlobals,param_2,this,0x2ce);
      pAVar11 = this + 0x170;
      local_98 = param_2;
      local_90 = this;
      uVar3 = KeAcquireSpinLockRaiseToDpc(pAVar11);
      uVar8 = _uStack_80;
      this_00 = (vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                 *)(this + 0x178);
      _uStack_80 = CONCAT41(uStack_7f,uVar3);
      uStack_7b = SUB82(uVar8,5);
      uStack_79 = SUB81(uVar8,7);
      puVar1 = *(undefined8 **)(this + 0x180);
      local_88 = pAVar11;
      if (puVar1 == *(undefined8 **)(this + 0x188)) {
        ppWVar14 = &local_98;
        uVar13 = (longlong)local_res18 + (-0xb0 - *(longlong *)this_00);
        uVar7 = (longlong)*(undefined8 **)(this + 0x188) - *(longlong *)this_00 >> 4;
        _Var9 = (uVar7 >> 2) * 7 + 8;
        if (0x7ffffffffffffff < _Var9) {
          _Var9 = 0x7ffffffffffffff;
        }
        if ((uVar7 < _Var9) &&
           (bVar15 = utl::
                     vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                     ::_SetCapacity(this_00,_Var9), bVar15)) {
          puVar1 = *(undefined8 **)(this + 0x180);
          lVar2 = *(longlong *)this_00;
          pWVar10 = param_2;
          if (uVar13 < (ulonglong)((longlong)puVar1 - lVar2)) {
            pWVar10 = *(WDFREQUEST__ **)(lVar2 + uVar13);
            ppWVar14 = (WDFREQUEST__ **)(lVar2 + uVar13);
          }
          *puVar1 = pWVar10;
          puVar1[1] = ppWVar14[1];
          *ppWVar14 = (WDFREQUEST__ *)0x0;
          ppWVar14[1] = (WDFREQUEST__ *)0x0;
          *(longlong *)(this + 0x180) = *(longlong *)(this + 0x180) + 0x10;
          pAVar11 = local_90;
          pWVar10 = local_98;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          else {
            cVar4 = '\x01';
          }
          if ((cVar4 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_qq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar16,in_stack_ffffffffffffff30,
                       0x2f,in_stack_ffffffffffffff40,(char)param_2,uVar17);
          }
          pAVar11 = this;
          pWVar10 = param_2;
        }
      }
      else {
        *puVar1 = param_2;
        puVar1[1] = this;
        *(longlong *)(this + 0x180) = *(longlong *)(this + 0x180) + 0x10;
        pAVar11 = (AvrcpTransportDeviceService *)0x0;
        pWVar10 = (WDFREQUEST__ *)0x0;
      }
      if (this != (AvrcpTransportDeviceService *)0xfffffffffffffe90) {
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_88);
      }
      if (pWVar10 != (WDFREQUEST__ *)0x0) {
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,pWVar10,pAVar11,0x1977,
                   "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
      }
    }
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
    cVar4 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_2,uVar8,0);
    if (cVar4 == '\0') {
      uVar7 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 != 0) {
        UntrackSentRequest(this,param_2);
      }
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals);
      if (iVar5 < 0) goto LAB_140005cbb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) {
      bVar15 = (byte)WPP_GLOBAL_Control[0x29] < 5;
      goto LAB_140005ccd;
    }
  }
  bVar15 = false;
LAB_140005cd5:
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar15)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar12 = '\0';
  }
  else {
    cVar12 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar12 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar12,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xff,in_stack_ffffffffffffff30,0x32,
               in_stack_ffffffffffffff40,uVar17,(char)iVar5);
  }
  return iVar5;
}



===== EvtObjectContextDestroyThunk @ 140005d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFDRIVER__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFDRIVER__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDriver_TYPE_INFO_14000f048);
  return;
}



===== ~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_> @ 140005d84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   WDFCOLLECTION__ * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct WDFCOLLECTION__ *
   __ptr64,struct WDFCOLLECTION__ * __ptr64,0,std::nullptr_t> >::~unique_storage<struct
   wil::details::resource_policy<struct WDFCOLLECTION__ * __ptr64,void (__cdecl*)(void *
   __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,struct WDFCOLLECTION__ * __ptr64,struct WDFCOLLECTION__ * __ptr64,0,std::nullptr_t>
   >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<WDFCOLLECTION__*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,WDFCOLLECTION__*___ptr64,WDFCOLLECTION__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== ConnectionlessIndicationCallback @ 140005dc0 =====

/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ConnectionlessIndicationCallback(void
   * __ptr64,enum _INDICATION_CODE,struct _INDICATION_PARAMETERS * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
ConnectionlessIndicationCallback
          (void *param_1,_INDICATION_CODE param_2,_INDICATION_PARAMETERS *param_3)

{
  OnConnectionlessIndication(param_1,param_2,param_3);
  return;
}



===== FxStubBindClasses @ 140005dd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140005dfd) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x14000f1df < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14000f1e8 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubDriverUnloadCommon @ 140005f38 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14000f4c0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== FxStubUnbindClasses @ 140005f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000f1e8 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_14000f1e8 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxStubInitTypes @ 14000602c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140006049) */
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
    if ((void **)0x14000f1ff < ppvVar2) break;
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



===== GetCurrentState @ 1400060f4 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::GetCurrentState(struct
   BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_STATE * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::GetCurrentState
          (AvrcpTransportDeviceService *this,BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_STATE *param_1)

{
  AvrcpTransportDeviceService *pAVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  AvrcpTransportDeviceService *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  pAVar1 = this + 0x38;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  uVar3 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar4);
  uStack_b = SUB82(uVar3,5);
  uStack_9 = SUB81(uVar3,7);
  *(uint *)param_1 = (*(int *)(this + 0x18) == 1) + 1;
  iVar2 = *(int *)(this + 0x48);
  param_1[8] = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_STATE)(iVar2 == 1);
  if (iVar2 == 1) {
    *(undefined2 *)(param_1 + 4) = *(undefined2 *)(this + 0x6c);
    *(undefined2 *)(param_1 + 6) = *(undefined2 *)(this + 0xbc);
  }
  if (pAVar1 != (AvrcpTransportDeviceService *)0x0) {
    local_18 = pAVar1;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_> @ 14000619c =====

/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,long (__cdecl*)(void * __ptr64),&long __cdecl BtaMpmUnregister(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<void * __ptr64,long (__cdecl*)(void *
   __ptr64),&long __cdecl BtaMpmUnregister(void * __ptr64),struct wistd::integral_constant<unsigned
   __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<void*___ptr64,long_(__cdecl*)(void*___ptr64),&long___cdecl_BtaMpmUnregister(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    BtaMpmUnregister();
  }
  return;
}



===== ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_> @ 1400061c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl wil::details::unique_storage<struct wil::details::resource_policy<struct
   WDFWAITLOCK__ * __ptr64,void (__cdecl*)(struct WDFWAITLOCK__ * __ptr64),&void __cdecl
   WdfWaitLockRelease(struct WDFWAITLOCK__ * __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct WDFWAITLOCK__ * __ptr64,struct WDFWAITLOCK__ * __ptr64,0,std::nullptr_t>
   >::~unique_storage<struct wil::details::resource_policy<struct WDFWAITLOCK__ * __ptr64,void
   (__cdecl*)(struct WDFWAITLOCK__ * __ptr64),&void __cdecl WdfWaitLockRelease(struct WDFWAITLOCK__
   * __ptr64),struct wistd::integral_constant<unsigned __int64,2>,struct WDFWAITLOCK__ *
   __ptr64,struct WDFWAITLOCK__ * __ptr64,0,std::nullptr_t> >(void) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
::
~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
          (unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
           *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  return;
}



===== kernel_event_t<0> @ 1400061f4 =====

/* public: __cdecl wil::details::kernel_event_t<0>::kernel_event_t<0>(bool) __ptr64 */

kernel_event_t<0> * __thiscall
wil::details::kernel_event_t<0>::kernel_event_t<0>(kernel_event_t<0> *this,bool param_1)

{
  KeInitializeEvent(this,0,1);
  return this;
}



===== ObjectAttributesInit @ 140006220 =====

/* public: static void __cdecl WdfCpp::ObjectContext<struct WDFDRIVER__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>::ObjectAttributesInit(struct
   _WDF_OBJECT_ATTRIBUTES * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFDRIVER__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>
::ObjectAttributesInit(_WDF_OBJECT_ATTRIBUTES *param_1)

{
  bool in_DL;
  
  SetEvtObjectContextCleanup<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver>
            (param_1,in_DL);
  *(code **)(param_1 + 0x10) = EvtObjectContextDestroyThunk;
  return;
}



===== SetEvtObjectContextCleanup<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver> @ 140006240 =====

/* protected: static void (__cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::*__cdecl
   WdfCpp::ObjectContext<struct WDFDRIVER__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>::SetEvtObjectContextCleanup<class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver>(struct _WDF_OBJECT_ATTRIBUTES
   * __ptr64,bool))(void) __ptr64 */

_func_void * __cdecl
WdfCpp::
ObjectContext<WDFDRIVER__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>
::SetEvtObjectContextCleanup<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver>
          (_WDF_OBJECT_ATTRIBUTES *param_1,bool param_2)

{
  *(code **)(param_1 + 8) = EvtObjectContextCleanupThunk;
  return (_func_void *)0x0;
}



===== out_param<wil::details::unique_wdf_wait_lock_storage> @ 140006258 =====

/* struct wil::details::out_param_t<class wil::details::unique_wdf_wait_lock_storage> __cdecl
   wil::out_param<class wil::details::unique_wdf_wait_lock_storage>(class
   wil::details::unique_wdf_wait_lock_storage & __ptr64) */

unique_wdf_wait_lock_storage * __cdecl
wil::out_param<wil::details::unique_wdf_wait_lock_storage>(unique_wdf_wait_lock_storage *param_1)

{
  undefined8 in_RDX;
  
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)param_1 = in_RDX;
  param_1[0x10] = (unique_wdf_wait_lock_storage)0x1;
  return param_1;
}



===== forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_> @ 140006270 =====

/* public: __cdecl utl::forward_list<class wil::unique_wdf_object_reference<void * __ptr64>,class
   utl::allocator<class wil::unique_wdf_object_reference<void * __ptr64> > >::forward_list<class
   wil::unique_wdf_object_reference<void * __ptr64>,class utl::allocator<class
   wil::unique_wdf_object_reference<void * __ptr64> > >(void) __ptr64 */

forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
* __thiscall
utl::
forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
::
forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
          (forward_list<wil::unique_wdf_object_reference<void*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<void*___ptr64>_>_>
           *this)

{
  *(undefined8 *)this = 0xffffffffffffffff;
  return this;
}



===== __report_gsfailure @ 140006290 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _vsnwprintf @ 1400062a0 =====

int __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnwprintf_l @ 1400062c0 =====

int __cdecl
_vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  local_38._12_4_ = 0;
  local_38._tmpfname._4_4_ = 0;
  local_38._file = 0;
  local_38._charbuf = 0;
  local_38._36_8_ = 0;
  if ((_Format == (wchar_t *)0x0) || ((_MaxCount != 0 && (_DstBuf == (wchar_t *)0x0)))) {
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    if (_MaxCount < 0x40000000) {
      local_38._cnt = (int)_MaxCount * 2;
    }
    else {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = (char *)_DstBuf;
    local_38._base = (char *)_DstBuf;
    iVar1 = _woutput_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
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



===== _flsbuf @ 1400063b8 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _woutput_l @ 1400063c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _woutput_l(FILE *_File,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  char *pcVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  wchar_t *pwVar13;
  uint uVar14;
  FILE *pFVar15;
  uint uVar16;
  ulonglong uVar17;
  wchar_t wVar18;
  ulonglong uVar19;
  uint uVar20;
  wchar_t *pwVar21;
  int iVar22;
  undefined1 auStack_4d8 [32];
  undefined8 local_4b8;
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
  FILE *local_470;
  undefined4 local_468;
  wchar_t *local_460;
  wchar_t local_448 [255];
  undefined2 local_249;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_4d8;
  local_468 = 0;
  uVar16 = 0;
  local_488 = 0;
  uVar12 = 0;
  uVar14 = 0;
  local_4a0 = 0;
  pwVar13 = (wchar_t *)0x0;
  local_4a4 = 0;
  local_478 = 0;
  local_480 = (wchar_t *)_ArgList;
  local_470 = _File;
  memset(local_448,0,0x400);
  local_49c[0] = L'\0';
  local_498 = 0;
  if ((_File == (FILE *)0x0) || (_Format == (wchar_t *)0x0)) {
LAB_140006c8c:
    local_4b8 = 0;
    _guard_check_icall();
    iVar6 = -1;
  }
  else {
    wVar18 = *_Format;
    iVar6 = 0;
    local_4a8 = 0;
    uVar19 = 0;
    local_494 = 0;
    if (wVar18 != L'\0') {
      do {
        pwVar21 = _Format + 1;
        if (iVar6 < 0) break;
        uVar8 = 0;
        if ((ushort)(wVar18 + L'￠') < 0x5b) {
          uVar20 = (int)(char)(&DAT_14000c6f0)[(ushort)wVar18] & 0xf;
        }
        else {
          uVar20 = uVar8;
        }
        uVar11 = (uint)(ushort)wVar18;
        local_494 = (int)(char)(&__lookuptable)[(int)(local_494 + uVar20 * 8)] >> 4;
        uVar20 = uVar16;
        local_460 = pwVar21;
        if (local_494 == 0) {
LAB_140006b60:
          local_498 = 1;
          write_char(wVar18,local_470,&local_4a8);
          uVar16 = uVar20;
LAB_140006a0e:
          iVar6 = local_4a8;
LAB_140006a16:
        }
        else if (local_494 == 1) {
          uVar12 = 0xffffffff;
          uVar14 = 0xffffffff;
          local_478 = 0;
          local_4a0 = 0xffffffff;
          local_488 = 0;
          local_4a4 = 0;
          local_498 = 0;
          uVar16 = uVar8;
        }
        else if (local_494 == 2) {
          if (uVar11 == 0x20) {
            uVar16 = uVar16 | 2;
          }
          else if (uVar11 == 0x23) {
            uVar16 = uVar16 | 0x80;
          }
          else if (uVar11 == 0x2b) {
            uVar16 = uVar16 | 1;
          }
          else if (uVar11 == 0x2d) {
            uVar16 = uVar16 | 4;
          }
          else if (uVar11 == 0x30) {
            uVar16 = uVar16 | 8;
          }
        }
        else if (local_494 == 3) {
          if (wVar18 == L'*') {
            uVar8 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            if ((int)uVar8 < 0) {
              uVar16 = uVar16 | 4;
            }
            local_488 = -uVar8;
            if (-1 < (int)uVar8) {
              local_488 = uVar8;
            }
          }
          else {
            local_488 = uVar11 + (local_488 * 5 + -0x18) * 2;
          }
        }
        else if (local_494 == 4) {
          local_4a0 = 0;
          uVar14 = uVar8;
          uVar12 = uVar8;
        }
        else if (local_494 == 5) {
          if (wVar18 == L'*') {
            local_4a0 = *(uint *)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            uVar14 = local_4a0;
            uVar12 = local_4a0;
            if ((int)local_4a0 < 0) {
              local_4a0 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar12 = 0xffffffff;
            }
          }
          else {
            local_4a0 = uVar11 + (uVar14 * 5 + -0x18) * 2;
            uVar14 = local_4a0;
            uVar12 = local_4a0;
          }
        }
        else if (local_494 == 6) {
          if (uVar11 == 0x49) {
LAB_140006ab1:
            uVar20 = uVar16 | 0x8000;
            if (wVar18 == L'I') {
              if (*pwVar21 == L'6') {
                if (_Format[2] != L'4') goto LAB_140006b34;
                pwVar21 = _Format + 3;
                uVar16 = uVar20;
              }
              else {
                if ((*pwVar21 != L'3') || (_Format[2] != L'2')) {
LAB_140006b34:
                  if ((ushort)(*pwVar21 + L'ﾨ') < 0x21) {
                    uVar16 = uVar20;
                    if ((0x120821001U >> ((ulonglong)(ushort)(*pwVar21 + L'ﾨ') & 0x3f) & 1) != 0)
                    goto LAB_140006a20;
                  }
                  local_494 = 0;
                  goto LAB_140006b60;
                }
                pwVar21 = _Format + 3;
                uVar16 = uVar16 & 0xffff7fff;
              }
            }
            else {
              uVar16 = uVar20;
              if (wVar18 != L'j') goto LAB_140006b34;
            }
          }
          else if (uVar11 == 0x68) {
            uVar16 = uVar16 | 0x20;
          }
          else {
            if (uVar11 == 0x6a) goto LAB_140006ab1;
            if (uVar11 == 0x6c) {
              if (*pwVar21 == L'l') {
                pwVar21 = _Format + 2;
                uVar16 = uVar16 | 0x1000;
              }
              else {
                uVar16 = uVar16 | 0x10;
              }
            }
            else {
              if (uVar11 == 0x74) goto LAB_140006ab1;
              if (uVar11 == 0x77) {
                uVar16 = uVar16 | 0x800;
              }
              else if (uVar11 == 0x7a) goto LAB_140006ab1;
            }
          }
        }
        else if (local_494 == 7) {
          if ((ushort)wVar18 < 0x6a) {
            if (wVar18 == L'i') {
LAB_140006559:
              uVar16 = uVar16 | 0x40;
LAB_14000655c:
              uVar19 = 10;
              goto LAB_140006567;
            }
            if (uVar11 == 0x43) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140006690:
              local_49c[0] = *(wchar_t *)_ArgList;
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              local_498 = 1;
              if ((uVar16 & 0x20) == 0) {
                local_448[0] = local_49c[0];
              }
              else {
                local_490[0] = (char)local_49c[0];
                local_490[1] = 0;
                iVar22 = mbtowc(local_448,local_490,(longlong)__mb_cur_max);
                if (iVar22 < 0) {
                  local_478 = 1;
                }
              }
              pwVar13 = local_448;
              uVar19 = 1;
            }
            else if (uVar11 == 0x53) {
              if ((uVar16 & 0x830) == 0) {
                uVar16 = uVar16 | 0x20;
              }
LAB_140006619:
              pwVar13 = *(wchar_t **)_ArgList;
              uVar8 = uVar14;
              if (uVar14 == 0xffffffff) {
                uVar8 = 0x7fffffff;
              }
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 & 0x20) == 0) {
                local_498 = 1;
                pwVar9 = L"(null)";
                pwVar5 = L"(null)";
                if (pwVar13 != (wchar_t *)0x0) {
                  pwVar9 = pwVar13;
                  pwVar5 = pwVar13;
                }
                for (; (pwVar13 = pwVar5, uVar8 != 0 && (uVar8 = uVar8 - 1, *pwVar9 != L'\0'));
                    pwVar9 = pwVar9 + 1) {
                  pwVar5 = pwVar13;
                }
                uVar19 = (longlong)pwVar9 - (longlong)pwVar13 >> 1 & 0xffffffff;
              }
              else {
                if (pwVar13 == (wchar_t *)0x0) {
                  pwVar13 = L"渨汵⥬";
                }
                pwVar9 = pwVar13;
                uVar19 = 0;
                if (0 < (int)uVar8) {
                  do {
                    if ((char)*pwVar9 == '\0') break;
                    pwVar9 = (wchar_t *)((longlong)pwVar9 + 1);
                    uVar20 = (int)uVar19 + 1;
                    uVar19 = (ulonglong)uVar20;
                  } while ((int)uVar20 < (int)uVar8);
                }
              }
            }
            else {
              if (uVar11 == 0x58) goto LAB_14000676a;
              if (uVar11 == 0x5a) {
                puVar3 = *(ushort **)_ArgList;
                local_480 = (wchar_t *)((longlong)_ArgList + 8);
                if ((puVar3 == (ushort *)0x0) ||
                   (pwVar13 = *(wchar_t **)(puVar3 + 4), pwVar13 == (wchar_t *)0x0)) {
                  pwVar13 = L"渨汵⥬";
                  uVar7 = 0xffffffffffffffff;
                  do {
                    uVar19 = uVar7 + 1;
                    pcVar1 = "null)" + uVar7;
                    uVar7 = uVar19;
                  } while (*pcVar1 != '\0');
                }
                else {
                  uVar2 = *puVar3;
                  if (puVar3[1] < uVar2) goto LAB_140006c8c;
                  uVar19 = (ulonglong)(uint)uVar2;
                  if ((uVar16 >> 0xb & 1) == 0) {
                    local_498 = 0;
                  }
                  else {
                    if (((~(uint)uVar2 & 1) == 0) || ((~(uint)pwVar13 & 1) == 0))
                    goto LAB_140006c8c;
                    uVar19 = (ulonglong)(uVar2 >> 1);
                    local_498 = 1;
                  }
                }
              }
              else {
                if (uVar11 == 99) goto LAB_140006690;
                if (uVar11 == 100) goto LAB_140006559;
              }
            }
LAB_1400068a6:
            if (local_478 != 0) goto LAB_140006a16;
            if ((uVar16 & 0x40) != 0) {
              if ((uVar16 >> 8 & 1) == 0) {
                if ((uVar16 & 1) == 0) {
                  if ((uVar16 & 2) == 0) goto LAB_1400068f4;
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
LAB_1400068f4:
            uVar14 = local_4a4;
            iVar6 = (int)uVar19;
            iVar22 = (local_488 - iVar6) - local_4a4;
            if ((uVar16 & 0xc) == 0) {
              write_multi_char(L' ',iVar22,local_470,&local_4a8);
            }
            write_string(&local_48c,uVar14,local_470,&local_4a8);
            pFVar15 = local_470;
            if ((uVar16 & 0xc) == 8) {
              write_multi_char(L'0',iVar22,local_470,&local_4a8);
            }
            if ((local_498 == 0) && (0 < iVar6)) {
              uVar7 = uVar19 & 0xffffffff;
              pwVar21 = pwVar13;
              do {
                iVar6 = mbtowc(local_49c,(char *)pwVar21,(longlong)__mb_cur_max);
                uVar14 = (int)uVar7 - ((iVar6 == 2) + 1);
                uVar7 = (ulonglong)uVar14;
                if (iVar6 < 1) {
                  local_4a8 = -1;
                  pFVar15 = local_470;
                  pwVar21 = local_460;
                  goto LAB_1400069ea;
                }
                write_char(local_49c[0],local_470,&local_4a8);
                pwVar21 = (wchar_t *)((longlong)pwVar21 + (longlong)iVar6);
              } while (0 < (int)uVar14);
              pFVar15 = local_470;
              pwVar21 = local_460;
            }
            else {
              write_string(pwVar13,iVar6,pFVar15,&local_4a8);
            }
LAB_1400069ea:
            iVar6 = local_4a8;
            if ((-1 < local_4a8) && ((uVar16 & 4) != 0)) {
              write_multi_char(L' ',iVar22,pFVar15,&local_4a8);
              uVar14 = local_4a0;
              uVar12 = local_4a0;
              goto LAB_140006a0e;
            }
          }
          else {
            if (wVar18 != L'n') {
              if (wVar18 == L'o') {
                uVar19 = 8;
                if ((char)uVar16 < '\0') {
                  uVar16 = uVar16 | 0x200;
                }
              }
              else {
                if (wVar18 == L'p') {
                  uVar12 = 0x10;
                  uVar14 = 0x10;
                  uVar16 = uVar16 | 0x8000;
LAB_14000676a:
                  local_468 = 7;
                }
                else {
                  if (wVar18 == L's') goto LAB_140006619;
                  if (wVar18 == L'u') goto LAB_14000655c;
                  if (wVar18 != L'x') goto LAB_1400068a6;
                  local_468 = 0x27;
                }
                if ((char)uVar16 < '\0') {
                  local_4a4 = 2;
                  local_48a = (short)local_468 + 0x51;
                  local_48c = L'0';
                }
                uVar19 = 0x10;
              }
LAB_140006567:
              local_480 = (wchar_t *)((longlong)_ArgList + 8);
              if ((uVar16 >> 0xf == 0) && ((uVar16 >> 0xc & 1) == 0)) {
                if ((uVar16 & 0x20) == 0) {
                  if ((uVar16 & 0x40) != 0) {
                    uVar7 = (ulonglong)(int)*(uint *)_ArgList;
                    goto LAB_1400067e1;
                  }
                  uVar7 = (ulonglong)*(uint *)_ArgList;
                }
                else if ((uVar16 & 0x40) == 0) {
                  uVar7 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar7 = (ulonglong)*(wchar_t *)_ArgList;
LAB_1400067e1:
                  if ((longlong)uVar7 < 0) {
                    uVar7 = -uVar7;
                    uVar16 = uVar16 | 0x100;
                  }
                }
              }
              else {
                uVar7 = *(ulonglong *)_ArgList;
                if ((uVar16 & 0x40) != 0) goto LAB_1400067e1;
              }
              uVar17 = uVar7 & 0xffffffff;
              if ((uVar16 & 0x9000) != 0) {
                uVar17 = uVar7;
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
              pwVar9 = &local_249;
              for (; (uVar14 = uVar12 - 1, 0 < (int)uVar12 || (uVar17 != 0));
                  uVar17 = uVar17 / uVar19) {
                uVar12 = (int)(uVar17 % uVar19) + 0x30;
                cVar10 = (char)uVar12;
                if (0x39 < uVar12) {
                  cVar10 = cVar10 + (char)local_468;
                }
                *(char *)pwVar9 = cVar10;
                pwVar9 = (wchar_t *)((longlong)pwVar9 + -1);
                uVar12 = uVar14;
              }
              uVar12 = (int)&local_249 - (int)pwVar9;
              uVar19 = (ulonglong)uVar12;
              pwVar13 = (wchar_t *)((longlong)pwVar9 + 1);
              if (((uVar16 >> 9 & 1) != 0) && ((uVar12 == 0 || (*(char *)pwVar13 != '0')))) {
                uVar19 = (ulonglong)(uVar12 + 1);
                *(char *)pwVar9 = '0';
                pwVar13 = pwVar9;
              }
              uVar12 = uVar14;
              local_4a0 = uVar14;
              goto LAB_1400068a6;
            }
            piVar4 = *(int **)_ArgList;
            local_480 = (wchar_t *)((longlong)_ArgList + 8);
            iVar22 = _get_printf_count_output();
            if (iVar22 == 0) goto LAB_140006c8c;
            if ((uVar16 & 0x20) == 0) {
              *piVar4 = iVar6;
            }
            else {
              *(short *)piVar4 = (short)iVar6;
            }
            local_478 = 1;
          }
          uVar14 = local_4a0;
          uVar12 = local_4a0;
        }
LAB_140006a20:
        wVar18 = *pwVar21;
        _Format = pwVar21;
        _ArgList = (va_list)local_480;
      } while (wVar18 != L'\0');
    }
  }
  return iVar6;
}



===== write_char @ 140006cd4 =====

void write_char(wchar_t param_1,FILE *param_2,int *param_3)

{
  wint_t wVar1;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    wVar1 = _fputwc_nolock(param_1,param_2);
    if ((wVar1 == 0xffff) && ((param_2->_flag & 0x20U) != 0)) {
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



===== write_multi_char @ 140006d28 =====

void write_multi_char(wchar_t param_1,int param_2,FILE *param_3,int *param_4)

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



===== write_string @ 140006d80 =====

void write_string(wchar_t *param_1,int param_2,FILE *param_3,int *param_4)

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



===== _guard_check_icall @ 140006e00 =====

void _guard_check_icall(void)

{
  return;
}



===== _get_printf_count_output @ 140006e0c =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_14000f220 == (__security_cookie | 1));
}



===== _fputwc_nolock @ 140006e2c =====

wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File)

{
  int *piVar1;
  int iVar2;
  
  if (_File == (FILE *)0x0) {
    _guard_check_icall();
    _Ch = L'\xffff';
  }
  else {
    piVar1 = &_File->_cnt;
    *piVar1 = *piVar1 + -2;
    if (*piVar1 < 0) {
      iVar2 = _flswbuf((uint)(ushort)_Ch,_File);
      _Ch = (wchar_t)iVar2;
    }
    else {
      *(wchar_t *)_File->_ptr = _Ch;
      _File->_ptr = _File->_ptr + 2;
    }
  }
  return _Ch;
}



===== mbtowc @ 140006e78 =====

int __cdecl mbtowc(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes)

{
  wchar_t wVar1;
  char *local_res10 [3];
  
  local_res10[0]._0_4_ = 0;
  if ((_SrcCh != (char *)0x0) && (_SrcSizeInBytes != 0)) {
    if (*_SrcCh == '\0') {
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = L'\0';
      }
    }
    else {
      local_res10[0] = _SrcCh;
      wVar1 = RtlAnsiCharToUnicodeChar(local_res10);
      *_DstCh = wVar1;
      local_res10[0]._0_4_ = (int)local_res10[0] - (int)_SrcCh;
    }
  }
  return (int)local_res10[0];
}



===== __GSHandlerCheck @ 140006ecc =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140006ef0 =====

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



===== _flswbuf @ 140006f58 =====

int __cdecl _flswbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return 0xffff;
}



===== __cpu_features_init @ 140006f70 =====

/* WARNING: Removing unreachable block (ram,0x000140006fda) */
/* WARNING: Removing unreachable block (ram,0x000140006f89) */
/* WARNING: Removing unreachable block (ram,0x000140006f7a) */

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



===== RtlAnsiCharToUnicodeChar @ 140007036 =====

void RtlAnsiCharToUnicodeChar(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140007036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlAnsiCharToUnicodeChar();
  return;
}



===== FxStubDriverEntryFailure @ 140007048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverEntryFailure(void) */

void __cdecl FxStubDriverEntryFailure(void)

{
  int iVar1;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000f1e8 != &__KMDF_CLASS_BIND_START) {
    local_1c = 0;
    uStack_18 = 0;
    local_14 = 0;
    local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
    local_20 = 0x18;
    iVar1 = WdfLdrQueryInterface(&local_28);
    if (-1 < iVar1) {
      (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
    }
  }
  return;
}



===== FxGetNextClassBindInfo @ 1400070b4 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== EvtObjectContextCleanupThunk @ 140007100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFDRIVER__ * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>::EvtObjectContextCleanupThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<WDFDRIVER__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>
::EvtObjectContextCleanupThunk(void *param_1)

{
  AvrcpTransportDriver *this;
  
  this = (AvrcpTransportDriver *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDriver_TYPE_INFO_14000f048);
  Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::EvtObjectContextCleanup(this);
  return;
}



===== DriverEntry @ 14000713c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long DriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  long lVar2;
  ulonglong uVar3;
  char cVar4;
  char cVar5;
  
  _DAT_14000f498 = 1;
  _WPP_MAIN_CB = 0;
  DAT_14000f478 = &WPP_ThisDir_CTLGUID_LegacyAvrcpTransportLibTraceGuid;
  DAT_14000f480 = 0;
  _DAT_14000f490 = 0;
  cVar5 = '\x01';
  _DAT_14000f4b0 = 0;
  _DAT_14000f4b8 = 0;
  WppLoadTracingSupport();
  _DAT_14000f490 = 0;
  WppInitKm(param_1,param_2);
  iVar1 = wil_InitializeFeatureStaging();
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
       (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,10,
                 &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids,(char)iVar1);
    }
  }
  uVar3 = InitializeTelemetryAssertsKMByDriverObject(param_1);
  if ((int)uVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      cVar5 = '\0';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xb,
                 &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids,(char)uVar3);
    }
  }
  lVar2 = Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::MakeAndInitialize
                    (param_1,param_2);
  if (lVar2 < 0) {
    DriverCleanup(param_1);
  }
  return lVar2;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 1400072e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_d
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined4 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,0);
  }
  return;
}



===== WppClassicProviderCallback @ 1400073a0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400073fc =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000e7c7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140007424 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140007570 =====

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



===== operator()<wil::unique_wdf_object_reference<WDFREQUEST___*>_> @ 1400075f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool <lambda_a806a49f997524ec77c68226c5c11469>::
     operator()<wil::unique_wdf_object_reference<WDFREQUEST___*>_>
               (longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,*param_2);
  return lVar1 != *param_1;
}



===== _InsertManyFillFn<<lambda_ba3483de173771986484699ed9d38c29>_> @ 140007630 =====

/* private: class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> * __ptr64 __cdecl
   utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64>,class
   utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> >
   >::_InsertManyFillFn<class <lambda_ba3483de173771986484699ed9d38c29> >(class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> * __ptr64,unsigned __int64,class
   <lambda_ba3483de173771986484699ed9d38c29>) __ptr64 */

unique_wdf_object_reference<WDFREQUEST__*___ptr64> * __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::_InsertManyFillFn<<lambda_ba3483de173771986484699ed9d38c29>_>
          (vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
           *this,unique_wdf_object_reference<WDFREQUEST__*___ptr64> *param_1,__uint64 param_2,
          undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  <lambda_ba3483de173771986484699ed9d38c29> *this_00;
  allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *paVar6;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar11;
  ulonglong uVar12;
  __uint64 _Var13;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar14;
  undefined8 local_res20;
  longlong local_58;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puStack_50;
  undefined8 local_48;
  
  puVar11 = *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8);
  paVar6 = *(allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> **)this;
  uVar12 = (longlong)puVar11 - (longlong)paVar6 >> 4;
  uVar1 = uVar12 + param_2;
  if (uVar1 <= uVar12) {
    if (uVar1 == uVar12) {
      return param_1;
    }
    return (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0x0;
  }
  uVar4 = *(longlong *)(this + 0x10) - (longlong)paVar6 >> 4;
  local_res20 = param_4;
  if (uVar1 <= uVar4) {
    if (puVar11 == param_1) {
      bVar3 = <lambda_ba3483de173771986484699ed9d38c29>::operator()
                        ((<lambda_ba3483de173771986484699ed9d38c29> *)&local_res20,paVar6,param_1,
                         param_2);
      if (bVar3) {
        *(__uint64 *)(this + 8) = *(longlong *)(this + 8) + param_2 * 0x10;
        return param_1;
      }
    }
    else {
      _Var13 = (longlong)puVar11 - (longlong)param_1 >> 4;
      puVar7 = param_1 + param_2 * 0x10;
      if (param_2 < _Var13) {
        lVar10 = _Var13 - param_2;
        bVar3 = _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                          (uVar1,paVar6,puVar11,param_1 + lVar10 * 0x10,param_2);
        if (bVar3) {
          *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8) =
               puVar11 + param_2 * 0x10;
          if (lVar10 != 0) {
            puVar14 = puVar7 + lVar10 * 0x10;
            do {
              puVar14 = puVar14 + -0x10;
              wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=
                        (puVar14,(unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)
                                 (puVar14 + ((longlong)param_1 - (longlong)puVar7)));
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
          }
          *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8) = puVar7;
          goto LAB_140007846;
        }
      }
      else {
        bVar3 = _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                          (uVar1,paVar6,puVar7,param_1,_Var13);
        if (bVar3) {
LAB_140007846:
          puVar14 = param_1;
          _EraseTail(this,param_1);
          this_00 = (<lambda_ba3483de173771986484699ed9d38c29> *)&local_res20;
          bVar3 = <lambda_ba3483de173771986484699ed9d38c29>::operator()
                            (this_00,(allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>
                                      *)puVar14,param_1,param_2);
          if (bVar3) {
            *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8) =
                 puVar11 + param_2 * 0x10;
            _Var13 = 0;
          }
          else {
            param_1 = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0x0;
          }
          _RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                    ((allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)this_00,
                     puVar7,_Var13);
          return param_1;
        }
      }
    }
    return (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0x0;
  }
  uVar5 = (uVar4 >> 2) * 7 + 8;
  uVar4 = uVar1;
  if (uVar1 <= uVar5) {
    uVar4 = uVar5;
  }
  if (0x7ffffffffffffff < uVar4) {
    uVar4 = 0x7ffffffffffffff;
  }
  if (uVar4 < uVar1) {
    return (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0x0;
  }
  vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
            ((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
              *)&local_58,paVar6,uVar4);
  lVar10 = local_58;
  if (local_58 != -1) {
    lVar8 = (longlong)param_1 - *(longlong *)this >> 4;
    bVar3 = _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                      ();
    if (bVar3) {
      lVar9 = lVar8 * 0x10;
      puStack_50 = puStack_50 + lVar9;
      bVar3 = <lambda_ba3483de173771986484699ed9d38c29>::operator()
                        ((<lambda_ba3483de173771986484699ed9d38c29> *)&local_res20,paVar6,puStack_50
                         ,param_2);
      if (bVar3) {
        puVar11 = puStack_50 + param_2 * 0x10;
        puStack_50 = puVar11;
        bVar3 = _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                          ();
        if (bVar3) {
          _Uninit(this);
          uVar2 = local_48;
          puVar7 = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)(lVar10 + lVar9);
          local_48 = 0xffffffffffffffff;
          *(undefined8 *)(this + 0x10) = uVar2;
          local_58 = -1;
          puStack_50 = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0xffffffffffffffff;
          *(longlong *)this = lVar10;
          *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8) =
               puVar11 + (uVar12 - lVar8) * 0x10;
          goto LAB_1400076e4;
        }
      }
    }
  }
  puVar7 = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0x0;
LAB_1400076e4:
  _Uninit((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
           *)&local_58);
  return puVar7;
}



===== _PartitionImp<utl::_ArrayIt<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_a806a49f997524ec77c68226c5c11469>_&> @ 1400078c0 =====

undefined8 *
utl::
_PartitionImp<utl::_ArrayIt<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_a806a49f997524ec77c68226c5c11469>_&>
          (undefined8 *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *this;
  unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *this_00;
  bool bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 local_18;
  undefined8 local_10;
  
  while (puVar2 = (undefined8 *)*param_2, puVar2 != (undefined8 *)*param_3) {
    bVar1 = <lambda_a806a49f997524ec77c68226c5c11469>::
            operator()<wil::unique_wdf_object_reference<WDFREQUEST___*>_>(param_4,puVar2);
    if (!bVar1) {
      do {
        puVar3 = (undefined8 *)(*param_3 + -0x10);
        *param_3 = (longlong)puVar3;
        puVar2 = (undefined8 *)*param_2;
        if (puVar2 == puVar3) goto LAB_140007964;
        bVar1 = <lambda_a806a49f997524ec77c68226c5c11469>::
                operator()<wil::unique_wdf_object_reference<WDFREQUEST___*>_>(param_4,puVar3);
      } while (!bVar1);
      this = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)*param_2;
      this_00 = (unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)*param_3;
      local_18 = *(undefined8 *)this;
      *(undefined8 *)this = 0;
      local_10 = *(undefined8 *)(this + 8);
      *(undefined8 *)(this + 8) = 0;
      wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=(this,this_00);
      wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=
                ((unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)this_00,
                 (unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)&local_18);
      wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::reset
                ((unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)&local_18,(WDFREQUEST__ *)0x0
                 ,(void *)0x0);
    }
    *param_2 = *param_2 + 0x10;
  }
LAB_140007964:
  *param_1 = puVar2;
  return param_1;
}



===== _RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_> @ 14000798c =====

/* void __cdecl utl::_RangeDestroyApc<class utl::allocator<class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > >(class utl::allocator<class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > & __ptr64,class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> * __ptr64,unsigned __int64) */

void __cdecl
utl::_RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
          (allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *param_1,
          unique_wdf_object_reference<WDFREQUEST__*___ptr64> *param_2,__uint64 param_3)

{
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *this;
  
  if (param_3 != 0) {
    this = param_2 + param_3 * 0x10;
    do {
      this = this + -0x10;
      wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::reset
                (this,(WDFREQUEST__ *)0x0,(void *)0x0);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}



===== _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_> @ 1400079d4 =====

/* bool __cdecl utl::_RangeTransferAppc<class utl::allocator<class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > >(struct
   utl::integral_constant<bool,0>,class utl::allocator<class wil::unique_wdf_object_reference<struct
   WDFREQUEST__ * __ptr64> > & __ptr64,class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> * __ptr64,class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> *
   __ptr64,unsigned __int64) */

bool __cdecl
utl::_RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
          (allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *param_1,
          undefined8 param_2,unique_wdf_object_reference<WDFREQUEST__*___ptr64> *param_3,
          longlong param_4,longlong param_5)

{
  undefined8 *puVar1;
  
  if (param_5 != 0) {
    puVar1 = (undefined8 *)(param_4 + 8);
    do {
      *(undefined8 *)(((longlong)param_3 - param_4) + -8 + (longlong)puVar1) = puVar1[-1];
      param_1 = (allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)*puVar1;
      *(allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> **)
       (((longlong)param_3 - param_4) + (longlong)puVar1) = param_1;
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1 = puVar1 + 2;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  _RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
            (param_1,param_3,0);
  return true;
}



===== _Resize<0> @ 140007a2c =====

/* private: bool __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::_Resize<0>(unsigned __int64) __ptr64 */

bool __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::_Resize<0>(vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
             *this,__uint64 param_1)

{
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar1;
  bool bVar2;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  uVar5 = *(longlong *)(this + 8) - *(longlong *)this >> 4;
  if (uVar5 < param_1) {
    bVar2 = reserve(this,param_1);
    if (bVar2) {
      puVar1 = *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8);
      bVar2 = true;
      lVar4 = param_1 - uVar5;
      if (lVar4 != 0) {
        puVar3 = puVar1;
        do {
          *(undefined8 *)puVar3 = 0;
          *(undefined8 *)(puVar3 + 8) = 0;
          puVar3 = puVar3 + 0x10;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
      }
      _RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                ((allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)0x0,puVar1,0
                );
      *(__uint64 *)(this + 8) = param_1 * 0x10 + *(longlong *)this;
    }
    else {
      bVar2 = false;
    }
  }
  else {
    _EraseTail(this,(unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)
                    (*(longlong *)this + param_1 * 0x10));
    bVar2 = true;
  }
  return bVar2;
}



===== erase_if<wil::unique_wdf_object_reference<WDFREQUEST___*>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_5ff2eca44cb02447b3256f37da78d202>_> @ 140007ad4 =====

longlong utl::
         erase_if<wil::unique_wdf_object_reference<WDFREQUEST___*>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_5ff2eca44cb02447b3256f37da78d202>_>
                   (vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                    *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *puVar3;
  __uint64 _Var4;
  __uint64 _Var5;
  __uint64 _Var6;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *this;
  longlong lVar7;
  
  plVar1 = *(longlong **)param_1;
  _Var6 = *(longlong *)(param_1 + 8) - (longlong)plVar1 >> 4;
  _Var5 = 0;
  if (_Var6 != 0) {
    plVar2 = plVar1;
    _Var4 = 0;
    do {
      _Var5 = _Var4 + 1;
      if (param_2 == *plVar2) {
        if (_Var5 != _Var6) {
          this = (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)(plVar1 + _Var4 * 2);
          puVar3 = (unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)(plVar1 + _Var5 * 2)
          ;
          lVar7 = _Var6 - _Var5;
          do {
            if (param_2 != *(longlong *)puVar3) {
              wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=(this,puVar3);
              _Var4 = _Var4 + 1;
              this = this + 0x10;
            }
            puVar3 = puVar3 + 0x10;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
        }
        vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
        ::_Resize<0>(param_1,_Var4);
        _Var5 = _Var4;
        break;
      }
      plVar2 = plVar2 + 2;
      _Var4 = _Var5;
    } while (_Var5 != _Var6);
  }
  return _Var6 - _Var5;
}



===== vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_> @ 140007ba0 =====

/* private: __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64>,class
   utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > >(class
   utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > const &
   __ptr64,unsigned __int64) __ptr64 */

vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
* __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
          (vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
           *this,allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *param_1,
          __uint64 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 < 0x1000000000000000) {
    lVar1 = ExAllocatePool2(0x40,param_2 * 0x10,0x646d4370);
  }
  else {
    lVar1 = 0;
  }
  *(longlong *)this = lVar1;
  if (lVar1 == 0) {
    lVar2 = -1;
    *(undefined8 *)this = 0xffffffffffffffff;
    lVar1 = -1;
  }
  else {
    lVar2 = param_2 * 0x10 + lVar1;
  }
  *(longlong *)(this + 8) = lVar1;
  *(longlong *)(this + 0x10) = lVar2;
  return this;
}



===== operator= @ 140007c18 =====

/* public: class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> & __ptr64 __cdecl
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64>::operator=(class
   wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> && __ptr64) __ptr64 */

unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> * __thiscall
wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=
          (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *this,
          unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *param_1)

{
  if (this != (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)param_1) {
    reset(this,*(WDFREQUEST__ **)param_1,*(void **)(param_1 + 8));
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return (unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)this;
}



===== operator() @ 140007c58 =====

/* public: bool __cdecl <lambda_ba3483de173771986484699ed9d38c29>::operator()(class
   utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> > &
   __ptr64,class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> * __ptr64,unsigned
   __int64)const __ptr64 */

bool __thiscall
<lambda_ba3483de173771986484699ed9d38c29>::operator()
          (<lambda_ba3483de173771986484699ed9d38c29> *this,
          allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *param_1,
          unique_wdf_object_reference<WDFREQUEST__*___ptr64> *param_2,__uint64 param_3)

{
  allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *paVar1;
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar2;
  
  paVar1 = (allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)
           **(undefined8 **)this;
  if (param_3 != 0) {
    puVar2 = param_2;
    do {
      *(undefined8 *)puVar2 = *(undefined8 *)paVar1;
      *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(paVar1 + 8);
      *(undefined8 *)paVar1 = 0;
      *(undefined8 *)(paVar1 + 8) = 0;
      paVar1 = paVar1 + 0x10;
      param_3 = param_3 - 1;
      puVar2 = puVar2 + 0x10;
    } while (param_3 != 0);
  }
  utl::_RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
            (paVar1,param_2,0);
  return true;
}



===== AcquireIndicationReference @ 140007cac =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::AcquireIndicationReference(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::AcquireIndicationReference
          (AvrcpTransportDevice *this)

{
  IndicationReferenceCounter::Increment((IndicationReferenceCounter *)(this + 0x858));
  return;
}



===== CancelSentRequestsForFileObject @ 140007cc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::CancelSentRequestsForFileObject(struct
   WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
CancelSentRequestsForFileObject(AvrcpTransportDeviceService *this,WDFFILEOBJECT__ *param_1)

{
  AvrcpTransportDeviceService *pAVar1;
  bool bVar2;
  AvrcpTransportDeviceService *pAVar3;
  WDFFILEOBJECT__ *pWVar4;
  undefined8 *puVar5;
  longlong lVar6;
  AvrcpTransportDeviceService *this_00;
  WDFFILEOBJECT__ *local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff40;
  undefined8 in_stack_ffffffffffffff50;
  longlong local_98 [2];
  AvrcpTransportDeviceService *local_88;
  undefined1 uStack_80;
  undefined7 uStack_7f;
  AvrcpTransportDeviceService *local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 *puStack_60;
  undefined8 local_58;
  
  pAVar1 = this + 0x170;
  local_58 = 0xffffffffffffffff;
  local_68 = (undefined8 *)0xffffffffffffffff;
  puStack_60 = (undefined8 *)0xffffffffffffffff;
  uStack_80 = KeAcquireSpinLockRaiseToDpc(pAVar1);
  local_res20 = *(longlong *)(this + 0x180);
  uStack_70 = CONCAT71(uStack_7f,uStack_80);
  local_98[0] = *(longlong *)(this + 0x178);
  local_res18 = param_1;
  local_88 = pAVar1;
  local_78 = pAVar1;
  utl::
  _PartitionImp<utl::_ArrayIt<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_a806a49f997524ec77c68226c5c11469>_&>
            (&local_88,local_98,&local_res20,(longlong *)&local_res18);
  pAVar3 = local_88;
  local_res18 = (WDFFILEOBJECT__ *)local_88;
  pWVar4 = (WDFFILEOBJECT__ *)
           utl::
           vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
           ::_InsertManyFillFn<<lambda_ba3483de173771986484699ed9d38c29>_>
                     ((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                       *)&local_68,0xffffffffffffffff,
                      *(longlong *)(this + 0x180) - (longlong)local_88 >> 4,&local_res18);
  pAVar1 = *(AvrcpTransportDeviceService **)(this + 0x180);
  bVar2 = true;
  local_res18 = pWVar4;
  if (pAVar3 != pAVar1) {
    lVar6 = *(longlong *)(this + 0x180) - (longlong)pAVar1 >> 4;
    if (lVar6 != 0) {
      this_00 = pAVar3;
      do {
        wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::operator=
                  ((unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)this_00,
                   (unique_wdf_object_reference<struct_WDFREQUEST__*___ptr64> *)
                   (this_00 + ((longlong)pAVar1 - (longlong)pAVar3)));
        this_00 = this_00 + 0x10;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    pWVar4 = local_res18;
    utl::
    vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
    ::_EraseTail((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                  *)(this + 0x178),
                 (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)
                 (*(longlong *)(this + 0x180) -
                 ((longlong)pAVar1 - (longlong)pAVar3 & 0xfffffffffffffff0U)));
  }
  if (pWVar4 == (WDFFILEOBJECT__ *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar2 = false;
    }
    if ((bVar2) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff38,
                 in_stack_ffffffffffffff40,0x30,in_stack_ffffffffffffff50,(char)param_1,(char)this);
    }
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                *)&local_78);
  }
  else {
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::
    ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                *)&local_78);
    for (puVar5 = local_68; puVar5 != puStack_60; puVar5 = puVar5 + 2) {
      (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,*puVar5);
    }
  }
  utl::
  vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
  ::_Uninit((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
             *)&local_68);
  return;
}



===== Decrement @ 140007ebc =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::Decrement(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::Decrement
          (IndicationReferenceCounter *this)

{
  undefined1 uVar1;
  longlong lVar2;
  char cVar3;
  long in_EDX;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  IndicationReferenceCounter *local_18;
  undefined8 uStack_10;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  uStack_20 = CONCAT31(uStack_20._1_3_,uVar1);
  uStack_10 = CONCAT44(uStack_1c,uStack_20);
  local_18 = this;
  if (*(longlong *)(this + 0x20) == 0) {
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
             *)&local_18);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x9c,
                 &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
    }
    MicrosoftTelemetryAssertTriggeredMsgKM("Indication reference counter underref.");
  }
  else {
    lVar2 = *(longlong *)(this + 0x20) + -1;
    *(longlong *)(this + 0x20) = lVar2;
    if (lVar2 == 0) {
      wil::details::kernel_event_t<0>::set((kernel_event_t<0> *)(this + 8),in_EDX);
    }
  }
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              *)&local_18);
  return;
}



===== EvtObjectContextDestroyThunk @ 140007fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<void * __ptr64,class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService,0>::EvtObjectContextDestroyThunk(void
   * __ptr64) */

void __cdecl
WdfCpp::
ObjectContext<void*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService,0>
::EvtObjectContextDestroyThunk(void *param_1)

{
  AvrcpTransportDeviceService *this;
  
  this = (AvrcpTransportDeviceService *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,
                    PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
  if (this != (AvrcpTransportDeviceService *)0x0) {
    Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::
    ~AvrcpTransportDeviceService(this);
  }
  return;
}



===== ForwardRequest @ 140008004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl WdfCpp::ObjectDispatchHandler<class
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice>::ForwardRequest(struct
   WDFQUEUE__ * __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64) __ptr64 */

void __thiscall
WdfCpp::ObjectDispatchHandler<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice>::
ForwardRequest(ObjectDispatchHandler<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice>
               *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,WDFIOTARGET__ *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_18 [2];
  
  local_18[0] = 0x100000008;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x2e0))(WdfDriverGlobals,uVar2);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xc58))(WdfDriverGlobals,param_2,uVar2,local_18);
  if (iVar1 < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  return;
}



===== Increment @ 1400080b4 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::Increment(void) __ptr64
    */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::Increment
          (IndicationReferenceCounter *this)

{
  bool bVar1;
  IndicationReferenceCounter *local_28;
  undefined1 uStack_20;
  undefined3 uStack_1f;
  undefined4 uStack_1c;
  IndicationReferenceCounter *local_18;
  undefined1 uStack_10;
  undefined3 uStack_f;
  undefined4 uStack_c;
  
  uStack_10 = KeAcquireSpinLockRaiseToDpc();
  bVar1 = true;
  *(longlong *)(this + 0x20) = *(longlong *)(this + 0x20) + 1;
  uStack_f = uStack_1f;
  uStack_c = uStack_1c;
  local_28 = this;
  uStack_20 = uStack_10;
  local_18 = this;
  if (*(longlong *)(this + 0x20) == 1) {
    KeClearEvent(this + 8);
  }
  if (this[0x28] != (IndicationReferenceCounter)0x0) {
    local_28 = (IndicationReferenceCounter *)0x0;
    uStack_20 = 0;
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
             *)&local_18,&local_28);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x9b,
                 &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
    }
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("Indication reference counter incremented after waiting for zero.");
  }
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              *)&local_18);
  return;
}



===== ReleaseIndicationReference @ 1400081c8 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ReleaseIndicationReference(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ReleaseIndicationReference
          (AvrcpTransportDevice *this)

{
  IndicationReferenceCounter::Decrement((IndicationReferenceCounter *)(this + 0x858));
  return;
}



===== RequestDisconnect @ 1400081e4 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RequestDisconnect(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RequestDisconnect
          (AvrcpTransportDeviceService *this)

{
  long lVar1;
  unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
  local_res8 [8];
  
  lVar1 = -0x3ffffe7c;
  wil::details::unique_wdf_wait_lock_storage::acquire
            ((unique_wdf_wait_lock_storage *)(this + 0x108));
  if (*(longlong *)(this + 0x110) != 0) {
    lVar1 = BtaMpmConnectionRequest(*(longlong *)(this + 0x110),0,0);
  }
  wil::details::
  unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<WDFWAITLOCK__*___ptr64,void_(__cdecl*)(WDFWAITLOCK__*___ptr64),&void___cdecl_WdfWaitLockRelease(struct_WDFWAITLOCK__*___ptr64),wistd::integral_constant<unsigned___int64,2>,WDFWAITLOCK__*___ptr64,WDFWAITLOCK__*___ptr64,0,std::nullptr_t>_>
            (local_res8);
  return lVar1;
}



===== UntrackSentRequest @ 140008244 =====

/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::UntrackSentRequest(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::UntrackSentRequest
          (AvrcpTransportDeviceService *this,WDFREQUEST__ *param_1)

{
  undefined1 uVar1;
  AvrcpTransportDeviceService *local_18;
  undefined1 uStack_10;
  undefined7 uStack_f;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(this + 0x170);
  _uStack_10 = CONCAT71(uStack_f,uVar1);
  local_18 = this + 0x170;
  utl::
  erase_if<wil::unique_wdf_object_reference<WDFREQUEST___*>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST___*>_>,<lambda_5ff2eca44cb02447b3256f37da78d202>_>
            ((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
              *)(this + 0x178),(longlong)param_1);
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              *)&local_18);
  return;
}



===== WaitForZero @ 1400082b4 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::WaitForZero(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::IndicationReferenceCounter::WaitForZero
          (IndicationReferenceCounter *this)

{
  bool bVar1;
  undefined1 uVar2;
  bool bVar3;
  char cVar4;
  undefined8 local_res8;
  IndicationReferenceCounter *local_28;
  undefined1 uStack_20;
  undefined7 uStack_1f;
  undefined8 local_18;
  uint uStack_10;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  _uStack_20 = CONCAT71(uStack_1f,uVar2);
  local_28 = this;
  if (this[0x28] == (IndicationReferenceCounter)0x0) {
    bVar1 = true;
    this[0x28] = (IndicationReferenceCounter)0x1;
    if (*(longlong *)(this + 0x20) != 0) {
      wil::details::
      unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
      ::
      ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
                  *)&local_28);
      local_res8 = 0xffffffffee1e5d00;
      bVar3 = wil::details::kernel_event_t<0>::wait_for_single_object
                        ((kernel_event_t<0> *)(this + 8),(_LARGE_INTEGER *)&local_res8);
      if (bVar3) {
        return;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_AND_TRACE_SF_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x9e,
                   &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
      }
      MicrosoftTelemetryAssertTriggeredMsgKM
                ("Timed out waiting on indication reference counter to reach zero.");
      return;
    }
  }
  else {
    uStack_10 = uStack_10 & 0xffffff00;
    local_18 = 0;
    wil::details::
    unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
    ::reset((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
             *)&local_28,&local_18);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x9d,
                 &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
    }
    MicrosoftTelemetryAssertTriggeredMsgKM
              ("Waiting on indication reference counter to reach zero more than once.");
  }
  wil::details::
  unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
  ::
  ~unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
            ((unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
              *)&local_28);
  return;
}



===== _EraseTail @ 140008454 =====

/* private: void __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::_EraseTail(class wil::unique_wdf_object_reference<struct WDFREQUEST__ * __ptr64> *
   __ptr64) __ptr64 */

void __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::_EraseTail(vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
             *this,unique_wdf_object_reference<WDFREQUEST__*___ptr64> *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)(this + 8) = param_1;
  _RangeDestroyApc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
            ((allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)this,param_1,
             lVar1 - (longlong)param_1 >> 4);
  return;
}



===== _FindInsertionPointUniqueUpper @ 140008478 =====

/* private: struct utl::pair<struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > > * __ptr64,bool> __cdecl utl::_Tree<struct
   WDFFILEOBJECT__ * __ptr64,struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   >,struct utl::less<struct WDFFILEOBJECT__ * __ptr64>,class utl::allocator<struct utl::pair<struct
   WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >,0>::_FindInsertionPointUniqueUpper(struct
   utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64 & __ptr64,struct WDFFILEOBJECT__ * __ptr64 const & __ptr64) __ptr64 */

_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
** __thiscall
utl::
_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
::_FindInsertionPointUniqueUpper
          (_Tree<WDFFILEOBJECT__*___ptr64,utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>,utl::less<WDFFILEOBJECT__*___ptr64>,utl::allocator<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>,0>
           *this,_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 **param_1,WDFFILEOBJECT__ **param_2)

{
  void *pvVar1;
  WDFFILEOBJECT__ *pWVar2;
  ulonglong *in_R9;
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var3;
  bool bVar4;
  
  p_Var3 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             **)this;
  *param_2 = (WDFFILEOBJECT__ *)0x0;
  pvVar1 = (void *)*in_R9;
  do {
    bVar4 = *(void **)(p_Var3 + 0x18) <= pvVar1;
    if (bVar4) {
      *param_2 = (WDFFILEOBJECT__ *)p_Var3;
    }
    *param_1 = p_Var3;
    p_Var3 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               **)(p_Var3 + (ulonglong)bVar4 * 8 + 8);
  } while (p_Var3 != (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                      *)&_TreeSentinel);
  pWVar2 = *param_2;
  *(bool *)(param_1 + 1) = bVar4;
  if ((pWVar2 != (WDFFILEOBJECT__ *)0x0) && (*(void **)(pWVar2 + 0x18) < pvVar1)) {
    *param_2 = (WDFFILEOBJECT__ *)0x0;
  }
  return param_1;
}



===== _HeadInsertNode @ 1400084c8 =====

/* public: void __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_HeadInsertNode(struct utl::_TreeNode<struct
   utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<void * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64,bool,struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > > * __ptr64) __ptr64 */

void __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_HeadInsertNode(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                  *this,_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                        *param_1,bool param_2,
                 _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *param_3)

{
  bool bVar1;
  _TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *this_00;
  ulonglong uVar2;
  
  *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)param_3 = param_1;
  *(void ***)(param_3 + 8) = &_TreeSentinel;
  *(void ***)(param_3 + 0x10) = &_TreeSentinel;
  *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)(param_1 + (ulonglong)param_2 * 8 + 8) = param_3;
  if (*(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + ((ulonglong)param_2 ^ 1) * 8 + 8) == param_1) {
    *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      **)(this + ((ulonglong)param_2 ^ 1) * 8 + 8) = param_3;
  }
  while( true ) {
    if ((*(ulonglong *)param_1 & 1) != 0) {
      return;
    }
    this_00 = (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               *)(*(ulonglong *)param_1 & 0xfffffffffffffffe);
    bVar1 = *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              **)(this_00 + 0x10) !=
            (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             *)param_1;
    uVar2 = (ulonglong)bVar1;
    if ((**(byte **)(this_00 + uVar2 * 8 + 8) & 1) != 0) break;
    **(ulonglong **)(this_00 + 8) = **(ulonglong **)(this_00 + 8) | 1;
    **(ulonglong **)(this_00 + 0x10) = **(ulonglong **)(this_00 + 0x10) | 1;
    param_1 = (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               *)(*(ulonglong *)this_00 & 0xfffffffffffffffe);
    if (this == (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)param_1) {
      return;
    }
    *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      **)this_00 = param_1;
  }
  if ((**(byte **)(param_1 + uVar2 * 8 + 8) & 1) == 0) {
    _NodeRotateNonRoot((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                        *)param_1,
                       *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                         **)(this_00 + 0x10) ==
                       (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                        *)param_1,false,false);
  }
  _NodeRotate(this_00,bVar1,false,true);
  return;
}



===== _NodeRotate @ 140008588 =====

/* private: struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64 __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_NodeRotate(bool,bool,bool) __ptr64 */

_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
* __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_NodeRotate(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
              *this,bool param_1,bool param_2,bool param_3)

{
  ulonglong uVar1;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var2;
  ulonglong *puVar3;
  _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var4;
  
  uVar1 = *(ulonglong *)this;
  p_Var2 = *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             **)(this + ((ulonglong)param_1 ^ 1) * 8 + 8);
  p_Var4 = p_Var2 + (ulonglong)param_1 * 8;
  puVar3 = *(ulonglong **)(p_Var4 + 8);
  *(ulonglong *)p_Var2 = (ulonglong)param_3 | uVar1 & 0xfffffffffffffffe;
  _ReplaceChild((_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)(uVar1 & 0xfffffffffffffffe),
                (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                 *)this,p_Var2);
  *(ulonglong *)this = (ulonglong)param_2 | (ulonglong)p_Var2;
  *puVar3 = (ulonglong)((uint)*puVar3 & 1) | (ulonglong)this;
  *(ulonglong **)(this + ((ulonglong)param_1 ^ 1) * 8 + 8) = puVar3;
  *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)(p_Var4 + 8) = this;
  return (_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
          *)p_Var2;
}



===== _NodeRotateNonRoot @ 140008608 =====

/* private: struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class
   wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<void *
   __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > * __ptr64 __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_NodeRotateNonRoot(bool,bool,bool) __ptr64 */

_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
* __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_NodeRotateNonRoot
          (_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
           *this,bool param_1,bool param_2,bool param_3)

{
  _TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
  *p_Var1;
  ulonglong *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar4 = (ulonglong)param_1;
  uVar5 = *(ulonglong *)this & 0xfffffffffffffffe;
  p_Var1 = *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
             **)(this + ((ulonglong)param_1 ^ 1) * 8 + 8);
  puVar2 = *(ulonglong **)(p_Var1 + uVar4 * 8 + 8);
  *(ulonglong *)p_Var1 = param_3 | uVar5;
  lVar3 = 8;
  if (*(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(uVar5 + 0x10) == this) {
    lVar3 = 0x10;
  }
  *(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)(lVar3 + uVar5) = p_Var1;
  *(ulonglong *)this = (ulonglong)param_2 | (ulonglong)p_Var1;
  *puVar2 = (ulonglong)((uint)*puVar2 & 1) | (ulonglong)this;
  *(ulonglong **)(this + (uVar4 ^ 1) * 8 + 8) = puVar2;
  *(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)(p_Var1 + uVar4 * 8 + 8) = this;
  return p_Var1;
}



===== _ReplaceChild @ 140008694 =====

/* private: void __cdecl utl::_TreeNodeHeader<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > >::_ReplaceChild(struct utl::_TreeNode<struct
   utl::pair<struct WDFFILEOBJECT__ * __ptr64 const,class wil::unique_any_t<class
   wil::details::unique_storage<struct wil::details::resource_policy<void * __ptr64,void
   (__cdecl*)(void * __ptr64),&void __cdecl WdfObjectDelete(void * __ptr64),struct
   wistd::integral_constant<unsigned __int64,0>,void * __ptr64,void * __ptr64,0,std::nullptr_t> > >
   > > const * __ptr64,struct utl::_TreeNode<struct utl::pair<struct WDFFILEOBJECT__ * __ptr64
   const,class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<void * __ptr64,void (__cdecl*)(void * __ptr64),&void __cdecl
   WdfObjectDelete(void * __ptr64),struct wistd::integral_constant<unsigned __int64,0>,void *
   __ptr64,void * __ptr64,0,std::nullptr_t> > > > > * __ptr64) __ptr64 */

void __thiscall
utl::
_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
::_ReplaceChild(_TreeNodeHeader<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                *this,_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
                      *param_1,
               _TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
               *param_2)

{
  longlong lVar1;
  
  if ((_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
       *)(*(ulonglong *)this & 0xfffffffffffffffe) == param_1) {
    *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
      **)this = param_2;
    return;
  }
  lVar1 = 8;
  if (*(_TreeNode<utl::pair<WDFFILEOBJECT__*___ptr64_const,wil::unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
        **)(this + 0x10) == param_1) {
    lVar1 = 0x10;
  }
  *(_TreeNode<struct_utl::pair<struct_WDFFILEOBJECT__*___ptr64_const,class_wil::unique_any_t<class_wil::details::unique_storage<struct_wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),struct_wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>_>_>
    **)(this + lVar1) = param_2;
  return;
}



===== _SetCapacity @ 1400086c4 =====

/* private: bool __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::_SetCapacity(unsigned __int64) __ptr64 */

bool __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::_SetCapacity(vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
               *this,__uint64 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  bool bVar6;
  longlong local_28;
  longlong lStack_20;
  undefined8 local_18;
  
  vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
            ((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
              *)&local_28,
             (allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_> *)param_1,param_1)
  ;
  lVar3 = local_28;
  if (local_28 == -1) {
    bVar6 = false;
  }
  else {
    bVar5 = _RangeTransferAppc<utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
                      ();
    bVar6 = false;
    if (bVar5) {
      lVar1 = *(longlong *)(this + 8);
      lVar2 = *(longlong *)this;
      _Uninit(this);
      uVar4 = local_18;
      local_18 = 0xffffffffffffffff;
      *(ulonglong *)(this + 8) = lStack_20 + (lVar1 - lVar2 & 0xfffffffffffffff0U);
      bVar6 = true;
      *(undefined8 *)(this + 0x10) = uVar4;
      local_28 = -1;
      lStack_20 = -1;
      *(longlong *)this = lVar3;
    }
  }
  _Uninit((vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
           *)&local_28);
  return bVar6;
}



===== _Uninit @ 140008778 =====

/* private: void __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::_Uninit(void) __ptr64 */

void __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::_Uninit(vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
          *this)

{
  unique_wdf_object_reference<WDFREQUEST__*___ptr64> *puVar1;
  
  puVar1 = *(unique_wdf_object_reference<WDFREQUEST__*___ptr64> **)this;
  if (puVar1 != (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *)0xffffffffffffffff) {
    _EraseTail(this,puVar1);
    operator_delete(*(void **)this,(nothrow_t *)puVar1);
  }
  return;
}



===== reserve @ 1400087a4 =====

/* public: bool __cdecl utl::vector<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>,class utl::allocator<class wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64> > >::reserve(unsigned __int64) __ptr64 */

bool __thiscall
utl::
vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
::reserve(vector<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>,utl::allocator<wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>_>_>
          *this,__uint64 param_1)

{
  bool bVar1;
  ulonglong uVar2;
  
  uVar2 = *(longlong *)(this + 0x10) - *(longlong *)this >> 4;
  if (uVar2 < param_1) {
    uVar2 = (uVar2 >> 2) * 7 + 8;
    if (uVar2 < param_1) {
      uVar2 = param_1;
    }
    if (0x7ffffffffffffff < uVar2) {
      uVar2 = 0x7ffffffffffffff;
    }
    if (uVar2 < param_1) {
      return false;
    }
    bVar1 = _SetCapacity(this,uVar2);
    if (!bVar1) {
      return false;
    }
  }
  return true;
}



===== reset @ 140008804 =====

/* public: void __cdecl wil::details::unique_storage<struct wil::details::resource_policy<unsigned
   __int64 * __ptr64,void __cdecl(struct wil::details::kspin_lock_saved_irql const &
   __ptr64),&public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64),struct wistd::integral_constant<unsigned
   __int64,2>,struct wil::details::kspin_lock_saved_irql,unsigned __int64 *
   __ptr64,0,std::nullptr_t> >::reset(struct wil::details::kspin_lock_saved_irql) __ptr64 */

void __thiscall
wil::details::
unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
::reset(unique_storage<wil::details::resource_policy<unsigned___int64*___ptr64,void___cdecl(wil::details::kspin_lock_saved_irql_const&___ptr64),&public:_static_void___cdecl_wil::details::kspin_lock_saved_irql::Release(struct_wil::details::kspin_lock_saved_irql_const&___ptr64),wistd::integral_constant<unsigned___int64,2>,wil::details::kspin_lock_saved_irql,unsigned___int64*___ptr64,0,std::nullptr_t>_>
        *this,undefined8 *param_2)

{
  undefined8 uVar1;
  code *local_res8;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (*(longlong *)this != 0) {
    local_18 = *(undefined8 *)this;
    uStack_10 = *(undefined8 *)(this + 8);
    local_res8 = kspin_lock_saved_irql::Release;
    wistd::
    invoke<void_(__cdecl*)(wil::details::kspin_lock_saved_irql_const&___ptr64),wil::details::kspin_lock_saved_irql&___ptr64>
              ((void____cdecl______ptr64__wil__details__kspin_lock_saved_irql_const____ptr64_ *)
               &local_res8,(kspin_lock_saved_irql *)&local_18);
  }
  uVar1 = param_2[1];
  *(undefined8 *)this = *param_2;
  *(undefined8 *)(this + 8) = uVar1;
  return;
}



===== reset @ 140008858 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl wil::unique_wdf_object_reference<struct WDFREQUEST__ *
   __ptr64>::reset(struct WDFREQUEST__ * __ptr64,void * __ptr64) __ptr64 */

void __thiscall
wil::unique_wdf_object_reference<WDFREQUEST__*___ptr64>::reset
          (unique_wdf_object_reference<WDFREQUEST__*___ptr64> *this,WDFREQUEST__ *param_1,
          void *param_2)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)this,*(undefined8 *)(this + 8),0x1977,
               "onecore\\internal\\sdk\\inc\\wil\\opensource/wil/resource.h");
  }
  *(WDFREQUEST__ **)this = param_1;
  *(void **)(this + 8) = param_2;
  return;
}



===== Feature_3736307001__private_IsEnabledDeviceUsageNoInline @ 1400088d0 =====

ulonglong Feature_3736307001__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3736307001__private_featureState;
  if ((Feature_3736307001__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3736307001__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3736307001__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3736307001__private_IsEnabledFallback @ 140008908 =====

void Feature_3736307001__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3736307001__private_descriptor);
  return;
}



===== Feature_53100197__private_IsEnabledDeviceUsageNoInline @ 140008924 =====

ulonglong Feature_53100197__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_53100197__private_featureState;
  if ((Feature_53100197__private_featureState & 0x10) == 0) {
    uVar1 = Feature_53100197__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_53100197__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_53100197__private_IsEnabledFallback @ 14000895c =====

void Feature_53100197__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF__guid_D @ 140008978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF__guid_D
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,0x6d);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,3,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,0x6d);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 140008a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,&param_9,8,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,
                    &param_9,8,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140008b2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,&param_9,8,
               &param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,3,&WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,param_7,&param_9,8,
                    &param_10,8,0);
  }
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140008bfc =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar4 = uVar1 >> 0xf & 0x7f;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        uVar4 = 5;
        if (param_2 != 1) {
          uVar4 = 1;
        }
        uVar2 = uVar1 & 0xffc07fff | 1;
        param_4[2] = uVar4;
      }
      uVar4 = 0;
      if (param_2 == 5) {
        uVar4 = 0x400000;
      }
      uVar2 = uVar4 | uVar2 & 0xffbfffff;
    }
    uVar3 = uVar2 >> 0xf & 0x7f;
    uVar4 = uVar3 + 1;
    if ((0x7f < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 0xf ^ uVar2) & 0x3f8000;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140008ce0 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar1 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar2 = uVar1 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar2 = uVar4 | uVar2 & 0xffffbfff;
    }
    uVar3 = uVar2 >> 5 & 0x1ff;
    uVar4 = uVar3 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 5 ^ uVar2) & 0x3fe0;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140008dd0 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140008f2c:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140008f1c:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140008f2c;
      if (uVar5 == 5) goto LAB_140008f1c;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140008f54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008fd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400090c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400091d8 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 14000923c =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 14000939c =====

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



===== wil_details_MapReportingKind @ 140009430 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== GetImageTuple @ 1400094d0 =====

/* WARNING: Removing unreachable block (ram,0x000140009506) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0x8235a053;
  *param_3 = 0x1f000;
  return 1;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 140009520 =====

ulonglong InitializeTelemetryAssertsKMByDriverObject(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_48,0);
    uVar3 = IoQueryFullDriverPath(param_1,&local_48);
    if (-1 < (int)uVar3) {
      uVar2 = RtlUnicodeStringToAnsiString(&local_38,&local_48,1);
      uVar3 = (ulonglong)uVar2;
      ExFreePoolWithTag(uStack_40,0);
      if (-1 < (int)uVar2) {
        uVar2 = (uint)(ushort)local_38;
        do {
          uVar1 = uVar2;
          uVar2 = uVar1 - 1;
          if (uVar2 == 0) goto LAB_140009601;
        } while (*(char *)((ulonglong)uVar2 + lStack_30) != '\\');
        if (uVar2 != (ushort)local_38) {
          local_28 = 0;
          uStack_20 = 0;
          RtlInitAnsiString(&local_28,(ulonglong)uVar1 + lStack_30);
          local_18 = local_28;
          uStack_10 = uStack_20;
          uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
          uVar3 = uVar3 & 0xffffffff;
        }
LAB_140009601:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140009628 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_14000f558 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140013040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140013008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140013078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredMsgKM @ 1400096dc =====

void MicrosoftTelemetryAssertTriggeredMsgKM(undefined8 param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  undefined4 in_stack_ffffffffffffffec;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,0,0,0xffffffff,CONCAT44(in_stack_ffffffffffffffec,0xffffffff),param_1);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 14000970c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  char *pcVar12;
  longlong *plVar13;
  uint uVar14;
  undefined1 *puVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  longlong lVar18;
  char *pcVar19;
  undefined1 auStack_168 [8];
  undefined1 auStack_160 [112];
  undefined8 local_f0;
  undefined1 local_e8 [32];
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  longlong local_88 [2];
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar15 = auStack_168;
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  local_f0 = param_6;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_140009c26;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar15 = auStack_168;
  for (plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar9 == param_1) goto LAB_14000984a;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar18 = _DAT_fffff78000000320;
  puVar15 = auStack_168;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar15 = auStack_168;
    *(undefined4 *)(plVar9 + 2) = 0;
    *(undefined4 *)((longlong)plVar9 + 0x14) = 0;
    *(undefined4 *)(plVar9 + 3) = 0;
    plVar9[1] = (longlong)((ulonglong)uVar6 * lVar18) / 10000 + -0xea61;
    plVar10 = plVar9 + 4;
    plVar13 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar13 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar1)();
      puVar15 = auStack_160;
    }
    *plVar10 = (longlong)plVar13;
    plVar10[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar13[1] = (longlong)plVar10;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
LAB_14000984a:
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
    lVar2 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar15 + -8) = 0x14000985a;
    uVar6 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar15 + 0x54) = 0;
    *(undefined4 *)(puVar15 + 0x50) = 0;
    lVar18 = (longlong)((ulonglong)uVar6 * lVar2) / 10000;
    if (60000 < (ulonglong)(lVar18 - plVar9[1])) {
      *(undefined8 *)(puVar15 + -8) = 0x1400098a8;
      uVar11 = GetImageTuple((ulonglong)uVar6 * lVar2,(dword *)(puVar15 + 0x54),
                             (dword *)(puVar15 + 0x50));
      uVar6 = *(uint *)(puVar15 + 0x50);
      iVar7 = (int)uVar11;
      if ((((iVar7 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar6) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar6) < param_1)) {
        uVar14 = 0;
      }
      else {
        uVar14 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar15 + 0x50) = (int)plVar9[2];
      plVar9[1] = lVar18;
      lVar18 = plVar9[3];
      *(undefined4 *)(puVar15 + 0x74) = *(undefined4 *)((longlong)plVar9 + 0x14);
      *(undefined8 *)(puVar15 + -8) = 0x1400098fc;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
      if (5 < DAT_140013040) {
        *(undefined8 *)(puVar15 + -8) = 0x14000992b;
        cVar4 = _tlgKeywordOn(0x140013040,0x400000000000);
        uVar11 = 0;
        if (cVar4 != '\0') {
          local_c8 = puVar15 + 0x58;
          *(undefined4 *)(puVar15 + 0x58) = 10;
          local_b8 = puVar15 + 0x5c;
          local_c0 = 4;
          *(uint *)(puVar15 + 0x5c) = uVar14;
          local_a8 = puVar15 + 0x60;
          local_b0 = 4;
          *(uint *)(puVar15 + 0x60) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x54);
          local_98 = puVar15 + 100;
          local_a0 = 4;
          *(uint *)(puVar15 + 100) = -(uint)(iVar7 != 0) & uVar6;
          local_90 = 4;
          pcVar12 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar12 = g_ModuleName;
          }
          *(undefined8 *)(puVar15 + -8) = 0x1400099bd;
          _tlgCreate1Sz_char(local_88,pcVar12);
          local_78 = puVar15 + 0x68;
          *(undefined4 *)(puVar15 + 0x6c) = *(undefined4 *)(puVar15 + 0x74);
          local_68 = puVar15 + 0x6c;
          *(undefined4 *)(puVar15 + 0x68) = *(undefined4 *)(puVar15 + 0x50);
          local_70 = 4;
          local_60 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x1400099f6;
          bVar5 = KeGetCurrentIrql();
          *(uint *)(puVar15 + 0x70) = (uint)bVar5;
          local_58 = puVar15 + 0x70;
          pcVar12 = *(char **)(puVar15 + 0x78);
          local_50 = 4;
          if (pcVar12 == (char *)0x0) {
            pcVar12 = "<unknown>";
          }
          *(undefined8 *)(puVar15 + -8) = 0x140009a2e;
          _tlgCreate1Sz_char(local_48,pcVar12);
          *(undefined1 **)(puVar15 + 0x28) = local_e8;
          *(undefined4 *)(puVar15 + 0x20) = 0xb;
          *(undefined8 *)(puVar15 + -8) = 0x140009a4b;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_e8,&DAT_14000cd61,uVar11,param_4,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if ((DAT_140013078 == 0) || ((int)lVar18 != 0)) goto LAB_140009c26;
      *(undefined8 *)(puVar15 + -8) = 0x140009a6a;
      cVar4 = KeGetCurrentIrql();
      if (cVar4 != '\0') goto LAB_140009c26;
      *(undefined4 *)(puVar15 + 0x40) = 0;
      *(undefined8 *)(puVar15 + 0x38) = 0;
      *(undefined8 *)(puVar15 + 0x30) = 0;
      *(ulonglong *)(puVar15 + 0x28) = (ulonglong)uVar6;
      *(ulonglong *)(puVar15 + 0x20) = (ulonglong)*(uint *)(puVar15 + 0x54);
      uVar16 = (ulonglong)uVar14;
      *(undefined8 *)(puVar15 + -8) = 0x140009ab2;
      pcVar12 = g_ModuleName;
      iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_140013040) {
        *(undefined8 *)(puVar15 + -8) = 0x140009adc;
        cVar4 = _tlgKeywordOn(0x140013040,0x400000000000);
        if (cVar4 != '\0') {
          local_c8 = puVar15 + 0x70;
          local_c0 = 4;
          uVar17 = 10;
          local_b8 = puVar15 + 0x6c;
          *(undefined4 *)(puVar15 + 0x70) = 10;
          *(uint *)(puVar15 + 0x6c) = uVar14;
          local_a8 = puVar15 + 0x68;
          local_b0 = 4;
          *(uint *)(puVar15 + 0x68) = -(uint)(iVar7 != 0) & *(uint *)(puVar15 + 0x54);
          plVar10 = local_88;
          local_a0 = 4;
          local_90 = 4;
          *(uint *)(puVar15 + 100) = -(uint)(iVar7 != 0) & uVar6;
          local_98 = puVar15 + 100;
          pcVar19 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar19 = g_ModuleName;
          }
          *(undefined8 *)(puVar15 + -8) = 0x140009b6c;
          _tlgCreate1Sz_char(plVar10,pcVar19);
          *(undefined4 *)(puVar15 + 0x60) = *(undefined4 *)(puVar15 + 0x50);
          local_78 = puVar15 + 0x60;
          *(undefined4 *)(puVar15 + 0x5c) = *(undefined4 *)(puVar15 + 0x74);
          local_68 = puVar15 + 0x5c;
          local_58 = puVar15 + 0x58;
          *(undefined1 **)(puVar15 + 0x28) = local_e8;
          *(undefined4 *)(puVar15 + 0x20) = uVar17;
          local_70 = 4;
          local_60 = 4;
          *(int *)(puVar15 + 0x58) = iVar8;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x140009bcd;
          _tlgWriteTransfer_EtwWriteTransfer
                    (plVar10,&DAT_14000cdce,uVar16,pcVar12,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if (iVar8 != 0) goto LAB_140009c26;
      *(undefined8 *)(puVar15 + -8) = 0x140009bdf;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar10[-4] == param_1) {
            *(int *)(plVar10 + -1) = (int)plVar10[-1] + 1;
            break;
          }
          plVar10 = (longlong *)*plVar10;
        } while ((longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x140009c21;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_140009c26:
  *(undefined8 *)(puVar15 + -8) = 0x140009c32;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140009c58 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140009ceb;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140009d08;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140013098;
    DAT_140013098 = 0;
    DAT_140013078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140009d32;
    EtwUnregister(uVar3);
    uVar3 = DAT_140013028;
    DAT_140013028 = 0;
    _DAT_140013008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140009d54;
    EtwUnregister(uVar3);
    uVar3 = DAT_140013060;
    DAT_140013060 = 0;
    DAT_140013040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140009d76;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140009d90 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== __security_check_cookie @ 140009db0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140009df0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140009e20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140009e20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140009e50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140009ec0 =====

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



===== __memset_repmovs @ 14000a000 =====

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



===== __memset_query @ 14000a080 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000a100 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000a240 =====

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



===== __memset_spec_plain @ 14000a2c0 =====

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



===== memmove @ 14000a400 =====

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



===== WppCleanupKm @ 140014008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== DriverCleanup @ 1400140b8 =====

/* void __cdecl DriverCleanup(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl DriverCleanup(_DRIVER_OBJECT *param_1)

{
  UninitializeTelemetryAssertsKM();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm(param_1);
  return;
}



===== EvtObjectContextCleanup @ 140014124 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::EvtObjectContextCleanup(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::EvtObjectContextCleanup
          (AvrcpTransportDriver *this)

{
  _DRIVER_OBJECT *p_Var1;
  
  p_Var1 = (_DRIVER_OBJECT *)
           (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*(undefined8 *)this);
  DriverCleanup(p_Var1);
  return;
}



===== WppTraceCallback @ 140014160 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400143e8 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_140014445;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140014445;
    }
  }
  uVar1 = 0x206;
LAB_140014445:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140014450 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140014508 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140014540 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400145c2;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400145c2;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_1400145c2:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140014610 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 140014664 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140014680 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001469c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== EvtDeviceFileCreate @ 140014750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceFileCreate(struct
   WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceFileCreate
          (WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,WDFFILEOBJECT__ *param_3)

{
  char cVar1;
  AvrcpTransportDevice *this;
  undefined4 *puVar2;
  undefined *puVar3;
  char cVar4;
  undefined4 uVar5;
  
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') ||
     (puVar3 = WPP_GLOBAL_Control,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_RECORDER_AND_TRACE_SF_
              (puVar3,cVar1,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x93,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  cVar1 = IsCallingProcess((ulonglong)puVar3,cVar1);
  if (cVar1 == '\0') {
    uVar5 = 0xc0000022;
  }
  else {
    uVar5 = 0;
    this = (AvrcpTransportDevice *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
    puVar2 = (undefined4 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_3,PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14000f080);
    *puVar2 = 1;
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
    if (*(longlong *)(this + 8) == 1) {
      OnWin32ServiceReady(this,true);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar5);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  if ((cVar1 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x94,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== EvtDeviceQueryRemove @ 140014920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceQueryRemove(struct
   WDFDEVICE__ * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceQueryRemove
          (WDFDEVICE__ *param_1)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  AvrcpTransportDevice *this;
  char cVar4;
  char cVar5;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x87,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  this = (AvrcpTransportDevice *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  lVar3 = OnDeviceQueryRemove(this);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar2)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    bVar1 = false;
  }
  if ((cVar4 != '\0') || (bVar1)) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x88,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar3);
  }
  return lVar3;
}



===== EvtDeviceSelfManagedIoFlush @ 140014a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceSelfManagedIoFlush(struct
   WDFDEVICE__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceSelfManagedIoFlush
          (WDFDEVICE__ *param_1)

{
  AvrcpTransportDevice *this;
  
  this = (AvrcpTransportDevice *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  OnDeviceSelfManagedIoFlush(this);
  return;
}



===== EvtFileCleanup @ 140014ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtFileCleanup(struct
   WDFFILEOBJECT__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtFileCleanup
          (WDFFILEOBJECT__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  AvrcpTransportDeviceService *pAVar3;
  char cVar4;
  char cVar5;
  
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x8f,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  if (*(longlong *)(lVar2 + 0x888) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar2 + 0x888),
                        PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
    AvrcpTransportDeviceService::OnFileCleanup(pAVar3,param_1);
  }
  if (*(longlong *)(lVar2 + 0x890) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar2 + 0x890),
                        PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
    AvrcpTransportDeviceService::OnFileCleanup(pAVar3,param_1);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x90,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== EvtIoStop @ 140014c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtIoStop(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned long) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtIoStop
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,ulong param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x99,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    bVar1 = false;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x9a,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== OnDeviceQueryRemove @ 140014dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceQueryRemove(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceQueryRemove
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDeviceService *pAVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  if ((cVar4 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x79,
               in_stack_ffffffffffffffd0,(char)this);
  }
  lVar2 = 0;
  if (*(longlong *)(this + 0x890) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(this + 0x890),
                        PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
    lVar2 = AvrcpTransportDeviceService::OnDeviceQueryRemove(pAVar3);
    if (lVar2 < 0) goto LAB_140014ec7;
  }
  if (*(longlong *)(this + 0x888) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(this + 0x888),
                        PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
    lVar2 = AvrcpTransportDeviceService::OnDeviceQueryRemove(pAVar3);
  }
LAB_140014ec7:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) ||
     (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (cVar4 = '\x01', !bVar1)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffc0,0x7a,
               in_stack_ffffffffffffffd0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== OnDeviceQueryRemove @ 140014f50 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnDeviceQueryRemove(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnDeviceQueryRemove
          (AvrcpTransportDeviceService *this)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x15,
               in_stack_ffffffffffffffe0,(char)this);
  }
  wil::details::kernel_event_t<0>::wait_for_single_object
            ((kernel_event_t<0> *)(this + 0x50),(_LARGE_INTEGER *)0x0);
  StartDisconnect(this);
  wil::details::kernel_event_t<0>::wait_for_single_object
            ((kernel_event_t<0> *)(this + 0x50),(_LARGE_INTEGER *)0x0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    bVar1 = false;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x16,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return 0;
}



===== OnDeviceSelfManagedIoFlush @ 14001507c =====

/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceSelfManagedIoFlush(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceSelfManagedIoFlush
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x7d,
               in_stack_ffffffffffffffe0,(char)this);
  }
  IndicationReferenceCounter::WaitForZero((IndicationReferenceCounter *)(this + 0x858));
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    bVar1 = false;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x7e,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== OnFileCleanup @ 140015184 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnFileCleanup(struct
   WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnFileCleanup
          (AvrcpTransportDeviceService *this,WDFFILEOBJECT__ *param_1)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x19,
               in_stack_ffffffffffffffe0,(char)this);
  }
  CancelSentRequestsForFileObject(this,param_1);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    bVar1 = false;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar1,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x1a,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== ProcessTestConnectRequest @ 1400152a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessTestConnectRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessTestConnectRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  bool bVar1;
  long lVar2;
  int *piVar3;
  AvrcpTransportDeviceService *this_00;
  undefined8 uVar4;
  
  *param_4 = 0;
  piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,0);
  if (*piVar3 == 1) {
    uVar4 = *(undefined8 *)(this + 0x888);
  }
  else {
    if (*piVar3 != 2) {
      return -0x3ffffff3;
    }
    bVar1 = IsBrowseChannelSupported(this);
    if (!bVar1) {
      return -0x3fffff45;
    }
    uVar4 = *(undefined8 *)(this + 0x890);
  }
  this_00 = (AvrcpTransportDeviceService *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,
                       PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
  lVar2 = AvrcpTransportDeviceService::RequestConnect(this_00);
  return lVar2;
}



===== ProcessTestDisconnectRequest @ 140015340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessTestDisconnectRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessTestDisconnectRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  bool bVar1;
  long lVar2;
  int *piVar3;
  AvrcpTransportDeviceService *this_00;
  undefined8 uVar4;
  
  *param_4 = 0;
  piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,0);
  if (*piVar3 == 1) {
    uVar4 = *(undefined8 *)(this + 0x888);
  }
  else {
    if (*piVar3 != 2) {
      return -0x3ffffff3;
    }
    bVar1 = IsBrowseChannelSupported(this);
    if (!bVar1) {
      return -0x3fffff45;
    }
    uVar4 = *(undefined8 *)(this + 0x890);
  }
  this_00 = (AvrcpTransportDeviceService *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar4,
                       PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
  lVar2 = AvrcpTransportDeviceService::RequestDisconnect(this_00);
  return lVar2;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1400153e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1400154ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001550f;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14001552f;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x140015543;
  return iVar6;
}



===== _tlgEnableCallback @ 140015560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== EvtDeviceIoControl @ 1400155e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceIoControl(struct
   WDFQUEUE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned
   long) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceIoControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  char cVar8;
  WDFIOTARGET__ *pWVar9;
  undefined8 local_res20;
  undefined8 local_38;
  undefined8 local_30;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x95,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  pWVar9 = *(WDFIOTARGET__ **)(WdfFunctions_01015 + 0x650);
  lVar3 = (*(code *)pWVar9)(WdfDriverGlobals,uVar2,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0
                           );
  local_38 = 0;
  local_res20 = 0;
  if (param_4 == 0) {
LAB_1400156f9:
    if (param_3 != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals,param_2,&local_res20);
      if (iVar1 < 0) goto LAB_1400157bf;
    }
    lVar6 = 0;
    for (uVar4 = 0; uVar4 < 0x118; uVar4 = uVar4 + 0x28) {
      if (param_5 == *(ulong *)((longlong)&DAT_14000c000 + uVar4)) {
        if ((param_4 < *(ulonglong *)(&UNK_14000c008 + lVar6 * 0x28)) ||
           (param_3 < *(ulonglong *)(&UNK_14000c010 + lVar6 * 0x28))) {
          iVar1 = -0x3ffffdfa;
        }
        else {
          lVar7 = 0;
          if (lVar3 != -8) {
            lVar7 = lVar3;
          }
          local_30 = 0;
          iVar1 = (**(code **)(&UNK_14000c018 + lVar6 * 0x28))
                            (*(int *)(&UNK_14000c020 + lVar6 * 0x28) + lVar7,param_2,local_38,
                             local_res20,&local_30);
          if ((-1 < iVar1) && (iVar1 != 0x103)) {
            (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar1,local_30);
          }
        }
        if (iVar1 < 0) goto LAB_1400157bf;
        goto LAB_1400157df;
      }
      lVar6 = lVar6 + 1;
    }
    WdfCpp::
    ObjectDispatchHandler<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice>::
    ForwardRequest((ObjectDispatchHandler<Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice>
                    *)(ulonglong)param_5,param_1,param_2,pWVar9);
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_38);
    if (-1 < iVar1) goto LAB_1400156f9;
LAB_1400157bf:
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals);
  }
LAB_1400157df:
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar8 = '\0';
  }
  else {
    cVar8 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar8 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar8,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x96,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== ProcessWriteChannelDataRequest @ 140015940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400159a7) */
/* WARNING: Removing unreachable block (ram,0x000140015a65) */
/* WARNING: Removing unreachable block (ram,0x000140015a6a) */
/* WARNING: Removing unreachable block (ram,0x000140015a74) */
/* WARNING: Removing unreachable block (ram,0x000140015a8c) */
/* WARNING: Removing unreachable block (ram,0x000140015a80) */
/* WARNING: Removing unreachable block (ram,0x0001400159b2) */
/* WARNING: Removing unreachable block (ram,0x0001400159b9) */
/* WARNING: Removing unreachable block (ram,0x000140015a39) */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessWriteChannelDataRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessWriteChannelDataRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  *param_4 = 0;
  (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x83,
               in_stack_ffffffffffffffe0,(char)this,6);
  }
  return -0x3ffffdfa;
}



===== WriteAclData @ 140015ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::WriteAclData(struct
   WDFREQUEST__ * __ptr64,void * __ptr64,unsigned __int64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::WriteAclData
          (AvrcpTransportDeviceService *this,WDFREQUEST__ *param_1,void *param_2,__uint64 param_3)

{
  bool bVar1;
  long lVar2;
  _BRB *p_Var3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  void *local_38 [2];
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x1d,
               in_stack_ffffffffffffffb0,(char)this);
  }
  local_38[0] = (void *)0x0;
  lVar2 = GetChannelHandle(this,local_38);
  if (-1 < lVar2) {
    p_Var3 = (_BRB *)(**(code **)(this + 0x138))(0x105);
    if (p_Var3 == (_BRB *)0x0) {
      lVar2 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(p_Var3 + 0x70) = *(undefined8 *)(this + 0x10);
      *(void **)(p_Var3 + 0x78) = local_38[0];
      *(undefined4 *)(p_Var3 + 0x80) = 0;
      *(void **)(p_Var3 + 0x88) = param_2;
      *(int *)(p_Var3 + 0x84) = (int)param_3;
      lVar2 = SubmitClientBrbAsync(this,p_Var3,param_1);
      if (lVar2 < 0) {
        (**(code **)(this + 0x140))(p_Var3);
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x1e,
               in_stack_ffffffffffffffb0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== ProcessReadChannelDataRequest @ 140015d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelDataRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelDataRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  bool bVar1;
  long lVar2;
  int *piVar3;
  void *pvVar4;
  AvrcpTransportDeviceService *this_00;
  char cVar5;
  undefined8 uVar6;
  char cVar7;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x81,
               in_stack_ffffffffffffffc0,(char)this);
  }
  *param_4 = 0;
  piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,0);
  pvVar4 = (void *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_3);
  if (*piVar3 == 1) {
    uVar6 = *(undefined8 *)(this + 0x888);
  }
  else {
    if (*piVar3 != 2) {
      lVar2 = -0x3ffffff3;
      goto LAB_140015e0e;
    }
    if ((*(ushort *)(this + 0x10) < 0x104) || (((byte)this[0x12] & 0x40) == 0)) {
      lVar2 = -0x3fffff45;
      goto LAB_140015e0e;
    }
    uVar6 = *(undefined8 *)(this + 0x890);
  }
  this_00 = (AvrcpTransportDeviceService *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar6,
                       PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
  lVar2 = AvrcpTransportDeviceService::ReadAclData(this_00,param_1,pvVar4,0);
LAB_140015e0e:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x82,
               in_stack_ffffffffffffffc0,(char)this,(char)lVar2);
  }
  if (-1 < lVar2) {
    lVar2 = 0x103;
  }
  return lVar2;
}



===== ReadAclData @ 140015f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ReadAclData(struct
   WDFREQUEST__ * __ptr64,void * __ptr64,unsigned __int64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::ReadAclData
          (AvrcpTransportDeviceService *this,WDFREQUEST__ *param_1,void *param_2,__uint64 param_3)

{
  bool bVar1;
  long lVar2;
  _BRB *p_Var3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  void *local_38 [2];
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x1b,
               in_stack_ffffffffffffffb0,(char)this);
  }
  local_38[0] = (void *)0x0;
  lVar2 = GetChannelHandle(this,local_38);
  if (-1 < lVar2) {
    p_Var3 = (_BRB *)(**(code **)(this + 0x138))(0x105);
    if (p_Var3 == (_BRB *)0x0) {
      lVar2 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(p_Var3 + 0x70) = *(undefined8 *)(this + 0x10);
      *(void **)(p_Var3 + 0x78) = local_38[0];
      *(undefined4 *)(p_Var3 + 0x80) = 3;
      *(void **)(p_Var3 + 0x88) = param_2;
      *(int *)(p_Var3 + 0x84) = (int)param_3;
      lVar2 = SubmitClientBrbAsync(this,p_Var3,param_1);
      if (lVar2 < 0) {
        (**(code **)(this + 0x140))(p_Var3);
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffa0,0x1c,
               in_stack_ffffffffffffffb0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== EvtDeviceD0Entry @ 140016170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceD0Entry(struct
   WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceD0Entry
          (WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDevice *this;
  char cVar3;
  char cVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x8b,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  this = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar2 = Start(this);
  if (lVar2 < 0) {
    if (lVar2 == -0x3ffff8e8) {
      lVar2 = 0;
    }
  }
  else {
    lVar2 = MakeAndInitializeDeviceInterface(this);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x8c,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== MakeAndInitializeDeviceInterface @ 140016340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::MakeAndInitializeDeviceInterface(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::MakeAndInitializeDeviceInterface
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x59,
               in_stack_ffffffffffffffe0,(char)this);
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                    (WdfDriverGlobals,*(undefined8 *)this,&GUID_BLUETOOTH_AVRCP_TRANSPORT_INTERFACE,
                     0);
  if (-1 < iVar2) {
    iVar2 = UpdateInterfaceProperties(this);
    if (-1 < iVar2) {
      (**(code **)(WdfFunctions_01015 + 0x270))
                (WdfDriverGlobals,*(undefined8 *)this,&GUID_BLUETOOTH_AVRCP_TRANSPORT_INTERFACE,0,1)
      ;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x5a,
               in_stack_ffffffffffffffe0,(char)this,(char)iVar2);
  }
  return iVar2;
}



===== Start @ 1400164c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Start(void) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Start
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDeviceService *pAVar3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x75,
               in_stack_ffffffffffffffe0,(char)this);
  }
  lVar2 = -0x3ffff8e8;
  if (*(longlong *)(this + 0x888) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    lVar2 = AvrcpTransportDeviceService::Start(pAVar3);
    if (-1 < lVar2) {
      bVar1 = IsBrowseChannelSupported(this);
      if (bVar1) {
        pAVar3 = (AvrcpTransportDeviceService *)
                 (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
        lVar2 = AvrcpTransportDeviceService::Start(pAVar3);
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x76,
               in_stack_ffffffffffffffe0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== UpdateInterfaceProperties @ 140016650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140016b02) */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UpdateInterfaceProperties(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UpdateInterfaceProperties
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  char cVar6;
  longlong local_res18 [2];
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 in_stack_ffffffffffffff80;
  undefined4 in_stack_ffffffffffffff84;
  undefined *in_stack_ffffffffffffff90;
  undefined8 local_58;
  undefined8 uStack_50;
  unique_ptr<unsigned_short_[0],wistd::default_delete<unsigned_short_[0]>_> *local_48;
  ushort *local_40;
  char local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
               CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),100,
               in_stack_ffffffffffffff90,(char)this);
  }
  local_res18[0] = 0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,local_res18);
  if (-1 < iVar3) {
    lVar4 = local_res18[0];
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x278))
                      (WdfDriverGlobals,*(undefined8 *)this,
                       &GUID_BLUETOOTH_AVRCP_TRANSPORT_INTERFACE,0,local_res18[0]);
    uVar8 = (undefined4)((ulonglong)lVar4 >> 0x20);
    if (-1 < iVar3) {
      local_58 = 0;
      uStack_50 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res18[0]);
      lVar4 = wil::out_param<wil::details::unique_wdf_wait_lock_storage>
                        ((unique_wdf_wait_lock_storage *)&local_48);
      lVar2 = GenerateBluetoothAddressString(*(__uint64 *)(this + 0x750),(ushort **)(lVar4 + 8));
      if (local_38 != '\0') {
        wil::
        attach_to_smart_pointer<wistd::unique_ptr<unsigned_short_[0],wistd::default_delete<unsigned_short_[0]>_>,void>
                  (local_48,local_40);
      }
      if (-1 < lVar2) {
        uVar7 = CONCAT44(uVar8,0x12);
        iVar3 = IoSetDeviceInterfacePropertyData
                          (&local_58,&DEVPKEY_Bluetooth_DeviceAddress,0,0,uVar7,0x1a,0);
        uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (iVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar5 = '\0';
          }
          else {
            cVar5 = '\x01';
          }
          if ((cVar5 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            in_stack_ffffffffffffff90 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
            WPP_RECORDER_AND_TRACE_SF_d
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x65,
                       &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar3);
          }
        }
      }
      uVar7 = CONCAT44(uVar8,5);
      iVar3 = IoSetDeviceInterfacePropertyData
                        (&local_58,&DEVPKEY_BluetoothAvrcp_RemoteTG_Version,0,0,uVar7,2,this + 0x14)
      ;
      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff90 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x66,
                     &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar3);
        }
      }
      uVar7 = CONCAT44(uVar8,5);
      iVar3 = IoSetDeviceInterfacePropertyData
                        (&local_58,&DEVPKEY_BluetoothAvrcp_RemoteTG_Features,0,0,uVar7,2,this + 0x16
                        );
      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff90 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x67,
                     &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar3);
        }
      }
      uVar7 = CONCAT44(uVar8,5);
      iVar3 = IoSetDeviceInterfacePropertyData
                        (&local_58,&DEVPKEY_BluetoothAvrcp_RemoteCT_Version,0,0,uVar7,2,this + 0x10)
      ;
      uVar8 = (undefined4)((ulonglong)uVar7 >> 0x20);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff90 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x68,
                     &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar3);
        }
      }
      in_stack_ffffffffffffff80 = 2;
      iVar3 = IoSetDeviceInterfacePropertyData
                        (&local_58,&DEVPKEY_BluetoothAvrcp_RemoteCT_Features,0,0,CONCAT44(uVar8,5),2
                         ,this + 0x12);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          in_stack_ffffffffffffff90 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
          in_stack_ffffffffffffff80 = 3;
          WPP_RECORDER_AND_TRACE_SF_d
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x69,
                     &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar3);
        }
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
               CONCAT44(in_stack_ffffffffffffff84,in_stack_ffffffffffffff80),0x6a,
               in_stack_ffffffffffffff90,(char)this,(char)iVar3);
  }
  if (local_res18[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar3;
}



===== GenerateBluetoothAddressString @ 140016be0 =====

/* long __cdecl GenerateBluetoothAddressString(unsigned __int64,unsigned short * __ptr64 * __ptr64)
    */

long __cdecl GenerateBluetoothAddressString(__uint64 param_1,ushort **param_2)

{
  bool bVar1;
  long lVar2;
  ushort *puVar3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined4 uVar6;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    uVar6 = 1;
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  puVar3 = (ushort *)ExAllocatePool2(0x100);
  if (puVar3 == (ushort *)0x0) {
    lVar2 = -0x3fffff66;
  }
  else {
    puVar3[0] = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    lVar2 = RtlStringCchPrintfW(puVar3,0xd,(ushort *)L"%02.2x%02.2x%02.2x%02.2x%02.2x%02.2x",
                                param_1 >> 0x28 & 0xff,(uint)(byte)(param_1 >> 0x20),
                                (uint)(byte)(param_1 >> 0x18),(uint)(byte)(param_1 >> 0x10),
                                CONCAT44(uVar6,(uint)(byte)(param_1 >> 8)),(uint)param_1 & 0xff);
    if (lVar2 < 0) goto LAB_140016c7e;
    *param_2 = puVar3;
  }
  puVar3 = (ushort *)0x0;
LAB_140016c7e:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xb,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  if (puVar3 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar3,0x646d4370);
  }
  return lVar2;
}



===== OnWin32ServiceReady @ 140016e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnWin32ServiceReady(bool)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnWin32ServiceReady
          (AvrcpTransportDevice *this,bool param_1)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDeviceService *pAVar3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x73,
               in_stack_ffffffffffffffe0,(char)this);
  }
  lVar2 = 0;
  if (*(longlong *)(this + 0x888) != 0) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    lVar2 = AvrcpTransportDeviceService::OnWin32ServiceReady(pAVar3,param_1);
    if (-1 < lVar2) {
      bVar1 = IsBrowseChannelSupported(this);
      if (bVar1) {
        pAVar3 = (AvrcpTransportDeviceService *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(this + 0x890));
        lVar2 = AvrcpTransportDeviceService::OnWin32ServiceReady(pAVar3,param_1);
      }
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x74,
               in_stack_ffffffffffffffe0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== OnWin32ServiceReady @ 140017050 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnWin32ServiceReady(bool)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnWin32ServiceReady
          (AvrcpTransportDeviceService *this,bool param_1)

{
  ConnectionAction CVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined2 uVar6;
  undefined8 in_stack_ffffffffffffffe0;
  undefined1 uVar7;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  uVar7 = SUB81(this,0);
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x1f,
               in_stack_ffffffffffffffe0,uVar7);
  }
  CVar1 = AutoConnectionAdvisor::AdviseWin32ServiceReady
                    ((AutoConnectionAdvisor *)(this + 0x28),param_1);
  if (CVar1 == 1) {
    lVar2 = RequestConnect(this);
    if (-1 < lVar2) goto LAB_1400170c9;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar5)) goto LAB_1400170c9;
    uVar6 = 0x20;
  }
  else {
    if (CVar1 != 2) goto LAB_1400170c9;
    lVar2 = RequestDisconnect(this);
    if (-1 < lVar2) goto LAB_1400170c9;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar5)) goto LAB_1400170c9;
    uVar6 = 0x21;
  }
  WPP_RECORDER_AND_TRACE_SF_dq
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffffd0,uVar6,
             in_stack_ffffffffffffffe0,(char)lVar2,uVar7);
LAB_1400170c9:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x22,
               in_stack_ffffffffffffffe0,uVar7,0);
  }
  return 0;
}



===== IsBrowseChannelSupported @ 1400172b0 =====

/* private: bool __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::IsBrowseChannelSupported(void)
   __ptr64 */

bool __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::IsBrowseChannelSupported
          (AvrcpTransportDevice *this)

{
  if ((*(ushort *)(this + 0x10) < 0x104) || (((byte)this[0x12] & 0x40) == 0)) {
    return false;
  }
  return true;
}



===== Start @ 1400172d0 =====

/* public: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Start(void) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Start
          (AvrcpTransportDeviceService *this)

{
  bool bVar1;
  long lVar2;
  ConnectionAction CVar3;
  long lVar4;
  ulonglong uVar5;
  char cVar6;
  char cVar7;
  code *in_stack_ffffffffffffffd0;
  AvrcpTransportDeviceService *in_stack_ffffffffffffffe0;
  undefined1 uVar8;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  uVar8 = SUB81(this,0);
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x10,
               in_stack_ffffffffffffffe0,uVar8);
  }
  lVar2 = RegisterServer(this);
  uVar5 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    if (lVar2 < 0) goto LAB_140017452;
    in_stack_ffffffffffffffe0 = this + 0x110;
    if (*(longlong *)in_stack_ffffffffffffffe0 != 0) {
      BtaMpmUnregister();
    }
    *(longlong *)in_stack_ffffffffffffffe0 = 0;
    in_stack_ffffffffffffffd0 = OnMediaStatusChanged;
    lVar2 = BtaMpmRegister(*(undefined8 *)(this + 0x10),(*(int *)(this + 0x18) == 1) + '\x02',
                           OnConnectRequested,OnMediaStatusChanged,OnMediaStatusChanged,
                           OnMediaStatusChanged,this);
  }
  if (-1 < lVar2) {
    CVar3 = AutoConnectionAdvisor::AdvisePnpDeviceReady((AutoConnectionAdvisor *)(this + 0x28),true)
    ;
    if (CVar3 == 1) {
      lVar4 = RequestConnect(this);
      if (lVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_AND_TRACE_SF_dq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                     *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_stack_ffffffffffffffd0,0x11,
                     in_stack_ffffffffffffffe0,(char)lVar4,uVar8);
        }
      }
    }
  }
LAB_140017452:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x12,
               in_stack_ffffffffffffffe0,uVar8,(char)lVar2);
  }
  return lVar2;
}



===== RegisterServer @ 1400174e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RegisterServer(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::RegisterServer
          (AvrcpTransportDeviceService *this)

{
  bool bVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  undefined8 in_stack_fffffffffffffdc0;
  undefined8 in_stack_fffffffffffffdd0;
  _BRB local_218 [112];
  undefined8 local_1a8;
  undefined2 local_1a0;
  undefined4 local_19c;
  code *local_198;
  AvrcpTransportDeviceService *local_190;
  undefined8 local_188;
  undefined8 local_180;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_fffffffffffffdc0,0x39,
               in_stack_fffffffffffffdd0,(char)this);
  }
  memset(local_218,0,0x210);
  (**(code **)(this + 0x148))(local_218,0x100);
  local_1a8 = *(undefined8 *)(this + 0x10);
  local_1a0 = 0x1b;
  if (*(int *)(this + 0x18) != 1) {
    local_1a0 = 0x17;
  }
  local_198 = ConnectionlessIndicationCallback;
  local_190 = this;
  local_188 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  local_19c = 2;
  lVar2 = SubmitBrbSync(this,local_218);
  if (-1 < lVar2) {
    *(undefined8 *)(this + 0x20) = local_180;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_fffffffffffffdc0,0x3a,
               in_stack_fffffffffffffdd0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== UnregisterServer @ 1400176b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::UnregisterServer(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::UnregisterServer
          (AvrcpTransportDeviceService *this)

{
  bool bVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  undefined8 in_stack_fffffffffffffdc0;
  undefined8 in_stack_fffffffffffffdd0;
  _BRB local_218 [112];
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined2 local_198;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_fffffffffffffdc0,0x3b,
               in_stack_fffffffffffffdd0,(char)this);
  }
  memset(local_218,0,0x210);
  (**(code **)(this + 0x148))(local_218,0x101);
  local_1a8 = *(undefined8 *)(this + 0x10);
  local_198 = 0x1b;
  if (*(int *)(this + 0x18) != 1) {
    local_198 = 0x17;
  }
  local_1a0 = *(undefined8 *)(this + 0x20);
  *(undefined8 *)(this + 0x20) = 0;
  lVar2 = SubmitBrbSync(this,local_218);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_fffffffffffffdc0,0x3c,
               in_stack_fffffffffffffdd0,(char)this,(char)lVar2);
  }
  return lVar2;
}



===== SubmitBrbSync @ 140017890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitBrbSync(struct
   _BRB * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::SubmitBrbSync
          (AvrcpTransportDeviceService *this,_BRB *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  undefined1 auStackY_98 [32];
  undefined8 in_stack_ffffffffffffff90;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 *puVar7;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x2b,
               in_stack_ffffffffffffffa0,(char)this);
  }
  local_28 = 0;
  local_30 = 0x10;
  local_2c = 2;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  puVar7 = &local_30;
  uVar6 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5f0))(WdfDriverGlobals,uVar3,0,0x410003);
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
LAB_140017a7b:
      bVar1 = true;
      goto LAB_1400179b3;
    }
  }
  else if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])
          ) goto LAB_140017a7b;
  bVar1 = false;
LAB_1400179b3:
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xff,uVar6,0x2c,puVar7,(char)this,
               (char)iVar2);
  }
  return iVar2;
}



===== InitializeDeviceInfo @ 140017ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::InitializeDeviceInfo(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::InitializeDeviceInfo
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  char cVar6;
  char cVar7;
  longlong local_res8;
  undefined8 local_res10;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar9;
  undefined8 *puVar8;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 *puVar10;
  undefined1 uVar11;
  undefined8 local_48;
  AvrcpTransportDevice *local_40;
  undefined8 local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  uVar11 = SUB81(this,0);
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x60,
               in_stack_ffffffffffffffa0,uVar11);
  }
  local_48 = 1;
  local_38 = 0x110;
  local_40 = this + 0x748;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
  puVar10 = (undefined8 *)0x0;
  puVar8 = &local_48;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,uVar4,0,0x41000b,0,puVar8,0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_dq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0x61,puVar10,(char)iVar2,uVar11
                );
    }
    goto LAB_140017d37;
  }
  if ((*(uint *)(this + 0x748) & 4) == 0) goto LAB_140017d37;
  local_res8 = 0;
  local_res10 = 0;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x138))(WdfDriverGlobals,*(undefined8 *)this);
  uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,uVar4);
  puVar10 = &local_res10;
  puVar8 = (undefined8 *)CONCAT44(uVar9,0x42415654);
  uVar9 = 0;
  iVar3 = BtaMpmBuildIndirectStringFromMessageWithSingleUTF8Arg
                    (*(undefined8 *)(lVar5 + 0x18),1,
                     L"@System32\\drivers\\Microsoft.Bluetooth.AvrcpTransport.sys",this + 0x75c,0xf8
                     ,puVar8,&local_res8);
  lVar5 = local_res8;
  if (iVar3 < 0) {
LAB_140017c56:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    if ((cVar6 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_dq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar8,0x62,puVar10,(char)iVar3,uVar11
                );
    }
  }
  else {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,*(undefined8 *)this);
    puVar8 = (undefined8 *)CONCAT44((int)((ulonglong)puVar8 >> 0x20),(int)local_res10 + 2);
    iVar3 = IoSetDevicePropertyData
                      (uVar4,&DEVPKEY_Device_FriendlyName,0,0,CONCAT44(uVar9,0x19),puVar8,lVar5);
    if (iVar3 < 0) goto LAB_140017c56;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag();
  }
LAB_140017d37:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  if ((cVar6 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,99,puVar10,uVar11,(char)iVar2);
  }
  return iVar2;
}



===== ProcessReadQueueConfigRequest @ 140017eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadQueueConfigRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadQueueConfigRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  long lVar1;
  BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG *pBVar2;
  WDFFILEOBJECT__ *pWVar3;
  
  *param_4 = 0;
  pBVar2 = (BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG *)
           (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,0);
  param_4 = (__uint64 *)0x0;
  lVar1 = AvrcpTransportDeviceReadQueue::MakeAndInitialize(*(WDFDEVICE__ **)this,pBVar2,&param_4);
  if (-1 < lVar1) {
    pWVar3 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
    lVar1 = RegisterReadQueue(this,pWVar3,
                              (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>_>
                               *)&param_4);
    if (-1 < lVar1) {
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x898));
      if (-1 < lVar1) {
        lVar1 = 0x103;
      }
    }
  }
  if (param_4 != (__uint64 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return lVar1;
}



===== MakeAndInitialize @ 140017fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400181bd) */
/* public: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::MakeAndInitialize(struct
   WDFDEVICE__ * __ptr64,struct BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG const & __ptr64,void *
   __ptr64 * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::MakeAndInitialize
          (WDFDEVICE__ *param_1,BLUETOOTH_AVRCP_TRANSPORT_EVENT_QUEUE_CONFIG *param_2,void **param_3
          )

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDeviceReadQueue *pAVar3;
  char cVar4;
  char cVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x45,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals);
  if (-1 < lVar2) {
    pAVar3 = (AvrcpTransportDeviceReadQueue *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (pAVar3 == (AvrcpTransportDeviceReadQueue *)0x0) {
      pAVar3 = (AvrcpTransportDeviceReadQueue *)0x0;
    }
    else {
      pAVar3 = (AvrcpTransportDeviceReadQueue *)
               AvrcpTransportDeviceReadQueue(pAVar3,param_1,param_2);
    }
    lVar2 = Initialize(pAVar3);
    if (-1 < lVar2) {
      *param_3 = (void *)0x0;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x46,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== Initialize @ 140018210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::Initialize(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceReadQueue::Initialize
          (AvrcpTransportDeviceReadQueue *this)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  undefined4 in_stack_ffffffffffffff30;
  undefined4 in_stack_ffffffffffffff34;
  undefined8 in_stack_ffffffffffffff40;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined8 uStack_9c;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined8 local_2c;
  undefined8 uStack_24;
  undefined8 local_1c;
  undefined8 uStack_14;
  undefined4 local_c;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,
               CONCAT44(in_stack_ffffffffffffff34,in_stack_ffffffffffffff30),0x50,
               in_stack_ffffffffffffff40,(char)this);
  }
  local_68 = 0x60;
  local_64 = 3;
  local_c = 0;
  local_88 = *(undefined8 *)this;
  local_5c = 0;
  uStack_54 = 0;
  local_94 = 0;
  local_4c = 0;
  uStack_44 = 0;
  local_a8 = 0x38;
  local_3c = 0;
  uStack_34 = 0;
  local_90 = 1;
  local_2c = 0;
  uStack_24 = 0;
  local_8c = 1;
  local_1c = 0;
  uStack_14 = 0;
  local_a4 = 0;
  uStack_9c = 0;
  local_80 = 0;
  uStack_78 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)(this + 8),&local_68,&local_a8,this + 0x18);
  if (iVar2 < 0) {
LAB_140018435:
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
LAB_140018449:
      bVar1 = true;
      goto LAB_140018428;
    }
  }
  else {
    if (*(longlong *)(this + 0x28) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    *(undefined8 *)(this + 0x28) = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals);
    if (iVar2 < 0) goto LAB_140018435;
    if (*(longlong *)(this + 0x30) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    }
    *(undefined8 *)(this + 0x30) = 0;
    in_stack_ffffffffffffff30 = 0x42415654;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x630))
                      (WdfDriverGlobals,0,0x11,0x200,0,0x42415654,this + 0x30);
    if (iVar2 < 0) goto LAB_140018435;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    goto LAB_140018449;
  }
  bVar1 = false;
LAB_140018428:
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xff,
               CONCAT44(in_stack_ffffffffffffff34,in_stack_ffffffffffffff30),0x51,
               in_stack_ffffffffffffff40,(char)this,(char)iVar2);
  }
  return iVar2;
}



===== UpdateProfileSupportedFeatures @ 1400184c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UpdateProfileSupportedFeatures(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::UpdateProfileSupportedFeatures
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  longlong lVar2;
  long lVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x70,
               in_stack_ffffffffffffffa0,(char)this);
  }
  lVar3 = 0;
  GetProfileVersionAndFeatures
            (this,(_GUID *)&AVRemoteControlServiceClass_UUID,(ushort *)(this + 0x10),
             (ushort *)(this + 0x12));
  GetProfileVersionAndFeatures
            (this,(_GUID *)&AVRemoteControlTargetServiceClass_UUID,(ushort *)(this + 0x14),
             (ushort *)(this + 0x16));
  if ((*(short *)(this + 0x10) == 0) && (*(short *)(this + 0x14) != 0)) {
    uVar6 = 0x110c;
  }
  else {
    uVar6 = 0x110e;
  }
  lVar2 = CONCAT44(0x10000000,uVar6) - *(longlong *)(this + 0x28);
  if (lVar2 == 0) {
    lVar2 = -0x4cb64a07fffff80 - *(longlong *)(this + 0x30);
  }
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar5 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF__guid_DD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffff90,0x71,
                 in_stack_ffffffffffffffa0,this + 0x28,(char)*(short *)(this + 0x10),
                 (char)*(undefined2 *)(this + 0x14));
    }
  }
  else {
    lVar3 = -0x3ffff8e8;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff90,0x72,
               in_stack_ffffffffffffffa0,(char)this,(char)lVar3);
  }
  return lVar3;
}



===== GetProfileVersionAndFeatures @ 1400186e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::GetProfileVersionAndFeatures(struct
   _GUID const & __ptr64,unsigned short & __ptr64,unsigned short & __ptr64) __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::GetProfileVersionAndFeatures
          (AvrcpTransportDevice *this,_GUID *param_1,ushort *param_2,ushort *param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffb0;
  ushort *puVar6;
  undefined *in_stack_ffffffffffffffc0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x6b,
               in_stack_ffffffffffffffc0,(char)this);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x590))(WdfDriverGlobals,uVar3);
  puVar6 = param_2;
  iVar2 = BtaMpmGetRemoteDeviceProfileVersionAndAttribute
                    (uVar3,this + 0x750,param_1,&AVRemoteControlServiceClass_UUID,0x311,param_2,
                     param_3);
  if (iVar2 < 0) {
    if (iVar2 == -0x3ffffaf4) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF__guid_D
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3)
         ) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        in_stack_ffffffffffffffc0 = &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids;
        puVar6 = (ushort *)CONCAT44((int)((ulonglong)puVar6 >> 0x20),3);
        WPP_RECORDER_AND_TRACE_SF_d
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x6e,
                   &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar2);
      }
      *param_2 = 0;
    }
    *param_3 = 0;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if ((cVar4 != '\0') || (cVar5 != '\0')) {
      WPP_RECORDER_AND_TRACE_SF__guid_DD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x6c,in_stack_ffffffffffffffc0,
                 param_1,(char)*param_2,(char)*param_3);
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x6f,in_stack_ffffffffffffffc0,
               (char)this,(char)iVar2);
  }
  return;
}



===== Initialize @ 1400189c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Initialize(void) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Initialize
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffff20;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 local_b8;
  undefined8 local_b4;
  undefined8 uStack_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  code *pcStack_40;
  undefined8 local_38;
  code *pcStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff20,0x57,
               in_stack_ffffffffffffff30,(char)this);
  }
  local_98 = *(undefined8 *)this;
  local_b8 = 0x38;
  local_58 = 0;
  pcStack_50 = EvtDeviceIoControl;
  local_48 = 0;
  local_res8 = 0;
  pcStack_40 = EvtIoStop;
  uStack_20 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_38 = 0;
  pcStack_30 = (code *)0x0;
  uStack_70 = 0x10000000002;
  local_78 = 0x200000060;
  local_28 = 0xffffffff;
  local_b4 = 0;
  uStack_ac = 0;
  local_a4 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 1;
  local_9c = 1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,local_98,&local_78,&local_b8,&local_res8);
  if (-1 < iVar2) {
    memset(&local_78,0,0x60);
    local_98 = *(undefined8 *)this;
    pcStack_30 = EvtIoCanceledOnQueue;
    uStack_70 = CONCAT44(uStack_70._4_4_,2);
    local_78 = 0x300000060;
    local_b4 = 0;
    uStack_ac = 0;
    local_a4 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_b8 = 0x38;
    local_a0 = 1;
    local_9c = 1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                      (WdfDriverGlobals,local_98,&local_78,&local_b8,this + 0x898);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffff20,0x58,
               in_stack_ffffffffffffff30,(char)this,(char)iVar2);
  }
  return iVar2;
}



===== InitializeEnumeratorInfo @ 140018c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::InitializeEnumeratorInfo(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::InitializeEnumeratorInfo
          (AvrcpTransportDevice *this)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 *puVar6;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined8 local_28;
  AvrcpTransportDevice *local_20;
  undefined8 local_18;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  uVar8 = SUB81(this,0);
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0x5d,
               in_stack_ffffffffffffffc0,uVar8);
  }
  local_20 = this + 0x18;
  local_28 = 1;
  local_18 = 0x730;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
  uVar7 = 0;
  puVar6 = &local_28;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,uVar3,0,0x410007,0,puVar6,0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_dq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x5e,uVar7,(char)iVar2,uVar8);
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x5f,uVar7,uVar8,(char)iVar2);
  }
  return iVar2;
}



===== MakeAndInitialize @ 140018ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140019011) */
/* public: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::MakeAndInitialize(struct
   WDFDEVICE__ * __ptr64,unsigned __int64,enum
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceServiceType,void * __ptr64 *
   __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::MakeAndInitialize
          (WDFDEVICE__ *param_1,__uint64 param_2,AvrcpTransportDeviceServiceType param_3,
          void **param_4)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDeviceService *pAVar3;
  char cVar4;
  char cVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xc,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals);
  if (-1 < lVar2) {
    pAVar3 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (pAVar3 == (AvrcpTransportDeviceService *)0x0) {
      pAVar3 = (AvrcpTransportDeviceService *)0x0;
    }
    else {
      pAVar3 = (AvrcpTransportDeviceService *)
               AvrcpTransportDeviceService(pAVar3,param_1,param_2,param_3);
    }
    lVar2 = Initialize(pAVar3);
    if (-1 < lVar2) {
      *param_4 = (void *)0x0;
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xd,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== Initialize @ 1400191a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Initialize(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::Initialize
          (AvrcpTransportDeviceService *this)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  char cVar6;
  code *in_stack_ffffffffffffffb0;
  AvrcpTransportDeviceService *in_stack_ffffffffffffffc0;
  void *local_28 [2];
  char local_18;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0xe,
               in_stack_ffffffffffffffc0,(char)this);
  }
  wil::out_param<wil::details::unique_wdf_wait_lock_storage>
            ((unique_wdf_wait_lock_storage *)local_28);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals);
  if (local_18 != '\0') {
    wil::details::
    unique_storage<wil::details::resource_policy<void*___ptr64,void_(__cdecl*)(void*___ptr64),&void___cdecl_WdfObjectDelete(void*___ptr64),wistd::integral_constant<unsigned___int64,0>,void*___ptr64,void*___ptr64,0,std::nullptr_t>_>
    ::reset(local_28[0]);
  }
  if (-1 < iVar2) {
    in_stack_ffffffffffffffb0 =
         (code *)CONCAT62((int6)((ulonglong)in_stack_ffffffffffffffb0 >> 0x10),0x200);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x418))
                      (WdfDriverGlobals,*(undefined8 *)(this + 8),
                       &GUID_BTHDDI_PROFILE_DRIVER_INTERFACE,this + 0x118,0x48,
                       in_stack_ffffffffffffffb0,0);
  }
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    if (iVar2 < 0) goto LAB_14001939e;
    in_stack_ffffffffffffffc0 = this + 0x110;
    if (*(longlong *)in_stack_ffffffffffffffc0 != 0) {
      BtaMpmUnregister();
    }
    *(longlong *)in_stack_ffffffffffffffc0 = 0;
    in_stack_ffffffffffffffb0 = OnMediaStatusChanged;
    iVar2 = BtaMpmRegister(*(undefined8 *)(this + 0x10),(*(int *)(this + 0x18) == 1) + '\x02',
                           OnConnectRequested,OnMediaStatusChanged,OnMediaStatusChanged,
                           OnMediaStatusChanged,this);
  }
  if (-1 < iVar2) {
    lVar4 = (**(code **)(this + 0x138))(0x212);
    *(longlong *)(this + 0x160) = lVar4;
    if (lVar4 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      lVar4 = (**(code **)(this + 0x138))(0x104);
      *(longlong *)(this + 0x168) = lVar4;
      iVar2 = 0;
      if (lVar4 == 0) {
        iVar2 = -0x3fffff66;
      }
    }
  }
LAB_14001939e:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffb0,0xf,
               in_stack_ffffffffffffffc0,(char)this,(char)iVar2);
  }
  return iVar2;
}



===== ProcessReadChannelStateRequest @ 140019440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelStateRequest(struct
   WDFREQUEST__ * __ptr64,struct WDFMEMORY__ * __ptr64,struct WDFMEMORY__ * __ptr64,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::ProcessReadChannelStateRequest
          (AvrcpTransportDevice *this,WDFREQUEST__ *param_1,WDFMEMORY__ *param_2,
          WDFMEMORY__ *param_3,__uint64 *param_4)

{
  int *piVar1;
  BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_STATE *pBVar2;
  AvrcpTransportDeviceService *this_00;
  undefined8 uVar3;
  
  piVar1 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2,0);
  pBVar2 = (BLUETOOTH_AVRCP_TRANSPORT_CHANNEL_STATE *)
           (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_3,0);
  if (*piVar1 == 1) {
    uVar3 = *(undefined8 *)(this + 0x888);
  }
  else {
    if (*piVar1 != 2) {
      return -0x3ffffff3;
    }
    if ((*(ushort *)(this + 0x10) < 0x104) || (((byte)this[0x12] & 0x40) == 0)) {
      return -0x3fffff45;
    }
    uVar3 = *(undefined8 *)(this + 0x890);
  }
  this_00 = (AvrcpTransportDeviceService *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar3,
                       PTR__WDF_AvrcpTransportDeviceService_TYPE_INFO_14000f0f8);
  AvrcpTransportDeviceService::GetCurrentState(this_00,pBVar2);
  *param_4 = 9;
  return 0;
}



===== EvtDeviceSurpriseRemoval @ 140019530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceSurpriseRemoval(struct
   WDFDEVICE__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceSurpriseRemoval
          (WDFDEVICE__ *param_1)

{
  AvrcpTransportDevice *this;
  char cVar1;
  char cVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar1 != '\0') || (cVar2 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar2,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x89,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  this = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  OnDeviceSurpriseRemoval(this);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar1 != '\0') || (cVar2 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar2,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x8a,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== OnDeviceSurpriseRemoval @ 140019670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceSurpriseRemoval(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::OnDeviceSurpriseRemoval
          (AvrcpTransportDevice *this)

{
  AvrcpTransportDeviceService *pAVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x7b,
               in_stack_ffffffffffffffe0,(char)this);
  }
  if (*(longlong *)(this + 0x890) != 0) {
    pAVar1 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDeviceService::OnDeviceSurpriseRemoval(pAVar1);
  }
  if (*(longlong *)(this + 0x888) != 0) {
    pAVar1 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDeviceService::OnDeviceSurpriseRemoval(pAVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x7c,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== EvtDevicePrepareHardware @ 1400197d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDevicePrepareHardware(struct
   WDFDEVICE__ * __ptr64,struct WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDevicePrepareHardware
          (WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDevice *this;
  char cVar3;
  char cVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x84,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  this = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar2 = PrepareProfileResources(this);
  if (lVar2 == -0x3ffff8e8) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x85,
                 &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals);
    lVar2 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x86,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== PrepareProfileResources @ 140019a20 =====

/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::PrepareProfileResources(void)
   __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::PrepareProfileResources
          (AvrcpTransportDevice *this)

{
  AvrcpTransportDevice AVar1;
  bool bVar2;
  long lVar3;
  ulonglong uVar4;
  char cVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x5b,
               in_stack_ffffffffffffffe0,(char)this);
  }
  lVar3 = InitializeEnumeratorInfo(this);
  if ((-1 < lVar3) && (lVar3 = InitializeDeviceInfo(this), -1 < lVar3)) {
    lVar3 = UpdateProfileSupportedFeatures(this);
  }
  uVar4 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    if (((lVar3 < 0) ||
        (lVar3 = AvrcpTransportDeviceService::MakeAndInitialize
                           (*(WDFDEVICE__ **)this,*(__uint64 *)(this + 0x750),0,
                            (void **)(this + 0x888)), lVar3 < 0)) ||
       (*(ushort *)(this + 0x10) < 0x104)) goto LAB_140019b71;
    AVar1 = this[0x12];
  }
  else {
    if ((((lVar3 < 0) ||
         ((*(void **)(this + 0x888) == (void *)0x0 &&
          (lVar3 = AvrcpTransportDeviceService::MakeAndInitialize
                             (*(WDFDEVICE__ **)this,*(__uint64 *)(this + 0x750),0,
                              (void **)(this + 0x888)), lVar3 < 0)))) ||
        (*(longlong *)(this + 0x890) != 0)) || (*(ushort *)(this + 0x10) < 0x104))
    goto LAB_140019b71;
    AVar1 = this[0x12];
  }
  if (((byte)AVar1 & 0x40) != 0) {
    lVar3 = AvrcpTransportDeviceService::MakeAndInitialize
                      (*(WDFDEVICE__ **)this,*(__uint64 *)(this + 0x750),1,(void **)(this + 0x890));
  }
LAB_140019b71:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar2)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x5c,
               in_stack_ffffffffffffffe0,(char)this,(char)lVar3);
  }
  return lVar3;
}



===== MakeAndInitialize @ 140019c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::MakeAndInitialize(struct
   _DRIVER_OBJECT * __ptr64,struct _UNICODE_STRING const * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::MakeAndInitialize
          (_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  undefined8 local_res18;
  undefined8 local_78;
  code *local_70;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xc,
               &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids);
  }
  local_28 = PTR__WDF_AvrcpTransportDriver_TYPE_INFO_14000f048;
  local_58 = 0x38;
  local_54 = 0;
  uStack_4c = 0;
  local_44 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 1;
  local_3c = 1;
  WdfCpp::
  ObjectContext<WDFDRIVER__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver,0>
  ::ObjectAttributesInit((_WDF_OBJECT_ATTRIBUTES *)&local_58);
  local_78 = 0x20;
  local_70 = s_OnDriverDeviceAdd;
  local_res18 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_58,&local_78,&local_res18);
  if (-1 < iVar2) {
    puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (puVar3 != (undefined8 *)0x0) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals);
      *puVar3 = uVar4;
    }
    iVar2 = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xd,
               &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== s_OnDriverDeviceAdd @ 140019e50 =====

/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::s_OnDriverDeviceAdd(struct
   WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDriver::s_OnDriverDeviceAdd
          (WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  bool bVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xe,
               &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids);
  }
  lVar2 = AvrcpTransportDevice::MakeAndInitialize(param_2);
  if (lVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_d
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xf,
                 &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids,(char)lVar2);
    }
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x10,
               &WPP_010c4d8cbb1b332136d8c9b49c87c5de_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== MakeAndInitialize @ 140019fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::MakeAndInitialize(struct
   WDFDEVICE_INIT * __ptr64) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::MakeAndInitialize
          (WDFDEVICE_INIT *param_1)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  AvrcpTransportDevice *pAVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  WDFDEVICE_INIT *local_res8;
  undefined8 local_res10;
  undefined4 local_118;
  undefined4 local_114;
  code *local_110;
  code *local_108;
  code *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  code *pcStack_e8;
  code *local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined *local_c0;
  undefined4 local_b8 [2];
  code *local_b0;
  code *local_a0;
  code *local_90;
  code *local_78;
  code *local_58;
  code *local_50;
  
  cVar6 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar7 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar7 = '\0';
  }
  local_res8 = param_1;
  if ((cVar5 != '\0') || (cVar7 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x52,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  local_e0 = (code *)0x0;
  pcStack_e8 = (code *)0x0;
  local_f0 = 0x38;
  uStack_d8 = 0x100000001;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14000f080;
  local_114 = 0;
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  local_118 = 0x28;
  local_110 = EvtDeviceFileCreate;
  local_108 = EvtFileClose;
  local_f8 = 2;
  if ((int)uVar3 == 0) {
    local_100 = (code *)0x0;
  }
  else {
    local_100 = EvtFileCleanup;
  }
  local_f4 = 0x80000002;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res8,&local_118,&local_f0);
  memset(local_b8,0,0x90);
  local_b8[0] = 0x90;
  local_90 = EvtDevicePrepareHardware;
  local_b0 = EvtDeviceD0Entry;
  local_a0 = EvtDeviceD0Exit;
  local_78 = EvtDeviceSelfManagedIoFlush;
  uVar3 = Feature_53100197__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    local_50 = EvtDeviceQueryRemove;
    local_58 = EvtDeviceSurpriseRemoval;
  }
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res8,local_b8);
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_res8,0);
  local_c0 = PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0;
  local_f0 = 0x38;
  pcStack_e8 = WdfCpp::
               ObjectContext<WDFDEVICE__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>
               ::EvtObjectContextCleanupThunk;
  local_e0 = WdfCpp::
             ObjectContext<WDFDEVICE__*___ptr64,Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice,0>
             ::EvtObjectContextDestroyThunk;
  local_d0 = 0;
  uStack_c8 = 0;
  uStack_d8 = 0x200000002;
  local_res10 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res8,&local_f0,&local_res10);
  if (-1 < iVar2) {
    pAVar4 = (AvrcpTransportDevice *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res10,
                        PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
    if (pAVar4 == (AvrcpTransportDevice *)0x0) {
      pAVar4 = (AvrcpTransportDevice *)0x0;
    }
    else {
      memset(pAVar4,0,0x8c8);
      pAVar4 = (AvrcpTransportDevice *)AvrcpTransportDevice(pAVar4);
    }
    iVar2 = Initialize(pAVar4);
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) ||
     (bVar1 = true, (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (cVar5 = '\x01', !bVar1)) {
    cVar5 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x53,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)iVar2);
  }
  return iVar2;
}



===== EvtDeviceD0Exit @ 14001a320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceD0Exit(struct
   WDFDEVICE__ * __ptr64,enum _WDF_POWER_DEVICE_STATE) */

long __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtDeviceD0Exit
          (WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  bool bVar1;
  long lVar2;
  AvrcpTransportDevice *this;
  char cVar3;
  char cVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x8d,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  this = (AvrcpTransportDevice *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar2 = Stop(this);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) || (!bVar1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x8e,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids,(char)lVar2);
  }
  return lVar2;
}



===== Stop @ 14001a480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Stop(void) __ptr64 */

long __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::Stop(AvrcpTransportDevice *this)

{
  AvrcpTransportDeviceService *pAVar1;
  char cVar2;
  char cVar3;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x77,
               in_stack_ffffffffffffffe0,(char)this);
  }
  if (*(longlong *)(this + 0x890) != 0) {
    pAVar1 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDeviceService::Stop(pAVar1);
  }
  if (*(longlong *)(this + 0x888) != 0) {
    pAVar1 = (AvrcpTransportDeviceService *)
             (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    AvrcpTransportDeviceService::Stop(pAVar1);
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if ((cVar2 != '\0') || (cVar3 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,cVar3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x78,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return 0;
}



===== EvtIoCanceledOnQueue @ 14001a5e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtIoCanceledOnQueue(struct
   WDFQUEUE__ * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtIoCanceledOnQueue
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  undefined8 uVar1;
  AvrcpTransportDevice *this;
  WDFFILEOBJECT__ *pWVar2;
  char cVar3;
  char cVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x97,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = (AvrcpTransportDevice *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
  UnregisterReadQueue(this,pWVar2);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  if ((cVar3 != '\0') || (cVar4 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,cVar4,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x98,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== IsCallingProcess @ 14001a7a0 =====

undefined1 IsCallingProcess(ulonglong param_1,undefined1 param_2)

{
  undefined1 uVar1;
  ulonglong local_res8;
  int local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  longlong local_38 [5];
  
  local_res10[0] = CONCAT31(local_res10[0]._1_3_,param_2);
  uVar1 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_38[2] = 0;
  local_38[3] = 0;
  local_res18 = 0;
  local_res20 = 0;
  SeCaptureSubjectContext(local_38);
  SeLockSubjectContext(local_38);
  local_res10[0] = SeQueryInformationToken(local_38[2],0x16,&local_res18);
  if (-1 < local_res10[0]) {
    if (local_38[0] != 0) {
      local_res10[0] = SeQueryInformationToken(local_38[0],0x16,&local_res20);
      if (local_res10[0] < 0) goto LAB_14001a8a2;
    }
    uVar1 = SeAccessCheckFromState
                      (&`IsCallingProcessBluetoothAudioService'::__l2::s_sdBthAvctpSvc,local_res18,
                       local_res20,1,0,0,&DAT_14000f538,1,&local_res8,local_res10);
  }
LAB_14001a8a2:
  if (local_res18 != 0) {
    ExFreePoolWithTag(local_res18,0);
  }
  if (local_res20 != 0) {
    ExFreePoolWithTag(local_res20,0);
  }
  SeUnlockSubjectContext(local_38);
  SeReleaseSubjectContext(local_38);
  return uVar1;
}



===== OnDeviceSurpriseRemoval @ 14001a910 =====

/* public: void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnDeviceSurpriseRemoval(void)
   __ptr64 */

void __thiscall
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDeviceService::OnDeviceSurpriseRemoval
          (AvrcpTransportDeviceService *this)

{
  char cVar1;
  char cVar2;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar1 != '\0') || (cVar2 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar2,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x17,
               in_stack_ffffffffffffffe0,(char)this);
  }
  KeWaitForSingleObject(this + 0x50,0,0,0,0);
  StartDisconnect(this);
  KeWaitForSingleObject(this + 0x50,0,0,0,0);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar1 != '\0') || (cVar2 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,cVar2,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,in_stack_ffffffffffffffd0,0x18,
               in_stack_ffffffffffffffe0,(char)this);
  }
  return;
}



===== WppLoadTracingSupport @ 14001aa60 =====

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



===== WppInitKm @ 14001abb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== EvtFileClose @ 14001aca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtFileClose(struct
   WDFFILEOBJECT__ * __ptr64) */

void __cdecl
Microsoft::Bluetooth::Legacy::AvrcpTransport::AvrcpTransportDevice::EvtFileClose
          (WDFFILEOBJECT__ *param_1)

{
  AvrcpTransportDevice *pAVar1;
  int *piVar2;
  undefined8 uVar3;
  AvrcpTransportDevice *this;
  char cVar4;
  char cVar5;
  
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x91,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  piVar2 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_FILE_OBJECT_CONTEXT_TYPE_INFO_14000f080);
  if (*piVar2 != 0) {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
    this = (AvrcpTransportDevice *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar3,PTR__WDF_AvrcpTransportDevice_TYPE_INFO_14000f0d0);
    pAVar1 = this + 8;
    *(longlong *)pAVar1 = *(longlong *)pAVar1 + -1;
    if (*(longlong *)pAVar1 == 0) {
      OnWin32ServiceReady(this,false);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar4 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar5 = '\0';
  }
  if ((cVar4 != '\0') || (cVar5 != '\0')) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,cVar5,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x92,
               &WPP_cb68bba32fb73382502b30e6a97226a9_Traceguids);
  }
  return;
}



===== __security_init_cookie @ 14001b008 =====

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



===== wil_InitializeFeatureStaging @ 14001b03c =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001b12c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


