#include<bits/stdc++.h>
using namespace std;
bool f[202][1000000];
int n,s;
int a[202];
int main()
{
	cin>>n>>s;
	for(int i = 1 ; i <= n ; i++) cin>>a[i];
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= s ; j++)
		{
			f[i][j] = f[i-1][j];
			if(j>=a[i])
			{
				f[i][j] = max(f[i][j],f[i-1][j-a[i]]);
			}
		}
	}
	cout<<f[n][s];
}
