#include<iostream>
#include<vector>
#include<numeric>

void test01()
{
	std::vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	int total=std::accumulate(v.begin(), v.end(), 0);//参数3 是起始累加值
	std::cout << "total = " << total << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}