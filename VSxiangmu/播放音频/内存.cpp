#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

// 音频数据回调函数
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) return;

    // 从内存解码器中读取数据输出给声卡
    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);
    (void)pInput;
}

int main() {
    // 1. 使用 wstring 处理中文路径，并将文件内容读入内存
    std::wstring filePath = L"C:\\Users\\aa137\\Downloads\\抖音.mp3"; // 替换为你的中文路径
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        std::cout << "无法打开文件，请检查路径！" << std::endl;
        return -1;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    file.close();

    // 2. 初始化内存解码器
    ma_decoder decoder;
    if (ma_decoder_init_memory(buffer.data(), fileSize, NULL, &decoder) != MA_SUCCESS) {
        std::cout << "内存解码器初始化失败！" << std::endl;
        return -1;
    }

    // 3. 配置播放设备
    ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate = decoder.outputSampleRate;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &decoder;

    ma_device device;
    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        std::cout << "播放设备初始化失败！" << std::endl;
        ma_decoder_uninit(&decoder);
        return -1;
    }

    // 4. 开始播放
    if (ma_device_start(&device) != MA_SUCCESS) {
        std::cout << "启动播放失败！" << std::endl;
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -1;
    }

    std::cout << "正在播放... 按回车键退出" << std::endl;
    getchar();

    // 5. 清理资源
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
    return 0;
}