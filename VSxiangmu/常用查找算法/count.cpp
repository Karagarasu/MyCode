#include<iostream>
#include<vector>
#include<algorithm>
//常用查找算法count

//1、统计内置数据类型
void test01()
{
	std::vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	int num=std::count(v.begin(), v.end(), 40);
	std::cout << "40的元素个数为：" << num << std::endl;
}
//2、统计自定义数据类型
class Person
{
public:
	Person(std::string name,int age):name(name),age(age){}
	std::string name;
	int age;
	bool operator== (const Person &p)
	{
		return age == p.age;
	}
};
void test02()
{
	std::vector<Person>v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云",30);
	Person p5("曹操", 40);
	Person p("诸葛亮", 35);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = std::count(v.begin(), v.end(), p);
	std::cout << "和诸葛亮同岁数的人员个数为："<<num << std::endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}