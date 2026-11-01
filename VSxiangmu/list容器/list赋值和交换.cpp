#include<iostream>
#include<list>
using namespace std;
/*
assign(beg.end);将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem);将n个elem拷贝赋值给本身
list & operator=(const list &lst);重载等号操作符
swap(lst);将lst与本身的元素互换
*/
void printlist(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printlist(l1);
	list<int>l2;
	l2 = l1;
	printlist(l2);
	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printlist(l3);
	list<int>l4;
	l4.assign(100, 100);
	printlist(l4);
}
//交换
void test02()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	list<int>l2;
	l2.assign(10, 100);
	cout << "交换前：" << endl;
	printlist(l1);
	printlist(l2);
	l1.swap(l2);
	cout << "交换后：" << endl;
	printlist(l1);
	printlist(l2);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}