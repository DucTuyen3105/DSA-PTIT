#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int &x : a) cin>>x;
	stack<int>st;
	for(int i = 0 ; i < n ; i++)
	{
		while(!st.empty()&&a[i]>a[st.top()])
		{
			b[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		b[st.top()] = -1;
		st.pop();
	}
	int c[n];
	for(int i = 0 ; i < n ; i++)
	{
		while(!st.empty()&&a[i] < a[st.top()])
		{
			c[st.top()] = a[i]; st.pop();
		}
		st.push(i);
	}
	while(!st.empty())
	{
		c[st.top()] = -1;
		st.pop();
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(b[i]!=-1)
		{
			cout<<c[b[i]]<<" ";
		}
		else
		{
			cout<<-1<<" ";
		}
	}
}
	
			
