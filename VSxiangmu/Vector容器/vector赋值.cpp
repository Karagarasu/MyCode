#include<iostream>
#include<vector>
using namespace std;
/*
函数原型
vector& operator=(const vector &vec);重载等号操作符
assign(beg,end);将[beg，end)区间中的数据拷贝赋值给本身
assign(n,elem);将n个elem拷贝赋值给本身
*/
void printvector(vector<int> &vet)
{
	for (vector<int>::iterator it = vet.begin(); it != vet.end(); it++)
	{
		cout << *it << " ";
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
	printvector(v1);
	//赋值 operator=
	vector<int> v2;
	v2 = v1;
	printvector(v2);
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v3);
	//n个elem 方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	printvector(v4);
}
int main()
{
	test01();
	system("pause");
	return 0;
}