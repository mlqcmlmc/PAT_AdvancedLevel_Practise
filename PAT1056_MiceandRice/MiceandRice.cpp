#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int NP, NG;
    cin >> NP >> NG;
    vector<int> weights(NP);
    for (int i = 0; i < NP;++i)
    {
        scanf("%d", &weights[i]);
    }
    vector<int> order(NP);
    for (int i = 0; i < NP; ++i)
    {
        scanf("%d", &order[i]);
    }
    vector<int> next_turn;
    vector<int> ranks(NP);
    int groups = NP / NG + (NP%NG == 0 ? 0 : 1) ;//每局的组数
    int max_eachgroup = -1;
    int max_index;
    for (int i = 0; i < groups;++i)
    {
        max_eachgroup = -1;
        for (int j = i*NG; j < NP&&j < (i + 1)*NG; ++j)
        {
            ranks[j] = groups + 1;
            if (weights[order[j]]>max_eachgroup)
            {
                max_eachgroup = weights[order[j]];
                max_index = order[j];
            }
        }
        next_turn.push_back(max_index);
    }
    while (next_turn.size() != 1)
    {
        groups = groups / NG + (groups%NG == 0 ? 0 : 1);
        vector<int> temp_next_turn;
        for (int i = 0; i < groups; ++i)
        {
            max_eachgroup = -1;
            for (int j = i*NG; j < next_turn.size()&&j < (i + 1)*NG; ++j)
            {
                ranks[next_turn[j]] = groups + 1;
                if (weights[next_turn[j]]>max_eachgroup)
                {
                    max_eachgroup = weights[next_turn[j]];
                    max_index = next_turn[j];
                }
            }
            temp_next_turn.push_back(max_index);
        }
        next_turn = temp_next_turn;
    }
    ranks[next_turn[0]] = 1;
    if (NP!=0)
    {
        printf("%d", ranks[0]);
        for (int i = 1; i < NP;++i)
        {
            printf(" %d", ranks[i]);
        }
    }
    return 0;
}


