#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分
*/
class Person//选手类
{
public:
	Person(string name, int score)
	{
		m_name = name;
		m_score = score;
	}
	string m_name;
	int m_score;
};
void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		//将创建的person对象 放入容器中
		v.push_back(p);
	}
}
//打分
void setscore(vector<Person>&v)
{
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		//将评委的分数 放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  //60~100
			d.push_back(score);
		}
	/*	cout << "选手： " << i->m_name << "打分： " << endl;
		for (deque<int>::iterator di = d.begin(); di != d.end(); di++)
		{
			cout << *di << " ";
		}
		cout << endl;*/
		//排序
		sort(d.begin(), d.end());
		//去除两端
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator di = d.begin(); di != d.end(); di++)
		{
			sum += *di;
		}
		int avg = sum / d.size();
		//将平均分赋值
		i->m_score = avg;
	}
}
void showscore(vector<Person>& v)
{
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "姓名：" << i->m_name << " 平均分：" << i->m_score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person>v;//存放选手容器
	createPerson(v);
	//测试
	/*for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << " 姓名：" << (*i).m_name << " 分数： "<<(*i).m_score<<endl;
	}*/
	//给5名选手打分
	setscore(v);
	//显示最后得分
	showscore(v);
	system("pause");
	return 0;
}