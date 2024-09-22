#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[100000];
ll v[100000];
ll a[100000];
int n;
int ok;
void kt()
{
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>w[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>v[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = 0;
	}
}
void sinh()
{
	int i = n;
	while(i>=1&&a[i]==1)
	{
		a[i] = 0;
		i--;
	}
	if(i==0)
	{
		ok = 0;
	}
	else
	{
		a[i] = 1;
	}
}
int main()
{
	cin>>n;
	ll s;
	cin>>s;
	kt();
	ok = 1;
	ll ans = INT_MIN;
	while(ok)
	{
		ll sum = 0;
		ll sum2 = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i]==1)
			{
				sum+=w[i];
				sum2+=v[i];
			}
		}
		if(sum<=s)
		{
			ans = max(ans,sum2);
		}
		sinh();
	}
	cout<<ans;
}	
