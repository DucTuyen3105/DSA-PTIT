#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	int l = 0; int r = 0;
	int ans = 0;
	for(char x : s)
	{
		if(x == '(')
		{
			l++;
		}
		if(x == ')')
		{
			r++;
		}
		if(l==r) ans = max(ans,2*r);
		if(r>l) r = l = 0;
	}
	r = l = 0;
	for(int i = s.size() - 1 ; i >= 0 ; i--)
	{
		if(s[i] == ')')
		{
			r++;
		}
		if(s[i] == '(') l++;
		if(r==l) ans = max(ans,l*2);
		if(r<l) l = r = 0;
	}
	cout<<ans<<endl;
	}
}
