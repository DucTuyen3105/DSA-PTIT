#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l , int m , int r)
{
	vector<int>x(a+l,a+m+1);
	vector<int>y(a+m+1,a+r+1);
	int index = l; int i = 0 ; int j = 0;
	while(i<x.size()&&j<y.size())
	{
		if(x[i]<=y[j])
		{
			a[index] = x[i];
			i++;index++;
		}
		else
		{
			a[index] = y[j];
			j++;index++;
		}
	}
	while(i<x.size())
	{
		a[index] = x[i];
		i++; index++;
	}
	while(j<y.size())
	{
		a[index] = y[j];
		j++; index++;
	}
}
void tron(int a[], int l , int r)
{
	if(l>=r) return;
	int mid = (l+r) / 2;
	tron(a,l,mid);
	tron(a,mid+1,r);
	merge(a,l,mid,r);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int &x : a) cin>>x;
	tron(a,0,n-1);
	for(int x : a) cout<<x<<" ";
}
