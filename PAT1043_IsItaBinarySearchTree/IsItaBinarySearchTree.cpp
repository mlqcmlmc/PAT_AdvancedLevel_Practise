#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
vector<int> post;
struct Node
{
    Node(int val) :data_(val), lchild(nullptr), rchild(nullptr){}
    int data_;
    Node *lchild;
    Node *rchild;
};
bool isBinarySearchTree(const vector<int>&  tree, Node* proot, bool mirror)
{
    if (tree.size() == 1)
    {
        return true;
    }
    else if (!mirror)
    {
        int root = tree[0];
        int i = 1;
        for (; i < tree.size(); ++i)
        {
            if (tree[i] >= root)
            {
                break;
            }
        }
        int index_ = i;
        for (; i < tree.size(); ++i)
        {
            if (tree[i] < root)
            {
                return false;
            }
        }
        auto ite = tree.begin();
        vector<int> leftsubtree(ite + 1, ite + index_);
        vector<int> rightsubtree(ite + index_, tree.end());
        bool leftflag = true;
        bool rightfalg = true;
        if (!leftsubtree.empty())
        {
            Node* p = new Node(leftsubtree[0]);
            proot->lchild = p;
            leftflag = isBinarySearchTree(leftsubtree, p, mirror);
        }
        if (!rightsubtree.empty())
        {
            Node* p = new Node(rightsubtree[0]);
            proot->rchild = p;
            rightfalg = isBinarySearchTree(rightsubtree, p, mirror);

        }
        if (leftflag && rightfalg)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int root = tree[0];
        int i = 1;
        for (; i < tree.size(); ++i)
        {
            if (tree[i] < root)
            {
                break;
            }
        }
        int index_ = i;
        for (; i < tree.size(); ++i)
        {
            if (tree[i] > root)
            {
                return false;
            }
        }
        auto ite = tree.begin();
        vector<int> leftsubtree(ite + 1, ite + index_);
        vector<int> rightsubtree(ite + index_, tree.end());
        bool leftflag = true;
        bool rightfalg = true;
        if (!leftsubtree.empty())
        {
            Node* p = new Node(leftsubtree[0]);
            proot->lchild = p;
            leftflag = isBinarySearchTree(leftsubtree, p, mirror);
        }
        if (!rightsubtree.empty())
        {
            Node* p = new Node(rightsubtree[0]);
            proot->rchild = p;
            rightfalg = isBinarySearchTree(rightsubtree, p, mirror);

        }
        if (leftflag && rightfalg)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void postOrder(Node *root)//ºóÐò
{  
    if (root == nullptr)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post.push_back(root->data_);
}

int main()
{
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int i = 0; i < n;++i)
    {
        scanf("%d", &tree[i]);
    }
    Node* p = new Node(tree[0]);
    if (isBinarySearchTree(tree, p, false))
    {
        printf("YES\n");
        postOrder(p);
        printf("%d", post[0]);
        for (int i = 1; i < post.size();++i)
        {
            printf(" %d",post[i]);
        }
        printf("\n");
    }
    else if (isBinarySearchTree(tree, p, true))
    {
        printf("YES\n");
        postOrder(p);
        printf("%d", post[0]);
        for (int i = 1; i < post.size(); ++i)
        {
            printf(" %d", post[i]);
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;

}