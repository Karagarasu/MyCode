#include"pch.h"
#include"声明.hpp"
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) 
{
     ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
     if (pDecoder == NULL) return;

     // 从文件中读取 PCM 数据输出给声卡
     ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);
     (void)pInput;
}
int playsound(const wchar_t* path)
{
    ma_result result;
    ma_decoder decoder;
    ma_device_config deviceConfig;
    ma_device device;

    // 1. 使用 wchar_t 定义带中文的路径
    const wchar_t* filePath = path;

    // 2. 使用 miniaudio 专用于 Windows 宽字符的文件初始化函数
    result = ma_decoder_init_file_w(filePath, NULL, &decoder);
    if (result != MA_SUCCESS) {
        printf("无法初始化音频解码器，请检查路径是否正确。\n");
        return -1;
    }

    // 3. 配置播放设备
    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate = decoder.outputSampleRate;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &decoder;

    // 4. 初始化并启动设备
    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return -2;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -3;
    }

    // 1. 声明一个变量来接收总帧数
    ma_uint64 totalFrames = 0;

    // 2. 正确调用函数（注意第二个参数需要传地址 &totalFrames）
    if (ma_decoder_get_length_in_pcm_frames(&decoder, &totalFrames) == MA_SUCCESS) {
        double durationInSeconds = (double)totalFrames / decoder.outputSampleRate;

        // 3. 加上 1 秒冗余时间，并转换为毫秒
        DWORD waitTimeMs = (DWORD)((durationInSeconds + 1.0) * 1000);

        // 4. 让主线程“死等”
        Sleep(waitTimeMs);
    }
    else {
        // 如果获取失败（比如某些流媒体没有固定长度），可以做个保底等待
        Sleep(5000);
    }

    // 5. 清理资源
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
    return 0;
}
extern "C" __declspec(dllexport) const char* getID()
{
    return"音频播放.dll";
}
extern "C" __declspec(dllexport) const char* getVersion()
{
    return "0.3";
}
extern "C" __declspec(dllexport) const char* help()
{
    return "文件如其名，播放音频\n";
}           
extern "C" __declspec(dllexport) const char* funcHelps()
{
    return "data_callback|void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)音频数据回调函数，一般不调用;\nplaysound|int playsound(const wchar_t* path)请传入绝对路径;\n";
}
extern "C" __declspec(dllexport) const char* funcArgs()
{
    return"data_callback|ma_device*:pDevice:触发回调的 ma_device 实例指针。允许用户在回调中访问设备特定的设置或状态|void*:pOutput:输出缓冲区指针，用于在播放模式下写入音频样本。缓冲区通常包含交错排列的浮点样本，准备发送给数模转换器 (DAC)|const void*:pInput:输入缓冲区指针，包含来自麦克风/输入源的原始音频样本（仅在录制模式下有效）。它是只读的 (const)|ma_uint32:frameCount:当前回调需要处理的音频帧数。注意：这里指的是“帧”(frames)，而不是字节或单个样本。一帧通常等于每个通道一个样本（例如，立体声中，一帧 = 2 个样本);playsound|Wstring:path:要播放的音频文件的绝对路径;\n";
}