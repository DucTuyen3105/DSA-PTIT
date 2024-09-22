#include<bits/stdc++.h>
using namespace std;
int sz[20005];
int parent[20005];
int n,m;
int bac[20005];
void init()
{
	for(int i = 1 ; i <= n ; i++)
	{
		sz[i] = 1;
		parent[i] = i;
	}
}
int find(int x)
{
	if(x==parent[x])
	{
		return x;
	}
	else return parent[x] = find(parent[x]);
}
bool dsu(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return false;
	else
	{
		if(bac[x] > bac[y] || bac[x] == bac[y] && x < y)
		{
			parent[y] = x;
			sz[y] += sz[x];
		}
		else
		{
			parent[x] = y;
			sz[x] += sz[y];
		}
		return true;
	}
}
int main()
{
	cin>>n>>m;
	init();vector<pair<int,int>>v;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y; cin>>x>>y;
		bac[x]++;
		bac[y]++;
		v.push_back({x,y});
	}
	for(auto x : v)
	{
		dsu	(x.first,x.second);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(i==parent[i])
		{
			cout<<i<<" ";
		}
	}
}
