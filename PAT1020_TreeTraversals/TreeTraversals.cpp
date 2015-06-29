#include<iostream>
#include<vector>
using namespace std;



struct Node
{
	int data;
	Node *lchild, *rchild;
	Node(){}
};

Node* CreatTree(int n,int *post, int *in)
{
	if (n <= 0)
	{
		return NULL;
	}
	
	//Node *root = new Node(post[n-1]);
	Node *root = new Node();
	root->data = post[n - 1];
	root->lchild = NULL;
	root->rchild = NULL;
	int index = 0;
	while (post[n - 1] != in[index] && index < n)
	{
		++index;
	}
	root->lchild = CreatTree(index, post, in);
	root->rchild = CreatTree(n - index - 1, post + index, in + index + 1);
	return root;
}


int main()
{
	int N;
	int postoder[31], inoder[31];
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> postoder[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> inoder[i];
	}
	Node *root = CreatTree(N, postoder, inoder);



	return 0;
}