#include<bits/stdc++.h>
using namespace std;
vector<int>ke[20005];
int n, m;
int dem = 0;
int vst[20005];
void nhap()
{
    cin>>n>>m;
	for(int i = 1 ; i <= m ; i++)
	{
	    int x; int y;
		cin>>x>>y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
vector<int>tplt[20005];
void dfs(int u)
{
	tplt[dem].push_back(u);
	vst[u] = 1;
	for(auto x : ke[u])
	{
		if(!vst[x])
		{
			dfs(x);
		}
	}
}
int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
	nhap();
	for(int i = 1 ; i <= n ; i++)
	{
		if(!vst[i])
		{
			dem++;
			dfs(i);
		}
	}
	int flag = 1;
	for(int i = 1 ; i <= dem ; i++)
	{
		for(auto x : tplt[i])
		{
			if(ke[x].size()!=tplt[i].size() - 1)
			{
				cout<<"NO";
				flag = 0;
				break;
			}
		}
		if(flag == 0) break;
	}
	if(flag) cout<<"YES";
	for(int i = 1 ; i <= n ; i++)
	{
		ke[i].clear();
	}
	for(int i = 1 ; i <= dem ; i++)
	{
		tplt[i].clear();
	}
	memset(vst,0,sizeof(vst));
	cout<<endl;
	}
}
		
		
