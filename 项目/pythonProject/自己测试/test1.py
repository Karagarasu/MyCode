import os
import sys
import psutil
import win32com.shell.shell as shell
import win32api
import win32con
import concurrent.futures


# 检查是否以管理员身份运行
def run_as_admin():
    if not shell.IsUserAnAdmin():
        script_path = os.path.abspath(sys.argv[0])
        shell.ShellExecuteEx(lpVerb='runas', lpFile=sys.executable, lpParameters=f'"{script_path}"')
        sys.exit()  # 确保脚本退出
    else:
        print("管理员权限获取失败!")


# 列出所有正在运行的进程及其PID
def list_processes():
    print("\n当前正在运行的进程：")
    processes = []
    for proc in psutil.process_iter(['pid', 'name']):
        try:
            processes.append(proc.info)
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            continue
    for i, proc in enumerate(processes):
        print(f"{i + 1}. {proc['name']} (PID: {proc['pid']})")
    return processes


# 根据进程PID强行结束进程
def kill_process(pid):
    try:
        process = psutil.Process(pid)
        process.terminate()
        process.wait(timeout=3)  # 等待进程终止
        print(f"已强行结束进程 {pid}")
    except psutil.NoSuchProcess:
        print(f"进程 {pid} 不存在")
    except psutil.AccessDenied:
        print(f"没有权限结束进程 {pid}")
    except psutil.ZombieProcess:
        print(f"进程 {pid} 是僵尸进程，无法操作")
    except Exception as e:
        print(f"无法结束进程 {pid}: {e}")


# 使用win32api强行结束进程
def kill_process_with_win32(pid):
    try:
        handle = win32api.OpenProcess(win32con.PROCESS_TERMINATE, False, pid)
        win32api.TerminateProcess(handle, -1)
        print(f"通过win32api强行结束进程 {pid}")
    except Exception as e:
        print(f"无法通过win32api终止进程 {pid}: {e}")

def main():
    while True:
        # 列出所有进程
        list_processes()
        user_input = input("\n请输入你要结束的进程的PID（多个PID用逗号分隔，或输入“拜拜/退出/再见/bye”退出程序）：").strip()

        # 检查退出条件
        if user_input.lower() in ["拜拜", "退出", "再见", "bye"]:
            print("程序已退出，再见！")
            break

        # 检查用户输入是否是有效的数字
        try:
            pids_to_kill = [int(pid.strip()) for pid in user_input.split(',')]
            for pid in pids_to_kill:
                if not psutil.pid_exists(pid):
                    print(f"进程 {pid} 不存在。")
                    continue

            # 创建一个进程池
            with concurrent.futures.ProcessPoolExecutor() as executor:
                # 提交任务来结束每个进程
                for pid in pids_to_kill:
                    executor.submit(kill_process, pid)

        except ValueError:
            print("请输入有效的PID（多个PID用逗号分隔）。")

# ... 其他代码保持不变 ...


if __name__ == "__main__":
    try:
        run_as_admin()  # 尝试提升权限
        main()
    except KeyboardInterrupt:
        print("\n用户中止程序。")
    except Exception as e:
        print(f"发生未知错误: {e}")
