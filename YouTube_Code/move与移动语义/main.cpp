#include<iostream>
class String
{
public:
	String() = default;
	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	String(const String& other)
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other)noexcept
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;
		other.m_Size = 0;
		other.m_Data = nullptr;
	}
	String& operator=(String&& other)noexcept
	{
		printf("Moved!\n");
		if (this != &other)
		{
			delete[] m_Data;
			m_Size = other.m_Size;
			m_Data = other.m_Data;
			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
	}
	~String()
	{
		printf("Destoryed!\n");
		delete m_Data;
	}
	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};
class Entity
{
public:
	Entity(const String& name) :m_Name(name)
	{

	}
	Entity(String&& name) :m_Name(std::move(name))
	{

	}
	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
//	Entity entity("Cherno");
	//entity.PrintName();
	String apple = "Apple";
	String dest=std::move(apple);
	std::cout << "Apple：";
	//String string = "Hello";
	//String dest = (String&&)string;  //相当于
	//String dest((String&&)string);
	//String dest=std::move(string);//更优雅更灵活
	//dest = (std::move(dest));
	apple.Print();
	std::cout << "Dest：";
	dest.Print();
	//dest.operator=(std::move(apple));
	dest=std::move(apple);
	std::cout << "Apple：";
	apple.Print();
	std::cout << "Dest：";
	dest.Print();
	system("pause");
	return 0;
}