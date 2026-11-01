#pragma once
#include<iostream>
#include<fstream>
#include"globalFile.hpp"
#include<vector>
#include<algorithm>
#include"computerRoom.hpp"
#include"orderFile.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
class Identity//身份抽象类
{
public:
	//操作菜单
	virtual void operMenu() = 0;
	string m_Name;
	string m_Pwd;
};