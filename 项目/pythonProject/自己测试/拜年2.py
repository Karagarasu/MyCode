import subprocess
import ctypes
import sys,time

# 视频文件路径，假设视频文件被打包到 'videos' 目录下
video_file = sys._MEIPASS + '\\videos\\your_video.mp4'

# 调用系统默认播放器播放视频
subprocess.Popen(['start', video_file], shell=True)

# 给播放器一些时间来启动
time.sleep(1)

# 播放器窗口的标题，这需要根据你的播放器进行调整
player_window_title = "Windows Media Player"  # 示例，可能需要根据实际情况修改

# 找到播放器窗口的句柄
player_hwnd = ctypes.windll.user32.FindWindowW(None, player_window_title)

# 如果找到了窗口句柄，尝试将其置顶
if player_hwnd:
    ctypes.windll.user32.SetForegroundWindow(player_hwnd)
