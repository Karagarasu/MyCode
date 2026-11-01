#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include <random>   
#include <chrono>
//常用排序算法 random_shuffle
void myprint(int val)
{
	std::cout << val << " ";
}
void test01()
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 rng(seed);
	std::vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//利用洗牌 算法 打乱顺序
	std::shuffle(v.begin(), v.end(),rng);
	std::for_each(v.begin(), v.end(), myprint);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}