#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct job
{
	ll id;
	ll dl;
	ll profit;
};
bool cmp(job x , job y)
{
	return x.profit > y.profit;
}
int main()
{
	int n;
	cin>>n;
	job a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i].id>>a[i].dl>>a[i].profit;
	}
	sort(a,a+n,cmp);
	ll ans = 0;
	ll used[n] = {0};
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = a[i].dl - 1 ; j >=0 ; j--)
		{
			if(used[j]==0)
			{
				ans+=a[i].profit;
				used[j] = 1;
				break;
			}
		}
	}
	cout<<ans;
}
