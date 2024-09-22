#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bac(ll n){
	int cnt = 0;
	while(n){
		n /= 2;
		cnt++;
	}
	return cnt;
}

ll H[100];

int xuly(ll n, int bac, ll pos){
	ll mid = H[bac-1];
	if(pos == mid) return n % 2;
	if(pos > mid) return xuly(n/2, bac-1, pos-mid);
	return xuly(n/2, bac-1, pos);
}

int main(){
	ll n, l, r;
	cin >> n >> l >> r;
	H[0] = 1;
	for(int i = 1; i <= 50; i++){
		H[i] = H[i-1] * 2;
	}
	int b = bac(n);
	int cnt = 0;
	for(ll i = l; i <= r; i++){
		if(xuly(n, b, i)) cnt++;
		cout << i << " " << xuly(n, b, i) << endl;
	}
	cout << cnt;
}
