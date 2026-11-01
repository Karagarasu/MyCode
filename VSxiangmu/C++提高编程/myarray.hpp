//自己的通用的数组类
#pragma once
#include<iostream>
using namespace std;
template<class T>
class myarray
{
public:
	myarray(int capacity)//有参构造 参数容量
	{
		//cout << "myarray有参构造调用" << endl;
		m_capacity = capacity;
		m_size = 0;
		paddress = new T[m_capacity];
	}
	//拷贝构造
	myarray(const myarray& arr)
	{
		//cout << "myarray拷贝构造调用" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->paddress = arr.paddress;
		this->paddress=new T[arr.m_capacity];//深拷贝
		//将aa中的数据都拷贝
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
	}
	//operator=防止浅拷贝 a=b=c
	myarray& operator=(const myarray& arr)
	{
		//cout << "myarrayoperator=调用" << endl;
		//先判断原来堆区是否有数据 如果有先释放
		if (this->paddress != NULL)
		{
			delete[]this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
			
         }
		//深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->paddress = new T[arr.m_capacity];//深拷贝
		//将aa中的数据都拷贝
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
		return *this;
	}
	//尾插法
	void push_back(const T&val)
	{
		//判断容量是否等于大小
		if (this->m_capacity == this->m_size)
		{
			cout << "大小达到容量上限，插入失败" << endl;
			return;
		}
		this->paddress[this->m_size] = val;//在数组末尾插入数据
		this->m_size++;//更新数组大小
	}
	//尾删法
	void pop_back()
	{
		//让用户访问不到最后一个元素 即为尾删
		if (this->m_size == 0)
		{
			cout << "目前无数据" << endl;
		}
		this->m_size--;
	}
	//通过下标方式访问数组中的元素
	T& operator[](int index)
	{
		return this->paddress[index];
	}
	//返回数组容量
	int getcapacity()
	{
		return m_capacity;
	}
	//返回数组大小
	int getsize()
	{
		return m_size;
	}
	//析构函数
	~myarray()
	{
		if(paddress!=NULL)
		{
			//cout << "myarray析构调用" << endl;
			delete[]paddress;
			paddress = NULL;
		}
	}
private:
	T* paddress;//指针指向堆区开辟的真实数组
	int m_capacity;//数组容量
	int m_size;//数组大小
};