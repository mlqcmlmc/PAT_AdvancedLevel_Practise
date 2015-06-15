#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct CTNode
{
    int child;
    CTNode *next;
};
struct CTBox
{
    int data;
    int child_num;
    CTNode *first_child;
};
struct
{
    vector<CTBox> nodes;
    int N;              //节点数
    int M;              //叶子节点数

}CTree;
vector<int> VecCount;
void PreOrderTraverseTree(CTBox T, int depth)
{
    auto pchild = T.first_child;
    if (VecCount.size() <= depth)
    {
        VecCount.push_back(0);
    }

    if (T.child_num == 0)
    {
        ++VecCount[depth];
    }
    else
    {
        while (pchild != nullptr)
        {

            PreOrderTraverseTree(CTree.nodes[pchild->child - 1], depth + 1);
            pchild = pchild->next;
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    CTree.N = N;
    CTree.M = M;
    CTree.nodes.resize(N);
    int node_data;
    int child_num;
    for (int i = 0; i < M; i++)
    {
        cin >> node_data >> child_num;
        CTree.nodes[node_data - 1].data = node_data;
        CTree.nodes[node_data - 1].child_num = child_num;
        int child;
        CTNode *tempchild, *tempnextchild = nullptr;
        cin >> child;
        tempchild = (CTNode*)malloc(sizeof(CTNode));
        tempchild->child = child;
        tempchild->next = nullptr;
        CTree.nodes[node_data - 1].first_child = tempchild;
        for (int j = 1; j < child_num; j++)
        {
            cin >> child;
            tempnextchild = (CTNode*)malloc(sizeof(CTNode));
            tempnextchild->child = child;
            tempnextchild->next = nullptr;
            tempchild->next = tempnextchild;
            tempchild = tempnextchild;
            tempnextchild = nullptr;
        }

    }
    for (int i = 0; i < N; i++)
    {
        if (CTree.nodes[i].data == 0)
        {
            CTree.nodes[i].data = i + 1;
            CTree.nodes[i].child_num = 0;
            CTree.nodes[i].first_child = nullptr;
        }
    }
    PreOrderTraverseTree(CTree.nodes[0], 0);
    cout << VecCount[0];
    for (int i = 1; i < VecCount.size(); i++)
    {
        cout << ' ' << VecCount[i];
    }


    return 0;

}