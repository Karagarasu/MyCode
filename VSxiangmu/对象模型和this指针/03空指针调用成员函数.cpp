#include<iostream>
using namespace std;
//空指针调用成员函数
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << m_Age << endl;//此时相当于cout << "age=" << this->m_Age << endl; 报错
		                                //原因是因为传入的指针是NULL
	}
	int m_Age;
};
void test01()
{
	Person* p = NULL;
	//p->showClassName();
	p->showPersonAge();
}
int main() {
	test01();
	system("pause");
	return 0;
}