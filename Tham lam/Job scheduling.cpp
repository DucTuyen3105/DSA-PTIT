#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>x,pair<int,int>y)
{
	return x.second < y.second ;
}
int main()
{
	vector<pair<int,int>>v;
	int n;
	cin>>n;
	while(n--)
	{
		pair<int,int>x;
		cin>>x.first;
		cin>>x.second;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	int cnt = 1;
	int last = v[0].second;
	for(int i = 1 ; i < v.size() ; i++)
	{
		if(v[i].first>last)
		{
			last = v[i].second;
			cnt++;
		}
	}
	cout<<n-cnt;
	
}
		
