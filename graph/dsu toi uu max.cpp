#include<bits/stdc++.h> 
using namespace std;
int n, m;
int parent[100];
int sz[100];
void init()
{ 
	for(int i = 1 ; i <= n ; i++) 
	{
		parent[i] = i;
		sz[i] = 1;
	}
}
int find(int u)
{
	if(u==parent[u])
	{
		return u;
	}
	int x = find(parent[u]);
	parent[u] = x;
	return x;
}
bool Union(int x , int y)
{
	x = find(x);// tim nguoi dai dien cho x
	y = find(y);// tim nguoi dai dien cho y
	if(x==y)
	{
		return false;
	}
	else
	{
		if(sz[x]<sz[y])
		{
			parent[x] = y;
			sz[y] += sz[x];
		}
		else
		{
			parent[y] = x;
			sz[x] += sz[y];
		}
		return true;
	}	
}
/*
 4 5
 3 4
 2 3
 1 2*/
int main()
{
	cin>>n>>m;
	init();
	int dem = n;
	for(int i = 0 ; i < m ; i++)
	{
		int x,y; cin>>x>>y;
		if(Union(x,y))
		{
			--dem;
		}
	}
	cout<<dem;
}

