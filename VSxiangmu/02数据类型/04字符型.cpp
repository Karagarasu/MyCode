#include<iostream>
using namespace std;
int main() {
	//1字符型变量创建方式
	char ch = 'a';
	cout << ch << endl;
	//2字符型变量所占内存大小
	cout <<"char字符型变量所占内存：" << sizeof(char) << endl; //1字节
	//3字符型变量常见错误
	//char ch2 = "b";错误，创建字符型变量不能用双引号，用单引号
	//char ch2 = 'abcdef';错误，创建字符型变量时，单引号内只能有一个字符
	//4字符型变量对应ASCII编码    a对应97 A对应65
	cout << (int)ch << endl;//输出97
	char ch2 = 'b';
	cout << (int)ch2 << endl;//输出98
	char ch3 = 'A';
	cout << (int)ch3 << endl;//输出65
	system("pause");
	return 0;
}