#include<iostream>
#include<chrono>
#include<thread>
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start,end;
	std::chrono::duration<float> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() *1000.0f;
		std::cout << "Timer took " << ms << " ms" << std::endl;
	}
};
void Function()
{
	std::cout << "测试你电脑输出y次“你好”需要多少毫秒！\n请输入y值：" << std::endl;
	int y=0;
	std::cin >> y;
	Timer tm;
	for (int i=0; i < y; i++)
	{
		std::cout << "你好\n" ;
	}
}
int main()
{
	//using namespace std::literals::chrono_literals;
	//auto start=std::chrono::high_resolution_clock::now();
	//std::this_thread::sleep_for(1s);
	Function();
	/*auto end= std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s" << std::endl;*/
	system("pause");
	return 0;
}