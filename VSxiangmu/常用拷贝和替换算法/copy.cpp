#include<iostream>
#include<vector>
#include<algorithm>
//常用拷贝算法 copy
class myprint
{
public:
	void operator()(int val)
	{
		std::cout << val<<" ";
	}
};
void test01()
{
	std::vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	std::vector<int>v2;
	v2.resize(v1.size());
	std::copy(v1.begin(), v1.end(), v2.begin());
	std::for_each(v2.begin(), v2.end(), myprint());
}
int main()
{
	test01();
	system("pause");
	return 0;
}