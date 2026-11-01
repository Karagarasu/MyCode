#pragma once
#include<iostream>
#include"speaker.h"
#include<vector>
#include<map>
#include<random>
#include<deque>
#include<numeric>
#include<fstream>
#include<ctime>
//设计演讲管理类
class SpeechManager
{
public:
	SpeechManager();
	void show_Menu();
	void ExitSpeechManager();
	~SpeechManager();
	//初始化容器和属性
	void initSpeech();
	//创建12名选手
	void createSpeaker();
	std::vector<int>v1;//保存第一轮比赛选手编号容器
	std::vector<int>v2;//第一轮晋级选手编号容器
	std::vector<int>vVictory;//胜出前三名选手编号容器
	std::map<int, Speaker>m_Speaker;//存放编号以及对应具体选手容器
	int m_Index;//存放比赛轮数
	void startSpeech();//开始比赛 比赛整个流程控制函数
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord(bool tag=false);
	//文件为空的标志
	bool fileIsEmpty;
	//往届记录
	std::map<int, std::vector<std::string>> m_Record;
	//显示往届得分
	void showRecord();
	//清空记录
	void clearRecord();
};