#include <iostream>  

using namespace std;

const int CITYMAX = 501;
const int INF = 0x7fffffff;

int city[CITYMAX] = { 0 };              //��¼�������е��Ŷ��� 
int road[CITYMAX][CITYMAX] = { 0 };     //��¼��·�ĳ��ȣ���һ���ԽǾ���
bool isvisited[CITYMAX] = { false };    //��¼��ǰ�����Ƿ���ʹ�
int minLen[CITYMAX] = { 0 };            //��Դ���е���index���е����·��ֵ  
int sum[CITYMAX] = { 0 };               //��Դ���е���index���У������ټ�������Ŷ���  
int same[CITYMAX] = { 0 };              //��Դ���е���index����,������ͬ��̵�·������  
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
                if (t < minLen[i] || minLen[i] == 0)    //�������i�������µ����·��  
                {
                    minLen[i] = t;
                    same[i] = same[cur];                //���¼���,���ܵ��ﱾ�ڵ�cur�����·���ж���  
                    sum[i] = sum[cur] + city[i];
                }
                else if (t == minLen[i])                //�������i��������ͬ�����·��  
                {
                    same[i] += same[cur];
                    if (sum[cur] + city[i] > sum[i])    //�����Ŷ����ϴ��ֵ  
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
    if (C1 == C2)//�����ڵؾ���Ŀ�ĵ� ��ֱ��������
    {
        cout << 1 << ' ' << city[C1] << endl;
        return 0;
    }
    Dij(C1, C2, N);
    cout << same[C2] << ' ' << sum[C2] << endl;
    return 0;
}