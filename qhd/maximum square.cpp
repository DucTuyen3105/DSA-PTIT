#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1000][1000];
int a[1000][1000];
int main()
{
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)
	for(int j = 1 ; j <= m ; j++)
	cin>>a[i][j];
	int ans = INT_MIN;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; i <= m ; j++)
		{
			if(a[i][j]==1)
			{
				f[i][j] = min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
				ans = max(ans,f[i][j]);
			}
		}
	}
	cout<<ans;
}
