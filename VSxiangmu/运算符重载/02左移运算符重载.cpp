#include<iostream>
using namespace std;
//左移运算符重载
class Person
{
friend std::ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a, int b)
	{
		int m_A = a;
		int m_B = b;
	}
private:
	//利用成员函数重载左移运算符
	//不会利用成员函数重载<<,因为无法实现cout在左
	/*void operator<<(cout)
	{

	}*/
	int m_A;
	int m_B;
};
//只能利用全局函数重载左移运算符
std::ostream& operator<<(ostream & out, Person& p)
{
	out << "m_A=" << p.m_A << " m_B=" << p.m_B;
	return out;
}
void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;
	cout << p << "hello world"<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}