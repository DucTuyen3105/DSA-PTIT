#include<bits/stdc++.h>
using namespace std;
vector<string>v;
void Sinh(string s,int n)
{
	if(s.size()==n)
	{
		v.push_back(s);
	}
	else
	{
		Sinh(s+"0",n);
		Sinh(s+"1",n);
	}
}
bool check(string s,int k)
{
	int count = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i]=='1')
		{
			count++;
			if(count>k)
			{
				return false;
			}
		}
	}
	return count==k;
}
bool check1(string s, int k)
{
	int count = 0;
	string temp = "";
	while(temp.size()<k+1)
	{
		temp+="1";
	}
	if(s.find(temp)!=string::npos)
	{
		return false;
	}
	temp.pop_back();
	if(s.find(temp)!=string::npos)
	{
		s.erase(s.find(temp),k);
		if(s.find(temp)!=string::npos)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
	
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	Sinh("",n);
	for(auto x : v)
	{
		if(check(x,k))
		{
			cout<<x<<" ";
		}
	}
	cout<<endl;
	for(auto x : v)
	{
		if(check1(x,k))
		{
			cout<<x<<" ";
		}
	}
}
		
