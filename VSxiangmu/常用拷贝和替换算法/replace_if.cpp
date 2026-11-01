#include<iostream>
#include<vector>
#include<algorithm>
void print(int val)
{
	std::cout << val<<" ";
}
//常用拷贝和替换算法 replace_if
bool 大于等于三十替换9000(int val)
{
	return val >= 30;
}
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);
	std::cout << "替换前：" << std::endl;
	std::for_each(v.begin(), v.end(), print);
	std::cout << std::endl;
	std::cout << "替换后：" << std::endl;
	std::replace_if(v.begin(), v.end(), 大于等于三十替换9000, 9000);
	std::for_each(v.begin(), v.end(), print);
}
int main()
{
	test01();
	system("pause");
	return 0;
}