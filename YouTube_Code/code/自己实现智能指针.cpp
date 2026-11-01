#include<iostream>
template<typename T>
class 智能指针
{
private:
	T* ptr;
public:
	智能指针(T*外部指针):ptr(外部指针)
	{

	}
	~智能指针()
	{
		delete ptr;
	}
};
class 对象
{
public:
	对象()
	{
		std::cout << "创建了对象！" << std::endl;
	}
	~对象()
	{
		std::cout << "销毁了对象！" << std::endl;
	}
};
int main()
{
	{
		对象* 对象指针 = new 对象();
		智能指针 智能指针(对象指针);
	}
	system("pause");
	return 0;
}