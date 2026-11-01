#include<iostream>
#include<vector>
#include<algorithm>
//常用集合算法 set_union
class myprint
{
public:
	void operator()(int& val)
	{
		std::cout << val << " ";
	}
};
void test01()
{
	std::vector<int>v1;
	std::vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	std::vector<int>Target;
	Target.resize(v1.size()+v1.size());//最特殊情况 两个容器没有交集 
	std::vector<int>::iterator itend =std::set_union(v1.begin(), v1.end(), v2.begin(),v2.end(), Target.begin());
	std::for_each(Target.begin(), itend, myprint());
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}