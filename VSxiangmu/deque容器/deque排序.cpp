#include<iostream>
#include<deque>
#include<algorithm>//标准算法头文件
using namespace std;
/*
sort(iterator beg,iterator end)对beg和end区间内元素进行排序
*/
void printdeque(const deque<int>&d)
{
	for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printdeque(d);
	//排序 默认从小到大 升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序 例如vector
	sort(d.begin(), d.end());
	cout << "排序后：" << endl;
	printdeque(d);
}
int main()
{
	test01();
	system("pause");
	return 0;
}