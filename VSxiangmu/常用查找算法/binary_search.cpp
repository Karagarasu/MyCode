#include<iostream>
#include<vector>
#include<algorithm>
//常用的查找算法 binary_search
void test01()
{
	std::vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(2); 如果是无序序列 结果未知
	//查找容器中是否有9
	//注意：容器必须是有序的序列
	bool result=std::binary_search(v.begin(), v.end(), 9);
	if (result)
	{
		std::cout << "找到元素"  << std::endl;
	}
	else
	{
		std::cout << "未找到" << std::endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}