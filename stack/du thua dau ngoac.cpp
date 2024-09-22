#include<bits/stdc++.h>
using namespace std;
int xuly(string s)
{
	stack<int>st;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '(')
		{
			st.push(i);
		}
		else if(s[i] == ')' )
		{
			int m = st.top();
			if(s[i-1] == ')' && s[m+1] == '(' || abs(m-i) == 2)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	string s;
	cin>>s;
	if(xuly(s)) cout<<"YES";
	else cout<<"NO";
}
