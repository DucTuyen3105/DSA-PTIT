#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int a[],int n, int k,ll sum)
{
	int count = 0;
	ll tong = 0;
	for(int i = 0 ; i < n ; i++)
	{
		tong+=a[i];
		if(tong>sum)
		{
			count++;
			tong = a[i];
		}
	}
	count++;
	return count <= k;
}
int main()
{
	int n;
	int k;
	cin>>n;
	cin>>k;
	ll sum = 0;
	int a[n];	
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	ll l = *max_element(a,a+n);
	ll r = sum ;
	ll res = -1;
	while(l<=r)
	{
		ll mid = (l+r) / 2;
		if(check(a,n,k,mid))
		{
			res = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout<<res;
}
			
	
			
