#pragma once
#include<string>
#include<iostream>
#include "worker.h"
using namespace std;
class Manager:public Worker //经理类
{
public:
	//构造函数
	Manager(int id, string name, int dId);
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};