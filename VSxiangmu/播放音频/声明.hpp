#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>

// 音频数据回调函数
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

int playsound(wchar_t* path);