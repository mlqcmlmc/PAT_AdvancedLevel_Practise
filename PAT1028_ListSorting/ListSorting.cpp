#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"stdio.h"
using namespace std;
struct StuRecord
{
	long int ID;
	string name;
	int grade;
};


bool cmp1(StuRecord stu1, StuRecord stu2)
{
	return stu1.ID < stu2.ID;
}
bool cmp2(StuRecord stu1, StuRecord stu2)
{
	if (stu1.name != stu2.name)
	{
		return stu1.name < stu2.name;
	}
	else
	{
		return stu1.ID < stu2.ID;
	}
}
bool cmp3(StuRecord stu1, StuRecord stu2)
{
	if (stu1.grade != stu2.grade)
	{
		return stu1.grade < stu2.grade;
	}
	else
	{
		return stu1.ID < stu2.ID;
	}
}

int main()
{
	long int N;
	int C;
	cin >> N >> C;
	vector<StuRecord> records;
	StuRecord temp_record;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp_record.ID);
		cin >> temp_record.name;
		scanf("%d", &temp_record.grade);

		records.push_back(temp_record);
	}
	if (C == 1)
	{
		sort(records.begin(), records.end(), cmp1);
	}
	else if (C == 2)
	{
		sort(records.begin(), records.end(), cmp2);
	}
	else
	{
		sort(records.begin(), records.end(), cmp3);
	}
	for (int i = 0; i < N; ++i)
	{
		printf("%06d %s %d\n", records[i].ID, records[i].name.c_str(), records[i].grade);
	}
	return 0;
}