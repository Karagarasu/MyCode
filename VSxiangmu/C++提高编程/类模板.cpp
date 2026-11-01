#include<iostream>
using namespace std;
//ÀàÄ£°å
template<typename nametype,typename agetype>
class person
{
public:
	person(nametype name,agetype age)
	{
		m_name = name;
		m_age = age;
	}
	void show()
	{
		cout << "name=" << m_name << endl;
		cout << "age=" << m_age << endl;
	}
	nametype m_name;
	agetype m_age;
};
void test01()
{
	person<string, int>p1("ËïÎò¿Õ", 999);
	p1.show();
}
int main()
{
	test01();
	system("pause");
	return 0;
}