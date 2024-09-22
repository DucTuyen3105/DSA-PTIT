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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
	int flag = 0;
	init();
	for(int i = 1 ; i <= m ; i++)
	{
		if(Union(x,y)==0)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	}
}
