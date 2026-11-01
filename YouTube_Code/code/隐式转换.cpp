#include<iostream>
class Entity
{
private:
	std::string m_name;
	int m_age;
public:
	Entity(const std::string& name) :m_name(name),m_age(-1) {};
	Entity(int age) :m_name("Unknown"), m_age(age) {};
void getname()
{
	std::cout << m_name << std::endl;
}
void getage()
{
	std::cout << m_age << std::endl;
}
};
int main()
{
	Entity e("sb");
	e.getname();
	e.getage();
	system("pause");
	return 0;
}