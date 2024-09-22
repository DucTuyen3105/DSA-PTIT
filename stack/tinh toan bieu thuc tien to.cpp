#include<bits/stdc++.h>
using namespace std;
int xuly(string s)
{
	stack<int>st;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(!isdigit(s[i]))
		{
			int o1 = st.top() ; st.pop();
			int o2 = st.top() ; st.pop();
			int res;
			if(s[i] == '+') res = o1 + o2;
			else if(s[i] == '-') res = o2 - o1;
			else if(s[i] == '*') res = o2 * o1;
			else res = o2 / o1;
			st.push(res);
		}
		else
		{
			st.push(s[i] - '0');
		}
	}
	return st.top();
			
}
int main()
{
	string s;
	cin>>s;
	cout<<xuly(s);
}
