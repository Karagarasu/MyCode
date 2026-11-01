#include<iostream>
#include<vector>
#include<algorithm>
//swap互换容器内容
void myprint(int &val)
{
	std::cout << val<<" ";
	
}
void test01()
{
	std::vector<int>v1;
	std::vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}
	std::cout << "交换前： " << std::endl;
	std::for_each(v1.begin(), v1.end(), myprint);
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), myprint);
	std::cout << std::endl;
	std::swap(v1, v2);
	std::cout << "交换后： " << std::endl;
	std::for_each(v1.begin(), v1.end(), myprint);
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), myprint);
	std::cout << std::endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}