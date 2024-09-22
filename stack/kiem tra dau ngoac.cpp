#include<bits/stdc++.h>
using namespace std;
bool check(char x, char y)
{
	return (x == '(' && y == ')') || (x =='{' && y == '}') || (x =='[' && y == ']');
}
bool isvalid(string s)
{
	stack<char>st;
	for(char x : s)
	{
		if(x == '(' || x == '{' || x == '[')
		{
			st.push(x);
		}
		else
		{
			if(st.empty())
			{
				return false;
			}
			if(!check(st.top(),x)) return false;
			st.pop();
		}
	}
	if(st.empty()) return true;
	else return false;
}
int main()
{
	string s;
	getline(cin,s);
	if(isvalid(s)) cout<<"YES";
	else cout<<"NO";
}
	
			
