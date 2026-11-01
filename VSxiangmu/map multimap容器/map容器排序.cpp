#include<iostream>
#include<map>
using namespace std;
//mapÈİÆ÷ ÅÅĞò
class mycompare
{
public:
	bool operator()(int v1,int v2) const
	{//½µĞò
		return v1 > v2;
	}

};
void test01()
{
	map<int, int,mycompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(5, 50));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	for (map<int, int, mycompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}