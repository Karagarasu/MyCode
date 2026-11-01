#include<iostream>
#include<deque>
using namespace std;
/*
deque& operator=(const deque &deq);重载等号操作符
assign(beg,end);将[beg，end)区间中的数据拷贝赋值给本身
assign(n,elem);将n个elem拷贝赋值给本身
*/
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);
	//operator=赋值
	deque<int>d2;
	d2 = d1;
	printdeque(d2);
	//assign
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printdeque(d3);
	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);
}
int main()
{
	test01();
	system("pause");
	return 0;
}