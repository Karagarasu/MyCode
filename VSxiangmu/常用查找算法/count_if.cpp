#include<iostream>
#include<vector>
#include<algorithm>
//常用的查找算法 count_if
//统计内置数据类型
class Greater20
{
public:
	bool operator()(int v)
	{
		return v> 20;
	}
};
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	int num=std::count_if(v.begin(), v.end(), Greater20());
	std::cout << "大于20的元素个数为： " << num << std::endl;
}
//统计自定义数据类型
class Person
{
public:
	Person(std::string name, int age) :name(name), age(age) {};
	std::string name;
	int age;
};
class suishudayu20
{
public:
	bool operator()(const Person& p)
	{
		return p.age > 20;
	}
};

void test02()
{
	std::vector<Person>v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 40);
	Person p5("曹操", 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = std::count_if(v.begin(), v.end(),suishudayu20());
	std::cout << "大于20岁的人个数为： " << num << std::endl;

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}