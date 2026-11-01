#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void Color(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SlowPrint(string text, int delay = 40)
{
    for (char c : text)
    {
        cout << c;
        Sleep(delay);
    }
    cout << endl;
}

void Flash()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 8; i++)
    {
        SetConsoleTextAttribute(h, BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
        Sleep(80);
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        Sleep(80);
    }
}

int main()
{
    SetConsoleOutputCP(65001);

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    system("title 系统控制台");

    Color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    SlowPrint("Windows 系统控制台");
    Sleep(500);

    SlowPrint("正在检查系统...");
    Sleep(1000);

    SlowPrint("检查完成。");
    Sleep(1000);

    Color(FOREGROUND_RED | FOREGROUND_INTENSITY);

    SlowPrint("发现未知异常。");
    Sleep(900);

    SlowPrint("正在尝试修复...");
    Sleep(1200);

    Flash();

    vector<string> msg = {

        "错误：无法读取核心数据。",

        "错误：内存映射失败。",

        "错误：未知对象响应。",

        "错误：■■■■■■■■",

        "錯誤：資料區塊遺失。",

        "錯誤：請勿繼續觀看。",

        "錯誤：請離開螢幕。",

        "錯誤：祂正在讀取你。",

        "驫饕魑魍龘龖靐灪",

        "讀取緩衝區■■■■",

        "㵘㙓䶮龘驫靐饕魑",

        "鏖讟欞灪䨻䖷䫴",

        "錯誤：祂已經知道你在這裡。",

        "錯誤：不要回頭。",

        "錯誤：██████████",

        "錯誤：請停止呼吸。",

        "魑魍魎魘饕龘龖靐",

        "緩衝區■■■■■■■■",

        "祂■■■■■■■■■■",

        "ERROR ERROR ERROR",

        "ERR0R",

        "SYST3M",

        "祂來了",

        "祂來了",

        "祂來了"

    };

    for (int i = 0; i < msg.size(); i++)
    {
        Color(FOREGROUND_RED | FOREGROUND_INTENSITY);

        SlowPrint(msg[i], 25);

        if (i % 3 == 0)
            Flash();

        Sleep(300);
    }

    for (int i = 0; i < 30; i++)
    {
        Color(rand() % 16);

        cout
            << "龘魑靐饕灪䶮㵘█▓▒░ERR"
            << rand() % 999999
            << "■■■■■■"
            << endl;

        Sleep(40);
    }

    Flash();

    Color(FOREGROUND_RED | FOREGROUND_INTENSITY);

    SlowPrint("");
    SlowPrint("連線已終止");
    SlowPrint("無法恢復");
    SlowPrint("祂還在這裡。", 120);

    Sleep(3000);

    Color(7);

    return 0;
}