#include<iostream>
using namespace std;
//标识符命名规则
//标识符不可以是关键字
//标识符由字母，数字，下划线，构成
//标识符第一个字符只能是字母/下划线
//标识符区分大小写
int main() {
	//int int = 10; 错误的，标识符不可以是关键字
	int abc = 10;
	int _abc = 20;
	int _123abc = 30;
	//int 123abc = 40; 错误的，标识符第一个字符只能是字母/下划线
	int aaa = 100;
	//cout << AAA <<endl; 错误的，标识符区分大小写
	//建议：给变量起名，最好能做到见名知意
	/*int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	*/
	int a = 10;
	int b = 20;
	int c = a + b;
	cout << c << endl;
	system("pause");
	return 0;
}