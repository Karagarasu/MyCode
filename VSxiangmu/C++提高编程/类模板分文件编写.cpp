#include<iostream>
//第一种解决方式 直接包含 源文件
//#include"person.cpp"

//第二种解决方式 将.h和.cpp中的内容写到一起 将后缀改为.hpp
#include"person.hpp"
using namespace std;
//类模板分文件编写的问题以及解决
//template<class T1,class T2>
//class person
//{
//public:
//	person(T1 name, T2 age);
//	void showperson();
//	T1 m_name;
//	T2 m_age;
//};
//template<class T1,class T2>
//person<T1,T2>::person(T1 name,T2 age)
//{
//	m_name = name;
//	m_age = age;
//}
//template<class T1, class T2>
//void person<T1, T2>::showperson()
//{
//	cout << "姓名：" << m_name << "年龄：" << m_age << endl;
//}
void test01()
{
	person<string, int>p("jerry", 19);
	p.showperson();
}
int main()
{
	test01();
	system("pause");
	return 0;
}