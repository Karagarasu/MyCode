#include<iostream>
using namespace std;
//函数的声明
//比较函数，实现两个整形数字进行比较，返回较大值
//提前告诉编译器函数的存在，可以利用函数的声明
int bijiao(int a, int b);//函数的声明 声明可以写多次，定义只能有一次 多次定义则报错
int bijiao(int a, int b);
int bijiao(int a, int b);
//若函数定义在 main（）{...}前，可以不写声明
int bijiao(int a, int b)//如果函数定义在main（）{...}后且未声明函数，则报错
{
	return a > b ? a : b;
}

int main() {
	int a = 10;
	int b = 20;
	cout << bijiao(a, b) << endl;
	system("pause");
	return 0;
}
