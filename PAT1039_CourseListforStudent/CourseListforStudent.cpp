#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include "stdio.h"
using namespace std;

//巧用数组，将string转换为int，会很快

int hashName(const char *name){
    return (name[0] - 'A') * 26 * 26 * 10\
        + (name[1] - 'A') * 26 * 10\
        + (name[2] - 'A') * 10\
        + (name[3] - '0');
}
int main()
{
	int stu_num, course_num;
    char name[5];
    vector<set<int>> students;
    students.resize(26 * 26 * 26 * 10 + 1);
	cin >> stu_num >> course_num;    
	int No_course, num;
	for (int i = 0; i < course_num;++i)
	{		
		scanf("%d %d", &No_course, &num);
		for (int j = 0; j < num;++j)
		{
			scanf("%s", name);
            int int_name = hashName(name);
            students[int_name].insert(No_course);
		}
	}
	for (int i = 0; i < stu_num;++i)
	{
		scanf("%s", name);
        int int_name = hashName(name);
        printf("%s %d", name, students[int_name].size());
        set<int>::iterator ite = students[int_name].begin();
        for (; ite != students[int_name].end(); ++ite)
		{
            cout << ' ' << *ite;
		}
		cout << endl;
	}
	return 0;
}