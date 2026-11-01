#include<iostream>
using namespace std;
int main() {
	//指针所占用的内存
	int a = 10;
	/*int * p;
	p = &a;*/
	int* p = &a;                                       
	cout << "sizeof (p) =" << sizeof(p) << endl;//无论什么类型指针在32位系统下占4字节内存 
	cout << "sizeof (int *) =" << sizeof(int *) << endl;//无论什么类型指针在64位系统下占8字节内存
	cout << "sizeof (float *) =" << sizeof(float*) << endl;
	cout << "sizeof (double *) =" << sizeof(double*) << endl;
	cout << "sizeof (char *) =" << sizeof(char*) << endl;
	system("pause");
	return 0;
}