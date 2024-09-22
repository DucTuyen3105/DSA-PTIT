#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val; node *left; node *right;
	node(int x) 
	{
		val = x; left = right = NULL;
	}
};
void makenode(node*root,int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node*root,int u,int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->right,u,v,c);
		insert(root->left,u,v,c);
	}
}
int ok1 = 1;
int ok2 = 1;
int chieucao = 0;
void check1(node *root, int h)
{
	if(root == NULL) 
	{
		return;
	}
	else if(root->left == NULL && root -> right == NULL)
	{
		if(chieucao == 0)
		{
			chieucao = h;
		}
		else
		{
			if(chieucao!=h)
			{
				ok1 = 0;
				return;
			}
		}
	}
	check1(root->left,h+1);
	check1(root->right,h+1);
}
void check2(node *root)	
{
	if(root == NULL) return;
	else if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
	{
		ok2 = 0;
		return;
	}
	check2(root->left); check2(root->right);
}
int main()
{
	int n;cin>>n; node *root = NULL;
	for(int i = 0 ; i < n ; i++)
	{
		int u,v; char c; cin>>u>>v>>c;
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
	check1(root,0);
	check2(root);
	if(ok1&&ok2) cout<<"YES"; else cout<<"NO";
}
