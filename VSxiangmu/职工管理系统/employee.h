//普通员工文件
#include "worker.h"
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);//构造函数
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};