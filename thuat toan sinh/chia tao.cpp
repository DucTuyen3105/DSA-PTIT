#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n;
int x[10000];
int ok;
void kt()
{
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		x[i] = 0;
	}
}
void sinh()
{
	int i = n;
	while(x[i]==1&&i>0)
	{
		x[i] = 0;
		i--;
	}
	if(i==0)
	{
		ok = 0;
	}
	else
	{
		x[i] = 1;
	}
}
int main()
{
	cin>>n;
	kt();
	ok = 1;
	long long ans = LLONG_MAX;
	while(ok)
	{
		long long s1 = 0; long long s2 = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(x[i]==1) s1 += a[i];
			else s2 += a[i];
		}
		ans = min(ans,abs(s1-s2));
		sinh();
	}
	cout<<ans;
}
