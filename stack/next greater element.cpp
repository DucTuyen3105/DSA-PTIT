#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	int b[n];
	stack<int> st;
	for(int i = 0; i < n; i++){
		//a[i] : >= st.top() => update
		while(!st.empty() && a[i] > a[st.top()]){
			b[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		b[st.top()] = -1;
		st.pop();
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
}
