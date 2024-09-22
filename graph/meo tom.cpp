#include<bits/stdc++.h>
using namespace std;
int used[20005];
vector<int>ke[20005];
int n, m; 
int d[20005];
int res = 0;
void nhap()
{
	cin>>n>>m;
	for(int i = 1 ; i <= n; i++) cin>>d[i];
	for(int i = 1 ; i <= n - 1 ; i++)
	{
		int x; int y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u , int cnt)
{
	used[u] = 1;
	int ok = 1;
	if(cnt>m)
	{
		return;
	}
	for(auto x : ke[u])
	{
		if(!used[x])
		{
			ok = 0;
			if(!d[x])
			{
				dfs(x,0);
			}
			else
			{
				dfs(x,cnt+1);
			}
		}
	}
	if(ok) res++;
}
int main()
{
	nhap();
	dfs(1,d[1]);
	cout<<res;
}
