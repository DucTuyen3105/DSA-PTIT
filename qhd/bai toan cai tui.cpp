#include<bits/stdc++.h>
using namespace std;
int f[1003][1003];
int c[1003];
int w[1003];
int n;
int v;
int main()
{
	cin>>n>>v;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>w[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>c[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= v ; j++)
		{
			f[i][j] = f[i-1][j];
			if(j>=w[i])
			{
				f[i][j] = max(f[i][j],f[i-1][j-w[i]]+c[i]);
			}
		}
	}
	cout<<f[n][v];
}
	
