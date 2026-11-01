#pragma once
#include"Identity.hpp"
class Teacher :public Identity
{
public:
	Teacher();//默认构造
	Teacher(int empId, string name, string pwd);//有参构造（职工编号，姓名，密码）
	void operMenu();
	void showAllOrder();//查看所有预约
	void validOrder();//审核预约
	int m_empId;//教师编号
};