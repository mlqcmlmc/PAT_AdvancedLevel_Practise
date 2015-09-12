#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
//const int CMAX = 102;
const int NMAX = 505;
const int INF = 0x7fffffff;

int bikes[NMAX] = { 0 };//��¼ÿ����վ��ǰ�����г�����
int roads[NMAX][NMAX] = { 0 };//��¼��·���ʱ��
bool isvisited[NMAX] = { false };//��¼�ڵ��Ƿ񱻷���
int minTime[NMAX] = { 0 };//����㵽Ŀ�공վ�����·��ֵ
int maxsumbike[NMAX] = { 0 };
vector<int> minroads[NMAX];
//bool pathflag[NMAX][NMAX];//pathflag[v][w]Ϊtrue�����Ǵ�v0��v�ĵ����·���Ķ���
//vector<int> curRoad;
//vector<int> minRoad;
int sendbike[NMAX] = { 0 };
int takeback[NMAX] = { 0 };

int perfectnum;;
void Dijkstra(int sourcce, int dest, int n)
{
    int cur = sourcce;
    int count = 0;
    int pathtime, mm, next;
    while (count <= n)
    {
        isvisited[cur] = true;
        mm = INF;
        for (int i = 0; i <= n; ++i)
        {
            if (isvisited[i])
            {
                continue;
            }
            if (roads[cur][i]>0)
            {
                pathtime = minTime[cur] + roads[cur][i];
                if (pathtime < minTime[i] || minTime[i] == 0)//�������i�������µ����·��  
                {
                    minTime[i] = pathtime;
                    maxsumbike[i] = maxsumbike[cur] + bikes[i];
                    minroads[i] = minroads[cur];
                    minroads[i].push_back(i);
                    if (perfectnum==bikes[i])
                    {
                        sendbike[i] = sendbike[cur];
                        takeback[i] = takeback[cur];

                    }
                    else if (perfectnum>bikes[i])
                    {
                        if (takeback[cur]>perfectnum-bikes[i])
                        {
                            takeback[i] = takeback[cur] - (perfectnum - bikes[i]);
                            sendbike[i] = sendbike[cur];
                        }
                        else
                        {
                            takeback[i] = 0;
                            sendbike[i] = sendbike[cur] + (perfectnum - bikes[i]) - takeback[cur];
                        }
                    }
                    else
                    {
                        takeback[i] = takeback[cur] + bikes[i] - perfectnum;
                        sendbike[i] = sendbike[cur];
                    }
                }
                else if (pathtime == minTime[i]) //�������i��������ͬ�����·��  
                {
                    int temp_teke, temp_send;
                    if (perfectnum == bikes[i])
                    {
                        temp_send = sendbike[cur];
                        temp_teke = takeback[cur];

                    }
                    else if (perfectnum > bikes[i])
                    {
                        if (takeback[cur] > perfectnum - bikes[i])
                        {
                            temp_teke = takeback[cur] - (perfectnum - bikes[i]);
                            temp_send = sendbike[cur];
                        }
                        else
                        {
                            temp_teke = 0;
                            temp_send = sendbike[cur] + (perfectnum - bikes[i]) - takeback[cur];
                        }
                    }
                    else
                    {
                        temp_teke = takeback[cur] + bikes[i] - perfectnum;
                        temp_send = sendbike[cur];
                    }
                    if (temp_send < sendbike[i] ||  (sendbike[i] == temp_send && temp_teke<takeback[i]))
                  //  if (temp_send+temp_teke < sendbike[i] +takeback[i])
                    {
                        maxsumbike[i] = maxsumbike[cur] + bikes[i];
                        minroads[i] = minroads[cur];
                        minroads[i].push_back(i);
                        sendbike[i] = temp_send;
                        takeback[i] = temp_teke;
                    }
                }

            }
            if (minTime[i] < mm&&minTime[i] != 0)
            {
                mm = minTime[i];
                //next = i;
            }
           
        }
        minTime[cur] = mm;
        //if (next == dest)
        //  break;
       // cur = next;  
        ++count;
        cur = count;
    }
}



int main()
{
    int  cmax,n, sp, m;
    cin >> cmax >> n >> sp >> m;
    perfectnum = cmax / 2;
    for (int i = 1; i <= n;++i)
    {
        cin >> bikes[i];
    }
    for (int i = 0; i < m;++i)
    {
        int si, sj, weight;
        cin >> si >> sj >> weight;
        roads[si][sj] = weight;
        roads[sj][si] = weight;
    }
    Dijkstra(0, sp, n);
    printf("%d 0", sendbike[sp]);
    for (int i = 0; i < minroads[sp].size();++i)
    {
        printf("->%d", minroads[sp][i]);
    }
   // printf("%d", sp);
    printf(" %d\n", takeback[sp]);

    return 0;
}




