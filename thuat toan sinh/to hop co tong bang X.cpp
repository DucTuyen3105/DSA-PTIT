#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int x[1000];
int s;
int cnt = 0;
vector<vector<int>>v;
void Try(int i , int pos , int tong)
{
	for(int j = pos ; j <= n ; j++)
	{
		x[i] = a[j];
		tong+=x[i];
		if(tong==s)
		{
			cnt++;
			vector<int>temp;
			for(int k = 1 ; k <= i ; k++)
			{
				temp.push_back(x[k]);
			}
			v.push_back(temp);
		}
		else if(tong<s) Try(i+1,j,tong);
		tong -= x[i];
	}
}
int main()
{
	cin>>n;
	cin>>s;
	set<int>se;
	for(int i = 1 ; i <= n ; i++)
	{
		int temp;
		cin>>temp;
		se.insert(temp);
	}
	n = se.size();
	int res = 1;
	for(auto y : se)
	{
		a[res] = y;
		res++;
	}
	Try(1,1,0);
	if(cnt==0)cout<<-1;
	else
	{
		cout<<cnt;
		cout<<endl;
		for(auto l : v)
		{
			cout<<"{";
			for(int i = 0 ; i < l.size() ; i++)
			{
				cout<<l[i];
				if(i!=l.size()-1) cout<<" ";
				else cout<<"}";
			}
			cout<<endl;
		}
	}		
}
