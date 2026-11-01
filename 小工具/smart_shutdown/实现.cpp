#include"pch.h"
#include"声明.h"
enum class SHUTDOWN_ACTION : ULONG {
    ShutdownNoReboot = 0,
    ShutdownReboot = 1,
    ShutdownPowerOff = 2
};
BOOL ForcePowerOff()
{
    // 1. 获取并提升 SeShutdownPrivilege
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        return FALSE;

    TOKEN_PRIVILEGES tp = { 0 };
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!LookupPrivilegeValueW(NULL, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid))
    {
        CloseHandle(hToken);
        return FALSE;
    }

    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL) ||
        GetLastError() == ERROR_NOT_ALL_ASSIGNED)
    {
        CloseHandle(hToken);
        return FALSE;
    }
    CloseHandle(hToken);

    // 2. 动态加载 NtShutdownSystem
    HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
    auto pfnShutdown = reinterpret_cast<PFN_NtShutdownSystem>(
        GetProcAddress(hNtdll, "NtShutdownSystem")
        );
    if (!pfnShutdown)
        return FALSE;

    // 3. 执行断电关机
    NTSTATUS status = pfnShutdown(SHUTDOWN_ACTION::ShutdownPowerOff);

    // 成功则系统已断电，不会执行到这里
    if (status == 0) // STATUS_SUCCESS
        return TRUE;

    SetLastError(RtlNtStatusToDosError(status));
    return FALSE;
}
__declspec(dllexport) const char* getID()
{
    return "智能关机\n";
}
__declspec(dllexport) const char* getVersion()
{
    return "0.2\n";
}
__declspec(dllexport) const char* help()
{
    return "帮助目标用户更好更快的安全关机！\n";
}
__declspec(dllexport) const char* funcHelps()
{
    return "ForcePowerOff|BOOL ForcePowerOff()\n";
}
__declspec(dllexport) const char* funcArgs()
{
    return "ForcePowerOff|void:void:无形参:void\n";
}