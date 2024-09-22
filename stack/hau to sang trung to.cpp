#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<string>st;
	for(auto x : s)
	{
		if(isalpha(x))
		{
			string temp = "";
			temp+=x;
			st.push(temp);
		}
		else
		{
			string x1 = st.top(); st.pop();
			string x2 = st.top(); st.pop();
			string temp = "(" + x2 + x + x1 + ")";
			st.push(temp);
		}
	}
	cout<<st.top();
}
