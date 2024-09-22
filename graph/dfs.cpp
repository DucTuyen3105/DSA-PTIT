#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> ke[1005];
int n,m;
int visited[1005];
void nhap()
{
	cin>>n;
	for(int i = 0 ; i < m ; i++)
	{
		int x,int y;
		cin>>x>>y;
		ke[x].push_back(y);
	}
}
void dfs(int u)
{
	cout<< u <<" ";
	visited[u] = 1;
	for(int v : ke[u])
	{
		if(visited[v]==0)
		{
			dfs(v);
		}
	}
}
int main()
{
	nhap();
	
	

