#include<iostream>
#include<list>
using namespace std;
/*
front();返回第一个元素
back();返回最后一个元素
*/
void test01()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	//l1[0]; 不可以用中括号访问list容器中的元素
	//l1.at(0); 不可以用at访问
	//原因是：list是链表 不是用连续的线性空间存储数据 迭代器也是不支持随机访问的
	cout << "第一个元素为：" << l1.front() << endl;
	cout << "最后一个元素为：" << l1.back() << endl;
	//验证迭代器是不支持随机访问的
	list<int>::iterator it = l1.begin();
	it=it++;//支持双向 ++ --
	//it=it+1;错误，不支持随机访问
}
int main()
{
	test01();
	system("pause");
	return 0;
}