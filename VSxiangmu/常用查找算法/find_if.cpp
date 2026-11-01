#include<iostream>
#include<vector>
#include<algorithm>
//常用查找算法 find_if
//1、查找内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	std::vector<int>::iterator it=std::find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		std::cout << "未找到" << std::endl;
	}
	else
	{
		std::cout << "找到大于五的数字为：" << *it << std::endl;
	}
}
//2、查找自定义数据类型
class Person
{
public:
	Person(std::string name,int age):name(name),age(age)
	{

	}
	std::string name;
	int age;
};
class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.age > 20;
	}
};
void test02()
{
	std::vector<Person>v;
	Person p1("aaa",10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//找年龄大于20的人
	std::vector<Person>::iterator it = std::find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		std::cout << "未找到" << std::endl;
	}
	else
	{
		std::cout << "找到年龄大于20的人为：" << it->name <<" 年龄："<<(*it).age << std::endl;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}