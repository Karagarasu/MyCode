#include<iostream>
using namespace std;
//重载递增运算符

//自定义的整型
class MyInteger
{
friend std::ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符
MyInteger& operator++()//返回引用为了一直对一个数据进行递增操作
	{//先进行++
		m_Num++;
		return *this;//再返回自身
	}
	//重载后置++运算符
MyInteger operator++(int)//int代表占位参数，可以用于区分前置和后置递增 局部对象不能返回引用
{
	//先 记录当时结果
	MyInteger temp = *this;
	//后 递增
	m_Num++;
	//最后将记录结果返回
	return temp;
}
private:
	int m_Num;
};
//重载<<运算符
std::ostream& operator<<(ostream& cout,MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout <<++ (++myint) << endl;
	cout << myint<< endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	/*int a = 0;
	cout << ++(++a) << endl;
	cout << a << endl;
	system("pause");*/
	return 0;
}