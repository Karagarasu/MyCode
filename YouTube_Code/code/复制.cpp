#include<iostream>
class String
{
friend std::ostream& operator<<(std::ostream& ost,const String& s);
private:
	char* name;
	unsigned int m_size;
public:
	String(const char* str)
	{
		m_size = strlen(str);
		name = new char[m_size + 1];
		memcpy(name, str, m_size);
		name[m_size ] = 0;
	}
	String(const String & other):m_size(other.m_size)
	{
		name = new char[m_size + 1];
		memcpy(name, other.name, m_size + 1);
		name[m_size] = 0;
	}
	~String()
	{
		delete[]name;
	}
	char& operator[](int a)
	{
		return name[a];
	}
};
std::ostream& operator<<(std::ostream& ost,const String& s)
{
	ost << s.name;
	return ost;
}
int main()
{
	String Person = "Cangye";
	String Second = Person;
	Second[0] = 'a';
	std::cout << Person << std::endl;
	std::cout << Second << std::endl;
	system("pause");
	return 0;
}