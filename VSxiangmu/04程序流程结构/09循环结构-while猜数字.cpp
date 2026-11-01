#include<iostream>
//time系统时间头文件包含
#include<ctime>
using namespace std;
int main() {
	//添加随机数种子，作用利用当前系统时间生产，防止每次随机数都一样
	srand((unsigned int)time(NULL));
	//1、系统生成随机数
	int num=rand() % 100+1;//生成0+1~99+1随机数
	//2、玩家进行猜测
	cout << "请输入" << endl;
	int val = 0;//玩家输入的数据
	while(true)
	{
	cin >> val;
	//3、判断玩家的猜测
	//猜错则提示猜的结果，过大过小，返回第二步
	if (val > num)
	{
		cout << "猜测过头" << endl;
	}
	else if (val < num)
	{
		cout << "猜测过小" << endl;
	}
	else
	{
		cout << "恭喜您猜对了" << endl;
		//猜对则退出
		break;
	}
	
	}
	system("pause");
	return 0;
}