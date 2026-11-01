#include<iostream>
#include<deque>
using namespace std;
/*
deque.empty();判断容器是否为空
deque.size();返回容器中的元素个数
deque.resize(num);重新指定容器的长度为num若容器变长则以默认值填充新位置
如果容器变短 则末尾超出容器长度的元素被删除
deque.resize(num,elem); 重新指定容器的长度为num若容器变长则以elem填充新位置
如果容器变短 则末尾超出容器长度的元素被删除
*/
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";
	}cout << endl;
}
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);
	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl;
		//deque没有容量概念
	}
	//重新指定大小
	//d1.resize(15);
	//printdeque(d1);
	d1.resize(15, 1);
	printdeque(d1);
	d1.resize(5);
	printdeque(d1);
}
int main()
{
	test01();
	system("pause");
	return 0;
}