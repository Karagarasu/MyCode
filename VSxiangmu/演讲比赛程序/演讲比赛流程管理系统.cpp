#include"speechManager.h"
//#include"speaker.h"
int main()
{
	//随机数种子
	//srand((unsigned int)time(NULL));
	SpeechManager sm;
	//测试12名选手创建
	/*for (std::map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		std::cout << "选手编号：" << it->first << " 姓名：" << it->second.m_Name << " 分数：" << it->second.m_Score[0] << std::endl;
	}*/
	int choice=0;
	while (true)
	{
		sm.show_Menu();
		std::cout << "请输入您的选择：" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届比赛记录
			//sm.loadRecord();
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.ExitSpeechManager();
			break;
		default://清屏
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}