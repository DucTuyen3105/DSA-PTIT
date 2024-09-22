#include<bits/stdc++.h>
using namespace std;
vector<int>ke[20005];
int visited[20005];
int dem[20005];
void dfs(int x)
{
	visited[x] = 1;
	dem[x]++;
	for(auto y : ke[x])
	{
		if(!visited[y])
		{
			dfs(y);
		}
	}
}
	
int main()
{
	int k, n, m;
	cin>>k>>n>>m;
	vector<int>v;
	for(int i = 1 ; i <= k ; i++)
	{
		int x; cin>>x;
		v.push_back(x);
	}
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y; cin>>x>>y;
		ke[x].push_back(y);
	}
	for(auto x : v)
	{
		memset(visited,0,sizeof(visited));
		dfs(x);
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(dem[i]==k) cnt++;
	}
	cout<<cnt;
}
