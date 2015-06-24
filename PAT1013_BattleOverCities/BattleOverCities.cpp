/*使用深度优先搜索方法，当然也可以使用广度优先算法来做*/
#include<iostream>
#include <cstring>
using namespace std;


#define MAX 1000
int matrix[MAX][MAX] = { 0 };
int visited[MAX];
int N, M, K;

void DFS(int v)
{
    visited[v] = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == 0 && matrix[v][i] == 1)
        {
            DFS(i);
        }
    }
}
int main()
{

    cin >> N >> M >> K;
    int index1, index2;
    for (int i = 0; i < M; ++i)
    {
        cin >> index1 >> index2;
        matrix[index1][index2] = 1;
        matrix[index2][index1] = 1;
    }
    int check;
    for (int i = 0; i < K; ++i)
    {
        int count = 0;
        cin >> check;
        memset(visited, 0, sizeof(visited));
        visited[check] = 1;     //使得被占领的城市标记为零，则深度优化算法不会通过该定点了
        for (int j = 1; j <= N; ++j)
        {
            if (visited[j] == 0)
            {
                DFS(j);
                ++count;
            }
        }
        cout << count-1 << endl;
    }
    return 0;
}