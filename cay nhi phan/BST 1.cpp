#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val; node *left ; node*right;
	node(int x)
	{
		val = x;
		right = left = NULL;
	}
};
node* insert(node*root,int key)
{
	if(root == NULL)
	{
		return new node(key);
	}
	else if(key < root->val)
	{
		root->left = insert(root->left,key);
	}
	else
	{
		root->right = insert(root->right,key);
	}
	return root;
}
void inorder(node *root)
{
	if(root == NULL) return;
	else if(root != NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
int main()
{
	int n; cin>>n; int a[n];
	for(int&x : a) cin>>x;
	node* root = NULL;
	for(int i = 0 ; i <	 n ; i++)
	{
		insert(root,a[i]);
	}
	inorder(root);
}
	

