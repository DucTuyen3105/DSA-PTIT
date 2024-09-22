#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int n, m, chutrinh = 0;
vector<int> ke[200005];
int color[200005];
int parent[200005];

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		//ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

void dfs(int u){
	color[u] = 1; // xam
	for(int v : ke[u]){
		if(color[v] == 0){
			dfs(v);
		}
		else if(color[v] == 1){
			chutrinh = 1;
		}
	}
	color[u] = 2;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	nhap();
	for(int i = 1; i <= n; i++){
		if(color[i] == 0){
			dfs(i);
			if(chutrinh){
				cout << 1 << endl; return 0;
			}
		}
	}
	cout << 0 << endl;
}
