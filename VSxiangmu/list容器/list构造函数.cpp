#include<iostream>
#include<list>
using namespace std;
/*
list<T> lst; list采用模板类实现 对象的默认构造形式
list(beg,end); 构造函数将[beg,end)区间中的元素拷贝给本身
list(n,elem); 构造函数将ngeelem拷贝给本身
list(const list &lst);拷贝构造
*/
void printlist( const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	//遍历
	printlist(l1);

	list<int> l2(l1.begin(), l1.end());
	printlist(l2);

	list<int>l3(l2);
	printlist(l3);
	list<int>l4(10, 1000);
		printlist(l4);
}
int main()
{
	test01();
	system("pause");
	return 0;
}