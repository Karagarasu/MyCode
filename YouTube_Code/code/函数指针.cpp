#include <iostream>
#include<vector>
template<typename N>
using FuncName = void(*)(N);
template<typename T>
void ForEach(std::vector<T>& vector, FuncName<int> func)
{
	for (int values : vector)
		func(values);
}
int main()
{
	std::vector<int> ve = { 1,2,3,4,5,6,9 };
	ForEach(ve, [](int vlaues) {std::cout << vlaues << std::endl; });
	std::cin.get();
	return 0;
}