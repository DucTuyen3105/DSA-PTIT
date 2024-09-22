#include<bits/stdc++.h>
using namespace std;
//duong cheo xuoi i - j + n
//duong cheo nguoc i + j - 1;
int x[1000] ;//hang
int cot[1000] ;//cot
int xuoi[1000] ;//cheo xuoi
int nguoc[1000] ;//cheo nguoc
int n;
int cnt = 0;
void Try(int i)
{
	for(int j = 1 ; j <= n ; j++)
	{
		if(cot[j]==0&&xuoi[i-j+n]==0&&nguoc[i+j-1]==0)
		{
			x[i] = j;
			cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 1;
			if(i==n)
			{
				cnt++;
			}
			else
			{
				Try(i+1);
			}
			cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 0;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	Try(1);
	cout<<cnt<<endl;
	}
}
