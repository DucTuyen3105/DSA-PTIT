#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1000];
int n,m;
int visited[1000];
void nhap()
{
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
	}
}
void dfs(int u)
{
	visited[u] = 1;
	for(int x : ke[u])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
}
int main()
{
	nhap();
	for(int i = 1 ; i <= n ; i++)
	{
		memset(visited,0,sizeof(visited));
		dfs(i);
		for(int j = 1 ; j <= n ; j++)
		{
			if(!visited[j])
			{
				cout<<0;
				return 0;
			}
		}
	}
	cout<<1;
}
