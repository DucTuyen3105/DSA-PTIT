#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i = n / 7 ; i >= 0 ; i--)
	{
		int res = n - 7*i;
		if(res%4==0)
		{
			int x = res/4;
			for(int j = 0 ; j < x ; j++)
			{
				cout<<4;
			}
			for(int j = 0 ; j < i ; j++)
			{
				cout<<7;
			}
			return 0;
		}
	}
	cout<<-1;
}
				
