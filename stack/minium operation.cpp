#include<bits/stdc++.h>
using namespace std;
int bfs(int s , int t)
{
	queue<pair<int,int>>q;
	q.push({s,0});
    set<int>se;
	while(q.size() != 0)
	{
		auto x = q.front(); q.pop();
		if(x.first == t) return x.second;
		if(!se.count(x.first * 2) && x.first < t)
		{
			q.push({x.first*2,x.second+1});
			se.insert(x.first * 2);
		}
		if(!se.count(x.first - 1) && x.first >= 0)
		{
			q.push({x.first  - 1 , x.second + 1});
			se.insert(x.first - 1);
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int s, t;
	cin>>s>>t; cout<<bfs(s,t)<<endl;
	}
}
