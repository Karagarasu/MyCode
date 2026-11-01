import os
import ctypes
import sys
import win32com.client
import subprocess
from concurrent.futures import ThreadPoolExecutor

# 常量定义
PROCESS_ALL_ACCESS = 0x1F0FFF
kernel32 = ctypes.WinDLL("kernel32")
ntdll = ctypes.WinDLL("ntdll")

# 定义函数原型
OpenProcess = kernel32.OpenProcess
OpenProcess.argtypes = [ctypes.c_uint, ctypes.c_bool, ctypes.c_uint]
OpenProcess.restype = ctypes.c_void_p

TerminateProcess = kernel32.TerminateProcess
TerminateProcess.argtypes = [ctypes.c_void_p, ctypes.c_uint]
TerminateProcess.restype = ctypes.c_bool

CloseHandle = kernel32.CloseHandle
CloseHandle.argtypes = [ctypes.c_void_p]
CloseHandle.restype = ctypes.c_bool

def list_processes():
    """遍历所有进程，输出进程名称和PID"""
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

def get_process_path(pid):
    """获取进程路径并打开资源管理器"""
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

def violent_kill_process(pid):
    """强行终止进程（暴力方法）"""
    try:
        # 提权操作
        if not ctypes.windll.shell32.IsUserAnAdmin():
            print("尝试提权运行脚本...")
            ctypes.windll.shell32.ShellExecuteW(
                None, "runas", sys.executable, __file__, None, 1
            )
            return

        # 打开进程句柄
        process_handle = OpenProcess(PROCESS_ALL_ACCESS, False, pid)
        if not process_handle:
            raise ctypes.WinError()

        # 使用 ZwTerminateProcess 强制杀死进程
        ntstatus = ntdll.ZwTerminateProcess(process_handle, 0)
        if ntstatus != 0:  # 0 表示成功
            print(f"无法终止进程 {pid}，返回值: {ntstatus}")
        else:
            print(f"进程 {pid} 已被暴力终止！")
    except Exception as e:
        print(f"强制终止进程失败: {e}")
    finally:
        if process_handle:
            CloseHandle(process_handle)

def main():
    while True:
        print("\n任务管理器功能选项：")
        print("1. 查看进程路径并打开资源管理器")
        print("2. 取消进程的自启动")
        print("3. 强行关闭进程")
        print("0. 退出")

        # 先列出所有进程
        processes = list_processes()

        choice = input("请输入选项：")

        if choice == "0":
            break
        elif choice in {"1", "2", "3"}:
            try:
                pids = input("请输入多个进程PID（以逗号分隔）：").split(",")
                pids = [int(pid.strip()) for pid in pids]
            except ValueError:
                print("无效的PID！")
                continue

            invalid_pids = [pid for pid in pids if pid not in [proc[0] for proc in processes]]
            if invalid_pids:
                print("无效的PID:", ", ".join(map(str, invalid_pids)))
                continue

            if choice == "1":
                with ThreadPoolExecutor() as executor:
                    executor.map(get_process_path, pids)
            elif choice == "2":
                with ThreadPoolExecutor() as executor:
                    executor.map(disable_autorun, pids)
            elif choice == "3":
                with ThreadPoolExecutor() as executor:
                    executor.map(violent_kill_process, pids)
        else:
            print("无效的选项，请重试！")

if __name__ == "__main__":
    main()
