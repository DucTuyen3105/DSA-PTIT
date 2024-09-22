#include<bits/stdc++.h>
using namespace std;
int uutien(char c)
{
	if(c=='*'||c=='/')
	{
		return 2;
	}
	else if(c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void solve(string s)
{
	stack<char>st;
	string res ="";
	for(char c : s)
	{
		if(c == '(' ) st.push(c);
		else if(isalpha(c)) res+=c;
		else if(c==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while(!st.empty()&&uutien(st.top()) >= uutien(c))
			{
				res+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	cout<<res;
}
int main()
{
	string s;
	cin>>s;
	solve(s);
}
