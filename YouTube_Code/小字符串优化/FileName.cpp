#include<iostream>
void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}
int main()
{
	//std::string name = "Cherno Small Str"; 
	std::string name = "C";
	system("pause");
	return 0;
}