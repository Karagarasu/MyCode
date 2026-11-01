#include"manager.hpp"
#include"Student.hpp"
#include"Teacher.hpp"
Manager::Manager()
{
}//默认构造
Manager::Manager(string name, string pwd)
{//初始化管理员信息
	m_Name = name;
	m_Pwd = pwd;
	initVector();
	//获取机房信息
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	ComputerRoom c;
	while (ifs>>c.m_ComId&&ifs>>c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
	cout << "机房的数量为：" << vCom.size() << endl;
}//有参构造 管理员姓名 密码
void Manager::operMenu()
{
	cout << "欢迎管理员："<<m_Name<<"登录！" << endl;
	cout << "\t\t -----------------------" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看帐号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请选择您的操作：" << endl;
}//选择菜单
void Manager::addPerson() 
{
TAG:
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加老师" << endl;
	};
	string fileName;
	string tip;
	string errortip;
	std::ofstream ofs;
	short select = 0;
	cin >> select;
	switch(select)
	{
	case 1:
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入";
	}
		break;
	case 2:
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工号重复，请重新输入";
	}
		break;
	default:
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
	}
	goto TAG;
	}
	ofs.open(fileName, std::ios::out | std::ios::app);//利用追加方式写文件
	short id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		//initVector(false);
		cin >> id;
		if (checkRepeat(id, select))//有重复
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	//cin >> id;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	initVector();
	system("pause");
	system("cls");
}//添加账号
void printStudent(Student& s)
{
	cout << "学生学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "学生学号：" << t.m_empId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

void Manager::showPerson()
{
Tag: {
	cout << "请选择查看的内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	cout << "3.查看所有师生" << endl;
	}
	int select = 0;//接受用户选择
	cin >> select;
	switch (select)
	{
	case 1://查看学生
	{
		cout << "所有学生信息：" << endl;
		std::for_each(vStu.begin(),vStu.end(),printStudent);
		break;
	}
	case 2://查看老师
	{
		cout << "所有老师信息：" << endl;
		std::for_each(vTea.begin(), vTea.end(), printTeacher);
		break;
	}
	case 3:
	{
		cout << "所有学生信息：" << endl;
		std::for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "所有老师信息：" << endl;
		std::for_each(vTea.begin(), vTea.end(), printTeacher);
		break;
	}
	default:
	{
		cout << "似乎有些错误！" << endl;
		system("pause");
		system("cls");
		goto Tag;
	}
	}
	system("pause");
	system("cls");
}//查看账号
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;
	std::for_each(vCom.begin(), vCom.end(), [](ComputerRoom& v) {cout << "机房号：" << v.m_ComId << " 机房容量：" << v.m_MaxNum<<endl; });
	system("pause");
	system("cls");
}//查看机房信息
void Manager::cleanFile()//清空预约记录
{

	std::ofstream ofs(ORDER_FILE, std::ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector(bool isCout)
{
	vStu.clear();
	vTea.clear();
	//读取学生文件中信息
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	if(isCout)
	{ cout << "当前学生数量为：" << vStu.size() << endl; }
	ifs.close();
	ifs.open(TEACHER_FILE, std::ios::in);
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	if (isCout)
	{ cout << "当前教师数量为：" << vTea.size() << endl; }
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)//学生
	{
		for (auto it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto it = vTea.begin(); it!= vTea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		}
	}
	return false;
}
