//题目不难，关键是要看懂小人和愚人的定义
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Person
{
    int id;
    int virtue;
    int talent;
    int total;
};
bool Compare(const Person& lhs, const Person& rhs)
{
    if (lhs.total!=rhs.total)
    {
        return lhs.total > rhs.total;
    }
    else if (lhs.virtue!=rhs.virtue)
    {
        return lhs.virtue > rhs.virtue;
    }
    else
    {
        return lhs.id < rhs.id;
    }

}
int main()
{
    int N, lower_, high_;
    scanf("%d %d %d", &N, &lower_, &high_);
    vector<Person> sages;
    vector<Person> nobleman;
    vector<Person> foolman;
    vector<Person> smallman;
    Person temp;
    int toal_person = 0;
    for (int i = 0; i < N; ++i)
    {

        scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
        if (temp.talent >= lower_&&temp.virtue >= lower_)
        {
            ++toal_person;
            temp.total = temp.talent + temp.virtue;
            if (temp.virtue >= high_&&temp.talent >= high_)
            {
                sages.push_back(temp);
            }
            else if (temp.virtue >= high_&&temp.talent < high_)
            {
                nobleman.push_back(temp);
            }
            else if (temp.virtue < high_&&temp.talent < high_&&temp.virtue>=temp.talent)
            {
                foolman.push_back(temp);
            }
            else 
            {
                smallman.push_back(temp);
            }
        }
    }
    sort(sages.begin(), sages.end(), Compare);
    sort(nobleman.begin(), nobleman.end(), Compare);
    sort(foolman.begin(), foolman.end(), Compare);
    sort(smallman.begin(), smallman.end(), Compare);

    printf("%d\n", toal_person);
    for (int i = 0; i < sages.size(); ++i)
    {
        printf("%d %d %d\n", sages[i].id, sages[i].virtue, sages[i].talent);
    }
    for (int i = 0; i < nobleman.size(); ++i)
    {
        printf("%d %d %d\n", nobleman[i].id, nobleman[i].virtue, nobleman[i].talent);
    }
    for (int i = 0; i < foolman.size(); ++i)
    {
        printf("%d %d %d\n", foolman[i].id, foolman[i].virtue, foolman[i].talent);
    }
    for (int i = 0; i < smallman.size(); ++i)
    {
        printf("%d %d %d\n", smallman[i].id, smallman[i].virtue, smallman[i].talent);
    }
    return 0;
}
