///*使用深度优先搜索方法，当然也可以使用广度优先算法来做*/
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
//        visited[check] = 1;     //使得被占领的城市标记为零，则深度优化算法不会通过该定点了
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



/*使用并查集来实现*/
#include<iostream>
#include <cstring>
using namespace std;

#define MAXCITY 1000
#define MAXHIGHWAY 500000 //这里是使用了C1000中取2 ，然后是1000*999/(2*1)，来计算的
int uset[MAXCITY];
int N, M, K;
struct HighWay
{
    int x;
    int y;
}highways[MAXHIGHWAY];

/*MakeSet()：建立一个新的并查集，其中包含 N 个单元素集合*/
void MakeSet() 
{
    for (int i = 0; i <= N; i++)
    {
        uset[i] = i;
    }
}

/*FindSet(a)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。*/
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
            if (highways[j].x != check && highways[j].y != check)////对于含有要检查的点的路径的两端点不加入并查集
            {
                JoinSet(highways[j].x, highways[j].y);
            }
        }
        int count = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (uset[j] == j && uset[j] != check)
            {
                count++; //统计除check节点外的连通分量个数
            }
        }
        printf("%d\n", count - 1);
    }
    return 0;
}