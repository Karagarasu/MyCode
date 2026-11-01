#include "Wallpaper.hpp"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <commdlg.h>
#include <iostream>
// 引入 FFmpeg 头文件
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/log.h> // 【必须添加这一行】
#include <libavutil/imgutils.h> // 【新增这一行】
}
// 1. 获取壁纸路径 (使用 Windows 原生文件选择器)
std::wstring GetWallpaperPath() {
    OPENFILENAMEW ofn;
    wchar_t szFile[260] = { 0 }; // 用 wchar_t 数组完美支持中文路径
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(szFile[0]); // 修复：传入字符数
    // 设置过滤器，只显示视频和GIF，注意双终止符
    ofn.lpstrFilter = L"Media Files\0*.mp4;*.avi;*.mkv;*.mov;*.gif\0All Files\0*.*\0\0";
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileNameW(&ofn)) {
        return std::wstring(szFile);
    }
    return L"";
}

// 2. 播放壁纸 (完整版：包含解码和渲染)
void PlayWallpaper(const std::wstring& path) {
    // --- 1. 初始化 ---
    av_log_set_level(AV_LOG_ERROR);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL 初始化失败!" << std::endl;
        return;
    }

    SDL_Window* window = SDL_CreateWindow("Mini Wallpaper",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // --- 2. FFmpeg 打开视频文件 ---
    AVFormatContext* formatCtx = avformat_alloc_context();

    // 【关键】将 wstring 路径转为 UTF-8，FFmpeg 才能识别中文路径
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &path[0], (int)path.size(), NULL, 0, NULL, NULL);
    std::string pathStr(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &path[0], (int)path.size(), &pathStr[0], size_needed, NULL, NULL);

    if (avformat_open_input(&formatCtx, pathStr.c_str(), NULL, NULL) != 0) {
        std::cout << "无法打开视频文件: " << pathStr << std::endl;
        return;
    }
    avformat_find_stream_info(formatCtx, NULL);

    // --- 3. 找到视频流和解码器 ---
    int videoStream = -1;
    for (unsigned int i = 0; i < formatCtx->nb_streams; i++) {
        if (formatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
            break;
        }
    }
    if (videoStream == -1) return;

    AVCodecParameters* codecPar = formatCtx->streams[videoStream]->codecpar;
    const AVCodec* codec = avcodec_find_decoder(codecPar->codec_id);
    AVCodecContext* codecCtx = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecCtx, codecPar);
    avcodec_open2(codecCtx, codec, NULL);

    // --- 4. 准备帧和纹理 ---
    AVFrame* frame = av_frame_alloc();       // 存放解码后的原始帧 (通常是 YUV 格式)
    AVFrame* frameRGB = av_frame_alloc();    // 存放转换后的 RGB 帧
    int numBytes = av_image_get_buffer_size(AV_PIX_FMT_RGB24, codecCtx->width, codecCtx->height, 1);
    uint8_t* buffer = (uint8_t*)av_malloc(numBytes * sizeof(uint8_t));
    av_image_fill_arrays(frameRGB->data, frameRGB->linesize, buffer, AV_PIX_FMT_RGB24, codecCtx->width, codecCtx->height, 1);

    // 创建颜色空间转换上下文 (YUV -> RGB)
    struct SwsContext* sws_ctx = sws_getContext(codecCtx->width, codecCtx->height, codecCtx->pix_fmt,
        codecCtx->width, codecCtx->height, AV_PIX_FMT_RGB24, SWS_BILINEAR, NULL, NULL, NULL);

    // 创建 SDL 纹理，用于渲染
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, codecCtx->width, codecCtx->height);

    AVPacket* packet = av_packet_alloc();
    bool running = true;
    SDL_Event e;

    // --- 5. 核心播放循环 ---
    while (running) {
        // 处理退出事件
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) running = false;
        }

        // 读取一个数据包
        if (av_read_frame(formatCtx, packet) >= 0) {
            // 如果是视频流的数据包
            if (packet->stream_index == videoStream) {
                // 发送数据包给解码器
                if (avcodec_send_packet(codecCtx, packet) == 0) {
                    // 从解码器接收解码后的帧
                    while (avcodec_receive_frame(codecCtx, frame) == 0) {
                        // 【步骤A】转换颜色格式 (YUV -> RGB)
                        sws_scale(sws_ctx, (uint8_t const* const*)frame->data, frame->linesize, 0, codecCtx->height, frameRGB->data, frameRGB->linesize);

                        // 【步骤B】更新纹理 (把 RGB 数据上传到显卡)
                        SDL_UpdateTexture(texture, NULL, frameRGB->data[0], frameRGB->linesize[0]);

                        // 【步骤C】清空屏幕
                        SDL_RenderClear(renderer);

                        // 【步骤D】复制纹理到屏幕
                        SDL_RenderCopy(renderer, texture, NULL, NULL);

                        // 【步骤E】现呈！(把后台画好的图展示出来)
                        SDL_RenderPresent(renderer);
                    }
                }
            }
            av_packet_unref(packet); // 释放数据包
        }
        else {
            // 视频播放完毕，循环播放
            av_seek_frame(formatCtx, videoStream, 0, AVSEEK_FLAG_BACKWARD);
        }
    }

    // --- 6. 清理资源 ---
    av_free(buffer);
    av_frame_free(&frame);
    av_frame_free(&frameRGB);
    sws_freeContext(sws_ctx);
    avcodec_free_context(&codecCtx);
    avformat_close_input(&formatCtx);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}