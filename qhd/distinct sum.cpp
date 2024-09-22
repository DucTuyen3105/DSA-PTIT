#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int sum = 0;
	for(int i = 0 ; i < n ; i++)
	{	
		cin>>a[i];
		sum+=a[i];
	}
	int f[sum+1] = {0};
	f[0] = 1;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = sum ; j >= a[i] ; j--)
		{
			if(f[j-a[i]]==1)
			{
				f[j] = 1;
			}
		}
	}
	for(int i = 0 ; i <= sum ; i++)
	{
		if(f[i]!=0)
		{
			cout<<i<<" ";
		}
	}
}
