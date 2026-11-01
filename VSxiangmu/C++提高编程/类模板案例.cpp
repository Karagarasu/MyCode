#include<iostream>
#include"myarray.hpp"
using namespace std;
void printintarray(myarray<int>&arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << endl;;
	}
}
void test01()
{
	myarray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.push_back(i);
	}
	cout << "arr1的打印输出为：" << endl;
	/*myarray<int> arr2(arr1);
	myarray<int> arr3(100);
	arr3 = arr1;*/
	printintarray(arr1);
	cout << "arr1容量：" << arr1.getcapacity() << endl;
	cout << "arr1大小：" << arr1.getsize() << endl;
	cout << "arr2的打印输出为：" << endl;

	myarray<int>arr2(arr1);
	printintarray(arr2);
	//尾删
	arr2.pop_back();
	cout << "arr2尾删后：" << endl;
	cout << "arr2容量：" << arr2.getcapacity() << endl;
	cout << "arr2大小：" << arr2.getsize() << endl;


}
//测试自定义数据类型
class person
{
public:
	person() {};
	person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
void printpersonarray(myarray<person>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << "姓名：" << arr[i].m_name << "年龄：" << arr[i].m_age << endl;
	}
}
void test02()
{
	myarray<person>arr(10);
	person p1("孙悟空",999 );
	person p2("韩信",20 );
	person p3("妲己", 200);
	person p4("赵云",25);
	person p5("安其拉",30 );
	//将数据插入到数组中
	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);
	//打印数组
	printpersonarray(arr);

	//输出容量

	cout << "arr容量：" << arr.getcapacity() << endl;
	//输出大小
	cout << "arr大下：" << arr.getsize() << endl;

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}