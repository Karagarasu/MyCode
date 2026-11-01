#include<iostream>
#include<array>
//int size = 5;
	////int array[size]; 报错，这必须是一个在编译时已知的常量，因为编译器必须知道栈上这块内存分配的大小
	//int array[5];
	//int* heapArray = new int[size];
	//delete[] heapArray;
	/*std::array<int, 10> collection;
	collection.size();
	for (auto i = 0; i <collection.size(); i++)
	{
		std::cout << collection[i] << std::endl;;
	}*/
template<typename T,size_t S>
class Array
{
public:
	//Array(int size)
	//{
	//	//m_Data = (int*)alloca(size * sizeof(int));
	//}
	constexpr size_t Size() const
	{
		return S;
	}
	T& operator[](size_t index)
	{
		/*if (!(index < S))
		{
			__debugbreak();
		}*/
		return m_Data[index];
	}
	const T& operator[]  (size_t index)const
	{
		return m_Data[index];
	}
	T* Data()
	{
		return m_Data;
	}
	const T* Data() const
	{
		return m_Data;
	}
private:
	T m_Data[S];
};
int main()
{
	int size = 5;
	Array<std::string,2> data;
	data[0] = "Cherno";
	data[1] = "C++";
	//static_assert(data.Size() < 10, "Size is too latge!");
	//Array<std::string, data.Size()> newArray;
	//const auto& arrayReference = data;
	//memset(&data[0], 0, data.Size() * sizeof(int));
	//data[1] = 5;
	//data[4] = 8;
	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
		//std::cout<< arrayReference[i]<<std::endl;
	}
	/*for (auto& element : data)
	{

	}*/
	system("pause");
	return 0;
}