#include<iostream>
using namespace std;
//普通函数与函数模板的区别

//1、普通函数调用时可以发生隐式类型转换

//2、函数模板 用自动类型推导 不可以发生隐式类型转换

//3、函数模板 用显式指定类型 可以发生隐式类型转换

//普通函数
int myadd01(int a,int b)
{
	return a + b;
}
//函数模板
template<typename T>
T myadd02(T a, T b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c'; //a - 97  c - 99
	cout<<myadd01(a,c)<<endl;
	//自动类型推导 不会发生隐式类型转换 
	//cout<<myadd02(a,c)<<endl; 报错
	//显式指定类型
	cout << myadd02<int>(a, c);
}
int main()
{
	test01();
	system("pause");
	return 0;
}