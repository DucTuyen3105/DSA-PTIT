#include<bits/stdc++.h>
using namespace std;
vector<int>ke[100];
vector<int>t_ke[100];
stack<int>q;
int visited[1000];
int n,m;
void nhap()
{
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		t_ke[y].push_back(x);
	}
}
void dfs1(int u)
{
	visited[u] = 1;
	for(auto x : ke[u])
	{
		if(!visited[x])
		{
			dfs1(x);
		}
	}
	q.push(u);
}
void dfs2(int u)
{
	cout<<u<<" ";
	visited[u] = 1;
	for(auto x : t_ke[u])
	{
		if(!visited[x])
		{
			dfs2(x);
		}
	}
}
int main()
{
	nhap();
	for(int i = 1 ; i <= n ; i++)
	{
		if(!visited[i])
		dfs1(i);
	}
	memset(visited,0,sizeof(visited));
	while(q.size()!=0)
	{
		int x = q.top();
		q.pop();
		if(!visited[x])
		{
			dfs2(x);
			cout<<endl;
		}
	}
}
