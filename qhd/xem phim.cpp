#include<bits/stdc++.h>
using namespace std;
int f[102][25002];
int c,n,w[102];
int main()
{
	cin>>c>>n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>w[i];
	}
	// cho dc toi da la j
	// xet i con bo 
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			f[i][j] = f[i-1][j]; // bo qua con bo thu i, khong cho i len xe
			if(j>=w[i])
			{
				//cho con bo i len xe
				f[i][j] = max(f[i][j],f[i-1][j-w[i]]+w[i]);
				// them w[i] vao thi khoi luong toi da giam la j - w[i]
				//+w[i] con bo dc dua len xe nen khoi luong tang, khoi luong thuc te tang them;
			}
		}
	}
	cout<<f[n][c];
}
