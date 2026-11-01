#include<iostream>
#include<tuple>

std::tuple<std::string,int> CreatePerson()//tuple可以任意多个值 pair是一对2个值
{
	return { "Cherno",24 };
}
int main()
{
	//std::tuple<std::string, int> person= CreatePerson();
	//auto person = CreatePerson();
	//std::string& name=std::get<0>(person);
	//auto name = std::get<0>(person);
	//auto age = std::get<1>(person);       //不够优雅
	//相对优雅
	//std::string name;
	//int age;
	//std::tie(name, age)=CreatePerson();
	//优雅
	auto [name, age] = CreatePerson();//结构化绑定 c++17及以上才有
	std::cout << name;
	return 0;
}