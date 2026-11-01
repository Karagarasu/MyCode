#include<iostream>
#include<variant>
#include<optional>
enum class ErrorCode
{
	None=0,NotFound=1,NoAccess=2
};
std::variant<std::string, ErrorCode> ReadFileAsString()
{
//	return ErrorCode::NotFound;
	return {};
}
int main()
{
	std::variant<std::string, int>data;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(data) << std::endl;
	data = "Cherno";
	std::cout<<std::get<std::string>(data)<<std::endl;
	if (auto* value = std::get_if<std::string>(&data))
	{
		std::string& v = *value;
	}
	else
	{

	}
	data =2;
	std::cout << std::get<std::string>(data) << std::endl;
	std::cout << std::get<int>(data) << std::endl;
	system("pause");
	return 0;
}