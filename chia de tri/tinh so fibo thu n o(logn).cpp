#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll F[100];


struct matran{
	ll a[2][2];
	//Nap chong toan tu nhan cho cau truc ma tran
	friend matran operator * (matran x, matran y){
		matran tich;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				tich.a[i][j] = 0;
				for(int k = 0; k < 2; k++){
					tich.a[i][j] += x.a[i][k] * y.a[k][j];
					tich.a[i][j] %= 1000000007;
				}
			}
		}
		return tich;
	}
};

matran binpow(matran a, ll n){
	if(n == 1) return a;
	matran X = binpow(a, n / 2);
	if(n % 2 == 0){
		return X * X;
	}
	else{
		return X * X * a;
	}
}

int main(){
	matran x;
	x.a[0][0] = 1;
	x.a[0][1] = 1;
	x.a[1][0] = 1;
	x.a[1][1] = 0;
	ll n; cin >> n;
	matran kq = binpow(x, n);
	cout << kq.a[0][1] << endl;
}
