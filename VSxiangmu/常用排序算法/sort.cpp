#include<iostream>
#include<vector>
#include<algorithm>
//常用排序算法 sort
void myprint(int val)
{
	std::cout << val << " ";
}
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	std::sort(v.begin(), v.end());
	std::for_each(v.begin(), v.end(),myprint);
	std::cout << std::endl;
	//改变为降序
	std::sort(v.begin(), v.end(),std::greater<int>());
	std::for_each(v.begin(), v.end(), myprint);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}