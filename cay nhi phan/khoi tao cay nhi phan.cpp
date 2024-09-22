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
void makeroot(node*root, int u, int v, char c) // goc cay nhi phan // u la not cha // v la not con // c la left hoac right
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insertNode(node *root, int u,int v, char c)
{
	if(root == NULL) return;
	if(root->val == u)
	{
		makeroot(root,u,v,c);
	}
	else
	{
		insertNode(root->left,u,v,c);
		insertNode(root->right,u,v,c);
	}
}
// ko can tham chieu vi chi thay doi cac node con ma k thay doi root
int main()
{
	node *root = NULL;
	int n; cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		int u, v, char c;
		cin>>u>>v>>c;
		if(root == NULL)
		{
			root = new node(u);
			if(c == 'L') root->left = new node(v);
			else root->right = new node(v);
		}
		else
		{
			insertNode(root,u,v,c);
		}
	}
}
