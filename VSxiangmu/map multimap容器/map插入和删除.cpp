#include<map>
#include<iostream>
using namespace std;
/*
函数原型：
insert(elem);//在容器中插入元素
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素 返回下一个元素的迭代器
erase(beg,end);//删除区间[beg,end)的所有元素 返回下一个元素的迭代器
erase(key);//删除容器中值为key的元素
*/
void printmap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << "\n";
}
void printmap(map<int, int>& m,map<int,int>&m2)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << "\n";
	for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << "\n";
}

void test01()
{
	map<int, int>m;
	//插入
	//第一种
	m.insert(pair<int, int>(1, 10));
	//第二种
	m.insert(make_pair(2, 20));
	//第三种
	m.insert(map<int, int>::value_type(3, 30));
	//第四种 []不建议插入 可以用key访问到value
	m[4] = 40;
	//cout << m[5] << endl; 会插入0
	cout << m[4] << endl;
	printmap(m);
	//删除
	m.erase(m.begin());
	printmap(m);
	m.erase(3);//按照key删除
	printmap(m);
	//清空
	//m.erase(m.begin(), m.end());
	m.clear();
	printmap(m);
}
int main()
{
	test01();
	system("pause");
	return 0;
}