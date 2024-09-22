#include<bits/stdc++.h>
using namespace std;
int n,k,a[100];
int x[100];
int sum = 0;
void nhap()
{
	cin>>n;cin>>k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); // sap sep de khi quay lui in ra dc cac phan tu theo thu tu tang dan
}
void Try(int i,int pos)
{
	for(int j = pos ; j <= n ; j++)
	{
		x[i] = a[j];
		sum+=x[i];
		if(sum==k)
		{
			cout<<"[";
			for(int r = 1 ; r <= i ; r++)
			{
				cout<<x[r];
				if(r!=i) cout<<" ";
				else cout<<"]";
			}
			cout<<endl;
		}
		else if(sum<k) // danh gia can neu chua = k thi goi de quy
		{
			Try(i+1,j+1); // chon j+1 la diem bat dau khi goi de quy vi day con k lay hoan vi tu dau;
		}
		sum-=x[i];
	}
}
int main()
{
	nhap();
	Try(1,1);
}
			
