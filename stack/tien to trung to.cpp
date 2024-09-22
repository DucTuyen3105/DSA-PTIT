#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<string>st;
	for(int i = s.size() - 1 ; i >= 0 ; i--)
	{
		if(isalpha(s[i]))
		{
			string temp = "";
			temp+=s[i];
			st.push(temp);
		}
		else
		{
			string x1 = st.top(); st.pop();
			string x2 = st.top(); st.pop();
			string temp = "(" + x1 + s[i] + x2 + ")";
			st.push(temp);
		}
	}
	cout<<st.top();
}
	
