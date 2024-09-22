#include<bits/stdc++.h>
using namespace std; // 1 2 
                     // 2 3
                     // 3 4
                     // 4 7
                     // 3 5
                     // 2 5
                     // 2 6
int n, m;
vector<int>ke[2000];
int visited[1000];
int degree[1000]; // tinh ban bac vao cua tung dinh
void nhap()
{
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
		int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		degree[y]++;
	}
}
void kahn()
{
	queue<int>q;
	for(int i = 1 ; i <= n ; i++)
	{
		if(degree[i]==0) q.push(i);
	}
	int dem = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop(); dem++;
		for(int y : ke[u])
		{
			degree[y]--;
			if(degree[y]==0)
			{
				q.push(y);
			}
		}
	}
	if(dem==n) cout<<0;
	else cout<<1; 
}
int main()
{
	nhap();
	kahn();
}
