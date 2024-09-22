#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s;
	cin>>s;
	int a[n];
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	int f[s+1];
    f[0] = 0;
	for(int i = 1 ; i <= s ; i++)
	{
		f[i] = 1e9;
		for(int x : a)
		{
			if(i >= x)
			{
				f[i] = min(f[i],f[i-x]+1); 
				// f[i-x] + 1 ( so to can tao ra so tien i - x cong them mot to menh gia x)
			}
		}
	}
	if(f[s]==1e9) cout<<-1;
	else
	{
		cout<<f[s];
	}
}

