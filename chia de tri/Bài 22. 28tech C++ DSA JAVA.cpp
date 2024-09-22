#include<bits/stdc++.h>
using namespace std;
long long f[100];
string find(long long n , long long k)
{
	if(n==1)
	{
		return "28tech";
	}
	if(n==2)
	{
		return "C++";
	}
	if(n==3)
	{
		if(k==1)
		{
			return "DSA";
		}
		if(k==2)
		{
			return "JAVA";
		}
	}
	if(k<=f[n-3])
	{
		return find(n-3,k);
	}
	else if(k<=f[n-3]+f[n-2])
	{
		return find(n-2,k-f[n-3]);
	}
	else return find(n-1,k-f[n-2]-f[n-3]);
	
}
int main()
{
	f[1] = 1;
	f[2] = 1;
	f[3] = 2;
	for(int i = 4 ; i <= 60 ; i++)
	{
		f[i] = f[i-1] + f[i-2] + f[i-3];
	}
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long k;
		cin>>k;
		cout<<find(n,k)<<endl;
	}
}
	

	
