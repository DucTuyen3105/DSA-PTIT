#include<bits/stdc++.h>
using namespace std;
int visited[1000];
vector<int>ke[1000];
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
	int n;
	cin>>n;
	int m;
	cin>>m;
	while(m--)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	int res = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			res++;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int temp = 1 ; temp <= 1000 ; temp++)
		{
			visited[temp] = 0;
		}
		visited[i] = 1;
		int dem = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			if(!visited[j])
			{
				dfs(j);
				dem++;
			}
		}
		if(dem>res) ans++;
	}
	cout<<ans;
}
				
		
			
