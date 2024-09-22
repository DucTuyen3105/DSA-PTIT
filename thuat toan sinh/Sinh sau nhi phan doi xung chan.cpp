#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int ok;
void kt()
{
	s.clear();
	for(int i = 0 ; i < n ; i++)
	{
		s.push_back('0');
	}
}
void sinh()
{
	int i = s.size()-1;
	while(i>=0&&s[i]=='1')
	{
		s[i]='0';
		i--;
	}
	if(i==-1)
	{
		ok = 0;
	}
	else
	{
		s[i] = '1';
	}
}
int main()
{
	int x;
	cin>>x;
	vector<string>ans;
	for(int i = 1 ; i <= x / 2 ; i++)
	{
		n = i;
		kt();
		ok = 1;
		while(ok)
		{
			string t = s;
			reverse(t.begin(),t.end());
			ans.push_back(s+t);
			sinh();
		}
	}
	sort(ans.begin(),ans.end());
	for(auto x : ans) cout<<x<<endl;
}
