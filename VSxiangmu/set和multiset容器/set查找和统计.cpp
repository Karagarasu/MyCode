#include<iostream>
#include<set>
using namespace std;
/*
函数原型
find(key);查找key是否存在 返回该键的元素的迭代器 若不存在 返回set.end();
cout(key);统计key元素的个数 set容器只返回 0或1
*/
void test01()
	{
	//查找
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator it=s1.find(300);
	if (it != s1.end())
	{
		cout << "找到元素：" << *it << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	}
//统计
void test02()
{
	//查找
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	//统计30的个数
	int num = s1.count(30);
	//对于set而言 统计的结果 非0即1
	cout <<"num=" << num << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}