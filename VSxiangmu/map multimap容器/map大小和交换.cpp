#include<iostream>
#include<map>
using namespace std;
/*
size();返回容器中元素的数目
empty();判断容器是否为空
swap(st);交换两个集合容器
*/
void printmap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first<<" "<<(*it).second << " ";
	}
	cout << endl;
}
void printmap(map<int, int>& m, map<int, int>& m2)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: "<<(*it).first << " value: " << (*it).second << "\n";
	}
	cout << "\n";
	for (map<int, int>::iterator it2 = m2.begin(); it2 != m2.end(); it2++)
	{
		cout << "key: " << (*it2).first << " value: " << (*it2).second << "\n";
	}
	cout << endl;
}
//大小
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空"<<endl;
		cout << "m大小为：" << m.size() << endl;
	}
}
//交换
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30)); 
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "交换前：" << endl;
	printmap(m,m2);
	m.swap(m2);
	cout << "交换后：" << endl;
	printmap(m, m2);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}