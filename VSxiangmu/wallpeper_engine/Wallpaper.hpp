#pragma once
#include <string>

#include <commdlg.h>
#include <iostream>
// 1. 弹出文件选择框，获取壁纸路径
std::wstring GetWallpaperPath();
// 2. 播放壁纸
void PlayWallpaper(const std::wstring& path);
std::wstring GetWallpaperPath();
void PlayWallpaper(const std::wstring& path);