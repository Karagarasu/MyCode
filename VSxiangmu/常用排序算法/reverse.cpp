#include<iostream>
#include<vector>
#include<algorithm>
void myprint(int val)
{
	std::cout <<" " << val;
}
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	std::cout << "反转前： " <<std:: endl;
	std::for_each(v.begin(), v.end(), myprint);
	std::cout << "反转后： " << std::endl;
	std::reverse(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), myprint);
}
int main()
{
	test01();
	system("pause");
	return 0;
}