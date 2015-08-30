#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "stdio.h"
using namespace std;
int Name2Int(const char *name){
    return (name[0] - 'A') * 26 * 26 * 10\
        + (name[1] - 'A') * 26 * 10\
        + (name[2] - 'A') * 10\
        + (name[3] - '0');
}
char* Int2Name(int name_int)
{
    char* name = new char[5];
    name[4] = '\0';
    name[3] = name_int % 10 + '0';
    name_int = (name_int / 10);
    name[2] = name_int % 26 + 'A';
    name_int = name_int / 26;
    name[1] = name_int % 26 + 'A';
    name_int = name_int / 26;
    name[0] = name_int + 'A';
    return name;
}
int main()
{
    char name[5];
    int N, M;
    cin >> N >> M;
    vector<vector<int>> courses;
    courses.resize(M);
    for (int i = 0; i < N; ++i)
    {
        int course_num;
        scanf("%s %d", name, &course_num);
        int name_int = Name2Int(name);
        for (int j = 0; j < course_num; ++j)
        {
            int course;
            scanf("%d", &course);
            courses[course - 1].push_back(name_int);
        }
    }
    for (int i = 0; i < M; ++i)
    {
        printf("%d %d\n", i + 1, courses[i].size());
        sort(courses[i].begin(), courses[i].end());
        auto beg = courses[i].begin();
        auto end = courses[i].end();
        for (; beg != end; ++beg)
        {
            char* out_name = Int2Name(*beg);
            printf("%s\n", out_name);
        }
    }
    return 0;
}