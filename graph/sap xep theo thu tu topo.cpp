#include<bits/stdc++.h>
using namespace std;
vector<int>ke[100];
vector<int>topo;
int n, m;
int visited[100];
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
	for(auto x : ke[u])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
	topo.push_back(u);
}
int main()
{
	nhap();
	for(int i = 1 ; i <= n ; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	for(auto x : topo)
	{
		cout<<x<<" ";	
	}
}
