#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	int left[n];
	for(int i = 0 ; i < n ; i++)
	{
		left[i] = a[i];
		for(int j = 0 ; j < i ; j++)
		{
			if(a[j]<a[i])
			{
				left[i] = max(left[i],left[j]+a[i]);
			}
		}
	}
	int right[n];
	for(int i = n - 1 ; i >= 0 ; i--)
	{
		right[i] = a[i];
		for(int j = i + 1 ; j < n ; j++)
		{
			if(a[i]>a[j])
			{
				right[i] = max(right[i],right[j] + a[i]);
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		ans = max(ans,left[i] + right[i] - a[i]);
	}
	cout<<ans;
		
}
