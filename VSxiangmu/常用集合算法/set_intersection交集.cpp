#include<iostream>
#include<vector>
#include<algorithm>
//常用集合算法 交集 set_intersection
void myprint(int& val)
{
	std::cout << val << " ";
}
void test01()
{
	std::vector<int>v1;
	std::vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);//0~9
		v2.push_back(i + 5);//5~14
	}
	std::vector<int>vTarget;
	//目标容器需要提前开辟空间
	//vTarget.resize(v1.size()>v2.size()? v2.size() : v1.size()); //最特殊情况 大容器包含小容器 开辟空间 取小容器的大小
	vTarget.resize(std::min(v1.size(), v2.size()));
	//获取交集
	std::vector<int>::iterator itEnd=std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	std::for_each(vTarget.begin(), itEnd, myprint);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}