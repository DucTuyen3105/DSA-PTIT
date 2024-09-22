#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool check(int n)
{
	int cnt[10] = {0};
	while(n)
	{
		if(cnt[n%10] == 1) return false;
		cnt[n%10] = 1;
		n/=10;
	}
	return true;
}
void bfs()
{
	queue<int>q;
	for(auto x : {1 , 2 , 3 , 4 ,5})
	{
		q.push(x);
	}
	while(true)
	{
		int x = q.front(); q.pop();
		v.push_back(x);
		if(x>1e5) break;
		for(auto y : {0 , 1 , 2 , 3 ,4 , 5})
		{
			int res = x * 10 + y;
			if(check(res))
			{
				q.push(res);
			}
		}
	}
}
int main()
{
	int tc;
	cin>>tc;
	bfs();
	while(tc--)
	{
		int cnt = 0;
		int l, r; cin>>l>>r;
		for(auto x : v)
		{
			if(x>=l&&x<=r)
			{
				cnt++;
			}
			if(x>r) break;
		}
		cout<<cnt<<endl;
	}
}
				
			
		
		
