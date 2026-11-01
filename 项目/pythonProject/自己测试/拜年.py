import cv2
import pygame
import ctypes

def play_video(video_path):
    # 初始化Pygame
    pygame.init()

    # 创建全屏窗口
    screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)

    # 获取窗口句柄并置顶
    hwnd = pygame.display.get_wm_info()["window"]
    ctypes.windll.user32.SetWindowPos(hwnd, -1, 0, 0, 0, 0, 0x0001 | 0x0002)

    # 加载视频
    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print("Error: Cannot open video.")
        return

    # 获取视频帧率
    fps = int(cap.get(cv2.CAP_PROP_FPS))
    frame_time = int(1000 / fps)

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                running = False

        ret, frame = cap.read()
        if not ret:
            break

        # 将视频帧从 BGR 转换为 RGB
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # 转换为 Pygame 的 Surface
        frame_surface = pygame.surfarray.make_surface(frame)

        # 调整视频尺寸以适应屏幕
        frame_surface = pygame.transform.scale(frame_surface, screen.get_size())

        # 显示视频帧
        screen.blit(frame_surface, (0, 0))
        pygame.display.update()
        pygame.time.delay(frame_time)

    cap.release()
    pygame.quit()

if __name__ == "__main__":
    video_path = "your_video.mp4"  # 替换为你的视频路径
    play_video(video_path)
