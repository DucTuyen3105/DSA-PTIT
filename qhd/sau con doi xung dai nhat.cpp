#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool f[1003][1003]; //f[i][j]: doan tu i den j co doi xung hay k
//dap an: max(j-i+1) voi f[i][j] = 1;
int main()
{
	cin>>s;
	n = s.size();
	for(int i = 1 ; i <= n ; i++)
	{
		f[i][i] = 1; // sau co 1 ki tu thi luon doi xung
	}
	int ans = 0;
	for(int len = 2 ; len <= n ; len++)
	{
		// duyet do dai s	au 
		for(int i = 1 ; i + len - 1 <= n ; i++)
		{
			//duyet vi tri ket thuc
			int j = i + len -1 ;
			if(len == 2 ) 
			{
				if(s[i-1]==s[j-1])
				{
					f[i][j] = true;
				}
				else
				{
					f[i][j] = false;
				}
			}
			else
			{
				if(s[i-1] ==s[j-1] && f[i+1][j-1] == true)	
				{
					f[i][j] = true;
				}
				else
				{
					f[i][j] = false;
				}
			}
			if(f[i][j] == true)
			{
				ans = len;
			}
		}
	}
	cout<<ans;
}
