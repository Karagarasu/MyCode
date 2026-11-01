#include<iostream>
#include<vector>
#include<algorithm>
void myprint(int &val)
{
	std::cout << val << " ";
}
void test01()
{
	std::vector<int>v1;
	std::vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);

	}
	std::vector<int>Vtarget;
	//最特殊的情况 两个容器没有交集 取大的size作为目标容器开辟空间
	//Vtarget.resize(v1.size() > v2.size() ? v1.size() : v2.size());
	Vtarget.resize(std::max(v1.size(), v2.size()));
	std::cout << "v1和v2的差集为: " << std::endl;
	std::vector<int>::iterator Vtend=std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), Vtarget.begin());
	std::for_each(Vtarget.begin(), Vtend, myprint);
	std::cout << std::endl;
	std::cout << "v2和v1的差集为: " << std::endl;
Vtend = std::set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), Vtarget.begin());
	std::for_each(Vtarget.begin(), Vtend, myprint);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}