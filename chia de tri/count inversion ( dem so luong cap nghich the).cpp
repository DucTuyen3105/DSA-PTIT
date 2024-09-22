#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll merge(int a[],int l , int m , int r)
{
	vector<int>x(a+l,a+m+1);
	vector<int>y(a+m+1,a+r+1);
	ll dem = 0;
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
			dem += x.size() - i;
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
	return dem;
}
ll tron(int a[], int l , int r)
{
	ll dem = 0;
	if(l<r)
	{
	int mid = (l+r) / 2;
	dem+=tron(a,l,mid);
	dem+=tron(a,mid+1,r);
	dem+=merge(a,l,mid,r);
	}
	return dem;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int &x : a) cin>>x;
	cout<<tron(a,0,n-1);
	
}
