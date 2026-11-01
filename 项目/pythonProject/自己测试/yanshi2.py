import cv2
import numpy as np
from PIL import Image
import time


# 将图像转换为字符画的函数
def image_to_ascii(image, new_width=100, threshold=128):
    # 获取原图的宽高比
    width, height = image.size
    ratio = height / width
    new_height = int(new_width * ratio)
    image = image.resize((new_width, new_height))  # 调整大小

    # 转换为灰度图
    image = image.convert('L')

    # 转换为numpy数组
    img_array = np.array(image)

    # 输出字符画
    ascii_str = ''
    for row in img_array:
        for pixel in row:
            if pixel < threshold:
                ascii_str += '*'  # 黑色部分
            else:
                ascii_str += ' '  # 白色部分
        ascii_str += '\n'

    return ascii_str


# 处理视频文件的函数
def video_to_ascii(video_path, new_width=100, threshold=128):
    # 打开视频文件
    cap = cv2.VideoCapture(video_path)

    while True:
        ret, frame = cap.read()  # 逐帧读取视频
        if not ret:
            break

        # 转换为灰度图
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # 将帧转换为PIL图像格式
        pil_image = Image.fromarray(gray_frame)

        # 将每一帧转换为字符画
        ascii_art = image_to_ascii(pil_image, new_width, threshold)

        # 模拟清屏，通过打印换行符
        print("\n" * 100)  # 打印100个换行符，清屏效果

        # 输出字符画
        print(ascii_art)

        # 延迟0.5秒
        time.sleep(0.5)

    cap.release()


# 使用示例
video_path = r'D:\Desktop\新建文件夹\bad apple.mp4'  # 替换为你的视频路径
video_to_ascii(video_path, new_width=100)
