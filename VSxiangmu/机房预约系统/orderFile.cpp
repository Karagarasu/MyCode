#include"orderFile.hpp"

OrderFile::OrderFile()
{
	std::ifstream ifs;
	ifs.open(ORDER_FILE, std::ios::in);/* 日期：1 时间段 学号 姓名 机房号  状态                   */
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	m_Size = 0;//预约条数
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << 日期 << endl;
		cout << 时间段 << endl;
		cout << 学号 << endl;
		cout << 姓名 << endl;
		cout << 机房号 << endl;
		cout << 状态 << endl;
		cout << endl;*/
		string key;
		string value;
		std::map<string, string>m;
		short pos=date.find(":");//4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		//cout << "key=" << key << endl;
		//cout << "value=" << value << endl;
		pos = interval.find(":");//4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");//4
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");//4
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomId.find(":");//4
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");//4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//将小map嵌入大map

		m_orderData.insert(std::make_pair(m_Size, m));
		m_Size++;
	}
	ifs.close();
	//测试大map
	/*for(auto it=m_orderData.begin();it!=m_orderData.end();it++)
	{
		cout << "条数为：" << it->first << " value = " << endl;
		for (auto tt = it->second.begin(); tt != it->second.end(); tt++)
		{
			cout << " key = " << tt->first << " value = " << tt->second<<" ";
		}
		cout << endl;
	}*/
}

void OrderFile::updateOrder()//更新预约记录
{
	if (m_Size == 0)
	{
		return;//预约记录0条，直接return
	}
	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << m_orderData[i]["date"] << " ";
		ofs << "interval:" << m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << m_orderData[i]["roomId"] << " ";
		ofs << "status:" << m_orderData[i]["status"] << endl;
	}
	ofs.close();
}