#include<bits/stdc++.h>
using namespace std;
int bac[20005];
vector<int> ke[20005];
int n,m;
int nhom_truong;
int visited[20005];
void nhap()
{
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y; cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		bac[x]++;
		bac[y]++;
	}
}
void dfs(int u)
{
	visited[u] = 1;
	if(bac[u] > bac[nhom_truong] || bac[u] == bac[nhom_truong] && u < nhom_truong)
	{
		nhom_truong = u;
	}
	for(auto x : ke[u])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
}
int main()
{
	nhap();
	vector<int>v;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!visited[i])
		{
			nhom_truong = i;
			dfs(i);
			v.push_back(nhom_truong);
		}
	}
	sort(v.begin(),v.end());
	for(auto x : v) cout<<x<<" ";
}
