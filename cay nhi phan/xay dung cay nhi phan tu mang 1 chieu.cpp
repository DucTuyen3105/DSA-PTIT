#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node*left; node*right;
	node(int x)
	{
		val = x;
		left = right = NULL;
	}
};
node*tree(int a[],int l, int r)
{
	if(l > r) return NULL;
	int mid = (l + r) / 2;
	node* root = new node(a[mid]);
	root->left = tree(a,l,mid-1);
	root->right = tree(a,mid+1,r);
	return root;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n; cin>>n; int a[n]; for(int&x : a) cin>>x;
	sort(a,a+n);
	node*root = tree(a,0,n-1);
	cout<<root->val;
	cout<<endl;
	}
}
	
