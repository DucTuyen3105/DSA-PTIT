#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int dp[s.size() + 1];
	int n = s.size();
	s = "0" + s;
	for(int i = 1 ; i <= n ; i++)
	{
		dp[i] = dp[i-1] * 10 + (s[i] - '0') * i;
	}
	cout<<dp[n-1];
}
