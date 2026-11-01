#include<iostream>
using namespace std;
//常函数
class Person
{
public:
	//this指针的本质 是指针常量 指针的指向是不可修改的 this指针不可以修改指针的指向 Person * const this;
	void showPerson() const
	//void showPerson()
	{
		this->m_B = 100;
		//m_A = 100;//相当于this->m_A=100;
		//this->m_A = 100;
		//this=NULL; //当this在函数被const修饰时this指针完整形式：
		                   //const Person* const this既是 常量指针，也是 指针常量。
	}
	void func()
	{
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改值,加上mutable关键字
};
void test01()
{
	Person p;
	p.showPerson();
}
//常对象
void test02()
{
	const Person p;//在对象前加const变为常对象
	//p.m_A = 100;
	p.m_B = 100;//m_B是特殊值，在常对象下也可以修改
	//常对象只能调常函数
	p.showPerson();
	//p.func(); 常对象 不可以调用普通函数 因为普通成员函数可以修改属性
}
int main()
{
	system("pause");
	return 0;
}