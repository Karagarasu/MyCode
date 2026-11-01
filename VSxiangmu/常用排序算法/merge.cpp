#include<iostream>
#include<vector>
#include<algorithm>
void print(int val)
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
		v2.push_back(i + 1);
	}

	//目标容器
	std::vector<int>vTarget;
	//提前给目标容器分配空间
	vTarget.resize(v1.size() + v2.size());
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	std::for_each(vTarget.begin(), vTarget.end(), print);
}
int main()
{
	test01();
	system("pause");
	return 0;
}