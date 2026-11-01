#include<iostream>
#include<list>
using namespace std;
//list容器 排序案例 对于自定义数据类型 做排序
//按照年龄进行升序 如果年龄相同按照身高进行降序
class person
{
public:
	person(string name,int age,int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
//指定排序规则
bool compareperson(person &p1,person &p2)
{
	//按照年龄 升序
	if (p1.m_age == p2.m_age)
	{
		//年龄相同 按照身高降序
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
}
void test01()
{
	list<person>l;
	person p1("刘备", 35, 175);
	person p2("曹操", 45, 180);
	person p3("孙权",40,170);
	person p4("赵云",25,190);
	person p5("张飞",35,160);
	person p6("关羽",35,200);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	for (list<person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}
	//排序
	cout << "-----------------------------" << endl;
	cout << "排序后：" << endl;
	l.sort(compareperson);
	for (list<person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}