#include "pch.h"
#include "Func.hpp"
extern "C" __declspec(dllexport) const char* getID()
{
	return "Sample.dll";
}
extern "C" __declspec(dllexport) const char* getVersion()
{
	return "0.1";
}
extern "C" __declspec(dllexport) const char* help()
{
	return "第一次实现标准！";
}