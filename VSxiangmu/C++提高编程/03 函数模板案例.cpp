#include<iostream>
using namespace std;
//实现通用的 对数组进行排序的函数
//规则 从大到小 算法 选择排序
//测试 char数组 int数组
// 交换模板
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//排序算法
template<typename T>
void mysort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j]) //认定的最大值 比 遍历出的数值小 说明 j才是真正的最大值
				max = j;
		}
		if (max != i)
		{//交换max和i
			myswap(arr[max], arr[i]);
		}
	}
}
//提供打印数组模板
template<typename T>
void printarray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void test01()
{
	//测试cahr数组
	char chararr[] = "badcfe";
	int num = sizeof(chararr) / sizeof(char);
	mysort(chararr, num);
	printarray(chararr, num);
}
void test02()
{
	//测试int数组
	int intarr[] = { 7,5,1,3,9,2,4,6,8 };
	int num = sizeof(intarr) / sizeof(int);
	mysort(intarr, num);
	printarray(intarr, num);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}