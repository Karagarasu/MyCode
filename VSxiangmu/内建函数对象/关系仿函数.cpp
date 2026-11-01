#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
//内建函数对象 关系仿函数
//大于 greater
class Mycompare
{public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void PrintVector(std::vector<int>& v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	//降序
	//std::sort(v.begin(), v.end(),Mycompare());
	std::sort(v.begin(), v.end(),std::greater<int>());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	PrintVector(v);
}
int main()
{
	test01();
	system("pause");
	return 0;
}