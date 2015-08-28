#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "stdio.h"
using namespace std;
int main()
{
    string name;
    name.resize(5);
    int N, M;
    cin >> N >> M;
    vector<set<string>> courses;
    courses.resize(M);
    for (int i = 0; i < N; ++i)
    {
        int course_num;
        scanf("%s %d", &name[0], &course_num);
        for (int j = 0; j < course_num; ++j)
        {
            int course;
            scanf("%d", &course);
            courses[course-1].insert(name);
        }
    }
    for (int i = 0; i < M; ++i)
    {
        printf("%d %d\n", i + 1, courses[i].size());
        for (auto beg = courses[i].begin(), end = courses[i].end(); beg != end; ++beg)
        {
            cout << *beg << endl;
        }
    }
    return 0;
}