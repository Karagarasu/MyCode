#include<iostream>
using namespace std;
//定义加法函数
int add(int num1, int num2)//num1和num2并没有真实数据 称为 形式参数 即 形参
{
	int sum = num1 + num2;
	return sum;
}
int main() {
	//main函数中调用add函数
	int a = 10;
	int b = 20;
	//函数调用语法：函数名称（参数）
	//a和b称为 实际参数 即 实参
	//当调用函数的时候，实参的值会传递给形参
	int c=add(a, b);
	cout << "c=" << c << endl;
	a = 100;
	b = 500;
	c = add(a, b);
	cout << "c=" << c << endl;
	system("pause");
	return 0;
}