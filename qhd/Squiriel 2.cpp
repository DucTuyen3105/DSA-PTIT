#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	ll F[n];
	F[0] = 0;
	for(int i = 1; i < n; i++){
		F[i] = LLONG_MAX;
		for(int j = 1; j <= k; j++){
			if(i - j >= 0)
				F[i] = min(F[i], F[i - j] + abs(a[i] - a[i - j]));
		}
	}
	cout << F[n - 1] << endl;
}
