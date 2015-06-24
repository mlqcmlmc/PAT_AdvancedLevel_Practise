/*ʹ���������������������ȻҲ����ʹ�ù�������㷨����*/
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
        visited[check] = 1;     //ʹ�ñ�ռ��ĳ��б��Ϊ�㣬������Ż��㷨����ͨ���ö�����
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