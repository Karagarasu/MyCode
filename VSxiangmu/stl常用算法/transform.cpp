#include<iostream>
#include<vector>
#include<algorithm>
/*
常用的遍历算法 transform
*/
class Tramsform
{
	public:
		int operator()(int v)
		{
			return v+100;
		}
};
class print
{
public:
	void operator()(int val)
	{
		std::cout << val << " ";
	}
};
void test01()
{
	std::vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	std::vector<int>vTarget;
	vTarget.resize(v.size());//目标容器需要提前开辟空间
	std::transform(v.begin(), v.end(), vTarget.begin(),Tramsform());
	std::for_each(vTarget.begin(), vTarget.end(), print());
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}