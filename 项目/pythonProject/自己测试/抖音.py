import webview
import tkinter as tk

def open_douyin():
    # 打开嵌入式浏览器窗口
    webview.create_window("抖音", "https://www.douyin.com/")
    webview.start()

# 创建主窗口
root = tk.Tk()
root.title("抖音套壳")
root.geometry("300x150")

# 创建按钮
button = tk.Button(root, text="打开抖音", command=open_douyin, height=2, width=20)
button.pack(pady=50)

# 运行Tkinter GUI
root.mainloop()
