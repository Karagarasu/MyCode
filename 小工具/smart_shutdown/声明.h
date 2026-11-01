#pragma once
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "advapi32.lib")
#include <windows.h>
#include <winternl.h>
#include <iostream>
#include <psapi.h> 
// 如果定义了 MYDLL_EXPORTS，说明正在编译 DLL，函数需要导出
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif
enum class SHUTDOWN_ACTION : ULONG;
using PFN_NtShutdownSystem = NTSTATUS(NTAPI*)(SHUTDOWN_ACTION Action);
// 加上 extern "C" 防止 C++ 名称修饰，让函数名更干净
extern "C" MYDLL_API BOOL ForcePowerOff();
extern "C" __declspec(dllexport) const char* getID();
extern "C" __declspec(dllexport) const char* getVersion();
extern "C" __declspec(dllexport) const char* help();
extern "C" __declspec(dllexport) const char* funcHelps();
extern "C" __declspec(dllexport) const char* funcArgs();