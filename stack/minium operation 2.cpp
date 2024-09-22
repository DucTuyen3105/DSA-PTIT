#include<bits/stdc++.h>
using namespace std;
int bfs(int n)
{
	queue<pair<int,int>>q;
	q.push({n,0});
	set<int>se;
	while(!q.empty())
	{
		auto x = q.front(); q.pop();
		if(x.first == 1) return x.second;
		if(!se.count(x.first-1) && x.first > 1)
		{
		    q.push({x.first-1,x.second+1});
		    se.insert(x.first-1);
		}
		for(int i = 2 ; i <= sqrt(x.first) ; i++)
		{
			if(x.first%i==0)
			{
				int temp1 = i;
				int temp2 = x.first / i;
				int res = max(i,x.first/i);
				if(!se.count(res) && x.first > 1)
				{
					se.insert(res);
					q.push({res,x.second+1});
				}
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	cout<<bfs(n)<<endl;
	}
}
