#include<bits/stdc++.h>
using namespace std;
long long f[100];
char find(int n , int k)
{
	if(n==1)
	{
		return 'A';
	}
	if(n==2)
	{
		return 'B';
	}
	if(k<=f[n-2])
	{
		return find(n-2,k);
	}
	else
	{
		return find(n-1,k-f[n-2]);
	}
}
int main()
{
	int n;
	cin>>n;
	f[1] = 1;
	f[2] = 1;
	int k; cin>>k;
	for(int i = 3 ; i <= n ; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	cout<<find(n,k);
}
