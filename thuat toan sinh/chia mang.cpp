#include<bits/stdc++.h>
using namespace std;
int n, k,s = 0;
int a[100];
int x[100];
bool check[100]; int ok = 0;
void nhap()
{
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		s += a[i];
	}
}
void Try(int i ,int pos , int sum , int cnt)
{
	if(cnt==k)
	{
		ok = 1;
		return;
	}
	if(ok) return;
	for(int j = pos ; j <= n ; j++)
	{
		if(sum+a[j]<=s&&!check[j])
		{
			x[i] = a[j];
			check[j] = 1;
			if(sum + a[j] == s)
			{
				Try(i+1,1,0,cnt+1);
			}
			else
			{
				Try(i+1,j+1,sum+=a[j],cnt);
			}
			check[j] = 0;
		}
	}
}
int main()
{
	nhap();
	if(s%k==0)
	{
		s/=k;
		Try(1,1,0,0);
		cout<<ok;
	}
	else
	{
		cout<<ok;
	}
	
}
	
	

