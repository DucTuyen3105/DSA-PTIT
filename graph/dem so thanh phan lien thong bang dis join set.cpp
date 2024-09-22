#include<bits/stdc++.h> 
using namespace std;
int n, m;
int parent[100];
void init()
{ 
	for(int i = 1 ; i <= n ; i++) 
	{
		parent[i] = i;
	}
}
int find(int u)
{
	while(u != parent[u])
	{
		u = parent[u];
	}
	return u;
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
		if(x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
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
