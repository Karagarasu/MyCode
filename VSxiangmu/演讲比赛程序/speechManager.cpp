#include"speechManager.h"
SpeechManager::SpeechManager()
{
	initSpeech();
	//创建12名选手
	createSpeaker();
	//加载往届记录
	loadRecord();
}
void SpeechManager::show_Menu()
{
	system("cls");
	std::cout << "*************************************" << std::endl;
	std::cout << "************* 欢迎参加演讲比赛 ******" << std::endl;
	std::cout << "************* 1.开始演讲比赛 ********" << std::endl;
	std::cout << "************* 2.查看往届记录 ********" << std::endl;
	std::cout << "************* 3.清空比赛记录 ********" << std::endl;
	std::cout << "************* 0.退出比赛程序 ********" << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << std::endl;
}
void SpeechManager::ExitSpeechManager()
{
	std::cout << "欢迎下次使用！" << std::endl;
	system("pause");
	exit(0);
}
void SpeechManager::initSpeech()
{
	//容器都为空
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Index = 1;
	m_Record.clear();//将记录的容器 也清空
}
//创建12名选手
void SpeechManager::createSpeaker()
{
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		std::string name = "选手";
		name += nameSeed[i];
		//创建具体选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//创建选手编号 并且放到v1容器中
		v1.push_back(i + 10001);
		//选手编号以及对应选手 放入map容器中
		m_Speaker.insert(std::make_pair(i + 10001, sp));
	}
}
void SpeechManager::startSpeech()//开始比赛 比赛整个流程控制函数
{
	//重新初始化比赛数据（防止重复开始导致晋级人数累加）
	initSpeech();
	//创建12名选手
	createSpeaker();

	//第一轮开始比赛
	//抽签
	speechDraw();
	//比赛
	speechContest();
	//显示晋级结果
	showScore();
	//（后续：可以在这里增加第二轮流程并保存记录）
	//第二轮开始比赛
	m_Index++;
	//抽签
	speechDraw();
	//比赛
	speechContest();
	//显示最终结果
	showScore();
	//保存分数到文件中
	saveRecord();
	std::cout << "本届比赛完毕！" << std::endl;
	system("pause");
	system("cls");
}
void SpeechManager::speechDraw()//抽签
{
	std::cout << "第 << " << m_Index << " >> 轮比赛选手正在抽签" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "抽签后演讲顺序如下：" << std::endl; 
	if (m_Index == 1)
	{
		//第一轮
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(v1.begin(), v1.end(),g);
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		//第二轮
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(v2.begin(), v2.end(), g);
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	system("pause");
	std::cout << std::endl;
}
void SpeechManager::speechContest()
{
	std::cout << "---------第" << m_Index << " 轮比赛正式开始---------" << std::endl;
	//准备临时容器 存放小组成绩
	std::multimap<double, int, std::greater<double>>groupScore;
	int num = 0;//用于记录人员的个数 6人一组
	std::vector<int>*v_Src=0;//比赛选手容器
	if (m_Index == 1)
	{
		v_Src = &v1;
	}
	else
	{
		v_Src = &v2;
	}
	//遍历所有选手进行比赛
	for (std::vector<int>::iterator it = v_Src->begin(); it != v_Src->end(); it++)
	{
		num++;
		//评委打分
		std::deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.0f;//600-1000
			//std::cout << score << " ";
			d.push_back(score);
		}//std::cout << std::endl;
			std::sort(d.begin(), d.end(),std::greater<double>());//排序
			d.pop_front();//去除最高分
			d.pop_back();//去除最低分
			double sum = std::accumulate(d.begin(), d.end(), 0.0f);//总分
			double avg = sum / double(d.size());//平均分
			//打印平均分
			//std::cout << "编号：" << *it << " 选手姓名：" << m_Speaker[*it].m_Name << " 获取平均分：" << avg << std::endl;
		//将平均分放入map容器
			m_Speaker[*it].m_Score[m_Index - 1] = avg;
			//将打分数据 放入到临时小组容器中
			groupScore.insert(std::make_pair(avg, *it));//key是得分 value是具体选手编号
			//每六人取出前三名
			if (num % 6 == 0)
			{
				std::cout << "第 " << num / 6 << " 小组比赛名次如下：" << std::endl;
				for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
				{
					std::cout << "编号：" << it->second << " 姓名：" << m_Speaker[it->second].m_Name << " 成绩：" << m_Speaker[it->second].m_Score[m_Index - 1] << std::endl;
				}
				//取走前三名 
				int count = 0;
				for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count<3 ; it++,count++)
				{
					if (m_Index == 1)
					{
						v2.push_back(it->second);
					}
					else
					{
						vVictory.push_back(it->second);
					}
				}
				groupScore.clear();//清空
				std::cout << std::endl;
			}
	}
	std::cout << "-----------------------第 " << m_Index << " 轮比赛完毕！-----------------------" << std::endl;
	system("pause");
}
void SpeechManager::showScore()
{
	std::cout << "-----------------------第 " << m_Index << " 轮晋级选手信息如下：-----------------------" << std::endl;
	std::vector<int>* v;
	if (m_Index==1)
	{
		v = &v2;
	}
	else
	{
		v = &vVictory;
	}
	for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
	{
		std::cout << "选手编号： " << *it << " 姓名：" << m_Speaker[*it].m_Name << " 得分：" << m_Speaker[*it].m_Score[m_Index - 1] << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	system("cls");
	show_Menu();
}
void SpeechManager::saveRecord()
{
	std::ofstream ofs;
	ofs.open("speech.csv",std:: ios::out | std::ios::app);//用追加的方式写文件
	//将每个选手的数据写入到文件中
	for (std::vector<int>::iterator it=vVictory.begin();it!=vVictory.end();it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Name << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << std::endl;
	//关闭文件
	ofs.close();
	std::cout << "记录已经保存" << std::endl;
	//更改文件不为空状态
	fileIsEmpty = false;
}
void SpeechManager::loadRecord(bool tag)
{
	std::ifstream ifs("speech.csv",std::ios::in);//读文件
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		//std::cout << "文件不存在！" << std::endl;
		ifs.close();
		if(tag){}
		else{ system("pause"); }
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//std::cout << "文件为空" << std::endl;
		fileIsEmpty = true;
		ifs.close();
		if(tag){}
		else{ system("pause"); }
		return;
	}
	//文件不为空
	fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符放回
	std::string data;
	int index = 1;
	while (ifs >> data)
	{
		//std::cout << data << std::endl;
		std::vector<std::string>v;//存放9个string的字符串
		/*
10006
选手F
84.15
10010
选手J
83.4625
10003
选手C
80
		*/
		int pos = -1;//查到“,”位置的变量
		int start=0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到
				break;
			}
			std::string temp = data.substr(start, pos - start);
			//std::cout << temp << std::endl;
			v.push_back(temp);
			start = pos + 1;
		}
		m_Record.insert(std::make_pair(index,v));
		index++;
	}
	ifs.close();
	/*for (std::map<int, std::vector<std::string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		std::cout<<" 第 " << it->first<<" 届 " << " 冠军编号：" << it->second[0] << " 名字：" << it->second[1] << " 分数：" << it->second[2] << std::endl;
	}*/
	if(tag){  }
	else{ system("pause"); }
}
void SpeechManager::showRecord()
{
	loadRecord(true);
	if (fileIsEmpty)
	{
		std::cout << "文件不存在，或者记录为空！" << std::endl;
	}
	else
	{
	  for (int i = 0; i < m_Record.size(); i++)
	  {
		std::cout << " 第 " << i+1 << " 届 " << "冠军编号：" << m_Record[i+1][0] << " 得分：" << m_Record[i+1][2] << " "
			<< "亚军编号：" << m_Record[i+1][3] << " 得分：" << m_Record[i+1][5] << " "
			<< "季军编号：" << m_Record[i+1][6] << " 得分：" << m_Record[i+1][8] << std::endl;
	  }
	}
	system("pause");
	system("cls");
}
void SpeechManager::clearRecord()
{
	std::cout << "确认清空(Y/N)？" << std::endl;
	std::string select;
	std::cin >> select;
	if (select == "Y" || select == "y")
	{
		//std::cout << "清空" << std::endl;
		std::ofstream ofs("speech.csv", std::ios::trunc);
		ofs.close();
		initSpeech();
		createSpeaker();
		loadRecord();
		std::cout << "清空成功！" << std::endl;
	}
	else if (select == "N" || select == "n")
	{
		std::cout << "取消操作！" << std::endl;
	}
	else
	{
		std::cout << "输入有误！" << std::endl;
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{

}