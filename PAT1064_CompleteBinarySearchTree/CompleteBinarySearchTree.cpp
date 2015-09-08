//这个题目要求构造完全二叉排序树，如果直接采用普通的建树方式，其实挺麻烦的，
//我刚开始也是那样做得到，还调试了很久，AC了，但今天突然在网上看到别人做的这个题思路非常的好，
//所以消化吸收后写了下，其实就是利用了数据结构中完全二叉树的的一个性质：
//孩子节点的下标为i则其左孩子节点的下标为2*i，右孩子节点的下标为2*i + 1，这个性质只有完全二叉树才满足，
//其实反过来按这个性质构造出来的树就是一个完全二叉树。 要实现这棵完全二叉树也是排序树，其实就简单了，
//显然一棵二叉排序树的中序遍历序列是递增有序的，所以这就简单了，只要在构造完全二叉树的时候按中序构造就可以了
//（前提是元素递增有序）。
//以前做树的题目都是链接型的，而这个题目用完全二叉树的这个性质确非常的合适，所以记录下，供以后回顾学习。


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tree[1005] = { 0 };
int N, pos;
vector<int> numbers;
void BuildTress(int root)
{
    if (root > N)
        return;
    int lson = root << 1;
    int rson = (root << 1) + 1;
    BuildTress(lson);
    tree[root] = numbers[pos++];
    BuildTress(rson);
}
int main()
{
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    pos = 0;
    BuildTress(1);
    printf("%d", tree[1]);
    for (int i = 2; i <= N; ++i){
        printf(" %d", tree[i]);
    }
    printf("\n");
    return 0;
}