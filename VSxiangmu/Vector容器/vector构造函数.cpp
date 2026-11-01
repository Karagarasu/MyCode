#include <iostream>
#include<vector>
using namespace std;
/*
函数原型
vector<T> v;采用模板实现类实现，默认构造函数
vector(v.begin(),v.end()); 将v[v.begin(),v.end())区间中的元素拷贝给本身
vector(n,elem);构造函数将n个elem拷贝给本身
vector(const vector &vec);拷贝构造函数

*/
void printvector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}
void test01()
{
	vector<int>v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printvector(v2);
	//n个elem方式构造
	vector<int>v3(10, 100);
	printvector(v3);
	//拷贝构造
	vector<int>v4(v3);
	printvector(v4);
}
int main()
{
	test01();
	system("pause");
	return 0;
}