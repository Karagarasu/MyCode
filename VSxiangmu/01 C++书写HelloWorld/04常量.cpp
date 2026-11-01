#include<iostream>
using namespace std;
//常量的定义方式
//1 #define宏常量
//2 const修饰的变量
#define Day 7
int main() {
	//Day = 14;  错误的，Day是常量，修改则报错
	cout << "一周总共有：" << Day << "天" << endl;
	const int month = 12;
	//month = 24; 错误的，const修饰的变量是常量，修改则报错
	cout << "一年总共有：" <<month<< "个月" << endl;
	system("pause");
	return 0;
}