#include<iostream>
#include<vector>
using namespace std;
/*
函数原型
swap(vec);//将vec与本身的元素互换
*/
void printvector(vector<int>&v)
{
	for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "互换前：" << endl;
	printvector(v1);
	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printvector(v2);
	v1.swap(v2);
	cout << "互换后："<<endl;
	printvector(v1);
	printvector(v2);
}
//实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
	v.resize(3);//重新指定大小
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
	//巧用swap收缩内存
	vector<int>(v).swap(v);
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}