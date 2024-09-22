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
		right = left = NULL;
	}
};
void makenode(node *root, int u, int v, char c)
{
	if(c == 'L') root -> left = new node(v);
	else root -> right = new node(v);
}
void insert(node *root, int u, int v , char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->right,u,v,c);
		insert(root->left,u,v,c);
	}
}
bool find(node *root, int x)
{
	if(root == NULL) return false;
	if(root -> val == x) return true;
	else if(x < root->val)
	{
		return find(root->left,x);
	}
	else 
	{
		return find(root->right,x);
	}
}
		
int main()
{
	int n; cin>>n; node *root = NULL;
	int x; cin>>x;
	for(int i = 0 ; i < n ; i++)
	{
		int u; int v; char c; cin>>u>>v>>c;
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
    if(find(root, x)) cout<<1; else cout<<0;
}

