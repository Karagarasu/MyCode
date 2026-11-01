#include<iostream>
#include<map>
using namespace std;
/*
map容器 构造和赋值

*/
void printmap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= "<<(*it).first << " value= " << it->second << endl;
	}
	cout << endl;
}
void test01()
	{
	map<int, int> m; //创建map容器 按key排序
	m.insert(pair<int, int>(1, 10));//匿名对组
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printmap(m);
	//拷贝构造
	map<int, int>m2(m);
	printmap(m2);
	//赋值
	map<int, int>m3;
	m3 = m2;
	printmap(m3);
	}
int main()
{
	test01();
	system("pause");
	return 0;
}