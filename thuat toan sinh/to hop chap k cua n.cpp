#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int ok;
int a[1000000];
void kt()
{
	for(int i = 1 ; i <= k ; i++)
	{
		a[i] = i ;
	}
}
void Sinh()
{
	int i = k;
	while(i>=1&&a[i]==n-k+i)
	{
		i--;
	}
	if(i==0) ok = 0;
	else
	{
		a[i]++;
		for(int j = i + 1 ; j <= k ; j++)
		{
			a[j] = a[j-1] + 1;
		}
	}
		
}
int main()
{
	cin>>k;
	cin>>n;
	kt();
	ok = 1;
	while(ok)
	{
		for(int i = 1 ; i <= k ; i++)
		{
			cout<<a[i];
		}
		cout<<endl;
		Sinh();
	}
}

