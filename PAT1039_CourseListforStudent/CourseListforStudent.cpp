#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
#include <string>
#include "stdio.h"
using namespace std;
int main()
{
	int stu_num, course_num;
	map<string, set<int>> students;
	cin >> stu_num >> course_num;
	for (int i = 0; i < course_num;++i)
	{
		int No_course, num;
		string name;
		scanf("%d %d", &No_course, &num);
		for (int j = 0; j < num;++j)
		{
			//cin >> name;
			name.resize(100); //需要预先分配空间
			scanf("%s", &name[0]);
			auto ite = students.find(name);
			if (ite!=students.end())
			{
				ite->second.insert(No_course);
			}
			else
			{
				set<int> temp_set;
				temp_set.insert(No_course);
				students.insert({ name, temp_set });
			}
		}
	}
	for (int i = 0; i < stu_num;++i)
	{
		string name;
		//cin >> name;
		name.resize(100); //需要预先分配空间
		scanf("%s", &name[0]);
		printf("%s %d", name.c_str(), students[name].size());
		auto ite = students[name].begin();
		for (; ite != students[name].end(); ++ite)
		{
			cout << ' ' << *ite;
		}
		cout << endl;
	}
	return 0;
}