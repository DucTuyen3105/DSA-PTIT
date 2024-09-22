#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int ok;
int cnt;
void kt()
{
	cnt = 1;
	a[1] = n;
}
void sinh()
{
	int i = cnt;
	while(i>=1&&a[i]==1) // tim bit dau tien khac mot
	{
		i--;
	}
	if(i==0) ok = 0;
	else
	{
		a[i]-=1;//giam di 1 don vi khi tim dc bit khac 1
		int d = cnt - i + 1;//tinh phan bu vao cho tong bang n
		cnt = i;//reset so luong so hang
		int q = d / a[i];// bieu dien d qua a[i] thong qua chia nguyen
		int r = d%a[i];//bieu dien d qua a[i] thong qua chia du
		if(q)
		{
			for(int j = 1 ; j <= q ; j++)
			{
				cnt++;
				a[cnt] = a[i];
			}
		}
		if(r)
		{
			++cnt ; a[cnt] = r;
		}
	}
}
int main()
{
	cin>>n;
	ok = 1;
	kt();
	int count = 0;
	ok = 1;
	while(ok)
	{
		for(int i = 1 ; i <= cnt ; i++ )
		{
			cout<<a[i];
			if(i!=cnt) cout<<"+";
		}
		cout<<endl;
		sinh();
	}
}

