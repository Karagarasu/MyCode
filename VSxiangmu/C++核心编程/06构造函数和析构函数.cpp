#include<iostream>
using namespace std;
//对象的初始化和清理
class Person
{
public:
	//1、构造函数
	//没有返回值 不写void
	//函数名与类名相同
	//构造函数可以有参数，可以重载
	//创建对象时，构造函数自动调用，只一次
	Person() 
	{
		cout << "Person 构造函数的调用" << endl;
	}
	//2、析构函数 进行清理操作
	//没有返回值 不写void
	//函数名和类名相同 在名称前加~
	//析构函数不可以有参数，不可以重载
	//对象在销毁前 会自动调用析构函数 而且只会调用一次
	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
};
//构造和析构都是必须有的实现，如果不写，编译器自己提供空实现构造析构
void test01()
{
	Person p;//在栈上的数据，test01执行完毕后，释放这个对象
}
int main() {
	test01();
	//Person p;
	system("pause");
	return 0;
}