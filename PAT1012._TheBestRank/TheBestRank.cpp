#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
    string id;
    int grade[4];//分别表示A,C,M,E
    int rank_type;
    int rank;
};

//按4门课程分数的排序，降序  
bool cmp0(const Student &s1, const Student &s2)
{
    return s1.grade[0] > s2.grade[0];
}
bool cmp1(const Student &s1, const Student &s2)
{
    return s1.grade[1] > s2.grade[1];
}
bool cmp2(const Student &s1, const Student &s2)
{
    return s1.grade[2] > s2.grade[2];
}
bool cmp3(const Student &s1, const Student &s2)
{
    return s1.grade[3] > s2.grade[3];
}
//对已经根据课程col分降序排好的N个学生的学生序列s,更新其最佳排名,由于可能存在分数相同，排名相同情况，故排名需注意 
void Rank(vector<Student> &stu, int type)
{
    int last_rank = 0;
    for (int i = 0; i < stu.size(); i++)
    {
        if (stu[i].grade[type]<stu[last_rank].grade[type])      //可能存在分数相同，排名相同情况
        {
            last_rank = i;
        }
        if (stu[i].rank>last_rank + 1)
        {
            stu[i].rank_type = type;
            stu[i].rank = last_rank + 1;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<Student> allstu;
    allstu.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> allstu[i].id;
        cin >> allstu[i].grade[1] >> allstu[i].grade[2] >> allstu[i].grade[3];
        allstu[i].grade[0] = (allstu[i].grade[1] + allstu[i].grade[2] + allstu[i].grade[3]) / 3;
        allstu[i].rank_type = 4;
        allstu[i].rank = N;
    }
    sort(allstu.begin(), allstu.end(), cmp0);
    Rank(allstu, 0);
    sort(allstu.begin(), allstu.end(), cmp1);
    Rank(allstu, 1);
    sort(allstu.begin(), allstu.end(), cmp2);
    Rank(allstu, 2);
    sort(allstu.begin(), allstu.end(), cmp3);
    Rank(allstu, 3);
    map<string, Student> allstu_map;
    for (int i = 0; i < N; ++i)
    {
        allstu_map[allstu[i].id] = allstu[i];
    }
    string strid_out;
    char crank_type[4] = { 'A', 'C', 'M', 'E' };
    for (int i = 0; i < M; i++)
    {
        cin >> strid_out;
        auto it = allstu_map.find(strid_out);
        if (it == allstu_map.end())
        {
            cout << "N/A" << endl;
        }
        else
        {
            cout << it->second.rank << ' ' << crank_type[it->second.rank_type] << endl;

        }
    }
    return 0;
}