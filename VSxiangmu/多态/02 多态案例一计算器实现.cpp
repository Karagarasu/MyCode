#include<iostream>
#include<string>
using namespace std;
//分别利用普通写法和多态技术实现计算器

//普通写法
class Calculator
{
public:
	short getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if(oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//想扩展新功能要修改源码
		//在真实开发中 提倡 开闭原则：对扩展开放 对修改关闭
		else
		{
			cout << "黑祲的龙根最长最粗" << endl;
		}
	}
	int m_Num1;
	int m_Num2;
};
void test01()
{
	//创建计算器对象
	Calculator c;
	while (true)
	{
		cout << "请输入m_Num1的值" << endl;
		cin >> c.m_Num1;
		cout << "请输入m_Num2的值" << endl;
		cin >> c.m_Num2;
		cout << "请输入操作符（仅限+-*）" << endl;
		string oper;
		cin >> oper;
		cout << c.m_Num1 << oper << c.m_Num2 << "=" << c.getResult(oper) << endl;
		cout << "敲回车外的任意键继续并清除控制台，输入“退出”则退出" << endl;
		string CIN;
		cin >> CIN;
		if (CIN == "退出")
		{
			break;
		}
		system("cls");
	}
}
//利用多态实现计算器
//多态带来的好处：组织结构清晰 可读性强 对于后期和前期扩展以及维护性高
//实现计算器的抽象类
class AbstractCalculator
{
public:
	virtual short getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法的计算器类
class AddCalculator :public AbstractCalculator
{
public:
	short getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	short getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	short getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test02()
{
	//多态使用条件
	//父类指针或引用指向子类对象
	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	/*相当于(*abc).m_Num1 = 10;
	(*abc).m_Num2 = 10;*/
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;
	//减法运算
	abc = new SubCalculator; //只是销毁数据 指针类型没变
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	/*相当于(*abc).m_Num1 = 10;
	(*abc).m_Num2 = 10;*/
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "-" << abc->getResult() << endl;
	delete abc;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}