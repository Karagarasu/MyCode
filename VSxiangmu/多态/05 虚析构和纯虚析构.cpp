#include<iostream>
#include<string>
using namespace std;
//虚析构和纯虚析构
class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	virtual void speak() = 0;//纯虚函数
	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal虚析构函数调用" << endl;
	}*/
	//纯虚析构 需要声明也需要实现
	//如果无纯虚函数 有了纯虚析构后 这个个类也属于抽象类 无法实例化对象
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
};
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name =new string(name);
	}
	void speak()
	{
		cout <<*m_Name << "小猫在说话" << endl;
	}
	string* m_Name;
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时不会调用子类中析构函数 导致子类如果有堆区属性 出现内存泄露
	delete animal;
}
int main()
{
	test01();
	system("pause");
	return 0;
}