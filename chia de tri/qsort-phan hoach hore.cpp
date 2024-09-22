#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l , int r)
{
	int x = a[l]; //pivot;
	int i = l - 1;
	int j = r + 1;
	while(true)
	{
		do
		{
			i++;
		}
		while(a[i]<x);
		do
		{
			j--;
		}
		while(a[j]>x);
		if(i<j)
		{
			swap(a[i],a[j]);
		}
		else
		{
			return j;
		}
	}
}
void qsort(int a[],int l,int r)
{
	if(l<r)
	{
		int p = partition(a,l,r);
		qsort(a,l,p);
		qsort(a,p+1,r);
	}
}
int main()
{
	int n;
	cin>>n; int a[n];
	for(int &x : a) cin>>x;
	qsort(a,0,n-1);
	for(int x : a) cout<<x<<" ";
}
		
