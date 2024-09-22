#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	vector<int>v;
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++)
	{
		auto x = lower_bound(v.begin(),v.end(),a[i]);
		if(x==v.end())
		{
			v.push_back(a[i]);
		}
		else
		{
			*x = a[i];
		}
	}
	cout<<v.size();
}
