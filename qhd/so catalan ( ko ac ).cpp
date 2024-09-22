#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[1001];
int mod = 1e9+7;
void catalan()
{
	c[0] = 1;
    c[1] = 1;
	for(int i = 2 ; i <= 1000 ; i++)
	{
		ll sum = 0;
		for(int j = 0 ; j < i ; j++)
		{
			sum += c[j]*c[i-j-1];
		}
		c[i] = sum;
		c[i] %=mod;
	}
}
int main()
{
	catalan();
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		cout<<c[x]<<endl;
	}
}
