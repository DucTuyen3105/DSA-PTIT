#include<bits/stdc++.h>
using namespace std;
void xuly(string s)
{
	stack<char>st;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(!st.empty()&&s[i] == st.top())
		{
			st.pop();
		}else
		{
			st.push(s[i]);
		}
	}
	string temp = "";
	while(!st.empty())
	{
		temp+=st.top();
		st.pop();
	}
	reverse(temp.begin(),temp.end());
	if(temp.size()==0) cout<<"EMPTY";
	else cout<<temp;
}
int main()
{
    string s;
	cin>>s;
    xuly(s);
}
