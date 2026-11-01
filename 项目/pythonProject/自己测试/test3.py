import os
import ctypes
import sys
import win32com.client
import subprocess
from concurrent.futures import ThreadPoolExecutor
from ctypes import wintypes

# 常量和全局定义
PROCESS_ALL_ACCESS = 0x1F0FFF
PROCESS_TERMINATE = 0x0001
kernel32 = ctypes.WinDLL("kernel32")
ntdll = ctypes.WinDLL("ntdll")

# 提权函数
def ensure_admin():
    if not ctypes.windll.shell32.IsUserAnAdmin():
        print("当前脚本未以管理员权限运行，尝试提权...")
        choice = input("是否输入4进行提权？(输入4提权), 输入'不要提权'则尝试普通权限结束进程: ")
        if choice == "4":
            ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, " ".join(sys.argv), None, 1)
            sys.exit(0)
        elif choice == "不要提权":
            print("您选择不提权，程序将尝试用普通权限结束进程。")
            return False  # 返回 False 表示没有管理员权限，且用户选择不提权
        else:
            print("无效的输入，程序将退出。")
            sys.exit(0)
    return True  # 如果是管理员权限返回 True

# 定义函数原型
OpenProcess = kernel32.OpenProcess
OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
OpenProcess.restype = wintypes.HANDLE

TerminateProcess = kernel32.TerminateProcess
TerminateProcess.argtypes = [wintypes.HANDLE, wintypes.UINT]
TerminateProcess.restype = wintypes.BOOL

CloseHandle = kernel32.CloseHandle
CloseHandle.argtypes = [wintypes.HANDLE]
CloseHandle.restype = wintypes.BOOL

# ZwTerminateProcess原型定义
ZwTerminateProcess = ntdll.ZwTerminateProcess
ZwTerminateProcess.argtypes = [wintypes.HANDLE, wintypes.UINT]
ZwTerminateProcess.restype = wintypes.INT

# 列出进程
def list_processes():
    print(f"{'PID':<10}{'Process Name':<30}")
    print("=" * 40)
    processes = []
    wmi = win32com.client.GetObject("winmgmts:")
    for process in wmi.InstancesOf("Win32_Process"):
        try:
            processes.append((process.ProcessId, process.Name))
            print(f"{process.ProcessId:<10}{process.Name:<30}")
        except Exception:
            continue
    return processes

# 获取进程路径
def get_process_path(pid):
    try:
        wmi = win32com.client.GetObject("winmgmts:")
        for process in wmi.InstancesOf("Win32_Process"):
            if process.ProcessId == pid:
                exe_path = process.ExecutablePath
                if exe_path:
                    print(f"Process Path: {exe_path}")
                    folder = os.path.dirname(exe_path)
                    subprocess.run(f'explorer "{folder}"', shell=True)
                else:
                    print("无法获取进程路径，可能没有足够权限！")
                return
        print("未找到指定PID的进程！")
    except Exception as e:
        print(f"获取进程路径失败: {e}")

# 取消自启动
def disable_autorun(pid):
    """取消进程的自启动"""
    try:
        wmi = win32com.client.GetObject("winmgmts:")
        for process in wmi.InstancesOf("Win32_Process"):
            if process.ProcessId == pid:
                exe_path = process.ExecutablePath
                if exe_path:
                    key_path = r"Software\Microsoft\Windows\CurrentVersion\Run"
                    command = f'reg delete "HKCU\\{key_path}" /v "{os.path.basename(exe_path).split(".")[0]}" /f'
                    result = subprocess.run(command, shell=True)
                    if result.returncode == 0:
                        print("已成功取消自启动！")
                    else:
                        print("取消自启动失败！请检查权限或确认进程是否注册为自启动。")
                else:
                    print("无法获取进程路径，可能没有足够权限！")
                return
        print("未找到指定PID的进程！")
    except Exception as e:
        print(f"取消自启动失败: {e}")

# 强制终止进程
def terminate_process(pid, is_admin):
    process_handle = OpenProcess(PROCESS_TERMINATE, False, pid)
    if not process_handle:
        print(f"无法打开进程 {pid}，可能没有足够权限！")
        return False

    # 尝试用 TerminateProcess 结束进程
    if TerminateProcess(process_handle, 0):
        print(f"进程 {pid} 被正常终止")
        CloseHandle(process_handle)
        return True

    # 如果 TerminateProcess 失败，检查是否是管理员
    if not is_admin:
        print("用普通权限无法终止该进程，正在尝试提权后使用 ZwTerminateProcess 强制终止。")
        return False

    # 如果是管理员权限，尝试用 ZwTerminateProcess 强制终止进程
    try:
        ntstatus = ZwTerminateProcess(process_handle, 0)
        if ntstatus != 0:  # 0表示成功
            print(f"无法终止进程 {pid}，ZwTerminateProcess 返回: {ntstatus}")
        else:
            print(f"进程 {pid} 已被强制终止！")
    except Exception as e:
        print(f"强制终止进程失败: {e}")
    finally:
        CloseHandle(process_handle)

    return True

# 检查是否为管理员
def check_admin_status():
    if ctypes.windll.shell32.IsUserAnAdmin():
        print("当前用户具有管理员权限。")
    else:
        print("当前用户没有管理员权限。")

# 主程序逻辑
def main():
    is_admin = ensure_admin()  # 检查管理员权限，返回 True 或 False

    while True:
        print("\n任务管理器功能选项：")
        print("1. 查看进程路径并打开资源管理器")
        print("2. 取消进程的自启动")
        print("3. 强行关闭进程")
        print("4. 提权")
        print("5. 查看当前是否为管理员")
        print("0. 退出")

        processes = list_processes()

        choice = input("请输入选项：")
        if choice == "0":
            break
        elif choice == "5":
            check_admin_status()  # 添加查看管理员权限选项
        elif choice in {"1", "2", "3"}:
            try:
                pids = [int(pid.strip()) for pid in input("请输入多个进程PID（以逗号分隔）：").split(",")]
            except ValueError:
                print("无效的PID！")
                continue

            if choice == "1":
                with ThreadPoolExecutor() as executor:
                    executor.map(get_process_path, pids)
            elif choice == "2":
                with ThreadPoolExecutor() as executor:
                    executor.map(disable_autorun, pids)
            elif choice == "3":
                # 如果没有管理员权限，仍尝试使用 TerminateProcess
                with ThreadPoolExecutor() as executor:
                    if not is_admin:
                        print("正在尝试用普通权限结束进程...")
                    executor.map(lambda pid: terminate_process(pid, is_admin), pids)
        else:
            print("无效的选项，请重试！")

if __name__ == "__main__":
    main()