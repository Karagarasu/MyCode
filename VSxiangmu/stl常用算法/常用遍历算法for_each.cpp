#include<iostream>
#include<algorithm>
#include<vector>
/*
常用的遍历算法for_each
*/
//普通函数
void print01(int val)
{
	std::cout << val << " ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		std::cout << val<<" ";
	}
};
void test01()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	std::for_each(v.begin(), v.end(), print01);
	std::cout <<std:: endl;
	//print02 p02;
	//std::for_each(v.begin(), v.end(), p02);
	std::for_each(v.begin(), v.end(), print02());
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}