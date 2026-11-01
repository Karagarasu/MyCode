#include<iostream>
using namespace std;
//打印数据函数
void showVaule(const int& val)
{
	//val = 1000;
	cout <<"val=" << val << endl;
}
int main() {
	//常量引用
	//使用场景：用来修饰形参，防止误操作
	//int a = 10;
	//加上const后 编译器修改为 int temp =10; const int & ref=temp;
	const int& ref = 10;//引用必须引一块合法内存空间
	//ref = 20;//错误，加入const后只读不可修改
	int a = 100;
	showVaule(a);
	cout << "a=" << a << endl;
	system("pause");
	return 0;
}