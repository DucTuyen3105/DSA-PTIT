#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val; node *left; node *right;
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};
void makenode(node *root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}
void insert(node *root,int u, int v, char c)
{
	if(root == NULL) return;
	else if(root->val == u) makenode(root,u,v,c);
	else
	{
		insert(root->left,u,v,c);
		insert(root->right,u,v,c);
	}
}
int ok = 0;
void check(node *root)
{
	if(root==NULL) return;
	else if((root->left == NULL && root->right!=NULL) || (root->left != NULL && root->right==NULL))
	{
		ok = 1;
		return;
	}
	check(root->right);
	check(root->left);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n; cin>>n;
	node *root = NULL;
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
	check(root);
	if(ok) cout<<"NO";
	else cout<<"YES";
	cout<<endl;
	ok = 0;
	delete root;
	}
}
