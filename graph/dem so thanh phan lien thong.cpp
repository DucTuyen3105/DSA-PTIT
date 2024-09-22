#include<bits/stdc++.h>
using namespace std;
vector<int>ke[100];
int visited[100];
void dfs(int u)
{
	visited[u] = 1;
	for(int x : ke[u])
	{
		if(visited[x]==0)
		{
			dfs(x);
		}
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	while(m--)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	int dem = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			dem++;
		}
	}
	cout<<dem;
}
	
