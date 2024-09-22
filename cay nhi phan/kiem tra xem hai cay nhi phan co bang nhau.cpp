#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};
void makenode(node*root,int u,int v,char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node*root,int u,int v,char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->right,u,v,c);
		insert(root->left,u,v,c);
	}
}
bool ok = 1;
void dfs(node *root1 , node *root2)
{
	if(root1 == NULL && root2 == NULL) return;
	if(root1 == NULL || root1 == NULL)
	{
		ok = 0;
		return;
	}
	if(root1->val != root2 -> val)
	{
		ok = 0;
		return;
	}
	dfs(root1->left,root2->left);
	dfs(root1->right,root2->right);
}
int main()
{
	int n1; cin>>n1;
	node *root1 = NULL;
	for(int i = 0 ; i < n1 ; i++)
	{
		int u; int v; char c; cin>>u>>v>>c;
		if(root1 == NULL)
		{
			root1 = new node(u);
			makenode(root1,u,v,c);
		}
		else
		{
			insert(root1,u,v,c);
		}
	}
	int n2; cin>>n2;
	node *root2 = NULL;
	for(int i = 0 ; i < n2 ; i++)
	{
		int u; int v; char c; cin>>u>>v>>c;
		if(root2 == NULL)
		{
			root2 = new node(u);
			makenode(root2,u,v,c);
		}
		else
		{
			insert(root2,u,v,c);
		}
	}
	dfs(root1,root2);
	if(ok) cout<<"YES";
	else cout<<"NO";			
}
	
