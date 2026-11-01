#include<iostream>
//#if 0
#if YG_Debug==1;
#define LOG(x) std::cout<<x<<std::endl;
#elif defined(YG_Release)
#define LOG(x)
#endif
//#endif
int main()
{
	LOG("Hello");
	system("pause");
}