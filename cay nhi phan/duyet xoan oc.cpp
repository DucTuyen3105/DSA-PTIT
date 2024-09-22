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
void makenode(node *root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node *root, int u, int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root, u,  v,  c);
	else
	{
		insert(root->left, u, v, c);
		insert(root->right, u, v, c);
	}
}
void xoanoc(node *root)
{
	stack<node*>st1,st2;
	st1.push(root);
	while(!st1.empty()||!st2.empty())
	{
		while(!st1.empty())
		{
			node *x = st1.top(); st1.pop();
			cout<<x->val<<" ";
			if(x->right!=NULL)
			{
				st2.push(x->right);
			}
			if(x->left!=NULL)
			{
				st2.push(x->left);
			}
		}
		while(!st2.empty())
		{
			node *x = st2.top(); st2.pop();
			cout<<x->val<<" ";
			if(x->left!=NULL)
			{
				st1.push(x->left);
			}
			if(x->right!=NULL)
			{
				st1.push(x->right);
			}
		}
	}
}
		
int main()
{
	int n; cin>>n;
	node *root = NULL;
	for(int i = 0 ; i < n ; i++)
	{
		int u; int v; char c; cin>>u>>v>>c;
		if(root == NULL)
		{
			root = new node(u);
			makenode(root, u, v, c);
		}
		else
		{
			insert(root,u,v,c);
		}
	}
	xoanoc(root);
}
