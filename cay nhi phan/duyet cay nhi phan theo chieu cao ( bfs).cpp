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
	if(c == 'L') root -> left = new node(v);
	else root -> right = new node(v);
}
void insert(node *root, int u, int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->right, u, v ,c);
		insert(root->left, u, v, c);
	}
}
void bfs(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *x = q.front(); q.pop();
		cout<<x->val<<" ";
		if(x->left != NULL) q.push(x->left);
		if(x->right != NULL) q.push(x->right);
	}
}
int main()
{
	int n;
	cin>>n; node *root = NULL;
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
	bfs(root);
}

