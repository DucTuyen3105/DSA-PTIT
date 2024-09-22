#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int a[],int n, int t,ll time)
{
	ll ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		ans+=time/a[i];
		if(ans>=t) return true;
	}
	return ans >= t;
}
int main()
{
	int n;
	int t;
	cin>>n>>t;
	int a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	ll res = -1;
	ll l = 0 ; 
	ll r = 1e18;
	while(l<=r)
	{
		ll mid = (l + r) / 2;
		if(check(a,n,t,mid))
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
		
	
