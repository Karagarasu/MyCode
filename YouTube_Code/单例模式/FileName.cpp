#include<iostream>
class Random
{
public:
	Random(const Random& other) = delete;
	void operator=(const Random& other) = delete;
	static Random& Get()
	{
		static Random instance;
		return instance;
	}
	static float Float() { return Get().IFloat(); }
private:
	float IFloat()
	{
		return m_RandomGenerator;
	}
	Random() {};
	float m_RandomGenerator = 0.5f;
};
namespace RandomClass
{
	static float s_RandomGenerator = 0.5f;
	static float Float() { return s_RandomGenerator; }
}
int main()
{
	float number= RandomClass::Float();
	std::cout << number << std::endl;
	system("pause");
	return 0;
}