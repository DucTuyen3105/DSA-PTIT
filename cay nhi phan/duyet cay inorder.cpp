#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
	node(int x)
	{
		val = x;
		right = left = NULL;
	}
};
void makenode(node*root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node*root,int u, int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else 
	{
		insert(root->left,u,v,c);
		insert(root->right,u,v,c);
	}
}
void inorder(node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
int main()
{
	int n;
	cin>>n;
	node *root = NULL;
	for(int i = 0 ; i < n ; i++)
	{
		int u, v; char c; cin>>u>>v>>c;
		if(root == NULL)
		{
			root = new node(u);
			if(c == 'L') root->left = new node(v);
			else root->right = new node(v);
		}
		else
		{
			insert(root,u,v,c);
		}
	}
	inorder(root);
}
