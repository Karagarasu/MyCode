#include<iostream>
#include<vector>
#include<algorithm>
//常用查找算法 
void test01()
{
	std::vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	std::vector<int>::iterator pos=std::adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		std::cout << "未找到重复相邻元素" << std::endl;
	}
	else
	{
		std::cout << "找到重复相邻元素："<<*pos << std::endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}