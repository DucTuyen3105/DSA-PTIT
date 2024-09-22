#include<bits/stdc++.h>
using namespace std;
string s;
void Try(string ans, int pos)
{
	if(pos==s.size())
	{
		cout<<ans<<endl;
		return;
	}
	if(isalpha(s[pos]))
	{
		Try(ans+(char)toupper(s[pos]),pos+1);
		Try(ans+(char)tolower(s[pos]),pos+1);
	}
	else
	{
		Try(ans+s[pos],pos+1);
	}
}
int main()
{
	cin>>s;
	Try("",0);
}

