#include"Student.hpp"
#include"Teacher.hpp"
#include"manager.hpp"
 //按位与& 按位或| 按位异或^ 取反~ 右移运算符>> 左移运算符<<
//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针 转为子类指针 调用子类里其他接口
		Manager* man = (Manager*)manager;
		short i = 0;
		cin >> i;
		if (i == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (i == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (i == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (i == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void studentMenu(Identity*& student)//进入学生的子菜单界面
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();
		auto stu = (Student*)student;
		short select=0;
		cin >> select;
		switch (select)
		{
		case 1://申请预约
		{
			stu->applyOrder();
			break;
		}
		case 2://查看自身预约
		{
			stu->showMyOrder();
			break;
		}
		case 3://查看所有人预约
		{
			stu->showAllOrder();
			break;
		}
		case 4://取消预约

		{
			stu->cancelOrder();
			break;
		}
		default://注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = static_cast<Teacher*>(teacher);
		short select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();//查看所有预约
		}
		else if (select == 2)
		{
			tea->validOrder();//审核预约
		}
		else
		{
			delete teacher;
			cout << "注销成功！" << Endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能
void LoginIn(string fileName, short type)//操作文件名 操作身份类型
{
	Identity* person = NULL;//父类指针 用于指向子类对象
	//读文件
	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	short id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//老师
	{
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	short fid;//从文件中读取的id号
	string fname;//从文件中读取
	string fpwd;//从文件中获取的密码
	switch (type)
	{
	case 1:
	{
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生的验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
		break;//学生
	case 2:
	{
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师的验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
		break;//教师
	case 3://管理员
	{
		while ( ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员的验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
		break;
	default:
		break;
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select=0;
	while(true)
	{ 
	cout << "==================== 欢迎来到机房预约系统 ====================" << endl;
	cout << endl << "请输入你的身份" << endl;
	cout << "1.学生代表" << endl;
	cout << "2.老师" << endl;
	cout << "3.管理员" << endl;
	cout << "0.退出" << endl;
	cout << "请输入你的选择：";
	cin >> select;
	switch (select)
	{
	case 1://学生
		LoginIn(STUDENT_FILE, select);
		break;
	case 2://老师
		LoginIn(TEACHER_FILE, select);
		break;
	case 3://管理员
		LoginIn(ADMIN_FILE, select);
		break;
	case 0://退出
		cout << "欢迎下次使用！" << endl;
		system("pause");
		exit(0);
	default:
		cout << "输入有误，请重新选择！" << endl;
		system("pause");
		system("cls");
		break;
	}
	}
	system("pause");
	return 0;
}