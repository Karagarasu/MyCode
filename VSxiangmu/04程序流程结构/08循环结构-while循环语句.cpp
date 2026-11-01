#include<iostream>
using namespace std;
int main() {
	//while循环
	//在屏幕中打印0~9 10个数字
	int num = 0;
	while (num < 10)//()中填入循环条件，一定要避免死循环
	{
		cout << num << endl;
		num++;
	}
	system("pause");
	return 0;
}