#include <bits/stdc++.h>
using namespace std;

using ll = long long;

typedef pair<int, int> ii;

bool check(int n){
	int cnt[10] = {0};
	while(n){
		if(cnt[n % 10] == 1) return false;
		cnt[n % 10] = 1;
		n /= 10;
	}
	return true;
}

vector<int> v;

void init(){
	queue<int> q;
	for(int x : {1, 2, 3, 4, 5}) q.push({x});
	while(true){
		int n = q.front(); q.pop();
		if(n > 1e5) break;
		v.push_back(n);
		for(int x : {0, 1, 2, 3, 4, 5}){
			int m = n * 10 + x;
			if(check(m)){
				q.push(m);
			}
		} 
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	init();
	int TC; cin >> TC;
	while(TC--){
		int l, r;
		cin >> l >> r;
		int dem = 0;
		for(int x : v){
			if(x >= l && x <= r) ++dem;
			else if(x > r) break;
		}
		cout << dem << endl;
	}
}
