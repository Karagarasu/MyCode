#include<iostream>
#include<vector>
#include<algorithm>
//将内容内指定范围的旧元素改为新元素
void print(int val)
{
	std::cout << val << std::endl;
}
void test01()
{
	std::vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);
	std::cout << "替换前 ： " << std::endl;
	std::for_each(v.begin(), v.end(), print);
	std::cout << std::endl;
	std::replace(v.begin(), v.end(), 20, 2000);
	std::cout << "替换后 ： " << std::endl;
	std::for_each(v.begin(), v.end(), print);
}
int main()
{
	test01();
	system("pause");
	return 0;
}