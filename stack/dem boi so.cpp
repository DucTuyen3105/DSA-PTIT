#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> v;
ll ans[205];

void init(){
	queue<ll> q;
	q.push(8);
	while(true){
		ll n = q.front(); q.pop();
		if(n > 1e18) break;
		v.push_back(n);
		q.push(n * 10);
		q.push(n * 10 + 8);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	init();
	for(int i = 1; i <= 200; i++){
		for(ll x : v){
			if(x % i == 0){
				++dem;
				ans[i] = x; break;
			}
		}
	}
	int TC; cin >> TC;
	while(TC--){
		int n; cin >> n;
		cout << ans[n] << endl;
	}
}
