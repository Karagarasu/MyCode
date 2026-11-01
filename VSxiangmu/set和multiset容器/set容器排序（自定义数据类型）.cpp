#include<iostream>
#include<set>
using namespace std;
//set容器排序 存放自定义数据类型
class person
{
public:
	person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
class compare
{
public:
	bool operator() (const person&p1,const person p2) const
	{
		//按照年龄降序
		return p1.m_age > p2.m_age;
	}
};
void test01()
	{
	//自定义数据类型 都会指定排序规则
	set<person,compare>s;
	//创建person对象
	person p1("刘备", 24);
	person p2("关羽", 28);
	person p3("张飞", 25);
	person p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<person,compare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
	}
	}
int main()
{
	test01();
	system("pause");
	return 0;
}