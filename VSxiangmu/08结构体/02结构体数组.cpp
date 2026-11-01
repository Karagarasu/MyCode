#include<iostream>
#include<string>
using namespace std;
//结构体数组
//1、定义一个结构体
struct Student {
	//姓名
	string name;
	//年龄
	int age;
	//分数
	float score;
};
int main() {
//2、创建结构体数组
	struct Student stuArry[3] =
	{   {"张三",18,100},
		{"李四",28,99},
		{"王五",38,66}
	};
//3、给结构体数组中的元素赋值
	stuArry[2].name = "赵六";
	stuArry[2].age = 80;
	stuArry[2].score = 60;
//4、遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << " 姓名： " 
			 << stuArry[i].name 
			 << " 年龄： " << stuArry[i].age 
			 << " 分数： " << stuArry[i].score << endl;
	}
	system("pause");
	return 0;
}