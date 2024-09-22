#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int ok;
void kt()
{
    for(int i = 0 ; i < n ; i++)	
    {
    	s.push_back('0');
    }
    s[n-1] = '8';
}
void sinh()
{
	int i = n - 1;
	while(i>=0&&s[i]=='8')
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
		s[i] = '8';
	}
}
vector<long long>v;
int main()
{
	n = 19;
	ok = 1;
	kt();
	while(ok)
	{
		v.push_back(stoll(s));
		sinh();
	}
	long long ans[305];
	for(int i = 1 ; i <= 300 ; i++)
	{
		for(long long x : v)
		{
			if(x%i==0)
			{
				ans[i] = x;
				break;
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		long long x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
}

