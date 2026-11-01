#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
//常用算数生成算法 fill
void print(int &val)
{
	std::cout << val<<" ";
}
void test01()
{
	std::vector<int>v;
	v.resize(10);
	//后期重新填充
	std::fill(v.begin(), v.end(), 100);
	std::for_each(v.begin(), v.end(), print);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}