#include<iostream>
using namespace std;
int main() {
	//整型分类
	//1短整型(-32768到+32767)
	short num1 = 32768;//结果是-32768
	//2整型
	int num2 = 32768;
	//3长整型
	long num3 = 10;
	//4长长整型
	long long num4 = 10;
	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;
	system("pause");
	return 0;
}