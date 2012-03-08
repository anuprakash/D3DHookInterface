﻿#ifndef _ist_D3DHookInterface_Utilities_Module_h_
#define _ist_D3DHookInterface_Utilities_Module_h_

#include <windows.h>
#include <TlHelp32.h>
#include <vector>


template<class T> inline void** get_vtable(T _this) { return ((void***)_this)[0]; }
template<class T> inline void   set_vtable(T _this, void **vtable) { ((void***)_this)[0] = vtable; }


/// 指定のプロセス内の指定の名前のモジュール情報を取得
/// dwProcessId: 0 だと current process 扱いになります
bool GetModuleInfo(MODULEENTRY32W &out_info, WCHAR *lpModuleName, DWORD dwProcessId=0);

/// 指定のプロセス内の全モジュール情報を取得
size_t GetAllModuleInfo(std::vector<MODULEENTRY32W> &out_info, DWORD dwProcessId=0);



/// 指定のアドレスが d3d11.dll モジュール内かを調べます
bool IsAddressInD3D11DLL(void *address, DWORD dwProcessId=0);

/// return address が d3d11.dll モジュール内でない場合に true となるマクロです
/// d3d11.dll モジュール内から呼ばれた場合 hook 処理を無効化したい、という要件がよくあるため用意されています
#define IsNotReturnAddressInD3D11DLL() !IsAddressInD3D11DLL(_ReturnAddress())


#endif // _ist_D3DHookInterface_Utilities_Module_h_