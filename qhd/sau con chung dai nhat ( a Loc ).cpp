#include<bits/stdc++.h>
using namespace std;
int f[1000][1000];
int main()
{
	string s;
	string t;
	cin>>s>>t;
	int n = s.size();
	int m = t.size();
	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= m ; j++)
		{
			if(i==0||j==0)
			{
				f[i][j] = 0;
			}
			else
			{
				if(s[i-1] == t[i-1])
				{
					f[i][j] = f[i-1][j-1] + 1;
				}
				else
				{
					f[i][j] = max(f[i-1][j],f[i][j-1]);
				}
			}
		}
	}
	cout<<f[n][m];
}	
		
