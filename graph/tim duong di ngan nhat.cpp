#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1005][1005];
int d[1005][1005];
int n, m, s, t, u, v;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void nhap(){
	cin >> n;
	cin >> s >> t >> u >> v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

int bfs(int i, int j){
	queue<pair<int, int>> q;
	d[i][j] = 0;
	a[i][j] = 0;
	q.push({i, j});
	while(!q.empty()){
		pair<int, int> p = q.front(); q.pop();
		int i1 = p.first, j1 = p.second;
		if(i1 == u && j1 == v) return d[u][v];
		for(int k = 0; k < 8; k++){
			int i2 = i1 + dx[k], j2 = j1 + dy[k];
			if(i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= n && a[i2][j2] == 1){
				q.push({i2, j2});
				a[i2][j2] = 0;
				d[i2][j2] = d[i1][j1] + 1;
			}
		}
	}
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	cout << bfs(s, t) << endl;
}
