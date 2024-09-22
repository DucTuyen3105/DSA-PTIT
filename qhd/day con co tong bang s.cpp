#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s;
	cin>>s;
	int f[s+1] = {0};
	f[0] = 1; // co mot tap con rong co tong bang 0
	int a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = s ; j >= a[i] ; j--)
		{
			if(f[j-a[i]]==1)
			{
				f[j] = 1;
			}
		}
	}
	cout<<f[s];
}
			
