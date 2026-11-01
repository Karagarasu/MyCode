#include<iostream>
#include<optional>
#include<fstream>
std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream ifs(filepath);
	if (ifs)
	{
		std::string result;

		ifs.close();
		return result;
	}

	return {};
}
int main()
{

	std::optional<std::string> data = ReadFileAsString("data.txt");
	std::string value = data.value_or("不存在！");
	std::cout << value << std::endl;
	if (data.has_value())//或直接写data
	{
		std::cout << "文件读取成功" << std::endl;
	}
	else
	{
		//std::string& string = *data;
		std::cout << "文件无法打开" << std::endl;
	}
	system("pause");
	return 0;
}