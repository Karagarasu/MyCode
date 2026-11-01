#include<iostream>
#include<set>
using namespace std;
/*
size();返回容器中的元素的数目
empty();判断容器是否为空
swap(st);交换两个集合容器
*/
//大小
void printset(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	//打印容器
	printset(s1);
	//判断是否为空
	if (s1.empty())
	{
		cout << "s1为空"<<endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}
//交换
void test02()
{
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int>s2;
	//插入数据
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "交换前：" << endl;
	printset(s1);
	printset(s2);
	cout << "交换后：" << endl;
	s1.swap(s2);
	printset(s1);
	printset(s2);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}