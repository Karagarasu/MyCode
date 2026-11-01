import tkinter as tk
from datetime import datetime
import time

# 计算倒计时
def countdown(target_date):
    current_time = datetime.now()
    delta = target_date - current_time
    days, remainder = divmod(delta.total_seconds(), 86400)
    hours, remainder = divmod(remainder, 3600)
    minutes, seconds = divmod(remainder, 60)
    return int(days), int(hours), int(minutes), int(seconds)

# 更新标签显示倒计时
def update_label():
    try:
        target_date = datetime.strptime(entry.get(), '%Y-%m-%d')
        days, hours, minutes, seconds = countdown(target_date)
        label_countdown.config(text=f"{days}天 {hours}小时 {minutes}分钟 {seconds}秒")
    except ValueError:
        label_countdown.config(text="输入的日期格式不正确，请使用YYYY-MM-DD格式")
    root.after(1000, update_label)

# 创建主窗口
root = tk.Tk()
root.title("倒计时器")

# 创建输入框
entry = tk.Entry(root, width=50)
entry.pack(pady=20)

# 创建标签显示倒计时，并设置字体和颜色
# 注意：这里的字体需要系统中已经安装的字体，可以根据实际情况修改
font_style = ("Helvetica", 18, "bold")
label_countdown = tk.Label(root, text="输入日期后开始倒计时", font=font_style, fg="blue")
label_countdown.pack(pady=20)

# 启动倒计时更新
update_label()

# 运行主循环
root.mainloop()
