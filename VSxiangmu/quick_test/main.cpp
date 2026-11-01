#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;


// 设置颜色
void Color(WORD color)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color
    );
}


// 延迟输出（打字机效果）
void TypeText(string text, int speed = 30)
{
    for (char c : text)
    {
        cout << c;
        cout.flush();

        this_thread::sleep_for(
            chrono::milliseconds(speed)
        );
    }

    cout << endl;
}


// 清屏
void Clear()
{
    system("cls");
}


// 进度条
void Loading(string name)
{
    Color(8);
    cout << name << endl;

    Color(10);

    cout << "[";

    for (int i = 0; i < 30; i++)
    {
        cout << "#";
        cout.flush();

        this_thread::sleep_for(
            chrono::milliseconds(50)
        );
    }

    cout << "]";

    Color(7);
    cout << " COMPLETE\n\n";
}


int main()
{
    srand(time(nullptr));


    // 设置黑色背景
    system("color 0A");


    Clear();


    Color(10);
    TypeText("=================================");
    TypeText("       UNKNOWN SYSTEM CORE");
    TypeText("=================================");
    cout << endl;



    Color(8);
    TypeText("[BOOT] Initializing kernel...");
    TypeText("[BOOT] Loading memory...");


    Loading("Memory scan");
    Loading("Network scan");


    Color(11);
    TypeText("[SYSTEM] Connection established.");

    this_thread::sleep_for(
        chrono::seconds(1)
    );


    Color(14);
    TypeText("[WARNING] Unexpected process detected.");

    this_thread::sleep_for(
        chrono::milliseconds(800)
    );


    Color(12);
    TypeText("[ERROR] Process ID : 0x00004F");
    TypeText("[ERROR] Unknown executable found.");
    TypeText("[ERROR] Location : C:\\UNKNOWN\\entity.exe");


    this_thread::sleep_for(
        chrono::seconds(1)
    );


    Color(13);

    TypeText("[UNKNOWN]");
    TypeText("Analyzing entity...");


    Loading("Scanning");


    Color(12);

    TypeText("ERROR CODE : 0xFFFFFFFF");
    TypeText("MEMORY STATUS : CORRUPTED");
    TypeText("USER STATUS : UNKNOWN");


    this_thread::sleep_for(
        chrono::seconds(2)
    );


    Color(8);

    TypeText("");
    TypeText("03:33:33");
    TypeText("System log recovered...");


    this_thread::sleep_for(
        chrono::seconds(1)
    );


    Color(12);


    TypeText("");
    TypeText("!!! CRITICAL FAILURE !!!");


    this_thread::sleep_for(
        chrono::seconds(1)
    );


    Color(13);


    TypeText("The process you are watching");
    TypeText("is not running on this machine.");


    this_thread::sleep_for(
        chrono::seconds(2)
    );


    Color(12);

    TypeText("");
    TypeText("ERROR:");
    TypeText("WHY ARE YOU STILL HERE?");


    Color(7);


    cout << endl;
    system("pause");


    return 0;
}