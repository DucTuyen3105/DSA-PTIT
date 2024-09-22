#include<bits/stdc++.h>
using namespace std;
int xuly(string s)
{
	stack<int>st;
	int n = s.size();
	int cnt = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '(') st.push(i);
		else
		{
			if(st.empty()) cnt++;
			else
			{
			    st.pop();
			}
		}
	}
	cnt+= st.size();
	return cnt;
}
int main()
{
    string s;
	cin>>s;
	cout<<xuly(s);
}		
