#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool check(int a[],int n, int L, int h)
{
	int ans = 0;
	for(int i = 0 ; i < n ; i++ )
	{
		if(a[i]>h)
		{
			ans += a[i] - h;
			if(ans>=L)
			{
				return true;
			}
		}
	}
	return ans>=L;
}
int main()
{
	int n;
	cin>>n;
	int L;
	cin>>L;
	int a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	ll l = 0;
	ll r = *max_element(a,a+n); // do cao lon nhat cua cay trong array
	int res = -1;
	while(l<=r)
	{
		ll mid =  (l+r) / 2;
		if(check(a,n,L,mid))
		{
			res = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<res;
}
			
		
