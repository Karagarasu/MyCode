#include<iostream>
using namespace std;
/*
函数对象（仿函数）
函数对象在使用时 可以像普通函数那样调用 可以有参数 可以有返回值
函数对象超出普通函数的概念 函数对象可以有自己的状态
函数对象可以作为参数传递

*/
class myadd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};
//1 函数对象在使用时 可以像普通函数那样调用 可以有参数 可以有返回值
void test01()
{
	myadd myadd;
	cout<<myadd(10, 10)<<endl;
}
//2 函数对象超出普通函数的概念 函数对象可以有自己的状态
class myprint
{
public:
	myprint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count;//内部自己的状态

};
void test02()
{
	myprint myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	cout << "myprint调用的次数：" << myprint.count << endl;
}
//3 函数对象可以作为参数传递
void doprint(myprint & mp,string test)
{
	mp(test);
}
void test03()
{
	myprint myprint;
	doprint(myprint, "hello c++");
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}