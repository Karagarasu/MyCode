#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
返回bool类型的仿函数称为谓词
如果operator（）接受一个参数 那么叫做一元谓词
如果operator（）接受两个参数 那么叫做二元谓词
*/
class greaterfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中有没有大于五的数字
	vector<int>::iterator it=find_if(v.begin(), v.end(), greaterfive());//greaterfive()匿名函数对象
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字为：" << *it << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}