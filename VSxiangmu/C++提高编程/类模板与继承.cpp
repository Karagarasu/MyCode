#include<iostream>
using namespace std;
//类模板与继承
template<typename T>
class base
{

	T m;
};
//class son :public base //错误 必须要知道父类中T类型 才能继承给子类
class son:public base<int>
{

};
void test01()
{
	son s1;
}
//如果想灵活指定父类中T类型 子类也需要编成类模板
template<typename T1,typename T2>
class son2 :public base<T2>
{
public:
	son2()
	{
		cout << "T2:" << typeid(T2).name() << endl;
		cout << "T1:" << typeid(T1).name() << endl;
	}
	T1 obj;
};
void test02()
{
	son2<int, char>s2;
}
int main()
{
	test02();
	system("pause");
	return 0;
}