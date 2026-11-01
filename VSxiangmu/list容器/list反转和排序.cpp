#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
/*
函数原型
reverse();反转链表
sort();链表排序
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
	//反转
	list<int>l1;
	l1.push_back(20);
	l1.push_back(10); 
	l1.push_back(50);
	l1.push_back(40);
	l1.push_back(30);
	cout << "反转前：" << endl;
	printlist(l1);
	//反转
	cout << "反转后："<<endl;
	l1.reverse();
	printlist(l1);
}
//排序
bool mycompare(int v1,int v2)
{
	//降序 就让第一个数大于第二个数
	return v1 > v2;
}
void test02()
{
	list<int>l1;
	l1.push_back(20);
	l1.push_back(10);
	l1.push_back(50);
	l1.push_back(40);
	l1.push_back(30);
	//排序
	cout << "排序前：" << endl;
	printlist(l1);
	//sort(l1.begin(), l1.end());//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器 内部会提供对应一些算法
	l1.sort();//默认排序规则 从小到大 升序
	cout << "排序后：" << endl;
	printlist(l1);
	l1.sort(mycompare);
	printlist(l1);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}