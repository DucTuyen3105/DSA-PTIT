#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
	node(int x)
	{
		val = x; right = left = NULL;
	}
};
void makenode(node *root, int u,int v,char c)
{
	if(c == 'L') root->left = new node(v);
	else if(c == 'R') root->right = new node(v);
}
void insert(node *root,int u,int v,char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->left,u,v,c);
		insert(root->right,u,v,c);
	}
}
int chieucao = 0;
void dfs(node*root,int hight)
{
	if(root == NULL) return;
	else if(root->left == NULL && root->right == NULL)
	{
		chieucao = max(chieucao,hight); return;
	}
	dfs(root->left,hight+1);
	dfs(root->right,hight+1);
}
int main()
{
	node *root = NULL;
	int n; cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		int u, v; char c; cin>>u>>v>>c;
		if(root == NULL)
		{
			root = new node(u);
			makenode(root,u,v,c);
		}
		else
		{
			insert(root,u,v,c);
		}
	}
	dfs(root,0);
	cout<<chieucao;
}
