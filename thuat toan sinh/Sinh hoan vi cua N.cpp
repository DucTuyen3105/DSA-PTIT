#include<bits/stdc++.h>
using namespace std;
int n;
int ok;
int a[1000000];
void kt()
{
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = i;
	}
}
void sinh()
{
	int i = n - 1;
	while(i>=1&&a[i]>a[i+1])
	{
		i--;
	}
	if(i==0)
	{
		ok = 0;
	}
	else
	{
		int j = n;
		while(a[i]>a[j])
		{
			j--;
		}
		swap(a[i],a[j]);
		int start = i + 1;
		int end = n;
		while(start<end)
		{
			swap(a[start],a[end]);
			start++;
			end--;
		}
	}
}
int main()
{
	cin>>n;
	kt();
	ok = 1;
	while(ok)
	{
		for(int i = 1 ; i <= n ; i++ )
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		sinh();
	}
}
			
