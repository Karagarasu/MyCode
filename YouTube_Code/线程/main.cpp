#include<iostream>
#include<thread>
#include<chrono>
static bool s_Finished = false;
void DoWork()
{
using namespace std::literals::chrono_literals;
std::cout << "开始的线程ID= " << std::this_thread::get_id() << std::endl;
  while (!s_Finished)
  {
   std::cout << "Working......." << std::endl;
std::this_thread::sleep_for(1s);
  }
}
int main()
{
	std::thread worker(DoWork);
	std::cin.get();
	s_Finished = true;
	worker.join();
	std::cout << "Finished!" << std::endl;
	std::cout << "开始的线程ID= " << std::this_thread::get_id() << std::endl;
	system("pause");
	return 0;
}