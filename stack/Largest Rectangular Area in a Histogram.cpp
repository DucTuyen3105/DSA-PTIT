#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	ll a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	ll left[n];
	stack<ll>st;
	for(int i = n - 1 ; i >= 0 ; i--)
	{
		while(!st.empty() && a[st.top()] > a[i])
		{
			left[st.top()] = i; st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		left[st.top()] = -1;
		st.pop();
	}
	ll right[n];
	for(int i = 0 ; i < n ; i++)
	{
		while(!st.empty() && a[st.top()] > a[i])
		{
			right[st.top()] = i; st.pop();
		}
		st.push(i);
	}
	while(!st.empty()) 
	{
		right[st.top()] = n; st.pop();
	}
	ll ans = LLONG_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		ll temp = 1ll*a[i] * (right[i] - left[i] - 1);
		ans = max(ans,temp);
	}
	cout<<ans;	
	cout<<endl;
	}
}

