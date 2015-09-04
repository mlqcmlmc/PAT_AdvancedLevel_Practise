#include <iostream>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;
int weight_[100] = { 0 };
vector<int> trees[100];
long long int S;
vector<vector<int>> paths;
void TreeDFS(int v, int sum, vector<int> vec)
{
    sum += weight_[v];
    vec.push_back(weight_[v]);
    if (trees[v].size()==0)
    {
        if (sum == S)
        {
            paths.push_back(vec);
        }
        return;
    }
    for (int i = 0; i < trees[v].size(); ++i)
    {
        TreeDFS(trees[v][i], sum, vec);
    }
}
bool Compared(vector<int>a, vector<int>b)
{
    if (a.size()==0)
    {
        return false;
    }
    else if (b.size()==0)
    {
        return true;
    }
    if (a[0]>b[0])
    {
        return true;
    }
    else if (a[0]<b[0])
    {
        return false;
    }
    else
    {
        vector<int> a1;
        a1.insert(a1.end(), a.begin() + 1, a.end());
        vector<int> b1;
        b1.insert(b1.end(), b.begin() + 1, b.end());
        return Compared(a1, b1);
    }
}
int main()
{
    int N, M;
    cin >> N >> M >> S;
    for (int i = 0; i < N;++i)
    {
        scanf("%d", &weight_[i]);
    }
    for (int i = 0; i < M;++i)
    {
        int node_, num, childen;
        scanf("%d %d", &node_, &num);
        for (int j = 0; j < num;++j)
        {
            scanf("%d", &childen);
            trees[node_].push_back(childen);
        }
    }
    vector<int> vec;
    TreeDFS(0, 0, vec);
    sort(paths.begin(), paths.end(), Compared);

    for (int i = 0; i < paths.size();++i)
    {
        printf("%d", paths[i][0]);
        for (int j = 1; j < paths[i].size();++j)
        {
            printf(" %d", paths[i][j]);
        }
        printf("\n");

    }
    return 0;
}