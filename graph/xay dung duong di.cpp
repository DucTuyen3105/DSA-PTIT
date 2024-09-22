#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1000];
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	vector<int>v;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			v.push_back(i);
		}
	}
	cout<< v.size() - 1<<end;
	for(int i = 1 ; i < v.size() ; i++)
	{
		cout<< v[i - 1] <<" " << v[i] <<endl;
	}
	
