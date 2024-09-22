#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int partition(int a[],int l, int r)
{
	int ok = 0;
	int pivo = a[r];
	int j = l - 1;
	for(int i = l ; i < r ; i++)
	{
		if(a[i]<=pivo)
		{
			j++;
			ok = 1;
			swap(a[i],a[j]);
		}
	}
	j++; swap(a[j],a[r]);
	if(ok==0) cout<<a[r];
	return j;
}
void qsort(int a[],int l, int r)
{
	if(l<r)
	{
	int q = partition(a,l,r);
	qsort(a,l,q-1);
	qsort(a,q+1,r);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	qsort(a,0,n-1);
	for(int &x : a) cout<<x<<" ";
}
