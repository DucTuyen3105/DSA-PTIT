#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
struct node
{
	int val;
	node *right;
	node *left;
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};
void makenode(node*root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root ->right = new node(v);
}
void insert(node*root, int u, int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->right,u,v,c);
		insert(root->left,u,v,c);
	}
}
int count(node*root)
{
	if(root == NULL) return 0;
	else if(root->left == NULL && root->right == NULL) return 1;
	else return count(root->left) + count(root->right);
}
int main()
{
	int n; cin>>n;
	node*root = NULL;
	for(int i = 0 ; i < n ; i++)
	{
		int u, v; char c; cin>>u>>v>>c;
		if(root==NULL)
		{
			root = new node(u);
			makenode(root,u,v,c);
		}
		else
		{
			insert(root,u,v,c);
		}
	}
	cout<<count(root);
}
