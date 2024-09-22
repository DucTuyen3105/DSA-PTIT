#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int n, m, ans = 1;
int used[100005];
typedef pair<int,int> ii;
vector<ii>ke[100000];
void nhap()
{
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++)
	{
		int x, y, w; cin>>x>>y>>w;
		ke[x].push_back({y,w});
		ke[y].push_back({x,w});
	}
}
void Prim(int s)
{
	ll d = 0;
	priority_queue<ii,vector<ii>,greater<ii>>Q; // min heap
	used[s] = 1;
	for(ii x : ke[s])
	{
		if(used[x.first]==0)
		{
			Q.push({x.second,x.first});
		}
	}
	ll dem = 0;
	while(!Q.empty())
	{
		ii p = Q.top(); Q.pop();
		if(used[p.second]==1) continue;
		d+= p.first;
		++dem;
		used[p.second] = 1;
		for(ii x : ke[p.second])
		{
			if(used[x.first]==0)
			{
				Q.push({x.second,x.first});
			}
		}
	}
	if(dem==n-1)
	{
		cout<<d<<endl;
	}
	else
	{
		cout<<"IMPOSSIBLE";
	}
}
int main()
{
	nhap();
	Prim(1);
}
	
