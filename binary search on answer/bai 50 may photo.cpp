#include<bits/stdc++.h>
using namespace std;
bool check(double a[],int n,int k,double mid)
{
	int count = 0;
	for(int i = 0 ; i < n ; i++)
	{
		count += a[i] / mid;
		if(count>=k)return true;
	}
	return count>=k;
}
int main()
{
	int n;
	cin>>n;
	double a[n];
	int k;
	cin>>k;
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}
	double left = 0;
	double right = 1e18;
	double res = -1;
	for(int i = 1 ; i <= 80 ; i++)
	{
		double mid = (left + right) / 2;
		if(check(a,n,k,mid))
		{
			res = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout<<setprecision(6)<<fixed<<res;
}
