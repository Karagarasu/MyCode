#include "Wallpaper.hpp"
int main() {
    // 1. 获取用户选择的文件路径
    std::wstring path = GetWallpaperPath();

    if (!path.empty()) {
        // 2. 隐藏控制台黑框 (让界面更干净)
        HWND hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);

        // 3. 开始播放
        PlayWallpaper(path);
    }
    return 0;
}