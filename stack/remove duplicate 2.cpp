#include<bits/stdc++.h>
using namespace std;
int k;
void xuly(string s)
{
	stack<pair<char,int>>st;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(!st.empty() && s[i] == st.top().first && st.top().second == k - 1)
		{
			st.pop();
		}
		else
		{
			if(!st.empty() && s[i] == st.top().first)
			{
				pair<char,int>t = st.top(); st.pop();
				t.second++;
				st.push(t);
			}
			else
			{
				st.push({s[i],1});
			}
		}
	}
	if(st.size()==0) cout<<"EMPTY";
	else 
	{
		stack<pair<char,int>>st1;
		while(st.size()!=0)
		{
			st1.push(st.top());
			st.pop();
		}
		while(st1.size()!=0)
		{
			auto x = st1.top();
			for(int i = 0 ; i < x.second ; i++)
			{
				cout<<x.first;
			}
			st1.pop();
		}
	}
}
int main()
{
	string s;
	cin>>s>>k;
	xuly(s);
}
