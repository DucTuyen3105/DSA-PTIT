#include<bits/stdc++.h>
using namespace std;
string path = "DLRU";
string s="";
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
int a[100][100];
int ok = -1;
int n;
void nhap()
{
	cin>>n;
	for(int i = 1 ; i <= n ; i++)
	for(int j = 1 ; j <= n ; j++)
	cin>>a[i][j];
}
void Try(int i , int j)
{
	if(i==n&&j==n)
	{
		cout<<s<<endl;
		ok = 0;
		return;
	}
	for(int k = 0 ; k < 4 ; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(x<=n&&y<=n&&x>=1&&y>=1&&a[x][y]==1)
		{
			s += path[k];
			a[x][y] = 0;
			Try(x,y);
			s.pop_back();
			a[x][y] = 1;
		}
	}
}
int main()
{
	nhap();
	if(a[1][1]==1&&a[n][n]==1)
	{
		a[1][1] = 0;
		Try(1,1);
	}
	if(ok==-1) cout<<ok;
}
