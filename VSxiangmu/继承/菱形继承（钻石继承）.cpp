#include<iostream>
using namespace std;
//动物类
class Animal
{
public:
	int m_Age;
};
//利用虚继承解决菱形继承的问题
// 在继承前加virtual 变为虚继承
// Animalc称为 虚基类
//羊类
class Sheep :virtual public Animal
{

};
//驼类
class Tuo :virtual public Animal
{

};
//羊驼类
class SheepTuo :public Sheep, public Tuo
{

};
void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，有两个父类拥有相同的数据，需要加作用域以区分
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age =" << st.Tuo::m_Age << endl;
	cout << "st.m_Age=" << st.m_Age << endl;
	//这份数据只要有一份，菱形继承导致有两份，资源浪费
	cout<<sizeof(st)<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}