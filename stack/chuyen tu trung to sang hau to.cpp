#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int uutien(char c){
	if(c == '*' || c == '/')
		return 2;
	if(c == '+' || c == '-')
		return 1;
	return 0; // (
}

void solve(string s){
	stack<char> st;
	string res = "";
	for(char c : s){
		if(c == '(') st.push(c);
		else if(isalpha(c)) res += c;
		else if(c == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			//N?u m?c d? uu tiên c?a các toán t? trong ngan x?p >= uu tiên c
			while(!st.empty() && uutien(st.top()) >= uutien(c)){
				res += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	cout << res << endl;
}

int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	string s; cin >> s;
	solve(s);
}
