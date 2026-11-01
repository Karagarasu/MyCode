#include<iostream>
#include<algorithm>
#include<vector>
//常用查找算法 find

//查找 内置数据类型
void test01()
{
	std::vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找 容器中 是否有 5 这个元素
	std::vector<int>::iterator it= std::find(v.begin(), v.end(), 50);
	if (it == v.end())
	{
		std::cout << "没有找到！ " << std::endl;
	}
	else
	{
		std::cout << "找到：" <<*it<< std::endl;
	}
}
//查找 自定义数据类型
class Person
{
public:
	Person(std::string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//重载== 让底层find知道如何对比Person类型
	bool operator==(const Person&p)
	{
		if (m_name == p.m_name &&m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	std::string m_name;
	int m_age;
};
//bool operator==(const Person p1, const Person p2)
//{
//	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
void test02()
{
	std::vector<Person>v;
	//创建数据
	Person p1("aaa",10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	//放入到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person pp("bbb", 20);
	std::vector<Person>::iterator it=find(v.begin(), v.end(), pp);
	if (it == v.end())
	{
		std::cout << "没有找到！" << std::endl;
	}
	else
	{
		std::cout << "找到："<<(*it).m_name<<"年龄："<<it->m_age << std::endl;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}