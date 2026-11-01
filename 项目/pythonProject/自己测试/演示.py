import cv2
import numpy as np
from PIL import Image
import threading
import queue
import time
import sys
import os
from ffpyplayer.player import MediaPlayer

# 将图像转换为字符画的函数
def image_to_ascii(image, new_width=100, threshold=128):
    width, height = image.size
    ratio = height / width
    new_height = int(new_width * ratio)
    image = image.resize((new_width, new_height))  # 调整大小
    image = image.convert('L')  # 转换为灰度图
    img_array = np.array(image)

    ascii_str = ''
    for row in img_array:
        for pixel in row:
            ascii_str += '*' if pixel < threshold else ' '
        ascii_str += '\n'
    return ascii_str

# 视频解析线程
def video_parser(video_path, frame_queue, stop_event, new_width=100, threshold=128):
    cap = cv2.VideoCapture(video_path)
    while not stop_event.is_set():
        ret, frame = cap.read()
        if not ret:
            stop_event.set()  # 如果没有更多帧，停止解析
            break

        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        pil_image = Image.fromarray(gray_frame)
        ascii_art = image_to_ascii(pil_image, new_width, threshold)
        frame_queue.put(ascii_art)  # 将字符画放入队列中

    cap.release()

# 字符画打印线程
def ascii_printer(frame_queue, stop_event, fps):
    while not stop_event.is_set() or not frame_queue.empty():
        try:
            ascii_art = frame_queue.get(timeout=0.1)  # 从队列中取出字符画
            print(ascii_art)
            time.sleep(1 / fps)  # 控制输出速度
        except queue.Empty:
            continue

# 音频播放线程
def audio_player(video_path, stop_event):
    player = MediaPlayer(video_path)
    while not stop_event.is_set():
        audio_frame, val = player.get_frame()
        if val == 'eof':
            stop_event.set()  # 音频播放结束后，停止程序
            break
        #time.sleep(0.01)  # 小延时避免过高 CPU 占用

# 获取打包后的视频路径
def get_resource_path(relative_path):
    if hasattr(sys, '_MEIPASS'):
        # 打包后运行，资源在临时目录下
        return os.path.join(sys._MEIPASS, relative_path)
    else:
        # 开发环境运行，直接使用相对路径
        return relative_path

# 主函数
def main():
    video_path = get_resource_path("bad apple.mp4")  # 打包时的资源文件名
    frame_queue = queue.Queue(maxsize=10)  # 创建队列，存储解析后的字符画
    stop_event = threading.Event()  # 用于停止线程的事件

    # 获取视频帧率
    cap = cv2.VideoCapture(video_path)
    fps = cap.get(cv2.CAP_PROP_FPS)
    cap.release()
    print(f"视频帧率: {fps} FPS")

    # 创建并启动线程
    parser_thread = threading.Thread(target=video_parser, args=(video_path, frame_queue, stop_event))
    printer_thread = threading.Thread(target=ascii_printer, args=(frame_queue, stop_event, fps))
    audio_thread = threading.Thread(target=audio_player, args=(video_path, stop_event))

    parser_thread.start()
    printer_thread.start()
    audio_thread.start()

    # 等待线程结束
    audio_thread.join()  # 等待音频播放结束
    parser_thread.join()  # 等待视频解析线程结束
    printer_thread.join()  # 等待字符画打印线程结束

if __name__ == "__main__":
    main()
