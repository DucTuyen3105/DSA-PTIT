#include<bits/stdc++.h>
using namespace std;
int find(long long n, long long k)
{
	if(k==(long long)pow(2,n-1))
	{
		return n;
	}
	else if(k<(long long)pow(2,n-1))
	{
		find(n-1,k);
	}
	else
	{
		find(n-1,k-(long long)pow(2,n-1));
	}
}
int main()
{
	long long n,k;
	cin>>n>>k;
	cout<<find(n,k);
}
