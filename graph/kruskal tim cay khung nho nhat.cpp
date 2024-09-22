#include<bits/stdc++.h> 
using namespace std;
long long n, m;
long long parent[(int)1e5];
long long sz[(int)1e5];
struct canh
{
	long long x;
	long long y;
	long long w;
};
vector<canh>dscanh;
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
bool Union(long long x , long long y)
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
bool cmp(canh x, canh y)
{
	return x.w < y.w;
}
void kruskal()
{
	sort(dscanh.begin(),dscanh.end(),cmp);
	long long d = 0;
	vector<canh> mst; // luu tung canh
	for(int i = 0 ; i < m ; i++)
	{
		if(Union(dscanh[i].x,dscanh[i].y))
		{
			d+=dscanh[i].w;
			mst.push_back(dscanh[i]);
		}
		if(mst.size()==n-1) break;
	}
	if(mst.size()!=n-1)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		cout<<d<<endl;
	}
}
int main()
{
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y; int w;
		cin>>x>>y>>w;
		canh temp;
		temp.x = x;
		temp.y = y;
		temp.w = w;
		dscanh.push_back(temp);
	}
	init();
	kruskal();
	
}

