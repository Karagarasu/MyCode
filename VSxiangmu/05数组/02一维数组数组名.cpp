#include<iostream>
using namespace std;
int main() {
	//数组名用途
	//1、可以通过数组名统计整个数组占用内存大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用的内存空间为：" << sizeof(arr) << endl;
	cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
	cout << "数组中元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	//2、可以通过数组名查看数组首地址
	cout << "数组的首地址为：" << (long long)arr << endl;
	cout << "数组中第一个元素地址为：" << (long long) & arr[0] << endl;
	cout << "数组中第二个元素地址为：" << (long long)&arr[1] << endl;
	//数组名是常量，不可赋值 例如 arr=100; 错误
	system("pause");
	return 0;
}