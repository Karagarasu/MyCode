#include<iostream>
#include<string>
using namespace std;
//const的使用场景
struct student
{
	string name;//姓名
	int age;//年龄
	float score;//分数
};
void printStudent(const student *s) //将函数中的形参改为指针，
                            //可以减少内存空间，而且不会复制新的副本
{
	//s->age = 150; 加入const后，一旦有修改操作就会报错，可以防止误操作
	cout << "姓名：" << s->name << " 年龄：" << s->age << " 分数：" << s->score << endl;
}
int main() {
	//创建结构体变量
	struct student s = { "张三",15,70 };
	//通过函数打印结构体变量的信息
	printStudent(&s);
	cout << "main中张三年龄为：" << s.age << endl;
	system("pause");
	return 0;
}