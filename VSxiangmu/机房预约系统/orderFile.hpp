#pragma once
#include<iostream>
#include<map>
#include"globalFile.hpp"
#include<fstream>
using std::string;
using std::cout;
using std::endl;
class OrderFile
{
public:
	OrderFile();//构造函数
	//更新预约记录
	void updateOrder();
	//记录的容器 key---记录的条数 value---具体记录的键值对信息
	std::map<int, std::map<std::string, std::string>>m_orderData;
	//预约记录条数
	short m_Size;
	
};
