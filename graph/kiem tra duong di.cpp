#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1000];
int visited[1000];
int n,m;
int tplt[1000];
int dem = 0;
void nhap()
{
	cin>>n>>m;
	while(m--)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void dfs(int u)
{
	tplt[u] = dem;
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
	nhap();
	for(int i = 1 ; i <= n ; i++)
	{
		if(visited[i]==0)
		{
			dem++;
			dfs(i);
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int s; int t;
		cin>>s>>t;
		if(tplt[s] == tplt[t]) cout<<1<<endl;
		else cout<<-1<<endl;
	}
}

