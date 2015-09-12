#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
using namespace std;
const int NMAX = 10002;
int dist[NMAX];  // store distance  
int points[NMAX];  // store root  
vector<int> adj_list[NMAX];  //store neighbor  
int components = 0;          // number of components  连通域的个数
////return the  max distance  
int BFS(int start, int vnum)
{
    memset(dist, -1, sizeof(dist));
    queue<int> queue_;
    int cur_ = start;
    int dmax = 0;
    queue_.push(cur_);
    dist[cur_] = 0;
    while (!queue_.empty())
    {
        cur_ = queue_.front();
        queue_.pop();
        for (int j = 0; j < adj_list[cur_].size(); ++j)
        {
            if (dist[adj_list[cur_][j]] == -1)
            {
                dist[adj_list[cur_][j]] = dist[cur_] + 1;
                queue_.push(adj_list[cur_][j]);
            }
        }
        if (dist[cur_]>dmax)
        {
            dmax = dist[cur_];
        }

    }
    return dmax;
            
}
//并查集找连通域个数
int Find(int p)
{
    // 寻找p节点所在组的根节点，根节点具有性质id[root] = root  
    while (p != points[p]) 
        p = points[p];
    return p;
}
void Union(int p, int q)
{
    // Give p and q the same root.  
    int pRoot = Find(p);
    int qRoot = Find(q);
    if (pRoot == qRoot)
        return;
    points[pRoot] = qRoot;    // 将一颗树(即一个组)变成另外一课树(即一个组)的子树  
    --components;
}

int main()
{
    int n; 
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        points[i] = i;    // 每个节点的组号就是该节点的序号
    }
    components = n;// number of components  
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    set<int> first;
    set<int> total;

    if (components != 1)
    {
        cout << "Error: " << components << " components" << endl;
    }
    else
    {
        int dmax = BFS(1, n);
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == dmax)
            {
                first.insert(i);
                total.insert(i);
            }
        }
        dmax = BFS(*first.begin(), n);
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == dmax)
            {
                first.insert(i);
                total.insert(i);
            }
        }

        for (set<int>::iterator it = total.begin(); it != total.end(); ++it)
        {
            cout << *it << endl;
        }

    }

    return 0;
}


