#include <iostream>  

using namespace std;

const int CITYMAX = 501;
const int INF = 0x7fffffff;

int city[CITYMAX] = { 0 };              //记录各个城市的团队数 
int road[CITYMAX][CITYMAX] = { 0 };     //记录道路的长度，是一个对角矩阵
bool isvisited[CITYMAX] = { false };    //记录当前定点是否访问过
int minLen[CITYMAX] = { 0 };            //从源城市到达index城市的最短路径值  
int sum[CITYMAX] = { 0 };               //从源城市到达index城市，所能召集的最大团队数  
int same[CITYMAX] = { 0 };              //从源城市到达index城市,具有相同最短的路径个数  
void Dij(int source, int dest, int n)
{
    int i, t, mm, next;
    int count = 0;
    int cur = source;
    sum[cur] = city[cur];
    same[cur] = 1;
    while (count < n - 1)
    {
        isvisited[cur] = true;
        mm = INF;
        for (i = 0; i < n; i++)
        {
            if (isvisited[i])
            {
                continue;
            }
            if (road[cur][i])
            {
                t = minLen[cur] + road[cur][i];
                if (t < minLen[i] || minLen[i] == 0)    //到达城市i，出现新的最短路径  
                {
                    minLen[i] = t;
                    same[i] = same[cur];                //重新计数,可能到达本节点cur的最短路径有多条  
                    sum[i] = sum[cur] + city[i];
                }
                else if (t == minLen[i])                //到达城市i，出现相同的最短路径  
                {
                    same[i] += same[cur];
                    if (sum[cur] + city[i] > sum[i])    //记下团队数较大的值  
                        sum[i] = sum[cur] + city[i];
                }
            }
            if (minLen[i] < mm && minLen[i] != 0)
            {
                mm = minLen[i];
                next = i;
            }
        }
        minLen[cur] = mm;
        //if (next == dest)
        //  break;
        cur = next;
        count++;
    }
    return;
}
int main()
{
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N;++i)
    {
        cin >> city[i];
    }
    for (int i = 0; i < M; ++i)
    {
        int c1, c2;
        cin >> c1 >> c2;
        cin >> road[c1][c2];
        road[c2][c1] = road[c1][c2];
    }
    if (C1 == C2)//若所在地就是目的地 则直接输出结果
    {
        cout << 1 << ' ' << city[C1] << endl;
        return 0;
    }
    Dij(C1, C2, N);
    cout << same[C2] << ' ' << sum[C2] << endl;
    return 0;
}