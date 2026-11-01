#include<iostream>
using namespace std;
int main() {
	//1、创建bool数据类型
	bool flag = true;//true代表真
	cout << flag << endl;
	flag = false;
	cout << flag << endl;//false代表假
	//本质上true是1，false是0
	//2、查看bool类型所占内存空间
	cout << "bool类型所占内存空间:" << sizeof(bool) << endl;//1
	system("pause");
	return 0;
}