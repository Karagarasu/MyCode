#define MINIAUDIO_IMPLEMENTATION
#pragma once
#include "miniaudio.h"
#include <iostream>
#include <windows.h>
#include <psapi.h> 
// 如果定义了 MYDLL_EXPORTS，说明正在编译 DLL，函数需要导出
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif
// 加上 extern "C" 防止 C++ 名称修饰，让函数名更干净
extern "C" MYDLL_API void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);// 音频数据回调函数
extern "C" MYDLL_API int playsound(const wchar_t* path);
extern "C" MYDLL_API extern "C" __declspec(dllexport) const char* getID();
extern "C" MYDLL_API extern "C" __declspec(dllexport) const char* getVersion();
extern "C" MYDLL_API extern "C" __declspec(dllexport) const char* help();
extern "C" MYDLL_API extern "C" __declspec(dllexport) const char* funcHelps();
extern "C" MYDLL_API extern "C" __declspec(dllexport) const char* funcArgs();