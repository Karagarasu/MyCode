#include<iostream>
using namespace std;
//模板的局限性
//模板不是万能 有些特定数据类型 需要用具体化方式做特殊实现

class person
{
public:
	person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	//姓名
	string m_name;
	//年龄
	int m_age;
};
//对比两个数据是否相等函数
template<typename T>
bool mycompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//利用具体化person的版本实现代码 具体化优先调用
template<>bool mycompare(person& p1, person& p2)
{
	if(p1.m_name==p2.m_name&&p1.m_age==p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	bool ret = mycompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test02()
{
	person p1("tom", 11);
	person p2("tom", 10);
	bool ret = mycompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}