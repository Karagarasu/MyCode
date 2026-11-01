#include<iostream>
using namespace std;
//类模板与函数模板的区别
template<typename nametype,typename agetype= int>
class person
{
public:
	person(nametype name, agetype age)
	{
		m_name = name;
		m_age = age;
	}
	void shwoperson()
	{
		cout << "name:" << m_name << "age:" << m_age<< endl;
	}
	nametype m_name;
	agetype m_age;

};
//1、类模板没有自动类型推导的使用方式
void test01()
{
	//person p("孙悟空", 1000); 错误 无法用自动类型推导
	person<string, int>p("孙悟空", 1000); //正确 只能用显式指定类型
	p.shwoperson();
}
//2、类模板在模板参数列表中可以有默认参数
void test02()
{
	person<string>p("猪八戒", 999);
	p.shwoperson();
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}