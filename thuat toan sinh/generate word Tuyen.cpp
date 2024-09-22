#include<bits/stdc++.h>
using namespace std;
char c[100][100];
string s;
int n;
int m;
int ok = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visited[100][100];
void Try(int i , int j ,int pos)
{
	visited[i][j] = 1;
	if(pos==s.size()-1)
	{
		ok = 1;
		return;
	}
	if(ok) return;
	for(int k = 0 ; k < 4 ; k++ )
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]==s[pos+1]&&visited[x][y]==0)
		{
			visited[x][y] = 1;
			Try(x,y,pos+1);
			visited[x][y] = 0;
		}
	}
}
		
int main()
{
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			cin>>c[i][j];
		}
	}
	cin>>s;
	s = "0" + s;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(c[i][j]==s[1])
			{
				Try(i,j,1);
			}
		}
	}
	if(ok) cout<<"YES"; else cout<<"NO";
}
	
	
