///*ʹ���������������������ȻҲ����ʹ�ù�������㷨����*/
//#include<iostream>
//#include <cstring>
//using namespace std;
//
//
//#define MAX 1000
//int matrix[MAX][MAX] = { 0 };
//int visited[MAX];
//int N, M, K;
//
//void DFS(int v)
//{
//    visited[v] = 1;
//    for (int i = 1; i <= N; ++i)
//    {
//        if (visited[i] == 0 && matrix[v][i] == 1)
//        {
//            DFS(i);
//        }
//    }
//}
//int main()
//{
//
//    cin >> N >> M >> K;
//    int index1, index2;
//    for (int i = 0; i < M; ++i)
//    {
//        cin >> index1 >> index2;
//        matrix[index1][index2] = 1;
//        matrix[index2][index1] = 1;
//    }
//    int check;
//    for (int i = 0; i < K; ++i)
//    {
//        int count = 0;
//        cin >> check;
//        memset(visited, 0, sizeof(visited));
//        visited[check] = 1;     //ʹ�ñ�ռ��ĳ��б��Ϊ�㣬������Ż��㷨����ͨ���ö�����
//        for (int j = 1; j <= N; ++j)
//        {
//            if (visited[j] == 0)
//            {
//                DFS(j);
//                ++count;
//            }
//        }
//        cout << count-1 << endl;
//    }
//    return 0;
//}



/*ʹ�ò��鼯��ʵ��*/
#include<iostream>
#include <cstring>
using namespace std;

#define MAXCITY 1000
#define MAXHIGHWAY 500000 //������ʹ����C1000��ȡ2 ��Ȼ����1000*999/(2*1)���������
int uset[MAXCITY];
int N, M, K;
struct HighWay
{
    int x;
    int y;
}highways[MAXHIGHWAY];

/*MakeSet()������һ���µĲ��鼯�����а��� N ����Ԫ�ؼ���*/
void MakeSet() 
{
    for (int i = 0; i <= N; i++)
    {
        uset[i] = i;
    }
}

/*FindSet(a)���ҵ�Ԫ�� x ���ڵļ��ϵĴ����ò���Ҳ���������ж�����Ԫ���Ƿ�λ��ͬһ�����ϣ�ֻҪ�����Ǹ��ԵĴ���Ƚ�һ�¾Ϳ����ˡ�*/
int FindSet(int a)
{
    if (uset[a] != a)
    {
        uset[a] = FindSet(uset[a]);
    }
    return uset[a];
}


void JoinSet(int x, int y)
{
    x = FindSet(x);
    y = FindSet(y);
    if (x != y) 
    {
        uset[y] = x;
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        cin >> highways[i].x >> highways[i].y;
    }

    int check;
    for (int i = 0; i < K; ++i)
    {
        cin >> check;
        MakeSet();
        for (int j = 0; j < M; ++j)
        {
            if (highways[j].x != check && highways[j].y != check)////���ں���Ҫ���ĵ��·�������˵㲻���벢�鼯
            {
                JoinSet(highways[j].x, highways[j].y);
            }
        }
        int count = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (uset[j] == j && uset[j] != check)
            {
                count++; //ͳ�Ƴ�check�ڵ������ͨ��������
            }
        }
        printf("%d\n", count - 1);
    }
    return 0;
}