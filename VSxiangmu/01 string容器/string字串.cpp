#include<iostream>
using namespace std;
/*
函数原型
string substr(int pos=0,int n=npos) const; 返回由pos开始的n个字符组成的字符串
*/
void test01()
{
	string str = "abcdef";
	string substr = str.substr(1, 3);
	cout << "substr=" << substr << endl;
}
//使用操作
void test02()
{
	string email = "lisi@sina.com";
	//从邮件地址中获取用户名信息
	int pos=email.find("@");
	cout << pos << endl;
	string usrname = email.substr(0, pos);
	cout << usrname << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}