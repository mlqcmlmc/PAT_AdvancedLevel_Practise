#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "stdio.h"
using namespace std;
struct WealthPeople
{
    string name;
    int age;
    int net_worth;
};
bool cmp(WealthPeople p1, WealthPeople p2)
{
    if (p1.net_worth!=p2.net_worth)
    {
        return p1.net_worth > p2.net_worth;

    }
    if (p1.age != p2.age)
    {
        return p1.age < p2.age;
    }
    return p1.name < p2.name;
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<WealthPeople> wealth_people;
    for (int i = 0; i < N; ++i)
    {
        WealthPeople temp;
        temp.name.resize(9);
        scanf("%s %d %d", &temp.name[0], &temp.age, &temp.net_worth);
        wealth_people.push_back(temp);
    }
    sort(wealth_people.begin(), wealth_people.end(), cmp);
    for (int i = 0; i < K;++i)
    {
        int M, age_min, age_max;
        scanf("%d %d %d", &M, &age_min, &age_max);       
        printf("Case #%d:\n", i + 1);
        int counts = 0;
        for (int j = 0; j < N;++j)
        {
            if (counts>=M)
            {
                break;
            }
            if ((wealth_people[j].age >= age_min) && (wealth_people[j].age<=age_max))
            {
                ++counts;
                printf("%s %d %d\n", wealth_people[j].name.c_str(), wealth_people[j].age, wealth_people[j].net_worth);
            }
        }
        if (counts==0)
        {
            printf("%s\n", "None");
        }
    }
    return 0;
}